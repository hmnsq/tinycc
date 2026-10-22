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
#شامل "tcc.h"
#ifdef CONFIG_TCC_ASM

ایستا Section *last_text_section; /* to handle .previous asm directive */
ایستا صحیح asmgoto_n;

ایستا صحیح tcc_assemble_internal(TCCState *s1, صحیح do_preprocess, صحیح global);
ایستا Sym* asm_new_label(TCCState *s1, صحیح label, صحیح is_local);
ایستا Sym* asm_new_label1(TCCState *s1, صحیح label, صحیح is_local, صحیح sh_رقم, صحیح مقدار);

#اگر PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC تهی gen_addr64(صحیح r, Sym *sym, int64_t c)
{
    اگر (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC تهی gen_expr64(عبارت_مقدار *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

ایستا صحیح asm_get_prefix_name(TCCState *s1, ثابت نویسه *prefix, unsigned صحیح n)
{
    نویسه buf[64];
    snprintf(buf, اندازه(buf), "%s%u", prefix, n);
    بازگشت tok_alloc_const(buf);
}

ST_FUNC صحیح asm_get_local_label_name(TCCState *s1, unsigned صحیح n)
{
    بازگشت asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ایستا صحیح asm2cname(صحیح v, صحیح *addeddot)
{
    ثابت نویسه *name;
    *addeddot = 0;
    اگر (!tcc_state->leading_underscore)
      بازگشت v;
    name = get_tok_str(v, پوچ);
    اگر (!name)
      بازگشت v;
    اگر (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } وگرنه اگر (!strchr(name, '.')) {
        نویسه newname[256];
        snprintf(newname, اندازه newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    بازگشت v;
}

ایستا Sym *asm_label_find(صحیح v)
{
    Sym *sym;
    صحیح addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    وقتی (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    بازگشت sym;
}

ایستا Sym *asm_label_افزودن(صحیح v)
{
    صحیح addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_افزودن(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    اگر (addeddot)
        sym->asm_label = v;
    بازگشت sym;
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
ST_FUNC Sym* get_asm_sym(صحیح name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    اگر (!sym) {
	sym = asm_label_افزودن(name);
	اگر (csym)
	  sym->c = csym->c;
    }
    بازگشت sym;
}

ایستا Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    نویسه buf[100]; صحیح label; Sym *sym;
    snprintf(buf, اندازه buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    بازگشت sym ? sym : asm_new_label1(s1, label, 1, sec->sh_رقم, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ایستا تهی asm_عبارت_unary(TCCState *s1, عبارت_مقدار *pe)
{
    Sym *sym;
    صحیح op, label;
    uint64_t n;
    ثابت نویسه *p;

    انتخاب(tok) {
    حالت TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (نویسه **)&p, 0);
        اگر (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            اگر (*p == 'b') {
                /* backward : find the last corresponding defined label */
                اگر (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                اگر (!sym)
                    tcc_error("local label '%d' not found backward", (صحیح)n);
            } وگرنه {
                /* forward */
                اگر (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_افزودن(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } وگرنه اگر (*p == '\0') {
            pe->v = n;
            pe->sym = پوچ;
	    pe->pcrel = 0;
        } وگرنه {
            tcc_error("invalid number syntax");
        }
        next();
        بشکن;
    حالت '+':
        next();
        asm_عبارت_unary(s1, pe);
        بشکن;
    حالت '-':
    حالت '~':
        op = tok;
        next();
        asm_عبارت_unary(s1, pe);
        اگر (pe->sym)
            tcc_error("invalid operation with label");
        اگر (op == '-')
            pe->v = -pe->v;
        وگرنه
            pe->v = ~pe->v;
        بشکن;
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = پوچ;
	pe->pcrel = 0;
	next();
	بشکن;
    حالت '(':
        next();
        asm_عبارت(s1, pe);
        skip(')');
        بشکن;
    حالت '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        بشکن;
    پیشفرض:
        اگر (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, پوچ);
	    esym = elfsym(sym);
            اگر (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_مقدار;
                pe->sym = پوچ;
		pe->pcrel = 0;
            } وگرنه {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } وگرنه {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        بشکن;
    }
}
    
ایستا تهی asm_عبارت_prod(TCCState *s1, عبارت_مقدار *pe)
{
    صحیح op;
    عبارت_مقدار e2;

    asm_عبارت_unary(s1, pe);
    برای(;;) {
        op = tok;
        اگر (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            بشکن;
        next();
        asm_عبارت_unary(s1, &e2);
        اگر (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        انتخاب(op) {
        حالت '*':
            pe->v *= e2.v;
            بشکن;
        حالت '/':  
            اگر (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            بشکن;
        حالت '%':  
            اگر (e2.v == 0)
                برو div_error;
            pe->v %= e2.v;
            بشکن;
        حالت TOK_SHL:
            pe->v <<= e2.v;
            بشکن;
        پیشفرض:
        حالت TOK_SAR:
            pe->v >>= e2.v;
            بشکن;
        }
    }
}

ایستا تهی asm_عبارت_logic(TCCState *s1, عبارت_مقدار *pe)
{
    صحیح op;
    عبارت_مقدار e2;

    asm_عبارت_prod(s1, pe);
    برای(;;) {
        op = tok;
        اگر (op != '&' && op != '|' && op != '^')
            بشکن;
        next();
        asm_عبارت_prod(s1, &e2);
        اگر (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        انتخاب(op) {
        حالت '&':
            pe->v &= e2.v;
            بشکن;
        حالت '|':  
            pe->v |= e2.v;
            بشکن;
        پیشفرض:
        حالت '^':
            pe->v ^= e2.v;
            بشکن;
        }
    }
}

ایستا درونخطی تهی asm_عبارت_sum(TCCState *s1, عبارت_مقدار *pe)
{
    صحیح op;
    عبارت_مقدار e2;

    asm_عبارت_logic(s1, pe);
    برای(;;) {
        op = tok;
        اگر (op != '+' && op != '-')
            بشکن;
        next();
        asm_عبارت_logic(s1, &e2);
        اگر (op == '+') {
            اگر (pe->sym != پوچ && e2.sym != پوچ)
                برو cannot_relocate;
            pe->v += e2.v;
            اگر (pe->sym == پوچ && e2.sym != پوچ)
                pe->sym = e2.sym;
        } وگرنه {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    اگر (!e2.sym) {
		/* OK */
	    } وگرنه اگر (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = پوچ; /* same symbols can be subtracted to NULL */
	    } وگرنه {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		اگر (!esym2)
		    برو cannot_relocate;
		اگر (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (صحیح)(esym1->st_مقدار - esym2->st_مقدار);
		    pe->sym = پوچ;
		} وگرنه اگر (esym2->st_shndx == cur_text_section->sh_رقم) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (صحیح)(0 - esym2->st_مقدار);
		    pe->pcrel = 1;
		    e2.sym = پوچ;
		} وگرنه {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ایستا درونخطی تهی asm_عبارت_cmp(TCCState *s1, عبارت_مقدار *pe)
{
    صحیح op;
    عبارت_مقدار e2;

    asm_عبارت_sum(s1, pe);
    برای(;;) {
        op = tok;
	اگر (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            بشکن;
        next();
        asm_عبارت_sum(s1, &e2);
        اگر (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        انتخاب(op) {
	حالت TOK_EQ:
	    pe->v = pe->v == e2.v;
	    بشکن;
	حالت TOK_NE:
	    pe->v = pe->v != e2.v;
	    بشکن;
	حالت TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    بشکن;
	حالت TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    بشکن;
	حالت TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    بشکن;
	حالت TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    بشکن;
        پیشفرض:
            بشکن;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC تهی asm_عبارت(TCCState *s1, عبارت_مقدار *pe)
{
    asm_عبارت_cmp(s1, pe);
}

ST_FUNC صحیح asm_int_عبارت(TCCState *s1)
{
    عبارت_مقدار e;
    asm_عبارت(s1, &e);
    اگر (e.sym)
        expect("constant");
    اگر ((صحیح)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    بازگشت e.v;
}

ایستا Sym* asm_new_label1(TCCState *s1, صحیح label, صحیح is_local,
                           صحیح sh_رقم, صحیح مقدار)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    اگر (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        اگر (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            اگر (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                برو new_label;
            اگر (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, پوچ));
        }
    } وگرنه {
    new_label:
        sym = asm_label_افزودن(label);
    }
    اگر (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_رقم;
    esym->st_مقدار = مقدار;
    اگر (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    بازگشت sym;
}

ایستا Sym* asm_new_label(TCCState *s1, صحیح label, صحیح is_local)
{
    بازگشت asm_new_label1(s1, label, is_local, cur_text_section->sh_رقم, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ایستا Sym* set_نماد(TCCState *s1, صحیح label)
{
    long n;
    عبارت_مقدار e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_عبارت(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    اگر (esym)
	n += esym->st_مقدار;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    بازگشت sym;
}

ایستا تهی use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

ایستا تهی use_section(TCCState *s1, ثابت نویسه *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

ایستا تهی افزودن_section(TCCState *s1, ثابت نویسه *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

ایستا تهی برداشت_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    اگر (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = پوچ;
    use_section1(s1, prev);
}

ایستا تهی asm_parse_directive(TCCState *s1, صحیح global)
{
    صحیح n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    انتخاب(tok) {
    حالت TOK_ASMDIR_align:
    حالت TOK_ASMDIR_balign:
    حالت TOK_ASMDIR_p2align:
    حالت TOK_ASMDIR_skip:
    حالت TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_عبارت(s1);
        اگر (tok1 == TOK_ASMDIR_p2align)
        {
            اگر (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        اگر (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            اگر (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            اگر (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } وگرنه {
	    اگر (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        اگر (tok == ',') {
            next();
            v = asm_int_عبارت(s1), c = 0;
        }
    zero_pad:
	اگر ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        اگر (sec->sh_type != SHT_NOBITS) {
            اگر (c) {
                gen_fill_nops(size);
                بشکن;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        بشکن;
    حالت TOK_ASMDIR_quad:
#اگر PTR_SIZE == 8
	size = 8;
	برو asm_data;
#وگرنه
        next();
        برای(;;) {
            uint64_t vl;
            ثابت نویسه *p;

            p = tokc.str.data;
            اگر (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (نویسه **)&p, 0);
            اگر (*p != '\0')
                برو error_constant;
            next();
            اگر (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } وگرنه {
                ind += 8;
            }
            اگر (tok != ',')
                بشکن;
            next();
        }
        بشکن;
#endif
    حالت TOK_ASMDIR_byte:
        size = 1;
        برو asm_data;
    حالت TOK_ASMDIR_word:
    حالت TOK_ASMDIR_short:
        size = 2;
        برو asm_data;
    حالت TOK_ASMDIR_long:
    حالت TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        برای(;;) {
            عبارت_مقدار e;
            asm_عبارت(s1, &e);
            اگر (sec->sh_type != SHT_NOBITS) {
                اگر (size == 4) {
                    gen_expr32(&e);
#اگر PTR_SIZE == 8
		} وگرنه اگر (size == 8) {
		    gen_expr64(&e);
#endif
                } وگرنه {
                    اگر (e.sym)
                        expect("constant");
                    اگر (size == 1)
                        g(e.v);
                    وگرنه
                        gen_le16(e.v);
                }
            } وگرنه {
                ind += size;
            }
            اگر (tok != ',')
                بشکن;
            next();
        }
        بشکن;
    حالت TOK_ASMDIR_fill:
        {
            صحیح repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_عبارت(s1);
            اگر (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                بشکن;
            }
            size = 1;
            val = 0;
            اگر (tok == ',') {
                next();
                size = asm_int_عبارت(s1);
                اگر (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    بشکن;
                }
                اگر (size > 8)
                    size = 8;
                اگر (tok == ',') {
                    next();
                    val = asm_int_عبارت(s1);
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
            برای(i = 0; i < repeat; i++) {
                برای(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        بشکن;
    حالت TOK_ASMDIR_rept:
        {
            صحیح repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_عبارت(s1);
            init_str = tok_str_alloc();
            وقتی (next(), tok != TOK_ASMDIR_endr) {
                اگر (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            وقتی (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            بشکن;
        }
    حالت TOK_ASMDIR_org:
        {
	    عبارت_مقدار e;
	    ElfSym *esym;
            next();
	    asm_عبارت(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    اگر (esym) {
		اگر (esym->st_shndx != cur_text_section->sh_رقم)
		  expect("constant or same-section symbol");
		n += esym->st_مقدار;
	    }
            اگر (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            برو zero_pad;
        }
        بشکن;
    حالت TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	اگر (tok == ',')
	    set_نماد(s1, tok1);
	بشکن;
    حالت TOK_ASMDIR_globl:
    حالت TOK_ASMDIR_global:
    حالت TOK_ASMDIR_weak:
    حالت TOK_ASMDIR_hidden:
	tok1 = tok;
	انجامبده { 
            Sym *sym;
            next();
	    اگر (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, پوچ);
	    اگر (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            اگر (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    وگرنه اگر (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} وقتی (tok == ',');
	بشکن;
    حالت TOK_ASMDIR_string:
    حالت TOK_ASMDIR_ascii:
    حالت TOK_ASMDIR_asciz:
        {
            ثابت نویسه *p;
            صحیح i, size, t;

            t = tok;
            next();
            برای(;;) {
                اگر (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                اگر (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                برای(i = 0; i < size; i++)
                    g(p[i]);
                next();
                اگر (tok == ',') {
                    next();
                } وگرنه اگر (tok != TOK_STR) {
                    بشکن;
                }
            }
	}
	بشکن;
    حالت TOK_ASMDIR_text:
    حالت TOK_ASMDIR_data:
    حالت TOK_ASMDIR_bss:
	{ 
            نویسه sname[64];
            tok1 = tok;
            n = 0;
            next();
            اگر (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_عبارت(s1);
		next();
            }
            اگر (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, پوچ), n);
            وگرنه
                sprintf(sname, "%s", get_tok_str(tok1, پوچ));
            use_section(s1, sname);
	}
	بشکن;
    حالت TOK_ASMDIR_file:
        {
            ثابت نویسه *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            اگر (tok == TOK_PPNUM)
                next();
            اگر (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } وگرنه اگر (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } وگرنه {
                skip_to_eol(0);
                بشکن;
            }
            tccpp_putfile(p);
            next();
        }
        بشکن;
    حالت TOK_ASMDIR_ident:
        {
            نویسه ident[256];

            ident[0] = '\0';
            next();
            اگر (tok == TOK_STR)
                pstrcat(ident, اندازه(ident), tokc.str.data);
            وگرنه
                pstrcat(ident, اندازه(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        بشکن;
    حالت TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    اگر (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            اگر (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, پوچ));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, پوچ));
            next();
            skip(',');
            n = asm_int_عبارت(s1);
            esym = elfsym(sym);
            اگر (esym) {
                esym->st_size = n;
            }
        }
        بشکن;
    حالت TOK_ASMDIR_type:
        { 
            Sym *sym;
            ثابت نویسه *newtype;
            صحیح st_type;

            next();
	    اگر (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, پوچ);
            next();
            skip(',');
            اگر (tok == TOK_STR) {
                newtype = tokc.str.data;
            } وگرنه {
                اگر (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, پوچ);
            }

            اگر (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                اگر (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                اگر (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } وگرنه اگر (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                برو set_st_type;
            } وگرنه
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, پوچ), sym->type.t, newtype);

            next();
        }
        بشکن;
    حالت TOK_ASMDIR_pushsection:
    حالت TOK_ASMDIR_section:
        {
            نویسه sname[256];
	    صحیح old_nb_section = s1->nb_sections;
            صحیح flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            وقتی (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                اگر (tok == TOK_STR)
                    pstrcat(sname, اندازه(sname), tokc.str.data);
                وگرنه
                    pstrcat(sname, اندازه(sname), get_tok_str(tok, پوچ));
                next();
            }
            اگر (tok == ',') {
                ثابت نویسه *p;
                /* skip section options */
                next();
                اگر (tok != TOK_STR)
                    expect("string constant");
                برای (p = tokc.str.data; *p; ++p) {
                    اگر (*p == 'w')
                        flags |= SHF_WRITE;
                    اگر (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                اگر (tok == ',') {
                    next();
                    اگر (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    اگر (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    وگرنه
	        افزودن_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    اگر (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                اگر (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        بشکن;
    حالت TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            اگر (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        بشکن;
    حالت TOK_ASMDIR_popsection:
	next();
	برداشت_section(s1);
	بشکن;
#ifdef TCC_TARGET_I386
    حالت TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        بشکن;
    حالت TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        بشکن;
#endif
#اگر PTR_SIZE == 8
    /* added for compatibility with GAS */
    حالت TOK_ASMDIR_code64:
        next();
        بشکن;
#endif
#ifdef TCC_TARGET_RISCV64
    حالت TOK_ASMDIR_option:
        next();
        انتخاب(tok){
            حالت TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            حالت TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            حالت TOK_ASM_pic:
            حالت TOK_ASM_nopic:
            حالت TOK_ASM_relax:
            حالت TOK_ASM_norelax:
            حالت TOK_ASM_افزودن:
            حالت TOK_ASM_برداشت:
                /* TODO: unimplemented */
                next();
                بشکن;
            حالت TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, پوچ));
                بشکن;
            پیشفرض:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, پوچ));
                بشکن;
        }
        بشکن;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    حالت TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	بشکن;
    حالت TOK_ASMDIR_reloc:
	{
	    عبارت_مقدار e;
	    ثابت نویسه *reloc_name;
	    صحیح reloc_type = -1;

	    next();
	    asm_عبارت(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, پوچ);
#اگر defined(TCC_TARGET_ARM64)
	    اگر (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#وگرنهاگر defined(TCC_TARGET_RISCV64)
	    اگر (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    وگرنه اگر (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    اگر (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, پوچ), e.v, reloc_type, 0);
	    next();
	}
	بشکن;
    پیشفرض:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, پوچ));
        بشکن;
    }
}


/* assemble a file */
ایستا صحیح tcc_assemble_internal(TCCState *s1, صحیح do_preprocess, صحیح global)
{
    صحیح opcode;
    صحیح saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    اگر (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    برای(;;) {
        next();
        اگر (tok == TOK_EOF)
            بشکن;
        tcc_debug_سطر(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#اگر !defined(TCC_TARGET_ARM64)
        اگر (tok == '#') {
            /* horrible gas comment */
            وقتی (tok != TOK_LINEFEED)
                next();
        } وگرنه
#endif
        اگر (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } وگرنه اگر (tok == TOK_PPNUM) {
            ثابت نویسه *p;
            صحیح n;
            p = tokc.str.data;
            n = strtoul(p, (نویسه **)&p, 10);
            اگر (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            برو redo;
        } وگرنه اگر (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            اگر (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                برو redo;
            } وگرنه اگر (tok == '=') {
		set_نماد(s1, opcode);
                برو redo;
            } وگرنه {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        اگر (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    بازگشت 0;
}

/* Assemble the current file */
ST_FUNC صحیح tcc_assemble(TCCState *s1, صحیح do_preprocess)
{
    صحیح ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    بازگشت ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ایستا تهی tcc_assemble_inline(TCCState *s1, ثابت نویسه *str, صحیح len, صحیح global)
{
    ثابت صحیح *saved_macro_ptr = macro_ptr;
    صحیح dotid = set_idnum('.', IS_ID);
#اگر !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    صحیح dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = پوچ;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#اگر !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC صحیح find_constraint(ASMOperand *operands, صحیح nb_operands, 
                           ثابت نویسه *name, ثابت نویسه **pp)
{
    صحیح index;
    TokenSym *ts;
    ثابت نویسه *p;

    اگر (isnum(*name)) {
        index = 0;
        وقتی (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        اگر ((unsigned)index >= nb_operands)
            index = -1;
    } وگرنه اگر (*name == '[') {
        name++;
        p = strchr(name, ']');
        اگر (p) {
            ts = tok_alloc(name, p - name);
            برای(index = 0; index < nb_operands; index++) {
                اگر (operands[index].id == ts->tok)
                    برو found;
            }
            index = -1;
        found:
            name = p + 1;
        } وگرنه {
            index = -1;
        }
    } وگرنه {
        index = -1;
    }
    اگر (pp)
        *pp = name;
    بازگشت index;
}

ایستا تهی subst_asm_operands(ASMOperand *operands, صحیح nb_operands, 
                               CString *out_str, ثابت نویسه *str)
{
    صحیح c, index, modifier;
    ASMOperand *op;
    SValue sv;

    برای(;;) {
        c = *str++;
        اگر (c == '%') {
            اگر (*str == '%') {
                str++;
                برو add_char;
            }
            modifier = 0;
            اگر (*str == 'c' || *str == 'n' ||
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
            اگر (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            اگر (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, پوچ), -1);
            } وگرنه {
		اگر (op->vt == پوچ)
		    برو error;
                sv = *op->vt;
                اگر (op->reg >= 0) {
                    sv.r = op->reg;
                    اگر (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } وگرنه {
        add_char:
            cstr_ccat(out_str, c);
            اگر (c == '\0')
                بشکن;
        }
    }
}


ایستا تهی parse_asm_operands(ASMOperand *operands, صحیح *nb_operands_ptr,
                               صحیح is_output)
{
    ASMOperand *op;
    صحیح nb_operands;
    نویسه* astr;

    اگر (tok != ':') {
        nb_operands = *nb_operands_ptr;
        برای(;;) {
            اگر (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            اگر (tok == '[') {
                next();
                اگر (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, اندازه op->constraint, astr);
            skip('(');
            gexpr();
            اگر (is_output) {
                اگر (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } وگرنه {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                اگر ((vtop->r & VT_LVAL) &&
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
            اگر (tok == ',') {
                next();
            } وگرنه {
                بشکن;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC تهی asm_instr(تهی)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    صحیح nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    وقتی (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, اندازه(clobber_regs));
    اگر (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        اگر (tok == ':') {
            next();
            اگر (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                اگر (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    برای(;;) {
                        اگر (tok == ':')
                          بشکن;
                        اگر (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        اگر (tok == ',') {
                            next();
                        } وگرنه {
                            بشکن;
                        }
                    }
                }
                اگر (tok == ':') {
                    /* goto labels */
                    next();
                    برای (;;) {
                        Sym *csym;
                        صحیح asmname;
                        اگر (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        اگر (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       اندازه(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        اگر (!csym) {
                            csym = label_افزودن(&global_label_پشته, tok,
                                              LABEL_FORWARD);
                        } وگرنه {
                            اگر (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        اگر (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        اگر (tok != ',')
                          بشکن;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    اگر (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (نویسه *)astr.data);
#endif
    اگر (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (نویسه *)astr.data);
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
    اگر (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    برای(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC تهی asm_global_instr(تهی)
{
    CString *astr;
    صحیح saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    اگر (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (نویسه *)astr->data);
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
#وگرنه
ST_FUNC صحیح tcc_assemble(TCCState *s1, صحیح do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC تهی asm_instr(تهی)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC تهی asm_global_instr(تهی)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
