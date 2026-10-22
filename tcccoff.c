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

#அந்தர்பாவ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

முழு nFuncs;
எழுத்து Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
எழுத்து AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
முழு வரி_No_File_Ptr[MAX_FUNCS];
முழு EndAddress[MAX_FUNCS];
முழு Last_வரி_No[MAX_FUNCS];
முழு FuncEntries[MAX_FUNCS];

முழு OutputTheSection(Section * sect);
short முழு GetCoffFlags(மாறிலி எழுத்து *s);
வெறுமை Sort_குறியீடு_Table(TCCState *s1);
Section *FindSection(TCCState * s1, மாறிலி எழுத்து *sname);

முழு C67_main_entry_point;

முழு Find_Coff_குறியீடு_Index(TCCState * s1, மாறிலி எழுத்து *func_name);
முழு nb_syms;

வகைவரை கட்டமைப்பு {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short முழு dummy;
} AUXFUNC;

வகைவரை கட்டமைப்பு {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    முழு localframe;
    முழு nextentry;
    short முழு dummy;
} AUXBF;

வகைவரை கட்டமைப்பு {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    முழு dummy2;
    முழு dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC முழு tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    முழு file_pointer;
    எழுத்து *Coff_str_table, *pCoff_str_table;
    முழு CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    முழு i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = வெற்று;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / அளவு(Elf32_Sym);
    coff_nb_syms = Find_Coff_குறியீடு_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = அளவு(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + அளவு(AOUTHDR);

    CoffTextSectionNo = -1;

    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    எனில் (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += அளவு(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    எனில் (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * அளவு(கட்டமைப்பு reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	எனில் (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    எழுத்து func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    மாறிலி எழுத்து *incl_files[INCLUDE_அடுக்கு_SIZE];
	    முழு incl_index, len, last_வரி_இலக்கம்;
	    மாறிலி எழுத்து *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_வரி_இலக்கம் = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    போது (sym < sym_end) {
		தேர்வு (sym->n_type) {
		    /* function start or end */
		நிலை N_FUN:
		    எனில் (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_மதிப்பு + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     வரி_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_வரி_No[nFuncs++] = last_வரி_இலக்கம் + 1;
		    } இல்லையெனில் {
			// beginning of function

			வரி_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (மாறிலி எழுத்து *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			எனில் (!p) {
			    pstrcpy(func_name, அளவு(func_name), str);
			    pstrcpy(Func[nFuncs], அளவு(func_name), str);
			} இல்லையெனில் {
			    len = p - str;
			    எனில் (len > அளவு(func_name) - 1)
				len = அளவு(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], அளவு(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_மதிப்பு;
		    }
		    நிறுத்து;

		    /* line number info */
		நிலை N_SLINE:
		    pc = sym->n_மதிப்பு + func_addr;

		    last_pc = pc;
		    last_வரி_இலக்கம் = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    நிறுத்து;
		    /* include files */
		நிலை N_BINCL:
		    str =
			(மாறிலி எழுத்து *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    எனில் (incl_index < INCLUDE_அடுக்கு_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    நிறுத்து;
		நிலை N_EINCL:
		    எனில் (incl_index > 1)
			incl_index--;
		    நிறுத்து;
		நிலை N_SO:
		    எனில் (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } இல்லையெனில் {
			str =
			    (மாறிலி எழுத்து *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			எனில் (len > 0 && str[len - 1] != '/')
			    செல் add_incl;
		    }
		    நிறுத்து;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    எனில் (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    இல்லையெனில்
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, அளவு(o_filehdr), 1, f);

    // write section headers
    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, அளவு(SCNHDR), 1, f);
	}
    }

    // write raw data
    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    எனில் (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * அளவு(கட்டமைப்பு reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    எனில் (s1->do_debug)
	Sort_குறியீடு_Table(s1);

    // write line no data

    க்கு (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	எனில் (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    எழுத்து func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    மாறிலி எழுத்து *incl_files[INCLUDE_அடுக்கு_SIZE];
	    முழு incl_index, len, last_வரி_இலக்கம்;
	    மாறிலி எழுத்து *str, *p;

	    LINENO Coff_வரி_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_வரி_இலக்கம் = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    போது (sym < sym_end) {
		தேர்வு (sym->n_type) {
		    /* function start or end */
		நிலை N_FUN:
		    எனில் (sym->n_strx == 0) {
			// end of function

			Coff_வரி_No.l_addr.l_paddr = last_pc;
			Coff_வரி_No.l_lnno = last_வரி_இலக்கம் + 1;
			fwrite(&Coff_வரி_No, 6, 1, f);

			pc = sym->n_மதிப்பு + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } இல்லையெனில் {
			// beginning of function

			str =
			    (மாறிலி எழுத்து *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			எனில் (!p) {
			    pstrcpy(func_name, அளவு(func_name), str);
			} இல்லையெனில் {
			    len = p - str;
			    எனில் (len > அளவு(func_name) - 1)
				len = அளவு(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_மதிப்பு;
			last_pc = func_addr;
			last_வரி_இலக்கம் = -1;

			// output a function begin

			Coff_வரி_No.l_addr.l_symndx =
			    Find_Coff_குறியீடு_Index(s1, func_name);
			Coff_வரி_No.l_lnno = 0;

			fwrite(&Coff_வரி_No, 6, 1, f);
		    }
		    நிறுத்து;

		    /* line number info */
		நிலை N_SLINE:
		    pc = sym->n_மதிப்பு + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_வரி_No.l_addr.l_paddr = last_pc;

		    எனில் (last_வரி_இலக்கம் == -1) {
			Coff_வரி_No.l_lnno = sym->n_desc;
		    } இல்லையெனில் {
			Coff_வரி_No.l_lnno = last_வரி_இலக்கம் + 1;
		    }

		    fwrite(&Coff_வரி_No, 6, 1, f);

		    last_pc = pc;
		    last_வரி_இலக்கம் = sym->n_desc;

		    நிறுத்து;

		    /* include files */
		நிலை N_BINCL:
		    str =
			(மாறிலி எழுத்து *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    எனில் (incl_index < INCLUDE_அடுக்கு_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    நிறுத்து;
		நிலை N_EINCL:
		    எனில் (incl_index > 1)
			incl_index--;
		    நிறுத்து;
		நிலை N_SO:
		    எனில் (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } இல்லையெனில் {
			str =
			    (மாறிலி எழுத்து *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			எனில் (len > 0 && str[len - 1] != '/')
			    செல் add_incl2;
		    }
		    நிறுத்து;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    எனில் (s1->do_debug) {
	முழு k;
	கட்டமைப்பு syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	முழு i;
	Elf32_Sym *p;
	மாறிலி எழுத்து *name;
	முழு nstr;
	முழு n = 0;

	Coff_str_table = (எழுத்து *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	க்கு (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    க்கு (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    எனில் (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } இல்லையெனில் {
		எனில் (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    எனில் (p->st_info == 4) {
		// put a filename symbol
		csym.n_மதிப்பு = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } இல்லையெனில் எனில் (p->st_info == 0x12) {
		// find the function data

		க்கு (k = 0; k < nFuncs; k++) {
		    எனில் (strcmp(name, Func[k]) == 0)
			நிறுத்து;
		}

		எனில் (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_மதிப்பு = p->st_மதிப்பு;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_மதிப்பு;
		auxfunc.fileptr = வரி_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_மதிப்பு = p->st_மதிப்பு;	// physical address
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
		csym.n_மதிப்பு = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_வரி_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } இல்லையெனில் {
		// try an put some type info

		எனில் ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} இல்லையெனில் எனில் ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} இல்லையெனில் எனில் ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} இல்லையெனில் எனில் ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} இல்லையெனில் எனில் ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} இல்லையெனில் {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_மதிப்பு = p->st_மதிப்பு;
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

    எனில் (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    திரும்பு 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

வெறுமை Sort_குறியீடு_Table(TCCState *s1)
{
    முழு i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    எழுத்து *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * அளவு(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    க்கு (i = 0; i < nb_syms; i++) {
	எனில் (p->st_info == 4) {
	    name = (எழுத்து *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    க்கு (j = 0; j < nb_syms; j++) {
		எனில் (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(எழுத்து *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    க்கு (k = 0; k < nFuncs; k++) {
			எனில் (strcmp(name2, Func[k]) == 0)
			    நிறுத்து;
		    }

		    எனில் (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    எனில் (strcmp(AssociatedFile[k], name) == 0) {
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
    க்கு (i = 0; i < nb_syms; i++) {
	எனில் (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    எனில் (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    க்கு (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


முழு Find_Coff_குறியீடு_Index(TCCState *s1, மாறிலி எழுத்து *func_name)
{
    முழு i, n = 0;
    Elf32_Sym *p;
    எழுத்து *name;

    p = (Elf32_Sym *) symtab_section->data;

    க்கு (i = 0; i < nb_syms; i++) {

	name = (எழுத்து *) symtab_section->link->data + p->st_name;

	எனில் (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} இல்லையெனில் எனில் (p->st_info == 0x12) {

	    எனில் (strcmp(func_name, name) == 0)
		திரும்பு n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} இல்லையெனில் {
	    n += 2;
	}

	p++;
    }

    திரும்பு n;			// total number of symbols
}

முழு OutputTheSection(Section * sect)
{
    மாறிலி எழுத்து *s = sect->name;

    எனில் (!strcmp(s, ".text"))
	திரும்பு 1;
    இல்லையெனில் எனில் (!strcmp(s, ".data"))
	திரும்பு 1;
    இல்லையெனில்
	திரும்பு 0;
}

short முழு GetCoffFlags(மாறிலி எழுத்து *s)
{
    எனில் (!strcmp(s, ".text"))
	திரும்பு STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    இல்லையெனில் எனில் (!strcmp(s, ".data"))
	திரும்பு STYP_DATA;
    இல்லையெனில் எனில் (!strcmp(s, ".bss"))
	திரும்பு STYP_BSS;
    இல்லையெனில் எனில் (!strcmp(s, ".stack"))
	திரும்பு STYP_BSS | STYP_ALIGN | 0x200;
    இல்லையெனில் எனில் (!strcmp(s, ".cinit"))
	திரும்பு STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    இல்லையெனில்
	திரும்பு 0;
}

Section *FindSection(TCCState * s1, மாறிலி எழுத்து *sname)
{
    Section *s;
    முழு i;

    க்கு (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	எனில் (!strcmp(sname, s->name))
	    திரும்பு s;
    }

    tcc_error("could not find section %s", sname);
    திரும்பு 0;
}

ST_FUNC முழு tcc_load_coff(TCCState * s1, முழு fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned முழு str_size;
    எழுத்து *Coff_str_table, *name;
    முழு i, k;
    கட்டமைப்பு syment csym;
    எழுத்து name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    எனில் (!f) {
	tcc_error("Unable to open .out file for input");
    }

    எனில் (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    எனில் (fread(&o_filehdr, அளவு(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    எனில் (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    எனில் (fread(&str_size, அளவு(முழு), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (எழுத்து *) tcc_malloc(str_size);

    எனில் (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    எனில் (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    க்கு (i = 0; i < file_hdr.f_nsyms; i++) {
	எனில் (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	எனில் (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} இல்லையெனில் {
	    name = csym._n._n_name;

	    எனில் (name[7] != 0) {
		க்கு (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	எனில் (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    எனில் (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_குறியீடு(s1, name, (வெறுமை*)(uintptr_t)csym.n_மதிப்பு);
	}
	// skip any aux records

	எனில் (csym.n_numaux == 1) {
	    எனில் (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    திரும்பு 0;
}
