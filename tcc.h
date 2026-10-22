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
#ضمن "config.h"

#ضمن <stdarg.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#ضمن <string.h>
#ضمن <errno.h>
#ضمن <math.h>
#ضمن <fcntl.h>
#ضمن <setjmp.h>
#ضمن <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
خارجي عائم strtof (ثابت حرف *__nptr, حرف **__endptr);
خارجي long مزدوج strtold (ثابت حرف *__nptr, حرف **__endptr);
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
# define مضمن __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long مزدوج)strtod
#  define strtof (عائم)strtod
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
# إذا defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_ثنائي_2
# define O_ثنائي_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#وإلا
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (حجم(tab) / حجم((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#وإلا
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#وإلا
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
#إذا !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# إذا defined __x86_64__
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
# وإلا
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
#إذا defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# إذا defined __i386__ && defined TCC_TARGET_I386
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

#إذا defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#وإلا
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#إذا defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#وإلا
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#إذا defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#وإلا
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#إذا defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وإلاإذا !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#إذا defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#وإلا
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#إذا defined TCC_TARGET_PE \
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

#إذا !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#وإلا
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
# إذا defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# وإلا
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# إذا defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# وإلا
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# إذا defined __GNU__
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
# وإلا
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

#ضمن "libtcc.h"
#ضمن "elf.h"
#ضمن "stab.h"
#ضمن "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#إذا ONE_SOURCE
#define ST_INLN ساكن مضمن
#define ST_FUNC ساكن
#define ST_DATA ساكن
#وإلا
#define ST_INLN
#define ST_FUNC
#define ST_DATA خارجي
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define ساكن
# define مضمن
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#وإلاإذا defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#وإلاإذا defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#وإلاإذا defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#وإلاإذا defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#وإلاإذا defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#وإلا
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#إذا PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#وإلا
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

#إذا PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#وإلا
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_مكدس_SIZE  32
#define IFDEF_مكدس_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_مكدس_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
تعريفنوع بنية TokenSym {
    بنية TokenSym *hash_next;
    بنية Sym *sym_define; /* direct pointer to define */
    بنية Sym *sym_label; /* direct pointer to label */
    بنية Sym *sym_struct; /* direct pointer to structure */
    بنية Sym *sym_identifier; /* direct pointer to identifier */
    صحيح tok; /* token number */
    صحيح len;
    حرف str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
تعريفنوع unsigned short nwchar_t;
#وإلا
تعريفنوع صحيح nwchar_t;
#endif

تعريفنوع بنية CString {
    صحيح size; /* size in bytes */
    صحيح size_allocated;
    حرف *data; /* nwchar_t* in cases */
} CString;

/* type definition */
تعريفنوع بنية CType {
    صحيح t;
    بنية Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_كلمات ((حجم(long مزدوج)+3)/4)

/* constant value */
تعريفنوع اتحاد CValue {
    long مزدوج ld;
    مزدوج d;
    عائم f;
    uint64_t i;
    بنية {
        حرف *data;
        صحيح size;
    } str;
    صحيح tab[LDOUBLE_كلمات];
} CValue;

/* value on stack */
تعريفنوع بنية SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اتحاد {
      بنية { صحيح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اتحاد {
      بنية { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      بنية Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
بنية SymAttr {
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
بنية FuncAttr {
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
تعريفنوع بنية Sym {
    صحيح v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    بنية SymAttr a; /* symbol attributes */
    اتحاد {
        بنية {
            صحيح c; /* associated number or Elf symbol index */
            اتحاد {
                صحيح sym_scope; /* scope level for locals */
                صحيح jnext; /* next jump label */
                صحيح jind; /* label position */
                بنية FuncAttr f; /* function attributes */
                صحيح auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        صحيح *d; /* define token stream */
        بنية Sym *cleanup_func;
    };

    CType type; /* associated type */
    اتحاد {
        بنية Sym *next; /* next related symbol (for fields and anoms) */
        صحيح *e; /* expanded token stream with preprocessor macros */
        صحيح asm_label; /* associated asm label */
        بنية Sym *cleanupstate; /* in defined labels */
        صحيح *vla_array_str; /* vla array code */
    };
    بنية Sym *prev; /* prev symbol in stack */
    اتحاد {
        بنية Sym *prev_tok; /* previous symbol for this token */
        بنية Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        بنية Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
تعريفنوع بنية Section {
    unsigned long data_offset; /* current data offset */
    unsigned حرف *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحيح sh_name;             /* elf section name (only used during output) */
    صحيح sh_رقم;              /* elf section number */
    صحيح sh_type;             /* elf section type */
    صحيح sh_flags;            /* elf section flags */
    صحيح sh_info;             /* elf section info */
    صحيح sh_addralign;        /* elf section alignment */
    صحيح sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    صحيح nb_hashed_syms;      /* used to resize the hash table */
    بنية Section *link;    /* link to another section */
    بنية Section *reloc;   /* corresponding section for relocation, if any */
    بنية Section *hash;    /* hash table for symbols */
    بنية Section *prev;    /* previous section on section stack */
    حرف name[1];           /* section name */
} Section;

تعريفنوع بنية DLLReference {
    صحيح level;
    فراغ *handle;
    unsigned حرف found, index;
    حرف name[1];
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

تعريفنوع بنية BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    صحيح fd;
    بنية BufferedFile *prev;
    صحيح سطر_رقم;    /* current line number - here to simplify code */
    صحيح سطر_ref;    /* tcc -E: last printed line */
    صحيح ifndef_macro;  /* #ifndef macro / #endif search */
    صحيح ifndef_macro_saved; /* saved ifndef_macro */
    صحيح *ifdef_مكدس_ptr; /* ifdef_stack value at the start of the file */
    صحيح include_next_index; /* next search path */
    صحيح prev_tok_flags; /* saved tok_flags */
    حرف filename[1024];    /* filename */
    حرف *true_filename; /* filename not modified by # line directive */
    unsigned حرف unget[4];
    unsigned حرف buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
تعريفنوع بنية TokenString {
    صحيح *str;
    صحيح len;
    صحيح need_spc;
    صحيح allocated_len;
    صحيح last_سطر_رقم;
    صحيح save_سطر_رقم;
    /* used to chain token-strings with begin/end_macro() */
    بنية TokenString *prev;
    ثابت صحيح *prev_ptr;
    حرف alloc;
} TokenString;

/* GNUC attribute definition */
تعريفنوع بنية AttributeDef {
    بنية SymAttr a;
    بنية FuncAttr f;
    بنية Section *section;
    Sym *cleanup_func;
    صحيح alias_target; /* token */
    صحيح asm_label; /* associated asm label */
    حرف attr_mode; /* __attribute__((__mode__(...))) */
    حرف new_section; /* section is new */
} AttributeDef;

/* inline functions */
تعريفنوع بنية InlineFunc {
    TokenString *func_str;
    Sym *sym;
    حرف filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
تعريفنوع بنية CachedInclude {
    صحيح ifndef_macro;
    صحيح once;
    صحيح hash_next; /* -1 if none */
    حرف filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
تعريفنوع بنية تعبير_قيمة {
    uint64_t v;
    Sym *sym;
    صحيح pcrel;
} تعبير_قيمة;

#define MAX_ASM_OPERANDS 30
تعريفنوع بنية ASMOperand {
    صحيح id; /* GCC 3 optional identifier (0 if number only supported) */
    حرف constraint[16];
    حرف asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحيح ref_index; /* if >= 0, gives reference to a output constraint */
    صحيح إدخال_index; /* if >= 0, gives reference to an input constraint */
    صحيح priority; /* priority, used to assign registers */
    صحيح reg; /* if >= 0, register number used for this operand */
    صحيح is_llong; /* true if double register value */
    صحيح is_memory; /* true if memory operand */
    صحيح is_rw;     /* for '+' modifier */
    صحيح is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
بنية sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    صحيح plt_sym;
    صحيح dyn_index;
    unsigned حرف linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned حرف plt_thumb_stub:1;
#endif
};

بنية TCCState {
    unsigned حرف verbose; /* if true, display some information during compilation */
    unsigned حرف nostdinc; /* if true, no standard headers are added */
    unsigned حرف nostdlib; /* if true, no standard libraries are added */
    unsigned حرف nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned حرف nocommon; /* if true, do not use common symbols for .bss data */
    unsigned حرف static_link; /* if true, static linking is performed */
    unsigned حرف rdynamic; /* if true, all symbols are exported */
    unsigned حرف symbolic; /* if true, resolve symbols in the current module first */
    unsigned حرف znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned حرف filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned حرف optimize; /* only to #define __OPTIMIZE__ */
    unsigned حرف option_pthread; /* -pthread option */
    unsigned حرف enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned صحيح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned حرف char_is_unsigned;
    unsigned حرف leading_underscore;
    unsigned حرف ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned حرف dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned حرف ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned حرف reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned حرف gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned حرف unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned حرف warn_none;
    unsigned حرف warn_all;
    unsigned حرف warn_error;
    unsigned حرف warn_write_strings;
    unsigned حرف warn_unsupported;
    unsigned حرف warn_implicit_function_declaration;
    unsigned حرف warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned حرف warn_رقم; /* temp var for tcc_warning_c() */

    unsigned حرف option_r; /* option -r */
    unsigned حرف do_bench; /* option -bench */
    unsigned حرف just_deps; /* option -M  */
    unsigned حرف gen_deps; /* option -MD  */
    unsigned حرف include_sys_deps; /* option -MD  */
    unsigned حرف gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned حرف do_debug;
    unsigned حرف dwarf;
    unsigned حرف do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned حرف do_bounds_check;
#endif
    unsigned حرف test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned حرف gnu_ext;
    /* use TinyCC extensions */
    unsigned حرف tcc_ext;

    unsigned حرف dflag; /* -dX value */
    unsigned حرف Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned حرف nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned حرف float_abi; /* float ABI of the generated code*/
#endif

    unsigned حرف has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    صحيح seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    حرف *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    حرف *soname; /* as specified on the command line (-soname) */
    حرف *rpath; /* as specified on the command line (-Wl,-rpath=) */
    حرف *elfint; /* -Wl,-I... on command line */
    حرف *elf_entryname; /* "_start" unless set */
    حرف *init_رمز; /* symbols to call at load-time (not used currently) */
    حرف *fini_رمز; /* symbols to call at unload-time (not used currently) */
    حرف *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحيح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحيح output_format;
    /* nth test to run with -dt -run */
    صحيح run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    صحيح nb_loaded_dlls;

    /* include paths */
    حرف **include_paths;
    صحيح nb_include_paths;

    حرف **sysinclude_paths;
    صحيح nb_sysinclude_paths;

    /* library paths */
    حرف **library_paths;
    صحيح nb_library_paths;

    /* crt?.o object path */
    حرف **crt_paths;
    صحيح nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    فراغ *error_opaque;
    فراغ (*error_func)(فراغ *opaque, ثابت حرف *رسالة);
    صحيح error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحيح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    حرف **target_deps;
    صحيح nb_target_deps;

    /* compilation */
    BufferedFile *include_مكدس[INCLUDE_مكدس_SIZE];
    BufferedFile **include_مكدس_ptr;

    صحيح ifdef_مكدس[IFDEF_مكدس_SIZE];
    صحيح *ifdef_مكدس_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحيح cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    صحيح nb_cached_includes;

    /* #pragma pack stack */
    صحيح pack_مكدس[PACK_مكدس_SIZE];
    صحيح *pack_مكدس_ptr;
    حرف **pragma_libs;
    صحيح nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    بنية InlineFunc **inline_fns;
    صحيح nb_inline_fns;

    /* sections */
    Section **sections;
    صحيح nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    صحيح nb_priv_sections; /* number of private sections */

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
    اتحاد { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_سطر_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_سطر_str_section;
    صحيح dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    بنية _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    بنية sym_attr *sym_attrs;
    صحيح nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    بنية pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحيح nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    صحيح pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_مكدس_size;
    addr_t pe_imagebase;
# إذا defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    صحيح uw_sym;
    صحيح uw_xsym;
    unsigned uw_offs;
# endif
#endif

#إذا defined TCC_TARGET_MACHO
    حرف *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    صحيح nb_sym_versions;
    بنية sym_version *sym_versions;
    صحيح nb_sym_to_version;
    صحيح *sym_to_version;
    صحيح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    ثابت حرف *run_main; /* entry for tcc_run() */
    فراغ *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    ثابت حرف *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    فراغ *run_function_table; /* unwind data */
#endif
    بنية TCCState *next;
    بنية rt_context *rc; /* pointer to backtrace info block */
    فراغ *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    فراغ *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    صحيح rt_رقم_callers;
#endif

    /* benchmark info */
    صحيح total_idents;
    صحيح total_أسطر;
    unsigned صحيح total_bytes;
    unsigned صحيح total_output[4];

    /* used by tcc_load_ldscript */
    unsigned حرف *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ثابت حرف *current_filename;

    /* used by main and tcc_parse_args only */
    بنية filespec **files; /* files seen on command line */
    صحيح nb_files; /* number thereof */
    صحيح nb_libraries; /* number of libs thereof */
    حرف *outfile; /* output filename */
    حرف *deps_outfile; /* option -MF */
    صحيح argc;
    حرف **argv;
    /* -Wl options */
    حرف **link_argv;
    صحيح link_argc, link_optind;
};

بنية filespec {
    حرف type;
    حرف name[1];
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

#define TOK_HAS_قيمة(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

تعداد tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#ضمن "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA بنية TCCState *tcc_state;
ST_DATA فراغ** stk_data;
ST_DATA صحيح nb_stk_data;
ST_DATA صحيح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC حرف *pstrcpy(حرف *buf, size_t buf_size, ثابت حرف *s);
ST_FUNC حرف *pstrcat(حرف *buf, size_t buf_size, ثابت حرف *s);
ST_FUNC حرف *pstrncpy(حرف *out, size_t buf_size, ثابت حرف *s, size_t رقم);
PUB_FUNC حرف *tcc_basename(ثابت حرف *name);
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC فراغ tcc_free(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc(unsigned long size);
PUB_FUNC فراغ *tcc_mallocz(unsigned long size);
PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, unsigned long size);
PUB_FUNC حرف *tcc_strdup(ثابت حرف *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC فراغ tcc_free_debug(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc_debug(unsigned long size, ثابت حرف *file, صحيح سطر);
PUB_FUNC فراغ *tcc_mallocz_debug(unsigned long size, ثابت حرف *file, صحيح سطر);
PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, unsigned long size, ثابت حرف *file, صحيح سطر);
PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح سطر);
#endif

ST_FUNC فراغ libc_free(فراغ *ptr);
/* defined to be not used */
#define حرر(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC صحيح _tcc_error_noabort(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN فراغ _tcc_error(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC فراغ _tcc_warning(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(رسالة) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,رسالة)

/* other utilities */
ST_FUNC فراغ dynarray_add(فراغ *ptab, صحيح *nb_ptr, فراغ *data);
ST_FUNC فراغ dynarray_reset(فراغ *pp, صحيح *n);
ST_INLN فراغ cstr_ccat(CString *cstr, صحيح ch);
ST_FUNC فراغ cstr_cat(CString *cstr, ثابت حرف *str, صحيح len);
ST_FUNC فراغ cstr_wccat(CString *cstr, صحيح ch);
ST_FUNC فراغ cstr_new(CString *cstr);
ST_FUNC فراغ cstr_free(CString *cstr);
ST_FUNC صحيح cstr_printf(CString *cs, ثابت حرف *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC صحيح cstr_vprintf(CString *cstr, ثابت حرف *fmt, va_list ap);
ST_FUNC فراغ cstr_reset(CString *cstr);
ST_FUNC فراغ tcc_open_bf(TCCState *s1, ثابت حرف *filename, صحيح initlen);
ST_FUNC صحيح tcc_open(TCCState *s1, ثابت حرف *filename);
ST_FUNC فراغ tcc_close(فراغ);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_ادفع(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_اسحب() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_ادفع(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_اسحب())

ST_FUNC صحيح tcc_add_file_internal(TCCState *s1, ثابت حرف *filename, صحيح flags);
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
ST_FUNC صحيح tcc_add_crt(TCCState *s, ثابت حرف *filename);
#endif
ST_FUNC صحيح tcc_add_dll(TCCState *s, ثابت حرف *filename, صحيح flags);
ST_FUNC صحيح tcc_add_support(TCCState *s1, ثابت حرف *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC فراغ tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC فراغ tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC صحيح tcc_add_library_err(TCCState *s, ثابت حرف *f);
PUB_FUNC فراغ tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC صحيح tcc_parse_args(TCCState *s, صحيح *argc, حرف ***argv);
#ifdef _WIN32
ST_FUNC حرف *normalize_slashes(حرف *path);
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m);
PUB_FUNC صحيح tcc_fclose(FILE *f);
#وإلا
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level);
ST_FUNC حرف *tcc_load_text(صحيح fd);
/* for #pragma once */
ST_FUNC صحيح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2);

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

ST_DATA بنية BufferedFile *file;
ST_DATA صحيح tok;
ST_DATA CValue tokc;
ST_DATA ثابت صحيح *macro_ptr;
ST_DATA صحيح parse_flags;
ST_DATA صحيح tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA صحيح tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA صحيح pp_تعبير;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_رقم    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_رقم 4

تعداد سطر_macro_output_format {
    سطر_MACRO_OUTPUT_FORMAT_GCC,
    سطر_MACRO_OUTPUT_FORMAT_NONE,
    سطر_MACRO_OUTPUT_FORMAT_STD,
    سطر_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحيح len);
ST_FUNC صحيح tok_alloc_const(ثابت حرف *str);
ST_FUNC ثابت حرف *get_tok_str(صحيح v, CValue *cv);
ST_FUNC فراغ begin_macro(TokenString *str, صحيح alloc);
ST_FUNC فراغ end_macro(فراغ);
ST_FUNC صحيح set_idnum(صحيح c, صحيح val);
ST_INLN فراغ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(فراغ);
ST_FUNC فراغ tok_str_free(TokenString *s);
ST_FUNC فراغ tok_str_free_str(صحيح *str);
ST_FUNC فراغ tok_str_add(TokenString *s, صحيح t);
ST_FUNC فراغ tok_str_add_tok(TokenString *s);
ST_INLN فراغ define_ادفع(صحيح v, صحيح macro_type, صحيح *str, Sym *first_arg);
ST_FUNC فراغ define_undef(Sym *s);
ST_INLN Sym *define_find(صحيح v);
ST_FUNC فراغ free_defines(Sym *b);
ST_FUNC فراغ parse_define(فراغ);
ST_FUNC فراغ skip_to_eol(صحيح warn);
ST_FUNC فراغ preprocess(صحيح is_bof);
ST_FUNC فراغ next(فراغ);
ST_INLN فراغ unget_tok(صحيح last_tok);
ST_FUNC فراغ preprocess_start(TCCState *s1, صحيح filetype);
ST_FUNC فراغ preprocess_end(TCCState *s1);
ST_FUNC فراغ tccpp_new(TCCState *s);
ST_FUNC فراغ tccpp_delete(TCCState *s);
ST_FUNC فراغ tccpp_putfile(ثابت حرف *filename);
ST_FUNC صحيح tcc_preprocess(TCCState *s1);
ST_FUNC فراغ skip(صحيح c);
ST_FUNC NORETURN فراغ expect(ثابت حرف *رسالة);
ST_FUNC فراغ pp_error(CString *cs);


/* space excluding newline */
ساكن مضمن صحيح is_space(صحيح ch) {
    إرجاع ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ساكن مضمن صحيح isid(صحيح c) {
    إرجاع (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ساكن مضمن صحيح isnum(صحيح c) {
    إرجاع c >= '0' && c <= '9';
}
ساكن مضمن صحيح isoct(صحيح c) {
    إرجاع c >= '0' && c <= '7';
}
ساكن مضمن صحيح toup(صحيح c) {
    إرجاع (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / حجم(Sym))

ST_DATA Sym *global_مكدس;
ST_DATA Sym *local_مكدس;
ST_DATA Sym *local_label_مكدس;
ST_DATA Sym *global_label_مكدس;
ST_DATA Sym *define_مكدس;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA صحيح rsym, anon_sym, ind, loc;
ST_DATA حرف debug_modes;

ST_DATA صحيح nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA صحيح global_تعبير;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA صحيح func_var; /* true if current function is variadic */
ST_DATA صحيح func_vc; /* stack address for implicit struct return storage */
ST_DATA صحيح func_ind; /* function start address */
ST_DATA ثابت حرف *funcname;

ST_FUNC فراغ tccgen_init(TCCState *s1);
ST_FUNC صحيح tccgen_compile(TCCState *s1);
ST_FUNC فراغ tccgen_finish(TCCState *s1);
ST_FUNC فراغ check_vstack(فراغ);

ST_INLN صحيح is_float(صحيح t);
ST_FUNC صحيح ieee_finite(مزدوج d);
ST_FUNC صحيح exact_log2p1(صحيح i);
ST_FUNC فراغ test_lvalue(فراغ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC فراغ update_storage(Sym *sym);
ST_FUNC فراغ put_extern_sym2(Sym *sym, صحيح sh_رقم, addr_t قيمة, unsigned long size, صحيح can_add_underscore);
ST_FUNC فراغ put_extern_sym(Sym *sym, Section *section, addr_t قيمة, unsigned long size);
#إذا PTR_SIZE == 4
ST_FUNC فراغ greloc(Section *s, Sym *sym, unsigned long offset, صحيح type);
#endif
ST_FUNC فراغ greloca(Section *s, Sym *sym, unsigned long offset, صحيح type, addr_t addend);

ST_INLN فراغ sym_free(Sym *sym);
ST_FUNC Sym *sym_ادفع(صحيح v, CType *type, صحيح r, صحيح c);
ST_FUNC فراغ sym_اسحب(Sym **ptop, Sym *b, صحيح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحيح v, صحيح t, صحيح c);
ST_FUNC Sym *sym_find2(Sym *s, صحيح v);
ST_INLN Sym *sym_find(صحيح v);
ST_FUNC Sym *label_find(صحيح v);
ST_FUNC Sym *label_ادفع(Sym **ptop, صحيح v, صحيح flags);
ST_FUNC فراغ label_اسحب(Sym **ptop, Sym *slast, صحيح keep);
ST_INLN Sym *struct_find(صحيح v);

ST_FUNC Sym *global_identifier_ادفع(صحيح v, صحيح t, صحيح c);
ST_FUNC Sym *external_global_sym(صحيح v, CType *type);
ST_FUNC Sym *external_helper_sym(صحيح v);
ST_FUNC فراغ vpush_helper_func(صحيح v);
ST_FUNC فراغ vset(CType *type, صحيح r, صحيح v);
ST_FUNC فراغ vset_VT_CMP(صحيح op);
ST_FUNC فراغ vpushi(صحيح v);
ST_FUNC فراغ vpushv(SValue *v);
ST_FUNC فراغ vpushsym(CType *type, Sym *sym);
ST_FUNC فراغ vswap(فراغ);
ST_FUNC فراغ vrott(صحيح n);
ST_FUNC فراغ vrotb(صحيح n);
ST_FUNC فراغ vrev(صحيح n);
ST_FUNC فراغ vpop(فراغ);
#إذا PTR_SIZE == 4
ST_FUNC فراغ lexpand(فراغ);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC صحيح get_reg_ex(صحيح rc, صحيح rc2);
#endif
ST_FUNC فراغ save_reg(صحيح r);
ST_FUNC فراغ save_reg_upstack(صحيح r, صحيح n);
ST_FUNC صحيح get_reg(صحيح rc);
ST_FUNC فراغ save_regs(صحيح n);
ST_FUNC فراغ gaddrof(فراغ);
ST_FUNC صحيح gv(صحيح rc);
ST_FUNC فراغ gv2(صحيح rc1, صحيح rc2);
ST_FUNC فراغ gen_op(صحيح op);
ST_FUNC صحيح type_size(CType *type, صحيح *a);
ST_FUNC فراغ mk_pointer(CType *type);
ST_FUNC فراغ vstore(فراغ);
ST_FUNC فراغ inc(صحيح post, صحيح c);
ST_FUNC CString* parse_mult_str(ثابت حرف *رسالة);
ST_FUNC CString* parse_asm_str(فراغ);
ST_FUNC فراغ indir(فراغ);
ST_FUNC فراغ unary(فراغ);
ST_FUNC فراغ gexpr(فراغ);
ST_FUNC صحيح تعبير_const(فراغ);
#إذا defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#إذا defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC صحيح classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC فراغ gbound_args(صحيح nb_args);
ST_DATA صحيح func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, صحيح c, صحيح byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_ثنائي 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

تعريفنوع بنية {
    unsigned صحيح n_strx;         /* index into string table of name */
    unsigned حرف n_type;         /* type of symbol */
    unsigned حرف n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned صحيح n_قيمة;        /* value of symbol */
} Stab_Sym;

ST_FUNC فراغ tccelf_new(TCCState *s);
ST_FUNC فراغ tccelf_delete(TCCState *s);
ST_FUNC فراغ tccelf_begin_file(TCCState *s1);
ST_FUNC فراغ tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags);
ST_FUNC فراغ section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, صحيح align);
ST_FUNC فراغ *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, ثابت حرف *name);
ST_FUNC فراغ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت حرف *symtab_name, صحيح sh_type, صحيح sh_flags, ثابت حرف *strtab_name, ثابت حرف *hash_name, صحيح hash_sh_flags);
ST_FUNC فراغ init_symtab(Section *s);

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym);
ST_FUNC صحيح put_elf_sym(Section *s, addr_t قيمة, unsigned long size, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح set_elf_sym(Section *s, addr_t قيمة, unsigned long size, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح find_elf_sym(Section *s, ثابت حرف *name);
ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, unsigned long offset, صحيح type, صحيح رمز);
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, unsigned long offset, صحيح type, صحيح رمز, addr_t addend);

ST_FUNC فراغ resolve_common_syms(TCCState *s1);
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve);
ST_FUNC فراغ relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(صحيح fd, فراغ *buf, size_t تعداد_3);
ST_FUNC فراغ *load_data(صحيح fd, unsigned long file_offset, unsigned long size);
ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h);
ST_FUNC صحيح tcc_load_object_file(TCCState *s1, صحيح fd, unsigned long file_offset);
ST_FUNC صحيح tcc_load_archive(TCCState *s1, صحيح fd, صحيح alacarte);
ST_FUNC فراغ add_array(TCCState *s1, ثابت حرف *sec, صحيح c);

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح index, صحيح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت حرف *name, صحيح err, صحيح forc);
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*رمز_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));
ST_FUNC صحيح set_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    لكل (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC صحيح tcc_load_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level);
ST_FUNC صحيح tcc_load_ldscript(TCCState *s1, صحيح fd);
ST_FUNC فراغ tccelf_add_crtbegin(TCCState *s1);
ST_FUNC فراغ tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC فراغ tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC صحيح code_reloc (صحيح reloc_type);
ST_FUNC صحيح gotplt_entry_type (صحيح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
تعداد gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#إذا !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, بنية sym_attr *attr);
ST_FUNC فراغ relocate_plt(TCCState *s1);
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, unsigned حرف *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA ثابت حرف * ثابت target_machine_defs;
ST_DATA ثابت صحيح reg_classes[NB_REGS];

ST_FUNC فراغ gsym_addr(صحيح t, صحيح a);
ST_FUNC فراغ gsym(صحيح t);
ST_FUNC فراغ load(صحيح r, SValue *sv);
ST_FUNC فراغ store(صحيح r, SValue *v);
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *align, صحيح *regsize);
ST_FUNC فراغ gfunc_call(صحيح nb_args);
ST_FUNC فراغ gfunc_prolog(Sym *func_sym);
ST_FUNC فراغ gfunc_epilog(فراغ);
ST_FUNC فراغ gen_fill_nops(صحيح);
ST_FUNC صحيح gjmp(صحيح t);
ST_FUNC فراغ gjmp_addr(صحيح a);
ST_FUNC صحيح gjmp_cond(صحيح op, صحيح t);
ST_FUNC صحيح gjmp_append(صحيح n, صحيح t);
ST_FUNC فراغ gen_opi(صحيح op);
ST_FUNC فراغ gen_opf(صحيح op);
ST_FUNC فراغ gen_cvt_ftoi(صحيح t);
ST_FUNC فراغ gen_cvt_itof(صحيح t);
ST_FUNC فراغ gen_cvt_ftof(صحيح t);
ST_FUNC فراغ ggoto(فراغ);
#ifndef TCC_TARGET_C67
ST_FUNC فراغ o(unsigned صحيح c);
#endif
ST_FUNC فراغ gen_vla_sp_save(صحيح addr);
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr);
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align);

ساكن مضمن uint16_t read16le(unsigned حرف *p) {
    إرجاع p[0] | (uint16_t)p[1] << 8;
}
ساكن مضمن فراغ write16le(unsigned حرف *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ساكن مضمن uint32_t read32le(unsigned حرف *p) {
  إرجاع read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ساكن مضمن فراغ write32le(unsigned حرف *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ساكن مضمن فراغ add32le(unsigned حرف *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ساكن مضمن uint64_t read64le(unsigned حرف *p) {
  إرجاع read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ساكن مضمن فراغ write64le(unsigned حرف *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ساكن مضمن فراغ add64le(unsigned حرف *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#إذا defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);
#endif
#إذا defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC فراغ gen_opl(صحيح op);
#ifdef TCC_TARGET_PE
ST_FUNC فراغ gen_vla_result(صحيح addr);
#endif
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#إذا defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت حرف *default_elfinterp(بنية TCCState *s);
#endif
ST_FUNC فراغ arm_init(بنية TCCState *s);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gfunc_return(CType *func_type);
ST_FUNC فراغ gen_va_start(فراغ);
ST_FUNC فراغ gen_va_arg(CType *t);
ST_FUNC فراغ gen_clear_cache(فراغ);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gen_va_start(فراغ);
ST_FUNC فراغ arch_transfer_ret_regs(صحيح);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
ST_FUNC فراغ gen_clear_cache(فراغ);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحيح tcc_load_coff(TCCState * s1, صحيح fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC فراغ asm_instr(فراغ);
ST_FUNC فراغ asm_global_instr(فراغ);
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC صحيح find_constraint(ASMOperand *operands, صحيح nb_operands, ثابت حرف *name, ثابت حرف **pp);
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym);
ST_FUNC فراغ asm_تعبير(TCCState *s1, تعبير_قيمة *pe);
ST_FUNC صحيح asm_int_تعبير(TCCState *s1);
#إذا PTR_SIZE == 8
ST_FUNC فراغ gen_expr64(تعبير_قيمة *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC فراغ gen_expr32(تعبير_قيمة *pe);
ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode);
ST_FUNC صحيح asm_parse_regvar(صحيح t);
ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, ثابت uint8_t *clobber_regs, صحيح *pout_reg);
ST_FUNC فراغ subst_asm_operand(CString *add_str, SValue *sv, صحيح modifier);
ST_FUNC فراغ asm_gen_code(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, صحيح is_output, uint8_t *clobber_regs, صحيح out_reg);
ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC صحيح pe_load_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename);
ST_FUNC صحيح pe_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t قيمة);
ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg);
#إذا defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#إذا defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC فراغ pe_add_unwind_data(unsigned start, unsigned end, unsigned مكدس);
#endif
PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC صحيح macho_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح macho_load_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
ST_FUNC صحيح macho_load_tbd(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
#ifdef TCC_IS_NATIVE
ST_FUNC فراغ tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC حرف* macho_tbd_soname(صحيح fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    عدم
/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ST_FUNC فراغ dlclose(فراغ *p);
ST_FUNC ثابت حرف *dlerror(فراغ);
ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *رمز);
#endif
ST_FUNC فراغ tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#إذا 0 /* included in tcc.c */
ST_FUNC صحيح tcc_tool_ar(TCCState *s, صحيح argc, حرف **argv);
#ifdef TCC_TARGET_PE
ST_FUNC صحيح tcc_tool_impdef(TCCState *s, صحيح argc, حرف **argv);
#endif
ST_FUNC صحيح tcc_tool_cross(TCCState *s, حرف **argv, صحيح option);
ST_FUNC صحيح gen_makedeps(TCCState *s, ثابت حرف *target, ثابت حرف *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC فراغ tcc_debug_new(TCCState *s);

ST_FUNC فراغ tcc_debug_start(TCCState *s1);
ST_FUNC فراغ tcc_debug_end(TCCState *s1);
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1);

ST_FUNC فراغ tcc_debug_سطر(TCCState *s1);
ST_FUNC فراغ tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC فراغ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح قيمة);
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح size);
ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_رقم, صحيح sym_bind, صحيح sym_type);
ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح قيمة);
ST_FUNC فراغ tcc_debug_fix_forw(TCCState *s1, CType *t);

#إذا !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC فراغ tcc_eh_frame_start(TCCState *s1);
ST_FUNC فراغ tcc_eh_frame_end(TCCState *s1);
ST_FUNC فراغ tcc_eh_frame_hdr(TCCState *s1, صحيح final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC فراغ tcc_tcov_start(TCCState *s1);
ST_FUNC فراغ tcc_tcov_end(TCCState *s1);
ST_FUNC فراغ tcc_tcov_check_سطر(TCCState *s1, صحيح start);
ST_FUNC فراغ tcc_tcov_block_end(TCCState *s1, صحيح سطر);
ST_FUNC فراغ tcc_tcov_block_begin(TCCState *s1);
ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_سطر_section      s1->dwarf_سطر_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_سطر_str_section  s1->dwarf_سطر_str_section

#define DWARF_MAX_128	((8 * حجم (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
ساكن مضمن uint64_t
dwarf_read_uleb128(unsigned حرف **ln, unsigned حرف *end)
{
    unsigned حرف *cp = *ln;
    uint64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0)
	    اكسر;
    }
    *ln = cp;
    إرجاع retval;
}
ساكن مضمن int64_t
dwarf_read_sleb128(unsigned حرف **ln, unsigned حرف *end)
{
    unsigned حرف *cp = *ln;
    int64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0) {
	    إذا ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    اكسر;
	}
    }
    *ln = cp;
    إرجاع retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#وإلا
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#إذا defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#وإلا
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#إذا CONFIG_TCC_SEMLOCK
#إذا defined _WIN32
تعريفنوع بنية { متطاير LONG init; CRITICAL_SECTION cs; } TCCSem;
ساكن مضمن فراغ wait_sem(TCCSem *p) {
    إذا (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } وإلا {
        بينما (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ساكن مضمن فراغ post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#وإلاإذا defined __APPLE__
#ضمن <dispatch/dispatch.h>
تعريفنوع بنية { صحيح init; dispatch_semaphore_t sem; } TCCSem;
ساكن مضمن فراغ wait_sem(TCCSem *p) {
    إذا (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
ساكن مضمن فراغ post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#وإلا
#ضمن <semaphore.h>
تعريفنوع بنية { صحيح init; sem_t sem; } TCCSem;
ساكن مضمن فراغ wait_sem(TCCSem *p) {
    إذا (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    بينما (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ساكن مضمن فراغ post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#وإلا
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#إذا ONE_SOURCE
#define ST_DATA ساكن
#وإلا
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
#define total_أسطر         TCC_STATE_VAR(total_أسطر)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC فراغ tcc_enter_state(TCCState *s1);
PUB_FUNC فراغ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_رقم = offsetof(TCCState, sw) \
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
#وإلا
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
