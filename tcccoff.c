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

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _tcc_error

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_STR_ਸਾਰਣੀ 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_ਸਿਰਲੇਖ[MAXNSCNS];

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_FUNCS 1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_FUNC_NAME_ਲੰਮਾਈ 128

ਪੂਰਨ nFuncs;
ਅੱਖਰ Func[MAX_FUNCS][MAX_FUNC_NAME_ਲੰਮਾਈ];
ਅੱਖਰ AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_ਲੰਮਾਈ];
ਪੂਰਨ ਸਤਰ_No_File_Ptr[MAX_FUNCS];
ਪੂਰਨ ਸਿਰਾ_ਪਤਾ[MAX_FUNCS];
ਪੂਰਨ ਆਖਰੀ_ਸਤਰ_No[MAX_FUNCS];
ਪੂਰਨ FuncEntries[MAX_FUNCS];

ਪੂਰਨ OutputTheSection(Section * sect);
ਛੋਟਾ ਪੂਰਨ GetCoffFlags(ਅਚਲ ਅੱਖਰ *s);
ਖਾਲੀ ਛਾਂਟੋ_ਚਿੰਨ੍ਹ_ਸਾਰਣੀ(TCCState *s1);
Section *ਲੱਭੋ_Section(TCCState * s1, ਅਚਲ ਅੱਖਰ *sname);

ਪੂਰਨ C67_main_ਇੰਦਰਾਜ_ਬਿੰਦੂ;

ਪੂਰਨ ਲੱਭੋ_Coff_ਚਿੰਨ੍ਹ_ਸੂਚਕਾਂਕ(TCCState * s1, ਅਚਲ ਅੱਖਰ *func_name);
ਪੂਰਨ nb_syms;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਲੰਮਾ ਟੈਗ;
    ਲੰਮਾ ਮਾਪ;
    ਲੰਮਾ fileptr;
    ਲੰਮਾ nextsym;
    ਛੋਟਾ ਪੂਰਨ dummy;
} AUXFUNC;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਲੰਮਾ regmask;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ lineno;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ nentries;
    ਪੂਰਨ localframe;
    ਪੂਰਨ nextentry;
    ਛੋਟਾ ਪੂਰਨ dummy;
} AUXBF;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਲੰਮਾ dummy;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ lineno;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ dummy1;
    ਪੂਰਨ dummy2;
    ਪੂਰਨ dummy3;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ dummy4;
} AUXEF;

