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

#ifndef _TCC_H
#define _TCC_H

#define _GNU_SOURCE
#define _DARWIN_C_SOURCE
#ಅನ್ತರ್ಭಾವ "config.h"

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ತರ್ಭಾವ <math.h>
#ಅನ್ತರ್ಭಾವ <fcntl.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>
#ಅನ್ತರ್ಭಾವ <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
ಬಾಹ್ಯ ಭಿನ್ನ strtof (ಧ್ರುವ ವರ್ಣ *__nptr, ವರ್ಣ **__endptr);
ಬಾಹ್ಯ long ದ್ವಿಗುಣ strtold (ಧ್ರುವ ವರ್ಣ *__nptr, ವರ್ಣ **__endptr);
#endif

#ifdef _WIN32
# define WIN32_LEAN_AND_MEAN 1
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
# define ಅನ್ತಃಸ್ಥ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long ದ್ವಿಗುಣ)strtod
#  define strtof (ಭಿನ್ನ)strtod
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
# ಯದಿ defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_ದ್ವಿಮಾನ_2
# define O_ದ್ವಿಮಾನ_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#ಅನ್ಯಥಾ
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (ಪರಿಮಾಣ(tab) / ಪರಿಮಾಣ((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#ಅನ್ಯಥಾ
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#ಅನ್ಯಥಾ
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#endif

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
#ಯದಿ !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# ಯದಿ defined __x86_64__
#  define TCC_TARGET_X86_64
# elif defined __arm__
#  define TCC_TARGET_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_TARGET_ARM64
# elif defined __riscv
#  define TCC_TARGET_RISCV64
# ಅನ್ಯಥಾ
#  define TCC_TARGET_I386
# endif
# ifdef _WIN32
#  define TCC_TARGET_PE 1
# endif
# ifdef __APPLE__
#  define TCC_TARGET_MACHO 1
# endif
#endif

/* only native compiler supports -run */
#ಯದಿ defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# ಯದಿ defined __i386__ && defined TCC_TARGET_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_TARGET_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_TARGET_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_TARGET_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_TARGET_RISCV64
#  define TCC_IS_NATIVE
# endif
#endif

#ಯದಿ defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#ಅನ್ಯಥಾ
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#ಯದಿ defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#ಅನ್ಯಥಾ
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#ಯದಿ defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#ಅನ್ಯಥಾ
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#ಯದಿ defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#ನೋಚೇದ್ಯದಿ !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#ಯದಿ defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#ಅನ್ಯಥಾ
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#ಯದಿ defined TCC_TARGET_PE \
    || (defined TCC_TARGET_MACHO && defined TCC_TARGET_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#endif

#ifdef CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#endif

/* support using libtcc from threads */
#ifndef CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#endif

/* ------------ path configuration ------------ */

#ifndef CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#endif

#ಯದಿ !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#ಅನ್ಯಥಾ
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#endif

/* path to find crt1.o, crti.o and crtn.o */
#ifndef CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#endif

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#ifndef CONFIG_TCC_SYSINCLUDEPATHS
# ಯದಿ defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# ಅನ್ಯಥಾ
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# ಯದಿ defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# ಅನ್ಯಥಾ
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# ಯದಿ defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_TARGET_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_TARGET_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_TARGET_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_TARGET_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_TARGET_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# ಅನ್ಯಥಾ
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#endif

/* (target specific) libtcc1.a */
#ifndef TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#endif

/* <cross-prefix-to->libtcc1.a */
#ifndef CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#endif

/* -------------------------------------------- */

#ಅನ್ತರ್ಭಾವ "libtcc.h"
#ಅನ್ತರ್ಭಾವ "elf.h"
#ಅನ್ತರ್ಭಾವ "stab.h"
#ಅನ್ತರ್ಭಾವ "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#ಯದಿ ONE_SOURCE
#define ST_INLN ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ
#define ST_FUNC ಸ್ಥಿರ
#define ST_DATA ಸ್ಥಿರ
#ಅನ್ಯಥಾ
#define ST_INLN
#define ST_FUNC
#define ST_DATA ಬಾಹ್ಯ
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define ಸ್ಥಿರ
# define ಅನ್ತಃಸ್ಥ
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#ಅನ್ಯಥಾ
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#ಯದಿ PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#ಅನ್ಯಥಾ
# define ELFCLASSW ELFCLASS32
# define ElfW(type) Elf##32##_##type
# define ELFW(type) ELF##32##_##type
# define ElfW_Rel ElfW(Rel)
# define SHT_RELX SHT_REL
# define REL_SECTION_FMT ".rel%s"
#endif
/* target address type */
#define addr_t ElfW(Addr)
#define ElfSym ElfW(Sym)

#ಯದಿ PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#ಅನ್ಯಥಾ
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_ರಾಶಿ_SIZE  32
#define IFDEF_ರಾಶಿ_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_ರಾಶಿ_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ TokenSym {
    ಸಂರಚನಾ TokenSym *hash_next;
    ಸಂರಚನಾ Sym *sym_define; /* direct pointer to define */
    ಸಂರಚನಾ Sym *sym_label; /* direct pointer to label */
    ಸಂರಚನಾ Sym *sym_struct; /* direct pointer to structure */
    ಸಂರಚನಾ Sym *sym_identifier; /* direct pointer to identifier */
    ಪೂರ್ಣಾಙ್ಕ tok; /* token number */
    ಪೂರ್ಣಾಙ್ಕ len;
    ವರ್ಣ str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short nwchar_t;
#ಅನ್ಯಥಾ
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ nwchar_t;
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ CString {
    ಪೂರ್ಣಾಙ್ಕ size; /* size in bytes */
    ಪೂರ್ಣಾಙ್ಕ size_allocated;
    ವರ್ಣ *data; /* nwchar_t* in cases */
} CString;

/* type definition */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ CType {
    ಪೂರ್ಣಾಙ್ಕ t;
    ಸಂರಚನಾ Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_ಪದಗಳು ((ಪರಿಮಾಣ(long ದ್ವಿಗುಣ)+3)/4)

/* constant value */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ CValue {
    long ದ್ವಿಗುಣ ld;
    ದ್ವಿಗುಣ d;
    ಭಿನ್ನ f;
    uint64_t i;
    ಸಂರಚನಾ {
        ವರ್ಣ *data;
        ಪೂರ್ಣಾಙ್ಕ size;
    } str;
    ಪೂರ್ಣಾಙ್ಕ tab[LDOUBLE_ಪದಗಳು];
} CValue;

/* value on stack */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    ಸಙ್ಘ {
      ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    ಸಙ್ಘ {
      ಸಂರಚನಾ { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      ಸಂರಚನಾ Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ಸಂರಚನಾ SymAttr {
    unsigned short
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
ಸಂರಚನಾ FuncAttr {
    unsigned
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_args   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Sym {
    ಪೂರ್ಣಾಙ್ಕ v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ಸಂರಚನಾ SymAttr a; /* symbol attributes */
    ಸಙ್ಘ {
        ಸಂರಚನಾ {
            ಪೂರ್ಣಾಙ್ಕ c; /* associated number or Elf symbol index */
            ಸಙ್ಘ {
                ಪೂರ್ಣಾಙ್ಕ sym_scope; /* scope level for locals */
                ಪೂರ್ಣಾಙ್ಕ jnext; /* next jump label */
                ಪೂರ್ಣಾಙ್ಕ jind; /* label position */
                ಸಂರಚನಾ FuncAttr f; /* function attributes */
                ಪೂರ್ಣಾಙ್ಕ auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        ಪೂರ್ಣಾಙ್ಕ *d; /* define token stream */
        ಸಂರಚನಾ Sym *cleanup_func;
    };

    CType type; /* associated type */
    ಸಙ್ಘ {
        ಸಂರಚನಾ Sym *next; /* next related symbol (for fields and anoms) */
        ಪೂರ್ಣಾಙ್ಕ *e; /* expanded token stream with preprocessor macros */
        ಪೂರ್ಣಾಙ್ಕ asm_label; /* associated asm label */
        ಸಂರಚನಾ Sym *cleanupstate; /* in defined labels */
        ಪೂರ್ಣಾಙ್ಕ *vla_array_str; /* vla array code */
    };
    ಸಂರಚನಾ Sym *prev; /* prev symbol in stack */
    ಸಙ್ಘ {
        ಸಂರಚನಾ Sym *prev_tok; /* previous symbol for this token */
        ಸಂರಚನಾ Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ಸಂರಚನಾ Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Section {
    unsigned long data_offset; /* current data offset */
    unsigned ವರ್ಣ *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    ಪೂರ್ಣಾಙ್ಕ sh_name;             /* elf section name (only used during output) */
    ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ;              /* elf section number */
    ಪೂರ್ಣಾಙ್ಕ sh_type;             /* elf section type */
    ಪೂರ್ಣಾಙ್ಕ sh_flags;            /* elf section flags */
    ಪೂರ್ಣಾಙ್ಕ sh_info;             /* elf section info */
    ಪೂರ್ಣಾಙ್ಕ sh_addralign;        /* elf section alignment */
    ಪೂರ್ಣಾಙ್ಕ sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    ಪೂರ್ಣಾಙ್ಕ nb_hashed_syms;      /* used to resize the hash table */
    ಸಂರಚನಾ Section *link;    /* link to another section */
    ಸಂರಚನಾ Section *reloc;   /* corresponding section for relocation, if any */
    ಸಂರಚನಾ Section *hash;    /* hash table for symbols */
    ಸಂರಚನಾ Section *prev;    /* previous section on section stack */
    ವರ್ಣ name[1];           /* section name */
} Section;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ DLLReference {
    ಪೂರ್ಣಾಙ್ಕ level;
    ಶೂನ್ಯ *handle;
    unsigned ವರ್ಣ found, index;
    ವರ್ಣ name[1];
} DLLReference;

/* -------------------------------------------------- */

#define SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#define SYM_FIELD      0x20000000 /* struct/union field symbol space */
#define SYM_FIRST_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#define FUNC_NEW       1 /* ansi function prototype */
#define FUNC_OLD       2 /* old function prototype */
#define FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#define FUNC_CDECL     0 /* standard c call */
#define FUNC_STDCALL   1 /* pascal c call */
#define FUNC_FASTCALL1 2 /* first param in %eax */
#define FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#define FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#define FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#define FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#define MACRO_OBJ      0 /* object like macro */
#define MACRO_FUNC     1 /* function like macro */
#define MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#define LABEL_DEFINED  0 /* label is defined */
#define LABEL_FORWARD  1 /* label is forward defined */
#define LABEL_DECLARED 2 /* label is declared but never used */
#define LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#define TYPE_ABSTRACT  1 /* type without variable */
#define TYPE_DIRECT    2 /* type with variable */
#define TYPE_PARAM     4 /* type declares function parameter */
#define TYPE_NEST      8 /* nested call to post_type */

#define IO_BUF_SIZE 8192

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    ಪೂರ್ಣಾಙ್ಕ fd;
    ಸಂರಚನಾ BufferedFile *prev;
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_ಅಂಕೆ;    /* current line number - here to simplify code */
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_ref;    /* tcc -E: last printed line */
    ಪೂರ್ಣಾಙ್ಕ ifndef_macro;  /* #ifndef macro / #endif search */
    ಪೂರ್ಣಾಙ್ಕ ifndef_macro_saved; /* saved ifndef_macro */
    ಪೂರ್ಣಾಙ್ಕ *ifdef_ರಾಶಿ_ptr; /* ifdef_stack value at the start of the file */
    ಪೂರ್ಣಾಙ್ಕ include_next_index; /* next search path */
    ಪೂರ್ಣಾಙ್ಕ prev_tok_flags; /* saved tok_flags */
    ವರ್ಣ filename[1024];    /* filename */
    ವರ್ಣ *true_filename; /* filename not modified by # line directive */
    unsigned ವರ್ಣ unget[4];
    unsigned ವರ್ಣ buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ TokenString {
    ಪೂರ್ಣಾಙ್ಕ *str;
    ಪೂರ್ಣಾಙ್ಕ len;
    ಪೂರ್ಣಾಙ್ಕ need_spc;
    ಪೂರ್ಣಾಙ್ಕ allocated_len;
    ಪೂರ್ಣಾಙ್ಕ last_ಸಾಲು_ಅಂಕೆ;
    ಪೂರ್ಣಾಙ್ಕ save_ಸಾಲು_ಅಂಕೆ;
    /* used to chain token-strings with begin/end_macro() */
    ಸಂರಚನಾ TokenString *prev;
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *prev_ptr;
    ವರ್ಣ alloc;
} TokenString;

/* GNUC attribute definition */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ AttributeDef {
    ಸಂರಚನಾ SymAttr a;
    ಸಂರಚನಾ FuncAttr f;
    ಸಂರಚನಾ Section *section;
    Sym *cleanup_func;
    ಪೂರ್ಣಾಙ್ಕ alias_target; /* token */
    ಪೂರ್ಣಾಙ್ಕ asm_label; /* associated asm label */
    ವರ್ಣ attr_mode; /* __attribute__((__mode__(...))) */
    ವರ್ಣ new_section; /* section is new */
} AttributeDef;

/* inline functions */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ InlineFunc {
    TokenString *func_str;
    Sym *sym;
    ವರ್ಣ filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ CachedInclude {
    ಪೂರ್ಣಾಙ್ಕ ifndef_macro;
    ಪೂರ್ಣಾಙ್ಕ once;
    ಪೂರ್ಣಾಙ್ಕ hash_next; /* -1 if none */
    ವರ್ಣ filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ {
    uint64_t v;
    Sym *sym;
    ಪೂರ್ಣಾಙ್ಕ pcrel;
} ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ;

#define MAX_ASM_OPERANDS 30
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ASMOperand {
    ಪೂರ್ಣಾಙ್ಕ id; /* GCC 3 optional identifier (0 if number only supported) */
    ವರ್ಣ constraint[16];
    ವರ್ಣ asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    ಪೂರ್ಣಾಙ್ಕ ref_index; /* if >= 0, gives reference to a output constraint */
    ಪೂರ್ಣಾಙ್ಕ ಒಳಹರಿವು_index; /* if >= 0, gives reference to an input constraint */
    ಪೂರ್ಣಾಙ್ಕ priority; /* priority, used to assign registers */
    ಪೂರ್ಣಾಙ್ಕ reg; /* if >= 0, register number used for this operand */
    ಪೂರ್ಣಾಙ್ಕ is_llong; /* true if double register value */
    ಪೂರ್ಣಾಙ್ಕ is_memory; /* true if memory operand */
    ಪೂರ್ಣಾಙ್ಕ is_rw;     /* for '+' modifier */
    ಪೂರ್ಣಾಙ್ಕ is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
ಸಂರಚನಾ sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    ಪೂರ್ಣಾಙ್ಕ plt_sym;
    ಪೂರ್ಣಾಙ್ಕ dyn_index;
    unsigned ವರ್ಣ linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned ವರ್ಣ plt_thumb_stub:1;
#endif
};

ಸಂರಚನಾ TCCState {
    unsigned ವರ್ಣ verbose; /* if true, display some information during compilation */
    unsigned ವರ್ಣ nostdinc; /* if true, no standard headers are added */
    unsigned ವರ್ಣ nostdlib; /* if true, no standard libraries are added */
    unsigned ವರ್ಣ nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned ವರ್ಣ nocommon; /* if true, do not use common symbols for .bss data */
    unsigned ವರ್ಣ static_link; /* if true, static linking is performed */
    unsigned ವರ್ಣ rdynamic; /* if true, all symbols are exported */
    unsigned ವರ್ಣ symbolic; /* if true, resolve symbols in the current module first */
    unsigned ವರ್ಣ znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned ವರ್ಣ filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned ವರ್ಣ optimize; /* only to #define __OPTIMIZE__ */
    unsigned ವರ್ಣ option_pthread; /* -pthread option */
    unsigned ವರ್ಣ enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned ಪೂರ್ಣಾಙ್ಕ  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned ವರ್ಣ char_is_unsigned;
    unsigned ವರ್ಣ leading_underscore;
    unsigned ವರ್ಣ ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned ವರ್ಣ dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned ವರ್ಣ ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned ವರ್ಣ reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned ವರ್ಣ gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned ವರ್ಣ unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned ವರ್ಣ warn_none;
    unsigned ವರ್ಣ warn_all;
    unsigned ವರ್ಣ warn_error;
    unsigned ವರ್ಣ warn_write_strings;
    unsigned ವರ್ಣ warn_unsupported;
    unsigned ವರ್ಣ warn_implicit_function_declaration;
    unsigned ವರ್ಣ warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned ವರ್ಣ warn_ಅಂಕೆ; /* temp var for tcc_warning_c() */

    unsigned ವರ್ಣ option_r; /* option -r */
    unsigned ವರ್ಣ do_bench; /* option -bench */
    unsigned ವರ್ಣ just_deps; /* option -M  */
    unsigned ವರ್ಣ gen_deps; /* option -MD  */
    unsigned ವರ್ಣ include_sys_deps; /* option -MD  */
    unsigned ವರ್ಣ gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned ವರ್ಣ do_debug;
    unsigned ವರ್ಣ dwarf;
    unsigned ವರ್ಣ do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned ವರ್ಣ do_bounds_check;
#endif
    unsigned ವರ್ಣ test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned ವರ್ಣ gnu_ext;
    /* use TinyCC extensions */
    unsigned ವರ್ಣ tcc_ext;

    unsigned ವರ್ಣ dflag; /* -dX value */
    unsigned ವರ್ಣ Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned ವರ್ಣ nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned ವರ್ಣ float_abi; /* float ABI of the generated code*/
#endif

    unsigned ವರ್ಣ has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    ಪೂರ್ಣಾಙ್ಕ seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    ವರ್ಣ *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    ವರ್ಣ *soname; /* as specified on the command line (-soname) */
    ವರ್ಣ *rpath; /* as specified on the command line (-Wl,-rpath=) */
    ವರ್ಣ *elfint; /* -Wl,-I... on command line */
    ವರ್ಣ *elf_entryname; /* "_start" unless set */
    ವರ್ಣ *init_ಚಿಹ್ನೆ; /* symbols to call at load-time (not used currently) */
    ವರ್ಣ *fini_ಚಿಹ್ನೆ; /* symbols to call at unload-time (not used currently) */
    ವರ್ಣ *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    ಪೂರ್ಣಾಙ್ಕ output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    ಪೂರ್ಣಾಙ್ಕ output_format;
    /* nth test to run with -dt -run */
    ಪೂರ್ಣಾಙ್ಕ run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    ಪೂರ್ಣಾಙ್ಕ nb_loaded_dlls;

    /* include paths */
    ವರ್ಣ **include_paths;
    ಪೂರ್ಣಾಙ್ಕ nb_include_paths;

    ವರ್ಣ **sysinclude_paths;
    ಪೂರ್ಣಾಙ್ಕ nb_sysinclude_paths;

    /* library paths */
    ವರ್ಣ **library_paths;
    ಪೂರ್ಣಾಙ್ಕ nb_library_paths;

    /* crt?.o object path */
    ವರ್ಣ **crt_paths;
    ಪೂರ್ಣಾಙ್ಕ nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    ಶೂನ್ಯ *error_opaque;
    ಶೂನ್ಯ (*error_func)(ಶೂನ್ಯ *opaque, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ);
    ಪೂರ್ಣಾಙ್ಕ error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    ಪೂರ್ಣಾಙ್ಕ nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    ವರ್ಣ **target_deps;
    ಪೂರ್ಣಾಙ್ಕ nb_target_deps;

    /* compilation */
    BufferedFile *include_ರಾಶಿ[INCLUDE_ರಾಶಿ_SIZE];
    BufferedFile **include_ರಾಶಿ_ptr;

    ಪೂರ್ಣಾಙ್ಕ ifdef_ರಾಶಿ[IFDEF_ರಾಶಿ_SIZE];
    ಪೂರ್ಣಾಙ್ಕ *ifdef_ರಾಶಿ_ptr;

    /* included files enclosed with #ifndef MACRO */
    ಪೂರ್ಣಾಙ್ಕ cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    ಪೂರ್ಣಾಙ್ಕ nb_cached_includes;

    /* #pragma pack stack */
    ಪೂರ್ಣಾಙ್ಕ pack_ರಾಶಿ[PACK_ರಾಶಿ_SIZE];
    ಪೂರ್ಣಾಙ್ಕ *pack_ರಾಶಿ_ptr;
    ವರ್ಣ **pragma_libs;
    ಪೂರ್ಣಾಙ್ಕ nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ಸಂರಚನಾ InlineFunc **inline_fns;
    ಪೂರ್ಣಾಙ್ಕ nb_inline_fns;

    /* sections */
    Section **sections;
    ಪೂರ್ಣಾಙ್ಕ nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    ಪೂರ್ಣಾಙ್ಕ nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *text_section, *data_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_text_section; /* current section where function code is generated */
#ifdef CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#endif
    /* symbol section */
    ಸಙ್ಘ { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_frame_section;
    Section *eh_frame_hdr_section;
    unsigned long eh_start;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_ಸಾಲು_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_ಸಾಲು_str_section;
    ಪೂರ್ಣಾಙ್ಕ dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    ಸಂರಚನಾ _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ಸಂರಚನಾ sym_attr *sym_attrs;
    ಪೂರ್ಣಾಙ್ಕ nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    ಸಂರಚನಾ pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    ಪೂರ್ಣಾಙ್ಕ nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    ಪೂರ್ಣಾಙ್ಕ pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_ರಾಶಿ_size;
    addr_t pe_imagebase;
# ಯದಿ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    ಪೂರ್ಣಾಙ್ಕ uw_sym;
    ಪೂರ್ಣಾಙ್ಕ uw_xsym;
    unsigned uw_offs;
# endif
#endif

#ಯದಿ defined TCC_TARGET_MACHO
    ವರ್ಣ *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    ಪೂರ್ಣಾಙ್ಕ nb_sym_versions;
    ಸಂರಚನಾ sym_version *sym_versions;
    ಪೂರ್ಣಾಙ್ಕ nb_sym_to_version;
    ಪೂರ್ಣಾಙ್ಕ *sym_to_version;
    ಪೂರ್ಣಾಙ್ಕ dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    ಧ್ರುವ ವರ್ಣ *run_main; /* entry for tcc_run() */
    ಶೂನ್ಯ *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    ಧ್ರುವ ವರ್ಣ *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    ಶೂನ್ಯ *run_function_table; /* unwind data */
#endif
    ಸಂರಚನಾ TCCState *next;
    ಸಂರಚನಾ rt_context *rc; /* pointer to backtrace info block */
    ಶೂನ್ಯ *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    ಶೂನ್ಯ *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    ಪೂರ್ಣಾಙ್ಕ rt_ಅಂಕೆ_callers;
#endif

    /* benchmark info */
    ಪೂರ್ಣಾಙ್ಕ total_idents;
    ಪೂರ್ಣಾಙ್ಕ total_ಸಾಲುಗಳು;
    unsigned ಪೂರ್ಣಾಙ್ಕ total_bytes;
    unsigned ಪೂರ್ಣಾಙ್ಕ total_output[4];

    /* used by tcc_load_ldscript */
    unsigned ವರ್ಣ *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ಧ್ರುವ ವರ್ಣ *current_filename;

    /* used by main and tcc_parse_args only */
    ಸಂರಚನಾ filespec **files; /* files seen on command line */
    ಪೂರ್ಣಾಙ್ಕ nb_files; /* number thereof */
    ಪೂರ್ಣಾಙ್ಕ nb_libraries; /* number of libs thereof */
    ವರ್ಣ *outfile; /* output filename */
    ವರ್ಣ *deps_outfile; /* option -MF */
    ಪೂರ್ಣಾಙ್ಕ argc;
    ವರ್ಣ **argv;
    /* -Wl options */
    ವರ್ಣ **link_argv;
    ಪೂರ್ಣಾಙ್ಕ link_argc, link_optind;
};

ಸಂರಚನಾ filespec {
    ವರ್ಣ type;
    ವರ್ಣ name[1];
};

/* The current value can be: */
#define VT_VALMASK   0x003f  /* mask for value location, register or: */
#define VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#define VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#define VT_LOCAL     0x0032  /* offset on stack */
#define VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#define VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#define VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#define VT_LVAL      0x0100  /* var is an lvalue */
#define VT_SYM       0x0200  /* a symbol value is added */
#define VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#define VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#define VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#define VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#define VT_BTYPE       0x000f  /* mask for basic type */
#define VT_VOID             0  /* void type */
#define VT_BYTE             1  /* signed byte type */
#define VT_SHORT            2  /* short type */
#define VT_INT              3  /* integer type */
#define VT_LLONG            4  /* 64 bit integer */
#define VT_PTR              5  /* pointer */
#define VT_FUNC             6  /* function type */
#define VT_STRUCT           7  /* struct/union definition */
#define VT_FLOAT            8  /* IEEE float */
#define VT_DOUBLE           9  /* IEEE double */
#define VT_LDOUBLE         10  /* IEEE long double */
#define VT_BOOL            11  /* ISOC99 boolean type */
#define VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#define VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#define VT_UNSIGNED    0x0010  /* unsigned type */
#define VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#define VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#define VT_BITFIELD    0x0080  /* bitfield modifier */
#define VT_CONSTANT    0x0100  /* const modifier */
#define VT_VOLATILE    0x0200  /* volatile modifier */
#define VT_RESTRICT    0x0400  /* restrict modifier */
#define VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#define VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#define VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#define VT_EXTERN  0x00002000  /* extern definition */
#define VT_STATIC  0x00004000  /* static variable */
#define VT_TYPEDEF 0x00008000  /* typedef definition */
#define VT_INLINE  0x00010000  /* inline definition */
#define VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#define VT_STRUCT_SHIFT 20     /* shift for bitfield shift values (32 - 2*6) */
#define VT_STRUCT_MASK (((1U << (6+6)) - 1) << VT_STRUCT_SHIFT | VT_BITFIELD)
#define BIT_POS(t) (((t) >> VT_STRUCT_SHIFT) & 0x3f)
#define BIT_SIZE(t) (((t) >> (VT_STRUCT_SHIFT + 6)) & 0x3f)

#define VT_UNION    (1 << VT_STRUCT_SHIFT | VT_STRUCT)
#define VT_ENUM     (2 << VT_STRUCT_SHIFT) /* integral type is an enum really */
#define VT_ENUM_VAL (3 << VT_STRUCT_SHIFT) /* integral type is an enum constant really */

#define IS_ENUM(t) ((t & VT_STRUCT_MASK) == VT_ENUM)
#define IS_ENUM_VAL(t) ((t & VT_STRUCT_MASK) == VT_ENUM_VAL)
#define IS_UNION(t) ((t & (VT_STRUCT_MASK|VT_BTYPE)) == VT_UNION)

#define VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#define VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#define VT_TYPE (~(VT_STORAGE|VT_STRUCT_MASK))

/* symbol was created by tccasm.c first */
#define VT_ASM (VT_VOID | 4 << VT_STRUCT_SHIFT)
#define VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_SHIFT)
#define IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_MASK) & ~(1<<VT_STRUCT_SHIFT))) == VT_ASM)
#define IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_MASK)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#define VT_BT_ARRAY (6 << VT_STRUCT_SHIFT)
#define IS_BT_ARRAY(t) ((t & VT_STRUCT_MASK) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#define BFVAL(M,N) ((unsigned)((M) & ~((M) << 1)) * (N))
#define BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#define BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#define TOK_LAND  0x90
#define TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#define TOK_ULT 0x92
#define TOK_UGE 0x93
#define TOK_EQ  0x94
#define TOK_NE  0x95
#define TOK_ULE 0x96
#define TOK_UGT 0x97
#define TOK_Nset 0x98
#define TOK_Nclear 0x99
#define TOK_LT  0x9c
#define TOK_GE  0x9d
#define TOK_LE  0x9e
#define TOK_GT  0x9f

#define TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#define TOK_DEC     0x80 /* -- */
#define TOK_MID     0x81 /* inc/dec, to void constant */
#define TOK_INC     0x82 /* ++ */
#define TOK_UDIV    0x83 /* unsigned division */
#define TOK_UMOD    0x84 /* unsigned modulo */
#define TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#define TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#define TOK_ADDC1   0x87 /* add with carry generation */
#define TOK_ADDC2   0x88 /* add with carry use */
#define TOK_SUBC1   0x89 /* add with carry generation */
#define TOK_SUBC2   0x8a /* add with carry use */
#define TOK_SHL     '<' /* shift left */
#define TOK_SAR     '>' /* signed shift right */
#define TOK_SHR     0x8b /* unsigned shift right */
#define TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#define TOK_ARROW   0xa0 /* -> */
#define TOK_DOTS    0xa1 /* three dots */
#define TOK_TWODOTS 0xa2 /* C++ token ? */
#define TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#define TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#define TOK_PPJOIN  (TOK_TWOSHARPS | SYM_FIELD) /* A '##' in a macro to mean pasting */
#define TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#define TOK_A_ADD   0xb0
#define TOK_A_SUB   0xb1
#define TOK_A_MUL   0xb2
#define TOK_A_DIV   0xb3
#define TOK_A_MOD   0xb4
#define TOK_A_AND   0xb5
#define TOK_A_OR    0xb6
#define TOK_A_XOR   0xb7
#define TOK_A_SHL   0xb8
#define TOK_A_SAR   0xb9

#define TOK_ASSIGN(t) (t >= TOK_A_ADD && t <= TOK_A_SAR)
#define TOK_ASSIGN_OP(t) ("+-*/%&|^<>"[t - TOK_A_ADD])

/* tokens that carry values (in additional token string space / tokc) --> */
#define TOK_CCHAR   0xc0 /* char constant in tokc */
#define TOK_LCHAR   0xc1
#define TOK_CINT    0xc2 /* number in tokc */
#define TOK_CUINT   0xc3 /* unsigned int constant */
#define TOK_CLLONG  0xc4 /* long long constant */
#define TOK_CULLONG 0xc5 /* unsigned long long constant */
#define TOK_CLONG   0xc6 /* long constant */
#define TOK_CULONG  0xc7 /* unsigned long constant */
#define TOK_STR     0xc8 /* pointer to string in tokc */
#define TOK_LSTR    0xc9
#define TOK_CFLOAT  0xca /* float constant */
#define TOK_CDOUBLE 0xcb /* double constant */
#define TOK_CLDOUBLE 0xcc /* long double constant */
#define TOK_PPNUM   0xcd /* preprocessor number */
#define TOK_PPSTR   0xce /* preprocessor string */
#define TOK_LINENUM 0xcf /* line number info */

#define TOK_HAS_ಮೌಲ್ಯ(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

ಗಣನಾ tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#ಅನ್ತರ್ಭಾವ "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA ಸಂರಚನಾ TCCState *tcc_state;
ST_DATA ಶೂನ್ಯ** stk_data;
ST_DATA ಪೂರ್ಣಾಙ್ಕ nb_stk_data;
ST_DATA ಪೂರ್ಣಾಙ್ಕ g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC ವರ್ಣ *pstrcpy(ವರ್ಣ *buf, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s);
ST_FUNC ವರ್ಣ *pstrcat(ವರ್ಣ *buf, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s);
ST_FUNC ವರ್ಣ *pstrncpy(ವರ್ಣ *out, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s, size_t ಅಂಕೆ);
PUB_FUNC ವರ್ಣ *tcc_basename(ಧ್ರುವ ವರ್ಣ *name);
PUB_FUNC ವರ್ಣ *tcc_fileextension (ಧ್ರುವ ವರ್ಣ *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC ಶೂನ್ಯ tcc_free(ಶೂನ್ಯ *ptr);
PUB_FUNC ಶೂನ್ಯ *tcc_malloc(unsigned long size);
PUB_FUNC ಶೂನ್ಯ *tcc_mallocz(unsigned long size);
PUB_FUNC ಶೂನ್ಯ *tcc_realloc(ಶೂನ್ಯ *ptr, unsigned long size);
PUB_FUNC ವರ್ಣ *tcc_strdup(ಧ್ರುವ ವರ್ಣ *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC ಶೂನ್ಯ tcc_free_debug(ಶೂನ್ಯ *ptr);
PUB_FUNC ಶೂನ್ಯ *tcc_malloc_debug(unsigned long size, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು);
PUB_FUNC ಶೂನ್ಯ *tcc_mallocz_debug(unsigned long size, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು);
PUB_FUNC ಶೂನ್ಯ *tcc_realloc_debug(ಶೂನ್ಯ *ptr, unsigned long size, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು);
PUB_FUNC ವರ್ಣ *tcc_strdup_debug(ಧ್ರುವ ವರ್ಣ *str, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು);
#endif

ST_FUNC ಶೂನ್ಯ libc_free(ಶೂನ್ಯ *ptr);
/* defined to be not used */
#define ಮುಕ್ತ(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ _tcc_error_noabort(ಧ್ರುವ ವರ್ಣ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN ಶೂನ್ಯ _tcc_error(ಧ್ರುವ ವರ್ಣ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC ಶೂನ್ಯ _tcc_warning(ಧ್ರುವ ವರ್ಣ *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(ಸಂದೇಶ) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,ಸಂದೇಶ)

/* other utilities */
ST_FUNC ಶೂನ್ಯ dynarray_add(ಶೂನ್ಯ *ptab, ಪೂರ್ಣಾಙ್ಕ *nb_ptr, ಶೂನ್ಯ *data);
ST_FUNC ಶೂನ್ಯ dynarray_reset(ಶೂನ್ಯ *pp, ಪೂರ್ಣಾಙ್ಕ *n);
ST_INLN ಶೂನ್ಯ cstr_ccat(CString *cstr, ಪೂರ್ಣಾಙ್ಕ ch);
ST_FUNC ಶೂನ್ಯ cstr_cat(CString *cstr, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ len);
ST_FUNC ಶೂನ್ಯ cstr_wccat(CString *cstr, ಪೂರ್ಣಾಙ್ಕ ch);
ST_FUNC ಶೂನ್ಯ cstr_new(CString *cstr);
ST_FUNC ಶೂನ್ಯ cstr_free(CString *cstr);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ cstr_printf(CString *cs, ಧ್ರುವ ವರ್ಣ *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ cstr_vprintf(CString *cstr, ಧ್ರುವ ವರ್ಣ *fmt, va_list ap);
ST_FUNC ಶೂನ್ಯ cstr_reset(CString *cstr);
ST_FUNC ಶೂನ್ಯ tcc_open_bf(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ initlen);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_open(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename);
ST_FUNC ಶೂನ್ಯ tcc_close(ಶೂನ್ಯ);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_ತಳ್ಳು(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_ತೆಗೆ() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_ತಳ್ಳು(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_ತೆಗೆ())

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_file_internal(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flags);
/* flags: */
#define AFF_PRINT_ERROR     0x10 /* print error if file not found */
#define AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#define AFF_TYPE_BIN        0x40 /* file to add is binary */
#define AFF_WHOLE_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#define AFF_TYPE_NONE   0
#define AFF_TYPE_C      1
#define AFF_TYPE_ASM    2
#define AFF_TYPE_ASMPP  4
#define AFF_TYPE_LIB    8
#define AFF_TYPE_MASK   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#define AFF_BINTYPE_REL 1
#define AFF_BINTYPE_DYN 2
#define AFF_BINTYPE_AR  3
#define AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#define FILE_NOT_FOUND -2
#define FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#ifndef ELF_OBJ_ONLY
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_crt(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename);
#endif
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_dll(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flags);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_support(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC ಶೂನ್ಯ tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC ಶೂನ್ಯ tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC ಶೂನ್ಯ tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_library_err(TCCState *s, ಧ್ರುವ ವರ್ಣ *f);
PUB_FUNC ಶೂನ್ಯ tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_parse_args(TCCState *s, ಪೂರ್ಣಾಙ್ಕ *argc, ವರ್ಣ ***argv);
#ifdef _WIN32
ST_FUNC ವರ್ಣ *normalize_slashes(ವರ್ಣ *path);
PUB_FUNC FILE *tcc_fopen(ಧ್ರುವ ವರ್ಣ *f, ಧ್ರುವ ವರ್ಣ *m);
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_fclose(FILE *f);
#ಅನ್ಯಥಾ
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ಧ್ರುವ ವರ್ಣ *dllname, ಪೂರ್ಣಾಙ್ಕ level);
ST_FUNC ವರ್ಣ *tcc_load_text(ಪೂರ್ಣಾಙ್ಕ fd);
/* for #pragma once */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ normalized_PATHCMP(ಧ್ರುವ ವರ್ಣ *f1, ಧ್ರುವ ವರ್ಣ *f2);

/* tcc_parse_args return codes: */
#define OPT_HELP 1
#define OPT_HELP2 2
#define OPT_V 3
#define OPT_PRINT_DIRS 4
#define OPT_AR 5
#define OPT_IMPDEF 6
#define OPT_M32 32
#define OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_DATA ಸಂರಚನಾ BufferedFile *file;
ST_DATA ಪೂರ್ಣಾಙ್ಕ tok;
ST_DATA CValue tokc;
ST_DATA ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *macro_ptr;
ST_DATA ಪೂರ್ಣಾಙ್ಕ parse_flags;
ST_DATA ಪೂರ್ಣಾಙ್ಕ tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ಪೂರ್ಣಾಙ್ಕ tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ಪೂರ್ಣಾಙ್ಕ pp_ಅಭಿವ್ಯಕ್ತಿ;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_ಅಂಕೆ    0x0002 /* return numbers instead of TOK_PPNUM */
#define PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#define PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#define PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#define PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#define PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#define IS_SPC 1
#define IS_ID  2
#define IS_ಅಂಕೆ 4

ಗಣನಾ ಸಾಲು_macro_output_format {
    ಸಾಲು_MACRO_OUTPUT_FORMAT_GCC,
    ಸಾಲು_MACRO_OUTPUT_FORMAT_NONE,
    ಸಾಲು_MACRO_OUTPUT_FORMAT_STD,
    ಸಾಲು_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ len);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tok_alloc_const(ಧ್ರುವ ವರ್ಣ *str);
ST_FUNC ಧ್ರುವ ವರ್ಣ *get_tok_str(ಪೂರ್ಣಾಙ್ಕ v, CValue *cv);
ST_FUNC ಶೂನ್ಯ begin_macro(TokenString *str, ಪೂರ್ಣಾಙ್ಕ alloc);
ST_FUNC ಶೂನ್ಯ end_macro(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ set_idnum(ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ val);
ST_INLN ಶೂನ್ಯ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ tok_str_free(TokenString *s);
ST_FUNC ಶೂನ್ಯ tok_str_free_str(ಪೂರ್ಣಾಙ್ಕ *str);
ST_FUNC ಶೂನ್ಯ tok_str_add(TokenString *s, ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ tok_str_add_tok(TokenString *s);
ST_INLN ಶೂನ್ಯ define_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ macro_type, ಪೂರ್ಣಾಙ್ಕ *str, Sym *first_arg);
ST_FUNC ಶೂನ್ಯ define_undef(Sym *s);
ST_INLN Sym *define_find(ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC ಶೂನ್ಯ free_defines(Sym *b);
ST_FUNC ಶೂನ್ಯ parse_define(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ skip_to_eol(ಪೂರ್ಣಾಙ್ಕ warn);
ST_FUNC ಶೂನ್ಯ preprocess(ಪೂರ್ಣಾಙ್ಕ is_bof);
ST_FUNC ಶೂನ್ಯ next(ಶೂನ್ಯ);
ST_INLN ಶೂನ್ಯ unget_tok(ಪೂರ್ಣಾಙ್ಕ last_tok);
ST_FUNC ಶೂನ್ಯ preprocess_start(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ filetype);
ST_FUNC ಶೂನ್ಯ preprocess_end(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccpp_new(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccpp_delete(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccpp_putfile(ಧ್ರುವ ವರ್ಣ *filename);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_preprocess(TCCState *s1);
ST_FUNC ಶೂನ್ಯ skip(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC NORETURN ಶೂನ್ಯ expect(ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ);
ST_FUNC ಶೂನ್ಯ pp_error(CString *cs);


/* space excluding newline */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ is_space(ಪೂರ್ಣಾಙ್ಕ ch) {
    ಪ್ರತ್ಯಾಗಮ ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ isid(ಪೂರ್ಣಾಙ್ಕ c) {
    ಪ್ರತ್ಯಾಗಮ (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ isnum(ಪೂರ್ಣಾಙ್ಕ c) {
    ಪ್ರತ್ಯಾಗಮ c >= '0' && c <= '9';
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ isoct(ಪೂರ್ಣಾಙ್ಕ c) {
    ಪ್ರತ್ಯಾಗಮ c >= '0' && c <= '7';
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ toup(ಪೂರ್ಣಾಙ್ಕ c) {
    ಪ್ರತ್ಯಾಗಮ (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / ಪರಿಮಾಣ(Sym))

ST_DATA Sym *global_ರಾಶಿ;
ST_DATA Sym *local_ರಾಶಿ;
ST_DATA Sym *local_label_ರಾಶಿ;
ST_DATA Sym *global_label_ರಾಶಿ;
ST_DATA Sym *define_ರಾಶಿ;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA ಪೂರ್ಣಾಙ್ಕ rsym, anon_sym, ind, loc;
ST_DATA ವರ್ಣ debug_modes;

ST_DATA ಪೂರ್ಣಾಙ್ಕ nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA ಪೂರ್ಣಾಙ್ಕ global_ಅಭಿವ್ಯಕ್ತಿ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_var; /* true if current function is variadic */
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_vc; /* stack address for implicit struct return storage */
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_ind; /* function start address */
ST_DATA ಧ್ರುವ ವರ್ಣ *funcname;

ST_FUNC ಶೂನ್ಯ tccgen_init(TCCState *s1);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tccgen_compile(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccgen_finish(TCCState *s1);
ST_FUNC ಶೂನ್ಯ check_vstack(ಶೂನ್ಯ);

ST_INLN ಪೂರ್ಣಾಙ್ಕ is_float(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ ieee_finite(ದ್ವಿಗುಣ d);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ exact_log2p1(ಪೂರ್ಣಾಙ್ಕ i);
ST_FUNC ಶೂನ್ಯ test_lvalue(ಶೂನ್ಯ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC ಶೂನ್ಯ update_storage(Sym *sym);
ST_FUNC ಶೂನ್ಯ put_extern_sym2(Sym *sym, ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ, addr_t ಮೌಲ್ಯ, unsigned long size, ಪೂರ್ಣಾಙ್ಕ can_add_underscore);
ST_FUNC ಶೂನ್ಯ put_extern_sym(Sym *sym, Section *section, addr_t ಮೌಲ್ಯ, unsigned long size);
#ಯದಿ PTR_SIZE == 4
ST_FUNC ಶೂನ್ಯ greloc(Section *s, Sym *sym, unsigned long offset, ಪೂರ್ಣಾಙ್ಕ type);
#endif
ST_FUNC ಶೂನ್ಯ greloca(Section *s, Sym *sym, unsigned long offset, ಪೂರ್ಣಾಙ್ಕ type, addr_t addend);

ST_INLN ಶೂನ್ಯ sym_free(Sym *sym);
ST_FUNC Sym *sym_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v, CType *type, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ sym_ತೆಗೆ(Sym **ptop, Sym *b, ಪೂರ್ಣಾಙ್ಕ keep);
ST_FUNC Sym *sym_push2(Sym **ps, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC Sym *sym_find2(Sym *s, ಪೂರ್ಣಾಙ್ಕ v);
ST_INLN Sym *sym_find(ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC Sym *label_find(ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC Sym *label_ತಳ್ಳು(Sym **ptop, ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ flags);
ST_FUNC ಶೂನ್ಯ label_ತೆಗೆ(Sym **ptop, Sym *slast, ಪೂರ್ಣಾಙ್ಕ keep);
ST_INLN Sym *struct_find(ಪೂರ್ಣಾಙ್ಕ v);

ST_FUNC Sym *global_identifier_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC Sym *external_global_sym(ಪೂರ್ಣಾಙ್ಕ v, CType *type);
ST_FUNC Sym *external_helper_sym(ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC ಶೂನ್ಯ vpush_helper_func(ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC ಶೂನ್ಯ vset(CType *type, ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC ಶೂನ್ಯ vset_VT_CMP(ಪೂರ್ಣಾಙ್ಕ op);
ST_FUNC ಶೂನ್ಯ vpushi(ಪೂರ್ಣಾಙ್ಕ v);
ST_FUNC ಶೂನ್ಯ vpushv(SValue *v);
ST_FUNC ಶೂನ್ಯ vpushsym(CType *type, Sym *sym);
ST_FUNC ಶೂನ್ಯ vswap(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ vrott(ಪೂರ್ಣಾಙ್ಕ n);
ST_FUNC ಶೂನ್ಯ vrotb(ಪೂರ್ಣಾಙ್ಕ n);
ST_FUNC ಶೂನ್ಯ vrev(ಪೂರ್ಣಾಙ್ಕ n);
ST_FUNC ಶೂನ್ಯ vpop(ಶೂನ್ಯ);
#ಯದಿ PTR_SIZE == 4
ST_FUNC ಶೂನ್ಯ lexpand(ಶೂನ್ಯ);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC ಪೂರ್ಣಾಙ್ಕ get_reg_ex(ಪೂರ್ಣಾಙ್ಕ rc, ಪೂರ್ಣಾಙ್ಕ rc2);
#endif
ST_FUNC ಶೂನ್ಯ save_reg(ಪೂರ್ಣಾಙ್ಕ r);
ST_FUNC ಶೂನ್ಯ save_reg_upstack(ಪೂರ್ಣಾಙ್ಕ r, ಪೂರ್ಣಾಙ್ಕ n);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ get_reg(ಪೂರ್ಣಾಙ್ಕ rc);
ST_FUNC ಶೂನ್ಯ save_regs(ಪೂರ್ಣಾಙ್ಕ n);
ST_FUNC ಶೂನ್ಯ gaddrof(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gv(ಪೂರ್ಣಾಙ್ಕ rc);
ST_FUNC ಶೂನ್ಯ gv2(ಪೂರ್ಣಾಙ್ಕ rc1, ಪೂರ್ಣಾಙ್ಕ rc2);
ST_FUNC ಶೂನ್ಯ gen_op(ಪೂರ್ಣಾಙ್ಕ op);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ type_size(CType *type, ಪೂರ್ಣಾಙ್ಕ *a);
ST_FUNC ಶೂನ್ಯ mk_pointer(CType *type);
ST_FUNC ಶೂನ್ಯ vstore(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ inc(ಪೂರ್ಣಾಙ್ಕ post, ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC CString* parse_mult_str(ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ);
ST_FUNC CString* parse_asm_str(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ indir(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ unary(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gexpr(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ ಅಭಿವ್ಯಕ್ತಿ_const(ಶೂನ್ಯ);
#ಯದಿ defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#ಯದಿ defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC ಪೂರ್ಣಾಙ್ಕ classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC ಶೂನ್ಯ gbound_args(ಪೂರ್ಣಾಙ್ಕ nb_args);
ST_DATA ಪೂರ್ಣಾಙ್ಕ func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_ದ್ವಿಮಾನ 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    unsigned ಪೂರ್ಣಾಙ್ಕ n_strx;         /* index into string table of name */
    unsigned ವರ್ಣ n_type;         /* type of symbol */
    unsigned ವರ್ಣ n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned ಪೂರ್ಣಾಙ್ಕ n_ಮೌಲ್ಯ;        /* value of symbol */
} Stab_Sym;

ST_FUNC ಶೂನ್ಯ tccelf_new(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccelf_delete(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccelf_begin_file(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, ಪೂರ್ಣಾಙ್ಕ sh_type, ಪೂರ್ಣಾಙ್ಕ sh_flags);
ST_FUNC ಶೂನ್ಯ section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, ಪೂರ್ಣಾಙ್ಕ align);
ST_FUNC ಶೂನ್ಯ *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name);
ST_FUNC ಶೂನ್ಯ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ಧ್ರುವ ವರ್ಣ *symtab_name, ಪೂರ್ಣಾಙ್ಕ sh_type, ಪೂರ್ಣಾಙ್ಕ sh_flags, ಧ್ರುವ ವರ್ಣ *strtab_name, ಧ್ರುವ ವರ್ಣ *hash_name, ಪೂರ್ಣಾಙ್ಕ hash_sh_flags);
ST_FUNC ಶೂನ್ಯ init_symtab(Section *s);

ST_FUNC ಪೂರ್ಣಾಙ್ಕ put_elf_str(Section *s, ಧ್ರುವ ವರ್ಣ *sym);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ put_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, unsigned long size, ಪೂರ್ಣಾಙ್ಕ info, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ shndx, ಧ್ರುವ ವರ್ಣ *name);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ set_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, unsigned long size, ಪೂರ್ಣಾಙ್ಕ info, ಪೂರ್ಣಾಙ್ಕ other, ಪೂರ್ಣಾಙ್ಕ shndx, ಧ್ರುವ ವರ್ಣ *name);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ find_elf_sym(Section *s, ಧ್ರುವ ವರ್ಣ *name);
ST_FUNC ಶೂನ್ಯ put_elf_reloc(Section *symtab, Section *s, unsigned long offset, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ ಚಿಹ್ನೆ);
ST_FUNC ಶೂನ್ಯ put_elf_reloca(Section *symtab, Section *s, unsigned long offset, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ ಚಿಹ್ನೆ, addr_t addend);

ST_FUNC ಶೂನ್ಯ resolve_common_syms(TCCState *s1);
ST_FUNC ಶೂನ್ಯ relocate_syms(TCCState *s1, Section *symtab, ಪೂರ್ಣಾಙ್ಕ do_resolve);
ST_FUNC ಶೂನ್ಯ relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(ಪೂರ್ಣಾಙ್ಕ fd, ಶೂನ್ಯ *buf, size_t ಎಣಿಕೆ_2);
ST_FUNC ಶೂನ್ಯ *load_data(ಪೂರ್ಣಾಙ್ಕ fd, unsigned long file_offset, unsigned long size);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_object_type(ಪೂರ್ಣಾಙ್ಕ fd, ElfW(Ehdr) *h);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_object_file(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, unsigned long file_offset);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_archive(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಪೂರ್ಣಾಙ್ಕ alacarte);
ST_FUNC ಶೂನ್ಯ add_array(TCCState *s1, ಧ್ರುವ ವರ್ಣ *sec, ಪೂರ್ಣಾಙ್ಕ c);

ST_FUNC ಸಂರಚನಾ sym_attr *get_sym_attr(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ index, ಪೂರ್ಣಾಙ್ಕ alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ಧ್ರುವ ವರ್ಣ *name, ಪೂರ್ಣಾಙ್ಕ err, ಪೂರ್ಣಾಙ್ಕ forc);
ST_FUNC ಶೂನ್ಯ list_elf_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ಶೂನ್ಯ *val));
ST_FUNC ಪೂರ್ಣಾಙ್ಕ set_global_sym(TCCState *s1, ಧ್ರುವ ವರ್ಣ *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    ಪ್ರತಿ (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_dll(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ level);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_ldscript(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd);
ST_FUNC ಶೂನ್ಯ tccelf_add_crtbegin(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC ಶೂನ್ಯ tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC ಪೂರ್ಣಾಙ್ಕ code_reloc (ಪೂರ್ಣಾಙ್ಕ reloc_type);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gotplt_entry_type (ಪೂರ್ಣಾಙ್ಕ reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
ಗಣನಾ gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#ಯದಿ !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ಸಂರಚನಾ sym_attr *attr);
ST_FUNC ಶೂನ್ಯ relocate_plt(TCCState *s1);
ST_FUNC ಶೂನ್ಯ build_got_entries(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಙ್ಕ type, unsigned ವರ್ಣ *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ target_machine_defs;
ST_DATA ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ reg_classes[NB_REGS];

ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಙ್ಕ t, ಪೂರ್ಣಾಙ್ಕ a);
ST_FUNC ಶೂನ್ಯ gsym(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ load(ಪೂರ್ಣಾಙ್ಕ r, SValue *sv);
ST_FUNC ಶೂನ್ಯ store(ಪೂರ್ಣಾಙ್ಕ r, SValue *v);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಙ್ಕ variadic, CType *ret, ಪೂರ್ಣಾಙ್ಕ *align, ಪೂರ್ಣಾಙ್ಕ *regsize);
ST_FUNC ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಙ್ಕ nb_args);
ST_FUNC ಶೂನ್ಯ gfunc_prolog(Sym *func_sym);
ST_FUNC ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಙ್ಕ);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಙ್ಕ a);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_cond(ಪೂರ್ಣಾಙ್ಕ op, ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gjmp_append(ಪೂರ್ಣಾಙ್ಕ n, ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಙ್ಕ op);
ST_FUNC ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಙ್ಕ op);
ST_FUNC ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ ggoto(ಶೂನ್ಯ);
#ifndef TCC_TARGET_C67
ST_FUNC ಶೂನ್ಯ o(unsigned ಪೂರ್ಣಾಙ್ಕ c);
#endif
ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಙ್ಕ addr);
ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಙ್ಕ addr);
ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಙ್ಕ align);

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ uint16_t read16le(unsigned ವರ್ಣ *p) {
    ಪ್ರತ್ಯಾಗಮ p[0] | (uint16_t)p[1] << 8;
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ write16le(unsigned ವರ್ಣ *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ uint32_t read32le(unsigned ವರ್ಣ *p) {
  ಪ್ರತ್ಯಾಗಮ read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ write32le(unsigned ವರ್ಣ *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ add32le(unsigned ವರ್ಣ *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ uint64_t read64le(unsigned ವರ್ಣ *p) {
  ಪ್ರತ್ಯಾಗಮ read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ write64le(unsigned ವರ್ಣ *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ add64le(unsigned ವರ್ಣ *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#ಯದಿ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಙ್ಕ c);
#endif
#ಯದಿ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC ಶೂನ್ಯ gen_addr32(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_addrpc32(ಪೂರ್ಣಾಙ್ಕ r, Sym *sym, ಪೂರ್ಣಾಙ್ಕ c);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op);
#ifdef TCC_TARGET_PE
ST_FUNC ಶೂನ್ಯ gen_vla_result(ಪೂರ್ಣಾಙ್ಕ addr);
#endif
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#ಯದಿ defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ಧ್ರುವ ವರ್ಣ *default_elfinterp(ಸಂರಚನಾ TCCState *s);
#endif
ST_FUNC ಶೂನ್ಯ arm_init(ಸಂರಚನಾ TCCState *s);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op);
ST_FUNC ಶೂನ್ಯ gfunc_return(CType *func_type);
ST_FUNC ಶೂನ್ಯ gen_va_start(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_va_arg(CType *t);
ST_FUNC ಶೂನ್ಯ gen_clear_cache(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಙ್ಕ op);
ST_FUNC ಶೂನ್ಯ gen_va_start(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ arch_transfer_ret_regs(ಪೂರ್ಣಾಙ್ಕ);
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
ST_FUNC ಶೂನ್ಯ gen_clear_cache(ಶೂನ್ಯ);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_load_coff(TCCState * s1, ಪೂರ್ಣಾಙ್ಕ fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC ಶೂನ್ಯ asm_instr(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ asm_global_instr(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_assemble(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC ಪೂರ್ಣಾಙ್ಕ find_constraint(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, ಧ್ರುವ ವರ್ಣ *name, ಧ್ರುವ ವರ್ಣ **pp);
ST_FUNC Sym* get_asm_sym(ಪೂರ್ಣಾಙ್ಕ name, Sym *csym);
ST_FUNC ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_int_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1);
#ಯದಿ PTR_SIZE == 8
ST_FUNC ಶೂನ್ಯ gen_expr64(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ opcode);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ asm_parse_regvar(ಪೂರ್ಣಾಙ್ಕ t);
ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಧ್ರುವ uint8_t *clobber_regs, ಪೂರ್ಣಾಙ್ಕ *pout_reg);
ST_FUNC ಶೂನ್ಯ subst_asm_operand(CString *add_str, SValue *sv, ಪೂರ್ಣಾಙ್ಕ modifier);
ST_FUNC ಶೂನ್ಯ asm_gen_code(ASMOperand *operands, ಪೂರ್ಣಾಙ್ಕ nb_operands, ಪೂರ್ಣಾಙ್ಕ nb_outputs, ಪೂರ್ಣಾಙ್ಕ is_output, uint8_t *clobber_regs, ಪೂರ್ಣಾಙ್ಕ out_reg);
ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಧ್ರುವ ವರ್ಣ *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_load_file(ಸಂರಚನಾ TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_output_file(TCCState * s1, ಧ್ರುವ ವರ್ಣ *filename);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_putimport(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ dllindex, ಧ್ರುವ ವರ್ಣ *name, addr_t ಮೌಲ್ಯ);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ pe_setsubsy(TCCState *s1, ಧ್ರುವ ವರ್ಣ *arg);
#ಯದಿ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#ಯದಿ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC ಶೂನ್ಯ pe_add_unwind_data(unsigned start, unsigned end, unsigned ರಾಶಿ);
#endif
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_get_dllexports(ಧ್ರುವ ವರ್ಣ *filename, ವರ್ಣ **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC ಪೂರ್ಣಾಙ್ಕ macho_output_file(TCCState * s1, ಧ್ರುವ ವರ್ಣ *filename);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ macho_load_dll(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ lev);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ macho_load_tbd(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ fd, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ lev);
#ifdef TCC_IS_NATIVE
ST_FUNC ಶೂನ್ಯ tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC ವರ್ಣ* macho_tbd_soname(ಪೂರ್ಣಾಙ್ಕ fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    ರಿಕ್ತ
/* dummy function for profiling */
ST_FUNC ಶೂನ್ಯ *dlopen(ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flag);
ST_FUNC ಶೂನ್ಯ dlclose(ಶೂನ್ಯ *p);
ST_FUNC ಧ್ರುವ ವರ್ಣ *dlerror(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ *dlsym(ಶೂನ್ಯ *handle, ಧ್ರುವ ವರ್ಣ *ಚಿಹ್ನೆ);
#endif
ST_FUNC ಶೂನ್ಯ tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#ಯದಿ 0 /* included in tcc.c */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_ar(TCCState *s, ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv);
#ifdef TCC_TARGET_PE
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_impdef(TCCState *s, ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv);
#endif
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_tool_cross(TCCState *s, ವರ್ಣ **argv, ಪೂರ್ಣಾಙ್ಕ option);
ST_FUNC ಪೂರ್ಣಾಙ್ಕ gen_makedeps(TCCState *s, ಧ್ರುವ ವರ್ಣ *target, ಧ್ರುವ ವರ್ಣ *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC ಶೂನ್ಯ tcc_debug_new(TCCState *s);

ST_FUNC ಶೂನ್ಯ tcc_debug_start(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_end(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_bincl(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_eincl(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_newfile(TCCState *s1);

ST_FUNC ಶೂನ್ಯ tcc_debug_ಸಾಲು(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC ಶೂನ್ಯ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC ಶೂನ್ಯ tcc_debug_prolog_epilog(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ);
ST_FUNC ಶೂನ್ಯ tcc_debug_funcend(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ size);
ST_FUNC ಶೂನ್ಯ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ಪೂರ್ಣಾಙ್ಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಙ್ಕ sym_bind, ಪೂರ್ಣಾಙ್ಕ sym_type);
ST_FUNC ಶೂನ್ಯ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC ಶೂನ್ಯ tcc_debug_stabn(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ type, ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ);
ST_FUNC ಶೂನ್ಯ tcc_debug_fix_forw(TCCState *s1, CType *t);

#ಯದಿ !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC ಶೂನ್ಯ tcc_eh_frame_start(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_eh_frame_end(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_eh_frame_hdr(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC ಶೂನ್ಯ tcc_tcov_start(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_tcov_end(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_tcov_check_ಸಾಲು(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ start);
ST_FUNC ಶೂನ್ಯ tcc_tcov_block_end(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು);
ST_FUNC ಶೂನ್ಯ tcc_tcov_block_begin(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_ಸಾಲು_section      s1->dwarf_ಸಾಲು_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_ಸಾಲು_str_section  s1->dwarf_ಸಾಲು_str_section

#define DWARF_MAX_128	((8 * ಪರಿಮಾಣ (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ uint64_t
dwarf_read_uleb128(unsigned ವರ್ಣ **ln, unsigned ವರ್ಣ *end)
{
    unsigned ವರ್ಣ *cp = *ln;
    uint64_t retval = 0;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	ಯದಿ ((byte & 0x80) == 0)
	    ಭಙ್ಗ;
    }
    *ln = cp;
    ಪ್ರತ್ಯಾಗಮ retval;
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ int64_t
dwarf_read_sleb128(unsigned ವರ್ಣ **ln, unsigned ವರ್ಣ *end)
{
    unsigned ವರ್ಣ *cp = *ln;
    int64_t retval = 0;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	ಯದಿ ((byte & 0x80) == 0) {
	    ಯದಿ ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    ಭಙ್ಗ;
	}
    }
    *ln = cp;
    ಪ್ರತ್ಯಾಗಮ retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#ಅನ್ಯಥಾ
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#ಯದಿ defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#ಅನ್ಯಥಾ
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#ಯದಿ CONFIG_TCC_SEMLOCK
#ಯದಿ defined _WIN32
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಚಞ್ಚಲ LONG init; CRITICAL_SECTION cs; } TCCSem;
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ wait_sem(TCCSem *p) {
    ಯದಿ (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } ಅನ್ಯಥಾ {
        ಯಾವತ್ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#ನೋಚೇದ್ಯದಿ defined __APPLE__
#ಅನ್ತರ್ಭಾವ <dispatch/dispatch.h>
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ init; dispatch_semaphore_t sem; } TCCSem;
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ wait_sem(TCCSem *p) {
    ಯದಿ (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <semaphore.h>
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ init; sem_t sem; } TCCSem;
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ wait_sem(TCCSem *p) {
    ಯದಿ (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    ಯಾವತ್ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#ಅನ್ಯಥಾ
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#ಯದಿ ONE_SOURCE
#define ST_DATA ಸ್ಥಿರ
#ಅನ್ಯಥಾ
#define ST_DATA
#endif
/********************************************************/

#define text_section        TCC_STATE_VAR(text_section)
#define data_section        TCC_STATE_VAR(data_section)
#define rodata_section      TCC_STATE_VAR(rodata_section)
#define bss_section         TCC_STATE_VAR(bss_section)
#define common_section      TCC_STATE_VAR(common_section)
#define cur_text_section    TCC_STATE_VAR(cur_text_section)
#define bounds_section      TCC_STATE_VAR(bounds_section)
#define lbounds_section     TCC_STATE_VAR(lbounds_section)
#define symtab_section      TCC_STATE_VAR(symtab_section)
#define gnu_ext             TCC_STATE_VAR(gnu_ext)
#define tcc_error_noabort   TCC_SET_STATE(_tcc_error_noabort)
#define tcc_error           TCC_SET_STATE(_tcc_error)
#define tcc_warning         TCC_SET_STATE(_tcc_warning)

#define total_idents        TCC_STATE_VAR(total_idents)
#define total_ಸಾಲುಗಳು         TCC_STATE_VAR(total_ಸಾಲುಗಳು)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC ಶೂನ್ಯ tcc_enter_state(TCCState *s1);
PUB_FUNC ಶೂನ್ಯ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_ಅಂಕೆ = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#endif /* _TCC_H */

#undef TCC_STATE_VAR
#undef TCC_SET_STATE

#ifdef USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_SET_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#ಅನ್ಯಥಾ
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
