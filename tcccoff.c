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

#അന്തര്ഭാവ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

പൂർണ്ണസംഖ്യ nFuncs;
അക്ഷരം Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
അക്ഷരം AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
പൂർണ്ണസംഖ്യ വരി_No_File_Ptr[MAX_FUNCS];
പൂർണ്ണസംഖ്യ EndAddress[MAX_FUNCS];
പൂർണ്ണസംഖ്യ Last_വരി_No[MAX_FUNCS];
പൂർണ്ണസംഖ്യ FuncEntries[MAX_FUNCS];

പൂർണ്ണസംഖ്യ OutputTheSection(Section * sect);
short പൂർണ്ണസംഖ്യ GetCoffFlags(സ്ഥിരം അക്ഷരം *s);
ശൂന്യം Sort_ചിഹ്നം_Table(TCCState *s1);
Section *FindSection(TCCState * s1, സ്ഥിരം അക്ഷരം *sname);

പൂർണ്ണസംഖ്യ C67_main_entry_point;

പൂർണ്ണസംഖ്യ Find_Coff_ചിഹ്നം_Index(TCCState * s1, സ്ഥിരം അക്ഷരം *func_name);
പൂർണ്ണസംഖ്യ nb_syms;

തരനിർവചനം ഘടന {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short പൂർണ്ണസംഖ്യ dummy;
} AUXFUNC;

തരനിർവചനം ഘടന {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    പൂർണ്ണസംഖ്യ localframe;
    പൂർണ്ണസംഖ്യ nextentry;
    short പൂർണ്ണസംഖ്യ dummy;
} AUXBF;

