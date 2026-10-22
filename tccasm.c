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
#अन्तर्भाव "tcc.h"
#ifdef CONFIG_TCC_ASM

स्थिर Section *last_text_section; /* to handle .previous asm directive */
स्थिर पूर्णाङ्क asmgoto_n;

स्थिर पूर्णाङ्क tcc_assemble_internal(TCCState *s1, पूर्णाङ्क do_preprocess, पूर्णाङ्क global);
स्थिर Sym* asm_new_label(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local);
स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local, पूर्णाङ्क sh_अङ्कः, पूर्णाङ्क मानम्);

#सचे PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC शून्य gen_addr64(पूर्णाङ्क r, Sym *sym, int64_t c)
{
    सचे (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC शून्य gen_expr64(व्यञ्जकम्_मानम् *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

स्थिर पूर्णाङ्क asm_get_prefix_name(TCCState *s1, ध्रुव वर्ण *prefix, unsigned पूर्णाङ्क n)
{
    वर्ण buf[64];
    snprintf(buf, परिमाण(buf), "%s%u", prefix, n);
    पटिनिवत्त tok_alloc_const(buf);
}

ST_FUNC पूर्णाङ्क asm_get_local_label_name(TCCState *s1, unsigned पूर्णाङ्क n)
{
    पटिनिवत्त asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
स्थिर पूर्णाङ्क asm2cname(पूर्णाङ्क v, पूर्णाङ्क *addeddot)
{
    ध्रुव वर्ण *name;
    *addeddot = 0;
    सचे (!tcc_state->leading_underscore)
      पटिनिवत्त v;
    name = get_tok_str(v, रिक्त);
    सचे (!name)
      पटिनिवत्त v;
    सचे (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } अञ्ञथा सचे (!strchr(name, '.')) {
        वर्ण newname[256];
        snprintf(newname, परिमाण newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    पटिनिवत्त v;
}

स्थिर Sym *asm_label_find(पूर्णाङ्क v)
{
    Sym *sym;
    पूर्णाङ्क addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    याव (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    पटिनिवत्त sym;
}

स्थिर Sym *asm_label_प्रक्षिप(पूर्णाङ्क v)
{
    पूर्णाङ्क addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_प्रक्षिप(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    सचे (addeddot)
        sym->asm_label = v;
    पटिनिवत्त sym;
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
ST_FUNC Sym* get_asm_sym(पूर्णाङ्क name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    सचे (!sym) {
	sym = asm_label_प्रक्षिप(name);
	सचे (csym)
	  sym->c = csym->c;
    }
    पटिनिवत्त sym;
}

स्थिर Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    वर्ण buf[100]; पूर्णाङ्क label; Sym *sym;
    snprintf(buf, परिमाण buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    पटिनिवत्त sym ? sym : asm_new_label1(s1, label, 1, sec->sh_अङ्कः, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

स्थिर शून्य asm_व्यञ्जकम्_unary(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    Sym *sym;
    पूर्णाङ्क op, label;
    uint64_t n;
    ध्रुव वर्ण *p;

    विकल्प(tok) {
    पक्ष TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (वर्ण **)&p, 0);
        सचे (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            सचे (*p == 'b') {
                /* backward : find the last corresponding defined label */
                सचे (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                सचे (!sym)
                    tcc_error("local label '%d' not found backward", (पूर्णाङ्क)n);
            } अञ्ञथा {
                /* forward */
                सचे (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_प्रक्षिप(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } अञ्ञथा सचे (*p == '\0') {
            pe->v = n;
            pe->sym = रिक्त;
	    pe->pcrel = 0;
        } अञ्ञथा {
            tcc_error("invalid number syntax");
        }
        next();
        भङ्ग;
    पक्ष '+':
        next();
        asm_व्यञ्जकम्_unary(s1, pe);
        भङ्ग;
    पक्ष '-':
    पक्ष '~':
        op = tok;
        next();
        asm_व्यञ्जकम्_unary(s1, pe);
        सचे (pe->sym)
            tcc_error("invalid operation with label");
        सचे (op == '-')
            pe->v = -pe->v;
        अञ्ञथा
            pe->v = ~pe->v;
        भङ्ग;
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = रिक्त;
	pe->pcrel = 0;
	next();
	भङ्ग;
    पक्ष '(':
        next();
        asm_व्यञ्जकम्(s1, pe);
        skip(')');
        भङ्ग;
    पक्ष '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        भङ्ग;
    स्वभाव:
        सचे (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, रिक्त);
	    esym = elfsym(sym);
            सचे (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_मानम्;
                pe->sym = रिक्त;
		pe->pcrel = 0;
            } अञ्ञथा {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } अञ्ञथा {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        भङ्ग;
    }
}
    
स्थिर शून्य asm_व्यञ्जकम्_prod(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    पूर्णाङ्क op;
    व्यञ्जकम्_मानम् e2;

    asm_व्यञ्जकम्_unary(s1, pe);
    अत्थाय(;;) {
        op = tok;
        सचे (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            भङ्ग;
        next();
        asm_व्यञ्जकम्_unary(s1, &e2);
        सचे (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
        पक्ष '*':
            pe->v *= e2.v;
            भङ्ग;
        पक्ष '/':  
            सचे (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            भङ्ग;
        पक्ष '%':  
            सचे (e2.v == 0)
                गच्छ div_error;
            pe->v %= e2.v;
            भङ्ग;
        पक्ष TOK_SHL:
            pe->v <<= e2.v;
            भङ्ग;
        स्वभाव:
        पक्ष TOK_SAR:
            pe->v >>= e2.v;
            भङ्ग;
        }
    }
}

स्थिर शून्य asm_व्यञ्जकम्_logic(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    पूर्णाङ्क op;
    व्यञ्जकम्_मानम् e2;

    asm_व्यञ्जकम्_prod(s1, pe);
    अत्थाय(;;) {
        op = tok;
        सचे (op != '&' && op != '|' && op != '^')
            भङ्ग;
        next();
        asm_व्यञ्जकम्_prod(s1, &e2);
        सचे (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
        पक्ष '&':
            pe->v &= e2.v;
            भङ्ग;
        पक्ष '|':  
            pe->v |= e2.v;
            भङ्ग;
        स्वभाव:
        पक्ष '^':
            pe->v ^= e2.v;
            भङ्ग;
        }
    }
}

स्थिर अन्तःस्थ शून्य asm_व्यञ्जकम्_sum(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    पूर्णाङ्क op;
    व्यञ्जकम्_मानम् e2;

    asm_व्यञ्जकम्_logic(s1, pe);
    अत्थाय(;;) {
        op = tok;
        सचे (op != '+' && op != '-')
            भङ्ग;
        next();
        asm_व्यञ्जकम्_logic(s1, &e2);
        सचे (op == '+') {
            सचे (pe->sym != रिक्त && e2.sym != रिक्त)
                गच्छ cannot_relocate;
            pe->v += e2.v;
            सचे (pe->sym == रिक्त && e2.sym != रिक्त)
                pe->sym = e2.sym;
        } अञ्ञथा {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    सचे (!e2.sym) {
		/* OK */
	    } अञ्ञथा सचे (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = रिक्त; /* same symbols can be subtracted to NULL */
	    } अञ्ञथा {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		सचे (!esym2)
		    गच्छ cannot_relocate;
		सचे (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (पूर्णाङ्क)(esym1->st_मानम् - esym2->st_मानम्);
		    pe->sym = रिक्त;
		} अञ्ञथा सचे (esym2->st_shndx == cur_text_section->sh_अङ्कः) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (पूर्णाङ्क)(0 - esym2->st_मानम्);
		    pe->pcrel = 1;
		    e2.sym = रिक्त;
		} अञ्ञथा {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

स्थिर अन्तःस्थ शून्य asm_व्यञ्जकम्_cmp(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    पूर्णाङ्क op;
    व्यञ्जकम्_मानम् e2;

    asm_व्यञ्जकम्_sum(s1, pe);
    अत्थाय(;;) {
        op = tok;
	सचे (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            भङ्ग;
        next();
        asm_व्यञ्जकम्_sum(s1, &e2);
        सचे (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
	पक्ष TOK_EQ:
	    pe->v = pe->v == e2.v;
	    भङ्ग;
	पक्ष TOK_NE:
	    pe->v = pe->v != e2.v;
	    भङ्ग;
	पक्ष TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    भङ्ग;
	पक्ष TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    भङ्ग;
	पक्ष TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    भङ्ग;
	पक्ष TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    भङ्ग;
        स्वभाव:
            भङ्ग;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC शून्य asm_व्यञ्जकम्(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    asm_व्यञ्जकम्_cmp(s1, pe);
}

ST_FUNC पूर्णाङ्क asm_int_व्यञ्जकम्(TCCState *s1)
{
    व्यञ्जकम्_मानम् e;
    asm_व्यञ्जकम्(s1, &e);
    सचे (e.sym)
        expect("constant");
    सचे ((पूर्णाङ्क)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    पटिनिवत्त e.v;
}

स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local,
                           पूर्णाङ्क sh_अङ्कः, पूर्णाङ्क मानम्)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    सचे (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        सचे (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            सचे (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                गच्छ new_label;
            सचे (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, रिक्त));
        }
    } अञ्ञथा {
    new_label:
        sym = asm_label_प्रक्षिप(label);
    }
    सचे (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_अङ्कः;
    esym->st_मानम् = मानम्;
    सचे (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    पटिनिवत्त sym;
}

स्थिर Sym* asm_new_label(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local)
{
    पटिनिवत्त asm_new_label1(s1, label, is_local, cur_text_section->sh_अङ्कः, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
स्थिर Sym* set_चिह्नम्(TCCState *s1, पूर्णाङ्क label)
{
    long n;
    व्यञ्जकम्_मानम् e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_व्यञ्जकम्(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    सचे (esym)
	n += esym->st_मानम्;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    पटिनिवत्त sym;
}

स्थिर शून्य use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

स्थिर शून्य use_section(TCCState *s1, ध्रुव वर्ण *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

स्थिर शून्य प्रक्षिप_section(TCCState *s1, ध्रुव वर्ण *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

स्थिर शून्य निष्कासय_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    सचे (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = रिक्त;
    use_section1(s1, prev);
}

स्थिर शून्य asm_parse_directive(TCCState *s1, पूर्णाङ्क global)
{
    पूर्णाङ्क n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    विकल्प(tok) {
    पक्ष TOK_ASMDIR_align:
    पक्ष TOK_ASMDIR_balign:
    पक्ष TOK_ASMDIR_p2align:
    पक्ष TOK_ASMDIR_skip:
    पक्ष TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_व्यञ्जकम्(s1);
        सचे (tok1 == TOK_ASMDIR_p2align)
        {
            सचे (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        सचे (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            सचे (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            सचे (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } अञ्ञथा {
	    सचे (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        सचे (tok == ',') {
            next();
            v = asm_int_व्यञ्जकम्(s1), c = 0;
        }
    zero_pad:
	सचे ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        सचे (sec->sh_type != SHT_NOBITS) {
            सचे (c) {
                gen_fill_nops(size);
                भङ्ग;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        भङ्ग;
    पक्ष TOK_ASMDIR_quad:
#सचे PTR_SIZE == 8
	size = 8;
	गच्छ asm_data;
#अञ्ञथा
        next();
        अत्थाय(;;) {
            uint64_t vl;
            ध्रुव वर्ण *p;

            p = tokc.str.data;
            सचे (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (वर्ण **)&p, 0);
            सचे (*p != '\0')
                गच्छ error_constant;
            next();
            सचे (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } अञ्ञथा {
                ind += 8;
            }
            सचे (tok != ',')
                भङ्ग;
            next();
        }
        भङ्ग;
#endif
    पक्ष TOK_ASMDIR_byte:
        size = 1;
        गच्छ asm_data;
    पक्ष TOK_ASMDIR_word:
    पक्ष TOK_ASMDIR_short:
        size = 2;
        गच्छ asm_data;
    पक्ष TOK_ASMDIR_long:
    पक्ष TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        अत्थाय(;;) {
            व्यञ्जकम्_मानम् e;
            asm_व्यञ्जकम्(s1, &e);
            सचे (sec->sh_type != SHT_NOBITS) {
                सचे (size == 4) {
                    gen_expr32(&e);
#सचे PTR_SIZE == 8
		} अञ्ञथा सचे (size == 8) {
		    gen_expr64(&e);
#endif
                } अञ्ञथा {
                    सचे (e.sym)
                        expect("constant");
                    सचे (size == 1)
                        g(e.v);
                    अञ्ञथा
                        gen_le16(e.v);
                }
            } अञ्ञथा {
                ind += size;
            }
            सचे (tok != ',')
                भङ्ग;
            next();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_fill:
        {
            पूर्णाङ्क repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_व्यञ्जकम्(s1);
            सचे (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                भङ्ग;
            }
            size = 1;
            val = 0;
            सचे (tok == ',') {
                next();
                size = asm_int_व्यञ्जकम्(s1);
                सचे (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    भङ्ग;
                }
                सचे (size > 8)
                    size = 8;
                सचे (tok == ',') {
                    next();
                    val = asm_int_व्यञ्जकम्(s1);
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
            अत्थाय(i = 0; i < repeat; i++) {
                अत्थाय(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_rept:
        {
            पूर्णाङ्क repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_व्यञ्जकम्(s1);
            init_str = tok_str_alloc();
            याव (next(), tok != TOK_ASMDIR_endr) {
                सचे (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            याव (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            भङ्ग;
        }
    पक्ष TOK_ASMDIR_org:
        {
	    व्यञ्जकम्_मानम् e;
	    ElfSym *esym;
            next();
	    asm_व्यञ्जकम्(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    सचे (esym) {
		सचे (esym->st_shndx != cur_text_section->sh_अङ्कः)
		  expect("constant or same-section symbol");
		n += esym->st_मानम्;
	    }
            सचे (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            गच्छ zero_pad;
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	सचे (tok == ',')
	    set_चिह्नम्(s1, tok1);
	भङ्ग;
    पक्ष TOK_ASMDIR_globl:
    पक्ष TOK_ASMDIR_global:
    पक्ष TOK_ASMDIR_weak:
    पक्ष TOK_ASMDIR_hidden:
	tok1 = tok;
	करोहि { 
            Sym *sym;
            next();
	    सचे (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
	    सचे (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            सचे (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    अञ्ञथा सचे (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} याव (tok == ',');
	भङ्ग;
    पक्ष TOK_ASMDIR_string:
    पक्ष TOK_ASMDIR_ascii:
    पक्ष TOK_ASMDIR_asciz:
        {
            ध्रुव वर्ण *p;
            पूर्णाङ्क i, size, t;

            t = tok;
            next();
            अत्थाय(;;) {
                सचे (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                सचे (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                अत्थाय(i = 0; i < size; i++)
                    g(p[i]);
                next();
                सचे (tok == ',') {
                    next();
                } अञ्ञथा सचे (tok != TOK_STR) {
                    भङ्ग;
                }
            }
	}
	भङ्ग;
    पक्ष TOK_ASMDIR_text:
    पक्ष TOK_ASMDIR_data:
    पक्ष TOK_ASMDIR_bss:
	{ 
            वर्ण sname[64];
            tok1 = tok;
            n = 0;
            next();
            सचे (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_व्यञ्जकम्(s1);
		next();
            }
            सचे (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, रिक्त), n);
            अञ्ञथा
                sprintf(sname, "%s", get_tok_str(tok1, रिक्त));
            use_section(s1, sname);
	}
	भङ्ग;
    पक्ष TOK_ASMDIR_file:
        {
            ध्रुव वर्ण *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            सचे (tok == TOK_PPNUM)
                next();
            सचे (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } अञ्ञथा सचे (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } अञ्ञथा {
                skip_to_eol(0);
                भङ्ग;
            }
            tccpp_putfile(p);
            next();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_ident:
        {
            वर्ण ident[256];

            ident[0] = '\0';
            next();
            सचे (tok == TOK_STR)
                pstrcat(ident, परिमाण(ident), tokc.str.data);
            अञ्ञथा
                pstrcat(ident, परिमाण(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    सचे (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            सचे (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, रिक्त));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, रिक्त));
            next();
            skip(',');
            n = asm_int_व्यञ्जकम्(s1);
            esym = elfsym(sym);
            सचे (esym) {
                esym->st_size = n;
            }
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_type:
        { 
            Sym *sym;
            ध्रुव वर्ण *newtype;
            पूर्णाङ्क st_type;

            next();
	    सचे (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
            next();
            skip(',');
            सचे (tok == TOK_STR) {
                newtype = tokc.str.data;
            } अञ्ञथा {
                सचे (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, रिक्त);
            }

            सचे (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                सचे (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                सचे (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } अञ्ञथा सचे (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                गच्छ set_st_type;
            } अञ्ञथा
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, रिक्त), sym->type.t, newtype);

            next();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_pushsection:
    पक्ष TOK_ASMDIR_section:
        {
            वर्ण sname[256];
	    पूर्णाङ्क old_nb_section = s1->nb_sections;
            पूर्णाङ्क flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            याव (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                सचे (tok == TOK_STR)
                    pstrcat(sname, परिमाण(sname), tokc.str.data);
                अञ्ञथा
                    pstrcat(sname, परिमाण(sname), get_tok_str(tok, रिक्त));
                next();
            }
            सचे (tok == ',') {
                ध्रुव वर्ण *p;
                /* skip section options */
                next();
                सचे (tok != TOK_STR)
                    expect("string constant");
                अत्थाय (p = tokc.str.data; *p; ++p) {
                    सचे (*p == 'w')
                        flags |= SHF_WRITE;
                    सचे (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                सचे (tok == ',') {
                    next();
                    सचे (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    सचे (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    अञ्ञथा
	        प्रक्षिप_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    सचे (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                सचे (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            सचे (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_popsection:
	next();
	निष्कासय_section(s1);
	भङ्ग;
#ifdef TCC_TARGET_I386
    पक्ष TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        भङ्ग;
#endif
#सचे PTR_SIZE == 8
    /* added for compatibility with GAS */
    पक्ष TOK_ASMDIR_code64:
        next();
        भङ्ग;
#endif
#ifdef TCC_TARGET_RISCV64
    पक्ष TOK_ASMDIR_option:
        next();
        विकल्प(tok){
            पक्ष TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            पक्ष TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            पक्ष TOK_ASM_pic:
            पक्ष TOK_ASM_nopic:
            पक्ष TOK_ASM_relax:
            पक्ष TOK_ASM_norelax:
            पक्ष TOK_ASM_प्रक्षिप:
            पक्ष TOK_ASM_निष्कासय:
                /* TODO: unimplemented */
                next();
                भङ्ग;
            पक्ष TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, रिक्त));
                भङ्ग;
            स्वभाव:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, रिक्त));
                भङ्ग;
        }
        भङ्ग;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    पक्ष TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	भङ्ग;
    पक्ष TOK_ASMDIR_reloc:
	{
	    व्यञ्जकम्_मानम् e;
	    ध्रुव वर्ण *reloc_name;
	    पूर्णाङ्क reloc_type = -1;

	    next();
	    asm_व्यञ्जकम्(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, रिक्त);
#सचे defined(TCC_TARGET_ARM64)
	    सचे (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#नोचेद्यदि defined(TCC_TARGET_RISCV64)
	    सचे (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    अञ्ञथा सचे (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    सचे (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, रिक्त), e.v, reloc_type, 0);
	    next();
	}
	भङ्ग;
    स्वभाव:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, रिक्त));
        भङ्ग;
    }
}


/* assemble a file */
स्थिर पूर्णाङ्क tcc_assemble_internal(TCCState *s1, पूर्णाङ्क do_preprocess, पूर्णाङ्क global)
{
    पूर्णाङ्क opcode;
    पूर्णाङ्क saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    सचे (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    अत्थाय(;;) {
        next();
        सचे (tok == TOK_EOF)
            भङ्ग;
        tcc_debug_पङ्क्तिः(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#सचे !defined(TCC_TARGET_ARM64)
        सचे (tok == '#') {
            /* horrible gas comment */
            याव (tok != TOK_LINEFEED)
                next();
        } अञ्ञथा
#endif
        सचे (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } अञ्ञथा सचे (tok == TOK_PPNUM) {
            ध्रुव वर्ण *p;
            पूर्णाङ्क n;
            p = tokc.str.data;
            n = strtoul(p, (वर्ण **)&p, 10);
            सचे (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            गच्छ redo;
        } अञ्ञथा सचे (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            सचे (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                गच्छ redo;
            } अञ्ञथा सचे (tok == '=') {
		set_चिह्नम्(s1, opcode);
                गच्छ redo;
            } अञ्ञथा {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        सचे (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    पटिनिवत्त 0;
}

/* Assemble the current file */
ST_FUNC पूर्णाङ्क tcc_assemble(TCCState *s1, पूर्णाङ्क do_preprocess)
{
    पूर्णाङ्क ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    पटिनिवत्त ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
स्थिर शून्य tcc_assemble_inline(TCCState *s1, ध्रुव वर्ण *str, पूर्णाङ्क len, पूर्णाङ्क global)
{
    ध्रुव पूर्णाङ्क *saved_macro_ptr = macro_ptr;
    पूर्णाङ्क dotid = set_idnum('.', IS_ID);
#सचे !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    पूर्णाङ्क dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = रिक्त;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#सचे !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC पूर्णाङ्क find_constraint(ASMOperand *operands, पूर्णाङ्क nb_operands, 
                           ध्रुव वर्ण *name, ध्रुव वर्ण **pp)
{
    पूर्णाङ्क index;
    TokenSym *ts;
    ध्रुव वर्ण *p;

    सचे (isnum(*name)) {
        index = 0;
        याव (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        सचे ((unsigned)index >= nb_operands)
            index = -1;
    } अञ्ञथा सचे (*name == '[') {
        name++;
        p = strchr(name, ']');
        सचे (p) {
            ts = tok_alloc(name, p - name);
            अत्थाय(index = 0; index < nb_operands; index++) {
                सचे (operands[index].id == ts->tok)
                    गच्छ found;
            }
            index = -1;
        found:
            name = p + 1;
        } अञ्ञथा {
            index = -1;
        }
    } अञ्ञथा {
        index = -1;
    }
    सचे (pp)
        *pp = name;
    पटिनिवत्त index;
}

स्थिर शून्य subst_asm_operands(ASMOperand *operands, पूर्णाङ्क nb_operands, 
                               CString *out_str, ध्रुव वर्ण *str)
{
    पूर्णाङ्क c, index, modifier;
    ASMOperand *op;
    SValue sv;

    अत्थाय(;;) {
        c = *str++;
        सचे (c == '%') {
            सचे (*str == '%') {
                str++;
                गच्छ add_char;
            }
            modifier = 0;
            सचे (*str == 'c' || *str == 'n' ||
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
            सचे (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            सचे (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, रिक्त), -1);
            } अञ्ञथा {
		सचे (op->vt == रिक्त)
		    गच्छ error;
                sv = *op->vt;
                सचे (op->reg >= 0) {
                    sv.r = op->reg;
                    सचे (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } अञ्ञथा {
        add_char:
            cstr_ccat(out_str, c);
            सचे (c == '\0')
                भङ्ग;
        }
    }
}


स्थिर शून्य parse_asm_operands(ASMOperand *operands, पूर्णाङ्क *nb_operands_ptr,
                               पूर्णाङ्क is_output)
{
    ASMOperand *op;
    पूर्णाङ्क nb_operands;
    वर्ण* astr;

    सचे (tok != ':') {
        nb_operands = *nb_operands_ptr;
        अत्थाय(;;) {
            सचे (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            सचे (tok == '[') {
                next();
                सचे (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, परिमाण op->constraint, astr);
            skip('(');
            gexpr();
            सचे (is_output) {
                सचे (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } अञ्ञथा {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                सचे ((vtop->r & VT_LVAL) &&
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
            सचे (tok == ',') {
                next();
            } अञ्ञथा {
                भङ्ग;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC शून्य asm_instr(शून्य)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    पूर्णाङ्क nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    याव (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, परिमाण(clobber_regs));
    सचे (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        सचे (tok == ':') {
            next();
            सचे (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                सचे (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    अत्थाय(;;) {
                        सचे (tok == ':')
                          भङ्ग;
                        सचे (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        सचे (tok == ',') {
                            next();
                        } अञ्ञथा {
                            भङ्ग;
                        }
                    }
                }
                सचे (tok == ':') {
                    /* goto labels */
                    next();
                    अत्थाय (;;) {
                        Sym *csym;
                        पूर्णाङ्क asmname;
                        सचे (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        सचे (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       परिमाण(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        सचे (!csym) {
                            csym = label_प्रक्षिप(&global_label_राशिः, tok,
                                              LABEL_FORWARD);
                        } अञ्ञथा {
                            सचे (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        सचे (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        सचे (tok != ',')
                          भङ्ग;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    सचे (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (वर्ण *)astr.data);
#endif
    सचे (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (वर्ण *)astr.data);
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
    सचे (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    अत्थाय(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC शून्य asm_global_instr(शून्य)
{
    CString *astr;
    पूर्णाङ्क saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    सचे (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (वर्ण *)astr->data);
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
#अञ्ञथा
ST_FUNC पूर्णाङ्क tcc_assemble(TCCState *s1, पूर्णाङ्क do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC शून्य asm_instr(शून्य)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC शून्य asm_global_instr(शून्य)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
