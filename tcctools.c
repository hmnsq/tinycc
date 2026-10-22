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

#ضمن "tcc.h"

//#define ARMAG  "!<arch>\n"
#تعریف_کرو ARFMAG "`\n"

تعريفنوع بنية {
    حرف ar_name[16];
    حرف ar_date[12];
    حرف ar_uid[6];
    حرف ar_gid[6];
    حرف ar_منوال[8];
    حرف ar_ناپ[10];
    حرف ar_fmag[2];
} ArHdr;

ساكن بنانشانی لما le2belong(بنانشانی لما ul) {
    أرجع ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

ساكن صحيح ar_usage(صحيح ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    أرجع ret;
}

ST_FUNC صحيح tcc_tool_ar(صحيح argc, حرف **argv)
{
    ساكن ثابت ArHdr arhdr_init = {
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

    FILE *fi, *fh = عدم, *fo = عدم;
    ثابت حرف *created_file = عدم; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    صحيح i, fsize, i_lib, i_obj;
    حرف *buf, *shstr, *symtab, *strtab;
    صحيح symtabsize = 0;//, strtabsize = 0;
    حرف *anames = عدم;
    صحيح *afpos = عدم;
    صحيح istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    حرف tfile[260], stmp[20];
    حرف *file, *name;
    صحيح ret = 2;
    ثابت حرف *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    صحيح کڈھو = 0;
    صحيح جدول = 0;
    صحيح verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    لكل (i = 1; i < argc; i++) {
        ثابت حرف *a = argv[i];
        إذا (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        إذا ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            إذا (strpbrk(a, ops_conflict))
                ret = 1;
            إذا (strchr(a, 'x'))
                کڈھو = 1;
            إذا (strchr(a, 't'))
                جدول = 1;
            إذا (strchr(a, 'v'))
                verbose = 1;
        } وإلا {  // lib or obj files: don't abort - keep validating all args.
            إذا (!i_lib)  // first file is the lib
                i_lib = i;
            وإلا إذا (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    إذا (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    إذا (ret == 1)
        أرجع ar_usage(ret);

    إذا (کڈھو || جدول) {
        إذا ((fh = fopen(argv[i_lib], "rb")) == عدم)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            اذهب انت;
        }
        fread(stmp, 1, 8, fh);
	إذا (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            اذهب انت;
	}
	طالما (fread(&arhdr, 1, حجم(arhdr), fh) == حجم(arhdr)) {
	    حرف *p, *e;

	    إذا (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		اذهب no_ar;
	    p = arhdr.ar_name;
	    لكل (e = p + حجم arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_ناپ[حجم arhdr.ar_ناپ-1] = 0;
	    fsize = atoi(arhdr.ar_ناپ);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    إذا (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		إذا (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        إذا (جدول || verbose)
		    لکھو("%s%s\n", کڈھو ? "x - " : "", arhdr.ar_name);
		إذا (کڈھو) {
		    إذا ((fo = fopen(arhdr.ar_name, "wb")) == عدم)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			اذهب انت;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            إذا (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
انت:
	إذا (fh)
		fclose(fh);
	أرجع ret;
    }

    إذا ((fh = fopen(argv[i_lib], "wb")) == عدم)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        اذهب the_سرا;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    إذا ((fo = fopen(tfile, "wb+")) == عدم)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        اذهب the_سرا;
    }

    funcmax = 250;
    afpos = tcc_realloc(عدم, funcmax * حجم *afpos); // 250 func
    حافظہ_نقل(&arhdro.ar_منوال, "100644", 6);

    // i_obj = first input object file
    طالما (i_obj < argc)
    {
        إذا (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            استمر;
        }
        إذا ((fi = fopen(argv[i_obj], "rb")) == عدم) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            اذهب the_سرا;
        }
        إذا (verbose)
            لکھو("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        إذا (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            اذهب the_سرا;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (حرف *)(buf + shdr->sh_وتھ);
        symtab = strtab = عدم;
        لكل (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            إذا (!shdr->sh_وتھ)
                استمر;
            إذا (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (حرف *)(buf + shdr->sh_وتھ);
                symtabsize = shdr->sh_ناپ;
            }
            إذا (shdr->sh_type == SHT_STRTAB)
            {
                إذا (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (حرف *)(buf + shdr->sh_وتھ);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        إذا (symtab && strtab)
        {
            صحيح nsym = symtabsize / حجم(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            لكل (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * حجم(ElfW(Sym)));
                إذا (sym->st_shndx &&
                    (sym->st_info == 0x10
                    || sym->st_info == 0x11
                    || sym->st_info == 0x12
                    || sym->st_info == 0x20
                    || sym->st_info == 0x21
                    || sym->st_info == 0x22
                    )) {
                    //printf("symtab: %2Xh %4Xh %2Xh %s\n", sym->st_info, sym->st_size, sym->st_shndx, strtab + sym->st_name);
                    istrlen = لڑی_لمبائی(strtab + sym->st_name)+1;
                    anames = tcc_realloc(anames, strpos+istrlen);
                    strcpy(anames + strpos, strtab + sym->st_name);
                    strpos += istrlen;
                    إذا (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * حجم *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        لكل (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = لڑی_لمبائی(name);
        إذا (istrlen >= حجم(arhdro.ar_name))
            istrlen = حجم(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', حجم(arhdro.ar_name));
        حافظہ_نقل(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        حافظہ_نقل(&arhdro.ar_ناپ, stmp, 10);
        fwrite(&arhdro, حجم(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + حجم(arhdro));
        إذا (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + حجم(arhdr) + strpos + (funccnt+1) * حجم(صحيح);
    fpos = 0;
    إذا ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    إذا (!funccnt) {
        ret = 0;
        اذهب the_سرا;
    }
    sprintf(stmp, "%-10d", (صحيح)(strpos + (funccnt+1) * حجم(صحيح)) + fpos);
    حافظہ_نقل(&arhdr.ar_ناپ, stmp, 10);
    fwrite(&arhdr, حجم(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    لكل (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * حجم(صحيح), 1, fh);
    fwrite(anames, strpos, 1, fh);
    إذا (fpos)
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
the_سرا:
    إذا (anames)
        tcc_free(anames);
    إذا (afpos)
        tcc_free(afpos);
    إذا (fh)
        fclose(fh);
    إذا (created_file && ret != 0)
        remove(created_file);
    إذا (fo)
        fclose(fo), remove(tfile);
    أرجع ret;
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

#جے_تعریف_شدہ TCC_نشانہ_PE

ST_FUNC صحيح tcc_tool_impdef(صحيح argc, حرف **argv)
{
    صحيح ret, v, i;
    حرف infile[260];
    حرف outfile[260];

    ثابت حرف *file;
    حرف *p, *q;
    FILE *fp, *op;

#جے_تعریف_شدہ _WIN32
    حرف رستہ[260];
#جے_انت

    infile[0] = outfile[0] = 0;
    fp = op = عدم;
    ret = 1;
    p = عدم;
    v = 0;

    لكل (i = 1; i < argc; ++i) {
        ثابت حرف *a = argv[i];
        إذا ('-' == a[0]) {
            إذا (0 == strcmp(a, "-v")) {
                v = 1;
            } وإلا إذا (0 == strcmp(a, "-o")) {
                إذا (++i == argc)
                    اذهب usage;
                strcpy(outfile, argv[i]);
            } وإلا
                اذهب usage;
        } وإلا إذا (0 == infile[0])
            strcpy(infile, a);
        وإلا
            اذهب usage;
    }

    إذا (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        اذهب the_سرا;
    }

    إذا (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        إذا (عدم == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#جے_تعریف_شدہ _WIN32
    إذا (تلاش_رستہ(عدم, file, ".dll", حجم رستہ, رستہ, عدم))
        file = رستہ;
#جے_انت
    ret = tcc_get_dllexports(file, &p);
    إذا (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        اذهب the_سرا;
    }

    إذا (v)
        لکھو("-> %s\n", file);

    op = fopen(outfile, "wb");
    إذا (عدم == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        اذهب the_سرا;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    لكل (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += لڑی_لمبائی(q) + 1;
    }

    إذا (v)
        لکھو("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_سرا:
    إذا (p)
        tcc_free(p);
    إذا (fp)
        fclose(fp);
    إذا (op)
        fclose(op);
    أرجع ret;
}

#جے_انت /* TCC_TARGET_PE */

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

#إذا !defined TCC_نشانہ_I386 && !defined TCC_نشانہ_X86_64

ST_FUNC صحيح tcc_tool_cross(حرف **argv, صحيح option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    أرجع 1;
}

#وإلا
#جے_تعریف_شدہ _WIN32
#ضمن <process.h>

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
ساكن حرف *quote_win32(ثابت حرف *s)
{
    حرف *o, *r = tcc_malloc(2 * لڑی_لمبائی(s) + 3);   /* max-esc, quotes, \0 */
    صحيح cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    لكل (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        إذا (*s == '\\' || *s == '"')
            *o++ = '\\';
        وإلا
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    إذا (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } وإلا {
        o -= cbs;
    }

    *o = 0;
    أرجع r; /* don't bother with realloc(r, o-r+1) */
}

ساكن صحيح execvp_win32(ثابت حرف *prog, حرف **argv)
{
    صحيح ret; حرف **p;
    /* replace all " by \" */
    لكل (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ثابت حرف *ثابت*)argv);
    إذا (-1 == ret)
        أرجع ret;
    _cwait(&ret, ret, WAIT_بچہ);
    باہر_نکلو(ret);
}
#تعریف_کرو execvp execvp_win32
#جے_انت /* _WIN32 */

ST_FUNC صحيح tcc_tool_cross(حرف **argv, صحيح نشانہ)
{
    حرف پروگرام[4096];
    حرف *a0 = argv[0];
    صحيح اگیتر = tcc_basename(a0) - a0;

    snprintf(پروگرام, حجم پروگرام,
        "%.*s%s"
#جے_تعریف_شدہ TCC_نشانہ_PE
        "-win32"
#جے_انت
        "-tcc"
#جے_تعریف_شدہ _WIN32
        ".exe"
#جے_انت
        , اگیتر, a0, نشانہ == 64 ? "x86_64" : "i386");

    إذا (strcmp(a0, پروگرام))
        execvp(argv[0] = پروگرام, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", پروگرام);
    أرجع 1;
}

#جے_انت /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#جے_تعریف_شدہ _WIN32
ثابت صحيح _CRT_glob = 1;
#جے_بنا_تعریف _CRT_glob
ثابت صحيح _dowildcard = 1;
#جے_انت
#جے_انت

/* -------------------------------------------------------------- */
/* generate xxx.d file */

ساكن حرف *escape_نشانہ_dep(ثابت حرف *s) {
    حرف *res = tcc_malloc(لڑی_لمبائی(s) * 2 + 1);
    صحيح j;
    لكل (j = 0; *s; s++, j++) {
        إذا (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    أرجع res;
}

ST_FUNC صحيح gen_makedeps(TCCState *s1, ثابت حرف *نشانہ, ثابت حرف *filename)
{
    FILE *depout;
    حرف buf[1024];
    حرف **escaped_targets;
    صحيح i, k, عدد_targets;

    إذا (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, حجم buf, "%.*s.d",
            (صحيح)(tcc_fileextension(نشانہ) - نشانہ), نشانہ);
        filename = buf;
    }

    إذا(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    وإلا
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    إذا (!depout)
        أرجع tcc_error_noabort("could not open '%s'", filename);
    إذا (s1->verbose)
        لکھو("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_نشانہ_deps * حجم(*escaped_targets));
    عدد_targets = 0;
    لكل (i = 0; i<s1->nb_نشانہ_deps; ++i) {
        لكل (k = 0; k < i; ++k)
            إذا (0 == strcmp(s1->نشانہ_deps[i], s1->نشانہ_deps[k]))
                اذهب اگلا;
        escaped_targets[عدد_targets++] = escape_نشانہ_dep(s1->نشانہ_deps[i]);
    اگلا:;
    }

    fprintf(depout, "%s:", نشانہ);
    لكل (i = 0; i < عدد_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    إذا (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        لكل (i = 1; i < عدد_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    لكل (i = 0; i < عدد_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    أرجع 0;
}

/* -------------------------------------------------------------- */
