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
static 整数 asmgoto_n;

static 整数 tcc_assemble_internal(TCCState *s1, 整数 do_preprocess, 整数 global);
static Sym* asm_new_label(TCCState *s1, 整数 label, 整数 is_local);
static Sym* asm_new_label1(TCCState *s1, 整数 label, 整数 is_local, 整数 sh_num, 整数 value);

#もし PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC void gen_addr64(整数 r, Sym *sym, int64_t c)
{
    もし (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC void gen_expr64(ExprValue *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

static 整数 asm_get_prefix_name(TCCState *s1, const char *prefix, unsigned 整数 n)
{
    char buf[64];
    snprintf(buf, sizeof(buf), "%s%u", prefix, n);
    戻る tok_alloc_const(buf);
}

ST_FUNC 整数 asm_get_local_label_name(TCCState *s1, unsigned 整数 n)
{
    戻る asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
static 整数 asm2cname(整数 v, 整数 *addeddot)
{
    const char *name;
    *addeddot = 0;
    もし (!tcc_state->leading_underscore)
      戻る v;
    name = get_tok_str(v, NULL);
    もし (!name)
      戻る v;
    もし (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } 否则 もし (!strchr(name, '.')) {
        char newname[256];
        snprintf(newname, sizeof newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    戻る v;
}

static Sym *asm_label_find(整数 v)
{
    Sym *sym;
    整数 addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    ながら (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    戻る sym;
}

static Sym *asm_label_push(整数 v)
{
    整数 addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_push(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    もし (addeddot)
        sym->asm_label = v;
    戻る sym;
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
ST_FUNC Sym* get_asm_sym(整数 name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    もし (!sym) {
	sym = asm_label_push(name);
	もし (csym)
	  sym->c = csym->c;
    }
    戻る sym;
}

static Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    char buf[100]; 整数 label; Sym *sym;
    snprintf(buf, sizeof buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    戻る sym ? sym : asm_new_label1(s1, label, 1, sec->sh_num, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

static void asm_expr_unary(TCCState *s1, ExprValue *pe)
{
    Sym *sym;
    整数 op, label;
    uint64_t n;
    const char *p;

    switch(tok) {
    case TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (char **)&p, 0);
        もし (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            もし (*p == 'b') {
                /* backward : find the last corresponding defined label */
                もし (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                もし (!sym)
                    tcc_error("local label '%d' not found backward", (整数)n);
            } 否则 {
                /* forward */
                もし (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_push(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } 否则 もし (*p == '\0') {
            pe->v = n;
            pe->sym = NULL;
	    pe->pcrel = 0;
        } 否则 {
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
        もし (pe->sym)
            tcc_error("invalid operation with label");
        もし (op == '-')
            pe->v = -pe->v;
        否则
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
        もし (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, NULL);
	    esym = elfsym(sym);
            もし (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_value;
                pe->sym = NULL;
		pe->pcrel = 0;
            } 否则 {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } 否则 {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        break;
    }
}
    
static void asm_expr_prod(TCCState *s1, ExprValue *pe)
{
    整数 op;
    ExprValue e2;

    asm_expr_unary(s1, pe);
    ために(;;) {
        op = tok;
        もし (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            break;
        next();
        asm_expr_unary(s1, &e2);
        もし (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
        case '*':
            pe->v *= e2.v;
            break;
        case '/':  
            もし (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            break;
        case '%':  
            もし (e2.v == 0)
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
    整数 op;
    ExprValue e2;

    asm_expr_prod(s1, pe);
    ために(;;) {
        op = tok;
        もし (op != '&' && op != '|' && op != '^')
            break;
        next();
        asm_expr_prod(s1, &e2);
        もし (pe->sym || e2.sym)
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
    整数 op;
    ExprValue e2;

    asm_expr_logic(s1, pe);
    ために(;;) {
        op = tok;
        もし (op != '+' && op != '-')
            break;
        next();
        asm_expr_logic(s1, &e2);
        もし (op == '+') {
            もし (pe->sym != NULL && e2.sym != NULL)
                goto cannot_relocate;
            pe->v += e2.v;
            もし (pe->sym == NULL && e2.sym != NULL)
                pe->sym = e2.sym;
        } 否则 {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    もし (!e2.sym) {
		/* OK */
	    } 否则 もし (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = NULL; /* same symbols can be subtracted to NULL */
	    } 否则 {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		もし (!esym2)
		    goto cannot_relocate;
		もし (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (整数)(esym1->st_value - esym2->st_value);
		    pe->sym = NULL;
		} 否则 もし (esym2->st_shndx == cur_text_section->sh_num) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (整数)(0 - esym2->st_value);
		    pe->pcrel = 1;
		    e2.sym = NULL;
		} 否则 {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

static inline void asm_expr_cmp(TCCState *s1, ExprValue *pe)
{
    整数 op;
    ExprValue e2;

    asm_expr_sum(s1, pe);
    ために(;;) {
        op = tok;
	もし (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            break;
        next();
        asm_expr_sum(s1, &e2);
        もし (pe->sym || e2.sym)
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

ST_FUNC 整数 asm_int_expr(TCCState *s1)
{
    ExprValue e;
    asm_expr(s1, &e);
    もし (e.sym)
        expect("constant");
    もし ((整数)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    戻る e.v;
}

static Sym* asm_new_label1(TCCState *s1, 整数 label, 整数 is_local,
                           整数 sh_num, 整数 value)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    もし (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        もし (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            もし (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                goto new_label;
            もし (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, NULL));
        }
    } 否则 {
    new_label:
        sym = asm_label_push(label);
    }
    もし (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_num;
    esym->st_value = value;
    もし (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    戻る sym;
}

static Sym* asm_new_label(TCCState *s1, 整数 label, 整数 is_local)
{
    戻る asm_new_label1(s1, label, is_local, cur_text_section->sh_num, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
static Sym* set_symbol(TCCState *s1, 整数 label)
{
    long n;
    ExprValue e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_expr(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    もし (esym)
	n += esym->st_value;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    戻る sym;
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
    もし (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = NULL;
    use_section1(s1, prev);
}

static void asm_parse_directive(TCCState *s1, 整数 global)
{
    整数 n, offset, v, size, tok1, c;
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
        もし (tok1 == TOK_ASMDIR_p2align)
        {
            もし (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        もし (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            もし (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            もし (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } 否则 {
	    もし (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        もし (tok == ',') {
            next();
            v = asm_int_expr(s1), c = 0;
        }
    zero_pad:
	もし ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        もし (sec->sh_type != SHT_NOBITS) {
            もし (c) {
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
#もし PTR_SIZE == 8
	size = 8;
	goto asm_data;
#否则
        next();
        ために(;;) {
            uint64_t vl;
            const char *p;

            p = tokc.str.data;
            もし (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (char **)&p, 0);
            もし (*p != '\0')
                goto error_constant;
            next();
            もし (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } 否则 {
                ind += 8;
            }
            もし (tok != ',')
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
        ために(;;) {
            ExprValue e;
            asm_expr(s1, &e);
            もし (sec->sh_type != SHT_NOBITS) {
                もし (size == 4) {
                    gen_expr32(&e);
#もし PTR_SIZE == 8
		} 否则 もし (size == 8) {
		    gen_expr64(&e);
#endif
                } 否则 {
                    もし (e.sym)
                        expect("constant");
                    もし (size == 1)
                        g(e.v);
                    否则
                        gen_le16(e.v);
                }
            } 否则 {
                ind += size;
            }
            もし (tok != ',')
                break;
            next();
        }
        break;
    case TOK_ASMDIR_fill:
        {
            整数 repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_expr(s1);
            もし (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                break;
            }
            size = 1;
            val = 0;
            もし (tok == ',') {
                next();
                size = asm_int_expr(s1);
                もし (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    break;
                }
                もし (size > 8)
                    size = 8;
                もし (tok == ',') {
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
            ために(i = 0; i < repeat; i++) {
                ために(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        break;
    case TOK_ASMDIR_rept:
        {
            整数 repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_expr(s1);
            init_str = tok_str_alloc();
            ながら (next(), tok != TOK_ASMDIR_endr) {
                もし (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ながら (repeat-- > 0) {
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
	    もし (esym) {
		もし (esym->st_shndx != cur_text_section->sh_num)
		  expect("constant or same-section symbol");
		n += esym->st_value;
	    }
            もし (n < ind)
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
	もし (tok == ',')
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
	    もし (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
	    もし (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            もし (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    否则 もし (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} ながら (tok == ',');
	break;
    case TOK_ASMDIR_string:
    case TOK_ASMDIR_ascii:
    case TOK_ASMDIR_asciz:
        {
            const char *p;
            整数 i, size, t;

            t = tok;
            next();
            ために(;;) {
                もし (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                もし (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                ために(i = 0; i < size; i++)
                    g(p[i]);
                next();
                もし (tok == ',') {
                    next();
                } 否则 もし (tok != TOK_STR) {
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
            もし (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_expr(s1);
		next();
            }
            もし (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, NULL), n);
            否则
                sprintf(sname, "%s", get_tok_str(tok1, NULL));
            use_section(s1, sname);
	}
	break;
    case TOK_ASMDIR_file:
        {
            const char *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            もし (tok == TOK_PPNUM)
                next();
            もし (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } 否则 もし (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } 否则 {
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
            もし (tok == TOK_STR)
                pstrcat(ident, sizeof(ident), tokc.str.data);
            否则
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
	    もし (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            もし (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, NULL));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, NULL));
            next();
            skip(',');
            n = asm_int_expr(s1);
            esym = elfsym(sym);
            もし (esym) {
                esym->st_size = n;
            }
        }
        break;
    case TOK_ASMDIR_type:
        { 
            Sym *sym;
            const char *newtype;
            整数 st_type;

            next();
	    もし (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
            next();
            skip(',');
            もし (tok == TOK_STR) {
                newtype = tokc.str.data;
            } 否则 {
                もし (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, NULL);
            }

            もし (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                もし (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                もし (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } 否则 もし (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                goto set_st_type;
            } 否则
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, NULL), sym->type.t, newtype);

            next();
        }
        break;
    case TOK_ASMDIR_pushsection:
    case TOK_ASMDIR_section:
        {
            char sname[256];
	    整数 old_nb_section = s1->nb_sections;
            整数 flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            ながら (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                もし (tok == TOK_STR)
                    pstrcat(sname, sizeof(sname), tokc.str.data);
                否则
                    pstrcat(sname, sizeof(sname), get_tok_str(tok, NULL));
                next();
            }
            もし (tok == ',') {
                const char *p;
                /* skip section options */
                next();
                もし (tok != TOK_STR)
                    expect("string constant");
                ために (p = tokc.str.data; *p; ++p) {
                    もし (*p == 'w')
                        flags |= SHF_WRITE;
                    もし (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                もし (tok == ',') {
                    next();
                    もし (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    もし (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    否则
	        push_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    もし (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                もし (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        break;
    case TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            もし (!last_text_section)
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
#もし PTR_SIZE == 8
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
	    整数 reloc_type = -1;

	    next();
	    asm_expr(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, NULL);
#もし defined(TCC_TARGET_ARM64)
	    もし (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#elif defined(TCC_TARGET_RISCV64)
	    もし (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    否则 もし (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    もし (reloc_type < 0)
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
static 整数 tcc_assemble_internal(TCCState *s1, 整数 do_preprocess, 整数 global)
{
    整数 opcode;
    整数 saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    もし (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    ために(;;) {
        next();
        もし (tok == TOK_EOF)
            break;
        tcc_debug_line(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#もし !defined(TCC_TARGET_ARM64)
        もし (tok == '#') {
            /* horrible gas comment */
            ながら (tok != TOK_LINEFEED)
                next();
        } 否则
#endif
        もし (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } 否则 もし (tok == TOK_PPNUM) {
            const char *p;
            整数 n;
            p = tokc.str.data;
            n = strtoul(p, (char **)&p, 10);
            もし (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            goto redo;
        } 否则 もし (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            もし (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                goto redo;
            } 否则 もし (tok == '=') {
		set_symbol(s1, opcode);
                goto redo;
            } 否则 {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        もし (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    戻る 0;
}

/* Assemble the current file */
ST_FUNC 整数 tcc_assemble(TCCState *s1, 整数 do_preprocess)
{
    整数 ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    戻る ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
static void tcc_assemble_inline(TCCState *s1, const char *str, 整数 len, 整数 global)
{
    const 整数 *saved_macro_ptr = macro_ptr;
    整数 dotid = set_idnum('.', IS_ID);
#もし !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    整数 dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = NULL;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#もし !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC 整数 find_constraint(ASMOperand *operands, 整数 nb_operands, 
                           const char *name, const char **pp)
{
    整数 index;
    TokenSym *ts;
    const char *p;

    もし (isnum(*name)) {
        index = 0;
        ながら (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        もし ((unsigned)index >= nb_operands)
            index = -1;
    } 否则 もし (*name == '[') {
        name++;
        p = strchr(name, ']');
        もし (p) {
            ts = tok_alloc(name, p - name);
            ために(index = 0; index < nb_operands; index++) {
                もし (operands[index].id == ts->tok)
                    goto found;
            }
            index = -1;
        found:
            name = p + 1;
        } 否则 {
            index = -1;
        }
    } 否则 {
        index = -1;
    }
    もし (pp)
        *pp = name;
    戻る index;
}

static void subst_asm_operands(ASMOperand *operands, 整数 nb_operands, 
                               CString *out_str, const char *str)
{
    整数 c, index, modifier;
    ASMOperand *op;
    SValue sv;

    ために(;;) {
        c = *str++;
        もし (c == '%') {
            もし (*str == '%') {
                str++;
                goto add_char;
            }
            modifier = 0;
            もし (*str == 'c' || *str == 'n' ||
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
            もし (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            もし (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, NULL), -1);
            } 否则 {
		もし (op->vt == NULL)
		    goto error;
                sv = *op->vt;
                もし (op->reg >= 0) {
                    sv.r = op->reg;
                    もし (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } 否则 {
        add_char:
            cstr_ccat(out_str, c);
            もし (c == '\0')
                break;
        }
    }
}


static void parse_asm_operands(ASMOperand *operands, 整数 *nb_operands_ptr,
                               整数 is_output)
{
    ASMOperand *op;
    整数 nb_operands;
    char* astr;

    もし (tok != ':') {
        nb_operands = *nb_operands_ptr;
        ために(;;) {
            もし (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            もし (tok == '[') {
                next();
                もし (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, sizeof op->constraint, astr);
            skip('(');
            gexpr();
            もし (is_output) {
                もし (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } 否则 {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                もし ((vtop->r & VT_LVAL) &&
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
            もし (tok == ',') {
                next();
            } 否则 {
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
    整数 nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ながら (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    もし (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        もし (tok == ':') {
            next();
            もし (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                もし (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    ために(;;) {
                        もし (tok == ':')
                          break;
                        もし (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        もし (tok == ',') {
                            next();
                        } 否则 {
                            break;
                        }
                    }
                }
                もし (tok == ':') {
                    /* goto labels */
                    next();
                    ために (;;) {
                        Sym *csym;
                        整数 asmname;
                        もし (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        もし (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       sizeof(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        もし (!csym) {
                            csym = label_push(&global_label_stack, tok,
                                              LABEL_FORWARD);
                        } 否则 {
                            もし (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        もし (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        もし (tok != ',')
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
    もし (tok != ';')
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
    もし (must_subst) {
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
    もし (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    ために(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC void asm_global_instr(void)
{
    CString *astr;
    整数 saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    もし (tok != ';')
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
#否则
ST_FUNC 整数 tcc_assemble(TCCState *s1, 整数 do_preprocess)
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
