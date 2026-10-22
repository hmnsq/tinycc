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
#অন্তর্ভাৱ "tcc.h"
#ifdef CONFIG_TCC_ASM

স্থির Section *last_text_section; /* to handle .previous asm directive */
স্থির পূর্ণাঙ্ক asmgoto_n;

স্থির পূর্ণাঙ্ক tcc_assemble_internal(TCCState *s1, পূর্ণাঙ্ক do_preprocess, পূর্ণাঙ্ক global);
স্থির Sym* asm_new_label(TCCState *s1, পূর্ণাঙ্ক label, পূর্ণাঙ্ক is_local);
স্থির Sym* asm_new_label1(TCCState *s1, পূর্ণাঙ্ক label, পূর্ণাঙ্ক is_local, পূর্ণাঙ্ক sh_অঙ্ক, পূর্ণাঙ্ক মান);

#যদি PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC শূন্য gen_addr64(পূর্ণাঙ্ক r, Sym *sym, int64_t c)
{
    যদি (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC শূন্য gen_expr64(ৰাশিমালা_মান *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

স্থির পূর্ণাঙ্ক asm_get_prefix_name(TCCState *s1, ধ্রুৱ ৱর্ণ *prefix, unsigned পূর্ণাঙ্ক n)
{
    ৱর্ণ buf[64];
    snprintf(buf, পরিমাণ(buf), "%s%u", prefix, n);
    ঘূৰাই tok_alloc_const(buf);
}

ST_FUNC পূর্ণাঙ্ক asm_get_local_label_name(TCCState *s1, unsigned পূর্ণাঙ্ক n)
{
    ঘূৰাই asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
স্থির পূর্ণাঙ্ক asm2cname(পূর্ণাঙ্ক v, পূর্ণাঙ্ক *addeddot)
{
    ধ্রুৱ ৱর্ণ *name;
    *addeddot = 0;
    যদি (!tcc_state->leading_underscore)
      ঘূৰাই v;
    name = get_tok_str(v, রিক্ত);
    যদি (!name)
      ঘূৰাই v;
    যদি (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } অন্যথা যদি (!strchr(name, '.')) {
        ৱর্ণ newname[256];
        snprintf(newname, পরিমাণ newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ঘূৰাই v;
}

স্থির Sym *asm_label_find(পূর্ণাঙ্ক v)
{
    Sym *sym;
    পূর্ণাঙ্ক addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    যেতিয়ালৈ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    ঘূৰাই sym;
}

স্থির Sym *asm_label_ঠেলো(পূর্ণাঙ্ক v)
{
    পূর্ণাঙ্ক addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ঠেলো(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    যদি (addeddot)
        sym->asm_label = v;
    ঘূৰাই sym;
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
ST_FUNC Sym* get_asm_sym(পূর্ণাঙ্ক name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    যদি (!sym) {
	sym = asm_label_ঠেলো(name);
	যদি (csym)
	  sym->c = csym->c;
    }
    ঘূৰাই sym;
}

স্থির Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    ৱর্ণ buf[100]; পূর্ণাঙ্ক label; Sym *sym;
    snprintf(buf, পরিমাণ buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    ঘূৰাই sym ? sym : asm_new_label1(s1, label, 1, sec->sh_অঙ্ক, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

স্থির শূন্য asm_ৰাশিমালা_unary(TCCState *s1, ৰাশিমালা_মান *pe)
{
    Sym *sym;
    পূর্ণাঙ্ক op, label;
    uint64_t n;
    ধ্রুৱ ৱর্ণ *p;

    ৱিকল্প(tok) {
    পক্ষ TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (ৱর্ণ **)&p, 0);
        যদি (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            যদি (*p == 'b') {
                /* backward : find the last corresponding defined label */
                যদি (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                যদি (!sym)
                    tcc_error("local label '%d' not found backward", (পূর্ণাঙ্ক)n);
            } অন্যথা {
                /* forward */
                যদি (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ঠেলো(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } অন্যথা যদি (*p == '\0') {
            pe->v = n;
            pe->sym = রিক্ত;
	    pe->pcrel = 0;
        } অন্যথা {
            tcc_error("invalid number syntax");
        }
        next();
        ভঙ্গ;
    পক্ষ '+':
        next();
        asm_ৰাশিমালা_unary(s1, pe);
        ভঙ্গ;
    পক্ষ '-':
    পক্ষ '~':
        op = tok;
        next();
        asm_ৰাশিমালা_unary(s1, pe);
        যদি (pe->sym)
            tcc_error("invalid operation with label");
        যদি (op == '-')
            pe->v = -pe->v;
        অন্যথা
            pe->v = ~pe->v;
        ভঙ্গ;
    পক্ষ TOK_CCHAR:
    পক্ষ TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = রিক্ত;
	pe->pcrel = 0;
	next();
	ভঙ্গ;
    পক্ষ '(':
        next();
        asm_ৰাশিমালা(s1, pe);
        skip(')');
        ভঙ্গ;
    পক্ষ '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        ভঙ্গ;
    স্ৱভাৱ:
        যদি (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, রিক্ত);
	    esym = elfsym(sym);
            যদি (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_মান;
                pe->sym = রিক্ত;
		pe->pcrel = 0;
            } অন্যথা {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } অন্যথা {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        ভঙ্গ;
    }
}
    
স্থির শূন্য asm_ৰাশিমালা_prod(TCCState *s1, ৰাশিমালা_মান *pe)
{
    পূর্ণাঙ্ক op;
    ৰাশিমালা_মান e2;

    asm_ৰাশিমালা_unary(s1, pe);
    বাবে(;;) {
        op = tok;
        যদি (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            ভঙ্গ;
        next();
        asm_ৰাশিমালা_unary(s1, &e2);
        যদি (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ৱিকল্প(op) {
        পক্ষ '*':
            pe->v *= e2.v;
            ভঙ্গ;
        পক্ষ '/':  
            যদি (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            ভঙ্গ;
        পক্ষ '%':  
            যদি (e2.v == 0)
                গচ্ছ div_error;
            pe->v %= e2.v;
            ভঙ্গ;
        পক্ষ TOK_SHL:
            pe->v <<= e2.v;
            ভঙ্গ;
        স্ৱভাৱ:
        পক্ষ TOK_SAR:
            pe->v >>= e2.v;
            ভঙ্গ;
        }
    }
}

স্থির শূন্য asm_ৰাশিমালা_logic(TCCState *s1, ৰাশিমালা_মান *pe)
{
    পূর্ণাঙ্ক op;
    ৰাশিমালা_মান e2;

    asm_ৰাশিমালা_prod(s1, pe);
    বাবে(;;) {
        op = tok;
        যদি (op != '&' && op != '|' && op != '^')
            ভঙ্গ;
        next();
        asm_ৰাশিমালা_prod(s1, &e2);
        যদি (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ৱিকল্প(op) {
        পক্ষ '&':
            pe->v &= e2.v;
            ভঙ্গ;
        পক্ষ '|':  
            pe->v |= e2.v;
            ভঙ্গ;
        স্ৱভাৱ:
        পক্ষ '^':
            pe->v ^= e2.v;
            ভঙ্গ;
        }
    }
}

স্থির অন্তঃস্থ শূন্য asm_ৰাশিমালা_sum(TCCState *s1, ৰাশিমালা_মান *pe)
{
    পূর্ণাঙ্ক op;
    ৰাশিমালা_মান e2;

    asm_ৰাশিমালা_logic(s1, pe);
    বাবে(;;) {
        op = tok;
        যদি (op != '+' && op != '-')
            ভঙ্গ;
        next();
        asm_ৰাশিমালা_logic(s1, &e2);
        যদি (op == '+') {
            যদি (pe->sym != রিক্ত && e2.sym != রিক্ত)
                গচ্ছ cannot_relocate;
            pe->v += e2.v;
            যদি (pe->sym == রিক্ত && e2.sym != রিক্ত)
                pe->sym = e2.sym;
        } অন্যথা {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    যদি (!e2.sym) {
		/* OK */
	    } অন্যথা যদি (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = রিক্ত; /* same symbols can be subtracted to NULL */
	    } অন্যথা {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		যদি (!esym2)
		    গচ্ছ cannot_relocate;
		যদি (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (পূর্ণাঙ্ক)(esym1->st_মান - esym2->st_মান);
		    pe->sym = রিক্ত;
		} অন্যথা যদি (esym2->st_shndx == cur_text_section->sh_অঙ্ক) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (পূর্ণাঙ্ক)(0 - esym2->st_মান);
		    pe->pcrel = 1;
		    e2.sym = রিক্ত;
		} অন্যথা {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

স্থির অন্তঃস্থ শূন্য asm_ৰাশিমালা_cmp(TCCState *s1, ৰাশিমালা_মান *pe)
{
    পূর্ণাঙ্ক op;
    ৰাশিমালা_মান e2;

    asm_ৰাশিমালা_sum(s1, pe);
    বাবে(;;) {
        op = tok;
	যদি (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            ভঙ্গ;
        next();
        asm_ৰাশিমালা_sum(s1, &e2);
        যদি (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ৱিকল্প(op) {
	পক্ষ TOK_EQ:
	    pe->v = pe->v == e2.v;
	    ভঙ্গ;
	পক্ষ TOK_NE:
	    pe->v = pe->v != e2.v;
	    ভঙ্গ;
	পক্ষ TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    ভঙ্গ;
	পক্ষ TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    ভঙ্গ;
	পক্ষ TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    ভঙ্গ;
	পক্ষ TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    ভঙ্গ;
        স্ৱভাৱ:
            ভঙ্গ;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC শূন্য asm_ৰাশিমালা(TCCState *s1, ৰাশিমালা_মান *pe)
{
    asm_ৰাশিমালা_cmp(s1, pe);
}

ST_FUNC পূর্ণাঙ্ক asm_int_ৰাশিমালা(TCCState *s1)
{
    ৰাশিমালা_মান e;
    asm_ৰাশিমালা(s1, &e);
    যদি (e.sym)
        expect("constant");
    যদি ((পূর্ণাঙ্ক)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    ঘূৰাই e.v;
}

স্থির Sym* asm_new_label1(TCCState *s1, পূর্ণাঙ্ক label, পূর্ণাঙ্ক is_local,
                           পূর্ণাঙ্ক sh_অঙ্ক, পূর্ণাঙ্ক মান)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    যদি (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        যদি (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            যদি (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                গচ্ছ new_label;
            যদি (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, রিক্ত));
        }
    } অন্যথা {
    new_label:
        sym = asm_label_ঠেলো(label);
    }
    যদি (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_অঙ্ক;
    esym->st_মান = মান;
    যদি (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    ঘূৰাই sym;
}

স্থির Sym* asm_new_label(TCCState *s1, পূর্ণাঙ্ক label, পূর্ণাঙ্ক is_local)
{
    ঘূৰাই asm_new_label1(s1, label, is_local, cur_text_section->sh_অঙ্ক, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
স্থির Sym* set_প্ৰতীক(TCCState *s1, পূর্ণাঙ্ক label)
{
    long n;
    ৰাশিমালা_মান e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_ৰাশিমালা(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    যদি (esym)
	n += esym->st_মান;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    ঘূৰাই sym;
}

স্থির শূন্য use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

স্থির শূন্য use_section(TCCState *s1, ধ্রুৱ ৱর্ণ *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

স্থির শূন্য ঠেলো_section(TCCState *s1, ধ্রুৱ ৱর্ণ *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

স্থির শূন্য বেৰ_কৰো_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    যদি (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = রিক্ত;
    use_section1(s1, prev);
}

স্থির শূন্য asm_parse_directive(TCCState *s1, পূর্ণাঙ্ক global)
{
    পূর্ণাঙ্ক n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    ৱিকল্প(tok) {
    পক্ষ TOK_ASMDIR_align:
    পক্ষ TOK_ASMDIR_balign:
    পক্ষ TOK_ASMDIR_p2align:
    পক্ষ TOK_ASMDIR_skip:
    পক্ষ TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_ৰাশিমালা(s1);
        যদি (tok1 == TOK_ASMDIR_p2align)
        {
            যদি (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        যদি (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            যদি (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            যদি (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } অন্যথা {
	    যদি (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        যদি (tok == ',') {
            next();
            v = asm_int_ৰাশিমালা(s1), c = 0;
        }
    zero_pad:
	যদি ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        যদি (sec->sh_type != SHT_NOBITS) {
            যদি (c) {
                gen_fill_nops(size);
                ভঙ্গ;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_quad:
#যদি PTR_SIZE == 8
	size = 8;
	গচ্ছ asm_data;
#অন্যথা
        next();
        বাবে(;;) {
            uint64_t vl;
            ধ্রুৱ ৱর্ণ *p;

            p = tokc.str.data;
            যদি (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (ৱর্ণ **)&p, 0);
            যদি (*p != '\0')
                গচ্ছ error_constant;
            next();
            যদি (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } অন্যথা {
                ind += 8;
            }
            যদি (tok != ',')
                ভঙ্গ;
            next();
        }
        ভঙ্গ;
#endif
    পক্ষ TOK_ASMDIR_byte:
        size = 1;
        গচ্ছ asm_data;
    পক্ষ TOK_ASMDIR_word:
    পক্ষ TOK_ASMDIR_short:
        size = 2;
        গচ্ছ asm_data;
    পক্ষ TOK_ASMDIR_long:
    পক্ষ TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        বাবে(;;) {
            ৰাশিমালা_মান e;
            asm_ৰাশিমালা(s1, &e);
            যদি (sec->sh_type != SHT_NOBITS) {
                যদি (size == 4) {
                    gen_expr32(&e);
#যদি PTR_SIZE == 8
		} অন্যথা যদি (size == 8) {
		    gen_expr64(&e);
#endif
                } অন্যথা {
                    যদি (e.sym)
                        expect("constant");
                    যদি (size == 1)
                        g(e.v);
                    অন্যথা
                        gen_le16(e.v);
                }
            } অন্যথা {
                ind += size;
            }
            যদি (tok != ',')
                ভঙ্গ;
            next();
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_fill:
        {
            পূর্ণাঙ্ক repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_ৰাশিমালা(s1);
            যদি (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                ভঙ্গ;
            }
            size = 1;
            val = 0;
            যদি (tok == ',') {
                next();
                size = asm_int_ৰাশিমালা(s1);
                যদি (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    ভঙ্গ;
                }
                যদি (size > 8)
                    size = 8;
                যদি (tok == ',') {
                    next();
                    val = asm_int_ৰাশিমালা(s1);
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
            বাবে(i = 0; i < repeat; i++) {
                বাবে(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_rept:
        {
            পূর্ণাঙ্ক repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_ৰাশিমালা(s1);
            init_str = tok_str_alloc();
            যেতিয়ালৈ (next(), tok != TOK_ASMDIR_endr) {
                যদি (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            যেতিয়ালৈ (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            ভঙ্গ;
        }
    পক্ষ TOK_ASMDIR_org:
        {
	    ৰাশিমালা_মান e;
	    ElfSym *esym;
            next();
	    asm_ৰাশিমালা(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    যদি (esym) {
		যদি (esym->st_shndx != cur_text_section->sh_অঙ্ক)
		  expect("constant or same-section symbol");
		n += esym->st_মান;
	    }
            যদি (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            গচ্ছ zero_pad;
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	যদি (tok == ',')
	    set_প্ৰতীক(s1, tok1);
	ভঙ্গ;
    পক্ষ TOK_ASMDIR_globl:
    পক্ষ TOK_ASMDIR_global:
    পক্ষ TOK_ASMDIR_weak:
    পক্ষ TOK_ASMDIR_hidden:
	tok1 = tok;
	কৰা { 
            Sym *sym;
            next();
	    যদি (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, রিক্ত);
	    যদি (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            যদি (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    অন্যথা যদি (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} যেতিয়ালৈ (tok == ',');
	ভঙ্গ;
    পক্ষ TOK_ASMDIR_string:
    পক্ষ TOK_ASMDIR_ascii:
    পক্ষ TOK_ASMDIR_asciz:
        {
            ধ্রুৱ ৱর্ণ *p;
            পূর্ণাঙ্ক i, size, t;

            t = tok;
            next();
            বাবে(;;) {
                যদি (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                যদি (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                বাবে(i = 0; i < size; i++)
                    g(p[i]);
                next();
                যদি (tok == ',') {
                    next();
                } অন্যথা যদি (tok != TOK_STR) {
                    ভঙ্গ;
                }
            }
	}
	ভঙ্গ;
    পক্ষ TOK_ASMDIR_text:
    পক্ষ TOK_ASMDIR_data:
    পক্ষ TOK_ASMDIR_bss:
	{ 
            ৱর্ণ sname[64];
            tok1 = tok;
            n = 0;
            next();
            যদি (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_ৰাশিমালা(s1);
		next();
            }
            যদি (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, রিক্ত), n);
            অন্যথা
                sprintf(sname, "%s", get_tok_str(tok1, রিক্ত));
            use_section(s1, sname);
	}
	ভঙ্গ;
    পক্ষ TOK_ASMDIR_file:
        {
            ধ্রুৱ ৱর্ণ *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            যদি (tok == TOK_PPNUM)
                next();
            যদি (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } অন্যথা যদি (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } অন্যথা {
                skip_to_eol(0);
                ভঙ্গ;
            }
            tccpp_putfile(p);
            next();
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_ident:
        {
            ৱর্ণ ident[256];

            ident[0] = '\0';
            next();
            যদি (tok == TOK_STR)
                pstrcat(ident, পরিমাণ(ident), tokc.str.data);
            অন্যথা
                pstrcat(ident, পরিমাণ(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    যদি (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            যদি (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, রিক্ত));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, রিক্ত));
            next();
            skip(',');
            n = asm_int_ৰাশিমালা(s1);
            esym = elfsym(sym);
            যদি (esym) {
                esym->st_size = n;
            }
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_type:
        { 
            Sym *sym;
            ধ্রুৱ ৱর্ণ *newtype;
            পূর্ণাঙ্ক st_type;

            next();
	    যদি (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, রিক্ত);
            next();
            skip(',');
            যদি (tok == TOK_STR) {
                newtype = tokc.str.data;
            } অন্যথা {
                যদি (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, রিক্ত);
            }

            যদি (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                যদি (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                যদি (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } অন্যথা যদি (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                গচ্ছ set_st_type;
            } অন্যথা
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, রিক্ত), sym->type.t, newtype);

            next();
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_pushsection:
    পক্ষ TOK_ASMDIR_section:
        {
            ৱর্ণ sname[256];
	    পূর্ণাঙ্ক old_nb_section = s1->nb_sections;
            পূর্ণাঙ্ক flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            যেতিয়ালৈ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                যদি (tok == TOK_STR)
                    pstrcat(sname, পরিমাণ(sname), tokc.str.data);
                অন্যথা
                    pstrcat(sname, পরিমাণ(sname), get_tok_str(tok, রিক্ত));
                next();
            }
            যদি (tok == ',') {
                ধ্রুৱ ৱর্ণ *p;
                /* skip section options */
                next();
                যদি (tok != TOK_STR)
                    expect("string constant");
                বাবে (p = tokc.str.data; *p; ++p) {
                    যদি (*p == 'w')
                        flags |= SHF_WRITE;
                    যদি (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                যদি (tok == ',') {
                    next();
                    যদি (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    যদি (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    অন্যথা
	        ঠেলো_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    যদি (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                যদি (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            যদি (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_popsection:
	next();
	বেৰ_কৰো_section(s1);
	ভঙ্গ;
#ifdef TCC_TARGET_I386
    পক্ষ TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        ভঙ্গ;
    পক্ষ TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        ভঙ্গ;
#endif
#যদি PTR_SIZE == 8
    /* added for compatibility with GAS */
    পক্ষ TOK_ASMDIR_code64:
        next();
        ভঙ্গ;
#endif
#ifdef TCC_TARGET_RISCV64
    পক্ষ TOK_ASMDIR_option:
        next();
        ৱিকল্প(tok){
            পক্ষ TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            পক্ষ TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            পক্ষ TOK_ASM_pic:
            পক্ষ TOK_ASM_nopic:
            পক্ষ TOK_ASM_relax:
            পক্ষ TOK_ASM_norelax:
            পক্ষ TOK_ASM_ঠেলো:
            পক্ষ TOK_ASM_বেৰ_কৰো:
                /* TODO: unimplemented */
                next();
                ভঙ্গ;
            পক্ষ TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, রিক্ত));
                ভঙ্গ;
            স্ৱভাৱ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, রিক্ত));
                ভঙ্গ;
        }
        ভঙ্গ;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    পক্ষ TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	ভঙ্গ;
    পক্ষ TOK_ASMDIR_reloc:
	{
	    ৰাশিমালা_মান e;
	    ধ্রুৱ ৱর্ণ *reloc_name;
	    পূর্ণাঙ্ক reloc_type = -1;

	    next();
	    asm_ৰাশিমালা(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, রিক্ত);
#যদি defined(TCC_TARGET_ARM64)
	    যদি (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#নোচেদ্যদি defined(TCC_TARGET_RISCV64)
	    যদি (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    অন্যথা যদি (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    যদি (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, রিক্ত), e.v, reloc_type, 0);
	    next();
	}
	ভঙ্গ;
    স্ৱভাৱ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, রিক্ত));
        ভঙ্গ;
    }
}


/* assemble a file */
স্থির পূর্ণাঙ্ক tcc_assemble_internal(TCCState *s1, পূর্ণাঙ্ক do_preprocess, পূর্ণাঙ্ক global)
{
    পূর্ণাঙ্ক opcode;
    পূর্ণাঙ্ক saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    যদি (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    বাবে(;;) {
        next();
        যদি (tok == TOK_EOF)
            ভঙ্গ;
        tcc_debug_সাৰি(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#যদি !defined(TCC_TARGET_ARM64)
        যদি (tok == '#') {
            /* horrible gas comment */
            যেতিয়ালৈ (tok != TOK_LINEFEED)
                next();
        } অন্যথা
#endif
        যদি (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } অন্যথা যদি (tok == TOK_PPNUM) {
            ধ্রুৱ ৱর্ণ *p;
            পূর্ণাঙ্ক n;
            p = tokc.str.data;
            n = strtoul(p, (ৱর্ণ **)&p, 10);
            যদি (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            গচ্ছ redo;
        } অন্যথা যদি (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            যদি (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                গচ্ছ redo;
            } অন্যথা যদি (tok == '=') {
		set_প্ৰতীক(s1, opcode);
                গচ্ছ redo;
            } অন্যথা {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        যদি (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    ঘূৰাই 0;
}

/* Assemble the current file */
ST_FUNC পূর্ণাঙ্ক tcc_assemble(TCCState *s1, পূর্ণাঙ্ক do_preprocess)
{
    পূর্ণাঙ্ক ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    ঘূৰাই ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
স্থির শূন্য tcc_assemble_inline(TCCState *s1, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক len, পূর্ণাঙ্ক global)
{
    ধ্রুৱ পূর্ণাঙ্ক *saved_macro_ptr = macro_ptr;
    পূর্ণাঙ্ক dotid = set_idnum('.', IS_ID);
#যদি !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    পূর্ণাঙ্ক dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = রিক্ত;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#যদি !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC পূর্ণাঙ্ক find_constraint(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, 
                           ধ্রুৱ ৱর্ণ *name, ধ্রুৱ ৱর্ণ **pp)
{
    পূর্ণাঙ্ক index;
    TokenSym *ts;
    ধ্রুৱ ৱর্ণ *p;

    যদি (isnum(*name)) {
        index = 0;
        যেতিয়ালৈ (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        যদি ((unsigned)index >= nb_operands)
            index = -1;
    } অন্যথা যদি (*name == '[') {
        name++;
        p = strchr(name, ']');
        যদি (p) {
            ts = tok_alloc(name, p - name);
            বাবে(index = 0; index < nb_operands; index++) {
                যদি (operands[index].id == ts->tok)
                    গচ্ছ found;
            }
            index = -1;
        found:
            name = p + 1;
        } অন্যথা {
            index = -1;
        }
    } অন্যথা {
        index = -1;
    }
    যদি (pp)
        *pp = name;
    ঘূৰাই index;
}

স্থির শূন্য subst_asm_operands(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, 
                               CString *out_str, ধ্রুৱ ৱর্ণ *str)
{
    পূর্ণাঙ্ক c, index, modifier;
    ASMOperand *op;
    SValue sv;

    বাবে(;;) {
        c = *str++;
        যদি (c == '%') {
            যদি (*str == '%') {
                str++;
                গচ্ছ add_char;
            }
            modifier = 0;
            যদি (*str == 'c' || *str == 'n' ||
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
            যদি (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            যদি (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, রিক্ত), -1);
            } অন্যথা {
		যদি (op->vt == রিক্ত)
		    গচ্ছ error;
                sv = *op->vt;
                যদি (op->reg >= 0) {
                    sv.r = op->reg;
                    যদি (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } অন্যথা {
        add_char:
            cstr_ccat(out_str, c);
            যদি (c == '\0')
                ভঙ্গ;
        }
    }
}


স্থির শূন্য parse_asm_operands(ASMOperand *operands, পূর্ণাঙ্ক *nb_operands_ptr,
                               পূর্ণাঙ্ক is_output)
{
    ASMOperand *op;
    পূর্ণাঙ্ক nb_operands;
    ৱর্ণ* astr;

    যদি (tok != ':') {
        nb_operands = *nb_operands_ptr;
        বাবে(;;) {
            যদি (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            যদি (tok == '[') {
                next();
                যদি (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, পরিমাণ op->constraint, astr);
            skip('(');
            gexpr();
            যদি (is_output) {
                যদি (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } অন্যথা {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                যদি ((vtop->r & VT_LVAL) &&
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
            যদি (tok == ',') {
                next();
            } অন্যথা {
                ভঙ্গ;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC শূন্য asm_instr(শূন্য)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    পূর্ণাঙ্ক nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    যেতিয়ালৈ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, পরিমাণ(clobber_regs));
    যদি (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        যদি (tok == ':') {
            next();
            যদি (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                যদি (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    বাবে(;;) {
                        যদি (tok == ':')
                          ভঙ্গ;
                        যদি (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        যদি (tok == ',') {
                            next();
                        } অন্যথা {
                            ভঙ্গ;
                        }
                    }
                }
                যদি (tok == ':') {
                    /* goto labels */
                    next();
                    বাবে (;;) {
                        Sym *csym;
                        পূর্ণাঙ্ক asmname;
                        যদি (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        যদি (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       পরিমাণ(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        যদি (!csym) {
                            csym = label_ঠেলো(&global_label_স্তূপ, tok,
                                              LABEL_FORWARD);
                        } অন্যথা {
                            যদি (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        যদি (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        যদি (tok != ',')
                          ভঙ্গ;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    যদি (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (ৱর্ণ *)astr.data);
#endif
    যদি (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (ৱর্ণ *)astr.data);
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
    যদি (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    বাবে(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC শূন্য asm_global_instr(শূন্য)
{
    CString *astr;
    পূর্ণাঙ্ক saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    যদি (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (ৱর্ণ *)astr->data);
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
#অন্যথা
ST_FUNC পূর্ণাঙ্ক tcc_assemble(TCCState *s1, পূর্ণাঙ্ক do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC শূন্য asm_instr(শূন্য)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC শূন্য asm_global_instr(শূন্য)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
