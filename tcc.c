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

#اگر_غیر_تعریف_شدہ ONE_ماخذ
# define ONE_ماخذ 1
#اگر_ختم

#شامل "tcc.h"
#اگر ONE_ماخذ
# include "libtcc.c"
#اگر_ختم
#شامل "tcctools.c"

ساکن ثابت حرف help[] =
    "Tiny C Compiler "TCC_نسخہ" - Copyright (C) 2001-2006 Fabrice Bellard\n"
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
#اگر_تعریف_شدہ TCC_ہدف_PE
    "  -g.pdb       create .pdb debug database\n"
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    "  -b           compile with built-in memory and bounds checker (implies -g)\n"
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    "  -bt[N]       link with backtrace (stack dump) support [show max N callers]\n"
#اگر_ختم
    "Misc. options:\n"
    "  -std=version define __STDC_VERSION__ according to version (c11/gnu11)\n"
    "  -x[c|a|b|n]  specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -Bdir        set tcc's private include/library dir\n"
    "  -M[M]D       generate make dependency file [ignore system files]\n"
    "  -M[M]        as above but no other output\n"
    "  -MF file     specify dependency file name\n"
#اگر defined(TCC_ہدف_I386) || defined(TCC_ہدف_X86_64)
    "  -m32/64      defer to i386/x86_64 cross compiler\n"
#اگر_ختم
    "Tools:\n"
    "  create library  : tcc -ar [crstvx] lib [files]\n"
#اگر_تعریف_شدہ TCC_ہدف_PE
    "  create def file : tcc -impdef lib.dll [-v] [-o lib.def]\n"
#اگر_ختم
    "Discussion & bug reports:\n"
    "  https://lists.nongnu.org/mailman/listinfo/tinycc-devel\n"
    ;

ساکن ثابت حرف help2[] =
    "Tiny C Compiler "TCC_نسخہ" - More Options\n"
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
#اگر_تعریف_شدہ TCC_ہدف_ARM
    "  float-abi                     hard/softfp on arm\n"
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    "  no-sse                        disable floats on x86_64\n"
#اگر_ختم
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not search standard library paths\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#اگر_تعریف_شدہ TCC_ہدف_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < nul\n"
#ورنہ
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
#اگر defined(TCC_ہدف_MACHO)
    "  -install_name=                set DT_SONAME elf tag (soname macOS alias)\n"
#ورنہ
    "  -Ipath, -dynamic-linker=path  set ELF interpreter to path\n"
#اگر_ختم
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -Map= -as-needed -O -z= (ignored)\n"
    "Predefined macros:\n"
    "  tcc -E -dM - < /dev/null\n"
#اگر_ختم
    "See also the manual for more details.\n"
    ;

ساکن ثابت حرف نسخہ[] =
    "tcc version "TCC_نسخہ
#اگر_تعریف_شدہ TCC_GITHASH
    " "TCC_GITHASH
#اگر_ختم
    " ("
#اگر_تعریف_شدہ TCC_ہدف_I386
        "i386"
#وگرنہ_اگر defined TCC_ہدف_X86_64
        "x86_64"
#وگرنہ_اگر defined TCC_ہدف_C67
        "C67"
#وگرنہ_اگر defined TCC_ہدف_ARM
        "ARM"
# ifdef TCC_ARM_EABI
        " eabi"
#  ifdef TCC_ARM_HARDFLOAT
        "hf"
#  endif
# endif
#وگرنہ_اگر defined TCC_ہدف_ARM64
        "AArch64"
#وگرنہ_اگر defined TCC_ہدف_RISCV64
        "riscv64"
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_PE
        " Windows"
#وگرنہ_اگر defined(TCC_ہدف_MACHO)
        " Darwin"
#وگرنہ_اگر TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
        " FreeBSD"
#وگرنہ_اگر TARGETOS_OpenBSD
        " OpenBSD"
#وگرنہ_اگر TARGETOS_NetBSD
        " NetBSD"
#ورنہ
        " Linux"
