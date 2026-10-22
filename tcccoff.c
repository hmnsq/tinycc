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
#تعریف_لغوه _tcc_error

#تعریف_کړه MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#تعریف_کړه MAX_STR_جدول 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_سرلیک[MAXNSCNS];

#تعریف_کړه MAX_FUNCS 1000
#تعریف_کړه MAX_FUNC_NAME_اوږدتیا 128

صحيح nFuncs;
حرف Func[MAX_FUNCS][MAX_FUNC_NAME_اوږدتیا];
حرف AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_اوږدتیا];
صحيح کرښه_No_File_Ptr[MAX_FUNCS];
صحيح پای_ټکی_پته[MAX_FUNCS];
صحيح وروستی_کرښه_No[MAX_FUNCS];
صحيح FuncEntries[MAX_FUNCS];

صحيح OutputTheSection(Section * sect);
لنډ صحيح GetCoffFlags(ثابت حرف *s);
فراغ ترتیبول_نښه_جدول(TCCState *s1);
Section *پیدا_کړه_Section(TCCState * s1, ثابت حرف *sname);

صحيح C67_main_ثبت_ټکی;

صحيح پیدا_کړه_Coff_نښه_شاخص(TCCState * s1, ثابت حرف *func_name);
صحيح nb_syms;

تعريفنوع بنية {
    اوږد نښان;
    اوږد اندازه;
    اوږد fileptr;
    اوږد nextsym;
    لنډ صحيح dummy;
} AUXFUNC;

تعريفنوع بنية {
    اوږد regmask;
    بینښه لنډ lineno;
    بینښه لنډ nentries;
    صحيح localframe;
    صحيح nextentry;
    لنډ صحيح dummy;
} AUXBF;

