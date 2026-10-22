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
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

صحیح nFuncs;
نویسه Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
نویسه AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
صحیح سطر_No_File_Ptr[MAX_FUNCS];
صحیح EndAddress[MAX_FUNCS];
صحیح Last_سطر_No[MAX_FUNCS];
صحیح FuncEntries[MAX_FUNCS];

صحیح OutputTheSection(Section * sect);
short صحیح GetCoffFlags(ثابت نویسه *s);
تهی Sort_نماد_Table(TCCState *s1);
Section *FindSection(TCCState * s1, ثابت نویسه *sname);

صحیح C67_main_entry_point;

صحیح Find_Coff_نماد_Index(TCCState * s1, ثابت نویسه *func_name);
صحیح nb_syms;

تعریفنوع ساختار {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short صحیح dummy;
} AUXFUNC;

تعریفنوع ساختار {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    صحیح localframe;
    صحیح nextentry;
    short صحیح dummy;
} AUXBF;

تعریفنوع ساختار {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    صحیح dummy2;
    صحیح dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC صحیح tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    صحیح file_pointer;
    نویسه *Coff_str_table, *pCoff_str_table;
    صحیح CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    صحیح i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = پوچ;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / اندازه(Elf32_Sym);
    coff_nb_syms = Find_Coff_نماد_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = اندازه(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + اندازه(AOUTHDR);

    CoffTextSectionNo = -1;

    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    اگر (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += اندازه(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    اگر (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * اندازه(ساختار reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	اگر (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    نویسه func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    ثابت نویسه *incl_files[INCLUDE_پشته_SIZE];
	    صحیح incl_index, len, last_سطر_رقم;
	    ثابت نویسه *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_سطر_رقم = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    وقتی (sym < sym_end) {
		انتخاب (sym->n_type) {
		    /* function start or end */
		حالت N_FUN:
		    اگر (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_مقدار + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     سطر_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_سطر_No[nFuncs++] = last_سطر_رقم + 1;
		    } وگرنه {
			// beginning of function

			سطر_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (ثابت نویسه *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			اگر (!p) {
			    pstrcpy(func_name, اندازه(func_name), str);
			    pstrcpy(Func[nFuncs], اندازه(func_name), str);
			} وگرنه {
			    len = p - str;
			    اگر (len > اندازه(func_name) - 1)
				len = اندازه(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], اندازه(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_مقدار;
		    }
		    بشکن;

		    /* line number info */
		حالت N_SLINE:
		    pc = sym->n_مقدار + func_addr;

		    last_pc = pc;
		    last_سطر_رقم = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    بشکن;
		    /* include files */
		حالت N_BINCL:
		    str =
			(ثابت نویسه *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    اگر (incl_index < INCLUDE_پشته_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    بشکن;
		حالت N_EINCL:
		    اگر (incl_index > 1)
			incl_index--;
		    بشکن;
		حالت N_SO:
		    اگر (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } وگرنه {
			str =
			    (ثابت نویسه *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			اگر (len > 0 && str[len - 1] != '/')
			    برو add_incl;
		    }
		    بشکن;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    اگر (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    وگرنه
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, اندازه(o_filehdr), 1, f);

    // write section headers
    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, اندازه(SCNHDR), 1, f);
	}
    }

    // write raw data
    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    اگر (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * اندازه(ساختار reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    اگر (s1->do_debug)
	Sort_نماد_Table(s1);

    // write line no data

    برای (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	اگر (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    نویسه func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    ثابت نویسه *incl_files[INCLUDE_پشته_SIZE];
	    صحیح incl_index, len, last_سطر_رقم;
	    ثابت نویسه *str, *p;

	    LINENO Coff_سطر_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_سطر_رقم = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    وقتی (sym < sym_end) {
		انتخاب (sym->n_type) {
		    /* function start or end */
		حالت N_FUN:
		    اگر (sym->n_strx == 0) {
			// end of function

			Coff_سطر_No.l_addr.l_paddr = last_pc;
			Coff_سطر_No.l_lnno = last_سطر_رقم + 1;
			fwrite(&Coff_سطر_No, 6, 1, f);

			pc = sym->n_مقدار + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } وگرنه {
			// beginning of function

			str =
			    (ثابت نویسه *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			اگر (!p) {
			    pstrcpy(func_name, اندازه(func_name), str);
			} وگرنه {
			    len = p - str;
			    اگر (len > اندازه(func_name) - 1)
				len = اندازه(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_مقدار;
			last_pc = func_addr;
			last_سطر_رقم = -1;

			// output a function begin

			Coff_سطر_No.l_addr.l_symndx =
			    Find_Coff_نماد_Index(s1, func_name);
			Coff_سطر_No.l_lnno = 0;

			fwrite(&Coff_سطر_No, 6, 1, f);
		    }
		    بشکن;

		    /* line number info */
		حالت N_SLINE:
		    pc = sym->n_مقدار + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_سطر_No.l_addr.l_paddr = last_pc;

		    اگر (last_سطر_رقم == -1) {
			Coff_سطر_No.l_lnno = sym->n_desc;
		    } وگرنه {
			Coff_سطر_No.l_lnno = last_سطر_رقم + 1;
		    }

		    fwrite(&Coff_سطر_No, 6, 1, f);

		    last_pc = pc;
		    last_سطر_رقم = sym->n_desc;

		    بشکن;

		    /* include files */
		حالت N_BINCL:
		    str =
			(ثابت نویسه *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    اگر (incl_index < INCLUDE_پشته_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    بشکن;
		حالت N_EINCL:
		    اگر (incl_index > 1)
			incl_index--;
		    بشکن;
		حالت N_SO:
		    اگر (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } وگرنه {
			str =
			    (ثابت نویسه *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			اگر (len > 0 && str[len - 1] != '/')
			    برو add_incl2;
		    }
		    بشکن;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    اگر (s1->do_debug) {
	صحیح k;
	ساختار syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	صحیح i;
	Elf32_Sym *p;
	ثابت نویسه *name;
	صحیح nstr;
	صحیح n = 0;

	Coff_str_table = (نویسه *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	برای (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    برای (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    اگر (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } وگرنه {
		اگر (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    اگر (p->st_info == 4) {
		// put a filename symbol
		csym.n_مقدار = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } وگرنه اگر (p->st_info == 0x12) {
		// find the function data

		برای (k = 0; k < nFuncs; k++) {
		    اگر (strcmp(name, Func[k]) == 0)
			بشکن;
		}

		اگر (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_مقدار = p->st_مقدار;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_مقدار;
		auxfunc.fileptr = سطر_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_مقدار = p->st_مقدار;	// physical address
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
		csym.n_مقدار = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_سطر_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } وگرنه {
		// try an put some type info

		اگر ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} وگرنه اگر ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} وگرنه اگر ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} وگرنه اگر ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} وگرنه اگر ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} وگرنه {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_مقدار = p->st_مقدار;
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

    اگر (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    بازگشت 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

تهی Sort_نماد_Table(TCCState *s1)
{
    صحیح i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    نویسه *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * اندازه(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    برای (i = 0; i < nb_syms; i++) {
	اگر (p->st_info == 4) {
	    name = (نویسه *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    برای (j = 0; j < nb_syms; j++) {
		اگر (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(نویسه *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    برای (k = 0; k < nFuncs; k++) {
			اگر (strcmp(name2, Func[k]) == 0)
			    بشکن;
		    }

		    اگر (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    اگر (strcmp(AssociatedFile[k], name) == 0) {
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
    برای (i = 0; i < nb_syms; i++) {
	اگر (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    اگر (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    برای (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


صحیح Find_Coff_نماد_Index(TCCState *s1, ثابت نویسه *func_name)
{
    صحیح i, n = 0;
    Elf32_Sym *p;
    نویسه *name;

    p = (Elf32_Sym *) symtab_section->data;

    برای (i = 0; i < nb_syms; i++) {

	name = (نویسه *) symtab_section->link->data + p->st_name;

	اگر (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} وگرنه اگر (p->st_info == 0x12) {

	    اگر (strcmp(func_name, name) == 0)
		بازگشت n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} وگرنه {
	    n += 2;
	}

	p++;
    }

    بازگشت n;			// total number of symbols
}

صحیح OutputTheSection(Section * sect)
{
    ثابت نویسه *s = sect->name;

    اگر (!strcmp(s, ".text"))
	بازگشت 1;
    وگرنه اگر (!strcmp(s, ".data"))
	بازگشت 1;
    وگرنه
	بازگشت 0;
}

short صحیح GetCoffFlags(ثابت نویسه *s)
{
    اگر (!strcmp(s, ".text"))
	بازگشت STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    وگرنه اگر (!strcmp(s, ".data"))
	بازگشت STYP_DATA;
    وگرنه اگر (!strcmp(s, ".bss"))
	بازگشت STYP_BSS;
    وگرنه اگر (!strcmp(s, ".stack"))
	بازگشت STYP_BSS | STYP_ALIGN | 0x200;
    وگرنه اگر (!strcmp(s, ".cinit"))
	بازگشت STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    وگرنه
	بازگشت 0;
}

Section *FindSection(TCCState * s1, ثابت نویسه *sname)
{
    Section *s;
    صحیح i;

    برای (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	اگر (!strcmp(sname, s->name))
	    بازگشت s;
    }

    tcc_error("could not find section %s", sname);
    بازگشت 0;
}

ST_FUNC صحیح tcc_load_coff(TCCState * s1, صحیح fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned صحیح str_size;
    نویسه *Coff_str_table, *name;
    صحیح i, k;
    ساختار syment csym;
    نویسه name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    اگر (!f) {
	tcc_error("Unable to open .out file for input");
    }

    اگر (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    اگر (fread(&o_filehdr, اندازه(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    اگر (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    اگر (fread(&str_size, اندازه(صحیح), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (نویسه *) tcc_malloc(str_size);

    اگر (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    اگر (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    برای (i = 0; i < file_hdr.f_nsyms; i++) {
	اگر (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	اگر (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} وگرنه {
	    name = csym._n._n_name;

	    اگر (name[7] != 0) {
		برای (k = 0; k < 8; k++)
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

	    tcc_add_نماد(s1, name, (تهی*)(uintptr_t)csym.n_مقدار);
	}
	// skip any aux records

	اگر (csym.n_numaux == 1) {
	    اگر (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    بازگشت 0;
}
