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
static цяло asmgoto_n;

static цяло tcc_assemble_internal(TCCState *s1, цяло do_preprocess, цяло global);
static Sym* asm_new_label(TCCState *s1, цяло label, цяло is_local);
static Sym* asm_new_label1(TCCState *s1, цяло label, цяло is_local, цяло sh_num, цяло value);

#ако PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC void gen_addr64(цяло r, Sym *sym, int64_t c)
{
    ако (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC void gen_expr64(ExprValue *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

static цяло asm_get_prefix_name(TCCState *s1, const char *prefix, unsigned цяло n)
{
    char buf[64];
    snprintf(buf, sizeof(buf), "%s%u", prefix, n);
    върни tok_alloc_const(buf);
}

ST_FUNC цяло asm_get_local_label_name(TCCState *s1, unsigned цяло n)
{
    върни asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
static цяло asm2cname(цяло v, цяло *addeddot)
{
    const char *name;
    *addeddot = 0;
    ако (!tcc_state->leading_underscore)
      върни v;
    name = get_tok_str(v, NULL);
    ако (!name)
      върни v;
    ако (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } иначе ако (!strchr(name, '.')) {
        char newname[256];
        snprintf(newname, sizeof newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    върни v;
}

static Sym *asm_label_find(цяло v)
{
    Sym *sym;
    цяло addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    докато (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    върни sym;
}

static Sym *asm_label_push(цяло v)
{
    цяло addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_push(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ако (addeddot)
        sym->asm_label = v;
    върни sym;
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
ST_FUNC Sym* get_asm_sym(цяло name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    ако (!sym) {
	sym = asm_label_push(name);
	ако (csym)
	  sym->c = csym->c;
    }
    върни sym;
}

static Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    char buf[100]; цяло label; Sym *sym;
    snprintf(buf, sizeof buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    върни sym ? sym : asm_new_label1(s1, label, 1, sec->sh_num, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

static void asm_expr_unary(TCCState *s1, ExprValue *pe)
{
    Sym *sym;
    цяло op, label;
    uint64_t n;
    const char *p;

    switch(tok) {
    case TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (char **)&p, 0);
        ако (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            ако (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ако (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ако (!sym)
                    tcc_error("local label '%d' not found backward", (цяло)n);
            } иначе {
                /* forward */
                ако (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_push(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } иначе ако (*p == '\0') {
            pe->v = n;
            pe->sym = NULL;
	    pe->pcrel = 0;
        } иначе {
            tcc_error("invalid number syntax");
        }
        next();
        break;
    case '+':
        next();
        asm_expr_unary(s1, pe);
        break;
    case '-':
    case '~':
        op = tok;
        next();
        asm_expr_unary(s1, pe);
        ако (pe->sym)
            tcc_error("invalid operation with label");
        ако (op == '-')
            pe->v = -pe->v;
        иначе
            pe->v = ~pe->v;
        break;
    case TOK_CCHAR:
    case TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = NULL;
	pe->pcrel = 0;
	next();
	break;
    case '(':
        next();
        asm_expr(s1, pe);
        skip(')');
        break;
    case '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        break;
    default:
        ако (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, NULL);
	    esym = elfsym(sym);
            ако (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_value;
                pe->sym = NULL;
		pe->pcrel = 0;
            } иначе {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } иначе {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        break;
    }
}
    
static void asm_expr_prod(TCCState *s1, ExprValue *pe)
{
    цяло op;
    ExprValue e2;

    asm_expr_unary(s1, pe);
    за(;;) {
        op = tok;
        ако (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            break;
        next();
        asm_expr_unary(s1, &e2);
        ако (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
        case '*':
            pe->v *= e2.v;
            break;
        case '/':  
            ако (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            break;
        case '%':  
            ако (e2.v == 0)
                goto div_error;
            pe->v %= e2.v;
            break;
        case TOK_SHL:
            pe->v <<= e2.v;
            break;
        default:
        case TOK_SAR:
            pe->v >>= e2.v;
            break;
        }
    }
}

static void asm_expr_logic(TCCState *s1, ExprValue *pe)
{
    цяло op;
    ExprValue e2;

    asm_expr_prod(s1, pe);
    за(;;) {
        op = tok;
        ако (op != '&' && op != '|' && op != '^')
            break;
        next();
        asm_expr_prod(s1, &e2);
        ако (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
        case '&':
            pe->v &= e2.v;
            break;
        case '|':  
            pe->v |= e2.v;
            break;
        default:
        case '^':
            pe->v ^= e2.v;
            break;
        }
    }
}

static inline void asm_expr_sum(TCCState *s1, ExprValue *pe)
{
    цяло op;
    ExprValue e2;

    asm_expr_logic(s1, pe);
    за(;;) {
        op = tok;
        ако (op != '+' && op != '-')
            break;
        next();
        asm_expr_logic(s1, &e2);
        ако (op == '+') {
            ако (pe->sym != NULL && e2.sym != NULL)
                goto cannot_relocate;
            pe->v += e2.v;
            ако (pe->sym == NULL && e2.sym != NULL)
                pe->sym = e2.sym;
        } иначе {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ако (!e2.sym) {
		/* OK */
	    } иначе ако (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = NULL; /* same symbols can be subtracted to NULL */
	    } иначе {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ако (!esym2)
		    goto cannot_relocate;
		ако (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (цяло)(esym1->st_value - esym2->st_value);
		    pe->sym = NULL;
		} иначе ако (esym2->st_shndx == cur_text_section->sh_num) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (цяло)(0 - esym2->st_value);
		    pe->pcrel = 1;
		    e2.sym = NULL;
		} иначе {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

static inline void asm_expr_cmp(TCCState *s1, ExprValue *pe)
{
    цяло op;
    ExprValue e2;

    asm_expr_sum(s1, pe);
    за(;;) {
        op = tok;
	ако (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            break;
        next();
        asm_expr_sum(s1, &e2);
        ако (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
	case TOK_EQ:
	    pe->v = pe->v == e2.v;
	    break;
	case TOK_NE:
	    pe->v = pe->v != e2.v;
	    break;
	case TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    break;
	case TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    break;
	case TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    break;
	case TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    break;
        default:
            break;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC void asm_expr(TCCState *s1, ExprValue *pe)
{
    asm_expr_cmp(s1, pe);
}

ST_FUNC цяло asm_int_expr(TCCState *s1)
{
    ExprValue e;
    asm_expr(s1, &e);
    ако (e.sym)
        expect("constant");
    ако ((цяло)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    върни e.v;
}

static Sym* asm_new_label1(TCCState *s1, цяло label, цяло is_local,
                           цяло sh_num, цяло value)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    ако (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ако (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ако (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                goto new_label;
            ако (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, NULL));
        }
    } иначе {
    new_label:
        sym = asm_label_push(label);
    }
    ако (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_num;
    esym->st_value = value;
    ако (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    върни sym;
}

static Sym* asm_new_label(TCCState *s1, цяло label, цяло is_local)
{
    върни asm_new_label1(s1, label, is_local, cur_text_section->sh_num, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
static Sym* set_symbol(TCCState *s1, цяло label)
{
    long n;
    ExprValue e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_expr(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ако (esym)
	n += esym->st_value;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    върни sym;
}

static void use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

static void use_section(TCCState *s1, const char *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

static void push_section(TCCState *s1, const char *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

static void pop_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    ако (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = NULL;
    use_section1(s1, prev);
}

static void asm_parse_directive(TCCState *s1, цяло global)
{
    цяло n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    switch(tok) {
    case TOK_ASMDIR_align:
    case TOK_ASMDIR_balign:
    case TOK_ASMDIR_p2align:
    case TOK_ASMDIR_skip:
    case TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_expr(s1);
        ако (tok1 == TOK_ASMDIR_p2align)
        {
            ако (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ако (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ако (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            ако (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } иначе {
	    ако (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        ако (tok == ',') {
            next();
            v = asm_int_expr(s1), c = 0;
        }
    zero_pad:
	ако ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        ако (sec->sh_type != SHT_NOBITS) {
            ако (c) {
                gen_fill_nops(size);
                break;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        break;
    case TOK_ASMDIR_quad:
#ако PTR_SIZE == 8
	size = 8;
	goto asm_data;
#иначе
        next();
        за(;;) {
            uint64_t vl;
            const char *p;

            p = tokc.str.data;
            ако (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (char **)&p, 0);
            ако (*p != '\0')
                goto error_constant;
            next();
            ако (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } иначе {
                ind += 8;
            }
            ако (tok != ',')
                break;
            next();
        }
        break;
#endif
    case TOK_ASMDIR_byte:
        size = 1;
        goto asm_data;
    case TOK_ASMDIR_word:
    case TOK_ASMDIR_short:
        size = 2;
        goto asm_data;
    case TOK_ASMDIR_long:
    case TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        за(;;) {
            ExprValue e;
            asm_expr(s1, &e);
            ако (sec->sh_type != SHT_NOBITS) {
                ако (size == 4) {
                    gen_expr32(&e);
#ако PTR_SIZE == 8
		} иначе ако (size == 8) {
		    gen_expr64(&e);
#endif
                } иначе {
                    ако (e.sym)
                        expect("constant");
                    ако (size == 1)
                        g(e.v);
                    иначе
                        gen_le16(e.v);
                }
            } иначе {
                ind += size;
            }
            ако (tok != ',')
                break;
            next();
        }
        break;
    case TOK_ASMDIR_fill:
        {
            цяло repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_expr(s1);
            ако (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                break;
            }
            size = 1;
            val = 0;
            ако (tok == ',') {
                next();
                size = asm_int_expr(s1);
                ако (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    break;
                }
                ако (size > 8)
                    size = 8;
                ако (tok == ',') {
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
            за(i = 0; i < repeat; i++) {
                за(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        break;
    case TOK_ASMDIR_rept:
        {
            цяло repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_expr(s1);
            init_str = tok_str_alloc();
            докато (next(), tok != TOK_ASMDIR_endr) {
                ако (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            докато (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            break;
        }
    case TOK_ASMDIR_org:
        {
	    ExprValue e;
	    ElfSym *esym;
            next();
	    asm_expr(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    ако (esym) {
		ако (esym->st_shndx != cur_text_section->sh_num)
		  expect("constant or same-section symbol");
		n += esym->st_value;
	    }
            ако (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            goto zero_pad;
        }
        break;
    case TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	ако (tok == ',')
	    set_symbol(s1, tok1);
	break;
    case TOK_ASMDIR_globl:
    case TOK_ASMDIR_global:
    case TOK_ASMDIR_weak:
    case TOK_ASMDIR_hidden:
	tok1 = tok;
	do { 
            Sym *sym;
            next();
	    ако (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
	    ако (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ако (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    иначе ако (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} докато (tok == ',');
	break;
    case TOK_ASMDIR_string:
    case TOK_ASMDIR_ascii:
    case TOK_ASMDIR_asciz:
        {
            const char *p;
            цяло i, size, t;

            t = tok;
            next();
            за(;;) {
                ако (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                ако (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                за(i = 0; i < size; i++)
                    g(p[i]);
                next();
                ако (tok == ',') {
                    next();
                } иначе ако (tok != TOK_STR) {
                    break;
                }
            }
	}
	break;
    case TOK_ASMDIR_text:
    case TOK_ASMDIR_data:
    case TOK_ASMDIR_bss:
	{ 
            char sname[64];
            tok1 = tok;
            n = 0;
            next();
            ако (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_expr(s1);
		next();
            }
            ако (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, NULL), n);
            иначе
                sprintf(sname, "%s", get_tok_str(tok1, NULL));
            use_section(s1, sname);
	}
	break;
    case TOK_ASMDIR_file:
        {
            const char *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            ако (tok == TOK_PPNUM)
                next();
            ако (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } иначе ако (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } иначе {
                skip_to_eol(0);
                break;
            }
            tccpp_putfile(p);
            next();
        }
        break;
    case TOK_ASMDIR_ident:
        {
            char ident[256];

            ident[0] = '\0';
            next();
            ако (tok == TOK_STR)
                pstrcat(ident, sizeof(ident), tokc.str.data);
            иначе
                pstrcat(ident, sizeof(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        break;
    case TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    ако (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            ако (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, NULL));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, NULL));
            next();
            skip(',');
            n = asm_int_expr(s1);
            esym = elfsym(sym);
            ако (esym) {
                esym->st_size = n;
            }
        }
        break;
    case TOK_ASMDIR_type:
        { 
            Sym *sym;
            const char *newtype;
            цяло st_type;

            next();
	    ако (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
            next();
            skip(',');
            ако (tok == TOK_STR) {
                newtype = tokc.str.data;
            } иначе {
                ако (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, NULL);
            }

            ако (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ако (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                ако (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } иначе ако (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                goto set_st_type;
            } иначе
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, NULL), sym->type.t, newtype);

            next();
        }
        break;
    case TOK_ASMDIR_pushsection:
    case TOK_ASMDIR_section:
        {
            char sname[256];
	    цяло old_nb_section = s1->nb_sections;
            цяло flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            докато (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ако (tok == TOK_STR)
                    pstrcat(sname, sizeof(sname), tokc.str.data);
                иначе
                    pstrcat(sname, sizeof(sname), get_tok_str(tok, NULL));
                next();
            }
            ако (tok == ',') {
                const char *p;
                /* skip section options */
                next();
                ако (tok != TOK_STR)
                    expect("string constant");
                за (p = tokc.str.data; *p; ++p) {
                    ако (*p == 'w')
                        flags |= SHF_WRITE;
                    ако (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                ако (tok == ',') {
                    next();
                    ако (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    ако (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    иначе
	        push_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ако (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ако (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        break;
    case TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            ако (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        break;
    case TOK_ASMDIR_popsection:
	next();
	pop_section(s1);
	break;
#ifdef TCC_TARGET_I386
    case TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        break;
    case TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        break;
#endif
#ако PTR_SIZE == 8
    /* added for compatibility with GAS */
    case TOK_ASMDIR_code64:
        next();
        break;
#endif
#ifdef TCC_TARGET_RISCV64
    case TOK_ASMDIR_option:
        next();
        switch(tok){
            case TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            case TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            case TOK_ASM_pic:
            case TOK_ASM_nopic:
            case TOK_ASM_relax:
            case TOK_ASM_norelax:
            case TOK_ASM_push:
            case TOK_ASM_pop:
                /* TODO: unimplemented */
                next();
                break;
            case TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, NULL));
                break;
            default:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, NULL));
                break;
        }
        break;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    case TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	break;
    case TOK_ASMDIR_reloc:
	{
	    ExprValue e;
	    const char *reloc_name;
	    цяло reloc_type = -1;

	    next();
	    asm_expr(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, NULL);
#ако defined(TCC_TARGET_ARM64)
	    ако (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#elif defined(TCC_TARGET_RISCV64)
	    ако (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    иначе ако (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    ако (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, NULL), e.v, reloc_type, 0);
	    next();
	}
	break;
    default:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, NULL));
        break;
    }
}


/* assemble a file */
static цяло tcc_assemble_internal(TCCState *s1, цяло do_preprocess, цяло global)
{
    цяло opcode;
    цяло saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ако (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    за(;;) {
        next();
        ако (tok == TOK_EOF)
            break;
        tcc_debug_line(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ако !defined(TCC_TARGET_ARM64)
        ако (tok == '#') {
            /* horrible gas comment */
            докато (tok != TOK_LINEFEED)
                next();
        } иначе
#endif
        ако (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } иначе ако (tok == TOK_PPNUM) {
            const char *p;
            цяло n;
            p = tokc.str.data;
            n = strtoul(p, (char **)&p, 10);
            ако (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            goto redo;
        } иначе ако (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            ако (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                goto redo;
            } иначе ако (tok == '=') {
		set_symbol(s1, opcode);
                goto redo;
            } иначе {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ако (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    върни 0;
}

/* Assemble the current file */
ST_FUNC цяло tcc_assemble(TCCState *s1, цяло do_preprocess)
{
    цяло ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    върни ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
static void tcc_assemble_inline(TCCState *s1, const char *str, цяло len, цяло global)
{
    const цяло *saved_macro_ptr = macro_ptr;
    цяло dotid = set_idnum('.', IS_ID);
#ако !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    цяло dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = NULL;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#ако !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC цяло find_constraint(ASMOperand *operands, цяло nb_operands, 
                           const char *name, const char **pp)
{
    цяло index;
    TokenSym *ts;
    const char *p;

    ако (isnum(*name)) {
        index = 0;
        докато (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        ако ((unsigned)index >= nb_operands)
            index = -1;
    } иначе ако (*name == '[') {
        name++;
        p = strchr(name, ']');
        ако (p) {
            ts = tok_alloc(name, p - name);
            за(index = 0; index < nb_operands; index++) {
                ако (operands[index].id == ts->tok)
                    goto found;
            }
            index = -1;
        found:
            name = p + 1;
        } иначе {
            index = -1;
        }
    } иначе {
        index = -1;
    }
    ако (pp)
        *pp = name;
    върни index;
}

static void subst_asm_operands(ASMOperand *operands, цяло nb_operands, 
                               CString *out_str, const char *str)
{
    цяло c, index, modifier;
    ASMOperand *op;
    SValue sv;

    за(;;) {
        c = *str++;
        ако (c == '%') {
            ако (*str == '%') {
                str++;
                goto add_char;
            }
            modifier = 0;
            ако (*str == 'c' || *str == 'n' ||
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
            ако (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            ако (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, NULL), -1);
            } иначе {
		ако (op->vt == NULL)
		    goto error;
                sv = *op->vt;
                ако (op->reg >= 0) {
                    sv.r = op->reg;
                    ако (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } иначе {
        add_char:
            cstr_ccat(out_str, c);
            ако (c == '\0')
                break;
        }
    }
}


static void parse_asm_operands(ASMOperand *operands, цяло *nb_operands_ptr,
                               цяло is_output)
{
    ASMOperand *op;
    цяло nb_operands;
    char* astr;

    ако (tok != ':') {
        nb_operands = *nb_operands_ptr;
        за(;;) {
            ако (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ако (tok == '[') {
                next();
                ако (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, sizeof op->constraint, astr);
            skip('(');
            gexpr();
            ако (is_output) {
                ако (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } иначе {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ако ((vtop->r & VT_LVAL) &&
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
            ако (tok == ',') {
                next();
            } иначе {
                break;
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
    цяло nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    докато (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, sizeof(clobber_regs));
    ако (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ако (tok == ':') {
            next();
            ако (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ако (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    за(;;) {
                        ако (tok == ':')
                          break;
                        ако (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        ако (tok == ',') {
                            next();
                        } иначе {
                            break;
                        }
                    }
                }
                ако (tok == ':') {
                    /* goto labels */
                    next();
                    за (;;) {
                        Sym *csym;
                        цяло asmname;
                        ако (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ако (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       sizeof(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        ако (!csym) {
                            csym = label_push(&global_label_stack, tok,
                                              LABEL_FORWARD);
                        } иначе {
                            ако (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ако (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ако (tok != ',')
                          break;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ако (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (char *)astr.data);
#endif
    ако (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (char *)astr.data);
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
    ако (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    за(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC void asm_global_instr(void)
{
    CString *astr;
    цяло saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ако (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (char *)astr->data);
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
#иначе
ST_FUNC цяло tcc_assemble(TCCState *s1, цяло do_preprocess)
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
