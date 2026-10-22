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

#અન્તર્ભાવ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#undef _tcc_error

#define MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#define MAX_STR_TABLE 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_header[MAXNSCNS];

#define MAX_FUNCS 1000
#define MAX_FUNC_NAME_LENGTH 128

પૂર્ણાંક nFuncs;
અક્ષર Func[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
અક્ષર AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_LENGTH];
પૂર્ણાંક લીટી_No_File_Ptr[MAX_FUNCS];
પૂર્ણાંક EndAddress[MAX_FUNCS];
પૂર્ણાંક Last_લીટી_No[MAX_FUNCS];
પૂર્ણાંક FuncEntries[MAX_FUNCS];

પૂર્ણાંક OutputTheSection(Section * sect);
short પૂર્ણાંક GetCoffFlags(અચલ અક્ષર *s);
શૂન્ય Sort_પ્રતીક_Table(TCCState *s1);
Section *FindSection(TCCState * s1, અચલ અક્ષર *sname);

પૂર્ણાંક C67_main_entry_point;

પૂર્ણાંક Find_Coff_પ્રતીક_Index(TCCState * s1, અચલ અક્ષર *func_name);
પૂર્ણાંક nb_syms;

પ્રકારવ્યાખ્યા સંરચના {
    long tag;
    long size;
    long fileptr;
    long nextsym;
    short પૂર્ણાંક dummy;
} AUXFUNC;

પ્રકારવ્યાખ્યા સંરચના {
    long regmask;
    unsigned short lineno;
    unsigned short nentries;
    પૂર્ણાંક localframe;
    પૂર્ણાંક nextentry;
    short પૂર્ણાંક dummy;
} AUXBF;

પ્રકારવ્યાખ્યા સંરચના {
    long dummy;
    unsigned short lineno;
    unsigned short dummy1;
    પૂર્ણાંક dummy2;
    પૂર્ણાંક dummy3;
    unsigned short dummy4;
} AUXEF;

