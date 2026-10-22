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

#شامل "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

تعریفنوع ساختار {
    نویسه ar_name[16];
    نویسه ar_date[12];
    نویسه ar_uid[6];
    نویسه ar_gid[6];
    نویسه ar_mode[8];
    نویسه ar_size[10];
    نویسه ar_fmag[2];
} ArHdr;

ایستا unsigned long le2belong(unsigned long ul) {
    بازگشت ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

ایستا صحیح ar_usage(صحیح ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    بازگشت ret;
}

ST_FUNC صحیح tcc_tool_ar(صحیح argc, نویسه **argv)
{
    ایستا ثابت ArHdr arhdr_init = {
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

    FILE *fi, *fh = پوچ, *fo = پوچ;
    ثابت نویسه *created_file = پوچ; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    صحیح i, fsize, i_lib, i_obj;
    نویسه *buf, *shstr, *symtab, *strtab;
    صحیح symtabsize = 0;//, strtabsize = 0;
    نویسه *anames = پوچ;
    صحیح *afpos = پوچ;
    صحیح istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    نویسه tfile[260], stmp[20];
    نویسه *file, *name;
    صحیح ret = 2;
    ثابت نویسه *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    صحیح extract = 0;
    صحیح table = 0;
    صحیح verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    برای (i = 1; i < argc; i++) {
        ثابت نویسه *a = argv[i];
        اگر (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        اگر ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            اگر (strpbrk(a, ops_conflict))
                ret = 1;
            اگر (strchr(a, 'x'))
                extract = 1;
            اگر (strchr(a, 't'))
                table = 1;
            اگر (strchr(a, 'v'))
                verbose = 1;
        } وگرنه {  // lib or obj files: don't abort - keep validating all args.
            اگر (!i_lib)  // first file is the lib
                i_lib = i;
            وگرنه اگر (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    اگر (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    اگر (ret == 1)
        بازگشت ar_usage(ret);

    اگر (extract || table) {
        اگر ((fh = fopen(argv[i_lib], "rb")) == پوچ)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            برو finish;
        }
        fread(stmp, 1, 8, fh);
	اگر (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            برو finish;
	}
	وقتی (fread(&arhdr, 1, اندازه(arhdr), fh) == اندازه(arhdr)) {
	    نویسه *p, *e;

	    اگر (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		برو no_ar;
	    p = arhdr.ar_name;
	    برای (e = p + اندازه arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[اندازه arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    اگر (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		اگر (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        اگر (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		اگر (extract) {
		    اگر ((fo = fopen(arhdr.ar_name, "wb")) == پوچ)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			برو finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            اگر (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	اگر (fh)
		fclose(fh);
	بازگشت ret;
    }

    اگر ((fh = fopen(argv[i_lib], "wb")) == پوچ)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        برو the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    اگر ((fo = fopen(tfile, "wb+")) == پوچ)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        برو the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(پوچ, funcmax * اندازه *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    وقتی (i_obj < argc)
    {
        اگر (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            ادامه;
        }
        اگر ((fi = fopen(argv[i_obj], "rb")) == پوچ) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            برو the_end;
        }
        اگر (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        اگر (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            برو the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (نویسه *)(buf + shdr->sh_offset);
        symtab = strtab = پوچ;
        برای (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            اگر (!shdr->sh_offset)
                ادامه;
            اگر (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (نویسه *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            اگر (shdr->sh_type == SHT_STRTAB)
            {
                اگر (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (نویسه *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        اگر (symtab && strtab)
        {
            صحیح nsym = symtabsize / اندازه(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            برای (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * اندازه(ElfW(Sym)));
                اگر (sym->st_shndx &&
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
                    اگر (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * اندازه *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        برای (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        اگر (istrlen >= اندازه(arhdro.ar_name))
            istrlen = اندازه(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', اندازه(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, اندازه(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + اندازه(arhdro));
        اگر (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + اندازه(arhdr) + strpos + (funccnt+1) * اندازه(صحیح);
    fpos = 0;
    اگر ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    اگر (!funccnt) {
        ret = 0;
        برو the_end;
    }
    sprintf(stmp, "%-10d", (صحیح)(strpos + (funccnt+1) * اندازه(صحیح)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, اندازه(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    برای (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * اندازه(صحیح), 1, fh);
    fwrite(anames, strpos, 1, fh);
    اگر (fpos)
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
    اگر (anames)
        tcc_free(anames);
    اگر (afpos)
        tcc_free(afpos);
    اگر (fh)
        fclose(fh);
    اگر (created_file && ret != 0)
        remove(created_file);
    اگر (fo)
        fclose(fo), remove(tfile);
    بازگشت ret;
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

ST_FUNC صحیح tcc_tool_impdef(صحیح argc, نویسه **argv)
{
    صحیح ret, v, i;
    نویسه infile[260];
    نویسه outfile[260];

    ثابت نویسه *file;
    نویسه *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    نویسه path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = پوچ;
    ret = 1;
    p = پوچ;
    v = 0;

    برای (i = 1; i < argc; ++i) {
        ثابت نویسه *a = argv[i];
        اگر ('-' == a[0]) {
            اگر (0 == strcmp(a, "-v")) {
                v = 1;
            } وگرنه اگر (0 == strcmp(a, "-o")) {
                اگر (++i == argc)
                    برو usage;
                strcpy(outfile, argv[i]);
            } وگرنه
                برو usage;
        } وگرنه اگر (0 == infile[0])
            strcpy(infile, a);
        وگرنه
            برو usage;
    }

    اگر (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        برو the_end;
    }

    اگر (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        اگر (پوچ == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    اگر (جستجو_Path(پوچ, file, ".dll", اندازه path, path, پوچ))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    اگر (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        برو the_end;
    }

    اگر (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    اگر (پوچ == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        برو the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    برای (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    اگر (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    اگر (p)
        tcc_free(p);
    اگر (fp)
        fclose(fp);
    اگر (op)
        fclose(op);
    بازگشت ret;
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

#اگر !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC صحیح tcc_tool_cross(نویسه **argv, صحیح option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    بازگشت 1;
}

#وگرنه
#ifdef _WIN32
#شامل <process.h>

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
ایستا نویسه *quote_win32(ثابت نویسه *s)
{
    نویسه *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    صحیح cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    برای (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        اگر (*s == '\\' || *s == '"')
            *o++ = '\\';
        وگرنه
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    اگر (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } وگرنه {
        o -= cbs;
    }

    *o = 0;
    بازگشت r; /* don't bother with realloc(r, o-r+1) */
}

ایستا صحیح execvp_win32(ثابت نویسه *prog, نویسه **argv)
{
    صحیح ret; نویسه **p;
    /* replace all " by \" */
    برای (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ثابت نویسه *ثابت*)argv);
    اگر (-1 == ret)
        بازگشت ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC صحیح tcc_tool_cross(نویسه **argv, صحیح target)
{
    نویسه program[4096];
    نویسه *a0 = argv[0];
    صحیح prefix = tcc_basename(a0) - a0;

    snprintf(program, اندازه program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    اگر (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    بازگشت 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
ثابت صحیح _CRT_glob = 1;
#ifndef _CRT_glob
ثابت صحیح _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

ایستا نویسه *escape_target_dep(ثابت نویسه *s) {
    نویسه *res = tcc_malloc(strlen(s) * 2 + 1);
    صحیح j;
    برای (j = 0; *s; s++, j++) {
        اگر (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    بازگشت res;
}

ST_FUNC صحیح gen_makedeps(TCCState *s1, ثابت نویسه *target, ثابت نویسه *filename)
{
    FILE *depout;
    نویسه buf[1024];
    نویسه **escaped_targets;
    صحیح i, k, رقم_targets;

    اگر (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, اندازه buf, "%.*s.d",
            (صحیح)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    اگر(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    وگرنه
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    اگر (!depout)
        بازگشت tcc_error_noabort("could not open '%s'", filename);
    اگر (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * اندازه(*escaped_targets));
    رقم_targets = 0;
    برای (i = 0; i<s1->nb_target_deps; ++i) {
        برای (k = 0; k < i; ++k)
            اگر (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                برو next;
        escaped_targets[رقم_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    برای (i = 0; i < رقم_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    اگر (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        برای (i = 1; i < رقم_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    برای (i = 0; i < رقم_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    بازگشت 0;
}

/* -------------------------------------------------------------- */
