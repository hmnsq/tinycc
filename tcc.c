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

#నిర్వచితం_కాకపోతే ONE_ఆధారం
# define ONE_ఆధారం 1
#అయితే_ముగింపు

#అన్తర్భావ "tcc.h"
#ఒకవేళ ONE_ఆధారం
# include "libtcc.c"
#అయితే_ముగింపు
#అన్తర్భావ "tcctools.c"

స్థిర స్థిరరాశి అక్షరం help[] =
    "Tiny C Compiler "TCC_సంస్కరణ" - Copyright (C) 2001-2006 Fabrice Bellard\n"
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
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    "  -g.pdb       create .pdb debug database\n"
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    "  -b           compile with built-in memory and bounds checker (implies -g)\n"
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    "  -bt[N]       link with backtrace (stack dump) support [show max N callers]\n"
#అయితే_ముగింపు
    "Misc. options:\n"
    "  -std=version define __STDC_VERSION__ according to version (c11/gnu11)\n"
    "  -x[c|a|b|n]  specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -Bdir        set tcc's private include/library dir\n"
    "  -M[M]D       generate make dependency file [ignore system files]\n"
    "  -M[M]        as above but no other output\n"
    "  -MF file     specify dependency file name\n"
#ఒకవేళ defined(TCC_లక్ష్యం_I386) || defined(TCC_లక్ష్యం_X86_64)
    "  -m32/64      defer to i386/x86_64 cross compiler\n"
#అయితే_ముగింపు
    "Tools:\n"
    "  create library  : tcc -ar [crstvx] lib [files]\n"
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    "  create def file : tcc -impdef lib.dll [-v] [-o lib.def]\n"
#అయితే_ముగింపు
    "Discussion & bug reports:\n"
    "  https://lists.nongnu.org/mailman/listinfo/tinycc-devel\n"
    ;

స్థిర స్థిరరాశి అక్షరం help2[] =
    "Tiny C Compiler "TCC_సంస్కరణ" - More Options\n"
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
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    "  float-abi                     hard/softfp on arm\n"
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    "  no-sse                        disable floats on x86_64\n"
#అయితే_ముగింపు
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not search standard library paths\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < nul\n"
#లేకపోతే
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#ఒకవేళ defined(TCC_లక్ష్యం_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#లేకపోతే
    "  -Ipath, -dynamic-linker=path  set ELF interpreter to path\n"
#అయితే_ముగింపు
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -Map= -as-needed -O -z= (ignored)\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < /dev/null\n"
#అయితే_ముగింపు
    "See also the manual for more details.\n"
    ;

స్థిర స్థిరరాశి అక్షరం సంస్కరణ[] =
    "tcc version "TCC_సంస్కరణ
#నిర్వచితమైతే TCC_GITHASH
    " "TCC_GITHASH
#అయితే_ముగింపు
    " ("
#నిర్వచితమైతే TCC_లక్ష్యం_I386
        "i386"
#లేదావేళ defined TCC_లక్ష్యం_X86_64
        "x86_64"
#లేదావేళ defined TCC_లక్ష్యం_C67
        "C67"
#లేదావేళ defined TCC_లక్ష్యం_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#లేదావేళ defined TCC_లక్ష్యం_ARM64
        "AArch64"
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
        "riscv64"
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        " Windows"
#లేదావేళ defined(TCC_లక్ష్యం_MACHO)
        " Darwin"
#లేదావేళ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#లేదావేళ TARGETOS_OpenBSD
        " OpenBSD"
#లేదావేళ TARGETOS_NetBSD
        " NetBSD"
#లేకపోతే
        " Linux"
#అయితే_ముగింపు
    ")\n"
    ;

స్థిర శూన్య print_dirs(స్థిరరాశి అక్షరం *సందేశం, అక్షరం **paths, పూర్ణాంకం nb_paths)
{
    పూర్ణాంకం i;
    రాయి("%s:\n%s", సందేశం, nb_paths ? "" : "  -\n");
    కొరకు(i = 0; i < nb_paths; i++)
        రాయి("  %s\n", paths[i]);
}

స్థిర శూన్య print_శోధన_dirs(TCCState *s)
{
    రాయి("install: %s\n", s->tcc_lib_మార్గం);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    రాయి("libtcc1:\n  %s/%s\n", s->library_paths[0], CONFIG_TCC_CROSSPREFIX TCC_LIBTCC1);
#నిర్వచితమైతే TCC_లక్ష్యం_UNIX
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    రాయి("elfinterp:\n  %s\n",  s->elfint);
#అయితే_ముగింపు
}

స్థిర శూన్య సమితి_environment(TCCState *s)
{
    అక్షరం * మార్గం;

    మార్గం = getenv("C_INCLUDE_PATH");
    ఒకవేళ(మార్గం != ఖాళీ) {
        tcc_కూడు_sysinclude_మార్గం(s, మార్గం);
    }
    మార్గం = getenv("CPATH");
    ఒకవేళ(మార్గం != ఖాళీ) {
        tcc_కూడు_include_మార్గం(s, మార్గం);
    }
    మార్గం = getenv("LIBRARY_PATH");
    ఒకవేళ(మార్గం != ఖాళీ) {
        tcc_కూడు_library_మార్గం(s, మార్గం);
    }
}

