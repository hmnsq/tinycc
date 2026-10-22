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

#ଅନ୍ତର୍ଭାଵ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

ପୂର୍ଣ୍ଣସଂଖ୍ୟା nFuncs;
ଅକ୍ଷର Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
ଅକ୍ଷର AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_No_File_Ptr[MAX_FUNCS];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା EndAddress[MAX_FUNCS];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା Last_ଧାଡ଼ି_No[MAX_FUNCS];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା FuncEntries[MAX_FUNCS];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା OutputTheSection(Section * sect);
short ପୂର୍ଣ୍ଣସଂଖ୍ୟା GetCoffFlags(ଅଚଳ ଅକ୍ଷର *s);
ଶୂନ୍ୟ Sort_ପ୍ରତୀକ_Table(TCCState *s1);
Section *FindSection(TCCState * s1, ଅଚଳ ଅକ୍ଷର *sname);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା C67_main_entry_point;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା Find_Coff_ପ୍ରତୀକ_Index(TCCState * s1, ଅଚଳ ଅକ୍ଷର *func_name);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_syms;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short ପୂର୍ଣ୍ଣସଂଖ୍ୟା dummy;
} AUXFUNC;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା localframe;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nextentry;
    short ପୂର୍ଣ୍ଣସଂଖ୍ୟା dummy;
} AUXBF;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dummy2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା file_pointer;
    ଅକ୍ଷର *Coff_str_table, *pCoff_str_table;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = ଖାଲି;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / ଆକାର(Elf32_Sym);
    coff_nb_syms = Find_Coff_ପ୍ରତୀକ_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = ଆକାର(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + ଆକାର(AOUTHDR);

    CoffTextSectionNo = -1;

    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    ଯଦି (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += ଆକାର(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ଯଦି (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * ଆକାର(ସଂରଚନା reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	ଯଦି (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    ଅକ୍ଷର func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    ଅଚଳ ଅକ୍ଷର *incl_files[INCLUDE_ଗଦା_SIZE];
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା incl_index, len, last_ଧାଡ଼ି_ଅଙ୍କ;
	    ଅଚଳ ଅକ୍ଷର *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_ଧାଡ଼ି_ଅଙ୍କ = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    ଯେତେବେଳେ (sym < sym_end) {
		ବାଛ (sym->n_type) {
		    /* function start or end */
		ସ୍ଥିତି N_FUN:
		    ଯଦି (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_ମୂଲ୍ୟ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     ଧାଡ଼ି_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_ଧାଡ଼ି_No[nFuncs++] = last_ଧାଡ଼ି_ଅଙ୍କ + 1;
		    } ଅନ୍ୟଥା {
			// beginning of function

			ଧାଡ଼ି_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (ଅଚଳ ଅକ୍ଷର *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			ଯଦି (!p) {
			    pstrcpy(func_name, ଆକାର(func_name), str);
			    pstrcpy(Func[nFuncs], ଆକାର(func_name), str);
			} ଅନ୍ୟଥା {
			    len = p - str;
			    ଯଦି (len > ଆକାର(func_name) - 1)
				len = ଆକାର(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], ଆକାର(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_ମୂଲ୍ୟ;
		    }
		    ଭାଙ୍ଗ;

		    /* line number info */
		ସ୍ଥିତି N_SLINE:
		    pc = sym->n_ମୂଲ୍ୟ + func_addr;

		    last_pc = pc;
		    last_ଧାଡ଼ି_ଅଙ୍କ = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    ଭାଙ୍ଗ;
		    /* include files */
		ସ୍ଥିତି N_BINCL:
		    str =
			(ଅଚଳ ଅକ୍ଷର *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    ଯଦି (incl_index < INCLUDE_ଗଦା_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    ଭାଙ୍ଗ;
		ସ୍ଥିତି N_EINCL:
		    ଯଦି (incl_index > 1)
			incl_index--;
		    ଭାଙ୍ଗ;
		ସ୍ଥିତି N_SO:
		    ଯଦି (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } ଅନ୍ୟଥା {
			str =
			    (ଅଚଳ ଅକ୍ଷର *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			ଯଦି (len > 0 && str[len - 1] != '/')
			    ଯାଅ add_incl;
		    }
		    ଭାଙ୍ଗ;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    ଯଦି (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    ଅନ୍ୟଥା
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, ଆକାର(o_filehdr), 1, f);

    // write section headers
    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, ଆକାର(SCNHDR), 1, f);
	}
    }

    // write raw data
    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ଯଦି (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * ଆକାର(ସଂରଚନା reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    ଯଦି (s1->do_debug)
	Sort_ପ୍ରତୀକ_Table(s1);

    // write line no data

    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	ଯଦି (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    ଅକ୍ଷର func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    ଅଚଳ ଅକ୍ଷର *incl_files[INCLUDE_ଗଦା_SIZE];
	    ପୂର୍ଣ୍ଣସଂଖ୍ୟା incl_index, len, last_ଧାଡ଼ି_ଅଙ୍କ;
	    ଅଚଳ ଅକ୍ଷର *str, *p;

	    LINENO Coff_ଧାଡ଼ି_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_ଧାଡ଼ି_ଅଙ୍କ = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    ଯେତେବେଳେ (sym < sym_end) {
		ବାଛ (sym->n_type) {
		    /* function start or end */
		ସ୍ଥିତି N_FUN:
		    ଯଦି (sym->n_strx == 0) {
			// end of function

			Coff_ଧାଡ଼ି_No.l_addr.l_paddr = last_pc;
			Coff_ଧାଡ଼ି_No.l_lnno = last_ଧାଡ଼ି_ଅଙ୍କ + 1;
			fwrite(&Coff_ଧାଡ଼ି_No, 6, 1, f);

			pc = sym->n_ମୂଲ୍ୟ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } ଅନ୍ୟଥା {
			// beginning of function

			str =
			    (ଅଚଳ ଅକ୍ଷର *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			ଯଦି (!p) {
			    pstrcpy(func_name, ଆକାର(func_name), str);
			} ଅନ୍ୟଥା {
			    len = p - str;
			    ଯଦି (len > ଆକାର(func_name) - 1)
				len = ଆକାର(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_ମୂଲ୍ୟ;
			last_pc = func_addr;
			last_ଧାଡ଼ି_ଅଙ୍କ = -1;

			// output a function begin

			Coff_ଧାଡ଼ି_No.l_addr.l_symndx =
			    Find_Coff_ପ୍ରତୀକ_Index(s1, func_name);
			Coff_ଧାଡ଼ି_No.l_lnno = 0;

			fwrite(&Coff_ଧାଡ଼ି_No, 6, 1, f);
		    }
		    ଭାଙ୍ଗ;

		    /* line number info */
		ସ୍ଥିତି N_SLINE:
		    pc = sym->n_ମୂଲ୍ୟ + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_ଧାଡ଼ି_No.l_addr.l_paddr = last_pc;

		    ଯଦି (last_ଧାଡ଼ି_ଅଙ୍କ == -1) {
			Coff_ଧାଡ଼ି_No.l_lnno = sym->n_desc;
		    } ଅନ୍ୟଥା {
			Coff_ଧାଡ଼ି_No.l_lnno = last_ଧାଡ଼ି_ଅଙ୍କ + 1;
		    }

		    fwrite(&Coff_ଧାଡ଼ି_No, 6, 1, f);

		    last_pc = pc;
		    last_ଧାଡ଼ି_ଅଙ୍କ = sym->n_desc;

		    ଭାଙ୍ଗ;

		    /* include files */
		ସ୍ଥିତି N_BINCL:
		    str =
			(ଅଚଳ ଅକ୍ଷର *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    ଯଦି (incl_index < INCLUDE_ଗଦା_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    ଭାଙ୍ଗ;
		ସ୍ଥିତି N_EINCL:
		    ଯଦି (incl_index > 1)
			incl_index--;
		    ଭାଙ୍ଗ;
		ସ୍ଥିତି N_SO:
		    ଯଦି (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } ଅନ୍ୟଥା {
			str =
			    (ଅଚଳ ଅକ୍ଷର *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			ଯଦି (len > 0 && str[len - 1] != '/')
			    ଯାଅ add_incl2;
		    }
		    ଭାଙ୍ଗ;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    ଯଦି (s1->do_debug) {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା k;
	ସଂରଚନା syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
	Elf32_Sym *p;
	ଅଚଳ ଅକ୍ଷର *name;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା nstr;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = 0;

	Coff_str_table = (ଅକ୍ଷର *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	ପାଇଁ (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    ପାଇଁ (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    ଯଦି (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } ଅନ୍ୟଥା {
		ଯଦି (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    ଯଦି (p->st_info == 4) {
		// put a filename symbol
		csym.n_ମୂଲ୍ୟ = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } ଅନ୍ୟଥା ଯଦି (p->st_info == 0x12) {
		// find the function data

		ପାଇଁ (k = 0; k < nFuncs; k++) {
		    ଯଦି (strcmp(name, Func[k]) == 0)
			ଭାଙ୍ଗ;
		}

		ଯଦି (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_ମୂଲ୍ୟ = p->st_ମୂଲ୍ୟ;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_ମୂଲ୍ୟ;
		auxfunc.fileptr = ଧାଡ଼ି_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_ମୂଲ୍ୟ = p->st_ମୂଲ୍ୟ;	// physical address
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
		csym.n_ମୂଲ୍ୟ = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_ଧାଡ଼ି_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } ଅନ୍ୟଥା {
		// try an put some type info

		ଯଦି ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} ଅନ୍ୟଥା ଯଦି ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} ଅନ୍ୟଥା ଯଦି ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} ଅନ୍ୟଥା ଯଦି ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} ଅନ୍ୟଥା ଯଦି ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} ଅନ୍ୟଥା {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_ମୂଲ୍ୟ = p->st_ମୂଲ୍ୟ;
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

    ଯଦି (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    ଫେରନ୍ତୁ 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

ଶୂନ୍ୟ Sort_ପ୍ରତୀକ_Table(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    ଅକ୍ଷର *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * ଆକାର(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    ପାଇଁ (i = 0; i < nb_syms; i++) {
	ଯଦି (p->st_info == 4) {
	    name = (ଅକ୍ଷର *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    ପାଇଁ (j = 0; j < nb_syms; j++) {
		ଯଦି (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(ଅକ୍ଷର *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    ପାଇଁ (k = 0; k < nFuncs; k++) {
			ଯଦି (strcmp(name2, Func[k]) == 0)
			    ଭାଙ୍ଗ;
		    }

		    ଯଦି (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    ଯଦି (strcmp(AssociatedFile[k], name) == 0) {
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
    ପାଇଁ (i = 0; i < nb_syms; i++) {
	ଯଦି (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    ଯଦି (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    ପାଇଁ (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


ପୂର୍ଣ୍ଣସଂଖ୍ୟା Find_Coff_ପ୍ରତୀକ_Index(TCCState *s1, ଅଚଳ ଅକ୍ଷର *func_name)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, n = 0;
    Elf32_Sym *p;
    ଅକ୍ଷର *name;

    p = (Elf32_Sym *) symtab_section->data;

    ପାଇଁ (i = 0; i < nb_syms; i++) {

	name = (ଅକ୍ଷର *) symtab_section->link->data + p->st_name;

	ଯଦି (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} ଅନ୍ୟଥା ଯଦି (p->st_info == 0x12) {

	    ଯଦି (strcmp(func_name, name) == 0)
		ଫେରନ୍ତୁ n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} ଅନ୍ୟଥା {
	    n += 2;
	}

	p++;
    }

    ଫେରନ୍ତୁ n;			// total number of symbols
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା OutputTheSection(Section * sect)
{
    ଅଚଳ ଅକ୍ଷର *s = sect->name;

    ଯଦି (!strcmp(s, ".text"))
	ଫେରନ୍ତୁ 1;
    ଅନ୍ୟଥା ଯଦି (!strcmp(s, ".data"))
	ଫେରନ୍ତୁ 1;
    ଅନ୍ୟଥା
	ଫେରନ୍ତୁ 0;
}

short ପୂର୍ଣ୍ଣସଂଖ୍ୟା GetCoffFlags(ଅଚଳ ଅକ୍ଷର *s)
{
    ଯଦି (!strcmp(s, ".text"))
	ଫେରନ୍ତୁ STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    ଅନ୍ୟଥା ଯଦି (!strcmp(s, ".data"))
	ଫେରନ୍ତୁ STYP_DATA;
    ଅନ୍ୟଥା ଯଦି (!strcmp(s, ".bss"))
	ଫେରନ୍ତୁ STYP_BSS;
    ଅନ୍ୟଥା ଯଦି (!strcmp(s, ".stack"))
	ଫେରନ୍ତୁ STYP_BSS | STYP_ALIGN | 0x200;
    ଅନ୍ୟଥା ଯଦି (!strcmp(s, ".cinit"))
	ଫେରନ୍ତୁ STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    ଅନ୍ୟଥା
	ଫେରନ୍ତୁ 0;
}

Section *FindSection(TCCState * s1, ଅଚଳ ଅକ୍ଷର *sname)
{
    Section *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ପାଇଁ (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	ଯଦି (!strcmp(sname, s->name))
	    ଫେରନ୍ତୁ s;
    }

    tcc_error("could not find section %s", sname);
    ଫେରନ୍ତୁ 0;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_load_coff(TCCState * s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା str_size;
    ଅକ୍ଷର *Coff_str_table, *name;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, k;
    ସଂରଚନା syment csym;
    ଅକ୍ଷର name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    ଯଦି (!f) {
	tcc_error("Unable to open .out file for input");
    }

    ଯଦି (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    ଯଦି (fread(&o_filehdr, ଆକାର(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    ଯଦି (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    ଯଦି (fread(&str_size, ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (ଅକ୍ଷର *) tcc_malloc(str_size);

    ଯଦି (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    ଯଦି (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    ପାଇଁ (i = 0; i < file_hdr.f_nsyms; i++) {
	ଯଦି (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	ଯଦି (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} ଅନ୍ୟଥା {
	    name = csym._n._n_name;

	    ଯଦି (name[7] != 0) {
		ପାଇଁ (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	ଯଦି (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    ଯଦି (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_ପ୍ରତୀକ(s1, name, (ଶୂନ୍ୟ*)(uintptr_t)csym.n_ମୂଲ୍ୟ);
	}
	// skip any aux records

	ଯଦି (csym.n_numaux == 1) {
	    ଯଦି (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    ଫେରନ୍ତୁ 0;
}
