/* -------------------------------------------------------------- */
/*
 *  TCC - Tiny C Compiler
 *
 *  tcctools.c - extra tools and and -m32/64 support
 *
 */

/* -------------------------------------------------------------- */
/*
 * This program is for making libtcc1.a without ar
 * tiny_libmaker - tiny elf lib maker
 * usage: tiny_libmaker [lib] files...
 * Copyright (c) 2007 Timppa
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#అన్తర్భావ "tcc.h"

//#define ARMAG  "!<arch>\n"
#నిర్వచించు ARFMAG "`\n"

రకనిర్వచనం నిర్మాణం {
    అక్షరం ar_name[16];
    అక్షరం ar_date[12];
    అక్షరం ar_uid[6];
    అక్షరం ar_gid[6];
    అక్షరం ar_బహుళకం[8];
    అక్షరం ar_కొలత[10];
    అక్షరం ar_fmag[2];
} ArHdr;

స్థిర గుర్తులేని దీర్ఘ le2belong(గుర్తులేని దీర్ఘ ul) {
    తిరిగి ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

స్థిర పూర్ణాంకం ar_usage(పూర్ణాంకం ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    తిరిగి ret;
}

ST_FUNC పూర్ణాంకం tcc_tool_ar(పూర్ణాంకం argc, అక్షరం **argv)
{
    స్థిర స్థిరరాశి ArHdr arhdr_init = {
        "/               ",
        "0           ",
        "0     ",
        "0     ",
        "0       ",
        "0         ",
        ARFMAG
        };

    ArHdr arhdr = arhdr_init;
    ArHdr arhdro = arhdr_init;

    FILE *fi, *fh = ఖాళీ, *fo = ఖాళీ;
    స్థిరరాశి అక్షరం *created_file = ఖాళీ; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    పూర్ణాంకం i, fsize, i_lib, i_obj;
    అక్షరం *buf, *shstr, *symtab, *strtab;
    పూర్ణాంకం symtabsize = 0;//, strtabsize = 0;
    అక్షరం *anames = ఖాళీ;
    పూర్ణాంకం *afpos = ఖాళీ;
    పూర్ణాంకం istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    అక్షరం tfile[260], stmp[20];
    అక్షరం *file, *name;
    పూర్ణాంకం ret = 2;
    స్థిరరాశి అక్షరం *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    పూర్ణాంకం వెలికితీయి = 0;
    పూర్ణాంకం పట్టిక = 0;
    పూర్ణాంకం verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    కొరకు (i = 1; i < argc; i++) {
        స్థిరరాశి అక్షరం *a = argv[i];
        ఒకవేళ (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        ఒకవేళ ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            ఒకవేళ (strpbrk(a, ops_conflict))
                ret = 1;
            ఒకవేళ (strchr(a, 'x'))
                వెలికితీయి = 1;
            ఒకవేళ (strchr(a, 't'))
                పట్టిక = 1;
            ఒకవేళ (strchr(a, 'v'))
                verbose = 1;
        } లేకపోతే {  // lib or obj files: don't abort - keep validating all args.
            ఒకవేళ (!i_lib)  // first file is the lib
                i_lib = i;
            లేకపోతే ఒకవేళ (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    ఒకవేళ (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    ఒకవేళ (ret == 1)
        తిరిగి ar_usage(ret);

    ఒకవేళ (వెలికితీయి || పట్టిక) {
        ఒకవేళ ((fh = fopen(argv[i_lib], "rb")) == ఖాళీ)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            వెళ్ళు ముగింపు_2;
        }
        fread(stmp, 1, 8, fh);
	ఒకవేళ (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            వెళ్ళు ముగింపు_2;
	}
	అయితే (fread(&arhdr, 1, పరిమాణం(arhdr), fh) == పరిమాణం(arhdr)) {
	    అక్షరం *p, *e;

	    ఒకవేళ (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		వెళ్ళు no_ar;
	    p = arhdr.ar_name;
	    కొరకు (e = p + పరిమాణం arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_కొలత[పరిమాణం arhdr.ar_కొలత-1] = 0;
	    fsize = atoi(arhdr.ar_కొలత);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    ఒకవేళ (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		ఒకవేళ (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        ఒకవేళ (పట్టిక || verbose)
		    రాయి("%s%s\n", వెలికితీయి ? "x - " : "", arhdr.ar_name);
		ఒకవేళ (వెలికితీయి) {
		    ఒకవేళ ((fo = fopen(arhdr.ar_name, "wb")) == ఖాళీ)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			వెళ్ళు ముగింపు_2;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            ఒకవేళ (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
ముగింపు_2:
	ఒకవేళ (fh)
		fclose(fh);
	తిరిగి ret;
    }

    ఒకవేళ ((fh = fopen(argv[i_lib], "wb")) == ఖాళీ)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        వెళ్ళు the_చివర;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    ఒకవేళ ((fo = fopen(tfile, "wb+")) == ఖాళీ)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        వెళ్ళు the_చివర;
    }

    funcmax = 250;
    afpos = tcc_realloc(ఖాళీ, funcmax * పరిమాణం *afpos); // 250 func
    జ్ఞాపకం_నకలు(&arhdro.ar_బహుళకం, "100644", 6);

    // i_obj = first input object file
    అయితే (i_obj < argc)
    {
        ఒకవేళ (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            కొనసాగు;
        }
        ఒకవేళ ((fi = fopen(argv[i_obj], "rb")) == ఖాళీ) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            వెళ్ళు the_చివర;
        }
        ఒకవేళ (verbose)
            రాయి("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        ఒకవేళ (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            వెళ్ళు the_చివర;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (అక్షరం *)(buf + shdr->sh_స్థానభ్రంశం);
        symtab = strtab = ఖాళీ;
        కొరకు (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            ఒకవేళ (!shdr->sh_స్థానభ్రంశం)
                కొనసాగు;
            ఒకవేళ (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (అక్షరం *)(buf + shdr->sh_స్థానభ్రంశం);
                symtabsize = shdr->sh_కొలత;
            }
            ఒకవేళ (shdr->sh_type == SHT_STRTAB)
            {
                ఒకవేళ (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (అక్షరం *)(buf + shdr->sh_స్థానభ్రంశం);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        ఒకవేళ (symtab && strtab)
        {
            పూర్ణాంకం nsym = symtabsize / పరిమాణం(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            కొరకు (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * పరిమాణం(ElfW(Sym)));
                ఒకవేళ (sym->st_shndx &&
                    (sym->st_info == 0x10
                    || sym->st_info == 0x11
                    || sym->st_info == 0x12
                    || sym->st_info == 0x20
                    || sym->st_info == 0x21
                    || sym->st_info == 0x22
                    )) {
                    //printf("symtab: %2Xh %4Xh %2Xh %s\n", sym->st_info, sym->st_size, sym->st_shndx, strtab + sym->st_name);
                    istrlen = అక్షరశ్రేణి_పొడవు(strtab + sym->st_name)+1;
                    anames = tcc_realloc(anames, strpos+istrlen);
                    strcpy(anames + strpos, strtab + sym->st_name);
                    strpos += istrlen;
                    ఒకవేళ (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * పరిమాణం *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        కొరకు (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = అక్షరశ్రేణి_పొడవు(name);
        ఒకవేళ (istrlen >= పరిమాణం(arhdro.ar_name))
            istrlen = పరిమాణం(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', పరిమాణం(arhdro.ar_name));
        జ్ఞాపకం_నకలు(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        జ్ఞాపకం_నకలు(&arhdro.ar_కొలత, stmp, 10);
        fwrite(&arhdro, పరిమాణం(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + పరిమాణం(arhdro));
        ఒకవేళ (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + పరిమాణం(arhdr) + strpos + (funccnt+1) * పరిమాణం(పూర్ణాంకం);
    fpos = 0;
    ఒకవేళ ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    ఒకవేళ (!funccnt) {
        ret = 0;
        వెళ్ళు the_చివర;
    }
    sprintf(stmp, "%-10d", (పూర్ణాంకం)(strpos + (funccnt+1) * పరిమాణం(పూర్ణాంకం)) + fpos);
    జ్ఞాపకం_నకలు(&arhdr.ar_కొలత, stmp, 10);
    fwrite(&arhdr, పరిమాణం(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    కొరకు (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * పరిమాణం(పూర్ణాంకం), 1, fh);
    fwrite(anames, strpos, 1, fh);
    ఒకవేళ (fpos)
        fwrite("", 1, 1, fh);
    // write objects
    fseek(fo, 0, SEEK_END);
    fsize = ftell(fo);
    fseek(fo, 0, SEEK_SET);
    buf = tcc_malloc(fsize + 1);
    fread(buf, fsize, 1, fo);
    fwrite(buf, fsize, 1, fh);
    tcc_free(buf);
    ret = 0;
the_చివర:
    ఒకవేళ (anames)
        tcc_free(anames);
    ఒకవేళ (afpos)
        tcc_free(afpos);
    ఒకవేళ (fh)
        fclose(fh);
    ఒకవేళ (created_file && ret != 0)
        remove(created_file);
    ఒకవేళ (fo)
        fclose(fo), remove(tfile);
    తిరిగి ret;
}

/* -------------------------------------------------------------- */
/*
 * tiny_impdef creates an export definition file (.def) from a dll
 * on MS-Windows. Usage: tiny_impdef library.dll [-o outputfile]"
 *
 *  Copyright (c) 2005,2007 grischka
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#నిర్వచితమైతే TCC_లక్ష్యం_PE

ST_FUNC పూర్ణాంకం tcc_tool_impdef(పూర్ణాంకం argc, అక్షరం **argv)
{
    పూర్ణాంకం ret, v, i;
    అక్షరం infile[260];
    అక్షరం outfile[260];

    స్థిరరాశి అక్షరం *file;
    అక్షరం *p, *q;
    FILE *fp, *op;

#నిర్వచితమైతే _WIN32
    అక్షరం మార్గం[260];
#అయితే_ముగింపు

    infile[0] = outfile[0] = 0;
    fp = op = ఖాళీ;
    ret = 1;
    p = ఖాళీ;
    v = 0;

    కొరకు (i = 1; i < argc; ++i) {
        స్థిరరాశి అక్షరం *a = argv[i];
        ఒకవేళ ('-' == a[0]) {
            ఒకవేళ (0 == strcmp(a, "-v")) {
                v = 1;
            } లేకపోతే ఒకవేళ (0 == strcmp(a, "-o")) {
                ఒకవేళ (++i == argc)
                    వెళ్ళు usage;
                strcpy(outfile, argv[i]);
            } లేకపోతే
                వెళ్ళు usage;
        } లేకపోతే ఒకవేళ (0 == infile[0])
            strcpy(infile, a);
        లేకపోతే
            వెళ్ళు usage;
    }

    ఒకవేళ (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        వెళ్ళు the_చివర;
    }

    ఒకవేళ (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        ఒకవేళ (ఖాళీ == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#నిర్వచితమైతే _WIN32
    ఒకవేళ (శోధన_మార్గం(ఖాళీ, file, ".dll", పరిమాణం మార్గం, మార్గం, ఖాళీ))
        file = మార్గం;
#అయితే_ముగింపు
    ret = tcc_get_dllexports(file, &p);
    ఒకవేళ (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        వెళ్ళు the_చివర;
    }

    ఒకవేళ (v)
        రాయి("-> %s\n", file);

    op = fopen(outfile, "wb");
    ఒకవేళ (ఖాళీ == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        వెళ్ళు the_చివర;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    కొరకు (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += అక్షరశ్రేణి_పొడవు(q) + 1;
    }

    ఒకవేళ (v)
        రాయి("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_చివర:
    ఒకవేళ (p)
        tcc_free(p);
    ఒకవేళ (fp)
        fclose(fp);
    ఒకవేళ (op)
        fclose(op);
    తిరిగి ret;
}

#అయితే_ముగింపు /* TCC_TARGET_PE */