#اگر_ختم
    ")\n"
    ;

ساکن خالی print_dirs(ثابت حرف *پیغام, حرف **paths, صحیح nb_paths)
{
    صحیح i;
    لکھو("%s:\n%s", پیغام, nb_paths ? "" : "  -\n");
    برائے(i = 0; i < nb_paths; i++)
        لکھو("  %s\n", paths[i]);
}

ساکن خالی print_تلاش_dirs(TCCState *s)
{
    لکھو("install: %s\n", s->tcc_lib_راستہ);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    لکھو("libtcc1:\n  %s/%s\n", s->library_paths[0], CONFIG_TCC_CROSSPREFIX TCC_LIBTCC1);
#اگر_تعریف_شدہ TCC_ہدف_UNIX
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    لکھو("elfinterp:\n  %s\n",  s->elfint);
#اگر_ختم
}

ساکن خالی سیٹ_environment(TCCState *s)
{
    حرف * راستہ;

    راستہ = getenv("C_INCLUDE_PATH");
    اگر(راستہ != تہی) {
        tcc_جوڑو_sysinclude_راستہ(s, راستہ);
    }
    راستہ = getenv("CPATH");
    اگر(راستہ != تہی) {
        tcc_جوڑو_include_راستہ(s, راستہ);
    }
    راستہ = getenv("LIBRARY_PATH");
    اگر(راستہ != تہی) {
        tcc_جوڑو_library_راستہ(s, راستہ);
    }
}

