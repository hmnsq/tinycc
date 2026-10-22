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

#شامل "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#تعریف_منسوخ _tcc_error

#تعریف_کرو MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#تعریف_کرو MAX_STR_جدول 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_سرخی[MAXNSCNS];

#تعریف_کرو MAX_FUNCS 1000
#تعریف_کرو MAX_FUNC_NAME_لمبائی 128

صحیح nFuncs;
حرف Func[MAX_FUNCS][MAX_FUNC_NAME_لمبائی];
حرف AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_لمبائی];
صحیح سطر_No_File_Ptr[MAX_FUNCS];
صحیح انتہا_پتہ[MAX_FUNCS];
صحیح آخری_سطر_No[MAX_FUNCS];
صحیح FuncEntries[MAX_FUNCS];

صحیح OutputTheSection(Section * sect);
مختصر صحیح GetCoffFlags(ثابت حرف *s);
خالی ترتیب_دو_علامت_جدول(TCCState *s1);
Section *ڈھونڈو_Section(TCCState * s1, ثابت حرف *sname);

صحیح C67_main_اندراج_نقطہ;

صحیح ڈھونڈو_Coff_علامت_اشاریہ(TCCState * s1, ثابت حرف *func_name);
صحیح nb_syms;

قسمتعریف ساخت {
    طویل لیبل;
    طویل سائز;
    طویل fileptr;
    طویل nextsym;
    مختصر صحیح dummy;
} AUXFUNC;

قسمتعریف ساخت {
    طویل regmask;
    غیرعلامتی مختصر lineno;
    غیرعلامتی مختصر nentries;
    صحیح localframe;
    صحیح nextentry;
    مختصر صحیح dummy;
} AUXBF;

قسمتعریف ساخت {
    طویل dummy;
    غیرعلامتی مختصر lineno;
    غیرعلامتی مختصر dummy1;
    صحیح dummy2;
    صحیح dummy3;
    غیرعلامتی مختصر dummy4;
} AUXEF;

