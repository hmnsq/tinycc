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

#అన్తర్భావ "tcc.h"

/* XXX: this file uses tcc_error() to the effect of exit(1) */
#నిర్వచనం_రద్దు _tcc_error

#నిర్వచించు MAXNSCNS 255		/* MAXIMUM NUMBER OF SECTIONS         */
#నిర్వచించు MAX_STR_పట్టిక 1000000
AOUTHDR o_filehdr;		/* OPTIONAL (A.OUT) FILE HEADER       */

SCNHDR section_శీర్షిక[MAXNSCNS];

#నిర్వచించు MAX_FUNCS 1000
#నిర్వచించు MAX_FUNC_NAME_నిడివి 128

పూర్ణాంకం nFuncs;
అక్షరం Func[MAX_FUNCS][MAX_FUNC_NAME_నిడివి];
అక్షరం AssociatedFile[MAX_FUNCS][MAX_FUNC_NAME_నిడివి];
పూర్ణాంకం పంక్తి_No_File_Ptr[MAX_FUNCS];
పూర్ణాంకం చివర_చిరునామా[MAX_FUNCS];
పూర్ణాంకం చివరి_పంక్తి_No[MAX_FUNCS];
పూర్ణాంకం FuncEntries[MAX_FUNCS];

పూర్ణాంకం OutputTheSection(Section * sect);
పొట్టి పూర్ణాంకం GetCoffFlags(స్థిరరాశి అక్షరం *s);
శూన్య క్రమీకరించు_చిహ్నం_పట్టిక(TCCState *s1);
Section *కనుగొను_Section(TCCState * s1, స్థిరరాశి అక్షరం *sname);

పూర్ణాంకం C67_main_నమోదు_బిందువు;

పూర్ణాంకం కనుగొను_Coff_చిహ్నం_సూచీ(TCCState * s1, స్థిరరాశి అక్షరం *func_name);
పూర్ణాంకం nb_syms;

రకనిర్వచనం నిర్మాణం {
    దీర్ఘ ట్యాగ్;
    దీర్ఘ కొలత;
    దీర్ఘ fileptr;
    దీర్ఘ nextsym;
    పొట్టి పూర్ణాంకం dummy;
} AUXFUNC;

రకనిర్వచనం నిర్మాణం {
    దీర్ఘ regmask;
    గుర్తులేని పొట్టి lineno;
    గుర్తులేని పొట్టి nentries;
    పూర్ణాంకం localframe;
    పూర్ణాంకం nextentry;
    పొట్టి పూర్ణాంకం dummy;
} AUXBF;

రకనిర్వచనం నిర్మాణం {
    దీర్ఘ dummy;
    గుర్తులేని పొట్టి lineno;
    గుర్తులేని పొట్టి dummy1;
    పూర్ణాంకం dummy2;
    పూర్ణాంకం dummy3;
    గుర్తులేని పొట్టి dummy4;
} AUXEF;

