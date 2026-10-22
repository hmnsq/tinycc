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

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ONE_ਸਰੋਤ
# define ONE_ਸਰੋਤ 1
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"
#ਜੇ ONE_ਸਰੋਤ
# include "libtcc.c"
#ਜੇ_ਅੰਤ
#ਅਨ੍ਤਰ੍ਭਾਵ "tcctools.c"

ਸਥਿਰ ਅਚਲ ਅੱਖਰ help[] =
    "Tiny C Compiler "TCC_ਸੰਸਕਰਣ" - Copyright (C) 2001-2006 Fabrice Bellard\n"
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
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    "  -g.pdb       create .pdb debug database\n"
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    "  -b           compile with built-in memory and bounds checker (implies -g)\n"
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    "  -bt[N]       link with backtrace (stack dump) support [show max N callers]\n"
#ਜੇ_ਅੰਤ
    "Misc. options:\n"
    "  -std=version define __STDC_VERSION__ according to version (c11/gnu11)\n"
    "  -x[c|a|b|n]  specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -Bdir        set tcc's private include/library dir\n"
    "  -M[M]D       generate make dependency file [ignore system files]\n"
    "  -M[M]        as above but no other output\n"
    "  -MF file     specify dependency file name\n"
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_I386) || defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
    "  -m32/64      defer to i386/x86_64 cross compiler\n"
#ਜੇ_ਅੰਤ
    "Tools:\n"
    "  create library  : tcc -ar [crstvx] lib [files]\n"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    "  create def file : tcc -impdef lib.dll [-v] [-o lib.def]\n"
#ਜੇ_ਅੰਤ
    "Discussion & bug reports:\n"
    "  https://lists.nongnu.org/mailman/listinfo/tinycc-devel\n"
    ;

ਸਥਿਰ ਅਚਲ ਅੱਖਰ help2[] =
    "Tiny C Compiler "TCC_ਸੰਸਕਰਣ" - More Options\n"
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
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    "  float-abi                     hard/softfp on arm\n"
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    "  no-sse                        disable floats on x86_64\n"
#ਜੇ_ਅੰਤ
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not search standard library paths\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < nul\n"
#ਨਹੀਂਤਾਂ
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#ਨਹੀਂਤਾਂ
    "  -Ipath, -dynamic-linker=path  set ELF interpreter to path\n"
#ਜੇ_ਅੰਤ
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -Map= -as-needed -O -z= (ignored)\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < /dev/null\n"
#ਜੇ_ਅੰਤ
    "See also the manual for more details.\n"
    ;

ਸਥਿਰ ਅਚਲ ਅੱਖਰ ਸੰਸਕਰਣ[] =
    "tcc version "TCC_ਸੰਸਕਰਣ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_GITHASH
    " "TCC_GITHASH
#ਜੇ_ਅੰਤ
    " ("
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
        "i386"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
        "x86_64"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_C67
        "C67"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
        "AArch64"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
        "riscv64"
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        " Windows"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
        " Darwin"
#ਜਾਂਜੇ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#ਜਾਂਜੇ TARGETOS_OpenBSD
        " OpenBSD"
#ਜਾਂਜੇ TARGETOS_NetBSD
        " NetBSD"
#ਨਹੀਂਤਾਂ
        " Linux"
#ਜੇ_ਅੰਤ
    ")\n"
    ;

ਸਥਿਰ ਖਾਲੀ print_dirs(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ, ਅੱਖਰ **paths, ਪੂਰਨ nb_paths)
{
    ਪੂਰਨ i;
    ਲਿਖੋ("%s:\n%s", ਸੁਨੇਹਾ, nb_paths ? "" : "  -\n");
    ਲਈ(i = 0; i < nb_paths; i++)
        ਲਿਖੋ("  %s\n", paths[i]);
}

ਸਥਿਰ ਖਾਲੀ print_ਖੋਜ_dirs(TCCState *s)
{
    ਲਿਖੋ("install: %s\n", s->tcc_lib_ਰਸਤਾ);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    ਲਿਖੋ("libtcc1:\n  %s/%s\n", s->library_paths[0], CONFIG_TCC_CROSSPREFIX TCC_LIBTCC1);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_UNIX
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    ਲਿਖੋ("elfinterp:\n  %s\n",  s->elfint);
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_environment(TCCState *s)
{
    ਅੱਖਰ * ਰਸਤਾ;

    ਰਸਤਾ = getenv("C_INCLUDE_PATH");
    ਜੇ(ਰਸਤਾ != ਨਿਰਾ) {
        tcc_ਜੋੜੋ_sysinclude_ਰਸਤਾ(s, ਰਸਤਾ);
    }
    ਰਸਤਾ = getenv("CPATH");
    ਜੇ(ਰਸਤਾ != ਨਿਰਾ) {
        tcc_ਜੋੜੋ_include_ਰਸਤਾ(s, ਰਸਤਾ);
    }
    ਰਸਤਾ = getenv("LIBRARY_PATH");
    ਜੇ(ਰਸਤਾ != ਨਿਰਾ) {
        tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, ਰਸਤਾ);
    }
}

