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

#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_ASM

ಸ್ಥಿರ Section *ಕೊನೆಯ_ಪಠ್ಯ_section; /* to handle .previous asm directive */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asmgoto_n;

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_assemble_ಆಂತರಿಕ(TCCState *s1, ಪೂರ್ಣಾಂಕ do_preprocess, ಪೂರ್ಣಾಂಕ global);
ಸ್ಥಿರ Sym* asm_new_label(TCCState *s1, ಪೂರ್ಣಾಂಕ label, ಪೂರ್ಣಾಂಕ is_local);
ಸ್ಥಿರ Sym* asm_new_label1(TCCState *s1, ಪೂರ್ಣಾಂಕ label, ಪೂರ್ಣಾಂಕ is_local, ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ);

#ಆದರೆ PTR_ಗಾತ್ರ == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ಶೂನ್ಯ gen_addr64(ಪೂರ್ಣಾಂಕ r, Sym *sym, int64_t c)
{
    ಆದರೆ (r & VT_SYM)
        greloca(cur_ಪಠ್ಯ_section, sym, ind, R_ದತ್ತಾಂಶ_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC ಶೂನ್ಯ gen_expr64(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm_get_ಪೂರ್ವಪ್ರತ್ಯಯ_name(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಪೂರ್ವಪ್ರತ್ಯಯ, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ n)
{
    ಅಕ್ಷರ buf[64];
    snprintf(buf, ಗಾತ್ರ(buf), "%s%u", ಪೂರ್ವಪ್ರತ್ಯಯ, n);
    ಹಿಂತಿರುಗಿ tok_alloc_const(buf);
}

ST_FUNC ಪೂರ್ಣಾಂಕ asm_get_local_label_name(TCCState *s1, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ n)
{
    ಹಿಂತಿರುಗಿ asm_get_ಪೂರ್ವಪ್ರತ್ಯಯ_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ asm2cname(ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ *addeddot)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    *addeddot = 0;
    ಆದರೆ (!tcc_state->leading_underscore)
      ಹಿಂತಿರುಗಿ v;
    name = get_tok_str(v, ಖಾಲಿ);
    ಆದರೆ (!name)
      ಹಿಂತಿರುಗಿ v;
    ಆದರೆ (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strchr(name, '.')) {
        ಅಕ್ಷರ newname[256];
        snprintf(newname, ಗಾತ್ರ newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ಹಿಂತಿರುಗಿ v;
}

ಸ್ಥಿರ Sym *asm_label_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v)
{
    Sym *sym;
    ಪೂರ್ಣಾಂಕ addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_ಕಂಡುಹಿಡಿ(v);
    ಆಗ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    ಹಿಂತಿರುಗಿ sym;
}

ಸ್ಥಿರ Sym *asm_label_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v)
{
    ಪೂರ್ಣಾಂಕ addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ತಳ್ಳು(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ಆದರೆ (addeddot)
        sym->asm_label = v;
    ಹಿಂತಿರುಗಿ sym;
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
ST_FUNC Sym* get_asm_sym(ಪೂರ್ಣಾಂಕ name, Sym *csym)
{
    Sym *sym = asm_label_ಕಂಡುಹಿಡಿ(name);
    ಆದರೆ (!sym) {
	sym = asm_label_ತಳ್ಳು(name);
	ಆದರೆ (csym)
	  sym->c = csym->c;
    }
    ಹಿಂತಿರುಗಿ sym;
}

ಸ್ಥಿರ Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    ಅಕ್ಷರ buf[100]; ಪೂರ್ಣಾಂಕ label; Sym *sym;
    snprintf(buf, ಗಾತ್ರ buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_ಕಂಡುಹಿಡಿ(label);
    ಹಿಂತಿರುಗಿ sym ? sym : asm_new_label1(s1, label, 1, sec->sh_ಅಂಕೆ, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ಸ್ಥಿರ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_unary(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    Sym *sym;
    ಪೂರ್ಣಾಂಕ op, label;
    uint64_t n;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;

    ಆಯ್ಕೆ(tok) {
    ಸ್ಥಿತಿ TOK_PPNUM:
        p = tokc.str.ದತ್ತಾಂಶ;
        n = strtoull(p, (ಅಕ್ಷರ **)&p, 0);
        ಆದರೆ (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_ಕಂಡುಹಿಡಿ(label);
            ಆದರೆ (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ಆದರೆ (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ಆದರೆ (!sym)
                    tcc_error("local label '%d' not found backward", (ಪೂರ್ಣಾಂಕ)n);
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* forward */
                ಆದರೆ (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ತಳ್ಳು(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*p == '\0') {
            pe->v = n;
            pe->sym = ಖಾಲಿ;
	    pe->pcrel = 0;
        } ಇಲ್ಲದಿದ್ದರೆ {
            tcc_error("invalid number syntax");
        }
        ಮುಂದಿನ();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '+':
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, pe);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '-':
    ಸ್ಥಿತಿ '~':
        op = tok;
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, pe);
        ಆದರೆ (pe->sym)
            tcc_error("invalid operation with label");
        ಆದರೆ (op == '-')
            pe->v = -pe->v;
        ಇಲ್ಲದಿದ್ದರೆ
            pe->v = ~pe->v;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_CCHAR:
    ಸ್ಥಿತಿ TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ಖಾಲಿ;
	pe->pcrel = 0;
	ಮುಂದಿನ();
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '(':
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ(s1, pe);
        skip(')');
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_ಪಠ್ಯ_section);
        pe->pcrel = 0;
        ಮುಂದಿನ();
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಆದರೆ (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ಖಾಲಿ);
	    esym = elfsym(sym);
            ಆದರೆ (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_ಮೌಲ್ಯ;
                pe->sym = ಖಾಲಿ;
		pe->pcrel = 0;
            } ಇಲ್ಲದಿದ್ದರೆ {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        ನಿಲ್ಲಿಸು;
    }
}
    
ಸ್ಥಿರ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_prod(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಂಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, pe);
    ಗಾಗಿ(;;) {
        op = tok;
        ಆದರೆ (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ_unary(s1, &e2);
        ಆದರೆ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ಆಯ್ಕೆ(op) {
        ಸ್ಥಿತಿ '*':
            pe->v *= e2.v;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '/':  
            ಆದರೆ (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '%':  
            ಆದರೆ (e2.v == 0)
                ಹೋಗು div_error;
            pe->v %= e2.v;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TOK_SHL:
            pe->v <<= e2.v;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
        ಸ್ಥಿತಿ TOK_SAR:
            pe->v >>= e2.v;
            ನಿಲ್ಲಿಸು;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_logic(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಂಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_prod(s1, pe);
    ಗಾಗಿ(;;) {
        op = tok;
        ಆದರೆ (op != '&' && op != '|' && op != '^')
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ_prod(s1, &e2);
        ಆದರೆ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ಆಯ್ಕೆ(op) {
        ಸ್ಥಿತಿ '&':
            pe->v &= e2.v;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '|':  
            pe->v |= e2.v;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
        ಸ್ಥಿತಿ '^':
            pe->v ^= e2.v;
            ನಿಲ್ಲಿಸು;
        }
    }
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_ಮೊತ್ತ(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಂಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_logic(s1, pe);
    ಗಾಗಿ(;;) {
        op = tok;
        ಆದರೆ (op != '+' && op != '-')
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ_logic(s1, &e2);
        ಆದರೆ (op == '+') {
            ಆದರೆ (pe->sym != ಖಾಲಿ && e2.sym != ಖಾಲಿ)
                ಹೋಗು cannot_relocate;
            pe->v += e2.v;
            ಆದರೆ (pe->sym == ಖಾಲಿ && e2.sym != ಖಾಲಿ)
                pe->sym = e2.sym;
        } ಇಲ್ಲದಿದ್ದರೆ {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ಆದರೆ (!e2.sym) {
		/* OK */
	    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ಖಾಲಿ; /* same symbols can be subtracted to NULL */
	    } ಇಲ್ಲದಿದ್ದರೆ {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ಆದರೆ (!esym2)
		    ಹೋಗು cannot_relocate;
		ಆದರೆ (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (ಪೂರ್ಣಾಂಕ)(esym1->st_ಮೌಲ್ಯ - esym2->st_ಮೌಲ್ಯ);
		    pe->sym = ಖಾಲಿ;
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (esym2->st_shndx == cur_ಪಠ್ಯ_section->sh_ಅಂಕೆ) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (ಪೂರ್ಣಾಂಕ)(0 - esym2->st_ಮೌಲ್ಯ);
		    pe->pcrel = 1;
		    e2.sym = ಖಾಲಿ;
		} ಇಲ್ಲದಿದ್ದರೆ {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ_cmp(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    ಪೂರ್ಣಾಂಕ op;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e2;

    asm_ಅಭಿವ್ಯಕ್ತಿ_ಮೊತ್ತ(s1, pe);
    ಗಾಗಿ(;;) {
        op = tok;
	ಆದರೆ (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            ನಿಲ್ಲಿಸು;
        ಮುಂದಿನ();
        asm_ಅಭಿವ್ಯಕ್ತಿ_ಮೊತ್ತ(s1, &e2);
        ಆದರೆ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ಆಯ್ಕೆ(op) {
	ಸ್ಥಿತಿ TOK_EQ:
	    pe->v = pe->v == e2.v;
	    ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ TOK_NE:
	    pe->v = pe->v != e2.v;
	    ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    ನಿಲ್ಲಿಸು;
	ಸ್ಥಿತಿ TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ನಿಲ್ಲಿಸು;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe)
{
    asm_ಅಭಿವ್ಯಕ್ತಿ_cmp(s1, pe);
}

ST_FUNC ಪೂರ್ಣಾಂಕ asm_int_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1)
{
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    ಆದರೆ (e.sym)
        expect("constant");
    ಆದರೆ ((ಪೂರ್ಣಾಂಕ)e.v != e.v)
	tcc_error("integer out of range %lld", (ದೀರ್ಘ ದೀರ್ಘ)e.v);
    ಹಿಂತಿರುಗಿ e.v;
}

ಸ್ಥಿರ Sym* asm_new_label1(TCCState *s1, ಪೂರ್ಣಾಂಕ label, ಪೂರ್ಣಾಂಕ is_local,
                           ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_ಕಂಡುಹಿಡಿ(label);
    ಆದರೆ (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ಆದರೆ (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ಆದರೆ (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                ಹೋಗು new_label;
            ಆದರೆ (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ಖಾಲಿ));
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
    new_label:
        sym = asm_label_ತಳ್ಳು(label);
    }
    ಆದರೆ (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_ಅಂಕೆ;
    esym->st_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    ಆದರೆ (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    ಹಿಂತಿರುಗಿ sym;
}

ಸ್ಥಿರ Sym* asm_new_label(TCCState *s1, ಪೂರ್ಣಾಂಕ label, ಪೂರ್ಣಾಂಕ is_local)
{
    ಹಿಂತಿರುಗಿ asm_new_label1(s1, label, is_local, cur_ಪಠ್ಯ_section->sh_ಅಂಕೆ, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ಸ್ಥಿರ Sym* ಗಣ_ಚಿಹ್ನೆ(TCCState *s1, ಪೂರ್ಣಾಂಕ label)
{
    ದೀರ್ಘ n;
    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
    Sym *sym;
    ElfSym *esym;
    ಮುಂದಿನ();
    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ಆದರೆ (esym)
	n += esym->st_ಮೌಲ್ಯ;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_ಗಣ;
    ಹಿಂತಿರುಗಿ sym;
}

ಸ್ಥಿರ ಶೂನ್ಯ use_section1(TCCState *s1, Section *sec)
{
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ind;
    cur_ಪಠ್ಯ_section = sec;
    ind = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
}

ಸ್ಥಿರ ಶೂನ್ಯ use_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    Section *sec;
    sec = ಕಂಡುಹಿಡಿ_section(s1, name);
    use_section1(s1, sec);
}

ಸ್ಥಿರ ಶೂನ್ಯ ತಳ್ಳು_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    Section *sec = ಕಂಡುಹಿಡಿ_section(s1, name);
    sec->prev = cur_ಪಠ್ಯ_section;
    use_section1(s1, sec);
}

ಸ್ಥಿರ ಶೂನ್ಯ ತೆಗೆ_section(TCCState *s1)
{
    Section *prev = cur_ಪಠ್ಯ_section->prev;
    ಆದರೆ (!prev)
        tcc_error(".popsection without .pushsection");
    cur_ಪಠ್ಯ_section->prev = ಖಾಲಿ;
    use_section1(s1, prev);
}

ಸ್ಥಿರ ಶೂನ್ಯ asm_parse_directive(TCCState *s1, ಪೂರ್ಣಾಂಕ global)
{
    ಪೂರ್ಣಾಂಕ n, ಸ್ಥಾನಾಂತರ, v, ಗಾತ್ರ_2, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_ಪಠ್ಯ_section;
    ಆಯ್ಕೆ(tok) {
    ಸ್ಥಿತಿ TOK_ASMDIR_align:
    ಸ್ಥಿತಿ TOK_ASMDIR_balign:
    ಸ್ಥಿತಿ TOK_ASMDIR_p2align:
    ಸ್ಥಿತಿ TOK_ASMDIR_skip:
    ಸ್ಥಿತಿ TOK_ASMDIR_space:
        tok1 = tok;
        ಮುಂದಿನ();
        n = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
        ಆದರೆ (tok1 == TOK_ASMDIR_p2align)
        {
            ಆದರೆ (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ಆದರೆ (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ಆದರೆ (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            ಸ್ಥಾನಾಂತರ = (ind + n - 1) & -n;
            ಗಾತ್ರ_2 = ಸ್ಥಾನಾಂತರ - ind;
            /* the section must have a compatible alignment */
            ಆದರೆ (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } ಇಲ್ಲದಿದ್ದರೆ {
	    ಆದರೆ (n < 0)
	        n = 0;
            ಗಾತ್ರ_2 = n, c = 0;
        }
        v = 0;
        ಆದರೆ (tok == ',') {
            ಮುಂದಿನ();
            v = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1), c = 0;
        }
    zero_pad:
	ಆದರೆ ((uint64_t)ind + ಗಾತ್ರ_2 >= 1<<30)
	    tcc_error("too much data");
        ಆದರೆ (sec->sh_type != SHT_NOBITS) {
            ಆದರೆ (c) {
                gen_fill_nops(ಗಾತ್ರ_2);
                ನಿಲ್ಲಿಸು;
            }
            sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ind;
            ptr = section_ptr_ಕೂಡಿಸು(sec, ಗಾತ್ರ_2);
            memset(ptr, v, ಗಾತ್ರ_2);
        }
        ind += ಗಾತ್ರ_2;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_quad:
#ಆದರೆ PTR_ಗಾತ್ರ == 8
	ಗಾತ್ರ_2 = 8;
	ಹೋಗು asm_ದತ್ತಾಂಶ;
#ಇಲ್ಲದಿದ್ದರೆ
        ಮುಂದಿನ();
        ಗಾಗಿ(;;) {
            uint64_t vl;
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;

            p = tokc.str.ದತ್ತಾಂಶ;
            ಆದರೆ (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (ಅಕ್ಷರ **)&p, 0);
            ಆದರೆ (*p != '\0')
                ಹೋಗು error_constant;
            ಮುಂದಿನ();
            ಆದರೆ (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } ಇಲ್ಲದಿದ್ದರೆ {
                ind += 8;
            }
            ಆದರೆ (tok != ',')
                ನಿಲ್ಲಿಸು;
            ಮುಂದಿನ();
        }
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
    ಸ್ಥಿತಿ TOK_ASMDIR_byte:
        ಗಾತ್ರ_2 = 1;
        ಹೋಗು asm_ದತ್ತಾಂಶ;
    ಸ್ಥಿತಿ TOK_ASMDIR_ಶಬ್ದ:
    ಸ್ಥಿತಿ TOK_ASMDIR_short:
        ಗಾತ್ರ_2 = 2;
        ಹೋಗು asm_ದತ್ತಾಂಶ;
    ಸ್ಥಿತಿ TOK_ASMDIR_long:
    ಸ್ಥಿತಿ TOK_ASMDIR_int:
        ಗಾತ್ರ_2 = 4;
    asm_ದತ್ತಾಂಶ:
        ಮುಂದಿನ();
        ಗಾಗಿ(;;) {
            ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
            asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
            ಆದರೆ (sec->sh_type != SHT_NOBITS) {
                ಆದರೆ (ಗಾತ್ರ_2 == 4) {
                    gen_expr32(&e);
#ಆದರೆ PTR_ಗಾತ್ರ == 8
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಗಾತ್ರ_2 == 8) {
		    gen_expr64(&e);
#ಆದರೆ_ಅಂತ್ಯ
                } ಇಲ್ಲದಿದ್ದರೆ {
                    ಆದರೆ (e.sym)
                        expect("constant");
                    ಆದರೆ (ಗಾತ್ರ_2 == 1)
                        g(e.v);
                    ಇಲ್ಲದಿದ್ದರೆ
                        gen_le16(e.v);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                ind += ಗಾತ್ರ_2;
            }
            ಆದರೆ (tok != ',')
                ನಿಲ್ಲಿಸು;
            ಮುಂದಿನ();
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_fill:
        {
            ಪೂರ್ಣಾಂಕ repeat, ಗಾತ್ರ_2, val, i, j;
            uint8_t repeat_buf[8];
            ಮುಂದಿನ();
            repeat = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
            ಆದರೆ (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                ನಿಲ್ಲಿಸು;
            }
            ಗಾತ್ರ_2 = 1;
            val = 0;
            ಆದರೆ (tok == ',') {
                ಮುಂದಿನ();
                ಗಾತ್ರ_2 = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
                ಆದರೆ (ಗಾತ್ರ_2 < 0) {
                    tcc_error("size < 0; .fill ignored");
                    ನಿಲ್ಲಿಸು;
                }
                ಆದರೆ (ಗಾತ್ರ_2 > 8)
                    ಗಾತ್ರ_2 = 8;
                ಆದರೆ (tok == ',') {
                    ಮುಂದಿನ();
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
            ಗಾಗಿ(i = 0; i < repeat; i++) {
                ಗಾಗಿ(j = 0; j < ಗಾತ್ರ_2; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_rept:
        {
            ಪೂರ್ಣಾಂಕ repeat;
            TokenString *init_str;
            ಮುಂದಿನ();
            repeat = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
            init_str = tok_str_alloc();
            ಆಗ (ಮುಂದಿನ(), tok != TOK_ASMDIR_endr) {
                ಆದರೆ (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_ಕೂಡಿಸು_tok(init_str);
            }
            tok_str_ಕೂಡಿಸು(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ಆಗ (repeat-- > 0) {
                tcc_assemble_ಆಂತರಿಕ(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            ಕೊನೆ_macro();
            ಮುಂದಿನ();
            ನಿಲ್ಲಿಸು;
        }
    ಸ್ಥಿತಿ TOK_ASMDIR_org:
        {
	    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
	    ElfSym *esym;
            ಮುಂದಿನ();
	    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    ಆದರೆ (esym) {
		ಆದರೆ (esym->st_shndx != cur_ಪಠ್ಯ_section->sh_ಅಂಕೆ)
		  expect("constant or same-section symbol");
		n += esym->st_ಮೌಲ್ಯ;
	    }
            ಆದರೆ (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            ಗಾತ್ರ_2 = n - ind;
            ಹೋಗು zero_pad;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_ಗಣ:
	ಮುಂದಿನ();
	tok1 = tok;
	ಮುಂದಿನ();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	ಆದರೆ (tok == ',')
	    ಗಣ_ಚಿಹ್ನೆ(s1, tok1);
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_globl:
    ಸ್ಥಿತಿ TOK_ASMDIR_global:
    ಸ್ಥಿತಿ TOK_ASMDIR_weak:
    ಸ್ಥಿತಿ TOK_ASMDIR_hidden:
	tok1 = tok;
	ಮಾಡು { 
            Sym *sym;
            ಮುಂದಿನ();
	    ಆದರೆ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ಖಾಲಿ);
	    ಆದರೆ (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ಆದರೆ (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            ಮುಂದಿನ();
	} ಆಗ (tok == ',');
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_string:
    ಸ್ಥಿತಿ TOK_ASMDIR_ascii:
    ಸ್ಥಿತಿ TOK_ASMDIR_asciz:
        {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
            ಪೂರ್ಣಾಂಕ i, ಗಾತ್ರ_2, t;

            t = tok;
            ಮುಂದಿನ();
            ಗಾಗಿ(;;) {
                ಆದರೆ (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.ದತ್ತಾಂಶ;
                ಗಾತ್ರ_2 = tokc.str.ಗಾತ್ರ_2;
                ಆದರೆ (t == TOK_ASMDIR_ascii && ಗಾತ್ರ_2 > 0)
                    ಗಾತ್ರ_2--;
                ಗಾಗಿ(i = 0; i < ಗಾತ್ರ_2; i++)
                    g(p[i]);
                ಮುಂದಿನ();
                ಆದರೆ (tok == ',') {
                    ಮುಂದಿನ();
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok != TOK_STR) {
                    ನಿಲ್ಲಿಸು;
                }
            }
	}
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_ಪಠ್ಯ:
    ಸ್ಥಿತಿ TOK_ASMDIR_ದತ್ತಾಂಶ:
    ಸ್ಥಿತಿ TOK_ASMDIR_bss:
	{ 
            ಅಕ್ಷರ sname[64];
            tok1 = tok;
            n = 0;
            ಮುಂದಿನ();
            ಆದರೆ (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
		ಮುಂದಿನ();
            }
            ಆದರೆ (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ಖಾಲಿ), n);
            ಇಲ್ಲದಿದ್ದರೆ
                sprintf(sname, "%s", get_tok_str(tok1, ಖಾಲಿ));
            use_section(s1, sname);
	}
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_file:
        {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            ಮುಂದಿನ();
            ಆದರೆ (tok == TOK_PPNUM)
                ಮುಂದಿನ();
            ಆದರೆ (tok == TOK_PPSTR && tokc.str.ದತ್ತಾಂಶ[0] == '"') {
                tokc.str.ದತ್ತಾಂಶ[tokc.str.ಗಾತ್ರ_2 - 2] = 0;
                p = tokc.str.ದತ್ತಾಂಶ + 1;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } ಇಲ್ಲದಿದ್ದರೆ {
                skip_ಗಮ್ಯ_eol(0);
                ನಿಲ್ಲಿಸು;
            }
            tccpp_putfile(p);
            ಮುಂದಿನ();
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_ident:
        {
            ಅಕ್ಷರ ident[256];

            ident[0] = '\0';
            ಮುಂದಿನ();
            ಆದರೆ (tok == TOK_STR)
                pstrcat(ident, ಗಾತ್ರ(ident), tokc.str.ದತ್ತಾಂಶ);
            ಇಲ್ಲದಿದ್ದರೆ
                pstrcat(ident, ಗಾತ್ರ(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            ಮುಂದಿನ();
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_ಗಾತ್ರ:
        { 
            Sym *sym;
            ElfSym *esym;

            ಮುಂದಿನ();
	    ಆದರೆ (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_ಕಂಡುಹಿಡಿ(tok);
            ಆದರೆ (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ಖಾಲಿ));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ಖಾಲಿ));
            ಮುಂದಿನ();
            skip(',');
            n = asm_int_ಅಭಿವ್ಯಕ್ತಿ(s1);
            esym = elfsym(sym);
            ಆದರೆ (esym) {
                esym->st_ಗಾತ್ರ = n;
            }
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_type:
        { 
            Sym *sym;
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *newtype;
            ಪೂರ್ಣಾಂಕ st_type;

            ಮುಂದಿನ();
	    ಆದರೆ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ಖಾಲಿ);
            ಮುಂದಿನ();
            skip(',');
            ಆದರೆ (tok == TOK_STR) {
                newtype = tokc.str.ದತ್ತಾಂಶ;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಆದರೆ (tok == '@' || tok == '%')
                    ಮುಂದಿನ();
                newtype = get_tok_str(tok, ಖಾಲಿ);
            }

            ಆದರೆ (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ಆದರೆ (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            ಗಣ_st_type:
                ಆದರೆ (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                ಹೋಗು ಗಣ_st_type;
            } ಇಲ್ಲದಿದ್ದರೆ
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ಖಾಲಿ), sym->type.t, newtype);

            ಮುಂದಿನ();
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_pushsection:
    ಸ್ಥಿತಿ TOK_ASMDIR_section:
        {
            ಅಕ್ಷರ sname[256];
	    ಪೂರ್ಣಾಂಕ old_nb_section = s1->nb_sections;
            ಪೂರ್ಣಾಂಕ flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            ಮುಂದಿನ();
            sname[0] = '\0';
            ಆಗ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ಆದರೆ (tok == TOK_STR)
                    pstrcat(sname, ಗಾತ್ರ(sname), tokc.str.ದತ್ತಾಂಶ);
                ಇಲ್ಲದಿದ್ದರೆ
                    pstrcat(sname, ಗಾತ್ರ(sname), get_tok_str(tok, ಖಾಲಿ));
                ಮುಂದಿನ();
            }
            ಆದರೆ (tok == ',') {
                ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
                /* skip section options */
                ಮುಂದಿನ();
                ಆದರೆ (tok != TOK_STR)
                    expect("string constant");
                ಗಾಗಿ (p = tokc.str.ದತ್ತಾಂಶ; *p; ++p) {
                    ಆದರೆ (*p == 'w')
                        flags |= SHF_WRITE;
                    ಆದರೆ (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                ಮುಂದಿನ();
                ಆದರೆ (tok == ',') {
                    ಮುಂದಿನ();
                    ಆದರೆ (tok == '@' || tok == '%')
                        ಮುಂದಿನ();
                    ಮುಂದಿನ();
                }
            }
            ಕೊನೆಯ_ಪಠ್ಯ_section = cur_ಪಠ್ಯ_section;
	    ಆದರೆ (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    ಇಲ್ಲದಿದ್ದರೆ
	        ತಳ್ಳು_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ಆದರೆ (old_nb_section != s1->nb_sections) {
	        cur_ಪಠ್ಯ_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ಆದರೆ (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_ಪಠ್ಯ_section->sh_flags = flags;
            }
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_ಹಿಂದಿನ:
        { 
            Section *sec;
            ಮುಂದಿನ();
            ಆದರೆ (!ಕೊನೆಯ_ಪಠ್ಯ_section)
                tcc_error("no previous section referenced");
            sec = cur_ಪಠ್ಯ_section;
            use_section1(s1, ಕೊನೆಯ_ಪಠ್ಯ_section);
            ಕೊನೆಯ_ಪಠ್ಯ_section = sec;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_popsection:
	ಮುಂದಿನ();
	ತೆಗೆ_section(s1);
	ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
    ಸ್ಥಿತಿ TOK_ASMDIR_code16:
        {
            ಮುಂದಿನ();
            s1->seg_ಗಾತ್ರ = 16;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_code32:
        {
            ಮುಂದಿನ();
            s1->seg_ಗಾತ್ರ = 32;
        }
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ PTR_ಗಾತ್ರ == 8
    /* added for compatibility with GAS */
    ಸ್ಥಿತಿ TOK_ASMDIR_code64:
        ಮುಂದಿನ();
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    ಸ್ಥಿತಿ TOK_ASMDIR_option:
        ಮುಂದಿನ();
        ಆಯ್ಕೆ(tok){
            ಸ್ಥಿತಿ TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            ಸ್ಥಿತಿ TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            ಸ್ಥಿತಿ TOK_ASM_pic:
            ಸ್ಥಿತಿ TOK_ASM_nopic:
            ಸ್ಥಿತಿ TOK_ASM_relax:
            ಸ್ಥಿತಿ TOK_ASM_norelax:
            ಸ್ಥಿತಿ TOK_ASM_ತಳ್ಳು:
            ಸ್ಥಿತಿ TOK_ASM_ತೆಗೆ:
                /* TODO: unimplemented */
                ಮುಂದಿನ();
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ಖಾಲಿ));
                ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ಖಾಲಿ));
                ನಿಲ್ಲಿಸು;
        }
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    ಸ್ಥಿತಿ TOK_ASMDIR_symver:
	ಮುಂದಿನ();
	ಮುಂದಿನ();
        skip(',');
	ಮುಂದಿನ();
        skip('@');
	ಮುಂದಿನ();
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ASMDIR_reloc:
	{
	    ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ e;
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *reloc_name;
	    ಪೂರ್ಣಾಂಕ reloc_type = -1;

	    ಮುಂದಿನ();
	    asm_ಅಭಿವ್ಯಕ್ತಿ(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ಖಾಲಿ);
#ಆದರೆ defined(TCC_ಗುರಿ_ARM64)
	    ಆದರೆ (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_RISCV64)
	    ಆದರೆ (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#ಆದರೆ_ಅಂತ್ಯ
	    ಆದರೆ (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    ಮುಂದಿನ();
	    skip(',');
	    greloca(cur_ಪಠ್ಯ_section, get_asm_sym(tok, ಖಾಲಿ), e.v, reloc_type, 0);
	    ಮುಂದಿನ();
	}
	ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ಖಾಲಿ));
        ನಿಲ್ಲಿಸು;
    }
}


/* assemble a file */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_assemble_ಆಂತರಿಕ(TCCState *s1, ಪೂರ್ಣಾಂಕ do_preprocess, ಪೂರ್ಣಾಂಕ global)
{
    ಪೂರ್ಣಾಂಕ opcode;
    ಪೂರ್ಣಾಂಕ saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ಆದರೆ (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    ಗಾಗಿ(;;) {
        ಮುಂದಿನ();
        ಆದರೆ (tok == TOK_EOF)
            ನಿಲ್ಲಿಸು;
        tcc_debug_ಸಾಲು(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ಆದರೆ !defined(TCC_ಗುರಿ_ARM64)
        ಆದರೆ (tok == '#') {
            /* horrible gas comment */
            ಆಗ (tok != TOK_LINEFEED)
                ಮುಂದಿನ();
        } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (tok >= TOK_ASMDIR_ಮೊದಲ && tok <= TOK_ASMDIR_ಕೊನೆಯ) {
            asm_parse_directive(s1, global);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_PPNUM) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
            ಪೂರ್ಣಾಂಕ n;
            p = tokc.str.ದತ್ತಾಂಶ;
            n = strtoul(p, (ಅಕ್ಷರ **)&p, 10);
            ಆದರೆ (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            ಮುಂದಿನ();
            skip(':');
            ಹೋಗು redo;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            ಮುಂದಿನ();
            ಆದರೆ (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                ಮುಂದಿನ();
                ಹೋಗು redo;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == '=') {
		ಗಣ_ಚಿಹ್ನೆ(s1, opcode);
                ಹೋಗು redo;
            } ಇಲ್ಲದಿದ್ದರೆ {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ಆದರೆ (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    ಹಿಂತಿರುಗಿ 0;
}

/* Assemble the current file */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_assemble(TCCState *s1, ಪೂರ್ಣಾಂಕ do_preprocess)
{
    ಪೂರ್ಣಾಂಕ ret;
    tcc_debug_ಆರಂಭ(s1);
    /* default section is text */
    cur_ಪಠ್ಯ_section = ಪಠ್ಯ_section;
    ind = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
    nocode_wanted = 0;
    ret = tcc_assemble_ಆಂತರಿಕ(s1, do_preprocess, 1);
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ind;
    tcc_debug_ಕೊನೆ(s1);
    ಹಿಂತಿರುಗಿ ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_assemble_inline(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ len, ಪೂರ್ಣಾಂಕ global)
{
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *saved_macro_ptr = macro_ptr;
    ಪೂರ್ಣಾಂಕ dotid = ಗಣ_idnum('.', IS_ID);
#ಆದರೆ !defined(TCC_ಗುರಿ_RISCV64) && !defined(TCC_ಗುರಿ_X86_64)
    ಪೂರ್ಣಾಂಕ dolid = ಗಣ_idnum('$', 0);
#ಆದರೆ_ಅಂತ್ಯ

    tcc_open_bf(s1, ":asm:", len);
    ಸ್ಮರಣೆ_ನಕಲು(file->ಬಫರ್, str, len);
    macro_ptr = ಖಾಲಿ;
    tcc_assemble_ಆಂತರಿಕ(s1, 0, global);
    tcc_close();

#ಆದರೆ !defined(TCC_ಗುರಿ_RISCV64) && !defined(TCC_ಗುರಿ_X86_64)
    ಗಣ_idnum('$', dolid);
#ಆದರೆ_ಅಂತ್ಯ
    ಗಣ_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC ಪೂರ್ಣಾಂಕ ಕಂಡುಹಿಡಿ_constraint(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, 
                           ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ **pp)
{
    ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ;
    TokenSym *ts;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;

    ಆದರೆ (isnum(*name)) {
        ಸೂಚ್ಯಂಕ = 0;
        ಆಗ (isnum(*name)) {
            ಸೂಚ್ಯಂಕ = (ಸೂಚ್ಯಂಕ * 10) + (*name) - '0';
            name++;
        }
        ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)ಸೂಚ್ಯಂಕ >= nb_operands)
            ಸೂಚ್ಯಂಕ = -1;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*name == '[') {
        name++;
        p = strchr(name, ']');
        ಆದರೆ (p) {
            ts = tok_alloc(name, p - name);
            ಗಾಗಿ(ಸೂಚ್ಯಂಕ = 0; ಸೂಚ್ಯಂಕ < nb_operands; ಸೂಚ್ಯಂಕ++) {
                ಆದರೆ (operands[ಸೂಚ್ಯಂಕ].id == ts->tok)
                    ಹೋಗು ಸಿಕ್ಕಿತು;
            }
            ಸೂಚ್ಯಂಕ = -1;
        ಸಿಕ್ಕಿತು:
            name = p + 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಸೂಚ್ಯಂಕ = -1;
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಸೂಚ್ಯಂಕ = -1;
    }
    ಆದರೆ (pp)
        *pp = name;
    ಹಿಂತಿರುಗಿ ಸೂಚ್ಯಂಕ;
}

ಸ್ಥಿರ ಶೂನ್ಯ subst_asm_operands(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, 
                               CString *ಹೊರಹೋಗು_str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಪೂರ್ಣಾಂಕ c, ಸೂಚ್ಯಂಕ, modifier;
    ASMOperand *op;
    SValue sv;

    ಗಾಗಿ(;;) {
        c = *str++;
        ಆದರೆ (c == '%') {
            ಆದರೆ (*str == '%') {
                str++;
                ಹೋಗು ಕೂಡಿಸು_char;
            }
            modifier = 0;
            ಆದರೆ (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
		*str == 'z' ||
#ಆದರೆ_ಅಂತ್ಯ
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            ಸೂಚ್ಯಂಕ = ಕಂಡುಹಿಡಿ_constraint(operands, nb_operands, str, &str);
            ಆದರೆ (ಸೂಚ್ಯಂಕ < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[ಸೂಚ್ಯಂಕ];
            ಆದರೆ (modifier == 'l') {
                cstr_cat(ಹೊರಹೋಗು_str, get_tok_str(op->is_label, ಖಾಲಿ), -1);
            } ಇಲ್ಲದಿದ್ದರೆ {
		ಆದರೆ (op->vt == ಖಾಲಿ)
		    ಹೋಗು error;
                sv = *op->vt;
                ಆದರೆ (op->reg >= 0) {
                    sv.r = op->reg;
                    ಆದರೆ (op->is_ಸ್ಮರಣೆ)
                      sv.r |= VT_LVAL;
                }
                subst_asm_ಕಾರ್ಯಾಂಶ(ಹೊರಹೋಗು_str, &sv, modifier);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
        ಕೂಡಿಸು_char:
            cstr_ccat(ಹೊರಹೋಗು_str, c);
            ಆದರೆ (c == '\0')
                ನಿಲ್ಲಿಸು;
        }
    }
}


ಸ್ಥಿರ ಶೂನ್ಯ parse_asm_operands(ASMOperand *operands, ಪೂರ್ಣಾಂಕ *nb_operands_ptr,
                               ಪೂರ್ಣಾಂಕ is_output)
{
    ASMOperand *op;
    ಪೂರ್ಣಾಂಕ nb_operands;
    ಅಕ್ಷರ* astr;

    ಆದರೆ (tok != ':') {
        nb_operands = *nb_operands_ptr;
        ಗಾಗಿ(;;) {
            ಆದರೆ (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ಆದರೆ (tok == '[') {
                ಮುಂದಿನ();
                ಆದರೆ (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                ಮುಂದಿನ();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->ದತ್ತಾಂಶ;
            pstrcpy(op->constraint, ಗಾತ್ರ op->constraint, astr);
            skip('(');
            gexpr();
            ಆದರೆ (is_output) {
                ಆದರೆ (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ಆದರೆ ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು(op->constraint, "Ump")
#ಆದರೆ_ಅಂತ್ಯ
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            ಆದರೆ (tok == ',') {
                ಮುಂದಿನ();
            } ಇಲ್ಲದಿದ್ದರೆ {
                ನಿಲ್ಲಿಸು;
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
    ಪೂರ್ಣಾಂಕ nb_outputs, nb_operands, i, must_subst, ಹೊರಹೋಗು_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ಆಗ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        ಮುಂದಿನ();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->ದತ್ತಾಂಶ, astr1->ಗಾತ್ರ_2);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, ಗಾತ್ರ(clobber_regs));
    ಆದರೆ (tok == ':') {
        ಮುಂದಿನ();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ಆದರೆ (tok == ':') {
            ಮುಂದಿನ();
            ಆದರೆ (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ಆದರೆ (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    ಮುಂದಿನ();
                    ಗಾಗಿ(;;) {
                        ಆದರೆ (tok == ':')
                          ನಿಲ್ಲಿಸು;
                        ಆದರೆ (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.ದತ್ತಾಂಶ);
                        ಮುಂದಿನ();
                        ಆದರೆ (tok == ',') {
                            ಮುಂದಿನ();
                        } ಇಲ್ಲದಿದ್ದರೆ {
                            ನಿಲ್ಲಿಸು;
                        }
                    }
                }
                ಆದರೆ (tok == ':') {
                    /* goto labels */
                    ಮುಂದಿನ();
                    ಗಾಗಿ (;;) {
                        Sym *csym;
                        ಪೂರ್ಣಾಂಕ asmname;
                        ಆದರೆ (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ಆದರೆ (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       ಗಾತ್ರ(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_ಕಂಡುಹಿಡಿ(tok);
                        ಆದರೆ (!csym) {
                            csym = label_ತಳ್ಳು(&global_label_ರಾಶಿ, tok,
                                              LABEL_FORWARD);
                        } ಇಲ್ಲದಿದ್ದರೆ {
                            ಆದರೆ (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        ಮುಂದಿನ();
                        asmname = asm_get_ಪೂರ್ವಪ್ರತ್ಯಯ_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ಆದರೆ (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ಆದರೆ (tok != ',')
                          ನಿಲ್ಲಿಸು;
                        ಮುಂದಿನ();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ಆದರೆ (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &ಹೊರಹೋಗು_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಬರೆ("asm: \"%s\"\n", (ಅಕ್ಷರ *)astr.ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.ದತ್ತಾಂಶ, astr.ಗಾತ್ರ_2);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->ದತ್ತಾಂಶ);
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಬರೆ("subst_asm: \"%s\"\n", (ಅಕ್ಷರ *)astr.ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ

    /* generate loads */
    asm_gen_ಸಂಕೇತ(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, ಹೊರಹೋಗು_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_ಪಠ್ಯ_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.ದತ್ತಾಂಶ, astr.ಗಾತ್ರ_2 - 1, 0);
    cstr_free_s(&astr);
    ಆದರೆ (sec != cur_ಪಠ್ಯ_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    ಮುಂದಿನ();

    /* store the output values if needed */
    asm_gen_ಸಂಕೇತ(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, ಹೊರಹೋಗು_reg);
    
    /* free everything */
    ಗಾಗಿ(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC ಶೂನ್ಯ asm_global_instr(ಶೂನ್ಯ)
{
    CString *astr;
    ಪೂರ್ಣಾಂಕ saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    ಮುಂದಿನ();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ಆದರೆ (tok != ';')
        expect("';'");
    
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ASM_DEBUG
    ಬರೆ("asm_global: \"%s\"\n", (ಅಕ್ಷರ *)astr->ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ
    cur_ಪಠ್ಯ_section = ಪಠ್ಯ_section;
    ind = cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->ದತ್ತಾಂಶ, astr->ಗಾತ್ರ_2 - 1, 1);
    
    cur_ಪಠ್ಯ_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = ind;

    /* restore the current C token */
    ಮುಂದಿನ();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#ಇಲ್ಲದಿದ್ದರೆ
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_assemble(TCCState *s1, ಪೂರ್ಣಾಂಕ do_preprocess)
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
#ಆದರೆ_ಅಂತ್ಯ /* CONFIG_TCC_ASM */
