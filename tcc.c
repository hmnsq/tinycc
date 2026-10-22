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

#அந்தர்பாவ "tcc.h"
#எனில் ONE_SOURCE
# include "libtcc.c"
#endif
#அந்தர்பாவ "tcctools.c"

நிலையான மாறிலி எழுத்து help[] =
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
#எனில் defined(TCC_TARGET_I386) || defined(TCC_TARGET_X86_64)
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

நிலையான மாறிலி எழுத்து help2[] =
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
#இல்லையெனில்
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#எனில் defined(TCC_TARGET_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#இல்லையெனில்
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

நிலையான மாறிலி எழுத்து version[] =
    "tcc version "TCC_VERSION
#ifdef TCC_GITHASH
    " "TCC_GITHASH
#endif
    " ("
#ifdef TCC_TARGET_I386
        "i386"
#அல்லதெனில் defined TCC_TARGET_X86_64
        "x86_64"
#அல்லதெனில் defined TCC_TARGET_C67
        "C67"
#அல்லதெனில் defined TCC_TARGET_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#அல்லதெனில் defined TCC_TARGET_ARM64
        "AArch64"
#அல்லதெனில் defined TCC_TARGET_RISCV64
        "riscv64"
#endif
#ifdef TCC_TARGET_PE
        " Windows"
#அல்லதெனில் defined(TCC_TARGET_MACHO)
        " Darwin"
#அல்லதெனில் TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#அல்லதெனில் TARGETOS_OpenBSD
        " OpenBSD"
#அல்லதெனில் TARGETOS_NetBSD
        " NetBSD"
#இல்லையெனில்
        " Linux"
#endif
    ")\n"
    ;

நிலையான வெறுமை print_dirs(மாறிலி எழுத்து *செய்தி, எழுத்து **paths, முழு nb_paths)
{
    முழு i;
    printf("%s:\n%s", செய்தி, nb_paths ? "" : "  -\n");
    க்கு(i = 0; i < nb_paths; i++)
        printf("  %s\n", paths[i]);
}

நிலையான வெறுமை print_தேடல்_dirs(TCCState *s)
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

நிலையான வெறுமை set_environment(TCCState *s)
{
    எழுத்து * path;

    path = getenv("C_INCLUDE_PATH");
    எனில்(path != வெற்று) {
        tcc_add_sysinclude_path(s, path);
    }
    path = getenv("CPATH");
    எனில்(path != வெற்று) {
        tcc_add_include_path(s, path);
    }
    path = getenv("LIBRARY_PATH");
    எனில்(path != வெற்று) {
        tcc_add_library_path(s, path);
    }
}

நிலையான எழுத்து *default_outputfile(TCCState *s, மாறிலி எழுத்து *first_file)
{
    எழுத்து buf[1024];
    எழுத்து *ext;
    மாறிலி எழுத்து *name = "a";

    எனில் (first_file && strcmp(first_file, "-"))
        name = tcc_basename(first_file);
    எனில் (strlen(name) + 4 >= அளவு buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#ifdef TCC_TARGET_PE
    எனில் (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    இல்லையெனில்
    எனில் (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    இல்லையெனில்
#endif
    எனில் ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    இல்லையெனில்
        strcpy(buf, "a.out");
    திரும்பு tcc_strdup(buf);
}

நிலையான unsigned getclock_ms(வெறுமை)
{
#ifdef _WIN32
    திரும்பு Get_Tick_மொத்தம்();
#இல்லையெனில்
    கட்டமைப்பு timeval tv;
    gettimeofday(&tv, வெற்று);
    திரும்பு tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    TCCState *s, *s1;
    முழு ret, opt, n = 0, t = 0, done;
    unsigned start_time = 0, end_time = 0;
    மாறிலி எழுத்து *first_file;
    முழு argc0 = argc;
    எழுத்து **argv0 = argv;
    FILE *ppfp = வெற்று;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_args(s, &argc, &argv);

    எனில் (n == 0) {
        ret = 0;
        எனில் (opt == OPT_HELP) {
            fputs(help, stdout);
            எனில் (s->verbose)
                செல் help2;
        } இல்லையெனில் எனில் (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } இல்லையெனில் எனில் (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } இல்லையெனில் எனில் (s->verbose)
            printf("%s", version);

        எனில் (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#ifdef TCC_TARGET_PE
        எனில் (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#endif
        எனில் (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            set_environment(s);
            tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
            print_தேடல்_dirs(s);
        }
        எனில் (opt) {
            எனில் (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            திரும்பு ret;
        }
        எனில் (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } இல்லையெனில் எனில் (s->output_type == TCC_OUTPUT_PREPROCESS) {
            எனில் (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                எனில் (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } இல்லையெனில் எனில் (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            எனில் (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            இல்லையெனில் எனில் (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        எனில் (s->nb_errors)
            செல் err;
        எனில் (s->do_bench)
            start_time = getclock_ms();
    }

    set_environment(s);
    எனில் (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_set_output_type(s, s->output_type);
    எனில் (ppfp)
        s->ppfp = ppfp;

    எனில் ((s->output_type == TCC_OUTPUT_MEMORY
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        எனில் (t)
            s->dflag |= 32;
        s->run_test = ++t;
        எனில் (n)
            --n;
    }

    /* compile or add each files or library */
    first_file = வெற்று;
    போது (0 == ret) {
        கட்டமைப்பு filespec *f = s->files[n];
        s->filetype = f->type;
        எனில் (f->type & AFF_TYPE_LIB) {
            ret = tcc_add_library(s, f->name);
        } இல்லையெனில் {
            எனில் (1 == s->verbose)
                printf("-> %s\n", f->name);
            எனில் (!first_file)
                first_file = f->name;
            ret = tcc_add_file(s, f->name);
        }
        எனில் (++n == s->nb_files)
            நிறுத்து;
        எனில் (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            நிறுத்து;
    }

    எனில் (s->do_bench)
        end_time = getclock_ms();

    எனில் (s->run_test) {
        t = 0;
    } இல்லையெனில் எனில் (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } இல்லையெனில் எனில் (0 == ret) {
        எனில் (s->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ret = tcc_run(s, argc, argv);
#endif
        } இல்லையெனில் {
            எனில் (!s->outfile)
                s->outfile = default_outputfile(s, first_file);
            எனில் (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            எனில் (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    done = 1;
    எனில் (t)
        done = 0; /* run more tests with -dt -run */
    இல்லையெனில் எனில் (ret) {
        எனில் (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } இல்லையெனில் எனில் (n < s->nb_files)
        done = 0; /* compile more files with -c */
    இல்லையெனில் எனில் (s->do_bench)
        tcc_print_stats(s, end_time - start_time);

    tcc_delete(s);
    எனில் (!done)
        செல் redo;
    எனில் (ppfp)
        tcc_fclose(ppfp);
    திரும்பு ret;
}
