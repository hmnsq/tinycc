/*
 *  GAS like assembler for TCC
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
#ifdef CONFIG_TCC_ASM

static Section *last_text_section; /* to handle .previous asm directive */
static පූර්ණ_සංඛ්‍යා asmgoto_n;

static පූර්ණ_සංඛ්‍යා tcc_assemble_internal(TCCState *s1, පූර්ණ_සංඛ්‍යා do_preprocess, පූර්ණ_සංඛ්‍යා global);
static Sym* asm_new_label(TCCState *s1, පූර්ණ_සංඛ්‍යා label, පූර්ණ_සංඛ්‍යා is_local);
static Sym* asm_new_label1(TCCState *s1, පූර්ණ_සංඛ්‍යා label, පූර්ණ_සංඛ්‍යා is_local, පූර්ණ_සංඛ්‍යා sh_num, පූර්ණ_සංඛ්‍යා value);

#නම් PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC void gen_addr64(පූර්ණ_සංඛ්‍යා r, Sym *sym, int64_t c)
{
    නම් (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC void gen_expr64(ExprValue *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

static පූර්ණ_සංඛ්‍යා asm_get_prefix_name(TCCState *s1, const var_na *prefix, unsigned පූර්ණ_සංඛ්‍යා n)
{
    var_na buf[64];
    snprintf(buf, parimaa_na(buf), "%s%u", prefix, n);
    ආපසු tok_alloc_const(buf);
}

ST_FUNC පූර්ණ_සංඛ්‍යා asm_get_local_label_name(TCCState *s1, unsigned පූර්ණ_සංඛ්‍යා n)
{
    ආපසු asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
static පූර්ණ_සංඛ්‍යා asm2cname(පූර්ණ_සංඛ්‍යා v, පූර්ණ_සංඛ්‍යා *addeddot)
{
    const var_na *name;
    *addeddot = 0;
    නම් (!tcc_state->leading_underscore)
      ආපසු v;
    name = get_tok_str(v, NULL);
    නම් (!name)
      ආපසු v;
    නම් (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } නැතහොත් නම් (!strchr(name, '.')) {
        var_na newname[256];
        snprintf(newname, parimaa_na newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ආපසු v;
}

static Sym *asm_label_find(පූර්ණ_සංඛ්‍යා v)
{
    Sym *sym;
    පූර්ණ_සංඛ්‍යා addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    අතරතුර (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    ආපසු sym;
}

static Sym *asm_label_push(පූර්ණ_සංඛ්‍යා v)
{
    පූර්ණ_සංඛ්‍යා addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_push(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    නම් (addeddot)
        sym->asm_label = v;
    ආපසු sym;
}

/* Return a symbol we can use inside the assembler, having name NAME.
   Symbols from asm and C source share a namespace.  If we generate
   an asm symbol it's also a (file-global) C symbol, but it's
   either not accessible by name (like "L.123"), or its type information
   is such that it's not usable without a proper C declaration.

   Sometimes we need symbols accessible by name from asm, which
   are anonymous in C, in this case CSYM can be used to transfer
   all information from that symbol to the (possibly newly created)
   asm symbol.  */
ST_FUNC Sym* get_asm_sym(පූර්ණ_සංඛ්‍යා name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    නම් (!sym) {
	sym = asm_label_push(name);
	නම් (csym)
	  sym->c = csym->c;
    }
    ආපසු sym;
}

static Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    var_na buf[100]; පූර්ණ_සංඛ්‍යා label; Sym *sym;
    snprintf(buf, parimaa_na buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    ආපසු sym ? sym : asm_new_label1(s1, label, 1, sec->sh_num, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

static void asm_expr_unary(TCCState *s1, ExprValue *pe)
{
    Sym *sym;
    පූර්ණ_සංඛ්‍යා op, label;
    uint64_t n;
    const var_na *p;

    switch(tok) {
    pak_sa TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (var_na **)&p, 0);
        නම් (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            නම් (*p == 'b') {
                /* backward : find the last corresponding defined label */
                නම් (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                නම් (!sym)
                    tcc_error("local label '%d' not found backward", (පූර්ණ_සංඛ්‍යා)n);
            } නැතහොත් {
                /* forward */
                නම් (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_push(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } නැතහොත් නම් (*p == '\0') {
            pe->v = n;
            pe->sym = NULL;
	    pe->pcrel = 0;
        } නැතහොත් {
            tcc_error("invalid number syntax");
        }
        next();
        bha_nga;
    pak_sa '+':
        next();
        asm_expr_unary(s1, pe);
        bha_nga;
    pak_sa '-':
    pak_sa '~':
        op = tok;
        next();
        asm_expr_unary(s1, pe);
        නම් (pe->sym)
            tcc_error("invalid operation with label");
        නම් (op == '-')
            pe->v = -pe->v;
        නැතහොත්
            pe->v = ~pe->v;
        bha_nga;
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = NULL;
	pe->pcrel = 0;
	next();
	bha_nga;
    pak_sa '(':
        next();
        asm_expr(s1, pe);
        skip(')');
        bha_nga;
    pak_sa '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        bha_nga;
    default:
        නම් (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, NULL);
	    esym = elfsym(sym);
            නම් (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_value;
                pe->sym = NULL;
		pe->pcrel = 0;
            } නැතහොත් {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } නැතහොත් {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        bha_nga;
    }
}
    
static void asm_expr_prod(TCCState *s1, ExprValue *pe)
{
    පූර්ණ_සංඛ්‍යා op;
    ExprValue e2;

    asm_expr_unary(s1, pe);
    සඳහා(;;) {
        op = tok;
        නම් (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            bha_nga;
        next();
        asm_expr_unary(s1, &e2);
        නම් (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
        pak_sa '*':
            pe->v *= e2.v;
            bha_nga;
        pak_sa '/':  
            නම් (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            bha_nga;
        pak_sa '%':  
            නම් (e2.v == 0)
                goto div_error;
            pe->v %= e2.v;
            bha_nga;
        pak_sa TOK_SHL:
            pe->v <<= e2.v;
            bha_nga;
        default:
        pak_sa TOK_SAR:
            pe->v >>= e2.v;
            bha_nga;
        }
    }
}

static void asm_expr_logic(TCCState *s1, ExprValue *pe)
{
    පූර්ණ_සංඛ්‍යා op;
    ExprValue e2;

    asm_expr_prod(s1, pe);
    සඳහා(;;) {
        op = tok;
        නම් (op != '&' && op != '|' && op != '^')
            bha_nga;
        next();
        asm_expr_prod(s1, &e2);
        නම් (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
        pak_sa '&':
            pe->v &= e2.v;
            bha_nga;
        pak_sa '|':  
            pe->v |= e2.v;
            bha_nga;
        default:
        pak_sa '^':
            pe->v ^= e2.v;
            bha_nga;
        }
    }
}

static anta_hstha void asm_expr_sum(TCCState *s1, ExprValue *pe)
{
    පූර්ණ_සංඛ්‍යා op;
    ExprValue e2;

    asm_expr_logic(s1, pe);
    සඳහා(;;) {
        op = tok;
        නම් (op != '+' && op != '-')
            bha_nga;
        next();
        asm_expr_logic(s1, &e2);
        නම් (op == '+') {
            නම් (pe->sym != NULL && e2.sym != NULL)
                goto cannot_relocate;
            pe->v += e2.v;
            නම් (pe->sym == NULL && e2.sym != NULL)
                pe->sym = e2.sym;
        } නැතහොත් {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    නම් (!e2.sym) {
		/* OK */
	    } නැතහොත් නම් (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = NULL; /* same symbols can be subtracted to NULL */
	    } නැතහොත් {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		නම් (!esym2)
		    goto cannot_relocate;
		නම් (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (පූර්ණ_සංඛ්‍යා)(esym1->st_value - esym2->st_value);
		    pe->sym = NULL;
		} නැතහොත් නම් (esym2->st_shndx == cur_text_section->sh_num) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (පූර්ණ_සංඛ්‍යා)(0 - esym2->st_value);
		    pe->pcrel = 1;
		    e2.sym = NULL;
		} නැතහොත් {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

static anta_hstha void asm_expr_cmp(TCCState *s1, ExprValue *pe)
{
    පූර්ණ_සංඛ්‍යා op;
    ExprValue e2;

    asm_expr_sum(s1, pe);
    සඳහා(;;) {
        op = tok;
	නම් (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            bha_nga;
        next();
        asm_expr_sum(s1, &e2);
        නම් (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
	pak_sa TOK_EQ:
	    pe->v = pe->v == e2.v;
	    bha_nga;
	pak_sa TOK_NE:
	    pe->v = pe->v != e2.v;
	    bha_nga;
	pak_sa TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    bha_nga;
	pak_sa TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    bha_nga;
	pak_sa TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    bha_nga;
	pak_sa TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    bha_nga;
        default:
            bha_nga;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC void asm_expr(TCCState *s1, ExprValue *pe)
{
    asm_expr_cmp(s1, pe);
}

ST_FUNC පූර්ණ_සංඛ්‍යා asm_int_expr(TCCState *s1)
{
    ExprValue e;
    asm_expr(s1, &e);
    නම් (e.sym)
        expect("constant");
    නම් ((පූර්ණ_සංඛ්‍යා)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    ආපසු e.v;
}

static Sym* asm_new_label1(TCCState *s1, පූර්ණ_සංඛ්‍යා label, පූර්ණ_සංඛ්‍යා is_local,
                           පූර්ණ_සංඛ්‍යා sh_num, පූර්ණ_සංඛ්‍යා value)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    නම් (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        නම් (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            නම් (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                goto new_label;
            නම් (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, NULL));
        }
    } නැතහොත් {
    new_label:
        sym = asm_label_push(label);
    }
    නම් (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_num;
    esym->st_value = value;
    නම් (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    ආපසු sym;
}

static Sym* asm_new_label(TCCState *s1, පූර්ණ_සංඛ්‍යා label, පූර්ණ_සංඛ්‍යා is_local)
{
    ආපසු asm_new_label1(s1, label, is_local, cur_text_section->sh_num, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
static Sym* set_symbol(TCCState *s1, පූර්ණ_සංඛ්‍යා label)
{
    long n;
    ExprValue e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_expr(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    නම් (esym)
	n += esym->st_value;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    ආපසු sym;
}

static void use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

static void use_section(TCCState *s1, const var_na *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

static void push_section(TCCState *s1, const var_na *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

static void pop_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    නම් (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = NULL;
    use_section1(s1, prev);
}

static void asm_parse_directive(TCCState *s1, පූර්ණ_සංඛ්‍යා global)
{
    පූර්ණ_සංඛ්‍යා n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    switch(tok) {
    pak_sa TOK_ASMDIR_align:
    pak_sa TOK_ASMDIR_balign:
    pak_sa TOK_ASMDIR_p2align:
    pak_sa TOK_ASMDIR_skip:
    pak_sa TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_expr(s1);
        නම් (tok1 == TOK_ASMDIR_p2align)
        {
            නම් (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        නම් (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            නම් (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            නම් (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } නැතහොත් {
	    නම් (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        නම් (tok == ',') {
            next();
            v = asm_int_expr(s1), c = 0;
        }
    zero_pad:
	නම් ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        නම් (sec->sh_type != SHT_NOBITS) {
            නම් (c) {
                gen_fill_nops(size);
                bha_nga;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        bha_nga;
    pak_sa TOK_ASMDIR_quad:
#නම් PTR_SIZE == 8
	size = 8;
	goto asm_data;
#නැතහොත්
        next();
        සඳහා(;;) {
            uint64_t vl;
            const var_na *p;

            p = tokc.str.data;
            නම් (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (var_na **)&p, 0);
            නම් (*p != '\0')
                goto error_constant;
            next();
            නම් (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } නැතහොත් {
                ind += 8;
            }
            නම් (tok != ',')
                bha_nga;
            next();
        }
        bha_nga;
#endif
    pak_sa TOK_ASMDIR_byte:
        size = 1;
        goto asm_data;
    pak_sa TOK_ASMDIR_word:
    pak_sa TOK_ASMDIR_short:
        size = 2;
        goto asm_data;
    pak_sa TOK_ASMDIR_long:
    pak_sa TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        සඳහා(;;) {
            ExprValue e;
            asm_expr(s1, &e);
            නම් (sec->sh_type != SHT_NOBITS) {
                නම් (size == 4) {
                    gen_expr32(&e);
#නම් PTR_SIZE == 8
		} නැතහොත් නම් (size == 8) {
		    gen_expr64(&e);
#endif
                } නැතහොත් {
                    නම් (e.sym)
                        expect("constant");
                    නම් (size == 1)
                        g(e.v);
                    නැතහොත්
                        gen_le16(e.v);
                }
            } නැතහොත් {
                ind += size;
            }
            නම් (tok != ',')
                bha_nga;
            next();
        }
        bha_nga;
    pak_sa TOK_ASMDIR_fill:
        {
            පූර්ණ_සංඛ්‍යා repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_expr(s1);
            නම් (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                bha_nga;
            }
            size = 1;
            val = 0;
            නම් (tok == ',') {
                next();
                size = asm_int_expr(s1);
                නම් (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    bha_nga;
                }
                නම් (size > 8)
                    size = 8;
                නම් (tok == ',') {
                    next();
                    val = asm_int_expr(s1);
                }
            }
            /* XXX: endianness */
            repeat_buf[0] = val;
            repeat_buf[1] = val >> 8;
            repeat_buf[2] = val >> 16;
            repeat_buf[3] = val >> 24;
            repeat_buf[4] = 0;
            repeat_buf[5] = 0;
            repeat_buf[6] = 0;
            repeat_buf[7] = 0;
            සඳහා(i = 0; i < repeat; i++) {
                සඳහා(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        bha_nga;
    pak_sa TOK_ASMDIR_rept:
        {
            පූර්ණ_සංඛ්‍යා repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_expr(s1);
            init_str = tok_str_alloc();
            අතරතුර (next(), tok != TOK_ASMDIR_endr) {
                නම් (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            අතරතුර (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            bha_nga;
        }
    pak_sa TOK_ASMDIR_org:
        {
	    ExprValue e;
	    ElfSym *esym;
            next();
	    asm_expr(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    නම් (esym) {
		නම් (esym->st_shndx != cur_text_section->sh_num)
		  expect("constant or same-section symbol");
		n += esym->st_value;
	    }
            නම් (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            goto zero_pad;
        }
        bha_nga;
    pak_sa TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	නම් (tok == ',')
	    set_symbol(s1, tok1);
	bha_nga;
    pak_sa TOK_ASMDIR_globl:
    pak_sa TOK_ASMDIR_global:
    pak_sa TOK_ASMDIR_weak:
    pak_sa TOK_ASMDIR_hidden:
	tok1 = tok;
	do { 
            Sym *sym;
            next();
	    නම් (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
	    නම් (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            නම් (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    නැතහොත් නම් (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} අතරතුර (tok == ',');
	bha_nga;
    pak_sa TOK_ASMDIR_string:
    pak_sa TOK_ASMDIR_ascii:
    pak_sa TOK_ASMDIR_asciz:
        {
            const var_na *p;
            පූර්ණ_සංඛ්‍යා i, size, t;

            t = tok;
            next();
            සඳහා(;;) {
                නම් (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                නම් (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                සඳහා(i = 0; i < size; i++)
                    g(p[i]);
                next();
                නම් (tok == ',') {
                    next();
                } නැතහොත් නම් (tok != TOK_STR) {
                    bha_nga;
                }
            }
	}
	bha_nga;
    pak_sa TOK_ASMDIR_text:
    pak_sa TOK_ASMDIR_data:
    pak_sa TOK_ASMDIR_bss:
	{ 
            var_na sname[64];
            tok1 = tok;
            n = 0;
            next();
            නම් (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_expr(s1);
		next();
            }
            නම් (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, NULL), n);
            නැතහොත්
                sprintf(sname, "%s", get_tok_str(tok1, NULL));
            use_section(s1, sname);
	}
	bha_nga;
    pak_sa TOK_ASMDIR_file:
        {
            const var_na *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            නම් (tok == TOK_PPNUM)
                next();
            නම් (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } නැතහොත් නම් (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } නැතහොත් {
                skip_to_eol(0);
                bha_nga;
            }
            tccpp_putfile(p);
            next();
        }
        bha_nga;
    pak_sa TOK_ASMDIR_ident:
        {
            var_na ident[256];

            ident[0] = '\0';
            next();
            නම් (tok == TOK_STR)
                pstrcat(ident, parimaa_na(ident), tokc.str.data);
            නැතහොත්
                pstrcat(ident, parimaa_na(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        bha_nga;
    pak_sa TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    නම් (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            නම් (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, NULL));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, NULL));
            next();
            skip(',');
            n = asm_int_expr(s1);
            esym = elfsym(sym);
            නම් (esym) {
                esym->st_size = n;
            }
        }
        bha_nga;
    pak_sa TOK_ASMDIR_type:
        { 
            Sym *sym;
            const var_na *newtype;
            පූර්ණ_සංඛ්‍යා st_type;

            next();
	    නම් (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
            next();
            skip(',');
            නම් (tok == TOK_STR) {
                newtype = tokc.str.data;
            } නැතහොත් {
                නම් (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, NULL);
            }

            නම් (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                නම් (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                නම් (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } නැතහොත් නම් (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                goto set_st_type;
            } නැතහොත්
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, NULL), sym->type.t, newtype);

            next();
        }
        bha_nga;
    pak_sa TOK_ASMDIR_pushsection:
    pak_sa TOK_ASMDIR_section:
        {
            var_na sname[256];
	    පූර්ණ_සංඛ්‍යා old_nb_section = s1->nb_sections;
            පූර්ණ_සංඛ්‍යා flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            අතරතුර (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                නම් (tok == TOK_STR)
                    pstrcat(sname, parimaa_na(sname), tokc.str.data);
                නැතහොත්
                    pstrcat(sname, parimaa_na(sname), get_tok_str(tok, NULL));
                next();
            }
            නම් (tok == ',') {
                const var_na *p;
                /* skip section options */
                next();
                නම් (tok != TOK_STR)
                    expect("string constant");
                සඳහා (p = tokc.str.data; *p; ++p) {
                    නම් (*p == 'w')
                        flags |= SHF_WRITE;
                    නම් (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                නම් (tok == ',') {
                    next();
                    නම් (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    නම් (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    නැතහොත්
	        push_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    නම් (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                නම් (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        bha_nga;
    pak_sa TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            නම් (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        bha_nga;
    pak_sa TOK_ASMDIR_popsection:
	next();
	pop_section(s1);
	bha_nga;
#ifdef TCC_TARGET_I386
    pak_sa TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        bha_nga;
    pak_sa TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        bha_nga;
#endif
#නම් PTR_SIZE == 8
    /* added for compatibility with GAS */
    pak_sa TOK_ASMDIR_code64:
        next();
        bha_nga;
#endif
#ifdef TCC_TARGET_RISCV64
    pak_sa TOK_ASMDIR_option:
        next();
        switch(tok){
            pak_sa TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            pak_sa TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            pak_sa TOK_ASM_pic:
            pak_sa TOK_ASM_nopic:
            pak_sa TOK_ASM_relax:
            pak_sa TOK_ASM_norelax:
            pak_sa TOK_ASM_push:
            pak_sa TOK_ASM_pop:
                /* TODO: unimplemented */
                next();
                bha_nga;
            pak_sa TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, NULL));
                bha_nga;
            default:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, NULL));
                bha_nga;
        }
        bha_nga;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    pak_sa TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	bha_nga;
    pak_sa TOK_ASMDIR_reloc:
	{
	    ExprValue e;
	    const var_na *reloc_name;
	    පූර්ණ_සංඛ්‍යා reloc_type = -1;

	    next();
	    asm_expr(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, NULL);
#නම් defined(TCC_TARGET_ARM64)
	    නම් (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#elif defined(TCC_TARGET_RISCV64)
	    නම් (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    නැතහොත් නම් (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    නම් (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, NULL), e.v, reloc_type, 0);
	    next();
	}
	bha_nga;
    default:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, NULL));
        bha_nga;
    }
}


/* assemble a file */
static පූර්ණ_සංඛ්‍යා tcc_assemble_internal(TCCState *s1, පූර්ණ_සංඛ්‍යා do_preprocess, පූර්ණ_සංඛ්‍යා global)
{
    පූර්ණ_සංඛ්‍යා opcode;
    පූර්ණ_සංඛ්‍යා saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    නම් (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    සඳහා(;;) {
        next();
        නම් (tok == TOK_EOF)
            bha_nga;
        tcc_debug_line(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#නම් !defined(TCC_TARGET_ARM64)
        නම් (tok == '#') {
            /* horrible gas comment */
            අතරතුර (tok != TOK_LINEFEED)
                next();
        } නැතහොත්
#endif
        නම් (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } නැතහොත් නම් (tok == TOK_PPNUM) {
            const var_na *p;
            පූර්ණ_සංඛ්‍යා n;
            p = tokc.str.data;
            n = strtoul(p, (var_na **)&p, 10);
            නම් (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            goto redo;
        } නැතහොත් නම් (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            නම් (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                goto redo;
            } නැතහොත් නම් (tok == '=') {
		set_symbol(s1, opcode);
                goto redo;
            } නැතහොත් {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        නම් (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    ආපසු 0;
}

/* Assemble the current file */
ST_FUNC පූර්ණ_සංඛ්‍යා tcc_assemble(TCCState *s1, පූර්ණ_සංඛ්‍යා do_preprocess)
{
    පූර්ණ_සංඛ්‍යා ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    ආපසු ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
static void tcc_assemble_inline(TCCState *s1, const var_na *str, පූර්ණ_සංඛ්‍යා len, පූර්ණ_සංඛ්‍යා global)
{
    const පූර්ණ_සංඛ්‍යා *saved_macro_ptr = macro_ptr;
    පූර්ණ_සංඛ්‍යා dotid = set_idnum('.', IS_ID);
#නම් !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    පූර්ණ_සංඛ්‍යා dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = NULL;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#නම් !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC පූර්ණ_සංඛ්‍යා find_constraint(ASMOperand *operands, පූර්ණ_සංඛ්‍යා nb_operands, 
                           const var_na *name, const var_na **pp)
{
    පූර්ණ_සංඛ්‍යා index;
    TokenSym *ts;
    const var_na *p;

    නම් (isnum(*name)) {
        index = 0;
        අතරතුර (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        නම් ((unsigned)index >= nb_operands)
            index = -1;
    } නැතහොත් නම් (*name == '[') {
        name++;
        p = strchr(name, ']');
        නම් (p) {
            ts = tok_alloc(name, p - name);
            සඳහා(index = 0; index < nb_operands; index++) {
                නම් (operands[index].id == ts->tok)
                    goto found;
            }
            index = -1;
        found:
            name = p + 1;
        } නැතහොත් {
            index = -1;
        }
    } නැතහොත් {
        index = -1;
    }
    නම් (pp)
        *pp = name;
    ආපසු index;
}

static void subst_asm_operands(ASMOperand *operands, පූර්ණ_සංඛ්‍යා nb_operands, 
                               CString *out_str, const var_na *str)
{
    පූර්ණ_සංඛ්‍යා c, index, modifier;
    ASMOperand *op;
    SValue sv;

    සඳහා(;;) {
        c = *str++;
        නම් (c == '%') {
            නම් (*str == '%') {
                str++;
                goto add_char;
            }
            modifier = 0;
            නම් (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#ifdef TCC_TARGET_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#endif
#ifdef TCC_TARGET_RISCV64
		*str == 'z' ||
#endif
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            index = find_constraint(operands, nb_operands, str, &str);
            නම් (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            නම් (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, NULL), -1);
            } නැතහොත් {
		නම් (op->vt == NULL)
		    goto error;
                sv = *op->vt;
                නම් (op->reg >= 0) {
                    sv.r = op->reg;
                    නම් (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } නැතහොත් {
        add_char:
            cstr_ccat(out_str, c);
            නම් (c == '\0')
                bha_nga;
        }
    }
}


static void parse_asm_operands(ASMOperand *operands, පූර්ණ_සංඛ්‍යා *nb_operands_ptr,
                               පූර්ණ_සංඛ්‍යා is_output)
{
    ASMOperand *op;
    පූර්ණ_සංඛ්‍යා nb_operands;
    var_na* astr;

    නම් (tok != ':') {
        nb_operands = *nb_operands_ptr;
        සඳහා(;;) {
            නම් (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            නම් (tok == '[') {
                next();
                නම් (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, parimaa_na op->constraint, astr);
            skip('(');
            gexpr();
            නම් (is_output) {
                නම් (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } නැතහොත් {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                නම් ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#ifdef TCC_TARGET_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !strstr(op->constraint, "Ump")
#endif
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            නම් (tok == ',') {
                next();
            } නැතහොත් {
                bha_nga;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC void asm_instr(void)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    පූර්ණ_සංඛ්‍යා nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    අතරතුර (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        next();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->data, astr1->size);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, parimaa_na(clobber_regs));
    නම් (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        නම් (tok == ':') {
            next();
            නම් (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                නම් (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    සඳහා(;;) {
                        නම් (tok == ':')
                          bha_nga;
                        නම් (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        නම් (tok == ',') {
                            next();
                        } නැතහොත් {
                            bha_nga;
                        }
                    }
                }
                නම් (tok == ':') {
                    /* goto labels */
                    next();
                    සඳහා (;;) {
                        Sym *csym;
                        පූර්ණ_සංඛ්‍යා asmname;
                        නම් (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        නම් (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       parimaa_na(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        නම් (!csym) {
                            csym = label_push(&global_label_stack, tok,
                                              LABEL_FORWARD);
                        } නැතහොත් {
                            නම් (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        නම් (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        නම් (tok != ',')
                          bha_nga;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    නම් (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (var_na *)astr.data);
#endif
    නම් (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (var_na *)astr.data);
#endif

    /* generate loads */
    asm_gen_code(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, out_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_text_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.data, astr.size - 1, 0);
    cstr_free_s(&astr);
    නම් (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    සඳහා(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC void asm_global_instr(void)
{
    CString *astr;
    පූර්ණ_සංඛ්‍යා saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    නම් (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (var_na *)astr->data);
#endif
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->data, astr->size - 1, 1);
    
    cur_text_section->data_offset = ind;

    /* restore the current C token */
    next();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#නැතහොත්
ST_FUNC පූර්ණ_සංඛ්‍යා tcc_assemble(TCCState *s1, පූර්ණ_සංඛ්‍යා do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC void asm_instr(void)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC void asm_global_instr(void)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
