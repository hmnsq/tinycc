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

#अन्तर्भाव "tcc.h"

//#define ARMAG  "!<arch>\n"
#define ARFMAG "`\n"

प्रकारव्याख्या संरचना {
    अक्षर ar_name[16];
    अक्षर ar_date[12];
    अक्षर ar_uid[6];
    अक्षर ar_gid[6];
    अक्षर ar_mode[8];
    अक्षर ar_size[10];
    अक्षर ar_fmag[2];
} ArHdr;

स्थिर अचिन्हित दीर्घ le2belong(अचिन्हित दीर्घ ul) {
    परत ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

स्थिर पूर्णांक ar_usage(पूर्णांक ret) {
    ख_लिखो(मानक_त्रुटि, "usage: tcc -ar [crstvx] lib [files]\n");
    ख_लिखो(मानक_त्रुटि, "create library ([abdiopN] not supported).\n");
    परत ret;
}

ST_FUNC पूर्णांक tcc_tool_ar(पूर्णांक argc, अक्षर **argv)
{
    स्थिर स्थिरांक ArHdr arhdr_init = {
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

    खाता *fi, *fh = रिक्त, *fo = रिक्त;
    स्थिरांक अक्षर *created_file = रिक्त; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    पूर्णांक i, fsize, i_lib, i_obj;
    अक्षर *buf, *shstr, *symtab, *strtab;
    पूर्णांक symtabsize = 0;//, strtabsize = 0;
    अक्षर *anames = रिक्त;
    पूर्णांक *afpos = रिक्त;
    पूर्णांक istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    अक्षर tfile[260], stmp[20];
    अक्षर *file, *name;
    पूर्णांक ret = 2;
    स्थिरांक अक्षर *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    पूर्णांक extract = 0;
    पूर्णांक table = 0;
    पूर्णांक verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    साठी (i = 1; i < argc; i++) {
        स्थिरांक अक्षर *a = argv[i];
        जर (*a == '-' && म_अक्षर(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        जर ((*a == '-') || (i == 1 && !म_अक्षर(a, '.'))) {  // options argument
            जर (strpbrk(a, ops_conflict))
                ret = 1;
            जर (म_अक्षर(a, 'x'))
                extract = 1;
            जर (म_अक्षर(a, 't'))
                table = 1;
            जर (म_अक्षर(a, 'v'))
                verbose = 1;
        } अन्यथा {  // lib or obj files: don't abort - keep validating all args.
            जर (!i_lib)  // first file is the lib
                i_lib = i;
            अन्यथा जर (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    जर (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    जर (ret == 1)
        परत ar_usage(ret);

    जर (extract || table) {
        जर ((fh = ख_खोलो(argv[i_lib], "rb")) == रिक्त)
        {
            ख_लिखो(मानक_त्रुटि, "tcc: ar: can't open file %s\n", argv[i_lib]);
            जा finish;
        }
        ख_पढ़ो(stmp, 1, 8, fh);
	जर (स_भेद(stmp,ARMAG,8))
	{
no_ar:
            ख_लिखो(मानक_त्रुटि, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            जा finish;
	}
	पर्यंत (ख_पढ़ो(&arhdr, 1, आकार(arhdr), fh) == आकार(arhdr)) {
	    अक्षर *p, *e;

	    जर (स_भेद(arhdr.ar_fmag, ARFMAG, 2))
		जा no_ar;
	    p = arhdr.ar_name;
	    साठी (e = p + आकार arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_size[आकार arhdr.ar_size-1] = 0;
	    fsize = म_से_प(arhdr.ar_size);
	    buf = tcc_malloc(fsize + 1);
	    ख_पढ़ो(buf, fsize, 1, fh);
	    जर (म_भेद(arhdr.ar_name,"/") && म_भेद(arhdr.ar_name,"/SYM64/")) {
		जर (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        जर (table || verbose)
		    म_लिखो("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		जर (extract) {
		    जर ((fo = ख_खोलो(arhdr.ar_name, "wb")) == रिक्त)
		    {
			ख_लिखो(मानक_त्रुटि, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			जा finish;
		    }
		    ख_डालो(buf, fsize, 1, fo);
		    ख_बंद(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            जर (fsize & 1)
                ख_अक्षर_लो(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	जर (fh)
		ख_बंद(fh);
	परत ret;
    }

    जर ((fh = ख_खोलो(argv[i_lib], "wb")) == रिक्त)
    {
        ख_लिखो(मानक_त्रुटि, "tcc: ar: can't create file %s\n", argv[i_lib]);
        जा the_end;
    }
    created_file = argv[i_lib];

    प्र_लिखो(tfile, "%s.tmp", argv[i_lib]);
    जर ((fo = ख_खोलो(tfile, "wb+")) == रिक्त)
    {
        ख_लिखो(मानक_त्रुटि, "tcc: ar: can't create temporary file %s\n", tfile);
        जा the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(रिक्त, funcmax * आकार *afpos); // 250 func
    स_नकल(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    पर्यंत (i_obj < argc)
    {
        जर (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            सुरूठेवा;
        }
        जर ((fi = ख_खोलो(argv[i_obj], "rb")) == रिक्त) {
            ख_लिखो(मानक_त्रुटि, "tcc: ar: can't open file %s \n", argv[i_obj]);
            जा the_end;
        }
        जर (verbose)
            म_लिखो("a - %s\n", argv[i_obj]);

        ख_जाओ(fi, 0, अंत_से);
        fsize = ख_बताओ(fi);
        ख_जाओ(fi, 0, शुरू_से);
        buf = tcc_malloc(fsize + 1);
        ख_पढ़ो(buf, fsize, 1, fi);
        ख_बंद(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        जर (ehdr->e_ident[4] != ELFCLASSW)
        {
            ख_लिखो(मानक_त्रुटि, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            जा the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (अक्षर *)(buf + shdr->sh_offset);
        symtab = strtab = रिक्त;
        साठी (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            जर (!shdr->sh_offset)
                सुरूठेवा;
            जर (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (अक्षर *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_size;
            }
            जर (shdr->sh_type == SHT_STRTAB)
            {
                जर (!म_भेद(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (अक्षर *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        जर (symtab && strtab)
        {
            पूर्णांक nsym = symtabsize / आकार(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            साठी (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * आकार(ElfW(Sym)));
                जर (sym->st_shndx &&
                    (sym->st_info == 0x10
                    || sym->st_info == 0x11
                    || sym->st_info == 0x12
                    || sym->st_info == 0x20
                    || sym->st_info == 0x21
                    || sym->st_info == 0x22
                    )) {
                    //printf("symtab: %2Xh %4Xh %2Xh %s\n", sym->st_info, sym->st_size, sym->st_shndx, strtab + sym->st_name);
                    istrlen = म_माप(strtab + sym->st_name)+1;
                    anames = tcc_realloc(anames, strpos+istrlen);
                    म_नकल(anames + strpos, strtab + sym->st_name);
                    strpos += istrlen;
                    जर (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * आकार *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        साठी (name = म_अक्षर(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = म_माप(name);
        जर (istrlen >= आकार(arhdro.ar_name))
            istrlen = आकार(arhdro.ar_name) - 1;
        स_रखो(arhdro.ar_name, ' ', आकार(arhdro.ar_name));
        स_नकल(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        प्र_लिखो(stmp, "%-10d", fsize);
        स_नकल(&arhdro.ar_size, stmp, 10);
        ख_डालो(&arhdro, आकार(arhdro), 1, fo);
        ख_डालो(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + आकार(arhdro));
        जर (fpos & 1)
            ख_अक्षर_दो(0, fo), ++fpos;
    }
    hofs = 8 + आकार(arhdr) + strpos + (funccnt+1) * आकार(पूर्णांक);
    fpos = 0;
    जर ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    ख_डालो(ARMAG, 8, 1, fh);
    // create an empty archive
    जर (!funccnt) {
        ret = 0;
        जा the_end;
    }
    प्र_लिखो(stmp, "%-10d", (पूर्णांक)(strpos + (funccnt+1) * आकार(पूर्णांक)) + fpos);
    स_नकल(&arhdr.ar_size, stmp, 10);
    ख_डालो(&arhdr, आकार(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    साठी (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    ख_डालो(afpos, (funccnt+1) * आकार(पूर्णांक), 1, fh);
    ख_डालो(anames, strpos, 1, fh);
    जर (fpos)
        ख_डालो("", 1, 1, fh);
    // write objects
    ख_जाओ(fo, 0, अंत_से);
    fsize = ख_बताओ(fo);
    ख_जाओ(fo, 0, शुरू_से);
    buf = tcc_malloc(fsize + 1);
    ख_पढ़ो(buf, fsize, 1, fo);
    ख_डालो(buf, fsize, 1, fh);
    tcc_free(buf);
    ret = 0;
the_end:
    जर (anames)
        tcc_free(anames);
    जर (afpos)
        tcc_free(afpos);
    जर (fh)
        ख_बंद(fh);
    जर (created_file && ret != 0)
        हटाओ(created_file);
    जर (fo)
        ख_बंद(fo), हटाओ(tfile);
    परत ret;
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

ST_FUNC पूर्णांक tcc_tool_impdef(पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक ret, v, i;
    अक्षर infile[260];
    अक्षर outfile[260];

    स्थिरांक अक्षर *file;
    अक्षर *p, *q;
    खाता *fp, *op;

#ifdef _WIN32
    अक्षर path[260];
#endif

    infile[0] = outfile[0] = 0;
    fp = op = रिक्त;
    ret = 1;
    p = रिक्त;
    v = 0;

    साठी (i = 1; i < argc; ++i) {
        स्थिरांक अक्षर *a = argv[i];
        जर ('-' == a[0]) {
            जर (0 == म_भेद(a, "-v")) {
                v = 1;
            } अन्यथा जर (0 == म_भेद(a, "-o")) {
                जर (++i == argc)
                    जा usage;
                म_नकल(outfile, argv[i]);
            } अन्यथा
                जा usage;
        } अन्यथा जर (0 == infile[0])
            म_नकल(infile, a);
        अन्यथा
            जा usage;
    }

    जर (0 == infile[0]) {
usage:
        ख_लिखो(मानक_त्रुटि,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        जा the_end;
    }

    जर (0 == outfile[0]) {
        म_नकल(outfile, tcc_basename(infile));
        q = म_खोजप(outfile, '.');
        जर (रिक्त == q)
            q = म_अक्षर(outfile, 0);
        म_नकल(q, ".def");
    }

    file = infile;
#ifdef _WIN32
    जर (शोध_Path(रिक्त, file, ".dll", आकार path, path, रिक्त))
        file = path;
#endif
    ret = tcc_get_dllexports(file, &p);
    जर (ret || !p) {
        ख_लिखो(मानक_त्रुटि, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        जा the_end;
    }

    जर (v)
        म_लिखो("-> %s\n", file);

    op = ख_खोलो(outfile, "wb");
    जर (रिक्त == op) {
        ख_लिखो(मानक_त्रुटि, "tcc: impdef: could not create output file: %s\n", outfile);
        जा the_end;
    }

    ख_लिखो(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    साठी (q = p, i = 0; *q; ++i) {
        ख_लिखो(op, "%s\n", q);
        q += म_माप(q) + 1;
    }

    जर (v)
        म_लिखो("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    जर (p)
        tcc_free(p);
    जर (fp)
        ख_बंद(fp);
    जर (op)
        ख_बंद(op);
    परत ret;
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

#जर !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC पूर्णांक tcc_tool_cross(अक्षर **argv, पूर्णांक option)
{
    ख_लिखो(मानक_त्रुटि, "tcc -m%d not implemented\n", option);
    परत 1;
}

#अन्यथा
#ifdef _WIN32
#अन्तर्भाव <process.h>

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
स्थिर अक्षर *quote_win32(स्थिरांक अक्षर *s)
{
    अक्षर *o, *r = tcc_malloc(2 * म_माप(s) + 3);   /* max-esc, quotes, \0 */
    पूर्णांक cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    साठी (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        जर (*s == '\\' || *s == '"')
            *o++ = '\\';
        अन्यथा
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    जर (quoted) {
        स_हटाओ(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } अन्यथा {
        o -= cbs;
    }

    *o = 0;
    परत r; /* don't bother with realloc(r, o-r+1) */
}

स्थिर पूर्णांक execvp_win32(स्थिरांक अक्षर *prog, अक्षर **argv)
{
    पूर्णांक ret; अक्षर **p;
    /* replace all " by \" */
    साठी (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (स्थिरांक अक्षर *स्थिरांक*)argv);
    जर (-1 == ret)
        परत ret;
    _cwait(&ret, ret, WAIT_CHILD);
    निकास(ret);
}
#define execvp execvp_win32
#endif /* _WIN32 */

ST_FUNC पूर्णांक tcc_tool_cross(अक्षर **argv, पूर्णांक target)
{
    अक्षर program[4096];
    अक्षर *a0 = argv[0];
    पूर्णांक prefix = tcc_basename(a0) - a0;

    snprintf(program, आकार program,
        "%.*s%s"
#ifdef TCC_TARGET_PE
        "-win32"
#endif
        "-tcc"
#ifdef _WIN32
        ".exe"
#endif
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    जर (म_भेद(a0, program))
        execvp(argv[0] = program, argv);
    ख_लिखो(मानक_त्रुटि, "tcc: could not run '%s'\n", program);
    परत 1;
}

#endif /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#ifdef _WIN32
स्थिरांक पूर्णांक _CRT_glob = 1;
#ifndef _CRT_glob
स्थिरांक पूर्णांक _dowildcard = 1;
#endif
#endif

/* -------------------------------------------------------------- */
/* generate xxx.d file */

स्थिर अक्षर *escape_target_dep(स्थिरांक अक्षर *s) {
    अक्षर *res = tcc_malloc(म_माप(s) * 2 + 1);
    पूर्णांक j;
    साठी (j = 0; *s; s++, j++) {
        जर (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    परत res;
}

ST_FUNC पूर्णांक gen_makedeps(TCCState *s1, स्थिरांक अक्षर *target, स्थिरांक अक्षर *filename)
{
    खाता *depout;
    अक्षर buf[1024];
    अक्षर **escaped_targets;
    पूर्णांक i, k, अंक_targets;

    जर (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, आकार buf, "%.*s.d",
            (पूर्णांक)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    जर(!म_भेद(filename, "-"))
        depout = fdopen(1, "w");
    अन्यथा
        /* XXX return err codes instead of error() ? */
        depout = ख_खोलो(filename, "w");
    जर (!depout)
        परत tcc_error_noabort("could not open '%s'", filename);
    जर (s1->verbose)
        म_लिखो("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * आकार(*escaped_targets));
    अंक_targets = 0;
    साठी (i = 0; i<s1->nb_target_deps; ++i) {
        साठी (k = 0; k < i; ++k)
            जर (0 == म_भेद(s1->target_deps[i], s1->target_deps[k]))
                जा next;
        escaped_targets[अंक_targets++] = escape_target_dep(s1->target_deps[i]);
    next:;
    }

    ख_लिखो(depout, "%s:", target);
    साठी (i = 0; i < अंक_targets; ++i)
        ख_लिखो(depout, " \\\n  %s", escaped_targets[i]);
    ख_लिखो(depout, "\n");
    जर (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        साठी (i = 1; i < अंक_targets; ++i)
            ख_लिखो(depout, "%s:\n", escaped_targets[i]);
    }
    साठी (i = 0; i < अंक_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    ख_बंद(depout);
    परत 0;
}

/* -------------------------------------------------------------- */
