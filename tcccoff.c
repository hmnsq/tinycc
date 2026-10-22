/*
 *  COFF file handling for TCC
 * 
 *  Copyright (c) 2003, 2004 TK
 *  Copyright (c) 2004 Fabrice Bellard
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

#ضمن "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#تعریف_رد _tcc_error

#تعریف_کرو MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#تعریف_کرو MAX_STR_جدول 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_سرخی[MAXNSCNS];

#تعریف_کرو MAX_FUNCS 1000
#تعریف_کرو MAX_FUNC_NAME_لمائی 128

صحيح nFuncs;
حرف Func[MAX_FUNCS][MAX_FUNC_NAME_لمائی];
حرف AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_لمائی];
صحيح سطر_No_File_Ptr[MAX_FUNCS];
صحيح سرا_پتہ[MAX_FUNCS];
صحيح آخری_سطر_No[MAX_FUNCS];
صحيح FuncEntries[MAX_FUNCS];

صحيح OutputTheSection(Section * sect);
چھوٹا صحيح GetCoffFlags(ثابت حرف *s);
فراغ ترتیب_دیو_علامت_جدول(TCCState *s1);
Section *لبھو_Section(TCCState * s1, ثابت حرف *sname);

صحيح C67_main_اندراج_نقطہ;

صحيح لبھو_Coff_علامت_اشاریہ(TCCState * s1, ثابت حرف *func_name);
صحيح nb_syms;

تعريفنوع بنية {
    لما ٹیگ;
    لما ناپ;
    لما fileptr;
    لما nextsym;
    چھوٹا صحيح dummy;
} AUXFUNC;

تعريفنوع بنية {
    لما regmask;
    بنانشانی چھوٹا lineno;
    بنانشانی چھوٹا nentries;
    صحيح localframe;
    صحيح nextentry;
    چھوٹا صحيح dummy;
} AUXBF;

تعريفنوع بنية {
    لما dummy;
    بنانشانی چھوٹا lineno;
    بنانشانی چھوٹا dummy1;
    صحيح dummy2;
    صحيح dummy3;
    بنانشانی چھوٹا dummy4;
} AUXEF;

ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    صحيح file_اشارہ_گر;
    حرف *Coff_str_جدول, *p_Coff_str_جدول;
    صحيح Coff_متن_Section_No, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    صحيح i, NSections_منزل_Output = 0;

    Coff_str_جدول = p_Coff_str_جدول = عدم;

    stext = لبھو_Section(s1, ".text");
    sdata = لبھو_Section(s1, ".data");
    sbss = لبھو_Section(s1, ".bss");

    nb_syms = symtab_section->انکڑے_وتھ / حجم(Elf32_Sym);
    coff_nb_syms = لبھو_Coff_علامت_اشاریہ(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = حجم(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_نشانہ_ID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->انکڑے_وتھ;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->انکڑے_وتھ;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->انکڑے_وتھ;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_اندراج_نقطہ;	/* entry pt.                          */
    o_filehdr.متن_شروع = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.انکڑے_شروع = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_اشارہ_گر = FILHSZ + حجم(AOUTHDR);

    Coff_متن_Section_No = -1;

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    NSections_منزل_Output++;

	    إذا (Coff_متن_Section_No == -1 && tcc_sect == stext)
		Coff_متن_Section_No = NSections_منزل_Output;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_ناپ = tcc_sect->انکڑے_وتھ;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_ورقہ = 0;	/* memory page id */

	    file_اشارہ_گر += حجم(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSections_منزل_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_اشارہ_گر;	/* file ptr to raw data for section */
	    file_اشارہ_گر += coff_sec->s_ناپ;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    إذا (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_اشارہ_گر;	/* file ptr to relocation */
		file_اشارہ_گر += coff_sec->s_nreloc * حجم(بنية reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	إذا (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_سرا;
	    حرف func_name[MAX_FUNC_NAME_لمائی],
		آخری_func_name[MAX_FUNC_NAME_لمائی];
	    بنانشانی لما func_addr, آخری_pc, pc;
	    ثابت حرف *incl_files[INCLUDE_ڈھیر_ناپ];
	    صحيح incl_اشاریہ, len, آخری_سطر_عدد;
	    ثابت حرف *str, *p;

	    coff_sec->s_lnnoptr = file_اشارہ_گر;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_اشاریہ = 0;
	    آخری_func_name[0] = '\0';
	    آخری_pc = 0xffffffff;
	    آخری_سطر_عدد = 1;
	    sym = (Stab_Sym *) stab_section->انکڑے + 1;
	    sym_سرا =
		(Stab_Sym *) (stab_section->انکڑے +
			      stab_section->انکڑے_وتھ);

	    nFuncs = 0;
	    طالما (sym < sym_سرا) {
		بدل (sym->n_type) {
		    /* function start or end */
		حالة N_FUN:
		    إذا (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_اشارہ_گر += LINESZ;

			pc = sym->n_قدر + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			سرا_پتہ[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_اشارہ_گر -
			     سطر_No_File_Ptr[nFuncs]) / LINESZ - 1;
			آخری_سطر_No[nFuncs++] = آخری_سطر_عدد + 1;
		    } وإلا {
			// beginning of function

			سطر_No_File_Ptr[nFuncs] = file_اشارہ_گر;
			coff_sec->s_nlnno++;
			file_اشارہ_گر += LINESZ;

			str =
			    (ثابت حرف *) stabstr_section->انکڑے +
			    sym->n_strx;

			p = strchr(str, ':');
			إذا (!p) {
			    pstrcpy(func_name, حجم(func_name), str);
			    pstrcpy(Func[nFuncs], حجم(func_name), str);
			} وإلا {
			    len = p - str;
			    إذا (len > حجم(func_name) - 1)
				len = حجم(func_name) - 1;
			    حافظہ_نقل(func_name, str, len);
			    حافظہ_نقل(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], حجم(func_name),
				incl_files[incl_اشاریہ - 1]);

			func_addr = sym->n_قدر;
		    }
		    اكسر;

		    /* line number info */
		حالة N_SLINE:
		    pc = sym->n_قدر + func_addr;

		    آخری_pc = pc;
		    آخری_سطر_عدد = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(آخری_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_اشارہ_گر += LINESZ;
		    اكسر;
		    /* include files */
		حالة N_BINCL:
		    str =
			(ثابت حرف *) stabstr_section->انکڑے + sym->n_strx;
		  جوڑو_incl:
		    إذا (incl_اشاریہ < INCLUDE_ڈھیر_ناپ) {
			incl_files[incl_اشاریہ++] = str;
		    }
		    اكسر;
		حالة N_EINCL:
		    إذا (incl_اشاریہ > 1)
			incl_اشاریہ--;
		    اكسر;
		حالة N_SO:
		    إذا (sym->n_strx == 0) {
			incl_اشاریہ = 0;	/* end of translation unit */
		    } وإلا {
			str =
			    (ثابت حرف *) stabstr_section->انکڑے +
			    sym->n_strx;
			/* do not add path */
			len = لڑی_لمبائی(str);
			إذا (len > 0 && str[len - 1] != '/')
			    اذهب جوڑو_incl;
		    }
		    اكسر;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_اشارہ_گر;	/* file pointer to symtab */

    إذا (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    وإلا
	file_hdr.f_nsyms = 0;

    file_اشارہ_گر += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, حجم(o_filehdr), 1, f);

    // write section headers
    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, حجم(SCNHDR), 1, f);
	}
    }

    // write raw data
    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->انکڑے, tcc_sect->انکڑے_وتھ, 1, f);
	}
    }

    // write relocation data
    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    إذا (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * حجم(بنية reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    إذا (s1->do_debug)
	ترتیب_دیو_علامت_جدول(s1);

    // write line no data

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	إذا (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_سرا;
	    حرف func_name[128], آخری_func_name[128];
	    بنانشانی لما func_addr, آخری_pc, pc;
	    ثابت حرف *incl_files[INCLUDE_ڈھیر_ناپ];
	    صحيح incl_اشاریہ, len, آخری_سطر_عدد;
	    ثابت حرف *str, *p;

	    LINENO Coff_سطر_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_اشاریہ = 0;
	    آخری_func_name[0] = '\0';
	    آخری_pc = 0;
	    آخری_سطر_عدد = 1;
	    sym = (Stab_Sym *) stab_section->انکڑے + 1;
	    sym_سرا =
		(Stab_Sym *) (stab_section->انکڑے +
			      stab_section->انکڑے_وتھ);

	    طالما (sym < sym_سرا) {
		بدل (sym->n_type) {
		    /* function start or end */
		حالة N_FUN:
		    إذا (sym->n_strx == 0) {
			// end of function

			Coff_سطر_No.l_addr.l_paddr = آخری_pc;
			Coff_سطر_No.l_lnno = آخری_سطر_عدد + 1;
			fwrite(&Coff_سطر_No, 6, 1, f);

			pc = sym->n_قدر + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } وإلا {
			// beginning of function

			str =
			    (ثابت حرف *) stabstr_section->انکڑے +
			    sym->n_strx;


			p = strchr(str, ':');
			إذا (!p) {
			    pstrcpy(func_name, حجم(func_name), str);
			} وإلا {
			    len = p - str;
			    إذا (len > حجم(func_name) - 1)
				len = حجم(func_name) - 1;
			    حافظہ_نقل(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_قدر;
			آخری_pc = func_addr;
			آخری_سطر_عدد = -1;

			// output a function begin

			Coff_سطر_No.l_addr.l_symndx =
			    لبھو_Coff_علامت_اشاریہ(s1, func_name);
			Coff_سطر_No.l_lnno = 0;

			fwrite(&Coff_سطر_No, 6, 1, f);
		    }
		    اكسر;

		    /* line number info */
		حالة N_SLINE:
		    pc = sym->n_قدر + func_addr;


		    /* XXX: slow! */
		    strcpy(آخری_func_name, func_name);

		    // output a line reference

		    Coff_سطر_No.l_addr.l_paddr = آخری_pc;

		    إذا (آخری_سطر_عدد == -1) {
			Coff_سطر_No.l_lnno = sym->n_desc;
		    } وإلا {
			Coff_سطر_No.l_lnno = آخری_سطر_عدد + 1;
		    }

		    fwrite(&Coff_سطر_No, 6, 1, f);

		    آخری_pc = pc;
		    آخری_سطر_عدد = sym->n_desc;

		    اكسر;

		    /* include files */
		حالة N_BINCL:
		    str =
			(ثابت حرف *) stabstr_section->انکڑے + sym->n_strx;
		  جوڑو_incl2:
		    إذا (incl_اشاریہ < INCLUDE_ڈھیر_ناپ) {
			incl_files[incl_اشاریہ++] = str;
		    }
		    اكسر;
		حالة N_EINCL:
		    إذا (incl_اشاریہ > 1)
			incl_اشاریہ--;
		    اكسر;
		حالة N_SO:
		    إذا (sym->n_strx == 0) {
			incl_اشاریہ = 0;	/* end of translation unit */
		    } وإلا {
			str =
			    (ثابت حرف *) stabstr_section->انکڑے +
			    sym->n_strx;
			/* do not add path */
			len = لڑی_لمبائی(str);
			إذا (len > 0 && str[len - 1] != '/')
			    اذهب جوڑو_incl2;
		    }
		    اكسر;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    إذا (s1->do_debug) {
	صحيح k;
	بنية syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	صحيح i;
	Elf32_Sym *p;
	ثابت حرف *name;
	صحيح nstr;
	صحيح n = 0;

	Coff_str_جدول = (حرف *) tcc_malloc(MAX_STR_جدول);
	p_Coff_str_جدول = Coff_str_جدول;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->انکڑے;


	لكل (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->انکڑے + p->st_name;

	    لكل (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    إذا (لڑی_لمبائی(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } وإلا {
		إذا (p_Coff_str_جدول - Coff_str_جدول + لڑی_لمبائی(name) >
		    MAX_STR_جدول - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_وتھ =
		    p_Coff_str_جدول - Coff_str_جدول + 4;

		strcpy(p_Coff_str_جدول, name);
		p_Coff_str_جدول += لڑی_لمبائی(name) + 1;	// skip over null
		nstr++;
	    }

	    إذا (p->st_info == 4) {
		// put a filename symbol
		csym.n_قدر = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } وإلا إذا (p->st_info == 0x12) {
		// find the function data

		لكل (k = 0; k < nFuncs; k++) {
		    إذا (strcmp(name, Func[k]) == 0)
			اكسر;
		}

		إذا (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_قدر = p->st_قدر;	// physical address
		csym.n_scnum = Coff_متن_Section_No;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.ٹیگ = 0;
		auxfunc.ناپ = سرا_پتہ[k] - p->st_قدر;
		auxfunc.fileptr = سطر_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_قدر = p->st_قدر;	// physical address
		csym.n_scnum = Coff_متن_Section_No;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxbf.regmask = 0;
		auxbf.lineno = 0;
		auxbf.nentries = FuncEntries[k];
		auxbf.localframe = 0;
		auxbf.nextentry = n + 6;
		auxbf.dummy = 0;
		fwrite(&auxbf, 18, 1, f);

		// put a .ef

		strcpy(csym._n._n_name, ".ef");
		csym.n_قدر = سرا_پتہ[k];	// physical address  
		csym.n_scnum = Coff_متن_Section_No;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = آخری_سطر_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } وإلا {
		// try an put some type info

		إذا ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} وإلا إذا ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} وإلا إذا ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} وإلا إذا ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} وإلا إذا ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} وإلا {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_قدر = p->st_قدر;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.ٹیگ = 0;
		auxfunc.ناپ = 0x20;
		auxfunc.fileptr = 0;
		auxfunc.nextsym = 0;
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);
		n++;
		n++;

	    }

	    p++;
	}
    }

    إذا (s1->do_debug) {
	// write string table

	// first write the size
	i = p_Coff_str_جدول - Coff_str_جدول;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_جدول, i, 1, f);

	tcc_free(Coff_str_جدول);
    }

    أرجع 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

فراغ ترتیب_دیو_علامت_جدول(TCCState *s1)
{
    صحيح i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_جدول;
    حرف *name, *name2;

    New_جدول = (Elf32_Sym *) tcc_malloc(nb_syms * حجم(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->انکڑے;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    لكل (i = 0; i < nb_syms; i++) {
	إذا (p->st_info == 4) {
	    name = (حرف *) symtab_section->link->انکڑے + p->st_name;

	    // this is a file symbol, copy it over

	    New_جدول[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->انکڑے;

	    لكل (j = 0; j < nb_syms; j++) {
		إذا (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(حرف *) symtab_section->link->انکڑے + p2->st_name;

		    // find the function data index

		    لكل (k = 0; k < nFuncs; k++) {
			إذا (strcmp(name2, Func[k]) == 0)
			    اكسر;
		    }

		    إذا (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    إذا (strcmp(AssociatedFile[k], name) == 0) {
			// yes they match copy it over

			New_جدول[n++] = *p2;
		    }
		}
		p2++;
	    }
	}
	p++;
    }

    // now all the filename and func symbols should have been copied over
    // copy all the rest over (all except file and funcs)

    p = (Elf32_Sym *) symtab_section->انکڑے;
    لكل (i = 0; i < nb_syms; i++) {
	إذا (p->st_info != 4 && p->st_info != 0x12) {
	    New_جدول[n++] = *p;
	}
	p++;
    }

    إذا (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->انکڑے;
    لكل (i = 0; i < nb_syms; i++) {
	*p++ = New_جدول[i];
    }

    tcc_free(New_جدول);
}


صحيح لبھو_Coff_علامت_اشاریہ(TCCState *s1, ثابت حرف *func_name)
{
    صحيح i, n = 0;
    Elf32_Sym *p;
    حرف *name;

    p = (Elf32_Sym *) symtab_section->انکڑے;

    لكل (i = 0; i < nb_syms; i++) {

	name = (حرف *) symtab_section->link->انکڑے + p->st_name;

	إذا (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} وإلا إذا (p->st_info == 0x12) {

	    إذا (strcmp(func_name, name) == 0)
		أرجع n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} وإلا {
	    n += 2;
	}

	p++;
    }

    أرجع n;			// total number of symbols
}

صحيح OutputTheSection(Section * sect)
{
    ثابت حرف *s = sect->name;

    إذا (!strcmp(s, ".text"))
	أرجع 1;
    وإلا إذا (!strcmp(s, ".data"))
	أرجع 1;
    وإلا
	أرجع 0;
}

چھوٹا صحيح GetCoffFlags(ثابت حرف *s)
{
    إذا (!strcmp(s, ".text"))
	أرجع STYP_متن | STYP_انکڑے | STYP_ALIGN | 0x400;
    وإلا إذا (!strcmp(s, ".data"))
	أرجع STYP_انکڑے;
    وإلا إذا (!strcmp(s, ".bss"))
	أرجع STYP_BSS;
    وإلا إذا (!strcmp(s, ".stack"))
	أرجع STYP_BSS | STYP_ALIGN | 0x200;
    وإلا إذا (!strcmp(s, ".cinit"))
	أرجع STYP_COPY | STYP_انکڑے | STYP_ALIGN | 0x200;
    وإلا
	أرجع 0;
}

Section *لبھو_Section(TCCState * s1, ثابت حرف *sname)
{
    Section *s;
    صحيح i;

    لكل (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	إذا (!strcmp(sname, s->name))
	    أرجع s;
    }

    tcc_error("could not find section %s", sname);
    أرجع 0;
}

ST_FUNC صحيح tcc_لدو_coff(TCCState * s1, صحيح fd)
{
// tktk TokenSym *ts;

    FILE *f;
    بنانشانی صحيح str_ناپ;
    حرف *Coff_str_جدول, *name;
    صحيح i, k;
    بنية syment csym;
    حرف name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    إذا (!f) {
	tcc_error("Unable to open .out file for input");
    }

    إذا (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    إذا (fread(&o_filehdr, حجم(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    إذا (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    إذا (fread(&str_ناپ, حجم(صحيح), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_جدول = (حرف *) tcc_malloc(str_ناپ);

    إذا (fread(Coff_str_جدول, str_ناپ - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    إذا (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    لكل (i = 0; i < file_hdr.f_nsyms; i++) {
	إذا (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	إذا (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_جدول + csym._n._n_n.n_وتھ - 4;
	} وإلا {
	    name = csym._n._n_name;

	    إذا (name[7] != 0) {
		لكل (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	إذا (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    إذا (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_جوڑو_علامت(s1, name, (فراغ*)(uintptr_t)csym.n_قدر);
	}
	// skip any aux records

	إذا (csym.n_numaux == 1) {
	    إذا (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    أرجع 0;
}
