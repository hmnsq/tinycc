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

typedef sa_nracanaa {
    var_na ar_name[16];
    var_na ar_date[12];
    var_na ar_uid[6];
    var_na ar_gid[6];
    var_na ar_mode[8];
    var_na ar_size[10];
    var_na ar_fmag[2];
} ArHdr;

static unsigned long le2belong(unsigned long ul) {
    ལོག ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

static ཧྲིལ ar_usage(ཧྲིལ ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    ལོག ret;
}

ST_FUNC ཧྲིལ tcc_tool_ar(ཧྲིལ argc, var_na **argv)
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
    const var_na *created_file = NULL; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    ཧྲིལ i, fsize, i_lib, i_obj;
    var_na *buf, *shstr, *symtab, *strtab;
    ཧྲིལ symtabsize = 0;//, strtabsize = 0;
    var_na *anames = NULL;
    ཧྲིལ *afpos = NULL;
    ཧྲིལ istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    var_na tfile[260], stmp[20];
    var_na *file, *name;
    ཧྲིལ ret = 2;
    const var_na *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    ཧྲིལ extract = 0;
    ཧྲིལ table = 0;
    ཧྲིལ verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    དོན་ལུ (i = 1; i < argc; i++) {
        const var_na *a = argv[i];
        གལ་སྲིད (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        གལ་སྲིད ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            གལ་སྲིད (strpbrk(a, ops_conflict))
                ret = 1;
            གལ་སྲིད (strchr(a, 'x'))
                extract = 1;
            གལ་སྲིད (strchr(a, 't'))
                table = 1;
            གལ་སྲིད (strchr(a, 'v'))
                verbose = 1;
        } དེ་མིན {  // lib or obj files: don't abort - keep validating all args.
            གལ་སྲིད (!i_lib)  // first file is the lib
                i_lib = i;
            དེ་མིན གལ་སྲིད (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    གལ་སྲིད (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    གལ་སྲིད (ret == 1)
        ལོག ar_usage(ret);

    གལ་སྲིད (extract || table) {
        གལ་སྲིད ((fh = fopen(argv[i_lib], "rb")) == NULL)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            goto finish;
        }
        fread(stmp, 1, 8, fh);
	གལ་སྲིད (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            goto finish;
	}
	སྐབས (fread(&arhdr, 1, parimaa_na(arhdr), fh) == parimaa_na(arhdr)) {
	    var_na *p, *e;

	    གལ་སྲིད (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		goto no_ar;
	    p = arhdr.ar_name;
	    དོན་ལུ (e = p + parimaa_na arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[parimaa_na arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    གལ་སྲིད (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		གལ་སྲིད (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        གལ་སྲིད (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		གལ་སྲིད (extract) {
		    གལ་སྲིད ((fo = fopen(arhdr.ar_name, "wb")) == NULL)
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
            གལ་སྲིད (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	གལ་སྲིད (fh)
		fclose(fh);
	ལོག ret;
    }

    གལ་སྲིད ((fh = fopen(argv[i_lib], "wb")) == NULL)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        goto the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    གལ་སྲིད ((fo = fopen(tfile, "wb+")) == NULL)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        goto the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(NULL, funcmax * parimaa_na *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    སྐབས (i_obj < argc)
    {
        གལ་སྲིད (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            continue;
        }
        གལ་སྲིད ((fi = fopen(argv[i_obj], "rb")) == NULL) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            goto the_end;
        }
        གལ་སྲིད (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        གལ་སྲིད (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            goto the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (var_na *)(buf + shdr->sh_offset);
        symtab = strtab = NULL;
        དོན་ལུ (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            གལ་སྲིད (!shdr->sh_offset)
                continue;
            གལ་སྲིད (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (var_na *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            གལ་སྲིད (shdr->sh_type == SHT_STRTAB)
            {
                གལ་སྲིད (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (var_na *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        གལ་སྲིད (symtab && strtab)
        {
            ཧྲིལ nsym = symtabsize / parimaa_na(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            དོན་ལུ (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * parimaa_na(ElfW(Sym)));
                གལ་སྲིད (sym->st_shndx &&
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
                    གལ་སྲིད (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * parimaa_na *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        དོན་ལུ (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        གལ་སྲིད (istrlen >= parimaa_na(arhdro.ar_name))
            istrlen = parimaa_na(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', parimaa_na(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, parimaa_na(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + parimaa_na(arhdro));
        གལ་སྲིད (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + parimaa_na(arhdr) + strpos + (funccnt+1) * parimaa_na(ཧྲིལ);
    fpos = 0;
    གལ་སྲིད ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    གལ་སྲིད (!funccnt) {
        ret = 0;
        goto the_end;
    }
    sprintf(stmp, "%-10d", (ཧྲིལ)(strpos + (funccnt+1) * parimaa_na(ཧྲིལ)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, parimaa_na(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    དོན་ལུ (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * parimaa_na(ཧྲིལ), 1, fh);
    fwrite(anames, strpos, 1, fh);
    གལ་སྲིད (fpos)
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
    གལ་སྲིད (anames)
        tcc_free(anames);
    གལ་སྲིད (afpos)
        tcc_free(afpos);
    གལ་སྲིད (fh)
        fclose(fh);
    གལ་སྲིད (created_file && ret != 0)
        remove(created_file);
    གལ་སྲིད (fo)
        fclose(fo), remove(tfile);
    ལོག ret;
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

ST_FUNC ཧྲིལ tcc_tool_impdef(ཧྲིལ argc, var_na **argv)
{
    ཧྲིལ ret, v, i;
    var_na infile[260];
    var_na outfile[260];

    const var_na *file;
    var_na *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    var_na path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = NULL;
    ret = 1;
    p = NULL;
    v = 0;

    དོན་ལུ (i = 1; i < argc; ++i) {
        const var_na *a = argv[i];
        གལ་སྲིད ('-' == a[0]) {
            གལ་སྲིད (0 == strcmp(a, "-v")) {
                v = 1;
            } དེ་མིན གལ་སྲིད (0 == strcmp(a, "-o")) {
                གལ་སྲིད (++i == argc)
                    goto usage;
                strcpy(outfile, argv[i]);
            } དེ་མིན
                goto usage;
        } དེ་མིན གལ་སྲིད (0 == infile[0])
            strcpy(infile, a);
        དེ་མིན
            goto usage;
    }

    གལ་སྲིད (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        goto the_end;
    }

    གལ་སྲིད (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        གལ་སྲིད (NULL == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    གལ་སྲིད (SearchPath(NULL, file, ".dll", parimaa_na path, path, NULL))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    གལ་སྲིད (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        goto the_end;
    }

    གལ་སྲིད (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    གལ་སྲིད (NULL == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        goto the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    དོན་ལུ (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    གལ་སྲིད (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    གལ་སྲིད (p)
        tcc_free(p);
    གལ་སྲིད (fp)
        fclose(fp);
    གལ་སྲིད (op)
        fclose(op);
    ལོག ret;
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

#གལ་སྲིད !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC ཧྲིལ tcc_tool_cross(var_na **argv, ཧྲིལ option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    ལོག 1;
}

#དེ་མིན
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
static var_na *quote_win32(const var_na *s)
{
    var_na *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    ཧྲིལ cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    དོན་ལུ (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        གལ་སྲིད (*s == '\\' || *s == '"')
            *o++ = '\\';
        དེ་མིན
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    གལ་སྲིད (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } དེ་མིན {
        o -= cbs;
    }

    *o = 0;
    ལོག r; /* don't bother with realloc(r, o-r+1) */
}

static ཧྲིལ execvp_win32(const var_na *prog, var_na **argv)
{
    ཧྲིལ ret; var_na **p;
    /* replace all " by \" */
    དོན་ལུ (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (const var_na *const*)argv);
    གལ་སྲིད (-1 == ret)
        ལོག ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC ཧྲིལ tcc_tool_cross(var_na **argv, ཧྲིལ target)
{
    var_na program[4096];
    var_na *a0 = argv[0];
    ཧྲིལ prefix = tcc_basename(a0) - a0;

    snprintf(program, parimaa_na program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    གལ་སྲིད (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    ལོག 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
const ཧྲིལ _CRT_glob = 1;
#ifndef _CRT_glob
const ཧྲིལ _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

static var_na *escape_target_dep(const var_na *s) {
    var_na *res = tcc_malloc(strlen(s) * 2 + 1);
    ཧྲིལ j;
    དོན་ལུ (j = 0; *s; s++, j++) {
        གལ་སྲིད (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    ལོག res;
}

ST_FUNC ཧྲིལ gen_makedeps(TCCState *s1, const var_na *target, const var_na *filename)
{
    FILE *depout;
    var_na buf[1024];
    var_na **escaped_targets;
    ཧྲིལ i, k, num_targets;

    གལ་སྲིད (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, parimaa_na buf, "%.*s.d",
            (ཧྲིལ)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    གལ་སྲིད(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    དེ་མིན
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    གལ་སྲིད (!depout)
        ལོག tcc_error_noabort("could not open '%s'", filename);
    གལ་སྲིད (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * parimaa_na(*escaped_targets));
    num_targets = 0;
    དོན་ལུ (i = 0; i<s1->nb_target_deps; ++i) {
        དོན་ལུ (k = 0; k < i; ++k)
            གལ་སྲིད (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                goto next;
        escaped_targets[num_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    དོན་ལུ (i = 0; i < num_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    གལ་སྲིད (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        དོན་ལུ (i = 1; i < num_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    དོན་ལུ (i = 0; i < num_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    ལོག 0;
}

/* -------------------------------------------------------------- */
