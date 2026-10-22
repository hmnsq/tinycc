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

#घोषणा USING_GLOBALS
#समावेश "tcc.h"
#अगर_घोषित CONFIG_TCC_ASM

अटल Section *last_text_section; /* to handle .previous asm directive */
अटल पूर्णांक asmgoto_n;

अटल पूर्णांक tcc_assemble_internal(TCCState *s1, पूर्णांक do_preprocess, पूर्णांक global);
अटल Sym* asm_new_label(TCCState *s1, पूर्णांक label, पूर्णांक is_local);
अटल Sym* asm_new_label1(TCCState *s1, पूर्णांक label, पूर्णांक is_local, पूर्णांक sh_अंक, पूर्णांक मूल्य);

#अगर PTR_आकार == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC व्योम gen_addr64(पूर्णांक r, Sym *sym, int64_t c)
{
    अगर (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_तथ्य_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC व्योम gen_expr64(व्यंजक_मूल्य *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#पूर्ण_अगर

अटल पूर्णांक asm_get_prefix_name(TCCState *s1, स्थिर अक्षर *prefix, अचिन्हित पूर्णांक n)
{
    अक्षर buf[64];
    snprintf(buf, माप(buf), "%s%u", prefix, n);
    वापस tok_alloc_const(buf);
}

ST_FUNC पूर्णांक asm_get_local_label_name(TCCState *s1, अचिन्हित पूर्णांक n)
{
    वापस asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
अटल पूर्णांक asm2cname(पूर्णांक v, पूर्णांक *addeddot)
{
    स्थिर अक्षर *name;
    *addeddot = 0;
    अगर (!tcc_state->leading_underscore)
      वापस v;
    name = get_tok_str(v, शून्य);
    अगर (!name)
      वापस v;
    अगर (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } अन्यथा अगर (!म_अक्षर(name, '.')) {
        अक्षर newname[256];
        snprintf(newname, माप newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    वापस v;
}

अटल Sym *asm_label_find(पूर्णांक v)
{
    Sym *sym;
    पूर्णांक addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    जबतक (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->पूर्व_tok;
    वापस sym;
}

अटल Sym *asm_label_धकेलो(पूर्णांक v)
{
    पूर्णांक addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_धकेलो(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    अगर (addeddot)
        sym->asm_label = v;
    वापस sym;
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
ST_FUNC Sym* get_asm_sym(पूर्णांक name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    अगर (!sym) {
	sym = asm_label_धकेलो(name);
	अगर (csym)
	  sym->c = csym->c;
    }
    वापस sym;
}

अटल Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    अक्षर buf[100]; पूर्णांक label; Sym *sym;
    snprintf(buf, माप buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    वापस sym ? sym : asm_new_label1(s1, label, 1, sec->sh_अंक, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

अटल व्योम asm_व्यंजक_unary(TCCState *s1, व्यंजक_मूल्य *pe)
{
    Sym *sym;
    पूर्णांक op, label;
    uint64_t n;
    स्थिर अक्षर *p;

    चयन(tok) {
    हाल TOK_PPNUM:
        p = tokc.str.तथ्य;
        n = strtoull(p, (अक्षर **)&p, 0);
        अगर (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            अगर (*p == 'b') {
                /* backward : find the last corresponding defined label */
                अगर (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->पूर्व_tok;
                अगर (!sym)
                    tcc_error("local label '%d' not found backward", (पूर्णांक)n);
            } अन्यथा {
                /* forward */
                अगर (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_धकेलो(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } अन्यथा अगर (*p == '\0') {
            pe->v = n;
            pe->sym = शून्य;
	    pe->pcrel = 0;
        } अन्यथा {
            tcc_error("invalid number syntax");
        }
        अग्र();
        अवरोध;
    हाल '+':
        अग्र();
        asm_व्यंजक_unary(s1, pe);
        अवरोध;
    हाल '-':
    हाल '~':
        op = tok;
        अग्र();
        asm_व्यंजक_unary(s1, pe);
        अगर (pe->sym)
            tcc_error("invalid operation with label");
        अगर (op == '-')
            pe->v = -pe->v;
        अन्यथा
            pe->v = ~pe->v;
        अवरोध;
    हाल TOK_CCHAR:
    हाल TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = शून्य;
	pe->pcrel = 0;
	अग्र();
	अवरोध;
    हाल '(':
        अग्र();
        asm_व्यंजक(s1, pe);
        skip(')');
        अवरोध;
    हाल '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        अग्र();
        अवरोध;
    शेष:
        अगर (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, शून्य);
	    esym = elfsym(sym);
            अगर (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_मूल्य;
                pe->sym = शून्य;
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
        अवरोध;
    }
}
    
अटल व्योम asm_व्यंजक_prod(TCCState *s1, व्यंजक_मूल्य *pe)
{
    पूर्णांक op;
    व्यंजक_मूल्य e2;

    asm_व्यंजक_unary(s1, pe);
    क्रम(;;) {
        op = tok;
        अगर (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            अवरोध;
        अग्र();
        asm_व्यंजक_unary(s1, &e2);
        अगर (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        चयन(op) {
        हाल '*':
            pe->v *= e2.v;
            अवरोध;
        हाल '/':  
            अगर (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            अवरोध;
        हाल '%':  
            अगर (e2.v == 0)
                जाओ div_error;
            pe->v %= e2.v;
            अवरोध;
        हाल TOK_SHL:
            pe->v <<= e2.v;
            अवरोध;
        शेष:
        हाल TOK_SAR:
            pe->v >>= e2.v;
            अवरोध;
        }
    }
}

अटल व्योम asm_व्यंजक_logic(TCCState *s1, व्यंजक_मूल्य *pe)
{
    पूर्णांक op;
    व्यंजक_मूल्य e2;

    asm_व्यंजक_prod(s1, pe);
    क्रम(;;) {
        op = tok;
        अगर (op != '&' && op != '|' && op != '^')
            अवरोध;
        अग्र();
        asm_व्यंजक_prod(s1, &e2);
        अगर (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        चयन(op) {
        हाल '&':
            pe->v &= e2.v;
            अवरोध;
        हाल '|':  
            pe->v |= e2.v;
            अवरोध;
        शेष:
        हाल '^':
            pe->v ^= e2.v;
            अवरोध;
        }
    }
}

अटल अंतरभूत व्योम asm_व्यंजक_योग(TCCState *s1, व्यंजक_मूल्य *pe)
{
    पूर्णांक op;
    व्यंजक_मूल्य e2;

    asm_व्यंजक_logic(s1, pe);
    क्रम(;;) {
        op = tok;
        अगर (op != '+' && op != '-')
            अवरोध;
        अग्र();
        asm_व्यंजक_logic(s1, &e2);
        अगर (op == '+') {
            अगर (pe->sym != शून्य && e2.sym != शून्य)
                जाओ cannot_relocate;
            pe->v += e2.v;
            अगर (pe->sym == शून्य && e2.sym != शून्य)
                pe->sym = e2.sym;
        } अन्यथा {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    अगर (!e2.sym) {
		/* OK */
	    } अन्यथा अगर (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = शून्य; /* same symbols can be subtracted to NULL */
	    } अन्यथा {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		अगर (!esym2)
		    जाओ cannot_relocate;
		अगर (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (पूर्णांक)(esym1->st_मूल्य - esym2->st_मूल्य);
		    pe->sym = शून्य;
		} अन्यथा अगर (esym2->st_shndx == cur_text_section->sh_अंक) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (पूर्णांक)(0 - esym2->st_मूल्य);
		    pe->pcrel = 1;
		    e2.sym = शून्य;
		} अन्यथा {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

अटल अंतरभूत व्योम asm_व्यंजक_cmp(TCCState *s1, व्यंजक_मूल्य *pe)
{
    पूर्णांक op;
    व्यंजक_मूल्य e2;

    asm_व्यंजक_योग(s1, pe);
    क्रम(;;) {
        op = tok;
	अगर (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            अवरोध;
        अग्र();
        asm_व्यंजक_योग(s1, &e2);
        अगर (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        चयन(op) {
	हाल TOK_EQ:
	    pe->v = pe->v == e2.v;
	    अवरोध;
	हाल TOK_NE:
	    pe->v = pe->v != e2.v;
	    अवरोध;
	हाल TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    अवरोध;
	हाल TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    अवरोध;
	हाल TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    अवरोध;
	हाल TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    अवरोध;
        शेष:
            अवरोध;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC व्योम asm_व्यंजक(TCCState *s1, व्यंजक_मूल्य *pe)
{
    asm_व्यंजक_cmp(s1, pe);
}

ST_FUNC पूर्णांक asm_int_व्यंजक(TCCState *s1)
{
    व्यंजक_मूल्य e;
    asm_व्यंजक(s1, &e);
    अगर (e.sym)
        expect("constant");
    अगर ((पूर्णांक)e.v != e.v)
	tcc_error("integer out of range %lld", (दीर्घ दीर्घ)e.v);
    वापस e.v;
}

अटल Sym* asm_new_label1(TCCState *s1, पूर्णांक label, पूर्णांक is_local,
                           पूर्णांक sh_अंक, पूर्णांक मूल्य)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    अगर (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        अगर (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            अगर (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                जाओ new_label;
            अगर (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, शून्य));
        }
    } अन्यथा {
    new_label:
        sym = asm_label_धकेलो(label);
    }
    अगर (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_अंक;
    esym->st_मूल्य = मूल्य;
    अगर (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    वापस sym;
}

अटल Sym* asm_new_label(TCCState *s1, पूर्णांक label, पूर्णांक is_local)
{
    वापस asm_new_label1(s1, label, is_local, cur_text_section->sh_अंक, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
अटल Sym* set_प्रतीक(TCCState *s1, पूर्णांक label)
{
    दीर्घ n;
    व्यंजक_मूल्य e;
    Sym *sym;
    ElfSym *esym;
    अग्र();
    asm_व्यंजक(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    अगर (esym)
	n += esym->st_मूल्य;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    वापस sym;
}

अटल व्योम use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->तथ्य_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->तथ्य_offset;
}

अटल व्योम use_section(TCCState *s1, स्थिर अक्षर *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

अटल व्योम धकेलो_section(TCCState *s1, स्थिर अक्षर *name)
{
    Section *sec = find_section(s1, name);
    sec->पूर्व = cur_text_section;
    use_section1(s1, sec);
}

अटल व्योम निकालो_section(TCCState *s1)
{
    Section *पूर्व = cur_text_section->पूर्व;
    अगर (!पूर्व)
        tcc_error(".popsection without .pushsection");
    cur_text_section->पूर्व = शून्य;
    use_section1(s1, पूर्व);
}

अटल व्योम asm_parse_directive(TCCState *s1, पूर्णांक global)
{
    पूर्णांक n, offset, v, आकार, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    चयन(tok) {
    हाल TOK_ASMDIR_align:
    हाल TOK_ASMDIR_balign:
    हाल TOK_ASMDIR_p2align:
    हाल TOK_ASMDIR_skip:
    हाल TOK_ASMDIR_space:
        tok1 = tok;
        अग्र();
        n = asm_int_व्यंजक(s1);
        अगर (tok1 == TOK_ASMDIR_p2align)
        {
            अगर (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        अगर (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            अगर (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            आकार = offset - ind;
            /* the section must have a compatible alignment */
            अगर (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } अन्यथा {
	    अगर (n < 0)
	        n = 0;
            आकार = n, c = 0;
        }
        v = 0;
        अगर (tok == ',') {
            अग्र();
            v = asm_int_व्यंजक(s1), c = 0;
        }
    zero_pad:
	अगर ((uint64_t)ind + आकार >= 1<<30)
	    tcc_error("too much data");
        अगर (sec->sh_type != SHT_NOBITS) {
            अगर (c) {
                gen_fill_nops(आकार);
                अवरोध;
            }
            sec->तथ्य_offset = ind;
            ptr = section_ptr_add(sec, आकार);
            स_रखो(ptr, v, आकार);
        }
        ind += आकार;
        अवरोध;
    हाल TOK_ASMDIR_quad:
#अगर PTR_आकार == 8
	आकार = 8;
	जाओ asm_तथ्य;
#अन्यथा
        अग्र();
        क्रम(;;) {
            uint64_t vl;
            स्थिर अक्षर *p;

            p = tokc.str.तथ्य;
            अगर (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (अक्षर **)&p, 0);
            अगर (*p != '\0')
                जाओ error_constant;
            अग्र();
            अगर (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } अन्यथा {
                ind += 8;
            }
            अगर (tok != ',')
                अवरोध;
            अग्र();
        }
        अवरोध;
#पूर्ण_अगर
    हाल TOK_ASMDIR_byte:
        आकार = 1;
        जाओ asm_तथ्य;
    हाल TOK_ASMDIR_word:
    हाल TOK_ASMDIR_short:
        आकार = 2;
        जाओ asm_तथ्य;
    हाल TOK_ASMDIR_long:
    हाल TOK_ASMDIR_int:
        आकार = 4;
    asm_तथ्य:
        अग्र();
        क्रम(;;) {
            व्यंजक_मूल्य e;
            asm_व्यंजक(s1, &e);
            अगर (sec->sh_type != SHT_NOBITS) {
                अगर (आकार == 4) {
                    gen_expr32(&e);
#अगर PTR_आकार == 8
		} अन्यथा अगर (आकार == 8) {
		    gen_expr64(&e);
#पूर्ण_अगर
                } अन्यथा {
                    अगर (e.sym)
                        expect("constant");
                    अगर (आकार == 1)
                        g(e.v);
                    अन्यथा
                        gen_le16(e.v);
                }
            } अन्यथा {
                ind += आकार;
            }
            अगर (tok != ',')
                अवरोध;
            अग्र();
        }
        अवरोध;
    हाल TOK_ASMDIR_fill:
        {
            पूर्णांक repeat, आकार, val, i, j;
            uint8_t repeat_buf[8];
            अग्र();
            repeat = asm_int_व्यंजक(s1);
            अगर (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                अवरोध;
            }
            आकार = 1;
            val = 0;
            अगर (tok == ',') {
                अग्र();
                आकार = asm_int_व्यंजक(s1);
                अगर (आकार < 0) {
                    tcc_error("size < 0; .fill ignored");
                    अवरोध;
                }
                अगर (आकार > 8)
                    आकार = 8;
                अगर (tok == ',') {
                    अग्र();
                    val = asm_int_व्यंजक(s1);
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
            क्रम(i = 0; i < repeat; i++) {
                क्रम(j = 0; j < आकार; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        अवरोध;
    हाल TOK_ASMDIR_rept:
        {
            पूर्णांक repeat;
            TokenString *init_str;
            अग्र();
            repeat = asm_int_व्यंजक(s1);
            init_str = tok_str_alloc();
            जबतक (अग्र(), tok != TOK_ASMDIR_endr) {
                अगर (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            जबतक (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            अग्र();
            अवरोध;
        }
    हाल TOK_ASMDIR_org:
        {
	    व्यंजक_मूल्य e;
	    ElfSym *esym;
            अग्र();
	    asm_व्यंजक(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    अगर (esym) {
		अगर (esym->st_shndx != cur_text_section->sh_अंक)
		  expect("constant or same-section symbol");
		n += esym->st_मूल्य;
	    }
            अगर (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            आकार = n - ind;
            जाओ zero_pad;
        }
        अवरोध;
    हाल TOK_ASMDIR_set:
	अग्र();
	tok1 = tok;
	अग्र();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	अगर (tok == ',')
	    set_प्रतीक(s1, tok1);
	अवरोध;
    हाल TOK_ASMDIR_globl:
    हाल TOK_ASMDIR_global:
    हाल TOK_ASMDIR_weak:
    हाल TOK_ASMDIR_hidden:
	tok1 = tok;
	करो { 
            Sym *sym;
            अग्र();
	    अगर (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, शून्य);
	    अगर (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            अगर (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    अन्यथा अगर (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            अग्र();
	} जबतक (tok == ',');
	अवरोध;
    हाल TOK_ASMDIR_string:
    हाल TOK_ASMDIR_ascii:
    हाल TOK_ASMDIR_asciz:
        {
            स्थिर अक्षर *p;
            पूर्णांक i, आकार, t;

            t = tok;
            अग्र();
            क्रम(;;) {
                अगर (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.तथ्य;
                आकार = tokc.str.आकार;
                अगर (t == TOK_ASMDIR_ascii && आकार > 0)
                    आकार--;
                क्रम(i = 0; i < आकार; i++)
                    g(p[i]);
                अग्र();
                अगर (tok == ',') {
                    अग्र();
                } अन्यथा अगर (tok != TOK_STR) {
                    अवरोध;
                }
            }
	}
	अवरोध;
    हाल TOK_ASMDIR_text:
    हाल TOK_ASMDIR_तथ्य:
    हाल TOK_ASMDIR_bss:
	{ 
            अक्षर sname[64];
            tok1 = tok;
            n = 0;
            अग्र();
            अगर (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_व्यंजक(s1);
		अग्र();
            }
            अगर (n)
                प्र_लिखो(sname, "%s%d", get_tok_str(tok1, शून्य), n);
            अन्यथा
                प्र_लिखो(sname, "%s", get_tok_str(tok1, शून्य));
            use_section(s1, sname);
	}
	अवरोध;
    हाल TOK_ASMDIR_file:
        {
            स्थिर अक्षर *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            अग्र();
            अगर (tok == TOK_PPNUM)
                अग्र();
            अगर (tok == TOK_PPSTR && tokc.str.तथ्य[0] == '"') {
                tokc.str.तथ्य[tokc.str.आकार - 2] = 0;
                p = tokc.str.तथ्य + 1;
            } अन्यथा अगर (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } अन्यथा {
                skip_to_eol(0);
                अवरोध;
            }
            tccpp_putfile(p);
            अग्र();
        }
        अवरोध;
    हाल TOK_ASMDIR_ident:
        {
            अक्षर ident[256];

            ident[0] = '\0';
            अग्र();
            अगर (tok == TOK_STR)
                pstrcat(ident, माप(ident), tokc.str.तथ्य);
            अन्यथा
                pstrcat(ident, माप(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            अग्र();
        }
        अवरोध;
    हाल TOK_ASMDIR_आकार:
        { 
            Sym *sym;
            ElfSym *esym;

            अग्र();
	    अगर (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            अगर (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, शून्य));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, शून्य));
            अग्र();
            skip(',');
            n = asm_int_व्यंजक(s1);
            esym = elfsym(sym);
            अगर (esym) {
                esym->st_आकार = n;
            }
        }
        अवरोध;
    हाल TOK_ASMDIR_type:
        { 
            Sym *sym;
            स्थिर अक्षर *newtype;
            पूर्णांक st_type;

            अग्र();
	    अगर (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, शून्य);
            अग्र();
            skip(',');
            अगर (tok == TOK_STR) {
                newtype = tokc.str.तथ्य;
            } अन्यथा {
                अगर (tok == '@' || tok == '%')
                    अग्र();
                newtype = get_tok_str(tok, शून्य);
            }

            अगर (!म_भेद(newtype, "function") || !म_भेद(newtype, "STT_FUNC")) {
                अगर (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                अगर (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } अन्यथा अगर (!म_भेद(newtype, "object") || !म_भेद(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                जाओ set_st_type;
            } अन्यथा
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, शून्य), sym->type.t, newtype);

            अग्र();
        }
        अवरोध;
    हाल TOK_ASMDIR_pushsection:
    हाल TOK_ASMDIR_section:
        {
            अक्षर sname[256];
	    पूर्णांक old_nb_section = s1->nb_sections;
            पूर्णांक flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            अग्र();
            sname[0] = '\0';
            जबतक (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                अगर (tok == TOK_STR)
                    pstrcat(sname, माप(sname), tokc.str.तथ्य);
                अन्यथा
                    pstrcat(sname, माप(sname), get_tok_str(tok, शून्य));
                अग्र();
            }
            अगर (tok == ',') {
                स्थिर अक्षर *p;
                /* skip section options */
                अग्र();
                अगर (tok != TOK_STR)
                    expect("string constant");
                क्रम (p = tokc.str.तथ्य; *p; ++p) {
                    अगर (*p == 'w')
                        flags |= SHF_WRITE;
                    अगर (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                अग्र();
                अगर (tok == ',') {
                    अग्र();
                    अगर (tok == '@' || tok == '%')
                        अग्र();
                    अग्र();
                }
            }
            last_text_section = cur_text_section;
	    अगर (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    अन्यथा
	        धकेलो_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    अगर (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                अगर (!म_भेद(sname, ".init") || !म_भेद(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        अवरोध;
    हाल TOK_ASMDIR_previous:
        { 
            Section *sec;
            अग्र();
            अगर (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        अवरोध;
    हाल TOK_ASMDIR_popsection:
	अग्र();
	निकालो_section(s1);
	अवरोध;
#अगर_घोषित TCC_TARGET_I386
    हाल TOK_ASMDIR_code16:
        {
            अग्र();
            s1->seg_आकार = 16;
        }
        अवरोध;
    हाल TOK_ASMDIR_code32:
        {
            अग्र();
            s1->seg_आकार = 32;
        }
        अवरोध;
#पूर्ण_अगर
#अगर PTR_आकार == 8
    /* added for compatibility with GAS */
    हाल TOK_ASMDIR_code64:
        अग्र();
        अवरोध;
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_RISCV64
    हाल TOK_ASMDIR_option:
        अग्र();
        चयन(tok){
            हाल TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            हाल TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            हाल TOK_ASM_pic:
            हाल TOK_ASM_nopic:
            हाल TOK_ASM_relax:
            हाल TOK_ASM_norelax:
            हाल TOK_ASM_धकेलो:
            हाल TOK_ASM_निकालो:
                /* TODO: unimplemented */
                अग्र();
                अवरोध;
            हाल TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, शून्य));
                अवरोध;
            शेष:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, शून्य));
                अवरोध;
        }
        अवरोध;
#पूर्ण_अगर
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    हाल TOK_ASMDIR_symver:
	अग्र();
	अग्र();
        skip(',');
	अग्र();
        skip('@');
	अग्र();
	अवरोध;
    हाल TOK_ASMDIR_reloc:
	{
	    व्यंजक_मूल्य e;
	    स्थिर अक्षर *reloc_name;
	    पूर्णांक reloc_type = -1;

	    अग्र();
	    asm_व्यंजक(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, शून्य);
#अगर defined(TCC_TARGET_ARM64)
	    अगर (!म_भेद(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#या_अगर defined(TCC_TARGET_RISCV64)
	    अगर (!म_भेद(reloc_name, "R_RISCV_CALL") || !म_भेद(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    अन्यथा अगर (!म_भेद(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#पूर्ण_अगर
	    अगर (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    अग्र();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, शून्य), e.v, reloc_type, 0);
	    अग्र();
	}
	अवरोध;
    शेष:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, शून्य));
        अवरोध;
    }
}


/* assemble a file */
अटल पूर्णांक tcc_assemble_internal(TCCState *s1, पूर्णांक do_preprocess, पूर्णांक global)
{
    पूर्णांक opcode;
    पूर्णांक saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    अगर (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    क्रम(;;) {
        अग्र();
        अगर (tok == TOK_EOF)
            अवरोध;
        tcc_debug_पंक्ति(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#अगर !defined(TCC_TARGET_ARM64)
        अगर (tok == '#') {
            /* horrible gas comment */
            जबतक (tok != TOK_LINEFEED)
                अग्र();
        } अन्यथा
#पूर्ण_अगर
        अगर (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } अन्यथा अगर (tok == TOK_PPNUM) {
            स्थिर अक्षर *p;
            पूर्णांक n;
            p = tokc.str.तथ्य;
            n = म_से_अदीर्घ(p, (अक्षर **)&p, 10);
            अगर (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            अग्र();
            skip(':');
            जाओ redo;
        } अन्यथा अगर (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            अग्र();
            अगर (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                अग्र();
                जाओ redo;
            } अन्यथा अगर (tok == '=') {
		set_प्रतीक(s1, opcode);
                जाओ redo;
            } अन्यथा {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        अगर (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    वापस 0;
}

/* Assemble the current file */
ST_FUNC पूर्णांक tcc_assemble(TCCState *s1, पूर्णांक do_preprocess)
{
    पूर्णांक ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->तथ्य_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->तथ्य_offset = ind;
    tcc_debug_end(s1);
    वापस ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
अटल व्योम tcc_assemble_inline(TCCState *s1, स्थिर अक्षर *str, पूर्णांक len, पूर्णांक global)
{
    स्थिर पूर्णांक *saved_macro_ptr = macro_ptr;
    पूर्णांक dotid = set_idnum('.', IS_ID);
#अगर !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    पूर्णांक dolid = set_idnum('$', 0);
#पूर्ण_अगर

    tcc_open_bf(s1, ":asm:", len);
    स_नकल(file->बफर, str, len);
    macro_ptr = शून्य;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#अगर !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#पूर्ण_अगर
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC पूर्णांक find_constraint(ASMOperand *operands, पूर्णांक nb_operands, 
                           स्थिर अक्षर *name, स्थिर अक्षर **pp)
{
    पूर्णांक सूचकांक;
    TokenSym *ts;
    स्थिर अक्षर *p;

    अगर (isnum(*name)) {
        सूचकांक = 0;
        जबतक (isnum(*name)) {
            सूचकांक = (सूचकांक * 10) + (*name) - '0';
            name++;
        }
        अगर ((अचिन्हित)सूचकांक >= nb_operands)
            सूचकांक = -1;
    } अन्यथा अगर (*name == '[') {
        name++;
        p = म_अक्षर(name, ']');
        अगर (p) {
            ts = tok_alloc(name, p - name);
            क्रम(सूचकांक = 0; सूचकांक < nb_operands; सूचकांक++) {
                अगर (operands[सूचकांक].id == ts->tok)
                    जाओ found;
            }
            सूचकांक = -1;
        found:
            name = p + 1;
        } अन्यथा {
            सूचकांक = -1;
        }
    } अन्यथा {
        सूचकांक = -1;
    }
    अगर (pp)
        *pp = name;
    वापस सूचकांक;
}

अटल व्योम subst_asm_operands(ASMOperand *operands, पूर्णांक nb_operands, 
                               CString *out_str, स्थिर अक्षर *str)
{
    पूर्णांक c, सूचकांक, modifier;
    ASMOperand *op;
    SValue sv;

    क्रम(;;) {
        c = *str++;
        अगर (c == '%') {
            अगर (*str == '%') {
                str++;
                जाओ add_char;
            }
            modifier = 0;
            अगर (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#अगर_घोषित TCC_TARGET_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_RISCV64
		*str == 'z' ||
#पूर्ण_अगर
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            सूचकांक = find_constraint(operands, nb_operands, str, &str);
            अगर (सूचकांक < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[सूचकांक];
            अगर (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, शून्य), -1);
            } अन्यथा {
		अगर (op->vt == शून्य)
		    जाओ error;
                sv = *op->vt;
                अगर (op->reg >= 0) {
                    sv.r = op->reg;
                    अगर (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } अन्यथा {
        add_char:
            cstr_ccat(out_str, c);
            अगर (c == '\0')
                अवरोध;
        }
    }
}


अटल व्योम parse_asm_operands(ASMOperand *operands, पूर्णांक *nb_operands_ptr,
                               पूर्णांक is_output)
{
    ASMOperand *op;
    पूर्णांक nb_operands;
    अक्षर* astr;

    अगर (tok != ':') {
        nb_operands = *nb_operands_ptr;
        क्रम(;;) {
            अगर (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            अगर (tok == '[') {
                अग्र();
                अगर (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                अग्र();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->तथ्य;
            pstrcpy(op->constraint, माप op->constraint, astr);
            skip('(');
            gexpr();
            अगर (is_output) {
                अगर (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } अन्यथा {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                अगर ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !म_अक्षर(op->constraint, 'm')
#अगर_घोषित TCC_TARGET_ARM64
                    && !म_अक्षर(op->constraint, 'Q')
                    && !म_माला(op->constraint, "Ump")
#पूर्ण_अगर
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            अगर (tok == ',') {
                अग्र();
            } अन्यथा {
                अवरोध;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC व्योम asm_instr(व्योम)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    पूर्णांक nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    जबतक (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        अग्र();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->तथ्य, astr1->आकार);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    स_रखो(clobber_regs, 0, माप(clobber_regs));
    अगर (tok == ':') {
        अग्र();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        अगर (tok == ':') {
            अग्र();
            अगर (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                अगर (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    अग्र();
                    क्रम(;;) {
                        अगर (tok == ':')
                          अवरोध;
                        अगर (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.तथ्य);
                        अग्र();
                        अगर (tok == ',') {
                            अग्र();
                        } अन्यथा {
                            अवरोध;
                        }
                    }
                }
                अगर (tok == ':') {
                    /* goto labels */
                    अग्र();
                    क्रम (;;) {
                        Sym *csym;
                        पूर्णांक asmname;
                        अगर (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        अगर (tok < TOK_UIDENT)
                          expect("label identifier");
			स_रखो(operands + nb_operands + nb_labels, 0,
			       माप(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        अगर (!csym) {
                            csym = label_धकेलो(&global_label_ढेर, tok,
                                              LABEL_FORWARD);
                        } अन्यथा {
                            अगर (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        अग्र();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        अगर (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        अगर (tok != ',')
                          अवरोध;
                        अग्र();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    अगर (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#अगर_घोषित ASM_DEBUG
    म_लिखो("asm: \"%s\"\n", (अक्षर *)astr.तथ्य);
#पूर्ण_अगर
    अगर (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.तथ्य, astr.आकार);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->तथ्य);
    }

#अगर_घोषित ASM_DEBUG
    म_लिखो("subst_asm: \"%s\"\n", (अक्षर *)astr.तथ्य);
#पूर्ण_अगर

    /* generate loads */
    asm_gen_code(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, out_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_text_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.तथ्य, astr.आकार - 1, 0);
    cstr_free_s(&astr);
    अगर (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    अग्र();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    क्रम(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC व्योम asm_global_instr(व्योम)
{
    CString *astr;
    पूर्णांक saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    अग्र();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    अगर (tok != ';')
        expect("';'");
    
#अगर_घोषित ASM_DEBUG
    म_लिखो("asm_global: \"%s\"\n", (अक्षर *)astr->तथ्य);
#पूर्ण_अगर
    cur_text_section = text_section;
    ind = cur_text_section->तथ्य_offset;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->तथ्य, astr->आकार - 1, 1);
    
    cur_text_section->तथ्य_offset = ind;

    /* restore the current C token */
    अग्र();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#अन्यथा
ST_FUNC पूर्णांक tcc_assemble(TCCState *s1, पूर्णांक do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC व्योम asm_instr(व्योम)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC व्योम asm_global_instr(व्योम)
{
    tcc_error("inline asm() not supported");
}
#पूर्ण_अगर /* CONFIG_TCC_ASM */
