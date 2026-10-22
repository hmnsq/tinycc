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

#ifndef ONE_SOURCE
# define ONE_SOURCE 1
#endif

#अन्तर्भाव "tcc.h"
#सचे ONE_SOURCE
# include "libtcc.c"
#endif
#अन्तर्भाव "tcctools.c"

स्थिर ध्रुव वर्ण help[] =
    "Tiny C Compiler "TCC_VERSION" - Copyright (C) 2001-2006 Fabrice Bellard\n"
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
#ifdef TCC_TARGET_PE
    "  -g.pdb       create .pdb debug database\n"
#endif
#ifdef CONFIG_TCC_BCHECK
    "  -b           compile with built-in memory and bounds checker (implies -g)\n"
#endif
#ifdef CONFIG_TCC_BACKTRACE
    "  -bt[N]       link with backtrace (stack dump) support [show max N callers]\n"
#endif
    "Misc. options:\n"
    "  -std=version define __STDC_VERSION__ according to version (c11/gnu11)\n"
    "  -x[c|a|b|n]  specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -Bdir        set tcc's private include/library dir\n"
    "  -M[M]D       generate make dependency file [ignore system files]\n"
    "  -M[M]        as above but no other output\n"
    "  -MF file     specify dependency file name\n"
#सचे defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
    "  -m32/64      defer to i386/x86_64 cross compiler\n"
#endif
    "Tools:\n"
    "  create library  : tcc -ar [crstvx] lib [files]\n"
#ifdef TCC_TARGET_PE
    "  create def file : tcc -impdef lib.dll [-v] [-o lib.def]\n"
#endif
    "Discussion & bug reports:\n"
    "  https://lists.nongnu.org/mailman/listinfo/tinycc-devel\n"
    ;

स्थिर ध्रुव वर्ण help2[] =
    "Tiny C Compiler "TCC_VERSION" - More Options\n"
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
#ifdef TCC_TARGET_ARM
    "  float-abi                     hard/softfp on arm\n"
#endif
#ifdef TCC_TARGET_X86_64
    "  no-sse                        disable floats on x86_64\n"
#endif
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not search standard library paths\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#ifdef TCC_TARGET_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < nul\n"
#अञ्ञथा
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#सचे defined(TCC_TARGET_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#अञ्ञथा
    "  -Ipath, -dynamic-linker=path  set ELF interpreter to path\n"
#endif
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -Map= -as-needed -O -z= (ignored)\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < /dev/null\n"
#endif
    "See also the manual for more details.\n"
    ;

स्थिर ध्रुव वर्ण version[] =
    "tcc version "TCC_VERSION
#ifdef TCC_GITHASH
    " "TCC_GITHASH
#endif
    " ("
#ifdef TCC_TARGET_I386
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
#endif
#ifdef TCC_TARGET_PE
        " Windows"
#नोचेद्यदि defined(TCC_TARGET_MACHO)
        " Darwin"
#नोचेद्यदि TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#नोचेद्यदि TARGETOS_OpenBSD
        " OpenBSD"
#नोचेद्यदि TARGETOS_NetBSD
        " NetBSD"
#अञ्ञथा
        " Linux"
#endif
    ")\n"
    ;

स्थिर शून्य print_dirs(ध्रुव वर्ण *सन्देशः, वर्ण **paths, पूर्णाङ्क nb_paths)
{
    पूर्णाङ्क i;
    printf("%s:\n%s", सन्देशः, nb_paths ? "" : "  -\n");
    अत्थाय(i = 0; i < nb_paths; i++)
        printf("  %s\n", paths[i]);
}

स्थिर शून्य print_अन्वेषणम्_dirs(TCCState *s)
{
    printf("install: %s\n", s->tcc_lib_path);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    printf("libtcc1:\n  %s/%s\n", s->library_paths[0], CONFIG_TCC_CROSSPREFIX TCC_LIBTCC1);
#ifdef TCC_TARGET_UNIX
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    printf("elfinterp:\n  %s\n",  s->elfint);
#endif
}

स्थिर शून्य set_environment(TCCState *s)
{
    वर्ण * path;

    path = getenv("C_INCLUDE_PATH");
    सचे(path != रिक्त) {
        tcc_add_sysinclude_path(s, path);
    }
    path = getenv("CPATH");
    सचे(path != रिक्त) {
        tcc_add_include_path(s, path);
    }
    path = getenv("LIBRARY_PATH");
    सचे(path != रिक्त) {
        tcc_add_library_path(s, path);
    }
}

