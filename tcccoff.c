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

#समावेश "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#अघोषित _tcc_error

#घोषणा MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#घोषणा MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#घोषणा MAX_FUNCS 1000
#घोषणा MAX_FUNC_NAME_लंबाई 128

पूर्णांक nFuncs;
अक्षर Func[MAX_FUNCS][MAX_FUNC_NAME_लंबाई];
अक्षर AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_लंबाई];
पूर्णांक पंक्ति_No_File_Ptr[MAX_FUNCS];
पूर्णांक EndAddress[MAX_FUNCS];
पूर्णांक Last_पंक्ति_No[MAX_FUNCS];
पूर्णांक FuncEntries[MAX_FUNCS];

पूर्णांक OutputTheSection(Section * sect);
लघु पूर्णांक GetCoffFlags(स्थिर अक्षर *s);
व्योम Sort_प्रतीक_Table(TCCState *s1);
Section *FindSection(TCCState * s1, स्थिर अक्षर *sname);

पूर्णांक C67_main_entry_point;

पूर्णांक Find_Coff_प्रतीक_सूचकांक(TCCState * s1, स्थिर अक्षर *func_name);
पूर्णांक nb_syms;

प्रकार काष्ठा {
    दीर्घ tag;
    दीर्घ आकार;
    दीर्घ fileptr;
    दीर्घ nextsym;
    लघु पूर्णांक dummy;
} AUXFUNC;

प्रकार काष्ठा {
    दीर्घ regmask;
    अचिन्हित लघु lineno;
    अचिन्हित लघु nentries;
    पूर्णांक localframe;
    पूर्णांक nextentry;
    लघु पूर्णांक dummy;
} AUXBF;

प्रकार काष्ठा {
    दीर्घ dummy;
    अचिन्हित लघु lineno;
    अचिन्हित लघु dummy1;
    पूर्णांक dummy2;
    पूर्णांक dummy3;
    अचिन्हित लघु dummy4;
} AUXEF;

