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
#ضمن "tcc.h"
#ifdef CONFIG_TCC_ASM

ساكن Section *last_text_section; /* to handle .previous asm directive */
ساكن صحيح asmgoto_n;

ساكن صحيح tcc_assemble_internal(TCCState *s1, صحيح do_preprocess, صحيح global);
ساكن Sym* asm_new_label(TCCState *s1, صحيح label, صحيح is_local);
ساكن Sym* asm_new_label1(TCCState *s1, صحيح label, صحيح is_local, صحيح sh_num, صحيح value);

#𐡄𐡍 PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC فراغ gen_addr64(صحيح r, Sym *sym, int64_t c)
{
    𐡄𐡍 (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC فراغ gen_expr64(ExprValue *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

ساكن صحيح asm_get_prefix_name(TCCState *s1, ثابت حرف *prefix, unsigned صحيح n)
{
    حرف buf[64];
    snprintf(buf, حجم(buf), "%s%u", prefix, n);
    أرجع tok_alloc_const(buf);
}

ST_FUNC صحيح asm_get_local_label_name(TCCState *s1, unsigned صحيح n)
{
    أرجع asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ساكن صحيح asm2cname(صحيح v, صحيح *addeddot)
{
    ثابت حرف *name;
    *addeddot = 0;
    𐡄𐡍 (!tcc_state->leading_underscore)
      أرجع v;
    name = get_tok_str(v, عدم);
    𐡄𐡍 (!name)
      أرجع v;
    𐡄𐡍 (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } وإلا 𐡄𐡍 (!strchr(name, '.')) {
        حرف newname[256];
        snprintf(newname, حجم newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    أرجع v;
}

ساكن Sym *asm_label_find(صحيح v)
{
    Sym *sym;
    صحيح addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    طالما (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    أرجع sym;
}

ساكن Sym *asm_label_push(صحيح v)
{
    صحيح addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_push(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    𐡄𐡍 (addeddot)
        sym->asm_label = v;
    أرجع sym;
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
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    𐡄𐡍 (!sym) {
	sym = asm_label_push(name);
	𐡄𐡍 (csym)
	  sym->c = csym->c;
    }
    أرجع sym;
}

ساكن Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    حرف buf[100]; صحيح label; Sym *sym;
    snprintf(buf, حجم buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    أرجع sym ? sym : asm_new_label1(s1, label, 1, sec->sh_num, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ساكن فراغ asm_expr_unary(TCCState *s1, ExprValue *pe)
{
    Sym *sym;
    صحيح op, label;
    uint64_t n;
    ثابت حرف *p;

    بدل(tok) {
    حالة TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (حرف **)&p, 0);
        𐡄𐡍 (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            𐡄𐡍 (*p == 'b') {
                /* backward : find the last corresponding defined label */
                𐡄𐡍 (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                𐡄𐡍 (!sym)
                    tcc_error("local label '%d' not found backward", (صحيح)n);
            } وإلا {
                /* forward */
                𐡄𐡍 (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_push(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } وإلا 𐡄𐡍 (*p == '\0') {
            pe->v = n;
            pe->sym = عدم;
	    pe->pcrel = 0;
        } وإلا {
            tcc_error("invalid number syntax");
        }
        next();
        اكسر;
    حالة '+':
        next();
        asm_expr_unary(s1, pe);
        اكسر;
    حالة '-':
    حالة '~':
        op = tok;
        next();
        asm_expr_unary(s1, pe);
        𐡄𐡍 (pe->sym)
            tcc_error("invalid operation with label");
        𐡄𐡍 (op == '-')
            pe->v = -pe->v;
        وإلا
            pe->v = ~pe->v;
        اكسر;
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = عدم;
	pe->pcrel = 0;
	next();
	اكسر;
    حالة '(':
        next();
        asm_expr(s1, pe);
        skip(')');
        اكسر;
    حالة '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        اكسر;
    افتراضي:
        𐡄𐡍 (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, عدم);
	    esym = elfsym(sym);
            𐡄𐡍 (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_value;
                pe->sym = عدم;
		pe->pcrel = 0;
            } وإلا {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } وإلا {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        اكسر;
    }
}
    
ساكن فراغ asm_expr_prod(TCCState *s1, ExprValue *pe)
{
    صحيح op;
    ExprValue e2;

    asm_expr_unary(s1, pe);
    لكل(;;) {
        op = tok;
        𐡄𐡍 (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            اكسر;
        next();
        asm_expr_unary(s1, &e2);
        𐡄𐡍 (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        بدل(op) {
        حالة '*':
            pe->v *= e2.v;
            اكسر;
        حالة '/':  
            𐡄𐡍 (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            اكسر;
        حالة '%':  
            𐡄𐡍 (e2.v == 0)
                اذهب div_error;
            pe->v %= e2.v;
            اكسر;
        حالة TOK_SHL:
            pe->v <<= e2.v;
            اكسر;
        افتراضي:
        حالة TOK_SAR:
            pe->v >>= e2.v;
            اكسر;
        }
    }
}

ساكن فراغ asm_expr_logic(TCCState *s1, ExprValue *pe)
{
    صحيح op;
    ExprValue e2;

    asm_expr_prod(s1, pe);
    لكل(;;) {
        op = tok;
        𐡄𐡍 (op != '&' && op != '|' && op != '^')
            اكسر;
        next();
        asm_expr_prod(s1, &e2);
        𐡄𐡍 (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        بدل(op) {
        حالة '&':
            pe->v &= e2.v;
            اكسر;
        حالة '|':  
            pe->v |= e2.v;
            اكسر;
        افتراضي:
        حالة '^':
            pe->v ^= e2.v;
            اكسر;
        }
    }
}

ساكن مضمن فراغ asm_expr_sum(TCCState *s1, ExprValue *pe)
{
    صحيح op;
    ExprValue e2;

    asm_expr_logic(s1, pe);
    لكل(;;) {
        op = tok;
        𐡄𐡍 (op != '+' && op != '-')
            اكسر;
        next();
        asm_expr_logic(s1, &e2);
        𐡄𐡍 (op == '+') {
            𐡄𐡍 (pe->sym != عدم && e2.sym != عدم)
                اذهب cannot_relocate;
            pe->v += e2.v;
            𐡄𐡍 (pe->sym == عدم && e2.sym != عدم)
                pe->sym = e2.sym;
        } وإلا {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    𐡄𐡍 (!e2.sym) {
		/* OK */
	    } وإلا 𐡄𐡍 (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = عدم; /* same symbols can be subtracted to NULL */
	    } وإلا {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		𐡄𐡍 (!esym2)
		    اذهب cannot_relocate;
		𐡄𐡍 (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (صحيح)(esym1->st_value - esym2->st_value);
		    pe->sym = عدم;
		} وإلا 𐡄𐡍 (esym2->st_shndx == cur_text_section->sh_num) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (صحيح)(0 - esym2->st_value);
		    pe->pcrel = 1;
		    e2.sym = عدم;
		} وإلا {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ساكن مضمن فراغ asm_expr_cmp(TCCState *s1, ExprValue *pe)
{
    صحيح op;
    ExprValue e2;

    asm_expr_sum(s1, pe);
    لكل(;;) {
        op = tok;
	𐡄𐡍 (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            اكسر;
        next();
        asm_expr_sum(s1, &e2);
        𐡄𐡍 (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        بدل(op) {
	حالة TOK_EQ:
	    pe->v = pe->v == e2.v;
	    اكسر;
	حالة TOK_NE:
	    pe->v = pe->v != e2.v;
	    اكسر;
	حالة TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    اكسر;
	حالة TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    اكسر;
	حالة TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    اكسر;
	حالة TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    اكسر;
        افتراضي:
            اكسر;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC فراغ asm_expr(TCCState *s1, ExprValue *pe)
{
    asm_expr_cmp(s1, pe);
}

ST_FUNC صحيح asm_int_expr(TCCState *s1)
{
    ExprValue e;
    asm_expr(s1, &e);
    𐡄𐡍 (e.sym)
        expect("constant");
    𐡄𐡍 ((صحيح)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    أرجع e.v;
}

ساكن Sym* asm_new_label1(TCCState *s1, صحيح label, صحيح is_local,
                           صحيح sh_num, صحيح value)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    𐡄𐡍 (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        𐡄𐡍 (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            𐡄𐡍 (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                اذهب new_label;
            𐡄𐡍 (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, عدم));
        }
    } وإلا {
    new_label:
        sym = asm_label_push(label);
    }
    𐡄𐡍 (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_num;
    esym->st_value = value;
    𐡄𐡍 (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    أرجع sym;
}

ساكن Sym* asm_new_label(TCCState *s1, صحيح label, صحيح is_local)
{
    أرجع asm_new_label1(s1, label, is_local, cur_text_section->sh_num, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ساكن Sym* set_symbol(TCCState *s1, صحيح label)
{
    long n;
    ExprValue e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_expr(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    𐡄𐡍 (esym)
	n += esym->st_value;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    أرجع sym;
}

ساكن فراغ use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

ساكن فراغ use_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

ساكن فراغ push_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

ساكن فراغ pop_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    𐡄𐡍 (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = عدم;
    use_section1(s1, prev);
}

ساكن فراغ asm_parse_directive(TCCState *s1, صحيح global)
{
    صحيح n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    بدل(tok) {
    حالة TOK_ASMDIR_align:
    حالة TOK_ASMDIR_balign:
    حالة TOK_ASMDIR_p2align:
    حالة TOK_ASMDIR_skip:
    حالة TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_expr(s1);
        𐡄𐡍 (tok1 == TOK_ASMDIR_p2align)
        {
            𐡄𐡍 (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        𐡄𐡍 (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            𐡄𐡍 (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            𐡄𐡍 (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } وإلا {
	    𐡄𐡍 (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        𐡄𐡍 (tok == ',') {
            next();
            v = asm_int_expr(s1), c = 0;
        }
    zero_pad:
	𐡄𐡍 ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        𐡄𐡍 (sec->sh_type != SHT_NOBITS) {
            𐡄𐡍 (c) {
                gen_fill_nops(size);
                اكسر;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        اكسر;
    حالة TOK_ASMDIR_quad:
#𐡄𐡍 PTR_SIZE == 8
	size = 8;
	اذهب asm_data;
#وإلا
        next();
        لكل(;;) {
            uint64_t vl;
            ثابت حرف *p;

            p = tokc.str.data;
            𐡄𐡍 (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (حرف **)&p, 0);
            𐡄𐡍 (*p != '\0')
                اذهب error_constant;
            next();
            𐡄𐡍 (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } وإلا {
                ind += 8;
            }
            𐡄𐡍 (tok != ',')
                اكسر;
            next();
        }
        اكسر;
#endif
    حالة TOK_ASMDIR_byte:
        size = 1;
        اذهب asm_data;
    حالة TOK_ASMDIR_word:
    حالة TOK_ASMDIR_short:
        size = 2;
        اذهب asm_data;
    حالة TOK_ASMDIR_long:
    حالة TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        لكل(;;) {
            ExprValue e;
            asm_expr(s1, &e);
            𐡄𐡍 (sec->sh_type != SHT_NOBITS) {
                𐡄𐡍 (size == 4) {
                    gen_expr32(&e);
#𐡄𐡍 PTR_SIZE == 8
		} وإلا 𐡄𐡍 (size == 8) {
		    gen_expr64(&e);
#endif
                } وإلا {
                    𐡄𐡍 (e.sym)
                        expect("constant");
                    𐡄𐡍 (size == 1)
                        g(e.v);
                    وإلا
                        gen_le16(e.v);
                }
            } وإلا {
                ind += size;
            }
            𐡄𐡍 (tok != ',')
                اكسر;
            next();
        }
        اكسر;
    حالة TOK_ASMDIR_fill:
        {
            صحيح repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_expr(s1);
            𐡄𐡍 (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                اكسر;
            }
            size = 1;
            val = 0;
            𐡄𐡍 (tok == ',') {
                next();
                size = asm_int_expr(s1);
                𐡄𐡍 (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    اكسر;
                }
                𐡄𐡍 (size > 8)
                    size = 8;
                𐡄𐡍 (tok == ',') {
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
            لكل(i = 0; i < repeat; i++) {
                لكل(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        اكسر;
    حالة TOK_ASMDIR_rept:
        {
            صحيح repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_expr(s1);
            init_str = tok_str_alloc();
            طالما (next(), tok != TOK_ASMDIR_endr) {
                𐡄𐡍 (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            طالما (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            اكسر;
        }
    حالة TOK_ASMDIR_org:
        {
	    ExprValue e;
	    ElfSym *esym;
            next();
	    asm_expr(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    𐡄𐡍 (esym) {
		𐡄𐡍 (esym->st_shndx != cur_text_section->sh_num)
		  expect("constant or same-section symbol");
		n += esym->st_value;
	    }
            𐡄𐡍 (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            اذهب zero_pad;
        }
        اكسر;
    حالة TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	𐡄𐡍 (tok == ',')
	    set_symbol(s1, tok1);
	اكسر;
    حالة TOK_ASMDIR_globl:
    حالة TOK_ASMDIR_global:
    حالة TOK_ASMDIR_weak:
    حالة TOK_ASMDIR_hidden:
	tok1 = tok;
	𐡏𐡁𐡃 { 
            Sym *sym;
            next();
	    𐡄𐡍 (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, عدم);
	    𐡄𐡍 (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            𐡄𐡍 (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    وإلا 𐡄𐡍 (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} طالما (tok == ',');
	اكسر;
    حالة TOK_ASMDIR_string:
    حالة TOK_ASMDIR_ascii:
    حالة TOK_ASMDIR_asciz:
        {
            ثابت حرف *p;
            صحيح i, size, t;

            t = tok;
            next();
            لكل(;;) {
                𐡄𐡍 (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                𐡄𐡍 (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                لكل(i = 0; i < size; i++)
                    g(p[i]);
                next();
                𐡄𐡍 (tok == ',') {
                    next();
                } وإلا 𐡄𐡍 (tok != TOK_STR) {
                    اكسر;
                }
            }
	}
	اكسر;
    حالة TOK_ASMDIR_text:
    حالة TOK_ASMDIR_data:
    حالة TOK_ASMDIR_bss:
	{ 
            حرف sname[64];
            tok1 = tok;
            n = 0;
            next();
            𐡄𐡍 (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_expr(s1);
		next();
            }
            𐡄𐡍 (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, عدم), n);
            وإلا
                sprintf(sname, "%s", get_tok_str(tok1, عدم));
            use_section(s1, sname);
	}
	اكسر;
    حالة TOK_ASMDIR_file:
        {
            ثابت حرف *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            𐡄𐡍 (tok == TOK_PPNUM)
                next();
            𐡄𐡍 (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } وإلا 𐡄𐡍 (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } وإلا {
                skip_to_eol(0);
                اكسر;
            }
            tccpp_putfile(p);
            next();
        }
        اكسر;
    حالة TOK_ASMDIR_ident:
        {
            حرف ident[256];

            ident[0] = '\0';
            next();
            𐡄𐡍 (tok == TOK_STR)
                pstrcat(ident, حجم(ident), tokc.str.data);
            وإلا
                pstrcat(ident, حجم(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        اكسر;
    حالة TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    𐡄𐡍 (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            𐡄𐡍 (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, عدم));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, عدم));
            next();
            skip(',');
            n = asm_int_expr(s1);
            esym = elfsym(sym);
            𐡄𐡍 (esym) {
                esym->st_size = n;
            }
        }
        اكسر;
    حالة TOK_ASMDIR_type:
        { 
            Sym *sym;
            ثابت حرف *newtype;
            صحيح st_type;

            next();
	    𐡄𐡍 (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, عدم);
            next();
            skip(',');
            𐡄𐡍 (tok == TOK_STR) {
                newtype = tokc.str.data;
            } وإلا {
                𐡄𐡍 (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, عدم);
            }

            𐡄𐡍 (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                𐡄𐡍 (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                𐡄𐡍 (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } وإلا 𐡄𐡍 (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                اذهب set_st_type;
            } وإلا
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, عدم), sym->type.t, newtype);

            next();
        }
        اكسر;
    حالة TOK_ASMDIR_pushsection:
    حالة TOK_ASMDIR_section:
        {
            حرف sname[256];
	    صحيح old_nb_section = s1->nb_sections;
            صحيح flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            طالما (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                𐡄𐡍 (tok == TOK_STR)
                    pstrcat(sname, حجم(sname), tokc.str.data);
                وإلا
                    pstrcat(sname, حجم(sname), get_tok_str(tok, عدم));
                next();
            }
            𐡄𐡍 (tok == ',') {
                ثابت حرف *p;
                /* skip section options */
                next();
                𐡄𐡍 (tok != TOK_STR)
                    expect("string constant");
                لكل (p = tokc.str.data; *p; ++p) {
                    𐡄𐡍 (*p == 'w')
                        flags |= SHF_WRITE;
                    𐡄𐡍 (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                𐡄𐡍 (tok == ',') {
                    next();
                    𐡄𐡍 (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    𐡄𐡍 (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    وإلا
	        push_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    𐡄𐡍 (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                𐡄𐡍 (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        اكسر;
    حالة TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            𐡄𐡍 (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        اكسر;
    حالة TOK_ASMDIR_popsection:
	next();
	pop_section(s1);
	اكسر;
#ifdef TCC_TARGET_I386
    حالة TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        اكسر;
    حالة TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        اكسر;
#endif
#𐡄𐡍 PTR_SIZE == 8
    /* added for compatibility with GAS */
    حالة TOK_ASMDIR_code64:
        next();
        اكسر;
#endif
#ifdef TCC_TARGET_RISCV64
    حالة TOK_ASMDIR_option:
        next();
        بدل(tok){
            حالة TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            حالة TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            حالة TOK_ASM_pic:
            حالة TOK_ASM_nopic:
            حالة TOK_ASM_relax:
            حالة TOK_ASM_norelax:
            حالة TOK_ASM_push:
            حالة TOK_ASM_pop:
                /* TODO: unimplemented */
                next();
                اكسر;
            حالة TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, عدم));
                اكسر;
            افتراضي:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, عدم));
                اكسر;
        }
        اكسر;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    حالة TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	اكسر;
    حالة TOK_ASMDIR_reloc:
	{
	    ExprValue e;
	    ثابت حرف *reloc_name;
	    صحيح reloc_type = -1;

	    next();
	    asm_expr(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, عدم);
#𐡄𐡍 defined(TCC_TARGET_ARM64)
	    𐡄𐡍 (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#وإلاإذا defined(TCC_TARGET_RISCV64)
	    𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    وإلا 𐡄𐡍 (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    𐡄𐡍 (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, عدم), e.v, reloc_type, 0);
	    next();
	}
	اكسر;
    افتراضي:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, عدم));
        اكسر;
    }
}


/* assemble a file */
ساكن صحيح tcc_assemble_internal(TCCState *s1, صحيح do_preprocess, صحيح global)
{
    صحيح opcode;
    صحيح saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    𐡄𐡍 (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    لكل(;;) {
        next();
        𐡄𐡍 (tok == TOK_EOF)
            اكسر;
        tcc_debug_line(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#𐡄𐡍 !defined(TCC_TARGET_ARM64)
        𐡄𐡍 (tok == '#') {
            /* horrible gas comment */
            طالما (tok != TOK_LINEFEED)
                next();
        } وإلا
#endif
        𐡄𐡍 (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } وإلا 𐡄𐡍 (tok == TOK_PPNUM) {
            ثابت حرف *p;
            صحيح n;
            p = tokc.str.data;
            n = strtoul(p, (حرف **)&p, 10);
            𐡄𐡍 (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            اذهب redo;
        } وإلا 𐡄𐡍 (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            𐡄𐡍 (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                اذهب redo;
            } وإلا 𐡄𐡍 (tok == '=') {
		set_symbol(s1, opcode);
                اذهب redo;
            } وإلا {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        𐡄𐡍 (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    أرجع 0;
}

/* Assemble the current file */
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess)
{
    صحيح ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    أرجع ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ساكن فراغ tcc_assemble_inline(TCCState *s1, ثابت حرف *str, صحيح len, صحيح global)
{
    ثابت صحيح *saved_macro_ptr = macro_ptr;
    صحيح dotid = set_idnum('.', IS_ID);
#𐡄𐡍 !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    صحيح dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = عدم;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#𐡄𐡍 !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC صحيح find_constraint(ASMOperand *operands, صحيح nb_operands, 
                           ثابت حرف *name, ثابت حرف **pp)
{
    صحيح index;
    TokenSym *ts;
    ثابت حرف *p;

    𐡄𐡍 (isnum(*name)) {
        index = 0;
        طالما (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        𐡄𐡍 ((unsigned)index >= nb_operands)
            index = -1;
    } وإلا 𐡄𐡍 (*name == '[') {
        name++;
        p = strchr(name, ']');
        𐡄𐡍 (p) {
            ts = tok_alloc(name, p - name);
            لكل(index = 0; index < nb_operands; index++) {
                𐡄𐡍 (operands[index].id == ts->tok)
                    اذهب found;
            }
            index = -1;
        found:
            name = p + 1;
        } وإلا {
            index = -1;
        }
    } وإلا {
        index = -1;
    }
    𐡄𐡍 (pp)
        *pp = name;
    أرجع index;
}

ساكن فراغ subst_asm_operands(ASMOperand *operands, صحيح nb_operands, 
                               CString *out_str, ثابت حرف *str)
{
    صحيح c, index, modifier;
    ASMOperand *op;
    SValue sv;

    لكل(;;) {
        c = *str++;
        𐡄𐡍 (c == '%') {
            𐡄𐡍 (*str == '%') {
                str++;
                اذهب add_char;
            }
            modifier = 0;
            𐡄𐡍 (*str == 'c' || *str == 'n' ||
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
            𐡄𐡍 (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            𐡄𐡍 (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, عدم), -1);
            } وإلا {
		𐡄𐡍 (op->vt == عدم)
		    اذهب error;
                sv = *op->vt;
                𐡄𐡍 (op->reg >= 0) {
                    sv.r = op->reg;
                    𐡄𐡍 (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } وإلا {
        add_char:
            cstr_ccat(out_str, c);
            𐡄𐡍 (c == '\0')
                اكسر;
        }
    }
}


ساكن فراغ parse_asm_operands(ASMOperand *operands, صحيح *nb_operands_ptr,
                               صحيح is_output)
{
    ASMOperand *op;
    صحيح nb_operands;
    حرف* astr;

    𐡄𐡍 (tok != ':') {
        nb_operands = *nb_operands_ptr;
        لكل(;;) {
            𐡄𐡍 (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            𐡄𐡍 (tok == '[') {
                next();
                𐡄𐡍 (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, حجم op->constraint, astr);
            skip('(');
            gexpr();
            𐡄𐡍 (is_output) {
                𐡄𐡍 (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } وإلا {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                𐡄𐡍 ((vtop->r & VT_LVAL) &&
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
            𐡄𐡍 (tok == ',') {
                next();
            } وإلا {
                اكسر;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC فراغ asm_instr(فراغ)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    صحيح nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    طالما (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, حجم(clobber_regs));
    𐡄𐡍 (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        𐡄𐡍 (tok == ':') {
            next();
            𐡄𐡍 (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                𐡄𐡍 (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    لكل(;;) {
                        𐡄𐡍 (tok == ':')
                          اكسر;
                        𐡄𐡍 (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        𐡄𐡍 (tok == ',') {
                            next();
                        } وإلا {
                            اكسر;
                        }
                    }
                }
                𐡄𐡍 (tok == ':') {
                    /* goto labels */
                    next();
                    لكل (;;) {
                        Sym *csym;
                        صحيح asmname;
                        𐡄𐡍 (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        𐡄𐡍 (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       حجم(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        𐡄𐡍 (!csym) {
                            csym = label_push(&global_label_stack, tok,
                                              LABEL_FORWARD);
                        } وإلا {
                            𐡄𐡍 (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        𐡄𐡍 (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        𐡄𐡍 (tok != ',')
                          اكسر;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    𐡄𐡍 (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (حرف *)astr.data);
#endif
    𐡄𐡍 (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (حرف *)astr.data);
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
    𐡄𐡍 (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    لكل(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC فراغ asm_global_instr(فراغ)
{
    CString *astr;
    صحيح saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    𐡄𐡍 (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (حرف *)astr->data);
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
#وإلا
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC فراغ asm_instr(فراغ)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC فراغ asm_global_instr(فراغ)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
