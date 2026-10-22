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
#ଅନ୍ତର୍ଭାଵ "config.h"

#ଅନ୍ତର୍ଭାଵ <stdarg.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <errno.h>
#ଅନ୍ତର୍ଭାଵ <math.h>
#ଅନ୍ତର୍ଭାଵ <fcntl.h>
#ଅନ୍ତର୍ଭାଵ <setjmp.h>
#ଅନ୍ତର୍ଭାଵ <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
ବାହ୍ୟ ଦଶମିକ strtof (ଅଚଳ ଅକ୍ଷର *__nptr, ଅକ୍ଷର **__endptr);
ବାହ୍ୟ long ଦ୍ୱିଗୁଣ strtold (ଅଚଳ ଅକ୍ଷର *__nptr, ଅକ୍ଷର **__endptr);
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
# define ଧାଡ଼ିଭିତରେ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long ଦ୍ୱିଗୁଣ)strtod
#  define strtof (ଦଶମିକ)strtod
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
# ଯଦି defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_ଦ୍ୱିମିକ_2
# define O_ଦ୍ୱିମିକ_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#ଅନ୍ୟଥା
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (ଆକାର(tab) / ଆକାର((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#ଅନ୍ୟଥା
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#ଅନ୍ୟଥା
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
#ଯଦି !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# ଯଦି defined __x86_64__
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
# ଅନ୍ୟଥା
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
#ଯଦି defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# ଯଦି defined __i386__ && defined TCC_TARGET_I386
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

#ଯଦି defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#ଅନ୍ୟଥା
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#ଯଦି defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#ଅନ୍ୟଥା
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#ଯଦି defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#ଅନ୍ୟଥା
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#ଯଦି defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#ନଚେତଯଦି !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#ଯଦି defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#ଅନ୍ୟଥା
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#ଯଦି defined TCC_TARGET_PE \
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

#ଯଦି !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#ଅନ୍ୟଥା
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
# ଯଦି defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# ଅନ୍ୟଥା
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# ଯଦି defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# ଅନ୍ୟଥା
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# ଯଦି defined __GNU__
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
# ଅନ୍ୟଥା
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

#ଅନ୍ତର୍ଭାଵ "libtcc.h"
#ଅନ୍ତର୍ଭାଵ "elf.h"
#ଅନ୍ତର୍ଭାଵ "stab.h"
#ଅନ୍ତର୍ଭାଵ "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#ଯଦି ONE_SOURCE
#define ST_INLN ସ୍ଥିର ଧାଡ଼ିଭିତରେ
#define ST_FUNC ସ୍ଥିର
#define ST_DATA ସ୍ଥିର
#ଅନ୍ୟଥା
#define ST_INLN
#define ST_FUNC
#define ST_DATA ବାହ୍ୟ
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define ସ୍ଥିର
# define ଧାଡ଼ିଭିତରେ
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#ନଚେତଯଦି defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#ନଚେତଯଦି defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#ନଚେତଯଦି defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#ନଚେତଯଦି defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#ନଚେତଯଦି defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#ଅନ୍ୟଥା
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#ଯଦି PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#ଅନ୍ୟଥା
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

#ଯଦି PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#ଅନ୍ୟଥା
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_ଗଦା_SIZE  32
#define IFDEF_ଗଦା_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_ଗଦା_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା TokenSym {
    ସଂରଚନା TokenSym *hash_next;
    ସଂରଚନା Sym *sym_define; /* direct pointer to define */
    ସଂରଚନା Sym *sym_label; /* direct pointer to label */
    ସଂରଚନା Sym *sym_struct; /* direct pointer to structure */
    ସଂରଚନା Sym *sym_identifier; /* direct pointer to identifier */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok; /* token number */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
    ଅକ୍ଷର str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short nwchar_t;
#ଅନ୍ୟଥା
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା nwchar_t;
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା CString {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size; /* size in bytes */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size_allocated;
    ଅକ୍ଷର *data; /* nwchar_t* in cases */
} CString;

/* type definition */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା CType {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    ସଂରଚନା Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_ଶବ୍ଦଗୁଡ଼ିକ ((ଆକାର(long ଦ୍ୱିଗୁଣ)+3)/4)

/* constant value */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ CValue {
    long ଦ୍ୱିଗୁଣ ld;
    ଦ୍ୱିଗୁଣ d;
    ଦଶମିକ f;
    uint64_t i;
    ସଂରଚନା {
        ଅକ୍ଷର *data;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା size;
    } str;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab[LDOUBLE_ଶବ୍ଦଗୁଡ଼ିକ];
} CValue;

/* value on stack */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    ସଂଘ {
      ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    ସଂଘ {
      ସଂରଚନା { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      ସଂରଚନା Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ସଂରଚନା SymAttr {
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
ସଂରଚନା FuncAttr {
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
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା Sym {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ସଂରଚନା SymAttr a; /* symbol attributes */
    ସଂଘ {
        ସଂରଚନା {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା c; /* associated number or Elf symbol index */
            ସଂଘ {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_scope; /* scope level for locals */
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା jnext; /* next jump label */
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା jind; /* label position */
                ସଂରଚନା FuncAttr f; /* function attributes */
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *d; /* define token stream */
        ସଂରଚନା Sym *cleanup_func;
    };

    CType type; /* associated type */
    ସଂଘ {
        ସଂରଚନା Sym *next; /* next related symbol (for fields and anoms) */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *e; /* expanded token stream with preprocessor macros */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_label; /* associated asm label */
        ସଂରଚନା Sym *cleanupstate; /* in defined labels */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *vla_array_str; /* vla array code */
    };
    ସଂରଚନା Sym *prev; /* prev symbol in stack */
    ସଂଘ {
        ସଂରଚନା Sym *prev_tok; /* previous symbol for this token */
        ସଂରଚନା Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ସଂରଚନା Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା Section {
    unsigned long data_offset; /* current data offset */
    unsigned ଅକ୍ଷର *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_name;             /* elf section name (only used during output) */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ;              /* elf section number */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_type;             /* elf section type */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_flags;            /* elf section flags */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_info;             /* elf section info */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_addralign;        /* elf section alignment */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_hashed_syms;      /* used to resize the hash table */
    ସଂରଚନା Section *link;    /* link to another section */
    ସଂରଚନା Section *reloc;   /* corresponding section for relocation, if any */
    ସଂରଚନା Section *hash;    /* hash table for symbols */
    ସଂରଚନା Section *prev;    /* previous section on section stack */
    ଅକ୍ଷର name[1];           /* section name */
} Section;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା DLLReference {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା level;
    ଶୂନ୍ୟ *handle;
    unsigned ଅକ୍ଷର found, index;
    ଅକ୍ଷର name[1];
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd;
    ସଂରଚନା BufferedFile *prev;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_ଅଙ୍କ;    /* current line number - here to simplify code */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_ref;    /* tcc -E: last printed line */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ifndef_macro;  /* #ifndef macro / #endif search */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ifndef_macro_saved; /* saved ifndef_macro */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ifdef_ଗଦା_ptr; /* ifdef_stack value at the start of the file */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା include_next_index; /* next search path */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା prev_tok_flags; /* saved tok_flags */
    ଅକ୍ଷର filename[1024];    /* filename */
    ଅକ୍ଷର *true_filename; /* filename not modified by # line directive */
    unsigned ଅକ୍ଷର unget[4];
    unsigned ଅକ୍ଷର buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା TokenString {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା need_spc;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା allocated_len;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_ଧାଡ଼ି_ଅଙ୍କ;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା save_ଧାଡ଼ି_ଅଙ୍କ;
    /* used to chain token-strings with begin/end_macro() */
    ସଂରଚନା TokenString *prev;
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *prev_ptr;
    ଅକ୍ଷର alloc;
} TokenString;

/* GNUC attribute definition */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା AttributeDef {
    ସଂରଚନା SymAttr a;
    ସଂରଚନା FuncAttr f;
    ସଂରଚନା Section *section;
    Sym *cleanup_func;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା alias_target; /* token */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_label; /* associated asm label */
    ଅକ୍ଷର attr_mode; /* __attribute__((__mode__(...))) */
    ଅକ୍ଷର new_section; /* section is new */
} AttributeDef;

/* inline functions */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା InlineFunc {
    TokenString *func_str;
    Sym *sym;
    ଅକ୍ଷର filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା CachedInclude {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ifndef_macro;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା once;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା hash_next; /* -1 if none */
    ଅକ୍ଷର filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା ପଦସମଷ୍ଟି_ମୂଲ୍ୟ {
    uint64_t v;
    Sym *sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pcrel;
} ପଦସମଷ୍ଟି_ମୂଲ୍ୟ;

#define MAX_ASM_OPERANDS 30
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା ASMOperand {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା id; /* GCC 3 optional identifier (0 if number only supported) */
    ଅକ୍ଷର constraint[16];
    ଅକ୍ଷର asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ref_index; /* if >= 0, gives reference to a output constraint */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ନିବେଶ_index; /* if >= 0, gives reference to an input constraint */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା priority; /* priority, used to assign registers */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg; /* if >= 0, register number used for this operand */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_llong; /* true if double register value */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_memory; /* true if memory operand */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_rw;     /* for '+' modifier */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
ସଂରଚନା sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା plt_sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dyn_index;
    unsigned ଅକ୍ଷର linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned ଅକ୍ଷର plt_thumb_stub:1;
#endif
};

ସଂରଚନା TCCState {
    unsigned ଅକ୍ଷର verbose; /* if true, display some information during compilation */
    unsigned ଅକ୍ଷର nostdinc; /* if true, no standard headers are added */
    unsigned ଅକ୍ଷର nostdlib; /* if true, no standard libraries are added */
    unsigned ଅକ୍ଷର nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned ଅକ୍ଷର nocommon; /* if true, do not use common symbols for .bss data */
    unsigned ଅକ୍ଷର static_link; /* if true, static linking is performed */
    unsigned ଅକ୍ଷର rdynamic; /* if true, all symbols are exported */
    unsigned ଅକ୍ଷର symbolic; /* if true, resolve symbols in the current module first */
    unsigned ଅକ୍ଷର znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned ଅକ୍ଷର filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned ଅକ୍ଷର optimize; /* only to #define __OPTIMIZE__ */
    unsigned ଅକ୍ଷର option_pthread; /* -pthread option */
    unsigned ଅକ୍ଷର enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned ଅକ୍ଷର char_is_unsigned;
    unsigned ଅକ୍ଷର leading_underscore;
    unsigned ଅକ୍ଷର ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned ଅକ୍ଷର dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned ଅକ୍ଷର ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned ଅକ୍ଷର reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned ଅକ୍ଷର gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned ଅକ୍ଷର unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned ଅକ୍ଷର warn_none;
    unsigned ଅକ୍ଷର warn_all;
    unsigned ଅକ୍ଷର warn_error;
    unsigned ଅକ୍ଷର warn_write_strings;
    unsigned ଅକ୍ଷର warn_unsupported;
    unsigned ଅକ୍ଷର warn_implicit_function_declaration;
    unsigned ଅକ୍ଷର warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned ଅକ୍ଷର warn_ଅଙ୍କ; /* temp var for tcc_warning_c() */

    unsigned ଅକ୍ଷର option_r; /* option -r */
    unsigned ଅକ୍ଷର do_bench; /* option -bench */
    unsigned ଅକ୍ଷର just_deps; /* option -M  */
    unsigned ଅକ୍ଷର gen_deps; /* option -MD  */
    unsigned ଅକ୍ଷର include_sys_deps; /* option -MD  */
    unsigned ଅକ୍ଷର gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned ଅକ୍ଷର do_debug;
    unsigned ଅକ୍ଷର dwarf;
    unsigned ଅକ୍ଷର do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned ଅକ୍ଷର do_bounds_check;
#endif
    unsigned ଅକ୍ଷର test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned ଅକ୍ଷର gnu_ext;
    /* use TinyCC extensions */
    unsigned ଅକ୍ଷର tcc_ext;

    unsigned ଅକ୍ଷର dflag; /* -dX value */
    unsigned ଅକ୍ଷର Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned ଅକ୍ଷର nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned ଅକ୍ଷର float_abi; /* float ABI of the generated code*/
#endif

    unsigned ଅକ୍ଷର has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    ଅକ୍ଷର *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    ଅକ୍ଷର *soname; /* as specified on the command line (-soname) */
    ଅକ୍ଷର *rpath; /* as specified on the command line (-Wl,-rpath=) */
    ଅକ୍ଷର *elfint; /* -Wl,-I... on command line */
    ଅକ୍ଷର *elf_entryname; /* "_start" unless set */
    ଅକ୍ଷର *init_ପ୍ରତୀକ; /* symbols to call at load-time (not used currently) */
    ଅକ୍ଷର *fini_ପ୍ରତୀକ; /* symbols to call at unload-time (not used currently) */
    ଅକ୍ଷର *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା output_format;
    /* nth test to run with -dt -run */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_loaded_dlls;

    /* include paths */
    ଅକ୍ଷର **include_paths;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_include_paths;

    ଅକ୍ଷର **sysinclude_paths;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sysinclude_paths;

    /* library paths */
    ଅକ୍ଷର **library_paths;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_library_paths;

    /* crt?.o object path */
    ଅକ୍ଷର **crt_paths;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    ଶୂନ୍ୟ *error_opaque;
    ଶୂନ୍ୟ (*error_func)(ଶୂନ୍ୟ *opaque, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    ଅକ୍ଷର **target_deps;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_target_deps;

    /* compilation */
    BufferedFile *include_ଗଦା[INCLUDE_ଗଦା_SIZE];
    BufferedFile **include_ଗଦା_ptr;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ifdef_ଗଦା[IFDEF_ଗଦା_SIZE];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ifdef_ଗଦା_ptr;

    /* included files enclosed with #ifndef MACRO */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_cached_includes;

    /* #pragma pack stack */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pack_ଗଦା[PACK_ଗଦା_SIZE];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pack_ଗଦା_ptr;
    ଅକ୍ଷର **pragma_libs;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ସଂରଚନା InlineFunc **inline_fns;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_inline_fns;

    /* sections */
    Section **sections;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_priv_sections; /* number of private sections */

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
    ସଂଘ { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_ଧାଡ଼ି_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_ଧାଡ଼ି_str_section;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    ସଂରଚନା _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ସଂରଚନା sym_attr *sym_attrs;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    ସଂରଚନା pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_ଗଦା_size;
    addr_t pe_imagebase;
# ଯଦି defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା uw_sym;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା uw_xsym;
    unsigned uw_offs;
# endif
#endif

#ଯଦି defined TCC_TARGET_MACHO
    ଅକ୍ଷର *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sym_versions;
    ସଂରଚନା sym_version *sym_versions;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_sym_to_version;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *sym_to_version;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    ଅଚଳ ଅକ୍ଷର *run_main; /* entry for tcc_run() */
    ଶୂନ୍ୟ *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    ଅଚଳ ଅକ୍ଷର *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    ଶୂନ୍ୟ *run_function_table; /* unwind data */
#endif
    ସଂରଚନା TCCState *next;
    ସଂରଚନା rt_context *rc; /* pointer to backtrace info block */
    ଶୂନ୍ୟ *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    ଶୂନ୍ୟ *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_ଅଙ୍କ_callers;
#endif

    /* benchmark info */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା total_idents;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା total_ଧାଡ଼ିଗୁଡ଼ିକ;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା total_bytes;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା total_output[4];

    /* used by tcc_load_ldscript */
    unsigned ଅକ୍ଷର *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ଅଚଳ ଅକ୍ଷର *current_filename;

    /* used by main and tcc_parse_args only */
    ସଂରଚନା filespec **files; /* files seen on command line */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_files; /* number thereof */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_libraries; /* number of libs thereof */
    ଅକ୍ଷର *outfile; /* output filename */
    ଅକ୍ଷର *deps_outfile; /* option -MF */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc;
    ଅକ୍ଷର **argv;
    /* -Wl options */
    ଅକ୍ଷର **link_argv;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା link_argc, link_optind;
};

ସଂରଚନା filespec {
    ଅକ୍ଷର type;
    ଅକ୍ଷର name[1];
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

#define TOK_HAS_ମୂଲ୍ୟ(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

ଗଣନା tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#ଅନ୍ତର୍ଭାଵ "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA ସଂରଚନା TCCState *tcc_state;
ST_DATA ଶୂନ୍ୟ** stk_data;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_stk_data;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC ଅକ୍ଷର *pstrcpy(ଅକ୍ଷର *buf, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s);
ST_FUNC ଅକ୍ଷର *pstrcat(ଅକ୍ଷର *buf, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s);
ST_FUNC ଅକ୍ଷର *pstrncpy(ଅକ୍ଷର *out, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s, size_t ଅଙ୍କ);
PUB_FUNC ଅକ୍ଷର *tcc_basename(ଅଚଳ ଅକ୍ଷର *name);
PUB_FUNC ଅକ୍ଷର *tcc_fileextension (ଅଚଳ ଅକ୍ଷର *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC ଶୂନ୍ୟ tcc_free(ଶୂନ୍ୟ *ptr);
PUB_FUNC ଶୂନ୍ୟ *tcc_malloc(unsigned long size);
PUB_FUNC ଶୂନ୍ୟ *tcc_mallocz(unsigned long size);
PUB_FUNC ଶୂନ୍ୟ *tcc_realloc(ଶୂନ୍ୟ *ptr, unsigned long size);
PUB_FUNC ଅକ୍ଷର *tcc_strdup(ଅଚଳ ଅକ୍ଷର *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC ଶୂନ୍ୟ tcc_free_debug(ଶୂନ୍ୟ *ptr);
PUB_FUNC ଶୂନ୍ୟ *tcc_malloc_debug(unsigned long size, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି);
PUB_FUNC ଶୂନ୍ୟ *tcc_mallocz_debug(unsigned long size, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି);
PUB_FUNC ଶୂନ୍ୟ *tcc_realloc_debug(ଶୂନ୍ୟ *ptr, unsigned long size, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି);
PUB_FUNC ଅକ୍ଷର *tcc_strdup_debug(ଅଚଳ ଅକ୍ଷର *str, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି);
#endif

ST_FUNC ଶୂନ୍ୟ libc_free(ଶୂନ୍ୟ *ptr);
/* defined to be not used */
#define ମୁକ୍ତ(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tcc_error_noabort(ଅଚଳ ଅକ୍ଷର *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN ଶୂନ୍ୟ _tcc_error(ଅଚଳ ଅକ୍ଷର *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC ଶୂନ୍ୟ _tcc_warning(ଅଚଳ ଅକ୍ଷର *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(ସନ୍ଦେଶ) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,ସନ୍ଦେଶ)

/* other utilities */
ST_FUNC ଶୂନ୍ୟ dynarray_add(ଶୂନ୍ୟ *ptab, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *nb_ptr, ଶୂନ୍ୟ *data);
ST_FUNC ଶୂନ୍ୟ dynarray_reset(ଶୂନ୍ୟ *pp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *n);
ST_INLN ଶୂନ୍ୟ cstr_ccat(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch);
ST_FUNC ଶୂନ୍ୟ cstr_cat(CString *cstr, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len);
ST_FUNC ଶୂନ୍ୟ cstr_wccat(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch);
ST_FUNC ଶୂନ୍ୟ cstr_new(CString *cstr);
ST_FUNC ଶୂନ୍ୟ cstr_free(CString *cstr);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା cstr_printf(CString *cs, ଅଚଳ ଅକ୍ଷର *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା cstr_vprintf(CString *cstr, ଅଚଳ ଅକ୍ଷର *fmt, va_list ap);
ST_FUNC ଶୂନ୍ୟ cstr_reset(CString *cstr);
ST_FUNC ଶୂନ୍ୟ tcc_open_bf(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା initlen);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_open(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename);
ST_FUNC ଶୂନ୍ୟ tcc_close(ଶୂନ୍ୟ);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_ଠେଲ(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_କାଢ଼() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_ଠେଲ(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_କାଢ଼())

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_file_internal(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
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
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_crt(TCCState *s, ଅଚଳ ଅକ୍ଷର *filename);
#endif
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_dll(TCCState *s, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_support(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC ଶୂନ୍ୟ tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC ଶୂନ୍ୟ tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC ଶୂନ୍ୟ tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_library_err(TCCState *s, ଅଚଳ ଅକ୍ଷର *f);
PUB_FUNC ଶୂନ୍ୟ tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_parse_args(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *argc, ଅକ୍ଷର ***argv);
#ifdef _WIN32
ST_FUNC ଅକ୍ଷର *normalize_slashes(ଅକ୍ଷର *path);
PUB_FUNC FILE *tcc_fopen(ଅଚଳ ଅକ୍ଷର *f, ଅଚଳ ଅକ୍ଷର *m);
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_fclose(FILE *f);
#ଅନ୍ୟଥା
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ଅଚଳ ଅକ୍ଷର *dllname, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level);
ST_FUNC ଅକ୍ଷର *tcc_load_text(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd);
/* for #pragma once */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା normalized_PATHCMP(ଅଚଳ ଅକ୍ଷର *f1, ଅଚଳ ଅକ୍ଷର *f2);

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

ST_DATA ସଂରଚନା BufferedFile *file;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok;
ST_DATA CValue tokc;
ST_DATA ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_ptr;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା parse_flags;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_ପଦସମଷ୍ଟି;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_ଅଙ୍କ    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_ଅଙ୍କ 4

ଗଣନା ଧାଡ଼ି_macro_output_format {
    ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_GCC,
    ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_NONE,
    ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_STD,
    ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_alloc_const(ଅଚଳ ଅକ୍ଷର *str);
ST_FUNC ଅଚଳ ଅକ୍ଷର *get_tok_str(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CValue *cv);
ST_FUNC ଶୂନ୍ୟ begin_macro(TokenString *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା alloc);
ST_FUNC ଶୂନ୍ୟ end_macro(ଶୂନ୍ୟ);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_idnum(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val);
ST_INLN ଶୂନ୍ୟ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ tok_str_free(TokenString *s);
ST_FUNC ଶୂନ୍ୟ tok_str_free_str(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str);
ST_FUNC ଶୂନ୍ୟ tok_str_add(TokenString *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ tok_str_add_tok(TokenString *s);
ST_INLN ଶୂନ୍ୟ define_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା macro_type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str, Sym *first_arg);
ST_FUNC ଶୂନ୍ୟ define_undef(Sym *s);
ST_INLN Sym *define_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC ଶୂନ୍ୟ free_defines(Sym *b);
ST_FUNC ଶୂନ୍ୟ parse_define(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ skip_to_eol(ପୂର୍ଣ୍ଣସଂଖ୍ୟା warn);
ST_FUNC ଶୂନ୍ୟ preprocess(ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_bof);
ST_FUNC ଶୂନ୍ୟ next(ଶୂନ୍ୟ);
ST_INLN ଶୂନ୍ୟ unget_tok(ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_tok);
ST_FUNC ଶୂନ୍ୟ preprocess_start(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା filetype);
ST_FUNC ଶୂନ୍ୟ preprocess_end(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tccpp_new(TCCState *s);
ST_FUNC ଶୂନ୍ୟ tccpp_delete(TCCState *s);
ST_FUNC ଶୂନ୍ୟ tccpp_putfile(ଅଚଳ ଅକ୍ଷର *filename);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_preprocess(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ skip(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC NORETURN ଶୂନ୍ୟ expect(ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ);
ST_FUNC ଶୂନ୍ୟ pp_error(CString *cs);


/* space excluding newline */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_space(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch) {
    ଫେରନ୍ତୁ ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା isid(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c) {
    ଫେରନ୍ତୁ (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା isnum(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c) {
    ଫେରନ୍ତୁ c >= '0' && c <= '9';
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା isoct(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c) {
    ଫେରନ୍ତୁ c >= '0' && c <= '7';
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା toup(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c) {
    ଫେରନ୍ତୁ (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / ଆକାର(Sym))

ST_DATA Sym *global_ଗଦା;
ST_DATA Sym *local_ଗଦା;
ST_DATA Sym *local_label_ଗଦା;
ST_DATA Sym *global_label_ଗଦା;
ST_DATA Sym *define_ଗଦା;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା rsym, anon_sym, ind, loc;
ST_DATA ଅକ୍ଷର debug_modes;

ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା global_ପଦସମଷ୍ଟି;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_var; /* true if current function is variadic */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_vc; /* stack address for implicit struct return storage */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_ind; /* function start address */
ST_DATA ଅଚଳ ଅକ୍ଷର *funcname;

ST_FUNC ଶୂନ୍ୟ tccgen_init(TCCState *s1);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tccgen_compile(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tccgen_finish(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ check_vstack(ଶୂନ୍ୟ);

ST_INLN ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_float(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା ieee_finite(ଦ୍ୱିଗୁଣ d);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା exact_log2p1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i);
ST_FUNC ଶୂନ୍ୟ test_lvalue(ଶୂନ୍ୟ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC ଶୂନ୍ୟ update_storage(Sym *sym);
ST_FUNC ଶୂନ୍ୟ put_extern_sym2(Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ, addr_t ମୂଲ୍ୟ, unsigned long size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା can_add_underscore);
ST_FUNC ଶୂନ୍ୟ put_extern_sym(Sym *sym, Section *section, addr_t ମୂଲ୍ୟ, unsigned long size);
#ଯଦି PTR_SIZE == 4
ST_FUNC ଶୂନ୍ୟ greloc(Section *s, Sym *sym, unsigned long offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type);
#endif
ST_FUNC ଶୂନ୍ୟ greloca(Section *s, Sym *sym, unsigned long offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, addr_t addend);

ST_INLN ଶୂନ୍ୟ sym_free(Sym *sym);
ST_FUNC Sym *sym_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ sym_କାଢ଼(Sym **ptop, Sym *b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା keep);
ST_FUNC Sym *sym_push2(Sym **ps, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC Sym *sym_find2(Sym *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_INLN Sym *sym_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC Sym *label_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC Sym *label_ଠେଲ(Sym **ptop, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
ST_FUNC ଶୂନ୍ୟ label_କାଢ଼(Sym **ptop, Sym *slast, ପୂର୍ଣ୍ଣସଂଖ୍ୟା keep);
ST_INLN Sym *struct_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);

ST_FUNC Sym *global_identifier_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC Sym *external_global_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CType *type);
ST_FUNC Sym *external_helper_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC ଶୂନ୍ୟ vpush_helper_func(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC ଶୂନ୍ୟ vset(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC ଶୂନ୍ୟ vset_VT_CMP(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
ST_FUNC ଶୂନ୍ୟ vpushi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ST_FUNC ଶୂନ୍ୟ vpushv(SValue *v);
ST_FUNC ଶୂନ୍ୟ vpushsym(CType *type, Sym *sym);
ST_FUNC ଶୂନ୍ୟ vswap(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ vrott(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ST_FUNC ଶୂନ୍ୟ vrotb(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ST_FUNC ଶୂନ୍ୟ vrev(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ST_FUNC ଶୂନ୍ୟ vpop(ଶୂନ୍ୟ);
#ଯଦି PTR_SIZE == 4
ST_FUNC ଶୂନ୍ୟ lexpand(ଶୂନ୍ୟ);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_reg_ex(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc2);
#endif
ST_FUNC ଶୂନ୍ୟ save_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r);
ST_FUNC ଶୂନ୍ୟ save_reg_upstack(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା get_reg(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc);
ST_FUNC ଶୂନ୍ୟ save_regs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ST_FUNC ଶୂନ୍ୟ gaddrof(ଶୂନ୍ୟ);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc);
ST_FUNC ଶୂନ୍ୟ gv2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା rc2);
ST_FUNC ଶୂନ୍ୟ gen_op(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା type_size(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *a);
ST_FUNC ଶୂନ୍ୟ mk_pointer(CType *type);
ST_FUNC ଶୂନ୍ୟ vstore(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ inc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା post, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC CString* parse_mult_str(ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ);
ST_FUNC CString* parse_asm_str(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ indir(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ unary(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gexpr(ଶୂନ୍ୟ);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା ପଦସମଷ୍ଟି_const(ଶୂନ୍ୟ);
#ଯଦି defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#ଯଦି defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC ଶୂନ୍ୟ gbound_args(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args);
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_ଦ୍ୱିମିକ 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_strx;         /* index into string table of name */
    unsigned ଅକ୍ଷର n_type;         /* type of symbol */
    unsigned ଅକ୍ଷର n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_ମୂଲ୍ୟ;        /* value of symbol */
} Stab_Sym;

ST_FUNC ଶୂନ୍ୟ tccelf_new(TCCState *s);
ST_FUNC ଶୂନ୍ୟ tccelf_delete(TCCState *s);
ST_FUNC ଶୂନ୍ୟ tccelf_begin_file(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ଅଚଳ ଅକ୍ଷର *name, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_flags);
ST_FUNC ଶୂନ୍ୟ section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା align);
ST_FUNC ଶୂନ୍ୟ *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, ଅଚଳ ଅକ୍ଷର *name);
ST_FUNC ଶୂନ୍ୟ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ଅଚଳ ଅକ୍ଷର *symtab_name, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_flags, ଅଚଳ ଅକ୍ଷର *strtab_name, ଅଚଳ ଅକ୍ଷର *hash_name, ପୂର୍ଣ୍ଣସଂଖ୍ୟା hash_sh_flags);
ST_FUNC ଶୂନ୍ୟ init_symtab(Section *s);

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା put_elf_str(Section *s, ଅଚଳ ଅକ୍ଷର *sym);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା put_elf_sym(Section *s, addr_t ମୂଲ୍ୟ, unsigned long size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା info, ପୂର୍ଣ୍ଣସଂଖ୍ୟା other, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shndx, ଅଚଳ ଅକ୍ଷର *name);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_elf_sym(Section *s, addr_t ମୂଲ୍ୟ, unsigned long size, ପୂର୍ଣ୍ଣସଂଖ୍ୟା info, ପୂର୍ଣ୍ଣସଂଖ୍ୟା other, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shndx, ଅଚଳ ଅକ୍ଷର *name);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା find_elf_sym(Section *s, ଅଚଳ ଅକ୍ଷର *name);
ST_FUNC ଶୂନ୍ୟ put_elf_reloc(Section *symtab, Section *s, unsigned long offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ପ୍ରତୀକ);
ST_FUNC ଶୂନ୍ୟ put_elf_reloca(Section *symtab, Section *s, unsigned long offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ପ୍ରତୀକ, addr_t addend);

ST_FUNC ଶୂନ୍ୟ resolve_common_syms(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ relocate_syms(TCCState *s1, Section *symtab, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_resolve);
ST_FUNC ଶୂନ୍ୟ relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଶୂନ୍ୟ *buf, size_t ଗଣନା_3);
ST_FUNC ଶୂନ୍ୟ *load_data(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, unsigned long file_offset, unsigned long size);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_object_type(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ElfW(Ehdr) *h);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_load_object_file(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, unsigned long file_offset);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_load_archive(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ପୂର୍ଣ୍ଣସଂଖ୍ୟା alacarte);
ST_FUNC ଶୂନ୍ୟ add_array(TCCState *s1, ଅଚଳ ଅକ୍ଷର *sec, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);

ST_FUNC ସଂରଚନା sym_attr *get_sym_attr(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା index, ପୂର୍ଣ୍ଣସଂଖ୍ୟା alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ଅଚଳ ଅକ୍ଷର *name, ପୂର୍ଣ୍ଣସଂଖ୍ୟା err, ପୂର୍ଣ୍ଣସଂଖ୍ୟା forc);
ST_FUNC ଶୂନ୍ୟ list_elf_symbols(TCCState *s, ଶୂନ୍ୟ *ctx,
    ଶୂନ୍ୟ (*ପ୍ରତୀକ_cb)(ଶୂନ୍ୟ *ctx, ଅଚଳ ଅକ୍ଷର *name, ଅଚଳ ଶୂନ୍ୟ *val));
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_global_sym(TCCState *s1, ଅଚଳ ଅକ୍ଷର *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    ପାଇଁ (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_load_dll(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_load_ldscript(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd);
ST_FUNC ଶୂନ୍ୟ tccelf_add_crtbegin(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC ଶୂନ୍ୟ tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା code_reloc (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gotplt_entry_type (ପୂର୍ଣ୍ଣସଂଖ୍ୟା reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
ଗଣନା gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#ଯଦି !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ସଂରଚନା sym_attr *attr);
ST_FUNC ଶୂନ୍ୟ relocate_plt(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ build_got_entries(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC ଶୂନ୍ୟ relocate(TCCState *s1, ElfW_Rel *rel, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, unsigned ଅକ୍ଷର *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA ଅଚଳ ଅକ୍ଷର * ଅଚଳ target_machine_defs;
ST_DATA ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା reg_classes[NB_REGS];

ST_FUNC ଶୂନ୍ୟ gsym_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a);
ST_FUNC ଶୂନ୍ୟ gsym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ load(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *sv);
ST_FUNC ଶୂନ୍ୟ store(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, SValue *v);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gfunc_sret(CType *vt, ପୂର୍ଣ୍ଣସଂଖ୍ୟା variadic, CType *ret, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *align, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *regsize);
ST_FUNC ଶୂନ୍ୟ gfunc_call(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_args);
ST_FUNC ଶୂନ୍ୟ gfunc_prolog(Sym *func_sym);
ST_FUNC ଶୂନ୍ୟ gfunc_epilog(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gen_fill_nops(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gjmp_addr(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp_cond(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gjmp_append(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gen_opi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
ST_FUNC ଶୂନ୍ୟ gen_opf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
ST_FUNC ଶୂନ୍ୟ gen_cvt_ftoi(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gen_cvt_itof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gen_cvt_ftof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ ggoto(ଶୂନ୍ୟ);
#ifndef TCC_TARGET_C67
ST_FUNC ଶୂନ୍ୟ o(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
#endif
ST_FUNC ଶୂନ୍ୟ gen_vla_sp_save(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr);
ST_FUNC ଶୂନ୍ୟ gen_vla_sp_restore(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr);
ST_FUNC ଶୂନ୍ୟ gen_vla_alloc(CType *type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା align);

ସ୍ଥିର ଧାଡ଼ିଭିତରେ uint16_t read16le(unsigned ଅକ୍ଷର *p) {
    ଫେରନ୍ତୁ p[0] | (uint16_t)p[1] << 8;
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ write16le(unsigned ଅକ୍ଷର *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ uint32_t read32le(unsigned ଅକ୍ଷର *p) {
  ଫେରନ୍ତୁ read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ write32le(unsigned ଅକ୍ଷର *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ add32le(unsigned ଅକ୍ଷର *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ uint64_t read64le(unsigned ଅକ୍ଷର *p) {
  ଫେରନ୍ତୁ read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ write64le(unsigned ଅକ୍ଷର *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ add64le(unsigned ଅକ୍ଷର *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#ଯଦି defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC ଶୂନ୍ୟ g(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_le16(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_le32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
#endif
#ଯଦି defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC ଶୂନ୍ୟ gen_addr32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_addrpc32(ପୂର୍ଣ୍ଣସଂଖ୍ୟା r, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);
ST_FUNC ଶୂନ୍ୟ gen_cvt_csti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC ଶୂନ୍ୟ gen_opl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
#ifdef TCC_TARGET_PE
ST_FUNC ଶୂନ୍ୟ gen_vla_result(ପୂର୍ଣ୍ଣସଂଖ୍ୟା addr);
#endif
ST_FUNC ଶୂନ୍ୟ gen_cvt_sxtw(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gen_cvt_csti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#ଯଦି defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ଅଚଳ ଅକ୍ଷର *default_elfinterp(ସଂରଚନା TCCState *s);
#endif
ST_FUNC ଶୂନ୍ୟ arm_init(ସଂରଚନା TCCState *s);
ST_FUNC ଶୂନ୍ୟ gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC ଶୂନ୍ୟ gen_opl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
ST_FUNC ଶୂନ୍ୟ gfunc_return(CType *func_type);
ST_FUNC ଶୂନ୍ୟ gen_va_start(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gen_va_arg(CType *t);
ST_FUNC ଶୂନ୍ୟ gen_clear_cache(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gen_cvt_sxtw(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gen_cvt_csti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC ଶୂନ୍ୟ gen_opl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା op);
ST_FUNC ଶୂନ୍ୟ gen_va_start(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ arch_transfer_ret_regs(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
ST_FUNC ଶୂନ୍ୟ gen_cvt_sxtw(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ gen_cvt_csti(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ gen_increment_tcov (SValue *sv);
ST_FUNC ଶୂନ୍ୟ gen_clear_cache(ଶୂନ୍ୟ);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_load_coff(TCCState * s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC ଶୂନ୍ୟ asm_instr(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ asm_global_instr(ଶୂନ୍ୟ);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_assemble(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା find_constraint(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ଅଚଳ ଅକ୍ଷର *name, ଅଚଳ ଅକ୍ଷର **pp);
ST_FUNC Sym* get_asm_sym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା name, Sym *csym);
ST_FUNC ଶୂନ୍ୟ asm_ପଦସମଷ୍ଟି(TCCState *s1, ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_int_ପଦସମଷ୍ଟି(TCCState *s1);
#ଯଦି PTR_SIZE == 8
ST_FUNC ଶୂନ୍ୟ gen_expr64(ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC ଶୂନ୍ୟ gen_expr32(ପଦସମଷ୍ଟି_ମୂଲ୍ୟ *pe);
ST_FUNC ଶୂନ୍ୟ asm_opcode(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା opcode);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା asm_parse_regvar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t);
ST_FUNC ଶୂନ୍ୟ asm_compute_constraints(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, ଅଚଳ uint8_t *clobber_regs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pout_reg);
ST_FUNC ଶୂନ୍ୟ subst_asm_operand(CString *add_str, SValue *sv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା modifier);
ST_FUNC ଶୂନ୍ୟ asm_gen_code(ASMOperand *operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_operands, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_outputs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_output, uint8_t *clobber_regs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା out_reg);
ST_FUNC ଶୂନ୍ୟ asm_clobber(uint8_t *clobber_regs, ଅଚଳ ଅକ୍ଷର *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_load_file(ସଂରଚନା TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *filename);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_output_file(TCCState * s1, ଅଚଳ ଅକ୍ଷର *filename);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_putimport(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dllindex, ଅଚଳ ଅକ୍ଷର *name, addr_t ମୂଲ୍ୟ);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା pe_setsubsy(TCCState *s1, ଅଚଳ ଅକ୍ଷର *arg);
#ଯଦି defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#ଯଦି defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC ଶୂନ୍ୟ pe_add_unwind_data(unsigned start, unsigned end, unsigned ଗଦା);
#endif
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_get_dllexports(ଅଚଳ ଅକ୍ଷର *filename, ଅକ୍ଷର **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା macho_output_file(TCCState * s1, ଅଚଳ ଅକ୍ଷର *filename);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା macho_load_dll(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା lev);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା macho_load_tbd(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା lev);
#ifdef TCC_IS_NATIVE
ST_FUNC ଶୂନ୍ୟ tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC ଅକ୍ଷର* macho_tbd_soname(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    ଖାଲି
/* dummy function for profiling */
ST_FUNC ଶୂନ୍ୟ *dlopen(ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flag);
ST_FUNC ଶୂନ୍ୟ dlclose(ଶୂନ୍ୟ *p);
ST_FUNC ଅଚଳ ଅକ୍ଷର *dlerror(ଶୂନ୍ୟ);
ST_FUNC ଶୂନ୍ୟ *dlsym(ଶୂନ୍ୟ *handle, ଅଚଳ ଅକ୍ଷର *ପ୍ରତୀକ);
#endif
ST_FUNC ଶୂନ୍ୟ tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#ଯଦି 0 /* included in tcc.c */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_ar(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv);
#ifdef TCC_TARGET_PE
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_impdef(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv);
#endif
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_tool_cross(TCCState *s, ଅକ୍ଷର **argv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା option);
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା gen_makedeps(TCCState *s, ଅଚଳ ଅକ୍ଷର *target, ଅଚଳ ଅକ୍ଷର *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC ଶୂନ୍ୟ tcc_debug_new(TCCState *s);

ST_FUNC ଶୂନ୍ୟ tcc_debug_start(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_debug_end(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_debug_bincl(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_debug_eincl(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_debug_newfile(TCCState *s1);

ST_FUNC ଶୂନ୍ୟ tcc_debug_ଧାଡ଼ି(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC ଶୂନ୍ୟ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC ଶୂନ୍ୟ tcc_debug_prolog_epilog(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ);
ST_FUNC ଶୂନ୍ୟ tcc_debug_funcend(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size);
ST_FUNC ଶୂନ୍ୟ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sh_ଅଙ୍କ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_bind, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_type);
ST_FUNC ଶୂନ୍ୟ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC ଶୂନ୍ୟ tcc_debug_stabn(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ);
ST_FUNC ଶୂନ୍ୟ tcc_debug_fix_forw(TCCState *s1, CType *t);

#ଯଦି !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC ଶୂନ୍ୟ tcc_eh_frame_start(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_eh_frame_end(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_eh_frame_hdr(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC ଶୂନ୍ୟ tcc_tcov_start(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_tcov_end(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_tcov_check_ଧାଡ଼ି(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା start);
ST_FUNC ଶୂନ୍ୟ tcc_tcov_block_end(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି);
ST_FUNC ଶୂନ୍ୟ tcc_tcov_block_begin(TCCState *s1);
ST_FUNC ଶୂନ୍ୟ tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_ଧାଡ଼ି_section      s1->dwarf_ଧାଡ଼ି_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_ଧାଡ଼ି_str_section  s1->dwarf_ଧାଡ଼ି_str_section

#define DWARF_MAX_128	((8 * ଆକାର (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
ସ୍ଥିର ଧାଡ଼ିଭିତରେ uint64_t
dwarf_read_uleb128(unsigned ଅକ୍ଷର **ln, unsigned ଅକ୍ଷର *end)
{
    unsigned ଅକ୍ଷର *cp = *ln;
    uint64_t retval = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	ଯଦି ((byte & 0x80) == 0)
	    ଭାଙ୍ଗ;
    }
    *ln = cp;
    ଫେରନ୍ତୁ retval;
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ int64_t
dwarf_read_sleb128(unsigned ଅକ୍ଷର **ln, unsigned ଅକ୍ଷର *end)
{
    unsigned ଅକ୍ଷର *cp = *ln;
    int64_t retval = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	ଯଦି ((byte & 0x80) == 0) {
	    ଯଦି ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    ଭାଙ୍ଗ;
	}
    }
    *ln = cp;
    ଫେରନ୍ତୁ retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#ଅନ୍ୟଥା
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#ଯଦି defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#ଅନ୍ୟଥା
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#ଯଦି CONFIG_TCC_SEMLOCK
#ଯଦି defined _WIN32
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ଅସ୍ଥିର LONG init; CRITICAL_SECTION cs; } TCCSem;
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ wait_sem(TCCSem *p) {
    ଯଦି (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } ଅନ୍ୟଥା {
        ଯେତେବେଳେ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#ନଚେତଯଦି defined __APPLE__
#ଅନ୍ତର୍ଭାଵ <dispatch/dispatch.h>
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା init; dispatch_semaphore_t sem; } TCCSem;
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ wait_sem(TCCSem *p) {
    ଯଦି (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <semaphore.h>
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା init; sem_t sem; } TCCSem;
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ wait_sem(TCCSem *p) {
    ଯଦି (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    ଯେତେବେଳେ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#ଅନ୍ୟଥା
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#ଯଦି ONE_SOURCE
#define ST_DATA ସ୍ଥିର
#ଅନ୍ୟଥା
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
#define total_ଧାଡ଼ିଗୁଡ଼ିକ         TCC_STATE_VAR(total_ଧାଡ଼ିଗୁଡ଼ିକ)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC ଶୂନ୍ୟ tcc_enter_state(TCCState *s1);
PUB_FUNC ଶୂନ୍ୟ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_ଅଙ୍କ = offsetof(TCCState, sw) \
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
#ଅନ୍ୟଥା
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
