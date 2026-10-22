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
#अन्तर्भाव "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_DATA पूर्णाङ्क rsym, anon_sym, ind, loc;

ST_DATA Sym *global_राशिः;
ST_DATA Sym *local_राशिः;
ST_DATA Sym *define_राशिः;
ST_DATA Sym *global_label_राशिः;
ST_DATA Sym *local_label_राशिः;

स्थिर Sym *sym_free_first;
स्थिर शून्य **sym_pools;
स्थिर पूर्णाङ्क nb_sym_pools;

स्थिर Sym *all_cleanups, *pending_gotos;
स्थिर पूर्णाङ्क local_scope;
ST_DATA वर्ण debug_modes;

ST_DATA SValue *vtop;
स्थिर SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA पूर्णाङ्क nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() सचे(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA पूर्णाङ्क global_व्यञ्जकम्;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA पूर्णाङ्क func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA पूर्णाङ्क func_vc; /* stack address for implicit struct return storage */
ST_DATA पूर्णाङ्क func_ind; /* function start address */
स्थिर पूर्णाङ्क func_old;
ST_DATA ध्रुव वर्ण *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
स्थिर CString initstr;

#सचे PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#नोचेद्यदि LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#अञ्ञथा
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

स्थिर संरचना switch_t {
    संरचना case_t {
        int64_t v1, v2;
        पूर्णाङ्क ind, पङ्क्तिः;
    } **p; पूर्णाङ्क n; /* list of case ranges */
    पूर्णाङ्क def_sym; /* default symbol */
    पूर्णाङ्क nocode_wanted;
    पूर्णाङ्क *bsym;
    संरचना scope *scope;
    संरचना switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_सङ्ख्या 8
/*list of temporary local variables on the stack in current function. */
स्थिर संरचना temp_local_variable {
	पूर्णाङ्क location; //offset on stack. Svalue.c.i
	short size;
	short align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_सङ्ख्या];
स्थिर पूर्णाङ्क nb_temp_local_vars;

स्थिर संरचना scope {
    संरचना scope *prev;
    संरचना { पूर्णाङ्क loc, locorig, अङ्कः; } vla;
    संरचना { Sym *s; पूर्णाङ्क n; } cl;
    पूर्णाङ्क *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *मूलम्_scope;

प्रकारनिर्देश संरचना {
    Section *sec;
    पूर्णाङ्क local_offset;
    Sym *flex_array_ref;
} init_params;

#सचे 1
#define precedence_parser
स्थिर शून्य init_prec(शून्य);
#endif

स्थिर शून्य block(पूर्णाङ्क flags);
#define STMT_व्यञ्जकम् 1
#define STMT_COMPOUND 2

स्थिर शून्य gen_cast(CType *type);
स्थिर शून्य gen_cast_s(पूर्णाङ्क t);
स्थिर अन्तःस्थ CType *pointed_type(CType *type);
स्थिर शून्य check_restrict_type(CType *type);
स्थिर पूर्णाङ्क type_qualifiers(CType *type);
स्थिर शून्य parse_btype_qualify(CType *type, पूर्णाङ्क qualifiers);
स्थिर पूर्णाङ्क is_compatible_types(CType *type1, CType *type2);
स्थिर पूर्णाङ्क parse_btype(CType *type, AttributeDef *ad, पूर्णाङ्क ignore_label);
स्थिर CType *type_decl(CType *type, AttributeDef *ad, पूर्णाङ्क *v, पूर्णाङ्क td);
स्थिर शून्य parse_व्यञ्जकम्_type(CType *type);
स्थिर शून्य init_putv(init_params *p, CType *type, unsigned long c);
स्थिर शून्य decl_initializer(init_params *p, CType *type, unsigned long c, पूर्णाङ्क flags);
स्थिर शून्य decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णाङ्क r, पूर्णाङ्क has_init, पूर्णाङ्क v, पूर्णाङ्क scope);
स्थिर पूर्णाङ्क decl(पूर्णाङ्क l);
स्थिर शून्य व्यञ्जकम्_eq(शून्य);
स्थिर शून्य vpush_type_size(CType *type, पूर्णाङ्क *a);
स्थिर पूर्णाङ्क is_compatible_unqualified_types(CType *type1, CType *type2);
स्थिर अन्तःस्थ int64_t व्यञ्जकम्_const64(शून्य);
स्थिर शून्य vpush64(पूर्णाङ्क ty, unsigned long long v);
स्थिर शून्य vpush(CType *type);
स्थिर पूर्णाङ्क gvtst(पूर्णाङ्क inv, पूर्णाङ्क t);
स्थिर शून्य gen_inline_functions(TCCState *s);
स्थिर शून्य free_inline_functions(TCCState *s);
स्थिर शून्य skip_or_save_block(TokenString **str);
स्थिर शून्य gv_dup(शून्य);
स्थिर पूर्णाङ्क get_temp_local_var(पूर्णाङ्क size,पूर्णाङ्क align,पूर्णाङ्क *r2);
स्थिर शून्य cast_error(CType *st, CType *dt);
स्थिर शून्य end_switch(शून्य);
स्थिर शून्य do_Static_assert(शून्य);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC शून्य gsym(पूर्णाङ्क t)
{
  सचे (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
स्थिर पूर्णाङ्क gind()
{
  पूर्णाङ्क t = ind;
  CODE_ON();
  सचे (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  पटिनिवत्त t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
स्थिर शून्य gjmp_addr_acs(पूर्णाङ्क t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
स्थिर पूर्णाङ्क gjmp_acs(पूर्णाङ्क t)
{
  t = gjmp(t);
  CODE_OFF();
  पटिनिवत्त t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN पूर्णाङ्क is_float(पूर्णाङ्क t)
{
    पूर्णाङ्क bt = t & VT_BTYPE;
    पटिनिवत्त bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

स्थिर अन्तःस्थ पूर्णाङ्क is_integer_btype(पूर्णाङ्क bt)
{
    पटिनिवत्त bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

स्थिर पूर्णाङ्क btype_size(पूर्णाङ्क bt)
{
    पटिनिवत्त bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
स्थिर पूर्णाङ्क R_RET(पूर्णाङ्क t)
{
    सचे (!is_float(t))
        पटिनिवत्त REG_IRET;
#ifdef TCC_TARGET_X86_64
    सचे ((t & VT_BTYPE) == VT_LDOUBLE)
        पटिनिवत्त TREG_ST0;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    सचे ((t & VT_BTYPE) == VT_LDOUBLE)
        पटिनिवत्त REG_IRET;
#endif
    पटिनिवत्त REG_FRET;
}

/* returns 2nd function return register, if any */
स्थिर पूर्णाङ्क R2_RET(पूर्णाङ्क t)
{
    t &= VT_BTYPE;
#सचे PTR_SIZE == 4
    सचे (t == VT_LLONG)
        पटिनिवत्त REG_IRE2;
#नोचेद्यदि defined TCC_TARGET_X86_64
    सचे (t == VT_QLONG)
        पटिनिवत्त REG_IRE2;
    सचे (t == VT_QFLOAT)
        पटिनिवत्त REG_FRE2;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    सचे (t == VT_LDOUBLE)
        पटिनिवत्त REG_IRE2;
#endif
    पटिनिवत्त VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_शब्दाः(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
स्थिर शून्य PUT_R_RET(SValue *sv, पूर्णाङ्क t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
स्थिर पूर्णाङ्क RC_RET(पूर्णाङ्क t)
{
    पटिनिवत्त reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
स्थिर पूर्णाङ्क RC_TYPE(पूर्णाङ्क t)
{
    सचे (!is_float(t))
        पटिनिवत्त RC_INT;
#ifdef TCC_TARGET_X86_64
    सचे ((t & VT_BTYPE) == VT_LDOUBLE)
        पटिनिवत्त RC_ST0;
    सचे ((t & VT_BTYPE) == VT_QFLOAT)
        पटिनिवत्त RC_FRET;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    सचे ((t & VT_BTYPE) == VT_LDOUBLE)
        पटिनिवत्त RC_INT;
#endif
    पटिनिवत्त RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
स्थिर पूर्णाङ्क RC2_TYPE(पूर्णाङ्क t, पूर्णाङ्क rc)
{
    सचे (!USING_TWO_शब्दाः(t))
        पटिनिवत्त 0;
#ifdef RC_IRE2
    सचे (rc == RC_IRET)
        पटिनिवत्त RC_IRE2;
#endif
#ifdef RC_FRE2
    सचे (rc == RC_FRET)
        पटिनिवत्त RC_FRE2;
#endif
    सचे (rc & RC_FLOAT)
        पटिनिवत्त RC_FLOAT;
    पटिनिवत्त RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC पूर्णाङ्क ieee_finite(द्विगुण d)
{
    पूर्णाङ्क p[4];
    memcpy(p, &d, परिमाण(द्विगुण));
    पटिनिवत्त ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC शून्य test_lvalue(शून्य)
{
    सचे (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC शून्य check_vstack(शून्य)
{
    सचे (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (पूर्णाङ्क)(vtop - vstack + 1));
}

#सचे 0
/* dump 'b' vstack entries starting with 'a'  */
शून्य pv (ध्रुव वर्ण *lbl, पूर्णाङ्क a, पूर्णाङ्क b)
{
    पूर्णाङ्क i;
    अत्थाय (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (पूर्णाङ्क)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
स्थिर अन्तःस्थ शून्य psyms(ध्रुव वर्ण *सन्देशः, Sym *s, Sym *last)
{
    printf("%-8s scope         v        c        r   type.t\n", सन्देशः);
    याव (s && s != last) {
        printf("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

स्थिर शून्य type_to_str(वर्ण *buf, पूर्णाङ्क buf_size, CType *type, ध्रुव वर्ण *varstr);

/* print type */
स्थिर शून्य ptype(ध्रुव वर्ण *सन्देशः, CType *type, पूर्णाङ्क v)
{
    वर्ण buf[500];
    type_to_str(buf, परिमाण(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, रिक्त) : रिक्त);
    printf("%s : %s;\n", सन्देशः, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC शून्य tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, परिमाण *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    सचे (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_प्रक्षिप(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC पूर्णाङ्क tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_व्यञ्जकम् = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_अङ्कः | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#सचे TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    पटिनिवत्त 0;
}

ST_FUNC शून्य tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_निष्कासय(&global_राशिः, रिक्त, 0);
    sym_निष्कासय(&local_राशिः, रिक्त, 0);
    /* free preprocessor macros */
    free_defines(रिक्त);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    याव (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = रिक्त;
    all_cleanups = रिक्त;
    pending_gotos = रिक्त;
    nb_temp_local_vars = 0;
    global_label_राशिः = रिक्त;
    local_label_राशिः = रिक्त;
    cur_text_section = रिक्त;
    sym_free_first = रिक्त;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  सचे (!s || !s->c)
    पटिनिवत्त रिक्त;
  पटिनिवत्त &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC शून्य update_storage(Sym *sym)
{
    ElfSym *esym;
    पूर्णाङ्क sym_bind, old_sym_bind;

    esym = elfsym(sym);
    सचे (!esym)
        पटिनिवत्त;

    सचे (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    सचे (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    अञ्ञथा सचे (sym->a.weak)
        sym_bind = STB_WEAK;
    अञ्ञथा
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    सचे (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    सचे (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    सचे (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#सचे 0
    printf("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, रिक्त),
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

ST_FUNC शून्य put_extern_sym2(Sym *sym, पूर्णाङ्क sh_अङ्कः,
                            addr_t मानम्, unsigned long size,
                            पूर्णाङ्क can_add_underscore)
{
    पूर्णाङ्क sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ध्रुव वर्ण *name;
    वर्ण buf1[256];

    सचे (!sym->c) {
        name = get_tok_str(sym->v, रिक्त);
        t = sym->type.t;
        सचे ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } अञ्ञथा सचे ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            सचे (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } अञ्ञथा सचे (t & VT_TLS) {
            sym_type = STT_TLS;
        } अञ्ञथा {
            sym_type = STT_OBJECT;
        }
        सचे (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        अञ्ञथा
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        सचे (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            सचे (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            सचे (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        सचे (sym->asm_label) {
            name = get_tok_str(sym->asm_label, रिक्त);
            can_add_underscore = 0;
        }

        सचे (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, परिमाण(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, मानम्, size, info, other, sh_अङ्कः, name);

        सचे (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_अङ्कः, sym_bind, sym_type);

    } अञ्ञथा {
        esym = elfsym(sym);
        esym->st_मानम् = मानम्;
        esym->st_size = size;
        esym->st_shndx = sh_अङ्कः;
    }
    update_storage(sym);
}

ST_FUNC शून्य put_extern_sym(Sym *sym, Section *s, addr_t मानम्, unsigned long size)
{
    सचे (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        पटिनिवत्त;
    put_extern_sym2(sym, s ? s->sh_अङ्कः : SHN_UNDEF, मानम्, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC शून्य greloca(Section *s, Sym *sym, unsigned long offset, पूर्णाङ्क type,
                     addr_t addend)
{
    पूर्णाङ्क c = 0;

    सचे (nocode_wanted && s == cur_text_section)
        पटिनिवत्त;

    सचे (sym) {
        सचे (0 == sym->c) {
            put_extern_sym(sym, रिक्त, 0, 0);
            सचे (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                याव (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#सचे PTR_SIZE == 4
ST_FUNC शून्य greloc(Section *s, Sym *sym, unsigned long offset, पूर्णाङ्क type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
स्थिर Sym *__sym_malloc(शून्य)
{
    Sym *sym_pool, *sym, *last_sym;
    पूर्णाङ्क i;

    sym_pool = tcc_malloc(SYM_POOL_NB * परिमाण(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    अत्थाय(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    पटिनिवत्त last_sym;
}

स्थिर अन्तःस्थ Sym *sym_malloc(शून्य)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    सचे (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    पटिनिवत्त sym;
#अञ्ञथा
    sym = tcc_malloc(परिमाण(Sym));
    पटिनिवत्त sym;
#endif
}

ST_INLN शून्य sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#अञ्ञथा
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, पूर्णाङ्क v, पूर्णाङ्क t, पूर्णाङ्क c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, परिमाण *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    पटिनिवत्त s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, पूर्णाङ्क v)
{
    याव (s) {
        सचे (s->v == v)
            पटिनिवत्त s;
        s = s->prev;
    }
    पटिनिवत्त रिक्त;
}

/* structure lookup */
ST_INLN Sym *struct_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    सचे ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        पटिनिवत्त रिक्त;
    पटिनिवत्त table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    सचे ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        पटिनिवत्त रिक्त;
    पटिनिवत्त table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
स्थिर अन्तःस्थ शून्य sym_link(Sym *s, पूर्णाङ्क yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    सचे (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    अञ्ञथा
        ps = &ts->sym_identifier;
    सचे (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } अञ्ञथा {
        *ps = s->prev_tok;
    }
}

स्थिर अन्तःस्थ पूर्णाङ्क sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    पटिनिवत्त IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_प्रक्षिप(पूर्णाङ्क v, CType *type, पूर्णाङ्क r, पूर्णाङ्क c)
{
    Sym *s, **ps;
    सचे (local_राशिः)
        ps = &local_राशिः;
    अञ्ञथा
        ps = &global_राशिः;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    सचे ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        सचे (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, रिक्त));
    }
    पटिनिवत्त s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_प्रक्षिप(पूर्णाङ्क v, पूर्णाङ्क t, पूर्णाङ्क c)
{
    Sym *s, **ps;
    s = sym_push2(&global_राशिः, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    सचे (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        याव (*ps != रिक्त && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    पटिनिवत्त s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC शून्य sym_निष्कासय(Sym **ptop, Sym *b, पूर्णाङ्क keep)
{
    Sym *s, *ss;
    पूर्णाङ्क v;

    s = *ptop;
    याव(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        सचे ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	सचे (!keep)
	    sym_free(s);
        s = ss;
    }
    सचे (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    सचे ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        पटिनिवत्त रिक्त;
    पटिनिवत्त table_ident[v]->sym_label;
}

ST_FUNC Sym *label_प्रक्षिप(Sym **ptop, पूर्णाङ्क v, पूर्णाङ्क flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    सचे (ptop == &global_label_राशिः) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        याव (*ps != रिक्त)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    पटिनिवत्त s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC शून्य label_निष्कासय(Sym **ptop, Sym *slast, पूर्णाङ्क keep)
{
    Sym *s, *s1;
    अत्थाय(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        सचे (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, रिक्त));
        } अञ्ञथा सचे (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, रिक्त));
        } अञ्ञथा {
            सचे (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        सचे (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        सचे (!keep)
            sym_free(s);
        अञ्ञथा
            s->r = LABEL_GONE;
    }
    सचे (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
स्थिर शून्य vcheck_cmp(शून्य)
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

    सचे (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

स्थिर शून्य vsetc(CType *type, पूर्णाङ्क r, CValue *vc)
{
    सचे (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = रिक्त;
}

ST_FUNC शून्य vswap(शून्य)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC शून्य vpop(शून्य)
{
    पूर्णाङ्क v;
    v = vtop->r & VT_VALMASK;
#सचे defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    सचे (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } अञ्ञथा
#endif
    सचे (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
स्थिर शून्य vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
स्थिर शून्य vpush64(पूर्णाङ्क ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = रिक्त;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC शून्य vpushi(पूर्णाङ्क v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
स्थिर शून्य vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
स्थिर अन्तःस्थ शून्य vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC शून्य vset(CType *type, पूर्णाङ्क r, पूर्णाङ्क v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

स्थिर शून्य vseti(पूर्णाङ्क r, पूर्णाङ्क v)
{
    CType type;
    type.t = VT_INT;
    type.ref = रिक्त;
    vset(&type, r, v);
}

ST_FUNC शून्य vpushv(SValue *v)
{
    सचे (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

स्थिर शून्य vdup(शून्य)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC शून्य vrotb(पूर्णाङ्क n)
{
    SValue tmp;
    सचे (--n < 1)
        पटिनिवत्त;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, परिमाण *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC शून्य vrott(पूर्णाङ्क n)
{
    SValue tmp;
    सचे (--n < 1)
        पटिनिवत्त;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, परिमाण *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC शून्य vrev(पूर्णाङ्क n)
{
    पूर्णाङ्क i;
    SValue tmp;
    vcheck_cmp();
    अत्थाय (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC शून्य vset_VT_CMP(पूर्णाङ्क op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
स्थिर शून्य vset_VT_JMP(शून्य)
{
    पूर्णाङ्क op = vtop->cmp_op;

    सचे (vtop->jtrue || vtop->jfalse) {
        पूर्णाङ्क origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        पूर्णाङ्क inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } अञ्ञथा {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        सचे (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
स्थिर शून्य gvtst_set(पूर्णाङ्क inv, पूर्णाङ्क t)
{
    पूर्णाङ्क *p;

    सचे (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        सचे (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
स्थिर पूर्णाङ्क gvtst(पूर्णाङ्क inv, पूर्णाङ्क t)
{
    पूर्णाङ्क op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    सचे (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    सचे (op > 1)
        t = gjmp_cond(op ^ inv, t);
    अञ्ञथा सचे (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    पटिनिवत्त t;
}

/* generate a zero or nozero test */
स्थिर शून्य gen_test_zero(पूर्णाङ्क op)
{
    सचे (vtop->r == VT_CMP) {
        पूर्णाङ्क j;
        सचे (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } अञ्ञथा {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC शून्य vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    पूर्णाङ्क v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_प्रक्षिप(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    पटिनिवत्त sym;
}

/* push a reference to a section offset by adding a dummy symbol */
स्थिर शून्य vpush_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(पूर्णाङ्क v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    सचे (!s) {
        /* push forward reference */
        s = global_identifier_प्रक्षिप(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } अञ्ञथा सचे (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    पटिनिवत्त s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(पूर्णाङ्क v)
{
    CType ct = { VT_ASM_FUNC, रिक्त };
    पटिनिवत्त external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC शून्य vpush_helper_func(पूर्णाङ्क v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
स्थिर शून्य merge_symattr(संरचना SymAttr *sa, संरचना SymAttr *sa1)
{
    सचे (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    सचे (sa1->visibility != STV_DEFAULT) {
	पूर्णाङ्क vis = sa->visibility;
	सचे (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
स्थिर शून्य merge_funcattr(संरचना FuncAttr *fa, संरचना FuncAttr *fa1)
{
    सचे (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    सचे (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    सचे (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    सचे (fa1->func_noreturn)
      fa->func_noreturn = 1;
    सचे (fa1->func_ctor)
      fa->func_ctor = 1;
    सचे (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
स्थिर शून्य merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    सचे (ad1->section)
      ad->section = ad1->section;
    सचे (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    सचे (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    सचे (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
स्थिर शून्य patch_type(Sym *sym, CType *type)
{
    सचे (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        सचे (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, रिक्त));
        sym->type.t &= ~VT_EXTERN;
    }

    सचे (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        सचे ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    सचे (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, रिक्त));

    } अञ्ञथा सचे ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        पूर्णाङ्क static_proto = sym->type.t & VT_STATIC;
        पूर्णाङ्क ft1 = sym->type.ref->f.func_type;
        पूर्णाङ्क ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        सचे ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, रिक्त));

        /* set 'inline' if both agree or if one has static */
        सचे ((type->t | sym->type.t) & VT_INLINE) {
            सचे (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        सचे (0 == (type->t & VT_EXTERN)) {
            संरचना FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            सचे (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } अञ्ञथा {
            sym->type.t &= ~VT_INLINE | static_proto;
            सचे (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } अञ्ञथा {
        सचे ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        सचे ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, रिक्त));
    }
}

/* Merge some storage attributes.  */
स्थिर शून्य patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    सचे (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    सचे (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, रिक्त));
#endif
    merge_symattr(&sym->a, &ad->a);
    सचे (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
स्थिर Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    सचे ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    पटिनिवत्त s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
स्थिर शून्य move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    पूर्णाङ्क n, bt;

    bt = s->type.t & VT_BTYPE;
    सचे (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        पटिनिवत्त;

    अत्थाय (s = s->type.ref, n = 0; s; s = s->next) {
        अत्थाय (lp = &local_राशिः; !!(l = *lp); lp = &l->prev) {
            सचे (l == s) {
                *lp = s->prev;
                s->prev = global_राशिः, global_राशिः = s;
                सचे (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } अञ्ञथा {
                    सचे ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                सचे (bt != VT_PTR)
                    n = 1;
                भङ्ग;
            }
        }
        सचे (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            भङ्ग;
    }
}

/* define a new external reference to a symbol 'v' */
स्थिर Sym *external_sym(पूर्णाङ्क v, CType *type, पूर्णाङ्क r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    याव (s && s->sym_scope)
        s = s->prev_tok;

    सचे (!s) {
        /* push forward reference */
        s = global_identifier_प्रक्षिप(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } अञ्ञथा {
        patch_storage(s, ad, type);
    }
    सचे (local_राशिः) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_राशिः);
    }
    पटिनिवत्त s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC शून्य save_regs(पूर्णाङ्क n)
{
    SValue *p, *p1;
    अत्थाय(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC शून्य save_reg(पूर्णाङ्क r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC शून्य save_reg_upstack(पूर्णाङ्क r, पूर्णाङ्क n)
{
    पूर्णाङ्क l, size, align, bt, r2;
    SValue *p, *p1, sv;

    सचे ((r &= VT_VALMASK) >= VT_CONST)
        पटिनिवत्त;
    सचे (nocode_wanted)
        पटिनिवत्त;
    l = r2 = 0;
    अत्थाय(p = vstack, p1 = vtop - n; p <= p1; p++) {
        सचे ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            सचे (!l) {
                bt = p->type.t & VT_BTYPE;
                सचे (bt == VT_VOID)
                    अनुवर्त;
                सचे ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = रिक्त;
                store(p->r & VT_VALMASK, &sv);
#सचे defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                सचे (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                सचे (p->r2 < VT_CONST && USING_TWO_शब्दाः(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            सचे (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } अञ्ञथा {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = रिक्त;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC पूर्णाङ्क get_reg_ex(पूर्णाङ्क rc, पूर्णाङ्क rc2)
{
    पूर्णाङ्क r;
    SValue *p;
    
    अत्थाय(r=0;r<NB_REGS;r++) {
        सचे (reg_classes[r] & rc2) {
            पूर्णाङ्क n;
            n=0;
            अत्थाय(p = vstack; p <= vtop; p++) {
                सचे ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            सचे (n <= 1)
                पटिनिवत्त r;
        }
    }
    पटिनिवत्त get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC पूर्णाङ्क get_reg(पूर्णाङ्क rc)
{
    पूर्णाङ्क r;
    SValue *p;

    /* find a free register */
    अत्थाय(r=0;r<NB_REGS;r++) {
        सचे (reg_classes[r] & rc) {
            सचे (nocode_wanted)
                पटिनिवत्त r;
            अत्थाय(p=vstack;p<=vtop;p++) {
                सचे ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    गच्छ notfound;
            }
            पटिनिवत्त r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    अत्थाय(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        सचे (r < VT_CONST && (reg_classes[r] & rc))
            गच्छ save_found;
        r = p->r & VT_VALMASK;
        सचे (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            पटिनिवत्त r;
        }
    }
    /* Should never comes here */
    पटिनिवत्त -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
स्थिर पूर्णाङ्क get_temp_local_var(पूर्णाङ्क size,पूर्णाङ्क align, पूर्णाङ्क *r2)
{
    पूर्णाङ्क i;
    संरचना temp_local_variable *temp_var;
    SValue *p;
    पूर्णाङ्क r;
    unsigned used = 0;

    /* mark locations that are still in use */
    अत्थाय (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	सचे (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    सचे (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_सङ्ख्या)
	        used |= 1<<r;
	}
    }
    अत्थाय (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	सचे(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    पटिनिवत्त temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    सचे (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_सङ्ख्या) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	गच्छ ret_tmp;
    }
    *r2 = VT_CONST;
    पटिनिवत्त loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
स्थिर शून्य move_reg(पूर्णाङ्क r, पूर्णाङ्क s, पूर्णाङ्क t)
{
    SValue sv;

    सचे (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = रिक्त;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC शून्य gaddrof(शून्य)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    सचे ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
स्थिर शून्य gen_bounded_ptr_add(शून्य)
{
    पूर्णाङ्क save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    सचे (save) {
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
    सचे (nocode_wanted)
        पटिनिवत्त;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - परिमाण(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
स्थिर शून्य gen_bounded_ptr_deref(शून्य)
{
    addr_t func;
    पूर्णाङ्क size, align;
    ElfW_Rel *rel;
    Sym *sym;

    सचे (nocode_wanted)
        पटिनिवत्त;

    size = type_size(&vtop->type, &align);
    विकल्प(size) {
    पक्ष  1: func = TOK___bound_ptr_indir1; भङ्ग;
    पक्ष  2: func = TOK___bound_ptr_indir2; भङ्ग;
    पक्ष  4: func = TOK___bound_ptr_indir4; भङ्ग;
    पक्ष  8: func = TOK___bound_ptr_indir8; भङ्ग;
    पक्ष 12: func = TOK___bound_ptr_indir12; भङ्ग;
    पक्ष 16: func = TOK___bound_ptr_indir16; भङ्ग;
    स्वभाव:
        /* may happen with struct member access */
        पटिनिवत्त;
    }
    sym = external_helper_sym(func);
    सचे (!sym->c)
        put_extern_sym(sym, रिक्त, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->data + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
स्थिर शून्य gbound(शून्य)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    सचे (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        सचे (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC शून्य gbound_args(पूर्णाङ्क nb_args)
{
    पूर्णाङ्क i, v;
    SValue *sv;

    अत्थाय (i = 1; i <= nb_args; ++i)
        सचे (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    सचे (sv->r & VT_SYM) {
        v = sv->sym->v;
        सचे (v == TOK_setjmp
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
        सचे (v == TOK_alloca)
            func_bound_add_epilog = 1;
#सचे TARGETOS_NetBSD
        सचे (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
स्थिर शून्य add_local_bounds(Sym *s, Sym *e)
{
    अत्थाय (; s != e; s = s->prev) {
        सचे (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          अनुवर्त;
        /* Add arrays/structs/unions because we always take address */
        सचे ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            पूर्णाङ्क align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * परिमाण(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
स्थिर शून्य tcc_debug_end_scope(Sym *b, पूर्णाङ्क bounds)
{
#ifdef CONFIG_TCC_BCHECK
    सचे (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_राशिः, b);
#endif
    tcc_add_debug_info (tcc_state, local_राशिः, b);
}

/* increment an lvalue pointer */
स्थिर शून्य incr_offset(पूर्णाङ्क offset)
{
    पूर्णाङ्क t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

स्थिर शून्य incr_bf_adr(पूर्णाङ्क o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
स्थिर शून्य load_packed_bf(CType *type, पूर्णाङ्क bit_pos, पूर्णाङ्क bit_size)
{
    पूर्णाङ्क n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    करोहि {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        सचे (n > bit_size)
            n = bit_size;
        सचे (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        सचे (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        सचे (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } याव (bit_size);
    vswap(), vpop();
    सचे (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
स्थिर शून्य store_packed_bf(पूर्णाङ्क bit_pos, पूर्णाङ्क bit_size)
{
    पूर्णाङ्क bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    करोहि {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        सचे (bits)
            vpushi(bits), gen_op(TOK_SHR);
        सचे (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        सचे (n > bit_size)
            n = bit_size;
        सचे (n < 8) {
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
    } याव (bit_size);
    vpop(), vpop();
}

स्थिर पूर्णाङ्क adjust_bf(SValue *sv, पूर्णाङ्क bit_pos, पूर्णाङ्क bit_size)
{
    पूर्णाङ्क t;
    सचे (0 == sv->type.ref)
        पटिनिवत्त 0;
    t = sv->type.ref->auxtype;
    सचे (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    पटिनिवत्त t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC पूर्णाङ्क gv(पूर्णाङ्क rc)
{
    पूर्णाङ्क r, r2, r_ok, r2_ok, rc2, bt;
    पूर्णाङ्क bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    सचे (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = रिक्त;
        type.t = vtop->type.t & VT_UNSIGNED;
        सचे ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        सचे ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        अञ्ञथा
            type.t |= VT_INT;

        सचे (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } अञ्ञथा {
            पूर्णाङ्क bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } अञ्ञथा {
        सचे (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            unsigned long offset;
            size = type_size(&vtop->type, &align);
            सचे (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        सचे (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        सचे (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            पटिनिवत्त vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        सचे (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        सचे (!r_ok || !r2_ok) {

            सचे (!r_ok) {
                सचे (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                अञ्ञथा
                    r = get_reg(rc);
            }

            सचे (rc2) {
                पूर्णाङ्क load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                पूर्णाङ्क original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                सचे ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    unsigned long long ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } अञ्ञथा सचे (vtop->r & VT_LVAL) {
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
                } अञ्ञथा {
                    /* move registers */
                    सचे (!r_ok)
                        load(r, vtop);
                    सचे (r2_ok && vtop->r2 < VT_CONST)
                        गच्छ done;
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
            } अञ्ञथा {
                सचे (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        सचे (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    पटिनिवत्त r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC शून्य gv2(पूर्णाङ्क rc1, पूर्णाङ्क rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    सचे (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        सचे ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } अञ्ञथा {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        सचे ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#सचे PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC शून्य lexpand(शून्य)
{
    पूर्णाङ्क u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    सचे (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } अञ्ञथा सचे (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } अञ्ञथा {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#सचे PTR_SIZE == 4
/* build a long long from two ints */
स्थिर शून्य lbuild(पूर्णाङ्क t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#endif

/* convert stack entry to register and duplicate its value in another
   register */
स्थिर शून्य gv_dup(शून्य)
{
    पूर्णाङ्क t, rc, r;

    t = vtop->type.t;
#सचे PTR_SIZE == 4
    सचे ((t & VT_BTYPE) == VT_LLONG) {
        सचे (t & VT_BITFIELD) {
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
        पटिनिवत्त;
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

#सचे PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
स्थिर शून्य gen_opl(पूर्णाङ्क op)
{
    पूर्णाङ्क t, a, b, op1, c, i;
    पूर्णाङ्क func;
    unsigned short reg_iret = REG_IRET;
    unsigned short reg_lret = REG_IRE2;
    SValue tmp;

    विकल्प(op) {
    पक्ष '/':
    पक्ष TOK_PDIV:
        func = TOK___divdi3;
        गच्छ gen_func;
    पक्ष TOK_UDIV:
        func = TOK___udivdi3;
        गच्छ gen_func;
    पक्ष '%':
        func = TOK___moddi3;
        गच्छ gen_mod_func;
    पक्ष TOK_UMOD:
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
        भङ्ग;
    पक्ष '^':
    पक्ष '&':
    पक्ष '|':
    पक्ष '*':
    पक्ष '+':
    पक्ष '-':
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
        सचे (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            अत्थाय(i=0;i<4;i++)
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
        } अञ्ञथा सचे (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            सचे (op == '+')
                op1 = TOK_ADDC1;
            अञ्ञथा
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } अञ्ञथा {
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
        भङ्ग;
    पक्ष TOK_SAR:
    पक्ष TOK_SHR:
    पक्ष TOK_SHL:
        सचे ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (पूर्णाङ्क)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            सचे (op != TOK_SHL)
                vswap();
            सचे (c >= 32) {
                /* stack: L H */
                vpop();
                सचे (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                सचे (op != TOK_SAR) {
                    vpushi(0);
                } अञ्ञथा {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } अञ्ञथा {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                सचे (op == TOK_SHL)
                    gen_op(TOK_SHR);
                अञ्ञथा
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                सचे (op == TOK_SHL)
                    gen_op(TOK_SHL);
                अञ्ञथा
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            सचे (op != TOK_SHL)
                vswap();
            lbuild(t);
        } अञ्ञथा {
            /* XXX: should provide a faster fallback on x86 ? */
            विकल्प(op) {
            पक्ष TOK_SAR:
                func = TOK___ashrdi3;
                गच्छ gen_func;
            पक्ष TOK_SHR:
                func = TOK___lshrdi3;
                गच्छ gen_func;
            पक्ष TOK_SHL:
                func = TOK___ashldi3;
                गच्छ gen_func;
            }
        }
        भङ्ग;
    स्वभाव:
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
        सचे (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        सचे (op1 == TOK_LT)
            op1 = TOK_LE;
        अञ्ञथा सचे (op1 == TOK_GT)
            op1 = TOK_GE;
        अञ्ञथा सचे (op1 == TOK_ULT)
            op1 = TOK_ULE;
        अञ्ञथा सचे (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        सचे (op == TOK_NE) {
            b = gvtst(0, 0);
        } अञ्ञथा {
            a = gvtst(1, 0);
            सचे (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        सचे (op1 == TOK_LT)
            op1 = TOK_ULT;
        अञ्ञथा सचे (op1 == TOK_LE)
            op1 = TOK_ULE;
        अञ्ञथा सचे (op1 == TOK_GT)
            op1 = TOK_UGT;
        अञ्ञथा सचे (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#सचे 0//def TCC_TARGET_I386
        सचे (op == TOK_NE) { gsym(b); भङ्ग; }
        सचे (op == TOK_EQ) { gsym(a); भङ्ग; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        भङ्ग;
    }
}
#endif

/* normalize values */
स्थिर uint64_t value64(uint64_t l1, पूर्णाङ्क t)
{
    सचे ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        पटिनिवत्त l1;
    अञ्ञथा सचे (t & VT_UNSIGNED)
        पटिनिवत्त (uint32_t)l1;
    अञ्ञथा
        पटिनिवत्त (uint32_t)l1 | -(l1 & 0x80000000);
}

स्थिर uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    पटिनिवत्त (a ^ b) >> 63 ? -x : x;
}

स्थिर पूर्णाङ्क gen_opic_lt(uint64_t a, uint64_t b)
{
    पटिनिवत्त (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
स्थिर शून्य gen_opic(पूर्णाङ्क op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    पूर्णाङ्क t1 = v1->type.t & VT_BTYPE;
    पूर्णाङ्क t2 = v2->type.t & VT_BTYPE;
    पूर्णाङ्क c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    पूर्णाङ्क c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    पूर्णाङ्क shm = (t1 == VT_LLONG) ? 63 : 31;
    पूर्णाङ्क r;

    सचे (c1 && c2) {
        विकल्प(op) {
        पक्ष '+': l1 += l2; भङ्ग;
        पक्ष '-': l1 -= l2; भङ्ग;
        पक्ष '&': l1 &= l2; भङ्ग;
        पक्ष '^': l1 ^= l2; भङ्ग;
        पक्ष '|': l1 |= l2; भङ्ग;
        पक्ष '*': l1 *= l2; भङ्ग;

        पक्ष TOK_PDIV:
        पक्ष '/':
        पक्ष '%':
        पक्ष TOK_UDIV:
        पक्ष TOK_UMOD:
            /* if division by zero, generate explicit division */
            सचे (l2 == 0) {
                सचे (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                गच्छ general_case;
            }
            विकल्प(op) {
            स्वभाव: l1 = gen_opic_sdiv(l1, l2); भङ्ग;
            पक्ष '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); भङ्ग;
            पक्ष TOK_UDIV: l1 = l1 / l2; भङ्ग;
            पक्ष TOK_UMOD: l1 = l1 % l2; भङ्ग;
            }
            भङ्ग;
        पक्ष TOK_SHL: l1 <<= (l2 & shm); भङ्ग;
        पक्ष TOK_SHR: l1 >>= (l2 & shm); भङ्ग;
        पक्ष TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            भङ्ग;
            /* tests */
        पक्ष TOK_ULT: l1 = l1 < l2; भङ्ग;
        पक्ष TOK_UGE: l1 = l1 >= l2; भङ्ग;
        पक्ष TOK_EQ: l1 = l1 == l2; भङ्ग;
        पक्ष TOK_NE: l1 = l1 != l2; भङ्ग;
        पक्ष TOK_ULE: l1 = l1 <= l2; भङ्ग;
        पक्ष TOK_UGT: l1 = l1 > l2; भङ्ग;
        पक्ष TOK_LT: l1 = gen_opic_lt(l1, l2); भङ्ग;
        पक्ष TOK_GE: l1 = !gen_opic_lt(l1, l2); भङ्ग;
        पक्ष TOK_LE: l1 = !gen_opic_lt(l2, l1); भङ्ग;
        पक्ष TOK_GT: l1 = gen_opic_lt(l2, l1); भङ्ग;
            /* logical */
        पक्ष TOK_LAND: l1 = l1 && l2; भङ्ग;
        पक्ष TOK_LOR: l1 = l1 || l2; भङ्ग;
        स्वभाव:
            गच्छ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } अञ्ञथा {
        /* if commutative ops, put c2 as constant */
        सचे (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        सचे (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } अञ्ञथा सचे (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            सचे (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } अञ्ञथा सचे (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } अञ्ञथा सचे (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            सचे (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                पूर्णाङ्क n = -1;
                सचे (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    गच्छ general_case;
                }
                याव (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                सचे (op == '*')
                    op = TOK_SHL;
                अञ्ञथा सचे (op == TOK_PDIV)
                    op = TOK_SAR;
                अञ्ञथा
                    op = TOK_SHR;
            }
            गच्छ general_case;
        } अञ्ञथा सचे (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            सचे (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    सचे ((पूर्णाङ्क)l2 != l2)
	        गच्छ general_case;
            vtop--;
            vtop->c.i = l2;
        } अञ्ञथा {
        general_case:
                /* call low level op generator */
                सचे (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                अञ्ञथा
                    gen_opi(op);
        }
        सचे (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#सचे defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#नोचेद्यदि defined TCC_TARGET_ARM
शून्य gen_negf(पूर्णाङ्क op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#अञ्ञथा
/* XXX: implement in gen_opf() for other backends too */
शून्य gen_negf(पूर्णाङ्क op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    पूर्णाङ्क align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#सचे defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    सचे (bt == VT_LDOUBLE)
        size = 10;
#endif
    सचे (nocode_wanted) /* save_reg() wont work */
        गच्छ gv2;
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
स्थिर शून्य gen_opif(पूर्णाङ्क op)
{
    पूर्णाङ्क c1, c2, i, bt;
    SValue *v1, *v2;
#सचे defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    चञ्चल
#endif
    long द्विगुण f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    सचे (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    सचे (c1 && c2) {
        सचे (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } अञ्ञथा सचे (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } अञ्ञथा {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        सचे (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            गच्छ general_case;
        विकल्प(op) {
        पक्ष '+': f1 += f2; भङ्ग;
        पक्ष '-': f1 -= f2; भङ्ग;
        पक्ष '*': f1 *= f2; भङ्ग;
        पक्ष '/': 
            सचे (f2 == 0.0) {
                सङ्घ { भिन्न f; unsigned u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                सचे (!CONST_WANTED)
                    गच्छ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                सचे (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                अञ्ञथा
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                भङ्ग;
            }
            f1 /= f2;
            भङ्ग;
        पक्ष TOK_NEG:
            f1 = -f1;
            गच्छ unary_result;
        पक्ष TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            पटिनिवत्त;
        पक्ष TOK_NE:
            i = f1 != f2;
	    गच्छ make_int;
        पक्ष TOK_LT:
            i = f1 < f2;
	    गच्छ make_int;
        पक्ष TOK_GE:
            i = f1 >= f2;
	    गच्छ make_int;
        पक्ष TOK_LE:
            i = f1 <= f2;
	    गच्छ make_int;
        पक्ष TOK_GT:
            i = f1 > f2;
	    गच्छ make_int;
        स्वभाव:
            गच्छ general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        सचे (bt == VT_FLOAT) {
            v1->c.f = f1;
        } अञ्ञथा सचे (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } अञ्ञथा {
            v1->c.ld = f1;
        }
    } अञ्ञथा {
    general_case:
        सचे (op == TOK_NEG) {
            gen_negf(op);
        } अञ्ञथा {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
स्थिर शून्य type_to_str(वर्ण *buf, पूर्णाङ्क buf_size,
                 CType *type, ध्रुव वर्ण *varstr)
{
    पूर्णाङ्क bt, v, t;
    Sym *s, *sa;
    वर्ण buf1[256];
    ध्रुव वर्ण *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    सचे (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    सचे (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    सचे (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    सचे (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    सचे (bt != VT_PTR) {
        सचे (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        सचे (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        सचे (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    सचे (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    विकल्प(bt) {
    पक्ष VT_VOID:
        tstr = "void";
        गच्छ add_tstr;
    पक्ष VT_BOOL:
        tstr = "_Bool";
        गच्छ add_tstr;
    पक्ष VT_BYTE:
        tstr = "char";
        गच्छ add_tstr;
    पक्ष VT_SHORT:
        tstr = "short";
        गच्छ add_tstr;
    पक्ष VT_INT:
        tstr = "int";
        गच्छ maybe_long;
    पक्ष VT_LLONG:
        tstr = "long long";
    maybe_long:
        सचे (t & VT_LONG)
            tstr = "long";
        सचे (!IS_ENUM(t))
            गच्छ add_tstr;
        tstr = "enum ";
        गच्छ tstruct;
    पक्ष VT_FLOAT:
        tstr = "float";
        गच्छ add_tstr;
    पक्ष VT_DOUBLE:
        tstr = "double";
        सचे (!(t & VT_LONG))
            गच्छ add_tstr;
    पक्ष VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        भङ्ग;
    पक्ष VT_STRUCT:
        tstr = "struct ";
        सचे (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        सचे (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        अञ्ञथा
            pstrcat(buf, buf_size, get_tok_str(v, रिक्त));
        भङ्ग;
    पक्ष VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        सचे (varstr && '*' == *varstr) {
            pstrcat(buf1, परिमाण(buf1), "(");
            pstrcat(buf1, परिमाण(buf1), varstr);
            pstrcat(buf1, परिमाण(buf1), ")");
        }
        pstrcat(buf1, परिमाण(buf1), "(");
        sa = s->next;
        याव (sa != रिक्त) {
            वर्ण buf2[256];
            type_to_str(buf2, परिमाण(buf2), &sa->type, रिक्त);
            pstrcat(buf1, परिमाण(buf1), buf2);
            sa = sa->next;
            सचे (sa)
                pstrcat(buf1, परिमाण(buf1), ", ");
        }
        सचे (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, परिमाण(buf1), ", ...");
        pstrcat(buf1, परिमाण(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        गच्छ no_var;
    पक्ष VT_PTR:
        s = type->ref;
        सचे (t & (VT_ARRAY|VT_VLA)) {
            सचे (varstr && '*' == *varstr)
                snprintf(buf1, परिमाण(buf1), "(%s)[%d]", varstr, s->c);
            अञ्ञथा
                snprintf(buf1, परिमाण(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            गच्छ no_var;
        }
        pstrcpy(buf1, परिमाण(buf1), "*");
        सचे (t & VT_RESTRICT)
            pstrcat(buf1, परिमाण(buf1), "restrict ");
        सचे (t & VT_CONSTANT)
            pstrcat(buf1, परिमाण(buf1), "const ");
        सचे (t & VT_VOLATILE)
            pstrcat(buf1, परिमाण(buf1), "volatile ");
        सचे (varstr)
            pstrcat(buf1, परिमाण(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        गच्छ no_var;
    }
    सचे (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

स्थिर शून्य type_incompatibility_error(CType* st, CType* dt, ध्रुव वर्ण* fmt)
{
    वर्ण buf1[256], buf2[256];
    type_to_str(buf1, परिमाण(buf1), st, रिक्त);
    type_to_str(buf2, परिमाण(buf2), dt, रिक्त);
    tcc_error(fmt, buf1, buf2);
}

स्थिर शून्य type_incompatibility_warning(CType* st, CType* dt, ध्रुव वर्ण* fmt)
{
    वर्ण buf1[256], buf2[256];
    type_to_str(buf1, परिमाण(buf1), st, रिक्त);
    type_to_str(buf2, परिमाण(buf2), dt, रिक्त);
    tcc_warning(fmt, buf1, buf2);
}

स्थिर पूर्णाङ्क pointed_size(CType *type)
{
    पूर्णाङ्क align;
    पटिनिवत्त type_size(pointed_type(type), &align);
}

स्थिर अन्तःस्थ पूर्णाङ्क is_null_pointer(SValue *p)
{
    सचे ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        पटिनिवत्त 0;
    पटिनिवत्त ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
स्थिर पूर्णाङ्क is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    सचे (s1->f.func_call != s2->f.func_call)
        पटिनिवत्त 0;
    सचे (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        पटिनिवत्त 0;
    अत्थाय (;;) {
        सचे (!is_compatible_unqualified_types(&s1->type, &s2->type))
            पटिनिवत्त 0;
        सचे (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            पटिनिवत्त 1;
        s1 = s1->next;
        s2 = s2->next;
        सचे (!s1)
            पटिनिवत्त !s2;
        सचे (!s2)
            पटिनिवत्त 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
स्थिर पूर्णाङ्क compare_types(CType *type1, CType *type2, पूर्णाङ्क unqualified)
{
    पूर्णाङ्क bt1, t1, t2;

    सचे (IS_ENUM(type1->t)) {
        सचे (IS_ENUM(type2->t))
            पटिनिवत्त type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } अञ्ञथा सचे (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    सचे (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    सचे ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    सचे (t1 != t2)
        पटिनिवत्त 0;

    सचे ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            पटिनिवत्त 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    सचे (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        सचे (unqualified && (t1 & VT_ARRAY))
            पटिनिवत्त compare_types(type1, type2, 1);
        पटिनिवत्त is_compatible_types(type1, type2);
    } अञ्ञथा सचे (bt1 == VT_STRUCT) {
        पटिनिवत्त (type1->ref == type2->ref);
    } अञ्ञथा सचे (bt1 == VT_FUNC) {
        पटिनिवत्त is_compatible_func(type1, type2);
    } अञ्ञथा {
        पटिनिवत्त 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
स्थिर पूर्णाङ्क combine_types(CType *dest, SValue *op1, SValue *op2, पूर्णाङ्क op)
{
    CType *type1, *type2, type;
    पूर्णाङ्क t1, t2, bt1, bt2;
    पूर्णाङ्क ret = 1;

    /* for shifts, 'combine' only left operand */
    सचे (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = रिक्त;

    सचे (bt1 == VT_VOID || bt2 == VT_VOID) {
        सचे (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } अञ्ञथा सचे (bt1 == VT_PTR || bt2 == VT_PTR) {
        सचे (op == '+') {
          सचे (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        अञ्ञथा सचे (is_null_pointer (op2)) type = *type1;
        अञ्ञथा सचे (is_null_pointer (op1)) type = *type2;
        अञ्ञथा सचे (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            सचे ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            अञ्ञथा सचे (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } अञ्ञथा {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            पूर्णाङ्क pbt1 = pt1->t & VT_BTYPE;
            पूर्णाङ्क pbt2 = pt2->t & VT_BTYPE;
            पूर्णाङ्क newquals, copied = 0;
            सचे (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                सचे (op != '?' && op != CMP_OP)
                  ret = 0;
                अञ्ञथा
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            सचे (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                सचे ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_प्रक्षिप(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                सचे (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    सचे (!copied)
                      type.ref = sym_प्रक्षिप(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_प्रक्षिप(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        सचे (op == CMP_OP)
          type.t = VT_SIZE_T;
    } अञ्ञथा सचे (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        सचे (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } अञ्ञथा सचे (is_float(bt1) || is_float(bt2)) {
        सचे (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } अञ्ञथा सचे (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } अञ्ञथा {
            type.t = VT_FLOAT;
        }
    } अञ्ञथा सचे (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        सचे (bt1 == VT_LLONG)
          type.t &= t1;
        सचे (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        सचे ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } अञ्ञथा {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        सचे (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    सचे (dest)
      *dest = type;
    पटिनिवत्त ret;
}

/* generic gen_op: handles types problems */
ST_FUNC शून्य gen_op(पूर्णाङ्क op)
{
    पूर्णाङ्क t1, t2, bt1, bt2, t;
    CType type1, combtype;
    पूर्णाङ्क op_class = op;

    सचे (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    अञ्ञथा सचे (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    सचे (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	सचे (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	सचे (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	गच्छ redo;
    } अञ्ञथा सचे (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } अञ्ञथा सचे (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        पूर्णाङ्क align;
        सचे (op_class == CMP_OP)
            गच्छ std_op;
        /* if both pointers, then it must be the '-' op */
        सचे (bt1 == VT_PTR && bt2 == VT_PTR) {
            सचे (op != '-')
                गच्छ op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } अञ्ञथा {
            /* exactly one pointer : must be '+' or '-'. */
            सचे (op != '-' && op != '+')
                गच्छ op_err;
            /* Put pointer as first operand */
            सचे (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#सचे PTR_SIZE == 4
            सचे (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            सचे (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                सचे (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } अञ्ञथा
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } अञ्ञथा {
        /* floats can only be used for a few operations */
        सचे (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            गच्छ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        सचे (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        सचे (t & VT_UNSIGNED) {
            सचे (op == TOK_SAR)
                op = TOK_SHR;
            अञ्ञथा सचे (op == '/')
                op = TOK_UDIV;
            अञ्ञथा सचे (op == '%')
                op = TOK_UMOD;
            अञ्ञथा सचे (op == TOK_LT)
                op = TOK_ULT;
            अञ्ञथा सचे (op == TOK_GT)
                op = TOK_UGT;
            अञ्ञथा सचे (op == TOK_LE)
                op = TOK_ULE;
            अञ्ञथा सचे (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        सचे (is_float(t))
            gen_opif(op);
        अञ्ञथा
            gen_opic(op);
        सचे (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } अञ्ञथा {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    सचे (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#सचे defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#अञ्ञथा
/* generic itof for unsigned long long case */
स्थिर शून्य gen_cvt_itof1(पूर्णाङ्क t)
{
    सचे ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        सचे (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#सचे LDOUBLE_SIZE != 8
        अञ्ञथा सचे (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        अञ्ञथा
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } अञ्ञथा {
        gen_cvt_itof(t);
    }
}
#endif

#सचे defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#अञ्ञथा
/* generic ftoi for unsigned long long case */
स्थिर शून्य gen_cvt_ftoi1(पूर्णाङ्क t)
{
    पूर्णाङ्क st;
    सचे (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        सचे (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#सचे LDOUBLE_SIZE != 8
        अञ्ञथा सचे (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        अञ्ञथा
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } अञ्ञथा {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
स्थिर शून्य force_charshort_cast(शून्य)
{
    पूर्णाङ्क sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    पूर्णाङ्क dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

स्थिर शून्य gen_cast_s(पूर्णाङ्क t)
{
    CType type;
    type.t = t;
    type.ref = रिक्त;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
स्थिर शून्य gen_cast(CType *type)
{
    पूर्णाङ्क sbt, dbt, sf, df, c;
    पूर्णाङ्क dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    सचे (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    सचे (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    सचे (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    सचे (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    सचे (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        सचे (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            गच्छ done;
        }
        सचे (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        सचे (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            सचे (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            अञ्ञथा सचे (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            सचे (df) {
                सचे (sbt_bt == VT_LLONG) {
                    सचे ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    अञ्ञथा
                        vtop->c.ld = -(long द्विगुण)-vtop->c.i;
                } अञ्ञथा सचे(!sf) {
                    सचे ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    अञ्ञथा
                        vtop->c.ld = -(long द्विगुण)-(uint32_t)vtop->c.i;
                }

                सचे (dbt == VT_FLOAT)
                    vtop->c.f = (भिन्न)vtop->c.ld;
                अञ्ञथा सचे (dbt == VT_DOUBLE)
                    vtop->c.d = (द्विगुण)vtop->c.ld;
            } अञ्ञथा सचे (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } अञ्ञथा {
                सचे(sf) {
                    सचे (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    अञ्ञथा
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                अञ्ञथा सचे (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                अञ्ञथा सचे (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                अञ्ञथा
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                सचे (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                अञ्ञथा सचे (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                अञ्ञथा {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    सचे (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            गच्छ done;

        } अञ्ञथा सचे (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            गच्छ done;
        }

        /* cannot generate code for global or static initializers */
        सचे (nocode_wanted & DATA_ONLY_WANTED) {
            सचे (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            गच्छ done;
        }

        /* non constant case: generate code */
        सचे (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            गच्छ done;
        }

        सचे (sf || df) {
            सचे (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } अञ्ञथा सचे (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } अञ्ञथा {
                /* convert fp to int */
                sbt = dbt;
                सचे (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                गच्छ again; /* may need char/short cast */
            }
            गच्छ done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        सचे (ds == 0 || ss == 0)
            गच्छ error;

        /* same size and no sign conversion needed */
        सचे (ds == ss && ds >= 4)
            गच्छ done;
        सचे (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            सचे (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        सचे (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            सचे (ds <= ss)
                गच्छ done;
            /* ss <= 4 here */
            सचे (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                गच्छ done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#सचे PTR_SIZE == 4
        सचे (ds == 8) {
            /* generate high word */
            सचे (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } अञ्ञथा {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } अञ्ञथा सचे (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#नोचेद्यदि PTR_SIZE == 8
        सचे (ds == 8) {
            /* need to convert from 32bit to 64bit */
            सचे (sbt & VT_UNSIGNED) {
#सचे defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#अञ्ञथा
                गच्छ done;
#endif
            } अञ्ञथा {
                gen_cvt_sxtw();
                गच्छ done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } अञ्ञथा सचे (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#सचे !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } अञ्ञथा {
            ss = 4;
        }
#endif

        सचे (ds >= ss)
            गच्छ done;
#सचे defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    सचे (ss == 4) {
        gen_cvt_csti(dbt);
        गच्छ done;
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
ST_FUNC पूर्णाङ्क type_size(CType *type, पूर्णाङ्क *a)
{
    Sym *s;
    पूर्णाङ्क bt;

    bt = type->t & VT_BTYPE;
    सचे (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        पटिनिवत्त s->c;
    } अञ्ञथा सचे (bt == VT_PTR) {
        सचे (type->t & VT_ARRAY) {
            पूर्णाङ्क ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            सचे (s->c < 0)
                पटिनिवत्त s->c;
            पटिनिवत्त ts * s->c;
        } अञ्ञथा {
            *a = PTR_SIZE;
            पटिनिवत्त PTR_SIZE;
        }
    } अञ्ञथा सचे (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        पटिनिवत्त -1; /* incomplete enum */
    } अञ्ञथा सचे (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        पटिनिवत्त LDOUBLE_SIZE;
    } अञ्ञथा सचे (bt == VT_DOUBLE || bt == VT_LLONG) {
#सचे (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#अञ्ञथा
        *a = 8;
#endif
        पटिनिवत्त 8;
    } अञ्ञथा सचे (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        पटिनिवत्त 4;
    } अञ्ञथा सचे (bt == VT_SHORT) {
        *a = 2;
        पटिनिवत्त 2;
    } अञ्ञथा सचे (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        पटिनिवत्त 16;
    } अञ्ञथा {
        /* char, void, function, _Bool */
        *a = 1;
        पटिनिवत्त 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
स्थिर शून्य vpush_type_size(CType *type, पूर्णाङ्क *a)
{
    सचे (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } अञ्ञथा {
        पूर्णाङ्क size = type_size(type, a);
        सचे (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
स्थिर अन्तःस्थ CType *pointed_type(CType *type)
{
    पटिनिवत्त &type->ref->type;
}

स्थिर शून्य check_restrict_type(CType *type)
{
    याव ((type->t & VT_BTYPE) == VT_PTR) {
        सचे ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    सचे (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
स्थिर पूर्णाङ्क type_qualifiers(CType *type)
{
    याव (type->t & VT_ARRAY)
        type = pointed_type(type);
    पटिनिवत्त type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC शून्य mk_pointer(CType *type)
{
    Sym *s;
    s = sym_प्रक्षिप(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
स्थिर पूर्णाङ्क is_compatible_types(CType *type1, CType *type2)
{
    पटिनिवत्त compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
स्थिर पूर्णाङ्क is_compatible_unqualified_types(CType *type1, CType *type2)
{
    पटिनिवत्त compare_types(type1,type2,1);
}

स्थिर शून्य cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
स्थिर शून्य verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    पूर्णाङ्क dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    सचे (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    विकल्प(dbt) {
    पक्ष VT_VOID:
        सचे (sbt != dbt)
            tcc_error("assignment to void expression");
        भङ्ग;
    पक्ष VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        सचे (is_null_pointer(vtop))
            भङ्ग;
        /* accept implicit pointer to integer cast with warning */
        सचे (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            भङ्ग;
        }
        type1 = pointed_type(dt);
        सचे (sbt == VT_PTR)
            type2 = pointed_type(st);
        अञ्ञथा सचे (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        अञ्ञथा
            गच्छ error;
        सचे (is_compatible_types(type1, type2))
            भङ्ग;
        अत्थाय (qualwarn = lvl = 0;; ++lvl) {
            सचे ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            सचे (dbt != VT_PTR || sbt != VT_PTR)
                भङ्ग;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        सचे (!is_compatible_unqualified_types(type1, type2)) {
            सचे ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } अञ्ञथा सचे (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } अञ्ञथा {
                tcc_warning("assignment from incompatible pointer type");
                भङ्ग;
            }
        }
        सचे (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        भङ्ग;
    पक्ष VT_BYTE:
    पक्ष VT_SHORT:
    पक्ष VT_INT:
    पक्ष VT_LLONG:
        सचे (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } अञ्ञथा सचे (sbt == VT_STRUCT) {
            गच्छ case_VT_STRUCT;
        }
        /* XXX: more tests */
        भङ्ग;
    पक्ष VT_STRUCT:
    case_VT_STRUCT:
        सचे (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        भङ्ग;
    }
}

स्थिर शून्य gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC शून्य vstore(शून्य)
{
    पूर्णाङ्क sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    सचे (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        सचे (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        सचे (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        सचे (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } अञ्ञथा
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            सचे(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            अञ्ञथा सचे(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            अञ्ञथा
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } अञ्ञथा सचे (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        सचे (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        सचे (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        सचे (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } अञ्ञथा {
            unsigned long long mask = (1ULL << bit_size) - 1;
            सचे (dbt != VT_BOOL) {
                /* mask source */
                सचे (dbt == VT_LLONG)
                    vpushll(mask);
                अञ्ञथा
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
            सचे (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            अञ्ञथा
                vpushi(~((unsigned)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } अञ्ञथा सचे (dbt == VT_VOID) {
        --vtop;
    } अञ्ञथा {
            /* optimize char/short casts */
            delayed_cast = 0;
            सचे ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                सचे ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } अञ्ञथा {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            सचे (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            सचे (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            सचे ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = रिक्त;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            सचे (USING_TWO_शब्दाः(dbt)) {
                पूर्णाङ्क load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } अञ्ञथा {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC शून्य inc(पूर्णाङ्क post, पूर्णाङ्क c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    सचे (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    सचे (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ध्रुव वर्ण *सन्देशः)
{
    /* read the string */
    सचे (tok != TOK_STR)
        expect(सन्देशः);
    cstr_reset(&initstr);
    याव (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    पटिनिवत्त &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC पूर्णाङ्क exact_log2p1(पूर्णाङ्क i)
{
  पूर्णाङ्क ret;
  सचे (!i)
    पटिनिवत्त 0;
  अत्थाय (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  सचे (i >= 1 << 4)
    ret += 4, i >>= 4;
  सचे (i >= 1 << 2)
    ret += 2, i >>= 2;
  सचे (i >= 1 << 1)
    ret++;
  पटिनिवत्त ret;
}

/* Parse __attribute__((...)) GNUC extension. */
स्थिर शून्य parse_attribute(AttributeDef *ad)
{
    पूर्णाङ्क t, n;
    वर्ण *astr;
    AttributeDef ad_tmp;
    
redo:
    सचे (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        पटिनिवत्त;
    सचे (रिक्त == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    याव (tok != ')') {
        सचे (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        विकल्प(t) {
	पक्ष TOK_CLEANUP1:
	पक्ष TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    सचे (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } अञ्ञथा सचे ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    भङ्ग;
	}
        पक्ष TOK_CONSTRUCTOR1:
        पक्ष TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            भङ्ग;
        पक्ष TOK_DESTRUCTOR1:
        पक्ष TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            भङ्ग;
        पक्ष TOK_ALWAYS_INLINE1:
        पक्ष TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            भङ्ग;
        पक्ष TOK_SECTION1:
        पक्ष TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            भङ्ग;
        पक्ष TOK_ALIAS1:
        पक्ष TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            भङ्ग;
	पक्ष TOK_VISIBILITY1:
	पक्ष TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    सचे (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    अञ्ञथा सचे (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    अञ्ञथा सचे (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    अञ्ञथा सचे (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    अञ्ञथा
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            भङ्ग;
        पक्ष TOK_ALIGNED1:
        पक्ष TOK_ALIGNED2:
            सचे (tok == '(') {
                next();
                n = व्यञ्जकम्_const();
                सचे (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } अञ्ञथा {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    सचे (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            भङ्ग;
        पक्ष TOK_PACKED1:
        पक्ष TOK_PACKED2:
            ad->a.packed = 1;
            भङ्ग;
        पक्ष TOK_WEAK1:
        पक्ष TOK_WEAK2:
            ad->a.weak = 1;
            भङ्ग;
        पक्ष TOK_NODEBUG1:
        पक्ष TOK_NODEBUG2:
            ad->a.nodebug = 1;
            भङ्ग;
        पक्ष TOK_USED1:
        पक्ष TOK_USED2:
        पक्ष TOK_UNUSED1:
        पक्ष TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            भङ्ग;
        पक्ष TOK_CONST1:
        पक्ष TOK_CONST2:
        पक्ष TOK_CONST3:
        पक्ष TOK_PURE1:
        पक्ष TOK_PURE2:
	    /* ignored */
            भङ्ग;
        पक्ष TOK_NOINLINE:
	    /* ignored */
	    भङ्ग;
        पक्ष TOK_FORMAT1:
        पक्ष TOK_FORMAT2:
	    /* ignored */
            गच्छ skip_param;
        पक्ष TOK_NORETURN1:
        पक्ष TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            भङ्ग;
        पक्ष TOK_CDECL1:
        पक्ष TOK_CDECL2:
        पक्ष TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            भङ्ग;
        पक्ष TOK_STDCALL1:
        पक्ष TOK_STDCALL2:
        पक्ष TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            भङ्ग;
#ifdef TCC_TARGET_I386
        पक्ष TOK_REGPARM1:
        पक्ष TOK_REGPARM2:
            skip('(');
            n = व्यञ्जकम्_const();
            सचे (n > 3) 
                n = 3;
            अञ्ञथा सचे (n < 0)
                n = 0;
            सचे (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            भङ्ग;
        पक्ष TOK_FASTCALL1:
        पक्ष TOK_FASTCALL2:
        पक्ष TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            भङ्ग;
        पक्ष TOK_THISCALL1:
        पक्ष TOK_THISCALL2:
        पक्ष TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            भङ्ग;
#endif
        पक्ष TOK_MODE:
            skip('(');
            विकल्प(tok) {
                पक्ष TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    भङ्ग;
                पक्ष TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    भङ्ग;
                पक्ष TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    भङ्ग;
                पक्ष TOK_MODE_SI:
                पक्ष TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    भङ्ग;
                स्वभाव:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, रिक्त));
                    भङ्ग;
            }
            next();
            skip(')');
            भङ्ग;
        पक्ष TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            भङ्ग;
        पक्ष TOK_NODECORATE:
            ad->a.nodecorate = 1;
            भङ्ग;
        पक्ष TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            भङ्ग;
        स्वभाव:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, रिक्त));
            /* skip parameters */
skip_param:
            सचे (tok == '(') {
                पूर्णाङ्क parenthesis = 0;
                करोहि {
                    सचे (tok == '(') 
                        parenthesis++;
                    अञ्ञथा सचे (tok == ')') 
                        parenthesis--;
                    next();
                } याव (parenthesis && tok != -1);
            }
            भङ्ग;
        }
        सचे (tok != ',')
            भङ्ग;
        next();
    }
    skip(')');
    skip(')');
    गच्छ redo;
}

स्थिर Sym * find_field (CType *type, पूर्णाङ्क v, पूर्णाङ्क *cumofs)
{
    Sym *s = type->ref;
    पूर्णाङ्क v1 = v | SYM_FIELD;
    सचे (!(v & SYM_FIELD)) { /* top-level call */
        सचे ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        सचे (v < TOK_UIDENT)
            expect("field name");
        सचे (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    याव ((s = s->next) != रिक्त) {
        सचे (s->v == v1) {
            *cumofs = s->c;
            पटिनिवत्त s;
        }
        सचे ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            सचे (ret) {
                *cumofs += s->c;
                पटिनिवत्त ret;
            }
        }
    }
    सचे (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, रिक्त));
    पटिनिवत्त s;
}

स्थिर शून्य check_fields (CType *type, पूर्णाङ्क check)
{
    Sym *s = type->ref;

    याव ((s = s->next) != रिक्त) {
        पूर्णाङ्क v = s->v & ~SYM_FIELD;
        सचे (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            सचे (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, रिक्त));
            ts->tok ^= SYM_FIELD;
        } अञ्ञथा सचे ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

स्थिर शून्य struct_layout(CType *type, AttributeDef *ad)
{
    पूर्णाङ्क size, align, maxalign, offset, c, bit_pos, bit_size;
    पूर्णाङ्क packed, a, bt, prevbt, prev_bit_size;
    पूर्णाङ्क pcc = !tcc_state->ms_bitfields;
    पूर्णाङ्क pragma_pack = *tcc_state->pack_राशिः_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    अत्थाय (f = type->ref->next; f; f = f->next) {
        सचे (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        अञ्ञथा
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        सचे (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } अञ्ञथा {
            /* in pcc mode, attribute packed overrides if set. */
            सचे (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            सचे (pragma_pack) {
                packed = 1;
                सचे (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                सचे (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        सचे (a)
            align = a;

        सचे (type->ref->type.t == VT_UNION) {
	    सचे (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    सचे (size > c)
	        c = size;

	} अञ्ञथा सचे (bit_size < 0) {
            सचे (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    सचे (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} अञ्ञथा {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            सचे (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                सचे (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } अञ्ञथा सचे (f->a.aligned) {
                    गच्छ new_field;
                } अञ्ञथा सचे (!packed) {
                    पूर्णाङ्क a8 = align * 8;
	            पूर्णाङ्क ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    सचे (ofs > size / align)
                        गच्छ new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                सचे (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                याव (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		सचे (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } अञ्ञथा {
		bt = f->type.t & VT_BTYPE;
		सचे ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    सचे (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		सचे (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	सचे (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	printf("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, रिक्त), offset, size, align);
	सचे (f->type.t & VT_BITFIELD) {
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

    सचे (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    सचे (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    सचे (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        सचे (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    printf("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#endif

    /* check whether we can access bitfields by their type */
    अत्थाय (f = type->ref->next; f; f = f->next) {
        पूर्णाङ्क s, px, cx, c0;
        CType t;

        सचे (0 == (f->type.t & VT_BITFIELD))
            अनुवर्त;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        सचे (bit_size == 0)
            अनुवर्त;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        सचे (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            अनुवर्त;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        अत्थाय (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            सचे (c0 == cx)
                भङ्ग;
            s = (px + bit_size + 7) >> 3;
            सचे (s > 4) {
                t.t = VT_LLONG;
            } अञ्ञथा सचे (s > 2) {
                t.t = VT_INT;
            } अञ्ञथा सचे (s > 1) {
                t.t = VT_SHORT;
            } अञ्ञथा {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        सचे (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            सचे (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            printf("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, रिक्त),
                cx, s, align, px, bit_size);
#endif
        } अञ्ञथा {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            printf("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, रिक्त));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
स्थिर पूर्णाङ्क in_range(long long n, पूर्णाङ्क t)
{
    unsigned long long m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    सचे (t & VT_UNSIGNED)
        पटिनिवत्त n <= (m << 1) + 1;
    पटिनिवत्त n >= -(long long)m - 1 && n <= (long long)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
स्थिर शून्य struct_decl(CType *type, पूर्णाङ्क u)
{
    पूर्णाङ्क v, c, size, align, flexible;
    पूर्णाङ्क bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, परिमाण ad);
    next();
    parse_attribute(&ad);

    v = 0;
    सचे (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    सचे (u == VT_ENUM) {
        ut = VT_INT;
        सचे (tok == ':') { /* C2x enum : <type> ... */
            next();
            सचे (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    सचे (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        सचे (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            सचे (u == s->type.t)
                गच्छ do_decl;
            सचे (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                गच्छ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, रिक्त));
        }
    } अञ्ञथा {
        सचे (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = रिक्त;
    /* we put an undefined size for struct/union */
    s = sym_प्रक्षिप(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    सचे (tok == '{') {
        next();
        सचे (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        सचे (u == VT_ENUM) {
            long long ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            सचे (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            अत्थाय(;;) {
                v = tok;
                सचे (v < TOK_UIDENT)
                    expect("identifier");
                next();
                सचे (tok == '=') {
                    next();
		    ll = व्यञ्जकम्_const64();
                }
                सचे (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, रिक्त));
                ss = sym_प्रक्षिप(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                सचे (ll < nl)
                    nl = ll;
                सचे (ll > pl)
                    pl = ll;
                सचे (tok != ',')
                    भङ्ग;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                सचे (tok == '}')
                    भङ्ग;
            }
            skip('}');

            सचे (bt) {
                t.t = bt;
                s->c = 2;
                गच्छ enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            सचे (nl >= 0) {
                सचे (pl != (unsigned)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } अञ्ञथा सचे (pl != (पूर्णाङ्क)pl || nl != (पूर्णाङ्क)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            अत्थाय (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                सचे (ll == (पूर्णाङ्क)ll) /* default is int if it fits */
                    अनुवर्त;
                सचे (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    सचे (ll == (unsigned)ll)
                        अनुवर्त;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } अञ्ञथा {
            c = 0;
            flexible = 0;
            याव (tok != '}') {
                सचे (!parse_btype(&btype, &ad1, 0)) {
                    सचे (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        अनुवर्त;
                    }
		    skip(';');
		    अनुवर्त;
		}
                याव (1) {
		    सचे (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, रिक्त));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    सचे (tok != ':') {
			सचे (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        सचे (v == 0) {
                    	    सचे ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    अञ्ञथा {
				पूर्णाङ्क v = btype.ref->v;
				सचे ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    सचे (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        सचे (type_size(&type1, &align) < 0) {
			    सचे ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    अञ्ञथा
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, रिक्त));
                        }
                        सचे ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, रिक्त));
                    }
                    सचे (tok == ':') {
                        next();
                        bit_size = व्यञ्जकम्_const();
                        /* XXX: handle v = 0 case for messages */
                        सचे (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, रिक्त));
                        सचे (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, रिक्त));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    सचे (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        सचे (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        सचे (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, रिक्त));
                        } अञ्ञथा सचे (bit_size == bsize
				    && !*tcc_state->pack_राशिः_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } अञ्ञथा सचे (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } अञ्ञथा {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((unsigned)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    सचे (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    सचे (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    सचे (v) {
                        ss = sym_प्रक्षिप(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    सचे (tok == ';' || tok == TOK_EOF)
                        भङ्ग;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            सचे (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        सचे (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

स्थिर शून्य sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
स्थिर शून्य parse_btype_qualify(CType *type, पूर्णाङ्क qualifiers)
{
    याव (type->t & VT_ARRAY) {
        type->ref = sym_प्रक्षिप(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    सचे (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
स्थिर पूर्णाङ्क parse_btype(CType *type, AttributeDef *ad, पूर्णाङ्क ignore_label)
{
    पूर्णाङ्क t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, परिमाण(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = रिक्त;

    याव(1) {
        विकल्प(tok) {
        पक्ष TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            अनुवर्त;

            /* basic types */
        पक्ष TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            सचे (u == VT_SHORT || u == VT_LONG) {
                सचे (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } अञ्ञथा {
                सचे (bt != -1 || (st != -1 && u != VT_INT))
                    गच्छ tmbt;
                सचे ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    गच्छ tmbt;
                bt = u;
            }
            सचे (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            भङ्ग;
        पक्ष TOK_VOID:
            u = VT_VOID;
            गच्छ basic_type;
        पक्ष TOK_SHORT:
            u = VT_SHORT;
            गच्छ basic_type;
        पक्ष TOK_INT:
            u = VT_INT;
            गच्छ basic_type;
        पक्ष TOK_ALIGNAS:
            { पूर्णाङ्क n;
              AttributeDef ad1;
              next();
              skip('(');
              memset(&ad1, 0, परिमाण(AttributeDef));
              सचे (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  सचे (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  अञ्ञथा
                    type_size(&type1, &n);
              } अञ्ञथा {
                  n = व्यञ्जकम्_const();
                  सचे (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            अनुवर्त;
        पक्ष TOK_LONG:
            सचे ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अञ्ञथा सचे ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } अञ्ञथा {
                u = VT_LONG;
                गच्छ basic_type;
            }
            next();
            भङ्ग;
        पक्ष TOK_BOOL:
            u = VT_BOOL;
            गच्छ basic_type;
        पक्ष TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        पक्ष TOK_FLOAT:
            u = VT_FLOAT;
            गच्छ basic_type;
        पक्ष TOK_DOUBLE:
            सचे ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अञ्ञथा {
                u = VT_DOUBLE;
                गच्छ basic_type;
            }
            next();
            भङ्ग;
        पक्ष TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            गच्छ basic_type1;
        पक्ष TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            गच्छ basic_type2;
        पक्ष TOK_UNION:
            struct_decl(&type1, VT_UNION);
            गच्छ basic_type2;

            /* type modifiers */
        पक्ष TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            सचे (tok == '(') {
                parse_व्यञ्जकम्_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                सचे (type1.ref)
                    sym_to_attr(ad, type1.ref);
                गच्छ basic_type2;
            }
            भङ्ग;
        पक्ष TOK_CONST1:
        पक्ष TOK_CONST2:
        पक्ष TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            भङ्ग;
        पक्ष TOK_VOLATILE1:
        पक्ष TOK_VOLATILE2:
        पक्ष TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            भङ्ग;
        पक्ष TOK_SIGNED1:
        पक्ष TOK_SIGNED2:
        पक्ष TOK_SIGNED3:
            सचे ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            भङ्ग;
        पक्ष TOK_RESTRICT1:
        पक्ष TOK_RESTRICT2:
        पक्ष TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            भङ्ग;
        पक्ष TOK_REGISTER:
        पक्ष TOK_AUTO:
            next();
            भङ्ग;
        पक्ष TOK_UNSIGNED:
            सचे ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            भङ्ग;

            /* storage */
        पक्ष TOK_EXTERN:
            g = VT_EXTERN;
            गच्छ storage;
        पक्ष TOK_STATIC:
            g = VT_STATIC;
            गच्छ storage;
        पक्ष TOK_TYPEDEF:
            g = VT_TYPEDEF;
            गच्छ storage;
       storage:
            सचे (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            भङ्ग;
        पक्ष TOK_INLINE1:
        पक्ष TOK_INLINE2:
        पक्ष TOK_INLINE3:
            t |= VT_INLINE;
            next();
            भङ्ग;
        पक्ष TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            भङ्ग;
            /* GNUC attribute */
        पक्ष TOK_ATTRIBUTE1:
        पक्ष TOK_ATTRIBUTE2:
            parse_attribute(ad);
            सचे (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            अनुवर्त;
            /* GNUC typeof */
        पक्ष TOK_TYPEOF1:
        पक्ष TOK_TYPEOF2:
        पक्ष TOK_TYPEOF3:
            next();
            parse_व्यञ्जकम्_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            सचे (type1.ref) {
                sym_to_attr(ad, type1.ref);
                सचे (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            गच्छ basic_type2;
        पक्ष TOK_THREAD_LOCAL:
        पक्ष TOK___thread:
            सचे (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            भङ्ग;
        स्वभाव:
            सचे (typespec_found)
                गच्छ the_end;
            s = sym_find(tok);
            सचे (!s || !(s->type.t & VT_TYPEDEF))
                गच्छ the_end;

            n = tok, next();
            सचे (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                गच्छ the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            सचे (t)
                parse_btype_qualify(type, t);
            t = type->t;
            सचे (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            भङ्ग;
        }
        type_found = 1;
    }
the_end:
    सचे (tcc_state->char_is_unsigned) {
        सचे ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    सचे (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    सचे (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    पटिनिवत्त type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
स्थिर अन्तःस्थ शून्य convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    सचे ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
स्थिर अन्तःस्थ शून्य convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(शून्य)
{
    skip('(');
    पटिनिवत्त parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
स्थिर पूर्णाङ्क asm_label_instr(शून्य)
{
    पूर्णाङ्क v;
    वर्ण *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    printf("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    पटिनिवत्त v;
}

स्थिर पूर्णाङ्क post_type(CType *type, AttributeDef *ad, पूर्णाङ्क storage, पूर्णाङ्क td)
{
    पूर्णाङ्क n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = रिक्त;
    पूर्णाङ्क *vla_array_str = रिक्त;

    सचे (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	सचे (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  पटिनिवत्त 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_राशिः ? &local_राशिः : &global_राशिः;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	सचे (tok == ')')
	  l = 0;
	अञ्ञथा सचे (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	अञ्ञथा सचे (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_निष्कासय(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    पटिनिवत्त 0;
	} अञ्ञथा
	  l = FUNC_OLD;

        first = रिक्त;
        plast = &first;
        arg_size = 0;
        सचे (l) {
            अत्थाय(;;) {
                /* read param name and compute offset */
                सचे (l != FUNC_OLD) {
                    सचे ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        भङ्ग;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    सचे ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    सचे (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } अञ्ञथा {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = रिक्त;
                    next();
                }
                सचे (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_प्रक्षिप(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                सचे (tok == ')')
                    भङ्ग;
                skip(',');
                सचे (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    भङ्ग;
                }
		सचे (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } अञ्ञथा
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        सचे (tok == '[') {
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
        sym_निष्कासय(ps, sr, 1);
        --local_scope;

    } अञ्ञथा सचे (tok == '[') {
	पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
        पूर्णाङ्क array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        सचे (td & TYPE_PARAM) याव (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    विकल्प (tok) {
	    पक्ष TOK_CONST1: पक्ष TOK_CONST2: पक्ष TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		अनुवर्त;
	    पक्ष TOK_VOLATILE1: पक्ष TOK_VOLATILE2: पक्ष TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		अनुवर्त;
	    पक्ष TOK_RESTRICT1: पक्ष TOK_RESTRICT2: पक्ष TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		अनुवर्त;
	    पक्ष TOK_STATIC:
	    पक्ष '*':
		next();
		अनुवर्त;
	    स्वभाव:
		भङ्ग;
	    }
            सचे (tok != ']') {
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
		गच्छ check;
            }
            भङ्ग;

	} अञ्ञथा सचे (tok != ']') {
            सचे (!local_राशिः || (storage & VT_STATIC))
                vpushi(व्यञ्जकम्_const());
            अञ्ञथा {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            सचे ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                सचे (n < 0)
                    tcc_error("invalid array size");
            } अञ्ञथा {
                सचे (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        सचे ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        सचे ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        सचे (t1 & VT_VLA) {
            सचे (n < 0) {
		सचे  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    अञ्ञथा {
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
        सचे (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_प्रक्षिप(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        सचे (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    सचे ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    अञ्ञथा
	        tok_str_free_str(vla_array_str);
	}
    }
    पटिनिवत्त 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
स्थिर CType *type_decl(CType *type, AttributeDef *ad, पूर्णाङ्क *v, पूर्णाङ्क td)
{
    CType *post, *ret;
    पूर्णाङ्क qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    याव (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        विकल्प(tok) {
        पक्ष TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            गच्छ redo;
        पक्ष TOK_CONST1:
        पक्ष TOK_CONST2:
        पक्ष TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            गच्छ redo;
        पक्ष TOK_VOLATILE1:
        पक्ष TOK_VOLATILE2:
        पक्ष TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            गच्छ redo;
        पक्ष TOK_RESTRICT1:
        पक्ष TOK_RESTRICT2:
        पक्ष TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            गच्छ redo;
	/* XXX: clarify attribute handling */
	पक्ष TOK_ATTRIBUTE1:
	पक्ष TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    भङ्ग;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	सचे (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    सचे (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	सचे (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} अञ्ञथा
	  गच्छ abstract;
    } अञ्ञथा सचे (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } अञ्ञथा {
  abstract:
	सचे (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    पटिनिवत्त ret;
}

/* indirection with full error checking and bound check */
ST_FUNC शून्य indir(शून्य)
{
    सचे ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        सचे ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            पटिनिवत्त;
        expect("pointer");
    }
    सचे (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    सचे (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        सचे (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
स्थिर शून्य gfunc_param_typed(Sym *func, Sym *arg)
{
    पूर्णाङ्क func_type;
    CType type;

    func_type = func->f.func_type;
    सचे (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == रिक्त)) {
        /* default casting : only need to convert float to double */
        सचे ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } अञ्ञथा सचे (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } अञ्ञथा सचे (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } अञ्ञथा सचे (arg == रिक्त) {
        tcc_error("too many arguments to function");
    } अञ्ञथा {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
स्थिर शून्य व्यञ्जकम्_type(CType *type, शून्य (*व्यञ्जकम्_fn)(शून्य))
{
    nocode_wanted++;
    व्यञ्जकम्_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
स्थिर शून्य parse_व्यञ्जकम्_type(CType *type)
{
    पूर्णाङ्क n;
    AttributeDef ad;

    skip('(');
    सचे (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } अञ्ञथा {
        व्यञ्जकम्_type(type, gexpr);
    }
    skip(')');
}

स्थिर शून्य parse_type(CType *type)
{
    AttributeDef ad;
    पूर्णाङ्क n;

    सचे (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

स्थिर शून्य parse_builtin_params(पूर्णाङ्क nc, ध्रुव वर्ण *args)
{
    वर्ण c, sep = '(';
    CType type;
    सचे (nc)
        nocode_wanted++;
    next();
    सचे (*args == 0)
	skip(sep);
    याव ((c = *args++)) {
	skip(sep);
	sep = ',';
        सचे (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    अनुवर्त;
        }
        व्यञ्जकम्_eq();
        type.ref = रिक्त;
        type.t = 0;
	विकल्प (c) {
	    पक्ष 'e':
		अनुवर्त;
	    पक्ष 'V':
                type.t = VT_CONSTANT;
	    पक्ष 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                भङ्ग;
	    पक्ष 'S':
                type.t = VT_CONSTANT;
	    पक्ष 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                भङ्ग;
	    पक्ष 'i':
                type.t = VT_INT;
                भङ्ग;
	    पक्ष 'l':
                type.t = VT_SIZE_T;
                भङ्ग;
	    स्वभाव:
                भङ्ग;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    सचे (nc)
        nocode_wanted--;
}

स्थिर शून्य parse_atomic(पूर्णाङ्क atok)
{
    पूर्णाङ्क size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    वर्ण buf[40];
    स्थिर ध्रुव वर्ण *ध्रुव templates[] = {
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
    ध्रुव वर्ण *template = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = रिक्त;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    अत्थाय (arg = 0;;) {
        व्यञ्जकम्_eq();
        विकल्प (template[arg]) {
        पक्ष 'a':
        पक्ष 'A':
            atom_ptr = &vtop->type;
            सचे ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            सचे (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            भङ्ग;

        पक्ष 'p':
            सचे ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            भङ्ग;
        पक्ष 'v':
            gen_assign_cast(atom);
            भङ्ग;
        पक्ष 'l':
            indir();
            gen_assign_cast(atom);
            भङ्ग;
        पक्ष 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            भङ्ग;
        पक्ष 'm':
            gen_assign_cast(&int_type);
            भङ्ग;
        पक्ष 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            भङ्ग;
        }
        सचे ('.' == template[++arg])
            भङ्ग;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    विकल्प (template[arg + 1]) {
    पक्ष 'b':
        ct.t = VT_BOOL;
        भङ्ग;
    पक्ष 'v':
        ct = *atom;
        भङ्ग;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    सचे (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अञ्ञथा
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    सचे (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC शून्य unary(शून्य)
{
    पूर्णाङ्क n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    सचे (debug_modes)
        tcc_debug_पङ्क्तिः(tcc_state), tcc_tcov_check_पङ्क्तिः (tcc_state, 1);

    type.ref = रिक्त;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    विकल्प(tok) {
    पक्ष TOK_EXTENSION:
        next();
        गच्छ tok_next;
    पक्ष TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        गच्छ प्रक्षिप_tokc;
#endif
    पक्ष TOK_CINT:
    पक्ष TOK_CCHAR: 
	t = VT_INT;
 प्रक्षिप_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        भङ्ग;
    पक्ष TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CLLONG:
        t = VT_LLONG;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CFLOAT:
        t = VT_FLOAT;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CDOUBLE:
        t = VT_DOUBLE;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#अञ्ञथा
        t = VT_LDOUBLE;
#endif
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK___FUNCTION__:
        सचे (!gnu_ext)
            गच्छ tok_identifier;
        /* fall thru */
    पक्ष TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        गच्छ case_TOK_STR;
    पक्ष TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#अञ्ञथा
        t = VT_INT;
#endif
        गच्छ str_init;
    पक्ष TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        सचे (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, परिमाण(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        भङ्ग;
    पक्ष TOK_SOTYPE:
    पक्ष '(':
        t = tok;
        next();
        /* cast ? */
        सचे (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            सचे (tok == '{') {
                    /* data is allocated locally by default */
                सचे (global_व्यञ्जकम्)
                    r = VT_CONST;
                अञ्ञथा
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                सचे (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, परिमाण(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } अञ्ञथा सचे (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                पटिनिवत्त;
            } अञ्ञथा {
                unary();
                gen_cast(&type);
            }
        } अञ्ञथा सचे (tok == '{') {
	    पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
            सचे (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            सचे (0 == local_scope)
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
            block(STMT_व्यञ्जकम्);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            सचे (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } अञ्ञथा {
            gexpr();
            skip(')');
        }
        भङ्ग;
    पक्ष '*':
        next();
        unary();
        indir();
        भङ्ग;
    पक्ष '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        सचे ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        सचे (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        भङ्ग;
    पक्ष '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        भङ्ग;
    पक्ष '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        भङ्ग;
    पक्ष '+':
        next();
        unary();
        सचे ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	सचे (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        भङ्ग;
    पक्ष TOK_SIZEOF:
    पक्ष TOK_ALIGNOF1:
    पक्ष TOK_ALIGNOF2:
    पक्ष TOK_ALIGNOF3:
        t = tok;
        next();
        सचे (tok == '(')
            tok = TOK_SOTYPE;
        व्यञ्जकम्_type(&type, unary);
        सचे (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } अञ्ञथा {
            type_size(&type, &align);
            s = रिक्त;
            सचे (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            सचे (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        भङ्ग;

    पक्ष TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        भङ्ग;
    पक्ष TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        भङ्ग;
    पक्ष TOK_builtin_choose_व्यञ्जकम्:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = व्यञ्जकम्_const64();
	    skip(',');
	    सचे (!c) {
		nocode_wanted++;
	    }
	    व्यञ्जकम्_eq();
	    सचे (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    सचे (c) {
		nocode_wanted++;
	    }
	    व्यञ्जकम्_eq();
	    सचे (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        भङ्ग;
    पक्ष TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	सचे ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        भङ्ग;
    पक्ष TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        भङ्ग;
    पक्ष TOK_builtin_frame_address:
    पक्ष TOK_builtin_return_address:
        {
            पूर्णाङ्क tok1 = tok;
            पूर्णाङ्क level;
            next();
            skip('(');
            level = व्यञ्जकम्_const();
            सचे (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            याव (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            सचे (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#नोचेद्यदि defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#अञ्ञथा
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        भङ्ग;
#ifdef TCC_TARGET_RISCV64
    पक्ष TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        सचे (r == VT_LLOCAL)
            r = VT_LOCAL;
        सचे (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        भङ्ग;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    पक्ष TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        सचे (r == VT_LLOCAL)
            r = VT_LOCAL;
        सचे (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        भङ्ग;
#अञ्ञथा
    पक्ष TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	भङ्ग;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    पक्ष TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        भङ्ग;
    }
    पक्ष TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        भङ्ग;
    }
#endif
#ifdef TCC_TARGET_ARM64
    पक्ष TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        भङ्ग;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    पक्ष TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        भङ्ग;
    }
#endif

    /* atomic operations */
    पक्ष TOK___atomic_store:
    पक्ष TOK___atomic_load:
    पक्ष TOK___atomic_exchange:
    पक्ष TOK___atomic_compare_exchange:
    पक्ष TOK___atomic_fetch_add:
    पक्ष TOK___atomic_fetch_sub:
    पक्ष TOK___atomic_fetch_or:
    पक्ष TOK___atomic_fetch_xor:
    पक्ष TOK___atomic_fetch_and:
    पक्ष TOK___atomic_fetch_nand:
    पक्ष TOK___atomic_add_fetch:
    पक्ष TOK___atomic_sub_fetch:
    पक्ष TOK___atomic_or_fetch:
    पक्ष TOK___atomic_xor_fetch:
    पक्ष TOK___atomic_and_fetch:
    पक्ष TOK___atomic_nand_fetch:
        parse_atomic(tok);
        भङ्ग;

    /* pre operations */
    पक्ष TOK_INC:
    पक्ष TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        भङ्ग;
    पक्ष '-':
        next();
        unary();
	सचे (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} अञ्ञथा {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        भङ्ग;
    पक्ष TOK_LAND:
        सचे (!gnu_ext)
            गच्छ tok_identifier;
        next();
        /* allow to take the address of a label */
        सचे (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        सचे (!s) {
            s = label_प्रक्षिप(&global_label_राशिः, tok, LABEL_FORWARD);
        } अञ्ञथा {
            सचे (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        सचे ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        भङ्ग;

    पक्ष TOK_GENERIC:
    {
	CType controlling_type;
	पूर्णाङ्क has_default = 0;
	पूर्णाङ्क has_match = 0;
	पूर्णाङ्क learn = 0;
	TokenString *str = रिक्त;
	पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	व्यञ्जकम्_type(&controlling_type, व्यञ्जकम्_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        अत्थाय (;;) {
	    learn = 0;
	    skip(',');
	    सचे (tok == TOK_DEFAULT) {
		सचे (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		सचे (!has_match)
		    learn = 1;
		next();
	    } अञ्ञथा {
		पूर्णाङ्क v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		सचे (compare_types(&controlling_type, &type, 0)) {
		    सचे (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    सचे (learn) {
		सचे (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } अञ्ञथा {
		skip_or_save_block(रिक्त);
	    }
	    सचे (tok == ')')
		भङ्ग;
	}
	सचे (!str) {
	    वर्ण buf[60];
	    type_to_str(buf, परिमाण buf, &controlling_type, रिक्त);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	व्यञ्जकम्_eq();
	सचे (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	भङ्ग;
    }
    // special qnan , snan and infinity values
    पक्ष TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        भङ्ग;
    पक्ष TOK___SNAN__:
	n = 0x7f800001;
	गच्छ special_math_val;
    पक्ष TOK___INF__:
	n = 0x7f800000;
	गच्छ special_math_val;

    स्वभाव:
    tok_identifier:
        सचे (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        सचे (!s || IS_ASM_SYM(s)) {
            ध्रुव वर्ण *name = get_tok_str(t, रिक्त);
            सचे (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            सचे (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        सचे ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        सचे (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            सचे (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } अञ्ञथा सचे (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        भङ्ग;
    }
    
    /* post operations */
    याव (1) {
        सचे (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } अञ्ञथा सचे (tok == '.' || tok == TOK_ARROW) {
            पूर्णाङ्क qualifiers, cumofs;
            /* field */ 
            सचे (tok == TOK_ARROW) 
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
            सचे (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            सचे (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                सचे (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } अञ्ञथा सचे (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } अञ्ञथा सचे (tok == '(') {
            SValue ret;
            Sym *sa;
            पूर्णाङ्क nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            सचे ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                सचे ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    सचे ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        गच्छ error_func;
                } अञ्ञथा {
                error_func:
                    expect("function pointer");
                }
            } अञ्ञथा {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            सचे ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                सचे (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                सचे (size < 16)
                    याव (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    सचे (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    सचे (ret_nregs < 0)
                      vtop--;
                    अञ्ञथा
                      nb_args++;
                }
            } अञ्ञथा {
                ret_nregs = 1;
                ret.type = s->type;
            }

            सचे (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = रिक्त;
            सचे (tok != ')') {
                r = tcc_state->reverse_funcargs;
                अत्थाय(;;) {
                    सचे (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } अञ्ञथा {
                        व्यञ्जकम्_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    सचे (sa)
                        sa = sa->next;
                    सचे (tok == ')')
                        भङ्ग;
                    skip(',');
                }
            }
            सचे (sa)
                tcc_error("too few arguments to function");

            सचे (p) { /* with reverse_funcargs */
                अत्थाय (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    करोहि {
                        sa = sa->next, p2 = p2->prev;
                    } याव (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    व्यञ्जकम्_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            सचे (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } अञ्ञथा {
                /* return value */
                n = ret_nregs;
                याव (n > 1) {
                    पूर्णाङ्क rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    अत्थाय (r = 0; r < NB_REGS; ++r)
                        सचे (reg_classes[r] & rc)
                            भङ्ग;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                सचे (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    पूर्णाङ्क addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    सचे (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    अत्थाय (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        सचे (--ret_nregs == 0)
                          भङ्ग;
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
                सचे (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अञ्ञथा
                    vtop->type.t = VT_INT;
#endif
                }
            }
            सचे (s->f.func_noreturn) {
                सचे (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } अञ्ञथा {
            भङ्ग;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

स्थिर शून्य व्यञ्जकम्_prod(शून्य)
{
    पूर्णाङ्क t;

    unary();
    याव ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_sum(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_prod();
    याव ((t = tok) == '+' || t == '-') {
        next();
        व्यञ्जकम्_prod();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_shift(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_sum();
    याव ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        व्यञ्जकम्_sum();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_cmp(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_shift();
    याव (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        व्यञ्जकम्_shift();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_cmpeq(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_cmp();
    याव ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        व्यञ्जकम्_cmp();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_and(शून्य)
{
    व्यञ्जकम्_cmpeq();
    याव (tok == '&') {
        next();
        व्यञ्जकम्_cmpeq();
        gen_op('&');
    }
}

स्थिर शून्य व्यञ्जकम्_xor(शून्य)
{
    व्यञ्जकम्_and();
    याव (tok == '^') {
        next();
        व्यञ्जकम्_and();
        gen_op('^');
    }
}

स्थिर शून्य व्यञ्जकम्_or(शून्य)
{
    व्यञ्जकम्_xor();
    याव (tok == '|') {
        next();
        व्यञ्जकम्_xor();
        gen_op('|');
    }
}

स्थिर शून्य व्यञ्जकम्_landor(पूर्णाङ्क op);

स्थिर शून्य व्यञ्जकम्_land(शून्य)
{
    व्यञ्जकम्_or();
    सचे (tok == TOK_LAND)
        व्यञ्जकम्_landor(tok);
}

स्थिर शून्य व्यञ्जकम्_lor(शून्य)
{
    व्यञ्जकम्_land();
    सचे (tok == TOK_LOR)
        व्यञ्जकम्_landor(tok);
}

# define व्यञ्जकम्_landor_next(op) op == TOK_LAND ? व्यञ्जकम्_or() : व्यञ्जकम्_land()
#अञ्ञथा /* defined precedence_parser */
# define व्यञ्जकम्_landor_next(op) unary(), व्यञ्जकम्_infix(precedence(op) + 1)
# define व्यञ्जकम्_lor() unary(), व्यञ्जकम्_infix(1)

स्थिर पूर्णाङ्क precedence(पूर्णाङ्क tok)
{
    विकल्प (tok) {
        पक्ष TOK_LOR: पटिनिवत्त 1;
        पक्ष TOK_LAND: पटिनिवत्त 2;
	पक्ष '|': पटिनिवत्त 3;
	पक्ष '^': पटिनिवत्त 4;
	पक्ष '&': पटिनिवत्त 5;
	पक्ष TOK_EQ: पक्ष TOK_NE: पटिनिवत्त 6;
 relat: पक्ष TOK_ULT: पक्ष TOK_UGE: पटिनिवत्त 7;
	पक्ष TOK_SHL: पक्ष TOK_SAR: पटिनिवत्त 8;
	पक्ष '+': पक्ष '-': पटिनिवत्त 9;
	पक्ष '*': पक्ष '/': पक्ष '%': पटिनिवत्त 10;
	स्वभाव:
	    सचे (tok >= TOK_ULE && tok <= TOK_GT)
	        गच्छ relat;
	    पटिनिवत्त 0;
    }
}
स्थिर unsigned वर्ण prec[256];
स्थिर शून्य init_prec(शून्य)
{
    पूर्णाङ्क i;
    अत्थाय (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((unsigned)i < 256 ? prec[i] : 0)

स्थिर शून्य व्यञ्जकम्_landor(पूर्णाङ्क op);

स्थिर शून्य व्यञ्जकम्_infix(पूर्णाङ्क p)
{
    पूर्णाङ्क t = tok, p2;
    याव ((p2 = precedence(t)) >= p) {
        सचे (t == TOK_LOR || t == TOK_LAND) {
            व्यञ्जकम्_landor(t);
        } अञ्ञथा {
            next();
            unary();
            सचे (precedence(tok) > p2)
              व्यञ्जकम्_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
स्थिर पूर्णाङ्क condition_3way(शून्य)
{
    पूर्णाङ्क c = -1;
    सचे ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    पटिनिवत्त c;
}

स्थिर शून्य व्यञ्जकम्_landor(पूर्णाङ्क op)
{
    पूर्णाङ्क t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    अत्थाय(;;) {
        c = f ? i : condition_3way();
        सचे (c < 0)
            save_regs(1), cc = 0;
        अञ्ञथा सचे (c != i)
            nocode_wanted++, f = 1;
        सचे (tok != op)
            भङ्ग;
        सचे (c < 0)
            t = gvtst(i, t);
        अञ्ञथा
            vpop();
        next();
        व्यञ्जकम्_landor_next(op);
    }
    सचे (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } अञ्ञथा {
        gvtst_set(i, t);
    }
}

स्थिर पूर्णाङ्क is_cond_bool(SValue *sv)
{
    सचे ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        पटिनिवत्त (unsigned)sv->c.i < 2;
    सचे (sv->r == VT_CMP)
        पटिनिवत्त 1;
    पटिनिवत्त 0;
}

स्थिर शून्य व्यञ्जकम्_cond(शून्य)
{
    पूर्णाङ्क tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    व्यञ्जकम्_lor();
    सचे (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        सचे (!g) {
            सचे (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } अञ्ञथा {
                vpop();
            }
        } अञ्ञथा सचे (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        सचे (c == 0)
          nocode_wanted++;
        सचे (!g)
          gexpr();

        सचे ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        सचे (g) {
            u = tt;
        } अञ्ञथा सचे (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } अञ्ञथा
          u = 0;

        सचे (c == 0)
          nocode_wanted--;
        सचे (c == 1)
          nocode_wanted++;
        skip(':');
        व्यञ्जकम्_cond();

        सचे ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        सचे (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        सचे (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            पटिनिवत्त;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        सचे (c != 1) {
            gen_cast(&type);
            सचे (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        सचे (USING_TWO_शब्दाः(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        सचे (c < 0) {
            सचे (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        सचे (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        सचे (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            सचे (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        सचे (c < 0) {
            सचे (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        सचे (islv)
          indir();
    }
}

स्थिर शून्य व्यञ्जकम्_eq(शून्य)
{
    पूर्णाङ्क t;
    
    व्यञ्जकम्_cond();
    सचे ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        सचे (t == '=') {
            व्यञ्जकम्_eq();
        } अञ्ञथा {
            vdup();
            व्यञ्जकम्_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC शून्य gexpr(शून्य)
{
    व्यञ्जकम्_eq();
    सचे (tok == ',') {
        करोहि {
            vpop();
            next();
            व्यञ्जकम्_eq();
        } याव (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        सचे ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            सचे (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
स्थिर शून्य व्यञ्जकम्_const1(शून्य)
{
    nocode_wanted += CONST_WANTED_BIT;
    व्यञ्जकम्_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
स्थिर अन्तःस्थ int64_t व्यञ्जकम्_const64(शून्य)
{
    int64_t c;
    व्यञ्जकम्_const1();
    सचे ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    पटिनिवत्त c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC पूर्णाङ्क व्यञ्जकम्_const(शून्य)
{
    पूर्णाङ्क c;
    int64_t wc = व्यञ्जकम्_const64();
    c = wc;
    सचे (c != wc && (unsigned)c != wc)
        tcc_error("constant exceeds 32 bit");
    पटिनिवत्त c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
स्थिर शून्य gfunc_return(CType *func_type)
{
    सचे ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        पूर्णाङ्क ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        सचे (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } अञ्ञथा सचे (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } अञ्ञथा {
            /* returning structure packed into registers */
            पूर्णाङ्क size, addr, align, rc, n;
            size = type_size(func_type,&align);
            सचे (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		सचे (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		सचे (ret_align > align)
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
            अत्थाय (n = ret_nregs; --n > 0;) {
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
    } अञ्ञथा {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

स्थिर शून्य check_func_return(शून्य)
{
    सचे ((func_vt.t & VT_BTYPE) == VT_VOID)
        पटिनिवत्त;
    सचे ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } अञ्ञथा {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

स्थिर पूर्णाङ्क case_cmp(uint64_t a, uint64_t b)
{
    सचे (cur_switch->sv.type.t & VT_UNSIGNED)
        पटिनिवत्त a < b ? -1 : a > b;
    अञ्ञथा
        पटिनिवत्त (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

स्थिर पूर्णाङ्क case_cmp_qs(ध्रुव शून्य *pa, ध्रुव शून्य *pb)
{
    पटिनिवत्त case_cmp((*(संरचना case_t**)pa)->v1, (*(संरचना case_t**)pb)->v1);
}

स्थिर शून्य case_sort(संरचना switch_t *sw)
{
    संरचना case_t **p;
    सचे (sw->n < 2)
        पटिनिवत्त;
    qsort(sw->p, sw->n, परिमाण *sw->p, case_cmp_qs);
    p = sw->p;
    याव (p < sw->p + sw->n - 1) {
        सचे (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            पूर्णाङ्क l1 = p[0]->पङ्क्तिः, l2 = p[1]->पङ्क्तिः;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } अञ्ञथा सचे (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * परिमाण *p);
        } अञ्ञथा
            ++p;
    }
}

स्थिर पूर्णाङ्क gcase(संरचना case_t **base, पूर्णाङ्क len, पूर्णाङ्क dsym)
{
    संरचना case_t *p;
    पूर्णाङ्क t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    सचे (t != VT_LLONG)
        t = VT_INT;
    याव (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        सचे (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } अञ्ञथा {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            सचे (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            अञ्ञथा
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
    पटिनिवत्त gjmp(dsym);
}

स्थिर शून्य end_switch(शून्य)
{
    संरचना switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
स्थिर शून्य save_lvalues(शून्य)
{
    SValue *sv = vtop;
    याव (sv >= vstack) {
        सचे (sv->sym && (sv->r & VT_LVAL)) {
            पूर्णाङ्क align, size = type_size(&sv->type, &align);
            पूर्णाङ्क r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

स्थिर शून्य try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    अत्थाय (; cls != stop; cls = cls->next) {
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


स्थिर शून्य try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    पूर्णाङ्क ocd, ccd;

    सचे (!cur_scope->cl.s)
	पटिनिवत्त;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    अत्थाय (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    अत्थाय (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    अत्थाय (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
स्थिर शून्य block_cleanup(संरचना scope *o)
{
    पूर्णाङ्क jmp = 0;
    Sym *g, **pg;
    अत्थाय (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        सचे (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            सचे (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            सचे (!o->cl.n)
                गच्छ remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } अञ्ञथा {
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

स्थिर शून्य vla_restore(पूर्णाङ्क loc)
{
    सचे (loc)
        gen_vla_sp_restore(loc);
}

स्थिर शून्य vla_leave(संरचना scope *o)
{
    संरचना scope *c = cur_scope, *v = रिक्त;
    अत्थाय (; c != o && c; c = c->prev)
      सचे (c->vla.अङ्कः)
        v = c;
    सचे (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

स्थिर शून्य new_scope(संरचना scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.अङ्कः = 0;

    /* record local declaration stack position */
    o->lstk = local_राशिः;
    o->llstk = local_label_राशिः;
    ++local_scope;
}

स्थिर शून्य prev_scope(संरचना scope *o, पूर्णाङ्क is_व्यञ्जकम्)
{
    vla_leave(o->prev);

    सचे (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    सचे (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_व्यञ्जकम्);

    /* pop locally defined labels */
    label_निष्कासय(&local_label_राशिः, o->llstk, is_व्यञ्जकम्);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_निष्कासय(&local_राशिः, o->lstk, is_व्यञ्जकम्);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
स्थिर शून्य leave_scope(संरचना scope *o)
{
    सचे (!o)
        पटिनिवत्त;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
स्थिर शून्य new_scope_s(संरचना scope *o)
{
    o->lstk = local_राशिः;
    ++local_scope;
}

स्थिर शून्य prev_scope_s(संरचना scope *o)
{
    sym_निष्कासय(&local_राशिः, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

स्थिर शून्य lblock(पूर्णाङ्क *bsym, पूर्णाङ्क *csym)
{
    संरचना scope *lo = loop_scope, *co = cur_scope;
    पूर्णाङ्क *b = co->bsym, *c = co->csym;
    सचे (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    सचे (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
स्थिर शून्य gexpr_decl(शून्य)
{
    पूर्णाङ्क v = decl(VT_JMP);
    सचे (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } अञ्ञथा {
        सचे (v)
            skip(';');
        gexpr();
    }
}

स्थिर शून्य block(पूर्णाङ्क flags)
{
    पूर्णाङ्क a, b, c, d, e, t;
    संरचना scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    सचे (TOK_HAS_मानम्(t))
        गच्छ व्यञ्जकम्;
    next();

    सचे (debug_modes)
        tcc_tcov_check_पङ्क्तिः (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    सचे (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        सचे (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } अञ्ञथा {
            gsym(a);
        }
        prev_scope_s(&o);

    } अञ्ञथा सचे (t == TOK_WHILE) {
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

    } अञ्ञथा सचे (t == '{') {
        सचे (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        याव (tok == TOK_LABEL) {
            करोहि {
                next();
                सचे (tok < TOK_UIDENT)
                    expect("label identifier");
                label_प्रक्षिप(&local_label_राशिः, tok, LABEL_DECLARED);
                next();
            } याव (tok == ',');
            skip(';');
        }

        याव (tok != '}') {
	    decl(VT_LOCAL);
            सचे (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_व्यञ्जकम्);
        सचे (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        सचे (local_scope)
            next();
        अञ्ञथा सचे (!nocode_wanted)
            check_func_return();

    } अञ्ञथा सचे (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        सचे (tok != ';') {
            gexpr();
            सचे (b) {
                gen_assign_cast(&func_vt);
            } अञ्ञथा {
                सचे (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } अञ्ञथा सचे (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } अञ्ञथा सचे (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(मूलम्_scope);
        सचे (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        सचे (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        सचे (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } अञ्ञथा सचे (t == TOK_BREAK) {
        /* compute jump */
        सचे (!cur_scope->bsym)
            tcc_error("cannot break");
        सचे (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        अञ्ञथा
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } अञ्ञथा सचे (t == TOK_CONTINUE) {
        /* compute jump */
        सचे (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } अञ्ञथा सचे (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        सचे (tok != ';') {
            /* c99 for-loop init decl? */
            सचे (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        सचे (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        सचे (tok != ')') {
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

    } अञ्ञथा सचे (t == TOK_DO) {
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

    } अञ्ञथा सचे (t == TOK_SWITCH) {
        संरचना switch_t *sw;

        sw = tcc_mallocz(परिमाण *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        सचे (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, रिक्त);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        सचे (sw->nocode_wanted)
            गच्छ skip_switch;
        case_sort(sw);
        sw->bsym = रिक्त; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        सचे (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        अञ्ञथा
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } अञ्ञथा सचे (t == TOK_CASE) {
        संरचना case_t *cr;
        सचे (!cur_switch)
            expect("switch");
        cr = tcc_malloc(परिमाण(संरचना case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(व्यञ्जकम्_const64(), t);
        सचे (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(व्यञ्जकम्_const64(), t);
            सचे (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        सचे (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->पङ्क्तिः = file->पङ्क्तिः_अङ्कः;
        skip(':');
        गच्छ block_after_label;

    } अञ्ञथा सचे (t == TOK_DEFAULT) {
        सचे (!cur_switch)
            expect("switch");
        सचे (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        गच्छ block_after_label;

    } अञ्ञथा सचे (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        सचे (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            सचे ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } अञ्ञथा सचे (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            सचे (!s)
              s = label_प्रक्षिप(&global_label_राशिः, tok, LABEL_FORWARD);
            अञ्ञथा सचे (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    सचे (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		सचे (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } अञ्ञथा {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } अञ्ञथा {
            expect("label identifier");
        }
        skip(';');

    } अञ्ञथा सचे (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } अञ्ञथा {
        सचे (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            सचे (s) {
                सचे (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, रिक्त));
                s->r = LABEL_DEFINED;
		सचे (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    अत्थाय (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_निष्कासय(&s->next, रिक्त, 0);
		} अञ्ञथा
		  gsym(s->jnext);
            } अञ्ञथा {
                s = label_प्रक्षिप(&global_label_राशिः, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(रिक्त);

            सचे (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            सचे (tok != '}') {
                सचे (0 == (flags & STMT_COMPOUND))
                    गच्छ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } अञ्ञथा {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } अञ्ञथा {
            /* expression case */
            सचे (t != ';') {
                unget_tok(t);
    व्यञ्जकम्:
                सचे (flags & STMT_व्यञ्जकम्) {
                    vpop();
                    gexpr();
                } अञ्ञथा {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    सचे (debug_modes)
        tcc_tcov_check_पङ्क्तिः (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
स्थिर शून्य skip_or_save_block(TokenString **str)
{
    पूर्णाङ्क braces = tok == '{';
    पूर्णाङ्क level = 0;
    सचे (str)
      *str = tok_str_alloc();

    याव (1) {
	पूर्णाङ्क t = tok;
        सचे (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             भङ्ग;
	सचे (t == TOK_EOF) {
	     सचे (str || level > 0)
	       tcc_error("unexpected end of file");
	     अञ्ञथा
	       भङ्ग;
	}
	सचे (str)
	  tok_str_add_tok(*str);
	next();
	सचे (t == '{' || t == '(' || t == '[') {
	    level++;
	} अञ्ञथा सचे (t == '}' || t == ')' || t == ']') {
	    level--;
	    सचे (level == 0 && braces && t == '}')
	      भङ्ग;
	}
    }
    सचे (str)
	tok_str_add(*str, TOK_EOF);
}

#define व्यञ्जकम्_CONST 1
#define व्यञ्जकम्_ANY   2

स्थिर शून्य parse_init_elem(पूर्णाङ्क व्यञ्जकम्_type)
{
    पूर्णाङ्क saved_global_व्यञ्जकम्;
    विकल्प(व्यञ्जकम्_type) {
    पक्ष व्यञ्जकम्_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_व्यञ्जकम् = global_व्यञ्जकम्;
        global_व्यञ्जकम् = 1;
        व्यञ्जकम्_const1();
        global_व्यञ्जकम् = saved_global_व्यञ्जकम्;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        सचे (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        भङ्ग;
    पक्ष व्यञ्जकम्_ANY:
        व्यञ्जकम्_eq();
        भङ्ग;
    }
}

#सचे 1
स्थिर शून्य init_assert(init_params *p, पूर्णाङ्क offset)
{
    सचे (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#अञ्ञथा
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
स्थिर शून्य init_putz(init_params *p, unsigned long c, पूर्णाङ्क size)
{
    init_assert(p, c + size);
    सचे (p->sec) {
        /* nothing to do because globals are already set to zero */
    } अञ्ञथा {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#सचे defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
स्थिर शून्य decl_design_delrels(Section *sec, पूर्णाङ्क c, पूर्णाङ्क size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    सचे (!sec || !sec->reloc)
        पटिनिवत्त;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    याव (rel < rel_end) {
        सचे (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= परिमाण *rel;
        } अञ्ञथा {
            सचे (rel2 != rel)
                memcpy(rel2, rel, परिमाण *rel);
            ++rel2;
        }
        ++rel;
    }
}

स्थिर शून्य decl_design_flex(init_params *p, Sym *ref, पूर्णाङ्क index)
{
    सचे (ref == p->flex_array_ref) {
        सचे (index >= ref->c)
            ref->c = index + 1;
    } अञ्ञथा सचे (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
स्थिर पूर्णाङ्क decl_designator(init_params *p, CType *type, unsigned long c,
                           Sym **cur_field, पूर्णाङ्क flags, पूर्णाङ्क al)
{
    Sym *s, *f;
    पूर्णाङ्क index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;

    सचे (flags & DIF_HAVE_ELEM)
        गच्छ no_designator;

    सचे (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        सचे (tok == ':')
            गच्छ struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    याव (nb_elems == 1 && (tok == '[' || tok == '.')) {
        सचे (tok == '[') {
            सचे (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = व्यञ्जकम्_const();
            सचे (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = व्यञ्जकम्_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            सचे (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            सचे (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } अञ्ञथा {
            पूर्णाङ्क cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            सचे (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = रिक्त;
    }
    सचे (!cur_field) {
        सचे (tok == '=') {
            next();
        } अञ्ञथा सचे (!gnu_ext) {
	    expect("=");
        }
    } अञ्ञथा {
    no_designator:
        सचे (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            सचे (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } अञ्ञथा {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    याव (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            सचे (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    सचे (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    सचे (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    सचे (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        पूर्णाङ्क i;
        सचे (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        सचे (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        अञ्ञथा
	    vset(type, VT_LOCAL|VT_LVAL, c);
        अत्थाय (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    सचे (c - corig > al)
      al = c - corig;
    पटिनिवत्त al;
}

स्थिर शून्य write_ldouble(unsigned वर्ण *d, शून्य *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    सचे (LDOUBLE_SIZE >= 10) {
        द्विगुण b = *(long द्विगुण*)s;
        s = &b;
#अञ्ञथा
    सचे (परिमाण (long द्विगुण) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        पूर्णाङ्क e = m >> 48;
        पूर्णाङ्क f = e >> 4 & 0x7FF;
        m <<= 11;
        सचे (0 == f) {
            सचे (0 == m)
                गच्छ set;
            अत्थाय (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        सचे (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #सचे (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #नोचेद्यदि LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } अञ्ञथा {
    #सचे LDOUBLE_SIZE == 8
        /* long double -> double */
        द्विगुण b = *(long द्विगुण*)s;
        memcpy(d, &b, 8);
    #नोचेद्यदि (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        memcpy(d, s, 10);
    #नोचेद्यदि (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        पूर्णाङ्क e = *(uint16_t*)((वर्ण*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #नोचेद्यदि (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((वर्ण*)s + 6);
        पूर्णाङ्क e = read16le((वर्ण*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #अञ्ञथा
        /* unknown */
        सचे (परिमाण (long द्विगुण) == LDOUBLE_SIZE)
            memcpy(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
स्थिर शून्य init_putv(init_params *p, CType *type, unsigned long c)
{
    पूर्णाङ्क bt;
    शून्य *ptr;
    CType dtype;
    पूर्णाङ्क size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    सचे (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    सचे (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        सचे ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        सचे (NODATA_WANTED) {
            vtop--;
            पटिनिवत्त;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	सचे ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->data + esym->st_मानम् + (पूर्णाङ्क)vtop->c.i, size);
	    सचे (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                unsigned long relofs = ssec->reloc->data_offset;
		याव (relofs >= परिमाण(*rel)) {
                    relofs -= परिमाण(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    सचे (rel->r_offset >= esym->st_मानम् + size)
		      अनुवर्त;
		    सचे (rel->r_offset < esym->st_मानम्)
		      भङ्ग;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_मानम्,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#सचे PTR_SIZE == 8
				   rel->r_addend
#अञ्ञथा
				   0
#endif
				  );
		}
	    }
	} अञ्ञथा {
            सचे (type->t & VT_BITFIELD) {
                पूर्णाङ्क bit_pos, bit_size, bits, n;
                unsigned वर्ण *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned वर्ण*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                याव (bit_size) {
                    n = 8 - bit_pos;
                    सचे (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } अञ्ञथा
            विकल्प(bt) {
	    पक्ष VT_BOOL:
		*(वर्ण *)ptr = val != 0;
                भङ्ग;
	    पक्ष VT_BYTE:
		*(वर्ण *)ptr = val;
		भङ्ग;
	    पक्ष VT_SHORT:
                write16le(ptr, val);
		भङ्ग;
	    पक्ष VT_FLOAT:
                write32le(ptr, val);
		भङ्ग;
	    पक्ष VT_DOUBLE:
                write64le(ptr, val);
		भङ्ग;
	    पक्ष VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		भङ्ग;

#सचे PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    पक्ष VT_LLONG:
	    पक्ष VT_PTR:
	        सचे (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        अञ्ञथा
	          write64le(ptr, val);
	        भङ्ग;
            पक्ष VT_INT:
                write32le(ptr, val);
                भङ्ग;
#अञ्ञथा
	    पक्ष VT_LLONG:
                write64le(ptr, val);
                भङ्ग;
            पक्ष VT_PTR:
            पक्ष VT_INT:
	        सचे (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        भङ्ग;
#endif
	    स्वभाव:
                //tcc_internal_error("unexpected type");
                भङ्ग;
	    }
	}
        vtop--;
    } अञ्ञथा {
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
स्थिर शून्य decl_initializer(init_params *p, CType *type, unsigned long c, पूर्णाङ्क flags)
{
    पूर्णाङ्क len, n, no_oblock, i;
    पूर्णाङ्क size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    सचे (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_पङ्क्तिः(tcc_state), tcc_tcov_check_पङ्क्तिः (tcc_state, 1);

    सचे (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        पूर्णाङ्क ncw_prev = nocode_wanted;
        सचे ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? व्यञ्जकम्_ANY : व्यञ्जकम्_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    सचे (type->t & VT_ARRAY) {
        no_oblock = 1;
        सचे (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        सचे ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#अञ्ञथा
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            सचे (size1 != (tok == TOK_STR ? 1 : परिमाण(nwchar_t)))
              tcc_error("unhandled string literal merging");
            याव (tok == TOK_STR || tok == TOK_LSTR) {
                सचे (initstr.size)
                  initstr.size -= size1;
                सचे (tok == TOK_STR)
                  len += tokc.str.size;
                अञ्ञथा
                  len += tokc.str.size / परिमाण(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            सचे (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                गच्छ do_init_array;
            }

            decl_design_flex(p, s, len);
            सचे (!(flags & DIF_SIZE_ONLY)) {
                पूर्णाङ्क nb = n, ch;
                सचे (len < nb)
                    nb = len;
                सचे (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                सचे (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    सचे (!NODATA_WANTED)
                      memcpy(p->sec->data + c, initstr.data, nb);
                } अञ्ञथा {
                    अत्थाय(i=0;i<n;i++) {
                        सचे (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          सचे (flags & DIF_CLEAR)
                            भङ्ग;
                          सचे (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            भङ्ग;
                          }
                          ch = 0;
                        } अञ्ञथा सचे (size1 == 1)
                          ch = ((unsigned वर्ण *)initstr.data)[i];
                        अञ्ञथा
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            सचे (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } अञ्ञथा {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            सचे (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    याव (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		सचे (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    सचे (no_oblock && len >= n*size1)
		        भङ्ग;
		} अञ्ञथा {
		    सचे (s->type.t == VT_UNION)
		        f = रिक्त;
		    अञ्ञथा
		        f = f->next;
		    सचे (no_oblock && f == रिक्त)
		        भङ्ग;
		}

		सचे (tok == '}')
		    भङ्ग;
		skip(',');
	    }
        }
        सचे (!no_oblock)
            skip('}');

    } अञ्ञथा सचे ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        गच्छ one_elem;

    } अञ्ञथा सचे ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        सचे ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	गच्छ do_init_list;

    } अञ्ञथा सचे (tok == '{') {
        सचे (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } अञ्ञथा one_elem: सचे ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        सचे (flags & DIF_HAVE_ELEM)
            vpop();
        अञ्ञथा
            skip_or_save_block(रिक्त);

    } अञ्ञथा {
	सचे (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    सचे (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? व्यञ्जकम्_ANY : व्यञ्जकम्_CONST);
	}
        सचे (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        अञ्ञथा
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
स्थिर शून्य decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णाङ्क r, 
                                   पूर्णाङ्क has_init, पूर्णाङ्क v, पूर्णाङ्क scope)
{
    पूर्णाङ्क size, align, addr;
    TokenString *init_str = रिक्त;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = रिक्त;
    पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    पूर्णाङ्क bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    सचे (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        सचे (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            सचे (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                पटिनिवत्त;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    सचे (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = रिक्त;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    सचे (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        सचे (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        सचे (IS_BT_ARRAY(type->t))
            type->ref = sym_प्रक्षिप(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } अञ्ञथा सचे (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        सचे (field) {
            याव (field->next)
                field = field->next;
            सचे (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    सचे (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        सचे (!has_init)
            गच्छ err_size;
        सचे (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            याव (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } अञ्ञथा
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
        सचे (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        सचे (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    सचे (ad->a.aligned) {
	पूर्णाङ्क speca = 1 << (ad->a.aligned - 1);
        सचे (speca > align)
            align = speca;
    } अञ्ञथा सचे (ad->a.packed) {
        align = 1;
    }

    सचे (!v && NODATA_WANTED)
        size = 0, align = 1;

    सचे ((r & VT_VALMASK) == VT_LOCAL) {
        sec = रिक्त;
#ifdef CONFIG_TCC_BCHECK
        सचे (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        सचे (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        सचे (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    सचे (ad->asm_label) {
		पूर्णाङ्क reg = asm_parse_regvar(ad->asm_label);
		सचे (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_प्रक्षिप(v, type, r, addr);
	    सचे (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } अञ्ञथा {
            /* push local reference */
            vset(type, r, addr);
        }
    } अञ्ञथा {
        CType *tp = type;
        पूर्णाङ्क is_const;

        याव ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        सचे (!sec) {
            सचे (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } अञ्ञथा सचे (is_const) {
		sec = rodata_section;
            } अञ्ञथा सचे (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } अञ्ञथा सचे (tcc_state->nocommon)
                sec = bss_section;
        } अञ्ञथा सचे (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            सचे (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                सचे (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        सचे (bcheck)
            size = size + 1; /* add padding */
#endif
        सचे (sec) {
	    addr = section_add(sec, size, align);
        } अञ्ञथा {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        सचे (v) {
            सचे (!sym) {
                sym = sym_प्रक्षिप(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, रिक्त);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } अञ्ञथा {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        सचे (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * परिमाण(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    सचे (type->t & VT_VLA) {
        पूर्णाङ्क a;

        सचे (has_init)
            tcc_error("variable length array cannot be initialized");

        सचे (NODATA_WANTED)
            गच्छ no_alloc;

        /* save before-VLA stack pointer if needed */
        सचे (cur_scope->vla.अङ्कः == 0) {
            सचे (cur_scope->prev && cur_scope->prev->vla.अङ्कः) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } अञ्ञथा {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#सचे defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.अङ्कः++;
    } अञ्ञथा सचे (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        सचे (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    सचे (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
स्थिर शून्य func_vla_arg_code(Sym *arg)
{
    पूर्णाङ्क align;
    TokenString *vla_array_tok = रिक्त;

    सचे (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    सचे ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

स्थिर शून्य func_vla_arg(Sym *sym)
{
    Sym *arg;

    अत्थाय (arg = sym->type.ref->next; arg; arg = arg->next)
        सचे ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, पूर्णाङ्क c, पूर्णाङ्क byref)
{
    s = sym_find(s->v);
    सचे (!s) /* unnamed parameters, not enabled */
        पटिनिवत्त रिक्त;
    s->c = c;
    सचे (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    पटिनिवत्त s;
}

/* push parameters (and their types), last first */
स्थिर शून्य sym_प्रक्षिप_params(Sym *ref)
{
    Sym *s = ref;
    याव (s->next)
        s = s->next;
    याव (s != ref) {
        सचे ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_राशिः);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
स्थिर शून्य gen_function(Sym *sym)
{
    संरचना scope f = { 0 };

    cur_scope = मूलम्_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    सचे (sym->a.aligned) {
	size_t newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, रिक्त);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    सचे (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    सचे (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_राशिः, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_प्रक्षिप_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_temp_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(रिक्त, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    cur_text_section->data_offset = ind;

    sym_निष्कासय(&local_राशिः, रिक्त, 0);
    label_निष्कासय(&global_label_राशिः, रिक्त, 0);
    sym_निष्कासय(&all_cleanups, रिक्त, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = रिक्त;
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

स्थिर शून्य gen_inline_functions(TCCState *s)
{
    Sym *sym;
    पूर्णाङ्क inline_generated, i;
    संरचना InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    करोहि {
        inline_generated = 0;
        अत्थाय (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            सचे (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = रिक्त;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } याव (inline_generated);
    tcc_close();
}

स्थिर शून्य free_inline_functions(TCCState *s)
{
    पूर्णाङ्क i;
    /* free tokens of unused inline functions */
    अत्थाय (i = 0; i < s->nb_inline_fns; ++i) {
        संरचना InlineFunc *fn = s->inline_fns[i];
        सचे (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

स्थिर शून्य do_Static_assert(शून्य)
{
    पूर्णाङ्क c;
    ध्रुव वर्ण *सन्देशः;

    next();
    skip('(');
    c = व्यञ्जकम्_const();
    सन्देशः = "_Static_assert fail";
    सचे (tok == ',') {
        next();
        सन्देशः = parse_mult_str("string constant")->data;
    }
    skip(')');
    सचे (c == 0)
        tcc_error("%s", सन्देशः);
    skip(';');
}

#ifdef TCC_TARGET_PE
स्थिर शून्य pe_check_linkage(CType *type, AttributeDef *ad)
{
    सचे (!ad->a.dllimport && !ad->a.dllexport)
        पटिनिवत्त;
    सचे (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    सचे (type->t & VT_TYPEDEF) {
        ध्रुव वर्ण *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } अञ्ञथा सचे (ad->a.dllimport) {
        सचे ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        अञ्ञथा
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
स्थिर पूर्णाङ्क decl(पूर्णाङ्क l)
{
    पूर्णाङ्क v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    याव (1) {

        oldint = 0;
        सचे (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            सचे (l == VT_JMP)
                पटिनिवत्त 0;
            /* skip redundant ';' if not in old parameter decl scope */
            सचे (tok == ';' && l != VT_CMP) {
                next();
                अनुवर्त;
            }
            सचे (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                अनुवर्त;
            }
            सचे (l != VT_CONST)
                भङ्ग;
            सचे (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                अनुवर्त;
            }
            सचे (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } अञ्ञथा {
                सचे (tok != TOK_EOF)
                    expect("declaration");
                भङ्ग;
            }
        }

        सचे (tok == ';') {
            सचे ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            अञ्ञथा सचे (IS_ENUM(btype.t))
                ; /* enum decl */
            अञ्ञथा
                tcc_warning("useless type defines no instances");
            सचे (l == VT_JMP)
                पटिनिवत्त 1;
            next();
            अनुवर्त;
        }

        याव (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            सचे ((type.t & VT_BTYPE) == VT_FUNC) {
                सचे ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                सचे (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                सचे ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    सचे (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    अञ्ञथा
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } अञ्ञथा सचे (oldint) {
                tcc_warning("type defaults to int");
            }

            सचे (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #सचे 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                सचे (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            सचे (tok == '{') {
                सचे (l != VT_CONST)
                    tcc_error("cannot use local functions");
                सचे ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                अत्थाय (sa = sym->type.ref; (sa = sa->next) != रिक्त;) {
                    सचे (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    सचे (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                सचे (sym->type.t & VT_INLINE) {
                    संरचना InlineFunc *fn;
                    fn = tcc_malloc(परिमाण *fn + strlen(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } अञ्ञथा {
                    /* compute text section */
                    cur_text_section = text_section;
                    सचे (ad.section) {
                        cur_text_section = ad.section;
                        सचे (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                भङ्ग;
            } अञ्ञथा {
                has_init = 0;
		सचे (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    अत्थाय (sym = func_vt.ref->next; sym; sym = sym->next)
			सचे ((sym->v & ~SYM_FIELD) == v)
			    गच्छ found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, रिक्त));
                found:
		    सचे (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, रिक्त));
		    सचे (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, रिक्त));
		    convert_parameter_type(&type);
		    sym->type = type;
		} अञ्ञथा सचे (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    सचे (sym && sym->sym_scope == local_scope) {
                        सचे (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, रिक्त));
                        sym->type = type;
                    } अञ्ञथा {
                        sym = sym_प्रक्षिप(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    सचे ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    सचे (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} अञ्ञथा सचे ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } अञ्ञथा {
                    r = 0;
                    सचे ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } अञ्ञथा सचे (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    सचे (tok == '=')
                        has_init = 1;

                    सचे (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } अञ्ञथा {
                        सचे (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        अञ्ञथा
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        सचे (has_init)
                            next();
                        अञ्ञथा सचे (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    सचे (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        सचे (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_मानम्, esym->st_size, 1);
                    }
                }
                सचे (tok != ',') {
                    सचे (l == VT_JMP)
                        पटिनिवत्त has_init ? v : 1;
                    skip(';');
                    भङ्ग;
                }
                next();
            }
        }
    }
    पटिनिवत्त 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
