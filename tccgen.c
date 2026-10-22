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

#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
ST_దత్తాంశం పూర్ణాంకం rsym, anon_sym, ind, loc;

ST_దత్తాంశం Sym *global_దొంతర;
ST_దత్తాంశం Sym *local_దొంతర;
ST_దత్తాంశం Sym *define_దొంతర;
ST_దత్తాంశం Sym *global_label_దొంతర;
ST_దత్తాంశం Sym *local_label_దొంతర;

స్థిర Sym *sym_free_మొదటి;
స్థిర శూన్య **sym_pools;
స్థిర పూర్ణాంకం nb_sym_pools;

స్థిర Sym *all_cleanups, *pending_gotos;
స్థిర పూర్ణాంకం local_scope;
ST_దత్తాంశం అక్షరం debug_modes;

ST_దత్తాంశం SValue *vtop;
స్థిర SValue _vstack[1 + VSTACK_కొలత];
#నిర్వచించు vstack (_vstack + 1)

ST_దత్తాంశం పూర్ణాంకం nocode_wanted; /* no code generation wanted */
#నిర్వచించు NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#నిర్వచించు దత్తాంశం_ONLY_WANTED 0x80000000 /* ON outside of functions and for static initializers */

/* no code output after unconditional jumps such as with if (0) ... */
#నిర్వచించు సంకేతం_OFF_బిట్టు 0x20000000
#నిర్వచించు సంకేతం_OFF() ఒకవేళ(!nocode_wanted)(nocode_wanted |= సంకేతం_OFF_బిట్టు)
#నిర్వచించు సంకేతం_ON() (nocode_wanted &= ~సంకేతం_OFF_బిట్టు)

/* no code output when parsing sizeof()/typeof() etc. (using nocode_wanted++/--) */
#నిర్వచించు NOEVAL_ముసుగు 0x0000FFFF
#నిర్వచించు NOEVAL_WANTED (nocode_wanted & NOEVAL_ముసుగు)

/* no code output when parsing constant expressions */
#నిర్వచించు CONST_WANTED_బిట్టు  0x00010000
#నిర్వచించు CONST_WANTED_ముసుగు 0x0FFF0000
#నిర్వచించు CONST_WANTED  (nocode_wanted & CONST_WANTED_ముసుగు)

ST_దత్తాంశం పూర్ణాంకం global_సమాసం;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_దత్తాంశం CType func_vt; /* current function return type (used by return instruction) */
ST_దత్తాంశం పూర్ణాంకం func_var; /* true if current function is variadic (used by return instruction) */
ST_దత్తాంశం పూర్ణాంకం func_vc; /* stack address for implicit struct return storage */
ST_దత్తాంశం పూర్ణాంకం func_ind; /* function start address */
స్థిర పూర్ణాంకం func_old;
ST_దత్తాంశం స్థిరరాశి అక్షరం *funcname;
ST_దత్తాంశం CType int_type, func_old_type, char_type, char_సూచిక_type;
స్థిర CString initstr;

#ఒకవేళ PTR_కొలత == 4
#నిర్వచించు VT_కొలత_T (VT_INT | VT_UNSIGNED)
#నిర్వచించు VT_PTRDIFF_T VT_INT
#లేదావేళ LONG_కొలత == 4
#నిర్వచించు VT_కొలత_T (VT_LLONG | VT_UNSIGNED)
#నిర్వచించు VT_PTRDIFF_T VT_LLONG
#లేకపోతే
#నిర్వచించు VT_కొలత_T (VT_LONG | VT_LLONG | VT_UNSIGNED)
#నిర్వచించు VT_PTRDIFF_T (VT_LONG | VT_LLONG)
#అయితే_ముగింపు

స్థిర నిర్మాణం switch_t {
    నిర్మాణం case_t {
        int64_t v1, v2;
        పూర్ణాంకం ind, పంక్తి;
    } **p; పూర్ణాంకం n; /* list of case ranges */
    పూర్ణాంకం def_sym; /* default symbol */
    పూర్ణాంకం nocode_wanted;
    పూర్ణాంకం *bsym;
    నిర్మాణం scope *scope;
    నిర్మాణం switch_t *prev;
    SValue sv;
} *cur_switch; /* current switch */

#నిర్వచించు MAX_తాత్కాలిక_LOCAL_VARIABLE_సంఖ్య 8
/*list of temporary local variables on the stack in current function. */
స్థిర నిర్మాణం తాత్కాలిక_local_variable {
	పూర్ణాంకం location; //offset on stack. Svalue.c.i
	పొట్టి కొలత;
	పొట్టి align;
} arr_తాత్కాలిక_local_vars[MAX_తాత్కాలిక_LOCAL_VARIABLE_సంఖ్య];
స్థిర పూర్ణాంకం nb_తాత్కాలిక_local_vars;

స్థిర నిర్మాణం scope {
    నిర్మాణం scope *prev;
    నిర్మాణం { పూర్ణాంకం loc, locorig, అంకె; } vla;
    నిర్మాణం { Sym *s; పూర్ణాంకం n; } cl;
    పూర్ణాంకం *bsym, *csym;
    Sym *lstk, *llstk;
} *cur_scope, *loop_scope, *మూలం_scope;

రకనిర్వచనం నిర్మాణం {
    Section *sec;
    పూర్ణాంకం local_స్థానభ్రంశం;
    Sym *flex_array_ref;
} init_params;

#ఒకవేళ 1
#నిర్వచించు precedence_parser
స్థిర శూన్య init_prec(శూన్య);
#అయితే_ముగింపు

స్థిర శూన్య ఖండం(పూర్ణాంకం flags);
#నిర్వచించు STMT_సమాసం 1
#నిర్వచించు STMT_COMPOUND 2

స్థిర శూన్య gen_cast(CType *type);
స్థిర శూన్య gen_cast_s(పూర్ణాంకం t);
స్థిర అంతఃవరుస CType *pointed_type(CType *type);
స్థిర శూన్య check_restrict_type(CType *type);
స్థిర పూర్ణాంకం type_qualifiers(CType *type);
స్థిర శూన్య parse_btype_qualify(CType *type, పూర్ణాంకం qualifiers);
స్థిర పూర్ణాంకం is_compatible_types(CType *type1, CType *type2);
స్థిర పూర్ణాంకం parse_btype(CType *type, AttributeDef *ad, పూర్ణాంకం ignore_label);
స్థిర CType *type_decl(CType *type, AttributeDef *ad, పూర్ణాంకం *v, పూర్ణాంకం td);
స్థిర శూన్య parse_సమాసం_type(CType *type);
స్థిర శూన్య init_putv(init_params *p, CType *type, గుర్తులేని దీర్ఘ c);
స్థిర శూన్య decl_initializer(init_params *p, CType *type, గుర్తులేని దీర్ఘ c, పూర్ణాంకం flags);
స్థిర శూన్య decl_initializer_alloc(CType *type, AttributeDef *ad, పూర్ణాంకం r, పూర్ణాంకం has_init, పూర్ణాంకం v, పూర్ణాంకం scope);
స్థిర పూర్ణాంకం decl(పూర్ణాంకం l);
స్థిర శూన్య సమాసం_eq(శూన్య);
స్థిర శూన్య vpush_type_కొలత(CType *type, పూర్ణాంకం *a);
స్థిర పూర్ణాంకం is_compatible_unqualified_types(CType *type1, CType *type2);
స్థిర అంతఃవరుస int64_t సమాసం_const64(శూన్య);
స్థిర శూన్య vpush64(పూర్ణాంకం ty, గుర్తులేని దీర్ఘ దీర్ఘ v);
స్థిర శూన్య vpush(CType *type);
స్థిర పూర్ణాంకం gvtst(పూర్ణాంకం inv, పూర్ణాంకం t);
స్థిర శూన్య gen_inline_functions(TCCState *s);
స్థిర శూన్య free_inline_functions(TCCState *s);
స్థిర శూన్య skip_or_save_ఖండం(TokenString **str);
స్థిర శూన్య gv_dup(శూన్య);
స్థిర పూర్ణాంకం get_తాత్కాలిక_local_var(పూర్ణాంకం కొలత,పూర్ణాంకం align,పూర్ణాంకం *r2);
స్థిర శూన్య cast_error(CType *st, CType *dt);
స్థిర శూన్య చివర_switch(శూన్య);
స్థిర శూన్య do_Static_assert(శూన్య);

/* ------------------------------------------------------------------------- */
/* Automagical code suppression */

/* Clear 'nocode_wanted' at forward label if it was used */
ST_FUNC శూన్య gsym(పూర్ణాంకం t)
{
  ఒకవేళ (t) {
    gsym_addr(t, ind);
    సంకేతం_ON();
  }
}

/* Clear 'nocode_wanted' if current pc is a label */
స్థిర పూర్ణాంకం gind()
{
  పూర్ణాంకం t = ind;
  సంకేతం_ON();
  ఒకవేళ (debug_modes)
    tcc_tcov_ఖండం_begin(tcc_state);
  తిరిగి t;
}

/* Set 'nocode_wanted' after unconditional (backwards) jump */
స్థిర శూన్య gjmp_addr_acs(పూర్ణాంకం t)
{
  gjmp_addr(t);
  సంకేతం_OFF();
}

/* Set 'nocode_wanted' after unconditional (forwards) jump */
స్థిర పూర్ణాంకం gjmp_acs(పూర్ణాంకం t)
{
  t = gjmp(t);
  సంకేతం_OFF();
  తిరిగి t;
}

/* These are #undef'd at the end of this file */
#నిర్వచించు gjmp_addr gjmp_addr_acs
#నిర్వచించు gjmp gjmp_acs
/* ------------------------------------------------------------------------- */

ST_INLN పూర్ణాంకం is_float(పూర్ణాంకం t)
{
    పూర్ణాంకం bt = t & VT_BTYPE;
    తిరిగి bt == VT_LDOUBLE
        || bt == VT_DOUBLE
        || bt == VT_FLOAT
        || bt == VT_QFLOAT;
}

స్థిర అంతఃవరుస పూర్ణాంకం is_integer_btype(పూర్ణాంకం bt)
{
    తిరిగి bt == VT_BYTE
        || bt == VT_BOOL
        || bt == VT_SHORT
        || bt == VT_INT
        || bt == VT_LLONG;
}

స్థిర పూర్ణాంకం btype_కొలత(పూర్ణాంకం bt)
{
    తిరిగి bt == VT_BYTE || bt == VT_BOOL ? 1 :
        bt == VT_SHORT ? 2 :
        bt == VT_INT ? 4 :
        bt == VT_LLONG ? 8 :
        bt == VT_PTR ? PTR_కొలత : 0;
}

/* returns function return register from type */
స్థిర పూర్ణాంకం R_RET(పూర్ణాంకం t)
{
    ఒకవేళ (!is_float(t))
        తిరిగి REG_IRET;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    ఒకవేళ ((t & VT_BTYPE) == VT_LDOUBLE)
        తిరిగి TREG_ST0;
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    ఒకవేళ ((t & VT_BTYPE) == VT_LDOUBLE)
        తిరిగి REG_IRET;
#అయితే_ముగింపు
    తిరిగి REG_FRET;
}

/* returns 2nd function return register, if any */
స్థిర పూర్ణాంకం R2_RET(పూర్ణాంకం t)
{
    t &= VT_BTYPE;
#ఒకవేళ PTR_కొలత == 4
    ఒకవేళ (t == VT_LLONG)
        తిరిగి REG_IRE2;
#లేదావేళ defined TCC_లక్ష్యం_X86_64
    ఒకవేళ (t == VT_QLONG)
        తిరిగి REG_IRE2;
    ఒకవేళ (t == VT_QFLOAT)
        తిరిగి REG_FRE2;
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    ఒకవేళ (t == VT_LDOUBLE)
        తిరిగి REG_IRE2;
#అయితే_ముగింపు
    తిరిగి VT_CONST;
}

/* returns true for two-word types */
#నిర్వచించు USING_TWO_పదాలు(t) (R2_RET(t) != VT_CONST)

/* put function return registers to stack value */
స్థిర శూన్య PUT_R_RET(SValue *sv, పూర్ణాంకం t)
{
    sv->r = R_RET(t), sv->r2 = R2_RET(t);
}

/* returns function return register class for type t */
స్థిర పూర్ణాంకం RC_RET(పూర్ణాంకం t)
{
    తిరిగి reg_classes[R_RET(t)] & ~(RC_FLOAT | RC_INT);
}

/* returns generic register class for type t */
స్థిర పూర్ణాంకం RC_TYPE(పూర్ణాంకం t)
{
    ఒకవేళ (!is_float(t))
        తిరిగి RC_INT;
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    ఒకవేళ ((t & VT_BTYPE) == VT_LDOUBLE)
        తిరిగి RC_ST0;
    ఒకవేళ ((t & VT_BTYPE) == VT_QFLOAT)
        తిరిగి RC_FRET;
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    ఒకవేళ ((t & VT_BTYPE) == VT_LDOUBLE)
        తిరిగి RC_INT;
#అయితే_ముగింపు
    తిరిగి RC_FLOAT;
}

/* returns 2nd register class corresponding to t and rc */
స్థిర పూర్ణాంకం RC2_TYPE(పూర్ణాంకం t, పూర్ణాంకం rc)
{
    ఒకవేళ (!USING_TWO_పదాలు(t))
        తిరిగి 0;
#నిర్వచితమైతే RC_IRE2
    ఒకవేళ (rc == RC_IRET)
        తిరిగి RC_IRE2;
#అయితే_ముగింపు
#నిర్వచితమైతే RC_FRE2
    ఒకవేళ (rc == RC_FRET)
        తిరిగి RC_FRE2;
#అయితే_ముగింపు
    ఒకవేళ (rc & RC_FLOAT)
        తిరిగి RC_FLOAT;
    తిరిగి RC_INT;
}

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
ST_FUNC పూర్ణాంకం ieee_finite(ద్విగుణ d)
{
    పూర్ణాంకం p[4];
    జ్ఞాపకం_నకలు(p, &d, పరిమాణం(ద్విగుణ));
    తిరిగి ((గుర్తులేని)((p[1] | 0x800fffff) + 1)) >> 31;
}

ST_FUNC శూన్య test_lvalue(శూన్య)
{
    ఒకవేళ (!(vtop->r & VT_LVAL))
        expect("lvalue");
}

ST_FUNC శూన్య check_vstack(శూన్య)
{
    ఒకవేళ (vtop != vstack - 1)
        tcc_error("internal compiler error: vstack leak (%d)",
                  (పూర్ణాంకం)(vtop - vstack + 1));
}

#ఒకవేళ 0
/* dump 'b' vstack entries starting with 'a'  */
శూన్య pv (స్థిరరాశి అక్షరం *lbl, పూర్ణాంకం a, పూర్ణాంకం b)
{
    పూర్ణాంకం i;
    కొరకు (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        రాయి("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (పూర్ణాంకం)p->c.i);
    }
}

/* dump symbols on stack from s ... last */
స్థిర అంతఃవరుస శూన్య psyms(స్థిరరాశి అక్షరం *సందేశం, Sym *s, Sym *చివరి)
{
    రాయి("%-8s scope         v        c        r   type.t\n", సందేశం);
    అయితే (s && s != చివరి) {
        రాయి("      %8x  %08x %08x %08x %08x %s\n",
            s->sym_scope, s->v, s->c, s->r, s->type.t, get_tok_str(s->v, 0));
        s = s->prev;
    }
}

స్థిర శూన్య type_గమ్యం_str(అక్షరం *buf, పూర్ణాంకం buf_కొలత, CType *type, స్థిరరాశి అక్షరం *varstr);

/* print type */
స్థిర శూన్య ptype(స్థిరరాశి అక్షరం *సందేశం, CType *type, పూర్ణాంకం v)
{
    అక్షరం buf[500];
    type_గమ్యం_str(buf, పరిమాణం(buf), type,
        (v & ~SYM_క్షేత్రం) ? get_tok_str(v, ఖాళీ) : ఖాళీ);
    రాయి("%s : %s;\n", సందేశం, buf);
}
#అయితే_ముగింపు

/* ------------------------------------------------------------------------- */
/* initialize vstack and types.  This must be done also for tcc -E */
ST_FUNC శూన్య tccgen_init(TCCState *s1)
{
    vtop = vstack - 1;
    memset(vtop, 0, పరిమాణం *vtop);

    /* define some often used types */
    int_type.t = VT_INT;

    char_type.t = VT_BYTE;
    ఒకవేళ (s1->char_is_unsigned)
        char_type.t |= VT_UNSIGNED;
    char_సూచిక_type = char_type;
    mk_సూచిక(&char_సూచిక_type);

    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_నెట్టు(SYM_క్షేత్రం, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;
#నిర్వచితమైతే precedence_parser
    init_prec();
#అయితే_ముగింపు
    cstr_new(&initstr);
}

ST_FUNC పూర్ణాంకం tccgen_compile(TCCState *s1)
{
    funcname = "";
    func_ind = -1;
    anon_sym = SYM_మొదటి_ANOM;
    nocode_wanted = దత్తాంశం_ONLY_WANTED; /* no code outside of functions */
    debug_modes = (s1->do_debug ? 1 : 0) | s1->test_coverage << 1;
    global_సమాసం = 0;

    tcc_debug_ప్రారంభం(s1);
    tcc_tcov_ప్రారంభం (s1);
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    arm_init(s1);
#అయితే_ముగింపు
#నిర్వచితమైతే INC_DEBUG
    రాయి("%s: **** new file\n", file->filename);
#అయితే_ముగింపు
    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_అంకె | PARSE_FLAG_TOK_STR;
    తదుపరి();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
#ఒకవేళ TCC_EH_చట్రం
    tcc_eh_చట్రం_చివర(s1);
#అయితే_ముగింపు
    tcc_debug_చివర(s1);
    tcc_tcov_చివర(s1);
    తిరిగి 0;
}

ST_FUNC శూన్య tccgen_ముగింపు(TCCState *s1)
{
    tcc_debug_చివర(s1); /* just in case of errors: free memory */
    free_inline_functions(s1);
    sym_తీయి(&global_దొంతర, ఖాళీ, 0);
    sym_తీయి(&local_దొంతర, ఖాళీ, 0);
    /* free preprocessor macros */
    free_నిర్వచిస్తుంది(ఖాళీ);
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    cstr_free(&initstr);
    dynarray_reset(&stk_దత్తాంశం, &nb_stk_దత్తాంశం);
    అయితే (cur_switch)
        చివర_switch();
    local_scope = 0;
    loop_scope = ఖాళీ;
    all_cleanups = ఖాళీ;
    pending_gotos = ఖాళీ;
    nb_తాత్కాలిక_local_vars = 0;
    global_label_దొంతర = ఖాళీ;
    local_label_దొంతర = ఖాళీ;
    cur_పాఠ్యం_section = ఖాళీ;
    sym_free_మొదటి = ఖాళీ;
}

/* ------------------------------------------------------------------------- */
ST_FUNC ElfSym *elfsym(Sym *s)
{
  ఒకవేళ (!s || !s->c)
    తిరిగి ఖాళీ;
  తిరిగి &((ElfSym *)symtab_section->దత్తాంశం)[s->c];
}

/* apply storage attributes to Elf symbol */
ST_FUNC శూన్య update_storage(Sym *sym)
{
    ElfSym *esym;
    పూర్ణాంకం sym_bind, old_sym_bind;

    esym = elfsym(sym);
    ఒకవేళ (!esym)
        తిరిగి;

    ఒకవేళ (sym->a.visibility)
        esym->st_other = (esym->st_other & ~ELFW(ST_VISIBILITY)(-1))
            | sym->a.visibility;

    ఒకవేళ (sym->type.t & (VT_STATIC | VT_INLINE))
        sym_bind = STB_LOCAL;
    లేకపోతే ఒకవేళ (sym->a.weak)
        sym_bind = STB_WEAK;
    లేకపోతే
        sym_bind = STB_GLOBAL;
    old_sym_bind = ELFW(ST_BIND)(esym->st_info);
    ఒకవేళ (sym_bind != old_sym_bind) {
        esym->st_info = ELFW(ST_INFO)(sym_bind, ELFW(ST_TYPE)(esym->st_info));
    }

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (sym->a.dllimport)
        esym->st_other |= ST_PE_IMPORT;
    ఒకవేళ (sym->a.dllexport)
        esym->st_other |= ST_PE_EXPORT;
#అయితే_ముగింపు

#ఒకవేళ 0
    రాయి("storage %s: bind=%c vis=%d exp=%d imp=%d\n",
        get_tok_str(sym->v, ఖాళీ),
        sym_bind == STB_WEAK ? 'w' : sym_bind == STB_LOCAL ? 'l' : 'g',
        sym->a.visibility,
        sym->a.dllexport,
        sym->a.dllimport
        );
#అయితే_ముగింపు
}

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC శూన్య put_extern_sym2(Sym *sym, పూర్ణాంకం sh_అంకె,
                            addr_t విలువ, గుర్తులేని దీర్ఘ కొలత,
                            పూర్ణాంకం can_కూడు_underscore)
{
    పూర్ణాంకం sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    స్థిరరాశి అక్షరం *name;
    అక్షరం buf1[256];

    ఒకవేళ (!sym->c) {
        name = get_tok_str(sym->v, ఖాళీ);
        t = sym->type.t;
        ఒకవేళ ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } లేకపోతే ఒకవేళ ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
            ఒకవేళ (IS_ASM_FUNC(t))
                sym_type = STT_FUNC;
        } లేకపోతే ఒకవేళ (t & VT_TLS) {
            sym_type = STT_TLS;
        } లేకపోతే {
            sym_type = STT_OBJECT;
        }
        ఒకవేళ (t & (VT_STATIC | VT_INLINE))
            sym_bind = STB_LOCAL;
        లేకపోతే
            sym_bind = STB_GLOBAL;
        other = 0;

#నిర్వచితమైతే TCC_లక్ష్యం_PE
        ఒకవేళ (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            ఒకవేళ (ref->a.nodecorate) {
                can_కూడు_underscore = 0;
            }
            ఒకవేళ (ref->f.func_call == FUNC_STDCALL && can_కూడు_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_వాదనలు * PTR_కొలత);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_కూడు_underscore = 0;
            }
        }
#అయితే_ముగింపు

        ఒకవేళ (sym->asm_label) {
            name = get_tok_str(sym->asm_label, ఖాళీ);
            can_కూడు_underscore = 0;
        }

        ఒకవేళ (tcc_state->leading_underscore && can_కూడు_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, పరిమాణం(buf1) - 1, name);
            name = buf1;
        }

        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, విలువ, కొలత, info, other, sh_అంకె, name);

        ఒకవేళ (debug_modes)
            tcc_debug_extern_sym(tcc_state, sym, sh_అంకె, sym_bind, sym_type);

    } లేకపోతే {
        esym = elfsym(sym);
        esym->st_విలువ = విలువ;
        esym->st_కొలత = కొలత;
        esym->st_shndx = sh_అంకె;
    }
    update_storage(sym);
}

ST_FUNC శూన్య put_extern_sym(Sym *sym, Section *s, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత)
{
    ఒకవేళ (nocode_wanted && (NODATA_WANTED || (s && s == cur_పాఠ్యం_section)))
        తిరిగి;
    put_extern_sym2(sym, s ? s->sh_అంకె : SHN_UNDEF, విలువ, కొలత, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC శూన్య greloca(Section *s, Sym *sym, గుర్తులేని దీర్ఘ స్థానభ్రంశం, పూర్ణాంకం type,
                     addr_t addend)
{
    పూర్ణాంకం c = 0;

    ఒకవేళ (nocode_wanted && s == cur_పాఠ్యం_section)
        తిరిగి;

    ఒకవేళ (sym) {
        ఒకవేళ (0 == sym->c) {
            put_extern_sym(sym, ఖాళీ, 0, 0);
            ఒకవేళ (sym->sym_scope
                && (sym->type.t & (VT_STATIC|VT_EXTERN)) == (VT_STATIC|VT_EXTERN)) {
                /* when a local function declaraion redeclares a global static one
                   then tccelf would not resolve them to the same symbol. */
                Sym *s = sym;
                అయితే (s->prev_tok)
                    s = s->prev_tok;
                s->c = sym->c;
            }
        }
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, స్థానభ్రంశం, type, c, addend);
}

#ఒకవేళ PTR_కొలత == 4
ST_FUNC శూన్య greloc(Section *s, Sym *sym, గుర్తులేని దీర్ఘ స్థానభ్రంశం, పూర్ణాంకం type)
{
    greloca(s, sym, స్థానభ్రంశం, type, 0);
}
#అయితే_ముగింపు

/* ------------------------------------------------------------------------- */
/* symbol allocator */
స్థిర Sym *__sym_malloc(శూన్య)
{
    Sym *sym_pool, *sym, *చివరి_sym;
    పూర్ణాంకం i;

    sym_pool = tcc_malloc(SYM_POOL_NB * పరిమాణం(Sym));
    dynarray_కూడు(&sym_pools, &nb_sym_pools, sym_pool);

    చివరి_sym = sym_free_మొదటి;
    sym = sym_pool;
    కొరకు(i = 0; i < SYM_POOL_NB; i++) {
        sym->తదుపరి = చివరి_sym;
        చివరి_sym = sym;
        sym++;
    }
    sym_free_మొదటి = చివరి_sym;
    తిరిగి చివరి_sym;
}

స్థిర అంతఃవరుస Sym *sym_malloc(శూన్య)
{
    Sym *sym;
#నిర్వచితం_కాకపోతే SYM_DEBUG
    sym = sym_free_మొదటి;
    ఒకవేళ (!sym)
        sym = __sym_malloc();
    sym_free_మొదటి = sym->తదుపరి;
    తిరిగి sym;
#లేకపోతే
    sym = tcc_malloc(పరిమాణం(Sym));
    తిరిగి sym;
#అయితే_ముగింపు
}

ST_INLN శూన్య sym_free(Sym *sym)
{
#నిర్వచితం_కాకపోతే SYM_DEBUG
    sym->తదుపరి = sym_free_మొదటి;
    sym_free_మొదటి = sym;
#లేకపోతే
    tcc_free(sym);
#అయితే_ముగింపు
}

/* push, without hashing */
ST_FUNC Sym *sym_push2(Sym **ps, పూర్ణాంకం v, పూర్ణాంకం t, పూర్ణాంకం c)
{
    Sym *s;

    s = sym_malloc();
    memset(s, 0, పరిమాణం *s);
    s->v = v;
    s->type.t = t;
    s->c = c;
    /* add in stack */
    s->prev = *ps;
    *ps = s;
    తిరిగి s;
}

/* find a symbol and return its associated structure. 's' is the top
   of the symbol stack */
ST_FUNC Sym *sym_find2(Sym *s, పూర్ణాంకం v)
{
    అయితే (s) {
        ఒకవేళ (s->v == v)
            తిరిగి s;
        s = s->prev;
    }
    తిరిగి ఖాళీ;
}

/* structure lookup */
ST_INLN Sym *struct_కనుగొను(పూర్ణాంకం v)
{
    v -= TOK_IDENT;
    ఒకవేళ ((గుర్తులేని)v >= (గుర్తులేని)(tok_ident - TOK_IDENT))
        తిరిగి ఖాళీ;
    తిరిగి పట్టిక_ident[v]->sym_struct;
}

/* find an identifier */
ST_INLN Sym *sym_కనుగొను(పూర్ణాంకం v)
{
    v -= TOK_IDENT;
    ఒకవేళ ((గుర్తులేని)v >= (గుర్తులేని)(tok_ident - TOK_IDENT))
        తిరిగి ఖాళీ;
    తిరిగి పట్టిక_ident[v]->sym_identifier;
}

/* make sym in-/visible to the parser */
స్థిర అంతఃవరుస శూన్య sym_link(Sym *s, పూర్ణాంకం yes)
{
    TokenSym *ts = పట్టిక_ident[(s->v & ~SYM_STRUCT) - TOK_IDENT];
    Sym **ps;
    ఒకవేళ (s->v & SYM_STRUCT)
        ps = &ts->sym_struct;
    లేకపోతే
        ps = &ts->sym_identifier;
    ఒకవేళ (yes) {
        s->prev_tok = *ps, *ps = s;
        s->sym_scope = local_scope;
    } లేకపోతే {
        *ps = s->prev_tok;
    }
}

స్థిర అంతఃవరుస పూర్ణాంకం sym_scope_ex(Sym *s)
{
    /* enums have 'sym_scope' overwritten by 'enum_val' */
    తిరిగి IS_ENUM_VAL (s->type.t)
        ? s->type.ref->sym_scope
        : s->sym_scope;
}

/* push a given symbol on the symbol stack */
ST_FUNC Sym *sym_నెట్టు(పూర్ణాంకం v, CType *type, పూర్ణాంకం r, పూర్ణాంకం c)
{
    Sym *s, **ps;
    ఒకవేళ (local_దొంతర)
        ps = &local_దొంతర;
    లేకపోతే
        ps = &global_దొంతర;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    /* don't record fields or anonymous symbols */
    ఒకవేళ ((v & ~SYM_STRUCT) < SYM_మొదటి_ANOM) {
        /* record symbol in token array */
        sym_link(s, 1);
        ఒకవేళ (s->prev_tok && sym_scope_ex(s->prev_tok) == local_scope)
            tcc_error("redeclaration of '%s'", get_tok_str(s->v, ఖాళీ));
    }
    తిరిగి s;
}

/* push a global identifier */
ST_FUNC Sym *global_identifier_నెట్టు(పూర్ణాంకం v, పూర్ణాంకం t, పూర్ణాంకం c)
{
    Sym *s, **ps;
    s = sym_push2(&global_దొంతర, v, t, c);
    s->r = VT_CONST | VT_SYM;
    /* don't record anonymous symbol */
    ఒకవేళ (v < SYM_మొదటి_ANOM) {
        ps = &పట్టిక_ident[v - TOK_IDENT]->sym_identifier;
        /* modify the top most local identifier, so that sym_identifier will
           point to 's' when popped; happens when called from inline asm */
        అయితే (*ps != ఖాళీ && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    తిరిగి s;
}

/* pop symbols until top reaches 'b'.  If KEEP is non-zero don't really
   pop them yet from the list, but do remove them from the token array.  */
ST_FUNC శూన్య sym_తీయి(Sym **ptop, Sym *b, పూర్ణాంకం keep)
{
    Sym *s, *ss;
    పూర్ణాంకం v;

    s = *ptop;
    అయితే(s != b) {
        ss = s->prev;
        v = s->v;
        /* remove symbol in token array */
        ఒకవేళ ((v & ~SYM_STRUCT) < SYM_మొదటి_ANOM)
            sym_link(s, 0);
	ఒకవేళ (!keep)
	    sym_free(s);
        s = ss;
    }
    ఒకవేళ (!keep)
	*ptop = b;
}

/* label lookup */
ST_FUNC Sym *label_కనుగొను(పూర్ణాంకం v)
{
    v -= TOK_IDENT;
    ఒకవేళ ((గుర్తులేని)v >= (గుర్తులేని)(tok_ident - TOK_IDENT))
        తిరిగి ఖాళీ;
    తిరిగి పట్టిక_ident[v]->sym_label;
}

ST_FUNC Sym *label_నెట్టు(Sym **ptop, పూర్ణాంకం v, పూర్ణాంకం flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, VT_STATIC, 0);
    s->r = flags;
    ps = &పట్టిక_ident[v - TOK_IDENT]->sym_label;
    ఒకవేళ (ptop == &global_label_దొంతర) {
        /* modify the top most local identifier, so that
           sym_identifier will point to 's' when popped */
        అయితే (*ps != ఖాళీ)
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    తిరిగి s;
}

/* pop labels until element last is reached. Look if any labels are
   undefined. Define symbols if '&&label' was used. */
ST_FUNC శూన్య label_తీయి(Sym **ptop, Sym *slast, పూర్ణాంకం keep)
{
    Sym *s, *s1;
    కొరకు(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        ఒకవేళ (s->r == LABEL_DECLARED) {
            tcc_warning_c(warn_all)("label '%s' declared but not used", get_tok_str(s->v, ఖాళీ));
        } లేకపోతే ఒకవేళ (s->r == LABEL_FORWARD) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ఖాళీ));
        } లేకపోతే {
            ఒకవేళ (s->c) {
                /* define corresponding symbol. A size of
                   1 is put. */
                put_extern_sym(s, cur_పాఠ్యం_section, s->jind, 1);
            }
        }
        /* remove label */
        ఒకవేళ (s->r != LABEL_GONE)
            పట్టిక_ident[s->v - TOK_IDENT]->sym_label = s->prev_tok;
        ఒకవేళ (!keep)
            sym_free(s);
        లేకపోతే
            s->r = LABEL_GONE;
    }
    ఒకవేళ (!keep)
        *ptop = slast;
}

/* ------------------------------------------------------------------------- */
స్థిర శూన్య vcheck_cmp(శూన్య)
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

    ఒకవేళ (vtop->r == VT_CMP && 0 == (nocode_wanted & ~సంకేతం_OFF_బిట్టు))
        gv(RC_INT);
}

స్థిర శూన్య vsetc(CType *type, పూర్ణాంకం r, CValue *vc)
{
    ఒకవేళ (vtop >= vstack + (VSTACK_కొలత - 1))
        tcc_error("memory full (vstack)");
    vcheck_cmp();
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    vtop->r2 = VT_CONST;
    vtop->c = *vc;
    vtop->sym = ఖాళీ;
}

ST_FUNC శూన్య vswap(శూన్య)
{
    SValue tmp;

    vcheck_cmp();
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}

/* pop stack value */
ST_FUNC శూన్య vpop(శూన్య)
{
    పూర్ణాంకం v;
    v = vtop->r & VT_VALMASK;
#ఒకవేళ defined(TCC_లక్ష్యం_I386) || defined(TCC_లక్ష్యం_X86_64)
    /* for x86, we need to pop the FP stack */
    ఒకవేళ (v == TREG_ST0) {
        o(0xd8dd); /* fstp %st(0) */
    } లేకపోతే
#అయితే_ముగింపు
    ఒకవేళ (v == VT_CMP) {
        /* need to put correct jump if && or || without test */
        gsym(vtop->jtrue);
        gsym(vtop->jfalse);
    }
    vtop--;
}

/* push constant of type "type" with useless value */
స్థిర శూన్య vpush(CType *type)
{
    vset(type, VT_CONST, 0);
}

