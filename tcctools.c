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

#समावेश "tcc.h"

//#define ARMAG  "!<arch>\n"
#घोषणा ARFMAG "`\n"

प्रकार काष्ठा {
    अक्षर ar_name[16];
    अक्षर ar_date[12];
    अक्षर ar_uid[6];
    अक्षर ar_gid[6];
    अक्षर ar_mode[8];
    अक्षर ar_आकार[10];
    अक्षर ar_fmag[2];
} ArHdr;

अटल अचिन्हित दीर्घ le2belong(अचिन्हित दीर्घ ul) {
    वापस ((ul & 0xFF0000)>>8)+((ul & 0xFF000000)>>24) +
        ((ul & 0xFF)<<24)+((ul & 0xFF00)<<8);
}

अटल पूर्णांक ar_usage(पूर्णांक ret) {
    ख_लिखो(मानक_त्रुटि, "usage: tcc -ar [crstvx] lib [files]\n");
    ख_लिखो(मानक_त्रुटि, "create library ([abdiopN] not supported).\n");
    वापस ret;
}

ST_FUNC पूर्णांक tcc_tool_ar(पूर्णांक argc, अक्षर **argv)
{
    अटल स्थिर ArHdr arhdr_init = {
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

    खाता *fi, *fh = शून्य, *fo = शून्य;
    स्थिर अक्षर *created_file = शून्य; // must delete on error
    ElfW(Ehdr) *ehdr;
    ElfW(Shdr) *shdr;
    ElfW(Sym) *sym;
    पूर्णांक i, fsize, i_lib, i_obj;
    अक्षर *buf, *shstr, *symtab, *strtab;
    पूर्णांक symtabsize = 0;//, strtabsize = 0;
    अक्षर *anames = शून्य;
    पूर्णांक *afpos = शून्य;
    पूर्णांक istrlen, strpos = 0, fpos = 0, funccnt = 0, funcmax, hofs;
    अक्षर tfile[260], stmp[20];
    अक्षर *file, *name;
    पूर्णांक ret = 2;
    स्थिर अक्षर *ops_conflict = "habdiopN";  // unsupported but destructive if ignored.
    पूर्णांक extract = 0;
    पूर्णांक table = 0;
    पूर्णांक verbose = 0;

    i_lib = 0; i_obj = 0;  // will hold the index of the lib and first obj
    क्रम (i = 1; i < argc; i++) {
        स्थिर अक्षर *a = argv[i];
        अगर (*a == '-' && म_अक्षर(a, '.'))
            ret = 1; // -x.y is always invalid (same as gnu ar)
        अगर ((*a == '-') || (i == 1 && !म_अक्षर(a, '.'))) {  // options argument
            अगर (strpbrk(a, ops_conflict))
                ret = 1;
            अगर (म_अक्षर(a, 'x'))
                extract = 1;
            अगर (म_अक्षर(a, 't'))
                table = 1;
            अगर (म_अक्षर(a, 'v'))
                verbose = 1;
        } अन्यथा {  // lib or obj files: don't abort - keep validating all args.
            अगर (!i_lib)  // first file is the lib
                i_lib = i;
            अन्यथा अगर (!i_obj)  // second file is the first obj
                i_obj = i;
        }
    }

    अगर (!i_lib)  // i_obj implies also i_lib.
        ret = 1;
    i_obj = i_obj ? i_obj : argc;  // An empty archive will be generated if no input file is given

    अगर (ret == 1)
        वापस ar_usage(ret);

    अगर (extract || table) {
        अगर ((fh = ख_खोलो(argv[i_lib], "rb")) == शून्य)
        {
            ख_लिखो(मानक_त्रुटि, "tcc: ar: can't open file %s\n", argv[i_lib]);
            जाओ finish;
        }
        ख_पढ़ो(stmp, 1, 8, fh);
	अगर (स_भेद(stmp,ARMAG,8))
	{
no_ar:
            ख_लिखो(मानक_त्रुटि, "tcc: ar: not an ar archive %s\n", argv[i_lib]);
            जाओ finish;
	}
	जबतक (ख_पढ़ो(&arhdr, 1, माप(arhdr), fh) == माप(arhdr)) {
	    अक्षर *p, *e;

	    अगर (स_भेद(arhdr.ar_fmag, ARFMAG, 2))
		जाओ no_ar;
	    p = arhdr.ar_name;
	    क्रम (e = p + माप arhdr.ar_name; e > p && e[-1] == ' ';)
		e--;
	    *e = '\0';
	    arhdr.ar_आकार[माप arhdr.ar_आकार-1] = 0;
	    fsize = म_से_प(arhdr.ar_आकार);
	    buf = tcc_malloc(fsize + 1);
	    ख_पढ़ो(buf, fsize, 1, fh);
	    अगर (म_भेद(arhdr.ar_name,"/") && म_भेद(arhdr.ar_name,"/SYM64/")) {
		अगर (e > p && e[-1] == '/')
		    e[-1] = '\0';
		/* tv not implemented */
	        अगर (table || verbose)
		    म_लिखो("%s%s\n", extract ? "x - " : "", arhdr.ar_name);
		अगर (extract) {
		    अगर ((fo = ख_खोलो(arhdr.ar_name, "wb")) == शून्य)
		    {
			ख_लिखो(मानक_त्रुटि, "tcc: ar: can't create file %s\n",
				arhdr.ar_name);
		        tcc_free(buf);
			जाओ finish;
		    }
		    ख_डालो(buf, fsize, 1, fo);
		    ख_बंद(fo);
		    /* ignore date/uid/gid/mode */
		}
	    }
            अगर (fsize & 1)
                ख_अक्षर_लो(fh);
            tcc_free(buf);
	}
	ret = 0;
finish:
	अगर (fh)
		ख_बंद(fh);
	वापस ret;
    }

    अगर ((fh = ख_खोलो(argv[i_lib], "wb")) == शून्य)
    {
        ख_लिखो(मानक_त्रुटि, "tcc: ar: can't create file %s\n", argv[i_lib]);
        जाओ the_end;
    }
    created_file = argv[i_lib];

    प्र_लिखो(tfile, "%s.tmp", argv[i_lib]);
    अगर ((fo = ख_खोलो(tfile, "wb+")) == शून्य)
    {
        ख_लिखो(मानक_त्रुटि, "tcc: ar: can't create temporary file %s\n", tfile);
        जाओ the_end;
    }

    funcmax = 250;
    afpos = tcc_realloc(शून्य, funcmax * माप *afpos); // 250 func
    स_नकल(&arhdro.ar_mode, "100644", 6);

    // i_obj = first input object file
    जबतक (i_obj < argc)
    {
        अगर (*argv[i_obj] == '-') {  // by now, all options start with '-'
            i_obj++;
            जारी;
        }
        अगर ((fi = ख_खोलो(argv[i_obj], "rb")) == शून्य) {
            ख_लिखो(मानक_त्रुटि, "tcc: ar: can't open file %s \n", argv[i_obj]);
            जाओ the_end;
        }
        अगर (verbose)
            म_लिखो("a - %s\n", argv[i_obj]);

        ख_जाओ(fi, 0, अंत_से);
        fsize = ख_बताओ(fi);
        ख_जाओ(fi, 0, शुरू_से);
        buf = tcc_malloc(fsize + 1);
        ख_पढ़ो(buf, fsize, 1, fi);
        ख_बंद(fi);

        // elf header
        ehdr = (ElfW(Ehdr) *)buf;
        अगर (ehdr->e_ident[4] != ELFCLASSW)
        {
            ख_लिखो(मानक_त्रुटि, "tcc: ar: Unsupported Elf Class: %s\n", argv[i_obj]);
            जाओ the_end;
        }

        shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize);
        shstr = (अक्षर *)(buf + shdr->sh_offset);
        symtab = strtab = शून्य;
        क्रम (i = 0; i < ehdr->e_shnum; i++)
        {
            shdr = (ElfW(Shdr) *) (buf + ehdr->e_shoff + i * ehdr->e_shentsize);
            अगर (!shdr->sh_offset)
                जारी;
            अगर (shdr->sh_type == SHT_SYMTAB)
            {
                symtab = (अक्षर *)(buf + shdr->sh_offset);
                symtabsize = shdr->sh_आकार;
            }
            अगर (shdr->sh_type == SHT_STRTAB)
            {
                अगर (!म_भेद(shstr + shdr->sh_name, ".strtab"))
                {
                    strtab = (अक्षर *)(buf + shdr->sh_offset);
                    //strtabsize = shdr->sh_size;
                }
            }
        }

        अगर (symtab && strtab)
        {
            पूर्णांक nsym = symtabsize / माप(ElfW(Sym));
            //printf("symtab: info size shndx name\n");
            क्रम (i = 1; i < nsym; i++)
            {
                sym = (ElfW(Sym) *) (symtab + i * माप(ElfW(Sym)));
                अगर (sym->st_shndx &&
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
                    अगर (++funccnt >= funcmax) {
                        funcmax += 250;
                        afpos = tcc_realloc(afpos, funcmax * माप *afpos); // 250 func more
                    }
                    afpos[funccnt] = fpos;
                }
            }
        }

        file = argv[i_obj];
        क्रम (name = म_अक्षर(file, 0);
             name > file && name[-1] != '/' && name[-1] != '\\';
             --name);
        istrlen = म_माप(name);
        अगर (istrlen >= माप(arhdro.ar_name))
            istrlen = माप(arhdro.ar_name) - 1;
        स_रखो(arhdro.ar_name, ' ', माप(arhdro.ar_name));
        स_नकल(arhdro.ar_name, name, istrlen);
        arhdro.ar_name[istrlen] = '/';
        प्र_लिखो(stmp, "%-10d", fsize);
        स_नकल(&arhdro.ar_आकार, stmp, 10);
        ख_डालो(&arhdro, माप(arhdro), 1, fo);
        ख_डालो(buf, fsize, 1, fo);
        tcc_free(buf);
        i_obj++;
        fpos += (fsize + माप(arhdro));
        अगर (fpos & 1)
            ख_अक्षर_दो(0, fo), ++fpos;
    }
    hofs = 8 + माप(arhdr) + strpos + (funccnt+1) * माप(पूर्णांक);
    fpos = 0;
    अगर ((hofs & 1)) // align
        hofs++, fpos = 1;
    // write header
    ख_डालो(ARMAG, 8, 1, fh);
    // create an empty archive
    अगर (!funccnt) {
        ret = 0;
        जाओ the_end;
    }
    प्र_लिखो(stmp, "%-10d", (पूर्णांक)(strpos + (funccnt+1) * माप(पूर्णांक)) + fpos);
    स_नकल(&arhdr.ar_आकार, stmp, 10);
    ख_डालो(&arhdr, माप(arhdr), 1, fh);
    afpos[0] = le2belong(funccnt);
    क्रम (i=1; i<=funccnt; i++)
        afpos[i] = le2belong(afpos[i] + hofs);
    ख_डालो(afpos, (funccnt+1) * माप(पूर्णांक), 1, fh);
    ख_डालो(anames, strpos, 1, fh);
    अगर (fpos)
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
    अगर (anames)
        tcc_free(anames);
    अगर (afpos)
        tcc_free(afpos);
    अगर (fh)
        ख_बंद(fh);
    अगर (created_file && ret != 0)
        हटाओ(created_file);
    अगर (fo)
        ख_बंद(fo), हटाओ(tfile);
    वापस ret;
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

#अगर_घोषित TCC_TARGET_PE

ST_FUNC पूर्णांक tcc_tool_impdef(पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक ret, v, i;
    अक्षर infile[260];
    अक्षर outfile[260];

    स्थिर अक्षर *file;
    अक्षर *p, *q;
    खाता *fp, *op;

#अगर_घोषित _WIN32
    अक्षर path[260];
#पूर्ण_अगर

    infile[0] = outfile[0] = 0;
    fp = op = शून्य;
    ret = 1;
    p = शून्य;
    v = 0;

    क्रम (i = 1; i < argc; ++i) {
        स्थिर अक्षर *a = argv[i];
        अगर ('-' == a[0]) {
            अगर (0 == म_भेद(a, "-v")) {
                v = 1;
            } अन्यथा अगर (0 == म_भेद(a, "-o")) {
                अगर (++i == argc)
                    जाओ usage;
                म_नकल(outfile, argv[i]);
            } अन्यथा
                जाओ usage;
        } अन्यथा अगर (0 == infile[0])
            म_नकल(infile, a);
        अन्यथा
            जाओ usage;
    }

    अगर (0 == infile[0]) {
usage:
        ख_लिखो(मानक_त्रुटि,
            "usage: tcc -impdef library.dll [-v] [-o outputfile]\n"
            "create export definition file (.def) from dll\n"
            );
        जाओ the_end;
    }

    अगर (0 == outfile[0]) {
        म_नकल(outfile, tcc_basename(infile));
        q = म_खोजप(outfile, '.');
        अगर (शून्य == q)
            q = म_अक्षर(outfile, 0);
        म_नकल(q, ".def");
    }

    file = infile;
#अगर_घोषित _WIN32
    अगर (खोज_Path(शून्य, file, ".dll", माप path, path, शून्य))
        file = path;
#पूर्ण_अगर
    ret = tcc_get_dllexports(file, &p);
    अगर (ret || !p) {
        ख_लिखो(मानक_त्रुटि, "tcc: impdef: %s '%s'\n",
            ret == -1 ? "can't find file" :
            ret ==  1 ? "can't read symbols" :
            ret ==  0 ? "no symbols found in" :
            "unknown file type", file);
        ret = 1;
        जाओ the_end;
    }

    अगर (v)
        म_लिखो("-> %s\n", file);

    op = ख_खोलो(outfile, "wb");
    अगर (शून्य == op) {
        ख_लिखो(मानक_त्रुटि, "tcc: impdef: could not create output file: %s\n", outfile);
        जाओ the_end;
    }

    ख_लिखो(op, "LIBRARY %s\n\nEXPORTS\n", tcc_basename(file));
    क्रम (q = p, i = 0; *q; ++i) {
        ख_लिखो(op, "%s\n", q);
        q += म_माप(q) + 1;
    }

    अगर (v)
        म_लिखो("<- %s (%d symbol%s)\n", outfile, i, &"s"[i<2]);

    ret = 0;

the_end:
    अगर (p)
        tcc_free(p);
    अगर (fp)
        ख_बंद(fp);
    अगर (op)
        ख_बंद(op);
    वापस ret;
}

#पूर्ण_अगर /* TCC_TARGET_PE */

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

#अगर !defined TCC_TARGET_I386 && !defined TCC_TARGET_X86_64

ST_FUNC पूर्णांक tcc_tool_cross(अक्षर **argv, पूर्णांक option)
{
    ख_लिखो(मानक_त्रुटि, "tcc -m%d not implemented\n", option);
    वापस 1;
}

#अन्यथा
#अगर_घोषित _WIN32
#समावेश <process.h>

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
अटल अक्षर *quote_win32(स्थिर अक्षर *s)
{
    अक्षर *o, *r = tcc_malloc(2 * म_माप(s) + 3);   /* max-esc, quotes, \0 */
    पूर्णांक cbs = 0, quoted = !*s;  /* consecutive backslashes before current */

    क्रम (o = r; *s; *o++ = *s++) {
        quoted |= *s == ' ' || *s == '\t';
        अगर (*s == '\\' || *s == '"')
            *o++ = '\\';
        अन्यथा
            o -= cbs;  /* undo cbs escapes, if any (not followed by DQ) */
        cbs = *s == '\\' ? cbs + 1 : 0;
    }
    अगर (quoted) {
        स_हटाओ(r + 1, r, o++ - r);
        *r = *o++ = '"';
    } अन्यथा {
        o -= cbs;
    }

    *o = 0;
    वापस r; /* don't bother with realloc(r, o-r+1) */
}

अटल पूर्णांक execvp_win32(स्थिर अक्षर *prog, अक्षर **argv)
{
    पूर्णांक ret; अक्षर **p;
    /* replace all " by \" */
    क्रम (p = argv; *p; ++p)
        *p = quote_win32(*p);
    ret = _spawnvp(P_NOWAIT, prog, (स्थिर अक्षर *स्थिर*)argv);
    अगर (-1 == ret)
        वापस ret;
    _cwait(&ret, ret, WAIT_CHILD);
    निकास(ret);
}
#घोषणा execvp execvp_win32
#पूर्ण_अगर /* _WIN32 */

ST_FUNC पूर्णांक tcc_tool_cross(अक्षर **argv, पूर्णांक target)
{
    अक्षर program[4096];
    अक्षर *a0 = argv[0];
    पूर्णांक prefix = tcc_basename(a0) - a0;

    snprintf(program, माप program,
        "%.*s%s"
#अगर_घोषित TCC_TARGET_PE
        "-win32"
#पूर्ण_अगर
        "-tcc"
#अगर_घोषित _WIN32
        ".exe"
#पूर्ण_अगर
        , prefix, a0, target == 64 ? "x86_64" : "i386");

    अगर (म_भेद(a0, program))
        execvp(argv[0] = program, argv);
    ख_लिखो(मानक_त्रुटि, "tcc: could not run '%s'\n", program);
    वापस 1;
}

#पूर्ण_अगर /* TCC_TARGET_I386 && TCC_TARGET_X86_64 */
/* -------------------------------------------------------------- */
/* enable commandline wildcard expansion (tcc -o x.exe *.c) */

#अगर_घोषित _WIN32
स्थिर पूर्णांक _CRT_glob = 1;
#अगर_अघोषित _CRT_glob
स्थिर पूर्णांक _dowildcard = 1;
#पूर्ण_अगर
#पूर्ण_अगर

/* -------------------------------------------------------------- */
/* generate xxx.d file */

अटल अक्षर *escape_target_dep(स्थिर अक्षर *s) {
    अक्षर *res = tcc_malloc(म_माप(s) * 2 + 1);
    पूर्णांक j;
    क्रम (j = 0; *s; s++, j++) {
        अगर (is_space(*s)) {
            res[j++] = '\\';
        }
        res[j] = *s;
    }
    res[j] = '\0';
    वापस res;
}

ST_FUNC पूर्णांक gen_makedeps(TCCState *s1, स्थिर अक्षर *target, स्थिर अक्षर *filename)
{
    खाता *depout;
    अक्षर buf[1024];
    अक्षर **escaped_targets;
    पूर्णांक i, k, अंक_targets;

    अगर (!filename) {
        /* compute filename automatically: dir/file.o -> dir/file.d */
        snprintf(buf, माप buf, "%.*s.d",
            (पूर्णांक)(tcc_fileextension(target) - target), target);
        filename = buf;
    }

    अगर(!म_भेद(filename, "-"))
        depout = fdopen(1, "w");
    अन्यथा
        /* XXX return err codes instead of error() ? */
        depout = ख_खोलो(filename, "w");
    अगर (!depout)
        वापस tcc_error_noabort("could not open '%s'", filename);
    अगर (s1->verbose)
        म_लिखो("<- %s\n", filename);

    escaped_targets = tcc_malloc(s1->nb_target_deps * माप(*escaped_targets));
    अंक_targets = 0;
    क्रम (i = 0; i<s1->nb_target_deps; ++i) {
        क्रम (k = 0; k < i; ++k)
            अगर (0 == म_भेद(s1->target_deps[i], s1->target_deps[k]))
                जाओ अग्र;
        escaped_targets[अंक_targets++] = escape_target_dep(s1->target_deps[i]);
    अग्र:;
    }

    ख_लिखो(depout, "%s:", target);
    क्रम (i = 0; i < अंक_targets; ++i)
        ख_लिखो(depout, " \\\n  %s", escaped_targets[i]);
    ख_लिखो(depout, "\n");
    अगर (s1->gen_phony_deps) {
        /* Skip first file, which is the c file.
         * Only works for single file give on command-line,
         * but other compilers have the same limitation */
        क्रम (i = 1; i < अंक_targets; ++i)
            ख_लिखो(depout, "%s:\n", escaped_targets[i]);
    }
    क्रम (i = 0; i < अंक_targets; ++i)
        tcc_free(escaped_targets[i]);
    tcc_free(escaped_targets);
    ख_बंद(depout);
    वापस 0;
}

/* -------------------------------------------------------------- */
