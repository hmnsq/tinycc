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
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ifdef CONFIG_TCC_ASM

ಸ್ಥಿರ Section *last_text_section; /* to handle .previous asm directive */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asmgoto_n;

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_assemble_internal(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ do_preprocess, ಪೂರ್ಣಾಙ್ಕ global);
ಸ್ಥಿರ Sym* asm_new_label(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ label, ಪೂರ್ಣಾಙ್ಕ is_local);
ಸ್ಥಿರ Sym* asm_new_label1(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ label, ಪೂರ್ಣಾಙ್ಕ is_local, ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ);

#ಯದಿ PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ಶೂನ್ಯ gen_addr64(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, int64_t c)
{
    ಯದಿ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC ಶೂನ್ಯ gen_expr64(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm_get_prefix_name(TCCState *s1, ಧ್ರುವ ವರ್ಣ *prefix, unsigned ಪೂರ್ಣಾಙ್ಕ n)
{
    ವರ್ಣ buf[64];
    snprintf(buf, ಪರಿಮಾಣ(buf), "%s%u", prefix, n);
    ಪ್ರತ್ಯಾಗಮ tok_alloc_const(buf);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_get_local_label_name(TCCState *s1, unsigned ಪೂರ್ಣಾಙ್ಕ n)
{
    ಪ್ರತ್ಯಾಗಮ asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ asm2cname(ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ *addeddot)
{
    ಧ್ರುವ ವರ್ಣ *name;
    *addeddot = 0;
    ಯದಿ (!tcc_state->leading_underscore)
      ಪ್ರತ್ಯಾಗಮ v;
    name = get_tok_str(v, ರಿಕ್ತ);
    ಯದಿ (!name)
      ಪ್ರತ್ಯಾಗಮ v;
    ಯದಿ (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } ಅನ್ಯಥಾ ಯದಿ (!strchr(name, '.')) {
        ವರ್ಣ newname[256];
        snprintf(newname, ಪರಿಮಾಣ newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ಪ್ರತ್ಯಾಗಮ v;
}

ಸ್ಥಿರ Sym *asm_label_find(ಪೂರ್ಣಾಙ್ಕ v)
{
    Sym *sym;
    ಪೂರ್ಣಾಙ್ಕ addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    ಯಾವತ್ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    ಪ್ರತ್ಯಾಗಮ sym;
}

ಸ್ಥಿರ Sym *asm_label_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v)
{
    ಪೂರ್ಣಾಙ್ಕ addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ತಳ್ಳು(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ಯದಿ (addeddot)
        sym->asm_label = v;
    ಪ್ರತ್ಯಾಗಮ sym;
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
ST_FUNC Sym* get_asm_sym(ಪೂರ್ಣಾಙ್ಕ name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    ಯದಿ (!sym) {
	sym = asm_label_ತಳ್ಳು(name);
	ಯದಿ (csym)
	  sym->c = csym->c;
    }
    ಪ್ರತ್ಯಾಗಮ sym;
}

ಸ್ಥಿರ Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    ವರ್ಣ buf[100]; ಪೂರ್ಣಾಙ್ಕ label; Sym *sym;
    snprintf(buf, ಪರಿಮಾಣ buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    ಪ್ರತ್ಯಾಗಮ sym ? sym : asm_new_label1(s1, label, 1, sec->sh_ಅಂಕೆ, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ಸ್ಥಿರ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_unary(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    Sym *sym;
    ಪೂರ್ಣಾಙ್ಕ op, label;
    uint64_t n;
    ಧ್ರುವ ವರ್ಣ *p;

    ವಿಕಲ್ಪ(tok) {
    ಪಕ್ಷ TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (ವರ್ಣ **)&p, 0);
        ಯದಿ (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            ಯದಿ (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ಯದಿ (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ಯದಿ (!sym)
                    tcc_error("local label '%d' not found backward", (ಪೂರ್ಣಾಙ್ಕ)n);
            } ಅನ್ಯಥಾ {
                /* forward */
                ಯದಿ (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ತಳ್ಳು(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } ಅನ್ಯಥಾ ಯದಿ (*p == '\0') {
            pe->v = n;
            pe->sym = ರಿಕ್ತ;
	    pe->pcrel = 0;
        } ಅನ್ಯಥಾ {
            tcc_error("invalid number syntax");
        }
        next();
        ಭಙ್ಗ;
    ಪಕ್ಷ '+':
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, pe);
        ಭಙ್ಗ;
    ಪಕ್ಷ '-':
    ಪಕ್ಷ '~':
        op = tok;
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, pe);
        ಯದಿ (pe->sym)
            tcc_error("invalid operation with label");
        ಯದಿ (op == '-')
            pe->v = -pe->v;
        ಅನ್ಯಥಾ
            pe->v = ~pe->v;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_CCHAR:
    ಪಕ್ಷ TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ರಿಕ್ತ;
	pe->pcrel = 0;
	next();
	ಭಙ್ಗ;
    ಪಕ್ಷ '(':
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, pe);
        skip(')');
        ಭಙ್ಗ;
    ಪಕ್ಷ '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        ಯದಿ (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ರಿಕ್ತ);
	    esym = elfsym(sym);
            ಯದಿ (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_ಮೌಲ್ಯ;
                pe->sym = ರಿಕ್ತ;
		pe->pcrel = 0;
            } ಅನ್ಯಥಾ {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } ಅನ್ಯಥಾ {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        ಭಙ್ಗ;
    }
}
    
ಸ್ಥಿರ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_prod(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಙ್ಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, pe);
    ಪ್ರತಿ(;;) {
        op = tok;
        ಯದಿ (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            ಭಙ್ಗ;
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, &e2);
        ಯದಿ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ವಿಕಲ್ಪ(op) {
        ಪಕ್ಷ '*':
            pe->v *= e2.v;
            ಭಙ್ಗ;
        ಪಕ್ಷ '/':  
            ಯದಿ (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            ಭಙ್ಗ;
        ಪಕ್ಷ '%':  
            ಯದಿ (e2.v == 0)
                ಗಚ್ಛ div_error;
            pe->v %= e2.v;
            ಭಙ್ಗ;
        ಪಕ್ಷ TOK_SHL:
            pe->v <<= e2.v;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
        ಪಕ್ಷ TOK_SAR:
            pe->v >>= e2.v;
            ಭಙ್ಗ;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_logic(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಙ್ಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_prod(s1, pe);
    ಪ್ರತಿ(;;) {
        op = tok;
        ಯದಿ (op != '&' && op != '|' && op != '^')
            ಭಙ್ಗ;
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ_prod(s1, &e2);
        ಯದಿ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ವಿಕಲ್ಪ(op) {
        ಪಕ್ಷ '&':
            pe->v &= e2.v;
            ಭಙ್ಗ;
        ಪಕ್ಷ '|':  
            pe->v |= e2.v;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
        ಪಕ್ಷ '^':
            pe->v ^= e2.v;
            ಭಙ್ಗ;
        }
    }
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_sum(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಙ್ಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_logic(s1, pe);
    ಪ್ರತಿ(;;) {
        op = tok;
        ಯದಿ (op != '+' && op != '-')
            ಭಙ್ಗ;
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ_logic(s1, &e2);
        ಯದಿ (op == '+') {
            ಯದಿ (pe->sym != ರಿಕ್ತ && e2.sym != ರಿಕ್ತ)
                ಗಚ್ಛ cannot_relocate;
            pe->v += e2.v;
            ಯದಿ (pe->sym == ರಿಕ್ತ && e2.sym != ರಿಕ್ತ)
                pe->sym = e2.sym;
        } ಅನ್ಯಥಾ {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ಯದಿ (!e2.sym) {
		/* OK */
	    } ಅನ್ಯಥಾ ಯದಿ (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ರಿಕ್ತ; /* same symbols can be subtracted to NULL */
	    } ಅನ್ಯಥಾ {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ಯದಿ (!esym2)
		    ಗಚ್ಛ cannot_relocate;
		ಯದಿ (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (ಪೂರ್ಣಾಙ್ಕ)(esym1->st_ಮೌಲ್ಯ - esym2->st_ಮೌಲ್ಯ);
		    pe->sym = ರಿಕ್ತ;
		} ಅನ್ಯಥಾ ಯದಿ (esym2->st_shndx == cur_text_section->sh_ಅಂಕೆ) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (ಪೂರ್ಣಾಙ್ಕ)(0 - esym2->st_ಮೌಲ್ಯ);
		    pe->pcrel = 1;
		    e2.sym = ರಿಕ್ತ;
		} ಅನ್ಯಥಾ {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_cmp(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಙ್ಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_sum(s1, pe);
    ಪ್ರತಿ(;;) {
        op = tok;
	ಯದಿ (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            ಭಙ್ಗ;
        next();
        asm_ಅಭಿವ್ಯಕ್ತಿ_sum(s1, &e2);
        ಯದಿ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ವಿಕಲ್ಪ(op) {
	ಪಕ್ಷ TOK_EQ:
	    pe->v = pe->v == e2.v;
	    ಭಙ್ಗ;
	ಪಕ್ಷ TOK_NE:
	    pe->v = pe->v != e2.v;
	    ಭಙ್ಗ;
	ಪಕ್ಷ TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    ಭಙ್ಗ;
	ಪಕ್ಷ TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    ಭಙ್ಗ;
	ಪಕ್ಷ TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    ಭಙ್ಗ;
	ಪಕ್ಷ TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            ಭಙ್ಗ;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    asm_ಅಭಿವ್ಯಕ್ತಿ_cmp(s1, pe);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_int_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    ಯದಿ (e.sym)
        expect("constant");
    ಯದಿ ((ಪೂರ್ಣಾಙ್ಕ)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    ಪ್ರತ್ಯಾಗಮ e.v;
}

ಸ್ಥಿರ Sym* asm_new_label1(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ label, ಪೂರ್ಣಾಙ್ಕ is_local,
                           ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    ಯದಿ (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ಯದಿ (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ಯದಿ (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                ಗಚ್ಛ new_label;
            ಯದಿ (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ರಿಕ್ತ));
        }
    } ಅನ್ಯಥಾ {
    new_label:
        sym = asm_label_ತಳ್ಳು(label);
    }
    ಯದಿ (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_ಅಂಕೆ;
    esym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    ಯದಿ (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    ಪ್ರತ್ಯಾಗಮ sym;
}

ಸ್ಥಿರ Sym* asm_new_label(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ label, ಪೂರ್ಣಾಙ್ಕ is_local)
{
    ಪ್ರತ್ಯಾಗಮ asm_new_label1(s1, label, is_local, cur_text_section->sh_ಅಂಕೆ, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ಸ್ಥಿರ Sym* set_ಚಿಹ್ನೆ(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ label)
{
    long n;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ಯದಿ (esym)
	n += esym->st_ಮೌಲ್ಯ;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    ಪ್ರತ್ಯಾಗಮ sym;
}

ಸ್ಥಿರ ಶೂನ್ಯ use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

ಸ್ಥಿರ ಶೂನ್ಯ use_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

ಸ್ಥಿರ ಶೂನ್ಯ ತಳ್ಳು_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

ಸ್ಥಿರ ಶೂನ್ಯ ತೆಗೆ_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    ಯದಿ (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = ರಿಕ್ತ;
    use_section1(s1, prev);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_parse_directive(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ global)
{
    ಪೂರ್ಣಾಙ್ಕ n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    ವಿಕಲ್ಪ(tok) {
    ಪಕ್ಷ TOK_ASMDIR_align:
    ಪಕ್ಷ TOK_ASMDIR_balign:
    ಪಕ್ಷ TOK_ASMDIR_p2align:
    ಪಕ್ಷ TOK_ASMDIR_skip:
    ಪಕ್ಷ TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
        ಯದಿ (tok1 == TOK_ASMDIR_p2align)
        {
            ಯದಿ (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ಯದಿ (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ಯದಿ (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            ಯದಿ (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } ಅನ್ಯಥಾ {
	    ಯದಿ (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        ಯದಿ (tok == ',') {
            next();
            v = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1), c = 0;
        }
    zero_pad:
	ಯದಿ ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        ಯದಿ (sec->sh_type != SHT_NOBITS) {
            ಯದಿ (c) {
                gen_fill_nops(size);
                ಭಙ್ಗ;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_quad:
#ಯದಿ PTR_SIZE == 8
	size = 8;
	ಗಚ್ಛ asm_data;
#ಅನ್ಯಥಾ
        next();
        ಪ್ರತಿ(;;) {
            uint64_t vl;
            ಧ್ರುವ ವರ್ಣ *p;

            p = tokc.str.data;
            ಯದಿ (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (ವರ್ಣ **)&p, 0);
            ಯದಿ (*p != '\0')
                ಗಚ್ಛ error_constant;
            next();
            ಯದಿ (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } ಅನ್ಯಥಾ {
                ind += 8;
            }
            ಯದಿ (tok != ',')
                ಭಙ್ಗ;
            next();
        }
        ಭಙ್ಗ;
#endif
    ಪಕ್ಷ TOK_ASMDIR_byte:
        size = 1;
        ಗಚ್ಛ asm_data;
    ಪಕ್ಷ TOK_ASMDIR_word:
    ಪಕ್ಷ TOK_ASMDIR_short:
        size = 2;
        ಗಚ್ಛ asm_data;
    ಪಕ್ಷ TOK_ASMDIR_long:
    ಪಕ್ಷ TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        ಪ್ರತಿ(;;) {
            ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
            asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
            ಯದಿ (sec->sh_type != SHT_NOBITS) {
                ಯದಿ (size == 4) {
                    gen_expr32(&e);
#ಯದಿ PTR_SIZE == 8
		} ಅನ್ಯಥಾ ಯದಿ (size == 8) {
		    gen_expr64(&e);
#endif
                } ಅನ್ಯಥಾ {
                    ಯದಿ (e.sym)
                        expect("constant");
                    ಯದಿ (size == 1)
                        g(e.v);
                    ಅನ್ಯಥಾ
                        gen_le16(e.v);
                }
            } ಅನ್ಯಥಾ {
                ind += size;
            }
            ಯದಿ (tok != ',')
                ಭಙ್ಗ;
            next();
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_fill:
        {
            ಪೂರ್ಣಾಙ್ಕ repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
            ಯದಿ (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                ಭಙ್ಗ;
            }
            size = 1;
            val = 0;
            ಯದಿ (tok == ',') {
                next();
                size = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
                ಯದಿ (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    ಭಙ್ಗ;
                }
                ಯದಿ (size > 8)
                    size = 8;
                ಯದಿ (tok == ',') {
                    next();
                    val = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
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
            ಪ್ರತಿ(i = 0; i < repeat; i++) {
                ಪ್ರತಿ(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_rept:
        {
            ಪೂರ್ಣಾಙ್ಕ repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
            init_str = tok_str_alloc();
            ಯಾವತ್ (next(), tok != TOK_ASMDIR_endr) {
                ಯದಿ (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ಯಾವತ್ (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            ಭಙ್ಗ;
        }
    ಪಕ್ಷ TOK_ASMDIR_org:
        {
	    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
	    ElfSym *esym;
            next();
	    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    ಯದಿ (esym) {
		ಯದಿ (esym->st_shndx != cur_text_section->sh_ಅಂಕೆ)
		  expect("constant or same-section symbol");
		n += esym->st_ಮೌಲ್ಯ;
	    }
            ಯದಿ (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            ಗಚ್ಛ zero_pad;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	ಯದಿ (tok == ',')
	    set_ಚಿಹ್ನೆ(s1, tok1);
	ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_globl:
    ಪಕ್ಷ TOK_ASMDIR_global:
    ಪಕ್ಷ TOK_ASMDIR_weak:
    ಪಕ್ಷ TOK_ASMDIR_hidden:
	tok1 = tok;
	ಕುರು { 
            Sym *sym;
            next();
	    ಯದಿ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ರಿಕ್ತ);
	    ಯದಿ (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ಯದಿ (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    ಅನ್ಯಥಾ ಯದಿ (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} ಯಾವತ್ (tok == ',');
	ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_string:
    ಪಕ್ಷ TOK_ASMDIR_ascii:
    ಪಕ್ಷ TOK_ASMDIR_asciz:
        {
            ಧ್ರುವ ವರ್ಣ *p;
            ಪೂರ್ಣಾಙ್ಕ i, size, t;

            t = tok;
            next();
            ಪ್ರತಿ(;;) {
                ಯದಿ (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                ಯದಿ (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                ಪ್ರತಿ(i = 0; i < size; i++)
                    g(p[i]);
                next();
                ಯದಿ (tok == ',') {
                    next();
                } ಅನ್ಯಥಾ ಯದಿ (tok != TOK_STR) {
                    ಭಙ್ಗ;
                }
            }
	}
	ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_text:
    ಪಕ್ಷ TOK_ASMDIR_data:
    ಪಕ್ಷ TOK_ASMDIR_bss:
	{ 
            ವರ್ಣ sname[64];
            tok1 = tok;
            n = 0;
            next();
            ಯದಿ (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
		next();
            }
            ಯದಿ (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ರಿಕ್ತ), n);
            ಅನ್ಯಥಾ
                sprintf(sname, "%s", get_tok_str(tok1, ರಿಕ್ತ));
            use_section(s1, sname);
	}
	ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_file:
        {
            ಧ್ರುವ ವರ್ಣ *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            ಯದಿ (tok == TOK_PPNUM)
                next();
            ಯದಿ (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } ಅನ್ಯಥಾ {
                skip_to_eol(0);
                ಭಙ್ಗ;
            }
            tccpp_putfile(p);
            next();
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_ident:
        {
            ವರ್ಣ ident[256];

            ident[0] = '\0';
            next();
            ಯದಿ (tok == TOK_STR)
                pstrcat(ident, ಪರಿಮಾಣ(ident), tokc.str.data);
            ಅನ್ಯಥಾ
                pstrcat(ident, ಪರಿಮಾಣ(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    ಯದಿ (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            ಯದಿ (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ರಿಕ್ತ));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ರಿಕ್ತ));
            next();
            skip(',');
            n = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
            esym = elfsym(sym);
            ಯದಿ (esym) {
                esym->st_size = n;
            }
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_type:
        { 
            Sym *sym;
            ಧ್ರುವ ವರ್ಣ *newtype;
            ಪೂರ್ಣಾಙ್ಕ st_type;

            next();
	    ಯದಿ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ರಿಕ್ತ);
            next();
            skip(',');
            ಯದಿ (tok == TOK_STR) {
                newtype = tokc.str.data;
            } ಅನ್ಯಥಾ {
                ಯದಿ (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, ರಿಕ್ತ);
            }

            ಯದಿ (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ಯದಿ (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                ಯದಿ (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } ಅನ್ಯಥಾ ಯದಿ (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                ಗಚ್ಛ set_st_type;
            } ಅನ್ಯಥಾ
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ರಿಕ್ತ), sym->type.t, newtype);

            next();
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_pushsection:
    ಪಕ್ಷ TOK_ASMDIR_section:
        {
            ವರ್ಣ sname[256];
	    ಪೂರ್ಣಾಙ್ಕ old_nb_section = s1->nb_sections;
            ಪೂರ್ಣಾಙ್ಕ flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            ಯಾವತ್ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ಯದಿ (tok == TOK_STR)
                    pstrcat(sname, ಪರಿಮಾಣ(sname), tokc.str.data);
                ಅನ್ಯಥಾ
                    pstrcat(sname, ಪರಿಮಾಣ(sname), get_tok_str(tok, ರಿಕ್ತ));
                next();
            }
            ಯದಿ (tok == ',') {
                ಧ್ರುವ ವರ್ಣ *p;
                /* skip section options */
                next();
                ಯದಿ (tok != TOK_STR)
                    expect("string constant");
                ಪ್ರತಿ (p = tokc.str.data; *p; ++p) {
                    ಯದಿ (*p == 'w')
                        flags |= SHF_WRITE;
                    ಯದಿ (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                ಯದಿ (tok == ',') {
                    next();
                    ಯದಿ (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    ಯದಿ (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    ಅನ್ಯಥಾ
	        ತಳ್ಳು_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ಯದಿ (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ಯದಿ (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            ಯದಿ (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_popsection:
	next();
	ತೆಗೆ_section(s1);
	ಭಙ್ಗ;
#ifdef TCC_TARGET_I386
    ಪಕ್ಷ TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        ಭಙ್ಗ;
#endif
#ಯದಿ PTR_SIZE == 8
    /* added for compatibility with GAS */
    ಪಕ್ಷ TOK_ASMDIR_code64:
        next();
        ಭಙ್ಗ;
#endif
#ifdef TCC_TARGET_RISCV64
    ಪಕ್ಷ TOK_ASMDIR_option:
        next();
        ವಿಕಲ್ಪ(tok){
            ಪಕ್ಷ TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            ಪಕ್ಷ TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            ಪಕ್ಷ TOK_ASM_pic:
            ಪಕ್ಷ TOK_ASM_nopic:
            ಪಕ್ಷ TOK_ASM_relax:
            ಪಕ್ಷ TOK_ASM_norelax:
            ಪಕ್ಷ TOK_ASM_ತಳ್ಳು:
            ಪಕ್ಷ TOK_ASM_ತೆಗೆ:
                /* TODO: unimplemented */
                next();
                ಭಙ್ಗ;
            ಪಕ್ಷ TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ರಿಕ್ತ));
                ಭಙ್ಗ;
            ಸ್ವಭಾವ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ರಿಕ್ತ));
                ಭಙ್ಗ;
        }
        ಭಙ್ಗ;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    ಪಕ್ಷ TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ASMDIR_reloc:
	{
	    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
	    ಧ್ರುವ ವರ್ಣ *reloc_name;
	    ಪೂರ್ಣಾಙ್ಕ reloc_type = -1;

	    next();
	    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ರಿಕ್ತ);
#ಯದಿ defined(TCC_TARGET_ARM64)
	    ಯದಿ (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_RISCV64)
	    ಯದಿ (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    ಅನ್ಯಥಾ ಯದಿ (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    ಯದಿ (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, ರಿಕ್ತ), e.v, reloc_type, 0);
	    next();
	}
	ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ರಿಕ್ತ));
        ಭಙ್ಗ;
    }
}


/* assemble a file */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_assemble_internal(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ do_preprocess, ಪೂರ್ಣಾಙ್ಕ global)
{
    ಪೂರ್ಣಾಙ್ಕ opcode;
    ಪೂರ್ಣಾಙ್ಕ saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ಯದಿ (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    ಪ್ರತಿ(;;) {
        next();
        ಯದಿ (tok == TOK_EOF)
            ಭಙ್ಗ;
        tcc_debug_ಸಾಲು(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ಯದಿ !defined(TCC_TARGET_ARM64)
        ಯದಿ (tok == '#') {
            /* horrible gas comment */
            ಯಾವತ್ (tok != TOK_LINEFEED)
                next();
        } ಅನ್ಯಥಾ
#endif
        ಯದಿ (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_PPNUM) {
            ಧ್ರುವ ವರ್ಣ *p;
            ಪೂರ್ಣಾಙ್ಕ n;
            p = tokc.str.data;
            n = strtoul(p, (ವರ್ಣ **)&p, 10);
            ಯದಿ (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            ಗಚ್ಛ redo;
        } ಅನ್ಯಥಾ ಯದಿ (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            ಯದಿ (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                ಗಚ್ಛ redo;
            } ಅನ್ಯಥಾ ಯದಿ (tok == '=') {
		set_ಚಿಹ್ನೆ(s1, opcode);
                ಗಚ್ಛ redo;
            } ಅನ್ಯಥಾ {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ಯದಿ (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* Assemble the current file */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_assemble(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ do_preprocess)
{
    ಪೂರ್ಣಾಙ್ಕ ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_assemble_inline(TCCState *s1, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ len, ಪೂರ್ಣಾಙ್ಕ global)
{
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *saved_macro_ptr = macro_ptr;
    ಪೂರ್ಣಾಙ್ಕ dotid = set_idnum('.', IS_ID);
#ಯದಿ !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    ಪೂರ್ಣಾಙ್ಕ dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = ರಿಕ್ತ;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#ಯದಿ !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ find_constraint(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, 
                           ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ವರ್ಣ **pp)
{
    ಪೂರ್ಣಾಙ್ಕ index;
    TokenSym *ts;
    ಧ್ರುವ ವರ್ಣ *p;

    ಯದಿ (isnum(*name)) {
        index = 0;
        ಯಾವತ್ (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        ಯದಿ ((unsigned)index >= nb_operands)
            index = -1;
    } ಅನ್ಯಥಾ ಯದಿ (*name == '[') {
        name++;
        p = strchr(name, ']');
        ಯದಿ (p) {
            ts = tok_alloc(name, p - name);
            ಪ್ರತಿ(index = 0; index < nb_operands; index++) {
                ಯದಿ (operands[index].id == ts->tok)
                    ಗಚ್ಛ found;
            }
            index = -1;
        found:
            name = p + 1;
        } ಅನ್ಯಥಾ {
            index = -1;
        }
    } ಅನ್ಯಥಾ {
        index = -1;
    }
    ಯದಿ (pp)
        *pp = name;
    ಪ್ರತ್ಯಾಗಮ index;
}

ಸ್ಥಿರ ಶೂನ್ಯ subst_asm_operands(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, 
                               CString *out_str, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪೂರ್ಣಾಙ್ಕ c, index, modifier;
    ASMOperand *op;
    SValue sv;

    ಪ್ರತಿ(;;) {
        c = *str++;
        ಯದಿ (c == '%') {
            ಯದಿ (*str == '%') {
                str++;
                ಗಚ್ಛ add_char;
            }
            modifier = 0;
            ಯದಿ (*str == 'c' || *str == 'n' ||
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
            ಯದಿ (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            ಯದಿ (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, ರಿಕ್ತ), -1);
            } ಅನ್ಯಥಾ {
		ಯದಿ (op->vt == ರಿಕ್ತ)
		    ಗಚ್ಛ error;
                sv = *op->vt;
                ಯದಿ (op->reg >= 0) {
                    sv.r = op->reg;
                    ಯದಿ (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } ಅನ್ಯಥಾ {
        add_char:
            cstr_ccat(out_str, c);
            ಯದಿ (c == '\0')
                ಭಙ್ಗ;
        }
    }
}


ಸ್ಥಿರ ಶೂನ್ಯ parse_asm_operands(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ *nb_operands_ptr,
                               ಪೂರ್ಣಾಙ್ಕ is_output)
{
    ASMOperand *op;
    ಪೂರ್ಣಾಙ್ಕ nb_operands;
    ವರ್ಣ* astr;

    ಯದಿ (tok != ':') {
        nb_operands = *nb_operands_ptr;
        ಪ್ರತಿ(;;) {
            ಯದಿ (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ಯದಿ (tok == '[') {
                next();
                ಯದಿ (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, ಪರಿಮಾಣ op->constraint, astr);
            skip('(');
            gexpr();
            ಯದಿ (is_output) {
                ಯದಿ (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } ಅನ್ಯಥಾ {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ಯದಿ ((vtop->r & VT_LVAL) &&
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
            ಯದಿ (tok == ',') {
                next();
            } ಅನ್ಯಥಾ {
                ಭಙ್ಗ;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC ಶೂನ್ಯ asm_instr(ಶೂನ್ಯ)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    ಪೂರ್ಣಾಙ್ಕ nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ಯಾವತ್ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, ಪರಿಮಾಣ(clobber_regs));
    ಯದಿ (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ಯದಿ (tok == ':') {
            next();
            ಯದಿ (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ಯದಿ (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    ಪ್ರತಿ(;;) {
                        ಯದಿ (tok == ':')
                          ಭಙ್ಗ;
                        ಯದಿ (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        ಯದಿ (tok == ',') {
                            next();
                        } ಅನ್ಯಥಾ {
                            ಭಙ್ಗ;
                        }
                    }
                }
                ಯದಿ (tok == ':') {
                    /* goto labels */
                    next();
                    ಪ್ರತಿ (;;) {
                        Sym *csym;
                        ಪೂರ್ಣಾಙ್ಕ asmname;
                        ಯದಿ (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ಯದಿ (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       ಪರಿಮಾಣ(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        ಯದಿ (!csym) {
                            csym = label_ತಳ್ಳು(&global_label_ರಾಶಿ, tok,
                                              LABEL_FORWARD);
                        } ಅನ್ಯಥಾ {
                            ಯದಿ (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ಯದಿ (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ಯದಿ (tok != ',')
                          ಭಙ್ಗ;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ಯದಿ (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (ವರ್ಣ *)astr.data);
#endif
    ಯದಿ (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (ವರ್ಣ *)astr.data);
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
    ಯದಿ (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    ಪ್ರತಿ(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC ಶೂನ್ಯ asm_global_instr(ಶೂನ್ಯ)
{
    CString *astr;
    ಪೂರ್ಣಾಙ್ಕ saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ಯದಿ (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (ವರ್ಣ *)astr->data);
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
#ಅನ್ಯಥಾ
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_assemble(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC ಶೂನ್ಯ asm_instr(ಶೂನ್ಯ)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC ಶೂನ್ಯ asm_global_instr(ಶೂನ್ಯ)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