ساکن حرف *default_outputfile(TCCState *s, ثابت حرف *پہلا_file)
{
    حرف buf[1024];
    حرف *ext;
    ثابت حرف *name = "a";

    اگر (پہلا_file && strcmp(پہلا_file, "-"))
        name = tcc_basename(پہلا_file);
    اگر (لڑی_لمبائی(name) + 4 >= حجم buf)
        name = "a";
    strcpy(buf, name);
    ext = tcc_fileextension(buf);
#اگر_تعریف_شدہ TCC_ہدف_PE
    اگر (s->output_type == TCC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    ورنہ
    اگر (s->output_type == TCC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    ورنہ
#اگر_ختم
    اگر ((s->just_deps || s->output_type == TCC_OUTPUT_OBJ) && !s->option_r && *ext)
        strcpy(ext, ".o");
    ورنہ
        strcpy(buf, "a.out");
    واپس tcc_strdup(buf);
}

ساکن غیرعلامتی getclock_ms(خالی)
{
#اگر_تعریف_شدہ _WIN32
    واپس Get_Tick_گنتی();
#ورنہ
    ساخت timeval tv;
    gettimeofday(&tv, تہی);
    واپس tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#اگر_ختم
}

صحیح مین(صحیح argc, حرف **argv)
{
    TCCState *s, *s1;
    صحیح ret, opt, n = 0, t = 0, مکمل;
    غیرعلامتی آغاز_وقت = 0, انتہا_وقت = 0;
    ثابت حرف *پہلا_file;
    صحیح argc0 = argc;
    حرف **argv0 = argv;
    FILE *ppfp = تہی;

redo:
    argc = argc0, argv = argv0;
    s = s1 = tcc_new();
    opt = tcc_parse_دلائل(s, &argc, &argv);

    اگر (n == 0) {
        ret = 0;
        اگر (opt == OPT_HELP) {
            fputs(help, stdout);
            اگر (s->verbose)
                جاؤ help2;
        } ورنہ اگر (opt == OPT_HELP2) {
            help2: fputs(help2, stdout);
        } ورنہ اگر (opt == OPT_M32 || opt == OPT_M64) {
            ret = tcc_tool_cross(argv, opt);
        } ورنہ اگر (s->verbose)
            لکھو("%s", نسخہ);

        اگر (opt == OPT_AR)
            ret = tcc_tool_ar(argc, argv);
#اگر_تعریف_شدہ TCC_ہدف_PE
        اگر (opt == OPT_IMPDEF)
            ret = tcc_tool_impdef(argc, argv);
#اگر_ختم
        اگر (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            سیٹ_environment(s);
            tcc_سیٹ_output_type(s, TCC_OUTPUT_حافظہ);
            print_تلاش_dirs(s);
        }
        اگر (opt) {
            اگر (opt < 0) err:
                ret = 1;
            tcc_delete(s);
            واپس ret;
        }
        اگر (s->nb_files == 0) {
            tcc_error_noabort("no input files");
        } ورنہ اگر (s->output_type == TCC_OUTPUT_PREPROCESS) {
            اگر (s->outfile && 0!=strcmp("-",s->outfile)) {
                ppfp = tcc_fopen(s->outfile, "wb");
                اگر (!ppfp)
                    tcc_error_noabort("could not write '%s'", s->outfile);
            }
        } ورنہ اگر (s->output_type == TCC_OUTPUT_OBJ && !s->option_r) {
            اگر (s->nb_libraries)
                tcc_error_noabort("cannot specify libraries with -c");
            ورنہ اگر (s->nb_files > 1 && s->outfile)
                tcc_error_noabort("cannot specify output file with -c many files");
        }
        اگر (s->nb_errors)
            جاؤ err;
        اگر (s->do_bench)
            آغاز_وقت = getclock_ms();
    }

    سیٹ_environment(s);
    اگر (s->output_type == 0)
        s->output_type = TCC_OUTPUT_EXE;
    ret = tcc_سیٹ_output_type(s, s->output_type);
    اگر (ppfp)
        s->ppfp = ppfp;

    اگر ((s->output_type == TCC_OUTPUT_حافظہ
      || s->output_type == TCC_OUTPUT_PREPROCESS)
        && (s->dflag & 16)) { /* -dt option */
        اگر (t)
            s->dflag |= 32;
        s->تسلسل_test = ++t;
        اگر (n)
            --n;
    }

    /* compile or add each files or library */
    پہلا_file = تہی;
    جب (0 == ret) {
        ساخت filespec *f = s->files[n];
        s->filetype = f->type;
        اگر (f->type & AFF_TYPE_LIB) {
            ret = tcc_جوڑو_library(s, f->name);
        } ورنہ {
            اگر (1 == s->verbose)
                لکھو("-> %s\n", f->name);
            اگر (!پہلا_file)
                پہلا_file = f->name;
            ret = tcc_جوڑو_file(s, f->name);
        }
        اگر (++n == s->nb_files)
            توڑو;
        اگر (s->output_type == TCC_OUTPUT_OBJ && !s->option_r)
            توڑو;
    }

    اگر (s->do_bench)
        انتہا_وقت = getclock_ms();

    اگر (s->تسلسل_test) {
        t = 0;
    } ورنہ اگر (s->output_type == TCC_OUTPUT_PREPROCESS) {
        ;
    } ورنہ اگر (0 == ret) {
        اگر (s->output_type == TCC_OUTPUT_حافظہ) {
#اگر_تعریف_شدہ TCC_IS_NATIVE
            ret = tcc_تسلسل(s, argc, argv);
#اگر_ختم
        } ورنہ {
            اگر (!s->outfile)
                s->outfile = default_outputfile(s, پہلا_file);
            اگر (!s->just_deps)
                ret = tcc_output_file(s, s->outfile);
            اگر (!ret && s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    مکمل = 1;
    اگر (t)
        مکمل = 0; /* run more tests with -dt -run */
    ورنہ اگر (ret) {
        اگر (s->nb_errors)
            ret = 1;
        /* else keep the original exit code from tcc_run() */
    } ورنہ اگر (n < s->nb_files)
        مکمل = 0; /* compile more files with -c */
    ورنہ اگر (s->do_bench)
        tcc_print_stats(s, انتہا_وقت - آغاز_وقت);

    tcc_delete(s);
    اگر (!مکمل)
        جاؤ redo;
    اگر (ppfp)
        tcc_fclose(ppfp);
    واپس ret;
}
