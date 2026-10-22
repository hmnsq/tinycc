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

#अन्तर्भाव "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

पूर्णांक nFuncs;
अक्षर Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
अक्षर AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
पूर्णांक ओळ_No_File_Ptr[MAX_FUNCS];
पूर्णांक EndAddress[MAX_FUNCS];
पूर्णांक Last_ओळ_No[MAX_FUNCS];
पूर्णांक FuncEntries[MAX_FUNCS];

पूर्णांक OutputTheSection(Section * sect);
लघु पूर्णांक GetCoffFlags(स्थिरांक अक्षर *s);
शून्य Sort_चिन्ह_Table(TCCState *s1);
Section *FindSection(TCCState * s1, स्थिरांक अक्षर *sname);

पूर्णांक C67_main_entry_point;

पूर्णांक Find_Coff_चिन्ह_Index(TCCState * s1, स्थिरांक अक्षर *func_name);
पूर्णांक nb_syms;

प्रकारव्याख्या संरचना {
    दीर्घ tag;
    दीर्घ size;
    दीर्घ fileptr;
    दीर्घ nextsym;
    लघु पूर्णांक dummy;
} AUXFUNC;

प्रकारव्याख्या संरचना {
    दीर्घ regmask;
    अचिन्हित लघु lineno;
    अचिन्हित लघु nentries;
    पूर्णांक localframe;
    पूर्णांक nextentry;
    लघु पूर्णांक dummy;
} AUXBF;

