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
#define ARFMAG "`\n"

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ವರ್ಣ ar_name[16];
    ವರ್ಣ ar_date[12];
    ವರ್ಣ ar_uid[6];
    ವರ್ಣ ar_gid[6];
    ವರ್ಣ ar_mode[8];
    ವರ್ಣ ar_size[10];
    ವರ್ಣ ar_fmag[2];
} ArHdr;

ಸ್ಥಿರ unsigned long le2belong(unsigned long ul) {
    ಪ್ರತ್ಯಾಗಮ ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ar_usage(ಪೂರ್ಣಾಙ್ಕ ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    ಪ್ರತ್ಯಾಗಮ ret;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_ar(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಸ್ಥಿರ ಧ್ರುವ ArHdr arhdr_init = {
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

    FILE *fi, *fh = ರಿಕ್ತ, *fo = ರಿಕ್ತ;
    ಧ್ರುವ ವರ್ಣ *created_file = ರಿಕ್ತ; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    ಪೂರ್ಣಾಙ್ಕ i, fsize, i_lib, i_obj;
    ವರ್ಣ *buf, *shstr, *symtab, *strtab;
    ಪೂರ್ಣಾಙ್ಕ symtabsize = 0;//, strtabsize = 0;
    ವರ್ಣ *anames = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ *afpos = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    ವರ್ಣ tfile[260], stmp[20];
    ವರ್ಣ *file, *name;
    ಪೂರ್ಣಾಙ್ಕ ret = 2;
    ಧ್ರುವ ವರ್ಣ *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    ಪೂರ್ಣಾಙ್ಕ extract = 0;
    ಪೂರ್ಣಾಙ್ಕ table = 0;
    ಪೂರ್ಣಾಙ್ಕ verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    ಪ್ರತಿ (i = 1; i < argc; i++) {
        ಧ್ರುವ ವರ್ಣ *a = argv[i];
        ಯದಿ (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        ಯದಿ ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            ಯದಿ (strpbrk(a, ops_conflict))
                ret = 1;
            ಯದಿ (strchr(a, 'x'))
                extract = 1;
            ಯದಿ (strchr(a, 't'))
                table = 1;
            ಯದಿ (strchr(a, 'v'))
                verbose = 1;
        } ಅನ್ಯಥಾ {  // lib or obj files: don't abort - keep validating all args.
            ಯದಿ (!i_lib)  // first file is the lib
                i_lib = i;
            ಅನ್ಯಥಾ ಯದಿ (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    ಯದಿ (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    ಯದಿ (ret == 1)
        ಪ್ರತ್ಯಾಗಮ ar_usage(ret);

    ಯದಿ (extract || table) {
        ಯದಿ ((fh = fopen(argv[i_lib], "rb")) == ರಿಕ್ತ)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            ಗಚ್ಛ finish;
        }
        fread(stmp, 1, 8, fh);
	ಯದಿ (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            ಗಚ್ಛ finish;
	}
	ಯಾವತ್ (fread(&arhdr, 1, ಪರಿಮಾಣ(arhdr), fh) == ಪರಿಮಾಣ(arhdr)) {
	    ವರ್ಣ *p, *e;

	    ಯದಿ (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		ಗಚ್ಛ no_ar;
	    p = arhdr.ar_name;
	    ಪ್ರತಿ (e = p + ಪರಿಮಾಣ arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[ಪರಿಮಾಣ arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    ಯದಿ (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		ಯದಿ (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        ಯದಿ (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		ಯದಿ (extract) {
		    ಯದಿ ((fo = fopen(arhdr.ar_name, "wb")) == ರಿಕ್ತ)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			ಗಚ್ಛ finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            ಯದಿ (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	ಯದಿ (fh)
		fclose(fh);
	ಪ್ರತ್ಯಾಗಮ ret;
    }

    ಯದಿ ((fh = fopen(argv[i_lib], "wb")) == ರಿಕ್ತ)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        ಗಚ್ಛ the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    ಯದಿ ((fo = fopen(tfile, "wb+")) == ರಿಕ್ತ)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        ಗಚ್ಛ the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(ರಿಕ್ತ, funcmax * ಪರಿಮಾಣ *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    ಯಾವತ್ (i_obj < argc)
    {
        ಯದಿ (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            ಅನುವರ್ತ;
        }
        ಯದಿ ((fi = fopen(argv[i_obj], "rb")) == ರಿಕ್ತ) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            ಗಚ್ಛ the_end;
        }
        ಯದಿ (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        ಯದಿ (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            ಗಚ್ಛ the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (ವರ್ಣ *)(buf + shdr->sh_offset);
        symtab = strtab = ರಿಕ್ತ;
        ಪ್ರತಿ (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            ಯದಿ (!shdr->sh_offset)
                ಅನುವರ್ತ;
            ಯದಿ (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (ವರ್ಣ *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            ಯದಿ (shdr->sh_type == SHT_STRTAB)
            {
                ಯದಿ (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (ವರ್ಣ *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        ಯದಿ (symtab && strtab)
        {
            ಪೂರ್ಣಾಙ್ಕ nsym = symtabsize / ಪರಿಮಾಣ(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            ಪ್ರತಿ (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * ಪರಿಮಾಣ(ElfW(Sym)));
                ಯದಿ (sym->st_shndx &&
                    (sym->st_info == 0x10
                    || sym->st_info == 0x11
                    || sym->st_info == 0x12
                    || sym->st_info == 0x20
                    || sym->st_info == 0x21
                    || sym->st_info == 0x22
                    )) {
                    //printf("symtab: %2Xh %4Xh %2Xh %s\n", sym->st_info, sym->st_size, sym->st_shndx, strtab + sym->st_name);
                    istrlen = strlen(strtab + sym->st_name)+1;
                    anames = tcc_realloc(anames, strpos+istrlen);
                    strcpy(anames + strpos, strtab + sym->st_name);
                    strpos += istrlen;
                    ಯದಿ (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * ಪರಿಮಾಣ *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        ಪ್ರತಿ (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        ಯದಿ (istrlen >= ಪರಿಮಾಣ(arhdro.ar_name))
            istrlen = ಪರಿಮಾಣ(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', ಪರಿಮಾಣ(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, ಪರಿಮಾಣ(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + ಪರಿಮಾಣ(arhdro));
        ಯದಿ (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + ಪರಿಮಾಣ(arhdr) + strpos + (funccnt+1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ);
    fpos = 0;
    ಯದಿ ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    ಯದಿ (!funccnt) {
        ret = 0;
        ಗಚ್ಛ the_end;
    }
    sprintf(stmp, "%-10d", (ಪೂರ್ಣಾಙ್ಕ)(strpos + (funccnt+1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, ಪರಿಮಾಣ(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    ಪ್ರತಿ (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ), 1, fh);
    fwrite(anames, strpos, 1, fh);
    ಯದಿ (fpos)
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
the_end:
    ಯದಿ (anames)
        tcc_free(anames);
    ಯದಿ (afpos)
        tcc_free(afpos);
    ಯದಿ (fh)
        fclose(fh);
    ಯದಿ (created_file && ret != 0)
        remove(created_file);
    ಯದಿ (fo)
        fclose(fo), remove(tfile);
    ಪ್ರತ್ಯಾಗಮ ret;
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

#ifdef TCC_TARGET_PE

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_impdef(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ ret, v, i;
    ವರ್ಣ infile[260];
    ವರ್ಣ outfile[260];

    ಧ್ರುವ ವರ್ಣ *file;
    ವರ್ಣ *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    ವರ್ಣ path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = ರಿಕ್ತ;
    ret = 1;
    p = ರಿಕ್ತ;
    v = 0;

    ಪ್ರತಿ (i = 1; i < argc; ++i) {
        ಧ್ರುವ ವರ್ಣ *a = argv[i];
        ಯದಿ ('-' == a[0]) {
            ಯದಿ (0 == strcmp(a, "-v")) {
                v = 1;
            } ಅನ್ಯಥಾ ಯದಿ (0 == strcmp(a, "-o")) {
                ಯದಿ (++i == argc)
                    ಗಚ್ಛ usage;
                strcpy(outfile, argv[i]);
            } ಅನ್ಯಥಾ
                ಗಚ್ಛ usage;
        } ಅನ್ಯಥಾ ಯದಿ (0 == infile[0])
            strcpy(infile, a);
        ಅನ್ಯಥಾ
            ಗಚ್ಛ usage;
    }

    ಯದಿ (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        ಗಚ್ಛ the_end;
    }

    ಯದಿ (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        ಯದಿ (ರಿಕ್ತ == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    ಯದಿ (ಹುಡುಕು_Path(ರಿಕ್ತ, file, ".dll", ಪರಿಮಾಣ path, path, ರಿಕ್ತ))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    ಯದಿ (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        ಗಚ್ಛ the_end;
    }

    ಯದಿ (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    ಯದಿ (ರಿಕ್ತ == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        ಗಚ್ಛ the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    ಪ್ರತಿ (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    ಯದಿ (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    ಯದಿ (p)
        tcc_free(p);
    ಯದಿ (fp)
        fclose(fp);
    ಯದಿ (op)
        fclose(op);
    ಪ್ರತ್ಯಾಗಮ ret;
}

#endif /* TCC_TARGET_PE */

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

#ಯದಿ !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_cross(ವರ್ಣ **argv, ಪೂರ್ಣಾಙ್ಕ option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    ಪ್ರತ್ಯಾಗಮ 1;
}

#ಅನ್ಯಥಾ
#ifdef _WIN32
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
ಸ್ಥಿರ ವರ್ಣ *quote_win32(ಧ್ರುವ ವರ್ಣ *s)
{
    ವರ್ಣ *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    ಪೂರ್ಣಾಙ್ಕ cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    ಪ್ರತಿ (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        ಯದಿ (*s == '\\' || *s == '"')
            *o++ = '\\';
        ಅನ್ಯಥಾ
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    ಯದಿ (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } ಅನ್ಯಥಾ {
        o -= cbs;
    }

    *o = 0;
    ಪ್ರತ್ಯಾಗಮ r; /* don't bother with realloc(r, o-r+1) */
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ execvp_win32(ಧ್ರುವ ವರ್ಣ *prog, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ ret; ವರ್ಣ **p;
    /* replace all " by \" */
    ಪ್ರತಿ (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ*)argv);
    ಯದಿ (-1 == ret)
        ಪ್ರತ್ಯಾಗಮ ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_cross(ವರ್ಣ **argv, ಪೂರ್ಣಾಙ್ಕ target)
{
    ವರ್ಣ program[4096];
    ವರ್ಣ *a0 = argv[0];
    ಪೂರ್ಣಾಙ್ಕ prefix = tcc_basename(a0) - a0;

    snprintf(program, ಪರಿಮಾಣ program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    ಯದಿ (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    ಪ್ರತ್ಯಾಗಮ 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ _CRT_glob = 1;
#ifndef _CRT_glob
ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

ಸ್ಥಿರ ವರ್ಣ *escape_target_dep(ಧ್ರುವ ವರ್ಣ *s) {
    ವರ್ಣ *res = tcc_malloc(strlen(s) * 2 + 1);
    ಪೂರ್ಣಾಙ್ಕ j;
    ಪ್ರತಿ (j = 0; *s; s++, j++) {
        ಯದಿ (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    ಪ್ರತ್ಯಾಗಮ res;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ gen_makedeps(TCCState *s1, ಧ್ರುವ ವರ್ಣ *target, ಧ್ರುವ ವರ್ಣ *filename)
{
    FILE *depout;
    ವರ್ಣ buf[1024];
    ವರ್ಣ **escaped_targets;
    ಪೂರ್ಣಾಙ್ಕ i, k, ಅಂಕೆ_targets;

    ಯದಿ (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, ಪರಿಮಾಣ buf, "%.*s.d",
            (ಪೂರ್ಣಾಙ್ಕ)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    ಯದಿ(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    ಅನ್ಯಥಾ
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    ಯದಿ (!depout)
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("could not open '%s'", filename);
    ಯದಿ (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * ಪರಿಮಾಣ(*escaped_targets));
    ಅಂಕೆ_targets = 0;
    ಪ್ರತಿ (i = 0; i<s1->nb_target_deps; ++i) {
        ಪ್ರತಿ (k = 0; k < i; ++k)
            ಯದಿ (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                ಗಚ್ಛ next;
        escaped_targets[ಅಂಕೆ_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    ಪ್ರತಿ (i = 0; i < ಅಂಕೆ_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    ಯದಿ (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        ಪ್ರತಿ (i = 1; i < ಅಂಕೆ_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    ಪ್ರತಿ (i = 0; i < ಅಂಕೆ_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* -------------------------------------------------------------- */