ਸਥਿਰ ਅੱਖਰ *default_outputfile(TCCState *s, ਅਚਲ ਅੱਖਰ *ਪਹਿਲਾ_file)
{
    ਅੱਖਰ buf[1024];
    ਅੱਖਰ *ext;
    ਅਚਲ ਅੱਖਰ *name = "a";

    ਜੇ (ਪਹਿਲਾ_file && strcmp(ਪਹਿਲਾ_file, "-"))
        name = tcc_basename(ਪਹਿਲਾ_file);
    ਜੇ (ਲੜੀ_ਲੰਬਾਈ(name) + 4 >= ਆਕਾਰ buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    ਜੇ (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    ਨਹੀਂਤਾਂ
    ਜੇ (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
    ਜੇ ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    ਨਹੀਂਤਾਂ
        strcpy(buf, "a.out");
    ਵਾਪਸ tcc_strdup(buf);
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ getclock_ms(ਖਾਲੀ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਵਾਪਸ Get_Tick_ਗਿਣਤੀ();
#ਨਹੀਂਤਾਂ
    ਬਣਤਰ timeval tv;
    gettimeofday(&tv, ਨਿਰਾ);
    ਵਾਪਸ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#ਜੇ_ਅੰਤ
}

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    TCCState *s, *s1;
    ਪੂਰਨ ret, opt, n = 0, t = 0, ਪੂਰਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਸ਼ੁਰੂ_ਸਮਾਂ = 0, ਸਿਰਾ_ਸਮਾਂ = 0;
    ਅਚਲ ਅੱਖਰ *ਪਹਿਲਾ_file;
    ਪੂਰਨ argc0 = argc;
    ਅੱਖਰ **argv0 = argv;
    FILE *ppfp = ਨਿਰਾ;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_ਦਲੀਲਾਂ(s, &argc, &argv);

    ਜੇ (n == 0) {
        ret = 0;
        ਜੇ (opt == OPT_HELP) {
            fputs(help, stdout);
            ਜੇ (s->verbose)
                ਜਾਓ help2;
        } ਨਹੀਂਤਾਂ ਜੇ (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } ਨਹੀਂਤਾਂ ਜੇ (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } ਨਹੀਂਤਾਂ ਜੇ (s->verbose)
            ਲਿਖੋ("%s", ਸੰਸਕਰਣ);

        ਜੇ (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        ਜੇ (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#ਜੇ_ਅੰਤ
        ਜੇ (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            ਸੈੱਟ_environment(s);
            tcc_ਸੈੱਟ_output_type(s, TCC_OUTPUT_ਸਮ੍ਰਿਤੀ);
            print_ਖੋਜ_dirs(s);
        }
        ਜੇ (opt) {
            ਜੇ (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            ਵਾਪਸ ret;
        }
        ਜੇ (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } ਨਹੀਂਤਾਂ ਜੇ (s->output_type == TCC_OUTPUT_PREPROCESS) {
            ਜੇ (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                ਜੇ (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } ਨਹੀਂਤਾਂ ਜੇ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            ਜੇ (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            ਨਹੀਂਤਾਂ ਜੇ (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        ਜੇ (s->nb_errors)
            ਜਾਓ err;
        ਜੇ (s->do_bench)
            ਸ਼ੁਰੂ_ਸਮਾਂ = getclock_ms();
    }

    ਸੈੱਟ_environment(s);
    ਜੇ (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_ਸੈੱਟ_output_type(s, s->output_type);
    ਜੇ (ppfp)
        s->ppfp = ppfp;

    ਜੇ ((s->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        ਜੇ (t)
            s->dflag |= 32;
        s->ਲੜੀਵਾਰ_test = ++t;
        ਜੇ (n)
            --n;
    }

    /* compile or add each files or library */
    ਪਹਿਲਾ_file = ਨਿਰਾ;
    ਜਦੋਂ (0 == ret) {
        ਬਣਤਰ filespec *f = s->files[n];
        s->filetype = f->type;
        ਜੇ (f->type & AFF_TYPE_LIB) {
            ret = tcc_ਜੋੜੋ_library(s, f->name);
        } ਨਹੀਂਤਾਂ {
            ਜੇ (1 == s->verbose)
                ਲਿਖੋ("-> %s\n", f->name);
            ਜੇ (!ਪਹਿਲਾ_file)
                ਪਹਿਲਾ_file = f->name;
            ret = tcc_ਜੋੜੋ_file(s, f->name);
        }
        ਜੇ (++n == s->nb_files)
            ਰੋਕੋ;
        ਜੇ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            ਰੋਕੋ;
    }

    ਜੇ (s->do_bench)
        ਸਿਰਾ_ਸਮਾਂ = getclock_ms();

    ਜੇ (s->ਲੜੀਵਾਰ_test) {
        t = 0;
    } ਨਹੀਂਤਾਂ ਜੇ (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } ਨਹੀਂਤਾਂ ਜੇ (0 == ret) {
        ਜੇ (s->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
            ret = tcc_ਲੜੀਵਾਰ(s, argc, argv);
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ {
            ਜੇ (!s->outfile)
                s->outfile = default_outputfile(s, ਪਹਿਲਾ_file);
            ਜੇ (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            ਜੇ (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    ਪੂਰਾ = 1;
    ਜੇ (t)
        ਪੂਰਾ = 0; /* run more tests with -dt -run */
    ਨਹੀਂਤਾਂ ਜੇ (ret) {
        ਜੇ (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } ਨਹੀਂਤਾਂ ਜੇ (n < s->nb_files)
        ਪੂਰਾ = 0; /* compile more files with -c */
    ਨਹੀਂਤਾਂ ਜੇ (s->do_bench)
        tcc_print_stats(s, ਸਿਰਾ_ਸਮਾਂ - ਸ਼ੁਰੂ_ਸਮਾਂ);

    tcc_delete(s);
    ਜੇ (!ਪੂਰਾ)
        ਜਾਓ redo;
    ਜੇ (ppfp)
        tcc_fclose(ppfp);
    ਵਾਪਸ ret;
}
