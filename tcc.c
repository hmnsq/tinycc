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

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ONE_ಮೂಲ
# define ONE_ಮೂಲ 1
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ "tcc.h"
#ಆದರೆ ONE_ಮೂಲ
# include "libtcc.c"
#ಆದರೆ_ಅಂತ್ಯ
#ಅನ್ತರ್ಭಾವ "tcctools.c"

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ help[] =
    "Tiny C Compiler "TCC_ಆವೃತ್ತಿ" - Copyright (C) 2001-2006 Fabrice Bellard\n"
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
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    "  -g.pdb       create .pdb debug database\n"
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    "  -b           compile with built-in memory and bounds checker (implies -g)\n"
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    "  -bt[N]       link with backtrace (stack dump) support [show max N callers]\n"
#ಆದರೆ_ಅಂತ್ಯ
    "Misc. options:\n"
    "  -std=version define __STDC_VERSION__ according to version (c11/gnu11)\n"
    "  -x[c|a|b|n]  specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -Bdir        set tcc's private include/library dir\n"
    "  -M[M]D       generate make dependency file [ignore system files]\n"
    "  -M[M]        as above but no other output\n"
    "  -MF file     specify dependency file name\n"
#ಆದರೆ defined(TCC_ಗುರಿ_I386) || defined(TCC_ಗುರಿ_X86_64)
    "  -m32/64      defer to i386/x86_64 cross compiler\n"
#ಆದರೆ_ಅಂತ್ಯ
    "Tools:\n"
    "  create library  : tcc -ar [crstvx] lib [files]\n"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    "  create def file : tcc -impdef lib.dll [-v] [-o lib.def]\n"
#ಆದರೆ_ಅಂತ್ಯ
    "Discussion & bug reports:\n"
    "  https://lists.nongnu.org/mailman/listinfo/tinycc-devel\n"
    ;

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ help2[] =
    "Tiny C Compiler "TCC_ಆವೃತ್ತಿ" - More Options\n"
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
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    "  float-abi                     hard/softfp on arm\n"
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    "  no-sse                        disable floats on x86_64\n"
#ಆದರೆ_ಅಂತ್ಯ
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not search standard library paths\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < nul\n"
#ಇಲ್ಲದಿದ್ದರೆ
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#ಆದರೆ defined(TCC_ಗುರಿ_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#ಇಲ್ಲದಿದ್ದರೆ
    "  -Ipath, -dynamic-linker=path  set ELF interpreter to path\n"
#ಆದರೆ_ಅಂತ್ಯ
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -Map= -as-needed -O -z= (ignored)\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < /dev/null\n"
#ಆದರೆ_ಅಂತ್ಯ
    "See also the manual for more details.\n"
    ;

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ ಆವೃತ್ತಿ[] =
    "tcc version "TCC_ಆವೃತ್ತಿ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_GITHASH
    " "TCC_GITHASH
#ಆದರೆ_ಅಂತ್ಯ
    " ("
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
        "i386"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
        "x86_64"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_C67
        "C67"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
        "AArch64"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
        "riscv64"
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        " Windows"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_MACHO)
        " Darwin"
#ಅಥವಾಆದರೆ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#ಅಥವಾಆದರೆ TARGETOS_OpenBSD
        " OpenBSD"
#ಅಥವಾಆದರೆ TARGETOS_NetBSD
        " NetBSD"
#ಇಲ್ಲದಿದ್ದರೆ
        " Linux"
#ಆದರೆ_ಅಂತ್ಯ
    ")\n"
    ;

ಸ್ಥಿರ ಶೂನ್ಯ print_dirs(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ, ಅಕ್ಷರ **paths, ಪೂರ್ಣಾಂಕ nb_paths)
{
    ಪೂರ್ಣಾಂಕ i;
    ಬರೆ("%s:\n%s", ಸಂದೇಶ, nb_paths ? "" : "  -\n");
    ಗಾಗಿ(i = 0; i < nb_paths; i++)
        ಬರೆ("  %s\n", paths[i]);
}

ಸ್ಥಿರ ಶೂನ್ಯ print_ಹುಡುಕು_dirs(TCCState *s)
{
    ಬರೆ("install: %s\n", s->tcc_lib_ಮಾರ್ಗ);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    ಬರೆ("libtcc1:\n  %s/%s\n", s->library_paths[0], CONFIG_TCC_CROSSPREFIX TCC_LIBTCC1);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_UNIX
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    ಬರೆ("elfinterp:\n  %s\n",  s->elfint);
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_environment(TCCState *s)
{
    ಅಕ್ಷರ * ಮಾರ್ಗ;

    ಮಾರ್ಗ = getenv("C_INCLUDE_PATH");
    ಆದರೆ(ಮಾರ್ಗ != ಖಾಲಿ) {
        tcc_ಕೂಡಿಸು_sysinclude_ಮಾರ್ಗ(s, ಮಾರ್ಗ);
    }
    ಮಾರ್ಗ = getenv("CPATH");
    ಆದರೆ(ಮಾರ್ಗ != ಖಾಲಿ) {
        tcc_ಕೂಡಿಸು_include_ಮಾರ್ಗ(s, ಮಾರ್ಗ);
    }
    ಮಾರ್ಗ = getenv("LIBRARY_PATH");
    ಆದರೆ(ಮಾರ್ಗ != ಖಾಲಿ) {
        tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, ಮಾರ್ಗ);
    }
}

