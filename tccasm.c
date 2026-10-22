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

#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"
#اگر_تعریف_شدہ CONFIG_TCC_ASM

ساکن Section *آخری_متن_section; /* to handle .previous asm directive */
ساکن صحیح asmgoto_n;

ساکن صحیح tcc_assemble_اندرونی(TCCState *s1, صحیح do_preprocess, صحیح global);
ساکن Sym* asm_new_label(TCCState *s1, صحیح label, صحیح is_local);
ساکن Sym* asm_new_label1(TCCState *s1, صحیح label, صحیح is_local, صحیح sh_عدد, صحیح قدر);

#اگر PTR_سائز == 8
/* output constant with relocation if 'r & VT_SYM' is true */
ST_FUNC خالی gen_addr64(صحیح r, Sym *sym, int64_t c)
{
    اگر (r & VT_SYM)
        greloca(cur_متن_section, sym, ind, R_ڈیٹا_PTR, c), c=0;
    gen_le32(c);
    gen_le32(c>>32);
}

ST_FUNC خالی gen_expr64(اظہاریہ_قدر *pe)
{
    gen_addr64(pe->sym ? VT_SYM : 0, pe->sym, pe->v);
}
#اگر_ختم

ساکن صحیح asm_get_سابقہ_name(TCCState *s1, ثابت حرف *سابقہ, غیرعلامتی صحیح n)
{
    حرف buf[64];
    snprintf(buf, حجم(buf), "%s%u", سابقہ, n);
    واپس tok_alloc_const(buf);
}

ST_FUNC صحیح asm_get_local_label_name(TCCState *s1, غیرعلامتی صحیح n)
{
    واپس asm_get_سابقہ_name(s1, "L..", n);
}

/* If a C name has an _ prepended then only asm labels that start
   with _ are representable in C, by removing the first _.  ASM names
   without _ at the beginning don't correspond to C names, but we use
   the global C symbol table to track ASM names as well, so we need to
   transform those into ones that don't conflict with a C name,
   so prepend a '.' for them, but force the ELF asm name to be set.  */
ساکن صحیح asm2cname(صحیح v, صحیح *addeddot)
{
    ثابت حرف *name;
    *addeddot = 0;
    اگر (!tcc_state->leading_underscore)
      واپس v;
    name = get_tok_str(v, تہی);
    اگر (!name)
      واپس v;
    اگر (name[0] == '_') {
        v = tok_alloc_const(name + 1);
    } ورنہ اگر (!strchr(name, '.')) {
        حرف newname[256];
        snprintf(newname, حجم newname, ".%s", name);
        v = tok_alloc_const(newname);
        *addeddot = 1;
    }
    واپس v;
}

ساکن Sym *asm_label_ڈھونڈو(صحیح v)
{
    Sym *sym;
    صحیح addeddot;
    v = asm2cname(v, &addeddot);
    sym = sym_ڈھونڈو(v);
    جب (sym && sym->sym_scope && !(sym->type.t & VT_STATIC))
        sym = sym->پچھلا_tok;
    واپس sym;
}

