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
#അന്തര്ഭാവ "tcc.h"
#ifdef CONFIG_TCC_ASM

സ്ഥിതം Section *last_text_section; /* to handle .previous asm directive */
സ്ഥിതം പൂർണ്ണസംഖ്യ asmgoto_n;

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_assemble_internal(TCCState *s1, പൂർണ്ണസംഖ്യ do_preprocess, പൂർണ്ണസംഖ്യ global);
സ്ഥിതം Sym* asm_new_label(TCCState *s1, പൂർണ്ണസംഖ്യ label, പൂർണ്ണസംഖ്യ is_local);
സ്ഥിതം Sym* asm_new_label1(TCCState *s1, പൂർണ്ണസംഖ്യ label, പൂർണ്ണസംഖ്യ is_local, പൂർണ്ണസംഖ്യ sh_അക്കം, പൂർണ്ണസംഖ്യ മൂല്യം);

#എങ്കിൽ PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC ശൂന്യം gen_addr64(പൂർണ്ണസംഖ്യ r, Sym *sym, int64_t c)
{
    എങ്കിൽ (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC ശൂന്യം gen_expr64(വ്യഞ്ജകം_മൂല്യം *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ asm_get_prefix_name(TCCState *s1, സ്ഥിരം അക്ഷരം *prefix, unsigned പൂർണ്ണസംഖ്യ n)
{
    അക്ഷരം buf[64];
    snprintf(buf, വലുപ്പം(buf), "%s%u", prefix, n);
    തിരികെ tok_alloc_const(buf);
}

ST_FUNC പൂർണ്ണസംഖ്യ asm_get_local_label_name(TCCState *s1, unsigned പൂർണ്ണസംഖ്യ n)
{
    തിരികെ asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
സ്ഥിതം പൂർണ്ണസംഖ്യ asm2cname(പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ *addeddot)
{
    സ്ഥിരം അക്ഷരം *name;
    *addeddot = 0;
    എങ്കിൽ (!tcc_state->leading_underscore)
      തിരികെ v;
    name = get_tok_str(v, ശൂന്യ);
    എങ്കിൽ (!name)
      തിരികെ v;
    എങ്കിൽ (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } അല്ലെങ്കിൽ എങ്കിൽ (!strchr(name, '.')) {
        അക്ഷരം newname[256];
        snprintf(newname, വലുപ്പം newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    തിരികെ v;
}

സ്ഥിതം Sym *asm_label_find(പൂർണ്ണസംഖ്യ v)
{
    Sym *sym;
    പൂർണ്ണസംഖ്യ addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    ആകുമ്പോൾ (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    തിരികെ sym;
}

സ്ഥിതം Sym *asm_label_തള്ളുക(പൂർണ്ണസംഖ്യ v)
{
    പൂർണ്ണസംഖ്യ addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_തള്ളുക(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    എങ്കിൽ (addeddot)
        sym->asm_label = v;
    തിരികെ sym;
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
ST_FUNC Sym* get_asm_sym(പൂർണ്ണസംഖ്യ name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    എങ്കിൽ (!sym) {
	sym = asm_label_തള്ളുക(name);
	എങ്കിൽ (csym)
	  sym->c = csym->c;
    }
    തിരികെ sym;
}

സ്ഥിതം Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    അക്ഷരം buf[100]; പൂർണ്ണസംഖ്യ label; Sym *sym;
    snprintf(buf, വലുപ്പം buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    തിരികെ sym ? sym : asm_new_label1(s1, label, 1, sec->sh_അക്കം, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

സ്ഥിതം ശൂന്യം asm_വ്യഞ്ജകം_unary(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe)
{
    Sym *sym;
    പൂർണ്ണസംഖ്യ op, label;
    uint64_t n;
    സ്ഥിരം അക്ഷരം *p;

    തിരഞ്ഞെടുപ്പ്(tok) {
    അവസ്ഥ TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (അക്ഷരം **)&p, 0);
        എങ്കിൽ (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            എങ്കിൽ (*p == 'b') {
                /* backward : find the last corresponding defined label */
                എങ്കിൽ (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                എങ്കിൽ (!sym)
                    tcc_error("local label '%d' not found backward", (പൂർണ്ണസംഖ്യ)n);
            } അല്ലെങ്കിൽ {
                /* forward */
                എങ്കിൽ (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_തള്ളുക(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } അല്ലെങ്കിൽ എങ്കിൽ (*p == '\0') {
            pe->v = n;
            pe->sym = ശൂന്യ;
	    pe->pcrel = 0;
        } അല്ലെങ്കിൽ {
            tcc_error("invalid number syntax");
        }
        next();
        നിർത്തുക;
    അവസ്ഥ '+':
        next();
        asm_വ്യഞ്ജകം_unary(s1, pe);
        നിർത്തുക;
    അവസ്ഥ '-':
    അവസ്ഥ '~':
        op = tok;
        next();
        asm_വ്യഞ്ജകം_unary(s1, pe);
        എങ്കിൽ (pe->sym)
            tcc_error("invalid operation with label");
        എങ്കിൽ (op == '-')
            pe->v = -pe->v;
        അല്ലെങ്കിൽ
            pe->v = ~pe->v;
        നിർത്തുക;
    അവസ്ഥ TOK_CCHAR:
    അവസ്ഥ TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ശൂന്യ;
	pe->pcrel = 0;
	next();
	നിർത്തുക;
    അവസ്ഥ '(':
        next();
        asm_വ്യഞ്ജകം(s1, pe);
        skip(')');
        നിർത്തുക;
    അവസ്ഥ '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        എങ്കിൽ (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ശൂന്യ);
	    esym = elfsym(sym);
            എങ്കിൽ (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_മൂല്യം;
                pe->sym = ശൂന്യ;
		pe->pcrel = 0;
            } അല്ലെങ്കിൽ {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } അല്ലെങ്കിൽ {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        നിർത്തുക;
    }
}
    
സ്ഥിതം ശൂന്യം asm_വ്യഞ്ജകം_prod(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe)
{
    പൂർണ്ണസംഖ്യ op;
    വ്യഞ്ജകം_മൂല്യം e2;

    asm_വ്യഞ്ജകം_unary(s1, pe);
    വേണ്ടി(;;) {
        op = tok;
        എങ്കിൽ (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            നിർത്തുക;
        next();
        asm_വ്യഞ്ജകം_unary(s1, &e2);
        എങ്കിൽ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        തിരഞ്ഞെടുപ്പ്(op) {
        അവസ്ഥ '*':
            pe->v *= e2.v;
            നിർത്തുക;
        അവസ്ഥ '/':  
            എങ്കിൽ (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            നിർത്തുക;
        അവസ്ഥ '%':  
            എങ്കിൽ (e2.v == 0)
                പോകുക div_error;
            pe->v %= e2.v;
            നിർത്തുക;
        അവസ്ഥ TOK_SHL:
            pe->v <<= e2.v;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
        അവസ്ഥ TOK_SAR:
            pe->v >>= e2.v;
            നിർത്തുക;
        }
    }
}

സ്ഥിതം ശൂന്യം asm_വ്യഞ്ജകം_logic(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe)
{
    പൂർണ്ണസംഖ്യ op;
    വ്യഞ്ജകം_മൂല്യം e2;

    asm_വ്യഞ്ജകം_prod(s1, pe);
    വേണ്ടി(;;) {
        op = tok;
        എങ്കിൽ (op != '&' && op != '|' && op != '^')
            നിർത്തുക;
        next();
        asm_വ്യഞ്ജകം_prod(s1, &e2);
        എങ്കിൽ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        തിരഞ്ഞെടുപ്പ്(op) {
        അവസ്ഥ '&':
            pe->v &= e2.v;
            നിർത്തുക;
        അവസ്ഥ '|':  
            pe->v |= e2.v;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
        അവസ്ഥ '^':
            pe->v ^= e2.v;
            നിർത്തുക;
        }
    }
}

സ്ഥിതം വരിയിൽ ശൂന്യം asm_വ്യഞ്ജകം_sum(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe)
{
    പൂർണ്ണസംഖ്യ op;
    വ്യഞ്ജകം_മൂല്യം e2;

    asm_വ്യഞ്ജകം_logic(s1, pe);
    വേണ്ടി(;;) {
        op = tok;
        എങ്കിൽ (op != '+' && op != '-')
            നിർത്തുക;
        next();
        asm_വ്യഞ്ജകം_logic(s1, &e2);
        എങ്കിൽ (op == '+') {
            എങ്കിൽ (pe->sym != ശൂന്യ && e2.sym != ശൂന്യ)
                പോകുക cannot_relocate;
            pe->v += e2.v;
            എങ്കിൽ (pe->sym == ശൂന്യ && e2.sym != ശൂന്യ)
                pe->sym = e2.sym;
        } അല്ലെങ്കിൽ {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    എങ്കിൽ (!e2.sym) {
		/* OK */
	    } അല്ലെങ്കിൽ എങ്കിൽ (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ശൂന്യ; /* same symbols can be subtracted to NULL */
	    } അല്ലെങ്കിൽ {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		എങ്കിൽ (!esym2)
		    പോകുക cannot_relocate;
		എങ്കിൽ (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (പൂർണ്ണസംഖ്യ)(esym1->st_മൂല്യം - esym2->st_മൂല്യം);
		    pe->sym = ശൂന്യ;
		} അല്ലെങ്കിൽ എങ്കിൽ (esym2->st_shndx == cur_text_section->sh_അക്കം) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (പൂർണ്ണസംഖ്യ)(0 - esym2->st_മൂല്യം);
		    pe->pcrel = 1;
		    e2.sym = ശൂന്യ;
		} അല്ലെങ്കിൽ {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

സ്ഥിതം വരിയിൽ ശൂന്യം asm_വ്യഞ്ജകം_cmp(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe)
{
    പൂർണ്ണസംഖ്യ op;
    വ്യഞ്ജകം_മൂല്യം e2;

    asm_വ്യഞ്ജകം_sum(s1, pe);
    വേണ്ടി(;;) {
        op = tok;
	എങ്കിൽ (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            നിർത്തുക;
        next();
        asm_വ്യഞ്ജകം_sum(s1, &e2);
        എങ്കിൽ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        തിരഞ്ഞെടുപ്പ്(op) {
	അവസ്ഥ TOK_EQ:
	    pe->v = pe->v == e2.v;
	    നിർത്തുക;
	അവസ്ഥ TOK_NE:
	    pe->v = pe->v != e2.v;
	    നിർത്തുക;
	അവസ്ഥ TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    നിർത്തുക;
	അവസ്ഥ TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    നിർത്തുക;
	അവസ്ഥ TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    നിർത്തുക;
	അവസ്ഥ TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            നിർത്തുക;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC ശൂന്യം asm_വ്യഞ്ജകം(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe)
{
    asm_വ്യഞ്ജകം_cmp(s1, pe);
}

ST_FUNC പൂർണ്ണസംഖ്യ asm_int_വ്യഞ്ജകം(TCCState *s1)
{
    വ്യഞ്ജകം_മൂല്യം e;
    asm_വ്യഞ്ജകം(s1, &e);
    എങ്കിൽ (e.sym)
        expect("constant");
    എങ്കിൽ ((പൂർണ്ണസംഖ്യ)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    തിരികെ e.v;
}

സ്ഥിതം Sym* asm_new_label1(TCCState *s1, പൂർണ്ണസംഖ്യ label, പൂർണ്ണസംഖ്യ is_local,
                           പൂർണ്ണസംഖ്യ sh_അക്കം, പൂർണ്ണസംഖ്യ മൂല്യം)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    എങ്കിൽ (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        എങ്കിൽ (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            എങ്കിൽ (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                പോകുക new_label;
            എങ്കിൽ (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ശൂന്യ));
        }
    } അല്ലെങ്കിൽ {
    new_label:
        sym = asm_label_തള്ളുക(label);
    }
    എങ്കിൽ (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_അക്കം;
    esym->st_മൂല്യം = മൂല്യം;
    എങ്കിൽ (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    തിരികെ sym;
}

സ്ഥിതം Sym* asm_new_label(TCCState *s1, പൂർണ്ണസംഖ്യ label, പൂർണ്ണസംഖ്യ is_local)
{
    തിരികെ asm_new_label1(s1, label, is_local, cur_text_section->sh_അക്കം, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
സ്ഥിതം Sym* set_ചിഹ്നം(TCCState *s1, പൂർണ്ണസംഖ്യ label)
{
    long n;
    വ്യഞ്ജകം_മൂല്യം e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_വ്യഞ്ജകം(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    എങ്കിൽ (esym)
	n += esym->st_മൂല്യം;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    തിരികെ sym;
}

സ്ഥിതം ശൂന്യം use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

സ്ഥിതം ശൂന്യം use_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

സ്ഥിതം ശൂന്യം തള്ളുക_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

സ്ഥിതം ശൂന്യം എടുക്കുക_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    എങ്കിൽ (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = ശൂന്യ;
    use_section1(s1, prev);
}

സ്ഥിതം ശൂന്യം asm_parse_directive(TCCState *s1, പൂർണ്ണസംഖ്യ global)
{
    പൂർണ്ണസംഖ്യ n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    തിരഞ്ഞെടുപ്പ്(tok) {
    അവസ്ഥ TOK_ASMDIR_align:
    അവസ്ഥ TOK_ASMDIR_balign:
    അവസ്ഥ TOK_ASMDIR_p2align:
    അവസ്ഥ TOK_ASMDIR_skip:
    അവസ്ഥ TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_വ്യഞ്ജകം(s1);
        എങ്കിൽ (tok1 == TOK_ASMDIR_p2align)
        {
            എങ്കിൽ (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        എങ്കിൽ (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            എങ്കിൽ (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            എങ്കിൽ (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } അല്ലെങ്കിൽ {
	    എങ്കിൽ (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        എങ്കിൽ (tok == ',') {
            next();
            v = asm_int_വ്യഞ്ജകം(s1), c = 0;
        }
    zero_pad:
	എങ്കിൽ ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        എങ്കിൽ (sec->sh_type != SHT_NOBITS) {
            എങ്കിൽ (c) {
                gen_fill_nops(size);
                നിർത്തുക;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_quad:
#എങ്കിൽ PTR_SIZE == 8
	size = 8;
	പോകുക asm_data;
#അല്ലെങ്കിൽ
        next();
        വേണ്ടി(;;) {
            uint64_t vl;
            സ്ഥിരം അക്ഷരം *p;

            p = tokc.str.data;
            എങ്കിൽ (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (അക്ഷരം **)&p, 0);
            എങ്കിൽ (*p != '\0')
                പോകുക error_constant;
            next();
            എങ്കിൽ (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } അല്ലെങ്കിൽ {
                ind += 8;
            }
            എങ്കിൽ (tok != ',')
                നിർത്തുക;
            next();
        }
        നിർത്തുക;
#endif
    അവസ്ഥ TOK_ASMDIR_byte:
        size = 1;
        പോകുക asm_data;
    അവസ്ഥ TOK_ASMDIR_word:
    അവസ്ഥ TOK_ASMDIR_short:
        size = 2;
        പോകുക asm_data;
    അവസ്ഥ TOK_ASMDIR_long:
    അവസ്ഥ TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        വേണ്ടി(;;) {
            വ്യഞ്ജകം_മൂല്യം e;
            asm_വ്യഞ്ജകം(s1, &e);
            എങ്കിൽ (sec->sh_type != SHT_NOBITS) {
                എങ്കിൽ (size == 4) {
                    gen_expr32(&e);
#എങ്കിൽ PTR_SIZE == 8
		} അല്ലെങ്കിൽ എങ്കിൽ (size == 8) {
		    gen_expr64(&e);
#endif
                } അല്ലെങ്കിൽ {
                    എങ്കിൽ (e.sym)
                        expect("constant");
                    എങ്കിൽ (size == 1)
                        g(e.v);
                    അല്ലെങ്കിൽ
                        gen_le16(e.v);
                }
            } അല്ലെങ്കിൽ {
                ind += size;
            }
            എങ്കിൽ (tok != ',')
                നിർത്തുക;
            next();
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_fill:
        {
            പൂർണ്ണസംഖ്യ repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_വ്യഞ്ജകം(s1);
            എങ്കിൽ (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                നിർത്തുക;
            }
            size = 1;
            val = 0;
            എങ്കിൽ (tok == ',') {
                next();
                size = asm_int_വ്യഞ്ജകം(s1);
                എങ്കിൽ (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    നിർത്തുക;
                }
                എങ്കിൽ (size > 8)
                    size = 8;
                എങ്കിൽ (tok == ',') {
                    next();
                    val = asm_int_വ്യഞ്ജകം(s1);
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
            വേണ്ടി(i = 0; i < repeat; i++) {
                വേണ്ടി(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_rept:
        {
            പൂർണ്ണസംഖ്യ repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_വ്യഞ്ജകം(s1);
            init_str = tok_str_alloc();
            ആകുമ്പോൾ (next(), tok != TOK_ASMDIR_endr) {
                എങ്കിൽ (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            ആകുമ്പോൾ (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            നിർത്തുക;
        }
    അവസ്ഥ TOK_ASMDIR_org:
        {
	    വ്യഞ്ജകം_മൂല്യം e;
	    ElfSym *esym;
            next();
	    asm_വ്യഞ്ജകം(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    എങ്കിൽ (esym) {
		എങ്കിൽ (esym->st_shndx != cur_text_section->sh_അക്കം)
		  expect("constant or same-section symbol");
		n += esym->st_മൂല്യം;
	    }
            എങ്കിൽ (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            പോകുക zero_pad;
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	എങ്കിൽ (tok == ',')
	    set_ചിഹ്നം(s1, tok1);
	നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_globl:
    അവസ്ഥ TOK_ASMDIR_global:
    അവസ്ഥ TOK_ASMDIR_weak:
    അവസ്ഥ TOK_ASMDIR_hidden:
	tok1 = tok;
	ചെയ്യുക { 
            Sym *sym;
            next();
	    എങ്കിൽ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ശൂന്യ);
	    എങ്കിൽ (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            എങ്കിൽ (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    അല്ലെങ്കിൽ എങ്കിൽ (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} ആകുമ്പോൾ (tok == ',');
	നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_string:
    അവസ്ഥ TOK_ASMDIR_ascii:
    അവസ്ഥ TOK_ASMDIR_asciz:
        {
            സ്ഥിരം അക്ഷരം *p;
            പൂർണ്ണസംഖ്യ i, size, t;

            t = tok;
            next();
            വേണ്ടി(;;) {
                എങ്കിൽ (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                എങ്കിൽ (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                വേണ്ടി(i = 0; i < size; i++)
                    g(p[i]);
                next();
                എങ്കിൽ (tok == ',') {
                    next();
                } അല്ലെങ്കിൽ എങ്കിൽ (tok != TOK_STR) {
                    നിർത്തുക;
                }
            }
	}
	നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_text:
    അവസ്ഥ TOK_ASMDIR_data:
    അവസ്ഥ TOK_ASMDIR_bss:
	{ 
            അക്ഷരം sname[64];
            tok1 = tok;
            n = 0;
            next();
            എങ്കിൽ (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_വ്യഞ്ജകം(s1);
		next();
            }
            എങ്കിൽ (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ശൂന്യ), n);
            അല്ലെങ്കിൽ
                sprintf(sname, "%s", get_tok_str(tok1, ശൂന്യ));
            use_section(s1, sname);
	}
	നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_file:
        {
            സ്ഥിരം അക്ഷരം *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            എങ്കിൽ (tok == TOK_PPNUM)
                next();
            എങ്കിൽ (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } അല്ലെങ്കിൽ {
                skip_to_eol(0);
                നിർത്തുക;
            }
            tccpp_putfile(p);
            next();
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_ident:
        {
            അക്ഷരം ident[256];

            ident[0] = '\0';
            next();
            എങ്കിൽ (tok == TOK_STR)
                pstrcat(ident, വലുപ്പം(ident), tokc.str.data);
            അല്ലെങ്കിൽ
                pstrcat(ident, വലുപ്പം(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    എങ്കിൽ (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            എങ്കിൽ (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ശൂന്യ));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ശൂന്യ));
            next();
            skip(',');
            n = asm_int_വ്യഞ്ജകം(s1);
            esym = elfsym(sym);
            എങ്കിൽ (esym) {
                esym->st_size = n;
            }
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_type:
        { 
            Sym *sym;
            സ്ഥിരം അക്ഷരം *newtype;
            പൂർണ്ണസംഖ്യ st_type;

            next();
	    എങ്കിൽ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ശൂന്യ);
            next();
            skip(',');
            എങ്കിൽ (tok == TOK_STR) {
                newtype = tokc.str.data;
            } അല്ലെങ്കിൽ {
                എങ്കിൽ (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, ശൂന്യ);
            }

            എങ്കിൽ (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                എങ്കിൽ (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                എങ്കിൽ (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                പോകുക set_st_type;
            } അല്ലെങ്കിൽ
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ശൂന്യ), sym->type.t, newtype);

            next();
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_pushsection:
    അവസ്ഥ TOK_ASMDIR_section:
        {
            അക്ഷരം sname[256];
	    പൂർണ്ണസംഖ്യ old_nb_section = s1->nb_sections;
            പൂർണ്ണസംഖ്യ flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            ആകുമ്പോൾ (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                എങ്കിൽ (tok == TOK_STR)
                    pstrcat(sname, വലുപ്പം(sname), tokc.str.data);
                അല്ലെങ്കിൽ
                    pstrcat(sname, വലുപ്പം(sname), get_tok_str(tok, ശൂന്യ));
                next();
            }
            എങ്കിൽ (tok == ',') {
                സ്ഥിരം അക്ഷരം *p;
                /* skip section options */
                next();
                എങ്കിൽ (tok != TOK_STR)
                    expect("string constant");
                വേണ്ടി (p = tokc.str.data; *p; ++p) {
                    എങ്കിൽ (*p == 'w')
                        flags |= SHF_WRITE;
                    എങ്കിൽ (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                എങ്കിൽ (tok == ',') {
                    next();
                    എങ്കിൽ (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    എങ്കിൽ (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    അല്ലെങ്കിൽ
	        തള്ളുക_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    എങ്കിൽ (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                എങ്കിൽ (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            എങ്കിൽ (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_popsection:
	next();
	എടുക്കുക_section(s1);
	നിർത്തുക;
#ifdef TCC_TARGET_I386
    അവസ്ഥ TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        നിർത്തുക;
#endif
#എങ്കിൽ PTR_SIZE == 8
    /* added for compatibility with GAS */
    അവസ്ഥ TOK_ASMDIR_code64:
        next();
        നിർത്തുക;
#endif
#ifdef TCC_TARGET_RISCV64
    അവസ്ഥ TOK_ASMDIR_option:
        next();
        തിരഞ്ഞെടുപ്പ്(tok){
            അവസ്ഥ TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            അവസ്ഥ TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            അവസ്ഥ TOK_ASM_pic:
            അവസ്ഥ TOK_ASM_nopic:
            അവസ്ഥ TOK_ASM_relax:
            അവസ്ഥ TOK_ASM_norelax:
            അവസ്ഥ TOK_ASM_തള്ളുക:
            അവസ്ഥ TOK_ASM_എടുക്കുക:
                /* TODO: unimplemented */
                next();
                നിർത്തുക;
            അവസ്ഥ TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ശൂന്യ));
                നിർത്തുക;
            സ്ഥിരസ്ഥിതി:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ശൂന്യ));
                നിർത്തുക;
        }
        നിർത്തുക;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    അവസ്ഥ TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	നിർത്തുക;
    അവസ്ഥ TOK_ASMDIR_reloc:
	{
	    വ്യഞ്ജകം_മൂല്യം e;
	    സ്ഥിരം അക്ഷരം *reloc_name;
	    പൂർണ്ണസംഖ്യ reloc_type = -1;

	    next();
	    asm_വ്യഞ്ജകം(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ശൂന്യ);
#എങ്കിൽ defined(TCC_TARGET_ARM64)
	    എങ്കിൽ (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_RISCV64)
	    എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    എങ്കിൽ (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, ശൂന്യ), e.v, reloc_type, 0);
	    next();
	}
	നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ശൂന്യ));
        നിർത്തുക;
    }
}


/* assemble a file */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_assemble_internal(TCCState *s1, പൂർണ്ണസംഖ്യ do_preprocess, പൂർണ്ണസംഖ്യ global)
{
    പൂർണ്ണസംഖ്യ opcode;
    പൂർണ്ണസംഖ്യ saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    എങ്കിൽ (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    വേണ്ടി(;;) {
        next();
        എങ്കിൽ (tok == TOK_EOF)
            നിർത്തുക;
        tcc_debug_വരി(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#എങ്കിൽ !defined(TCC_TARGET_ARM64)
        എങ്കിൽ (tok == '#') {
            /* horrible gas comment */
            ആകുമ്പോൾ (tok != TOK_LINEFEED)
                next();
        } അല്ലെങ്കിൽ
#endif
        എങ്കിൽ (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_PPNUM) {
            സ്ഥിരം അക്ഷരം *p;
            പൂർണ്ണസംഖ്യ n;
            p = tokc.str.data;
            n = strtoul(p, (അക്ഷരം **)&p, 10);
            എങ്കിൽ (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            പോകുക redo;
        } അല്ലെങ്കിൽ എങ്കിൽ (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            എങ്കിൽ (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                പോകുക redo;
            } അല്ലെങ്കിൽ എങ്കിൽ (tok == '=') {
		set_ചിഹ്നം(s1, opcode);
                പോകുക redo;
            } അല്ലെങ്കിൽ {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        എങ്കിൽ (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    തിരികെ 0;
}

/* Assemble the current file */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_assemble(TCCState *s1, പൂർണ്ണസംഖ്യ do_preprocess)
{
    പൂർണ്ണസംഖ്യ ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    തിരികെ ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
സ്ഥിതം ശൂന്യം tcc_assemble_inline(TCCState *s1, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ len, പൂർണ്ണസംഖ്യ global)
{
    സ്ഥിരം പൂർണ്ണസംഖ്യ *saved_macro_ptr = macro_ptr;
    പൂർണ്ണസംഖ്യ dotid = set_idnum('.', IS_ID);
#എങ്കിൽ !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    പൂർണ്ണസംഖ്യ dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = ശൂന്യ;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#എങ്കിൽ !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC പൂർണ്ണസംഖ്യ find_constraint(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, 
                           സ്ഥിരം അക്ഷരം *name, സ്ഥിരം അക്ഷരം **pp)
{
    പൂർണ്ണസംഖ്യ index;
    TokenSym *ts;
    സ്ഥിരം അക്ഷരം *p;

    എങ്കിൽ (isnum(*name)) {
        index = 0;
        ആകുമ്പോൾ (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        എങ്കിൽ ((unsigned)index >= nb_operands)
            index = -1;
    } അല്ലെങ്കിൽ എങ്കിൽ (*name == '[') {
        name++;
        p = strchr(name, ']');
        എങ്കിൽ (p) {
            ts = tok_alloc(name, p - name);
            വേണ്ടി(index = 0; index < nb_operands; index++) {
                എങ്കിൽ (operands[index].id == ts->tok)
                    പോകുക found;
            }
            index = -1;
        found:
            name = p + 1;
        } അല്ലെങ്കിൽ {
            index = -1;
        }
    } അല്ലെങ്കിൽ {
        index = -1;
    }
    എങ്കിൽ (pp)
        *pp = name;
    തിരികെ index;
}

സ്ഥിതം ശൂന്യം subst_asm_operands(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, 
                               CString *out_str, സ്ഥിരം അക്ഷരം *str)
{
    പൂർണ്ണസംഖ്യ c, index, modifier;
    ASMOperand *op;
    SValue sv;

    വേണ്ടി(;;) {
        c = *str++;
        എങ്കിൽ (c == '%') {
            എങ്കിൽ (*str == '%') {
                str++;
                പോകുക add_char;
            }
            modifier = 0;
            എങ്കിൽ (*str == 'c' || *str == 'n' ||
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
            എങ്കിൽ (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            എങ്കിൽ (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, ശൂന്യ), -1);
            } അല്ലെങ്കിൽ {
		എങ്കിൽ (op->vt == ശൂന്യ)
		    പോകുക error;
                sv = *op->vt;
                എങ്കിൽ (op->reg >= 0) {
                    sv.r = op->reg;
                    എങ്കിൽ (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } അല്ലെങ്കിൽ {
        add_char:
            cstr_ccat(out_str, c);
            എങ്കിൽ (c == '\0')
                നിർത്തുക;
        }
    }
}


സ്ഥിതം ശൂന്യം parse_asm_operands(ASMOperand *operands, പൂർണ്ണസംഖ്യ *nb_operands_ptr,
                               പൂർണ്ണസംഖ്യ is_output)
{
    ASMOperand *op;
    പൂർണ്ണസംഖ്യ nb_operands;
    അക്ഷരം* astr;

    എങ്കിൽ (tok != ':') {
        nb_operands = *nb_operands_ptr;
        വേണ്ടി(;;) {
            എങ്കിൽ (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            എങ്കിൽ (tok == '[') {
                next();
                എങ്കിൽ (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, വലുപ്പം op->constraint, astr);
            skip('(');
            gexpr();
            എങ്കിൽ (is_output) {
                എങ്കിൽ (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } അല്ലെങ്കിൽ {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                എങ്കിൽ ((vtop->r & VT_LVAL) &&
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
            എങ്കിൽ (tok == ',') {
                next();
            } അല്ലെങ്കിൽ {
                നിർത്തുക;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC ശൂന്യം asm_instr(ശൂന്യം)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    പൂർണ്ണസംഖ്യ nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    ആകുമ്പോൾ (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, വലുപ്പം(clobber_regs));
    എങ്കിൽ (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        എങ്കിൽ (tok == ':') {
            next();
            എങ്കിൽ (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                എങ്കിൽ (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    വേണ്ടി(;;) {
                        എങ്കിൽ (tok == ':')
                          നിർത്തുക;
                        എങ്കിൽ (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        എങ്കിൽ (tok == ',') {
                            next();
                        } അല്ലെങ്കിൽ {
                            നിർത്തുക;
                        }
                    }
                }
                എങ്കിൽ (tok == ':') {
                    /* goto labels */
                    next();
                    വേണ്ടി (;;) {
                        Sym *csym;
                        പൂർണ്ണസംഖ്യ asmname;
                        എങ്കിൽ (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        എങ്കിൽ (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       വലുപ്പം(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        എങ്കിൽ (!csym) {
                            csym = label_തള്ളുക(&global_label_അട്ടി, tok,
                                              LABEL_FORWARD);
                        } അല്ലെങ്കിൽ {
                            എങ്കിൽ (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        എങ്കിൽ (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        എങ്കിൽ (tok != ',')
                          നിർത്തുക;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    എങ്കിൽ (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (അക്ഷരം *)astr.data);
#endif
    എങ്കിൽ (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (അക്ഷരം *)astr.data);
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
    എങ്കിൽ (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    വേണ്ടി(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC ശൂന്യം asm_global_instr(ശൂന്യം)
{
    CString *astr;
    പൂർണ്ണസംഖ്യ saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    എങ്കിൽ (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (അക്ഷരം *)astr->data);
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
#അല്ലെങ്കിൽ
ST_FUNC പൂർണ്ണസംഖ്യ tcc_assemble(TCCState *s1, പൂർണ്ണസംഖ്യ do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC ശൂന്യം asm_instr(ശൂന്യം)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC ശൂന്യം asm_global_instr(ശൂന്യം)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
