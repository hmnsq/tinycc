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
#അന്തര്ഭാവ "config.h"

#അന്തര്ഭാവ <stdarg.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <errno.h>
#അന്തര്ഭാവ <math.h>
#അന്തര്ഭാവ <fcntl.h>
#അന്തര്ഭാവ <setjmp.h>
#അന്തര്ഭാവ <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
ബാഹ്യ ദശാംശം strtof (സ്ഥിരം അക്ഷരം *__nptr, അക്ഷരം **__endptr);
ബാഹ്യ long ഇരട്ട strtold (സ്ഥിരം അക്ഷരം *__nptr, അക്ഷരം **__endptr);
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
# define വരിയിൽ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long ഇരട്ട)strtod
#  define strtof (ദശാംശം)strtod
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
# എങ്കിൽ defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_ദ്വിമാന_2
# define O_ദ്വിമാന_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#അല്ലെങ്കിൽ
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (വലുപ്പം(tab) / വലുപ്പം((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#അല്ലെങ്കിൽ
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#അല്ലെങ്കിൽ
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
#എങ്കിൽ !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# എങ്കിൽ defined __x86_64__
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
# അല്ലെങ്കിൽ
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
#എങ്കിൽ defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# എങ്കിൽ defined __i386__ && defined TCC_TARGET_I386
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

#എങ്കിൽ defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#അല്ലെങ്കിൽ
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#എങ്കിൽ defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#അല്ലെങ്കിൽ
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#എങ്കിൽ defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#അല്ലെങ്കിൽ
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#എങ്കിൽ defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#അല്ലെങ്കിലെങ്കിൽ !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#എങ്കിൽ defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#അല്ലെങ്കിൽ
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#എങ്കിൽ defined TCC_TARGET_PE \
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

#എങ്കിൽ !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#അല്ലെങ്കിൽ
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
# എങ്കിൽ defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# അല്ലെങ്കിൽ
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# എങ്കിൽ defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# അല്ലെങ്കിൽ
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# എങ്കിൽ defined __GNU__
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
# അല്ലെങ്കിൽ
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

#അന്തര്ഭാവ "libtcc.h"
#അന്തര്ഭാവ "elf.h"
#അന്തര്ഭാവ "stab.h"
#അന്തര്ഭാവ "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#എങ്കിൽ ONE_SOURCE
#define ST_INLN സ്ഥിതം വരിയിൽ
#define ST_FUNC സ്ഥിതം
#define ST_DATA സ്ഥിതം
#അല്ലെങ്കിൽ
#define ST_INLN
#define ST_FUNC
#define ST_DATA ബാഹ്യ
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define സ്ഥിതം
# define വരിയിൽ
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#അല്ലെങ്കിൽ
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#എങ്കിൽ PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#അല്ലെങ്കിൽ
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

#എങ്കിൽ PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#അല്ലെങ്കിൽ
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_അട്ടി_SIZE  32
#define IFDEF_അട്ടി_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_അട്ടി_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
തരനിർവചനം ഘടന TokenSym {
    ഘടന TokenSym *hash_next;
    ഘടന Sym *sym_define; /* direct pointer to define */
    ഘടന Sym *sym_label; /* direct pointer to label */
    ഘടന Sym *sym_struct; /* direct pointer to structure */
    ഘടന Sym *sym_identifier; /* direct pointer to identifier */
    പൂർണ്ണസംഖ്യ tok; /* token number */
    പൂർണ്ണസംഖ്യ len;
    അക്ഷരം str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
തരനിർവചനം unsigned short nwchar_t;
#അല്ലെങ്കിൽ
തരനിർവചനം പൂർണ്ണസംഖ്യ nwchar_t;
#endif

തരനിർവചനം ഘടന CString {
    പൂർണ്ണസംഖ്യ size; /* size in bytes */
    പൂർണ്ണസംഖ്യ size_allocated;
    അക്ഷരം *data; /* nwchar_t* in cases */
} CString;

/* type definition */
തരനിർവചനം ഘടന CType {
    പൂർണ്ണസംഖ്യ t;
    ഘടന Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_വാക്കുകൾ ((വലുപ്പം(long ഇരട്ട)+3)/4)

/* constant value */
തരനിർവചനം സംഘം CValue {
    long ഇരട്ട ld;
    ഇരട്ട d;
    ദശാംശം f;
    uint64_t i;
    ഘടന {
        അക്ഷരം *data;
        പൂർണ്ണസംഖ്യ size;
    } str;
    പൂർണ്ണസംഖ്യ tab[LDOUBLE_വാക്കുകൾ];
} CValue;

/* value on stack */
തരനിർവചനം ഘടന SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    സംഘം {
      ഘടന { പൂർണ്ണസംഖ്യ jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    സംഘം {
      ഘടന { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      ഘടന Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ഘടന SymAttr {
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
ഘടന FuncAttr {
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
തരനിർവചനം ഘടന Sym {
    പൂർണ്ണസംഖ്യ v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ഘടന SymAttr a; /* symbol attributes */
    സംഘം {
        ഘടന {
            പൂർണ്ണസംഖ്യ c; /* associated number or Elf symbol index */
            സംഘം {
                പൂർണ്ണസംഖ്യ sym_scope; /* scope level for locals */
                പൂർണ്ണസംഖ്യ jnext; /* next jump label */
                പൂർണ്ണസംഖ്യ jind; /* label position */
                ഘടന FuncAttr f; /* function attributes */
                പൂർണ്ണസംഖ്യ auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        പൂർണ്ണസംഖ്യ *d; /* define token stream */
        ഘടന Sym *cleanup_func;
    };

    CType type; /* associated type */
    സംഘം {
        ഘടന Sym *next; /* next related symbol (for fields and anoms) */
        പൂർണ്ണസംഖ്യ *e; /* expanded token stream with preprocessor macros */
        പൂർണ്ണസംഖ്യ asm_label; /* associated asm label */
        ഘടന Sym *cleanupstate; /* in defined labels */
        പൂർണ്ണസംഖ്യ *vla_array_str; /* vla array code */
    };
    ഘടന Sym *prev; /* prev symbol in stack */
    സംഘം {
        ഘടന Sym *prev_tok; /* previous symbol for this token */
        ഘടന Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ഘടന Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
തരനിർവചനം ഘടന Section {
    unsigned long data_offset; /* current data offset */
    unsigned അക്ഷരം *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    പൂർണ്ണസംഖ്യ sh_name;             /* elf section name (only used during output) */
    പൂർണ്ണസംഖ്യ sh_അക്കം;              /* elf section number */
    പൂർണ്ണസംഖ്യ sh_type;             /* elf section type */
    പൂർണ്ണസംഖ്യ sh_flags;            /* elf section flags */
    പൂർണ്ണസംഖ്യ sh_info;             /* elf section info */
    പൂർണ്ണസംഖ്യ sh_addralign;        /* elf section alignment */
    പൂർണ്ണസംഖ്യ sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    പൂർണ്ണസംഖ്യ nb_hashed_syms;      /* used to resize the hash table */
    ഘടന Section *link;    /* link to another section */
    ഘടന Section *reloc;   /* corresponding section for relocation, if any */
    ഘടന Section *hash;    /* hash table for symbols */
    ഘടന Section *prev;    /* previous section on section stack */
    അക്ഷരം name[1];           /* section name */
} Section;

തരനിർവചനം ഘടന DLLReference {
    പൂർണ്ണസംഖ്യ level;
    ശൂന്യം *handle;
    unsigned അക്ഷരം found, index;
    അക്ഷരം name[1];
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

തരനിർവചനം ഘടന BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    പൂർണ്ണസംഖ്യ fd;
    ഘടന BufferedFile *prev;
    പൂർണ്ണസംഖ്യ വരി_അക്കം;    /* current line number - here to simplify code */
    പൂർണ്ണസംഖ്യ വരി_ref;    /* tcc -E: last printed line */
    പൂർണ്ണസംഖ്യ ifndef_macro;  /* #ifndef macro / #endif search */
    പൂർണ്ണസംഖ്യ ifndef_macro_saved; /* saved ifndef_macro */
    പൂർണ്ണസംഖ്യ *ifdef_അട്ടി_ptr; /* ifdef_stack value at the start of the file */
    പൂർണ്ണസംഖ്യ include_next_index; /* next search path */
    പൂർണ്ണസംഖ്യ prev_tok_flags; /* saved tok_flags */
    അക്ഷരം filename[1024];    /* filename */
    അക്ഷരം *true_filename; /* filename not modified by # line directive */
    unsigned അക്ഷരം unget[4];
    unsigned അക്ഷരം buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
തരനിർവചനം ഘടന TokenString {
    പൂർണ്ണസംഖ്യ *str;
    പൂർണ്ണസംഖ്യ len;
    പൂർണ്ണസംഖ്യ need_spc;
    പൂർണ്ണസംഖ്യ allocated_len;
    പൂർണ്ണസംഖ്യ last_വരി_അക്കം;
    പൂർണ്ണസംഖ്യ save_വരി_അക്കം;
    /* used to chain token-strings with begin/end_macro() */
    ഘടന TokenString *prev;
    സ്ഥിരം പൂർണ്ണസംഖ്യ *prev_ptr;
    അക്ഷരം alloc;
} TokenString;

/* GNUC attribute definition */
തരനിർവചനം ഘടന AttributeDef {
    ഘടന SymAttr a;
    ഘടന FuncAttr f;
    ഘടന Section *section;
    Sym *cleanup_func;
    പൂർണ്ണസംഖ്യ alias_target; /* token */
    പൂർണ്ണസംഖ്യ asm_label; /* associated asm label */
    അക്ഷരം attr_mode; /* __attribute__((__mode__(...))) */
    അക്ഷരം new_section; /* section is new */
} AttributeDef;

/* inline functions */
തരനിർവചനം ഘടന InlineFunc {
    TokenString *func_str;
    Sym *sym;
    അക്ഷരം filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
തരനിർവചനം ഘടന CachedInclude {
    പൂർണ്ണസംഖ്യ ifndef_macro;
    പൂർണ്ണസംഖ്യ once;
    പൂർണ്ണസംഖ്യ hash_next; /* -1 if none */
    അക്ഷരം filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
തരനിർവചനം ഘടന വ്യഞ്ജകം_മൂല്യം {
    uint64_t v;
    Sym *sym;
    പൂർണ്ണസംഖ്യ pcrel;
} വ്യഞ്ജകം_മൂല്യം;

#define MAX_ASM_OPERANDS 30
തരനിർവചനം ഘടന ASMOperand {
    പൂർണ്ണസംഖ്യ id; /* GCC 3 optional identifier (0 if number only supported) */
    അക്ഷരം constraint[16];
    അക്ഷരം asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    പൂർണ്ണസംഖ്യ ref_index; /* if >= 0, gives reference to a output constraint */
    പൂർണ്ണസംഖ്യ നിവേശം_index; /* if >= 0, gives reference to an input constraint */
    പൂർണ്ണസംഖ്യ priority; /* priority, used to assign registers */
    പൂർണ്ണസംഖ്യ reg; /* if >= 0, register number used for this operand */
    പൂർണ്ണസംഖ്യ is_llong; /* true if double register value */
    പൂർണ്ണസംഖ്യ is_memory; /* true if memory operand */
    പൂർണ്ണസംഖ്യ is_rw;     /* for '+' modifier */
    പൂർണ്ണസംഖ്യ is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
ഘടന sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    പൂർണ്ണസംഖ്യ plt_sym;
    പൂർണ്ണസംഖ്യ dyn_index;
    unsigned അക്ഷരം linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned അക്ഷരം plt_thumb_stub:1;
#endif
};

ഘടന TCCState {
    unsigned അക്ഷരം verbose; /* if true, display some information during compilation */
    unsigned അക്ഷരം nostdinc; /* if true, no standard headers are added */
    unsigned അക്ഷരം nostdlib; /* if true, no standard libraries are added */
    unsigned അക്ഷരം nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned അക്ഷരം nocommon; /* if true, do not use common symbols for .bss data */
    unsigned അക്ഷരം static_link; /* if true, static linking is performed */
    unsigned അക്ഷരം rdynamic; /* if true, all symbols are exported */
    unsigned അക്ഷരം symbolic; /* if true, resolve symbols in the current module first */
    unsigned അക്ഷരം znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned അക്ഷരം filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned അക്ഷരം optimize; /* only to #define __OPTIMIZE__ */
    unsigned അക്ഷരം option_pthread; /* -pthread option */
    unsigned അക്ഷരം enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned പൂർണ്ണസംഖ്യ  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned അക്ഷരം char_is_unsigned;
    unsigned അക്ഷരം leading_underscore;
    unsigned അക്ഷരം ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned അക്ഷരം dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned അക്ഷരം ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned അക്ഷരം reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned അക്ഷരം gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned അക്ഷരം unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned അക്ഷരം warn_none;
    unsigned അക്ഷരം warn_all;
    unsigned അക്ഷരം warn_error;
    unsigned അക്ഷരം warn_write_strings;
    unsigned അക്ഷരം warn_unsupported;
    unsigned അക്ഷരം warn_implicit_function_declaration;
    unsigned അക്ഷരം warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned അക്ഷരം warn_അക്കം; /* temp var for tcc_warning_c() */

    unsigned അക്ഷരം option_r; /* option -r */
    unsigned അക്ഷരം do_bench; /* option -bench */
    unsigned അക്ഷരം just_deps; /* option -M  */
    unsigned അക്ഷരം gen_deps; /* option -MD  */
    unsigned അക്ഷരം include_sys_deps; /* option -MD  */
    unsigned അക്ഷരം gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned അക്ഷരം do_debug;
    unsigned അക്ഷരം dwarf;
    unsigned അക്ഷരം do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned അക്ഷരം do_bounds_check;
#endif
    unsigned അക്ഷരം test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned അക്ഷരം gnu_ext;
    /* use TinyCC extensions */
    unsigned അക്ഷരം tcc_ext;

    unsigned അക്ഷരം dflag; /* -dX value */
    unsigned അക്ഷരം Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned അക്ഷരം nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned അക്ഷരം float_abi; /* float ABI of the generated code*/
#endif

    unsigned അക്ഷരം has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    പൂർണ്ണസംഖ്യ seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    അക്ഷരം *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    അക്ഷരം *soname; /* as specified on the command line (-soname) */
    അക്ഷരം *rpath; /* as specified on the command line (-Wl,-rpath=) */
    അക്ഷരം *elfint; /* -Wl,-I... on command line */
    അക്ഷരം *elf_entryname; /* "_start" unless set */
    അക്ഷരം *init_ചിഹ്നം; /* symbols to call at load-time (not used currently) */
    അക്ഷരം *fini_ചിഹ്നം; /* symbols to call at unload-time (not used currently) */
    അക്ഷരം *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    പൂർണ്ണസംഖ്യ output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    പൂർണ്ണസംഖ്യ output_format;
    /* nth test to run with -dt -run */
    പൂർണ്ണസംഖ്യ run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    പൂർണ്ണസംഖ്യ nb_loaded_dlls;

    /* include paths */
    അക്ഷരം **include_paths;
    പൂർണ്ണസംഖ്യ nb_include_paths;

    അക്ഷരം **sysinclude_paths;
    പൂർണ്ണസംഖ്യ nb_sysinclude_paths;

    /* library paths */
    അക്ഷരം **library_paths;
    പൂർണ്ണസംഖ്യ nb_library_paths;

    /* crt?.o object path */
    അക്ഷരം **crt_paths;
    പൂർണ്ണസംഖ്യ nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    ശൂന്യം *error_opaque;
    ശൂന്യം (*error_func)(ശൂന്യം *opaque, സ്ഥിരം അക്ഷരം *സന്ദേശം);
    പൂർണ്ണസംഖ്യ error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    പൂർണ്ണസംഖ്യ nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    അക്ഷരം **target_deps;
    പൂർണ്ണസംഖ്യ nb_target_deps;

    /* compilation */
    BufferedFile *include_അട്ടി[INCLUDE_അട്ടി_SIZE];
    BufferedFile **include_അട്ടി_ptr;

    പൂർണ്ണസംഖ്യ ifdef_അട്ടി[IFDEF_അട്ടി_SIZE];
    പൂർണ്ണസംഖ്യ *ifdef_അട്ടി_ptr;

    /* included files enclosed with #ifndef MACRO */
    പൂർണ്ണസംഖ്യ cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    പൂർണ്ണസംഖ്യ nb_cached_includes;

    /* #pragma pack stack */
    പൂർണ്ണസംഖ്യ pack_അട്ടി[PACK_അട്ടി_SIZE];
    പൂർണ്ണസംഖ്യ *pack_അട്ടി_ptr;
    അക്ഷരം **pragma_libs;
    പൂർണ്ണസംഖ്യ nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ഘടന InlineFunc **inline_fns;
    പൂർണ്ണസംഖ്യ nb_inline_fns;

    /* sections */
    Section **sections;
    പൂർണ്ണസംഖ്യ nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    പൂർണ്ണസംഖ്യ nb_priv_sections; /* number of private sections */

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
    സംഘം { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_വരി_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_വരി_str_section;
    പൂർണ്ണസംഖ്യ dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    ഘടന _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ഘടന sym_attr *sym_attrs;
    പൂർണ്ണസംഖ്യ nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    ഘടന pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    പൂർണ്ണസംഖ്യ nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    പൂർണ്ണസംഖ്യ pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_അട്ടി_size;
    addr_t pe_imagebase;
# എങ്കിൽ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    പൂർണ്ണസംഖ്യ uw_sym;
    പൂർണ്ണസംഖ്യ uw_xsym;
    unsigned uw_offs;
# endif
#endif

#എങ്കിൽ defined TCC_TARGET_MACHO
    അക്ഷരം *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    പൂർണ്ണസംഖ്യ nb_sym_versions;
    ഘടന sym_version *sym_versions;
    പൂർണ്ണസംഖ്യ nb_sym_to_version;
    പൂർണ്ണസംഖ്യ *sym_to_version;
    പൂർണ്ണസംഖ്യ dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    സ്ഥിരം അക്ഷരം *run_main; /* entry for tcc_run() */
    ശൂന്യം *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    സ്ഥിരം അക്ഷരം *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    ശൂന്യം *run_function_table; /* unwind data */
#endif
    ഘടന TCCState *next;
    ഘടന rt_context *rc; /* pointer to backtrace info block */
    ശൂന്യം *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    ശൂന്യം *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    പൂർണ്ണസംഖ്യ rt_അക്കം_callers;
#endif

    /* benchmark info */
    പൂർണ്ണസംഖ്യ total_idents;
    പൂർണ്ണസംഖ്യ total_വരികൾ;
    unsigned പൂർണ്ണസംഖ്യ total_bytes;
    unsigned പൂർണ്ണസംഖ്യ total_output[4];

    /* used by tcc_load_ldscript */
    unsigned അക്ഷരം *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    സ്ഥിരം അക്ഷരം *current_filename;

    /* used by main and tcc_parse_args only */
    ഘടന filespec **files; /* files seen on command line */
    പൂർണ്ണസംഖ്യ nb_files; /* number thereof */
    പൂർണ്ണസംഖ്യ nb_libraries; /* number of libs thereof */
    അക്ഷരം *outfile; /* output filename */
    അക്ഷരം *deps_outfile; /* option -MF */
    പൂർണ്ണസംഖ്യ argc;
    അക്ഷരം **argv;
    /* -Wl options */
    അക്ഷരം **link_argv;
    പൂർണ്ണസംഖ്യ link_argc, link_optind;
};

ഘടന filespec {
    അക്ഷരം type;
    അക്ഷരം name[1];
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

#define TOK_HAS_മൂല്യം(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

എണ്ണൽ tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#അന്തര്ഭാവ "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA ഘടന TCCState *tcc_state;
ST_DATA ശൂന്യം** stk_data;
ST_DATA പൂർണ്ണസംഖ്യ nb_stk_data;
ST_DATA പൂർണ്ണസംഖ്യ g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC അക്ഷരം *pstrcpy(അക്ഷരം *buf, size_t buf_size, സ്ഥിരം അക്ഷരം *s);
ST_FUNC അക്ഷരം *pstrcat(അക്ഷരം *buf, size_t buf_size, സ്ഥിരം അക്ഷരം *s);
ST_FUNC അക്ഷരം *pstrncpy(അക്ഷരം *out, size_t buf_size, സ്ഥിരം അക്ഷരം *s, size_t അക്കം);
PUB_FUNC അക്ഷരം *tcc_basename(സ്ഥിരം അക്ഷരം *name);
PUB_FUNC അക്ഷരം *tcc_fileextension (സ്ഥിരം അക്ഷരം *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC ശൂന്യം tcc_free(ശൂന്യം *ptr);
PUB_FUNC ശൂന്യം *tcc_malloc(unsigned long size);
PUB_FUNC ശൂന്യം *tcc_mallocz(unsigned long size);
PUB_FUNC ശൂന്യം *tcc_realloc(ശൂന്യം *ptr, unsigned long size);
PUB_FUNC അക്ഷരം *tcc_strdup(സ്ഥിരം അക്ഷരം *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC ശൂന്യം tcc_free_debug(ശൂന്യം *ptr);
PUB_FUNC ശൂന്യം *tcc_malloc_debug(unsigned long size, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി);
PUB_FUNC ശൂന്യം *tcc_mallocz_debug(unsigned long size, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി);
PUB_FUNC ശൂന്യം *tcc_realloc_debug(ശൂന്യം *ptr, unsigned long size, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി);
PUB_FUNC അക്ഷരം *tcc_strdup_debug(സ്ഥിരം അക്ഷരം *str, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി);
#endif

ST_FUNC ശൂന്യം libc_free(ശൂന്യം *ptr);
/* defined to be not used */
#define സ്വതന്ത്രം(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC പൂർണ്ണസംഖ്യ _tcc_error_noabort(സ്ഥിരം അക്ഷരം *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN ശൂന്യം _tcc_error(സ്ഥിരം അക്ഷരം *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC ശൂന്യം _tcc_warning(സ്ഥിരം അക്ഷരം *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(സന്ദേശം) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,സന്ദേശം)

/* other utilities */
ST_FUNC ശൂന്യം dynarray_add(ശൂന്യം *ptab, പൂർണ്ണസംഖ്യ *nb_ptr, ശൂന്യം *data);
ST_FUNC ശൂന്യം dynarray_reset(ശൂന്യം *pp, പൂർണ്ണസംഖ്യ *n);
ST_INLN ശൂന്യം cstr_ccat(CString *cstr, പൂർണ്ണസംഖ്യ ch);
ST_FUNC ശൂന്യം cstr_cat(CString *cstr, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ len);
ST_FUNC ശൂന്യം cstr_wccat(CString *cstr, പൂർണ്ണസംഖ്യ ch);
ST_FUNC ശൂന്യം cstr_new(CString *cstr);
ST_FUNC ശൂന്യം cstr_free(CString *cstr);
ST_FUNC പൂർണ്ണസംഖ്യ cstr_printf(CString *cs, സ്ഥിരം അക്ഷരം *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC പൂർണ്ണസംഖ്യ cstr_vprintf(CString *cstr, സ്ഥിരം അക്ഷരം *fmt, va_list ap);
ST_FUNC ശൂന്യം cstr_reset(CString *cstr);
ST_FUNC ശൂന്യം tcc_open_bf(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ initlen);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_open(TCCState *s1, സ്ഥിരം അക്ഷരം *filename);
ST_FUNC ശൂന്യം tcc_close(ശൂന്യം);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_തള്ളുക(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_എടുക്കുക() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_തള്ളുക(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_എടുക്കുക())

ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_file_internal(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flags);
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
ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_crt(TCCState *s, സ്ഥിരം അക്ഷരം *filename);
#endif
ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_dll(TCCState *s, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flags);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_support(TCCState *s1, സ്ഥിരം അക്ഷരം *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC ശൂന്യം tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC ശൂന്യം tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC ശൂന്യം tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC പൂർണ്ണസംഖ്യ tcc_add_library_err(TCCState *s, സ്ഥിരം അക്ഷരം *f);
PUB_FUNC ശൂന്യം tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC പൂർണ്ണസംഖ്യ tcc_parse_args(TCCState *s, പൂർണ്ണസംഖ്യ *argc, അക്ഷരം ***argv);
#ifdef _WIN32
ST_FUNC അക്ഷരം *normalize_slashes(അക്ഷരം *path);
PUB_FUNC FILE *tcc_fopen(സ്ഥിരം അക്ഷരം *f, സ്ഥിരം അക്ഷരം *m);
PUB_FUNC പൂർണ്ണസംഖ്യ tcc_fclose(FILE *f);
#അല്ലെങ്കിൽ
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, സ്ഥിരം അക്ഷരം *dllname, പൂർണ്ണസംഖ്യ level);
ST_FUNC അക്ഷരം *tcc_load_text(പൂർണ്ണസംഖ്യ fd);
/* for #pragma once */
ST_FUNC പൂർണ്ണസംഖ്യ normalized_PATHCMP(സ്ഥിരം അക്ഷരം *f1, സ്ഥിരം അക്ഷരം *f2);

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

ST_DATA ഘടന BufferedFile *file;
ST_DATA പൂർണ്ണസംഖ്യ tok;
ST_DATA CValue tokc;
ST_DATA സ്ഥിരം പൂർണ്ണസംഖ്യ *macro_ptr;
ST_DATA പൂർണ്ണസംഖ്യ parse_flags;
ST_DATA പൂർണ്ണസംഖ്യ tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA പൂർണ്ണസംഖ്യ tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA പൂർണ്ണസംഖ്യ pp_വ്യഞ്ജകം;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_അക്കം    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_അക്കം 4

എണ്ണൽ വരി_macro_output_format {
    വരി_MACRO_OUTPUT_FORMAT_GCC,
    വരി_MACRO_OUTPUT_FORMAT_NONE,
    വരി_MACRO_OUTPUT_FORMAT_STD,
    വരി_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ len);
ST_FUNC പൂർണ്ണസംഖ്യ tok_alloc_const(സ്ഥിരം അക്ഷരം *str);
ST_FUNC സ്ഥിരം അക്ഷരം *get_tok_str(പൂർണ്ണസംഖ്യ v, CValue *cv);
ST_FUNC ശൂന്യം begin_macro(TokenString *str, പൂർണ്ണസംഖ്യ alloc);
ST_FUNC ശൂന്യം end_macro(ശൂന്യം);
ST_FUNC പൂർണ്ണസംഖ്യ set_idnum(പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ val);
ST_INLN ശൂന്യം tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(ശൂന്യം);
ST_FUNC ശൂന്യം tok_str_free(TokenString *s);
ST_FUNC ശൂന്യം tok_str_free_str(പൂർണ്ണസംഖ്യ *str);
ST_FUNC ശൂന്യം tok_str_add(TokenString *s, പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം tok_str_add_tok(TokenString *s);
ST_INLN ശൂന്യം define_തള്ളുക(പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ macro_type, പൂർണ്ണസംഖ്യ *str, Sym *first_arg);
ST_FUNC ശൂന്യം define_undef(Sym *s);
ST_INLN Sym *define_find(പൂർണ്ണസംഖ്യ v);
ST_FUNC ശൂന്യം free_defines(Sym *b);
ST_FUNC ശൂന്യം parse_define(ശൂന്യം);
ST_FUNC ശൂന്യം skip_to_eol(പൂർണ്ണസംഖ്യ warn);
ST_FUNC ശൂന്യം preprocess(പൂർണ്ണസംഖ്യ is_bof);
ST_FUNC ശൂന്യം next(ശൂന്യം);
ST_INLN ശൂന്യം unget_tok(പൂർണ്ണസംഖ്യ last_tok);
ST_FUNC ശൂന്യം preprocess_start(TCCState *s1, പൂർണ്ണസംഖ്യ filetype);
ST_FUNC ശൂന്യം preprocess_end(TCCState *s1);
ST_FUNC ശൂന്യം tccpp_new(TCCState *s);
ST_FUNC ശൂന്യം tccpp_delete(TCCState *s);
ST_FUNC ശൂന്യം tccpp_putfile(സ്ഥിരം അക്ഷരം *filename);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_preprocess(TCCState *s1);
ST_FUNC ശൂന്യം skip(പൂർണ്ണസംഖ്യ c);
ST_FUNC NORETURN ശൂന്യം expect(സ്ഥിരം അക്ഷരം *സന്ദേശം);
ST_FUNC ശൂന്യം pp_error(CString *cs);


/* space excluding newline */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ is_space(പൂർണ്ണസംഖ്യ ch) {
    തിരികെ ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ isid(പൂർണ്ണസംഖ്യ c) {
    തിരികെ (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ isnum(പൂർണ്ണസംഖ്യ c) {
    തിരികെ c >= '0' && c <= '9';
}
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ isoct(പൂർണ്ണസംഖ്യ c) {
    തിരികെ c >= '0' && c <= '7';
}
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ toup(പൂർണ്ണസംഖ്യ c) {
    തിരികെ (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / വലുപ്പം(Sym))

ST_DATA Sym *global_അട്ടി;
ST_DATA Sym *local_അട്ടി;
ST_DATA Sym *local_label_അട്ടി;
ST_DATA Sym *global_label_അട്ടി;
ST_DATA Sym *define_അട്ടി;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA പൂർണ്ണസംഖ്യ rsym, anon_sym, ind, loc;
ST_DATA അക്ഷരം debug_modes;

ST_DATA പൂർണ്ണസംഖ്യ nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA പൂർണ്ണസംഖ്യ global_വ്യഞ്ജകം;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA പൂർണ്ണസംഖ്യ func_var; /* true if current function is variadic */
ST_DATA പൂർണ്ണസംഖ്യ func_vc; /* stack address for implicit struct return storage */
ST_DATA പൂർണ്ണസംഖ്യ func_ind; /* function start address */
ST_DATA സ്ഥിരം അക്ഷരം *funcname;

ST_FUNC ശൂന്യം tccgen_init(TCCState *s1);
ST_FUNC പൂർണ്ണസംഖ്യ tccgen_compile(TCCState *s1);
ST_FUNC ശൂന്യം tccgen_finish(TCCState *s1);
ST_FUNC ശൂന്യം check_vstack(ശൂന്യം);

ST_INLN പൂർണ്ണസംഖ്യ is_float(പൂർണ്ണസംഖ്യ t);
ST_FUNC പൂർണ്ണസംഖ്യ ieee_finite(ഇരട്ട d);
ST_FUNC പൂർണ്ണസംഖ്യ exact_log2p1(പൂർണ്ണസംഖ്യ i);
ST_FUNC ശൂന്യം test_lvalue(ശൂന്യം);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC ശൂന്യം update_storage(Sym *sym);
ST_FUNC ശൂന്യം put_extern_sym2(Sym *sym, പൂർണ്ണസംഖ്യ sh_അക്കം, addr_t മൂല്യം, unsigned long size, പൂർണ്ണസംഖ്യ can_add_underscore);
ST_FUNC ശൂന്യം put_extern_sym(Sym *sym, Section *section, addr_t മൂല്യം, unsigned long size);
#എങ്കിൽ PTR_SIZE == 4
ST_FUNC ശൂന്യം greloc(Section *s, Sym *sym, unsigned long offset, പൂർണ്ണസംഖ്യ type);
#endif
ST_FUNC ശൂന്യം greloca(Section *s, Sym *sym, unsigned long offset, പൂർണ്ണസംഖ്യ type, addr_t addend);

ST_INLN ശൂന്യം sym_free(Sym *sym);
ST_FUNC Sym *sym_തള്ളുക(പൂർണ്ണസംഖ്യ v, CType *type, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം sym_എടുക്കുക(Sym **ptop, Sym *b, പൂർണ്ണസംഖ്യ keep);
ST_FUNC Sym *sym_push2(Sym **ps, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ c);
ST_FUNC Sym *sym_find2(Sym *s, പൂർണ്ണസംഖ്യ v);
ST_INLN Sym *sym_find(പൂർണ്ണസംഖ്യ v);
ST_FUNC Sym *label_find(പൂർണ്ണസംഖ്യ v);
ST_FUNC Sym *label_തള്ളുക(Sym **ptop, പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ flags);
ST_FUNC ശൂന്യം label_എടുക്കുക(Sym **ptop, Sym *slast, പൂർണ്ണസംഖ്യ keep);
ST_INLN Sym *struct_find(പൂർണ്ണസംഖ്യ v);

ST_FUNC Sym *global_identifier_തള്ളുക(പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ c);
ST_FUNC Sym *external_global_sym(പൂർണ്ണസംഖ്യ v, CType *type);
ST_FUNC Sym *external_helper_sym(പൂർണ്ണസംഖ്യ v);
ST_FUNC ശൂന്യം vpush_helper_func(പൂർണ്ണസംഖ്യ v);
ST_FUNC ശൂന്യം vset(CType *type, പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ v);
ST_FUNC ശൂന്യം vset_VT_CMP(പൂർണ്ണസംഖ്യ op);
ST_FUNC ശൂന്യം vpushi(പൂർണ്ണസംഖ്യ v);
ST_FUNC ശൂന്യം vpushv(SValue *v);
ST_FUNC ശൂന്യം vpushsym(CType *type, Sym *sym);
ST_FUNC ശൂന്യം vswap(ശൂന്യം);
ST_FUNC ശൂന്യം vrott(പൂർണ്ണസംഖ്യ n);
ST_FUNC ശൂന്യം vrotb(പൂർണ്ണസംഖ്യ n);
ST_FUNC ശൂന്യം vrev(പൂർണ്ണസംഖ്യ n);
ST_FUNC ശൂന്യം vpop(ശൂന്യം);
#എങ്കിൽ PTR_SIZE == 4
ST_FUNC ശൂന്യം lexpand(ശൂന്യം);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC പൂർണ്ണസംഖ്യ get_reg_ex(പൂർണ്ണസംഖ്യ rc, പൂർണ്ണസംഖ്യ rc2);
#endif
ST_FUNC ശൂന്യം save_reg(പൂർണ്ണസംഖ്യ r);
ST_FUNC ശൂന്യം save_reg_upstack(പൂർണ്ണസംഖ്യ r, പൂർണ്ണസംഖ്യ n);
ST_FUNC പൂർണ്ണസംഖ്യ get_reg(പൂർണ്ണസംഖ്യ rc);
ST_FUNC ശൂന്യം save_regs(പൂർണ്ണസംഖ്യ n);
ST_FUNC ശൂന്യം gaddrof(ശൂന്യം);
ST_FUNC പൂർണ്ണസംഖ്യ gv(പൂർണ്ണസംഖ്യ rc);
ST_FUNC ശൂന്യം gv2(പൂർണ്ണസംഖ്യ rc1, പൂർണ്ണസംഖ്യ rc2);
ST_FUNC ശൂന്യം gen_op(പൂർണ്ണസംഖ്യ op);
ST_FUNC പൂർണ്ണസംഖ്യ type_size(CType *type, പൂർണ്ണസംഖ്യ *a);
ST_FUNC ശൂന്യം mk_pointer(CType *type);
ST_FUNC ശൂന്യം vstore(ശൂന്യം);
ST_FUNC ശൂന്യം inc(പൂർണ്ണസംഖ്യ post, പൂർണ്ണസംഖ്യ c);
ST_FUNC CString* parse_mult_str(സ്ഥിരം അക്ഷരം *സന്ദേശം);
ST_FUNC CString* parse_asm_str(ശൂന്യം);
ST_FUNC ശൂന്യം indir(ശൂന്യം);
ST_FUNC ശൂന്യം unary(ശൂന്യം);
ST_FUNC ശൂന്യം gexpr(ശൂന്യം);
ST_FUNC പൂർണ്ണസംഖ്യ വ്യഞ്ജകം_const(ശൂന്യം);
#എങ്കിൽ defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#എങ്കിൽ defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC പൂർണ്ണസംഖ്യ classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC ശൂന്യം gbound_args(പൂർണ്ണസംഖ്യ nb_args);
ST_DATA പൂർണ്ണസംഖ്യ func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_ദ്വിമാന 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

തരനിർവചനം ഘടന {
    unsigned പൂർണ്ണസംഖ്യ n_strx;         /* index into string table of name */
    unsigned അക്ഷരം n_type;         /* type of symbol */
    unsigned അക്ഷരം n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned പൂർണ്ണസംഖ്യ n_മൂല്യം;        /* value of symbol */
} Stab_Sym;

ST_FUNC ശൂന്യം tccelf_new(TCCState *s);
ST_FUNC ശൂന്യം tccelf_delete(TCCState *s);
ST_FUNC ശൂന്യം tccelf_begin_file(TCCState *s1);
ST_FUNC ശൂന്യം tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name, പൂർണ്ണസംഖ്യ sh_type, പൂർണ്ണസംഖ്യ sh_flags);
ST_FUNC ശൂന്യം section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, പൂർണ്ണസംഖ്യ align);
ST_FUNC ശൂന്യം *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, സ്ഥിരം അക്ഷരം *name);
ST_FUNC ശൂന്യം free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, സ്ഥിരം അക്ഷരം *symtab_name, പൂർണ്ണസംഖ്യ sh_type, പൂർണ്ണസംഖ്യ sh_flags, സ്ഥിരം അക്ഷരം *strtab_name, സ്ഥിരം അക്ഷരം *hash_name, പൂർണ്ണസംഖ്യ hash_sh_flags);
ST_FUNC ശൂന്യം init_symtab(Section *s);

ST_FUNC പൂർണ്ണസംഖ്യ put_elf_str(Section *s, സ്ഥിരം അക്ഷരം *sym);
ST_FUNC പൂർണ്ണസംഖ്യ put_elf_sym(Section *s, addr_t മൂല്യം, unsigned long size, പൂർണ്ണസംഖ്യ info, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ shndx, സ്ഥിരം അക്ഷരം *name);
ST_FUNC പൂർണ്ണസംഖ്യ set_elf_sym(Section *s, addr_t മൂല്യം, unsigned long size, പൂർണ്ണസംഖ്യ info, പൂർണ്ണസംഖ്യ other, പൂർണ്ണസംഖ്യ shndx, സ്ഥിരം അക്ഷരം *name);
ST_FUNC പൂർണ്ണസംഖ്യ find_elf_sym(Section *s, സ്ഥിരം അക്ഷരം *name);
ST_FUNC ശൂന്യം put_elf_reloc(Section *symtab, Section *s, unsigned long offset, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ ചിഹ്നം);
ST_FUNC ശൂന്യം put_elf_reloca(Section *symtab, Section *s, unsigned long offset, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ ചിഹ്നം, addr_t addend);

ST_FUNC ശൂന്യം resolve_common_syms(TCCState *s1);
ST_FUNC ശൂന്യം relocate_syms(TCCState *s1, Section *symtab, പൂർണ്ണസംഖ്യ do_resolve);
ST_FUNC ശൂന്യം relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(പൂർണ്ണസംഖ്യ fd, ശൂന്യം *buf, size_t എണ്ണം_2);
ST_FUNC ശൂന്യം *load_data(പൂർണ്ണസംഖ്യ fd, unsigned long file_offset, unsigned long size);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_object_type(പൂർണ്ണസംഖ്യ fd, ElfW(Ehdr) *h);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_object_file(TCCState *s1, പൂർണ്ണസംഖ്യ fd, unsigned long file_offset);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_archive(TCCState *s1, പൂർണ്ണസംഖ്യ fd, പൂർണ്ണസംഖ്യ alacarte);
ST_FUNC ശൂന്യം add_array(TCCState *s1, സ്ഥിരം അക്ഷരം *sec, പൂർണ്ണസംഖ്യ c);

ST_FUNC ഘടന sym_attr *get_sym_attr(TCCState *s1, പൂർണ്ണസംഖ്യ index, പൂർണ്ണസംഖ്യ alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, സ്ഥിരം അക്ഷരം *name, പൂർണ്ണസംഖ്യ err, പൂർണ്ണസംഖ്യ forc);
ST_FUNC ശൂന്യം list_elf_symbols(TCCState *s, ശൂന്യം *ctx,
    ശൂന്യം (*ചിഹ്നം_cb)(ശൂന്യം *ctx, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം ശൂന്യം *val));
ST_FUNC പൂർണ്ണസംഖ്യ set_global_sym(TCCState *s1, സ്ഥിരം അക്ഷരം *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    വേണ്ടി (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_dll(TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ level);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_ldscript(TCCState *s1, പൂർണ്ണസംഖ്യ fd);
ST_FUNC ശൂന്യം tccelf_add_crtbegin(TCCState *s1);
ST_FUNC ശൂന്യം tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC ശൂന്യം tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC പൂർണ്ണസംഖ്യ code_reloc (പൂർണ്ണസംഖ്യ reloc_type);
ST_FUNC പൂർണ്ണസംഖ്യ gotplt_entry_type (പൂർണ്ണസംഖ്യ reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
എണ്ണൽ gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#എങ്കിൽ !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ഘടന sym_attr *attr);
ST_FUNC ശൂന്യം relocate_plt(TCCState *s1);
ST_FUNC ശൂന്യം build_got_entries(TCCState *s1, പൂർണ്ണസംഖ്യ got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC ശൂന്യം relocate(TCCState *s1, ElfW_Rel *rel, പൂർണ്ണസംഖ്യ type, unsigned അക്ഷരം *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA സ്ഥിരം അക്ഷരം * സ്ഥിരം target_machine_defs;
ST_DATA സ്ഥിരം പൂർണ്ണസംഖ്യ reg_classes[NB_REGS];

ST_FUNC ശൂന്യം gsym_addr(പൂർണ്ണസംഖ്യ t, പൂർണ്ണസംഖ്യ a);
ST_FUNC ശൂന്യം gsym(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം load(പൂർണ്ണസംഖ്യ r, SValue *sv);
ST_FUNC ശൂന്യം store(പൂർണ്ണസംഖ്യ r, SValue *v);
ST_FUNC പൂർണ്ണസംഖ്യ gfunc_sret(CType *vt, പൂർണ്ണസംഖ്യ variadic, CType *ret, പൂർണ്ണസംഖ്യ *align, പൂർണ്ണസംഖ്യ *regsize);
ST_FUNC ശൂന്യം gfunc_call(പൂർണ്ണസംഖ്യ nb_args);
ST_FUNC ശൂന്യം gfunc_prolog(Sym *func_sym);
ST_FUNC ശൂന്യം gfunc_epilog(ശൂന്യം);
ST_FUNC ശൂന്യം gen_fill_nops(പൂർണ്ണസംഖ്യ);
ST_FUNC പൂർണ്ണസംഖ്യ gjmp(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gjmp_addr(പൂർണ്ണസംഖ്യ a);
ST_FUNC പൂർണ്ണസംഖ്യ gjmp_cond(പൂർണ്ണസംഖ്യ op, പൂർണ്ണസംഖ്യ t);
ST_FUNC പൂർണ്ണസംഖ്യ gjmp_append(പൂർണ്ണസംഖ്യ n, പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gen_opi(പൂർണ്ണസംഖ്യ op);
ST_FUNC ശൂന്യം gen_opf(പൂർണ്ണസംഖ്യ op);
ST_FUNC ശൂന്യം gen_cvt_ftoi(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gen_cvt_itof(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gen_cvt_ftof(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം ggoto(ശൂന്യം);
#ifndef TCC_TARGET_C67
ST_FUNC ശൂന്യം o(unsigned പൂർണ്ണസംഖ്യ c);
#endif
ST_FUNC ശൂന്യം gen_vla_sp_save(പൂർണ്ണസംഖ്യ addr);
ST_FUNC ശൂന്യം gen_vla_sp_restore(പൂർണ്ണസംഖ്യ addr);
ST_FUNC ശൂന്യം gen_vla_alloc(CType *type, പൂർണ്ണസംഖ്യ align);

സ്ഥിതം വരിയിൽ uint16_t read16le(unsigned അക്ഷരം *p) {
    തിരികെ p[0] | (uint16_t)p[1] << 8;
}
സ്ഥിതം വരിയിൽ ശൂന്യം write16le(unsigned അക്ഷരം *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
സ്ഥിതം വരിയിൽ uint32_t read32le(unsigned അക്ഷരം *p) {
  തിരികെ read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
സ്ഥിതം വരിയിൽ ശൂന്യം write32le(unsigned അക്ഷരം *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
സ്ഥിതം വരിയിൽ ശൂന്യം add32le(unsigned അക്ഷരം *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
സ്ഥിതം വരിയിൽ uint64_t read64le(unsigned അക്ഷരം *p) {
  തിരികെ read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
സ്ഥിതം വരിയിൽ ശൂന്യം write64le(unsigned അക്ഷരം *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
സ്ഥിതം വരിയിൽ ശൂന്യം add64le(unsigned അക്ഷരം *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#എങ്കിൽ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC ശൂന്യം g(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le16(പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_le32(പൂർണ്ണസംഖ്യ c);
#endif
#എങ്കിൽ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC ശൂന്യം gen_addr32(പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_addrpc32(പൂർണ്ണസംഖ്യ r, Sym *sym, പൂർണ്ണസംഖ്യ c);
ST_FUNC ശൂന്യം gen_cvt_csti(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC ശൂന്യം gen_opl(പൂർണ്ണസംഖ്യ op);
#ifdef TCC_TARGET_PE
ST_FUNC ശൂന്യം gen_vla_result(പൂർണ്ണസംഖ്യ addr);
#endif
ST_FUNC ശൂന്യം gen_cvt_sxtw(ശൂന്യം);
ST_FUNC ശൂന്യം gen_cvt_csti(പൂർണ്ണസംഖ്യ t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#എങ്കിൽ defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC സ്ഥിരം അക്ഷരം *default_elfinterp(ഘടന TCCState *s);
#endif
ST_FUNC ശൂന്യം arm_init(ഘടന TCCState *s);
ST_FUNC ശൂന്യം gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC ശൂന്യം gen_opl(പൂർണ്ണസംഖ്യ op);
ST_FUNC ശൂന്യം gfunc_return(CType *func_type);
ST_FUNC ശൂന്യം gen_va_start(ശൂന്യം);
ST_FUNC ശൂന്യം gen_va_arg(CType *t);
ST_FUNC ശൂന്യം gen_clear_cache(ശൂന്യം);
ST_FUNC ശൂന്യം gen_cvt_sxtw(ശൂന്യം);
ST_FUNC ശൂന്യം gen_cvt_csti(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC ശൂന്യം gen_opl(പൂർണ്ണസംഖ്യ op);
ST_FUNC ശൂന്യം gen_va_start(ശൂന്യം);
ST_FUNC ശൂന്യം arch_transfer_ret_regs(പൂർണ്ണസംഖ്യ);
ST_FUNC ശൂന്യം gen_cvt_sxtw(ശൂന്യം);
ST_FUNC ശൂന്യം gen_cvt_csti(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം gen_increment_tcov (SValue *sv);
ST_FUNC ശൂന്യം gen_clear_cache(ശൂന്യം);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC പൂർണ്ണസംഖ്യ tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_load_coff(TCCState * s1, പൂർണ്ണസംഖ്യ fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC ശൂന്യം asm_instr(ശൂന്യം);
ST_FUNC ശൂന്യം asm_global_instr(ശൂന്യം);
ST_FUNC പൂർണ്ണസംഖ്യ tcc_assemble(TCCState *s1, പൂർണ്ണസംഖ്യ do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC പൂർണ്ണസംഖ്യ find_constraint(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം അക്ഷരം **pp);
ST_FUNC Sym* get_asm_sym(പൂർണ്ണസംഖ്യ name, Sym *csym);
ST_FUNC ശൂന്യം asm_വ്യഞ്ജകം(TCCState *s1, വ്യഞ്ജകം_മൂല്യം *pe);
ST_FUNC പൂർണ്ണസംഖ്യ asm_int_വ്യഞ്ജകം(TCCState *s1);
#എങ്കിൽ PTR_SIZE == 8
ST_FUNC ശൂന്യം gen_expr64(വ്യഞ്ജകം_മൂല്യം *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC ശൂന്യം gen_expr32(വ്യഞ്ജകം_മൂല്യം *pe);
ST_FUNC ശൂന്യം asm_opcode(TCCState *s1, പൂർണ്ണസംഖ്യ opcode);
ST_FUNC പൂർണ്ണസംഖ്യ asm_parse_regvar(പൂർണ്ണസംഖ്യ t);
ST_FUNC ശൂന്യം asm_compute_constraints(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs, സ്ഥിരം uint8_t *clobber_regs, പൂർണ്ണസംഖ്യ *pout_reg);
ST_FUNC ശൂന്യം subst_asm_operand(CString *add_str, SValue *sv, പൂർണ്ണസംഖ്യ modifier);
ST_FUNC ശൂന്യം asm_gen_code(ASMOperand *operands, പൂർണ്ണസംഖ്യ nb_operands, പൂർണ്ണസംഖ്യ nb_outputs, പൂർണ്ണസംഖ്യ is_output, uint8_t *clobber_regs, പൂർണ്ണസംഖ്യ out_reg);
ST_FUNC ശൂന്യം asm_clobber(uint8_t *clobber_regs, സ്ഥിരം അക്ഷരം *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC പൂർണ്ണസംഖ്യ pe_load_file(ഘടന TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename);
ST_FUNC പൂർണ്ണസംഖ്യ pe_output_file(TCCState * s1, സ്ഥിരം അക്ഷരം *filename);
ST_FUNC പൂർണ്ണസംഖ്യ pe_putimport(TCCState *s1, പൂർണ്ണസംഖ്യ dllindex, സ്ഥിരം അക്ഷരം *name, addr_t മൂല്യം);
ST_FUNC പൂർണ്ണസംഖ്യ pe_setsubsy(TCCState *s1, സ്ഥിരം അക്ഷരം *arg);
#എങ്കിൽ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#എങ്കിൽ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC ശൂന്യം pe_add_unwind_data(unsigned start, unsigned end, unsigned അട്ടി);
#endif
PUB_FUNC പൂർണ്ണസംഖ്യ tcc_get_dllexports(സ്ഥിരം അക്ഷരം *filename, അക്ഷരം **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC പൂർണ്ണസംഖ്യ macho_output_file(TCCState * s1, സ്ഥിരം അക്ഷരം *filename);
ST_FUNC പൂർണ്ണസംഖ്യ macho_load_dll(TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ lev);
ST_FUNC പൂർണ്ണസംഖ്യ macho_load_tbd(TCCState *s1, പൂർണ്ണസംഖ്യ fd, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ lev);
#ifdef TCC_IS_NATIVE
ST_FUNC ശൂന്യം tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC അക്ഷരം* macho_tbd_soname(പൂർണ്ണസംഖ്യ fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    ശൂന്യ
/* dummy function for profiling */
ST_FUNC ശൂന്യം *dlopen(സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flag);
ST_FUNC ശൂന്യം dlclose(ശൂന്യം *p);
ST_FUNC സ്ഥിരം അക്ഷരം *dlerror(ശൂന്യം);
ST_FUNC ശൂന്യം *dlsym(ശൂന്യം *handle, സ്ഥിരം അക്ഷരം *ചിഹ്നം);
#endif
ST_FUNC ശൂന്യം tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#എങ്കിൽ 0 /* included in tcc.c */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_ar(TCCState *s, പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv);
#ifdef TCC_TARGET_PE
ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_impdef(TCCState *s, പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv);
#endif
ST_FUNC പൂർണ്ണസംഖ്യ tcc_tool_cross(TCCState *s, അക്ഷരം **argv, പൂർണ്ണസംഖ്യ option);
ST_FUNC പൂർണ്ണസംഖ്യ gen_makedeps(TCCState *s, സ്ഥിരം അക്ഷരം *target, സ്ഥിരം അക്ഷരം *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC ശൂന്യം tcc_debug_new(TCCState *s);

ST_FUNC ശൂന്യം tcc_debug_start(TCCState *s1);
ST_FUNC ശൂന്യം tcc_debug_end(TCCState *s1);
ST_FUNC ശൂന്യം tcc_debug_bincl(TCCState *s1);
ST_FUNC ശൂന്യം tcc_debug_eincl(TCCState *s1);
ST_FUNC ശൂന്യം tcc_debug_newfile(TCCState *s1);

ST_FUNC ശൂന്യം tcc_debug_വരി(TCCState *s1);
ST_FUNC ശൂന്യം tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC ശൂന്യം tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC ശൂന്യം tcc_debug_prolog_epilog(TCCState *s1, പൂർണ്ണസംഖ്യ മൂല്യം);
ST_FUNC ശൂന്യം tcc_debug_funcend(TCCState *s1, പൂർണ്ണസംഖ്യ size);
ST_FUNC ശൂന്യം tcc_debug_extern_sym(TCCState *s1, Sym *sym, പൂർണ്ണസംഖ്യ sh_അക്കം, പൂർണ്ണസംഖ്യ sym_bind, പൂർണ്ണസംഖ്യ sym_type);
ST_FUNC ശൂന്യം tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC ശൂന്യം tcc_debug_stabn(TCCState *s1, പൂർണ്ണസംഖ്യ type, പൂർണ്ണസംഖ്യ മൂല്യം);
ST_FUNC ശൂന്യം tcc_debug_fix_forw(TCCState *s1, CType *t);

#എങ്കിൽ !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC ശൂന്യം tcc_eh_frame_start(TCCState *s1);
ST_FUNC ശൂന്യം tcc_eh_frame_end(TCCState *s1);
ST_FUNC ശൂന്യം tcc_eh_frame_hdr(TCCState *s1, പൂർണ്ണസംഖ്യ final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC ശൂന്യം tcc_tcov_start(TCCState *s1);
ST_FUNC ശൂന്യം tcc_tcov_end(TCCState *s1);
ST_FUNC ശൂന്യം tcc_tcov_check_വരി(TCCState *s1, പൂർണ്ണസംഖ്യ start);
ST_FUNC ശൂന്യം tcc_tcov_block_end(TCCState *s1, പൂർണ്ണസംഖ്യ വരി);
ST_FUNC ശൂന്യം tcc_tcov_block_begin(TCCState *s1);
ST_FUNC ശൂന്യം tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_വരി_section      s1->dwarf_വരി_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_വരി_str_section  s1->dwarf_വരി_str_section

#define DWARF_MAX_128	((8 * വലുപ്പം (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
സ്ഥിതം വരിയിൽ uint64_t
dwarf_read_uleb128(unsigned അക്ഷരം **ln, unsigned അക്ഷരം *end)
{
    unsigned അക്ഷരം *cp = *ln;
    uint64_t retval = 0;
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	എങ്കിൽ ((byte & 0x80) == 0)
	    നിർത്തുക;
    }
    *ln = cp;
    തിരികെ retval;
}
സ്ഥിതം വരിയിൽ int64_t
dwarf_read_sleb128(unsigned അക്ഷരം **ln, unsigned അക്ഷരം *end)
{
    unsigned അക്ഷരം *cp = *ln;
    int64_t retval = 0;
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	എങ്കിൽ ((byte & 0x80) == 0) {
	    എങ്കിൽ ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    നിർത്തുക;
	}
    }
    *ln = cp;
    തിരികെ retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#അല്ലെങ്കിൽ
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#എങ്കിൽ defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#അല്ലെങ്കിൽ
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#എങ്കിൽ CONFIG_TCC_SEMLOCK
#എങ്കിൽ defined _WIN32
തരനിർവചനം ഘടന { അസ്ഥിര LONG init; CRITICAL_SECTION cs; } TCCSem;
സ്ഥിതം വരിയിൽ ശൂന്യം wait_sem(TCCSem *p) {
    എങ്കിൽ (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } അല്ലെങ്കിൽ {
        ആകുമ്പോൾ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
സ്ഥിതം വരിയിൽ ശൂന്യം post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#അല്ലെങ്കിലെങ്കിൽ defined __APPLE__
#അന്തര്ഭാവ <dispatch/dispatch.h>
തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ init; dispatch_semaphore_t sem; } TCCSem;
സ്ഥിതം വരിയിൽ ശൂന്യം wait_sem(TCCSem *p) {
    എങ്കിൽ (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
സ്ഥിതം വരിയിൽ ശൂന്യം post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <semaphore.h>
തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ init; sem_t sem; } TCCSem;
സ്ഥിതം വരിയിൽ ശൂന്യം wait_sem(TCCSem *p) {
    എങ്കിൽ (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    ആകുമ്പോൾ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
സ്ഥിതം വരിയിൽ ശൂന്യം post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#അല്ലെങ്കിൽ
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#എങ്കിൽ ONE_SOURCE
#define ST_DATA സ്ഥിതം
#അല്ലെങ്കിൽ
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
#define total_വരികൾ         TCC_STATE_VAR(total_വരികൾ)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC ശൂന്യം tcc_enter_state(TCCState *s1);
PUB_FUNC ശൂന്യം tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_അക്കം = offsetof(TCCState, sw) \
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
#അല്ലെങ്കിൽ
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
