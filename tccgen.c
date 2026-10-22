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

#परिभाषय USING_GLOBALS
#अन्तर्भाव "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_दत्त पूर्णाङ्क rsym, anon_sym, ind, loc;

ST_दत्त Sym *global_राशिः;
ST_दत्त Sym *local_राशिः;
ST_दत्त Sym *define_राशिः;
ST_दत्त Sym *global_label_राशिः;
ST_दत्त Sym *local_label_राशिः;

स्थिर Sym *sym_free_first;
स्थिर शून्य **sym_pools;
स्थिर पूर्णाङ्क nb_sym_pools;

स्थिर Sym *all_cleanups, *pending_gotos;
स्थिर पूर्णाङ्क local_scope;
ST_दत्त वर्ण debug_modes;

ST_दत्त SValue *vtop;
स्थिर SValue _vstack[1 + VSTACK_आकार];
#परिभाषय vstack (_vstack + 1)

ST_दत्त पूर्णाङ्क nocode_wanted; /* no code generation wanted */
#परिभाषय NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#परिभाषय दत्त_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#परिभाषय संहिता_OFF_BIT 0x20000000
#परिभाषय संहिता_OFF() यदि(!nocode_wanted)(nocode_wanted |= संहिता_OFF_BIT)
#परिभाषय संहिता_ON() (nocode_wanted &= ~संहिता_OFF_BIT)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#परिभाषय NOEVAL_आवरणम् 0x0000FFFF
#परिभाषय NOEVAL_WANTED (nocode_wanted & NOEVAL_आवरणम्)

/* no code output when parsing constant expressions */
#परिभाषय CONST_WANTED_BIT  0x00010000
#परिभाषय CONST_WANTED_आवरणम् 0x0FFF0000
#परिभाषय CONST_WANTED  (nocode_wanted & CONST_WANTED_आवरणम्)

ST_दत्त पूर्णाङ्क global_व्यञ्जकम्;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_दत्त CType func_vt; /* current function return type (used by return instruction) */
ST_दत्त पूर्णाङ्क func_var; /* true if current function is variadic (used by return instruction) */
ST_दत्त पूर्णाङ्क func_vc; /* stack address for implicit struct return storage */
ST_दत्त पूर्णाङ्क func_ind; /* function start address */
स्थिर पूर्णाङ्क func_old;
ST_दत्त ध्रुव वर्ण *funcname;
ST_दत्त CType int_type, func_old_type, char_type, char_pointer_type;
स्थिर CString initstr;

#यदि PTR_आकार == 4
#परिभाषय VT_आकार_T (VT_INT | VT_UNSIGNED)
#परिभाषय VT_PTRDIFF_T VT_INT
#नोचेद्यदि LONG_आकार == 4
#परिभाषय VT_आकार_T (VT_LLONG | VT_UNSIGNED)
#परिभाषय VT_PTRDIFF_T VT_LLONG
#अन्यथा
#परिभाषय VT_आकार_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#परिभाषय VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#यदि_अन्तः

स्थिर संरचना switch_t {
    संरचना case_t {
        int64_t v1, v2;
        पूर्णाङ्क ind, पङ्क्तिः;
    } **p; पूर्णाङ्क n; /* list of case ranges */
    पूर्णाङ्क def_sym; /* default symbol */
    पूर्णाङ्क nocode_wanted;
    पूर्णाङ्क *bsym;
    संरचना scope *scope;
    संरचना switch_t *पूर्व;
    SValue sv;
} *cur_switch; /* current switch */

#परिभाषय MAX_अस्थायी_LOCAL_VARIABLE_सङ्ख्या 8
/*list of temporary local variables on the stack in current function. */
स्थिर संरचना अस्थायी_local_variable {
	पूर्णाङ्क location; //offset on stack. Svalue.c.i
	ह्रस्व आकार;
	ह्रस्व align;
} arr_अस्थायी_local_vars[MAX_अस्थायी_LOCAL_VARIABLE_सङ्ख्या];
स्थिर पूर्णाङ्क nb_अस्थायी_local_vars;

