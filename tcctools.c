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

#அந்தர்பாவ "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

வகைவரை கட்டமைப்பு {
    எழுத்து ar_name[16];
    எழுத்து ar_date[12];
    எழுத்து ar_uid[6];
    எழுத்து ar_gid[6];
    எழுத்து ar_mode[8];
    எழுத்து ar_size[10];
    எழுத்து ar_fmag[2];
} ArHdr;

நிலையான unsigned long le2belong(unsigned long ul) {
    திரும்பு ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

நிலையான முழு ar_usage(முழு ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    திரும்பு ret;
}

ST_FUNC முழு tcc_tool_ar(முழு argc, எழுத்து **argv)
{
    நிலையான மாறிலி ArHdr arhdr_init = {
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

    FILE *fi, *fh = வெற்று, *fo = வெற்று;
    மாறிலி எழுத்து *created_file = வெற்று; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    முழு i, fsize, i_lib, i_obj;
    எழுத்து *buf, *shstr, *symtab, *strtab;
    முழு symtabsize = 0;//, strtabsize = 0;
    எழுத்து *anames = வெற்று;
    முழு *afpos = வெற்று;
    முழு istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    எழுத்து tfile[260], stmp[20];
    எழுத்து *file, *name;
    முழு ret = 2;
    மாறிலி எழுத்து *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    முழு extract = 0;
    முழு table = 0;
    முழு verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    க்கு (i = 1; i < argc; i++) {
        மாறிலி எழுத்து *a = argv[i];
        எனில் (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        எனில் ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            எனில் (strpbrk(a, ops_conflict))
                ret = 1;
            எனில் (strchr(a, 'x'))
                extract = 1;
            எனில் (strchr(a, 't'))
                table = 1;
            எனில் (strchr(a, 'v'))
                verbose = 1;
        } இல்லையெனில் {  // lib or obj files: don't abort - keep validating all args.
            எனில் (!i_lib)  // first file is the lib
                i_lib = i;
            இல்லையெனில் எனில் (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    எனில் (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    எனில் (ret == 1)
        திரும்பு ar_usage(ret);

    எனில் (extract || table) {
        எனில் ((fh = fopen(argv[i_lib], "rb")) == வெற்று)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            செல் finish;
        }
        fread(stmp, 1, 8, fh);
	எனில் (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            செல் finish;
	}
	போது (fread(&arhdr, 1, அளவு(arhdr), fh) == அளவு(arhdr)) {
	    எழுத்து *p, *e;

	    எனில் (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		செல் no_ar;
	    p = arhdr.ar_name;
	    க்கு (e = p + அளவு arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[அளவு arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    எனில் (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		எனில் (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        எனில் (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		எனில் (extract) {
		    எனில் ((fo = fopen(arhdr.ar_name, "wb")) == வெற்று)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			செல் finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            எனில் (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	எனில் (fh)
		fclose(fh);
	திரும்பு ret;
    }

    எனில் ((fh = fopen(argv[i_lib], "wb")) == வெற்று)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        செல் the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    எனில் ((fo = fopen(tfile, "wb+")) == வெற்று)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        செல் the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(வெற்று, funcmax * அளவு *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    போது (i_obj < argc)
    {
        எனில் (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            தொடர்;
        }
        எனில் ((fi = fopen(argv[i_obj], "rb")) == வெற்று) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            செல் the_end;
        }
        எனில் (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        எனில் (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            செல் the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (எழுத்து *)(buf + shdr->sh_offset);
        symtab = strtab = வெற்று;
        க்கு (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            எனில் (!shdr->sh_offset)
                தொடர்;
            எனில் (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (எழுத்து *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            எனில் (shdr->sh_type == SHT_STRTAB)
            {
                எனில் (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (எழுத்து *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        எனில் (symtab && strtab)
        {
            முழு nsym = symtabsize / அளவு(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            க்கு (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * அளவு(ElfW(Sym)));
                எனில் (sym->st_shndx &&
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
                    எனில் (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * அளவு *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        க்கு (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        எனில் (istrlen >= அளவு(arhdro.ar_name))
            istrlen = அளவு(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', அளவு(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, அளவு(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + அளவு(arhdro));
        எனில் (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + அளவு(arhdr) + strpos + (funccnt+1) * அளவு(முழு);
    fpos = 0;
    எனில் ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    எனில் (!funccnt) {
        ret = 0;
        செல் the_end;
    }
    sprintf(stmp, "%-10d", (முழு)(strpos + (funccnt+1) * அளவு(முழு)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, அளவு(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    க்கு (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * அளவு(முழு), 1, fh);
    fwrite(anames, strpos, 1, fh);
    எனில் (fpos)
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
    எனில் (anames)
        tcc_free(anames);
    எனில் (afpos)
        tcc_free(afpos);
    எனில் (fh)
        fclose(fh);
    எனில் (created_file && ret != 0)
        remove(created_file);
    எனில் (fo)
        fclose(fo), remove(tfile);
    திரும்பு ret;
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

ST_FUNC முழு tcc_tool_impdef(முழு argc, எழுத்து **argv)
{
    முழு ret, v, i;
    எழுத்து infile[260];
    எழுத்து outfile[260];

    மாறிலி எழுத்து *file;
    எழுத்து *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    எழுத்து path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = வெற்று;
    ret = 1;
    p = வெற்று;
    v = 0;

    க்கு (i = 1; i < argc; ++i) {
        மாறிலி எழுத்து *a = argv[i];
        எனில் ('-' == a[0]) {
            எனில் (0 == strcmp(a, "-v")) {
                v = 1;
            } இல்லையெனில் எனில் (0 == strcmp(a, "-o")) {
                எனில் (++i == argc)
                    செல் usage;
                strcpy(outfile, argv[i]);
            } இல்லையெனில்
                செல் usage;
        } இல்லையெனில் எனில் (0 == infile[0])
            strcpy(infile, a);
        இல்லையெனில்
            செல் usage;
    }

    எனில் (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        செல் the_end;
    }

    எனில் (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        எனில் (வெற்று == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    எனில் (தேடல்_Path(வெற்று, file, ".dll", அளவு path, path, வெற்று))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    எனில் (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        செல் the_end;
    }

    எனில் (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    எனில் (வெற்று == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        செல் the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    க்கு (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    எனில் (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    எனில் (p)
        tcc_free(p);
    எனில் (fp)
        fclose(fp);
    எனில் (op)
        fclose(op);
    திரும்பு ret;
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

#எனில் !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC முழு tcc_tool_cross(எழுத்து **argv, முழு option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    திரும்பு 1;
}

#இல்லையெனில்
#ifdef _WIN32
#அந்தர்பாவ <process.h>

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
நிலையான எழுத்து *quote_win32(மாறிலி எழுத்து *s)
{
    எழுத்து *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    முழு cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    க்கு (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        எனில் (*s == '\\' || *s == '"')
            *o++ = '\\';
        இல்லையெனில்
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    எனில் (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } இல்லையெனில் {
        o -= cbs;
    }

    *o = 0;
    திரும்பு r; /* don't bother with realloc(r, o-r+1) */
}

நிலையான முழு execvp_win32(மாறிலி எழுத்து *prog, எழுத்து **argv)
{
    முழு ret; எழுத்து **p;
    /* replace all " by \" */
    க்கு (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (மாறிலி எழுத்து *மாறிலி*)argv);
    எனில் (-1 == ret)
        திரும்பு ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC முழு tcc_tool_cross(எழுத்து **argv, முழு target)
{
    எழுத்து program[4096];
    எழுத்து *a0 = argv[0];
    முழு prefix = tcc_basename(a0) - a0;

    snprintf(program, அளவு program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    எனில் (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    திரும்பு 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
மாறிலி முழு _CRT_glob = 1;
#ifndef _CRT_glob
மாறிலி முழு _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

நிலையான எழுத்து *escape_target_dep(மாறிலி எழுத்து *s) {
    எழுத்து *res = tcc_malloc(strlen(s) * 2 + 1);
    முழு j;
    க்கு (j = 0; *s; s++, j++) {
        எனில் (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    திரும்பு res;
}

ST_FUNC முழு gen_makedeps(TCCState *s1, மாறிலி எழுத்து *target, மாறிலி எழுத்து *filename)
{
    FILE *depout;
    எழுத்து buf[1024];
    எழுத்து **escaped_targets;
    முழு i, k, இலக்கம்_targets;

    எனில் (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, அளவு buf, "%.*s.d",
            (முழு)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    எனில்(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    இல்லையெனில்
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    எனில் (!depout)
        திரும்பு tcc_error_noabort("could not open '%s'", filename);
    எனில் (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * அளவு(*escaped_targets));
    இலக்கம்_targets = 0;
    க்கு (i = 0; i<s1->nb_target_deps; ++i) {
        க்கு (k = 0; k < i; ++k)
            எனில் (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                செல் next;
        escaped_targets[இலக்கம்_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    க்கு (i = 0; i < இலக்கம்_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    எனில் (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        க்கு (i = 1; i < இலக்கம்_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    க்கு (i = 0; i < இலக்கம்_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    திரும்பு 0;
}

/* -------------------------------------------------------------- */
