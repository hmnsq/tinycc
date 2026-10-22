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

#यदि_अपरिभाषितम् ONE_SOURCE
# define ONE_SOURCE 1
#यदि_अन्तः

#अन्तर्भाव "tcc.h"
#यदि ONE_SOURCE
# include "libtcc.c"
#यदि_अन्तः
#अन्तर्भाव "tcctools.c"

स्थिर ध्रुव वर्ण help[] =
    "Tiny C Compiler "TCC_संस्करणम्" - Copyright (C) 2001-2006 Fabrice Bellard\n"
    "Usage: tcc [options...] [-o outfile] [-c] infile(s)...\n"
    "       tcc [options...] -run infile (or --) [arguments...]\n"
    "General options:\n"
    "  -c           compile only - generate an object file\n"
    "  -o outfile   set output filename\n"
    "  -run         run compiled source\n"
    "  -fflag       set or reset (with 'no-' prefix) 'flag' (see tcc -hh)\n"
    "  -Wwarning    set or reset (with 'no-' prefix) 'warning' (see tcc -hh)\n"
    "  -w           disable all warnings\n"
    "  -v --version show version\n"
    "  -vv          show search paths or loaded files\n"
    "  -h -hh       show this, show more help\n"
    "  -bench       show compilation statistics\n"
    "  -            use stdin pipe as infile\n"
    "  @listfile    read arguments from listfile\n"
    "Preprocessor options:\n"
    "  -Idir        add include path 'dir'\n"
    "  -Dsym[=val]  define 'sym' with value 'val'\n"
    "  -Usym        undefine 'sym'\n"
    "  -E           preprocess only\n"
    "  -nostdinc    do not use standard system include paths\n"
    "Linker options:\n"
    "  -Ldir        add library path 'dir'\n"
    "  -llib        link with dynamic or static library 'lib'\n"
    "  -nostdlib    do not link with standard crt and libraries\n"
    "  -r           generate (relocatable) object file\n"
    "  -rdynamic    export all global symbols to dynamic linker\n"
    "  -shared      generate a shared library/dll\n"
    "  -soname      set name for shared library to be used at runtime\n"
    "  -Wl,-opt[=val]  set linker option (see tcc -hh)\n"
    "Debugger options:\n"
    "  -g           generate stab runtime debug info\n"
    "  -gdwarf[-x]  generate dwarf runtime debug info\n"
#यदि_परिभाषितम् TCC_TARGET_PE
    "  -g.pdb       create .pdb debug database\n"
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    "  -b           compile with built-in memory and bounds checker (implies -g)\n"
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    "  -bt[N]       link with backtrace (stack dump) support [show max N callers]\n"
#यदि_अन्तः
    "Misc. options:\n"
    "  -std=version define __STDC_VERSION__ according to version (c11/gnu11)\n"
    "  -x[c|a|b|n]  specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -Bdir        set tcc's private include/library dir\n"
    "  -M[M]D       generate make dependency file [ignore system files]\n"
    "  -M[M]        as above but no other output\n"
    "  -MF file     specify dependency file name\n"
#यदि defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    "  -m32/64      defer to i386/x86_64 cross compiler\n"
#यदि_अन्तः
    "Tools:\n"
    "  create library  : tcc -ar [crstvx] lib [files]\n"
#यदि_परिभाषितम् TCC_TARGET_PE
    "  create def file : tcc -impdef lib.dll [-v] [-o lib.def]\n"
#यदि_अन्तः
    "Discussion & bug reports:\n"
    "  https://lists.nongnu.org/mailman/listinfo/tinycc-devel\n"
    ;

स्थिर ध्रुव वर्ण help2[] =
    "Tiny C Compiler "TCC_संस्करणम्" - More Options\n"
    "Special options:\n"
    "  -P -P1                        with -E: no/alternative #line output\n"
    "  -dD -dM                       with -E: output #define directives\n"
    "  -pthread                      same as -D_REENTRANT and -lpthread\n"
    "  -On                           same as -D__OPTIMIZE__ for n > 0\n"
    "  -Wp,-opt                      same as -opt\n"
    "  -include file                 include 'file' above each input file\n"
    "  -nostdlib                     do not link with standard crt/libs\n"
    "  -isystem dir                  add 'dir' to system include path\n"
    "  -static                       link to static libraries (not recommended)\n"
    "  -dumpversion                  print version\n"
    "  -print-search-dirs            print search paths\n"
    "  -rstdin file                  with -run: use 'file' as custom stdin\n"
    "  -dt                           with -run/-E: auto-define 'test_...' macros\n"
    "Ignored options:\n"
    "  -arch -C --param -pedantic -pipe -s -traditional\n"
    "-W[no-]... warnings:\n"
    "  all                           turn on some (*) warnings\n"
    "  error[=warning]               stop after warning (any or specified)\n"
    "  write-strings                 strings are const\n"
    "  unsupported                   warn about ignored options, pragmas, etc.\n"
    "  implicit-function-declaration warn for missing prototype (*)\n"
    "  discarded-qualifiers          warn when const is dropped (*)\n"
    "-f[no-]... flags:\n"
    "  unsigned-char                 default char is unsigned\n"
    "  signed-char                   default char is signed\n"
    "  common                        use common section instead of bss\n"
    "  leading-underscore            decorate extern symbols\n"
    "  ms-extensions                 allow anonymous struct in struct\n"
    "  dollars-in-identifiers        allow '$' in C symbols\n"
    "  reverse-funcargs              evaluate function arguments right to left\n"
    "  gnu89-inline                  'extern inline' is like 'static inline'\n"
    "  asynchronous-unwind-tables    create eh_frame section [on]\n"
    "  test-coverage                 create code coverage code\n"
    "-m... target specific options:\n"
    "  ms-bitfields                  use MSVC bitfield layout\n"