ST_FUNC పూర్ణాంకం tcc_output_coff(TCCState *s1, FILE *f)
{
    Section *tcc_sect;
    SCNHDR *coff_sec;
    పూర్ణాంకం file_సూచిక;
    అక్షరం *Coff_str_పట్టిక, *p_Coff_str_పట్టిక;
    పూర్ణాంకం Coff_పాఠ్యం_Section_No, coff_nb_syms;
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */
    Section *stext, *sdata, *sbss;
    పూర్ణాంకం i, NSections_గమ్యం_Output = 0;

    Coff_str_పట్టిక = p_Coff_str_పట్టిక = ఖాళీ;

    stext = కనుగొను_Section(s1, ".text");
    sdata = కనుగొను_Section(s1, ".data");
    sbss = కనుగొను_Section(s1, ".bss");

    nb_syms = symtab_section->దత్తాంశం_స్థానభ్రంశం / పరిమాణం(Elf32_Sym);
    coff_nb_syms = కనుగొను_Coff_చిహ్నం_సూచీ(s1, "XXXXXXXXXX1");

    file_hdr.f_magic = COFF_C67_MAGIC;	/* magic number */
    file_hdr.f_timdat = 0;	/* time & date stamp */
    file_hdr.f_opthdr = పరిమాణం(AOUTHDR);	/* sizeof(optional hdr) */
    file_hdr.f_flags = 0x1143;	/* flags (copied from what code composer does) */
    file_hdr.f_లక్ష్యం_ID = 0x99;	/* for C6x = 0x0099 */

    o_filehdr.magic = 0x0108;	/* see magic.h                          */
    o_filehdr.vstamp = 0x0190;	/* version stamp                        */
    o_filehdr.tsize = stext->దత్తాంశం_స్థానభ్రంశం;	/* text size in bytes, padded to FW bdry */
    o_filehdr.dsize = sdata->దత్తాంశం_స్థానభ్రంశం;	/* initialized data "  "                */
    o_filehdr.bsize = sbss->దత్తాంశం_స్థానభ్రంశం;	/* uninitialized data "   "             */
    o_filehdr.entrypt = C67_main_నమోదు_బిందువు;	/* entry pt.                          */
    o_filehdr.పాఠ్యం_ప్రారంభం = stext->sh_addr;	/* base of text used for this file      */
    o_filehdr.దత్తాంశం_ప్రారంభం = sdata->sh_addr;	/* base of data used for this file      */


    // create all the section headers

    file_సూచిక = FILHSZ + పరిమాణం(AOUTHDR);

    Coff_పాఠ్యం_Section_No = -1;

    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (OutputTheSection(tcc_sect)) {
	    NSections_గమ్యం_Output++;

	    ఒకవేళ (Coff_పాఠ్యం_Section_No == -1 && tcc_sect == stext)
		Coff_పాఠ్యం_Section_No = NSections_గమ్యం_Output;	// rem which coff sect number the .text sect is

	    strcpy(coff_sec->s_name, tcc_sect->name);	/* section name */

	    coff_sec->s_paddr = tcc_sect->sh_addr;	/* physical address */
	    coff_sec->s_vaddr = tcc_sect->sh_addr;	/* virtual address */
	    coff_sec->s_కొలత = tcc_sect->దత్తాంశం_స్థానభ్రంశం;	/* section size */
	    coff_sec->s_scnptr = 0;	/* file ptr to raw data for section */
	    coff_sec->s_relptr = 0;	/* file ptr to relocation */
	    coff_sec->s_lnnoptr = 0;	/* file ptr to line numbers */
	    coff_sec->s_nreloc = 0;	/* number of relocation entries */
	    coff_sec->s_flags = GetCoffFlags(coff_sec->s_name);	/* flags */
	    coff_sec->s_reserved = 0;	/* reserved byte */
	    coff_sec->s_పుట = 0;	/* memory page id */

	    file_సూచిక += పరిమాణం(SCNHDR);
	}
    }

    file_hdr.f_nscns = NSections_గమ్యం_Output;	/* number of sections */

    // now loop through and determine file pointer locations
    // for the raw data


    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (OutputTheSection(tcc_sect)) {
	    // put raw data
	    coff_sec->s_scnptr = file_సూచిక;	/* file ptr to raw data for section */
	    file_సూచిక += coff_sec->s_కొలత;
	}
    }

    // now loop through and determine file pointer locations
    // for the relocation data

    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ఒకవేళ (coff_sec->s_nreloc > 0) {
		coff_sec->s_relptr = file_సూచిక;	/* file ptr to relocation */
		file_సూచిక += coff_sec->s_nreloc * పరిమాణం(నిర్మాణం reloc);
	    }
	}
    }

    // now loop through and determine file pointer locations
    // for the line number data

    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	coff_sec->s_nlnno = 0;
	coff_sec->s_lnnoptr = 0;

	ఒకవేళ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data

	    // also find association between source file name and function
	    // so we can sort the symbol table


	    Stab_Sym *sym, *sym_చివర;
	    అక్షరం func_name[MAX_FUNC_NAME_నిడివి],
		చివరి_func_name[MAX_FUNC_NAME_నిడివి];
	    గుర్తులేని దీర్ఘ func_addr, చివరి_pc, pc;
	    స్థిరరాశి అక్షరం *incl_files[INCLUDE_దొంతర_కొలత];
	    పూర్ణాంకం incl_సూచీ, len, చివరి_పంక్తి_అంకె;
	    స్థిరరాశి అక్షరం *str, *p;

	    coff_sec->s_lnnoptr = file_సూచిక;	/* file ptr to linno */


	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_సూచీ = 0;
	    చివరి_func_name[0] = '\0';
	    చివరి_pc = 0xffffffff;
	    చివరి_పంక్తి_అంకె = 1;
	    sym = (Stab_Sym *) stab_section->దత్తాంశం + 1;
	    sym_చివర =
		(Stab_Sym *) (stab_section->దత్తాంశం +
			      stab_section->దత్తాంశం_స్థానభ్రంశం);

	    nFuncs = 0;
	    అయితే (sym < sym_చివర) {
		ఎంపిక (sym->n_type) {
		    /* function start or end */
		స్థితి N_FUN:
		    ఒకవేళ (sym->n_strx == 0) {
			// end of function

			coff_sec->s_nlnno++;
			file_సూచిక += LINESZ;

			pc = sym->n_విలువ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
			చివర_చిరునామా[nFuncs] = pc;
			FuncEntries[nFuncs] =
			    (file_సూచిక -
			     పంక్తి_No_File_Ptr[nFuncs]) / LINESZ - 1;
			చివరి_పంక్తి_No[nFuncs++] = చివరి_పంక్తి_అంకె + 1;
		    } లేకపోతే {
			// beginning of function

			పంక్తి_No_File_Ptr[nFuncs] = file_సూచిక;
			coff_sec->s_nlnno++;
			file_సూచిక += LINESZ;

			str =
			    (స్థిరరాశి అక్షరం *) stabstr_section->దత్తాంశం +
			    sym->n_strx;

			p = strchr(str, ':');
			ఒకవేళ (!p) {
			    pstrcpy(func_name, పరిమాణం(func_name), str);
			    pstrcpy(Func[nFuncs], పరిమాణం(func_name), str);
			} లేకపోతే {
			    len = p - str;
			    ఒకవేళ (len > పరిమాణం(func_name) - 1)
				len = పరిమాణం(func_name) - 1;
			    జ్ఞాపకం_నకలు(func_name, str, len);
			    జ్ఞాపకం_నకలు(Func[nFuncs], str, len);
			    func_name[len] = '\0';
			}

			// save the file that it came in so we can sort later
			pstrcpy(AssociatedFile[nFuncs], పరిమాణం(func_name),
				incl_files[incl_సూచీ - 1]);

			func_addr = sym->n_విలువ;
		    }
		    ఆపు;

		    /* line number info */
		స్థితి N_SLINE:
		    pc = sym->n_విలువ + func_addr;

		    చివరి_pc = pc;
		    చివరి_పంక్తి_అంకె = sym->n_desc;

		    /* XXX: slow! */
		    strcpy(చివరి_func_name, func_name);

		    coff_sec->s_nlnno++;
		    file_సూచిక += LINESZ;
		    ఆపు;
		    /* include files */
		స్థితి N_BINCL:
		    str =
			(స్థిరరాశి అక్షరం *) stabstr_section->దత్తాంశం + sym->n_strx;
		  కూడు_incl:
		    ఒకవేళ (incl_సూచీ < INCLUDE_దొంతర_కొలత) {
			incl_files[incl_సూచీ++] = str;
		    }
		    ఆపు;
		స్థితి N_EINCL:
		    ఒకవేళ (incl_సూచీ > 1)
			incl_సూచీ--;
		    ఆపు;
		స్థితి N_SO:
		    ఒకవేళ (sym->n_strx == 0) {
			incl_సూచీ = 0;	/* end of translation unit */
		    } లేకపోతే {
			str =
			    (స్థిరరాశి అక్షరం *) stabstr_section->దత్తాంశం +
			    sym->n_strx;
			/* do not add path */
			len = అక్షరశ్రేణి_పొడవు(str);
			ఒకవేళ (len > 0 && str[len - 1] != '/')
			    వెళ్ళు కూడు_incl;
		    }
		    ఆపు;
		}
		sym++;
	    }
	}

    }

    file_hdr.f_symptr = file_సూచిక;	/* file pointer to symtab */

    ఒకవేళ (s1->do_debug)
	file_hdr.f_nsyms = coff_nb_syms;	/* number of symtab entries */
    లేకపోతే
	file_hdr.f_nsyms = 0;

    file_సూచిక += file_hdr.f_nsyms * SYMNMLEN;

    // OK now we are all set to write the file


    fwrite(&file_hdr, FILHSZ, 1, f);
    fwrite(&o_filehdr, పరిమాణం(o_filehdr), 1, f);

    // write section headers
    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (OutputTheSection(tcc_sect)) {
	    fwrite(coff_sec, పరిమాణం(SCNHDR), 1, f);
	}
    }

    // write raw data
    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (OutputTheSection(tcc_sect)) {
	    fwrite(tcc_sect->దత్తాంశం, tcc_sect->దత్తాంశం_స్థానభ్రంశం, 1, f);
	}
    }

    // write relocation data
    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (OutputTheSection(tcc_sect)) {
	    // put relocations data
	    ఒకవేళ (coff_sec->s_nreloc > 0) {
		fwrite(tcc_sect->reloc,
		       coff_sec->s_nreloc * పరిమాణం(నిర్మాణం reloc), 1, f);
	    }
	}
    }


    // group the symbols in order of filename, func1, func2, etc
    // finally global symbols

    ఒకవేళ (s1->do_debug)
	క్రమీకరించు_చిహ్నం_పట్టిక(s1);

    // write line no data

    కొరకు (i = 1; i < s1->nb_sections; i++) {
	coff_sec = &section_శీర్షిక[i];
	tcc_sect = s1->sections[i];

	ఒకవేళ (s1->do_debug && tcc_sect == stext) {
	    // count how many line nos data


	    Stab_Sym *sym, *sym_చివర;
	    అక్షరం func_name[128], చివరి_func_name[128];
	    గుర్తులేని దీర్ఘ func_addr, చివరి_pc, pc;
	    స్థిరరాశి అక్షరం *incl_files[INCLUDE_దొంతర_కొలత];
	    పూర్ణాంకం incl_సూచీ, len, చివరి_పంక్తి_అంకె;
	    స్థిరరాశి అక్షరం *str, *p;

	    LINENO Coff_పంక్తి_No;

	    func_name[0] = '\0';
	    func_addr = 0;
	    incl_సూచీ = 0;
	    చివరి_func_name[0] = '\0';
	    చివరి_pc = 0;
	    చివరి_పంక్తి_అంకె = 1;
	    sym = (Stab_Sym *) stab_section->దత్తాంశం + 1;
	    sym_చివర =
		(Stab_Sym *) (stab_section->దత్తాంశం +
			      stab_section->దత్తాంశం_స్థానభ్రంశం);

	    అయితే (sym < sym_చివర) {
		ఎంపిక (sym->n_type) {
		    /* function start or end */
		స్థితి N_FUN:
		    ఒకవేళ (sym->n_strx == 0) {
			// end of function

			Coff_పంక్తి_No.l_addr.l_paddr = చివరి_pc;
			Coff_పంక్తి_No.l_lnno = చివరి_పంక్తి_అంకె + 1;
			fwrite(&Coff_పంక్తి_No, 6, 1, f);

			pc = sym->n_విలువ + func_addr;
			func_name[0] = '\0';
			func_addr = 0;
		    } లేకపోతే {
			// beginning of function

			str =
			    (స్థిరరాశి అక్షరం *) stabstr_section->దత్తాంశం +
			    sym->n_strx;


			p = strchr(str, ':');
			ఒకవేళ (!p) {
			    pstrcpy(func_name, పరిమాణం(func_name), str);
			} లేకపోతే {
			    len = p - str;
			    ఒకవేళ (len > పరిమాణం(func_name) - 1)
				len = పరిమాణం(func_name) - 1;
			    జ్ఞాపకం_నకలు(func_name, str, len);
			    func_name[len] = '\0';
			}
			func_addr = sym->n_విలువ;
			చివరి_pc = func_addr;
			చివరి_పంక్తి_అంకె = -1;

			// output a function begin

			Coff_పంక్తి_No.l_addr.l_symndx =
			    కనుగొను_Coff_చిహ్నం_సూచీ(s1, func_name);
			Coff_పంక్తి_No.l_lnno = 0;

			fwrite(&Coff_పంక్తి_No, 6, 1, f);
		    }
		    ఆపు;

		    /* line number info */
		స్థితి N_SLINE:
		    pc = sym->n_విలువ + func_addr;


		    /* XXX: slow! */
		    strcpy(చివరి_func_name, func_name);

		    // output a line reference

		    Coff_పంక్తి_No.l_addr.l_paddr = చివరి_pc;

		    ఒకవేళ (చివరి_పంక్తి_అంకె == -1) {
			Coff_పంక్తి_No.l_lnno = sym->n_desc;
		    } లేకపోతే {
			Coff_పంక్తి_No.l_lnno = చివరి_పంక్తి_అంకె + 1;
		    }

		    fwrite(&Coff_పంక్తి_No, 6, 1, f);

		    చివరి_pc = pc;
		    చివరి_పంక్తి_అంకె = sym->n_desc;

		    ఆపు;

		    /* include files */
		స్థితి N_BINCL:
		    str =
			(స్థిరరాశి అక్షరం *) stabstr_section->దత్తాంశం + sym->n_strx;
		  కూడు_incl2:
		    ఒకవేళ (incl_సూచీ < INCLUDE_దొంతర_కొలత) {
			incl_files[incl_సూచీ++] = str;
		    }
		    ఆపు;
		స్థితి N_EINCL:
		    ఒకవేళ (incl_సూచీ > 1)
			incl_సూచీ--;
		    ఆపు;
		స్థితి N_SO:
		    ఒకవేళ (sym->n_strx == 0) {
			incl_సూచీ = 0;	/* end of translation unit */
		    } లేకపోతే {
			str =
			    (స్థిరరాశి అక్షరం *) stabstr_section->దత్తాంశం +
			    sym->n_strx;
			/* do not add path */
			len = అక్షరశ్రేణి_పొడవు(str);
			ఒకవేళ (len > 0 && str[len - 1] != '/')
			    వెళ్ళు కూడు_incl2;
		    }
		    ఆపు;
		}
		sym++;
	    }
	}
    }

    // write symbol table
    ఒకవేళ (s1->do_debug) {
	పూర్ణాంకం k;
	నిర్మాణం syment csym;
	AUXFUNC auxfunc;
	AUXBF auxbf;
	AUXEF auxef;
	పూర్ణాంకం i;
	Elf32_Sym *p;
	స్థిరరాశి అక్షరం *name;
	పూర్ణాంకం nstr;
	పూర్ణాంకం n = 0;

	Coff_str_పట్టిక = (అక్షరం *) tcc_malloc(MAX_STR_పట్టిక);
	p_Coff_str_పట్టిక = Coff_str_పట్టిక;
	nstr = 0;

	p = (Elf32_Sym *) symtab_section->దత్తాంశం;


	కొరకు (i = 0; i < nb_syms; i++) {

	    name = symtab_section->link->దత్తాంశం + p->st_name;

	    కొరకు (k = 0; k < 8; k++)
		csym._n._n_name[k] = 0;

	    ఒకవేళ (అక్షరశ్రేణి_పొడవు(name) <= 8) {
		strcpy(csym._n._n_name, name);
	    } లేకపోతే {
		ఒకవేళ (p_Coff_str_పట్టిక - Coff_str_పట్టిక + అక్షరశ్రేణి_పొడవు(name) >
		    MAX_STR_పట్టిక - 1)
		    tcc_error("String table too large");

		csym._n._n_n._n_zeroes = 0;
		csym._n._n_n.n_స్థానభ్రంశం =
		    p_Coff_str_పట్టిక - Coff_str_పట్టిక + 4;

		strcpy(p_Coff_str_పట్టిక, name);
		p_Coff_str_పట్టిక += అక్షరశ్రేణి_పొడవు(name) + 1;	// skip over null
		nstr++;
	    }

	    ఒకవేళ (p->st_info == 4) {
		// put a filename symbol
		csym.n_విలువ = 33;	// ?????
		csym.n_scnum = N_DEBUG;
		csym.n_type = 0;
		csym.n_sclass = C_FILE;
		csym.n_numaux = 0;
		fwrite(&csym, 18, 1, f);
		n++;

	    } లేకపోతే ఒకవేళ (p->st_info == 0x12) {
		// find the function data

		కొరకు (k = 0; k < nFuncs; k++) {
		    ఒకవేళ (strcmp(name, Func[k]) == 0)
			ఆపు;
		}

		ఒకవేళ (k >= nFuncs) {
		    tcc_error("debug info can't find function: %s", name);
		}
		// put a Function Name

		csym.n_విలువ = p->st_విలువ;	// physical address
		csym.n_scnum = Coff_పాఠ్యం_Section_No;
		csym.n_type = MKTYPE(T_INT, DT_FCN, 0, 0, 0, 0, 0);
		csym.n_sclass = C_EXT;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxfunc.ట్యాగ్ = 0;
		auxfunc.కొలత = చివర_చిరునామా[k] - p->st_విలువ;
		auxfunc.fileptr = పంక్తి_No_File_Ptr[k];
		auxfunc.nextsym = n + 6;	// tktk
		auxfunc.dummy = 0;
		fwrite(&auxfunc, 18, 1, f);

		// put a .bf

		strcpy(csym._n._n_name, ".bf");
		csym.n_విలువ = p->st_విలువ;	// physical address
		csym.n_scnum = Coff_పాఠ్యం_Section_No;
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
		csym.n_విలువ = చివర_చిరునామా[k];	// physical address  
		csym.n_scnum = Coff_పాఠ్యం_Section_No;
		csym.n_type = 0;
		csym.n_sclass = C_FCN;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		// now put aux info

		auxef.dummy = 0;
		auxef.lineno = చివరి_పంక్తి_No[k];
		auxef.dummy1 = 0;
		auxef.dummy2 = 0;
		auxef.dummy3 = 0;
		auxef.dummy4 = 0;
		fwrite(&auxef, 18, 1, f);

		n += 6;

	    } లేకపోతే {
		// try an put some type info

		ఒకవేళ ((p->st_other & VT_BTYPE) == VT_DOUBLE) {
		    csym.n_type = T_DOUBLE;	// int
		    csym.n_sclass = C_EXT;
		} లేకపోతే ఒకవేళ ((p->st_other & VT_BTYPE) == VT_FLOAT) {
		    csym.n_type = T_FLOAT;
		    csym.n_sclass = C_EXT;
		} లేకపోతే ఒకవేళ ((p->st_other & VT_BTYPE) == VT_INT) {
		    csym.n_type = T_INT;	// int
		    csym.n_sclass = C_EXT;
		} లేకపోతే ఒకవేళ ((p->st_other & VT_BTYPE) == VT_SHORT) {
		    csym.n_type = T_SHORT;
		    csym.n_sclass = C_EXT;
		} లేకపోతే ఒకవేళ ((p->st_other & VT_BTYPE) == VT_BYTE) {
		    csym.n_type = T_CHAR;
		    csym.n_sclass = C_EXT;
		} లేకపోతే {
		    csym.n_type = T_INT;	// just mark as a label
		    csym.n_sclass = C_LABEL;
		}


		csym.n_విలువ = p->st_విలువ;
		csym.n_scnum = 2;
		csym.n_numaux = 1;
		fwrite(&csym, 18, 1, f);

		auxfunc.ట్యాగ్ = 0;
		auxfunc.కొలత = 0x20;
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

    ఒకవేళ (s1->do_debug) {
	// write string table

	// first write the size
	i = p_Coff_str_పట్టిక - Coff_str_పట్టిక;
	fwrite(&i, 4, 1, f);

	// then write the strings
	fwrite(Coff_str_పట్టిక, i, 1, f);

	tcc_free(Coff_str_పట్టిక);
    }

    తిరిగి 0;
}



// group the symbols in order of filename, func1, func2, etc
// finally global symbols

శూన్య క్రమీకరించు_చిహ్నం_పట్టిక(TCCState *s1)
{
    పూర్ణాంకం i, j, k, n = 0;
    Elf32_Sym *p, *p2, *New_పట్టిక;
    అక్షరం *name, *name2;

    New_పట్టిక = (Elf32_Sym *) tcc_malloc(nb_syms * పరిమాణం(Elf32_Sym));

    p = (Elf32_Sym *) symtab_section->దత్తాంశం;


    // find a file symbol, copy it over
    // then scan the whole symbol list and copy any function
    // symbols that match the file association

    కొరకు (i = 0; i < nb_syms; i++) {
	ఒకవేళ (p->st_info == 4) {
	    name = (అక్షరం *) symtab_section->link->దత్తాంశం + p->st_name;

	    // this is a file symbol, copy it over

	    New_పట్టిక[n++] = *p;

	    p2 = (Elf32_Sym *) symtab_section->దత్తాంశం;

	    కొరకు (j = 0; j < nb_syms; j++) {
		ఒకవేళ (p2->st_info == 0x12) {
		    // this is a func symbol

		    name2 =
			(అక్షరం *) symtab_section->link->దత్తాంశం + p2->st_name;

		    // find the function data index

		    కొరకు (k = 0; k < nFuncs; k++) {
			ఒకవేళ (strcmp(name2, Func[k]) == 0)
			    ఆపు;
		    }

		    ఒకవేళ (k >= nFuncs) {
                        tcc_error("debug (sort) info can't find function: %s", name2);
		    }

		    ఒకవేళ (strcmp(AssociatedFile[k], name) == 0) {
			// yes they match copy it over

			New_పట్టిక[n++] = *p2;
		    }
		}
		p2++;
	    }
	}
	p++;
    }

    // now all the filename and func symbols should have been copied over
    // copy all the rest over (all except file and funcs)

    p = (Elf32_Sym *) symtab_section->దత్తాంశం;
    కొరకు (i = 0; i < nb_syms; i++) {
	ఒకవేళ (p->st_info != 4 && p->st_info != 0x12) {
	    New_పట్టిక[n++] = *p;
	}
	p++;
    }

    ఒకవేళ (n != nb_syms)
	tcc_error("Internal Compiler error, debug info");

    // copy it all back

    p = (Elf32_Sym *) symtab_section->దత్తాంశం;
    కొరకు (i = 0; i < nb_syms; i++) {
	*p++ = New_పట్టిక[i];
    }

    tcc_free(New_పట్టిక);
}


పూర్ణాంకం కనుగొను_Coff_చిహ్నం_సూచీ(TCCState *s1, స్థిరరాశి అక్షరం *func_name)
{
    పూర్ణాంకం i, n = 0;
    Elf32_Sym *p;
    అక్షరం *name;

    p = (Elf32_Sym *) symtab_section->దత్తాంశం;

    కొరకు (i = 0; i < nb_syms; i++) {

	name = (అక్షరం *) symtab_section->link->దత్తాంశం + p->st_name;

	ఒకవేళ (p->st_info == 4) {
	    // put a filename symbol
	    n++;
	} లేకపోతే ఒకవేళ (p->st_info == 0x12) {

	    ఒకవేళ (strcmp(func_name, name) == 0)
		తిరిగి n;

	    n += 6;

	    // put a Function Name

	    // now put aux info

	    // put a .bf

	    // now put aux info

	    // put a .ef

	    // now put aux info

	} లేకపోతే {
	    n += 2;
	}

	p++;
    }

    తిరిగి n;			// total number of symbols
}

పూర్ణాంకం OutputTheSection(Section * sect)
{
    స్థిరరాశి అక్షరం *s = sect->name;

    ఒకవేళ (!strcmp(s, ".text"))
	తిరిగి 1;
    లేకపోతే ఒకవేళ (!strcmp(s, ".data"))
	తిరిగి 1;
    లేకపోతే
	తిరిగి 0;
}

పొట్టి పూర్ణాంకం GetCoffFlags(స్థిరరాశి అక్షరం *s)
{
    ఒకవేళ (!strcmp(s, ".text"))
	తిరిగి STYP_పాఠ్యం | STYP_దత్తాంశం | STYP_ALIGN | 0x400;
    లేకపోతే ఒకవేళ (!strcmp(s, ".data"))
	తిరిగి STYP_దత్తాంశం;
    లేకపోతే ఒకవేళ (!strcmp(s, ".bss"))
	తిరిగి STYP_BSS;
    లేకపోతే ఒకవేళ (!strcmp(s, ".stack"))
	తిరిగి STYP_BSS | STYP_ALIGN | 0x200;
    లేకపోతే ఒకవేళ (!strcmp(s, ".cinit"))
	తిరిగి STYP_COPY | STYP_దత్తాంశం | STYP_ALIGN | 0x200;
    లేకపోతే
	తిరిగి 0;
}

Section *కనుగొను_Section(TCCState * s1, స్థిరరాశి అక్షరం *sname)
{
    Section *s;
    పూర్ణాంకం i;

    కొరకు (i = 1; i < s1->nb_sections; i++) {
	s = s1->sections[i];

	ఒకవేళ (!strcmp(sname, s->name))
	    తిరిగి s;
    }

    tcc_error("could not find section %s", sname);
    తిరిగి 0;
}

ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_coff(TCCState * s1, పూర్ణాంకం fd)
{
// tktk TokenSym *ts;

    FILE *f;
    గుర్తులేని పూర్ణాంకం str_కొలత;
    అక్షరం *Coff_str_పట్టిక, *name;
    పూర్ణాంకం i, k;
    నిర్మాణం syment csym;
    అక్షరం name2[9];
    FILHDR file_hdr;		/* FILE HEADER STRUCTURE              */

    f = fdopen(fd, "rb");
    ఒకవేళ (!f) {
	tcc_error("Unable to open .out file for input");
    }

    ఒకవేళ (fread(&file_hdr, FILHSZ, 1, f) != 1)
	tcc_error("error reading .out file for input");

    ఒకవేళ (fread(&o_filehdr, పరిమాణం(o_filehdr), 1, f) != 1)
	tcc_error("error reading .out file for input");

    // first read the string table

    ఒకవేళ (fseek(f, file_hdr.f_symptr + file_hdr.f_nsyms * SYMESZ, SEEK_SET))
	tcc_error("error reading .out file for input");

    ఒకవేళ (fread(&str_కొలత, పరిమాణం(పూర్ణాంకం), 1, f) != 1)
	tcc_error("error reading .out file for input");


    Coff_str_పట్టిక = (అక్షరం *) tcc_malloc(str_కొలత);

    ఒకవేళ (fread(Coff_str_పట్టిక, str_కొలత - 4, 1, f) != 1)
	tcc_error("error reading .out file for input");

    // read/process all the symbols

    // seek back to symbols

    ఒకవేళ (fseek(f, file_hdr.f_symptr, SEEK_SET))
	tcc_error("error reading .out file for input");

    కొరకు (i = 0; i < file_hdr.f_nsyms; i++) {
	ఒకవేళ (fread(&csym, SYMESZ, 1, f) != 1)
	    tcc_error("error reading .out file for input");

	ఒకవేళ (csym._n._n_n._n_zeroes == 0) {
	    name = Coff_str_పట్టిక + csym._n._n_n.n_స్థానభ్రంశం - 4;
	} లేకపోతే {
	    name = csym._n._n_name;

	    ఒకవేళ (name[7] != 0) {
		కొరకు (k = 0; k < 8; k++)
		    name2[k] = name[k];

		name2[8] = 0;

		name = name2;
	    }
	}
//              if (strcmp("_DAC_Buffer",name)==0)  // tktk
//                      name[0]=0;

	ఒకవేళ (((csym.n_type & 0x30) == 0x20 && csym.n_sclass == 0x2) || ((csym.n_type & 0x30) == 0x30 && csym.n_sclass == 0x2) || (csym.n_type == 0x4 && csym.n_sclass == 0x2) || (csym.n_type == 0x8 && csym.n_sclass == 0x2) ||	// structures
	    (csym.n_type == 0x18 && csym.n_sclass == 0x2) ||	// pointer to structure
	    (csym.n_type == 0x7 && csym.n_sclass == 0x2) ||	// doubles
	    (csym.n_type == 0x6 && csym.n_sclass == 0x2))	// floats
	{
	    // strip off any leading underscore (except for other main routine)

	    ఒకవేళ (name[0] == '_' && strcmp(name, "_main") != 0)
		name++;

	    tcc_కూడు_చిహ్నం(s1, name, (శూన్య*)(uintptr_t)csym.n_విలువ);
	}
	// skip any aux records

	ఒకవేళ (csym.n_numaux == 1) {
	    ఒకవేళ (fread(&csym, SYMESZ, 1, f) != 1)
		tcc_error("error reading .out file for input");
	    i++;
	}
    }

    తిరిగి 0;
}