ساکن Sym *asm_label_ڈالو(صحیح v)
{
    صحیح addeddot, v2 = asm2cname(v, &addeddot);
    /* We always add VT_EXTERN, for sym definition that's tentative
       (for .set, removed for real defs), for mere references it's correct
       as is.  */
    Sym *sym = global_identifier_ڈالو(v2, VT_ASM | VT_EXTERN | VT_STATIC, 0);
    اگر (addeddot)
        sym->asm_label = v;
    واپس sym;
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
ST_FUNC Sym* get_asm_sym(صحیح name, Sym *csym)
{
    Sym *sym = asm_label_ڈھونڈو(name);
    اگر (!sym) {
	sym = asm_label_ڈالو(name);
	اگر (csym)
	  sym->c = csym->c;
    }
    واپس sym;
}

ساکن Sym* asm_section_sym(TCCState *s1, Section *sec)
{
    حرف buf[100]; صحیح label; Sym *sym;
    snprintf(buf, حجم buf, "L.%s", sec->name);
    label = tok_alloc_const(buf);
    sym = asm_label_ڈھونڈو(label);
    واپس sym ? sym : asm_new_label1(s1, label, 1, sec->sh_عدد, 0);
}

/* We do not use the C expression parser to handle symbols. Maybe the
   C expression parser could be tweaked to do so. */

ساکن خالی asm_اظہاریہ_unary(TCCState *s1, اظہاریہ_قدر *pe)
{
    Sym *sym;
    صحیح op, label;
    uint64_t n;
    ثابت حرف *p;

    انتخاب(tok) {
    حالت TOK_PPNUM:
        p = tokc.str.ڈیٹا;
        n = strtoull(p, (حرف **)&p, 0);
        اگر (*p == 'b' || *p == 'f') {
            /* backward or forward label */
            label = asm_get_local_label_name(s1, n);
            sym = asm_label_ڈھونڈو(label);
            اگر (*p == 'b') {
                /* backward : find the last corresponding defined label */
                اگر (sym && (!sym->c || elfsym(sym)->st_shndx == SHN_UNDEF))
                    sym = sym->پچھلا_tok;
                اگر (!sym)
                    tcc_error("local label '%d' not found backward", (صحیح)n);
            } ورنہ {
                /* forward */
                اگر (!sym || (sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)) {
                    /* if the last label is defined, then define a new one */
		    sym = asm_label_ڈالو(label);
                }
            }
	    pe->v = 0;
	    pe->sym = sym;
	    pe->pcrel = 0;
        } ورنہ اگر (*p == '\0') {
            pe->v = n;
            pe->sym = تہی;
	    pe->pcrel = 0;
        } ورنہ {
            tcc_error("invalid number syntax");
        }
        اگلا();
        توڑو;
    حالت '+':
        اگلا();
        asm_اظہاریہ_unary(s1, pe);
        توڑو;
    حالت '-':
    حالت '~':
        op = tok;
        اگلا();
        asm_اظہاریہ_unary(s1, pe);
        اگر (pe->sym)
            tcc_error("invalid operation with label");
        اگر (op == '-')
            pe->v = -pe->v;
        ورنہ
            pe->v = ~pe->v;
        توڑو;
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
	pe->v = tokc.i;
	pe->sym = تہی;
	pe->pcrel = 0;
	اگلا();
	توڑو;
    حالت '(':
        اگلا();
        asm_اظہاریہ(s1, pe);
        skip(')');
        توڑو;
    حالت '.':
        pe->v = ind;
        pe->sym = asm_section_sym(s1, cur_متن_section);
        pe->pcrel = 0;
        اگلا();
        توڑو;
    طےشدہ:
        اگر (tok >= TOK_IDENT) {
	    ElfSym *esym;
            /* label case : if the label was not found, add one */
	    sym = get_asm_sym(tok, تہی);
	    esym = elfsym(sym);
            اگر (esym && esym->st_shndx == SHN_ABS) {
                /* if absolute symbol, no need to put a symbol value */
                pe->v = esym->st_قدر;
                pe->sym = تہی;
		pe->pcrel = 0;
            } ورنہ {
                pe->v = 0;
                pe->sym = sym;
		pe->pcrel = 0;
            }
            اگلا();
        } ورنہ {
            tcc_error("bad expression syntax [%s]", get_tok_str(tok, &tokc));
        }
        توڑو;
    }
}
    
ساکن خالی asm_اظہاریہ_prod(TCCState *s1, اظہاریہ_قدر *pe)
{
    صحیح op;
    اظہاریہ_قدر e2;

    asm_اظہاریہ_unary(s1, pe);
    برائے(;;) {
        op = tok;
        اگر (op != '*' && op != '/' && op != '%' && 
            op != TOK_SHL && op != TOK_SAR)
            توڑو;
        اگلا();
        asm_اظہاریہ_unary(s1, &e2);
        اگر (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        انتخاب(op) {
        حالت '*':
            pe->v *= e2.v;
            توڑو;
        حالت '/':  
            اگر (e2.v == 0) {
            div_error:
                tcc_error("division by zero");
            }
            pe->v /= e2.v;
            توڑو;
        حالت '%':  
            اگر (e2.v == 0)
                جاؤ div_error;
            pe->v %= e2.v;
            توڑو;
        حالت TOK_SHL:
            pe->v <<= e2.v;
            توڑو;
        طےشدہ:
        حالت TOK_SAR:
            pe->v >>= e2.v;
            توڑو;
        }
    }
}

ساکن خالی asm_اظہاریہ_logic(TCCState *s1, اظہاریہ_قدر *pe)
{
    صحیح op;
    اظہاریہ_قدر e2;

    asm_اظہاریہ_prod(s1, pe);
    برائے(;;) {
        op = tok;
        اگر (op != '&' && op != '|' && op != '^')
            توڑو;
        اگلا();
        asm_اظہاریہ_prod(s1, &e2);
        اگر (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        انتخاب(op) {
        حالت '&':
            pe->v &= e2.v;
            توڑو;
        حالت '|':  
            pe->v |= e2.v;
            توڑو;
        طےشدہ:
        حالت '^':
            pe->v ^= e2.v;
            توڑو;
        }
    }
}

ساکن اندرونی خالی asm_اظہاریہ_مجموع(TCCState *s1, اظہاریہ_قدر *pe)
{
    صحیح op;
    اظہاریہ_قدر e2;

    asm_اظہاریہ_logic(s1, pe);
    برائے(;;) {
        op = tok;
        اگر (op != '+' && op != '-')
            توڑو;
        اگلا();
        asm_اظہاریہ_logic(s1, &e2);
        اگر (op == '+') {
            اگر (pe->sym != تہی && e2.sym != تہی)
                جاؤ cannot_relocate;
            pe->v += e2.v;
            اگر (pe->sym == تہی && e2.sym != تہی)
                pe->sym = e2.sym;
        } ورنہ {
            pe->v -= e2.v;
            /* NOTE: we are less powerful than gas in that case
               because we store only one symbol in the expression */
	    اگر (!e2.sym) {
		/* OK */
	    } ورنہ اگر (pe->sym == e2.sym) { 
		/* OK */
		pe->sym = تہی; /* same symbols can be subtracted to NULL */
	    } ورنہ {
		ElfSym *esym1, *esym2;
		esym1 = elfsym(pe->sym);
		esym2 = elfsym(e2.sym);
		اگر (!esym2)
		    جاؤ cannot_relocate;
		اگر (esym1 && esym1->st_shndx == esym2->st_shndx
		    && esym1->st_shndx != SHN_UNDEF) {
		    /* we also accept defined symbols in the same section */
		    pe->v += (صحیح)(esym1->st_قدر - esym2->st_قدر);
		    pe->sym = تہی;
		} ورنہ اگر (esym2->st_shndx == cur_متن_section->sh_عدد) {
		    /* When subtracting a defined symbol in current section
		       this actually makes the value PC-relative.  */
		    pe->v += (صحیح)(0 - esym2->st_قدر);
		    pe->pcrel = 1;
		    e2.sym = تہی;
		} ورنہ {
cannot_relocate:
		    tcc_error("invalid operation with label");
		}
	    }
        }
    }
}

ساکن اندرونی خالی asm_اظہاریہ_cmp(TCCState *s1, اظہاریہ_قدر *pe)
{
    صحیح op;
    اظہاریہ_قدر e2;

    asm_اظہاریہ_مجموع(s1, pe);
    برائے(;;) {
        op = tok;
	اگر (op != TOK_EQ && op != TOK_NE
	    && (op > TOK_GT || op < TOK_ULE))
            توڑو;
        اگلا();
        asm_اظہاریہ_مجموع(s1, &e2);
        اگر (pe->sym || e2.sym)
            tcc_error("invalid operation with label");
        انتخاب(op) {
	حالت TOK_EQ:
	    pe->v = pe->v == e2.v;
	    توڑو;
	حالت TOK_NE:
	    pe->v = pe->v != e2.v;
	    توڑو;
	حالت TOK_LT:
	    pe->v = (int64_t)pe->v < (int64_t)e2.v;
	    توڑو;
	حالت TOK_GE:
	    pe->v = (int64_t)pe->v >= (int64_t)e2.v;
	    توڑو;
	حالت TOK_LE:
	    pe->v = (int64_t)pe->v <= (int64_t)e2.v;
	    توڑو;
	حالت TOK_GT:
	    pe->v = (int64_t)pe->v > (int64_t)e2.v;
	    توڑو;
        طےشدہ:
            توڑو;
        }
	/* GAS compare results are -1/0 not 1/0.  */
	pe->v = -(int64_t)pe->v;
    }
}

ST_FUNC خالی asm_اظہاریہ(TCCState *s1, اظہاریہ_قدر *pe)
{
    asm_اظہاریہ_cmp(s1, pe);
}

ST_FUNC صحیح asm_int_اظہاریہ(TCCState *s1)
{
    اظہاریہ_قدر e;
    asm_اظہاریہ(s1, &e);
    اگر (e.sym)
        expect("constant");
    اگر ((صحیح)e.v != e.v)
	tcc_error("integer out of range %lld", (طویل طویل)e.v);
    واپس e.v;
}

ساکن Sym* asm_new_label1(TCCState *s1, صحیح label, صحیح is_local,
                           صحیح sh_عدد, صحیح قدر)
{
    Sym *sym;
    ElfSym *esym;

    sym = asm_label_ڈھونڈو(label);
    اگر (sym) {
	esym = elfsym(sym);
	/* A VT_EXTERN symbol, even if it has a section is considered
	   overridable.  This is how we "define" .set targets.  Real
	   definitions won't have VT_EXTERN set.  */
        اگر (esym && esym->st_shndx != SHN_UNDEF) {
            /* the label is already defined */
            اگر (IS_ASM_SYM(sym)
                && (is_local == 1 || (sym->type.t & VT_EXTERN)))
                جاؤ new_label;
            اگر (!(sym->type.t & VT_EXTERN))
                tcc_error("assembler label '%s' already defined",
                          get_tok_str(label, تہی));
        }
    } ورنہ {
    new_label:
        sym = asm_label_ڈالو(label);
    }
    اگر (!sym->c)
      put_extern_sym2(sym, SHN_UNDEF, 0, 0, 1);
    esym = elfsym(sym);
    esym->st_shndx = sh_عدد;
    esym->st_قدر = قدر;
    اگر (is_local != 2)
        sym->type.t &= ~VT_EXTERN;
    واپس sym;
}

ساکن Sym* asm_new_label(TCCState *s1, صحیح label, صحیح is_local)
{
    واپس asm_new_label1(s1, label, is_local, cur_متن_section->sh_عدد, ind);
}

/* Set the value of LABEL to that of some expression (possibly
   involving other symbols).  LABEL can be overwritten later still.  */
ساکن Sym* سیٹ_علامت(TCCState *s1, صحیح label)
{
    طویل n;
    اظہاریہ_قدر e;
    Sym *sym;
    ElfSym *esym;
    اگلا();
    asm_اظہاریہ(s1, &e);
    n = e.v;
    esym = elfsym(e.sym);
    اگر (esym)
	n += esym->st_قدر;
    sym = asm_new_label1(s1, label, 2, esym ? esym->st_shndx : SHN_ABS, n);
    elfsym(sym)->st_other |= ST_ASM_سیٹ;
    واپس sym;
}

ساکن خالی use_section1(TCCState *s1, Section *sec)
{
    cur_متن_section->ڈیٹا_انحراف = ind;
    cur_متن_section = sec;
    ind = cur_متن_section->ڈیٹا_انحراف;
}

ساکن خالی use_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec;
    sec = ڈھونڈو_section(s1, name);
    use_section1(s1, sec);
}

ساکن خالی ڈالو_section(TCCState *s1, ثابت حرف *name)
{
    Section *sec = ڈھونڈو_section(s1, name);
    sec->پچھلا = cur_متن_section;
    use_section1(s1, sec);
}

ساکن خالی نکالو_section(TCCState *s1)
{
    Section *پچھلا = cur_متن_section->پچھلا;
    اگر (!پچھلا)
        tcc_error(".popsection without .pushsection");
    cur_متن_section->پچھلا = تہی;
    use_section1(s1, پچھلا);
}

ساکن خالی asm_parse_directive(TCCState *s1, صحیح global)
{
    صحیح n, انحراف, v, سائز, tok1, c;
    Section *sec;
    uint8_t *ptr;

    /* assembler directive */
    sec = cur_متن_section;
    انتخاب(tok) {
    حالت TOK_ASMDIR_align:
    حالت TOK_ASMDIR_balign:
    حالت TOK_ASMDIR_p2align:
    حالت TOK_ASMDIR_skip:
    حالت TOK_ASMDIR_space:
        tok1 = tok;
        اگلا();
        n = asm_int_اظہاریہ(s1);
        اگر (tok1 == TOK_ASMDIR_p2align)
        {
            اگر (n < 0 || n > 30)
                tcc_error("invalid p2align, must be between 0 and 30");
            n = 1 << n;
            tok1 = TOK_ASMDIR_align;
        }
        اگر (tok1 == TOK_ASMDIR_align || tok1 == TOK_ASMDIR_balign) {
            اگر (n <= 0 || (n & (n-1)) != 0)
                tcc_error("alignment must be a positive power of two");
            انحراف = (ind + n - 1) & -n;
            سائز = انحراف - ind;
            /* the section must have a compatible alignment */
            اگر (sec->sh_addralign < n)
                sec->sh_addralign = n;
            c = sec->sh_flags & SHF_EXECINSTR;
        } ورنہ {
	    اگر (n < 0)
	        n = 0;
            سائز = n, c = 0;
        }
        v = 0;
        اگر (tok == ',') {
            اگلا();
            v = asm_int_اظہاریہ(s1), c = 0;
        }
    zero_pad:
	اگر ((uint64_t)ind + سائز >= 1<<30)
	    tcc_error("too much data");
        اگر (sec->sh_type != SHT_NOBITS) {
            اگر (c) {
                gen_fill_nops(سائز);
                توڑو;
            }
            sec->ڈیٹا_انحراف = ind;
            ptr = section_ptr_جوڑو(sec, سائز);
            memset(ptr, v, سائز);
        }
        ind += سائز;
        توڑو;
    حالت TOK_ASMDIR_quad:
#اگر PTR_سائز == 8
	سائز = 8;
	جاؤ asm_ڈیٹا;
#ورنہ
        اگلا();
        برائے(;;) {
            uint64_t vl;
            ثابت حرف *p;

            p = tokc.str.ڈیٹا;
            اگر (tok != TOK_PPNUM) {
            error_constant:
                tcc_error("64 bit constant");
            }
            vl = strtoll(p, (حرف **)&p, 0);
            اگر (*p != '\0')
                جاؤ error_constant;
            اگلا();
            اگر (sec->sh_type != SHT_NOBITS) {
                /* XXX: endianness */
                gen_le32(vl);
                gen_le32(vl >> 32);
            } ورنہ {
                ind += 8;
            }
            اگر (tok != ',')
                توڑو;
            اگلا();
        }
        توڑو;
#اگر_ختم
    حالت TOK_ASMDIR_byte:
        سائز = 1;
        جاؤ asm_ڈیٹا;
    حالت TOK_ASMDIR_لفظ:
    حالت TOK_ASMDIR_short:
        سائز = 2;
        جاؤ asm_ڈیٹا;
    حالت TOK_ASMDIR_long:
    حالت TOK_ASMDIR_int:
        سائز = 4;
    asm_ڈیٹا:
        اگلا();
        برائے(;;) {
            اظہاریہ_قدر e;
            asm_اظہاریہ(s1, &e);
            اگر (sec->sh_type != SHT_NOBITS) {
                اگر (سائز == 4) {
                    gen_expr32(&e);
#اگر PTR_سائز == 8
		} ورنہ اگر (سائز == 8) {
		    gen_expr64(&e);
#اگر_ختم
                } ورنہ {
                    اگر (e.sym)
                        expect("constant");
                    اگر (سائز == 1)
                        g(e.v);
                    ورنہ
                        gen_le16(e.v);
                }
            } ورنہ {
                ind += سائز;
            }
            اگر (tok != ',')
                توڑو;
            اگلا();
        }
        توڑو;
    حالت TOK_ASMDIR_fill:
        {
            صحیح repeat, سائز, val, i, j;
            uint8_t repeat_buf[8];
            اگلا();
            repeat = asm_int_اظہاریہ(s1);
            اگر (repeat < 0) {
                tcc_error("repeat < 0; .fill ignored");
                توڑو;
            }
            سائز = 1;
            val = 0;
            اگر (tok == ',') {
                اگلا();
                سائز = asm_int_اظہاریہ(s1);
                اگر (سائز < 0) {
                    tcc_error("size < 0; .fill ignored");
                    توڑو;
                }
                اگر (سائز > 8)
                    سائز = 8;
                اگر (tok == ',') {
                    اگلا();
                    val = asm_int_اظہاریہ(s1);
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
            برائے(i = 0; i < repeat; i++) {
                برائے(j = 0; j < سائز; j++) {
                    g(repeat_buf[j]);
                }
            }
        }
        توڑو;
    حالت TOK_ASMDIR_rept:
        {
            صحیح repeat;
            TokenString *init_str;
            اگلا();
            repeat = asm_int_اظہاریہ(s1);
            init_str = tok_str_alloc();
            جب (اگلا(), tok != TOK_ASMDIR_endr) {
                اگر (tok == CH_EOF)
                    tcc_error("we at end of file, .endr not found");
                tok_str_جوڑو_tok(init_str);
            }
            tok_str_جوڑو(init_str, TOK_EOF);
            begin_macro(init_str, 1);
            جب (repeat-- > 0) {
                tcc_assemble_اندرونی(s1, (parse_flags & PARSE_FLAG_PREPROCESS),
				      global);
                macro_ptr = init_str->str;
            }
            انتہا_macro();
            اگلا();
            توڑو;
        }
    حالت TOK_ASMDIR_org:
        {
	    اظہاریہ_قدر e;
	    ElfSym *esym;
            اگلا();
	    asm_اظہاریہ(s1, &e);
	    n = e.v;
	    esym = elfsym(e.sym);
	    اگر (esym) {
		اگر (esym->st_shndx != cur_متن_section->sh_عدد)
		  expect("constant or same-section symbol");
		n += esym->st_قدر;
	    }
            اگر (n < ind)
                tcc_error("attempt to .org backwards");
            v = c = 0;
            سائز = n - ind;
            جاؤ zero_pad;
        }
        توڑو;
    حالت TOK_ASMDIR_سیٹ:
	اگلا();
	tok1 = tok;
	اگلا();
	/* Also accept '.set stuff', but don't do anything with this.
	   It's used in GAS to set various features like '.set mips16'.  */
	اگر (tok == ',')
	    سیٹ_علامت(s1, tok1);
	توڑو;
    حالت TOK_ASMDIR_globl:
    حالت TOK_ASMDIR_global:
    حالت TOK_ASMDIR_weak:
    حالت TOK_ASMDIR_hidden:
	tok1 = tok;
	کرو { 
            Sym *sym;
            اگلا();
	    اگر (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, تہی);
	    اگر (tok1 != TOK_ASMDIR_hidden)
                sym->type.t &= ~VT_STATIC;
            اگر (tok1 == TOK_ASMDIR_weak)
                sym->a.weak = 1;
	    ورنہ اگر (tok1 == TOK_ASMDIR_hidden)
	        sym->a.visibility = STV_HIDDEN;
            update_storage(sym);
            اگلا();
	} جب (tok == ',');
	توڑو;
    حالت TOK_ASMDIR_string:
    حالت TOK_ASMDIR_ascii:
    حالت TOK_ASMDIR_asciz:
        {
            ثابت حرف *p;
            صحیح i, سائز, t;

            t = tok;
            اگلا();
            برائے(;;) {
                اگر (tok != TOK_STR)
                    expect("string constant");
                p = tokc.str.ڈیٹا;
                سائز = tokc.str.سائز;
                اگر (t == TOK_ASMDIR_ascii && سائز > 0)
                    سائز--;
                برائے(i = 0; i < سائز; i++)
                    g(p[i]);
                اگلا();
                اگر (tok == ',') {
                    اگلا();
                } ورنہ اگر (tok != TOK_STR) {
                    توڑو;
                }
            }
	}
	توڑو;
    حالت TOK_ASMDIR_متن:
    حالت TOK_ASMDIR_ڈیٹا:
    حالت TOK_ASMDIR_bss:
	{ 
            حرف sname[64];
            tok1 = tok;
            n = 0;
            اگلا();
            اگر (tok != ';' && tok != TOK_LINEFEED) {
		n = asm_int_اظہاریہ(s1);
		اگلا();
            }
            اگر (n)
                sprintf(sname, "%s%d", get_tok_str(tok1, تہی), n);
            ورنہ
                sprintf(sname, "%s", get_tok_str(tok1, تہی));
            use_section(s1, sname);
	}
	توڑو;
    حالت TOK_ASMDIR_file:
        {
            ثابت حرف *p;
            parse_flags &= ~PARSE_FLAG_TOK_STR;
            اگلا();
            اگر (tok == TOK_PPNUM)
                اگلا();
            اگر (tok == TOK_PPSTR && tokc.str.ڈیٹا[0] == '"') {
                tokc.str.ڈیٹا[tokc.str.سائز - 2] = 0;
                p = tokc.str.ڈیٹا + 1;
            } ورنہ اگر (tok >= TOK_IDENT) {
                p = get_tok_str(tok, &tokc);
            } ورنہ {
                skip_مقصد_eol(0);
                توڑو;
            }
            tccpp_putfile(p);
            اگلا();
        }
        توڑو;
    حالت TOK_ASMDIR_ident:
        {
            حرف ident[256];

            ident[0] = '\0';
            اگلا();
            اگر (tok == TOK_STR)
                pstrcat(ident, حجم(ident), tokc.str.ڈیٹا);
            ورنہ
                pstrcat(ident, حجم(ident), get_tok_str(tok, &tokc));
            tcc_warning_c(warn_unsupported)("ignoring .ident %s", ident);
            اگلا();
        }
        توڑو;
    حالت TOK_ASMDIR_سائز:
        { 
            Sym *sym;
            ElfSym *esym;

            اگلا();
	    اگر (tok < TOK_IDENT)
		expect("identifier");
            sym = asm_label_ڈھونڈو(tok);
            اگر (!sym)
                tcc_error("label not found: %s", get_tok_str(tok, تہی));
            /* XXX .size name,label2-label1 */
            tcc_warning_c(warn_unsupported)("ignoring .size %s,*", get_tok_str(tok, تہی));
            اگلا();
            skip(',');
            n = asm_int_اظہاریہ(s1);
            esym = elfsym(sym);
            اگر (esym) {
                esym->st_سائز = n;
            }
        }
        توڑو;
    حالت TOK_ASMDIR_type:
        { 
            Sym *sym;
            ثابت حرف *newtype;
            صحیح st_type;

            اگلا();
	    اگر (tok < TOK_IDENT)
		expect("identifier");
            sym = get_asm_sym(tok, تہی);
            اگلا();
            skip(',');
            اگر (tok == TOK_STR) {
                newtype = tokc.str.ڈیٹا;
            } ورنہ {
                اگر (tok == '@' || tok == '%')
                    اگلا();
                newtype = get_tok_str(tok, تہی);
            }

            اگر (!strcmp(newtype, "function") || !strcmp(newtype, "STT_FUNC")) {
                اگر (IS_ASM_SYM(sym))
                    sym->type.t |= VT_ASM_FUNC;
                st_type = STT_FUNC;
            سیٹ_st_type:
                اگر (sym->c) {
                    ElfSym *esym = elfsym(sym);
                    esym->st_info = ELFW(ST_INFO)(ELFW(ST_BIND)(esym->st_info), st_type);
                }
            } ورنہ اگر (!strcmp(newtype, "object") || !strcmp(newtype, "STT_OBJECT")) {
                st_type = STT_OBJECT;
                جاؤ سیٹ_st_type;
            } ورنہ
                tcc_warning_c(warn_unsupported)("change type of '%s' from 0x%x to '%s' ignored",
                    get_tok_str(sym->v, تہی), sym->type.t, newtype);

            اگلا();
        }
        توڑو;
    حالت TOK_ASMDIR_pushsection:
    حالت TOK_ASMDIR_section:
        {
            حرف sname[256];
	    صحیح old_nb_section = s1->nb_sections;
            صحیح flags = SHF_ALLOC;

	    tok1 = tok;
            /* XXX: support more options */
            اگلا();
            sname[0] = '\0';
            جب (tok != ';' && tok != TOK_LINEFEED && tok != ',') {
                اگر (tok == TOK_STR)
                    pstrcat(sname, حجم(sname), tokc.str.ڈیٹا);
                ورنہ
                    pstrcat(sname, حجم(sname), get_tok_str(tok, تہی));
                اگلا();
            }
            اگر (tok == ',') {
                ثابت حرف *p;
                /* skip section options */
                اگلا();
                اگر (tok != TOK_STR)
                    expect("string constant");
                برائے (p = tokc.str.ڈیٹا; *p; ++p) {
                    اگر (*p == 'w')
                        flags |= SHF_WRITE;
                    اگر (*p == 'x')
                        flags |= SHF_EXECINSTR;
                }
                اگلا();
                اگر (tok == ',') {
                    اگلا();
                    اگر (tok == '@' || tok == '%')
                        اگلا();
                    اگلا();
                }
            }
            آخری_متن_section = cur_متن_section;
	    اگر (tok1 == TOK_ASMDIR_section)
	        use_section(s1, sname);
	    ورنہ
	        ڈالو_section(s1, sname);
	    /* If we just allocated a new section reset its alignment to
	       1.  new_section normally acts for GCC compatibility and
	       sets alignment to PTR_SIZE.  The assembler behaves different. */
	    اگر (old_nb_section != s1->nb_sections) {
	        cur_متن_section->sh_addralign = 1;
                /* Make .init and .fini sections executable by default.
                   GAS does so, too, and musl relies on it. */
                اگر (!strcmp(sname, ".init") || !strcmp(sname, ".fini"))
                    flags |= SHF_EXECINSTR;
	        cur_متن_section->sh_flags = flags;
            }
        }
        توڑو;
    حالت TOK_ASMDIR_پچھلا:
        { 
            Section *sec;
            اگلا();
            اگر (!آخری_متن_section)
                tcc_error("no previous section referenced");
            sec = cur_متن_section;
            use_section1(s1, آخری_متن_section);
            آخری_متن_section = sec;
        }
        توڑو;
    حالت TOK_ASMDIR_popsection:
	اگلا();
	نکالو_section(s1);
	توڑو;
#اگر_تعریف_شدہ TCC_ہدف_I386
    حالت TOK_ASMDIR_code16:
        {
            اگلا();
            s1->seg_سائز = 16;
        }
        توڑو;
    حالت TOK_ASMDIR_code32:
        {
            اگلا();
            s1->seg_سائز = 32;
        }
        توڑو;
#اگر_ختم
#اگر PTR_سائز == 8
    /* added for compatibility with GAS */
    حالت TOK_ASMDIR_code64:
        اگلا();
        توڑو;
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    حالت TOK_ASMDIR_option:
        اگلا();
        انتخاب(tok){
            حالت TOK_ASM_rvc:    /* Will be deprecated soon in favor of arch */
            حالت TOK_ASM_norvc:  /* Will be deprecated soon in favor of arch */
            حالت TOK_ASM_pic:
            حالت TOK_ASM_nopic:
            حالت TOK_ASM_relax:
            حالت TOK_ASM_norelax:
            حالت TOK_ASM_ڈالو:
            حالت TOK_ASM_نکالو:
                /* TODO: unimplemented */
                اگلا();
                توڑو;
            حالت TOK_ASM_arch:
                /* TODO: unimplemented, requires extra parsing */
                tcc_error("unimp .option '.%s'", get_tok_str(tok, تہی));
                توڑو;
            طےشدہ:
                tcc_error("unknown .option '.%s'", get_tok_str(tok, تہی));
                توڑو;
        }
        توڑو;
#اگر_ختم
    /* TODO: Implement symvar support. FreeBSD >= 14 needs this */
    حالت TOK_ASMDIR_symver:
	اگلا();
	اگلا();
        skip(',');
	اگلا();
        skip('@');
	اگلا();
	توڑو;
    حالت TOK_ASMDIR_reloc:
	{
	    اظہاریہ_قدر e;
	    ثابت حرف *reloc_name;
	    صحیح reloc_type = -1;

	    اگلا();
	    asm_اظہاریہ(s1, &e);
	    skip(',');
	    reloc_name = get_tok_str(tok, تہی);
#اگر defined(TCC_ہدف_ARM64)
	    اگر (!strcmp(reloc_name, "R_AARCH64_CALL26"))
	        reloc_type = R_AARCH64_CALL26;
#وگرنہ_اگر defined(TCC_ہدف_RISCV64)
	    اگر (!strcmp(reloc_name, "R_RISCV_CALL") || !strcmp(reloc_name, "R_RISCV_CALL_PLT"))
	        reloc_type = R_RISCV_CALL;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_BRANCH"))
	        reloc_type = R_RISCV_BRANCH;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_JAL"))
	        reloc_type = R_RISCV_JAL;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_PCREL_HI20"))
	        reloc_type = R_RISCV_PCREL_HI20;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_I"))
	        reloc_type = R_RISCV_PCREL_LO12_I;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_PCREL_LO12_S"))
	        reloc_type = R_RISCV_PCREL_LO12_S;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_32_PCREL"))
	        reloc_type = R_RISCV_32_PCREL;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_32"))
	        reloc_type = R_RISCV_32;
	    ورنہ اگر (!strcmp(reloc_name, "R_RISCV_64"))
	        reloc_type = R_RISCV_64;
#اگر_ختم
	    اگر (reloc_type < 0)
	        tcc_error("unimp: reloc '%s' unknown", reloc_name);
	    اگلا();
	    skip(',');
	    greloca(cur_متن_section, get_asm_sym(tok, تہی), e.v, reloc_type, 0);
	    اگلا();
	}
	توڑو;
    طےشدہ:
        tcc_error("unknown assembler directive '.%s'", get_tok_str(tok, تہی));
        توڑو;
    }
}


/* assemble a file */
ساکن صحیح tcc_assemble_اندرونی(TCCState *s1, صحیح do_preprocess, صحیح global)
{
    صحیح opcode;
    صحیح saved_parse_flags = parse_flags;

    parse_flags = PARSE_FLAG_ASM_FILE | PARSE_FLAG_TOK_STR;
    اگر (do_preprocess)
        parse_flags |= PARSE_FLAG_PREPROCESS;
    برائے(;;) {
        اگلا();
        اگر (tok == TOK_EOF)
            توڑو;
        tcc_debug_سطر(s1);
        parse_flags |= PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    redo:
#اگر !defined(TCC_ہدف_ARM64)
        اگر (tok == '#') {
            /* horrible gas comment */
            جب (tok != TOK_LINEFEED)
                اگلا();
        } ورنہ
#اگر_ختم
        اگر (tok >= TOK_ASMDIR_پہلا && tok <= TOK_ASMDIR_آخری) {
            asm_parse_directive(s1, global);
        } ورنہ اگر (tok == TOK_PPNUM) {
            ثابت حرف *p;
            صحیح n;
            p = tokc.str.ڈیٹا;
            n = strtoul(p, (حرف **)&p, 10);
            اگر (*p != '\0')
                expect("':'");
            /* new local label */
            asm_new_label(s1, asm_get_local_label_name(s1, n), 1);
            اگلا();
            skip(':');
            جاؤ redo;
        } ورنہ اگر (tok >= TOK_IDENT) {
            /* instruction or label */
            opcode = tok;
            اگلا();
            اگر (tok == ':') {
                /* new label */
                asm_new_label(s1, opcode, 0);
                اگلا();
                جاؤ redo;
            } ورنہ اگر (tok == '=') {
		سیٹ_علامت(s1, opcode);
                جاؤ redo;
            } ورنہ {
                asm_opcode(s1, opcode);
            }
        }
        /* end of line */
        اگر (tok != ';' && tok != TOK_LINEFEED)
            expect("end of line");
        parse_flags &= ~PARSE_FLAG_LINEFEED; /* XXX: suppress that hack */
    }

    parse_flags = saved_parse_flags;
    واپس 0;
}

/* Assemble the current file */
ST_FUNC صحیح tcc_assemble(TCCState *s1, صحیح do_preprocess)
{
    صحیح ret;
    tcc_debug_آغاز(s1);
    /* default section is text */
    cur_متن_section = متن_section;
    ind = cur_متن_section->ڈیٹا_انحراف;
    nocode_wanted = 0;
    ret = tcc_assemble_اندرونی(s1, do_preprocess, 1);
    cur_متن_section->ڈیٹا_انحراف = ind;
    tcc_debug_انتہا(s1);
    واپس ret;
}

/********************************************************************/
/* GCC inline asm support */

/* assemble the string 'str' in the current C compilation unit without
   C preprocessing. */
ساکن خالی tcc_assemble_inline(TCCState *s1, ثابت حرف *str, صحیح len, صحیح global)
{
    ثابت صحیح *saved_macro_ptr = macro_ptr;
    صحیح dotid = سیٹ_idnum('.', IS_ID);
#اگر !defined(TCC_ہدف_RISCV64) && !defined(TCC_ہدف_X86_64)
    صحیح dolid = سیٹ_idnum('$', 0);
#اگر_ختم

    tcc_open_bf(s1, ":asm:", len);
    حافظہ_نقل(file->بفر, str, len);
    macro_ptr = تہی;
    tcc_assemble_اندرونی(s1, 0, global);
    tcc_close();

#اگر !defined(TCC_ہدف_RISCV64) && !defined(TCC_ہدف_X86_64)
    سیٹ_idnum('$', dolid);
#اگر_ختم
    سیٹ_idnum('.', dotid);
    macro_ptr = saved_macro_ptr;
}

/* find a constraint by its number or id (gcc 3 extended
   syntax). return -1 if not found. Return in *pp in char after the
   constraint */
ST_FUNC صحیح ڈھونڈو_constraint(ASMOperand *operands, صحیح nb_operands, 
                           ثابت حرف *name, ثابت حرف **pp)
{
    صحیح اشاریہ;
    TokenSym *ts;
    ثابت حرف *p;

    اگر (isnum(*name)) {
        اشاریہ = 0;
        جب (isnum(*name)) {
            اشاریہ = (اشاریہ * 10) + (*name) - '0';
            name++;
        }
        اگر ((غیرعلامتی)اشاریہ >= nb_operands)
            اشاریہ = -1;
    } ورنہ اگر (*name == '[') {
        name++;
        p = strchr(name, ']');
        اگر (p) {
            ts = tok_alloc(name, p - name);
            برائے(اشاریہ = 0; اشاریہ < nb_operands; اشاریہ++) {
                اگر (operands[اشاریہ].id == ts->tok)
                    جاؤ ملا;
            }
            اشاریہ = -1;
        ملا:
            name = p + 1;
        } ورنہ {
            اشاریہ = -1;
        }
    } ورنہ {
        اشاریہ = -1;
    }
    اگر (pp)
        *pp = name;
    واپس اشاریہ;
}

ساکن خالی subst_asm_operands(ASMOperand *operands, صحیح nb_operands, 
                               CString *برآمد_str, ثابت حرف *str)
{
    صحیح c, اشاریہ, modifier;
    ASMOperand *op;
    SValue sv;

    برائے(;;) {
        c = *str++;
        اگر (c == '%') {
            اگر (*str == '%') {
                str++;
                جاؤ جوڑو_char;
            }
            modifier = 0;
            اگر (*str == 'c' || *str == 'n' ||
                *str == 'b' || *str == 'w' || *str == 'h' || *str == 'k' ||
		*str == 'q' || *str == 'l' ||
#اگر_تعریف_شدہ TCC_ہدف_ARM64
                *str == 'x' || *str == 's' || *str == 'd' || *str == 'Z' ||
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
		*str == 'z' ||
#اگر_ختم
		/* P in GCC would add "@PLT" to symbol refs in PIC mode,
		   and make literal operands not be decorated with '$'.  */
		*str == 'P')
                modifier = *str++;
            اشاریہ = ڈھونڈو_constraint(operands, nb_operands, str, &str);
            اگر (اشاریہ < 0)
        error:
                tcc_error("invalid operand reference after %%");
            op = &operands[اشاریہ];
            اگر (modifier == 'l') {
                cstr_cat(برآمد_str, get_tok_str(op->is_label, تہی), -1);
            } ورنہ {
		اگر (op->vt == تہی)
		    جاؤ error;
                sv = *op->vt;
                اگر (op->reg >= 0) {
                    sv.r = op->reg;
                    اگر (op->is_حافظہ)
                      sv.r |= VT_LVAL;
                }
                subst_asm_عملیہ(برآمد_str, &sv, modifier);
            }
        } ورنہ {
        جوڑو_char:
            cstr_ccat(برآمد_str, c);
            اگر (c == '\0')
                توڑو;
        }
    }
}


ساکن خالی parse_asm_operands(ASMOperand *operands, صحیح *nb_operands_ptr,
                               صحیح is_output)
{
    ASMOperand *op;
    صحیح nb_operands;
    حرف* astr;

    اگر (tok != ':') {
        nb_operands = *nb_operands_ptr;
        برائے(;;) {
            اگر (nb_operands >= MAX_ASM_OPERANDS)
                tcc_error("too many asm operands");
            op = &operands[nb_operands++];
            op->id = 0;
            اگر (tok == '[') {
                اگلا();
                اگر (tok < TOK_IDENT)
                    expect("identifier");
                op->id = tok;
                اگلا();
                skip(']');
            }
	    astr = parse_mult_str("string constant")->ڈیٹا;
            pstrcpy(op->constraint, حجم op->constraint, astr);
            skip('(');
            gexpr();
            اگر (is_output) {
                اگر (!(vtop->type.t & VT_ARRAY))
                    test_lvalue();
            } ورنہ {
                /* we want to avoid LLOCAL case, except when the 'm'
                   constraint is used. Note that it may come from
                   register storage, so we need to convert (reg)
                   case */
                اگر ((vtop->r & VT_LVAL) &&
                    ((vtop->r & VT_VALMASK) == VT_LLOCAL ||
                     (vtop->r & VT_VALMASK) < VT_CONST) &&
                    !strchr(op->constraint, 'm')
#اگر_تعریف_شدہ TCC_ہدف_ARM64
                    && !strchr(op->constraint, 'Q')
                    && !لڑی_تلاش(op->constraint, "Ump")
#اگر_ختم
                    ) {
                    gv(RC_INT);
                }
            }
            op->vt = vtop;
            skip(')');
            اگر (tok == ',') {
                اگلا();
            } ورنہ {
                توڑو;
            }
        }
        *nb_operands_ptr = nb_operands;
    }
}

/* parse the GCC asm() instruction */
ST_FUNC خالی asm_instr(خالی)
{
    CString astr, *astr1;

    ASMOperand operands[MAX_ASM_OPERANDS];
    صحیح nb_outputs, nb_operands, i, must_subst, برآمد_reg, nb_labels;
    uint8_t clobber_regs[NB_ASM_REGS];
    Section *sec;

    /* since we always generate the asm() instruction, we can ignore
       volatile */
    جب (tok == TOK_VOLATILE1 || tok == TOK_VOLATILE2 || tok == TOK_VOLATILE3
           || tok == TOK_GOTO) {
        اگلا();
    }

    astr1 = parse_asm_str();
    cstr_new_s(&astr);
    cstr_cat(&astr, astr1->ڈیٹا, astr1->سائز);

    nb_operands = 0;
    nb_outputs = 0;
    nb_labels = 0;
    must_subst = 0;
    memset(clobber_regs, 0, حجم(clobber_regs));
    اگر (tok == ':') {
        اگلا();
        must_subst = 1;
        /* output args */
        parse_asm_operands(operands, &nb_operands, 1);
        nb_outputs = nb_operands;
        اگر (tok == ':') {
            اگلا();
            اگر (tok != ')') {
                /* input args */
                parse_asm_operands(operands, &nb_operands, 0);
                اگر (tok == ':') {
                    /* clobber list */
                    /* XXX: handle registers */
                    اگلا();
                    برائے(;;) {
                        اگر (tok == ':')
                          توڑو;
                        اگر (tok != TOK_STR)
                            expect("string constant");
                        asm_clobber(clobber_regs, tokc.str.ڈیٹا);
                        اگلا();
                        اگر (tok == ',') {
                            اگلا();
                        } ورنہ {
                            توڑو;
                        }
                    }
                }
                اگر (tok == ':') {
                    /* goto labels */
                    اگلا();
                    برائے (;;) {
                        Sym *csym;
                        صحیح asmname;
                        اگر (nb_operands + nb_labels >= MAX_ASM_OPERANDS)
                          tcc_error("too many asm operands");
                        اگر (tok < TOK_UIDENT)
                          expect("label identifier");
			memset(operands + nb_operands + nb_labels, 0,
			       حجم(operands[0]));
                        operands[nb_operands + nb_labels++].id = tok;

                        csym = label_ڈھونڈو(tok);
                        اگر (!csym) {
                            csym = label_ڈالو(&global_label_ڈھیر, tok,
                                              LABEL_FORWARD);
                        } ورنہ {
                            اگر (csym->r == LABEL_DECLARED)
                              csym->r = LABEL_FORWARD;
                        }
                        اگلا();
                        asmname = asm_get_سابقہ_name(tcc_state, "LG.",
                                                      ++asmgoto_n);
                        اگر (!csym->c)
                          put_extern_sym2(csym, SHN_UNDEF, 0, 0, 1);
                        get_asm_sym(asmname, csym);
                        operands[nb_operands + nb_labels - 1].is_label = asmname;

                        اگر (tok != ',')
                          توڑو;
                        اگلا();
                    }
                }
            }
        }
    }
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    اگر (tok != ';')
        expect("';'");
    
    /* save all values in the memory */
    save_regs(0);

    /* compute constraints */
    asm_compute_constraints(operands, nb_operands, nb_outputs, 
                            clobber_regs, &برآمد_reg);

    /* substitute the operands in the asm string. No substitution is
       done if no operands (GCC behaviour) */
#اگر_تعریف_شدہ ASM_DEBUG
    لکھو("asm: \"%s\"\n", (حرف *)astr.ڈیٹا);
#اگر_ختم
    اگر (must_subst) {
        cstr_reset(astr1);
        cstr_cat(astr1, astr.ڈیٹا, astr.سائز);
        cstr_reset(&astr);
        subst_asm_operands(operands, nb_operands + nb_labels, &astr, astr1->ڈیٹا);
    }

#اگر_تعریف_شدہ ASM_DEBUG
    لکھو("subst_asm: \"%s\"\n", (حرف *)astr.ڈیٹا);
#اگر_ختم

    /* generate loads */
    asm_gen_رمز(operands, nb_operands, nb_outputs, 0, 
                 clobber_regs, برآمد_reg);    

    /* We don't allow switching section within inline asm to
       bleed out to surrounding code.  */
    sec = cur_متن_section;
    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr.ڈیٹا, astr.سائز - 1, 0);
    cstr_free_s(&astr);
    اگر (sec != cur_متن_section) {
        tcc_warning("inline asm tries to change current section");
        use_section1(tcc_state, sec);
    }

    /* restore the current C token */
    اگلا();

    /* store the output values if needed */
    asm_gen_رمز(operands, nb_operands, nb_outputs, 1, 
                 clobber_regs, برآمد_reg);
    
    /* free everything */
    برائے(i=0;i<nb_operands;i++) {
        vpop();
    }

}

ST_FUNC خالی asm_global_instr(خالی)
{
    CString *astr;
    صحیح saved_nocode_wanted = nocode_wanted;

    /* Global asm blocks are always emitted.  */
    nocode_wanted = 0;
    اگلا();
    astr = parse_asm_str();
    skip(')');
    /* NOTE: we do not eat the ';' so that we can restore the current
       token after the assembler parsing */
    اگر (tok != ';')
        expect("';'");
    
#اگر_تعریف_شدہ ASM_DEBUG
    لکھو("asm_global: \"%s\"\n", (حرف *)astr->ڈیٹا);
#اگر_ختم
    cur_متن_section = متن_section;
    ind = cur_متن_section->ڈیٹا_انحراف;

    /* assemble the string with tcc internal assembler */
    tcc_assemble_inline(tcc_state, astr->ڈیٹا, astr->سائز - 1, 1);
    
    cur_متن_section->ڈیٹا_انحراف = ind;

    /* restore the current C token */
    اگلا();

    nocode_wanted = saved_nocode_wanted;
}

/********************************************************/
#ورنہ
ST_FUNC صحیح tcc_assemble(TCCState *s1, صحیح do_preprocess)
{
    tcc_error("asm not supported");
}

ST_FUNC خالی asm_instr(خالی)
{
    tcc_error("inline asm() not supported");
}

ST_FUNC خالی asm_global_instr(خالی)
{
    tcc_error("inline asm() not supported");
}
#اگر_ختم /* CONFIG_TCC_ASM */
