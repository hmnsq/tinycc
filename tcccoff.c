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
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _tcc_error

#ವ್ಯಾಖ್ಯಾನಿಸು MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_STR_ಕೋಷ್ಟಕ 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_ಶೀರ್ಷಿಕೆ[MAXNSCNS];

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_FUNCS 1000
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_FUNC_NAME_ಉದ್ದಳತೆ 128

ಪೂರ್ಣಾಂಕ nFuncs;
ಅಕ್ಷರ Func[MAX_FUNCS][MAX_FUNC_NAME_ಉದ್ದಳತೆ];
ಅಕ್ಷರ AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_ಉದ್ದಳತೆ];
ಪೂರ್ಣಾಂಕ ಸಾಲು_No_File_Ptr[MAX_FUNCS];
ಪೂರ್ಣಾಂಕ ಕೊನೆ_ವಿಳಾಸ[MAX_FUNCS];
ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_ಸಾಲು_No[MAX_FUNCS];
ಪೂರ್ಣಾಂಕ FuncEntries[MAX_FUNCS];

ಪೂರ್ಣಾಂಕ OutputTheSection(Section * sect);
ಗಿಡ್ಡ ಪೂರ್ಣಾಂಕ GetCoffFlags(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);
ಶೂನ್ಯ ವಿಂಗಡಿಸು_ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ(TCCState *s1);
Section *ಕಂಡುಹಿಡಿ_Section(TCCState * s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sname);

ಪೂರ್ಣಾಂಕ C67_main_ನಮೂದು_ಬಿಂದು;