تعريفنوع بنية {
    اوږد dummy;
    بینښه لنډ lineno;
    بینښه لنډ dummy1;
    صحيح dummy2;
    صحيح dummy3;
    بینښه لنډ dummy4;
} AUXEF;

ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    صحيح file_اشاره_ګر;
    حرف *Coff_str_جدول, *p_Coff_str_جدول;
    صحيح Coff_متن_Section_No, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    صحيح i, NSections_منزل_Output = 0;

    Coff_str_جدول = p_Coff_str_جدول = عدم;

    stext = پیدا_کړه_Section(s1, ".text");
    sdata = پیدا_کړه_Section(s1, ".data");
    sbss = پیدا_کړه_Section(s1, ".bss");

    nb_syms = symtab_section->معلومات_دننه_واټن / حجم(Elf32_Sym);
    coff_nb_syms = پیدا_کړه_Coff_نښه_شاخص(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = حجم(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_موخه_ID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->معلومات_دننه_واټن;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->معلومات_دننه_واټن;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->معلومات_دننه_واټن;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_ثبت_ټکی;	/* entry pt.                          */
    o_filehdr.متن_پیل = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.معلومات_پیل = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_اشاره_ګر = FILHSZ + حجم(AOUTHDR);

    Coff_متن_Section_No = -1;

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    NSections_منزل_Output++;

	    إذا (Coff_متن_Section_No == -1 && tcc_sect == stext)
		Coff_متن_Section_No = NSections_منزل_Output;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_اندازه = tcc_sect->معلومات_دننه_واټن;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_پاڼه = 0;	/* memory page id */

	    file_اشاره_ګر += حجم(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSections_منزل_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_اشاره_ګر;	/* file ptr to raw data for section */
	    file_اشاره_ګر += coff_sec->s_اندازه;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    إذا (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_اشاره_ګر;	/* file ptr to relocation */
		file_اشاره_ګر += coff_sec->s_nreloc * حجم(بنية reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	إذا (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_پای_ټکی;
	    حرف func_name[MAX_FUNC_NAME_اوږدتیا],
		وروستی_func_name[MAX_FUNC_NAME_اوږدتیا];
	    بینښه اوږد func_addr, وروستی_pc, pc;
	    ثابت حرف *incl_files[INCLUDE_ډېری_اندازه];
	    صحيح incl_شاخص, len, وروستی_کرښه_عدد;
	    ثابت حرف *str, *p;

	    coff_sec->s_lnnoptr = file_اشاره_ګر;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_شاخص = 0;
	    وروستی_func_name[0] = '\0';
	    وروستی_pc = 0xffffffff;
	    وروستی_کرښه_عدد = 1;
	    sym = (Stab_Sym *) stab_section->معلومات + 1;
	    sym_پای_ټکی =
		(Stab_Sym *) (stab_section->معلومات +
			      stab_section->معلومات_دننه_واټن);

	    nFuncs = 0;
	    طالما (sym < sym_پای_ټکی) {
		بدل (sym->n_type) {
		    /* function start or end */
		حالة N_FUN:
		    إذا (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_اشاره_ګر += LINESZ;

			pc = sym->n_ارزښت + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			پای_ټکی_پته[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_اشاره_ګر -
			     کرښه_No_File_Ptr[nFuncs]) / LINESZ - 1;
			وروستی_کرښه_No[nFuncs++] = وروستی_کرښه_عدد + 1;
		    } وإلا {
			// beginning of function

			کرښه_No_File_Ptr[nFuncs] = file_اشاره_ګر;
			coff_sec->s_nlnno++;
			file_اشاره_ګر += LINESZ;

			str =
			    (ثابت حرف *) stabstr_section->معلومات +
			    sym->n_strx;

			p = strchr(str, ':');
			إذا (!p) {
			    pstrcpy(func_name, حجم(func_name), str);
			    pstrcpy(Func[nFuncs], حجم(func_name), str);
			} وإلا {
			    len = p - str;
			    إذا (len > حجم(func_name) - 1)
				len = حجم(func_name) - 1;
			    حافظه_نقل(func_name, str, len);
			    حافظه_نقل(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], حجم(func_name),
				incl_files[incl_شاخص - 1]);

			func_addr = sym->n_ارزښت;
		    }
		    اكسر;

		    /* line number info */
		حالة N_SLINE:
		    pc = sym->n_ارزښت + func_addr;

		    وروستی_pc = pc;
		    وروستی_کرښه_عدد = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(وروستی_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_اشاره_ګر += LINESZ;
		    اكسر;
		    /* include files */
		حالة N_BINCL:
		    str =
			(ثابت حرف *) stabstr_section->معلومات + sym->n_strx;
		  جمع_کړه_incl:
		    إذا (incl_شاخص < INCLUDE_ډېری_اندازه) {
			incl_files[incl_شاخص++] = str;
		    }
		    اكسر;
		حالة N_EINCL:
		    إذا (incl_شاخص > 1)
			incl_شاخص--;
		    اكسر;
		حالة N_SO:
		    إذا (sym->n_strx == 0) {
			incl_شاخص = 0;	/* end of translation unit */
		    } وإلا {
			str =
			    (ثابت حرف *) stabstr_section->معلومات +
			    sym->n_strx;
			/* do not add path */
			len = مزي_اوږدوالی(str);
			إذا (len > 0 && str[len - 1] != '/')
			    اذهب جمع_کړه_incl;
		    }
		    اكسر;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_اشاره_ګر;	/* file pointer to symtab */

    إذا (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    وإلا
	file_hdr.f_nsyms = 0;

    file_اشاره_ګر += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, حجم(o_filehdr), 1, f);

    // write section headers
    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, حجم(SCNHDR), 1, f);
	}
    }

    // write raw data
    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	إذا (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->معلومات, tcc_sect->معلومات_دننه_واټن, 1, f);
	}
    }

    // write relocation data
    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
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
	ترتیبول_نښه_جدول(s1);

    // write line no data

    لكل (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_سرلیک[i];
	tcc_sect = s1->sections[i];

	إذا (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_پای_ټکی;
	    حرف func_name[128], وروستی_func_name[128];
	    بینښه اوږد func_addr, وروستی_pc, pc;
	    ثابت حرف *incl_files[INCLUDE_ډېری_اندازه];
	    صحيح incl_شاخص, len, وروستی_کرښه_عدد;
	    ثابت حرف *str, *p;

	    LINENO Coff_کرښه_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_شاخص = 0;
	    وروستی_func_name[0] = '\0';
	    وروستی_pc = 0;
	    وروستی_کرښه_عدد = 1;
	    sym = (Stab_Sym *) stab_section->معلومات + 1;
	    sym_پای_ټکی =
		(Stab_Sym *) (stab_section->معلومات +
			      stab_section->معلومات_دننه_واټن);

	    طالما (sym < sym_پای_ټکی) {
		بدل (sym->n_type) {
		    /* function start or end */
		حالة N_FUN:
		    إذا (sym->n_strx == 0) {
			// end of function

			Coff_کرښه_No.l_addr.l_paddr = وروستی_pc;
			Coff_کرښه_No.l_lnno = وروستی_کرښه_عدد + 1;
			fwrite(&Coff_کرښه_No, 6, 1, f);

			pc = sym->n_ارزښت + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } وإلا {
			// beginning of function

			str =
			    (ثابت حرف *) stabstr_section->معلومات +
			    sym->n_strx;


			p = strchr(str, ':');
			إذا (!p) {
			    pstrcpy(func_name, حجم(func_name), str);
			} وإلا {
			    len = p - str;
			    إذا (len > حجم(func_name) - 1)
				len = حجم(func_name) - 1;
			    حافظه_نقل(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_ارزښت;
			وروستی_pc = func_addr;
			وروستی_کرښه_عدد = -1;

			// output a function begin

			Coff_کرښه_No.l_addr.l_symndx =
			    پیدا_کړه_Coff_نښه_شاخص(s1, func_name);
			Coff_کرښه_No.l_lnno = 0;

			fwrite(&Coff_کرښه_No, 6, 1, f);
		    }
		    اكسر;

		    /* line number info */
		حالة N_SLINE:
		    pc = sym->n_ارزښت + func_addr;


		    /* XXX: slow! */
		    strcpy(وروستی_func_name, func_name);

		    // output a line reference

		    Coff_کرښه_No.l_addr.l_paddr = وروستی_pc;

		    إذا (وروستی_کرښه_عدد == -1) {
			Coff_کرښه_No.l_lnno = sym->n_desc;
		    } وإلا {
			Coff_کرښه_No.l_lnno = وروستی_کرښه_عدد + 1;
		    }

		    fwrite(&Coff_کرښه_No, 6, 1, f);

		    وروستی_pc = pc;
		    وروستی_کرښه_عدد = sym->n_desc;

		    اكسر;

		    /* include files */
		حالة N_BINCL:
		    str =
			(ثابت حرف *) stabstr_section->معلومات + sym->n_strx;
		  جمع_کړه_incl2:
		    إذا (incl_شاخص < INCLUDE_ډېری_اندازه) {
			incl_files[incl_شاخص++] = str;
		    }
		    اكسر;
		حالة N_EINCL:
		    إذا (incl_شاخص > 1)
			incl_شاخص--;
		    اكسر;
		حالة N_SO:
		    إذا (sym->n_strx == 0) {
			incl_شاخص = 0;	/* end of translation unit */
		    } وإلا {
			str =
			    (ثابت حرف *) stabstr_section->معلومات +
			    sym->n_strx;
			/* do not add path */
			len = مزي_اوږدوالی(str);
			إذا (len > 0 && str[len - 1] != '/')
			    اذهب جمع_کړه_incl2;
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

	p = (Elf32_Sym *) symtab_section->معلومات;


	لكل (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->معلومات + p->st_name;

	    لكل (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    إذا (مزي_اوږدوالی(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } وإلا {
		إذا (p_Coff_str_جدول - Coff_str_جدول + مزي_اوږدوالی(name) >
		    MAX_STR_جدول - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_دننه_واټن =
		    p_Coff_str_جدول - Coff_str_جدول + 4;

		strcpy(p_Coff_str_جدول, name);
		p_Coff_str_جدول += مزي_اوږدوالی(name) + 1;	// skip over null
		nstr++;
	    }

	    إذا (p->st_info == 4) {
		// put a filename symbol
		csym.n_ارزښت = 33;	// ?????
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

		csym.n_ارزښت = p->st_ارزښت;	// physical address
		csym.n_scnum = Coff_متن_Section_No;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.نښان = 0;
		auxfunc.اندازه = پای_ټکی_پته[k] - p->st_ارزښت;
		auxfunc.fileptr = کرښه_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_ارزښت = p->st_ارزښت;	// physical address
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
		csym.n_ارزښت = پای_ټکی_پته[k];	// physical address  
		csym.n_scnum = Coff_متن_Section_No;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = وروستی_کرښه_No[k];
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


		csym.n_ارزښت = p->st_ارزښت;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.نښان = 0;
		auxfunc.اندازه = 0x20;
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

فراغ ترتیبول_نښه_جدول(TCCState *s1)
{
    صحيح i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_جدول;
    حرف *name, *name2;

    New_جدول = (Elf32_Sym *) tcc_malloc(nb_syms * حجم(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->معلومات;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    لكل (i = 0; i < nb_syms; i++) {
	إذا (p->st_info == 4) {
	    name = (حرف *) symtab_section->link->معلومات + p->st_name;

	    // this is a file symbol, copy it over

	    New_جدول[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->معلومات;

	    لكل (j = 0; j < nb_syms; j++) {
		إذا (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(حرف *) symtab_section->link->معلومات + p2->st_name;

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

    p = (Elf32_Sym *) symtab_section->معلومات;
    لكل (i = 0; i < nb_syms; i++) {
	إذا (p->st_info != 4 && p->st_info != 0x12) {
	    New_جدول[n++] = *p;
	}
	p++;
    }

    إذا (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->معلومات;
    لكل (i = 0; i < nb_syms; i++) {
	*p++ = New_جدول[i];
    }

    tcc_free(New_جدول);
}


صحيح پیدا_کړه_Coff_نښه_شاخص(TCCState *s1, ثابت حرف *func_name)
{
    صحيح i, n = 0;
    Elf32_Sym *p;
    حرف *name;

    p = (Elf32_Sym *) symtab_section->معلومات;

    لكل (i = 0; i < nb_syms; i++) {

	name = (حرف *) symtab_section->link->معلومات + p->st_name;

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

لنډ صحيح GetCoffFlags(ثابت حرف *s)
{
    إذا (!strcmp(s, ".text"))
	أرجع STYP_متن | STYP_معلومات | STYP_ALIGN | 0x400;
    وإلا إذا (!strcmp(s, ".data"))
	أرجع STYP_معلومات;
    وإلا إذا (!strcmp(s, ".bss"))
	أرجع STYP_BSS;
    وإلا إذا (!strcmp(s, ".stack"))
	أرجع STYP_BSS | STYP_ALIGN | 0x200;
    وإلا إذا (!strcmp(s, ".cinit"))
	أرجع STYP_COPY | STYP_معلومات | STYP_ALIGN | 0x200;
    وإلا
	أرجع 0;
}

Section *پیدا_کړه_Section(TCCState * s1, ثابت حرف *sname)
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

ST_FUNC صحيح tcc_بارول_coff(TCCState * s1, صحيح fd)
{
// tktk TokenSym *ts;

    FILE *f;
    بینښه صحيح str_اندازه;
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

    إذا (fread(&str_اندازه, حجم(صحيح), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_جدول = (حرف *) tcc_malloc(str_اندازه);

    إذا (fread(Coff_str_جدول, str_اندازه - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    إذا (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    لكل (i = 0; i < file_hdr.f_nsyms; i++) {
	إذا (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	إذا (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_جدول + csym._n._n_n.n_دننه_واټن - 4;
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

	    tcc_جمع_کړه_نښه(s1, name, (فراغ*)(uintptr_t)csym.n_ارزښت);
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
