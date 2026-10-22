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
#அந்தர்பாவ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA முழு rsym, anon_sym, ind, loc;

ST_DATA Sym *global_அடுக்கு;
ST_DATA Sym *local_அடுக்கு;
ST_DATA Sym *define_அடுக்கு;
ST_DATA Sym *global_label_அடுக்கு;
ST_DATA Sym *local_label_அடுக்கு;

நிலையான Sym *sym_free_first;
நிலையான வெறுமை **sym_pools;
நிலையான முழு nb_sym_pools;

நிலையான Sym *all_cleanups, *pending_gotos;
நிலையான முழு local_scope;
ST_DATA எழுத்து debug_modes;

ST_DATA SValue *vtop;
நிலையான SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA முழு nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() எனில்(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA முழு global_கோவை;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA முழு func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA முழு func_vc; /* stack address for implicit struct return storage */
ST_DATA முழு func_ind; /* function start address */
நிலையான முழு func_old;
ST_DATA மாறிலி எழுத்து *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
நிலையான CString initstr;

#எனில் PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#அல்லதெனில் LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#இல்லையெனில்
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

நிலையான கட்டமைப்பு switch_t {
    கட்டமைப்பு case_t {
        int64_t v1, v2;
        முழு ind, வரி;
    } **p; முழு n; /* list of case ranges */
    முழு def_sym; /* default symbol */
    முழு nocode_wanted;
    முழு *bsym;
    கட்டமைப்பு scope *scope;
    கட்டமைப்பு switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_எண் 8
/*list of temporary local variables on the stack in current function. */
நிலையான கட்டமைப்பு temp_local_variable {
	முழு location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_எண்];
நிலையான முழு nb_temp_local_vars;

நிலையான கட்டமைப்பு scope {
    கட்டமைப்பு scope *prev;
    கட்டமைப்பு { முழு loc, locorig, இலக்கம்; } vla;
    கட்டமைப்பு { Sym *s; முழு n; } cl;
    முழு *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *வேர்_scope;

வகைவரை கட்டமைப்பு {
    Section *sec;
    முழு local_offset;
    Sym *flex_array_ref;
} init_params;

#எனில் 1
#define precedence_parser
நிலையான வெறுமை init_prec(வெறுமை);
#endif

நிலையான வெறுமை block(முழு flags);
#define STMT_கோவை 1
#define STMT_COMPOUND 2

நிலையான வெறுமை gen_cast(CType *type);
நிலையான வெறுமை gen_cast_s(முழு t);
நிலையான உள்வரி CType *pointed_type(CType *type);
நிலையான வெறுமை check_restrict_type(CType *type);
நிலையான முழு type_qualifiers(CType *type);
நிலையான வெறுமை parse_btype_qualify(CType *type, முழு qualifiers);
நிலையான முழு is_compatible_types(CType *type1, CType *type2);
நிலையான முழு parse_btype(CType *type, AttributeDef *ad, முழு ignore_label);
நிலையான CType *type_decl(CType *type, AttributeDef *ad, முழு *v, முழு td);
நிலையான வெறுமை parse_கோவை_type(CType *type);
நிலையான வெறுமை init_putv(init_params *p, CType *type, unsigned long c);
நிலையான வெறுமை decl_initializer(init_params *p, CType *type, unsigned long c, முழு flags);
நிலையான வெறுமை decl_initializer_alloc(CType *type, AttributeDef *ad, முழு r, முழு has_init, முழு v, முழு scope);
நிலையான முழு decl(முழு l);
நிலையான வெறுமை கோவை_eq(வெறுமை);
நிலையான வெறுமை vpush_type_size(CType *type, முழு *a);
நிலையான முழு is_compatible_unqualified_types(CType *type1, CType *type2);
நிலையான உள்வரி int64_t கோவை_const64(வெறுமை);
நிலையான வெறுமை vpush64(முழு ty, unsigned long long v);
நிலையான வெறுமை vpush(CType *type);
நிலையான முழு gvtst(முழு inv, முழு t);
நிலையான வெறுமை gen_inline_functions(TCCState *s);
நிலையான வெறுமை free_inline_functions(TCCState *s);
நிலையான வெறுமை skip_or_save_block(TokenString **str);
நிலையான வெறுமை gv_dup(வெறுமை);
நிலையான முழு get_temp_local_var(முழு size,முழு align,முழு *r2);
நிலையான வெறுமை cast_error(CType *st, CType *dt);
நிலையான வெறுமை end_switch(வெறுமை);
நிலையான வெறுமை do_Static_assert(வெறுமை);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC வெறுமை gsym(முழு t)
{
  எனில் (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
நிலையான முழு gind()
{
  முழு t = ind;
  CODE_ON();
  எனில் (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  திரும்பு t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
நிலையான வெறுமை gjmp_addr_acs(முழு t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
நிலையான முழு gjmp_acs(முழு t)
{
  t = gjmp(t);
  CODE_OFF();
  திரும்பு t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN முழு is_float(முழு t)
{
    முழு bt = t & VT_BTYPE;
    திரும்பு bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

நிலையான உள்வரி முழு is_integer_btype(முழு bt)
{
    திரும்பு bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

நிலையான முழு btype_size(முழு bt)
{
    திரும்பு bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
நிலையான முழு R_RET(முழு t)
{
    எனில் (!is_float(t))
        திரும்பு REG_IRET;
#ifdef TCC_TARGET_X86_64
    எனில் ((t & VT_BTYPE) == VT_LDOUBLE)
        திரும்பு TREG_ST0;
#அல்லதெனில் defined TCC_TARGET_RISCV64
    எனில் ((t & VT_BTYPE) == VT_LDOUBLE)
        திரும்பு REG_IRET;
#endif
    திரும்பு REG_FRET;
}

/* returns 2nd function return register, if any */
நிலையான முழு R2_RET(முழு t)
{
    t &= VT_BTYPE;
#எனில் PTR_SIZE == 4
    எனில் (t == VT_LLONG)
        திரும்பு REG_IRE2;
#அல்லதெனில் defined TCC_TARGET_X86_64
    எனில் (t == VT_QLONG)
        திரும்பு REG_IRE2;
    எனில் (t == VT_QFLOAT)
        திரும்பு REG_FRE2;
#அல்லதெனில் defined TCC_TARGET_RISCV64
    எனில் (t == VT_LDOUBLE)
        திரும்பு REG_IRE2;
#endif
    திரும்பு VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_சொற்கள்(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
நிலையான வெறுமை PUT_R_RET(SValue *sv, முழு t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
நிலையான முழு RC_RET(முழு t)
{
    திரும்பு reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
நிலையான முழு RC_TYPE(முழு t)
{
    எனில் (!is_float(t))
        திரும்பு RC_INT;
#ifdef TCC_TARGET_X86_64
    எனில் ((t & VT_BTYPE) == VT_LDOUBLE)
        திரும்பு RC_ST0;
    எனில் ((t & VT_BTYPE) == VT_QFLOAT)
        திரும்பு RC_FRET;
#அல்லதெனில் defined TCC_TARGET_RISCV64
    எனில் ((t & VT_BTYPE) == VT_LDOUBLE)
        திரும்பு RC_INT;
#endif
    திரும்பு RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
நிலையான முழு RC2_TYPE(முழு t, முழு rc)
{
    எனில் (!USING_TWO_சொற்கள்(t))
        திரும்பு 0;
#ifdef RC_IRE2
    எனில் (rc == RC_IRET)
        திரும்பு RC_IRE2;
#endif
#ifdef RC_FRE2
    எனில் (rc == RC_FRET)
        திரும்பு RC_FRE2;
#endif
    எனில் (rc & RC_FLOAT)
        திரும்பு RC_FLOAT;
    திரும்பு RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC முழு ieee_finite(இரட்டை d)
{
    முழு p[4];
    memcpy(p, &d, அளவு(இரட்டை));
    திரும்பு ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC வெறுமை test_lvalue(வெறுமை)
{
    எனில் (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC வெறுமை check_vstack(வெறுமை)
{
    எனில் (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (முழு)(vtop - vstack + 1));
}

#எனில் 0
/* dump 'b' vstack entries starting with 'a'  */
வெறுமை pv (மாறிலி எழுத்து *lbl, முழு a, முழு b)
{
    முழு i;
    க்கு (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (முழு)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
நிலையான உள்வரி வெறுமை psyms(மாறிலி எழுத்து *செய்தி, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", செய்தி);
    போது (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

நிலையான வெறுமை type_to_str(எழுத்து *buf, முழு buf_size, CType *type, மாறிலி எழுத்து *varstr);

/* print type */
நிலையான வெறுமை ptype(மாறிலி எழுத்து *செய்தி, CType *type, முழு v)
{
    எழுத்து buf[500];
    type_to_str(buf, அளவு(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, வெற்று) : வெற்று);
    printf("%s : %s;\n", செய்தி, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC வெறுமை tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, அளவு *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    எனில் (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_தள்ளு(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC முழு tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_கோவை = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_இலக்கம் | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#எனில் TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    திரும்பு 0;
}

ST_FUNC வெறுமை tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_எடு(&global_அடுக்கு, வெற்று, 0);
    sym_எடு(&local_அடுக்கு, வெற்று, 0);
    /* free preprocessor macros */
    free_defines(வெற்று);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    போது (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = வெற்று;
    all_cleanups = வெற்று;
    pending_gotos = வெற்று;
    nb_temp_local_vars = 0;
    global_label_அடுக்கு = வெற்று;
    local_label_அடுக்கு = வெற்று;
    cur_text_section = வெற்று;
    sym_free_first = வெற்று;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  எனில் (!s || !s->c)
    திரும்பு வெற்று;
  திரும்பு &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC வெறுமை update_storage(Sym *sym)
{
    ElfSym *esym;
    முழு sym_bind, old_sym_bind;

    esym = elfsym(sym);
    எனில் (!esym)
        திரும்பு;

    எனில் (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    எனில் (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    இல்லையெனில் எனில் (sym->a.weak)
        sym_bind = STB_WEAK;
    இல்லையெனில்
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    எனில் (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    எனில் (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    எனில் (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#எனில் 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, வெற்று),
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

ST_FUNC வெறுமை put_extern_sym2(Sym *sym, முழு sh_இலக்கம்,
                            addr_t மதிப்பு, unsigned long size,
                            முழு can_add_underscore)
{
    முழு sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    மாறிலி எழுத்து *name;
    எழுத்து buf1[256];

    எனில் (!sym->c) {
        name = get_tok_str(sym->v, வெற்று);
        t = sym->type.t;
        எனில் ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } இல்லையெனில் எனில் ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            எனில் (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } இல்லையெனில் எனில் (t & VT_TLS) {
            sym_type = STT_TLS;
        } இல்லையெனில் {
            sym_type = STT_OBJECT;
        }
        எனில் (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        இல்லையெனில்
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        எனில் (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            எனில் (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            எனில் (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        எனில் (sym->asm_label) {
            name = get_tok_str(sym->asm_label, வெற்று);
            can_add_underscore = 0;
        }

        எனில் (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, அளவு(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, மதிப்பு, size, info, other, sh_இலக்கம், name);

        எனில் (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_இலக்கம், sym_bind, sym_type);

    } இல்லையெனில் {
        esym = elfsym(sym);
        esym->st_மதிப்பு = மதிப்பு;
        esym->st_size = size;
        esym->st_shndx = sh_இலக்கம்;
    }
    update_storage(sym);
}

ST_FUNC வெறுமை put_extern_sym(Sym *sym, Section *s, addr_t மதிப்பு, unsigned long size)
{
    எனில் (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        திரும்பு;
    put_extern_sym2(sym, s ? s->sh_இலக்கம் : SHN_UNDEF, மதிப்பு, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC வெறுமை greloca(Section *s, Sym *sym, unsigned long offset, முழு type,
                     addr_t addend)
{
    முழு c = 0;

    எனில் (nocode_wanted && s == cur_text_section)
        திரும்பு;

    எனில் (sym) {
        எனில் (0 == sym->c) {
            put_extern_sym(sym, வெற்று, 0, 0);
            எனில் (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                போது (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#எனில் PTR_SIZE == 4
ST_FUNC வெறுமை greloc(Section *s, Sym *sym, unsigned long offset, முழு type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
நிலையான Sym *__sym_malloc(வெறுமை)
{
    Sym *sym_pool, *sym, *last_sym;
    முழு i;

    sym_pool = tcc_malloc(SYM_POOL_NB * அளவு(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    க்கு(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    திரும்பு last_sym;
}

நிலையான உள்வரி Sym *sym_malloc(வெறுமை)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    எனில் (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    திரும்பு sym;
#இல்லையெனில்
    sym = tcc_malloc(அளவு(Sym));
    திரும்பு sym;
#endif
}

ST_INLN வெறுமை sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#இல்லையெனில்
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, முழு v, முழு t, முழு c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, அளவு *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    திரும்பு s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, முழு v)
{
    போது (s) {
        எனில் (s->v == v)
            திரும்பு s;
        s = s->prev;
    }
    திரும்பு வெற்று;
}

/* structure lookup */
ST_INLN Sym *struct_find(முழு v)
{
    v -= TOK_IDENT;
    எனில் ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        திரும்பு வெற்று;
    திரும்பு table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(முழு v)
{
    v -= TOK_IDENT;
    எனில் ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        திரும்பு வெற்று;
    திரும்பு table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
நிலையான உள்வரி வெறுமை sym_link(Sym *s, முழு yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    எனில் (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    இல்லையெனில்
        ps = &ts->sym_identifier;
    எனில் (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } இல்லையெனில் {
        *ps = s->prev_tok;
    }
}

நிலையான உள்வரி முழு sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    திரும்பு IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_தள்ளு(முழு v, CType *type, முழு r, முழு c)
{
    Sym *s, **ps;
    எனில் (local_அடுக்கு)
        ps = &local_அடுக்கு;
    இல்லையெனில்
        ps = &global_அடுக்கு;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    எனில் ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        எனில் (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, வெற்று));
    }
    திரும்பு s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_தள்ளு(முழு v, முழு t, முழு c)
{
    Sym *s, **ps;
    s = sym_push2(&global_அடுக்கு, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    எனில் (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        போது (*ps != வெற்று && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    திரும்பு s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC வெறுமை sym_எடு(Sym **ptop, Sym *b, முழு keep)
{
    Sym *s, *ss;
    முழு v;

    s = *ptop;
    போது(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        எனில் ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	எனில் (!keep)
	    sym_free(s);
        s = ss;
    }
    எனில் (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(முழு v)
{
    v -= TOK_IDENT;
    எனில் ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        திரும்பு வெற்று;
    திரும்பு table_ident[v]->sym_label;
}

ST_FUNC Sym *label_தள்ளு(Sym **ptop, முழு v, முழு flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    எனில் (ptop == &global_label_அடுக்கு) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        போது (*ps != வெற்று)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    திரும்பு s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC வெறுமை label_எடு(Sym **ptop, Sym *slast, முழு keep)
{
    Sym *s, *s1;
    க்கு(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        எனில் (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, வெற்று));
        } இல்லையெனில் எனில் (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, வெற்று));
        } இல்லையெனில் {
            எனில் (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        எனில் (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        எனில் (!keep)
            sym_free(s);
        இல்லையெனில்
            s->r = LABEL_GONE;
    }
    எனில் (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
நிலையான வெறுமை vcheck_cmp(வெறுமை)
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

    எனில் (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

நிலையான வெறுமை vsetc(CType *type, முழு r, CValue *vc)
{
    எனில் (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = வெற்று;
}

ST_FUNC வெறுமை vswap(வெறுமை)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC வெறுமை vpop(வெறுமை)
{
    முழு v;
    v = vtop->r & VT_VALMASK;
#எனில் defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    எனில் (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } இல்லையெனில்
#endif
    எனில் (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
நிலையான வெறுமை vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
நிலையான வெறுமை vpush64(முழு ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = வெற்று;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC வெறுமை vpushi(முழு v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
நிலையான வெறுமை vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
நிலையான உள்வரி வெறுமை vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC வெறுமை vset(CType *type, முழு r, முழு v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

நிலையான வெறுமை vseti(முழு r, முழு v)
{
    CType type;
    type.t = VT_INT;
    type.ref = வெற்று;
    vset(&type, r, v);
}

ST_FUNC வெறுமை vpushv(SValue *v)
{
    எனில் (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

நிலையான வெறுமை vdup(வெறுமை)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC வெறுமை vrotb(முழு n)
{
    SValue tmp;
    எனில் (--n < 1)
        திரும்பு;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, அளவு *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC வெறுமை vrott(முழு n)
{
    SValue tmp;
    எனில் (--n < 1)
        திரும்பு;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, அளவு *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC வெறுமை vrev(முழு n)
{
    முழு i;
    SValue tmp;
    vcheck_cmp();
    க்கு (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC வெறுமை vset_VT_CMP(முழு op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
நிலையான வெறுமை vset_VT_JMP(வெறுமை)
{
    முழு op = vtop->cmp_op;

    எனில் (vtop->jtrue || vtop->jfalse) {
        முழு origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        முழு inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } இல்லையெனில் {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        எனில் (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
நிலையான வெறுமை gvtst_set(முழு inv, முழு t)
{
    முழு *p;

    எனில் (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        எனில் (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
நிலையான முழு gvtst(முழு inv, முழு t)
{
    முழு op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    எனில் (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    எனில் (op > 1)
        t = gjmp_cond(op ^ inv, t);
    இல்லையெனில் எனில் (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    திரும்பு t;
}

/* generate a zero or nozero test */
நிலையான வெறுமை gen_test_zero(முழு op)
{
    எனில் (vtop->r == VT_CMP) {
        முழு j;
        எனில் (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } இல்லையெனில் {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC வெறுமை vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    முழு v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_தள்ளு(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    திரும்பு sym;
}

/* push a reference to a section offset by adding a dummy symbol */
நிலையான வெறுமை vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(முழு v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    எனில் (!s) {
        /* push forward reference */
        s = global_identifier_தள்ளு(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } இல்லையெனில் எனில் (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    திரும்பு s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(முழு v)
{
    CType ct = { VT_ASM_FUNC, வெற்று };
    திரும்பு external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC வெறுமை vpush_helper_func(முழு v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
நிலையான வெறுமை merge_symattr(கட்டமைப்பு SymAttr *sa, கட்டமைப்பு SymAttr *sa1)
{
    எனில் (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    எனில் (sa1->visibility != STV_DEFAULT) {
	முழு vis = sa->visibility;
	எனில் (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
நிலையான வெறுமை merge_funcattr(கட்டமைப்பு FuncAttr *fa, கட்டமைப்பு FuncAttr *fa1)
{
    எனில் (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    எனில் (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    எனில் (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    எனில் (fa1->func_noreturn)
      fa->func_noreturn = 1;
    எனில் (fa1->func_ctor)
      fa->func_ctor = 1;
    எனில் (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
நிலையான வெறுமை merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    எனில் (ad1->section)
      ad->section = ad1->section;
    எனில் (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    எனில் (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    எனில் (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
நிலையான வெறுமை patch_type(Sym *sym, CType *type)
{
    எனில் (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        எனில் (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, வெற்று));
        sym->type.t &= ~VT_EXTERN;
    }

    எனில் (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        எனில் ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    எனில் (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, வெற்று));

    } இல்லையெனில் எனில் ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        முழு static_proto = sym->type.t & VT_STATIC;
        முழு ft1 = sym->type.ref->f.func_type;
        முழு ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        எனில் ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, வெற்று));

        /* set 'inline' if both agree or if one has static */
        எனில் ((type->t | sym->type.t) & VT_INLINE) {
            எனில் (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        எனில் (0 == (type->t & VT_EXTERN)) {
            கட்டமைப்பு FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            எனில் (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } இல்லையெனில் {
            sym->type.t &= ~VT_INLINE | static_proto;
            எனில் (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } இல்லையெனில் {
        எனில் ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        எனில் ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, வெற்று));
    }
}

/* Merge some storage attributes.  */
நிலையான வெறுமை patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    எனில் (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    எனில் (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, வெற்று));
#endif
    merge_symattr(&sym->a, &ad->a);
    எனில் (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
நிலையான Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    எனில் ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    திரும்பு s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
நிலையான வெறுமை move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    முழு n, bt;

    bt = s->type.t & VT_BTYPE;
    எனில் (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        திரும்பு;

    க்கு (s = s->type.ref, n = 0; s; s = s->next) {
        க்கு (lp = &local_அடுக்கு; !!(l = *lp); lp = &l->prev) {
            எனில் (l == s) {
                *lp = s->prev;
                s->prev = global_அடுக்கு, global_அடுக்கு = s;
                எனில் (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } இல்லையெனில் {
                    எனில் ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                எனில் (bt != VT_PTR)
                    n = 1;
                நிறுத்து;
            }
        }
        எனில் (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            நிறுத்து;
    }
}

/* define a new external reference to a symbol 'v' */
நிலையான Sym *external_sym(முழு v, CType *type, முழு r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    போது (s && s->sym_scope)
        s = s->prev_tok;

    எனில் (!s) {
        /* push forward reference */
        s = global_identifier_தள்ளு(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } இல்லையெனில் {
        patch_storage(s, ad, type);
    }
    எனில் (local_அடுக்கு) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_அடுக்கு);
    }
    திரும்பு s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC வெறுமை save_regs(முழு n)
{
    SValue *p, *p1;
    க்கு(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC வெறுமை save_reg(முழு r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC வெறுமை save_reg_upstack(முழு r, முழு n)
{
    முழு l, size, align, bt, r2;
    SValue *p, *p1, sv;

    எனில் ((r &= VT_VALMASK) >= VT_CONST)
        திரும்பு;
    எனில் (nocode_wanted)
        திரும்பு;
    l = r2 = 0;
    க்கு(p = vstack, p1 = vtop - n; p <= p1; p++) {
        எனில் ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            எனில் (!l) {
                bt = p->type.t & VT_BTYPE;
                எனில் (bt == VT_VOID)
                    தொடர்;
                எனில் ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = வெற்று;
                store(p->r & VT_VALMASK, &sv);
#எனில் defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                எனில் (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                எனில் (p->r2 < VT_CONST && USING_TWO_சொற்கள்(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            எனில் (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } இல்லையெனில் {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = வெற்று;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC முழு get_reg_ex(முழு rc, முழு rc2)
{
    முழு r;
    SValue *p;
    
    க்கு(r=0;r<NB_REGS;r++) {
        எனில் (reg_classes[r] & rc2) {
            முழு n;
            n=0;
            க்கு(p = vstack; p <= vtop; p++) {
                எனில் ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            எனில் (n <= 1)
                திரும்பு r;
        }
    }
    திரும்பு get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC முழு get_reg(முழு rc)
{
    முழு r;
    SValue *p;

    /* find a free register */
    க்கு(r=0;r<NB_REGS;r++) {
        எனில் (reg_classes[r] & rc) {
            எனில் (nocode_wanted)
                திரும்பு r;
            க்கு(p=vstack;p<=vtop;p++) {
                எனில் ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    செல் notfound;
            }
            திரும்பு r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    க்கு(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        எனில் (r < VT_CONST && (reg_classes[r] & rc))
            செல் save_found;
        r = p->r & VT_VALMASK;
        எனில் (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            திரும்பு r;
        }
    }
    /* Should never comes here */
    திரும்பு -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
நிலையான முழு get_temp_local_var(முழு size,முழு align, முழு *r2)
{
    முழு i;
    கட்டமைப்பு temp_local_variable *temp_var;
    SValue *p;
    முழு r;
    unsigned used = 0;

    /* mark locations that are still in use */
    க்கு (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	எனில் (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    எனில் (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_எண்)
	        used |= 1<<r;
	}
    }
    க்கு (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	எனில்(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    திரும்பு temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    எனில் (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_எண்) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	செல் ret_tmp;
    }
    *r2 = VT_CONST;
    திரும்பு loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
நிலையான வெறுமை move_reg(முழு r, முழு s, முழு t)
{
    SValue sv;

    எனில் (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = வெற்று;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC வெறுமை gaddrof(வெறுமை)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    எனில் ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
நிலையான வெறுமை gen_bounded_ptr_add(வெறுமை)
{
    முழு save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    எனில் (save) {
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
    எனில் (nocode_wanted)
        திரும்பு;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - அளவு(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
நிலையான வெறுமை gen_bounded_ptr_deref(வெறுமை)
{
    addr_t func;
    முழு size, align;
    ElfW_Rel *rel;
    Sym *sym;

    எனில் (nocode_wanted)
        திரும்பு;

    size = type_size(&vtop->type, &align);
    தேர்வு(size) {
    நிலை  1: func = TOK___bound_ptr_indir1; நிறுத்து;
    நிலை  2: func = TOK___bound_ptr_indir2; நிறுத்து;
    நிலை  4: func = TOK___bound_ptr_indir4; நிறுத்து;
    நிலை  8: func = TOK___bound_ptr_indir8; நிறுத்து;
    நிலை 12: func = TOK___bound_ptr_indir12; நிறுத்து;
    நிலை 16: func = TOK___bound_ptr_indir16; நிறுத்து;
    இயல்பு:
        /* may happen with struct member access */
        திரும்பு;
    }
    sym = external_helper_sym(func);
    எனில் (!sym->c)
        put_extern_sym(sym, வெற்று, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
நிலையான வெறுமை gbound(வெறுமை)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    எனில் (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        எனில் (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC வெறுமை gbound_args(முழு nb_args)
{
    முழு i, v;
    SValue *sv;

    க்கு (i = 1; i <= nb_args; ++i)
        எனில் (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    எனில் (sv->r & VT_SYM) {
        v = sv->sym->v;
        எனில் (v == TOK_setjmp
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
        எனில் (v == TOK_alloca)
            func_bound_add_epilog = 1;
#எனில் TARGETOS_NetBSD
        எனில் (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
நிலையான வெறுமை add_local_bounds(Sym *s, Sym *e)
{
    க்கு (; s != e; s = s->prev) {
        எனில் (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          தொடர்;
        /* Add arrays/structs/unions because we always take address */
        எனில் ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            முழு align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * அளவு(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
நிலையான வெறுமை tcc_debug_end_scope(Sym *b, முழு bounds)
{
#ifdef CONFIG_TCC_BCHECK
    எனில் (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_அடுக்கு, b);
#endif
    tcc_add_debug_info (tcc_state, local_அடுக்கு, b);
}

/* increment an lvalue pointer */
நிலையான வெறுமை incr_offset(முழு offset)
{
    முழு t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

நிலையான வெறுமை incr_bf_adr(முழு o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
நிலையான வெறுமை load_packed_bf(CType *type, முழு bit_pos, முழு bit_size)
{
    முழு n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    செய் {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        எனில் (n > bit_size)
            n = bit_size;
        எனில் (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        எனில் (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        எனில் (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } போது (bit_size);
    vswap(), vpop();
    எனில் (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
நிலையான வெறுமை store_packed_bf(முழு bit_pos, முழு bit_size)
{
    முழு bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    செய் {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        எனில் (bits)
            vpushi(bits), gen_op(TOK_SHR);
        எனில் (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        எனில் (n > bit_size)
            n = bit_size;
        எனில் (n < 8) {
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
    } போது (bit_size);
    vpop(), vpop();
}

நிலையான முழு adjust_bf(SValue *sv, முழு bit_pos, முழு bit_size)
{
    முழு t;
    எனில் (0 == sv->type.ref)
        திரும்பு 0;
    t = sv->type.ref->auxtype;
    எனில் (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    திரும்பு t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC முழு gv(முழு rc)
{
    முழு r, r2, r_ok, r2_ok, rc2, bt;
    முழு bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    எனில் (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = வெற்று;
        type.t = vtop->type.t & VT_UNSIGNED;
        எனில் ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        எனில் ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        இல்லையெனில்
            type.t |= VT_INT;

        எனில் (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } இல்லையெனில் {
            முழு bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } இல்லையெனில் {
        எனில் (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            எனில் (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        எனில் (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        எனில் (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            திரும்பு vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        எனில் (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        எனில் (!r_ok || !r2_ok) {

            எனில் (!r_ok) {
                எனில் (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                இல்லையெனில்
                    r = get_reg(rc);
            }

            எனில் (rc2) {
                முழு load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                முழு original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                எனில் ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } இல்லையெனில் எனில் (vtop->r & VT_LVAL) {
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
                } இல்லையெனில் {
                    /* move registers */
                    எனில் (!r_ok)
                        load(r, vtop);
                    எனில் (r2_ok && vtop->r2 < VT_CONST)
                        செல் done;
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
            } இல்லையெனில் {
                எனில் (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        எனில் (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    திரும்பு r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC வெறுமை gv2(முழு rc1, முழு rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    எனில் (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        எனில் ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } இல்லையெனில் {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        எனில் ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#எனில் PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC வெறுமை lexpand(வெறுமை)
{
    முழு u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    எனில் (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } இல்லையெனில் எனில் (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } இல்லையெனில் {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#எனில் PTR_SIZE == 4
/* build a long long from two ints */
நிலையான வெறுமை lbuild(முழு t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
நிலையான வெறுமை gv_dup(வெறுமை)
{
    முழு t, rc, r;

    t = vtop->type.t;
#எனில் PTR_SIZE == 4
    எனில் ((t & VT_BTYPE) == VT_LLONG) {
        எனில் (t & VT_BITFIELD) {
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
        திரும்பு;
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

#எனில் PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
நிலையான வெறுமை gen_opl(முழு op)
{
    முழு t, a, b, op1, c, i;
    முழு func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    தேர்வு(op) {
    நிலை '/':
    நிலை TOK_PDIV:
        func = TOK___divdi3;
        செல் gen_func;
    நிலை TOK_UDIV:
        func = TOK___udivdi3;
        செல் gen_func;
    நிலை '%':
        func = TOK___moddi3;
        செல் gen_mod_func;
    நிலை TOK_UMOD:
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
        நிறுத்து;
    நிலை '^':
    நிலை '&':
    நிலை '|':
    நிலை '*':
    நிலை '+':
    நிலை '-':
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
        எனில் (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            க்கு(i=0;i<4;i++)
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
        } இல்லையெனில் எனில் (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            எனில் (op == '+')
                op1 = TOK_ADDC1;
            இல்லையெனில்
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } இல்லையெனில் {
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
        நிறுத்து;
    நிலை TOK_SAR:
    நிலை TOK_SHR:
    நிலை TOK_SHL:
        எனில் ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (முழு)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            எனில் (op != TOK_SHL)
                vswap();
            எனில் (c >= 32) {
                /* stack: L H */
                vpop();
                எனில் (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                எனில் (op != TOK_SAR) {
                    vpushi(0);
                } இல்லையெனில் {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } இல்லையெனில் {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                எனில் (op == TOK_SHL)
                    gen_op(TOK_SHR);
                இல்லையெனில்
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                எனில் (op == TOK_SHL)
                    gen_op(TOK_SHL);
                இல்லையெனில்
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            எனில் (op != TOK_SHL)
                vswap();
            lbuild(t);
        } இல்லையெனில் {
            /* XXX: should provide a faster fallback on x86 ? */
            தேர்வு(op) {
            நிலை TOK_SAR:
                func = TOK___ashrdi3;
                செல் gen_func;
            நிலை TOK_SHR:
                func = TOK___lshrdi3;
                செல் gen_func;
            நிலை TOK_SHL:
                func = TOK___ashldi3;
                செல் gen_func;
            }
        }
        நிறுத்து;
    இயல்பு:
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
        எனில் (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        எனில் (op1 == TOK_LT)
            op1 = TOK_LE;
        இல்லையெனில் எனில் (op1 == TOK_GT)
            op1 = TOK_GE;
        இல்லையெனில் எனில் (op1 == TOK_ULT)
            op1 = TOK_ULE;
        இல்லையெனில் எனில் (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        எனில் (op == TOK_NE) {
            b = gvtst(0, 0);
        } இல்லையெனில் {
            a = gvtst(1, 0);
            எனில் (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        எனில் (op1 == TOK_LT)
            op1 = TOK_ULT;
        இல்லையெனில் எனில் (op1 == TOK_LE)
            op1 = TOK_ULE;
        இல்லையெனில் எனில் (op1 == TOK_GT)
            op1 = TOK_UGT;
        இல்லையெனில் எனில் (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#எனில் 0//def TCC_TARGET_I386
        எனில் (op == TOK_NE) { gsym(b); நிறுத்து; }
        எனில் (op == TOK_EQ) { gsym(a); நிறுத்து; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        நிறுத்து;
    }
}
#endif

/* normalize values */
நிலையான uint64_t value64(uint64_t l1, முழு t)
{
    எனில் ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        திரும்பு l1;
    இல்லையெனில் எனில் (t & VT_UNSIGNED)
        திரும்பு (uint32_t)l1;
    இல்லையெனில்
        திரும்பு (uint32_t)l1 | -(l1 & 0x80000000);
}

நிலையான uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    திரும்பு (a ^ b) >> 63 ? -x : x;
}

நிலையான முழு gen_opic_lt(uint64_t a, uint64_t b)
{
    திரும்பு (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
நிலையான வெறுமை gen_opic(முழு op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    முழு t1 = v1->type.t & VT_BTYPE;
    முழு t2 = v2->type.t & VT_BTYPE;
    முழு c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    முழு c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    முழு shm = (t1 == VT_LLONG) ? 63 : 31;
    முழு r;

    எனில் (c1 && c2) {
        தேர்வு(op) {
        நிலை '+': l1 += l2; நிறுத்து;
        நிலை '-': l1 -= l2; நிறுத்து;
        நிலை '&': l1 &= l2; நிறுத்து;
        நிலை '^': l1 ^= l2; நிறுத்து;
        நிலை '|': l1 |= l2; நிறுத்து;
        நிலை '*': l1 *= l2; நிறுத்து;

        நிலை TOK_PDIV:
        நிலை '/':
        நிலை '%':
        நிலை TOK_UDIV:
        நிலை TOK_UMOD:
            /* if division by zero, generate explicit division */
            எனில் (l2 == 0) {
                எனில் (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                செல் general_case;
            }
            தேர்வு(op) {
            இயல்பு: l1 = gen_opic_sdiv(l1, l2); நிறுத்து;
            நிலை '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); நிறுத்து;
            நிலை TOK_UDIV: l1 = l1 / l2; நிறுத்து;
            நிலை TOK_UMOD: l1 = l1 % l2; நிறுத்து;
            }
            நிறுத்து;
        நிலை TOK_SHL: l1 <<= (l2 & shm); நிறுத்து;
        நிலை TOK_SHR: l1 >>= (l2 & shm); நிறுத்து;
        நிலை TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            நிறுத்து;
            /* tests */
        நிலை TOK_ULT: l1 = l1 < l2; நிறுத்து;
        நிலை TOK_UGE: l1 = l1 >= l2; நிறுத்து;
        நிலை TOK_EQ: l1 = l1 == l2; நிறுத்து;
        நிலை TOK_NE: l1 = l1 != l2; நிறுத்து;
        நிலை TOK_ULE: l1 = l1 <= l2; நிறுத்து;
        நிலை TOK_UGT: l1 = l1 > l2; நிறுத்து;
        நிலை TOK_LT: l1 = gen_opic_lt(l1, l2); நிறுத்து;
        நிலை TOK_GE: l1 = !gen_opic_lt(l1, l2); நிறுத்து;
        நிலை TOK_LE: l1 = !gen_opic_lt(l2, l1); நிறுத்து;
        நிலை TOK_GT: l1 = gen_opic_lt(l2, l1); நிறுத்து;
            /* logical */
        நிலை TOK_LAND: l1 = l1 && l2; நிறுத்து;
        நிலை TOK_LOR: l1 = l1 || l2; நிறுத்து;
        இயல்பு:
            செல் general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } இல்லையெனில் {
        /* if commutative ops, put c2 as constant */
        எனில் (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        எனில் (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } இல்லையெனில் எனில் (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            எனில் (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } இல்லையெனில் எனில் (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } இல்லையெனில் எனில் (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            எனில் (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                முழு n = -1;
                எனில் (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    செல் general_case;
                }
                போது (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                எனில் (op == '*')
                    op = TOK_SHL;
                இல்லையெனில் எனில் (op == TOK_PDIV)
                    op = TOK_SAR;
                இல்லையெனில்
                    op = TOK_SHR;
            }
            செல் general_case;
        } இல்லையெனில் எனில் (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            எனில் (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    எனில் ((முழு)l2 != l2)
	        செல் general_case;
            vtop--;
            vtop->c.i = l2;
        } இல்லையெனில் {
        general_case:
                /* call low level op generator */
                எனில் (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                இல்லையெனில்
                    gen_opi(op);
        }
        எனில் (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#எனில் defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#அல்லதெனில் defined TCC_TARGET_ARM
வெறுமை gen_negf(முழு op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#இல்லையெனில்
/* XXX: implement in gen_opf() for other backends too */
வெறுமை gen_negf(முழு op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    முழு align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#எனில் defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    எனில் (bt == VT_LDOUBLE)
        size = 10;
#endif
    எனில் (nocode_wanted) /* save_reg() wont work */
        செல் gv2;
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
நிலையான வெறுமை gen_opif(முழு op)
{
    முழு c1, c2, i, bt;
    SValue *v1, *v2;
#எனில் defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    நிலையற்ற
#endif
    long இரட்டை f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    எனில் (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    எனில் (c1 && c2) {
        எனில் (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } இல்லையெனில் எனில் (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } இல்லையெனில் {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        எனில் (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            செல் general_case;
        தேர்வு(op) {
        நிலை '+': f1 += f2; நிறுத்து;
        நிலை '-': f1 -= f2; நிறுத்து;
        நிலை '*': f1 *= f2; நிறுத்து;
        நிலை '/': 
            எனில் (f2 == 0.0) {
                ஒன்றிப்பு { தசம f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                எனில் (!CONST_WANTED)
                    செல் general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                எனில் (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                இல்லையெனில்
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                நிறுத்து;
            }
            f1 /= f2;
            நிறுத்து;
        நிலை TOK_NEG:
            f1 = -f1;
            செல் unary_result;
        நிலை TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            திரும்பு;
        நிலை TOK_NE:
            i = f1 != f2;
	    செல் make_int;
        நிலை TOK_LT:
            i = f1 < f2;
	    செல் make_int;
        நிலை TOK_GE:
            i = f1 >= f2;
	    செல் make_int;
        நிலை TOK_LE:
            i = f1 <= f2;
	    செல் make_int;
        நிலை TOK_GT:
            i = f1 > f2;
	    செல் make_int;
        இயல்பு:
            செல் general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        எனில் (bt == VT_FLOAT) {
            v1->c.f = f1;
        } இல்லையெனில் எனில் (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } இல்லையெனில் {
            v1->c.ld = f1;
        }
    } இல்லையெனில் {
    general_case:
        எனில் (op == TOK_NEG) {
            gen_negf(op);
        } இல்லையெனில் {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
நிலையான வெறுமை type_to_str(எழுத்து *buf, முழு buf_size,
                 CType *type, மாறிலி எழுத்து *varstr)
{
    முழு bt, v, t;
    Sym *s, *sa;
    எழுத்து buf1[256];
    மாறிலி எழுத்து *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    எனில் (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    எனில் (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    எனில் (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    எனில் (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    எனில் (bt != VT_PTR) {
        எனில் (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        எனில் (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        எனில் (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    எனில் (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    தேர்வு(bt) {
    நிலை VT_VOID:
        tstr = "void";
        செல் add_tstr;
    நிலை VT_BOOL:
        tstr = "_Bool";
        செல் add_tstr;
    நிலை VT_BYTE:
        tstr = "char";
        செல் add_tstr;
    நிலை VT_SHORT:
        tstr = "short";
        செல் add_tstr;
    நிலை VT_INT:
        tstr = "int";
        செல் maybe_long;
    நிலை VT_LLONG:
        tstr = "long long";
    maybe_long:
        எனில் (t & VT_LONG)
            tstr = "long";
        எனில் (!IS_ENUM(t))
            செல் add_tstr;
        tstr = "enum ";
        செல் tstruct;
    நிலை VT_FLOAT:
        tstr = "float";
        செல் add_tstr;
    நிலை VT_DOUBLE:
        tstr = "double";
        எனில் (!(t & VT_LONG))
            செல் add_tstr;
    நிலை VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        நிறுத்து;
    நிலை VT_STRUCT:
        tstr = "struct ";
        எனில் (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        எனில் (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        இல்லையெனில்
            pstrcat(buf, buf_size, get_tok_str(v, வெற்று));
        நிறுத்து;
    நிலை VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        எனில் (varstr && '*' == *varstr) {
            pstrcat(buf1, அளவு(buf1), "(");
            pstrcat(buf1, அளவு(buf1), varstr);
            pstrcat(buf1, அளவு(buf1), ")");
        }
        pstrcat(buf1, அளவு(buf1), "(");
        sa = s->next;
        போது (sa != வெற்று) {
            எழுத்து buf2[256];
            type_to_str(buf2, அளவு(buf2), &sa->type, வெற்று);
            pstrcat(buf1, அளவு(buf1), buf2);
            sa = sa->next;
            எனில் (sa)
                pstrcat(buf1, அளவு(buf1), ", ");
        }
        எனில் (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, அளவு(buf1), ", ...");
        pstrcat(buf1, அளவு(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        செல் no_var;
    நிலை VT_PTR:
        s = type->ref;
        எனில் (t & (VT_ARRAY|VT_VLA)) {
            எனில் (varstr && '*' == *varstr)
                snprintf(buf1, அளவு(buf1), "(%s)[%d]", varstr, s->c);
            இல்லையெனில்
                snprintf(buf1, அளவு(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            செல் no_var;
        }
        pstrcpy(buf1, அளவு(buf1), "*");
        எனில் (t & VT_RESTRICT)
            pstrcat(buf1, அளவு(buf1), "restrict ");
        எனில் (t & VT_CONSTANT)
            pstrcat(buf1, அளவு(buf1), "const ");
        எனில் (t & VT_VOLATILE)
            pstrcat(buf1, அளவு(buf1), "volatile ");
        எனில் (varstr)
            pstrcat(buf1, அளவு(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        செல் no_var;
    }
    எனில் (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

நிலையான வெறுமை type_incompatibility_error(CType* st, CType* dt, மாறிலி எழுத்து* fmt)
{
    எழுத்து buf1[256], buf2[256];
    type_to_str(buf1, அளவு(buf1), st, வெற்று);
    type_to_str(buf2, அளவு(buf2), dt, வெற்று);
    tcc_error(fmt, buf1, buf2);
}

நிலையான வெறுமை type_incompatibility_warning(CType* st, CType* dt, மாறிலி எழுத்து* fmt)
{
    எழுத்து buf1[256], buf2[256];
    type_to_str(buf1, அளவு(buf1), st, வெற்று);
    type_to_str(buf2, அளவு(buf2), dt, வெற்று);
    tcc_warning(fmt, buf1, buf2);
}

நிலையான முழு pointed_size(CType *type)
{
    முழு align;
    திரும்பு type_size(pointed_type(type), &align);
}

நிலையான உள்வரி முழு is_null_pointer(SValue *p)
{
    எனில் ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        திரும்பு 0;
    திரும்பு ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
நிலையான முழு is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    எனில் (s1->f.func_call != s2->f.func_call)
        திரும்பு 0;
    எனில் (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        திரும்பு 0;
    க்கு (;;) {
        எனில் (!is_compatible_unqualified_types(&s1->type, &s2->type))
            திரும்பு 0;
        எனில் (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            திரும்பு 1;
        s1 = s1->next;
        s2 = s2->next;
        எனில் (!s1)
            திரும்பு !s2;
        எனில் (!s2)
            திரும்பு 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
நிலையான முழு compare_types(CType *type1, CType *type2, முழு unqualified)
{
    முழு bt1, t1, t2;

    எனில் (IS_ENUM(type1->t)) {
        எனில் (IS_ENUM(type2->t))
            திரும்பு type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } இல்லையெனில் எனில் (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    எனில் (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    எனில் ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    எனில் (t1 != t2)
        திரும்பு 0;

    எனில் ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            திரும்பு 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    எனில் (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        எனில் (unqualified && (t1 & VT_ARRAY))
            திரும்பு compare_types(type1, type2, 1);
        திரும்பு is_compatible_types(type1, type2);
    } இல்லையெனில் எனில் (bt1 == VT_STRUCT) {
        திரும்பு (type1->ref == type2->ref);
    } இல்லையெனில் எனில் (bt1 == VT_FUNC) {
        திரும்பு is_compatible_func(type1, type2);
    } இல்லையெனில் {
        திரும்பு 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
நிலையான முழு combine_types(CType *dest, SValue *op1, SValue *op2, முழு op)
{
    CType *type1, *type2, type;
    முழு t1, t2, bt1, bt2;
    முழு ret = 1;

    /* for shifts, 'combine' only left operand */
    எனில் (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = வெற்று;

    எனில் (bt1 == VT_VOID || bt2 == VT_VOID) {
        எனில் (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } இல்லையெனில் எனில் (bt1 == VT_PTR || bt2 == VT_PTR) {
        எனில் (op == '+') {
          எனில் (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        இல்லையெனில் எனில் (is_null_pointer (op2)) type = *type1;
        இல்லையெனில் எனில் (is_null_pointer (op1)) type = *type2;
        இல்லையெனில் எனில் (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            எனில் ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            இல்லையெனில் எனில் (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } இல்லையெனில் {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            முழு pbt1 = pt1->t & VT_BTYPE;
            முழு pbt2 = pt2->t & VT_BTYPE;
            முழு newquals, copied = 0;
            எனில் (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                எனில் (op != '?' && op != CMP_OP)
                  ret = 0;
                இல்லையெனில்
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            எனில் (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                எனில் ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_தள்ளு(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                எனில் (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    எனில் (!copied)
                      type.ref = sym_தள்ளு(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_தள்ளு(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        எனில் (op == CMP_OP)
          type.t = VT_SIZE_T;
    } இல்லையெனில் எனில் (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        எனில் (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } இல்லையெனில் எனில் (is_float(bt1) || is_float(bt2)) {
        எனில் (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } இல்லையெனில் எனில் (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } இல்லையெனில் {
            type.t = VT_FLOAT;
        }
    } இல்லையெனில் எனில் (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        எனில் (bt1 == VT_LLONG)
          type.t &= t1;
        எனில் (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        எனில் ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } இல்லையெனில் {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        எனில் (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    எனில் (dest)
      *dest = type;
    திரும்பு ret;
}

/* generic gen_op: handles types problems */
ST_FUNC வெறுமை gen_op(முழு op)
{
    முழு t1, t2, bt1, bt2, t;
    CType type1, combtype;
    முழு op_class = op;

    எனில் (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    இல்லையெனில் எனில் (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    எனில் (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	எனில் (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	எனில் (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	செல் redo;
    } இல்லையெனில் எனில் (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } இல்லையெனில் எனில் (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        முழு align;
        எனில் (op_class == CMP_OP)
            செல் std_op;
        /* if both pointers, then it must be the '-' op */
        எனில் (bt1 == VT_PTR && bt2 == VT_PTR) {
            எனில் (op != '-')
                செல் op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } இல்லையெனில் {
            /* exactly one pointer : must be '+' or '-'. */
            எனில் (op != '-' && op != '+')
                செல் op_err;
            /* Put pointer as first operand */
            எனில் (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#எனில் PTR_SIZE == 4
            எனில் (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            எனில் (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                எனில் (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } இல்லையெனில்
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } இல்லையெனில் {
        /* floats can only be used for a few operations */
        எனில் (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            செல் op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        எனில் (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        எனில் (t & VT_UNSIGNED) {
            எனில் (op == TOK_SAR)
                op = TOK_SHR;
            இல்லையெனில் எனில் (op == '/')
                op = TOK_UDIV;
            இல்லையெனில் எனில் (op == '%')
                op = TOK_UMOD;
            இல்லையெனில் எனில் (op == TOK_LT)
                op = TOK_ULT;
            இல்லையெனில் எனில் (op == TOK_GT)
                op = TOK_UGT;
            இல்லையெனில் எனில் (op == TOK_LE)
                op = TOK_ULE;
            இல்லையெனில் எனில் (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        எனில் (is_float(t))
            gen_opif(op);
        இல்லையெனில்
            gen_opic(op);
        எனில் (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } இல்லையெனில் {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    எனில் (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#எனில் defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#இல்லையெனில்
/* generic itof for unsigned long long case */
நிலையான வெறுமை gen_cvt_itof1(முழு t)
{
    எனில் ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        எனில் (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#எனில் LDOUBLE_SIZE != 8
        இல்லையெனில் எனில் (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        இல்லையெனில்
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } இல்லையெனில் {
        gen_cvt_itof(t);
    }
}
#endif

#எனில் defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#இல்லையெனில்
/* generic ftoi for unsigned long long case */
நிலையான வெறுமை gen_cvt_ftoi1(முழு t)
{
    முழு st;
    எனில் (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        எனில் (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#எனில் LDOUBLE_SIZE != 8
        இல்லையெனில் எனில் (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        இல்லையெனில்
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } இல்லையெனில் {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
நிலையான வெறுமை force_charshort_cast(வெறுமை)
{
    முழு sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    முழு dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

நிலையான வெறுமை gen_cast_s(முழு t)
{
    CType type;
    type.t = t;
    type.ref = வெற்று;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
நிலையான வெறுமை gen_cast(CType *type)
{
    முழு sbt, dbt, sf, df, c;
    முழு dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    எனில் (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    எனில் (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    எனில் (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    எனில் (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    எனில் (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        எனில் (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            செல் done;
        }
        எனில் (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        எனில் (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            எனில் (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            இல்லையெனில் எனில் (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            எனில் (df) {
                எனில் (sbt_bt == VT_LLONG) {
                    எனில் ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    இல்லையெனில்
                        vtop->c.ld = -(long இரட்டை)-vtop->c.i;
                } இல்லையெனில் எனில்(!sf) {
                    எனில் ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    இல்லையெனில்
                        vtop->c.ld = -(long இரட்டை)-(uint32_t)vtop->c.i;
                }

                எனில் (dbt == VT_FLOAT)
                    vtop->c.f = (தசம)vtop->c.ld;
                இல்லையெனில் எனில் (dbt == VT_DOUBLE)
                    vtop->c.d = (இரட்டை)vtop->c.ld;
            } இல்லையெனில் எனில் (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } இல்லையெனில் {
                எனில்(sf) {
                    எனில் (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    இல்லையெனில்
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                இல்லையெனில் எனில் (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                இல்லையெனில் எனில் (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                இல்லையெனில்
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                எனில் (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                இல்லையெனில் எனில் (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                இல்லையெனில் {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    எனில் (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            செல் done;

        } இல்லையெனில் எனில் (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            செல் done;
        }

        /* cannot generate code for global or static initializers */
        எனில் (nocode_wanted & DATA_ONLY_WANTED) {
            எனில் (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            செல் done;
        }

        /* non constant case: generate code */
        எனில் (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            செல் done;
        }

        எனில் (sf || df) {
            எனில் (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } இல்லையெனில் எனில் (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } இல்லையெனில் {
                /* convert fp to int */
                sbt = dbt;
                எனில் (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                செல் again; /* may need char/short cast */
            }
            செல் done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        எனில் (ds == 0 || ss == 0)
            செல் error;

        /* same size and no sign conversion needed */
        எனில் (ds == ss && ds >= 4)
            செல் done;
        எனில் (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            எனில் (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        எனில் (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            எனில் (ds <= ss)
                செல் done;
            /* ss <= 4 here */
            எனில் (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                செல் done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#எனில் PTR_SIZE == 4
        எனில் (ds == 8) {
            /* generate high word */
            எனில் (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } இல்லையெனில் {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } இல்லையெனில் எனில் (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#அல்லதெனில் PTR_SIZE == 8
        எனில் (ds == 8) {
            /* need to convert from 32bit to 64bit */
            எனில் (sbt & VT_UNSIGNED) {
#எனில் defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#இல்லையெனில்
                செல் done;
#endif
            } இல்லையெனில் {
                gen_cvt_sxtw();
                செல் done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } இல்லையெனில் எனில் (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#எனில் !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } இல்லையெனில் {
            ss = 4;
        }
#endif

        எனில் (ds >= ss)
            செல் done;
#எனில் defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    எனில் (ss == 4) {
        gen_cvt_csti(dbt);
        செல் done;
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
ST_FUNC முழு type_size(CType *type, முழு *a)
{
    Sym *s;
    முழு bt;

    bt = type->t & VT_BTYPE;
    எனில் (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        திரும்பு s->c;
    } இல்லையெனில் எனில் (bt == VT_PTR) {
        எனில் (type->t & VT_ARRAY) {
            முழு ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            எனில் (s->c < 0)
                திரும்பு s->c;
            திரும்பு ts * s->c;
        } இல்லையெனில் {
            *a = PTR_SIZE;
            திரும்பு PTR_SIZE;
        }
    } இல்லையெனில் எனில் (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        திரும்பு -1; /* incomplete enum */
    } இல்லையெனில் எனில் (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        திரும்பு LDOUBLE_SIZE;
    } இல்லையெனில் எனில் (bt == VT_DOUBLE || bt == VT_LLONG) {
#எனில் (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#இல்லையெனில்
        *a = 8;
#endif
        திரும்பு 8;
    } இல்லையெனில் எனில் (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        திரும்பு 4;
    } இல்லையெனில் எனில் (bt == VT_SHORT) {
        *a = 2;
        திரும்பு 2;
    } இல்லையெனில் எனில் (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        திரும்பு 16;
    } இல்லையெனில் {
        /* char, void, function, _Bool */
        *a = 1;
        திரும்பு 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
நிலையான வெறுமை vpush_type_size(CType *type, முழு *a)
{
    எனில் (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } இல்லையெனில் {
        முழு size = type_size(type, a);
        எனில் (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
நிலையான உள்வரி CType *pointed_type(CType *type)
{
    திரும்பு &type->ref->type;
}

நிலையான வெறுமை check_restrict_type(CType *type)
{
    போது ((type->t & VT_BTYPE) == VT_PTR) {
        எனில் ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    எனில் (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
நிலையான முழு type_qualifiers(CType *type)
{
    போது (type->t & VT_ARRAY)
        type = pointed_type(type);
    திரும்பு type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC வெறுமை mk_pointer(CType *type)
{
    Sym *s;
    s = sym_தள்ளு(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
நிலையான முழு is_compatible_types(CType *type1, CType *type2)
{
    திரும்பு compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
நிலையான முழு is_compatible_unqualified_types(CType *type1, CType *type2)
{
    திரும்பு compare_types(type1,type2,1);
}

நிலையான வெறுமை cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
நிலையான வெறுமை verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    முழு dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    எனில் (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    தேர்வு(dbt) {
    நிலை VT_VOID:
        எனில் (sbt != dbt)
            tcc_error("assignment to void expression");
        நிறுத்து;
    நிலை VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        எனில் (is_null_pointer(vtop))
            நிறுத்து;
        /* accept implicit pointer to integer cast with warning */
        எனில் (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            நிறுத்து;
        }
        type1 = pointed_type(dt);
        எனில் (sbt == VT_PTR)
            type2 = pointed_type(st);
        இல்லையெனில் எனில் (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        இல்லையெனில்
            செல் error;
        எனில் (is_compatible_types(type1, type2))
            நிறுத்து;
        க்கு (qualwarn = lvl = 0;; ++lvl) {
            எனில் ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            எனில் (dbt != VT_PTR || sbt != VT_PTR)
                நிறுத்து;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        எனில் (!is_compatible_unqualified_types(type1, type2)) {
            எனில் ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } இல்லையெனில் எனில் (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } இல்லையெனில் {
                tcc_warning("assignment from incompatible pointer type");
                நிறுத்து;
            }
        }
        எனில் (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        நிறுத்து;
    நிலை VT_BYTE:
    நிலை VT_SHORT:
    நிலை VT_INT:
    நிலை VT_LLONG:
        எனில் (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } இல்லையெனில் எனில் (sbt == VT_STRUCT) {
            செல் case_VT_STRUCT;
        }
        /* XXX: more tests */
        நிறுத்து;
    நிலை VT_STRUCT:
    case_VT_STRUCT:
        எனில் (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        நிறுத்து;
    }
}

நிலையான வெறுமை gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC வெறுமை vstore(வெறுமை)
{
    முழு sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    எனில் (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        எனில் (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        எனில் (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        எனில் (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } இல்லையெனில்
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            எனில்(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            இல்லையெனில் எனில்(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            இல்லையெனில்
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } இல்லையெனில் எனில் (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        எனில் (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        எனில் (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        எனில் (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } இல்லையெனில் {
            unsigned long long mask = (1ULL << bit_size) - 1;
            எனில் (dbt != VT_BOOL) {
                /* mask source */
                எனில் (dbt == VT_LLONG)
                    vpushll(mask);
                இல்லையெனில்
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
            எனில் (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            இல்லையெனில்
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } இல்லையெனில் எனில் (dbt == VT_VOID) {
        --vtop;
    } இல்லையெனில் {
            /* optimize char/short casts */
            delayed_cast = 0;
            எனில் ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                எனில் ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } இல்லையெனில் {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            எனில் (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            எனில் (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            எனில் ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = வெற்று;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            எனில் (USING_TWO_சொற்கள்(dbt)) {
                முழு load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } இல்லையெனில் {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC வெறுமை inc(முழு post, முழு c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    எனில் (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    எனில் (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (மாறிலி எழுத்து *செய்தி)
{
    /* read the string */
    எனில் (tok != TOK_STR)
        expect(செய்தி);
    cstr_reset(&initstr);
    போது (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    திரும்பு &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC முழு exact_log2p1(முழு i)
{
  முழு ret;
  எனில் (!i)
    திரும்பு 0;
  க்கு (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  எனில் (i >= 1 << 4)
    ret += 4, i >>= 4;
  எனில் (i >= 1 << 2)
    ret += 2, i >>= 2;
  எனில் (i >= 1 << 1)
    ret++;
  திரும்பு ret;
}

/* Parse __attribute__((...)) GNUC extension. */
நிலையான வெறுமை parse_attribute(AttributeDef *ad)
{
    முழு t, n;
    எழுத்து *astr;
    AttributeDef ad_tmp;
    
redo:
    எனில் (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        திரும்பு;
    எனில் (வெற்று == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    போது (tok != ')') {
        எனில் (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        தேர்வு(t) {
	நிலை TOK_CLEANUP1:
	நிலை TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    எனில் (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } இல்லையெனில் எனில் ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    நிறுத்து;
	}
        நிலை TOK_CONSTRUCTOR1:
        நிலை TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            நிறுத்து;
        நிலை TOK_DESTRUCTOR1:
        நிலை TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            நிறுத்து;
        நிலை TOK_ALWAYS_INLINE1:
        நிலை TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            நிறுத்து;
        நிலை TOK_SECTION1:
        நிலை TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            நிறுத்து;
        நிலை TOK_ALIAS1:
        நிலை TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            நிறுத்து;
	நிலை TOK_VISIBILITY1:
	நிலை TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    எனில் (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    இல்லையெனில் எனில் (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    இல்லையெனில் எனில் (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    இல்லையெனில் எனில் (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    இல்லையெனில்
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            நிறுத்து;
        நிலை TOK_ALIGNED1:
        நிலை TOK_ALIGNED2:
            எனில் (tok == '(') {
                next();
                n = கோவை_const();
                எனில் (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } இல்லையெனில் {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    எனில் (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            நிறுத்து;
        நிலை TOK_PACKED1:
        நிலை TOK_PACKED2:
            ad->a.packed = 1;
            நிறுத்து;
        நிலை TOK_WEAK1:
        நிலை TOK_WEAK2:
            ad->a.weak = 1;
            நிறுத்து;
        நிலை TOK_NODEBUG1:
        நிலை TOK_NODEBUG2:
            ad->a.nodebug = 1;
            நிறுத்து;
        நிலை TOK_USED1:
        நிலை TOK_USED2:
        நிலை TOK_UNUSED1:
        நிலை TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            நிறுத்து;
        நிலை TOK_CONST1:
        நிலை TOK_CONST2:
        நிலை TOK_CONST3:
        நிலை TOK_PURE1:
        நிலை TOK_PURE2:
	    /* ignored */
            நிறுத்து;
        நிலை TOK_NOINLINE:
	    /* ignored */
	    நிறுத்து;
        நிலை TOK_FORMAT1:
        நிலை TOK_FORMAT2:
	    /* ignored */
            செல் skip_param;
        நிலை TOK_NORETURN1:
        நிலை TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            நிறுத்து;
        நிலை TOK_CDECL1:
        நிலை TOK_CDECL2:
        நிலை TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            நிறுத்து;
        நிலை TOK_STDCALL1:
        நிலை TOK_STDCALL2:
        நிலை TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            நிறுத்து;
#ifdef TCC_TARGET_I386
        நிலை TOK_REGPARM1:
        நிலை TOK_REGPARM2:
            skip('(');
            n = கோவை_const();
            எனில் (n > 3) 
                n = 3;
            இல்லையெனில் எனில் (n < 0)
                n = 0;
            எனில் (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            நிறுத்து;
        நிலை TOK_FASTCALL1:
        நிலை TOK_FASTCALL2:
        நிலை TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            நிறுத்து;
        நிலை TOK_THISCALL1:
        நிலை TOK_THISCALL2:
        நிலை TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            நிறுத்து;
#endif
        நிலை TOK_MODE:
            skip('(');
            தேர்வு(tok) {
                நிலை TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    நிறுத்து;
                நிலை TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    நிறுத்து;
                நிலை TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    நிறுத்து;
                நிலை TOK_MODE_SI:
                நிலை TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    நிறுத்து;
                இயல்பு:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, வெற்று));
                    நிறுத்து;
            }
            next();
            skip(')');
            நிறுத்து;
        நிலை TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            நிறுத்து;
        நிலை TOK_NODECORATE:
            ad->a.nodecorate = 1;
            நிறுத்து;
        நிலை TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            நிறுத்து;
        இயல்பு:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, வெற்று));
            /* skip parameters */
skip_param:
            எனில் (tok == '(') {
                முழு parenthesis = 0;
                செய் {
                    எனில் (tok == '(') 
                        parenthesis++;
                    இல்லையெனில் எனில் (tok == ')') 
                        parenthesis--;
                    next();
                } போது (parenthesis && tok != -1);
            }
            நிறுத்து;
        }
        எனில் (tok != ',')
            நிறுத்து;
        next();
    }
    skip(')');
    skip(')');
    செல் redo;
}

நிலையான Sym * find_field (CType *type, முழு v, முழு *cumofs)
{
    Sym *s = type->ref;
    முழு v1 = v | SYM_FIELD;
    எனில் (!(v & SYM_FIELD)) { /* top-level call */
        எனில் ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        எனில் (v < TOK_UIDENT)
            expect("field name");
        எனில் (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    போது ((s = s->next) != வெற்று) {
        எனில் (s->v == v1) {
            *cumofs = s->c;
            திரும்பு s;
        }
        எனில் ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            எனில் (ret) {
                *cumofs += s->c;
                திரும்பு ret;
            }
        }
    }
    எனில் (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, வெற்று));
    திரும்பு s;
}

நிலையான வெறுமை check_fields (CType *type, முழு check)
{
    Sym *s = type->ref;

    போது ((s = s->next) != வெற்று) {
        முழு v = s->v & ~SYM_FIELD;
        எனில் (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            எனில் (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, வெற்று));
            ts->tok ^= SYM_FIELD;
        } இல்லையெனில் எனில் ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

நிலையான வெறுமை struct_layout(CType *type, AttributeDef *ad)
{
    முழு size, align, maxalign, offset, c, bit_pos, bit_size;
    முழு packed, a, bt, prevbt, prev_bit_size;
    முழு pcc = !tcc_state->ms_bitfields;
    முழு pragma_pack = *tcc_state->pack_அடுக்கு_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    க்கு (f = type->ref->next; f; f = f->next) {
        எனில் (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        இல்லையெனில்
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        எனில் (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } இல்லையெனில் {
            /* in pcc mode, attribute packed overrides if set. */
            எனில் (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            எனில் (pragma_pack) {
                packed = 1;
                எனில் (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                எனில் (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        எனில் (a)
            align = a;

        எனில் (type->ref->type.t == VT_UNION) {
	    எனில் (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    எனில் (size > c)
	        c = size;

	} இல்லையெனில் எனில் (bit_size < 0) {
            எனில் (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    எனில் (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} இல்லையெனில் {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            எனில் (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                எனில் (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } இல்லையெனில் எனில் (f->a.aligned) {
                    செல் new_field;
                } இல்லையெனில் எனில் (!packed) {
                    முழு a8 = align * 8;
	            முழு ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    எனில் (ofs > size / align)
                        செல் new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                எனில் (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                போது (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		எனில் (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } இல்லையெனில் {
		bt = f->type.t & VT_BTYPE;
		எனில் ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    எனில் (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		எனில் (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	எனில் (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, வெற்று), offset, size, align);
	எனில் (f->type.t & VT_BITFIELD) {
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

    எனில் (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    எனில் (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    எனில் (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        எனில் (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    க்கு (f = type->ref->next; f; f = f->next) {
        முழு s, px, cx, c0;
        CType t;

        எனில் (0 == (f->type.t & VT_BITFIELD))
            தொடர்;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        எனில் (bit_size == 0)
            தொடர்;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        எனில் (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            தொடர்;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        க்கு (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            எனில் (c0 == cx)
                நிறுத்து;
            s = (px + bit_size + 7) >> 3;
            எனில் (s > 4) {
                t.t = VT_LLONG;
            } இல்லையெனில் எனில் (s > 2) {
                t.t = VT_INT;
            } இல்லையெனில் எனில் (s > 1) {
                t.t = VT_SHORT;
            } இல்லையெனில் {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        எனில் (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            எனில் (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, வெற்று),
                cx, s, align, px, bit_size);
#endif
        } இல்லையெனில் {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, வெற்று));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
நிலையான முழு in_range(long long n, முழு t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    எனில் (t & VT_UNSIGNED)
        திரும்பு n <= (m << 1) + 1;
    திரும்பு n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
நிலையான வெறுமை struct_decl(CType *type, முழு u)
{
    முழு v, c, size, align, flexible;
    முழு bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, அளவு ad);
    next();
    parse_attribute(&ad);

    v = 0;
    எனில் (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    எனில் (u == VT_ENUM) {
        ut = VT_INT;
        எனில் (tok == ':') { /* C2x enum : <type> ... */
            next();
            எனில் (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    எனில் (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        எனில் (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            எனில் (u == s->type.t)
                செல் do_decl;
            எனில் (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                செல் do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, வெற்று));
        }
    } இல்லையெனில் {
        எனில் (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = வெற்று;
    /* we put an undefined size for struct/union */
    s = sym_தள்ளு(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    எனில் (tok == '{') {
        next();
        எனில் (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        எனில் (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            எனில் (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            க்கு(;;) {
                v = tok;
                எனில் (v < TOK_UIDENT)
                    expect("identifier");
                next();
                எனில் (tok == '=') {
                    next();
		    ll = கோவை_const64();
                }
                எனில் (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, வெற்று));
                ss = sym_தள்ளு(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                எனில் (ll < nl)
                    nl = ll;
                எனில் (ll > pl)
                    pl = ll;
                எனில் (tok != ',')
                    நிறுத்து;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                எனில் (tok == '}')
                    நிறுத்து;
            }
            skip('}');

            எனில் (bt) {
                t.t = bt;
                s->c = 2;
                செல் enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            எனில் (nl >= 0) {
                எனில் (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } இல்லையெனில் எனில் (pl != (முழு)pl || nl != (முழு)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            க்கு (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                எனில் (ll == (முழு)ll) /* default is int if it fits */
                    தொடர்;
                எனில் (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    எனில் (ll == (unsigned)ll)
                        தொடர்;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } இல்லையெனில் {
            c = 0;
            flexible = 0;
            போது (tok != '}') {
                எனில் (!parse_btype(&btype, &ad1, 0)) {
                    எனில் (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        தொடர்;
                    }
		    skip(';');
		    தொடர்;
		}
                போது (1) {
		    எனில் (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, வெற்று));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    எனில் (tok != ':') {
			எனில் (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        எனில் (v == 0) {
                    	    எனில் ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    இல்லையெனில் {
				முழு v = btype.ref->v;
				எனில் ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    எனில் (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        எனில் (type_size(&type1, &align) < 0) {
			    எனில் ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    இல்லையெனில்
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, வெற்று));
                        }
                        எனில் ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, வெற்று));
                    }
                    எனில் (tok == ':') {
                        next();
                        bit_size = கோவை_const();
                        /* XXX: handle v = 0 case for messages */
                        எனில் (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, வெற்று));
                        எனில் (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, வெற்று));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    எனில் (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        எனில் (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        எனில் (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, வெற்று));
                        } இல்லையெனில் எனில் (bit_size == bsize
				    && !*tcc_state->pack_அடுக்கு_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } இல்லையெனில் எனில் (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } இல்லையெனில் {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    எனில் (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    எனில் (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    எனில் (v) {
                        ss = sym_தள்ளு(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    எனில் (tok == ';' || tok == TOK_EOF)
                        நிறுத்து;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            எனில் (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        எனில் (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

நிலையான வெறுமை sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
நிலையான வெறுமை parse_btype_qualify(CType *type, முழு qualifiers)
{
    போது (type->t & VT_ARRAY) {
        type->ref = sym_தள்ளு(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    எனில் (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
நிலையான முழு parse_btype(CType *type, AttributeDef *ad, முழு ignore_label)
{
    முழு t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, அளவு(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = வெற்று;

    போது(1) {
        தேர்வு(tok) {
        நிலை TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            தொடர்;

            /* basic types */
        நிலை TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            எனில் (u == VT_SHORT || u == VT_LONG) {
                எனில் (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } இல்லையெனில் {
                எனில் (bt != -1 || (st != -1 && u != VT_INT))
                    செல் tmbt;
                எனில் ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    செல் tmbt;
                bt = u;
            }
            எனில் (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            நிறுத்து;
        நிலை TOK_VOID:
            u = VT_VOID;
            செல் basic_type;
        நிலை TOK_SHORT:
            u = VT_SHORT;
            செல் basic_type;
        நிலை TOK_INT:
            u = VT_INT;
            செல் basic_type;
        நிலை TOK_ALIGNAS:
            { முழு n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, அளவு(AttributeDef));
              எனில் (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  எனில் (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  இல்லையெனில்
                    type_size(&type1, &n);
              } இல்லையெனில் {
                  n = கோவை_const();
                  எனில் (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            தொடர்;
        நிலை TOK_LONG:
            எனில் ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } இல்லையெனில் எனில் ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } இல்லையெனில் {
                u = VT_LONG;
                செல் basic_type;
            }
            next();
            நிறுத்து;
        நிலை TOK_BOOL:
            u = VT_BOOL;
            செல் basic_type;
        நிலை TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        நிலை TOK_FLOAT:
            u = VT_FLOAT;
            செல் basic_type;
        நிலை TOK_DOUBLE:
            எனில் ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } இல்லையெனில் {
                u = VT_DOUBLE;
                செல் basic_type;
            }
            next();
            நிறுத்து;
        நிலை TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            செல் basic_type1;
        நிலை TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            செல் basic_type2;
        நிலை TOK_UNION:
            struct_decl(&type1, VT_UNION);
            செல் basic_type2;

            /* type modifiers */
        நிலை TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            எனில் (tok == '(') {
                parse_கோவை_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                எனில் (type1.ref)
                    sym_to_attr(ad, type1.ref);
                செல் basic_type2;
            }
            நிறுத்து;
        நிலை TOK_CONST1:
        நிலை TOK_CONST2:
        நிலை TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            நிறுத்து;
        நிலை TOK_VOLATILE1:
        நிலை TOK_VOLATILE2:
        நிலை TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            நிறுத்து;
        நிலை TOK_SIGNED1:
        நிலை TOK_SIGNED2:
        நிலை TOK_SIGNED3:
            எனில் ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            நிறுத்து;
        நிலை TOK_RESTRICT1:
        நிலை TOK_RESTRICT2:
        நிலை TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            நிறுத்து;
        நிலை TOK_REGISTER:
        நிலை TOK_AUTO:
            next();
            நிறுத்து;
        நிலை TOK_UNSIGNED:
            எனில் ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            நிறுத்து;

            /* storage */
        நிலை TOK_EXTERN:
            g = VT_EXTERN;
            செல் storage;
        நிலை TOK_STATIC:
            g = VT_STATIC;
            செல் storage;
        நிலை TOK_TYPEDEF:
            g = VT_TYPEDEF;
            செல் storage;
       storage:
            எனில் (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            நிறுத்து;
        நிலை TOK_INLINE1:
        நிலை TOK_INLINE2:
        நிலை TOK_INLINE3:
            t |= VT_INLINE;
            next();
            நிறுத்து;
        நிலை TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            நிறுத்து;
            /* GNUC attribute */
        நிலை TOK_ATTRIBUTE1:
        நிலை TOK_ATTRIBUTE2:
            parse_attribute(ad);
            எனில் (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            தொடர்;
            /* GNUC typeof */
        நிலை TOK_TYPEOF1:
        நிலை TOK_TYPEOF2:
        நிலை TOK_TYPEOF3:
            next();
            parse_கோவை_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            எனில் (type1.ref) {
                sym_to_attr(ad, type1.ref);
                எனில் (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            செல் basic_type2;
        நிலை TOK_THREAD_LOCAL:
        நிலை TOK___thread:
            எனில் (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            நிறுத்து;
        இயல்பு:
            எனில் (typespec_found)
                செல் the_end;
            s = sym_find(tok);
            எனில் (!s || !(s->type.t & VT_TYPEDEF))
                செல் the_end;

            n = tok, next();
            எனில் (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                செல் the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            எனில் (t)
                parse_btype_qualify(type, t);
            t = type->t;
            எனில் (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            நிறுத்து;
        }
        type_found = 1;
    }
the_end:
    எனில் (tcc_state->char_is_unsigned) {
        எனில் ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    எனில் (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    எனில் (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    திரும்பு type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
நிலையான உள்வரி வெறுமை convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    எனில் ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
நிலையான உள்வரி வெறுமை convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(வெறுமை)
{
    skip('(');
    திரும்பு parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
நிலையான முழு asm_label_instr(வெறுமை)
{
    முழு v;
    எழுத்து *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    திரும்பு v;
}

நிலையான முழு post_type(CType *type, AttributeDef *ad, முழு storage, முழு td)
{
    முழு n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = வெற்று;
    முழு *vla_array_str = வெற்று;

    எனில் (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	எனில் (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  திரும்பு 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_அடுக்கு ? &local_அடுக்கு : &global_அடுக்கு;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	எனில் (tok == ')')
	  l = 0;
	இல்லையெனில் எனில் (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	இல்லையெனில் எனில் (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_எடு(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    திரும்பு 0;
	} இல்லையெனில்
	  l = FUNC_OLD;

        first = வெற்று;
        plast = &first;
        arg_size = 0;
        எனில் (l) {
            க்கு(;;) {
                /* read param name and compute offset */
                எனில் (l != FUNC_OLD) {
                    எனில் ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        நிறுத்து;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    எனில் ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    எனில் (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } இல்லையெனில் {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = வெற்று;
                    next();
                }
                எனில் (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_தள்ளு(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                எனில் (tok == ')')
                    நிறுத்து;
                skip(',');
                எனில் (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    நிறுத்து;
                }
		எனில் (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } இல்லையெனில்
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        எனில் (tok == '[') {
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
        sym_எடு(ps, sr, 1);
        --local_scope;

    } இல்லையெனில் எனில் (tok == '[') {
	முழு saved_nocode_wanted = nocode_wanted;
        முழு array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        எனில் (td & TYPE_PARAM) போது (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    தேர்வு (tok) {
	    நிலை TOK_CONST1: நிலை TOK_CONST2: நிலை TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		தொடர்;
	    நிலை TOK_VOLATILE1: நிலை TOK_VOLATILE2: நிலை TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		தொடர்;
	    நிலை TOK_RESTRICT1: நிலை TOK_RESTRICT2: நிலை TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		தொடர்;
	    நிலை TOK_STATIC:
	    நிலை '*':
		next();
		தொடர்;
	    இயல்பு:
		நிறுத்து;
	    }
            எனில் (tok != ']') {
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
		செல் check;
            }
            நிறுத்து;

	} இல்லையெனில் எனில் (tok != ']') {
            எனில் (!local_அடுக்கு || (storage & VT_STATIC))
                vpushi(கோவை_const());
            இல்லையெனில் {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            எனில் ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                எனில் (n < 0)
                    tcc_error("invalid array size");
            } இல்லையெனில் {
                எனில் (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        எனில் ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        எனில் ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        எனில் (t1 & VT_VLA) {
            எனில் (n < 0) {
		எனில்  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    இல்லையெனில் {
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
        எனில் (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_தள்ளு(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        எனில் (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    எனில் ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    இல்லையெனில்
	        tok_str_free_str(vla_array_str);
	}
    }
    திரும்பு 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
நிலையான CType *type_decl(CType *type, AttributeDef *ad, முழு *v, முழு td)
{
    CType *post, *ret;
    முழு qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    போது (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        தேர்வு(tok) {
        நிலை TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            செல் redo;
        நிலை TOK_CONST1:
        நிலை TOK_CONST2:
        நிலை TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            செல் redo;
        நிலை TOK_VOLATILE1:
        நிலை TOK_VOLATILE2:
        நிலை TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            செல் redo;
        நிலை TOK_RESTRICT1:
        நிலை TOK_RESTRICT2:
        நிலை TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            செல் redo;
	/* XXX: clarify attribute handling */
	நிலை TOK_ATTRIBUTE1:
	நிலை TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    நிறுத்து;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	எனில் (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    எனில் (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	எனில் (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} இல்லையெனில்
	  செல் abstract;
    } இல்லையெனில் எனில் (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } இல்லையெனில் {
  abstract:
	எனில் (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    திரும்பு ret;
}

/* indirection with full error checking and bound check */
ST_FUNC வெறுமை indir(வெறுமை)
{
    எனில் ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        எனில் ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            திரும்பு;
        expect("pointer");
    }
    எனில் (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    எனில் (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        எனில் (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
நிலையான வெறுமை gfunc_param_typed(Sym *func, Sym *arg)
{
    முழு func_type;
    CType type;

    func_type = func->f.func_type;
    எனில் (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == வெற்று)) {
        /* default casting : only need to convert float to double */
        எனில் ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } இல்லையெனில் எனில் (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } இல்லையெனில் எனில் (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } இல்லையெனில் எனில் (arg == வெற்று) {
        tcc_error("too many arguments to function");
    } இல்லையெனில் {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
நிலையான வெறுமை கோவை_type(CType *type, வெறுமை (*கோவை_fn)(வெறுமை))
{
    nocode_wanted++;
    கோவை_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
நிலையான வெறுமை parse_கோவை_type(CType *type)
{
    முழு n;
    AttributeDef ad;

    skip('(');
    எனில் (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } இல்லையெனில் {
        கோவை_type(type, gexpr);
    }
    skip(')');
}

நிலையான வெறுமை parse_type(CType *type)
{
    AttributeDef ad;
    முழு n;

    எனில் (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

நிலையான வெறுமை parse_builtin_params(முழு nc, மாறிலி எழுத்து *args)
{
    எழுத்து c, sep = '(';
    CType type;
    எனில் (nc)
        nocode_wanted++;
    next();
    எனில் (*args == 0)
	skip(sep);
    போது ((c = *args++)) {
	skip(sep);
	sep = ',';
        எனில் (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    தொடர்;
        }
        கோவை_eq();
        type.ref = வெற்று;
        type.t = 0;
	தேர்வு (c) {
	    நிலை 'e':
		தொடர்;
	    நிலை 'V':
                type.t = VT_CONSTANT;
	    நிலை 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                நிறுத்து;
	    நிலை 'S':
                type.t = VT_CONSTANT;
	    நிலை 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                நிறுத்து;
	    நிலை 'i':
                type.t = VT_INT;
                நிறுத்து;
	    நிலை 'l':
                type.t = VT_SIZE_T;
                நிறுத்து;
	    இயல்பு:
                நிறுத்து;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    எனில் (nc)
        nocode_wanted--;
}

நிலையான வெறுமை parse_atomic(முழு atok)
{
    முழு size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    எழுத்து buf[40];
    நிலையான மாறிலி எழுத்து *மாறிலி templates[] = {
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
    மாறிலி எழுத்து *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = வெற்று;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    க்கு (arg = 0;;) {
        கோவை_eq();
        தேர்வு (template[arg]) {
        நிலை 'a':
        நிலை 'A':
            atom_ptr = &vtop->type;
            எனில் ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            எனில் (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            நிறுத்து;

        நிலை 'p':
            எனில் ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            நிறுத்து;
        நிலை 'v':
            gen_assign_cast(atom);
            நிறுத்து;
        நிலை 'l':
            indir();
            gen_assign_cast(atom);
            நிறுத்து;
        நிலை 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            நிறுத்து;
        நிலை 'm':
            gen_assign_cast(&int_type);
            நிறுத்து;
        நிலை 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            நிறுத்து;
        }
        எனில் ('.' == template[++arg])
            நிறுத்து;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    தேர்வு (template[arg + 1]) {
    நிலை 'b':
        ct.t = VT_BOOL;
        நிறுத்து;
    நிலை 'v':
        ct = *atom;
        நிறுத்து;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    எனில் (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#இல்லையெனில்
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    எனில் (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC வெறுமை unary(வெறுமை)
{
    முழு n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    எனில் (debug_modes)
        tcc_debug_வரி(tcc_state), tcc_tcov_check_வரி (tcc_state, 1);

    type.ref = வெற்று;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    தேர்வு(tok) {
    நிலை TOK_EXTENSION:
        next();
        செல் tok_next;
    நிலை TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        செல் தள்ளு_tokc;
#endif
    நிலை TOK_CINT:
    நிலை TOK_CCHAR: 
	t = VT_INT;
 தள்ளு_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        நிறுத்து;
    நிலை TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        செல் தள்ளு_tokc;
    நிலை TOK_CLLONG:
        t = VT_LLONG;
	செல் தள்ளு_tokc;
    நிலை TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	செல் தள்ளு_tokc;
    நிலை TOK_CFLOAT:
        t = VT_FLOAT;
	செல் தள்ளு_tokc;
    நிலை TOK_CDOUBLE:
        t = VT_DOUBLE;
	செல் தள்ளு_tokc;
    நிலை TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#இல்லையெனில்
        t = VT_LDOUBLE;
#endif
	செல் தள்ளு_tokc;
    நிலை TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	செல் தள்ளு_tokc;
    நிலை TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	செல் தள்ளு_tokc;
    நிலை TOK___FUNCTION__:
        எனில் (!gnu_ext)
            செல் tok_identifier;
        /* fall thru */
    நிலை TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        செல் case_TOK_STR;
    நிலை TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#இல்லையெனில்
        t = VT_INT;
#endif
        செல் str_init;
    நிலை TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        எனில் (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, அளவு(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        நிறுத்து;
    நிலை TOK_SOTYPE:
    நிலை '(':
        t = tok;
        next();
        /* cast ? */
        எனில் (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            எனில் (tok == '{') {
                    /* data is allocated locally by default */
                எனில் (global_கோவை)
                    r = VT_CONST;
                இல்லையெனில்
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                எனில் (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, அளவு(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } இல்லையெனில் எனில் (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                திரும்பு;
            } இல்லையெனில் {
                unary();
                gen_cast(&type);
            }
        } இல்லையெனில் எனில் (tok == '{') {
	    முழு saved_nocode_wanted = nocode_wanted;
            எனில் (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            எனில் (0 == local_scope)
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
            block(STMT_கோவை);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            எனில் (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } இல்லையெனில் {
            gexpr();
            skip(')');
        }
        நிறுத்து;
    நிலை '*':
        next();
        unary();
        indir();
        நிறுத்து;
    நிலை '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        எனில் ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        எனில் (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        நிறுத்து;
    நிலை '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        நிறுத்து;
    நிலை '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        நிறுத்து;
    நிலை '+':
        next();
        unary();
        எனில் ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	எனில் (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        நிறுத்து;
    நிலை TOK_SIZEOF:
    நிலை TOK_ALIGNOF1:
    நிலை TOK_ALIGNOF2:
    நிலை TOK_ALIGNOF3:
        t = tok;
        next();
        எனில் (tok == '(')
            tok = TOK_SOTYPE;
        கோவை_type(&type, unary);
        எனில் (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } இல்லையெனில் {
            type_size(&type, &align);
            s = வெற்று;
            எனில் (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            எனில் (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        நிறுத்து;

    நிலை TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        நிறுத்து;
    நிலை TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        நிறுத்து;
    நிலை TOK_builtin_choose_கோவை:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = கோவை_const64();
	    skip(',');
	    எனில் (!c) {
		nocode_wanted++;
	    }
	    கோவை_eq();
	    எனில் (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    எனில் (c) {
		nocode_wanted++;
	    }
	    கோவை_eq();
	    எனில் (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        நிறுத்து;
    நிலை TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	எனில் ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        நிறுத்து;
    நிலை TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        நிறுத்து;
    நிலை TOK_builtin_frame_address:
    நிலை TOK_builtin_return_address:
        {
            முழு tok1 = tok;
            முழு level;
            next();
            skip('(');
            level = கோவை_const();
            எனில் (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            போது (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            எனில் (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#அல்லதெனில் defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#இல்லையெனில்
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        நிறுத்து;
#ifdef TCC_TARGET_RISCV64
    நிலை TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        எனில் (r == VT_LLOCAL)
            r = VT_LOCAL;
        எனில் (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        நிறுத்து;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    நிலை TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        எனில் (r == VT_LLOCAL)
            r = VT_LOCAL;
        எனில் (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        நிறுத்து;
#இல்லையெனில்
    நிலை TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	நிறுத்து;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    நிலை TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        நிறுத்து;
    }
    நிலை TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        நிறுத்து;
    }
#endif
#ifdef TCC_TARGET_ARM64
    நிலை TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        நிறுத்து;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    நிலை TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        நிறுத்து;
    }
#endif

    /* atomic operations */
    நிலை TOK___atomic_store:
    நிலை TOK___atomic_load:
    நிலை TOK___atomic_exchange:
    நிலை TOK___atomic_compare_exchange:
    நிலை TOK___atomic_fetch_add:
    நிலை TOK___atomic_fetch_sub:
    நிலை TOK___atomic_fetch_or:
    நிலை TOK___atomic_fetch_xor:
    நிலை TOK___atomic_fetch_and:
    நிலை TOK___atomic_fetch_nand:
    நிலை TOK___atomic_add_fetch:
    நிலை TOK___atomic_sub_fetch:
    நிலை TOK___atomic_or_fetch:
    நிலை TOK___atomic_xor_fetch:
    நிலை TOK___atomic_and_fetch:
    நிலை TOK___atomic_nand_fetch:
        parse_atomic(tok);
        நிறுத்து;

    /* pre operations */
    நிலை TOK_INC:
    நிலை TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        நிறுத்து;
    நிலை '-':
        next();
        unary();
	எனில் (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} இல்லையெனில் {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        நிறுத்து;
    நிலை TOK_LAND:
        எனில் (!gnu_ext)
            செல் tok_identifier;
        next();
        /* allow to take the address of a label */
        எனில் (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        எனில் (!s) {
            s = label_தள்ளு(&global_label_அடுக்கு, tok, LABEL_FORWARD);
        } இல்லையெனில் {
            எனில் (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        எனில் ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        நிறுத்து;

    நிலை TOK_GENERIC:
    {
	CType controlling_type;
	முழு has_default = 0;
	முழு has_match = 0;
	முழு learn = 0;
	TokenString *str = வெற்று;
	முழு saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	கோவை_type(&controlling_type, கோவை_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        க்கு (;;) {
	    learn = 0;
	    skip(',');
	    எனில் (tok == TOK_DEFAULT) {
		எனில் (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		எனில் (!has_match)
		    learn = 1;
		next();
	    } இல்லையெனில் {
		முழு v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		எனில் (compare_types(&controlling_type, &type, 0)) {
		    எனில் (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    எனில் (learn) {
		எனில் (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } இல்லையெனில் {
		skip_or_save_block(வெற்று);
	    }
	    எனில் (tok == ')')
		நிறுத்து;
	}
	எனில் (!str) {
	    எழுத்து buf[60];
	    type_to_str(buf, அளவு buf, &controlling_type, வெற்று);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	கோவை_eq();
	எனில் (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	நிறுத்து;
    }
    // special qnan , snan and infinity values
    நிலை TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        நிறுத்து;
    நிலை TOK___SNAN__:
	n = 0x7f800001;
	செல் special_math_val;
    நிலை TOK___INF__:
	n = 0x7f800000;
	செல் special_math_val;

    இயல்பு:
    tok_identifier:
        எனில் (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        எனில் (!s || IS_ASM_SYM(s)) {
            மாறிலி எழுத்து *name = get_tok_str(t, வெற்று);
            எனில் (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            எனில் (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        எனில் ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        எனில் (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            எனில் (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } இல்லையெனில் எனில் (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        நிறுத்து;
    }
    
    /* post operations */
    போது (1) {
        எனில் (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } இல்லையெனில் எனில் (tok == '.' || tok == TOK_ARROW) {
            முழு qualifiers, cumofs;
            /* field */ 
            எனில் (tok == TOK_ARROW) 
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
            எனில் (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            எனில் (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                எனில் (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } இல்லையெனில் எனில் (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } இல்லையெனில் எனில் (tok == '(') {
            SValue ret;
            Sym *sa;
            முழு nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            எனில் ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                எனில் ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    எனில் ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        செல் error_func;
                } இல்லையெனில் {
                error_func:
                    expect("function pointer");
                }
            } இல்லையெனில் {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            எனில் ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                எனில் (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                எனில் (size < 16)
                    போது (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    எனில் (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    எனில் (ret_nregs < 0)
                      vtop--;
                    இல்லையெனில்
                      nb_args++;
                }
            } இல்லையெனில் {
                ret_nregs = 1;
                ret.type = s->type;
            }

            எனில் (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = வெற்று;
            எனில் (tok != ')') {
                r = tcc_state->reverse_funcargs;
                க்கு(;;) {
                    எனில் (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } இல்லையெனில் {
                        கோவை_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    எனில் (sa)
                        sa = sa->next;
                    எனில் (tok == ')')
                        நிறுத்து;
                    skip(',');
                }
            }
            எனில் (sa)
                tcc_error("too few arguments to function");

            எனில் (p) { /* with reverse_funcargs */
                க்கு (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    செய் {
                        sa = sa->next, p2 = p2->prev;
                    } போது (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    கோவை_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            எனில் (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } இல்லையெனில் {
                /* return value */
                n = ret_nregs;
                போது (n > 1) {
                    முழு rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    க்கு (r = 0; r < NB_REGS; ++r)
                        எனில் (reg_classes[r] & rc)
                            நிறுத்து;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                எனில் (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    முழு addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    எனில் (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    க்கு (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        எனில் (--ret_nregs == 0)
                          நிறுத்து;
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
                எனில் (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#இல்லையெனில்
                    vtop->type.t = VT_INT;
#endif
                }
            }
            எனில் (s->f.func_noreturn) {
                எனில் (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } இல்லையெனில் {
            நிறுத்து;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

நிலையான வெறுமை கோவை_prod(வெறுமை)
{
    முழு t;

    unary();
    போது ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

நிலையான வெறுமை கோவை_sum(வெறுமை)
{
    முழு t;

    கோவை_prod();
    போது ((t = tok) == '+' || t == '-') {
        next();
        கோவை_prod();
        gen_op(t);
    }
}

நிலையான வெறுமை கோவை_shift(வெறுமை)
{
    முழு t;

    கோவை_sum();
    போது ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        கோவை_sum();
        gen_op(t);
    }
}

நிலையான வெறுமை கோவை_cmp(வெறுமை)
{
    முழு t;

    கோவை_shift();
    போது (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        கோவை_shift();
        gen_op(t);
    }
}

நிலையான வெறுமை கோவை_cmpeq(வெறுமை)
{
    முழு t;

    கோவை_cmp();
    போது ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        கோவை_cmp();
        gen_op(t);
    }
}

நிலையான வெறுமை கோவை_and(வெறுமை)
{
    கோவை_cmpeq();
    போது (tok == '&') {
        next();
        கோவை_cmpeq();
        gen_op('&');
    }
}

நிலையான வெறுமை கோவை_xor(வெறுமை)
{
    கோவை_and();
    போது (tok == '^') {
        next();
        கோவை_and();
        gen_op('^');
    }
}

நிலையான வெறுமை கோவை_or(வெறுமை)
{
    கோவை_xor();
    போது (tok == '|') {
        next();
        கோவை_xor();
        gen_op('|');
    }
}

நிலையான வெறுமை கோவை_landor(முழு op);

நிலையான வெறுமை கோவை_land(வெறுமை)
{
    கோவை_or();
    எனில் (tok == TOK_LAND)
        கோவை_landor(tok);
}

நிலையான வெறுமை கோவை_lor(வெறுமை)
{
    கோவை_land();
    எனில் (tok == TOK_LOR)
        கோவை_landor(tok);
}

# define கோவை_landor_next(op) op == TOK_LAND ? கோவை_or() : கோவை_land()
#இல்லையெனில் /* defined precedence_parser */
# define கோவை_landor_next(op) unary(), கோவை_infix(precedence(op) + 1)
# define கோவை_lor() unary(), கோவை_infix(1)

நிலையான முழு precedence(முழு tok)
{
    தேர்வு (tok) {
        நிலை TOK_LOR: திரும்பு 1;
        நிலை TOK_LAND: திரும்பு 2;
	நிலை '|': திரும்பு 3;
	நிலை '^': திரும்பு 4;
	நிலை '&': திரும்பு 5;
	நிலை TOK_EQ: நிலை TOK_NE: திரும்பு 6;
 relat: நிலை TOK_ULT: நிலை TOK_UGE: திரும்பு 7;
	நிலை TOK_SHL: நிலை TOK_SAR: திரும்பு 8;
	நிலை '+': நிலை '-': திரும்பு 9;
	நிலை '*': நிலை '/': நிலை '%': திரும்பு 10;
	இயல்பு:
	    எனில் (tok >= TOK_ULE && tok <= TOK_GT)
	        செல் relat;
	    திரும்பு 0;
    }
}
நிலையான unsigned எழுத்து prec[256];
நிலையான வெறுமை init_prec(வெறுமை)
{
    முழு i;
    க்கு (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

நிலையான வெறுமை கோவை_landor(முழு op);

நிலையான வெறுமை கோவை_infix(முழு p)
{
    முழு t = tok, p2;
    போது ((p2 = precedence(t)) >= p) {
        எனில் (t == TOK_LOR || t == TOK_LAND) {
            கோவை_landor(t);
        } இல்லையெனில் {
            next();
            unary();
            எனில் (precedence(tok) > p2)
              கோவை_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
நிலையான முழு condition_3way(வெறுமை)
{
    முழு c = -1;
    எனில் ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    திரும்பு c;
}

நிலையான வெறுமை கோவை_landor(முழு op)
{
    முழு t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    க்கு(;;) {
        c = f ? i : condition_3way();
        எனில் (c < 0)
            save_regs(1), cc = 0;
        இல்லையெனில் எனில் (c != i)
            nocode_wanted++, f = 1;
        எனில் (tok != op)
            நிறுத்து;
        எனில் (c < 0)
            t = gvtst(i, t);
        இல்லையெனில்
            vpop();
        next();
        கோவை_landor_next(op);
    }
    எனில் (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } இல்லையெனில் {
        gvtst_set(i, t);
    }
}

நிலையான முழு is_cond_bool(SValue *sv)
{
    எனில் ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        திரும்பு (unsigned)sv->c.i < 2;
    எனில் (sv->r == VT_CMP)
        திரும்பு 1;
    திரும்பு 0;
}

நிலையான வெறுமை கோவை_cond(வெறுமை)
{
    முழு tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    கோவை_lor();
    எனில் (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        எனில் (!g) {
            எனில் (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } இல்லையெனில் {
                vpop();
            }
        } இல்லையெனில் எனில் (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        எனில் (c == 0)
          nocode_wanted++;
        எனில் (!g)
          gexpr();

        எனில் ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        எனில் (g) {
            u = tt;
        } இல்லையெனில் எனில் (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } இல்லையெனில்
          u = 0;

        எனில் (c == 0)
          nocode_wanted--;
        எனில் (c == 1)
          nocode_wanted++;
        skip(':');
        கோவை_cond();

        எனில் ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        எனில் (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        எனில் (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            திரும்பு;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        எனில் (c != 1) {
            gen_cast(&type);
            எனில் (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        எனில் (USING_TWO_சொற்கள்(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        எனில் (c < 0) {
            எனில் (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        எனில் (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        எனில் (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            எனில் (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        எனில் (c < 0) {
            எனில் (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        எனில் (islv)
          indir();
    }
}

நிலையான வெறுமை கோவை_eq(வெறுமை)
{
    முழு t;
    
    கோவை_cond();
    எனில் ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        எனில் (t == '=') {
            கோவை_eq();
        } இல்லையெனில் {
            vdup();
            கோவை_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC வெறுமை gexpr(வெறுமை)
{
    கோவை_eq();
    எனில் (tok == ',') {
        செய் {
            vpop();
            next();
            கோவை_eq();
        } போது (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        எனில் ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            எனில் (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
நிலையான வெறுமை கோவை_const1(வெறுமை)
{
    nocode_wanted += CONST_WANTED_BIT;
    கோவை_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
நிலையான உள்வரி int64_t கோவை_const64(வெறுமை)
{
    int64_t c;
    கோவை_const1();
    எனில் ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    திரும்பு c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC முழு கோவை_const(வெறுமை)
{
    முழு c;
    int64_t wc = கோவை_const64();
    c = wc;
    எனில் (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    திரும்பு c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
நிலையான வெறுமை gfunc_return(CType *func_type)
{
    எனில் ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        முழு ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        எனில் (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } இல்லையெனில் எனில் (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } இல்லையெனில் {
            /* returning structure packed into registers */
            முழு size, addr, align, rc, n;
            size = type_size(func_type,&align);
            எனில் (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		எனில் (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		எனில் (ret_align > align)
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
            க்கு (n = ret_nregs; --n > 0;) {
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
    } இல்லையெனில் {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

நிலையான வெறுமை check_func_return(வெறுமை)
{
    எனில் ((func_vt.t & VT_BTYPE) == VT_VOID)
        திரும்பு;
    எனில் ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } இல்லையெனில் {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

நிலையான முழு case_cmp(uint64_t a, uint64_t b)
{
    எனில் (cur_switch->sv.type.t & VT_UNSIGNED)
        திரும்பு a < b ? -1 : a > b;
    இல்லையெனில்
        திரும்பு (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

நிலையான முழு case_cmp_qs(மாறிலி வெறுமை *pa, மாறிலி வெறுமை *pb)
{
    திரும்பு case_cmp((*(கட்டமைப்பு case_t**)pa)->v1, (*(கட்டமைப்பு case_t**)pb)->v1);
}

நிலையான வெறுமை case_sort(கட்டமைப்பு switch_t *sw)
{
    கட்டமைப்பு case_t **p;
    எனில் (sw->n < 2)
        திரும்பு;
    qsort(sw->p, sw->n, அளவு *sw->p, case_cmp_qs);
    p = sw->p;
    போது (p < sw->p + sw->n - 1) {
        எனில் (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            முழு l1 = p[0]->வரி, l2 = p[1]->வரி;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } இல்லையெனில் எனில் (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * அளவு *p);
        } இல்லையெனில்
            ++p;
    }
}

நிலையான முழு gcase(கட்டமைப்பு case_t **base, முழு len, முழு dsym)
{
    கட்டமைப்பு case_t *p;
    முழு t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    எனில் (t != VT_LLONG)
        t = VT_INT;
    போது (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        எனில் (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } இல்லையெனில் {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            எனில் (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            இல்லையெனில்
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
    திரும்பு gjmp(dsym);
}

நிலையான வெறுமை end_switch(வெறுமை)
{
    கட்டமைப்பு switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
நிலையான வெறுமை save_lvalues(வெறுமை)
{
    SValue *sv = vtop;
    போது (sv >= vstack) {
        எனில் (sv->sym && (sv->r & VT_LVAL)) {
            முழு align, size = type_size(&sv->type, &align);
            முழு r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

நிலையான வெறுமை try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    க்கு (; cls != stop; cls = cls->next) {
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


நிலையான வெறுமை try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    முழு ocd, ccd;

    எனில் (!cur_scope->cl.s)
	திரும்பு;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    க்கு (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    க்கு (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    க்கு (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
நிலையான வெறுமை block_cleanup(கட்டமைப்பு scope *o)
{
    முழு jmp = 0;
    Sym *g, **pg;
    க்கு (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        எனில் (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            எனில் (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            எனில் (!o->cl.n)
                செல் remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } இல்லையெனில் {
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

நிலையான வெறுமை vla_restore(முழு loc)
{
    எனில் (loc)
        gen_vla_sp_restore(loc);
}

நிலையான வெறுமை vla_leave(கட்டமைப்பு scope *o)
{
    கட்டமைப்பு scope *c = cur_scope, *v = வெற்று;
    க்கு (; c != o && c; c = c->prev)
      எனில் (c->vla.இலக்கம்)
        v = c;
    எனில் (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

நிலையான வெறுமை new_scope(கட்டமைப்பு scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.இலக்கம் = 0;

    /* record local declaration stack position */
    o->lstk = local_அடுக்கு;
    o->llstk = local_label_அடுக்கு;
    ++local_scope;
}

நிலையான வெறுமை prev_scope(கட்டமைப்பு scope *o, முழு is_கோவை)
{
    vla_leave(o->prev);

    எனில் (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    எனில் (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_கோவை);

    /* pop locally defined labels */
    label_எடு(&local_label_அடுக்கு, o->llstk, is_கோவை);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_எடு(&local_அடுக்கு, o->lstk, is_கோவை);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
நிலையான வெறுமை leave_scope(கட்டமைப்பு scope *o)
{
    எனில் (!o)
        திரும்பு;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
நிலையான வெறுமை new_scope_s(கட்டமைப்பு scope *o)
{
    o->lstk = local_அடுக்கு;
    ++local_scope;
}

நிலையான வெறுமை prev_scope_s(கட்டமைப்பு scope *o)
{
    sym_எடு(&local_அடுக்கு, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

நிலையான வெறுமை lblock(முழு *bsym, முழு *csym)
{
    கட்டமைப்பு scope *lo = loop_scope, *co = cur_scope;
    முழு *b = co->bsym, *c = co->csym;
    எனில் (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    எனில் (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
நிலையான வெறுமை gexpr_decl(வெறுமை)
{
    முழு v = decl(VT_JMP);
    எனில் (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } இல்லையெனில் {
        எனில் (v)
            skip(';');
        gexpr();
    }
}

நிலையான வெறுமை block(முழு flags)
{
    முழு a, b, c, d, e, t;
    கட்டமைப்பு scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    எனில் (TOK_HAS_மதிப்பு(t))
        செல் கோவை;
    next();

    எனில் (debug_modes)
        tcc_tcov_check_வரி (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    எனில் (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        எனில் (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } இல்லையெனில் {
            gsym(a);
        }
        prev_scope_s(&o);

    } இல்லையெனில் எனில் (t == TOK_WHILE) {
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

    } இல்லையெனில் எனில் (t == '{') {
        எனில் (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        போது (tok == TOK_LABEL) {
            செய் {
                next();
                எனில் (tok < TOK_UIDENT)
                    expect("label identifier");
                label_தள்ளு(&local_label_அடுக்கு, tok, LABEL_DECLARED);
                next();
            } போது (tok == ',');
            skip(';');
        }

        போது (tok != '}') {
	    decl(VT_LOCAL);
            எனில் (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_கோவை);
        எனில் (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        எனில் (local_scope)
            next();
        இல்லையெனில் எனில் (!nocode_wanted)
            check_func_return();

    } இல்லையெனில் எனில் (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        எனில் (tok != ';') {
            gexpr();
            எனில் (b) {
                gen_assign_cast(&func_vt);
            } இல்லையெனில் {
                எனில் (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } இல்லையெனில் எனில் (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } இல்லையெனில் எனில் (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(வேர்_scope);
        எனில் (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        எனில் (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        எனில் (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } இல்லையெனில் எனில் (t == TOK_BREAK) {
        /* compute jump */
        எனில் (!cur_scope->bsym)
            tcc_error("cannot break");
        எனில் (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        இல்லையெனில்
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } இல்லையெனில் எனில் (t == TOK_CONTINUE) {
        /* compute jump */
        எனில் (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } இல்லையெனில் எனில் (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        எனில் (tok != ';') {
            /* c99 for-loop init decl? */
            எனில் (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        எனில் (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        எனில் (tok != ')') {
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

    } இல்லையெனில் எனில் (t == TOK_DO) {
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

    } இல்லையெனில் எனில் (t == TOK_SWITCH) {
        கட்டமைப்பு switch_t *sw;

        sw = tcc_mallocz(அளவு *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        எனில் (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, வெற்று);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        எனில் (sw->nocode_wanted)
            செல் skip_switch;
        case_sort(sw);
        sw->bsym = வெற்று; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        எனில் (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        இல்லையெனில்
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } இல்லையெனில் எனில் (t == TOK_CASE) {
        கட்டமைப்பு case_t *cr;
        எனில் (!cur_switch)
            expect("switch");
        cr = tcc_malloc(அளவு(கட்டமைப்பு case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(கோவை_const64(), t);
        எனில் (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(கோவை_const64(), t);
            எனில் (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        எனில் (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->வரி = file->வரி_இலக்கம்;
        skip(':');
        செல் block_after_label;

    } இல்லையெனில் எனில் (t == TOK_DEFAULT) {
        எனில் (!cur_switch)
            expect("switch");
        எனில் (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        செல் block_after_label;

    } இல்லையெனில் எனில் (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        எனில் (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            எனில் ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } இல்லையெனில் எனில் (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            எனில் (!s)
              s = label_தள்ளு(&global_label_அடுக்கு, tok, LABEL_FORWARD);
            இல்லையெனில் எனில் (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    எனில் (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		எனில் (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } இல்லையெனில் {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } இல்லையெனில் {
            expect("label identifier");
        }
        skip(';');

    } இல்லையெனில் எனில் (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } இல்லையெனில் {
        எனில் (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            எனில் (s) {
                எனில் (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, வெற்று));
                s->r = LABEL_DEFINED;
		எனில் (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    க்கு (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_எடு(&s->next, வெற்று, 0);
		} இல்லையெனில்
		  gsym(s->jnext);
            } இல்லையெனில் {
                s = label_தள்ளு(&global_label_அடுக்கு, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(வெற்று);

            எனில் (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            எனில் (tok != '}') {
                எனில் (0 == (flags & STMT_COMPOUND))
                    செல் again;
                /* C23: insert implicit null-statement whithin compound statement */
            } இல்லையெனில் {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } இல்லையெனில் {
            /* expression case */
            எனில் (t != ';') {
                unget_tok(t);
    கோவை:
                எனில் (flags & STMT_கோவை) {
                    vpop();
                    gexpr();
                } இல்லையெனில் {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    எனில் (debug_modes)
        tcc_tcov_check_வரி (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
நிலையான வெறுமை skip_or_save_block(TokenString **str)
{
    முழு braces = tok == '{';
    முழு level = 0;
    எனில் (str)
      *str = tok_str_alloc();

    போது (1) {
	முழு t = tok;
        எனில் (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             நிறுத்து;
	எனில் (t == TOK_EOF) {
	     எனில் (str || level > 0)
	       tcc_error("unexpected end of file");
	     இல்லையெனில்
	       நிறுத்து;
	}
	எனில் (str)
	  tok_str_add_tok(*str);
	next();
	எனில் (t == '{' || t == '(' || t == '[') {
	    level++;
	} இல்லையெனில் எனில் (t == '}' || t == ')' || t == ']') {
	    level--;
	    எனில் (level == 0 && braces && t == '}')
	      நிறுத்து;
	}
    }
    எனில் (str)
	tok_str_add(*str, TOK_EOF);
}

#define கோவை_CONST 1
#define கோவை_ANY   2

நிலையான வெறுமை parse_init_elem(முழு கோவை_type)
{
    முழு saved_global_கோவை;
    தேர்வு(கோவை_type) {
    நிலை கோவை_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_கோவை = global_கோவை;
        global_கோவை = 1;
        கோவை_const1();
        global_கோவை = saved_global_கோவை;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        எனில் (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        நிறுத்து;
    நிலை கோவை_ANY:
        கோவை_eq();
        நிறுத்து;
    }
}

#எனில் 1
நிலையான வெறுமை init_assert(init_params *p, முழு offset)
{
    எனில் (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#இல்லையெனில்
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
நிலையான வெறுமை init_putz(init_params *p, unsigned long c, முழு size)
{
    init_assert(p, c + size);
    எனில் (p->sec) {
        /* nothing to do because globals are already set to zero */
    } இல்லையெனில் {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#எனில் defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
நிலையான வெறுமை decl_design_delrels(Section *sec, முழு c, முழு size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    எனில் (!sec || !sec->reloc)
        திரும்பு;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    போது (rel < rel_end) {
        எனில் (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= அளவு *rel;
        } இல்லையெனில் {
            எனில் (rel2 != rel)
                memcpy(rel2, rel, அளவு *rel);
            ++rel2;
        }
        ++rel;
    }
}

நிலையான வெறுமை decl_design_flex(init_params *p, Sym *ref, முழு index)
{
    எனில் (ref == p->flex_array_ref) {
        எனில் (index >= ref->c)
            ref->c = index + 1;
    } இல்லையெனில் எனில் (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
நிலையான முழு decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, முழு flags, முழு al)
{
    Sym *s, *f;
    முழு index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    எனில் (flags & DIF_HAVE_ELEM)
        செல் no_designator;

    எனில் (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        எனில் (tok == ':')
            செல் struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    போது (nb_elems == 1 && (tok == '[' || tok == '.')) {
        எனில் (tok == '[') {
            எனில் (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = கோவை_const();
            எனில் (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = கோவை_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            எனில் (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            எனில் (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } இல்லையெனில் {
            முழு cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            எனில் (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = வெற்று;
    }
    எனில் (!cur_field) {
        எனில் (tok == '=') {
            next();
        } இல்லையெனில் எனில் (!gnu_ext) {
	    expect("=");
        }
    } இல்லையெனில் {
    no_designator:
        எனில் (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            எனில் (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } இல்லையெனில் {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    போது (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            எனில் (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    எனில் (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    எனில் (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    எனில் (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        முழு i;
        எனில் (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        எனில் (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        இல்லையெனில்
	    vset(type, VT_LOCAL|VT_LVAL, c);
        க்கு (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    எனில் (c - corig > al)
      al = c - corig;
    திரும்பு al;
}

நிலையான வெறுமை write_ldouble(unsigned எழுத்து *d, வெறுமை *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    எனில் (LDOUBLE_SIZE >= 10) {
        இரட்டை b = *(long இரட்டை*)s;
        s = &b;
#இல்லையெனில்
    எனில் (அளவு (long இரட்டை) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        முழு e = m >> 48;
        முழு f = e >> 4 & 0x7FF;
        m <<= 11;
        எனில் (0 == f) {
            எனில் (0 == m)
                செல் set;
            க்கு (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        எனில் (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #எனில் (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #அல்லதெனில் LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } இல்லையெனில் {
    #எனில் LDOUBLE_SIZE == 8
        /* long double -> double */
        இரட்டை b = *(long இரட்டை*)s;
        memcpy(d, &b, 8);
    #அல்லதெனில் (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #அல்லதெனில் (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        முழு e = *(uint16_t*)((எழுத்து*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #அல்லதெனில் (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((எழுத்து*)s + 6);
        முழு e = read16le((எழுத்து*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #இல்லையெனில்
        /* unknown */
        எனில் (அளவு (long இரட்டை) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
நிலையான வெறுமை init_putv(init_params *p, CType *type, unsigned long c)
{
    முழு bt;
    வெறுமை *ptr;
    CType dtype;
    முழு size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    எனில் (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    எனில் (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        எனில் ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        எனில் (NODATA_WANTED) {
            vtop--;
            திரும்பு;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	எனில் ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_மதிப்பு + (முழு)vtop->c.i, size);
	    எனில் (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		போது (relofs >= அளவு(*rel)) {
                    relofs -= அளவு(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    எனில் (rel->r_offset >= esym->st_மதிப்பு + size)
		      தொடர்;
		    எனில் (rel->r_offset < esym->st_மதிப்பு)
		      நிறுத்து;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_மதிப்பு,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#எனில் PTR_SIZE == 8
				   rel->r_addend
#இல்லையெனில்
				   0
#endif
				  );
		}
	    }
	} இல்லையெனில் {
            எனில் (type->t & VT_BITFIELD) {
                முழு bit_pos, bit_size, bits, n;
                unsigned எழுத்து *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned எழுத்து*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                போது (bit_size) {
                    n = 8 - bit_pos;
                    எனில் (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } இல்லையெனில்
            தேர்வு(bt) {
	    நிலை VT_BOOL:
		*(எழுத்து *)ptr = val != 0;
                நிறுத்து;
	    நிலை VT_BYTE:
		*(எழுத்து *)ptr = val;
		நிறுத்து;
	    நிலை VT_SHORT:
                write16le(ptr, val);
		நிறுத்து;
	    நிலை VT_FLOAT:
                write32le(ptr, val);
		நிறுத்து;
	    நிலை VT_DOUBLE:
                write64le(ptr, val);
		நிறுத்து;
	    நிலை VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		நிறுத்து;

#எனில் PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    நிலை VT_LLONG:
	    நிலை VT_PTR:
	        எனில் (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        இல்லையெனில்
	          write64le(ptr, val);
	        நிறுத்து;
            நிலை VT_INT:
                write32le(ptr, val);
                நிறுத்து;
#இல்லையெனில்
	    நிலை VT_LLONG:
                write64le(ptr, val);
                நிறுத்து;
            நிலை VT_PTR:
            நிலை VT_INT:
	        எனில் (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        நிறுத்து;
#endif
	    இயல்பு:
                //tcc_internal_error("unexpected type");
                நிறுத்து;
	    }
	}
        vtop--;
    } இல்லையெனில் {
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
நிலையான வெறுமை decl_initializer(init_params *p, CType *type, unsigned long c, முழு flags)
{
    முழு len, n, no_oblock, i;
    முழு size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    எனில் (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_வரி(tcc_state), tcc_tcov_check_வரி (tcc_state, 1);

    எனில் (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        முழு ncw_prev = nocode_wanted;
        எனில் ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? கோவை_ANY : கோவை_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    எனில் (type->t & VT_ARRAY) {
        no_oblock = 1;
        எனில் (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        எனில் ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#இல்லையெனில்
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            எனில் (size1 != (tok == TOK_STR ? 1 : அளவு(nwchar_t)))
              tcc_error("unhandled string literal merging");
            போது (tok == TOK_STR || tok == TOK_LSTR) {
                எனில் (initstr.size)
                  initstr.size -= size1;
                எனில் (tok == TOK_STR)
                  len += tokc.str.size;
                இல்லையெனில்
                  len += tokc.str.size / அளவு(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            எனில் (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                செல் do_init_array;
            }

            decl_design_flex(p, s, len);
            எனில் (!(flags & DIF_SIZE_ONLY)) {
                முழு nb = n, ch;
                எனில் (len < nb)
                    nb = len;
                எனில் (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                எனில் (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    எனில் (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } இல்லையெனில் {
                    க்கு(i=0;i<n;i++) {
                        எனில் (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          எனில் (flags & DIF_CLEAR)
                            நிறுத்து;
                          எனில் (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            நிறுத்து;
                          }
                          ch = 0;
                        } இல்லையெனில் எனில் (size1 == 1)
                          ch = ((unsigned எழுத்து *)initstr.data)[i];
                        இல்லையெனில்
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            எனில் (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } இல்லையெனில் {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            எனில் (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    போது (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		எனில் (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    எனில் (no_oblock && len >= n*size1)
		        நிறுத்து;
		} இல்லையெனில் {
		    எனில் (s->type.t == VT_UNION)
		        f = வெற்று;
		    இல்லையெனில்
		        f = f->next;
		    எனில் (no_oblock && f == வெற்று)
		        நிறுத்து;
		}

		எனில் (tok == '}')
		    நிறுத்து;
		skip(',');
	    }
        }
        எனில் (!no_oblock)
            skip('}');

    } இல்லையெனில் எனில் ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        செல் one_elem;

    } இல்லையெனில் எனில் ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        எனில் ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	செல் do_init_list;

    } இல்லையெனில் எனில் (tok == '{') {
        எனில் (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } இல்லையெனில் one_elem: எனில் ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        எனில் (flags & DIF_HAVE_ELEM)
            vpop();
        இல்லையெனில்
            skip_or_save_block(வெற்று);

    } இல்லையெனில் {
	எனில் (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    எனில் (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? கோவை_ANY : கோவை_CONST);
	}
        எனில் (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        இல்லையெனில்
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
நிலையான வெறுமை decl_initializer_alloc(CType *type, AttributeDef *ad, முழு r, 
                                   முழு has_init, முழு v, முழு scope)
{
    முழு size, align, addr;
    TokenString *init_str = வெற்று;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = வெற்று;
    முழு saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    முழு bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    எனில் (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        எனில் (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            எனில் (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                திரும்பு;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    எனில் (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = வெற்று;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    எனில் (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        எனில் (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        எனில் (IS_BT_ARRAY(type->t))
            type->ref = sym_தள்ளு(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } இல்லையெனில் எனில் (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        எனில் (field) {
            போது (field->next)
                field = field->next;
            எனில் (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    எனில் (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        எனில் (!has_init)
            செல் err_size;
        எனில் (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            போது (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } இல்லையெனில்
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
        எனில் (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        எனில் (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    எனில் (ad->a.aligned) {
	முழு speca = 1 << (ad->a.aligned - 1);
        எனில் (speca > align)
            align = speca;
    } இல்லையெனில் எனில் (ad->a.packed) {
        align = 1;
    }

    எனில் (!v && NODATA_WANTED)
        size = 0, align = 1;

    எனில் ((r & VT_VALMASK) == VT_LOCAL) {
        sec = வெற்று;
#ifdef CONFIG_TCC_BCHECK
        எனில் (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        எனில் (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        எனில் (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    எனில் (ad->asm_label) {
		முழு reg = asm_parse_regvar(ad->asm_label);
		எனில் (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_தள்ளு(v, type, r, addr);
	    எனில் (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } இல்லையெனில் {
            /* push local reference */
            vset(type, r, addr);
        }
    } இல்லையெனில் {
        CType *tp = type;
        முழு is_const;

        போது ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        எனில் (!sec) {
            எனில் (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } இல்லையெனில் எனில் (is_const) {
		sec = rodata_section;
            } இல்லையெனில் எனில் (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } இல்லையெனில் எனில் (tcc_state->nocommon)
                sec = bss_section;
        } இல்லையெனில் எனில் (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            எனில் (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                எனில் (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        எனில் (bcheck)
            size = size + 1; /* add padding */
#endif
        எனில் (sec) {
	    addr = section_add(sec, size, align);
        } இல்லையெனில் {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        எனில் (v) {
            எனில் (!sym) {
                sym = sym_தள்ளு(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, வெற்று);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } இல்லையெனில் {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        எனில் (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * அளவு(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    எனில் (type->t & VT_VLA) {
        முழு a;

        எனில் (has_init)
            tcc_error("variable length array cannot be initialized");

        எனில் (NODATA_WANTED)
            செல் no_alloc;

        /* save before-VLA stack pointer if needed */
        எனில் (cur_scope->vla.இலக்கம் == 0) {
            எனில் (cur_scope->prev && cur_scope->prev->vla.இலக்கம்) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } இல்லையெனில் {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#எனில் defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.இலக்கம்++;
    } இல்லையெனில் எனில் (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        எனில் (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    எனில் (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
நிலையான வெறுமை func_vla_arg_code(Sym *arg)
{
    முழு align;
    TokenString *vla_array_tok = வெற்று;

    எனில் (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    எனில் ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

நிலையான வெறுமை func_vla_arg(Sym *sym)
{
    Sym *arg;

    க்கு (arg = sym->type.ref->next; arg; arg = arg->next)
        எனில் ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, முழு c, முழு byref)
{
    s = sym_find(s->v);
    எனில் (!s) /* unnamed parameters, not enabled */
        திரும்பு வெற்று;
    s->c = c;
    எனில் (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    திரும்பு s;
}

/* push parameters (and their types), last first */
நிலையான வெறுமை sym_தள்ளு_params(Sym *ref)
{
    Sym *s = ref;
    போது (s->next)
        s = s->next;
    போது (s != ref) {
        எனில் ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_அடுக்கு);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
நிலையான வெறுமை gen_function(Sym *sym)
{
    கட்டமைப்பு scope f = { 0 };

    cur_scope = வேர்_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    எனில் (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, வெற்று);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    எனில் (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    எனில் (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_அடுக்கு, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_தள்ளு_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(வெற்று, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_எடு(&local_அடுக்கு, வெற்று, 0);
    label_எடு(&global_label_அடுக்கு, வெற்று, 0);
    sym_எடு(&all_cleanups, வெற்று, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = வெற்று;
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

நிலையான வெறுமை gen_inline_functions(TCCState *s)
{
    Sym *sym;
    முழு inline_generated, i;
    கட்டமைப்பு InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    செய் {
        inline_generated = 0;
        க்கு (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            எனில் (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = வெற்று;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } போது (inline_generated);
    tcc_close();
}

நிலையான வெறுமை free_inline_functions(TCCState *s)
{
    முழு i;
    /* free tokens of unused inline functions */
    க்கு (i = 0; i < s->nb_inline_fns; ++i) {
        கட்டமைப்பு InlineFunc *fn = s->inline_fns[i];
        எனில் (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

நிலையான வெறுமை do_Static_assert(வெறுமை)
{
    முழு c;
    மாறிலி எழுத்து *செய்தி;

    next();
    skip('(');
    c = கோவை_const();
    செய்தி = "_Static_assert fail";
    எனில் (tok == ',') {
        next();
        செய்தி = parse_mult_str("string constant")->data;
    }
    skip(')');
    எனில் (c == 0)
        tcc_error("%s", செய்தி);
    skip(';');
}

#ifdef TCC_TARGET_PE
நிலையான வெறுமை pe_check_linkage(CType *type, AttributeDef *ad)
{
    எனில் (!ad->a.dllimport && !ad->a.dllexport)
        திரும்பு;
    எனில் (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    எனில் (type->t & VT_TYPEDEF) {
        மாறிலி எழுத்து *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } இல்லையெனில் எனில் (ad->a.dllimport) {
        எனில் ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        இல்லையெனில்
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
நிலையான முழு decl(முழு l)
{
    முழு v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    போது (1) {

        oldint = 0;
        எனில் (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            எனில் (l == VT_JMP)
                திரும்பு 0;
            /* skip redundant ';' if not in old parameter decl scope */
            எனில் (tok == ';' && l != VT_CMP) {
                next();
                தொடர்;
            }
            எனில் (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                தொடர்;
            }
            எனில் (l != VT_CONST)
                நிறுத்து;
            எனில் (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                தொடர்;
            }
            எனில் (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } இல்லையெனில் {
                எனில் (tok != TOK_EOF)
                    expect("declaration");
                நிறுத்து;
            }
        }

        எனில் (tok == ';') {
            எனில் ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            இல்லையெனில் எனில் (IS_ENUM(btype.t))
                ; /* enum decl */
            இல்லையெனில்
                tcc_warning("useless type defines no instances");
            எனில் (l == VT_JMP)
                திரும்பு 1;
            next();
            தொடர்;
        }

        போது (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            எனில் ((type.t & VT_BTYPE) == VT_FUNC) {
                எனில் ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                எனில் (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                எனில் ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    எனில் (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    இல்லையெனில்
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } இல்லையெனில் எனில் (oldint) {
                tcc_warning("type defaults to int");
            }

            எனில் (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #எனில் 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                எனில் (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            எனில் (tok == '{') {
                எனில் (l != VT_CONST)
                    tcc_error("cannot use local functions");
                எனில் ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                க்கு (sa = sym->type.ref; (sa = sa->next) != வெற்று;) {
                    எனில் (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    எனில் (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                எனில் (sym->type.t & VT_INLINE) {
                    கட்டமைப்பு InlineFunc *fn;
                    fn = tcc_malloc(அளவு *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } இல்லையெனில் {
                    /* compute text section */
                    cur_text_section = text_section;
                    எனில் (ad.section) {
                        cur_text_section = ad.section;
                        எனில் (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                நிறுத்து;
            } இல்லையெனில் {
                has_init = 0;
		எனில் (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    க்கு (sym = func_vt.ref->next; sym; sym = sym->next)
			எனில் ((sym->v & ~SYM_FIELD) == v)
			    செல் found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, வெற்று));
                found:
		    எனில் (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, வெற்று));
		    எனில் (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, வெற்று));
		    convert_parameter_type(&type);
		    sym->type = type;
		} இல்லையெனில் எனில் (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    எனில் (sym && sym->sym_scope == local_scope) {
                        எனில் (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, வெற்று));
                        sym->type = type;
                    } இல்லையெனில் {
                        sym = sym_தள்ளு(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    எனில் ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    எனில் (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} இல்லையெனில் எனில் ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } இல்லையெனில் {
                    r = 0;
                    எனில் ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } இல்லையெனில் எனில் (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    எனில் (tok == '=')
                        has_init = 1;

                    எனில் (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } இல்லையெனில் {
                        எனில் (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        இல்லையெனில்
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        எனில் (has_init)
                            next();
                        இல்லையெனில் எனில் (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    எனில் (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        எனில் (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_மதிப்பு, esym->st_size, 1);
                    }
                }
                எனில் (tok != ',') {
                    எனில் (l == VT_JMP)
                        திரும்பு has_init ? v : 1;
                    skip(';');
                    நிறுத்து;
                }
                next();
            }
        }
    }
    திரும்பு 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
