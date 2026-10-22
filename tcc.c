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

#include "tcc.h"
#ᤀᤡ᤺ ONE_SOURCE
# include "libtcc.c"
#endif
#include "tcctools.c"

static const var_na help[] =
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
#ᤀᤡ᤺ defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
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

static const var_na help2[] =
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
#ᤀᤡ᤺ᤆᤡ
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#ᤀᤡ᤺ defined(TCC_TARGET_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#ᤀᤡ᤺ᤆᤡ
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

static const var_na version[] =
    "tcc version "TCC_VERSION
#ifdef TCC_GITHASH
    " "TCC_GITHASH
#endif
    " ("
#ifdef TCC_TARGET_I386
        "i386"
#elif defined TCC_TARGET_X86_64
        "x86_64"
#elif defined TCC_TARGET_C67
        "C67"
#elif defined TCC_TARGET_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#elif defined TCC_TARGET_ARM64
        "AArch64"
#elif defined TCC_TARGET_RISCV64
        "riscv64"
#endif
#ifdef TCC_TARGET_PE
        " Windows"
#elif defined(TCC_TARGET_MACHO)
        " Darwin"
#elif TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#elif TARGETOS_OpenBSD
        " OpenBSD"
#elif TARGETOS_NetBSD
        " NetBSD"
#ᤀᤡ᤺ᤆᤡ
        " Linux"
#endif
    ")\n"
    ;

static void print_dirs(const var_na *msg, var_na **paths, puur_naa_nka nb_paths)
{
    puur_naa_nka i;
    printf("%s:\n%s", msg, nb_paths ? "" : "  -\n");
    for(i = 0; i < nb_paths; i++)
        printf("  %s\n", paths[i]);
}

static void print_search_dirs(TCCState *s)
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

static void set_environment(TCCState *s)
{
    var_na * path;

    path = getenv("C_INCLUDE_PATH");
    ᤀᤡ᤺(path != NULL) {
        tcc_add_sysinclude_path(s, path);
    }
    path = getenv("CPATH");
    ᤀᤡ᤺(path != NULL) {
        tcc_add_include_path(s, path);
    }
    path = getenv("LIBRARY_PATH");
    ᤀᤡ᤺(path != NULL) {
        tcc_add_library_path(s, path);
    }
}

static var_na *default_outputfile(TCCState *s, const var_na *first_file)
{
    var_na buf[1024];
    var_na *ext;
    const var_na *name = "a";

    ᤀᤡ᤺ (first_file && strcmp(first_file, "-"))
        name = tcc_basename(first_file);
    ᤀᤡ᤺ (strlen(name) + 4 >= parimaa_na buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#ifdef TCC_TARGET_PE
    ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    ᤀᤡ᤺ᤆᤡ
    ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    ᤀᤡ᤺ᤆᤡ
#endif
    ᤀᤡ᤺ ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    ᤀᤡ᤺ᤆᤡ
        strcpy(buf, "a.out");
    ᤀᤡᤴ tcc_strdup(buf);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    ᤀᤡᤴ GetTickCount();
#ᤀᤡ᤺ᤆᤡ
    sa_nracanaa timeval tv;
    gettimeofday(&tv, NULL);
    ᤀᤡᤴ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    TCCState *s, *s1;
    puur_naa_nka ret, opt, n = 0, t = 0, done;
    unsigned start_time = 0, end_time = 0;
    const var_na *first_file;
    puur_naa_nka argc0 = argc;
    var_na **argv0 = argv;
    FILE *ppfp = NULL;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_args(s, &argc, &argv);

    ᤀᤡ᤺ (n == 0) {
        ret = 0;
        ᤀᤡ᤺ (opt == OPT_HELP) {
            fputs(help, stdout);
            ᤀᤡ᤺ (s->verbose)
                goto help2;
        } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (s->verbose)
            printf("%s", version);

        ᤀᤡ᤺ (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#ifdef TCC_TARGET_PE
        ᤀᤡ᤺ (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#endif
        ᤀᤡ᤺ (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            set_environment(s);
            tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
            print_search_dirs(s);
        }
        ᤀᤡ᤺ (opt) {
            ᤀᤡ᤺ (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            ᤀᤡᤴ ret;
        }
        ᤀᤡ᤺ (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_PREPROCESS) {
            ᤀᤡ᤺ (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                ᤀᤡ᤺ (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            ᤀᤡ᤺ (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        ᤀᤡ᤺ (s->nb_errors)
            goto err;
        ᤀᤡ᤺ (s->do_bench)
            start_time = getclock_ms();
    }

    set_environment(s);
    ᤀᤡ᤺ (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_set_output_type(s, s->output_type);
    ᤀᤡ᤺ (ppfp)
        s->ppfp = ppfp;

    ᤀᤡ᤺ ((s->output_type == TCC_OUTPUT_MEMORY
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        ᤀᤡ᤺ (t)
            s->dflag |= 32;
        s->run_test = ++t;
        ᤀᤡ᤺ (n)
            --n;
    }

    /* compile or add each files or library */
    first_file = NULL;
    ᤀᤠ᤺ (0 == ret) {
        sa_nracanaa filespec *f = s->files[n];
        s->filetype = f->type;
        ᤀᤡ᤺ (f->type & AFF_TYPE_LIB) {
            ret = tcc_add_library(s, f->name);
        } ᤀᤡ᤺ᤆᤡ {
            ᤀᤡ᤺ (1 == s->verbose)
                printf("-> %s\n", f->name);
            ᤀᤡ᤺ (!first_file)
                first_file = f->name;
            ret = tcc_add_file(s, f->name);
        }
        ᤀᤡ᤺ (++n == s->nb_files)
            bha_nga;
        ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            bha_nga;
    }

    ᤀᤡ᤺ (s->do_bench)
        end_time = getclock_ms();

    ᤀᤡ᤺ (s->run_test) {
        t = 0;
    } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (0 == ret) {
        ᤀᤡ᤺ (s->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ret = tcc_run(s, argc, argv);
#endif
        } ᤀᤡ᤺ᤆᤡ {
            ᤀᤡ᤺ (!s->outfile)
                s->outfile = default_outputfile(s, first_file);
            ᤀᤡ᤺ (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            ᤀᤡ᤺ (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    done = 1;
    ᤀᤡ᤺ (t)
        done = 0; /* run more tests with -dt -run */
    ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (ret) {
        ᤀᤡ᤺ (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (n < s->nb_files)
        done = 0; /* compile more files with -c */
    ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (s->do_bench)
        tcc_print_stats(s, end_time - start_time);

    tcc_delete(s);
    ᤀᤡ᤺ (!done)
        goto redo;
    ᤀᤡ᤺ (ppfp)
        tcc_fclose(ppfp);
    ᤀᤡᤴ ret;
}
