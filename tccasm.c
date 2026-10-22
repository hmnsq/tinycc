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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_ASM

ਸਥਿਰ Section *ਆਖਰੀ_ਪਾਠ_section; /* to handle .previous asm directive */
ਸਥਿਰ ਪੂਰਨ asmgoto_n;

ਸਥਿਰ ਪੂਰਨ tcc_assemble_ਅੰਦਰੂਨੀ(TCCState *s1, ਪੂਰਨ do_preprocess, ਪੂਰਨ global);
ਸਥਿਰ Sym* asm_new_label(TCCState *s1, ਪੂਰਨ label, ਪੂਰਨ is_local);
ਸਥਿਰ Sym* asm_new_label1(TCCState *s1, ਪੂਰਨ label, ਪੂਰਨ is_local, ਪੂਰਨ sh_ਅੰਕ, ਪੂਰਨ ਮੁੱਲ);

#ਜੇ PTR_ਮਾਪ == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ਖਾਲੀ gen_addr64(ਪੂਰਨ r, Sym *sym, int64_t c)
{
    ਜੇ (r & VT_SYM)
        greloca(cur_ਪਾਠ_section, sym, ind, R_ਅੰਕੜੇ_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC ਖਾਲੀ gen_expr64(ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ asm_get_ਅਗੇਤਰ_name(TCCState *s1, ਅਚਲ ਅੱਖਰ *ਅਗੇਤਰ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ n)
{
    ਅੱਖਰ buf[64];
    snprintf(buf, ਆਕਾਰ(buf), "%s%u", ਅਗੇਤਰ, n);
    ਵਾਪਸ tok_alloc_const(buf);
}

ST_FUNC ਪੂਰਨ asm_get_local_label_name(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ n)
{
    ਵਾਪਸ asm_get_ਅਗੇਤਰ_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ਸਥਿਰ ਪੂਰਨ asm2cname(ਪੂਰਨ v, ਪੂਰਨ *addeddot)
{
    ਅਚਲ ਅੱਖਰ *name;
    *addeddot = 0;
    ਜੇ (!tcc_state->leading_underscore)
      ਵਾਪਸ v;
    name = get_tok_str(v, ਨਿਰਾ);
    ਜੇ (!name)
      ਵਾਪਸ v;
    ਜੇ (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } ਨਹੀਂਤਾਂ ਜੇ (!strchr(name, '.')) {
        ਅੱਖਰ newname[256];
        snprintf(newname, ਆਕਾਰ newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    ਵਾਪਸ v;
}

ਸਥਿਰ Sym *asm_label_ਲੱਭੋ(ਪੂਰਨ v)
{
    Sym *sym;
    ਪੂਰਨ addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_ਲੱਭੋ(v);
    ਜਦੋਂ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    ਵਾਪਸ sym;
}

ਸਥਿਰ Sym *asm_label_ਧੱਕੋ(ਪੂਰਨ v)
{
    ਪੂਰਨ addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ਧੱਕੋ(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ਜੇ (addeddot)
        sym->asm_label = v;
    ਵਾਪਸ sym;
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
ST_FUNC Sym* get_asm_sym(ਪੂਰਨ name, Sym *csym)
{
    Sym *sym = asm_label_ਲੱਭੋ(name);
    ਜੇ (!sym) {
	sym = asm_label_ਧੱਕੋ(name);
	ਜੇ (csym)
	  sym->c = csym->c;
    }
    ਵਾਪਸ sym;
}

ਸਥਿਰ Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    ਅੱਖਰ buf[100]; ਪੂਰਨ label; Sym *sym;
    snprintf(buf, ਆਕਾਰ buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_ਲੱਭੋ(label);
    ਵਾਪਸ sym ? sym : asm_new_label1(s1, label, 1, sec->sh_ਅੰਕ, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ਸਥਿਰ ਖਾਲੀ asm_ਵਿਅੰਜਕ_unary(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    Sym *sym;
    ਪੂਰਨ op, label;
    uint64_t n;
    ਅਚਲ ਅੱਖਰ *p;

    ਚੋਣ(tok) {
    ਹਾਲਤ TOK_PPNUM:
        p = tokc.str.ਅੰਕੜੇ;
        n = strtoull(p, (ਅੱਖਰ **)&p, 0);
        ਜੇ (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_ਲੱਭੋ(label);
            ਜੇ (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ਜੇ (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ਜੇ (!sym)
                    tcc_error("local label '%d' not found backward", (ਪੂਰਨ)n);
            } ਨਹੀਂਤਾਂ {
                /* forward */
                ਜੇ (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ਧੱਕੋ(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } ਨਹੀਂਤਾਂ ਜੇ (*p == '\0') {
            pe->v = n;
            pe->sym = ਨਿਰਾ;
	    pe->pcrel = 0;
        } ਨਹੀਂਤਾਂ {
            tcc_error("invalid number syntax");
        }
        ਅਗਲਾ();
        ਰੋਕੋ;
    ਹਾਲਤ '+':
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ_unary(s1, pe);
        ਰੋਕੋ;
    ਹਾਲਤ '-':
    ਹਾਲਤ '~':
        op = tok;
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ_unary(s1, pe);
        ਜੇ (pe->sym)
            tcc_error("invalid operation with label");
        ਜੇ (op == '-')
            pe->v = -pe->v;
        ਨਹੀਂਤਾਂ
            pe->v = ~pe->v;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_CCHAR:
    ਹਾਲਤ TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ਨਿਰਾ;
	pe->pcrel = 0;
	ਅਗਲਾ();
	ਰੋਕੋ;
    ਹਾਲਤ '(':
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ(s1, pe);
        skip(')');
        ਰੋਕੋ;
    ਹਾਲਤ '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_ਪਾਠ_section);
        pe->pcrel = 0;
        ਅਗਲਾ();
        ਰੋਕੋ;
    ਮੂਲ:
        ਜੇ (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ਨਿਰਾ);
	    esym = elfsym(sym);
            ਜੇ (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_ਮੁੱਲ;
                pe->sym = ਨਿਰਾ;
		pe->pcrel = 0;
            } ਨਹੀਂਤਾਂ {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        ਰੋਕੋ;
    }
}
    
ਸਥਿਰ ਖਾਲੀ asm_ਵਿਅੰਜਕ_prod(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    ਪੂਰਨ op;
    ਵਿਅੰਜਕ_ਮੁੱਲ e2;

    asm_ਵਿਅੰਜਕ_unary(s1, pe);
    ਲਈ(;;) {
        op = tok;
        ਜੇ (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            ਰੋਕੋ;
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ_unary(s1, &e2);
        ਜੇ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ਚੋਣ(op) {
        ਹਾਲਤ '*':
            pe->v *= e2.v;
            ਰੋਕੋ;
        ਹਾਲਤ '/':  
            ਜੇ (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            ਰੋਕੋ;
        ਹਾਲਤ '%':  
            ਜੇ (e2.v == 0)
                ਜਾਓ div_error;
            pe->v %= e2.v;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_SHL:
            pe->v <<= e2.v;
            ਰੋਕੋ;
        ਮੂਲ:
        ਹਾਲਤ TOK_SAR:
            pe->v >>= e2.v;
            ਰੋਕੋ;
        }
    }
}

ਸਥਿਰ ਖਾਲੀ asm_ਵਿਅੰਜਕ_logic(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    ਪੂਰਨ op;
    ਵਿਅੰਜਕ_ਮੁੱਲ e2;

    asm_ਵਿਅੰਜਕ_prod(s1, pe);
    ਲਈ(;;) {
        op = tok;
        ਜੇ (op != '&' && op != '|' && op != '^')
            ਰੋਕੋ;
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ_prod(s1, &e2);
        ਜੇ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ਚੋਣ(op) {
        ਹਾਲਤ '&':
            pe->v &= e2.v;
            ਰੋਕੋ;
        ਹਾਲਤ '|':  
            pe->v |= e2.v;
            ਰੋਕੋ;
        ਮੂਲ:
        ਹਾਲਤ '^':
            pe->v ^= e2.v;
            ਰੋਕੋ;
        }
    }
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ asm_ਵਿਅੰਜਕ_ਜੋੜ(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    ਪੂਰਨ op;
    ਵਿਅੰਜਕ_ਮੁੱਲ e2;

    asm_ਵਿਅੰਜਕ_logic(s1, pe);
    ਲਈ(;;) {
        op = tok;
        ਜੇ (op != '+' && op != '-')
            ਰੋਕੋ;
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ_logic(s1, &e2);
        ਜੇ (op == '+') {
            ਜੇ (pe->sym != ਨਿਰਾ && e2.sym != ਨਿਰਾ)
                ਜਾਓ cannot_relocate;
            pe->v += e2.v;
            ਜੇ (pe->sym == ਨਿਰਾ && e2.sym != ਨਿਰਾ)
                pe->sym = e2.sym;
        } ਨਹੀਂਤਾਂ {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ਜੇ (!e2.sym) {
		/* OK */
	    } ਨਹੀਂਤਾਂ ਜੇ (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ਨਿਰਾ; /* same symbols can be subtracted to NULL */
	    } ਨਹੀਂਤਾਂ {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ਜੇ (!esym2)
		    ਜਾਓ cannot_relocate;
		ਜੇ (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (ਪੂਰਨ)(esym1->st_ਮੁੱਲ - esym2->st_ਮੁੱਲ);
		    pe->sym = ਨਿਰਾ;
		} ਨਹੀਂਤਾਂ ਜੇ (esym2->st_shndx == cur_ਪਾਠ_section->sh_ਅੰਕ) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (ਪੂਰਨ)(0 - esym2->st_ਮੁੱਲ);
		    pe->pcrel = 1;
		    e2.sym = ਨਿਰਾ;
		} ਨਹੀਂਤਾਂ {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ asm_ਵਿਅੰਜਕ_cmp(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    ਪੂਰਨ op;
    ਵਿਅੰਜਕ_ਮੁੱਲ e2;

    asm_ਵਿਅੰਜਕ_ਜੋੜ(s1, pe);
    ਲਈ(;;) {
        op = tok;
	ਜੇ (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            ਰੋਕੋ;
        ਅਗਲਾ();
        asm_ਵਿਅੰਜਕ_ਜੋੜ(s1, &e2);
        ਜੇ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ਚੋਣ(op) {
	ਹਾਲਤ TOK_EQ:
	    pe->v = pe->v == e2.v;
	    ਰੋਕੋ;
	ਹਾਲਤ TOK_NE:
	    pe->v = pe->v != e2.v;
	    ਰੋਕੋ;
	ਹਾਲਤ TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    ਰੋਕੋ;
	ਹਾਲਤ TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    ਰੋਕੋ;
	ਹਾਲਤ TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    ਰੋਕੋ;
	ਹਾਲਤ TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    ਰੋਕੋ;
        ਮੂਲ:
            ਰੋਕੋ;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC ਖਾਲੀ asm_ਵਿਅੰਜਕ(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    asm_ਵਿਅੰਜਕ_cmp(s1, pe);
}

ST_FUNC ਪੂਰਨ asm_int_ਵਿਅੰਜਕ(TCCState *s1)
{
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
    asm_ਵਿਅੰਜਕ(s1, &e);
    ਜੇ (e.sym)
        expect("constant");
    ਜੇ ((ਪੂਰਨ)e.v != e.v)
	tcc_error("integer out of range %lld", (ਲੰਮਾ ਲੰਮਾ)e.v);
    ਵਾਪਸ e.v;
}

ਸਥਿਰ Sym* asm_new_label1(TCCState *s1, ਪੂਰਨ label, ਪੂਰਨ is_local,
                           ਪੂਰਨ sh_ਅੰਕ, ਪੂਰਨ ਮੁੱਲ)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_ਲੱਭੋ(label);
    ਜੇ (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ਜੇ (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ਜੇ (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                ਜਾਓ new_label;
            ਜੇ (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ਨਿਰਾ));
        }
    } ਨਹੀਂਤਾਂ {
    new_label:
        sym = asm_label_ਧੱਕੋ(label);
    }
    ਜੇ (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_ਅੰਕ;
    esym->st_ਮੁੱਲ = ਮੁੱਲ;
    ਜੇ (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    ਵਾਪਸ sym;
}

ਸਥਿਰ Sym* asm_new_label(TCCState *s1, ਪੂਰਨ label, ਪੂਰਨ is_local)
{
    ਵਾਪਸ asm_new_label1(s1, label, is_local, cur_ਪਾਠ_section->sh_ਅੰਕ, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ਸਥਿਰ Sym* ਸੈੱਟ_ਚਿੰਨ੍ਹ(TCCState *s1, ਪੂਰਨ label)
{
    ਲੰਮਾ n;
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
    Sym *sym;
    ElfSym *esym;
    ਅਗਲਾ();
    asm_ਵਿਅੰਜਕ(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ਜੇ (esym)
	n += esym->st_ਮੁੱਲ;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_ਸੈੱਟ;
    ਵਾਪਸ sym;
}

ਸਥਿਰ ਖਾਲੀ use_section1(TCCState *s1, Section *sec)
{
    cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ = ind;
    cur_ਪਾਠ_section = sec;
    ind = cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;
}

ਸਥਿਰ ਖਾਲੀ use_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name)
{
    Section *sec;
    sec = ਲੱਭੋ_section(s1, name);
    use_section1(s1, sec);
}

ਸਥਿਰ ਖਾਲੀ ਧੱਕੋ_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name)
{
    Section *sec = ਲੱਭੋ_section(s1, name);
    sec->prev = cur_ਪਾਠ_section;
    use_section1(s1, sec);
}

ਸਥਿਰ ਖਾਲੀ ਕੱਢੋ_section(TCCState *s1)
{
    Section *prev = cur_ਪਾਠ_section->prev;
    ਜੇ (!prev)
        tcc_error(".popsection without .pushsection");
    cur_ਪਾਠ_section->prev = ਨਿਰਾ;
    use_section1(s1, prev);
}

ਸਥਿਰ ਖਾਲੀ asm_parse_directive(TCCState *s1, ਪੂਰਨ global)
{
    ਪੂਰਨ n, ਵਿੱਥ, v, ਮਾਪ, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_ਪਾਠ_section;
    ਚੋਣ(tok) {
    ਹਾਲਤ TOK_ASMDIR_align:
    ਹਾਲਤ TOK_ASMDIR_balign:
    ਹਾਲਤ TOK_ASMDIR_p2align:
    ਹਾਲਤ TOK_ASMDIR_skip:
    ਹਾਲਤ TOK_ASMDIR_space:
        tok1 = tok;
        ਅਗਲਾ();
        n = asm_int_ਵਿਅੰਜਕ(s1);
        ਜੇ (tok1 == TOK_ASMDIR_p2align)
        {
            ਜੇ (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ਜੇ (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ਜੇ (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            ਵਿੱਥ = (ind + n - 1) & -n;
            ਮਾਪ = ਵਿੱਥ - ind;
            /* the section must have a compatible alignment */
            ਜੇ (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } ਨਹੀਂਤਾਂ {
	    ਜੇ (n < 0)
	        n = 0;
            ਮਾਪ = n, c = 0;
        }
        v = 0;
        ਜੇ (tok == ',') {
            ਅਗਲਾ();
            v = asm_int_ਵਿਅੰਜਕ(s1), c = 0;
        }
    zero_pad:
	ਜੇ ((uint64_t)ind + ਮਾਪ >= 1<<30)
	    tcc_error("too much data");
        ਜੇ (sec->sh_type != SHT_NOBITS) {
            ਜੇ (c) {
                gen_fill_nops(ਮਾਪ);
                ਰੋਕੋ;
            }
            sec->ਅੰਕੜੇ_ਵਿੱਥ = ind;
            ptr = section_ptr_ਜੋੜੋ(sec, ਮਾਪ);
            memset(ptr, v, ਮਾਪ);
        }
        ind += ਮਾਪ;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_quad:
#ਜੇ PTR_ਮਾਪ == 8
	ਮਾਪ = 8;
	ਜਾਓ asm_ਅੰਕੜੇ;
#ਨਹੀਂਤਾਂ
        ਅਗਲਾ();
        ਲਈ(;;) {
            uint64_t vl;
            ਅਚਲ ਅੱਖਰ *p;

            p = tokc.str.ਅੰਕੜੇ;
            ਜੇ (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (ਅੱਖਰ **)&p, 0);
            ਜੇ (*p != '\0')
                ਜਾਓ error_constant;
            ਅਗਲਾ();
            ਜੇ (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } ਨਹੀਂਤਾਂ {
                ind += 8;
            }
            ਜੇ (tok != ',')
                ਰੋਕੋ;
            ਅਗਲਾ();
        }
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
    ਹਾਲਤ TOK_ASMDIR_byte:
        ਮਾਪ = 1;
        ਜਾਓ asm_ਅੰਕੜੇ;
    ਹਾਲਤ TOK_ASMDIR_ਸ਼ਬਦ:
    ਹਾਲਤ TOK_ASMDIR_short:
        ਮਾਪ = 2;
        ਜਾਓ asm_ਅੰਕੜੇ;
    ਹਾਲਤ TOK_ASMDIR_long:
    ਹਾਲਤ TOK_ASMDIR_int:
        ਮਾਪ = 4;
    asm_ਅੰਕੜੇ:
        ਅਗਲਾ();
        ਲਈ(;;) {
            ਵਿਅੰਜਕ_ਮੁੱਲ e;
            asm_ਵਿਅੰਜਕ(s1, &e);
            ਜੇ (sec->sh_type != SHT_NOBITS) {
                ਜੇ (ਮਾਪ == 4) {
                    gen_expr32(&e);
#ਜੇ PTR_ਮਾਪ == 8
		} ਨਹੀਂਤਾਂ ਜੇ (ਮਾਪ == 8) {
		    gen_expr64(&e);
#ਜੇ_ਅੰਤ
                } ਨਹੀਂਤਾਂ {
                    ਜੇ (e.sym)
                        expect("constant");
                    ਜੇ (ਮਾਪ == 1)
                        g(e.v);
                    ਨਹੀਂਤਾਂ
                        gen_le16(e.v);
                }
            } ਨਹੀਂਤਾਂ {
                ind += ਮਾਪ;
            }
            ਜੇ (tok != ',')
                ਰੋਕੋ;
            ਅਗਲਾ();
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_fill:
        {
            ਪੂਰਨ repeat, ਮਾਪ, val, i, j;
            uint8_t repeat_buf[8];
            ਅਗਲਾ();
            repeat = asm_int_ਵਿਅੰਜਕ(s1);
            ਜੇ (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                ਰੋਕੋ;
            }
            ਮਾਪ = 1;
            val = 0;
            ਜੇ (tok == ',') {
                ਅਗਲਾ();
                ਮਾਪ = asm_int_ਵਿਅੰਜਕ(s1);
                ਜੇ (ਮਾਪ < 0) {
                    tcc_error("size < 0; .fill ignored");
                    ਰੋਕੋ;
                }
                ਜੇ (ਮਾਪ > 8)
                    ਮਾਪ = 8;
                ਜੇ (tok == ',') {
                    ਅਗਲਾ();
                    val = asm_int_ਵਿਅੰਜਕ(s1);
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
            ਲਈ(i = 0; i < repeat; i++) {
                ਲਈ(j = 0; j < ਮਾਪ; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_rept:
        {
            ਪੂਰਨ repeat;
            TokenString *init_str;
            ਅਗਲਾ();
            repeat = asm_int_ਵਿਅੰਜਕ(s1);
            init_str = tok_str_alloc();
            ਜਦੋਂ (ਅਗਲਾ(), tok != TOK_ASMDIR_endr) {
                ਜੇ (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_ਜੋੜੋ_tok(init_str);
            }
            tok_str_ਜੋੜੋ(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ਜਦੋਂ (repeat-- > 0) {
                tcc_assemble_ਅੰਦਰੂਨੀ(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            ਸਿਰਾ_macro();
            ਅਗਲਾ();
            ਰੋਕੋ;
        }
    ਹਾਲਤ TOK_ASMDIR_org:
        {
	    ਵਿਅੰਜਕ_ਮੁੱਲ e;
	    ElfSym *esym;
            ਅਗਲਾ();
	    asm_ਵਿਅੰਜਕ(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    ਜੇ (esym) {
		ਜੇ (esym->st_shndx != cur_ਪਾਠ_section->sh_ਅੰਕ)
		  expect("constant or same-section symbol");
		n += esym->st_ਮੁੱਲ;
	    }
            ਜੇ (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            ਮਾਪ = n - ind;
            ਜਾਓ zero_pad;
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_ਸੈੱਟ:
	ਅਗਲਾ();
	tok1 = tok;
	ਅਗਲਾ();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	ਜੇ (tok == ',')
	    ਸੈੱਟ_ਚਿੰਨ੍ਹ(s1, tok1);
	ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_globl:
    ਹਾਲਤ TOK_ASMDIR_global:
    ਹਾਲਤ TOK_ASMDIR_weak:
    ਹਾਲਤ TOK_ASMDIR_hidden:
	tok1 = tok;
	ਕਰੋ { 
            Sym *sym;
            ਅਗਲਾ();
	    ਜੇ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ਨਿਰਾ);
	    ਜੇ (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ਜੇ (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    ਨਹੀਂਤਾਂ ਜੇ (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            ਅਗਲਾ();
	} ਜਦੋਂ (tok == ',');
	ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_string:
    ਹਾਲਤ TOK_ASMDIR_ascii:
    ਹਾਲਤ TOK_ASMDIR_asciz:
        {
            ਅਚਲ ਅੱਖਰ *p;
            ਪੂਰਨ i, ਮਾਪ, t;

            t = tok;
            ਅਗਲਾ();
            ਲਈ(;;) {
                ਜੇ (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.ਅੰਕੜੇ;
                ਮਾਪ = tokc.str.ਮਾਪ;
                ਜੇ (t == TOK_ASMDIR_ascii && ਮਾਪ > 0)
                    ਮਾਪ--;
                ਲਈ(i = 0; i < ਮਾਪ; i++)
                    g(p[i]);
                ਅਗਲਾ();
                ਜੇ (tok == ',') {
                    ਅਗਲਾ();
                } ਨਹੀਂਤਾਂ ਜੇ (tok != TOK_STR) {
                    ਰੋਕੋ;
                }
            }
	}
	ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_ਪਾਠ:
    ਹਾਲਤ TOK_ASMDIR_ਅੰਕੜੇ:
    ਹਾਲਤ TOK_ASMDIR_bss:
	{ 
            ਅੱਖਰ sname[64];
            tok1 = tok;
            n = 0;
            ਅਗਲਾ();
            ਜੇ (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_ਵਿਅੰਜਕ(s1);
		ਅਗਲਾ();
            }
            ਜੇ (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ਨਿਰਾ), n);
            ਨਹੀਂਤਾਂ
                sprintf(sname, "%s", get_tok_str(tok1, ਨਿਰਾ));
            use_section(s1, sname);
	}
	ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_file:
        {
            ਅਚਲ ਅੱਖਰ *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            ਅਗਲਾ();
            ਜੇ (tok == TOK_PPNUM)
                ਅਗਲਾ();
            ਜੇ (tok == TOK_PPSTR && tokc.str.ਅੰਕੜੇ[0] == '"') {
                tokc.str.ਅੰਕੜੇ[tokc.str.ਮਾਪ - 2] = 0;
                p = tokc.str.ਅੰਕੜੇ + 1;
            } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } ਨਹੀਂਤਾਂ {
                skip_ਮੰਜ਼ਿਲ_eol(0);
                ਰੋਕੋ;
            }
            tccpp_putfile(p);
            ਅਗਲਾ();
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_ident:
        {
            ਅੱਖਰ ident[256];

            ident[0] = '\0';
            ਅਗਲਾ();
            ਜੇ (tok == TOK_STR)
                pstrcat(ident, ਆਕਾਰ(ident), tokc.str.ਅੰਕੜੇ);
            ਨਹੀਂਤਾਂ
                pstrcat(ident, ਆਕਾਰ(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            ਅਗਲਾ();
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_ਮਾਪ:
        { 
            Sym *sym;
            ElfSym *esym;

            ਅਗਲਾ();
	    ਜੇ (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_ਲੱਭੋ(tok);
            ਜੇ (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ਨਿਰਾ));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ਨਿਰਾ));
            ਅਗਲਾ();
            skip(',');
            n = asm_int_ਵਿਅੰਜਕ(s1);
            esym = elfsym(sym);
            ਜੇ (esym) {
                esym->st_ਮਾਪ = n;
            }
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_type:
        { 
            Sym *sym;
            ਅਚਲ ਅੱਖਰ *newtype;
            ਪੂਰਨ st_type;

            ਅਗਲਾ();
	    ਜੇ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ਨਿਰਾ);
            ਅਗਲਾ();
            skip(',');
            ਜੇ (tok == TOK_STR) {
                newtype = tokc.str.ਅੰਕੜੇ;
            } ਨਹੀਂਤਾਂ {
                ਜੇ (tok == '@' || tok == '%')
                    ਅਗਲਾ();
                newtype = get_tok_str(tok, ਨਿਰਾ);
            }

            ਜੇ (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ਜੇ (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            ਸੈੱਟ_st_type:
                ਜੇ (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } ਨਹੀਂਤਾਂ ਜੇ (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                ਜਾਓ ਸੈੱਟ_st_type;
            } ਨਹੀਂਤਾਂ
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ਨਿਰਾ), sym->type.t, newtype);

            ਅਗਲਾ();
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_pushsection:
    ਹਾਲਤ TOK_ASMDIR_section:
        {
            ਅੱਖਰ sname[256];
	    ਪੂਰਨ old_nb_section = s1->nb_sections;
            ਪੂਰਨ flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            ਅਗਲਾ();
            sname[0] = '\0';
            ਜਦੋਂ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ਜੇ (tok == TOK_STR)
                    pstrcat(sname, ਆਕਾਰ(sname), tokc.str.ਅੰਕੜੇ);
                ਨਹੀਂਤਾਂ
                    pstrcat(sname, ਆਕਾਰ(sname), get_tok_str(tok, ਨਿਰਾ));
                ਅਗਲਾ();
            }
            ਜੇ (tok == ',') {
                ਅਚਲ ਅੱਖਰ *p;
                /* skip section options */
                ਅਗਲਾ();
                ਜੇ (tok != TOK_STR)
                    expect("string constant");
                ਲਈ (p = tokc.str.ਅੰਕੜੇ; *p; ++p) {
                    ਜੇ (*p == 'w')
                        flags |= SHF_WRITE;
                    ਜੇ (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                ਅਗਲਾ();
                ਜੇ (tok == ',') {
                    ਅਗਲਾ();
                    ਜੇ (tok == '@' || tok == '%')
                        ਅਗਲਾ();
                    ਅਗਲਾ();
                }
            }
            ਆਖਰੀ_ਪਾਠ_section = cur_ਪਾਠ_section;
	    ਜੇ (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    ਨਹੀਂਤਾਂ
	        ਧੱਕੋ_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ਜੇ (old_nb_section != s1->nb_sections) {
	        cur_ਪਾਠ_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ਜੇ (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_ਪਾਠ_section->sh_flags = flags;
            }
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_ਪਿਛਲਾ:
        { 
            Section *sec;
            ਅਗਲਾ();
            ਜੇ (!ਆਖਰੀ_ਪਾਠ_section)
                tcc_error("no previous section referenced");
            sec = cur_ਪਾਠ_section;
            use_section1(s1, ਆਖਰੀ_ਪਾਠ_section);
            ਆਖਰੀ_ਪਾਠ_section = sec;
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_popsection:
	ਅਗਲਾ();
	ਕੱਢੋ_section(s1);
	ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
    ਹਾਲਤ TOK_ASMDIR_code16:
        {
            ਅਗਲਾ();
            s1->seg_ਮਾਪ = 16;
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_code32:
        {
            ਅਗਲਾ();
            s1->seg_ਮਾਪ = 32;
        }
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
#ਜੇ PTR_ਮਾਪ == 8
    /* added for compatibility with GAS */
    ਹਾਲਤ TOK_ASMDIR_code64:
        ਅਗਲਾ();
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਹਾਲਤ TOK_ASMDIR_option:
        ਅਗਲਾ();
        ਚੋਣ(tok){
            ਹਾਲਤ TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            ਹਾਲਤ TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            ਹਾਲਤ TOK_ASM_pic:
            ਹਾਲਤ TOK_ASM_nopic:
            ਹਾਲਤ TOK_ASM_relax:
            ਹਾਲਤ TOK_ASM_norelax:
            ਹਾਲਤ TOK_ASM_ਧੱਕੋ:
            ਹਾਲਤ TOK_ASM_ਕੱਢੋ:
                /* TODO: unimplemented */
                ਅਗਲਾ();
                ਰੋਕੋ;
            ਹਾਲਤ TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ਨਿਰਾ));
                ਰੋਕੋ;
            ਮੂਲ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ਨਿਰਾ));
                ਰੋਕੋ;
        }
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    ਹਾਲਤ TOK_ASMDIR_symver:
	ਅਗਲਾ();
	ਅਗਲਾ();
        skip(',');
	ਅਗਲਾ();
        skip('@');
	ਅਗਲਾ();
	ਰੋਕੋ;
    ਹਾਲਤ TOK_ASMDIR_reloc:
	{
	    ਵਿਅੰਜਕ_ਮੁੱਲ e;
	    ਅਚਲ ਅੱਖਰ *reloc_name;
	    ਪੂਰਨ reloc_type = -1;

	    ਅਗਲਾ();
	    asm_ਵਿਅੰਜਕ(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ਨਿਰਾ);
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
	    ਜੇ (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
	    ਜੇ (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#ਜੇ_ਅੰਤ
	    ਜੇ (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    ਅਗਲਾ();
	    skip(',');
	    greloca(cur_ਪਾਠ_section, get_asm_sym(tok, ਨਿਰਾ), e.v, reloc_type, 0);
	    ਅਗਲਾ();
	}
	ਰੋਕੋ;
    ਮੂਲ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ਨਿਰਾ));
        ਰੋਕੋ;
    }
}


/* assemble a file */
ਸਥਿਰ ਪੂਰਨ tcc_assemble_ਅੰਦਰੂਨੀ(TCCState *s1, ਪੂਰਨ do_preprocess, ਪੂਰਨ global)
{
    ਪੂਰਨ opcode;
    ਪੂਰਨ saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ਜੇ (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    ਲਈ(;;) {
        ਅਗਲਾ();
        ਜੇ (tok == TOK_EOF)
            ਰੋਕੋ;
        tcc_debug_ਸਤਰ(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
        ਜੇ (tok == '#') {
            /* horrible gas comment */
            ਜਦੋਂ (tok != TOK_LINEFEED)
                ਅਗਲਾ();
        } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
        ਜੇ (tok >= TOK_ASMDIR_ਪਹਿਲਾ && tok <= TOK_ASMDIR_ਆਖਰੀ) {
            asm_parse_directive(s1, global);
        } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_PPNUM) {
            ਅਚਲ ਅੱਖਰ *p;
            ਪੂਰਨ n;
            p = tokc.str.ਅੰਕੜੇ;
            n = strtoul(p, (ਅੱਖਰ **)&p, 10);
            ਜੇ (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            ਅਗਲਾ();
            skip(':');
            ਜਾਓ redo;
        } ਨਹੀਂਤਾਂ ਜੇ (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            ਅਗਲਾ();
            ਜੇ (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                ਅਗਲਾ();
                ਜਾਓ redo;
            } ਨਹੀਂਤਾਂ ਜੇ (tok == '=') {
		ਸੈੱਟ_ਚਿੰਨ੍ਹ(s1, opcode);
                ਜਾਓ redo;
            } ਨਹੀਂਤਾਂ {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ਜੇ (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    ਵਾਪਸ 0;
}

/* Assemble the current file */
ST_FUNC ਪੂਰਨ tcc_assemble(TCCState *s1, ਪੂਰਨ do_preprocess)
{
    ਪੂਰਨ ret;
    tcc_debug_ਸ਼ੁਰੂ(s1);
    /* default section is text */
    cur_ਪਾਠ_section = ਪਾਠ_section;
    ind = cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;
    nocode_wanted = 0;
    ret = tcc_assemble_ਅੰਦਰੂਨੀ(s1, do_preprocess, 1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ = ind;
    tcc_debug_ਸਿਰਾ(s1);
    ਵਾਪਸ ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ਸਥਿਰ ਖਾਲੀ tcc_assemble_inline(TCCState *s1, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ len, ਪੂਰਨ global)
{
    ਅਚਲ ਪੂਰਨ *saved_macro_ptr = macro_ptr;
    ਪੂਰਨ dotid = ਸੈੱਟ_idnum('.', IS_ID);
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64) && !defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
    ਪੂਰਨ dolid = ਸੈੱਟ_idnum('$', 0);
#ਜੇ_ਅੰਤ

    tcc_open_bf(s1, ":asm:", len);
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(file->ਬਫਰ, str, len);
    macro_ptr = ਨਿਰਾ;
    tcc_assemble_ਅੰਦਰੂਨੀ(s1, 0, global);
    tcc_close();

#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64) && !defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
    ਸੈੱਟ_idnum('$', dolid);
#ਜੇ_ਅੰਤ
    ਸੈੱਟ_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC ਪੂਰਨ ਲੱਭੋ_constraint(ASMOperand *operands, ਪੂਰਨ nb_operands, 
                           ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਅੱਖਰ **pp)
{
    ਪੂਰਨ ਸੂਚਕਾਂਕ;
    TokenSym *ts;
    ਅਚਲ ਅੱਖਰ *p;

    ਜੇ (isnum(*name)) {
        ਸੂਚਕਾਂਕ = 0;
        ਜਦੋਂ (isnum(*name)) {
            ਸੂਚਕਾਂਕ = (ਸੂਚਕਾਂਕ * 10) + (*name) - '0';
            name++;
        }
        ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)ਸੂਚਕਾਂਕ >= nb_operands)
            ਸੂਚਕਾਂਕ = -1;
    } ਨਹੀਂਤਾਂ ਜੇ (*name == '[') {
        name++;
        p = strchr(name, ']');
        ਜੇ (p) {
            ts = tok_alloc(name, p - name);
            ਲਈ(ਸੂਚਕਾਂਕ = 0; ਸੂਚਕਾਂਕ < nb_operands; ਸੂਚਕਾਂਕ++) {
                ਜੇ (operands[ਸੂਚਕਾਂਕ].id == ts->tok)
                    ਜਾਓ ਮਿਲਿਆ;
            }
            ਸੂਚਕਾਂਕ = -1;
        ਮਿਲਿਆ:
            name = p + 1;
        } ਨਹੀਂਤਾਂ {
            ਸੂਚਕਾਂਕ = -1;
        }
    } ਨਹੀਂਤਾਂ {
        ਸੂਚਕਾਂਕ = -1;
    }
    ਜੇ (pp)
        *pp = name;
    ਵਾਪਸ ਸੂਚਕਾਂਕ;
}

ਸਥਿਰ ਖਾਲੀ subst_asm_operands(ASMOperand *operands, ਪੂਰਨ nb_operands, 
                               CString *ਬਾਹਰਲਾ_str, ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ c, ਸੂਚਕਾਂਕ, modifier;
    ASMOperand *op;
    SValue sv;

    ਲਈ(;;) {
        c = *str++;
        ਜੇ (c == '%') {
            ਜੇ (*str == '%') {
                str++;
                ਜਾਓ ਜੋੜੋ_char;
            }
            modifier = 0;
            ਜੇ (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
		*str == 'z' ||
#ਜੇ_ਅੰਤ
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            ਸੂਚਕਾਂਕ = ਲੱਭੋ_constraint(operands, nb_operands, str, &str);
            ਜੇ (ਸੂਚਕਾਂਕ < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[ਸੂਚਕਾਂਕ];
            ਜੇ (modifier == 'l') {
                cstr_cat(ਬਾਹਰਲਾ_str, get_tok_str(op->is_label, ਨਿਰਾ), -1);
            } ਨਹੀਂਤਾਂ {
		ਜੇ (op->vt == ਨਿਰਾ)
		    ਜਾਓ error;
                sv = *op->vt;
                ਜੇ (op->reg >= 0) {
                    sv.r = op->reg;
                    ਜੇ (op->is_ਸਮ੍ਰਿਤੀ)
                      sv.r |= VT_LVAL;
                }
                subst_asm_ਸੰਕਾਰਜ(ਬਾਹਰਲਾ_str, &sv, modifier);
            }
        } ਨਹੀਂਤਾਂ {
        ਜੋੜੋ_char:
            cstr_ccat(ਬਾਹਰਲਾ_str, c);
            ਜੇ (c == '\0')
                ਰੋਕੋ;
        }
    }
}


ਸਥਿਰ ਖਾਲੀ parse_asm_operands(ASMOperand *operands, ਪੂਰਨ *nb_operands_ptr,
                               ਪੂਰਨ is_output)
{
    ASMOperand *op;
    ਪੂਰਨ nb_operands;
    ਅੱਖਰ* astr;

    ਜੇ (tok != ':') {
        nb_operands = *nb_operands_ptr;
        ਲਈ(;;) {
            ਜੇ (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ਜੇ (tok == '[') {
                ਅਗਲਾ();
                ਜੇ (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                ਅਗਲਾ();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->ਅੰਕੜੇ;
            pstrcpy(op->constraint, ਆਕਾਰ op->constraint, astr);
            skip('(');
            gexpr();
            ਜੇ (is_output) {
                ਜੇ (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } ਨਹੀਂਤਾਂ {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ਜੇ ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !ਲੜੀ_ਖੋਜ(op->constraint, "Ump")
#ਜੇ_ਅੰਤ
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            ਜੇ (tok == ',') {
                ਅਗਲਾ();
            } ਨਹੀਂਤਾਂ {
                ਰੋਕੋ;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC ਖਾਲੀ asm_instr(ਖਾਲੀ)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    ਪੂਰਨ nb_outputs, nb_operands, i, must_subst, ਬਾਹਰਲਾ_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ਜਦੋਂ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        ਅਗਲਾ();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->ਅੰਕੜੇ, astr1->ਮਾਪ);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, ਆਕਾਰ(clobber_regs));
    ਜੇ (tok == ':') {
        ਅਗਲਾ();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ਜੇ (tok == ':') {
            ਅਗਲਾ();
            ਜੇ (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ਜੇ (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    ਅਗਲਾ();
                    ਲਈ(;;) {
                        ਜੇ (tok == ':')
                          ਰੋਕੋ;
                        ਜੇ (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.ਅੰਕੜੇ);
                        ਅਗਲਾ();
                        ਜੇ (tok == ',') {
                            ਅਗਲਾ();
                        } ਨਹੀਂਤਾਂ {
                            ਰੋਕੋ;
                        }
                    }
                }
                ਜੇ (tok == ':') {
                    /* goto labels */
                    ਅਗਲਾ();
                    ਲਈ (;;) {
                        Sym *csym;
                        ਪੂਰਨ asmname;
                        ਜੇ (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ਜੇ (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       ਆਕਾਰ(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_ਲੱਭੋ(tok);
                        ਜੇ (!csym) {
                            csym = label_ਧੱਕੋ(&global_label_ਢੇਰ, tok,
                                              LABEL_FORWARD);
                        } ਨਹੀਂਤਾਂ {
                            ਜੇ (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        ਅਗਲਾ();
                        asmname = asm_get_ਅਗੇਤਰ_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ਜੇ (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ਜੇ (tok != ',')
                          ਰੋਕੋ;
                        ਅਗਲਾ();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ਜੇ (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &ਬਾਹਰਲਾ_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਿਖੋ("asm: \"%s\"\n", (ਅੱਖਰ *)astr.ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ
    ਜੇ (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.ਅੰਕੜੇ, astr.ਮਾਪ);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->ਅੰਕੜੇ);
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਿਖੋ("subst_asm: \"%s\"\n", (ਅੱਖਰ *)astr.ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ

    /* generate loads */
    asm_gen_ਕੋਡ(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, ਬਾਹਰਲਾ_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_ਪਾਠ_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.ਅੰਕੜੇ, astr.ਮਾਪ - 1, 0);
    cstr_free_s(&astr);
    ਜੇ (sec != cur_ਪਾਠ_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    ਅਗਲਾ();

    /* store the output values if needed */
    asm_gen_ਕੋਡ(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, ਬਾਹਰਲਾ_reg);
    
    /* free everything */
    ਲਈ(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC ਖਾਲੀ asm_global_instr(ਖਾਲੀ)
{
    CString *astr;
    ਪੂਰਨ saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    ਅਗਲਾ();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ਜੇ (tok != ';')
        expect("';'");
    
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਿਖੋ("asm_global: \"%s\"\n", (ਅੱਖਰ *)astr->ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ
    cur_ਪਾਠ_section = ਪਾਠ_section;
    ind = cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->ਅੰਕੜੇ, astr->ਮਾਪ - 1, 1);
    
    cur_ਪਾਠ_section->ਅੰਕੜੇ_ਵਿੱਥ = ind;

    /* restore the current C token */
    ਅਗਲਾ();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#ਨਹੀਂਤਾਂ
ST_FUNC ਪੂਰਨ tcc_assemble(TCCState *s1, ਪੂਰਨ do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC ਖਾਲੀ asm_instr(ਖਾਲੀ)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC ਖਾਲੀ asm_global_instr(ਖਾਲੀ)
{
    tcc_error("inline asm() not supported");
}
#ਜੇ_ਅੰਤ /* CONFIG_TCC_ASM */
