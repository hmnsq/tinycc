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

#నిర్వచితం_కాకపోతే _TCC_H
#నిర్వచించు _TCC_H

#నిర్వచించు GNU_ఆధారం
#నిర్వచించు DARWIN_C_ఆధారం
#అన్తర్భావ "config.h"

#అన్తర్భావ <stdarg.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#నిర్వచితమైతే __TINYC__
# undef __attribute__
#అయితే_ముగింపు
#అన్తర్భావ <string.h>
#అన్తర్భావ <errno.h>
#అన్తర్భావ <math.h>
#అన్తర్భావ <fcntl.h>
#అన్తర్భావ <setjmp.h>
#అన్తర్భావ <time.h>

#నిర్వచితం_కాకపోతే _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
బాహ్య దశాంశం strtof (స్థిరరాశి అక్షరం *__nptr, అక్షరం **__endptr);
బాహ్య దీర్ఘ ద్విగుణ strtold (స్థిరరాశి అక్షరం *__nptr, అక్షరం **__endptr);
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN32
# define WIN32_LEAN_AND_సగటు 1
# ifndef _WIN32_WINNT
#  define _WIN32_WINNT 0x502 /* AddVectoredExceptionHandler */
# endif
# include <windows.h>
# include <io.h> /* open, close etc. */
# include <direct.h> /* getcwd */
# include <malloc.h> /* alloca */
# ifndef _MSC_VER
#  include <stdint.h>
# endif
# define అంతఃవరుస __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (దీర్ఘ ద్విగుణ)strtod
#  define strtof (దశాంశం)strtod
#  define strtoll _strtoi64
#  define strtoull _strtoui64
# endif
  /* some compilers don't know ldexpl and windows doesn't have long doubles anyway */
# undef ldexpl
# define ldexpl ldexp
# ifdef LIBTCC_AS_DLL
#  define LIBTCCAPI __declspec(dllexport)
#  define PUB_FUNC LIBTCCAPI
# endif
# ifdef _MSC_VER
#  pragma warning (disable : 4244)  // conversion from 'uint64_t' to 'int', possible loss of data
#  pragma warning (disable : 4267)  // conversion from 'size_t' to 'int', possible loss of data
#  pragma warning (disable : 4996)  // The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name
#  pragma warning (disable : 4018)  // signed/unsigned mismatch
#  pragma warning (disable : 4146)  // unary minus operator applied to unsigned type, result still unsigned
#  define ssize_t intptr_t
#  ifdef _X86_
#   define __i386__ 1
#  endif
#  ifdef _AMD64_
#   define __x86_64__ 1
#  endif
# endif
# ఒకవేళ defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే O_ద్విమాన_2
# define O_ద్విమాన_2 0
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే offsetof
#నిర్వచితమైతే __clang__ // clang -fsanitize compains about: NULL+value
#నిర్వచించు offsetof(type, క్షేత్రం) __builtin_offsetof(type, క్షేత్రం)
#లేకపోతే
#నిర్వచించు offsetof(type, క్షేత్రం) ((కొలత_t) &((type *)0)->క్షేత్రం)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే countof
#నిర్వచించు countof(tab) (పరిమాణం(tab) / పరిమాణం((tab)[0]))
#అయితే_ముగింపు

#నిర్వచితమైతే _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#లేకపోతే
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (రాయి, (x), (y))))
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#లేకపోతే
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#అయితే_ముగింపు

/* -------------------------------------------- */

/* parser debug */
/* #define PARSE_DEBUG */
/* preprocessor debug */
/* #define PP_DEBUG */
/* include file debug */
/* #define INC_DEBUG */
/* memory leak debug (only for single threaded usage) */
/* #define MEM_DEBUG 1,2,3 */
/* assembler debug */
/* #define ASM_DEBUG */

/* target selection */
/* #define TCC_TARGET_I386   *//* i386 code generator */
/* #define TCC_TARGET_X86_64 *//* x86-64 code generator */
/* #define TCC_TARGET_ARM    *//* ARMv4 code generator */
/* #define TCC_TARGET_ARM64  *//* ARMv8 code generator */
/* #define TCC_TARGET_C67    *//* TMS320C67xx code generator */
/* #define TCC_TARGET_RISCV64 *//* risc-v code generator */

/* default target is I386 */
#ఒకవేళ !defined(TCC_లక్ష్యం_I386) && !defined(TCC_లక్ష్యం_ARM) && \
    !defined(TCC_లక్ష్యం_ARM64) && !defined(TCC_లక్ష్యం_C67) && \
    !defined(TCC_లక్ష్యం_X86_64) && !defined(TCC_లక్ష్యం_RISCV64)
# ఒకవేళ defined __x86_64__
#  define TCC_లక్ష్యం_X86_64
# elif defined __arm__
#  define TCC_లక్ష్యం_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_లక్ష్యం_ARM64
# elif defined __riscv
#  define TCC_లక్ష్యం_RISCV64
# లేకపోతే
#  define TCC_లక్ష్యం_I386
# endif
# ifdef _WIN32
#  define TCC_లక్ష్యం_PE 1
# endif
# ifdef __APPLE__
#  define TCC_లక్ష్యం_MACHO 1
# endif
#అయితే_ముగింపు

/* only native compiler supports -run */
#ఒకవేళ defined _WIN32 == defined TCC_లక్ష్యం_PE \
    && defined __APPLE__ == defined TCC_లక్ష్యం_MACHO
# ఒకవేళ defined __i386__ && defined TCC_లక్ష్యం_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_లక్ష్యం_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_లక్ష్యం_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_లక్ష్యం_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_లక్ష్యం_RISCV64
#  define TCC_IS_NATIVE
# endif
#అయితే_ముగింపు

#ఒకవేళ defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#లేకపోతే
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#అయితే_ముగింపు

#ఒకవేళ defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#లేకపోతే
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#అయితే_ముగింపు

#ఒకవేళ defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#లేకపోతే
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#అయితే_ముగింపు

#ఒకవేళ defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#లేదావేళ !(defined TCC_లక్ష్యం_PE || defined TCC_లక్ష్యం_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#అయితే_ముగింపు

