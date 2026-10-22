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

#অন্তর্ভাব "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

প্রকারলেখ কাঠামো {
    অক্ষর ar_name[16];
    অক্ষর ar_date[12];
    অক্ষর ar_uid[6];
    অক্ষর ar_gid[6];
    অক্ষর ar_mode[8];
    অক্ষর ar_আকার[10];
    অক্ষর ar_fmag[2];
} ArHdr;

স্থির unsigned long le2belong(unsigned long ul) {
    ফেরত ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

স্থির পূর্ণসংখ্যা ar_usage(পূর্ণসংখ্যা ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    ফেরত ret;
}

ST_FUNC পূর্ণসংখ্যা tcc_tool_ar(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    স্থির ধ্রুবক ArHdr arhdr_init = {
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

    FILE *fi, *fh = ফাঁকা, *fo = ফাঁকা;
    ধ্রুবক অক্ষর *created_file = ফাঁকা; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    পূর্ণসংখ্যা i, fsize, i_lib, i_obj;
    অক্ষর *buf, *shstr, *symtab, *strtab;
    পূর্ণসংখ্যা symtabsize = 0;//, strtabsize = 0;
    অক্ষর *anames = ফাঁকা;
    পূর্ণসংখ্যা *afpos = ফাঁকা;
    পূর্ণসংখ্যা istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    অক্ষর tfile[260], stmp[20];
    অক্ষর *file, *name;
    পূর্ণসংখ্যা ret = 2;
    ধ্রুবক অক্ষর *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    পূর্ণসংখ্যা extract = 0;
    পূর্ণসংখ্যা table = 0;
    পূর্ণসংখ্যা verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    জন্য (i = 1; i < argc; i++) {
        ধ্রুবক অক্ষর *a = argv[i];
        যদি (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        যদি ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            যদি (strpbrk(a, ops_conflict))
                ret = 1;
            যদি (strchr(a, 'x'))
                extract = 1;
            যদি (strchr(a, 't'))
                table = 1;
            যদি (strchr(a, 'v'))
                verbose = 1;
        } অন্যথা {  // lib or obj files: don't abort - keep validating all args.
            যদি (!i_lib)  // first file is the lib
                i_lib = i;
            অন্যথা যদি (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    যদি (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    যদি (ret == 1)
        ফেরত ar_usage(ret);

    যদি (extract || table) {
        যদি ((fh = fopen(argv[i_lib], "rb")) == ফাঁকা)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            যাও finish;
        }
        fread(stmp, 1, 8, fh);
	যদি (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            যাও finish;
	}
	যখন (fread(&arhdr, 1, আকার(arhdr), fh) == আকার(arhdr)) {
	    অক্ষর *p, *e;

	    যদি (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		যাও no_ar;
	    p = arhdr.ar_name;
	    জন্য (e = p + আকার arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_আকার[আকার arhdr.ar_আকার-1] = 0;
	    fsize = atoi(arhdr.ar_আকার);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    যদি (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		যদি (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        যদি (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		যদি (extract) {
		    যদি ((fo = fopen(arhdr.ar_name, "wb")) == ফাঁকা)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			যাও finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            যদি (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	যদি (fh)
		fclose(fh);
	ফেরত ret;
    }

    যদি ((fh = fopen(argv[i_lib], "wb")) == ফাঁকা)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        যাও the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    যদি ((fo = fopen(tfile, "wb+")) == ফাঁকা)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        যাও the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(ফাঁকা, funcmax * আকার *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    যখন (i_obj < argc)
    {
        যদি (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            চালু;
        }
        যদি ((fi = fopen(argv[i_obj], "rb")) == ফাঁকা) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            যাও the_end;
        }
        যদি (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        যদি (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            যাও the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (অক্ষর *)(buf + shdr->sh_offset);
        symtab = strtab = ফাঁকা;
        জন্য (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            যদি (!shdr->sh_offset)
                চালু;
            যদি (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (অক্ষর *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_আকার;
            }
            যদি (shdr->sh_type == SHT_STRTAB)
            {
                যদি (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (অক্ষর *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        যদি (symtab && strtab)
        {
            পূর্ণসংখ্যা nsym = symtabsize / আকার(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            জন্য (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * আকার(ElfW(Sym)));
                যদি (sym->st_shndx &&
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
                    যদি (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * আকার *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        জন্য (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        যদি (istrlen >= আকার(arhdro.ar_name))
            istrlen = আকার(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', আকার(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_আকার, stmp, 10);
        fwrite(&arhdro, আকার(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + আকার(arhdro));
        যদি (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + আকার(arhdr) + strpos + (funccnt+1) * আকার(পূর্ণসংখ্যা);
    fpos = 0;
    যদি ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    যদি (!funccnt) {
        ret = 0;
        যাও the_end;
    }
    sprintf(stmp, "%-10d", (পূর্ণসংখ্যা)(strpos + (funccnt+1) * আকার(পূর্ণসংখ্যা)) + fpos);
    memcpy(&arhdr.ar_আকার, stmp, 10);
    fwrite(&arhdr, আকার(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    জন্য (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * আকার(পূর্ণসংখ্যা), 1, fh);
    fwrite(anames, strpos, 1, fh);
    যদি (fpos)
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
    যদি (anames)
        tcc_free(anames);
    যদি (afpos)
        tcc_free(afpos);
    যদি (fh)
        fclose(fh);
    যদি (created_file && ret != 0)
        remove(created_file);
    যদি (fo)
        fclose(fo), remove(tfile);
    ফেরত ret;
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

ST_FUNC পূর্ণসংখ্যা tcc_tool_impdef(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    পূর্ণসংখ্যা ret, v, i;
    অক্ষর infile[260];
    অক্ষর outfile[260];

    ধ্রুবক অক্ষর *file;
    অক্ষর *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    অক্ষর path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = ফাঁকা;
    ret = 1;
    p = ফাঁকা;
    v = 0;

    জন্য (i = 1; i < argc; ++i) {
        ধ্রুবক অক্ষর *a = argv[i];
        যদি ('-' == a[0]) {
            যদি (0 == strcmp(a, "-v")) {
                v = 1;
            } অন্যথা যদি (0 == strcmp(a, "-o")) {
                যদি (++i == argc)
                    যাও usage;
                strcpy(outfile, argv[i]);
            } অন্যথা
                যাও usage;
        } অন্যথা যদি (0 == infile[0])
            strcpy(infile, a);
        অন্যথা
            যাও usage;
    }

    যদি (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        যাও the_end;
    }

    যদি (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        যদি (ফাঁকা == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    যদি (অনুসন্ধান_Path(ফাঁকা, file, ".dll", আকার path, path, ফাঁকা))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    যদি (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        যাও the_end;
    }

    যদি (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    যদি (ফাঁকা == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        যাও the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    জন্য (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    যদি (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    যদি (p)
        tcc_free(p);
    যদি (fp)
        fclose(fp);
    যদি (op)
        fclose(op);
    ফেরত ret;
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

#যদি !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC পূর্ণসংখ্যা tcc_tool_cross(অক্ষর **argv, পূর্ণসংখ্যা option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    ফেরত 1;
}

#অন্যথা
#ifdef _WIN32
#অন্তর্ভাব <process.h>

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
স্থির অক্ষর *quote_win32(ধ্রুবক অক্ষর *s)
{
    অক্ষর *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    পূর্ণসংখ্যা cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    জন্য (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        যদি (*s == '\\' || *s == '"')
            *o++ = '\\';
        অন্যথা
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    যদি (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } অন্যথা {
        o -= cbs;
    }

    *o = 0;
    ফেরত r; /* don't bother with realloc(r, o-r+1) */
}

স্থির পূর্ণসংখ্যা execvp_win32(ধ্রুবক অক্ষর *prog, অক্ষর **argv)
{
    পূর্ণসংখ্যা ret; অক্ষর **p;
    /* replace all " by \" */
    জন্য (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ধ্রুবক অক্ষর *ধ্রুবক*)argv);
    যদি (-1 == ret)
        ফেরত ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC পূর্ণসংখ্যা tcc_tool_cross(অক্ষর **argv, পূর্ণসংখ্যা target)
{
    অক্ষর program[4096];
    অক্ষর *a0 = argv[0];
    পূর্ণসংখ্যা prefix = tcc_basename(a0) - a0;

    snprintf(program, আকার program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    যদি (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    ফেরত 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
ধ্রুবক পূর্ণসংখ্যা _CRT_glob = 1;
#ifndef _CRT_glob
ধ্রুবক পূর্ণসংখ্যা _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

স্থির অক্ষর *escape_target_dep(ধ্রুবক অক্ষর *s) {
    অক্ষর *res = tcc_malloc(strlen(s) * 2 + 1);
    পূর্ণসংখ্যা j;
    জন্য (j = 0; *s; s++, j++) {
        যদি (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    ফেরত res;
}

ST_FUNC পূর্ণসংখ্যা gen_makedeps(TCCState *s1, ধ্রুবক অক্ষর *target, ধ্রুবক অক্ষর *filename)
{
    FILE *depout;
    অক্ষর buf[1024];
    অক্ষর **escaped_targets;
    পূর্ণসংখ্যা i, k, অঙ্ক_targets;

    যদি (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, আকার buf, "%.*s.d",
            (পূর্ণসংখ্যা)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    যদি(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    অন্যথা
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    যদি (!depout)
        ফেরত tcc_error_noabort("could not open '%s'", filename);
    যদি (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * আকার(*escaped_targets));
    অঙ্ক_targets = 0;
    জন্য (i = 0; i<s1->nb_target_deps; ++i) {
        জন্য (k = 0; k < i; ++k)
            যদি (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                যাও পরবর্তী;
        escaped_targets[অঙ্ক_targets++] = escape_target_dep(s1->target_deps[i]);
    পরবর্তী:;
    }

    fprintf(depout, "%s:", target);
    জন্য (i = 0; i < অঙ্ক_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    যদি (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        জন্য (i = 1; i < অঙ্ক_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    জন্য (i = 0; i < অঙ্ক_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    ফেরত 0;
}

/* -------------------------------------------------------------- */
