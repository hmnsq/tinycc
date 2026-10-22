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
#અન્તર્ભાવ "tcc.h"
#ifdef CONFIG_TCC_ASM

સ્થિર Section *last_text_section; /* to handle .previous asm directive */
સ્થિર પૂર્ણાંક asmgoto_n;

સ્થિર પૂર્ણાંક tcc_assemble_internal(TCCState *s1, પૂર્ણાંક do_preprocess, પૂર્ણાંક global);
સ્થિર Sym* asm_new_label(TCCState *s1, પૂર્ણાંક label, પૂર્ણાંક is_local);
સ્થિર Sym* asm_new_label1(TCCState *s1, પૂર્ણાંક label, પૂર્ણાંક is_local, પૂર્ણાંક sh_અંક, પૂર્ણાંક કિંમત);

#જો PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC શૂન્ય gen_addr64(પૂર્ણાંક r, Sym *sym, int64_t c)
{
    જો (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC શૂન્ય gen_expr64(પદાવલિ_કિંમત *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

સ્થિર પૂર્ણાંક asm_get_prefix_name(TCCState *s1, અચલ અક્ષર *prefix, unsigned પૂર્ણાંક n)
{
    અક્ષર buf[64];
    snprintf(buf, કદ(buf), "%s%u", prefix, n);
    પાછા tok_alloc_const(buf);
}

ST_FUNC પૂર્ણાંક asm_get_local_label_name(TCCState *s1, unsigned પૂર્ણાંક n)
{
    પાછા asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
સ્થિર પૂર્ણાંક asm2cname(પૂર્ણાંક v, પૂર્ણાંક *addeddot)
{
    અચલ અક્ષર *name;
    *addeddot = 0;
    જો (!tcc_state->leading_underscore)
      પાછા v;
    name = get_tok_str(v, ખાલી);
    જો (!name)
      પાછા v;
    જો (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } નહીંતર જો (!strchr(name, '.')) {
        અક્ષર newname[256];
        snprintf(newname, કદ newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    પાછા v;
}

સ્થિર Sym *asm_label_find(પૂર્ણાંક v)
{
    Sym *sym;
    પૂર્ણાંક addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    જ્યારે (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    પાછા sym;
}

સ્થિર Sym *asm_label_ધકેલો(પૂર્ણાંક v)
{
    પૂર્ણાંક addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ધકેલો(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    જો (addeddot)
        sym->asm_label = v;
    પાછા sym;
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
ST_FUNC Sym* get_asm_sym(પૂર્ણાંક name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    જો (!sym) {
	sym = asm_label_ધકેલો(name);
	જો (csym)
	  sym->c = csym->c;
    }
    પાછા sym;
}

સ્થિર Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    અક્ષર buf[100]; પૂર્ણાંક label; Sym *sym;
    snprintf(buf, કદ buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    પાછા sym ? sym : asm_new_label1(s1, label, 1, sec->sh_અંક, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

સ્થિર શૂન્ય asm_પદાવલિ_unary(TCCState *s1, પદાવલિ_કિંમત *pe)
{
    Sym *sym;
    પૂર્ણાંક op, label;
    uint64_t n;
    અચલ અક્ષર *p;

    પસંદગી(tok) {
    સ્થિતિ TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (અક્ષર **)&p, 0);
        જો (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            જો (*p == 'b') {
                /* backward : find the last corresponding defined label */
                જો (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                જો (!sym)
                    tcc_error("local label '%d' not found backward", (પૂર્ણાંક)n);
            } નહીંતર {
                /* forward */
                જો (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ધકેલો(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } નહીંતર જો (*p == '\0') {
            pe->v = n;
            pe->sym = ખાલી;
	    pe->pcrel = 0;
        } નહીંતર {
            tcc_error("invalid number syntax");
        }
        next();
        તોડો;
    સ્થિતિ '+':
        next();
        asm_પદાવલિ_unary(s1, pe);
        તોડો;
    સ્થિતિ '-':
    સ્થિતિ '~':
        op = tok;
        next();
        asm_પદાવલિ_unary(s1, pe);
        જો (pe->sym)
            tcc_error("invalid operation with label");
        જો (op == '-')
            pe->v = -pe->v;
        નહીંતર
            pe->v = ~pe->v;
        તોડો;
    સ્થિતિ TOK_CCHAR:
    સ્થિતિ TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ખાલી;
	pe->pcrel = 0;
	next();
	તોડો;
    સ્થિતિ '(':
        next();
        asm_પદાવલિ(s1, pe);
        skip(')');
        તોડો;
    સ્થિતિ '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        તોડો;
    મૂળભૂત:
        જો (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ખાલી);
	    esym = elfsym(sym);
            જો (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_કિંમત;
                pe->sym = ખાલી;
		pe->pcrel = 0;
            } નહીંતર {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } નહીંતર {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        તોડો;
    }
}
    
સ્થિર શૂન્ય asm_પદાવલિ_prod(TCCState *s1, પદાવલિ_કિંમત *pe)
{
    પૂર્ણાંક op;
    પદાવલિ_કિંમત e2;

    asm_પદાવલિ_unary(s1, pe);
    માટે(;;) {
        op = tok;
        જો (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            તોડો;
        next();
        asm_પદાવલિ_unary(s1, &e2);
        જો (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        પસંદગી(op) {
        સ્થિતિ '*':
            pe->v *= e2.v;
            તોડો;
        સ્થિતિ '/':  
            જો (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            તોડો;
        સ્થિતિ '%':  
            જો (e2.v == 0)
                જાઓ div_error;
            pe->v %= e2.v;
            તોડો;
        સ્થિતિ TOK_SHL:
            pe->v <<= e2.v;
            તોડો;
        મૂળભૂત:
        સ્થિતિ TOK_SAR:
            pe->v >>= e2.v;
            તોડો;
        }
    }
}

સ્થિર શૂન્ય asm_પદાવલિ_logic(TCCState *s1, પદાવલિ_કિંમત *pe)
{
    પૂર્ણાંક op;
    પદાવલિ_કિંમત e2;

    asm_પદાવલિ_prod(s1, pe);
    માટે(;;) {
        op = tok;
        જો (op != '&' && op != '|' && op != '^')
            તોડો;
        next();
        asm_પદાવલિ_prod(s1, &e2);
        જો (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        પસંદગી(op) {
        સ્થિતિ '&':
            pe->v &= e2.v;
            તોડો;
        સ્થિતિ '|':  
            pe->v |= e2.v;
            તોડો;
        મૂળભૂત:
        સ્થિતિ '^':
            pe->v ^= e2.v;
            તોડો;
        }
    }
}

સ્થિર અંતઃરેખ શૂન્ય asm_પદાવલિ_sum(TCCState *s1, પદાવલિ_કિંમત *pe)
{
    પૂર્ણાંક op;
    પદાવલિ_કિંમત e2;

    asm_પદાવલિ_logic(s1, pe);
    માટે(;;) {
        op = tok;
        જો (op != '+' && op != '-')
            તોડો;
        next();
        asm_પદાવલિ_logic(s1, &e2);
        જો (op == '+') {
            જો (pe->sym != ખાલી && e2.sym != ખાલી)
                જાઓ cannot_relocate;
            pe->v += e2.v;
            જો (pe->sym == ખાલી && e2.sym != ખાલી)
                pe->sym = e2.sym;
        } નહીંતર {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    જો (!e2.sym) {
		/* OK */
	    } નહીંતર જો (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ખાલી; /* same symbols can be subtracted to NULL */
	    } નહીંતર {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		જો (!esym2)
		    જાઓ cannot_relocate;
		જો (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (પૂર્ણાંક)(esym1->st_કિંમત - esym2->st_કિંમત);
		    pe->sym = ખાલી;
		} નહીંતર જો (esym2->st_shndx == cur_text_section->sh_અંક) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (પૂર્ણાંક)(0 - esym2->st_કિંમત);
		    pe->pcrel = 1;
		    e2.sym = ખાલી;
		} નહીંતર {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

સ્થિર અંતઃરેખ શૂન્ય asm_પદાવલિ_cmp(TCCState *s1, પદાવલિ_કિંમત *pe)
{
    પૂર્ણાંક op;
    પદાવલિ_કિંમત e2;

    asm_પદાવલિ_sum(s1, pe);
    માટે(;;) {
        op = tok;
	જો (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            તોડો;
        next();
        asm_પદાવલિ_sum(s1, &e2);
        જો (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        પસંદગી(op) {
	સ્થિતિ TOK_EQ:
	    pe->v = pe->v == e2.v;
	    તોડો;
	સ્થિતિ TOK_NE:
	    pe->v = pe->v != e2.v;
	    તોડો;
	સ્થિતિ TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    તોડો;
	સ્થિતિ TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    તોડો;
	સ્થિતિ TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    તોડો;
	સ્થિતિ TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    તોડો;
        મૂળભૂત:
            તોડો;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC શૂન્ય asm_પદાવલિ(TCCState *s1, પદાવલિ_કિંમત *pe)
{
    asm_પદાવલિ_cmp(s1, pe);
}

ST_FUNC પૂર્ણાંક asm_int_પદાવલિ(TCCState *s1)
{
    પદાવલિ_કિંમત e;
    asm_પદાવલિ(s1, &e);
    જો (e.sym)
        expect("constant");
    જો ((પૂર્ણાંક)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    પાછા e.v;
}

સ્થિર Sym* asm_new_label1(TCCState *s1, પૂર્ણાંક label, પૂર્ણાંક is_local,
                           પૂર્ણાંક sh_અંક, પૂર્ણાંક કિંમત)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    જો (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        જો (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            જો (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                જાઓ new_label;
            જો (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ખાલી));
        }
    } નહીંતર {
    new_label:
        sym = asm_label_ધકેલો(label);
    }
    જો (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_અંક;
    esym->st_કિંમત = કિંમત;
    જો (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    પાછા sym;
}

સ્થિર Sym* asm_new_label(TCCState *s1, પૂર્ણાંક label, પૂર્ણાંક is_local)
{
    પાછા asm_new_label1(s1, label, is_local, cur_text_section->sh_અંક, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
સ્થિર Sym* set_પ્રતીક(TCCState *s1, પૂર્ણાંક label)
{
    long n;
    પદાવલિ_કિંમત e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_પદાવલિ(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    જો (esym)
	n += esym->st_કિંમત;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    પાછા sym;
}

સ્થિર શૂન્ય use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

સ્થિર શૂન્ય use_section(TCCState *s1, અચલ અક્ષર *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

સ્થિર શૂન્ય ધકેલો_section(TCCState *s1, અચલ અક્ષર *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

સ્થિર શૂન્ય કાઢો_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    જો (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = ખાલી;
    use_section1(s1, prev);
}

સ્થિર શૂન્ય asm_parse_directive(TCCState *s1, પૂર્ણાંક global)
{
    પૂર્ણાંક n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    પસંદગી(tok) {
    સ્થિતિ TOK_ASMDIR_align:
    સ્થિતિ TOK_ASMDIR_balign:
    સ્થિતિ TOK_ASMDIR_p2align:
    સ્થિતિ TOK_ASMDIR_skip:
    સ્થિતિ TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_પદાવલિ(s1);
        જો (tok1 == TOK_ASMDIR_p2align)
        {
            જો (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        જો (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            જો (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            જો (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } નહીંતર {
	    જો (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        જો (tok == ',') {
            next();
            v = asm_int_પદાવલિ(s1), c = 0;
        }
    zero_pad:
	જો ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        જો (sec->sh_type != SHT_NOBITS) {
            જો (c) {
                gen_fill_nops(size);
                તોડો;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        તોડો;
    સ્થિતિ TOK_ASMDIR_quad:
#જો PTR_SIZE == 8
	size = 8;
	જાઓ asm_data;
#નહીંતર
        next();
        માટે(;;) {
            uint64_t vl;
            અચલ અક્ષર *p;

            p = tokc.str.data;
            જો (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (અક્ષર **)&p, 0);
            જો (*p != '\0')
                જાઓ error_constant;
            next();
            જો (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } નહીંતર {
                ind += 8;
            }
            જો (tok != ',')
                તોડો;
            next();
        }
        તોડો;
#endif
    સ્થિતિ TOK_ASMDIR_byte:
        size = 1;
        જાઓ asm_data;
    સ્થિતિ TOK_ASMDIR_word:
    સ્થિતિ TOK_ASMDIR_short:
        size = 2;
        જાઓ asm_data;
    સ્થિતિ TOK_ASMDIR_long:
    સ્થિતિ TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        માટે(;;) {
            પદાવલિ_કિંમત e;
            asm_પદાવલિ(s1, &e);
            જો (sec->sh_type != SHT_NOBITS) {
                જો (size == 4) {
                    gen_expr32(&e);
#જો PTR_SIZE == 8
		} નહીંતર જો (size == 8) {
		    gen_expr64(&e);
#endif
                } નહીંતર {
                    જો (e.sym)
                        expect("constant");
                    જો (size == 1)
                        g(e.v);
                    નહીંતર
                        gen_le16(e.v);
                }
            } નહીંતર {
                ind += size;
            }
            જો (tok != ',')
                તોડો;
            next();
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_fill:
        {
            પૂર્ણાંક repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_પદાવલિ(s1);
            જો (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                તોડો;
            }
            size = 1;
            val = 0;
            જો (tok == ',') {
                next();
                size = asm_int_પદાવલિ(s1);
                જો (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    તોડો;
                }
                જો (size > 8)
                    size = 8;
                જો (tok == ',') {
                    next();
                    val = asm_int_પદાવલિ(s1);
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
            માટે(i = 0; i < repeat; i++) {
                માટે(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_rept:
        {
            પૂર્ણાંક repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_પદાવલિ(s1);
            init_str = tok_str_alloc();
            જ્યારે (next(), tok != TOK_ASMDIR_endr) {
                જો (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            જ્યારે (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            તોડો;
        }
    સ્થિતિ TOK_ASMDIR_org:
        {
	    પદાવલિ_કિંમત e;
	    ElfSym *esym;
            next();
	    asm_પદાવલિ(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    જો (esym) {
		જો (esym->st_shndx != cur_text_section->sh_અંક)
		  expect("constant or same-section symbol");
		n += esym->st_કિંમત;
	    }
            જો (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            જાઓ zero_pad;
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	જો (tok == ',')
	    set_પ્રતીક(s1, tok1);
	તોડો;
    સ્થિતિ TOK_ASMDIR_globl:
    સ્થિતિ TOK_ASMDIR_global:
    સ્થિતિ TOK_ASMDIR_weak:
    સ્થિતિ TOK_ASMDIR_hidden:
	tok1 = tok;
	કરો { 
            Sym *sym;
            next();
	    જો (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ખાલી);
	    જો (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            જો (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    નહીંતર જો (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} જ્યારે (tok == ',');
	તોડો;
    સ્થિતિ TOK_ASMDIR_string:
    સ્થિતિ TOK_ASMDIR_ascii:
    સ્થિતિ TOK_ASMDIR_asciz:
        {
            અચલ અક્ષર *p;
            પૂર્ણાંક i, size, t;

            t = tok;
            next();
            માટે(;;) {
                જો (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                જો (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                માટે(i = 0; i < size; i++)
                    g(p[i]);
                next();
                જો (tok == ',') {
                    next();
                } નહીંતર જો (tok != TOK_STR) {
                    તોડો;
                }
            }
	}
	તોડો;
    સ્થિતિ TOK_ASMDIR_text:
    સ્થિતિ TOK_ASMDIR_data:
    સ્થિતિ TOK_ASMDIR_bss:
	{ 
            અક્ષર sname[64];
            tok1 = tok;
            n = 0;
            next();
            જો (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_પદાવલિ(s1);
		next();
            }
            જો (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ખાલી), n);
            નહીંતર
                sprintf(sname, "%s", get_tok_str(tok1, ખાલી));
            use_section(s1, sname);
	}
	તોડો;
    સ્થિતિ TOK_ASMDIR_file:
        {
            અચલ અક્ષર *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            જો (tok == TOK_PPNUM)
                next();
            જો (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } નહીંતર જો (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } નહીંતર {
                skip_to_eol(0);
                તોડો;
            }
            tccpp_putfile(p);
            next();
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_ident:
        {
            અક્ષર ident[256];

            ident[0] = '\0';
            next();
            જો (tok == TOK_STR)
                pstrcat(ident, કદ(ident), tokc.str.data);
            નહીંતર
                pstrcat(ident, કદ(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    જો (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            જો (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ખાલી));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ખાલી));
            next();
            skip(',');
            n = asm_int_પદાવલિ(s1);
            esym = elfsym(sym);
            જો (esym) {
                esym->st_size = n;
            }
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_type:
        { 
            Sym *sym;
            અચલ અક્ષર *newtype;
            પૂર્ણાંક st_type;

            next();
	    જો (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ખાલી);
            next();
            skip(',');
            જો (tok == TOK_STR) {
                newtype = tokc.str.data;
            } નહીંતર {
                જો (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, ખાલી);
            }

            જો (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                જો (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                જો (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } નહીંતર જો (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                જાઓ set_st_type;
            } નહીંતર
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ખાલી), sym->type.t, newtype);

            next();
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_pushsection:
    સ્થિતિ TOK_ASMDIR_section:
        {
            અક્ષર sname[256];
	    પૂર્ણાંક old_nb_section = s1->nb_sections;
            પૂર્ણાંક flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            જ્યારે (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                જો (tok == TOK_STR)
                    pstrcat(sname, કદ(sname), tokc.str.data);
                નહીંતર
                    pstrcat(sname, કદ(sname), get_tok_str(tok, ખાલી));
                next();
            }
            જો (tok == ',') {
                અચલ અક્ષર *p;
                /* skip section options */
                next();
                જો (tok != TOK_STR)
                    expect("string constant");
                માટે (p = tokc.str.data; *p; ++p) {
                    જો (*p == 'w')
                        flags |= SHF_WRITE;
                    જો (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                જો (tok == ',') {
                    next();
                    જો (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    જો (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    નહીંતર
	        ધકેલો_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    જો (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                જો (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            જો (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_popsection:
	next();
	કાઢો_section(s1);
	તોડો;
#ifdef TCC_TARGET_I386
    સ્થિતિ TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        તોડો;
    સ્થિતિ TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        તોડો;
#endif
#જો PTR_SIZE == 8
    /* added for compatibility with GAS */
    સ્થિતિ TOK_ASMDIR_code64:
        next();
        તોડો;
#endif
#ifdef TCC_TARGET_RISCV64
    સ્થિતિ TOK_ASMDIR_option:
        next();
        પસંદગી(tok){
            સ્થિતિ TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            સ્થિતિ TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            સ્થિતિ TOK_ASM_pic:
            સ્થિતિ TOK_ASM_nopic:
            સ્થિતિ TOK_ASM_relax:
            સ્થિતિ TOK_ASM_norelax:
            સ્થિતિ TOK_ASM_ધકેલો:
            સ્થિતિ TOK_ASM_કાઢો:
                /* TODO: unimplemented */
                next();
                તોડો;
            સ્થિતિ TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ખાલી));
                તોડો;
            મૂળભૂત:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ખાલી));
                તોડો;
        }
        તોડો;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    સ્થિતિ TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	તોડો;
    સ્થિતિ TOK_ASMDIR_reloc:
	{
	    પદાવલિ_કિંમત e;
	    અચલ અક્ષર *reloc_name;
	    પૂર્ણાંક reloc_type = -1;

	    next();
	    asm_પદાવલિ(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ખાલી);
#જો defined(TCC_TARGET_ARM64)
	    જો (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#અથવાજો defined(TCC_TARGET_RISCV64)
	    જો (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    નહીંતર જો (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    જો (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, ખાલી), e.v, reloc_type, 0);
	    next();
	}
	તોડો;
    મૂળભૂત:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ખાલી));
        તોડો;
    }
}


/* assemble a file */
સ્થિર પૂર્ણાંક tcc_assemble_internal(TCCState *s1, પૂર્ણાંક do_preprocess, પૂર્ણાંક global)
{
    પૂર્ણાંક opcode;
    પૂર્ણાંક saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    જો (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    માટે(;;) {
        next();
        જો (tok == TOK_EOF)
            તોડો;
        tcc_debug_લીટી(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#જો !defined(TCC_TARGET_ARM64)
        જો (tok == '#') {
            /* horrible gas comment */
            જ્યારે (tok != TOK_LINEFEED)
                next();
        } નહીંતર
#endif
        જો (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } નહીંતર જો (tok == TOK_PPNUM) {
            અચલ અક્ષર *p;
            પૂર્ણાંક n;
            p = tokc.str.data;
            n = strtoul(p, (અક્ષર **)&p, 10);
            જો (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            જાઓ redo;
        } નહીંતર જો (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            જો (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                જાઓ redo;
            } નહીંતર જો (tok == '=') {
		set_પ્રતીક(s1, opcode);
                જાઓ redo;
            } નહીંતર {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        જો (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    પાછા 0;
}

/* Assemble the current file */
ST_FUNC પૂર્ણાંક tcc_assemble(TCCState *s1, પૂર્ણાંક do_preprocess)
{
    પૂર્ણાંક ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    પાછા ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
સ્થિર શૂન્ય tcc_assemble_inline(TCCState *s1, અચલ અક્ષર *str, પૂર્ણાંક len, પૂર્ણાંક global)
{
    અચલ પૂર્ણાંક *saved_macro_ptr = macro_ptr;
    પૂર્ણાંક dotid = set_idnum('.', IS_ID);
#જો !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    પૂર્ણાંક dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = ખાલી;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#જો !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC પૂર્ણાંક find_constraint(ASMOperand *operands, પૂર્ણાંક nb_operands, 
                           અચલ અક્ષર *name, અચલ અક્ષર **pp)
{
    પૂર્ણાંક index;
    TokenSym *ts;
    અચલ અક્ષર *p;

    જો (isnum(*name)) {
        index = 0;
        જ્યારે (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        જો ((unsigned)index >= nb_operands)
            index = -1;
    } નહીંતર જો (*name == '[') {
        name++;
        p = strchr(name, ']');
        જો (p) {
            ts = tok_alloc(name, p - name);
            માટે(index = 0; index < nb_operands; index++) {
                જો (operands[index].id == ts->tok)
                    જાઓ found;
            }
            index = -1;
        found:
            name = p + 1;
        } નહીંતર {
            index = -1;
        }
    } નહીંતર {
        index = -1;
    }
    જો (pp)
        *pp = name;
    પાછા index;
}

સ્થિર શૂન્ય subst_asm_operands(ASMOperand *operands, પૂર્ણાંક nb_operands, 
                               CString *out_str, અચલ અક્ષર *str)
{
    પૂર્ણાંક c, index, modifier;
    ASMOperand *op;
    SValue sv;

    માટે(;;) {
        c = *str++;
        જો (c == '%') {
            જો (*str == '%') {
                str++;
                જાઓ add_char;
            }
            modifier = 0;
            જો (*str == 'c' || *str == 'n' ||
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
            જો (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            જો (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, ખાલી), -1);
            } નહીંતર {
		જો (op->vt == ખાલી)
		    જાઓ error;
                sv = *op->vt;
                જો (op->reg >= 0) {
                    sv.r = op->reg;
                    જો (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } નહીંતર {
        add_char:
            cstr_ccat(out_str, c);
            જો (c == '\0')
                તોડો;
        }
    }
}


સ્થિર શૂન્ય parse_asm_operands(ASMOperand *operands, પૂર્ણાંક *nb_operands_ptr,
                               પૂર્ણાંક is_output)
{
    ASMOperand *op;
    પૂર્ણાંક nb_operands;
    અક્ષર* astr;

    જો (tok != ':') {
        nb_operands = *nb_operands_ptr;
        માટે(;;) {
            જો (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            જો (tok == '[') {
                next();
                જો (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, કદ op->constraint, astr);
            skip('(');
            gexpr();
            જો (is_output) {
                જો (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } નહીંતર {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                જો ((vtop->r & VT_LVAL) &&
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
            જો (tok == ',') {
                next();
            } નહીંતર {
                તોડો;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC શૂન્ય asm_instr(શૂન્ય)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    પૂર્ણાંક nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    જ્યારે (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, કદ(clobber_regs));
    જો (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        જો (tok == ':') {
            next();
            જો (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                જો (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    માટે(;;) {
                        જો (tok == ':')
                          તોડો;
                        જો (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        જો (tok == ',') {
                            next();
                        } નહીંતર {
                            તોડો;
                        }
                    }
                }
                જો (tok == ':') {
                    /* goto labels */
                    next();
                    માટે (;;) {
                        Sym *csym;
                        પૂર્ણાંક asmname;
                        જો (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        જો (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       કદ(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        જો (!csym) {
                            csym = label_ધકેલો(&global_label_ઢગલો, tok,
                                              LABEL_FORWARD);
                        } નહીંતર {
                            જો (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        જો (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        જો (tok != ',')
                          તોડો;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    જો (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (અક્ષર *)astr.data);
#endif
    જો (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (અક્ષર *)astr.data);
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
    જો (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    માટે(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC શૂન્ય asm_global_instr(શૂન્ય)
{
    CString *astr;
    પૂર્ણાંક saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    જો (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (અક્ષર *)astr->data);
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
#નહીંતર
ST_FUNC પૂર્ણાંક tcc_assemble(TCCState *s1, પૂર્ણાંક do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC શૂન્ય asm_instr(શૂન્ય)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC શૂન્ય asm_global_instr(શૂન્ય)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
