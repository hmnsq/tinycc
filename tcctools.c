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

#അന്തര്ഭാവ "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

തരനിർവചനം ഘടന {
    അക്ഷരം ar_name[16];
    അക്ഷരം ar_date[12];
    അക്ഷരം ar_uid[6];
    അക്ഷരം ar_gid[6];
    അക്ഷരം ar_mode[8];
    അക്ഷരം ar_size[10];
    അക്ഷരം ar_fmag[2];
} ArHdr;

സ്ഥിതം unsigned long le2belong(unsigned long ul) {
    തിരികെ ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ar_usage(പൂർണ്ണസംഖ്യ ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    തിരികെ ret;
}

ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_ar(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    സ്ഥിതം സ്ഥിരം ArHdr arhdr_init = {
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

    FILE *fi, *fh = ശൂന്യ, *fo = ശൂന്യ;
    സ്ഥിരം അക്ഷരം *created_file = ശൂന്യ; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    പൂർണ്ണസംഖ്യ i, fsize, i_lib, i_obj;
    അക്ഷരം *buf, *shstr, *symtab, *strtab;
    പൂർണ്ണസംഖ്യ symtabsize = 0;//, strtabsize = 0;
    അക്ഷരം *anames = ശൂന്യ;
    പൂർണ്ണസംഖ്യ *afpos = ശൂന്യ;
    പൂർണ്ണസംഖ്യ istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    അക്ഷരം tfile[260], stmp[20];
    അക്ഷരം *file, *name;
    പൂർണ്ണസംഖ്യ ret = 2;
    സ്ഥിരം അക്ഷരം *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    പൂർണ്ണസംഖ്യ extract = 0;
    പൂർണ്ണസംഖ്യ table = 0;
    പൂർണ്ണസംഖ്യ verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    വേണ്ടി (i = 1; i < argc; i++) {
        സ്ഥിരം അക്ഷരം *a = argv[i];
        എങ്കിൽ (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        എങ്കിൽ ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            എങ്കിൽ (strpbrk(a, ops_conflict))
                ret = 1;
            എങ്കിൽ (strchr(a, 'x'))
                extract = 1;
            എങ്കിൽ (strchr(a, 't'))
                table = 1;
            എങ്കിൽ (strchr(a, 'v'))
                verbose = 1;
        } അല്ലെങ്കിൽ {  // lib or obj files: don't abort - keep validating all args.
            എങ്കിൽ (!i_lib)  // first file is the lib
                i_lib = i;
            അല്ലെങ്കിൽ എങ്കിൽ (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    എങ്കിൽ (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    എങ്കിൽ (ret == 1)
        തിരികെ ar_usage(ret);

    എങ്കിൽ (extract || table) {
        എങ്കിൽ ((fh = fopen(argv[i_lib], "rb")) == ശൂന്യ)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            പോകുക finish;
        }
        fread(stmp, 1, 8, fh);
	എങ്കിൽ (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            പോകുക finish;
	}
	ആകുമ്പോൾ (fread(&arhdr, 1, വലുപ്പം(arhdr), fh) == വലുപ്പം(arhdr)) {
	    അക്ഷരം *p, *e;

	    എങ്കിൽ (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		പോകുക no_ar;
	    p = arhdr.ar_name;
	    വേണ്ടി (e = p + വലുപ്പം arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[വലുപ്പം arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    എങ്കിൽ (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		എങ്കിൽ (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        എങ്കിൽ (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		എങ്കിൽ (extract) {
		    എങ്കിൽ ((fo = fopen(arhdr.ar_name, "wb")) == ശൂന്യ)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			പോകുക finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            എങ്കിൽ (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	എങ്കിൽ (fh)
		fclose(fh);
	തിരികെ ret;
    }

    എങ്കിൽ ((fh = fopen(argv[i_lib], "wb")) == ശൂന്യ)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        പോകുക the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    എങ്കിൽ ((fo = fopen(tfile, "wb+")) == ശൂന്യ)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        പോകുക the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(ശൂന്യ, funcmax * വലുപ്പം *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    ആകുമ്പോൾ (i_obj < argc)
    {
        എങ്കിൽ (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            തുടരുക;
        }
        എങ്കിൽ ((fi = fopen(argv[i_obj], "rb")) == ശൂന്യ) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            പോകുക the_end;
        }
        എങ്കിൽ (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        എങ്കിൽ (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            പോകുക the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (അക്ഷരം *)(buf + shdr->sh_offset);
        symtab = strtab = ശൂന്യ;
        വേണ്ടി (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            എങ്കിൽ (!shdr->sh_offset)
                തുടരുക;
            എങ്കിൽ (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (അക്ഷരം *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            എങ്കിൽ (shdr->sh_type == SHT_STRTAB)
            {
                എങ്കിൽ (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (അക്ഷരം *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        എങ്കിൽ (symtab && strtab)
        {
            പൂർണ്ണസംഖ്യ nsym = symtabsize / വലുപ്പം(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            വേണ്ടി (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * വലുപ്പം(ElfW(Sym)));
                എങ്കിൽ (sym->st_shndx &&
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
                    എങ്കിൽ (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * വലുപ്പം *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        വേണ്ടി (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        എങ്കിൽ (istrlen >= വലുപ്പം(arhdro.ar_name))
            istrlen = വലുപ്പം(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', വലുപ്പം(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, വലുപ്പം(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + വലുപ്പം(arhdro));
        എങ്കിൽ (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + വലുപ്പം(arhdr) + strpos + (funccnt+1) * വലുപ്പം(പൂർണ്ണസംഖ്യ);
    fpos = 0;
    എങ്കിൽ ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    എങ്കിൽ (!funccnt) {
        ret = 0;
        പോകുക the_end;
    }
    sprintf(stmp, "%-10d", (പൂർണ്ണസംഖ്യ)(strpos + (funccnt+1) * വലുപ്പം(പൂർണ്ണസംഖ്യ)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, വലുപ്പം(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    വേണ്ടി (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * വലുപ്പം(പൂർണ്ണസംഖ്യ), 1, fh);
    fwrite(anames, strpos, 1, fh);
    എങ്കിൽ (fpos)
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
    എങ്കിൽ (anames)
        tcc_free(anames);
    എങ്കിൽ (afpos)
        tcc_free(afpos);
    എങ്കിൽ (fh)
        fclose(fh);
    എങ്കിൽ (created_file && ret != 0)
        remove(created_file);
    എങ്കിൽ (fo)
        fclose(fo), remove(tfile);
    തിരികെ ret;
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

ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_impdef(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ ret, v, i;
    അക്ഷരം infile[260];
    അക്ഷരം outfile[260];

    സ്ഥിരം അക്ഷരം *file;
    അക്ഷരം *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    അക്ഷരം path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = ശൂന്യ;
    ret = 1;
    p = ശൂന്യ;
    v = 0;

    വേണ്ടി (i = 1; i < argc; ++i) {
        സ്ഥിരം അക്ഷരം *a = argv[i];
        എങ്കിൽ ('-' == a[0]) {
            എങ്കിൽ (0 == strcmp(a, "-v")) {
                v = 1;
            } അല്ലെങ്കിൽ എങ്കിൽ (0 == strcmp(a, "-o")) {
                എങ്കിൽ (++i == argc)
                    പോകുക usage;
                strcpy(outfile, argv[i]);
            } അല്ലെങ്കിൽ
                പോകുക usage;
        } അല്ലെങ്കിൽ എങ്കിൽ (0 == infile[0])
            strcpy(infile, a);
        അല്ലെങ്കിൽ
            പോകുക usage;
    }

    എങ്കിൽ (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        പോകുക the_end;
    }

    എങ്കിൽ (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        എങ്കിൽ (ശൂന്യ == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    എങ്കിൽ (തിരയൽ_Path(ശൂന്യ, file, ".dll", വലുപ്പം path, path, ശൂന്യ))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    എങ്കിൽ (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        പോകുക the_end;
    }

    എങ്കിൽ (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    എങ്കിൽ (ശൂന്യ == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        പോകുക the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    വേണ്ടി (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    എങ്കിൽ (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    എങ്കിൽ (p)
        tcc_free(p);
    എങ്കിൽ (fp)
        fclose(fp);
    എങ്കിൽ (op)
        fclose(op);
    തിരികെ ret;
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

#എങ്കിൽ !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_cross(അക്ഷരം **argv, പൂർണ്ണസംഖ്യ option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    തിരികെ 1;
}

#അല്ലെങ്കിൽ
#ifdef _WIN32
#അന്തര്ഭാവ <process.h>

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
സ്ഥിതം അക്ഷരം *quote_win32(സ്ഥിരം അക്ഷരം *s)
{
    അക്ഷരം *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    പൂർണ്ണസംഖ്യ cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    വേണ്ടി (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        എങ്കിൽ (*s == '\\' || *s == '"')
            *o++ = '\\';
        അല്ലെങ്കിൽ
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    എങ്കിൽ (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } അല്ലെങ്കിൽ {
        o -= cbs;
    }

    *o = 0;
    തിരികെ r; /* don't bother with realloc(r, o-r+1) */
}

സ്ഥിതം പൂർണ്ണസംഖ്യ execvp_win32(സ്ഥിരം അക്ഷരം *prog, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ ret; അക്ഷരം **p;
    /* replace all " by \" */
    വേണ്ടി (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (സ്ഥിരം അക്ഷരം *സ്ഥിരം*)argv);
    എങ്കിൽ (-1 == ret)
        തിരികെ ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_cross(അക്ഷരം **argv, പൂർണ്ണസംഖ്യ target)
{
    അക്ഷരം program[4096];
    അക്ഷരം *a0 = argv[0];
    പൂർണ്ണസംഖ്യ prefix = tcc_basename(a0) - a0;

    snprintf(program, വലുപ്പം program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    എങ്കിൽ (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    തിരികെ 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
സ്ഥിരം പൂർണ്ണസംഖ്യ _CRT_glob = 1;
#ifndef _CRT_glob
സ്ഥിരം പൂർണ്ണസംഖ്യ _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

സ്ഥിതം അക്ഷരം *escape_target_dep(സ്ഥിരം അക്ഷരം *s) {
    അക്ഷരം *res = tcc_malloc(strlen(s) * 2 + 1);
    പൂർണ്ണസംഖ്യ j;
    വേണ്ടി (j = 0; *s; s++, j++) {
        എങ്കിൽ (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    തിരികെ res;
}

ST_FUNC പൂർണ്ണസംഖ്യ gen_makedeps(TCCState *s1, സ്ഥിരം അക്ഷരം *target, സ്ഥിരം അക്ഷരം *filename)
{
    FILE *depout;
    അക്ഷരം buf[1024];
    അക്ഷരം **escaped_targets;
    പൂർണ്ണസംഖ്യ i, k, അക്കം_targets;

    എങ്കിൽ (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, വലുപ്പം buf, "%.*s.d",
            (പൂർണ്ണസംഖ്യ)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    എങ്കിൽ(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    അല്ലെങ്കിൽ
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    എങ്കിൽ (!depout)
        തിരികെ tcc_error_noabort("could not open '%s'", filename);
    എങ്കിൽ (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * വലുപ്പം(*escaped_targets));
    അക്കം_targets = 0;
    വേണ്ടി (i = 0; i<s1->nb_target_deps; ++i) {
        വേണ്ടി (k = 0; k < i; ++k)
            എങ്കിൽ (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                പോകുക next;
        escaped_targets[അക്കം_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    വേണ്ടി (i = 0; i < അക്കം_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    എങ്കിൽ (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        വേണ്ടി (i = 1; i < അക്കം_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    വേണ്ടി (i = 0; i < അക്കം_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    തിരികെ 0;
}

/* -------------------------------------------------------------- */
