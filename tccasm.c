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

#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"
#నిర్వచితమైతే CONFIG_TCC_ASM

స్థిర Section *చివరి_పాఠ్యం_section; /* to handle .previous asm directive */
స్థిర పూర్ణాంకం asmgoto_n;

స్థిర పూర్ణాంకం tcc_assemble_అంతర్గత(TCCState *s1, పూర్ణాంకం do_preprocess, పూర్ణాంకం global);
స్థిర Sym* asm_new_label(TCCState *s1, పూర్ణాంకం label, పూర్ణాంకం is_local);
స్థిర Sym* asm_new_label1(TCCState *s1, పూర్ణాంకం label, పూర్ణాంకం is_local, పూర్ణాంకం sh_అంకె, పూర్ణాంకం విలువ);

#ఒకవేళ PTR_కొలత == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC శూన్య gen_addr64(పూర్ణాంకం r, Sym *sym, int64_t c)
{
    ఒకవేళ (r & VT_SYM)
        greloca(cur_పాఠ్యం_section, sym, ind, R_దత్తాంశం_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC శూన్య gen_expr64(సమాసం_విలువ *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#అయితే_ముగింపు

స్థిర పూర్ణాంకం asm_get_ఉపసర్గ_name(TCCState *s1, స్థిరరాశి అక్షరం *ఉపసర్గ, గుర్తులేని పూర్ణాంకం n)
{
    అక్షరం buf[64];
    snprintf(buf, పరిమాణం(buf), "%s%u", ఉపసర్గ, n);
    తిరిగి tok_alloc_const(buf);
}

ST_FUNC పూర్ణాంకం asm_get_local_label_name(TCCState *s1, గుర్తులేని పూర్ణాంకం n)
{
    తిరిగి asm_get_ఉపసర్గ_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
స్థిర పూర్ణాంకం asm2cname(పూర్ణాంకం v, పూర్ణాంకం *addeddot)
{
    స్థిరరాశి అక్షరం *name;
    *addeddot = 0;
    ఒకవేళ (!tcc_state->leading_underscore)
      తిరిగి v;
    name = get_tok_str(v, ఖాళీ);
    ఒకవేళ (!name)
      తిరిగి v;
    ఒకవేళ (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } లేకపోతే ఒకవేళ (!strchr(name, '.')) {
        అక్షరం newname[256];
        snprintf(newname, పరిమాణం newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    తిరిగి v;
}

స్థిర Sym *asm_label_కనుగొను(పూర్ణాంకం v)
{
    Sym *sym;
    పూర్ణాంకం addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_కనుగొను(v);
    అయితే (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    తిరిగి sym;
}

స్థిర Sym *asm_label_నెట్టు(పూర్ణాంకం v)
{
    పూర్ణాంకం addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_నెట్టు(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    ఒకవేళ (addeddot)
        sym->asm_label = v;
    తిరిగి sym;
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
ST_FUNC Sym* get_asm_sym(పూర్ణాంకం name, Sym *csym)
{
    Sym *sym = asm_label_కనుగొను(name);
    ఒకవేళ (!sym) {
	sym = asm_label_నెట్టు(name);
	ఒకవేళ (csym)
	  sym->c = csym->c;
    }
    తిరిగి sym;
}

స్థిర Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    అక్షరం buf[100]; పూర్ణాంకం label; Sym *sym;
    snprintf(buf, పరిమాణం buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_కనుగొను(label);
    తిరిగి sym ? sym : asm_new_label1(s1, label, 1, sec->sh_అంకె, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

స్థిర శూన్య asm_సమాసం_unary(TCCState *s1, సమాసం_విలువ *pe)
{
    Sym *sym;
    పూర్ణాంకం op, label;
    uint64_t n;
    స్థిరరాశి అక్షరం *p;

    ఎంపిక(tok) {
    స్థితి TOK_PPNUM:
        p = tokc.str.దత్తాంశం;
        n = strtoull(p, (అక్షరం **)&p, 0);
        ఒకవేళ (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_కనుగొను(label);
            ఒకవేళ (*p == 'b') {
                /* backward : find the last corresponding defined label */
                ఒకవేళ (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                ఒకవేళ (!sym)
                    tcc_error("local label '%d' not found backward", (పూర్ణాంకం)n);
            } లేకపోతే {
                /* forward */
                ఒకవేళ (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_నెట్టు(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } లేకపోతే ఒకవేళ (*p == '\0') {
            pe->v = n;
            pe->sym = ఖాళీ;
	    pe->pcrel = 0;
        } లేకపోతే {
            tcc_error("invalid number syntax");
        }
        తదుపరి();
        ఆపు;
    స్థితి '+':
        తదుపరి();
        asm_సమాసం_unary(s1, pe);
        ఆపు;
    స్థితి '-':
    స్థితి '~':
        op = tok;
        తదుపరి();
        asm_సమాసం_unary(s1, pe);
        ఒకవేళ (pe->sym)
            tcc_error("invalid operation with label");
        ఒకవేళ (op == '-')
            pe->v = -pe->v;
        లేకపోతే
            pe->v = ~pe->v;
        ఆపు;
    స్థితి TOK_CCHAR:
    స్థితి TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = ఖాళీ;
	pe->pcrel = 0;
	తదుపరి();
	ఆపు;
    స్థితి '(':
        తదుపరి();
        asm_సమాసం(s1, pe);
        skip(')');
        ఆపు;
    స్థితి '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_పాఠ్యం_section);
        pe->pcrel = 0;
        తదుపరి();
        ఆపు;
    అప్రమేయ:
        ఒకవేళ (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, ఖాళీ);
	    esym = elfsym(sym);
            ఒకవేళ (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_విలువ;
                pe->sym = ఖాళీ;
		pe->pcrel = 0;
            } లేకపోతే {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            తదుపరి();
        } లేకపోతే {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        ఆపు;
    }
}
    
స్థిర శూన్య asm_సమాసం_prod(TCCState *s1, సమాసం_విలువ *pe)
{
    పూర్ణాంకం op;
    సమాసం_విలువ e2;

    asm_సమాసం_unary(s1, pe);
    కొరకు(;;) {
        op = tok;
        ఒకవేళ (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            ఆపు;
        తదుపరి();
        asm_సమాసం_unary(s1, &e2);
        ఒకవేళ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ఎంపిక(op) {
        స్థితి '*':
            pe->v *= e2.v;
            ఆపు;
        స్థితి '/':  
            ఒకవేళ (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            ఆపు;
        స్థితి '%':  
            ఒకవేళ (e2.v == 0)
                వెళ్ళు div_error;
            pe->v %= e2.v;
            ఆపు;
        స్థితి TOK_SHL:
            pe->v <<= e2.v;
            ఆపు;
        అప్రమేయ:
        స్థితి TOK_SAR:
            pe->v >>= e2.v;
            ఆపు;
        }
    }
}

స్థిర శూన్య asm_సమాసం_logic(TCCState *s1, సమాసం_విలువ *pe)
{
    పూర్ణాంకం op;
    సమాసం_విలువ e2;

    asm_సమాసం_prod(s1, pe);
    కొరకు(;;) {
        op = tok;
        ఒకవేళ (op != '&' && op != '|' && op != '^')
            ఆపు;
        తదుపరి();
        asm_సమాసం_prod(s1, &e2);
        ఒకవేళ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ఎంపిక(op) {
        స్థితి '&':
            pe->v &= e2.v;
            ఆపు;
        స్థితి '|':  
            pe->v |= e2.v;
            ఆపు;
        అప్రమేయ:
        స్థితి '^':
            pe->v ^= e2.v;
            ఆపు;
        }
    }
}

స్థిర అంతఃవరుస శూన్య asm_సమాసం_కూడిక(TCCState *s1, సమాసం_విలువ *pe)
{
    పూర్ణాంకం op;
    సమాసం_విలువ e2;

    asm_సమాసం_logic(s1, pe);
    కొరకు(;;) {
        op = tok;
        ఒకవేళ (op != '+' && op != '-')
            ఆపు;
        తదుపరి();
        asm_సమాసం_logic(s1, &e2);
        ఒకవేళ (op == '+') {
            ఒకవేళ (pe->sym != ఖాళీ && e2.sym != ఖాళీ)
                వెళ్ళు cannot_relocate;
            pe->v += e2.v;
            ఒకవేళ (pe->sym == ఖాళీ && e2.sym != ఖాళీ)
                pe->sym = e2.sym;
        } లేకపోతే {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    ఒకవేళ (!e2.sym) {
		/* OK */
	    } లేకపోతే ఒకవేళ (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = ఖాళీ; /* same symbols can be subtracted to NULL */
	    } లేకపోతే {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		ఒకవేళ (!esym2)
		    వెళ్ళు cannot_relocate;
		ఒకవేళ (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (పూర్ణాంకం)(esym1->st_విలువ - esym2->st_విలువ);
		    pe->sym = ఖాళీ;
		} లేకపోతే ఒకవేళ (esym2->st_shndx == cur_పాఠ్యం_section->sh_అంకె) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (పూర్ణాంకం)(0 - esym2->st_విలువ);
		    pe->pcrel = 1;
		    e2.sym = ఖాళీ;
		} లేకపోతే {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

స్థిర అంతఃవరుస శూన్య asm_సమాసం_cmp(TCCState *s1, సమాసం_విలువ *pe)
{
    పూర్ణాంకం op;
    సమాసం_విలువ e2;

    asm_సమాసం_కూడిక(s1, pe);
    కొరకు(;;) {
        op = tok;
	ఒకవేళ (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            ఆపు;
        తదుపరి();
        asm_సమాసం_కూడిక(s1, &e2);
        ఒకవేళ (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        ఎంపిక(op) {
	స్థితి TOK_EQ:
	    pe->v = pe->v == e2.v;
	    ఆపు;
	స్థితి TOK_NE:
	    pe->v = pe->v != e2.v;
	    ఆపు;
	స్థితి TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    ఆపు;
	స్థితి TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    ఆపు;
	స్థితి TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    ఆపు;
	స్థితి TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    ఆపు;
        అప్రమేయ:
            ఆపు;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC శూన్య asm_సమాసం(TCCState *s1, సమాసం_విలువ *pe)
{
    asm_సమాసం_cmp(s1, pe);
}

ST_FUNC పూర్ణాంకం asm_int_సమాసం(TCCState *s1)
{
    సమాసం_విలువ e;
    asm_సమాసం(s1, &e);
    ఒకవేళ (e.sym)
        expect("constant");
    ఒకవేళ ((పూర్ణాంకం)e.v != e.v)
	tcc_error("integer out of range %lld", (దీర్ఘ దీర్ఘ)e.v);
    తిరిగి e.v;
}

స్థిర Sym* asm_new_label1(TCCState *s1, పూర్ణాంకం label, పూర్ణాంకం is_local,
                           పూర్ణాంకం sh_అంకె, పూర్ణాంకం విలువ)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_కనుగొను(label);
    ఒకవేళ (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        ఒకవేళ (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            ఒకవేళ (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                వెళ్ళు new_label;
            ఒకవేళ (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, ఖాళీ));
        }
    } లేకపోతే {
    new_label:
        sym = asm_label_నెట్టు(label);
    }
    ఒకవేళ (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_అంకె;
    esym->st_విలువ = విలువ;
    ఒకవేళ (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    తిరిగి sym;
}

స్థిర Sym* asm_new_label(TCCState *s1, పూర్ణాంకం label, పూర్ణాంకం is_local)
{
    తిరిగి asm_new_label1(s1, label, is_local, cur_పాఠ్యం_section->sh_అంకె, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
స్థిర Sym* సమితి_చిహ్నం(TCCState *s1, పూర్ణాంకం label)
{
    దీర్ఘ n;
    సమాసం_విలువ e;
    Sym *sym;
    ElfSym *esym;
    తదుపరి();
    asm_సమాసం(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    ఒకవేళ (esym)
	n += esym->st_విలువ;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_సమితి;
    తిరిగి sym;
}

స్థిర శూన్య use_section1(TCCState *s1, Section *sec)
{
    cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం = ind;
    cur_పాఠ్యం_section = sec;
    ind = cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;
}

స్థిర శూన్య use_section(TCCState *s1, స్థిరరాశి అక్షరం *name)
{
    Section *sec;
    sec = కనుగొను_section(s1, name);
    use_section1(s1, sec);
}

స్థిర శూన్య నెట్టు_section(TCCState *s1, స్థిరరాశి అక్షరం *name)
{
    Section *sec = కనుగొను_section(s1, name);
    sec->prev = cur_పాఠ్యం_section;
    use_section1(s1, sec);
}

స్థిర శూన్య తీయి_section(TCCState *s1)
{
    Section *prev = cur_పాఠ్యం_section->prev;
    ఒకవేళ (!prev)
        tcc_error(".popsection without .pushsection");
    cur_పాఠ్యం_section->prev = ఖాళీ;
    use_section1(s1, prev);
}

స్థిర శూన్య asm_parse_directive(TCCState *s1, పూర్ణాంకం global)
{
    పూర్ణాంకం n, స్థానభ్రంశం, v, కొలత, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_పాఠ్యం_section;
    ఎంపిక(tok) {
    స్థితి TOK_ASMDIR_align:
    స్థితి TOK_ASMDIR_balign:
    స్థితి TOK_ASMDIR_p2align:
    స్థితి TOK_ASMDIR_skip:
    స్థితి TOK_ASMDIR_space:
        tok1 = tok;
        తదుపరి();
        n = asm_int_సమాసం(s1);
        ఒకవేళ (tok1 == TOK_ASMDIR_p2align)
        {
            ఒకవేళ (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        ఒకవేళ (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            ఒకవేళ (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            స్థానభ్రంశం = (ind + n - 1) & -n;
            కొలత = స్థానభ్రంశం - ind;
            /* the section must have a compatible alignment */
            ఒకవేళ (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } లేకపోతే {
	    ఒకవేళ (n < 0)
	        n = 0;
            కొలత = n, c = 0;
        }
        v = 0;
        ఒకవేళ (tok == ',') {
            తదుపరి();
            v = asm_int_సమాసం(s1), c = 0;
        }
    zero_pad:
	ఒకవేళ ((uint64_t)ind + కొలత >= 1<<30)
	    tcc_error("too much data");
        ఒకవేళ (sec->sh_type != SHT_NOBITS) {
            ఒకవేళ (c) {
                gen_fill_nops(కొలత);
                ఆపు;
            }
            sec->దత్తాంశం_స్థానభ్రంశం = ind;
            ptr = section_ptr_కూడు(sec, కొలత);
            memset(ptr, v, కొలత);
        }
        ind += కొలత;
        ఆపు;
    స్థితి TOK_ASMDIR_quad:
#ఒకవేళ PTR_కొలత == 8
	కొలత = 8;
	వెళ్ళు asm_దత్తాంశం;
#లేకపోతే
        తదుపరి();
        కొరకు(;;) {
            uint64_t vl;
            స్థిరరాశి అక్షరం *p;

            p = tokc.str.దత్తాంశం;
            ఒకవేళ (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (అక్షరం **)&p, 0);
            ఒకవేళ (*p != '\0')
                వెళ్ళు error_constant;
            తదుపరి();
            ఒకవేళ (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } లేకపోతే {
                ind += 8;
            }
            ఒకవేళ (tok != ',')
                ఆపు;
            తదుపరి();
        }
        ఆపు;
#అయితే_ముగింపు
    స్థితి TOK_ASMDIR_byte:
        కొలత = 1;
        వెళ్ళు asm_దత్తాంశం;
    స్థితి TOK_ASMDIR_మాట:
    స్థితి TOK_ASMDIR_short:
        కొలత = 2;
        వెళ్ళు asm_దత్తాంశం;
    స్థితి TOK_ASMDIR_long:
    స్థితి TOK_ASMDIR_int:
        కొలత = 4;
    asm_దత్తాంశం:
        తదుపరి();
        కొరకు(;;) {
            సమాసం_విలువ e;
            asm_సమాసం(s1, &e);
            ఒకవేళ (sec->sh_type != SHT_NOBITS) {
                ఒకవేళ (కొలత == 4) {
                    gen_expr32(&e);
#ఒకవేళ PTR_కొలత == 8
		} లేకపోతే ఒకవేళ (కొలత == 8) {
		    gen_expr64(&e);
#అయితే_ముగింపు
                } లేకపోతే {
                    ఒకవేళ (e.sym)
                        expect("constant");
                    ఒకవేళ (కొలత == 1)
                        g(e.v);
                    లేకపోతే
                        gen_le16(e.v);
                }
            } లేకపోతే {
                ind += కొలత;
            }
            ఒకవేళ (tok != ',')
                ఆపు;
            తదుపరి();
        }
        ఆపు;
    స్థితి TOK_ASMDIR_fill:
        {
            పూర్ణాంకం repeat, కొలత, val, i, j;
            uint8_t repeat_buf[8];
            తదుపరి();
            repeat = asm_int_సమాసం(s1);
            ఒకవేళ (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                ఆపు;
            }
            కొలత = 1;
            val = 0;
            ఒకవేళ (tok == ',') {
                తదుపరి();
                కొలత = asm_int_సమాసం(s1);
                ఒకవేళ (కొలత < 0) {
                    tcc_error("size < 0; .fill ignored");
                    ఆపు;
                }
                ఒకవేళ (కొలత > 8)
                    కొలత = 8;
                ఒకవేళ (tok == ',') {
                    తదుపరి();
                    val = asm_int_సమాసం(s1);
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
            కొరకు(i = 0; i < repeat; i++) {
                కొరకు(j = 0; j < కొలత; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        ఆపు;
    స్థితి TOK_ASMDIR_rept:
        {
            పూర్ణాంకం repeat;
            TokenString *init_str;
            తదుపరి();
            repeat = asm_int_సమాసం(s1);
            init_str = tok_str_alloc();
            అయితే (తదుపరి(), tok != TOK_ASMDIR_endr) {
                ఒకవేళ (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_కూడు_tok(init_str);
            }
            tok_str_కూడు(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            అయితే (repeat-- > 0) {
                tcc_assemble_అంతర్గత(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            చివర_macro();
            తదుపరి();
            ఆపు;
        }
    స్థితి TOK_ASMDIR_org:
        {
	    సమాసం_విలువ e;
	    ElfSym *esym;
            తదుపరి();
	    asm_సమాసం(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    ఒకవేళ (esym) {
		ఒకవేళ (esym->st_shndx != cur_పాఠ్యం_section->sh_అంకె)
		  expect("constant or same-section symbol");
		n += esym->st_విలువ;
	    }
            ఒకవేళ (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            కొలత = n - ind;
            వెళ్ళు zero_pad;
        }
        ఆపు;
    స్థితి TOK_ASMDIR_సమితి:
	తదుపరి();
	tok1 = tok;
	తదుపరి();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	ఒకవేళ (tok == ',')
	    సమితి_చిహ్నం(s1, tok1);
	ఆపు;
    స్థితి TOK_ASMDIR_globl:
    స్థితి TOK_ASMDIR_global:
    స్థితి TOK_ASMDIR_weak:
    స్థితి TOK_ASMDIR_hidden:
	tok1 = tok;
	చేయి { 
            Sym *sym;
            తదుపరి();
	    ఒకవేళ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ఖాళీ);
	    ఒకవేళ (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            ఒకవేళ (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    లేకపోతే ఒకవేళ (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            తదుపరి();
	} అయితే (tok == ',');
	ఆపు;
    స్థితి TOK_ASMDIR_string:
    స్థితి TOK_ASMDIR_ascii:
    స్థితి TOK_ASMDIR_asciz:
        {
            స్థిరరాశి అక్షరం *p;
            పూర్ణాంకం i, కొలత, t;

            t = tok;
            తదుపరి();
            కొరకు(;;) {
                ఒకవేళ (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.దత్తాంశం;
                కొలత = tokc.str.కొలత;
                ఒకవేళ (t == TOK_ASMDIR_ascii && కొలత > 0)
                    కొలత--;
                కొరకు(i = 0; i < కొలత; i++)
                    g(p[i]);
                తదుపరి();
                ఒకవేళ (tok == ',') {
                    తదుపరి();
                } లేకపోతే ఒకవేళ (tok != TOK_STR) {
                    ఆపు;
                }
            }
	}
	ఆపు;
    స్థితి TOK_ASMDIR_పాఠ్యం:
    స్థితి TOK_ASMDIR_దత్తాంశం:
    స్థితి TOK_ASMDIR_bss:
	{ 
            అక్షరం sname[64];
            tok1 = tok;
            n = 0;
            తదుపరి();
            ఒకవేళ (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_సమాసం(s1);
		తదుపరి();
            }
            ఒకవేళ (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, ఖాళీ), n);
            లేకపోతే
                sprintf(sname, "%s", get_tok_str(tok1, ఖాళీ));
            use_section(s1, sname);
	}
	ఆపు;
    స్థితి TOK_ASMDIR_file:
        {
            స్థిరరాశి అక్షరం *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            తదుపరి();
            ఒకవేళ (tok == TOK_PPNUM)
                తదుపరి();
            ఒకవేళ (tok == TOK_PPSTR && tokc.str.దత్తాంశం[0] == '"') {
                tokc.str.దత్తాంశం[tokc.str.కొలత - 2] = 0;
                p = tokc.str.దత్తాంశం + 1;
            } లేకపోతే ఒకవేళ (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } లేకపోతే {
                skip_గమ్యం_eol(0);
                ఆపు;
            }
            tccpp_putfile(p);
            తదుపరి();
        }
        ఆపు;
    స్థితి TOK_ASMDIR_ident:
        {
            అక్షరం ident[256];

            ident[0] = '\0';
            తదుపరి();
            ఒకవేళ (tok == TOK_STR)
                pstrcat(ident, పరిమాణం(ident), tokc.str.దత్తాంశం);
            లేకపోతే
                pstrcat(ident, పరిమాణం(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            తదుపరి();
        }
        ఆపు;
    స్థితి TOK_ASMDIR_కొలత:
        { 
            Sym *sym;
            ElfSym *esym;

            తదుపరి();
	    ఒకవేళ (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_కనుగొను(tok);
            ఒకవేళ (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, ఖాళీ));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, ఖాళీ));
            తదుపరి();
            skip(',');
            n = asm_int_సమాసం(s1);
            esym = elfsym(sym);
            ఒకవేళ (esym) {
                esym->st_కొలత = n;
            }
        }
        ఆపు;
    స్థితి TOK_ASMDIR_type:
        { 
            Sym *sym;
            స్థిరరాశి అక్షరం *newtype;
            పూర్ణాంకం st_type;

            తదుపరి();
	    ఒకవేళ (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, ఖాళీ);
            తదుపరి();
            skip(',');
            ఒకవేళ (tok == TOK_STR) {
                newtype = tokc.str.దత్తాంశం;
            } లేకపోతే {
                ఒకవేళ (tok == '@' || tok == '%')
                    తదుపరి();
                newtype = get_tok_str(tok, ఖాళీ);
            }

            ఒకవేళ (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                ఒకవేళ (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            సమితి_st_type:
                ఒకవేళ (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } లేకపోతే ఒకవేళ (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                వెళ్ళు సమితి_st_type;
            } లేకపోతే
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, ఖాళీ), sym->type.t, newtype);

            తదుపరి();
        }
        ఆపు;
    స్థితి TOK_ASMDIR_pushsection:
    స్థితి TOK_ASMDIR_section:
        {
            అక్షరం sname[256];
	    పూర్ణాంకం old_nb_section = s1->nb_sections;
            పూర్ణాంకం flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            తదుపరి();
            sname[0] = '\0';
            అయితే (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                ఒకవేళ (tok == TOK_STR)
                    pstrcat(sname, పరిమాణం(sname), tokc.str.దత్తాంశం);
                లేకపోతే
                    pstrcat(sname, పరిమాణం(sname), get_tok_str(tok, ఖాళీ));
                తదుపరి();
            }
            ఒకవేళ (tok == ',') {
                స్థిరరాశి అక్షరం *p;
                /* skip section options */
                తదుపరి();
                ఒకవేళ (tok != TOK_STR)
                    expect("string constant");
                కొరకు (p = tokc.str.దత్తాంశం; *p; ++p) {
                    ఒకవేళ (*p == 'w')
                        flags |= SHF_WRITE;
                    ఒకవేళ (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                తదుపరి();
                ఒకవేళ (tok == ',') {
                    తదుపరి();
                    ఒకవేళ (tok == '@' || tok == '%')
                        తదుపరి();
                    తదుపరి();
                }
            }
            చివరి_పాఠ్యం_section = cur_పాఠ్యం_section;
	    ఒకవేళ (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    లేకపోతే
	        నెట్టు_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    ఒకవేళ (old_nb_section != s1->nb_sections) {
	        cur_పాఠ్యం_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                ఒకవేళ (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_పాఠ్యం_section->sh_flags = flags;
            }
        }
        ఆపు;
    స్థితి TOK_ASMDIR_మునుపటి:
        { 
            Section *sec;
            తదుపరి();
            ఒకవేళ (!చివరి_పాఠ్యం_section)
                tcc_error("no previous section referenced");
            sec = cur_పాఠ్యం_section;
            use_section1(s1, చివరి_పాఠ్యం_section);
            చివరి_పాఠ్యం_section = sec;
        }
        ఆపు;
    స్థితి TOK_ASMDIR_popsection:
	తదుపరి();
	తీయి_section(s1);
	ఆపు;
#నిర్వచితమైతే TCC_లక్ష్యం_I386
    స్థితి TOK_ASMDIR_code16:
        {
            తదుపరి();
            s1->seg_కొలత = 16;
        }
        ఆపు;
    స్థితి TOK_ASMDIR_code32:
        {
            తదుపరి();
            s1->seg_కొలత = 32;
        }
        ఆపు;
#అయితే_ముగింపు
#ఒకవేళ PTR_కొలత == 8
    /* added for compatibility with GAS */
    స్థితి TOK_ASMDIR_code64:
        తదుపరి();
        ఆపు;
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    స్థితి TOK_ASMDIR_option:
        తదుపరి();
        ఎంపిక(tok){
            స్థితి TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            స్థితి TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            స్థితి TOK_ASM_pic:
            స్థితి TOK_ASM_nopic:
            స్థితి TOK_ASM_relax:
            స్థితి TOK_ASM_norelax:
            స్థితి TOK_ASM_నెట్టు:
            స్థితి TOK_ASM_తీయి:
                /* TODO: unimplemented */
                తదుపరి();
                ఆపు;
            స్థితి TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, ఖాళీ));
                ఆపు;
            అప్రమేయ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, ఖాళీ));
                ఆపు;
        }
        ఆపు;
#అయితే_ముగింపు
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    స్థితి TOK_ASMDIR_symver:
	తదుపరి();
	తదుపరి();
        skip(',');
	తదుపరి();
        skip('@');
	తదుపరి();
	ఆపు;
    స్థితి TOK_ASMDIR_reloc:
	{
	    సమాసం_విలువ e;
	    స్థిరరాశి అక్షరం *reloc_name;
	    పూర్ణాంకం reloc_type = -1;

	    తదుపరి();
	    asm_సమాసం(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, ఖాళీ);
#ఒకవేళ defined(TCC_లక్ష్యం_ARM64)
	    ఒకవేళ (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#లేదావేళ defined(TCC_లక్ష్యం_RISCV64)
	    ఒకవేళ (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    లేకపోతే ఒకవేళ (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#అయితే_ముగింపు
	    ఒకవేళ (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    తదుపరి();
	    skip(',');
	    greloca(cur_పాఠ్యం_section, get_asm_sym(tok, ఖాళీ), e.v, reloc_type, 0);
	    తదుపరి();
	}
	ఆపు;
    అప్రమేయ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, ఖాళీ));
        ఆపు;
    }
}


/* assemble a file */
స్థిర పూర్ణాంకం tcc_assemble_అంతర్గత(TCCState *s1, పూర్ణాంకం do_preprocess, పూర్ణాంకం global)
{
    పూర్ణాంకం opcode;
    పూర్ణాంకం saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    ఒకవేళ (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    కొరకు(;;) {
        తదుపరి();
        ఒకవేళ (tok == TOK_EOF)
            ఆపు;
        tcc_debug_పంక్తి(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#ఒకవేళ !defined(TCC_లక్ష్యం_ARM64)
        ఒకవేళ (tok == '#') {
            /* horrible gas comment */
            అయితే (tok != TOK_LINEFEED)
                తదుపరి();
        } లేకపోతే
#అయితే_ముగింపు
        ఒకవేళ (tok >= TOK_ASMDIR_మొదటి && tok <= TOK_ASMDIR_చివరి) {
            asm_parse_directive(s1, global);
        } లేకపోతే ఒకవేళ (tok == TOK_PPNUM) {
            స్థిరరాశి అక్షరం *p;
            పూర్ణాంకం n;
            p = tokc.str.దత్తాంశం;
            n = strtoul(p, (అక్షరం **)&p, 10);
            ఒకవేళ (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            తదుపరి();
            skip(':');
            వెళ్ళు redo;
        } లేకపోతే ఒకవేళ (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            తదుపరి();
            ఒకవేళ (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                తదుపరి();
                వెళ్ళు redo;
            } లేకపోతే ఒకవేళ (tok == '=') {
		సమితి_చిహ్నం(s1, opcode);
                వెళ్ళు redo;
            } లేకపోతే {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        ఒకవేళ (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    తిరిగి 0;
}

/* Assemble the current file */
ST_FUNC పూర్ణాంకం tcc_assemble(TCCState *s1, పూర్ణాంకం do_preprocess)
{
    పూర్ణాంకం ret;
    tcc_debug_ప్రారంభం(s1);
    /* default section is text */
    cur_పాఠ్యం_section = పాఠ్యం_section;
    ind = cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;
    nocode_wanted = 0;
    ret = tcc_assemble_అంతర్గత(s1, do_preprocess, 1);
    cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం = ind;
    tcc_debug_చివర(s1);
    తిరిగి ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
స్థిర శూన్య tcc_assemble_inline(TCCState *s1, స్థిరరాశి అక్షరం *str, పూర్ణాంకం len, పూర్ణాంకం global)
{
    స్థిరరాశి పూర్ణాంకం *saved_macro_ptr = macro_ptr;
    పూర్ణాంకం dotid = సమితి_idnum('.', IS_ID);
#ఒకవేళ !defined(TCC_లక్ష్యం_RISCV64) && !defined(TCC_లక్ష్యం_X86_64)
    పూర్ణాంకం dolid = సమితి_idnum('$', 0);
#అయితే_ముగింపు

    tcc_open_bf(s1, ":asm:", len);
    జ్ఞాపకం_నకలు(file->బఫరు, str, len);
    macro_ptr = ఖాళీ;
    tcc_assemble_అంతర్గత(s1, 0, global);
    tcc_close();

#ఒకవేళ !defined(TCC_లక్ష్యం_RISCV64) && !defined(TCC_లక్ష్యం_X86_64)
    సమితి_idnum('$', dolid);
#అయితే_ముగింపు
    సమితి_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC పూర్ణాంకం కనుగొను_constraint(ASMOperand *operands, పూర్ణాంకం nb_operands, 
                           స్థిరరాశి అక్షరం *name, స్థిరరాశి అక్షరం **pp)
{
    పూర్ణాంకం సూచీ;
    TokenSym *ts;
    స్థిరరాశి అక్షరం *p;

    ఒకవేళ (isnum(*name)) {
        సూచీ = 0;
        అయితే (isnum(*name)) {
            సూచీ = (సూచీ * 10) + (*name) - '0';
            name++;
        }
        ఒకవేళ ((గుర్తులేని)సూచీ >= nb_operands)
            సూచీ = -1;
    } లేకపోతే ఒకవేళ (*name == '[') {
        name++;
        p = strchr(name, ']');
        ఒకవేళ (p) {
            ts = tok_alloc(name, p - name);
            కొరకు(సూచీ = 0; సూచీ < nb_operands; సూచీ++) {
                ఒకవేళ (operands[సూచీ].id == ts->tok)
                    వెళ్ళు దొరికింది;
            }
            సూచీ = -1;
        దొరికింది:
            name = p + 1;
        } లేకపోతే {
            సూచీ = -1;
        }
    } లేకపోతే {
        సూచీ = -1;
    }
    ఒకవేళ (pp)
        *pp = name;
    తిరిగి సూచీ;
}

స్థిర శూన్య subst_asm_operands(ASMOperand *operands, పూర్ణాంకం nb_operands, 
                               CString *బహిర్గతం_str, స్థిరరాశి అక్షరం *str)
{
    పూర్ణాంకం c, సూచీ, modifier;
    ASMOperand *op;
    SValue sv;

    కొరకు(;;) {
        c = *str++;
        ఒకవేళ (c == '%') {
            ఒకవేళ (*str == '%') {
                str++;
                వెళ్ళు కూడు_char;
            }
            modifier = 0;
            ఒకవేళ (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#నిర్వచితమైతే TCC_లక్ష్యం_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
		*str == 'z' ||
#అయితే_ముగింపు
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            సూచీ = కనుగొను_constraint(operands, nb_operands, str, &str);
            ఒకవేళ (సూచీ < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[సూచీ];
            ఒకవేళ (modifier == 'l') {
                cstr_cat(బహిర్గతం_str, get_tok_str(op->is_label, ఖాళీ), -1);
            } లేకపోతే {
		ఒకవేళ (op->vt == ఖాళీ)
		    వెళ్ళు error;
                sv = *op->vt;
                ఒకవేళ (op->reg >= 0) {
                    sv.r = op->reg;
                    ఒకవేళ (op->is_జ్ఞాపకం)
                      sv.r |= VT_LVAL;
                }
                subst_asm_నిర్వాహ్యం(బహిర్గతం_str, &sv, modifier);
            }
        } లేకపోతే {
        కూడు_char:
            cstr_ccat(బహిర్గతం_str, c);
            ఒకవేళ (c == '\0')
                ఆపు;
        }
    }
}


స్థిర శూన్య parse_asm_operands(ASMOperand *operands, పూర్ణాంకం *nb_operands_ptr,
                               పూర్ణాంకం is_output)
{
    ASMOperand *op;
    పూర్ణాంకం nb_operands;
    అక్షరం* astr;

    ఒకవేళ (tok != ':') {
        nb_operands = *nb_operands_ptr;
        కొరకు(;;) {
            ఒకవేళ (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            ఒకవేళ (tok == '[') {
                తదుపరి();
                ఒకవేళ (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                తదుపరి();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->దత్తాంశం;
            pstrcpy(op->constraint, పరిమాణం op->constraint, astr);
            skip('(');
            gexpr();
            ఒకవేళ (is_output) {
                ఒకవేళ (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } లేకపోతే {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                ఒకవేళ ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#నిర్వచితమైతే TCC_లక్ష్యం_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !అక్షరశ్రేణి_శోధన(op->constraint, "Ump")
#అయితే_ముగింపు
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            ఒకవేళ (tok == ',') {
                తదుపరి();
            } లేకపోతే {
                ఆపు;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC శూన్య asm_instr(శూన్య)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    పూర్ణాంకం nb_outputs, nb_operands, i, must_subst, బహిర్గతం_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    అయితే (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        తదుపరి();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->దత్తాంశం, astr1->కొలత);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, పరిమాణం(clobber_regs));
    ఒకవేళ (tok == ':') {
        తదుపరి();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        ఒకవేళ (tok == ':') {
            తదుపరి();
            ఒకవేళ (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                ఒకవేళ (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    తదుపరి();
                    కొరకు(;;) {
                        ఒకవేళ (tok == ':')
                          ఆపు;
                        ఒకవేళ (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.దత్తాంశం);
                        తదుపరి();
                        ఒకవేళ (tok == ',') {
                            తదుపరి();
                        } లేకపోతే {
                            ఆపు;
                        }
                    }
                }
                ఒకవేళ (tok == ':') {
                    /* goto labels */
                    తదుపరి();
                    కొరకు (;;) {
                        Sym *csym;
                        పూర్ణాంకం asmname;
                        ఒకవేళ (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        ఒకవేళ (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       పరిమాణం(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_కనుగొను(tok);
                        ఒకవేళ (!csym) {
                            csym = label_నెట్టు(&global_label_దొంతర, tok,
                                              LABEL_FORWARD);
                        } లేకపోతే {
                            ఒకవేళ (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        తదుపరి();
                        asmname = asm_get_ఉపసర్గ_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        ఒకవేళ (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        ఒకవేళ (tok != ',')
                          ఆపు;
                        తదుపరి();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ఒకవేళ (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &బహిర్గతం_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#నిర్వచితమైతే ASM_DEBUG
    రాయి("asm: \"%s\"\n", (అక్షరం *)astr.దత్తాంశం);
#అయితే_ముగింపు
    ఒకవేళ (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.దత్తాంశం, astr.కొలత);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->దత్తాంశం);
    }

#నిర్వచితమైతే ASM_DEBUG
    రాయి("subst_asm: \"%s\"\n", (అక్షరం *)astr.దత్తాంశం);
#అయితే_ముగింపు

    /* generate loads */
    asm_gen_సంకేతం(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, బహిర్గతం_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_పాఠ్యం_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.దత్తాంశం, astr.కొలత - 1, 0);
    cstr_free_s(&astr);
    ఒకవేళ (sec != cur_పాఠ్యం_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    తదుపరి();

    /* store the output values if needed */
    asm_gen_సంకేతం(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, బహిర్గతం_reg);
    
    /* free everything */
    కొరకు(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC శూన్య asm_global_instr(శూన్య)
{
    CString *astr;
    పూర్ణాంకం saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    తదుపరి();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    ఒకవేళ (tok != ';')
        expect("';'");
    
#నిర్వచితమైతే ASM_DEBUG
    రాయి("asm_global: \"%s\"\n", (అక్షరం *)astr->దత్తాంశం);
#అయితే_ముగింపు
    cur_పాఠ్యం_section = పాఠ్యం_section;
    ind = cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->దత్తాంశం, astr->కొలత - 1, 1);
    
    cur_పాఠ్యం_section->దత్తాంశం_స్థానభ్రంశం = ind;

    /* restore the current C token */
    తదుపరి();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#లేకపోతే
ST_FUNC పూర్ణాంకం tcc_assemble(TCCState *s1, పూర్ణాంకం do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC శూన్య asm_instr(శూన్య)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC శూన్య asm_global_instr(శూన్య)
{
    tcc_error("inline asm() not supported");
}
#అయితే_ముగింపు /* CONFIG_TCC_ASM */