തരനിർവചനം ഘടന {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    പൂർണ്ണസംഖ്യ dummy2;
    പൂർണ്ണസംഖ്യ dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC പൂർണ്ണസംഖ്യ tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    പൂർണ്ണസംഖ്യ file_pointer;
    അക്ഷരം *Coff_str_table, *pCoff_str_table;
    പൂർണ്ണസംഖ്യ CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    പൂർണ്ണസംഖ്യ i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = ശൂന്യ;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / വലുപ്പം(Elf32_Sym);
    coff_nb_syms = Find_Coff_ചിഹ്നം_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = വലുപ്പം(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + വലുപ്പം(AOUTHDR);

    CoffTextSectionNo = -1;

    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    എങ്കിൽ (CoffTextSectionNo == -1 && tcc_sect == stext)
		CoffTextSectionNo = NSectionsToOutput;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

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

	    file_pointer += വലുപ്പം(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    എങ്കിൽ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * വലുപ്പം(ഘടന reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	എങ്കിൽ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    അക്ഷരം func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    സ്ഥിരം അക്ഷരം *incl_files[INCLUDE_അട്ടി_SIZE];
	    പൂർണ്ണസംഖ്യ incl_index, len, last_വരി_അക്കം;
	    സ്ഥിരം അക്ഷരം *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_വരി_അക്കം = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    ആകുമ്പോൾ (sym < sym_end) {
		തിരഞ്ഞെടുപ്പ് (sym->n_type) {
		    /* function start or end */
		അവസ്ഥ N_FUN:
		    എങ്കിൽ (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_മൂല്യം + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     വരി_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_വരി_No[nFuncs++] = last_വരി_അക്കം + 1;
		    } അല്ലെങ്കിൽ {
			// beginning of function

			വരി_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (സ്ഥിരം അക്ഷരം *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			എങ്കിൽ (!p) {
			    pstrcpy(func_name, വലുപ്പം(func_name), str);
			    pstrcpy(Func[nFuncs], വലുപ്പം(func_name), str);
			} അല്ലെങ്കിൽ {
			    len = p - str;
			    എങ്കിൽ (len > വലുപ്പം(func_name) - 1)
				len = വലുപ്പം(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], വലുപ്പം(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_മൂല്യം;
		    }
		    നിർത്തുക;

		    /* line number info */
		അവസ്ഥ N_SLINE:
		    pc = sym->n_മൂല്യം + func_addr;

		    last_pc = pc;
		    last_വരി_അക്കം = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    നിർത്തുക;
		    /* include files */
		അവസ്ഥ N_BINCL:
		    str =
			(സ്ഥിരം അക്ഷരം *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    എങ്കിൽ (incl_index < INCLUDE_അട്ടി_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    നിർത്തുക;
		അവസ്ഥ N_EINCL:
		    എങ്കിൽ (incl_index > 1)
			incl_index--;
		    നിർത്തുക;
		അവസ്ഥ N_SO:
		    എങ്കിൽ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } അല്ലെങ്കിൽ {
			str =
			    (സ്ഥിരം അക്ഷരം *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			എങ്കിൽ (len > 0 && str[len - 1] != '/')
			    പോകുക add_incl;
		    }
		    നിർത്തുക;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    എങ്കിൽ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    അല്ലെങ്കിൽ
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, വലുപ്പം(o_filehdr), 1, f);

    // write section headers
    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, വലുപ്പം(SCNHDR), 1, f);
	}
    }

    // write raw data
    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    എങ്കിൽ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * വലുപ്പം(ഘടന reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    എങ്കിൽ (s1->do_debug)
	Sort_ചിഹ്നം_Table(s1);

    // write line no data

    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	എങ്കിൽ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    അക്ഷരം func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    സ്ഥിരം അക്ഷരം *incl_files[INCLUDE_അട്ടി_SIZE];
	    പൂർണ്ണസംഖ്യ incl_index, len, last_വരി_അക്കം;
	    സ്ഥിരം അക്ഷരം *str, *p;

	    LINENO Coff_വരി_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_വരി_അക്കം = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    ആകുമ്പോൾ (sym < sym_end) {
		തിരഞ്ഞെടുപ്പ് (sym->n_type) {
		    /* function start or end */
		അവസ്ഥ N_FUN:
		    എങ്കിൽ (sym->n_strx == 0) {
			// end of function

			Coff_വരി_No.l_addr.l_paddr = last_pc;
			Coff_വരി_No.l_lnno = last_വരി_അക്കം + 1;
			fwrite(&Coff_വരി_No, 6, 1, f);

			pc = sym->n_മൂല്യം + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } അല്ലെങ്കിൽ {
			// beginning of function

			str =
			    (സ്ഥിരം അക്ഷരം *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			എങ്കിൽ (!p) {
			    pstrcpy(func_name, വലുപ്പം(func_name), str);
			} അല്ലെങ്കിൽ {
			    len = p - str;
			    എങ്കിൽ (len > വലുപ്പം(func_name) - 1)
				len = വലുപ്പം(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_മൂല്യം;
			last_pc = func_addr;
			last_വരി_അക്കം = -1;

			// output a function begin

			Coff_വരി_No.l_addr.l_symndx =
			    Find_Coff_ചിഹ്നം_Index(s1, func_name);
			Coff_വരി_No.l_lnno = 0;

			fwrite(&Coff_വരി_No, 6, 1, f);
		    }
		    നിർത്തുക;

		    /* line number info */
		അവസ്ഥ N_SLINE:
		    pc = sym->n_മൂല്യം + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_വരി_No.l_addr.l_paddr = last_pc;

		    എങ്കിൽ (last_വരി_അക്കം == -1) {
			Coff_വരി_No.l_lnno = sym->n_desc;
		    } അല്ലെങ്കിൽ {
			Coff_വരി_No.l_lnno = last_വരി_അക്കം + 1;
		    }

		    fwrite(&Coff_വരി_No, 6, 1, f);

		    last_pc = pc;
		    last_വരി_അക്കം = sym->n_desc;

		    നിർത്തുക;

		    /* include files */
		അവസ്ഥ N_BINCL:
		    str =
			(സ്ഥിരം അക്ഷരം *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    എങ്കിൽ (incl_index < INCLUDE_അട്ടി_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    നിർത്തുക;
		അവസ്ഥ N_EINCL:
		    എങ്കിൽ (incl_index > 1)
			incl_index--;
		    നിർത്തുക;
		അവസ്ഥ N_SO:
		    എങ്കിൽ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } അല്ലെങ്കിൽ {
			str =
			    (സ്ഥിരം അക്ഷരം *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			എങ്കിൽ (len > 0 && str[len - 1] != '/')
			    പോകുക add_incl2;
		    }
		    നിർത്തുക;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    എങ്കിൽ (s1->do_debug) {
	പൂർണ്ണസംഖ്യ k;
	ഘടന syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	പൂർണ്ണസംഖ്യ i;
	Elf32_Sym *p;
	സ്ഥിരം അക്ഷരം *name;
	പൂർണ്ണസംഖ്യ nstr;
	പൂർണ്ണസംഖ്യ n = 0;

	Coff_str_table = (അക്ഷരം *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	വേണ്ടി (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    വേണ്ടി (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    എങ്കിൽ (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } അല്ലെങ്കിൽ {
		എങ്കിൽ (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    എങ്കിൽ (p->st_info == 4) {
		// put a filename symbol
		csym.n_മൂല്യം = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } അല്ലെങ്കിൽ എങ്കിൽ (p->st_info == 0x12) {
		// find the function data

		വേണ്ടി (k = 0; k < nFuncs; k++) {
		    എങ്കിൽ (strcmp(name, Func[k]) == 0)
			നിർത്തുക;
		}

		എങ്കിൽ (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_മൂല്യം = p->st_മൂല്യം;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_മൂല്യം;
		auxfunc.fileptr = വരി_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_മൂല്യം = p->st_മൂല്യം;	// physical address
		csym.n_scnum = CoffTextSectionNo;
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
		csym.n_മൂല്യം = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_വരി_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } അല്ലെങ്കിൽ {
		// try an put some type info

		എങ്കിൽ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} അല്ലെങ്കിൽ എങ്കിൽ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} അല്ലെങ്കിൽ എങ്കിൽ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} അല്ലെങ്കിൽ എങ്കിൽ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} അല്ലെങ്കിൽ എങ്കിൽ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} അല്ലെങ്കിൽ {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_മൂല്യം = p->st_മൂല്യം;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.tag = 0;
		auxfunc.size = 0x20;
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

    എങ്കിൽ (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    തിരികെ 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

ശൂന്യം Sort_ചിഹ്നം_Table(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    അക്ഷരം *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * വലുപ്പം(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    വേണ്ടി (i = 0; i < nb_syms; i++) {
	എങ്കിൽ (p->st_info == 4) {
	    name = (അക്ഷരം *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    വേണ്ടി (j = 0; j < nb_syms; j++) {
		എങ്കിൽ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(അക്ഷരം *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    വേണ്ടി (k = 0; k < nFuncs; k++) {
			എങ്കിൽ (strcmp(name2, Func[k]) == 0)
			    നിർത്തുക;
		    }

		    എങ്കിൽ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    എങ്കിൽ (strcmp(AssociatedFile[k], name) == 0) {
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
    വേണ്ടി (i = 0; i < nb_syms; i++) {
	എങ്കിൽ (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    എങ്കിൽ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    വേണ്ടി (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


പൂർണ്ണസംഖ്യ Find_Coff_ചിഹ്നം_Index(TCCState *s1, സ്ഥിരം അക്ഷരം *func_name)
{
    പൂർണ്ണസംഖ്യ i, n = 0;
    Elf32_Sym *p;
    അക്ഷരം *name;

    p = (Elf32_Sym *) symtab_section->data;

    വേണ്ടി (i = 0; i < nb_syms; i++) {

	name = (അക്ഷരം *) symtab_section->link->data + p->st_name;

	എങ്കിൽ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} അല്ലെങ്കിൽ എങ്കിൽ (p->st_info == 0x12) {

	    എങ്കിൽ (strcmp(func_name, name) == 0)
		തിരികെ n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} അല്ലെങ്കിൽ {
	    n += 2;
	}

	p++;
    }

    തിരികെ n;			// total number of symbols
}

പൂർണ്ണസംഖ്യ OutputTheSection(Section * sect)
{
    സ്ഥിരം അക്ഷരം *s = sect->name;

    എങ്കിൽ (!strcmp(s, ".text"))
	തിരികെ 1;
    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(s, ".data"))
	തിരികെ 1;
    അല്ലെങ്കിൽ
	തിരികെ 0;
}

short പൂർണ്ണസംഖ്യ GetCoffFlags(സ്ഥിരം അക്ഷരം *s)
{
    എങ്കിൽ (!strcmp(s, ".text"))
	തിരികെ STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(s, ".data"))
	തിരികെ STYP_DATA;
    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(s, ".bss"))
	തിരികെ STYP_BSS;
    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(s, ".stack"))
	തിരികെ STYP_BSS | STYP_ALIGN | 0x200;
    അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(s, ".cinit"))
	തിരികെ STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    അല്ലെങ്കിൽ
	തിരികെ 0;
}

Section *FindSection(TCCState * s1, സ്ഥിരം അക്ഷരം *sname)
{
    Section *s;
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	എങ്കിൽ (!strcmp(sname, s->name))
	    തിരികെ s;
    }

    tcc_error("could not find section %s", sname);
    തിരികെ 0;
}

ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_coff(TCCState * s1, പൂർണ്ണസംഖ്യ fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned പൂർണ്ണസംഖ്യ str_size;
    അക്ഷരം *Coff_str_table, *name;
    പൂർണ്ണസംഖ്യ i, k;
    ഘടന syment csym;
    അക്ഷരം name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    എങ്കിൽ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    എങ്കിൽ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    എങ്കിൽ (fread(&o_filehdr, വലുപ്പം(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    എങ്കിൽ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    എങ്കിൽ (fread(&str_size, വലുപ്പം(പൂർണ്ണസംഖ്യ), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (അക്ഷരം *) tcc_malloc(str_size);

    എങ്കിൽ (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    എങ്കിൽ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    വേണ്ടി (i = 0; i < file_hdr.f_nsyms; i++) {
	എങ്കിൽ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	എങ്കിൽ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} അല്ലെങ്കിൽ {
	    name = csym._n._n_name;

	    എങ്കിൽ (name[7] != 0) {
		വേണ്ടി (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	എങ്കിൽ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    എങ്കിൽ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_ചിഹ്നം(s1, name, (ശൂന്യം*)(uintptr_t)csym.n_മൂല്യം);
	}
	// skip any aux records

	എങ്കിൽ (csym.n_numaux == 1) {
	    എങ്കിൽ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    തിരികെ 0;
}