/* push arbitrary 64bit constant */
స్థిర శూన్య vpush64(పూర్ణాంకం ty, గుర్తులేని దీర్ఘ దీర్ఘ v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = ఖాళీ;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* push integer constant */
ST_FUNC శూన్య vpushi(పూర్ణాంకం v)
{
    vpush64(VT_INT, v);
}

/* push a pointer sized constant */
స్థిర శూన్య vpushs(addr_t v)
{
    vpush64(VT_కొలత_T, v);
}

/* push long long constant */
స్థిర అంతఃవరుస శూన్య vpushll(దీర్ఘ దీర్ఘ v)
{
    vpush64(VT_LLONG, v);
}

ST_FUNC శూన్య vset(CType *type, పూర్ణాంకం r, పూర్ణాంకం v)
{
    CValue cval;
    cval.i = v;
    vsetc(type, r, &cval);
}

స్థిర శూన్య vseti(పూర్ణాంకం r, పూర్ణాంకం v)
{
    CType type;
    type.t = VT_INT;
    type.ref = ఖాళీ;
    vset(&type, r, v);
}

ST_FUNC శూన్య vpushv(SValue *v)
{
    ఒకవేళ (vtop >= vstack + (VSTACK_కొలత - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}

స్థిర శూన్య vdup(శూన్య)
{
    vpushv(vtop);
}

/* rotate the stack element at position n-1 to the top */
ST_FUNC శూన్య vrotb(పూర్ణాంకం n)
{
    SValue tmp;
    ఒకవేళ (--n < 1)
        తిరిగి;
    vcheck_cmp();
    tmp = vtop[-n];
    memmove(vtop - n, vtop - n + 1, పరిమాణం *vtop * n);
    vtop[0] = tmp;
}

/* rotate the top stack element into position n-1 */
ST_FUNC శూన్య vrott(పూర్ణాంకం n)
{
    SValue tmp;
    ఒకవేళ (--n < 1)
        తిరిగి;
    vcheck_cmp();
    tmp = vtop[0];
    memmove(vtop - n + 1, vtop - n, పరిమాణం *vtop * n);
    vtop[-n] = tmp;
}

/* reverse order of the the first n stack elements */
ST_FUNC శూన్య vrev(పూర్ణాంకం n)
{
    పూర్ణాంకం i;
    SValue tmp;
    vcheck_cmp();
    కొరకు (i = 0, n = -n; i > ++n; --i)
        tmp = vtop[i], vtop[i] = vtop[n], vtop[n] = tmp;
}

/* ------------------------------------------------------------------------- */
/* vtop->r = VT_CMP means CPU-flags have been set from comparison or test. */

/* called from generators to set the result from relational ops  */
ST_FUNC శూన్య vset_VT_CMP(పూర్ణాంకం op)
{
    vtop->r = VT_CMP;
    vtop->cmp_op = op;
    vtop->jfalse = 0;
    vtop->jtrue = 0;
}

/* called once before asking generators to load VT_CMP to a register */
స్థిర శూన్య vset_VT_JMP(శూన్య)
{
    పూర్ణాంకం op = vtop->cmp_op;

    ఒకవేళ (vtop->jtrue || vtop->jfalse) {
        పూర్ణాంకం origt = vtop->type.t;
        /* we need to jump to 'mov $0,%R' or 'mov $1,%R' */
        పూర్ణాంకం inv = op & (op < 2); /* small optimization */
        vseti(VT_JMP+inv, gvtst(inv, 0));
        vtop->type.t |= origt & (VT_UNSIGNED | VT_DEFSIGN);
    } లేకపోతే {
        /* otherwise convert flags (rsp. 0/1) to register */
        vtop->c.i = op;
        ఒకవేళ (op < 2) /* doesn't seem to happen */
            vtop->r = VT_CONST;
    }
}

/* Set CPU Flags, doesn't yet jump */
స్థిర శూన్య gvtst_సమితి(పూర్ణాంకం inv, పూర్ణాంకం t)
{
    పూర్ణాంకం *p;

    ఒకవేళ (vtop->r != VT_CMP) {
        vpushi(0);
        gen_op(TOK_NE);
        ఒకవేళ (vtop->r != VT_CMP) /* must be VT_CONST then */
            vset_VT_CMP(vtop->c.i != 0);
    }

    p = inv ? &vtop->jfalse : &vtop->jtrue;
    *p = gjmp_append(*p, t);
}

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */
స్థిర పూర్ణాంకం gvtst(పూర్ణాంకం inv, పూర్ణాంకం t)
{
    పూర్ణాంకం op, x, u;

    gvtst_సమితి(inv, t);
    t = vtop->jtrue, u = vtop->jfalse;
    ఒకవేళ (inv)
        x = u, u = t, t = x;
    op = vtop->cmp_op;

    /* jump to the wanted target */
    ఒకవేళ (op > 1)
        t = gjmp_cond(op ^ inv, t);
    లేకపోతే ఒకవేళ (op != inv)
        t = gjmp(t);
    /* resolve complementary jumps to here */
    gsym(u);

    vtop--;
    తిరిగి t;
}

/* generate a zero or nozero test */
స్థిర శూన్య gen_test_zero(పూర్ణాంకం op)
{
    ఒకవేళ (vtop->r == VT_CMP) {
        పూర్ణాంకం j;
        ఒకవేళ (op == TOK_EQ) {
            j = vtop->jfalse;
            vtop->jfalse = vtop->jtrue;
            vtop->jtrue = j;
            vtop->cmp_op ^= 1;
        }
    } లేకపోతే {
        vpushi(0);
        gen_op(op);
    }
}

/* ------------------------------------------------------------------------- */
/* push a symbol value of TYPE */
ST_FUNC శూన్య vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cval.i = 0;
    vsetc(type, VT_CONST | VT_SYM, &cval);
    vtop->sym = sym;
}

/* Return a static symbol pointing to a section */
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, గుర్తులేని దీర్ఘ స్థానభ్రంశం, గుర్తులేని దీర్ఘ కొలత)
{
    పూర్ణాంకం v;
    Sym *sym;

    v = anon_sym++;
    sym = sym_నెట్టు(v, type, VT_CONST | VT_SYM, 0);
    sym->type.t |= VT_STATIC;
    put_extern_sym(sym, sec, స్థానభ్రంశం, కొలత);
    తిరిగి sym;
}

/* push a reference to a section offset by adding a dummy symbol */
స్థిర శూన్య vpush_ref(CType *type, Section *sec, గుర్తులేని దీర్ఘ స్థానభ్రంశం, గుర్తులేని దీర్ఘ కొలత)
{
    vpushsym(type, get_sym_ref(type, sec, స్థానభ్రంశం, కొలత));  
}

/* define a new external reference to a symbol 'v' of type 'u' */
ST_FUNC Sym *external_global_sym(పూర్ణాంకం v, CType *type)
{
    Sym *s;

    s = sym_కనుగొను(v);
    ఒకవేళ (!s) {
        /* push forward reference */
        s = global_identifier_నెట్టు(v, type->t | VT_EXTERN, 0);
        s->type.ref = type->ref;
    } లేకపోతే ఒకవేళ (IS_ASM_SYM(s)) {
        s->type.t = type->t | (s->type.t & VT_EXTERN);
        s->type.ref = type->ref;
        update_storage(s);
    }
    తిరిగి s;
}

/* create an external reference with no specific type similar to asm labels.
   This avoids type conflicts if the symbol is used from C too */
ST_FUNC Sym *external_helper_sym(పూర్ణాంకం v)
{
    CType ct = { VT_ASM_FUNC, ఖాళీ };
    తిరిగి external_global_sym(v, &ct);
}

/* push a reference to an helper function (such as memmove) */
ST_FUNC శూన్య vpush_helper_func(పూర్ణాంకం v)
{
    vpushsym(&func_old_type, external_helper_sym(v));
}

/* Merge symbol attributes.  */
స్థిర శూన్య విలీనం_symattr(నిర్మాణం SymAttr *sa, నిర్మాణం SymAttr *sa1)
{
    ఒకవేళ (sa1->aligned && !sa->aligned)
      sa->aligned = sa1->aligned;
    sa->packed |= sa1->packed;
    sa->weak |= sa1->weak;
    sa->nodebug |= sa1->nodebug;
    ఒకవేళ (sa1->visibility != STV_DEFAULT) {
	పూర్ణాంకం vis = sa->visibility;
	ఒకవేళ (vis == STV_DEFAULT
	    || vis > sa1->visibility)
	  vis = sa1->visibility;
	sa->visibility = vis;
    }
    sa->dllexport |= sa1->dllexport;
    sa->nodecorate |= sa1->nodecorate;
    sa->dllimport |= sa1->dllimport;
}

/* Merge function attributes.  */
స్థిర శూన్య విలీనం_funcattr(నిర్మాణం FuncAttr *fa, నిర్మాణం FuncAttr *fa1)
{
    ఒకవేళ (fa1->func_call && !fa->func_call)
      fa->func_call = fa1->func_call;
    ఒకవేళ (fa1->func_type && !fa->func_type)
      fa->func_type = fa1->func_type;
    ఒకవేళ (fa1->func_వాదనలు && !fa->func_వాదనలు)
      fa->func_వాదనలు = fa1->func_వాదనలు;
    ఒకవేళ (fa1->func_noreturn)
      fa->func_noreturn = 1;
    ఒకవేళ (fa1->func_ctor)
      fa->func_ctor = 1;
    ఒకవేళ (fa1->func_dtor)
      fa->func_dtor = 1;
}

/* Merge attributes.  */
స్థిర శూన్య విలీనం_attr(AttributeDef *ad, AttributeDef *ad1)
{
    విలీనం_symattr(&ad->a, &ad1->a);
    విలీనం_funcattr(&ad->f, &ad1->f);

    ఒకవేళ (ad1->section)
      ad->section = ad1->section;
    ఒకవేళ (ad1->alias_లక్ష్యం)
      ad->alias_లక్ష్యం = ad1->alias_లక్ష్యం;
    ఒకవేళ (ad1->asm_label)
      ad->asm_label = ad1->asm_label;
    ఒకవేళ (ad1->attr_బహుళకం)
      ad->attr_బహుళకం = ad1->attr_బహుళకం;
}

/* Merge some type attributes.  */
స్థిర శూన్య patch_type(Sym *sym, CType *type)
{
    ఒకవేళ (!(type->t & VT_EXTERN) || IS_ENUM_VAL(sym->type.t)) {
        ఒకవేళ (!(sym->type.t & VT_EXTERN))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ఖాళీ));
        sym->type.t &= ~VT_EXTERN;
    }

    ఒకవేళ (IS_ASM_SYM(sym)) {
        /* stay static if both are static */
        sym->type.t = type->t & (sym->type.t | ~VT_STATIC);
        sym->type.ref = type->ref;
        ఒకవేళ ((type->t & VT_BTYPE) != VT_FUNC && !(type->t & VT_ARRAY))
            sym->r |= VT_LVAL;
    }

    ఒకవేళ (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ఖాళీ));

    } లేకపోతే ఒకవేళ ((sym->type.t & VT_BTYPE) == VT_FUNC) {
        పూర్ణాంకం static_proto = sym->type.t & VT_STATIC;
        పూర్ణాంకం ft1 = sym->type.ref->f.func_type;
        పూర్ణాంకం ft2 = type->ref->f.func_type;

        /* warn if static follows non-static function declaration */
        ఒకవేళ ((type->t & VT_STATIC) && !static_proto
            /* XXX this test for inline shouldn't be here.  Until we
               implement gnu-inline mode again it silences a warning for
               mingw caused by our workarounds.  */
            && !((type->t | sym->type.t) & VT_INLINE))
            tcc_warning("static storage ignored for redefinition of '%s'",
                get_tok_str(sym->v, ఖాళీ));

        /* set 'inline' if both agree or if one has static */
        ఒకవేళ ((type->t | sym->type.t) & VT_INLINE) {
            ఒకవేళ (!((type->t ^ sym->type.t) & VT_INLINE)
             || ((type->t | sym->type.t) & VT_STATIC))
                static_proto |= VT_INLINE;
        }

        ఒకవేళ (0 == (type->t & VT_EXTERN)) {
            నిర్మాణం FuncAttr f = sym->type.ref->f;
            /* put complete type, use static from prototype */
            sym->type.t = (type->t & ~(VT_STATIC|VT_INLINE)) | static_proto;
            ఒకవేళ (ft1 != FUNC_OLD)
                type->ref->f.func_type = ft1;
            sym->type.ref = type->ref;
            విలీనం_funcattr(&sym->type.ref->f, &f);
        } లేకపోతే {
            sym->type.t &= ~VT_INLINE | static_proto;
            ఒకవేళ (ft1 == FUNC_OLD && ft2 != FUNC_OLD)
                sym->type.ref = type->ref;
        }

    } లేకపోతే {
        ఒకవేళ ((sym->type.t & VT_ARRAY) && type->ref->c >= 0) {
            /* set array size if it was omitted in extern declaration */
            sym->type.ref->c = type->ref->c;
        }
        ఒకవేళ ((type->t ^ sym->type.t) & VT_STATIC)
            tcc_warning("storage mismatch for redefinition of '%s'",
                get_tok_str(sym->v, ఖాళీ));
    }
}

/* Merge some storage attributes.  */
స్థిర శూన్య patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    ఒకవేళ (type)
        patch_type(sym, type);

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (sym->a.dllimport != ad->a.dllimport)
        tcc_error("incompatible dll linkage for redefinition of '%s'",
            get_tok_str(sym->v, ఖాళీ));
#అయితే_ముగింపు
    విలీనం_symattr(&sym->a, &ad->a);
    ఒకవేళ (ad->asm_label)
        sym->asm_label = ad->asm_label;
    update_storage(sym);
}

/* copy sym to other stack */
స్థిర Sym *sym_copy(Sym *s0, Sym **ps)
{
    Sym *s;
    s = sym_malloc(), *s = *s0;
    s->prev = *ps, *ps = s;
    ఒకవేళ ((s->v & ~SYM_STRUCT) < SYM_మొదటి_ANOM)
        sym_link(s, 1);
    తిరిగి s;
}

/* Symbol 's' was locally declared 'extern' (or as function), and is
   on global_stack.  Now must copy its 'ref' to global_stack too */
స్థిర శూన్య move_ref_గమ్యం_global(Sym *s)
{
    Sym *l, **lp;
    పూర్ణాంకం n, bt;

    bt = s->type.t & VT_BTYPE;
    ఒకవేళ (!(bt == VT_PTR
       || bt == VT_FUNC
       || bt == VT_STRUCT
       || IS_ENUM(s->type.t)))
        తిరిగి;

    కొరకు (s = s->type.ref, n = 0; s; s = s->తదుపరి) {
        కొరకు (lp = &local_దొంతర; !!(l = *lp); lp = &l->prev) {
            ఒకవేళ (l == s) {
                *lp = s->prev;
                s->prev = global_దొంతర, global_దొంతర = s;
                ఒకవేళ (n || bt == VT_PTR || bt == VT_FUNC) {
                    move_ref_గమ్యం_global(s);
                } లేకపోతే {
                    ఒకవేళ ((s->v & ~SYM_STRUCT) < SYM_మొదటి_ANOM) {
                        /* copy struct/enum tag to local scope */
                        s->v |= SYM_క్షేత్రం;
                        l = sym_copy(s, lp);
                        l->v &= ~SYM_క్షేత్రం;
                    }
                }
                ఒకవేళ (bt != VT_PTR)
                    n = 1;
                ఆపు;
            }
        }
        ఒకవేళ (n == 0) /* no next (VT_PTR) or ref not on local_stack */
            ఆపు;
    }
}

/* define a new external reference to a symbol 'v' */
స్థిర Sym *external_sym(పూర్ణాంకం v, CType *type, పూర్ణాంకం r, AttributeDef *ad)
{
    Sym *s;

    /* look for global symbol */
    s = sym_కనుగొను(v);
    అయితే (s && s->sym_scope)
        s = s->prev_tok;

    ఒకవేళ (!s) {
        /* push forward reference */
        s = global_identifier_నెట్టు(v, type->t, 0);
        s->r |= r;
        s->a = ad->a;
        s->asm_label = ad->asm_label;
        s->type.ref = type->ref;
    } లేకపోతే {
        patch_storage(s, ad, type);
    }
    ఒకవేళ (local_దొంతర) {
        /* make sure that type->ref is on global stack */
        move_ref_గమ్యం_global(s);
        /* put into local scope */
        sym_copy(s, &local_దొంతర);
    }
    తిరిగి s;
}

