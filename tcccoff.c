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

पूर्णाङ्क nFuncs;
वर्ण Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
वर्ण AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
पूर्णाङ्क पङ्क्तिः_No_File_Ptr[MAX_FUNCS];
पूर्णाङ्क EndAddress[MAX_FUNCS];
पूर्णाङ्क Last_पङ्क्तिः_No[MAX_FUNCS];
पूर्णाङ्क FuncEntries[MAX_FUNCS];

पूर्णाङ्क OutputTheSection(Section * sect);
short पूर्णाङ्क GetCoffFlags(ध्रुव वर्ण *s);
शून्य Sort_चिह्नम्_Table(TCCState *s1);
Section *FindSection(TCCState * s1, ध्रुव वर्ण *sname);

पूर्णाङ्क C67_main_entry_point;

पूर्णाङ्क Find_Coff_चिह्नम्_Index(TCCState * s1, ध्रुव वर्ण *func_name);
पूर्णाङ्क nb_syms;

प्रकारनिर्देश संरचना {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short पूर्णाङ्क dummy;
} AUXFUNC;

प्रकारनिर्देश संरचना {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    पूर्णाङ्क localframe;
    पूर्णाङ्क nextentry;
    short पूर्णाङ्क dummy;
} AUXBF;

प्रकारनिर्देश संरचना {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    पूर्णाङ्क dummy2;
    पूर्णाङ्क dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC पूर्णाङ्क tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    पूर्णाङ्क file_pointer;
    वर्ण *Coff_str_table, *pCoff_str_table;
    पूर्णाङ्क CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    पूर्णाङ्क i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = रिक्त;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / परिमाण(Elf32_Sym);
    coff_nb_syms = Find_Coff_चिह्नम्_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = परिमाण(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + परिमाण(AOUTHDR);

    CoffTextSectionNo = -1;

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    जइ (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += परिमाण(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    जइ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * परिमाण(संरचना reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	जइ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    वर्ण func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    ध्रुव वर्ण *incl_files[INCLUDE_राशिः_SIZE];
	    पूर्णाङ्क incl_index, len, last_पङ्क्तिः_अङ्कः;
	    ध्रुव वर्ण *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_पङ्क्तिः_अङ्कः = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    जाव (sym < sym_end) {
		विकल्प (sym->n_type) {
		    /* function start or end */
		पक्ष N_FUN:
		    जइ (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_मानम् + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     पङ्क्तिः_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_पङ्क्तिः_No[nFuncs++] = last_पङ्क्तिः_अङ्कः + 1;
		    } अण्णहा {
			// beginning of function

			पङ्क्तिः_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (ध्रुव वर्ण *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			जइ (!p) {
			    pstrcpy(func_name, परिमाण(func_name), str);
			    pstrcpy(Func[nFuncs], परिमाण(func_name), str);
			} अण्णहा {
			    len = p - str;
			    जइ (len > परिमाण(func_name) - 1)
				len = परिमाण(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], परिमाण(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_मानम्;
		    }
		    भङ्ग;

		    /* line number info */
		पक्ष N_SLINE:
		    pc = sym->n_मानम् + func_addr;

		    last_pc = pc;
		    last_पङ्क्तिः_अङ्कः = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    भङ्ग;
		    /* include files */
		पक्ष N_BINCL:
		    str =
			(ध्रुव वर्ण *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    जइ (incl_index < INCLUDE_राशिः_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    भङ्ग;
		पक्ष N_EINCL:
		    जइ (incl_index > 1)
			incl_index--;
		    भङ्ग;
		पक्ष N_SO:
		    जइ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } अण्णहा {
			str =
			    (ध्रुव वर्ण *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			जइ (len > 0 && str[len - 1] != '/')
			    गच्छ add_incl;
		    }
		    भङ्ग;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    जइ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    अण्णहा
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, परिमाण(o_filehdr), 1, f);

    // write section headers
    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, परिमाण(SCNHDR), 1, f);
	}
    }

    // write raw data
    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    जइ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * परिमाण(संरचना reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    जइ (s1->do_debug)
	Sort_चिह्नम्_Table(s1);

    // write line no data

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	जइ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    वर्ण func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    ध्रुव वर्ण *incl_files[INCLUDE_राशिः_SIZE];
	    पूर्णाङ्क incl_index, len, last_पङ्क्तिः_अङ्कः;
	    ध्रुव वर्ण *str, *p;

	    LINENO Coff_पङ्क्तिः_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_पङ्क्तिः_अङ्कः = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    जाव (sym < sym_end) {
		विकल्प (sym->n_type) {
		    /* function start or end */
		पक्ष N_FUN:
		    जइ (sym->n_strx == 0) {
			// end of function

			Coff_पङ्क्तिः_No.l_addr.l_paddr = last_pc;
			Coff_पङ्क्तिः_No.l_lnno = last_पङ्क्तिः_अङ्कः + 1;
			fwrite(&Coff_पङ्क्तिः_No, 6, 1, f);

			pc = sym->n_मानम् + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } अण्णहा {
			// beginning of function

			str =
			    (ध्रुव वर्ण *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			जइ (!p) {
			    pstrcpy(func_name, परिमाण(func_name), str);
			} अण्णहा {
			    len = p - str;
			    जइ (len > परिमाण(func_name) - 1)
				len = परिमाण(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_मानम्;
			last_pc = func_addr;
			last_पङ्क्तिः_अङ्कः = -1;

			// output a function begin

			Coff_पङ्क्तिः_No.l_addr.l_symndx =
			    Find_Coff_चिह्नम्_Index(s1, func_name);
			Coff_पङ्क्तिः_No.l_lnno = 0;

			fwrite(&Coff_पङ्क्तिः_No, 6, 1, f);
		    }
		    भङ्ग;

		    /* line number info */
		पक्ष N_SLINE:
		    pc = sym->n_मानम् + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_पङ्क्तिः_No.l_addr.l_paddr = last_pc;

		    जइ (last_पङ्क्तिः_अङ्कः == -1) {
			Coff_पङ्क्तिः_No.l_lnno = sym->n_desc;
		    } अण्णहा {
			Coff_पङ्क्तिः_No.l_lnno = last_पङ्क्तिः_अङ्कः + 1;
		    }

		    fwrite(&Coff_पङ्क्तिः_No, 6, 1, f);

		    last_pc = pc;
		    last_पङ्क्तिः_अङ्कः = sym->n_desc;

		    भङ्ग;

		    /* include files */
		पक्ष N_BINCL:
		    str =
			(ध्रुव वर्ण *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    जइ (incl_index < INCLUDE_राशिः_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    भङ्ग;
		पक्ष N_EINCL:
		    जइ (incl_index > 1)
			incl_index--;
		    भङ्ग;
		पक्ष N_SO:
		    जइ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } अण्णहा {
			str =
			    (ध्रुव वर्ण *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			जइ (len > 0 && str[len - 1] != '/')
			    गच्छ add_incl2;
		    }
		    भङ्ग;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    जइ (s1->do_debug) {
	पूर्णाङ्क k;
	संरचना syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	पूर्णाङ्क i;
	Elf32_Sym *p;
	ध्रुव वर्ण *name;
	पूर्णाङ्क nstr;
	पूर्णाङ्क n = 0;

	Coff_str_table = (वर्ण *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	प्रति (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    प्रति (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    जइ (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } अण्णहा {
		जइ (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    जइ (p->st_info == 4) {
		// put a filename symbol
		csym.n_मानम् = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } अण्णहा जइ (p->st_info == 0x12) {
		// find the function data

		प्रति (k = 0; k < nFuncs; k++) {
		    जइ (strcmp(name, Func[k]) == 0)
			भङ्ग;
		}

		जइ (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_मानम् = p->st_मानम्;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_मानम्;
		auxfunc.fileptr = पङ्क्तिः_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_मानम् = p->st_मानम्;	// physical address
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
		csym.n_मानम् = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_पङ्क्तिः_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } अण्णहा {
		// try an put some type info

		जइ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} अण्णहा जइ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} अण्णहा जइ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} अण्णहा जइ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} अण्णहा जइ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} अण्णहा {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_मानम् = p->st_मानम्;
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

    जइ (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    प्रत्यागम 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

शून्य Sort_चिह्नम्_Table(TCCState *s1)
{
    पूर्णाङ्क i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    वर्ण *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * परिमाण(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    प्रति (i = 0; i < nb_syms; i++) {
	जइ (p->st_info == 4) {
	    name = (वर्ण *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    प्रति (j = 0; j < nb_syms; j++) {
		जइ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(वर्ण *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    प्रति (k = 0; k < nFuncs; k++) {
			जइ (strcmp(name2, Func[k]) == 0)
			    भङ्ग;
		    }

		    जइ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    जइ (strcmp(AssociatedFile[k], name) == 0) {
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
    प्रति (i = 0; i < nb_syms; i++) {
	जइ (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    जइ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    प्रति (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


पूर्णाङ्क Find_Coff_चिह्नम्_Index(TCCState *s1, ध्रुव वर्ण *func_name)
{
    पूर्णाङ्क i, n = 0;
    Elf32_Sym *p;
    वर्ण *name;

    p = (Elf32_Sym *) symtab_section->data;

    प्रति (i = 0; i < nb_syms; i++) {

	name = (वर्ण *) symtab_section->link->data + p->st_name;

	जइ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} अण्णहा जइ (p->st_info == 0x12) {

	    जइ (strcmp(func_name, name) == 0)
		प्रत्यागम n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} अण्णहा {
	    n += 2;
	}

	p++;
    }

    प्रत्यागम n;			// total number of symbols
}

पूर्णाङ्क OutputTheSection(Section * sect)
{
    ध्रुव वर्ण *s = sect->name;

    जइ (!strcmp(s, ".text"))
	प्रत्यागम 1;
    अण्णहा जइ (!strcmp(s, ".data"))
	प्रत्यागम 1;
    अण्णहा
	प्रत्यागम 0;
}

short पूर्णाङ्क GetCoffFlags(ध्रुव वर्ण *s)
{
    जइ (!strcmp(s, ".text"))
	प्रत्यागम STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    अण्णहा जइ (!strcmp(s, ".data"))
	प्रत्यागम STYP_DATA;
    अण्णहा जइ (!strcmp(s, ".bss"))
	प्रत्यागम STYP_BSS;
    अण्णहा जइ (!strcmp(s, ".stack"))
	प्रत्यागम STYP_BSS | STYP_ALIGN | 0x200;
    अण्णहा जइ (!strcmp(s, ".cinit"))
	प्रत्यागम STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    अण्णहा
	प्रत्यागम 0;
}

Section *FindSection(TCCState * s1, ध्रुव वर्ण *sname)
{
    Section *s;
    पूर्णाङ्क i;

    प्रति (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	जइ (!strcmp(sname, s->name))
	    प्रत्यागम s;
    }

    tcc_error("could not find section %s", sname);
    प्रत्यागम 0;
}

ST_FUNC पूर्णाङ्क tcc_load_coff(TCCState * s1, पूर्णाङ्क fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned पूर्णाङ्क str_size;
    वर्ण *Coff_str_table, *name;
    पूर्णाङ्क i, k;
    संरचना syment csym;
    वर्ण name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    जइ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    जइ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    जइ (fread(&o_filehdr, परिमाण(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    जइ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    जइ (fread(&str_size, परिमाण(पूर्णाङ्क), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (वर्ण *) tcc_malloc(str_size);

    जइ (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    जइ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    प्रति (i = 0; i < file_hdr.f_nsyms; i++) {
	जइ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	जइ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} अण्णहा {
	    name = csym._n._n_name;

	    जइ (name[7] != 0) {
		प्रति (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	जइ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    जइ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_चिह्नम्(s1, name, (शून्य*)(uintptr_t)csym.n_मानम्);
	}
	// skip any aux records

	जइ (csym.n_numaux == 1) {
	    जइ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    प्रत्यागम 0;
}
