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

#অন্তর্ভাব "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

পূর্ণাঙ্ক nFuncs;
বর্ণ Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
বর্ণ AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
পূর্ণাঙ্ক সারি_No_File_Ptr[MAX_FUNCS];
পূর্ণাঙ্ক EndAddress[MAX_FUNCS];
পূর্ণাঙ্ক Last_সারি_No[MAX_FUNCS];
পূর্ণাঙ্ক FuncEntries[MAX_FUNCS];

পূর্ণাঙ্ক OutputTheSection(Section * sect);
short পূর্ণাঙ্ক GetCoffFlags(ধ্রুব বর্ণ *s);
শূন্য Sort_প্রতীক_Table(TCCState *s1);
Section *FindSection(TCCState * s1, ধ্রুব বর্ণ *sname);

পূর্ণাঙ্ক C67_main_entry_point;

পূর্ণাঙ্ক Find_Coff_প্রতীক_Index(TCCState * s1, ধ্রুব বর্ণ *func_name);
পূর্ণাঙ্ক nb_syms;

প্রকারনির্দেশ সংরচনা {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short পূর্ণাঙ্ক dummy;
} AUXFUNC;

প্রকারনির্দেশ সংরচনা {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    পূর্ণাঙ্ক localframe;
    পূর্ণাঙ্ক nextentry;
    short পূর্ণাঙ্ক dummy;
} AUXBF;

