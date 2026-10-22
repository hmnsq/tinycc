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

puur_naa_nka nFuncs;
var_na Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
var_na AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
puur_naa_nka LineNoFilePtr[MAX_FUNCS];
puur_naa_nka EndAddress[MAX_FUNCS];
puur_naa_nka LastLineNo[MAX_FUNCS];
puur_naa_nka FuncEntries[MAX_FUNCS];

puur_naa_nka OutputTheSection(Section * sect);
short puur_naa_nka GetCoffFlags(const var_na *s);
void SortSymbolTable(TCCState *s1);
Section *FindSection(TCCState * s1, const var_na *sname);

puur_naa_nka C67_main_entry_point;

puur_naa_nka FindCoffSymbolIndex(TCCState * s1, const var_na *func_name);
puur_naa_nka nb_syms;

typedef sa_nracanaa {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short puur_naa_nka dummy;
} AUXFUNC;

typedef sa_nracanaa {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    puur_naa_nka localframe;
    puur_naa_nka nextentry;
    short puur_naa_nka dummy;
} AUXBF;

typedef sa_nracanaa {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    puur_naa_nka dummy2;
    puur_naa_nka dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC puur_naa_nka tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    puur_naa_nka file_pointer;
    var_na *Coff_str_table, *pCoff_str_table;
    puur_naa_nka CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    puur_naa_nka i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = NULL;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / parimaa_na(Elf32_Sym);
    coff_nb_syms = FindCoffSymbolIndex(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = parimaa_na(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + parimaa_na(AOUTHDR);

    CoffTextSectionNo = -1;

    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    ᯀᯮᯝ (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += parimaa_na(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ᯀᯮᯝ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * parimaa_na(sa_nracanaa reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	ᯀᯮᯝ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    var_na func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    const var_na *incl_files[INCLUDE_STACK_SIZE];
	    puur_naa_nka incl_index, len, last_line_num;
	    const var_na *str, *p;

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
	    ᯀᯬᯝ (sym < sym_end) {
		switch (sym->n_type) {
		    /* function start or end */
		pak_sa N_FUN:
		    ᯀᯮᯝ (sym->n_strx == 0) {
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
		    } ᯀᯮᯝᯂᯪ {
			// beginning of function

			LineNoFilePtr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (const var_na *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			ᯀᯮᯝ (!p) {
			    pstrcpy(func_name, parimaa_na(func_name), str);
			    pstrcpy(Func[nFuncs], parimaa_na(func_name), str);
			} ᯀᯮᯝᯂᯪ {
			    len = p - str;
			    ᯀᯮᯝ (len > parimaa_na(func_name) - 1)
				len = parimaa_na(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], parimaa_na(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_value;
		    }
		    bha_nga;

		    /* line number info */
		pak_sa N_SLINE:
		    pc = sym->n_value + func_addr;

		    last_pc = pc;
		    last_line_num = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    bha_nga;
		    /* include files */
		pak_sa N_BINCL:
		    str =
			(const var_na *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    ᯀᯮᯝ (incl_index < INCLUDE_STACK_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    bha_nga;
		pak_sa N_EINCL:
		    ᯀᯮᯝ (incl_index > 1)
			incl_index--;
		    bha_nga;
		pak_sa N_SO:
		    ᯀᯮᯝ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } ᯀᯮᯝᯂᯪ {
			str =
			    (const var_na *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			ᯀᯮᯝ (len > 0 && str[len - 1] != '/')
			    goto add_incl;
		    }
		    bha_nga;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    ᯀᯮᯝ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    ᯀᯮᯝᯂᯪ
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, parimaa_na(o_filehdr), 1, f);

    // write section headers
    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, parimaa_na(SCNHDR), 1, f);
	}
    }

    // write raw data
    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ᯀᯮᯝ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * parimaa_na(sa_nracanaa reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    ᯀᯮᯝ (s1->do_debug)
	SortSymbolTable(s1);

    // write line no data

    for (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ᯀᯮᯝ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    var_na func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    const var_na *incl_files[INCLUDE_STACK_SIZE];
	    puur_naa_nka incl_index, len, last_line_num;
	    const var_na *str, *p;

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

	    ᯀᯬᯝ (sym < sym_end) {
		switch (sym->n_type) {
		    /* function start or end */
		pak_sa N_FUN:
		    ᯀᯮᯝ (sym->n_strx == 0) {
			// end of function

			CoffLineNo.l_addr.l_paddr = last_pc;
			CoffLineNo.l_lnno = last_line_num + 1;
			fwrite(&CoffLineNo, 6, 1, f);

			pc = sym->n_value + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } ᯀᯮᯝᯂᯪ {
			// beginning of function

			str =
			    (const var_na *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			ᯀᯮᯝ (!p) {
			    pstrcpy(func_name, parimaa_na(func_name), str);
			} ᯀᯮᯝᯂᯪ {
			    len = p - str;
			    ᯀᯮᯝ (len > parimaa_na(func_name) - 1)
				len = parimaa_na(func_name) - 1;
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
		    bha_nga;

		    /* line number info */
		pak_sa N_SLINE:
		    pc = sym->n_value + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    CoffLineNo.l_addr.l_paddr = last_pc;

		    ᯀᯮᯝ (last_line_num == -1) {
			CoffLineNo.l_lnno = sym->n_desc;
		    } ᯀᯮᯝᯂᯪ {
			CoffLineNo.l_lnno = last_line_num + 1;
		    }

		    fwrite(&CoffLineNo, 6, 1, f);

		    last_pc = pc;
		    last_line_num = sym->n_desc;

		    bha_nga;

		    /* include files */
		pak_sa N_BINCL:
		    str =
			(const var_na *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    ᯀᯮᯝ (incl_index < INCLUDE_STACK_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    bha_nga;
		pak_sa N_EINCL:
		    ᯀᯮᯝ (incl_index > 1)
			incl_index--;
		    bha_nga;
		pak_sa N_SO:
		    ᯀᯮᯝ (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } ᯀᯮᯝᯂᯪ {
			str =
			    (const var_na *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			ᯀᯮᯝ (len > 0 && str[len - 1] != '/')
			    goto add_incl2;
		    }
		    bha_nga;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    ᯀᯮᯝ (s1->do_debug) {
	puur_naa_nka k;
	sa_nracanaa syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	puur_naa_nka i;
	Elf32_Sym *p;
	const var_na *name;
	puur_naa_nka nstr;
	puur_naa_nka n = 0;

	Coff_str_table = (var_na *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	for (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    for (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    ᯀᯮᯝ (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } ᯀᯮᯝᯂᯪ {
		ᯀᯮᯝ (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    ᯀᯮᯝ (p->st_info == 4) {
		// put a filename symbol
		csym.n_value = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } ᯀᯮᯝᯂᯪ ᯀᯮᯝ (p->st_info == 0x12) {
		// find the function data

		for (k = 0; k < nFuncs; k++) {
		    ᯀᯮᯝ (strcmp(name, Func[k]) == 0)
			bha_nga;
		}

		ᯀᯮᯝ (k >= nFuncs) {
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

	    } ᯀᯮᯝᯂᯪ {
		// try an put some type info

		ᯀᯮᯝ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} ᯀᯮᯝᯂᯪ ᯀᯮᯝ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} ᯀᯮᯝᯂᯪ ᯀᯮᯝ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} ᯀᯮᯝᯂᯪ ᯀᯮᯝ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} ᯀᯮᯝᯂᯪ ᯀᯮᯝ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} ᯀᯮᯝᯂᯪ {
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

    ᯀᯮᯝ (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    ᯀᯮᯞ 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

void SortSymbolTable(TCCState *s1)
{
    puur_naa_nka i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    var_na *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * parimaa_na(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    for (i = 0; i < nb_syms; i++) {
	ᯀᯮᯝ (p->st_info == 4) {
	    name = (var_na *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    for (j = 0; j < nb_syms; j++) {
		ᯀᯮᯝ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(var_na *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    for (k = 0; k < nFuncs; k++) {
			ᯀᯮᯝ (strcmp(name2, Func[k]) == 0)
			    bha_nga;
		    }

		    ᯀᯮᯝ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    ᯀᯮᯝ (strcmp(AssociatedFile[k], name) == 0) {
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
    for (i = 0; i < nb_syms; i++) {
	ᯀᯮᯝ (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    ᯀᯮᯝ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    for (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


puur_naa_nka FindCoffSymbolIndex(TCCState *s1, const var_na *func_name)
{
    puur_naa_nka i, n = 0;
    Elf32_Sym *p;
    var_na *name;

    p = (Elf32_Sym *) symtab_section->data;

    for (i = 0; i < nb_syms; i++) {

	name = (var_na *) symtab_section->link->data + p->st_name;

	ᯀᯮᯝ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} ᯀᯮᯝᯂᯪ ᯀᯮᯝ (p->st_info == 0x12) {

	    ᯀᯮᯝ (strcmp(func_name, name) == 0)
		ᯀᯮᯞ n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} ᯀᯮᯝᯂᯪ {
	    n += 2;
	}

	p++;
    }

    ᯀᯮᯞ n;			// total number of symbols
}

puur_naa_nka OutputTheSection(Section * sect)
{
    const var_na *s = sect->name;

    ᯀᯮᯝ (!strcmp(s, ".text"))
	ᯀᯮᯞ 1;
    ᯀᯮᯝᯂᯪ ᯀᯮᯝ (!strcmp(s, ".data"))
	ᯀᯮᯞ 1;
    ᯀᯮᯝᯂᯪ
	ᯀᯮᯞ 0;
}

short puur_naa_nka GetCoffFlags(const var_na *s)
{
    ᯀᯮᯝ (!strcmp(s, ".text"))
	ᯀᯮᯞ STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    ᯀᯮᯝᯂᯪ ᯀᯮᯝ (!strcmp(s, ".data"))
	ᯀᯮᯞ STYP_DATA;
    ᯀᯮᯝᯂᯪ ᯀᯮᯝ (!strcmp(s, ".bss"))
	ᯀᯮᯞ STYP_BSS;
    ᯀᯮᯝᯂᯪ ᯀᯮᯝ (!strcmp(s, ".stack"))
	ᯀᯮᯞ STYP_BSS | STYP_ALIGN | 0x200;
    ᯀᯮᯝᯂᯪ ᯀᯮᯝ (!strcmp(s, ".cinit"))
	ᯀᯮᯞ STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    ᯀᯮᯝᯂᯪ
	ᯀᯮᯞ 0;
}

Section *FindSection(TCCState * s1, const var_na *sname)
{
    Section *s;
    puur_naa_nka i;

    for (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	ᯀᯮᯝ (!strcmp(sname, s->name))
	    ᯀᯮᯞ s;
    }

    tcc_error("could not find section %s", sname);
    ᯀᯮᯞ 0;
}

ST_FUNC puur_naa_nka tcc_load_coff(TCCState * s1, puur_naa_nka fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned puur_naa_nka str_size;
    var_na *Coff_str_table, *name;
    puur_naa_nka i, k;
    sa_nracanaa syment csym;
    var_na name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    ᯀᯮᯝ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    ᯀᯮᯝ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    ᯀᯮᯝ (fread(&o_filehdr, parimaa_na(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    ᯀᯮᯝ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    ᯀᯮᯝ (fread(&str_size, parimaa_na(puur_naa_nka), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (var_na *) tcc_malloc(str_size);

    ᯀᯮᯝ (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    ᯀᯮᯝ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    for (i = 0; i < file_hdr.f_nsyms; i++) {
	ᯀᯮᯝ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	ᯀᯮᯝ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} ᯀᯮᯝᯂᯪ {
	    name = csym._n._n_name;

	    ᯀᯮᯝ (name[7] != 0) {
		for (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	ᯀᯮᯝ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    ᯀᯮᯝ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_symbol(s1, name, (void*)(uintptr_t)csym.n_value);
	}
	// skip any aux records

	ᯀᯮᯝ (csym.n_numaux == 1) {
	    ᯀᯮᯝ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    ᯀᯮᯞ 0;
}
