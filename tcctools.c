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

#ଅନ୍ତର୍ଭାଵ "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ଅକ୍ଷର ar_name[16];
    ଅକ୍ଷର ar_date[12];
    ଅକ୍ଷର ar_uid[6];
    ଅକ୍ଷର ar_gid[6];
    ଅକ୍ଷର ar_mode[8];
    ଅକ୍ଷର ar_size[10];
    ଅକ୍ଷର ar_fmag[2];
} ArHdr;

ସ୍ଥିର unsigned long le2belong(unsigned long ul) {
    ଫେରନ୍ତୁ ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା ar_usage(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    ଫେରନ୍ତୁ ret;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_ar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ସ୍ଥିର ଅଚଳ ArHdr arhdr_init = {
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

    FILE *fi, *fh = ଖାଲି, *fo = ଖାଲି;
    ଅଚଳ ଅକ୍ଷର *created_file = ଖାଲି; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, fsize, i_lib, i_obj;
    ଅକ୍ଷର *buf, *shstr, *symtab, *strtab;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା symtabsize = 0;//, strtabsize = 0;
    ଅକ୍ଷର *anames = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *afpos = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    ଅକ୍ଷର tfile[260], stmp[20];
    ଅକ୍ଷର *file, *name;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = 2;
    ଅଚଳ ଅକ୍ଷର *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା extract = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା table = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    ପାଇଁ (i = 1; i < argc; i++) {
        ଅଚଳ ଅକ୍ଷର *a = argv[i];
        ଯଦି (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        ଯଦି ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            ଯଦି (strpbrk(a, ops_conflict))
                ret = 1;
            ଯଦି (strchr(a, 'x'))
                extract = 1;
            ଯଦି (strchr(a, 't'))
                table = 1;
            ଯଦି (strchr(a, 'v'))
                verbose = 1;
        } ଅନ୍ୟଥା {  // lib or obj files: don't abort - keep validating all args.
            ଯଦି (!i_lib)  // first file is the lib
                i_lib = i;
            ଅନ୍ୟଥା ଯଦି (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    ଯଦି (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    ଯଦି (ret == 1)
        ଫେରନ୍ତୁ ar_usage(ret);

    ଯଦି (extract || table) {
        ଯଦି ((fh = fopen(argv[i_lib], "rb")) == ଖାଲି)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            ଯାଅ finish;
        }
        fread(stmp, 1, 8, fh);
	ଯଦି (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            ଯାଅ finish;
	}
	ଯେତେବେଳେ (fread(&arhdr, 1, ଆକାର(arhdr), fh) == ଆକାର(arhdr)) {
	    ଅକ୍ଷର *p, *e;

	    ଯଦି (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		ଯାଅ no_ar;
	    p = arhdr.ar_name;
	    ପାଇଁ (e = p + ଆକାର arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[ଆକାର arhdr.ar_size-1] = 0;
	    fsize = atoi(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    ଯଦି (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		ଯଦି (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        ଯଦି (table || verbose)
		    printf("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		ଯଦି (extract) {
		    ଯଦି ((fo = fopen(arhdr.ar_name, "wb")) == ଖାଲି)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			ଯାଅ finish;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            ଯଦି (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	ଯଦି (fh)
		fclose(fh);
	ଫେରନ୍ତୁ ret;
    }

    ଯଦି ((fh = fopen(argv[i_lib], "wb")) == ଖାଲି)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        ଯାଅ the_end;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    ଯଦି ((fo = fopen(tfile, "wb+")) == ଖାଲି)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        ଯାଅ the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(ଖାଲି, funcmax * ଆକାର *afpos); // 250 func
    memcpy(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    ଯେତେବେଳେ (i_obj < argc)
    {
        ଯଦି (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            ଜାରି;
        }
        ଯଦି ((fi = fopen(argv[i_obj], "rb")) == ଖାଲି) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            ଯାଅ the_end;
        }
        ଯଦି (verbose)
            printf("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        ଯଦି (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            ଯାଅ the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (ଅକ୍ଷର *)(buf + shdr->sh_offset);
        symtab = strtab = ଖାଲି;
        ପାଇଁ (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            ଯଦି (!shdr->sh_offset)
                ଜାରି;
            ଯଦି (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (ଅକ୍ଷର *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            ଯଦି (shdr->sh_type == SHT_STRTAB)
            {
                ଯଦି (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (ଅକ୍ଷର *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        ଯଦି (symtab && strtab)
        {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା nsym = symtabsize / ଆକାର(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            ପାଇଁ (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * ଆକାର(ElfW(Sym)));
                ଯଦି (sym->st_shndx &&
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
                    ଯଦି (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * ଆକାର *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        ପାଇଁ (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = strlen(name);
        ଯଦି (istrlen >= ଆକାର(arhdro.ar_name))
            istrlen = ଆକାର(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', ଆକାର(arhdro.ar_name));
        memcpy(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        memcpy(&arhdro.ar_size, stmp, 10);
        fwrite(&arhdro, ଆକାର(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + ଆକାର(arhdro));
        ଯଦି (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + ଆକାର(arhdr) + strpos + (funccnt+1) * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    fpos = 0;
    ଯଦି ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    ଯଦି (!funccnt) {
        ret = 0;
        ଯାଅ the_end;
    }
    sprintf(stmp, "%-10d", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(strpos + (funccnt+1) * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)) + fpos);
    memcpy(&arhdr.ar_size, stmp, 10);
    fwrite(&arhdr, ଆକାର(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    ପାଇଁ (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା), 1, fh);
    fwrite(anames, strpos, 1, fh);
    ଯଦି (fpos)
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
    ଯଦି (anames)
        tcc_free(anames);
    ଯଦି (afpos)
        tcc_free(afpos);
    ଯଦି (fh)
        fclose(fh);
    ଯଦି (created_file && ret != 0)
        remove(created_file);
    ଯଦି (fo)
        fclose(fo), remove(tfile);
    ଫେରନ୍ତୁ ret;
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

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_impdef(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret, v, i;
    ଅକ୍ଷର infile[260];
    ଅକ୍ଷର outfile[260];

    ଅଚଳ ଅକ୍ଷର *file;
    ଅକ୍ଷର *p, *q;
    FILE *fp, *op;

#ifdef _WIN32
    ଅକ୍ଷର path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = ଖାଲି;
    ret = 1;
    p = ଖାଲି;
    v = 0;

    ପାଇଁ (i = 1; i < argc; ++i) {
        ଅଚଳ ଅକ୍ଷର *a = argv[i];
        ଯଦି ('-' == a[0]) {
            ଯଦି (0 == strcmp(a, "-v")) {
                v = 1;
            } ଅନ୍ୟଥା ଯଦି (0 == strcmp(a, "-o")) {
                ଯଦି (++i == argc)
                    ଯାଅ usage;
                strcpy(outfile, argv[i]);
            } ଅନ୍ୟଥା
                ଯାଅ usage;
        } ଅନ୍ୟଥା ଯଦି (0 == infile[0])
            strcpy(infile, a);
        ଅନ୍ୟଥା
            ଯାଅ usage;
    }

    ଯଦି (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        ଯାଅ the_end;
    }

    ଯଦି (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        ଯଦି (ଖାଲି == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    ଯଦି (ସନ୍ଧାନ_Path(ଖାଲି, file, ".dll", ଆକାର path, path, ଖାଲି))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    ଯଦି (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        ଯାଅ the_end;
    }

    ଯଦି (v)
        printf("-> %s\n", file);

    op = fopen(outfile, "wb");
    ଯଦି (ଖାଲି == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        ଯାଅ the_end;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    ପାଇଁ (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += strlen(q) + 1;
    }

    ଯଦି (v)
        printf("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    ଯଦି (p)
        tcc_free(p);
    ଯଦି (fp)
        fclose(fp);
    ଯଦି (op)
        fclose(op);
    ଫେରନ୍ତୁ ret;
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

#ଯଦି !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_cross(ଅକ୍ଷର **argv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    ଫେରନ୍ତୁ 1;
}

#ଅନ୍ୟଥା
#ifdef _WIN32
#ଅନ୍ତର୍ଭାଵ <process.h>

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
ସ୍ଥିର ଅକ୍ଷର *quote_win32(ଅଚଳ ଅକ୍ଷର *s)
{
    ଅକ୍ଷର *o, *r = tcc_malloc(2 * strlen(s) + 3);   /* max-esc, quotes, \0 */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    ପାଇଁ (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        ଯଦି (*s == '\\' || *s == '"')
            *o++ = '\\';
        ଅନ୍ୟଥା
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    ଯଦି (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } ଅନ୍ୟଥା {
        o -= cbs;
    }

    *o = 0;
    ଫେରନ୍ତୁ r; /* don't bother with realloc(r, o-r+1) */
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା execvp_win32(ଅଚଳ ଅକ୍ଷର *prog, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret; ଅକ୍ଷର **p;
    /* replace all " by \" */
    ପାଇଁ (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ଅଚଳ ଅକ୍ଷର *ଅଚଳ*)argv);
    ଯଦି (-1 == ret)
        ଫେରନ୍ତୁ ret;
    _cwait(&ret, ret, WAIT_CHILD);
    exit(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_cross(ଅକ୍ଷର **argv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା target)
{
    ଅକ୍ଷର program[4096];
    ଅକ୍ଷର *a0 = argv[0];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା prefix = tcc_basename(a0) - a0;

    snprintf(program, ଆକାର program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    ଯଦି (strcmp(a0, program))
        execvp(argv[0] = program, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", program);
    ଫେରନ୍ତୁ 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _CRT_glob = 1;
#ifndef _CRT_glob
ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

ସ୍ଥିର ଅକ୍ଷର *escape_target_dep(ଅଚଳ ଅକ୍ଷର *s) {
    ଅକ୍ଷର *res = tcc_malloc(strlen(s) * 2 + 1);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା j;
    ପାଇଁ (j = 0; *s; s++, j++) {
        ଯଦି (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    ଫେରନ୍ତୁ res;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gen_makedeps(TCCState *s1, ଅଚଳ ଅକ୍ଷର *target, ଅଚଳ ଅକ୍ଷର *filename)
{
    FILE *depout;
    ଅକ୍ଷର buf[1024];
    ଅକ୍ଷର **escaped_targets;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, k, ଅଙ୍କ_targets;

    ଯଦି (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, ଆକାର buf, "%.*s.d",
            (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    ଯଦି(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    ଅନ୍ୟଥା
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    ଯଦି (!depout)
        ଫେରନ୍ତୁ tcc_error_noabort("could not open '%s'", filename);
    ଯଦି (s1->verbose)
        printf("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * ଆକାର(*escaped_targets));
    ଅଙ୍କ_targets = 0;
    ପାଇଁ (i = 0; i<s1->nb_target_deps; ++i) {
        ପାଇଁ (k = 0; k < i; ++k)
            ଯଦି (0 == strcmp(s1->target_deps[i], s1->target_deps[k]))
                ଯାଅ next;
        escaped_targets[ଅଙ୍କ_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    fprintf(depout, "%s:", target);
    ପାଇଁ (i = 0; i < ଅଙ୍କ_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    ଯଦି (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        ପାଇଁ (i = 1; i < ଅଙ୍କ_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    ପାଇଁ (i = 0; i < ଅଙ୍କ_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    ଫେରନ୍ତୁ 0;
}

/* -------------------------------------------------------------- */