ST_FUNC पूर्णांक tcc_output_coff(TCCState *s1, खाता *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    पूर्णांक file_pointer;
    अक्षर *Coff_str_table, *pCoff_str_table;
    पूर्णांक CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    पूर्णांक i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = शून्य;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->तथ्य_offset / माप(Elf32_Sym);
    coff_nb_syms = Find_Coff_प्रतीक_सूचकांक(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = माप(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_TargetID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->तथ्य_offset;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->तथ्य_offset;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->तथ्य_offset;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_entry_point;	/* entry pt.                          */
    o_filehdr.text_start = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.तथ्य_start = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_pointer = FILHSZ + माप(AOUTHDR);

    CoffTextSectionNo = -1;

    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    अगर (CoffTextSectionNo == -1 && tcc_sect == stext)
		CoffTextSectionNo = NSectionsToOutput;	// rem which coff sect number the .text sect is

	    म_नकल(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_आकार = tcc_sect->तथ्य_offset;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_page = 0;	/* memory page id */

	    file_pointer += माप(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_आकार;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    अगर (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * माप(काष्ठा reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	अगर (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    अक्षर func_name[MAX_FUNC_NAME_लंबाई],
		last_func_name[MAX_FUNC_NAME_लंबाई];
	    अचिन्हित दीर्घ func_addr, last_pc, pc;
	    स्थिर अक्षर *incl_files[INCLUDE_ढेर_आकार];
	    पूर्णांक incl_सूचकांक, len, last_पंक्ति_अंक;
	    स्थिर अक्षर *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_सूचकांक = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_पंक्ति_अंक = 1;
	    sym = (Stab_Sym *) stab_section->तथ्य + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->तथ्य +
			      stab_section->तथ्य_offset);

	    nFuncs = 0;
	    जबतक (sym < sym_end) {
		चयन (sym->n_type) {
		    /* function start or end */
		हाल N_FUN:
		    अगर (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_मूल्य + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     पंक्ति_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_पंक्ति_No[nFuncs++] = last_पंक्ति_अंक + 1;
		    } अन्यथा {
			// beginning of function

			पंक्ति_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (स्थिर अक्षर *) stabstr_section->तथ्य +
			    sym->n_strx;

			p = म_अक्षर(str, ':');
			अगर (!p) {
			    pstrcpy(func_name, माप(func_name), str);
			    pstrcpy(Func[nFuncs], माप(func_name), str);
			} अन्यथा {
			    len = p - str;
			    अगर (len > माप(func_name) - 1)
				len = माप(func_name) - 1;
			    स_नकल(func_name, str, len);
			    स_नकल(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], माप(func_name),
				incl_files[incl_सूचकांक - 1]);

			func_addr = sym->n_मूल्य;
		    }
		    अवरोध;

		    /* line number info */
		हाल N_SLINE:
		    pc = sym->n_मूल्य + func_addr;

		    last_pc = pc;
		    last_पंक्ति_अंक = sym->n_desc;

		    /* XXX: slow! */
		    म_नकल(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    अवरोध;
		    /* include files */
		हाल N_BINCL:
		    str =
			(स्थिर अक्षर *) stabstr_section->तथ्य + sym->n_strx;
		  add_incl:
		    अगर (incl_सूचकांक < INCLUDE_ढेर_आकार) {
			incl_files[incl_सूचकांक++] = str;
		    }
		    अवरोध;
		हाल N_EINCL:
		    अगर (incl_सूचकांक > 1)
			incl_सूचकांक--;
		    अवरोध;
		हाल N_SO:
		    अगर (sym->n_strx == 0) {
			incl_सूचकांक = 0;	/* end of translation unit */
		    } अन्यथा {
			str =
			    (स्थिर अक्षर *) stabstr_section->तथ्य +
			    sym->n_strx;
			/* do not add path */
			len = म_माप(str);
			अगर (len > 0 && str[len - 1] != '/')
			    जाओ add_incl;
		    }
		    अवरोध;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    अगर (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    अन्यथा
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    ख_डालो(&file_hdr, FILHSZ, 1, f);
    ख_डालो(&o_filehdr, माप(o_filehdr), 1, f);

    // write section headers
    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (OutputTheSection(tcc_sect)) {
	    ख_डालो(coff_sec, माप(SCNHDR), 1, f);
	}
    }

    // write raw data
    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (OutputTheSection(tcc_sect)) {
	    ख_डालो(tcc_sect->तथ्य, tcc_sect->तथ्य_offset, 1, f);
	}
    }

    // write relocation data
    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    अगर (coff_sec->s_nreloc > 0) {
		ख_डालो(tcc_sect->reloc,
		       coff_sec->s_nreloc * माप(काष्ठा reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    अगर (s1->do_debug)
	Sort_प्रतीक_Table(s1);

    // write line no data

    क्रम (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	अगर (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    अक्षर func_name[128], last_func_name[128];
	    अचिन्हित दीर्घ func_addr, last_pc, pc;
	    स्थिर अक्षर *incl_files[INCLUDE_ढेर_आकार];
	    पूर्णांक incl_सूचकांक, len, last_पंक्ति_अंक;
	    स्थिर अक्षर *str, *p;

	    LINENO Coff_पंक्ति_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_सूचकांक = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_पंक्ति_अंक = 1;
	    sym = (Stab_Sym *) stab_section->तथ्य + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->तथ्य +
			      stab_section->तथ्य_offset);

	    जबतक (sym < sym_end) {
		चयन (sym->n_type) {
		    /* function start or end */
		हाल N_FUN:
		    अगर (sym->n_strx == 0) {
			// end of function

			Coff_पंक्ति_No.l_addr.l_paddr = last_pc;
			Coff_पंक्ति_No.l_lnno = last_पंक्ति_अंक + 1;
			ख_डालो(&Coff_पंक्ति_No, 6, 1, f);

			pc = sym->n_मूल्य + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } अन्यथा {
			// beginning of function

			str =
			    (स्थिर अक्षर *) stabstr_section->तथ्य +
			    sym->n_strx;


			p = म_अक्षर(str, ':');
			अगर (!p) {
			    pstrcpy(func_name, माप(func_name), str);
			} अन्यथा {
			    len = p - str;
			    अगर (len > माप(func_name) - 1)
				len = माप(func_name) - 1;
			    स_नकल(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_मूल्य;
			last_pc = func_addr;
			last_पंक्ति_अंक = -1;

			// output a function begin

			Coff_पंक्ति_No.l_addr.l_symndx =
			    Find_Coff_प्रतीक_सूचकांक(s1, func_name);
			Coff_पंक्ति_No.l_lnno = 0;

			ख_डालो(&Coff_पंक्ति_No, 6, 1, f);
		    }
		    अवरोध;

		    /* line number info */
		हाल N_SLINE:
		    pc = sym->n_मूल्य + func_addr;


		    /* XXX: slow! */
		    म_नकल(last_func_name, func_name);

		    // output a line reference

		    Coff_पंक्ति_No.l_addr.l_paddr = last_pc;

		    अगर (last_पंक्ति_अंक == -1) {
			Coff_पंक्ति_No.l_lnno = sym->n_desc;
		    } अन्यथा {
			Coff_पंक्ति_No.l_lnno = last_पंक्ति_अंक + 1;
		    }

		    ख_डालो(&Coff_पंक्ति_No, 6, 1, f);

		    last_pc = pc;
		    last_पंक्ति_अंक = sym->n_desc;

		    अवरोध;

		    /* include files */
		हाल N_BINCL:
		    str =
			(स्थिर अक्षर *) stabstr_section->तथ्य + sym->n_strx;
		  add_incl2:
		    अगर (incl_सूचकांक < INCLUDE_ढेर_आकार) {
			incl_files[incl_सूचकांक++] = str;
		    }
		    अवरोध;
		हाल N_EINCL:
		    अगर (incl_सूचकांक > 1)
			incl_सूचकांक--;
		    अवरोध;
		हाल N_SO:
		    अगर (sym->n_strx == 0) {
			incl_सूचकांक = 0;	/* end of translation unit */
		    } अन्यथा {
			str =
			    (स्थिर अक्षर *) stabstr_section->तथ्य +
			    sym->n_strx;
			/* do not add path */
			len = म_माप(str);
			अगर (len > 0 && str[len - 1] != '/')
			    जाओ add_incl2;
		    }
		    अवरोध;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    अगर (s1->do_debug) {
	पूर्णांक k;
	काष्ठा syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	पूर्णांक i;
	Elf32_Sym *p;
	स्थिर अक्षर *name;
	पूर्णांक nstr;
	पूर्णांक n = 0;

	Coff_str_table = (अक्षर *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->तथ्य;


	क्रम (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->तथ्य + p->st_name;

	    क्रम (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    अगर (म_माप(name) <= 8) {
		म_नकल(csym._n._n_name, name);
	    } अन्यथा {
		अगर (pCoff_str_table - Coff_str_table + म_माप(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		म_नकल(pCoff_str_table, name);
		pCoff_str_table += म_माप(name) + 1;	// skip over null
		nstr++;
	    }

	    अगर (p->st_info == 4) {
		// put a filename symbol
		csym.n_मूल्य = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		ख_डालो(&csym, 18, 1, f);
		n++;

	    } अन्यथा अगर (p->st_info == 0x12) {
		// find the function data

		क्रम (k = 0; k < nFuncs; k++) {
		    अगर (म_भेद(name, Func[k]) == 0)
			अवरोध;
		}

		अगर (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_मूल्य = p->st_मूल्य;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		ख_डालो(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.आकार = EndAddress[k] - p->st_मूल्य;
		auxfunc.fileptr = पंक्ति_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		ख_डालो(&auxfunc, 18, 1, f);

		// put a .bf

		म_नकल(csym._n._n_name, ".bf");
		csym.n_मूल्य = p->st_मूल्य;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		ख_डालो(&csym, 18, 1, f);

		// now put aux info

		auxbf.regmask = 0;
		auxbf.lineno = 0;
		auxbf.nentries = FuncEntries[k];
		auxbf.localframe = 0;
		auxbf.nextentry = n + 6;
		auxbf.dummy = 0;
		ख_डालो(&auxbf, 18, 1, f);

		// put a .ef

		म_नकल(csym._n._n_name, ".ef");
		csym.n_मूल्य = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		ख_डालो(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_पंक्ति_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		ख_डालो(&auxef, 18, 1, f);

		n += 6;

	    } अन्यथा {
		// try an put some type info

		अगर ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} अन्यथा अगर ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} अन्यथा अगर ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} अन्यथा अगर ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} अन्यथा अगर ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} अन्यथा {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_मूल्य = p->st_मूल्य;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		ख_डालो(&csym, 18, 1, f);

		auxfunc.tag = 0;
		auxfunc.आकार = 0x20;
		auxfunc.fileptr = 0;
		auxfunc.nextsym = 0;
		auxfunc.dummy = 0;
		ख_डालो(&auxfunc, 18, 1, f);
		n++;
		n++;

	    }

	    p++;
	}
    }

    अगर (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	ख_डालो(&i, 4, 1, f);

	// then write the strings
	ख_डालो(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    वापस 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

व्योम Sort_प्रतीक_Table(TCCState *s1)
{
    पूर्णांक i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    अक्षर *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * माप(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->तथ्य;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    क्रम (i = 0; i < nb_syms; i++) {
	अगर (p->st_info == 4) {
	    name = (अक्षर *) symtab_section->link->तथ्य + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->तथ्य;

	    क्रम (j = 0; j < nb_syms; j++) {
		अगर (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(अक्षर *) symtab_section->link->तथ्य + p2->st_name;

		    // find the function data index

		    क्रम (k = 0; k < nFuncs; k++) {
			अगर (म_भेद(name2, Func[k]) == 0)
			    अवरोध;
		    }

		    अगर (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    अगर (म_भेद(AssociatedFile[k], name) == 0) {
			// yes they match copy it over

			NewTable[n++] = *p2;
		    }
		}
		p2++;
	    }
	}
	p++;
    }

    // now all the filename and func symbols should have been copied over
    // copy all the rest over (all except file and funcs)

    p = (Elf32_Sym *) symtab_section->तथ्य;
    क्रम (i = 0; i < nb_syms; i++) {
	अगर (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    अगर (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->तथ्य;
    क्रम (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


पूर्णांक Find_Coff_प्रतीक_सूचकांक(TCCState *s1, स्थिर अक्षर *func_name)
{
    पूर्णांक i, n = 0;
    Elf32_Sym *p;
    अक्षर *name;

    p = (Elf32_Sym *) symtab_section->तथ्य;

    क्रम (i = 0; i < nb_syms; i++) {

	name = (अक्षर *) symtab_section->link->तथ्य + p->st_name;

	अगर (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} अन्यथा अगर (p->st_info == 0x12) {

	    अगर (म_भेद(func_name, name) == 0)
		वापस n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} अन्यथा {
	    n += 2;
	}

	p++;
    }

    वापस n;			// total number of symbols
}

पूर्णांक OutputTheSection(Section * sect)
{
    स्थिर अक्षर *s = sect->name;

    अगर (!म_भेद(s, ".text"))
	वापस 1;
    अन्यथा अगर (!म_भेद(s, ".data"))
	वापस 1;
    अन्यथा
	वापस 0;
}

लघु पूर्णांक GetCoffFlags(स्थिर अक्षर *s)
{
    अगर (!म_भेद(s, ".text"))
	वापस STYP_TEXT | STYP_तथ्य | STYP_ALIGN | 0x400;
    अन्यथा अगर (!म_भेद(s, ".data"))
	वापस STYP_तथ्य;
    अन्यथा अगर (!म_भेद(s, ".bss"))
	वापस STYP_BSS;
    अन्यथा अगर (!म_भेद(s, ".stack"))
	वापस STYP_BSS | STYP_ALIGN | 0x200;
    अन्यथा अगर (!म_भेद(s, ".cinit"))
	वापस STYP_COPY | STYP_तथ्य | STYP_ALIGN | 0x200;
    अन्यथा
	वापस 0;
}

Section *FindSection(TCCState * s1, स्थिर अक्षर *sname)
{
    Section *s;
    पूर्णांक i;

    क्रम (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	अगर (!म_भेद(sname, s->name))
	    वापस s;
    }

    tcc_error("could not find section %s", sname);
    वापस 0;
}

ST_FUNC पूर्णांक tcc_load_coff(TCCState * s1, पूर्णांक fd)
{
// tktk TokenSym *ts;

    खाता *f;
    अचिन्हित पूर्णांक str_आकार;
    अक्षर *Coff_str_table, *name;
    पूर्णांक i, k;
    काष्ठा syment csym;
    अक्षर name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    अगर (!f) {
	tcc_error("Unable to open .out file for input");
    }

    अगर (ख_पढ़ो(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    अगर (ख_पढ़ो(&o_filehdr, माप(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    अगर (ख_जाओ(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, शुरू_से))
	tcc_error("error reading .out file for input");

    अगर (ख_पढ़ो(&str_आकार, माप(पूर्णांक), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (अक्षर *) tcc_malloc(str_आकार);

    अगर (ख_पढ़ो(Coff_str_table, str_आकार - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    अगर (ख_जाओ(f, file_hdr.f_symptr, शुरू_से))
	tcc_error("error reading .out file for input");

    क्रम (i = 0; i < file_hdr.f_nsyms; i++) {
	अगर (ख_पढ़ो(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	अगर (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} अन्यथा {
	    name = csym._n._n_name;

	    अगर (name[7] != 0) {
		क्रम (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	अगर (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    अगर (name[0] == '_' && म_भेद(name, "_main") != 0)
		name++;

	    tcc_add_प्रतीक(s1, name, (व्योम*)(uintptr_t)csym.n_मूल्य);
	}
	// skip any aux records

	अगर (csym.n_numaux == 1) {
	    अगर (ख_पढ़ो(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    वापस 0;
}
