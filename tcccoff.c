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
#अपरिभाषय _tcc_error

#परिभाषय MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#परिभाषय MAX_STR_सारणी 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_शीर्षकम्[MAXNSCNS];

#परिभाषय MAX_FUNCS 1000
#परिभाषय MAX_FUNC_NAME_दीर्घता 128

पूर्णाङ्क nFuncs;
वर्ण Func[MAX_FUNCS][MAX_FUNC_NAME_दीर्घता];
वर्ण AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_दीर्घता];
पूर्णाङ्क पङ्क्तिः_No_File_Ptr[MAX_FUNCS];
पूर्णाङ्क अन्तः_स्थानाङ्कः[MAX_FUNCS];
पूर्णाङ्क चरमः_पङ्क्तिः_No[MAX_FUNCS];
पूर्णाङ्क FuncEntries[MAX_FUNCS];

पूर्णाङ्क OutputTheSection(Section * sect);
ह्रस्व पूर्णाङ्क GetCoffFlags(ध्रुव वर्ण *s);
शून्य क्रमय_चिह्नम्_सारणी(TCCState *s1);
Section *FindSection(TCCState * s1, ध्रुव वर्ण *sname);

पूर्णाङ्क C67_main_प्रविष्टिः_point;

पूर्णाङ्क Find_Coff_चिह्नम्_सूचकांक(TCCState * s1, ध्रुव वर्ण *func_name);
पूर्णाङ्क nb_syms;

प्रकारनिर्देश संरचना {
    दीर्घ चिह्नकम्;
    दीर्घ आकार;
    दीर्घ fileptr;
    दीर्घ nextsym;
    ह्रस्व पूर्णाङ्क dummy;
} AUXFUNC;

प्रकारनिर्देश संरचना {
    दीर्घ regmask;
    अचिह्नित ह्रस्व lineno;
    अचिह्नित ह्रस्व nentries;
    पूर्णाङ्क localframe;
    पूर्णाङ्क nextentry;
    ह्रस्व पूर्णाङ्क dummy;
} AUXBF;

प्रकारनिर्देश संरचना {
    दीर्घ dummy;
    अचिह्नित ह्रस्व lineno;
    अचिह्नित ह्रस्व dummy1;
    पूर्णाङ्क dummy2;
    पूर्णाङ्क dummy3;
    अचिह्नित ह्रस्व dummy4;
} AUXEF;

