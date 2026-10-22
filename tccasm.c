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
static จำนวนเต็ม asmgoto_n;

static จำนวนเต็ม tcc_assemble_internal(TCCState *s1, จำนวนเต็ม do_preprocess, จำนวนเต็ม global);
static Sym* asm_new_label(TCCState *s1, จำนวนเต็ม label, จำนวนเต็ม is_local);
static Sym* asm_new_label1(TCCState *s1, จำนวนเต็ม label, จำนวนเต็ม is_local, จำนวนเต็ม sh_num, จำนวนเต็ม value);

#ถ้า PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC void gen_addr64(จำนวนเต็ม r, Sym *sym, int64_t c)
{
    ถ้า (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC void gen_expr64(ExprValue *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

static จำนวนเต็ม asm_get_prefix_name(TCCState *s1, const var_na *prefix, unsigned จำนวนเต็ม n)
{
    var_na buf[64];
    snprintf(buf, parimaa_na(buf), "%s%u", prefix, n);
    คืน tok_alloc_const(buf);
}

ST_FUNC จำนวนเต็ม asm_get_local_label_name(TCCState *s1, unsigned จำนวนเต็ม n)
{
    คืน asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
static จำนวนเต็ม asm2cname(จำนวนเต็ม v, จำนวนเต็ม *addeddot)
{
    const var_na *name;
    *addeddot = 0;
    ถ้า (!tcc_state->leading_underscore)
      คืน v;
    name = get_tok_str(v, NULL);
    ถ้า (!name)
      คืน v;
    ถ้า (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } มิฉะนั้น ถ้า (!strchr(name, '.')) {
        var_na newname[256];
        snprintf(newname, parimaa_na newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    คืน v;
}

static Sym *asm_label_find(จำนวนเต็ม v)
{
    Sym *sym;
    จำนวนเต็ม addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    ขณะ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    คืน sym;
}

static Sym *asm_label_push(จำนวนเต็ม v)
{
    จำนวนเต็ม addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_push(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ถ้า (addeddot)
        sym->asm_label = v;
    คืน sym;
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
ST_FUNC Sym* get_asm_sym(จำนวนเต็ม name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    ถ้า (!sym) {
	sym = asm_label_push(name);
	ถ้า (csym)
	  sym->c = csym->c;
    }
    คืน sym;
}

static Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    var_na buf[100]; จำนวนเต็ม label; Sym *sym;
    snprintf(buf, parimaa_na buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    คืน sym ? sym : asm_new_label1(s1, label, 1, sec->sh_num, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

static void asm_expr_unary(TCCState *s1, ExprValue *pe)
{
    Sym *sym;
    จำนวนเต็ม op, label;
    uint64_t n;
    const var_na *p;

    switch(tok) {
    pak_sa TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (var_na **)&p, 0);
        ถ้า (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            ถ้า (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ถ้า (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ถ้า (!sym)
                    tcc_error("local label '%d' not found backward", (จำนวนเต็ม)n);
            } มิฉะนั้น {
                /* forward */
                ถ้า (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_push(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } มิฉะนั้น ถ้า (*p == '\0') {
            pe->v = n;
            pe->sym = NULL;
	    pe->pcrel = 0;
        } มิฉะนั้น {
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
        ถ้า (pe->sym)
            tcc_error("invalid operation with label");
        ถ้า (op == '-')
            pe->v = -pe->v;
        มิฉะนั้น
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
        ถ้า (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, NULL);
	    esym = elfsym(sym);
            ถ้า (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_value;
                pe->sym = NULL;
		pe->pcrel = 0;
            } มิฉะนั้น {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } มิฉะนั้น {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        bha_nga;
    }
}
    
static void asm_expr_prod(TCCState *s1, ExprValue *pe)
{
    จำนวนเต็ม op;
    ExprValue e2;

    asm_expr_unary(s1, pe);
    สำหรับ(;;) {
        op = tok;
        ถ้า (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            bha_nga;
        next();
        asm_expr_unary(s1, &e2);
        ถ้า (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        switch(op) {
        pak_sa '*':
            pe->v *= e2.v;
            bha_nga;
        pak_sa '/':  
            ถ้า (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            bha_nga;
        pak_sa '%':  
            ถ้า (e2.v == 0)
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
    จำนวนเต็ม op;
    ExprValue e2;

    asm_expr_prod(s1, pe);
    สำหรับ(;;) {
        op = tok;
        ถ้า (op != '&' && op != '|' && op != '^')
            bha_nga;
        next();
        asm_expr_prod(s1, &e2);
        ถ้า (pe->sym || e2.sym)
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
    จำนวนเต็ม op;
    ExprValue e2;

    asm_expr_logic(s1, pe);
    สำหรับ(;;) {
        op = tok;
        ถ้า (op != '+' && op != '-')
            bha_nga;
        next();
        asm_expr_logic(s1, &e2);
        ถ้า (op == '+') {
            ถ้า (pe->sym != NULL && e2.sym != NULL)
                goto cannot_relocate;
            pe->v += e2.v;
            ถ้า (pe->sym == NULL && e2.sym != NULL)
                pe->sym = e2.sym;
        } มิฉะนั้น {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ถ้า (!e2.sym) {
		/* OK */
	    } มิฉะนั้น ถ้า (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = NULL; /* same symbols can be subtracted to NULL */
	    } มิฉะนั้น {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ถ้า (!esym2)
		    goto cannot_relocate;
		ถ้า (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (จำนวนเต็ม)(esym1->st_value - esym2->st_value);
		    pe->sym = NULL;
		} มิฉะนั้น ถ้า (esym2->st_shndx == cur_text_section->sh_num) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (จำนวนเต็ม)(0 - esym2->st_value);
		    pe->pcrel = 1;
		    e2.sym = NULL;
		} มิฉะนั้น {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

static anta_hstha void asm_expr_cmp(TCCState *s1, ExprValue *pe)
{
    จำนวนเต็ม op;
    ExprValue e2;

    asm_expr_sum(s1, pe);
    สำหรับ(;;) {
        op = tok;
	ถ้า (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            bha_nga;
        next();
        asm_expr_sum(s1, &e2);
        ถ้า (pe->sym || e2.sym)
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

ST_FUNC จำนวนเต็ม asm_int_expr(TCCState *s1)
{
    ExprValue e;
    asm_expr(s1, &e);
    ถ้า (e.sym)
        expect("constant");
    ถ้า ((จำนวนเต็ม)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    คืน e.v;
}

static Sym* asm_new_label1(TCCState *s1, จำนวนเต็ม label, จำนวนเต็ม is_local,
                           จำนวนเต็ม sh_num, จำนวนเต็ม value)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    ถ้า (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ถ้า (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ถ้า (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                goto new_label;
            ถ้า (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, NULL));
        }
    } มิฉะนั้น {
    new_label:
        sym = asm_label_push(label);
    }
    ถ้า (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_num;
    esym->st_value = value;
    ถ้า (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    คืน sym;
}

static Sym* asm_new_label(TCCState *s1, จำนวนเต็ม label, จำนวนเต็ม is_local)
{
    คืน asm_new_label1(s1, label, is_local, cur_text_section->sh_num, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
static Sym* set_symbol(TCCState *s1, จำนวนเต็ม label)
{
    long n;
    ExprValue e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_expr(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ถ้า (esym)
	n += esym->st_value;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    คืน sym;
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
    ถ้า (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = NULL;
    use_section1(s1, prev);
}

static void asm_parse_directive(TCCState *s1, จำนวนเต็ม global)
{
    จำนวนเต็ม n, offset, v, size, tok1, c;
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
        ถ้า (tok1 == TOK_ASMDIR_p2align)
        {
            ถ้า (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ถ้า (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ถ้า (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            ถ้า (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } มิฉะนั้น {
	    ถ้า (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        ถ้า (tok == ',') {
            next();
            v = asm_int_expr(s1), c = 0;
        }
    zero_pad:
	ถ้า ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        ถ้า (sec->sh_type != SHT_NOBITS) {
            ถ้า (c) {
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
#ถ้า PTR_SIZE == 8
	size = 8;
	goto asm_data;
#มิฉะนั้น
        next();
        สำหรับ(;;) {
            uint64_t vl;
            const var_na *p;

            p = tokc.str.data;
            ถ้า (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (var_na **)&p, 0);
            ถ้า (*p != '\0')
                goto error_constant;
            next();
            ถ้า (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } มิฉะนั้น {
                ind += 8;
            }
            ถ้า (tok != ',')
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
        สำหรับ(;;) {
            ExprValue e;
            asm_expr(s1, &e);
            ถ้า (sec->sh_type != SHT_NOBITS) {
                ถ้า (size == 4) {
                    gen_expr32(&e);
#ถ้า PTR_SIZE == 8
		} มิฉะนั้น ถ้า (size == 8) {
		    gen_expr64(&e);
#endif
                } มิฉะนั้น {
                    ถ้า (e.sym)
                        expect("constant");
                    ถ้า (size == 1)
                        g(e.v);
                    มิฉะนั้น
                        gen_le16(e.v);
                }
            } มิฉะนั้น {
                ind += size;
            }
            ถ้า (tok != ',')
                bha_nga;
            next();
        }
        bha_nga;
    pak_sa TOK_ASMDIR_fill:
        {
            จำนวนเต็ม repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_expr(s1);
            ถ้า (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                bha_nga;
            }
            size = 1;
            val = 0;
            ถ้า (tok == ',') {
                next();
                size = asm_int_expr(s1);
                ถ้า (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    bha_nga;
                }
                ถ้า (size > 8)
                    size = 8;
                ถ้า (tok == ',') {
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
            สำหรับ(i = 0; i < repeat; i++) {
                สำหรับ(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        bha_nga;
    pak_sa TOK_ASMDIR_rept:
        {
            จำนวนเต็ม repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_expr(s1);
            init_str = tok_str_alloc();
            ขณะ (next(), tok != TOK_ASMDIR_endr) {
                ถ้า (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ขณะ (repeat-- > 0) {
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
	    ถ้า (esym) {
		ถ้า (esym->st_shndx != cur_text_section->sh_num)
		  expect("constant or same-section symbol");
		n += esym->st_value;
	    }
            ถ้า (n < ind)
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
	ถ้า (tok == ',')
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
	    ถ้า (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
	    ถ้า (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ถ้า (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    มิฉะนั้น ถ้า (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} ขณะ (tok == ',');
	bha_nga;
    pak_sa TOK_ASMDIR_string:
    pak_sa TOK_ASMDIR_ascii:
    pak_sa TOK_ASMDIR_asciz:
        {
            const var_na *p;
            จำนวนเต็ม i, size, t;

            t = tok;
            next();
            สำหรับ(;;) {
                ถ้า (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                ถ้า (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                สำหรับ(i = 0; i < size; i++)
                    g(p[i]);
                next();
                ถ้า (tok == ',') {
                    next();
                } มิฉะนั้น ถ้า (tok != TOK_STR) {
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
            ถ้า (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_expr(s1);
		next();
            }
            ถ้า (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, NULL), n);
            มิฉะนั้น
                sprintf(sname, "%s", get_tok_str(tok1, NULL));
            use_section(s1, sname);
	}
	bha_nga;
    pak_sa TOK_ASMDIR_file:
        {
            const var_na *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            ถ้า (tok == TOK_PPNUM)
                next();
            ถ้า (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } มิฉะนั้น ถ้า (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } มิฉะนั้น {
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
            ถ้า (tok == TOK_STR)
                pstrcat(ident, parimaa_na(ident), tokc.str.data);
            มิฉะนั้น
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
	    ถ้า (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            ถ้า (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, NULL));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, NULL));
            next();
            skip(',');
            n = asm_int_expr(s1);
            esym = elfsym(sym);
            ถ้า (esym) {
                esym->st_size = n;
            }
        }
        bha_nga;
    pak_sa TOK_ASMDIR_type:
        { 
            Sym *sym;
            const var_na *newtype;
            จำนวนเต็ม st_type;

            next();
	    ถ้า (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, NULL);
            next();
            skip(',');
            ถ้า (tok == TOK_STR) {
                newtype = tokc.str.data;
            } มิฉะนั้น {
                ถ้า (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, NULL);
            }

            ถ้า (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ถ้า (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                ถ้า (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } มิฉะนั้น ถ้า (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                goto set_st_type;
            } มิฉะนั้น
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, NULL), sym->type.t, newtype);

            next();
        }
        bha_nga;
    pak_sa TOK_ASMDIR_pushsection:
    pak_sa TOK_ASMDIR_section:
        {
            var_na sname[256];
	    จำนวนเต็ม old_nb_section = s1->nb_sections;
            จำนวนเต็ม flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            ขณะ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ถ้า (tok == TOK_STR)
                    pstrcat(sname, parimaa_na(sname), tokc.str.data);
                มิฉะนั้น
                    pstrcat(sname, parimaa_na(sname), get_tok_str(tok, NULL));
                next();
            }
            ถ้า (tok == ',') {
                const var_na *p;
                /* skip section options */
                next();
                ถ้า (tok != TOK_STR)
                    expect("string constant");
                สำหรับ (p = tokc.str.data; *p; ++p) {
                    ถ้า (*p == 'w')
                        flags |= SHF_WRITE;
                    ถ้า (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                ถ้า (tok == ',') {
                    next();
                    ถ้า (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    ถ้า (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    มิฉะนั้น
	        push_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ถ้า (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ถ้า (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        bha_nga;
    pak_sa TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            ถ้า (!last_text_section)
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
#ถ้า PTR_SIZE == 8
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
	    จำนวนเต็ม reloc_type = -1;

	    next();
	    asm_expr(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, NULL);
#ถ้า defined(TCC_TARGET_ARM64)
	    ถ้า (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#elif defined(TCC_TARGET_RISCV64)
	    ถ้า (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    มิฉะนั้น ถ้า (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    ถ้า (reloc_type < 0)
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
static จำนวนเต็ม tcc_assemble_internal(TCCState *s1, จำนวนเต็ม do_preprocess, จำนวนเต็ม global)
{
    จำนวนเต็ม opcode;
    จำนวนเต็ม saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ถ้า (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    สำหรับ(;;) {
        next();
        ถ้า (tok == TOK_EOF)
            bha_nga;
        tcc_debug_line(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ถ้า !defined(TCC_TARGET_ARM64)
        ถ้า (tok == '#') {
            /* horrible gas comment */
            ขณะ (tok != TOK_LINEFEED)
                next();
        } มิฉะนั้น
#endif
        ถ้า (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } มิฉะนั้น ถ้า (tok == TOK_PPNUM) {
            const var_na *p;
            จำนวนเต็ม n;
            p = tokc.str.data;
            n = strtoul(p, (var_na **)&p, 10);
            ถ้า (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            goto redo;
        } มิฉะนั้น ถ้า (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            ถ้า (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                goto redo;
            } มิฉะนั้น ถ้า (tok == '=') {
		set_symbol(s1, opcode);
                goto redo;
            } มิฉะนั้น {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ถ้า (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    คืน 0;
}

/* Assemble the current file */
ST_FUNC จำนวนเต็ม tcc_assemble(TCCState *s1, จำนวนเต็ม do_preprocess)
{
    จำนวนเต็ม ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    คืน ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
static void tcc_assemble_inline(TCCState *s1, const var_na *str, จำนวนเต็ม len, จำนวนเต็ม global)
{
    const จำนวนเต็ม *saved_macro_ptr = macro_ptr;
    จำนวนเต็ม dotid = set_idnum('.', IS_ID);
#ถ้า !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    จำนวนเต็ม dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = NULL;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#ถ้า !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC จำนวนเต็ม find_constraint(ASMOperand *operands, จำนวนเต็ม nb_operands, 
                           const var_na *name, const var_na **pp)
{
    จำนวนเต็ม index;
    TokenSym *ts;
    const var_na *p;

    ถ้า (isnum(*name)) {
        index = 0;
        ขณะ (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        ถ้า ((unsigned)index >= nb_operands)
            index = -1;
    } มิฉะนั้น ถ้า (*name == '[') {
        name++;
        p = strchr(name, ']');
        ถ้า (p) {
            ts = tok_alloc(name, p - name);
            สำหรับ(index = 0; index < nb_operands; index++) {
                ถ้า (operands[index].id == ts->tok)
                    goto found;
            }
            index = -1;
        found:
            name = p + 1;
        } มิฉะนั้น {
            index = -1;
        }
    } มิฉะนั้น {
        index = -1;
    }
    ถ้า (pp)
        *pp = name;
    คืน index;
}

static void subst_asm_operands(ASMOperand *operands, จำนวนเต็ม nb_operands, 
                               CString *out_str, const var_na *str)
{
    จำนวนเต็ม c, index, modifier;
    ASMOperand *op;
    SValue sv;

    สำหรับ(;;) {
        c = *str++;
        ถ้า (c == '%') {
            ถ้า (*str == '%') {
                str++;
                goto add_char;
            }
            modifier = 0;
            ถ้า (*str == 'c' || *str == 'n' ||
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
            ถ้า (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            ถ้า (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, NULL), -1);
            } มิฉะนั้น {
		ถ้า (op->vt == NULL)
		    goto error;
                sv = *op->vt;
                ถ้า (op->reg >= 0) {
                    sv.r = op->reg;
                    ถ้า (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } มิฉะนั้น {
        add_char:
            cstr_ccat(out_str, c);
            ถ้า (c == '\0')
                bha_nga;
        }
    }
}


static void parse_asm_operands(ASMOperand *operands, จำนวนเต็ม *nb_operands_ptr,
                               จำนวนเต็ม is_output)
{
    ASMOperand *op;
    จำนวนเต็ม nb_operands;
    var_na* astr;

    ถ้า (tok != ':') {
        nb_operands = *nb_operands_ptr;
        สำหรับ(;;) {
            ถ้า (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ถ้า (tok == '[') {
                next();
                ถ้า (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, parimaa_na op->constraint, astr);
            skip('(');
            gexpr();
            ถ้า (is_output) {
                ถ้า (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } มิฉะนั้น {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ถ้า ((vtop->r & VT_LVAL) &&
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
            ถ้า (tok == ',') {
                next();
            } มิฉะนั้น {
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
    จำนวนเต็ม nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ขณะ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    ถ้า (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ถ้า (tok == ':') {
            next();
            ถ้า (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ถ้า (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    สำหรับ(;;) {
                        ถ้า (tok == ':')
                          bha_nga;
                        ถ้า (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        ถ้า (tok == ',') {
                            next();
                        } มิฉะนั้น {
                            bha_nga;
                        }
                    }
                }
                ถ้า (tok == ':') {
                    /* goto labels */
                    next();
                    สำหรับ (;;) {
                        Sym *csym;
                        จำนวนเต็ม asmname;
                        ถ้า (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ถ้า (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       parimaa_na(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        ถ้า (!csym) {
                            csym = label_push(&global_label_stack, tok,
                                              LABEL_FORWARD);
                        } มิฉะนั้น {
                            ถ้า (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ถ้า (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ถ้า (tok != ',')
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
    ถ้า (tok != ';')
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
    ถ้า (must_subst) {
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
    ถ้า (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    สำหรับ(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC void asm_global_instr(void)
{
    CString *astr;
    จำนวนเต็ม saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ถ้า (tok != ';')
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
#มิฉะนั้น
ST_FUNC จำนวนเต็ม tcc_assemble(TCCState *s1, จำนวนเต็ม do_preprocess)
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