প্রকারনির্দেশ সংরচনা {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    পূর্ণাঙ্ক dummy2;
    পূর্ণাঙ্ক dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC পূর্ণাঙ্ক tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    পূর্ণাঙ্ক file_pointer;
    বর্ণ *Coff_str_table, *pCoff_str_table;
    পূর্ণাঙ্ক CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    পূর্ণাঙ্ক i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = রিক্ত;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / পরিমাণ(Elf32_Sym);
    coff_nb_syms = Find_Coff_প্রতীক_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = পরিমাণ(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + পরিমাণ(AOUTHDR);

    CoffTextSectionNo = -1;

    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    যদি (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += পরিমাণ(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    যদি (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * পরিমাণ(সংরচনা reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	যদি (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    বর্ণ func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    ধ্রুব বর্ণ *incl_files[INCLUDE_স্তূপ_SIZE];
	    পূর্ণাঙ্ক incl_index, len, last_সারি_অঙ্ক;
	    ধ্রুব বর্ণ *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_সারি_অঙ্ক = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    যাবত্ (sym < sym_end) {
		বিকল্প (sym->n_type) {
		    /* function start or end */
		পক্ষ N_FUN:
		    যদি (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_মান + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     সারি_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_সারি_No[nFuncs++] = last_সারি_অঙ্ক + 1;
		    } অন্যথা {
			// beginning of function

			সারি_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (ধ্রুব বর্ণ *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			যদি (!p) {
			    pstrcpy(func_name, পরিমাণ(func_name), str);
			    pstrcpy(Func[nFuncs], পরিমাণ(func_name), str);
			} অন্যথা {
			    len = p - str;
			    যদি (len > পরিমাণ(func_name) - 1)
				len = পরিমাণ(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], পরিমাণ(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_মান;
		    }
		    ভঙ্গ;

		    /* line number info */
		পক্ষ N_SLINE:
		    pc = sym->n_মান + func_addr;

		    last_pc = pc;
		    last_সারি_অঙ্ক = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    ভঙ্গ;
		    /* include files */
		পক্ষ N_BINCL:
		    str =
			(ধ্রুব বর্ণ *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    যদি (incl_index < INCLUDE_স্তূপ_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    ভঙ্গ;
		পক্ষ N_EINCL:
		    যদি (incl_index > 1)
			incl_index--;
		    ভঙ্গ;
		পক্ষ N_SO:
		    যদি (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } অন্যথা {
			str =
			    (ধ্রুব বর্ণ *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			যদি (len > 0 && str[len - 1] != '/')
			    গচ্ছ add_incl;
		    }
		    ভঙ্গ;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    যদি (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    অন্যথা
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, পরিমাণ(o_filehdr), 1, f);

    // write section headers
    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, পরিমাণ(SCNHDR), 1, f);
	}
    }

    // write raw data
    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    যদি (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * পরিমাণ(সংরচনা reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    যদি (s1->do_debug)
	Sort_প্রতীক_Table(s1);

    // write line no data

    প্রতি (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	যদি (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    বর্ণ func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    ধ্রুব বর্ণ *incl_files[INCLUDE_স্তূপ_SIZE];
	    পূর্ণাঙ্ক incl_index, len, last_সারি_অঙ্ক;
	    ধ্রুব বর্ণ *str, *p;

	    LINENO Coff_সারি_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_সারি_অঙ্ক = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    যাবত্ (sym < sym_end) {
		বিকল্প (sym->n_type) {
		    /* function start or end */
		পক্ষ N_FUN:
		    যদি (sym->n_strx == 0) {
			// end of function

			Coff_সারি_No.l_addr.l_paddr = last_pc;
			Coff_সারি_No.l_lnno = last_সারি_অঙ্ক + 1;
			fwrite(&Coff_সারি_No, 6, 1, f);

			pc = sym->n_মান + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } অন্যথা {
			// beginning of function

			str =
			    (ধ্রুব বর্ণ *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			যদি (!p) {
			    pstrcpy(func_name, পরিমাণ(func_name), str);
			} অন্যথা {
			    len = p - str;
			    যদি (len > পরিমাণ(func_name) - 1)
				len = পরিমাণ(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_মান;
			last_pc = func_addr;
			last_সারি_অঙ্ক = -1;

			// output a function begin

			Coff_সারি_No.l_addr.l_symndx =
			    Find_Coff_প্রতীক_Index(s1, func_name);
			Coff_সারি_No.l_lnno = 0;

			fwrite(&Coff_সারি_No, 6, 1, f);
		    }
		    ভঙ্গ;

		    /* line number info */
		পক্ষ N_SLINE:
		    pc = sym->n_মান + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_সারি_No.l_addr.l_paddr = last_pc;

		    যদি (last_সারি_অঙ্ক == -1) {
			Coff_সারি_No.l_lnno = sym->n_desc;
		    } অন্যথা {
			Coff_সারি_No.l_lnno = last_সারি_অঙ্ক + 1;
		    }

		    fwrite(&Coff_সারি_No, 6, 1, f);

		    last_pc = pc;
		    last_সারি_অঙ্ক = sym->n_desc;

		    ভঙ্গ;

		    /* include files */
		পক্ষ N_BINCL:
		    str =
			(ধ্রুব বর্ণ *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    যদি (incl_index < INCLUDE_স্তূপ_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    ভঙ্গ;
		পক্ষ N_EINCL:
		    যদি (incl_index > 1)
			incl_index--;
		    ভঙ্গ;
		পক্ষ N_SO:
		    যদি (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } অন্যথা {
			str =
			    (ধ্রুব বর্ণ *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			যদি (len > 0 && str[len - 1] != '/')
			    গচ্ছ add_incl2;
		    }
		    ভঙ্গ;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    যদি (s1->do_debug) {
	পূর্ণাঙ্ক k;
	সংরচনা syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	পূর্ণাঙ্ক i;
	Elf32_Sym *p;
	ধ্রুব বর্ণ *name;
	পূর্ণাঙ্ক nstr;
	পূর্ণাঙ্ক n = 0;

	Coff_str_table = (বর্ণ *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	প্রতি (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    প্রতি (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    যদি (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } অন্যথা {
		যদি (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    যদি (p->st_info == 4) {
		// put a filename symbol
		csym.n_মান = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } অন্যথা যদি (p->st_info == 0x12) {
		// find the function data

		প্রতি (k = 0; k < nFuncs; k++) {
		    যদি (strcmp(name, Func[k]) == 0)
			ভঙ্গ;
		}

		যদি (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_মান = p->st_মান;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_মান;
		auxfunc.fileptr = সারি_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_মান = p->st_মান;	// physical address
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
		csym.n_মান = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_সারি_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } অন্যথা {
		// try an put some type info

		যদি ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} অন্যথা যদি ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} অন্যথা যদি ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} অন্যথা যদি ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} অন্যথা যদি ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} অন্যথা {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_মান = p->st_মান;
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

    যদি (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    প্রত্যাগম 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

শূন্য Sort_প্রতীক_Table(TCCState *s1)
{
    পূর্ণাঙ্ক i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    বর্ণ *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * পরিমাণ(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    প্রতি (i = 0; i < nb_syms; i++) {
	যদি (p->st_info == 4) {
	    name = (বর্ণ *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    প্রতি (j = 0; j < nb_syms; j++) {
		যদি (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(বর্ণ *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    প্রতি (k = 0; k < nFuncs; k++) {
			যদি (strcmp(name2, Func[k]) == 0)
			    ভঙ্গ;
		    }

		    যদি (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    যদি (strcmp(AssociatedFile[k], name) == 0) {
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
    প্রতি (i = 0; i < nb_syms; i++) {
	যদি (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    যদি (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    প্রতি (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


পূর্ণাঙ্ক Find_Coff_প্রতীক_Index(TCCState *s1, ধ্রুব বর্ণ *func_name)
{
    পূর্ণাঙ্ক i, n = 0;
    Elf32_Sym *p;
    বর্ণ *name;

    p = (Elf32_Sym *) symtab_section->data;

    প্রতি (i = 0; i < nb_syms; i++) {

	name = (বর্ণ *) symtab_section->link->data + p->st_name;

	যদি (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} অন্যথা যদি (p->st_info == 0x12) {

	    যদি (strcmp(func_name, name) == 0)
		প্রত্যাগম n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} অন্যথা {
	    n += 2;
	}

	p++;
    }

    প্রত্যাগম n;			// total number of symbols
}

পূর্ণাঙ্ক OutputTheSection(Section * sect)
{
    ধ্রুব বর্ণ *s = sect->name;

    যদি (!strcmp(s, ".text"))
	প্রত্যাগম 1;
    অন্যথা যদি (!strcmp(s, ".data"))
	প্রত্যাগম 1;
    অন্যথা
	প্রত্যাগম 0;
}

short পূর্ণাঙ্ক GetCoffFlags(ধ্রুব বর্ণ *s)
{
    যদি (!strcmp(s, ".text"))
	প্রত্যাগম STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    অন্যথা যদি (!strcmp(s, ".data"))
	প্রত্যাগম STYP_DATA;
    অন্যথা যদি (!strcmp(s, ".bss"))
	প্রত্যাগম STYP_BSS;
    অন্যথা যদি (!strcmp(s, ".stack"))
	প্রত্যাগম STYP_BSS | STYP_ALIGN | 0x200;
    অন্যথা যদি (!strcmp(s, ".cinit"))
	প্রত্যাগম STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    অন্যথা
	প্রত্যাগম 0;
}

Section *FindSection(TCCState * s1, ধ্রুব বর্ণ *sname)
{
    Section *s;
    পূর্ণাঙ্ক i;

    প্রতি (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	যদি (!strcmp(sname, s->name))
	    প্রত্যাগম s;
    }

    tcc_error("could not find section %s", sname);
    প্রত্যাগম 0;
}

ST_FUNC পূর্ণাঙ্ক tcc_load_coff(TCCState * s1, পূর্ণাঙ্ক fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned পূর্ণাঙ্ক str_size;
    বর্ণ *Coff_str_table, *name;
    পূর্ণাঙ্ক i, k;
    সংরচনা syment csym;
    বর্ণ name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    যদি (!f) {
	tcc_error("Unable to open .out file for input");
    }

    যদি (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    যদি (fread(&o_filehdr, পরিমাণ(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    যদি (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    যদি (fread(&str_size, পরিমাণ(পূর্ণাঙ্ক), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (বর্ণ *) tcc_malloc(str_size);

    যদি (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    যদি (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    প্রতি (i = 0; i < file_hdr.f_nsyms; i++) {
	যদি (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	যদি (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} অন্যথা {
	    name = csym._n._n_name;

	    যদি (name[7] != 0) {
		প্রতি (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	যদি (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    যদি (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_প্রতীক(s1, name, (শূন্য*)(uintptr_t)csym.n_মান);
	}
	// skip any aux records

	যদি (csym.n_numaux == 1) {
	    যদি (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    প্রত্যাগম 0;
}
