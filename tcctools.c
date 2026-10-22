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

#ಅನ್ತರ್ಭಾವ "tcc.h"

//#define ARMAG  "!<arch>\n"
#ವ್ಯಾಖ್ಯಾನಿಸು ARFMAG "`\n"

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಅಕ್ಷರ ar_name[16];
    ಅಕ್ಷರ ar_date[12];
    ಅಕ್ಷರ ar_uid[6];
    ಅಕ್ಷರ ar_gid[6];
    ಅಕ್ಷರ ar_ಬಹುಲಕ[8];
    ಅಕ್ಷರ ar_ಗಾತ್ರ[10];
    ಅಕ್ಷರ ar_fmag[2];
} ArHdr;

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ le2belong(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ul) {
    ಹಿಂತಿರುಗಿ ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ar_usage(ಪೂರ್ಣಾಂಕ ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    ಹಿಂತಿರುಗಿ ret;
}

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_ar(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ArHdr arhdr_init = {
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

    FILE *fi, *fh = ಖಾಲಿ, *fo = ಖಾಲಿ;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *created_file = ಖಾಲಿ; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಂಕ i, fsize, i_lib, i_obj;
    ಅಕ್ಷರ *buf, *shstr, *symtab, *strtab;
    ಪೂರ್ಣಾಂಕ symtabsize = 0;//, strtabsize = 0;
    ಅಕ್ಷರ *anames = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ *afpos = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    ಅಕ್ಷರ tfile[260], stmp[20];
    ಅಕ್ಷರ *file, *name;
    ಪೂರ್ಣಾಂಕ ret = 2;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    ಪೂರ್ಣಾಂಕ ಹೊರತೆಗೆ = 0;
    ಪೂರ್ಣಾಂಕ ಕೋಷ್ಟಕ = 0;
    ಪೂರ್ಣಾಂಕ verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    ಗಾಗಿ (i = 1; i < argc; i++) {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *a = argv[i];
        ಆದರೆ (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        ಆದರೆ ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            ಆದರೆ (strpbrk(a, ops_conflict))
                ret = 1;
            ಆದರೆ (strchr(a, 'x'))
                ಹೊರತೆಗೆ = 1;
            ಆದರೆ (strchr(a, 't'))
                ಕೋಷ್ಟಕ = 1;
            ಆದರೆ (strchr(a, 'v'))
                verbose = 1;
        } ಇಲ್ಲದಿದ್ದರೆ {  // lib or obj files: don't abort - keep validating all args.
            ಆದರೆ (!i_lib)  // first file is the lib
                i_lib = i;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    ಆದರೆ (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    ಆದರೆ (ret == 1)
        ಹಿಂತಿರುಗಿ ar_usage(ret);

    ಆದರೆ (ಹೊರತೆಗೆ || ಕೋಷ್ಟಕ) {
        ಆದರೆ ((fh = fopen(argv[i_lib], "rb")) == ಖಾಲಿ)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            ಹೋಗು ಮುಕ್ತಾಯ;
        }
        fread(stmp, 1, 8, fh);
	ಆದರೆ (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            ಹೋಗು ಮುಕ್ತಾಯ;
	}
	ಆಗ (fread(&arhdr, 1, ಗಾತ್ರ(arhdr), fh) == ಗಾತ್ರ(arhdr)) {
	    ಅಕ್ಷರ *p, *e;

	    ಆದರೆ (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		ಹೋಗು no_ar;
	    p = arhdr.ar_name;
	    ಗಾಗಿ (e = p + ಗಾತ್ರ arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_ಗಾತ್ರ[ಗಾತ್ರ arhdr.ar_ಗಾತ್ರ-1] = 0;
	    fsize = atoi(arhdr.ar_ಗಾತ್ರ);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    ಆದರೆ (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		ಆದರೆ (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        ಆದರೆ (ಕೋಷ್ಟಕ || verbose)
		    ಬರೆ("%s%s\n", ಹೊರತೆಗೆ ? "x - " : "", arhdr.ar_name);
		ಆದರೆ (ಹೊರತೆಗೆ) {
		    ಆದರೆ ((fo = fopen(arhdr.ar_name, "wb")) == ಖಾಲಿ)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			ಹೋಗು ಮುಕ್ತಾಯ;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            ಆದರೆ (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
ಮುಕ್ತಾಯ:
	ಆದರೆ (fh)
		fclose(fh);
	ಹಿಂತಿರುಗಿ ret;
    }

    ಆದರೆ ((fh = fopen(argv[i_lib], "wb")) == ಖಾಲಿ)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        ಹೋಗು the_ಕೊನೆ;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    ಆದರೆ ((fo = fopen(tfile, "wb+")) == ಖಾಲಿ)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        ಹೋಗು the_ಕೊನೆ;
    }

    funcmax = 250;
    afpos = tcc_realloc(ಖಾಲಿ, funcmax * ಗಾತ್ರ *afpos); // 250 func
    ಸ್ಮರಣೆ_ನಕಲು(&arhdro.ar_ಬಹುಲಕ, "100644", 6);

    // i_obj = first input object file
    ಆಗ (i_obj < argc)
    {
        ಆದರೆ (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            ಮುಂದುವರಿ;
        }
        ಆದರೆ ((fi = fopen(argv[i_obj], "rb")) == ಖಾಲಿ) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            ಹೋಗು the_ಕೊನೆ;
        }
        ಆದರೆ (verbose)
            ಬರೆ("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        ಆದರೆ (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            ಹೋಗು the_ಕೊನೆ;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (ಅಕ್ಷರ *)(buf + shdr->sh_ಸ್ಥಾನಾಂತರ);
        symtab = strtab = ಖಾಲಿ;
        ಗಾಗಿ (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            ಆದರೆ (!shdr->sh_ಸ್ಥಾನಾಂತರ)
                ಮುಂದುವರಿ;
            ಆದರೆ (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (ಅಕ್ಷರ *)(buf + shdr->sh_ಸ್ಥಾನಾಂತರ);
                symtabsize = shdr->sh_ಗಾತ್ರ;
            }
            ಆದರೆ (shdr->sh_type == SHT_STRTAB)
            {
                ಆದರೆ (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (ಅಕ್ಷರ *)(buf + shdr->sh_ಸ್ಥಾನಾಂತರ);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        ಆದರೆ (symtab && strtab)
        {
            ಪೂರ್ಣಾಂಕ nsym = symtabsize / ಗಾತ್ರ(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            ಗಾಗಿ (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * ಗಾತ್ರ(ElfW(Sym)));
                ಆದರೆ (sym->st_shndx &&
                    (sym->st_info == 0x10
                    || sym->st_info == 0x11
                    || sym->st_info == 0x12
                    || sym->st_info == 0x20
                    || sym->st_info == 0x21
                    || sym->st_info == 0x22
                    )) {
                    //printf("symtab: %2Xh %4Xh %2Xh %s\n", sym->st_info, sym->st_size, sym->st_shndx, strtab + sym->st_name);
                    istrlen = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(strtab + sym->st_name)+1;
                    anames = tcc_realloc(anames, strpos+istrlen);
                    strcpy(anames + strpos, strtab + sym->st_name);
                    strpos += istrlen;
                    ಆದರೆ (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * ಗಾತ್ರ *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        ಗಾಗಿ (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name);
        ಆದರೆ (istrlen >= ಗಾತ್ರ(arhdro.ar_name))
            istrlen = ಗಾತ್ರ(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', ಗಾತ್ರ(arhdro.ar_name));
        ಸ್ಮರಣೆ_ನಕಲು(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        ಸ್ಮರಣೆ_ನಕಲು(&arhdro.ar_ಗಾತ್ರ, stmp, 10);
        fwrite(&arhdro, ಗಾತ್ರ(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + ಗಾತ್ರ(arhdro));
        ಆದರೆ (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + ಗಾತ್ರ(arhdr) + strpos + (funccnt+1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ);
    fpos = 0;
    ಆದರೆ ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    ಆದರೆ (!funccnt) {
        ret = 0;
        ಹೋಗು the_ಕೊನೆ;
    }
    sprintf(stmp, "%-10d", (ಪೂರ್ಣಾಂಕ)(strpos + (funccnt+1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ)) + fpos);
    ಸ್ಮರಣೆ_ನಕಲು(&arhdr.ar_ಗಾತ್ರ, stmp, 10);
    fwrite(&arhdr, ಗಾತ್ರ(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    ಗಾಗಿ (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ), 1, fh);
    fwrite(anames, strpos, 1, fh);
    ಆದರೆ (fpos)
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
the_ಕೊನೆ:
    ಆದರೆ (anames)
        tcc_free(anames);
    ಆದರೆ (afpos)
        tcc_free(afpos);
    ಆದರೆ (fh)
        fclose(fh);
    ಆದರೆ (created_file && ret != 0)
        remove(created_file);
    ಆದರೆ (fo)
        fclose(fo), remove(tfile);
    ಹಿಂತಿರುಗಿ ret;
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

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_impdef(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಪೂರ್ಣಾಂಕ ret, v, i;
    ಅಕ್ಷರ infile[260];
    ಅಕ್ಷರ outfile[260];

    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file;
    ಅಕ್ಷರ *p, *q;
    FILE *fp, *op;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    ಅಕ್ಷರ ಮಾರ್ಗ[260];
#ಆದರೆ_ಅಂತ್ಯ

    infile[0] = outfile[0] = 0;
    fp = op = ಖಾಲಿ;
    ret = 1;
    p = ಖಾಲಿ;
    v = 0;

    ಗಾಗಿ (i = 1; i < argc; ++i) {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *a = argv[i];
        ಆದರೆ ('-' == a[0]) {
            ಆದರೆ (0 == strcmp(a, "-v")) {
                v = 1;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == strcmp(a, "-o")) {
                ಆದರೆ (++i == argc)
                    ಹೋಗು usage;
                strcpy(outfile, argv[i]);
            } ಇಲ್ಲದಿದ್ದರೆ
                ಹೋಗು usage;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == infile[0])
            strcpy(infile, a);
        ಇಲ್ಲದಿದ್ದರೆ
            ಹೋಗು usage;
    }

    ಆದರೆ (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        ಹೋಗು the_ಕೊನೆ;
    }

    ಆದರೆ (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        ಆದರೆ (ಖಾಲಿ == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    ಆದರೆ (ಹುಡುಕು_ಮಾರ್ಗ(ಖಾಲಿ, file, ".dll", ಗಾತ್ರ ಮಾರ್ಗ, ಮಾರ್ಗ, ಖಾಲಿ))
        file = ಮಾರ್ಗ;
#ಆದರೆ_ಅಂತ್ಯ
    ret = tcc_get_dllexports(file, &p);
    ಆದರೆ (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        ಹೋಗು the_ಕೊನೆ;
    }

    ಆದರೆ (v)
        ಬರೆ("-> %s\n", file);

    op = fopen(outfile, "wb");
    ಆದರೆ (ಖಾಲಿ == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        ಹೋಗು the_ಕೊನೆ;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    ಗಾಗಿ (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(q) + 1;
    }

    ಆದರೆ (v)
        ಬರೆ("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_ಕೊನೆ:
    ಆದರೆ (p)
        tcc_free(p);
    ಆದರೆ (fp)
        fclose(fp);
    ಆದರೆ (op)
        fclose(op);
    ಹಿಂತಿರುಗಿ ret;
}

#ಆದರೆ_ಅಂತ್ಯ /* TCC_TARGET_PE */

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

#ಆದರೆ !defined TCC_ಗುರಿ_I386 && !defined TCC_ಗುರಿ_X86_64

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_cross(ಅಕ್ಷರ **argv, ಪೂರ್ಣಾಂಕ option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    ಹಿಂತಿರುಗಿ 1;
}

#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
#ಅನ್ತರ್ಭಾವ <process.h>

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
ಸ್ಥಿರ ಅಕ್ಷರ *quote_win32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಅಕ್ಷರ *o, *r = tcc_malloc(2 * ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(s) + 3);   /* max-esc, quotes, \0 */
    ಪೂರ್ಣಾಂಕ cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    ಗಾಗಿ (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        ಆದರೆ (*s == '\\' || *s == '"')
            *o++ = '\\';
        ಇಲ್ಲದಿದ್ದರೆ
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    ಆದರೆ (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } ಇಲ್ಲದಿದ್ದರೆ {
        o -= cbs;
    }

    *o = 0;
    ಹಿಂತಿರುಗಿ r; /* don't bother with realloc(r, o-r+1) */
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ execvp_win32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *prog, ಅಕ್ಷರ **argv)
{
    ಪೂರ್ಣಾಂಕ ret; ಅಕ್ಷರ **p;
    /* replace all " by \" */
    ಗಾಗಿ (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ*)argv);
    ಆದರೆ (-1 == ret)
        ಹಿಂತಿರುಗಿ ret;
    _cwait(&ret, ret, WAIT_ಮಗು);
    ನಿರ್ಗಮಿಸು(ret);
}
#ವ್ಯಾಖ್ಯಾನಿಸು execvp execvp_win32
#ಆದರೆ_ಅಂತ್ಯ /* _WIN32 */

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_cross(ಅಕ್ಷರ **argv, ಪೂರ್ಣಾಂಕ ಗುರಿ)
{
    ಅಕ್ಷರ ಕಾರ್ಯಕ್ರಮ[4096];
    ಅಕ್ಷರ *a0 = argv[0];
    ಪೂರ್ಣಾಂಕ ಪೂರ್ವಪ್ರತ್ಯಯ = tcc_basename(a0) - a0;

    snprintf(ಕಾರ್ಯಕ್ರಮ, ಗಾತ್ರ ಕಾರ್ಯಕ್ರಮ,
        "%.*s%s"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        "-win32"
#ಆದರೆ_ಅಂತ್ಯ
        "-tcc"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
        ".exe"
#ಆದರೆ_ಅಂತ್ಯ
        , ಪೂರ್ವಪ್ರತ್ಯಯ, a0, ಗುರಿ == 64 ? "x86_64" : "i386");

    ಆದರೆ (strcmp(a0, ಕಾರ್ಯಕ್ರಮ))
        execvp(argv[0] = ಕಾರ್ಯಕ್ರಮ, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", ಕಾರ್ಯಕ್ರಮ);
    ಹಿಂತಿರುಗಿ 1;
}

#ಆದರೆ_ಅಂತ್ಯ /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ _CRT_glob = 1;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_glob
ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ _dowildcard = 1;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

/* -------------------------------------------------------------- */
/* generate xxx.d file */

ಸ್ಥಿರ ಅಕ್ಷರ *escape_ಗುರಿ_dep(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s) {
    ಅಕ್ಷರ *res = tcc_malloc(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(s) * 2 + 1);
    ಪೂರ್ಣಾಂಕ j;
    ಗಾಗಿ (j = 0; *s; s++, j++) {
        ಆದರೆ (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    ಹಿಂತಿರುಗಿ res;
}

ST_FUNC ಪೂರ್ಣಾಂಕ gen_makedeps(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಗುರಿ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    FILE *depout;
    ಅಕ್ಷರ buf[1024];
    ಅಕ್ಷರ **escaped_targets;
    ಪೂರ್ಣಾಂಕ i, k, ಅಂಕೆ_targets;

    ಆದರೆ (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, ಗಾತ್ರ buf, "%.*s.d",
            (ಪೂರ್ಣಾಂಕ)(tcc_fileextension(ಗುರಿ) - ಗುರಿ), ಗುರಿ);
        filename = buf;
    }

    ಆದರೆ(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    ಇಲ್ಲದಿದ್ದರೆ
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    ಆದರೆ (!depout)
        ಹಿಂತಿರುಗಿ tcc_error_noabort("could not open '%s'", filename);
    ಆದರೆ (s1->verbose)
        ಬರೆ("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_ಗುರಿ_deps * ಗಾತ್ರ(*escaped_targets));
    ಅಂಕೆ_targets = 0;
    ಗಾಗಿ (i = 0; i<s1->nb_ಗುರಿ_deps; ++i) {
        ಗಾಗಿ (k = 0; k < i; ++k)
            ಆದರೆ (0 == strcmp(s1->ಗುರಿ_deps[i], s1->ಗುರಿ_deps[k]))
                ಹೋಗು ಮುಂದಿನ;
        escaped_targets[ಅಂಕೆ_targets++] = escape_ಗುರಿ_dep(s1->ಗುರಿ_deps[i]);
    ಮುಂದಿನ:;
    }

    fprintf(depout, "%s:", ಗುರಿ);
    ಗಾಗಿ (i = 0; i < ಅಂಕೆ_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    ಆದರೆ (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        ಗಾಗಿ (i = 1; i < ಅಂಕೆ_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    ಗಾಗಿ (i = 0; i < ಅಂಕೆ_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    ಹಿಂತಿರುಗಿ 0;
}

/* -------------------------------------------------------------- */
