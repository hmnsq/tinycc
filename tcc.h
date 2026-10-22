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
#include "config.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#include <string.h>
#include <errno.h>
#include <math.h>
#include <fcntl.h>
#include <setjmp.h>
#include <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
extern float strtof (const var_na *__nptr, var_na **__endptr);
extern long dviguu_na strtold (const var_na *__nptr, var_na **__endptr);
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
# define anta_hstha __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long dviguu_na)strtod
#  define strtof (float)strtod
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
# ꦪꦼꦤ꧀ defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_BINARY
# define O_BINARY 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#ꦭꦶꦪ
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (parimaa_na(tab) / parimaa_na((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#ꦭꦶꦪ
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#ꦭꦶꦪ
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
#ꦪꦼꦤ꧀ !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# ꦪꦼꦤ꧀ defined __x86_64__
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
# ꦭꦶꦪ
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
#ꦪꦼꦤ꧀ defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# ꦪꦼꦤ꧀ defined __i386__ && defined TCC_TARGET_I386
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

#ꦪꦼꦤ꧀ defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#ꦭꦶꦪ
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#ꦪꦼꦤ꧀ defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#ꦭꦶꦪ
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#ꦪꦼꦤ꧀ defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#ꦭꦶꦪ
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#ꦪꦼꦤ꧀ defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#elif !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#ꦪꦼꦤ꧀ defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#ꦭꦶꦪ
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#ꦪꦼꦤ꧀ defined TCC_TARGET_PE \
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

#ꦪꦼꦤ꧀ !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#ꦭꦶꦪ
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
# ꦪꦼꦤ꧀ defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# ꦭꦶꦪ
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# ꦪꦼꦤ꧀ defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# ꦭꦶꦪ
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# ꦪꦼꦤ꧀ defined __GNU__
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
# ꦭꦶꦪ
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

#include "libtcc.h"
#include "elf.h"
#include "stab.h"
#include "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#ꦪꦼꦤ꧀ ONE_SOURCE
#define ST_INLN static anta_hstha
#define ST_FUNC static
#define ST_DATA static
#ꦭꦶꦪ
#define ST_INLN
#define ST_FUNC
#define ST_DATA extern
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define static
# define anta_hstha
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#elif defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#elif defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#elif defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#elif defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#elif defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#ꦭꦶꦪ
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#ꦪꦼꦤ꧀ PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#ꦭꦶꦪ
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

#ꦪꦼꦤ꧀ PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#ꦭꦶꦪ
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_STACK_SIZE  32
#define IFDEF_STACK_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_STACK_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
typedef sa_nracanaa TokenSym {
    sa_nracanaa TokenSym *hash_next;
    sa_nracanaa Sym *sym_define; /* direct pointer to define */
    sa_nracanaa Sym *sym_label; /* direct pointer to label */
    sa_nracanaa Sym *sym_struct; /* direct pointer to structure */
    sa_nracanaa Sym *sym_identifier; /* direct pointer to identifier */
    puur_naa_nka tok; /* token number */
    puur_naa_nka len;
    var_na str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
typedef unsigned short nwchar_t;
#ꦭꦶꦪ
typedef puur_naa_nka nwchar_t;
#endif

typedef sa_nracanaa CString {
    puur_naa_nka size; /* size in bytes */
    puur_naa_nka size_allocated;
    var_na *data; /* nwchar_t* in cases */
} CString;

/* type definition */
typedef sa_nracanaa CType {
    puur_naa_nka t;
    sa_nracanaa Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_WORDS ((parimaa_na(long dviguu_na)+3)/4)

/* constant value */
typedef sa_ngha CValue {
    long dviguu_na ld;
    dviguu_na d;
    float f;
    uint64_t i;
    sa_nracanaa {
        var_na *data;
        puur_naa_nka size;
    } str;
    puur_naa_nka tab[LDOUBLE_WORDS];
} CValue;

/* value on stack */
typedef sa_nracanaa SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    sa_ngha {
      sa_nracanaa { puur_naa_nka jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    sa_ngha {
      sa_nracanaa { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      sa_nracanaa Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
sa_nracanaa SymAttr {
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
sa_nracanaa FuncAttr {
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
typedef sa_nracanaa Sym {
    puur_naa_nka v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    sa_nracanaa SymAttr a; /* symbol attributes */
    sa_ngha {
        sa_nracanaa {
            puur_naa_nka c; /* associated number or Elf symbol index */
            sa_ngha {
                puur_naa_nka sym_scope; /* scope level for locals */
                puur_naa_nka jnext; /* next jump label */
                puur_naa_nka jind; /* label position */
                sa_nracanaa FuncAttr f; /* function attributes */
                puur_naa_nka auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        puur_naa_nka *d; /* define token stream */
        sa_nracanaa Sym *cleanup_func;
    };

    CType type; /* associated type */
    sa_ngha {
        sa_nracanaa Sym *next; /* next related symbol (for fields and anoms) */
        puur_naa_nka *e; /* expanded token stream with preprocessor macros */
        puur_naa_nka asm_label; /* associated asm label */
        sa_nracanaa Sym *cleanupstate; /* in defined labels */
        puur_naa_nka *vla_array_str; /* vla array code */
    };
    sa_nracanaa Sym *prev; /* prev symbol in stack */
    sa_ngha {
        sa_nracanaa Sym *prev_tok; /* previous symbol for this token */
        sa_nracanaa Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        sa_nracanaa Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
typedef sa_nracanaa Section {
    unsigned long data_offset; /* current data offset */
    unsigned var_na *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    puur_naa_nka sh_name;             /* elf section name (only used during output) */
    puur_naa_nka sh_num;              /* elf section number */
    puur_naa_nka sh_type;             /* elf section type */
    puur_naa_nka sh_flags;            /* elf section flags */
    puur_naa_nka sh_info;             /* elf section info */
    puur_naa_nka sh_addralign;        /* elf section alignment */
    puur_naa_nka sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    puur_naa_nka nb_hashed_syms;      /* used to resize the hash table */
    sa_nracanaa Section *link;    /* link to another section */
    sa_nracanaa Section *reloc;   /* corresponding section for relocation, if any */
    sa_nracanaa Section *hash;    /* hash table for symbols */
    sa_nracanaa Section *prev;    /* previous section on section stack */
    var_na name[1];           /* section name */
} Section;

typedef sa_nracanaa DLLReference {
    puur_naa_nka level;
    void *handle;
    unsigned var_na found, index;
    var_na name[1];
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

typedef sa_nracanaa BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    puur_naa_nka fd;
    sa_nracanaa BufferedFile *prev;
    puur_naa_nka line_num;    /* current line number - here to simplify code */
    puur_naa_nka line_ref;    /* tcc -E: last printed line */
    puur_naa_nka ifndef_macro;  /* #ifndef macro / #endif search */
    puur_naa_nka ifndef_macro_saved; /* saved ifndef_macro */
    puur_naa_nka *ifdef_stack_ptr; /* ifdef_stack value at the start of the file */
    puur_naa_nka include_next_index; /* next search path */
    puur_naa_nka prev_tok_flags; /* saved tok_flags */
    var_na filename[1024];    /* filename */
    var_na *true_filename; /* filename not modified by # line directive */
    unsigned var_na unget[4];
    unsigned var_na buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
typedef sa_nracanaa TokenString {
    puur_naa_nka *str;
    puur_naa_nka len;
    puur_naa_nka need_spc;
    puur_naa_nka allocated_len;
    puur_naa_nka last_line_num;
    puur_naa_nka save_line_num;
    /* used to chain token-strings with begin/end_macro() */
    sa_nracanaa TokenString *prev;
    const puur_naa_nka *prev_ptr;
    var_na alloc;
} TokenString;

/* GNUC attribute definition */
typedef sa_nracanaa AttributeDef {
    sa_nracanaa SymAttr a;
    sa_nracanaa FuncAttr f;
    sa_nracanaa Section *section;
    Sym *cleanup_func;
    puur_naa_nka alias_target; /* token */
    puur_naa_nka asm_label; /* associated asm label */
    var_na attr_mode; /* __attribute__((__mode__(...))) */
    var_na new_section; /* section is new */
} AttributeDef;

/* inline functions */
typedef sa_nracanaa InlineFunc {
    TokenString *func_str;
    Sym *sym;
    var_na filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
typedef sa_nracanaa CachedInclude {
    puur_naa_nka ifndef_macro;
    puur_naa_nka once;
    puur_naa_nka hash_next; /* -1 if none */
    var_na filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
typedef sa_nracanaa ExprValue {
    uint64_t v;
    Sym *sym;
    puur_naa_nka pcrel;
} ExprValue;

#define MAX_ASM_OPERANDS 30
typedef sa_nracanaa ASMOperand {
    puur_naa_nka id; /* GCC 3 optional identifier (0 if number only supported) */
    var_na constraint[16];
    var_na asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    puur_naa_nka ref_index; /* if >= 0, gives reference to a output constraint */
    puur_naa_nka input_index; /* if >= 0, gives reference to an input constraint */
    puur_naa_nka priority; /* priority, used to assign registers */
    puur_naa_nka reg; /* if >= 0, register number used for this operand */
    puur_naa_nka is_llong; /* true if double register value */
    puur_naa_nka is_memory; /* true if memory operand */
    puur_naa_nka is_rw;     /* for '+' modifier */
    puur_naa_nka is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
sa_nracanaa sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    puur_naa_nka plt_sym;
    puur_naa_nka dyn_index;
    unsigned var_na linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned var_na plt_thumb_stub:1;
#endif
};

sa_nracanaa TCCState {
    unsigned var_na verbose; /* if true, display some information during compilation */
    unsigned var_na nostdinc; /* if true, no standard headers are added */
    unsigned var_na nostdlib; /* if true, no standard libraries are added */
    unsigned var_na nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned var_na nocommon; /* if true, do not use common symbols for .bss data */
    unsigned var_na static_link; /* if true, static linking is performed */
    unsigned var_na rdynamic; /* if true, all symbols are exported */
    unsigned var_na symbolic; /* if true, resolve symbols in the current module first */
    unsigned var_na znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned var_na filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned var_na optimize; /* only to #define __OPTIMIZE__ */
    unsigned var_na option_pthread; /* -pthread option */
    unsigned var_na enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned puur_naa_nka  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned var_na char_is_unsigned;
    unsigned var_na leading_underscore;
    unsigned var_na ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned var_na dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned var_na ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned var_na reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned var_na gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned var_na unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned var_na warn_none;
    unsigned var_na warn_all;
    unsigned var_na warn_error;
    unsigned var_na warn_write_strings;
    unsigned var_na warn_unsupported;
    unsigned var_na warn_implicit_function_declaration;
    unsigned var_na warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned var_na warn_num; /* temp var for tcc_warning_c() */

    unsigned var_na option_r; /* option -r */
    unsigned var_na do_bench; /* option -bench */
    unsigned var_na just_deps; /* option -M  */
    unsigned var_na gen_deps; /* option -MD  */
    unsigned var_na include_sys_deps; /* option -MD  */
    unsigned var_na gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned var_na do_debug;
    unsigned var_na dwarf;
    unsigned var_na do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned var_na do_bounds_check;
#endif
    unsigned var_na test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned var_na gnu_ext;
    /* use TinyCC extensions */
    unsigned var_na tcc_ext;

    unsigned var_na dflag; /* -dX value */
    unsigned var_na Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned var_na nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned var_na float_abi; /* float ABI of the generated code*/
#endif

    unsigned var_na has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    puur_naa_nka seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    var_na *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    var_na *soname; /* as specified on the command line (-soname) */
    var_na *rpath; /* as specified on the command line (-Wl,-rpath=) */
    var_na *elfint; /* -Wl,-I... on command line */
    var_na *elf_entryname; /* "_start" unless set */
    var_na *init_symbol; /* symbols to call at load-time (not used currently) */
    var_na *fini_symbol; /* symbols to call at unload-time (not used currently) */
    var_na *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    puur_naa_nka output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    puur_naa_nka output_format;
    /* nth test to run with -dt -run */
    puur_naa_nka run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    puur_naa_nka nb_loaded_dlls;

    /* include paths */
    var_na **include_paths;
    puur_naa_nka nb_include_paths;

    var_na **sysinclude_paths;
    puur_naa_nka nb_sysinclude_paths;

    /* library paths */
    var_na **library_paths;
    puur_naa_nka nb_library_paths;

    /* crt?.o object path */
    var_na **crt_paths;
    puur_naa_nka nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    void *error_opaque;
    void (*error_func)(void *opaque, const var_na *msg);
    puur_naa_nka error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    puur_naa_nka nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    var_na **target_deps;
    puur_naa_nka nb_target_deps;

    /* compilation */
    BufferedFile *include_stack[INCLUDE_STACK_SIZE];
    BufferedFile **include_stack_ptr;

    puur_naa_nka ifdef_stack[IFDEF_STACK_SIZE];
    puur_naa_nka *ifdef_stack_ptr;

    /* included files enclosed with #ifndef MACRO */
    puur_naa_nka cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    puur_naa_nka nb_cached_includes;

    /* #pragma pack stack */
    puur_naa_nka pack_stack[PACK_STACK_SIZE];
    puur_naa_nka *pack_stack_ptr;
    var_na **pragma_libs;
    puur_naa_nka nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    sa_nracanaa InlineFunc **inline_fns;
    puur_naa_nka nb_inline_fns;

    /* sections */
    Section **sections;
    puur_naa_nka nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    puur_naa_nka nb_priv_sections; /* number of private sections */

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
    sa_ngha { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_line_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_line_str_section;
    puur_naa_nka dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    sa_nracanaa _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    sa_nracanaa sym_attr *sym_attrs;
    puur_naa_nka nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    sa_nracanaa pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    puur_naa_nka nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    puur_naa_nka pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_stack_size;
    addr_t pe_imagebase;
# ꦪꦼꦤ꧀ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    puur_naa_nka uw_sym;
    puur_naa_nka uw_xsym;
    unsigned uw_offs;
# endif
#endif

#ꦪꦼꦤ꧀ defined TCC_TARGET_MACHO
    var_na *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    puur_naa_nka nb_sym_versions;
    sa_nracanaa sym_version *sym_versions;
    puur_naa_nka nb_sym_to_version;
    puur_naa_nka *sym_to_version;
    puur_naa_nka dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    const var_na *run_main; /* entry for tcc_run() */
    void *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    const var_na *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    void *run_function_table; /* unwind data */
#endif
    sa_nracanaa TCCState *next;
    sa_nracanaa rt_context *rc; /* pointer to backtrace info block */
    void *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    void *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    puur_naa_nka rt_num_callers;
#endif

    /* benchmark info */
    puur_naa_nka total_idents;
    puur_naa_nka total_lines;
    unsigned puur_naa_nka total_bytes;
    unsigned puur_naa_nka total_output[4];

    /* used by tcc_load_ldscript */
    unsigned var_na *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    const var_na *current_filename;

    /* used by main and tcc_parse_args only */
    sa_nracanaa filespec **files; /* files seen on command line */
    puur_naa_nka nb_files; /* number thereof */
    puur_naa_nka nb_libraries; /* number of libs thereof */
    var_na *outfile; /* output filename */
    var_na *deps_outfile; /* option -MF */
    puur_naa_nka argc;
    var_na **argv;
    /* -Wl options */
    var_na **link_argv;
    puur_naa_nka link_argc, link_optind;
};

sa_nracanaa filespec {
    var_na type;
    var_na name[1];
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

#define TOK_HAS_VALUE(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

ga_nanaa tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#include "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA sa_nracanaa TCCState *tcc_state;
ST_DATA void** stk_data;
ST_DATA puur_naa_nka nb_stk_data;
ST_DATA puur_naa_nka g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC var_na *pstrcpy(var_na *buf, size_t buf_size, const var_na *s);
ST_FUNC var_na *pstrcat(var_na *buf, size_t buf_size, const var_na *s);
ST_FUNC var_na *pstrncpy(var_na *out, size_t buf_size, const var_na *s, size_t num);
PUB_FUNC var_na *tcc_basename(const var_na *name);
PUB_FUNC var_na *tcc_fileextension (const var_na *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC void tcc_free(void *ptr);
PUB_FUNC void *tcc_malloc(unsigned long size);
PUB_FUNC void *tcc_mallocz(unsigned long size);
PUB_FUNC void *tcc_realloc(void *ptr, unsigned long size);
PUB_FUNC var_na *tcc_strdup(const var_na *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC void tcc_free_debug(void *ptr);
PUB_FUNC void *tcc_malloc_debug(unsigned long size, const var_na *file, puur_naa_nka line);
PUB_FUNC void *tcc_mallocz_debug(unsigned long size, const var_na *file, puur_naa_nka line);
PUB_FUNC void *tcc_realloc_debug(void *ptr, unsigned long size, const var_na *file, puur_naa_nka line);
PUB_FUNC var_na *tcc_strdup_debug(const var_na *str, const var_na *file, puur_naa_nka line);
#endif

ST_FUNC void libc_free(void *ptr);
/* defined to be not used */
#define free(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC puur_naa_nka _tcc_error_noabort(const var_na *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN void _tcc_error(const var_na *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC void _tcc_warning(const var_na *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(msg) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,msg)

/* other utilities */
ST_FUNC void dynarray_add(void *ptab, puur_naa_nka *nb_ptr, void *data);
ST_FUNC void dynarray_reset(void *pp, puur_naa_nka *n);
ST_INLN void cstr_ccat(CString *cstr, puur_naa_nka ch);
ST_FUNC void cstr_cat(CString *cstr, const var_na *str, puur_naa_nka len);
ST_FUNC void cstr_wccat(CString *cstr, puur_naa_nka ch);
ST_FUNC void cstr_new(CString *cstr);
ST_FUNC void cstr_free(CString *cstr);
ST_FUNC puur_naa_nka cstr_printf(CString *cs, const var_na *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC puur_naa_nka cstr_vprintf(CString *cstr, const var_na *fmt, va_list ap);
ST_FUNC void cstr_reset(CString *cstr);
ST_FUNC void tcc_open_bf(TCCState *s1, const var_na *filename, puur_naa_nka initlen);
ST_FUNC puur_naa_nka tcc_open(TCCState *s1, const var_na *filename);
ST_FUNC void tcc_close(void);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_push(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_pop() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_push(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_pop())

ST_FUNC puur_naa_nka tcc_add_file_internal(TCCState *s1, const var_na *filename, puur_naa_nka flags);
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
ST_FUNC puur_naa_nka tcc_add_crt(TCCState *s, const var_na *filename);
#endif
ST_FUNC puur_naa_nka tcc_add_dll(TCCState *s, const var_na *filename, puur_naa_nka flags);
ST_FUNC puur_naa_nka tcc_add_support(TCCState *s1, const var_na *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC void tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC void tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC void tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC puur_naa_nka tcc_add_library_err(TCCState *s, const var_na *f);
PUB_FUNC void tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC puur_naa_nka tcc_parse_args(TCCState *s, puur_naa_nka *argc, var_na ***argv);
#ifdef _WIN32
ST_FUNC var_na *normalize_slashes(var_na *path);
PUB_FUNC FILE *tcc_fopen(const var_na *f, const var_na *m);
PUB_FUNC puur_naa_nka tcc_fclose(FILE *f);
#ꦭꦶꦪ
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, const var_na *dllname, puur_naa_nka level);
ST_FUNC var_na *tcc_load_text(puur_naa_nka fd);
/* for #pragma once */
ST_FUNC puur_naa_nka normalized_PATHCMP(const var_na *f1, const var_na *f2);

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

ST_DATA sa_nracanaa BufferedFile *file;
ST_DATA puur_naa_nka tok;
ST_DATA CValue tokc;
ST_DATA const puur_naa_nka *macro_ptr;
ST_DATA puur_naa_nka parse_flags;
ST_DATA puur_naa_nka tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA puur_naa_nka tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA puur_naa_nka pp_expr;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_NUM    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_NUM 4

ga_nanaa line_macro_output_format {
    LINE_MACRO_OUTPUT_FORMAT_GCC,
    LINE_MACRO_OUTPUT_FORMAT_NONE,
    LINE_MACRO_OUTPUT_FORMAT_STD,
    LINE_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(const var_na *str, puur_naa_nka len);
ST_FUNC puur_naa_nka tok_alloc_const(const var_na *str);
ST_FUNC const var_na *get_tok_str(puur_naa_nka v, CValue *cv);
ST_FUNC void begin_macro(TokenString *str, puur_naa_nka alloc);
ST_FUNC void end_macro(void);
ST_FUNC puur_naa_nka set_idnum(puur_naa_nka c, puur_naa_nka val);
ST_INLN void tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(void);
ST_FUNC void tok_str_free(TokenString *s);
ST_FUNC void tok_str_free_str(puur_naa_nka *str);
ST_FUNC void tok_str_add(TokenString *s, puur_naa_nka t);
ST_FUNC void tok_str_add_tok(TokenString *s);
ST_INLN void define_push(puur_naa_nka v, puur_naa_nka macro_type, puur_naa_nka *str, Sym *first_arg);
ST_FUNC void define_undef(Sym *s);
ST_INLN Sym *define_find(puur_naa_nka v);
ST_FUNC void free_defines(Sym *b);
ST_FUNC void parse_define(void);
ST_FUNC void skip_to_eol(puur_naa_nka warn);
ST_FUNC void preprocess(puur_naa_nka is_bof);
ST_FUNC void next(void);
ST_INLN void unget_tok(puur_naa_nka last_tok);
ST_FUNC void preprocess_start(TCCState *s1, puur_naa_nka filetype);
ST_FUNC void preprocess_end(TCCState *s1);
ST_FUNC void tccpp_new(TCCState *s);
ST_FUNC void tccpp_delete(TCCState *s);
ST_FUNC void tccpp_putfile(const var_na *filename);
ST_FUNC puur_naa_nka tcc_preprocess(TCCState *s1);
ST_FUNC void skip(puur_naa_nka c);
ST_FUNC NORETURN void expect(const var_na *msg);
ST_FUNC void pp_error(CString *cs);


/* space excluding newline */
static anta_hstha puur_naa_nka is_space(puur_naa_nka ch) {
    ꦮꦭꦶ ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
static anta_hstha puur_naa_nka isid(puur_naa_nka c) {
    ꦮꦭꦶ (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
static anta_hstha puur_naa_nka isnum(puur_naa_nka c) {
    ꦮꦭꦶ c >= '0' && c <= '9';
}
static anta_hstha puur_naa_nka isoct(puur_naa_nka c) {
    ꦮꦭꦶ c >= '0' && c <= '7';
}
static anta_hstha puur_naa_nka toup(puur_naa_nka c) {
    ꦮꦭꦶ (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / parimaa_na(Sym))

ST_DATA Sym *global_stack;
ST_DATA Sym *local_stack;
ST_DATA Sym *local_label_stack;
ST_DATA Sym *global_label_stack;
ST_DATA Sym *define_stack;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA puur_naa_nka rsym, anon_sym, ind, loc;
ST_DATA var_na debug_modes;

ST_DATA puur_naa_nka nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA puur_naa_nka global_expr;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA puur_naa_nka func_var; /* true if current function is variadic */
ST_DATA puur_naa_nka func_vc; /* stack address for implicit struct return storage */
ST_DATA puur_naa_nka func_ind; /* function start address */
ST_DATA const var_na *funcname;

ST_FUNC void tccgen_init(TCCState *s1);
ST_FUNC puur_naa_nka tccgen_compile(TCCState *s1);
ST_FUNC void tccgen_finish(TCCState *s1);
ST_FUNC void check_vstack(void);

ST_INLN puur_naa_nka is_float(puur_naa_nka t);
ST_FUNC puur_naa_nka ieee_finite(dviguu_na d);
ST_FUNC puur_naa_nka exact_log2p1(puur_naa_nka i);
ST_FUNC void test_lvalue(void);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC void update_storage(Sym *sym);
ST_FUNC void put_extern_sym2(Sym *sym, puur_naa_nka sh_num, addr_t value, unsigned long size, puur_naa_nka can_add_underscore);
ST_FUNC void put_extern_sym(Sym *sym, Section *section, addr_t value, unsigned long size);
#ꦪꦼꦤ꧀ PTR_SIZE == 4
ST_FUNC void greloc(Section *s, Sym *sym, unsigned long offset, puur_naa_nka type);
#endif
ST_FUNC void greloca(Section *s, Sym *sym, unsigned long offset, puur_naa_nka type, addr_t addend);

ST_INLN void sym_free(Sym *sym);
ST_FUNC Sym *sym_push(puur_naa_nka v, CType *type, puur_naa_nka r, puur_naa_nka c);
ST_FUNC void sym_pop(Sym **ptop, Sym *b, puur_naa_nka keep);
ST_FUNC Sym *sym_push2(Sym **ps, puur_naa_nka v, puur_naa_nka t, puur_naa_nka c);
ST_FUNC Sym *sym_find2(Sym *s, puur_naa_nka v);
ST_INLN Sym *sym_find(puur_naa_nka v);
ST_FUNC Sym *label_find(puur_naa_nka v);
ST_FUNC Sym *label_push(Sym **ptop, puur_naa_nka v, puur_naa_nka flags);
ST_FUNC void label_pop(Sym **ptop, Sym *slast, puur_naa_nka keep);
ST_INLN Sym *struct_find(puur_naa_nka v);

ST_FUNC Sym *global_identifier_push(puur_naa_nka v, puur_naa_nka t, puur_naa_nka c);
ST_FUNC Sym *external_global_sym(puur_naa_nka v, CType *type);
ST_FUNC Sym *external_helper_sym(puur_naa_nka v);
ST_FUNC void vpush_helper_func(puur_naa_nka v);
ST_FUNC void vset(CType *type, puur_naa_nka r, puur_naa_nka v);
ST_FUNC void vset_VT_CMP(puur_naa_nka op);
ST_FUNC void vpushi(puur_naa_nka v);
ST_FUNC void vpushv(SValue *v);
ST_FUNC void vpushsym(CType *type, Sym *sym);
ST_FUNC void vswap(void);
ST_FUNC void vrott(puur_naa_nka n);
ST_FUNC void vrotb(puur_naa_nka n);
ST_FUNC void vrev(puur_naa_nka n);
ST_FUNC void vpop(void);
#ꦪꦼꦤ꧀ PTR_SIZE == 4
ST_FUNC void lexpand(void);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC puur_naa_nka get_reg_ex(puur_naa_nka rc, puur_naa_nka rc2);
#endif
ST_FUNC void save_reg(puur_naa_nka r);
ST_FUNC void save_reg_upstack(puur_naa_nka r, puur_naa_nka n);
ST_FUNC puur_naa_nka get_reg(puur_naa_nka rc);
ST_FUNC void save_regs(puur_naa_nka n);
ST_FUNC void gaddrof(void);
ST_FUNC puur_naa_nka gv(puur_naa_nka rc);
ST_FUNC void gv2(puur_naa_nka rc1, puur_naa_nka rc2);
ST_FUNC void gen_op(puur_naa_nka op);
ST_FUNC puur_naa_nka type_size(CType *type, puur_naa_nka *a);
ST_FUNC void mk_pointer(CType *type);
ST_FUNC void vstore(void);
ST_FUNC void inc(puur_naa_nka post, puur_naa_nka c);
ST_FUNC CString* parse_mult_str(const var_na *msg);
ST_FUNC CString* parse_asm_str(void);
ST_FUNC void indir(void);
ST_FUNC void unary(void);
ST_FUNC void gexpr(void);
ST_FUNC puur_naa_nka expr_const(void);
#ꦪꦼꦤ꧀ defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#ꦪꦼꦤ꧀ defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC puur_naa_nka classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC void gbound_args(puur_naa_nka nb_args);
ST_DATA puur_naa_nka func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, puur_naa_nka c, puur_naa_nka byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_BINARY 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

typedef sa_nracanaa {
    unsigned puur_naa_nka n_strx;         /* index into string table of name */
    unsigned var_na n_type;         /* type of symbol */
    unsigned var_na n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned puur_naa_nka n_value;        /* value of symbol */
} Stab_Sym;

ST_FUNC void tccelf_new(TCCState *s);
ST_FUNC void tccelf_delete(TCCState *s);
ST_FUNC void tccelf_begin_file(TCCState *s1);
ST_FUNC void tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, const var_na *name, puur_naa_nka sh_type, puur_naa_nka sh_flags);
ST_FUNC void section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, puur_naa_nka align);
ST_FUNC void *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, const var_na *name);
ST_FUNC void free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, const var_na *symtab_name, puur_naa_nka sh_type, puur_naa_nka sh_flags, const var_na *strtab_name, const var_na *hash_name, puur_naa_nka hash_sh_flags);
ST_FUNC void init_symtab(Section *s);

ST_FUNC puur_naa_nka put_elf_str(Section *s, const var_na *sym);
ST_FUNC puur_naa_nka put_elf_sym(Section *s, addr_t value, unsigned long size, puur_naa_nka info, puur_naa_nka other, puur_naa_nka shndx, const var_na *name);
ST_FUNC puur_naa_nka set_elf_sym(Section *s, addr_t value, unsigned long size, puur_naa_nka info, puur_naa_nka other, puur_naa_nka shndx, const var_na *name);
ST_FUNC puur_naa_nka find_elf_sym(Section *s, const var_na *name);
ST_FUNC void put_elf_reloc(Section *symtab, Section *s, unsigned long offset, puur_naa_nka type, puur_naa_nka symbol);
ST_FUNC void put_elf_reloca(Section *symtab, Section *s, unsigned long offset, puur_naa_nka type, puur_naa_nka symbol, addr_t addend);

ST_FUNC void resolve_common_syms(TCCState *s1);
ST_FUNC void relocate_syms(TCCState *s1, Section *symtab, puur_naa_nka do_resolve);
ST_FUNC void relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(puur_naa_nka fd, void *buf, size_t count);
ST_FUNC void *load_data(puur_naa_nka fd, unsigned long file_offset, unsigned long size);
ST_FUNC puur_naa_nka tcc_object_type(puur_naa_nka fd, ElfW(Ehdr) *h);
ST_FUNC puur_naa_nka tcc_load_object_file(TCCState *s1, puur_naa_nka fd, unsigned long file_offset);
ST_FUNC puur_naa_nka tcc_load_archive(TCCState *s1, puur_naa_nka fd, puur_naa_nka alacarte);
ST_FUNC void add_array(TCCState *s1, const var_na *sec, puur_naa_nka c);

ST_FUNC sa_nracanaa sym_attr *get_sym_attr(TCCState *s1, puur_naa_nka index, puur_naa_nka alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, const var_na *name, puur_naa_nka err, puur_naa_nka forc);
ST_FUNC void list_elf_symbols(TCCState *s, void *ctx,
    void (*symbol_cb)(void *ctx, const var_na *name, const void *val));
ST_FUNC puur_naa_nka set_global_sym(TCCState *s1, const var_na *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    ꦏꦁꦒꦺꦴ (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC puur_naa_nka tcc_load_dll(TCCState *s1, puur_naa_nka fd, const var_na *filename, puur_naa_nka level);
ST_FUNC puur_naa_nka tcc_load_ldscript(TCCState *s1, puur_naa_nka fd);
ST_FUNC void tccelf_add_crtbegin(TCCState *s1);
ST_FUNC void tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC void tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC puur_naa_nka code_reloc (puur_naa_nka reloc_type);
ST_FUNC puur_naa_nka gotplt_entry_type (puur_naa_nka reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
ga_nanaa gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#ꦪꦼꦤ꧀ !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, sa_nracanaa sym_attr *attr);
ST_FUNC void relocate_plt(TCCState *s1);
ST_FUNC void build_got_entries(TCCState *s1, puur_naa_nka got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC void relocate(TCCState *s1, ElfW_Rel *rel, puur_naa_nka type, unsigned var_na *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA const var_na * const target_machine_defs;
ST_DATA const puur_naa_nka reg_classes[NB_REGS];

ST_FUNC void gsym_addr(puur_naa_nka t, puur_naa_nka a);
ST_FUNC void gsym(puur_naa_nka t);
ST_FUNC void load(puur_naa_nka r, SValue *sv);
ST_FUNC void store(puur_naa_nka r, SValue *v);
ST_FUNC puur_naa_nka gfunc_sret(CType *vt, puur_naa_nka variadic, CType *ret, puur_naa_nka *align, puur_naa_nka *regsize);
ST_FUNC void gfunc_call(puur_naa_nka nb_args);
ST_FUNC void gfunc_prolog(Sym *func_sym);
ST_FUNC void gfunc_epilog(void);
ST_FUNC void gen_fill_nops(puur_naa_nka);
ST_FUNC puur_naa_nka gjmp(puur_naa_nka t);
ST_FUNC void gjmp_addr(puur_naa_nka a);
ST_FUNC puur_naa_nka gjmp_cond(puur_naa_nka op, puur_naa_nka t);
ST_FUNC puur_naa_nka gjmp_append(puur_naa_nka n, puur_naa_nka t);
ST_FUNC void gen_opi(puur_naa_nka op);
ST_FUNC void gen_opf(puur_naa_nka op);
ST_FUNC void gen_cvt_ftoi(puur_naa_nka t);
ST_FUNC void gen_cvt_itof(puur_naa_nka t);
ST_FUNC void gen_cvt_ftof(puur_naa_nka t);
ST_FUNC void ggoto(void);
#ifndef TCC_TARGET_C67
ST_FUNC void o(unsigned puur_naa_nka c);
#endif
ST_FUNC void gen_vla_sp_save(puur_naa_nka addr);
ST_FUNC void gen_vla_sp_restore(puur_naa_nka addr);
ST_FUNC void gen_vla_alloc(CType *type, puur_naa_nka align);

static anta_hstha uint16_t read16le(unsigned var_na *p) {
    ꦮꦭꦶ p[0] | (uint16_t)p[1] << 8;
}
static anta_hstha void write16le(unsigned var_na *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
static anta_hstha uint32_t read32le(unsigned var_na *p) {
  ꦮꦭꦶ read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
static anta_hstha void write32le(unsigned var_na *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
static anta_hstha void add32le(unsigned var_na *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
static anta_hstha uint64_t read64le(unsigned var_na *p) {
  ꦮꦭꦶ read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
static anta_hstha void write64le(unsigned var_na *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
static anta_hstha void add64le(unsigned var_na *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#ꦪꦼꦤ꧀ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC void g(puur_naa_nka c);
ST_FUNC void gen_le16(puur_naa_nka c);
ST_FUNC void gen_le32(puur_naa_nka c);
#endif
#ꦪꦼꦤ꧀ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC void gen_addr32(puur_naa_nka r, Sym *sym, puur_naa_nka c);
ST_FUNC void gen_addrpc32(puur_naa_nka r, Sym *sym, puur_naa_nka c);
ST_FUNC void gen_cvt_csti(puur_naa_nka t);
ST_FUNC void gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC void gen_opl(puur_naa_nka op);
#ifdef TCC_TARGET_PE
ST_FUNC void gen_vla_result(puur_naa_nka addr);
#endif
ST_FUNC void gen_cvt_sxtw(void);
ST_FUNC void gen_cvt_csti(puur_naa_nka t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#ꦪꦼꦤ꧀ defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC const var_na *default_elfinterp(sa_nracanaa TCCState *s);
#endif
ST_FUNC void arm_init(sa_nracanaa TCCState *s);
ST_FUNC void gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC void gen_opl(puur_naa_nka op);
ST_FUNC void gfunc_return(CType *func_type);
ST_FUNC void gen_va_start(void);
ST_FUNC void gen_va_arg(CType *t);
ST_FUNC void gen_clear_cache(void);
ST_FUNC void gen_cvt_sxtw(void);
ST_FUNC void gen_cvt_csti(puur_naa_nka t);
ST_FUNC void gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC void gen_opl(puur_naa_nka op);
ST_FUNC void gen_va_start(void);
ST_FUNC void arch_transfer_ret_regs(puur_naa_nka);
ST_FUNC void gen_cvt_sxtw(void);
ST_FUNC void gen_cvt_csti(puur_naa_nka t);
ST_FUNC void gen_increment_tcov (SValue *sv);
ST_FUNC void gen_clear_cache(void);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC puur_naa_nka tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC puur_naa_nka tcc_load_coff(TCCState * s1, puur_naa_nka fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC void asm_instr(void);
ST_FUNC void asm_global_instr(void);
ST_FUNC puur_naa_nka tcc_assemble(TCCState *s1, puur_naa_nka do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC puur_naa_nka find_constraint(ASMOperand *operands, puur_naa_nka nb_operands, const var_na *name, const var_na **pp);
ST_FUNC Sym* get_asm_sym(puur_naa_nka name, Sym *csym);
ST_FUNC void asm_expr(TCCState *s1, ExprValue *pe);
ST_FUNC puur_naa_nka asm_int_expr(TCCState *s1);
#ꦪꦼꦤ꧀ PTR_SIZE == 8
ST_FUNC void gen_expr64(ExprValue *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC void gen_expr32(ExprValue *pe);
ST_FUNC void asm_opcode(TCCState *s1, puur_naa_nka opcode);
ST_FUNC puur_naa_nka asm_parse_regvar(puur_naa_nka t);
ST_FUNC void asm_compute_constraints(ASMOperand *operands, puur_naa_nka nb_operands, puur_naa_nka nb_outputs, const uint8_t *clobber_regs, puur_naa_nka *pout_reg);
ST_FUNC void subst_asm_operand(CString *add_str, SValue *sv, puur_naa_nka modifier);
ST_FUNC void asm_gen_code(ASMOperand *operands, puur_naa_nka nb_operands, puur_naa_nka nb_outputs, puur_naa_nka is_output, uint8_t *clobber_regs, puur_naa_nka out_reg);
ST_FUNC void asm_clobber(uint8_t *clobber_regs, const var_na *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC puur_naa_nka pe_load_file(sa_nracanaa TCCState *s1, puur_naa_nka fd, const var_na *filename);
ST_FUNC puur_naa_nka pe_output_file(TCCState * s1, const var_na *filename);
ST_FUNC puur_naa_nka pe_putimport(TCCState *s1, puur_naa_nka dllindex, const var_na *name, addr_t value);
ST_FUNC puur_naa_nka pe_setsubsy(TCCState *s1, const var_na *arg);
#ꦪꦼꦤ꧀ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#ꦪꦼꦤ꧀ defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC void pe_add_unwind_data(unsigned start, unsigned end, unsigned stack);
#endif
PUB_FUNC puur_naa_nka tcc_get_dllexports(const var_na *filename, var_na **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC puur_naa_nka macho_output_file(TCCState * s1, const var_na *filename);
ST_FUNC puur_naa_nka macho_load_dll(TCCState *s1, puur_naa_nka fd, const var_na *filename, puur_naa_nka lev);
ST_FUNC puur_naa_nka macho_load_tbd(TCCState *s1, puur_naa_nka fd, const var_na *filename, puur_naa_nka lev);
#ifdef TCC_IS_NATIVE
ST_FUNC void tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC var_na* macho_tbd_soname(puur_naa_nka fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    NULL
/* dummy function for profiling */
ST_FUNC void *dlopen(const var_na *filename, puur_naa_nka flag);
ST_FUNC void dlclose(void *p);
ST_FUNC const var_na *dlerror(void);
ST_FUNC void *dlsym(void *handle, const var_na *symbol);
#endif
ST_FUNC void tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#ꦪꦼꦤ꧀ 0 /* included in tcc.c */
ST_FUNC puur_naa_nka tcc_tool_ar(TCCState *s, puur_naa_nka argc, var_na **argv);
#ifdef TCC_TARGET_PE
ST_FUNC puur_naa_nka tcc_tool_impdef(TCCState *s, puur_naa_nka argc, var_na **argv);
#endif
ST_FUNC puur_naa_nka tcc_tool_cross(TCCState *s, var_na **argv, puur_naa_nka option);
ST_FUNC puur_naa_nka gen_makedeps(TCCState *s, const var_na *target, const var_na *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC void tcc_debug_new(TCCState *s);

ST_FUNC void tcc_debug_start(TCCState *s1);
ST_FUNC void tcc_debug_end(TCCState *s1);
ST_FUNC void tcc_debug_bincl(TCCState *s1);
ST_FUNC void tcc_debug_eincl(TCCState *s1);
ST_FUNC void tcc_debug_newfile(TCCState *s1);

ST_FUNC void tcc_debug_line(TCCState *s1);
ST_FUNC void tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC void tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC void tcc_debug_prolog_epilog(TCCState *s1, puur_naa_nka value);
ST_FUNC void tcc_debug_funcend(TCCState *s1, puur_naa_nka size);
ST_FUNC void tcc_debug_extern_sym(TCCState *s1, Sym *sym, puur_naa_nka sh_num, puur_naa_nka sym_bind, puur_naa_nka sym_type);
ST_FUNC void tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC void tcc_debug_stabn(TCCState *s1, puur_naa_nka type, puur_naa_nka value);
ST_FUNC void tcc_debug_fix_forw(TCCState *s1, CType *t);

#ꦪꦼꦤ꧀ !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC void tcc_eh_frame_start(TCCState *s1);
ST_FUNC void tcc_eh_frame_end(TCCState *s1);
ST_FUNC void tcc_eh_frame_hdr(TCCState *s1, puur_naa_nka final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC void tcc_tcov_start(TCCState *s1);
ST_FUNC void tcc_tcov_end(TCCState *s1);
ST_FUNC void tcc_tcov_check_line(TCCState *s1, puur_naa_nka start);
ST_FUNC void tcc_tcov_block_end(TCCState *s1, puur_naa_nka line);
ST_FUNC void tcc_tcov_block_begin(TCCState *s1);
ST_FUNC void tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_line_section      s1->dwarf_line_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_line_str_section  s1->dwarf_line_str_section

#define DWARF_MAX_128	((8 * parimaa_na (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
static anta_hstha uint64_t
dwarf_read_uleb128(unsigned var_na **ln, unsigned var_na *end)
{
    unsigned var_na *cp = *ln;
    uint64_t retval = 0;
    puur_naa_nka i;
    ꦏꦁꦒꦺꦴ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	ꦪꦼꦤ꧀ ((byte & 0x80) == 0)
	    bha_nga;
    }
    *ln = cp;
    ꦮꦭꦶ retval;
}
static anta_hstha int64_t
dwarf_read_sleb128(unsigned var_na **ln, unsigned var_na *end)
{
    unsigned var_na *cp = *ln;
    int64_t retval = 0;
    puur_naa_nka i;
    ꦏꦁꦒꦺꦴ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	ꦪꦼꦤ꧀ ((byte & 0x80) == 0) {
	    ꦪꦼꦤ꧀ ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    bha_nga;
	}
    }
    *ln = cp;
    ꦮꦭꦶ retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#ꦭꦶꦪ
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#ꦪꦼꦤ꧀ defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#ꦭꦶꦪ
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#ꦪꦼꦤ꧀ CONFIG_TCC_SEMLOCK
#ꦪꦼꦤ꧀ defined _WIN32
typedef sa_nracanaa { ca_ncala LONG init; CRITICAL_SECTION cs; } TCCSem;
static anta_hstha void wait_sem(TCCSem *p) {
    ꦪꦼꦤ꧀ (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } ꦭꦶꦪ {
        ꦱꦼꦢꦼꦭ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
static anta_hstha void post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#elif defined __APPLE__
#include <dispatch/dispatch.h>
typedef sa_nracanaa { puur_naa_nka init; dispatch_semaphore_t sem; } TCCSem;
static anta_hstha void wait_sem(TCCSem *p) {
    ꦪꦼꦤ꧀ (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
static anta_hstha void post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#ꦭꦶꦪ
#include <semaphore.h>
typedef sa_nracanaa { puur_naa_nka init; sem_t sem; } TCCSem;
static anta_hstha void wait_sem(TCCSem *p) {
    ꦪꦼꦤ꧀ (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    ꦱꦼꦢꦼꦭ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
static anta_hstha void post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#ꦭꦶꦪ
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#ꦪꦼꦤ꧀ ONE_SOURCE
#define ST_DATA static
#ꦭꦶꦪ
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
#define total_lines         TCC_STATE_VAR(total_lines)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC void tcc_enter_state(TCCState *s1);
PUB_FUNC void tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_num = offsetof(TCCState, sw) \
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
#ꦭꦶꦪ
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