#यदि_परिभाषितम् TCC_TARGET_ARM
    "  float-abi                     hard/softfp on arm\n"
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_X86_64
    "  no-sse                        disable floats on x86_64\n"
#यदि_अन्तः
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not search standard library paths\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#यदि_परिभाषितम् TCC_TARGET_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < nul\n"
#अन्यथा
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#यदि defined(TCC_TARGET_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#अन्यथा
    "  -Ipath, -dynamic-linker=path  set ELF interpreter to path\n"
#यदि_अन्तः
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -Map= -as-needed -O -z= (ignored)\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < /dev/null\n"
#यदि_अन्तः
    "See also the manual for more details.\n"
    ;

स्थिर ध्रुव वर्ण संस्करणम्[] =
    "tcc version "TCC_संस्करणम्
#यदि_परिभाषितम् TCC_GITHASH
    " "TCC_GITHASH
#यदि_अन्तः
    " ("
#यदि_परिभाषितम् TCC_TARGET_I386
        "i386"
#नोचेद्यदि defined TCC_TARGET_X86_64
        "x86_64"
#नोचेद्यदि defined TCC_TARGET_C67
        "C67"
#नोचेद्यदि defined TCC_TARGET_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#नोचेद्यदि defined TCC_TARGET_ARM64
        "AArch64"
#नोचेद्यदि defined TCC_TARGET_RISCV64
        "riscv64"
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_PE
        " Windows"
#नोचेद्यदि defined(TCC_TARGET_MACHO)
        " Darwin"
#नोचेद्यदि TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#नोचेद्यदि TARGETOS_OpenBSD
        " OpenBSD"
#नोचेद्यदि TARGETOS_NetBSD
        " NetBSD"
#अन्यथा
        " Linux"
#यदि_अन्तः
    ")\n"
    ;

स्थिर शून्य print_dirs(ध्रुव वर्ण *सन्देशः, वर्ण **paths, पूर्णाङ्क nb_paths)
{
    पूर्णाङ्क i;
    प्रारूप_लिख("%s:\n%s", सन्देशः, nb_paths ? "" : "  -\n");
    प्रति(i = 0; i < nb_paths; i++)
        प्रारूप_लिख("  %s\n", paths[i]);
}

स्थिर शून्य print_अन्वेषणम्_dirs(TCCState *s)
{
    प्रारूप_लिख("install: %s\n", s->tcc_lib_मार्गः);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    प्रारूप_लिख("libtcc1:\n  %s/%s\n", s->library_paths[0], CONFIG_TCC_CROSSPREFIX TCC_LIBTCC1);
#यदि_परिभाषितम् TCC_TARGET_UNIX
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    प्रारूप_लिख("elfinterp:\n  %s\n",  s->elfint);
#यदि_अन्तः
}

स्थिर शून्य समुच्चयः_environment(TCCState *s)
{
    वर्ण * मार्गः;

    मार्गः = getenv("C_INCLUDE_PATH");
    यदि(मार्गः != रिक्त) {
        tcc_सङ्कलय_sysinclude_मार्गः(s, मार्गः);
    }
    मार्गः = getenv("CPATH");
    यदि(मार्गः != रिक्त) {
        tcc_सङ्कलय_include_मार्गः(s, मार्गः);
    }
    मार्गः = getenv("LIBRARY_PATH");
    यदि(मार्गः != रिक्त) {
        tcc_सङ्कलय_library_मार्गः(s, मार्गः);
    }
}

