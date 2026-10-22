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
#અન્તર્ભાવ "config.h"

#અન્તર્ભાવ <stdarg.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <errno.h>
#અન્તર્ભાવ <math.h>
#અન્તર્ભાવ <fcntl.h>
#અન્તર્ભાવ <setjmp.h>
#અન્તર્ભાવ <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
બાહ્ય દશાંશ strtof (અચલ અક્ષર *__nptr, અક્ષર **__endptr);
બાહ્ય long દ્વિગુણ strtold (અચલ અક્ષર *__nptr, અક્ષર **__endptr);
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
# define અંતઃરેખ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long દ્વિગુણ)strtod
#  define strtof (દશાંશ)strtod
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
# જો defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_દ્વિઅંકી_2
# define O_દ્વિઅંકી_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#નહીંતર
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (કદ(tab) / કદ((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#નહીંતર
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#નહીંતર
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
#જો !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# જો defined __x86_64__
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
# નહીંતર
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
#જો defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# જો defined __i386__ && defined TCC_TARGET_I386
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

#જો defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#નહીંતર
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#જો defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#નહીંતર
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#જો defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#નહીંતર
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#જો defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#અથવાજો !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#જો defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#નહીંતર
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#જો defined TCC_TARGET_PE \
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

#જો !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#નહીંતર
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
# જો defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# નહીંતર
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# જો defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# નહીંતર
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# જો defined __GNU__
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
# નહીંતર
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

#અન્તર્ભાવ "libtcc.h"
#અન્તર્ભાવ "elf.h"
#અન્તર્ભાવ "stab.h"
#અન્તર્ભાવ "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#જો ONE_SOURCE
#define ST_INLN સ્થિર અંતઃરેખ
#define ST_FUNC સ્થિર
#define ST_DATA સ્થિર
#નહીંતર
#define ST_INLN
#define ST_FUNC
#define ST_DATA બાહ્ય
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define સ્થિર
# define અંતઃરેખ
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#અથવાજો defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#અથવાજો defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#અથવાજો defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#અથવાજો defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#અથવાજો defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#નહીંતર
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#જો PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#નહીંતર
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

#જો PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#નહીંતર
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_ઢગલો_SIZE  32
#define IFDEF_ઢગલો_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_ઢગલો_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
પ્રકારવ્યાખ્યા સંરચના TokenSym {
    સંરચના TokenSym *hash_next;
    સંરચના Sym *sym_define; /* direct pointer to define */
    સંરચના Sym *sym_label; /* direct pointer to label */
    સંરચના Sym *sym_struct; /* direct pointer to structure */
    સંરચના Sym *sym_identifier; /* direct pointer to identifier */
    પૂર્ણાંક tok; /* token number */
    પૂર્ણાંક len;
    અક્ષર str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
પ્રકારવ્યાખ્યા unsigned short nwchar_t;
#નહીંતર
પ્રકારવ્યાખ્યા પૂર્ણાંક nwchar_t;
#endif

પ્રકારવ્યાખ્યા સંરચના CString {
    પૂર્ણાંક size; /* size in bytes */
    પૂર્ણાંક size_allocated;
    અક્ષર *data; /* nwchar_t* in cases */
} CString;

/* type definition */
પ્રકારવ્યાખ્યા સંરચના CType {
    પૂર્ણાંક t;
    સંરચના Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_શબ્દો ((કદ(long દ્વિગુણ)+3)/4)

/* constant value */
પ્રકારવ્યાખ્યા સંઘ CValue {
    long દ્વિગુણ ld;
    દ્વિગુણ d;
    દશાંશ f;
    uint64_t i;
    સંરચના {
        અક્ષર *data;
        પૂર્ણાંક size;
    } str;
    પૂર્ણાંક tab[LDOUBLE_શબ્દો];
} CValue;

/* value on stack */
પ્રકારવ્યાખ્યા સંરચના SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    સંઘ {
      સંરચના { પૂર્ણાંક jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    સંઘ {
      સંરચના { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      સંરચના Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
સંરચના SymAttr {
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
સંરચના FuncAttr {
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
પ્રકારવ્યાખ્યા સંરચના Sym {
    પૂર્ણાંક v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    સંરચના SymAttr a; /* symbol attributes */
    સંઘ {
        સંરચના {
            પૂર્ણાંક c; /* associated number or Elf symbol index */
            સંઘ {
                પૂર્ણાંક sym_scope; /* scope level for locals */
                પૂર્ણાંક jnext; /* next jump label */
                પૂર્ણાંક jind; /* label position */
                સંરચના FuncAttr f; /* function attributes */
                પૂર્ણાંક auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        પૂર્ણાંક *d; /* define token stream */
        સંરચના Sym *cleanup_func;
    };

    CType type; /* associated type */
    સંઘ {
        સંરચના Sym *next; /* next related symbol (for fields and anoms) */
        પૂર્ણાંક *e; /* expanded token stream with preprocessor macros */
        પૂર્ણાંક asm_label; /* associated asm label */
        સંરચના Sym *cleanupstate; /* in defined labels */
        પૂર્ણાંક *vla_array_str; /* vla array code */
    };
    સંરચના Sym *prev; /* prev symbol in stack */
    સંઘ {
        સંરચના Sym *prev_tok; /* previous symbol for this token */
        સંરચના Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        સંરચના Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
પ્રકારવ્યાખ્યા સંરચના Section {
    unsigned long data_offset; /* current data offset */
    unsigned અક્ષર *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    પૂર્ણાંક sh_name;             /* elf section name (only used during output) */
    પૂર્ણાંક sh_અંક;              /* elf section number */
    પૂર્ણાંક sh_type;             /* elf section type */
    પૂર્ણાંક sh_flags;            /* elf section flags */
    પૂર્ણાંક sh_info;             /* elf section info */
    પૂર્ણાંક sh_addralign;        /* elf section alignment */
    પૂર્ણાંક sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    પૂર્ણાંક nb_hashed_syms;      /* used to resize the hash table */
    સંરચના Section *link;    /* link to another section */
    સંરચના Section *reloc;   /* corresponding section for relocation, if any */
    સંરચના Section *hash;    /* hash table for symbols */
    સંરચના Section *prev;    /* previous section on section stack */
    અક્ષર name[1];           /* section name */
} Section;

પ્રકારવ્યાખ્યા સંરચના DLLReference {
    પૂર્ણાંક level;
    શૂન્ય *handle;
    unsigned અક્ષર found, index;
    અક્ષર name[1];
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

પ્રકારવ્યાખ્યા સંરચના BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    પૂર્ણાંક fd;
    સંરચના BufferedFile *prev;
    પૂર્ણાંક લીટી_અંક;    /* current line number - here to simplify code */
    પૂર્ણાંક લીટી_ref;    /* tcc -E: last printed line */
    પૂર્ણાંક ifndef_macro;  /* #ifndef macro / #endif search */
    પૂર્ણાંક ifndef_macro_saved; /* saved ifndef_macro */
    પૂર્ણાંક *ifdef_ઢગલો_ptr; /* ifdef_stack value at the start of the file */
    પૂર્ણાંક include_next_index; /* next search path */
    પૂર્ણાંક prev_tok_flags; /* saved tok_flags */
    અક્ષર filename[1024];    /* filename */
    અક્ષર *true_filename; /* filename not modified by # line directive */
    unsigned અક્ષર unget[4];
    unsigned અક્ષર buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
પ્રકારવ્યાખ્યા સંરચના TokenString {
    પૂર્ણાંક *str;
    પૂર્ણાંક len;
    પૂર્ણાંક need_spc;
    પૂર્ણાંક allocated_len;
    પૂર્ણાંક last_લીટી_અંક;
    પૂર્ણાંક save_લીટી_અંક;
    /* used to chain token-strings with begin/end_macro() */
    સંરચના TokenString *prev;
    અચલ પૂર્ણાંક *prev_ptr;
    અક્ષર alloc;
} TokenString;

/* GNUC attribute definition */
પ્રકારવ્યાખ્યા સંરચના AttributeDef {
    સંરચના SymAttr a;
    સંરચના FuncAttr f;
    સંરચના Section *section;
    Sym *cleanup_func;
    પૂર્ણાંક alias_target; /* token */
    પૂર્ણાંક asm_label; /* associated asm label */
    અક્ષર attr_mode; /* __attribute__((__mode__(...))) */
    અક્ષર new_section; /* section is new */
} AttributeDef;

/* inline functions */
પ્રકારવ્યાખ્યા સંરચના InlineFunc {
    TokenString *func_str;
    Sym *sym;
    અક્ષર filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
પ્રકારવ્યાખ્યા સંરચના CachedInclude {
    પૂર્ણાંક ifndef_macro;
    પૂર્ણાંક once;
    પૂર્ણાંક hash_next; /* -1 if none */
    અક્ષર filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
પ્રકારવ્યાખ્યા સંરચના પદાવલિ_કિંમત {
    uint64_t v;
    Sym *sym;
    પૂર્ણાંક pcrel;
} પદાવલિ_કિંમત;

#define MAX_ASM_OPERANDS 30
પ્રકારવ્યાખ્યા સંરચના ASMOperand {
    પૂર્ણાંક id; /* GCC 3 optional identifier (0 if number only supported) */
    અક્ષર constraint[16];
    અક્ષર asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    પૂર્ણાંક ref_index; /* if >= 0, gives reference to a output constraint */
    પૂર્ણાંક આગત_index; /* if >= 0, gives reference to an input constraint */
    પૂર્ણાંક priority; /* priority, used to assign registers */
    પૂર્ણાંક reg; /* if >= 0, register number used for this operand */
    પૂર્ણાંક is_llong; /* true if double register value */
    પૂર્ણાંક is_memory; /* true if memory operand */
    પૂર્ણાંક is_rw;     /* for '+' modifier */
    પૂર્ણાંક is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
સંરચના sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    પૂર્ણાંક plt_sym;
    પૂર્ણાંક dyn_index;
    unsigned અક્ષર linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned અક્ષર plt_thumb_stub:1;
#endif
};

સંરચના TCCState {
    unsigned અક્ષર verbose; /* if true, display some information during compilation */
    unsigned અક્ષર nostdinc; /* if true, no standard headers are added */
    unsigned અક્ષર nostdlib; /* if true, no standard libraries are added */
    unsigned અક્ષર nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned અક્ષર nocommon; /* if true, do not use common symbols for .bss data */
    unsigned અક્ષર static_link; /* if true, static linking is performed */
    unsigned અક્ષર rdynamic; /* if true, all symbols are exported */
    unsigned અક્ષર symbolic; /* if true, resolve symbols in the current module first */
    unsigned અક્ષર znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned અક્ષર filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned અક્ષર optimize; /* only to #define __OPTIMIZE__ */
    unsigned અક્ષર option_pthread; /* -pthread option */
    unsigned અક્ષર enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned પૂર્ણાંક  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned અક્ષર char_is_unsigned;
    unsigned અક્ષર leading_underscore;
    unsigned અક્ષર ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned અક્ષર dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned અક્ષર ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned અક્ષર reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned અક્ષર gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned અક્ષર unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned અક્ષર warn_none;
    unsigned અક્ષર warn_all;
    unsigned અક્ષર warn_error;
    unsigned અક્ષર warn_write_strings;
    unsigned અક્ષર warn_unsupported;
    unsigned અક્ષર warn_implicit_function_declaration;
    unsigned અક્ષર warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned અક્ષર warn_અંક; /* temp var for tcc_warning_c() */

    unsigned અક્ષર option_r; /* option -r */
    unsigned અક્ષર do_bench; /* option -bench */
    unsigned અક્ષર just_deps; /* option -M  */
    unsigned અક્ષર gen_deps; /* option -MD  */
    unsigned અક્ષર include_sys_deps; /* option -MD  */
    unsigned અક્ષર gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned અક્ષર do_debug;
    unsigned અક્ષર dwarf;
    unsigned અક્ષર do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned અક્ષર do_bounds_check;
#endif
    unsigned અક્ષર test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned અક્ષર gnu_ext;
    /* use TinyCC extensions */
    unsigned અક્ષર tcc_ext;

    unsigned અક્ષર dflag; /* -dX value */
    unsigned અક્ષર Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned અક્ષર nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned અક્ષર float_abi; /* float ABI of the generated code*/
#endif

    unsigned અક્ષર has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    પૂર્ણાંક seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    અક્ષર *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    અક્ષર *soname; /* as specified on the command line (-soname) */
    અક્ષર *rpath; /* as specified on the command line (-Wl,-rpath=) */
    અક્ષર *elfint; /* -Wl,-I... on command line */
    અક્ષર *elf_entryname; /* "_start" unless set */
    અક્ષર *init_પ્રતીક; /* symbols to call at load-time (not used currently) */
    અક્ષર *fini_પ્રતીક; /* symbols to call at unload-time (not used currently) */
    અક્ષર *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    પૂર્ણાંક output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    પૂર્ણાંક output_format;
    /* nth test to run with -dt -run */
    પૂર્ણાંક run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    પૂર્ણાંક nb_loaded_dlls;

    /* include paths */
    અક્ષર **include_paths;
    પૂર્ણાંક nb_include_paths;

    અક્ષર **sysinclude_paths;
    પૂર્ણાંક nb_sysinclude_paths;

    /* library paths */
    અક્ષર **library_paths;
    પૂર્ણાંક nb_library_paths;

    /* crt?.o object path */
    અક્ષર **crt_paths;
    પૂર્ણાંક nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    શૂન્ય *error_opaque;
    શૂન્ય (*error_func)(શૂન્ય *opaque, અચલ અક્ષર *સંદેશ);
    પૂર્ણાંક error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    પૂર્ણાંક nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    અક્ષર **target_deps;
    પૂર્ણાંક nb_target_deps;

    /* compilation */
    BufferedFile *include_ઢગલો[INCLUDE_ઢગલો_SIZE];
    BufferedFile **include_ઢગલો_ptr;

    પૂર્ણાંક ifdef_ઢગલો[IFDEF_ઢગલો_SIZE];
    પૂર્ણાંક *ifdef_ઢગલો_ptr;

    /* included files enclosed with #ifndef MACRO */
    પૂર્ણાંક cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    પૂર્ણાંક nb_cached_includes;

    /* #pragma pack stack */
    પૂર્ણાંક pack_ઢગલો[PACK_ઢગલો_SIZE];
    પૂર્ણાંક *pack_ઢગલો_ptr;
    અક્ષર **pragma_libs;
    પૂર્ણાંક nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    સંરચના InlineFunc **inline_fns;
    પૂર્ણાંક nb_inline_fns;

    /* sections */
    Section **sections;
    પૂર્ણાંક nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    પૂર્ણાંક nb_priv_sections; /* number of private sections */

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
    સંઘ { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_લીટી_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_લીટી_str_section;
    પૂર્ણાંક dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    સંરચના _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    સંરચના sym_attr *sym_attrs;
    પૂર્ણાંક nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    સંરચના pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    પૂર્ણાંક nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    પૂર્ણાંક pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_ઢગલો_size;
    addr_t pe_imagebase;
# જો defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    પૂર્ણાંક uw_sym;
    પૂર્ણાંક uw_xsym;
    unsigned uw_offs;
# endif
#endif

#જો defined TCC_TARGET_MACHO
    અક્ષર *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    પૂર્ણાંક nb_sym_versions;
    સંરચના sym_version *sym_versions;
    પૂર્ણાંક nb_sym_to_version;
    પૂર્ણાંક *sym_to_version;
    પૂર્ણાંક dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    અચલ અક્ષર *run_main; /* entry for tcc_run() */
    શૂન્ય *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    અચલ અક્ષર *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    શૂન્ય *run_function_table; /* unwind data */
#endif
    સંરચના TCCState *next;
    સંરચના rt_context *rc; /* pointer to backtrace info block */
    શૂન્ય *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    શૂન્ય *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    પૂર્ણાંક rt_અંક_callers;
#endif

    /* benchmark info */
    પૂર્ણાંક total_idents;
    પૂર્ણાંક total_લીટીઓ;
    unsigned પૂર્ણાંક total_bytes;
    unsigned પૂર્ણાંક total_output[4];

    /* used by tcc_load_ldscript */
    unsigned અક્ષર *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    અચલ અક્ષર *current_filename;

    /* used by main and tcc_parse_args only */
    સંરચના filespec **files; /* files seen on command line */
    પૂર્ણાંક nb_files; /* number thereof */
    પૂર્ણાંક nb_libraries; /* number of libs thereof */
    અક્ષર *outfile; /* output filename */
    અક્ષર *deps_outfile; /* option -MF */
    પૂર્ણાંક argc;
    અક્ષર **argv;
    /* -Wl options */
    અક્ષર **link_argv;
    પૂર્ણાંક link_argc, link_optind;
};

સંરચના filespec {
    અક્ષર type;
    અક્ષર name[1];
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

#define TOK_HAS_કિંમત(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

ગણના tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#અન્તર્ભાવ "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA સંરચના TCCState *tcc_state;
ST_DATA શૂન્ય** stk_data;
ST_DATA પૂર્ણાંક nb_stk_data;
ST_DATA પૂર્ણાંક g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC અક્ષર *pstrcpy(અક્ષર *buf, size_t buf_size, અચલ અક્ષર *s);
ST_FUNC અક્ષર *pstrcat(અક્ષર *buf, size_t buf_size, અચલ અક્ષર *s);
ST_FUNC અક્ષર *pstrncpy(અક્ષર *out, size_t buf_size, અચલ અક્ષર *s, size_t અંક);
PUB_FUNC અક્ષર *tcc_basename(અચલ અક્ષર *name);
PUB_FUNC અક્ષર *tcc_fileextension (અચલ અક્ષર *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC શૂન્ય tcc_free(શૂન્ય *ptr);
PUB_FUNC શૂન્ય *tcc_malloc(unsigned long size);
PUB_FUNC શૂન્ય *tcc_mallocz(unsigned long size);
PUB_FUNC શૂન્ય *tcc_realloc(શૂન્ય *ptr, unsigned long size);
PUB_FUNC અક્ષર *tcc_strdup(અચલ અક્ષર *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC શૂન્ય tcc_free_debug(શૂન્ય *ptr);
PUB_FUNC શૂન્ય *tcc_malloc_debug(unsigned long size, અચલ અક્ષર *file, પૂર્ણાંક લીટી);
PUB_FUNC શૂન્ય *tcc_mallocz_debug(unsigned long size, અચલ અક્ષર *file, પૂર્ણાંક લીટી);
PUB_FUNC શૂન્ય *tcc_realloc_debug(શૂન્ય *ptr, unsigned long size, અચલ અક્ષર *file, પૂર્ણાંક લીટી);
PUB_FUNC અક્ષર *tcc_strdup_debug(અચલ અક્ષર *str, અચલ અક્ષર *file, પૂર્ણાંક લીટી);
#endif

ST_FUNC શૂન્ય libc_free(શૂન્ય *ptr);
/* defined to be not used */
#define મુક્ત(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC પૂર્ણાંક _tcc_error_noabort(અચલ અક્ષર *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN શૂન્ય _tcc_error(અચલ અક્ષર *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC શૂન્ય _tcc_warning(અચલ અક્ષર *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(સંદેશ) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,સંદેશ)

/* other utilities */
ST_FUNC શૂન્ય dynarray_add(શૂન્ય *ptab, પૂર્ણાંક *nb_ptr, શૂન્ય *data);
ST_FUNC શૂન્ય dynarray_reset(શૂન્ય *pp, પૂર્ણાંક *n);
ST_INLN શૂન્ય cstr_ccat(CString *cstr, પૂર્ણાંક ch);
ST_FUNC શૂન્ય cstr_cat(CString *cstr, અચલ અક્ષર *str, પૂર્ણાંક len);
ST_FUNC શૂન્ય cstr_wccat(CString *cstr, પૂર્ણાંક ch);
ST_FUNC શૂન્ય cstr_new(CString *cstr);
ST_FUNC શૂન્ય cstr_free(CString *cstr);
ST_FUNC પૂર્ણાંક cstr_printf(CString *cs, અચલ અક્ષર *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC પૂર્ણાંક cstr_vprintf(CString *cstr, અચલ અક્ષર *fmt, va_list ap);
ST_FUNC શૂન્ય cstr_reset(CString *cstr);
ST_FUNC શૂન્ય tcc_open_bf(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક initlen);
ST_FUNC પૂર્ણાંક tcc_open(TCCState *s1, અચલ અક્ષર *filename);
ST_FUNC શૂન્ય tcc_close(શૂન્ય);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_ધકેલો(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_કાઢો() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_ધકેલો(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_કાઢો())

ST_FUNC પૂર્ણાંક tcc_add_file_internal(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક flags);
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
ST_FUNC પૂર્ણાંક tcc_add_crt(TCCState *s, અચલ અક્ષર *filename);
#endif
ST_FUNC પૂર્ણાંક tcc_add_dll(TCCState *s, અચલ અક્ષર *filename, પૂર્ણાંક flags);
ST_FUNC પૂર્ણાંક tcc_add_support(TCCState *s1, અચલ અક્ષર *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC શૂન્ય tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC શૂન્ય tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC શૂન્ય tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC પૂર્ણાંક tcc_add_library_err(TCCState *s, અચલ અક્ષર *f);
PUB_FUNC શૂન્ય tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC પૂર્ણાંક tcc_parse_args(TCCState *s, પૂર્ણાંક *argc, અક્ષર ***argv);
#ifdef _WIN32
ST_FUNC અક્ષર *normalize_slashes(અક્ષર *path);
PUB_FUNC FILE *tcc_fopen(અચલ અક્ષર *f, અચલ અક્ષર *m);
PUB_FUNC પૂર્ણાંક tcc_fclose(FILE *f);
#નહીંતર
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, અચલ અક્ષર *dllname, પૂર્ણાંક level);
ST_FUNC અક્ષર *tcc_load_text(પૂર્ણાંક fd);
/* for #pragma once */
ST_FUNC પૂર્ણાંક normalized_PATHCMP(અચલ અક્ષર *f1, અચલ અક્ષર *f2);

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

ST_DATA સંરચના BufferedFile *file;
ST_DATA પૂર્ણાંક tok;
ST_DATA CValue tokc;
ST_DATA અચલ પૂર્ણાંક *macro_ptr;
ST_DATA પૂર્ણાંક parse_flags;
ST_DATA પૂર્ણાંક tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA પૂર્ણાંક tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA પૂર્ણાંક pp_પદાવલિ;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_અંક    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_અંક 4

ગણના લીટી_macro_output_format {
    લીટી_MACRO_OUTPUT_FORMAT_GCC,
    લીટી_MACRO_OUTPUT_FORMAT_NONE,
    લીટી_MACRO_OUTPUT_FORMAT_STD,
    લીટી_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(અચલ અક્ષર *str, પૂર્ણાંક len);
ST_FUNC પૂર્ણાંક tok_alloc_const(અચલ અક્ષર *str);
ST_FUNC અચલ અક્ષર *get_tok_str(પૂર્ણાંક v, CValue *cv);
ST_FUNC શૂન્ય begin_macro(TokenString *str, પૂર્ણાંક alloc);
ST_FUNC શૂન્ય end_macro(શૂન્ય);
ST_FUNC પૂર્ણાંક set_idnum(પૂર્ણાંક c, પૂર્ણાંક val);
ST_INLN શૂન્ય tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(શૂન્ય);
ST_FUNC શૂન્ય tok_str_free(TokenString *s);
ST_FUNC શૂન્ય tok_str_free_str(પૂર્ણાંક *str);
ST_FUNC શૂન્ય tok_str_add(TokenString *s, પૂર્ણાંક t);
ST_FUNC શૂન્ય tok_str_add_tok(TokenString *s);
ST_INLN શૂન્ય define_ધકેલો(પૂર્ણાંક v, પૂર્ણાંક macro_type, પૂર્ણાંક *str, Sym *first_arg);
ST_FUNC શૂન્ય define_undef(Sym *s);
ST_INLN Sym *define_find(પૂર્ણાંક v);
ST_FUNC શૂન્ય free_defines(Sym *b);
ST_FUNC શૂન્ય parse_define(શૂન્ય);
ST_FUNC શૂન્ય skip_to_eol(પૂર્ણાંક warn);
ST_FUNC શૂન્ય preprocess(પૂર્ણાંક is_bof);
ST_FUNC શૂન્ય next(શૂન્ય);
ST_INLN શૂન્ય unget_tok(પૂર્ણાંક last_tok);
ST_FUNC શૂન્ય preprocess_start(TCCState *s1, પૂર્ણાંક filetype);
ST_FUNC શૂન્ય preprocess_end(TCCState *s1);
ST_FUNC શૂન્ય tccpp_new(TCCState *s);
ST_FUNC શૂન્ય tccpp_delete(TCCState *s);
ST_FUNC શૂન્ય tccpp_putfile(અચલ અક્ષર *filename);
ST_FUNC પૂર્ણાંક tcc_preprocess(TCCState *s1);
ST_FUNC શૂન્ય skip(પૂર્ણાંક c);
ST_FUNC NORETURN શૂન્ય expect(અચલ અક્ષર *સંદેશ);
ST_FUNC શૂન્ય pp_error(CString *cs);


/* space excluding newline */
સ્થિર અંતઃરેખ પૂર્ણાંક is_space(પૂર્ણાંક ch) {
    પાછા ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
સ્થિર અંતઃરેખ પૂર્ણાંક isid(પૂર્ણાંક c) {
    પાછા (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
સ્થિર અંતઃરેખ પૂર્ણાંક isnum(પૂર્ણાંક c) {
    પાછા c >= '0' && c <= '9';
}
સ્થિર અંતઃરેખ પૂર્ણાંક isoct(પૂર્ણાંક c) {
    પાછા c >= '0' && c <= '7';
}
સ્થિર અંતઃરેખ પૂર્ણાંક toup(પૂર્ણાંક c) {
    પાછા (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / કદ(Sym))

ST_DATA Sym *global_ઢગલો;
ST_DATA Sym *local_ઢગલો;
ST_DATA Sym *local_label_ઢગલો;
ST_DATA Sym *global_label_ઢગલો;
ST_DATA Sym *define_ઢગલો;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA પૂર્ણાંક rsym, anon_sym, ind, loc;
ST_DATA અક્ષર debug_modes;

ST_DATA પૂર્ણાંક nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA પૂર્ણાંક global_પદાવલિ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA પૂર્ણાંક func_var; /* true if current function is variadic */
ST_DATA પૂર્ણાંક func_vc; /* stack address for implicit struct return storage */
ST_DATA પૂર્ણાંક func_ind; /* function start address */
ST_DATA અચલ અક્ષર *funcname;

ST_FUNC શૂન્ય tccgen_init(TCCState *s1);
ST_FUNC પૂર્ણાંક tccgen_compile(TCCState *s1);
ST_FUNC શૂન્ય tccgen_finish(TCCState *s1);
ST_FUNC શૂન્ય check_vstack(શૂન્ય);

ST_INLN પૂર્ણાંક is_float(પૂર્ણાંક t);
ST_FUNC પૂર્ણાંક ieee_finite(દ્વિગુણ d);
ST_FUNC પૂર્ણાંક exact_log2p1(પૂર્ણાંક i);
ST_FUNC શૂન્ય test_lvalue(શૂન્ય);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC શૂન્ય update_storage(Sym *sym);
ST_FUNC શૂન્ય put_extern_sym2(Sym *sym, પૂર્ણાંક sh_અંક, addr_t કિંમત, unsigned long size, પૂર્ણાંક can_add_underscore);
ST_FUNC શૂન્ય put_extern_sym(Sym *sym, Section *section, addr_t કિંમત, unsigned long size);
#જો PTR_SIZE == 4
ST_FUNC શૂન્ય greloc(Section *s, Sym *sym, unsigned long offset, પૂર્ણાંક type);
#endif
ST_FUNC શૂન્ય greloca(Section *s, Sym *sym, unsigned long offset, પૂર્ણાંક type, addr_t addend);

ST_INLN શૂન્ય sym_free(Sym *sym);
ST_FUNC Sym *sym_ધકેલો(પૂર્ણાંક v, CType *type, પૂર્ણાંક r, પૂર્ણાંક c);
ST_FUNC શૂન્ય sym_કાઢો(Sym **ptop, Sym *b, પૂર્ણાંક keep);
ST_FUNC Sym *sym_push2(Sym **ps, પૂર્ણાંક v, પૂર્ણાંક t, પૂર્ણાંક c);
ST_FUNC Sym *sym_find2(Sym *s, પૂર્ણાંક v);
ST_INLN Sym *sym_find(પૂર્ણાંક v);
ST_FUNC Sym *label_find(પૂર્ણાંક v);
ST_FUNC Sym *label_ધકેલો(Sym **ptop, પૂર્ણાંક v, પૂર્ણાંક flags);
ST_FUNC શૂન્ય label_કાઢો(Sym **ptop, Sym *slast, પૂર્ણાંક keep);
ST_INLN Sym *struct_find(પૂર્ણાંક v);

ST_FUNC Sym *global_identifier_ધકેલો(પૂર્ણાંક v, પૂર્ણાંક t, પૂર્ણાંક c);
ST_FUNC Sym *external_global_sym(પૂર્ણાંક v, CType *type);
ST_FUNC Sym *external_helper_sym(પૂર્ણાંક v);
ST_FUNC શૂન્ય vpush_helper_func(પૂર્ણાંક v);
ST_FUNC શૂન્ય vset(CType *type, પૂર્ણાંક r, પૂર્ણાંક v);
ST_FUNC શૂન્ય vset_VT_CMP(પૂર્ણાંક op);
ST_FUNC શૂન્ય vpushi(પૂર્ણાંક v);
ST_FUNC શૂન્ય vpushv(SValue *v);
ST_FUNC શૂન્ય vpushsym(CType *type, Sym *sym);
ST_FUNC શૂન્ય vswap(શૂન્ય);
ST_FUNC શૂન્ય vrott(પૂર્ણાંક n);
ST_FUNC શૂન્ય vrotb(પૂર્ણાંક n);
ST_FUNC શૂન્ય vrev(પૂર્ણાંક n);
ST_FUNC શૂન્ય vpop(શૂન્ય);
#જો PTR_SIZE == 4
ST_FUNC શૂન્ય lexpand(શૂન્ય);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC પૂર્ણાંક get_reg_ex(પૂર્ણાંક rc, પૂર્ણાંક rc2);
#endif
ST_FUNC શૂન્ય save_reg(પૂર્ણાંક r);
ST_FUNC શૂન્ય save_reg_upstack(પૂર્ણાંક r, પૂર્ણાંક n);
ST_FUNC પૂર્ણાંક get_reg(પૂર્ણાંક rc);
ST_FUNC શૂન્ય save_regs(પૂર્ણાંક n);
ST_FUNC શૂન્ય gaddrof(શૂન્ય);
ST_FUNC પૂર્ણાંક gv(પૂર્ણાંક rc);
ST_FUNC શૂન્ય gv2(પૂર્ણાંક rc1, પૂર્ણાંક rc2);
ST_FUNC શૂન્ય gen_op(પૂર્ણાંક op);
ST_FUNC પૂર્ણાંક type_size(CType *type, પૂર્ણાંક *a);
ST_FUNC શૂન્ય mk_pointer(CType *type);
ST_FUNC શૂન્ય vstore(શૂન્ય);
ST_FUNC શૂન્ય inc(પૂર્ણાંક post, પૂર્ણાંક c);
ST_FUNC CString* parse_mult_str(અચલ અક્ષર *સંદેશ);
ST_FUNC CString* parse_asm_str(શૂન્ય);
ST_FUNC શૂન્ય indir(શૂન્ય);
ST_FUNC શૂન્ય unary(શૂન્ય);
ST_FUNC શૂન્ય gexpr(શૂન્ય);
ST_FUNC પૂર્ણાંક પદાવલિ_const(શૂન્ય);
#જો defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#જો defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC પૂર્ણાંક classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC શૂન્ય gbound_args(પૂર્ણાંક nb_args);
ST_DATA પૂર્ણાંક func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, પૂર્ણાંક c, પૂર્ણાંક byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_દ્વિઅંકી 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

પ્રકારવ્યાખ્યા સંરચના {
    unsigned પૂર્ણાંક n_strx;         /* index into string table of name */
    unsigned અક્ષર n_type;         /* type of symbol */
    unsigned અક્ષર n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned પૂર્ણાંક n_કિંમત;        /* value of symbol */
} Stab_Sym;

ST_FUNC શૂન્ય tccelf_new(TCCState *s);
ST_FUNC શૂન્ય tccelf_delete(TCCState *s);
ST_FUNC શૂન્ય tccelf_begin_file(TCCState *s1);
ST_FUNC શૂન્ય tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, અચલ અક્ષર *name, પૂર્ણાંક sh_type, પૂર્ણાંક sh_flags);
ST_FUNC શૂન્ય section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, પૂર્ણાંક align);
ST_FUNC શૂન્ય *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, અચલ અક્ષર *name);
ST_FUNC શૂન્ય free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, અચલ અક્ષર *symtab_name, પૂર્ણાંક sh_type, પૂર્ણાંક sh_flags, અચલ અક્ષર *strtab_name, અચલ અક્ષર *hash_name, પૂર્ણાંક hash_sh_flags);
ST_FUNC શૂન્ય init_symtab(Section *s);

ST_FUNC પૂર્ણાંક put_elf_str(Section *s, અચલ અક્ષર *sym);
ST_FUNC પૂર્ણાંક put_elf_sym(Section *s, addr_t કિંમત, unsigned long size, પૂર્ણાંક info, પૂર્ણાંક other, પૂર્ણાંક shndx, અચલ અક્ષર *name);
ST_FUNC પૂર્ણાંક set_elf_sym(Section *s, addr_t કિંમત, unsigned long size, પૂર્ણાંક info, પૂર્ણાંક other, પૂર્ણાંક shndx, અચલ અક્ષર *name);
ST_FUNC પૂર્ણાંક find_elf_sym(Section *s, અચલ અક્ષર *name);
ST_FUNC શૂન્ય put_elf_reloc(Section *symtab, Section *s, unsigned long offset, પૂર્ણાંક type, પૂર્ણાંક પ્રતીક);
ST_FUNC શૂન્ય put_elf_reloca(Section *symtab, Section *s, unsigned long offset, પૂર્ણાંક type, પૂર્ણાંક પ્રતીક, addr_t addend);

ST_FUNC શૂન્ય resolve_common_syms(TCCState *s1);
ST_FUNC શૂન્ય relocate_syms(TCCState *s1, Section *symtab, પૂર્ણાંક do_resolve);
ST_FUNC શૂન્ય relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(પૂર્ણાંક fd, શૂન્ય *buf, size_t ગણતરી_2);
ST_FUNC શૂન્ય *load_data(પૂર્ણાંક fd, unsigned long file_offset, unsigned long size);
ST_FUNC પૂર્ણાંક tcc_object_type(પૂર્ણાંક fd, ElfW(Ehdr) *h);
ST_FUNC પૂર્ણાંક tcc_load_object_file(TCCState *s1, પૂર્ણાંક fd, unsigned long file_offset);
ST_FUNC પૂર્ણાંક tcc_load_archive(TCCState *s1, પૂર્ણાંક fd, પૂર્ણાંક alacarte);
ST_FUNC શૂન્ય add_array(TCCState *s1, અચલ અક્ષર *sec, પૂર્ણાંક c);

ST_FUNC સંરચના sym_attr *get_sym_attr(TCCState *s1, પૂર્ણાંક index, પૂર્ણાંક alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, અચલ અક્ષર *name, પૂર્ણાંક err, પૂર્ણાંક forc);
ST_FUNC શૂન્ય list_elf_symbols(TCCState *s, શૂન્ય *ctx,
    શૂન્ય (*પ્રતીક_cb)(શૂન્ય *ctx, અચલ અક્ષર *name, અચલ શૂન્ય *val));
ST_FUNC પૂર્ણાંક set_global_sym(TCCState *s1, અચલ અક્ષર *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    માટે (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC પૂર્ણાંક tcc_load_dll(TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename, પૂર્ણાંક level);
ST_FUNC પૂર્ણાંક tcc_load_ldscript(TCCState *s1, પૂર્ણાંક fd);
ST_FUNC શૂન્ય tccelf_add_crtbegin(TCCState *s1);
ST_FUNC શૂન્ય tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC શૂન્ય tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC પૂર્ણાંક code_reloc (પૂર્ણાંક reloc_type);
ST_FUNC પૂર્ણાંક gotplt_entry_type (પૂર્ણાંક reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
ગણના gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#જો !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, સંરચના sym_attr *attr);
ST_FUNC શૂન્ય relocate_plt(TCCState *s1);
ST_FUNC શૂન્ય build_got_entries(TCCState *s1, પૂર્ણાંક got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC શૂન્ય relocate(TCCState *s1, ElfW_Rel *rel, પૂર્ણાંક type, unsigned અક્ષર *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA અચલ અક્ષર * અચલ target_machine_defs;
ST_DATA અચલ પૂર્ણાંક reg_classes[NB_REGS];

ST_FUNC શૂન્ય gsym_addr(પૂર્ણાંક t, પૂર્ણાંક a);
ST_FUNC શૂન્ય gsym(પૂર્ણાંક t);
ST_FUNC શૂન્ય load(પૂર્ણાંક r, SValue *sv);
ST_FUNC શૂન્ય store(પૂર્ણાંક r, SValue *v);
ST_FUNC પૂર્ણાંક gfunc_sret(CType *vt, પૂર્ણાંક variadic, CType *ret, પૂર્ણાંક *align, પૂર્ણાંક *regsize);
ST_FUNC શૂન્ય gfunc_call(પૂર્ણાંક nb_args);
ST_FUNC શૂન્ય gfunc_prolog(Sym *func_sym);
ST_FUNC શૂન્ય gfunc_epilog(શૂન્ય);
ST_FUNC શૂન્ય gen_fill_nops(પૂર્ણાંક);
ST_FUNC પૂર્ણાંક gjmp(પૂર્ણાંક t);
ST_FUNC શૂન્ય gjmp_addr(પૂર્ણાંક a);
ST_FUNC પૂર્ણાંક gjmp_cond(પૂર્ણાંક op, પૂર્ણાંક t);
ST_FUNC પૂર્ણાંક gjmp_append(પૂર્ણાંક n, પૂર્ણાંક t);
ST_FUNC શૂન્ય gen_opi(પૂર્ણાંક op);
ST_FUNC શૂન્ય gen_opf(પૂર્ણાંક op);
ST_FUNC શૂન્ય gen_cvt_ftoi(પૂર્ણાંક t);
ST_FUNC શૂન્ય gen_cvt_itof(પૂર્ણાંક t);
ST_FUNC શૂન્ય gen_cvt_ftof(પૂર્ણાંક t);
ST_FUNC શૂન્ય ggoto(શૂન્ય);
#ifndef TCC_TARGET_C67
ST_FUNC શૂન્ય o(unsigned પૂર્ણાંક c);
#endif
ST_FUNC શૂન્ય gen_vla_sp_save(પૂર્ણાંક addr);
ST_FUNC શૂન્ય gen_vla_sp_restore(પૂર્ણાંક addr);
ST_FUNC શૂન્ય gen_vla_alloc(CType *type, પૂર્ણાંક align);

સ્થિર અંતઃરેખ uint16_t read16le(unsigned અક્ષર *p) {
    પાછા p[0] | (uint16_t)p[1] << 8;
}
સ્થિર અંતઃરેખ શૂન્ય write16le(unsigned અક્ષર *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
સ્થિર અંતઃરેખ uint32_t read32le(unsigned અક્ષર *p) {
  પાછા read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
સ્થિર અંતઃરેખ શૂન્ય write32le(unsigned અક્ષર *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
સ્થિર અંતઃરેખ શૂન્ય add32le(unsigned અક્ષર *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
સ્થિર અંતઃરેખ uint64_t read64le(unsigned અક્ષર *p) {
  પાછા read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
સ્થિર અંતઃરેખ શૂન્ય write64le(unsigned અક્ષર *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
સ્થિર અંતઃરેખ શૂન્ય add64le(unsigned અક્ષર *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#જો defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC શૂન્ય g(પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_le16(પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_le32(પૂર્ણાંક c);
#endif
#જો defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC શૂન્ય gen_addr32(પૂર્ણાંક r, Sym *sym, પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_addrpc32(પૂર્ણાંક r, Sym *sym, પૂર્ણાંક c);
ST_FUNC શૂન્ય gen_cvt_csti(પૂર્ણાંક t);
ST_FUNC શૂન્ય gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC શૂન્ય gen_opl(પૂર્ણાંક op);
#ifdef TCC_TARGET_PE
ST_FUNC શૂન્ય gen_vla_result(પૂર્ણાંક addr);
#endif
ST_FUNC શૂન્ય gen_cvt_sxtw(શૂન્ય);
ST_FUNC શૂન્ય gen_cvt_csti(પૂર્ણાંક t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#જો defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC અચલ અક્ષર *default_elfinterp(સંરચના TCCState *s);
#endif
ST_FUNC શૂન્ય arm_init(સંરચના TCCState *s);
ST_FUNC શૂન્ય gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC શૂન્ય gen_opl(પૂર્ણાંક op);
ST_FUNC શૂન્ય gfunc_return(CType *func_type);
ST_FUNC શૂન્ય gen_va_start(શૂન્ય);
ST_FUNC શૂન્ય gen_va_arg(CType *t);
ST_FUNC શૂન્ય gen_clear_cache(શૂન્ય);
ST_FUNC શૂન્ય gen_cvt_sxtw(શૂન્ય);
ST_FUNC શૂન્ય gen_cvt_csti(પૂર્ણાંક t);
ST_FUNC શૂન્ય gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC શૂન્ય gen_opl(પૂર્ણાંક op);
ST_FUNC શૂન્ય gen_va_start(શૂન્ય);
ST_FUNC શૂન્ય arch_transfer_ret_regs(પૂર્ણાંક);
ST_FUNC શૂન્ય gen_cvt_sxtw(શૂન્ય);
ST_FUNC શૂન્ય gen_cvt_csti(પૂર્ણાંક t);
ST_FUNC શૂન્ય gen_increment_tcov (SValue *sv);
ST_FUNC શૂન્ય gen_clear_cache(શૂન્ય);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC પૂર્ણાંક tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC પૂર્ણાંક tcc_load_coff(TCCState * s1, પૂર્ણાંક fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC શૂન્ય asm_instr(શૂન્ય);
ST_FUNC શૂન્ય asm_global_instr(શૂન્ય);
ST_FUNC પૂર્ણાંક tcc_assemble(TCCState *s1, પૂર્ણાંક do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC પૂર્ણાંક find_constraint(ASMOperand *operands, પૂર્ણાંક nb_operands, અચલ અક્ષર *name, અચલ અક્ષર **pp);
ST_FUNC Sym* get_asm_sym(પૂર્ણાંક name, Sym *csym);
ST_FUNC શૂન્ય asm_પદાવલિ(TCCState *s1, પદાવલિ_કિંમત *pe);
ST_FUNC પૂર્ણાંક asm_int_પદાવલિ(TCCState *s1);
#જો PTR_SIZE == 8
ST_FUNC શૂન્ય gen_expr64(પદાવલિ_કિંમત *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC શૂન્ય gen_expr32(પદાવલિ_કિંમત *pe);
ST_FUNC શૂન્ય asm_opcode(TCCState *s1, પૂર્ણાંક opcode);
ST_FUNC પૂર્ણાંક asm_parse_regvar(પૂર્ણાંક t);
ST_FUNC શૂન્ય asm_compute_constraints(ASMOperand *operands, પૂર્ણાંક nb_operands, પૂર્ણાંક nb_outputs, અચલ uint8_t *clobber_regs, પૂર્ણાંક *pout_reg);
ST_FUNC શૂન્ય subst_asm_operand(CString *add_str, SValue *sv, પૂર્ણાંક modifier);
ST_FUNC શૂન્ય asm_gen_code(ASMOperand *operands, પૂર્ણાંક nb_operands, પૂર્ણાંક nb_outputs, પૂર્ણાંક is_output, uint8_t *clobber_regs, પૂર્ણાંક out_reg);
ST_FUNC શૂન્ય asm_clobber(uint8_t *clobber_regs, અચલ અક્ષર *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC પૂર્ણાંક pe_load_file(સંરચના TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename);
ST_FUNC પૂર્ણાંક pe_output_file(TCCState * s1, અચલ અક્ષર *filename);
ST_FUNC પૂર્ણાંક pe_putimport(TCCState *s1, પૂર્ણાંક dllindex, અચલ અક્ષર *name, addr_t કિંમત);
ST_FUNC પૂર્ણાંક pe_setsubsy(TCCState *s1, અચલ અક્ષર *arg);
#જો defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#જો defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC શૂન્ય pe_add_unwind_data(unsigned start, unsigned end, unsigned ઢગલો);
#endif
PUB_FUNC પૂર્ણાંક tcc_get_dllexports(અચલ અક્ષર *filename, અક્ષર **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC પૂર્ણાંક macho_output_file(TCCState * s1, અચલ અક્ષર *filename);
ST_FUNC પૂર્ણાંક macho_load_dll(TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename, પૂર્ણાંક lev);
ST_FUNC પૂર્ણાંક macho_load_tbd(TCCState *s1, પૂર્ણાંક fd, અચલ અક્ષર *filename, પૂર્ણાંક lev);
#ifdef TCC_IS_NATIVE
ST_FUNC શૂન્ય tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC અક્ષર* macho_tbd_soname(પૂર્ણાંક fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    ખાલી
/* dummy function for profiling */
ST_FUNC શૂન્ય *dlopen(અચલ અક્ષર *filename, પૂર્ણાંક flag);
ST_FUNC શૂન્ય dlclose(શૂન્ય *p);
ST_FUNC અચલ અક્ષર *dlerror(શૂન્ય);
ST_FUNC શૂન્ય *dlsym(શૂન્ય *handle, અચલ અક્ષર *પ્રતીક);
#endif
ST_FUNC શૂન્ય tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#જો 0 /* included in tcc.c */
ST_FUNC પૂર્ણાંક tcc_tool_ar(TCCState *s, પૂર્ણાંક argc, અક્ષર **argv);
#ifdef TCC_TARGET_PE
ST_FUNC પૂર્ણાંક tcc_tool_impdef(TCCState *s, પૂર્ણાંક argc, અક્ષર **argv);
#endif
ST_FUNC પૂર્ણાંક tcc_tool_cross(TCCState *s, અક્ષર **argv, પૂર્ણાંક option);
ST_FUNC પૂર્ણાંક gen_makedeps(TCCState *s, અચલ અક્ષર *target, અચલ અક્ષર *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC શૂન્ય tcc_debug_new(TCCState *s);

ST_FUNC શૂન્ય tcc_debug_start(TCCState *s1);
ST_FUNC શૂન્ય tcc_debug_end(TCCState *s1);
ST_FUNC શૂન્ય tcc_debug_bincl(TCCState *s1);
ST_FUNC શૂન્ય tcc_debug_eincl(TCCState *s1);
ST_FUNC શૂન્ય tcc_debug_newfile(TCCState *s1);

ST_FUNC શૂન્ય tcc_debug_લીટી(TCCState *s1);
ST_FUNC શૂન્ય tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC શૂન્ય tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC શૂન્ય tcc_debug_prolog_epilog(TCCState *s1, પૂર્ણાંક કિંમત);
ST_FUNC શૂન્ય tcc_debug_funcend(TCCState *s1, પૂર્ણાંક size);
ST_FUNC શૂન્ય tcc_debug_extern_sym(TCCState *s1, Sym *sym, પૂર્ણાંક sh_અંક, પૂર્ણાંક sym_bind, પૂર્ણાંક sym_type);
ST_FUNC શૂન્ય tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC શૂન્ય tcc_debug_stabn(TCCState *s1, પૂર્ણાંક type, પૂર્ણાંક કિંમત);
ST_FUNC શૂન્ય tcc_debug_fix_forw(TCCState *s1, CType *t);

#જો !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC શૂન્ય tcc_eh_frame_start(TCCState *s1);
ST_FUNC શૂન્ય tcc_eh_frame_end(TCCState *s1);
ST_FUNC શૂન્ય tcc_eh_frame_hdr(TCCState *s1, પૂર્ણાંક final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC શૂન્ય tcc_tcov_start(TCCState *s1);
ST_FUNC શૂન્ય tcc_tcov_end(TCCState *s1);
ST_FUNC શૂન્ય tcc_tcov_check_લીટી(TCCState *s1, પૂર્ણાંક start);
ST_FUNC શૂન્ય tcc_tcov_block_end(TCCState *s1, પૂર્ણાંક લીટી);
ST_FUNC શૂન્ય tcc_tcov_block_begin(TCCState *s1);
ST_FUNC શૂન્ય tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_લીટી_section      s1->dwarf_લીટી_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_લીટી_str_section  s1->dwarf_લીટી_str_section

#define DWARF_MAX_128	((8 * કદ (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
સ્થિર અંતઃરેખ uint64_t
dwarf_read_uleb128(unsigned અક્ષર **ln, unsigned અક્ષર *end)
{
    unsigned અક્ષર *cp = *ln;
    uint64_t retval = 0;
    પૂર્ણાંક i;
    માટે (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	જો ((byte & 0x80) == 0)
	    તોડો;
    }
    *ln = cp;
    પાછા retval;
}
સ્થિર અંતઃરેખ int64_t
dwarf_read_sleb128(unsigned અક્ષર **ln, unsigned અક્ષર *end)
{
    unsigned અક્ષર *cp = *ln;
    int64_t retval = 0;
    પૂર્ણાંક i;
    માટે (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	જો ((byte & 0x80) == 0) {
	    જો ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    તોડો;
	}
    }
    *ln = cp;
    પાછા retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#નહીંતર
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#જો defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#નહીંતર
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#જો CONFIG_TCC_SEMLOCK
#જો defined _WIN32
પ્રકારવ્યાખ્યા સંરચના { અસ્થિર LONG init; CRITICAL_SECTION cs; } TCCSem;
સ્થિર અંતઃરેખ શૂન્ય wait_sem(TCCSem *p) {
    જો (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } નહીંતર {
        જ્યારે (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
સ્થિર અંતઃરેખ શૂન્ય post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#અથવાજો defined __APPLE__
#અન્તર્ભાવ <dispatch/dispatch.h>
પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક init; dispatch_semaphore_t sem; } TCCSem;
સ્થિર અંતઃરેખ શૂન્ય wait_sem(TCCSem *p) {
    જો (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
સ્થિર અંતઃરેખ શૂન્ય post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#નહીંતર
#અન્તર્ભાવ <semaphore.h>
પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક init; sem_t sem; } TCCSem;
સ્થિર અંતઃરેખ શૂન્ય wait_sem(TCCSem *p) {
    જો (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    જ્યારે (sem_wait(&p->sem) < 0 && errno == EINTR);
}
સ્થિર અંતઃરેખ શૂન્ય post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#નહીંતર
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#જો ONE_SOURCE
#define ST_DATA સ્થિર
#નહીંતર
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
#define total_લીટીઓ         TCC_STATE_VAR(total_લીટીઓ)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC શૂન્ય tcc_enter_state(TCCState *s1);
PUB_FUNC શૂન્ય tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_અંક = offsetof(TCCState, sw) \
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
#નહીંતર
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
