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

#परिभाषय USING_GLOBALS
#अन्तर्भाव "tcc.h"
#यदि_परिभाषितम् CONFIG_TCC_ASM

स्थिर Section *चरमः_text_section; /* to handle .previous asm directive */
स्थिर पूर्णाङ्क asmgoto_n;

स्थिर पूर्णाङ्क tcc_assemble_आन्तरिकम्(TCCState *s1, पूर्णाङ्क do_preprocess, पूर्णाङ्क global);
स्थिर Sym* asm_new_label(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local);
स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local, पूर्णाङ्क sh_अङ्कः, पूर्णाङ्क मानम्);

#यदि PTR_आकार == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC शून्य gen_addr64(पूर्णाङ्क r, Sym *sym, int64_t c)
{
    यदि (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_दत्त_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC शून्य gen_expr64(व्यञ्जकम्_मानम् *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#यदि_अन्तः

स्थिर पूर्णाङ्क asm_get_उपसर्गः_name(TCCState *s1, ध्रुव वर्ण *उपसर्गः, अचिह्नित पूर्णाङ्क n)
{
    वर्ण buf[64];
    snprintf(buf, परिमाण(buf), "%s%u", उपसर्गः, n);
    प्रत्यागम tok_alloc_const(buf);
}

ST_FUNC पूर्णाङ्क asm_get_local_label_name(TCCState *s1, अचिह्नित पूर्णाङ्क n)
{
    प्रत्यागम asm_get_उपसर्गः_name(s1, "L..", n);
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
    यदि (!tcc_state->leading_underscore)
      प्रत्यागम v;
    name = get_tok_str(v, रिक्त);
    यदि (!name)
      प्रत्यागम v;
    यदि (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } अन्यथा यदि (!strchr(name, '.')) {
        वर्ण newname[256];
        snprintf(newname, परिमाण newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    प्रत्यागम v;
}

स्थिर Sym *asm_label_find(पूर्णाङ्क v)
{
    Sym *sym;
    पूर्णाङ्क addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    यावत् (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->पूर्व_tok;
    प्रत्यागम sym;
}

स्थिर Sym *asm_label_प्रक्षिप(पूर्णाङ्क v)
{
    पूर्णाङ्क addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_प्रक्षिप(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    यदि (addeddot)
        sym->asm_label = v;
    प्रत्यागम sym;
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
    यदि (!sym) {
	sym = asm_label_प्रक्षिप(name);
	यदि (csym)
	  sym->c = csym->c;
    }
    प्रत्यागम sym;
}

स्थिर Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    वर्ण buf[100]; पूर्णाङ्क label; Sym *sym;
    snprintf(buf, परिमाण buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    प्रत्यागम sym ? sym : asm_new_label1(s1, label, 1, sec->sh_अङ्कः, 0);
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
        p = tokc.str.दत्त;
        n = strtoull(p, (वर्ण **)&p, 0);
        यदि (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            यदि (*p == 'b') {
                /* backward : find the last corresponding defined label */
                यदि (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->पूर्व_tok;
                यदि (!sym)
                    tcc_error("local label '%d' not found backward", (पूर्णाङ्क)n);
            } अन्यथा {
                /* forward */
                यदि (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_प्रक्षिप(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } अन्यथा यदि (*p == '\0') {
            pe->v = n;
            pe->sym = रिक्त;
	    pe->pcrel = 0;
        } अन्यथा {
            tcc_error("invalid number syntax");
        }
        अग्र();
        भङ्ग;
    पक्ष '+':
        अग्र();
        asm_व्यञ्जकम्_unary(s1, pe);
        भङ्ग;
    पक्ष '-':
    पक्ष '~':
        op = tok;
        अग्र();
        asm_व्यञ्जकम्_unary(s1, pe);
        यदि (pe->sym)
            tcc_error("invalid operation with label");
        यदि (op == '-')
            pe->v = -pe->v;
        अन्यथा
            pe->v = ~pe->v;
        भङ्ग;
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = रिक्त;
	pe->pcrel = 0;
	अग्र();
	भङ्ग;
    पक्ष '(':
        अग्र();
        asm_व्यञ्जकम्(s1, pe);
        skip(')');
        भङ्ग;
    पक्ष '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        अग्र();
        भङ्ग;
    स्वभाव:
        यदि (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, रिक्त);
	    esym = elfsym(sym);
            यदि (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_मानम्;
                pe->sym = रिक्त;
		pe->pcrel = 0;
            } अन्यथा {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            अग्र();
        } अन्यथा {
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
    प्रति(;;) {
        op = tok;
        यदि (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            भङ्ग;
        अग्र();
        asm_व्यञ्जकम्_unary(s1, &e2);
        यदि (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
        पक्ष '*':
            pe->v *= e2.v;
            भङ्ग;
        पक्ष '/':  
            यदि (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            भङ्ग;
        पक्ष '%':  
            यदि (e2.v == 0)
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
    प्रति(;;) {
        op = tok;
        यदि (op != '&' && op != '|' && op != '^')
            भङ्ग;
        अग्र();
        asm_व्यञ्जकम्_prod(s1, &e2);
        यदि (pe->sym || e2.sym)
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

स्थिर अन्तःस्थ शून्य asm_व्यञ्जकम्_योग(TCCState *s1, व्यञ्जकम्_मानम् *pe)
{
    पूर्णाङ्क op;
    व्यञ्जकम्_मानम् e2;

    asm_व्यञ्जकम्_logic(s1, pe);
    प्रति(;;) {
        op = tok;
        यदि (op != '+' && op != '-')
            भङ्ग;
        अग्र();
        asm_व्यञ्जकम्_logic(s1, &e2);
        यदि (op == '+') {
            यदि (pe->sym != रिक्त && e2.sym != रिक्त)
                गच्छ cannot_relocate;
            pe->v += e2.v;
            यदि (pe->sym == रिक्त && e2.sym != रिक्त)
                pe->sym = e2.sym;
        } अन्यथा {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    यदि (!e2.sym) {
		/* OK */
	    } अन्यथा यदि (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = रिक्त; /* same symbols can be subtracted to NULL */
	    } अन्यथा {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		यदि (!esym2)
		    गच्छ cannot_relocate;
		यदि (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (पूर्णाङ्क)(esym1->st_मानम् - esym2->st_मानम्);
		    pe->sym = रिक्त;
		} अन्यथा यदि (esym2->st_shndx == cur_text_section->sh_अङ्कः) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (पूर्णाङ्क)(0 - esym2->st_मानम्);
		    pe->pcrel = 1;
		    e2.sym = रिक्त;
		} अन्यथा {
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

    asm_व्यञ्जकम्_योग(s1, pe);
    प्रति(;;) {
        op = tok;
	यदि (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            भङ्ग;
        अग्र();
        asm_व्यञ्जकम्_योग(s1, &e2);
        यदि (pe->sym || e2.sym)
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
    यदि (e.sym)
        expect("constant");
    यदि ((पूर्णाङ्क)e.v != e.v)
	tcc_error("integer out of range %lld", (दीर्घ दीर्घ)e.v);
    प्रत्यागम e.v;
}

स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local,
                           पूर्णाङ्क sh_अङ्कः, पूर्णाङ्क मानम्)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    यदि (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        यदि (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            यदि (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                गच्छ new_label;
            यदि (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, रिक्त));
        }
    } अन्यथा {
    new_label:
        sym = asm_label_प्रक्षिप(label);
    }
    यदि (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_अङ्कः;
    esym->st_मानम् = मानम्;
    यदि (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    प्रत्यागम sym;
}

स्थिर Sym* asm_new_label(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local)
{
    प्रत्यागम asm_new_label1(s1, label, is_local, cur_text_section->sh_अङ्कः, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
स्थिर Sym* समुच्चयः_चिह्नम्(TCCState *s1, पूर्णाङ्क label)
{
    दीर्घ n;
    व्यञ्जकम्_मानम् e;
    Sym *sym;
    ElfSym *esym;
    अग्र();
    asm_व्यञ्जकम्(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    यदि (esym)
	n += esym->st_मानम्;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_समुच्चयः;
    प्रत्यागम sym;
}

स्थिर शून्य use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->दत्त_विस्थापनम् = ind;
    cur_text_section = sec;
    ind = cur_text_section->दत्त_विस्थापनम्;
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
    sec->पूर्व = cur_text_section;
    use_section1(s1, sec);
}

स्थिर शून्य निष्कासय_section(TCCState *s1)
{
    Section *पूर्व = cur_text_section->पूर्व;
    यदि (!पूर्व)
        tcc_error(".popsection without .pushsection");
    cur_text_section->पूर्व = रिक्त;
    use_section1(s1, पूर्व);
}

स्थिर शून्य asm_parse_directive(TCCState *s1, पूर्णाङ्क global)
{
    पूर्णाङ्क n, विस्थापनम्, v, आकार, tok1, c;
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
        अग्र();
        n = asm_int_व्यञ्जकम्(s1);
        यदि (tok1 == TOK_ASMDIR_p2align)
        {
            यदि (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        यदि (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            यदि (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            विस्थापनम् = (ind + n - 1) & -n;
            आकार = विस्थापनम् - ind;
            /* the section must have a compatible alignment */
            यदि (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } अन्यथा {
	    यदि (n < 0)
	        n = 0;
            आकार = n, c = 0;
        }
        v = 0;
        यदि (tok == ',') {
            अग्र();
            v = asm_int_व्यञ्जकम्(s1), c = 0;
        }
    zero_pad:
	यदि ((uint64_t)ind + आकार >= 1<<30)
	    tcc_error("too much data");
        यदि (sec->sh_type != SHT_NOBITS) {
            यदि (c) {
                gen_fill_nops(आकार);
                भङ्ग;
            }
            sec->दत्त_विस्थापनम् = ind;
            ptr = section_ptr_सङ्कलय(sec, आकार);
            स्मृतिं_पूरय(ptr, v, आकार);
        }
        ind += आकार;
        भङ्ग;
    पक्ष TOK_ASMDIR_quad:
#यदि PTR_आकार == 8
	आकार = 8;
	गच्छ asm_दत्त;
#अन्यथा
        अग्र();
        प्रति(;;) {
            uint64_t vl;
            ध्रुव वर्ण *p;

            p = tokc.str.दत्त;
            यदि (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (वर्ण **)&p, 0);
            यदि (*p != '\0')
                गच्छ error_constant;
            अग्र();
            यदि (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } अन्यथा {
                ind += 8;
            }
            यदि (tok != ',')
                भङ्ग;
            अग्र();
        }
        भङ्ग;
#यदि_अन्तः
    पक्ष TOK_ASMDIR_byte:
        आकार = 1;
        गच्छ asm_दत्त;
    पक्ष TOK_ASMDIR_word:
    पक्ष TOK_ASMDIR_short:
        आकार = 2;
        गच्छ asm_दत्त;
    पक्ष TOK_ASMDIR_long:
    पक्ष TOK_ASMDIR_int:
        आकार = 4;
    asm_दत्त:
        अग्र();
        प्रति(;;) {
            व्यञ्जकम्_मानम् e;
            asm_व्यञ्जकम्(s1, &e);
            यदि (sec->sh_type != SHT_NOBITS) {
                यदि (आकार == 4) {
                    gen_expr32(&e);
#यदि PTR_आकार == 8
		} अन्यथा यदि (आकार == 8) {
		    gen_expr64(&e);
#यदि_अन्तः
                } अन्यथा {
                    यदि (e.sym)
                        expect("constant");
                    यदि (आकार == 1)
                        g(e.v);
                    अन्यथा
                        gen_le16(e.v);
                }
            } अन्यथा {
                ind += आकार;
            }
            यदि (tok != ',')
                भङ्ग;
            अग्र();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_fill:
        {
            पूर्णाङ्क repeat, आकार, val, i, j;
            uint8_t repeat_buf[8];
            अग्र();
            repeat = asm_int_व्यञ्जकम्(s1);
            यदि (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                भङ्ग;
            }
            आकार = 1;
            val = 0;
            यदि (tok == ',') {
                अग्र();
                आकार = asm_int_व्यञ्जकम्(s1);
                यदि (आकार < 0) {
                    tcc_error("size < 0; .fill ignored");
                    भङ्ग;
                }
                यदि (आकार > 8)
                    आकार = 8;
                यदि (tok == ',') {
                    अग्र();
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
            प्रति(i = 0; i < repeat; i++) {
                प्रति(j = 0; j < आकार; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_rept:
        {
            पूर्णाङ्क repeat;
            TokenString *init_str;
            अग्र();
            repeat = asm_int_व्यञ्जकम्(s1);
            init_str = tok_str_alloc();
            यावत् (अग्र(), tok != TOK_ASMDIR_endr) {
                यदि (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_सङ्कलय_tok(init_str);
            }
            tok_str_सङ्कलय(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            यावत् (repeat-- > 0) {
                tcc_assemble_आन्तरिकम्(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            अन्तः_macro();
            अग्र();
            भङ्ग;
        }
    पक्ष TOK_ASMDIR_org:
        {
	    व्यञ्जकम्_मानम् e;
	    ElfSym *esym;
            अग्र();
	    asm_व्यञ्जकम्(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    यदि (esym) {
		यदि (esym->st_shndx != cur_text_section->sh_अङ्कः)
		  expect("constant or same-section symbol");
		n += esym->st_मानम्;
	    }
            यदि (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            आकार = n - ind;
            गच्छ zero_pad;
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_समुच्चयः:
	अग्र();
	tok1 = tok;
	अग्र();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	यदि (tok == ',')
	    समुच्चयः_चिह्नम्(s1, tok1);
	भङ्ग;
    पक्ष TOK_ASMDIR_globl:
    पक्ष TOK_ASMDIR_global:
    पक्ष TOK_ASMDIR_weak:
    पक्ष TOK_ASMDIR_hidden:
	tok1 = tok;
	कुरु { 
            Sym *sym;
            अग्र();
	    यदि (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
	    यदि (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            यदि (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    अन्यथा यदि (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            अग्र();
	} यावत् (tok == ',');
	भङ्ग;
    पक्ष TOK_ASMDIR_string:
    पक्ष TOK_ASMDIR_ascii:
    पक्ष TOK_ASMDIR_asciz:
        {
            ध्रुव वर्ण *p;
            पूर्णाङ्क i, आकार, t;

            t = tok;
            अग्र();
            प्रति(;;) {
                यदि (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.दत्त;
                आकार = tokc.str.आकार;
                यदि (t == TOK_ASMDIR_ascii && आकार > 0)
                    आकार--;
                प्रति(i = 0; i < आकार; i++)
                    g(p[i]);
                अग्र();
                यदि (tok == ',') {
                    अग्र();
                } अन्यथा यदि (tok != TOK_STR) {
                    भङ्ग;
                }
            }
	}
	भङ्ग;
    पक्ष TOK_ASMDIR_text:
    पक्ष TOK_ASMDIR_दत्त:
    पक्ष TOK_ASMDIR_bss:
	{ 
            वर्ण sname[64];
            tok1 = tok;
            n = 0;
            अग्र();
            यदि (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_व्यञ्जकम्(s1);
		अग्र();
            }
            यदि (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, रिक्त), n);
            अन्यथा
                sprintf(sname, "%s", get_tok_str(tok1, रिक्त));
            use_section(s1, sname);
	}
	भङ्ग;
    पक्ष TOK_ASMDIR_file:
        {
            ध्रुव वर्ण *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            अग्र();
            यदि (tok == TOK_PPNUM)
                अग्र();
            यदि (tok == TOK_PPSTR && tokc.str.दत्त[0] == '"') {
                tokc.str.दत्त[tokc.str.आकार - 2] = 0;
                p = tokc.str.दत्त + 1;
            } अन्यथा यदि (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } अन्यथा {
                skip_गन्तव्यम्_eol(0);
                भङ्ग;
            }
            tccpp_putfile(p);
            अग्र();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_ident:
        {
            वर्ण ident[256];

            ident[0] = '\0';
            अग्र();
            यदि (tok == TOK_STR)
                pstrcat(ident, परिमाण(ident), tokc.str.दत्त);
            अन्यथा
                pstrcat(ident, परिमाण(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            अग्र();
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_आकार:
        { 
            Sym *sym;
            ElfSym *esym;

            अग्र();
	    यदि (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            यदि (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, रिक्त));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, रिक्त));
            अग्र();
            skip(',');
            n = asm_int_व्यञ्जकम्(s1);
            esym = elfsym(sym);
            यदि (esym) {
                esym->st_आकार = n;
            }
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_type:
        { 
            Sym *sym;
            ध्रुव वर्ण *newtype;
            पूर्णाङ्क st_type;

            अग्र();
	    यदि (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
            अग्र();
            skip(',');
            यदि (tok == TOK_STR) {
                newtype = tokc.str.दत्त;
            } अन्यथा {
                यदि (tok == '@' || tok == '%')
                    अग्र();
                newtype = get_tok_str(tok, रिक्त);
            }

            यदि (!वाक्यं_तुलय(newtype, "function") || !वाक्यं_तुलय(newtype, "STT_FUNC")) {
                यदि (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            समुच्चयः_st_type:
                यदि (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } अन्यथा यदि (!वाक्यं_तुलय(newtype, "object") || !वाक्यं_तुलय(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                गच्छ समुच्चयः_st_type;
            } अन्यथा
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, रिक्त), sym->type.t, newtype);

            अग्र();
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
            अग्र();
            sname[0] = '\0';
            यावत् (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                यदि (tok == TOK_STR)
                    pstrcat(sname, परिमाण(sname), tokc.str.दत्त);
                अन्यथा
                    pstrcat(sname, परिमाण(sname), get_tok_str(tok, रिक्त));
                अग्र();
            }
            यदि (tok == ',') {
                ध्रुव वर्ण *p;
                /* skip section options */
                अग्र();
                यदि (tok != TOK_STR)
                    expect("string constant");
                प्रति (p = tokc.str.दत्त; *p; ++p) {
                    यदि (*p == 'w')
                        flags |= SHF_WRITE;
                    यदि (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                अग्र();
                यदि (tok == ',') {
                    अग्र();
                    यदि (tok == '@' || tok == '%')
                        अग्र();
                    अग्र();
                }
            }
            चरमः_text_section = cur_text_section;
	    यदि (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    अन्यथा
	        प्रक्षिप_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    यदि (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                यदि (!वाक्यं_तुलय(sname, ".init") || !वाक्यं_तुलय(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_previous:
        { 
            Section *sec;
            अग्र();
            यदि (!चरमः_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, चरमः_text_section);
            चरमः_text_section = sec;
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_popsection:
	अग्र();
	निष्कासय_section(s1);
	भङ्ग;
#यदि_परिभाषितम् TCC_TARGET_I386
    पक्ष TOK_ASMDIR_code16:
        {
            अग्र();
            s1->seg_आकार = 16;
        }
        भङ्ग;
    पक्ष TOK_ASMDIR_code32:
        {
            अग्र();
            s1->seg_आकार = 32;
        }
        भङ्ग;
#यदि_अन्तः
#यदि PTR_आकार == 8
    /* added for compatibility with GAS */
    पक्ष TOK_ASMDIR_code64:
        अग्र();
        भङ्ग;
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_RISCV64
    पक्ष TOK_ASMDIR_option:
        अग्र();
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
                अग्र();
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
#यदि_अन्तः
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    पक्ष TOK_ASMDIR_symver:
	अग्र();
	अग्र();
        skip(',');
	अग्र();
        skip('@');
	अग्र();
	भङ्ग;
    पक्ष TOK_ASMDIR_reloc:
	{
	    व्यञ्जकम्_मानम् e;
	    ध्रुव वर्ण *reloc_name;
	    पूर्णाङ्क reloc_type = -1;

	    अग्र();
	    asm_व्यञ्जकम्(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, रिक्त);
#यदि defined(TCC_TARGET_ARM64)
	    यदि (!वाक्यं_तुलय(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#नोचेद्यदि defined(TCC_TARGET_RISCV64)
	    यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_CALL") || !वाक्यं_तुलय(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    अन्यथा यदि (!वाक्यं_तुलय(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#यदि_अन्तः
	    यदि (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    अग्र();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, रिक्त), e.v, reloc_type, 0);
	    अग्र();
	}
	भङ्ग;
    स्वभाव:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, रिक्त));
        भङ्ग;
    }
}


/* assemble a file */
स्थिर पूर्णाङ्क tcc_assemble_आन्तरिकम्(TCCState *s1, पूर्णाङ्क do_preprocess, पूर्णाङ्क global)
{
    पूर्णाङ्क opcode;
    पूर्णाङ्क saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    यदि (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    प्रति(;;) {
        अग्र();
        यदि (tok == TOK_EOF)
            भङ्ग;
        tcc_debug_पङ्क्तिः(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#यदि !defined(TCC_TARGET_ARM64)
        यदि (tok == '#') {
            /* horrible gas comment */
            यावत् (tok != TOK_LINEFEED)
                अग्र();
        } अन्यथा
#यदि_अन्तः
        यदि (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_चरमः) {
            asm_parse_directive(s1, global);
        } अन्यथा यदि (tok == TOK_PPNUM) {
            ध्रुव वर्ण *p;
            पूर्णाङ्क n;
            p = tokc.str.दत्त;
            n = strtoul(p, (वर्ण **)&p, 10);
            यदि (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            अग्र();
            skip(':');
            गच्छ redo;
        } अन्यथा यदि (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            अग्र();
            यदि (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                अग्र();
                गच्छ redo;
            } अन्यथा यदि (tok == '=') {
		समुच्चयः_चिह्नम्(s1, opcode);
                गच्छ redo;
            } अन्यथा {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        यदि (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    प्रत्यागम 0;
}

/* Assemble the current file */
ST_FUNC पूर्णाङ्क tcc_assemble(TCCState *s1, पूर्णाङ्क do_preprocess)
{
    पूर्णाङ्क ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->दत्त_विस्थापनम्;
    nocode_wanted = 0;
    ret = tcc_assemble_आन्तरिकम्(s1, do_preprocess, 1);
    cur_text_section->दत्त_विस्थापनम् = ind;
    tcc_debug_अन्तः(s1);
    प्रत्यागम ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
स्थिर शून्य tcc_assemble_inline(TCCState *s1, ध्रुव वर्ण *str, पूर्णाङ्क len, पूर्णाङ्क global)
{
    ध्रुव पूर्णाङ्क *saved_macro_ptr = macro_ptr;
    पूर्णाङ्क dotid = समुच्चयः_idnum('.', IS_ID);
#यदि !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    पूर्णाङ्क dolid = समुच्चयः_idnum('$', 0);
#यदि_अन्तः

    tcc_open_bf(s1, ":asm:", len);
    स्मृतिं_प्रतिलिख(file->बफर, str, len);
    macro_ptr = रिक्त;
    tcc_assemble_आन्तरिकम्(s1, 0, global);
    tcc_close();

#यदि !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    समुच्चयः_idnum('$', dolid);
#यदि_अन्तः
    समुच्चयः_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC पूर्णाङ्क find_constraint(ASMOperand *operands, पूर्णाङ्क nb_operands, 
                           ध्रुव वर्ण *name, ध्रुव वर्ण **pp)
{
    पूर्णाङ्क सूचकांक;
    TokenSym *ts;
    ध्रुव वर्ण *p;

    यदि (isnum(*name)) {
        सूचकांक = 0;
        यावत् (isnum(*name)) {
            सूचकांक = (सूचकांक * 10) + (*name) - '0';
            name++;
        }
        यदि ((अचिह्नित)सूचकांक >= nb_operands)
            सूचकांक = -1;
    } अन्यथा यदि (*name == '[') {
        name++;
        p = strchr(name, ']');
        यदि (p) {
            ts = tok_alloc(name, p - name);
            प्रति(सूचकांक = 0; सूचकांक < nb_operands; सूचकांक++) {
                यदि (operands[सूचकांक].id == ts->tok)
                    गच्छ प्राप्तम्;
            }
            सूचकांक = -1;
        प्राप्तम्:
            name = p + 1;
        } अन्यथा {
            सूचकांक = -1;
        }
    } अन्यथा {
        सूचकांक = -1;
    }
    यदि (pp)
        *pp = name;
    प्रत्यागम सूचकांक;
}

स्थिर शून्य subst_asm_operands(ASMOperand *operands, पूर्णाङ्क nb_operands, 
                               CString *बहिर्गमनम्_str, ध्रुव वर्ण *str)
{
    पूर्णाङ्क c, सूचकांक, modifier;
    ASMOperand *op;
    SValue sv;

    प्रति(;;) {
        c = *str++;
        यदि (c == '%') {
            यदि (*str == '%') {
                str++;
                गच्छ सङ्कलय_char;
            }
            modifier = 0;
            यदि (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#यदि_परिभाषितम् TCC_TARGET_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_RISCV64
		*str == 'z' ||
#यदि_अन्तः
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            सूचकांक = find_constraint(operands, nb_operands, str, &str);
            यदि (सूचकांक < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[सूचकांक];
            यदि (modifier == 'l') {
                cstr_cat(बहिर्गमनम्_str, get_tok_str(op->is_label, रिक्त), -1);
            } अन्यथा {
		यदि (op->vt == रिक्त)
		    गच्छ error;
                sv = *op->vt;
                यदि (op->reg >= 0) {
                    sv.r = op->reg;
                    यदि (op->is_स्मृतिः)
                      sv.r |= VT_LVAL;
                }
                subst_asm_सङ्कार्यम्(बहिर्गमनम्_str, &sv, modifier);
            }
        } अन्यथा {
        सङ्कलय_char:
            cstr_ccat(बहिर्गमनम्_str, c);
            यदि (c == '\0')
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

    यदि (tok != ':') {
        nb_operands = *nb_operands_ptr;
        प्रति(;;) {
            यदि (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            यदि (tok == '[') {
                अग्र();
                यदि (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                अग्र();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->दत्त;
            pstrcpy(op->constraint, परिमाण op->constraint, astr);
            skip('(');
            gexpr();
            यदि (is_output) {
                यदि (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } अन्यथा {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                यदि ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#यदि_परिभाषितम् TCC_TARGET_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !वाक्ये_अन्विष(op->constraint, "Ump")
#यदि_अन्तः
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            यदि (tok == ',') {
                अग्र();
            } अन्यथा {
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
    पूर्णाङ्क nb_outputs, nb_operands, i, must_subst, बहिर्गमनम्_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    यावत् (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        अग्र();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->दत्त, astr1->आकार);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    स्मृतिं_पूरय(clobber_regs, 0, परिमाण(clobber_regs));
    यदि (tok == ':') {
        अग्र();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        यदि (tok == ':') {
            अग्र();
            यदि (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                यदि (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    अग्र();
                    प्रति(;;) {
                        यदि (tok == ':')
                          भङ्ग;
                        यदि (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.दत्त);
                        अग्र();
                        यदि (tok == ',') {
                            अग्र();
                        } अन्यथा {
                            भङ्ग;
                        }
                    }
                }
                यदि (tok == ':') {
                    /* goto labels */
                    अग्र();
                    प्रति (;;) {
                        Sym *csym;
                        पूर्णाङ्क asmname;
                        यदि (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        यदि (tok < TOK_UIDENT)
                          expect("label identifier");
			स्मृतिं_पूरय(operands + nb_operands + nb_labels, 0,
			       परिमाण(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        यदि (!csym) {
                            csym = label_प्रक्षिप(&global_label_राशिः, tok,
                                              LABEL_FORWARD);
                        } अन्यथा {
                            यदि (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        अग्र();
                        asmname = asm_get_उपसर्गः_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        यदि (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        यदि (tok != ',')
                          भङ्ग;
                        अग्र();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    यदि (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &बहिर्गमनम्_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#यदि_परिभाषितम् ASM_DEBUG
    प्रारूप_लिख("asm: \"%s\"\n", (वर्ण *)astr.दत्त);
#यदि_अन्तः
    यदि (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.दत्त, astr.आकार);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->दत्त);
    }

#यदि_परिभाषितम् ASM_DEBUG
    प्रारूप_लिख("subst_asm: \"%s\"\n", (वर्ण *)astr.दत्त);
#यदि_अन्तः

    /* generate loads */
    asm_gen_संहिता(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, बहिर्गमनम्_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_text_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.दत्त, astr.आकार - 1, 0);
    cstr_free_s(&astr);
    यदि (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    अग्र();

    /* store the output values if needed */
    asm_gen_संहिता(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, बहिर्गमनम्_reg);
    
    /* free everything */
    प्रति(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC शून्य asm_global_instr(शून्य)
{
    CString *astr;
    पूर्णाङ्क saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    अग्र();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    यदि (tok != ';')
        expect("';'");
    
#यदि_परिभाषितम् ASM_DEBUG
    प्रारूप_लिख("asm_global: \"%s\"\n", (वर्ण *)astr->दत्त);
#यदि_अन्तः
    cur_text_section = text_section;
    ind = cur_text_section->दत्त_विस्थापनम्;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->दत्त, astr->आकार - 1, 1);
    
    cur_text_section->दत्त_विस्थापनम् = ind;

    /* restore the current C token */
    अग्र();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#अन्यथा
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
#यदि_अन्तः /* CONFIG_TCC_ASM */
