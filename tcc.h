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
#অন্তর্ভাব "config.h"

#অন্তর্ভাব <stdarg.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <errno.h>
#অন্তর্ভাব <math.h>
#অন্তর্ভাব <fcntl.h>
#অন্তর্ভাব <setjmp.h>
#অন্তর্ভাব <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
বাহ্য ভিন্ন strtof (ধ্রুব বর্ণ *__nptr, বর্ণ **__endptr);
বাহ্য long দ্বিগুণ strtold (ধ্রুব বর্ণ *__nptr, বর্ণ **__endptr);
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
# define অন্তঃস্থ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long দ্বিগুণ)strtod
#  define strtof (ভিন্ন)strtod
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
# যদি defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_দ্বিমিক_2
# define O_দ্বিমিক_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#অন্যথা
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (পরিমাণ(tab) / পরিমাণ((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#অন্যথা
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#অন্যথা
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
#যদি !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# যদি defined __x86_64__
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
# অন্যথা
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
#যদি defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# যদি defined __i386__ && defined TCC_TARGET_I386
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

#যদি defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#অন্যথা
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#যদি defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#অন্যথা
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#যদি defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#অন্যথা
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#যদি defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#নোচেদ্যদি !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#যদি defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#অন্যথা
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#যদি defined TCC_TARGET_PE \
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

#যদি !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#অন্যথা
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
# যদি defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# অন্যথা
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# যদি defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# অন্যথা
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# যদি defined __GNU__
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
# অন্যথা
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

#অন্তর্ভাব "libtcc.h"
#অন্তর্ভাব "elf.h"
#অন্তর্ভাব "stab.h"
#অন্তর্ভাব "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#যদি ONE_SOURCE
#define ST_INLN স্থির অন্তঃস্থ
#define ST_FUNC স্থির
#define ST_DATA স্থির
#অন্যথা
#define ST_INLN
#define ST_FUNC
#define ST_DATA বাহ্য
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define স্থির
# define অন্তঃস্থ
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#নোচেদ্যদি defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#নোচেদ্যদি defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#নোচেদ্যদি defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#নোচেদ্যদি defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#নোচেদ্যদি defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#অন্যথা
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#যদি PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#অন্যথা
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

#যদি PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#অন্যথা
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_স্তূপ_SIZE  32
#define IFDEF_স্তূপ_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_স্তূপ_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
প্রকারনির্দেশ সংরচনা TokenSym {
    সংরচনা TokenSym *hash_next;
    সংরচনা Sym *sym_define; /* direct pointer to define */
    সংরচনা Sym *sym_label; /* direct pointer to label */
    সংরচনা Sym *sym_struct; /* direct pointer to structure */
    সংরচনা Sym *sym_identifier; /* direct pointer to identifier */
    পূর্ণাঙ্ক tok; /* token number */
    পূর্ণাঙ্ক len;
    বর্ণ str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
প্রকারনির্দেশ unsigned short nwchar_t;
#অন্যথা
প্রকারনির্দেশ পূর্ণাঙ্ক nwchar_t;
#endif

প্রকারনির্দেশ সংরচনা CString {
    পূর্ণাঙ্ক size; /* size in bytes */
    পূর্ণাঙ্ক size_allocated;
    বর্ণ *data; /* nwchar_t* in cases */
} CString;

/* type definition */
প্রকারনির্দেশ সংরচনা CType {
    পূর্ণাঙ্ক t;
    সংরচনা Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_শব্দগুলি ((পরিমাণ(long দ্বিগুণ)+3)/4)

/* constant value */
প্রকারনির্দেশ সঙ্ঘ CValue {
    long দ্বিগুণ ld;
    দ্বিগুণ d;
    ভিন্ন f;
    uint64_t i;
    সংরচনা {
        বর্ণ *data;
        পূর্ণাঙ্ক size;
    } str;
    পূর্ণাঙ্ক tab[LDOUBLE_শব্দগুলি];
} CValue;

/* value on stack */
প্রকারনির্দেশ সংরচনা SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    সঙ্ঘ {
      সংরচনা { পূর্ণাঙ্ক jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    সঙ্ঘ {
      সংরচনা { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      সংরচনা Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
সংরচনা SymAttr {
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
সংরচনা FuncAttr {
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
প্রকারনির্দেশ সংরচনা Sym {
    পূর্ণাঙ্ক v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    সংরচনা SymAttr a; /* symbol attributes */
    সঙ্ঘ {
        সংরচনা {
            পূর্ণাঙ্ক c; /* associated number or Elf symbol index */
            সঙ্ঘ {
                পূর্ণাঙ্ক sym_scope; /* scope level for locals */
                পূর্ণাঙ্ক jnext; /* next jump label */
                পূর্ণাঙ্ক jind; /* label position */
                সংরচনা FuncAttr f; /* function attributes */
                পূর্ণাঙ্ক auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        পূর্ণাঙ্ক *d; /* define token stream */
        সংরচনা Sym *cleanup_func;
    };

    CType type; /* associated type */
    সঙ্ঘ {
        সংরচনা Sym *next; /* next related symbol (for fields and anoms) */
        পূর্ণাঙ্ক *e; /* expanded token stream with preprocessor macros */
        পূর্ণাঙ্ক asm_label; /* associated asm label */
        সংরচনা Sym *cleanupstate; /* in defined labels */
        পূর্ণাঙ্ক *vla_array_str; /* vla array code */
    };
    সংরচনা Sym *prev; /* prev symbol in stack */
    সঙ্ঘ {
        সংরচনা Sym *prev_tok; /* previous symbol for this token */
        সংরচনা Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        সংরচনা Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
প্রকারনির্দেশ সংরচনা Section {
    unsigned long data_offset; /* current data offset */
    unsigned বর্ণ *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    পূর্ণাঙ্ক sh_name;             /* elf section name (only used during output) */
    পূর্ণাঙ্ক sh_অঙ্ক;              /* elf section number */
    পূর্ণাঙ্ক sh_type;             /* elf section type */
    পূর্ণাঙ্ক sh_flags;            /* elf section flags */
    পূর্ণাঙ্ক sh_info;             /* elf section info */
    পূর্ণাঙ্ক sh_addralign;        /* elf section alignment */
    পূর্ণাঙ্ক sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    পূর্ণাঙ্ক nb_hashed_syms;      /* used to resize the hash table */
    সংরচনা Section *link;    /* link to another section */
    সংরচনা Section *reloc;   /* corresponding section for relocation, if any */
    সংরচনা Section *hash;    /* hash table for symbols */
    সংরচনা Section *prev;    /* previous section on section stack */
    বর্ণ name[1];           /* section name */
} Section;

প্রকারনির্দেশ সংরচনা DLLReference {
    পূর্ণাঙ্ক level;
    শূন্য *handle;
    unsigned বর্ণ found, index;
    বর্ণ name[1];
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

প্রকারনির্দেশ সংরচনা BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    পূর্ণাঙ্ক fd;
    সংরচনা BufferedFile *prev;
    পূর্ণাঙ্ক সারি_অঙ্ক;    /* current line number - here to simplify code */
    পূর্ণাঙ্ক সারি_ref;    /* tcc -E: last printed line */
    পূর্ণাঙ্ক ifndef_macro;  /* #ifndef macro / #endif search */
    পূর্ণাঙ্ক ifndef_macro_saved; /* saved ifndef_macro */
    পূর্ণাঙ্ক *ifdef_স্তূপ_ptr; /* ifdef_stack value at the start of the file */
    পূর্ণাঙ্ক include_next_index; /* next search path */
    পূর্ণাঙ্ক prev_tok_flags; /* saved tok_flags */
    বর্ণ filename[1024];    /* filename */
    বর্ণ *true_filename; /* filename not modified by # line directive */
    unsigned বর্ণ unget[4];
    unsigned বর্ণ buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
প্রকারনির্দেশ সংরচনা TokenString {
    পূর্ণাঙ্ক *str;
    পূর্ণাঙ্ক len;
    পূর্ণাঙ্ক need_spc;
    পূর্ণাঙ্ক allocated_len;
    পূর্ণাঙ্ক last_সারি_অঙ্ক;
    পূর্ণাঙ্ক save_সারি_অঙ্ক;
    /* used to chain token-strings with begin/end_macro() */
    সংরচনা TokenString *prev;
    ধ্রুব পূর্ণাঙ্ক *prev_ptr;
    বর্ণ alloc;
} TokenString;

/* GNUC attribute definition */
প্রকারনির্দেশ সংরচনা AttributeDef {
    সংরচনা SymAttr a;
    সংরচনা FuncAttr f;
    সংরচনা Section *section;
    Sym *cleanup_func;
    পূর্ণাঙ্ক alias_target; /* token */
    পূর্ণাঙ্ক asm_label; /* associated asm label */
    বর্ণ attr_mode; /* __attribute__((__mode__(...))) */
    বর্ণ new_section; /* section is new */
} AttributeDef;

/* inline functions */
প্রকারনির্দেশ সংরচনা InlineFunc {
    TokenString *func_str;
    Sym *sym;
    বর্ণ filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
প্রকারনির্দেশ সংরচনা CachedInclude {
    পূর্ণাঙ্ক ifndef_macro;
    পূর্ণাঙ্ক once;
    পূর্ণাঙ্ক hash_next; /* -1 if none */
    বর্ণ filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
প্রকারনির্দেশ সংরচনা রাশিমালা_মান {
    uint64_t v;
    Sym *sym;
    পূর্ণাঙ্ক pcrel;
} রাশিমালা_মান;

#define MAX_ASM_OPERANDS 30
প্রকারনির্দেশ সংরচনা ASMOperand {
    পূর্ণাঙ্ক id; /* GCC 3 optional identifier (0 if number only supported) */
    বর্ণ constraint[16];
    বর্ণ asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    পূর্ণাঙ্ক ref_index; /* if >= 0, gives reference to a output constraint */
    পূর্ণাঙ্ক প্রবেশ_index; /* if >= 0, gives reference to an input constraint */
    পূর্ণাঙ্ক priority; /* priority, used to assign registers */
    পূর্ণাঙ্ক reg; /* if >= 0, register number used for this operand */
    পূর্ণাঙ্ক is_llong; /* true if double register value */
    পূর্ণাঙ্ক is_memory; /* true if memory operand */
    পূর্ণাঙ্ক is_rw;     /* for '+' modifier */
    পূর্ণাঙ্ক is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
সংরচনা sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    পূর্ণাঙ্ক plt_sym;
    পূর্ণাঙ্ক dyn_index;
    unsigned বর্ণ linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned বর্ণ plt_thumb_stub:1;
#endif
};

সংরচনা TCCState {
    unsigned বর্ণ verbose; /* if true, display some information during compilation */
    unsigned বর্ণ nostdinc; /* if true, no standard headers are added */
    unsigned বর্ণ nostdlib; /* if true, no standard libraries are added */
    unsigned বর্ণ nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned বর্ণ nocommon; /* if true, do not use common symbols for .bss data */
    unsigned বর্ণ static_link; /* if true, static linking is performed */
    unsigned বর্ণ rdynamic; /* if true, all symbols are exported */
    unsigned বর্ণ symbolic; /* if true, resolve symbols in the current module first */
    unsigned বর্ণ znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned বর্ণ filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned বর্ণ optimize; /* only to #define __OPTIMIZE__ */
    unsigned বর্ণ option_pthread; /* -pthread option */
    unsigned বর্ণ enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned পূর্ণাঙ্ক  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned বর্ণ char_is_unsigned;
    unsigned বর্ণ leading_underscore;
    unsigned বর্ণ ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned বর্ণ dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned বর্ণ ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned বর্ণ reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned বর্ণ gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned বর্ণ unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned বর্ণ warn_none;
    unsigned বর্ণ warn_all;
    unsigned বর্ণ warn_error;
    unsigned বর্ণ warn_write_strings;
    unsigned বর্ণ warn_unsupported;
    unsigned বর্ণ warn_implicit_function_declaration;
    unsigned বর্ণ warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned বর্ণ warn_অঙ্ক; /* temp var for tcc_warning_c() */

    unsigned বর্ণ option_r; /* option -r */
    unsigned বর্ণ do_bench; /* option -bench */
    unsigned বর্ণ just_deps; /* option -M  */
    unsigned বর্ণ gen_deps; /* option -MD  */
    unsigned বর্ণ include_sys_deps; /* option -MD  */
    unsigned বর্ণ gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned বর্ণ do_debug;
    unsigned বর্ণ dwarf;
    unsigned বর্ণ do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned বর্ণ do_bounds_check;
#endif
    unsigned বর্ণ test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned বর্ণ gnu_ext;
    /* use TinyCC extensions */
    unsigned বর্ণ tcc_ext;

    unsigned বর্ণ dflag; /* -dX value */
    unsigned বর্ণ Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned বর্ণ nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned বর্ণ float_abi; /* float ABI of the generated code*/
#endif

    unsigned বর্ণ has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    পূর্ণাঙ্ক seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    বর্ণ *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    বর্ণ *soname; /* as specified on the command line (-soname) */
    বর্ণ *rpath; /* as specified on the command line (-Wl,-rpath=) */
    বর্ণ *elfint; /* -Wl,-I... on command line */
    বর্ণ *elf_entryname; /* "_start" unless set */
    বর্ণ *init_প্রতীক; /* symbols to call at load-time (not used currently) */
    বর্ণ *fini_প্রতীক; /* symbols to call at unload-time (not used currently) */
    বর্ণ *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    পূর্ণাঙ্ক output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    পূর্ণাঙ্ক output_format;
    /* nth test to run with -dt -run */
    পূর্ণাঙ্ক run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    পূর্ণাঙ্ক nb_loaded_dlls;

    /* include paths */
    বর্ণ **include_paths;
    পূর্ণাঙ্ক nb_include_paths;

    বর্ণ **sysinclude_paths;
    পূর্ণাঙ্ক nb_sysinclude_paths;

    /* library paths */
    বর্ণ **library_paths;
    পূর্ণাঙ্ক nb_library_paths;

    /* crt?.o object path */
    বর্ণ **crt_paths;
    পূর্ণাঙ্ক nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    শূন্য *error_opaque;
    শূন্য (*error_func)(শূন্য *opaque, ধ্রুব বর্ণ *বার্তা);
    পূর্ণাঙ্ক error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    পূর্ণাঙ্ক nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    বর্ণ **target_deps;
    পূর্ণাঙ্ক nb_target_deps;

    /* compilation */
    BufferedFile *include_স্তূপ[INCLUDE_স্তূপ_SIZE];
    BufferedFile **include_স্তূপ_ptr;

    পূর্ণাঙ্ক ifdef_স্তূপ[IFDEF_স্তূপ_SIZE];
    পূর্ণাঙ্ক *ifdef_স্তূপ_ptr;

    /* included files enclosed with #ifndef MACRO */
    পূর্ণাঙ্ক cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    পূর্ণাঙ্ক nb_cached_includes;

    /* #pragma pack stack */
    পূর্ণাঙ্ক pack_স্তূপ[PACK_স্তূপ_SIZE];
    পূর্ণাঙ্ক *pack_স্তূপ_ptr;
    বর্ণ **pragma_libs;
    পূর্ণাঙ্ক nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    সংরচনা InlineFunc **inline_fns;
    পূর্ণাঙ্ক nb_inline_fns;

    /* sections */
    Section **sections;
    পূর্ণাঙ্ক nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    পূর্ণাঙ্ক nb_priv_sections; /* number of private sections */

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
    সঙ্ঘ { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_সারি_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_সারি_str_section;
    পূর্ণাঙ্ক dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    সংরচনা _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    সংরচনা sym_attr *sym_attrs;
    পূর্ণাঙ্ক nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    সংরচনা pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    পূর্ণাঙ্ক nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    পূর্ণাঙ্ক pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_স্তূপ_size;
    addr_t pe_imagebase;
# যদি defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    পূর্ণাঙ্ক uw_sym;
    পূর্ণাঙ্ক uw_xsym;
    unsigned uw_offs;
# endif
#endif

#যদি defined TCC_TARGET_MACHO
    বর্ণ *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    পূর্ণাঙ্ক nb_sym_versions;
    সংরচনা sym_version *sym_versions;
    পূর্ণাঙ্ক nb_sym_to_version;
    পূর্ণাঙ্ক *sym_to_version;
    পূর্ণাঙ্ক dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    ধ্রুব বর্ণ *run_main; /* entry for tcc_run() */
    শূন্য *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    ধ্রুব বর্ণ *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    শূন্য *run_function_table; /* unwind data */
#endif
    সংরচনা TCCState *next;
    সংরচনা rt_context *rc; /* pointer to backtrace info block */
    শূন্য *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    শূন্য *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    পূর্ণাঙ্ক rt_অঙ্ক_callers;
#endif

    /* benchmark info */
    পূর্ণাঙ্ক total_idents;
    পূর্ণাঙ্ক total_সারিগুলি;
    unsigned পূর্ণাঙ্ক total_bytes;
    unsigned পূর্ণাঙ্ক total_output[4];

    /* used by tcc_load_ldscript */
    unsigned বর্ণ *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ধ্রুব বর্ণ *current_filename;

    /* used by main and tcc_parse_args only */
    সংরচনা filespec **files; /* files seen on command line */
    পূর্ণাঙ্ক nb_files; /* number thereof */
    পূর্ণাঙ্ক nb_libraries; /* number of libs thereof */
    বর্ণ *outfile; /* output filename */
    বর্ণ *deps_outfile; /* option -MF */
    পূর্ণাঙ্ক argc;
    বর্ণ **argv;
    /* -Wl options */
    বর্ণ **link_argv;
    পূর্ণাঙ্ক link_argc, link_optind;
};

সংরচনা filespec {
    বর্ণ type;
    বর্ণ name[1];
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

#define TOK_HAS_মান(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

গণনা tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#অন্তর্ভাব "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA সংরচনা TCCState *tcc_state;
ST_DATA শূন্য** stk_data;
ST_DATA পূর্ণাঙ্ক nb_stk_data;
ST_DATA পূর্ণাঙ্ক g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC বর্ণ *pstrcpy(বর্ণ *buf, size_t buf_size, ধ্রুব বর্ণ *s);
ST_FUNC বর্ণ *pstrcat(বর্ণ *buf, size_t buf_size, ধ্রুব বর্ণ *s);
ST_FUNC বর্ণ *pstrncpy(বর্ণ *out, size_t buf_size, ধ্রুব বর্ণ *s, size_t অঙ্ক);
PUB_FUNC বর্ণ *tcc_basename(ধ্রুব বর্ণ *name);
PUB_FUNC বর্ণ *tcc_fileextension (ধ্রুব বর্ণ *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC শূন্য tcc_free(শূন্য *ptr);
PUB_FUNC শূন্য *tcc_malloc(unsigned long size);
PUB_FUNC শূন্য *tcc_mallocz(unsigned long size);
PUB_FUNC শূন্য *tcc_realloc(শূন্য *ptr, unsigned long size);
PUB_FUNC বর্ণ *tcc_strdup(ধ্রুব বর্ণ *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC শূন্য tcc_free_debug(শূন্য *ptr);
PUB_FUNC শূন্য *tcc_malloc_debug(unsigned long size, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি);
PUB_FUNC শূন্য *tcc_mallocz_debug(unsigned long size, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি);
PUB_FUNC শূন্য *tcc_realloc_debug(শূন্য *ptr, unsigned long size, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি);
PUB_FUNC বর্ণ *tcc_strdup_debug(ধ্রুব বর্ণ *str, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি);
#endif

ST_FUNC শূন্য libc_free(শূন্য *ptr);
/* defined to be not used */
#define মুক্ত(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC পূর্ণাঙ্ক _tcc_error_noabort(ধ্রুব বর্ণ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN শূন্য _tcc_error(ধ্রুব বর্ণ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC শূন্য _tcc_warning(ধ্রুব বর্ণ *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(বার্তা) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,বার্তা)

/* other utilities */
ST_FUNC শূন্য dynarray_add(শূন্য *ptab, পূর্ণাঙ্ক *nb_ptr, শূন্য *data);
ST_FUNC শূন্য dynarray_reset(শূন্য *pp, পূর্ণাঙ্ক *n);
ST_INLN শূন্য cstr_ccat(CString *cstr, পূর্ণাঙ্ক ch);
ST_FUNC শূন্য cstr_cat(CString *cstr, ধ্রুব বর্ণ *str, পূর্ণাঙ্ক len);
ST_FUNC শূন্য cstr_wccat(CString *cstr, পূর্ণাঙ্ক ch);
ST_FUNC শূন্য cstr_new(CString *cstr);
ST_FUNC শূন্য cstr_free(CString *cstr);
ST_FUNC পূর্ণাঙ্ক cstr_printf(CString *cs, ধ্রুব বর্ণ *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC পূর্ণাঙ্ক cstr_vprintf(CString *cstr, ধ্রুব বর্ণ *fmt, va_list ap);
ST_FUNC শূন্য cstr_reset(CString *cstr);
ST_FUNC শূন্য tcc_open_bf(TCCState *s1, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক initlen);
ST_FUNC পূর্ণাঙ্ক tcc_open(TCCState *s1, ধ্রুব বর্ণ *filename);
ST_FUNC শূন্য tcc_close(শূন্য);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_ঠেলো(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_বের_করো() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_ঠেলো(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_বের_করো())

ST_FUNC পূর্ণাঙ্ক tcc_add_file_internal(TCCState *s1, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flags);
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
ST_FUNC পূর্ণাঙ্ক tcc_add_crt(TCCState *s, ধ্রুব বর্ণ *filename);
#endif
ST_FUNC পূর্ণাঙ্ক tcc_add_dll(TCCState *s, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flags);
ST_FUNC পূর্ণাঙ্ক tcc_add_support(TCCState *s1, ধ্রুব বর্ণ *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC শূন্য tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC শূন্য tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC শূন্য tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC পূর্ণাঙ্ক tcc_add_library_err(TCCState *s, ধ্রুব বর্ণ *f);
PUB_FUNC শূন্য tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC পূর্ণাঙ্ক tcc_parse_args(TCCState *s, পূর্ণাঙ্ক *argc, বর্ণ ***argv);
#ifdef _WIN32
ST_FUNC বর্ণ *normalize_slashes(বর্ণ *path);
PUB_FUNC FILE *tcc_fopen(ধ্রুব বর্ণ *f, ধ্রুব বর্ণ *m);
PUB_FUNC পূর্ণাঙ্ক tcc_fclose(FILE *f);
#অন্যথা
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ধ্রুব বর্ণ *dllname, পূর্ণাঙ্ক level);
ST_FUNC বর্ণ *tcc_load_text(পূর্ণাঙ্ক fd);
/* for #pragma once */
ST_FUNC পূর্ণাঙ্ক normalized_PATHCMP(ধ্রুব বর্ণ *f1, ধ্রুব বর্ণ *f2);

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

ST_DATA সংরচনা BufferedFile *file;
ST_DATA পূর্ণাঙ্ক tok;
ST_DATA CValue tokc;
ST_DATA ধ্রুব পূর্ণাঙ্ক *macro_ptr;
ST_DATA পূর্ণাঙ্ক parse_flags;
ST_DATA পূর্ণাঙ্ক tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA পূর্ণাঙ্ক tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA পূর্ণাঙ্ক pp_রাশিমালা;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_অঙ্ক    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_অঙ্ক 4

গণনা সারি_macro_output_format {
    সারি_MACRO_OUTPUT_FORMAT_GCC,
    সারি_MACRO_OUTPUT_FORMAT_NONE,
    সারি_MACRO_OUTPUT_FORMAT_STD,
    সারি_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ধ্রুব বর্ণ *str, পূর্ণাঙ্ক len);
ST_FUNC পূর্ণাঙ্ক tok_alloc_const(ধ্রুব বর্ণ *str);
ST_FUNC ধ্রুব বর্ণ *get_tok_str(পূর্ণাঙ্ক v, CValue *cv);
ST_FUNC শূন্য begin_macro(TokenString *str, পূর্ণাঙ্ক alloc);
ST_FUNC শূন্য end_macro(শূন্য);
ST_FUNC পূর্ণাঙ্ক set_idnum(পূর্ণাঙ্ক c, পূর্ণাঙ্ক val);
ST_INLN শূন্য tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(শূন্য);
ST_FUNC শূন্য tok_str_free(TokenString *s);
ST_FUNC শূন্য tok_str_free_str(পূর্ণাঙ্ক *str);
ST_FUNC শূন্য tok_str_add(TokenString *s, পূর্ণাঙ্ক t);
ST_FUNC শূন্য tok_str_add_tok(TokenString *s);
ST_INLN শূন্য define_ঠেলো(পূর্ণাঙ্ক v, পূর্ণাঙ্ক macro_type, পূর্ণাঙ্ক *str, Sym *first_arg);
ST_FUNC শূন্য define_undef(Sym *s);
ST_INLN Sym *define_find(পূর্ণাঙ্ক v);
ST_FUNC শূন্য free_defines(Sym *b);
ST_FUNC শূন্য parse_define(শূন্য);
ST_FUNC শূন্য skip_to_eol(পূর্ণাঙ্ক warn);
ST_FUNC শূন্য preprocess(পূর্ণাঙ্ক is_bof);
ST_FUNC শূন্য next(শূন্য);
ST_INLN শূন্য unget_tok(পূর্ণাঙ্ক last_tok);
ST_FUNC শূন্য preprocess_start(TCCState *s1, পূর্ণাঙ্ক filetype);
ST_FUNC শূন্য preprocess_end(TCCState *s1);
ST_FUNC শূন্য tccpp_new(TCCState *s);
ST_FUNC শূন্য tccpp_delete(TCCState *s);
ST_FUNC শূন্য tccpp_putfile(ধ্রুব বর্ণ *filename);
ST_FUNC পূর্ণাঙ্ক tcc_preprocess(TCCState *s1);
ST_FUNC শূন্য skip(পূর্ণাঙ্ক c);
ST_FUNC NORETURN শূন্য expect(ধ্রুব বর্ণ *বার্তা);
ST_FUNC শূন্য pp_error(CString *cs);


/* space excluding newline */
স্থির অন্তঃস্থ পূর্ণাঙ্ক is_space(পূর্ণাঙ্ক ch) {
    প্রত্যাগম ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
স্থির অন্তঃস্থ পূর্ণাঙ্ক isid(পূর্ণাঙ্ক c) {
    প্রত্যাগম (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
স্থির অন্তঃস্থ পূর্ণাঙ্ক isnum(পূর্ণাঙ্ক c) {
    প্রত্যাগম c >= '0' && c <= '9';
}
স্থির অন্তঃস্থ পূর্ণাঙ্ক isoct(পূর্ণাঙ্ক c) {
    প্রত্যাগম c >= '0' && c <= '7';
}
স্থির অন্তঃস্থ পূর্ণাঙ্ক toup(পূর্ণাঙ্ক c) {
    প্রত্যাগম (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / পরিমাণ(Sym))

ST_DATA Sym *global_স্তূপ;
ST_DATA Sym *local_স্তূপ;
ST_DATA Sym *local_label_স্তূপ;
ST_DATA Sym *global_label_স্তূপ;
ST_DATA Sym *define_স্তূপ;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA পূর্ণাঙ্ক rsym, anon_sym, ind, loc;
ST_DATA বর্ণ debug_modes;

ST_DATA পূর্ণাঙ্ক nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA পূর্ণাঙ্ক global_রাশিমালা;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA পূর্ণাঙ্ক func_var; /* true if current function is variadic */
ST_DATA পূর্ণাঙ্ক func_vc; /* stack address for implicit struct return storage */
ST_DATA পূর্ণাঙ্ক func_ind; /* function start address */
ST_DATA ধ্রুব বর্ণ *funcname;

ST_FUNC শূন্য tccgen_init(TCCState *s1);
ST_FUNC পূর্ণাঙ্ক tccgen_compile(TCCState *s1);
ST_FUNC শূন্য tccgen_finish(TCCState *s1);
ST_FUNC শূন্য check_vstack(শূন্য);

ST_INLN পূর্ণাঙ্ক is_float(পূর্ণাঙ্ক t);
ST_FUNC পূর্ণাঙ্ক ieee_finite(দ্বিগুণ d);
ST_FUNC পূর্ণাঙ্ক exact_log2p1(পূর্ণাঙ্ক i);
ST_FUNC শূন্য test_lvalue(শূন্য);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC শূন্য update_storage(Sym *sym);
ST_FUNC শূন্য put_extern_sym2(Sym *sym, পূর্ণাঙ্ক sh_অঙ্ক, addr_t মান, unsigned long size, পূর্ণাঙ্ক can_add_underscore);
ST_FUNC শূন্য put_extern_sym(Sym *sym, Section *section, addr_t মান, unsigned long size);
#যদি PTR_SIZE == 4
ST_FUNC শূন্য greloc(Section *s, Sym *sym, unsigned long offset, পূর্ণাঙ্ক type);
#endif
ST_FUNC শূন্য greloca(Section *s, Sym *sym, unsigned long offset, পূর্ণাঙ্ক type, addr_t addend);

ST_INLN শূন্য sym_free(Sym *sym);
ST_FUNC Sym *sym_ঠেলো(পূর্ণাঙ্ক v, CType *type, পূর্ণাঙ্ক r, পূর্ণাঙ্ক c);
ST_FUNC শূন্য sym_বের_করো(Sym **ptop, Sym *b, পূর্ণাঙ্ক keep);
ST_FUNC Sym *sym_push2(Sym **ps, পূর্ণাঙ্ক v, পূর্ণাঙ্ক t, পূর্ণাঙ্ক c);
ST_FUNC Sym *sym_find2(Sym *s, পূর্ণাঙ্ক v);
ST_INLN Sym *sym_find(পূর্ণাঙ্ক v);
ST_FUNC Sym *label_find(পূর্ণাঙ্ক v);
ST_FUNC Sym *label_ঠেলো(Sym **ptop, পূর্ণাঙ্ক v, পূর্ণাঙ্ক flags);
ST_FUNC শূন্য label_বের_করো(Sym **ptop, Sym *slast, পূর্ণাঙ্ক keep);
ST_INLN Sym *struct_find(পূর্ণাঙ্ক v);

ST_FUNC Sym *global_identifier_ঠেলো(পূর্ণাঙ্ক v, পূর্ণাঙ্ক t, পূর্ণাঙ্ক c);
ST_FUNC Sym *external_global_sym(পূর্ণাঙ্ক v, CType *type);
ST_FUNC Sym *external_helper_sym(পূর্ণাঙ্ক v);
ST_FUNC শূন্য vpush_helper_func(পূর্ণাঙ্ক v);
ST_FUNC শূন্য vset(CType *type, পূর্ণাঙ্ক r, পূর্ণাঙ্ক v);
ST_FUNC শূন্য vset_VT_CMP(পূর্ণাঙ্ক op);
ST_FUNC শূন্য vpushi(পূর্ণাঙ্ক v);
ST_FUNC শূন্য vpushv(SValue *v);
ST_FUNC শূন্য vpushsym(CType *type, Sym *sym);
ST_FUNC শূন্য vswap(শূন্য);
ST_FUNC শূন্য vrott(পূর্ণাঙ্ক n);
ST_FUNC শূন্য vrotb(পূর্ণাঙ্ক n);
ST_FUNC শূন্য vrev(পূর্ণাঙ্ক n);
ST_FUNC শূন্য vpop(শূন্য);
#যদি PTR_SIZE == 4
ST_FUNC শূন্য lexpand(শূন্য);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC পূর্ণাঙ্ক get_reg_ex(পূর্ণাঙ্ক rc, পূর্ণাঙ্ক rc2);
#endif
ST_FUNC শূন্য save_reg(পূর্ণাঙ্ক r);
ST_FUNC শূন্য save_reg_upstack(পূর্ণাঙ্ক r, পূর্ণাঙ্ক n);
ST_FUNC পূর্ণাঙ্ক get_reg(পূর্ণাঙ্ক rc);
ST_FUNC শূন্য save_regs(পূর্ণাঙ্ক n);
ST_FUNC শূন্য gaddrof(শূন্য);
ST_FUNC পূর্ণাঙ্ক gv(পূর্ণাঙ্ক rc);
ST_FUNC শূন্য gv2(পূর্ণাঙ্ক rc1, পূর্ণাঙ্ক rc2);
ST_FUNC শূন্য gen_op(পূর্ণাঙ্ক op);
ST_FUNC পূর্ণাঙ্ক type_size(CType *type, পূর্ণাঙ্ক *a);
ST_FUNC শূন্য mk_pointer(CType *type);
ST_FUNC শূন্য vstore(শূন্য);
ST_FUNC শূন্য inc(পূর্ণাঙ্ক post, পূর্ণাঙ্ক c);
ST_FUNC CString* parse_mult_str(ধ্রুব বর্ণ *বার্তা);
ST_FUNC CString* parse_asm_str(শূন্য);
ST_FUNC শূন্য indir(শূন্য);
ST_FUNC শূন্য unary(শূন্য);
ST_FUNC শূন্য gexpr(শূন্য);
ST_FUNC পূর্ণাঙ্ক রাশিমালা_const(শূন্য);
#যদি defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#যদি defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC পূর্ণাঙ্ক classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC শূন্য gbound_args(পূর্ণাঙ্ক nb_args);
ST_DATA পূর্ণাঙ্ক func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, পূর্ণাঙ্ক c, পূর্ণাঙ্ক byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_দ্বিমিক 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

প্রকারনির্দেশ সংরচনা {
    unsigned পূর্ণাঙ্ক n_strx;         /* index into string table of name */
    unsigned বর্ণ n_type;         /* type of symbol */
    unsigned বর্ণ n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned পূর্ণাঙ্ক n_মান;        /* value of symbol */
} Stab_Sym;

ST_FUNC শূন্য tccelf_new(TCCState *s);
ST_FUNC শূন্য tccelf_delete(TCCState *s);
ST_FUNC শূন্য tccelf_begin_file(TCCState *s1);
ST_FUNC শূন্য tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ধ্রুব বর্ণ *name, পূর্ণাঙ্ক sh_type, পূর্ণাঙ্ক sh_flags);
ST_FUNC শূন্য section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, পূর্ণাঙ্ক align);
ST_FUNC শূন্য *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, ধ্রুব বর্ণ *name);
ST_FUNC শূন্য free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ধ্রুব বর্ণ *symtab_name, পূর্ণাঙ্ক sh_type, পূর্ণাঙ্ক sh_flags, ধ্রুব বর্ণ *strtab_name, ধ্রুব বর্ণ *hash_name, পূর্ণাঙ্ক hash_sh_flags);
ST_FUNC শূন্য init_symtab(Section *s);

ST_FUNC পূর্ণাঙ্ক put_elf_str(Section *s, ধ্রুব বর্ণ *sym);
ST_FUNC পূর্ণাঙ্ক put_elf_sym(Section *s, addr_t মান, unsigned long size, পূর্ণাঙ্ক info, পূর্ণাঙ্ক other, পূর্ণাঙ্ক shndx, ধ্রুব বর্ণ *name);
ST_FUNC পূর্ণাঙ্ক set_elf_sym(Section *s, addr_t মান, unsigned long size, পূর্ণাঙ্ক info, পূর্ণাঙ্ক other, পূর্ণাঙ্ক shndx, ধ্রুব বর্ণ *name);
ST_FUNC পূর্ণাঙ্ক find_elf_sym(Section *s, ধ্রুব বর্ণ *name);
ST_FUNC শূন্য put_elf_reloc(Section *symtab, Section *s, unsigned long offset, পূর্ণাঙ্ক type, পূর্ণাঙ্ক প্রতীক);
ST_FUNC শূন্য put_elf_reloca(Section *symtab, Section *s, unsigned long offset, পূর্ণাঙ্ক type, পূর্ণাঙ্ক প্রতীক, addr_t addend);

ST_FUNC শূন্য resolve_common_syms(TCCState *s1);
ST_FUNC শূন্য relocate_syms(TCCState *s1, Section *symtab, পূর্ণাঙ্ক do_resolve);
ST_FUNC শূন্য relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(পূর্ণাঙ্ক fd, শূন্য *buf, size_t গুনতি_2);
ST_FUNC শূন্য *load_data(পূর্ণাঙ্ক fd, unsigned long file_offset, unsigned long size);
ST_FUNC পূর্ণাঙ্ক tcc_object_type(পূর্ণাঙ্ক fd, ElfW(Ehdr) *h);
ST_FUNC পূর্ণাঙ্ক tcc_load_object_file(TCCState *s1, পূর্ণাঙ্ক fd, unsigned long file_offset);
ST_FUNC পূর্ণাঙ্ক tcc_load_archive(TCCState *s1, পূর্ণাঙ্ক fd, পূর্ণাঙ্ক alacarte);
ST_FUNC শূন্য add_array(TCCState *s1, ধ্রুব বর্ণ *sec, পূর্ণাঙ্ক c);

ST_FUNC সংরচনা sym_attr *get_sym_attr(TCCState *s1, পূর্ণাঙ্ক index, পূর্ণাঙ্ক alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ধ্রুব বর্ণ *name, পূর্ণাঙ্ক err, পূর্ণাঙ্ক forc);
ST_FUNC শূন্য list_elf_symbols(TCCState *s, শূন্য *ctx,
    শূন্য (*প্রতীক_cb)(শূন্য *ctx, ধ্রুব বর্ণ *name, ধ্রুব শূন্য *val));
ST_FUNC পূর্ণাঙ্ক set_global_sym(TCCState *s1, ধ্রুব বর্ণ *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    প্রতি (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC পূর্ণাঙ্ক tcc_load_dll(TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক level);
ST_FUNC পূর্ণাঙ্ক tcc_load_ldscript(TCCState *s1, পূর্ণাঙ্ক fd);
ST_FUNC শূন্য tccelf_add_crtbegin(TCCState *s1);
ST_FUNC শূন্য tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC শূন্য tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC পূর্ণাঙ্ক code_reloc (পূর্ণাঙ্ক reloc_type);
ST_FUNC পূর্ণাঙ্ক gotplt_entry_type (পূর্ণাঙ্ক reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
গণনা gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#যদি !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, সংরচনা sym_attr *attr);
ST_FUNC শূন্য relocate_plt(TCCState *s1);
ST_FUNC শূন্য build_got_entries(TCCState *s1, পূর্ণাঙ্ক got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC শূন্য relocate(TCCState *s1, ElfW_Rel *rel, পূর্ণাঙ্ক type, unsigned বর্ণ *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA ধ্রুব বর্ণ * ধ্রুব target_machine_defs;
ST_DATA ধ্রুব পূর্ণাঙ্ক reg_classes[NB_REGS];

ST_FUNC শূন্য gsym_addr(পূর্ণাঙ্ক t, পূর্ণাঙ্ক a);
ST_FUNC শূন্য gsym(পূর্ণাঙ্ক t);
ST_FUNC শূন্য load(পূর্ণাঙ্ক r, SValue *sv);
ST_FUNC শূন্য store(পূর্ণাঙ্ক r, SValue *v);
ST_FUNC পূর্ণাঙ্ক gfunc_sret(CType *vt, পূর্ণাঙ্ক variadic, CType *ret, পূর্ণাঙ্ক *align, পূর্ণাঙ্ক *regsize);
ST_FUNC শূন্য gfunc_call(পূর্ণাঙ্ক nb_args);
ST_FUNC শূন্য gfunc_prolog(Sym *func_sym);
ST_FUNC শূন্য gfunc_epilog(শূন্য);
ST_FUNC শূন্য gen_fill_nops(পূর্ণাঙ্ক);
ST_FUNC পূর্ণাঙ্ক gjmp(পূর্ণাঙ্ক t);
ST_FUNC শূন্য gjmp_addr(পূর্ণাঙ্ক a);
ST_FUNC পূর্ণাঙ্ক gjmp_cond(পূর্ণাঙ্ক op, পূর্ণাঙ্ক t);
ST_FUNC পূর্ণাঙ্ক gjmp_append(পূর্ণাঙ্ক n, পূর্ণাঙ্ক t);
ST_FUNC শূন্য gen_opi(পূর্ণাঙ্ক op);
ST_FUNC শূন্য gen_opf(পূর্ণাঙ্ক op);
ST_FUNC শূন্য gen_cvt_ftoi(পূর্ণাঙ্ক t);
ST_FUNC শূন্য gen_cvt_itof(পূর্ণাঙ্ক t);
ST_FUNC শূন্য gen_cvt_ftof(পূর্ণাঙ্ক t);
ST_FUNC শূন্য ggoto(শূন্য);
#ifndef TCC_TARGET_C67
ST_FUNC শূন্য o(unsigned পূর্ণাঙ্ক c);
#endif
ST_FUNC শূন্য gen_vla_sp_save(পূর্ণাঙ্ক addr);
ST_FUNC শূন্য gen_vla_sp_restore(পূর্ণাঙ্ক addr);
ST_FUNC শূন্য gen_vla_alloc(CType *type, পূর্ণাঙ্ক align);

স্থির অন্তঃস্থ uint16_t read16le(unsigned বর্ণ *p) {
    প্রত্যাগম p[0] | (uint16_t)p[1] << 8;
}
স্থির অন্তঃস্থ শূন্য write16le(unsigned বর্ণ *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
স্থির অন্তঃস্থ uint32_t read32le(unsigned বর্ণ *p) {
  প্রত্যাগম read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
স্থির অন্তঃস্থ শূন্য write32le(unsigned বর্ণ *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
স্থির অন্তঃস্থ শূন্য add32le(unsigned বর্ণ *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
স্থির অন্তঃস্থ uint64_t read64le(unsigned বর্ণ *p) {
  প্রত্যাগম read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
স্থির অন্তঃস্থ শূন্য write64le(unsigned বর্ণ *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
স্থির অন্তঃস্থ শূন্য add64le(unsigned বর্ণ *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#যদি defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC শূন্য g(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le16(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le32(পূর্ণাঙ্ক c);
#endif
#যদি defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC শূন্য gen_addr32(পূর্ণাঙ্ক r, Sym *sym, পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_addrpc32(পূর্ণাঙ্ক r, Sym *sym, পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_cvt_csti(পূর্ণাঙ্ক t);
ST_FUNC শূন্য gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC শূন্য gen_opl(পূর্ণাঙ্ক op);
#ifdef TCC_TARGET_PE
ST_FUNC শূন্য gen_vla_result(পূর্ণাঙ্ক addr);
#endif
ST_FUNC শূন্য gen_cvt_sxtw(শূন্য);
ST_FUNC শূন্য gen_cvt_csti(পূর্ণাঙ্ক t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#যদি defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ধ্রুব বর্ণ *default_elfinterp(সংরচনা TCCState *s);
#endif
ST_FUNC শূন্য arm_init(সংরচনা TCCState *s);
ST_FUNC শূন্য gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC শূন্য gen_opl(পূর্ণাঙ্ক op);
ST_FUNC শূন্য gfunc_return(CType *func_type);
ST_FUNC শূন্য gen_va_start(শূন্য);
ST_FUNC শূন্য gen_va_arg(CType *t);
ST_FUNC শূন্য gen_clear_cache(শূন্য);
ST_FUNC শূন্য gen_cvt_sxtw(শূন্য);
ST_FUNC শূন্য gen_cvt_csti(পূর্ণাঙ্ক t);
ST_FUNC শূন্য gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC শূন্য gen_opl(পূর্ণাঙ্ক op);
ST_FUNC শূন্য gen_va_start(শূন্য);
ST_FUNC শূন্য arch_transfer_ret_regs(পূর্ণাঙ্ক);
ST_FUNC শূন্য gen_cvt_sxtw(শূন্য);
ST_FUNC শূন্য gen_cvt_csti(পূর্ণাঙ্ক t);
ST_FUNC শূন্য gen_increment_tcov (SValue *sv);
ST_FUNC শূন্য gen_clear_cache(শূন্য);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC পূর্ণাঙ্ক tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC পূর্ণাঙ্ক tcc_load_coff(TCCState * s1, পূর্ণাঙ্ক fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC শূন্য asm_instr(শূন্য);
ST_FUNC শূন্য asm_global_instr(শূন্য);
ST_FUNC পূর্ণাঙ্ক tcc_assemble(TCCState *s1, পূর্ণাঙ্ক do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC পূর্ণাঙ্ক find_constraint(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, ধ্রুব বর্ণ *name, ধ্রুব বর্ণ **pp);
ST_FUNC Sym* get_asm_sym(পূর্ণাঙ্ক name, Sym *csym);
ST_FUNC শূন্য asm_রাশিমালা(TCCState *s1, রাশিমালা_মান *pe);
ST_FUNC পূর্ণাঙ্ক asm_int_রাশিমালা(TCCState *s1);
#যদি PTR_SIZE == 8
ST_FUNC শূন্য gen_expr64(রাশিমালা_মান *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC শূন্য gen_expr32(রাশিমালা_মান *pe);
ST_FUNC শূন্য asm_opcode(TCCState *s1, পূর্ণাঙ্ক opcode);
ST_FUNC পূর্ণাঙ্ক asm_parse_regvar(পূর্ণাঙ্ক t);
ST_FUNC শূন্য asm_compute_constraints(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs, ধ্রুব uint8_t *clobber_regs, পূর্ণাঙ্ক *pout_reg);
ST_FUNC শূন্য subst_asm_operand(CString *add_str, SValue *sv, পূর্ণাঙ্ক modifier);
ST_FUNC শূন্য asm_gen_code(ASMOperand *operands, পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs, পূর্ণাঙ্ক is_output, uint8_t *clobber_regs, পূর্ণাঙ্ক out_reg);
ST_FUNC শূন্য asm_clobber(uint8_t *clobber_regs, ধ্রুব বর্ণ *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC পূর্ণাঙ্ক pe_load_file(সংরচনা TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *filename);
ST_FUNC পূর্ণাঙ্ক pe_output_file(TCCState * s1, ধ্রুব বর্ণ *filename);
ST_FUNC পূর্ণাঙ্ক pe_putimport(TCCState *s1, পূর্ণাঙ্ক dllindex, ধ্রুব বর্ণ *name, addr_t মান);
ST_FUNC পূর্ণাঙ্ক pe_setsubsy(TCCState *s1, ধ্রুব বর্ণ *arg);
#যদি defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#যদি defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC শূন্য pe_add_unwind_data(unsigned start, unsigned end, unsigned স্তূপ);
#endif
PUB_FUNC পূর্ণাঙ্ক tcc_get_dllexports(ধ্রুব বর্ণ *filename, বর্ণ **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC পূর্ণাঙ্ক macho_output_file(TCCState * s1, ধ্রুব বর্ণ *filename);
ST_FUNC পূর্ণাঙ্ক macho_load_dll(TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক lev);
ST_FUNC পূর্ণাঙ্ক macho_load_tbd(TCCState *s1, পূর্ণাঙ্ক fd, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক lev);
#ifdef TCC_IS_NATIVE
ST_FUNC শূন্য tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC বর্ণ* macho_tbd_soname(পূর্ণাঙ্ক fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    রিক্ত
/* dummy function for profiling */
ST_FUNC শূন্য *dlopen(ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flag);
ST_FUNC শূন্য dlclose(শূন্য *p);
ST_FUNC ধ্রুব বর্ণ *dlerror(শূন্য);
ST_FUNC শূন্য *dlsym(শূন্য *handle, ধ্রুব বর্ণ *প্রতীক);
#endif
ST_FUNC শূন্য tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#যদি 0 /* included in tcc.c */
ST_FUNC পূর্ণাঙ্ক tcc_tool_ar(TCCState *s, পূর্ণাঙ্ক argc, বর্ণ **argv);
#ifdef TCC_TARGET_PE
ST_FUNC পূর্ণাঙ্ক tcc_tool_impdef(TCCState *s, পূর্ণাঙ্ক argc, বর্ণ **argv);
#endif
ST_FUNC পূর্ণাঙ্ক tcc_tool_cross(TCCState *s, বর্ণ **argv, পূর্ণাঙ্ক option);
ST_FUNC পূর্ণাঙ্ক gen_makedeps(TCCState *s, ধ্রুব বর্ণ *target, ধ্রুব বর্ণ *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC শূন্য tcc_debug_new(TCCState *s);

ST_FUNC শূন্য tcc_debug_start(TCCState *s1);
ST_FUNC শূন্য tcc_debug_end(TCCState *s1);
ST_FUNC শূন্য tcc_debug_bincl(TCCState *s1);
ST_FUNC শূন্য tcc_debug_eincl(TCCState *s1);
ST_FUNC শূন্য tcc_debug_newfile(TCCState *s1);

ST_FUNC শূন্য tcc_debug_সারি(TCCState *s1);
ST_FUNC শূন্য tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC শূন্য tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC শূন্য tcc_debug_prolog_epilog(TCCState *s1, পূর্ণাঙ্ক মান);
ST_FUNC শূন্য tcc_debug_funcend(TCCState *s1, পূর্ণাঙ্ক size);
ST_FUNC শূন্য tcc_debug_extern_sym(TCCState *s1, Sym *sym, পূর্ণাঙ্ক sh_অঙ্ক, পূর্ণাঙ্ক sym_bind, পূর্ণাঙ্ক sym_type);
ST_FUNC শূন্য tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC শূন্য tcc_debug_stabn(TCCState *s1, পূর্ণাঙ্ক type, পূর্ণাঙ্ক মান);
ST_FUNC শূন্য tcc_debug_fix_forw(TCCState *s1, CType *t);

#যদি !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC শূন্য tcc_eh_frame_start(TCCState *s1);
ST_FUNC শূন্য tcc_eh_frame_end(TCCState *s1);
ST_FUNC শূন্য tcc_eh_frame_hdr(TCCState *s1, পূর্ণাঙ্ক final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC শূন্য tcc_tcov_start(TCCState *s1);
ST_FUNC শূন্য tcc_tcov_end(TCCState *s1);
ST_FUNC শূন্য tcc_tcov_check_সারি(TCCState *s1, পূর্ণাঙ্ক start);
ST_FUNC শূন্য tcc_tcov_block_end(TCCState *s1, পূর্ণাঙ্ক সারি);
ST_FUNC শূন্য tcc_tcov_block_begin(TCCState *s1);
ST_FUNC শূন্য tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_সারি_section      s1->dwarf_সারি_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_সারি_str_section  s1->dwarf_সারি_str_section

#define DWARF_MAX_128	((8 * পরিমাণ (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
স্থির অন্তঃস্থ uint64_t
dwarf_read_uleb128(unsigned বর্ণ **ln, unsigned বর্ণ *end)
{
    unsigned বর্ণ *cp = *ln;
    uint64_t retval = 0;
    পূর্ণাঙ্ক i;
    প্রতি (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	যদি ((byte & 0x80) == 0)
	    ভঙ্গ;
    }
    *ln = cp;
    প্রত্যাগম retval;
}
স্থির অন্তঃস্থ int64_t
dwarf_read_sleb128(unsigned বর্ণ **ln, unsigned বর্ণ *end)
{
    unsigned বর্ণ *cp = *ln;
    int64_t retval = 0;
    পূর্ণাঙ্ক i;
    প্রতি (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	যদি ((byte & 0x80) == 0) {
	    যদি ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    ভঙ্গ;
	}
    }
    *ln = cp;
    প্রত্যাগম retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#অন্যথা
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#যদি defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#অন্যথা
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#যদি CONFIG_TCC_SEMLOCK
#যদি defined _WIN32
প্রকারনির্দেশ সংরচনা { চঞ্চল LONG init; CRITICAL_SECTION cs; } TCCSem;
স্থির অন্তঃস্থ শূন্য wait_sem(TCCSem *p) {
    যদি (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } অন্যথা {
        যাবত্ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
স্থির অন্তঃস্থ শূন্য post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#নোচেদ্যদি defined __APPLE__
#অন্তর্ভাব <dispatch/dispatch.h>
প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক init; dispatch_semaphore_t sem; } TCCSem;
স্থির অন্তঃস্থ শূন্য wait_sem(TCCSem *p) {
    যদি (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
স্থির অন্তঃস্থ শূন্য post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#অন্যথা
#অন্তর্ভাব <semaphore.h>
প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক init; sem_t sem; } TCCSem;
স্থির অন্তঃস্থ শূন্য wait_sem(TCCSem *p) {
    যদি (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    যাবত্ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
স্থির অন্তঃস্থ শূন্য post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#অন্যথা
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#যদি ONE_SOURCE
#define ST_DATA স্থির
#অন্যথা
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
#define total_সারিগুলি         TCC_STATE_VAR(total_সারিগুলি)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC শূন্য tcc_enter_state(TCCState *s1);
PUB_FUNC শূন্য tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_অঙ্ক = offsetof(TCCState, sw) \
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
#অন্যথা
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