स्थिर वर्ण *default_outputfile(TCCState *s, ध्रुव वर्ण *first_file)
{
    वर्ण buf[1024];
    वर्ण *ext;
    ध्रुव वर्ण *name = "a";

    सचे (first_file && strcmp(first_file, "-"))
        name = tcc_basename(first_file);
    सचे (strlen(name) + 4 >= परिमाण buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#ifdef TCC_TARGET_PE
    सचे (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    अञ्ञथा
    सचे (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    अञ्ञथा
#endif
    सचे ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    अञ्ञथा
        strcpy(buf, "a.out");
    पटिनिवत्त tcc_strdup(buf);
}

स्थिर unsigned getclock_ms(शून्य)
{
#ifdef _WIN32
    पटिनिवत्त Get_Tick_गणनम्();
#अञ्ञथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    पटिनिवत्त tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    TCCState *s, *s1;
    पूर्णाङ्क ret, opt, n = 0, t = 0, done;
    unsigned start_time = 0, end_time = 0;
    ध्रुव वर्ण *first_file;
    पूर्णाङ्क argc0 = argc;
    वर्ण **argv0 = argv;
    FILE *ppfp = रिक्त;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_args(s, &argc, &argv);

    सचे (n == 0) {
        ret = 0;
        सचे (opt == OPT_HELP) {
            fputs(help, stdout);
            सचे (s->verbose)
                गच्छ help2;
        } अञ्ञथा सचे (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } अञ्ञथा सचे (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } अञ्ञथा सचे (s->verbose)
            printf("%s", version);

        सचे (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#ifdef TCC_TARGET_PE
        सचे (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#endif
        सचे (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            set_environment(s);
            tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
            print_अन्वेषणम्_dirs(s);
        }
        सचे (opt) {
            सचे (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            पटिनिवत्त ret;
        }
        सचे (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } अञ्ञथा सचे (s->output_type == TCC_OUTPUT_PREPROCESS) {
            सचे (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                सचे (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } अञ्ञथा सचे (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            सचे (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            अञ्ञथा सचे (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        सचे (s->nb_errors)
            गच्छ err;
        सचे (s->do_bench)
            start_time = getclock_ms();
    }

    set_environment(s);
    सचे (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_set_output_type(s, s->output_type);
    सचे (ppfp)
        s->ppfp = ppfp;

    सचे ((s->output_type == TCC_OUTPUT_MEMORY
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        सचे (t)
            s->dflag |= 32;
        s->run_test = ++t;
        सचे (n)
            --n;
    }

    /* compile or add each files or library */
    first_file = रिक्त;
    याव (0 == ret) {
        संरचना filespec *f = s->files[n];
        s->filetype = f->type;
        सचे (f->type & AFF_TYPE_LIB) {
            ret = tcc_add_library(s, f->name);
        } अञ्ञथा {
            सचे (1 == s->verbose)
                printf("-> %s\n", f->name);
            सचे (!first_file)
                first_file = f->name;
            ret = tcc_add_file(s, f->name);
        }
        सचे (++n == s->nb_files)
            भङ्ग;
        सचे (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            भङ्ग;
    }

    सचे (s->do_bench)
        end_time = getclock_ms();

    सचे (s->run_test) {
        t = 0;
    } अञ्ञथा सचे (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } अञ्ञथा सचे (0 == ret) {
        सचे (s->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ret = tcc_run(s, argc, argv);
#endif
        } अञ्ञथा {
            सचे (!s->outfile)
                s->outfile = default_outputfile(s, first_file);
            सचे (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            सचे (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    done = 1;
    सचे (t)
        done = 0; /* run more tests with -dt -run */
    अञ्ञथा सचे (ret) {
        सचे (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } अञ्ञथा सचे (n < s->nb_files)
        done = 0; /* compile more files with -c */
    अञ्ञथा सचे (s->do_bench)
        tcc_print_stats(s, end_time - start_time);

    tcc_delete(s);
    सचे (!done)
        गच्छ redo;
    सचे (ppfp)
        tcc_fclose(ppfp);
    पटिनिवत्त ret;
}
