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
#ଅନ୍ତର୍ଭାଵ "tcc.h"
#ifdef CONFIG_TCC_ASM

ସ୍ଥିର Section *last_text_section; /* to handle .previous asm directive */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asmgoto_n;

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_assemble_internal(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_preprocess, ପୂର୍ଣ୍ଣସଂଖ୍ୟା global);
ସ୍ଥିର Sym* asm_new_label(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା label, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_local);
ସ୍ଥିର Sym* asm_new_label1(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା label, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_local, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ);

#ଯଦି PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ଶୂନ୍ୟ gen_addr64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, int64_t c)
{
    ଯଦି (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC ଶୂନ୍ୟ gen_expr64(ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_get_prefix_name(TCCState *s1, ଅଚଳ ଅକ୍ଷର *prefix, unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ଅକ୍ଷର buf[64];
    snprintf(buf, ଆକାର(buf), "%s%u", prefix, n);
    ଫେରନ୍ତୁ tok_alloc_const(buf);
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_get_local_label_name(TCCState *s1, unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ଫେରନ୍ତୁ asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm2cname(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *addeddot)
{
    ଅଚଳ ଅକ୍ଷର *name;
    *addeddot = 0;
    ଯଦି (!tcc_state->leading_underscore)
      ଫେରନ୍ତୁ v;
    name = get_tok_str(v, ଖାଲି);
    ଯଦି (!name)
      ଫେରନ୍ତୁ v;
    ଯଦି (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } ଅନ୍ୟଥା ଯଦି (!strchr(name, '.')) {
        ଅକ୍ଷର newname[256];
        snprintf(newname, ଆକାର newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ଫେରନ୍ତୁ v;
}

ସ୍ଥିର Sym *asm_label_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    Sym *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    ଯେତେବେଳେ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    ଫେରନ୍ତୁ sym;
}

ସ୍ଥିର Sym *asm_label_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ଠେଲ(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ଯଦି (addeddot)
        sym->asm_label = v;
    ଫେରନ୍ତୁ sym;
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
ST_FUNC Sym* get_asm_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    ଯଦି (!sym) {
	sym = asm_label_ଠେଲ(name);
	ଯଦି (csym)
	  sym->c = csym->c;
    }
    ଫେରନ୍ତୁ sym;
}

ସ୍ଥିର Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    ଅକ୍ଷର buf[100]; ପୂର୍ଣ୍ଣସଂଖ୍ୟା label; Sym *sym;
    snprintf(buf, ଆକାର buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    ଫେରନ୍ତୁ sym ? sym : asm_new_label1(s1, label, 1, sec->sh_ଅଙ୍କ, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ସ୍ଥିର ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି_unary(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    Sym *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, label;
    uint64_t n;
    ଅଚଳ ଅକ୍ଷର *p;

    ବାଛ(tok) {
    ସ୍ଥିତି TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (ଅକ୍ଷର **)&p, 0);
        ଯଦି (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            ଯଦି (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ଯଦି (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ଯଦି (!sym)
                    tcc_error("local label '%d' not found backward", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)n);
            } ଅନ୍ୟଥା {
                /* forward */
                ଯଦି (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ଠେଲ(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } ଅନ୍ୟଥା ଯଦି (*p == '\0') {
            pe->v = n;
            pe->sym = ଖାଲି;
	    pe->pcrel = 0;
        } ଅନ୍ୟଥା {
            tcc_error("invalid number syntax");
        }
        next();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '+':
        next();
        asm_ପଦସମଷ୍ଟି_unary(s1, pe);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '-':
    ସ୍ଥିତି '~':
        op = tok;
        next();
        asm_ପଦସମଷ୍ଟି_unary(s1, pe);
        ଯଦି (pe->sym)
            tcc_error("invalid operation with label");
        ଯଦି (op == '-')
            pe->v = -pe->v;
        ଅନ୍ୟଥା
            pe->v = ~pe->v;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_CCHAR:
    ସ୍ଥିତି TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ଖାଲି;
	pe->pcrel = 0;
	next();
	ଭାଙ୍ଗ;
    ସ୍ଥିତି '(':
        next();
        asm_ପଦସମଷ୍ଟି(s1, pe);
        skip(')');
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଯଦି (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ଖାଲି);
	    esym = elfsym(sym);
            ଯଦି (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_ମୂଲ୍ୟ;
                pe->sym = ଖାଲି;
		pe->pcrel = 0;
            } ଅନ୍ୟଥା {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } ଅନ୍ୟଥା {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        ଭାଙ୍ଗ;
    }
}
    
ସ୍ଥିର ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି_prod(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op;
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e2;

    asm_ପଦସମଷ୍ଟି_unary(s1, pe);
    ପାଇଁ(;;) {
        op = tok;
        ଯଦି (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            ଭାଙ୍ଗ;
        next();
        asm_ପଦସମଷ୍ଟି_unary(s1, &e2);
        ଯଦି (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ବାଛ(op) {
        ସ୍ଥିତି '*':
            pe->v *= e2.v;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି '/':  
            ଯଦି (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି '%':  
            ଯଦି (e2.v == 0)
                ଯାଅ div_error;
            pe->v %= e2.v;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TOK_SHL:
            pe->v <<= e2.v;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ସ୍ଥିତି TOK_SAR:
            pe->v >>= e2.v;
            ଭାଙ୍ଗ;
        }
    }
}

ସ୍ଥିର ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି_logic(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op;
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e2;

    asm_ପଦସମଷ୍ଟି_prod(s1, pe);
    ପାଇଁ(;;) {
        op = tok;
        ଯଦି (op != '&' && op != '|' && op != '^')
            ଭାଙ୍ଗ;
        next();
        asm_ପଦସମଷ୍ଟି_prod(s1, &e2);
        ଯଦି (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ବାଛ(op) {
        ସ୍ଥିତି '&':
            pe->v &= e2.v;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି '|':  
            pe->v |= e2.v;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ସ୍ଥିତି '^':
            pe->v ^= e2.v;
            ଭାଙ୍ଗ;
        }
    }
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି_sum(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op;
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e2;

    asm_ପଦସମଷ୍ଟି_logic(s1, pe);
    ପାଇଁ(;;) {
        op = tok;
        ଯଦି (op != '+' && op != '-')
            ଭାଙ୍ଗ;
        next();
        asm_ପଦସମଷ୍ଟି_logic(s1, &e2);
        ଯଦି (op == '+') {
            ଯଦି (pe->sym != ଖାଲି && e2.sym != ଖାଲି)
                ଯାଅ cannot_relocate;
            pe->v += e2.v;
            ଯଦି (pe->sym == ଖାଲି && e2.sym != ଖାଲି)
                pe->sym = e2.sym;
        } ଅନ୍ୟଥା {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ଯଦି (!e2.sym) {
		/* OK */
	    } ଅନ୍ୟଥା ଯଦି (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ଖାଲି; /* same symbols can be subtracted to NULL */
	    } ଅନ୍ୟଥା {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ଯଦି (!esym2)
		    ଯାଅ cannot_relocate;
		ଯଦି (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(esym1->st_ମୂଲ୍ୟ - esym2->st_ମୂଲ୍ୟ);
		    pe->sym = ଖାଲି;
		} ଅନ୍ୟଥା ଯଦି (esym2->st_shndx == cur_text_section->sh_ଅଙ୍କ) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(0 - esym2->st_ମୂଲ୍ୟ);
		    pe->pcrel = 1;
		    e2.sym = ଖାଲି;
		} ଅନ୍ୟଥା {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି_cmp(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା op;
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e2;

    asm_ପଦସମଷ୍ଟି_sum(s1, pe);
    ପାଇଁ(;;) {
        op = tok;
	ଯଦି (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            ଭାଙ୍ଗ;
        next();
        asm_ପଦସମଷ୍ଟି_sum(s1, &e2);
        ଯଦି (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ବାଛ(op) {
	ସ୍ଥିତି TOK_EQ:
	    pe->v = pe->v == e2.v;
	    ଭାଙ୍ଗ;
	ସ୍ଥିତି TOK_NE:
	    pe->v = pe->v != e2.v;
	    ଭାଙ୍ଗ;
	ସ୍ଥିତି TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    ଭାଙ୍ଗ;
	ସ୍ଥିତି TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    ଭାଙ୍ଗ;
	ସ୍ଥିତି TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    ଭାଙ୍ଗ;
	ସ୍ଥିତି TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଭାଙ୍ଗ;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe)
{
    asm_ପଦସମଷ୍ଟି_cmp(s1, pe);
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_int_ପଦସମଷ୍ଟି(TCCState *s1)
{
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
    asm_ପଦସମଷ୍ଟି(s1, &e);
    ଯଦି (e.sym)
        expect("constant");
    ଯଦି ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    ଫେରନ୍ତୁ e.v;
}

ସ୍ଥିର Sym* asm_new_label1(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା label, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_local,
                           ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    ଯଦି (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ଯଦି (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ଯଦି (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                ଯାଅ new_label;
            ଯଦି (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ଖାଲି));
        }
    } ଅନ୍ୟଥା {
    new_label:
        sym = asm_label_ଠେଲ(label);
    }
    ଯଦି (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_ଅଙ୍କ;
    esym->st_ମୂଲ୍ୟ = ମୂଲ୍ୟ;
    ଯଦି (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    ଫେରନ୍ତୁ sym;
}

ସ୍ଥିର Sym* asm_new_label(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା label, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_local)
{
    ଫେରନ୍ତୁ asm_new_label1(s1, label, is_local, cur_text_section->sh_ଅଙ୍କ, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ସ୍ଥିର Sym* set_ପ୍ରତୀକ(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା label)
{
    long n;
    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_ପଦସମଷ୍ଟି(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ଯଦି (esym)
	n += esym->st_ମୂଲ୍ୟ;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    ଫେରନ୍ତୁ sym;
}

ସ୍ଥିର ଶୂନ୍ୟ use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

ସ୍ଥିର ଶୂନ୍ୟ use_section(TCCState *s1, ଅଚଳ ଅକ୍ଷର *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

ସ୍ଥିର ଶୂନ୍ୟ ଠେଲ_section(TCCState *s1, ଅଚଳ ଅକ୍ଷର *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

ସ୍ଥିର ଶୂନ୍ୟ କାଢ଼_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    ଯଦି (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = ଖାଲି;
    use_section1(s1, prev);
}

ସ୍ଥିର ଶୂନ୍ୟ asm_parse_directive(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା global)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    ବାଛ(tok) {
    ସ୍ଥିତି TOK_ASMDIR_align:
    ସ୍ଥିତି TOK_ASMDIR_balign:
    ସ୍ଥିତି TOK_ASMDIR_p2align:
    ସ୍ଥିତି TOK_ASMDIR_skip:
    ସ୍ଥିତି TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_ପଦସମଷ୍ଟି(s1);
        ଯଦି (tok1 == TOK_ASMDIR_p2align)
        {
            ଯଦି (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ଯଦି (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ଯଦି (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            ଯଦି (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } ଅନ୍ୟଥା {
	    ଯଦି (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        ଯଦି (tok == ',') {
            next();
            v = asm_int_ପଦସମଷ୍ଟି(s1), c = 0;
        }
    zero_pad:
	ଯଦି ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        ଯଦି (sec->sh_type != SHT_NOBITS) {
            ଯଦି (c) {
                gen_fill_nops(size);
                ଭାଙ୍ଗ;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_quad:
#ଯଦି PTR_SIZE == 8
	size = 8;
	ଯାଅ asm_data;
#ଅନ୍ୟଥା
        next();
        ପାଇଁ(;;) {
            uint64_t vl;
            ଅଚଳ ଅକ୍ଷର *p;

            p = tokc.str.data;
            ଯଦି (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (ଅକ୍ଷର **)&p, 0);
            ଯଦି (*p != '\0')
                ଯାଅ error_constant;
            next();
            ଯଦି (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } ଅନ୍ୟଥା {
                ind += 8;
            }
            ଯଦି (tok != ',')
                ଭାଙ୍ଗ;
            next();
        }
        ଭାଙ୍ଗ;
#endif
    ସ୍ଥିତି TOK_ASMDIR_byte:
        size = 1;
        ଯାଅ asm_data;
    ସ୍ଥିତି TOK_ASMDIR_word:
    ସ୍ଥିତି TOK_ASMDIR_short:
        size = 2;
        ଯାଅ asm_data;
    ସ୍ଥିତି TOK_ASMDIR_long:
    ସ୍ଥିତି TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        ପାଇଁ(;;) {
            ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
            asm_ପଦସମଷ୍ଟି(s1, &e);
            ଯଦି (sec->sh_type != SHT_NOBITS) {
                ଯଦି (size == 4) {
                    gen_expr32(&e);
#ଯଦି PTR_SIZE == 8
		} ଅନ୍ୟଥା ଯଦି (size == 8) {
		    gen_expr64(&e);
#endif
                } ଅନ୍ୟଥା {
                    ଯଦି (e.sym)
                        expect("constant");
                    ଯଦି (size == 1)
                        g(e.v);
                    ଅନ୍ୟଥା
                        gen_le16(e.v);
                }
            } ଅନ୍ୟଥା {
                ind += size;
            }
            ଯଦି (tok != ',')
                ଭାଙ୍ଗ;
            next();
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_fill:
        {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_ପଦସମଷ୍ଟି(s1);
            ଯଦି (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                ଭାଙ୍ଗ;
            }
            size = 1;
            val = 0;
            ଯଦି (tok == ',') {
                next();
                size = asm_int_ପଦସମଷ୍ଟି(s1);
                ଯଦି (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    ଭାଙ୍ଗ;
                }
                ଯଦି (size > 8)
                    size = 8;
                ଯଦି (tok == ',') {
                    next();
                    val = asm_int_ପଦସମଷ୍ଟି(s1);
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
            ପାଇଁ(i = 0; i < repeat; i++) {
                ପାଇଁ(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_rept:
        {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_ପଦସମଷ୍ଟି(s1);
            init_str = tok_str_alloc();
            ଯେତେବେଳେ (next(), tok != TOK_ASMDIR_endr) {
                ଯଦି (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ଯେତେବେଳେ (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            ଭାଙ୍ଗ;
        }
    ସ୍ଥିତି TOK_ASMDIR_org:
        {
	    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
	    ElfSym *esym;
            next();
	    asm_ପଦସମଷ୍ଟି(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    ଯଦି (esym) {
		ଯଦି (esym->st_shndx != cur_text_section->sh_ଅଙ୍କ)
		  expect("constant or same-section symbol");
		n += esym->st_ମୂଲ୍ୟ;
	    }
            ଯଦି (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            ଯାଅ zero_pad;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	ଯଦି (tok == ',')
	    set_ପ୍ରତୀକ(s1, tok1);
	ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_globl:
    ସ୍ଥିତି TOK_ASMDIR_global:
    ସ୍ଥିତି TOK_ASMDIR_weak:
    ସ୍ଥିତି TOK_ASMDIR_hidden:
	tok1 = tok;
	କର { 
            Sym *sym;
            next();
	    ଯଦି (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ଖାଲି);
	    ଯଦି (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ଯଦି (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    ଅନ୍ୟଥା ଯଦି (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} ଯେତେବେଳେ (tok == ',');
	ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_string:
    ସ୍ଥିତି TOK_ASMDIR_ascii:
    ସ୍ଥିତି TOK_ASMDIR_asciz:
        {
            ଅଚଳ ଅକ୍ଷର *p;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, size, t;

            t = tok;
            next();
            ପାଇଁ(;;) {
                ଯଦି (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                ଯଦି (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                ପାଇଁ(i = 0; i < size; i++)
                    g(p[i]);
                next();
                ଯଦି (tok == ',') {
                    next();
                } ଅନ୍ୟଥା ଯଦି (tok != TOK_STR) {
                    ଭାଙ୍ଗ;
                }
            }
	}
	ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_text:
    ସ୍ଥିତି TOK_ASMDIR_data:
    ସ୍ଥିତି TOK_ASMDIR_bss:
	{ 
            ଅକ୍ଷର sname[64];
            tok1 = tok;
            n = 0;
            next();
            ଯଦି (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_ପଦସମଷ୍ଟି(s1);
		next();
            }
            ଯଦି (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ଖାଲି), n);
            ଅନ୍ୟଥା
                sprintf(sname, "%s", get_tok_str(tok1, ଖାଲି));
            use_section(s1, sname);
	}
	ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_file:
        {
            ଅଚଳ ଅକ୍ଷର *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            ଯଦି (tok == TOK_PPNUM)
                next();
            ଯଦି (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } ଅନ୍ୟଥା ଯଦି (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } ଅନ୍ୟଥା {
                skip_to_eol(0);
                ଭାଙ୍ଗ;
            }
            tccpp_putfile(p);
            next();
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_ident:
        {
            ଅକ୍ଷର ident[256];

            ident[0] = '\0';
            next();
            ଯଦି (tok == TOK_STR)
                pstrcat(ident, ଆକାର(ident), tokc.str.data);
            ଅନ୍ୟଥା
                pstrcat(ident, ଆକାର(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    ଯଦି (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            ଯଦି (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ଖାଲି));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ଖାଲି));
            next();
            skip(',');
            n = asm_int_ପଦସମଷ୍ଟି(s1);
            esym = elfsym(sym);
            ଯଦି (esym) {
                esym->st_size = n;
            }
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_type:
        { 
            Sym *sym;
            ଅଚଳ ଅକ୍ଷର *newtype;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_type;

            next();
	    ଯଦି (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ଖାଲି);
            next();
            skip(',');
            ଯଦି (tok == TOK_STR) {
                newtype = tokc.str.data;
            } ଅନ୍ୟଥା {
                ଯଦି (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, ଖାଲି);
            }

            ଯଦି (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ଯଦି (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                ଯଦି (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } ଅନ୍ୟଥା ଯଦି (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                ଯାଅ set_st_type;
            } ଅନ୍ୟଥା
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ଖାଲି), sym->type.t, newtype);

            next();
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_pushsection:
    ସ୍ଥିତି TOK_ASMDIR_section:
        {
            ଅକ୍ଷର sname[256];
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା old_nb_section = s1->nb_sections;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            ଯେତେବେଳେ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ଯଦି (tok == TOK_STR)
                    pstrcat(sname, ଆକାର(sname), tokc.str.data);
                ଅନ୍ୟଥା
                    pstrcat(sname, ଆକାର(sname), get_tok_str(tok, ଖାଲି));
                next();
            }
            ଯଦି (tok == ',') {
                ଅଚଳ ଅକ୍ଷର *p;
                /* skip section options */
                next();
                ଯଦି (tok != TOK_STR)
                    expect("string constant");
                ପାଇଁ (p = tokc.str.data; *p; ++p) {
                    ଯଦି (*p == 'w')
                        flags |= SHF_WRITE;
                    ଯଦି (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                ଯଦି (tok == ',') {
                    next();
                    ଯଦି (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    ଯଦି (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    ଅନ୍ୟଥା
	        ଠେଲ_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ଯଦି (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ଯଦି (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            ଯଦି (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_popsection:
	next();
	କାଢ଼_section(s1);
	ଭାଙ୍ଗ;
#ifdef TCC_TARGET_I386
    ସ୍ଥିତି TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        ଭାଙ୍ଗ;
#endif
#ଯଦି PTR_SIZE == 8
    /* added for compatibility with GAS */
    ସ୍ଥିତି TOK_ASMDIR_code64:
        next();
        ଭାଙ୍ଗ;
#endif
#ifdef TCC_TARGET_RISCV64
    ସ୍ଥିତି TOK_ASMDIR_option:
        next();
        ବାଛ(tok){
            ସ୍ଥିତି TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            ସ୍ଥିତି TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            ସ୍ଥିତି TOK_ASM_pic:
            ସ୍ଥିତି TOK_ASM_nopic:
            ସ୍ଥିତି TOK_ASM_relax:
            ସ୍ଥିତି TOK_ASM_norelax:
            ସ୍ଥିତି TOK_ASM_ଠେଲ:
            ସ୍ଥିତି TOK_ASM_କାଢ଼:
                /* TODO: unimplemented */
                next();
                ଭାଙ୍ଗ;
            ସ୍ଥିତି TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ଖାଲି));
                ଭାଙ୍ଗ;
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ଖାଲି));
                ଭାଙ୍ଗ;
        }
        ଭାଙ୍ଗ;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    ସ୍ଥିତି TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ASMDIR_reloc:
	{
	    ପଦସମଷ୍ଟି_ମୂଲ୍ୟ e;
	    ଅଚଳ ଅକ୍ଷର *reloc_name;
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type = -1;

	    next();
	    asm_ପଦସମଷ୍ଟି(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ଖାଲି);
#ଯଦି defined(TCC_TARGET_ARM64)
	    ଯଦି (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#ନଚେତଯଦି defined(TCC_TARGET_RISCV64)
	    ଯଦି (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    ଅନ୍ୟଥା ଯଦି (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    ଯଦି (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, ଖାଲି), e.v, reloc_type, 0);
	    next();
	}
	ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ଖାଲି));
        ଭାଙ୍ଗ;
    }
}


/* assemble a file */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_assemble_internal(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_preprocess, ପୂର୍ଣ୍ଣସଂଖ୍ୟା global)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା opcode;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ଯଦି (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    ପାଇଁ(;;) {
        next();
        ଯଦି (tok == TOK_EOF)
            ଭାଙ୍ଗ;
        tcc_debug_ଧାଡ଼ି(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ଯଦି !defined(TCC_TARGET_ARM64)
        ଯଦି (tok == '#') {
            /* horrible gas comment */
            ଯେତେବେଳେ (tok != TOK_LINEFEED)
                next();
        } ଅନ୍ୟଥା
#endif
        ଯଦି (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } ଅନ୍ୟଥା ଯଦି (tok == TOK_PPNUM) {
            ଅଚଳ ଅକ୍ଷର *p;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
            p = tokc.str.data;
            n = strtoul(p, (ଅକ୍ଷର **)&p, 10);
            ଯଦି (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            ଯାଅ redo;
        } ଅନ୍ୟଥା ଯଦି (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            ଯଦି (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                ଯାଅ redo;
            } ଅନ୍ୟଥା ଯଦି (tok == '=') {
		set_ପ୍ରତୀକ(s1, opcode);
                ଯାଅ redo;
            } ଅନ୍ୟଥା {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ଯଦି (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    ଫେରନ୍ତୁ 0;
}

/* Assemble the current file */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_assemble(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_preprocess)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    ଫେରନ୍ତୁ ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ସ୍ଥିର ଶୂନ୍ୟ tcc_assemble_inline(TCCState *s1, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, ପୂର୍ଣ୍ଣସଂଖ୍ୟା global)
{
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *saved_macro_ptr = macro_ptr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dotid = set_idnum('.', IS_ID);
#ଯଦି !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = ଖାଲି;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#ଯଦି !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା find_constraint(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, 
                           ଅଚଳ ଅକ୍ଷର *name, ଅଚଳ ଅକ୍ଷର **pp)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index;
    TokenSym *ts;
    ଅଚଳ ଅକ୍ଷର *p;

    ଯଦି (isnum(*name)) {
        index = 0;
        ଯେତେବେଳେ (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        ଯଦି ((unsigned)index >= nb_operands)
            index = -1;
    } ଅନ୍ୟଥା ଯଦି (*name == '[') {
        name++;
        p = strchr(name, ']');
        ଯଦି (p) {
            ts = tok_alloc(name, p - name);
            ପାଇଁ(index = 0; index < nb_operands; index++) {
                ଯଦି (operands[index].id == ts->tok)
                    ଯାଅ found;
            }
            index = -1;
        found:
            name = p + 1;
        } ଅନ୍ୟଥା {
            index = -1;
        }
    } ଅନ୍ୟଥା {
        index = -1;
    }
    ଯଦି (pp)
        *pp = name;
    ଫେରନ୍ତୁ index;
}

ସ୍ଥିର ଶୂନ୍ୟ subst_asm_operands(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, 
                               CString *out_str, ଅଚଳ ଅକ୍ଷର *str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, index, modifier;
    ASMOperand *op;
    SValue sv;

    ପାଇଁ(;;) {
        c = *str++;
        ଯଦି (c == '%') {
            ଯଦି (*str == '%') {
                str++;
                ଯାଅ add_char;
            }
            modifier = 0;
            ଯଦି (*str == 'c' || *str == 'n' ||
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
            ଯଦି (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            ଯଦି (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, ଖାଲି), -1);
            } ଅନ୍ୟଥା {
		ଯଦି (op->vt == ଖାଲି)
		    ଯାଅ error;
                sv = *op->vt;
                ଯଦି (op->reg >= 0) {
                    sv.r = op->reg;
                    ଯଦି (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } ଅନ୍ୟଥା {
        add_char:
            cstr_ccat(out_str, c);
            ଯଦି (c == '\0')
                ଭାଙ୍ଗ;
        }
    }
}


ସ୍ଥିର ଶୂନ୍ୟ parse_asm_operands(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *nb_operands_ptr,
                               ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_output)
{
    ASMOperand *op;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands;
    ଅକ୍ଷର* astr;

    ଯଦି (tok != ':') {
        nb_operands = *nb_operands_ptr;
        ପାଇଁ(;;) {
            ଯଦି (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ଯଦି (tok == '[') {
                next();
                ଯଦି (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, ଆକାର op->constraint, astr);
            skip('(');
            gexpr();
            ଯଦି (is_output) {
                ଯଦି (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } ଅନ୍ୟଥା {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ଯଦି ((vtop->r & VT_LVAL) &&
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
            ଯଦି (tok == ',') {
                next();
            } ଅନ୍ୟଥା {
                ଭାଙ୍ଗ;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC ଶୂନ୍ୟ asm_instr(ଶୂନ୍ୟ)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ଯେତେବେଳେ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, ଆକାର(clobber_regs));
    ଯଦି (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ଯଦି (tok == ':') {
            next();
            ଯଦି (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ଯଦି (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    ପାଇଁ(;;) {
                        ଯଦି (tok == ':')
                          ଭାଙ୍ଗ;
                        ଯଦି (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        ଯଦି (tok == ',') {
                            next();
                        } ଅନ୍ୟଥା {
                            ଭାଙ୍ଗ;
                        }
                    }
                }
                ଯଦି (tok == ':') {
                    /* goto labels */
                    next();
                    ପାଇଁ (;;) {
                        Sym *csym;
                        ପୂର୍ଣ୍ଣସଂଖ୍ୟା asmname;
                        ଯଦି (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ଯଦି (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       ଆକାର(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        ଯଦି (!csym) {
                            csym = label_ଠେଲ(&global_label_ଗଦା, tok,
                                              LABEL_FORWARD);
                        } ଅନ୍ୟଥା {
                            ଯଦି (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ଯଦି (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ଯଦି (tok != ',')
                          ଭାଙ୍ଗ;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ଯଦି (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (ଅକ୍ଷର *)astr.data);
#endif
    ଯଦି (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (ଅକ୍ଷର *)astr.data);
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
    ଯଦି (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    ପାଇଁ(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC ଶୂନ୍ୟ asm_global_instr(ଶୂନ୍ୟ)
{
    CString *astr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ଯଦି (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (ଅକ୍ଷର *)astr->data);
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
#ଅନ୍ୟଥା
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_assemble(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC ଶୂନ୍ୟ asm_instr(ଶୂନ୍ୟ)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC ଶୂନ୍ୟ asm_global_instr(ଶୂନ୍ୟ)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