ST_FUNC પૂર્ણાંક tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    પૂર્ણાંક file_pointer;
    અક્ષર *Coff_str_table, *pCoff_str_table;
    પૂર્ણાંક CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    પૂર્ણાંક i, NSectionsToOutput = 0;

    Coff_str_table = pCoff_str_table = ખાલી;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->data_offset / કદ(Elf32_Sym);
    coff_nb_syms = Find_Coff_પ્રતીક_Index(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = કદ(AOUTHDR);	/* sizeof(optional hdr) */
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

    file_pointer = FILHSZ + કદ(AOUTHDR);

    CoffTextSectionNo = -1;

    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (OutputTheSection(tcc_sect)) {
	    NSectionsToOutput++;

	    જો (CoffTextSectionNo == -1 && tcc_sect == stext)
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

	    file_pointer += કદ(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSectionsToOutput;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_size;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    જો (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * કદ(સંરચના reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	જો (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_end;
	    અક્ષર func_name[MAX_FUNC_NAME_LENGTH],
		last_func_name[MAX_FUNC_NAME_LENGTH];
	    unsigned long func_addr, last_pc, pc;
	    અચલ અક્ષર *incl_files[INCLUDE_ઢગલો_SIZE];
	    પૂર્ણાંક incl_index, len, last_લીટી_અંક;
	    અચલ અક્ષર *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0xffffffff;
	    last_લીટી_અંક = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    nFuncs = 0;
	    જ્યારે (sym < sym_end) {
		પસંદગી (sym->n_type) {
		    /* function start or end */
		સ્થિતિ N_FUN:
		    જો (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_કિંમત + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			EndAddress[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     લીટી_No_File_Ptr[nFuncs]) / LINESZ - 1;
			Last_લીટી_No[nFuncs++] = last_લીટી_અંક + 1;
		    } નહીંતર {
			// beginning of function

			લીટી_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (અચલ અક્ષર *) stabstr_section->data +
			    sym->n_strx;

			p = strchr(str, ':');
			જો (!p) {
			    pstrcpy(func_name, કદ(func_name), str);
			    pstrcpy(Func[nFuncs], કદ(func_name), str);
			} નહીંતર {
			    len = p - str;
			    જો (len > કદ(func_name) - 1)
				len = કદ(func_name) - 1;
			    memcpy(func_name, str, len);
			    memcpy(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], કદ(func_name),
				incl_files[incl_index - 1]);

			func_addr = sym->n_કિંમત;
		    }
		    તોડો;

		    /* line number info */
		સ્થિતિ N_SLINE:
		    pc = sym->n_કિંમત + func_addr;

		    last_pc = pc;
		    last_લીટી_અંક = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    તોડો;
		    /* include files */
		સ્થિતિ N_BINCL:
		    str =
			(અચલ અક્ષર *) stabstr_section->data + sym->n_strx;
		  add_incl:
		    જો (incl_index < INCLUDE_ઢગલો_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    તોડો;
		સ્થિતિ N_EINCL:
		    જો (incl_index > 1)
			incl_index--;
		    તોડો;
		સ્થિતિ N_SO:
		    જો (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } નહીંતર {
			str =
			    (અચલ અક્ષર *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			જો (len > 0 && str[len - 1] != '/')
			    જાઓ add_incl;
		    }
		    તોડો;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    જો (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    નહીંતર
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, કદ(o_filehdr), 1, f);

    // write section headers
    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, કદ(SCNHDR), 1, f);
	}
    }

    // write raw data
    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->data, tcc_sect->data_offset, 1, f);
	}
    }

    // write relocation data
    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    જો (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * કદ(સંરચના reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    જો (s1->do_debug)
	Sort_પ્રતીક_Table(s1);

    // write line no data

    માટે (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_header[i];
	tcc_sect = s1->sections[i];

	જો (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_end;
	    અક્ષર func_name[128], last_func_name[128];
	    unsigned long func_addr, last_pc, pc;
	    અચલ અક્ષર *incl_files[INCLUDE_ઢગલો_SIZE];
	    પૂર્ણાંક incl_index, len, last_લીટી_અંક;
	    અચલ અક્ષર *str, *p;

	    LINENO Coff_લીટી_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_index = 0;
	    last_func_name[0] = '\0';
	    last_pc = 0;
	    last_લીટી_અંક = 1;
	    sym = (Stab_Sym *) stab_section->data + 1;
	    sym_end =
		(Stab_Sym *) (stab_section->data +
			      stab_section->data_offset);

	    જ્યારે (sym < sym_end) {
		પસંદગી (sym->n_type) {
		    /* function start or end */
		સ્થિતિ N_FUN:
		    જો (sym->n_strx == 0) {
			// end of function

			Coff_લીટી_No.l_addr.l_paddr = last_pc;
			Coff_લીટી_No.l_lnno = last_લીટી_અંક + 1;
			fwrite(&Coff_લીટી_No, 6, 1, f);

			pc = sym->n_કિંમત + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } નહીંતર {
			// beginning of function

			str =
			    (અચલ અક્ષર *) stabstr_section->data +
			    sym->n_strx;


			p = strchr(str, ':');
			જો (!p) {
			    pstrcpy(func_name, કદ(func_name), str);
			} નહીંતર {
			    len = p - str;
			    જો (len > કદ(func_name) - 1)
				len = કદ(func_name) - 1;
			    memcpy(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_કિંમત;
			last_pc = func_addr;
			last_લીટી_અંક = -1;

			// output a function begin

			Coff_લીટી_No.l_addr.l_symndx =
			    Find_Coff_પ્રતીક_Index(s1, func_name);
			Coff_લીટી_No.l_lnno = 0;

			fwrite(&Coff_લીટી_No, 6, 1, f);
		    }
		    તોડો;

		    /* line number info */
		સ્થિતિ N_SLINE:
		    pc = sym->n_કિંમત + func_addr;


		    /* XXX: slow! */
		    strcpy(last_func_name, func_name);

		    // output a line reference

		    Coff_લીટી_No.l_addr.l_paddr = last_pc;

		    જો (last_લીટી_અંક == -1) {
			Coff_લીટી_No.l_lnno = sym->n_desc;
		    } નહીંતર {
			Coff_લીટી_No.l_lnno = last_લીટી_અંક + 1;
		    }

		    fwrite(&Coff_લીટી_No, 6, 1, f);

		    last_pc = pc;
		    last_લીટી_અંક = sym->n_desc;

		    તોડો;

		    /* include files */
		સ્થિતિ N_BINCL:
		    str =
			(અચલ અક્ષર *) stabstr_section->data + sym->n_strx;
		  add_incl2:
		    જો (incl_index < INCLUDE_ઢગલો_SIZE) {
			incl_files[incl_index++] = str;
		    }
		    તોડો;
		સ્થિતિ N_EINCL:
		    જો (incl_index > 1)
			incl_index--;
		    તોડો;
		સ્થિતિ N_SO:
		    જો (sym->n_strx == 0) {
			incl_index = 0;	/* end of translation unit */
		    } નહીંતર {
			str =
			    (અચલ અક્ષર *) stabstr_section->data +
			    sym->n_strx;
			/* do not add path */
			len = strlen(str);
			જો (len > 0 && str[len - 1] != '/')
			    જાઓ add_incl2;
		    }
		    તોડો;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    જો (s1->do_debug) {
	પૂર્ણાંક k;
	સંરચના syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	પૂર્ણાંક i;
	Elf32_Sym *p;
	અચલ અક્ષર *name;
	પૂર્ણાંક nstr;
	પૂર્ણાંક n = 0;

	Coff_str_table = (અક્ષર *) tcc_malloc(MAX_STR_TABLE);
	pCoff_str_table = Coff_str_table;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->data;


	માટે (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->data + p->st_name;

	    માટે (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    જો (strlen(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } નહીંતર {
		જો (pCoff_str_table - Coff_str_table + strlen(name) >
		    MAX_STR_TABLE - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n._n_offset =
		    pCoff_str_table - Coff_str_table + 4;

		strcpy(pCoff_str_table, name);
		pCoff_str_table += strlen(name) + 1;	// skip over null
		nstr++;
	    }

	    જો (p->st_info == 4) {
		// put a filename symbol
		csym.n_કિંમત = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } નહીંતર જો (p->st_info == 0x12) {
		// find the function data

		માટે (k = 0; k < nFuncs; k++) {
		    જો (strcmp(name, Func[k]) == 0)
			તોડો;
		}

		જો (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_કિંમત = p->st_કિંમત;	// physical address
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.tag = 0;
		auxfunc.size = EndAddress[k] - p->st_કિંમત;
		auxfunc.fileptr = લીટી_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_કિંમત = p->st_કિંમત;	// physical address
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
		csym.n_કિંમત = EndAddress[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = Last_લીટી_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } નહીંતર {
		// try an put some type info

		જો ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} નહીંતર જો ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} નહીંતર જો ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} નહીંતર જો ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} નહીંતર જો ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} નહીંતર {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_કિંમત = p->st_કિંમત;
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

    જો (s1->do_debug) {
	// write string table

	// first write the size
	i = pCoff_str_table - Coff_str_table;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_table, i, 1, f);

	tcc_free(Coff_str_table);
    }

    પાછા 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

શૂન્ય Sort_પ્રતીક_Table(TCCState *s1)
{
    પૂર્ણાંક i, j, k, n = 0;
    Elf32_Sym *p, *p2, *NewTable;
    અક્ષર *name, *name2;

    NewTable = (Elf32_Sym *) tcc_malloc(nb_syms * કદ(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->data;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    માટે (i = 0; i < nb_syms; i++) {
	જો (p->st_info == 4) {
	    name = (અક્ષર *) symtab_section->link->data + p->st_name;

	    // this is a file symbol, copy it over

	    NewTable[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->data;

	    માટે (j = 0; j < nb_syms; j++) {
		જો (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(અક્ષર *) symtab_section->link->data + p2->st_name;

		    // find the function data index

		    માટે (k = 0; k < nFuncs; k++) {
			જો (strcmp(name2, Func[k]) == 0)
			    તોડો;
		    }

		    જો (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    જો (strcmp(AssociatedFile[k], name) == 0) {
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
    માટે (i = 0; i < nb_syms; i++) {
	જો (p->st_info != 4 && p->st_info != 0x12) {
	    NewTable[n++] = *p;
	}
	p++;
    }

    જો (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->data;
    માટે (i = 0; i < nb_syms; i++) {
	*p++ = NewTable[i];
    }

    tcc_free(NewTable);
}


પૂર્ણાંક Find_Coff_પ્રતીક_Index(TCCState *s1, અચલ અક્ષર *func_name)
{
    પૂર્ણાંક i, n = 0;
    Elf32_Sym *p;
    અક્ષર *name;

    p = (Elf32_Sym *) symtab_section->data;

    માટે (i = 0; i < nb_syms; i++) {

	name = (અક્ષર *) symtab_section->link->data + p->st_name;

	જો (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} નહીંતર જો (p->st_info == 0x12) {

	    જો (strcmp(func_name, name) == 0)
		પાછા n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} નહીંતર {
	    n += 2;
	}

	p++;
    }

    પાછા n;			// total number of symbols
}

પૂર્ણાંક OutputTheSection(Section * sect)
{
    અચલ અક્ષર *s = sect->name;

    જો (!strcmp(s, ".text"))
	પાછા 1;
    નહીંતર જો (!strcmp(s, ".data"))
	પાછા 1;
    નહીંતર
	પાછા 0;
}

short પૂર્ણાંક GetCoffFlags(અચલ અક્ષર *s)
{
    જો (!strcmp(s, ".text"))
	પાછા STYP_TEXT | STYP_DATA | STYP_ALIGN | 0x400;
    નહીંતર જો (!strcmp(s, ".data"))
	પાછા STYP_DATA;
    નહીંતર જો (!strcmp(s, ".bss"))
	પાછા STYP_BSS;
    નહીંતર જો (!strcmp(s, ".stack"))
	પાછા STYP_BSS | STYP_ALIGN | 0x200;
    નહીંતર જો (!strcmp(s, ".cinit"))
	પાછા STYP_COPY | STYP_DATA | STYP_ALIGN | 0x200;
    નહીંતર
	પાછા 0;
}

Section *FindSection(TCCState * s1, અચલ અક્ષર *sname)
{
    Section *s;
    પૂર્ણાંક i;

    માટે (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	જો (!strcmp(sname, s->name))
	    પાછા s;
    }

    tcc_error("could not find section %s", sname);
    પાછા 0;
}

ST_FUNC પૂર્ણાંક tcc_load_coff(TCCState * s1, પૂર્ણાંક fd)
{
// tktk TokenSym *ts;

    FILE *f;
    unsigned પૂર્ણાંક str_size;
    અક્ષર *Coff_str_table, *name;
    પૂર્ણાંક i, k;
    સંરચના syment csym;
    અક્ષર name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    જો (!f) {
	tcc_error("Unable to open .out file for input");
    }

    જો (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    જો (fread(&o_filehdr, કદ(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    જો (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    જો (fread(&str_size, કદ(પૂર્ણાંક), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_table = (અક્ષર *) tcc_malloc(str_size);

    જો (fread(Coff_str_table, str_size - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    જો (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    માટે (i = 0; i < file_hdr.f_nsyms; i++) {
	જો (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	જો (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_table + csym._n._n_n._n_offset - 4;
	} નહીંતર {
	    name = csym._n._n_name;

	    જો (name[7] != 0) {
		માટે (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	જો (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    જો (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_add_પ્રતીક(s1, name, (શૂન્ય*)(uintptr_t)csym.n_કિંમત);
	}
	// skip any aux records

	જો (csym.n_numaux == 1) {
	    જો (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    પાછા 0;
}
