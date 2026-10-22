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

#घोषणा USING_GLOBALS
#समावेश "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_तथ्य पूर्णांक rsym, anon_sym, ind, loc;

ST_तथ्य Sym *global_ढेर;
ST_तथ्य Sym *local_ढेर;
ST_तथ्य Sym *define_ढेर;
ST_तथ्य Sym *global_label_ढेर;
ST_तथ्य Sym *local_label_ढेर;

अटल Sym *sym_free_first;
अटल व्योम **sym_pools;
अटल पूर्णांक nb_sym_pools;

अटल Sym *all_cleanups, *pending_gotos;
अटल पूर्णांक local_scope;
ST_तथ्य अक्षर debug_modes;

ST_तथ्य SValue *vtop;
अटल SValue _vstack[1 + VSTACK_आकार];
#घोषणा vstack (_vstack + 1)

ST_तथ्य पूर्णांक nocode_wanted; /* no code generation wanted */
#घोषणा NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#घोषणा तथ्य_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#घोषणा CODE_OFF_BIT 0x20000000
#घोषणा CODE_OFF() अगर(!nocode_wanted)(nocode_wanted |= CODE_OFF_BIT)
#घोषणा CODE_ON() (nocode_wanted &= ~CODE_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#घोषणा NOEVAL_MASK 0x0000FFFF
#घोषणा NOEVAL_WANTED (nocode_wanted & NOEVAL_MASK)

/* no code output when parsing constant expressions */
#घोषणा CONST_WANTED_BIT  0x00010000
#घोषणा CONST_WANTED_MASK 0x0FFF0000
#घोषणा CONST_WANTED  (nocode_wanted & CONST_WANTED_MASK)

ST_तथ्य पूर्णांक global_व्यंजक;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_तथ्य CType func_vt; /* current function return type (used by return instruction) */
ST_तथ्य पूर्णांक func_var; /* true if current function is variadic (used by return instruction) */
ST_तथ्य पूर्णांक func_vc; /* stack address for implicit struct return storage */
ST_तथ्य पूर्णांक func_ind; /* function start address */
अटल पूर्णांक func_old;
ST_तथ्य स्थिर अक्षर *funcname;
ST_तथ्य CType int_type, func_old_type, char_type, char_pointer_type;
अटल CString initstr;

#अगर PTR_आकार == 4
#घोषणा VT_आकार_T (VT_INT | VT_UNSIGNED)
#घोषणा VT_PTRDIFF_T VT_INT
#या_अगर LONG_आकार == 4
#घोषणा VT_आकार_T (VT_LLONG | VT_UNSIGNED)
#घोषणा VT_PTRDIFF_T VT_LLONG
#अन्यथा
#घोषणा VT_आकार_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#घोषणा VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#पूर्ण_अगर

अटल काष्ठा switch_t {
    काष्ठा case_t {
        int64_t v1, v2;
        पूर्णांक ind, पंक्ति_2;
    } **p; पूर्णांक n; /* list of case ranges */
    पूर्णांक def_sym; /* default symbol */
    पूर्णांक nocode_wanted;
    पूर्णांक *bsym;
    काष्ठा scope *scope;
    काष्ठा switch_t *पूर्व;
    SValue sv;
} *cur_switch; /* current switch */

#घोषणा MAX_अस्थायी_LOCAL_VARIABLE_संख्या 8
/*list of temporary local variables on the stack in current function. */
अटल काष्ठा अस्थायी_local_variable {
	पूर्णांक location; //offset on stack. Svalue.c.i
	लघु आकार;
	लघु align;
} arr_अस्थायी_local_vars[MAX_अस्थायी_LOCAL_VARIABLE_संख्या];
अटल पूर्णांक nb_अस्थायी_local_vars;