स्थिर संरचना scope {
    संरचना scope *पूर्व;
    संरचना { पूर्णाङ्क loc, locorig, अङ्कः; } vla;
    संरचना { Sym *s; पूर्णाङ्क n; } cl;
    पूर्णाङ्क *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *मूलम्_scope;

प्रकारनिर्देश संरचना {
    Section *sec;
    पूर्णाङ्क local_विस्थापनम्;
    Sym *flex_array_ref;
} init_params;

#यदि 1
#परिभाषय precedence_parser
स्थिर शून्य init_prec(शून्य);
#यदि_अन्तः

स्थिर शून्य खण्डम्(पूर्णाङ्क flags);
#परिभाषय STMT_व्यञ्जकम् 1
#परिभाषय STMT_COMPOUND 2

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
स्थिर शून्य init_putv(init_params *p, CType *type, अचिह्नित दीर्घ c);
स्थिर शून्य decl_initializer(init_params *p, CType *type, अचिह्नित दीर्घ c, पूर्णाङ्क flags);
स्थिर शून्य decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णाङ्क r, पूर्णाङ्क has_init, पूर्णाङ्क v, पूर्णाङ्क scope);
स्थिर पूर्णाङ्क decl(पूर्णाङ्क l);
स्थिर शून्य व्यञ्जकम्_eq(शून्य);
स्थिर शून्य vpush_type_आकार(CType *type, पूर्णाङ्क *a);
स्थिर पूर्णाङ्क is_compatible_unqualified_types(CType *type1, CType *type2);
स्थिर अन्तःस्थ int64_t व्यञ्जकम्_const64(शून्य);
स्थिर शून्य vpush64(पूर्णाङ्क ty, अचिह्नित दीर्घ दीर्घ v);
स्थिर शून्य vpush(CType *type);
स्थिर पूर्णाङ्क gvtst(पूर्णाङ्क inv, पूर्णाङ्क t);
स्थिर शून्य gen_inline_functions(TCCState *s);
स्थिर शून्य free_inline_functions(TCCState *s);
स्थिर शून्य skip_or_save_खण्डम्(TokenString **str);
स्थिर शून्य gv_dup(शून्य);
स्थिर पूर्णाङ्क get_अस्थायी_local_var(पूर्णाङ्क आकार,पूर्णाङ्क align,पूर्णाङ्क *r2);
स्थिर शून्य cast_error(CType *st, CType *dt);
स्थिर शून्य अन्तः_switch(शून्य);
स्थिर शून्य do_Static_assert(शून्य);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC शून्य gsym(पूर्णाङ्क t)
{
  यदि (t) {
    gsym_addr(t, ind);
    संहिता_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
स्थिर पूर्णाङ्क gind()
{
  पूर्णाङ्क t = ind;
  संहिता_ON();
  यदि (debug_modes)
    tcc_tcov_खण्डम्_begin(tcc_state);
  प्रत्यागम t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
स्थिर शून्य gjmp_addr_acs(पूर्णाङ्क t)
{
  gjmp_addr(t);
  संहिता_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
स्थिर पूर्णाङ्क gjmp_acs(पूर्णाङ्क t)
{
  t = gjmp(t);
  संहिता_OFF();
  प्रत्यागम t;
}

/* These are #undef'd at the end of this file */
#परिभाषय gjmp_addr gjmp_addr_acs
#परिभाषय gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN पूर्णाङ्क is_float(पूर्णाङ्क t)
{
    पूर्णाङ्क bt = t & VT_BTYPE;
    प्रत्यागम bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

स्थिर अन्तःस्थ पूर्णाङ्क is_integer_btype(पूर्णाङ्क bt)
{
    प्रत्यागम bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

स्थिर पूर्णाङ्क btype_आकार(पूर्णाङ्क bt)
{
    प्रत्यागम bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_आकार : 0;
}

/* returns function return register from type */
स्थिर पूर्णाङ्क R_RET(पूर्णाङ्क t)
{
    यदि (!is_float(t))
        प्रत्यागम REG_IRET;
#यदि_परिभाषितम् TCC_TARGET_X86_64
    यदि ((t & VT_BTYPE) == VT_LDOUBLE)
        प्रत्यागम TREG_ST0;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    यदि ((t & VT_BTYPE) == VT_LDOUBLE)
        प्रत्यागम REG_IRET;
#यदि_अन्तः
    प्रत्यागम REG_FRET;
}

/* returns 2nd function return register, if any */
स्थिर पूर्णाङ्क R2_RET(पूर्णाङ्क t)
{
    t &= VT_BTYPE;
#यदि PTR_आकार == 4
    यदि (t == VT_LLONG)
        प्रत्यागम REG_IRE2;
#नोचेद्यदि defined TCC_TARGET_X86_64
    यदि (t == VT_QLONG)
        प्रत्यागम REG_IRE2;
    यदि (t == VT_QFLOAT)
        प्रत्यागम REG_FRE2;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    यदि (t == VT_LDOUBLE)
        प्रत्यागम REG_IRE2;
#यदि_अन्तः
    प्रत्यागम VT_CONST;
}

/* returns true for two-word types */
#परिभाषय USING_TWO_शब्दाः(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
स्थिर शून्य PUT_R_RET(SValue *sv, पूर्णाङ्क t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
स्थिर पूर्णाङ्क RC_RET(पूर्णाङ्क t)
{
    प्रत्यागम reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
स्थिर पूर्णाङ्क RC_TYPE(पूर्णाङ्क t)
{
    यदि (!is_float(t))
        प्रत्यागम RC_INT;
#यदि_परिभाषितम् TCC_TARGET_X86_64
    यदि ((t & VT_BTYPE) == VT_LDOUBLE)
        प्रत्यागम RC_ST0;
    यदि ((t & VT_BTYPE) == VT_QFLOAT)
        प्रत्यागम RC_FRET;
#नोचेद्यदि defined TCC_TARGET_RISCV64
    यदि ((t & VT_BTYPE) == VT_LDOUBLE)
        प्रत्यागम RC_INT;
#यदि_अन्तः
    प्रत्यागम RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
स्थिर पूर्णाङ्क RC2_TYPE(पूर्णाङ्क t, पूर्णाङ्क rc)
{
    यदि (!USING_TWO_शब्दाः(t))
        प्रत्यागम 0;
#यदि_परिभाषितम् RC_IRE2
    यदि (rc == RC_IRET)
        प्रत्यागम RC_IRE2;
#यदि_अन्तः
#यदि_परिभाषितम् RC_FRE2
    यदि (rc == RC_FRET)
        प्रत्यागम RC_FRE2;
#यदि_अन्तः
    यदि (rc & RC_FLOAT)
        प्रत्यागम RC_FLOAT;
    प्रत्यागम RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC पूर्णाङ्क ieee_finite(द्विगुण d)
{
    पूर्णाङ्क p[4];
    स्मृतिं_प्रतिलिख(p, &d, परिमाण(द्विगुण));
    प्रत्यागम ((अचिह्नित)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC शून्य test_lvalue(शून्य)
{
    यदि (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC शून्य check_vstack(शून्य)
{
    यदि (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (पूर्णाङ्क)(vtop - vstack + 1));
}

#यदि 0
/* dump 'b' vstack entries starting with 'a'  */
शून्य pv (ध्रुव वर्ण *lbl, पूर्णाङ्क a, पूर्णाङ्क b)
{
    पूर्णाङ्क i;
    प्रति (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        प्रारूप_लिख("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (पूर्णाङ्क)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
स्थिर अन्तःस्थ शून्य psyms(ध्रुव वर्ण *सन्देशः, Sym *s, Sym *चरमः)
{
    प्रारूप_लिख("%-8s scope         v        c        r   type.t\n", सन्देशः);
    यावत् (s && s != चरमः) {
        प्रारूप_लिख("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->पूर्व;
    }
}

स्थिर शून्य type_गन्तव्यम्_str(वर्ण *buf, पूर्णाङ्क buf_आकार, CType *type, ध्रुव वर्ण *varstr);

/* print type */
स्थिर शून्य ptype(ध्रुव वर्ण *सन्देशः, CType *type, पूर्णाङ्क v)
{
    वर्ण buf[500];
    type_गन्तव्यम्_str(buf, परिमाण(buf), type,
        (v & ~SYM_क्षेत्रम्) ? get_tok_str(v, रिक्त) : रिक्त);
    प्रारूप_लिख("%s : %s;\n", सन्देशः, buf);
}
#यदि_अन्तः

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC शून्य tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    स्मृतिं_पूरय(vtop, 0, परिमाण *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    यदि (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_pointer_type = char_type;
    mk_pointer(&char_pointer_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_प्रक्षिप(SYM_क्षेत्रम्, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#यदि_परिभाषितम् precedence_parser
    init_prec();
#यदि_अन्तः
    cstr_new(&initstr);
}

ST_FUNC पूर्णाङ्क tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_FIRST_ANOM;
    nocode_wanted = दत्त_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_व्यञ्जकम् = 0;

    tcc_debug_start(s1);
    tcc_tcov_start (s1);
#यदि_परिभाषितम् TCC_TARGET_ARM
    arm_init(s1);
#यदि_अन्तः
#यदि_परिभाषितम् INC_DEBUG
    प्रारूप_लिख("%s: **** new file\n", file->filename);
#यदि_अन्तः
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_अङ्कः | PARSE_FLAG_TOK_STR;
    अग्र();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#यदि TCC_EH_FRAME
    tcc_eh_frame_अन्तः(s1);
#यदि_अन्तः
    tcc_debug_अन्तः(s1);
    tcc_tcov_अन्तः(s1);
    प्रत्यागम 0;
}

ST_FUNC शून्य tccgen_finish(TCCState *s1)
{
    tcc_debug_अन्तः(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_निष्कासय(&global_राशिः, रिक्त, 0);
    sym_निष्कासय(&local_राशिः, रिक्त, 0);
    /* free preprocessor macros */
    free_परिभाषते(रिक्त);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_दत्त, &nb_stk_दत्त);
    यावत् (cur_switch)
        अन्तः_switch();
    local_scope = 0;
    loop_scope = रिक्त;
    all_cleanups = रिक्त;
    pending_gotos = रिक्त;
    nb_अस्थायी_local_vars = 0;
    global_label_राशिः = रिक्त;
    local_label_राशिः = रिक्त;
    cur_text_section = रिक्त;
    sym_free_first = रिक्त;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  यदि (!s || !s->c)
    प्रत्यागम रिक्त;
  प्रत्यागम &((ElfSym *)symtab_section->दत्त)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC शून्य update_storage(Sym *sym)
{
    ElfSym *esym;
    पूर्णाङ्क sym_bind, old_sym_bind;

    esym = elfsym(sym);
    यदि (!esym)
        प्रत्यागम;

    यदि (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    यदि (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    अन्यथा यदि (sym->a.weak)
        sym_bind = STB_WEAK;
    अन्यथा
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    यदि (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#यदि_परिभाषितम् TCC_TARGET_PE
    यदि (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    यदि (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#यदि_अन्तः

#यदि 0
    प्रारूप_लिख("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, रिक्त),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#यदि_अन्तः
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC शून्य put_extern_sym2(Sym *sym, पूर्णाङ्क sh_अङ्कः,
                            addr_t मानम्, अचिह्नित दीर्घ आकार,
                            पूर्णाङ्क can_सङ्कलय_underscore)
{
    पूर्णाङ्क sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    ध्रुव वर्ण *name;
    वर्ण buf1[256];

    यदि (!sym->c) {
        name = get_tok_str(sym->v, रिक्त);
        t = sym->type.t;
        यदि ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } अन्यथा यदि ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            यदि (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } अन्यथा यदि (t & VT_TLS) {
            sym_type = STT_TLS;
        } अन्यथा {
            sym_type = STT_OBJECT;
        }
        यदि (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        अन्यथा
            sym_bind = STB_GLOBAL;
        other = 0;

#यदि_परिभाषितम् TCC_TARGET_PE
        यदि (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            यदि (ref->a.nodecorate) {
                can_सङ्कलय_underscore = 0;
            }
            यदि (ref->f.func_call == FUNC_STDCALL && can_सङ्कलय_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_तर्काः * PTR_आकार);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_सङ्कलय_underscore = 0;
            }
        }
#यदि_अन्तः

        यदि (sym->asm_label) {
            name = get_tok_str(sym->asm_label, रिक्त);
            can_सङ्कलय_underscore = 0;
        }

        यदि (tcc_state->leading_underscore && can_सङ्कलय_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, परिमाण(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, मानम्, आकार, info, other, sh_अङ्कः, name);

        यदि (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_अङ्कः, sym_bind, sym_type);

    } अन्यथा {
        esym = elfsym(sym);
        esym->st_मानम् = मानम्;
        esym->st_आकार = आकार;
        esym->st_shndx = sh_अङ्कः;
    }
    update_storage(sym);
}

ST_FUNC शून्य put_extern_sym(Sym *sym, Section *s, addr_t मानम्, अचिह्नित दीर्घ आकार)
{
    यदि (nocode_wanted && (NODATA_WANTED || (s && s == cur_text_section)))
        प्रत्यागम;
    put_extern_sym2(sym, s ? s->sh_अङ्कः : SHN_UNDEF, मानम्, आकार, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC शून्य greloca(Section *s, Sym *sym, अचिह्नित दीर्घ विस्थापनम्, पूर्णाङ्क type,
                     addr_t addend)
{
    पूर्णाङ्क c = 0;

    यदि (nocode_wanted && s == cur_text_section)
        प्रत्यागम;

    यदि (sym) {
        यदि (0 == sym->c) {
            put_extern_sym(sym, रिक्त, 0, 0);
            यदि (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                यावत् (s->पूर्व_tok)
                    s = s->पूर्व_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, विस्थापनम्, type, c, addend);
}

#यदि PTR_आकार == 4
ST_FUNC शून्य greloc(Section *s, Sym *sym, अचिह्नित दीर्घ विस्थापनम्, पूर्णाङ्क type)
{
    greloca(s, sym, विस्थापनम्, type, 0);
}
#यदि_अन्तः

/* ------------------------------------------------------------------------- */
/* symbol allocator */
स्थिर Sym *__sym_malloc(शून्य)
{
    Sym *sym_pool, *sym, *चरमः_sym;
    पूर्णाङ्क i;

    sym_pool = tcc_malloc(SYM_POOL_NB * परिमाण(Sym));
    dynarray_सङ्कलय(&sym_pools, &nb_sym_pools, sym_pool);

    चरमः_sym = sym_free_first;
    sym = sym_pool;
    प्रति(i = 0; i < SYM_POOL_NB; i++) {
        sym->अग्र = चरमः_sym;
        चरमः_sym = sym;
        sym++;
    }
    sym_free_first = चरमः_sym;
    प्रत्यागम चरमः_sym;
}

स्थिर अन्तःस्थ Sym *sym_malloc(शून्य)
{
    Sym *sym;
#यदि_अपरिभाषितम् SYM_DEBUG
    sym = sym_free_first;
    यदि (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->अग्र;
    प्रत्यागम sym;
#अन्यथा
    sym = tcc_malloc(परिमाण(Sym));
    प्रत्यागम sym;
#यदि_अन्तः
}

ST_INLN शून्य sym_free(Sym *sym)
{
#यदि_अपरिभाषितम् SYM_DEBUG
    sym->अग्र = sym_free_first;
    sym_free_first = sym;
#अन्यथा
    tcc_free(sym);
#यदि_अन्तः
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, पूर्णाङ्क v, पूर्णाङ्क t, पूर्णाङ्क c)
{
    Sym *s;

    s = sym_malloc();
    स्मृतिं_पूरय(s, 0, परिमाण *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->पूर्व = *ps;
    *ps = s;
    प्रत्यागम s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, पूर्णाङ्क v)
{
    यावत् (s) {
        यदि (s->v == v)
            प्रत्यागम s;
        s = s->पूर्व;
    }
    प्रत्यागम रिक्त;
}

/* structure lookup */
ST_INLN Sym *struct_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    यदि ((अचिह्नित)v >= (अचिह्नित)(tok_ident - TOK_IDENT))
        प्रत्यागम रिक्त;
    प्रत्यागम सारणी_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    यदि ((अचिह्नित)v >= (अचिह्नित)(tok_ident - TOK_IDENT))
        प्रत्यागम रिक्त;
    प्रत्यागम सारणी_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
स्थिर अन्तःस्थ शून्य sym_link(Sym *s, पूर्णाङ्क yes)
{
    TokenSym *ts = सारणी_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    यदि (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    अन्यथा
        ps = &ts->sym_identifier;
    यदि (yes) {
        s->पूर्व_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } अन्यथा {
        *ps = s->पूर्व_tok;
    }
}

स्थिर अन्तःस्थ पूर्णाङ्क sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    प्रत्यागम IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_प्रक्षिप(पूर्णाङ्क v, CType *type, पूर्णाङ्क r, पूर्णाङ्क c)
{
    Sym *s, **ps;
    यदि (local_राशिः)
        ps = &local_राशिः;
    अन्यथा
        ps = &global_राशिः;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    यदि ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        यदि (s->पूर्व_tok && sym_scope_ex(s->पूर्व_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, रिक्त));
    }
    प्रत्यागम s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_प्रक्षिप(पूर्णाङ्क v, पूर्णाङ्क t, पूर्णाङ्क c)
{
    Sym *s, **ps;
    s = sym_push2(&global_राशिः, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    यदि (v < SYM_FIRST_ANOM) {
        ps = &सारणी_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        यावत् (*ps != रिक्त && (*ps)->sym_scope)
            ps = &(*ps)->पूर्व_tok;
        s->पूर्व_tok = *ps;
        *ps = s;
    }
    प्रत्यागम s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC शून्य sym_निष्कासय(Sym **ptop, Sym *b, पूर्णाङ्क keep)
{
    Sym *s, *ss;
    पूर्णाङ्क v;

    s = *ptop;
    यावत्(s != b) {
        ss = s->पूर्व;
        v = s->v;
        /* remove symbol in token array */
        यदि ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_link(s, 0);
	यदि (!keep)
	    sym_free(s);
        s = ss;
    }
    यदि (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    यदि ((अचिह्नित)v >= (अचिह्नित)(tok_ident - TOK_IDENT))
        प्रत्यागम रिक्त;
    प्रत्यागम सारणी_ident[v]->sym_label;
}

ST_FUNC Sym *label_प्रक्षिप(Sym **ptop, पूर्णाङ्क v, पूर्णाङ्क flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &सारणी_ident[v - TOK_IDENT]->sym_label;
    यदि (ptop == &global_label_राशिः) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        यावत् (*ps != रिक्त)
            ps = &(*ps)->पूर्व_tok;
    }
    s->पूर्व_tok = *ps;
    *ps = s;
    प्रत्यागम s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC शून्य label_निष्कासय(Sym **ptop, Sym *slast, पूर्णाङ्क keep)
{
    Sym *s, *s1;
    प्रति(s = *ptop; s != slast; s = s1) {
        s1 = s->पूर्व;
        यदि (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, रिक्त));
        } अन्यथा यदि (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, रिक्त));
        } अन्यथा {
            यदि (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_text_section, s->jind, 1);
            }
        }
        /* remove label */
        यदि (s->r != LABEL_GONE)
            सारणी_ident[s->v - TOK_IDENT]->sym_label = s->पूर्व_tok;
        यदि (!keep)
            sym_free(s);
        अन्यथा
            s->r = LABEL_GONE;
    }
    यदि (!keep)
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

    यदि (vtop->r == VT_CMP && 0 == (nocode_wanted & ~संहिता_OFF_BIT))
        gv(RC_INT);
}

स्थिर शून्य vsetc(CType *type, पूर्णाङ्क r, CValue *vc)
{
    यदि (vtop >= vstack + (VSTACK_आकार - 1))
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
#यदि defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    /* for x86, we need to pop the FP stack */
    यदि (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } अन्यथा
#यदि_अन्तः
    यदि (v == VT_CMP) {
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
स्थिर शून्य vpush64(पूर्णाङ्क ty, अचिह्नित दीर्घ दीर्घ v)
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
    vpush64(VT_आकार_T, v);
}

/* push long long constant */
स्थिर अन्तःस्थ शून्य vpushll(दीर्घ दीर्घ v)
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
    यदि (vtop >= vstack + (VSTACK_आकार - 1))
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
    यदि (--n < 1)
        प्रत्यागम;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, परिमाण *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC शून्य vrott(पूर्णाङ्क n)
{
    SValue tmp;
    यदि (--n < 1)
        प्रत्यागम;
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
    प्रति (i = 0, n = -n; i > ++n; --i)
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

    यदि (vtop->jtrue || vtop->jfalse) {
        पूर्णाङ्क origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        पूर्णाङ्क inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } अन्यथा {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        यदि (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
स्थिर शून्य gvtst_समुच्चयः(पूर्णाङ्क inv, पूर्णाङ्क t)
{
    पूर्णाङ्क *p;

    यदि (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        यदि (vtop->r != VT_CMP) /* must be VT_CONST then */
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

    gvtst_समुच्चयः(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    यदि (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    यदि (op > 1)
        t = gjmp_cond(op ^ inv, t);
    अन्यथा यदि (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    प्रत्यागम t;
}

/* generate a zero or nozero test */
स्थिर शून्य gen_test_zero(पूर्णाङ्क op)
{
    यदि (vtop->r == VT_CMP) {
        पूर्णाङ्क j;
        यदि (op == TOK_EQ) {
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
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, अचिह्नित दीर्घ विस्थापनम्, अचिह्नित दीर्घ आकार)
{
    पूर्णाङ्क v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_प्रक्षिप(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, विस्थापनम्, आकार);
    प्रत्यागम sym;
}

/* push a reference to a section offset by adding a dummy symbol */
स्थिर शून्य vpush_ref(CType *type, Section *sec, अचिह्नित दीर्घ विस्थापनम्, अचिह्नित दीर्घ आकार)
{
    vpushsym(type, get_sym_ref(type, sec, विस्थापनम्, आकार));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(पूर्णाङ्क v, CType *type)
{
    Sym *s;

    s = sym_find(v);
    यदि (!s) {
        /* push forward reference */
        s = global_identifier_प्रक्षिप(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } अन्यथा यदि (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    प्रत्यागम s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(पूर्णाङ्क v)
{
    CType ct = { VT_ASM_FUNC, रिक्त };
    प्रत्यागम external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC शून्य vpush_helper_func(पूर्णाङ्क v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
स्थिर शून्य merge_symattr(संरचना SymAttr *sa, संरचना SymAttr *sa1)
{
    यदि (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    यदि (sa1->visibility != STV_DEFAULT) {
	पूर्णाङ्क vis = sa->visibility;
	यदि (vis == STV_DEFAULT
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
    यदि (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    यदि (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    यदि (fa1->func_तर्काः && !fa->func_तर्काः)
      fa->func_तर्काः = fa1->func_तर्काः;
    यदि (fa1->func_noreturn)
      fa->func_noreturn = 1;
    यदि (fa1->func_ctor)
      fa->func_ctor = 1;
    यदि (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
स्थिर शून्य merge_attr(AttributeDef *ad, AttributeDef *ad1)
{
    merge_symattr(&ad->a, &ad1->a);
    merge_funcattr(&ad->f, &ad1->f);

    यदि (ad1->section)
      ad->section = ad1->section;
    यदि (ad1->alias_target)
      ad->alias_target = ad1->alias_target;
    यदि (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    यदि (ad1->attr_बहुलकम्)
      ad->attr_बहुलकम् = ad1->attr_बहुलकम्;
}

/* Merge some type attributes.  */
स्थिर शून्य patch_type(Sym *sym, CType *type)
{
    यदि (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        यदि (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, रिक्त));
        sym->type.t &= ~VT_EXTERN;
    }

    यदि (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        यदि ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    यदि (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, रिक्त));

    } अन्यथा यदि ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        पूर्णाङ्क static_proto = sym->type.t & VT_STATIC;
        पूर्णाङ्क ft1 = sym->type.ref->f.func_type;
        पूर्णाङ्क ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        यदि ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, रिक्त));

        /* set 'inline' if both agree or if one has static */
        यदि ((type->t | sym->type.t) & VT_INLINE) {
            यदि (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        यदि (0 == (type->t & VT_EXTERN)) {
            संरचना FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            यदि (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            merge_funcattr(&sym->type.ref->f, &f);
        } अन्यथा {
            sym->type.t &= ~VT_INLINE | static_proto;
            यदि (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } अन्यथा {
        यदि ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        यदि ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, रिक्त));
    }
}

/* Merge some storage attributes.  */
स्थिर शून्य patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    यदि (type)
        patch_type(sym, type);

#यदि_परिभाषितम् TCC_TARGET_PE
    यदि (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, रिक्त));
#यदि_अन्तः
    merge_symattr(&sym->a, &ad->a);
    यदि (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
स्थिर Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->पूर्व = *ps, *ps = s;
    यदि ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
        sym_link(s, 1);
    प्रत्यागम s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
स्थिर शून्य move_ref_गन्तव्यम्_global(Sym *s)
{
    Sym *l, **lp;
    पूर्णाङ्क n, bt;

    bt = s->type.t & VT_BTYPE;
    यदि (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        प्रत्यागम;

    प्रति (s = s->type.ref, n = 0; s; s = s->अग्र) {
        प्रति (lp = &local_राशिः; !!(l = *lp); lp = &l->पूर्व) {
            यदि (l == s) {
                *lp = s->पूर्व;
                s->पूर्व = global_राशिः, global_राशिः = s;
                यदि (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_गन्तव्यम्_global(s);
                } अन्यथा {
                    यदि ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_क्षेत्रम्;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_क्षेत्रम्;
                    }
                }
                यदि (bt != VT_PTR)
                    n = 1;
                भङ्ग;
            }
        }
        यदि (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            भङ्ग;
    }
}

/* define a new external reference to a symbol 'v' */
स्थिर Sym *external_sym(पूर्णाङ्क v, CType *type, पूर्णाङ्क r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_find(v);
    यावत् (s && s->sym_scope)
        s = s->पूर्व_tok;

    यदि (!s) {
        /* push forward reference */
        s = global_identifier_प्रक्षिप(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } अन्यथा {
        patch_storage(s, ad, type);
    }
    यदि (local_राशिः) {
        /* make sure that type->ref is on global stack */
        move_ref_गन्तव्यम्_global(s);
        /* put into local scope */
        sym_copy(s, &local_राशिः);
    }
    प्रत्यागम s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC शून्य save_regs(पूर्णाङ्क n)
{
    SValue *p, *p1;
    प्रति(p = vstack, p1 = vtop - n; p <= p1; p++)
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
    पूर्णाङ्क l, आकार, align, bt, r2;
    SValue *p, *p1, sv;

    यदि ((r &= VT_VALMASK) >= VT_CONST)
        प्रत्यागम;
    यदि (nocode_wanted)
        प्रत्यागम;
    l = r2 = 0;
    प्रति(p = vstack, p1 = vtop - n; p <= p1; p++) {
        यदि ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            यदि (!l) {
                bt = p->type.t & VT_BTYPE;
                यदि (bt == VT_VOID)
                    अनुवर्त;
                यदि ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                आकार = type_आकार(&sv.type, &align);
                l = get_अस्थायी_local_var(आकार, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = रिक्त;
                store(p->r & VT_VALMASK, &sv);
#यदि defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                यदि (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#यदि_अन्तः
                /* special long long case */
                यदि (p->r2 < VT_CONST && USING_TWO_शब्दाः(bt)) {
                    sv.c.i += PTR_आकार;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            यदि (p->r & VT_LVAL) {
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

#यदि_परिभाषितम् TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC पूर्णाङ्क get_reg_ex(पूर्णाङ्क rc, पूर्णाङ्क rc2)
{
    पूर्णाङ्क r;
    SValue *p;
    
    प्रति(r=0;r<NB_REGS;r++) {
        यदि (reg_classes[r] & rc2) {
            पूर्णाङ्क n;
            n=0;
            प्रति(p = vstack; p <= vtop; p++) {
                यदि ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            यदि (n <= 1)
                प्रत्यागम r;
        }
    }
    प्रत्यागम get_reg(rc);
}
#यदि_अन्तः

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC पूर्णाङ्क get_reg(पूर्णाङ्क rc)
{
    पूर्णाङ्क r;
    SValue *p;

    /* find a free register */
    प्रति(r=0;r<NB_REGS;r++) {
        यदि (reg_classes[r] & rc) {
            यदि (nocode_wanted)
                प्रत्यागम r;
            प्रति(p=vstack;p<=vtop;p++) {
                यदि ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    गच्छ notfound;
            }
            प्रत्यागम r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    प्रति(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        यदि (r < VT_CONST && (reg_classes[r] & rc))
            गच्छ save_प्राप्तम्;
        r = p->r & VT_VALMASK;
        यदि (r < VT_CONST && (reg_classes[r] & rc)) {
        save_प्राप्तम्:
            save_reg(r);
            प्रत्यागम r;
        }
    }
    /* Should never comes here */
    प्रत्यागम -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
स्थिर पूर्णाङ्क get_अस्थायी_local_var(पूर्णाङ्क आकार,पूर्णाङ्क align, पूर्णाङ्क *r2)
{
    पूर्णाङ्क i;
    संरचना अस्थायी_local_variable *अस्थायी_var;
    SValue *p;
    पूर्णाङ्क r;
    अचिह्नित प्रयुक्तम् = 0;

    /* mark locations that are still in use */
    प्रति (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	यदि (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    यदि (r >= 0 && r < MAX_अस्थायी_LOCAL_VARIABLE_सङ्ख्या)
	        प्रयुक्तम् |= 1<<r;
	}
    }
    प्रति (i=0;i<nb_अस्थायी_local_vars;i++) {
	अस्थायी_var=&arr_अस्थायी_local_vars[i];
	यदि(!(प्रयुक्तम् & 1<<i)
	 && अस्थायी_var->आकार>=आकार
	 && अस्थायी_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    प्रत्यागम अस्थायी_var->location;
	}
    }
    loc = (loc - आकार) & -align;
    यदि (nb_अस्थायी_local_vars<MAX_अस्थायी_LOCAL_VARIABLE_सङ्ख्या) {
	अस्थायी_var=&arr_अस्थायी_local_vars[i];
	अस्थायी_var->location=loc;
	अस्थायी_var->आकार=आकार;
	अस्थायी_var->align=align;
	nb_अस्थायी_local_vars++;
	गच्छ ret_tmp;
    }
    *r2 = VT_CONST;
    प्रत्यागम loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
स्थिर शून्य move_reg(पूर्णाङ्क r, पूर्णाङ्क s, पूर्णाङ्क t)
{
    SValue sv;

    यदि (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = रिक्त;
        sv.r = s;
        sv.c.i = 0;
        आरोपय(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC शून्य gaddrof(शून्य)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    यदि ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
स्थिर शून्य gen_bounded_ptr_सङ्कलय(शून्य)
{
    पूर्णाङ्क save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    यदि (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK_bound_ptr_सङ्कलय);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    यदि (nocode_wanted)
        प्रत्यागम;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_text_section->reloc->दत्त_विस्थापनम् - परिमाण(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
स्थिर शून्य gen_bounded_ptr_deref(शून्य)
{
    addr_t func;
    पूर्णाङ्क आकार, align;
    ElfW_Rel *rel;
    Sym *sym;

    यदि (nocode_wanted)
        प्रत्यागम;

    आकार = type_आकार(&vtop->type, &align);
    विकल्प(आकार) {
    पक्ष  1: func = TOK___bound_ptr_indir1; भङ्ग;
    पक्ष  2: func = TOK___bound_ptr_indir2; भङ्ग;
    पक्ष  4: func = TOK___bound_ptr_indir4; भङ्ग;
    पक्ष  8: func = TOK___bound_ptr_indir8; भङ्ग;
    पक्ष 12: func = TOK___bound_ptr_indir12; भङ्ग;
    पक्ष 16: func = TOK___bound_ptr_indir16; भङ्ग;
    स्वभाव:
        /* may happen with struct member access */
        प्रत्यागम;
    }
    sym = external_helper_sym(func);
    यदि (!sym->c)
        put_extern_sym(sym, रिक्त, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_text_section->reloc->दत्त + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
स्थिर शून्य gbound(शून्य)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    यदि (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        यदि (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_सङ्कलय();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC शून्य gbound_तर्काः(पूर्णाङ्क nb_तर्काः)
{
    पूर्णाङ्क i, v;
    SValue *sv;

    प्रति (i = 1; i <= nb_तर्काः; ++i)
        यदि (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_तर्काः;
    यदि (sv->r & VT_SYM) {
        v = sv->sym->v;
        यदि (v == TOK_setjmp
          || v == TOK__setjmp
#यदि_अपरिभाषितम् TCC_TARGET_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#यदि_अन्तः
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_सङ्कलय_epilog = 1;
        }
        यदि (v == TOK_alloca)
            func_bound_सङ्कलय_epilog = 1;
#यदि TARGETOS_NetBSD
        यदि (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#यदि_अन्तः
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
स्थिर शून्य सङ्कलय_local_bounds(Sym *s, Sym *e)
{
    प्रति (; s != e; s = s->पूर्व) {
        यदि (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          अनुवर्त;
        /* Add arrays/structs/unions because we always take address */
        यदि ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            पूर्णाङ्क align, आकार = type_आकार(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_सङ्कलय(lbounds_section,
                                                 2 * परिमाण(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = आकार;
        }
    }
}
#यदि_अन्तः

/* add debug info for locals or function parameters, optionally
   register bounds */
स्थिर शून्य tcc_debug_अन्तः_scope(Sym *b, पूर्णाङ्क bounds)
{
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (tcc_state->do_bounds_check && bounds)
        सङ्कलय_local_bounds(local_राशिः, b);
#यदि_अन्तः
    tcc_सङ्कलय_debug_info (tcc_state, local_राशिः, b);
}

/* increment an lvalue pointer */
स्थिर शून्य incr_विस्थापनम्(पूर्णाङ्क विस्थापनम्)
{
    पूर्णाङ्क t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(विस्थापनम्);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

स्थिर शून्य incr_bf_adr(पूर्णाङ्क o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_विस्थापनम्(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
स्थिर शून्य आरोपय_packed_bf(CType *type, पूर्णाङ्क bit_pos, पूर्णाङ्क bit_आकार)
{
    पूर्णाङ्क n, o, द्वयङ्काः;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    द्वयङ्काः = 0, o = bit_pos >> 3, bit_pos &= 7;
    कुरु {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - bit_pos;
        यदि (n > bit_आकार)
            n = bit_आकार;
        यदि (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHR), bit_pos = 0; // X B Y
        यदि (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        यदि (द्वयङ्काः)
            vpushi(द्वयङ्काः), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        द्वयङ्काः += n, bit_आकार -= n, o = 1;
    } यावत् (bit_आकार);
    vswap(), vpop();
    यदि (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - द्वयङ्काः;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
स्थिर शून्य store_packed_bf(पूर्णाङ्क bit_pos, पूर्णाङ्क bit_आकार)
{
    पूर्णाङ्क द्वयङ्काः, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    द्वयङ्काः = 0, o = bit_pos >> 3, bit_pos &= 7;
    कुरु {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        यदि (द्वयङ्काः)
            vpushi(द्वयङ्काः), gen_op(TOK_SHR);
        यदि (bit_pos)
            vpushi(bit_pos), gen_op(TOK_SHL);
        n = 8 - bit_pos;
        यदि (n > bit_आकार)
            n = bit_आकार;
        यदि (n < 8) {
            m = ((1 << n) - 1) << bit_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        द्वयङ्काः += n, bit_आकार -= n, bit_pos = 0, o = 1;
    } यावत् (bit_आकार);
    vpop(), vpop();
}

स्थिर पूर्णाङ्क adjust_bf(SValue *sv, पूर्णाङ्क bit_pos, पूर्णाङ्क bit_आकार)
{
    पूर्णाङ्क t;
    यदि (0 == sv->type.ref)
        प्रत्यागम 0;
    t = sv->type.ref->auxtype;
    यदि (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    प्रत्यागम t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC पूर्णाङ्क gv(पूर्णाङ्क rc)
{
    पूर्णाङ्क r, r2, r_ok, r2_ok, rc2, bt;
    पूर्णाङ्क bit_pos, bit_आकार, आकार, align;

    /* NOTE: get_reg can modify vstack[] */
    यदि (vtop->type.t & VT_BITFIELD) {
        CType type;

        bit_pos = BIT_POS(vtop->type.t);
        bit_आकार = BIT_आकार(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_आवरणम्;

        type.ref = रिक्त;
        type.t = vtop->type.t & VT_UNSIGNED;
        यदि ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, bit_pos, bit_आकार);

        यदि ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        अन्यथा
            type.t |= VT_INT;

        यदि (r == VT_STRUCT) {
            आरोपय_packed_bf(&type, bit_pos, bit_आकार);
        } अन्यथा {
            पूर्णाङ्क द्वयङ्काः = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(द्वयङ्काः - (bit_pos + bit_आकार));
            gen_op(TOK_SHL);
            vpushi(द्वयङ्काः - bit_आकार);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } अन्यथा {
        यदि (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            अचिह्नित दीर्घ विस्थापनम्;
            आकार = type_आकार(&vtop->type, &align);
            यदि (NODATA_WANTED)
                आकार = 0, align = 1;
            विस्थापनम् = section_सङ्कलय(p.sec, आकार, align);
            vpush_ref(&vtop->type, p.sec, विस्थापनम्, आकार);
	    vswap();
	    init_putv(&p, &vtop->type, विस्थापनम्);
	    vtop->r |= VT_LVAL;
        }
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (vtop->r & VT_MUSTBOUND) 
            gbound();
#यदि_अन्तः

        bt = vtop->type.t & VT_BTYPE;
        यदि (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            प्रत्यागम vtop->r;

#यदि_परिभाषितम् TCC_TARGET_RISCV64
        /* XXX mega hack */
        यदि (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#यदि_अन्तः
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        यदि (!r_ok || !r2_ok) {

            यदि (!r_ok) {
                यदि (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                अन्यथा
                    r = get_reg(rc);
            }

            यदि (rc2) {
                पूर्णाङ्क आरोपय_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                पूर्णाङ्क original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                यदि ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    अचिह्नित दीर्घ दीर्घ ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    आरोपय(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } अन्यथा यदि (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = आरोपय_type;
                    आरोपय(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_विस्थापनम्(PTR_आकार);
                } अन्यथा {
                    /* move registers */
                    यदि (!r_ok)
                        आरोपय(r, vtop);
                    यदि (r2_ok && vtop->r2 < VT_CONST)
                        गच्छ समाप्तम्;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                आरोपय(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            समाप्तम्:
                vtop->type.t = original_type;
            } अन्यथा {
                यदि (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                आरोपय(r, vtop);
            }
        }
        vtop->r = r;
#यदि_परिभाषितम् TCC_TARGET_C67
        /* uses register pairs for doubles */
        यदि (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#यदि_अन्तः
    }
    प्रत्यागम r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC शून्य gv2(पूर्णाङ्क rc1, पूर्णाङ्क rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    यदि (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        यदि ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
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
        यदि ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#यदि PTR_आकार == 4
/* expand 64bit on stack in two ints */
ST_FUNC शून्य lexpand(शून्य)
{
    पूर्णाङ्क u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    यदि (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } अन्यथा यदि (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
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
#यदि_अन्तः

#यदि PTR_आकार == 4
/* build a long long from two ints */
स्थिर शून्य lbuild(पूर्णाङ्क t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#यदि_अन्तः

/* convert stack entry to register and duplicate its value in another
पञ्जिकाकोशः*/
स्थिर शून्य gv_dup(शून्य)
{
    पूर्णाङ्क t, rc, r;

    t = vtop->type.t;
#यदि PTR_आकार == 4
    यदि ((t & VT_BTYPE) == VT_LLONG) {
        यदि (t & VT_BITFIELD) {
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
        प्रत्यागम;
    }
#यदि_अन्तः
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    आरोपय(r, vtop);
    vtop->r = r;
}

#यदि PTR_आकार == 4
/* generate CPU independent (unsigned) long long operations */
स्थिर शून्य gen_opl(पूर्णाङ्क op)
{
    पूर्णाङ्क t, a, b, op1, c, i;
    पूर्णाङ्क func;
    अचिह्नित ह्रस्व reg_iret = REG_IRET;
    अचिह्नित ह्रस्व reg_lret = REG_IRE2;
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
#यदि_परिभाषितम् TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#यदि_अन्तः
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
        यदि (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            प्रति(i=0;i<4;i++)
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
        } अन्यथा यदि (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            यदि (op == '+')
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
        भङ्ग;
    पक्ष TOK_SAR:
    पक्ष TOK_SHR:
    पक्ष TOK_SHL:
        यदि ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
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
            यदि (op != TOK_SHL)
                vswap();
            यदि (c >= 32) {
                /* stack: L H */
                vpop();
                यदि (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                यदि (op != TOK_SAR) {
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
                यदि (op == TOK_SHL)
                    gen_op(TOK_SHR);
                अन्यथा
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                यदि (op == TOK_SHL)
                    gen_op(TOK_SHL);
                अन्यथा
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            यदि (op != TOK_SHL)
                vswap();
            lbuild(t);
        } अन्यथा {
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
        यदि (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        यदि (op1 == TOK_LT)
            op1 = TOK_LE;
        अन्यथा यदि (op1 == TOK_GT)
            op1 = TOK_GE;
        अन्यथा यदि (op1 == TOK_ULT)
            op1 = TOK_ULE;
        अन्यथा यदि (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        यदि (op == TOK_NE) {
            b = gvtst(0, 0);
        } अन्यथा {
            a = gvtst(1, 0);
            यदि (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        यदि (op1 == TOK_LT)
            op1 = TOK_ULT;
        अन्यथा यदि (op1 == TOK_LE)
            op1 = TOK_ULE;
        अन्यथा यदि (op1 == TOK_GT)
            op1 = TOK_UGT;
        अन्यथा यदि (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#यदि 0//def TCC_TARGET_I386
        यदि (op == TOK_NE) { gsym(b); भङ्ग; }
        यदि (op == TOK_EQ) { gsym(a); भङ्ग; }
#यदि_अन्तः
        gvtst_समुच्चयः(1, a);
        gvtst_समुच्चयः(0, b);
        भङ्ग;
    }
}
#यदि_अन्तः

/* normalize values */
स्थिर uint64_t value64(uint64_t l1, पूर्णाङ्क t)
{
    यदि ((t & VT_BTYPE) == VT_LLONG
        || (PTR_आकार == 8 && (t & VT_BTYPE) == VT_PTR))
        प्रत्यागम l1;
    अन्यथा यदि (t & VT_UNSIGNED)
        प्रत्यागम (uint32_t)l1;
    अन्यथा
        प्रत्यागम (uint32_t)l1 | -(l1 & 0x80000000);
}

स्थिर uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    प्रत्यागम (a ^ b) >> 63 ? -x : x;
}

स्थिर पूर्णाङ्क gen_opic_lt(uint64_t a, uint64_t b)
{
    प्रत्यागम (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
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

    यदि (c1 && c2) {
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
            यदि (l2 == 0) {
                यदि (CONST_WANTED && !NOEVAL_WANTED)
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
    } अन्यथा {
        /* if commutative ops, put c2 as constant */
        यदि (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        यदि (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } अन्यथा यदि (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            यदि (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } अन्यथा यदि (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } अन्यथा यदि (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            यदि (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                पूर्णाङ्क n = -1;
                यदि (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    गच्छ general_case;
                }
                यावत् (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                यदि (op == '*')
                    op = TOK_SHL;
                अन्यथा यदि (op == TOK_PDIV)
                    op = TOK_SAR;
                अन्यथा
                    op = TOK_SHR;
            }
            गच्छ general_case;
        } अन्यथा यदि (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            यदि (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    यदि ((पूर्णाङ्क)l2 != l2)
	        गच्छ general_case;
            vtop--;
            vtop->c.i = l2;
        } अन्यथा {
        general_case:
                /* call low level op generator */
                यदि (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_आकार == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                अन्यथा
                    gen_opi(op);
        }
        यदि (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#यदि defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386 || defined TCC_TARGET_ARM64
# define gen_negf gen_opf
#नोचेद्यदि defined TCC_TARGET_ARM
शून्य gen_negf(पूर्णाङ्क op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#अन्यथा
/* XXX: implement in gen_opf() for other backends too */
शून्य gen_negf(पूर्णाङ्क op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    पूर्णाङ्क align, आकार, bt;
    आकार = type_आकार(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#यदि defined TCC_TARGET_X86_64 || defined TCC_TARGET_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    यदि (bt == VT_LDOUBLE)
        आकार = 10;
#यदि_अन्तः
    यदि (nocode_wanted) /* save_reg() wont work */
        गच्छ gv2;
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
#यदि_अन्तः

/* generate a floating point operation with constant propagation */
स्थिर शून्य gen_opif(पूर्णाङ्क op)
{
    पूर्णाङ्क c1, c2, i, bt;
    SValue *v1, *v2;
#यदि defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    चञ्चल
#यदि_अन्तः
    दीर्घ द्विगुण f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    यदि (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    यदि (c1 && c2) {
        यदि (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } अन्यथा यदि (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } अन्यथा {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        यदि (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            गच्छ general_case;
        विकल्प(op) {
        पक्ष '+': f1 += f2; भङ्ग;
        पक्ष '-': f1 -= f2; भङ्ग;
        पक्ष '*': f1 *= f2; भङ्ग;
        पक्ष '/': 
            यदि (f2 == 0.0) {
                सङ्घ { भिन्न f; अचिह्नित u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                यदि (!CONST_WANTED)
                    गच्छ general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                यदि (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                अन्यथा
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                भङ्ग;
            }
            f1 /= f2;
            भङ्ग;
        पक्ष TOK_NEG:
            f1 = -f1;
            गच्छ unary_परिणाम;
        पक्ष TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            प्रत्यागम;
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
    unary_परिणाम:
        /* XXX: overflow test ? */
        यदि (bt == VT_FLOAT) {
            v1->c.f = f1;
        } अन्यथा यदि (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } अन्यथा {
            v1->c.ld = f1;
        }
    } अन्यथा {
    general_case:
        यदि (op == TOK_NEG) {
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
स्थिर शून्य type_गन्तव्यम्_str(वर्ण *buf, पूर्णाङ्क buf_आकार,
                 CType *type, ध्रुव वर्ण *varstr)
{
    पूर्णाङ्क bt, v, t;
    Sym *s, *sa;
    वर्ण buf1[256];
    ध्रुव वर्ण *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    यदि (t & VT_EXTERN)
        pstrcat(buf, buf_आकार, "extern ");
    यदि (t & VT_STATIC)
        pstrcat(buf, buf_आकार, "static ");
    यदि (t & VT_TYPEDEF)
        pstrcat(buf, buf_आकार, "typedef ");
    यदि (t & VT_INLINE)
        pstrcat(buf, buf_आकार, "inline ");
    यदि (bt != VT_PTR) {
        यदि (t & VT_RESTRICT)
            pstrcat(buf, buf_आकार, "restrict ");
        यदि (t & VT_VOLATILE)
            pstrcat(buf, buf_आकार, "volatile ");
        यदि (t & VT_CONSTANT)
            pstrcat(buf, buf_आकार, "const ");
    }
    यदि (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_आकार, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_आकार -= वाक्यदैर्घ्यम्(buf);
    buf += वाक्यदैर्घ्यम्(buf);

    विकल्प(bt) {
    पक्ष VT_VOID:
        tstr = "void";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_BOOL:
        tstr = "_Bool";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_BYTE:
        tstr = "char";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_SHORT:
        tstr = "short";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_INT:
        tstr = "int";
        गच्छ maybe_long;
    पक्ष VT_LLONG:
        tstr = "long long";
    maybe_long:
        यदि (t & VT_LONG)
            tstr = "long";
        यदि (!IS_ENUM(t))
            गच्छ सङ्कलय_tstr;
        tstr = "enum ";
        गच्छ tstruct;
    पक्ष VT_FLOAT:
        tstr = "float";
        गच्छ सङ्कलय_tstr;
    पक्ष VT_DOUBLE:
        tstr = "double";
        यदि (!(t & VT_LONG))
            गच्छ सङ्कलय_tstr;
    पक्ष VT_LDOUBLE:
        tstr = "long double";
    सङ्कलय_tstr:
        pstrcat(buf, buf_आकार, tstr);
        भङ्ग;
    पक्ष VT_STRUCT:
        tstr = "struct ";
        यदि (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_आकार, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        यदि (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_आकार, "<anonymous>");
        अन्यथा
            pstrcat(buf, buf_आकार, get_tok_str(v, रिक्त));
        भङ्ग;
    पक्ष VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        यदि (varstr && '*' == *varstr) {
            pstrcat(buf1, परिमाण(buf1), "(");
            pstrcat(buf1, परिमाण(buf1), varstr);
            pstrcat(buf1, परिमाण(buf1), ")");
        }
        pstrcat(buf1, परिमाण(buf1), "(");
        sa = s->अग्र;
        यावत् (sa != रिक्त) {
            वर्ण buf2[256];
            type_गन्तव्यम्_str(buf2, परिमाण(buf2), &sa->type, रिक्त);
            pstrcat(buf1, परिमाण(buf1), buf2);
            sa = sa->अग्र;
            यदि (sa)
                pstrcat(buf1, परिमाण(buf1), ", ");
        }
        यदि (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, परिमाण(buf1), ", ...");
        pstrcat(buf1, परिमाण(buf1), ")");
        type_गन्तव्यम्_str(buf, buf_आकार, &s->type, buf1);
        गच्छ no_var;
    पक्ष VT_PTR:
        s = type->ref;
        यदि (t & (VT_ARRAY|VT_VLA)) {
            यदि (varstr && '*' == *varstr)
                snprintf(buf1, परिमाण(buf1), "(%s)[%d]", varstr, s->c);
            अन्यथा
                snprintf(buf1, परिमाण(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_गन्तव्यम्_str(buf, buf_आकार, &s->type, buf1);
            गच्छ no_var;
        }
        pstrcpy(buf1, परिमाण(buf1), "*");
        यदि (t & VT_RESTRICT)
            pstrcat(buf1, परिमाण(buf1), "restrict ");
        यदि (t & VT_CONSTANT)
            pstrcat(buf1, परिमाण(buf1), "const ");
        यदि (t & VT_VOLATILE)
            pstrcat(buf1, परिमाण(buf1), "volatile ");
        यदि (varstr)
            pstrcat(buf1, परिमाण(buf1), varstr);
        type_गन्तव्यम्_str(buf, buf_आकार, &s->type, buf1);
        गच्छ no_var;
    }
    यदि (varstr) {
        pstrcat(buf, buf_आकार, " ");
        pstrcat(buf, buf_आकार, varstr);
    }
 no_var: ;
}

स्थिर शून्य type_incompatibility_error(CType* st, CType* dt, ध्रुव वर्ण* fmt)
{
    वर्ण buf1[256], buf2[256];
    type_गन्तव्यम्_str(buf1, परिमाण(buf1), st, रिक्त);
    type_गन्तव्यम्_str(buf2, परिमाण(buf2), dt, रिक्त);
    tcc_error(fmt, buf1, buf2);
}

स्थिर शून्य type_incompatibility_warning(CType* st, CType* dt, ध्रुव वर्ण* fmt)
{
    वर्ण buf1[256], buf2[256];
    type_गन्तव्यम्_str(buf1, परिमाण(buf1), st, रिक्त);
    type_गन्तव्यम्_str(buf2, परिमाण(buf2), dt, रिक्त);
    tcc_warning(fmt, buf1, buf2);
}

स्थिर पूर्णाङ्क pointed_आकार(CType *type)
{
    पूर्णाङ्क align;
    प्रत्यागम type_आकार(pointed_type(type), &align);
}

स्थिर अन्तःस्थ पूर्णाङ्क is_null_pointer(SValue *p)
{
    यदि ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        प्रत्यागम 0;
    प्रत्यागम ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_आकार == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
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
    यदि (s1->f.func_call != s2->f.func_call)
        प्रत्यागम 0;
    यदि (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        प्रत्यागम 0;
    प्रति (;;) {
        यदि (!is_compatible_unqualified_types(&s1->type, &s2->type))
            प्रत्यागम 0;
        यदि (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            प्रत्यागम 1;
        s1 = s1->अग्र;
        s2 = s2->अग्र;
        यदि (!s1)
            प्रत्यागम !s2;
        यदि (!s2)
            प्रत्यागम 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
स्थिर पूर्णाङ्क compare_types(CType *type1, CType *type2, पूर्णाङ्क unqualified)
{
    पूर्णाङ्क bt1, t1, t2;

    यदि (IS_ENUM(type1->t)) {
        यदि (IS_ENUM(type2->t))
            प्रत्यागम type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } अन्यथा यदि (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    यदि (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    यदि ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    यदि (t1 != t2)
        प्रत्यागम 0;

    यदि ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            प्रत्यागम 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    यदि (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        यदि (unqualified && (t1 & VT_ARRAY))
            प्रत्यागम compare_types(type1, type2, 1);
        प्रत्यागम is_compatible_types(type1, type2);
    } अन्यथा यदि (bt1 == VT_STRUCT) {
        प्रत्यागम (type1->ref == type2->ref);
    } अन्यथा यदि (bt1 == VT_FUNC) {
        प्रत्यागम is_compatible_func(type1, type2);
    } अन्यथा {
        प्रत्यागम 1;
    }
}

#परिभाषय CMP_OP 'C'
#परिभाषय सरणम्_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
स्थिर पूर्णाङ्क combine_types(CType *dest, SValue *op1, SValue *op2, पूर्णाङ्क op)
{
    CType *type1, *type2, type;
    पूर्णाङ्क t1, t2, bt1, bt2;
    पूर्णाङ्क ret = 1;

    /* for shifts, 'combine' only left operand */
    यदि (op == सरणम्_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = रिक्त;

    यदि (bt1 == VT_VOID || bt2 == VT_VOID) {
        यदि (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } अन्यथा यदि (bt1 == VT_PTR || bt2 == VT_PTR) {
        यदि (op == '+') {
          यदि (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        अन्यथा यदि (is_null_pointer (op2)) type = *type1;
        अन्यथा यदि (is_null_pointer (op1)) type = *type2;
        अन्यथा यदि (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            यदि ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            अन्यथा यदि (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } अन्यथा {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            पूर्णाङ्क pbt1 = pt1->t & VT_BTYPE;
            पूर्णाङ्क pbt2 = pt2->t & VT_BTYPE;
            पूर्णाङ्क newquals, copied = 0;
            यदि (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                यदि (op != '?' && op != CMP_OP)
                  ret = 0;
                अन्यथा
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            यदि (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                यदि ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_प्रक्षिप(SYM_क्षेत्रम्, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                यदि (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    यदि (!copied)
                      type.ref = sym_प्रक्षिप(SYM_क्षेत्रम्, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_प्रक्षिप(SYM_क्षेत्रम्, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        यदि (op == CMP_OP)
          type.t = VT_आकार_T;
    } अन्यथा यदि (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        यदि (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } अन्यथा यदि (is_float(bt1) || is_float(bt2)) {
        यदि (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } अन्यथा यदि (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } अन्यथा {
            type.t = VT_FLOAT;
        }
    } अन्यथा यदि (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        यदि (bt1 == VT_LLONG)
          type.t &= t1;
        यदि (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        यदि ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } अन्यथा {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        यदि (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || BIT_आकार(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || BIT_आकार(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    यदि (dest)
      *dest = type;
    प्रत्यागम ret;
}

/* generic gen_op: handles types problems */
ST_FUNC शून्य gen_op(पूर्णाङ्क op)
{
    पूर्णाङ्क t1, t2, bt1, bt2, t;
    CType type1, combtype;
    पूर्णाङ्क op_class = op;

    यदि (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = सरणम्_OP;
    अन्यथा यदि (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    यदि (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	यदि (bt2 == VT_FUNC) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	यदि (bt1 == VT_FUNC) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
	गच्छ redo;
    } अन्यथा यदि (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } अन्यथा यदि (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        पूर्णाङ्क align;
        यदि (op_class == CMP_OP)
            गच्छ std_op;
        /* if both pointers, then it must be the '-' op */
        यदि (bt1 == VT_PTR && bt2 == VT_PTR) {
            यदि (op != '-')
                गच्छ op_err;
            vpush_type_आकार(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } अन्यथा {
            /* exactly one pointer : must be '+' or '-'. */
            यदि (op != '-' && op != '+')
                गच्छ op_err;
            /* Put pointer as first operand */
            यदि (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#यदि PTR_आकार == 4
            यदि (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#यदि_अन्तः
            type1 = vtop[-1].type;
            vpush_type_आकार(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
            यदि (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                यदि (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_सङ्कलय();
            } अन्यथा
#यदि_अन्तः
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } अन्यथा {
        /* floats can only be used for a few operations */
        यदि (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            गच्छ op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        यदि (op_class == सरणम्_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        यदि (t & VT_UNSIGNED) {
            यदि (op == TOK_SAR)
                op = TOK_SHR;
            अन्यथा यदि (op == '/')
                op = TOK_UDIV;
            अन्यथा यदि (op == '%')
                op = TOK_UMOD;
            अन्यथा यदि (op == TOK_LT)
                op = TOK_ULT;
            अन्यथा यदि (op == TOK_GT)
                op = TOK_UGT;
            अन्यथा यदि (op == TOK_LE)
                op = TOK_ULE;
            अन्यथा यदि (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        यदि (is_float(t))
            gen_opif(op);
        अन्यथा
            gen_opic(op);
        यदि (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } अन्यथा {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    यदि (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#यदि defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64 || defined TCC_TARGET_ARM
#परिभाषय gen_cvt_itof1 gen_cvt_itof
#अन्यथा
/* generic itof for unsigned long long case */
स्थिर शून्य gen_cvt_itof1(पूर्णाङ्क t)
{
    यदि ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        यदि (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#यदि LDOUBLE_आकार != 8
        अन्यथा यदि (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#यदि_अन्तः
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
#यदि_अन्तः

#यदि defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
#परिभाषय gen_cvt_ftoi1 gen_cvt_ftoi
#अन्यथा
/* generic ftoi for unsigned long long case */
स्थिर शून्य gen_cvt_ftoi1(पूर्णाङ्क t)
{
    पूर्णाङ्क st;
    यदि (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        यदि (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#यदि LDOUBLE_आकार != 8
        अन्यथा यदि (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#यदि_अन्तः
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
#यदि_अन्तः

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
    पूर्णाङ्क dbt_bt, sbt_bt, ds, ss, द्वयङ्काः, trunc;

    /* special delayed cast for char/short */
    यदि (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    यदि (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    यदि (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    यदि (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    यदि (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        यदि (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            गच्छ समाप्तम्;
        }
        यदि (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        यदि (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            यदि (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            अन्यथा यदि (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            यदि (df) {
                यदि (sbt_bt == VT_LLONG) {
                    यदि ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    अन्यथा
                        vtop->c.ld = -(दीर्घ द्विगुण)-vtop->c.i;
                } अन्यथा यदि(!sf) {
                    यदि ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    अन्यथा
                        vtop->c.ld = -(दीर्घ द्विगुण)-(uint32_t)vtop->c.i;
                }

                यदि (dbt == VT_FLOAT)
                    vtop->c.f = (भिन्न)vtop->c.ld;
                अन्यथा यदि (dbt == VT_DOUBLE)
                    vtop->c.d = (द्विगुण)vtop->c.ld;
            } अन्यथा यदि (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } अन्यथा {
                यदि(sf) {
                    यदि (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    अन्यथा
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                अन्यथा यदि (sbt_bt == VT_LLONG || (PTR_आकार == 8 && sbt == VT_PTR))
                    ;
                अन्यथा यदि (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                अन्यथा
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                यदि (dbt_bt == VT_LLONG || (PTR_आकार == 8 && dbt == VT_PTR))
                    ;
                अन्यथा यदि (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                अन्यथा {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    यदि (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            गच्छ समाप्तम्;

        } अन्यथा यदि (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            गच्छ समाप्तम्;
        }

        /* cannot generate code for global or static initializers */
        यदि (nocode_wanted & दत्त_ONLY_WANTED) {
            यदि (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            गच्छ समाप्तम्;
        }

        /* non constant case: generate code */
        यदि (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            गच्छ समाप्तम्;
        }

        यदि (sf || df) {
            यदि (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } अन्यथा यदि (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } अन्यथा {
                /* convert fp to int */
                sbt = dbt;
                यदि (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                गच्छ again; /* may need char/short cast */
            }
            गच्छ समाप्तम्;
        }

        ds = btype_आकार(dbt_bt);
        ss = btype_आकार(sbt_bt);
        यदि (ds == 0 || ss == 0)
            गच्छ error;

        /* same size and no sign conversion needed */
        यदि (ds == ss && ds >= 4)
            गच्छ समाप्तम्;
        यदि (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            यदि (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_आकार == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #परिभाषय ALLOW_SUBTYPE_ACCESS 1

        यदि (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            यदि (ds <= ss)
                गच्छ समाप्तम्;
            /* ss <= 4 here */
            यदि (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                गच्छ समाप्तम्; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#यदि PTR_आकार == 4
        यदि (ds == 8) {
            /* generate high word */
            यदि (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } अन्यथा {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } अन्यथा यदि (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#नोचेद्यदि PTR_आकार == 8
        यदि (ds == 8) {
            /* need to convert from 32bit to 64bit */
            यदि (sbt & VT_UNSIGNED) {
#यदि defined(TCC_TARGET_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#अन्यथा
                गच्छ समाप्तम्;
#यदि_अन्तः
            } अन्यथा {
                gen_cvt_sxtw();
                गच्छ समाप्तम्;
            }
            ss = ds, ds = 4, dbt = sbt;
        } अन्यथा यदि (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#यदि !defined(TCC_TARGET_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#यदि_अन्तः
        } अन्यथा {
            ss = 4;
        }
#यदि_अन्तः

        यदि (ds >= ss)
            गच्छ समाप्तम्;
#यदि defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    यदि (ss == 4) {
        gen_cvt_csti(dbt);
        गच्छ समाप्तम्;
    }
#यदि_अन्तः
        द्वयङ्काः = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(द्वयङ्काः);
        gen_op(TOK_SHL);
        vpushi(द्वयङ्काः - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
समाप्तम्:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC पूर्णाङ्क type_आकार(CType *type, पूर्णाङ्क *a)
{
    Sym *s;
    पूर्णाङ्क bt;

    bt = type->t & VT_BTYPE;
    यदि (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        प्रत्यागम s->c;
    } अन्यथा यदि (bt == VT_PTR) {
        यदि (type->t & VT_ARRAY) {
            पूर्णाङ्क ts;
            s = type->ref;
            ts = type_आकार(&s->type, a);
            यदि (s->c < 0)
                प्रत्यागम s->c;
            प्रत्यागम ts * s->c;
        } अन्यथा {
            *a = PTR_आकार;
            प्रत्यागम PTR_आकार;
        }
    } अन्यथा यदि (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        प्रत्यागम -1; /* incomplete enum */
    } अन्यथा यदि (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        प्रत्यागम LDOUBLE_आकार;
    } अन्यथा यदि (bt == VT_DOUBLE || bt == VT_LLONG) {
#यदि (defined TCC_TARGET_I386 && !defined TCC_TARGET_PE) \
 || (defined TCC_TARGET_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#अन्यथा
        *a = 8;
#यदि_अन्तः
        प्रत्यागम 8;
    } अन्यथा यदि (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        प्रत्यागम 4;
    } अन्यथा यदि (bt == VT_SHORT) {
        *a = 2;
        प्रत्यागम 2;
    } अन्यथा यदि (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        प्रत्यागम 16;
    } अन्यथा {
        /* char, void, function, _Bool */
        *a = 1;
        प्रत्यागम 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
स्थिर शून्य vpush_type_आकार(CType *type, पूर्णाङ्क *a)
{
    यदि (type->t & VT_VLA) {
        type_आकार(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } अन्यथा {
        पूर्णाङ्क आकार = type_आकार(type, a);
        यदि (आकार < 0)
            tcc_error("unknown type size");
        vpushs(आकार);
    }
}

/* return the pointed type of t */
स्थिर अन्तःस्थ CType *pointed_type(CType *type)
{
    प्रत्यागम &type->ref->type;
}

स्थिर शून्य check_restrict_type(CType *type)
{
    यावत् ((type->t & VT_BTYPE) == VT_PTR) {
        यदि ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    यदि (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
स्थिर पूर्णाङ्क type_qualifiers(CType *type)
{
    यावत् (type->t & VT_ARRAY)
        type = pointed_type(type);
    प्रत्यागम type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC शून्य mk_pointer(CType *type)
{
    Sym *s;
    s = sym_प्रक्षिप(SYM_क्षेत्रम्, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
स्थिर पूर्णाङ्क is_compatible_types(CType *type1, CType *type2)
{
    प्रत्यागम compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
स्थिर पूर्णाङ्क is_compatible_unqualified_types(CType *type1, CType *type2)
{
    प्रत्यागम compare_types(type1,type2,1);
}

स्थिर शून्य cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
स्थिर शून्य verify_नियोजय_cast(CType *dt)
{
    CType *st, *type1, *type2;
    पूर्णाङ्क dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    यदि (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    विकल्प(dbt) {
    पक्ष VT_VOID:
        यदि (sbt != dbt)
            tcc_error("assignment to void expression");
        भङ्ग;
    पक्ष VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        यदि (is_null_pointer(vtop))
            भङ्ग;
        /* accept implicit pointer to integer cast with warning */
        यदि (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            भङ्ग;
        }
        type1 = pointed_type(dt);
        यदि (sbt == VT_PTR)
            type2 = pointed_type(st);
        अन्यथा यदि (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        अन्यथा
            गच्छ error;
        यदि (is_compatible_types(type1, type2))
            भङ्ग;
        प्रति (qualwarn = lvl = 0;; ++lvl) {
            यदि ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            यदि (dbt != VT_PTR || sbt != VT_PTR)
                भङ्ग;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        यदि (!is_compatible_unqualified_types(type1, type2)) {
            यदि ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } अन्यथा यदि (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } अन्यथा {
                tcc_warning("assignment from incompatible pointer type");
                भङ्ग;
            }
        }
        यदि (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        भङ्ग;
    पक्ष VT_BYTE:
    पक्ष VT_SHORT:
    पक्ष VT_INT:
    पक्ष VT_LLONG:
        यदि (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } अन्यथा यदि (sbt == VT_STRUCT) {
            गच्छ case_VT_STRUCT;
        }
        /* XXX: more tests */
        भङ्ग;
    पक्ष VT_STRUCT:
    case_VT_STRUCT:
        यदि (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        भङ्ग;
    }
}

स्थिर शून्य gen_नियोजय_cast(CType *dt)
{
    verify_नियोजय_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC शून्य vstore(शून्य)
{
    पूर्णाङ्क sbt, dbt, ft, r, आकार, align, bit_आकार, bit_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_नियोजय_cast(&vtop[-1].type);

    यदि (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        आकार = type_आकार(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#यदि_अन्तः
        vtop->type.t = VT_PTR;
        gaddrof();
        /* source */
        vswap();
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (vtop->r & VT_MUSTBOUND)
            gbound();
#यदि_अन्तः
        vtop->type.t = VT_PTR;
        gaddrof();

#यदि_परिभाषितम् TCC_TARGET_NATIVE_STRUCT_COPY
        यदि (1
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#यदि_अन्तः
            ) {
            gen_struct_copy(आकार);
        } अन्यथा
#यदि_अन्तः
        {
            /* type size */
            vpushi(आकार);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#यदि_परिभाषितम् TCC_ARM_EABI
            यदि(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            अन्यथा यदि(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            अन्यथा
#यदि_अन्तः
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } अन्यथा यदि (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        bit_pos = BIT_POS(ft);
        bit_आकार = BIT_आकार(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_आवरणम्;

        यदि (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, bit_pos, bit_आकार);
        यदि (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        यदि (r == VT_STRUCT) {
            store_packed_bf(bit_pos, bit_आकार);
        } अन्यथा {
            अचिह्नित दीर्घ दीर्घ आवरणम् = (1ULL << bit_आकार) - 1;
            यदि (dbt != VT_BOOL) {
                /* mask source */
                यदि (dbt == VT_LLONG)
                    vpushll(आवरणम्);
                अन्यथा
                    vpushi((अचिह्नित)आवरणम्);
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
            यदि (dbt == VT_LLONG)
                vpushll(~(आवरणम् << bit_pos));
            अन्यथा
                vpushi(~((अचिह्नित)आवरणम् << bit_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } अन्यथा यदि (dbt == VT_VOID) {
        --vtop;
    } अन्यथा {
            /* optimize char/short casts */
            delayed_cast = 0;
            यदि ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                यदि ((vtop->r & VT_MUSTCAST)
                    && btype_आकार(dbt) > btype_आकार(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } अन्यथा {
                gen_cast(&vtop[-1].type);
            }

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
            /* bound check case */
            यदि (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#यदि_अन्तः
            gv(RC_TYPE(dbt)); /* generate value */

            यदि (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            यदि ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = रिक्त;
                आरोपय(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            यदि (USING_TWO_शब्दाः(dbt)) {
                पूर्णाङ्क आरोपय_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = आरोपय_type;
                store(r, vtop - 1);
                vswap();
                incr_विस्थापनम्(PTR_आकार);
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
ST_FUNC शून्य inc(पूर्णाङ्क post, पूर्णाङ्क c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    यदि (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    यदि (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (ध्रुव वर्ण *सन्देशः)
{
    /* read the string */
    यदि (tok != TOK_STR)
        expect(सन्देशः);
    cstr_reset(&initstr);
    यावत् (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.दत्त, -1);
        अग्र();
    }
    cstr_ccat(&initstr, '\0');
    प्रत्यागम &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC पूर्णाङ्क exact_log2p1(पूर्णाङ्क i)
{
  पूर्णाङ्क ret;
  यदि (!i)
    प्रत्यागम 0;
  प्रति (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  यदि (i >= 1 << 4)
    ret += 4, i >>= 4;
  यदि (i >= 1 << 2)
    ret += 2, i >>= 2;
  यदि (i >= 1 << 1)
    ret++;
  प्रत्यागम ret;
}

/* Parse __attribute__((...)) GNUC extension. */
स्थिर शून्य parse_attribute(AttributeDef *ad)
{
    पूर्णाङ्क t, n;
    वर्ण *astr;
    AttributeDef ad_tmp;
    
redo:
    यदि (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        प्रत्यागम;
    यदि (रिक्त == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    अग्र();
    skip('(');
    skip('(');
    यावत् (tok != ')') {
        यदि (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        अग्र();
        विकल्प(t) {
	पक्ष TOK_CLEANUP1:
	पक्ष TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_find(tok);
	    यदि (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } अन्यथा यदि ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    अग्र();
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
	    astr = parse_mult_str("section name")->दत्त;
            n = tcc_state->nb_sections;
            ad->section = find_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            भङ्ग;
        पक्ष TOK_ALIAS1:
        पक्ष TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->दत्त;
            /* save string as token, for later */
            ad->alias_target = tok_alloc_const(astr);
            skip(')');
            भङ्ग;
	पक्ष TOK_VISIBILITY1:
	पक्ष TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->दत्त;
	    यदि (!वाक्यं_तुलय (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    अन्यथा यदि (!वाक्यं_तुलय (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    अन्यथा यदि (!वाक्यं_तुलय (astr, "internal"))
	        ad->a.visibility = STV_आन्तरिकम्;
	    अन्यथा यदि (!वाक्यं_तुलय (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    अन्यथा
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            भङ्ग;
        पक्ष TOK_ALIGNED1:
        पक्ष TOK_ALIGNED2:
            यदि (tok == '(') {
                अग्र();
                n = व्यञ्जकम्_const();
                यदि (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } अन्यथा {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    यदि (n != 1 << (ad->a.aligned - 1))
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
#यदि_परिभाषितम् TCC_TARGET_I386
        पक्ष TOK_REGPARM1:
        पक्ष TOK_REGPARM2:
            skip('(');
            n = व्यञ्जकम्_const();
            यदि (n > 3) 
                n = 3;
            अन्यथा यदि (n < 0)
                n = 0;
            यदि (n > 0)
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
#यदि_अन्तः
        पक्ष TOK_बहुलकम्:
            skip('(');
            विकल्प(tok) {
                पक्ष TOK_बहुलकम्_DI:
                    ad->attr_बहुलकम् = VT_LLONG + 1;
                    भङ्ग;
                पक्ष TOK_बहुलकम्_QI:
                    ad->attr_बहुलकम् = VT_BYTE + 1;
                    भङ्ग;
                पक्ष TOK_बहुलकम्_HI:
                    ad->attr_बहुलकम् = VT_SHORT + 1;
                    भङ्ग;
                पक्ष TOK_बहुलकम्_SI:
                पक्ष TOK_बहुलकम्_word:
                    ad->attr_बहुलकम् = VT_INT + 1;
                    भङ्ग;
                स्वभाव:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, रिक्त));
                    भङ्ग;
            }
            अग्र();
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
            यदि (tok == '(') {
                पूर्णाङ्क parenthesis = 0;
                कुरु {
                    यदि (tok == '(') 
                        parenthesis++;
                    अन्यथा यदि (tok == ')') 
                        parenthesis--;
                    अग्र();
                } यावत् (parenthesis && tok != -1);
            }
            भङ्ग;
        }
        यदि (tok != ',')
            भङ्ग;
        अग्र();
    }
    skip(')');
    skip(')');
    गच्छ redo;
}

स्थिर Sym * find_क्षेत्रम् (CType *type, पूर्णाङ्क v, पूर्णाङ्क *cumofs)
{
    Sym *s = type->ref;
    पूर्णाङ्क v1 = v | SYM_क्षेत्रम्;
    यदि (!(v & SYM_क्षेत्रम्)) { /* top-level call */
        यदि ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        यदि (v < TOK_UIDENT)
            expect("field name");
        यदि (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    यावत् ((s = s->अग्र) != रिक्त) {
        यदि (s->v == v1) {
            *cumofs = s->c;
            प्रत्यागम s;
        }
        यदि ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_FIRST_ANOM | SYM_क्षेत्रम्)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = find_क्षेत्रम् (&s->type, v1, cumofs);
            यदि (ret) {
                *cumofs += s->c;
                प्रत्यागम ret;
            }
        }
    }
    यदि (!(v & SYM_क्षेत्रम्))
        tcc_error("field not found: %s", get_tok_str(v, रिक्त));
    प्रत्यागम s;
}

स्थिर शून्य check_fields (CType *type, पूर्णाङ्क check)
{
    Sym *s = type->ref;

    यावत् ((s = s->अग्र) != रिक्त) {
        पूर्णाङ्क v = s->v & ~SYM_क्षेत्रम्;
        यदि (v < SYM_FIRST_ANOM) {
            TokenSym *ts = सारणी_ident[v - TOK_IDENT];
            यदि (check && (ts->tok & SYM_क्षेत्रम्))
                tcc_error("duplicate member '%s'", get_tok_str(v, रिक्त));
            ts->tok ^= SYM_क्षेत्रम्;
        } अन्यथा यदि ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

स्थिर शून्य struct_layout(CType *type, AttributeDef *ad)
{
    पूर्णाङ्क आकार, align, maxalign, विस्थापनम्, c, bit_pos, bit_आकार;
    पूर्णाङ्क packed, a, bt, prevbt, पूर्व_bit_आकार;
    पूर्णाङ्क pcc = !tcc_state->ms_bitfields;
    पूर्णाङ्क pragma_pack = *tcc_state->pack_राशिः_ptr;
    Sym *f;

    maxalign = 1;
    विस्थापनम् = 0;
    c = 0;
    bit_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    पूर्व_bit_आकार = 0;

//#define BF_DEBUG

    प्रति (f = type->ref->अग्र; f; f = f->अग्र) {
        यदि (f->type.t & VT_BITFIELD)
            bit_आकार = BIT_आकार(f->type.t);
        अन्यथा
            bit_आकार = -1;
        आकार = type_आकार(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        यदि (pcc && bit_आकार == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } अन्यथा {
            /* in pcc mode, attribute packed overrides if set. */
            यदि (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            यदि (pragma_pack) {
                packed = 1;
                यदि (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                यदि (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        यदि (a)
            align = a;

        यदि (type->ref->type.t == VT_UNION) {
	    यदि (pcc && bit_आकार >= 0)
	        आकार = (bit_आकार + 7) >> 3;
	    विस्थापनम् = 0;
	    यदि (आकार > c)
	        c = आकार;

	} अन्यथा यदि (bit_आकार < 0) {
            यदि (pcc)
                c += (bit_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    विस्थापनम् = c;
	    यदि (आकार > 0)
	        c += आकार;
	    bit_pos = 0;
	    prevbt = VT_STRUCT;
	    पूर्व_bit_आकार = 0;

	} अन्यथा {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            यदि (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                यदि (bit_आकार == 0) {
            new_क्षेत्रम्:
		    c = (c + ((bit_pos + 7) >> 3) + align - 1) & -align;
		    bit_pos = 0;
                } अन्यथा यदि (f->a.aligned) {
                    गच्छ new_क्षेत्रम्;
                } अन्यथा यदि (!packed) {
                    पूर्णाङ्क a8 = align * 8;
	            पूर्णाङ्क ofs = ((c * 8 + bit_pos) % a8 + bit_आकार + a8 - 1) / a8;
                    यदि (ofs > आकार / align)
                        गच्छ new_क्षेत्रम्;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                यदि (आकार == 8 && bit_आकार <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, आकार = 4;

                यावत् (bit_pos >= align * 8)
                    c += align, bit_pos -= align * 8;
                विस्थापनम् = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		यदि (f->v & SYM_FIRST_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } अन्यथा {
		bt = f->type.t & VT_BTYPE;
		यदि ((bit_pos + bit_आकार > आकार * 8)
                    || (bit_आकार > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    विस्थापनम् = c;
		    bit_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    यदि (bit_आकार || पूर्व_bit_आकार)
		        c += आकार;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		यदि (bit_आकार == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                पूर्व_bit_आकार = bit_आकार;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_सरणम्))
		        | (bit_pos << VT_STRUCT_सरणम्);
	    bit_pos += bit_आकार;
	}
	यदि (align > maxalign)
	    maxalign = align;

#यदि_परिभाषितम् BF_DEBUG
	प्रारूप_लिख("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_क्षेत्रम्, रिक्त), विस्थापनम्, आकार, align);
	यदि (f->type.t & VT_BITFIELD) {
	    प्रारूप_लिख(" pos %-2d bits %-2d",
                    BIT_POS(f->type.t),
                    BIT_आकार(f->type.t)
                    );
	}
	प्रारूप_लिख("\n");
#यदि_अन्तः

        f->c = विस्थापनम्;
	f->r = 0;
    }

    यदि (pcc)
        c += (bit_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    यदि (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    यदि (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        यदि (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#यदि_परिभाषितम् BF_DEBUG
    प्रारूप_लिख("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#यदि_अन्तः

    /* check whether we can access bitfields by their type */
    प्रति (f = type->ref->अग्र; f; f = f->अग्र) {
        पूर्णाङ्क s, px, cx, c0;
        CType t;

        यदि (0 == (f->type.t & VT_BITFIELD))
            अनुवर्त;
        f->type.ref = f;
        f->auxtype = -1;
        bit_आकार = BIT_आकार(f->type.t);
        यदि (bit_आकार == 0)
            अनुवर्त;
        bit_pos = BIT_POS(f->type.t);
        आकार = type_आकार(&f->type, &align);

        यदि (bit_pos + bit_आकार <= आकार * 8 && f->c + आकार <= c
#यदि_परिभाषितम् TCC_TARGET_ARM
            && !(f->c & (align - 1))
#यदि_अन्तः
            )
            अनुवर्त;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        प्रति (;;) {
            px = f->c * 8 + bit_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            यदि (c0 == cx)
                भङ्ग;
            s = (px + bit_आकार + 7) >> 3;
            यदि (s > 4) {
                t.t = VT_LLONG;
            } अन्यथा यदि (s > 2) {
                t.t = VT_INT;
            } अन्यथा यदि (s > 1) {
                t.t = VT_SHORT;
            } अन्यथा {
                t.t = VT_BYTE;
            }
            s = type_आकार(&t, &align);
            c0 = cx;
        }

        यदि (px + bit_आकार <= s * 8 && cx + s <= c
#यदि_परिभाषितम् TCC_TARGET_ARM
            && !(cx & (align - 1))
#यदि_अन्तः
            ) {
            /* update offset and bit position */
            f->c = cx;
            bit_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_सरणम्))
		        | (bit_pos << VT_STRUCT_सरणम्);
            यदि (s != आकार)
                f->auxtype = t.t;
#यदि_परिभाषितम् BF_DEBUG
            प्रारूप_लिख("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_क्षेत्रम्, रिक्त),
                cx, s, align, px, bit_आकार);
#यदि_अन्तः
        } अन्यथा {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#यदि_परिभाषितम् BF_DEBUG
            प्रारूप_लिख("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_क्षेत्रम्, रिक्त));
#यदि_अन्तः
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
स्थिर पूर्णाङ्क अन्तर्_range(दीर्घ दीर्घ n, पूर्णाङ्क t)
{
    अचिह्नित दीर्घ दीर्घ m = (1ULL << (btype_आकार(t & VT_BTYPE) * 8 - 1)) - 1;
    यदि (t & VT_UNSIGNED)
        प्रत्यागम n <= (m << 1) + 1;
    प्रत्यागम n >= -(दीर्घ दीर्घ)m - 1 && n <= (दीर्घ दीर्घ)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
स्थिर शून्य struct_decl(CType *type, पूर्णाङ्क u)
{
    पूर्णाङ्क v, c, आकार, align, flexible;
    पूर्णाङ्क bit_आकार, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    स्मृतिं_पूरय(&ad, 0, परिमाण ad);
    अग्र();
    parse_attribute(&ad);

    v = 0;
    यदि (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, अग्र();

    bt = ut = 0;
    यदि (u == VT_ENUM) {
        ut = VT_INT;
        यदि (tok == ':') { /* C2x enum : <type> ... */
            अग्र();
            यदि (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    यदि (v) {
        /* struct already defined ? return it */
        s = struct_find(v);
        यदि (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            यदि (u == s->type.t)
                गच्छ do_decl;
            यदि (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                गच्छ do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, रिक्त));
        }
    } अन्यथा {
        यदि (tok != '{')
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

    यदि (tok == '{') {
        अग्र();
        यदि (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->अग्र;
        यदि (u == VT_ENUM) {
            दीर्घ दीर्घ ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            यदि (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            प्रति(;;) {
                v = tok;
                यदि (v < TOK_UIDENT)
                    expect("identifier");
                अग्र();
                यदि (tok == '=') {
                    अग्र();
		    ll = व्यञ्जकम्_const64();
                }
                यदि (bt && !अन्तर्_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, रिक्त));
                ss = sym_प्रक्षिप(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->अग्र;
                यदि (ll < nl)
                    nl = ll;
                यदि (ll > pl)
                    pl = ll;
                यदि (tok != ',')
                    भङ्ग;
                अग्र();
                ll++;
                /* NOTE: we accept a trailing comma */
                यदि (tok == '}')
                    भङ्ग;
            }
            skip('}');

            यदि (bt) {
                t.t = bt;
                s->c = 2;
                गच्छ enum_समाप्तम्;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            यदि (nl >= 0) {
                यदि (pl != (अचिह्नित)pl)
                    t.t = (LONG_आकार==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } अन्यथा यदि (pl != (पूर्णाङ्क)pl || nl != (पूर्णाङ्क)nl)
                t.t = (LONG_आकार==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            प्रति (ss = s->अग्र; ss; ss = ss->अग्र) {
                ll = ss->enum_val;
                यदि (ll == (पूर्णाङ्क)ll) /* default is int if it fits */
                    अनुवर्त;
                यदि (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    यदि (ll == (अचिह्नित)ll)
                        अनुवर्त;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_आकार==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_समाप्तम्:
            s->type.t = type->t = t.t | VT_ENUM;

        } अन्यथा {
            c = 0;
            flexible = 0;
            यावत् (tok != '}') {
                यदि (!parse_btype(&btype, &ad1, 0)) {
                    यदि (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        अनुवर्त;
                    }
		    skip(';');
		    अनुवर्त;
		}
                यावत् (1) {
		    यदि (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, रिक्त));
                    bit_आकार = -1;
                    v = 0;
                    type1 = btype;
                    यदि (tok != ':') {
			यदि (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_प्रत्यक्षम्);
                        यदि (v == 0) {
                    	    यदि ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    अन्यथा {
				पूर्णाङ्क v = btype.ref->v;
				यदि ((v & ~SYM_STRUCT) < SYM_FIRST_ANOM) {
				    यदि (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        यदि (type_आकार(&type1, &align) < 0) {
			    यदि ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    अन्यथा
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, रिक्त));
                        }
                        यदि ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, रिक्त));
                    }
                    यदि (tok == ':') {
                        अग्र();
                        bit_आकार = व्यञ्जकम्_const();
                        /* XXX: handle v = 0 case for messages */
                        यदि (bit_आकार < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, रिक्त));
                        यदि (v && bit_आकार == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, रिक्त));
			parse_attribute(&ad1);
                    }
                    आकार = type_आकार(&type1, &align);
                    यदि (bit_आकार >= 0) {
                        bt = type1.t & VT_BTYPE;
                        यदि (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = आकार * 8;
                        यदि (bit_आकार > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, रिक्त));
                        } अन्यथा यदि (bit_आकार == bsize
				    && !*tcc_state->pack_राशिः_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } अन्यथा यदि (bit_आकार == 64) {
                            tcc_error("field width 64 not implemented");
                        } अन्यथा {
                            type1.t = (type1.t & ~VT_STRUCT_आवरणम्)
                                | VT_BITFIELD
                                | ((अचिह्नित)bit_आकार << (VT_STRUCT_सरणम् + 6));
                        }
                    }
                    यदि (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    यदि (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 bit_आकार >= 0)) {
		        v = anon_sym++;
		    }
                    यदि (v) {
                        ss = sym_प्रक्षिप(v | SYM_क्षेत्रम्, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->अग्र;
                    }
                    यदि (tok == ';' || tok == TOK_EOF)
                        भङ्ग;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            यदि (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        यदि (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

स्थिर शून्य sym_गन्तव्यम्_attr(AttributeDef *ad, Sym *s)
{
    merge_symattr(&ad->a, &s->a);
    merge_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
स्थिर शून्य parse_btype_qualify(CType *type, पूर्णाङ्क qualifiers)
{
    यावत् (type->t & VT_ARRAY) {
        type->ref = sym_प्रक्षिप(SYM_क्षेत्रम्, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    यदि (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
स्थिर पूर्णाङ्क parse_btype(CType *type, AttributeDef *ad, पूर्णाङ्क ignore_label)
{
    पूर्णाङ्क t, u, bt, st, type_प्राप्तम्, typespec_प्राप्तम्, g, n;
    Sym *s;
    CType type1;

    स्मृतिं_पूरय(ad, 0, परिमाण(AttributeDef));
    type_प्राप्तम् = 0;
    typespec_प्राप्तम् = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = रिक्त;

    यावत्(1) {
        विकल्प(tok) {
        पक्ष TOK_EXTENSION:
            /* currently, we really ignore extension */
            अग्र();
            अनुवर्त;

            /* basic types */
        पक्ष TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            अग्र();
        basic_type1:
            यदि (u == VT_SHORT || u == VT_LONG) {
                यदि (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } अन्यथा {
                यदि (bt != -1 || (st != -1 && u != VT_INT))
                    गच्छ tmbt;
                यदि ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    गच्छ tmbt;
                bt = u;
            }
            यदि (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_प्राप्तम् = 1;
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
              अग्र();
              skip('(');
              स्मृतिं_पूरय(&ad1, 0, परिमाण(AttributeDef));
              यदि (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  यदि (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  अन्यथा
                    type_आकार(&type1, &n);
              } अन्यथा {
                  n = व्यञ्जकम्_const();
                  यदि (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            अनुवर्त;
        पक्ष TOK_LONG:
            यदि ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अन्यथा यदि ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } अन्यथा {
                u = VT_LONG;
                गच्छ basic_type;
            }
            अग्र();
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
            यदि ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } अन्यथा {
                u = VT_DOUBLE;
                गच्छ basic_type;
            }
            अग्र();
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
            अग्र();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            यदि (tok == '(') {
                parse_व्यञ्जकम्_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                यदि (type1.ref)
                    sym_गन्तव्यम्_attr(ad, type1.ref);
                गच्छ basic_type2;
            }
            भङ्ग;
        पक्ष TOK_CONST1:
        पक्ष TOK_CONST2:
        पक्ष TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            अग्र();
            भङ्ग;
        पक्ष TOK_VOLATILE1:
        पक्ष TOK_VOLATILE2:
        पक्ष TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            अग्र();
            भङ्ग;
        पक्ष TOK_SIGNED1:
        पक्ष TOK_SIGNED2:
        पक्ष TOK_SIGNED3:
            यदि ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            अग्र();
            typespec_प्राप्तम् = 1;
            भङ्ग;
        पक्ष TOK_RESTRICT1:
        पक्ष TOK_RESTRICT2:
        पक्ष TOK_RESTRICT3:
            t |= VT_RESTRICT;
            अग्र();
            भङ्ग;
        पक्ष TOK_पञ्जिकाकोशः:
        पक्ष TOK_AUTO:
            अग्र();
            भङ्ग;
        पक्ष TOK_UNSIGNED:
            यदि ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            अग्र();
            typespec_प्राप्तम् = 1;
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
            यदि (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            अग्र();
            भङ्ग;
        पक्ष TOK_INLINE1:
        पक्ष TOK_INLINE2:
        पक्ष TOK_INLINE3:
            t |= VT_INLINE;
            अग्र();
            भङ्ग;
        पक्ष TOK_NORETURN3:
            अग्र();
            ad->f.func_noreturn = 1;
            भङ्ग;
            /* GNUC attribute */
        पक्ष TOK_ATTRIBUTE1:
        पक्ष TOK_ATTRIBUTE2:
            parse_attribute(ad);
            यदि (ad->attr_बहुलकम्) {
                u = ad->attr_बहुलकम् -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            अनुवर्त;
            /* GNUC typeof */
        पक्ष TOK_TYPEOF1:
        पक्ष TOK_TYPEOF2:
        पक्ष TOK_TYPEOF3:
            अग्र();
            parse_व्यञ्जकम्_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            यदि (type1.ref) {
                sym_गन्तव्यम्_attr(ad, type1.ref);
                यदि (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            गच्छ basic_type2;
        पक्ष TOK_THREAD_LOCAL:
        पक्ष TOK___thread:
            यदि (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            अग्र();
            भङ्ग;
        स्वभाव:
            यदि (typespec_प्राप्तम्)
                गच्छ the_अन्तः;
            s = sym_find(tok);
            यदि (!s || !(s->type.t & VT_TYPEDEF))
                गच्छ the_अन्तः;

            n = tok, अग्र();
            यदि (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                गच्छ the_अन्तः;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            यदि (t)
                parse_btype_qualify(type, t);
            t = type->t;
            यदि (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_गन्तव्यम्_attr(ad, s);
            typespec_प्राप्तम् = 1;
            st = bt = -2;
            भङ्ग;
        }
        type_प्राप्तम् = 1;
    }
the_अन्तः:
    यदि (tcc_state->char_is_unsigned) {
        यदि ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    यदि (bt == VT_LONG)
        t |= LONG_आकार == 8 ? VT_LLONG : VT_INT;
#यदि_परिभाषितम् TCC_USING_DOUBLE_FOR_LDOUBLE
    यदि (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#यदि_अन्तः
    type->t = t;
    check_restrict_type(type);
    प्रत्यागम type_प्राप्तम्;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
स्थिर अन्तःस्थ शून्य convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    यदि ((pt->t & VT_BTYPE) == VT_FUNC) {
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
    प्रत्यागम parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
स्थिर पूर्णाङ्क asm_label_instr(शून्य)
{
    पूर्णाङ्क v;
    वर्ण *astr;

    अग्र();
    astr = parse_asm_str()->दत्त;
    skip(')');
#यदि_परिभाषितम् ASM_DEBUG
    प्रारूप_लिख("asm_alias: \"%s\"\n", astr);
#यदि_अन्तः
    v = tok_alloc_const(astr);
    प्रत्यागम v;
}

स्थिर पूर्णाङ्क post_type(CType *type, AttributeDef *ad, पूर्णाङ्क storage, पूर्णाङ्क td)
{
    पूर्णाङ्क n, l, t1, arg_आकार, align;
    Sym **plast, *s, *first, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = रिक्त;
    पूर्णाङ्क *vla_array_str = रिक्त;

    यदि (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        अग्र();
	यदि (TYPE_प्रत्यक्षम् == (td & (TYPE_प्रत्यक्षम्|TYPE_ABSTRACT)))
	  प्रत्यागम 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_राशिः ? &local_राशिः : &global_राशिः;
        ++local_scope;
        sr = sym_push2(ps, SYM_क्षेत्रम्, 0, 0);

	यदि (tok == ')')
	  l = 0;
	अन्यथा यदि (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	अन्यथा यदि (td & (TYPE_प्रत्यक्षम्|TYPE_ABSTRACT)) {
            sym_निष्कासय(ps, sr->पूर्व, 0);
            --local_scope;
	    merge_attr (ad, &ad1);
	    प्रत्यागम 0;
	} अन्यथा
	  l = FUNC_OLD;

        first = रिक्त;
        plast = &first;
        arg_आकार = 0;
        यदि (l) {
            प्रति(;;) {
                /* read param name and compute offset */
                यदि (l != FUNC_OLD) {
                    यदि ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        भङ्ग;
                    type_decl(&pt, &ad1, &n, TYPE_प्रत्यक्षम् | TYPE_ABSTRACT | TYPE_PARAM);
                    यदि ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    यदि (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_क्षेत्रम्;
                } अन्यथा {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = रिक्त;
                    अग्र();
                }
                यदि (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_आकार += (type_आकार(&pt, &align) + PTR_आकार - 1) / PTR_आकार;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_प्रक्षिप(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->अग्र;
                यदि (tok == ')')
                    भङ्ग;
                skip(',');
                यदि (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    अग्र();
                    भङ्ग;
                }
		यदि (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
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
        यदि (tok == '[') {
            अग्र();
            skip(']'); /* only handle simple "[]" */
            mk_pointer(type);
        }
        ad->f.func_तर्काः = arg_आकार;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->अग्र = first;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_निष्कासय(ps, sr, 1);
        --local_scope;

    } अन्यथा यदि (tok == '[') {
	पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
        पूर्णाङ्क array_qualifiers = 0;
        /* array definition */
        अग्र();
        n = -1;
        t1 = 0;
        यदि (td & TYPE_PARAM) यावत् (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    विकल्प (tok) {
	    पक्ष TOK_CONST1: पक्ष TOK_CONST2: पक्ष TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		अग्र();
		अनुवर्त;
	    पक्ष TOK_VOLATILE1: पक्ष TOK_VOLATILE2: पक्ष TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		अग्र();
		अनुवर्त;
	    पक्ष TOK_RESTRICT1: पक्ष TOK_RESTRICT2: पक्ष TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		अग्र();
		अनुवर्त;
	    पक्ष TOK_STATIC:
	    पक्ष '*':
		अग्र();
		अनुवर्त;
	    स्वभाव:
		भङ्ग;
	    }
            यदि (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_खण्डम्(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		अग्र();
	        gexpr();
		अन्तः_macro();
		अग्र();
		गच्छ check;
            }
            भङ्ग;

	} अन्यथा यदि (tok != ']') {
            यदि (!local_राशिः || (storage & VT_STATIC))
                vpushi(व्यञ्जकम्_const());
            अन्यथा {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            यदि ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                यदि (n < 0)
                    tcc_error("invalid array size");
            } अन्यथा {
                यदि (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_प्रत्यक्षम्|TYPE_ABSTRACT)) | TYPE_NEST);

        यदि ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        यदि ((type->t & VT_BTYPE) == VT_VOID
            || type_आकार(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        यदि (t1 & VT_VLA) {
            यदि (n < 0) {
		यदि  (td & TYPE_NEST)
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
        यदि (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_प्रक्षिप(SYM_क्षेत्रम्, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        यदि (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    यदि ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    अन्यथा
	        tok_str_free_str(vla_array_str);
	}
    }
    प्रत्यागम 1;
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

    यावत् (tok == '*') {
        qualifiers = 0;
    redo:
        अग्र();
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
	यदि (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    यदि (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	यदि (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} अन्यथा
	  गच्छ abstract;
    } अन्यथा यदि (tok >= TOK_IDENT && (td & TYPE_प्रत्यक्षम्)) {
	/* type identifier */
	*v = tok;
	अग्र();
    } अन्यथा {
  abstract:
	यदि (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_प्रत्यक्षम्|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    प्रत्यागम ret;
}

/* indirection with full error checking and bound check */
ST_FUNC शून्य indir(शून्य)
{
    यदि ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        यदि ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            प्रत्यागम;
        expect("pointer");
    }
    यदि (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    यदि (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#यदि_अन्तः
    }
}

/* pass a parameter to a function and do type checking and casting */
स्थिर शून्य gfunc_param_typed(Sym *func, Sym *arg)
{
    पूर्णाङ्क func_type;
    CType type;

    func_type = func->f.func_type;
    यदि (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == रिक्त)) {
        /* default casting : only need to convert float to double */
        यदि ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } अन्यथा यदि (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } अन्यथा यदि (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } अन्यथा यदि (arg == रिक्त) {
        tcc_error("too many arguments to function");
    } अन्यथा {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_नियोजय_cast(&type);
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
    यदि (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } अन्यथा {
        व्यञ्जकम्_type(type, gexpr);
    }
    skip(')');
}

स्थिर शून्य parse_type(CType *type)
{
    AttributeDef ad;
    पूर्णाङ्क n;

    यदि (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

स्थिर शून्य parse_builtin_params(पूर्णाङ्क nc, ध्रुव वर्ण *तर्काः)
{
    वर्ण c, sep = '(';
    CType type;
    यदि (nc)
        nocode_wanted++;
    अग्र();
    यदि (*तर्काः == 0)
	skip(sep);
    यावत् ((c = *तर्काः++)) {
	skip(sep);
	sep = ',';
        यदि (c == 't') {
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
                type.t = VT_आकार_T;
                भङ्ग;
	    स्वभाव:
                भङ्ग;
	}
        gen_नियोजय_cast(&type);
    }
    skip(')');
    यदि (nc)
        nocode_wanted--;
}

स्थिर शून्य parse_atomic(पूर्णाङ्क atok)
{
    पूर्णाङ्क आकार, align, arg, t, save = 0;
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
    ध्रुव वर्ण *प्रतिरूपम् = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = रिक्त;
    आकार = 0; /* pacify compiler */
    अग्र();
    skip('(');
    प्रति (arg = 0;;) {
        व्यञ्जकम्_eq();
        विकल्प (प्रतिरूपम्[arg]) {
        पक्ष 'a':
        पक्ष 'A':
            atom_ptr = &vtop->type;
            यदि ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            आकार = type_आकार(atom, &align);
            यदि (आकार > 8
                || (आकार & (आकार - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_आकार(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            भङ्ग;

        पक्ष 'p':
            यदि ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_आकार(pointed_type(&vtop->type), &align) != आकार)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_नियोजय_cast(atom_ptr);
            भङ्ग;
        पक्ष 'v':
            gen_नियोजय_cast(atom);
            भङ्ग;
        पक्ष 'l':
            indir();
            gen_नियोजय_cast(atom);
            भङ्ग;
        पक्ष 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            भङ्ग;
        पक्ष 'm':
            gen_नियोजय_cast(&int_type);
            भङ्ग;
        पक्ष 'b':
            ct.t = VT_BOOL;
            gen_नियोजय_cast(&ct);
            भङ्ग;
        }
        यदि ('.' == प्रतिरूपम्[++arg])
            भङ्ग;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    विकल्प (प्रतिरूपम्[arg + 1]) {
    पक्ष 'b':
        ct.t = VT_BOOL;
        भङ्ग;
    पक्ष 'v':
        ct = *atom;
        भङ्ग;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), आकार);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    यदि (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#यदि_परिभाषितम् PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अन्यथा
        vtop->type.t = VT_INT;
#यदि_अन्तः
    }
    gen_cast(&ct);
    यदि (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC शून्य unary(शून्य)
{
    पूर्णाङ्क n, t, align, आकार, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    यदि (debug_modes)
        tcc_debug_पङ्क्तिः(tcc_state), tcc_tcov_check_पङ्क्तिः (tcc_state, 1);

    type.ref = रिक्त;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_अग्र:
    विकल्प(tok) {
    पक्ष TOK_EXTENSION:
        अग्र();
        गच्छ tok_अग्र;
    पक्ष TOK_LCHAR:
#यदि_परिभाषितम् TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        गच्छ प्रक्षिप_tokc;
#यदि_अन्तः
    पक्ष TOK_CINT:
    पक्ष TOK_CCHAR: 
	t = VT_INT;
 प्रक्षिप_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        अग्र();
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
#यदि_परिभाषितम् TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#अन्यथा
        t = VT_LDOUBLE;
#यदि_अन्तः
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CLONG:
        t = (LONG_आकार == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK_CULONG:
        t = (LONG_आकार == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	गच्छ प्रक्षिप_tokc;
    पक्ष TOK___FUNCTION__:
        यदि (!gnu_ext)
            गच्छ tok_identifier;
        /* fall thru */
    पक्ष TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.दत्त = tokcstr.दत्त;
        गच्छ case_TOK_STR;
    पक्ष TOK_LSTR:
#यदि_परिभाषितम् TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#अन्यथा
        t = VT_INT;
#यदि_अन्तः
        गच्छ str_init;
    पक्ष TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        यदि (tcc_state->warn_write_वाक्यानि & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        स्मृतिं_पूरय(&ad, 0, परिमाण(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        भङ्ग;
    पक्ष TOK_SOTYPE:
    पक्ष '(':
        t = tok;
        अग्र();
        /* cast ? */
        यदि (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            यदि (tok == '{') {
                    /* data is allocated locally by default */
                यदि (global_व्यञ्जकम्)
                    r = VT_CONST;
                अन्यथा
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                यदि (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                स्मृतिं_पूरय(&ad, 0, परिमाण(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } अन्यथा यदि (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                प्रत्यागम;
            } अन्यथा {
                unary();
                gen_cast(&type);
            }
        } अन्यथा यदि (tok == '{') {
	    पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
            यदि (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            यदि (0 == local_scope)
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
            खण्डम्(STMT_व्यञ्जकम्);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            यदि (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } अन्यथा {
            gexpr();
            skip(')');
        }
        भङ्ग;
    पक्ष '*':
        अग्र();
        unary();
        indir();
        भङ्ग;
    पक्ष '&':
        अग्र();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        यदि ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        यदि (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_pointer(&vtop->type);
        gaddrof();
        भङ्ग;
    पक्ष '!':
        अग्र();
        unary();
        gen_test_zero(TOK_EQ);
        भङ्ग;
    पक्ष '~':
        अग्र();
        unary();
        vpushi(-1);
        gen_op('^');
        भङ्ग;
    पक्ष '+':
        अग्र();
        unary();
        यदि ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	यदि (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        भङ्ग;
    पक्ष TOK_SIZEOF:
    पक्ष TOK_ALIGNOF1:
    पक्ष TOK_ALIGNOF2:
    पक्ष TOK_ALIGNOF3:
        t = tok;
        अग्र();
        यदि (tok == '(')
            tok = TOK_SOTYPE;
        व्यञ्जकम्_type(&type, unary);
        यदि (t == TOK_SIZEOF) {
            vpush_type_आकार(&type, &align);
            gen_cast_s(VT_आकार_T);
        } अन्यथा {
            type_आकार(&type, &align);
            s = रिक्त;
            यदि (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            यदि (s && s->a.aligned)
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
    पक्ष TOK_builtin_वृणु_व्यञ्जकम्:
	{
	    int64_t c;
	    अग्र();
	    skip('(');
	    c = व्यञ्जकम्_const64();
	    skip(',');
	    यदि (!c) {
		nocode_wanted++;
	    }
	    व्यञ्जकम्_eq();
	    यदि (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    यदि (c) {
		nocode_wanted++;
	    }
	    व्यञ्जकम्_eq();
	    यदि (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        भङ्ग;
    पक्ष TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	यदि ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
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
        संहिता_OFF();
        भङ्ग;
    पक्ष TOK_builtin_frame_स्थानाङ्कः:
    पक्ष TOK_builtin_return_स्थानाङ्कः:
        {
            पूर्णाङ्क tok1 = tok;
            पूर्णाङ्क level;
            अग्र();
            skip('(');
            level = व्यञ्जकम्_const();
            यदि (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            यावत् (level--) {
#यदि_परिभाषितम् TCC_TARGET_RISCV64
                vpushi(2*PTR_आकार);
                gen_op('-');
#यदि_अन्तः
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            यदि (tok1 == TOK_builtin_return_स्थानाङ्कः) {
                // assume return address is just above frame pointer on stack
#यदि_परिभाषितम् TCC_TARGET_ARM
                vpushi(2*PTR_आकार);
                gen_op('+');
#नोचेद्यदि defined TCC_TARGET_RISCV64
                vpushi(PTR_आकार);
                gen_op('-');
#अन्यथा
                vpushi(PTR_आकार);
                gen_op('+');
#यदि_अन्तः
                mk_pointer(&vtop->type);
                indir();
            }
        }
        भङ्ग;
#यदि_परिभाषितम् TCC_TARGET_RISCV64
    पक्ष TOK_builtin_va_start:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        यदि (r == VT_LLOCAL)
            r = VT_LOCAL;
        यदि (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_start();
	vstore();
        भङ्ग;
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_X86_64
#यदि_परिभाषितम् TCC_TARGET_PE
    पक्ष TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        यदि (r == VT_LLOCAL)
            r = VT_LOCAL;
        यदि (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        भङ्ग;
#अन्यथा
    पक्ष TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	भङ्ग;
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_ARM64
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
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_ARM64
    पक्ष TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        भङ्ग;
    }
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_RISCV64
    पक्ष TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        भङ्ग;
    }
#यदि_अन्तः

    /* atomic operations */
    पक्ष TOK___atomic_store:
    पक्ष TOK_atomic_आरोपय:
    पक्ष TOK___atomic_exchange:
    पक्ष TOK___atomic_compare_exchange:
    पक्ष TOK_atomic_fetch_सङ्कलय:
    पक्ष TOK___atomic_fetch_sub:
    पक्ष TOK___atomic_fetch_or:
    पक्ष TOK___atomic_fetch_xor:
    पक्ष TOK___atomic_fetch_and:
    पक्ष TOK___atomic_fetch_nand:
    पक्ष TOK_atomic_सङ्कलय_fetch:
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
        अग्र();
        unary();
        inc(0, t);
        भङ्ग;
    पक्ष '-':
        अग्र();
        unary();
	यदि (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} अन्यथा {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        भङ्ग;
    पक्ष TOK_LAND:
        यदि (!gnu_ext)
            गच्छ tok_identifier;
        अग्र();
        /* allow to take the address of a label */
        यदि (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        यदि (!s) {
            s = label_प्रक्षिप(&global_label_राशिः, tok, LABEL_FORWARD);
        } अन्यथा {
            यदि (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        यदि ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        अग्र();
        भङ्ग;

    पक्ष TOK_GENERIC:
    {
	CType controlling_type;
	पूर्णाङ्क has_default = 0;
	पूर्णाङ्क has_मेलनम् = 0;
	पूर्णाङ्क learn = 0;
	TokenString *str = रिक्त;
	पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_आवरणम्;

        अग्र();
	skip('(');
	व्यञ्जकम्_type(&controlling_type, व्यञ्जकम्_eq);
	convert_expression_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        प्रति (;;) {
	    learn = 0;
	    skip(',');
	    यदि (tok == TOK_DEFAULT) {
		यदि (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		यदि (!has_मेलनम्)
		    learn = 1;
		अग्र();
	    } अन्यथा {
		पूर्णाङ्क v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		यदि (compare_types(&controlling_type, &type, 0)) {
		    यदि (has_मेलनम्) {
		      tcc_error("type match twice");
		    }
		    has_मेलनम् = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    यदि (learn) {
		यदि (str)
		    tok_str_free(str);
		skip_or_save_खण्डम्(&str);
	    } अन्यथा {
		skip_or_save_खण्डम्(रिक्त);
	    }
	    यदि (tok == ')')
		भङ्ग;
	}
	यदि (!str) {
	    वर्ण buf[60];
	    type_गन्तव्यम्_str(buf, परिमाण buf, &controlling_type, रिक्त);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	अग्र();
	व्यञ्जकम्_eq();
	यदि (tok != TOK_EOF)
	    expect(",");
	अन्तः_macro();
        अग्र();
	भङ्ग;
    }
    // special qnan , snan and infinity values
    पक्ष TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        अग्र();
        भङ्ग;
    पक्ष TOK___SNAN__:
	n = 0x7f800001;
	गच्छ special_math_val;
    पक्ष TOK___INF__:
	n = 0x7f800000;
	गच्छ special_math_val;

    स्वभाव:
    tok_identifier:
        यदि (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        अग्र();
        s = sym_find(t);
        यदि (!s || IS_ASM_SYM(s)) {
            ध्रुव वर्ण *name = get_tok_str(t, रिक्त);
            यदि (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            यदि (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        यदि ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        यदि (r & VT_SYM) {
            vtop->c.i = 0;
#यदि_परिभाषितम् TCC_TARGET_PE
            यदि (s->a.dllimport) {
                mk_pointer(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#यदि_अन्तः
        } अन्यथा यदि (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        भङ्ग;
    }
    
    /* post operations */
    यावत् (1) {
        यदि (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            अग्र();
        } अन्यथा यदि (tok == '.' || tok == TOK_ARROW) {
            पूर्णाङ्क qualifiers, cumofs;
            /*क्षेत्रम्*/ 
            यदि (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            अग्र();
	    s = find_क्षेत्रम्(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_pointer_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            यदि (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            यदि (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                यदि (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#यदि_अन्तः
            }
            अग्र();
        } अन्यथा यदि (tok == '[') {
            अग्र();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } अन्यथा यदि (tok == '(') {
            SValue ret;
            Sym *sa;
            पूर्णाङ्क nb_तर्काः, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            यदि ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                यदि ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    यदि ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        गच्छ error_func;
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
            nb_तर्काः = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            यदि ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                यदि (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    आकार = type_आकार(&s->type, &align);
#यदि_परिभाषितम् TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                यदि (आकार < 16)
                    यावत् (आकार & (आकार - 1))
                        आकार = (आकार | (आकार - 1)) + 1;
#यदि_अन्तः
                    loc = (loc - आकार) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
                    यदि (tcc_state->do_bounds_check)
                        --loc;
#यदि_अन्तः
                    ret.c = vtop->c;
                    यदि (ret_nregs < 0)
                      vtop--;
                    अन्यथा
                      nb_तर्काः++;
                }
            } अन्यथा {
                ret_nregs = 1;
                ret.type = s->type;
            }

            यदि (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = रिक्त;
            यदि (tok != ')') {
                r = tcc_state->reverse_funcargs;
                प्रति(;;) {
                    यदि (r) {
                        skip_or_save_खण्डम्(&p2);
                        p2->पूर्व = p, p = p2;
                    } अन्यथा {
                        व्यञ्जकम्_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_तर्काः++;
                    यदि (sa)
                        sa = sa->अग्र;
                    यदि (tok == ')')
                        भङ्ग;
                    skip(',');
                }
            }
            यदि (sa)
                tcc_error("too few arguments to function");

            यदि (p) { /* with reverse_funcargs */
                प्रति (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    कुरु {
                        sa = sa->अग्र, p2 = p2->पूर्व;
                    } यावत् (p2 && sa);
                    p2 = p->पूर्व;
                    begin_macro(p, 1), अग्र();
                    व्यञ्जकम्_eq();
                    gfunc_param_typed(s, sa);
                    अन्तः_macro();
                }
                vrev(n);
            }

            अग्र();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_तर्काः);

            यदि (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#यदि_परिभाषितम् TCC_TARGET_RISCV64
                arch_transfer_ret_regs(1);
#यदि_अन्तः
            } अन्यथा {
                /* return value */
                n = ret_nregs;
                यावत् (n > 1) {
                    पूर्णाङ्क rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    प्रति (r = 0; r < NB_REGS; ++r)
                        यदि (reg_classes[r] & rc)
                            भङ्ग;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                यदि (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    पूर्णाङ्क addr, विस्थापनम्;

                    आकार = type_आकार(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    आकार = (आकार + regsize - 1) & -regsize;
                    यदि (ret_align > align)
                        align = ret_align;
                    loc = (loc - आकार) & -align;
                    addr = loc;
                    विस्थापनम् = 0;
                    प्रति (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + विस्थापनम्);
                        vswap();
                        vstore();
                        vtop--;
                        यदि (--ret_nregs == 0)
                          भङ्ग;
                        विस्थापनम् += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                यदि (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#यदि_परिभाषितम् PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#अन्यथा
                    vtop->type.t = VT_INT;
#यदि_अन्तः
                }
            }
            यदि (s->f.func_noreturn) {
                यदि (debug_modes)
	            tcc_tcov_खण्डम्_अन्तः(tcc_state, -1);
                संहिता_OFF();
	    }
        } अन्यथा {
            भङ्ग;
        }
    }
}

#यदि_अपरिभाषितम् precedence_parser /* original top-down parser */

स्थिर शून्य व्यञ्जकम्_prod(शून्य)
{
    पूर्णाङ्क t;

    unary();
    यावत् ((t = tok) == '*' || t == '/' || t == '%') {
        अग्र();
        unary();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_योग(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_prod();
    यावत् ((t = tok) == '+' || t == '-') {
        अग्र();
        व्यञ्जकम्_prod();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_सरणम्(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_योग();
    यावत् ((t = tok) == TOK_SHL || t == TOK_SAR) {
        अग्र();
        व्यञ्जकम्_योग();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_cmp(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_सरणम्();
    यावत् (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        अग्र();
        व्यञ्जकम्_सरणम्();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_cmpeq(शून्य)
{
    पूर्णाङ्क t;

    व्यञ्जकम्_cmp();
    यावत् ((t = tok) == TOK_EQ || t == TOK_NE) {
        अग्र();
        व्यञ्जकम्_cmp();
        gen_op(t);
    }
}

स्थिर शून्य व्यञ्जकम्_and(शून्य)
{
    व्यञ्जकम्_cmpeq();
    यावत् (tok == '&') {
        अग्र();
        व्यञ्जकम्_cmpeq();
        gen_op('&');
    }
}

स्थिर शून्य व्यञ्जकम्_xor(शून्य)
{
    व्यञ्जकम्_and();
    यावत् (tok == '^') {
        अग्र();
        व्यञ्जकम्_and();
        gen_op('^');
    }
}

स्थिर शून्य व्यञ्जकम्_or(शून्य)
{
    व्यञ्जकम्_xor();
    यावत् (tok == '|') {
        अग्र();
        व्यञ्जकम्_xor();
        gen_op('|');
    }
}

स्थिर शून्य व्यञ्जकम्_landor(पूर्णाङ्क op);

स्थिर शून्य व्यञ्जकम्_land(शून्य)
{
    व्यञ्जकम्_or();
    यदि (tok == TOK_LAND)
        व्यञ्जकम्_landor(tok);
}

स्थिर शून्य व्यञ्जकम्_lor(शून्य)
{
    व्यञ्जकम्_land();
    यदि (tok == TOK_LOR)
        व्यञ्जकम्_landor(tok);
}

# define व्यञ्जकम्_landor_अग्र(op) op == TOK_LAND ? व्यञ्जकम्_or() : व्यञ्जकम्_land()
#अन्यथा /* defined precedence_parser */
# define व्यञ्जकम्_landor_अग्र(op) unary(), व्यञ्जकम्_infix(precedence(op) + 1)
# define व्यञ्जकम्_lor() unary(), व्यञ्जकम्_infix(1)

स्थिर पूर्णाङ्क precedence(पूर्णाङ्क tok)
{
    विकल्प (tok) {
        पक्ष TOK_LOR: प्रत्यागम 1;
        पक्ष TOK_LAND: प्रत्यागम 2;
	पक्ष '|': प्रत्यागम 3;
	पक्ष '^': प्रत्यागम 4;
	पक्ष '&': प्रत्यागम 5;
	पक्ष TOK_EQ: पक्ष TOK_NE: प्रत्यागम 6;
 relat: पक्ष TOK_ULT: पक्ष TOK_UGE: प्रत्यागम 7;
	पक्ष TOK_SHL: पक्ष TOK_SAR: प्रत्यागम 8;
	पक्ष '+': पक्ष '-': प्रत्यागम 9;
	पक्ष '*': पक्ष '/': पक्ष '%': प्रत्यागम 10;
	स्वभाव:
	    यदि (tok >= TOK_ULE && tok <= TOK_GT)
	        गच्छ relat;
	    प्रत्यागम 0;
    }
}
स्थिर अचिह्नित वर्ण prec[256];
स्थिर शून्य init_prec(शून्य)
{
    पूर्णाङ्क i;
    प्रति (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#परिभाषय precedence(i) ((अचिह्नित)i < 256 ? prec[i] : 0)

स्थिर शून्य व्यञ्जकम्_landor(पूर्णाङ्क op);

स्थिर शून्य व्यञ्जकम्_infix(पूर्णाङ्क p)
{
    पूर्णाङ्क t = tok, p2;
    यावत् ((p2 = precedence(t)) >= p) {
        यदि (t == TOK_LOR || t == TOK_LAND) {
            व्यञ्जकम्_landor(t);
        } अन्यथा {
            अग्र();
            unary();
            यदि (precedence(tok) > p2)
              व्यञ्जकम्_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#यदि_अन्तः

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
स्थिर पूर्णाङ्क condition_3way(शून्य)
{
    पूर्णाङ्क c = -1;
    यदि ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    प्रत्यागम c;
}

स्थिर शून्य व्यञ्जकम्_landor(पूर्णाङ्क op)
{
    पूर्णाङ्क t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    प्रति(;;) {
        c = f ? i : condition_3way();
        यदि (c < 0)
            save_regs(1), cc = 0;
        अन्यथा यदि (c != i)
            nocode_wanted++, f = 1;
        यदि (tok != op)
            भङ्ग;
        यदि (c < 0)
            t = gvtst(i, t);
        अन्यथा
            vpop();
        अग्र();
        व्यञ्जकम्_landor_अग्र(op);
    }
    यदि (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } अन्यथा {
        gvtst_समुच्चयः(i, t);
    }
}

स्थिर पूर्णाङ्क is_cond_bool(SValue *sv)
{
    यदि ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        प्रत्यागम (अचिह्नित)sv->c.i < 2;
    यदि (sv->r == VT_CMP)
        प्रत्यागम 1;
    प्रत्यागम 0;
}

स्थिर शून्य व्यञ्जकम्_cond(शून्य)
{
    पूर्णाङ्क tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    व्यञ्जकम्_lor();
    यदि (tok == '?') {
        अग्र();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        यदि (!g) {
            यदि (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } अन्यथा {
                vpop();
            }
        } अन्यथा यदि (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        यदि (c == 0)
          nocode_wanted++;
        यदि (!g)
          gexpr();

        यदि ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        यदि (g) {
            u = tt;
        } अन्यथा यदि (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } अन्यथा
          u = 0;

        यदि (c == 0)
          nocode_wanted--;
        यदि (c == 1)
          nocode_wanted++;
        skip(':');
        व्यञ्जकम्_cond();

        यदि ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_pointer(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        यदि (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        यदि (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_समुच्चयः(0, t1);
            gvtst_समुच्चयः(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            प्रत्यागम;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        यदि (c != 1) {
            gen_cast(&type);
            यदि (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        यदि (USING_TWO_शब्दाः(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        यदि (c < 0) {
            यदि (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        यदि (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
सङ्कार्यम्*/
        यदि (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            यदि (islv) {
                mk_pointer(&vtop->type);
                gaddrof();
            }
        }

        यदि (c < 0) {
            यदि (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        यदि (islv)
          indir();
    }
}

स्थिर शून्य व्यञ्जकम्_eq(शून्य)
{
    पूर्णाङ्क t;
    
    व्यञ्जकम्_cond();
    यदि ((t = tok) == '=' || TOK_नियोजय(t)) {
        test_lvalue();
        अग्र();
        यदि (t == '=') {
            व्यञ्जकम्_eq();
        } अन्यथा {
            vdup();
            व्यञ्जकम्_eq();
            gen_op(TOK_नियोजय_OP(t));
        }
        vstore();
    }
}

ST_FUNC शून्य gexpr(शून्य)
{
    व्यञ्जकम्_eq();
    यदि (tok == ',') {
        कुरु {
            vpop();
            अग्र();
            व्यञ्जकम्_eq();
        } यावत् (tok == ',');

        /* convert array & function to pointer */
        convert_expression_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        यदि ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            यदि (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
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
    यदि ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    प्रत्यागम c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC पूर्णाङ्क व्यञ्जकम्_const(शून्य)
{
    पूर्णाङ्क c;
    int64_t wc = व्यञ्जकम्_const64();
    c = wc;
    यदि (c != wc && (अचिह्नित)c != wc)
        tcc_error("constant exceeds 32 bit");
    प्रत्यागम c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#यदि_अपरिभाषितम् TCC_TARGET_ARM64
स्थिर शून्य gfunc_return(CType *func_type)
{
    यदि ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        पूर्णाङ्क ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        यदि (ret_nregs < 0) {
#यदि_परिभाषितम् TCC_TARGET_RISCV64
            arch_transfer_ret_regs(0);
#यदि_अन्तः
        } अन्यथा यदि (0 == ret_nregs) {
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
            पूर्णाङ्क आकार, addr, align, rc, n;
            आकार = type_आकार(func_type,&align);
            यदि (ret_nregs * regsize > आकार ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		यदि (ret_nregs * regsize > आकार)
		    आकार = ret_nregs * regsize;
		यदि (ret_align > align)
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
            प्रति (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_विस्थापनम्(regsize);
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
#यदि_अन्तः

स्थिर शून्य check_func_return(शून्य)
{
    यदि ((func_vt.t & VT_BTYPE) == VT_VOID)
        प्रत्यागम;
    यदि ((!वाक्यं_तुलय(funcname, "main") || func_old)
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

स्थिर पूर्णाङ्क case_cmp(uint64_t a, uint64_t b)
{
    यदि (cur_switch->sv.type.t & VT_UNSIGNED)
        प्रत्यागम a < b ? -1 : a > b;
    अन्यथा
        प्रत्यागम (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

स्थिर पूर्णाङ्क case_cmp_qs(ध्रुव शून्य *pa, ध्रुव शून्य *pb)
{
    प्रत्यागम case_cmp((*(संरचना case_t**)pa)->v1, (*(संरचना case_t**)pb)->v1);
}

स्थिर शून्य case_क्रमय(संरचना switch_t *sw)
{
    संरचना case_t **p;
    यदि (sw->n < 2)
        प्रत्यागम;
    शीघ्रं_क्रमय(sw->p, sw->n, परिमाण *sw->p, case_cmp_qs);
    p = sw->p;
    यावत् (p < sw->p + sw->n - 1) {
        यदि (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            पूर्णाङ्क l1 = p[0]->पङ्क्तिः, l2 = p[1]->पङ्क्तिः;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } अन्यथा यदि (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * परिमाण *p);
        } अन्यथा
            ++p;
    }
}

स्थिर पूर्णाङ्क gcase(संरचना case_t **आधारः, पूर्णाङ्क len, पूर्णाङ्क dsym)
{
    संरचना case_t *p;
    पूर्णाङ्क t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    यदि (t != VT_LLONG)
        t = VT_INT;
    यावत् (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = आधारः[l2];
        vdup(), vpush64(t, p->v2);
        यदि (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } अन्यथा {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            यदि (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            अन्यथा
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(आधारः, l2, dsym);
            gsym(e);
        }
        ++l2, आधारः += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    प्रत्यागम gjmp(dsym);
}

स्थिर शून्य अन्तः_switch(शून्य)
{
    संरचना switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->पूर्व;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
स्थिर शून्य save_lvalues(शून्य)
{
    SValue *sv = vtop;
    यावत् (sv >= vstack) {
        यदि (sv->sym && (sv->r & VT_LVAL)) {
            पूर्णाङ्क align, आकार = type_आकार(&sv->type, &align);
            पूर्णाङ्क r2, l = get_अस्थायी_local_var(आकार, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

स्थिर शून्य try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    प्रति (; cls != stop; cls = cls->अग्र) {
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

    यदि (!cur_scope->cl.s)
	प्रत्यागम;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_क्षेत्रम् : 0;
    प्रति (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->अग्र)
      ;
    प्रति (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->अग्र)
      ;
    प्रति (; cc != oc; cc = cc->अग्र, oc = oc->अग्र, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
स्थिर शून्य खण्डम्_cleanup(संरचना scope *o)
{
    पूर्णाङ्क jmp = 0;
    Sym *g, **pg;
    प्रति (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        यदि (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->अग्र;
            यदि (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            यदि (!o->cl.n)
                गच्छ remove_pending;
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

स्थिर शून्य vla_restore(पूर्णाङ्क loc)
{
    यदि (loc)
        gen_vla_sp_restore(loc);
}

स्थिर शून्य vla_leave(संरचना scope *o)
{
    संरचना scope *c = cur_scope, *v = रिक्त;
    प्रति (; c != o && c; c = c->पूर्व)
      यदि (c->vla.अङ्कः)
        v = c;
    यदि (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

स्थिर शून्य new_scope(संरचना scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->पूर्व = cur_scope;
    cur_scope = o;
    cur_scope->vla.अङ्कः = 0;

    /* record local declaration stack position */
    o->lstk = local_राशिः;
    o->llstk = local_label_राशिः;
    ++local_scope;
}

स्थिर शून्य पूर्व_scope(संरचना scope *o, पूर्णाङ्क is_व्यञ्जकम्)
{
    vla_leave(o->पूर्व);

    यदि (o->cl.s != o->पूर्व->cl.s)
        खण्डम्_cleanup(o->पूर्व);

    यदि (debug_modes)
        tcc_debug_अन्तः_scope(o->lstk, !is_व्यञ्जकम्);

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
    cur_scope = o->पूर्व;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
स्थिर शून्य leave_scope(संरचना scope *o)
{
    यदि (!o)
        प्रत्यागम;
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

स्थिर शून्य पूर्व_scope_s(संरचना scope *o)
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
    यदि (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    खण्डम्(0);
    co->bsym = b;
    यदि (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
स्थिर शून्य gexpr_decl(शून्य)
{
    पूर्णाङ्क v = decl(VT_JMP);
    यदि (v > 1 && tok != ';') {
        Sym *s = sym_find(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } अन्यथा {
        यदि (v)
            skip(';');
        gexpr();
    }
}

स्थिर शून्य खण्डम्(पूर्णाङ्क flags)
{
    पूर्णाङ्क a, b, c, d, e, t;
    संरचना scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    यदि (TOK_HAS_मानम्(t))
        गच्छ व्यञ्जकम्;
    अग्र();

    यदि (debug_modes)
        tcc_tcov_check_पङ्क्तिः (tcc_state, 0), tcc_tcov_खण्डम्_begin (tcc_state);

    यदि (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        खण्डम्(0);
        यदि (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            अग्र();
            खण्डम्(0);
            gsym(d); /* patch else jmp */
        } अन्यथा {
            gsym(a);
        }
        पूर्व_scope_s(&o);

    } अन्यथा यदि (t == TOK_WHILE) {
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

    } अन्यथा यदि (t == '{') {
        यदि (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        यावत् (tok == TOK_LABEL) {
            कुरु {
                अग्र();
                यदि (tok < TOK_UIDENT)
                    expect("label identifier");
                label_प्रक्षिप(&local_label_राशिः, tok, LABEL_DECLARED);
                अग्र();
            } यावत् (tok == ',');
            skip(';');
        }

        यावत् (tok != '}') {
	    decl(VT_LOCAL);
            यदि (tok != '}') {
                खण्डम्(flags | STMT_COMPOUND);
            }
        }

        पूर्व_scope(&o, flags & STMT_व्यञ्जकम्);
        यदि (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        यदि (local_scope)
            अग्र();
        अन्यथा यदि (!nocode_wanted)
            check_func_return();

    } अन्यथा यदि (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        यदि (tok != ';') {
            gexpr();
            यदि (b) {
                gen_नियोजय_cast(&func_vt);
            } अन्यथा {
                यदि (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } अन्यथा यदि (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } अन्यथा यदि (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(मूलम्_scope);
        यदि (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        यदि (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        यदि (debug_modes)
	    tcc_tcov_खण्डम्_अन्तः (tcc_state, -1);
        संहिता_OFF();

    } अन्यथा यदि (t == TOK_BREAK) {
        /* compute jump */
        यदि (!cur_scope->bsym)
            tcc_error("cannot break");
        यदि (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        अन्यथा
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } अन्यथा यदि (t == TOK_CONTINUE) {
        /* compute jump */
        यदि (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } अन्यथा यदि (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        यदि (tok != ';') {
            /* c99 for-loop init decl? */
            यदि (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        यदि (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        यदि (tok != ')') {
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

    } अन्यथा यदि (t == TOK_DO) {
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

    } अन्यथा यदि (t == TOK_SWITCH) {
        संरचना switch_t *sw;

        sw = tcc_mallocz(परिमाण *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->पूर्व = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        यदि (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, रिक्त);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        पूर्व_scope_s(&o);
        यदि (sw->nocode_wanted)
            गच्छ skip_switch;
        case_क्रमय(sw);
        sw->bsym = रिक्त; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        यदि (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        अन्यथा
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        अन्तः_switch();

    } अन्यथा यदि (t == TOK_CASE) {
        संरचना case_t *cr;
        यदि (!cur_switch)
            expect("switch");
        cr = tcc_malloc(परिमाण(संरचना case_t));
        dynarray_सङ्कलय(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(व्यञ्जकम्_const64(), t);
        यदि (tok == TOK_DOTS && gnu_ext) {
            अग्र();
            cr->v2 = value64(व्यञ्जकम्_const64(), t);
            यदि (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        यदि (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->पङ्क्तिः = file->पङ्क्तिः_अङ्कः;
        skip(':');
        गच्छ खण्डम्_after_label;

    } अन्यथा यदि (t == TOK_DEFAULT) {
        यदि (!cur_switch)
            expect("switch");
        यदि (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        गच्छ खण्डम्_after_label;

    } अन्यथा यदि (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        यदि (tok == '*' && gnu_ext) {
            /* computed goto */
            अग्र();
            gexpr();
            यदि ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } अन्यथा यदि (tok >= TOK_UIDENT) {
	    s = label_find(tok);
	    /* put forward definition if needed */
            यदि (!s)
              s = label_प्रक्षिप(&global_label_राशिः, tok, LABEL_FORWARD);
            अन्यथा यदि (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    यदि (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		यदि (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_क्षेत्रम्, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->अग्र, SYM_क्षेत्रम्, 0, 0);
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

    } अन्यथा यदि (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } अन्यथा {
        यदि (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    अग्र();
            s = label_find(t);
            यदि (s) {
                यदि (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, रिक्त));
                s->r = LABEL_DEFINED;
		यदि (s->अग्र) {
		    Sym *pcl; /* pending cleanup goto */
		    प्रति (pcl = s->अग्र; pcl; pcl = pcl->पूर्व)
		      gsym(pcl->jnext);
		    sym_निष्कासय(&s->अग्र, रिक्त, 0);
		} अन्यथा
		  gsym(s->jnext);
            } अन्यथा {
                s = label_प्रक्षिप(&global_label_राशिः, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    खण्डम्_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(रिक्त);

            यदि (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            यदि (tok != '}') {
                यदि (0 == (flags & STMT_COMPOUND))
                    गच्छ again;
                /* C23: insert implicit null-statement whithin compound statement */
            } अन्यथा {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } अन्यथा {
            /* expression case */
            यदि (t != ';') {
                unget_tok(t);
    व्यञ्जकम्:
                यदि (flags & STMT_व्यञ्जकम्) {
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

    यदि (debug_modes)
        tcc_tcov_check_पङ्क्तिः (tcc_state, 0), tcc_tcov_खण्डम्_अन्तः (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
स्थिर शून्य skip_or_save_खण्डम्(TokenString **str)
{
    पूर्णाङ्क braces = tok == '{';
    पूर्णाङ्क level = 0;
    यदि (str)
      *str = tok_str_alloc();

    यावत् (1) {
	पूर्णाङ्क t = tok;
        यदि (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             भङ्ग;
	यदि (t == TOK_EOF) {
	     यदि (str || level > 0)
	       tcc_error("unexpected end of file");
	     अन्यथा
	       भङ्ग;
	}
	यदि (str)
	  tok_str_सङ्कलय_tok(*str);
	अग्र();
	यदि (t == '{' || t == '(' || t == '[') {
	    level++;
	} अन्यथा यदि (t == '}' || t == ')' || t == ']') {
	    level--;
	    यदि (level == 0 && braces && t == '}')
	      भङ्ग;
	}
    }
    यदि (str)
	tok_str_सङ्कलय(*str, TOK_EOF);
}

#परिभाषय व्यञ्जकम्_CONST 1
#परिभाषय व्यञ्जकम्_ANY   2

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
        यदि (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_FIRST_ANOM))
#यदि_परिभाषितम् TCC_TARGET_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#यदि_अन्तः
           )
            tcc_error("initializer element is not constant");
        भङ्ग;
    पक्ष व्यञ्जकम्_ANY:
        व्यञ्जकम्_eq();
        भङ्ग;
    }
}

#यदि 1
स्थिर शून्य init_assert(init_params *p, पूर्णाङ्क विस्थापनम्)
{
    यदि (p->sec ? !NODATA_WANTED && विस्थापनम् > p->sec->दत्त_विस्थापनम्
               : !nocode_wanted && विस्थापनम् > p->local_विस्थापनम्)
        tcc_आन्तरिकम्_error("initializer overflow");
}
#अन्यथा
#परिभाषय init_assert(sec, विस्थापनम्)
#यदि_अन्तः

/* put zeros for variable based init */
स्थिर शून्य init_putz(init_params *p, अचिह्नित दीर्घ c, पूर्णाङ्क आकार)
{
    init_assert(p, c + आकार);
    यदि (p->sec) {
        /* nothing to do because globals are already set to zero */
    } अन्यथा {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(आकार);
#यदि defined TCC_TARGET_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#यदि_अन्तः
        gfunc_call(3);
    }
}

#परिभाषय DIF_FIRST     1
#परिभाषय DIF_आकार_ONLY 2
#परिभाषय DIF_HAVE_ELEM 4
#परिभाषय DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
स्थिर शून्य decl_design_delrels(Section *sec, पूर्णाङ्क c, पूर्णाङ्क आकार)
{
    ElfW_Rel *rel, *rel2, *rel_अन्तः;
    यदि (!sec || !sec->reloc)
        प्रत्यागम;
    rel = rel2 = (ElfW_Rel*)sec->reloc->दत्त;
    rel_अन्तः = (ElfW_Rel*)(sec->reloc->दत्त + sec->reloc->दत्त_विस्थापनम्);
    यावत् (rel < rel_अन्तः) {
        यदि (rel->r_विस्थापनम् >= c && rel->r_विस्थापनम् < c + आकार) {
            sec->reloc->दत्त_विस्थापनम् -= परिमाण *rel;
        } अन्यथा {
            यदि (rel2 != rel)
                स्मृतिं_प्रतिलिख(rel2, rel, परिमाण *rel);
            ++rel2;
        }
        ++rel;
    }
}

स्थिर शून्य decl_design_flex(init_params *p, Sym *ref, पूर्णाङ्क सूचकांक)
{
    यदि (ref == p->flex_array_ref) {
        यदि (सूचकांक >= ref->c)
            ref->c = सूचकांक + 1;
    } अन्यथा यदि (ref->c < 0 && सूचकांक >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
स्थिर पूर्णाङ्क decl_designator(init_params *p, CType *type, अचिह्नित दीर्घ c,
                           Sym **cur_क्षेत्रम्, पूर्णाङ्क flags, पूर्णाङ्क al)
{
    Sym *s, *f;
    पूर्णाङ्क सूचकांक, सूचकांक_चरमः, align, l, nb_elems, elem_आकार;
    अचिह्नित दीर्घ corig = c;

    elem_आकार = 0;
    nb_elems = 1;

    यदि (flags & DIF_HAVE_ELEM)
        गच्छ no_designator;

    यदि (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, अग्र();
        यदि (tok == ':')
            गच्छ struct_क्षेत्रम्;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    यावत् (nb_elems == 1 && (tok == '[' || tok == '.')) {
        यदि (tok == '[') {
            यदि (!(type->t & VT_ARRAY))
                expect("array type");
            अग्र();
            सूचकांक = सूचकांक_चरमः = व्यञ्जकम्_const();
            यदि (tok == TOK_DOTS && gnu_ext) {
                अग्र();
                सूचकांक_चरमः = व्यञ्जकम्_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, सूचकांक_चरमः);
            यदि (सूचकांक < 0 || सूचकांक_चरमः >= s->c || सूचकांक_चरमः < सूचकांक)
	        tcc_error("index exceeds array bounds or range is empty");
            यदि (cur_क्षेत्रम्)
		(*cur_क्षेत्रम्)->c = सूचकांक_चरमः;
            type = pointed_type(type);
            elem_आकार = type_आकार(type, &align);
            c += सूचकांक * elem_आकार;
            nb_elems = सूचकांक_चरमः - सूचकांक + 1;
        } अन्यथा {
            पूर्णाङ्क cumofs;
            अग्र();
            l = tok;
        struct_क्षेत्रम्:
            अग्र();
	    f = find_क्षेत्रम्(type, l, &cumofs);
            यदि (cur_क्षेत्रम्)
                *cur_क्षेत्रम् = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_क्षेत्रम् = रिक्त;
    }
    यदि (!cur_क्षेत्रम्) {
        यदि (tok == '=') {
            अग्र();
        } अन्यथा यदि (!gnu_ext) {
	    expect("=");
        }
    } अन्यथा {
    no_designator:
        यदि (type->t & VT_ARRAY) {
	    सूचकांक = (*cur_क्षेत्रम्)->c;
            s = type->ref;
            decl_design_flex(p, s, सूचकांक);
            यदि (सूचकांक >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_आकार = type_आकार(type, &align);
            c += सूचकांक * elem_आकार;
        } अन्यथा {
            f = *cur_क्षेत्रम्;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    यावत् (f && (f->v & SYM_FIRST_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_क्षेत्रम् = f = f->अग्र;
            यदि (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    यदि (!elem_आकार) /* for structs */
        elem_आकार = type_आकार(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    यदि (!(flags & DIF_आकार_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_आकार * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_FIRST);

    यदि (!(flags & DIF_आकार_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        पूर्णाङ्क i;
        यदि (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_आकार;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        यदि (p->sec)
            vpush_ref(type, p->sec, c, elem_आकार);
        अन्यथा
	    vset(type, VT_LOCAL|VT_LVAL, c);
        प्रति (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_आकार * i);
	}
        vpop();
    }

    c += nb_elems * elem_आकार;
    यदि (c - corig > al)
      al = c - corig;
    प्रत्यागम al;
}

स्थिर शून्य write_ldouble(अचिह्नित वर्ण *d, शून्य *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#यदि_परिभाषितम् TCC_CROSS_TEST
    यदि (LDOUBLE_आकार >= 10) {
        द्विगुण b = *(दीर्घ द्विगुण*)s;
        s = &b;
#अन्यथा
    यदि (परिमाण (दीर्घ द्विगुण) == 8 && LDOUBLE_आकार >= 10) {
#यदि_अन्तः
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        पूर्णाङ्क e = m >> 48;
        पूर्णाङ्क f = e >> 4 & 0x7FF;
        m <<= 11;
        यदि (0 == f) {
            यदि (0 == m)
                गच्छ समुच्चयः;
            प्रति (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        यदि (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    समुच्चयः:
    #यदि (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #नोचेद्यदि LDOUBLE_आकार == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #यदि_अन्तः
        ;
    } अन्यथा {
    #यदि LDOUBLE_आकार == 8
        /* long double -> double */
        द्विगुण b = *(दीर्घ द्विगुण*)s;
        स्मृतिं_प्रतिलिख(d, &b, 8);
    #नोचेद्यदि (__i386__ || __x86_64__) && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
        /* extended -> extended */
        स्मृतिं_प्रतिलिख(d, s, 10);
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
    #अन्यथा
        /* unknown */
        यदि (परिमाण (दीर्घ द्विगुण) == LDOUBLE_आकार)
            स्मृतिं_प्रतिलिख(d, s, LDOUBLE_आकार);
    #यदि_अन्तः
    }
}

/* store a value or an expression directly in global data or in local array */
स्थिर शून्य init_putv(init_params *p, CType *type, अचिह्नित दीर्घ c)
{
    पूर्णाङ्क bt;
    शून्य *ptr;
    CType dtype;
    पूर्णाङ्क आकार, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    आकार = type_आकार(type, &align);
    यदि (type->t & VT_BITFIELD)
        आकार = (BIT_POS(type->t) + BIT_आकार(type->t) + 7) / 8;
    init_assert(p, c + आकार);

    यदि (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_नियोजय_cast(&dtype);
        bt = type->t & VT_BTYPE;

        यदि ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_आकार == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        यदि (NODATA_WANTED) {
            vtop--;
            प्रत्यागम;
        }

        ptr = sec->दत्त + c;
        val = vtop->c.i;

	यदि ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
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
	    memmove (ptr, ssec->दत्त + esym->st_मानम् + (पूर्णाङ्क)vtop->c.i, आकार);
	    यदि (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                अचिह्नित दीर्घ relofs = ssec->reloc->दत्त_विस्थापनम्;
		यावत् (relofs >= परिमाण(*rel)) {
                    relofs -= परिमाण(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->दत्त + relofs);
		    यदि (rel->r_विस्थापनम् >= esym->st_मानम् + आकार)
		      अनुवर्त;
		    यदि (rel->r_विस्थापनम् < esym->st_मानम्)
		      भङ्ग;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_विस्थापनम् - esym->st_मानम्,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#यदि PTR_आकार == 8
				   rel->r_addend
#अन्यथा
				   0
#यदि_अन्तः
				  );
		}
	    }
	} अन्यथा {
            यदि (type->t & VT_BITFIELD) {
                पूर्णाङ्क bit_pos, bit_आकार, द्वयङ्काः, n;
                अचिह्नित वर्ण *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_आकार = BIT_आकार(vtop->type.t);
                p = (अचिह्नित वर्ण*)ptr + (bit_pos >> 3);
                bit_pos &= 7, द्वयङ्काः = 0;
                यावत् (bit_आकार) {
                    n = 8 - bit_pos;
                    यदि (n > bit_आकार)
                        n = bit_आकार;
                    v = val >> द्वयङ्काः << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    द्वयङ्काः += n, bit_आकार -= n, bit_pos = 0, ++p;
                }
            } अन्यथा
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

#यदि PTR_आकार == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    पक्ष VT_LLONG:
	    पक्ष VT_PTR:
	        यदि (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_दत्त_PTR, val);
	        अन्यथा
	          write64le(ptr, val);
	        भङ्ग;
            पक्ष VT_INT:
                write32le(ptr, val);
                भङ्ग;
#अन्यथा
	    पक्ष VT_LLONG:
                write64le(ptr, val);
                भङ्ग;
            पक्ष VT_PTR:
            पक्ष VT_INT:
	        यदि (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_दत्त_PTR);
	        write32le(ptr, val);
	        भङ्ग;
#यदि_अन्तः
	    स्वभाव:
                //tcc_internal_error("unexpected type");
                भङ्ग;
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
स्थिर शून्य decl_initializer(init_params *p, CType *type, अचिह्नित दीर्घ c, पूर्णाङ्क flags)
{
    पूर्णाङ्क len, n, no_oblock, i;
    पूर्णाङ्क size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    यदि (debug_modes && !(flags & DIF_आकार_ONLY) && !p->sec)
        tcc_debug_पङ्क्तिः(tcc_state), tcc_tcov_check_पङ्क्तिः (tcc_state, 1);

    यदि (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
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
        पूर्णाङ्क ncw_पूर्व = nocode_wanted;
        यदि ((flags & DIF_आकार_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? व्यञ्जकम्_ANY : व्यञ्जकम्_CONST);
        nocode_wanted = ncw_पूर्व;
        flags |= DIF_HAVE_ELEM;
    }

    यदि (type->t & VT_ARRAY) {
        no_oblock = 1;
        यदि (((flags & DIF_FIRST) && tok != TOK_LSTR && tok != TOK_STR) ||
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
        यदि ((tok == TOK_LSTR && 
#यदि_परिभाषितम् TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#अन्यथा
             (t1->t & VT_BTYPE) == VT_INT
#यदि_अन्तः
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            यदि (size1 != (tok == TOK_STR ? 1 : परिमाण(nwchar_t)))
              tcc_error("unhandled string literal merging");
            यावत् (tok == TOK_STR || tok == TOK_LSTR) {
                यदि (initstr.आकार)
                  initstr.आकार -= size1;
                यदि (tok == TOK_STR)
                  len += tokc.str.आकार;
                अन्यथा
                  len += tokc.str.आकार / परिमाण(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.दत्त, tokc.str.आकार);
                अग्र();
            }
            यदि (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.आकार = initstr.आकार;
                tokc.str.दत्त = initstr.दत्त;
                गच्छ do_init_array;
            }

            decl_design_flex(p, s, len);
            यदि (!(flags & DIF_आकार_ONLY)) {
                पूर्णाङ्क nb = n, ch;
                यदि (len < nb)
                    nb = len;
                यदि (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                यदि (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    यदि (!NODATA_WANTED)
                      स्मृतिं_प्रतिलिख(p->sec->दत्त + c, initstr.दत्त, nb);
                } अन्यथा {
                    प्रति(i=0;i<n;i++) {
                        यदि (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          यदि (flags & DIF_CLEAR)
                            भङ्ग;
                          यदि (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            भङ्ग;
                          }
                          ch = 0;
                        } अन्यथा यदि (size1 == 1)
                          ch = ((अचिह्नित वर्ण *)initstr.दत्त)[i];
                        अन्यथा
                          ch = ((nwchar_t *)initstr.दत्त)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            यदि (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                अग्र();
        } अन्यथा {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            यदि (!(flags & (DIF_CLEAR | DIF_आकार_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    यावत् (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		यदि (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    यदि (no_oblock && len >= n*size1)
		        भङ्ग;
		} अन्यथा {
		    यदि (s->type.t == VT_UNION)
		        f = रिक्त;
		    अन्यथा
		        f = f->अग्र;
		    यदि (no_oblock && f == रिक्त)
		        भङ्ग;
		}

		यदि (tok == '}')
		    भङ्ग;
		skip(',');
	    }
        }
        यदि (!no_oblock)
            skip('}');

    } अन्यथा यदि ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        गच्छ one_elem;

    } अन्यथा यदि ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        यदि ((flags & DIF_FIRST) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->अग्र;
        n = s->c;
        size1 = 1;
	गच्छ do_init_list;

    } अन्यथा यदि (tok == '{') {
        यदि (flags & DIF_HAVE_ELEM)
          skip(';');
        अग्र();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } अन्यथा one_elem: यदि ((flags & DIF_आकार_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        यदि (flags & DIF_HAVE_ELEM)
            vpop();
        अन्यथा
            skip_or_save_खण्डम्(रिक्त);

    } अन्यथा {
	यदि (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    यदि (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? व्यञ्जकम्_ANY : व्यञ्जकम्_CONST);
	}
        यदि (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
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
स्थिर शून्य decl_initializer_alloc(CType *type, AttributeDef *ad, पूर्णाङ्क r, 
                                   पूर्णाङ्क has_init, पूर्णाङ्क v, पूर्णाङ्क scope)
{
    पूर्णाङ्क आकार, align, addr;
    TokenString *init_str = रिक्त;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = रिक्त;
    पूर्णाङ्क saved_nocode_wanted = nocode_wanted;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    पूर्णाङ्क bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#यदि_अन्तः
    init_params p = {0};

    यदि (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_find(v);
        यदि (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            यदि (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                प्रत्यागम;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    यदि (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= दत्त_ONLY_WANTED;

    flexible_array = रिक्त;
    आकार = type_आकार(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    यदि (आकार < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        यदि (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        यदि (IS_BT_ARRAY(type->t))
            type->ref = sym_प्रक्षिप(SYM_क्षेत्रम्, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } अन्यथा यदि (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *क्षेत्रम् = type->ref->अग्र;
        यदि (क्षेत्रम्) {
            यावत् (क्षेत्रम्->अग्र)
                क्षेत्रम् = क्षेत्रम्->अग्र;
            यदि (क्षेत्रम्->type.t & VT_ARRAY && क्षेत्रम्->type.ref->c < 0) {
                flexible_array = क्षेत्रम्;
                p.flex_array_ref = क्षेत्रम्->type.ref;
                आकार = -1;
            }
        }
    }

    यदि (आकार < 0) {
        /* If unknown size, do a dry-run 1st pass */
        यदि (!has_init)
            गच्छ err_आकार;
        यदि (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            यावत् (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_सङ्कलय_tok(init_str);
                अग्र();
            }
            tok_str_सङ्कलय(init_str, TOK_EOF);
        } अन्यथा
            skip_or_save_खण्डम्(&init_str);
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
        यदि (आकार < 0)
    err_आकार:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        यदि (flexible_array && flexible_array->type.ref->c > 0)
            आकार += flexible_array->type.ref->c
                    * pointed_आकार(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    यदि (ad->a.aligned) {
	पूर्णाङ्क speca = 1 << (ad->a.aligned - 1);
        यदि (speca > align)
            align = speca;
    } अन्यथा यदि (ad->a.packed) {
        align = 1;
    }

    यदि (!v && NODATA_WANTED)
        आकार = 0, align = 1;

    यदि ((r & VT_VALMASK) == VT_LOCAL) {
        sec = रिक्त;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#यदि_अन्तः
        loc = (loc - आकार) & -align;
        addr = loc;
        p.local_विस्थापनम् = addr + आकार;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#यदि_अन्तः
        यदि (v) {
            /* local variable */
#यदि_परिभाषितम् CONFIG_TCC_ASM
	    यदि (ad->asm_label) {
		पूर्णाङ्क reg = asm_parse_regvar(ad->asm_label);
		यदि (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#यदि_अन्तः
            sym = sym_प्रक्षिप(v, type, r, addr);
	    यदि (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_क्षेत्रम् | ++cur_scope->cl.n, 0, 0);
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
        पूर्णाङ्क is_const;

        यावत् ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        यदि (!sec) {
            यदि (type->t & VT_TLS) {
                sec = find_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } अन्यथा यदि (is_const) {
		sec = rodata_section;
            } अन्यथा यदि (has_init) {
		sec = दत्त_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } अन्यथा यदि (tcc_state->nocommon)
                sec = bss_section;
        } अन्यथा यदि (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            यदि (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                यदि (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (bcheck)
            आकार = आकार + 1; /* add padding */
#यदि_अन्तः
        यदि (sec) {
	    addr = section_सङ्कलय(sec, आकार, align);
        } अन्यथा {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        यदि (v) {
            यदि (!sym) {
                sym = sym_प्रक्षिप(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, रिक्त);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, आकार);
        } अन्यथा {
            /* push global reference */
            vpush_ref(type, sec, addr, आकार);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        यदि (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->दत्त_विस्थापनम्, R_दत्त_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_सङ्कलय(bounds_section, 2 * परिमाण(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = आकार - 1;
        }
#यदि_अन्तः
    }

    यदि (type->t & VT_VLA) {
        पूर्णाङ्क a;

        यदि (has_init)
            tcc_error("variable length array cannot be initialized");

        यदि (NODATA_WANTED)
            गच्छ no_alloc;

        /* save before-VLA stack pointer if needed */
        यदि (cur_scope->vla.अङ्कः == 0) {
            यदि (cur_scope->पूर्व && cur_scope->पूर्व->vla.अङ्कः) {
                cur_scope->vla.locorig = cur_scope->पूर्व->vla.loc;
            } अन्यथा {
                gen_vla_sp_save(loc -= PTR_आकार);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_आकार(type, &a);
        gen_vla_alloc(type, a);
#यदि defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_परिणाम(addr), addr = (loc -= PTR_आकार);
#यदि_अन्तः
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.अङ्कः++;
    } अन्यथा यदि (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_FIRST);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        यदि (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    यदि (init_str) {
        अन्तः_macro();
        अग्र();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
स्थिर शून्य func_vla_arg_संहिता(Sym *arg)
{
    पूर्णाङ्क align;
    TokenString *vla_array_tok = रिक्त;

    यदि (arg->type.ref)
        func_vla_arg_संहिता(arg->type.ref);

    यदि ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_आकार(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	अग्र();
	gexpr();
	अन्तः_macro();
	अग्र();
	vpush_type_आकार(&arg->type.ref->type, &align);
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

    प्रति (arg = sym->type.ref->अग्र; arg; arg = arg->अग्र)
        यदि ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_संहिता(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_समुच्चयः_param(Sym *s, पूर्णाङ्क c, पूर्णाङ्क byref)
{
    s = sym_find(s->v);
    यदि (!s) /* unnamed parameters, not enabled */
        प्रत्यागम रिक्त;
    s->c = c;
    यदि (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    प्रत्यागम s;
}

/* push parameters (and their types), last first */
स्थिर शून्य sym_प्रक्षिप_params(Sym *ref)
{
    Sym *s = ref;
    यावत् (s->अग्र)
        s = s->अग्र;
    यावत् (s != ref) {
        यदि ((s->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
            sym_copy(s, &local_राशिः);
        s = s->पूर्व;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
स्थिर शून्य gen_function(Sym *sym)
{
    संरचना scope f = { 0 };

    cur_scope = मूलम्_scope = &f;
    nocode_wanted = 0;

    ind = cur_text_section->दत्त_विस्थापनम्;
    यदि (sym->a.aligned) {
	आकार_t newoff = section_सङ्कलय(cur_text_section, 0,
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

    यदि (sym->type.ref->f.func_ctor)
        सङ्कलय_array (tcc_state, ".init_array", sym->c);
    यदि (sym->type.ref->f.func_dtor)
        सङ्कलय_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_राशिः, SYM_क्षेत्रम्, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_प्रक्षिप_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_अस्थायी_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    खण्डम्(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_अन्तः_scope(रिक्त, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_आकार = ind - func_ind;
    cur_text_section->दत्त_विस्थापनम् = ind;

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
    nocode_wanted = दत्त_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    अग्र();
}

स्थिर शून्य gen_inline_functions(TCCState *s)
{
    Sym *sym;
    पूर्णाङ्क inline_generated, i;
    संरचना InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    कुरु {
        inline_generated = 0;
        प्रति (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            यदि (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = रिक्त;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                अग्र();
                cur_text_section = text_section;
                gen_function(sym);
                अन्तः_macro();

                inline_generated = 1;
            }
        }
    } यावत् (inline_generated);
    tcc_close();
}

स्थिर शून्य free_inline_functions(TCCState *s)
{
    पूर्णाङ्क i;
    /* free tokens of unused inline functions */
    प्रति (i = 0; i < s->nb_inline_fns; ++i) {
        संरचना InlineFunc *fn = s->inline_fns[i];
        यदि (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

स्थिर शून्य do_Static_assert(शून्य)
{
    पूर्णाङ्क c;
    ध्रुव वर्ण *सन्देशः;

    अग्र();
    skip('(');
    c = व्यञ्जकम्_const();
    सन्देशः = "_Static_assert fail";
    यदि (tok == ',') {
        अग्र();
        सन्देशः = parse_mult_str("string constant")->दत्त;
    }
    skip(')');
    यदि (c == 0)
        tcc_error("%s", सन्देशः);
    skip(';');
}

#यदि_परिभाषितम् TCC_TARGET_PE
स्थिर शून्य pe_check_linkage(CType *type, AttributeDef *ad)
{
    यदि (!ad->a.dllimport && !ad->a.dllexport)
        प्रत्यागम;
    यदि (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    यदि (type->t & VT_TYPEDEF) {
        ध्रुव वर्ण *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } अन्यथा यदि (ad->a.dllimport) {
        यदि ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        अन्यथा
            type->t |= VT_EXTERN;
    }
}
#यदि_अन्तः

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

    यावत् (1) {

        oldint = 0;
        यदि (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            यदि (l == VT_JMP)
                प्रत्यागम 0;
            /* skip redundant ';' if not in old parameter decl scope */
            यदि (tok == ';' && l != VT_CMP) {
                अग्र();
                अनुवर्त;
            }
            यदि (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                अनुवर्त;
            }
            यदि (l != VT_CONST)
                भङ्ग;
            यदि (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                अनुवर्त;
            }
            यदि (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } अन्यथा {
                यदि (tok != TOK_EOF)
                    expect("declaration");
                भङ्ग;
            }
        }

        यदि (tok == ';') {
            यदि ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_FIRST_ANOM)
                ; /* struct decl with named tag */
            अन्यथा यदि (IS_ENUM(btype.t))
                ; /* enum decl */
            अन्यथा
                tcc_warning("useless type defines no instances");
            यदि (l == VT_JMP)
                प्रत्यागम 1;
            अग्र();
            अनुवर्त;
        }

        यावत् (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_प्रत्यक्षम् | TYPE_PARAM : TYPE_प्रत्यक्षम्);
            /*ptype("decl", &type, v);*/
            यदि ((type.t & VT_BTYPE) == VT_FUNC) {
                यदि ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                यदि (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                यदि ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    यदि (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    अन्यथा
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } अन्यथा यदि (oldint) {
                tcc_warning("type defaults to int");
            }

            यदि (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #यदि 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                यदि (tok == '{')
                    expect(";");
            #यदि_अन्तः
            }

#यदि_परिभाषितम् TCC_TARGET_PE
            pe_check_linkage(&type, &ad);
#यदि_अन्तः
            यदि (tok == '{') {
                यदि (l != VT_CONST)
                    tcc_error("cannot use local functions");
                यदि ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                merge_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                प्रति (sa = sym->type.ref; (sa = sa->अग्र) != रिक्त;) {
                    यदि (!(sa->v & ~SYM_क्षेत्रम्))
                        expect("identifier");
                    यदि (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                यदि (sym->type.t & VT_INLINE) {
                    संरचना InlineFunc *fn;
                    fn = tcc_malloc(परिमाण *fn + वाक्यदैर्घ्यम्(file->filename));
                    वाक्यं_प्रतिलिख(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_सङ्कलय(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_खण्डम्(&fn->func_str);
                } अन्यथा {
                    /* compute text section */
                    cur_text_section = text_section;
                    यदि (ad.section) {
                        cur_text_section = ad.section;
                        यदि (ad.new_section)
                            ad.section->sh_flags = text_section->sh_flags;
                    }
                    gen_function(sym);
                }
                भङ्ग;
            } अन्यथा {
                has_init = 0;
		यदि (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    प्रति (sym = func_vt.ref->अग्र; sym; sym = sym->अग्र)
			यदि ((sym->v & ~SYM_क्षेत्रम्) == v)
			    गच्छ प्राप्तम्;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, रिक्त));
                प्राप्तम्:
		    यदि (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, रिक्त));
		    यदि (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, रिक्त));
		    convert_parameter_type(&type);
		    sym->type = type;
		} अन्यथा यदि (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    यदि (sym && sym->sym_scope == local_scope) {
                        यदि (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, रिक्त));
                        sym->type = type;
                    } अन्यथा {
                        sym = sym_प्रक्षिप(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    यदि ((type.t & VT_BTYPE) == VT_FUNC)
                      merge_funcattr(&sym->type.ref->f, &ad.f);
                    यदि (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} अन्यथा यदि ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } अन्यथा {
                    r = 0;
                    यदि ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        merge_funcattr(&type.ref->f, &ad.f);
                    } अन्यथा यदि (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    यदि (tok == '=')
                        has_init = 1;

                    यदि (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
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
                        यदि (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        अन्यथा
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        यदि (has_init)
                            अग्र();
                        अन्यथा यदि (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    यदि (ad.alias_target && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_find(ad.alias_target));
                        यदि (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_find(v), esym->st_shndx,
                                        esym->st_मानम्, esym->st_आकार, 1);
                    }
                }
                यदि (tok != ',') {
                    यदि (l == VT_JMP)
                        प्रत्यागम has_init ? v : 1;
                    skip(';');
                    भङ्ग;
                }
                अग्र();
            }
        }
    }
    प्रत्यागम 0;
}

/* ------------------------------------------------------------------------- */
#अपरिभाषय gjmp_addr
#अपरिभाषय gjmp
/* ------------------------------------------------------------------------- */
