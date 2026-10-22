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

#અન્તર્ભાવ "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

પ્રકારવ્યાખ્યા સંરચના {
    અક્ષર ar_name[16];
    અક્ષર ar_date[12];
    અક્ષર ar_uid[6];
    અક્ષર ar_gid[6];
    અક્ષર ar_mode[8];
    અક્ષર ar_size[10];
    અક્ષર ar_fmag[2];
} ArHdr;

સ્થિર unsigned long le2belong(unsigned long ul) {
    પાછા ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

સ્થિર પૂર્ણાંક ar_usage(પૂર્ણાંક ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    પાછા ret;
}

ST_FUNC પૂર્ણાંક tcc_tool_ar(પૂર્ણાંક argc, અક્ષર **argv)
{
    સ્થિર અચલ ArHdr arhdr_init = {
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

    FILE *fi, *fh = ખાલી, *fo = ખાલી;
    અચલ અક્ષર *created_file = ખાલી; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    પૂર્ણાંક i, fsize, i_lib, i_obj;
    અક્ષર *buf, *shstr, *symtab, *strtab;
    પૂર્ણાંક symtabsize = 0;//, strtabsize = 0;
    અક્ષર *anames = ખાલી;
    પૂર્ણાંક *afpos = ખાલી;
    પૂર્ણાંક istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    અક્ષર tfile[260], stmp[20];
    અક્ષર *file, *name;
    પૂર્ણાંક ret = 2;
    અચલ અક્ષર *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    પૂર્ણાંક extract = 0;
    પૂર્ણાંક table = 0;
    પૂર્ણાંક verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    માટે (i = 1; i < argc; i++) {
        અચલ અક્ષર *a = argv[i];
        જો (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        જો ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            જો (strpbrk(a, ops_conflict))
                ret = 1;
            જો (strchr(a, 'x'))
                extract = 1;
            જો (strchr(a, 't'))
                table = 1;
            જો (strchr(a, 'v'))
                verbose = 1;
        } નહીંતર {  // lib or obj files: don't abort - keep validating all args.
            જો (!i_lib)  // first file is the lib
                i_lib = i;
            નહીંતર જો (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    જો (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    જો (ret == 1)
        પાછા ar_usage(ret);

    જો (extract || table) {
        જો ((fh = fopen(argv[i_lib], "rb")) == ખાલી)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            જાઓ finish;
        }
        fread(stmp, 1, 8, fh);
	જો (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            જાઓ finish;
	}
	જ્યારે (fread(&arhdr, 1, કદ(arhdr), fh) == કદ(arhdr)) {
	    અક્ષર *p, *e;

	    જો (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		જાઓ no_ar;
	    p = arhdr.ar_name;
	    માટે (e = p + કદ arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[કદ arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    જો (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		જો (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        જો (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		જો (extract) {
		    જો ((fo = fopen(arhdr.ar_name, "wb")) == ખાલી)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			જાઓ finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            જો (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	જો (fh)
		fclose(fh);
	પાછા ret;
    }

    જો ((fh = fopen(argv[i_lib], "wb")) == ખાલી)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        જાઓ the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    જો ((fo = fopen(tfile, "wb+")) == ખાલી)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        જાઓ the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(ખાલી, funcmax * કદ *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    જ્યારે (i_obj < argc)
    {
        જો (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            ચાલુ;
        }
        જો ((fi = fopen(argv[i_obj], "rb")) == ખાલી) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            જાઓ the_end;
        }
        જો (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        જો (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            જાઓ the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (અક્ષર *)(buf + shdr->sh_offset);
        symtab = strtab = ખાલી;
        માટે (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            જો (!shdr->sh_offset)
                ચાલુ;
            જો (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (અક્ષર *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            જો (shdr->sh_type == SHT_STRTAB)
            {
                જો (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (અક્ષર *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        જો (symtab && strtab)
        {
            પૂર્ણાંક nsym = symtabsize / કદ(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            માટે (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * કદ(ElfW(Sym)));
                જો (sym->st_shndx &&
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
                    જો (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * કદ *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        માટે (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        જો (istrlen >= કદ(arhdro.ar_name))
            istrlen = કદ(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', કદ(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, કદ(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + કદ(arhdro));
        જો (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + કદ(arhdr) + strpos + (funccnt+1) * કદ(પૂર્ણાંક);
    fpos = 0;
    જો ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    જો (!funccnt) {
        ret = 0;
        જાઓ the_end;
    }
    sprintf(stmp, "%-10d", (પૂર્ણાંક)(strpos + (funccnt+1) * કદ(પૂર્ણાંક)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, કદ(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    માટે (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * કદ(પૂર્ણાંક), 1, fh);
    fwrite(anames, strpos, 1, fh);
    જો (fpos)
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
    જો (anames)
        tcc_free(anames);
    જો (afpos)
        tcc_free(afpos);
    જો (fh)
        fclose(fh);
    જો (created_file && ret != 0)
        remove(created_file);
    જો (fo)
        fclose(fo), remove(tfile);
    પાછા ret;
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

ST_FUNC પૂર્ણાંક tcc_tool_impdef(પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક ret, v, i;
    અક્ષર infile[260];
    અક્ષર outfile[260];

    અચલ અક્ષર *file;
    અક્ષર *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    અક્ષર path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = ખાલી;
    ret = 1;
    p = ખાલી;
    v = 0;

    માટે (i = 1; i < argc; ++i) {
        અચલ અક્ષર *a = argv[i];
        જો ('-' == a[0]) {
            જો (0 == strcmp(a, "-v")) {
                v = 1;
            } નહીંતર જો (0 == strcmp(a, "-o")) {
                જો (++i == argc)
                    જાઓ usage;
                strcpy(outfile, argv[i]);
            } નહીંતર
                જાઓ usage;
        } નહીંતર જો (0 == infile[0])
            strcpy(infile, a);
        નહીંતર
            જાઓ usage;
    }

    જો (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        જાઓ the_end;
    }

    જો (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        જો (ખાલી == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    જો (શોધ_Path(ખાલી, file, ".dll", કદ path, path, ખાલી))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    જો (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        જાઓ the_end;
    }

    જો (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    જો (ખાલી == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        જાઓ the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    માટે (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    જો (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    જો (p)
        tcc_free(p);
    જો (fp)
        fclose(fp);
    જો (op)
        fclose(op);
    પાછા ret;
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

#જો !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC પૂર્ણાંક tcc_tool_cross(અક્ષર **argv, પૂર્ણાંક option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    પાછા 1;
}

#નહીંતર
#ifdef _WIN32
#અન્તર્ભાવ <process.h>

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
સ્થિર અક્ષર *quote_win32(અચલ અક્ષર *s)
{
    અક્ષર *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    પૂર્ણાંક cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    માટે (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        જો (*s == '\\' || *s == '"')
            *o++ = '\\';
        નહીંતર
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    જો (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } નહીંતર {
        o -= cbs;
    }

    *o = 0;
    પાછા r; /* don't bother with realloc(r, o-r+1) */
}

સ્થિર પૂર્ણાંક execvp_win32(અચલ અક્ષર *prog, અક્ષર **argv)
{
    પૂર્ણાંક ret; અક્ષર **p;
    /* replace all " by \" */
    માટે (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (અચલ અક્ષર *અચલ*)argv);
    જો (-1 == ret)
        પાછા ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC પૂર્ણાંક tcc_tool_cross(અક્ષર **argv, પૂર્ણાંક target)
{
    અક્ષર program[4096];
    અક્ષર *a0 = argv[0];
    પૂર્ણાંક prefix = tcc_basename(a0) - a0;

    snprintf(program, કદ program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    જો (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    પાછા 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
અચલ પૂર્ણાંક _CRT_glob = 1;
#ifndef _CRT_glob
અચલ પૂર્ણાંક _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

સ્થિર અક્ષર *escape_target_dep(અચલ અક્ષર *s) {
    અક્ષર *res = tcc_malloc(strlen(s) * 2 + 1);
    પૂર્ણાંક j;
    માટે (j = 0; *s; s++, j++) {
        જો (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    પાછા res;
}

ST_FUNC પૂર્ણાંક gen_makedeps(TCCState *s1, અચલ અક્ષર *target, અચલ અક્ષર *filename)
{
    FILE *depout;
    અક્ષર buf[1024];
    અક્ષર **escaped_targets;
    પૂર્ણાંક i, k, અંક_targets;

    જો (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, કદ buf, "%.*s.d",
            (પૂર્ણાંક)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    જો(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    નહીંતર
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    જો (!depout)
        પાછા tcc_error_noabort("could not open '%s'", filename);
    જો (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * કદ(*escaped_targets));
    અંક_targets = 0;
    માટે (i = 0; i<s1->nb_target_deps; ++i) {
        માટે (k = 0; k < i; ++k)
            જો (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                જાઓ next;
        escaped_targets[અંક_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    માટે (i = 0; i < અંક_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    જો (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        માટે (i = 1; i < અંક_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    માટે (i = 0; i < અંક_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    પાછા 0;
}

/* -------------------------------------------------------------- */
