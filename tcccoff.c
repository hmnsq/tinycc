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

#ಅನ್ತರ್ಭಾವ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

ಪೂರ್ಣಾಙ್ಕ nFuncs;
ವರ್ಣ Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
ವರ್ಣ AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_No_File_Ptr[MAX_FUNCS];
ಪೂರ್ಣಾಙ್ಕ EndAddress[MAX_FUNCS];
ಪೂರ್ಣಾಙ್ಕ Last_ಸಾಲು_No[MAX_FUNCS];
ಪೂರ್ಣಾಙ್ಕ FuncEntries[MAX_FUNCS];

ಪೂರ್ಣಾಙ್ಕ OutputTheSection(Section * sect);
short ಪೂರ್ಣಾಙ್ಕ GetCoffFlags(ಧ್ರುವ ವರ್ಣ *s);
ಶೂನ್ಯ Sort_ಚಿಹ್ನೆ_Table(TCCState *s1);
Section *FindSection(TCCState * s1, ಧ್ರುವ ವರ್ಣ *sname);

ಪೂರ್ಣಾಙ್ಕ C67_main_entry_point;

ಪೂರ್ಣಾಙ್ಕ Find_Coff_ಚಿಹ್ನೆ_Index(TCCState * s1, ಧ್ರುವ ವರ್ಣ *func_name);
ಪೂರ್ಣಾಙ್ಕ nb_syms;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short ಪೂರ್ಣಾಙ್ಕ dummy;
} AUXFUNC;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    ಪೂರ್ಣಾಙ್ಕ localframe;
    ಪೂರ್ಣಾಙ್ಕ nextentry;
    short ಪೂರ್ಣಾಙ್ಕ dummy;
} AUXBF;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    ಪೂರ್ಣಾಙ್ಕ dummy2;
    ಪೂರ್ಣಾಙ್ಕ dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    ಪೂರ್ಣಾಙ್ಕ file_pointer;
    ವರ್ಣ *Coff_str_table, *pCoff_str_table;
    ಪೂರ್ಣಾಙ್ಕ CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    ಪೂರ್ಣಾಙ್ಕ i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = ರಿಕ್ತ;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / ಪರಿಮಾಣ(Elf32_Sym);
    coff_nb_syms = Find_Coff_ಚಿಹ್ನೆ_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = ಪರಿಮಾಣ(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + ಪರಿಮಾಣ(AOUTHDR);

    CoffTextSectionNo = -1;

    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    ಯದಿ (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += ಪರಿಮಾಣ(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ಯದಿ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * ಪರಿಮಾಣ(ಸಂರಚನಾ reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	ಯದಿ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    ವರ್ಣ func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    ಧ್ರುವ ವರ್ಣ *incl_files[INCLUDE_ರಾಶಿ_SIZE];
	    ಪೂರ್ಣಾಙ್ಕ incl_index, len, last_ಸಾಲು_ಅಂಕೆ;
	    ಧ್ರುವ ವರ್ಣ *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_ಸಾಲು_ಅಂಕೆ = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    ಯಾವತ್ (sym < sym_end) {
		ವಿಕಲ್ಪ (sym->n_type) {
		    /* function start or end */
		ಪಕ್ಷ N_FUN:
		    ಯದಿ (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_ಮೌಲ್ಯ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     ಸಾಲು_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_ಸಾಲು_No[nFuncs++] = last_ಸಾಲು_ಅಂಕೆ + 1;
		    } ಅನ್ಯಥಾ {
			// beginning of function

			ಸಾಲು_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (ಧ್ರುವ ವರ್ಣ *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			ಯದಿ (!p) {
			    pstrcpy(func_name, ಪರಿಮಾಣ(func_name), str);
			    pstrcpy(Func[nFuncs], ಪರಿಮಾಣ(func_name), str);
			} ಅನ್ಯಥಾ {
			    len = p - str;
			    ಯದಿ (len > ಪರಿಮಾಣ(func_name) - 1)
				len = ಪರಿಮಾಣ(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], ಪರಿಮಾಣ(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_ಮೌಲ್ಯ;
		    }
		    ಭಙ್ಗ;

		    /* line number info */
		ಪಕ್ಷ N_SLINE:
		    pc = sym->n_ಮೌಲ್ಯ + func_addr;

		    last_pc = pc;
		    last_ಸಾಲು_ಅಂಕೆ = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    ಭಙ್ಗ;
		    /* include files */
		ಪಕ್ಷ N_BINCL:
		    str =
			(ಧ್ರುವ ವರ್ಣ *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    ಯದಿ (incl_index < INCLUDE_ರಾಶಿ_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    ಭಙ್ಗ;
		ಪಕ್ಷ N_EINCL:
		    ಯದಿ (incl_index > 1)
			incl_index--;
		    ಭಙ್ಗ;
		ಪಕ್ಷ N_SO:
		    ಯದಿ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } ಅನ್ಯಥಾ {
			str =
			    (ಧ್ರುವ ವರ್ಣ *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			ಯದಿ (len > 0 && str[len - 1] != '/')
			    ಗಚ್ಛ add_incl;
		    }
		    ಭಙ್ಗ;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    ಯದಿ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    ಅನ್ಯಥಾ
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, ಪರಿಮಾಣ(o_filehdr), 1, f);

    // write section headers
    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, ಪರಿಮಾಣ(SCNHDR), 1, f);
	}
    }

    // write raw data
    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ಯದಿ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * ಪರಿಮಾಣ(ಸಂರಚನಾ reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    ಯದಿ (s1->do_debug)
	Sort_ಚಿಹ್ನೆ_Table(s1);

    // write line no data

    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ಯದಿ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    ವರ್ಣ func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    ಧ್ರುವ ವರ್ಣ *incl_files[INCLUDE_ರಾಶಿ_SIZE];
	    ಪೂರ್ಣಾಙ್ಕ incl_index, len, last_ಸಾಲು_ಅಂಕೆ;
	    ಧ್ರುವ ವರ್ಣ *str, *p;

	    LINENO Coff_ಸಾಲು_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_ಸಾಲು_ಅಂಕೆ = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    ಯಾವತ್ (sym < sym_end) {
		ವಿಕಲ್ಪ (sym->n_type) {
		    /* function start or end */
		ಪಕ್ಷ N_FUN:
		    ಯದಿ (sym->n_strx == 0) {
			// end of function

			Coff_ಸಾಲು_No.l_addr.l_paddr = last_pc;
			Coff_ಸಾಲು_No.l_lnno = last_ಸಾಲು_ಅಂಕೆ + 1;
			fwrite(&Coff_ಸಾಲು_No, 6, 1, f);

			pc = sym->n_ಮೌಲ್ಯ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } ಅನ್ಯಥಾ {
			// beginning of function

			str =
			    (ಧ್ರುವ ವರ್ಣ *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			ಯದಿ (!p) {
			    pstrcpy(func_name, ಪರಿಮಾಣ(func_name), str);
			} ಅನ್ಯಥಾ {
			    len = p - str;
			    ಯದಿ (len > ಪರಿಮಾಣ(func_name) - 1)
				len = ಪರಿಮಾಣ(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_ಮೌಲ್ಯ;
			last_pc = func_addr;
			last_ಸಾಲು_ಅಂಕೆ = -1;

			// output a function begin

			Coff_ಸಾಲು_No.l_addr.l_symndx =
			    Find_Coff_ಚಿಹ್ನೆ_Index(s1, func_name);
			Coff_ಸಾಲು_No.l_lnno = 0;

			fwrite(&Coff_ಸಾಲು_No, 6, 1, f);
		    }
		    ಭಙ್ಗ;

		    /* line number info */
		ಪಕ್ಷ N_SLINE:
		    pc = sym->n_ಮೌಲ್ಯ + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_ಸಾಲು_No.l_addr.l_paddr = last_pc;

		    ಯದಿ (last_ಸಾಲು_ಅಂಕೆ == -1) {
			Coff_ಸಾಲು_No.l_lnno = sym->n_desc;
		    } ಅನ್ಯಥಾ {
			Coff_ಸಾಲು_No.l_lnno = last_ಸಾಲು_ಅಂಕೆ + 1;
		    }

		    fwrite(&Coff_ಸಾಲು_No, 6, 1, f);

		    last_pc = pc;
		    last_ಸಾಲು_ಅಂಕೆ = sym->n_desc;

		    ಭಙ್ಗ;

		    /* include files */
		ಪಕ್ಷ N_BINCL:
		    str =
			(ಧ್ರುವ ವರ್ಣ *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    ಯದಿ (incl_index < INCLUDE_ರಾಶಿ_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    ಭಙ್ಗ;
		ಪಕ್ಷ N_EINCL:
		    ಯದಿ (incl_index > 1)
			incl_index--;
		    ಭಙ್ಗ;
		ಪಕ್ಷ N_SO:
		    ಯದಿ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } ಅನ್ಯಥಾ {
			str =
			    (ಧ್ರುವ ವರ್ಣ *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			ಯದಿ (len > 0 && str[len - 1] != '/')
			    ಗಚ್ಛ add_incl2;
		    }
		    ಭಙ್ಗ;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    ಯದಿ (s1->do_debug) {
	ಪೂರ್ಣಾಙ್ಕ k;
	ಸಂರಚನಾ syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	ಪೂರ್ಣಾಙ್ಕ i;
	Elf32_Sym *p;
	ಧ್ರುವ ವರ್ಣ *name;
	ಪೂರ್ಣಾಙ್ಕ nstr;
	ಪೂರ್ಣಾಙ್ಕ n = 0;

	Coff_str_table = (ವರ್ಣ *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	ಪ್ರತಿ (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    ಪ್ರತಿ (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    ಯದಿ (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } ಅನ್ಯಥಾ {
		ಯದಿ (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    ಯದಿ (p->st_info == 4) {
		// put a filename symbol
		csym.n_ಮೌಲ್ಯ = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } ಅನ್ಯಥಾ ಯದಿ (p->st_info == 0x12) {
		// find the function data

		ಪ್ರತಿ (k = 0; k < nFuncs; k++) {
		    ಯದಿ (strcmp(name, Func[k]) == 0)
			ಭಙ್ಗ;
		}

		ಯದಿ (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_ಮೌಲ್ಯ = p->st_ಮೌಲ್ಯ;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_ಮೌಲ್ಯ;
		auxfunc.fileptr = ಸಾಲು_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_ಮೌಲ್ಯ = p->st_ಮೌಲ್ಯ;	// physical address
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
		csym.n_ಮೌಲ್ಯ = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_ಸಾಲು_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } ಅನ್ಯಥಾ {
		// try an put some type info

		ಯದಿ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} ಅನ್ಯಥಾ ಯದಿ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} ಅನ್ಯಥಾ ಯದಿ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} ಅನ್ಯಥಾ ಯದಿ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} ಅನ್ಯಥಾ ಯದಿ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} ಅನ್ಯಥಾ {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_ಮೌಲ್ಯ = p->st_ಮೌಲ್ಯ;
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

    ಯದಿ (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    ಪ್ರತ್ಯಾಗಮ 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

ಶೂನ್ಯ Sort_ಚಿಹ್ನೆ_Table(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    ವರ್ಣ *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * ಪರಿಮಾಣ(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    ಪ್ರತಿ (i = 0; i < nb_syms; i++) {
	ಯದಿ (p->st_info == 4) {
	    name = (ವರ್ಣ *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    ಪ್ರತಿ (j = 0; j < nb_syms; j++) {
		ಯದಿ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(ವರ್ಣ *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    ಪ್ರತಿ (k = 0; k < nFuncs; k++) {
			ಯದಿ (strcmp(name2, Func[k]) == 0)
			    ಭಙ್ಗ;
		    }

		    ಯದಿ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    ಯದಿ (strcmp(AssociatedFile[k], name) == 0) {
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
    ಪ್ರತಿ (i = 0; i < nb_syms; i++) {
	ಯದಿ (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    ಯದಿ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    ಪ್ರತಿ (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


ಪೂರ್ಣಾಙ್ಕ Find_Coff_ಚಿಹ್ನೆ_Index(TCCState *s1, ಧ್ರುವ ವರ್ಣ *func_name)
{
    ಪೂರ್ಣಾಙ್ಕ i, n = 0;
    Elf32_Sym *p;
    ವರ್ಣ *name;

    p = (Elf32_Sym *) symtab_section->data;

    ಪ್ರತಿ (i = 0; i < nb_syms; i++) {

	name = (ವರ್ಣ *) symtab_section->link->data + p->st_name;

	ಯದಿ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} ಅನ್ಯಥಾ ಯದಿ (p->st_info == 0x12) {

	    ಯದಿ (strcmp(func_name, name) == 0)
		ಪ್ರತ್ಯಾಗಮ n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} ಅನ್ಯಥಾ {
	    n += 2;
	}

	p++;
    }

    ಪ್ರತ್ಯಾಗಮ n;			// total number of symbols
}

ಪೂರ್ಣಾಙ್ಕ OutputTheSection(Section * sect)
{
    ಧ್ರುವ ವರ್ಣ *s = sect->name;

    ಯದಿ (!strcmp(s, ".text"))
	ಪ್ರತ್ಯಾಗಮ 1;
    ಅನ್ಯಥಾ ಯದಿ (!strcmp(s, ".data"))
	ಪ್ರತ್ಯಾಗಮ 1;
    ಅನ್ಯಥಾ
	ಪ್ರತ್ಯಾಗಮ 0;
}

short ಪೂರ್ಣಾಙ್ಕ GetCoffFlags(ಧ್ರುವ ವರ್ಣ *s)
{
    ಯದಿ (!strcmp(s, ".text"))
	ಪ್ರತ್ಯಾಗಮ STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    ಅನ್ಯಥಾ ಯದಿ (!strcmp(s, ".data"))
	ಪ್ರತ್ಯಾಗಮ STYP_DATA;
    ಅನ್ಯಥಾ ಯದಿ (!strcmp(s, ".bss"))
	ಪ್ರತ್ಯಾಗಮ STYP_BSS;
    ಅನ್ಯಥಾ ಯದಿ (!strcmp(s, ".stack"))
	ಪ್ರತ್ಯಾಗಮ STYP_BSS | STYP_ALIGN | 0x200;
    ಅನ್ಯಥಾ ಯದಿ (!strcmp(s, ".cinit"))
	ಪ್ರತ್ಯಾಗಮ STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    ಅನ್ಯಥಾ
	ಪ್ರತ್ಯಾಗಮ 0;
}

Section *FindSection(TCCState * s1, ಧ್ರುವ ವರ್ಣ *sname)
{
    Section *s;
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	ಯದಿ (!strcmp(sname, s->name))
	    ಪ್ರತ್ಯಾಗಮ s;
    }

    tcc_error("could not find section %s", sname);
    ಪ್ರತ್ಯಾಗಮ 0;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_coff(TCCState * s1, ಪೂರ್ಣಾಙ್ಕ fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned ಪೂರ್ಣಾಙ್ಕ str_size;
    ವರ್ಣ *Coff_str_table, *name;
    ಪೂರ್ಣಾಙ್ಕ i, k;
    ಸಂರಚನಾ syment csym;
    ವರ್ಣ name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    ಯದಿ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    ಯದಿ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    ಯದಿ (fread(&o_filehdr, ಪರಿಮಾಣ(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    ಯದಿ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    ಯದಿ (fread(&str_size, ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (ವರ್ಣ *) tcc_malloc(str_size);

    ಯದಿ (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    ಯದಿ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    ಪ್ರತಿ (i = 0; i < file_hdr.f_nsyms; i++) {
	ಯದಿ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	ಯದಿ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} ಅನ್ಯಥಾ {
	    name = csym._n._n_name;

	    ಯದಿ (name[7] != 0) {
		ಪ್ರತಿ (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	ಯದಿ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    ಯದಿ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_ಚಿಹ್ನೆ(s1, name, (ಶೂನ್ಯ*)(uintptr_t)csym.n_ಮೌಲ್ಯ);
	}
	// skip any aux records

	ಯದಿ (csym.n_numaux == 1) {
	    ಯದಿ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    ಪ್ರತ್ಯಾಗಮ 0;
}