/* -------------------------------------------------------------- */
/*
 *  TCC - Tiny C Compiler
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
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

/* re-execute the i386/x86_64 cross-compilers with tcc -m32/-m64: */

#ఒకవేళ !defined TCC_లక్ష్యం_I386 && !defined TCC_లక్ష్యం_X86_64

ST_FUNC పూర్ణాంకం tcc_tool_cross(అక్షరం **argv, పూర్ణాంకం option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    తిరిగి 1;
}

#లేకపోతే
#నిర్వచితమైతే _WIN32
#అన్తర్భావ <process.h>

/* - Empty argument or with space/tab (not newline) requires quoting.
 * - Double-quotes at the value require '\'-escape, regardless of quoting.
 * - Consecutive (or 1) backslashes at the value all need '\'-escape only if
 *   followed by [escaped] double quote, else taken literally, e.g. <x\\y\>
 *   remains literal without quoting or esc, but <x\\"y\> becomes <x\\\\\"y\>.
 * - This "before double quote" rule applies also before delimiting quoting,
 *   e.g. <x\y \"z\> becomes <"x\y \\\"z\\"> (quoting required because space).
 *
 * https://learn.microsoft.com/en-us/cpp/c-language/parsing-c-command-line-arguments
 */
స్థిర అక్షరం *quote_win32(స్థిరరాశి అక్షరం *s)
{
    అక్షరం *o, *r = tcc_malloc(2 * అక్షరశ్రేణి_పొడవు(s) + 3);   /* max-esc, quotes, \0 */
    పూర్ణాంకం cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    కొరకు (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        ఒకవేళ (*s == '\\' || *s == '"')
            *o++ = '\\';
        లేకపోతే
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    ఒకవేళ (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } లేకపోతే {
        o -= cbs;
    }

    *o = 0;
    తిరిగి r; /* don't bother with realloc(r, o-r+1) */
}

స్థిర పూర్ణాంకం execvp_win32(స్థిరరాశి అక్షరం *prog, అక్షరం **argv)
{
    పూర్ణాంకం ret; అక్షరం **p;
    /* replace all " by \" */
    కొరకు (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (స్థిరరాశి అక్షరం *స్థిరరాశి*)argv);
    ఒకవేళ (-1 == ret)
        తిరిగి ret;
    _cwait(&ret, ret, WAIT_బిడ్డ);
    నిష్క్రమించు(ret);
}
#నిర్వచించు execvp execvp_win32
#అయితే_ముగింపు /* _WIN32 */

ST_FUNC పూర్ణాంకం tcc_tool_cross(అక్షరం **argv, పూర్ణాంకం లక్ష్యం)
{
    అక్షరం కార్యక్రమం[4096];
    అక్షరం *a0 = argv[0];
    పూర్ణాంకం ఉపసర్గ = tcc_basename(a0) - a0;

    snprintf(కార్యక్రమం, పరిమాణం కార్యక్రమం,
        "%.*s%s"
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        "-win32"
#అయితే_ముగింపు
        "-tcc"
#నిర్వచితమైతే _WIN32
        ".exe"
#అయితే_ముగింపు
        , ఉపసర్గ, a0, లక్ష్యం == 64 ? "x86_64" : "i386");

    ఒకవేళ (strcmp(a0, కార్యక్రమం))
        execvp(argv[0] = కార్యక్రమం, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", కార్యక్రమం);
    తిరిగి 1;
}

#అయితే_ముగింపు /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#నిర్వచితమైతే _WIN32
స్థిరరాశి పూర్ణాంకం _CRT_glob = 1;
#నిర్వచితం_కాకపోతే _CRT_glob
స్థిరరాశి పూర్ణాంకం _dowildcard = 1;
#అయితే_ముగింపు
#అయితే_ముగింపు

/* -------------------------------------------------------------- */
/* generate xxx.d file */

స్థిర అక్షరం *escape_లక్ష్యం_dep(స్థిరరాశి అక్షరం *s) {
    అక్షరం *res = tcc_malloc(అక్షరశ్రేణి_పొడవు(s) * 2 + 1);
    పూర్ణాంకం j;
    కొరకు (j = 0; *s; s++, j++) {
        ఒకవేళ (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    తిరిగి res;
}

ST_FUNC పూర్ణాంకం gen_makedeps(TCCState *s1, స్థిరరాశి అక్షరం *లక్ష్యం, స్థిరరాశి అక్షరం *filename)
{
    FILE *depout;
    అక్షరం buf[1024];
    అక్షరం **escaped_targets;
    పూర్ణాంకం i, k, అంకె_targets;

    ఒకవేళ (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, పరిమాణం buf, "%.*s.d",
            (పూర్ణాంకం)(tcc_fileextension(లక్ష్యం) - లక్ష్యం), లక్ష్యం);
        filename = buf;
    }

    ఒకవేళ(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    లేకపోతే
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    ఒకవేళ (!depout)
        తిరిగి tcc_error_noabort("could not open '%s'", filename);
    ఒకవేళ (s1->verbose)
        రాయి("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_లక్ష్యం_deps * పరిమాణం(*escaped_targets));
    అంకె_targets = 0;
    కొరకు (i = 0; i<s1->nb_లక్ష్యం_deps; ++i) {
        కొరకు (k = 0; k < i; ++k)
            ఒకవేళ (0 == strcmp(s1->లక్ష్యం_deps[i], s1->లక్ష్యం_deps[k]))
                వెళ్ళు తదుపరి;
        escaped_targets[అంకె_targets++] = escape_లక్ష్యం_dep(s1->లక్ష్యం_deps[i]);
    తదుపరి:;
    }

    fprintf(depout, "%s:", లక్ష్యం);
    కొరకు (i = 0; i < అంకె_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    ఒకవేళ (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        కొరకు (i = 1; i < అంకె_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    కొరకు (i = 0; i < అంకె_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    తిరిగి 0;
}

/* -------------------------------------------------------------- */