अटल काष्ठा scope {
    काष्ठा scope *पूर्व;
    काष्ठा { पूर्णांक loc, locorig, अंक; } vla;
    काष्ठा { Sym *s; पूर्णांक n; } cl;
    पूर्णांक *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *मूल_scope;

प्रकार काष्ठा {
    Section *sec;
    पूर्णांक local_offset;
    Sym *flex_array_ref;
} init_params;

#अगर 1
#घोषणा precedence_parser
अटल व्योम init_prec(व्योम);
#पूर्ण_अगर

अटल व्योम block(पूर्णांक flags);
#घोषणा STMT_व्यंजक 1
#घोषणा STMT_COMPOUND 2

अटल व्योम gen_cast(CType *type);
अटल व्योम gen_cast_s(पूर्णांक t);
अटल अंतरभूत CType *pointed_type(CType *type);
अटल व्योम check_restrict_type(CType *type);
अटल पूर्णांक type_qualifiers(CType *type);
अटल व्योम parse_btype_qualify(CType *type, पूर्णांक qualifiers);
अटल पूर्णांक is_compatible_types(CType *type1, CType *type2);
अटल पूर्णांक parse_btype(CType *type, AttributeDef *ad, पूर्णांक ignore_label);
अटल CType *type_decl(CType *type, AttributeDef *ad, पूर्णांक *v, पूर्णांक td);
अटल व्योम parse_व्यंजक_type(CType *type);
अटल व्योम init_putv(init_params *p, CType *type, अचिन्हित दीर्घ c);
अटल व्योम decl_initializer(init_params *p, CType *type, अचिन्हित दीर्घ c, पूर्णांक flags);
अटल व्योम decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णांक r, पूर्णांक has_init, पूर्णांक v, पूर्णांक scope);
अटल पूर्णांक decl(पूर्णांक l);
अटल व्योम व्यंजक_eq(व्योम);
अटल व्योम vpush_type_आकार(CType *type, पूर्णांक *a);
अटल पूर्णांक is_compatible_unqualified_types(CType *type1, CType *type2);
अटल अंतरभूत int64_t व्यंजक_const64(व्योम);
अटल व्योम vpush64(पूर्णांक ty, अचिन्हित दीर्घ दीर्घ v);
अटल व्योम vpush(CType *type);
अटल पूर्णांक gvtst(पूर्णांक inv, पूर्णांक t);
अटल व्योम gen_inline_functions(TCCState *s);
अटल व्योम free_inline_functions(TCCState *s);
अटल व्योम skip_or_save_block(TokenString **str);
अटल व्योम gv_dup(व्योम);
अटल पूर्णांक get_अस्थायी_local_var(पूर्णांक आकार,पूर्णांक align,पूर्णांक *r2);
अटल व्योम cast_error(CType *st, CType *dt);
अटल व्योम end_switch(व्योम);
अटल व्योम do_Static_assert(व्योम);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC व्योम gsym(पूर्णांक t)
{
  अगर (t) {
    gsym_addr(t, ind);
    CODE_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
अटल पूर्णांक gind()
{
  पूर्णांक t = ind;
  CODE_ON();
  अगर (debug_modes)
    tcc_tcov_block_begin(tcc_state);
  वापस t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
अटल व्योम gjmp_addr_acs(पूर्णांक t)
{
  gjmp_addr(t);
  CODE_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
अटल पूर्णांक gjmp_acs(पूर्णांक t)
{
  t = gjmp(t);
  CODE_OFF();
  वापस t;
}

/* These are #undef'd at the end of this file */
#घोषणा gjmp_addr gjmp_addr_acs
#घोषणा gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN पूर्णांक is_float(पूर्णांक t)
{
    पूर्णांक bt = t & VT_BTYPE;
    वापस bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

अटल अंतरभूत पूर्णांक is_integer_btype(पूर्णांक bt)
{
    वापस bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

अटल पूर्णांक btype_आकार(पूर्णांक bt)
{
    वापस bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_आकार : 0;
}

/* returns function return register from type */
अटल पूर्णांक R_RET(पूर्णांक t)
{
    अगर (!is_float(t))
        वापस REG_IRET;
#अगर_घोषित TCC_TARGET_X86_64
    अगर ((t & VT_BTYPE) == VT_LDOUBLE)
        वापस TREG_ST0;
#या_अगर defined TCC_TARGET_RISCV64
    अगर ((t & VT_BTYPE) == VT_LDOUBLE)
        वापस REG_IRET;
#पूर्ण_अगर
    वापस REG_FRET;
}

/* returns 2nd function return register, if any */
अटल पूर्णांक R2_RET(पूर्णांक t)
{
    t &= VT_BTYPE;
#अगर PTR_आकार == 4
    अगर (t == VT_LLONG)
        वापस REG_IRE2;
#या_अगर defined TCC_TARGET_X86_64
    अगर (t == VT_QLONG)
        वापस REG_IRE2;
    अगर (t == VT_QFLOAT)
        वापस REG_FRE2;
#या_अगर defined TCC_TARGET_RISCV64
    अगर (t == VT_LDOUBLE)
        वापस REG_IRE2;
#पूर्ण_अगर
    वापस VT_CONST;
}

/* returns true for two-word types */
#घोषणा USING_TWO_शब्दगण(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
अटल व्योम PUT_R_RET(SValue *sv, पूर्णांक t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
अटल पूर्णांक RC_RET(पूर्णांक t)
{
    वापस reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
अटल पूर्णांक RC_TYPE(पूर्णांक t)
{
    अगर (!is_float(t))
        वापस RC_INT;
#अगर_घोषित TCC_TARGET_X86_64
    अगर ((t & VT_BTYPE) == VT_LDOUBLE)
        वापस RC_ST0;
    अगर ((t & VT_BTYPE) == VT_QFLOAT)
        वापस RC_FRET;
#या_अगर defined TCC_TARGET_RISCV64
    अगर ((t & VT_BTYPE) == VT_LDOUBLE)
        वापस RC_INT;
#पूर्ण_अगर
    वापस RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
अटल पूर्णांक RC2_TYPE(पूर्णांक t, पूर्णांक rc)
{
    अगर (!USING_TWO_शब्दगण(t))
        वापस 0;
#अगर_घोषित RC_IRE2
    अगर (rc == RC_IRET)
        वापस RC_IRE2;
#पूर्ण_अगर
#अगर_घोषित RC_FRE2
    अगर (rc == RC_FRET)
        वापस RC_FRE2;
#पूर्ण_अगर
    अगर (rc & RC_FLOAT)
        वापस RC_FLOAT;
    वापस RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC पूर्णांक ieee_finite(द्विगुन d)
{
    पूर्णांक p[4];
    स_नकल(p, &d, माप(द्विगुन));
    वापस ((अचिन्हित)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC व्योम test_lvalue(व्योम)
{
    अगर (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC व्योम check_vstack(व्योम)
{
    अगर (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (पूर्णांक)(vtop - vstack + 1));
}

#अगर 0
/* dump 'b' vstack entries starting with 'a'  */
व्योम pv (स्थिर अक्षर *lbl, पूर्णांक a, पूर्णांक b)
{
    पूर्णांक i;
    क्रम (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        म_लिखो("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (पूर्णांक)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
अटल अंतरभूत व्योम psyms(स्थिर अक्षर *संदेश, Sym *s, Sym *last)
{
    म_लिखो("%-8s scope         v        c        r   type.t\n", संदेश);
    जबतक (s && s != last) {
        म_लिखो("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->पूर्व;
    }
}

अटल व्योम type_to_str(अक्षर *buf, पूर्णांक buf_आकार, CType *type, स्थिर अक्षर *varstr);

/* print type */
अटल व्योम ptype(स्थिर अक्षर *संदेश, CType *type, पूर्णांक v)
{
    अक्षर buf[500];
    type_to_str(buf, माप(buf), type,
        (v & ~SYM_FIELD) ? get_tok_str(v, शून्य) : शून्य);
    म_लिखो("%s : %s;\n", संदेश, buf);
}
#पूर्ण_अगर

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC व्योम tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    स_रखो(vtop, 0, माप *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    अगर (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_धकेलो(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#अगर_घोषित precedence_parser
    init_prec();
#पूर्ण_अगर
    cstr_new(&initstr);
}

ST_FUNC पूर्णांक tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = तथ्य_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_व्यंजक = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#अगर_घोषित TCC_TARGET_ARM
    arm_init(s1);
#पूर्ण_अगर
#अगर_घोषित INC_DEBUG
    म_लिखो("%s: **** new file\n", file->filename);
#पूर्ण_अगर
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_अंक | PARSE_FLAG_TOK_STR;
    अग्र();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#अगर TCC_EH_FRAME
    tcc_eh_frame_end(s1);
#पूर्ण_अगर
    tcc_debug_end(s1);
    tcc_tcov_end(s1);
    वापस 0;
}

ST_FUNC व्योम tccgen_finish(TCCState *s1)
{
    tcc_debug_end(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_निकालो(&global_ढेर, शून्य, 0);
    sym_निकालो(&local_ढेर, शून्य, 0);
    /* free preprocessor macros */
    free_defines(शून्य);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_तथ्य, &nb_stk_तथ्य);
    जबतक (cur_switch)
        end_switch();
    local_scope = 0;
    loop_scope = शून्य;
    all_cleanups = शून्य;
    pending_gotos = शून्य;
    nb_अस्थायी_local_vars = 0;
    global_label_ढेर = शून्य;
    local_label_ढेर = शून्य;
    cur_text_section = शून्य;
    sym_free_first = शून्य;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  अगर (!s || !s->c)
    वापस शून्य;
  वापस &((ElfSym *)symtab_section->तथ्य)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC व्योम update_storage(Sym *sym)
{
    ElfSym *esym;
    पूर्णांक sym_bind, old_sym_bind;

    esym = elfsym(sym);
    अगर (!esym)
        वापस;

    अगर (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    अगर (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    अन्यथा अगर (sym->a.weak)
        sym_bind = STB_WEAK;
    अन्यथा
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    अगर (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#अगर_घोषित TCC_TARGET_PE
    अगर (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    अगर (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#पूर्ण_अगर

#अगर 0
    म_लिखो("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, शून्य),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#पूर्ण_अगर
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC व्योम put_extern_sym2(Sym *sym, पूर्णांक sh_अंक,
                            addr_t मूल्य, अचिन्हित दीर्घ आकार,
                            पूर्णांक can_add_underscore)
{
    पूर्णांक sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    स्थिर अक्षर *name;
    अक्षर buf1[256];

    अगर (!sym->c) {
        name = get_tok_str(sym->v, शून्य);
        t = sym->type.t;
        अगर ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } अन्यथा अगर ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            अगर (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } अन्यथा अगर (t & VT_TLS) {
            sym_type = STT_TLS;
        } अन्यथा {
            sym_type = STT_OBJECT;
        }
        अगर (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        अन्यथा
            sym_bind = STB_GLOBAL;
        other = 0;

#अगर_घोषित TCC_TARGET_PE
        अगर (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            अगर (ref->a.nodecorate) {
                can_add_underscore = 0;
            }
            अगर (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                प्र_लिखो(buf1, "_%s@%d", name, ref->f.func_args * PTR_आकार);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#पूर्ण_अगर

        अगर (sym->asm_label) {
            name = get_tok_str(sym->asm_label, शून्य);
            can_add_underscore = 0;
        }

        अगर (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, माप(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, मूल्य, आकार, info, other, sh_अंक, name);

        अगर (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_अंक, sym_bind, sym_type);

    } अन्यथा {
        esym = elfsym(sym);
        esym->st_मूल्य = मूल्य;
        esym->st_आकार = आकार;
        esym->st_shndx = sh_अंक;
    }
    update_storage(sym);
}

ST_FUNC व्योम put_extern_sym(Sym *sym, Section *s, addr_t मूल्य, अचिन्हित दीर्घ आकार)
{
    अगर (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        वापस;
    put_extern_sym2(sym, s ? s->sh_अंक : SHN_UNDEF, मूल्य, आकार, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC व्योम greloca(Section *s, Sym *sym, अचिन्हित दीर्घ offset, पूर्णांक type,
                     addr_t addend)
{
    पूर्णांक c = 0;

    अगर (nocode_wanted && s == cur_text_section)
        वापस;

    अगर (sym) {
        अगर (0 == sym->c) {
            put_extern_sym(sym, शून्य, 0, 0);
            अगर (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                जबतक (s->पूर्व_tok)
                    s = s->पूर्व_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#अगर PTR_आकार == 4
ST_FUNC व्योम greloc(Section *s, Sym *sym, अचिन्हित दीर्घ offset, पूर्णांक type)
{
    greloca(s, sym, offset, type, 0);
}
#पूर्ण_अगर

/* ------------------------------------------------------------------------- */
/* symbol allocator */
अटल Sym *__sym_malloc(व्योम)
{
    Sym *sym_pool, *sym, *last_sym;
    पूर्णांक i;

    sym_pool = tcc_malloc(SYM_POOL_NB * माप(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);

    last_sym = sym_free_first;
    sym = sym_pool;
    क्रम(i = 0; i < SYM_POOL_NB; i++) {
        sym->अग्र = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    वापस last_sym;
}

अटल अंतरभूत Sym *sym_malloc(व्योम)
{
    Sym *sym;
#अगर_अघोषित SYM_DEBUG
    sym = sym_free_first;
    अगर (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->अग्र;
    वापस sym;
#अन्यथा
    sym = tcc_malloc(माप(Sym));
    वापस sym;
#पूर्ण_अगर
}

ST_INLN व्योम sym_free(Sym *sym)
{
#अगर_अघोषित SYM_DEBUG
    sym->अग्र = sym_free_first;
    sym_free_first = sym;
#अन्यथा
    tcc_free(sym);
#पूर्ण_अगर
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, पूर्णांक v, पूर्णांक t, पूर्णांक c)
{
    Sym *s;

    s = sym_malloc();
    स_रखो(s, 0, माप *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->पूर्व = *ps;
    *ps = s;
    वापस s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, पूर्णांक v)
{
    जबतक (s) {
        अगर (s->v == v)
            वापस s;
        s = s->पूर्व;
    }
    वापस शून्य;
}

/* structure lookup */
ST_INLN Sym *struct_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    अगर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        वापस शून्य;
    वापस table_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    अगर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        वापस शून्य;
    वापस table_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
अटल अंतरभूत व्योम sym_link(Sym *s, पूर्णांक yes)
{
    TokenSym *ts = table_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    अगर (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    अन्यथा
        ps = &ts->sym_identifier;
    अगर (yes) {
        s->पूर्व_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } अन्यथा {
        *ps = s->पूर्व_tok;
    }
}

अटल अंतरभूत पूर्णांक sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    वापस IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_धकेलो(पूर्णांक v, CType *type, पूर्णांक r, पूर्णांक c)
{
    Sym *s, **ps;
    अगर (local_ढेर)
        ps = &local_ढेर;
    अन्यथा
        ps = &global_ढेर;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    अगर ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        अगर (s->पूर्व_tok && sym_scope_ex(s->पूर्व_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, शून्य));
    }
    वापस s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_धकेलो(पूर्णांक v, पूर्णांक t, पूर्णांक c)
{
    Sym *s, **ps;
    s = sym_push2(&global_ढेर, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    अगर (v < SYM_FIRST_ANOM) {
        ps = &table_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        जबतक (*ps != शून्य && (*ps)->sym_scope)
            ps = &(*ps)->पूर्व_tok;
        s->पूर्व_tok = *ps;
        *ps = s;
    }
    वापस s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC व्योम sym_निकालो(Sym **ptop, Sym *b, पूर्णांक keep)
{
    Sym *s, *ss;
    पूर्णांक v;

    s = *ptop;
    जबतक(s != b) {
        ss = s->पूर्व;
        v = s->v;
        /* remove symbol in token array */
        अगर ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	अगर (!keep)
	    sym_free(s);
        s = ss;
    }
    अगर (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    अगर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        वापस शून्य;
    वापस table_ident[v]->sym_label;
}

ST_FUNC Sym *label_धकेलो(Sym **ptop, पूर्णांक v, पूर्णांक flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &table_ident[v - TOK_IDENT]->sym_label;
    अगर (ptop == &global_label_ढेर) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        जबतक (*ps != शून्य)
            ps = &(*ps)->पूर्व_tok;
    }
    s->पूर्व_tok = *ps;
    *ps = s;
    वापस s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC व्योम label_निकालो(Sym **ptop, Sym *slast, पूर्णांक keep)
{
    Sym *s, *s1;
    क्रम(s = *ptop; s != slast; s = s1) {
        s1 = s->पूर्व;
        अगर (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, शून्य));
        } अन्यथा अगर (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, शून्य));
        } अन्यथा {
            अगर (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        अगर (s->r != LABEL_GONE)
            table_ident[s->v - TOK_IDENT]->sym_label = s->पूर्व_tok;
        अगर (!keep)
            sym_free(s);
        अन्यथा
            s->r = LABEL_GONE;
    }
    अगर (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
अटल व्योम vcheck_cmp(व्योम)
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

    अगर (vtop->r == VT_CMP && 0 == (nocode_wanted & ~CODE_OFF_BIT))
        gv(RC_INT);
}

अटल व्योम vsetc(CType *type, पूर्णांक r, CValue *vc)
{
    अगर (vtop >= vstack + (VSTACK_आकार - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = शून्य;
}

ST_FUNC व्योम vswap(व्योम)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC व्योम vpop(व्योम)
{
    पूर्णांक v;
    v = vtop->r & VT_VALMASK;
#अगर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    अगर (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } अन्यथा
#पूर्ण_अगर
    अगर (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
अटल व्योम vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
अटल व्योम vpush64(पूर्णांक ty, अचिन्हित दीर्घ दीर्घ v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = शून्य;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC व्योम vpushi(पूर्णांक v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
अटल व्योम vpushs(addr_t v)
{
    vpush64(VT_आकार_T, v);
}

/* push long long constant */
अटल अंतरभूत व्योम vpushll(दीर्घ दीर्घ v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC व्योम vset(CType *type, पूर्णांक r, पूर्णांक v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

अटल व्योम vseti(पूर्णांक r, पूर्णांक v)
{
    CType type;
    type.t = VT_INT;
    type.ref = शून्य;
    vset(&type, r, v);
}

ST_FUNC व्योम vpushv(SValue *v)
{
    अगर (vtop >= vstack + (VSTACK_आकार - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

अटल व्योम vdup(व्योम)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC व्योम vrotb(पूर्णांक n)
{
    SValue tmp;
    अगर (--n < 1)
        वापस;
    vcheck_cmp();
    tmp = vtop[-n];
    स_हटाओ(vtop - n, vtop - n + 1, माप *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC व्योम vrott(पूर्णांक n)
{
    SValue tmp;
    अगर (--n < 1)
        वापस;
    vcheck_cmp();
    tmp = vtop[0];
    स_हटाओ(vtop - n + 1, vtop - n, माप *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC व्योम vrev(पूर्णांक n)
{
    पूर्णांक i;
    SValue tmp;
    vcheck_cmp();
    क्रम (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC व्योम vset_VT_CMP(पूर्णांक op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
अटल व्योम vset_VT_JMP(व्योम)
{
    पूर्णांक op = vtop->cmp_op;

    अगर (vtop->jtrue || vtop->jfalse) {
        पूर्णांक origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        पूर्णांक inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } अन्यथा {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        अगर (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
अटल व्योम gvtst_set(पूर्णांक inv, पूर्णांक t)
{
    पूर्णांक *p;

    अगर (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        अगर (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
अटल पूर्णांक gvtst(पूर्णांक inv, पूर्णांक t)
{
    पूर्णांक op, x, u;

    gvtst_set(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    अगर (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    अगर (op > 1)
        t = gjmp_cond(op ^ inv, t);
    अन्यथा अगर (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    वापस t;
}

/* generate a zero or nozero test */
अटल व्योम gen_test_zero(पूर्णांक op)
{
    अगर (vtop->r == VT_CMP) {
        पूर्णांक j;
        अगर (op == TOK_EQ) {
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
ST_FUNC व्योम vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, अचिन्हित दीर्घ offset, अचिन्हित दीर्घ आकार)
{
    पूर्णांक v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_धकेलो(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, offset, आकार);
    वापस sym;
}

/* push a reference to a section offset by adding a dummy symbol */
अटल व्योम vpush_ref(CType *type, Section *sec, अचिन्हित दीर्घ offset, अचिन्हित दीर्घ आकार)
{
    vpushsym(type, get_sym_ref(type, sec, offset, आकार));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(पूर्णांक v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    अगर (!s) {
        /* push forward reference */
        s = global_identifier_धकेलो(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } अन्यथा अगर (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    वापस s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(पूर्णांक v)
{
    CType ct = { VT_ASM_FUNC, शून्य };
    वापस external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC व्योम vpush_helper_func(पूर्णांक v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
अटल व्योम merge_symattr(काष्ठा SymAttr *sa, काष्ठा SymAttr *sa1)
{
    अगर (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    अगर (sa1->visibility != STV_DEFAULT) {
	पूर्णांक vis = sa->visibility;
	अगर (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
अटल व्योम merge_funcattr(काष्ठा FuncAttr *fa, काष्ठा FuncAttr *fa1)
{
    अगर (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    अगर (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    अगर (fa1->func_args && !fa->func_args)
      fa->func_args = fa1->func_args;
    अगर (fa1->func_noreturn)
      fa->func_noreturn = 1;
    अगर (fa1->func_ctor)
      fa->func_ctor = 1;
    अगर (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
अटल व्योम merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    अगर (ad1->section)
      ad->section = ad1->section;
    अगर (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    अगर (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    अगर (ad1->attr_mode)
      ad->attr_mode = ad1->attr_mode;
}

/* Merge some type attributes.  */
अटल व्योम patch_type(Sym *sym, CType *type)
{
    अगर (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        अगर (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, शून्य));
        sym->type.t &= ~VT_EXTERN;
    }

    अगर (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        अगर ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    अगर (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, शून्य));

    } अन्यथा अगर ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        पूर्णांक static_proto = sym->type.t & VT_STATIC;
        पूर्णांक ft1 = sym->type.ref->f.func_type;
        पूर्णांक ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        अगर ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, शून्य));

        /* set 'inline' if both agree or if one has static */
        अगर ((type->t | sym->type.t) & VT_INLINE) {
            अगर (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        अगर (0 == (type->t & VT_EXTERN)) {
            काष्ठा FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            अगर (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } अन्यथा {
            sym->type.t &= ~VT_INLINE | static_proto;
            अगर (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } अन्यथा {
        अगर ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        अगर ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, शून्य));
    }
}

/* Merge some storage attributes.  */
अटल व्योम patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    अगर (type)
        patch_type(sym, type);

#अगर_घोषित TCC_TARGET_PE
    अगर (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, शून्य));
#पूर्ण_अगर
    merge_symattr(&sym->a, &ad->a);
    अगर (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
अटल Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->पूर्व = *ps, *ps = s;
    अगर ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    वापस s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
अटल व्योम move_ref_to_global(Sym *s)
{
    Sym *l, **lp;
    पूर्णांक n, bt;

    bt = s->type.t & VT_BTYPE;
    अगर (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        वापस;

    क्रम (s = s->type.ref, n = 0; s; s = s->अग्र) {
        क्रम (lp = &local_ढेर; !!(l = *lp); lp = &l->पूर्व) {
            अगर (l == s) {
                *lp = s->पूर्व;
                s->पूर्व = global_ढेर, global_ढेर = s;
                अगर (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_to_global(s);
                } अन्यथा {
                    अगर ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_FIELD;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_FIELD;
                    }
                }
                अगर (bt != VT_PTR)
                    n = 1;
                अवरोध;
            }
        }
        अगर (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            अवरोध;
    }
}

/* define a new external reference to a symbol 'v' */
अटल Sym *external_sym(पूर्णांक v, CType *type, पूर्णांक r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    जबतक (s && s->sym_scope)
        s = s->पूर्व_tok;

    अगर (!s) {
        /* push forward reference */
        s = global_identifier_धकेलो(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } अन्यथा {
        patch_storage(s, ad, type);
    }
    अगर (local_ढेर) {
        /* make sure that type->ref is on global stack */
        move_ref_to_global(s);
        /* put into local scope */
        sym_copy(s, &local_ढेर);
    }
    वापस s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC व्योम save_regs(पूर्णांक n)
{
    SValue *p, *p1;
    क्रम(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC व्योम save_reg(पूर्णांक r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC व्योम save_reg_upstack(पूर्णांक r, पूर्णांक n)
{
    पूर्णांक l, आकार, align, bt, r2;
    SValue *p, *p1, sv;

    अगर ((r &= VT_VALMASK) >= VT_CONST)
        वापस;
    अगर (nocode_wanted)
        वापस;
    l = r2 = 0;
    क्रम(p = vstack, p1 = vtop - n; p <= p1; p++) {
        अगर ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            अगर (!l) {
                bt = p->type.t & VT_BTYPE;
                अगर (bt == VT_VOID)
                    जारी;
                अगर ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                आकार = type_आकार(&sv.type, &align);
                l = get_अस्थायी_local_var(आकार, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = शून्य;
                store(p->r & VT_VALMASK, &sv);
#अगर defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                अगर (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#पूर्ण_अगर
                /* special long long case */
                अगर (p->r2 < VT_CONST && USING_TWO_शब्दगण(bt)) {
                    sv.c.i += PTR_आकार;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            अगर (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } अन्यथा {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = शून्य;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#अगर_घोषित TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC पूर्णांक get_reg_ex(पूर्णांक rc, पूर्णांक rc2)
{
    पूर्णांक r;
    SValue *p;
    
    क्रम(r=0;r<NB_REGS;r++) {
        अगर (reg_classes[r] & rc2) {
            पूर्णांक n;
            n=0;
            क्रम(p = vstack; p <= vtop; p++) {
                अगर ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            अगर (n <= 1)
                वापस r;
        }
    }
    वापस get_reg(rc);
}
#पूर्ण_अगर

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC पूर्णांक get_reg(पूर्णांक rc)
{
    पूर्णांक r;
    SValue *p;

    /* find a free register */
    क्रम(r=0;r<NB_REGS;r++) {
        अगर (reg_classes[r] & rc) {
            अगर (nocode_wanted)
                वापस r;
            क्रम(p=vstack;p<=vtop;p++) {
                अगर ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    जाओ notfound;
            }
            वापस r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    क्रम(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        अगर (r < VT_CONST && (reg_classes[r] & rc))
            जाओ save_found;
        r = p->r & VT_VALMASK;
        अगर (r < VT_CONST && (reg_classes[r] & rc)) {
        save_found:
            save_reg(r);
            वापस r;
        }
    }
    /* Should never comes here */
    वापस -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
अटल पूर्णांक get_अस्थायी_local_var(पूर्णांक आकार,पूर्णांक align, पूर्णांक *r2)
{
    पूर्णांक i;
    काष्ठा अस्थायी_local_variable *अस्थायी_var;
    SValue *p;
    पूर्णांक r;
    अचिन्हित used = 0;

    /* mark locations that are still in use */
    क्रम (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	अगर (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    अगर (r >= 0 && r < MAX_अस्थायी_LOCAL_VARIABLE_संख्या)
	        used |= 1<<r;
	}
    }
    क्रम (i=0;i<nb_अस्थायी_local_vars;i++) {
	अस्थायी_var=&arr_अस्थायी_local_vars[i];
	अगर(!(used & 1<<i)
	 && अस्थायी_var->आकार>=आकार
	 && अस्थायी_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    वापस अस्थायी_var->location;
	}
    }
    loc = (loc - आकार) & -align;
    अगर (nb_अस्थायी_local_vars<MAX_अस्थायी_LOCAL_VARIABLE_संख्या) {
	अस्थायी_var=&arr_अस्थायी_local_vars[i];
	अस्थायी_var->location=loc;
	अस्थायी_var->आकार=आकार;
	अस्थायी_var->align=align;
	nb_अस्थायी_local_vars++;
	जाओ ret_tmp;
    }
    *r2 = VT_CONST;
    वापस loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
अटल व्योम move_reg(पूर्णांक r, पूर्णांक s, पूर्णांक t)
{
    SValue sv;

    अगर (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = शून्य;
        sv.r = s;
        sv.c.i = 0;
        load(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC व्योम gaddrof(व्योम)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    अगर ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#अगर_घोषित CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
अटल व्योम gen_bounded_ptr_add(व्योम)
{
    पूर्णांक save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    अगर (save) {
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
    अगर (nocode_wanted)
        वापस;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->तथ्य_offset - माप(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
अटल व्योम gen_bounded_ptr_deref(व्योम)
{
    addr_t func;
    पूर्णांक आकार, align;
    ElfW_Rel *rel;
    Sym *sym;

    अगर (nocode_wanted)
        वापस;

    आकार = type_आकार(&vtop->type, &align);
    चयन(आकार) {
    हाल  1: func = TOK___bound_ptr_indir1; अवरोध;
    हाल  2: func = TOK___bound_ptr_indir2; अवरोध;
    हाल  4: func = TOK___bound_ptr_indir4; अवरोध;
    हाल  8: func = TOK___bound_ptr_indir8; अवरोध;
    हाल 12: func = TOK___bound_ptr_indir12; अवरोध;
    हाल 16: func = TOK___bound_ptr_indir16; अवरोध;
    शेष:
        /* may happen with struct member access */
        वापस;
    }
    sym = external_helper_sym(func);
    अगर (!sym->c)
        put_extern_sym(sym, शून्य, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->तथ्य + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
अटल व्योम gbound(व्योम)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    अगर (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        अगर (!(vtop->r & VT_BOUNDED)) {
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
ST_FUNC व्योम gbound_args(पूर्णांक nb_args)
{
    पूर्णांक i, v;
    SValue *sv;

    क्रम (i = 1; i <= nb_args; ++i)
        अगर (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_args;
    अगर (sv->r & VT_SYM) {
        v = sv->sym->v;
        अगर (v == TOK_setjmp
          || v == TOK__setjmp
#अगर_अघोषित TCC_TARGET_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#पूर्ण_अगर
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_add_epilog = 1;
        }
        अगर (v == TOK_alloca)
            func_bound_add_epilog = 1;
#अगर TARGETOS_NetBSD
        अगर (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#पूर्ण_अगर
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
अटल व्योम add_local_bounds(Sym *s, Sym *e)
{
    क्रम (; s != e; s = s->पूर्व) {
        अगर (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          जारी;
        /* Add arrays/structs/unions because we always take address */
        अगर ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            पूर्णांक align, आकार = type_आकार(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_add(lbounds_section,
                                                 2 * माप(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = आकार;
        }
    }
}
#पूर्ण_अगर

/* add debug info for locals or function parameters, optionally
   register bounds */
अटल व्योम tcc_debug_end_scope(Sym *b, पूर्णांक bounds)
{
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (tcc_state->do_bounds_check && bounds)
        add_local_bounds(local_ढेर, b);
#पूर्ण_अगर
    tcc_add_debug_info (tcc_state, local_ढेर, b);
}

/* increment an lvalue pointer */
अटल व्योम incr_offset(पूर्णांक offset)
{
    पूर्णांक t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(offset);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

अटल व्योम incr_bf_adr(पूर्णांक o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_offset(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
अटल व्योम load_packed_bf(CType *type, पूर्णांक bit_pos, पूर्णांक bit_आकार)
{
    पूर्णांक n, o, bits;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    करो {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        अगर (n > bit_आकार)
            n = bit_आकार;
        अगर (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        अगर (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        अगर (bits)
            vpushi(bits), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        bits += n, bit_आकार -= n, o = 1;
    } जबतक (bit_आकार);
    vswap(), vpop();
    अगर (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - bits;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
अटल व्योम store_packed_bf(पूर्णांक bit_pos, पूर्णांक bit_आकार)
{
    पूर्णांक bits, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    bits = 0, o = bit_pos >> 3, bit_pos &= 7;
    करो {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        अगर (bits)
            vpushi(bits), gen_op(TOK_SHR);
        अगर (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        अगर (n > bit_आकार)
            n = bit_आकार;
        अगर (n < 8) {
            m = ((1 << n) - 1) << bit_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        bits += n, bit_आकार -= n, bit_pos = 0, o = 1;
    } जबतक (bit_आकार);
    vpop(), vpop();
}

अटल पूर्णांक adjust_bf(SValue *sv, पूर्णांक bit_pos, पूर्णांक bit_आकार)
{
    पूर्णांक t;
    अगर (0 == sv->type.ref)
        वापस 0;
    t = sv->type.ref->auxtype;
    अगर (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    वापस t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC पूर्णांक gv(पूर्णांक rc)
{
    पूर्णांक r, r2, r_ok, r2_ok, rc2, bt;
    पूर्णांक bit_pos, bit_आकार, आकार, align;

    /* NOTE: get_reg can modify vstack[] */
    अगर (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_आकार = BIT_आकार(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_MASK;

        type.ref = शून्य;
        type.t = vtop->type.t & VT_UNSIGNED;
        अगर ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_आकार);

        अगर ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        अन्यथा
            type.t |= VT_INT;

        अगर (r == VT_STRUCT) {
            load_packed_bf(&type, bit_pos, bit_आकार);
        } अन्यथा {
            पूर्णांक bits = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(bits - (bit_pos + bit_आकार));
            gen_op(TOK_SHL);
            vpushi(bits - bit_आकार);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } अन्यथा {
        अगर (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            अचिन्हित दीर्घ offset;
            आकार = type_आकार(&vtop->type, &align);
            अगर (NODATA_WANTED)
                आकार = 0, align = 1;
            offset = section_add(p.sec, आकार, align);
            vpush_ref(&vtop->type, p.sec, offset, आकार);
	    vswap();
	    init_putv(&p, &vtop->type, offset);
	    vtop->r |= VT_LVAL;
        }
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (vtop->r & VT_MUSTBOUND) 
            gbound();
#पूर्ण_अगर

        bt = vtop->type.t & VT_BTYPE;
        अगर (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            वापस vtop->r;

#अगर_घोषित TCC_TARGET_RISCV64
        /* XXX mega hack */
        अगर (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#पूर्ण_अगर
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        अगर (!r_ok || !r2_ok) {

            अगर (!r_ok) {
                अगर (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                अन्यथा
                    r = get_reg(rc);
            }

            अगर (rc2) {
                पूर्णांक load_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                पूर्णांक original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    अचिन्हित दीर्घ दीर्घ ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    load(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } अन्यथा अगर (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = load_type;
                    load(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_offset(PTR_आकार);
                } अन्यथा {
                    /* move registers */
                    अगर (!r_ok)
                        load(r, vtop);
                    अगर (r2_ok && vtop->r2 < VT_CONST)
                        जाओ done;
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
                अगर (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                load(r, vtop);
            }
        }
        vtop->r = r;
#अगर_घोषित TCC_TARGET_C67
        /* uses register pairs for doubles */
        अगर (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#पूर्ण_अगर
    }
    वापस r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC व्योम gv2(पूर्णांक rc1, पूर्णांक rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    अगर (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        अगर ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
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
        अगर ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#अगर PTR_आकार == 4
/* expand 64bit on stack in two ints */
ST_FUNC व्योम lexpand(व्योम)
{
    पूर्णांक u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    अगर (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } अन्यथा अगर (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
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
#पूर्ण_अगर

#अगर PTR_आकार == 4
/* build a long long from two ints */
अटल व्योम lbuild(पूर्णांक t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#पूर्ण_अगर

/* convert stack entry to register and duplicate its value in another
   register */
अटल व्योम gv_dup(व्योम)
{
    पूर्णांक t, rc, r;

    t = vtop->type.t;
#अगर PTR_आकार == 4
    अगर ((t & VT_BTYPE) == VT_LLONG) {
        अगर (t & VT_BITFIELD) {
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
        वापस;
    }
#पूर्ण_अगर
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    load(r, vtop);
    vtop->r = r;
}

#अगर PTR_आकार == 4
/* generate CPU independent (unsigned) long long operations */
अटल व्योम gen_opl(पूर्णांक op)
{
    पूर्णांक t, a, b, op1, c, i;
    पूर्णांक func;
    अचिन्हित लघु reg_iret = REG_IRET;
    अचिन्हित लघु reg_lret = REG_IRE2;
    SValue tmp;

    चयन(op) {
    हाल '/':
    हाल TOK_PDIV:
        func = TOK___divdi3;
        जाओ gen_func;
    हाल TOK_UDIV:
        func = TOK___udivdi3;
        जाओ gen_func;
    हाल '%':
        func = TOK___moddi3;
        जाओ gen_mod_func;
    हाल TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#अगर_घोषित TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#पूर्ण_अगर
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        अवरोध;
    हाल '^':
    हाल '&':
    हाल '|':
    हाल '*':
    हाल '+':
    हाल '-':
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
        अगर (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            क्रम(i=0;i<4;i++)
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
        } अन्यथा अगर (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            अगर (op == '+')
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
        अवरोध;
    हाल TOK_SAR:
    हाल TOK_SHR:
    हाल TOK_SHL:
        अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
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
            अगर (op != TOK_SHL)
                vswap();
            अगर (c >= 32) {
                /* stack: L H */
                vpop();
                अगर (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                अगर (op != TOK_SAR) {
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
                अगर (op == TOK_SHL)
                    gen_op(TOK_SHR);
                अन्यथा
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                अगर (op == TOK_SHL)
                    gen_op(TOK_SHL);
                अन्यथा
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            अगर (op != TOK_SHL)
                vswap();
            lbuild(t);
        } अन्यथा {
            /* XXX: should provide a faster fallback on x86 ? */
            चयन(op) {
            हाल TOK_SAR:
                func = TOK___ashrdi3;
                जाओ gen_func;
            हाल TOK_SHR:
                func = TOK___lshrdi3;
                जाओ gen_func;
            हाल TOK_SHL:
                func = TOK___ashldi3;
                जाओ gen_func;
            }
        }
        अवरोध;
    शेष:
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
        अगर (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        अगर (op1 == TOK_LT)
            op1 = TOK_LE;
        अन्यथा अगर (op1 == TOK_GT)
            op1 = TOK_GE;
        अन्यथा अगर (op1 == TOK_ULT)
            op1 = TOK_ULE;
        अन्यथा अगर (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        अगर (op == TOK_NE) {
            b = gvtst(0, 0);
        } अन्यथा {
            a = gvtst(1, 0);
            अगर (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        अगर (op1 == TOK_LT)
            op1 = TOK_ULT;
        अन्यथा अगर (op1 == TOK_LE)
            op1 = TOK_ULE;
        अन्यथा अगर (op1 == TOK_GT)
            op1 = TOK_UGT;
        अन्यथा अगर (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#अगर 0//def TCC_TARGET_I386
        अगर (op == TOK_NE) { gsym(b); अवरोध; }
        अगर (op == TOK_EQ) { gsym(a); अवरोध; }
#पूर्ण_अगर
        gvtst_set(1, a);
        gvtst_set(0, b);
        अवरोध;
    }
}
#पूर्ण_अगर

/* normalize values */
अटल uint64_t value64(uint64_t l1, पूर्णांक t)
{
    अगर ((t & VT_BTYPE) == VT_LLONG
        || (PTR_आकार == 8 && (t & VT_BTYPE) == VT_PTR))
        वापस l1;
    अन्यथा अगर (t & VT_UNSIGNED)
        वापस (uint32_t)l1;
    अन्यथा
        वापस (uint32_t)l1 | -(l1 & 0x80000000);
}

अटल uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    वापस (a ^ b) >> 63 ? -x : x;
}

अटल पूर्णांक gen_opic_lt(uint64_t a, uint64_t b)
{
    वापस (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
अटल व्योम gen_opic(पूर्णांक op)
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

    अगर (c1 && c2) {
        चयन(op) {
        हाल '+': l1 += l2; अवरोध;
        हाल '-': l1 -= l2; अवरोध;
        हाल '&': l1 &= l2; अवरोध;
        हाल '^': l1 ^= l2; अवरोध;
        हाल '|': l1 |= l2; अवरोध;
        हाल '*': l1 *= l2; अवरोध;

        हाल TOK_PDIV:
        हाल '/':
        हाल '%':
        हाल TOK_UDIV:
        हाल TOK_UMOD:
            /* if division by zero, generate explicit division */
            अगर (l2 == 0) {
                अगर (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                जाओ general_case;
            }
            चयन(op) {
            शेष: l1 = gen_opic_sdiv(l1, l2); अवरोध;
            हाल '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); अवरोध;
            हाल TOK_UDIV: l1 = l1 / l2; अवरोध;
            हाल TOK_UMOD: l1 = l1 % l2; अवरोध;
            }
            अवरोध;
        हाल TOK_SHL: l1 <<= (l2 & shm); अवरोध;
        हाल TOK_SHR: l1 >>= (l2 & shm); अवरोध;
        हाल TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            अवरोध;
            /* tests */
        हाल TOK_ULT: l1 = l1 < l2; अवरोध;
        हाल TOK_UGE: l1 = l1 >= l2; अवरोध;
        हाल TOK_EQ: l1 = l1 == l2; अवरोध;
        हाल TOK_NE: l1 = l1 != l2; अवरोध;
        हाल TOK_ULE: l1 = l1 <= l2; अवरोध;
        हाल TOK_UGT: l1 = l1 > l2; अवरोध;
        हाल TOK_LT: l1 = gen_opic_lt(l1, l2); अवरोध;
        हाल TOK_GE: l1 = !gen_opic_lt(l1, l2); अवरोध;
        हाल TOK_LE: l1 = !gen_opic_lt(l2, l1); अवरोध;
        हाल TOK_GT: l1 = gen_opic_lt(l2, l1); अवरोध;
            /* logical */
        हाल TOK_LAND: l1 = l1 && l2; अवरोध;
        हाल TOK_LOR: l1 = l1 || l2; अवरोध;
        शेष:
            जाओ general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } अन्यथा {
        /* if commutative ops, put c2 as constant */
        अगर (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        अगर (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } अन्यथा अगर (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            अगर (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } अन्यथा अगर (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } अन्यथा अगर (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            अगर (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                पूर्णांक n = -1;
                अगर (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    जाओ general_case;
                }
                जबतक (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                अगर (op == '*')
                    op = TOK_SHL;
                अन्यथा अगर (op == TOK_PDIV)
                    op = TOK_SAR;
                अन्यथा
                    op = TOK_SHR;
            }
            जाओ general_case;
        } अन्यथा अगर (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            अगर (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    अगर ((पूर्णांक)l2 != l2)
	        जाओ general_case;
            vtop--;
            vtop->c.i = l2;
        } अन्यथा {
        general_case:
                /* call low level op generator */
                अगर (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_आकार == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                अन्यथा
                    gen_opi(op);
        }
        अगर (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#अगर defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#या_अगर defined TCC_TARGET_ARM
व्योम gen_negf(पूर्णांक op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#अन्यथा
/* XXX: implement in gen_opf() for other backends too */
व्योम gen_negf(पूर्णांक op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    पूर्णांक align, आकार, bt;
    आकार = type_आकार(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#अगर defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    अगर (bt == VT_LDOUBLE)
        आकार = 10;
#पूर्ण_अगर
    अगर (nocode_wanted) /* save_reg() wont work */
        जाओ gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(आकार - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#पूर्ण_अगर

/* generate a floating point operation with constant propagation */
अटल व्योम gen_opif(पूर्णांक op)
{
    पूर्णांक c1, c2, i, bt;
    SValue *v1, *v2;
#अगर defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    अस्थिर
#पूर्ण_अगर
    दीर्घ द्विगुन f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    अगर (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    अगर (c1 && c2) {
        अगर (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } अन्यथा अगर (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } अन्यथा {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        अगर (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            जाओ general_case;
        चयन(op) {
        हाल '+': f1 += f2; अवरोध;
        हाल '-': f1 -= f2; अवरोध;
        हाल '*': f1 *= f2; अवरोध;
        हाल '/': 
            अगर (f2 == 0.0) {
                जोड़ { भग्न f; अचिन्हित u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                अगर (!CONST_WANTED)
                    जाओ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                अगर (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                अन्यथा
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                अवरोध;
            }
            f1 /= f2;
            अवरोध;
        हाल TOK_NEG:
            f1 = -f1;
            जाओ unary_परिणाम;
        हाल TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            वापस;
        हाल TOK_NE:
            i = f1 != f2;
	    जाओ make_int;
        हाल TOK_LT:
            i = f1 < f2;
	    जाओ make_int;
        हाल TOK_GE:
            i = f1 >= f2;
	    जाओ make_int;
        हाल TOK_LE:
            i = f1 <= f2;
	    जाओ make_int;
        हाल TOK_GT:
            i = f1 > f2;
	    जाओ make_int;
        शेष:
            जाओ general_case;
        }
        vtop--;
    unary_परिणाम:
        /* XXX: overflow test ? */
        अगर (bt == VT_FLOAT) {
            v1->c.f = f1;
        } अन्यथा अगर (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } अन्यथा {
            v1->c.ld = f1;
        }
    } अन्यथा {
    general_case:
        अगर (op == TOK_NEG) {
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
अटल व्योम type_to_str(अक्षर *buf, पूर्णांक buf_आकार,
                 CType *type, स्थिर अक्षर *varstr)
{
    पूर्णांक bt, v, t;
    Sym *s, *sa;
    अक्षर buf1[256];
    स्थिर अक्षर *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    अगर (t & VT_EXTERN)
        pstrcat(buf, buf_आकार, "extern ");
    अगर (t & VT_STATIC)
        pstrcat(buf, buf_आकार, "static ");
    अगर (t & VT_TYPEDEF)
        pstrcat(buf, buf_आकार, "typedef ");
    अगर (t & VT_INLINE)
        pstrcat(buf, buf_आकार, "inline ");
    अगर (bt != VT_PTR) {
        अगर (t & VT_RESTRICT)
            pstrcat(buf, buf_आकार, "restrict ");
        अगर (t & VT_VOLATILE)
            pstrcat(buf, buf_आकार, "volatile ");
        अगर (t & VT_CONSTANT)
            pstrcat(buf, buf_आकार, "const ");
    }
    अगर (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_आकार, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_आकार -= म_माप(buf);
    buf += म_माप(buf);

    चयन(bt) {
    हाल VT_VOID:
        tstr = "void";
        जाओ add_tstr;
    हाल VT_BOOL:
        tstr = "_Bool";
        जाओ add_tstr;
    हाल VT_BYTE:
        tstr = "char";
        जाओ add_tstr;
    हाल VT_SHORT:
        tstr = "short";
        जाओ add_tstr;
    हाल VT_INT:
        tstr = "int";
        जाओ maybe_long;
    हाल VT_LLONG:
        tstr = "long long";
    maybe_long:
        अगर (t & VT_LONG)
            tstr = "long";
        अगर (!IS_ENUM(t))
            जाओ add_tstr;
        tstr = "enum ";
        जाओ tstruct;
    हाल VT_FLOAT:
        tstr = "float";
        जाओ add_tstr;
    हाल VT_DOUBLE:
        tstr = "double";
        अगर (!(t & VT_LONG))
            जाओ add_tstr;
    हाल VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_आकार, tstr);
        अवरोध;
    हाल VT_STRUCT:
        tstr = "struct ";
        अगर (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_आकार, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        अगर (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_आकार, "<anonymous>");
        अन्यथा
            pstrcat(buf, buf_आकार, get_tok_str(v, शून्य));
        अवरोध;
    हाल VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        अगर (varstr && '*' == *varstr) {
            pstrcat(buf1, माप(buf1), "(");
            pstrcat(buf1, माप(buf1), varstr);
            pstrcat(buf1, माप(buf1), ")");
        }
        pstrcat(buf1, माप(buf1), "(");
        sa = s->अग्र;
        जबतक (sa != शून्य) {
            अक्षर buf2[256];
            type_to_str(buf2, माप(buf2), &sa->type, शून्य);
            pstrcat(buf1, माप(buf1), buf2);
            sa = sa->अग्र;
            अगर (sa)
                pstrcat(buf1, माप(buf1), ", ");
        }
        अगर (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, माप(buf1), ", ...");
        pstrcat(buf1, माप(buf1), ")");
        type_to_str(buf, buf_आकार, &s->type, buf1);
        जाओ no_var;
    हाल VT_PTR:
        s = type->ref;
        अगर (t & (VT_ARRAY|VT_VLA)) {
            अगर (varstr && '*' == *varstr)
                snprintf(buf1, माप(buf1), "(%s)[%d]", varstr, s->c);
            अन्यथा
                snprintf(buf1, माप(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_आकार, &s->type, buf1);
            जाओ no_var;
        }
        pstrcpy(buf1, माप(buf1), "*");
        अगर (t & VT_RESTRICT)
            pstrcat(buf1, माप(buf1), "restrict ");
        अगर (t & VT_CONSTANT)
            pstrcat(buf1, माप(buf1), "const ");
        अगर (t & VT_VOLATILE)
            pstrcat(buf1, माप(buf1), "volatile ");
        अगर (varstr)
            pstrcat(buf1, माप(buf1), varstr);
        type_to_str(buf, buf_आकार, &s->type, buf1);
        जाओ no_var;
    }
    अगर (varstr) {
        pstrcat(buf, buf_आकार, " ");
        pstrcat(buf, buf_आकार, varstr);
    }
 no_var: ;
}

अटल व्योम type_incompatibility_error(CType* st, CType* dt, स्थिर अक्षर* fmt)
{
    अक्षर buf1[256], buf2[256];
    type_to_str(buf1, माप(buf1), st, शून्य);
    type_to_str(buf2, माप(buf2), dt, शून्य);
    tcc_error(fmt, buf1, buf2);
}

अटल व्योम type_incompatibility_warning(CType* st, CType* dt, स्थिर अक्षर* fmt)
{
    अक्षर buf1[256], buf2[256];
    type_to_str(buf1, माप(buf1), st, शून्य);
    type_to_str(buf2, माप(buf2), dt, शून्य);
    tcc_warning(fmt, buf1, buf2);
}

अटल पूर्णांक pointed_आकार(CType *type)
{
    पूर्णांक align;
    वापस type_आकार(pointed_type(type), &align);
}

अटल अंतरभूत पूर्णांक is_null_pointer(SValue *p)
{
    अगर ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        वापस 0;
    वापस ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_आकार == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
अटल पूर्णांक is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    अगर (s1->f.func_call != s2->f.func_call)
        वापस 0;
    अगर (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        वापस 0;
    क्रम (;;) {
        अगर (!is_compatible_unqualified_types(&s1->type, &s2->type))
            वापस 0;
        अगर (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            वापस 1;
        s1 = s1->अग्र;
        s2 = s2->अग्र;
        अगर (!s1)
            वापस !s2;
        अगर (!s2)
            वापस 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
अटल पूर्णांक compare_types(CType *type1, CType *type2, पूर्णांक unqualified)
{
    पूर्णांक bt1, t1, t2;

    अगर (IS_ENUM(type1->t)) {
        अगर (IS_ENUM(type2->t))
            वापस type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } अन्यथा अगर (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    अगर (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    अगर ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    अगर (t1 != t2)
        वापस 0;

    अगर ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            वापस 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    अगर (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        अगर (unqualified && (t1 & VT_ARRAY))
            वापस compare_types(type1, type2, 1);
        वापस is_compatible_types(type1, type2);
    } अन्यथा अगर (bt1 == VT_STRUCT) {
        वापस (type1->ref == type2->ref);
    } अन्यथा अगर (bt1 == VT_FUNC) {
        वापस is_compatible_func(type1, type2);
    } अन्यथा {
        वापस 1;
    }
}

#घोषणा CMP_OP 'C'
#घोषणा SHIFT_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
अटल पूर्णांक combine_types(CType *dest, SValue *op1, SValue *op2, पूर्णांक op)
{
    CType *type1, *type2, type;
    पूर्णांक t1, t2, bt1, bt2;
    पूर्णांक ret = 1;

    /* for shifts, 'combine' only left operand */
    अगर (op == SHIFT_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = शून्य;

    अगर (bt1 == VT_VOID || bt2 == VT_VOID) {
        अगर (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } अन्यथा अगर (bt1 == VT_PTR || bt2 == VT_PTR) {
        अगर (op == '+') {
          अगर (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        अन्यथा अगर (is_null_pointer (op2)) type = *type1;
        अन्यथा अगर (is_null_pointer (op1)) type = *type2;
        अन्यथा अगर (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            अगर ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            अन्यथा अगर (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } अन्यथा {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            पूर्णांक pbt1 = pt1->t & VT_BTYPE;
            पूर्णांक pbt2 = pt2->t & VT_BTYPE;
            पूर्णांक newquals, copied = 0;
            अगर (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                अगर (op != '?' && op != CMP_OP)
                  ret = 0;
                अन्यथा
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            अगर (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                अगर ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_धकेलो(SYM_FIELD, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                अगर (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    अगर (!copied)
                      type.ref = sym_धकेलो(SYM_FIELD, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_धकेलो(SYM_FIELD, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        अगर (op == CMP_OP)
          type.t = VT_आकार_T;
    } अन्यथा अगर (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        अगर (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } अन्यथा अगर (is_float(bt1) || is_float(bt2)) {
        अगर (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } अन्यथा अगर (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } अन्यथा {
            type.t = VT_FLOAT;
        }
    } अन्यथा अगर (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        अगर (bt1 == VT_LLONG)
          type.t &= t1;
        अगर (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        अगर ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } अन्यथा {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        अगर (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_आकार(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_आकार(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    अगर (dest)
      *dest = type;
    वापस ret;
}

/* generic gen_op: handles types problems */
ST_FUNC व्योम gen_op(पूर्णांक op)
{
    पूर्णांक t1, t2, bt1, bt2, t;
    CType type1, combtype;
    पूर्णांक op_class = op;

    अगर (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = SHIFT_OP;
    अन्यथा अगर (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    अगर (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	अगर (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	अगर (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	जाओ redo;
    } अन्यथा अगर (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } अन्यथा अगर (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        पूर्णांक align;
        अगर (op_class == CMP_OP)
            जाओ std_op;
        /* if both pointers, then it must be the '-' op */
        अगर (bt1 == VT_PTR && bt2 == VT_PTR) {
            अगर (op != '-')
                जाओ op_err;
            vpush_type_आकार(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } अन्यथा {
            /* exactly one pointer : must be '+' or '-'. */
            अगर (op != '-' && op != '+')
                जाओ op_err;
            /* Put pointer as first operand */
            अगर (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#अगर PTR_आकार == 4
            अगर (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#पूर्ण_अगर
            type1 = vtop[-1].type;
            vpush_type_आकार(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#अगर_घोषित CONFIG_TCC_BCHECK
            अगर (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                अगर (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_add();
            } अन्यथा
#पूर्ण_अगर
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } अन्यथा {
        /* floats can only be used for a few operations */
        अगर (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            जाओ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        अगर (op_class == SHIFT_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        अगर (t & VT_UNSIGNED) {
            अगर (op == TOK_SAR)
                op = TOK_SHR;
            अन्यथा अगर (op == '/')
                op = TOK_UDIV;
            अन्यथा अगर (op == '%')
                op = TOK_UMOD;
            अन्यथा अगर (op == TOK_LT)
                op = TOK_ULT;
            अन्यथा अगर (op == TOK_GT)
                op = TOK_UGT;
            अन्यथा अगर (op == TOK_LE)
                op = TOK_ULE;
            अन्यथा अगर (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        अगर (is_float(t))
            gen_opif(op);
        अन्यथा
            gen_opic(op);
        अगर (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } अन्यथा {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    अगर (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#अगर defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#घोषणा gen_cvt_itof1 gen_cvt_itof
#अन्यथा
/* generic itof for unsigned long long case */
अटल व्योम gen_cvt_itof1(पूर्णांक t)
{
    अगर ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        अगर (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#अगर LDOUBLE_आकार != 8
        अन्यथा अगर (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#पूर्ण_अगर
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
#पूर्ण_अगर

#अगर defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#घोषणा gen_cvt_ftoi1 gen_cvt_ftoi
#अन्यथा
/* generic ftoi for unsigned long long case */
अटल व्योम gen_cvt_ftoi1(पूर्णांक t)
{
    पूर्णांक st;
    अगर (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        अगर (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#अगर LDOUBLE_आकार != 8
        अन्यथा अगर (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#पूर्ण_अगर
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
#पूर्ण_अगर

/* special delayed cast for char/short */
अटल व्योम force_charshort_cast(व्योम)
{
    पूर्णांक sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    पूर्णांक dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

अटल व्योम gen_cast_s(पूर्णांक t)
{
    CType type;
    type.t = t;
    type.ref = शून्य;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
अटल व्योम gen_cast(CType *type)
{
    पूर्णांक sbt, dbt, sf, df, c;
    पूर्णांक dbt_bt, sbt_bt, ds, ss, bits, trunc;

    /* special delayed cast for char/short */
    अगर (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    अगर (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    अगर (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    अगर (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    अगर (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        अगर (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            जाओ done;
        }
        अगर (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        अगर (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            अगर (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            अन्यथा अगर (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            अगर (df) {
                अगर (sbt_bt == VT_LLONG) {
                    अगर ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    अन्यथा
                        vtop->c.ld = -(दीर्घ द्विगुन)-vtop->c.i;
                } अन्यथा अगर(!sf) {
                    अगर ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    अन्यथा
                        vtop->c.ld = -(दीर्घ द्विगुन)-(uint32_t)vtop->c.i;
                }

                अगर (dbt == VT_FLOAT)
                    vtop->c.f = (भग्न)vtop->c.ld;
                अन्यथा अगर (dbt == VT_DOUBLE)
                    vtop->c.d = (द्विगुन)vtop->c.ld;
            } अन्यथा अगर (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } अन्यथा {
                अगर(sf) {
                    अगर (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    अन्यथा
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                अन्यथा अगर (sbt_bt == VT_LLONG || (PTR_आकार == 8 && sbt == VT_PTR))
                    ;
                अन्यथा अगर (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                अन्यथा
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                अगर (dbt_bt == VT_LLONG || (PTR_आकार == 8 && dbt == VT_PTR))
                    ;
                अन्यथा अगर (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                अन्यथा {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    अगर (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            जाओ done;

        } अन्यथा अगर (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            जाओ done;
        }

        /* cannot generate code for global or static initializers */
        अगर (nocode_wanted & तथ्य_ONLY_WANTED) {
            अगर (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            जाओ done;
        }

        /* non constant case: generate code */
        अगर (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            जाओ done;
        }

        अगर (sf || df) {
            अगर (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } अन्यथा अगर (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } अन्यथा {
                /* convert fp to int */
                sbt = dbt;
                अगर (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                जाओ again; /* may need char/short cast */
            }
            जाओ done;
        }

        ds = btype_आकार(dbt_bt);
        ss = btype_आकार(sbt_bt);
        अगर (ds == 0 || ss == 0)
            जाओ error;

        /* same size and no sign conversion needed */
        अगर (ds == ss && ds >= 4)
            जाओ done;
        अगर (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            अगर (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_आकार == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #घोषणा ALLOW_SUBTYPE_ACCESS 1

        अगर (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            अगर (ds <= ss)
                जाओ done;
            /* ss <= 4 here */
            अगर (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                जाओ done; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#अगर PTR_आकार == 4
        अगर (ds == 8) {
            /* generate high word */
            अगर (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } अन्यथा {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } अन्यथा अगर (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#या_अगर PTR_आकार == 8
        अगर (ds == 8) {
            /* need to convert from 32bit to 64bit */
            अगर (sbt & VT_UNSIGNED) {
#अगर defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#अन्यथा
                जाओ done;
#पूर्ण_अगर
            } अन्यथा {
                gen_cvt_sxtw();
                जाओ done;
            }
            ss = ds, ds = 4, dbt = sbt;
        } अन्यथा अगर (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#अगर !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#पूर्ण_अगर
        } अन्यथा {
            ss = 4;
        }
#पूर्ण_अगर

        अगर (ds >= ss)
            जाओ done;
#अगर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    अगर (ss == 4) {
        gen_cvt_csti(dbt);
        जाओ done;
    }
#पूर्ण_अगर
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
ST_FUNC पूर्णांक type_आकार(CType *type, पूर्णांक *a)
{
    Sym *s;
    पूर्णांक bt;

    bt = type->t & VT_BTYPE;
    अगर (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        वापस s->c;
    } अन्यथा अगर (bt == VT_PTR) {
        अगर (type->t & VT_ARRAY) {
            पूर्णांक ts;
            s = type->ref;
            ts = type_आकार(&s->type, a);
            अगर (s->c < 0)
                वापस s->c;
            वापस ts * s->c;
        } अन्यथा {
            *a = PTR_आकार;
            वापस PTR_आकार;
        }
    } अन्यथा अगर (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        वापस -1; /* incomplete enum */
    } अन्यथा अगर (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        वापस LDOUBLE_आकार;
    } अन्यथा अगर (bt == VT_DOUBLE || bt == VT_LLONG) {
#अगर (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#अन्यथा
        *a = 8;
#पूर्ण_अगर
        वापस 8;
    } अन्यथा अगर (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        वापस 4;
    } अन्यथा अगर (bt == VT_SHORT) {
        *a = 2;
        वापस 2;
    } अन्यथा अगर (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        वापस 16;
    } अन्यथा {
        /* char, void, function, _Bool */
        *a = 1;
        वापस 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
अटल व्योम vpush_type_आकार(CType *type, पूर्णांक *a)
{
    अगर (type->t & VT_VLA) {
        type_आकार(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } अन्यथा {
        पूर्णांक आकार = type_आकार(type, a);
        अगर (आकार < 0)
            tcc_error("unknown type size");
        vpushs(आकार);
    }
}

/* return the pointed type of t */
अटल अंतरभूत CType *pointed_type(CType *type)
{
    वापस &type->ref->type;
}

अटल व्योम check_restrict_type(CType *type)
{
    जबतक ((type->t & VT_BTYPE) == VT_PTR) {
        अगर ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    अगर (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
अटल पूर्णांक type_qualifiers(CType *type)
{
    जबतक (type->t & VT_ARRAY)
        type = pointed_type(type);
    वापस type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC व्योम mk_pointer(CType *type)
{
    Sym *s;
    s = sym_धकेलो(SYM_FIELD, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
अटल पूर्णांक is_compatible_types(CType *type1, CType *type2)
{
    वापस compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
अटल पूर्णांक is_compatible_unqualified_types(CType *type1, CType *type2)
{
    वापस compare_types(type1,type2,1);
}

अटल व्योम cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
अटल व्योम verify_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    पूर्णांक dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    अगर (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    चयन(dbt) {
    हाल VT_VOID:
        अगर (sbt != dbt)
            tcc_error("assignment to void expression");
        अवरोध;
    हाल VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        अगर (is_null_pointer(vtop))
            अवरोध;
        /* accept implicit pointer to integer cast with warning */
        अगर (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            अवरोध;
        }
        type1 = pointed_type(dt);
        अगर (sbt == VT_PTR)
            type2 = pointed_type(st);
        अन्यथा अगर (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        अन्यथा
            जाओ error;
        अगर (is_compatible_types(type1, type2))
            अवरोध;
        क्रम (qualwarn = lvl = 0;; ++lvl) {
            अगर ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            अगर (dbt != VT_PTR || sbt != VT_PTR)
                अवरोध;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        अगर (!is_compatible_unqualified_types(type1, type2)) {
            अगर ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } अन्यथा अगर (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } अन्यथा {
                tcc_warning("assignment from incompatible pointer type");
                अवरोध;
            }
        }
        अगर (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        अवरोध;
    हाल VT_BYTE:
    हाल VT_SHORT:
    हाल VT_INT:
    हाल VT_LLONG:
        अगर (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } अन्यथा अगर (sbt == VT_STRUCT) {
            जाओ case_VT_STRUCT;
        }
        /* XXX: more tests */
        अवरोध;
    हाल VT_STRUCT:
    case_VT_STRUCT:
        अगर (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        अवरोध;
    }
}

अटल व्योम gen_assign_cast(CType *dt)
{
    verify_assign_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC व्योम vstore(व्योम)
{
    पूर्णांक sbt, dbt, ft, r, आकार, align, bit_आकार, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_assign_cast(&vtop[-1].type);

    अगर (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        आकार = type_आकार(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#पूर्ण_अगर
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (vtop->r & VT_MUSTBOUND)
            gbound();
#पूर्ण_अगर
        vtop->type.t = VT_PTR;
        gaddrof();

#अगर_घोषित TCC_TARGET_NATIVE_STRUCT_COPY
        अगर (1
#अगर_घोषित CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#पूर्ण_अगर
            ) {
            gen_struct_copy(आकार);
        } अन्यथा
#पूर्ण_अगर
        {
            /* type size */
            vpushi(आकार);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#अगर_घोषित TCC_ARM_EABI
            अगर(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            अन्यथा अगर(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            अन्यथा
#पूर्ण_अगर
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } अन्यथा अगर (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_आकार = BIT_आकार(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_MASK;

        अगर (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_आकार);
        अगर (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        अगर (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_आकार);
        } अन्यथा {
            अचिन्हित दीर्घ दीर्घ mask = (1ULL << bit_आकार) - 1;
            अगर (dbt != VT_BOOL) {
                /* mask source */
                अगर (dbt == VT_LLONG)
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
            अगर (dbt == VT_LLONG)
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
    } अन्यथा अगर (dbt == VT_VOID) {
        --vtop;
    } अन्यथा {
            /* optimize char/short casts */
            delayed_cast = 0;
            अगर ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                अगर ((vtop->r & VT_MUSTCAST)
                    && btype_आकार(dbt) > btype_आकार(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } अन्यथा {
                gen_cast(&vtop[-1].type);
            }

#अगर_घोषित CONFIG_TCC_BCHECK
            /* bound check case */
            अगर (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#पूर्ण_अगर
            gv(RC_TYPE(dbt)); /* generate value */

            अगर (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            अगर ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = शून्य;
                load(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            अगर (USING_TWO_शब्दगण(dbt)) {
                पूर्णांक load_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = load_type;
                store(r, vtop - 1);
                vswap();
                incr_offset(PTR_आकार);
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
ST_FUNC व्योम inc(पूर्णांक post, पूर्णांक c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    अगर (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    अगर (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (स्थिर अक्षर *संदेश)
{
    /* read the string */
    अगर (tok != TOK_STR)
        expect(संदेश);
    cstr_reset(&initstr);
    जबतक (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.तथ्य, -1);
        अग्र();
    }
    cstr_ccat(&initstr, '\0');
    वापस &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC पूर्णांक exact_log2p1(पूर्णांक i)
{
  पूर्णांक ret;
  अगर (!i)
    वापस 0;
  क्रम (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  अगर (i >= 1 << 4)
    ret += 4, i >>= 4;
  अगर (i >= 1 << 2)
    ret += 2, i >>= 2;
  अगर (i >= 1 << 1)
    ret++;
  वापस ret;
}

/* Parse __attribute__((...)) GNUC extension. */
अटल व्योम parse_attribute(AttributeDef *ad)
{
    पूर्णांक t, n;
    अक्षर *astr;
    AttributeDef ad_tmp;
    
redo:
    अगर (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        वापस;
    अगर (शून्य == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    अग्र();
    skip('(');
    skip('(');
    जबतक (tok != ')') {
        अगर (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        अग्र();
        चयन(t) {
	हाल TOK_CLEANUP1:
	हाल TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    अगर (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } अन्यथा अगर ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    अग्र();
            skip(')');
	    अवरोध;
	}
        हाल TOK_CONSTRUCTOR1:
        हाल TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            अवरोध;
        हाल TOK_DESTRUCTOR1:
        हाल TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            अवरोध;
        हाल TOK_ALWAYS_INLINE1:
        हाल TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            अवरोध;
        हाल TOK_SECTION1:
        हाल TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->तथ्य;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            अवरोध;
        हाल TOK_ALIAS1:
        हाल TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->तथ्य;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            अवरोध;
	हाल TOK_VISIBILITY1:
	हाल TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->तथ्य;
	    अगर (!म_भेद (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    अन्यथा अगर (!म_भेद (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    अन्यथा अगर (!म_भेद (astr, "internal"))
	        ad->a.visibility = STV_INTERNAL;
	    अन्यथा अगर (!म_भेद (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    अन्यथा
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            अवरोध;
        हाल TOK_ALIGNED1:
        हाल TOK_ALIGNED2:
            अगर (tok == '(') {
                अग्र();
                n = व्यंजक_const();
                अगर (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } अन्यथा {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    अगर (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            अवरोध;
        हाल TOK_PACKED1:
        हाल TOK_PACKED2:
            ad->a.packed = 1;
            अवरोध;
        हाल TOK_WEAK1:
        हाल TOK_WEAK2:
            ad->a.weak = 1;
            अवरोध;
        हाल TOK_NODEBUG1:
        हाल TOK_NODEBUG2:
            ad->a.nodebug = 1;
            अवरोध;
        हाल TOK_USED1:
        हाल TOK_USED2:
        हाल TOK_UNUSED1:
        हाल TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            अवरोध;
        हाल TOK_CONST1:
        हाल TOK_CONST2:
        हाल TOK_CONST3:
        हाल TOK_PURE1:
        हाल TOK_PURE2:
	    /* ignored */
            अवरोध;
        हाल TOK_NOINLINE:
	    /* ignored */
	    अवरोध;
        हाल TOK_FORMAT1:
        हाल TOK_FORMAT2:
	    /* ignored */
            जाओ skip_param;
        हाल TOK_NORETURN1:
        हाल TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            अवरोध;
        हाल TOK_CDECL1:
        हाल TOK_CDECL2:
        हाल TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            अवरोध;
        हाल TOK_STDCALL1:
        हाल TOK_STDCALL2:
        हाल TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            अवरोध;
#अगर_घोषित TCC_TARGET_I386
        हाल TOK_REGPARM1:
        हाल TOK_REGPARM2:
            skip('(');
            n = व्यंजक_const();
            अगर (n > 3) 
                n = 3;
            अन्यथा अगर (n < 0)
                n = 0;
            अगर (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            अवरोध;
        हाल TOK_FASTCALL1:
        हाल TOK_FASTCALL2:
        हाल TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            अवरोध;
        हाल TOK_THISCALL1:
        हाल TOK_THISCALL2:
        हाल TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            अवरोध;
#पूर्ण_अगर
        हाल TOK_MODE:
            skip('(');
            चयन(tok) {
                हाल TOK_MODE_DI:
                    ad->attr_mode = VT_LLONG + 1;
                    अवरोध;
                हाल TOK_MODE_QI:
                    ad->attr_mode = VT_BYTE + 1;
                    अवरोध;
                हाल TOK_MODE_HI:
                    ad->attr_mode = VT_SHORT + 1;
                    अवरोध;
                हाल TOK_MODE_SI:
                हाल TOK_MODE_word:
                    ad->attr_mode = VT_INT + 1;
                    अवरोध;
                शेष:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, शून्य));
                    अवरोध;
            }
            अग्र();
            skip(')');
            अवरोध;
        हाल TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            अवरोध;
        हाल TOK_NODECORATE:
            ad->a.nodecorate = 1;
            अवरोध;
        हाल TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            अवरोध;
        शेष:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, शून्य));
            /* skip parameters */
skip_param:
            अगर (tok == '(') {
                पूर्णांक parenthesis = 0;
                करो {
                    अगर (tok == '(') 
                        parenthesis++;
                    अन्यथा अगर (tok == ')') 
                        parenthesis--;
                    अग्र();
                } जबतक (parenthesis && tok != -1);
            }
            अवरोध;
        }
        अगर (tok != ',')
            अवरोध;
        अग्र();
    }
    skip(')');
    skip(')');
    जाओ redo;
}

अटल Sym * find_field (CType *type, पूर्णांक v, पूर्णांक *cumofs)
{
    Sym *s = type->ref;
    पूर्णांक v1 = v | SYM_FIELD;
    अगर (!(v & SYM_FIELD)) { /* top-level call */
        अगर ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        अगर (v < TOK_UIDENT)
            expect("field name");
        अगर (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    जबतक ((s = s->अग्र) != शून्य) {
        अगर (s->v == v1) {
            *cumofs = s->c;
            वापस s;
        }
        अगर ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_FIELD)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_field (&s->type, v1, cumofs);
            अगर (ret) {
                *cumofs += s->c;
                वापस ret;
            }
        }
    }
    अगर (!(v & SYM_FIELD))
        tcc_error("field not found: %s", get_tok_str(v, शून्य));
    वापस s;
}

अटल व्योम check_fields (CType *type, पूर्णांक check)
{
    Sym *s = type->ref;

    जबतक ((s = s->अग्र) != शून्य) {
        पूर्णांक v = s->v & ~SYM_FIELD;
        अगर (v < SYM_FIRST_ANOM) {
            TokenSym *ts = table_ident[v - TOK_IDENT];
            अगर (check && (ts->tok & SYM_FIELD))
                tcc_error("duplicate member '%s'", get_tok_str(v, शून्य));
            ts->tok ^= SYM_FIELD;
        } अन्यथा अगर ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

अटल व्योम struct_layout(CType *type, AttributeDef *ad)
{
    पूर्णांक आकार, align, maxalign, offset, c, bit_pos, bit_आकार;
    पूर्णांक packed, a, bt, prevbt, पूर्व_bit_आकार;
    पूर्णांक pcc = !tcc_state->ms_bitfields;
    पूर्णांक pragma_pack = *tcc_state->pack_ढेर_ptr;
    Sym *f;

    maxalign = 1;
    offset = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    पूर्व_bit_आकार = 0;

//#define BF_DEBUG

    क्रम (f = type->ref->अग्र; f; f = f->अग्र) {
        अगर (f->type.t & VT_BITFIELD)
            bit_आकार = BIT_आकार(f->type.t);
        अन्यथा
            bit_आकार = -1;
        आकार = type_आकार(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        अगर (pcc && bit_आकार == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } अन्यथा {
            /* in pcc mode, attribute packed overrides if set. */
            अगर (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            अगर (pragma_pack) {
                packed = 1;
                अगर (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                अगर (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        अगर (a)
            align = a;

        अगर (type->ref->type.t == VT_UNION) {
	    अगर (pcc && bit_आकार >= 0)
	        आकार = (bit_आकार + 7) >> 3;
	    offset = 0;
	    अगर (आकार > c)
	        c = आकार;

	} अन्यथा अगर (bit_आकार < 0) {
            अगर (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    offset = c;
	    अगर (आकार > 0)
	        c += आकार;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    पूर्व_bit_आकार = 0;

	} अन्यथा {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            अगर (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                अगर (bit_आकार == 0) {
            new_field:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } अन्यथा अगर (f->a.aligned) {
                    जाओ new_field;
                } अन्यथा अगर (!packed) {
                    पूर्णांक a8 = align * 8;
	            पूर्णांक ofs = ((c * 8 + bit_pos) % a8 + bit_आकार + a8 - 1) / a8;
                    अगर (ofs > आकार / align)
                        जाओ new_field;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                अगर (आकार == 8 && bit_आकार <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, आकार = 4;

                जबतक (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                offset = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		अगर (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } अन्यथा {
		bt = f->type.t & VT_BTYPE;
		अगर ((bit_pos + bit_आकार > आकार * 8)
                    || (bit_आकार > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    offset = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    अगर (bit_आकार || पूर्व_bit_आकार)
		        c += आकार;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		अगर (bit_आकार == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                पूर्व_bit_आकार = bit_आकार;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
	    bit_pos += bit_आकार;
	}
	अगर (align > maxalign)
	    maxalign = align;

#अगर_घोषित BF_DEBUG
	म_लिखो("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_FIELD, शून्य), offset, आकार, align);
	अगर (f->type.t & VT_BITFIELD) {
	    म_लिखो(" pos %-2d bits %-2d",
                    BIT_POS(f->type.t),
                    BIT_आकार(f->type.t)
                    );
	}
	म_लिखो("\n");
#पूर्ण_अगर

        f->c = offset;
	f->r = 0;
    }

    अगर (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    अगर (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    अगर (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        अगर (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#अगर_घोषित BF_DEBUG
    म_लिखो("struct size %-2d align %-2d\n\n", c, a), ख_साफ(मानक_निकास);
#पूर्ण_अगर

    /* check whether we can access bitfields by their type */
    क्रम (f = type->ref->अग्र; f; f = f->अग्र) {
        पूर्णांक s, px, cx, c0;
        CType t;

        अगर (0 == (f->type.t & VT_BITFIELD))
            जारी;
        f->type.ref = f;
        f->auxtype = -1;
        bit_आकार = BIT_आकार(f->type.t);
        अगर (bit_आकार == 0)
            जारी;
        bit_pos = BIT_POS(f->type.t);
        आकार = type_आकार(&f->type, &align);

        अगर (bit_pos + bit_आकार <= आकार * 8 && f->c + आकार <= c
#अगर_घोषित TCC_TARGET_ARM
            && !(f->c & (align - 1))
#पूर्ण_अगर
            )
            जारी;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        क्रम (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            अगर (c0 == cx)
                अवरोध;
            s = (px + bit_आकार + 7) >> 3;
            अगर (s > 4) {
                t.t = VT_LLONG;
            } अन्यथा अगर (s > 2) {
                t.t = VT_INT;
            } अन्यथा अगर (s > 1) {
                t.t = VT_SHORT;
            } अन्यथा {
                t.t = VT_BYTE;
            }
            s = type_आकार(&t, &align);
            c0 = cx;
        }

        अगर (px + bit_आकार <= s * 8 && cx + s <= c
#अगर_घोषित TCC_TARGET_ARM
            && !(cx & (align - 1))
#पूर्ण_अगर
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_SHIFT))
		        | (bit_pos << VT_STRUCT_SHIFT);
            अगर (s != आकार)
                f->auxtype = t.t;
#अगर_घोषित BF_DEBUG
            म_लिखो("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_FIELD, शून्य),
                cx, s, align, px, bit_आकार);
#पूर्ण_अगर
        } अन्यथा {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#अगर_घोषित BF_DEBUG
            म_लिखो("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_FIELD, शून्य));
#पूर्ण_अगर
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
अटल पूर्णांक in_range(दीर्घ दीर्घ n, पूर्णांक t)
{
    अचिन्हित दीर्घ दीर्घ m = (1ULL << (btype_आकार(t & VT_BTYPE) * 8 - 1)) - 1;
    अगर (t & VT_UNSIGNED)
        वापस n <= (m << 1) + 1;
    वापस n >= -(दीर्घ दीर्घ)m - 1 && n <= (दीर्घ दीर्घ)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
अटल व्योम struct_decl(CType *type, पूर्णांक u)
{
    पूर्णांक v, c, आकार, align, flexible;
    पूर्णांक bit_आकार, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    स_रखो(&ad, 0, माप ad);
    अग्र();
    parse_attribute(&ad);

    v = 0;
    अगर (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, अग्र();

    bt = ut = 0;
    अगर (u == VT_ENUM) {
        ut = VT_INT;
        अगर (tok == ':') { /* C2x enum : <type> ... */
            अग्र();
            अगर (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    अगर (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        अगर (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            अगर (u == s->type.t)
                जाओ do_decl;
            अगर (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                जाओ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, शून्य));
        }
    } अन्यथा {
        अगर (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = शून्य;
    /* we put an undefined size for struct/union */
    s = sym_धकेलो(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    अगर (tok == '{') {
        अग्र();
        अगर (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->अग्र;
        अगर (u == VT_ENUM) {
            दीर्घ दीर्घ ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            अगर (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            क्रम(;;) {
                v = tok;
                अगर (v < TOK_UIDENT)
                    expect("identifier");
                अग्र();
                अगर (tok == '=') {
                    अग्र();
		    ll = व्यंजक_const64();
                }
                अगर (bt && !in_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, शून्य));
                ss = sym_धकेलो(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->अग्र;
                अगर (ll < nl)
                    nl = ll;
                अगर (ll > pl)
                    pl = ll;
                अगर (tok != ',')
                    अवरोध;
                अग्र();
                ll++;
                /* NOTE: we accept a trailing comma */
                अगर (tok == '}')
                    अवरोध;
            }
            skip('}');

            अगर (bt) {
                t.t = bt;
                s->c = 2;
                जाओ enum_done;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            अगर (nl >= 0) {
                अगर (pl != (अचिन्हित)pl)
                    t.t = (LONG_आकार==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } अन्यथा अगर (pl != (पूर्णांक)pl || nl != (पूर्णांक)nl)
                t.t = (LONG_आकार==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            क्रम (ss = s->अग्र; ss; ss = ss->अग्र) {
                ll = ss->enum_val;
                अगर (ll == (पूर्णांक)ll) /* default is int if it fits */
                    जारी;
                अगर (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    अगर (ll == (अचिन्हित)ll)
                        जारी;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_आकार==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_done:
            s->type.t = type->t = t.t | VT_ENUM;

        } अन्यथा {
            c = 0;
            flexible = 0;
            जबतक (tok != '}') {
                अगर (!parse_btype(&btype, &ad1, 0)) {
                    अगर (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        जारी;
                    }
		    skip(';');
		    जारी;
		}
                जबतक (1) {
		    अगर (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, शून्य));
                    bit_आकार = -1;
                    v = 0;
                    type1 = btype;
                    अगर (tok != ':') {
			अगर (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_DIRECT);
                        अगर (v == 0) {
                    	    अगर ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    अन्यथा {
				पूर्णांक v = btype.ref->v;
				अगर ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    अगर (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        अगर (type_आकार(&type1, &align) < 0) {
			    अगर ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    अन्यथा
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, शून्य));
                        }
                        अगर ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, शून्य));
                    }
                    अगर (tok == ':') {
                        अग्र();
                        bit_आकार = व्यंजक_const();
                        /* XXX: handle v = 0 case for messages */
                        अगर (bit_आकार < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, शून्य));
                        अगर (v && bit_आकार == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, शून्य));
			parse_attribute(&ad1);
                    }
                    आकार = type_आकार(&type1, &align);
                    अगर (bit_आकार >= 0) {
                        bt = type1.t & VT_BTYPE;
                        अगर (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = आकार * 8;
                        अगर (bit_आकार > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, शून्य));
                        } अन्यथा अगर (bit_आकार == bsize
				    && !*tcc_state->pack_ढेर_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } अन्यथा अगर (bit_आकार == 64) {
                            tcc_error("field width 64 not implemented");
                        } अन्यथा {
                            type1.t = (type1.t & ~VT_STRUCT_MASK)
                                | VT_BITFIELD
                                | ((अचिन्हित)bit_आकार << (VT_STRUCT_SHIFT + 6));
                        }
                    }
                    अगर (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    अगर (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_आकार >= 0)) {
		        v = anon_sym++;
		    }
                    अगर (v) {
                        ss = sym_धकेलो(v | SYM_FIELD, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->अग्र;
                    }
                    अगर (tok == ';' || tok == TOK_EOF)
                        अवरोध;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            अगर (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        अगर (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

अटल व्योम sym_to_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
अटल व्योम parse_btype_qualify(CType *type, पूर्णांक qualifiers)
{
    जबतक (type->t & VT_ARRAY) {
        type->ref = sym_धकेलो(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    अगर (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
अटल पूर्णांक parse_btype(CType *type, AttributeDef *ad, पूर्णांक ignore_label)
{
    पूर्णांक t, u, bt, st, type_found, typespec_found, g, n;
    Sym *s;
    CType type1;

    स_रखो(ad, 0, माप(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = शून्य;

    जबतक(1) {
        चयन(tok) {
        हाल TOK_EXTENSION:
            /* currently, we really ignore extension */
            अग्र();
            जारी;

            /* basic types */
        हाल TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            अग्र();
        basic_type1:
            अगर (u == VT_SHORT || u == VT_LONG) {
                अगर (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } अन्यथा {
                अगर (bt != -1 || (st != -1 && u != VT_INT))
                    जाओ tmbt;
                अगर ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    जाओ tmbt;
                bt = u;
            }
            अगर (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_found = 1;
            अवरोध;
        हाल TOK_VOID:
            u = VT_VOID;
            जाओ basic_type;
        हाल TOK_SHORT:
            u = VT_SHORT;
            जाओ basic_type;
        हाल TOK_INT:
            u = VT_INT;
            जाओ basic_type;
        हाल TOK_ALIGNAS:
            { पूर्णांक n;
              AttributeDef ad1;
              अग्र();
              skip('(');
              स_रखो(&ad1, 0, माप(AttributeDef));
              अगर (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  अगर (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  अन्यथा
                    type_आकार(&type1, &n);
              } अन्यथा {
                  n = व्यंजक_const();
                  अगर (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            जारी;
        हाल TOK_LONG:
            अगर ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अन्यथा अगर ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } अन्यथा {
                u = VT_LONG;
                जाओ basic_type;
            }
            अग्र();
            अवरोध;
        हाल TOK_BOOL:
            u = VT_BOOL;
            जाओ basic_type;
        हाल TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        हाल TOK_FLOAT:
            u = VT_FLOAT;
            जाओ basic_type;
        हाल TOK_DOUBLE:
            अगर ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अन्यथा {
                u = VT_DOUBLE;
                जाओ basic_type;
            }
            अग्र();
            अवरोध;
        हाल TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            जाओ basic_type1;
        हाल TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            जाओ basic_type2;
        हाल TOK_UNION:
            struct_decl(&type1, VT_UNION);
            जाओ basic_type2;

            /* type modifiers */
        हाल TOK__Atomic:
            अग्र();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            अगर (tok == '(') {
                parse_व्यंजक_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                अगर (type1.ref)
                    sym_to_attr(ad, type1.ref);
                जाओ basic_type2;
            }
            अवरोध;
        हाल TOK_CONST1:
        हाल TOK_CONST2:
        हाल TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            अग्र();
            अवरोध;
        हाल TOK_VOLATILE1:
        हाल TOK_VOLATILE2:
        हाल TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            अग्र();
            अवरोध;
        हाल TOK_SIGNED1:
        हाल TOK_SIGNED2:
        हाल TOK_SIGNED3:
            अगर ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            अग्र();
            typespec_found = 1;
            अवरोध;
        हाल TOK_RESTRICT1:
        हाल TOK_RESTRICT2:
        हाल TOK_RESTRICT3:
            t |= VT_RESTRICT;
            अग्र();
            अवरोध;
        हाल TOK_REGISTER:
        हाल TOK_AUTO:
            अग्र();
            अवरोध;
        हाल TOK_UNSIGNED:
            अगर ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            अग्र();
            typespec_found = 1;
            अवरोध;

            /* storage */
        हाल TOK_EXTERN:
            g = VT_EXTERN;
            जाओ storage;
        हाल TOK_STATIC:
            g = VT_STATIC;
            जाओ storage;
        हाल TOK_TYPEDEF:
            g = VT_TYPEDEF;
            जाओ storage;
       storage:
            अगर (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            अग्र();
            अवरोध;
        हाल TOK_INLINE1:
        हाल TOK_INLINE2:
        हाल TOK_INLINE3:
            t |= VT_INLINE;
            अग्र();
            अवरोध;
        हाल TOK_NORETURN3:
            अग्र();
            ad->f.func_noreturn = 1;
            अवरोध;
            /* GNUC attribute */
        हाल TOK_ATTRIBUTE1:
        हाल TOK_ATTRIBUTE2:
            parse_attribute(ad);
            अगर (ad->attr_mode) {
                u = ad->attr_mode -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            जारी;
            /* GNUC typeof */
        हाल TOK_TYPEOF1:
        हाल TOK_TYPEOF2:
        हाल TOK_TYPEOF3:
            अग्र();
            parse_व्यंजक_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            अगर (type1.ref) {
                sym_to_attr(ad, type1.ref);
                अगर (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            जाओ basic_type2;
        हाल TOK_THREAD_LOCAL:
        हाल TOK___thread:
            अगर (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            अग्र();
            अवरोध;
        शेष:
            अगर (typespec_found)
                जाओ the_end;
            s = sym_find(tok);
            अगर (!s || !(s->type.t & VT_TYPEDEF))
                जाओ the_end;

            n = tok, अग्र();
            अगर (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                जाओ the_end;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            अगर (t)
                parse_btype_qualify(type, t);
            t = type->t;
            अगर (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_to_attr(ad, s);
            typespec_found = 1;
            st = bt = -2;
            अवरोध;
        }
        type_found = 1;
    }
the_end:
    अगर (tcc_state->char_is_unsigned) {
        अगर ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    अगर (bt == VT_LONG)
        t |= LONG_आकार == 8 ? VT_LLONG : VT_INT;
#अगर_घोषित TCC_USING_DOUBLE_FOR_LDOUBLE
    अगर (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#पूर्ण_अगर
    type->t = t;
    check_restrict_type(type);
    वापस type_found;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
अटल अंतरभूत व्योम convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    अगर ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_pointer(pt);
    }
}

/* apply the conversions required for an expression value */
अटल अंतरभूत व्योम convert_expression_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(व्योम)
{
    skip('(');
    वापस parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
अटल पूर्णांक asm_label_instr(व्योम)
{
    पूर्णांक v;
    अक्षर *astr;

    अग्र();
    astr = parse_asm_str()->तथ्य;
    skip(')');
#अगर_घोषित ASM_DEBUG
    म_लिखो("asm_alias: \"%s\"\n", astr);
#पूर्ण_अगर
    v = tok_alloc_const(astr);
    वापस v;
}

अटल पूर्णांक post_type(CType *type, AttributeDef *ad, पूर्णांक storage, पूर्णांक td)
{
    पूर्णांक n, l, t1, arg_आकार, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = शून्य;
    पूर्णांक *vla_array_str = शून्य;

    अगर (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        अग्र();
	अगर (TYPE_DIRECT == (td & (TYPE_DIRECT|TYPE_ABSTRACT)))
	  वापस 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_ढेर ? &local_ढेर : &global_ढेर;
        ++local_scope;
        sr = sym_push2(ps, SYM_FIELD, 0, 0);

	अगर (tok == ')')
	  l = 0;
	अन्यथा अगर (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	अन्यथा अगर (td & (TYPE_DIRECT|TYPE_ABSTRACT)) {
            sym_निकालो(ps, sr->पूर्व, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    वापस 0;
	} अन्यथा
	  l = FUNC_OLD;

        first = शून्य;
        plast = &first;
        arg_आकार = 0;
        अगर (l) {
            क्रम(;;) {
                /* read param name and compute offset */
                अगर (l != FUNC_OLD) {
                    अगर ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        अवरोध;
                    type_decl(&pt, &ad1, &n, TYPE_DIRECT | TYPE_ABSTRACT | TYPE_PARAM);
                    अगर ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    अगर (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_FIELD;
                } अन्यथा {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = शून्य;
                    अग्र();
                }
                अगर (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_आकार += (type_आकार(&pt, &align) + PTR_आकार - 1) / PTR_आकार;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_धकेलो(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->अग्र;
                अगर (tok == ')')
                    अवरोध;
                skip(',');
                अगर (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    अग्र();
                    अवरोध;
                }
		अगर (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
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
        अगर (tok == '[') {
            अग्र();
            skip(']'); /* only handle simple "[]" */
            mk_pointer(type);
        }
        ad->f.func_args = arg_आकार;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->अग्र = first;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_निकालो(ps, sr, 1);
        --local_scope;

    } अन्यथा अगर (tok == '[') {
	पूर्णांक saved_nocode_wanted = nocode_wanted;
        पूर्णांक array_qualifiers = 0;
        /* array definition */
        अग्र();
        n = -1;
        t1 = 0;
        अगर (td & TYPE_PARAM) जबतक (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    चयन (tok) {
	    हाल TOK_CONST1: हाल TOK_CONST2: हाल TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		अग्र();
		जारी;
	    हाल TOK_VOLATILE1: हाल TOK_VOLATILE2: हाल TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		अग्र();
		जारी;
	    हाल TOK_RESTRICT1: हाल TOK_RESTRICT2: हाल TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		अग्र();
		जारी;
	    हाल TOK_STATIC:
	    हाल '*':
		अग्र();
		जारी;
	    शेष:
		अवरोध;
	    }
            अगर (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_block(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		अग्र();
	        gexpr();
		end_macro();
		अग्र();
		जाओ check;
            }
            अवरोध;

	} अन्यथा अगर (tok != ']') {
            अगर (!local_ढेर || (storage & VT_STATIC))
                vpushi(व्यंजक_const());
            अन्यथा {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                अगर (n < 0)
                    tcc_error("invalid array size");
            } अन्यथा {
                अगर (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_DIRECT|TYPE_ABSTRACT)) | TYPE_NEST);

        अगर ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        अगर ((type->t & VT_BTYPE) == VT_VOID
            || type_आकार(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        अगर (t1 & VT_VLA) {
            अगर (n < 0) {
		अगर  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    अन्यथा {
                loc -= type_आकार(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_आकार(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        अगर (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_धकेलो(SYM_FIELD, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        अगर (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    अगर ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    अन्यथा
	        tok_str_free_str(vla_array_str);
	}
    }
    वापस 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
अटल CType *type_decl(CType *type, AttributeDef *ad, पूर्णांक *v, पूर्णांक td)
{
    CType *post, *ret;
    पूर्णांक qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    जबतक (tok == '*') {
        qualifiers = 0;
    redo:
        अग्र();
        चयन(tok) {
        हाल TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            जाओ redo;
        हाल TOK_CONST1:
        हाल TOK_CONST2:
        हाल TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            जाओ redo;
        हाल TOK_VOLATILE1:
        हाल TOK_VOLATILE2:
        हाल TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            जाओ redo;
        हाल TOK_RESTRICT1:
        हाल TOK_RESTRICT2:
        हाल TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            जाओ redo;
	/* XXX: clarify attribute handling */
	हाल TOK_ATTRIBUTE1:
	हाल TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    अवरोध;
        }
        mk_pointer(type);
        type->t |= qualifiers;
	अगर (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    अगर (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	अगर (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} अन्यथा
	  जाओ abstract;
    } अन्यथा अगर (tok >= TOK_IDENT && (td & TYPE_DIRECT)) {
	/* type identifier */
	*v = tok;
	अग्र();
    } अन्यथा {
  abstract:
	अगर (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_DIRECT|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    वापस ret;
}

/* indirection with full error checking and bound check */
ST_FUNC व्योम indir(व्योम)
{
    अगर ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        अगर ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            वापस;
        expect("pointer");
    }
    अगर (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    अगर (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#पूर्ण_अगर
    }
}

/* pass a parameter to a function and do type checking and casting */
अटल व्योम gfunc_param_typed(Sym *func, Sym *arg)
{
    पूर्णांक func_type;
    CType type;

    func_type = func->f.func_type;
    अगर (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == शून्य)) {
        /* default casting : only need to convert float to double */
        अगर ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } अन्यथा अगर (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } अन्यथा अगर (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } अन्यथा अगर (arg == शून्य) {
        tcc_error("too many arguments to function");
    } अन्यथा {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_assign_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
अटल व्योम व्यंजक_type(CType *type, व्योम (*व्यंजक_fn)(व्योम))
{
    nocode_wanted++;
    व्यंजक_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
अटल व्योम parse_व्यंजक_type(CType *type)
{
    पूर्णांक n;
    AttributeDef ad;

    skip('(');
    अगर (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } अन्यथा {
        व्यंजक_type(type, gexpr);
    }
    skip(')');
}

अटल व्योम parse_type(CType *type)
{
    AttributeDef ad;
    पूर्णांक n;

    अगर (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

अटल व्योम parse_builtin_params(पूर्णांक nc, स्थिर अक्षर *args)
{
    अक्षर c, sep = '(';
    CType type;
    अगर (nc)
        nocode_wanted++;
    अग्र();
    अगर (*args == 0)
	skip(sep);
    जबतक ((c = *args++)) {
	skip(sep);
	sep = ',';
        अगर (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    जारी;
        }
        व्यंजक_eq();
        type.ref = शून्य;
        type.t = 0;
	चयन (c) {
	    हाल 'e':
		जारी;
	    हाल 'V':
                type.t = VT_CONSTANT;
	    हाल 'v':
                type.t |= VT_VOID;
                mk_pointer (&type);
                अवरोध;
	    हाल 'S':
                type.t = VT_CONSTANT;
	    हाल 's':
                type.t |= char_type.t;
                mk_pointer (&type);
                अवरोध;
	    हाल 'i':
                type.t = VT_INT;
                अवरोध;
	    हाल 'l':
                type.t = VT_आकार_T;
                अवरोध;
	    शेष:
                अवरोध;
	}
        gen_assign_cast(&type);
    }
    skip(')');
    अगर (nc)
        nocode_wanted--;
}

अटल व्योम parse_atomic(पूर्णांक atok)
{
    पूर्णांक आकार, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    अक्षर buf[40];
    अटल स्थिर अक्षर *स्थिर templates[] = {
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
    स्थिर अक्षर *ढाँचा = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = शून्य;
    आकार = 0; /* pacify compiler */
    अग्र();
    skip('(');
    क्रम (arg = 0;;) {
        व्यंजक_eq();
        चयन (ढाँचा[arg]) {
        हाल 'a':
        हाल 'A':
            atom_ptr = &vtop->type;
            अगर ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            आकार = type_आकार(atom, &align);
            अगर (आकार > 8
                || (आकार & (आकार - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_आकार(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            अवरोध;

        हाल 'p':
            अगर ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_आकार(pointed_type(&vtop->type), &align) != आकार)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_assign_cast(atom_ptr);
            अवरोध;
        हाल 'v':
            gen_assign_cast(atom);
            अवरोध;
        हाल 'l':
            indir();
            gen_assign_cast(atom);
            अवरोध;
        हाल 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            अवरोध;
        हाल 'm':
            gen_assign_cast(&int_type);
            अवरोध;
        हाल 'b':
            ct.t = VT_BOOL;
            gen_assign_cast(&ct);
            अवरोध;
        }
        अगर ('.' == ढाँचा[++arg])
            अवरोध;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    चयन (ढाँचा[arg + 1]) {
    हाल 'b':
        ct.t = VT_BOOL;
        अवरोध;
    हाल 'v':
        ct = *atom;
        अवरोध;
    }

    प्र_लिखो(buf, "%s_%d", get_tok_str(atok, 0), आकार);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    अगर (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#अगर_घोषित PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अन्यथा
        vtop->type.t = VT_INT;
#पूर्ण_अगर
    }
    gen_cast(&ct);
    अगर (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC व्योम unary(व्योम)
{
    पूर्णांक n, t, align, आकार, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    अगर (debug_modes)
        tcc_debug_पंक्ति(tcc_state), tcc_tcov_check_पंक्ति (tcc_state, 1);

    type.ref = शून्य;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_अग्र:
    चयन(tok) {
    हाल TOK_EXTENSION:
        अग्र();
        जाओ tok_अग्र;
    हाल TOK_LCHAR:
#अगर_घोषित TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        जाओ धकेलो_tokc;
#पूर्ण_अगर
    हाल TOK_CINT:
    हाल TOK_CCHAR: 
	t = VT_INT;
 धकेलो_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        अग्र();
        अवरोध;
    हाल TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        जाओ धकेलो_tokc;
    हाल TOK_CLLONG:
        t = VT_LLONG;
	जाओ धकेलो_tokc;
    हाल TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	जाओ धकेलो_tokc;
    हाल TOK_CFLOAT:
        t = VT_FLOAT;
	जाओ धकेलो_tokc;
    हाल TOK_CDOUBLE:
        t = VT_DOUBLE;
	जाओ धकेलो_tokc;
    हाल TOK_CLDOUBLE:
#अगर_घोषित TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#अन्यथा
        t = VT_LDOUBLE;
#पूर्ण_अगर
	जाओ धकेलो_tokc;
    हाल TOK_CLONG:
        t = (LONG_आकार == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	जाओ धकेलो_tokc;
    हाल TOK_CULONG:
        t = (LONG_आकार == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	जाओ धकेलो_tokc;
    हाल TOK___FUNCTION__:
        अगर (!gnu_ext)
            जाओ tok_identifier;
        /* fall thru */
    हाल TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.तथ्य = tokcstr.तथ्य;
        जाओ case_TOK_STR;
    हाल TOK_LSTR:
#अगर_घोषित TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#अन्यथा
        t = VT_INT;
#पूर्ण_अगर
        जाओ str_init;
    हाल TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        अगर (tcc_state->warn_write_strings & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        स_रखो(&ad, 0, माप(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        अवरोध;
    हाल TOK_SOTYPE:
    हाल '(':
        t = tok;
        अग्र();
        /* cast ? */
        अगर (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            अगर (tok == '{') {
                    /* data is allocated locally by default */
                अगर (global_व्यंजक)
                    r = VT_CONST;
                अन्यथा
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                अगर (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                स_रखो(&ad, 0, माप(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } अन्यथा अगर (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                वापस;
            } अन्यथा {
                unary();
                gen_cast(&type);
            }
        } अन्यथा अगर (tok == '{') {
	    पूर्णांक saved_nocode_wanted = nocode_wanted;
            अगर (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            अगर (0 == local_scope)
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
            block(STMT_व्यंजक);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            अगर (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } अन्यथा {
            gexpr();
            skip(')');
        }
        अवरोध;
    हाल '*':
        अग्र();
        unary();
        indir();
        अवरोध;
    हाल '&':
        अग्र();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        अगर ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        अगर (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        अवरोध;
    हाल '!':
        अग्र();
        unary();
        gen_test_zero(TOK_EQ);
        अवरोध;
    हाल '~':
        अग्र();
        unary();
        vpushi(-1);
        gen_op('^');
        अवरोध;
    हाल '+':
        अग्र();
        unary();
        अगर ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	अगर (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        अवरोध;
    हाल TOK_SIZEOF:
    हाल TOK_ALIGNOF1:
    हाल TOK_ALIGNOF2:
    हाल TOK_ALIGNOF3:
        t = tok;
        अग्र();
        अगर (tok == '(')
            tok = TOK_SOTYPE;
        व्यंजक_type(&type, unary);
        अगर (t == TOK_SIZEOF) {
            vpush_type_आकार(&type, &align);
            gen_cast_s(VT_आकार_T);
        } अन्यथा {
            type_आकार(&type, &align);
            s = शून्य;
            अगर (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            अगर (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        अवरोध;

    हाल TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        अवरोध;
    हाल TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        अवरोध;
    हाल TOK_builtin_choose_व्यंजक:
	{
	    int64_t c;
	    अग्र();
	    skip('(');
	    c = व्यंजक_const64();
	    skip(',');
	    अगर (!c) {
		nocode_wanted++;
	    }
	    व्यंजक_eq();
	    अगर (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    अगर (c) {
		nocode_wanted++;
	    }
	    व्यंजक_eq();
	    अगर (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        अवरोध;
    हाल TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        अवरोध;
    हाल TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        CODE_OFF();
        अवरोध;
    हाल TOK_builtin_frame_address:
    हाल TOK_builtin_return_address:
        {
            पूर्णांक tok1 = tok;
            पूर्णांक level;
            अग्र();
            skip('(');
            level = व्यंजक_const();
            अगर (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            जबतक (level--) {
#अगर_घोषित TCC_TARGET_RISCV64
                vpushi(2*PTR_आकार);
                gen_op('-');
#पूर्ण_अगर
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            अगर (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
#अगर_घोषित TCC_TARGET_ARM
                vpushi(2*PTR_आकार);
                gen_op('+');
#या_अगर defined TCC_TARGET_RISCV64
                vpushi(PTR_आकार);
                gen_op('-');
#अन्यथा
                vpushi(PTR_आकार);
                gen_op('+');
#पूर्ण_अगर
                mk_pointer(&vtop->type);
                indir();
            }
        }
        अवरोध;
#अगर_घोषित TCC_TARGET_RISCV64
    हाल TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        अगर (r == VT_LLOCAL)
            r = VT_LOCAL;
        अगर (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        अवरोध;
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_X86_64
#अगर_घोषित TCC_TARGET_PE
    हाल TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        अगर (r == VT_LLOCAL)
            r = VT_LOCAL;
        अगर (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        अवरोध;
#अन्यथा
    हाल TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	अवरोध;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_ARM64
    हाल TOK_builtin_va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        अवरोध;
    }
    हाल TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        अवरोध;
    }
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_ARM64
    हाल TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        अवरोध;
    }
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_RISCV64
    हाल TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        अवरोध;
    }
#पूर्ण_अगर

    /* atomic operations */
    हाल TOK___atomic_store:
    हाल TOK___atomic_load:
    हाल TOK___atomic_exchange:
    हाल TOK___atomic_compare_exchange:
    हाल TOK___atomic_fetch_add:
    हाल TOK___atomic_fetch_sub:
    हाल TOK___atomic_fetch_or:
    हाल TOK___atomic_fetch_xor:
    हाल TOK___atomic_fetch_and:
    हाल TOK___atomic_fetch_nand:
    हाल TOK___atomic_add_fetch:
    हाल TOK___atomic_sub_fetch:
    हाल TOK___atomic_or_fetch:
    हाल TOK___atomic_xor_fetch:
    हाल TOK___atomic_and_fetch:
    हाल TOK___atomic_nand_fetch:
        parse_atomic(tok);
        अवरोध;

    /* pre operations */
    हाल TOK_INC:
    हाल TOK_DEC:
        t = tok;
        अग्र();
        unary();
        inc(0, t);
        अवरोध;
    हाल '-':
        अग्र();
        unary();
	अगर (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} अन्यथा {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        अवरोध;
    हाल TOK_LAND:
        अगर (!gnu_ext)
            जाओ tok_identifier;
        अग्र();
        /* allow to take the address of a label */
        अगर (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        अगर (!s) {
            s = label_धकेलो(&global_label_ढेर, tok, LABEL_FORWARD);
        } अन्यथा {
            अगर (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        अगर ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        अग्र();
        अवरोध;

    हाल TOK_GENERIC:
    {
	CType controlling_type;
	पूर्णांक has_default = 0;
	पूर्णांक has_match = 0;
	पूर्णांक learn = 0;
	TokenString *str = शून्य;
	पूर्णांक saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_MASK;

        अग्र();
	skip('(');
	व्यंजक_type(&controlling_type, व्यंजक_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        क्रम (;;) {
	    learn = 0;
	    skip(',');
	    अगर (tok == TOK_DEFAULT) {
		अगर (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		अगर (!has_match)
		    learn = 1;
		अग्र();
	    } अन्यथा {
		पूर्णांक v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		अगर (compare_types(&controlling_type, &type, 0)) {
		    अगर (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    अगर (learn) {
		अगर (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } अन्यथा {
		skip_or_save_block(शून्य);
	    }
	    अगर (tok == ')')
		अवरोध;
	}
	अगर (!str) {
	    अक्षर buf[60];
	    type_to_str(buf, माप buf, &controlling_type, शून्य);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	अग्र();
	व्यंजक_eq();
	अगर (tok != TOK_EOF)
	    expect(",");
	end_macro();
        अग्र();
	अवरोध;
    }
    // special qnan , snan and infinity values
    हाल TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        अग्र();
        अवरोध;
    हाल TOK___SNAN__:
	n = 0x7f800001;
	जाओ special_math_val;
    हाल TOK___INF__:
	n = 0x7f800000;
	जाओ special_math_val;

    शेष:
    tok_identifier:
        अगर (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        अग्र();
        s = sym_find(t);
        अगर (!s || IS_ASM_SYM(s)) {
            स्थिर अक्षर *name = get_tok_str(t, शून्य);
            अगर (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            अगर (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        अगर ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        अगर (r & VT_SYM) {
            vtop->c.i = 0;
#अगर_घोषित TCC_TARGET_PE
            अगर (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#पूर्ण_अगर
        } अन्यथा अगर (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        अवरोध;
    }
    
    /* post operations */
    जबतक (1) {
        अगर (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            अग्र();
        } अन्यथा अगर (tok == '.' || tok == TOK_ARROW) {
            पूर्णांक qualifiers, cumofs;
            /* field */ 
            अगर (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            अग्र();
	    s = find_field(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_pointer_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            अगर (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            अगर (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#अगर_घोषित CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                अगर (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#पूर्ण_अगर
            }
            अग्र();
        } अन्यथा अगर (tok == '[') {
            अग्र();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } अन्यथा अगर (tok == '(') {
            SValue ret;
            Sym *sa;
            पूर्णांक nb_args, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            अगर ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                अगर ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    अगर ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        जाओ error_func;
                } अन्यथा {
                error_func:
                    expect("function pointer");
                }
            } अन्यथा {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            अग्र();
            sa = s->अग्र; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            अगर ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                अगर (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    आकार = type_आकार(&s->type, &align);
#अगर_घोषित TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                अगर (आकार < 16)
                    जबतक (आकार & (आकार - 1))
                        आकार = (आकार | (आकार - 1)) + 1;
#पूर्ण_अगर
                    loc = (loc - आकार) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#अगर_घोषित CONFIG_TCC_BCHECK
                    अगर (tcc_state->do_bounds_check)
                        --loc;
#पूर्ण_अगर
                    ret.c = vtop->c;
                    अगर (ret_nregs < 0)
                      vtop--;
                    अन्यथा
                      nb_args++;
                }
            } अन्यथा {
                ret_nregs = 1;
                ret.type = s->type;
            }

            अगर (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = शून्य;
            अगर (tok != ')') {
                r = tcc_state->reverse_funcargs;
                क्रम(;;) {
                    अगर (r) {
                        skip_or_save_block(&p2);
                        p2->पूर्व = p, p = p2;
                    } अन्यथा {
                        व्यंजक_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_args++;
                    अगर (sa)
                        sa = sa->अग्र;
                    अगर (tok == ')')
                        अवरोध;
                    skip(',');
                }
            }
            अगर (sa)
                tcc_error("too few arguments to function");

            अगर (p) { /* with reverse_funcargs */
                क्रम (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    करो {
                        sa = sa->अग्र, p2 = p2->पूर्व;
                    } जबतक (p2 && sa);
                    p2 = p->पूर्व;
                    begin_macro(p, 1), अग्र();
                    व्यंजक_eq();
                    gfunc_param_typed(s, sa);
                    end_macro();
                }
                vrev(n);
            }

            अग्र();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_args);

            अगर (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#अगर_घोषित TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#पूर्ण_अगर
            } अन्यथा {
                /* return value */
                n = ret_nregs;
                जबतक (n > 1) {
                    पूर्णांक rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    क्रम (r = 0; r < NB_REGS; ++r)
                        अगर (reg_classes[r] & rc)
                            अवरोध;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                अगर (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    पूर्णांक addr, offset;

                    आकार = type_आकार(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    आकार = (आकार + regsize - 1) & -regsize;
                    अगर (ret_align > align)
                        align = ret_align;
                    loc = (loc - आकार) & -align;
                    addr = loc;
                    offset = 0;
                    क्रम (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                        vswap();
                        vstore();
                        vtop--;
                        अगर (--ret_nregs == 0)
                          अवरोध;
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
                अगर (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#अगर_घोषित PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अन्यथा
                    vtop->type.t = VT_INT;
#पूर्ण_अगर
                }
            }
            अगर (s->f.func_noreturn) {
                अगर (debug_modes)
	            tcc_tcov_block_end(tcc_state, -1);
                CODE_OFF();
	    }
        } अन्यथा {
            अवरोध;
        }
    }
}

#अगर_अघोषित precedence_parser /* original top-down parser */

अटल व्योम व्यंजक_prod(व्योम)
{
    पूर्णांक t;

    unary();
    जबतक ((t = tok) == '*' || t == '/' || t == '%') {
        अग्र();
        unary();
        gen_op(t);
    }
}

अटल व्योम व्यंजक_योग(व्योम)
{
    पूर्णांक t;

    व्यंजक_prod();
    जबतक ((t = tok) == '+' || t == '-') {
        अग्र();
        व्यंजक_prod();
        gen_op(t);
    }
}

अटल व्योम व्यंजक_shift(व्योम)
{
    पूर्णांक t;

    व्यंजक_योग();
    जबतक ((t = tok) == TOK_SHL || t == TOK_SAR) {
        अग्र();
        व्यंजक_योग();
        gen_op(t);
    }
}

अटल व्योम व्यंजक_cmp(व्योम)
{
    पूर्णांक t;

    व्यंजक_shift();
    जबतक (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        अग्र();
        व्यंजक_shift();
        gen_op(t);
    }
}

अटल व्योम व्यंजक_cmpeq(व्योम)
{
    पूर्णांक t;

    व्यंजक_cmp();
    जबतक ((t = tok) == TOK_EQ || t == TOK_NE) {
        अग्र();
        व्यंजक_cmp();
        gen_op(t);
    }
}

अटल व्योम व्यंजक_and(व्योम)
{
    व्यंजक_cmpeq();
    जबतक (tok == '&') {
        अग्र();
        व्यंजक_cmpeq();
        gen_op('&');
    }
}

अटल व्योम व्यंजक_xor(व्योम)
{
    व्यंजक_and();
    जबतक (tok == '^') {
        अग्र();
        व्यंजक_and();
        gen_op('^');
    }
}

अटल व्योम व्यंजक_or(व्योम)
{
    व्यंजक_xor();
    जबतक (tok == '|') {
        अग्र();
        व्यंजक_xor();
        gen_op('|');
    }
}

अटल व्योम व्यंजक_landor(पूर्णांक op);

अटल व्योम व्यंजक_land(व्योम)
{
    व्यंजक_or();
    अगर (tok == TOK_LAND)
        व्यंजक_landor(tok);
}

अटल व्योम व्यंजक_lor(व्योम)
{
    व्यंजक_land();
    अगर (tok == TOK_LOR)
        व्यंजक_landor(tok);
}

# define व्यंजक_landor_अग्र(op) op == TOK_LAND ? व्यंजक_or() : व्यंजक_land()
#अन्यथा /* defined precedence_parser */
# define व्यंजक_landor_अग्र(op) unary(), व्यंजक_infix(precedence(op) + 1)
# define व्यंजक_lor() unary(), व्यंजक_infix(1)

अटल पूर्णांक precedence(पूर्णांक tok)
{
    चयन (tok) {
        हाल TOK_LOR: वापस 1;
        हाल TOK_LAND: वापस 2;
	हाल '|': वापस 3;
	हाल '^': वापस 4;
	हाल '&': वापस 5;
	हाल TOK_EQ: हाल TOK_NE: वापस 6;
 relat: हाल TOK_ULT: हाल TOK_UGE: वापस 7;
	हाल TOK_SHL: हाल TOK_SAR: वापस 8;
	हाल '+': हाल '-': वापस 9;
	हाल '*': हाल '/': हाल '%': वापस 10;
	शेष:
	    अगर (tok >= TOK_ULE && tok <= TOK_GT)
	        जाओ relat;
	    वापस 0;
    }
}
अटल अचिन्हित अक्षर prec[256];
अटल व्योम init_prec(व्योम)
{
    पूर्णांक i;
    क्रम (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#घोषणा precedence(i) ((अचिन्हित)i < 256 ? prec[i] : 0)

अटल व्योम व्यंजक_landor(पूर्णांक op);

अटल व्योम व्यंजक_infix(पूर्णांक p)
{
    पूर्णांक t = tok, p2;
    जबतक ((p2 = precedence(t)) >= p) {
        अगर (t == TOK_LOR || t == TOK_LAND) {
            व्यंजक_landor(t);
        } अन्यथा {
            अग्र();
            unary();
            अगर (precedence(tok) > p2)
              व्यंजक_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#पूर्ण_अगर

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
अटल पूर्णांक condition_3way(व्योम)
{
    पूर्णांक c = -1;
    अगर ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    वापस c;
}

अटल व्योम व्यंजक_landor(पूर्णांक op)
{
    पूर्णांक t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    क्रम(;;) {
        c = f ? i : condition_3way();
        अगर (c < 0)
            save_regs(1), cc = 0;
        अन्यथा अगर (c != i)
            nocode_wanted++, f = 1;
        अगर (tok != op)
            अवरोध;
        अगर (c < 0)
            t = gvtst(i, t);
        अन्यथा
            vpop();
        अग्र();
        व्यंजक_landor_अग्र(op);
    }
    अगर (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } अन्यथा {
        gvtst_set(i, t);
    }
}

अटल पूर्णांक is_cond_bool(SValue *sv)
{
    अगर ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        वापस (अचिन्हित)sv->c.i < 2;
    अगर (sv->r == VT_CMP)
        वापस 1;
    वापस 0;
}

अटल व्योम व्यंजक_cond(व्योम)
{
    पूर्णांक tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    व्यंजक_lor();
    अगर (tok == '?') {
        अग्र();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        अगर (!g) {
            अगर (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } अन्यथा {
                vpop();
            }
        } अन्यथा अगर (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        अगर (c == 0)
          nocode_wanted++;
        अगर (!g)
          gexpr();

        अगर ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        अगर (g) {
            u = tt;
        } अन्यथा अगर (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } अन्यथा
          u = 0;

        अगर (c == 0)
          nocode_wanted--;
        अगर (c == 1)
          nocode_wanted++;
        skip(':');
        व्यंजक_cond();

        अगर ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        अगर (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        अगर (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
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
            वापस;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        अगर (c != 1) {
            gen_cast(&type);
            अगर (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        अगर (USING_TWO_शब्दगण(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        अगर (c < 0) {
            अगर (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        अगर (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
           operand */
        अगर (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            अगर (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        अगर (c < 0) {
            अगर (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        अगर (islv)
          indir();
    }
}

अटल व्योम व्यंजक_eq(व्योम)
{
    पूर्णांक t;
    
    व्यंजक_cond();
    अगर ((t = tok) == '=' || TOK_ASSIGN(t)) {
        test_lvalue();
        अग्र();
        अगर (t == '=') {
            व्यंजक_eq();
        } अन्यथा {
            vdup();
            व्यंजक_eq();
            gen_op(TOK_ASSIGN_OP(t));
        }
        vstore();
    }
}

ST_FUNC व्योम gexpr(व्योम)
{
    व्यंजक_eq();
    अगर (tok == ',') {
        करो {
            vpop();
            अग्र();
            व्यंजक_eq();
        } जबतक (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        अगर ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            अगर (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
अटल व्योम व्यंजक_const1(व्योम)
{
    nocode_wanted += CONST_WANTED_BIT;
    व्यंजक_cond();
    nocode_wanted -= CONST_WANTED_BIT;
}

/* parse an integer constant and return its value. */
अटल अंतरभूत int64_t व्यंजक_const64(व्योम)
{
    int64_t c;
    व्यंजक_const1();
    अगर ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    वापस c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC पूर्णांक व्यंजक_const(व्योम)
{
    पूर्णांक c;
    int64_t wc = व्यंजक_const64();
    c = wc;
    अगर (c != wc && (अचिन्हित)c != wc)
        tcc_error("constant exceeds 32 bit");
    वापस c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#अगर_अघोषित TCC_TARGET_ARM64
अटल व्योम gfunc_return(CType *func_type)
{
    अगर ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        पूर्णांक ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        अगर (ret_nregs < 0) {
#अगर_घोषित TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#पूर्ण_अगर
        } अन्यथा अगर (0 == ret_nregs) {
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
            पूर्णांक आकार, addr, align, rc, n;
            आकार = type_आकार(func_type,&align);
            अगर (ret_nregs * regsize > आकार ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		अगर (ret_nregs * regsize > आकार)
		    आकार = ret_nregs * regsize;
		अगर (ret_align > align)
		    align = ret_align;
                loc = (loc - आकार) & -align;
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
            क्रम (n = ret_nregs; --n > 0;) {
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
#पूर्ण_अगर

अटल व्योम check_func_return(व्योम)
{
    अगर ((func_vt.t & VT_BTYPE) == VT_VOID)
        वापस;
    अगर ((!म_भेद(funcname, "main") || func_old)
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

अटल पूर्णांक case_cmp(uint64_t a, uint64_t b)
{
    अगर (cur_switch->sv.type.t & VT_UNSIGNED)
        वापस a < b ? -1 : a > b;
    अन्यथा
        वापस (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

अटल पूर्णांक case_cmp_qs(स्थिर व्योम *pa, स्थिर व्योम *pb)
{
    वापस case_cmp((*(काष्ठा case_t**)pa)->v1, (*(काष्ठा case_t**)pb)->v1);
}

अटल व्योम case_sort(काष्ठा switch_t *sw)
{
    काष्ठा case_t **p;
    अगर (sw->n < 2)
        वापस;
    क्विक(sw->p, sw->n, माप *sw->p, case_cmp_qs);
    p = sw->p;
    जबतक (p < sw->p + sw->n - 1) {
        अगर (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            पूर्णांक l1 = p[0]->पंक्ति_2, l2 = p[1]->पंक्ति_2;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } अन्यथा अगर (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            स_हटाओ(p, p + 1, (--sw->n - (p - sw->p)) * माप *p);
        } अन्यथा
            ++p;
    }
}

अटल पूर्णांक gcase(काष्ठा case_t **base, पूर्णांक len, पूर्णांक dsym)
{
    काष्ठा case_t *p;
    पूर्णांक t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    अगर (t != VT_LLONG)
        t = VT_INT;
    जबतक (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = base[l2];
        vdup(), vpush64(t, p->v2);
        अगर (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } अन्यथा {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            अगर (len == 1) /* last case test jumps to default when false */
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
    वापस gjmp(dsym);
}

अटल व्योम end_switch(व्योम)
{
    काष्ठा switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->पूर्व;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
अटल व्योम save_lvalues(व्योम)
{
    SValue *sv = vtop;
    जबतक (sv >= vstack) {
        अगर (sv->sym && (sv->r & VT_LVAL)) {
            पूर्णांक align, आकार = type_आकार(&sv->type, &align);
            पूर्णांक r2, l = get_अस्थायी_local_var(आकार, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

अटल व्योम try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    क्रम (; cls != stop; cls = cls->अग्र) {
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


अटल व्योम try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    पूर्णांक ocd, ccd;

    अगर (!cur_scope->cl.s)
	वापस;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_FIELD : 0;
    क्रम (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->अग्र)
      ;
    क्रम (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->अग्र)
      ;
    क्रम (; cc != oc; cc = cc->अग्र, oc = oc->अग्र, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
अटल व्योम block_cleanup(काष्ठा scope *o)
{
    पूर्णांक jmp = 0;
    Sym *g, **pg;
    क्रम (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        अगर (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->अग्र;
            अगर (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            अगर (!o->cl.n)
                जाओ remove_pending;
            g->c = o->cl.n;
            pg = &g->पूर्व;
        } अन्यथा {
    remove_pending:
            *pg = g->पूर्व;
            sym_free(g);
        }
    }
    gsym(jmp);
    try_call_scope_cleanup(o->cl.s);
}

/* ------------------------------------------------------------------------- */
/* VLA */

अटल व्योम vla_restore(पूर्णांक loc)
{
    अगर (loc)
        gen_vla_sp_restore(loc);
}

अटल व्योम vla_leave(काष्ठा scope *o)
{
    काष्ठा scope *c = cur_scope, *v = शून्य;
    क्रम (; c != o && c; c = c->पूर्व)
      अगर (c->vla.अंक)
        v = c;
    अगर (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

अटल व्योम new_scope(काष्ठा scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->पूर्व = cur_scope;
    cur_scope = o;
    cur_scope->vla.अंक = 0;

    /* record local declaration stack position */
    o->lstk = local_ढेर;
    o->llstk = local_label_ढेर;
    ++local_scope;
}

अटल व्योम पूर्व_scope(काष्ठा scope *o, पूर्णांक is_व्यंजक)
{
    vla_leave(o->पूर्व);

    अगर (o->cl.s != o->पूर्व->cl.s)
        block_cleanup(o->पूर्व);

    अगर (debug_modes)
        tcc_debug_end_scope(o->lstk, !is_व्यंजक);

    /* pop locally defined labels */
    label_निकालो(&local_label_ढेर, o->llstk, is_व्यंजक);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_निकालो(&local_ढेर, o->lstk, is_व्यंजक);
    cur_scope = o->पूर्व;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
अटल व्योम leave_scope(काष्ठा scope *o)
{
    अगर (!o)
        वापस;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
अटल व्योम new_scope_s(काष्ठा scope *o)
{
    o->lstk = local_ढेर;
    ++local_scope;
}

अटल व्योम पूर्व_scope_s(काष्ठा scope *o)
{
    sym_निकालो(&local_ढेर, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

अटल व्योम lblock(पूर्णांक *bsym, पूर्णांक *csym)
{
    काष्ठा scope *lo = loop_scope, *co = cur_scope;
    पूर्णांक *b = co->bsym, *c = co->csym;
    अगर (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    block(0);
    co->bsym = b;
    अगर (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
अटल व्योम gexpr_decl(व्योम)
{
    पूर्णांक v = decl(VT_JMP);
    अगर (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } अन्यथा {
        अगर (v)
            skip(';');
        gexpr();
    }
}

अटल व्योम block(पूर्णांक flags)
{
    पूर्णांक a, b, c, d, e, t;
    काष्ठा scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    अगर (TOK_HAS_मूल्य(t))
        जाओ व्यंजक;
    अग्र();

    अगर (debug_modes)
        tcc_tcov_check_पंक्ति (tcc_state, 0), tcc_tcov_block_begin (tcc_state);

    अगर (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        block(0);
        अगर (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            अग्र();
            block(0);
            gsym(d); /* patch else jmp */
        } अन्यथा {
            gsym(a);
        }
        पूर्व_scope_s(&o);

    } अन्यथा अगर (t == TOK_WHILE) {
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
        पूर्व_scope_s(&o);

    } अन्यथा अगर (t == '{') {
        अगर (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        जबतक (tok == TOK_LABEL) {
            करो {
                अग्र();
                अगर (tok < TOK_UIDENT)
                    expect("label identifier");
                label_धकेलो(&local_label_ढेर, tok, LABEL_DECLARED);
                अग्र();
            } जबतक (tok == ',');
            skip(';');
        }

        जबतक (tok != '}') {
	    decl(VT_LOCAL);
            अगर (tok != '}') {
                block(flags | STMT_COMPOUND);
            }
        }

        पूर्व_scope(&o, flags & STMT_व्यंजक);
        अगर (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        अगर (local_scope)
            अग्र();
        अन्यथा अगर (!nocode_wanted)
            check_func_return();

    } अन्यथा अगर (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        अगर (tok != ';') {
            gexpr();
            अगर (b) {
                gen_assign_cast(&func_vt);
            } अन्यथा {
                अगर (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } अन्यथा अगर (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } अन्यथा अगर (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(मूल_scope);
        अगर (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        अगर (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        अगर (debug_modes)
	    tcc_tcov_block_end (tcc_state, -1);
        CODE_OFF();

    } अन्यथा अगर (t == TOK_BREAK) {
        /* compute jump */
        अगर (!cur_scope->bsym)
            tcc_error("cannot break");
        अगर (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        अन्यथा
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } अन्यथा अगर (t == TOK_CONTINUE) {
        /* compute jump */
        अगर (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } अन्यथा अगर (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        अगर (tok != ';') {
            /* c99 for-loop init decl? */
            अगर (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        अगर (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        अगर (tok != ')') {
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
        पूर्व_scope(&o, 0);

    } अन्यथा अगर (t == TOK_DO) {
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
        पूर्व_scope_s(&o);

    } अन्यथा अगर (t == TOK_SWITCH) {
        काष्ठा switch_t *sw;

        sw = tcc_mallocz(माप *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->पूर्व = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        अगर (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, शून्य);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        पूर्व_scope_s(&o);
        अगर (sw->nocode_wanted)
            जाओ skip_switch;
        case_sort(sw);
        sw->bsym = शून्य; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        अगर (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        अन्यथा
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        end_switch();

    } अन्यथा अगर (t == TOK_CASE) {
        काष्ठा case_t *cr;
        अगर (!cur_switch)
            expect("switch");
        cr = tcc_malloc(माप(काष्ठा case_t));
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(व्यंजक_const64(), t);
        अगर (tok == TOK_DOTS && gnu_ext) {
            अग्र();
            cr->v2 = value64(व्यंजक_const64(), t);
            अगर (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        अगर (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->पंक्ति_2 = file->पंक्ति_अंक;
        skip(':');
        जाओ block_after_label;

    } अन्यथा अगर (t == TOK_DEFAULT) {
        अगर (!cur_switch)
            expect("switch");
        अगर (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        जाओ block_after_label;

    } अन्यथा अगर (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        अगर (tok == '*' && gnu_ext) {
            /* computed goto */
            अग्र();
            gexpr();
            अगर ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } अन्यथा अगर (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            अगर (!s)
              s = label_धकेलो(&global_label_ढेर, tok, LABEL_FORWARD);
            अन्यथा अगर (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    अगर (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		अगर (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_FIELD, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->अग्र, SYM_FIELD, 0, 0);
                    pending_gotos->अग्र = s;
                }
		s->jnext = gjmp(s->jnext);
	    } अन्यथा {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    अग्र();

        } अन्यथा {
            expect("label identifier");
        }
        skip(';');

    } अन्यथा अगर (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } अन्यथा {
        अगर (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    अग्र();
            s = label_find(t);
            अगर (s) {
                अगर (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, शून्य));
                s->r = LABEL_DEFINED;
		अगर (s->अग्र) {
		    Sym *pcl; /* pending cleanup goto */
		    क्रम (pcl = s->अग्र; pcl; pcl = pcl->पूर्व)
		      gsym(pcl->jnext);
		    sym_निकालो(&s->अग्र, शून्य, 0);
		} अन्यथा
		  gsym(s->jnext);
            } अन्यथा {
                s = label_धकेलो(&global_label_ढेर, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    block_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(शून्य);

            अगर (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            अगर (tok != '}') {
                अगर (0 == (flags & STMT_COMPOUND))
                    जाओ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } अन्यथा {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } अन्यथा {
            /* expression case */
            अगर (t != ';') {
                unget_tok(t);
    व्यंजक:
                अगर (flags & STMT_व्यंजक) {
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

    अगर (debug_modes)
        tcc_tcov_check_पंक्ति (tcc_state, 0), tcc_tcov_block_end (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
अटल व्योम skip_or_save_block(TokenString **str)
{
    पूर्णांक braces = tok == '{';
    पूर्णांक level = 0;
    अगर (str)
      *str = tok_str_alloc();

    जबतक (1) {
	पूर्णांक t = tok;
        अगर (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             अवरोध;
	अगर (t == TOK_EOF) {
	     अगर (str || level > 0)
	       tcc_error("unexpected end of file");
	     अन्यथा
	       अवरोध;
	}
	अगर (str)
	  tok_str_add_tok(*str);
	अग्र();
	अगर (t == '{' || t == '(' || t == '[') {
	    level++;
	} अन्यथा अगर (t == '}' || t == ')' || t == ']') {
	    level--;
	    अगर (level == 0 && braces && t == '}')
	      अवरोध;
	}
    }
    अगर (str)
	tok_str_add(*str, TOK_EOF);
}

#घोषणा व्यंजक_CONST 1
#घोषणा व्यंजक_ANY   2

अटल व्योम parse_init_elem(पूर्णांक व्यंजक_type)
{
    पूर्णांक saved_global_व्यंजक;
    चयन(व्यंजक_type) {
    हाल व्यंजक_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_व्यंजक = global_व्यंजक;
        global_व्यंजक = 1;
        व्यंजक_const1();
        global_व्यंजक = saved_global_व्यंजक;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        अगर (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#अगर_घोषित TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#पूर्ण_अगर
           )
            tcc_error("initializer element is not constant");
        अवरोध;
    हाल व्यंजक_ANY:
        व्यंजक_eq();
        अवरोध;
    }
}

#अगर 1
अटल व्योम init_assert(init_params *p, पूर्णांक offset)
{
    अगर (p->sec ? !NODATA_WANTED && offset > p->sec->तथ्य_offset
               : !nocode_wanted && offset > p->local_offset)
        tcc_internal_error("initializer overflow");
}
#अन्यथा
#घोषणा init_assert(sec, offset)
#पूर्ण_अगर

/* put zeros for variable based init */
अटल व्योम init_putz(init_params *p, अचिन्हित दीर्घ c, पूर्णांक आकार)
{
    init_assert(p, c + आकार);
    अगर (p->sec) {
        /* nothing to do because globals are already set to zero */
    } अन्यथा {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(आकार);
#अगर defined TCC_TARGET_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#पूर्ण_अगर
        gfunc_call(3);
    }
}

#घोषणा DIF_FIRST     1
#घोषणा DIF_आकार_ONLY 2
#घोषणा DIF_HAVE_ELEM 4
#घोषणा DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
अटल व्योम decl_design_delrels(Section *sec, पूर्णांक c, पूर्णांक आकार)
{
    ElfW_Rel *rel, *rel2, *rel_end;
    अगर (!sec || !sec->reloc)
        वापस;
    rel = rel2 = (ElfW_Rel*)sec->reloc->तथ्य;
    rel_end = (ElfW_Rel*)(sec->reloc->तथ्य + sec->reloc->तथ्य_offset);
    जबतक (rel < rel_end) {
        अगर (rel->r_offset >= c && rel->r_offset < c + आकार) {
            sec->reloc->तथ्य_offset -= माप *rel;
        } अन्यथा {
            अगर (rel2 != rel)
                स_नकल(rel2, rel, माप *rel);
            ++rel2;
        }
        ++rel;
    }
}

अटल व्योम decl_design_flex(init_params *p, Sym *ref, पूर्णांक सूचकांक)
{
    अगर (ref == p->flex_array_ref) {
        अगर (सूचकांक >= ref->c)
            ref->c = सूचकांक + 1;
    } अन्यथा अगर (ref->c < 0 && सूचकांक >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
अटल पूर्णांक decl_designator(init_params *p, CType *type, अचिन्हित दीर्घ c,
                           Sym **cur_field, पूर्णांक flags, पूर्णांक al)
{
    Sym *s, *f;
    पूर्णांक सूचकांक, सूचकांक_last, align, l, nb_elems, elem_आकार;
    अचिन्हित दीर्घ corig = c;

    elem_आकार = 0;
    nb_elems = 1;

    अगर (flags & DIF_HAVE_ELEM)
        जाओ no_designator;

    अगर (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, अग्र();
        अगर (tok == ':')
            जाओ struct_field;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    जबतक (nb_elems == 1 && (tok == '[' || tok == '.')) {
        अगर (tok == '[') {
            अगर (!(type->t & VT_ARRAY))
                expect("array type");
            अग्र();
            सूचकांक = सूचकांक_last = व्यंजक_const();
            अगर (tok == TOK_DOTS && gnu_ext) {
                अग्र();
                सूचकांक_last = व्यंजक_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, सूचकांक_last);
            अगर (सूचकांक < 0 || सूचकांक_last >= s->c || सूचकांक_last < सूचकांक)
	        tcc_error("index exceeds array bounds or range is empty");
            अगर (cur_field)
		(*cur_field)->c = सूचकांक_last;
            type = pointed_type(type);
            elem_आकार = type_आकार(type, &align);
            c += सूचकांक * elem_आकार;
            nb_elems = सूचकांक_last - सूचकांक + 1;
        } अन्यथा {
            पूर्णांक cumofs;
            अग्र();
            l = tok;
        struct_field:
            अग्र();
	    f = find_field(type, l, &cumofs);
            अगर (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_field = शून्य;
    }
    अगर (!cur_field) {
        अगर (tok == '=') {
            अग्र();
        } अन्यथा अगर (!gnu_ext) {
	    expect("=");
        }
    } अन्यथा {
    no_designator:
        अगर (type->t & VT_ARRAY) {
	    सूचकांक = (*cur_field)->c;
            s = type->ref;
            decl_design_flex(p, s, सूचकांक);
            अगर (सूचकांक >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_आकार = type_आकार(type, &align);
            c += सूचकांक * elem_आकार;
        } अन्यथा {
            f = *cur_field;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    जबतक (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_field = f = f->अग्र;
            अगर (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    अगर (!elem_आकार) /* for structs */
        elem_आकार = type_आकार(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    अगर (!(flags & DIF_आकार_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_आकार * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    अगर (!(flags & DIF_आकार_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        पूर्णांक i;
        अगर (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_आकार;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        अगर (p->sec)
            vpush_ref(type, p->sec, c, elem_आकार);
        अन्यथा
	    vset(type, VT_LOCAL|VT_LVAL, c);
        क्रम (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_आकार * i);
	}
        vpop();
    }

    c += nb_elems * elem_आकार;
    अगर (c - corig > al)
      al = c - corig;
    वापस al;
}

अटल व्योम write_ldouble(अचिन्हित अक्षर *d, व्योम *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#अगर_घोषित TCC_CROSS_TEST
    अगर (LDOUBLE_आकार >= 10) {
        द्विगुन b = *(दीर्घ द्विगुन*)s;
        s = &b;
#अन्यथा
    अगर (माप (दीर्घ द्विगुन) == 8 && LDOUBLE_आकार >= 10) {
#पूर्ण_अगर
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        पूर्णांक e = m >> 48;
        पूर्णांक f = e >> 4 & 0x7FF;
        m <<= 11;
        अगर (0 == f) {
            अगर (0 == m)
                जाओ set;
            क्रम (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        अगर (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    set:
    #अगर (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #या_अगर LDOUBLE_आकार == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #पूर्ण_अगर
        ;
    } अन्यथा {
    #अगर LDOUBLE_आकार == 8
        /* long double -> double */
        द्विगुन b = *(दीर्घ द्विगुन*)s;
        स_नकल(d, &b, 8);
    #या_अगर (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        स_नकल(d, s, 10);
    #या_अगर (__i386__ || __x86_64__) && (defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        पूर्णांक e = *(uint16_t*)((अक्षर*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #या_अगर (__aarch64__ || __riscv) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((अक्षर*)s + 6);
        पूर्णांक e = read16le((अक्षर*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #अन्यथा
        /* unknown */
        अगर (माप (दीर्घ द्विगुन) == LDOUBLE_आकार)
            स_नकल(d, s, LDOUBLE_आकार);
    #पूर्ण_अगर
    }
}

/* store a value or an expression directly in global data or in local array */
अटल व्योम init_putv(init_params *p, CType *type, अचिन्हित दीर्घ c)
{
    पूर्णांक bt;
    व्योम *ptr;
    CType dtype;
    पूर्णांक आकार, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    आकार = type_आकार(type, &align);
    अगर (type->t & VT_BITFIELD)
        आकार = (BIT_POS(type->t) + BIT_आकार(type->t) + 7) / 8;
    init_assert(p, c + आकार);

    अगर (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        अगर ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_आकार == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        अगर (NODATA_WANTED) {
            vtop--;
            वापस;
        }

        ptr = sec->तथ्य + c;
        val = vtop->c.i;

	अगर ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    स_हटाओ (ptr, ssec->तथ्य + esym->st_मूल्य + (पूर्णांक)vtop->c.i, आकार);
	    अगर (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                अचिन्हित दीर्घ relofs = ssec->reloc->तथ्य_offset;
		जबतक (relofs >= माप(*rel)) {
                    relofs -= माप(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->तथ्य + relofs);
		    अगर (rel->r_offset >= esym->st_मूल्य + आकार)
		      जारी;
		    अगर (rel->r_offset < esym->st_मूल्य)
		      अवरोध;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_मूल्य,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#अगर PTR_आकार == 8
				   rel->r_addend
#अन्यथा
				   0
#पूर्ण_अगर
				  );
		}
	    }
	} अन्यथा {
            अगर (type->t & VT_BITFIELD) {
                पूर्णांक bit_pos, bit_आकार, bits, n;
                अचिन्हित अक्षर *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_आकार = BIT_आकार(vtop->type.t);
                p = (अचिन्हित अक्षर*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                जबतक (bit_आकार) {
                    n = 8 - bit_pos;
                    अगर (n > bit_आकार)
                        n = bit_आकार;
                    v = val >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_आकार -= n, bit_pos = 0, ++p;
                }
            } अन्यथा
            चयन(bt) {
	    हाल VT_BOOL:
		*(अक्षर *)ptr = val != 0;
                अवरोध;
	    हाल VT_BYTE:
		*(अक्षर *)ptr = val;
		अवरोध;
	    हाल VT_SHORT:
                write16le(ptr, val);
		अवरोध;
	    हाल VT_FLOAT:
                write32le(ptr, val);
		अवरोध;
	    हाल VT_DOUBLE:
                write64le(ptr, val);
		अवरोध;
	    हाल VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		अवरोध;

#अगर PTR_आकार == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    हाल VT_LLONG:
	    हाल VT_PTR:
	        अगर (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_तथ्य_PTR, val);
	        अन्यथा
	          write64le(ptr, val);
	        अवरोध;
            हाल VT_INT:
                write32le(ptr, val);
                अवरोध;
#अन्यथा
	    हाल VT_LLONG:
                write64le(ptr, val);
                अवरोध;
            हाल VT_PTR:
            हाल VT_INT:
	        अगर (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_तथ्य_PTR);
	        write32le(ptr, val);
	        अवरोध;
#पूर्ण_अगर
	    शेष:
                //tcc_internal_error("unexpected type");
                अवरोध;
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
अटल व्योम decl_initializer(init_params *p, CType *type, अचिन्हित दीर्घ c, पूर्णांक flags)
{
    पूर्णांक len, n, no_oblock, i;
    पूर्णांक size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    अगर (debug_modes && !(flags & DIF_आकार_ONLY) && !p->sec)
        tcc_debug_पंक्ति(tcc_state), tcc_tcov_check_पंक्ति (tcc_state, 1);

    अगर (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_आकार_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        पूर्णांक ncw_पूर्व = nocode_wanted;
        अगर ((flags & DIF_आकार_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? व्यंजक_ANY : व्यंजक_CONST);
        nocode_wanted = ncw_पूर्व;
        flags |= DIF_HAVE_ELEM;
    }

    अगर (type->t & VT_ARRAY) {
        no_oblock = 1;
        अगर (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_आकार(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        अगर ((tok == TOK_LSTR && 
#अगर_घोषित TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#अन्यथा
             (t1->t & VT_BTYPE) == VT_INT
#पूर्ण_अगर
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            अगर (size1 != (tok == TOK_STR ? 1 : माप(nwchar_t)))
              tcc_error("unhandled string literal merging");
            जबतक (tok == TOK_STR || tok == TOK_LSTR) {
                अगर (initstr.आकार)
                  initstr.आकार -= size1;
                अगर (tok == TOK_STR)
                  len += tokc.str.आकार;
                अन्यथा
                  len += tokc.str.आकार / माप(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.तथ्य, tokc.str.आकार);
                अग्र();
            }
            अगर (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.आकार = initstr.आकार;
                tokc.str.तथ्य = initstr.तथ्य;
                जाओ do_init_array;
            }

            decl_design_flex(p, s, len);
            अगर (!(flags & DIF_आकार_ONLY)) {
                पूर्णांक nb = n, ch;
                अगर (len < nb)
                    nb = len;
                अगर (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                अगर (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    अगर (!NODATA_WANTED)
                      स_नकल(p->sec->तथ्य + c, initstr.तथ्य, nb);
                } अन्यथा {
                    क्रम(i=0;i<n;i++) {
                        अगर (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          अगर (flags & DIF_CLEAR)
                            अवरोध;
                          अगर (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            अवरोध;
                          }
                          ch = 0;
                        } अन्यथा अगर (size1 == 1)
                          ch = ((अचिन्हित अक्षर *)initstr.तथ्य)[i];
                        अन्यथा
                          ch = ((nwchar_t *)initstr.तथ्य)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            अगर (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                अग्र();
        } अन्यथा {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            अगर (!(flags & (DIF_CLEAR | DIF_आकार_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    जबतक (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		अगर (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    अगर (no_oblock && len >= n*size1)
		        अवरोध;
		} अन्यथा {
		    अगर (s->type.t == VT_UNION)
		        f = शून्य;
		    अन्यथा
		        f = f->अग्र;
		    अगर (no_oblock && f == शून्य)
		        अवरोध;
		}

		अगर (tok == '}')
		    अवरोध;
		skip(',');
	    }
        }
        अगर (!no_oblock)
            skip('}');

    } अन्यथा अगर ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        जाओ one_elem;

    } अन्यथा अगर ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        अगर ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->अग्र;
        n = s->c;
        size1 = 1;
	जाओ do_init_list;

    } अन्यथा अगर (tok == '{') {
        अगर (flags & DIF_HAVE_ELEM)
          skip(';');
        अग्र();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } अन्यथा one_elem: अगर ((flags & DIF_आकार_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        अगर (flags & DIF_HAVE_ELEM)
            vpop();
        अन्यथा
            skip_or_save_block(शून्य);

    } अन्यथा {
	अगर (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    अगर (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? व्यंजक_ANY : व्यंजक_CONST);
	}
        अगर (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_आकार(type->t & VT_BTYPE) /* not for fp constants */
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
अटल व्योम decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णांक r, 
                                   पूर्णांक has_init, पूर्णांक v, पूर्णांक scope)
{
    पूर्णांक आकार, align, addr;
    TokenString *init_str = शून्य;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = शून्य;
    पूर्णांक saved_nocode_wanted = nocode_wanted;
#अगर_घोषित CONFIG_TCC_BCHECK
    पूर्णांक bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#पूर्ण_अगर
    init_params p = {0};

    अगर (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        अगर (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            अगर (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                वापस;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    अगर (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= तथ्य_ONLY_WANTED;

    flexible_array = शून्य;
    आकार = type_आकार(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    अगर (आकार < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        अगर (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        अगर (IS_BT_ARRAY(type->t))
            type->ref = sym_धकेलो(SYM_FIELD, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } अन्यथा अगर (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->अग्र;
        अगर (field) {
            जबतक (field->अग्र)
                field = field->अग्र;
            अगर (field->type.t & VT_ARRAY && field->type.ref->c < 0) {
                flexible_array = field;
                p.flex_array_ref = field->type.ref;
                आकार = -1;
            }
        }
    }

    अगर (आकार < 0) {
        /* If unknown size, do a dry-run 1st pass */
        अगर (!has_init)
            जाओ err_आकार;
        अगर (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            जबतक (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                अग्र();
            }
            tok_str_add(init_str, TOK_EOF);
        } अन्यथा
            skip_or_save_block(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        अग्र();
        decl_initializer(&p, type, 0, DIF_FIRST | DIF_आकार_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        अग्र();

        /* if still unknown size, error */
        आकार = type_आकार(type, &align);
        अगर (आकार < 0)
    err_आकार:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        अगर (flexible_array && flexible_array->type.ref->c > 0)
            आकार += flexible_array->type.ref->c
                    * pointed_आकार(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    अगर (ad->a.aligned) {
	पूर्णांक speca = 1 << (ad->a.aligned - 1);
        अगर (speca > align)
            align = speca;
    } अन्यथा अगर (ad->a.packed) {
        align = 1;
    }

    अगर (!v && NODATA_WANTED)
        आकार = 0, align = 1;

    अगर ((r & VT_VALMASK) == VT_LOCAL) {
        sec = शून्य;
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#पूर्ण_अगर
        loc = (loc - आकार) & -align;
        addr = loc;
        p.local_offset = addr + आकार;
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#पूर्ण_अगर
        अगर (v) {
            /* local variable */
#अगर_घोषित CONFIG_TCC_ASM
	    अगर (ad->asm_label) {
		पूर्णांक reg = asm_parse_regvar(ad->asm_label);
		अगर (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#पूर्ण_अगर
            sym = sym_धकेलो(v, type, r, addr);
	    अगर (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_FIELD | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->अग्र = cur_scope->cl.s;
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

        जबतक ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        अगर (!sec) {
            अगर (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } अन्यथा अगर (is_const) {
		sec = rodata_section;
            } अन्यथा अगर (has_init) {
		sec = तथ्य_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } अन्यथा अगर (tcc_state->nocommon)
                sec = bss_section;
        } अन्यथा अगर (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            अगर (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                अगर (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (bcheck)
            आकार = आकार + 1; /* add padding */
#पूर्ण_अगर
        अगर (sec) {
	    addr = section_add(sec, आकार, align);
        } अन्यथा {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        अगर (v) {
            अगर (!sym) {
                sym = sym_धकेलो(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, शून्य);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, आकार);
        } अन्यथा {
            /* push global reference */
            vpush_ref(type, sec, addr, आकार);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#अगर_घोषित CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        अगर (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->तथ्य_offset, R_तथ्य_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * माप(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = आकार - 1;
        }
#पूर्ण_अगर
    }

    अगर (type->t & VT_VLA) {
        पूर्णांक a;

        अगर (has_init)
            tcc_error("variable length array cannot be initialized");

        अगर (NODATA_WANTED)
            जाओ no_alloc;

        /* save before-VLA stack pointer if needed */
        अगर (cur_scope->vla.अंक == 0) {
            अगर (cur_scope->पूर्व && cur_scope->पूर्व->vla.अंक) {
                cur_scope->vla.locorig = cur_scope->पूर्व->vla.loc;
            } अन्यथा {
                gen_vla_sp_save(loc -= PTR_आकार);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_आकार(type, &a);
        gen_vla_alloc(type, a);
#अगर defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_परिणाम(addr), addr = (loc -= PTR_आकार);
#पूर्ण_अगर
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.अंक++;
    } अन्यथा अगर (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        अगर (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    अगर (init_str) {
        end_macro();
        अग्र();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
अटल व्योम func_vla_arg_code(Sym *arg)
{
    पूर्णांक align;
    TokenString *vla_array_tok = शून्य;

    अगर (arg->type.ref)
        func_vla_arg_code(arg->type.ref);

    अगर ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_आकार(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	अग्र();
	gexpr();
	end_macro();
	अग्र();
	vpush_type_आकार(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

अटल व्योम func_vla_arg(Sym *sym)
{
    Sym *arg;

    क्रम (arg = sym->type.ref->अग्र; arg; arg = arg->अग्र)
        अगर ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_code(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_set_param(Sym *s, पूर्णांक c, पूर्णांक byref)
{
    s = sym_find(s->v);
    अगर (!s) /* unnamed parameters, not enabled */
        वापस शून्य;
    s->c = c;
    अगर (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    वापस s;
}

/* push parameters (and their types), last first */
अटल व्योम sym_धकेलो_params(Sym *ref)
{
    Sym *s = ref;
    जबतक (s->अग्र)
        s = s->अग्र;
    जबतक (s != ref) {
        अगर ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_ढेर);
        s = s->पूर्व;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
अटल व्योम gen_function(Sym *sym)
{
    काष्ठा scope f = { 0 };

    cur_scope = मूल_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->तथ्य_offset;
    अगर (sym->a.aligned) {
	माप_प्रकार newoff = section_add(cur_text_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, शून्य);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);

    अगर (sym->type.ref->f.func_ctor)
        add_array (tcc_state, ".init_array", sym->c);
    अगर (sym->type.ref->f.func_dtor)
        add_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_ढेर, SYM_FIELD, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_धकेलो_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_अस्थायी_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    block(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_end_scope(शून्य, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_आकार = ind - func_ind;
    cur_text_section->तथ्य_offset = ind;

    sym_निकालो(&local_ढेर, शून्य, 0);
    label_निकालो(&global_label_ढेर, शून्य, 0);
    sym_निकालो(&all_cleanups, शून्य, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_text_section = शून्य;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = तथ्य_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    अग्र();
}

अटल व्योम gen_inline_functions(TCCState *s)
{
    Sym *sym;
    पूर्णांक inline_generated, i;
    काष्ठा InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    करो {
        inline_generated = 0;
        क्रम (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            अगर (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = शून्य;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                अग्र();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } जबतक (inline_generated);
    tcc_close();
}

अटल व्योम free_inline_functions(TCCState *s)
{
    पूर्णांक i;
    /* free tokens of unused inline functions */
    क्रम (i = 0; i < s->nb_inline_fns; ++i) {
        काष्ठा InlineFunc *fn = s->inline_fns[i];
        अगर (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

अटल व्योम do_Static_assert(व्योम)
{
    पूर्णांक c;
    स्थिर अक्षर *संदेश;

    अग्र();
    skip('(');
    c = व्यंजक_const();
    संदेश = "_Static_assert fail";
    अगर (tok == ',') {
        अग्र();
        संदेश = parse_mult_str("string constant")->तथ्य;
    }
    skip(')');
    अगर (c == 0)
        tcc_error("%s", संदेश);
    skip(';');
}

#अगर_घोषित TCC_TARGET_PE
अटल व्योम pe_check_linkage(CType *type, AttributeDef *ad)
{
    अगर (!ad->a.dllimport && !ad->a.dllexport)
        वापस;
    अगर (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    अगर (type->t & VT_TYPEDEF) {
        स्थिर अक्षर *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } अन्यथा अगर (ad->a.dllimport) {
        अगर ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        अन्यथा
            type->t |= VT_EXTERN;
    }
}
#पूर्ण_अगर

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
अटल पूर्णांक decl(पूर्णांक l)
{
    पूर्णांक v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    जबतक (1) {

        oldint = 0;
        अगर (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            अगर (l == VT_JMP)
                वापस 0;
            /* skip redundant ';' if not in old parameter decl scope */
            अगर (tok == ';' && l != VT_CMP) {
                अग्र();
                जारी;
            }
            अगर (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                जारी;
            }
            अगर (l != VT_CONST)
                अवरोध;
            अगर (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                जारी;
            }
            अगर (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } अन्यथा {
                अगर (tok != TOK_EOF)
                    expect("declaration");
                अवरोध;
            }
        }

        अगर (tok == ';') {
            अगर ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            अन्यथा अगर (IS_ENUM(btype.t))
                ; /* enum decl */
            अन्यथा
                tcc_warning("useless type defines no instances");
            अगर (l == VT_JMP)
                वापस 1;
            अग्र();
            जारी;
        }

        जबतक (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_DIRECT | TYPE_PARAM : TYPE_DIRECT);
            /*ptype("decl", &type, v);*/
            अगर ((type.t & VT_BTYPE) == VT_FUNC) {
                अगर ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                अगर (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                अगर ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    अगर (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    अन्यथा
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } अन्यथा अगर (oldint) {
                tcc_warning("type defaults to int");
            }

            अगर (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #अगर 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                अगर (tok == '{')
                    expect(";");
            #पूर्ण_अगर
            }

#अगर_घोषित TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#पूर्ण_अगर
            अगर (tok == '{') {
                अगर (l != VT_CONST)
                    tcc_error("cannot use local functions");
                अगर ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                क्रम (sa = sym->type.ref; (sa = sa->अग्र) != शून्य;) {
                    अगर (!(sa->v & ~SYM_FIELD))
                        expect("identifier");
                    अगर (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                अगर (sym->type.t & VT_INLINE) {
                    काष्ठा InlineFunc *fn;
                    fn = tcc_malloc(माप *fn + म_माप(file->filename));
                    म_नकल(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_block(&fn->func_str);
                } अन्यथा {
                    /* compute text section */
                    cur_text_section = text_section;
                    अगर (ad.section) {
                        cur_text_section = ad.section;
                        अगर (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                अवरोध;
            } अन्यथा {
                has_init = 0;
		अगर (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    क्रम (sym = func_vt.ref->अग्र; sym; sym = sym->अग्र)
			अगर ((sym->v & ~SYM_FIELD) == v)
			    जाओ found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, शून्य));
                found:
		    अगर (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, शून्य));
		    अगर (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, शून्य));
		    convert_parameter_type(&type);
		    sym->type = type;
		} अन्यथा अगर (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    अगर (sym && sym->sym_scope == local_scope) {
                        अगर (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, शून्य));
                        sym->type = type;
                    } अन्यथा {
                        sym = sym_धकेलो(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    अगर ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    अगर (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} अन्यथा अगर ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } अन्यथा {
                    r = 0;
                    अगर ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } अन्यथा अगर (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    अगर (tok == '=')
                        has_init = 1;

                    अगर (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
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
                        अगर (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        अन्यथा
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        अगर (has_init)
                            अग्र();
                        अन्यथा अगर (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    अगर (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        अगर (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_मूल्य, esym->st_आकार, 1);
                    }
                }
                अगर (tok != ',') {
                    अगर (l == VT_JMP)
                        वापस has_init ? v : 1;
                    skip(';');
                    अवरोध;
                }
                अग्र();
            }
        }
    }
    वापस 0;
}

/* ------------------------------------------------------------------------- */
#अघोषित gjmp_addr
#अघोषित gjmp
/* ------------------------------------------------------------------------- */
