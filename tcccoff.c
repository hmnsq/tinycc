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

#include "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

số_nguyên nFuncs;
char Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
char AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
số_nguyên LineNoFilePtr[MAX_FUNCS];
số_nguyên EndAddress[MAX_FUNCS];
số_nguyên LastLineNo[MAX_FUNCS];
số_nguyên FuncEntries[MAX_FUNCS];

số_nguyên OutputTheSection(Section * sect);
short số_nguyên GetCoffFlags(const char *s);
void SortSymbolTable(TCCState *s1);
Section *FindSection(TCCState * s1, const char *sname);

số_nguyên C67_main_entry_point;

số_nguyên FindCoffSymbolIndex(TCCState * s1, const char *func_name);
số_nguyên nb_syms;

typedef struct {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short số_nguyên dummy;
} AUXFUNC;

typedef struct {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    số_nguyên localframe;
    số_nguyên nextentry;
    short số_nguyên dummy;
} AUXBF;

typedef struct {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    số_nguyên dummy2;
    số_nguyên dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC số_nguyên tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    số_nguyên file_pointer;
    char *Coff_str_table, *pCoff_str_table;
    số_nguyên CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    số_nguyên i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = NULL;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / sizeof(Elf32_Sym);
    coff_nb_syms = FindCoffSymbolIndex(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = sizeof(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + sizeof(AOUTHDR);

    CoffTextSectionNo = -1;

    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    nếu (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += sizeof(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    nếu (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * sizeof(struct reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	nếu (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    char func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    const char *incl_files[INCLUDE_STACK_SIZE];
	    số_nguyên incl_index, len, last_line_num;
	    const char *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_line_num = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    trong_khi (sym < sym_end) {
		switch (sym->n_type) {
		    /* function start or end */
		case N_FUN:
		    nếu (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_value + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     LineNoFilePtr[nFuncs]) / LINESZ - 1;
			LastLineNo[nFuncs++] = last_line_num + 1;
		    } không_thì {
			// beginning of function

			LineNoFilePtr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (const char *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			nếu (!p) {
			    pstrcpy(func_name, sizeof(func_name), str);
			    pstrcpy(Func[nFuncs], sizeof(func_name), str);
			} không_thì {
			    len = p - str;
			    nếu (len > sizeof(func_name) - 1)
				len = sizeof(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], sizeof(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_value;
		    }
		    break;

		    /* line number info */
		case N_SLINE:
		    pc = sym->n_value + func_addr;

		    last_pc = pc;
		    last_line_num = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    break;
		    /* include files */
		case N_BINCL:
		    str =
			(const char *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    nếu (incl_index < INCLUDE_STACK_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    break;
		case N_EINCL:
		    nếu (incl_index > 1)
			incl_index--;
		    break;
		case N_SO:
		    nếu (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } không_thì {
			str =
			    (const char *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			nếu (len > 0 && str[len - 1] != '/')
			    goto add_incl;
		    }
		    break;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    nếu (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    không_thì
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, sizeof(o_filehdr), 1, f);

    // write section headers
    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, sizeof(SCNHDR), 1, f);
	}
    }

    // write raw data
    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    nếu (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * sizeof(struct reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    nếu (s1->do_debug)
	SortSymbolTable(s1);

    // write line no data

    cho (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	nếu (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    char func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    const char *incl_files[INCLUDE_STACK_SIZE];
	    số_nguyên incl_index, len, last_line_num;
	    const char *str, *p;

	    LINENO CoffLineNo;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_line_num = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    trong_khi (sym < sym_end) {
		switch (sym->n_type) {
		    /* function start or end */
		case N_FUN:
		    nếu (sym->n_strx == 0) {
			// end of function

			CoffLineNo.l_addr.l_paddr = last_pc;
			CoffLineNo.l_lnno = last_line_num + 1;
			fwrite(&CoffLineNo, 6, 1, f);

			pc = sym->n_value + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } không_thì {
			// beginning of function

			str =
			    (const char *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			nếu (!p) {
			    pstrcpy(func_name, sizeof(func_name), str);
			} không_thì {
			    len = p - str;
			    nếu (len > sizeof(func_name) - 1)
				len = sizeof(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_value;
			last_pc = func_addr;
			last_line_num = -1;

			// output a function begin

			CoffLineNo.l_addr.l_symndx =
			    FindCoffSymbolIndex(s1, func_name);
			CoffLineNo.l_lnno = 0;

			fwrite(&CoffLineNo, 6, 1, f);
		    }
		    break;

		    /* line number info */
		case N_SLINE:
		    pc = sym->n_value + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    CoffLineNo.l_addr.l_paddr = last_pc;

		    nếu (last_line_num == -1) {
			CoffLineNo.l_lnno = sym->n_desc;
		    } không_thì {
			CoffLineNo.l_lnno = last_line_num + 1;
		    }

		    fwrite(&CoffLineNo, 6, 1, f);

		    last_pc = pc;
		    last_line_num = sym->n_desc;

		    break;

		    /* include files */
		case N_BINCL:
		    str =
			(const char *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    nếu (incl_index < INCLUDE_STACK_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    break;
		case N_EINCL:
		    nếu (incl_index > 1)
			incl_index--;
		    break;
		case N_SO:
		    nếu (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } không_thì {
			str =
			    (const char *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			nếu (len > 0 && str[len - 1] != '/')
			    goto add_incl2;
		    }
		    break;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    nếu (s1->do_debug) {
	số_nguyên k;
	struct syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	số_nguyên i;
	Elf32_Sym *p;
	const char *name;
	số_nguyên nstr;
	số_nguyên n = 0;

	Coff_str_table = (char *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	cho (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    cho (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    nếu (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } không_thì {
		nếu (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    nếu (p->st_info == 4) {
		// put a filename symbol
		csym.n_value = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } không_thì nếu (p->st_info == 0x12) {
		// find the function data

		cho (k = 0; k < nFuncs; k++) {
		    nếu (strcmp(name, Func[k]) == 0)
			break;
		}

		nếu (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_value = p->st_value;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_value;
		auxfunc.fileptr = LineNoFilePtr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_value = p->st_value;	// physical address
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
		csym.n_value = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = LastLineNo[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } không_thì {
		// try an put some type info

		nếu ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} không_thì nếu ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} không_thì nếu ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} không_thì nếu ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} không_thì nếu ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} không_thì {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_value = p->st_value;
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

    nếu (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    trả_về 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

void SortSymbolTable(TCCState *s1)
{
    số_nguyên i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    char *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * sizeof(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    cho (i = 0; i < nb_syms; i++) {
	nếu (p->st_info == 4) {
	    name = (char *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    cho (j = 0; j < nb_syms; j++) {
		nếu (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(char *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    cho (k = 0; k < nFuncs; k++) {
			nếu (strcmp(name2, Func[k]) == 0)
			    break;
		    }

		    nếu (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    nếu (strcmp(AssociatedFile[k], name) == 0) {
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
    cho (i = 0; i < nb_syms; i++) {
	nếu (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    nếu (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    cho (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


số_nguyên FindCoffSymbolIndex(TCCState *s1, const char *func_name)
{
    số_nguyên i, n = 0;
    Elf32_Sym *p;
    char *name;

    p = (Elf32_Sym *) symtab_section->data;

    cho (i = 0; i < nb_syms; i++) {

	name = (char *) symtab_section->link->data + p->st_name;

	nếu (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} không_thì nếu (p->st_info == 0x12) {

	    nếu (strcmp(func_name, name) == 0)
		trả_về n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} không_thì {
	    n += 2;
	}

	p++;
    }

    trả_về n;			// total number of symbols
}

số_nguyên OutputTheSection(Section * sect)
{
    const char *s = sect->name;

    nếu (!strcmp(s, ".text"))
	trả_về 1;
    không_thì nếu (!strcmp(s, ".data"))
	trả_về 1;
    không_thì
	trả_về 0;
}

short số_nguyên GetCoffFlags(const char *s)
{
    nếu (!strcmp(s, ".text"))
	trả_về STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    không_thì nếu (!strcmp(s, ".data"))
	trả_về STYP_DATA;
    không_thì nếu (!strcmp(s, ".bss"))
	trả_về STYP_BSS;
    không_thì nếu (!strcmp(s, ".stack"))
	trả_về STYP_BSS | STYP_ALIGN | 0x200;
    không_thì nếu (!strcmp(s, ".cinit"))
	trả_về STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    không_thì
	trả_về 0;
}

Section *FindSection(TCCState * s1, const char *sname)
{
    Section *s;
    số_nguyên i;

    cho (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	nếu (!strcmp(sname, s->name))
	    trả_về s;
    }

    tcc_error("could not find section %s", sname);
    trả_về 0;
}

ST_FUNC số_nguyên tcc_load_coff(TCCState * s1, số_nguyên fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned số_nguyên str_size;
    char *Coff_str_table, *name;
    số_nguyên i, k;
    struct syment csym;
    char name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    nếu (!f) {
	tcc_error("Unable to open .out file for input");
    }

    nếu (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    nếu (fread(&o_filehdr, sizeof(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    nếu (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    nếu (fread(&str_size, sizeof(số_nguyên), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (char *) tcc_malloc(str_size);

    nếu (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    nếu (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    cho (i = 0; i < file_hdr.f_nsyms; i++) {
	nếu (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	nếu (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} không_thì {
	    name = csym._n._n_name;

	    nếu (name[7] != 0) {
		cho (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	nếu (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    nếu (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_symbol(s1, name, (void*)(uintptr_t)csym.n_value);
	}
	// skip any aux records

	nếu (csym.n_numaux == 1) {
	    nếu (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    trả_về 0;
}
