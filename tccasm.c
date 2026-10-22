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
स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local, पूर्णाङ्क sh_अङ्क, पूर्णाङ्क मान);

#यदि PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC शून्य gen_addr64(पूर्णाङ्क r, Sym *sym, int64_t c)
{
    यदि (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC शून्य gen_expr64(अभिव्यक्ति_मान *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

स्थिर पूर्णाङ्क asm_get_prefix_name(TCCState *s1, अचर वर्ण *prefix, अचिन्हित पूर्णाङ्क n)
{
    वर्ण buf[64];
    snprintf(buf, परिमाण(buf), "%s%u", prefix, n);
    फर्काऊ tok_alloc_const(buf);
}

ST_FUNC पूर्णाङ्क asm_get_local_label_name(TCCState *s1, अचिन्हित पूर्णाङ्क n)
{
    फर्काऊ asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
स्थिर पूर्णाङ्क asm2cname(पूर्णाङ्क v, पूर्णाङ्क *addeddot)
{
    अचर वर्ण *name;
    *addeddot = 0;
    यदि (!tcc_state->leading_underscore)
      फर्काऊ v;
    name = get_tok_str(v, रिक्त);
    यदि (!name)
      फर्काऊ v;
    यदि (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } अन्यथा यदि (!म_अक्षर(name, '.')) {
        वर्ण newname[256];
        snprintf(newname, परिमाण newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    फर्काऊ v;
}

स्थिर Sym *asm_label_find(पूर्णाङ्क v)
{
    Sym *sym;
    पूर्णाङ्क addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    जबसम्म (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    फर्काऊ sym;
}

स्थिर Sym *asm_label_थप(पूर्णाङ्क v)
{
    पूर्णाङ्क addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_थप(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    यदि (addeddot)
        sym->asm_label = v;
    फर्काऊ sym;
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
	sym = asm_label_थप(name);
	यदि (csym)
	  sym->c = csym->c;
    }
    फर्काऊ sym;
}

स्थिर Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    वर्ण buf[100]; पूर्णाङ्क label; Sym *sym;
    snprintf(buf, परिमाण buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    फर्काऊ sym ? sym : asm_new_label1(s1, label, 1, sec->sh_अङ्क, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

स्थिर शून्य asm_अभिव्यक्ति_unary(TCCState *s1, अभिव्यक्ति_मान *pe)
{
    Sym *sym;
    पूर्णाङ्क op, label;
    uint64_t n;
    अचर वर्ण *p;

    विकल्प(tok) {
    पक्ष TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (वर्ण **)&p, 0);
        यदि (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            यदि (*p == 'b') {
                /* backward : find the last corresponding defined label */
                यदि (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                यदि (!sym)
                    tcc_error("local label '%d' not found backward", (पूर्णाङ्क)n);
            } अन्यथा {
                /* forward */
                यदि (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_थप(label);
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
        next();
        रोक;
    पक्ष '+':
        next();
        asm_अभिव्यक्ति_unary(s1, pe);
        रोक;
    पक्ष '-':
    पक्ष '~':
        op = tok;
        next();
        asm_अभिव्यक्ति_unary(s1, pe);
        यदि (pe->sym)
            tcc_error("invalid operation with label");
        यदि (op == '-')
            pe->v = -pe->v;
        अन्यथा
            pe->v = ~pe->v;
        रोक;
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = रिक्त;
	pe->pcrel = 0;
	next();
	रोक;
    पक्ष '(':
        next();
        asm_अभिव्यक्ति(s1, pe);
        skip(')');
        रोक;
    पक्ष '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        रोक;
    स्वभाव:
        यदि (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, रिक्त);
	    esym = elfsym(sym);
            यदि (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_मान;
                pe->sym = रिक्त;
		pe->pcrel = 0;
            } अन्यथा {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } अन्यथा {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        रोक;
    }
}
    
स्थिर शून्य asm_अभिव्यक्ति_prod(TCCState *s1, अभिव्यक्ति_मान *pe)
{
    पूर्णाङ्क op;
    अभिव्यक्ति_मान e2;

    asm_अभिव्यक्ति_unary(s1, pe);
    लागि(;;) {
        op = tok;
        यदि (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            रोक;
        next();
        asm_अभिव्यक्ति_unary(s1, &e2);
        यदि (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
        पक्ष '*':
            pe->v *= e2.v;
            रोक;
        पक्ष '/':  
            यदि (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            रोक;
        पक्ष '%':  
            यदि (e2.v == 0)
                गच्छ div_error;
            pe->v %= e2.v;
            रोक;
        पक्ष TOK_SHL:
            pe->v <<= e2.v;
            रोक;
        स्वभाव:
        पक्ष TOK_SAR:
            pe->v >>= e2.v;
            रोक;
        }
    }
}

स्थिर शून्य asm_अभिव्यक्ति_logic(TCCState *s1, अभिव्यक्ति_मान *pe)
{
    पूर्णाङ्क op;
    अभिव्यक्ति_मान e2;

    asm_अभिव्यक्ति_prod(s1, pe);
    लागि(;;) {
        op = tok;
        यदि (op != '&' && op != '|' && op != '^')
            रोक;
        next();
        asm_अभिव्यक्ति_prod(s1, &e2);
        यदि (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
        पक्ष '&':
            pe->v &= e2.v;
            रोक;
        पक्ष '|':  
            pe->v |= e2.v;
            रोक;
        स्वभाव:
        पक्ष '^':
            pe->v ^= e2.v;
            रोक;
        }
    }
}

स्थिर अन्तःस्थ शून्य asm_अभिव्यक्ति_sum(TCCState *s1, अभिव्यक्ति_मान *pe)
{
    पूर्णाङ्क op;
    अभिव्यक्ति_मान e2;

    asm_अभिव्यक्ति_logic(s1, pe);
    लागि(;;) {
        op = tok;
        यदि (op != '+' && op != '-')
            रोक;
        next();
        asm_अभिव्यक्ति_logic(s1, &e2);
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
		    pe->v += (पूर्णाङ्क)(esym1->st_मान - esym2->st_मान);
		    pe->sym = रिक्त;
		} अन्यथा यदि (esym2->st_shndx == cur_text_section->sh_अङ्क) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (पूर्णाङ्क)(0 - esym2->st_मान);
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

स्थिर अन्तःस्थ शून्य asm_अभिव्यक्ति_cmp(TCCState *s1, अभिव्यक्ति_मान *pe)
{
    पूर्णाङ्क op;
    अभिव्यक्ति_मान e2;

    asm_अभिव्यक्ति_sum(s1, pe);
    लागि(;;) {
        op = tok;
	यदि (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            रोक;
        next();
        asm_अभिव्यक्ति_sum(s1, &e2);
        यदि (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        विकल्प(op) {
	पक्ष TOK_EQ:
	    pe->v = pe->v == e2.v;
	    रोक;
	पक्ष TOK_NE:
	    pe->v = pe->v != e2.v;
	    रोक;
	पक्ष TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    रोक;
	पक्ष TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    रोक;
	पक्ष TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    रोक;
	पक्ष TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    रोक;
        स्वभाव:
            रोक;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC शून्य asm_अभिव्यक्ति(TCCState *s1, अभिव्यक्ति_मान *pe)
{
    asm_अभिव्यक्ति_cmp(s1, pe);
}

ST_FUNC पूर्णाङ्क asm_int_अभिव्यक्ति(TCCState *s1)
{
    अभिव्यक्ति_मान e;
    asm_अभिव्यक्ति(s1, &e);
    यदि (e.sym)
        expect("constant");
    यदि ((पूर्णाङ्क)e.v != e.v)
	tcc_error("integer out of range %lld", (दीर्घ दीर्घ)e.v);
    फर्काऊ e.v;
}

स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local,
                           पूर्णाङ्क sh_अङ्क, पूर्णाङ्क मान)
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
        sym = asm_label_थप(label);
    }
    यदि (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_अङ्क;
    esym->st_मान = मान;
    यदि (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    फर्काऊ sym;
}

स्थिर Sym* asm_new_label(TCCState *s1, पूर्णाङ्क label, पूर्णाङ्क is_local)
{
    फर्काऊ asm_new_label1(s1, label, is_local, cur_text_section->sh_अङ्क, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
स्थिर Sym* set_चिह्न(TCCState *s1, पूर्णाङ्क label)
{
    दीर्घ n;
    अभिव्यक्ति_मान e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_अभिव्यक्ति(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    यदि (esym)
	n += esym->st_मान;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    फर्काऊ sym;
}

स्थिर शून्य use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

स्थिर शून्य use_section(TCCState *s1, अचर वर्ण *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

स्थिर शून्य थप_section(TCCState *s1, अचर वर्ण *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

स्थिर शून्य झिक_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    यदि (!prev)
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
        n = asm_int_अभिव्यक्ति(s1);
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
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            यदि (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } अन्यथा {
	    यदि (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        यदि (tok == ',') {
            next();
            v = asm_int_अभिव्यक्ति(s1), c = 0;
        }
    zero_pad:
	यदि ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        यदि (sec->sh_type != SHT_NOBITS) {
            यदि (c) {
                gen_fill_nops(size);
                रोक;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            स_रखो(ptr, v, size);
        }
        ind += size;
        रोक;
    पक्ष TOK_ASMDIR_quad:
#यदि PTR_SIZE == 8
	size = 8;
	गच्छ asm_data;
#अन्यथा
        next();
        लागि(;;) {
            uint64_t vl;
            अचर वर्ण *p;

            p = tokc.str.data;
            यदि (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (वर्ण **)&p, 0);
            यदि (*p != '\0')
                गच्छ error_constant;
            next();
            यदि (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } अन्यथा {
                ind += 8;
            }
            यदि (tok != ',')
                रोक;
            next();
        }
        रोक;
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
        लागि(;;) {
            अभिव्यक्ति_मान e;
            asm_अभिव्यक्ति(s1, &e);
            यदि (sec->sh_type != SHT_NOBITS) {
                यदि (size == 4) {
                    gen_expr32(&e);
#यदि PTR_SIZE == 8
		} अन्यथा यदि (size == 8) {
		    gen_expr64(&e);
#endif
                } अन्यथा {
                    यदि (e.sym)
                        expect("constant");
                    यदि (size == 1)
                        g(e.v);
                    अन्यथा
                        gen_le16(e.v);
                }
            } अन्यथा {
                ind += size;
            }
            यदि (tok != ',')
                रोक;
            next();
        }
        रोक;
    पक्ष TOK_ASMDIR_fill:
        {
            पूर्णाङ्क repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_अभिव्यक्ति(s1);
            यदि (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                रोक;
            }
            size = 1;
            val = 0;
            यदि (tok == ',') {
                next();
                size = asm_int_अभिव्यक्ति(s1);
                यदि (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    रोक;
                }
                यदि (size > 8)
                    size = 8;
                यदि (tok == ',') {
                    next();
                    val = asm_int_अभिव्यक्ति(s1);
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
            लागि(i = 0; i < repeat; i++) {
                लागि(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        रोक;
    पक्ष TOK_ASMDIR_rept:
        {
            पूर्णाङ्क repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_अभिव्यक्ति(s1);
            init_str = tok_str_alloc();
            जबसम्म (next(), tok != TOK_ASMDIR_endr) {
                यदि (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            जबसम्म (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            रोक;
        }
    पक्ष TOK_ASMDIR_org:
        {
	    अभिव्यक्ति_मान e;
	    ElfSym *esym;
            next();
	    asm_अभिव्यक्ति(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    यदि (esym) {
		यदि (esym->st_shndx != cur_text_section->sh_अङ्क)
		  expect("constant or same-section symbol");
		n += esym->st_मान;
	    }
            यदि (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            गच्छ zero_pad;
        }
        रोक;
    पक्ष TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	यदि (tok == ',')
	    set_चिह्न(s1, tok1);
	रोक;
    पक्ष TOK_ASMDIR_globl:
    पक्ष TOK_ASMDIR_global:
    पक्ष TOK_ASMDIR_weak:
    पक्ष TOK_ASMDIR_hidden:
	tok1 = tok;
	गर { 
            Sym *sym;
            next();
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
            next();
	} जबसम्म (tok == ',');
	रोक;
    पक्ष TOK_ASMDIR_string:
    पक्ष TOK_ASMDIR_ascii:
    पक्ष TOK_ASMDIR_asciz:
        {
            अचर वर्ण *p;
            पूर्णाङ्क i, size, t;

            t = tok;
            next();
            लागि(;;) {
                यदि (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                यदि (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                लागि(i = 0; i < size; i++)
                    g(p[i]);
                next();
                यदि (tok == ',') {
                    next();
                } अन्यथा यदि (tok != TOK_STR) {
                    रोक;
                }
            }
	}
	रोक;
    पक्ष TOK_ASMDIR_text:
    पक्ष TOK_ASMDIR_data:
    पक्ष TOK_ASMDIR_bss:
	{ 
            वर्ण sname[64];
            tok1 = tok;
            n = 0;
            next();
            यदि (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_अभिव्यक्ति(s1);
		next();
            }
            यदि (n)
                प्र_लिखो(sname, "%s%d", get_tok_str(tok1, रिक्त), n);
            अन्यथा
                प्र_लिखो(sname, "%s", get_tok_str(tok1, रिक्त));
            use_section(s1, sname);
	}
	रोक;
    पक्ष TOK_ASMDIR_file:
        {
            अचर वर्ण *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            यदि (tok == TOK_PPNUM)
                next();
            यदि (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } अन्यथा यदि (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } अन्यथा {
                skip_to_eol(0);
                रोक;
            }
            tccpp_putfile(p);
            next();
        }
        रोक;
    पक्ष TOK_ASMDIR_ident:
        {
            वर्ण ident[256];

            ident[0] = '\0';
            next();
            यदि (tok == TOK_STR)
                pstrcat(ident, परिमाण(ident), tokc.str.data);
            अन्यथा
                pstrcat(ident, परिमाण(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        रोक;
    पक्ष TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    यदि (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            यदि (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, रिक्त));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, रिक्त));
            next();
            skip(',');
            n = asm_int_अभिव्यक्ति(s1);
            esym = elfsym(sym);
            यदि (esym) {
                esym->st_size = n;
            }
        }
        रोक;
    पक्ष TOK_ASMDIR_type:
        { 
            Sym *sym;
            अचर वर्ण *newtype;
            पूर्णाङ्क st_type;

            next();
	    यदि (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
            next();
            skip(',');
            यदि (tok == TOK_STR) {
                newtype = tokc.str.data;
            } अन्यथा {
                यदि (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, रिक्त);
            }

            यदि (!म_भेद(newtype, "function") || !म_भेद(newtype, "STT_FUNC")) {
                यदि (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                यदि (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } अन्यथा यदि (!म_भेद(newtype, "object") || !म_भेद(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                गच्छ set_st_type;
            } अन्यथा
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, रिक्त), sym->type.t, newtype);

            next();
        }
        रोक;
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
            जबसम्म (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                यदि (tok == TOK_STR)
                    pstrcat(sname, परिमाण(sname), tokc.str.data);
                अन्यथा
                    pstrcat(sname, परिमाण(sname), get_tok_str(tok, रिक्त));
                next();
            }
            यदि (tok == ',') {
                अचर वर्ण *p;
                /* skip section options */
                next();
                यदि (tok != TOK_STR)
                    expect("string constant");
                लागि (p = tokc.str.data; *p; ++p) {
                    यदि (*p == 'w')
                        flags |= SHF_WRITE;
                    यदि (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                यदि (tok == ',') {
                    next();
                    यदि (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    यदि (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    अन्यथा
	        थप_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    यदि (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                यदि (!म_भेद(sname, ".init") || !म_भेद(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        रोक;
    पक्ष TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            यदि (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        रोक;
    पक्ष TOK_ASMDIR_popsection:
	next();
	झिक_section(s1);
	रोक;
#ifdef TCC_TARGET_I386
    पक्ष TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        रोक;
    पक्ष TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        रोक;
#endif
#यदि PTR_SIZE == 8
    /* added for compatibility with GAS */
    पक्ष TOK_ASMDIR_code64:
        next();
        रोक;
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
            पक्ष TOK_ASM_थप:
            पक्ष TOK_ASM_झिक:
                /* TODO: unimplemented */
                next();
                रोक;
            पक्ष TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, रिक्त));
                रोक;
            स्वभाव:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, रिक्त));
                रोक;
        }
        रोक;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    पक्ष TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	रोक;
    पक्ष TOK_ASMDIR_reloc:
	{
	    अभिव्यक्ति_मान e;
	    अचर वर्ण *reloc_name;
	    पूर्णाङ्क reloc_type = -1;

	    next();
	    asm_अभिव्यक्ति(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, रिक्त);
#यदि defined(TCC_TARGET_ARM64)
	    यदि (!म_भेद(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#अथवायदि defined(TCC_TARGET_RISCV64)
	    यदि (!म_भेद(reloc_name, "R_RISCV_CALL") || !म_भेद(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    अन्यथा यदि (!म_भेद(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    यदि (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, रिक्त), e.v, reloc_type, 0);
	    next();
	}
	रोक;
    स्वभाव:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, रिक्त));
        रोक;
    }
}


/* assemble a file */
स्थिर पूर्णाङ्क tcc_assemble_internal(TCCState *s1, पूर्णाङ्क do_preprocess, पूर्णाङ्क global)
{
    पूर्णाङ्क opcode;
    पूर्णाङ्क saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    यदि (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    लागि(;;) {
        next();
        यदि (tok == TOK_EOF)
            रोक;
        tcc_debug_पङ्क्ति(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#यदि !defined(TCC_TARGET_ARM64)
        यदि (tok == '#') {
            /* horrible gas comment */
            जबसम्म (tok != TOK_LINEFEED)
                next();
        } अन्यथा
#endif
        यदि (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } अन्यथा यदि (tok == TOK_PPNUM) {
            अचर वर्ण *p;
            पूर्णाङ्क n;
            p = tokc.str.data;
            n = म_से_अदीर्घ(p, (वर्ण **)&p, 10);
            यदि (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            गच्छ redo;
        } अन्यथा यदि (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            यदि (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                गच्छ redo;
            } अन्यथा यदि (tok == '=') {
		set_चिह्न(s1, opcode);
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
    फर्काऊ 0;
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
    फर्काऊ ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
स्थिर शून्य tcc_assemble_inline(TCCState *s1, अचर वर्ण *str, पूर्णाङ्क len, पूर्णाङ्क global)
{
    अचर पूर्णाङ्क *saved_macro_ptr = macro_ptr;
    पूर्णाङ्क dotid = set_idnum('.', IS_ID);
#यदि !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    पूर्णाङ्क dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    स_नकल(file->buffer, str, len);
    macro_ptr = रिक्त;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#यदि !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC पूर्णाङ्क find_constraint(ASMOperand *operands, पूर्णाङ्क nb_operands, 
                           अचर वर्ण *name, अचर वर्ण **pp)
{
    पूर्णाङ्क index;
    TokenSym *ts;
    अचर वर्ण *p;

    यदि (isnum(*name)) {
        index = 0;
        जबसम्म (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        यदि ((अचिन्हित)index >= nb_operands)
            index = -1;
    } अन्यथा यदि (*name == '[') {
        name++;
        p = म_अक्षर(name, ']');
        यदि (p) {
            ts = tok_alloc(name, p - name);
            लागि(index = 0; index < nb_operands; index++) {
                यदि (operands[index].id == ts->tok)
                    गच्छ found;
            }
            index = -1;
        found:
            name = p + 1;
        } अन्यथा {
            index = -1;
        }
    } अन्यथा {
        index = -1;
    }
    यदि (pp)
        *pp = name;
    फर्काऊ index;
}

स्थिर शून्य subst_asm_operands(ASMOperand *operands, पूर्णाङ्क nb_operands, 
                               CString *out_str, अचर वर्ण *str)
{
    पूर्णाङ्क c, index, modifier;
    ASMOperand *op;
    SValue sv;

    लागि(;;) {
        c = *str++;
        यदि (c == '%') {
            यदि (*str == '%') {
                str++;
                गच्छ add_char;
            }
            modifier = 0;
            यदि (*str == 'c' || *str == 'n' ||
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
            यदि (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            यदि (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, रिक्त), -1);
            } अन्यथा {
		यदि (op->vt == रिक्त)
		    गच्छ error;
                sv = *op->vt;
                यदि (op->reg >= 0) {
                    sv.r = op->reg;
                    यदि (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } अन्यथा {
        add_char:
            cstr_ccat(out_str, c);
            यदि (c == '\0')
                रोक;
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
        लागि(;;) {
            यदि (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            यदि (tok == '[') {
                next();
                यदि (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
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
                    !म_अक्षर(op->constraint, 'm')
#ifdef TCC_TARGET_ARM64
                    && !म_अक्षर(op->constraint, 'Q')
                    && !म_माला(op->constraint, "Ump")
#endif
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            यदि (tok == ',') {
                next();
            } अन्यथा {
                रोक;
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
    जबसम्म (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    स_रखो(clobber_regs, 0, परिमाण(clobber_regs));
    यदि (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        यदि (tok == ':') {
            next();
            यदि (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                यदि (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    लागि(;;) {
                        यदि (tok == ':')
                          रोक;
                        यदि (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        यदि (tok == ',') {
                            next();
                        } अन्यथा {
                            रोक;
                        }
                    }
                }
                यदि (tok == ':') {
                    /* goto labels */
                    next();
                    लागि (;;) {
                        Sym *csym;
                        पूर्णाङ्क asmname;
                        यदि (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        यदि (tok < TOK_UIDENT)
                          expect("label identifier");
			स_रखो(operands + nb_operands + nb_labels, 0,
			       परिमाण(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        यदि (!csym) {
                            csym = label_थप(&global_label_थाक, tok,
                                              LABEL_FORWARD);
                        } अन्यथा {
                            यदि (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        यदि (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        यदि (tok != ',')
                          रोक;
                        next();
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
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    म_लिखो("asm: \"%s\"\n", (वर्ण *)astr.data);
#endif
    यदि (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    म_लिखो("subst_asm: \"%s\"\n", (वर्ण *)astr.data);
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
    यदि (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    लागि(i=0;i<nb_operands;i++) {
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
    यदि (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    म_लिखो("asm_global: \"%s\"\n", (वर्ण *)astr->data);
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
#endif /* CONFIG_TCC_ASM */