స్థిర అక్షరం *default_outputfile(TCCState *s, స్థిరరాశి అక్షరం *మొదటి_file)
{
    అక్షరం buf[1024];
    అక్షరం *ext;
    స్థిరరాశి అక్షరం *name = "a";

    ఒకవేళ (మొదటి_file && strcmp(మొదటి_file, "-"))
        name = tcc_basename(మొదటి_file);
    ఒకవేళ (అక్షరశ్రేణి_పొడవు(name) + 4 >= పరిమాణం buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    ఒకవేళ (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    లేకపోతే
    ఒకవేళ (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    లేకపోతే
#అయితే_ముగింపు
    ఒకవేళ ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    లేకపోతే
        strcpy(buf, "a.out");
    తిరిగి tcc_strdup(buf);
}

స్థిర గుర్తులేని getclock_ms(శూన్య)
{
#నిర్వచితమైతే _WIN32
    తిరిగి Get_Tick_లెక్క();
#లేకపోతే
    నిర్మాణం timeval tv;
    gettimeofday(&tv, ఖాళీ);
    తిరిగి tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#అయితే_ముగింపు
}

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    TCCState *s, *s1;
    పూర్ణాంకం ret, opt, n = 0, t = 0, పూర్తి;
    గుర్తులేని ప్రారంభం_సమయం = 0, చివర_సమయం = 0;
    స్థిరరాశి అక్షరం *మొదటి_file;
    పూర్ణాంకం argc0 = argc;
    అక్షరం **argv0 = argv;
    FILE *ppfp = ఖాళీ;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_వాదనలు(s, &argc, &argv);

    ఒకవేళ (n == 0) {
        ret = 0;
        ఒకవేళ (opt == OPT_HELP) {
            fputs(help, stdout);
            ఒకవేళ (s->verbose)
                వెళ్ళు help2;
        } లేకపోతే ఒకవేళ (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } లేకపోతే ఒకవేళ (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } లేకపోతే ఒకవేళ (s->verbose)
            రాయి("%s", సంస్కరణ);

        ఒకవేళ (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        ఒకవేళ (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#అయితే_ముగింపు
        ఒకవేళ (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            సమితి_environment(s);
            tcc_సమితి_output_type(s, TCC_OUTPUT_జ్ఞాపకం);
            print_శోధన_dirs(s);
        }
        ఒకవేళ (opt) {
            ఒకవేళ (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            తిరిగి ret;
        }
        ఒకవేళ (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } లేకపోతే ఒకవేళ (s->output_type == TCC_OUTPUT_PREPROCESS) {
            ఒకవేళ (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                ఒకవేళ (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } లేకపోతే ఒకవేళ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            ఒకవేళ (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            లేకపోతే ఒకవేళ (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        ఒకవేళ (s->nb_errors)
            వెళ్ళు err;
        ఒకవేళ (s->do_bench)
            ప్రారంభం_సమయం = getclock_ms();
    }

    సమితి_environment(s);
    ఒకవేళ (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_సమితి_output_type(s, s->output_type);
    ఒకవేళ (ppfp)
        s->ppfp = ppfp;

    ఒకవేళ ((s->output_type == TCC_OUTPUT_జ్ఞాపకం
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        ఒకవేళ (t)
            s->dflag |= 32;
        s->నిరంతరం_test = ++t;
        ఒకవేళ (n)
            --n;
    }

    /* compile or add each files or library */
    మొదటి_file = ఖాళీ;
    అయితే (0 == ret) {
        నిర్మాణం filespec *f = s->files[n];
        s->filetype = f->type;
        ఒకవేళ (f->type & AFF_TYPE_LIB) {
            ret = tcc_కూడు_library(s, f->name);
        } లేకపోతే {
            ఒకవేళ (1 == s->verbose)
                రాయి("-> %s\n", f->name);
            ఒకవేళ (!మొదటి_file)
                మొదటి_file = f->name;
            ret = tcc_కూడు_file(s, f->name);
        }
        ఒకవేళ (++n == s->nb_files)
            ఆపు;
        ఒకవేళ (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            ఆపు;
    }

    ఒకవేళ (s->do_bench)
        చివర_సమయం = getclock_ms();

    ఒకవేళ (s->నిరంతరం_test) {
        t = 0;
    } లేకపోతే ఒకవేళ (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } లేకపోతే ఒకవేళ (0 == ret) {
        ఒకవేళ (s->output_type == TCC_OUTPUT_జ్ఞాపకం) {
#నిర్వచితమైతే TCC_IS_NATIVE
            ret = tcc_నిరంతరం(s, argc, argv);
#అయితే_ముగింపు
        } లేకపోతే {
            ఒకవేళ (!s->outfile)
                s->outfile = default_outputfile(s, మొదటి_file);
            ఒకవేళ (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            ఒకవేళ (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    పూర్తి = 1;
    ఒకవేళ (t)
        పూర్తి = 0; /* run more tests with -dt -run */
    లేకపోతే ఒకవేళ (ret) {
        ఒకవేళ (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } లేకపోతే ఒకవేళ (n < s->nb_files)
        పూర్తి = 0; /* compile more files with -c */
    లేకపోతే ఒకవేళ (s->do_bench)
        tcc_print_stats(s, చివర_సమయం - ప్రారంభం_సమయం);

    tcc_delete(s);
    ఒకవేళ (!పూర్తి)
        వెళ్ళు redo;
    ఒకవేళ (ppfp)
        tcc_fclose(ppfp);
    తిరిగి ret;
}
