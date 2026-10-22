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
#অন্তর্ভাব "tcc.h"
#ifdef CONFIG_TCC_ASM

স্থির Section *last_text_section; /* to handle .previous asm directive */
স্থির পূর্ণসংখ্যা asmgoto_n;

স্থির পূর্ণসংখ্যা tcc_assemble_internal(TCCState *s1, পূর্ণসংখ্যা do_preprocess, পূর্ণসংখ্যা global);
স্থির Sym* asm_new_label(TCCState *s1, পূর্ণসংখ্যা label, পূর্ণসংখ্যা is_local);
স্থির Sym* asm_new_label1(TCCState *s1, পূর্ণসংখ্যা label, পূর্ণসংখ্যা is_local, পূর্ণসংখ্যা sh_অঙ্ক, পূর্ণসংখ্যা মান);

#যদি PTR_আকার == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC শূন্য gen_addr64(পূর্ণসংখ্যা r, Sym *sym, int64_t c)
{
    যদি (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_তথ্য_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC শূন্য gen_expr64(রাশিমালা_মান *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

স্থির পূর্ণসংখ্যা asm_get_prefix_name(TCCState *s1, ধ্রুবক অক্ষর *prefix, unsigned পূর্ণসংখ্যা n)
{
    অক্ষর buf[64];
    snprintf(buf, আকার(buf), "%s%u", prefix, n);
    ফেরত tok_alloc_const(buf);
}

ST_FUNC পূর্ণসংখ্যা asm_get_local_label_name(TCCState *s1, unsigned পূর্ণসংখ্যা n)
{
    ফেরত asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
স্থির পূর্ণসংখ্যা asm2cname(পূর্ণসংখ্যা v, পূর্ণসংখ্যা *addeddot)
{
    ধ্রুবক অক্ষর *name;
    *addeddot = 0;
    যদি (!tcc_state->leading_underscore)
      ফেরত v;
    name = get_tok_str(v, ফাঁকা);
    যদি (!name)
      ফেরত v;
    যদি (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } অন্যথা যদি (!strchr(name, '.')) {
        অক্ষর newname[256];
        snprintf(newname, আকার newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ফেরত v;
}

স্থির Sym *asm_label_find(পূর্ণসংখ্যা v)
{
    Sym *sym;
    পূর্ণসংখ্যা addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    যখন (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->পূর্ব_tok;
    ফেরত sym;
}

স্থির Sym *asm_label_ঠেলো(পূর্ণসংখ্যা v)
{
    পূর্ণসংখ্যা addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ঠেলো(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    যদি (addeddot)
        sym->asm_label = v;
    ফেরত sym;
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
ST_FUNC Sym* get_asm_sym(পূর্ণসংখ্যা name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    যদি (!sym) {
	sym = asm_label_ঠেলো(name);
	যদি (csym)
	  sym->c = csym->c;
    }
    ফেরত sym;
}

স্থির Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    অক্ষর buf[100]; পূর্ণসংখ্যা label; Sym *sym;
    snprintf(buf, আকার buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    ফেরত sym ? sym : asm_new_label1(s1, label, 1, sec->sh_অঙ্ক, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

স্থির শূন্য asm_রাশিমালা_unary(TCCState *s1, রাশিমালা_মান *pe)
{
    Sym *sym;
    পূর্ণসংখ্যা op, label;
    uint64_t n;
    ধ্রুবক অক্ষর *p;

    নির্বাচন(tok) {
    ক্ষেত্র TOK_PPNUM:
        p = tokc.str.তথ্য;
        n = strtoull(p, (অক্ষর **)&p, 0);
        যদি (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            যদি (*p == 'b') {
                /* backward : find the last corresponding defined label */
                যদি (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->পূর্ব_tok;
                যদি (!sym)
                    tcc_error("local label '%d' not found backward", (পূর্ণসংখ্যা)n);
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
            pe->sym = ফাঁকা;
	    pe->pcrel = 0;
        } অন্যথা {
            tcc_error("invalid number syntax");
        }
        পরবর্তী();
        বিরতি;
    ক্ষেত্র '+':
        পরবর্তী();
        asm_রাশিমালা_unary(s1, pe);
        বিরতি;
    ক্ষেত্র '-':
    ক্ষেত্র '~':
        op = tok;
        পরবর্তী();
        asm_রাশিমালা_unary(s1, pe);
        যদি (pe->sym)
            tcc_error("invalid operation with label");
        যদি (op == '-')
            pe->v = -pe->v;
        অন্যথা
            pe->v = ~pe->v;
        বিরতি;
    ক্ষেত্র TOK_CCHAR:
    ক্ষেত্র TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ফাঁকা;
	pe->pcrel = 0;
	পরবর্তী();
	বিরতি;
    ক্ষেত্র '(':
        পরবর্তী();
        asm_রাশিমালা(s1, pe);
        skip(')');
        বিরতি;
    ক্ষেত্র '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        পরবর্তী();
        বিরতি;
    পূর্বনির্ধারিত:
        যদি (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ফাঁকা);
	    esym = elfsym(sym);
            যদি (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_মান;
                pe->sym = ফাঁকা;
		pe->pcrel = 0;
            } অন্যথা {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            পরবর্তী();
        } অন্যথা {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        বিরতি;
    }
}
    
স্থির শূন্য asm_রাশিমালা_prod(TCCState *s1, রাশিমালা_মান *pe)
{
    পূর্ণসংখ্যা op;
    রাশিমালা_মান e2;

    asm_রাশিমালা_unary(s1, pe);
    জন্য(;;) {
        op = tok;
        যদি (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            বিরতি;
        পরবর্তী();
        asm_রাশিমালা_unary(s1, &e2);
        যদি (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        নির্বাচন(op) {
        ক্ষেত্র '*':
            pe->v *= e2.v;
            বিরতি;
        ক্ষেত্র '/':  
            যদি (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            বিরতি;
        ক্ষেত্র '%':  
            যদি (e2.v == 0)
                যাও div_error;
            pe->v %= e2.v;
            বিরতি;
        ক্ষেত্র TOK_SHL:
            pe->v <<= e2.v;
            বিরতি;
        পূর্বনির্ধারিত:
        ক্ষেত্র TOK_SAR:
            pe->v >>= e2.v;
            বিরতি;
        }
    }
}

স্থির শূন্য asm_রাশিমালা_logic(TCCState *s1, রাশিমালা_মান *pe)
{
    পূর্ণসংখ্যা op;
    রাশিমালা_মান e2;

    asm_রাশিমালা_prod(s1, pe);
    জন্য(;;) {
        op = tok;
        যদি (op != '&' && op != '|' && op != '^')
            বিরতি;
        পরবর্তী();
        asm_রাশিমালা_prod(s1, &e2);
        যদি (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        নির্বাচন(op) {
        ক্ষেত্র '&':
            pe->v &= e2.v;
            বিরতি;
        ক্ষেত্র '|':  
            pe->v |= e2.v;
            বিরতি;
        পূর্বনির্ধারিত:
        ক্ষেত্র '^':
            pe->v ^= e2.v;
            বিরতি;
        }
    }
}

স্থির অন্তঃরেখ শূন্য asm_রাশিমালা_যোগ(TCCState *s1, রাশিমালা_মান *pe)
{
    পূর্ণসংখ্যা op;
    রাশিমালা_মান e2;

    asm_রাশিমালা_logic(s1, pe);
    জন্য(;;) {
        op = tok;
        যদি (op != '+' && op != '-')
            বিরতি;
        পরবর্তী();
        asm_রাশিমালা_logic(s1, &e2);
        যদি (op == '+') {
            যদি (pe->sym != ফাঁকা && e2.sym != ফাঁকা)
                যাও cannot_relocate;
            pe->v += e2.v;
            যদি (pe->sym == ফাঁকা && e2.sym != ফাঁকা)
                pe->sym = e2.sym;
        } অন্যথা {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    যদি (!e2.sym) {
		/* OK */
	    } অন্যথা যদি (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ফাঁকা; /* same symbols can be subtracted to NULL */
	    } অন্যথা {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		যদি (!esym2)
		    যাও cannot_relocate;
		যদি (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (পূর্ণসংখ্যা)(esym1->st_মান - esym2->st_মান);
		    pe->sym = ফাঁকা;
		} অন্যথা যদি (esym2->st_shndx == cur_text_section->sh_অঙ্ক) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (পূর্ণসংখ্যা)(0 - esym2->st_মান);
		    pe->pcrel = 1;
		    e2.sym = ফাঁকা;
		} অন্যথা {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

স্থির অন্তঃরেখ শূন্য asm_রাশিমালা_cmp(TCCState *s1, রাশিমালা_মান *pe)
{
    পূর্ণসংখ্যা op;
    রাশিমালা_মান e2;

    asm_রাশিমালা_যোগ(s1, pe);
    জন্য(;;) {
        op = tok;
	যদি (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            বিরতি;
        পরবর্তী();
        asm_রাশিমালা_যোগ(s1, &e2);
        যদি (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        নির্বাচন(op) {
	ক্ষেত্র TOK_EQ:
	    pe->v = pe->v == e2.v;
	    বিরতি;
	ক্ষেত্র TOK_NE:
	    pe->v = pe->v != e2.v;
	    বিরতি;
	ক্ষেত্র TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    বিরতি;
	ক্ষেত্র TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    বিরতি;
	ক্ষেত্র TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    বিরতি;
	ক্ষেত্র TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    বিরতি;
        পূর্বনির্ধারিত:
            বিরতি;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC শূন্য asm_রাশিমালা(TCCState *s1, রাশিমালা_মান *pe)
{
    asm_রাশিমালা_cmp(s1, pe);
}

ST_FUNC পূর্ণসংখ্যা asm_int_রাশিমালা(TCCState *s1)
{
    রাশিমালা_মান e;
    asm_রাশিমালা(s1, &e);
    যদি (e.sym)
        expect("constant");
    যদি ((পূর্ণসংখ্যা)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    ফেরত e.v;
}

স্থির Sym* asm_new_label1(TCCState *s1, পূর্ণসংখ্যা label, পূর্ণসংখ্যা is_local,
                           পূর্ণসংখ্যা sh_অঙ্ক, পূর্ণসংখ্যা মান)
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
                যাও new_label;
            যদি (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ফাঁকা));
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
    ফেরত sym;
}

স্থির Sym* asm_new_label(TCCState *s1, পূর্ণসংখ্যা label, পূর্ণসংখ্যা is_local)
{
    ফেরত asm_new_label1(s1, label, is_local, cur_text_section->sh_অঙ্ক, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
স্থির Sym* set_প্রতীক(TCCState *s1, পূর্ণসংখ্যা label)
{
    long n;
    রাশিমালা_মান e;
    Sym *sym;
    ElfSym *esym;
    পরবর্তী();
    asm_রাশিমালা(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    যদি (esym)
	n += esym->st_মান;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    ফেরত sym;
}

স্থির শূন্য use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->তথ্য_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->তথ্য_offset;
}

স্থির শূন্য use_section(TCCState *s1, ধ্রুবক অক্ষর *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

স্থির শূন্য ঠেলো_section(TCCState *s1, ধ্রুবক অক্ষর *name)
{
    Section *sec = find_section(s1, name);
    sec->পূর্ব = cur_text_section;
    use_section1(s1, sec);
}

স্থির শূন্য বের_করো_section(TCCState *s1)
{
    Section *পূর্ব = cur_text_section->পূর্ব;
    যদি (!পূর্ব)
        tcc_error(".popsection without .pushsection");
    cur_text_section->পূর্ব = ফাঁকা;
    use_section1(s1, পূর্ব);
}

স্থির শূন্য asm_parse_directive(TCCState *s1, পূর্ণসংখ্যা global)
{
    পূর্ণসংখ্যা n, offset, v, আকার_2, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    নির্বাচন(tok) {
    ক্ষেত্র TOK_ASMDIR_align:
    ক্ষেত্র TOK_ASMDIR_balign:
    ক্ষেত্র TOK_ASMDIR_p2align:
    ক্ষেত্র TOK_ASMDIR_skip:
    ক্ষেত্র TOK_ASMDIR_space:
        tok1 = tok;
        পরবর্তী();
        n = asm_int_রাশিমালা(s1);
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
            আকার_2 = offset - ind;
            /* the section must have a compatible alignment */
            যদি (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } অন্যথা {
	    যদি (n < 0)
	        n = 0;
            আকার_2 = n, c = 0;
        }
        v = 0;
        যদি (tok == ',') {
            পরবর্তী();
            v = asm_int_রাশিমালা(s1), c = 0;
        }
    zero_pad:
	যদি ((uint64_t)ind + আকার_2 >= 1<<30)
	    tcc_error("too much data");
        যদি (sec->sh_type != SHT_NOBITS) {
            যদি (c) {
                gen_fill_nops(আকার_2);
                বিরতি;
            }
            sec->তথ্য_offset = ind;
            ptr = section_ptr_add(sec, আকার_2);
            memset(ptr, v, আকার_2);
        }
        ind += আকার_2;
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_quad:
#যদি PTR_আকার == 8
	আকার_2 = 8;
	যাও asm_তথ্য;
#অন্যথা
        পরবর্তী();
        জন্য(;;) {
            uint64_t vl;
            ধ্রুবক অক্ষর *p;

            p = tokc.str.তথ্য;
            যদি (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (অক্ষর **)&p, 0);
            যদি (*p != '\0')
                যাও error_constant;
            পরবর্তী();
            যদি (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } অন্যথা {
                ind += 8;
            }
            যদি (tok != ',')
                বিরতি;
            পরবর্তী();
        }
        বিরতি;
#endif
    ক্ষেত্র TOK_ASMDIR_byte:
        আকার_2 = 1;
        যাও asm_তথ্য;
    ক্ষেত্র TOK_ASMDIR_word:
    ক্ষেত্র TOK_ASMDIR_short:
        আকার_2 = 2;
        যাও asm_তথ্য;
    ক্ষেত্র TOK_ASMDIR_long:
    ক্ষেত্র TOK_ASMDIR_int:
        আকার_2 = 4;
    asm_তথ্য:
        পরবর্তী();
        জন্য(;;) {
            রাশিমালা_মান e;
            asm_রাশিমালা(s1, &e);
            যদি (sec->sh_type != SHT_NOBITS) {
                যদি (আকার_2 == 4) {
                    gen_expr32(&e);
#যদি PTR_আকার == 8
		} অন্যথা যদি (আকার_2 == 8) {
		    gen_expr64(&e);
#endif
                } অন্যথা {
                    যদি (e.sym)
                        expect("constant");
                    যদি (আকার_2 == 1)
                        g(e.v);
                    অন্যথা
                        gen_le16(e.v);
                }
            } অন্যথা {
                ind += আকার_2;
            }
            যদি (tok != ',')
                বিরতি;
            পরবর্তী();
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_fill:
        {
            পূর্ণসংখ্যা repeat, আকার_2, val, i, j;
            uint8_t repeat_buf[8];
            পরবর্তী();
            repeat = asm_int_রাশিমালা(s1);
            যদি (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                বিরতি;
            }
            আকার_2 = 1;
            val = 0;
            যদি (tok == ',') {
                পরবর্তী();
                আকার_2 = asm_int_রাশিমালা(s1);
                যদি (আকার_2 < 0) {
                    tcc_error("size < 0; .fill ignored");
                    বিরতি;
                }
                যদি (আকার_2 > 8)
                    আকার_2 = 8;
                যদি (tok == ',') {
                    পরবর্তী();
                    val = asm_int_রাশিমালা(s1);
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
            জন্য(i = 0; i < repeat; i++) {
                জন্য(j = 0; j < আকার_2; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_rept:
        {
            পূর্ণসংখ্যা repeat;
            TokenString *init_str;
            পরবর্তী();
            repeat = asm_int_রাশিমালা(s1);
            init_str = tok_str_alloc();
            যখন (পরবর্তী(), tok != TOK_ASMDIR_endr) {
                যদি (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            যখন (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            পরবর্তী();
            বিরতি;
        }
    ক্ষেত্র TOK_ASMDIR_org:
        {
	    রাশিমালা_মান e;
	    ElfSym *esym;
            পরবর্তী();
	    asm_রাশিমালা(s1, &e);
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
            আকার_2 = n - ind;
            যাও zero_pad;
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_set:
	পরবর্তী();
	tok1 = tok;
	পরবর্তী();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	যদি (tok == ',')
	    set_প্রতীক(s1, tok1);
	বিরতি;
    ক্ষেত্র TOK_ASMDIR_globl:
    ক্ষেত্র TOK_ASMDIR_global:
    ক্ষেত্র TOK_ASMDIR_weak:
    ক্ষেত্র TOK_ASMDIR_hidden:
	tok1 = tok;
	করো { 
            Sym *sym;
            পরবর্তী();
	    যদি (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ফাঁকা);
	    যদি (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            যদি (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    অন্যথা যদি (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            পরবর্তী();
	} যখন (tok == ',');
	বিরতি;
    ক্ষেত্র TOK_ASMDIR_string:
    ক্ষেত্র TOK_ASMDIR_ascii:
    ক্ষেত্র TOK_ASMDIR_asciz:
        {
            ধ্রুবক অক্ষর *p;
            পূর্ণসংখ্যা i, আকার_2, t;

            t = tok;
            পরবর্তী();
            জন্য(;;) {
                যদি (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.তথ্য;
                আকার_2 = tokc.str.আকার_2;
                যদি (t == TOK_ASMDIR_ascii && আকার_2 > 0)
                    আকার_2--;
                জন্য(i = 0; i < আকার_2; i++)
                    g(p[i]);
                পরবর্তী();
                যদি (tok == ',') {
                    পরবর্তী();
                } অন্যথা যদি (tok != TOK_STR) {
                    বিরতি;
                }
            }
	}
	বিরতি;
    ক্ষেত্র TOK_ASMDIR_text:
    ক্ষেত্র TOK_ASMDIR_তথ্য:
    ক্ষেত্র TOK_ASMDIR_bss:
	{ 
            অক্ষর sname[64];
            tok1 = tok;
            n = 0;
            পরবর্তী();
            যদি (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_রাশিমালা(s1);
		পরবর্তী();
            }
            যদি (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ফাঁকা), n);
            অন্যথা
                sprintf(sname, "%s", get_tok_str(tok1, ফাঁকা));
            use_section(s1, sname);
	}
	বিরতি;
    ক্ষেত্র TOK_ASMDIR_file:
        {
            ধ্রুবক অক্ষর *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            পরবর্তী();
            যদি (tok == TOK_PPNUM)
                পরবর্তী();
            যদি (tok == TOK_PPSTR && tokc.str.তথ্য[0] == '"') {
                tokc.str.তথ্য[tokc.str.আকার_2 - 2] = 0;
                p = tokc.str.তথ্য + 1;
            } অন্যথা যদি (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } অন্যথা {
                skip_to_eol(0);
                বিরতি;
            }
            tccpp_putfile(p);
            পরবর্তী();
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_ident:
        {
            অক্ষর ident[256];

            ident[0] = '\0';
            পরবর্তী();
            যদি (tok == TOK_STR)
                pstrcat(ident, আকার(ident), tokc.str.তথ্য);
            অন্যথা
                pstrcat(ident, আকার(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            পরবর্তী();
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_আকার:
        { 
            Sym *sym;
            ElfSym *esym;

            পরবর্তী();
	    যদি (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            যদি (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ফাঁকা));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ফাঁকা));
            পরবর্তী();
            skip(',');
            n = asm_int_রাশিমালা(s1);
            esym = elfsym(sym);
            যদি (esym) {
                esym->st_আকার = n;
            }
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_type:
        { 
            Sym *sym;
            ধ্রুবক অক্ষর *newtype;
            পূর্ণসংখ্যা st_type;

            পরবর্তী();
	    যদি (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ফাঁকা);
            পরবর্তী();
            skip(',');
            যদি (tok == TOK_STR) {
                newtype = tokc.str.তথ্য;
            } অন্যথা {
                যদি (tok == '@' || tok == '%')
                    পরবর্তী();
                newtype = get_tok_str(tok, ফাঁকা);
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
                যাও set_st_type;
            } অন্যথা
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ফাঁকা), sym->type.t, newtype);

            পরবর্তী();
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_pushsection:
    ক্ষেত্র TOK_ASMDIR_section:
        {
            অক্ষর sname[256];
	    পূর্ণসংখ্যা old_nb_section = s1->nb_sections;
            পূর্ণসংখ্যা flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            পরবর্তী();
            sname[0] = '\0';
            যখন (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                যদি (tok == TOK_STR)
                    pstrcat(sname, আকার(sname), tokc.str.তথ্য);
                অন্যথা
                    pstrcat(sname, আকার(sname), get_tok_str(tok, ফাঁকা));
                পরবর্তী();
            }
            যদি (tok == ',') {
                ধ্রুবক অক্ষর *p;
                /* skip section options */
                পরবর্তী();
                যদি (tok != TOK_STR)
                    expect("string constant");
                জন্য (p = tokc.str.তথ্য; *p; ++p) {
                    যদি (*p == 'w')
                        flags |= SHF_WRITE;
                    যদি (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                পরবর্তী();
                যদি (tok == ',') {
                    পরবর্তী();
                    যদি (tok == '@' || tok == '%')
                        পরবর্তী();
                    পরবর্তী();
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
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_previous:
        { 
            Section *sec;
            পরবর্তী();
            যদি (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_popsection:
	পরবর্তী();
	বের_করো_section(s1);
	বিরতি;
#ifdef TCC_TARGET_I386
    ক্ষেত্র TOK_ASMDIR_code16:
        {
            পরবর্তী();
            s1->seg_আকার = 16;
        }
        বিরতি;
    ক্ষেত্র TOK_ASMDIR_code32:
        {
            পরবর্তী();
            s1->seg_আকার = 32;
        }
        বিরতি;
#endif
#যদি PTR_আকার == 8
    /* added for compatibility with GAS */
    ক্ষেত্র TOK_ASMDIR_code64:
        পরবর্তী();
        বিরতি;
#endif
#ifdef TCC_TARGET_RISCV64
    ক্ষেত্র TOK_ASMDIR_option:
        পরবর্তী();
        নির্বাচন(tok){
            ক্ষেত্র TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            ক্ষেত্র TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            ক্ষেত্র TOK_ASM_pic:
            ক্ষেত্র TOK_ASM_nopic:
            ক্ষেত্র TOK_ASM_relax:
            ক্ষেত্র TOK_ASM_norelax:
            ক্ষেত্র TOK_ASM_ঠেলো:
            ক্ষেত্র TOK_ASM_বের_করো:
                /* TODO: unimplemented */
                পরবর্তী();
                বিরতি;
            ক্ষেত্র TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ফাঁকা));
                বিরতি;
            পূর্বনির্ধারিত:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ফাঁকা));
                বিরতি;
        }
        বিরতি;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    ক্ষেত্র TOK_ASMDIR_symver:
	পরবর্তী();
	পরবর্তী();
        skip(',');
	পরবর্তী();
        skip('@');
	পরবর্তী();
	বিরতি;
    ক্ষেত্র TOK_ASMDIR_reloc:
	{
	    রাশিমালা_মান e;
	    ধ্রুবক অক্ষর *reloc_name;
	    পূর্ণসংখ্যা reloc_type = -1;

	    পরবর্তী();
	    asm_রাশিমালা(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ফাঁকা);
#যদি defined(TCC_TARGET_ARM64)
	    যদি (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#নতুবা_যদি defined(TCC_TARGET_RISCV64)
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
	    পরবর্তী();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, ফাঁকা), e.v, reloc_type, 0);
	    পরবর্তী();
	}
	বিরতি;
    পূর্বনির্ধারিত:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ফাঁকা));
        বিরতি;
    }
}


/* assemble a file */
স্থির পূর্ণসংখ্যা tcc_assemble_internal(TCCState *s1, পূর্ণসংখ্যা do_preprocess, পূর্ণসংখ্যা global)
{
    পূর্ণসংখ্যা opcode;
    পূর্ণসংখ্যা saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    যদি (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    জন্য(;;) {
        পরবর্তী();
        যদি (tok == TOK_EOF)
            বিরতি;
        tcc_debug_সারি(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#যদি !defined(TCC_TARGET_ARM64)
        যদি (tok == '#') {
            /* horrible gas comment */
            যখন (tok != TOK_LINEFEED)
                পরবর্তী();
        } অন্যথা
#endif
        যদি (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } অন্যথা যদি (tok == TOK_PPNUM) {
            ধ্রুবক অক্ষর *p;
            পূর্ণসংখ্যা n;
            p = tokc.str.তথ্য;
            n = strtoul(p, (অক্ষর **)&p, 10);
            যদি (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            পরবর্তী();
            skip(':');
            যাও redo;
        } অন্যথা যদি (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            পরবর্তী();
            যদি (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                পরবর্তী();
                যাও redo;
            } অন্যথা যদি (tok == '=') {
		set_প্রতীক(s1, opcode);
                যাও redo;
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
    ফেরত 0;
}

/* Assemble the current file */
ST_FUNC পূর্ণসংখ্যা tcc_assemble(TCCState *s1, পূর্ণসংখ্যা do_preprocess)
{
    পূর্ণসংখ্যা ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->তথ্য_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->তথ্য_offset = ind;
    tcc_debug_end(s1);
    ফেরত ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
স্থির শূন্য tcc_assemble_inline(TCCState *s1, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা len, পূর্ণসংখ্যা global)
{
    ধ্রুবক পূর্ণসংখ্যা *saved_macro_ptr = macro_ptr;
    পূর্ণসংখ্যা dotid = set_idnum('.', IS_ID);
#যদি !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    পূর্ণসংখ্যা dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->বাফার, str, len);
    macro_ptr = ফাঁকা;
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
ST_FUNC পূর্ণসংখ্যা find_constraint(ASMOperand *operands, পূর্ণসংখ্যা nb_operands, 
                           ধ্রুবক অক্ষর *name, ধ্রুবক অক্ষর **pp)
{
    পূর্ণসংখ্যা সূচক;
    TokenSym *ts;
    ধ্রুবক অক্ষর *p;

    যদি (isnum(*name)) {
        সূচক = 0;
        যখন (isnum(*name)) {
            সূচক = (সূচক * 10) + (*name) - '0';
            name++;
        }
        যদি ((unsigned)সূচক >= nb_operands)
            সূচক = -1;
    } অন্যথা যদি (*name == '[') {
        name++;
        p = strchr(name, ']');
        যদি (p) {
            ts = tok_alloc(name, p - name);
            জন্য(সূচক = 0; সূচক < nb_operands; সূচক++) {
                যদি (operands[সূচক].id == ts->tok)
                    যাও found;
            }
            সূচক = -1;
        found:
            name = p + 1;
        } অন্যথা {
            সূচক = -1;
        }
    } অন্যথা {
        সূচক = -1;
    }
    যদি (pp)
        *pp = name;
    ফেরত সূচক;
}

স্থির শূন্য subst_asm_operands(ASMOperand *operands, পূর্ণসংখ্যা nb_operands, 
                               CString *out_str, ধ্রুবক অক্ষর *str)
{
    পূর্ণসংখ্যা c, সূচক, modifier;
    ASMOperand *op;
    SValue sv;

    জন্য(;;) {
        c = *str++;
        যদি (c == '%') {
            যদি (*str == '%') {
                str++;
                যাও add_char;
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
            সূচক = find_constraint(operands, nb_operands, str, &str);
            যদি (সূচক < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[সূচক];
            যদি (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, ফাঁকা), -1);
            } অন্যথা {
		যদি (op->vt == ফাঁকা)
		    যাও error;
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
                বিরতি;
        }
    }
}


স্থির শূন্য parse_asm_operands(ASMOperand *operands, পূর্ণসংখ্যা *nb_operands_ptr,
                               পূর্ণসংখ্যা is_output)
{
    ASMOperand *op;
    পূর্ণসংখ্যা nb_operands;
    অক্ষর* astr;

    যদি (tok != ':') {
        nb_operands = *nb_operands_ptr;
        জন্য(;;) {
            যদি (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            যদি (tok == '[') {
                পরবর্তী();
                যদি (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                পরবর্তী();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->তথ্য;
            pstrcpy(op->constraint, আকার op->constraint, astr);
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
                পরবর্তী();
            } অন্যথা {
                বিরতি;
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
    পূর্ণসংখ্যা nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    যখন (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        পরবর্তী();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->তথ্য, astr1->আকার_2);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, আকার(clobber_regs));
    যদি (tok == ':') {
        পরবর্তী();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        যদি (tok == ':') {
            পরবর্তী();
            যদি (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                যদি (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    পরবর্তী();
                    জন্য(;;) {
                        যদি (tok == ':')
                          বিরতি;
                        যদি (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.তথ্য);
                        পরবর্তী();
                        যদি (tok == ',') {
                            পরবর্তী();
                        } অন্যথা {
                            বিরতি;
                        }
                    }
                }
                যদি (tok == ':') {
                    /* goto labels */
                    পরবর্তী();
                    জন্য (;;) {
                        Sym *csym;
                        পূর্ণসংখ্যা asmname;
                        যদি (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        যদি (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       আকার(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        যদি (!csym) {
                            csym = label_ঠেলো(&global_label_স্তূপ, tok,
                                              LABEL_FORWARD);
                        } অন্যথা {
                            যদি (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        পরবর্তী();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        যদি (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        যদি (tok != ',')
                          বিরতি;
                        পরবর্তী();
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
    printf("asm: \"%s\"\n", (অক্ষর *)astr.তথ্য);
#endif
    যদি (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.তথ্য, astr.আকার_2);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->তথ্য);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (অক্ষর *)astr.তথ্য);
#endif

    /* generate loads */
    asm_gen_code(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, out_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_text_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.তথ্য, astr.আকার_2 - 1, 0);
    cstr_free_s(&astr);
    যদি (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    পরবর্তী();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    জন্য(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC শূন্য asm_global_instr(শূন্য)
{
    CString *astr;
    পূর্ণসংখ্যা saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    পরবর্তী();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    যদি (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (অক্ষর *)astr->তথ্য);
#endif
    cur_text_section = text_section;
    ind = cur_text_section->তথ্য_offset;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->তথ্য, astr->আকার_2 - 1, 1);
    
    cur_text_section->তথ্য_offset = ind;

    /* restore the current C token */
    পরবর্তী();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#অন্যথা
ST_FUNC পূর্ণসংখ্যা tcc_assemble(TCCState *s1, পূর্ণসংখ্যা do_preprocess)
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