#ఒకవేళ defined TCC_లక్ష్యం_PE || defined TCC_లక్ష్యం_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#లేకపోతే
# define TCC_లక్ష్యం_UNIX 1
#అయితే_ముగింపు

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#ఒకవేళ defined TCC_లక్ష్యం_PE \
    || (defined TCC_లక్ష్యం_MACHO && defined TCC_లక్ష్యం_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#అయితే_ముగింపు

#నిర్వచితమైతే CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#అయితే_ముగింపు

/* support using libtcc from threads */
#నిర్వచితం_కాకపోతే CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#అయితే_ముగింపు

/* ------------ path configuration ------------ */

#నిర్వచితం_కాకపోతే CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#అయితే_ముగింపు

#ఒకవేళ !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#అయితే_ముగింపు

#నిర్వచితమైతే CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#లేకపోతే
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#అయితే_ముగింపు

/* path to find crt1.o, crti.o and crtn.o */
#నిర్వచితం_కాకపోతే CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#అయితే_ముగింపు

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#నిర్వచితం_కాకపోతే CONFIG_TCC_SYSINCLUDEPATHS
# ఒకవేళ defined TCC_లక్ష్యం_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# లేకపోతే
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#అయితే_ముగింపు

/* library search paths */
#నిర్వచితం_కాకపోతే CONFIG_TCC_LIBPATHS
# ఒకవేళ defined TCC_లక్ష్యం_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# లేకపోతే
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#అయితే_ముగింపు

/* name of ELF interpreter */
#నిర్వచితం_కాకపోతే CONFIG_TCC_ELFINTERP
# ఒకవేళ defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_లక్ష్యం_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_లక్ష్యం_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_లక్ష్యం_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_లక్ష్యం_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_లక్ష్యం_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# లేకపోతే
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#అయితే_ముగింపు

/* (target specific) libtcc1.a */
#నిర్వచితం_కాకపోతే TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#అయితే_ముగింపు

/* <cross-prefix-to->libtcc1.a */
#నిర్వచితం_కాకపోతే CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#అయితే_ముగింపు

/* -------------------------------------------- */

#అన్తర్భావ "libtcc.h"
#అన్తర్భావ "elf.h"
#అన్తర్భావ "stab.h"
#అన్తర్భావ "dwarf.h"

/* -------------------------------------------- */

#నిర్వచితం_కాకపోతే PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ONE_ఆధారం
# define ONE_ఆధారం 0
#అయితే_ముగింపు

#ఒకవేళ ONE_ఆధారం
#నిర్వచించు ST_INLN స్థిర అంతఃవరుస
#నిర్వచించు ST_FUNC స్థిర
#నిర్వచించు ST_దత్తాంశం స్థిర
#లేకపోతే
#నిర్వచించు ST_INLN
#నిర్వచించు ST_FUNC
#నిర్వచించు ST_దత్తాంశం బాహ్య
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_PROFILE /* profile all functions */
# define స్థిర
# define అంతఃవరుస
#అయితే_ముగింపు

/* -------------------------------------------- */
/* include the target specific definitions */

#నిర్వచించు లక్ష్యం_DEFS_ONLY
#నిర్వచితమైతే TCC_లక్ష్యం_I386
# include "i386-gen.c"
# include "i386-link.c"
#లేదావేళ defined TCC_లక్ష్యం_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#లేదావేళ defined TCC_లక్ష్యం_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#లేదావేళ defined TCC_లక్ష్యం_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#లేదావేళ defined TCC_లక్ష్యం_C67
# define TCC_లక్ష్యం_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#లేదావేళ defined(TCC_లక్ష్యం_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#లేకపోతే
#దోషం unknown లక్ష్యం
#అయితే_ముగింపు
#నిర్వచనం_రద్దు లక్ష్యం_DEFS_ONLY

/* -------------------------------------------- */

#ఒకవేళ PTR_కొలత == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#లేకపోతే
# define ELFCLASSW ELFCLASS32
# define ElfW(type) Elf##32##_##type
# define ELFW(type) ELF##32##_##type
# define ElfW_Rel ElfW(Rel)
# define SHT_RELX SHT_REL
# define REL_SECTION_FMT ".rel%s"
#అయితే_ముగింపు
/* target address type */
#నిర్వచించు addr_t ElfW(Addr)
#నిర్వచించు ElfSym ElfW(Sym)

#ఒకవేళ PTR_కొలత == 8 && !defined TCC_లక్ష్యం_PE
# define LONG_కొలత 8
#లేకపోతే
# define LONG_కొలత 4
#అయితే_ముగింపు

/* -------------------------------------------- */

#నిర్వచించు INCLUDE_దొంతర_కొలత  32
#నిర్వచించు IFDEF_దొంతర_కొలత    64
#నిర్వచించు VSTACK_కొలత         512
#నిర్వచించు STRING_MAX_కొలత     1024
#నిర్వచించు TOKSTR_MAX_కొలత     256
#నిర్వచించు PACK_దొంతర_కొలత     8

#నిర్వచించు TOK_HASH_కొలత       16384 /* must be a power of two */
#నిర్వచించు TOK_ALLOC_INCR      512  /* must be a power of two */
#నిర్వచించు TOK_MAX_కొలత        4 /* token max size in int unit when stored in string */

/* token symbol management */
రకనిర్వచనం నిర్మాణం TokenSym {
    నిర్మాణం TokenSym *hash_తదుపరి;
    నిర్మాణం Sym *sym_define; /* direct pointer to define */
    నిర్మాణం Sym *sym_label; /* direct pointer to label */
    నిర్మాణం Sym *sym_struct; /* direct pointer to structure */
    నిర్మాణం Sym *sym_identifier; /* direct pointer to identifier */
    పూర్ణాంకం tok; /* token number */
    పూర్ణాంకం len;
    అక్షరం str[1];
} TokenSym;

#నిర్వచితమైతే TCC_లక్ష్యం_PE
రకనిర్వచనం గుర్తులేని పొట్టి nwchar_t;
#లేకపోతే
రకనిర్వచనం పూర్ణాంకం nwchar_t;
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం CString {
    పూర్ణాంకం కొలత; /* size in bytes */
    పూర్ణాంకం కొలత_allocated;
    అక్షరం *దత్తాంశం; /* nwchar_t* in cases */
} CString;

/* type definition */
రకనిర్వచనం నిర్మాణం CType {
    పూర్ణాంకం t;
    నిర్మాణం Sym *ref;
} CType;

/* long double words on host(!) platform */
#నిర్వచించు LDOUBLE_పదాలు ((పరిమాణం(దీర్ఘ ద్విగుణ)+3)/4)

/* constant value */
రకనిర్వచనం సంఘం CValue {
    దీర్ఘ ద్విగుణ ld;
    ద్విగుణ d;
    దశాంశం f;
    uint64_t i;
    నిర్మాణం {
        అక్షరం *దత్తాంశం;
        పూర్ణాంకం కొలత;
    } str;
    పూర్ణాంకం tab[LDOUBLE_పదాలు];
} CValue;

/* value on stack */
రకనిర్వచనం నిర్మాణం SValue {
    CType type;      /* type */
    గుర్తులేని పొట్టి r;      /* register + flags */
    గుర్తులేని పొట్టి r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    సంఘం {
      నిర్మాణం { పూర్ణాంకం jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    సంఘం {
      నిర్మాణం { గుర్తులేని పొట్టి cmp_op, cmp_r; }; /* VT_CMP operation */
      నిర్మాణం Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
నిర్మాణం SymAttr {
    గుర్తులేని పొట్టి
    aligned     : 5, /* alignment as log2+1 (0 == unspecified) */
    packed      : 1,
    weak        : 1,
    visibility  : 2,
    dllexport   : 1,
    nodecorate  : 1,
    dllimport   : 1,
    addrtaken   : 1,
    nodebug     : 1,
    xxxx        : 2; /* not used */
};

/* function attributes or temporary attributes for parsing */
నిర్మాణం FuncAttr {
    గుర్తులేని
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_వాదనలు   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
రకనిర్వచనం నిర్మాణం Sym {
    పూర్ణాంకం v; /* symbol token */
    గుర్తులేని పొట్టి r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    నిర్మాణం SymAttr a; /* symbol attributes */
    సంఘం {
        నిర్మాణం {
            పూర్ణాంకం c; /* associated number or Elf symbol index */
            సంఘం {
                పూర్ణాంకం sym_scope; /* scope level for locals */
                పూర్ణాంకం jnext; /* next jump label */
                పూర్ణాంకం jind; /* label position */
                నిర్మాణం FuncAttr f; /* function attributes */
                పూర్ణాంకం auxtype; /* bitfield access type */
            };
        };
        దీర్ఘ దీర్ఘ enum_val; /* enum constant if IS_ENUM_VAL */
        పూర్ణాంకం *d; /* define token stream */
        నిర్మాణం Sym *cleanup_func;
    };

    CType type; /* associated type */
    సంఘం {
        నిర్మాణం Sym *తదుపరి; /* next related symbol (for fields and anoms) */
        పూర్ణాంకం *e; /* expanded token stream with preprocessor macros */
        పూర్ణాంకం asm_label; /* associated asm label */
        నిర్మాణం Sym *cleanupstate; /* in defined labels */
        పూర్ణాంకం *vla_array_str; /* vla array code */
    };
    నిర్మాణం Sym *prev; /* prev symbol in stack */
    సంఘం {
        నిర్మాణం Sym *prev_tok; /* previous symbol for this token */
        నిర్మాణం Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        నిర్మాణం Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
రకనిర్వచనం నిర్మాణం Section {
    గుర్తులేని దీర్ఘ దత్తాంశం_స్థానభ్రంశం; /* current data offset */
    గుర్తులేని అక్షరం *దత్తాంశం;       /* section data */
    గుర్తులేని దీర్ఘ దత్తాంశం_allocated; /* used for realloc() handling */
    TCCState *s1;
    పూర్ణాంకం sh_name;             /* elf section name (only used during output) */
    పూర్ణాంకం sh_అంకె;              /* elf section number */
    పూర్ణాంకం sh_type;             /* elf section type */
    పూర్ణాంకం sh_flags;            /* elf section flags */
    పూర్ణాంకం sh_info;             /* elf section info */
    పూర్ణాంకం sh_addralign;        /* elf section alignment */
    పూర్ణాంకం sh_entsize;          /* elf entry size */
    గుర్తులేని దీర్ఘ sh_కొలత;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    గుర్తులేని దీర్ఘ sh_స్థానభ్రంశం; /* file offset */
    పూర్ణాంకం nb_hashed_syms;      /* used to resize the hash table */
    నిర్మాణం Section *link;    /* link to another section */
    నిర్మాణం Section *reloc;   /* corresponding section for relocation, if any */
    నిర్మాణం Section *hash;    /* hash table for symbols */
    నిర్మాణం Section *prev;    /* previous section on section stack */
    అక్షరం name[1];           /* section name */
} Section;

రకనిర్వచనం నిర్మాణం DLLReference {
    పూర్ణాంకం level;
    శూన్య *handle;
    గుర్తులేని అక్షరం దొరికింది, సూచీ;
    అక్షరం name[1];
} DLLReference;

/* -------------------------------------------------- */

#నిర్వచించు SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#నిర్వచించు SYM_క్షేత్రం      0x20000000 /* struct/union field symbol space */
#నిర్వచించు SYM_మొదటి_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#నిర్వచించు FUNC_NEW       1 /* ansi function prototype */
#నిర్వచించు FUNC_OLD       2 /* old function prototype */
#నిర్వచించు FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#నిర్వచించు FUNC_CDECL     0 /* standard c call */
#నిర్వచించు FUNC_STDCALL   1 /* pascal c call */
#నిర్వచించు FUNC_FASTCALL1 2 /* first param in %eax */
#నిర్వచించు FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#నిర్వచించు FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#నిర్వచించు FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#నిర్వచించు FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#నిర్వచించు MACRO_OBJ      0 /* object like macro */
#నిర్వచించు MACRO_FUNC     1 /* function like macro */
#నిర్వచించు MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#నిర్వచించు LABEL_DEFINED  0 /* label is defined */
#నిర్వచించు LABEL_FORWARD  1 /* label is forward defined */
#నిర్వచించు LABEL_DECLARED 2 /* label is declared but never used */
#నిర్వచించు LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#నిర్వచించు TYPE_ABSTRACT  1 /* type without variable */
#నిర్వచించు TYPE_ప్రత్యక్ష    2 /* type with variable */
#నిర్వచించు TYPE_PARAM     4 /* type declares function parameter */
#నిర్వచించు TYPE_NEST      8 /* nested call to post_type */

#నిర్వచించు IO_BUF_కొలత 8192

రకనిర్వచనం నిర్మాణం BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_చివర;
    పూర్ణాంకం fd;
    నిర్మాణం BufferedFile *prev;
    పూర్ణాంకం పంక్తి_అంకె;    /* current line number - here to simplify code */
    పూర్ణాంకం పంక్తి_ref;    /* tcc -E: last printed line */
    పూర్ణాంకం ifndef_macro;  /* #ifndef macro / #endif search */
    పూర్ణాంకం ifndef_macro_saved; /* saved ifndef_macro */
    పూర్ణాంకం *ifdef_దొంతర_ptr; /* ifdef_stack value at the start of the file */
    పూర్ణాంకం include_తదుపరి_సూచీ; /* next search path */
    పూర్ణాంకం prev_tok_flags; /* saved tok_flags */
    అక్షరం filename[1024];    /* filename */
    అక్షరం *true_filename; /* filename not modified by # line directive */
    గుర్తులేని అక్షరం unget[4];
    గుర్తులేని అక్షరం బఫరు[1]; /* extra size for CH_EOB char */
} BufferedFile;

#నిర్వచించు CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#నిర్వచించు CH_EOF   (-1)   /* end of file */

/* used to record tokens */
రకనిర్వచనం నిర్మాణం TokenString {
    పూర్ణాంకం *str;
    పూర్ణాంకం len;
    పూర్ణాంకం need_spc;
    పూర్ణాంకం allocated_len;
    పూర్ణాంకం చివరి_పంక్తి_అంకె;
    పూర్ణాంకం save_పంక్తి_అంకె;
    /* used to chain token-strings with begin/end_macro() */
    నిర్మాణం TokenString *prev;
    స్థిరరాశి పూర్ణాంకం *prev_ptr;
    అక్షరం alloc;
} TokenString;

/* GNUC attribute definition */
రకనిర్వచనం నిర్మాణం AttributeDef {
    నిర్మాణం SymAttr a;
    నిర్మాణం FuncAttr f;
    నిర్మాణం Section *section;
    Sym *cleanup_func;
    పూర్ణాంకం alias_లక్ష్యం; /* token */
    పూర్ణాంకం asm_label; /* associated asm label */
    అక్షరం attr_బహుళకం; /* __attribute__((__mode__(...))) */
    అక్షరం new_section; /* section is new */
} AttributeDef;

/* inline functions */
రకనిర్వచనం నిర్మాణం InlineFunc {
    TokenString *func_str;
    Sym *sym;
    అక్షరం filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
రకనిర్వచనం నిర్మాణం CachedInclude {
    పూర్ణాంకం ifndef_macro;
    పూర్ణాంకం once;
    పూర్ణాంకం hash_తదుపరి; /* -1 if none */
    అక్షరం filename[1]; /* path specified in #include */
} CachedInclude;

#నిర్వచించు CACHED_INCLUDES_HASH_కొలత 32

#నిర్వచితమైతే CONFIG_TCC_ASM
రకనిర్వచనం నిర్మాణం సమాసం_విలువ {
    uint64_t v;
    Sym *sym;
    పూర్ణాంకం pcrel;
} సమాసం_విలువ;

#నిర్వచించు MAX_ASM_OPERANDS 30
రకనిర్వచనం నిర్మాణం ASMOperand {
    పూర్ణాంకం id; /* GCC 3 optional identifier (0 if number only supported) */
    అక్షరం constraint[16];
    అక్షరం asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    పూర్ణాంకం ref_సూచీ; /* if >= 0, gives reference to a output constraint */
    పూర్ణాంకం ఆదానం_సూచీ; /* if >= 0, gives reference to an input constraint */
    పూర్ణాంకం ప్రాధాన్యత; /* priority, used to assign registers */
    పూర్ణాంకం reg; /* if >= 0, register number used for this operand */
    పూర్ణాంకం is_llong; /* true if double register value */
    పూర్ణాంకం is_జ్ఞాపకం; /* true if memory operand */
    పూర్ణాంకం is_rw;     /* for '+' modifier */
    పూర్ణాంకం is_label;  /* for asm goto */
} ASMOperand;
#అయితే_ముగింపు

/* extra symbol attributes (not in symbol table) */
నిర్మాణం sym_attr {
    గుర్తులేని got_స్థానభ్రంశం;
    గుర్తులేని plt_స్థానభ్రంశం;
    పూర్ణాంకం plt_sym;
    పూర్ణాంకం dyn_సూచీ;
    గుర్తులేని అక్షరం linker_sym:1;
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    గుర్తులేని అక్షరం plt_thumb_stub:1;
#అయితే_ముగింపు
};

నిర్మాణం TCCState {
    గుర్తులేని అక్షరం verbose; /* if true, display some information during compilation */
    గుర్తులేని అక్షరం nostdinc; /* if true, no standard headers are added */
    గుర్తులేని అక్షరం nostdlib; /* if true, no standard libraries are added */
    గుర్తులేని అక్షరం nostdlib_paths; /* if true, the default paths are not searched for libraries */
    గుర్తులేని అక్షరం nocommon; /* if true, do not use common symbols for .bss data */
    గుర్తులేని అక్షరం static_link; /* if true, static linking is performed */
    గుర్తులేని అక్షరం rdynamic; /* if true, all symbols are exported */
    గుర్తులేని అక్షరం symbolic; /* if true, resolve symbols in the current module first */
    గుర్తులేని అక్షరం znodelete; /* Set DF_1_NODELETE in dynamic section */
    గుర్తులేని అక్షరం filetype; /* file type for compilation (NONE,C,ASM) */
    గుర్తులేని అక్షరం optimize; /* only to #define __OPTIMIZE__ */
    గుర్తులేని అక్షరం option_pthread; /* -pthread option */
    గుర్తులేని అక్షరం enable_new_dtags; /* -Wl,--enable-new-dtags */
    గుర్తులేని పూర్ణాంకం  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    గుర్తులేని అక్షరం char_is_unsigned;
    గుర్తులేని అక్షరం leading_underscore;
    గుర్తులేని అక్షరం ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    గుర్తులేని అక్షరం dollars_లోపల_identifiers;  /* allows '$' char in identifiers */
    గుర్తులేని అక్షరం ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    గుర్తులేని అక్షరం తిరగేయి_funcargs; /* if true, evaluate last function arg first */
    గుర్తులేని అక్షరం gnu89_inline; /* treat 'extern inline' like 'static inline' */
    గుర్తులేని అక్షరం unwind_tables; /* create eh_frame section */

    /* warning switches */
    గుర్తులేని అక్షరం warn_none;
    గుర్తులేని అక్షరం warn_all;
    గుర్తులేని అక్షరం warn_error;
    గుర్తులేని అక్షరం warn_write_అక్షరశ్రేణులు;
    గుర్తులేని అక్షరం warn_unsupported;
    గుర్తులేని అక్షరం warn_implicit_function_declaration;
    గుర్తులేని అక్షరం warn_discarded_qualifiers;
    #నిర్వచించు WARN_ON  1 /* warning is on (-Woption) */
    గుర్తులేని అక్షరం warn_అంకె; /* temp var for tcc_warning_c() */

    గుర్తులేని అక్షరం option_r; /* option -r */
    గుర్తులేని అక్షరం do_bench; /* option -bench */
    గుర్తులేని అక్షరం just_deps; /* option -M  */
    గుర్తులేని అక్షరం gen_deps; /* option -MD  */
    గుర్తులేని అక్షరం include_sys_deps; /* option -MD  */
    గుర్తులేని అక్షరం gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    గుర్తులేని అక్షరం do_debug;
    గుర్తులేని అక్షరం dwarf;
    గుర్తులేని అక్షరం do_backtrace;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    గుర్తులేని అక్షరం do_bounds_check;
#అయితే_ముగింపు
    గుర్తులేని అక్షరం test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    గుర్తులేని అక్షరం gnu_ext;
    /* use TinyCC extensions */
    గుర్తులేని అక్షరం tcc_ext;

    గుర్తులేని అక్షరం dflag; /* -dX value */
    గుర్తులేని అక్షరం Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    గుర్తులేని అక్షరం nosse; /* For -mno-sse support. */
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    గుర్తులేని అక్షరం float_abi; /* float ABI of the generated code*/
#అయితే_ముగింపు

    గుర్తులేని అక్షరం has_పాఠ్యం_addr;
    addr_t పాఠ్యం_addr; /* address of text section */
    గుర్తులేని section_align; /* section alignment */
#నిర్వచితమైతే TCC_లక్ష్యం_I386
    పూర్ణాంకం seg_కొలత; /* 32. Can be 16 with i386 assembler (.code16) */
#అయితే_ముగింపు

    అక్షరం *tcc_lib_మార్గం; /* CONFIG_TCCDIR or -B option */
    అక్షరం *soname; /* as specified on the command line (-soname) */
    అక్షరం *rpath; /* as specified on the command line (-Wl,-rpath=) */
    అక్షరం *elfint; /* -Wl,-I... on command line */
    అక్షరం *elf_entryname; /* "_start" unless set */
    అక్షరం *init_చిహ్నం; /* symbols to call at load-time (not used currently) */
    అక్షరం *fini_చిహ్నం; /* symbols to call at unload-time (not used currently) */
    అక్షరం *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    పూర్ణాంకం output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    పూర్ణాంకం output_format;
    /* nth test to run with -dt -run */
    పూర్ణాంకం నిరంతరం_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    పూర్ణాంకం nb_loaded_dlls;

    /* include paths */
    అక్షరం **include_paths;
    పూర్ణాంకం nb_include_paths;

    అక్షరం **sysinclude_paths;
    పూర్ణాంకం nb_sysinclude_paths;

    /* library paths */
    అక్షరం **library_paths;
    పూర్ణాంకం nb_library_paths;

    /* crt?.o object path */
    అక్షరం **crt_paths;
    పూర్ణాంకం nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    శూన్య *error_opaque;
    శూన్య (*error_func)(శూన్య *opaque, స్థిరరాశి అక్షరం *సందేశం);
    పూర్ణాంకం error_సమితి_jmp_enabled;
    jmp_buf error_jmp_buf;
    పూర్ణాంకం nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    అక్షరం **లక్ష్యం_deps;
    పూర్ణాంకం nb_లక్ష్యం_deps;

    /* compilation */
    BufferedFile *include_దొంతర[INCLUDE_దొంతర_కొలత];
    BufferedFile **include_దొంతర_ptr;

    పూర్ణాంకం ifdef_దొంతర[IFDEF_దొంతర_కొలత];
    పూర్ణాంకం *ifdef_దొంతర_ptr;

    /* included files enclosed with #ifndef MACRO */
    పూర్ణాంకం cached_includes_hash[CACHED_INCLUDES_HASH_కొలత];
    CachedInclude **cached_includes;
    పూర్ణాంకం nb_cached_includes;

    /* #pragma pack stack */
    పూర్ణాంకం pack_దొంతర[PACK_దొంతర_కొలత];
    పూర్ణాంకం *pack_దొంతర_ptr;
    అక్షరం **pragma_libs;
    పూర్ణాంకం nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    నిర్మాణం InlineFunc **inline_fns;
    పూర్ణాంకం nb_inline_fns;

    /* sections */
    Section **sections;
    పూర్ణాంకం nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    పూర్ణాంకం nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *పాఠ్యం_section, *దత్తాంశం_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_పాఠ్యం_section; /* current section where function code is generated */
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#అయితే_ముగింపు
    /* symbol section */
    సంఘం { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_చట్రం_section;
    Section *eh_చట్రం_hdr_section;
    గుర్తులేని దీర్ఘ eh_ప్రారంభం;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_పంక్తి_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_పంక్తి_str_section;
    పూర్ణాంకం dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    నిర్మాణం _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    నిర్మాణం sym_attr *sym_attrs;
    పూర్ణాంకం nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #నిర్వచించు qrel s1->qrel

    addr_t tls_ప్రారంభం, tls_చివర;

#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
    నిర్మాణం pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    పూర్ణాంకం nb_pcrel_hi_entries;
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_PE
    /* PE info */
    పూర్ణాంకం pe_subsystem;
    గుర్తులేని pe_characteristics;
    గుర్తులేని pe_dll_characteristics;
    గుర్తులేని pe_file_align;
    గుర్తులేని pe_దొంతర_కొలత;
    addr_t pe_imagebase;
# ఒకవేళ defined(TCC_లక్ష్యం_X86_64) || defined(TCC_లక్ష్యం_ARM64)
    Section *uw_pdata;
    పూర్ణాంకం uw_sym;
    పూర్ణాంకం uw_xsym;
    గుర్తులేని uw_offs;
# endif
#అయితే_ముగింపు

#ఒకవేళ defined TCC_లక్ష్యం_MACHO
    అక్షరం *install_name;
    uint32_t compatibility_సంస్కరణ;
    uint32_t current_సంస్కరణ;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
    పూర్ణాంకం nb_sym_versions;
    నిర్మాణం sym_సంస్కరణ *sym_versions;
    పూర్ణాంకం nb_sym_గమ్యం_సంస్కరణ;
    పూర్ణాంకం *sym_గమ్యం_సంస్కరణ;
    పూర్ణాంకం dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_IS_NATIVE
    స్థిరరాశి అక్షరం *నిరంతరం_main; /* entry for tcc_run() */
    శూన్య *నిరంతరం_ptr; /* runtime_memory */
    గుర్తులేని నిరంతరం_కొలత; /* size of runtime_memory  */
    స్థిరరాశి అక్షరం *నిరంతరం_stdin; /* custom stdin file for run_main */
#నిర్వచితమైతే _WIN64
    శూన్య *నిరంతరం_function_పట్టిక; /* unwind data */
#అయితే_ముగింపు
    నిర్మాణం TCCState *తదుపరి;
    నిర్మాణం rt_context *rc; /* pointer to backtrace info block */
    శూన్య *నిరంతరం_lj, *నిరంతరం_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    శూన్య *bt_దత్తాంశం;
#అయితే_ముగింపు

#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    పూర్ణాంకం rt_అంకె_callers;
#అయితే_ముగింపు

    /* benchmark info */
    పూర్ణాంకం మొత్తం_idents;
    పూర్ణాంకం మొత్తం_పంక్తులు;
    గుర్తులేని పూర్ణాంకం మొత్తం_బైట్లు;
    గుర్తులేని పూర్ణాంకం మొత్తం_output[4];

    /* used by tcc_load_ldscript */
    గుర్తులేని అక్షరం *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    స్థిరరాశి అక్షరం *current_filename;

    /* used by main and tcc_parse_args only */
    నిర్మాణం filespec **files; /* files seen on command line */
    పూర్ణాంకం nb_files; /* number thereof */
    పూర్ణాంకం nb_libraries; /* number of libs thereof */
    అక్షరం *outfile; /* output filename */
    అక్షరం *deps_outfile; /* option -MF */
    పూర్ణాంకం argc;
    అక్షరం **argv;
    /* -Wl options */
    అక్షరం **link_argv;
    పూర్ణాంకం link_argc, link_optind;
};

నిర్మాణం filespec {
    అక్షరం type;
    అక్షరం name[1];
};

/* The current value can be: */
#నిర్వచించు VT_VALMASK   0x003f  /* mask for value location, register or: */
#నిర్వచించు VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#నిర్వచించు VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#నిర్వచించు VT_LOCAL     0x0032  /* offset on stack */
#నిర్వచించు VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#నిర్వచించు VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#నిర్వచించు VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#నిర్వచించు VT_LVAL      0x0100  /* var is an lvalue */
#నిర్వచించు VT_SYM       0x0200  /* a symbol value is added */
#నిర్వచించు VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#నిర్వచించు VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#నిర్వచించు VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#నిర్వచించు VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#నిర్వచించు VT_BTYPE       0x000f  /* mask for basic type */
#నిర్వచించు VT_VOID             0  /* void type */
#నిర్వచించు VT_BYTE             1  /* signed byte type */
#నిర్వచించు VT_SHORT            2  /* short type */
#నిర్వచించు VT_INT              3  /* integer type */
#నిర్వచించు VT_LLONG            4  /* 64 bit integer */
#నిర్వచించు VT_PTR              5  /*సూచిక*/
#నిర్వచించు VT_FUNC             6  /* function type */
#నిర్వచించు VT_STRUCT           7  /* struct/union definition */
#నిర్వచించు VT_FLOAT            8  /* IEEE float */
#నిర్వచించు VT_DOUBLE           9  /* IEEE double */
#నిర్వచించు VT_LDOUBLE         10  /* IEEE long double */
#నిర్వచించు VT_BOOL            11  /* ISOC99 boolean type */
#నిర్వచించు VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#నిర్వచించు VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#నిర్వచించు VT_UNSIGNED    0x0010  /* unsigned type */
#నిర్వచించు VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#నిర్వచించు VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#నిర్వచించు VT_BITFIELD    0x0080  /* bitfield modifier */
#నిర్వచించు VT_CONSTANT    0x0100  /* const modifier */
#నిర్వచించు VT_VOLATILE    0x0200  /* volatile modifier */
#నిర్వచించు VT_RESTRICT    0x0400  /* restrict modifier */
#నిర్వచించు VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#నిర్వచించు VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#నిర్వచించు VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#నిర్వచించు VT_EXTERN  0x00002000  /* extern definition */
#నిర్వచించు VT_STATIC  0x00004000  /* static variable */
#నిర్వచించు VT_TYPEDEF 0x00008000  /* typedef definition */
#నిర్వచించు VT_INLINE  0x00010000  /* inline definition */
#నిర్వచించు VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#నిర్వచించు VT_STRUCT_జరుపు 20     /* shift for bitfield shift values (32 - 2*6) */
#నిర్వచించు VT_STRUCT_ముసుగు (((1U << (6+6)) - 1) << VT_STRUCT_జరుపు | VT_BITFIELD)
#నిర్వచించు బిట్టు_POS(t) (((t) >> VT_STRUCT_జరుపు) & 0x3f)
#నిర్వచించు బిట్టు_కొలత(t) (((t) >> (VT_STRUCT_జరుపు + 6)) & 0x3f)

#నిర్వచించు VT_UNION    (1 << VT_STRUCT_జరుపు | VT_STRUCT)
#నిర్వచించు VT_ENUM     (2 << VT_STRUCT_జరుపు) /* integral type is an enum really */
#నిర్వచించు VT_ENUM_VAL (3 << VT_STRUCT_జరుపు) /* integral type is an enum constant really */

#నిర్వచించు IS_ENUM(t) ((t & VT_STRUCT_ముసుగు) == VT_ENUM)
#నిర్వచించు IS_ENUM_VAL(t) ((t & VT_STRUCT_ముసుగు) == VT_ENUM_VAL)
#నిర్వచించు IS_UNION(t) ((t & (VT_STRUCT_ముసుగు|VT_BTYPE)) == VT_UNION)

#నిర్వచించు VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#నిర్వచించు VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#నిర్వచించు VT_TYPE (~(VT_STORAGE|VT_STRUCT_ముసుగు))

/* symbol was created by tccasm.c first */
#నిర్వచించు VT_ASM (VT_VOID | 4 << VT_STRUCT_జరుపు)
#నిర్వచించు VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_జరుపు)
#నిర్వచించు IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_ముసుగు) & ~(1<<VT_STRUCT_జరుపు))) == VT_ASM)
#నిర్వచించు IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_ముసుగు)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#నిర్వచించు VT_BT_ARRAY (6 << VT_STRUCT_జరుపు)
#నిర్వచించు IS_BT_ARRAY(t) ((t & VT_STRUCT_ముసుగు) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#నిర్వచించు BFVAL(M,N) ((గుర్తులేని)((M) & ~((M) << 1)) * (N))
#నిర్వచించు BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#నిర్వచించు BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#నిర్వచించు TOK_LAND  0x90
#నిర్వచించు TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#నిర్వచించు TOK_ULT 0x92
#నిర్వచించు TOK_UGE 0x93
#నిర్వచించు TOK_EQ  0x94
#నిర్వచించు TOK_NE  0x95
#నిర్వచించు TOK_ULE 0x96
#నిర్వచించు TOK_UGT 0x97
#నిర్వచించు TOK_Nset 0x98
#నిర్వచించు TOK_Nclear 0x99
#నిర్వచించు TOK_LT  0x9c
#నిర్వచించు TOK_GE  0x9d
#నిర్వచించు TOK_LE  0x9e
#నిర్వచించు TOK_GT  0x9f

#నిర్వచించు TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#నిర్వచించు TOK_DEC     0x80 /* -- */
#నిర్వచించు TOK_MID     0x81 /* inc/dec, to void constant */
#నిర్వచించు TOK_INC     0x82 /* ++ */
#నిర్వచించు TOK_UDIV    0x83 /* unsigned division */
#నిర్వచించు TOK_UMOD    0x84 /* unsigned modulo */
#నిర్వచించు TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#నిర్వచించు TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#నిర్వచించు TOK_ADDC1   0x87 /* add with carry generation */
#నిర్వచించు TOK_ADDC2   0x88 /* add with carry use */
#నిర్వచించు TOK_SUBC1   0x89 /* add with carry generation */
#నిర్వచించు TOK_SUBC2   0x8a /* add with carry use */
#నిర్వచించు TOK_SHL     '<' /* shift left */
#నిర్వచించు TOK_SAR     '>' /* signed shift right */
#నిర్వచించు TOK_SHR     0x8b /* unsigned shift right */
#నిర్వచించు TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#నిర్వచించు TOK_ARROW   0xa0 /* -> */
#నిర్వచించు TOK_DOTS    0xa1 /* three dots */
#నిర్వచించు TOK_TWODOTS 0xa2 /* C++ token ? */
#నిర్వచించు TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#నిర్వచించు TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#నిర్వచించు TOK_PPJOIN  (TOK_TWOSHARPS | SYM_క్షేత్రం) /* A '##' in a macro to mean pasting */
#నిర్వచించు TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#నిర్వచించు TOK_A_కూడు   0xb0
#నిర్వచించు TOK_A_SUB   0xb1
#నిర్వచించు TOK_A_MUL   0xb2
#నిర్వచించు TOK_A_DIV   0xb3
#నిర్వచించు TOK_A_MOD   0xb4
#నిర్వచించు TOK_A_AND   0xb5
#నిర్వచించు TOK_A_OR    0xb6
#నిర్వచించు TOK_A_XOR   0xb7
#నిర్వచించు TOK_A_SHL   0xb8
#నిర్వచించు TOK_A_SAR   0xb9

#నిర్వచించు TOK_కేటాయించు(t) (t >= TOK_A_కూడు && t <= TOK_A_SAR)
#నిర్వచించు TOK_కేటాయించు_OP(t) ("+-*/%&|^<>"[t - TOK_A_కూడు])

/* tokens that carry values (in additional token string space / tokc) --> */
#నిర్వచించు TOK_CCHAR   0xc0 /* char constant in tokc */
#నిర్వచించు TOK_LCHAR   0xc1
#నిర్వచించు TOK_CINT    0xc2 /* number in tokc */
#నిర్వచించు TOK_CUINT   0xc3 /* unsigned int constant */
#నిర్వచించు TOK_CLLONG  0xc4 /* long long constant */
#నిర్వచించు TOK_CULLONG 0xc5 /* unsigned long long constant */
#నిర్వచించు TOK_CLONG   0xc6 /* long constant */
#నిర్వచించు TOK_CULONG  0xc7 /* unsigned long constant */
#నిర్వచించు TOK_STR     0xc8 /* pointer to string in tokc */
#నిర్వచించు TOK_LSTR    0xc9
#నిర్వచించు TOK_CFLOAT  0xca /* float constant */
#నిర్వచించు TOK_CDOUBLE 0xcb /* double constant */
#నిర్వచించు TOK_CLDOUBLE 0xcc /* long double constant */
#నిర్వచించు TOK_PPNUM   0xcd /* preprocessor number */
#నిర్వచించు TOK_PPSTR   0xce /* preprocessor string */
#నిర్వచించు TOK_LINENUM 0xcf /* line number info */

#నిర్వచించు TOK_HAS_విలువ(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#నిర్వచించు TOK_EOF       (-1)  /* end of file */
#నిర్వచించు TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#నిర్వచించు TOK_IDENT 256

గణన tcc_token {
    TOK_చివరి = TOK_IDENT - 1
#నిర్వచించు DEF(id, str) ,id
#అన్తర్భావ "tcctok.h"
#నిర్వచనం_రద్దు DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#నిర్వచించు TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_దత్తాంశం నిర్మాణం TCCState *tcc_state;
ST_దత్తాంశం శూన్య** stk_దత్తాంశం;
ST_దత్తాంశం పూర్ణాంకం nb_stk_దత్తాంశం;
ST_దత్తాంశం పూర్ణాంకం g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC అక్షరం *pstrcpy(అక్షరం *buf, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s);
ST_FUNC అక్షరం *pstrcat(అక్షరం *buf, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s);
ST_FUNC అక్షరం *pstrncpy(అక్షరం *బహిర్గతం, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s, కొలత_t అంకె);
PUB_FUNC అక్షరం *tcc_basename(స్థిరరాశి అక్షరం *name);
PUB_FUNC అక్షరం *tcc_fileextension (స్థిరరాశి అక్షరం *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC శూన్య tcc_free(శూన్య *ptr);
PUB_FUNC శూన్య *tcc_malloc(గుర్తులేని దీర్ఘ కొలత);
PUB_FUNC శూన్య *tcc_mallocz(గుర్తులేని దీర్ఘ కొలత);
PUB_FUNC శూన్య *tcc_realloc(శూన్య *ptr, గుర్తులేని దీర్ఘ కొలత);
PUB_FUNC అక్షరం *tcc_strdup(స్థిరరాశి అక్షరం *str);

#నిర్వచితమైతే MEM_DEBUG
#నిర్వచించు tcc_free(ptr)           tcc_free_debug(ptr)
#నిర్వచించు tcc_malloc(కొలత)        tcc_malloc_debug(కొలత, __FILE__, __LINE__)
#నిర్వచించు tcc_mallocz(కొలత)       tcc_mallocz_debug(కొలత, __FILE__, __LINE__)
#నిర్వచించు tcc_realloc(ptr,కొలత)   tcc_realloc_debug(ptr, కొలత, __FILE__, __LINE__)
#నిర్వచించు tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC శూన్య tcc_free_debug(శూన్య *ptr);
PUB_FUNC శూన్య *tcc_malloc_debug(గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి);
PUB_FUNC శూన్య *tcc_mallocz_debug(గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి);
PUB_FUNC శూన్య *tcc_realloc_debug(శూన్య *ptr, గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి);
PUB_FUNC అక్షరం *tcc_strdup_debug(స్థిరరాశి అక్షరం *str, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి);
#అయితే_ముగింపు

ST_FUNC శూన్య libc_free(శూన్య *ptr);
/* defined to be not used */
#నిర్వచించు విడుదల(p) use_tcc_free(p)
#నిర్వచించు జ్ఞాపకం_ఇవ్వు(s) use_tcc_malloc(s)
#నిర్వచించు realloc(p, s) use_tcc_realloc(p, s)
#నిర్వచనం_రద్దు strdup
#నిర్వచించు strdup(s) use_tcc_strdup(s)
PUB_FUNC పూర్ణాంకం _tcc_error_noabort(స్థిరరాశి అక్షరం *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN శూన్య _tcc_error(స్థిరరాశి అక్షరం *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC శూన్య _tcc_warning(స్థిరరాశి అక్షరం *fmt, ...) PRINTF_LIKE(1,2);
#నిర్వచించు tcc_అంతర్గత_error(సందేశం) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,సందేశం)

/* other utilities */
ST_FUNC శూన్య dynarray_కూడు(శూన్య *ptab, పూర్ణాంకం *nb_ptr, శూన్య *దత్తాంశం);
ST_FUNC శూన్య dynarray_reset(శూన్య *pp, పూర్ణాంకం *n);
ST_INLN శూన్య cstr_ccat(CString *cstr, పూర్ణాంకం ch);
ST_FUNC శూన్య cstr_cat(CString *cstr, స్థిరరాశి అక్షరం *str, పూర్ణాంకం len);
ST_FUNC శూన్య cstr_wccat(CString *cstr, పూర్ణాంకం ch);
ST_FUNC శూన్య cstr_new(CString *cstr);
ST_FUNC శూన్య cstr_free(CString *cstr);
ST_FUNC పూర్ణాంకం cstr_printf(CString *cs, స్థిరరాశి అక్షరం *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC పూర్ణాంకం cstr_vprintf(CString *cstr, స్థిరరాశి అక్షరం *fmt, va_list ap);
ST_FUNC శూన్య cstr_reset(CString *cstr);
ST_FUNC శూన్య tcc_open_bf(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం initlen);
ST_FUNC పూర్ణాంకం tcc_open(TCCState *s1, స్థిరరాశి అక్షరం *filename);
ST_FUNC శూన్య tcc_close(శూన్య);

/* mark a memory pointer on stack for cleanup after errors */
#నిర్వచించు stk_నెట్టు(p) dynarray_కూడు(&stk_దత్తాంశం, &nb_stk_దత్తాంశం, p)
#నిర్వచించు stk_తీయి() (--nb_stk_దత్తాంశం)
/* mark CString on stack for cleanup errors */
#నిర్వచించు cstr_new_s(cstr) (cstr_new(cstr), stk_నెట్టు(&(cstr)->దత్తాంశం))
#నిర్వచించు cstr_free_s(cstr) (cstr_free(cstr), stk_తీయి())

ST_FUNC పూర్ణాంకం tcc_కూడు_file_అంతర్గత(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flags);
/* flags: */
#నిర్వచించు AFF_PRINT_ERROR     0x10 /* print error if file not found */
#నిర్వచించు AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#నిర్వచించు AFF_TYPE_BIN        0x40 /* file to add is binary */
#నిర్వచించు AFF_సంపూర్ణ_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#నిర్వచించు AFF_TYPE_NONE   0
#నిర్వచించు AFF_TYPE_C      1
#నిర్వచించు AFF_TYPE_ASM    2
#నిర్వచించు AFF_TYPE_ASMPP  4
#నిర్వచించు AFF_TYPE_LIB    8
#నిర్వచించు AFF_TYPE_ముసుగు   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#నిర్వచించు AFF_BINTYPE_REL 1
#నిర్వచించు AFF_BINTYPE_DYN 2
#నిర్వచించు AFF_BINTYPE_AR  3
#నిర్వచించు AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#నిర్వచించు FILE_NOT_దొరికింది -2
#నిర్వచించు FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
ST_FUNC పూర్ణాంకం tcc_కూడు_crt(TCCState *s, స్థిరరాశి అక్షరం *filename);
#అయితే_ముగింపు
ST_FUNC పూర్ణాంకం tcc_కూడు_dll(TCCState *s, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flags);
ST_FUNC పూర్ణాంకం tcc_కూడు_support(TCCState *s1, స్థిరరాశి అక్షరం *filename);
#నిర్వచితమైతే CONFIG_TCC_BCHECK
ST_FUNC శూన్య tcc_కూడు_bcheck(TCCState *s1);
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
ST_FUNC శూన్య tcc_కూడు_btstub(TCCState *s1);
#అయితే_ముగింపు
ST_FUNC శూన్య tcc_కూడు_pragma_libs(TCCState *s1);
PUB_FUNC పూర్ణాంకం tcc_కూడు_library_err(TCCState *s, స్థిరరాశి అక్షరం *f);
PUB_FUNC శూన్య tcc_print_stats(TCCState *s, గుర్తులేని మొత్తం_సమయం);
PUB_FUNC పూర్ణాంకం tcc_parse_వాదనలు(TCCState *s, పూర్ణాంకం *argc, అక్షరం ***argv);
#నిర్వచితమైతే _WIN32
ST_FUNC అక్షరం *normalize_slashes(అక్షరం *మార్గం);
PUB_FUNC FILE *tcc_fopen(స్థిరరాశి అక్షరం *f, స్థిరరాశి అక్షరం *m);
PUB_FUNC పూర్ణాంకం tcc_fclose(FILE *f);
#లేకపోతే
# define tcc_fopen fopen
# define tcc_fclose fclose
#అయితే_ముగింపు
ST_FUNC DLLReference *tcc_కూడు_dllref(TCCState *s1, స్థిరరాశి అక్షరం *dllname, పూర్ణాంకం level);
ST_FUNC అక్షరం *tcc_ఎక్కించు_పాఠ్యం(పూర్ణాంకం fd);
/* for #pragma once */
ST_FUNC పూర్ణాంకం normalized_PATHCMP(స్థిరరాశి అక్షరం *f1, స్థిరరాశి అక్షరం *f2);

/* tcc_parse_args return codes: */
#నిర్వచించు OPT_HELP 1
#నిర్వచించు OPT_HELP2 2
#నిర్వచించు OPT_V 3
#నిర్వచించు OPT_PRINT_DIRS 4
#నిర్వచించు OPT_AR 5
#నిర్వచించు OPT_IMPDEF 6
#నిర్వచించు OPT_M32 32
#నిర్వచించు OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_దత్తాంశం నిర్మాణం BufferedFile *file;
ST_దత్తాంశం పూర్ణాంకం tok;
ST_దత్తాంశం CValue tokc;
ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం *macro_ptr;
ST_దత్తాంశం పూర్ణాంకం parse_flags;
ST_దత్తాంశం పూర్ణాంకం tok_flags;
ST_దత్తాంశం CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_దత్తాంశం పూర్ణాంకం tok_ident;
ST_దత్తాంశం TokenSym **పట్టిక_ident;
ST_దత్తాంశం పూర్ణాంకం pp_సమాసం;

#నిర్వచించు TOK_FLAG_BOL   0x0001 /* beginning of line before */
#నిర్వచించు TOK_FLAG_BOF   0x0002 /* beginning of file before */
#నిర్వచించు TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#నిర్వచించు PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#నిర్వచించు PARSE_FLAG_TOK_అంకె    0x0002 /* return numbers instead of TOK_PPNUM */
#నిర్వచించు PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#నిర్వచించు PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#నిర్వచించు PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#నిర్వచించు PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#నిర్వచించు PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#నిర్వచించు IS_SPC 1
#నిర్వచించు IS_ID  2
#నిర్వచించు IS_అంకె 4

గణన పంక్తి_macro_output_format {
    పంక్తి_MACRO_OUTPUT_FORMAT_GCC,
    పంక్తి_MACRO_OUTPUT_FORMAT_NONE,
    పంక్తి_MACRO_OUTPUT_FORMAT_STD,
    పంక్తి_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(స్థిరరాశి అక్షరం *str, పూర్ణాంకం len);
ST_FUNC పూర్ణాంకం tok_alloc_const(స్థిరరాశి అక్షరం *str);
ST_FUNC స్థిరరాశి అక్షరం *get_tok_str(పూర్ణాంకం v, CValue *cv);
ST_FUNC శూన్య begin_macro(TokenString *str, పూర్ణాంకం alloc);
ST_FUNC శూన్య చివర_macro(శూన్య);
ST_FUNC పూర్ణాంకం సమితి_idnum(పూర్ణాంకం c, పూర్ణాంకం val);
ST_INLN శూన్య tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(శూన్య);
ST_FUNC శూన్య tok_str_free(TokenString *s);
ST_FUNC శూన్య tok_str_free_str(పూర్ణాంకం *str);
ST_FUNC శూన్య tok_str_కూడు(TokenString *s, పూర్ణాంకం t);
ST_FUNC శూన్య tok_str_కూడు_tok(TokenString *s);
ST_INLN శూన్య define_నెట్టు(పూర్ణాంకం v, పూర్ణాంకం macro_type, పూర్ణాంకం *str, Sym *మొదటి_arg);
ST_FUNC శూన్య define_undef(Sym *s);
ST_INLN Sym *define_కనుగొను(పూర్ణాంకం v);
ST_FUNC శూన్య free_నిర్వచిస్తుంది(Sym *b);
ST_FUNC శూన్య parse_define(శూన్య);
ST_FUNC శూన్య skip_గమ్యం_eol(పూర్ణాంకం warn);
ST_FUNC శూన్య preprocess(పూర్ణాంకం is_bof);
ST_FUNC శూన్య తదుపరి(శూన్య);
ST_INLN శూన్య unget_tok(పూర్ణాంకం చివరి_tok);
ST_FUNC శూన్య preprocess_ప్రారంభం(TCCState *s1, పూర్ణాంకం filetype);
ST_FUNC శూన్య preprocess_చివర(TCCState *s1);
ST_FUNC శూన్య tccpp_new(TCCState *s);
ST_FUNC శూన్య tccpp_delete(TCCState *s);
ST_FUNC శూన్య tccpp_putfile(స్థిరరాశి అక్షరం *filename);
ST_FUNC పూర్ణాంకం tcc_preprocess(TCCState *s1);
ST_FUNC శూన్య skip(పూర్ణాంకం c);
ST_FUNC NORETURN శూన్య expect(స్థిరరాశి అక్షరం *సందేశం);
ST_FUNC శూన్య pp_error(CString *cs);


/* space excluding newline */
స్థిర అంతఃవరుస పూర్ణాంకం is_space(పూర్ణాంకం ch) {
    తిరిగి ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
స్థిర అంతఃవరుస పూర్ణాంకం isid(పూర్ణాంకం c) {
    తిరిగి (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
స్థిర అంతఃవరుస పూర్ణాంకం isnum(పూర్ణాంకం c) {
    తిరిగి c >= '0' && c <= '9';
}
స్థిర అంతఃవరుస పూర్ణాంకం isoct(పూర్ణాంకం c) {
    తిరిగి c >= '0' && c <= '7';
}
స్థిర అంతఃవరుస పూర్ణాంకం toup(పూర్ణాంకం c) {
    తిరిగి (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#నిర్వచించు SYM_POOL_NB (8192 / పరిమాణం(Sym))

ST_దత్తాంశం Sym *global_దొంతర;
ST_దత్తాంశం Sym *local_దొంతర;
ST_దత్తాంశం Sym *local_label_దొంతర;
ST_దత్తాంశం Sym *global_label_దొంతర;
ST_దత్తాంశం Sym *define_దొంతర;
ST_దత్తాంశం CType int_type, func_old_type, char_సూచిక_type;
ST_దత్తాంశం SValue *vtop;
ST_దత్తాంశం పూర్ణాంకం rsym, anon_sym, ind, loc;
ST_దత్తాంశం అక్షరం debug_modes;

ST_దత్తాంశం పూర్ణాంకం nocode_wanted; /* true if no code generation wanted for an expression */
ST_దత్తాంశం పూర్ణాంకం global_సమాసం;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_దత్తాంశం CType func_vt; /* current function return type (used by return instruction) */
ST_దత్తాంశం పూర్ణాంకం func_var; /* true if current function is variadic */
ST_దత్తాంశం పూర్ణాంకం func_vc; /* stack address for implicit struct return storage */
ST_దత్తాంశం పూర్ణాంకం func_ind; /* function start address */
ST_దత్తాంశం స్థిరరాశి అక్షరం *funcname;

ST_FUNC శూన్య tccgen_init(TCCState *s1);
ST_FUNC పూర్ణాంకం tccgen_compile(TCCState *s1);
ST_FUNC శూన్య tccgen_ముగింపు(TCCState *s1);
ST_FUNC శూన్య check_vstack(శూన్య);

ST_INLN పూర్ణాంకం is_float(పూర్ణాంకం t);
ST_FUNC పూర్ణాంకం ieee_finite(ద్విగుణ d);
ST_FUNC పూర్ణాంకం exact_log2p1(పూర్ణాంకం i);
ST_FUNC శూన్య test_lvalue(శూన్య);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC శూన్య update_storage(Sym *sym);
ST_FUNC శూన్య put_extern_sym2(Sym *sym, పూర్ణాంకం sh_అంకె, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత, పూర్ణాంకం can_కూడు_underscore);
ST_FUNC శూన్య put_extern_sym(Sym *sym, Section *section, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత);
#ఒకవేళ PTR_కొలత == 4
ST_FUNC శూన్య greloc(Section *s, Sym *sym, గుర్తులేని దీర్ఘ స్థానభ్రంశం, పూర్ణాంకం type);
#అయితే_ముగింపు
ST_FUNC శూన్య greloca(Section *s, Sym *sym, గుర్తులేని దీర్ఘ స్థానభ్రంశం, పూర్ణాంకం type, addr_t addend);

ST_INLN శూన్య sym_free(Sym *sym);
ST_FUNC Sym *sym_నెట్టు(పూర్ణాంకం v, CType *type, పూర్ణాంకం r, పూర్ణాంకం c);
ST_FUNC శూన్య sym_తీయి(Sym **ptop, Sym *b, పూర్ణాంకం keep);
ST_FUNC Sym *sym_push2(Sym **ps, పూర్ణాంకం v, పూర్ణాంకం t, పూర్ణాంకం c);
ST_FUNC Sym *sym_find2(Sym *s, పూర్ణాంకం v);
ST_INLN Sym *sym_కనుగొను(పూర్ణాంకం v);
ST_FUNC Sym *label_కనుగొను(పూర్ణాంకం v);
ST_FUNC Sym *label_నెట్టు(Sym **ptop, పూర్ణాంకం v, పూర్ణాంకం flags);
ST_FUNC శూన్య label_తీయి(Sym **ptop, Sym *slast, పూర్ణాంకం keep);
ST_INLN Sym *struct_కనుగొను(పూర్ణాంకం v);

ST_FUNC Sym *global_identifier_నెట్టు(పూర్ణాంకం v, పూర్ణాంకం t, పూర్ణాంకం c);
ST_FUNC Sym *external_global_sym(పూర్ణాంకం v, CType *type);
ST_FUNC Sym *external_helper_sym(పూర్ణాంకం v);
ST_FUNC శూన్య vpush_helper_func(పూర్ణాంకం v);
ST_FUNC శూన్య vset(CType *type, పూర్ణాంకం r, పూర్ణాంకం v);
ST_FUNC శూన్య vset_VT_CMP(పూర్ణాంకం op);
ST_FUNC శూన్య vpushi(పూర్ణాంకం v);
ST_FUNC శూన్య vpushv(SValue *v);
ST_FUNC శూన్య vpushsym(CType *type, Sym *sym);
ST_FUNC శూన్య vswap(శూన్య);
ST_FUNC శూన్య vrott(పూర్ణాంకం n);
ST_FUNC శూన్య vrotb(పూర్ణాంకం n);
ST_FUNC శూన్య vrev(పూర్ణాంకం n);
ST_FUNC శూన్య vpop(శూన్య);
#ఒకవేళ PTR_కొలత == 4
ST_FUNC శూన్య lexpand(శూన్య);
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
ST_FUNC పూర్ణాంకం get_reg_ex(పూర్ణాంకం rc, పూర్ణాంకం rc2);
#అయితే_ముగింపు
ST_FUNC శూన్య save_reg(పూర్ణాంకం r);
ST_FUNC శూన్య save_reg_upstack(పూర్ణాంకం r, పూర్ణాంకం n);
ST_FUNC పూర్ణాంకం get_reg(పూర్ణాంకం rc);
ST_FUNC శూన్య save_regs(పూర్ణాంకం n);
ST_FUNC శూన్య gaddrof(శూన్య);
ST_FUNC పూర్ణాంకం gv(పూర్ణాంకం rc);
ST_FUNC శూన్య gv2(పూర్ణాంకం rc1, పూర్ణాంకం rc2);
ST_FUNC శూన్య gen_op(పూర్ణాంకం op);
ST_FUNC పూర్ణాంకం type_కొలత(CType *type, పూర్ణాంకం *a);
ST_FUNC శూన్య mk_సూచిక(CType *type);
ST_FUNC శూన్య vstore(శూన్య);
ST_FUNC శూన్య inc(పూర్ణాంకం post, పూర్ణాంకం c);
ST_FUNC CString* parse_mult_str(స్థిరరాశి అక్షరం *సందేశం);
ST_FUNC CString* parse_asm_str(శూన్య);
ST_FUNC శూన్య indir(శూన్య);
ST_FUNC శూన్య unary(శూన్య);
ST_FUNC శూన్య gexpr(శూన్య);
ST_FUNC పూర్ణాంకం సమాసం_const(శూన్య);
#ఒకవేళ defined CONFIG_TCC_BCHECK || defined TCC_లక్ష్యం_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, గుర్తులేని దీర్ఘ స్థానభ్రంశం, గుర్తులేని దీర్ఘ కొలత);
#అయితే_ముగింపు
#ఒకవేళ defined TCC_లక్ష్యం_X86_64 && !defined TCC_లక్ష్యం_PE
ST_FUNC పూర్ణాంకం classify_x86_64_va_arg(CType *ty);
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BCHECK
ST_FUNC శూన్య gbound_వాదనలు(పూర్ణాంకం nb_వాదనలు);
ST_దత్తాంశం పూర్ణాంకం func_bound_కూడు_epilog;
#అయితే_ముగింపు
ST_FUNC Sym *gfunc_సమితి_param(Sym *s, పూర్ణాంకం c, పూర్ణాంకం byref);

/* ------------ tccelf.c ------------ */

#నిర్వచించు TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#నిర్వచించు TCC_OUTPUT_FORMAT_ద్విమాన 1 /* binary image output */
#నిర్వచించు TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#నిర్వచించు TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#నిర్వచించు ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

రకనిర్వచనం నిర్మాణం {
    గుర్తులేని పూర్ణాంకం n_strx;         /* index into string table of name */
    గుర్తులేని అక్షరం n_type;         /* type of symbol */
    గుర్తులేని అక్షరం n_other;        /* misc info (usually empty) */
    గుర్తులేని పొట్టి n_desc;        /* description field */
    గుర్తులేని పూర్ణాంకం n_విలువ;        /* value of symbol */
} Stab_Sym;

ST_FUNC శూన్య tccelf_new(TCCState *s);
ST_FUNC శూన్య tccelf_delete(TCCState *s);
ST_FUNC శూన్య tccelf_begin_file(TCCState *s1);
ST_FUNC శూన్య tccelf_చివర_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, స్థిరరాశి అక్షరం *name, పూర్ణాంకం sh_type, పూర్ణాంకం sh_flags);
ST_FUNC శూన్య section_realloc(Section *sec, గుర్తులేని దీర్ఘ new_కొలత);
ST_FUNC కొలత_t section_కూడు(Section *sec, addr_t కొలత, పూర్ణాంకం align);
ST_FUNC శూన్య *section_ptr_కూడు(Section *sec, addr_t కొలత);
ST_FUNC Section *కనుగొను_section(TCCState *s1, స్థిరరాశి అక్షరం *name);
ST_FUNC శూన్య free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, స్థిరరాశి అక్షరం *symtab_name, పూర్ణాంకం sh_type, పూర్ణాంకం sh_flags, స్థిరరాశి అక్షరం *strtab_name, స్థిరరాశి అక్షరం *hash_name, పూర్ణాంకం hash_sh_flags);
ST_FUNC శూన్య init_symtab(Section *s);

ST_FUNC పూర్ణాంకం put_elf_str(Section *s, స్థిరరాశి అక్షరం *sym);
ST_FUNC పూర్ణాంకం put_elf_sym(Section *s, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత, పూర్ణాంకం info, పూర్ణాంకం other, పూర్ణాంకం shndx, స్థిరరాశి అక్షరం *name);
ST_FUNC పూర్ణాంకం సమితి_elf_sym(Section *s, addr_t విలువ, గుర్తులేని దీర్ఘ కొలత, పూర్ణాంకం info, పూర్ణాంకం other, పూర్ణాంకం shndx, స్థిరరాశి అక్షరం *name);
ST_FUNC పూర్ణాంకం కనుగొను_elf_sym(Section *s, స్థిరరాశి అక్షరం *name);
ST_FUNC శూన్య put_elf_reloc(Section *symtab, Section *s, గుర్తులేని దీర్ఘ స్థానభ్రంశం, పూర్ణాంకం type, పూర్ణాంకం చిహ్నం);
ST_FUNC శూన్య put_elf_reloca(Section *symtab, Section *s, గుర్తులేని దీర్ఘ స్థానభ్రంశం, పూర్ణాంకం type, పూర్ణాంకం చిహ్నం, addr_t addend);

ST_FUNC శూన్య resolve_common_syms(TCCState *s1);
ST_FUNC శూన్య relocate_syms(TCCState *s1, Section *symtab, పూర్ణాంకం do_resolve);
ST_FUNC శూన్య relocate_sections(TCCState *s1);

ST_FUNC ssize_t నిండిన_read(పూర్ణాంకం fd, శూన్య *buf, కొలత_t లెక్క_2);
ST_FUNC శూన్య *ఎక్కించు_దత్తాంశం(పూర్ణాంకం fd, గుర్తులేని దీర్ఘ file_స్థానభ్రంశం, గుర్తులేని దీర్ఘ కొలత);
ST_FUNC పూర్ణాంకం tcc_object_type(పూర్ణాంకం fd, ElfW(Ehdr) *h);
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_object_file(TCCState *s1, పూర్ణాంకం fd, గుర్తులేని దీర్ఘ file_స్థానభ్రంశం);
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_archive(TCCState *s1, పూర్ణాంకం fd, పూర్ణాంకం alacarte);
ST_FUNC శూన్య కూడు_array(TCCState *s1, స్థిరరాశి అక్షరం *sec, పూర్ణాంకం c);

ST_FUNC నిర్మాణం sym_attr *get_sym_attr(TCCState *s1, పూర్ణాంకం సూచీ, పూర్ణాంకం alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, స్థిరరాశి అక్షరం *name, పూర్ణాంకం err, పూర్ణాంకం forc);
ST_FUNC శూన్య list_elf_symbols(TCCState *s, శూన్య *ctx,
    శూన్య (*చిహ్నం_cb)(శూన్య *ctx, స్థిరరాశి అక్షరం *name, స్థిరరాశి శూన్య *val));
ST_FUNC పూర్ణాంకం సమితి_global_sym(TCCState *s1, స్థిరరాశి అక్షరం *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#నిర్వచించు for_each_elem(sec, startoff, elem, type) \
    కొరకు (elem = (type *) sec->దత్తాంశం + startoff; \
         elem < (type *) (sec->దత్తాంశం + sec->దత్తాంశం_స్థానభ్రంశం); elem++)

#నిర్వచితం_కాకపోతే ELF_OBJ_ONLY
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_dll(TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం level);
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_ldscript(TCCState *s1, పూర్ణాంకం fd);
ST_FUNC శూన్య tccelf_కూడు_crtbegin(TCCState *s1);
ST_FUNC శూన్య tccelf_కూడు_crtend(TCCState *s1);
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
ST_FUNC శూన్య tcc_కూడు_runtime(TCCState *s1);
#అయితే_ముగింపు

/* ------------ xxx-link.c ------------ */

#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_PE
ST_FUNC పూర్ణాంకం సంకేతం_reloc (పూర్ణాంకం reloc_type);
ST_FUNC పూర్ణాంకం gotplt_నమోదు_type (పూర్ణాంకం reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
గణన gotplt_నమోదు {
    NO_GOTPLT_నమోదు,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_నమోదు,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_నమోదు	/* always generate (eg. PLTOFF relocs) */
};
#నిర్వచించు NEED_RELOC_TYPE
#ఒకవేళ !defined TCC_లక్ష్యం_MACHO || defined TCC_IS_NATIVE
ST_FUNC గుర్తులేని create_plt_నమోదు(TCCState *s1, గుర్తులేని got_స్థానభ్రంశం, నిర్మాణం sym_attr *attr);
ST_FUNC శూన్య relocate_plt(TCCState *s1);
ST_FUNC శూన్య build_got_entries(TCCState *s1, పూర్ణాంకం got_sym); /* in tccelf.c */
#నిర్వచించు NEED_BUILD_GOT
#అయితే_ముగింపు
#అయితే_ముగింపు

ST_FUNC శూన్య relocate(TCCState *s1, ElfW_Rel *rel, పూర్ణాంకం type, గుర్తులేని అక్షరం *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_దత్తాంశం స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_machine_defs;
ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం reg_classes[NB_REGS];

ST_FUNC శూన్య gsym_addr(పూర్ణాంకం t, పూర్ణాంకం a);
ST_FUNC శూన్య gsym(పూర్ణాంకం t);
ST_FUNC శూన్య ఎక్కించు(పూర్ణాంకం r, SValue *sv);
ST_FUNC శూన్య store(పూర్ణాంకం r, SValue *v);
ST_FUNC పూర్ణాంకం gfunc_sret(CType *vt, పూర్ణాంకం variadic, CType *ret, పూర్ణాంకం *align, పూర్ణాంకం *regsize);
ST_FUNC శూన్య gfunc_call(పూర్ణాంకం nb_వాదనలు);
ST_FUNC శూన్య gfunc_prolog(Sym *func_sym);
ST_FUNC శూన్య gfunc_epilog(శూన్య);
ST_FUNC శూన్య gen_fill_nops(పూర్ణాంకం);
ST_FUNC పూర్ణాంకం gjmp(పూర్ణాంకం t);
ST_FUNC శూన్య gjmp_addr(పూర్ణాంకం a);
ST_FUNC పూర్ణాంకం gjmp_cond(పూర్ణాంకం op, పూర్ణాంకం t);
ST_FUNC పూర్ణాంకం gjmp_append(పూర్ణాంకం n, పూర్ణాంకం t);
ST_FUNC శూన్య gen_opi(పూర్ణాంకం op);
ST_FUNC శూన్య gen_opf(పూర్ణాంకం op);
ST_FUNC శూన్య gen_cvt_ftoi(పూర్ణాంకం t);
ST_FUNC శూన్య gen_cvt_itof(పూర్ణాంకం t);
ST_FUNC శూన్య gen_cvt_ftof(పూర్ణాంకం t);
ST_FUNC శూన్య ggoto(శూన్య);
#నిర్వచితం_కాకపోతే TCC_లక్ష్యం_C67
ST_FUNC శూన్య o(గుర్తులేని పూర్ణాంకం c);
#అయితే_ముగింపు
ST_FUNC శూన్య gen_vla_sp_save(పూర్ణాంకం addr);
ST_FUNC శూన్య gen_vla_sp_restore(పూర్ణాంకం addr);
ST_FUNC శూన్య gen_vla_alloc(CType *type, పూర్ణాంకం align);

స్థిర అంతఃవరుస uint16_t read16le(గుర్తులేని అక్షరం *p) {
    తిరిగి p[0] | (uint16_t)p[1] << 8;
}
స్థిర అంతఃవరుస శూన్య write16le(గుర్తులేని అక్షరం *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
స్థిర అంతఃవరుస uint32_t read32le(గుర్తులేని అక్షరం *p) {
  తిరిగి read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
స్థిర అంతఃవరుస శూన్య write32le(గుర్తులేని అక్షరం *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
స్థిర అంతఃవరుస శూన్య add32le(గుర్తులేని అక్షరం *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
స్థిర అంతఃవరుస uint64_t read64le(గుర్తులేని అక్షరం *p) {
  తిరిగి read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
స్థిర అంతఃవరుస శూన్య write64le(గుర్తులేని అక్షరం *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
స్థిర అంతఃవరుస శూన్య add64le(గుర్తులేని అక్షరం *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#ఒకవేళ defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64 || defined TCC_లక్ష్యం_ARM
ST_FUNC శూన్య g(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le16(పూర్ణాంకం c);
ST_FUNC శూన్య gen_le32(పూర్ణాంకం c);
#అయితే_ముగింపు
#ఒకవేళ defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64
ST_FUNC శూన్య gen_addr32(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c);
ST_FUNC శూన్య gen_addrpc32(పూర్ణాంకం r, Sym *sym, పూర్ణాంకం c);
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t);
ST_FUNC శూన్య gen_increment_tcov (SValue *sv);
#అయితే_ముగింపు

/* ------------ x86_64-gen.c ------------ */
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
ST_FUNC శూన్య gen_opl(పూర్ణాంకం op);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
ST_FUNC శూన్య gen_vla_ఫలితం(పూర్ణాంకం addr);
#అయితే_ముగింపు
ST_FUNC శూన్య gen_cvt_sxtw(శూన్య);
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t);
#అయితే_ముగింపు

/* ------------ arm-gen.c ------------ */
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
#ఒకవేళ defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC స్థిరరాశి అక్షరం *default_elfinterp(నిర్మాణం TCCState *s);
#అయితే_ముగింపు
ST_FUNC శూన్య arm_init(నిర్మాణం TCCState *s);
ST_FUNC శూన్య gen_increment_tcov (SValue *sv);
#అయితే_ముగింపు

/* ------------ arm64-gen.c ------------ */
#నిర్వచితమైతే TCC_లక్ష్యం_ARM64
ST_FUNC శూన్య gen_opl(పూర్ణాంకం op);
ST_FUNC శూన్య gfunc_return(CType *func_type);
ST_FUNC శూన్య gen_va_ప్రారంభం(శూన్య);
ST_FUNC శూన్య gen_va_arg(CType *t);
ST_FUNC శూన్య gen_clear_cache(శూన్య);
ST_FUNC శూన్య gen_cvt_sxtw(శూన్య);
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t);
ST_FUNC శూన్య gen_increment_tcov (SValue *sv);
#అయితే_ముగింపు

/* ------------ riscv64-gen.c ------------ */
#నిర్వచితమైతే TCC_లక్ష్యం_RISCV64
ST_FUNC శూన్య gen_opl(పూర్ణాంకం op);
ST_FUNC శూన్య gen_va_ప్రారంభం(శూన్య);
ST_FUNC శూన్య arch_transfer_ret_regs(పూర్ణాంకం);
ST_FUNC శూన్య gen_cvt_sxtw(శూన్య);
ST_FUNC శూన్య gen_cvt_csti(పూర్ణాంకం t);
ST_FUNC శూన్య gen_increment_tcov (SValue *sv);
ST_FUNC శూన్య gen_clear_cache(శూన్య);
#అయితే_ముగింపు

/* ------------ c67-gen.c ------------ */
#నిర్వచితమైతే TCC_లక్ష్యం_C67
#అయితే_ముగింపు

/* ------------ tcccoff.c ------------ */
#నిర్వచితమైతే TCC_లక్ష్యం_COFF
ST_FUNC పూర్ణాంకం tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC పూర్ణాంకం tcc_ఎక్కించు_coff(TCCState * s1, పూర్ణాంకం fd);
#అయితే_ముగింపు

/* ------------ tccasm.c ------------ */
ST_FUNC శూన్య asm_instr(శూన్య);
ST_FUNC శూన్య asm_global_instr(శూన్య);
ST_FUNC పూర్ణాంకం tcc_assemble(TCCState *s1, పూర్ణాంకం do_preprocess);
#నిర్వచితమైతే CONFIG_TCC_ASM
ST_FUNC పూర్ణాంకం కనుగొను_constraint(ASMOperand *operands, పూర్ణాంకం nb_operands, స్థిరరాశి అక్షరం *name, స్థిరరాశి అక్షరం **pp);
ST_FUNC Sym* get_asm_sym(పూర్ణాంకం name, Sym *csym);
ST_FUNC శూన్య asm_సమాసం(TCCState *s1, సమాసం_విలువ *pe);
ST_FUNC పూర్ణాంకం asm_int_సమాసం(TCCState *s1);
#ఒకవేళ PTR_కొలత == 8
ST_FUNC శూన్య gen_expr64(సమాసం_విలువ *pe);
#అయితే_ముగింపు
/* ------------ i386-asm.c ------------ */
ST_FUNC శూన్య gen_expr32(సమాసం_విలువ *pe);
ST_FUNC శూన్య asm_opcode(TCCState *s1, పూర్ణాంకం opcode);
ST_FUNC పూర్ణాంకం asm_parse_regvar(పూర్ణాంకం t);
ST_FUNC శూన్య asm_compute_constraints(ASMOperand *operands, పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs, స్థిరరాశి uint8_t *clobber_regs, పూర్ణాంకం *pout_reg);
ST_FUNC శూన్య subst_asm_నిర్వాహ్యం(CString *కూడు_str, SValue *sv, పూర్ణాంకం modifier);
ST_FUNC శూన్య asm_gen_సంకేతం(ASMOperand *operands, పూర్ణాంకం nb_operands, పూర్ణాంకం nb_outputs, పూర్ణాంకం is_output, uint8_t *clobber_regs, పూర్ణాంకం బహిర్గతం_reg);
ST_FUNC శూన్య asm_clobber(uint8_t *clobber_regs, స్థిరరాశి అక్షరం *str);
#అయితే_ముగింపు

/* ------------ tccpe.c -------------- */
#నిర్వచితమైతే TCC_లక్ష్యం_PE
ST_FUNC పూర్ణాంకం pe_ఎక్కించు_file(నిర్మాణం TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename);
ST_FUNC పూర్ణాంకం pe_output_file(TCCState * s1, స్థిరరాశి అక్షరం *filename);
ST_FUNC పూర్ణాంకం pe_putimport(TCCState *s1, పూర్ణాంకం dllindex, స్థిరరాశి అక్షరం *name, addr_t విలువ);
ST_FUNC పూర్ణాంకం pe_setsubsy(TCCState *s1, స్థిరరాశి అక్షరం *arg);
#ఒకవేళ defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64
#అయితే_ముగింపు
#ఒకవేళ defined(TCC_లక్ష్యం_X86_64) || defined(TCC_లక్ష్యం_ARM64)
ST_FUNC శూన్య pe_కూడు_unwind_దత్తాంశం(గుర్తులేని ప్రారంభం, గుర్తులేని చివర, గుర్తులేని దొంతర);
#అయితే_ముగింపు
PUB_FUNC పూర్ణాంకం tcc_get_dllexports(స్థిరరాశి అక్షరం *filename, అక్షరం **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#అయితే_ముగింపు
#నిర్వచించు ST_ASM_సమితి 0x04

/* ------------ tccmacho.c ----------------- */
#నిర్వచితమైతే TCC_లక్ష్యం_MACHO
ST_FUNC పూర్ణాంకం macho_output_file(TCCState * s1, స్థిరరాశి అక్షరం *filename);
ST_FUNC పూర్ణాంకం macho_ఎక్కించు_dll(TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం lev);
ST_FUNC పూర్ణాంకం macho_ఎక్కించు_tbd(TCCState *s1, పూర్ణాంకం fd, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం lev);
#నిర్వచితమైతే TCC_IS_NATIVE
ST_FUNC శూన్య tcc_కూడు_macos_sdkpath(TCCState* s);
ST_FUNC అక్షరం* macho_tbd_soname(పూర్ణాంకం fd);
#అయితే_ముగింపు
#అయితే_ముగింపు
/* ------------ tccrun.c ----------------- */
#నిర్వచితమైతే TCC_IS_NATIVE
#నిర్వచితమైతే CONFIG_TCC_STATIC
#నిర్వచించు RTLD_LAZY       0x001
#నిర్వచించు RTLD_NOW        0x002
#నిర్వచించు RTLD_GLOBAL     0x100
#నిర్వచించు RTLD_DEFAULT    ఖాళీ
/* dummy function for profiling */
ST_FUNC శూన్య *dlopen(స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flag);
ST_FUNC శూన్య dlclose(శూన్య *p);
ST_FUNC స్థిరరాశి అక్షరం *dlerror(శూన్య);
ST_FUNC శూన్య *dlsym(శూన్య *handle, స్థిరరాశి అక్షరం *చిహ్నం);
#అయితే_ముగింపు
ST_FUNC శూన్య tcc_నిరంతరం_free(TCCState *s1);
#అయితే_ముగింపు

/* ------------ tcctools.c ----------------- */
#ఒకవేళ 0 /* included in tcc.c */
ST_FUNC పూర్ణాంకం tcc_tool_ar(TCCState *s, పూర్ణాంకం argc, అక్షరం **argv);
#నిర్వచితమైతే TCC_లక్ష్యం_PE
ST_FUNC పూర్ణాంకం tcc_tool_impdef(TCCState *s, పూర్ణాంకం argc, అక్షరం **argv);
#అయితే_ముగింపు
ST_FUNC పూర్ణాంకం tcc_tool_cross(TCCState *s, అక్షరం **argv, పూర్ణాంకం option);
ST_FUNC పూర్ణాంకం gen_makedeps(TCCState *s, స్థిరరాశి అక్షరం *లక్ష్యం, స్థిరరాశి అక్షరం *filename);
#అయితే_ముగింపు

/* ------------ tccdbg.c ------------ */

ST_FUNC శూన్య tcc_debug_new(TCCState *s);

ST_FUNC శూన్య tcc_debug_ప్రారంభం(TCCState *s1);
ST_FUNC శూన్య tcc_debug_చివర(TCCState *s1);
ST_FUNC శూన్య tcc_debug_bincl(TCCState *s1);
ST_FUNC శూన్య tcc_debug_eincl(TCCState *s1);
ST_FUNC శూన్య tcc_debug_newfile(TCCState *s1);

ST_FUNC శూన్య tcc_debug_పంక్తి(TCCState *s1);
ST_FUNC శూన్య tcc_కూడు_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC శూన్య tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC శూన్య tcc_debug_prolog_epilog(TCCState *s1, పూర్ణాంకం విలువ);
ST_FUNC శూన్య tcc_debug_funcend(TCCState *s1, పూర్ణాంకం కొలత);
ST_FUNC శూన్య tcc_debug_extern_sym(TCCState *s1, Sym *sym, పూర్ణాంకం sh_అంకె, పూర్ణాంకం sym_bind, పూర్ణాంకం sym_type);
ST_FUNC శూన్య tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC శూన్య tcc_debug_stabn(TCCState *s1, పూర్ణాంకం type, పూర్ణాంకం విలువ);
ST_FUNC శూన్య tcc_debug_fix_forw(TCCState *s1, CType *t);

#ఒకవేళ !(defined ELF_OBJ_ONLY || defined TCC_లక్ష్యం_ARM || defined TARGETOS_BSD)
ST_FUNC శూన్య tcc_eh_చట్రం_ప్రారంభం(TCCState *s1);
ST_FUNC శూన్య tcc_eh_చట్రం_చివర(TCCState *s1);
ST_FUNC శూన్య tcc_eh_చట్రం_hdr(TCCState *s1, పూర్ణాంకం final);
#నిర్వచించు TCC_EH_చట్రం 1
#అయితే_ముగింపు

ST_FUNC శూన్య tcc_tcov_ప్రారంభం(TCCState *s1);
ST_FUNC శూన్య tcc_tcov_చివర(TCCState *s1);
ST_FUNC శూన్య tcc_tcov_check_పంక్తి(TCCState *s1, పూర్ణాంకం ప్రారంభం);
ST_FUNC శూన్య tcc_tcov_ఖండం_చివర(TCCState *s1, పూర్ణాంకం పంక్తి);
ST_FUNC శూన్య tcc_tcov_ఖండం_begin(TCCState *s1);
ST_FUNC శూన్య tcc_tcov_reset_ind(TCCState *s1);

#నిర్వచించు stab_section            s1->stab_section
#నిర్వచించు stabstr_section         stab_section->link
#నిర్వచించు tcov_section            s1->tcov_section
#నిర్వచించు eh_చట్రం_section        s1->eh_చట్రం_section
#నిర్వచించు eh_చట్రం_hdr_section    s1->eh_చట్రం_hdr_section
#నిర్వచించు dwarf_info_section      s1->dwarf_info_section
#నిర్వచించు dwarf_abbrev_section    s1->dwarf_abbrev_section
#నిర్వచించు dwarf_పంక్తి_section      s1->dwarf_పంక్తి_section
#నిర్వచించు dwarf_aranges_section   s1->dwarf_aranges_section
#నిర్వచించు dwarf_str_section       s1->dwarf_str_section
#నిర్వచించు dwarf_పంక్తి_str_section  s1->dwarf_పంక్తి_str_section

#నిర్వచించు DWARF_MAX_128	((8 * పరిమాణం (int64_t) + 6) / 7)
#నిర్వచించు	dwarf_read_1(ln,చివర) \
	((ln) < (చివర) ? *(ln)++ : 0)
#నిర్వచించు	dwarf_read_2(ln,చివర) \
	((ln) + 1 < (చివర) ? read16le(((ln)+=2) - 2) : 0)
#నిర్వచించు	dwarf_read_4(ln,చివర) \
	((ln) + 3 < (చివర) ? read32le(((ln)+=4) - 4) : 0)
#నిర్వచించు	dwarf_read_8(ln,చివర) \
	((ln) + 7 < (చివర) ? read64le(((ln)+=8) - 8) : 0)
స్థిర అంతఃవరుస uint64_t
dwarf_read_uleb128(గుర్తులేని అక్షరం **ln, గుర్తులేని అక్షరం *చివర)
{
    గుర్తులేని అక్షరం *cp = *ln;
    uint64_t retval = 0;
    పూర్ణాంకం i;
    కొరకు (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, చివర);
        retval |= (byte & 0x7f) << (i * 7);
	ఒకవేళ ((byte & 0x80) == 0)
	    ఆపు;
    }
    *ln = cp;
    తిరిగి retval;
}
స్థిర అంతఃవరుస int64_t
dwarf_read_sleb128(గుర్తులేని అక్షరం **ln, గుర్తులేని అక్షరం *చివర)
{
    గుర్తులేని అక్షరం *cp = *ln;
    int64_t retval = 0;
    పూర్ణాంకం i;
    కొరకు (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, చివర);
        retval |= (byte & 0x7f) << (i * 7);
	ఒకవేళ ((byte & 0x80) == 0) {
	    ఒకవేళ ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    ఆపు;
	}
    }
    *ln = cp;
    తిరిగి retval;
}

/* default dwarf version for "-gdwarf" */
#నిర్వచితమైతే TCC_లక్ష్యం_MACHO
# define DEFAULT_DWARF_సంస్కరణ 2
#లేకపోతే
# define DEFAULT_DWARF_సంస్కరణ 5
#అయితే_ముగింపు

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#నిర్వచితం_కాకపోతే CONFIG_DWARF_సంస్కరణ
# define CONFIG_DWARF_సంస్కరణ 0
#అయితే_ముగింపు

#ఒకవేళ defined TCC_లక్ష్యం_X86_64
# define R_దత్తాంశం_32_DW R_X86_64_32
#లేకపోతే
# define R_దత్తాంశం_32_DW R_దత్తాంశం_32
#అయితే_ముగింపు

/********************************************************/
#ఒకవేళ CONFIG_TCC_SEMLOCK
#ఒకవేళ defined _WIN32
రకనిర్వచనం నిర్మాణం { అస్థిర LONG init; CRITICAL_SECTION cs; } TCCSem;
స్థిర అంతఃవరుస శూన్య wait_sem(TCCSem *p) {
    ఒకవేళ (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } లేకపోతే {
        అయితే (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
స్థిర అంతఃవరుస శూన్య post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#లేదావేళ defined __APPLE__
#అన్తర్భావ <dispatch/dispatch.h>
రకనిర్వచనం నిర్మాణం { పూర్ణాంకం init; dispatch_semaphore_t sem; } TCCSem;
స్థిర అంతఃవరుస శూన్య wait_sem(TCCSem *p) {
    ఒకవేళ (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_సమయం_FOREVER);
}
స్థిర అంతఃవరుస శూన్య post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#లేకపోతే
#అన్తర్భావ <semaphore.h>
రకనిర్వచనం నిర్మాణం { పూర్ణాంకం init; sem_t sem; } TCCSem;
స్థిర అంతఃవరుస శూన్య wait_sem(TCCSem *p) {
    ఒకవేళ (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    అయితే (sem_wait(&p->sem) < 0 && errno == EINTR);
}
స్థిర అంతఃవరుస శూన్య post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#అయితే_ముగింపు
#నిర్వచించు TCC_SEM(s) TCCSem s
#నిర్వచించు WAIT_SEM wait_sem
#నిర్వచించు POST_SEM post_sem
#లేకపోతే
#నిర్వచించు TCC_SEM(s)
#నిర్వచించు WAIT_SEM(p)
#నిర్వచించు POST_SEM(p)
#అయితే_ముగింపు

/********************************************************/
#నిర్వచనం_రద్దు ST_దత్తాంశం
#ఒకవేళ ONE_ఆధారం
#నిర్వచించు ST_దత్తాంశం స్థిర
#లేకపోతే
#నిర్వచించు ST_దత్తాంశం
#అయితే_ముగింపు
/********************************************************/

#నిర్వచించు పాఠ్యం_section        TCC_STATE_VAR(పాఠ్యం_section)
#నిర్వచించు దత్తాంశం_section        TCC_STATE_VAR(దత్తాంశం_section)
#నిర్వచించు rodata_section      TCC_STATE_VAR(rodata_section)
#నిర్వచించు bss_section         TCC_STATE_VAR(bss_section)
#నిర్వచించు common_section      TCC_STATE_VAR(common_section)
#నిర్వచించు cur_పాఠ్యం_section    TCC_STATE_VAR(cur_పాఠ్యం_section)
#నిర్వచించు bounds_section      TCC_STATE_VAR(bounds_section)
#నిర్వచించు lbounds_section     TCC_STATE_VAR(lbounds_section)
#నిర్వచించు symtab_section      TCC_STATE_VAR(symtab_section)
#నిర్వచించు gnu_ext             TCC_STATE_VAR(gnu_ext)
#నిర్వచించు tcc_error_noabort   TCC_సమితి_STATE(_tcc_error_noabort)
#నిర్వచించు tcc_error           TCC_సమితి_STATE(_tcc_error)
#నిర్వచించు tcc_warning         TCC_సమితి_STATE(_tcc_warning)

#నిర్వచించు మొత్తం_idents        TCC_STATE_VAR(మొత్తం_idents)
#నిర్వచించు మొత్తం_పంక్తులు         TCC_STATE_VAR(మొత్తం_పంక్తులు)
#నిర్వచించు మొత్తం_బైట్లు         TCC_STATE_VAR(మొత్తం_బైట్లు)

PUB_FUNC శూన్య tcc_enter_state(TCCState *s1);
PUB_FUNC శూన్య tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#నిర్వచించు tcc_warning_c(sw) TCC_సమితి_STATE((\
    tcc_state->warn_అంకె = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#అయితే_ముగింపు /* _TCC_H */

#నిర్వచనం_రద్దు TCC_STATE_VAR
#నిర్వచనం_రద్దు TCC_సమితి_STATE

#నిర్వచితమైతే USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_సమితి_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#లేకపోతే
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_సమితి_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#అయితే_ముగింపు
