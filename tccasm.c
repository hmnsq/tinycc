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

#تعریف_کن USING_GLOBALS
#ضمن "tcc.h"
#اگر_تعریف_شده CONFIG_TCC_ASM

ساكن Section *آخرین_متن_section; /* to handle .previous asm directive */
ساكن صحيح asmgoto_n;

ساكن صحيح tcc_assemble_داخلی(TCCState *s1, صحيح do_preprocess, صحيح global);
ساكن Sym* asm_new_label(TCCState *s1, صحيح label, صحيح is_local);
ساكن Sym* asm_new_label1(TCCState *s1, صحيح label, صحيح is_local, صحيح sh_رقم, صحيح مقدار);

#إذا PTR_اندازه == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC فراغ gen_addr64(صحيح r, Sym *sym, int64_t c)
{
    إذا (r & VT_SYM)
        greloca(cur_متن_section, sym, ind, R_داده_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC فراغ gen_expr64(عبارت_مقدار *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#پایان_اگر

ساكن صحيح asm_get_پیشوند_name(TCCState *s1, ثابت حرف *پیشوند, بیعلامت صحيح n)
{
    حرف buf[64];
    snprintf(buf, حجم(buf), "%s%u", پیشوند, n);
    أرجع tok_alloc_const(buf);
}

ST_FUNC صحيح asm_get_local_label_name(TCCState *s1, بیعلامت صحيح n)
{
    أرجع asm_get_پیشوند_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ساكن صحيح asm2cname(صحيح v, صحيح *addeddot)
{
    ثابت حرف *name;
    *addeddot = 0;
    إذا (!tcc_state->leading_underscore)
      أرجع v;
    name = get_tok_str(v, عدم);
    إذا (!name)
      أرجع v;
    إذا (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } وإلا إذا (!strchr(name, '.')) {
        حرف newname[256];
        snprintf(newname, حجم newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    أرجع v;
}

ساكن Sym *asm_label_پیدا_کن(صحيح v)
{
    Sym *sym;
    صحيح addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_پیدا_کن(v);
    طالما (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->prev_tok;
    أرجع sym;
}

ساكن Sym *asm_label_افزودن(صحيح v)
{
    صحيح addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_افزودن(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    إذا (addeddot)
        sym->asm_label = v;
    أرجع sym;
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
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym)
{
    Sym *sym = asm_label_پیدا_کن(name);
    إذا (!sym) {
	sym = asm_label_افزودن(name);
	إذا (csym)
	  sym->c = csym->c;
    }
    أرجع sym;
}

ساكن Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    حرف buf[100]; صحيح label; Sym *sym;
    snprintf(buf, حجم buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_پیدا_کن(label);
    أرجع sym ? sym : asm_new_label1(s1, label, 1, sec->sh_رقم, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ساكن فراغ asm_عبارت_unary(TCCState *s1, عبارت_مقدار *pe)
{
    Sym *sym;
    صحيح op, label;
    uint64_t n;
    ثابت حرف *p;

    بدل(tok) {
    حالة TOK_PPNUM:
        p = tokc.str.داده;
        n = strtoull(p, (حرف **)&p, 0);
        إذا (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_پیدا_کن(label);
            إذا (*p == 'b') {
                /* backward : find the last corresponding defined label */
                إذا (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->prev_tok;
                إذا (!sym)
                    tcc_error("local label '%d' not found backward", (صحيح)n);
            } وإلا {
                /* forward */
                إذا (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_افزودن(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } وإلا إذا (*p == '\0') {
            pe->v = n;
            pe->sym = عدم;
	    pe->pcrel = 0;
        } وإلا {
            tcc_error("invalid number syntax");
        }
        بعدی();
        اكسر;
    حالة '+':
        بعدی();
        asm_عبارت_unary(s1, pe);
        اكسر;
    حالة '-':
    حالة '~':
        op = tok;
        بعدی();
        asm_عبارت_unary(s1, pe);
        إذا (pe->sym)
            tcc_error("invalid operation with label");
        إذا (op == '-')
            pe->v = -pe->v;
        وإلا
            pe->v = ~pe->v;
        اكسر;
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = عدم;
	pe->pcrel = 0;
	بعدی();
	اكسر;
    حالة '(':
        بعدی();
        asm_عبارت(s1, pe);
        skip(')');
        اكسر;
    حالة '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_متن_section);
        pe->pcrel = 0;
        بعدی();
        اكسر;
    افتراضي:
        إذا (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, عدم);
	    esym = elfsym(sym);
            إذا (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_مقدار;
                pe->sym = عدم;
		pe->pcrel = 0;
            } وإلا {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            بعدی();
        } وإلا {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        اكسر;
    }
}
    
ساكن فراغ asm_عبارت_prod(TCCState *s1, عبارت_مقدار *pe)
{
    صحيح op;
    عبارت_مقدار e2;

    asm_عبارت_unary(s1, pe);
    لكل(;;) {
        op = tok;
        إذا (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            اكسر;
        بعدی();
        asm_عبارت_unary(s1, &e2);
        إذا (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        بدل(op) {
        حالة '*':
            pe->v *= e2.v;
            اكسر;
        حالة '/':  
            إذا (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            اكسر;
        حالة '%':  
            إذا (e2.v == 0)
                اذهب div_error;
            pe->v %= e2.v;
            اكسر;
        حالة TOK_SHL:
            pe->v <<= e2.v;
            اكسر;
        افتراضي:
        حالة TOK_SAR:
            pe->v >>= e2.v;
            اكسر;
        }
    }
}

ساكن فراغ asm_عبارت_logic(TCCState *s1, عبارت_مقدار *pe)
{
    صحيح op;
    عبارت_مقدار e2;

    asm_عبارت_prod(s1, pe);
    لكل(;;) {
        op = tok;
        إذا (op != '&' && op != '|' && op != '^')
            اكسر;
        بعدی();
        asm_عبارت_prod(s1, &e2);
        إذا (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        بدل(op) {
        حالة '&':
            pe->v &= e2.v;
            اكسر;
        حالة '|':  
            pe->v |= e2.v;
            اكسر;
        افتراضي:
        حالة '^':
            pe->v ^= e2.v;
            اكسر;
        }
    }
}

ساكن مضمن فراغ asm_عبارت_جمع(TCCState *s1, عبارت_مقدار *pe)
{
    صحيح op;
    عبارت_مقدار e2;

    asm_عبارت_logic(s1, pe);
    لكل(;;) {
        op = tok;
        إذا (op != '+' && op != '-')
            اكسر;
        بعدی();
        asm_عبارت_logic(s1, &e2);
        إذا (op == '+') {
            إذا (pe->sym != عدم && e2.sym != عدم)
                اذهب cannot_relocate;
            pe->v += e2.v;
            إذا (pe->sym == عدم && e2.sym != عدم)
                pe->sym = e2.sym;
        } وإلا {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    إذا (!e2.sym) {
		/* OK */
	    } وإلا إذا (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = عدم; /* same symbols can be subtracted to NULL */
	    } وإلا {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		إذا (!esym2)
		    اذهب cannot_relocate;
		إذا (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (صحيح)(esym1->st_مقدار - esym2->st_مقدار);
		    pe->sym = عدم;
		} وإلا إذا (esym2->st_shndx == cur_متن_section->sh_رقم) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (صحيح)(0 - esym2->st_مقدار);
		    pe->pcrel = 1;
		    e2.sym = عدم;
		} وإلا {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ساكن مضمن فراغ asm_عبارت_cmp(TCCState *s1, عبارت_مقدار *pe)
{
    صحيح op;
    عبارت_مقدار e2;

    asm_عبارت_جمع(s1, pe);
    لكل(;;) {
        op = tok;
	إذا (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            اكسر;
        بعدی();
        asm_عبارت_جمع(s1, &e2);
        إذا (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        بدل(op) {
	حالة TOK_EQ:
	    pe->v = pe->v == e2.v;
	    اكسر;
	حالة TOK_NE:
	    pe->v = pe->v != e2.v;
	    اكسر;
	حالة TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    اكسر;
	حالة TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    اكسر;
	حالة TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    اكسر;
	حالة TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    اكسر;
        افتراضي:
            اكسر;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC فراغ asm_عبارت(TCCState *s1, عبارت_مقدار *pe)
{
    asm_عبارت_cmp(s1, pe);
}

ST_FUNC صحيح asm_int_عبارت(TCCState *s1)
{
    عبارت_مقدار e;
    asm_عبارت(s1, &e);
    إذا (e.sym)
        expect("constant");
    إذا ((صحيح)e.v != e.v)
	tcc_error("integer out of range %lld", (دراز دراز)e.v);
    أرجع e.v;
}

ساكن Sym* asm_new_label1(TCCState *s1, صحيح label, صحيح is_local,
                           صحيح sh_رقم, صحيح مقدار)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_پیدا_کن(label);
    إذا (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        إذا (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            إذا (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                اذهب new_label;
            إذا (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, عدم));
        }
    } وإلا {
    new_label:
        sym = asm_label_افزودن(label);
    }
    إذا (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_رقم;
    esym->st_مقدار = مقدار;
    إذا (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    أرجع sym;
}

ساكن Sym* asm_new_label(TCCState *s1, صحيح label, صحيح is_local)
{
    أرجع asm_new_label1(s1, label, is_local, cur_متن_section->sh_رقم, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ساكن Sym* مجموعه_نماد(TCCState *s1, صحيح label)
{
    دراز n;
    عبارت_مقدار e;
    Sym *sym;
    ElfSym *esym;
    بعدی();
    asm_عبارت(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    إذا (esym)
	n += esym->st_مقدار;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_مجموعه;
    أرجع sym;
}

ساكن فراغ use_section1(TCCState *s1, Section *sec)
{
    cur_متن_section->داده_جابه_جایی = ind;
    cur_متن_section = sec;
    ind = cur_متن_section->داده_جابه_جایی;
}

ساكن فراغ use_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec;
    sec = پیدا_کن_section(s1, name);
    use_section1(s1, sec);
}

ساكن فراغ افزودن_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec = پیدا_کن_section(s1, name);
    sec->prev = cur_متن_section;
    use_section1(s1, sec);
}

ساكن فراغ برداشت_section(TCCState *s1)
{
    Section *prev = cur_متن_section->prev;
    إذا (!prev)
        tcc_error(".popsection without .pushsection");
    cur_متن_section->prev = عدم;
    use_section1(s1, prev);
}

ساكن فراغ asm_parse_directive(TCCState *s1, صحيح global)
{
    صحيح n, جابه_جایی, v, اندازه, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_متن_section;
    بدل(tok) {
    حالة TOK_ASMDIR_align:
    حالة TOK_ASMDIR_balign:
    حالة TOK_ASMDIR_p2align:
    حالة TOK_ASMDIR_skip:
    حالة TOK_ASMDIR_space:
        tok1 = tok;
        بعدی();
        n = asm_int_عبارت(s1);
        إذا (tok1 == TOK_ASMDIR_p2align)
        {
            إذا (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        إذا (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            إذا (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            جابه_جایی = (ind + n - 1) & -n;
            اندازه = جابه_جایی - ind;
            /* the section must have a compatible alignment */
            إذا (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } وإلا {
	    إذا (n < 0)
	        n = 0;
            اندازه = n, c = 0;
        }
        v = 0;
        إذا (tok == ',') {
            بعدی();
            v = asm_int_عبارت(s1), c = 0;
        }
    zero_pad:
	إذا ((uint64_t)ind + اندازه >= 1<<30)
	    tcc_error("too much data");
        إذا (sec->sh_type != SHT_NOBITS) {
            إذا (c) {
                gen_fill_nops(اندازه);
                اكسر;
            }
            sec->داده_جابه_جایی = ind;
            ptr = section_ptr_جمع_کن(sec, اندازه);
            memset(ptr, v, اندازه);
        }
        ind += اندازه;
        اكسر;
    حالة TOK_ASMDIR_quad:
#إذا PTR_اندازه == 8
	اندازه = 8;
	اذهب asm_داده;
#وإلا
        بعدی();
        لكل(;;) {
            uint64_t vl;
            ثابت حرف *p;

            p = tokc.str.داده;
            إذا (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (حرف **)&p, 0);
            إذا (*p != '\0')
                اذهب error_constant;
            بعدی();
            إذا (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } وإلا {
                ind += 8;
            }
            إذا (tok != ',')
                اكسر;
            بعدی();
        }
        اكسر;
#پایان_اگر
    حالة TOK_ASMDIR_byte:
        اندازه = 1;
        اذهب asm_داده;
    حالة TOK_ASMDIR_کلمه:
    حالة TOK_ASMDIR_short:
        اندازه = 2;
        اذهب asm_داده;
    حالة TOK_ASMDIR_long:
    حالة TOK_ASMDIR_int:
        اندازه = 4;
    asm_داده:
        بعدی();
        لكل(;;) {
            عبارت_مقدار e;
            asm_عبارت(s1, &e);
            إذا (sec->sh_type != SHT_NOBITS) {
                إذا (اندازه == 4) {
                    gen_expr32(&e);
#إذا PTR_اندازه == 8
		} وإلا إذا (اندازه == 8) {
		    gen_expr64(&e);
#پایان_اگر
                } وإلا {
                    إذا (e.sym)
                        expect("constant");
                    إذا (اندازه == 1)
                        g(e.v);
                    وإلا
                        gen_le16(e.v);
                }
            } وإلا {
                ind += اندازه;
            }
            إذا (tok != ',')
                اكسر;
            بعدی();
        }
        اكسر;
    حالة TOK_ASMDIR_fill:
        {
            صحيح repeat, اندازه, val, i, j;
            uint8_t repeat_buf[8];
            بعدی();
            repeat = asm_int_عبارت(s1);
            إذا (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                اكسر;
            }
            اندازه = 1;
            val = 0;
            إذا (tok == ',') {
                بعدی();
                اندازه = asm_int_عبارت(s1);
                إذا (اندازه < 0) {
                    tcc_error("size < 0; .fill ignored");
                    اكسر;
                }
                إذا (اندازه > 8)
                    اندازه = 8;
                إذا (tok == ',') {
                    بعدی();
                    val = asm_int_عبارت(s1);
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
            لكل(i = 0; i < repeat; i++) {
                لكل(j = 0; j < اندازه; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        اكسر;
    حالة TOK_ASMDIR_rept:
        {
            صحيح repeat;
            TokenString *init_str;
            بعدی();
            repeat = asm_int_عبارت(s1);
            init_str = tok_str_alloc();
            طالما (بعدی(), tok != TOK_ASMDIR_endr) {
                إذا (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_جمع_کن_tok(init_str);
            }
            tok_str_جمع_کن(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            طالما (repeat-- > 0) {
                tcc_assemble_داخلی(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            انتها_macro();
            بعدی();
            اكسر;
        }
    حالة TOK_ASMDIR_org:
        {
	    عبارت_مقدار e;
	    ElfSym *esym;
            بعدی();
	    asm_عبارت(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    إذا (esym) {
		إذا (esym->st_shndx != cur_متن_section->sh_رقم)
		  expect("constant or same-section symbol");
		n += esym->st_مقدار;
	    }
            إذا (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            اندازه = n - ind;
            اذهب zero_pad;
        }
        اكسر;
    حالة TOK_ASMDIR_مجموعه:
	بعدی();
	tok1 = tok;
	بعدی();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	إذا (tok == ',')
	    مجموعه_نماد(s1, tok1);
	اكسر;
    حالة TOK_ASMDIR_globl:
    حالة TOK_ASMDIR_global:
    حالة TOK_ASMDIR_weak:
    حالة TOK_ASMDIR_hidden:
	tok1 = tok;
	افعل { 
            Sym *sym;
            بعدی();
	    إذا (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, عدم);
	    إذا (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            إذا (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    وإلا إذا (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            بعدی();
	} طالما (tok == ',');
	اكسر;
    حالة TOK_ASMDIR_string:
    حالة TOK_ASMDIR_ascii:
    حالة TOK_ASMDIR_asciz:
        {
            ثابت حرف *p;
            صحيح i, اندازه, t;

            t = tok;
            بعدی();
            لكل(;;) {
                إذا (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.داده;
                اندازه = tokc.str.اندازه;
                إذا (t == TOK_ASMDIR_ascii && اندازه > 0)
                    اندازه--;
                لكل(i = 0; i < اندازه; i++)
                    g(p[i]);
                بعدی();
                إذا (tok == ',') {
                    بعدی();
                } وإلا إذا (tok != TOK_STR) {
                    اكسر;
                }
            }
	}
	اكسر;
    حالة TOK_ASMDIR_متن:
    حالة TOK_ASMDIR_داده:
    حالة TOK_ASMDIR_bss:
	{ 
            حرف sname[64];
            tok1 = tok;
            n = 0;
            بعدی();
            إذا (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_عبارت(s1);
		بعدی();
            }
            إذا (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, عدم), n);
            وإلا
                sprintf(sname, "%s", get_tok_str(tok1, عدم));
            use_section(s1, sname);
	}
	اكسر;
    حالة TOK_ASMDIR_file:
        {
            ثابت حرف *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            بعدی();
            إذا (tok == TOK_PPNUM)
                بعدی();
            إذا (tok == TOK_PPSTR && tokc.str.داده[0] == '"') {
                tokc.str.داده[tokc.str.اندازه - 2] = 0;
                p = tokc.str.داده + 1;
            } وإلا إذا (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } وإلا {
                skip_مقصد_eol(0);
                اكسر;
            }
            tccpp_putfile(p);
            بعدی();
        }
        اكسر;
    حالة TOK_ASMDIR_ident:
        {
            حرف ident[256];

            ident[0] = '\0';
            بعدی();
            إذا (tok == TOK_STR)
                pstrcat(ident, حجم(ident), tokc.str.داده);
            وإلا
                pstrcat(ident, حجم(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            بعدی();
        }
        اكسر;
    حالة TOK_ASMDIR_اندازه:
        { 
            Sym *sym;
            ElfSym *esym;

            بعدی();
	    إذا (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_پیدا_کن(tok);
            إذا (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, عدم));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, عدم));
            بعدی();
            skip(',');
            n = asm_int_عبارت(s1);
            esym = elfsym(sym);
            إذا (esym) {
                esym->st_اندازه = n;
            }
        }
        اكسر;
    حالة TOK_ASMDIR_type:
        { 
            Sym *sym;
            ثابت حرف *newtype;
            صحيح st_type;

            بعدی();
	    إذا (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, عدم);
            بعدی();
            skip(',');
            إذا (tok == TOK_STR) {
                newtype = tokc.str.داده;
            } وإلا {
                إذا (tok == '@' || tok == '%')
                    بعدی();
                newtype = get_tok_str(tok, عدم);
            }

            إذا (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                إذا (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            مجموعه_st_type:
                إذا (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } وإلا إذا (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                اذهب مجموعه_st_type;
            } وإلا
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, عدم), sym->type.t, newtype);

            بعدی();
        }
        اكسر;
    حالة TOK_ASMDIR_pushsection:
    حالة TOK_ASMDIR_section:
        {
            حرف sname[256];
	    صحيح old_nb_section = s1->nb_sections;
            صحيح flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            بعدی();
            sname[0] = '\0';
            طالما (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                إذا (tok == TOK_STR)
                    pstrcat(sname, حجم(sname), tokc.str.داده);
                وإلا
                    pstrcat(sname, حجم(sname), get_tok_str(tok, عدم));
                بعدی();
            }
            إذا (tok == ',') {
                ثابت حرف *p;
                /* skip section options */
                بعدی();
                إذا (tok != TOK_STR)
                    expect("string constant");
                لكل (p = tokc.str.داده; *p; ++p) {
                    إذا (*p == 'w')
                        flags |= SHF_WRITE;
                    إذا (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                بعدی();
                إذا (tok == ',') {
                    بعدی();
                    إذا (tok == '@' || tok == '%')
                        بعدی();
                    بعدی();
                }
            }
            آخرین_متن_section = cur_متن_section;
	    إذا (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    وإلا
	        افزودن_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    إذا (old_nb_section != s1->nb_sections) {
	        cur_متن_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                إذا (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_متن_section->sh_flags = flags;
            }
        }
        اكسر;
    حالة TOK_ASMDIR_قبلی:
        { 
            Section *sec;
            بعدی();
            إذا (!آخرین_متن_section)
                tcc_error("no previous section referenced");
            sec = cur_متن_section;
            use_section1(s1, آخرین_متن_section);
            آخرین_متن_section = sec;
        }
        اكسر;
    حالة TOK_ASMDIR_popsection:
	بعدی();
	برداشت_section(s1);
	اكسر;
#اگر_تعریف_شده TCC_هدف_I386
    حالة TOK_ASMDIR_code16:
        {
            بعدی();
            s1->seg_اندازه = 16;
        }
        اكسر;
    حالة TOK_ASMDIR_code32:
        {
            بعدی();
            s1->seg_اندازه = 32;
        }
        اكسر;
#پایان_اگر
#إذا PTR_اندازه == 8
    /* added for compatibility with GAS */
    حالة TOK_ASMDIR_code64:
        بعدی();
        اكسر;
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_RISCV64
    حالة TOK_ASMDIR_option:
        بعدی();
        بدل(tok){
            حالة TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            حالة TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            حالة TOK_ASM_pic:
            حالة TOK_ASM_nopic:
            حالة TOK_ASM_relax:
            حالة TOK_ASM_norelax:
            حالة TOK_ASM_افزودن:
            حالة TOK_ASM_برداشت:
                /* TODO: unimplemented */
                بعدی();
                اكسر;
            حالة TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, عدم));
                اكسر;
            افتراضي:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, عدم));
                اكسر;
        }
        اكسر;
#پایان_اگر
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    حالة TOK_ASMDIR_symver:
	بعدی();
	بعدی();
        skip(',');
	بعدی();
        skip('@');
	بعدی();
	اكسر;
    حالة TOK_ASMDIR_reloc:
	{
	    عبارت_مقدار e;
	    ثابت حرف *reloc_name;
	    صحيح reloc_type = -1;

	    بعدی();
	    asm_عبارت(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, عدم);
#إذا defined(TCC_هدف_ARM64)
	    إذا (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#وإلاإذا defined(TCC_هدف_RISCV64)
	    إذا (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    وإلا إذا (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#پایان_اگر
	    إذا (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    بعدی();
	    skip(',');
	    greloca(cur_متن_section, get_asm_sym(tok, عدم), e.v, reloc_type, 0);
	    بعدی();
	}
	اكسر;
    افتراضي:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, عدم));
        اكسر;
    }
}


/* assemble a file */
ساكن صحيح tcc_assemble_داخلی(TCCState *s1, صحيح do_preprocess, صحيح global)
{
    صحيح opcode;
    صحيح saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    إذا (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    لكل(;;) {
        بعدی();
        إذا (tok == TOK_EOF)
            اكسر;
        tcc_debug_سطر(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#إذا !defined(TCC_هدف_ARM64)
        إذا (tok == '#') {
            /* horrible gas comment */
            طالما (tok != TOK_LINEFEED)
                بعدی();
        } وإلا
#پایان_اگر
        إذا (tok >= TOK_ASMDIR_اولی && tok <= TOK_ASMDIR_آخرین) {
            asm_parse_directive(s1, global);
        } وإلا إذا (tok == TOK_PPNUM) {
            ثابت حرف *p;
            صحيح n;
            p = tokc.str.داده;
            n = strtoul(p, (حرف **)&p, 10);
            إذا (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            بعدی();
            skip(':');
            اذهب redo;
        } وإلا إذا (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            بعدی();
            إذا (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                بعدی();
                اذهب redo;
            } وإلا إذا (tok == '=') {
		مجموعه_نماد(s1, opcode);
                اذهب redo;
            } وإلا {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        إذا (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    أرجع 0;
}

/* Assemble the current file */
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess)
{
    صحيح ret;
    tcc_debug_شروع(s1);
    /* default section is text */
    cur_متن_section = متن_section;
    ind = cur_متن_section->داده_جابه_جایی;
    nocode_wanted = 0;
    ret = tcc_assemble_داخلی(s1, do_preprocess, 1);
    cur_متن_section->داده_جابه_جایی = ind;
    tcc_debug_انتها(s1);
    أرجع ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ساكن فراغ tcc_assemble_inline(TCCState *s1, ثابت حرف *str, صحيح len, صحيح global)
{
    ثابت صحيح *saved_macro_ptr = macro_ptr;
    صحيح dotid = مجموعه_idnum('.', IS_ID);
#إذا !defined(TCC_هدف_RISCV64) && !defined(TCC_هدف_X86_64)
    صحيح dolid = مجموعه_idnum('$', 0);
#پایان_اگر

    tcc_open_bf(s1, ":asm:", len);
    کپی_حافظه(file->میانگیر, str, len);
    macro_ptr = عدم;
    tcc_assemble_داخلی(s1, 0, global);
    tcc_close();

#إذا !defined(TCC_هدف_RISCV64) && !defined(TCC_هدف_X86_64)
    مجموعه_idnum('$', dolid);
#پایان_اگر
    مجموعه_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC صحيح پیدا_کن_constraint(ASMOperand *operands, صحيح nb_operands, 
                           ثابت حرف *name, ثابت حرف **pp)
{
    صحيح شاخص;
    TokenSym *ts;
    ثابت حرف *p;

    إذا (isnum(*name)) {
        شاخص = 0;
        طالما (isnum(*name)) {
            شاخص = (شاخص * 10) + (*name) - '0';
            name++;
        }
        إذا ((بیعلامت)شاخص >= nb_operands)
            شاخص = -1;
    } وإلا إذا (*name == '[') {
        name++;
        p = strchr(name, ']');
        إذا (p) {
            ts = tok_alloc(name, p - name);
            لكل(شاخص = 0; شاخص < nb_operands; شاخص++) {
                إذا (operands[شاخص].id == ts->tok)
                    اذهب یافت;
            }
            شاخص = -1;
        یافت:
            name = p + 1;
        } وإلا {
            شاخص = -1;
        }
    } وإلا {
        شاخص = -1;
    }
    إذا (pp)
        *pp = name;
    أرجع شاخص;
}

ساكن فراغ subst_asm_operands(ASMOperand *operands, صحيح nb_operands, 
                               CString *بیرون_str, ثابت حرف *str)
{
    صحيح c, شاخص, modifier;
    ASMOperand *op;
    SValue sv;

    لكل(;;) {
        c = *str++;
        إذا (c == '%') {
            إذا (*str == '%') {
                str++;
                اذهب جمع_کن_char;
            }
            modifier = 0;
            إذا (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#اگر_تعریف_شده TCC_هدف_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_RISCV64
		*str == 'z' ||
#پایان_اگر
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            شاخص = پیدا_کن_constraint(operands, nb_operands, str, &str);
            إذا (شاخص < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[شاخص];
            إذا (modifier == 'l') {
                cstr_cat(بیرون_str, get_tok_str(op->is_label, عدم), -1);
            } وإلا {
		إذا (op->vt == عدم)
		    اذهب error;
                sv = *op->vt;
                إذا (op->reg >= 0) {
                    sv.r = op->reg;
                    إذا (op->is_حافظه)
                      sv.r |= VT_LVAL;
                }
                subst_asm_عملوند(بیرون_str, &sv, modifier);
            }
        } وإلا {
        جمع_کن_char:
            cstr_ccat(بیرون_str, c);
            إذا (c == '\0')
                اكسر;
        }
    }
}


ساكن فراغ parse_asm_operands(ASMOperand *operands, صحيح *nb_operands_ptr,
                               صحيح is_output)
{
    ASMOperand *op;
    صحيح nb_operands;
    حرف* astr;

    إذا (tok != ':') {
        nb_operands = *nb_operands_ptr;
        لكل(;;) {
            إذا (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            إذا (tok == '[') {
                بعدی();
                إذا (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                بعدی();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->داده;
            pstrcpy(op->constraint, حجم op->constraint, astr);
            skip('(');
            gexpr();
            إذا (is_output) {
                إذا (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } وإلا {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                إذا ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#اگر_تعریف_شده TCC_هدف_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !جستجوی_رشته(op->constraint, "Ump")
#پایان_اگر
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            إذا (tok == ',') {
                بعدی();
            } وإلا {
                اكسر;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC فراغ asm_instr(فراغ)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    صحيح nb_outputs, nb_operands, i, must_subst, بیرون_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    طالما (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        بعدی();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->داده, astr1->اندازه);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, حجم(clobber_regs));
    إذا (tok == ':') {
        بعدی();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        إذا (tok == ':') {
            بعدی();
            إذا (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                إذا (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    بعدی();
                    لكل(;;) {
                        إذا (tok == ':')
                          اكسر;
                        إذا (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.داده);
                        بعدی();
                        إذا (tok == ',') {
                            بعدی();
                        } وإلا {
                            اكسر;
                        }
                    }
                }
                إذا (tok == ':') {
                    /* goto labels */
                    بعدی();
                    لكل (;;) {
                        Sym *csym;
                        صحيح asmname;
                        إذا (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        إذا (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       حجم(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_پیدا_کن(tok);
                        إذا (!csym) {
                            csym = label_افزودن(&global_label_پشته, tok,
                                              LABEL_FORWARD);
                        } وإلا {
                            إذا (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        بعدی();
                        asmname = asm_get_پیشوند_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        إذا (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        إذا (tok != ',')
                          اكسر;
                        بعدی();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    إذا (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &بیرون_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#اگر_تعریف_شده ASM_DEBUG
    چاپ_کن("asm: \"%s\"\n", (حرف *)astr.داده);
#پایان_اگر
    إذا (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.داده, astr.اندازه);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->داده);
    }

#اگر_تعریف_شده ASM_DEBUG
    چاپ_کن("subst_asm: \"%s\"\n", (حرف *)astr.داده);
#پایان_اگر

    /* generate loads */
    asm_gen_کد(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, بیرون_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_متن_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.داده, astr.اندازه - 1, 0);
    cstr_free_s(&astr);
    إذا (sec != cur_متن_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    بعدی();

    /* store the output values if needed */
    asm_gen_کد(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, بیرون_reg);
    
    /* free everything */
    لكل(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC فراغ asm_global_instr(فراغ)
{
    CString *astr;
    صحيح saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    بعدی();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    إذا (tok != ';')
        expect("';'");
    
#اگر_تعریف_شده ASM_DEBUG
    چاپ_کن("asm_global: \"%s\"\n", (حرف *)astr->داده);
#پایان_اگر
    cur_متن_section = متن_section;
    ind = cur_متن_section->داده_جابه_جایی;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->داده, astr->اندازه - 1, 1);
    
    cur_متن_section->داده_جابه_جایی = ind;

    /* restore the current C token */
    بعدی();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#وإلا
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC فراغ asm_instr(فراغ)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC فراغ asm_global_instr(فراغ)
{
    tcc_error("inline asm() not supported");
}
#پایان_اگر /* CONFIG_TCC_ASM */
