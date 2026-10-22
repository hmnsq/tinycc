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
ST_DATA पूर्णांक rsym, anon_sym, ind, loc;

ST_DATA Sym *global_चळत;
ST_DATA Sym *local_चळत;
ST_DATA Sym *define_चळत;
ST_DATA Sym *global_label_चळत;
ST_DATA Sym *local_label_चळत;

स्थिर Sym *sym_free_first;
स्थिर शून्य **sym_pools;
स्थिर पूर्णांक nb_sym_pools;

स्थिर Sym *all_cleanups, *pending_gotos;
स्थिर पूर्णांक local_scope;
ST_DATA अक्षर debug_modes;

ST_DATA SValue *vtop;
स्थिर SValue _vstack[1 + VSTACK_SIZE];
#define vstack (_vstack + 1)

ST_DATA पूर्णांक nocode_wanted; /* no code generation wanted */
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define DATA_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#define CODE_OFF_BIT 0x20000000
#define CODE_OFF() जर(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#define CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#define NOEVAL_MASK 0x0000FFFF
#define NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#define CONST_WANTED_BIT  0x00010000
#define CONST_WANTED_MASK 0x0FFF0000
#define CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_DATA पूर्णांक global_अभिव्यक्ती;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA पूर्णांक func_var; /* true if current function is variadic (used by return instruction) */
ST_DATA पूर्णांक func_vc; /* stack address for implicit struct return storage */
ST_DATA पूर्णांक func_ind; /* function start address */
स्थिर पूर्णांक func_old;
ST_DATA स्थिरांक अक्षर *funcname;
ST_DATA CType int_type, func_old_type, char_type, char_pointer_type;
स्थिर CString initstr;

#जर PTR_SIZE == 4
#define VT_SIZE_T (VT_INT | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_INT
#किंवाजर LONG_SIZE == 4
#define VT_SIZE_T (VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T VT_LLONG
#अन्यथा
#define VT_SIZE_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#define VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#endif

