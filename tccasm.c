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
#அந்தர்பாவ "tcc.h"
#ifdef CONFIG_TCC_ASM

நிலையான Section *last_text_section; /* to handle .previous asm directive */
நிலையான முழு asmgoto_n;

நிலையான முழு tcc_assemble_internal(TCCState *s1, முழு do_preprocess, முழு global);
நிலையான Sym* asm_new_label(TCCState *s1, முழு label, முழு is_local);
நிலையான Sym* asm_new_label1(TCCState *s1, முழு label, முழு is_local, முழு sh_இலக்கம், முழு மதிப்பு);

#எனில் PTR_SIZE == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC வெறுமை gen_addr64(முழு r, Sym *sym, int64_t c)
{
    எனில் (r & VT_SYM)
        greloca(cur_text_section, sym, ind, R_DATA_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC வெறுமை gen_expr64(கோவை_மதிப்பு *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#endif

நிலையான முழு asm_get_prefix_name(TCCState *s1, மாறிலி எழுத்து *prefix, unsigned முழு n)
{
    எழுத்து buf[64];
    snprintf(buf, அளவு(buf), "%s%u", prefix, n);
    திரும்பு tok_alloc_const(buf);
}

ST_FUNC முழு asm_get_local_label_name(TCCState *s1, unsigned முழு n)
{
    திரும்பு asm_get_prefix_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
நிலையான முழு asm2cname(முழு v, முழு *addeddot)
{
    மாறிலி எழுத்து *name;
    *addeddot = 0;
    எனில் (!tcc_state->leading_underscore)
      திரும்பு v;
    name = get_tok_str(v, வெற்று);
    எனில் (!name)
      திரும்பு v;
    எனில் (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } இல்லையெனில் எனில் (!strchr(name, '.')) {
        எழுத்து newname[256];
        snprintf(newname, அளவு newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    திரும்பு v;
}

நிலையான Sym *asm_label_find(முழு v)
{
    Sym *sym;
    முழு addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_find(v);
    போது (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    திரும்பு sym;
}

நிலையான Sym *asm_label_தள்ளு(முழு v)
{
    முழு addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_தள்ளு(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    எனில் (addeddot)
        sym->asm_label = v;
    திரும்பு sym;
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
ST_FUNC Sym* get_asm_sym(முழு name, Sym *csym)
{
    Sym *sym = asm_label_find(name);
    எனில் (!sym) {
	sym = asm_label_தள்ளு(name);
	எனில் (csym)
	  sym->c = csym->c;
    }
    திரும்பு sym;
}

நிலையான Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    எழுத்து buf[100]; முழு label; Sym *sym;
    snprintf(buf, அளவு buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_find(label);
    திரும்பு sym ? sym : asm_new_label1(s1, label, 1, sec->sh_இலக்கம், 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

நிலையான வெறுமை asm_கோவை_unary(TCCState *s1, கோவை_மதிப்பு *pe)
{
    Sym *sym;
    முழு op, label;
    uint64_t n;
    மாறிலி எழுத்து *p;

    தேர்வு(tok) {
    நிலை TOK_PPNUM:
        p = tokc.str.data;
        n = strtoull(p, (எழுத்து **)&p, 0);
        எனில் (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_find(label);
            எனில் (*p == 'b') {
                /* backward : find the last corresponding defined label */
                எனில் (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                எனில் (!sym)
                    tcc_error("local label '%d' not found backward", (முழு)n);
            } இல்லையெனில் {
                /* forward */
                எனில் (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_தள்ளு(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } இல்லையெனில் எனில் (*p == '\0') {
            pe->v = n;
            pe->sym = வெற்று;
	    pe->pcrel = 0;
        } இல்லையெனில் {
            tcc_error("invalid number syntax");
        }
        next();
        நிறுத்து;
    நிலை '+':
        next();
        asm_கோவை_unary(s1, pe);
        நிறுத்து;
    நிலை '-':
    நிலை '~':
        op = tok;
        next();
        asm_கோவை_unary(s1, pe);
        எனில் (pe->sym)
            tcc_error("invalid operation with label");
        எனில் (op == '-')
            pe->v = -pe->v;
        இல்லையெனில்
            pe->v = ~pe->v;
        நிறுத்து;
    நிலை TOK_CCHAR:
    நிலை TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = வெற்று;
	pe->pcrel = 0;
	next();
	நிறுத்து;
    நிலை '(':
        next();
        asm_கோவை(s1, pe);
        skip(')');
        நிறுத்து;
    நிலை '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_text_section);
        pe->pcrel = 0;
        next();
        நிறுத்து;
    இயல்பு:
        எனில் (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, வெற்று);
	    esym = elfsym(sym);
            எனில் (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_மதிப்பு;
                pe->sym = வெற்று;
		pe->pcrel = 0;
            } இல்லையெனில் {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            next();
        } இல்லையெனில் {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        நிறுத்து;
    }
}
    
நிலையான வெறுமை asm_கோவை_prod(TCCState *s1, கோவை_மதிப்பு *pe)
{
    முழு op;
    கோவை_மதிப்பு e2;

    asm_கோவை_unary(s1, pe);
    க்கு(;;) {
        op = tok;
        எனில் (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            நிறுத்து;
        next();
        asm_கோவை_unary(s1, &e2);
        எனில் (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        தேர்வு(op) {
        நிலை '*':
            pe->v *= e2.v;
            நிறுத்து;
        நிலை '/':  
            எனில் (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            நிறுத்து;
        நிலை '%':  
            எனில் (e2.v == 0)
                செல் div_error;
            pe->v %= e2.v;
            நிறுத்து;
        நிலை TOK_SHL:
            pe->v <<= e2.v;
            நிறுத்து;
        இயல்பு:
        நிலை TOK_SAR:
            pe->v >>= e2.v;
            நிறுத்து;
        }
    }
}

நிலையான வெறுமை asm_கோவை_logic(TCCState *s1, கோவை_மதிப்பு *pe)
{
    முழு op;
    கோவை_மதிப்பு e2;

    asm_கோவை_prod(s1, pe);
    க்கு(;;) {
        op = tok;
        எனில் (op != '&' && op != '|' && op != '^')
            நிறுத்து;
        next();
        asm_கோவை_prod(s1, &e2);
        எனில் (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        தேர்வு(op) {
        நிலை '&':
            pe->v &= e2.v;
            நிறுத்து;
        நிலை '|':  
            pe->v |= e2.v;
            நிறுத்து;
        இயல்பு:
        நிலை '^':
            pe->v ^= e2.v;
            நிறுத்து;
        }
    }
}

நிலையான உள்வரி வெறுமை asm_கோவை_sum(TCCState *s1, கோவை_மதிப்பு *pe)
{
    முழு op;
    கோவை_மதிப்பு e2;

    asm_கோவை_logic(s1, pe);
    க்கு(;;) {
        op = tok;
        எனில் (op != '+' && op != '-')
            நிறுத்து;
        next();
        asm_கோவை_logic(s1, &e2);
        எனில் (op == '+') {
            எனில் (pe->sym != வெற்று && e2.sym != வெற்று)
                செல் cannot_relocate;
            pe->v += e2.v;
            எனில் (pe->sym == வெற்று && e2.sym != வெற்று)
                pe->sym = e2.sym;
        } இல்லையெனில் {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    எனில் (!e2.sym) {
		/* OK */
	    } இல்லையெனில் எனில் (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = வெற்று; /* same symbols can be subtracted to NULL */
	    } இல்லையெனில் {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		எனில் (!esym2)
		    செல் cannot_relocate;
		எனில் (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (முழு)(esym1->st_மதிப்பு - esym2->st_மதிப்பு);
		    pe->sym = வெற்று;
		} இல்லையெனில் எனில் (esym2->st_shndx == cur_text_section->sh_இலக்கம்) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (முழு)(0 - esym2->st_மதிப்பு);
		    pe->pcrel = 1;
		    e2.sym = வெற்று;
		} இல்லையெனில் {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

நிலையான உள்வரி வெறுமை asm_கோவை_cmp(TCCState *s1, கோவை_மதிப்பு *pe)
{
    முழு op;
    கோவை_மதிப்பு e2;

    asm_கோவை_sum(s1, pe);
    க்கு(;;) {
        op = tok;
	எனில் (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            நிறுத்து;
        next();
        asm_கோவை_sum(s1, &e2);
        எனில் (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        தேர்வு(op) {
	நிலை TOK_EQ:
	    pe->v = pe->v == e2.v;
	    நிறுத்து;
	நிலை TOK_NE:
	    pe->v = pe->v != e2.v;
	    நிறுத்து;
	நிலை TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    நிறுத்து;
	நிலை TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    நிறுத்து;
	நிலை TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    நிறுத்து;
	நிலை TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    நிறுத்து;
        இயல்பு:
            நிறுத்து;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC வெறுமை asm_கோவை(TCCState *s1, கோவை_மதிப்பு *pe)
{
    asm_கோவை_cmp(s1, pe);
}

ST_FUNC முழு asm_int_கோவை(TCCState *s1)
{
    கோவை_மதிப்பு e;
    asm_கோவை(s1, &e);
    எனில் (e.sym)
        expect("constant");
    எனில் ((முழு)e.v != e.v)
	tcc_error("integer out of range %lld", (long long)e.v);
    திரும்பு e.v;
}

நிலையான Sym* asm_new_label1(TCCState *s1, முழு label, முழு is_local,
                           முழு sh_இலக்கம், முழு மதிப்பு)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_find(label);
    எனில் (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        எனில் (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            எனில் (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                செல் new_label;
            எனில் (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, வெற்று));
        }
    } இல்லையெனில் {
    new_label:
        sym = asm_label_தள்ளு(label);
    }
    எனில் (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_இலக்கம்;
    esym->st_மதிப்பு = மதிப்பு;
    எனில் (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    திரும்பு sym;
}

நிலையான Sym* asm_new_label(TCCState *s1, முழு label, முழு is_local)
{
    திரும்பு asm_new_label1(s1, label, is_local, cur_text_section->sh_இலக்கம், ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
நிலையான Sym* set_குறியீடு(TCCState *s1, முழு label)
{
    long n;
    கோவை_மதிப்பு e;
    Sym *sym;
    ElfSym *esym;
    next();
    asm_கோவை(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    எனில் (esym)
	n += esym->st_மதிப்பு;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_SET;
    திரும்பு sym;
}

நிலையான வெறுமை use_section1(TCCState *s1, Section *sec)
{
    cur_text_section->data_offset = ind;
    cur_text_section = sec;
    ind = cur_text_section->data_offset;
}

நிலையான வெறுமை use_section(TCCState *s1, மாறிலி எழுத்து *name)
{
    Section *sec;
    sec = find_section(s1, name);
    use_section1(s1, sec);
}

நிலையான வெறுமை தள்ளு_section(TCCState *s1, மாறிலி எழுத்து *name)
{
    Section *sec = find_section(s1, name);
    sec->prev = cur_text_section;
    use_section1(s1, sec);
}

நிலையான வெறுமை எடு_section(TCCState *s1)
{
    Section *prev = cur_text_section->prev;
    எனில் (!prev)
        tcc_error(".popsection without .pushsection");
    cur_text_section->prev = வெற்று;
    use_section1(s1, prev);
}

நிலையான வெறுமை asm_parse_directive(TCCState *s1, முழு global)
{
    முழு n, offset, v, size, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_text_section;
    தேர்வு(tok) {
    நிலை TOK_ASMDIR_align:
    நிலை TOK_ASMDIR_balign:
    நிலை TOK_ASMDIR_p2align:
    நிலை TOK_ASMDIR_skip:
    நிலை TOK_ASMDIR_space:
        tok1 = tok;
        next();
        n = asm_int_கோவை(s1);
        எனில் (tok1 == TOK_ASMDIR_p2align)
        {
            எனில் (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        எனில் (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            எனில் (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            offset = (ind + n - 1) & -n;
            size = offset - ind;
            /* the section must have a compatible alignment */
            எனில் (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } இல்லையெனில் {
	    எனில் (n < 0)
	        n = 0;
            size = n, c = 0;
        }
        v = 0;
        எனில் (tok == ',') {
            next();
            v = asm_int_கோவை(s1), c = 0;
        }
    zero_pad:
	எனில் ((uint64_t)ind + size >= 1<<30)
	    tcc_error("too much data");
        எனில் (sec->sh_type != SHT_NOBITS) {
            எனில் (c) {
                gen_fill_nops(size);
                நிறுத்து;
            }
            sec->data_offset = ind;
            ptr = section_ptr_add(sec, size);
            memset(ptr, v, size);
        }
        ind += size;
        நிறுத்து;
    நிலை TOK_ASMDIR_quad:
#எனில் PTR_SIZE == 8
	size = 8;
	செல் asm_data;
#இல்லையெனில்
        next();
        க்கு(;;) {
            uint64_t vl;
            மாறிலி எழுத்து *p;

            p = tokc.str.data;
            எனில் (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (எழுத்து **)&p, 0);
            எனில் (*p != '\0')
                செல் error_constant;
            next();
            எனில் (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } இல்லையெனில் {
                ind += 8;
            }
            எனில் (tok != ',')
                நிறுத்து;
            next();
        }
        நிறுத்து;
#endif
    நிலை TOK_ASMDIR_byte:
        size = 1;
        செல் asm_data;
    நிலை TOK_ASMDIR_word:
    நிலை TOK_ASMDIR_short:
        size = 2;
        செல் asm_data;
    நிலை TOK_ASMDIR_long:
    நிலை TOK_ASMDIR_int:
        size = 4;
    asm_data:
        next();
        க்கு(;;) {
            கோவை_மதிப்பு e;
            asm_கோவை(s1, &e);
            எனில் (sec->sh_type != SHT_NOBITS) {
                எனில் (size == 4) {
                    gen_expr32(&e);
#எனில் PTR_SIZE == 8
		} இல்லையெனில் எனில் (size == 8) {
		    gen_expr64(&e);
#endif
                } இல்லையெனில் {
                    எனில் (e.sym)
                        expect("constant");
                    எனில் (size == 1)
                        g(e.v);
                    இல்லையெனில்
                        gen_le16(e.v);
                }
            } இல்லையெனில் {
                ind += size;
            }
            எனில் (tok != ',')
                நிறுத்து;
            next();
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_fill:
        {
            முழு repeat, size, val, i, j;
            uint8_t repeat_buf[8];
            next();
            repeat = asm_int_கோவை(s1);
            எனில் (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                நிறுத்து;
            }
            size = 1;
            val = 0;
            எனில் (tok == ',') {
                next();
                size = asm_int_கோவை(s1);
                எனில் (size < 0) {
                    tcc_error("size < 0; .fill ignored");
                    நிறுத்து;
                }
                எனில் (size > 8)
                    size = 8;
                எனில் (tok == ',') {
                    next();
                    val = asm_int_கோவை(s1);
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
            க்கு(i = 0; i < repeat; i++) {
                க்கு(j = 0; j < size; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_rept:
        {
            முழு repeat;
            TokenString *init_str;
            next();
            repeat = asm_int_கோவை(s1);
            init_str = tok_str_alloc();
            போது (next(), tok != TOK_ASMDIR_endr) {
                எனில் (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_add_tok(init_str);
            }
            tok_str_add(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            போது (repeat-- > 0) {
                tcc_assemble_internal(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            end_macro();
            next();
            நிறுத்து;
        }
    நிலை TOK_ASMDIR_org:
        {
	    கோவை_மதிப்பு e;
	    ElfSym *esym;
            next();
	    asm_கோவை(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    எனில் (esym) {
		எனில் (esym->st_shndx != cur_text_section->sh_இலக்கம்)
		  expect("constant or same-section symbol");
		n += esym->st_மதிப்பு;
	    }
            எனில் (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            size = n - ind;
            செல் zero_pad;
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_set:
	next();
	tok1 = tok;
	next();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	எனில் (tok == ',')
	    set_குறியீடு(s1, tok1);
	நிறுத்து;
    நிலை TOK_ASMDIR_globl:
    நிலை TOK_ASMDIR_global:
    நிலை TOK_ASMDIR_weak:
    நிலை TOK_ASMDIR_hidden:
	tok1 = tok;
	செய் { 
            Sym *sym;
            next();
	    எனில் (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, வெற்று);
	    எனில் (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            எனில் (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    இல்லையெனில் எனில் (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            next();
	} போது (tok == ',');
	நிறுத்து;
    நிலை TOK_ASMDIR_string:
    நிலை TOK_ASMDIR_ascii:
    நிலை TOK_ASMDIR_asciz:
        {
            மாறிலி எழுத்து *p;
            முழு i, size, t;

            t = tok;
            next();
            க்கு(;;) {
                எனில் (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.data;
                size = tokc.str.size;
                எனில் (t == TOK_ASMDIR_ascii && size > 0)
                    size--;
                க்கு(i = 0; i < size; i++)
                    g(p[i]);
                next();
                எனில் (tok == ',') {
                    next();
                } இல்லையெனில் எனில் (tok != TOK_STR) {
                    நிறுத்து;
                }
            }
	}
	நிறுத்து;
    நிலை TOK_ASMDIR_text:
    நிலை TOK_ASMDIR_data:
    நிலை TOK_ASMDIR_bss:
	{ 
            எழுத்து sname[64];
            tok1 = tok;
            n = 0;
            next();
            எனில் (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_கோவை(s1);
		next();
            }
            எனில் (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, வெற்று), n);
            இல்லையெனில்
                sprintf(sname, "%s", get_tok_str(tok1, வெற்று));
            use_section(s1, sname);
	}
	நிறுத்து;
    நிலை TOK_ASMDIR_file:
        {
            மாறிலி எழுத்து *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            next();
            எனில் (tok == TOK_PPNUM)
                next();
            எனில் (tok == TOK_PPSTR && tokc.str.data[0] == '"') {
                tokc.str.data[tokc.str.size - 2] = 0;
                p = tokc.str.data + 1;
            } இல்லையெனில் எனில் (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } இல்லையெனில் {
                skip_to_eol(0);
                நிறுத்து;
            }
            tccpp_putfile(p);
            next();
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_ident:
        {
            எழுத்து ident[256];

            ident[0] = '\0';
            next();
            எனில் (tok == TOK_STR)
                pstrcat(ident, அளவு(ident), tokc.str.data);
            இல்லையெனில்
                pstrcat(ident, அளவு(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            next();
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_size:
        { 
            Sym *sym;
            ElfSym *esym;

            next();
	    எனில் (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_find(tok);
            எனில் (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, வெற்று));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, வெற்று));
            next();
            skip(',');
            n = asm_int_கோவை(s1);
            esym = elfsym(sym);
            எனில் (esym) {
                esym->st_size = n;
            }
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_type:
        { 
            Sym *sym;
            மாறிலி எழுத்து *newtype;
            முழு st_type;

            next();
	    எனில் (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, வெற்று);
            next();
            skip(',');
            எனில் (tok == TOK_STR) {
                newtype = tokc.str.data;
            } இல்லையெனில் {
                எனில் (tok == '@' || tok == '%')
                    next();
                newtype = get_tok_str(tok, வெற்று);
            }

            எனில் (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                எனில் (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            set_st_type:
                எனில் (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } இல்லையெனில் எனில் (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                செல் set_st_type;
            } இல்லையெனில்
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, வெற்று), sym->type.t, newtype);

            next();
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_pushsection:
    நிலை TOK_ASMDIR_section:
        {
            எழுத்து sname[256];
	    முழு old_nb_section = s1->nb_sections;
            முழு flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            next();
            sname[0] = '\0';
            போது (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                எனில் (tok == TOK_STR)
                    pstrcat(sname, அளவு(sname), tokc.str.data);
                இல்லையெனில்
                    pstrcat(sname, அளவு(sname), get_tok_str(tok, வெற்று));
                next();
            }
            எனில் (tok == ',') {
                மாறிலி எழுத்து *p;
                /* skip section options */
                next();
                எனில் (tok != TOK_STR)
                    expect("string constant");
                க்கு (p = tokc.str.data; *p; ++p) {
                    எனில் (*p == 'w')
                        flags |= SHF_WRITE;
                    எனில் (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                next();
                எனில் (tok == ',') {
                    next();
                    எனில் (tok == '@' || tok == '%')
                        next();
                    next();
                }
            }
            last_text_section = cur_text_section;
	    எனில் (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    இல்லையெனில்
	        தள்ளு_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    எனில் (old_nb_section != s1->nb_sections) {
	        cur_text_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                எனில் (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_text_section->sh_flags = flags;
            }
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_previous:
        { 
            Section *sec;
            next();
            எனில் (!last_text_section)
                tcc_error("no previous section referenced");
            sec = cur_text_section;
            use_section1(s1, last_text_section);
            last_text_section = sec;
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_popsection:
	next();
	எடு_section(s1);
	நிறுத்து;
#ifdef TCC_TARGET_I386
    நிலை TOK_ASMDIR_code16:
        {
            next();
            s1->seg_size = 16;
        }
        நிறுத்து;
    நிலை TOK_ASMDIR_code32:
        {
            next();
            s1->seg_size = 32;
        }
        நிறுத்து;
#endif
#எனில் PTR_SIZE == 8
    /* added for compatibility with GAS */
    நிலை TOK_ASMDIR_code64:
        next();
        நிறுத்து;
#endif
#ifdef TCC_TARGET_RISCV64
    நிலை TOK_ASMDIR_option:
        next();
        தேர்வு(tok){
            நிலை TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            நிலை TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            நிலை TOK_ASM_pic:
            நிலை TOK_ASM_nopic:
            நிலை TOK_ASM_relax:
            நிலை TOK_ASM_norelax:
            நிலை TOK_ASM_தள்ளு:
            நிலை TOK_ASM_எடு:
                /* TODO: unimplemented */
                next();
                நிறுத்து;
            நிலை TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, வெற்று));
                நிறுத்து;
            இயல்பு:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, வெற்று));
                நிறுத்து;
        }
        நிறுத்து;
#endif
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    நிலை TOK_ASMDIR_symver:
	next();
	next();
        skip(',');
	next();
        skip('@');
	next();
	நிறுத்து;
    நிலை TOK_ASMDIR_reloc:
	{
	    கோவை_மதிப்பு e;
	    மாறிலி எழுத்து *reloc_name;
	    முழு reloc_type = -1;

	    next();
	    asm_கோவை(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, வெற்று);
#எனில் defined(TCC_TARGET_ARM64)
	    எனில் (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#அல்லதெனில் defined(TCC_TARGET_RISCV64)
	    எனில் (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    இல்லையெனில் எனில் (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#endif
	    எனில் (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    next();
	    skip(',');
	    greloca(cur_text_section, get_asm_sym(tok, வெற்று), e.v, reloc_type, 0);
	    next();
	}
	நிறுத்து;
    இயல்பு:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, வெற்று));
        நிறுத்து;
    }
}


/* assemble a file */
நிலையான முழு tcc_assemble_internal(TCCState *s1, முழு do_preprocess, முழு global)
{
    முழு opcode;
    முழு saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    எனில் (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    க்கு(;;) {
        next();
        எனில் (tok == TOK_EOF)
            நிறுத்து;
        tcc_debug_வரி(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#எனில் !defined(TCC_TARGET_ARM64)
        எனில் (tok == '#') {
            /* horrible gas comment */
            போது (tok != TOK_LINEFEED)
                next();
        } இல்லையெனில்
#endif
        எனில் (tok >= TOK_ASMDIR_FIRST && tok <= TOK_ASMDIR_LAST) {
            asm_parse_directive(s1, global);
        } இல்லையெனில் எனில் (tok == TOK_PPNUM) {
            மாறிலி எழுத்து *p;
            முழு n;
            p = tokc.str.data;
            n = strtoul(p, (எழுத்து **)&p, 10);
            எனில் (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            next();
            skip(':');
            செல் redo;
        } இல்லையெனில் எனில் (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            next();
            எனில் (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                next();
                செல் redo;
            } இல்லையெனில் எனில் (tok == '=') {
		set_குறியீடு(s1, opcode);
                செல் redo;
            } இல்லையெனில் {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        எனில் (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    திரும்பு 0;
}

/* Assemble the current file */
ST_FUNC முழு tcc_assemble(TCCState *s1, முழு do_preprocess)
{
    முழு ret;
    tcc_debug_start(s1);
    /* default section is text */
    cur_text_section = text_section;
    ind = cur_text_section->data_offset;
    nocode_wanted = 0;
    ret = tcc_assemble_internal(s1, do_preprocess, 1);
    cur_text_section->data_offset = ind;
    tcc_debug_end(s1);
    திரும்பு ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
நிலையான வெறுமை tcc_assemble_inline(TCCState *s1, மாறிலி எழுத்து *str, முழு len, முழு global)
{
    மாறிலி முழு *saved_macro_ptr = macro_ptr;
    முழு dotid = set_idnum('.', IS_ID);
#எனில் !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    முழு dolid = set_idnum('$', 0);
#endif

    tcc_open_bf(s1, ":asm:", len);
    memcpy(file->buffer, str, len);
    macro_ptr = வெற்று;
    tcc_assemble_internal(s1, 0, global);
    tcc_close();

#எனில் !defined(TCC_TARGET_RISCV64) && !defined(TCC_TARGET_X86_64)
    set_idnum('$', dolid);
#endif
    set_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC முழு find_constraint(ASMOperand *operands, முழு nb_operands, 
                           மாறிலி எழுத்து *name, மாறிலி எழுத்து **pp)
{
    முழு index;
    TokenSym *ts;
    மாறிலி எழுத்து *p;

    எனில் (isnum(*name)) {
        index = 0;
        போது (isnum(*name)) {
            index = (index * 10) + (*name) - '0';
            name++;
        }
        எனில் ((unsigned)index >= nb_operands)
            index = -1;
    } இல்லையெனில் எனில் (*name == '[') {
        name++;
        p = strchr(name, ']');
        எனில் (p) {
            ts = tok_alloc(name, p - name);
            க்கு(index = 0; index < nb_operands; index++) {
                எனில் (operands[index].id == ts->tok)
                    செல் found;
            }
            index = -1;
        found:
            name = p + 1;
        } இல்லையெனில் {
            index = -1;
        }
    } இல்லையெனில் {
        index = -1;
    }
    எனில் (pp)
        *pp = name;
    திரும்பு index;
}

நிலையான வெறுமை subst_asm_operands(ASMOperand *operands, முழு nb_operands, 
                               CString *out_str, மாறிலி எழுத்து *str)
{
    முழு c, index, modifier;
    ASMOperand *op;
    SValue sv;

    க்கு(;;) {
        c = *str++;
        எனில் (c == '%') {
            எனில் (*str == '%') {
                str++;
                செல் add_char;
            }
            modifier = 0;
            எனில் (*str == 'c' || *str == 'n' ||
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
            எனில் (index < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[index];
            எனில் (modifier == 'l') {
                cstr_cat(out_str, get_tok_str(op->is_label, வெற்று), -1);
            } இல்லையெனில் {
		எனில் (op->vt == வெற்று)
		    செல் error;
                sv = *op->vt;
                எனில் (op->reg >= 0) {
                    sv.r = op->reg;
                    எனில் (op->is_memory)
                      sv.r |= VT_LVAL;
                }
                subst_asm_operand(out_str, &sv, modifier);
            }
        } இல்லையெனில் {
        add_char:
            cstr_ccat(out_str, c);
            எனில் (c == '\0')
                நிறுத்து;
        }
    }
}


நிலையான வெறுமை parse_asm_operands(ASMOperand *operands, முழு *nb_operands_ptr,
                               முழு is_output)
{
    ASMOperand *op;
    முழு nb_operands;
    எழுத்து* astr;

    எனில் (tok != ':') {
        nb_operands = *nb_operands_ptr;
        க்கு(;;) {
            எனில் (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            எனில் (tok == '[') {
                next();
                எனில் (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                next();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->data;
            pstrcpy(op->constraint, அளவு op->constraint, astr);
            skip('(');
            gexpr();
            எனில் (is_output) {
                எனில் (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } இல்லையெனில் {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                எனில் ((vtop->r & VT_LVAL) &&
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
            எனில் (tok == ',') {
                next();
            } இல்லையெனில் {
                நிறுத்து;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC வெறுமை asm_instr(வெறுமை)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    முழு nb_outputs, nb_operands, i, must_subst, out_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    போது (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
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
    memset(clobber_regs, 0, அளவு(clobber_regs));
    எனில் (tok == ':') {
        next();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        எனில் (tok == ':') {
            next();
            எனில் (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                எனில் (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    next();
                    க்கு(;;) {
                        எனில் (tok == ':')
                          நிறுத்து;
                        எனில் (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.data);
                        next();
                        எனில் (tok == ',') {
                            next();
                        } இல்லையெனில் {
                            நிறுத்து;
                        }
                    }
                }
                எனில் (tok == ':') {
                    /* goto labels */
                    next();
                    க்கு (;;) {
                        Sym *csym;
                        முழு asmname;
                        எனில் (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        எனில் (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       அளவு(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_find(tok);
                        எனில் (!csym) {
                            csym = label_தள்ளு(&global_label_அடுக்கு, tok,
                                              LABEL_FORWARD);
                        } இல்லையெனில் {
                            எனில் (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        next();
                        asmname = asm_get_prefix_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        எனில் (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        எனில் (tok != ',')
                          நிறுத்து;
                        next();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    எனில் (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &out_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#ifdef ASM_DEBUG
    printf("asm: \"%s\"\n", (எழுத்து *)astr.data);
#endif
    எனில் (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.data, astr.size);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->data);
    }

#ifdef ASM_DEBUG
    printf("subst_asm: \"%s\"\n", (எழுத்து *)astr.data);
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
    எனில் (sec != cur_text_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    next();

    /* store the output values if needed */
    asm_gen_code(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, out_reg);
    
    /* free everything */
    க்கு(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC வெறுமை asm_global_instr(வெறுமை)
{
    CString *astr;
    முழு saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    next();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    எனில் (tok != ';')
        expect("';'");
    
#ifdef ASM_DEBUG
    printf("asm_global: \"%s\"\n", (எழுத்து *)astr->data);
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
#இல்லையெனில்
ST_FUNC முழு tcc_assemble(TCCState *s1, முழு do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC வெறுமை asm_instr(வெறுமை)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC வெறுமை asm_global_instr(வெறுமை)
{
    tcc_error("inline asm() not supported");
}
#endif /* CONFIG_TCC_ASM */