ಸ್ಥಿರ ಅಕ್ಷರ *default_outputfile(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೊದಲ_file)
{
    ಅಕ್ಷರ buf[1024];
    ಅಕ್ಷರ *ext;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = "a";

    ಆದರೆ (ಮೊದಲ_file && strcmp(ಮೊದಲ_file, "-"))
        name = tcc_basename(ಮೊದಲ_file);
    ಆದರೆ (ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(name) + 4 >= ಗಾತ್ರ buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    ಆದರೆ (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    ಇಲ್ಲದಿದ್ದರೆ
    ಆದರೆ (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    ಇಲ್ಲದಿದ್ದರೆ
        strcpy(buf, "a.out");
    ಹಿಂತಿರುಗಿ tcc_strdup(buf);
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ getclock_ms(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    ಹಿಂತಿರುಗಿ Get_Tick_ಎಣಿಕೆ();
#ಇಲ್ಲದಿದ್ದರೆ
    ರಚನೆ timeval tv;
    gettimeofday(&tv, ಖಾಲಿ);
    ಹಿಂತಿರುಗಿ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#ಆದರೆ_ಅಂತ್ಯ
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    TCCState *s, *s1;
    ಪೂರ್ಣಾಂಕ ret, opt, n = 0, t = 0, ಮುಗಿದ;
    ಚಿಹ್ನೆರಹಿತ ಆರಂಭ_ಸಮಯ = 0, ಕೊನೆ_ಸಮಯ = 0;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೊದಲ_file;
    ಪೂರ್ಣಾಂಕ argc0 = argc;
    ಅಕ್ಷರ **argv0 = argv;
    FILE *ppfp = ಖಾಲಿ;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_ವಾದಗಳು(s, &argc, &argv);

    ಆದರೆ (n == 0) {
        ret = 0;
        ಆದರೆ (opt == OPT_HELP) {
            fputs(help, stdout);
            ಆದರೆ (s->verbose)
                ಹೋಗು help2;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->verbose)
            ಬರೆ("%s", ಆವೃತ್ತಿ);

        ಆದರೆ (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        ಆದರೆ (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            ಗಣ_environment(s);
            tcc_ಗಣ_output_type(s, TCC_OUTPUT_ಸ್ಮರಣೆ);
            print_ಹುಡುಕು_dirs(s);
        }
        ಆದರೆ (opt) {
            ಆದರೆ (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            ಹಿಂತಿರುಗಿ ret;
        }
        ಆದರೆ (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->output_type == TCC_OUTPUT_PREPROCESS) {
            ಆದರೆ (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                ಆದರೆ (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            ಆದರೆ (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        ಆದರೆ (s->nb_errors)
            ಹೋಗು err;
        ಆದರೆ (s->do_bench)
            ಆರಂಭ_ಸಮಯ = getclock_ms();
    }

    ಗಣ_environment(s);
    ಆದರೆ (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_ಗಣ_output_type(s, s->output_type);
    ಆದರೆ (ppfp)
        s->ppfp = ppfp;

    ಆದರೆ ((s->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        ಆದರೆ (t)
            s->dflag |= 32;
        s->ಸತತ_test = ++t;
        ಆದರೆ (n)
            --n;
    }

    /* compile or add each files or library */
    ಮೊದಲ_file = ಖಾಲಿ;
    ಆಗ (0 == ret) {
        ರಚನೆ filespec *f = s->files[n];
        s->filetype = f->type;
        ಆದರೆ (f->type & AFF_TYPE_LIB) {
            ret = tcc_ಕೂಡಿಸು_library(s, f->name);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (1 == s->verbose)
                ಬರೆ("-> %s\n", f->name);
            ಆದರೆ (!ಮೊದಲ_file)
                ಮೊದಲ_file = f->name;
            ret = tcc_ಕೂಡಿಸು_file(s, f->name);
        }
        ಆದರೆ (++n == s->nb_files)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            ನಿಲ್ಲಿಸು;
    }

    ಆದರೆ (s->do_bench)
        ಕೊನೆ_ಸಮಯ = getclock_ms();

    ಆದರೆ (s->ಸತತ_test) {
        t = 0;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == ret) {
        ಆದರೆ (s->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
            ret = tcc_ಸತತ(s, argc, argv);
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (!s->outfile)
                s->outfile = default_outputfile(s, ಮೊದಲ_file);
            ಆದರೆ (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            ಆದರೆ (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    ಮುಗಿದ = 1;
    ಆದರೆ (t)
        ಮುಗಿದ = 0; /* run more tests with -dt -run */
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ret) {
        ಆದರೆ (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (n < s->nb_files)
        ಮುಗಿದ = 0; /* compile more files with -c */
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s->do_bench)
        tcc_print_stats(s, ಕೊನೆ_ಸಮಯ - ಆರಂಭ_ಸಮಯ);

    tcc_delete(s);
    ಆದರೆ (!ಮುಗಿದ)
        ಹೋಗು redo;
    ಆದರೆ (ppfp)
        tcc_fclose(ppfp);
    ಹಿಂತಿರುಗಿ ret;
}