स्थिर वर्ण *default_outputfile(TCCState *s, ध्रुव वर्ण *first_file)
{
    वर्ण buf[1024];
    वर्ण *ext;
    ध्रुव वर्ण *name = "a";

    यदि (first_file && वाक्यं_तुलय(first_file, "-"))
        name = tcc_basename(first_file);
    यदि (वाक्यदैर्घ्यम्(name) + 4 >= परिमाण buf)
        name = "a";
    वाक्यं_प्रतिलिख(buf, name);
    ext = tcc_fileextension(buf);
#यदि_परिभाषितम् TCC_TARGET_PE
    यदि (s->output_type == TCC_OUTPUT_DLL)
        वाक्यं_प्रतिलिख(ext, ".dll");
    अन्यथा
    यदि (s->output_type == TCC_OUTPUT_EXE)
        वाक्यं_प्रतिलिख(ext, ".exe");
    अन्यथा
#यदि_अन्तः
    यदि ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        वाक्यं_प्रतिलिख(ext, ".o");
    अन्यथा
        वाक्यं_प्रतिलिख(buf, "a.out");
    प्रत्यागम tcc_strdup(buf);
}

स्थिर अचिह्नित getclock_ms(शून्य)
{
#यदि_परिभाषितम् _WIN32
    प्रत्यागम Get_Tick_गणनम्();
#अन्यथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    प्रत्यागम tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#यदि_अन्तः
}

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    TCCState *s, *s1;
    पूर्णाङ्क ret, opt, n = 0, t = 0, समाप्तम्;
    अचिह्नित start_time = 0, अन्तः_time = 0;
    ध्रुव वर्ण *first_file;
    पूर्णाङ्क argc0 = argc;
    वर्ण **argv0 = argv;
    FILE *ppfp = रिक्त;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_तर्काः(s, &argc, &argv);

    यदि (n == 0) {
        ret = 0;
        यदि (opt == OPT_HELP) {
            fputs(help, stdout);
            यदि (s->verbose)
                गच्छ help2;
        } अन्यथा यदि (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } अन्यथा यदि (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } अन्यथा यदि (s->verbose)
            प्रारूप_लिख("%s", संस्करणम्);

        यदि (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#यदि_परिभाषितम् TCC_TARGET_PE
        यदि (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#यदि_अन्तः
        यदि (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            समुच्चयः_environment(s);
            tcc_समुच्चयः_output_type(s, TCC_OUTPUT_स्मृतिः);
            print_अन्वेषणम्_dirs(s);
        }
        यदि (opt) {
            यदि (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            प्रत्यागम ret;
        }
        यदि (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } अन्यथा यदि (s->output_type == TCC_OUTPUT_PREPROCESS) {
            यदि (s->outfile && 0!=वाक्यं_तुलय("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                यदि (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } अन्यथा यदि (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            यदि (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            अन्यथा यदि (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        यदि (s->nb_errors)
            गच्छ err;
        यदि (s->do_bench)
            start_time = getclock_ms();
    }

    समुच्चयः_environment(s);
    यदि (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_समुच्चयः_output_type(s, s->output_type);
    यदि (ppfp)
        s->ppfp = ppfp;

    यदि ((s->output_type == TCC_OUTPUT_स्मृतिः
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        यदि (t)
            s->dflag |= 32;
        s->सततम्_test = ++t;
        यदि (n)
            --n;
    }

    /* compile or add each files or library */
    first_file = रिक्त;
    यावत् (0 == ret) {
        संरचना filespec *f = s->files[n];
        s->filetype = f->type;
        यदि (f->type & AFF_TYPE_LIB) {
            ret = tcc_सङ्कलय_library(s, f->name);
        } अन्यथा {
            यदि (1 == s->verbose)
                प्रारूप_लिख("-> %s\n", f->name);
            यदि (!first_file)
                first_file = f->name;
            ret = tcc_सङ्कलय_file(s, f->name);
        }
        यदि (++n == s->nb_files)
            भङ्ग;
        यदि (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            भङ्ग;
    }

    यदि (s->do_bench)
        अन्तः_time = getclock_ms();

    यदि (s->सततम्_test) {
        t = 0;
    } अन्यथा यदि (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } अन्यथा यदि (0 == ret) {
        यदि (s->output_type == TCC_OUTPUT_स्मृतिः) {
#यदि_परिभाषितम् TCC_IS_NATIVE
            ret = tcc_सततम्(s, argc, argv);
#यदि_अन्तः
        } अन्यथा {
            यदि (!s->outfile)
                s->outfile = default_outputfile(s, first_file);
            यदि (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            यदि (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    समाप्तम् = 1;
    यदि (t)
        समाप्तम् = 0; /* run more tests with -dt -run */
    अन्यथा यदि (ret) {
        यदि (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } अन्यथा यदि (n < s->nb_files)
        समाप्तम् = 0; /* compile more files with -c */
    अन्यथा यदि (s->do_bench)
        tcc_print_stats(s, अन्तः_time - start_time);

    tcc_delete(s);
    यदि (!समाप्तम्)
        गच्छ redo;
    यदि (ppfp)
        tcc_fclose(ppfp);
    प्रत्यागम ret;
}