प्रकारव्याख्या संरचना {
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

    Coff_str_table = pCoff_str_table = रिक्त;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / आकार(Elf32_Sym);
    coff_nb_syms = Find_Coff_चिन्ह_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = आकार(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_TargetID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->data_offset;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->data_offset;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->data_offset;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_entry_point;	/* entry pt.                          */
    o_filehdr.text_start = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.data_start = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_pointer = FILHSZ + आकार(AOUTHDR);

    CoffTextSectionNo = -1;

    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    जर (CoffTextSectionNo == -1 && tcc_sect == stext)
		CoffTextSectionNo = NSectionsToOutput;	// rem which coff sect number the .text sect is

	    म_नकल(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_size = tcc_sect->data_offset;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_page = 0;	/* memory page id */

	    file_pointer += आकार(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    जर (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * आकार(संरचना reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	जर (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    अक्षर func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    अचिन्हित दीर्घ func_addr, last_pc, pc;
	    स्थिरांक अक्षर *incl_files[INCLUDE_चळत_SIZE];
	    पूर्णांक incl_index, len, last_ओळ_अंक;
	    स्थिरांक अक्षर *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_ओळ_अंक = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    पर्यंत (sym < sym_end) {
		निवड (sym->n_type) {
		    /* function start or end */
		स्थिती N_FUN:
		    जर (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_मूल्य + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     ओळ_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_ओळ_No[nFuncs++] = last_ओळ_अंक + 1;
		    } अन्यथा {
			// beginning of function

			ओळ_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (स्थिरांक अक्षर *) stabstr_section->data +
			    sym->n_strx;

			p = म_अक्षर(str, ':');
			जर (!p) {
			    pstrcpy(func_name, आकार(func_name), str);
			    pstrcpy(Func[nFuncs], आकार(func_name), str);
			} अन्यथा {
			    len = p - str;
			    जर (len > आकार(func_name) - 1)
				len = आकार(func_name) - 1;
			    स_नकल(func_name, str, len);
			    स_नकल(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], आकार(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_मूल्य;
		    }
		    थांबा;

		    /* line number info */
		स्थिती N_SLINE:
		    pc = sym->n_मूल्य + func_addr;

		    last_pc = pc;
		    last_ओळ_अंक = sym->n_desc;

		    /* XXX: slow! */
		    म_नकल(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    थांबा;
		    /* include files */
		स्थिती N_BINCL:
		    str =
			(स्थिरांक अक्षर *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    जर (incl_index < INCLUDE_चळत_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    थांबा;
		स्थिती N_EINCL:
		    जर (incl_index > 1)
			incl_index--;
		    थांबा;
		स्थिती N_SO:
		    जर (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } अन्यथा {
			str =
			    (स्थिरांक अक्षर *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = म_माप(str);
			जर (len > 0 && str[len - 1] != '/')
			    जा add_incl;
		    }
		    थांबा;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    जर (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    अन्यथा
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    ख_डालो(&file_hdr, FILHSZ, 1, f);
    ख_डालो(&o_filehdr, आकार(o_filehdr), 1, f);

    // write section headers
    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (OutputTheSection(tcc_sect)) {
	    ख_डालो(coff_sec, आकार(SCNHDR), 1, f);
	}
    }

    // write raw data
    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (OutputTheSection(tcc_sect)) {
	    ख_डालो(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    जर (coff_sec->s_nreloc > 0) {
		ख_डालो(tcc_sect->reloc,
		       coff_sec->s_nreloc * आकार(संरचना reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    जर (s1->do_debug)
	Sort_चिन्ह_Table(s1);

    // write line no data

    साठी (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जर (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    अक्षर func_name[128], last_func_name[128];
	    अचिन्हित दीर्घ func_addr, last_pc, pc;
	    स्थिरांक अक्षर *incl_files[INCLUDE_चळत_SIZE];
	    पूर्णांक incl_index, len, last_ओळ_अंक;
	    स्थिरांक अक्षर *str, *p;

	    LINENO Coff_ओळ_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_ओळ_अंक = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    पर्यंत (sym < sym_end) {
		निवड (sym->n_type) {
		    /* function start or end */
		स्थिती N_FUN:
		    जर (sym->n_strx == 0) {
			// end of function

			Coff_ओळ_No.l_addr.l_paddr = last_pc;
			Coff_ओळ_No.l_lnno = last_ओळ_अंक + 1;
			ख_डालो(&Coff_ओळ_No, 6, 1, f);

			pc = sym->n_मूल्य + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } अन्यथा {
			// beginning of function

			str =
			    (स्थिरांक अक्षर *) stabstr_section->data +
			    sym->n_strx;


			p = म_अक्षर(str, ':');
			जर (!p) {
			    pstrcpy(func_name, आकार(func_name), str);
			} अन्यथा {
			    len = p - str;
			    जर (len > आकार(func_name) - 1)
				len = आकार(func_name) - 1;
			    स_नकल(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_मूल्य;
			last_pc = func_addr;
			last_ओळ_अंक = -1;

			// output a function begin

			Coff_ओळ_No.l_addr.l_symndx =
			    Find_Coff_चिन्ह_Index(s1, func_name);
			Coff_ओळ_No.l_lnno = 0;

			ख_डालो(&Coff_ओळ_No, 6, 1, f);
		    }
		    थांबा;

		    /* line number info */
		स्थिती N_SLINE:
		    pc = sym->n_मूल्य + func_addr;


		    /* XXX: slow! */
		    म_नकल(last_func_name, func_name);

		    // output a line reference

		    Coff_ओळ_No.l_addr.l_paddr = last_pc;

		    जर (last_ओळ_अंक == -1) {
			Coff_ओळ_No.l_lnno = sym->n_desc;
		    } अन्यथा {
			Coff_ओळ_No.l_lnno = last_ओळ_अंक + 1;
		    }

		    ख_डालो(&Coff_ओळ_No, 6, 1, f);

		    last_pc = pc;
		    last_ओळ_अंक = sym->n_desc;

		    थांबा;

		    /* include files */
		स्थिती N_BINCL:
		    str =
			(स्थिरांक अक्षर *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    जर (incl_index < INCLUDE_चळत_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    थांबा;
		स्थिती N_EINCL:
		    जर (incl_index > 1)
			incl_index--;
		    थांबा;
		स्थिती N_SO:
		    जर (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } अन्यथा {
			str =
			    (स्थिरांक अक्षर *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = म_माप(str);
			जर (len > 0 && str[len - 1] != '/')
			    जा add_incl2;
		    }
		    थांबा;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    जर (s1->do_debug) {
	पूर्णांक k;
	संरचना syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	पूर्णांक i;
	Elf32_Sym *p;
	स्थिरांक अक्षर *name;
	पूर्णांक nstr;
	पूर्णांक n = 0;

	Coff_str_table = (अक्षर *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	साठी (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    साठी (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    जर (म_माप(name) <= 8) {
		म_नकल(csym._n._n_name, name);
	    } अन्यथा {
		जर (pCoff_str_table - Coff_str_table + म_माप(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		म_नकल(pCoff_str_table, name);
		pCoff_str_table += म_माप(name) + 1;	// skip over null
		nstr++;
	    }

	    जर (p->st_info == 4) {
		// put a filename symbol
		csym.n_मूल्य = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		ख_डालो(&csym, 18, 1, f);
		n++;

	    } अन्यथा जर (p->st_info == 0x12) {
		// find the function data

		साठी (k = 0; k < nFuncs; k++) {
		    जर (म_भेद(name, Func[k]) == 0)
			थांबा;
		}

		जर (k >= nFuncs) {
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
		auxfunc.size = EndAddress[k] - p->st_मूल्य;
		auxfunc.fileptr = ओळ_No_File_Ptr[k];
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
		auxef.lineno = Last_ओळ_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		ख_डालो(&auxef, 18, 1, f);

		n += 6;

	    } अन्यथा {
		// try an put some type info

		जर ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} अन्यथा जर ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} अन्यथा जर ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} अन्यथा जर ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} अन्यथा जर ((p->st_other & VT_BTYPE) == VT_BYTE) {
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
		auxfunc.size = 0x20;
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

    जर (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	ख_डालो(&i, 4, 1, f);

	// then write the strings
	ख_डालो(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    परत 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

शून्य Sort_चिन्ह_Table(TCCState *s1)
{
    पूर्णांक i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    अक्षर *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * आकार(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    साठी (i = 0; i < nb_syms; i++) {
	जर (p->st_info == 4) {
	    name = (अक्षर *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    साठी (j = 0; j < nb_syms; j++) {
		जर (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(अक्षर *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    साठी (k = 0; k < nFuncs; k++) {
			जर (म_भेद(name2, Func[k]) == 0)
			    थांबा;
		    }

		    जर (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    जर (म_भेद(AssociatedFile[k], name) == 0) {
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

    p = (Elf32_Sym *) symtab_section->data;
    साठी (i = 0; i < nb_syms; i++) {
	जर (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    जर (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    साठी (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


पूर्णांक Find_Coff_चिन्ह_Index(TCCState *s1, स्थिरांक अक्षर *func_name)
{
    पूर्णांक i, n = 0;
    Elf32_Sym *p;
    अक्षर *name;

    p = (Elf32_Sym *) symtab_section->data;

    साठी (i = 0; i < nb_syms; i++) {

	name = (अक्षर *) symtab_section->link->data + p->st_name;

	जर (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} अन्यथा जर (p->st_info == 0x12) {

	    जर (म_भेद(func_name, name) == 0)
		परत n;

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

    परत n;			// total number of symbols
}

पूर्णांक OutputTheSection(Section * sect)
{
    स्थिरांक अक्षर *s = sect->name;

    जर (!म_भेद(s, ".text"))
	परत 1;
    अन्यथा जर (!म_भेद(s, ".data"))
	परत 1;
    अन्यथा
	परत 0;
}

लघु पूर्णांक GetCoffFlags(स्थिरांक अक्षर *s)
{
    जर (!म_भेद(s, ".text"))
	परत STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    अन्यथा जर (!म_भेद(s, ".data"))
	परत STYP_DATA;
    अन्यथा जर (!म_भेद(s, ".bss"))
	परत STYP_BSS;
    अन्यथा जर (!म_भेद(s, ".stack"))
	परत STYP_BSS | STYP_ALIGN | 0x200;
    अन्यथा जर (!म_भेद(s, ".cinit"))
	परत STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    अन्यथा
	परत 0;
}

Section *FindSection(TCCState * s1, स्थिरांक अक्षर *sname)
{
    Section *s;
    पूर्णांक i;

    साठी (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	जर (!म_भेद(sname, s->name))
	    परत s;
    }

    tcc_error("could not find section %s", sname);
    परत 0;
}

ST_FUNC पूर्णांक tcc_load_coff(TCCState * s1, पूर्णांक fd)
{
// tktk TokenSym *ts;

    खाता *f;
    अचिन्हित पूर्णांक str_size;
    अक्षर *Coff_str_table, *name;
    पूर्णांक i, k;
    संरचना syment csym;
    अक्षर name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    जर (!f) {
	tcc_error("Unable to open .out file for input");
    }

    जर (ख_पढ़ो(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    जर (ख_पढ़ो(&o_filehdr, आकार(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    जर (ख_जाओ(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, शुरू_से))
	tcc_error("error reading .out file for input");

    जर (ख_पढ़ो(&str_size, आकार(पूर्णांक), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (अक्षर *) tcc_malloc(str_size);

    जर (ख_पढ़ो(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    जर (ख_जाओ(f, file_hdr.f_symptr, शुरू_से))
	tcc_error("error reading .out file for input");

    साठी (i = 0; i < file_hdr.f_nsyms; i++) {
	जर (ख_पढ़ो(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	जर (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} अन्यथा {
	    name = csym._n._n_name;

	    जर (name[7] != 0) {
		साठी (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	जर (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    जर (name[0] == '_' && म_भेद(name, "_main") != 0)
		name++;

	    tcc_add_चिन्ह(s1, name, (शून्य*)(uintptr_t)csym.n_मूल्य);
	}
	// skip any aux records

	जर (csym.n_numaux == 1) {
	    जर (ख_पढ़ो(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    परत 0;
}