ST_FUNC صحیح tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    صحیح file_اشارہ_گر;
    حرف *Coff_str_جدول, *p_Coff_str_جدول;
    صحیح Coff_متن_Section_No, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    صحیح i, NSections_مقصد_Output = 0;

    Coff_str_جدول = p_Coff_str_جدول = تہی;

    stext = ڈھونڈو_Section(s1, ".text");
    sdata = ڈھونڈو_Section(s1, ".data");
    sbss = ڈھونڈو_Section(s1, ".bss");

    nb_syms = symtab_section->ڈیٹا_انحراف / حجم(Elf32_Sym);
    coff_nb_syms = ڈھونڈو_Coff_علامت_اشاریہ(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = حجم(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_ہدف_ID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->ڈیٹا_انحراف;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->ڈیٹا_انحراف;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->ڈیٹا_انحراف;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_اندراج_نقطہ;	/* entry pt.                          */
    o_filehdr.متن_آغاز = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.ڈیٹا_آغاز = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_اشارہ_گر = FILHSZ + حجم(AOUTHDR);

    Coff_متن_Section_No = -1;

    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    NSections_مقصد_Output++;

	    اگر (Coff_متن_Section_No == -1 && tcc_sect == stext)
		Coff_متن_Section_No = NSections_مقصد_Output;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_سائز = tcc_sect->ڈیٹا_انحراف;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_صفحہ = 0;	/* memory page id */

	    file_اشارہ_گر += حجم(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSections_مقصد_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_اشارہ_گر;	/* file ptr to raw data for section */
	    file_اشارہ_گر += coff_sec->s_سائز;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    اگر (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_اشارہ_گر;	/* file ptr to relocation */
		file_اشارہ_گر += coff_sec->s_nreloc * حجم(ساخت reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	اگر (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_انتہا;
	    حرف func_name[MAX_FUNC_NAME_لمبائی],
		آخری_func_name[MAX_FUNC_NAME_لمبائی];
	    غیرعلامتی طویل func_addr, آخری_pc, pc;
	    ثابت حرف *incl_files[INCLUDE_ڈھیر_سائز];
	    صحیح incl_اشاریہ, len, آخری_سطر_عدد;
	    ثابت حرف *str, *p;

	    coff_sec->s_lnnoptr = file_اشارہ_گر;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_اشاریہ = 0;
	    آخری_func_name[0] = '\0';
	    آخری_pc = 0xffffffff;
	    آخری_سطر_عدد = 1;
	    sym = (Stab_Sym *) stab_section->ڈیٹا + 1;
	    sym_انتہا =
		(Stab_Sym *) (stab_section->ڈیٹا +
			      stab_section->ڈیٹا_انحراف);

	    nFuncs = 0;
	    جب (sym < sym_انتہا) {
		انتخاب (sym->n_type) {
		    /* function start or end */
		حالت N_FUN:
		    اگر (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_اشارہ_گر += LINESZ;

			pc = sym->n_قدر + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			انتہا_پتہ[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_اشارہ_گر -
			     سطر_No_File_Ptr[nFuncs]) / LINESZ - 1;
			آخری_سطر_No[nFuncs++] = آخری_سطر_عدد + 1;
		    } ورنہ {
			// beginning of function

			سطر_No_File_Ptr[nFuncs] = file_اشارہ_گر;
			coff_sec->s_nlnno++;
			file_اشارہ_گر += LINESZ;

			str =
			    (ثابت حرف *) stabstr_section->ڈیٹا +
			    sym->n_strx;

			p = strchr(str, ':');
			اگر (!p) {
			    pstrcpy(func_name, حجم(func_name), str);
			    pstrcpy(Func[nFuncs], حجم(func_name), str);
			} ورنہ {
			    len = p - str;
			    اگر (len > حجم(func_name) - 1)
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
		    توڑو;

		    /* line number info */
		حالت N_SLINE:
		    pc = sym->n_قدر + func_addr;

		    آخری_pc = pc;
		    آخری_سطر_عدد = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(آخری_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_اشارہ_گر += LINESZ;
		    توڑو;
		    /* include files */
		حالت N_BINCL:
		    str =
			(ثابت حرف *) stabstr_section->ڈیٹا + sym->n_strx;
		  جوڑو_incl:
		    اگر (incl_اشاریہ < INCLUDE_ڈھیر_سائز) {
			incl_files[incl_اشاریہ++] = str;
		    }
		    توڑو;
		حالت N_EINCL:
		    اگر (incl_اشاریہ > 1)
			incl_اشاریہ--;
		    توڑو;
		حالت N_SO:
		    اگر (sym->n_strx == 0) {
			incl_اشاریہ = 0;	/* end of translation unit */
		    } ورنہ {
			str =
			    (ثابت حرف *) stabstr_section->ڈیٹا +
			    sym->n_strx;
			/* do not add path */
			len = لڑی_لمبائی(str);
			اگر (len > 0 && str[len - 1] != '/')
			    جاؤ جوڑو_incl;
		    }
		    توڑو;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_اشارہ_گر;	/* file pointer to symtab */

    اگر (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    ورنہ
	file_hdr.f_nsyms = 0;

    file_اشارہ_گر += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, حجم(o_filehdr), 1, f);

    // write section headers
    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, حجم(SCNHDR), 1, f);
	}
    }

    // write raw data
    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->ڈیٹا, tcc_sect->ڈیٹا_انحراف, 1, f);
	}
    }

    // write relocation data
    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    اگر (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * حجم(ساخت reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    اگر (s1->do_debug)
	ترتیب_دو_علامت_جدول(s1);

    // write line no data

    برائے (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرخی[i];
	tcc_sect = s1->sections[i];

	اگر (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_انتہا;
	    حرف func_name[128], آخری_func_name[128];
	    غیرعلامتی طویل func_addr, آخری_pc, pc;
	    ثابت حرف *incl_files[INCLUDE_ڈھیر_سائز];
	    صحیح incl_اشاریہ, len, آخری_سطر_عدد;
	    ثابت حرف *str, *p;

	    LINENO Coff_سطر_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_اشاریہ = 0;
	    آخری_func_name[0] = '\0';
	    آخری_pc = 0;
	    آخری_سطر_عدد = 1;
	    sym = (Stab_Sym *) stab_section->ڈیٹا + 1;
	    sym_انتہا =
		(Stab_Sym *) (stab_section->ڈیٹا +
			      stab_section->ڈیٹا_انحراف);

	    جب (sym < sym_انتہا) {
		انتخاب (sym->n_type) {
		    /* function start or end */
		حالت N_FUN:
		    اگر (sym->n_strx == 0) {
			// end of function

			Coff_سطر_No.l_addr.l_paddr = آخری_pc;
			Coff_سطر_No.l_lnno = آخری_سطر_عدد + 1;
			fwrite(&Coff_سطر_No, 6, 1, f);

			pc = sym->n_قدر + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } ورنہ {
			// beginning of function

			str =
			    (ثابت حرف *) stabstr_section->ڈیٹا +
			    sym->n_strx;


			p = strchr(str, ':');
			اگر (!p) {
			    pstrcpy(func_name, حجم(func_name), str);
			} ورنہ {
			    len = p - str;
			    اگر (len > حجم(func_name) - 1)
				len = حجم(func_name) - 1;
			    حافظہ_نقل(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_قدر;
			آخری_pc = func_addr;
			آخری_سطر_عدد = -1;

			// output a function begin

			Coff_سطر_No.l_addr.l_symndx =
			    ڈھونڈو_Coff_علامت_اشاریہ(s1, func_name);
			Coff_سطر_No.l_lnno = 0;

			fwrite(&Coff_سطر_No, 6, 1, f);
		    }
		    توڑو;

		    /* line number info */
		حالت N_SLINE:
		    pc = sym->n_قدر + func_addr;


		    /* XXX: slow! */
		    strcpy(آخری_func_name, func_name);

		    // output a line reference

		    Coff_سطر_No.l_addr.l_paddr = آخری_pc;

		    اگر (آخری_سطر_عدد == -1) {
			Coff_سطر_No.l_lnno = sym->n_desc;
		    } ورنہ {
			Coff_سطر_No.l_lnno = آخری_سطر_عدد + 1;
		    }

		    fwrite(&Coff_سطر_No, 6, 1, f);

		    آخری_pc = pc;
		    آخری_سطر_عدد = sym->n_desc;

		    توڑو;

		    /* include files */
		حالت N_BINCL:
		    str =
			(ثابت حرف *) stabstr_section->ڈیٹا + sym->n_strx;
		  جوڑو_incl2:
		    اگر (incl_اشاریہ < INCLUDE_ڈھیر_سائز) {
			incl_files[incl_اشاریہ++] = str;
		    }
		    توڑو;
		حالت N_EINCL:
		    اگر (incl_اشاریہ > 1)
			incl_اشاریہ--;
		    توڑو;
		حالت N_SO:
		    اگر (sym->n_strx == 0) {
			incl_اشاریہ = 0;	/* end of translation unit */
		    } ورنہ {
			str =
			    (ثابت حرف *) stabstr_section->ڈیٹا +
			    sym->n_strx;
			/* do not add path */
			len = لڑی_لمبائی(str);
			اگر (len > 0 && str[len - 1] != '/')
			    جاؤ جوڑو_incl2;
		    }
		    توڑو;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    اگر (s1->do_debug) {
	صحیح k;
	ساخت syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	صحیح i;
	Elf32_Sym *p;
	ثابت حرف *name;
	صحیح nstr;
	صحیح n = 0;

	Coff_str_جدول = (حرف *) tcc_malloc(MAX_STR_جدول);
	p_Coff_str_جدول = Coff_str_جدول;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->ڈیٹا;


	برائے (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->ڈیٹا + p->st_name;

	    برائے (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    اگر (لڑی_لمبائی(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } ورنہ {
		اگر (p_Coff_str_جدول - Coff_str_جدول + لڑی_لمبائی(name) >
		    MAX_STR_جدول - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_انحراف =
		    p_Coff_str_جدول - Coff_str_جدول + 4;

		strcpy(p_Coff_str_جدول, name);
		p_Coff_str_جدول += لڑی_لمبائی(name) + 1;	// skip over null
		nstr++;
	    }

	    اگر (p->st_info == 4) {
		// put a filename symbol
		csym.n_قدر = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } ورنہ اگر (p->st_info == 0x12) {
		// find the function data

		برائے (k = 0; k < nFuncs; k++) {
		    اگر (strcmp(name, Func[k]) == 0)
			توڑو;
		}

		اگر (k >= nFuncs) {
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

		auxfunc.لیبل = 0;
		auxfunc.سائز = انتہا_پتہ[k] - p->st_قدر;
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
		csym.n_قدر = انتہا_پتہ[k];	// physical address  
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

	    } ورنہ {
		// try an put some type info

		اگر ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} ورنہ اگر ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} ورنہ اگر ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} ورنہ اگر ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} ورنہ اگر ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} ورنہ {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_قدر = p->st_قدر;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.لیبل = 0;
		auxfunc.سائز = 0x20;
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

    اگر (s1->do_debug) {
	// write string table

	// first write the size
	i = p_Coff_str_جدول - Coff_str_جدول;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_جدول, i, 1, f);

	tcc_free(Coff_str_جدول);
    }

    واپس 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

خالی ترتیب_دو_علامت_جدول(TCCState *s1)
{
    صحیح i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_جدول;
    حرف *name, *name2;

    New_جدول = (Elf32_Sym *) tcc_malloc(nb_syms * حجم(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->ڈیٹا;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    برائے (i = 0; i < nb_syms; i++) {
	اگر (p->st_info == 4) {
	    name = (حرف *) symtab_section->link->ڈیٹا + p->st_name;

	    // this is a file symbol, copy it over

	    New_جدول[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->ڈیٹا;

	    برائے (j = 0; j < nb_syms; j++) {
		اگر (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(حرف *) symtab_section->link->ڈیٹا + p2->st_name;

		    // find the function data index

		    برائے (k = 0; k < nFuncs; k++) {
			اگر (strcmp(name2, Func[k]) == 0)
			    توڑو;
		    }

		    اگر (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    اگر (strcmp(AssociatedFile[k], name) == 0) {
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

    p = (Elf32_Sym *) symtab_section->ڈیٹا;
    برائے (i = 0; i < nb_syms; i++) {
	اگر (p->st_info != 4 && p->st_info != 0x12) {
	    New_جدول[n++] = *p;
	}
	p++;
    }

    اگر (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->ڈیٹا;
    برائے (i = 0; i < nb_syms; i++) {
	*p++ = New_جدول[i];
    }

    tcc_free(New_جدول);
}


صحیح ڈھونڈو_Coff_علامت_اشاریہ(TCCState *s1, ثابت حرف *func_name)
{
    صحیح i, n = 0;
    Elf32_Sym *p;
    حرف *name;

    p = (Elf32_Sym *) symtab_section->ڈیٹا;

    برائے (i = 0; i < nb_syms; i++) {

	name = (حرف *) symtab_section->link->ڈیٹا + p->st_name;

	اگر (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} ورنہ اگر (p->st_info == 0x12) {

	    اگر (strcmp(func_name, name) == 0)
		واپس n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} ورنہ {
	    n += 2;
	}

	p++;
    }

    واپس n;			// total number of symbols
}

صحیح OutputTheSection(Section * sect)
{
    ثابت حرف *s = sect->name;

    اگر (!strcmp(s, ".text"))
	واپس 1;
    ورنہ اگر (!strcmp(s, ".data"))
	واپس 1;
    ورنہ
	واپس 0;
}

مختصر صحیح GetCoffFlags(ثابت حرف *s)
{
    اگر (!strcmp(s, ".text"))
	واپس STYP_متن | STYP_ڈیٹا | STYP_ALIGN | 0x400;
    ورنہ اگر (!strcmp(s, ".data"))
	واپس STYP_ڈیٹا;
    ورنہ اگر (!strcmp(s, ".bss"))
	واپس STYP_BSS;
    ورنہ اگر (!strcmp(s, ".stack"))
	واپس STYP_BSS | STYP_ALIGN | 0x200;
    ورنہ اگر (!strcmp(s, ".cinit"))
	واپس STYP_COPY | STYP_ڈیٹا | STYP_ALIGN | 0x200;
    ورنہ
	واپس 0;
}

Section *ڈھونڈو_Section(TCCState * s1, ثابت حرف *sname)
{
    Section *s;
    صحیح i;

    برائے (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	اگر (!strcmp(sname, s->name))
	    واپس s;
    }

    tcc_error("could not find section %s", sname);
    واپس 0;
}

ST_FUNC صحیح tcc_بھرو_coff(TCCState * s1, صحیح fd)
{
// tktk TokenSym *ts;

    FILE *f;
    غیرعلامتی صحیح str_سائز;
    حرف *Coff_str_جدول, *name;
    صحیح i, k;
    ساخت syment csym;
    حرف name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    اگر (!f) {
	tcc_error("Unable to open .out file for input");
    }

    اگر (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    اگر (fread(&o_filehdr, حجم(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    اگر (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    اگر (fread(&str_سائز, حجم(صحیح), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_جدول = (حرف *) tcc_malloc(str_سائز);

    اگر (fread(Coff_str_جدول, str_سائز - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    اگر (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    برائے (i = 0; i < file_hdr.f_nsyms; i++) {
	اگر (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	اگر (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_جدول + csym._n._n_n.n_انحراف - 4;
	} ورنہ {
	    name = csym._n._n_name;

	    اگر (name[7] != 0) {
		برائے (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	اگر (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    اگر (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_جوڑو_علامت(s1, name, (خالی*)(uintptr_t)csym.n_قدر);
	}
	// skip any aux records

	اگر (csym.n_numaux == 1) {
	    اگر (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    واپس 0;
}