स्थिर संरचना switch_t {
    संरचना case_t {
        int64_t v1, v2;
        पूर्णांक ind, ओळ;
    } **p; पूर्णांक n; /* list of case ranges */
    पूर्णांक def_sym; /* default symbol */
    पूर्णांक nocode_wanted;
    पूर्णांक *bsym;
    संरचना scope *scope;
    संरचना switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#define MAX_TEMP_LOCAL_VARIABLE_संख्या 8
/*list of temporary local variables on the stack in current function. */
स्थिर संरचना temp_local_variable {
	पूर्णांक location; //offset on stack. Svalue.c.i
	लघु size;
	लघु align;
} arr_temp_local_vars[MAX_TEMP_LOCAL_VARIABLE_संख्या];
स्थिर पूर्णांक nb_temp_local_vars;

स्थिर संरचना scope {
    संरचना scope *prev;
    संरचना { पूर्णांक loc, locorig, अंक; } vla;
    संरचना { Sym *s; पूर्णांक n; } cl;
    पूर्णांक *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *मूळ_scope;

प्रकारव्याख्या संरचना {
    Section *sec;
    पूर्णांक local_offset;
    Sym *flex_array_ref;
} init_params;

#जर 1
#define precedence_parser
स्थिर शून्य init_prec(शून्य);
#endif

स्थिर शून्य block(पूर्णांक flags);
#define STMT_अभिव्यक्ती 1
#define STMT_COMPOUND 2

स्थिर शून्य gen_cast(CType *type);
स्थिर शून्य gen_cast_s(पूर्णांक t);
स्थिर ओळीत CType *pointed_type(CType *type);
स्थिर शून्य check_restrict_type(CType *type);
स्थिर पूर्णांक type_qualifiers(CType *type);
स्थिर शून्य parse_btype_qualify(CType *type, पूर्णांक qualifiers);
स्थिर पूर्णांक is_compatible_types(CType *type1, CType *type2);
स्थिर पूर्णांक parse_btype(CType *type, AttributeDef *ad, पूर्णांक ignore_label);
स्थिर CType *type_decl(CType *type, AttributeDef *ad, पूर्णांक *v, पूर्णांक td);
स्थिर शून्य parse_अभिव्यक्ती_type(CType *type);
स्थिर शून्य init_putv(init_params *p, CType *type, अचिन्हित दीर्घ c);
स्थिर शून्य decl_initializer(init_params *p, CType *type, अचिन्हित दीर्घ c, पूर्णांक flags);
स्थिर शून्य decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णांक r, पूर्णांक has_init, पूर्णांक v, पूर्णांक scope);
स्थिर पूर्णांक decl(पूर्णांक l);
स्थिर शून्य अभिव्यक्ती_eq(शून्य);
स्थिर शून्य vpush_type_size(CType *type, पूर्णांक *a);
स्थिर पूर्णांक is_compatible_unqualified_types(CType *type1, CType *type2);
स्थिर ओळीत int64_t अभिव्यक्ती_const64(शून्य);
स्थिर शून्य vpush64(पूर्णांक ty, अचिन्हित दीर्घ दीर्घ v);
स्थिर शून्य vpush(CType *type);
स्थिर पूर्णांक gvtst(पूर्णांक inv, पूर्णांक t);
स्थिर शून्य gen_inline_functions(TCCState *s);
स्थिर शून्य free_inline_functions(TCCState *s);
स्थिर शून्य skip_or_save_block(TokenString **str);
स्थिर शून्य gv_dup(शून्य);
स्थिर पूर्णांक get_temp_local_var(पूर्णांक size,पूर्णांक align,पूर्णांक *r2);
स्थिर शून्य cast_error(CType *st, CType *dt);
स्थिर शून्य end_switch(शून्य);
स्थिर शून्य do_Static_assert(शून्य);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC शून्य gsym(पूर्णांक t)
{
  जर (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
स्थिर पूर्णांक gind()
{
  पूर्णांक t = ind;
  CODE_ON();
  जर (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  परत t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
स्थिर शून्य gjmp_addr_acs(पूर्णांक t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
स्थिर पूर्णांक gjmp_acs(पूर्णांक t)
{
  t = gjmp(t);
  CODE_OFF();
  परत t;
}

/* These are #undef'd at the end of this file */
#define gjmp_addr gjmp_addr_acs
#define gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN पूर्णांक is_float(पूर्णांक t)
{
    पूर्णांक bt = t & VT_BTYPE;
    परत bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

स्थिर ओळीत पूर्णांक is_integer_btype(पूर्णांक bt)
{
    परत bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

स्थिर पूर्णांक btype_size(पूर्णांक bt)
{
    परत bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_SIZE : 0;
}

/* returns function return register from type */
स्थिर पूर्णांक R_RET(पूर्णांक t)
{
    जर (!is_float(t))
        परत REG_IRET;
#ifdef TCC_TARGET_X86_64
    जर ((t & VT_BTYPE) == VT_LDOUBLE)
        परत TREG_ST0;
#किंवाजर defined TCC_TARGET_RISCV64
    जर ((t & VT_BTYPE) == VT_LDOUBLE)
        परत REG_IRET;
#endif
    परत REG_FRET;
}

/* returns 2nd function return register, if any */
स्थिर पूर्णांक R2_RET(पूर्णांक t)
{
    t &= VT_BTYPE;
#जर PTR_SIZE == 4
    जर (t == VT_LLONG)
        परत REG_IRE2;
#किंवाजर defined TCC_TARGET_X86_64
    जर (t == VT_QLONG)
        परत REG_IRE2;
    जर (t == VT_QFLOAT)
        परत REG_FRE2;
#किंवाजर defined TCC_TARGET_RISCV64
    जर (t == VT_LDOUBLE)
        परत REG_IRE2;
#endif
    परत VT_CONST;
}

/* returns true for two-word types */
#define USING_TWO_शब्द(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
स्थिर शून्य PUT_R_RET(SValue *sv, पूर्णांक t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
स्थिर पूर्णांक RC_RET(पूर्णांक t)
{
    परत reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
स्थिर पूर्णांक RC_TYPE(पूर्णांक t)
{
    जर (!is_float(t))
        परत RC_INT;
#ifdef TCC_TARGET_X86_64
    जर ((t & VT_BTYPE) == VT_LDOUBLE)
        परत RC_ST0;
    जर ((t & VT_BTYPE) == VT_QFLOAT)
        परत RC_FRET;
#किंवाजर defined TCC_TARGET_RISCV64
    जर ((t & VT_BTYPE) == VT_LDOUBLE)
        परत RC_INT;
#endif
    परत RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
स्थिर पूर्णांक RC2_TYPE(पूर्णांक t, पूर्णांक rc)
{
    जर (!USING_TWO_शब्द(t))
        परत 0;
#ifdef RC_IRE2
    जर (rc == RC_IRET)
        परत RC_IRE2;
#endif
#ifdef RC_FRE2
    जर (rc == RC_FRET)
        परत RC_FRE2;
#endif
    जर (rc & RC_FLOAT)
        परत RC_FLOAT;
    परत RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC पूर्णांक ieee_finite(द्विगुण d)
{
    पूर्णांक p[4];
    स_नकल(p, &d, आकार(द्विगुण));
    परत ((अचिन्हित)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC शून्य test_lvalue(शून्य)
{
    जर (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC शून्य check_vstack(शून्य)
{
    जर (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (पूर्णांक)(vtop - vstack + 1));
}

#जर 0
/* dump 'b' vstack entries starting with 'a'  */
शून्य pv (स्थिरांक अक्षर *lbl, पूर्णांक a, पूर्णांक b)
{
    पूर्णांक i;
    साठी (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        म_लिखो("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (पूर्णांक)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
स्थिर ओळीत शून्य psyms(स्थिरांक अक्षर *संदेश, Sym *s, Sym *last)
{
    म_लिखो("%-8s scope         v        c        r   type.t\n", संदेश);
    पर्यंत (s && s != last) {
        म_लिखो("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

स्थिर शून्य type_to_str(अक्षर *buf, पूर्णांक buf_size, CType *type, स्थिरांक अक्षर *varstr);

/* print type */
स्थिर शून्य ptype(स्थिरांक अक्षर *संदेश, CType *type, पूर्णांक v)
{
    अक्षर buf[500];
    type_to_str(buf, आकार(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, रिक्त) : रिक्त);
    म_लिखो("%s : %s;\n", संदेश, buf);
}
#endif

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC शून्य tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    स_रखो(vtop, 0, आकार *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    जर (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_ढकला(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#ifdef precedence_parser
    init_prec();
#endif
    cstr_new(&initstr);
}

ST_FUNC पूर्णांक tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = DATA_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_अभिव्यक्ती = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif
#ifdef INC_DEBUG
    म_लिखो("%s: **** new file\n", file->filename);
#endif
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_अंक | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#जर TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#endif
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    परत 0;
}

ST_FUNC शून्य tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_काढा(&global_चळत, रिक्त, 0);
    sym_काढा(&local_चळत, रिक्त, 0);
    /* free preprocessor macros */
    free_defines(रिक्त);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_data, &nb_stk_data);
    पर्यंत (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = रिक्त;
    all_cleanups = रिक्त;
    pending_gotos = रिक्त;
    nb_temp_local_vars = 0;
    global_label_चळत = रिक्त;
    local_label_चळत = रिक्त;
    cur_text_section = रिक्त;
    sym_free_first = रिक्त;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  जर (!s || !s->c)
    परत रिक्त;
  परत &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC शून्य update_storage(Sym *sym)
{
    ElfSym *esym;
    पूर्णांक sym_bind, old_sym_bind;

    esym = elfsym(sym);
    जर (!esym)
        परत;

    जर (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    जर (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    अन्यथा जर (sym->a.weak)
        sym_bind = STB_WEAK;
    अन्यथा
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    जर (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#ifdef TCC_TARGET_PE
    जर (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    जर (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#endif

#जर 0
    म_लिखो("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
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

ST_FUNC शून्य put_extern_sym2(Sym *sym, पूर्णांक sh_अंक,
                            addr_t मूल्य, अचिन्हित दीर्घ size,
                            पूर्णांक can_add_underscore)
{
    पूर्णांक sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    स्थिरांक अक्षर *name;
    अक्षर buf1[256];

    जर (!sym->c) {
        name = get_tok_str(sym->v, रिक्त);
        t = sym->type.t;
        जर ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } अन्यथा जर ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            जर (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } अन्यथा जर (t & VT_TLS) {
            sym_type = STT_TLS;
        } अन्यथा {
            sym_type = STT_OBJECT;
        }
        जर (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        अन्यथा
            sym_bind = STB_GLOBAL;
        other = 0;

#ifdef TCC_TARGET_PE
        जर (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            जर (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            जर (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                प्र_लिखो(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif

        जर (sym->asm_label) {
            name = get_tok_str(sym->asm_label, रिक्त);
            can_add_underscore = 0;
        }

        जर (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, आकार(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, मूल्य, size, info, other, sh_अंक, name);

        जर (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_अंक, sym_bind, sym_type);

    } अन्यथा {
        esym = elfsym(sym);
        esym->st_मूल्य = मूल्य;
        esym->st_size = size;
        esym->st_shndx = sh_अंक;
    }
    update_storage(sym);
}

ST_FUNC शून्य put_extern_sym(Sym *sym, Section *s, addr_t मूल्य, अचिन्हित दीर्घ size)
{
    जर (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        परत;
    put_extern_sym2(sym, s ? s->sh_अंक : SHN_UNDEF, मूल्य, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC शून्य greloca(Section *s, Sym *sym, अचिन्हित दीर्घ offset, पूर्णांक type,
                     addr_t addend)
{
    पूर्णांक c = 0;

    जर (nocode_wanted && s == cur_text_section)
        परत;

    जर (sym) {
        जर (0 == sym->c) {
            put_extern_sym(sym, रिक्त, 0, 0);
            जर (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                पर्यंत (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#जर PTR_SIZE == 4
ST_FUNC शून्य greloc(Section *s, Sym *sym, अचिन्हित दीर्घ offset, पूर्णांक type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */
/* symbol allocator */
स्थिर Sym *__sym_malloc(शून्य)
{
    Sym *sym_pool, *sym, *last_sym;
    पूर्णांक i;

    sym_pool = tcc_malloc(SYM_POOL_NB * आकार(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    साठी(i = 0; i < SYM_POOL_NB; i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    परत last_sym;
}

स्थिर ओळीत Sym *sym_malloc(शून्य)
{
    Sym *sym;
#ifndef SYM_DEBUG
    sym = sym_free_first;
    जर (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    परत sym;
#अन्यथा
    sym = tcc_malloc(आकार(Sym));
    परत sym;
#endif
}

ST_INLN शून्य sym_free(Sym *sym)
{
#ifndef SYM_DEBUG
    sym->next = sym_free_first;
    sym_free_first = sym;
#अन्यथा
    tcc_free(sym);
#endif
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, पूर्णांक v, पूर्णांक t, पूर्णांक c)
{
    Sym *s;

    s = sym_malloc();
    स_रखो(s, 0, आकार *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    परत s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, पूर्णांक v)
{
    पर्यंत (s) {
        जर (s->v == v)
            परत s;
        s = s->prev;
    }
    परत रिक्त;
}

/* structure lookup */
ST_INLN Sym *struct_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    जर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        परत रिक्त;
    परत table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    जर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        परत रिक्त;
    परत table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
स्थिर ओळीत शून्य sym_link(Sym *s, पूर्णांक yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    जर (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    अन्यथा
        ps = &ts->sym_identifier;
    जर (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } अन्यथा {
        *ps = s->prev_tok;
    }
}

स्थिर ओळीत पूर्णांक sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    परत IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_ढकला(पूर्णांक v, CType *type, पूर्णांक r, पूर्णांक c)
{
    Sym *s, **ps;
    जर (local_चळत)
        ps = &local_चळत;
    अन्यथा
        ps = &global_चळत;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    जर ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        जर (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, रिक्त));
    }
    परत s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_ढकला(पूर्णांक v, पूर्णांक t, पूर्णांक c)
{
    Sym *s, **ps;
    s = sym_push2(&global_चळत, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    जर (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        पर्यंत (*ps != रिक्त && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    परत s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC शून्य sym_काढा(Sym **ptop, Sym *b, पूर्णांक keep)
{
    Sym *s, *ss;
    पूर्णांक v;

    s = *ptop;
    पर्यंत(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        जर ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	जर (!keep)
	    sym_free(s);
        s = ss;
    }
    जर (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    जर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        परत रिक्त;
    परत table_ident[v]->sym_label;
}

ST_FUNC Sym *label_ढकला(Sym **ptop, पूर्णांक v, पूर्णांक flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    जर (ptop == &global_label_चळत) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        पर्यंत (*ps != रिक्त)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    परत s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC शून्य label_काढा(Sym **ptop, Sym *slast, पूर्णांक keep)
{
    Sym *s, *s1;
    साठी(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        जर (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, रिक्त));
        } अन्यथा जर (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, रिक्त));
        } अन्यथा {
            जर (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        जर (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        जर (!keep)
            sym_free(s);
        अन्यथा
            s->r = LABEL_GONE;
    }
    जर (!keep)
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

    जर (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

स्थिर शून्य vsetc(CType *type, पूर्णांक r, CValue *vc)
{
    जर (vtop >= vstack + (VSTACK_SIZE - 1))
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
    पूर्णांक v;
    v = vtop->r & VT_VALMASK;
#जर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    जर (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } अन्यथा
#endif
    जर (v == VT_CMP) {
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
स्थिर शून्य vpush64(पूर्णांक ty, अचिन्हित दीर्घ दीर्घ v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = रिक्त;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC शून्य vpushi(पूर्णांक v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
स्थिर शून्य vpushs(addr_t v)
{
    vpush64(VT_SIZE_T, v);
}

/* push long long constant */
स्थिर ओळीत शून्य vpushll(दीर्घ दीर्घ v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC शून्य vset(CType *type, पूर्णांक r, पूर्णांक v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

स्थिर शून्य vseti(पूर्णांक r, पूर्णांक v)
{
    CType type;
    type.t = VT_INT;
    type.ref = रिक्त;
    vset(&type, r, v);
}

ST_FUNC शून्य vpushv(SValue *v)
{
    जर (vtop >= vstack + (VSTACK_SIZE - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

स्थिर शून्य vdup(शून्य)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC शून्य vrotb(पूर्णांक n)
{
    SValue tmp;
    जर (--n < 1)
        परत;
    vcheck_cmp();
    tmp = vtop[-n];
    स_हटाओ(vtop - n, vtop - n + 1, आकार *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC शून्य vrott(पूर्णांक n)
{
    SValue tmp;
    जर (--n < 1)
        परत;
    vcheck_cmp();
    tmp = vtop[0];
    स_हटाओ(vtop - n + 1, vtop - n, आकार *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC शून्य vrev(पूर्णांक n)
{
    पूर्णांक i;
    SValue tmp;
    vcheck_cmp();
    साठी (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC शून्य vset_VT_CMP(पूर्णांक op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
स्थिर शून्य vset_VT_JMP(शून्य)
{
    पूर्णांक op = vtop->cmp_op;

    जर (vtop->jtrue || vtop->jfalse) {
        पूर्णांक origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        पूर्णांक inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } अन्यथा {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        जर (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
स्थिर शून्य gvtst_set(पूर्णांक inv, पूर्णांक t)
{
    पूर्णांक *p;

    जर (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        जर (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
स्थिर पूर्णांक gvtst(पूर्णांक inv, पूर्णांक t)
{
    पूर्णांक op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    जर (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    जर (op > 1)
        t = gjmp_cond(op ^ inv, t);
    अन्यथा जर (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    परत t;
}

/* generate a zero or nozero test */
स्थिर शून्य gen_test_zero(पूर्णांक op)
{
    जर (vtop->r == VT_CMP) {
        पूर्णांक j;
        जर (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } अन्यथा {
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
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, अचिन्हित दीर्घ offset, अचिन्हित दीर्घ size)
{
    पूर्णांक v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_ढकला(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, size);
    परत sym;
}

/* push a reference to a section offset by adding a dummy symbol */
स्थिर शून्य vpush_ref(CType *type, Section *sec, अचिन्हित दीर्घ offset, अचिन्हित दीर्घ size)
{
    vpushsym(type, get_sym_ref(type, sec, offset, size));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(पूर्णांक v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    जर (!s) {
        /* push forward reference */
        s = global_identifier_ढकला(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } अन्यथा जर (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    परत s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(पूर्णांक v)
{
    CType ct = { VT_ASM_FUNC, रिक्त };
    परत external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC शून्य vpush_helper_func(पूर्णांक v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
स्थिर शून्य merge_symattr(संरचना SymAttr *sa, संरचना SymAttr *sa1)
{
    जर (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    जर (sa1->visibility != STV_DEFAULT) {
	पूर्णांक vis = sa->visibility;
	जर (vis == STV_DEFAULT
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
    जर (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    जर (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    जर (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    जर (fa1->func_noreturn)
      fa->func_noreturn = 1;
    जर (fa1->func_ctor)
      fa->func_ctor = 1;
    जर (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
स्थिर शून्य merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    जर (ad1->section)
      ad->section = ad1->section;
    जर (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    जर (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    जर (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
स्थिर शून्य patch_type(Sym *sym, CType *type)
{
    जर (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        जर (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, रिक्त));
        sym->type.t &= ~VT_EXTERN;
    }

    जर (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        जर ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    जर (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, रिक्त));

    } अन्यथा जर ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        पूर्णांक static_proto = sym->type.t & VT_STATIC;
        पूर्णांक ft1 = sym->type.ref->f.func_type;
        पूर्णांक ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        जर ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, रिक्त));

        /* set 'inline' if both agree or if one has static */
        जर ((type->t | sym->type.t) & VT_INLINE) {
            जर (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        जर (0 == (type->t & VT_EXTERN)) {
            संरचना FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            जर (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } अन्यथा {
            sym->type.t &= ~VT_INLINE | static_proto;
            जर (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } अन्यथा {
        जर ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        जर ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, रिक्त));
    }
}

/* Merge some storage attributes.  */
स्थिर शून्य patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    जर (type)
        patch_type(sym, type);

#ifdef TCC_TARGET_PE
    जर (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, रिक्त));
#endif
    merge_symattr(&sym->a, &ad->a);
    जर (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
स्थिर Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    जर ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    परत s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
स्थिर शून्य move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    पूर्णांक n, bt;

    bt = s->type.t & VT_BTYPE;
    जर (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        परत;

    साठी (s = s->type.ref, n = 0; s; s = s->next) {
        साठी (lp = &local_चळत; !!(l = *lp); lp = &l->prev) {
            जर (l == s) {
                *lp = s->prev;
                s->prev = global_चळत, global_चळत = s;
                जर (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } अन्यथा {
                    जर ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                जर (bt != VT_PTR)
                    n = 1;
                थांबा;
            }
        }
        जर (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            थांबा;
    }
}

/* define a new external reference to a symbol 'v' */
स्थिर Sym *external_sym(पूर्णांक v, CType *type, पूर्णांक r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    पर्यंत (s && s->sym_scope)
        s = s->prev_tok;

    जर (!s) {
        /* push forward reference */
        s = global_identifier_ढकला(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } अन्यथा {
        patch_storage(s, ad, type);
    }
    जर (local_चळत) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_चळत);
    }
    परत s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC शून्य save_regs(पूर्णांक n)
{
    SValue *p, *p1;
    साठी(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC शून्य save_reg(पूर्णांक r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC शून्य save_reg_upstack(पूर्णांक r, पूर्णांक n)
{
    पूर्णांक l, size, align, bt, r2;
    SValue *p, *p1, sv;

    जर ((r &= VT_VALMASK) >= VT_CONST)
        परत;
    जर (nocode_wanted)
        परत;
    l = r2 = 0;
    साठी(p = vstack, p1 = vtop - n; p <= p1; p++) {
        जर ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            जर (!l) {
                bt = p->type.t & VT_BTYPE;
                जर (bt == VT_VOID)
                    सुरूठेवा;
                जर ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                size = type_size(&sv.type, &align);
                l = get_temp_local_var(size, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = रिक्त;
                store(p->r & VT_VALMASK, &sv);
#जर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                जर (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#endif
                /* special long long case */
                जर (p->r2 < VT_CONST && USING_TWO_शब्द(bt)) {
                    sv.c.i += PTR_SIZE;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            जर (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } अन्यथा {
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
ST_FUNC पूर्णांक get_reg_ex(पूर्णांक rc, पूर्णांक rc2)
{
    पूर्णांक r;
    SValue *p;
    
    साठी(r=0;r<NB_REGS;r++) {
        जर (reg_classes[r] & rc2) {
            पूर्णांक n;
            n=0;
            साठी(p = vstack; p <= vtop; p++) {
                जर ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            जर (n <= 1)
                परत r;
        }
    }
    परत get_reg(rc);
}
#endif

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC पूर्णांक get_reg(पूर्णांक rc)
{
    पूर्णांक r;
    SValue *p;

    /* find a free register */
    साठी(r=0;r<NB_REGS;r++) {
        जर (reg_classes[r] & rc) {
            जर (nocode_wanted)
                परत r;
            साठी(p=vstack;p<=vtop;p++) {
                जर ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    जा notfound;
            }
            परत r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    साठी(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        जर (r < VT_CONST && (reg_classes[r] & rc))
            जा save_found;
        r = p->r & VT_VALMASK;
        जर (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            परत r;
        }
    }
    /* Should never comes here */
    परत -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
स्थिर पूर्णांक get_temp_local_var(पूर्णांक size,पूर्णांक align, पूर्णांक *r2)
{
    पूर्णांक i;
    संरचना temp_local_variable *temp_var;
    SValue *p;
    पूर्णांक r;
    अचिन्हित used = 0;

    /* mark locations that are still in use */
    साठी (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	जर (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    जर (r >= 0 && r < MAX_TEMP_LOCAL_VARIABLE_संख्या)
	        used |= 1<<r;
	}
    }
    साठी (i=0;i<nb_temp_local_vars;i++) {
	temp_var=&arr_temp_local_vars[i];
	जर(!(used & 1<<i)
	 && temp_var->size>=size
	 && temp_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    परत temp_var->location;
	}
    }
    loc = (loc - size) & -align;
    जर (nb_temp_local_vars<MAX_TEMP_LOCAL_VARIABLE_संख्या) {
	temp_var=&arr_temp_local_vars[i];
	temp_var->location=loc;
	temp_var->size=size;
	temp_var->align=align;
	nb_temp_local_vars++;
	जा ret_tmp;
    }
    *r2 = VT_CONST;
    परत loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
स्थिर शून्य move_reg(पूर्णांक r, पूर्णांक s, पूर्णांक t)
{
    SValue sv;

    जर (r != s) {
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
    जर ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#ifdef CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
स्थिर शून्य gen_bounded_ptr_add(शून्य)
{
    पूर्णांक save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    जर (save) {
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
    जर (nocode_wanted)
        परत;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->data_offset - आकार(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
स्थिर शून्य gen_bounded_ptr_deref(शून्य)
{
    addr_t func;
    पूर्णांक size, align;
    ElfW_Rel *rel;
    Sym *sym;

    जर (nocode_wanted)
        परत;

    size = type_size(&vtop->type, &align);
    निवड(size) {
    स्थिती  1: func = TOK___bound_ptr_indir1; थांबा;
    स्थिती  2: func = TOK___bound_ptr_indir2; थांबा;
    स्थिती  4: func = TOK___bound_ptr_indir4; थांबा;
    स्थिती  8: func = TOK___bound_ptr_indir8; थांबा;
    स्थिती 12: func = TOK___bound_ptr_indir12; थांबा;
    स्थिती 16: func = TOK___bound_ptr_indir16; थांबा;
    पूर्वनिर्धारित:
        /* may happen with struct member access */
        परत;
    }
    sym = external_helper_sym(func);
    जर (!sym->c)
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
    जर (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        जर (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC शून्य gbound_args(पूर्णांक nb_args)
{
    पूर्णांक i, v;
    SValue *sv;

    साठी (i = 1; i <= nb_args; ++i)
        जर (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    जर (sv->r & VT_SYM) {
        v = sv->sym->v;
        जर (v == TOK_setjmp
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
        जर (v == TOK_alloca)
            func_bound_add_epilog = 1;
#जर TARGETOS_NetBSD
        जर (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#endif
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
स्थिर शून्य add_local_bounds(Sym *s, Sym *e)
{
    साठी (; s != e; s = s->prev) {
        जर (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          सुरूठेवा;
        /* Add arrays/structs/unions because we always take address */
        जर ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            पूर्णांक align, size = type_size(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * आकार(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = size;
        }
    }
}
#endif

/* add debug info for locals or function parameters, optionally
   register bounds */
स्थिर शून्य tcc_debug_end_scope(Sym *b, पूर्णांक bounds)
{
#ifdef CONFIG_TCC_BCHECK
    जर (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_चळत, b);
#endif
    tcc_add_debug_info (tcc_state, local_चळत, b);
}

/* increment an lvalue pointer */
स्थिर शून्य incr_offset(पूर्णांक offset)
{
    पूर्णांक t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

स्थिर शून्य incr_bf_adr(पूर्णांक o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
स्थिर शून्य load_packed_bf(CType *type, पूर्णांक bit_pos, पूर्णांक bit_size)
{
    पूर्णांक n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    करा {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        जर (n > bit_size)
            n = bit_size;
        जर (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        जर (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        जर (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_size -= n, o = 1;
    } पर्यंत (bit_size);
    vswap(), vpop();
    जर (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
स्थिर शून्य store_packed_bf(पूर्णांक bit_pos, पूर्णांक bit_size)
{
    पूर्णांक bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    करा {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        जर (bits)
            vpushi(bits), gen_op(TOK_SHR);
        जर (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        जर (n > bit_size)
            n = bit_size;
        जर (n < 8) {
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
    } पर्यंत (bit_size);
    vpop(), vpop();
}

स्थिर पूर्णांक adjust_bf(SValue *sv, पूर्णांक bit_pos, पूर्णांक bit_size)
{
    पूर्णांक t;
    जर (0 == sv->type.ref)
        परत 0;
    t = sv->type.ref->auxtype;
    जर (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    परत t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC पूर्णांक gv(पूर्णांक rc)
{
    पूर्णांक r, r2, r_ok, r2_ok, rc2, bt;
    पूर्णांक bit_pos, bit_size, size, align;

    /* NOTE: get_reg can modify vstack[] */
    जर (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_size = BIT_SIZE(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = रिक्त;
        type.t = vtop->type.t & VT_UNSIGNED;
        जर ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_size);

        जर ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        अन्यथा
            type.t |= VT_INT;

        जर (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_size);
        } अन्यथा {
            पूर्णांक bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
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
    } अन्यथा {
        जर (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            अचिन्हित दीर्घ offset;
            size = type_size(&vtop->type, &align);
            जर (NODATA_WANTED)
                size = 0, align = 1;
            offset = section_add(p.sec, size, align);
            vpush_ref(&vtop->type, p.sec, offset, size);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#ifdef CONFIG_TCC_BCHECK
        जर (vtop->r & VT_MUSTBOUND) 
            gbound();
#endif

        bt = vtop->type.t & VT_BTYPE;
        जर (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            परत vtop->r;

#ifdef TCC_TARGET_RISCV64
        /* XXX mega hack */
        जर (bt == VT_LDOUBLE && rc == RC_FLOAT)
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

        जर (!r_ok || !r2_ok) {

            जर (!r_ok) {
                जर (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                अन्यथा
                    r = get_reg(rc);
            }

            जर (rc2) {
                पूर्णांक load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                पूर्णांक original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                जर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    अचिन्हित दीर्घ दीर्घ ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } अन्यथा जर (vtop->r & VT_LVAL) {
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
                } अन्यथा {
                    /* move registers */
                    जर (!r_ok)
                        load(r, vtop);
                    जर (r2_ok && vtop->r2 < VT_CONST)
                        जा done;
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
            } अन्यथा {
                जर (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#ifdef TCC_TARGET_C67
        /* uses register pairs for doubles */
        जर (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#endif
    }
    परत r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC शून्य gv2(पूर्णांक rc1, पूर्णांक rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    जर (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        जर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } अन्यथा {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        जर ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#जर PTR_SIZE == 4
/* expand 64bit on stack in two ints */
ST_FUNC शून्य lexpand(शून्य)
{
    पूर्णांक u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    जर (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } अन्यथा जर (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } अन्यथा {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#endif

#जर PTR_SIZE == 4
/* build a long long from two ints */
स्थिर शून्य lbuild(पूर्णांक t)
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
    पूर्णांक t, rc, r;

    t = vtop->type.t;
#जर PTR_SIZE == 4
    जर ((t & VT_BTYPE) == VT_LLONG) {
        जर (t & VT_BITFIELD) {
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
        परत;
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

#जर PTR_SIZE == 4
/* generate CPU independent (unsigned) long long operations */
स्थिर शून्य gen_opl(पूर्णांक op)
{
    पूर्णांक t, a, b, op1, c, i;
    पूर्णांक func;
    अचिन्हित लघु reg_iret = REG_IRET;
    अचिन्हित लघु reg_lret = REG_IRE2;
    SValue tmp;

    निवड(op) {
    स्थिती '/':
    स्थिती TOK_PDIV:
        func = TOK___divdi3;
        जा gen_func;
    स्थिती TOK_UDIV:
        func = TOK___udivdi3;
        जा gen_func;
    स्थिती '%':
        func = TOK___moddi3;
        जा gen_mod_func;
    स्थिती TOK_UMOD:
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
        थांबा;
    स्थिती '^':
    स्थिती '&':
    स्थिती '|':
    स्थिती '*':
    स्थिती '+':
    स्थिती '-':
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
        जर (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            साठी(i=0;i<4;i++)
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
        } अन्यथा जर (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            जर (op == '+')
                op1 = TOK_ADDC1;
            अन्यथा
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } अन्यथा {
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
        थांबा;
    स्थिती TOK_SAR:
    स्थिती TOK_SHR:
    स्थिती TOK_SHL:
        जर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (पूर्णांक)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            जर (op != TOK_SHL)
                vswap();
            जर (c >= 32) {
                /* stack: L H */
                vpop();
                जर (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                जर (op != TOK_SAR) {
                    vpushi(0);
                } अन्यथा {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } अन्यथा {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                जर (op == TOK_SHL)
                    gen_op(TOK_SHR);
                अन्यथा
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                जर (op == TOK_SHL)
                    gen_op(TOK_SHL);
                अन्यथा
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            जर (op != TOK_SHL)
                vswap();
            lbuild(t);
        } अन्यथा {
            /* XXX: should provide a faster fallback on x86 ? */
            निवड(op) {
            स्थिती TOK_SAR:
                func = TOK___ashrdi3;
                जा gen_func;
            स्थिती TOK_SHR:
                func = TOK___lshrdi3;
                जा gen_func;
            स्थिती TOK_SHL:
                func = TOK___ashldi3;
                जा gen_func;
            }
        }
        थांबा;
    पूर्वनिर्धारित:
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
        जर (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        जर (op1 == TOK_LT)
            op1 = TOK_LE;
        अन्यथा जर (op1 == TOK_GT)
            op1 = TOK_GE;
        अन्यथा जर (op1 == TOK_ULT)
            op1 = TOK_ULE;
        अन्यथा जर (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        जर (op == TOK_NE) {
            b = gvtst(0, 0);
        } अन्यथा {
            a = gvtst(1, 0);
            जर (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        जर (op1 == TOK_LT)
            op1 = TOK_ULT;
        अन्यथा जर (op1 == TOK_LE)
            op1 = TOK_ULE;
        अन्यथा जर (op1 == TOK_GT)
            op1 = TOK_UGT;
        अन्यथा जर (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#जर 0//def TCC_TARGET_I386
        जर (op == TOK_NE) { gsym(b); थांबा; }
        जर (op == TOK_EQ) { gsym(a); थांबा; }
#endif
        gvtst_set(1, a);
        gvtst_set(0, b);
        थांबा;
    }
}
#endif

/* normalize values */
स्थिर uint64_t value64(uint64_t l1, पूर्णांक t)
{
    जर ((t & VT_BTYPE) == VT_LLONG
        || (PTR_SIZE == 8 && (t & VT_BTYPE) == VT_PTR))
        परत l1;
    अन्यथा जर (t & VT_UNSIGNED)
        परत (uint32_t)l1;
    अन्यथा
        परत (uint32_t)l1 | -(l1 & 0x80000000);
}

स्थिर uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    परत (a ^ b) >> 63 ? -x : x;
}

स्थिर पूर्णांक gen_opic_lt(uint64_t a, uint64_t b)
{
    परत (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
स्थिर शून्य gen_opic(पूर्णांक op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    पूर्णांक t1 = v1->type.t & VT_BTYPE;
    पूर्णांक t2 = v2->type.t & VT_BTYPE;
    पूर्णांक c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    पूर्णांक c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    पूर्णांक shm = (t1 == VT_LLONG) ? 63 : 31;
    पूर्णांक r;

    जर (c1 && c2) {
        निवड(op) {
        स्थिती '+': l1 += l2; थांबा;
        स्थिती '-': l1 -= l2; थांबा;
        स्थिती '&': l1 &= l2; थांबा;
        स्थिती '^': l1 ^= l2; थांबा;
        स्थिती '|': l1 |= l2; थांबा;
        स्थिती '*': l1 *= l2; थांबा;

        स्थिती TOK_PDIV:
        स्थिती '/':
        स्थिती '%':
        स्थिती TOK_UDIV:
        स्थिती TOK_UMOD:
            /* if division by zero, generate explicit division */
            जर (l2 == 0) {
                जर (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                जा general_case;
            }
            निवड(op) {
            पूर्वनिर्धारित: l1 = gen_opic_sdiv(l1, l2); थांबा;
            स्थिती '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); थांबा;
            स्थिती TOK_UDIV: l1 = l1 / l2; थांबा;
            स्थिती TOK_UMOD: l1 = l1 % l2; थांबा;
            }
            थांबा;
        स्थिती TOK_SHL: l1 <<= (l2 & shm); थांबा;
        स्थिती TOK_SHR: l1 >>= (l2 & shm); थांबा;
        स्थिती TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            थांबा;
            /* tests */
        स्थिती TOK_ULT: l1 = l1 < l2; थांबा;
        स्थिती TOK_UGE: l1 = l1 >= l2; थांबा;
        स्थिती TOK_EQ: l1 = l1 == l2; थांबा;
        स्थिती TOK_NE: l1 = l1 != l2; थांबा;
        स्थिती TOK_ULE: l1 = l1 <= l2; थांबा;
        स्थिती TOK_UGT: l1 = l1 > l2; थांबा;
        स्थिती TOK_LT: l1 = gen_opic_lt(l1, l2); थांबा;
        स्थिती TOK_GE: l1 = !gen_opic_lt(l1, l2); थांबा;
        स्थिती TOK_LE: l1 = !gen_opic_lt(l2, l1); थांबा;
        स्थिती TOK_GT: l1 = gen_opic_lt(l2, l1); थांबा;
            /* logical */
        स्थिती TOK_LAND: l1 = l1 && l2; थांबा;
        स्थिती TOK_LOR: l1 = l1 || l2; थांबा;
        पूर्वनिर्धारित:
            जा general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } अन्यथा {
        /* if commutative ops, put c2 as constant */
        जर (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        जर (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } अन्यथा जर (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            जर (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } अन्यथा जर (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } अन्यथा जर (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            जर (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                पूर्णांक n = -1;
                जर (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    जा general_case;
                }
                पर्यंत (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                जर (op == '*')
                    op = TOK_SHL;
                अन्यथा जर (op == TOK_PDIV)
                    op = TOK_SAR;
                अन्यथा
                    op = TOK_SHR;
            }
            जा general_case;
        } अन्यथा जर (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            जर (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    जर ((पूर्णांक)l2 != l2)
	        जा general_case;
            vtop--;
            vtop->c.i = l2;
        } अन्यथा {
        general_case:
                /* call low level op generator */
                जर (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                अन्यथा
                    gen_opi(op);
        }
        जर (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#जर defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#किंवाजर defined TCC_TARGET_ARM
शून्य gen_negf(पूर्णांक op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#अन्यथा
/* XXX: implement in gen_opf() for other backends too */
शून्य gen_negf(पूर्णांक op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    पूर्णांक align, size, bt;
    size = type_size(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#जर defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    जर (bt == VT_LDOUBLE)
        size = 10;
#endif
    जर (nocode_wanted) /* save_reg() wont work */
        जा gv2;
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
स्थिर शून्य gen_opif(पूर्णांक op)
{
    पूर्णांक c1, c2, i, bt;
    SValue *v1, *v2;
#जर defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    अस्थिर
#endif
    दीर्घ द्विगुण f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    जर (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    जर (c1 && c2) {
        जर (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } अन्यथा जर (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } अन्यथा {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        जर (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            जा general_case;
        निवड(op) {
        स्थिती '+': f1 += f2; थांबा;
        स्थिती '-': f1 -= f2; थांबा;
        स्थिती '*': f1 *= f2; थांबा;
        स्थिती '/': 
            जर (f2 == 0.0) {
                संघ { दशांश f; अचिन्हित u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                जर (!CONST_WANTED)
                    जा general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                जर (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                अन्यथा
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                थांबा;
            }
            f1 /= f2;
            थांबा;
        स्थिती TOK_NEG:
            f1 = -f1;
            जा unary_result;
        स्थिती TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            परत;
        स्थिती TOK_NE:
            i = f1 != f2;
	    जा make_int;
        स्थिती TOK_LT:
            i = f1 < f2;
	    जा make_int;
        स्थिती TOK_GE:
            i = f1 >= f2;
	    जा make_int;
        स्थिती TOK_LE:
            i = f1 <= f2;
	    जा make_int;
        स्थिती TOK_GT:
            i = f1 > f2;
	    जा make_int;
        पूर्वनिर्धारित:
            जा general_case;
        }
        vtop--;
    unary_result:
        /* XXX: overflow test ? */
        जर (bt == VT_FLOAT) {
            v1->c.f = f1;
        } अन्यथा जर (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } अन्यथा {
            v1->c.ld = f1;
        }
    } अन्यथा {
    general_case:
        जर (op == TOK_NEG) {
            gen_negf(op);
        } अन्यथा {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
स्थिर शून्य type_to_str(अक्षर *buf, पूर्णांक buf_size,
                 CType *type, स्थिरांक अक्षर *varstr)
{
    पूर्णांक bt, v, t;
    Sym *s, *sa;
    अक्षर buf1[256];
    स्थिरांक अक्षर *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    जर (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    जर (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    जर (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    जर (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    जर (bt != VT_PTR) {
        जर (t & VT_RESTRICT)
            pstrcat(buf, buf_size, "restrict ");
        जर (t & VT_VOLATILE)
            pstrcat(buf, buf_size, "volatile ");
        जर (t & VT_CONSTANT)
            pstrcat(buf, buf_size, "const ");
    }
    जर (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= म_माप(buf);
    buf += म_माप(buf);

    निवड(bt) {
    स्थिती VT_VOID:
        tstr = "void";
        जा add_tstr;
    स्थिती VT_BOOL:
        tstr = "_Bool";
        जा add_tstr;
    स्थिती VT_BYTE:
        tstr = "char";
        जा add_tstr;
    स्थिती VT_SHORT:
        tstr = "short";
        जा add_tstr;
    स्थिती VT_INT:
        tstr = "int";
        जा maybe_long;
    स्थिती VT_LLONG:
        tstr = "long long";
    maybe_long:
        जर (t & VT_LONG)
            tstr = "long";
        जर (!IS_ENUM(t))
            जा add_tstr;
        tstr = "enum ";
        जा tstruct;
    स्थिती VT_FLOAT:
        tstr = "float";
        जा add_tstr;
    स्थिती VT_DOUBLE:
        tstr = "double";
        जर (!(t & VT_LONG))
            जा add_tstr;
    स्थिती VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        थांबा;
    स्थिती VT_STRUCT:
        tstr = "struct ";
        जर (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        जर (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        अन्यथा
            pstrcat(buf, buf_size, get_tok_str(v, रिक्त));
        थांबा;
    स्थिती VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        जर (varstr && '*' == *varstr) {
            pstrcat(buf1, आकार(buf1), "(");
            pstrcat(buf1, आकार(buf1), varstr);
            pstrcat(buf1, आकार(buf1), ")");
        }
        pstrcat(buf1, आकार(buf1), "(");
        sa = s->next;
        पर्यंत (sa != रिक्त) {
            अक्षर buf2[256];
            type_to_str(buf2, आकार(buf2), &sa->type, रिक्त);
            pstrcat(buf1, आकार(buf1), buf2);
            sa = sa->next;
            जर (sa)
                pstrcat(buf1, आकार(buf1), ", ");
        }
        जर (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, आकार(buf1), ", ...");
        pstrcat(buf1, आकार(buf1), ")");
        type_to_str(buf, buf_size, &s->type, buf1);
        जा no_var;
    स्थिती VT_PTR:
        s = type->ref;
        जर (t & (VT_ARRAY|VT_VLA)) {
            जर (varstr && '*' == *varstr)
                snprintf(buf1, आकार(buf1), "(%s)[%d]", varstr, s->c);
            अन्यथा
                snprintf(buf1, आकार(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            जा no_var;
        }
        pstrcpy(buf1, आकार(buf1), "*");
        जर (t & VT_RESTRICT)
            pstrcat(buf1, आकार(buf1), "restrict ");
        जर (t & VT_CONSTANT)
            pstrcat(buf1, आकार(buf1), "const ");
        जर (t & VT_VOLATILE)
            pstrcat(buf1, आकार(buf1), "volatile ");
        जर (varstr)
            pstrcat(buf1, आकार(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        जा no_var;
    }
    जर (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

स्थिर शून्य type_incompatibility_error(CType* st, CType* dt, स्थिरांक अक्षर* fmt)
{
    अक्षर buf1[256], buf2[256];
    type_to_str(buf1, आकार(buf1), st, रिक्त);
    type_to_str(buf2, आकार(buf2), dt, रिक्त);
    tcc_error(fmt, buf1, buf2);
}

स्थिर शून्य type_incompatibility_warning(CType* st, CType* dt, स्थिरांक अक्षर* fmt)
{
    अक्षर buf1[256], buf2[256];
    type_to_str(buf1, आकार(buf1), st, रिक्त);
    type_to_str(buf2, आकार(buf2), dt, रिक्त);
    tcc_warning(fmt, buf1, buf2);
}

स्थिर पूर्णांक pointed_size(CType *type)
{
    पूर्णांक align;
    परत type_size(pointed_type(type), &align);
}

स्थिर ओळीत पूर्णांक is_null_pointer(SValue *p)
{
    जर ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        परत 0;
    परत ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_SIZE == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
स्थिर पूर्णांक is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    जर (s1->f.func_call != s2->f.func_call)
        परत 0;
    जर (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        परत 0;
    साठी (;;) {
        जर (!is_compatible_unqualified_types(&s1->type, &s2->type))
            परत 0;
        जर (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            परत 1;
        s1 = s1->next;
        s2 = s2->next;
        जर (!s1)
            परत !s2;
        जर (!s2)
            परत 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
स्थिर पूर्णांक compare_types(CType *type1, CType *type2, पूर्णांक unqualified)
{
    पूर्णांक bt1, t1, t2;

    जर (IS_ENUM(type1->t)) {
        जर (IS_ENUM(type2->t))
            परत type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } अन्यथा जर (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    जर (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    जर ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    जर (t1 != t2)
        परत 0;

    जर ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            परत 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    जर (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        जर (unqualified && (t1 & VT_ARRAY))
            परत compare_types(type1, type2, 1);
        परत is_compatible_types(type1, type2);
    } अन्यथा जर (bt1 == VT_STRUCT) {
        परत (type1->ref == type2->ref);
    } अन्यथा जर (bt1 == VT_FUNC) {
        परत is_compatible_func(type1, type2);
    } अन्यथा {
        परत 1;
    }
}

#define CMP_OP 'C'
#define SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
स्थिर पूर्णांक combine_types(CType *dest, SValue *op1, SValue *op2, पूर्णांक op)
{
    CType *type1, *type2, type;
    पूर्णांक t1, t2, bt1, bt2;
    पूर्णांक ret = 1;

    /* for shifts, 'combine' only left operand */
    जर (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = रिक्त;

    जर (bt1 == VT_VOID || bt2 == VT_VOID) {
        जर (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } अन्यथा जर (bt1 == VT_PTR || bt2 == VT_PTR) {
        जर (op == '+') {
          जर (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        अन्यथा जर (is_null_pointer (op2)) type = *type1;
        अन्यथा जर (is_null_pointer (op1)) type = *type2;
        अन्यथा जर (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            जर ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            अन्यथा जर (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } अन्यथा {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            पूर्णांक pbt1 = pt1->t & VT_BTYPE;
            पूर्णांक pbt2 = pt2->t & VT_BTYPE;
            पूर्णांक newquals, copied = 0;
            जर (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                जर (op != '?' && op != CMP_OP)
                  ret = 0;
                अन्यथा
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            जर (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                जर ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_ढकला(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                जर (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    जर (!copied)
                      type.ref = sym_ढकला(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_ढकला(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        जर (op == CMP_OP)
          type.t = VT_SIZE_T;
    } अन्यथा जर (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        जर (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } अन्यथा जर (is_float(bt1) || is_float(bt2)) {
        जर (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } अन्यथा जर (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } अन्यथा {
            type.t = VT_FLOAT;
        }
    } अन्यथा जर (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        जर (bt1 == VT_LLONG)
          type.t &= t1;
        जर (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        जर ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } अन्यथा {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        जर (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_SIZE(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_SIZE(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    जर (dest)
      *dest = type;
    परत ret;
}

/* generic gen_op: handles types problems */
ST_FUNC शून्य gen_op(पूर्णांक op)
{
    पूर्णांक t1, t2, bt1, bt2, t;
    CType type1, combtype;
    पूर्णांक op_class = op;

    जर (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    अन्यथा जर (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    जर (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	जर (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	जर (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	जा redo;
    } अन्यथा जर (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } अन्यथा जर (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        पूर्णांक align;
        जर (op_class == CMP_OP)
            जा std_op;
        /* if both pointers, then it must be the '-' op */
        जर (bt1 == VT_PTR && bt2 == VT_PTR) {
            जर (op != '-')
                जा op_err;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } अन्यथा {
            /* exactly one pointer : must be '+' or '-'. */
            जर (op != '-' && op != '+')
                जा op_err;
            /* Put pointer as first operand */
            जर (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#जर PTR_SIZE == 4
            जर (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#endif
            type1 = vtop[-1].type;
            vpush_type_size(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#ifdef CONFIG_TCC_BCHECK
            जर (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                जर (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } अन्यथा
#endif
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } अन्यथा {
        /* floats can only be used for a few operations */
        जर (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            जा op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        जर (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        जर (t & VT_UNSIGNED) {
            जर (op == TOK_SAR)
                op = TOK_SHR;
            अन्यथा जर (op == '/')
                op = TOK_UDIV;
            अन्यथा जर (op == '%')
                op = TOK_UMOD;
            अन्यथा जर (op == TOK_LT)
                op = TOK_ULT;
            अन्यथा जर (op == TOK_GT)
                op = TOK_UGT;
            अन्यथा जर (op == TOK_LE)
                op = TOK_ULE;
            अन्यथा जर (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        जर (is_float(t))
            gen_opif(op);
        अन्यथा
            gen_opic(op);
        जर (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } अन्यथा {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    जर (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#जर defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#define gen_cvt_itof1 gen_cvt_itof
#अन्यथा
/* generic itof for unsigned long long case */
स्थिर शून्य gen_cvt_itof1(पूर्णांक t)
{
    जर ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        जर (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#जर LDOUBLE_SIZE != 8
        अन्यथा जर (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#endif
        अन्यथा
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } अन्यथा {
        gen_cvt_itof(t);
    }
}
#endif

#जर defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#define gen_cvt_ftoi1 gen_cvt_ftoi
#अन्यथा
/* generic ftoi for unsigned long long case */
स्थिर शून्य gen_cvt_ftoi1(पूर्णांक t)
{
    पूर्णांक st;
    जर (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        जर (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#जर LDOUBLE_SIZE != 8
        अन्यथा जर (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#endif
        अन्यथा
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } अन्यथा {
        gen_cvt_ftoi(t);
    }
}
#endif

/* special delayed cast for char/short */
स्थिर शून्य force_charshort_cast(शून्य)
{
    पूर्णांक sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    पूर्णांक dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

स्थिर शून्य gen_cast_s(पूर्णांक t)
{
    CType type;
    type.t = t;
    type.ref = रिक्त;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
स्थिर शून्य gen_cast(CType *type)
{
    पूर्णांक sbt, dbt, sf, df, c;
    पूर्णांक dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    जर (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    जर (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    जर (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    जर (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    जर (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        जर (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            जा done;
        }
        जर (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        जर (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            जर (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            अन्यथा जर (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            जर (df) {
                जर (sbt_bt == VT_LLONG) {
                    जर ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    अन्यथा
                        vtop->c.ld = -(दीर्घ द्विगुण)-vtop->c.i;
                } अन्यथा जर(!sf) {
                    जर ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    अन्यथा
                        vtop->c.ld = -(दीर्घ द्विगुण)-(uint32_t)vtop->c.i;
                }

                जर (dbt == VT_FLOAT)
                    vtop->c.f = (दशांश)vtop->c.ld;
                अन्यथा जर (dbt == VT_DOUBLE)
                    vtop->c.d = (द्विगुण)vtop->c.ld;
            } अन्यथा जर (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } अन्यथा {
                जर(sf) {
                    जर (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    अन्यथा
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                अन्यथा जर (sbt_bt == VT_LLONG || (PTR_SIZE == 8 && sbt == VT_PTR))
                    ;
                अन्यथा जर (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                अन्यथा
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                जर (dbt_bt == VT_LLONG || (PTR_SIZE == 8 && dbt == VT_PTR))
                    ;
                अन्यथा जर (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                अन्यथा {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    जर (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            जा done;

        } अन्यथा जर (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            जा done;
        }

        /* cannot generate code for global or static initializers */
        जर (nocode_wanted & DATA_ONLY_WANTED) {
            जर (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            जा done;
        }

        /* non constant case: generate code */
        जर (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            जा done;
        }

        जर (sf || df) {
            जर (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } अन्यथा जर (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } अन्यथा {
                /* convert fp to int */
                sbt = dbt;
                जर (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                जा again; /* may need char/short cast */
            }
            जा done;
        }

        ds = btype_size(dbt_bt);
        ss = btype_size(sbt_bt);
        जर (ds == 0 || ss == 0)
            जा error;

        /* same size and no sign conversion needed */
        जर (ds == ss && ds >= 4)
            जा done;
        जर (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            जर (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_SIZE == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #define ALLOW_SUBTYPE_ACCESS 1

        जर (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            जर (ds <= ss)
                जा done;
            /* ss <= 4 here */
            जर (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                जा done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#जर PTR_SIZE == 4
        जर (ds == 8) {
            /* generate high word */
            जर (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } अन्यथा {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } अन्यथा जर (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#किंवाजर PTR_SIZE == 8
        जर (ds == 8) {
            /* need to convert from 32bit to 64bit */
            जर (sbt & VT_UNSIGNED) {
#जर defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#अन्यथा
                जा done;
#endif
            } अन्यथा {
                gen_cvt_sxtw();
                जा done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } अन्यथा जर (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#जर !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#endif
        } अन्यथा {
            ss = 4;
        }
#endif

        जर (ds >= ss)
            जा done;
#जर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    जर (ss == 4) {
        gen_cvt_csti(dbt);
        जा done;
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
ST_FUNC पूर्णांक type_size(CType *type, पूर्णांक *a)
{
    Sym *s;
    पूर्णांक bt;

    bt = type->t & VT_BTYPE;
    जर (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        परत s->c;
    } अन्यथा जर (bt == VT_PTR) {
        जर (type->t & VT_ARRAY) {
            पूर्णांक ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            जर (s->c < 0)
                परत s->c;
            परत ts * s->c;
        } अन्यथा {
            *a = PTR_SIZE;
            परत PTR_SIZE;
        }
    } अन्यथा जर (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        परत -1; /* incomplete enum */
    } अन्यथा जर (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        परत LDOUBLE_SIZE;
    } अन्यथा जर (bt == VT_DOUBLE || bt == VT_LLONG) {
#जर (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#अन्यथा
        *a = 8;
#endif
        परत 8;
    } अन्यथा जर (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        परत 4;
    } अन्यथा जर (bt == VT_SHORT) {
        *a = 2;
        परत 2;
    } अन्यथा जर (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        परत 16;
    } अन्यथा {
        /* char, void, function, _Bool */
        *a = 1;
        परत 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
स्थिर शून्य vpush_type_size(CType *type, पूर्णांक *a)
{
    जर (type->t & VT_VLA) {
        type_size(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } अन्यथा {
        पूर्णांक size = type_size(type, a);
        जर (size < 0)
            tcc_error("unknown type size");
        vpushs(size);
    }
}

/* return the pointed type of t */
स्थिर ओळीत CType *pointed_type(CType *type)
{
    परत &type->ref->type;
}

स्थिर शून्य check_restrict_type(CType *type)
{
    पर्यंत ((type->t & VT_BTYPE) == VT_PTR) {
        जर ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    जर (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
स्थिर पूर्णांक type_qualifiers(CType *type)
{
    पर्यंत (type->t & VT_ARRAY)
        type = pointed_type(type);
    परत type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC शून्य mk_pointer(CType *type)
{
    Sym *s;
    s = sym_ढकला(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
स्थिर पूर्णांक is_compatible_types(CType *type1, CType *type2)
{
    परत compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
स्थिर पूर्णांक is_compatible_unqualified_types(CType *type1, CType *type2)
{
    परत compare_types(type1,type2,1);
}

स्थिर शून्य cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
स्थिर शून्य verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    पूर्णांक dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    जर (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    निवड(dbt) {
    स्थिती VT_VOID:
        जर (sbt != dbt)
            tcc_error("assignment to void expression");
        थांबा;
    स्थिती VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        जर (is_null_pointer(vtop))
            थांबा;
        /* accept implicit pointer to integer cast with warning */
        जर (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            थांबा;
        }
        type1 = pointed_type(dt);
        जर (sbt == VT_PTR)
            type2 = pointed_type(st);
        अन्यथा जर (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        अन्यथा
            जा error;
        जर (is_compatible_types(type1, type2))
            थांबा;
        साठी (qualwarn = lvl = 0;; ++lvl) {
            जर ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            जर (dbt != VT_PTR || sbt != VT_PTR)
                थांबा;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        जर (!is_compatible_unqualified_types(type1, type2)) {
            जर ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } अन्यथा जर (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } अन्यथा {
                tcc_warning("assignment from incompatible pointer type");
                थांबा;
            }
        }
        जर (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        थांबा;
    स्थिती VT_BYTE:
    स्थिती VT_SHORT:
    स्थिती VT_INT:
    स्थिती VT_LLONG:
        जर (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } अन्यथा जर (sbt == VT_STRUCT) {
            जा case_VT_STRUCT;
        }
        /* XXX: more tests */
        थांबा;
    स्थिती VT_STRUCT:
    case_VT_STRUCT:
        जर (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        थांबा;
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
    पूर्णांक sbt, dbt, ft, r, size, align, bit_size, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    जर (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        size = type_size(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#ifdef CONFIG_TCC_BCHECK
        जर (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#endif
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#ifdef CONFIG_TCC_BCHECK
        जर (vtop->r & VT_MUSTBOUND)
            gbound();
#endif
        vtop->type.t = VT_PTR;
        gaddrof();

#ifdef TCC_TARGET_NATIVE_STRUCT_COPY
        जर (1
#ifdef CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#endif
            ) {
            gen_struct_copy(size);
        } अन्यथा
#endif
        {
            /* type size */
            vpushi(size);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#ifdef TCC_ARM_EABI
            जर(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            अन्यथा जर(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            अन्यथा
#endif
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } अन्यथा जर (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_size = BIT_SIZE(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        जर (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_size);
        जर (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        जर (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_size);
        } अन्यथा {
            अचिन्हित दीर्घ दीर्घ mask = (1ULL << bit_size) - 1;
            जर (dbt != VT_BOOL) {
                /* mask source */
                जर (dbt == VT_LLONG)
                    vpushll(mask);
                अन्यथा
                    vpushi((अचिन्हित)mask);
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
            जर (dbt == VT_LLONG)
                vpushll(~(mask << bit_pos));
            अन्यथा
                vpushi(~((अचिन्हित)mask << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } अन्यथा जर (dbt == VT_VOID) {
        --vtop;
    } अन्यथा {
            /* optimize char/short casts */
            delayed_cast = 0;
            जर ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                जर ((vtop->r & VT_MUSTCAST)
                    && btype_size(dbt) > btype_size(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } अन्यथा {
                gen_cast(&vtop[-1].type);
            }

#ifdef CONFIG_TCC_BCHECK
            /* bound check case */
            जर (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#endif
            gv(RC_TYPE(dbt)); /* generate value */

            जर (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            जर ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
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
            जर (USING_TWO_शब्द(dbt)) {
                पूर्णांक load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_SIZE);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } अन्यथा {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC शून्य inc(पूर्णांक post, पूर्णांक c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    जर (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    जर (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (स्थिरांक अक्षर *संदेश)
{
    /* read the string */
    जर (tok != TOK_STR)
        expect(संदेश);
    cstr_reset(&initstr);
    पर्यंत (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(&initstr, '\0');
    परत &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC पूर्णांक exact_log2p1(पूर्णांक i)
{
  पूर्णांक ret;
  जर (!i)
    परत 0;
  साठी (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  जर (i >= 1 << 4)
    ret += 4, i >>= 4;
  जर (i >= 1 << 2)
    ret += 2, i >>= 2;
  जर (i >= 1 << 1)
    ret++;
  परत ret;
}

/* Parse __attribute__((...)) GNUC extension. */
स्थिर शून्य parse_attribute(AttributeDef *ad)
{
    पूर्णांक t, n;
    अक्षर *astr;
    AttributeDef ad_tmp;
    
redo:
    जर (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        परत;
    जर (रिक्त == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    next();
    skip('(');
    skip('(');
    पर्यंत (tok != ')') {
        जर (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        next();
        निवड(t) {
	स्थिती TOK_CLEANUP1:
	स्थिती TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    जर (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } अन्यथा जर ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    next();
            skip(')');
	    थांबा;
	}
        स्थिती TOK_CONSTRUCTOR1:
        स्थिती TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            थांबा;
        स्थिती TOK_DESTRUCTOR1:
        स्थिती TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            थांबा;
        स्थिती TOK_ALWAYS_INLINE1:
        स्थिती TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            थांबा;
        स्थिती TOK_SECTION1:
        स्थिती TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->data;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            थांबा;
        स्थिती TOK_ALIAS1:
        स्थिती TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->data;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            थांबा;
	स्थिती TOK_VISIBILITY1:
	स्थिती TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->data;
	    जर (!म_भेद (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    अन्यथा जर (!म_भेद (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    अन्यथा जर (!म_भेद (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    अन्यथा जर (!म_भेद (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    अन्यथा
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            थांबा;
        स्थिती TOK_ALIGNED1:
        स्थिती TOK_ALIGNED2:
            जर (tok == '(') {
                next();
                n = अभिव्यक्ती_const();
                जर (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } अन्यथा {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    जर (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            थांबा;
        स्थिती TOK_PACKED1:
        स्थिती TOK_PACKED2:
            ad->a.packed = 1;
            थांबा;
        स्थिती TOK_WEAK1:
        स्थिती TOK_WEAK2:
            ad->a.weak = 1;
            थांबा;
        स्थिती TOK_NODEBUG1:
        स्थिती TOK_NODEBUG2:
            ad->a.nodebug = 1;
            थांबा;
        स्थिती TOK_USED1:
        स्थिती TOK_USED2:
        स्थिती TOK_UNUSED1:
        स्थिती TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            थांबा;
        स्थिती TOK_CONST1:
        स्थिती TOK_CONST2:
        स्थिती TOK_CONST3:
        स्थिती TOK_PURE1:
        स्थिती TOK_PURE2:
	    /* ignored */
            थांबा;
        स्थिती TOK_NOINLINE:
	    /* ignored */
	    थांबा;
        स्थिती TOK_FORMAT1:
        स्थिती TOK_FORMAT2:
	    /* ignored */
            जा skip_param;
        स्थिती TOK_NORETURN1:
        स्थिती TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            थांबा;
        स्थिती TOK_CDECL1:
        स्थिती TOK_CDECL2:
        स्थिती TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            थांबा;
        स्थिती TOK_STDCALL1:
        स्थिती TOK_STDCALL2:
        स्थिती TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            थांबा;
#ifdef TCC_TARGET_I386
        स्थिती TOK_REGPARM1:
        स्थिती TOK_REGPARM2:
            skip('(');
            n = अभिव्यक्ती_const();
            जर (n > 3) 
                n = 3;
            अन्यथा जर (n < 0)
                n = 0;
            जर (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            थांबा;
        स्थिती TOK_FASTCALL1:
        स्थिती TOK_FASTCALL2:
        स्थिती TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            थांबा;
        स्थिती TOK_THISCALL1:
        स्थिती TOK_THISCALL2:
        स्थिती TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            थांबा;
#endif
        स्थिती TOK_MODE:
            skip('(');
            निवड(tok) {
                स्थिती TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    थांबा;
                स्थिती TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    थांबा;
                स्थिती TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    थांबा;
                स्थिती TOK_MODE_SI:
                स्थिती TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    थांबा;
                पूर्वनिर्धारित:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, रिक्त));
                    थांबा;
            }
            next();
            skip(')');
            थांबा;
        स्थिती TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            थांबा;
        स्थिती TOK_NODECORATE:
            ad->a.nodecorate = 1;
            थांबा;
        स्थिती TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            थांबा;
        पूर्वनिर्धारित:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, रिक्त));
            /* skip parameters */
skip_param:
            जर (tok == '(') {
                पूर्णांक parenthesis = 0;
                करा {
                    जर (tok == '(') 
                        parenthesis++;
                    अन्यथा जर (tok == ')') 
                        parenthesis--;
                    next();
                } पर्यंत (parenthesis && tok != -1);
            }
            थांबा;
        }
        जर (tok != ',')
            थांबा;
        next();
    }
    skip(')');
    skip(')');
    जा redo;
}

स्थिर Sym * find_field (CType *type, पूर्णांक v, पूर्णांक *cumofs)
{
    Sym *s = type->ref;
    पूर्णांक v1 = v | SYM_FIELD;
    जर (!(v & SYM_FIELD)) { /* top-level call */
        जर ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        जर (v < TOK_UIDENT)
            expect("field name");
        जर (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    पर्यंत ((s = s->next) != रिक्त) {
        जर (s->v == v1) {
            *cumofs = s->c;
            परत s;
        }
        जर ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            जर (ret) {
                *cumofs += s->c;
                परत ret;
            }
        }
    }
    जर (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, रिक्त));
    परत s;
}

स्थिर शून्य check_fields (CType *type, पूर्णांक check)
{
    Sym *s = type->ref;

    पर्यंत ((s = s->next) != रिक्त) {
        पूर्णांक v = s->v & ~SYM_FIELD;
        जर (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            जर (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, रिक्त));
            ts->tok ^= SYM_FIELD;
        } अन्यथा जर ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

स्थिर शून्य struct_layout(CType *type, AttributeDef *ad)
{
    पूर्णांक size, align, maxalign, offset, c, bit_pos, bit_size;
    पूर्णांक packed, a, bt, prevbt, prev_bit_size;
    पूर्णांक pcc = !tcc_state->ms_bitfields;
    पूर्णांक pragma_pack = *tcc_state->pack_चळत_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_bit_size = 0;

//#define BF_DEBUG

    साठी (f = type->ref->next; f; f = f->next) {
        जर (f->type.t & VT_BITFIELD)
            bit_size = BIT_SIZE(f->type.t);
        अन्यथा
            bit_size = -1;
        size = type_size(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        जर (pcc && bit_size == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } अन्यथा {
            /* in pcc mode, attribute packed overrides if set. */
            जर (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            जर (pragma_pack) {
                packed = 1;
                जर (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                जर (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        जर (a)
            align = a;

        जर (type->ref->type.t == VT_UNION) {
	    जर (pcc && bit_size >= 0)
	        size = (bit_size + 7) >> 3;
	    offset = 0;
	    जर (size > c)
	        c = size;

	} अन्यथा जर (bit_size < 0) {
            जर (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    जर (size > 0)
	        c += size;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_bit_size = 0;

	} अन्यथा {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            जर (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                जर (bit_size == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } अन्यथा जर (f->a.aligned) {
                    जा new_field;
                } अन्यथा जर (!packed) {
                    पूर्णांक a8 = align * 8;
	            पूर्णांक ofs = ((c * 8 + bit_pos) % a8 + bit_size + a8 - 1) / a8;
                    जर (ofs > size / align)
                        जा new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                जर (size == 8 && bit_size <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, size = 4;

                पर्यंत (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		जर (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } अन्यथा {
		bt = f->type.t & VT_BTYPE;
		जर ((bit_pos + bit_size > size * 8)
                    || (bit_size > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    जर (bit_size || prev_bit_size)
		        c += size;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		जर (bit_size == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_bit_size = bit_size;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_size;
	}
	जर (align > maxalign)
	    maxalign = align;

#ifdef BF_DEBUG
	म_लिखो("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, रिक्त), offset, size, align);
	जर (f->type.t & VT_BITFIELD) {
	    म_लिखो(" pos %-2d bits %-2d",
                    BIT_POS(f->type.t),
                    BIT_SIZE(f->type.t)
                    );
	}
	म_लिखो("\n");
#endif

        f->c = offset;
	f->r = 0;
    }

    जर (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    जर (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    जर (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        जर (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#ifdef BF_DEBUG
    म_लिखो("struct size %-2d align %-2d\n\n", c, a), ख_साफ(मानक_निकास);
#endif

    /* check whether we can access bitfields by their type */
    साठी (f = type->ref->next; f; f = f->next) {
        पूर्णांक s, px, cx, c0;
        CType t;

        जर (0 == (f->type.t & VT_BITFIELD))
            सुरूठेवा;
        f->type.ref = f;
        f->auxtype = -1;
        bit_size = BIT_SIZE(f->type.t);
        जर (bit_size == 0)
            सुरूठेवा;
        bit_pos = BIT_POS(f->type.t);
        size = type_size(&f->type, &align);

        जर (bit_pos + bit_size <= size * 8 && f->c + size <= c
#ifdef TCC_TARGET_ARM
            && !(f->c & (align - 1))
#endif
            )
            सुरूठेवा;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        साठी (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            जर (c0 == cx)
                थांबा;
            s = (px + bit_size + 7) >> 3;
            जर (s > 4) {
                t.t = VT_LLONG;
            } अन्यथा जर (s > 2) {
                t.t = VT_INT;
            } अन्यथा जर (s > 1) {
                t.t = VT_SHORT;
            } अन्यथा {
                t.t = VT_BYTE;
            }
            s = type_size(&t, &align);
            c0 = cx;
        }

        जर (px + bit_size <= s * 8 && cx + s <= c
#ifdef TCC_TARGET_ARM
            && !(cx & (align - 1))
#endif
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            जर (s != size)
                f->auxtype = t.t;
#ifdef BF_DEBUG
            म_लिखो("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, रिक्त),
                cx, s, align, px, bit_size);
#endif
        } अन्यथा {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#ifdef BF_DEBUG
            म_लिखो("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, रिक्त));
#endif
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
स्थिर पूर्णांक in_range(दीर्घ दीर्घ n, पूर्णांक t)
{
    अचिन्हित दीर्घ दीर्घ m = (1ULL << (btype_size(t & VT_BTYPE) * 8 - 1)) - 1;
    जर (t & VT_UNSIGNED)
        परत n <= (m << 1) + 1;
    परत n >= -(दीर्घ दीर्घ)m - 1 && n <= (दीर्घ दीर्घ)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
स्थिर शून्य struct_decl(CType *type, पूर्णांक u)
{
    पूर्णांक v, c, size, align, flexible;
    पूर्णांक bit_size, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    स_रखो(&ad, 0, आकार ad);
    next();
    parse_attribute(&ad);

    v = 0;
    जर (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, next();

    bt = ut = 0;
    जर (u == VT_ENUM) {
        ut = VT_INT;
        जर (tok == ':') { /* C2x enum : <type> ... */
            next();
            जर (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    जर (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        जर (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            जर (u == s->type.t)
                जा do_decl;
            जर (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                जा do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, रिक्त));
        }
    } अन्यथा {
        जर (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = रिक्त;
    /* we put an undefined size for struct/union */
    s = sym_ढकला(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    जर (tok == '{') {
        next();
        जर (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->next;
        जर (u == VT_ENUM) {
            दीर्घ दीर्घ ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            जर (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            साठी(;;) {
                v = tok;
                जर (v < TOK_UIDENT)
                    expect("identifier");
                next();
                जर (tok == '=') {
                    next();
		    ll = अभिव्यक्ती_const64();
                }
                जर (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, रिक्त));
                ss = sym_ढकला(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                जर (ll < nl)
                    nl = ll;
                जर (ll > pl)
                    pl = ll;
                जर (tok != ',')
                    थांबा;
                next();
                ll++;
                /* NOTE: we accept a trailing comma */
                जर (tok == '}')
                    थांबा;
            }
            skip('}');

            जर (bt) {
                t.t = bt;
                s->c = 2;
                जा enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            जर (nl >= 0) {
                जर (pl != (अचिन्हित)pl)
                    t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } अन्यथा जर (pl != (पूर्णांक)pl || nl != (पूर्णांक)nl)
                t.t = (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            साठी (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                जर (ll == (पूर्णांक)ll) /* default is int if it fits */
                    सुरूठेवा;
                जर (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    जर (ll == (अचिन्हित)ll)
                        सुरूठेवा;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_SIZE==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } अन्यथा {
            c = 0;
            flexible = 0;
            पर्यंत (tok != '}') {
                जर (!parse_btype(&btype, &ad1, 0)) {
                    जर (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        सुरूठेवा;
                    }
		    skip(';');
		    सुरूठेवा;
		}
                पर्यंत (1) {
		    जर (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, रिक्त));
                    bit_size = -1;
                    v = 0;
                    type1 = btype;
                    जर (tok != ':') {
			जर (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        जर (v == 0) {
                    	    जर ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    अन्यथा {
				पूर्णांक v = btype.ref->v;
				जर ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    जर (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        जर (type_size(&type1, &align) < 0) {
			    जर ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    अन्यथा
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, रिक्त));
                        }
                        जर ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, रिक्त));
                    }
                    जर (tok == ':') {
                        next();
                        bit_size = अभिव्यक्ती_const();
                        /* XXX: handle v = 0 case for messages */
                        जर (bit_size < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, रिक्त));
                        जर (v && bit_size == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, रिक्त));
			parse_attribute(&ad1);
                    }
                    size = type_size(&type1, &align);
                    जर (bit_size >= 0) {
                        bt = type1.t & VT_BTYPE;
                        जर (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = size * 8;
                        जर (bit_size > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, रिक्त));
                        } अन्यथा जर (bit_size == bsize
				    && !*tcc_state->pack_चळत_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } अन्यथा जर (bit_size == 64) {
                            tcc_error("field width 64 not implemented");
                        } अन्यथा {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((अचिन्हित)bit_size << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    जर (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    जर (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_size >= 0)) {
		        v = anon_sym++;
		    }
                    जर (v) {
                        ss = sym_ढकला(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->next;
                    }
                    जर (tok == ';' || tok == TOK_EOF)
                        थांबा;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            जर (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        जर (debug_modes)
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
स्थिर शून्य parse_btype_qualify(CType *type, पूर्णांक qualifiers)
{
    पर्यंत (type->t & VT_ARRAY) {
        type->ref = sym_ढकला(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    जर (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
स्थिर पूर्णांक parse_btype(CType *type, AttributeDef *ad, पूर्णांक ignore_label)
{
    पूर्णांक t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    स_रखो(ad, 0, आकार(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = रिक्त;

    पर्यंत(1) {
        निवड(tok) {
        स्थिती TOK_EXTENSION:
            /* currently, we really ignore extension */
            next();
            सुरूठेवा;

            /* basic types */
        स्थिती TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            next();
        basic_type1:
            जर (u == VT_SHORT || u == VT_LONG) {
                जर (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } अन्यथा {
                जर (bt != -1 || (st != -1 && u != VT_INT))
                    जा tmbt;
                जर ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    जा tmbt;
                bt = u;
            }
            जर (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            थांबा;
        स्थिती TOK_VOID:
            u = VT_VOID;
            जा basic_type;
        स्थिती TOK_SHORT:
            u = VT_SHORT;
            जा basic_type;
        स्थिती TOK_INT:
            u = VT_INT;
            जा basic_type;
        स्थिती TOK_ALIGNAS:
            { पूर्णांक n;
              AttributeDef ad1;
              next();
              skip('(');
              स_रखो(&ad1, 0, आकार(AttributeDef));
              जर (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  जर (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  अन्यथा
                    type_size(&type1, &n);
              } अन्यथा {
                  n = अभिव्यक्ती_const();
                  जर (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            सुरूठेवा;
        स्थिती TOK_LONG:
            जर ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अन्यथा जर ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } अन्यथा {
                u = VT_LONG;
                जा basic_type;
            }
            next();
            थांबा;
        स्थिती TOK_BOOL:
            u = VT_BOOL;
            जा basic_type;
        स्थिती TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        स्थिती TOK_FLOAT:
            u = VT_FLOAT;
            जा basic_type;
        स्थिती TOK_DOUBLE:
            जर ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अन्यथा {
                u = VT_DOUBLE;
                जा basic_type;
            }
            next();
            थांबा;
        स्थिती TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            जा basic_type1;
        स्थिती TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            जा basic_type2;
        स्थिती TOK_UNION:
            struct_decl(&type1, VT_UNION);
            जा basic_type2;

            /* type modifiers */
        स्थिती TOK__Atomic:
            next();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            जर (tok == '(') {
                parse_अभिव्यक्ती_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                जर (type1.ref)
                    sym_to_attr(ad, type1.ref);
                जा basic_type2;
            }
            थांबा;
        स्थिती TOK_CONST1:
        स्थिती TOK_CONST2:
        स्थिती TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            next();
            थांबा;
        स्थिती TOK_VOLATILE1:
        स्थिती TOK_VOLATILE2:
        स्थिती TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            next();
            थांबा;
        स्थिती TOK_SIGNED1:
        स्थिती TOK_SIGNED2:
        स्थिती TOK_SIGNED3:
            जर ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            next();
            typespec_found = 1;
            थांबा;
        स्थिती TOK_RESTRICT1:
        स्थिती TOK_RESTRICT2:
        स्थिती TOK_RESTRICT3:
            t |= VT_RESTRICT;
            next();
            थांबा;
        स्थिती TOK_REGISTER:
        स्थिती TOK_AUTO:
            next();
            थांबा;
        स्थिती TOK_UNSIGNED:
            जर ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            next();
            typespec_found = 1;
            थांबा;

            /* storage */
        स्थिती TOK_EXTERN:
            g = VT_EXTERN;
            जा storage;
        स्थिती TOK_STATIC:
            g = VT_STATIC;
            जा storage;
        स्थिती TOK_TYPEDEF:
            g = VT_TYPEDEF;
            जा storage;
       storage:
            जर (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            थांबा;
        स्थिती TOK_INLINE1:
        स्थिती TOK_INLINE2:
        स्थिती TOK_INLINE3:
            t |= VT_INLINE;
            next();
            थांबा;
        स्थिती TOK_NORETURN3:
            next();
            ad->f.func_noreturn = 1;
            थांबा;
            /* GNUC attribute */
        स्थिती TOK_ATTRIBUTE1:
        स्थिती TOK_ATTRIBUTE2:
            parse_attribute(ad);
            जर (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            सुरूठेवा;
            /* GNUC typeof */
        स्थिती TOK_TYPEOF1:
        स्थिती TOK_TYPEOF2:
        स्थिती TOK_TYPEOF3:
            next();
            parse_अभिव्यक्ती_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            जर (type1.ref) {
                sym_to_attr(ad, type1.ref);
                जर (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            जा basic_type2;
        स्थिती TOK_THREAD_LOCAL:
        स्थिती TOK___thread:
            जर (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            next();
            थांबा;
        पूर्वनिर्धारित:
            जर (typespec_found)
                जा the_end;
            s = sym_find(tok);
            जर (!s || !(s->type.t & VT_TYPEDEF))
                जा the_end;

            n = tok, next();
            जर (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                जा the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            जर (t)
                parse_btype_qualify(type, t);
            t = type->t;
            जर (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            थांबा;
        }
        type_found = 1;
    }
the_end:
    जर (tcc_state->char_is_unsigned) {
        जर ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    जर (bt == VT_LONG)
        t |= LONG_SIZE == 8 ? VT_LLONG : VT_INT;
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
    जर (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#endif
    type->t = t;
    check_restrict_type(type);
    परत type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
स्थिर ओळीत शून्य convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    जर ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
स्थिर ओळीत शून्य convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(शून्य)
{
    skip('(');
    परत parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
स्थिर पूर्णांक asm_label_instr(शून्य)
{
    पूर्णांक v;
    अक्षर *astr;

    next();
    astr = parse_asm_str()->data;
    skip(')');
#ifdef ASM_DEBUG
    म_लिखो("asm_alias: \"%s\"\n", astr);
#endif
    v = tok_alloc_const(astr);
    परत v;
}

स्थिर पूर्णांक post_type(CType *type, AttributeDef *ad, पूर्णांक storage, पूर्णांक td)
{
    पूर्णांक n, l, t1, arg_size, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = रिक्त;
    पूर्णांक *vla_array_str = रिक्त;

    जर (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        next();
	जर (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  परत 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_चळत ? &local_चळत : &global_चळत;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	जर (tok == ')')
	  l = 0;
	अन्यथा जर (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	अन्यथा जर (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_काढा(ps, sr->prev, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    परत 0;
	} अन्यथा
	  l = FUNC_OLD;

        first = रिक्त;
        plast = &first;
        arg_size = 0;
        जर (l) {
            साठी(;;) {
                /* read param name and compute offset */
                जर (l != FUNC_OLD) {
                    जर ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        थांबा;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    जर ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    जर (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } अन्यथा {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = रिक्त;
                    next();
                }
                जर (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_size += (type_size(&pt, &align) + PTR_SIZE - 1) / PTR_SIZE;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_ढकला(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->next;
                जर (tok == ')')
                    थांबा;
                skip(',');
                जर (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    next();
                    थांबा;
                }
		जर (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } अन्यथा
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        जर (tok == '[') {
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
        sym_काढा(ps, sr, 1);
        --local_scope;

    } अन्यथा जर (tok == '[') {
	पूर्णांक saved_nocode_wanted = nocode_wanted;
        पूर्णांक array_qualifiers = 0;
        /* array definition */
        next();
        n = -1;
        t1 = 0;
        जर (td & TYPE_PARAM) पर्यंत (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    निवड (tok) {
	    स्थिती TOK_CONST1: स्थिती TOK_CONST2: स्थिती TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		next();
		सुरूठेवा;
	    स्थिती TOK_VOLATILE1: स्थिती TOK_VOLATILE2: स्थिती TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		next();
		सुरूठेवा;
	    स्थिती TOK_RESTRICT1: स्थिती TOK_RESTRICT2: स्थिती TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		next();
		सुरूठेवा;
	    स्थिती TOK_STATIC:
	    स्थिती '*':
		next();
		सुरूठेवा;
	    पूर्वनिर्धारित:
		थांबा;
	    }
            जर (tok != ']') {
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
		जा check;
            }
            थांबा;

	} अन्यथा जर (tok != ']') {
            जर (!local_चळत || (storage & VT_STATIC))
                vpushi(अभिव्यक्ती_const());
            अन्यथा {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            जर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                जर (n < 0)
                    tcc_error("invalid array size");
            } अन्यथा {
                जर (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        जर ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        जर ((type->t & VT_BTYPE) == VT_VOID
            || type_size(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        जर (t1 & VT_VLA) {
            जर (n < 0) {
		जर  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    अन्यथा {
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
        जर (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_ढकला(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        जर (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    जर ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    अन्यथा
	        tok_str_free_str(vla_array_str);
	}
    }
    परत 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
स्थिर CType *type_decl(CType *type, AttributeDef *ad, पूर्णांक *v, पूर्णांक td)
{
    CType *post, *ret;
    पूर्णांक qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    पर्यंत (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        निवड(tok) {
        स्थिती TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            जा redo;
        स्थिती TOK_CONST1:
        स्थिती TOK_CONST2:
        स्थिती TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            जा redo;
        स्थिती TOK_VOLATILE1:
        स्थिती TOK_VOLATILE2:
        स्थिती TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            जा redo;
        स्थिती TOK_RESTRICT1:
        स्थिती TOK_RESTRICT2:
        स्थिती TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            जा redo;
	/* XXX: clarify attribute handling */
	स्थिती TOK_ATTRIBUTE1:
	स्थिती TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    थांबा;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	जर (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    जर (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	जर (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} अन्यथा
	  जा abstract;
    } अन्यथा जर (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	next();
    } अन्यथा {
  abstract:
	जर (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    परत ret;
}

/* indirection with full error checking and bound check */
ST_FUNC शून्य indir(शून्य)
{
    जर ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        जर ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            परत;
        expect("pointer");
    }
    जर (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    जर (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#ifdef CONFIG_TCC_BCHECK
        जर (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#endif
    }
}

/* pass a parameter to a function and do type checking and casting */
स्थिर शून्य gfunc_param_typed(Sym *func, Sym *arg)
{
    पूर्णांक func_type;
    CType type;

    func_type = func->f.func_type;
    जर (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == रिक्त)) {
        /* default casting : only need to convert float to double */
        जर ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } अन्यथा जर (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } अन्यथा जर (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } अन्यथा जर (arg == रिक्त) {
        tcc_error("too many arguments to function");
    } अन्यथा {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
स्थिर शून्य अभिव्यक्ती_type(CType *type, शून्य (*अभिव्यक्ती_fn)(शून्य))
{
    nocode_wanted++;
    अभिव्यक्ती_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
स्थिर शून्य parse_अभिव्यक्ती_type(CType *type)
{
    पूर्णांक n;
    AttributeDef ad;

    skip('(');
    जर (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } अन्यथा {
        अभिव्यक्ती_type(type, gexpr);
    }
    skip(')');
}

स्थिर शून्य parse_type(CType *type)
{
    AttributeDef ad;
    पूर्णांक n;

    जर (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

स्थिर शून्य parse_builtin_params(पूर्णांक nc, स्थिरांक अक्षर *args)
{
    अक्षर c, sep = '(';
    CType type;
    जर (nc)
        nocode_wanted++;
    next();
    जर (*args == 0)
	skip(sep);
    पर्यंत ((c = *args++)) {
	skip(sep);
	sep = ',';
        जर (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    सुरूठेवा;
        }
        अभिव्यक्ती_eq();
        type.ref = रिक्त;
        type.t = 0;
	निवड (c) {
	    स्थिती 'e':
		सुरूठेवा;
	    स्थिती 'V':
                type.t = VT_CONSTANT;
	    स्थिती 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                थांबा;
	    स्थिती 'S':
                type.t = VT_CONSTANT;
	    स्थिती 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                थांबा;
	    स्थिती 'i':
                type.t = VT_INT;
                थांबा;
	    स्थिती 'l':
                type.t = VT_SIZE_T;
                थांबा;
	    पूर्वनिर्धारित:
                थांबा;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    जर (nc)
        nocode_wanted--;
}

स्थिर शून्य parse_atomic(पूर्णांक atok)
{
    पूर्णांक size, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    अक्षर buf[40];
    स्थिर स्थिरांक अक्षर *स्थिरांक templates[] = {
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
    स्थिरांक अक्षर *ढाँचा = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = रिक्त;
    size = 0; /* pacify compiler */
    next();
    skip('(');
    साठी (arg = 0;;) {
        अभिव्यक्ती_eq();
        निवड (ढाँचा[arg]) {
        स्थिती 'a':
        स्थिती 'A':
            atom_ptr = &vtop->type;
            जर ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            size = type_size(atom, &align);
            जर (size > 8
                || (size & (size - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_size(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            थांबा;

        स्थिती 'p':
            जर ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_size(pointed_type(&vtop->type), &align) != size)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            थांबा;
        स्थिती 'v':
            gen_assign_cast(atom);
            थांबा;
        स्थिती 'l':
            indir();
            gen_assign_cast(atom);
            थांबा;
        स्थिती 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            थांबा;
        स्थिती 'm':
            gen_assign_cast(&int_type);
            थांबा;
        स्थिती 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            थांबा;
        }
        जर ('.' == ढाँचा[++arg])
            थांबा;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    निवड (ढाँचा[arg + 1]) {
    स्थिती 'b':
        ct.t = VT_BOOL;
        थांबा;
    स्थिती 'v':
        ct = *atom;
        थांबा;
    }

    प्र_लिखो(buf, "%s_%d", get_tok_str(atok, 0), size);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    जर (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अन्यथा
        vtop->type.t = VT_INT;
#endif
    }
    gen_cast(&ct);
    जर (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC शून्य unary(शून्य)
{
    पूर्णांक n, t, align, size, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    जर (debug_modes)
        tcc_debug_ओळ(tcc_state), tcc_tcov_check_ओळ (tcc_state, 1);

    type.ref = रिक्त;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    निवड(tok) {
    स्थिती TOK_EXTENSION:
        next();
        जा tok_next;
    स्थिती TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        जा ढकला_tokc;
#endif
    स्थिती TOK_CINT:
    स्थिती TOK_CCHAR: 
	t = VT_INT;
 ढकला_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        थांबा;
    स्थिती TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        जा ढकला_tokc;
    स्थिती TOK_CLLONG:
        t = VT_LLONG;
	जा ढकला_tokc;
    स्थिती TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	जा ढकला_tokc;
    स्थिती TOK_CFLOAT:
        t = VT_FLOAT;
	जा ढकला_tokc;
    स्थिती TOK_CDOUBLE:
        t = VT_DOUBLE;
	जा ढकला_tokc;
    स्थिती TOK_CLDOUBLE:
#ifdef TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#अन्यथा
        t = VT_LDOUBLE;
#endif
	जा ढकला_tokc;
    स्थिती TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	जा ढकला_tokc;
    स्थिती TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	जा ढकला_tokc;
    स्थिती TOK___FUNCTION__:
        जर (!gnu_ext)
            जा tok_identifier;
        /* fall thru */
    स्थिती TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        जा case_TOK_STR;
    स्थिती TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#अन्यथा
        t = VT_INT;
#endif
        जा str_init;
    स्थिती TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        जर (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        स_रखो(&ad, 0, आकार(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        थांबा;
    स्थिती TOK_SOTYPE:
    स्थिती '(':
        t = tok;
        next();
        /* cast ? */
        जर (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            जर (tok == '{') {
                    /* data is allocated locally by default */
                जर (global_अभिव्यक्ती)
                    r = VT_CONST;
                अन्यथा
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                जर (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                स_रखो(&ad, 0, आकार(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } अन्यथा जर (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                परत;
            } अन्यथा {
                unary();
                gen_cast(&type);
            }
        } अन्यथा जर (tok == '{') {
	    पूर्णांक saved_nocode_wanted = nocode_wanted;
            जर (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            जर (0 == local_scope)
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
            block(STMT_अभिव्यक्ती);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            जर (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } अन्यथा {
            gexpr();
            skip(')');
        }
        थांबा;
    स्थिती '*':
        next();
        unary();
        indir();
        थांबा;
    स्थिती '&':
        next();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        जर ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        जर (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        थांबा;
    स्थिती '!':
        next();
        unary();
        gen_test_zero(TOK_EQ);
        थांबा;
    स्थिती '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        थांबा;
    स्थिती '+':
        next();
        unary();
        जर ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	जर (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        थांबा;
    स्थिती TOK_SIZEOF:
    स्थिती TOK_ALIGNOF1:
    स्थिती TOK_ALIGNOF2:
    स्थिती TOK_ALIGNOF3:
        t = tok;
        next();
        जर (tok == '(')
            tok = TOK_SOTYPE;
        अभिव्यक्ती_type(&type, unary);
        जर (t == TOK_SIZEOF) {
            vpush_type_size(&type, &align);
            gen_cast_s(VT_SIZE_T);
        } अन्यथा {
            type_size(&type, &align);
            s = रिक्त;
            जर (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            जर (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        थांबा;

    स्थिती TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        थांबा;
    स्थिती TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        थांबा;
    स्थिती TOK_builtin_choose_अभिव्यक्ती:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = अभिव्यक्ती_const64();
	    skip(',');
	    जर (!c) {
		nocode_wanted++;
	    }
	    अभिव्यक्ती_eq();
	    जर (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    जर (c) {
		nocode_wanted++;
	    }
	    अभिव्यक्ती_eq();
	    जर (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        थांबा;
    स्थिती TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	जर ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        थांबा;
    स्थिती TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        थांबा;
    स्थिती TOK_builtin_frame_address:
    स्थिती TOK_builtin_return_address:
        {
            पूर्णांक tok1 = tok;
            पूर्णांक level;
            next();
            skip('(');
            level = अभिव्यक्ती_const();
            जर (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            पर्यंत (level--) {
#ifdef TCC_TARGET_RISCV64
                vpushi(2*PTR_SIZE);
                gen_op('-');
#endif
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            जर (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#ifdef TCC_TARGET_ARM
                vpushi(2*PTR_SIZE);
                gen_op('+');
#किंवाजर defined TCC_TARGET_RISCV64
                vpushi(PTR_SIZE);
                gen_op('-');
#अन्यथा
                vpushi(PTR_SIZE);
                gen_op('+');
#endif
                mk_pointer(&vtop->type);
                indir();
            }
        }
        थांबा;
#ifdef TCC_TARGET_RISCV64
    स्थिती TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        जर (r == VT_LLOCAL)
            r = VT_LOCAL;
        जर (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        थांबा;
#endif
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    स्थिती TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        जर (r == VT_LLOCAL)
            r = VT_LOCAL;
        जर (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        थांबा;
#अन्यथा
    स्थिती TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	थांबा;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    स्थिती TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        थांबा;
    }
    स्थिती TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        थांबा;
    }
#endif
#ifdef TCC_TARGET_ARM64
    स्थिती TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        थांबा;
    }
#endif
#ifdef TCC_TARGET_RISCV64
    स्थिती TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        थांबा;
    }
#endif

    /* atomic operations */
    स्थिती TOK___atomic_store:
    स्थिती TOK___atomic_load:
    स्थिती TOK___atomic_exchange:
    स्थिती TOK___atomic_compare_exchange:
    स्थिती TOK___atomic_fetch_add:
    स्थिती TOK___atomic_fetch_sub:
    स्थिती TOK___atomic_fetch_or:
    स्थिती TOK___atomic_fetch_xor:
    स्थिती TOK___atomic_fetch_and:
    स्थिती TOK___atomic_fetch_nand:
    स्थिती TOK___atomic_add_fetch:
    स्थिती TOK___atomic_sub_fetch:
    स्थिती TOK___atomic_or_fetch:
    स्थिती TOK___atomic_xor_fetch:
    स्थिती TOK___atomic_and_fetch:
    स्थिती TOK___atomic_nand_fetch:
        parse_atomic(tok);
        थांबा;

    /* pre operations */
    स्थिती TOK_INC:
    स्थिती TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        थांबा;
    स्थिती '-':
        next();
        unary();
	जर (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} अन्यथा {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        थांबा;
    स्थिती TOK_LAND:
        जर (!gnu_ext)
            जा tok_identifier;
        next();
        /* allow to take the address of a label */
        जर (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        जर (!s) {
            s = label_ढकला(&global_label_चळत, tok, LABEL_FORWARD);
        } अन्यथा {
            जर (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        जर ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        थांबा;

    स्थिती TOK_GENERIC:
    {
	CType controlling_type;
	पूर्णांक has_default = 0;
	पूर्णांक has_match = 0;
	पूर्णांक learn = 0;
	TokenString *str = रिक्त;
	पूर्णांक saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        next();
	skip('(');
	अभिव्यक्ती_type(&controlling_type, अभिव्यक्ती_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        साठी (;;) {
	    learn = 0;
	    skip(',');
	    जर (tok == TOK_DEFAULT) {
		जर (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		जर (!has_match)
		    learn = 1;
		next();
	    } अन्यथा {
		पूर्णांक v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		जर (compare_types(&controlling_type, &type, 0)) {
		    जर (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    जर (learn) {
		जर (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } अन्यथा {
		skip_or_save_block(रिक्त);
	    }
	    जर (tok == ')')
		थांबा;
	}
	जर (!str) {
	    अक्षर buf[60];
	    type_to_str(buf, आकार buf, &controlling_type, रिक्त);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	अभिव्यक्ती_eq();
	जर (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	थांबा;
    }
    // special qnan , snan and infinity values
    स्थिती TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        next();
        थांबा;
    स्थिती TOK___SNAN__:
	n = 0x7f800001;
	जा special_math_val;
    स्थिती TOK___INF__:
	n = 0x7f800000;
	जा special_math_val;

    पूर्वनिर्धारित:
    tok_identifier:
        जर (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        next();
        s = sym_find(t);
        जर (!s || IS_ASM_SYM(s)) {
            स्थिरांक अक्षर *name = get_tok_str(t, रिक्त);
            जर (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            जर (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        जर ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        जर (r & VT_SYM) {
            vtop->c.i = 0;
#ifdef TCC_TARGET_PE
            जर (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#endif
        } अन्यथा जर (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        थांबा;
    }
    
    /* post operations */
    पर्यंत (1) {
        जर (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } अन्यथा जर (tok == '.' || tok == TOK_ARROW) {
            पूर्णांक qualifiers, cumofs;
            /* field */ 
            जर (tok == TOK_ARROW) 
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
            जर (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            जर (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                जर (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#endif
            }
            next();
        } अन्यथा जर (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } अन्यथा जर (tok == '(') {
            SValue ret;
            Sym *sa;
            पूर्णांक nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            जर ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                जर ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    जर ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        जा error_func;
                } अन्यथा {
                error_func:
                    expect("function pointer");
                }
            } अन्यथा {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            जर ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                जर (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                जर (size < 16)
                    पर्यंत (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#ifdef CONFIG_TCC_BCHECK
                    जर (tcc_state->do_bounds_check)
                        --loc;
#endif
                    ret.c = vtop->c;
                    जर (ret_nregs < 0)
                      vtop--;
                    अन्यथा
                      nb_args++;
                }
            } अन्यथा {
                ret_nregs = 1;
                ret.type = s->type;
            }

            जर (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = रिक्त;
            जर (tok != ')') {
                r = tcc_state->reverse_funcargs;
                साठी(;;) {
                    जर (r) {
                        skip_or_save_block(&p2);
                        p2->prev = p, p = p2;
                    } अन्यथा {
                        अभिव्यक्ती_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    जर (sa)
                        sa = sa->next;
                    जर (tok == ')')
                        थांबा;
                    skip(',');
                }
            }
            जर (sa)
                tcc_error("too few arguments to function");

            जर (p) { /* with reverse_funcargs */
                साठी (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    करा {
                        sa = sa->next, p2 = p2->prev;
                    } पर्यंत (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), next();
                    अभिव्यक्ती_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            next();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            जर (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#ifdef TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#endif
            } अन्यथा {
                /* return value */
                n = ret_nregs;
                पर्यंत (n > 1) {
                    पूर्णांक rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    साठी (r = 0; r < NB_REGS; ++r)
                        जर (reg_classes[r] & rc)
                            थांबा;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                जर (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    पूर्णांक addr, offset;

                    size = type_size(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    size = (size + regsize - 1) & -regsize;
                    जर (ret_align > align)
                        align = ret_align;
                    loc = (loc - size) & -align;
                    addr = loc;
                    offset = 0;
                    साठी (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        जर (--ret_nregs == 0)
                          थांबा;
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
                जर (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#ifdef PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अन्यथा
                    vtop->type.t = VT_INT;
#endif
                }
            }
            जर (s->f.func_noreturn) {
                जर (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } अन्यथा {
            थांबा;
        }
    }
}

#ifndef precedence_parser /* original top-down parser */

स्थिर शून्य अभिव्यक्ती_prod(शून्य)
{
    पूर्णांक t;

    unary();
    पर्यंत ((t = tok) == '*' || t == '/' || t == '%') {
        next();
        unary();
        gen_op(t);
    }
}

स्थिर शून्य अभिव्यक्ती_sum(शून्य)
{
    पूर्णांक t;

    अभिव्यक्ती_prod();
    पर्यंत ((t = tok) == '+' || t == '-') {
        next();
        अभिव्यक्ती_prod();
        gen_op(t);
    }
}

स्थिर शून्य अभिव्यक्ती_shift(शून्य)
{
    पूर्णांक t;

    अभिव्यक्ती_sum();
    पर्यंत ((t = tok) == TOK_SHL || t == TOK_SAR) {
        next();
        अभिव्यक्ती_sum();
        gen_op(t);
    }
}

स्थिर शून्य अभिव्यक्ती_cmp(शून्य)
{
    पूर्णांक t;

    अभिव्यक्ती_shift();
    पर्यंत (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        next();
        अभिव्यक्ती_shift();
        gen_op(t);
    }
}

स्थिर शून्य अभिव्यक्ती_cmpeq(शून्य)
{
    पूर्णांक t;

    अभिव्यक्ती_cmp();
    पर्यंत ((t = tok) == TOK_EQ || t == TOK_NE) {
        next();
        अभिव्यक्ती_cmp();
        gen_op(t);
    }
}

स्थिर शून्य अभिव्यक्ती_and(शून्य)
{
    अभिव्यक्ती_cmpeq();
    पर्यंत (tok == '&') {
        next();
        अभिव्यक्ती_cmpeq();
        gen_op('&');
    }
}

स्थिर शून्य अभिव्यक्ती_xor(शून्य)
{
    अभिव्यक्ती_and();
    पर्यंत (tok == '^') {
        next();
        अभिव्यक्ती_and();
        gen_op('^');
    }
}

स्थिर शून्य अभिव्यक्ती_or(शून्य)
{
    अभिव्यक्ती_xor();
    पर्यंत (tok == '|') {
        next();
        अभिव्यक्ती_xor();
        gen_op('|');
    }
}

स्थिर शून्य अभिव्यक्ती_landor(पूर्णांक op);

स्थिर शून्य अभिव्यक्ती_land(शून्य)
{
    अभिव्यक्ती_or();
    जर (tok == TOK_LAND)
        अभिव्यक्ती_landor(tok);
}

स्थिर शून्य अभिव्यक्ती_lor(शून्य)
{
    अभिव्यक्ती_land();
    जर (tok == TOK_LOR)
        अभिव्यक्ती_landor(tok);
}

# define अभिव्यक्ती_landor_next(op) op == TOK_LAND ? अभिव्यक्ती_or() : अभिव्यक्ती_land()
#अन्यथा /* defined precedence_parser */
# define अभिव्यक्ती_landor_next(op) unary(), अभिव्यक्ती_infix(precedence(op) + 1)
# define अभिव्यक्ती_lor() unary(), अभिव्यक्ती_infix(1)

स्थिर पूर्णांक precedence(पूर्णांक tok)
{
    निवड (tok) {
        स्थिती TOK_LOR: परत 1;
        स्थिती TOK_LAND: परत 2;
	स्थिती '|': परत 3;
	स्थिती '^': परत 4;
	स्थिती '&': परत 5;
	स्थिती TOK_EQ: स्थिती TOK_NE: परत 6;
 relat: स्थिती TOK_ULT: स्थिती TOK_UGE: परत 7;
	स्थिती TOK_SHL: स्थिती TOK_SAR: परत 8;
	स्थिती '+': स्थिती '-': परत 9;
	स्थिती '*': स्थिती '/': स्थिती '%': परत 10;
	पूर्वनिर्धारित:
	    जर (tok >= TOK_ULE && tok <= TOK_GT)
	        जा relat;
	    परत 0;
    }
}
स्थिर अचिन्हित अक्षर prec[256];
स्थिर शून्य init_prec(शून्य)
{
    पूर्णांक i;
    साठी (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#define precedence(i) ((अचिन्हित)i < 256 ? prec[i] : 0)

स्थिर शून्य अभिव्यक्ती_landor(पूर्णांक op);

स्थिर शून्य अभिव्यक्ती_infix(पूर्णांक p)
{
    पूर्णांक t = tok, p2;
    पर्यंत ((p2 = precedence(t)) >= p) {
        जर (t == TOK_LOR || t == TOK_LAND) {
            अभिव्यक्ती_landor(t);
        } अन्यथा {
            next();
            unary();
            जर (precedence(tok) > p2)
              अभिव्यक्ती_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#endif

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
स्थिर पूर्णांक condition_3way(शून्य)
{
    पूर्णांक c = -1;
    जर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    परत c;
}

स्थिर शून्य अभिव्यक्ती_landor(पूर्णांक op)
{
    पूर्णांक t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    साठी(;;) {
        c = f ? i : condition_3way();
        जर (c < 0)
            save_regs(1), cc = 0;
        अन्यथा जर (c != i)
            nocode_wanted++, f = 1;
        जर (tok != op)
            थांबा;
        जर (c < 0)
            t = gvtst(i, t);
        अन्यथा
            vpop();
        next();
        अभिव्यक्ती_landor_next(op);
    }
    जर (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } अन्यथा {
        gvtst_set(i, t);
    }
}

स्थिर पूर्णांक is_cond_bool(SValue *sv)
{
    जर ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        परत (अचिन्हित)sv->c.i < 2;
    जर (sv->r == VT_CMP)
        परत 1;
    परत 0;
}

स्थिर शून्य अभिव्यक्ती_cond(शून्य)
{
    पूर्णांक tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    अभिव्यक्ती_lor();
    जर (tok == '?') {
        next();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        जर (!g) {
            जर (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } अन्यथा {
                vpop();
            }
        } अन्यथा जर (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        जर (c == 0)
          nocode_wanted++;
        जर (!g)
          gexpr();

        जर ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        जर (g) {
            u = tt;
        } अन्यथा जर (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } अन्यथा
          u = 0;

        जर (c == 0)
          nocode_wanted--;
        जर (c == 1)
          nocode_wanted++;
        skip(':');
        अभिव्यक्ती_cond();

        जर ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        जर (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        जर (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            परत;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        जर (c != 1) {
            gen_cast(&type);
            जर (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        जर (USING_TWO_शब्द(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        जर (c < 0) {
            जर (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        जर (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        जर (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            जर (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        जर (c < 0) {
            जर (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        जर (islv)
          indir();
    }
}

स्थिर शून्य अभिव्यक्ती_eq(शून्य)
{
    पूर्णांक t;
    
    अभिव्यक्ती_cond();
    जर ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        next();
        जर (t == '=') {
            अभिव्यक्ती_eq();
        } अन्यथा {
            vdup();
            अभिव्यक्ती_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC शून्य gexpr(शून्य)
{
    अभिव्यक्ती_eq();
    जर (tok == ',') {
        करा {
            vpop();
            next();
            अभिव्यक्ती_eq();
        } पर्यंत (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        जर ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            जर (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
स्थिर शून्य अभिव्यक्ती_const1(शून्य)
{
    nocode_wanted += CONST_WANTED_BIT;
    अभिव्यक्ती_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
स्थिर ओळीत int64_t अभिव्यक्ती_const64(शून्य)
{
    int64_t c;
    अभिव्यक्ती_const1();
    जर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    परत c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC पूर्णांक अभिव्यक्ती_const(शून्य)
{
    पूर्णांक c;
    int64_t wc = अभिव्यक्ती_const64();
    c = wc;
    जर (c != wc && (अचिन्हित)c != wc)
        tcc_error("constant exceeds 32 bit");
    परत c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#ifndef TCC_TARGET_ARM64
स्थिर शून्य gfunc_return(CType *func_type)
{
    जर ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        पूर्णांक ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        जर (ret_nregs < 0) {
#ifdef TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#endif
        } अन्यथा जर (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_pointer(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } अन्यथा {
            /* returning structure packed into registers */
            पूर्णांक size, addr, align, rc, n;
            size = type_size(func_type,&align);
            जर (ret_nregs * regsize > size ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		जर (ret_nregs * regsize > size)
		    size = ret_nregs * regsize;
		जर (ret_align > align)
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
            साठी (n = ret_nregs; --n > 0;) {
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
    } अन्यथा {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#endif

स्थिर शून्य check_func_return(शून्य)
{
    जर ((func_vt.t & VT_BTYPE) == VT_VOID)
        परत;
    जर ((!म_भेद(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } अन्यथा {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

स्थिर पूर्णांक case_cmp(uint64_t a, uint64_t b)
{
    जर (cur_switch->sv.type.t & VT_UNSIGNED)
        परत a < b ? -1 : a > b;
    अन्यथा
        परत (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

स्थिर पूर्णांक case_cmp_qs(स्थिरांक शून्य *pa, स्थिरांक शून्य *pb)
{
    परत case_cmp((*(संरचना case_t**)pa)->v1, (*(संरचना case_t**)pb)->v1);
}

स्थिर शून्य case_sort(संरचना switch_t *sw)
{
    संरचना case_t **p;
    जर (sw->n < 2)
        परत;
    क्विक(sw->p, sw->n, आकार *sw->p, case_cmp_qs);
    p = sw->p;
    पर्यंत (p < sw->p + sw->n - 1) {
        जर (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            पूर्णांक l1 = p[0]->ओळ, l2 = p[1]->ओळ;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } अन्यथा जर (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            स_हटाओ(p, p + 1, (--sw->n - (p - sw->p)) * आकार *p);
        } अन्यथा
            ++p;
    }
}

स्थिर पूर्णांक gcase(संरचना case_t **base, पूर्णांक len, पूर्णांक dsym)
{
    संरचना case_t *p;
    पूर्णांक t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    जर (t != VT_LLONG)
        t = VT_INT;
    पर्यंत (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        जर (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } अन्यथा {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            जर (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            अन्यथा
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
    परत gjmp(dsym);
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
    पर्यंत (sv >= vstack) {
        जर (sv->sym && (sv->r & VT_LVAL)) {
            पूर्णांक align, size = type_size(&sv->type, &align);
            पूर्णांक r2, l = get_temp_local_var(size, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

स्थिर शून्य try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    साठी (; cls != stop; cls = cls->next) {
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
    पूर्णांक ocd, ccd;

    जर (!cur_scope->cl.s)
	परत;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    साठी (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->next)
      ;
    साठी (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->next)
      ;
    साठी (; cc != oc; cc = cc->next, oc = oc->next, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
स्थिर शून्य block_cleanup(संरचना scope *o)
{
    पूर्णांक jmp = 0;
    Sym *g, **pg;
    साठी (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        जर (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->next;
            जर (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            जर (!o->cl.n)
                जा remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } अन्यथा {
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

स्थिर शून्य vla_restore(पूर्णांक loc)
{
    जर (loc)
        gen_vla_sp_restore(loc);
}

स्थिर शून्य vla_leave(संरचना scope *o)
{
    संरचना scope *c = cur_scope, *v = रिक्त;
    साठी (; c != o && c; c = c->prev)
      जर (c->vla.अंक)
        v = c;
    जर (v)
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
    cur_scope->vla.अंक = 0;

    /* record local declaration stack position */
    o->lstk = local_चळत;
    o->llstk = local_label_चळत;
    ++local_scope;
}

स्थिर शून्य prev_scope(संरचना scope *o, पूर्णांक is_अभिव्यक्ती)
{
    vla_leave(o->prev);

    जर (o->cl.s != o->prev->cl.s)
        block_cleanup(o->prev);

    जर (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_अभिव्यक्ती);

    /* pop locally defined labels */
    label_काढा(&local_label_चळत, o->llstk, is_अभिव्यक्ती);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_काढा(&local_चळत, o->lstk, is_अभिव्यक्ती);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
स्थिर शून्य leave_scope(संरचना scope *o)
{
    जर (!o)
        परत;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
स्थिर शून्य new_scope_s(संरचना scope *o)
{
    o->lstk = local_चळत;
    ++local_scope;
}

स्थिर शून्य prev_scope_s(संरचना scope *o)
{
    sym_काढा(&local_चळत, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

स्थिर शून्य lblock(पूर्णांक *bsym, पूर्णांक *csym)
{
    संरचना scope *lo = loop_scope, *co = cur_scope;
    पूर्णांक *b = co->bsym, *c = co->csym;
    जर (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    जर (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
स्थिर शून्य gexpr_decl(शून्य)
{
    पूर्णांक v = decl(VT_JMP);
    जर (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } अन्यथा {
        जर (v)
            skip(';');
        gexpr();
    }
}

स्थिर शून्य block(पूर्णांक flags)
{
    पूर्णांक a, b, c, d, e, t;
    संरचना scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    जर (TOK_HAS_मूल्य(t))
        जा अभिव्यक्ती;
    next();

    जर (debug_modes)
        tcc_tcov_check_ओळ (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    जर (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        जर (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            next();
            block(0);
            gsym(d); /* patch else jmp */
        } अन्यथा {
            gsym(a);
        }
        prev_scope_s(&o);

    } अन्यथा जर (t == TOK_WHILE) {
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

    } अन्यथा जर (t == '{') {
        जर (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        पर्यंत (tok == TOK_LABEL) {
            करा {
                next();
                जर (tok < TOK_UIDENT)
                    expect("label identifier");
                label_ढकला(&local_label_चळत, tok, LABEL_DECLARED);
                next();
            } पर्यंत (tok == ',');
            skip(';');
        }

        पर्यंत (tok != '}') {
	    decl(VT_LOCAL);
            जर (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_अभिव्यक्ती);
        जर (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        जर (local_scope)
            next();
        अन्यथा जर (!nocode_wanted)
            check_func_return();

    } अन्यथा जर (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        जर (tok != ';') {
            gexpr();
            जर (b) {
                gen_assign_cast(&func_vt);
            } अन्यथा {
                जर (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } अन्यथा जर (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } अन्यथा जर (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(मूळ_scope);
        जर (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        जर (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        जर (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } अन्यथा जर (t == TOK_BREAK) {
        /* compute jump */
        जर (!cur_scope->bsym)
            tcc_error("cannot break");
        जर (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        अन्यथा
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } अन्यथा जर (t == TOK_CONTINUE) {
        /* compute jump */
        जर (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } अन्यथा जर (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        जर (tok != ';') {
            /* c99 for-loop init decl? */
            जर (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        जर (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        जर (tok != ')') {
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

    } अन्यथा जर (t == TOK_DO) {
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

    } अन्यथा जर (t == TOK_SWITCH) {
        संरचना switch_t *sw;

        sw = tcc_mallocz(आकार *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        जर (!is_integer_btype(vtop->type.t & VT_BTYPE))
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
        जर (sw->nocode_wanted)
            जा skip_switch;
        case_sort(sw);
        sw->bsym = रिक्त; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        जर (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        अन्यथा
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } अन्यथा जर (t == TOK_CASE) {
        संरचना case_t *cr;
        जर (!cur_switch)
            expect("switch");
        cr = tcc_malloc(आकार(संरचना case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(अभिव्यक्ती_const64(), t);
        जर (tok == TOK_DOTS && gnu_ext) {
            next();
            cr->v2 = value64(अभिव्यक्ती_const64(), t);
            जर (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        जर (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->ओळ = file->ओळ_अंक;
        skip(':');
        जा block_after_label;

    } अन्यथा जर (t == TOK_DEFAULT) {
        जर (!cur_switch)
            expect("switch");
        जर (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        जा block_after_label;

    } अन्यथा जर (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        जर (tok == '*' && gnu_ext) {
            /* computed goto */
            next();
            gexpr();
            जर ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } अन्यथा जर (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            जर (!s)
              s = label_ढकला(&global_label_चळत, tok, LABEL_FORWARD);
            अन्यथा जर (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    जर (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		जर (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->next, SYM_FIELD, 0, 0);
                    pending_gotos->next = s;
                }
		s->jnext = gjmp(s->jnext);
	    } अन्यथा {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    next();

        } अन्यथा {
            expect("label identifier");
        }
        skip(';');

    } अन्यथा जर (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } अन्यथा {
        जर (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    next();
            s = label_find(t);
            जर (s) {
                जर (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, रिक्त));
                s->r = LABEL_DEFINED;
		जर (s->next) {
		    Sym *pcl; /* pending cleanup goto */
		    साठी (pcl = s->next; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_काढा(&s->next, रिक्त, 0);
		} अन्यथा
		  gsym(s->jnext);
            } अन्यथा {
                s = label_ढकला(&global_label_चळत, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(रिक्त);

            जर (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            जर (tok != '}') {
                जर (0 == (flags & STMT_COMPOUND))
                    जा again;
                /* C23: insert implicit null-statement whithin compound statement */
            } अन्यथा {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } अन्यथा {
            /* expression case */
            जर (t != ';') {
                unget_tok(t);
    अभिव्यक्ती:
                जर (flags & STMT_अभिव्यक्ती) {
                    vpop();
                    gexpr();
                } अन्यथा {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    जर (debug_modes)
        tcc_tcov_check_ओळ (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
स्थिर शून्य skip_or_save_block(TokenString **str)
{
    पूर्णांक braces = tok == '{';
    पूर्णांक level = 0;
    जर (str)
      *str = tok_str_alloc();

    पर्यंत (1) {
	पूर्णांक t = tok;
        जर (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             थांबा;
	जर (t == TOK_EOF) {
	     जर (str || level > 0)
	       tcc_error("unexpected end of file");
	     अन्यथा
	       थांबा;
	}
	जर (str)
	  tok_str_add_tok(*str);
	next();
	जर (t == '{' || t == '(' || t == '[') {
	    level++;
	} अन्यथा जर (t == '}' || t == ')' || t == ']') {
	    level--;
	    जर (level == 0 && braces && t == '}')
	      थांबा;
	}
    }
    जर (str)
	tok_str_add(*str, TOK_EOF);
}

#define अभिव्यक्ती_CONST 1
#define अभिव्यक्ती_ANY   2

स्थिर शून्य parse_init_elem(पूर्णांक अभिव्यक्ती_type)
{
    पूर्णांक saved_global_अभिव्यक्ती;
    निवड(अभिव्यक्ती_type) {
    स्थिती अभिव्यक्ती_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_अभिव्यक्ती = global_अभिव्यक्ती;
        global_अभिव्यक्ती = 1;
        अभिव्यक्ती_const1();
        global_अभिव्यक्ती = saved_global_अभिव्यक्ती;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        जर (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#ifdef TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#endif
           )
            tcc_error("initializer element is not constant");
        थांबा;
    स्थिती अभिव्यक्ती_ANY:
        अभिव्यक्ती_eq();
        थांबा;
    }
}

#जर 1
स्थिर शून्य init_assert(init_params *p, पूर्णांक offset)
{
    जर (p->sec ? !NODATA_WANTED && offset > p->sec->data_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#अन्यथा
#define init_assert(sec, offset)
#endif

/* put zeros for variable based init */
स्थिर शून्य init_putz(init_params *p, अचिन्हित दीर्घ c, पूर्णांक size)
{
    init_assert(p, c + size);
    जर (p->sec) {
        /* nothing to do because globals are already set to zero */
    } अन्यथा {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(size);
#जर defined TCC_TARGET_ARM && defined TCC_ARM_EABI
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
स्थिर शून्य decl_design_delrels(Section *sec, पूर्णांक c, पूर्णांक size)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    जर (!sec || !sec->reloc)
        परत;
    rel = rel2 = (ElfW_Rel*)sec->reloc->data;
    rel_end = (ElfW_Rel*)(sec->reloc->data + sec->reloc->data_offset);
    पर्यंत (rel < rel_end) {
        जर (rel->r_offset >= c && rel->r_offset < c + size) {
            sec->reloc->data_offset -= आकार *rel;
        } अन्यथा {
            जर (rel2 != rel)
                स_नकल(rel2, rel, आकार *rel);
            ++rel2;
        }
        ++rel;
    }
}

स्थिर शून्य decl_design_flex(init_params *p, Sym *ref, पूर्णांक index)
{
    जर (ref == p->flex_array_ref) {
        जर (index >= ref->c)
            ref->c = index + 1;
    } अन्यथा जर (ref->c < 0 && index >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
स्थिर पूर्णांक decl_designator(init_params *p, CType *type, अचिन्हित दीर्घ c,
                           Sym **cur_field, पूर्णांक flags, पूर्णांक al)
{
    Sym *s, *f;
    पूर्णांक index, index_last, align, l, nb_elems, elem_size;
    अचिन्हित दीर्घ corig = c;

    elem_size = 0;
    nb_elems = 1;

    जर (flags & DIF_HAVE_ELEM)
        जा no_designator;

    जर (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, next();
        जर (tok == ':')
            जा struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    पर्यंत (nb_elems == 1 && (tok == '[' || tok == '.')) {
        जर (tok == '[') {
            जर (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = अभिव्यक्ती_const();
            जर (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = अभिव्यक्ती_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, index_last);
            जर (index < 0 || index_last >= s->c || index_last < index)
	        tcc_error("index exceeds array bounds or range is empty");
            जर (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } अन्यथा {
            पूर्णांक cumofs;
            next();
            l = tok;
        struct_field:
            next();
	    f = find_field(type, l, &cumofs);
            जर (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = रिक्त;
    }
    जर (!cur_field) {
        जर (tok == '=') {
            next();
        } अन्यथा जर (!gnu_ext) {
	    expect("=");
        }
    } अन्यथा {
    no_designator:
        जर (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, index);
            जर (index >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
        } अन्यथा {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    पर्यंत (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->next;
            जर (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    जर (!elem_size) /* for structs */
        elem_size = type_size(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    जर (!(flags & DIF_SIZE_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_size * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    जर (!(flags & DIF_SIZE_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        पूर्णांक i;
        जर (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_size;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        जर (p->sec)
            vpush_ref(type, p->sec, c, elem_size);
        अन्यथा
	    vset(type, VT_LOCAL|VT_LVAL, c);
        साठी (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_size * i);
	}
        vpop();
    }

    c += nb_elems * elem_size;
    जर (c - corig > al)
      al = c - corig;
    परत al;
}

स्थिर शून्य write_ldouble(अचिन्हित अक्षर *d, शून्य *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#ifdef TCC_CROSS_TEST
    जर (LDOUBLE_SIZE >= 10) {
        द्विगुण b = *(दीर्घ द्विगुण*)s;
        s = &b;
#अन्यथा
    जर (आकार (दीर्घ द्विगुण) == 8 && LDOUBLE_SIZE >= 10) {
#endif
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        पूर्णांक e = m >> 48;
        पूर्णांक f = e >> 4 & 0x7FF;
        m <<= 11;
        जर (0 == f) {
            जर (0 == m)
                जा set;
            साठी (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        जर (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #जर (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #किंवाजर LDOUBLE_SIZE == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #endif
        ;
    } अन्यथा {
    #जर LDOUBLE_SIZE == 8
        /* long double -> double */
        द्विगुण b = *(दीर्घ द्विगुण*)s;
        स_नकल(d, &b, 8);
    #किंवाजर (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        स_नकल(d, s, 10);
    #किंवाजर (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        पूर्णांक e = *(uint16_t*)((अक्षर*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #किंवाजर (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((अक्षर*)s + 6);
        पूर्णांक e = read16le((अक्षर*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #अन्यथा
        /* unknown */
        जर (आकार (दीर्घ द्विगुण) == LDOUBLE_SIZE)
            स_नकल(d, s, LDOUBLE_SIZE);
    #endif
    }
}

/* store a value or an expression directly in global data or in local array */
स्थिर शून्य init_putv(init_params *p, CType *type, अचिन्हित दीर्घ c)
{
    पूर्णांक bt;
    शून्य *ptr;
    CType dtype;
    पूर्णांक size, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    size = type_size(type, &align);
    जर (type->t & VT_BITFIELD)
        size = (BIT_POS(type->t) + BIT_SIZE(type->t) + 7) / 8;
    init_assert(p, c + size);

    जर (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        जर ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        जर (NODATA_WANTED) {
            vtop--;
            परत;
        }

        ptr = sec->data + c;
        val = vtop->c.i;

	जर ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    स_हटाओ (ptr, ssec->data + esym->st_मूल्य + (पूर्णांक)vtop->c.i, size);
	    जर (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                अचिन्हित दीर्घ relofs = ssec->reloc->data_offset;
		पर्यंत (relofs >= आकार(*rel)) {
                    relofs -= आकार(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->data + relofs);
		    जर (rel->r_offset >= esym->st_मूल्य + size)
		      सुरूठेवा;
		    जर (rel->r_offset < esym->st_मूल्य)
		      थांबा;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_मूल्य,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#जर PTR_SIZE == 8
				   rel->r_addend
#अन्यथा
				   0
#endif
				  );
		}
	    }
	} अन्यथा {
            जर (type->t & VT_BITFIELD) {
                पूर्णांक bit_pos, bit_size, bits, n;
                अचिन्हित अक्षर *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (अचिन्हित अक्षर*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                पर्यंत (bit_size) {
                    n = 8 - bit_pos;
                    जर (n > bit_size)
                        n = bit_size;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } अन्यथा
            निवड(bt) {
	    स्थिती VT_BOOL:
		*(अक्षर *)ptr = val != 0;
                थांबा;
	    स्थिती VT_BYTE:
		*(अक्षर *)ptr = val;
		थांबा;
	    स्थिती VT_SHORT:
                write16le(ptr, val);
		थांबा;
	    स्थिती VT_FLOAT:
                write32le(ptr, val);
		थांबा;
	    स्थिती VT_DOUBLE:
                write64le(ptr, val);
		थांबा;
	    स्थिती VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		थांबा;

#जर PTR_SIZE == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    स्थिती VT_LLONG:
	    स्थिती VT_PTR:
	        जर (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_DATA_PTR, val);
	        अन्यथा
	          write64le(ptr, val);
	        थांबा;
            स्थिती VT_INT:
                write32le(ptr, val);
                थांबा;
#अन्यथा
	    स्थिती VT_LLONG:
                write64le(ptr, val);
                थांबा;
            स्थिती VT_PTR:
            स्थिती VT_INT:
	        जर (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_DATA_PTR);
	        write32le(ptr, val);
	        थांबा;
#endif
	    पूर्वनिर्धारित:
                //tcc_internal_error("unexpected type");
                थांबा;
	    }
	}
        vtop--;
    } अन्यथा {
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
स्थिर शून्य decl_initializer(init_params *p, CType *type, अचिन्हित दीर्घ c, पूर्णांक flags)
{
    पूर्णांक len, n, no_oblock, i;
    पूर्णांक size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    जर (debug_modes && !(flags & DIF_SIZE_ONLY) && !p->sec)
        tcc_debug_ओळ(tcc_state), tcc_tcov_check_ओळ (tcc_state, 1);

    जर (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        पूर्णांक ncw_prev = nocode_wanted;
        जर ((flags & DIF_SIZE_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? अभिव्यक्ती_ANY : अभिव्यक्ती_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    जर (type->t & VT_ARRAY) {
        no_oblock = 1;
        जर (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        जर ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#अन्यथा
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            जर (size1 != (tok == TOK_STR ? 1 : आकार(nwchar_t)))
              tcc_error("unhandled string literal merging");
            पर्यंत (tok == TOK_STR || tok == TOK_LSTR) {
                जर (initstr.size)
                  initstr.size -= size1;
                जर (tok == TOK_STR)
                  len += tokc.str.size;
                अन्यथा
                  len += tokc.str.size / आकार(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.data, tokc.str.size);
                next();
            }
            जर (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.size = initstr.size;
                tokc.str.data = initstr.data;
                जा do_init_array;
            }

            decl_design_flex(p, s, len);
            जर (!(flags & DIF_SIZE_ONLY)) {
                पूर्णांक nb = n, ch;
                जर (len < nb)
                    nb = len;
                जर (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                जर (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    जर (!NODATA_WANTED)
                      स_नकल(p->sec->data + c, initstr.data, nb);
                } अन्यथा {
                    साठी(i=0;i<n;i++) {
                        जर (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          जर (flags & DIF_CLEAR)
                            थांबा;
                          जर (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            थांबा;
                          }
                          ch = 0;
                        } अन्यथा जर (size1 == 1)
                          ch = ((अचिन्हित अक्षर *)initstr.data)[i];
                        अन्यथा
                          ch = ((nwchar_t *)initstr.data)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            जर (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                next();
        } अन्यथा {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            जर (!(flags & (DIF_CLEAR | DIF_SIZE_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    पर्यंत (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		जर (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    जर (no_oblock && len >= n*size1)
		        थांबा;
		} अन्यथा {
		    जर (s->type.t == VT_UNION)
		        f = रिक्त;
		    अन्यथा
		        f = f->next;
		    जर (no_oblock && f == रिक्त)
		        थांबा;
		}

		जर (tok == '}')
		    थांबा;
		skip(',');
	    }
        }
        जर (!no_oblock)
            skip('}');

    } अन्यथा जर ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        जा one_elem;

    } अन्यथा जर ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        जर ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        size1 = 1;
	जा do_init_list;

    } अन्यथा जर (tok == '{') {
        जर (flags & DIF_HAVE_ELEM)
          skip(';');
        next();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } अन्यथा one_elem: जर ((flags & DIF_SIZE_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        जर (flags & DIF_HAVE_ELEM)
            vpop();
        अन्यथा
            skip_or_save_block(रिक्त);

    } अन्यथा {
	जर (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    जर (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? अभिव्यक्ती_ANY : अभिव्यक्ती_CONST);
	}
        जर (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_size(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        अन्यथा
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
स्थिर शून्य decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णांक r, 
                                   पूर्णांक has_init, पूर्णांक v, पूर्णांक scope)
{
    पूर्णांक size, align, addr;
    TokenString *init_str = रिक्त;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = रिक्त;
    पूर्णांक saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    पूर्णांक bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif
    init_params p = {0};

    जर (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        जर (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            जर (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                परत;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    जर (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= DATA_ONLY_WANTED;

    flexible_array = रिक्त;
    size = type_size(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    जर (size < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        जर (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        जर (IS_BT_ARRAY(type->t))
            type->ref = sym_ढकला(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } अन्यथा जर (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        जर (field) {
            पर्यंत (field->next)
                field = field->next;
            जर (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                size = -1;
            }
        }
    }

    जर (size < 0) {
        /* If unknown size, do a dry-run 1st pass */
        जर (!has_init)
            जा err_size;
        जर (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            पर्यंत (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
            tok_str_add(init_str, TOK_EOF);
        } अन्यथा
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
        जर (size < 0)
    err_size:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        जर (flexible_array && flexible_array->type.ref->c > 0)
            size += flexible_array->type.ref->c
                    * pointed_size(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    जर (ad->a.aligned) {
	पूर्णांक speca = 1 << (ad->a.aligned - 1);
        जर (speca > align)
            align = speca;
    } अन्यथा जर (ad->a.packed) {
        align = 1;
    }

    जर (!v && NODATA_WANTED)
        size = 0, align = 1;

    जर ((r & VT_VALMASK) == VT_LOCAL) {
        sec = रिक्त;
#ifdef CONFIG_TCC_BCHECK
        जर (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
        p.local_offset = addr + size;
#ifdef CONFIG_TCC_BCHECK
        जर (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#endif
        जर (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    जर (ad->asm_label) {
		पूर्णांक reg = asm_parse_regvar(ad->asm_label);
		जर (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_ढकला(v, type, r, addr);
	    जर (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->next = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } अन्यथा {
            /* push local reference */
            vset(type, r, addr);
        }
    } अन्यथा {
        CType *tp = type;
        पूर्णांक is_const;

        पर्यंत ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        जर (!sec) {
            जर (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } अन्यथा जर (is_const) {
		sec = rodata_section;
            } अन्यथा जर (has_init) {
		sec = data_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } अन्यथा जर (tcc_state->nocommon)
                sec = bss_section;
        } अन्यथा जर (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            जर (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                जर (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#ifdef CONFIG_TCC_BCHECK
        जर (bcheck)
            size = size + 1; /* add padding */
#endif
        जर (sec) {
	    addr = section_add(sec, size, align);
        } अन्यथा {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        जर (v) {
            जर (!sym) {
                sym = sym_ढकला(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, रिक्त);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } अन्यथा {
            /* push global reference */
            vpush_ref(type, sec, addr, size);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        जर (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * आकार(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size - 1;
        }
#endif
    }

    जर (type->t & VT_VLA) {
        पूर्णांक a;

        जर (has_init)
            tcc_error("variable length array cannot be initialized");

        जर (NODATA_WANTED)
            जा no_alloc;

        /* save before-VLA stack pointer if needed */
        जर (cur_scope->vla.अंक == 0) {
            जर (cur_scope->prev && cur_scope->prev->vla.अंक) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } अन्यथा {
                gen_vla_sp_save(loc -= PTR_SIZE);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_size(type, &a);
        gen_vla_alloc(type, a);
#जर defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.अंक++;
    } अन्यथा जर (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        जर (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    जर (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
स्थिर शून्य func_vla_arg_code(Sym *arg)
{
    पूर्णांक align;
    TokenString *vla_array_tok = रिक्त;

    जर (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    जर ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
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

    साठी (arg = sym->type.ref->next; arg; arg = arg->next)
        जर ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, पूर्णांक c, पूर्णांक byref)
{
    s = sym_find(s->v);
    जर (!s) /* unnamed parameters, not enabled */
        परत रिक्त;
    s->c = c;
    जर (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    परत s;
}

/* push parameters (and their types), last first */
स्थिर शून्य sym_ढकला_params(Sym *ref)
{
    Sym *s = ref;
    पर्यंत (s->next)
        s = s->next;
    पर्यंत (s != ref) {
        जर ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_चळत);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
स्थिर शून्य gen_function(Sym *sym)
{
    संरचना scope f = { 0 };

    cur_scope = मूळ_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->data_offset;
    जर (sym->a.aligned) {
	माप_प्रकार newoff = section_add(cur_text_section, 0,
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

    जर (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    जर (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_चळत, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_ढकला_params(sym->type.ref);

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

    sym_काढा(&local_चळत, रिक्त, 0);
    label_काढा(&global_label_चळत, रिक्त, 0);
    sym_काढा(&all_cleanups, रिक्त, 0);
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
    पूर्णांक inline_generated, i;
    संरचना InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    करा {
        inline_generated = 0;
        साठी (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            जर (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
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
    } पर्यंत (inline_generated);
    tcc_close();
}

स्थिर शून्य free_inline_functions(TCCState *s)
{
    पूर्णांक i;
    /* free tokens of unused inline functions */
    साठी (i = 0; i < s->nb_inline_fns; ++i) {
        संरचना InlineFunc *fn = s->inline_fns[i];
        जर (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

स्थिर शून्य do_Static_assert(शून्य)
{
    पूर्णांक c;
    स्थिरांक अक्षर *संदेश;

    next();
    skip('(');
    c = अभिव्यक्ती_const();
    संदेश = "_Static_assert fail";
    जर (tok == ',') {
        next();
        संदेश = parse_mult_str("string constant")->data;
    }
    skip(')');
    जर (c == 0)
        tcc_error("%s", संदेश);
    skip(';');
}

#ifdef TCC_TARGET_PE
स्थिर शून्य pe_check_linkage(CType *type, AttributeDef *ad)
{
    जर (!ad->a.dllimport && !ad->a.dllexport)
        परत;
    जर (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    जर (type->t & VT_TYPEDEF) {
        स्थिरांक अक्षर *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } अन्यथा जर (ad->a.dllimport) {
        जर ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        अन्यथा
            type->t |= VT_EXTERN;
    }
}
#endif

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
स्थिर पूर्णांक decl(पूर्णांक l)
{
    पूर्णांक v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    पर्यंत (1) {

        oldint = 0;
        जर (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            जर (l == VT_JMP)
                परत 0;
            /* skip redundant ';' if not in old parameter decl scope */
            जर (tok == ';' && l != VT_CMP) {
                next();
                सुरूठेवा;
            }
            जर (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                सुरूठेवा;
            }
            जर (l != VT_CONST)
                थांबा;
            जर (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                सुरूठेवा;
            }
            जर (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } अन्यथा {
                जर (tok != TOK_EOF)
                    expect("declaration");
                थांबा;
            }
        }

        जर (tok == ';') {
            जर ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            अन्यथा जर (IS_ENUM(btype.t))
                ; /* enum decl */
            अन्यथा
                tcc_warning("useless type defines no instances");
            जर (l == VT_JMP)
                परत 1;
            next();
            सुरूठेवा;
        }

        पर्यंत (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            जर ((type.t & VT_BTYPE) == VT_FUNC) {
                जर ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                जर (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                जर ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    जर (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    अन्यथा
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } अन्यथा जर (oldint) {
                tcc_warning("type defaults to int");
            }

            जर (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #जर 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                जर (tok == '{')
                    expect(";");
            #endif
            }

#ifdef TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#endif
            जर (tok == '{') {
                जर (l != VT_CONST)
                    tcc_error("cannot use local functions");
                जर ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                साठी (sa = sym->type.ref; (sa = sa->next) != रिक्त;) {
                    जर (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    जर (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                जर (sym->type.t & VT_INLINE) {
                    संरचना InlineFunc *fn;
                    fn = tcc_malloc(आकार *fn + म_माप(file->filename));
                    म_नकल(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } अन्यथा {
                    /* compute text section */
                    cur_text_section = text_section;
                    जर (ad.section) {
                        cur_text_section = ad.section;
                        जर (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                थांबा;
            } अन्यथा {
                has_init = 0;
		जर (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    साठी (sym = func_vt.ref->next; sym; sym = sym->next)
			जर ((sym->v & ~SYM_FIELD) == v)
			    जा found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, रिक्त));
                found:
		    जर (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, रिक्त));
		    जर (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, रिक्त));
		    convert_parameter_type(&type);
		    sym->type = type;
		} अन्यथा जर (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    जर (sym && sym->sym_scope == local_scope) {
                        जर (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, रिक्त));
                        sym->type = type;
                    } अन्यथा {
                        sym = sym_ढकला(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    जर ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    जर (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} अन्यथा जर ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } अन्यथा {
                    r = 0;
                    जर ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } अन्यथा जर (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    जर (tok == '=')
                        has_init = 1;

                    जर (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } अन्यथा {
                        जर (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        अन्यथा
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        जर (has_init)
                            next();
                        अन्यथा जर (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    जर (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        जर (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_मूल्य, esym->st_size, 1);
                    }
                }
                जर (tok != ',') {
                    जर (l == VT_JMP)
                        परत has_init ? v : 1;
                    skip(';');
                    थांबा;
                }
                next();
            }
        }
    }
    परत 0;
}

/* ------------------------------------------------------------------------- */
#undef gjmp_addr
#undef gjmp
/* ------------------------------------------------------------------------- */