ಪೂರ್ಣಾಂಕ ಕಂಡುಹಿಡಿ_Coff_ಚಿಹ್ನೆ_ಸೂಚ್ಯಂಕ(TCCState * s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *func_name);
ಪೂರ್ಣಾಂಕ nb_syms;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ದೀರ್ಘ ಟ್ಯಾಗ್;
    ದೀರ್ಘ ಗಾತ್ರ_2;
    ದೀರ್ಘ fileptr;
    ದೀರ್ಘ nextsym;
    ಗಿಡ್ಡ ಪೂರ್ಣಾಂಕ dummy;
} AUXFUNC;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ದೀರ್ಘ regmask;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ lineno;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ nentries;
    ಪೂರ್ಣಾಂಕ localframe;
    ಪೂರ್ಣಾಂಕ nextentry;
    ಗಿಡ್ಡ ಪೂರ್ಣಾಂಕ dummy;
} AUXBF;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ದೀರ್ಘ dummy;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ lineno;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ dummy1;
    ಪೂರ್ಣಾಂಕ dummy2;
    ಪೂರ್ಣಾಂಕ dummy3;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ dummy4;
} AUXEF;

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    ಪೂರ್ಣಾಂಕ file_ಸೂಚಕ;
    ಅಕ್ಷರ *Coff_str_ಕೋಷ್ಟಕ, *p_Coff_str_ಕೋಷ್ಟಕ;
    ಪೂರ್ಣಾಂಕ Coff_ಪಠ್ಯ_Section_No, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    ಪೂರ್ಣಾಂಕ i, NSections_ಗಮ್ಯ_Output = 0;

    Coff_str_ಕೋಷ್ಟಕ = p_Coff_str_ಕೋಷ್ಟಕ = ಖಾಲಿ;

    stext = ಕಂಡುಹಿಡಿ_Section(s1, ".text");
    sdata = ಕಂಡುಹಿಡಿ_Section(s1, ".data");
    sbss = ಕಂಡುಹಿಡಿ_Section(s1, ".bss");

    nb_syms = symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ(Elf32_Sym);
    coff_nb_syms = ಕಂಡುಹಿಡಿ_Coff_ಚಿಹ್ನೆ_ಸೂಚ್ಯಂಕ(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = ಗಾತ್ರ(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_ಗುರಿ_ID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_ನಮೂದು_ಬಿಂದು;	/* entry pt.                          */
    o_filehdr.ಪಠ್ಯ_ಆರಂಭ = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.ದತ್ತಾಂಶ_ಆರಂಭ = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_ಸೂಚಕ = FILHSZ + ಗಾತ್ರ(AOUTHDR);

    Coff_ಪಠ್ಯ_Section_No = -1;

    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (OutputTheSection(tcc_sect)) {
	    NSections_ಗಮ್ಯ_Output++;

	    ಆದರೆ (Coff_ಪಠ್ಯ_Section_No == -1 && tcc_sect == stext)
		Coff_ಪಠ್ಯ_Section_No = NSections_ಗಮ್ಯ_Output;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_ಗಾತ್ರ = tcc_sect->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_ಪುಟ = 0;	/* memory page id */

	    file_ಸೂಚಕ += ಗಾತ್ರ(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSections_ಗಮ್ಯ_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_ಸೂಚಕ;	/* file ptr to raw data for section */
	    file_ಸೂಚಕ += coff_sec->s_ಗಾತ್ರ;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ಆದರೆ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_ಸೂಚಕ;	/* file ptr to relocation */
		file_ಸೂಚಕ += coff_sec->s_nreloc * ಗಾತ್ರ(ರಚನೆ reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	ಆದರೆ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_ಕೊನೆ;
	    ಅಕ್ಷರ func_name[MAX_FUNC_NAME_ಉದ್ದಳತೆ],
		ಕೊನೆಯ_func_name[MAX_FUNC_NAME_ಉದ್ದಳತೆ];
	    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_addr, ಕೊನೆಯ_pc, pc;
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *incl_files[INCLUDE_ರಾಶಿ_ಗಾತ್ರ];
	    ಪೂರ್ಣಾಂಕ incl_ಸೂಚ್ಯಂಕ, len, ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ;
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, *p;

	    coff_sec->s_lnnoptr = file_ಸೂಚಕ;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_ಸೂಚ್ಯಂಕ = 0;
	    ಕೊನೆಯ_func_name[0] = '\0';
	    ಕೊನೆಯ_pc = 0xffffffff;
	    ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = 1;
	    sym = (Stab_Sym *) stab_section->ದತ್ತಾಂಶ + 1;
	    sym_ಕೊನೆ =
		(Stab_Sym *) (stab_section->ದತ್ತಾಂಶ +
			      stab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);

	    nFuncs = 0;
	    ಆಗ (sym < sym_ಕೊನೆ) {
		ಆಯ್ಕೆ (sym->n_type) {
		    /* function start or end */
		ಸ್ಥಿತಿ N_FUN:
		    ಆದರೆ (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_ಸೂಚಕ += LINESZ;

			pc = sym->n_ಮೌಲ್ಯ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			ಕೊನೆ_ವಿಳಾಸ[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_ಸೂಚಕ -
			     ಸಾಲು_No_File_Ptr[nFuncs]) / LINESZ - 1;
			ಕೊನೆಯ_ಸಾಲು_No[nFuncs++] = ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ + 1;
		    } ಇಲ್ಲದಿದ್ದರೆ {
			// beginning of function

			ಸಾಲು_No_File_Ptr[nFuncs] = file_ಸೂಚಕ;
			coff_sec->s_nlnno++;
			file_ಸೂಚಕ += LINESZ;

			str =
			    (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) stabstr_section->ದತ್ತಾಂಶ +
			    sym->n_strx;

			p = strchr(str, ':');
			ಆದರೆ (!p) {
			    pstrcpy(func_name, ಗಾತ್ರ(func_name), str);
			    pstrcpy(Func[nFuncs], ಗಾತ್ರ(func_name), str);
			} ಇಲ್ಲದಿದ್ದರೆ {
			    len = p - str;
			    ಆದರೆ (len > ಗಾತ್ರ(func_name) - 1)
				len = ಗಾತ್ರ(func_name) - 1;
			    ಸ್ಮರಣೆ_ನಕಲು(func_name, str, len);
			    ಸ್ಮರಣೆ_ನಕಲು(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], ಗಾತ್ರ(func_name),
				incl_files[incl_ಸೂಚ್ಯಂಕ - 1]);

			func_addr = sym->n_ಮೌಲ್ಯ;
		    }
		    ನಿಲ್ಲಿಸು;

		    /* line number info */
		ಸ್ಥಿತಿ N_SLINE:
		    pc = sym->n_ಮೌಲ್ಯ + func_addr;

		    ಕೊನೆಯ_pc = pc;
		    ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(ಕೊನೆಯ_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_ಸೂಚಕ += LINESZ;
		    ನಿಲ್ಲಿಸು;
		    /* include files */
		ಸ್ಥಿತಿ N_BINCL:
		    str =
			(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) stabstr_section->ದತ್ತಾಂಶ + sym->n_strx;
		  ಕೂಡಿಸು_incl:
		    ಆದರೆ (incl_ಸೂಚ್ಯಂಕ < INCLUDE_ರಾಶಿ_ಗಾತ್ರ) {
			incl_files[incl_ಸೂಚ್ಯಂಕ++] = str;
		    }
		    ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ N_EINCL:
		    ಆದರೆ (incl_ಸೂಚ್ಯಂಕ > 1)
			incl_ಸೂಚ್ಯಂಕ--;
		    ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ N_SO:
		    ಆದರೆ (sym->n_strx == 0) {
			incl_ಸೂಚ್ಯಂಕ = 0;	/* end of translation unit */
		    } ಇಲ್ಲದಿದ್ದರೆ {
			str =
			    (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) stabstr_section->ದತ್ತಾಂಶ +
			    sym->n_strx;
			/* do not add path */
			len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str);
			ಆದರೆ (len > 0 && str[len - 1] != '/')
			    ಹೋಗು ಕೂಡಿಸು_incl;
		    }
		    ನಿಲ್ಲಿಸು;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_ಸೂಚಕ;	/* file pointer to symtab */

    ಆದರೆ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    ಇಲ್ಲದಿದ್ದರೆ
	file_hdr.f_nsyms = 0;

    file_ಸೂಚಕ += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, ಗಾತ್ರ(o_filehdr), 1, f);

    // write section headers
    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, ಗಾತ್ರ(SCNHDR), 1, f);
	}
    }

    // write raw data
    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->ದತ್ತಾಂಶ, tcc_sect->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ, 1, f);
	}
    }

    // write relocation data
    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ಆದರೆ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * ಗಾತ್ರ(ರಚನೆ reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    ಆದರೆ (s1->do_debug)
	ವಿಂಗಡಿಸು_ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ(s1);

    // write line no data

    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ಶೀರ್ಷಿಕೆ[i];
	tcc_sect = s1->sections[i];

	ಆದರೆ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_ಕೊನೆ;
	    ಅಕ್ಷರ func_name[128], ಕೊನೆಯ_func_name[128];
	    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ func_addr, ಕೊನೆಯ_pc, pc;
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *incl_files[INCLUDE_ರಾಶಿ_ಗಾತ್ರ];
	    ಪೂರ್ಣಾಂಕ incl_ಸೂಚ್ಯಂಕ, len, ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ;
	    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, *p;

	    LINENO Coff_ಸಾಲು_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_ಸೂಚ್ಯಂಕ = 0;
	    ಕೊನೆಯ_func_name[0] = '\0';
	    ಕೊನೆಯ_pc = 0;
	    ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = 1;
	    sym = (Stab_Sym *) stab_section->ದತ್ತಾಂಶ + 1;
	    sym_ಕೊನೆ =
		(Stab_Sym *) (stab_section->ದತ್ತಾಂಶ +
			      stab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);

	    ಆಗ (sym < sym_ಕೊನೆ) {
		ಆಯ್ಕೆ (sym->n_type) {
		    /* function start or end */
		ಸ್ಥಿತಿ N_FUN:
		    ಆದರೆ (sym->n_strx == 0) {
			// end of function

			Coff_ಸಾಲು_No.l_addr.l_paddr = ಕೊನೆಯ_pc;
			Coff_ಸಾಲು_No.l_lnno = ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ + 1;
			fwrite(&Coff_ಸಾಲು_No, 6, 1, f);

			pc = sym->n_ಮೌಲ್ಯ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } ಇಲ್ಲದಿದ್ದರೆ {
			// beginning of function

			str =
			    (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) stabstr_section->ದತ್ತಾಂಶ +
			    sym->n_strx;


			p = strchr(str, ':');
			ಆದರೆ (!p) {
			    pstrcpy(func_name, ಗಾತ್ರ(func_name), str);
			} ಇಲ್ಲದಿದ್ದರೆ {
			    len = p - str;
			    ಆದರೆ (len > ಗಾತ್ರ(func_name) - 1)
				len = ಗಾತ್ರ(func_name) - 1;
			    ಸ್ಮರಣೆ_ನಕಲು(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_ಮೌಲ್ಯ;
			ಕೊನೆಯ_pc = func_addr;
			ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = -1;

			// output a function begin

			Coff_ಸಾಲು_No.l_addr.l_symndx =
			    ಕಂಡುಹಿಡಿ_Coff_ಚಿಹ್ನೆ_ಸೂಚ್ಯಂಕ(s1, func_name);
			Coff_ಸಾಲು_No.l_lnno = 0;

			fwrite(&Coff_ಸಾಲು_No, 6, 1, f);
		    }
		    ನಿಲ್ಲಿಸು;

		    /* line number info */
		ಸ್ಥಿತಿ N_SLINE:
		    pc = sym->n_ಮೌಲ್ಯ + func_addr;


		    /* XXX: slow! */
		    strcpy(ಕೊನೆಯ_func_name, func_name);

		    // output a line reference

		    Coff_ಸಾಲು_No.l_addr.l_paddr = ಕೊನೆಯ_pc;

		    ಆದರೆ (ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ == -1) {
			Coff_ಸಾಲು_No.l_lnno = sym->n_desc;
		    } ಇಲ್ಲದಿದ್ದರೆ {
			Coff_ಸಾಲು_No.l_lnno = ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ + 1;
		    }

		    fwrite(&Coff_ಸಾಲು_No, 6, 1, f);

		    ಕೊನೆಯ_pc = pc;
		    ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = sym->n_desc;

		    ನಿಲ್ಲಿಸು;

		    /* include files */
		ಸ್ಥಿತಿ N_BINCL:
		    str =
			(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) stabstr_section->ದತ್ತಾಂಶ + sym->n_strx;
		  ಕೂಡಿಸು_incl2:
		    ಆದರೆ (incl_ಸೂಚ್ಯಂಕ < INCLUDE_ರಾಶಿ_ಗಾತ್ರ) {
			incl_files[incl_ಸೂಚ್ಯಂಕ++] = str;
		    }
		    ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ N_EINCL:
		    ಆದರೆ (incl_ಸೂಚ್ಯಂಕ > 1)
			incl_ಸೂಚ್ಯಂಕ--;
		    ನಿಲ್ಲಿಸು;
		ಸ್ಥಿತಿ N_SO:
		    ಆದರೆ (sym->n_strx == 0) {
			incl_ಸೂಚ್ಯಂಕ = 0;	/* end of translation unit */
		    } ಇಲ್ಲದಿದ್ದರೆ {
			str =
			    (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *) stabstr_section->ದತ್ತಾಂಶ +
			    sym->n_strx;
			/* do not add path */
			len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str);
			ಆದರೆ (len > 0 && str[len - 1] != '/')
			    ಹೋಗು ಕೂಡಿಸು_incl2;
		    }
		    ನಿಲ್ಲಿಸು;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    ಆದರೆ (s1->do_debug) {
	ಪೂರ್ಣಾಂಕ k;
	ರಚನೆ syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	ಪೂರ್ಣಾಂಕ i;
	Elf32_Sym *p;
	ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
	ಪೂರ್ಣಾಂಕ nstr;
	ಪೂರ್ಣಾಂಕ n = 0;

	Coff_str_ಕೋಷ್ಟಕ = (ಅಕ್ಷರ *) tcc_malloc(MAX_STR_ಕೋಷ್ಟಕ);
	p_Coff_str_ಕೋಷ್ಟಕ = Coff_str_ಕೋಷ್ಟಕ;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->ದತ್ತಾಂಶ;


	ಗಾಗಿ (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->ದತ್ತಾಂಶ + p->st_name;

	    ಗಾಗಿ (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    ಆದರೆ (ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } ಇಲ್ಲದಿದ್ದರೆ {
		ಆದರೆ (p_Coff_str_ಕೋಷ್ಟಕ - Coff_str_ಕೋಷ್ಟಕ + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) >
		    MAX_STR_ಕೋಷ್ಟಕ - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_ಸ್ಥಾನಾಂತರ =
		    p_Coff_str_ಕೋಷ್ಟಕ - Coff_str_ಕೋಷ್ಟಕ + 4;

		strcpy(p_Coff_str_ಕೋಷ್ಟಕ, name);
		p_Coff_str_ಕೋಷ್ಟಕ += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 1;	// skip over null
		nstr++;
	    }

	    ಆದರೆ (p->st_info == 4) {
		// put a filename symbol
		csym.n_ಮೌಲ್ಯ = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (p->st_info == 0x12) {
		// find the function data

		ಗಾಗಿ (k = 0; k < nFuncs; k++) {
		    ಆದರೆ (strcmp(name, Func[k]) == 0)
			ನಿಲ್ಲಿಸು;
		}

		ಆದರೆ (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_ಮೌಲ್ಯ = p->st_ಮೌಲ್ಯ;	// physical address
		csym.n_scnum = Coff_ಪಠ್ಯ_Section_No;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.ಟ್ಯಾಗ್ = 0;
		auxfunc.ಗಾತ್ರ_2 = ಕೊನೆ_ವಿಳಾಸ[k] - p->st_ಮೌಲ್ಯ;
		auxfunc.fileptr = ಸಾಲು_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_ಮೌಲ್ಯ = p->st_ಮೌಲ್ಯ;	// physical address
		csym.n_scnum = Coff_ಪಠ್ಯ_Section_No;
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
		csym.n_ಮೌಲ್ಯ = ಕೊನೆ_ವಿಳಾಸ[k];	// physical address  
		csym.n_scnum = Coff_ಪಠ್ಯ_Section_No;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = ಕೊನೆಯ_ಸಾಲು_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } ಇಲ್ಲದಿದ್ದರೆ {
		// try an put some type info

		ಆದರೆ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} ಇಲ್ಲದಿದ್ದರೆ {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_ಮೌಲ್ಯ = p->st_ಮೌಲ್ಯ;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.ಟ್ಯಾಗ್ = 0;
		auxfunc.ಗಾತ್ರ_2 = 0x20;
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

    ಆದರೆ (s1->do_debug) {
	// write string table

	// first write the size
	i = p_Coff_str_ಕೋಷ್ಟಕ - Coff_str_ಕೋಷ್ಟಕ;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_ಕೋಷ್ಟಕ, i, 1, f);

	tcc_free(Coff_str_ಕೋಷ್ಟಕ);
    }

    ಹಿಂತಿರುಗಿ 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

ಶೂನ್ಯ ವಿಂಗಡಿಸು_ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_ಕೋಷ್ಟಕ;
    ಅಕ್ಷರ *name, *name2;

    New_ಕೋಷ್ಟಕ = (Elf32_Sym *) tcc_malloc(nb_syms * ಗಾತ್ರ(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->ದತ್ತಾಂಶ;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    ಗಾಗಿ (i = 0; i < nb_syms; i++) {
	ಆದರೆ (p->st_info == 4) {
	    name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + p->st_name;

	    // this is a file symbol, copy it over

	    New_ಕೋಷ್ಟಕ[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->ದತ್ತಾಂಶ;

	    ಗಾಗಿ (j = 0; j < nb_syms; j++) {
		ಆದರೆ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + p2->st_name;

		    // find the function data index

		    ಗಾಗಿ (k = 0; k < nFuncs; k++) {
			ಆದರೆ (strcmp(name2, Func[k]) == 0)
			    ನಿಲ್ಲಿಸು;
		    }

		    ಆದರೆ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    ಆದರೆ (strcmp(AssociatedFile[k], name) == 0) {
			// yes they match copy it over

			New_ಕೋಷ್ಟಕ[n++] = *p2;
		    }
		}
		p2++;
	    }
	}
	p++;
    }

    // now all the filename and func symbols should have been copied over
    // copy all the rest over (all except file and funcs)

    p = (Elf32_Sym *) symtab_section->ದತ್ತಾಂಶ;
    ಗಾಗಿ (i = 0; i < nb_syms; i++) {
	ಆದರೆ (p->st_info != 4 && p->st_info != 0x12) {
	    New_ಕೋಷ್ಟಕ[n++] = *p;
	}
	p++;
    }

    ಆದರೆ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->ದತ್ತಾಂಶ;
    ಗಾಗಿ (i = 0; i < nb_syms; i++) {
	*p++ = New_ಕೋಷ್ಟಕ[i];
    }

    tcc_free(New_ಕೋಷ್ಟಕ);
}


ಪೂರ್ಣಾಂಕ ಕಂಡುಹಿಡಿ_Coff_ಚಿಹ್ನೆ_ಸೂಚ್ಯಂಕ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *func_name)
{
    ಪೂರ್ಣಾಂಕ i, n = 0;
    Elf32_Sym *p;
    ಅಕ್ಷರ *name;

    p = (Elf32_Sym *) symtab_section->ದತ್ತಾಂಶ;

    ಗಾಗಿ (i = 0; i < nb_syms; i++) {

	name = (ಅಕ್ಷರ *) symtab_section->link->ದತ್ತಾಂಶ + p->st_name;

	ಆದರೆ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (p->st_info == 0x12) {

	    ಆದರೆ (strcmp(func_name, name) == 0)
		ಹಿಂತಿರುಗಿ n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} ಇಲ್ಲದಿದ್ದರೆ {
	    n += 2;
	}

	p++;
    }

    ಹಿಂತಿರುಗಿ n;			// total number of symbols
}

ಪೂರ್ಣಾಂಕ OutputTheSection(Section * sect)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s = sect->name;

    ಆದರೆ (!strcmp(s, ".text"))
	ಹಿಂತಿರುಗಿ 1;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(s, ".data"))
	ಹಿಂತಿರುಗಿ 1;
    ಇಲ್ಲದಿದ್ದರೆ
	ಹಿಂತಿರುಗಿ 0;
}

ಗಿಡ್ಡ ಪೂರ್ಣಾಂಕ GetCoffFlags(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಆದರೆ (!strcmp(s, ".text"))
	ಹಿಂತಿರುಗಿ STYP_ಪಠ್ಯ | STYP_ದತ್ತಾಂಶ | STYP_ALIGN | 0x400;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(s, ".data"))
	ಹಿಂತಿರುಗಿ STYP_ದತ್ತಾಂಶ;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(s, ".bss"))
	ಹಿಂತಿರುಗಿ STYP_BSS;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(s, ".stack"))
	ಹಿಂತಿರುಗಿ STYP_BSS | STYP_ALIGN | 0x200;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(s, ".cinit"))
	ಹಿಂತಿರುಗಿ STYP_COPY | STYP_ದತ್ತಾಂಶ | STYP_ALIGN | 0x200;
    ಇಲ್ಲದಿದ್ದರೆ
	ಹಿಂತಿರುಗಿ 0;
}

Section *ಕಂಡುಹಿಡಿ_Section(TCCState * s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sname)
{
    Section *s;
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	ಆದರೆ (!strcmp(sname, s->name))
	    ಹಿಂತಿರುಗಿ s;
    }

    tcc_error("could not find section %s", sname);
    ಹಿಂತಿರುಗಿ 0;
}

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_coff(TCCState * s1, ಪೂರ್ಣಾಂಕ fd)
{
// tktk TokenSym *ts;

    FILE *f;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ str_ಗಾತ್ರ;
    ಅಕ್ಷರ *Coff_str_ಕೋಷ್ಟಕ, *name;
    ಪೂರ್ಣಾಂಕ i, k;
    ರಚನೆ syment csym;
    ಅಕ್ಷರ name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    ಆದರೆ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    ಆದರೆ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    ಆದರೆ (fread(&o_filehdr, ಗಾತ್ರ(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    ಆದರೆ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    ಆದರೆ (fread(&str_ಗಾತ್ರ, ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_ಕೋಷ್ಟಕ = (ಅಕ್ಷರ *) tcc_malloc(str_ಗಾತ್ರ);

    ಆದರೆ (fread(Coff_str_ಕೋಷ್ಟಕ, str_ಗಾತ್ರ - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    ಆದರೆ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    ಗಾಗಿ (i = 0; i < file_hdr.f_nsyms; i++) {
	ಆದರೆ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	ಆದರೆ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_ಕೋಷ್ಟಕ + csym._n._n_n.n_ಸ್ಥಾನಾಂತರ - 4;
	} ಇಲ್ಲದಿದ್ದರೆ {
	    name = csym._n._n_name;

	    ಆದರೆ (name[7] != 0) {
		ಗಾಗಿ (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	ಆದರೆ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    ಆದರೆ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s1, name, (ಶೂನ್ಯ*)(uintptr_t)csym.n_ಮೌಲ್ಯ);
	}
	// skip any aux records

	ಆದರೆ (csym.n_numaux == 1) {
	    ಆದರೆ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    ಹಿಂತಿರುಗಿ 0;
}
