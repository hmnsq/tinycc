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

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

//#define ARMAG  "!<arch>\n"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARFMAG "`\n"

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਅੱਖਰ ar_name[16];
    ਅੱਖਰ ar_date[12];
    ਅੱਖਰ ar_uid[6];
    ਅੱਖਰ ar_gid[6];
    ਅੱਖਰ ar_ਬਹੁਲਕ[8];
    ਅੱਖਰ ar_ਮਾਪ[10];
    ਅੱਖਰ ar_fmag[2];
} ArHdr;

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ le2belong(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ul) {
    ਵਾਪਸ ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

ਸਥਿਰ ਪੂਰਨ ar_usage(ਪੂਰਨ ret) {
    fprintf(stderr, "usage: tcc -ar [crstvx] lib [files]\n");
    fprintf(stderr, "create library ([abdiopN] not supported).\n");
    ਵਾਪਸ ret;
}

ST_FUNC ਪੂਰਨ tcc_tool_ar(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਸਥਿਰ ਅਚਲ ArHdr arhdr_init = {
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

    FILE *fi, *fh = ਨਿਰਾ, *fo = ਨਿਰਾ;
    ਅਚਲ ਅੱਖਰ *created_file = ਨਿਰਾ; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    ਪੂਰਨ i, fsize, i_lib, i_obj;
    ਅੱਖਰ *buf, *shstr, *symtab, *strtab;
    ਪੂਰਨ symtabsize = 0;//, strtabsize = 0;
    ਅੱਖਰ *anames = ਨਿਰਾ;
    ਪੂਰਨ *afpos = ਨਿਰਾ;
    ਪੂਰਨ istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    ਅੱਖਰ tfile[260], stmp[20];
    ਅੱਖਰ *file, *name;
    ਪੂਰਨ ret = 2;
    ਅਚਲ ਅੱਖਰ *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    ਪੂਰਨ ਕੱਢੋ_3 = 0;
    ਪੂਰਨ ਸਾਰਣੀ = 0;
    ਪੂਰਨ verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    ਲਈ (i = 1; i < argc; i++) {
        ਅਚਲ ਅੱਖਰ *a = argv[i];
        ਜੇ (*a == '-' && strchr(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        ਜੇ ((*a == '-') || (i == 1 && !strchr(a, '.'))) {  // options argument
            ਜੇ (strpbrk(a, ops_conflict))
                ret = 1;
            ਜੇ (strchr(a, 'x'))
                ਕੱਢੋ_3 = 1;
            ਜੇ (strchr(a, 't'))
                ਸਾਰਣੀ = 1;
            ਜੇ (strchr(a, 'v'))
                verbose = 1;
        } ਨਹੀਂਤਾਂ {  // lib or obj files: don't abort - keep validating all args.
            ਜੇ (!i_lib)  // first file is the lib
                i_lib = i;
            ਨਹੀਂਤਾਂ ਜੇ (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    ਜੇ (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    ਜੇ (ret == 1)
        ਵਾਪਸ ar_usage(ret);

    ਜੇ (ਕੱਢੋ_3 || ਸਾਰਣੀ) {
        ਜੇ ((fh = fopen(argv[i_lib], "rb")) == ਨਿਰਾ)
        {
            fprintf(stderr, "tcc: ar: can't open file %s\n", argv[i_lib]);
            ਜਾਓ ਅੰਤ_2;
        }
        fread(stmp, 1, 8, fh);
	ਜੇ (memcmp(stmp,ARMAG,8))
	{
no_ar:
            fprintf(stderr, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            ਜਾਓ ਅੰਤ_2;
	}
	ਜਦੋਂ (fread(&arhdr, 1, ਆਕਾਰ(arhdr), fh) == ਆਕਾਰ(arhdr)) {
	    ਅੱਖਰ *p, *e;

	    ਜੇ (memcmp(arhdr.ar_fmag, ARFMAG, 2))
		ਜਾਓ no_ar;
	    p = arhdr.ar_name;
	    ਲਈ (e = p + ਆਕਾਰ arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_ਮਾਪ[ਆਕਾਰ arhdr.ar_ਮਾਪ-1] = 0;
	    fsize = atoi(arhdr.ar_ਮਾਪ);
	    buf = tcc_malloc(fsize + 1);
	    fread(buf, fsize, 1, fh);
	    ਜੇ (strcmp(arhdr.ar_name,"/") && strcmp(arhdr.ar_name,"/SYM64/")) {
		ਜੇ (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        ਜੇ (ਸਾਰਣੀ || verbose)
		    ਲਿਖੋ("%s%s\n", ਕੱਢੋ_3 ? "x - " : "", arhdr.ar_name);
		ਜੇ (ਕੱਢੋ_3) {
		    ਜੇ ((fo = fopen(arhdr.ar_name, "wb")) == ਨਿਰਾ)
		    {
			fprintf(stderr, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			ਜਾਓ ਅੰਤ_2;
		    }
		    fwrite(buf, fsize, 1, fo);
		    fclose(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            ਜੇ (fsize & 1)
                fgetc(fh);
            tcc_free(buf);
	}
	ret = 0;
ਅੰਤ_2:
	ਜੇ (fh)
		fclose(fh);
	ਵਾਪਸ ret;
    }

    ਜੇ ((fh = fopen(argv[i_lib], "wb")) == ਨਿਰਾ)
    {
        fprintf(stderr, "tcc: ar: can't create file %s\n", argv[i_lib]);
        ਜਾਓ the_ਸਿਰਾ;
    }
    created_file = argv[i_lib];

    sprintf(tfile, "%s.tmp", argv[i_lib]);
    ਜੇ ((fo = fopen(tfile, "wb+")) == ਨਿਰਾ)
    {
        fprintf(stderr, "tcc: ar: can't create temporary file %s\n", tfile);
        ਜਾਓ the_ਸਿਰਾ;
    }

    funcmax = 250;
    afpos = tcc_realloc(ਨਿਰਾ, funcmax * ਆਕਾਰ *afpos); // 250 func
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&arhdro.ar_ਬਹੁਲਕ, "100644", 6);

    // i_obj = first input object file
    ਜਦੋਂ (i_obj < argc)
    {
        ਜੇ (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            ਜਾਰੀ;
        }
        ਜੇ ((fi = fopen(argv[i_obj], "rb")) == ਨਿਰਾ) {
            fprintf(stderr, "tcc: ar: can't open file %s \n", argv[i_obj]);
            ਜਾਓ the_ਸਿਰਾ;
        }
        ਜੇ (verbose)
            ਲਿਖੋ("a - %s\n", argv[i_obj]);

        fseek(fi, 0, SEEK_END);
        fsize = ftell(fi);
        fseek(fi, 0, SEEK_SET);
        buf = tcc_malloc(fsize + 1);
        fread(buf, fsize, 1, fi);
        fclose(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        ਜੇ (ehdr->e_ident[4] != ELFCLASSW)
        {
            fprintf(stderr, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            ਜਾਓ the_ਸਿਰਾ;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (ਅੱਖਰ *)(buf + shdr->sh_ਵਿੱਥ);
        symtab = strtab = ਨਿਰਾ;
        ਲਈ (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            ਜੇ (!shdr->sh_ਵਿੱਥ)
                ਜਾਰੀ;
            ਜੇ (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (ਅੱਖਰ *)(buf + shdr->sh_ਵਿੱਥ);
                symtabsize = shdr->sh_ਮਾਪ;
            }
            ਜੇ (shdr->sh_type == SHT_STRTAB)
            {
                ਜੇ (!strcmp(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (ਅੱਖਰ *)(buf + shdr->sh_ਵਿੱਥ);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        ਜੇ (symtab && strtab)
        {
            ਪੂਰਨ nsym = symtabsize / ਆਕਾਰ(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            ਲਈ (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * ਆਕਾਰ(ElfW(Sym)));
                ਜੇ (sym->st_shndx &&
                    (sym->st_info == 0x10
                    || sym->st_info == 0x11
                    || sym->st_info == 0x12
                    || sym->st_info == 0x20
                    || sym->st_info == 0x21
                    || sym->st_info == 0x22
                    )) {
                    //printf("symtab: %2Xh %4Xh %2Xh %s\n", sym->st_info, sym->st_size, sym->st_shndx, strtab + sym->st_name);
                    istrlen = ਲੜੀ_ਲੰਬਾਈ(strtab + sym->st_name)+1;
                    anames = tcc_realloc(anames, strpos+istrlen);
                    strcpy(anames + strpos, strtab + sym->st_name);
                    strpos += istrlen;
                    ਜੇ (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * ਆਕਾਰ *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        ਲਈ (name = strchr(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = ਲੜੀ_ਲੰਬਾਈ(name);
        ਜੇ (istrlen >= ਆਕਾਰ(arhdro.ar_name))
            istrlen = ਆਕਾਰ(arhdro.ar_name) - 1;
        memset(arhdro.ar_name, ' ', ਆਕਾਰ(arhdro.ar_name));
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        sprintf(stmp, "%-10d", fsize);
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(&arhdro.ar_ਮਾਪ, stmp, 10);
        fwrite(&arhdro, ਆਕਾਰ(arhdro), 1, fo);
        fwrite(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + ਆਕਾਰ(arhdro));
        ਜੇ (fpos & 1)
            fputc(0, fo), ++fpos;
    }
    hofs = 8 + ਆਕਾਰ(arhdr) + strpos + (funccnt+1) * ਆਕਾਰ(ਪੂਰਨ);
    fpos = 0;
    ਜੇ ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    fwrite(ARMAG, 8, 1, fh);
    // create an empty archive
    ਜੇ (!funccnt) {
        ret = 0;
        ਜਾਓ the_ਸਿਰਾ;
    }
    sprintf(stmp, "%-10d", (ਪੂਰਨ)(strpos + (funccnt+1) * ਆਕਾਰ(ਪੂਰਨ)) + fpos);
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&arhdr.ar_ਮਾਪ, stmp, 10);
    fwrite(&arhdr, ਆਕਾਰ(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    ਲਈ (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    fwrite(afpos, (funccnt+1) * ਆਕਾਰ(ਪੂਰਨ), 1, fh);
    fwrite(anames, strpos, 1, fh);
    ਜੇ (fpos)
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
the_ਸਿਰਾ:
    ਜੇ (anames)
        tcc_free(anames);
    ਜੇ (afpos)
        tcc_free(afpos);
    ਜੇ (fh)
        fclose(fh);
    ਜੇ (created_file && ret != 0)
        remove(created_file);
    ਜੇ (fo)
        fclose(fo), remove(tfile);
    ਵਾਪਸ ret;
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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE

ST_FUNC ਪੂਰਨ tcc_tool_impdef(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਪੂਰਨ ret, v, i;
    ਅੱਖਰ infile[260];
    ਅੱਖਰ outfile[260];

    ਅਚਲ ਅੱਖਰ *file;
    ਅੱਖਰ *p, *q;
    FILE *fp, *op;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਅੱਖਰ ਰਸਤਾ[260];
#ਜੇ_ਅੰਤ

    infile[0] = outfile[0] = 0;
    fp = op = ਨਿਰਾ;
    ret = 1;
    p = ਨਿਰਾ;
    v = 0;

    ਲਈ (i = 1; i < argc; ++i) {
        ਅਚਲ ਅੱਖਰ *a = argv[i];
        ਜੇ ('-' == a[0]) {
            ਜੇ (0 == strcmp(a, "-v")) {
                v = 1;
            } ਨਹੀਂਤਾਂ ਜੇ (0 == strcmp(a, "-o")) {
                ਜੇ (++i == argc)
                    ਜਾਓ usage;
                strcpy(outfile, argv[i]);
            } ਨਹੀਂਤਾਂ
                ਜਾਓ usage;
        } ਨਹੀਂਤਾਂ ਜੇ (0 == infile[0])
            strcpy(infile, a);
        ਨਹੀਂਤਾਂ
            ਜਾਓ usage;
    }

    ਜੇ (0 == infile[0]) {
usage:
        fprintf(stderr,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        ਜਾਓ the_ਸਿਰਾ;
    }

    ਜੇ (0 == outfile[0]) {
        strcpy(outfile, tcc_basename(infile));
        q = strrchr(outfile, '.');
        ਜੇ (ਨਿਰਾ == q)
            q = strchr(outfile, 0);
        strcpy(q, ".def");
    }

    file = infile;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਜੇ (ਖੋਜ_ਰਸਤਾ(ਨਿਰਾ, file, ".dll", ਆਕਾਰ ਰਸਤਾ, ਰਸਤਾ, ਨਿਰਾ))
        file = ਰਸਤਾ;
#ਜੇ_ਅੰਤ
    ret = tcc_get_dllexports(file, &p);
    ਜੇ (ret || !p) {
        fprintf(stderr, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        ਜਾਓ the_ਸਿਰਾ;
    }

    ਜੇ (v)
        ਲਿਖੋ("-> %s\n", file);

    op = fopen(outfile, "wb");
    ਜੇ (ਨਿਰਾ == op) {
        fprintf(stderr, "tcc: impdef: could not create output file: %s\n", outfile);
        ਜਾਓ the_ਸਿਰਾ;
    }

    fprintf(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    ਲਈ (q = p, i = 0; *q; ++i) {
        fprintf(op, "%s\n", q);
        q += ਲੜੀ_ਲੰਬਾਈ(q) + 1;
    }

    ਜੇ (v)
        ਲਿਖੋ("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_ਸਿਰਾ:
    ਜੇ (p)
        tcc_free(p);
    ਜੇ (fp)
        fclose(fp);
    ਜੇ (op)
        fclose(op);
    ਵਾਪਸ ret;
}

#ਜੇ_ਅੰਤ /* TCC_TARGET_PE */

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

#ਜੇ !defined TCC_ਨਿਸ਼ਾਨਾ_I386 && !defined TCC_ਨਿਸ਼ਾਨਾ_X86_64

ST_FUNC ਪੂਰਨ tcc_tool_cross(ਅੱਖਰ **argv, ਪੂਰਨ option)
{
    fprintf(stderr, "tcc -m%d not implemented\n", option);
    ਵਾਪਸ 1;
}

#ਨਹੀਂਤਾਂ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਅਨ੍ਤਰ੍ਭਾਵ <process.h>

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
ਸਥਿਰ ਅੱਖਰ *quote_win32(ਅਚਲ ਅੱਖਰ *s)
{
    ਅੱਖਰ *o, *r = tcc_malloc(2 * ਲੜੀ_ਲੰਬਾਈ(s) + 3);   /* max-esc, quotes, \0 */
    ਪੂਰਨ cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    ਲਈ (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        ਜੇ (*s == '\\' || *s == '"')
            *o++ = '\\';
        ਨਹੀਂਤਾਂ
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    ਜੇ (quoted) {
        memmove(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } ਨਹੀਂਤਾਂ {
        o -= cbs;
    }

    *o = 0;
    ਵਾਪਸ r; /* don't bother with realloc(r, o-r+1) */
}

ਸਥਿਰ ਪੂਰਨ execvp_win32(ਅਚਲ ਅੱਖਰ *prog, ਅੱਖਰ **argv)
{
    ਪੂਰਨ ret; ਅੱਖਰ **p;
    /* replace all " by \" */
    ਲਈ (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (ਅਚਲ ਅੱਖਰ *ਅਚਲ*)argv);
    ਜੇ (-1 == ret)
        ਵਾਪਸ ret;
    _cwait(&ret, ret, WAIT_ਬੱਚਾ);
    ਬਾਹਰ_ਨਿਕਲੋ(ret);
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ execvp execvp_win32
#ਜੇ_ਅੰਤ /* _WIN32 */

ST_FUNC ਪੂਰਨ tcc_tool_cross(ਅੱਖਰ **argv, ਪੂਰਨ ਨਿਸ਼ਾਨਾ)
{
    ਅੱਖਰ ਪ੍ਰੋਗਰਾਮ[4096];
    ਅੱਖਰ *a0 = argv[0];
    ਪੂਰਨ ਅਗੇਤਰ = tcc_basename(a0) - a0;

    snprintf(ਪ੍ਰੋਗਰਾਮ, ਆਕਾਰ ਪ੍ਰੋਗਰਾਮ,
        "%.*s%s"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        "-win32"
#ਜੇ_ਅੰਤ
        "-tcc"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
        ".exe"
#ਜੇ_ਅੰਤ
        , ਅਗੇਤਰ, a0, ਨਿਸ਼ਾਨਾ == 64 ? "x86_64" : "i386");

    ਜੇ (strcmp(a0, ਪ੍ਰੋਗਰਾਮ))
        execvp(argv[0] = ਪ੍ਰੋਗਰਾਮ, argv);
    fprintf(stderr, "tcc: could not run '%s'\n", ਪ੍ਰੋਗਰਾਮ);
    ਵਾਪਸ 1;
}

#ਜੇ_ਅੰਤ /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
ਅਚਲ ਪੂਰਨ _CRT_glob = 1;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_glob
ਅਚਲ ਪੂਰਨ _dowildcard = 1;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

/* -------------------------------------------------------------- */
/* generate xxx.d file */

ਸਥਿਰ ਅੱਖਰ *escape_ਨਿਸ਼ਾਨਾ_dep(ਅਚਲ ਅੱਖਰ *s) {
    ਅੱਖਰ *res = tcc_malloc(ਲੜੀ_ਲੰਬਾਈ(s) * 2 + 1);
    ਪੂਰਨ j;
    ਲਈ (j = 0; *s; s++, j++) {
        ਜੇ (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    ਵਾਪਸ res;
}

ST_FUNC ਪੂਰਨ gen_makedeps(TCCState *s1, ਅਚਲ ਅੱਖਰ *ਨਿਸ਼ਾਨਾ, ਅਚਲ ਅੱਖਰ *filename)
{
    FILE *depout;
    ਅੱਖਰ buf[1024];
    ਅੱਖਰ **escaped_targets;
    ਪੂਰਨ i, k, ਅੰਕ_targets;

    ਜੇ (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, ਆਕਾਰ buf, "%.*s.d",
            (ਪੂਰਨ)(tcc_fileextension(ਨਿਸ਼ਾਨਾ) - ਨਿਸ਼ਾਨਾ), ਨਿਸ਼ਾਨਾ);
        filename = buf;
    }

    ਜੇ(!strcmp(filename, "-"))
        depout = fdopen(1, "w");
    ਨਹੀਂਤਾਂ
        /* XXX return err codes instead of error() ? */
        depout = fopen(filename, "w");
    ਜੇ (!depout)
        ਵਾਪਸ tcc_error_noabort("could not open '%s'", filename);
    ਜੇ (s1->verbose)
        ਲਿਖੋ("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_ਨਿਸ਼ਾਨਾ_deps * ਆਕਾਰ(*escaped_targets));
    ਅੰਕ_targets = 0;
    ਲਈ (i = 0; i<s1->nb_ਨਿਸ਼ਾਨਾ_deps; ++i) {
        ਲਈ (k = 0; k < i; ++k)
            ਜੇ (0 == strcmp(s1->ਨਿਸ਼ਾਨਾ_deps[i], s1->ਨਿਸ਼ਾਨਾ_deps[k]))
                ਜਾਓ ਅਗਲਾ;
        escaped_targets[ਅੰਕ_targets++] = escape_ਨਿਸ਼ਾਨਾ_dep(s1->ਨਿਸ਼ਾਨਾ_deps[i]);
    ਅਗਲਾ:;
    }

    fprintf(depout, "%s:", ਨਿਸ਼ਾਨਾ);
    ਲਈ (i = 0; i < ਅੰਕ_targets; ++i)
        fprintf(depout, " \\\n  %s", escaped_targets[i]);
    fprintf(depout, "\n");
    ਜੇ (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        ਲਈ (i = 1; i < ਅੰਕ_targets; ++i)
            fprintf(depout, "%s:\n", escaped_targets[i]);
    }
    ਲਈ (i = 0; i < ਅੰਕ_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    fclose(depout);
    ਵਾਪਸ 0;
}

/* -------------------------------------------------------------- */
