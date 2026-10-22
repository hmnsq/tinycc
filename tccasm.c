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
स्थिर पूर्णांक asmgoto_n;

स्थिर पूर्णांक tcc_assemble_internal(TCCState *s1, पूर्णांक do_preprocess, पूर्णांक global);
स्थिर Sym* asm_new_label(TCCState *s1, पूर्णांक label, पूर्णांक is_local);
स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णांक label, पूर्णांक is_local, पूर्णांक sh_अंक, पूर्णांक मूल्य);

#जर PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC शून्य gen_addr64(पूर्णांक r, Sym *sym, int64_t c)
{
    जर (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC शून्य gen_expr64(अभिव्यक्ती_मूल्य *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

स्थिर पूर्णांक asm_get_prefix_name(TCCState *s1, स्थिरांक अक्षर *prefix, अचिन्हित पूर्णांक n)
{
    अक्षर buf[64];
    snprintf(buf, आकार(buf), "%s%u", prefix, n);
    परत tok_alloc_const(buf);
}

ST_FUNC पूर्णांक asm_get_local_label_name(TCCState *s1, अचिन्हित पूर्णांक n)
{
    परत asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
स्थिर पूर्णांक asm2cname(पूर्णांक v, पूर्णांक *addeddot)
{
    स्थिरांक अक्षर *name;
    *addeddot = 0;
    जर (!tcc_state->leading_underscore)
      परत v;
    name = get_tok_str(v, रिक्त);
    जर (!name)
      परत v;
    जर (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } अन्यथा जर (!म_अक्षर(name, '.')) {
        अक्षर newname[256];
        snprintf(newname, आकार newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    परत v;
}

स्थिर Sym *asm_label_find(पूर्णांक v)
{
    Sym *sym;
    पूर्णांक addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    पर्यंत (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    परत sym;
}

स्थिर Sym *asm_label_ढकला(पूर्णांक v)
{
    पूर्णांक addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ढकला(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    जर (addeddot)
        sym->asm_label = v;
    परत sym;
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
    जर (!sym) {
	sym = asm_label_ढकला(name);
	जर (csym)
	  sym->c = csym->c;
    }
    परत sym;
}

स्थिर Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    अक्षर buf[100]; पूर्णांक label; Sym *sym;
    snprintf(buf, आकार buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    परत sym ? sym : asm_new_label1(s1, label, 1, sec->sh_अंक, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

स्थिर शून्य asm_अभिव्यक्ती_unary(TCCState *s1, अभिव्यक्ती_मूल्य *pe)
{
    Sym *sym;
    पूर्णांक op, label;
    uint64_t n;
    स्थिरांक अक्षर *p;

    निवड(tok) {
    स्थिती TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (अक्षर **)&p, 0);
        जर (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            जर (*p == 'b') {
                /* backward : find the last corresponding defined label */
                जर (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                जर (!sym)
                    tcc_error("local label '%d' not found backward", (पूर्णांक)n);
            } अन्यथा {
                /* forward */
                जर (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ढकला(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } अन्यथा जर (*p == '\0') {
            pe->v = n;
            pe->sym = रिक्त;
	    pe->pcrel = 0;
        } अन्यथा {
            tcc_error("invalid number syntax");
        }
        next();
        थांबा;
    स्थिती '+':
        next();
        asm_अभिव्यक्ती_unary(s1, pe);
        थांबा;
    स्थिती '-':
    स्थिती '~':
        op = tok;
        next();
        asm_अभिव्यक्ती_unary(s1, pe);
        जर (pe->sym)
            tcc_error("invalid operation with label");
        जर (op == '-')
            pe->v = -pe->v;
        अन्यथा
            pe->v = ~pe->v;
        थांबा;
    स्थिती TOK_CCHAR:
    स्थिती TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = रिक्त;
	pe->pcrel = 0;
	next();
	थांबा;
    स्थिती '(':
        next();
        asm_अभिव्यक्ती(s1, pe);
        skip(')');
        थांबा;
    स्थिती '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        थांबा;
    पूर्वनिर्धारित:
        जर (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, रिक्त);
	    esym = elfsym(sym);
            जर (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_मूल्य;
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
        थांबा;
    }
}
    
स्थिर शून्य asm_अभिव्यक्ती_prod(TCCState *s1, अभिव्यक्ती_मूल्य *pe)
{
    पूर्णांक op;
    अभिव्यक्ती_मूल्य e2;

    asm_अभिव्यक्ती_unary(s1, pe);
    साठी(;;) {
        op = tok;
        जर (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            थांबा;
        next();
        asm_अभिव्यक्ती_unary(s1, &e2);
        जर (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        निवड(op) {
        स्थिती '*':
            pe->v *= e2.v;
            थांबा;
        स्थिती '/':  
            जर (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            थांबा;
        स्थिती '%':  
            जर (e2.v == 0)
                जा div_error;
            pe->v %= e2.v;
            थांबा;
        स्थिती TOK_SHL:
            pe->v <<= e2.v;
            थांबा;
        पूर्वनिर्धारित:
        स्थिती TOK_SAR:
            pe->v >>= e2.v;
            थांबा;
        }
    }
}

स्थिर शून्य asm_अभिव्यक्ती_logic(TCCState *s1, अभिव्यक्ती_मूल्य *pe)
{
    पूर्णांक op;
    अभिव्यक्ती_मूल्य e2;

    asm_अभिव्यक्ती_prod(s1, pe);
    साठी(;;) {
        op = tok;
        जर (op != '&' && op != '|' && op != '^')
            थांबा;
        next();
        asm_अभिव्यक्ती_prod(s1, &e2);
        जर (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        निवड(op) {
        स्थिती '&':
            pe->v &= e2.v;
            थांबा;
        स्थिती '|':  
            pe->v |= e2.v;
            थांबा;
        पूर्वनिर्धारित:
        स्थिती '^':
            pe->v ^= e2.v;
            थांबा;
        }
    }
}

स्थिर ओळीत शून्य asm_अभिव्यक्ती_sum(TCCState *s1, अभिव्यक्ती_मूल्य *pe)
{
    पूर्णांक op;
    अभिव्यक्ती_मूल्य e2;

    asm_अभिव्यक्ती_logic(s1, pe);
    साठी(;;) {
        op = tok;
        जर (op != '+' && op != '-')
            थांबा;
        next();
        asm_अभिव्यक्ती_logic(s1, &e2);
        जर (op == '+') {
            जर (pe->sym != रिक्त && e2.sym != रिक्त)
                जा cannot_relocate;
            pe->v += e2.v;
            जर (pe->sym == रिक्त && e2.sym != रिक्त)
                pe->sym = e2.sym;
        } अन्यथा {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    जर (!e2.sym) {
		/* OK */
	    } अन्यथा जर (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = रिक्त; /* same symbols can be subtracted to NULL */
	    } अन्यथा {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		जर (!esym2)
		    जा cannot_relocate;
		जर (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (पूर्णांक)(esym1->st_मूल्य - esym2->st_मूल्य);
		    pe->sym = रिक्त;
		} अन्यथा जर (esym2->st_shndx == cur_text_section->sh_अंक) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (पूर्णांक)(0 - esym2->st_मूल्य);
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

स्थिर ओळीत शून्य asm_अभिव्यक्ती_cmp(TCCState *s1, अभिव्यक्ती_मूल्य *pe)
{
    पूर्णांक op;
    अभिव्यक्ती_मूल्य e2;

    asm_अभिव्यक्ती_sum(s1, pe);
    साठी(;;) {
        op = tok;
	जर (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            थांबा;
        next();
        asm_अभिव्यक्ती_sum(s1, &e2);
        जर (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        निवड(op) {
	स्थिती TOK_EQ:
	    pe->v = pe->v == e2.v;
	    थांबा;
	स्थिती TOK_NE:
	    pe->v = pe->v != e2.v;
	    थांबा;
	स्थिती TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    थांबा;
	स्थिती TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    थांबा;
	स्थिती TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    थांबा;
	स्थिती TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    थांबा;
        पूर्वनिर्धारित:
            थांबा;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC शून्य asm_अभिव्यक्ती(TCCState *s1, अभिव्यक्ती_मूल्य *pe)
{
    asm_अभिव्यक्ती_cmp(s1, pe);
}

ST_FUNC पूर्णांक asm_int_अभिव्यक्ती(TCCState *s1)
{
    अभिव्यक्ती_मूल्य e;
    asm_अभिव्यक्ती(s1, &e);
    जर (e.sym)
        expect("constant");
    जर ((पूर्णांक)e.v != e.v)
	tcc_error("integer out of range %lld", (दीर्घ दीर्घ)e.v);
    परत e.v;
}

स्थिर Sym* asm_new_label1(TCCState *s1, पूर्णांक label, पूर्णांक is_local,
                           पूर्णांक sh_अंक, पूर्णांक मूल्य)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    जर (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        जर (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            जर (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                जा new_label;
            जर (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, रिक्त));
        }
    } अन्यथा {
    new_label:
        sym = asm_label_ढकला(label);
    }
    जर (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_अंक;
    esym->st_मूल्य = मूल्य;
    जर (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    परत sym;
}

स्थिर Sym* asm_new_label(TCCState *s1, पूर्णांक label, पूर्णांक is_local)
{
    परत asm_new_label1(s1, label, is_local, cur_text_section->sh_अंक, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
स्थिर Sym* set_चिन्ह(TCCState *s1, पूर्णांक label)
{
    दीर्घ n;
    अभिव्यक्ती_मूल्य e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_अभिव्यक्ती(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    जर (esym)
	n += esym->st_मूल्य;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    परत sym;
}

स्थिर शून्य use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

स्थिर शून्य use_section(TCCState *s1, स्थिरांक अक्षर *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

स्थिर शून्य ढकला_section(TCCState *s1, स्थिरांक अक्षर *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

स्थिर शून्य काढा_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    जर (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = रिक्त;
    use_section1(s1, prev);
}

स्थिर शून्य asm_parse_directive(TCCState *s1, पूर्णांक global)
{
    पूर्णांक n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    निवड(tok) {
    स्थिती TOK_ASMDIR_align:
    स्थिती TOK_ASMDIR_balign:
    स्थिती TOK_ASMDIR_p2align:
    स्थिती TOK_ASMDIR_skip:
    स्थिती TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_अभिव्यक्ती(s1);
        जर (tok1 == TOK_ASMDIR_p2align)
        {
            जर (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        जर (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            जर (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            जर (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } अन्यथा {
	    जर (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        जर (tok == ',') {
            next();
            v = asm_int_अभिव्यक्ती(s1), c = 0;
        }
    zero_pad:
	जर ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        जर (sec->sh_type != SHT_NOBITS) {
            जर (c) {
                gen_fill_nops(size);
                थांबा;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            स_रखो(ptr, v, size);
        }
        ind += size;
        थांबा;
    स्थिती TOK_ASMDIR_quad:
#जर PTR_SIZE == 8
	size = 8;
	जा asm_data;
#अन्यथा
        next();
        साठी(;;) {
            uint64_t vl;
            स्थिरांक अक्षर *p;

            p = tokc.str.data;
            जर (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (अक्षर **)&p, 0);
            जर (*p != '\0')
                जा error_constant;
            next();
            जर (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } अन्यथा {
                ind += 8;
            }
            जर (tok != ',')
                थांबा;
            next();
        }
        थांबा;
#endif
    स्थिती TOK_ASMDIR_byte:
        size = 1;
        जा asm_data;
    स्थिती TOK_ASMDIR_word:
    स्थिती TOK_ASMDIR_short:
        size = 2;
        जा asm_data;
    स्थिती TOK_ASMDIR_long:
    स्थिती TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        साठी(;;) {
            अभिव्यक्ती_मूल्य e;
            asm_अभिव्यक्ती(s1, &e);
            जर (sec->sh_type != SHT_NOBITS) {
                जर (size == 4) {
                    gen_expr32(&e);
#जर PTR_SIZE == 8
		} अन्यथा जर (size == 8) {
		    gen_expr64(&e);
#endif
                } अन्यथा {
                    जर (e.sym)
                        expect("constant");
                    जर (size == 1)
                        g(e.v);
                    अन्यथा
                        gen_le16(e.v);
                }
            } अन्यथा {
                ind += size;
            }
            जर (tok != ',')
                थांबा;
            next();
        }
        थांबा;
    स्थिती TOK_ASMDIR_fill:
        {
            पूर्णांक repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_अभिव्यक्ती(s1);
            जर (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                थांबा;
            }
            size = 1;
            val = 0;
            जर (tok == ',') {
                next();
                size = asm_int_अभिव्यक्ती(s1);
                जर (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    थांबा;
                }
                जर (size > 8)
                    size = 8;
                जर (tok == ',') {
                    next();
                    val = asm_int_अभिव्यक्ती(s1);
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
            साठी(i = 0; i < repeat; i++) {
                साठी(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        थांबा;
    स्थिती TOK_ASMDIR_rept:
        {
            पूर्णांक repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_अभिव्यक्ती(s1);
            init_str = tok_str_alloc();
            पर्यंत (next(), tok != TOK_ASMDIR_endr) {
                जर (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            पर्यंत (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            थांबा;
        }
    स्थिती TOK_ASMDIR_org:
        {
	    अभिव्यक्ती_मूल्य e;
	    ElfSym *esym;
            next();
	    asm_अभिव्यक्ती(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    जर (esym) {
		जर (esym->st_shndx != cur_text_section->sh_अंक)
		  expect("constant or same-section symbol");
		n += esym->st_मूल्य;
	    }
            जर (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            जा zero_pad;
        }
        थांबा;
    स्थिती TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	जर (tok == ',')
	    set_चिन्ह(s1, tok1);
	थांबा;
    स्थिती TOK_ASMDIR_globl:
    स्थिती TOK_ASMDIR_global:
    स्थिती TOK_ASMDIR_weak:
    स्थिती TOK_ASMDIR_hidden:
	tok1 = tok;
	करा { 
            Sym *sym;
            next();
	    जर (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
	    जर (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            जर (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    अन्यथा जर (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} पर्यंत (tok == ',');
	थांबा;
    स्थिती TOK_ASMDIR_string:
    स्थिती TOK_ASMDIR_ascii:
    स्थिती TOK_ASMDIR_asciz:
        {
            स्थिरांक अक्षर *p;
            पूर्णांक i, size, t;

            t = tok;
            next();
            साठी(;;) {
                जर (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                जर (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                साठी(i = 0; i < size; i++)
                    g(p[i]);
                next();
                जर (tok == ',') {
                    next();
                } अन्यथा जर (tok != TOK_STR) {
                    थांबा;
                }
            }
	}
	थांबा;
    स्थिती TOK_ASMDIR_text:
    स्थिती TOK_ASMDIR_data:
    स्थिती TOK_ASMDIR_bss:
	{ 
            अक्षर sname[64];
            tok1 = tok;
            n = 0;
            next();
            जर (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_अभिव्यक्ती(s1);
		next();
            }
            जर (n)
                प्र_लिखो(sname, "%s%d", get_tok_str(tok1, रिक्त), n);
            अन्यथा
                प्र_लिखो(sname, "%s", get_tok_str(tok1, रिक्त));
            use_section(s1, sname);
	}
	थांबा;
    स्थिती TOK_ASMDIR_file:
        {
            स्थिरांक अक्षर *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            जर (tok == TOK_PPNUM)
                next();
            जर (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } अन्यथा जर (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } अन्यथा {
                skip_to_eol(0);
                थांबा;
            }
            tccpp_putfile(p);
            next();
        }
        थांबा;
    स्थिती TOK_ASMDIR_ident:
        {
            अक्षर ident[256];

            ident[0] = '\0';
            next();
            जर (tok == TOK_STR)
                pstrcat(ident, आकार(ident), tokc.str.data);
            अन्यथा
                pstrcat(ident, आकार(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        थांबा;
    स्थिती TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    जर (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            जर (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, रिक्त));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, रिक्त));
            next();
            skip(',');
            n = asm_int_अभिव्यक्ती(s1);
            esym = elfsym(sym);
            जर (esym) {
                esym->st_size = n;
            }
        }
        थांबा;
    स्थिती TOK_ASMDIR_type:
        { 
            Sym *sym;
            स्थिरांक अक्षर *newtype;
            पूर्णांक st_type;

            next();
	    जर (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, रिक्त);
            next();
            skip(',');
            जर (tok == TOK_STR) {
                newtype = tokc.str.data;
            } अन्यथा {
                जर (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, रिक्त);
            }

            जर (!म_भेद(newtype, "function") || !म_भेद(newtype, "STT_FUNC")) {
                जर (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                जर (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } अन्यथा जर (!म_भेद(newtype, "object") || !म_भेद(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                जा set_st_type;
            } अन्यथा
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, रिक्त), sym->type.t, newtype);

            next();
        }
        थांबा;
    स्थिती TOK_ASMDIR_pushsection:
    स्थिती TOK_ASMDIR_section:
        {
            अक्षर sname[256];
	    पूर्णांक old_nb_section = s1->nb_sections;
            पूर्णांक flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            पर्यंत (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                जर (tok == TOK_STR)
                    pstrcat(sname, आकार(sname), tokc.str.data);
                अन्यथा
                    pstrcat(sname, आकार(sname), get_tok_str(tok, रिक्त));
                next();
            }
            जर (tok == ',') {
                स्थिरांक अक्षर *p;
                /* skip section options */
                next();
                जर (tok != TOK_STR)
                    expect("string constant");
                साठी (p = tokc.str.data; *p; ++p) {
                    जर (*p == 'w')
                        flags |= SHF_WRITE;
                    जर (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                जर (tok == ',') {
                    next();
                    जर (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    जर (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    अन्यथा
	        ढकला_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    जर (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                जर (!म_भेद(sname, ".init") || !म_भेद(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        थांबा;
    स्थिती TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            जर (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        थांबा;
    स्थिती TOK_ASMDIR_popsection:
	next();
	काढा_section(s1);
	थांबा;
#ifdef TCC_TARGET_I386
    स्थिती TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        थांबा;
    स्थिती TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        थांबा;
#endif
#जर PTR_SIZE == 8
    /* added for compatibility with GAS */
    स्थिती TOK_ASMDIR_code64:
        next();
        थांबा;
#endif
#ifdef TCC_TARGET_RISCV64
    स्थिती TOK_ASMDIR_option:
        next();
        निवड(tok){
            स्थिती TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            स्थिती TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            स्थिती TOK_ASM_pic:
            स्थिती TOK_ASM_nopic:
            स्थिती TOK_ASM_relax:
            स्थिती TOK_ASM_norelax:
            स्थिती TOK_ASM_ढकला:
            स्थिती TOK_ASM_काढा:
                /* TODO: unimplemented */
                next();
                थांबा;
            स्थिती TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, रिक्त));
                थांबा;
            पूर्वनिर्धारित:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, रिक्त));
                थांबा;
        }
        थांबा;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    स्थिती TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	थांबा;
    स्थिती TOK_ASMDIR_reloc:
	{
	    अभिव्यक्ती_मूल्य e;
	    स्थिरांक अक्षर *reloc_name;
	    पूर्णांक reloc_type = -1;

	    next();
	    asm_अभिव्यक्ती(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, रिक्त);
#जर defined(TCC_TARGET_ARM64)
	    जर (!म_भेद(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#किंवाजर defined(TCC_TARGET_RISCV64)
	    जर (!म_भेद(reloc_name, "R_RISCV_CALL") || !म_भेद(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    अन्यथा जर (!म_भेद(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    जर (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, रिक्त), e.v, reloc_type, 0);
	    next();
	}
	थांबा;
    पूर्वनिर्धारित:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, रिक्त));
        थांबा;
    }
}


/* assemble a file */
स्थिर पूर्णांक tcc_assemble_internal(TCCState *s1, पूर्णांक do_preprocess, पूर्णांक global)
{
    पूर्णांक opcode;
    पूर्णांक saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    जर (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    साठी(;;) {
        next();
        जर (tok == TOK_EOF)
            थांबा;
        tcc_debug_ओळ(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#जर !defined(TCC_TARGET_ARM64)
        जर (tok == '#') {
            /* horrible gas comment */
            पर्यंत (tok != TOK_LINEFEED)
                next();
        } अन्यथा
#endif
        जर (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } अन्यथा जर (tok == TOK_PPNUM) {
            स्थिरांक अक्षर *p;
            पूर्णांक n;
            p = tokc.str.data;
            n = म_से_अदीर्घ(p, (अक्षर **)&p, 10);
            जर (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            जा redo;
        } अन्यथा जर (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            जर (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                जा redo;
            } अन्यथा जर (tok == '=') {
		set_चिन्ह(s1, opcode);
                जा redo;
            } अन्यथा {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        जर (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    परत 0;
}

/* Assemble the current file */
ST_FUNC पूर्णांक tcc_assemble(TCCState *s1, पूर्णांक do_preprocess)
{
    पूर्णांक ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    परत ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
स्थिर शून्य tcc_assemble_inline(TCCState *s1, स्थिरांक अक्षर *str, पूर्णांक len, पूर्णांक global)
{
    स्थिरांक पूर्णांक *saved_macro_ptr = macro_ptr;
    पूर्णांक dotid = set_idnum('.', IS_ID);
#जर !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    पूर्णांक dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    स_नकल(file->buffer, str, len);
    macro_ptr = रिक्त;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#जर !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC पूर्णांक find_constraint(ASMOperand *operands, पूर्णांक nb_operands, 
                           स्थिरांक अक्षर *name, स्थिरांक अक्षर **pp)
{
    पूर्णांक index;
    TokenSym *ts;
    स्थिरांक अक्षर *p;

    जर (isnum(*name)) {
        index = 0;
        पर्यंत (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        जर ((अचिन्हित)index >= nb_operands)
            index = -1;
    } अन्यथा जर (*name == '[') {
        name++;
        p = म_अक्षर(name, ']');
        जर (p) {
            ts = tok_alloc(name, p - name);
            साठी(index = 0; index < nb_operands; index++) {
                जर (operands[index].id == ts->tok)
                    जा found;
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
    जर (pp)
        *pp = name;
    परत index;
}

स्थिर शून्य subst_asm_operands(ASMOperand *operands, पूर्णांक nb_operands, 
                               CString *out_str, स्थिरांक अक्षर *str)
{
    पूर्णांक c, index, modifier;
    ASMOperand *op;
    SValue sv;

    साठी(;;) {
        c = *str++;
        जर (c == '%') {
            जर (*str == '%') {
                str++;
                जा add_char;
            }
            modifier = 0;
            जर (*str == 'c' || *str == 'n' ||
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
            जर (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            जर (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, रिक्त), -1);
            } अन्यथा {
		जर (op->vt == रिक्त)
		    जा error;
                sv = *op->vt;
                जर (op->reg >= 0) {
                    sv.r = op->reg;
                    जर (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } अन्यथा {
        add_char:
            cstr_ccat(out_str, c);
            जर (c == '\0')
                थांबा;
        }
    }
}


स्थिर शून्य parse_asm_operands(ASMOperand *operands, पूर्णांक *nb_operands_ptr,
                               पूर्णांक is_output)
{
    ASMOperand *op;
    पूर्णांक nb_operands;
    अक्षर* astr;

    जर (tok != ':') {
        nb_operands = *nb_operands_ptr;
        साठी(;;) {
            जर (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            जर (tok == '[') {
                next();
                जर (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, आकार op->constraint, astr);
            skip('(');
            gexpr();
            जर (is_output) {
                जर (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } अन्यथा {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                जर ((vtop->r & VT_LVAL) &&
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
            जर (tok == ',') {
                next();
            } अन्यथा {
                थांबा;
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
    पूर्णांक nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    पर्यंत (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    स_रखो(clobber_regs, 0, आकार(clobber_regs));
    जर (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        जर (tok == ':') {
            next();
            जर (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                जर (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    साठी(;;) {
                        जर (tok == ':')
                          थांबा;
                        जर (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        जर (tok == ',') {
                            next();
                        } अन्यथा {
                            थांबा;
                        }
                    }
                }
                जर (tok == ':') {
                    /* goto labels */
                    next();
                    साठी (;;) {
                        Sym *csym;
                        पूर्णांक asmname;
                        जर (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        जर (tok < TOK_UIDENT)
                          expect("label identifier");
			स_रखो(operands + nb_operands + nb_labels, 0,
			       आकार(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        जर (!csym) {
                            csym = label_ढकला(&global_label_चळत, tok,
                                              LABEL_FORWARD);
                        } अन्यथा {
                            जर (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        जर (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        जर (tok != ',')
                          थांबा;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    जर (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    म_लिखो("asm: \"%s\"\n", (अक्षर *)astr.data);
#endif
    जर (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    म_लिखो("subst_asm: \"%s\"\n", (अक्षर *)astr.data);
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
    जर (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    साठी(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC शून्य asm_global_instr(शून्य)
{
    CString *astr;
    पूर्णांक saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    जर (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    म_लिखो("asm_global: \"%s\"\n", (अक्षर *)astr->data);
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
ST_FUNC पूर्णांक tcc_assemble(TCCState *s1, पूर्णांक do_preprocess)
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