ST_FUNC ਪੂਰਨ tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    ਪੂਰਨ file_ਸੂਚਕ;
    ਅੱਖਰ *Coff_str_ਸਾਰਣੀ, *p_Coff_str_ਸਾਰਣੀ;
    ਪੂਰਨ Coff_ਪਾਠ_Section_No, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    ਪੂਰਨ i, NSections_ਮੰਜ਼ਿਲ_Output = 0;

    Coff_str_ਸਾਰਣੀ = p_Coff_str_ਸਾਰਣੀ = ਨਿਰਾ;

    stext = ਲੱਭੋ_Section(s1, ".text");
    sdata = ਲੱਭੋ_Section(s1, ".data");
    sbss = ਲੱਭੋ_Section(s1, ".bss");

    nb_syms = symtab_section->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ(Elf32_Sym);
    coff_nb_syms = ਲੱਭੋ_Coff_ਚਿੰਨ੍ਹ_ਸੂਚਕਾਂਕ(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = ਆਕਾਰ(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_ਨਿਸ਼ਾਨਾ_ID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->ਅੰਕੜੇ_ਵਿੱਥ;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->ਅੰਕੜੇ_ਵਿੱਥ;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->ਅੰਕੜੇ_ਵਿੱਥ;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_ਇੰਦਰਾਜ_ਬਿੰਦੂ;	/* entry pt.                          */
    o_filehdr.ਪਾਠ_ਸ਼ੁਰੂ = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.ਅੰਕੜੇ_ਸ਼ੁਰੂ = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_ਸੂਚਕ = FILHSZ + ਆਕਾਰ(AOUTHDR);

    Coff_ਪਾਠ_Section_No = -1;

    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (OutputTheSection(tcc_sect)) {
	    NSections_ਮੰਜ਼ਿਲ_Output++;

	    ਜੇ (Coff_ਪਾਠ_Section_No == -1 && tcc_sect == stext)
		Coff_ਪਾਠ_Section_No = NSections_ਮੰਜ਼ਿਲ_Output;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_ਮਾਪ = tcc_sect->ਅੰਕੜੇ_ਵਿੱਥ;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_ਪੰਨਾ = 0;	/* memory page id */

	    file_ਸੂਚਕ += ਆਕਾਰ(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSections_ਮੰਜ਼ਿਲ_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_ਸੂਚਕ;	/* file ptr to raw data for section */
	    file_ਸੂਚਕ += coff_sec->s_ਮਾਪ;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ਜੇ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_ਸੂਚਕ;	/* file ptr to relocation */
		file_ਸੂਚਕ += coff_sec->s_nreloc * ਆਕਾਰ(ਬਣਤਰ reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	ਜੇ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_ਸਿਰਾ;
	    ਅੱਖਰ func_name[MAX_FUNC_NAME_ਲੰਮਾਈ],
		ਆਖਰੀ_func_name[MAX_FUNC_NAME_ਲੰਮਾਈ];
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_addr, ਆਖਰੀ_pc, pc;
	    ਅਚਲ ਅੱਖਰ *incl_files[INCLUDE_ਢੇਰ_ਮਾਪ];
	    ਪੂਰਨ incl_ਸੂਚਕਾਂਕ, len, ਆਖਰੀ_ਸਤਰ_ਅੰਕ;
	    ਅਚਲ ਅੱਖਰ *str, *p;

	    coff_sec->s_lnnoptr = file_ਸੂਚਕ;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_ਸੂਚਕਾਂਕ = 0;
	    ਆਖਰੀ_func_name[0] = '\0';
	    ਆਖਰੀ_pc = 0xffffffff;
	    ਆਖਰੀ_ਸਤਰ_ਅੰਕ = 1;
	    sym = (Stab_Sym *) stab_section->ਅੰਕੜੇ + 1;
	    sym_ਸਿਰਾ =
		(Stab_Sym *) (stab_section->ਅੰਕੜੇ +
			      stab_section->ਅੰਕੜੇ_ਵਿੱਥ);

	    nFuncs = 0;
	    ਜਦੋਂ (sym < sym_ਸਿਰਾ) {
		ਚੋਣ (sym->n_type) {
		    /* function start or end */
		ਹਾਲਤ N_FUN:
		    ਜੇ (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_ਸੂਚਕ += LINESZ;

			pc = sym->n_ਮੁੱਲ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			ਸਿਰਾ_ਪਤਾ[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_ਸੂਚਕ -
			     ਸਤਰ_No_File_Ptr[nFuncs]) / LINESZ - 1;
			ਆਖਰੀ_ਸਤਰ_No[nFuncs++] = ਆਖਰੀ_ਸਤਰ_ਅੰਕ + 1;
		    } ਨਹੀਂਤਾਂ {
			// beginning of function

			ਸਤਰ_No_File_Ptr[nFuncs] = file_ਸੂਚਕ;
			coff_sec->s_nlnno++;
			file_ਸੂਚਕ += LINESZ;

			str =
			    (ਅਚਲ ਅੱਖਰ *) stabstr_section->ਅੰਕੜੇ +
			    sym->n_strx;

			p = strchr(str, ':');
			ਜੇ (!p) {
			    pstrcpy(func_name, ਆਕਾਰ(func_name), str);
			    pstrcpy(Func[nFuncs], ਆਕਾਰ(func_name), str);
			} ਨਹੀਂਤਾਂ {
			    len = p - str;
			    ਜੇ (len > ਆਕਾਰ(func_name) - 1)
				len = ਆਕਾਰ(func_name) - 1;
			    ਸਮ੍ਰਿਤੀ_ਨਕਲ(func_name, str, len);
			    ਸਮ੍ਰਿਤੀ_ਨਕਲ(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], ਆਕਾਰ(func_name),
				incl_files[incl_ਸੂਚਕਾਂਕ - 1]);

			func_addr = sym->n_ਮੁੱਲ;
		    }
		    ਰੋਕੋ;

		    /* line number info */
		ਹਾਲਤ N_SLINE:
		    pc = sym->n_ਮੁੱਲ + func_addr;

		    ਆਖਰੀ_pc = pc;
		    ਆਖਰੀ_ਸਤਰ_ਅੰਕ = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(ਆਖਰੀ_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_ਸੂਚਕ += LINESZ;
		    ਰੋਕੋ;
		    /* include files */
		ਹਾਲਤ N_BINCL:
		    str =
			(ਅਚਲ ਅੱਖਰ *) stabstr_section->ਅੰਕੜੇ + sym->n_strx;
		  ਜੋੜੋ_incl:
		    ਜੇ (incl_ਸੂਚਕਾਂਕ < INCLUDE_ਢੇਰ_ਮਾਪ) {
			incl_files[incl_ਸੂਚਕਾਂਕ++] = str;
		    }
		    ਰੋਕੋ;
		ਹਾਲਤ N_EINCL:
		    ਜੇ (incl_ਸੂਚਕਾਂਕ > 1)
			incl_ਸੂਚਕਾਂਕ--;
		    ਰੋਕੋ;
		ਹਾਲਤ N_SO:
		    ਜੇ (sym->n_strx == 0) {
			incl_ਸੂਚਕਾਂਕ = 0;	/* end of translation unit */
		    } ਨਹੀਂਤਾਂ {
			str =
			    (ਅਚਲ ਅੱਖਰ *) stabstr_section->ਅੰਕੜੇ +
			    sym->n_strx;
			/* do not add path */
			len = ਲੜੀ_ਲੰਬਾਈ(str);
			ਜੇ (len > 0 && str[len - 1] != '/')
			    ਜਾਓ ਜੋੜੋ_incl;
		    }
		    ਰੋਕੋ;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_ਸੂਚਕ;	/* file pointer to symtab */

    ਜੇ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    ਨਹੀਂਤਾਂ
	file_hdr.f_nsyms = 0;

    file_ਸੂਚਕ += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, ਆਕਾਰ(o_filehdr), 1, f);

    // write section headers
    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, ਆਕਾਰ(SCNHDR), 1, f);
	}
    }

    // write raw data
    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->ਅੰਕੜੇ, tcc_sect->ਅੰਕੜੇ_ਵਿੱਥ, 1, f);
	}
    }

    // write relocation data
    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ਜੇ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * ਆਕਾਰ(ਬਣਤਰ reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    ਜੇ (s1->do_debug)
	ਛਾਂਟੋ_ਚਿੰਨ੍ਹ_ਸਾਰਣੀ(s1);

    // write line no data

    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_ਸਿਰਲੇਖ[i];
	tcc_sect = s1->sections[i];

	ਜੇ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_ਸਿਰਾ;
	    ਅੱਖਰ func_name[128], ਆਖਰੀ_func_name[128];
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ func_addr, ਆਖਰੀ_pc, pc;
	    ਅਚਲ ਅੱਖਰ *incl_files[INCLUDE_ਢੇਰ_ਮਾਪ];
	    ਪੂਰਨ incl_ਸੂਚਕਾਂਕ, len, ਆਖਰੀ_ਸਤਰ_ਅੰਕ;
	    ਅਚਲ ਅੱਖਰ *str, *p;

	    LINENO Coff_ਸਤਰ_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_ਸੂਚਕਾਂਕ = 0;
	    ਆਖਰੀ_func_name[0] = '\0';
	    ਆਖਰੀ_pc = 0;
	    ਆਖਰੀ_ਸਤਰ_ਅੰਕ = 1;
	    sym = (Stab_Sym *) stab_section->ਅੰਕੜੇ + 1;
	    sym_ਸਿਰਾ =
		(Stab_Sym *) (stab_section->ਅੰਕੜੇ +
			      stab_section->ਅੰਕੜੇ_ਵਿੱਥ);

	    ਜਦੋਂ (sym < sym_ਸਿਰਾ) {
		ਚੋਣ (sym->n_type) {
		    /* function start or end */
		ਹਾਲਤ N_FUN:
		    ਜੇ (sym->n_strx == 0) {
			// end of function

			Coff_ਸਤਰ_No.l_addr.l_paddr = ਆਖਰੀ_pc;
			Coff_ਸਤਰ_No.l_lnno = ਆਖਰੀ_ਸਤਰ_ਅੰਕ + 1;
			fwrite(&Coff_ਸਤਰ_No, 6, 1, f);

			pc = sym->n_ਮੁੱਲ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } ਨਹੀਂਤਾਂ {
			// beginning of function

			str =
			    (ਅਚਲ ਅੱਖਰ *) stabstr_section->ਅੰਕੜੇ +
			    sym->n_strx;


			p = strchr(str, ':');
			ਜੇ (!p) {
			    pstrcpy(func_name, ਆਕਾਰ(func_name), str);
			} ਨਹੀਂਤਾਂ {
			    len = p - str;
			    ਜੇ (len > ਆਕਾਰ(func_name) - 1)
				len = ਆਕਾਰ(func_name) - 1;
			    ਸਮ੍ਰਿਤੀ_ਨਕਲ(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_ਮੁੱਲ;
			ਆਖਰੀ_pc = func_addr;
			ਆਖਰੀ_ਸਤਰ_ਅੰਕ = -1;

			// output a function begin

			Coff_ਸਤਰ_No.l_addr.l_symndx =
			    ਲੱਭੋ_Coff_ਚਿੰਨ੍ਹ_ਸੂਚਕਾਂਕ(s1, func_name);
			Coff_ਸਤਰ_No.l_lnno = 0;

			fwrite(&Coff_ਸਤਰ_No, 6, 1, f);
		    }
		    ਰੋਕੋ;

		    /* line number info */
		ਹਾਲਤ N_SLINE:
		    pc = sym->n_ਮੁੱਲ + func_addr;


		    /* XXX: slow! */
		    strcpy(ਆਖਰੀ_func_name, func_name);

		    // output a line reference

		    Coff_ਸਤਰ_No.l_addr.l_paddr = ਆਖਰੀ_pc;

		    ਜੇ (ਆਖਰੀ_ਸਤਰ_ਅੰਕ == -1) {
			Coff_ਸਤਰ_No.l_lnno = sym->n_desc;
		    } ਨਹੀਂਤਾਂ {
			Coff_ਸਤਰ_No.l_lnno = ਆਖਰੀ_ਸਤਰ_ਅੰਕ + 1;
		    }

		    fwrite(&Coff_ਸਤਰ_No, 6, 1, f);

		    ਆਖਰੀ_pc = pc;
		    ਆਖਰੀ_ਸਤਰ_ਅੰਕ = sym->n_desc;

		    ਰੋਕੋ;

		    /* include files */
		ਹਾਲਤ N_BINCL:
		    str =
			(ਅਚਲ ਅੱਖਰ *) stabstr_section->ਅੰਕੜੇ + sym->n_strx;
		  ਜੋੜੋ_incl2:
		    ਜੇ (incl_ਸੂਚਕਾਂਕ < INCLUDE_ਢੇਰ_ਮਾਪ) {
			incl_files[incl_ਸੂਚਕਾਂਕ++] = str;
		    }
		    ਰੋਕੋ;
		ਹਾਲਤ N_EINCL:
		    ਜੇ (incl_ਸੂਚਕਾਂਕ > 1)
			incl_ਸੂਚਕਾਂਕ--;
		    ਰੋਕੋ;
		ਹਾਲਤ N_SO:
		    ਜੇ (sym->n_strx == 0) {
			incl_ਸੂਚਕਾਂਕ = 0;	/* end of translation unit */
		    } ਨਹੀਂਤਾਂ {
			str =
			    (ਅਚਲ ਅੱਖਰ *) stabstr_section->ਅੰਕੜੇ +
			    sym->n_strx;
			/* do not add path */
			len = ਲੜੀ_ਲੰਬਾਈ(str);
			ਜੇ (len > 0 && str[len - 1] != '/')
			    ਜਾਓ ਜੋੜੋ_incl2;
		    }
		    ਰੋਕੋ;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    ਜੇ (s1->do_debug) {
	ਪੂਰਨ k;
	ਬਣਤਰ syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	ਪੂਰਨ i;
	Elf32_Sym *p;
	ਅਚਲ ਅੱਖਰ *name;
	ਪੂਰਨ nstr;
	ਪੂਰਨ n = 0;

	Coff_str_ਸਾਰਣੀ = (ਅੱਖਰ *) tcc_malloc(MAX_STR_ਸਾਰਣੀ);
	p_Coff_str_ਸਾਰਣੀ = Coff_str_ਸਾਰਣੀ;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->ਅੰਕੜੇ;


	ਲਈ (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->ਅੰਕੜੇ + p->st_name;

	    ਲਈ (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    ਜੇ (ਲੜੀ_ਲੰਬਾਈ(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } ਨਹੀਂਤਾਂ {
		ਜੇ (p_Coff_str_ਸਾਰਣੀ - Coff_str_ਸਾਰਣੀ + ਲੜੀ_ਲੰਬਾਈ(name) >
		    MAX_STR_ਸਾਰਣੀ - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_ਵਿੱਥ =
		    p_Coff_str_ਸਾਰਣੀ - Coff_str_ਸਾਰਣੀ + 4;

		strcpy(p_Coff_str_ਸਾਰਣੀ, name);
		p_Coff_str_ਸਾਰਣੀ += ਲੜੀ_ਲੰਬਾਈ(name) + 1;	// skip over null
		nstr++;
	    }

	    ਜੇ (p->st_info == 4) {
		// put a filename symbol
		csym.n_ਮੁੱਲ = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } ਨਹੀਂਤਾਂ ਜੇ (p->st_info == 0x12) {
		// find the function data

		ਲਈ (k = 0; k < nFuncs; k++) {
		    ਜੇ (strcmp(name, Func[k]) == 0)
			ਰੋਕੋ;
		}

		ਜੇ (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_ਮੁੱਲ = p->st_ਮੁੱਲ;	// physical address
		csym.n_scnum = Coff_ਪਾਠ_Section_No;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.ਟੈਗ = 0;
		auxfunc.ਮਾਪ = ਸਿਰਾ_ਪਤਾ[k] - p->st_ਮੁੱਲ;
		auxfunc.fileptr = ਸਤਰ_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_ਮੁੱਲ = p->st_ਮੁੱਲ;	// physical address
		csym.n_scnum = Coff_ਪਾਠ_Section_No;
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
		csym.n_ਮੁੱਲ = ਸਿਰਾ_ਪਤਾ[k];	// physical address  
		csym.n_scnum = Coff_ਪਾਠ_Section_No;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = ਆਖਰੀ_ਸਤਰ_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } ਨਹੀਂਤਾਂ {
		// try an put some type info

		ਜੇ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} ਨਹੀਂਤਾਂ ਜੇ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} ਨਹੀਂਤਾਂ ਜੇ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} ਨਹੀਂਤਾਂ ਜੇ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} ਨਹੀਂਤਾਂ ਜੇ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} ਨਹੀਂਤਾਂ {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_ਮੁੱਲ = p->st_ਮੁੱਲ;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.ਟੈਗ = 0;
		auxfunc.ਮਾਪ = 0x20;
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

    ਜੇ (s1->do_debug) {
	// write string table

	// first write the size
	i = p_Coff_str_ਸਾਰਣੀ - Coff_str_ਸਾਰਣੀ;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_ਸਾਰਣੀ, i, 1, f);

	tcc_free(Coff_str_ਸਾਰਣੀ);
    }

    ਵਾਪਸ 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

ਖਾਲੀ ਛਾਂਟੋ_ਚਿੰਨ੍ਹ_ਸਾਰਣੀ(TCCState *s1)
{
    ਪੂਰਨ i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_ਸਾਰਣੀ;
    ਅੱਖਰ *name, *name2;

    New_ਸਾਰਣੀ = (Elf32_Sym *) tcc_malloc(nb_syms * ਆਕਾਰ(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->ਅੰਕੜੇ;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    ਲਈ (i = 0; i < nb_syms; i++) {
	ਜੇ (p->st_info == 4) {
	    name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + p->st_name;

	    // this is a file symbol, copy it over

	    New_ਸਾਰਣੀ[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->ਅੰਕੜੇ;

	    ਲਈ (j = 0; j < nb_syms; j++) {
		ਜੇ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + p2->st_name;

		    // find the function data index

		    ਲਈ (k = 0; k < nFuncs; k++) {
			ਜੇ (strcmp(name2, Func[k]) == 0)
			    ਰੋਕੋ;
		    }

		    ਜੇ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    ਜੇ (strcmp(AssociatedFile[k], name) == 0) {
			// yes they match copy it over

			New_ਸਾਰਣੀ[n++] = *p2;
		    }
		}
		p2++;
	    }
	}
	p++;
    }

    // now all the filename and func symbols should have been copied over
    // copy all the rest over (all except file and funcs)

    p = (Elf32_Sym *) symtab_section->ਅੰਕੜੇ;
    ਲਈ (i = 0; i < nb_syms; i++) {
	ਜੇ (p->st_info != 4 && p->st_info != 0x12) {
	    New_ਸਾਰਣੀ[n++] = *p;
	}
	p++;
    }

    ਜੇ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->ਅੰਕੜੇ;
    ਲਈ (i = 0; i < nb_syms; i++) {
	*p++ = New_ਸਾਰਣੀ[i];
    }

    tcc_free(New_ਸਾਰਣੀ);
}


ਪੂਰਨ ਲੱਭੋ_Coff_ਚਿੰਨ੍ਹ_ਸੂਚਕਾਂਕ(TCCState *s1, ਅਚਲ ਅੱਖਰ *func_name)
{
    ਪੂਰਨ i, n = 0;
    Elf32_Sym *p;
    ਅੱਖਰ *name;

    p = (Elf32_Sym *) symtab_section->ਅੰਕੜੇ;

    ਲਈ (i = 0; i < nb_syms; i++) {

	name = (ਅੱਖਰ *) symtab_section->link->ਅੰਕੜੇ + p->st_name;

	ਜੇ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} ਨਹੀਂਤਾਂ ਜੇ (p->st_info == 0x12) {

	    ਜੇ (strcmp(func_name, name) == 0)
		ਵਾਪਸ n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} ਨਹੀਂਤਾਂ {
	    n += 2;
	}

	p++;
    }

    ਵਾਪਸ n;			// total number of symbols
}

ਪੂਰਨ OutputTheSection(Section * sect)
{
    ਅਚਲ ਅੱਖਰ *s = sect->name;

    ਜੇ (!strcmp(s, ".text"))
	ਵਾਪਸ 1;
    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(s, ".data"))
	ਵਾਪਸ 1;
    ਨਹੀਂਤਾਂ
	ਵਾਪਸ 0;
}

ਛੋਟਾ ਪੂਰਨ GetCoffFlags(ਅਚਲ ਅੱਖਰ *s)
{
    ਜੇ (!strcmp(s, ".text"))
	ਵਾਪਸ STYP_ਪਾਠ | STYP_ਅੰਕੜੇ | STYP_ALIGN | 0x400;
    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(s, ".data"))
	ਵਾਪਸ STYP_ਅੰਕੜੇ;
    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(s, ".bss"))
	ਵਾਪਸ STYP_BSS;
    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(s, ".stack"))
	ਵਾਪਸ STYP_BSS | STYP_ALIGN | 0x200;
    ਨਹੀਂਤਾਂ ਜੇ (!strcmp(s, ".cinit"))
	ਵਾਪਸ STYP_COPY | STYP_ਅੰਕੜੇ | STYP_ALIGN | 0x200;
    ਨਹੀਂਤਾਂ
	ਵਾਪਸ 0;
}

Section *ਲੱਭੋ_Section(TCCState * s1, ਅਚਲ ਅੱਖਰ *sname)
{
    Section *s;
    ਪੂਰਨ i;

    ਲਈ (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	ਜੇ (!strcmp(sname, s->name))
	    ਵਾਪਸ s;
    }

    tcc_error("could not find section %s", sname);
    ਵਾਪਸ 0;
}

ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_coff(TCCState * s1, ਪੂਰਨ fd)
{
// tktk TokenSym *ts;

    FILE *f;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ str_ਮਾਪ;
    ਅੱਖਰ *Coff_str_ਸਾਰਣੀ, *name;
    ਪੂਰਨ i, k;
    ਬਣਤਰ syment csym;
    ਅੱਖਰ name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    ਜੇ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    ਜੇ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    ਜੇ (fread(&o_filehdr, ਆਕਾਰ(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    ਜੇ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    ਜੇ (fread(&str_ਮਾਪ, ਆਕਾਰ(ਪੂਰਨ), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_ਸਾਰਣੀ = (ਅੱਖਰ *) tcc_malloc(str_ਮਾਪ);

    ਜੇ (fread(Coff_str_ਸਾਰਣੀ, str_ਮਾਪ - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    ਜੇ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    ਲਈ (i = 0; i < file_hdr.f_nsyms; i++) {
	ਜੇ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	ਜੇ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_ਸਾਰਣੀ + csym._n._n_n.n_ਵਿੱਥ - 4;
	} ਨਹੀਂਤਾਂ {
	    name = csym._n._n_name;

	    ਜੇ (name[7] != 0) {
		ਲਈ (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	ਜੇ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    ਜੇ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s1, name, (ਖਾਲੀ*)(uintptr_t)csym.n_ਮੁੱਲ);
	}
	// skip any aux records

	ਜੇ (csym.n_numaux == 1) {
	    ਜੇ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    ਵਾਪਸ 0;
}