ST_FUNC पूर्णाङ्क tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    पूर्णाङ्क file_pointer;
    वर्ण *Coff_str_सारणी, *p_Coff_str_सारणी;
    पूर्णाङ्क CoffTextSectionNo, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    पूर्णाङ्क i, NSections_गन्तव्यम्_Output = 0;

    Coff_str_सारणी = p_Coff_str_सारणी = रिक्त;

    stext = FindSection(s1, ".text");
    sdata = FindSection(s1, ".data");
    sbss = FindSection(s1, ".bss");

    nb_syms = symtab_section->दत्त_विस्थापनम् / परिमाण(Elf32_Sym);
    coff_nb_syms = Find_Coff_चिह्नम्_सूचकांक(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = परिमाण(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_TargetID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->दत्त_विस्थापनम्;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->दत्त_विस्थापनम्;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->दत्त_विस्थापनम्;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_प्रविष्टिः_point;	/* entry pt.                          */
    o_filehdr.text_start = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.दत्त_start = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_pointer = FILHSZ + परिमाण(AOUTHDR);

    CoffTextSectionNo = -1;

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (OutputTheSection(tcc_sect)) {
	    NSections_गन्तव्यम्_Output++;

	    यदि (CoffTextSectionNo == -1 && tcc_sect == stext)
		CoffTextSectionNo = NSections_गन्तव्यम्_Output;	// rem which coff sect number the .text sect is

	    वाक्यं_प्रतिलिख(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_आकार = tcc_sect->दत्त_विस्थापनम्;	/* section size */
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

    file_hdr.f_nscns = NSections_गन्तव्यम्_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_pointer;	/* file ptr to raw data for section */
	    file_pointer += coff_sec->s_आकार;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    यदि (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_pointer;	/* file ptr to relocation */
		file_pointer += coff_sec->s_nreloc * परिमाण(संरचना reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	यदि (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_अन्तः;
	    वर्ण func_name[MAX_FUNC_NAME_दीर्घता],
		चरमः_func_name[MAX_FUNC_NAME_दीर्घता];
	    अचिह्नित दीर्घ func_addr, चरमः_pc, pc;
	    ध्रुव वर्ण *incl_files[INCLUDE_राशिः_आकार];
	    पूर्णाङ्क incl_सूचकांक, len, चरमः_पङ्क्तिः_अङ्कः;
	    ध्रुव वर्ण *str, *p;

	    coff_sec->s_lnnoptr = file_pointer;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_सूचकांक = 0;
	    चरमः_func_name[0] = '\0';
	    चरमः_pc = 0xffffffff;
	    चरमः_पङ्क्तिः_अङ्कः = 1;
	    sym = (Stab_Sym *) stab_section->दत्त + 1;
	    sym_अन्तः =
		(Stab_Sym *) (stab_section->दत्त +
			      stab_section->दत्त_विस्थापनम्);

	    nFuncs = 0;
	    यावत् (sym < sym_अन्तः) {
		विकल्प (sym->n_type) {
		    /* function start or end */
		पक्ष N_FUN:
		    यदि (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			pc = sym->n_मानम् + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			अन्तः_स्थानाङ्कः[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_pointer -
			     पङ्क्तिः_No_File_Ptr[nFuncs]) / LINESZ - 1;
			चरमः_पङ्क्तिः_No[nFuncs++] = चरमः_पङ्क्तिः_अङ्कः + 1;
		    } अन्यथा {
			// beginning of function

			पङ्क्तिः_No_File_Ptr[nFuncs] = file_pointer;
			coff_sec->s_nlnno++;
			file_pointer += LINESZ;

			str =
			    (ध्रुव वर्ण *) stabstr_section->दत्त +
			    sym->n_strx;

			p = strchr(str, ':');
			यदि (!p) {
			    pstrcpy(func_name, परिमाण(func_name), str);
			    pstrcpy(Func[nFuncs], परिमाण(func_name), str);
			} अन्यथा {
			    len = p - str;
			    यदि (len > परिमाण(func_name) - 1)
				len = परिमाण(func_name) - 1;
			    स्मृतिं_प्रतिलिख(func_name, str, len);
			    स्मृतिं_प्रतिलिख(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], परिमाण(func_name),
				incl_files[incl_सूचकांक - 1]);

			func_addr = sym->n_मानम्;
		    }
		    भङ्ग;

		    /* line number info */
		पक्ष N_SLINE:
		    pc = sym->n_मानम् + func_addr;

		    चरमः_pc = pc;
		    चरमः_पङ्क्तिः_अङ्कः = sym->n_desc;

		    /* XXX: slow! */
		    वाक्यं_प्रतिलिख(चरमः_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_pointer += LINESZ;
		    भङ्ग;
		    /* include files */
		पक्ष N_BINCL:
		    str =
			(ध्रुव वर्ण *) stabstr_section->दत्त + sym->n_strx;
		  सङ्कलय_incl:
		    यदि (incl_सूचकांक < INCLUDE_राशिः_आकार) {
			incl_files[incl_सूचकांक++] = str;
		    }
		    भङ्ग;
		पक्ष N_EINCL:
		    यदि (incl_सूचकांक > 1)
			incl_सूचकांक--;
		    भङ्ग;
		पक्ष N_SO:
		    यदि (sym->n_strx == 0) {
			incl_सूचकांक = 0;	/* end of translation unit */
		    } अन्यथा {
			str =
			    (ध्रुव वर्ण *) stabstr_section->दत्त +
			    sym->n_strx;
			/* do not add path */
			len = वाक्यदैर्घ्यम्(str);
			यदि (len > 0 && str[len - 1] != '/')
			    गच्छ सङ्कलय_incl;
		    }
		    भङ्ग;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_pointer;	/* file pointer to symtab */

    यदि (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    अन्यथा
	file_hdr.f_nsyms = 0;

    file_pointer += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, परिमाण(o_filehdr), 1, f);

    // write section headers
    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, परिमाण(SCNHDR), 1, f);
	}
    }

    // write raw data
    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->दत्त, tcc_sect->दत्त_विस्थापनम्, 1, f);
	}
    }

    // write relocation data
    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    यदि (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * परिमाण(संरचना reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    यदि (s1->do_debug)
	क्रमय_चिह्नम्_सारणी(s1);

    // write line no data

    प्रति (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_शीर्षकम्[i];
	tcc_sect = s1->sections[i];

	यदि (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_अन्तः;
	    वर्ण func_name[128], चरमः_func_name[128];
	    अचिह्नित दीर्घ func_addr, चरमः_pc, pc;
	    ध्रुव वर्ण *incl_files[INCLUDE_राशिः_आकार];
	    पूर्णाङ्क incl_सूचकांक, len, चरमः_पङ्क्तिः_अङ्कः;
	    ध्रुव वर्ण *str, *p;

	    LINENO Coff_पङ्क्तिः_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_सूचकांक = 0;
	    चरमः_func_name[0] = '\0';
	    चरमः_pc = 0;
	    चरमः_पङ्क्तिः_अङ्कः = 1;
	    sym = (Stab_Sym *) stab_section->दत्त + 1;
	    sym_अन्तः =
		(Stab_Sym *) (stab_section->दत्त +
			      stab_section->दत्त_विस्थापनम्);

	    यावत् (sym < sym_अन्तः) {
		विकल्प (sym->n_type) {
		    /* function start or end */
		पक्ष N_FUN:
		    यदि (sym->n_strx == 0) {
			// end of function

			Coff_पङ्क्तिः_No.l_addr.l_paddr = चरमः_pc;
			Coff_पङ्क्तिः_No.l_lnno = चरमः_पङ्क्तिः_अङ्कः + 1;
			fwrite(&Coff_पङ्क्तिः_No, 6, 1, f);

			pc = sym->n_मानम् + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } अन्यथा {
			// beginning of function

			str =
			    (ध्रुव वर्ण *) stabstr_section->दत्त +
			    sym->n_strx;


			p = strchr(str, ':');
			यदि (!p) {
			    pstrcpy(func_name, परिमाण(func_name), str);
			} अन्यथा {
			    len = p - str;
			    यदि (len > परिमाण(func_name) - 1)
				len = परिमाण(func_name) - 1;
			    स्मृतिं_प्रतिलिख(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_मानम्;
			चरमः_pc = func_addr;
			चरमः_पङ्क्तिः_अङ्कः = -1;

			// output a function begin

			Coff_पङ्क्तिः_No.l_addr.l_symndx =
			    Find_Coff_चिह्नम्_सूचकांक(s1, func_name);
			Coff_पङ्क्तिः_No.l_lnno = 0;

			fwrite(&Coff_पङ्क्तिः_No, 6, 1, f);
		    }
		    भङ्ग;

		    /* line number info */
		पक्ष N_SLINE:
		    pc = sym->n_मानम् + func_addr;


		    /* XXX: slow! */
		    वाक्यं_प्रतिलिख(चरमः_func_name, func_name);

		    // output a line reference

		    Coff_पङ्क्तिः_No.l_addr.l_paddr = चरमः_pc;

		    यदि (चरमः_पङ्क्तिः_अङ्कः == -1) {
			Coff_पङ्क्तिः_No.l_lnno = sym->n_desc;
		    } अन्यथा {
			Coff_पङ्क्तिः_No.l_lnno = चरमः_पङ्क्तिः_अङ्कः + 1;
		    }

		    fwrite(&Coff_पङ्क्तिः_No, 6, 1, f);

		    चरमः_pc = pc;
		    चरमः_पङ्क्तिः_अङ्कः = sym->n_desc;

		    भङ्ग;

		    /* include files */
		पक्ष N_BINCL:
		    str =
			(ध्रुव वर्ण *) stabstr_section->दत्त + sym->n_strx;
		  सङ्कलय_incl2:
		    यदि (incl_सूचकांक < INCLUDE_राशिः_आकार) {
			incl_files[incl_सूचकांक++] = str;
		    }
		    भङ्ग;
		पक्ष N_EINCL:
		    यदि (incl_सूचकांक > 1)
			incl_सूचकांक--;
		    भङ्ग;
		पक्ष N_SO:
		    यदि (sym->n_strx == 0) {
			incl_सूचकांक = 0;	/* end of translation unit */
		    } अन्यथा {
			str =
			    (ध्रुव वर्ण *) stabstr_section->दत्त +
			    sym->n_strx;
			/* do not add path */
			len = वाक्यदैर्घ्यम्(str);
			यदि (len > 0 && str[len - 1] != '/')
			    गच्छ सङ्कलय_incl2;
		    }
		    भङ्ग;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    यदि (s1->do_debug) {
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

	Coff_str_सारणी = (वर्ण *) tcc_malloc(MAX_STR_सारणी);
	p_Coff_str_सारणी = Coff_str_सारणी;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->दत्त;


	प्रति (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->दत्त + p->st_name;

	    प्रति (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    यदि (वाक्यदैर्घ्यम्(name) <= 8) {
		वाक्यं_प्रतिलिख(csym._n._n_name, name);
	    } अन्यथा {
		यदि (p_Coff_str_सारणी - Coff_str_सारणी + वाक्यदैर्घ्यम्(name) >
		    MAX_STR_सारणी - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_विस्थापनम् =
		    p_Coff_str_सारणी - Coff_str_सारणी + 4;

		वाक्यं_प्रतिलिख(p_Coff_str_सारणी, name);
		p_Coff_str_सारणी += वाक्यदैर्घ्यम्(name) + 1;	// skip over null
		nstr++;
	    }

	    यदि (p->st_info == 4) {
		// put a filename symbol
		csym.n_मानम् = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } अन्यथा यदि (p->st_info == 0x12) {
		// find the function data

		प्रति (k = 0; k < nFuncs; k++) {
		    यदि (वाक्यं_तुलय(name, Func[k]) == 0)
			भङ्ग;
		}

		यदि (k >= nFuncs) {
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

		auxfunc.चिह्नकम् = 0;
		auxfunc.आकार = अन्तः_स्थानाङ्कः[k] - p->st_मानम्;
		auxfunc.fileptr = पङ्क्तिः_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		वाक्यं_प्रतिलिख(csym._n._n_name, ".bf");
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

		वाक्यं_प्रतिलिख(csym._n._n_name, ".ef");
		csym.n_मानम् = अन्तः_स्थानाङ्कः[k];	// physical address  
		csym.n_scnum = CoffTextSectionNo;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = चरमः_पङ्क्तिः_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } अन्यथा {
		// try an put some type info

		यदि ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} अन्यथा यदि ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} अन्यथा यदि ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} अन्यथा यदि ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} अन्यथा यदि ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} अन्यथा {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_मानम् = p->st_मानम्;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.चिह्नकम् = 0;
		auxfunc.आकार = 0x20;
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

    यदि (s1->do_debug) {
	// write string table

	// first write the size
	i = p_Coff_str_सारणी - Coff_str_सारणी;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_सारणी, i, 1, f);

	tcc_free(Coff_str_सारणी);
    }

    प्रत्यागम 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

शून्य क्रमय_चिह्नम्_सारणी(TCCState *s1)
{
    पूर्णाङ्क i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_सारणी;
    वर्ण *name, *name2;

    New_सारणी = (Elf32_Sym *) tcc_malloc(nb_syms * परिमाण(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->दत्त;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    प्रति (i = 0; i < nb_syms; i++) {
	यदि (p->st_info == 4) {
	    name = (वर्ण *) symtab_section->link->दत्त + p->st_name;

	    // this is a file symbol, copy it over

	    New_सारणी[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->दत्त;

	    प्रति (j = 0; j < nb_syms; j++) {
		यदि (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(वर्ण *) symtab_section->link->दत्त + p2->st_name;

		    // find the function data index

		    प्रति (k = 0; k < nFuncs; k++) {
			यदि (वाक्यं_तुलय(name2, Func[k]) == 0)
			    भङ्ग;
		    }

		    यदि (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    यदि (वाक्यं_तुलय(AssociatedFile[k], name) == 0) {
			// yes they match copy it over

			New_सारणी[n++] = *p2;
		    }
		}
		p2++;
	    }
	}
	p++;
    }

    // now all the filename and func symbols should have been copied over
    // copy all the rest over (all except file and funcs)

    p = (Elf32_Sym *) symtab_section->दत्त;
    प्रति (i = 0; i < nb_syms; i++) {
	यदि (p->st_info != 4 && p->st_info != 0x12) {
	    New_सारणी[n++] = *p;
	}
	p++;
    }

    यदि (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->दत्त;
    प्रति (i = 0; i < nb_syms; i++) {
	*p++ = New_सारणी[i];
    }

    tcc_free(New_सारणी);
}


पूर्णाङ्क Find_Coff_चिह्नम्_सूचकांक(TCCState *s1, ध्रुव वर्ण *func_name)
{
    पूर्णाङ्क i, n = 0;
    Elf32_Sym *p;
    वर्ण *name;

    p = (Elf32_Sym *) symtab_section->दत्त;

    प्रति (i = 0; i < nb_syms; i++) {

	name = (वर्ण *) symtab_section->link->दत्त + p->st_name;

	यदि (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} अन्यथा यदि (p->st_info == 0x12) {

	    यदि (वाक्यं_तुलय(func_name, name) == 0)
		प्रत्यागम n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} अन्यथा {
	    n += 2;
	}

	p++;
    }

    प्रत्यागम n;			// total number of symbols
}

पूर्णाङ्क OutputTheSection(Section * sect)
{
    ध्रुव वर्ण *s = sect->name;

    यदि (!वाक्यं_तुलय(s, ".text"))
	प्रत्यागम 1;
    अन्यथा यदि (!वाक्यं_तुलय(s, ".data"))
	प्रत्यागम 1;
    अन्यथा
	प्रत्यागम 0;
}

ह्रस्व पूर्णाङ्क GetCoffFlags(ध्रुव वर्ण *s)
{
    यदि (!वाक्यं_तुलय(s, ".text"))
	प्रत्यागम STYP_TEXT | STYP_दत्त | STYP_ALIGN | 0x400;
    अन्यथा यदि (!वाक्यं_तुलय(s, ".data"))
	प्रत्यागम STYP_दत्त;
    अन्यथा यदि (!वाक्यं_तुलय(s, ".bss"))
	प्रत्यागम STYP_BSS;
    अन्यथा यदि (!वाक्यं_तुलय(s, ".stack"))
	प्रत्यागम STYP_BSS | STYP_ALIGN | 0x200;
    अन्यथा यदि (!वाक्यं_तुलय(s, ".cinit"))
	प्रत्यागम STYP_COPY | STYP_दत्त | STYP_ALIGN | 0x200;
    अन्यथा
	प्रत्यागम 0;
}

Section *FindSection(TCCState * s1, ध्रुव वर्ण *sname)
{
    Section *s;
    पूर्णाङ्क i;

    प्रति (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	यदि (!वाक्यं_तुलय(sname, s->name))
	    प्रत्यागम s;
    }

    tcc_error("could not find section %s", sname);
    प्रत्यागम 0;
}

ST_FUNC पूर्णाङ्क tcc_आरोपय_coff(TCCState * s1, पूर्णाङ्क fd)
{
// tktk TokenSym *ts;

    FILE *f;
    अचिह्नित पूर्णाङ्क str_आकार;
    वर्ण *Coff_str_सारणी, *name;
    पूर्णाङ्क i, k;
    संरचना syment csym;
    वर्ण name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    यदि (!f) {
	tcc_error("Unable to open .out file for input");
    }

    यदि (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    यदि (fread(&o_filehdr, परिमाण(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    यदि (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    यदि (fread(&str_आकार, परिमाण(पूर्णाङ्क), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_सारणी = (वर्ण *) tcc_malloc(str_आकार);

    यदि (fread(Coff_str_सारणी, str_आकार - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    यदि (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    प्रति (i = 0; i < file_hdr.f_nsyms; i++) {
	यदि (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	यदि (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_सारणी + csym._n._n_n.n_विस्थापनम् - 4;
	} अन्यथा {
	    name = csym._n._n_name;

	    यदि (name[7] != 0) {
		प्रति (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	यदि (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    यदि (name[0] == '_' && वाक्यं_तुलय(name, "_main") != 0)
		name++;

	    tcc_सङ्कलय_चिह्नम्(s1, name, (शून्य*)(uintptr_t)csym.n_मानम्);
	}
	// skip any aux records

	यदि (csym.n_numaux == 1) {
	    यदि (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    प्रत्यागम 0;
}