/* save registers up to (vtop - n) stack entry */
ST_FUNC శూన్య save_regs(పూర్ణాంకం n)
{
    SValue *p, *p1;
    కొరకు(p = vstack, p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}

/* save r to the memory stack, and mark it as being free */
ST_FUNC శూన్య save_reg(పూర్ణాంకం r)
{
    save_reg_upstack(r, 0);
}

/* save r to the memory stack, and mark it as being free,
   if seen up to (vtop - n) stack entry */
ST_FUNC శూన్య save_reg_upstack(పూర్ణాంకం r, పూర్ణాంకం n)
{
    పూర్ణాంకం l, కొలత, align, bt, r2;
    SValue *p, *p1, sv;

    ఒకవేళ ((r &= VT_VALMASK) >= VT_CONST)
        తిరిగి;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    l = r2 = 0;
    కొరకు(p = vstack, p1 = vtop - n; p <= p1; p++) {
        ఒకవేళ ((p->r & VT_VALMASK) == r || p->r2 == r) {
            /* must save value on stack if not already done */
            ఒకవేళ (!l) {
                bt = p->type.t & VT_BTYPE;
                ఒకవేళ (bt == VT_VOID)
                    కొనసాగు;
                ఒకవేళ ((p->r & VT_LVAL) || bt == VT_FUNC)
                    bt = VT_PTR;
                sv.type.t = bt;
                కొలత = type_కొలత(&sv.type, &align);
                l = get_తాత్కాలిక_local_var(కొలత, align, &r2);
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = l;
		sv.sym = ఖాళీ;
                store(p->r & VT_VALMASK, &sv);
#ఒకవేళ defined(TCC_లక్ష్యం_I386) || defined(TCC_లక్ష్యం_X86_64)
                /* x86 specific: need to pop fp register ST0 if saved */
                ఒకవేళ (r == TREG_ST0) {
                    o(0xd8dd); /* fstp %st(0) */
                }
#అయితే_ముగింపు
                /* special long long case */
                ఒకవేళ (p->r2 < VT_CONST && USING_TWO_పదాలు(bt)) {
                    sv.c.i += PTR_కొలత;
                    store(p->r2, &sv);
                }
            }
            /* mark that stack entry as being saved on the stack */
            ఒకవేళ (p->r & VT_LVAL) {
                /* also clear the bounded flag because the
                   relocation address of the function was stored in
                   p->c.i */
                p->r = (p->r & ~(VT_VALMASK | VT_BOUNDED)) | VT_LLOCAL;
            } లేకపోతే {
                p->r = VT_LVAL | VT_LOCAL;
                p->type.t &= ~VT_ARRAY; /* cannot combine VT_LVAL with VT_ARRAY */
            }
            p->sym = ఖాళీ;
            p->r2 = r2;
            p->c.i = l;
        }
    }
}

#నిర్వచితమైతే TCC_లక్ష్యం_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC పూర్ణాంకం get_reg_ex(పూర్ణాంకం rc, పూర్ణాంకం rc2)
{
    పూర్ణాంకం r;
    SValue *p;
    
    కొరకు(r=0;r<NB_REGS;r++) {
        ఒకవేళ (reg_classes[r] & rc2) {
            పూర్ణాంకం n;
            n=0;
            కొరకు(p = vstack; p <= vtop; p++) {
                ఒకవేళ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    n++;
            }
            ఒకవేళ (n <= 1)
                తిరిగి r;
        }
    }
    తిరిగి get_reg(rc);
}
#అయితే_ముగింపు

/* find a free register of class 'rc'. If none, save one register */
ST_FUNC పూర్ణాంకం get_reg(పూర్ణాంకం rc)
{
    పూర్ణాంకం r;
    SValue *p;

    /* find a free register */
    కొరకు(r=0;r<NB_REGS;r++) {
        ఒకవేళ (reg_classes[r] & rc) {
            ఒకవేళ (nocode_wanted)
                తిరిగి r;
            కొరకు(p=vstack;p<=vtop;p++) {
                ఒకవేళ ((p->r & VT_VALMASK) == r ||
                    p->r2 == r)
                    వెళ్ళు notfound;
            }
            తిరిగి r;
        }
    notfound: ;
    }
    
    /* no register left : free the first one on the stack (VERY
       IMPORTANT to start from the bottom to ensure that we don't
       spill registers used in gen_opi()) */
    కొరకు(p=vstack;p<=vtop;p++) {
        /* look at second register (if long long) */
        r = p->r2;
        ఒకవేళ (r < VT_CONST && (reg_classes[r] & rc))
            వెళ్ళు save_దొరికింది;
        r = p->r & VT_VALMASK;
        ఒకవేళ (r < VT_CONST && (reg_classes[r] & rc)) {
        save_దొరికింది:
            save_reg(r);
            తిరిగి r;
        }
    }
    /* Should never comes here */
    తిరిగి -1;
}

/* find a free temporary local variable (return the offset on stack) match
   size and align. If none, add new temporary stack variable */
స్థిర పూర్ణాంకం get_తాత్కాలిక_local_var(పూర్ణాంకం కొలత,పూర్ణాంకం align, పూర్ణాంకం *r2)
{
    పూర్ణాంకం i;
    నిర్మాణం తాత్కాలిక_local_variable *తాత్కాలిక_var;
    SValue *p;
    పూర్ణాంకం r;
    గుర్తులేని వాడిన = 0;

    /* mark locations that are still in use */
    కొరకు (p = vstack; p <= vtop; p++) {
	r = p->r & VT_VALMASK;
	ఒకవేళ (r == VT_LOCAL || r == VT_LLOCAL) {
	    r = p->r2 - (VT_CONST + 1);
	    ఒకవేళ (r >= 0 && r < MAX_తాత్కాలిక_LOCAL_VARIABLE_సంఖ్య)
	        వాడిన |= 1<<r;
	}
    }
    కొరకు (i=0;i<nb_తాత్కాలిక_local_vars;i++) {
	తాత్కాలిక_var=&arr_తాత్కాలిక_local_vars[i];
	ఒకవేళ(!(వాడిన & 1<<i)
	 && తాత్కాలిక_var->కొలత>=కొలత
	 && తాత్కాలిక_var->align>=align) {
ret_tmp:
	    *r2 = (VT_CONST + 1) + i;
	    తిరిగి తాత్కాలిక_var->location;
	}
    }
    loc = (loc - కొలత) & -align;
    ఒకవేళ (nb_తాత్కాలిక_local_vars<MAX_తాత్కాలిక_LOCAL_VARIABLE_సంఖ్య) {
	తాత్కాలిక_var=&arr_తాత్కాలిక_local_vars[i];
	తాత్కాలిక_var->location=loc;
	తాత్కాలిక_var->కొలత=కొలత;
	తాత్కాలిక_var->align=align;
	nb_తాత్కాలిక_local_vars++;
	వెళ్ళు ret_tmp;
    }
    *r2 = VT_CONST;
    తిరిగి loc;
}

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
స్థిర శూన్య move_reg(పూర్ణాంకం r, పూర్ణాంకం s, పూర్ణాంకం t)
{
    SValue sv;

    ఒకవేళ (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ఖాళీ;
        sv.r = s;
        sv.c.i = 0;
        ఎక్కించు(r, &sv);
    }
}

/* get address of vtop (vtop MUST BE an lvalue) */
ST_FUNC శూన్య gaddrof(శూన్య)
{
    vtop->r &= ~VT_LVAL;
    /* tricky: if saved lvalue, then we can go back to lvalue */
    ఒకవేళ ((vtop->r & VT_VALMASK) == VT_LLOCAL)
        vtop->r = (vtop->r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
}

#నిర్వచితమైతే CONFIG_TCC_BCHECK
/* generate a bounded pointer addition */
స్థిర శూన్య gen_bounded_ptr_కూడు(శూన్య)
{
    పూర్ణాంకం save = (vtop[-1].r & VT_VALMASK) == VT_LOCAL;
    ఒకవేళ (save) {
      vpushv(&vtop[-1]);
      vrott(3);
    }
    vpush_helper_func(TOK_bound_ptr_కూడు);
    vrott(3);
    gfunc_call(2);
    vtop -= save;
    vpushi(0);
    /* returned pointer is in REG_IRET */
    vtop->r = REG_IRET | VT_BOUNDED;
    ఒకవేళ (nocode_wanted)
        తిరిగి;
    /* relocation offset of the bounding function call point */
    vtop->c.i = (cur_పాఠ్యం_section->reloc->దత్తాంశం_స్థానభ్రంశం - పరిమాణం(ElfW_Rel));
}

/* patch pointer addition in vtop so that pointer dereferencing is
   also tested */
స్థిర శూన్య gen_bounded_ptr_deref(శూన్య)
{
    addr_t func;
    పూర్ణాంకం కొలత, align;
    ElfW_Rel *rel;
    Sym *sym;

    ఒకవేళ (nocode_wanted)
        తిరిగి;

    కొలత = type_కొలత(&vtop->type, &align);
    ఎంపిక(కొలత) {
    స్థితి  1: func = TOK___bound_ptr_indir1; ఆపు;
    స్థితి  2: func = TOK___bound_ptr_indir2; ఆపు;
    స్థితి  4: func = TOK___bound_ptr_indir4; ఆపు;
    స్థితి  8: func = TOK___bound_ptr_indir8; ఆపు;
    స్థితి 12: func = TOK___bound_ptr_indir12; ఆపు;
    స్థితి 16: func = TOK___bound_ptr_indir16; ఆపు;
    అప్రమేయ:
        /* may happen with struct member access */
        తిరిగి;
    }
    sym = external_helper_sym(func);
    ఒకవేళ (!sym->c)
        put_extern_sym(sym, ఖాళీ, 0, 0);
    /* patch relocation */
    /* XXX: find a better solution ? */
    rel = (ElfW_Rel *)(cur_పాఠ్యం_section->reloc->దత్తాంశం + vtop->c.i);
    rel->r_info = ELFW(R_INFO)(sym->c, ELFW(R_TYPE)(rel->r_info));
}

/* generate lvalue bound code */
స్థిర శూన్య gbound(శూన్య)
{
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    ఒకవేళ (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        ఒకవేళ (!(vtop->r & VT_BOUNDED)) {
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_కూడు();
            vtop->r |= VT_LVAL;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}

/* we need to call __bound_ptr_add before we start to load function
   args into registers */
ST_FUNC శూన్య gbound_వాదనలు(పూర్ణాంకం nb_వాదనలు)
{
    పూర్ణాంకం i, v;
    SValue *sv;

    కొరకు (i = 1; i <= nb_వాదనలు; ++i)
        ఒకవేళ (vtop[1 - i].r & VT_MUSTBOUND) {
            vrotb(i);
            gbound();
            vrott(i);
        }

    sv = vtop - nb_వాదనలు;
    ఒకవేళ (sv->r & VT_SYM) {
        v = sv->sym->v;
        ఒకవేళ (v == TOK_setjmp
          || v == TOK__setjmp
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
          || v == TOK_sigsetjmp
          || v == TOK___sigsetjmp
#అయితే_ముగింపు
          ) {
            vpush_helper_func(TOK___bound_setjmp);
            vpushv(sv + 1);
            gfunc_call(1);
            func_bound_కూడు_epilog = 1;
        }
        ఒకవేళ (v == TOK_alloca)
            func_bound_కూడు_epilog = 1;
#ఒకవేళ TARGETOS_NetBSD
        ఒకవేళ (v == TOK_longjmp) /* undo rename to __longjmp14 */
            sv->sym->asm_label = TOK___bound_longjmp;
#అయితే_ముగింపు
    }
}

/* Add bounds for local symbols from S to E (via ->prev) */
స్థిర శూన్య కూడు_local_bounds(Sym *s, Sym *e)
{
    కొరకు (; s != e; s = s->prev) {
        ఒకవేళ (!s->v || (s->r & VT_VALMASK) != VT_LOCAL)
          కొనసాగు;
        /* Add arrays/structs/unions because we always take address */
        ఒకవేళ ((s->type.t & VT_ARRAY)
            || (s->type.t & VT_BTYPE) == VT_STRUCT
            || s->a.addrtaken) {
            /* add local bound info */
            పూర్ణాంకం align, కొలత = type_కొలత(&s->type, &align);
            addr_t *bounds_ptr = section_ptr_కూడు(lbounds_section,
                                                 2 * పరిమాణం(addr_t));
            bounds_ptr[0] = s->c;
            bounds_ptr[1] = కొలత;
        }
    }
}
#అయితే_ముగింపు

/* add debug info for locals or function parameters, optionally
   register bounds */
స్థిర శూన్య tcc_debug_చివర_scope(Sym *b, పూర్ణాంకం bounds)
{
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (tcc_state->do_bounds_check && bounds)
        కూడు_local_bounds(local_దొంతర, b);
#అయితే_ముగింపు
    tcc_కూడు_debug_info (tcc_state, local_దొంతర, b);
}

/* increment an lvalue pointer */
స్థిర శూన్య incr_స్థానభ్రంశం(పూర్ణాంకం స్థానభ్రంశం)
{
    పూర్ణాంకం t = vtop->type.t;
    gaddrof(); /* remove VT_LVAL */
    vtop->type.t = VT_PTRDIFF_T; /* set scalar type */
    vpushs(స్థానభ్రంశం);
    gen_op('+');
    vtop->r |= VT_LVAL;
    vtop->type.t = t;
}

స్థిర శూన్య incr_bf_adr(పూర్ణాంకం o)
{
    vtop->type.t = VT_BYTE | VT_UNSIGNED;
    incr_స్థానభ్రంశం(o);
}

/* single-byte load mode for packed or otherwise unaligned bitfields */
స్థిర శూన్య ఎక్కించు_packed_bf(CType *type, పూర్ణాంకం బిట్టు_pos, పూర్ణాంకం బిట్టు_కొలత_2)
{
    పూర్ణాంకం n, o, బిట్లు;
    save_reg_upstack(vtop->r, 1);
    vpush64(type->t & VT_BTYPE, 0); // B X
    బిట్లు = 0, o = బిట్టు_pos >> 3, బిట్టు_pos &= 7;
    చేయి {
        vswap(); // X B
        incr_bf_adr(o);
        vdup(); // X B B
        n = 8 - బిట్టు_pos;
        ఒకవేళ (n > బిట్టు_కొలత_2)
            n = బిట్టు_కొలత_2;
        ఒకవేళ (బిట్టు_pos)
            vpushi(బిట్టు_pos), gen_op(TOK_SHR), బిట్టు_pos = 0; // X B Y
        ఒకవేళ (n < 8)
            vpushi((1 << n) - 1), gen_op('&');
        gen_cast(type);
        ఒకవేళ (బిట్లు)
            vpushi(బిట్లు), gen_op(TOK_SHL);
        vrotb(3); // B Y X
        gen_op('|'); // B X
        బిట్లు += n, బిట్టు_కొలత_2 -= n, o = 1;
    } అయితే (బిట్టు_కొలత_2);
    vswap(), vpop();
    ఒకవేళ (!(type->t & VT_UNSIGNED)) {
        n = ((type->t & VT_BTYPE) == VT_LLONG ? 64 : 32) - బిట్లు;
        vpushi(n), gen_op(TOK_SHL);
        vpushi(n), gen_op(TOK_SAR);
    }
}

/* single-byte store mode for packed or otherwise unaligned bitfields */
స్థిర శూన్య store_packed_bf(పూర్ణాంకం బిట్టు_pos, పూర్ణాంకం బిట్టు_కొలత_2)
{
    పూర్ణాంకం బిట్లు, n, o, m, c;
    c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    vswap(); // X B
    save_reg_upstack(vtop->r, 1);
    బిట్లు = 0, o = బిట్టు_pos >> 3, బిట్టు_pos &= 7;
    చేయి {
        incr_bf_adr(o); // X B
        vswap(); //B X
        c ? vdup() : gv_dup(); // B V X
        vrott(3); // X B V
        ఒకవేళ (బిట్లు)
            vpushi(బిట్లు), gen_op(TOK_SHR);
        ఒకవేళ (బిట్టు_pos)
            vpushi(బిట్టు_pos), gen_op(TOK_SHL);
        n = 8 - బిట్టు_pos;
        ఒకవేళ (n > బిట్టు_కొలత_2)
            n = బిట్టు_కొలత_2;
        ఒకవేళ (n < 8) {
            m = ((1 << n) - 1) << బిట్టు_pos;
            vpushi(m), gen_op('&'); // X B V1
            vpushv(vtop-1); // X B V1 B
            vpushi(m & 0x80 ? ~m & 0x7f : ~m);
            gen_op('&'); // X B V1 B1
            gen_op('|'); // X B V2
        }
        vdup(), vtop[-1] = vtop[-2]; // X B B V2
        vstore(), vpop(); // X B
        బిట్లు += n, బిట్టు_కొలత_2 -= n, బిట్టు_pos = 0, o = 1;
    } అయితే (బిట్టు_కొలత_2);
    vpop(), vpop();
}

స్థిర పూర్ణాంకం adjust_bf(SValue *sv, పూర్ణాంకం బిట్టు_pos, పూర్ణాంకం బిట్టు_కొలత_2)
{
    పూర్ణాంకం t;
    ఒకవేళ (0 == sv->type.ref)
        తిరిగి 0;
    t = sv->type.ref->auxtype;
    ఒకవేళ (t != -1 && t != VT_STRUCT) {
        sv->type.t = (sv->type.t & ~(VT_BTYPE | VT_LONG)) | t;
        sv->r |= VT_LVAL;
    }
    తిరిగి t;
}

/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */
ST_FUNC పూర్ణాంకం gv(పూర్ణాంకం rc)
{
    పూర్ణాంకం r, r2, r_ok, r2_ok, rc2, bt;
    పూర్ణాంకం బిట్టు_pos, బిట్టు_కొలత_2, కొలత, align;

    /* NOTE: get_reg can modify vstack[] */
    ఒకవేళ (vtop->type.t & VT_BITFIELD) {
        CType type;

        బిట్టు_pos = బిట్టు_POS(vtop->type.t);
        బిట్టు_కొలత_2 = బిట్టు_కొలత(vtop->type.t);
        /* remove bit field info to avoid loops */
        vtop->type.t &= ~VT_STRUCT_ముసుగు;

        type.ref = ఖాళీ;
        type.t = vtop->type.t & VT_UNSIGNED;
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_BOOL)
            type.t |= VT_UNSIGNED;

        r = adjust_bf(vtop, బిట్టు_pos, బిట్టు_కొలత_2);

        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_LLONG)
            type.t |= VT_LLONG;
        లేకపోతే
            type.t |= VT_INT;

        ఒకవేళ (r == VT_STRUCT) {
            ఎక్కించు_packed_bf(&type, బిట్టు_pos, బిట్టు_కొలత_2);
        } లేకపోతే {
            పూర్ణాంకం బిట్లు = (type.t & VT_BTYPE) == VT_LLONG ? 64 : 32;
            /* cast to int to propagate signedness in following ops */
            gen_cast(&type);
            /* generate shifts */
            vpushi(బిట్లు - (బిట్టు_pos + బిట్టు_కొలత_2));
            gen_op(TOK_SHL);
            vpushi(బిట్లు - బిట్టు_కొలత_2);
            /* NOTE: transformed to SHR if unsigned */
            gen_op(TOK_SAR);
        }
        r = gv(rc);
    } లేకపోతే {
        ఒకవేళ (is_float(vtop->type.t) && 
            (vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
            /* CPUs usually cannot use float constants, so we store them
               generically in data segment */
            init_params p = { rodata_section };
            గుర్తులేని దీర్ఘ స్థానభ్రంశం;
            కొలత = type_కొలత(&vtop->type, &align);
            ఒకవేళ (NODATA_WANTED)
                కొలత = 0, align = 1;
            స్థానభ్రంశం = section_కూడు(p.sec, కొలత, align);
            vpush_ref(&vtop->type, p.sec, స్థానభ్రంశం, కొలత);
	    vswap();
	    init_putv(&p, &vtop->type, స్థానభ్రంశం);
	    vtop->r |= VT_LVAL;
        }
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (vtop->r & VT_MUSTBOUND) 
            gbound();
#అయితే_ముగింపు

        bt = vtop->type.t & VT_BTYPE;
        ఒకవేళ (bt == VT_VOID || bt == VT_STRUCT) /* should not happen */
            తిరిగి vtop->r;

#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
        /* XXX mega hack */
        ఒకవేళ (bt == VT_LDOUBLE && rc == RC_FLOAT)
          rc = RC_INT;
#అయితే_ముగింపు
        rc2 = RC2_TYPE(bt, rc);

        /* need to reload if:
           - constant
           - lvalue (need to dereference pointer)
           - already a register, but not in the right class */
        r = vtop->r & VT_VALMASK;
        r_ok = !(vtop->r & VT_LVAL) && (r < VT_CONST) && (reg_classes[r] & rc);
        r2_ok = !rc2 || ((vtop->r2 < VT_CONST) && (reg_classes[vtop->r2] & rc2));

        ఒకవేళ (!r_ok || !r2_ok) {

            ఒకవేళ (!r_ok) {
                ఒకవేళ (1 /* we can 'mov (r),r' in cases */
                    && r < VT_CONST
                    && (reg_classes[r] & rc)
                    && !rc2
                    )
                    save_reg_upstack(r, 1);
                లేకపోతే
                    r = get_reg(rc);
            }

            ఒకవేళ (rc2) {
                పూర్ణాంకం ఎక్కించు_type = (bt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                పూర్ణాంకం original_type = vtop->type.t;

                /* two register type load :
                   expand to two words temporarily */
                ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST) {
                    /* load constant */
                    గుర్తులేని దీర్ఘ దీర్ఘ ll = vtop->c.i;
                    vtop->c.i = ll; /* first word */
                    ఎక్కించు(r, vtop);
                    vtop->r = r; /* save register value */
                    vpushi(ll >> 32); /* second word */
                } లేకపోతే ఒకవేళ (vtop->r & VT_LVAL) {
                    /* We do not want to modifier the long long pointer here.
                       So we save any other instances down the stack */
                    save_reg_upstack(vtop->r, 1);
                    /* load from memory */
                    vtop->type.t = ఎక్కించు_type;
                    ఎక్కించు(r, vtop);
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    /* increment pointer to get second word */
                    incr_స్థానభ్రంశం(PTR_కొలత);
                } లేకపోతే {
                    /* move registers */
                    ఒకవేళ (!r_ok)
                        ఎక్కించు(r, vtop);
                    ఒకవేళ (r2_ok && vtop->r2 < VT_CONST)
                        వెళ్ళు పూర్తి;
                    vdup();
                    vtop[-1].r = r; /* save register value */
                    vtop->r = vtop[-1].r2;
                }
                /* Allocate second register. Here we rely on the fact that
                   get_reg() tries first to free r2 of an SValue. */
                r2 = get_reg(rc2);
                ఎక్కించు(r2, vtop);
                vpop();
                /* write second register */
                vtop->r2 = r2;
            పూర్తి:
                vtop->type.t = original_type;
            } లేకపోతే {
                ఒకవేళ (vtop->r == VT_CMP)
                    vset_VT_JMP();
                /* one register type load */
                ఎక్కించు(r, vtop);
            }
        }
        vtop->r = r;
#నిర్వచితమైతే TCC_లక్ష్యం_C67
        /* uses register pairs for doubles */
        ఒకవేళ (bt == VT_DOUBLE)
            vtop->r2 = r+1;
#అయితే_ముగింపు
    }
    తిరిగి r;
}

/* generate vtop[-1] and vtop[0] in resp. classes rc1 and rc2 */
ST_FUNC శూన్య gv2(పూర్ణాంకం rc1, పూర్ణాంకం rc2)
{
    /* generate more generic register first. But VT_JMP or VT_CMP
       values must be generated first in all cases to avoid possible
       reload errors */
    ఒకవేళ (vtop->r != VT_CMP && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        /* test if reload is needed for first register */
        ఒకవేళ ((vtop[-1].r & VT_VALMASK) >= VT_CONST) {
            vswap();
            gv(rc1);
            vswap();
        }
    } లేకపోతే {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        /* test if reload is needed for first register */
        ఒకవేళ ((vtop[0].r & VT_VALMASK) >= VT_CONST) {
            gv(rc2);
        }
    }
}

#ఒకవేళ PTR_కొలత == 4
/* expand 64bit on stack in two ints */
ST_FUNC శూన్య lexpand(శూన్య)
{
    పూర్ణాంకం u, v;
    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    v = vtop->r & (VT_VALMASK | VT_LVAL);
    ఒకవేళ (v == VT_CONST) {
        vdup();
        vtop[0].c.i >>= 32;
    } లేకపోతే ఒకవేళ (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
        vdup();
        vtop[0].c.i += 4;
    } లేకపోతే {
        gv(RC_INT);
        vdup();
        vtop[0].r = vtop[-1].r2;
        vtop[0].r2 = vtop[-1].r2 = VT_CONST;
    }
    vtop[0].type.t = vtop[-1].type.t = VT_INT | u;
}
#అయితే_ముగింపు

#ఒకవేళ PTR_కొలత == 4
/* build a long long from two ints */
స్థిర శూన్య lbuild(పూర్ణాంకం t)
{
    gv2(RC_INT, RC_INT);
    vtop[-1].r2 = vtop[0].r;
    vtop[-1].type.t = t;
    vpop();
}
#అయితే_ముగింపు

/* convert stack entry to register and duplicate its value in another
రిజిస్టరు*/
స్థిర శూన్య gv_dup(శూన్య)
{
    పూర్ణాంకం t, rc, r;

    t = vtop->type.t;
#ఒకవేళ PTR_కొలత == 4
    ఒకవేళ ((t & VT_BTYPE) == VT_LLONG) {
        ఒకవేళ (t & VT_BITFIELD) {
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
        తిరిగి;
    }
#అయితే_ముగింపు
    /* duplicate value */
    rc = RC_TYPE(t);
    gv(rc);
    r = get_reg(rc);
    vdup();
    ఎక్కించు(r, vtop);
    vtop->r = r;
}

#ఒకవేళ PTR_కొలత == 4
/* generate CPU independent (unsigned) long long operations */
స్థిర శూన్య gen_opl(పూర్ణాంకం op)
{
    పూర్ణాంకం t, a, b, op1, c, i;
    పూర్ణాంకం func;
    గుర్తులేని పొట్టి reg_iret = REG_IRET;
    గుర్తులేని పొట్టి reg_lret = REG_IRE2;
    SValue tmp;

    ఎంపిక(op) {
    స్థితి '/':
    స్థితి TOK_PDIV:
        func = TOK___divdi3;
        వెళ్ళు gen_func;
    స్థితి TOK_UDIV:
        func = TOK___udivdi3;
        వెళ్ళు gen_func;
    స్థితి '%':
        func = TOK___moddi3;
        వెళ్ళు gen_mod_func;
    స్థితి TOK_UMOD:
        func = TOK___umoddi3;
    gen_mod_func:
#నిర్వచితమైతే TCC_ARM_EABI
        reg_iret = TREG_R2;
        reg_lret = TREG_R3;
#అయితే_ముగింపు
    gen_func:
        /* call generic long long function */
        vpush_helper_func(func);
        vrott(3);
        gfunc_call(2);
        vpushi(0);
        vtop->r = reg_iret;
        vtop->r2 = reg_lret;
        ఆపు;
    స్థితి '^':
    స్థితి '&':
    స్థితి '|':
    స్థితి '*':
    స్థితి '+':
    స్థితి '-':
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
        ఒకవేళ (op == '*') {
            vpushv(vtop - 1);
            vpushv(vtop - 1);
            gen_op(TOK_UMULL);
            lexpand();
            /* stack: H1 H2 L1 L2 ML MH */
            కొరకు(i=0;i<4;i++)
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
        } లేకపోతే ఒకవేళ (op == '+' || op == '-') {
            /* XXX: add non carry method too (for MIPS or alpha) */
            ఒకవేళ (op == '+')
                op1 = TOK_ADDC1;
            లేకపోతే
                op1 = TOK_SUBC1;
            gen_op(op1);
            /* stack: H1 H2 (L1 op L2) */
            vrotb(3);
            vrotb(3);
            gen_op(op1 + 1); /* TOK_xxxC2 */
        } లేకపోతే {
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
        ఆపు;
    స్థితి TOK_SAR:
    స్థితి TOK_SHR:
    స్థితి TOK_SHL:
        ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            t = vtop[-1].type.t;
            vswap();
            lexpand();
            vrotb(3);
            /* stack: L H shift */
            c = (పూర్ణాంకం)vtop->c.i;
            /* constant: simpler */
            /* NOTE: all comments are for SHL. the other cases are
               done by swapping words */
            vpop();
            ఒకవేళ (op != TOK_SHL)
                vswap();
            ఒకవేళ (c >= 32) {
                /* stack: L H */
                vpop();
                ఒకవేళ (c > 32) {
                    vpushi(c - 32);
                    gen_op(op);
                }
                ఒకవేళ (op != TOK_SAR) {
                    vpushi(0);
                } లేకపోతే {
                    gv_dup();
                    vpushi(31);
                    gen_op(TOK_SAR);
                }
                vswap();
            } లేకపోతే {
                vswap();
                gv_dup();
                /* stack: H L L */
                vpushi(c);
                gen_op(op);
                vswap();
                vpushi(32 - c);
                ఒకవేళ (op == TOK_SHL)
                    gen_op(TOK_SHR);
                లేకపోతే
                    gen_op(TOK_SHL);
                vrotb(3);
                /* stack: L L H */
                vpushi(c);
                ఒకవేళ (op == TOK_SHL)
                    gen_op(TOK_SHL);
                లేకపోతే
                    gen_op(TOK_SHR);
                gen_op('|');
            }
            ఒకవేళ (op != TOK_SHL)
                vswap();
            lbuild(t);
        } లేకపోతే {
            /* XXX: should provide a faster fallback on x86 ? */
            ఎంపిక(op) {
            స్థితి TOK_SAR:
                func = TOK___ashrdi3;
                వెళ్ళు gen_func;
            స్థితి TOK_SHR:
                func = TOK___lshrdi3;
                వెళ్ళు gen_func;
            స్థితి TOK_SHL:
                func = TOK___ashldi3;
                వెళ్ళు gen_func;
            }
        }
        ఆపు;
    అప్రమేయ:
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
        ఒకవేళ (!cur_switch || cur_switch->bsym) {
            /* avoid differnt registers being saved in branches.
               This is not needed when comparing switch cases */
            save_regs(4);
        }
        /* compare high */
        op1 = op;
        /* when values are equal, we need to compare low words. since
           the jump is inverted, we invert the test too. */
        ఒకవేళ (op1 == TOK_LT)
            op1 = TOK_LE;
        లేకపోతే ఒకవేళ (op1 == TOK_GT)
            op1 = TOK_GE;
        లేకపోతే ఒకవేళ (op1 == TOK_ULT)
            op1 = TOK_ULE;
        లేకపోతే ఒకవేళ (op1 == TOK_UGT)
            op1 = TOK_UGE;
        a = 0;
        b = 0;
        gen_op(op1);
        ఒకవేళ (op == TOK_NE) {
            b = gvtst(0, 0);
        } లేకపోతే {
            a = gvtst(1, 0);
            ఒకవేళ (op != TOK_EQ) {
                /* generate non equal test */
                vpushi(0);
                vset_VT_CMP(TOK_NE);
                b = gvtst(0, 0);
            }
        }
        /* compare low. Always unsigned */
        op1 = op;
        ఒకవేళ (op1 == TOK_LT)
            op1 = TOK_ULT;
        లేకపోతే ఒకవేళ (op1 == TOK_LE)
            op1 = TOK_ULE;
        లేకపోతే ఒకవేళ (op1 == TOK_GT)
            op1 = TOK_UGT;
        లేకపోతే ఒకవేళ (op1 == TOK_GE)
            op1 = TOK_UGE;
        gen_op(op1);
#ఒకవేళ 0//def TCC_TARGET_I386
        ఒకవేళ (op == TOK_NE) { gsym(b); ఆపు; }
        ఒకవేళ (op == TOK_EQ) { gsym(a); ఆపు; }
#అయితే_ముగింపు
        gvtst_సమితి(1, a);
        gvtst_సమితి(0, b);
        ఆపు;
    }
}
#అయితే_ముగింపు

/* normalize values */
స్థిర uint64_t value64(uint64_t l1, పూర్ణాంకం t)
{
    ఒకవేళ ((t & VT_BTYPE) == VT_LLONG
        || (PTR_కొలత == 8 && (t & VT_BTYPE) == VT_PTR))
        తిరిగి l1;
    లేకపోతే ఒకవేళ (t & VT_UNSIGNED)
        తిరిగి (uint32_t)l1;
    లేకపోతే
        తిరిగి (uint32_t)l1 | -(l1 & 0x80000000);
}

స్థిర uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    తిరిగి (a ^ b) >> 63 ? -x : x;
}

స్థిర పూర్ణాంకం gen_opic_lt(uint64_t a, uint64_t b)
{
    తిరిగి (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
స్థిర శూన్య gen_opic(పూర్ణాంకం op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    పూర్ణాంకం t1 = v1->type.t & VT_BTYPE;
    పూర్ణాంకం t2 = v2->type.t & VT_BTYPE;
    పూర్ణాంకం c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    పూర్ణాంకం c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? value64(v1->c.i, v1->type.t) : 0;
    uint64_t l2 = c2 ? value64(v2->c.i, v2->type.t) : 0;
    పూర్ణాంకం shm = (t1 == VT_LLONG) ? 63 : 31;
    పూర్ణాంకం r;

    ఒకవేళ (c1 && c2) {
        ఎంపిక(op) {
        స్థితి '+': l1 += l2; ఆపు;
        స్థితి '-': l1 -= l2; ఆపు;
        స్థితి '&': l1 &= l2; ఆపు;
        స్థితి '^': l1 ^= l2; ఆపు;
        స్థితి '|': l1 |= l2; ఆపు;
        స్థితి '*': l1 *= l2; ఆపు;

        స్థితి TOK_PDIV:
        స్థితి '/':
        స్థితి '%':
        స్థితి TOK_UDIV:
        స్థితి TOK_UMOD:
            /* if division by zero, generate explicit division */
            ఒకవేళ (l2 == 0) {
                ఒకవేళ (CONST_WANTED && !NOEVAL_WANTED)
                    tcc_error("division by zero in constant");
                వెళ్ళు general_case;
            }
            ఎంపిక(op) {
            అప్రమేయ: l1 = gen_opic_sdiv(l1, l2); ఆపు;
            స్థితి '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); ఆపు;
            స్థితి TOK_UDIV: l1 = l1 / l2; ఆపు;
            స్థితి TOK_UMOD: l1 = l1 % l2; ఆపు;
            }
            ఆపు;
        స్థితి TOK_SHL: l1 <<= (l2 & shm); ఆపు;
        స్థితి TOK_SHR: l1 >>= (l2 & shm); ఆపు;
        స్థితి TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            ఆపు;
            /* tests */
        స్థితి TOK_ULT: l1 = l1 < l2; ఆపు;
        స్థితి TOK_UGE: l1 = l1 >= l2; ఆపు;
        స్థితి TOK_EQ: l1 = l1 == l2; ఆపు;
        స్థితి TOK_NE: l1 = l1 != l2; ఆపు;
        స్థితి TOK_ULE: l1 = l1 <= l2; ఆపు;
        స్థితి TOK_UGT: l1 = l1 > l2; ఆపు;
        స్థితి TOK_LT: l1 = gen_opic_lt(l1, l2); ఆపు;
        స్థితి TOK_GE: l1 = !gen_opic_lt(l1, l2); ఆపు;
        స్థితి TOK_LE: l1 = !gen_opic_lt(l2, l1); ఆపు;
        స్థితి TOK_GT: l1 = gen_opic_lt(l2, l1); ఆపు;
            /* logical */
        స్థితి TOK_LAND: l1 = l1 && l2; ఆపు;
        స్థితి TOK_LOR: l1 = l1 || l2; ఆపు;
        అప్రమేయ:
            వెళ్ళు general_case;
        }
        v1->c.i = value64(l1, v1->type.t);
        v1->r |= v2->r & VT_NONCONST;
        vtop--;
    } లేకపోతే {
        /* if commutative ops, put c2 as constant */
        ఒకవేళ (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*' || op == TOK_EQ || op == TOK_NE)) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        ఒకవేళ (c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vpop();
        } లేకపోతే ఒకవేళ (c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            ఒకవేళ (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } లేకపోతే ఒకవేళ (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } లేకపోతే ఒకవేళ (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV || op == TOK_UMOD)) {
            /* try to use shifts instead of muls or divs */
            ఒకవేళ (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                పూర్ణాంకం n = -1;
                ఒకవేళ (op == TOK_UMOD) {
                    vtop->c.i = l2 - 1;
                    op = '&';
                    వెళ్ళు general_case;
                }
                అయితే (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                ఒకవేళ (op == '*')
                    op = TOK_SHL;
                లేకపోతే ఒకవేళ (op == TOK_PDIV)
                    op = TOK_SAR;
                లేకపోతే
                    op = TOK_SHR;
            }
            వెళ్ళు general_case;
        } లేకపోతే ఒకవేళ (c2 && (op == '+' || op == '-') &&
                   (r = vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM),
                    r == (VT_CONST | VT_SYM) || r == VT_LOCAL)) {
            /* symbol + constant case */
            ఒకవేళ (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    ఒకవేళ ((పూర్ణాంకం)l2 != l2)
	        వెళ్ళు general_case;
            vtop--;
            vtop->c.i = l2;
        } లేకపోతే {
        general_case:
                /* call low level op generator */
                ఒకవేళ (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_కొలత == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                లేకపోతే
                    gen_opi(op);
        }
        ఒకవేళ (vtop->r == VT_CONST)
            vtop->r |= VT_NONCONST; /* is const, but only by optimization */
    }
}

#ఒకవేళ defined TCC_లక్ష్యం_X86_64 || defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_ARM64
# define gen_negf gen_opf
#లేదావేళ defined TCC_లక్ష్యం_ARM
శూన్య gen_negf(పూర్ణాంకం op)
{
    /* arm will detect 0-x and replace by vneg */
    vpushi(0), vswap(), gen_op('-');
}
#లేకపోతే
/* XXX: implement in gen_opf() for other backends too */
శూన్య gen_negf(పూర్ణాంకం op)
{
    /* In IEEE negate(x) isn't subtract(0,x).  Without NaNs it's
       subtract(-0, x), but with them it's really a sign flip
       operation.  We implement this with bit manipulation and have
       to do some type reinterpretation for this, which TCC can do
       only via memory.  */
    పూర్ణాంకం align, కొలత, bt;
    కొలత = type_కొలత(&vtop->type, &align);
    bt = vtop->type.t & VT_BTYPE;
#ఒకవేళ defined TCC_లక్ష్యం_X86_64 || defined TCC_లక్ష్యం_I386
    /* sizeof long double is 12 or 16 here, but it's really the 80bit
       extended float format.  */
    ఒకవేళ (bt == VT_LDOUBLE)
        కొలత = 10;
#అయితే_ముగింపు
    ఒకవేళ (nocode_wanted) /* save_reg() wont work */
        వెళ్ళు gv2;
    save_reg(gv(RC_TYPE(bt)));
    vdup();
    incr_bf_adr(కొలత - 1);
    vdup();
    vpushi(0x80); /* flip sign */
    gen_op('^');
    vstore();
    vpop();
gv2:
    gv(RC_TYPE(bt)); /* -n is not a lvalue */
}
#అయితే_ముగింపు

/* generate a floating point operation with constant propagation */
స్థిర శూన్య gen_opif(పూర్ణాంకం op)
{
    పూర్ణాంకం c1, c2, i, bt;
    SValue *v1, *v2;
#ఒకవేళ defined _MSC_VER && defined __x86_64__
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    అస్థిర
#అయితే_ముగింపు
    దీర్ఘ ద్విగుణ f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    ఒకవేళ (op == TOK_NEG)
        v1 = v2;
    bt = v1->type.t & VT_BTYPE;

    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    ఒకవేళ (c1 && c2) {
        ఒకవేళ (bt == VT_FLOAT) {
            f1 = v1->c.f;
            f2 = v2->c.f;
        } లేకపోతే ఒకవేళ (bt == VT_DOUBLE) {
            f1 = v1->c.d;
            f2 = v2->c.d;
        } లేకపోతే {
            f1 = v1->c.ld;
            f2 = v2->c.ld;
        }
        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        ఒకవేళ (!(ieee_finite(f1) || !ieee_finite(f2)) && !CONST_WANTED)
            వెళ్ళు general_case;
        ఎంపిక(op) {
        స్థితి '+': f1 += f2; ఆపు;
        స్థితి '-': f1 -= f2; ఆపు;
        స్థితి '*': f1 *= f2; ఆపు;
        స్థితి '/': 
            ఒకవేళ (f2 == 0.0) {
                సంఘం { దశాంశం f; గుర్తులేని u; } x1, x2, y;
		/* If not in initializer we need to potentially generate
		   FP exceptions at runtime, otherwise we want to fold.  */
                ఒకవేళ (!CONST_WANTED)
                    వెళ్ళు general_case;
                /* the run-time result of 0.0/0.0 on x87, also of other compilers
                   when used to compile the f1 /= f2 below, would be -nan */
                x1.f = f1, x2.f = f2;
                ఒకవేళ (f1 == 0.0)
                    y.u = 0x7fc00000; /* nan */
                లేకపోతే
                    y.u = 0x7f800000; /* infinity */
                y.u |= (x1.u ^ x2.u) & 0x80000000; /* set sign */
                f1 = y.f;
                ఆపు;
            }
            f1 /= f2;
            ఆపు;
        స్థితి TOK_NEG:
            f1 = -f1;
            వెళ్ళు unary_ఫలితం;
        స్థితి TOK_EQ:
            i = f1 == f2;
	make_int:
            vtop -= 2;
            vpushi(i);
            తిరిగి;
        స్థితి TOK_NE:
            i = f1 != f2;
	    వెళ్ళు make_int;
        స్థితి TOK_LT:
            i = f1 < f2;
	    వెళ్ళు make_int;
        స్థితి TOK_GE:
            i = f1 >= f2;
	    వెళ్ళు make_int;
        స్థితి TOK_LE:
            i = f1 <= f2;
	    వెళ్ళు make_int;
        స్థితి TOK_GT:
            i = f1 > f2;
	    వెళ్ళు make_int;
        అప్రమేయ:
            వెళ్ళు general_case;
        }
        vtop--;
    unary_ఫలితం:
        /* XXX: overflow test ? */
        ఒకవేళ (bt == VT_FLOAT) {
            v1->c.f = f1;
        } లేకపోతే ఒకవేళ (bt == VT_DOUBLE) {
            v1->c.d = f1;
        } లేకపోతే {
            v1->c.ld = f1;
        }
    } లేకపోతే {
    general_case:
        ఒకవేళ (op == TOK_NEG) {
            gen_negf(op);
        } లేకపోతే {
            gen_opf(op);
        }
    }
}

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
స్థిర శూన్య type_గమ్యం_str(అక్షరం *buf, పూర్ణాంకం buf_కొలత,
                 CType *type, స్థిరరాశి అక్షరం *varstr)
{
    పూర్ణాంకం bt, v, t;
    Sym *s, *sa;
    అక్షరం buf1[256];
    స్థిరరాశి అక్షరం *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    ఒకవేళ (t & VT_EXTERN)
        pstrcat(buf, buf_కొలత, "extern ");
    ఒకవేళ (t & VT_STATIC)
        pstrcat(buf, buf_కొలత, "static ");
    ఒకవేళ (t & VT_TYPEDEF)
        pstrcat(buf, buf_కొలత, "typedef ");
    ఒకవేళ (t & VT_INLINE)
        pstrcat(buf, buf_కొలత, "inline ");
    ఒకవేళ (bt != VT_PTR) {
        ఒకవేళ (t & VT_RESTRICT)
            pstrcat(buf, buf_కొలత, "restrict ");
        ఒకవేళ (t & VT_VOLATILE)
            pstrcat(buf, buf_కొలత, "volatile ");
        ఒకవేళ (t & VT_CONSTANT)
            pstrcat(buf, buf_కొలత, "const ");
    }
    ఒకవేళ (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_కొలత, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_కొలత -= అక్షరశ్రేణి_పొడవు(buf);
    buf += అక్షరశ్రేణి_పొడవు(buf);

    ఎంపిక(bt) {
    స్థితి VT_VOID:
        tstr = "void";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_BOOL:
        tstr = "_Bool";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_BYTE:
        tstr = "char";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_SHORT:
        tstr = "short";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_INT:
        tstr = "int";
        వెళ్ళు maybe_long;
    స్థితి VT_LLONG:
        tstr = "long long";
    maybe_long:
        ఒకవేళ (t & VT_LONG)
            tstr = "long";
        ఒకవేళ (!IS_ENUM(t))
            వెళ్ళు కూడు_tstr;
        tstr = "enum ";
        వెళ్ళు tstruct;
    స్థితి VT_FLOAT:
        tstr = "float";
        వెళ్ళు కూడు_tstr;
    స్థితి VT_DOUBLE:
        tstr = "double";
        ఒకవేళ (!(t & VT_LONG))
            వెళ్ళు కూడు_tstr;
    స్థితి VT_LDOUBLE:
        tstr = "long double";
    కూడు_tstr:
        pstrcat(buf, buf_కొలత, tstr);
        ఆపు;
    స్థితి VT_STRUCT:
        tstr = "struct ";
        ఒకవేళ (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_కొలత, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        ఒకవేళ (v >= SYM_మొదటి_ANOM)
            pstrcat(buf, buf_కొలత, "<anonymous>");
        లేకపోతే
            pstrcat(buf, buf_కొలత, get_tok_str(v, ఖాళీ));
        ఆపు;
    స్థితి VT_FUNC:
        s = type->ref;
        buf1[0]=0;
        ఒకవేళ (varstr && '*' == *varstr) {
            pstrcat(buf1, పరిమాణం(buf1), "(");
            pstrcat(buf1, పరిమాణం(buf1), varstr);
            pstrcat(buf1, పరిమాణం(buf1), ")");
        }
        pstrcat(buf1, పరిమాణం(buf1), "(");
        sa = s->తదుపరి;
        అయితే (sa != ఖాళీ) {
            అక్షరం buf2[256];
            type_గమ్యం_str(buf2, పరిమాణం(buf2), &sa->type, ఖాళీ);
            pstrcat(buf1, పరిమాణం(buf1), buf2);
            sa = sa->తదుపరి;
            ఒకవేళ (sa)
                pstrcat(buf1, పరిమాణం(buf1), ", ");
        }
        ఒకవేళ (s->f.func_type == FUNC_ELLIPSIS)
            pstrcat(buf1, పరిమాణం(buf1), ", ...");
        pstrcat(buf1, పరిమాణం(buf1), ")");
        type_గమ్యం_str(buf, buf_కొలత, &s->type, buf1);
        వెళ్ళు no_var;
    స్థితి VT_PTR:
        s = type->ref;
        ఒకవేళ (t & (VT_ARRAY|VT_VLA)) {
            ఒకవేళ (varstr && '*' == *varstr)
                snprintf(buf1, పరిమాణం(buf1), "(%s)[%d]", varstr, s->c);
            లేకపోతే
                snprintf(buf1, పరిమాణం(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_గమ్యం_str(buf, buf_కొలత, &s->type, buf1);
            వెళ్ళు no_var;
        }
        pstrcpy(buf1, పరిమాణం(buf1), "*");
        ఒకవేళ (t & VT_RESTRICT)
            pstrcat(buf1, పరిమాణం(buf1), "restrict ");
        ఒకవేళ (t & VT_CONSTANT)
            pstrcat(buf1, పరిమాణం(buf1), "const ");
        ఒకవేళ (t & VT_VOLATILE)
            pstrcat(buf1, పరిమాణం(buf1), "volatile ");
        ఒకవేళ (varstr)
            pstrcat(buf1, పరిమాణం(buf1), varstr);
        type_గమ్యం_str(buf, buf_కొలత, &s->type, buf1);
        వెళ్ళు no_var;
    }
    ఒకవేళ (varstr) {
        pstrcat(buf, buf_కొలత, " ");
        pstrcat(buf, buf_కొలత, varstr);
    }
 no_var: ;
}

స్థిర శూన్య type_incompatibility_error(CType* st, CType* dt, స్థిరరాశి అక్షరం* fmt)
{
    అక్షరం buf1[256], buf2[256];
    type_గమ్యం_str(buf1, పరిమాణం(buf1), st, ఖాళీ);
    type_గమ్యం_str(buf2, పరిమాణం(buf2), dt, ఖాళీ);
    tcc_error(fmt, buf1, buf2);
}

స్థిర శూన్య type_incompatibility_warning(CType* st, CType* dt, స్థిరరాశి అక్షరం* fmt)
{
    అక్షరం buf1[256], buf2[256];
    type_గమ్యం_str(buf1, పరిమాణం(buf1), st, ఖాళీ);
    type_గమ్యం_str(buf2, పరిమాణం(buf2), dt, ఖాళీ);
    tcc_warning(fmt, buf1, buf2);
}

స్థిర పూర్ణాంకం pointed_కొలత(CType *type)
{
    పూర్ణాంకం align;
    తిరిగి type_కొలత(pointed_type(type), &align);
}

స్థిర అంతఃవరుస పూర్ణాంకం is_null_సూచిక(SValue *p)
{
    ఒకవేళ ((p->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        తిరిగి 0;
    తిరిగి ((p->type.t & VT_BTYPE) == VT_INT && (uint32_t)p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_LLONG && p->c.i == 0) ||
        ((p->type.t & VT_BTYPE) == VT_PTR &&
         (PTR_కొలత == 4 ? (uint32_t)p->c.i == 0 : p->c.i == 0) &&
         ((pointed_type(&p->type)->t & VT_BTYPE) == VT_VOID) &&
         0 == (pointed_type(&p->type)->t & VT_QUAL)
         );
}

/* compare function types. OLD functions match any new functions */
స్థిర పూర్ణాంకం is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;

    s1 = type1->ref;
    s2 = type2->ref;
    ఒకవేళ (s1->f.func_call != s2->f.func_call)
        తిరిగి 0;
    ఒకవేళ (s1->f.func_type != s2->f.func_type
        && s1->f.func_type != FUNC_OLD
        && s2->f.func_type != FUNC_OLD)
        తిరిగి 0;
    కొరకు (;;) {
        ఒకవేళ (!is_compatible_unqualified_types(&s1->type, &s2->type))
            తిరిగి 0;
        ఒకవేళ (s1->f.func_type == FUNC_OLD || s2->f.func_type == FUNC_OLD )
            తిరిగి 1;
        s1 = s1->తదుపరి;
        s2 = s2->తదుపరి;
        ఒకవేళ (!s1)
            తిరిగి !s2;
        ఒకవేళ (!s2)
            తిరిగి 0;
    }
}

/* return true if type1 and type2 are the same.  If unqualified is
   true, qualifiers on the types are ignored.
 */
స్థిర పూర్ణాంకం compare_types(CType *type1, CType *type2, పూర్ణాంకం unqualified)
{
    పూర్ణాంకం bt1, t1, t2;

    ఒకవేళ (IS_ENUM(type1->t)) {
        ఒకవేళ (IS_ENUM(type2->t))
            తిరిగి type1->ref == type2->ref;
        type1 = &type1->ref->type;
    } లేకపోతే ఒకవేళ (IS_ENUM(type2->t))
        type2 = &type2->ref->type;

    t1 = type1->t & VT_TYPE;
    t2 = type2->t & VT_TYPE;
    ఒకవేళ (unqualified) {
        /* strip qualifiers before comparing */
        t1 &= ~VT_QUAL;
        t2 &= ~VT_QUAL;
    }

    /* Default Vs explicit signedness only matters for char */
    ఒకవేళ ((t1 & VT_BTYPE) != VT_BYTE) {
        t1 &= ~VT_DEFSIGN;
        t2 &= ~VT_DEFSIGN;
    }
    /* XXX: bitfields ? */
    ఒకవేళ (t1 != t2)
        తిరిగి 0;

    ఒకవేళ ((t1 & VT_ARRAY)
        && !(type1->ref->c < 0
          || type2->ref->c < 0
          || type1->ref->c == type2->ref->c))
            తిరిగి 0;

    /* test more complicated cases */
    bt1 = t1 & VT_BTYPE;
    ఒకవేళ (bt1 == VT_PTR) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        ఒకవేళ (unqualified && (t1 & VT_ARRAY))
            తిరిగి compare_types(type1, type2, 1);
        తిరిగి is_compatible_types(type1, type2);
    } లేకపోతే ఒకవేళ (bt1 == VT_STRUCT) {
        తిరిగి (type1->ref == type2->ref);
    } లేకపోతే ఒకవేళ (bt1 == VT_FUNC) {
        తిరిగి is_compatible_func(type1, type2);
    } లేకపోతే {
        తిరిగి 1;
    }
}

#నిర్వచించు CMP_OP 'C'
#నిర్వచించు జరుపు_OP 'S'

/* Check if OP1 and OP2 can be "combined" with operation OP, the combined
   type is stored in DEST if non-null (except for pointer plus/minus) . */
స్థిర పూర్ణాంకం combine_types(CType *dest, SValue *op1, SValue *op2, పూర్ణాంకం op)
{
    CType *type1, *type2, type;
    పూర్ణాంకం t1, t2, bt1, bt2;
    పూర్ణాంకం ret = 1;

    /* for shifts, 'combine' only left operand */
    ఒకవేళ (op == జరుపు_OP)
        op2 = op1;

    type1 = &op1->type, type2 = &op2->type;
    t1 = type1->t, t2 = type2->t;
    bt1 = t1 & VT_BTYPE, bt2 = t2 & VT_BTYPE;

    type.t = VT_VOID;
    type.ref = ఖాళీ;

    ఒకవేళ (bt1 == VT_VOID || bt2 == VT_VOID) {
        ఒకవేళ (op != '?')
            tcc_error("operation on void value");
        /* NOTE: as an extension, we accept void on only one side */
        type.t = VT_VOID;
    } లేకపోతే ఒకవేళ (bt1 == VT_PTR || bt2 == VT_PTR) {
        ఒకవేళ (op == '+') {
          ఒకవేళ (!is_integer_btype(bt1 == VT_PTR ? bt2 : bt1))
            ret = 0;
        }
        /* http://port70.net/~nsz/c/c99/n1256.html#6.5.15p6 */
        /* If one is a null ptr constant the result type is the other.  */
        లేకపోతే ఒకవేళ (is_null_సూచిక (op2)) type = *type1;
        లేకపోతే ఒకవేళ (is_null_సూచిక (op1)) type = *type2;
        లేకపోతే ఒకవేళ (bt1 != bt2) {
            /* accept comparison or cond-expr between pointer and integer
               with a warning */
            ఒకవేళ ((op == '?' || op == CMP_OP)
                && (is_integer_btype(bt1) || is_integer_btype(bt2)))
              tcc_warning("pointer/integer mismatch in %s",
                          op == '?' ? "conditional expression" : "comparison");
            లేకపోతే ఒకవేళ (op != '-' || !is_integer_btype(bt2))
              ret = 0;
            type = *(bt1 == VT_PTR ? type1 : type2);
        } లేకపోతే {
            CType *pt1 = pointed_type(type1);
            CType *pt2 = pointed_type(type2);
            పూర్ణాంకం pbt1 = pt1->t & VT_BTYPE;
            పూర్ణాంకం pbt2 = pt2->t & VT_BTYPE;
            పూర్ణాంకం newquals, copied = 0;
            ఒకవేళ (pbt1 != VT_VOID && pbt2 != VT_VOID
                && !compare_types(pt1, pt2, 1/*unqualif*/)) {
                ఒకవేళ (op != '?' && op != CMP_OP)
                  ret = 0;
                లేకపోతే
                  type_incompatibility_warning(type1, type2,
                    op == '?'
                     ? "pointer type mismatch in conditional expression ('%s' and '%s')"
                     : "pointer type mismatch in comparison('%s' and '%s')");
            }
            ఒకవేళ (op == '?') {
                /* pointers to void get preferred, otherwise the
                   pointed to types minus qualifs should be compatible */
                type = *((pbt1 == VT_VOID) ? type1 : type2);
                /* combine qualifs */
                newquals = type_qualifiers(pt1) | type_qualifiers(pt2);
                ఒకవేళ ((~type_qualifiers(pointed_type(&type))) & newquals)
                  {
                    /* copy the pointer target symbol */
                    type.ref = sym_నెట్టు(SYM_క్షేత్రం, &type.ref->type,
                                        0, type.ref->c);
                    copied = 1;
                    parse_btype_qualify(pointed_type(&type), newquals);
                  }
                /* pointers to incomplete arrays get converted to
                   pointers to completed ones if possible */
                ఒకవేళ (pt1->t & VT_ARRAY
                    && pt2->t & VT_ARRAY
                    && pointed_type(&type)->ref->c < 0
                    && (pt1->ref->c > 0 || pt2->ref->c > 0))
                  {
                    ఒకవేళ (!copied)
                      type.ref = sym_నెట్టు(SYM_క్షేత్రం, &type.ref->type,
                                          0, type.ref->c);
                    pointed_type(&type)->ref =
                        sym_నెట్టు(SYM_క్షేత్రం, &pointed_type(&type)->ref->type,
                                 0, pointed_type(&type)->ref->c);
                    pointed_type(&type)->ref->c =
                        0 < pt1->ref->c ? pt1->ref->c : pt2->ref->c;
                  }
            }
        }
        ఒకవేళ (op == CMP_OP)
          type.t = VT_కొలత_T;
    } లేకపోతే ఒకవేళ (bt1 == VT_STRUCT || bt2 == VT_STRUCT) {
        ఒకవేళ (op != '?' || !compare_types(type1, type2, 1))
          ret = 0;
        type = *type1;
    } లేకపోతే ఒకవేళ (is_float(bt1) || is_float(bt2)) {
        ఒకవేళ (bt1 == VT_LDOUBLE || bt2 == VT_LDOUBLE) {
            type.t = VT_LDOUBLE;
        } లేకపోతే ఒకవేళ (bt1 == VT_DOUBLE || bt2 == VT_DOUBLE) {
            type.t = VT_DOUBLE;
        } లేకపోతే {
            type.t = VT_FLOAT;
        }
    } లేకపోతే ఒకవేళ (bt1 == VT_LLONG || bt2 == VT_LLONG) {
        /* cast to biggest op */
        type.t = VT_LLONG | VT_LONG;
        ఒకవేళ (bt1 == VT_LLONG)
          type.t &= t1;
        ఒకవేళ (bt2 == VT_LLONG)
          type.t &= t2;
        /* convert to unsigned if it does not fit in a long long */
        ఒకవేళ ((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED) ||
            (t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_LLONG | VT_UNSIGNED))
          type.t |= VT_UNSIGNED;
    } లేకపోతే {
        /* integer operations */
        type.t = VT_INT | (VT_LONG & (t1 | t2));
        /* convert to unsigned if it does not fit in an integer */
        ఒకవేళ (((t1 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t1 & VT_BITFIELD) || బిట్టు_కొలత(t1) == 32))
         || ((t2 & (VT_BTYPE | VT_UNSIGNED)) == (VT_INT | VT_UNSIGNED)
                && (!(t2 & VT_BITFIELD) || బిట్టు_కొలత(t2) == 32)))
          type.t |= VT_UNSIGNED;
    }
    ఒకవేళ (dest)
      *dest = type;
    తిరిగి ret;
}

/* generic gen_op: handles types problems */
ST_FUNC శూన్య gen_op(పూర్ణాంకం op)
{
    పూర్ణాంకం t1, t2, bt1, bt2, t;
    CType type1, combtype;
    పూర్ణాంకం op_class = op;

    ఒకవేళ (op == TOK_SHR || op == TOK_SAR || op == TOK_SHL)
        op_class = జరుపు_OP;
    లేకపోతే ఒకవేళ (TOK_ISCOND(op)) /* == != > ... */
        op_class = CMP_OP;

redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & VT_BTYPE;
    bt2 = t2 & VT_BTYPE;
        
    ఒకవేళ (bt1 == VT_FUNC || bt2 == VT_FUNC) {
	ఒకవేళ (bt2 == VT_FUNC) {
	    mk_సూచిక(&vtop->type);
	    gaddrof();
	}
	ఒకవేళ (bt1 == VT_FUNC) {
	    vswap();
	    mk_సూచిక(&vtop->type);
	    gaddrof();
	    vswap();
	}
	వెళ్ళు redo;
    } లేకపోతే ఒకవేళ (!combine_types(&combtype, vtop - 1, vtop, op_class)) {
op_err:
        tcc_error("invalid operand types for binary operation");
    } లేకపోతే ఒకవేళ (bt1 == VT_PTR || bt2 == VT_PTR) {
        /* at least one operand is a pointer */
        /* relational op: must be both pointers */
        పూర్ణాంకం align;
        ఒకవేళ (op_class == CMP_OP)
            వెళ్ళు std_op;
        /* if both pointers, then it must be the '-' op */
        ఒకవేళ (bt1 == VT_PTR && bt2 == VT_PTR) {
            ఒకవేళ (op != '-')
                వెళ్ళు op_err;
            vpush_type_కొలత(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            vrott(3);
            gen_opic(op);
            vtop->type.t = VT_PTRDIFF_T;
            vswap();
            gen_op(TOK_PDIV);
        } లేకపోతే {
            /* exactly one pointer : must be '+' or '-'. */
            ఒకవేళ (op != '-' && op != '+')
                వెళ్ళు op_err;
            /* Put pointer as first operand */
            ఒకవేళ (bt2 == VT_PTR) {
                vswap();
                t = t1, t1 = t2, t2 = t;
                bt2 = bt1;
            }
#ఒకవేళ PTR_కొలత == 4
            ఒకవేళ (bt2 == VT_LLONG)
                /* XXX: truncate here because gen_opl can't handle ptr + long long */
                gen_cast_s(VT_INT);
#అయితే_ముగింపు
            type1 = vtop[-1].type;
            vpush_type_కొలత(pointed_type(&vtop[-1].type), &align);
            vtop->type.t &= ~VT_UNSIGNED;
            gen_op('*');
#నిర్వచితమైతే CONFIG_TCC_BCHECK
            ఒకవేళ (tcc_state->do_bounds_check && !CONST_WANTED) {
                /* if bounded pointers, we generate a special code to
                   test bounds */
                ఒకవేళ (op == '-') {
                    vpushi(0);
                    vswap();
                    gen_op('-');
                }
                gen_bounded_ptr_కూడు();
            } లేకపోతే
#అయితే_ముగింపు
            {
                gen_opic(op);
            }
            type1.t &= ~(VT_ARRAY|VT_VLA);
            /* put again type if gen_opic() swaped operands */
            vtop->type = type1;
        }
    } లేకపోతే {
        /* floats can only be used for a few operations */
        ఒకవేళ (is_float(combtype.t)
            && op != '+' && op != '-' && op != '*' && op != '/'
            && op_class != CMP_OP) {
            వెళ్ళు op_err;
        }
    std_op:
        t = t2 = combtype.t;
        /* special case for shifts and long long: we keep the shift as
           an integer */
        ఒకవేళ (op_class == జరుపు_OP)
            t2 = VT_INT;
        /* XXX: currently, some unsigned operations are explicit, so
           we modify them here */
        ఒకవేళ (t & VT_UNSIGNED) {
            ఒకవేళ (op == TOK_SAR)
                op = TOK_SHR;
            లేకపోతే ఒకవేళ (op == '/')
                op = TOK_UDIV;
            లేకపోతే ఒకవేళ (op == '%')
                op = TOK_UMOD;
            లేకపోతే ఒకవేళ (op == TOK_LT)
                op = TOK_ULT;
            లేకపోతే ఒకవేళ (op == TOK_GT)
                op = TOK_UGT;
            లేకపోతే ఒకవేళ (op == TOK_LE)
                op = TOK_ULE;
            లేకపోతే ఒకవేళ (op == TOK_GE)
                op = TOK_UGE;
        }
        vswap();
        gen_cast_s(t);
        vswap();
        gen_cast_s(t2);
        ఒకవేళ (is_float(t))
            gen_opif(op);
        లేకపోతే
            gen_opic(op);
        ఒకవేళ (op_class == CMP_OP) {
            /* relational op: the result is an int */
            vtop->type.t = VT_INT;
        } లేకపోతే {
            vtop->type.t = t;
        }
    }
    // Make sure that we have converted to an rvalue:
    ఒకవేళ (vtop->r & VT_LVAL)
        gv(RC_TYPE(vtop->type.t));
}

#ఒకవేళ defined TCC_లక్ష్యం_ARM64 || defined TCC_లక్ష్యం_RISCV64 || defined TCC_లక్ష్యం_ARM
#నిర్వచించు gen_cvt_itof1 gen_cvt_itof
#లేకపోతే
/* generic itof for unsigned long long case */
స్థిర శూన్య gen_cvt_itof1(పూర్ణాంకం t)
{
    ఒకవేళ ((vtop->type.t & (VT_BTYPE | VT_UNSIGNED)) == 
        (VT_LLONG | VT_UNSIGNED)) {

        ఒకవేళ (t == VT_FLOAT)
            vpush_helper_func(TOK___floatundisf);
#ఒకవేళ LDOUBLE_కొలత != 8
        లేకపోతే ఒకవేళ (t == VT_LDOUBLE)
            vpush_helper_func(TOK___floatundixf);
#అయితే_ముగింపు
        లేకపోతే
            vpush_helper_func(TOK___floatundidf);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } లేకపోతే {
        gen_cvt_itof(t);
    }
}
#అయితే_ముగింపు

#ఒకవేళ defined TCC_లక్ష్యం_ARM64 || defined TCC_లక్ష్యం_RISCV64
#నిర్వచించు gen_cvt_ftoi1 gen_cvt_ftoi
#లేకపోతే
/* generic ftoi for unsigned long long case */
స్థిర శూన్య gen_cvt_ftoi1(పూర్ణాంకం t)
{
    పూర్ణాంకం st;
    ఒకవేళ (t == (VT_LLONG | VT_UNSIGNED)) {
        /* not handled natively */
        st = vtop->type.t & VT_BTYPE;
        ఒకవేళ (st == VT_FLOAT)
            vpush_helper_func(TOK___fixunssfdi);
#ఒకవేళ LDOUBLE_కొలత != 8
        లేకపోతే ఒకవేళ (st == VT_LDOUBLE)
            vpush_helper_func(TOK___fixunsxfdi);
#అయితే_ముగింపు
        లేకపోతే
            vpush_helper_func(TOK___fixunsdfdi);
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        PUT_R_RET(vtop, t);
    } లేకపోతే {
        gen_cvt_ftoi(t);
    }
}
#అయితే_ముగింపు

/* special delayed cast for char/short */
స్థిర శూన్య force_charshort_cast(శూన్య)
{
    పూర్ణాంకం sbt = BFGET(vtop->r, VT_MUSTCAST) == 2 ? VT_LLONG : VT_INT;
    పూర్ణాంకం dbt = vtop->type.t;
    vtop->r &= ~VT_MUSTCAST;
    vtop->type.t = sbt;
    gen_cast_s(dbt == VT_BOOL ? VT_BYTE|VT_UNSIGNED : dbt);
    vtop->type.t = dbt;
}

స్థిర శూన్య gen_cast_s(పూర్ణాంకం t)
{
    CType type;
    type.t = t;
    type.ref = ఖాళీ;
    gen_cast(&type);
}

/* cast 'vtop' to 'type'. Casting to bitfields is forbidden. */
స్థిర శూన్య gen_cast(CType *type)
{
    పూర్ణాంకం sbt, dbt, sf, df, c;
    పూర్ణాంకం dbt_bt, sbt_bt, ds, ss, బిట్లు, trunc;

    /* special delayed cast for char/short */
    ఒకవేళ (vtop->r & VT_MUSTCAST)
        force_charshort_cast();

    /* bitfields first get cast to ints */
    ఒకవేళ (vtop->type.t & VT_BITFIELD)
        gv(RC_INT);

    ఒకవేళ (IS_ENUM(type->t) && type->ref->c < 0)
        tcc_error("cast to incomplete type");

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    ఒకవేళ (sbt == VT_FUNC)
        sbt = VT_PTR;

again:
    ఒకవేళ (sbt != dbt) {
        sf = is_float(sbt);
        df = is_float(dbt);
        dbt_bt = dbt & VT_BTYPE;
        sbt_bt = sbt & VT_BTYPE;
        ఒకవేళ (dbt_bt == VT_VOID) {
            /* do not confuse backends with VT_VOID in registers */
            vpop(), vpushi(0);
            వెళ్ళు పూర్తి;
        }
        ఒకవేళ (sbt_bt == VT_VOID) {
error:
            cast_error(&vtop->type, type);
        }

        c = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
        ఒకవేళ (c) {
            /* constant case: we can do it now */
            /* XXX: in ISOC, cannot do it if error in convert */
            ఒకవేళ (sbt == VT_FLOAT)
                vtop->c.ld = vtop->c.f;
            లేకపోతే ఒకవేళ (sbt == VT_DOUBLE)
                vtop->c.ld = vtop->c.d;

            ఒకవేళ (df) {
                ఒకవేళ (sbt_bt == VT_LLONG) {
                    ఒకవేళ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                        vtop->c.ld = vtop->c.i;
                    లేకపోతే
                        vtop->c.ld = -(దీర్ఘ ద్విగుణ)-vtop->c.i;
                } లేకపోతే ఒకవేళ(!sf) {
                    ఒకవేళ ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                        vtop->c.ld = (uint32_t)vtop->c.i;
                    లేకపోతే
                        vtop->c.ld = -(దీర్ఘ ద్విగుణ)-(uint32_t)vtop->c.i;
                }

                ఒకవేళ (dbt == VT_FLOAT)
                    vtop->c.f = (దశాంశం)vtop->c.ld;
                లేకపోతే ఒకవేళ (dbt == VT_DOUBLE)
                    vtop->c.d = (ద్విగుణ)vtop->c.ld;
            } లేకపోతే ఒకవేళ (sf && dbt == VT_BOOL) {
                vtop->c.i = (vtop->c.ld != 0);
            } లేకపోతే {
                ఒకవేళ(sf) {
                    ఒకవేళ (dbt & VT_UNSIGNED)
                        vtop->c.i = (uint64_t)vtop->c.ld;
                    లేకపోతే
                        vtop->c.i = (int64_t)vtop->c.ld;
                }
                లేకపోతే ఒకవేళ (sbt_bt == VT_LLONG || (PTR_కొలత == 8 && sbt == VT_PTR))
                    ;
                లేకపోతే ఒకవేళ (sbt & VT_UNSIGNED)
                    vtop->c.i = (uint32_t)vtop->c.i;
                లేకపోతే
                    vtop->c.i = ((uint32_t)vtop->c.i | -(vtop->c.i & 0x80000000));

                ఒకవేళ (dbt_bt == VT_LLONG || (PTR_కొలత == 8 && dbt == VT_PTR))
                    ;
                లేకపోతే ఒకవేళ (dbt == VT_BOOL)
                    vtop->c.i = (vtop->c.i != 0);
                లేకపోతే {
                    uint32_t m = dbt_bt == VT_BYTE ? 0xff :
                                 dbt_bt == VT_SHORT ? 0xffff :
                                  0xffffffff;
                    vtop->c.i &= m;
                    ఒకవేళ (!(dbt & VT_UNSIGNED))
                        vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
                }
            }
            వెళ్ళు పూర్తి;

        } లేకపోతే ఒకవేళ (dbt == VT_BOOL
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM))
                == (VT_CONST | VT_SYM)) {
            /* addresses are considered non-zero (see tcctest.c:sinit23) */
            vtop->r = VT_CONST;
            vtop->c.i = 1;
            వెళ్ళు పూర్తి;
        }

        /* cannot generate code for global or static initializers */
        ఒకవేళ (nocode_wanted & దత్తాంశం_ONLY_WANTED) {
            ఒకవేళ (df)
                vtop->r = get_reg(RC_FLOAT); /* don't confuse backends */
            వెళ్ళు పూర్తి;
        }

        /* non constant case: generate code */
        ఒకవేళ (dbt == VT_BOOL) {
            gen_test_zero(TOK_NE);
            వెళ్ళు పూర్తి;
        }

        ఒకవేళ (sf || df) {
            ఒకవేళ (sf && df) {
                /* convert from fp to fp */
                gen_cvt_ftof(dbt);
            } లేకపోతే ఒకవేళ (df) {
                /* convert int to fp */
                gen_cvt_itof1(dbt);
            } లేకపోతే {
                /* convert fp to int */
                sbt = dbt;
                ఒకవేళ (dbt_bt != VT_LLONG && dbt_bt != VT_INT)
                    sbt = VT_INT;
                gen_cvt_ftoi1(sbt);
                వెళ్ళు again; /* may need char/short cast */
            }
            వెళ్ళు పూర్తి;
        }

        ds = btype_కొలత(dbt_bt);
        ss = btype_కొలత(sbt_bt);
        ఒకవేళ (ds == 0 || ss == 0)
            వెళ్ళు error;

        /* same size and no sign conversion needed */
        ఒకవేళ (ds == ss && ds >= 4)
            వెళ్ళు పూర్తి;
        ఒకవేళ (dbt_bt == VT_PTR || sbt_bt == VT_PTR) {
            tcc_warning("cast between pointer and integer of different size");
            ఒకవేళ (sbt_bt == VT_PTR) {
                /* put integer type to allow logical operations below */
                vtop->type.t = (PTR_కొలత == 8 ? VT_LLONG : VT_INT);
            }
        }

        /* processor allows { int a = 0, b = *(char*)&a; }
           That means that if we cast to less width, we can just
           change the type and read it still later. */
        #నిర్వచించు ALLOW_SUBTYPE_ACCESS 1

        ఒకవేళ (ALLOW_SUBTYPE_ACCESS && (vtop->r & VT_LVAL)) {
            /* value still in memory */
            ఒకవేళ (ds <= ss)
                వెళ్ళు పూర్తి;
            /* ss <= 4 here */
            ఒకవేళ (ds <= 4 && !(dbt == (VT_SHORT | VT_UNSIGNED) && sbt == VT_BYTE)) {
                gv(RC_INT);
                వెళ్ళు పూర్తి; /* no 64bit envolved */
            }
        }
        gv(RC_INT);

        trunc = 0;
#ఒకవేళ PTR_కొలత == 4
        ఒకవేళ (ds == 8) {
            /* generate high word */
            ఒకవేళ (sbt & VT_UNSIGNED) {
                vpushi(0);
                gv(RC_INT);
            } లేకపోతే {
                gv_dup();
                vpushi(31);
                gen_op(TOK_SAR);
            }
            lbuild(dbt);
        } లేకపోతే ఒకవేళ (ss == 8) {
            /* from long long: just take low order word */
            lexpand();
            vpop();
        }
        ss = 4;

#లేదావేళ PTR_కొలత == 8
        ఒకవేళ (ds == 8) {
            /* need to convert from 32bit to 64bit */
            ఒకవేళ (sbt & VT_UNSIGNED) {
#ఒకవేళ defined(TCC_లక్ష్యం_RISCV64)
                /* RISC-V keeps 32bit vals in registers sign-extended.
                   So here we need a zero-extension.  */
                trunc = 32;
#లేకపోతే
                వెళ్ళు పూర్తి;
#అయితే_ముగింపు
            } లేకపోతే {
                gen_cvt_sxtw();
                వెళ్ళు పూర్తి;
            }
            ss = ds, ds = 4, dbt = sbt;
        } లేకపోతే ఒకవేళ (ss == 8) {
            /* RISC-V keeps 32bit vals in registers sign-extended.
               So here we need a sign-extension for signed types and
               zero-extension. for unsigned types. */
#ఒకవేళ !defined(TCC_లక్ష్యం_RISCV64)
            trunc = 32; /* zero upper 32 bits for non RISC-V targets */
#అయితే_ముగింపు
        } లేకపోతే {
            ss = 4;
        }
#అయితే_ముగింపు

        ఒకవేళ (ds >= ss)
            వెళ్ళు పూర్తి;
#ఒకవేళ defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64 || defined TCC_లక్ష్యం_ARM64 || defined TCC_లక్ష్యం_RISCV64
    ఒకవేళ (ss == 4) {
        gen_cvt_csti(dbt);
        వెళ్ళు పూర్తి;
    }
#అయితే_ముగింపు
        బిట్లు = (ss - ds) * 8;
        /* for unsigned, gen_op will convert SAR to SHR */
        vtop->type.t = (ss == 8 ? VT_LLONG : VT_INT) | (dbt & VT_UNSIGNED);
        vpushi(బిట్లు);
        gen_op(TOK_SHL);
        vpushi(బిట్లు - trunc);
        gen_op(TOK_SAR);
        vpushi(trunc);
        gen_op(TOK_SHR);
    }
పూర్తి:
    vtop->type = *type;
    vtop->type.t &= ~ ( VT_QUAL | VT_ARRAY | VT_TLS );
}

/* return type size as known at compile time. Put alignment at 'a' */
ST_FUNC పూర్ణాంకం type_కొలత(CType *type, పూర్ణాంకం *a)
{
    Sym *s;
    పూర్ణాంకం bt;

    bt = type->t & VT_BTYPE;
    ఒకవేళ (bt == VT_STRUCT) {
        /* struct/union */
        s = type->ref;
        *a = s->r;
        తిరిగి s->c;
    } లేకపోతే ఒకవేళ (bt == VT_PTR) {
        ఒకవేళ (type->t & VT_ARRAY) {
            పూర్ణాంకం ts;
            s = type->ref;
            ts = type_కొలత(&s->type, a);
            ఒకవేళ (s->c < 0)
                తిరిగి s->c;
            తిరిగి ts * s->c;
        } లేకపోతే {
            *a = PTR_కొలత;
            తిరిగి PTR_కొలత;
        }
    } లేకపోతే ఒకవేళ (IS_ENUM(type->t) && type->ref->c < 0) {
        *a = 0;
        తిరిగి -1; /* incomplete enum */
    } లేకపోతే ఒకవేళ (bt == VT_LDOUBLE) {
        *a = LDOUBLE_ALIGN;
        తిరిగి LDOUBLE_కొలత;
    } లేకపోతే ఒకవేళ (bt == VT_DOUBLE || bt == VT_LLONG) {
#ఒకవేళ (defined TCC_లక్ష్యం_I386 && !defined TCC_లక్ష్యం_PE) \
 || (defined TCC_లక్ష్యం_ARM && !defined TCC_ARM_EABI)
        *a = 4;
#లేకపోతే
        *a = 8;
#అయితే_ముగింపు
        తిరిగి 8;
    } లేకపోతే ఒకవేళ (bt == VT_INT || bt == VT_FLOAT) {
        *a = 4;
        తిరిగి 4;
    } లేకపోతే ఒకవేళ (bt == VT_SHORT) {
        *a = 2;
        తిరిగి 2;
    } లేకపోతే ఒకవేళ (bt == VT_QLONG || bt == VT_QFLOAT) {
        *a = 8;
        తిరిగి 16;
    } లేకపోతే {
        /* char, void, function, _Bool */
        *a = 1;
        తిరిగి 1;
    }
}

/* push type size as known at runtime time on top of value stack. Put
   alignment at 'a' */
స్థిర శూన్య vpush_type_కొలత(CType *type, పూర్ణాంకం *a)
{
    ఒకవేళ (type->t & VT_VLA) {
        type_కొలత(&type->ref->type, a);
        vset(&int_type, VT_LOCAL|VT_LVAL, type->ref->c);
    } లేకపోతే {
        పూర్ణాంకం కొలత = type_కొలత(type, a);
        ఒకవేళ (కొలత < 0)
            tcc_error("unknown type size");
        vpushs(కొలత);
    }
}

/* return the pointed type of t */
స్థిర అంతఃవరుస CType *pointed_type(CType *type)
{
    తిరిగి &type->ref->type;
}

స్థిర శూన్య check_restrict_type(CType *type)
{
    అయితే ((type->t & VT_BTYPE) == VT_PTR) {
        ఒకవేళ ((type->t & VT_RESTRICT)
            && (pointed_type(type)->t & VT_BTYPE) == VT_FUNC)
            tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
        type = pointed_type(type);
    }
    ఒకవేళ (type->t & VT_RESTRICT)
        tcc_error("restrict-qualified type must be a pointer to object or incomplete type");
}

/* Array qualifiers are represented on the element type. */
స్థిర పూర్ణాంకం type_qualifiers(CType *type)
{
    అయితే (type->t & VT_ARRAY)
        type = pointed_type(type);
    తిరిగి type->t & VT_QUAL;
}

/* modify type so that its it is a pointer to type. */
ST_FUNC శూన్య mk_సూచిక(CType *type)
{
    Sym *s;
    s = sym_నెట్టు(SYM_క్షేత్రం, type, 0, -1);
    type->t = VT_PTR | (type->t & VT_STORAGE);
    type->ref = s;
}

/* return true if type1 and type2 are exactly the same (including
   qualifiers). 
*/
స్థిర పూర్ణాంకం is_compatible_types(CType *type1, CType *type2)
{
    తిరిగి compare_types(type1,type2,0);
}

/* return true if type1 and type2 are the same (ignoring qualifiers).
*/
స్థిర పూర్ణాంకం is_compatible_unqualified_types(CType *type1, CType *type2)
{
    తిరిగి compare_types(type1,type2,1);
}

స్థిర శూన్య cast_error(CType *st, CType *dt)
{
    type_incompatibility_error(st, dt, "cannot convert '%s' to '%s'");
}

/* verify type compatibility to store vtop in 'dt' type */
స్థిర శూన్య verify_కేటాయించు_cast(CType *dt)
{
    CType *st, *type1, *type2;
    పూర్ణాంకం dbt, sbt, qualwarn, lvl;

    st = &vtop->type; /* source type */
    dbt = dt->t & VT_BTYPE;
    sbt = st->t & VT_BTYPE;
    ఒకవేళ (dt->t & VT_CONSTANT)
        tcc_warning("assignment of read-only location");
    ఎంపిక(dbt) {
    స్థితి VT_VOID:
        ఒకవేళ (sbt != dbt)
            tcc_error("assignment to void expression");
        ఆపు;
    స్థితి VT_PTR:
        /* special cases for pointers */
        /* '0' can also be a pointer */
        ఒకవేళ (is_null_సూచిక(vtop))
            ఆపు;
        /* accept implicit pointer to integer cast with warning */
        ఒకవేళ (is_integer_btype(sbt)) {
            tcc_warning("assignment makes pointer from integer without a cast");
            ఆపు;
        }
        type1 = pointed_type(dt);
        ఒకవేళ (sbt == VT_PTR)
            type2 = pointed_type(st);
        లేకపోతే ఒకవేళ (sbt == VT_FUNC)
            type2 = st; /* a function is implicitly a function pointer */
        లేకపోతే
            వెళ్ళు error;
        ఒకవేళ (is_compatible_types(type1, type2))
            ఆపు;
        కొరకు (qualwarn = lvl = 0;; ++lvl) {
            ఒకవేళ ((type2->t & ~type1->t) & VT_QUAL)
                qualwarn = 1;
            dbt = type1->t & (VT_BTYPE|VT_LONG);
            sbt = type2->t & (VT_BTYPE|VT_LONG);
            ఒకవేళ (dbt != VT_PTR || sbt != VT_PTR)
                ఆపు;
            type1 = pointed_type(type1);
            type2 = pointed_type(type2);
        }
        ఒకవేళ (!is_compatible_unqualified_types(type1, type2)) {
            ఒకవేళ ((dbt == VT_VOID || sbt == VT_VOID) && lvl == 0) {
                /* void * can match anything */
            } లేకపోతే ఒకవేళ (dbt == sbt
                && is_integer_btype(sbt & VT_BTYPE)
                && IS_ENUM(type1->t) + IS_ENUM(type2->t)
                    + !!((type1->t ^ type2->t) & VT_UNSIGNED) < 2) {
		/* Like GCC don't warn by default for merely changes
		   in pointer target signedness.  Do warn for different
		   base types, though, in particular for unsigned enums
		   and signed int targets.  */
            } లేకపోతే {
                tcc_warning("assignment from incompatible pointer type");
                ఆపు;
            }
        }
        ఒకవేళ (qualwarn)
            tcc_warning_c(warn_discarded_qualifiers)("assignment discards qualifiers from pointer target type");
        ఆపు;
    స్థితి VT_BYTE:
    స్థితి VT_SHORT:
    స్థితి VT_INT:
    స్థితి VT_LLONG:
        ఒకవేళ (sbt == VT_PTR || sbt == VT_FUNC) {
            tcc_warning("assignment makes integer from pointer without a cast");
        } లేకపోతే ఒకవేళ (sbt == VT_STRUCT) {
            వెళ్ళు case_VT_STRUCT;
        }
        /* XXX: more tests */
        ఆపు;
    స్థితి VT_STRUCT:
    case_VT_STRUCT:
        ఒకవేళ (!is_compatible_unqualified_types(dt, st)) {
    error:
            cast_error(st, dt);
        }
        ఆపు;
    }
}

స్థిర శూన్య gen_కేటాయించు_cast(CType *dt)
{
    verify_కేటాయించు_cast(dt);
    gen_cast(dt);
}

/* store vtop in lvalue pushed on stack */
ST_FUNC శూన్య vstore(శూన్య)
{
    పూర్ణాంకం sbt, dbt, ft, r, కొలత, align, బిట్టు_కొలత_2, బిట్టు_pos, delayed_cast;

    ft = vtop[-1].type.t;
    sbt = vtop->type.t & VT_BTYPE;
    dbt = ft & VT_BTYPE;
    verify_కేటాయించు_cast(&vtop[-1].type);

    ఒకవేళ (sbt == VT_STRUCT) {
        /* if structure, only generate pointer */
        /* structure assignment : generate memcpy */
        కొలత = type_కొలత(&vtop->type, &align);
        /* destination, keep on stack() as result */
        vpushv(vtop - 1);
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (vtop->r & VT_MUSTBOUND)
            gbound(); /* check would be wrong after gaddrof() */
#అయితే_ముగింపు
        vtop->type.t = VT_PTR;
        gaddrof();
        /*ఆధారం*/
        vswap();
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (vtop->r & VT_MUSTBOUND)
            gbound();
#అయితే_ముగింపు
        vtop->type.t = VT_PTR;
        gaddrof();

#నిర్వచితమైతే TCC_లక్ష్యం_NATIVE_STRUCT_COPY
        ఒకవేళ (1
#నిర్వచితమైతే CONFIG_TCC_BCHECK
            && !tcc_state->do_bounds_check
#అయితే_ముగింపు
            ) {
            gen_struct_copy(కొలత);
        } లేకపోతే
#అయితే_ముగింపు
        {
            /* type size */
            vpushi(కొలత);
            /* Use memmove, rather than memcpy, as dest and src may be same: */
#నిర్వచితమైతే TCC_ARM_EABI
            ఒకవేళ(!(align & 7))
                vpush_helper_func(TOK_memmove8);
            లేకపోతే ఒకవేళ(!(align & 3))
                vpush_helper_func(TOK_memmove4);
            లేకపోతే
#అయితే_ముగింపు
            vpush_helper_func(TOK_memmove);
            vrott(4);
            gfunc_call(3);
        }

    } లేకపోతే ఒకవేళ (ft & VT_BITFIELD) {
        /* bitfield store handling */

        /* save lvalue as expression result (example: s.b = s.a = n;) */
        vdup(), vtop[-1] = vtop[-2];

        బిట్టు_pos = బిట్టు_POS(ft);
        బిట్టు_కొలత_2 = బిట్టు_కొలత(ft);
        /* remove bit field info to avoid loops */
        vtop[-1].type.t = ft & ~VT_STRUCT_ముసుగు;

        ఒకవేళ (dbt == VT_BOOL) {
            gen_cast(&vtop[-1].type);
            vtop[-1].type.t = (vtop[-1].type.t & ~VT_BTYPE) | (VT_BYTE | VT_UNSIGNED);
        }
        r = adjust_bf(vtop - 1, బిట్టు_pos, బిట్టు_కొలత_2);
        ఒకవేళ (dbt != VT_BOOL) {
            gen_cast(&vtop[-1].type);
            dbt = vtop[-1].type.t & VT_BTYPE;
        }
        ఒకవేళ (r == VT_STRUCT) {
            store_packed_bf(బిట్టు_pos, బిట్టు_కొలత_2);
        } లేకపోతే {
            గుర్తులేని దీర్ఘ దీర్ఘ ముసుగు = (1ULL << బిట్టు_కొలత_2) - 1;
            ఒకవేళ (dbt != VT_BOOL) {
                /* mask source */
                ఒకవేళ (dbt == VT_LLONG)
                    vpushll(ముసుగు);
                లేకపోతే
                    vpushi((గుర్తులేని)ముసుగు);
                gen_op('&');
            }
            /* shift source */
            vpushi(బిట్టు_pos);
            gen_op(TOK_SHL);
            vswap();
            /* duplicate destination */
            vdup();
            vrott(3);
            /* load destination, mask and or with source */
            ఒకవేళ (dbt == VT_LLONG)
                vpushll(~(ముసుగు << బిట్టు_pos));
            లేకపోతే
                vpushi(~((గుర్తులేని)ముసుగు << బిట్టు_pos));
            gen_op('&');
            gen_op('|');
            /* store result */
            vstore();
            /* ... and discard */
            vpop();
        }
    } లేకపోతే ఒకవేళ (dbt == VT_VOID) {
        --vtop;
    } లేకపోతే {
            /* optimize char/short casts */
            delayed_cast = 0;
            ఒకవేళ ((dbt == VT_BYTE || dbt == VT_SHORT)
                && is_integer_btype(sbt)
                ) {
                ఒకవేళ ((vtop->r & VT_MUSTCAST)
                    && btype_కొలత(dbt) > btype_కొలత(sbt)
                    )
                    force_charshort_cast();
                delayed_cast = 1;
            } లేకపోతే {
                gen_cast(&vtop[-1].type);
            }

#నిర్వచితమైతే CONFIG_TCC_BCHECK
            /* bound check case */
            ఒకవేళ (vtop[-1].r & VT_MUSTBOUND) {
                vswap();
                gbound();
                vswap();
            }
#అయితే_ముగింపు
            gv(RC_TYPE(dbt)); /* generate value */

            ఒకవేళ (delayed_cast) {
                vtop->r |= BFVAL(VT_MUSTCAST, (sbt == VT_LLONG) + 1);
                //tcc_warning("deley cast %x -> %x", sbt, dbt);
                vtop->type.t = ft & VT_TYPE;
            }

            /* if lvalue was saved on stack, must read it */
            ఒకవేళ ((vtop[-1].r & VT_VALMASK) == VT_LLOCAL) {
                SValue sv;
                r = get_reg(RC_INT);
                sv.type.t = VT_PTRDIFF_T;
                sv.r = VT_LOCAL | VT_LVAL;
                sv.c.i = vtop[-1].c.i;
		sv.sym = ఖాళీ;
                ఎక్కించు(r, &sv);
                vtop[-1].r = r | VT_LVAL;
            }

            r = vtop->r & VT_VALMASK;
            /* two word case handling :
               store second register at word + 4 (or +8 for x86-64)  */
            ఒకవేళ (USING_TWO_పదాలు(dbt)) {
                పూర్ణాంకం ఎక్కించు_type = (dbt == VT_QFLOAT) ? VT_DOUBLE : VT_PTRDIFF_T;
                vtop[-1].type.t = ఎక్కించు_type;
                store(r, vtop - 1);
                vswap();
                incr_స్థానభ్రంశం(PTR_కొలత);
                vswap();
                /* XXX: it works because r2 is spilled last ! */
                store(vtop->r2, vtop - 1);
            } లేకపోతే {
                /* single word */
                store(r, vtop - 1);
            }
        vswap();
        vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
    }
}

/* post defines POST/PRE add. c is the token ++ or -- */
ST_FUNC శూన్య inc(పూర్ణాంకం post, పూర్ణాంకం c)
{
    test_lvalue();
    vdup(); /* save lvalue */
    ఒకవేళ (post) {
        gv_dup(); /* duplicate value */
        vrotb(3);
        vrotb(3);
    }
    /* add constant */
    vpushi(c - TOK_MID); 
    gen_op('+');
    vstore(); /* store value */
    ఒకవేళ (post)
        vpop(); /* if post op, return saved value */
}

ST_FUNC CString* parse_mult_str (స్థిరరాశి అక్షరం *సందేశం)
{
    /* read the string */
    ఒకవేళ (tok != TOK_STR)
        expect(సందేశం);
    cstr_reset(&initstr);
    అయితే (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(&initstr, tokc.str.దత్తాంశం, -1);
        తదుపరి();
    }
    cstr_ccat(&initstr, '\0');
    తిరిగి &initstr;
}

/* If I is >= 1 and a power of two, returns log2(i)+1.
   If I is 0 returns 0.  */
ST_FUNC పూర్ణాంకం exact_log2p1(పూర్ణాంకం i)
{
  పూర్ణాంకం ret;
  ఒకవేళ (!i)
    తిరిగి 0;
  కొరకు (ret = 1; i >= 1 << 8; ret += 8)
    i >>= 8;
  ఒకవేళ (i >= 1 << 4)
    ret += 4, i >>= 4;
  ఒకవేళ (i >= 1 << 2)
    ret += 2, i >>= 2;
  ఒకవేళ (i >= 1 << 1)
    ret++;
  తిరిగి ret;
}

/* Parse __attribute__((...)) GNUC extension. */
స్థిర శూన్య parse_attribute(AttributeDef *ad)
{
    పూర్ణాంకం t, n;
    అక్షరం *astr;
    AttributeDef ad_tmp;
    
redo:
    ఒకవేళ (tok != TOK_ATTRIBUTE1 && tok != TOK_ATTRIBUTE2)
        తిరిగి;
    ఒకవేళ (ఖాళీ == ad) /* skip over / ignore attributes */
        ad = &ad_tmp;

    తదుపరి();
    skip('(');
    skip('(');
    అయితే (tok != ')') {
        ఒకవేళ (tok < TOK_IDENT)
            expect("attribute name");
        t = tok;
        తదుపరి();
        ఎంపిక(t) {
	స్థితి TOK_CLEANUP1:
	స్థితి TOK_CLEANUP2:
	{
	    Sym *s;

	    skip('(');
	    s = sym_కనుగొను(tok);
	    ఒకవేళ (!s) {
	        tcc_warning_c(warn_implicit_function_declaration)(
                    "implicit declaration of function '%s'", get_tok_str(tok, &tokc));
	        s = external_global_sym(tok, &func_old_type);
            } లేకపోతే ఒకవేళ ((s->type.t & VT_BTYPE) != VT_FUNC)
                tcc_error("'%s' is not declared as function", get_tok_str(tok, &tokc));
	    ad->cleanup_func = s;
	    తదుపరి();
            skip(')');
	    ఆపు;
	}
        స్థితి TOK_CONSTRUCTOR1:
        స్థితి TOK_CONSTRUCTOR2:
            ad->f.func_ctor = 1;
            ఆపు;
        స్థితి TOK_DESTRUCTOR1:
        స్థితి TOK_DESTRUCTOR2:
            ad->f.func_dtor = 1;
            ఆపు;
        స్థితి TOK_ALWAYS_INLINE1:
        స్థితి TOK_ALWAYS_INLINE2:
            ad->f.func_alwinl = 1;
            ఆపు;
        స్థితి TOK_SECTION1:
        స్థితి TOK_SECTION2:
            skip('(');
	    astr = parse_mult_str("section name")->దత్తాంశం;
            n = tcc_state->nb_sections;
            ad->section = కనుగొను_section(tcc_state, astr);
            ad->new_section = n < tcc_state->nb_sections;
            skip(')');
            ఆపు;
        స్థితి TOK_ALIAS1:
        స్థితి TOK_ALIAS2:
            skip('(');
	    astr = parse_mult_str("alias(\"target\")")->దత్తాంశం;
            /* save string as token, for later */
            ad->alias_లక్ష్యం = tok_alloc_const(astr);
            skip(')');
            ఆపు;
	స్థితి TOK_VISIBILITY1:
	స్థితి TOK_VISIBILITY2:
            skip('(');
	    astr = parse_mult_str("visibility(\"default|hidden|internal|protected\")")->దత్తాంశం;
	    ఒకవేళ (!strcmp (astr, "default"))
	        ad->a.visibility = STV_DEFAULT;
	    లేకపోతే ఒకవేళ (!strcmp (astr, "hidden"))
	        ad->a.visibility = STV_HIDDEN;
	    లేకపోతే ఒకవేళ (!strcmp (astr, "internal"))
	        ad->a.visibility = STV_అంతర్గత;
	    లేకపోతే ఒకవేళ (!strcmp (astr, "protected"))
	        ad->a.visibility = STV_PROTECTED;
	    లేకపోతే
                expect("visibility(\"default|hidden|internal|protected\")");
            skip(')');
            ఆపు;
        స్థితి TOK_ALIGNED1:
        స్థితి TOK_ALIGNED2:
            ఒకవేళ (tok == '(') {
                తదుపరి();
                n = సమాసం_const();
                ఒకవేళ (n <= 0 || (n & (n - 1)) != 0) 
                    tcc_error("alignment must be a positive power of two");
                skip(')');
            } లేకపోతే {
                n = MAX_ALIGN;
            }
            ad->a.aligned = exact_log2p1(n);
	    ఒకవేళ (n != 1 << (ad->a.aligned - 1))
	      tcc_error("alignment of %d is larger than implemented", n);
            ఆపు;
        స్థితి TOK_PACKED1:
        స్థితి TOK_PACKED2:
            ad->a.packed = 1;
            ఆపు;
        స్థితి TOK_WEAK1:
        స్థితి TOK_WEAK2:
            ad->a.weak = 1;
            ఆపు;
        స్థితి TOK_NODEBUG1:
        స్థితి TOK_NODEBUG2:
            ad->a.nodebug = 1;
            ఆపు;
        స్థితి TOK_USED1:
        స్థితి TOK_USED2:
        స్థితి TOK_UNUSED1:
        స్థితి TOK_UNUSED2:
            /* currently, no need to handle it because tcc does not
               track used/unused objects */
            ఆపు;
        స్థితి TOK_CONST1:
        స్థితి TOK_CONST2:
        స్థితి TOK_CONST3:
        స్థితి TOK_PURE1:
        స్థితి TOK_PURE2:
	    /* ignored */
            ఆపు;
        స్థితి TOK_NOINLINE:
	    /* ignored */
	    ఆపు;
        స్థితి TOK_FORMAT1:
        స్థితి TOK_FORMAT2:
	    /* ignored */
            వెళ్ళు skip_param;
        స్థితి TOK_NORETURN1:
        స్థితి TOK_NORETURN2:
            ad->f.func_noreturn = 1;
            ఆపు;
        స్థితి TOK_CDECL1:
        స్థితి TOK_CDECL2:
        స్థితి TOK_CDECL3:
            ad->f.func_call = FUNC_CDECL;
            ఆపు;
        స్థితి TOK_STDCALL1:
        స్థితి TOK_STDCALL2:
        స్థితి TOK_STDCALL3:
            ad->f.func_call = FUNC_STDCALL;
            ఆపు;
#నిర్వచితమైతే TCC_లక్ష్యం_I386
        స్థితి TOK_REGPARM1:
        స్థితి TOK_REGPARM2:
            skip('(');
            n = సమాసం_const();
            ఒకవేళ (n > 3) 
                n = 3;
            లేకపోతే ఒకవేళ (n < 0)
                n = 0;
            ఒకవేళ (n > 0)
                ad->f.func_call = FUNC_FASTCALL1 + n - 1;
            skip(')');
            ఆపు;
        స్థితి TOK_FASTCALL1:
        స్థితి TOK_FASTCALL2:
        స్థితి TOK_FASTCALL3:
            ad->f.func_call = FUNC_FASTCALLW;
            ఆపు;
        స్థితి TOK_THISCALL1:
        స్థితి TOK_THISCALL2:
        స్థితి TOK_THISCALL3:
            ad->f.func_call = FUNC_THISCALL;
            ఆపు;
#అయితే_ముగింపు
        స్థితి TOK_బహుళకం:
            skip('(');
            ఎంపిక(tok) {
                స్థితి TOK_బహుళకం_DI:
                    ad->attr_బహుళకం = VT_LLONG + 1;
                    ఆపు;
                స్థితి TOK_బహుళకం_QI:
                    ad->attr_బహుళకం = VT_BYTE + 1;
                    ఆపు;
                స్థితి TOK_బహుళకం_HI:
                    ad->attr_బహుళకం = VT_SHORT + 1;
                    ఆపు;
                స్థితి TOK_బహుళకం_SI:
                స్థితి TOK_బహుళకం_మాట:
                    ad->attr_బహుళకం = VT_INT + 1;
                    ఆపు;
                అప్రమేయ:
                    tcc_warning("__mode__(%s) not supported\n", get_tok_str(tok, ఖాళీ));
                    ఆపు;
            }
            తదుపరి();
            skip(')');
            ఆపు;
        స్థితి TOK_DLLEXPORT:
            ad->a.dllexport = 1;
            ఆపు;
        స్థితి TOK_NODECORATE:
            ad->a.nodecorate = 1;
            ఆపు;
        స్థితి TOK_DLLIMPORT:
            ad->a.dllimport = 1;
            ఆపు;
        అప్రమేయ:
            tcc_warning_c(warn_unsupported)("'%s' attribute ignored", get_tok_str(t, ఖాళీ));
            /* skip parameters */
skip_param:
            ఒకవేళ (tok == '(') {
                పూర్ణాంకం parenthesis = 0;
                చేయి {
                    ఒకవేళ (tok == '(') 
                        parenthesis++;
                    లేకపోతే ఒకవేళ (tok == ')') 
                        parenthesis--;
                    తదుపరి();
                } అయితే (parenthesis && tok != -1);
            }
            ఆపు;
        }
        ఒకవేళ (tok != ',')
            ఆపు;
        తదుపరి();
    }
    skip(')');
    skip(')');
    వెళ్ళు redo;
}

స్థిర Sym * కనుగొను_క్షేత్రం (CType *type, పూర్ణాంకం v, పూర్ణాంకం *cumofs)
{
    Sym *s = type->ref;
    పూర్ణాంకం v1 = v | SYM_క్షేత్రం;
    ఒకవేళ (!(v & SYM_క్షేత్రం)) { /* top-level call */
        ఒకవేళ ((type->t & VT_BTYPE) != VT_STRUCT)
            expect("struct or union");
        ఒకవేళ (v < TOK_UIDENT)
            expect("field name");
        ఒకవేళ (s->c < 0)
            tcc_error("dereferencing incomplete type '%s'",
                get_tok_str(s->v & ~SYM_STRUCT, 0));
    }
    అయితే ((s = s->తదుపరి) != ఖాళీ) {
        ఒకవేళ (s->v == v1) {
            *cumofs = s->c;
            తిరిగి s;
        }
        ఒకవేళ ((s->type.t & VT_BTYPE) == VT_STRUCT
          && s->v >= (SYM_మొదటి_ANOM | SYM_క్షేత్రం)) {
            /* try to find field in anonymous sub-struct/union */
            Sym *ret = కనుగొను_క్షేత్రం (&s->type, v1, cumofs);
            ఒకవేళ (ret) {
                *cumofs += s->c;
                తిరిగి ret;
            }
        }
    }
    ఒకవేళ (!(v & SYM_క్షేత్రం))
        tcc_error("field not found: %s", get_tok_str(v, ఖాళీ));
    తిరిగి s;
}

స్థిర శూన్య check_fields (CType *type, పూర్ణాంకం check)
{
    Sym *s = type->ref;

    అయితే ((s = s->తదుపరి) != ఖాళీ) {
        పూర్ణాంకం v = s->v & ~SYM_క్షేత్రం;
        ఒకవేళ (v < SYM_మొదటి_ANOM) {
            TokenSym *ts = పట్టిక_ident[v - TOK_IDENT];
            ఒకవేళ (check && (ts->tok & SYM_క్షేత్రం))
                tcc_error("duplicate member '%s'", get_tok_str(v, ఖాళీ));
            ts->tok ^= SYM_క్షేత్రం;
        } లేకపోతే ఒకవేళ ((s->type.t & VT_BTYPE) == VT_STRUCT)
            check_fields (&s->type, check);
    }
}

స్థిర శూన్య struct_layout(CType *type, AttributeDef *ad)
{
    పూర్ణాంకం కొలత, align, maxalign, స్థానభ్రంశం, c, బిట్టు_pos, బిట్టు_కొలత_2;
    పూర్ణాంకం packed, a, bt, prevbt, prev_బిట్టు_కొలత;
    పూర్ణాంకం pcc = !tcc_state->ms_bitfields;
    పూర్ణాంకం pragma_pack = *tcc_state->pack_దొంతర_ptr;
    Sym *f;

    maxalign = 1;
    స్థానభ్రంశం = 0;
    c = 0;
    బిట్టు_pos = 0;
    prevbt = VT_STRUCT; /* make it never match */
    prev_బిట్టు_కొలత = 0;

//#define BF_DEBUG

    కొరకు (f = type->ref->తదుపరి; f; f = f->తదుపరి) {
        ఒకవేళ (f->type.t & VT_BITFIELD)
            బిట్టు_కొలత_2 = బిట్టు_కొలత(f->type.t);
        లేకపోతే
            బిట్టు_కొలత_2 = -1;
        కొలత = type_కొలత(&f->type, &align);
        a = f->a.aligned ? 1 << (f->a.aligned - 1) : 0;
        packed = 0;

        ఒకవేళ (pcc && బిట్టు_కొలత_2 == 0) {
            /* in pcc mode, packing does not affect zero-width bitfields */

        } లేకపోతే {
            /* in pcc mode, attribute packed overrides if set. */
            ఒకవేళ (pcc && (f->a.packed || ad->a.packed))
                align = packed = 1;

            /* pragma pack overrides align if lesser and packs bitfields always */
            ఒకవేళ (pragma_pack) {
                packed = 1;
                ఒకవేళ (pragma_pack < align)
                    align = pragma_pack;
                /* in pcc mode pragma pack also overrides individual align */
                ఒకవేళ (pcc && pragma_pack < a)
                    a = 0;
            }
        }
        /* some individual align was specified */
        ఒకవేళ (a)
            align = a;

        ఒకవేళ (type->ref->type.t == VT_UNION) {
	    ఒకవేళ (pcc && బిట్టు_కొలత_2 >= 0)
	        కొలత = (బిట్టు_కొలత_2 + 7) >> 3;
	    స్థానభ్రంశం = 0;
	    ఒకవేళ (కొలత > c)
	        c = కొలత;

	} లేకపోతే ఒకవేళ (బిట్టు_కొలత_2 < 0) {
            ఒకవేళ (pcc)
                c += (బిట్టు_pos + 7) >> 3;
	    c = (c + align - 1) & -align;
	    స్థానభ్రంశం = c;
	    ఒకవేళ (కొలత > 0)
	        c += కొలత;
	    బిట్టు_pos = 0;
	    prevbt = VT_STRUCT;
	    prev_బిట్టు_కొలత = 0;

	} లేకపోతే {
	    /* A bit-field.  Layout is more complicated.  There are two
	       options: PCC (GCC) compatible and MS compatible */
            ఒకవేళ (pcc) {
		/* In PCC layout a bit-field is placed adjacent to the
                   preceding bit-fields, except if:
                   - it has zero-width
                   - an individual alignment was given
                   - it would overflow its base type container and
                     there is no packing */
                ఒకవేళ (బిట్టు_కొలత_2 == 0) {
            new_క్షేత్రం:
		    c = (c + ((బిట్టు_pos + 7) >> 3) + align - 1) & -align;
		    బిట్టు_pos = 0;
                } లేకపోతే ఒకవేళ (f->a.aligned) {
                    వెళ్ళు new_క్షేత్రం;
                } లేకపోతే ఒకవేళ (!packed) {
                    పూర్ణాంకం a8 = align * 8;
	            పూర్ణాంకం ofs = ((c * 8 + బిట్టు_pos) % a8 + బిట్టు_కొలత_2 + a8 - 1) / a8;
                    ఒకవేళ (ofs > కొలత / align)
                        వెళ్ళు new_క్షేత్రం;
                }

                /* in pcc mode, long long bitfields have type int if they fit */
                ఒకవేళ (కొలత == 8 && బిట్టు_కొలత_2 <= 32)
                    f->type.t = (f->type.t & ~VT_BTYPE) | VT_INT, కొలత = 4;

                అయితే (బిట్టు_pos >= align * 8)
                    c += align, బిట్టు_pos -= align * 8;
                స్థానభ్రంశం = c;

		/* In PCC layout named bit-fields influence the alignment
		   of the containing struct using the base types alignment,
		   except for packed fields (which here have correct align).  */
		ఒకవేళ (f->v & SYM_మొదటి_ANOM
                    // && bit_size // ??? gcc on ARM/rpi does that
                    )
		    align = 1;

	    } లేకపోతే {
		bt = f->type.t & VT_BTYPE;
		ఒకవేళ ((బిట్టు_pos + బిట్టు_కొలత_2 > కొలత * 8)
                    || (బిట్టు_కొలత_2 > 0) == (bt != prevbt)
                    ) {
		    c = (c + align - 1) & -align;
		    స్థానభ్రంశం = c;
		    బిట్టు_pos = 0;
		    /* In MS bitfield mode a bit-field run always uses
		       at least as many bits as the underlying type.
		       To start a new run it's also required that this
		       or the last bit-field had non-zero width.  */
		    ఒకవేళ (బిట్టు_కొలత_2 || prev_బిట్టు_కొలత)
		        c += కొలత;
		}
		/* In MS layout the records alignment is normally
		   influenced by the field, except for a zero-width
		   field at the start of a run (but by further zero-width
		   fields it is again).  */
		ఒకవేళ (బిట్టు_కొలత_2 == 0 && prevbt != bt)
		    align = 1;
		prevbt = bt;
                prev_బిట్టు_కొలత = బిట్టు_కొలత_2;
	    }

	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_జరుపు))
		        | (బిట్టు_pos << VT_STRUCT_జరుపు);
	    బిట్టు_pos += బిట్టు_కొలత_2;
	}
	ఒకవేళ (align > maxalign)
	    maxalign = align;

#నిర్వచితమైతే BF_DEBUG
	రాయి("set field %s offset %-2d size %-2d align %-2d",
	       get_tok_str(f->v & ~SYM_క్షేత్రం, ఖాళీ), స్థానభ్రంశం, కొలత, align);
	ఒకవేళ (f->type.t & VT_BITFIELD) {
	    రాయి(" pos %-2d bits %-2d",
                    బిట్టు_POS(f->type.t),
                    బిట్టు_కొలత(f->type.t)
                    );
	}
	రాయి("\n");
#అయితే_ముగింపు

        f->c = స్థానభ్రంశం;
	f->r = 0;
    }

    ఒకవేళ (pcc)
        c += (బిట్టు_pos + 7) >> 3;

    /* store size and alignment */
    a = bt = ad->a.aligned ? 1 << (ad->a.aligned - 1) : 1;
    ఒకవేళ (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    ఒకవేళ (pragma_pack && pragma_pack < maxalign && 0 == pcc) {
        /* can happen if individual align for some member was given.  In
           this case MSVC ignores maxalign when aligning the size */
        a = pragma_pack;
        ఒకవేళ (a < bt)
            a = bt;
    }
    c = (c + a - 1) & -a;
    type->ref->c = c;

#నిర్వచితమైతే BF_DEBUG
    రాయి("struct size %-2d align %-2d\n\n", c, a), fflush(stdout);
#అయితే_ముగింపు

    /* check whether we can access bitfields by their type */
    కొరకు (f = type->ref->తదుపరి; f; f = f->తదుపరి) {
        పూర్ణాంకం s, px, cx, c0;
        CType t;

        ఒకవేళ (0 == (f->type.t & VT_BITFIELD))
            కొనసాగు;
        f->type.ref = f;
        f->auxtype = -1;
        బిట్టు_కొలత_2 = బిట్టు_కొలత(f->type.t);
        ఒకవేళ (బిట్టు_కొలత_2 == 0)
            కొనసాగు;
        బిట్టు_pos = బిట్టు_POS(f->type.t);
        కొలత = type_కొలత(&f->type, &align);

        ఒకవేళ (బిట్టు_pos + బిట్టు_కొలత_2 <= కొలత * 8 && f->c + కొలత <= c
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
            && !(f->c & (align - 1))
#అయితే_ముగింపు
            )
            కొనసాగు;

        /* try to access the field using a different type */
        c0 = -1, s = align = 1;
        t.t = VT_BYTE;
        కొరకు (;;) {
            px = f->c * 8 + బిట్టు_pos;
            cx = (px >> 3) & -align;
            px = px - (cx << 3);
            ఒకవేళ (c0 == cx)
                ఆపు;
            s = (px + బిట్టు_కొలత_2 + 7) >> 3;
            ఒకవేళ (s > 4) {
                t.t = VT_LLONG;
            } లేకపోతే ఒకవేళ (s > 2) {
                t.t = VT_INT;
            } లేకపోతే ఒకవేళ (s > 1) {
                t.t = VT_SHORT;
            } లేకపోతే {
                t.t = VT_BYTE;
            }
            s = type_కొలత(&t, &align);
            c0 = cx;
        }

        ఒకవేళ (px + బిట్టు_కొలత_2 <= s * 8 && cx + s <= c
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
            && !(cx & (align - 1))
#అయితే_ముగింపు
            ) {
            /* update offset and bit position */
            f->c = cx;
            బిట్టు_pos = px;
	    f->type.t = (f->type.t & ~(0x3f << VT_STRUCT_జరుపు))
		        | (బిట్టు_pos << VT_STRUCT_జరుపు);
            ఒకవేళ (s != కొలత)
                f->auxtype = t.t;
#నిర్వచితమైతే BF_DEBUG
            రాయి("FIX field %s offset %-2d size %-2d align %-2d "
                "pos %-2d bits %-2d\n",
                get_tok_str(f->v & ~SYM_క్షేత్రం, ఖాళీ),
                cx, s, align, px, బిట్టు_కొలత_2);
#అయితే_ముగింపు
        } లేకపోతే {
            /* fall back to load/store single-byte wise */
            f->auxtype = VT_STRUCT;
#నిర్వచితమైతే BF_DEBUG
            రాయి("FIX field %s : load byte-wise\n",
                 get_tok_str(f->v & ~SYM_క్షేత్రం, ఖాళీ));
#అయితే_ముగింపు
        }
    }
}

/* Does 'n' fit into integer type 't' ? */
స్థిర పూర్ణాంకం లోపల_range(దీర్ఘ దీర్ఘ n, పూర్ణాంకం t)
{
    గుర్తులేని దీర్ఘ దీర్ఘ m = (1ULL << (btype_కొలత(t & VT_BTYPE) * 8 - 1)) - 1;
    ఒకవేళ (t & VT_UNSIGNED)
        తిరిగి n <= (m << 1) + 1;
    తిరిగి n >= -(దీర్ఘ దీర్ఘ)m - 1 && n <= (దీర్ఘ దీర్ఘ)m;
}

/* enum/struct/union declaration. u is VT_ENUM/VT_STRUCT/VT_UNION */
స్థిర శూన్య struct_decl(CType *type, పూర్ణాంకం u)
{
    పూర్ణాంకం v, c, కొలత, align, flexible;
    పూర్ణాంకం బిట్టు_కొలత_2, bsize, bt, ut;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;

    memset(&ad, 0, పరిమాణం ad);
    తదుపరి();
    parse_attribute(&ad);

    v = 0;
    ఒకవేళ (tok >= TOK_IDENT) /* struct/enum tag */
        v = tok, తదుపరి();

    bt = ut = 0;
    ఒకవేళ (u == VT_ENUM) {
        ut = VT_INT;
        ఒకవేళ (tok == ':') { /* C2x enum : <type> ... */
            తదుపరి();
            ఒకవేళ (!parse_btype(&btype, &ad1, 0)
             || !is_integer_btype(btype.t & VT_BTYPE))
                expect("enum type");
            bt = ut = btype.t & (VT_BTYPE|VT_LONG|VT_UNSIGNED|VT_DEFSIGN);
        }
    }

    ఒకవేళ (v) {
        /* struct already defined ? return it */
        s = struct_కనుగొను(v);
        ఒకవేళ (s && (s->sym_scope == local_scope || (tok != '{' && tok != ';'))) {
            ఒకవేళ (u == s->type.t)
                వెళ్ళు do_decl;
            ఒకవేళ (u == VT_ENUM && IS_ENUM(s->type.t)) /* XXX: check integral types */
                వెళ్ళు do_decl;
            tcc_error("redeclaration of '%s'", get_tok_str(v, ఖాళీ));
        }
    } లేకపోతే {
        ఒకవేళ (tok != '{')
            expect("struct/union/enum name");
        v = anon_sym++;
    }
    /* Record the original enum/struct/union token.  */
    type1.t = u | ut;
    type1.ref = ఖాళీ;
    /* we put an undefined size for struct/union */
    s = sym_నెట్టు(v | SYM_STRUCT, &type1, 0, bt ? 0 : -1);
    s->r = 0; /* default alignment is zero as gcc */
do_decl:
    type->t = s->type.t;
    type->ref = s;

    ఒకవేళ (tok == '{') {
        తదుపరి();
        ఒకవేళ (s->c != -1
            && !(u == VT_ENUM && s->c == 0)) /* not yet defined typed enum */
            tcc_error("struct/union/enum already defined");
        s->c = -2;
        /* cannot be empty */
        /* non empty enums are not allowed */
        ps = &s->తదుపరి;
        ఒకవేళ (u == VT_ENUM) {
            దీర్ఘ దీర్ఘ ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            s->sym_scope = local_scope; /* anonymous symbol won't have set */
            /* enum symbols have static storage */
            t.t = VT_INT|VT_STATIC|VT_ENUM_VAL;
            ఒకవేళ (bt)
                t.t = bt|VT_STATIC|VT_ENUM_VAL;
            కొరకు(;;) {
                v = tok;
                ఒకవేళ (v < TOK_UIDENT)
                    expect("identifier");
                తదుపరి();
                ఒకవేళ (tok == '=') {
                    తదుపరి();
		    ll = సమాసం_const64();
                }
                ఒకవేళ (bt && !లోపల_range(ll, t.t))
		    tcc_error("enumerator '%s' out of range of its type",
			get_tok_str(v, ఖాళీ));
                ss = sym_నెట్టు(v, &t, VT_CONST, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->తదుపరి;
                ఒకవేళ (ll < nl)
                    nl = ll;
                ఒకవేళ (ll > pl)
                    pl = ll;
                ఒకవేళ (tok != ',')
                    ఆపు;
                తదుపరి();
                ll++;
                /* NOTE: we accept a trailing comma */
                ఒకవేళ (tok == '}')
                    ఆపు;
            }
            skip('}');

            ఒకవేళ (bt) {
                t.t = bt;
                s->c = 2;
                వెళ్ళు enum_పూర్తి;
            }

            /* set integral type of the enum */
            t.t = VT_INT;
            ఒకవేళ (nl >= 0) {
                ఒకవేళ (pl != (గుర్తులేని)pl)
                    t.t = (LONG_కొలత==8 ? VT_LLONG|VT_LONG : VT_LLONG);
                t.t |= VT_UNSIGNED;
            } లేకపోతే ఒకవేళ (pl != (పూర్ణాంకం)pl || nl != (పూర్ణాంకం)nl)
                t.t = (LONG_కొలత==8 ? VT_LLONG|VT_LONG : VT_LLONG);

            /* set type for enum members */
            కొరకు (ss = s->తదుపరి; ss; ss = ss->తదుపరి) {
                ll = ss->enum_val;
                ఒకవేళ (ll == (పూర్ణాంకం)ll) /* default is int if it fits */
                    కొనసాగు;
                ఒకవేళ (t.t & VT_UNSIGNED) {
                    ss->type.t |= VT_UNSIGNED;
                    ఒకవేళ (ll == (గుర్తులేని)ll)
                        కొనసాగు;
                }
                ss->type.t = (ss->type.t & ~VT_BTYPE)
                    | (LONG_కొలత==8 ? VT_LLONG|VT_LONG : VT_LLONG);
            }
            s->c = 1;
        enum_పూర్తి:
            s->type.t = type->t = t.t | VT_ENUM;

        } లేకపోతే {
            c = 0;
            flexible = 0;
            అయితే (tok != '}') {
                ఒకవేళ (!parse_btype(&btype, &ad1, 0)) {
                    ఒకవేళ (tok == TOK_STATIC_ASSERT) {
                        do_Static_assert();
                        కొనసాగు;
                    }
		    skip(';');
		    కొనసాగు;
		}
                అయితే (1) {
		    ఒకవేళ (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ఖాళీ));
                    బిట్టు_కొలత_2 = -1;
                    v = 0;
                    type1 = btype;
                    ఒకవేళ (tok != ':') {
			ఒకవేళ (tok != ';')
                            type_decl(&type1, &ad1, &v, TYPE_ప్రత్యక్ష);
                        ఒకవేళ (v == 0) {
                    	    ఒకవేళ ((type1.t & VT_BTYPE) != VT_STRUCT)
                        	expect("identifier");
                    	    లేకపోతే {
				పూర్ణాంకం v = btype.ref->v;
				ఒకవేళ ((v & ~SYM_STRUCT) < SYM_మొదటి_ANOM) {
				    ఒకవేళ (tcc_state->ms_extensions == 0)
                        		expect("identifier");
				}
                    	    }
                        }
                        ఒకవేళ (type_కొలత(&type1, &align) < 0) {
			    ఒకవేళ ((u == VT_STRUCT) && (type1.t & VT_ARRAY) && c)
			        flexible = 1;
			    లేకపోతే
			        tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ఖాళీ));
                        }
                        ఒకవేళ ((type1.t & VT_BTYPE) == VT_FUNC ||
			    (type1.t & VT_BTYPE) == VT_VOID ||
                            (type1.t & VT_STORAGE))
                            tcc_error("invalid type for '%s'", 
                                  get_tok_str(v, ఖాళీ));
                    }
                    ఒకవేళ (tok == ':') {
                        తదుపరి();
                        బిట్టు_కొలత_2 = సమాసం_const();
                        /* XXX: handle v = 0 case for messages */
                        ఒకవేళ (బిట్టు_కొలత_2 < 0)
                            tcc_error("negative width in bit-field '%s'", 
                                  get_tok_str(v, ఖాళీ));
                        ఒకవేళ (v && బిట్టు_కొలత_2 == 0)
                            tcc_error("zero width for bit-field '%s'", 
                                  get_tok_str(v, ఖాళీ));
			parse_attribute(&ad1);
                    }
                    కొలత = type_కొలత(&type1, &align);
                    ఒకవేళ (బిట్టు_కొలత_2 >= 0) {
                        bt = type1.t & VT_BTYPE;
                        ఒకవేళ (bt != VT_INT && 
                            bt != VT_BYTE && 
                            bt != VT_SHORT &&
                            bt != VT_BOOL &&
                            bt != VT_LLONG)
                            tcc_error("bitfields must have scalar type");
                        bsize = కొలత * 8;
                        ఒకవేళ (బిట్టు_కొలత_2 > bsize) {
                            tcc_error("width of '%s' exceeds its type",
                                  get_tok_str(v, ఖాళీ));
                        } లేకపోతే ఒకవేళ (బిట్టు_కొలత_2 == bsize
				    && !*tcc_state->pack_దొంతర_ptr
                                    && !ad.a.packed && !ad1.a.packed) {
                            /* no need for bit fields */
                            ;
                        } లేకపోతే ఒకవేళ (బిట్టు_కొలత_2 == 64) {
                            tcc_error("field width 64 not implemented");
                        } లేకపోతే {
                            type1.t = (type1.t & ~VT_STRUCT_ముసుగు)
                                | VT_BITFIELD
                                | ((గుర్తులేని)బిట్టు_కొలత_2 << (VT_STRUCT_జరుపు + 6));
                        }
                    }
                    ఒకవేళ (v != 0 || (type1.t & VT_BTYPE) == VT_STRUCT) {
                        /* Remember we've seen a real field to check
			   for placement of flexible array member. */
			c = 1;
                    }
		    /* If member is a struct or bit-field, enforce
		       placing into the struct (as anonymous).  */
                    ఒకవేళ (v == 0 &&
			((type1.t & VT_BTYPE) == VT_STRUCT ||
			 బిట్టు_కొలత_2 >= 0)) {
		        v = anon_sym++;
		    }
                    ఒకవేళ (v) {
                        ss = sym_నెట్టు(v | SYM_క్షేత్రం, &type1, 0, 0);
                        ss->a = ad1.a;
                        *ps = ss;
                        ps = &ss->తదుపరి;
                    }
                    ఒకవేళ (tok == ';' || tok == TOK_EOF)
                        ఆపు;
                    skip(',');
                }
                skip(';');
            }
            skip('}');
	    parse_attribute(&ad);
            ఒకవేళ (ad.cleanup_func) {
                tcc_warning("attribute '__cleanup__' ignored on type");
            }
	    check_fields(type, 1);
	    check_fields(type, 0);
            struct_layout(type, &ad);
        }
        ఒకవేళ (debug_modes)
            tcc_debug_fix_forw(tcc_state, type);
    }
}

స్థిర శూన్య sym_గమ్యం_attr(AttributeDef *ad, Sym *s)
{
    విలీనం_symattr(&ad->a, &s->a);
    విలీనం_funcattr(&ad->f, &s->f);
}

/* Add type qualifiers to a type. If the type is an array then the qualifiers
   are added to the element type, copied because it could be a typedef. */
స్థిర శూన్య parse_btype_qualify(CType *type, పూర్ణాంకం qualifiers)
{
    అయితే (type->t & VT_ARRAY) {
        type->ref = sym_నెట్టు(SYM_క్షేత్రం, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    ఒకవేళ (qualifiers & VT_RESTRICT)
        check_restrict_type(type);
    type->t |= qualifiers;
}

/* return 0 if no type declaration. otherwise, return the basic type
   and skip it. 
 */
స్థిర పూర్ణాంకం parse_btype(CType *type, AttributeDef *ad, పూర్ణాంకం ignore_label)
{
    పూర్ణాంకం t, u, bt, st, type_దొరికింది, typespec_దొరికింది, g, n;
    Sym *s;
    CType type1;

    memset(ad, 0, పరిమాణం(AttributeDef));
    type_దొరికింది = 0;
    typespec_దొరికింది = 0;
    t = VT_INT;
    bt = st = -1;
    type->ref = ఖాళీ;

    అయితే(1) {
        ఎంపిక(tok) {
        స్థితి TOK_EXTENSION:
            /* currently, we really ignore extension */
            తదుపరి();
            కొనసాగు;

            /* basic types */
        స్థితి TOK_CHAR:
            u = VT_BYTE;
        basic_type:
            తదుపరి();
        basic_type1:
            ఒకవేళ (u == VT_SHORT || u == VT_LONG) {
                ఒకవేళ (st != -1 || (bt != -1 && bt != VT_INT))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } లేకపోతే {
                ఒకవేళ (bt != -1 || (st != -1 && u != VT_INT))
                    వెళ్ళు tmbt;
                ఒకవేళ ((t & VT_DEFSIGN) && (u == VT_VOID || u > VT_LLONG))
                    వెళ్ళు tmbt;
                bt = u;
            }
            ఒకవేళ (u != VT_INT)
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            typespec_దొరికింది = 1;
            ఆపు;
        స్థితి TOK_VOID:
            u = VT_VOID;
            వెళ్ళు basic_type;
        స్థితి TOK_SHORT:
            u = VT_SHORT;
            వెళ్ళు basic_type;
        స్థితి TOK_INT:
            u = VT_INT;
            వెళ్ళు basic_type;
        స్థితి TOK_ALIGNAS:
            { పూర్ణాంకం n;
              AttributeDef ad1;
              తదుపరి();
              skip('(');
              memset(&ad1, 0, పరిమాణం(AttributeDef));
              ఒకవేళ (parse_btype(&type1, &ad1, 0)) {
                  type_decl(&type1, &ad1, &n, TYPE_ABSTRACT);
                  ఒకవేళ (ad1.a.aligned)
                    n = 1 << (ad1.a.aligned - 1);
                  లేకపోతే
                    type_కొలత(&type1, &n);
              } లేకపోతే {
                  n = సమాసం_const();
                  ఒకవేళ (n < 0 || (n & (n - 1)) != 0)
                    tcc_error("alignment must be a positive power of two");
              }
              skip(')');
              ad->a.aligned = exact_log2p1(n);
            }
            కొనసాగు;
        స్థితి TOK_LONG:
            ఒకవేళ ((t & VT_BTYPE) == VT_DOUBLE) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } లేకపోతే ఒకవేళ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LLONG;
            } లేకపోతే {
                u = VT_LONG;
                వెళ్ళు basic_type;
            }
            తదుపరి();
            ఆపు;
        స్థితి TOK_BOOL:
            u = VT_BOOL;
            వెళ్ళు basic_type;
        స్థితి TOK_COMPLEX:
            tcc_error("_Complex is not yet supported");
        స్థితి TOK_FLOAT:
            u = VT_FLOAT;
            వెళ్ళు basic_type;
        స్థితి TOK_DOUBLE:
            ఒకవేళ ((t & (VT_BTYPE|VT_LONG)) == VT_LONG) {
                t = (t & ~(VT_BTYPE|VT_LONG)) | VT_LDOUBLE;
            } లేకపోతే {
                u = VT_DOUBLE;
                వెళ్ళు basic_type;
            }
            తదుపరి();
            ఆపు;
        స్థితి TOK_ENUM:
            struct_decl(&type1, VT_ENUM);
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            వెళ్ళు basic_type1;
        స్థితి TOK_STRUCT:
            struct_decl(&type1, VT_STRUCT);
            వెళ్ళు basic_type2;
        స్థితి TOK_UNION:
            struct_decl(&type1, VT_UNION);
            వెళ్ళు basic_type2;

            /* type modifiers */
        స్థితి TOK__Atomic:
            తదుపరి();
            type->t = t;
            parse_btype_qualify(type, VT_ATOMIC);
            t = type->t;
            ఒకవేళ (tok == '(') {
                parse_సమాసం_type(&type1);
                /* remove all storage modifiers except typedef */
                type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
                ఒకవేళ (type1.ref)
                    sym_గమ్యం_attr(ad, type1.ref);
                వెళ్ళు basic_type2;
            }
            ఆపు;
        స్థితి TOK_CONST1:
        స్థితి TOK_CONST2:
        స్థితి TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, VT_CONSTANT);
            t = type->t;
            తదుపరి();
            ఆపు;
        స్థితి TOK_VOLATILE1:
        స్థితి TOK_VOLATILE2:
        స్థితి TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, VT_VOLATILE);
            t = type->t;
            తదుపరి();
            ఆపు;
        స్థితి TOK_SIGNED1:
        స్థితి TOK_SIGNED2:
        స్థితి TOK_SIGNED3:
            ఒకవేళ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == (VT_DEFSIGN|VT_UNSIGNED))
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN;
            తదుపరి();
            typespec_దొరికింది = 1;
            ఆపు;
        స్థితి TOK_RESTRICT1:
        స్థితి TOK_RESTRICT2:
        స్థితి TOK_RESTRICT3:
            t |= VT_RESTRICT;
            తదుపరి();
            ఆపు;
        స్థితి TOK_రిజిస్టరు:
        స్థితి TOK_AUTO:
            తదుపరి();
            ఆపు;
        స్థితి TOK_UNSIGNED:
            ఒకవేళ ((t & (VT_DEFSIGN|VT_UNSIGNED)) == VT_DEFSIGN)
                tcc_error("signed and unsigned modifier");
            t |= VT_DEFSIGN | VT_UNSIGNED;
            తదుపరి();
            typespec_దొరికింది = 1;
            ఆపు;

            /* storage */
        స్థితి TOK_EXTERN:
            g = VT_EXTERN;
            వెళ్ళు storage;
        స్థితి TOK_STATIC:
            g = VT_STATIC;
            వెళ్ళు storage;
        స్థితి TOK_TYPEDEF:
            g = VT_TYPEDEF;
            వెళ్ళు storage;
       storage:
            ఒకవేళ (t & (VT_EXTERN|VT_STATIC|VT_TYPEDEF) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            తదుపరి();
            ఆపు;
        స్థితి TOK_INLINE1:
        స్థితి TOK_INLINE2:
        స్థితి TOK_INLINE3:
            t |= VT_INLINE;
            తదుపరి();
            ఆపు;
        స్థితి TOK_NORETURN3:
            తదుపరి();
            ad->f.func_noreturn = 1;
            ఆపు;
            /* GNUC attribute */
        స్థితి TOK_ATTRIBUTE1:
        స్థితి TOK_ATTRIBUTE2:
            parse_attribute(ad);
            ఒకవేళ (ad->attr_బహుళకం) {
                u = ad->attr_బహుళకం -1;
                t = (t & ~(VT_BTYPE|VT_LONG)) | u;
            }
            కొనసాగు;
            /* GNUC typeof */
        స్థితి TOK_TYPEOF1:
        స్థితి TOK_TYPEOF2:
        స్థితి TOK_TYPEOF3:
            తదుపరి();
            parse_సమాసం_type(&type1);
            /* remove all storage modifiers except typedef */
            type1.t &= ~(VT_STORAGE&~VT_TYPEDEF);
            ఒకవేళ (type1.ref) {
                sym_గమ్యం_attr(ad, type1.ref);
                ఒకవేళ (type1.t & VT_ARRAY)
                    type1.t |= VT_BT_ARRAY;
            }
            వెళ్ళు basic_type2;
        స్థితి TOK_THREAD_LOCAL:
        స్థితి TOK___thread:
            ఒకవేళ (t & VT_TLS)
                tcc_error("multiple thread-local storage specifiers");
            t |= VT_TLS;
            తదుపరి();
            ఆపు;
        అప్రమేయ:
            ఒకవేళ (typespec_దొరికింది)
                వెళ్ళు the_చివర;
            s = sym_కనుగొను(tok);
            ఒకవేళ (!s || !(s->type.t & VT_TYPEDEF))
                వెళ్ళు the_చివర;

            n = tok, తదుపరి();
            ఒకవేళ (tok == ':' && ignore_label) {
                /* ignore if it's a label */
                unget_tok(n);
                వెళ్ళు the_చివర;
            }

            t &= ~(VT_BTYPE|VT_LONG);
            u = t & ~VT_QUAL, t ^= u;
            type->t = (s->type.t & ~VT_TYPEDEF) | u;
            type->ref = s->type.ref;
            ఒకవేళ (t)
                parse_btype_qualify(type, t);
            t = type->t;
            ఒకవేళ (t & VT_ARRAY)
                t |= VT_BT_ARRAY;
            /* get attributes from typedef */
            sym_గమ్యం_attr(ad, s);
            typespec_దొరికింది = 1;
            st = bt = -2;
            ఆపు;
        }
        type_దొరికింది = 1;
    }
the_చివర:
    ఒకవేళ (tcc_state->char_is_unsigned) {
        ఒకవేళ ((t & (VT_DEFSIGN|VT_BTYPE)) == VT_BYTE)
            t |= VT_UNSIGNED;
    }
    /* VT_LONG is used just as a modifier for VT_INT / VT_LLONG */
    bt = t & (VT_BTYPE|VT_LONG);
    ఒకవేళ (bt == VT_LONG)
        t |= LONG_కొలత == 8 ? VT_LLONG : VT_INT;
#నిర్వచితమైతే TCC_USING_DOUBLE_FOR_LDOUBLE
    ఒకవేళ (bt == VT_LDOUBLE)
        t = (t & ~(VT_BTYPE|VT_LONG)) | (VT_DOUBLE|VT_LONG);
#అయితే_ముగింపు
    type->t = t;
    check_restrict_type(type);
    తిరిగి type_దొరికింది;
}

/* convert a function parameter type (array to pointer and function to
   function pointer) */
స్థిర అంతఃవరుస శూన్య convert_parameter_type(CType *pt)
{
    /* array must be transformed to pointer according to ANSI C */
    pt->t &= ~(VT_ARRAY | VT_VLA);
    ఒకవేళ ((pt->t & VT_BTYPE) == VT_FUNC) {
        mk_సూచిక(pt);
    }
}

/* apply the conversions required for an expression value */
స్థిర అంతఃవరుస శూన్య convert_వ్యక్తీకరణ_type(CType *pt)
{
    pt->t &= ~VT_QUAL;
    convert_parameter_type(pt);
}

ST_FUNC CString* parse_asm_str(శూన్య)
{
    skip('(');
    తిరిగి parse_mult_str("string constant");
}

/* Parse an asm label and return the token */
స్థిర పూర్ణాంకం asm_label_instr(శూన్య)
{
    పూర్ణాంకం v;
    అక్షరం *astr;

    తదుపరి();
    astr = parse_asm_str()->దత్తాంశం;
    skip(')');
#నిర్వచితమైతే ASM_DEBUG
    రాయి("asm_alias: \"%s\"\n", astr);
#అయితే_ముగింపు
    v = tok_alloc_const(astr);
    తిరిగి v;
}

స్థిర పూర్ణాంకం post_type(CType *type, AttributeDef *ad, పూర్ణాంకం storage, పూర్ణాంకం td)
{
    పూర్ణాంకం n, l, t1, arg_కొలత, align;
    Sym **plast, *s, *మొదటి, **ps, *sr;
    AttributeDef ad1;
    CType pt;
    TokenString *vla_array_tok = ఖాళీ;
    పూర్ణాంకం *vla_array_str = ఖాళీ;

    ఒకవేళ (tok == '(') {
        /* function type, or recursive declarator (return if so) */
        తదుపరి();
	ఒకవేళ (TYPE_ప్రత్యక్ష == (td & (TYPE_ప్రత్యక్ష|TYPE_ABSTRACT)))
	  తిరిగి 0;

        /* we push a anonymous symbol which will contain the function prototype */
        /* it also serves as a boundary for the function parameter scope */
        ps = local_దొంతర ? &local_దొంతర : &global_దొంతర;
        ++local_scope;
        sr = sym_push2(ps, SYM_క్షేత్రం, 0, 0);

	ఒకవేళ (tok == ')')
	  l = 0;
	లేకపోతే ఒకవేళ (parse_btype(&pt, &ad1, 0))
	  l = FUNC_NEW;
	లేకపోతే ఒకవేళ (td & (TYPE_ప్రత్యక్ష|TYPE_ABSTRACT)) {
            sym_తీయి(ps, sr->prev, 0);
            --local_scope;
	    విలీనం_attr (ad, &ad1);
	    తిరిగి 0;
	} లేకపోతే
	  l = FUNC_OLD;

        మొదటి = ఖాళీ;
        plast = &మొదటి;
        arg_కొలత = 0;
        ఒకవేళ (l) {
            కొరకు(;;) {
                /* read param name and compute offset */
                ఒకవేళ (l != FUNC_OLD) {
                    ఒకవేళ ((pt.t & VT_BTYPE) == VT_VOID && tok == ')')
                        ఆపు;
                    type_decl(&pt, &ad1, &n, TYPE_ప్రత్యక్ష | TYPE_ABSTRACT | TYPE_PARAM);
                    ఒకవేళ ((pt.t & VT_BTYPE) == VT_VOID)
                        tcc_error("parameter declared as void");
                    ఒకవేళ (n == 0 || (td & TYPE_PARAM))
                        n |= SYM_క్షేత్రం;
                } లేకపోతే {
                    n = tok;
                    pt.t = VT_INT | VT_EXTERN; /* default type */
                    pt.ref = ఖాళీ;
                    తదుపరి();
                }
                ఒకవేళ (n < TOK_UIDENT)
                    expect("identifier");
                convert_parameter_type(&pt);
                arg_కొలత += (type_కొలత(&pt, &align) + PTR_కొలత - 1) / PTR_కొలత;
                /* these symbols may be evaluated for VLArrays (see below, under
                   nocode_wanted) Example: int func(int a, int b[++a]); */
                s = sym_నెట్టు(n, &pt, VT_LOCAL|VT_LVAL, 0);
                *plast = s;
                plast = &s->తదుపరి;
                ఒకవేళ (tok == ')')
                    ఆపు;
                skip(',');
                ఒకవేళ (l == FUNC_NEW && tok == TOK_DOTS) {
                    l = FUNC_ELLIPSIS;
                    తదుపరి();
                    ఆపు;
                }
		ఒకవేళ (l == FUNC_NEW && !parse_btype(&pt, &ad1, 0))
		    tcc_error("invalid type");
            }
        } లేకపోతే
            /* if no parameters, then old type prototype */
            l = FUNC_OLD;
        skip(')');
        /* A function return value has the unqualified version of its
           declared type. */
        type->t &= ~VT_QUAL;
        /* some ancient pre-K&R C allows a function to return an array
           and the array brackets to be put after the arguments, such 
           that "int c()[]" means something like "int[] c()" */
        ఒకవేళ (tok == '[') {
            తదుపరి();
            skip(']'); /* only handle simple "[]" */
            mk_సూచిక(type);
        }
        ad->f.func_వాదనలు = arg_కొలత;
        ad->f.func_type = l;
        sr->type = *type, s = sr;
        s->a = ad->a;
        s->f = ad->f;
        s->తదుపరి = మొదటి;
        type->t = VT_FUNC;
        type->ref = s;
        /* unlink parameter symbols from the token table, keep on stack */
        sym_తీయి(ps, sr, 1);
        --local_scope;

    } లేకపోతే ఒకవేళ (tok == '[') {
	పూర్ణాంకం saved_nocode_wanted = nocode_wanted;
        పూర్ణాంకం array_qualifiers = 0;
        /* array definition */
        తదుపరి();
        n = -1;
        t1 = 0;
        ఒకవేళ (td & TYPE_PARAM) అయితే (1) {
	    /* XXX The optional type-quals and static should only be accepted
	       in parameter decls.  The '*' as well, and then even only
	       in prototypes (not function defs).  */
	    ఎంపిక (tok) {
	    స్థితి TOK_CONST1: స్థితి TOK_CONST2: స్థితి TOK_CONST3:
		array_qualifiers |= VT_CONSTANT;
		తదుపరి();
		కొనసాగు;
	    స్థితి TOK_VOLATILE1: స్థితి TOK_VOLATILE2: స్థితి TOK_VOLATILE3:
		array_qualifiers |= VT_VOLATILE;
		తదుపరి();
		కొనసాగు;
	    స్థితి TOK_RESTRICT1: స్థితి TOK_RESTRICT2: స్థితి TOK_RESTRICT3:
		array_qualifiers |= VT_RESTRICT;
		తదుపరి();
		కొనసాగు;
	    స్థితి TOK_STATIC:
	    స్థితి '*':
		తదుపరి();
		కొనసాగు;
	    అప్రమేయ:
		ఆపు;
	    }
            ఒకవేళ (tok != ']') {
		/* Code generation is not done now but has to be done
		   at start of function. Save code here for later use. */
	        nocode_wanted = 1;
		skip_or_save_ఖండం(&vla_array_tok);
		unget_tok(0);
		vla_array_str = vla_array_tok->str;
		begin_macro(vla_array_tok, 2);
		తదుపరి();
	        gexpr();
		చివర_macro();
		తదుపరి();
		వెళ్ళు check;
            }
            ఆపు;

	} లేకపోతే ఒకవేళ (tok != ']') {
            ఒకవేళ (!local_దొంతర || (storage & VT_STATIC))
                vpushi(సమాసం_const());
            లేకపోతే {
		/* VLAs (which can only happen with local_stack && !VT_STATIC)
		   length must always be evaluated, even under nocode_wanted,
		   so that its size slot is initialized (e.g. under sizeof
		   or typeof).  */
		nocode_wanted = 0;
		gexpr();
	    }
check:
            ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
                n = vtop->c.i;
                ఒకవేళ (n < 0)
                    tcc_error("invalid array size");
            } లేకపోతే {
                ఒకవేళ (!is_integer_btype(vtop->type.t & VT_BTYPE))
                    tcc_error("size of variable length array should be an integer");
                n = 0;
                t1 = VT_VLA;
            }
        }
        skip(']');
        /* parse next post type */
        post_type(type, ad, storage, (td & ~(TYPE_ప్రత్యక్ష|TYPE_ABSTRACT)) | TYPE_NEST);

        ఒకవేళ ((type->t & VT_BTYPE) == VT_FUNC)
            tcc_error("declaration of an array of functions");
        ఒకవేళ ((type->t & VT_BTYPE) == VT_VOID
            || type_కొలత(type, &align) < 0)
            tcc_error("declaration of an array of incomplete type elements");

        t1 |= type->t & VT_VLA;

        ఒకవేళ (t1 & VT_VLA) {
            ఒకవేళ (n < 0) {
		ఒకవేళ  (td & TYPE_NEST)
                    tcc_error("need explicit inner array size in VLAs");
	    }
	    లేకపోతే {
                loc -= type_కొలత(&int_type, &align);
                loc &= -align;
                n = loc;

                vpush_type_కొలత(type, &align);
                gen_op('*');
                vset(&int_type, VT_LOCAL|VT_LVAL, n);
                vswap();
                vstore();
	    }
        }
        ఒకవేళ (n != -1)
            vpop();
	nocode_wanted = saved_nocode_wanted;
                
        /* we push an anonymous symbol which will contain the array
           element type */
        s = sym_నెట్టు(SYM_క్షేత్రం, type, 0, n);
        type->t = (t1 ? VT_VLA : VT_ARRAY) | VT_PTR;
        type->ref = s;
        type->t |= array_qualifiers;

        ఒకవేళ (vla_array_str) {
            /* for function args, the top dimension is converted to pointer */
	    ఒకవేళ ((t1 & VT_VLA) && (td & TYPE_NEST))
	        s->vla_array_str = vla_array_str;
	    లేకపోతే
	        tok_str_free_str(vla_array_str);
	}
    }
    తిరిగి 1;
}

/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
స్థిర CType *type_decl(CType *type, AttributeDef *ad, పూర్ణాంకం *v, పూర్ణాంకం td)
{
    CType *post, *ret;
    పూర్ణాంకం qualifiers, storage;

    /* recursive type, remove storage bits first, apply them later again */
    storage = type->t & VT_STORAGE;
    type->t &= ~VT_STORAGE;
    post = ret = type;

    అయితే (tok == '*') {
        qualifiers = 0;
    redo:
        తదుపరి();
        ఎంపిక(tok) {
        స్థితి TOK__Atomic:
            qualifiers |= VT_ATOMIC;
            వెళ్ళు redo;
        స్థితి TOK_CONST1:
        స్థితి TOK_CONST2:
        స్థితి TOK_CONST3:
            qualifiers |= VT_CONSTANT;
            వెళ్ళు redo;
        స్థితి TOK_VOLATILE1:
        స్థితి TOK_VOLATILE2:
        స్థితి TOK_VOLATILE3:
            qualifiers |= VT_VOLATILE;
            వెళ్ళు redo;
        స్థితి TOK_RESTRICT1:
        స్థితి TOK_RESTRICT2:
        స్థితి TOK_RESTRICT3:
            qualifiers |= VT_RESTRICT;
            వెళ్ళు redo;
	/* XXX: clarify attribute handling */
	స్థితి TOK_ATTRIBUTE1:
	స్థితి TOK_ATTRIBUTE2:
	    parse_attribute(ad);
	    ఆపు;
        }
        mk_సూచిక(type);
        type->t |= qualifiers;
	ఒకవేళ (ret == type)
	    /* innermost pointed to type is the one for the first derivation */
	    ret = pointed_type(type);
    }

    ఒకవేళ (tok == '(') {
	/* This is possibly a parameter type list for abstract declarators
	   ('int ()'), use post_type for testing this.  */
	ఒకవేళ (!post_type(type, ad, 0, td)) {
	    /* It's not, so it's a nested declarator, and the post operations
	       apply to the innermost pointed to type (if any).  */
	    /* XXX: this is not correct to modify 'ad' at this point, but
	       the syntax is not clear */
	    parse_attribute(ad);
	    post = type_decl(type, ad, v, td);
	    skip(')');
	} లేకపోతే
	  వెళ్ళు abstract;
    } లేకపోతే ఒకవేళ (tok >= TOK_IDENT && (td & TYPE_ప్రత్యక్ష)) {
	/* type identifier */
	*v = tok;
	తదుపరి();
    } లేకపోతే {
  abstract:
	ఒకవేళ (!(td & TYPE_ABSTRACT))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, post != ret ? 0 : storage,
              td & ~(TYPE_ప్రత్యక్ష|TYPE_ABSTRACT));
    check_restrict_type(type);
    parse_attribute(ad);
    type->t |= storage;
    తిరిగి ret;
}

/* indirection with full error checking and bound check */
ST_FUNC శూన్య indir(శూన్య)
{
    ఒకవేళ ((vtop->type.t & VT_BTYPE) != VT_PTR) {
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
            తిరిగి;
        expect("pointer");
    }
    ఒకవేళ (vtop->r & VT_LVAL)
        gv(RC_INT);
    vtop->type = *pointed_type(&vtop->type);
    /* Arrays and functions are never lvalues */
    ఒకవేళ (!(vtop->type.t & (VT_ARRAY | VT_VLA))
        && (vtop->type.t & VT_BTYPE) != VT_FUNC) {
        vtop->r |= VT_LVAL;
        /* if bound checking, the referenced pointer must be checked */
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (tcc_state->do_bounds_check)
            vtop->r |= VT_MUSTBOUND;
#అయితే_ముగింపు
    }
}

/* pass a parameter to a function and do type checking and casting */
స్థిర శూన్య gfunc_param_typed(Sym *func, Sym *arg)
{
    పూర్ణాంకం func_type;
    CType type;

    func_type = func->f.func_type;
    ఒకవేళ (func_type == FUNC_OLD ||
        (func_type == FUNC_ELLIPSIS && arg == ఖాళీ)) {
        /* default casting : only need to convert float to double */
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_FLOAT) {
            gen_cast_s(VT_DOUBLE);
        } లేకపోతే ఒకవేళ (vtop->type.t & VT_BITFIELD) {
            type.t = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
	    type.ref = vtop->type.ref;
            gen_cast(&type);
        } లేకపోతే ఒకవేళ (vtop->r & VT_MUSTCAST) {
            force_charshort_cast();
        }
    } లేకపోతే ఒకవేళ (arg == ఖాళీ) {
        tcc_error("too many arguments to function");
    } లేకపోతే {
        type = arg->type;
        type.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */
        gen_కేటాయించు_cast(&type);
    }
}

/* parse an expression and return its type without any side effect. */
స్థిర శూన్య సమాసం_type(CType *type, శూన్య (*సమాసం_fn)(శూన్య))
{
    nocode_wanted++;
    సమాసం_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}

/* parse an expression of the form '(type)' or '(expr)' and return its
   type */
స్థిర శూన్య parse_సమాసం_type(CType *type)
{
    పూర్ణాంకం n;
    AttributeDef ad;

    skip('(');
    ఒకవేళ (parse_btype(type, &ad, 0)) {
        type_decl(type, &ad, &n, TYPE_ABSTRACT);
    } లేకపోతే {
        సమాసం_type(type, gexpr);
    }
    skip(')');
}

స్థిర శూన్య parse_type(CType *type)
{
    AttributeDef ad;
    పూర్ణాంకం n;

    ఒకవేళ (!parse_btype(type, &ad, 0)) {
        expect("type");
    }
    type_decl(type, &ad, &n, TYPE_ABSTRACT);
}

స్థిర శూన్య parse_builtin_params(పూర్ణాంకం nc, స్థిరరాశి అక్షరం *వాదనలు)
{
    అక్షరం c, sep = '(';
    CType type;
    ఒకవేళ (nc)
        nocode_wanted++;
    తదుపరి();
    ఒకవేళ (*వాదనలు == 0)
	skip(sep);
    అయితే ((c = *వాదనలు++)) {
	skip(sep);
	sep = ',';
        ఒకవేళ (c == 't') {
            parse_type(&type);
	    vpush(&type);
	    కొనసాగు;
        }
        సమాసం_eq();
        type.ref = ఖాళీ;
        type.t = 0;
	ఎంపిక (c) {
	    స్థితి 'e':
		కొనసాగు;
	    స్థితి 'V':
                type.t = VT_CONSTANT;
	    స్థితి 'v':
                type.t |= VT_VOID;
                mk_సూచిక (&type);
                ఆపు;
	    స్థితి 'S':
                type.t = VT_CONSTANT;
	    స్థితి 's':
                type.t |= char_type.t;
                mk_సూచిక (&type);
                ఆపు;
	    స్థితి 'i':
                type.t = VT_INT;
                ఆపు;
	    స్థితి 'l':
                type.t = VT_కొలత_T;
                ఆపు;
	    అప్రమేయ:
                ఆపు;
	}
        gen_కేటాయించు_cast(&type);
    }
    skip(')');
    ఒకవేళ (nc)
        nocode_wanted--;
}

స్థిర శూన్య parse_atomic(పూర్ణాంకం atok)
{
    పూర్ణాంకం కొలత, align, arg, t, save = 0;
    CType *atom, *atom_ptr, ct = {0};
    SValue store;
    అక్షరం buf[40];
    స్థిర స్థిరరాశి అక్షరం *స్థిరరాశి templates[] = {
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
    స్థిరరాశి అక్షరం *మూస = templates[(atok - TOK___atomic_store)];

    atom = atom_ptr = ఖాళీ;
    కొలత = 0; /* pacify compiler */
    తదుపరి();
    skip('(');
    కొరకు (arg = 0;;) {
        సమాసం_eq();
        ఎంపిక (మూస[arg]) {
        స్థితి 'a':
        స్థితి 'A':
            atom_ptr = &vtop->type;
            ఒకవేళ ((atom_ptr->t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            atom = pointed_type(atom_ptr);
            కొలత = type_కొలత(atom, &align);
            ఒకవేళ (కొలత > 8
                || (కొలత & (కొలత - 1))
                || (atok > TOK___atomic_compare_exchange
                    && (0 == btype_కొలత(atom->t & VT_BTYPE)
                        || (atom->t & VT_BTYPE) == VT_PTR)))
                expect("integral or integer-sized pointer target type");
            /* GCC does not care either: */
            /* if (!(atom->t & VT_ATOMIC))
                tcc_warning("pointer target declaration is missing '_Atomic'"); */
            ఆపు;

        స్థితి 'p':
            ఒకవేళ ((vtop->type.t & VT_BTYPE) != VT_PTR
             || type_కొలత(pointed_type(&vtop->type), &align) != కొలత)
                tcc_error("pointer target type mismatch in argument %d", arg + 1);
            gen_కేటాయించు_cast(atom_ptr);
            ఆపు;
        స్థితి 'v':
            gen_కేటాయించు_cast(atom);
            ఆపు;
        స్థితి 'l':
            indir();
            gen_కేటాయించు_cast(atom);
            ఆపు;
        స్థితి 's':
            save = 1;
            indir();
            store = *vtop;
            vpop();
            ఆపు;
        స్థితి 'm':
            gen_కేటాయించు_cast(&int_type);
            ఆపు;
        స్థితి 'b':
            ct.t = VT_BOOL;
            gen_కేటాయించు_cast(&ct);
            ఆపు;
        }
        ఒకవేళ ('.' == మూస[++arg])
            ఆపు;
        skip(',');
    }
    skip(')');

    ct.t = VT_VOID;
    ఎంపిక (మూస[arg + 1]) {
    స్థితి 'b':
        ct.t = VT_BOOL;
        ఆపు;
    స్థితి 'v':
        ct = *atom;
        ఆపు;
    }

    sprintf(buf, "%s_%d", get_tok_str(atok, 0), కొలత);
    vpush_helper_func(tok_alloc_const(buf));
    vrott(arg - save + 1);
    gfunc_call(arg - save);

    vpush(&ct);
    PUT_R_RET(vtop, ct.t);
    t = ct.t & VT_BTYPE;
    ఒకవేళ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#నిర్వచితమైతే PROMOTE_RET
        vtop->r |= BFVAL(VT_MUSTCAST, 1);
#లేకపోతే
        vtop->type.t = VT_INT;
#అయితే_ముగింపు
    }
    gen_cast(&ct);
    ఒకవేళ (save) {
        vpush(&ct);
        *vtop = store;
        vswap();
        vstore();
    }
}

ST_FUNC శూన్య unary(శూన్య)
{
    పూర్ణాంకం n, t, align, కొలత, r;
    CType type;
    Sym *s;
    AttributeDef ad;

    /* generate line number info */
    ఒకవేళ (debug_modes)
        tcc_debug_పంక్తి(tcc_state), tcc_tcov_check_పంక్తి (tcc_state, 1);

    type.ref = ఖాళీ;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_తదుపరి:
    ఎంపిక(tok) {
    స్థితి TOK_EXTENSION:
        తదుపరి();
        వెళ్ళు tok_తదుపరి;
    స్థితి TOK_LCHAR:
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        t = VT_SHORT|VT_UNSIGNED;
        వెళ్ళు నెట్టు_tokc;
#అయితే_ముగింపు
    స్థితి TOK_CINT:
    స్థితి TOK_CCHAR: 
	t = VT_INT;
 నెట్టు_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        తదుపరి();
        ఆపు;
    స్థితి TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CLLONG:
        t = VT_LLONG;
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CFLOAT:
        t = VT_FLOAT;
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CDOUBLE:
        t = VT_DOUBLE;
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CLDOUBLE:
#నిర్వచితమైతే TCC_USING_DOUBLE_FOR_LDOUBLE
        t = VT_DOUBLE | VT_LONG;
        tokc.d = tokc.ld;
#లేకపోతే
        t = VT_LDOUBLE;
#అయితే_ముగింపు
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CLONG:
        t = (LONG_కొలత == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK_CULONG:
        t = (LONG_కొలత == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	వెళ్ళు నెట్టు_tokc;
    స్థితి TOK___FUNCTION__:
        ఒకవేళ (!gnu_ext)
            వెళ్ళు tok_identifier;
        /* fall thru */
    స్థితి TOK___FUNC__:
        tok = TOK_STR;
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, funcname, 0);
        tokc.str.కొలత = tokcstr.కొలత;
        tokc.str.దత్తాంశం = tokcstr.దత్తాంశం;
        వెళ్ళు case_TOK_STR;
    స్థితి TOK_LSTR:
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        t = VT_SHORT | VT_UNSIGNED;
#లేకపోతే
        t = VT_INT;
#అయితే_ముగింపు
        వెళ్ళు str_init;
    స్థితి TOK_STR:
    case_TOK_STR:
        /* string parsing */
        t = char_type.t;
    str_init:
        ఒకవేళ (tcc_state->warn_write_అక్షరశ్రేణులు & WARN_ON)
            t |= VT_CONSTANT;
        type.t = t;
        mk_సూచిక(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, పరిమాణం(AttributeDef));
        ad.section = rodata_section;
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        ఆపు;
    స్థితి TOK_SOTYPE:
    స్థితి '(':
        t = tok;
        తదుపరి();
        /* cast ? */
        ఒకవేళ (parse_btype(&type, &ad, 0)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            ఒకవేళ (tok == '{') {
                    /* data is allocated locally by default */
                ఒకవేళ (global_సమాసం)
                    r = VT_CONST;
                లేకపోతే
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                ఒకవేళ (!(type.t & VT_ARRAY))
                    r |= VT_LVAL;
                memset(&ad, 0, పరిమాణం(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } లేకపోతే ఒకవేళ (t == TOK_SOTYPE) { /* from sizeof/alignof (...) */
                vpush(&type);
                తిరిగి;
            } లేకపోతే {
                unary();
                gen_cast(&type);
            }
        } లేకపోతే ఒకవేళ (tok == '{') {
	    పూర్ణాంకం saved_nocode_wanted = nocode_wanted;
            ఒకవేళ (CONST_WANTED && !NOEVAL_WANTED)
                expect("constant");
            ఒకవేళ (0 == local_scope)
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
            ఖండం(STMT_సమాసం);
            /* If the statement expr can be entered, then we retain the current
               nocode_wanted state (from e.g. a 'return 0;' in the stmt-expr).
               If it can't be entered then the state is that from before the
               statement expression.  */
            ఒకవేళ (saved_nocode_wanted)
              nocode_wanted = saved_nocode_wanted;
            skip(')');
        } లేకపోతే {
            gexpr();
            skip(')');
        }
        ఆపు;
    స్థితి '*':
        తదుపరి();
        unary();
        indir();
        ఆపు;
    స్థితి '&':
        తదుపరి();
        unary();
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        ఒకవేళ ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & (VT_ARRAY | VT_VLA)))
            test_lvalue();
        ఒకవేళ (vtop->sym)
          vtop->sym->a.addrtaken = 1;
        mk_సూచిక(&vtop->type);
        gaddrof();
        ఆపు;
    స్థితి '!':
        తదుపరి();
        unary();
        gen_test_zero(TOK_EQ);
        ఆపు;
    స్థితి '~':
        తదుపరి();
        unary();
        vpushi(-1);
        gen_op('^');
        ఆపు;
    స్థితి '+':
        తదుపరి();
        unary();
        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	ఒకవేళ (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        ఆపు;
    స్థితి TOK_SIZEOF:
    స్థితి TOK_ALIGNOF1:
    స్థితి TOK_ALIGNOF2:
    స్థితి TOK_ALIGNOF3:
        t = tok;
        తదుపరి();
        ఒకవేళ (tok == '(')
            tok = TOK_SOTYPE;
        సమాసం_type(&type, unary);
        ఒకవేళ (t == TOK_SIZEOF) {
            vpush_type_కొలత(&type, &align);
            gen_cast_s(VT_కొలత_T);
        } లేకపోతే {
            type_కొలత(&type, &align);
            s = ఖాళీ;
            ఒకవేళ (vtop[1].r & VT_SYM)
                s = vtop[1].sym; /* hack: accessing previous vtop */
            ఒకవేళ (s && s->a.aligned)
                align = 1 << (s->a.aligned - 1);
            vpushs(align);
        }
        ఆపు;

    స్థితి TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        ఆపు;
    స్థితి TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	n = compare_types(&vtop[-1].type, &vtop[0].type, 1);
	vtop -= 2;
	vpushi(n);
        ఆపు;
    స్థితి TOK_builtin_ఎంచుకో_సమాసం:
	{
	    int64_t c;
	    తదుపరి();
	    skip('(');
	    c = సమాసం_const64();
	    skip(',');
	    ఒకవేళ (!c) {
		nocode_wanted++;
	    }
	    సమాసం_eq();
	    ఒకవేళ (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    ఒకవేళ (c) {
		nocode_wanted++;
	    }
	    సమాసం_eq();
	    ఒకవేళ (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        ఆపు;
    స్థితి TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = 1;
	ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
	    || ((vtop->r & VT_SYM) && vtop->sym->a.addrtaken)
	    )
	    n = 0;
	vtop--;
	vpushi(n);
        ఆపు;
    స్థితి TOK_builtin_unreachable:
	parse_builtin_params(0, ""); /* just skip '()' */
        type.t = VT_VOID;
        vpush(&type);
        సంకేతం_OFF();
        ఆపు;
    స్థితి TOK_builtin_చట్రం_చిరునామా:
    స్థితి TOK_builtin_return_చిరునామా:
        {
            పూర్ణాంకం tok1 = tok;
            పూర్ణాంకం level;
            తదుపరి();
            skip('(');
            level = సమాసం_const();
            ఒకవేళ (level < 0)
                tcc_error("%s only takes positive integers", get_tok_str(tok1, 0));
            skip(')');
            type.t = VT_VOID;
            mk_సూచిక(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            అయితే (level--) {
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
                vpushi(2*PTR_కొలత);
                gen_op('-');
#అయితే_ముగింపు
                mk_సూచిక(&vtop->type);
                indir();                    /* -> parent frame */
            }
            ఒకవేళ (tok1 == TOK_builtin_return_చిరునామా) {
                // assume return address is just above frame pointer on stack
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
                vpushi(2*PTR_కొలత);
                gen_op('+');
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
                vpushi(PTR_కొలత);
                gen_op('-');
#లేకపోతే
                vpushi(PTR_కొలత);
                gen_op('+');
#అయితే_ముగింపు
                mk_సూచిక(&vtop->type);
                indir();
            }
        }
        ఆపు;
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    స్థితి TOK_builtin_va_ప్రారంభం:
        parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ఒకవేళ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ఒకవేళ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        gen_va_ప్రారంభం();
	vstore();
        ఆపు;
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    స్థితి TOK_builtin_va_ప్రారంభం:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        ఒకవేళ (r == VT_LLOCAL)
            r = VT_LOCAL;
        ఒకవేళ (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_సూచిక_type;
	vtop->c.i += 8;
	vstore();
        ఆపు;
#లేకపోతే
    స్థితి TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
	ఆపు;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_ARM64
    స్థితి TOK_builtin_va_ప్రారంభం: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_ప్రారంభం();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ఆపు;
    }
    స్థితి TOK_builtin_va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        ఆపు;
    }
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_ARM64
    స్థితి TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ఆపు;
    }
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    స్థితి TOK___riscv64_clear_cache: {
	parse_builtin_params(0, "ee");
	vpop();
	vpop();
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        ఆపు;
    }
#అయితే_ముగింపు

    /* atomic operations */
    స్థితి TOK___atomic_store:
    స్థితి TOK_atomic_ఎక్కించు:
    స్థితి TOK___atomic_exchange:
    స్థితి TOK___atomic_compare_exchange:
    స్థితి TOK_atomic_fetch_కూడు:
    స్థితి TOK___atomic_fetch_sub:
    స్థితి TOK___atomic_fetch_or:
    స్థితి TOK___atomic_fetch_xor:
    స్థితి TOK___atomic_fetch_and:
    స్థితి TOK___atomic_fetch_nand:
    స్థితి TOK_atomic_కూడు_fetch:
    స్థితి TOK___atomic_sub_fetch:
    స్థితి TOK___atomic_or_fetch:
    స్థితి TOK___atomic_xor_fetch:
    స్థితి TOK___atomic_and_fetch:
    స్థితి TOK___atomic_nand_fetch:
        parse_atomic(tok);
        ఆపు;

    /* pre operations */
    స్థితి TOK_INC:
    స్థితి TOK_DEC:
        t = tok;
        తదుపరి();
        unary();
        inc(0, t);
        ఆపు;
    స్థితి '-':
        తదుపరి();
        unary();
	ఒకవేళ (is_float(vtop->type.t)) {
            gen_opif(TOK_NEG);
	} లేకపోతే {
            vpushi(0);
            vswap();
            gen_op('-');
        }
        ఆపు;
    స్థితి TOK_LAND:
        ఒకవేళ (!gnu_ext)
            వెళ్ళు tok_identifier;
        తదుపరి();
        /* allow to take the address of a label */
        ఒకవేళ (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_కనుగొను(tok);
        ఒకవేళ (!s) {
            s = label_నెట్టు(&global_label_దొంతర, tok, LABEL_FORWARD);
        } లేకపోతే {
            ఒకవేళ (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        ఒకవేళ ((s->type.t & VT_BTYPE) != VT_PTR) {
            s->type.t = VT_VOID;
            mk_సూచిక(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        తదుపరి();
        ఆపు;

    స్థితి TOK_GENERIC:
    {
	CType controlling_type;
	పూర్ణాంకం has_default = 0;
	పూర్ణాంకం has_సరిపోలిక = 0;
	పూర్ణాంకం learn = 0;
	TokenString *str = ఖాళీ;
	పూర్ణాంకం saved_nocode_wanted = nocode_wanted;
        nocode_wanted &= ~CONST_WANTED_ముసుగు;

        తదుపరి();
	skip('(');
	సమాసం_type(&controlling_type, సమాసం_eq);
	convert_వ్యక్తీకరణ_type(&controlling_type);

        nocode_wanted = saved_nocode_wanted;

        కొరకు (;;) {
	    learn = 0;
	    skip(',');
	    ఒకవేళ (tok == TOK_DEFAULT) {
		ఒకవేళ (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		ఒకవేళ (!has_సరిపోలిక)
		    learn = 1;
		తదుపరి();
	    } లేకపోతే {
		పూర్ణాంకం v;
		parse_btype(&type, &ad, 0);
		type_decl(&type, &ad, &v, TYPE_ABSTRACT);
		ఒకవేళ (compare_types(&controlling_type, &type, 0)) {
		    ఒకవేళ (has_సరిపోలిక) {
		      tcc_error("type match twice");
		    }
		    has_సరిపోలిక = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    ఒకవేళ (learn) {
		ఒకవేళ (str)
		    tok_str_free(str);
		skip_or_save_ఖండం(&str);
	    } లేకపోతే {
		skip_or_save_ఖండం(ఖాళీ);
	    }
	    ఒకవేళ (tok == ')')
		ఆపు;
	}
	ఒకవేళ (!str) {
	    అక్షరం buf[60];
	    type_గమ్యం_str(buf, పరిమాణం buf, &controlling_type, ఖాళీ);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	తదుపరి();
	సమాసం_eq();
	ఒకవేళ (tok != TOK_EOF)
	    expect(",");
	చివర_macro();
        తదుపరి();
	ఆపు;
    }
    // special qnan , snan and infinity values
    స్థితి TOK___NAN__:
        n = 0x7fc00000;
special_math_val:
	vpushi(n);
	vtop->type.t = VT_FLOAT;
        తదుపరి();
        ఆపు;
    స్థితి TOK___SNAN__:
	n = 0x7f800001;
	వెళ్ళు special_math_val;
    స్థితి TOK___INF__:
	n = 0x7f800000;
	వెళ్ళు special_math_val;

    అప్రమేయ:
    tok_identifier:
        ఒకవేళ (tok < TOK_UIDENT)
            tcc_error("expression expected before '%s'", get_tok_str(tok, &tokc));
        t = tok;
        తదుపరి();
        s = sym_కనుగొను(t);
        ఒకవేళ (!s || IS_ASM_SYM(s)) {
            స్థిరరాశి అక్షరం *name = get_tok_str(t, ఖాళీ);
            ఒకవేళ (tok != '(')
                tcc_error("'%s' undeclared", name);
            /* for simple function calls, we tolerate undeclared
               external reference to int() function */
            ఒకవేళ (!func_old)
            tcc_warning_c(warn_implicit_function_declaration)(
                "implicit declaration of function '%s'", name);
            s = external_global_sym(t, &func_old_type);
        }

        r = s->r;
        /* A symbol that has a register is a local register variable,
           which starts out as VT_LOCAL value.  */
        ఒకవేళ ((r & VT_VALMASK) < VT_CONST)
            r = (r & ~VT_VALMASK) | VT_LOCAL;

        vset(&s->type, r, s->c);
        /* Point to s as backpointer (even without r&VT_SYM).
	   Will be used by at least the x86 inline asm parser for
	   regvars.  */
	vtop->sym = s;

        ఒకవేళ (r & VT_SYM) {
            vtop->c.i = 0;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            ఒకవేళ (s->a.dllimport) {
                mk_సూచిక(&vtop->type);
                vtop->r |= VT_LVAL;
                indir();
            }
#అయితే_ముగింపు
        } లేకపోతే ఒకవేళ (r == VT_CONST && IS_ENUM_VAL(s->type.t)) {
            vtop->c.i = s->enum_val;
        }
        ఆపు;
    }
    
    /* post operations */
    అయితే (1) {
        ఒకవేళ (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            తదుపరి();
        } లేకపోతే ఒకవేళ (tok == '.' || tok == TOK_ARROW) {
            పూర్ణాంకం qualifiers, cumofs;
            /*క్షేత్రం*/ 
            ఒకవేళ (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & VT_QUAL;
            test_lvalue();
            /* expect pointer on structure */
            తదుపరి();
	    s = కనుగొను_క్షేత్రం(&vtop->type, tok, &cumofs);
            /* add field offset to pointer */
            gaddrof();
            vtop->type = char_సూచిక_type; /* change type to 'char *' */
            vpushi(cumofs);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            ఒకవేళ (qualifiers)
                parse_btype_qualify(&vtop->type, qualifiers);
            /* an array is never an lvalue */
            ఒకవేళ (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= VT_LVAL;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                ఒకవేళ (tcc_state->do_bounds_check)
                    vtop->r |= VT_MUSTBOUND;
#అయితే_ముగింపు
            }
            తదుపరి();
        } లేకపోతే ఒకవేళ (tok == '[') {
            తదుపరి();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } లేకపోతే ఒకవేళ (tok == '(') {
            SValue ret;
            Sym *sa;
            పూర్ణాంకం nb_వాదనలు, ret_nregs, ret_align, regsize, variadic;
            TokenString *p, *p2;

            /* function call  */
            ఒకవేళ ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                ఒకవేళ ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    ఒకవేళ ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        వెళ్ళు error_func;
                } లేకపోతే {
                error_func:
                    expect("function pointer");
                }
            } లేకపోతే {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            తదుపరి();
            sa = s->తదుపరి; /* first parameter */
            nb_వాదనలు = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            ఒకవేళ ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                ఒకవేళ (ret_nregs <= 0) {
                    /* get some space for the returned structure */
                    కొలత = type_కొలత(&s->type, &align);
#నిర్వచితమైతే TCC_లక్ష్యం_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                ఒకవేళ (కొలత < 16)
                    అయితే (కొలత & (కొలత - 1))
                        కొలత = (కొలత | (కొలత - 1)) + 1;
#అయితే_ముగింపు
                    loc = (loc - కొలత) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
#నిర్వచితమైతే CONFIG_TCC_BCHECK
                    ఒకవేళ (tcc_state->do_bounds_check)
                        --loc;
#అయితే_ముగింపు
                    ret.c = vtop->c;
                    ఒకవేళ (ret_nregs < 0)
                      vtop--;
                    లేకపోతే
                      nb_వాదనలు++;
                }
            } లేకపోతే {
                ret_nregs = 1;
                ret.type = s->type;
            }

            ఒకవేళ (ret_nregs > 0) {
                /* return in register */
                ret.c.i = 0;
                PUT_R_RET(&ret, ret.type.t);
            }

            p = ఖాళీ;
            ఒకవేళ (tok != ')') {
                r = tcc_state->తిరగేయి_funcargs;
                కొరకు(;;) {
                    ఒకవేళ (r) {
                        skip_or_save_ఖండం(&p2);
                        p2->prev = p, p = p2;
                    } లేకపోతే {
                        సమాసం_eq();
                        gfunc_param_typed(s, sa);
                    }
                    nb_వాదనలు++;
                    ఒకవేళ (sa)
                        sa = sa->తదుపరి;
                    ఒకవేళ (tok == ')')
                        ఆపు;
                    skip(',');
                }
            }
            ఒకవేళ (sa)
                tcc_error("too few arguments to function");

            ఒకవేళ (p) { /* with reverse_funcargs */
                కొరకు (n = 0; p; p = p2, ++n) {
                    p2 = p, sa = s;
                    చేయి {
                        sa = sa->తదుపరి, p2 = p2->prev;
                    } అయితే (p2 && sa);
                    p2 = p->prev;
                    begin_macro(p, 1), తదుపరి();
                    సమాసం_eq();
                    gfunc_param_typed(s, sa);
                    చివర_macro();
                }
                vrev(n);
            }

            తదుపరి();
            vcheck_cmp(); /* the generators don't like VT_CMP on vtop */
            gfunc_call(nb_వాదనలు);

            ఒకవేళ (ret_nregs < 0) {
                vsetc(&ret.type, ret.r, &ret.c);
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
                arch_transfer_ret_regs(1);
#అయితే_ముగింపు
            } లేకపోతే {
                /* return value */
                n = ret_nregs;
                అయితే (n > 1) {
                    పూర్ణాంకం rc = reg_classes[ret.r] & ~(RC_INT | RC_FLOAT);
                    /* We assume that when a structure is returned in multiple
                       registers, their classes are consecutive values of the
                       suite s(n) = 2^n */
                    rc <<= --n;
                    కొరకు (r = 0; r < NB_REGS; ++r)
                        ఒకవేళ (reg_classes[r] & rc)
                            ఆపు;
                    vsetc(&ret.type, r, &ret.c);
                }
                vsetc(&ret.type, ret.r, &ret.c);
                vtop->r2 = ret.r2;

                /* handle packed struct return */
                ఒకవేళ (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                    పూర్ణాంకం addr, స్థానభ్రంశం;

                    కొలత = type_కొలత(&s->type, &align);
                    /* We're writing whole regs often, make sure there's enough
                       space.  Assume register size is power of 2.  */
                    కొలత = (కొలత + regsize - 1) & -regsize;
                    ఒకవేళ (ret_align > align)
                        align = ret_align;
                    loc = (loc - కొలత) & -align;
                    addr = loc;
                    స్థానభ్రంశం = 0;
                    కొరకు (;;) {
                        vset(&ret.type, VT_LOCAL | VT_LVAL, addr + స్థానభ్రంశం);
                        vswap();
                        vstore();
                        vtop--;
                        ఒకవేళ (--ret_nregs == 0)
                          ఆపు;
                        స్థానభ్రంశం += regsize;
                    }
                    vset(&s->type, VT_LOCAL | VT_LVAL, addr);
                }

                /* Promote char/short return values. This is matters only
                   for calling function that were not compiled by TCC and
                   only on some architectures.  For those where it doesn't
                   matter we expect things to be already promoted to int,
                   but not larger.  */
                t = s->type.t & VT_BTYPE;
                ఒకవేళ (t == VT_BYTE || t == VT_SHORT || t == VT_BOOL) {
#నిర్వచితమైతే PROMOTE_RET
                    vtop->r |= BFVAL(VT_MUSTCAST, 1);
#లేకపోతే
                    vtop->type.t = VT_INT;
#అయితే_ముగింపు
                }
            }
            ఒకవేళ (s->f.func_noreturn) {
                ఒకవేళ (debug_modes)
	            tcc_tcov_ఖండం_చివర(tcc_state, -1);
                సంకేతం_OFF();
	    }
        } లేకపోతే {
            ఆపు;
        }
    }
}

#నిర్వచితం_కాకపోతే precedence_parser /* original top-down parser */

స్థిర శూన్య సమాసం_prod(శూన్య)
{
    పూర్ణాంకం t;

    unary();
    అయితే ((t = tok) == '*' || t == '/' || t == '%') {
        తదుపరి();
        unary();
        gen_op(t);
    }
}

స్థిర శూన్య సమాసం_కూడిక(శూన్య)
{
    పూర్ణాంకం t;

    సమాసం_prod();
    అయితే ((t = tok) == '+' || t == '-') {
        తదుపరి();
        సమాసం_prod();
        gen_op(t);
    }
}

స్థిర శూన్య సమాసం_జరుపు(శూన్య)
{
    పూర్ణాంకం t;

    సమాసం_కూడిక();
    అయితే ((t = tok) == TOK_SHL || t == TOK_SAR) {
        తదుపరి();
        సమాసం_కూడిక();
        gen_op(t);
    }
}

స్థిర శూన్య సమాసం_cmp(శూన్య)
{
    పూర్ణాంకం t;

    సమాసం_జరుపు();
    అయితే (((t = tok) >= TOK_ULE && t <= TOK_GT) ||
           t == TOK_ULT || t == TOK_UGE) {
        తదుపరి();
        సమాసం_జరుపు();
        gen_op(t);
    }
}

స్థిర శూన్య సమాసం_cmpeq(శూన్య)
{
    పూర్ణాంకం t;

    సమాసం_cmp();
    అయితే ((t = tok) == TOK_EQ || t == TOK_NE) {
        తదుపరి();
        సమాసం_cmp();
        gen_op(t);
    }
}

స్థిర శూన్య సమాసం_and(శూన్య)
{
    సమాసం_cmpeq();
    అయితే (tok == '&') {
        తదుపరి();
        సమాసం_cmpeq();
        gen_op('&');
    }
}

స్థిర శూన్య సమాసం_xor(శూన్య)
{
    సమాసం_and();
    అయితే (tok == '^') {
        తదుపరి();
        సమాసం_and();
        gen_op('^');
    }
}

స్థిర శూన్య సమాసం_or(శూన్య)
{
    సమాసం_xor();
    అయితే (tok == '|') {
        తదుపరి();
        సమాసం_xor();
        gen_op('|');
    }
}

స్థిర శూన్య సమాసం_landor(పూర్ణాంకం op);

స్థిర శూన్య సమాసం_land(శూన్య)
{
    సమాసం_or();
    ఒకవేళ (tok == TOK_LAND)
        సమాసం_landor(tok);
}

స్థిర శూన్య సమాసం_lor(శూన్య)
{
    సమాసం_land();
    ఒకవేళ (tok == TOK_LOR)
        సమాసం_landor(tok);
}

# define సమాసం_landor_తదుపరి(op) op == TOK_LAND ? సమాసం_or() : సమాసం_land()
#లేకపోతే /* defined precedence_parser */
# define సమాసం_landor_తదుపరి(op) unary(), సమాసం_infix(precedence(op) + 1)
# define సమాసం_lor() unary(), సమాసం_infix(1)

స్థిర పూర్ణాంకం precedence(పూర్ణాంకం tok)
{
    ఎంపిక (tok) {
        స్థితి TOK_LOR: తిరిగి 1;
        స్థితి TOK_LAND: తిరిగి 2;
	స్థితి '|': తిరిగి 3;
	స్థితి '^': తిరిగి 4;
	స్థితి '&': తిరిగి 5;
	స్థితి TOK_EQ: స్థితి TOK_NE: తిరిగి 6;
 relat: స్థితి TOK_ULT: స్థితి TOK_UGE: తిరిగి 7;
	స్థితి TOK_SHL: స్థితి TOK_SAR: తిరిగి 8;
	స్థితి '+': స్థితి '-': తిరిగి 9;
	స్థితి '*': స్థితి '/': స్థితి '%': తిరిగి 10;
	అప్రమేయ:
	    ఒకవేళ (tok >= TOK_ULE && tok <= TOK_GT)
	        వెళ్ళు relat;
	    తిరిగి 0;
    }
}
స్థిర గుర్తులేని అక్షరం prec[256];
స్థిర శూన్య init_prec(శూన్య)
{
    పూర్ణాంకం i;
    కొరకు (i = 0; i < 256; i++)
	prec[i] = precedence(i);
}
#నిర్వచించు precedence(i) ((గుర్తులేని)i < 256 ? prec[i] : 0)

స్థిర శూన్య సమాసం_landor(పూర్ణాంకం op);

స్థిర శూన్య సమాసం_infix(పూర్ణాంకం p)
{
    పూర్ణాంకం t = tok, p2;
    అయితే ((p2 = precedence(t)) >= p) {
        ఒకవేళ (t == TOK_LOR || t == TOK_LAND) {
            సమాసం_landor(t);
        } లేకపోతే {
            తదుపరి();
            unary();
            ఒకవేళ (precedence(tok) > p2)
              సమాసం_infix(p2 + 1);
            gen_op(t);
        }
        t = tok;
    }
}
#అయితే_ముగింపు

/* Assuming vtop is a value used in a conditional context
   (i.e. compared with zero) return 0 if it's false, 1 if
   true and -1 if it can't be statically determined.  */
స్థిర పూర్ణాంకం condition_3way(శూన్య)
{
    పూర్ణాంకం c = -1;
    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL)) == VT_CONST &&
	(!(vtop->r & VT_SYM) || !vtop->sym->a.weak)) {
	vdup();
        gen_cast_s(VT_BOOL);
	c = vtop->c.i;
	vpop();
    }
    తిరిగి c;
}

స్థిర శూన్య సమాసం_landor(పూర్ణాంకం op)
{
    పూర్ణాంకం t = 0, cc = 1, f = 0, i = op == TOK_LAND, c;
    కొరకు(;;) {
        c = f ? i : condition_3way();
        ఒకవేళ (c < 0)
            save_regs(1), cc = 0;
        లేకపోతే ఒకవేళ (c != i)
            nocode_wanted++, f = 1;
        ఒకవేళ (tok != op)
            ఆపు;
        ఒకవేళ (c < 0)
            t = gvtst(i, t);
        లేకపోతే
            vpop();
        తదుపరి();
        సమాసం_landor_తదుపరి(op);
    }
    ఒకవేళ (cc || f) {
        vpop();
        vpushi(i ^ f);
        gsym(t);
        nocode_wanted -= f;
    } లేకపోతే {
        gvtst_సమితి(i, t);
    }
}

స్థిర పూర్ణాంకం is_cond_bool(SValue *sv)
{
    ఒకవేళ ((sv->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
        && (sv->type.t & VT_BTYPE) == VT_INT)
        తిరిగి (గుర్తులేని)sv->c.i < 2;
    ఒకవేళ (sv->r == VT_CMP)
        తిరిగి 1;
    తిరిగి 0;
}

స్థిర శూన్య సమాసం_cond(శూన్య)
{
    పూర్ణాంకం tt, u, r1, r2, rc, t1, t2, islv, c, g;
    SValue sv;
    CType type;

    సమాసం_lor();
    ఒకవేళ (tok == '?') {
        తదుపరి();
	c = condition_3way();
        g = (tok == ':' && gnu_ext);
        tt = 0;
        ఒకవేళ (!g) {
            ఒకవేళ (c < 0) {
                save_regs(1);
                tt = gvtst(1, 0);
            } లేకపోతే {
                vpop();
            }
        } లేకపోతే ఒకవేళ (c < 0) {
            /* needed to avoid having different registers saved in
               each branch */
            save_regs(1);
            gv_dup();
            tt = gvtst(0, 0);
        }

        ఒకవేళ (c == 0)
          nocode_wanted++;
        ఒకవేళ (!g)
          gexpr();

        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_సూచిక(&vtop->type);
        sv = *vtop; /* save value to handle it later */
        vtop--; /* no vpop so that FP stack is not flushed */

        ఒకవేళ (g) {
            u = tt;
        } లేకపోతే ఒకవేళ (c < 0) {
            u = gjmp(0);
            gsym(tt);
        } లేకపోతే
          u = 0;

        ఒకవేళ (c == 0)
          nocode_wanted--;
        ఒకవేళ (c == 1)
          nocode_wanted++;
        skip(':');
        సమాసం_cond();

        ఒకవేళ ((vtop->type.t & VT_BTYPE) == VT_FUNC)
          mk_సూచిక(&vtop->type);

        /* cast operands to correct type according to ISOC rules */
        ఒకవేళ (!combine_types(&type, &sv, vtop, '?'))
          type_incompatibility_error(&sv.type, &vtop->type,
            "type mismatch in conditional expression (have '%s' and '%s')");

        ఒకవేళ (c < 0 && is_cond_bool(vtop) && is_cond_bool(&sv)) {
            /* optimize "if (f ? a > b : c || d) ..." for example, where normally
               "a < b" and "c || d" would be forced to "(int)0/1" first, whereas
               this code jumps directly to the if's then/else branches. */
            t1 = gvtst(0, 0);
            t2 = gjmp(0);
            gsym(u);
            vpushv(&sv);
            /* combine jump targets of 2nd op with VT_CMP of 1st op */
            gvtst_సమితి(0, t1);
            gvtst_సమితి(1, t2);
            gen_cast(&type);
            //  tcc_warning("two conditions expr_cond");
            తిరిగి;
        }

        /* keep structs lvalue by transforming `(expr ? a : b)` to `*(expr ? &a : &b)` so
           that `(expr ? a : b).mem` does not error  with "lvalue expected" */
        islv = VT_STRUCT == (type.t & VT_BTYPE);

        /* now we convert second operand */
        ఒకవేళ (c != 1) {
            gen_cast(&type);
            ఒకవేళ (islv) {
                mk_సూచిక(&vtop->type);
                gaddrof();
            }
        }

        rc = RC_TYPE(type.t);
        /* for long longs, we use fixed registers to avoid having
           to handle a complicated move */
        ఒకవేళ (USING_TWO_పదాలు(type.t))
          rc = RC_RET(type.t);

        tt = r2 = 0;
        ఒకవేళ (c < 0) {
            ఒకవేళ (type.t != VT_VOID)
                r2 = gv(rc);
            tt = gjmp(0);
        }
        gsym(u);
        ఒకవేళ (c == 1)
          nocode_wanted--;

        /* this is horrible, but we must also convert first
నిర్వాహ్యం*/
        ఒకవేళ (c != 0) {
            *vtop = sv;
            gen_cast(&type);
            ఒకవేళ (islv) {
                mk_సూచిక(&vtop->type);
                gaddrof();
            }
        }

        ఒకవేళ (c < 0) {
            ఒకవేళ (type.t != VT_VOID) {
                r1 = gv(rc);
                move_reg(r2, r1, islv ? VT_PTR : type.t);
                vtop->r = r2;
            }
            gsym(tt);
        }

        ఒకవేళ (islv)
          indir();
    }
}

స్థిర శూన్య సమాసం_eq(శూన్య)
{
    పూర్ణాంకం t;
    
    సమాసం_cond();
    ఒకవేళ ((t = tok) == '=' || TOK_కేటాయించు(t)) {
        test_lvalue();
        తదుపరి();
        ఒకవేళ (t == '=') {
            సమాసం_eq();
        } లేకపోతే {
            vdup();
            సమాసం_eq();
            gen_op(TOK_కేటాయించు_OP(t));
        }
        vstore();
    }
}

ST_FUNC శూన్య gexpr(శూన్య)
{
    సమాసం_eq();
    ఒకవేళ (tok == ',') {
        చేయి {
            vpop();
            తదుపరి();
            సమాసం_eq();
        } అయితే (tok == ',');

        /* convert array & function to pointer */
        convert_వ్యక్తీకరణ_type(&vtop->type);

        /* make builtin_constant_p((1,2)) return 0 (like on gcc) */
        ఒకవేళ ((vtop->r & VT_VALMASK) == VT_CONST && nocode_wanted && !CONST_WANTED)
            ఒకవేళ (vtop->type.t != VT_VOID && (vtop->type.t & VT_BTYPE) != VT_STRUCT)
                gv(RC_TYPE(vtop->type.t));
    }
}

/* parse a constant expression and return value in vtop.  */
స్థిర శూన్య సమాసం_const1(శూన్య)
{
    nocode_wanted += CONST_WANTED_బిట్టు;
    సమాసం_cond();
    nocode_wanted -= CONST_WANTED_బిట్టు;
}

/* parse an integer constant and return its value. */
స్థిర అంతఃవరుస int64_t సమాసం_const64(శూన్య)
{
    int64_t c;
    సమాసం_const1();
    ఒకవేళ ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM | VT_NONCONST)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    తిరిగి c;
}

/* parse an integer constant and return its value.
   Complain if it doesn't fit 32bit (signed or unsigned).  */
ST_FUNC పూర్ణాంకం సమాసం_const(శూన్య)
{
    పూర్ణాంకం c;
    int64_t wc = సమాసం_const64();
    c = wc;
    ఒకవేళ (c != wc && (గుర్తులేని)c != wc)
        tcc_error("constant exceeds 32 bit");
    తిరిగి c;
}

/* ------------------------------------------------------------------------- */
/* return from function */

#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_ARM64
స్థిర శూన్య gfunc_return(CType *func_type)
{
    ఒకవేళ ((func_type->t & VT_BTYPE) == VT_STRUCT) {
        CType type, ret_type;
        పూర్ణాంకం ret_align, ret_nregs, regsize;
        ret_nregs = gfunc_sret(func_type, func_var, &ret_type,
                               &ret_align, &regsize);
        ఒకవేళ (ret_nregs < 0) {
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
            arch_transfer_ret_regs(0);
#అయితే_ముగింపు
        } లేకపోతే ఒకవేళ (0 == ret_nregs) {
            /* if returning structure, must copy it to implicit
               first pointer arg location */
            type = *func_type;
            mk_సూచిక(&type);
            vset(&type, VT_LOCAL | VT_LVAL, func_vc);
            indir();
            vswap();
            /* copy structure value to pointer */
            vstore();
        } లేకపోతే {
            /* returning structure packed into registers */
            పూర్ణాంకం కొలత, addr, align, rc, n;
            కొలత = type_కొలత(func_type,&align);
            ఒకవేళ (ret_nregs * regsize > కొలత ||
		((align & (ret_align - 1))
                 && ((vtop->r & VT_VALMASK) < VT_CONST /* pointer to struct */
                     || (vtop->c.i & (ret_align - 1))
                     ))) {
		ఒకవేళ (ret_nregs * regsize > కొలత)
		    కొలత = ret_nregs * regsize;
		ఒకవేళ (ret_align > align)
		    align = ret_align;
                loc = (loc - కొలత) & -align;
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
            కొరకు (n = ret_nregs; --n > 0;) {
                vdup();
                gv(rc);
                vswap();
                incr_స్థానభ్రంశం(regsize);
                /* We assume that when a structure is returned in multiple
                   registers, their classes are consecutive values of the
                   suite s(n) = 2^n */
                rc <<= 1;
            }
            gv(rc);
            vtop -= ret_nregs - 1;
        }
    } లేకపోతే {
        gv(RC_RET(func_type->t));
    }
    vtop--; /* NOT vpop() because on x86 it would flush the fp stack */
}
#అయితే_ముగింపు

స్థిర శూన్య check_func_return(శూన్య)
{
    ఒకవేళ ((func_vt.t & VT_BTYPE) == VT_VOID)
        తిరిగి;
    ఒకవేళ ((!strcmp(funcname, "main") || func_old)
        && (func_vt.t & VT_BTYPE) == VT_INT) {
        /* main returns 0 by default */
        vpushi(0);
        gfunc_return(&func_vt);
    } లేకపోతే {
        tcc_warning("function might return no value: '%s'", funcname);
    }
}

/* ------------------------------------------------------------------------- */
/* switch/case */

స్థిర పూర్ణాంకం case_cmp(uint64_t a, uint64_t b)
{
    ఒకవేళ (cur_switch->sv.type.t & VT_UNSIGNED)
        తిరిగి a < b ? -1 : a > b;
    లేకపోతే
        తిరిగి (int64_t)a < (int64_t)b ? -1 : (int64_t)a > (int64_t)b;
}

స్థిర పూర్ణాంకం case_cmp_qs(స్థిరరాశి శూన్య *pa, స్థిరరాశి శూన్య *pb)
{
    తిరిగి case_cmp((*(నిర్మాణం case_t**)pa)->v1, (*(నిర్మాణం case_t**)pb)->v1);
}

స్థిర శూన్య case_క్రమీకరించు(నిర్మాణం switch_t *sw)
{
    నిర్మాణం case_t **p;
    ఒకవేళ (sw->n < 2)
        తిరిగి;
    qsort(sw->p, sw->n, పరిమాణం *sw->p, case_cmp_qs);
    p = sw->p;
    అయితే (p < sw->p + sw->n - 1) {
        ఒకవేళ (case_cmp(p[0]->v2, p[1]->v1) >= 0) {
            పూర్ణాంకం l1 = p[0]->పంక్తి, l2 = p[1]->పంక్తి;
            /* using special format "%i:..." to show specific line */
            tcc_error("%i:duplicate case value", l1 > l2 ? l1 : l2);
        } లేకపోతే ఒకవేళ (p[0]->v2 + 1 == p[1]->v1 && p[0]->ind == p[1]->ind) {
            /* treat "case 1: case 2: case 3:" like "case 1 ... 3: */
            p[1]->v1 = p[0]->v1;
            tcc_free(p[0]);
            memmove(p, p + 1, (--sw->n - (p - sw->p)) * పరిమాణం *p);
        } లేకపోతే
            ++p;
    }
}

స్థిర పూర్ణాంకం gcase(నిర్మాణం case_t **పునాది, పూర్ణాంకం len, పూర్ణాంకం dsym)
{
    నిర్మాణం case_t *p;
    పూర్ణాంకం t, l2, e;

    t = vtop->type.t & VT_BTYPE;
    ఒకవేళ (t != VT_LLONG)
        t = VT_INT;
    అయితే (len) {
        /* binary search while len > 8, else linear */
        l2 = len > 8 ? len/2 : 0;
        p = పునాది[l2];
        vdup(), vpush64(t, p->v2);
        ఒకవేళ (l2 == 0 && p->v1 == p->v2) {
            gen_op(TOK_EQ); /* jmp to case when equal */
            gsym_addr(gvtst(0, 0), p->ind);
        } లేకపోతే {
            /* case v1 ... v2 */
            gen_op(TOK_GT); /* jmp over when > V2 */
            ఒకవేళ (len == 1) /* last case test jumps to default when false */
                dsym = gvtst(0, dsym), e = 0;
            లేకపోతే
                e = gvtst(0, 0);
            vdup(), vpush64(t, p->v1);
            gen_op(TOK_GE); /* jmp to case when >= V1 */
            gsym_addr(gvtst(0, 0), p->ind);
            dsym = gcase(పునాది, l2, dsym);
            gsym(e);
        }
        ++l2, పునాది += l2, len -= l2;
    }
    /* jump automagically will suppress more jumps */
    తిరిగి gjmp(dsym);
}

స్థిర శూన్య చివర_switch(శూన్య)
{
    నిర్మాణం switch_t *sw = cur_switch;
    dynarray_reset(&sw->p, &sw->n);
    cur_switch = sw->prev;
    tcc_free(sw);
}

/* ------------------------------------------------------------------------- */
/* __attribute__((cleanup(fn))) */

/* protect symbol lvalues from further modification  */
స్థిర శూన్య save_lvalues(శూన్య)
{
    SValue *sv = vtop;
    అయితే (sv >= vstack) {
        ఒకవేళ (sv->sym && (sv->r & VT_LVAL)) {
            పూర్ణాంకం align, కొలత = type_కొలత(&sv->type, &align);
            పూర్ణాంకం r2, l = get_తాత్కాలిక_local_var(కొలత, align, &r2);
            vset(&sv->type, VT_LOCAL | VT_LVAL, l), vtop->r2 = r2;
            vpushv(sv), *sv = vtop[-1], vstore(), --vtop;
        }
        --sv;
    }
}

స్థిర శూన్య try_call_scope_cleanup(Sym *stop)
{
    Sym *cls = cur_scope->cl.s;
    కొరకు (; cls != stop; cls = cls->తదుపరి) {
	Sym *fs = cls->cleanup_func;
	Sym *vs = cls->cleanup_sym;
	save_lvalues();
	vpushsym(&fs->type, fs);
	vset(&vs->type, vs->r, vs->c);
	vtop->sym = vs;
        mk_సూచిక(&vtop->type);
	gaddrof();
	gfunc_call(1);
    }
}


స్థిర శూన్య try_call_cleanup_goto(Sym *cleanupstate)
{
    Sym *oc, *cc;
    పూర్ణాంకం ocd, ccd;

    ఒకవేళ (!cur_scope->cl.s)
	తిరిగి;

    /* search NCA of both cleanup chains given parents and initial depth */
    ocd = cleanupstate ? cleanupstate->v & ~SYM_క్షేత్రం : 0;
    కొరకు (ccd = cur_scope->cl.n, oc = cleanupstate; ocd > ccd; --ocd, oc = oc->తదుపరి)
      ;
    కొరకు (cc = cur_scope->cl.s; ccd > ocd; --ccd, cc = cc->తదుపరి)
      ;
    కొరకు (; cc != oc; cc = cc->తదుపరి, oc = oc->తదుపరి, --ccd)
      ;

    try_call_scope_cleanup(cc);
}

/* call 'func' for each __attribute__((cleanup(func))) */
స్థిర శూన్య ఖండం_cleanup(నిర్మాణం scope *o)
{
    పూర్ణాంకం jmp = 0;
    Sym *g, **pg;
    కొరకు (pg = &pending_gotos; (g = *pg) && g->c > o->cl.n;) {
        ఒకవేళ (g->cleanup_label->r & LABEL_FORWARD) {
            Sym *pcl = g->తదుపరి;
            ఒకవేళ (!jmp)
                jmp = gjmp(0);
            gsym(pcl->jnext);
            try_call_scope_cleanup(o->cl.s);
            pcl->jnext = gjmp(0);
            ఒకవేళ (!o->cl.n)
                వెళ్ళు remove_pending;
            g->c = o->cl.n;
            pg = &g->prev;
        } లేకపోతే {
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

స్థిర శూన్య vla_restore(పూర్ణాంకం loc)
{
    ఒకవేళ (loc)
        gen_vla_sp_restore(loc);
}

స్థిర శూన్య vla_leave(నిర్మాణం scope *o)
{
    నిర్మాణం scope *c = cur_scope, *v = ఖాళీ;
    కొరకు (; c != o && c; c = c->prev)
      ఒకవేళ (c->vla.అంకె)
        v = c;
    ఒకవేళ (v)
      vla_restore(v->vla.locorig);
}

/* ------------------------------------------------------------------------- */
/* local scopes */

స్థిర శూన్య new_scope(నిర్మాణం scope *o)
{
    /* copy and link previous scope */
    *o = *cur_scope;
    o->prev = cur_scope;
    cur_scope = o;
    cur_scope->vla.అంకె = 0;

    /* record local declaration stack position */
    o->lstk = local_దొంతర;
    o->llstk = local_label_దొంతర;
    ++local_scope;
}

స్థిర శూన్య prev_scope(నిర్మాణం scope *o, పూర్ణాంకం is_సమాసం)
{
    vla_leave(o->prev);

    ఒకవేళ (o->cl.s != o->prev->cl.s)
        ఖండం_cleanup(o->prev);

    ఒకవేళ (debug_modes)
        tcc_debug_చివర_scope(o->lstk, !is_సమాసం);

    /* pop locally defined labels */
    label_తీయి(&local_label_దొంతర, o->llstk, is_సమాసం);

    /* In the is_expr case (a statement expression is finished here),
       vtop might refer to symbols on the local_stack.  Either via the
       type or via vtop->sym.  We can't pop those nor any that in turn
       might be referred to.  To make it easier we don't roll back
       any symbols in that case; some upper level call to block() will
       do that.  We do have to remove such symbols from the lookup
       tables, though.  sym_pop will do that.  */

    /* pop locally defined symbols */
    sym_తీయి(&local_దొంతర, o->lstk, is_సమాసం);
    cur_scope = o->prev;
    --local_scope;
}

/* leave a scope via break/continue(/goto) */
స్థిర శూన్య leave_scope(నిర్మాణం scope *o)
{
    ఒకవేళ (!o)
        తిరిగి;
    try_call_scope_cleanup(o->cl.s);
    vla_leave(o);
}

/* short versiona for scopes with 'if/do/while/switch' which can
   declare only types (of struct/union/enum) */
స్థిర శూన్య new_scope_s(నిర్మాణం scope *o)
{
    o->lstk = local_దొంతర;
    ++local_scope;
}

స్థిర శూన్య prev_scope_s(నిర్మాణం scope *o)
{
    sym_తీయి(&local_దొంతర, o->lstk, 0);
    --local_scope;
}

/* ------------------------------------------------------------------------- */
/* call block from 'for do while' loops */

స్థిర శూన్య lblock(పూర్ణాంకం *bsym, పూర్ణాంకం *csym)
{
    నిర్మాణం scope *lo = loop_scope, *co = cur_scope;
    పూర్ణాంకం *b = co->bsym, *c = co->csym;
    ఒకవేళ (csym) {
        co->csym = csym;
        loop_scope = co;
    }
    co->bsym = bsym;
    ఖండం(0);
    co->bsym = b;
    ఒకవేళ (csym) {
        co->csym = c;
        loop_scope = lo;
    }
}

/* c2y if/switch declaration */
స్థిర శూన్య gexpr_decl(శూన్య)
{
    పూర్ణాంకం v = decl(VT_JMP);
    ఒకవేళ (v > 1 && tok != ';') {
        Sym *s = sym_కనుగొను(v);
        vset(&s->type, s->r, (s->r & VT_SYM) ? 0 : s->c);
        vtop->sym = s;
    } లేకపోతే {
        ఒకవేళ (v)
            skip(';');
        gexpr();
    }
}

స్థిర శూన్య ఖండం(పూర్ణాంకం flags)
{
    పూర్ణాంకం a, b, c, d, e, t;
    నిర్మాణం scope o;
    Sym *s;

again:
    t = tok;
    /* If the token carries a value, next() might destroy it. Only with
       invalid code such as f(){"123"4;} */
    ఒకవేళ (TOK_HAS_విలువ(t))
        వెళ్ళు సమాసం;
    తదుపరి();

    ఒకవేళ (debug_modes)
        tcc_tcov_check_పంక్తి (tcc_state, 0), tcc_tcov_ఖండం_begin (tcc_state);

    ఒకవేళ (t == TOK_IF) {
        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        a = gvtst(1, 0);
        skip(')');
        ఖండం(0);
        ఒకవేళ (tok == TOK_ELSE) {
            d = gjmp(0);
            gsym(a);
            తదుపరి();
            ఖండం(0);
            gsym(d); /* patch else jmp */
        } లేకపోతే {
            gsym(a);
        }
        prev_scope_s(&o);

    } లేకపోతే ఒకవేళ (t == TOK_WHILE) {
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

    } లేకపోతే ఒకవేళ (t == '{') {
        ఒకవేళ (debug_modes)
            tcc_debug_stabn(tcc_state, N_LBRAC, ind - func_ind);
        new_scope(&o);

        /* handle local labels declarations */
        అయితే (tok == TOK_LABEL) {
            చేయి {
                తదుపరి();
                ఒకవేళ (tok < TOK_UIDENT)
                    expect("label identifier");
                label_నెట్టు(&local_label_దొంతర, tok, LABEL_DECLARED);
                తదుపరి();
            } అయితే (tok == ',');
            skip(';');
        }

        అయితే (tok != '}') {
	    decl(VT_LOCAL);
            ఒకవేళ (tok != '}') {
                ఖండం(flags | STMT_COMPOUND);
            }
        }

        prev_scope(&o, flags & STMT_సమాసం);
        ఒకవేళ (debug_modes)
            tcc_debug_stabn(tcc_state, N_RBRAC, ind - func_ind);
        ఒకవేళ (local_scope)
            తదుపరి();
        లేకపోతే ఒకవేళ (!nocode_wanted)
            check_func_return();

    } లేకపోతే ఒకవేళ (t == TOK_RETURN) {
        b = (func_vt.t & VT_BTYPE) != VT_VOID;
        ఒకవేళ (tok != ';') {
            gexpr();
            ఒకవేళ (b) {
                gen_కేటాయించు_cast(&func_vt);
            } లేకపోతే {
                ఒకవేళ (vtop->type.t != VT_VOID)
                    tcc_warning("void function returns a value");
                vtop--;
            }
        } లేకపోతే ఒకవేళ (b && func_old && (func_vt.t & VT_BTYPE) == VT_INT) {
            vpushi(0);
        } లేకపోతే ఒకవేళ (b) {
            tcc_warning("'return' with no value");
            b = 0;
        }
        leave_scope(మూలం_scope);
        ఒకవేళ (b)
            gfunc_return(&func_vt);
        skip(';');
        /* jump unless last stmt in top-level block */
        ఒకవేళ (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
        ఒకవేళ (debug_modes)
	    tcc_tcov_ఖండం_చివర (tcc_state, -1);
        సంకేతం_OFF();

    } లేకపోతే ఒకవేళ (t == TOK_BREAK) {
        /* compute jump */
        ఒకవేళ (!cur_scope->bsym)
            tcc_error("cannot break");
        ఒకవేళ (cur_switch && cur_scope->bsym == cur_switch->bsym)
            leave_scope(cur_switch->scope);
        లేకపోతే
            leave_scope(loop_scope);
        *cur_scope->bsym = gjmp(*cur_scope->bsym);
        skip(';');

    } లేకపోతే ఒకవేళ (t == TOK_CONTINUE) {
        /* compute jump */
        ఒకవేళ (!cur_scope->csym)
            tcc_error("cannot continue");
        leave_scope(loop_scope);
        *cur_scope->csym = gjmp(*cur_scope->csym);
        skip(';');

    } లేకపోతే ఒకవేళ (t == TOK_FOR) {
        new_scope(&o);

        skip('(');
        ఒకవేళ (tok != ';') {
            /* c99 for-loop init decl? */
            ఒకవేళ (!decl(VT_JMP)) {
                /* no, regular for-loop init expr */
                gexpr();
                vpop();
            }
        }
        skip(';');
        a = b = 0;
        c = d = gind();
        ఒకవేళ (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        ఒకవేళ (tok != ')') {
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

    } లేకపోతే ఒకవేళ (t == TOK_DO) {
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

    } లేకపోతే ఒకవేళ (t == TOK_SWITCH) {
        నిర్మాణం switch_t *sw;

        sw = tcc_mallocz(పరిమాణం *sw);
        sw->bsym = &a;
        sw->scope = cur_scope;
        sw->prev = cur_switch;
        sw->nocode_wanted = nocode_wanted;
        cur_switch = sw;

        new_scope_s(&o);
        skip('(');
        gexpr_decl();
        ఒకవేళ (!is_integer_btype(vtop->type.t & VT_BTYPE))
            tcc_error("switch value not an integer");
        skip(')');
        sw->sv = *vtop--; /* save switch value */
        a = 0;
        b = gjmp(0); /* jump to first case */
        lblock(&a, ఖాళీ);
        a = gjmp(a); /* add implicit break */
        /* case lookup */
        gsym(b);
        prev_scope_s(&o);
        ఒకవేళ (sw->nocode_wanted)
            వెళ్ళు skip_switch;
        case_క్రమీకరించు(sw);
        sw->bsym = ఖాళీ; /* marker for 32bit:gen_opl() */
        vpushv(&sw->sv);
        gv(RC_INT);
        d = gcase(sw->p, sw->n, 0);
        vpop();
        ఒకవేళ (sw->def_sym)
            gsym_addr(d, sw->def_sym);
        లేకపోతే
            gsym(d);
    skip_switch:
        /* break label */
        gsym(a);
        చివర_switch();

    } లేకపోతే ఒకవేళ (t == TOK_CASE) {
        నిర్మాణం case_t *cr;
        ఒకవేళ (!cur_switch)
            expect("switch");
        cr = tcc_malloc(పరిమాణం(నిర్మాణం case_t));
        dynarray_కూడు(&cur_switch->p, &cur_switch->n, cr);
        t = cur_switch->sv.type.t;
        cr->v1 = cr->v2 = value64(సమాసం_const64(), t);
        ఒకవేళ (tok == TOK_DOTS && gnu_ext) {
            తదుపరి();
            cr->v2 = value64(సమాసం_const64(), t);
            ఒకవేళ (case_cmp(cr->v2, cr->v1) < 0)
                tcc_warning("empty case range");
        }
        /* case and default are unreachable from a switch under nocode_wanted */
        ఒకవేళ (!cur_switch->nocode_wanted)
            cr->ind = gind();
        cr->పంక్తి = file->పంక్తి_అంకె;
        skip(':');
        వెళ్ళు ఖండం_after_label;

    } లేకపోతే ఒకవేళ (t == TOK_DEFAULT) {
        ఒకవేళ (!cur_switch)
            expect("switch");
        ఒకవేళ (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = cur_switch->nocode_wanted ? -1 : gind();
        skip(':');
        వెళ్ళు ఖండం_after_label;

    } లేకపోతే ఒకవేళ (t == TOK_GOTO) {
        vla_restore(cur_scope->vla.locorig);
        ఒకవేళ (tok == '*' && gnu_ext) {
            /* computed goto */
            తదుపరి();
            gexpr();
            ఒకవేళ ((vtop->type.t & VT_BTYPE) != VT_PTR)
                expect("pointer");
            ggoto();

        } లేకపోతే ఒకవేళ (tok >= TOK_UIDENT) {
	    s = label_కనుగొను(tok);
	    /* put forward definition if needed */
            ఒకవేళ (!s)
              s = label_నెట్టు(&global_label_దొంతర, tok, LABEL_FORWARD);
            లేకపోతే ఒకవేళ (s->r == LABEL_DECLARED)
              s->r = LABEL_FORWARD;

	    ఒకవేళ (s->r & LABEL_FORWARD) {
		/* start new goto chain for cleanups, linked via label->next */
		ఒకవేళ (cur_scope->cl.s && !nocode_wanted) {
                    sym_push2(&pending_gotos, SYM_క్షేత్రం, 0, cur_scope->cl.n);
                    pending_gotos->cleanup_label = s;
                    s = sym_push2(&s->తదుపరి, SYM_క్షేత్రం, 0, 0);
                    pending_gotos->తదుపరి = s;
                }
		s->jnext = gjmp(s->jnext);
	    } లేకపోతే {
		try_call_cleanup_goto(s->cleanupstate);
		gjmp_addr(s->jind);
	    }
	    తదుపరి();

        } లేకపోతే {
            expect("label identifier");
        }
        skip(';');

    } లేకపోతే ఒకవేళ (t == TOK_ASM1 || t == TOK_ASM2 || t == TOK_ASM3) {
        asm_instr();

    } లేకపోతే {
        ఒకవేళ (tok == ':' && t >= TOK_UIDENT) {
            /* label case */
	    తదుపరి();
            s = label_కనుగొను(t);
            ఒకవేళ (s) {
                ఒకవేళ (s->r == LABEL_DEFINED)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ఖాళీ));
                s->r = LABEL_DEFINED;
		ఒకవేళ (s->తదుపరి) {
		    Sym *pcl; /* pending cleanup goto */
		    కొరకు (pcl = s->తదుపరి; pcl; pcl = pcl->prev)
		      gsym(pcl->jnext);
		    sym_తీయి(&s->తదుపరి, ఖాళీ, 0);
		} లేకపోతే
		  gsym(s->jnext);
            } లేకపోతే {
                s = label_నెట్టు(&global_label_దొంతర, t, LABEL_DEFINED);
            }
            s->jind = gind();
            s->cleanupstate = cur_scope->cl.s;

    ఖండం_after_label:
            /* Accept attributes after labels (e.g. 'unused') */
            parse_attribute(ఖాళీ);

            ఒకవేళ (debug_modes)
                tcc_tcov_reset_ind(tcc_state);
            vla_restore(cur_scope->vla.loc);

            ఒకవేళ (tok != '}') {
                ఒకవేళ (0 == (flags & STMT_COMPOUND))
                    వెళ్ళు again;
                /* C23: insert implicit null-statement whithin compound statement */
            } లేకపోతే {
                /* we accept this, but it is a mistake */
                tcc_warning_c(warn_all)("deprecated use of label at end of compound statement");
            }
        } లేకపోతే {
            /* expression case */
            ఒకవేళ (t != ';') {
                unget_tok(t);
    సమాసం:
                ఒకవేళ (flags & STMT_సమాసం) {
                    vpop();
                    gexpr();
                } లేకపోతే {
                    gexpr();
                    vpop();
                }
                skip(';');
            }
        }
    }

    ఒకవేళ (debug_modes)
        tcc_tcov_check_పంక్తి (tcc_state, 0), tcc_tcov_ఖండం_చివర (tcc_state, 0);
}

/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
స్థిర శూన్య skip_or_save_ఖండం(TokenString **str)
{
    పూర్ణాంకం braces = tok == '{';
    పూర్ణాంకం level = 0;
    ఒకవేళ (str)
      *str = tok_str_alloc();

    అయితే (1) {
	పూర్ణాంకం t = tok;
        ఒకవేళ (level == 0
            && (t == ','
             || t == ';'
             || t == '}'
             || t == ')'
             || t == ']'))
             ఆపు;
	ఒకవేళ (t == TOK_EOF) {
	     ఒకవేళ (str || level > 0)
	       tcc_error("unexpected end of file");
	     లేకపోతే
	       ఆపు;
	}
	ఒకవేళ (str)
	  tok_str_కూడు_tok(*str);
	తదుపరి();
	ఒకవేళ (t == '{' || t == '(' || t == '[') {
	    level++;
	} లేకపోతే ఒకవేళ (t == '}' || t == ')' || t == ']') {
	    level--;
	    ఒకవేళ (level == 0 && braces && t == '}')
	      ఆపు;
	}
    }
    ఒకవేళ (str)
	tok_str_కూడు(*str, TOK_EOF);
}

#నిర్వచించు సమాసం_CONST 1
#నిర్వచించు సమాసం_ANY   2

స్థిర శూన్య parse_init_elem(పూర్ణాంకం సమాసం_type)
{
    పూర్ణాంకం saved_global_సమాసం;
    ఎంపిక(సమాసం_type) {
    స్థితి సమాసం_CONST:
        /* compound literals must be allocated globally in this case */
        saved_global_సమాసం = global_సమాసం;
        global_సమాసం = 1;
        సమాసం_const1();
        global_సమాసం = saved_global_సమాసం;
        /* NOTE: symbols are accepted, as well as lvalue for anon symbols
	   (compound literals).  */
        ఒకవేళ (((vtop->r & (VT_VALMASK | VT_LVAL)) != VT_CONST
             && ((vtop->r & (VT_SYM|VT_LVAL)) != (VT_SYM|VT_LVAL)
                 || vtop->sym->v < SYM_మొదటి_ANOM))
#నిర్వచితమైతే TCC_లక్ష్యం_PE
                 || ((vtop->r & VT_SYM) && vtop->sym->a.dllimport)
#అయితే_ముగింపు
           )
            tcc_error("initializer element is not constant");
        ఆపు;
    స్థితి సమాసం_ANY:
        సమాసం_eq();
        ఆపు;
    }
}

#ఒకవేళ 1
స్థిర శూన్య init_assert(init_params *p, పూర్ణాంకం స్థానభ్రంశం)
{
    ఒకవేళ (p->sec ? !NODATA_WANTED && స్థానభ్రంశం > p->sec->దత్తాంశం_స్థానభ్రంశం
               : !nocode_wanted && స్థానభ్రంశం > p->local_స్థానభ్రంశం)
        tcc_అంతర్గత_error("initializer overflow");
}
#లేకపోతే
#నిర్వచించు init_assert(sec, స్థానభ్రంశం)
#అయితే_ముగింపు

/* put zeros for variable based init */
స్థిర శూన్య init_putz(init_params *p, గుర్తులేని దీర్ఘ c, పూర్ణాంకం కొలత)
{
    init_assert(p, c + కొలత);
    ఒకవేళ (p->sec) {
        /* nothing to do because globals are already set to zero */
    } లేకపోతే {
        vpush_helper_func(TOK_memset);
        vseti(VT_LOCAL, c);
        vpushi(0);
        vpushs(కొలత);
#ఒకవేళ defined TCC_లక్ష్యం_ARM && defined TCC_ARM_EABI
        vswap();  /* using __aeabi_memset(void*, size_t, int) */
#అయితే_ముగింపు
        gfunc_call(3);
    }
}

#నిర్వచించు DIF_మొదటి     1
#నిర్వచించు DIF_కొలత_ONLY 2
#నిర్వచించు DIF_HAVE_ELEM 4
#నిర్వచించు DIF_CLEAR     8

/* delete relocations for specified range c ... c + size. Unfortunatly
   in very special cases, relocations may occur unordered */
స్థిర శూన్య decl_design_delrels(Section *sec, పూర్ణాంకం c, పూర్ణాంకం కొలత)
{
    ElfW_Rel *rel, *rel2, *rel_చివర;
    ఒకవేళ (!sec || !sec->reloc)
        తిరిగి;
    rel = rel2 = (ElfW_Rel*)sec->reloc->దత్తాంశం;
    rel_చివర = (ElfW_Rel*)(sec->reloc->దత్తాంశం + sec->reloc->దత్తాంశం_స్థానభ్రంశం);
    అయితే (rel < rel_చివర) {
        ఒకవేళ (rel->r_స్థానభ్రంశం >= c && rel->r_స్థానభ్రంశం < c + కొలత) {
            sec->reloc->దత్తాంశం_స్థానభ్రంశం -= పరిమాణం *rel;
        } లేకపోతే {
            ఒకవేళ (rel2 != rel)
                జ్ఞాపకం_నకలు(rel2, rel, పరిమాణం *rel);
            ++rel2;
        }
        ++rel;
    }
}

స్థిర శూన్య decl_design_flex(init_params *p, Sym *ref, పూర్ణాంకం సూచీ)
{
    ఒకవేళ (ref == p->flex_array_ref) {
        ఒకవేళ (సూచీ >= ref->c)
            ref->c = సూచీ + 1;
    } లేకపోతే ఒకవేళ (ref->c < 0 && సూచీ >= 0)
        tcc_error("flexible array has zero size in this context");
}

/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'flags' is as in decl_initializer.
   'al' contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
స్థిర పూర్ణాంకం decl_designator(init_params *p, CType *type, గుర్తులేని దీర్ఘ c,
                           Sym **cur_క్షేత్రం, పూర్ణాంకం flags, పూర్ణాంకం al)
{
    Sym *s, *f;
    పూర్ణాంకం సూచీ, సూచీ_చివరి, align, l, nb_elems, elem_కొలత;
    గుర్తులేని దీర్ఘ corig = c;

    elem_కొలత = 0;
    nb_elems = 1;

    ఒకవేళ (flags & DIF_HAVE_ELEM)
        వెళ్ళు no_designator;

    ఒకవేళ (gnu_ext && tok >= TOK_UIDENT) {
        l = tok, తదుపరి();
        ఒకవేళ (tok == ':')
            వెళ్ళు struct_క్షేత్రం;
        unget_tok(l);
    }

    /* NOTE: we only support ranges for last designator */
    అయితే (nb_elems == 1 && (tok == '[' || tok == '.')) {
        ఒకవేళ (tok == '[') {
            ఒకవేళ (!(type->t & VT_ARRAY))
                expect("array type");
            తదుపరి();
            సూచీ = సూచీ_చివరి = సమాసం_const();
            ఒకవేళ (tok == TOK_DOTS && gnu_ext) {
                తదుపరి();
                సూచీ_చివరి = సమాసం_const();
            }
            skip(']');
            s = type->ref;
            decl_design_flex(p, s, సూచీ_చివరి);
            ఒకవేళ (సూచీ < 0 || సూచీ_చివరి >= s->c || సూచీ_చివరి < సూచీ)
	        tcc_error("index exceeds array bounds or range is empty");
            ఒకవేళ (cur_క్షేత్రం)
		(*cur_క్షేత్రం)->c = సూచీ_చివరి;
            type = pointed_type(type);
            elem_కొలత = type_కొలత(type, &align);
            c += సూచీ * elem_కొలత;
            nb_elems = సూచీ_చివరి - సూచీ + 1;
        } లేకపోతే {
            పూర్ణాంకం cumofs;
            తదుపరి();
            l = tok;
        struct_క్షేత్రం:
            తదుపరి();
	    f = కనుగొను_క్షేత్రం(type, l, &cumofs);
            ఒకవేళ (cur_క్షేత్రం)
                *cur_క్షేత్రం = f;
	    type = &f->type;
            c += cumofs;
        }
        cur_క్షేత్రం = ఖాళీ;
    }
    ఒకవేళ (!cur_క్షేత్రం) {
        ఒకవేళ (tok == '=') {
            తదుపరి();
        } లేకపోతే ఒకవేళ (!gnu_ext) {
	    expect("=");
        }
    } లేకపోతే {
    no_designator:
        ఒకవేళ (type->t & VT_ARRAY) {
	    సూచీ = (*cur_క్షేత్రం)->c;
            s = type->ref;
            decl_design_flex(p, s, సూచీ);
            ఒకవేళ (సూచీ >= s->c)
                tcc_error("too many initializers");
            type = pointed_type(type);
            elem_కొలత = type_కొలత(type, &align);
            c += సూచీ * elem_కొలత;
        } లేకపోతే {
            f = *cur_క్షేత్రం;
	    /* Skip bitfield padding. Also with size 32 and 64. */
	    అయితే (f && (f->v & SYM_మొదటి_ANOM) &&
		   is_integer_btype(f->type.t & VT_BTYPE))
	        *cur_క్షేత్రం = f = f->తదుపరి;
            ఒకవేళ (!f)
                tcc_error("too many initializers");
	    type = &f->type;
            c += f->c;
        }
    }

    ఒకవేళ (!elem_కొలత) /* for structs */
        elem_కొలత = type_కొలత(type, &align);

    /* Using designators the same element can be initialized more
       than once.  In that case we need to delete possibly already
       existing relocations. */
    ఒకవేళ (!(flags & DIF_కొలత_ONLY) && c - corig < al) {
        decl_design_delrels(p->sec, c, elem_కొలత * nb_elems);
        flags &= ~DIF_CLEAR; /* mark stack dirty too */
    }

    decl_initializer(p, type, c, flags & ~DIF_మొదటి);

    ఒకవేళ (!(flags & DIF_కొలత_ONLY) && nb_elems > 1) {
        Sym aref = {0};
        CType t1;
        పూర్ణాంకం i;
        ఒకవేళ (p->sec || (type->t & VT_ARRAY)) {
            /* make init_putv/vstore believe it were a struct */
            aref.c = elem_కొలత;
            t1.t = VT_STRUCT, t1.ref = &aref;
            type = &t1;
        }
        ఒకవేళ (p->sec)
            vpush_ref(type, p->sec, c, elem_కొలత);
        లేకపోతే
	    vset(type, VT_LOCAL|VT_LVAL, c);
        కొరకు (i = 1; i < nb_elems; i++) {
            vdup();
            init_putv(p, type, c + elem_కొలత * i);
	}
        vpop();
    }

    c += nb_elems * elem_కొలత;
    ఒకవేళ (c - corig > al)
      al = c - corig;
    తిరిగి al;
}

స్థిర శూన్య write_ldouble(గుర్తులేని అక్షరం *d, శూన్య *s)
{
    //printf("long double %Lf\n", *(long double*)s);
#నిర్వచితమైతే TCC_CROSS_TEST
    ఒకవేళ (LDOUBLE_కొలత >= 10) {
        ద్విగుణ b = *(దీర్ఘ ద్విగుణ*)s;
        s = &b;
#లేకపోతే
    ఒకవేళ (పరిమాణం (దీర్ఘ ద్విగుణ) == 8 && LDOUBLE_కొలత >= 10) {
#అయితే_ముగింపు
        /* our 'long double' is a double really (_WIN32, __APPLE__) */
        uint64_t m = *(uint64_t*)s;
        పూర్ణాంకం e = m >> 48;
        పూర్ణాంకం f = e >> 4 & 0x7FF;
        m <<= 11;
        ఒకవేళ (0 == f) {
            ఒకవేళ (0 == m)
                వెళ్ళు సమితి;
            కొరకు (f = 1; !(m & 1ULL<<63); --f)
                m <<= 1;
        }
        ఒకవేళ (f == 0x7ff)
            f = 0x43FF;
        e = (e & 0x8000) | (f + 0x3C00);
        m |= 1ULL<<63;
    సమితి:
    #ఒకవేళ (defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64)
        /* double -> extended */
        write64le(d, m);
        write16le(d+8, e);
    #లేదావేళ LDOUBLE_కొలత == 16
        /* double -> quad */
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #అయితే_ముగింపు
        ;
    } లేకపోతే {
    #ఒకవేళ LDOUBLE_కొలత == 8
        /* long double -> double */
        ద్విగుణ b = *(దీర్ఘ ద్విగుణ*)s;
        జ్ఞాపకం_నకలు(d, &b, 8);
    #లేదావేళ (__i386__ || __x86_64__) && (defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64)
        /* extended -> extended */
        జ్ఞాపకం_నకలు(d, s, 10);
    #లేదావేళ (__i386__ || __x86_64__) && (defined TCC_లక్ష్యం_ARM64 || defined TCC_లక్ష్యం_RISCV64)
        /* extended -> quad */
        uint64_t m = *(uint64_t*)s;
        పూర్ణాంకం e = *(uint16_t*)((అక్షరం*)s + 8);
        write64le(d+6, m << 1);
        write16le(d+14, e);
    #లేదావేళ (__aarch64__ || __riscv) && (defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64)
        /* quad -> extended */
        uint64_t m = read64le((అక్షరం*)s + 6);
        పూర్ణాంకం e = read16le((అక్షరం*)s + 14);
        (e & 0x7fff) && (m & 1) && 0 == ++m && ++e;
        write64le(d, m >> 1 | ((e & 0x7fff) ? 1ULL<<63 : 0));
        write16le(d+8, e);
    #లేకపోతే
        /* unknown */
        ఒకవేళ (పరిమాణం (దీర్ఘ ద్విగుణ) == LDOUBLE_కొలత)
            జ్ఞాపకం_నకలు(d, s, LDOUBLE_కొలత);
    #అయితే_ముగింపు
    }
}

/* store a value or an expression directly in global data or in local array */
స్థిర శూన్య init_putv(init_params *p, CType *type, గుర్తులేని దీర్ఘ c)
{
    పూర్ణాంకం bt;
    శూన్య *ptr;
    CType dtype;
    పూర్ణాంకం కొలత, align;
    Section *sec = p->sec;
    uint64_t val;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    కొలత = type_కొలత(type, &align);
    ఒకవేళ (type->t & VT_BITFIELD)
        కొలత = (బిట్టు_POS(type->t) + బిట్టు_కొలత(type->t) + 7) / 8;
    init_assert(p, c + కొలత);

    ఒకవేళ (sec) {
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_కేటాయించు_cast(&dtype);
        bt = type->t & VT_BTYPE;

        ఒకవేళ ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && (bt != (PTR_కొలత == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_మొదటి_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        ఒకవేళ (NODATA_WANTED) {
            vtop--;
            తిరిగి;
        }

        ptr = sec->దత్తాంశం + c;
        val = vtop->c.i;

	ఒకవేళ ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST)
            && vtop->sym->v >= SYM_మొదటి_ANOM
            && ((vtop->r & VT_LVAL) /* compound literal */
                || bt == VT_STRUCT /* designator */
                )) {
	    /* memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->దత్తాంశం + esym->st_విలువ + (పూర్ణాంకం)vtop->c.i, కొలత);
	    ఒకవేళ (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
                గుర్తులేని దీర్ఘ relofs = ssec->reloc->దత్తాంశం_స్థానభ్రంశం;
		అయితే (relofs >= పరిమాణం(*rel)) {
                    relofs -= పరిమాణం(*rel);
                    rel = (ElfW_Rel*)(ssec->reloc->దత్తాంశం + relofs);
		    ఒకవేళ (rel->r_స్థానభ్రంశం >= esym->st_విలువ + కొలత)
		      కొనసాగు;
		    ఒకవేళ (rel->r_స్థానభ్రంశం < esym->st_విలువ)
		      ఆపు;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_స్థానభ్రంశం - esym->st_విలువ,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#ఒకవేళ PTR_కొలత == 8
				   rel->r_addend
#లేకపోతే
				   0
#అయితే_ముగింపు
				  );
		}
	    }
	} లేకపోతే {
            ఒకవేళ (type->t & VT_BITFIELD) {
                పూర్ణాంకం బిట్టు_pos, బిట్టు_కొలత_2, బిట్లు, n;
                గుర్తులేని అక్షరం *p, v, m;
                బిట్టు_pos = బిట్టు_POS(vtop->type.t);
                బిట్టు_కొలత_2 = బిట్టు_కొలత(vtop->type.t);
                p = (గుర్తులేని అక్షరం*)ptr + (బిట్టు_pos >> 3);
                బిట్టు_pos &= 7, బిట్లు = 0;
                అయితే (బిట్టు_కొలత_2) {
                    n = 8 - బిట్టు_pos;
                    ఒకవేళ (n > బిట్టు_కొలత_2)
                        n = బిట్టు_కొలత_2;
                    v = val >> బిట్లు << బిట్టు_pos;
                    m = ((1 << n) - 1) << బిట్టు_pos;
                    *p = (*p & ~m) | (v & m);
                    బిట్లు += n, బిట్టు_కొలత_2 -= n, బిట్టు_pos = 0, ++p;
                }
            } లేకపోతే
            ఎంపిక(bt) {
	    స్థితి VT_BOOL:
		*(అక్షరం *)ptr = val != 0;
                ఆపు;
	    స్థితి VT_BYTE:
		*(అక్షరం *)ptr = val;
		ఆపు;
	    స్థితి VT_SHORT:
                write16le(ptr, val);
		ఆపు;
	    స్థితి VT_FLOAT:
                write32le(ptr, val);
		ఆపు;
	    స్థితి VT_DOUBLE:
                write64le(ptr, val);
		ఆపు;
	    స్థితి VT_LDOUBLE:
                write_ldouble(ptr, &vtop->c.ld);
		ఆపు;

#ఒకవేళ PTR_కొలత == 8
            /* intptr_t may need a reloc too, see tcctest.c:relocation_test() */
	    స్థితి VT_LLONG:
	    స్థితి VT_PTR:
	        ఒకవేళ (vtop->r & VT_SYM)
	          greloca(sec, vtop->sym, c, R_దత్తాంశం_PTR, val);
	        లేకపోతే
	          write64le(ptr, val);
	        ఆపు;
            స్థితి VT_INT:
                write32le(ptr, val);
                ఆపు;
#లేకపోతే
	    స్థితి VT_LLONG:
                write64le(ptr, val);
                ఆపు;
            స్థితి VT_PTR:
            స్థితి VT_INT:
	        ఒకవేళ (vtop->r & VT_SYM)
	          greloc(sec, vtop->sym, c, R_దత్తాంశం_PTR);
	        write32le(ptr, val);
	        ఆపు;
#అయితే_ముగింపు
	    అప్రమేయ:
                //tcc_internal_error("unexpected type");
                ఆపు;
	    }
	}
        vtop--;
    } లేకపోతే {
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
స్థిర శూన్య decl_initializer(init_params *p, CType *type, గుర్తులేని దీర్ఘ c, పూర్ణాంకం flags)
{
    పూర్ణాంకం len, n, no_oblock, i;
    పూర్ణాంకం size1, align1;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* generate line number info */
    ఒకవేళ (debug_modes && !(flags & DIF_కొలత_ONLY) && !p->sec)
        tcc_debug_పంక్తి(tcc_state), tcc_tcov_check_పంక్తి (tcc_state, 1);

    ఒకవేళ (!(flags & DIF_HAVE_ELEM) && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	(!(flags & DIF_కొలత_ONLY)
            /* a struct may be initialized from a struct of same type, as in
                    struct {int x,y;} a = {1,2}, b = {3,4}, c[] = {a,b};
               In that case we need to parse the element in order to check
               it for compatibility below */
            || (type->t & VT_BTYPE) == VT_STRUCT)
        ) {
        పూర్ణాంకం ncw_prev = nocode_wanted;
        ఒకవేళ ((flags & DIF_కొలత_ONLY) && !p->sec)
            ++nocode_wanted;
	parse_init_elem(!p->sec ? సమాసం_ANY : సమాసం_CONST);
        nocode_wanted = ncw_prev;
        flags |= DIF_HAVE_ELEM;
    }

    ఒకవేళ (type->t & VT_ARRAY) {
        no_oblock = 1;
        ఒకవేళ (((flags & DIF_మొదటి) && tok != TOK_LSTR && tok != TOK_STR) ||
            tok == '{') {
            skip('{');
            no_oblock = 0;
        }

        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_కొలత(t1, &align1);

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        ఒకవేళ ((tok == TOK_LSTR && 
#నిర్వచితమైతే TCC_లక్ష్యం_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#లేకపోతే
             (t1->t & VT_BTYPE) == VT_INT
#అయితే_ముగింపు
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            cstr_reset(&initstr);
            ఒకవేళ (size1 != (tok == TOK_STR ? 1 : పరిమాణం(nwchar_t)))
              tcc_error("unhandled string literal merging");
            అయితే (tok == TOK_STR || tok == TOK_LSTR) {
                ఒకవేళ (initstr.కొలత)
                  initstr.కొలత -= size1;
                ఒకవేళ (tok == TOK_STR)
                  len += tokc.str.కొలత;
                లేకపోతే
                  len += tokc.str.కొలత / పరిమాణం(nwchar_t);
                len--;
                cstr_cat(&initstr, tokc.str.దత్తాంశం, tokc.str.కొలత);
                తదుపరి();
            }
            ఒకవేళ (tok != ')' && tok != '}' && tok != ',' && tok != ';'
                && tok != TOK_EOF) {
                /* Not a lone literal but part of a bigger expression.  */
                unget_tok(size1 == 1 ? TOK_STR : TOK_LSTR);
                tokc.str.కొలత = initstr.కొలత;
                tokc.str.దత్తాంశం = initstr.దత్తాంశం;
                వెళ్ళు do_init_array;
            }

            decl_design_flex(p, s, len);
            ఒకవేళ (!(flags & DIF_కొలత_ONLY)) {
                పూర్ణాంకం nb = n, ch;
                ఒకవేళ (len < nb)
                    nb = len;
                ఒకవేళ (len > nb)
                  tcc_warning("initializer-string for array is too long");
                /* in order to go faster for common case (char
                   string in global variable, we handle it
                   specifically */
                ఒకవేళ (p->sec && size1 == 1) {
                    init_assert(p, c + nb);
                    ఒకవేళ (!NODATA_WANTED)
                      జ్ఞాపకం_నకలు(p->sec->దత్తాంశం + c, initstr.దత్తాంశం, nb);
                } లేకపోతే {
                    కొరకు(i=0;i<n;i++) {
                        ఒకవేళ (i >= nb) {
                          /* only add trailing zero if enough storage (no
                             warning in this case since it is standard) */
                          ఒకవేళ (flags & DIF_CLEAR)
                            ఆపు;
                          ఒకవేళ (n - i >= 4) {
                            init_putz(p, c + i * size1, (n - i) * size1);
                            ఆపు;
                          }
                          ch = 0;
                        } లేకపోతే ఒకవేళ (size1 == 1)
                          ch = ((గుర్తులేని అక్షరం *)initstr.దత్తాంశం)[i];
                        లేకపోతే
                          ch = ((nwchar_t *)initstr.దత్తాంశం)[i];
                        vpushi(ch);
                        init_putv(p, t1, c + i * size1);
                    }
                }
            }
            ఒకవేళ (tok == ',' && !no_oblock) /* static const char s[] = { "123", }; */
                తదుపరి();
        } లేకపోతే {

          do_init_array:
	    indexsym.c = 0;
	    f = &indexsym;

          do_init_list:
            /* zero memory once in advance */
            ఒకవేళ (!(flags & (DIF_CLEAR | DIF_కొలత_ONLY))) {
                init_putz(p, c, n*size1);
                flags |= DIF_CLEAR;
            }

	    len = 0;
            /* GNU extension: if the initializer is empty for a flex array,
               it's size is zero.  We won't enter the loop, so set the size
               now.  */
            decl_design_flex(p, s, len - 1);
	    అయితే (tok != '}' || (flags & DIF_HAVE_ELEM)) {
		len = decl_designator(p, type, c, &f, flags, len);
		flags &= ~DIF_HAVE_ELEM;
		ఒకవేళ (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    ఒకవేళ (no_oblock && len >= n*size1)
		        ఆపు;
		} లేకపోతే {
		    ఒకవేళ (s->type.t == VT_UNION)
		        f = ఖాళీ;
		    లేకపోతే
		        f = f->తదుపరి;
		    ఒకవేళ (no_oblock && f == ఖాళీ)
		        ఆపు;
		}

		ఒకవేళ (tok == '}')
		    ఆపు;
		skip(',');
	    }
        }
        ఒకవేళ (!no_oblock)
            skip('}');

    } లేకపోతే ఒకవేళ ((flags & DIF_HAVE_ELEM)
        /* Use i_c_parameter_t, to strip toplevel qualifiers.
           The source type might have VT_CONSTANT set, which is
           of course assignable to non-const elements.  */
            && is_compatible_unqualified_types(type, &vtop->type)) {
        వెళ్ళు one_elem;

    } లేకపోతే ఒకవేళ ((type->t & VT_BTYPE) == VT_STRUCT) {
        no_oblock = 1;
        ఒకవేళ ((flags & DIF_మొదటి) || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->తదుపరి;
        n = s->c;
        size1 = 1;
	వెళ్ళు do_init_list;

    } లేకపోతే ఒకవేళ (tok == '{') {
        ఒకవేళ (flags & DIF_HAVE_ELEM)
          skip(';');
        తదుపరి();
        decl_initializer(p, type, c, flags & ~DIF_HAVE_ELEM);
        skip('}');

    } లేకపోతే one_elem: ఒకవేళ ((flags & DIF_కొలత_ONLY)) {
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array if DIF_SIZE_ONLY (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when DIF_SIZE_ONLY is set.  */
        /* just skip expression */
        ఒకవేళ (flags & DIF_HAVE_ELEM)
            vpop();
        లేకపోతే
            skip_or_save_ఖండం(ఖాళీ);

    } లేకపోతే {
	ఒకవేళ (!(flags & DIF_HAVE_ELEM)) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    ఒకవేళ (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!p->sec ? సమాసం_ANY : సమాసం_CONST);
	}
        ఒకవేళ (!p->sec && (flags & DIF_CLEAR) /* container was already zero'd */
            && (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST
            && vtop->c.i == 0
            && btype_కొలత(type->t & VT_BTYPE) /* not for fp constants */
            )
            vpop();
        లేకపోతే
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
స్థిర శూన్య decl_initializer_alloc(CType *type, AttributeDef *ad, పూర్ణాంకం r, 
                                   పూర్ణాంకం has_init, పూర్ణాంకం v, పూర్ణాంకం scope)
{
    పూర్ణాంకం కొలత, align, addr;
    TokenString *init_str = ఖాళీ;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = ఖాళీ;
    పూర్ణాంకం saved_nocode_wanted = nocode_wanted;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    పూర్ణాంకం bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#అయితే_ముగింపు
    init_params p = {0};

    ఒకవేళ (scope == VT_CONST) {
        /* see if a global symbol was already defined */
        sym = sym_కనుగొను(v);
        ఒకవేళ (sym) {
            patch_storage(sym, ad, type);
            /* we accept several definitions of the same global variable. */
            ఒకవేళ (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                తిరిగి;
            type = &sym->type;
        }
    }

    /* Always allocate static or global variables */
    ఒకవేళ (v && (r & VT_VALMASK) == VT_CONST)
        nocode_wanted |= దత్తాంశం_ONLY_WANTED;

    flexible_array = ఖాళీ;
    కొలత = type_కొలత(type, &align);

    /* exactly one flexible array may be initialized, either the
       toplevel array or the last member of the toplevel struct */

    ఒకవేళ (కొలత < 0) {
        // error out except for top-level incomplete arrays
        // (arrays of incomplete types are handled in array parsing)
        ఒకవేళ (!(type->t & VT_ARRAY))
            tcc_error("initialization of incomplete type");
        /* If the base type itself was an array type of unspecified
           size (like in 'typedef int arr[]; arr x = {1};') then
           we will overwrite the unknown size by the real one for
           this decl.  We need to unshare the ref symbol holding
           that size.  */
        ఒకవేళ (IS_BT_ARRAY(type->t))
            type->ref = sym_నెట్టు(SYM_క్షేత్రం, &type->ref->type, 0, type->ref->c);
        p.flex_array_ref = type->ref;

    } లేకపోతే ఒకవేళ (has_init && (type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *క్షేత్రం = type->ref->తదుపరి;
        ఒకవేళ (క్షేత్రం) {
            అయితే (క్షేత్రం->తదుపరి)
                క్షేత్రం = క్షేత్రం->తదుపరి;
            ఒకవేళ (క్షేత్రం->type.t & VT_ARRAY && క్షేత్రం->type.ref->c < 0) {
                flexible_array = క్షేత్రం;
                p.flex_array_ref = క్షేత్రం->type.ref;
                కొలత = -1;
            }
        }
    }

    ఒకవేళ (కొలత < 0) {
        /* If unknown size, do a dry-run 1st pass */
        ఒకవేళ (!has_init)
            వెళ్ళు err_కొలత;
        ఒకవేళ (has_init == 2) {
            /* only get strings */
            init_str = tok_str_alloc();
            అయితే (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_కూడు_tok(init_str);
                తదుపరి();
            }
            tok_str_కూడు(init_str, TOK_EOF);
        } లేకపోతే
            skip_or_save_ఖండం(&init_str);
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        తదుపరి();
        decl_initializer(&p, type, 0, DIF_మొదటి | DIF_కొలత_ONLY);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        తదుపరి();

        /* if still unknown size, error */
        కొలత = type_కొలత(type, &align);
        ఒకవేళ (కొలత < 0)
    err_కొలత:
            tcc_error("unknown type size");

        /* If there's a flex member and it was used in the initializer
           adjust size.  */
        ఒకవేళ (flexible_array && flexible_array->type.ref->c > 0)
            కొలత += flexible_array->type.ref->c
                    * pointed_కొలత(&flexible_array->type);
    }

    /* take into account specified alignment if bigger */
    ఒకవేళ (ad->a.aligned) {
	పూర్ణాంకం speca = 1 << (ad->a.aligned - 1);
        ఒకవేళ (speca > align)
            align = speca;
    } లేకపోతే ఒకవేళ (ad->a.packed) {
        align = 1;
    }

    ఒకవేళ (!v && NODATA_WANTED)
        కొలత = 0, align = 1;

    ఒకవేళ ((r & VT_VALMASK) == VT_LOCAL) {
        sec = ఖాళీ;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#అయితే_ముగింపు
        loc = (loc - కొలత) & -align;
        addr = loc;
        p.local_స్థానభ్రంశం = addr + కొలత;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (bcheck && v) {
            /* add padding between stack variables for bound checking */
            loc -= align;
        }
#అయితే_ముగింపు
        ఒకవేళ (v) {
            /* local variable */
#నిర్వచితమైతే CONFIG_TCC_ASM
	    ఒకవేళ (ad->asm_label) {
		పూర్ణాంకం reg = asm_parse_regvar(ad->asm_label);
		ఒకవేళ (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#అయితే_ముగింపు
            sym = sym_నెట్టు(v, type, r, addr);
	    ఒకవేళ (ad->cleanup_func) {
		Sym *cls = sym_push2(&all_cleanups,
                    SYM_క్షేత్రం | ++cur_scope->cl.n, 0, 0);
		cls->cleanup_sym = sym;
		cls->cleanup_func = ad->cleanup_func;
		cls->తదుపరి = cur_scope->cl.s;
		cur_scope->cl.s = cls;
	    }

            sym->a = ad->a;
        } లేకపోతే {
            /* push local reference */
            vset(type, r, addr);
        }
    } లేకపోతే {
        CType *tp = type;
        పూర్ణాంకం is_const;

        అయితే ((tp->t & (VT_BTYPE|VT_ARRAY)) == (VT_PTR|VT_ARRAY))
            tp = &tp->ref->type;
        is_const = tp->t & VT_CONSTANT;

        /* allocate symbol in corresponding section */
        sec = ad->section;
        ఒకవేళ (!sec) {
            ఒకవేళ (type->t & VT_TLS) {
                sec = కనుగొను_section(tcc_state, has_init ? ".tdata" : ".tbss");
                sec->sh_flags = SHF_ALLOC | SHF_WRITE | SHF_TLS;
                sec->sh_type = has_init ? SHT_PROGBITS : SHT_NOBITS;
            } లేకపోతే ఒకవేళ (is_const) {
		sec = rodata_section;
            } లేకపోతే ఒకవేళ (has_init) {
		sec = దత్తాంశం_section;
                /*if (g_debug & 4)
                    tcc_warning("rw data: %s", get_tok_str(v, 0));*/
            } లేకపోతే ఒకవేళ (tcc_state->nocommon)
                sec = bss_section;
        } లేకపోతే ఒకవేళ (ad->new_section) {
            /* XXX: DWIM logic: set section flags according to first usage */
            ఒకవేళ (!is_const) {
                sec->sh_flags |= SHF_WRITE;
                ఒకవేళ (!has_init)
                    sec->sh_type = SHT_NOBITS;
            }
        }

#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (bcheck)
            కొలత = కొలత + 1; /* add padding */
#అయితే_ముగింపు
        ఒకవేళ (sec) {
	    addr = section_కూడు(sec, కొలత, align);
        } లేకపోతే {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        ఒకవేళ (v) {
            ఒకవేళ (!sym) {
                sym = sym_నెట్టు(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, ఖాళీ);
            }
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, కొలత);
        } లేకపోతే {
            /* push global reference */
            vpush_ref(type, sec, addr, కొలత);
            sym = vtop->sym;
	    vtop->r |= r;
        }

#నిర్వచితమైతే CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        ఒకవేళ (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->దత్తాంశం_స్థానభ్రంశం, R_దత్తాంశం_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_కూడు(bounds_section, 2 * పరిమాణం(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = కొలత - 1;
        }
#అయితే_ముగింపు
    }

    ఒకవేళ (type->t & VT_VLA) {
        పూర్ణాంకం a;

        ఒకవేళ (has_init)
            tcc_error("variable length array cannot be initialized");

        ఒకవేళ (NODATA_WANTED)
            వెళ్ళు no_alloc;

        /* save before-VLA stack pointer if needed */
        ఒకవేళ (cur_scope->vla.అంకె == 0) {
            ఒకవేళ (cur_scope->prev && cur_scope->prev->vla.అంకె) {
                cur_scope->vla.locorig = cur_scope->prev->vla.loc;
            } లేకపోతే {
                gen_vla_sp_save(loc -= PTR_కొలత);
                cur_scope->vla.locorig = loc;
            }
        }

        vpush_type_కొలత(type, &a);
        gen_vla_alloc(type, a);
#ఒకవేళ defined TCC_లక్ష్యం_PE && defined TCC_లక్ష్యం_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_ఫలితం(addr), addr = (loc -= PTR_కొలత);
#అయితే_ముగింపు
        gen_vla_sp_save(addr);
        cur_scope->vla.loc = addr;
        cur_scope->vla.అంకె++;
    } లేకపోతే ఒకవేళ (has_init) {
        p.sec = sec;
        decl_initializer(&p, type, addr, DIF_మొదటి);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        ఒకవేళ (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    ఒకవేళ (init_str) {
        చివర_macro();
        తదుపరి();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* generate vla code saved in post_type() */
స్థిర శూన్య func_vla_arg_సంకేతం(Sym *arg)
{
    పూర్ణాంకం align;
    TokenString *vla_array_tok = ఖాళీ;

    ఒకవేళ (arg->type.ref)
        func_vla_arg_సంకేతం(arg->type.ref);

    ఒకవేళ ((arg->type.t & VT_VLA) && arg->type.ref->vla_array_str) {
	loc -= type_కొలత(&int_type, &align);
	loc &= -align;
	arg->type.ref->c = loc;

	unget_tok(0);
	vla_array_tok = tok_str_alloc();
	vla_array_tok->str = arg->type.ref->vla_array_str;
	begin_macro(vla_array_tok, 1);
	తదుపరి();
	gexpr();
	చివర_macro();
	తదుపరి();
	vpush_type_కొలత(&arg->type.ref->type, &align);
	gen_op('*');
	vset(&int_type, VT_LOCAL|VT_LVAL, arg->type.ref->c);
	vswap();
	vstore();
	vpop();
    }
}

స్థిర శూన్య func_vla_arg(Sym *sym)
{
    Sym *arg;

    కొరకు (arg = sym->type.ref->తదుపరి; arg; arg = arg->తదుపరి)
        ఒకవేళ ((arg->type.t & VT_BTYPE) == VT_PTR && (arg->type.ref->type.t & VT_VLA))
            func_vla_arg_సంకేతం(arg->type.ref);
}

/* set the local stack address for function parameter from gfunc_prolog() */
ST_FUNC Sym *gfunc_సమితి_param(Sym *s, పూర్ణాంకం c, పూర్ణాంకం byref)
{
    s = sym_కనుగొను(s->v);
    ఒకవేళ (!s) /* unnamed parameters, not enabled */
        తిరిగి ఖాళీ;
    s->c = c;
    ఒకవేళ (byref)
        s->r = VT_LLOCAL | VT_LVAL; /* otherwise VT_LOCAL */
    తిరిగి s;
}

/* push parameters (and their types), last first */
స్థిర శూన్య sym_నెట్టు_params(Sym *ref)
{
    Sym *s = ref;
    అయితే (s->తదుపరి)
        s = s->తదుపరి;
    అయితే (s != ref) {
        ఒకవేళ ((s->v & ~SYM_STRUCT) < SYM_మొదటి_ANOM)
            sym_copy(s, &local_దొంతర);
        s = s->prev;
    }
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
స్థిర శూన్య gen_function(Sym *sym)
{
    నిర్మాణం scope f = { 0 };

    cur_scope = మూలం_scope = &f;
    nocode_wanted = 0;

    ind = cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;
    ఒకవేళ (sym->a.aligned) {
	కొలత_t newoff = section_కూడు(cur_పాఠ్యం_section, 0,
				    1 << (sym->a.aligned - 1));
	gen_fill_nops(newoff - ind);
    }

    funcname = get_tok_str(sym->v, ఖాళీ);
    func_ind = ind;
    func_vt = sym->type.ref->type;
    func_var = sym->type.ref->f.func_type == FUNC_ELLIPSIS;
    func_old = sym->type.ref->f.func_type == FUNC_OLD;

    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_పాఠ్యం_section, ind, 0);

    ఒకవేళ (sym->type.ref->f.func_ctor)
        కూడు_array (tcc_state, ".init_array", sym->c);
    ఒకవేళ (sym->type.ref->f.func_dtor)
        కూడు_array (tcc_state, ".fini_array", sym->c);

    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);

    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_దొంతర, SYM_క్షేత్రం, 0, 0);
    /* push parameters */
    local_scope = 1;
    sym_నెట్టు_params(sym->type.ref);

    local_scope = 0;
    rsym = 0;
    nb_తాత్కాలిక_local_vars = 0;

    gfunc_prolog(sym);
    tcc_debug_prolog_epilog(tcc_state, 0);
    func_vla_arg(sym);
    ఖండం(0);
    gsym(rsym);
    nocode_wanted = 0;
    tcc_debug_చివర_scope(ఖాళీ, !func_var);
    tcc_debug_prolog_epilog(tcc_state, 1);
    gfunc_epilog();

    /* end of function */
    tcc_debug_funcend(tcc_state, ind - func_ind);

    /* patch symbol size */
    elfsym(sym)->st_కొలత = ind - func_ind;
    cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం = ind;

    sym_తీయి(&local_దొంతర, ఖాళీ, 0);
    label_తీయి(&global_label_దొంతర, ఖాళీ, 0);
    sym_తీయి(&all_cleanups, ఖాళీ, 0);
    local_scope = 0;

    /* It's better to crash than to generate wrong code */
    cur_పాఠ్యం_section = ఖాళీ;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    func_ind = -1;
    nocode_wanted = దత్తాంశం_ONLY_WANTED;
    check_vstack();

    /* do this after funcend debug info */
    తదుపరి();
}

స్థిర శూన్య gen_inline_functions(TCCState *s)
{
    Sym *sym;
    పూర్ణాంకం inline_generated, i;
    నిర్మాణం InlineFunc *fn;

    tcc_open_bf(s, ":inline:", 0);
    /* iterate while inline function are referenced */
    చేయి {
        inline_generated = 0;
        కొరకు (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            ఒకవేళ (sym && (sym->c || !(sym->type.t & VT_INLINE))) {
                /* the function was used or forced (and then not internal):
                   generate its code and convert it to a normal function */
                fn->sym = ఖాళీ;
                tccpp_putfile(fn->filename);
                begin_macro(fn->func_str, 1);
                తదుపరి();
                cur_పాఠ్యం_section = పాఠ్యం_section;
                gen_function(sym);
                చివర_macro();

                inline_generated = 1;
            }
        }
    } అయితే (inline_generated);
    tcc_close();
}

స్థిర శూన్య free_inline_functions(TCCState *s)
{
    పూర్ణాంకం i;
    /* free tokens of unused inline functions */
    కొరకు (i = 0; i < s->nb_inline_fns; ++i) {
        నిర్మాణం InlineFunc *fn = s->inline_fns[i];
        ఒకవేళ (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

స్థిర శూన్య do_Static_assert(శూన్య)
{
    పూర్ణాంకం c;
    స్థిరరాశి అక్షరం *సందేశం;

    తదుపరి();
    skip('(');
    c = సమాసం_const();
    సందేశం = "_Static_assert fail";
    ఒకవేళ (tok == ',') {
        తదుపరి();
        సందేశం = parse_mult_str("string constant")->దత్తాంశం;
    }
    skip(')');
    ఒకవేళ (c == 0)
        tcc_error("%s", సందేశం);
    skip(';');
}

#నిర్వచితమైతే TCC_లక్ష్యం_PE
స్థిర శూన్య pe_check_linkage(CType *type, AttributeDef *ad)
{
    ఒకవేళ (!ad->a.dllimport && !ad->a.dllexport)
        తిరిగి;
    ఒకవేళ (type->t & VT_STATIC)
        tcc_error("cannot have dll linkage with static");
    ఒకవేళ (type->t & VT_TYPEDEF) {
        స్థిరరాశి అక్షరం *m = ad->a.dllimport ? "im" : "ex";
        tcc_warning("'dll%sport' attribute ignored for typedef", m);
        ad->a.dllimport = 0;
        ad->a.dllexport = 0;
    } లేకపోతే ఒకవేళ (ad->a.dllimport) {
        ఒకవేళ ((type->t & VT_BTYPE) == VT_FUNC)
            ad->a.dllimport = 0;
        లేకపోతే
            type->t |= VT_EXTERN;
    }
}
#అయితే_ముగింపు

/* 'l' is VT_LOCAL or VT_CONST to define default storage type
   or VT_CMP if parsing old style parameter list
   or VT_JMP if parsing c99 for decl: for (int i = 0, ...) */
స్థిర పూర్ణాంకం decl(పూర్ణాంకం l)
{
    పూర్ణాంకం v, has_init, r, oldint;
    CType type, btype;
    Sym *sym, *sa;
    AttributeDef ad, adbase;
    ElfSym *esym;

    అయితే (1) {

        oldint = 0;
        ఒకవేళ (!parse_btype(&btype, &adbase, l == VT_LOCAL)) {
            ఒకవేళ (l == VT_JMP)
                తిరిగి 0;
            /* skip redundant ';' if not in old parameter decl scope */
            ఒకవేళ (tok == ';' && l != VT_CMP) {
                తదుపరి();
                కొనసాగు;
            }
            ఒకవేళ (tok == TOK_STATIC_ASSERT) {
                do_Static_assert();
                కొనసాగు;
            }
            ఒకవేళ (l != VT_CONST)
                ఆపు;
            ఒకవేళ (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                కొనసాగు;
            }
            ఒకవేళ (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
                oldint = 1;
            } లేకపోతే {
                ఒకవేళ (tok != TOK_EOF)
                    expect("declaration");
                ఆపు;
            }
        }

        ఒకవేళ (tok == ';') {
            ఒకవేళ ((btype.t & VT_BTYPE) == VT_STRUCT
                && (btype.ref->v & ~SYM_STRUCT) < SYM_మొదటి_ANOM)
                ; /* struct decl with named tag */
            లేకపోతే ఒకవేళ (IS_ENUM(btype.t))
                ; /* enum decl */
            లేకపోతే
                tcc_warning("useless type defines no instances");
            ఒకవేళ (l == VT_JMP)
                తిరిగి 1;
            తదుపరి();
            కొనసాగు;
        }

        అయితే (1) { /* iterate thru each declaration */
            type = btype;
	    ad = adbase;
            type_decl(&type, &ad, &v, l == VT_CMP ? TYPE_ప్రత్యక్ష | TYPE_PARAM : TYPE_ప్రత్యక్ష);
            /*ptype("decl", &type, v);*/
            ఒకవేళ ((type.t & VT_BTYPE) == VT_FUNC) {
                ఒకవేళ ((type.t & VT_STATIC) && (l != VT_CONST))
                    tcc_error("function without file scope cannot be static");
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                ఒకవేళ (sym->f.func_type == FUNC_OLD && l == VT_CONST) {
                    func_vt = type;
		    ++local_scope;
                    decl(VT_CMP);
		    --local_scope;
                }
                ఒకవేళ ((type.t & (VT_EXTERN|VT_INLINE)) == (VT_EXTERN|VT_INLINE)) {
                    /* always_inline functions must be handled as if they
                       don't generate multiple global defs, even if extern
                       inline, i.e. GNU inline semantics for those.  Rewrite
                       them into static inline.  */
                    ఒకవేళ (tcc_state->gnu89_inline || sym->f.func_alwinl)
                        type.t = (type.t & ~VT_EXTERN) | VT_STATIC;
                    లేకపోతే
                        type.t &= ~VT_INLINE; /* always compile otherwise */
                }

            } లేకపోతే ఒకవేళ (oldint) {
                tcc_warning("type defaults to int");
            }

            ఒకవేళ (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
            #ఒకవేళ 0
                /* gcc does not allow __asm__("label") with function definition,
                   but why not ... */
                ఒకవేళ (tok == '{')
                    expect(";");
            #అయితే_ముగింపు
            }

#నిర్వచితమైతే TCC_లక్ష్యం_PE
            pe_check_linkage(&type, &ad);
#అయితే_ముగింపు
            ఒకవేళ (tok == '{') {
                ఒకవేళ (l != VT_CONST)
                    tcc_error("cannot use local functions");
                ఒకవేళ ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* apply post-declaraton attributes */
                విలీనం_funcattr(&type.ref->f, &ad.f);
                /* put function symbol */
                type.t &= ~VT_EXTERN;
                sym = external_sym(v, &type, 0, &ad);

                /* reject abstract declarators in function definition
                   make old-style float params double */
                కొరకు (sa = sym->type.ref; (sa = sa->తదుపరి) != ఖాళీ;) {
                    ఒకవేళ (!(sa->v & ~SYM_క్షేత్రం))
                        expect("identifier");
                    ఒకవేళ (sa->type.t == VT_FLOAT
                        && sym->type.ref->f.func_type == FUNC_OLD) {
                        sa->type.t = VT_DOUBLE;
                    }
                }

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                ఒకవేళ (sym->type.t & VT_INLINE) {
                    నిర్మాణం InlineFunc *fn;
                    fn = tcc_malloc(పరిమాణం *fn + అక్షరశ్రేణి_పొడవు(file->filename));
                    strcpy(fn->filename, file->filename);
                    fn->sym = sym;
                    dynarray_కూడు(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                    skip_or_save_ఖండం(&fn->func_str);
                } లేకపోతే {
                    /* compute text section */
                    cur_పాఠ్యం_section = పాఠ్యం_section;
                    ఒకవేళ (ad.section) {
                        cur_పాఠ్యం_section = ad.section;
                        ఒకవేళ (ad.new_section)
                            ad.section->sh_flags = పాఠ్యం_section->sh_flags;
                    }
                    gen_function(sym);
                }
                ఆపు;
            } లేకపోతే {
                has_init = 0;
		ఒకవేళ (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    కొరకు (sym = func_vt.ref->తదుపరి; sym; sym = sym->తదుపరి)
			ఒకవేళ ((sym->v & ~SYM_క్షేత్రం) == v)
			    వెళ్ళు దొరికింది;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, ఖాళీ));
                దొరికింది:
		    ఒకవేళ (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, ఖాళీ));
		    ఒకవేళ (!(sym->type.t & VT_EXTERN))
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, ఖాళీ));
		    convert_parameter_type(&type);
		    sym->type = type;
		} లేకపోతే ఒకవేళ (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_కనుగొను(v);
                    ఒకవేళ (sym && sym->sym_scope == local_scope) {
                        ఒకవేళ (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ఖాళీ));
                        sym->type = type;
                    } లేకపోతే {
                        sym = sym_నెట్టు(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    ఒకవేళ ((type.t & VT_BTYPE) == VT_FUNC)
                      విలీనం_funcattr(&sym->type.ref->f, &ad.f);
                    ఒకవేళ (debug_modes)
                        tcc_debug_typedef (tcc_state, sym);
		} లేకపోతే ఒకవేళ ((type.t & VT_BTYPE) == VT_VOID
			   && !(type.t & VT_EXTERN)) {
		    tcc_error("declaration of void object");
                } లేకపోతే {
                    r = 0;
                    ఒకవేళ ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        విలీనం_funcattr(&type.ref->f, &ad.f);
                    } లేకపోతే ఒకవేళ (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= VT_LVAL;
                    }

                    ఒకవేళ (tok == '=')
                        has_init = 1;

                    ఒకవేళ (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST))
		        || (type.t & VT_BTYPE) == VT_FUNC
                        /* as with GCC, uninitialized global arrays with no size
                           are considered extern: */
                        || ((type.t & VT_ARRAY) && !has_init
                            && l == VT_CONST && type.ref->c < 0)
                        ) {
                        /* external variable or function */
                        type.t |= VT_EXTERN;
                        external_sym(v, &type, r, &ad);
                    } లేకపోతే {
                        ఒకవేళ (l == VT_CONST || (type.t & VT_STATIC))
                            r |= VT_CONST;
                        లేకపోతే
                            r |= VT_LOCAL;
                        type.t &= ~VT_EXTERN;
                        ఒకవేళ (has_init)
                            తదుపరి();
                        లేకపోతే ఒకవేళ (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }

                    ఒకవేళ (ad.alias_లక్ష్యం && l == VT_CONST) {
                        /* Aliases need to be emitted when their target symbol
                           is emitted, even if perhaps unreferenced.
                           We only support the case where the base is already
                           defined, otherwise we would need deferring to emit
                           the aliases until the end of the compile unit.  */
                        esym = elfsym(sym_కనుగొను(ad.alias_లక్ష్యం));
                        ఒకవేళ (!esym)
                            tcc_error("unsupported forward __alias__ attribute");
                        put_extern_sym2(sym_కనుగొను(v), esym->st_shndx,
                                        esym->st_విలువ, esym->st_కొలత, 1);
                    }
                }
                ఒకవేళ (tok != ',') {
                    ఒకవేళ (l == VT_JMP)
                        తిరిగి has_init ? v : 1;
                    skip(';');
                    ఆపు;
                }
                తదుపరి();
            }
        }
    }
    తిరిగి 0;
}

/* ------------------------------------------------------------------------- */
#నిర్వచనం_రద్దు gjmp_addr
#నిర్వచనం_రద్దు gjmp
/* ------------------------------------------------------------------------- */
