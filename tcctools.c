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

#include "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

typedef struct {
    char ar_name[16];
    char ar_date[12];
    char ar_uid[6];
    char ar_gid[6];
    char ar_mode[8];
    char ar_size[10];
    char ar_fmag[2];
} ArHdr;

static unsigned long le2belong(unsigned long ul) {
    返回 ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

static 整数 ar_usage(整数 ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    返回 ret;
}

ST_FUNC 整数 tcc_tool_ar(整数 argc, char **argv)
{
    static const ArHdr arhdr_init = {
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

    FILE *fi, *fh = NULL, *fo = NULL;
    const char *created_file = NULL; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    整数 i, fsize, i_lib, i_obj;
    char *buf, *shstr, *symtab, *strtab;
    整数 symtabsize = 0;//, strtabsize = 0;
    char *anames = NULL;
    整数 *afpos = NULL;
    整数 istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    char tfile[260], stmp[20];
    char *file, *name;
    整数 ret = 2;
    const char *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    整数 extract = 0;
    整数 table = 0;
    整数 verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    为 (i = 1; i < argc; i++) {
        const char *a = argv[i];
        如果 (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        如果 ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            如果 (strpbrk(a, ops_conflict))
                ret = 1;
            如果 (strchr(a, 'x'))
                extract = 1;
            如果 (strchr(a, 't'))
                table = 1;
            如果 (strchr(a, 'v'))
                verbose = 1;
        } 否则 {  // lib or obj files: don't abort - keep validating all args.
            如果 (!i_lib)  // first file is the lib
                i_lib = i;
            否则 如果 (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    如果 (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    如果 (ret == 1)
        返回 ar_usage(ret);

    如果 (extract || table) {
        如果 ((fh = fopen(argv[i_lib], "rb")) == NULL)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            goto finish;
        }
        fread(stmp, 1, 8, fh);
	如果 (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            goto finish;
	}
	当 (fread(&arhdr, 1, sizeof(arhdr), fh) == sizeof(arhdr)) {
	    char *p, *e;

	    如果 (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		goto no_ar;
	    p = arhdr.ar_name;
	    为 (e = p + sizeof arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[sizeof arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    如果 (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		如果 (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        如果 (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		如果 (extract) {
		    如果 ((fo = fopen(arhdr.ar_name, "wb")) == NULL)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			goto finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            如果 (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	如果 (fh)
		fclose(fh);
	返回 ret;
    }

    如果 ((fh = fopen(argv[i_lib], "wb")) == NULL)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        goto the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    如果 ((fo = fopen(tfile, "wb+")) == NULL)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        goto the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(NULL, funcmax * sizeof *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    当 (i_obj < argc)
    {
        如果 (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            continue;
        }
        如果 ((fi = fopen(argv[i_obj], "rb")) == NULL) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            goto the_end;
        }
        如果 (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        如果 (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            goto the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (char *)(buf + shdr->sh_offset);
        symtab = strtab = NULL;
        为 (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            如果 (!shdr->sh_offset)
                continue;
            如果 (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (char *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            如果 (shdr->sh_type == SHT_STRTAB)
            {
                如果 (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (char *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        如果 (symtab && strtab)
        {
            整数 nsym = symtabsize / sizeof(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            为 (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * sizeof(ElfW(Sym)));
                如果 (sym->st_shndx &&
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
                    如果 (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * sizeof *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        为 (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        如果 (istrlen >= sizeof(arhdro.ar_name))
            istrlen = sizeof(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', sizeof(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, sizeof(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + sizeof(arhdro));
        如果 (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + sizeof(arhdr) + strpos + (funccnt+1) * sizeof(整数);
    fpos = 0;
    如果 ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    如果 (!funccnt) {
        ret = 0;
        goto the_end;
    }
    sprintf(stmp, "%-10d", (整数)(strpos + (funccnt+1) * sizeof(整数)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, sizeof(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    为 (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * sizeof(整数), 1, fh);
    fwrite(anames, strpos, 1, fh);
    如果 (fpos)
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
    如果 (anames)
        tcc_free(anames);
    如果 (afpos)
        tcc_free(afpos);
    如果 (fh)
        fclose(fh);
    如果 (created_file && ret != 0)
        remove(created_file);
    如果 (fo)
        fclose(fo), remove(tfile);
    返回 ret;
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

ST_FUNC 整数 tcc_tool_impdef(整数 argc, char **argv)
{
    整数 ret, v, i;
    char infile[260];
    char outfile[260];

    const char *file;
    char *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    char path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = NULL;
    ret = 1;
    p = NULL;
    v = 0;

    为 (i = 1; i < argc; ++i) {
        const char *a = argv[i];
        如果 ('-' == a[0]) {
            如果 (0 == strcmp(a, "-v")) {
                v = 1;
            } 否则 如果 (0 == strcmp(a, "-o")) {
                如果 (++i == argc)
                    goto usage;
                strcpy(outfile, argv[i]);
            } 否则
                goto usage;
        } 否则 如果 (0 == infile[0])
            strcpy(infile, a);
        否则
            goto usage;
    }

    如果 (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        goto the_end;
    }

    如果 (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        如果 (NULL == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    如果 (SearchPath(NULL, file, ".dll", sizeof path, path, NULL))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    如果 (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        goto the_end;
    }

    如果 (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    如果 (NULL == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        goto the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    为 (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    如果 (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    如果 (p)
        tcc_free(p);
    如果 (fp)
        fclose(fp);
    如果 (op)
        fclose(op);
    返回 ret;
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

#如果 !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC 整数 tcc_tool_cross(char **argv, 整数 option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    返回 1;
}

#否则
#ifdef _WIN32
#include <process.h>

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
static char *quote_win32(const char *s)
{
    char *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    整数 cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    为 (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        如果 (*s == '\\' || *s == '"')
            *o++ = '\\';
        否则
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    如果 (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } 否则 {
        o -= cbs;
    }

    *o = 0;
    返回 r; /* don't bother with realloc(r, o-r+1) */
}

static 整数 execvp_win32(const char *prog, char **argv)
{
    整数 ret; char **p;
    /* replace all " by \" */
    为 (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (const char *const*)argv);
    如果 (-1 == ret)
        返回 ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC 整数 tcc_tool_cross(char **argv, 整数 target)
{
    char program[4096];
    char *a0 = argv[0];
    整数 prefix = tcc_basename(a0) - a0;

    snprintf(program, sizeof program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    如果 (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    返回 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
const 整数 _CRT_glob = 1;
#ifndef _CRT_glob
const 整数 _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

static char *escape_target_dep(const char *s) {
    char *res = tcc_malloc(strlen(s) * 2 + 1);
    整数 j;
    为 (j = 0; *s; s++, j++) {
        如果 (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    返回 res;
}

ST_FUNC 整数 gen_makedeps(TCCState *s1, const char *target, const char *filename)
{
    FILE *depout;
    char buf[1024];
    char **escaped_targets;
    整数 i, k, num_targets;

    如果 (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, sizeof buf, "%.*s.d",
            (整数)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    如果(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    否则
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    如果 (!depout)
        返回 tcc_error_noabort("could not open '%s'", filename);
    如果 (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * sizeof(*escaped_targets));
    num_targets = 0;
    为 (i = 0; i<s1->nb_target_deps; ++i) {
        为 (k = 0; k < i; ++k)
            如果 (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                goto next;
        escaped_targets[num_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    为 (i = 0; i < num_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    如果 (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        为 (i = 1; i < num_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    为 (i = 0; i < num_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    返回 0;
}

/* -------------------------------------------------------------- */
