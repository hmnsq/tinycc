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
#شامل "config.h"

#شامل <stdarg.h>
#شامل <stdlib.h>
#شامل <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#شامل <string.h>
#شامل <errno.h>
#شامل <math.h>
#شامل <fcntl.h>
#شامل <setjmp.h>
#شامل <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
بیرونی اعشاری strtof (ثابت نویسه *__nptr, نویسه **__endptr);
بیرونی long دوگانه strtold (ثابت نویسه *__nptr, نویسه **__endptr);
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
# define درونخطی __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long دوگانه)strtod
#  define strtof (اعشاری)strtod
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
# اگر defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_دودویی_2
# define O_دودویی_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#وگرنه
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (اندازه(tab) / اندازه((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#وگرنه
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#وگرنه
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
#اگر !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# اگر defined __x86_64__
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
# وگرنه
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
#اگر defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# اگر defined __i386__ && defined TCC_TARGET_I386
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

#اگر defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#وگرنه
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#اگر defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#وگرنه
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#اگر defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#وگرنه
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#اگر defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وگرنهاگر !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#اگر defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#وگرنه
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#اگر defined TCC_TARGET_PE \
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

#اگر !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#وگرنه
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
# اگر defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# وگرنه
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# اگر defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# وگرنه
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# اگر defined __GNU__
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
# وگرنه
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

#شامل "libtcc.h"
#شامل "elf.h"
#شامل "stab.h"
#شامل "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#اگر ONE_SOURCE
#define ST_INLN ایستا درونخطی
#define ST_FUNC ایستا
#define ST_DATA ایستا
#وگرنه
#define ST_INLN
#define ST_FUNC
#define ST_DATA بیرونی
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define ایستا
# define درونخطی
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#وگرنهاگر defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#وگرنهاگر defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#وگرنهاگر defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#وگرنهاگر defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#وگرنهاگر defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#وگرنه
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#اگر PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#وگرنه
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

#اگر PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#وگرنه
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_پشته_SIZE  32
#define IFDEF_پشته_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_پشته_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
تعریفنوع ساختار TokenSym {
    ساختار TokenSym *hash_next;
    ساختار Sym *sym_define; /* direct pointer to define */
    ساختار Sym *sym_label; /* direct pointer to label */
    ساختار Sym *sym_struct; /* direct pointer to structure */
    ساختار Sym *sym_identifier; /* direct pointer to identifier */
    صحیح tok; /* token number */
    صحیح len;
    نویسه str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
تعریفنوع unsigned short nwchar_t;
#وگرنه
تعریفنوع صحیح nwchar_t;
#endif

تعریفنوع ساختار CString {
    صحیح size; /* size in bytes */
    صحیح size_allocated;
    نویسه *data; /* nwchar_t* in cases */
} CString;

/* type definition */
تعریفنوع ساختار CType {
    صحیح t;
    ساختار Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_واژگان ((اندازه(long دوگانه)+3)/4)

/* constant value */
تعریفنوع اجتماع CValue {
    long دوگانه ld;
    دوگانه d;
    اعشاری f;
    uint64_t i;
    ساختار {
        نویسه *data;
        صحیح size;
    } str;
    صحیح tab[LDOUBLE_واژگان];
} CValue;

/* value on stack */
تعریفنوع ساختار SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اجتماع {
      ساختار { صحیح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اجتماع {
      ساختار { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      ساختار Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ساختار SymAttr {
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
ساختار FuncAttr {
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
تعریفنوع ساختار Sym {
    صحیح v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ساختار SymAttr a; /* symbol attributes */
    اجتماع {
        ساختار {
            صحیح c; /* associated number or Elf symbol index */
            اجتماع {
                صحیح sym_scope; /* scope level for locals */
                صحیح jnext; /* next jump label */
                صحیح jind; /* label position */
                ساختار FuncAttr f; /* function attributes */
                صحیح auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        صحیح *d; /* define token stream */
        ساختار Sym *cleanup_func;
    };

    CType type; /* associated type */
    اجتماع {
        ساختار Sym *next; /* next related symbol (for fields and anoms) */
        صحیح *e; /* expanded token stream with preprocessor macros */
        صحیح asm_label; /* associated asm label */
        ساختار Sym *cleanupstate; /* in defined labels */
        صحیح *vla_array_str; /* vla array code */
    };
    ساختار Sym *prev; /* prev symbol in stack */
    اجتماع {
        ساختار Sym *prev_tok; /* previous symbol for this token */
        ساختار Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ساختار Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
تعریفنوع ساختار Section {
    unsigned long data_offset; /* current data offset */
    unsigned نویسه *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحیح sh_name;             /* elf section name (only used during output) */
    صحیح sh_رقم;              /* elf section number */
    صحیح sh_type;             /* elf section type */
    صحیح sh_flags;            /* elf section flags */
    صحیح sh_info;             /* elf section info */
    صحیح sh_addralign;        /* elf section alignment */
    صحیح sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    صحیح nb_hashed_syms;      /* used to resize the hash table */
    ساختار Section *link;    /* link to another section */
    ساختار Section *reloc;   /* corresponding section for relocation, if any */
    ساختار Section *hash;    /* hash table for symbols */
    ساختار Section *prev;    /* previous section on section stack */
    نویسه name[1];           /* section name */
} Section;

تعریفنوع ساختار DLLReference {
    صحیح level;
    تهی *handle;
    unsigned نویسه found, index;
    نویسه name[1];
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

تعریفنوع ساختار BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    صحیح fd;
    ساختار BufferedFile *prev;
    صحیح سطر_رقم;    /* current line number - here to simplify code */
    صحیح سطر_ref;    /* tcc -E: last printed line */
    صحیح ifndef_macro;  /* #ifndef macro / #endif search */
    صحیح ifndef_macro_saved; /* saved ifndef_macro */
    صحیح *ifdef_پشته_ptr; /* ifdef_stack value at the start of the file */
    صحیح include_next_index; /* next search path */
    صحیح prev_tok_flags; /* saved tok_flags */
    نویسه filename[1024];    /* filename */
    نویسه *true_filename; /* filename not modified by # line directive */
    unsigned نویسه unget[4];
    unsigned نویسه buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
تعریفنوع ساختار TokenString {
    صحیح *str;
    صحیح len;
    صحیح need_spc;
    صحیح allocated_len;
    صحیح last_سطر_رقم;
    صحیح save_سطر_رقم;
    /* used to chain token-strings with begin/end_macro() */
    ساختار TokenString *prev;
    ثابت صحیح *prev_ptr;
    نویسه alloc;
} TokenString;

/* GNUC attribute definition */
تعریفنوع ساختار AttributeDef {
    ساختار SymAttr a;
    ساختار FuncAttr f;
    ساختار Section *section;
    Sym *cleanup_func;
    صحیح alias_target; /* token */
    صحیح asm_label; /* associated asm label */
    نویسه attr_mode; /* __attribute__((__mode__(...))) */
    نویسه new_section; /* section is new */
} AttributeDef;

/* inline functions */
تعریفنوع ساختار InlineFunc {
    TokenString *func_str;
    Sym *sym;
    نویسه filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
تعریفنوع ساختار CachedInclude {
    صحیح ifndef_macro;
    صحیح once;
    صحیح hash_next; /* -1 if none */
    نویسه filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
تعریفنوع ساختار عبارت_مقدار {
    uint64_t v;
    Sym *sym;
    صحیح pcrel;
} عبارت_مقدار;

#define MAX_ASM_OPERANDS 30
تعریفنوع ساختار ASMOperand {
    صحیح id; /* GCC 3 optional identifier (0 if number only supported) */
    نویسه constraint[16];
    نویسه asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحیح ref_index; /* if >= 0, gives reference to a output constraint */
    صحیح درون_داد_index; /* if >= 0, gives reference to an input constraint */
    صحیح priority; /* priority, used to assign registers */
    صحیح reg; /* if >= 0, register number used for this operand */
    صحیح is_llong; /* true if double register value */
    صحیح is_memory; /* true if memory operand */
    صحیح is_rw;     /* for '+' modifier */
    صحیح is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
ساختار sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    صحیح plt_sym;
    صحیح dyn_index;
    unsigned نویسه linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned نویسه plt_thumb_stub:1;
#endif
};

ساختار TCCState {
    unsigned نویسه verbose; /* if true, display some information during compilation */
    unsigned نویسه nostdinc; /* if true, no standard headers are added */
    unsigned نویسه nostdlib; /* if true, no standard libraries are added */
    unsigned نویسه nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned نویسه nocommon; /* if true, do not use common symbols for .bss data */
    unsigned نویسه static_link; /* if true, static linking is performed */
    unsigned نویسه rdynamic; /* if true, all symbols are exported */
    unsigned نویسه symbolic; /* if true, resolve symbols in the current module first */
    unsigned نویسه znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned نویسه filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned نویسه optimize; /* only to #define __OPTIMIZE__ */
    unsigned نویسه option_pthread; /* -pthread option */
    unsigned نویسه enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned صحیح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned نویسه char_is_unsigned;
    unsigned نویسه leading_underscore;
    unsigned نویسه ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned نویسه dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned نویسه ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned نویسه reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned نویسه gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned نویسه unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned نویسه warn_none;
    unsigned نویسه warn_all;
    unsigned نویسه warn_error;
    unsigned نویسه warn_write_strings;
    unsigned نویسه warn_unsupported;
    unsigned نویسه warn_implicit_function_declaration;
    unsigned نویسه warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned نویسه warn_رقم; /* temp var for tcc_warning_c() */

    unsigned نویسه option_r; /* option -r */
    unsigned نویسه do_bench; /* option -bench */
    unsigned نویسه just_deps; /* option -M  */
    unsigned نویسه gen_deps; /* option -MD  */
    unsigned نویسه include_sys_deps; /* option -MD  */
    unsigned نویسه gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned نویسه do_debug;
    unsigned نویسه dwarf;
    unsigned نویسه do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned نویسه do_bounds_check;
#endif
    unsigned نویسه test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned نویسه gnu_ext;
    /* use TinyCC extensions */
    unsigned نویسه tcc_ext;

    unsigned نویسه dflag; /* -dX value */
    unsigned نویسه Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned نویسه nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned نویسه float_abi; /* float ABI of the generated code*/
#endif

    unsigned نویسه has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    صحیح seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    نویسه *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    نویسه *soname; /* as specified on the command line (-soname) */
    نویسه *rpath; /* as specified on the command line (-Wl,-rpath=) */
    نویسه *elfint; /* -Wl,-I... on command line */
    نویسه *elf_entryname; /* "_start" unless set */
    نویسه *init_نماد; /* symbols to call at load-time (not used currently) */
    نویسه *fini_نماد; /* symbols to call at unload-time (not used currently) */
    نویسه *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحیح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحیح output_format;
    /* nth test to run with -dt -run */
    صحیح run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    صحیح nb_loaded_dlls;

    /* include paths */
    نویسه **include_paths;
    صحیح nb_include_paths;

    نویسه **sysinclude_paths;
    صحیح nb_sysinclude_paths;

    /* library paths */
    نویسه **library_paths;
    صحیح nb_library_paths;

    /* crt?.o object path */
    نویسه **crt_paths;
    صحیح nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    تهی *error_opaque;
    تهی (*error_func)(تهی *opaque, ثابت نویسه *پیام);
    صحیح error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحیح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    نویسه **target_deps;
    صحیح nb_target_deps;

    /* compilation */
    BufferedFile *include_پشته[INCLUDE_پشته_SIZE];
    BufferedFile **include_پشته_ptr;

    صحیح ifdef_پشته[IFDEF_پشته_SIZE];
    صحیح *ifdef_پشته_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحیح cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    صحیح nb_cached_includes;

    /* #pragma pack stack */
    صحیح pack_پشته[PACK_پشته_SIZE];
    صحیح *pack_پشته_ptr;
    نویسه **pragma_libs;
    صحیح nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ساختار InlineFunc **inline_fns;
    صحیح nb_inline_fns;

    /* sections */
    Section **sections;
    صحیح nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    صحیح nb_priv_sections; /* number of private sections */

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
    اجتماع { Section *symtab_section, *symtab; }; /* historical alias */
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
    صحیح dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    ساختار _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ساختار sym_attr *sym_attrs;
    صحیح nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    ساختار pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحیح nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    صحیح pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_پشته_size;
    addr_t pe_imagebase;
# اگر defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    صحیح uw_sym;
    صحیح uw_xsym;
    unsigned uw_offs;
# endif
#endif

#اگر defined TCC_TARGET_MACHO
    نویسه *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    صحیح nb_sym_versions;
    ساختار sym_version *sym_versions;
    صحیح nb_sym_to_version;
    صحیح *sym_to_version;
    صحیح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    ثابت نویسه *run_main; /* entry for tcc_run() */
    تهی *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    ثابت نویسه *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    تهی *run_function_table; /* unwind data */
#endif
    ساختار TCCState *next;
    ساختار rt_context *rc; /* pointer to backtrace info block */
    تهی *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    تهی *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    صحیح rt_رقم_callers;
#endif

    /* benchmark info */
    صحیح total_idents;
    صحیح total_سطرها;
    unsigned صحیح total_bytes;
    unsigned صحیح total_output[4];

    /* used by tcc_load_ldscript */
    unsigned نویسه *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ثابت نویسه *current_filename;

    /* used by main and tcc_parse_args only */
    ساختار filespec **files; /* files seen on command line */
    صحیح nb_files; /* number thereof */
    صحیح nb_libraries; /* number of libs thereof */
    نویسه *outfile; /* output filename */
    نویسه *deps_outfile; /* option -MF */
    صحیح argc;
    نویسه **argv;
    /* -Wl options */
    نویسه **link_argv;
    صحیح link_argc, link_optind;
};

ساختار filespec {
    نویسه type;
    نویسه name[1];
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

#define TOK_HAS_مقدار(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

شمارش tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#شامل "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA ساختار TCCState *tcc_state;
ST_DATA تهی** stk_data;
ST_DATA صحیح nb_stk_data;
ST_DATA صحیح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC نویسه *pstrcpy(نویسه *buf, size_t buf_size, ثابت نویسه *s);
ST_FUNC نویسه *pstrcat(نویسه *buf, size_t buf_size, ثابت نویسه *s);
ST_FUNC نویسه *pstrncpy(نویسه *out, size_t buf_size, ثابت نویسه *s, size_t رقم);
PUB_FUNC نویسه *tcc_basename(ثابت نویسه *name);
PUB_FUNC نویسه *tcc_fileextension (ثابت نویسه *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC تهی tcc_free(تهی *ptr);
PUB_FUNC تهی *tcc_malloc(unsigned long size);
PUB_FUNC تهی *tcc_mallocz(unsigned long size);
PUB_FUNC تهی *tcc_realloc(تهی *ptr, unsigned long size);
PUB_FUNC نویسه *tcc_strdup(ثابت نویسه *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC تهی tcc_free_debug(تهی *ptr);
PUB_FUNC تهی *tcc_malloc_debug(unsigned long size, ثابت نویسه *file, صحیح سطر);
PUB_FUNC تهی *tcc_mallocz_debug(unsigned long size, ثابت نویسه *file, صحیح سطر);
PUB_FUNC تهی *tcc_realloc_debug(تهی *ptr, unsigned long size, ثابت نویسه *file, صحیح سطر);
PUB_FUNC نویسه *tcc_strdup_debug(ثابت نویسه *str, ثابت نویسه *file, صحیح سطر);
#endif

ST_FUNC تهی libc_free(تهی *ptr);
/* defined to be not used */
#define آزاد(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC صحیح _tcc_error_noabort(ثابت نویسه *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN تهی _tcc_error(ثابت نویسه *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC تهی _tcc_warning(ثابت نویسه *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(پیام) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,پیام)

/* other utilities */
ST_FUNC تهی dynarray_add(تهی *ptab, صحیح *nb_ptr, تهی *data);
ST_FUNC تهی dynarray_reset(تهی *pp, صحیح *n);
ST_INLN تهی cstr_ccat(CString *cstr, صحیح ch);
ST_FUNC تهی cstr_cat(CString *cstr, ثابت نویسه *str, صحیح len);
ST_FUNC تهی cstr_wccat(CString *cstr, صحیح ch);
ST_FUNC تهی cstr_new(CString *cstr);
ST_FUNC تهی cstr_free(CString *cstr);
ST_FUNC صحیح cstr_printf(CString *cs, ثابت نویسه *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC صحیح cstr_vprintf(CString *cstr, ثابت نویسه *fmt, va_list ap);
ST_FUNC تهی cstr_reset(CString *cstr);
ST_FUNC تهی tcc_open_bf(TCCState *s1, ثابت نویسه *filename, صحیح initlen);
ST_FUNC صحیح tcc_open(TCCState *s1, ثابت نویسه *filename);
ST_FUNC تهی tcc_close(تهی);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_افزودن(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_برداشت() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_افزودن(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_برداشت())

ST_FUNC صحیح tcc_add_file_internal(TCCState *s1, ثابت نویسه *filename, صحیح flags);
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
ST_FUNC صحیح tcc_add_crt(TCCState *s, ثابت نویسه *filename);
#endif
ST_FUNC صحیح tcc_add_dll(TCCState *s, ثابت نویسه *filename, صحیح flags);
ST_FUNC صحیح tcc_add_support(TCCState *s1, ثابت نویسه *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC تهی tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC تهی tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC تهی tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC صحیح tcc_add_library_err(TCCState *s, ثابت نویسه *f);
PUB_FUNC تهی tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC صحیح tcc_parse_args(TCCState *s, صحیح *argc, نویسه ***argv);
#ifdef _WIN32
ST_FUNC نویسه *normalize_slashes(نویسه *path);
PUB_FUNC FILE *tcc_fopen(ثابت نویسه *f, ثابت نویسه *m);
PUB_FUNC صحیح tcc_fclose(FILE *f);
#وگرنه
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ثابت نویسه *dllname, صحیح level);
ST_FUNC نویسه *tcc_load_text(صحیح fd);
/* for #pragma once */
ST_FUNC صحیح normalized_PATHCMP(ثابت نویسه *f1, ثابت نویسه *f2);

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

ST_DATA ساختار BufferedFile *file;
ST_DATA صحیح tok;
ST_DATA CValue tokc;
ST_DATA ثابت صحیح *macro_ptr;
ST_DATA صحیح parse_flags;
ST_DATA صحیح tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA صحیح tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA صحیح pp_عبارت;

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

شمارش سطر_macro_output_format {
    سطر_MACRO_OUTPUT_FORMAT_GCC,
    سطر_MACRO_OUTPUT_FORMAT_NONE,
    سطر_MACRO_OUTPUT_FORMAT_STD,
    سطر_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ثابت نویسه *str, صحیح len);
ST_FUNC صحیح tok_alloc_const(ثابت نویسه *str);
ST_FUNC ثابت نویسه *get_tok_str(صحیح v, CValue *cv);
ST_FUNC تهی begin_macro(TokenString *str, صحیح alloc);
ST_FUNC تهی end_macro(تهی);
ST_FUNC صحیح set_idnum(صحیح c, صحیح val);
ST_INLN تهی tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(تهی);
ST_FUNC تهی tok_str_free(TokenString *s);
ST_FUNC تهی tok_str_free_str(صحیح *str);
ST_FUNC تهی tok_str_add(TokenString *s, صحیح t);
ST_FUNC تهی tok_str_add_tok(TokenString *s);
ST_INLN تهی define_افزودن(صحیح v, صحیح macro_type, صحیح *str, Sym *first_arg);
ST_FUNC تهی define_undef(Sym *s);
ST_INLN Sym *define_find(صحیح v);
ST_FUNC تهی free_defines(Sym *b);
ST_FUNC تهی parse_define(تهی);
ST_FUNC تهی skip_to_eol(صحیح warn);
ST_FUNC تهی preprocess(صحیح is_bof);
ST_FUNC تهی next(تهی);
ST_INLN تهی unget_tok(صحیح last_tok);
ST_FUNC تهی preprocess_start(TCCState *s1, صحیح filetype);
ST_FUNC تهی preprocess_end(TCCState *s1);
ST_FUNC تهی tccpp_new(TCCState *s);
ST_FUNC تهی tccpp_delete(TCCState *s);
ST_FUNC تهی tccpp_putfile(ثابت نویسه *filename);
ST_FUNC صحیح tcc_preprocess(TCCState *s1);
ST_FUNC تهی skip(صحیح c);
ST_FUNC NORETURN تهی expect(ثابت نویسه *پیام);
ST_FUNC تهی pp_error(CString *cs);


/* space excluding newline */
ایستا درونخطی صحیح is_space(صحیح ch) {
    بازگشت ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ایستا درونخطی صحیح isid(صحیح c) {
    بازگشت (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ایستا درونخطی صحیح isnum(صحیح c) {
    بازگشت c >= '0' && c <= '9';
}
ایستا درونخطی صحیح isoct(صحیح c) {
    بازگشت c >= '0' && c <= '7';
}
ایستا درونخطی صحیح toup(صحیح c) {
    بازگشت (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / اندازه(Sym))

ST_DATA Sym *global_پشته;
ST_DATA Sym *local_پشته;
ST_DATA Sym *local_label_پشته;
ST_DATA Sym *global_label_پشته;
ST_DATA Sym *define_پشته;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA صحیح rsym, anon_sym, ind, loc;
ST_DATA نویسه debug_modes;

ST_DATA صحیح nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA صحیح global_عبارت;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA صحیح func_var; /* true if current function is variadic */
ST_DATA صحیح func_vc; /* stack address for implicit struct return storage */
ST_DATA صحیح func_ind; /* function start address */
ST_DATA ثابت نویسه *funcname;

ST_FUNC تهی tccgen_init(TCCState *s1);
ST_FUNC صحیح tccgen_compile(TCCState *s1);
ST_FUNC تهی tccgen_finish(TCCState *s1);
ST_FUNC تهی check_vstack(تهی);

ST_INLN صحیح is_float(صحیح t);
ST_FUNC صحیح ieee_finite(دوگانه d);
ST_FUNC صحیح exact_log2p1(صحیح i);
ST_FUNC تهی test_lvalue(تهی);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC تهی update_storage(Sym *sym);
ST_FUNC تهی put_extern_sym2(Sym *sym, صحیح sh_رقم, addr_t مقدار, unsigned long size, صحیح can_add_underscore);
ST_FUNC تهی put_extern_sym(Sym *sym, Section *section, addr_t مقدار, unsigned long size);
#اگر PTR_SIZE == 4
ST_FUNC تهی greloc(Section *s, Sym *sym, unsigned long offset, صحیح type);
#endif
ST_FUNC تهی greloca(Section *s, Sym *sym, unsigned long offset, صحیح type, addr_t addend);

ST_INLN تهی sym_free(Sym *sym);
ST_FUNC Sym *sym_افزودن(صحیح v, CType *type, صحیح r, صحیح c);
ST_FUNC تهی sym_برداشت(Sym **ptop, Sym *b, صحیح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحیح v, صحیح t, صحیح c);
ST_FUNC Sym *sym_find2(Sym *s, صحیح v);
ST_INLN Sym *sym_find(صحیح v);
ST_FUNC Sym *label_find(صحیح v);
ST_FUNC Sym *label_افزودن(Sym **ptop, صحیح v, صحیح flags);
ST_FUNC تهی label_برداشت(Sym **ptop, Sym *slast, صحیح keep);
ST_INLN Sym *struct_find(صحیح v);

ST_FUNC Sym *global_identifier_افزودن(صحیح v, صحیح t, صحیح c);
ST_FUNC Sym *external_global_sym(صحیح v, CType *type);
ST_FUNC Sym *external_helper_sym(صحیح v);
ST_FUNC تهی vpush_helper_func(صحیح v);
ST_FUNC تهی vset(CType *type, صحیح r, صحیح v);
ST_FUNC تهی vset_VT_CMP(صحیح op);
ST_FUNC تهی vpushi(صحیح v);
ST_FUNC تهی vpushv(SValue *v);
ST_FUNC تهی vpushsym(CType *type, Sym *sym);
ST_FUNC تهی vswap(تهی);
ST_FUNC تهی vrott(صحیح n);
ST_FUNC تهی vrotb(صحیح n);
ST_FUNC تهی vrev(صحیح n);
ST_FUNC تهی vpop(تهی);
#اگر PTR_SIZE == 4
ST_FUNC تهی lexpand(تهی);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC صحیح get_reg_ex(صحیح rc, صحیح rc2);
#endif
ST_FUNC تهی save_reg(صحیح r);
ST_FUNC تهی save_reg_upstack(صحیح r, صحیح n);
ST_FUNC صحیح get_reg(صحیح rc);
ST_FUNC تهی save_regs(صحیح n);
ST_FUNC تهی gaddrof(تهی);
ST_FUNC صحیح gv(صحیح rc);
ST_FUNC تهی gv2(صحیح rc1, صحیح rc2);
ST_FUNC تهی gen_op(صحیح op);
ST_FUNC صحیح type_size(CType *type, صحیح *a);
ST_FUNC تهی mk_pointer(CType *type);
ST_FUNC تهی vstore(تهی);
ST_FUNC تهی inc(صحیح post, صحیح c);
ST_FUNC CString* parse_mult_str(ثابت نویسه *پیام);
ST_FUNC CString* parse_asm_str(تهی);
ST_FUNC تهی indir(تهی);
ST_FUNC تهی unary(تهی);
ST_FUNC تهی gexpr(تهی);
ST_FUNC صحیح عبارت_const(تهی);
#اگر defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#اگر defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC صحیح classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC تهی gbound_args(صحیح nb_args);
ST_DATA صحیح func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, صحیح c, صحیح byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_دودویی 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

تعریفنوع ساختار {
    unsigned صحیح n_strx;         /* index into string table of name */
    unsigned نویسه n_type;         /* type of symbol */
    unsigned نویسه n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned صحیح n_مقدار;        /* value of symbol */
} Stab_Sym;

ST_FUNC تهی tccelf_new(TCCState *s);
ST_FUNC تهی tccelf_delete(TCCState *s);
ST_FUNC تهی tccelf_begin_file(TCCState *s1);
ST_FUNC تهی tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت نویسه *name, صحیح sh_type, صحیح sh_flags);
ST_FUNC تهی section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, صحیح align);
ST_FUNC تهی *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, ثابت نویسه *name);
ST_FUNC تهی free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت نویسه *symtab_name, صحیح sh_type, صحیح sh_flags, ثابت نویسه *strtab_name, ثابت نویسه *hash_name, صحیح hash_sh_flags);
ST_FUNC تهی init_symtab(Section *s);

ST_FUNC صحیح put_elf_str(Section *s, ثابت نویسه *sym);
ST_FUNC صحیح put_elf_sym(Section *s, addr_t مقدار, unsigned long size, صحیح info, صحیح other, صحیح shndx, ثابت نویسه *name);
ST_FUNC صحیح set_elf_sym(Section *s, addr_t مقدار, unsigned long size, صحیح info, صحیح other, صحیح shndx, ثابت نویسه *name);
ST_FUNC صحیح find_elf_sym(Section *s, ثابت نویسه *name);
ST_FUNC تهی put_elf_reloc(Section *symtab, Section *s, unsigned long offset, صحیح type, صحیح نماد);
ST_FUNC تهی put_elf_reloca(Section *symtab, Section *s, unsigned long offset, صحیح type, صحیح نماد, addr_t addend);

ST_FUNC تهی resolve_common_syms(TCCState *s1);
ST_FUNC تهی relocate_syms(TCCState *s1, Section *symtab, صحیح do_resolve);
ST_FUNC تهی relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(صحیح fd, تهی *buf, size_t شمار_2);
ST_FUNC تهی *load_data(صحیح fd, unsigned long file_offset, unsigned long size);
ST_FUNC صحیح tcc_object_type(صحیح fd, ElfW(Ehdr) *h);
ST_FUNC صحیح tcc_load_object_file(TCCState *s1, صحیح fd, unsigned long file_offset);
ST_FUNC صحیح tcc_load_archive(TCCState *s1, صحیح fd, صحیح alacarte);
ST_FUNC تهی add_array(TCCState *s1, ثابت نویسه *sec, صحیح c);

ST_FUNC ساختار sym_attr *get_sym_attr(TCCState *s1, صحیح index, صحیح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت نویسه *name, صحیح err, صحیح forc);
ST_FUNC تهی list_elf_symbols(TCCState *s, تهی *ctx,
    تهی (*نماد_cb)(تهی *ctx, ثابت نویسه *name, ثابت تهی *val));
ST_FUNC صحیح set_global_sym(TCCState *s1, ثابت نویسه *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    برای (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC صحیح tcc_load_dll(TCCState *s1, صحیح fd, ثابت نویسه *filename, صحیح level);
ST_FUNC صحیح tcc_load_ldscript(TCCState *s1, صحیح fd);
ST_FUNC تهی tccelf_add_crtbegin(TCCState *s1);
ST_FUNC تهی tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC تهی tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC صحیح code_reloc (صحیح reloc_type);
ST_FUNC صحیح gotplt_entry_type (صحیح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
شمارش gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#اگر !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, ساختار sym_attr *attr);
ST_FUNC تهی relocate_plt(TCCState *s1);
ST_FUNC تهی build_got_entries(TCCState *s1, صحیح got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC تهی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, unsigned نویسه *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA ثابت نویسه * ثابت target_machine_defs;
ST_DATA ثابت صحیح reg_classes[NB_REGS];

ST_FUNC تهی gsym_addr(صحیح t, صحیح a);
ST_FUNC تهی gsym(صحیح t);
ST_FUNC تهی load(صحیح r, SValue *sv);
ST_FUNC تهی store(صحیح r, SValue *v);
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *align, صحیح *regsize);
ST_FUNC تهی gfunc_call(صحیح nb_args);
ST_FUNC تهی gfunc_prolog(Sym *func_sym);
ST_FUNC تهی gfunc_epilog(تهی);
ST_FUNC تهی gen_fill_nops(صحیح);
ST_FUNC صحیح gjmp(صحیح t);
ST_FUNC تهی gjmp_addr(صحیح a);
ST_FUNC صحیح gjmp_cond(صحیح op, صحیح t);
ST_FUNC صحیح gjmp_append(صحیح n, صحیح t);
ST_FUNC تهی gen_opi(صحیح op);
ST_FUNC تهی gen_opf(صحیح op);
ST_FUNC تهی gen_cvt_ftoi(صحیح t);
ST_FUNC تهی gen_cvt_itof(صحیح t);
ST_FUNC تهی gen_cvt_ftof(صحیح t);
ST_FUNC تهی ggoto(تهی);
#ifndef TCC_TARGET_C67
ST_FUNC تهی o(unsigned صحیح c);
#endif
ST_FUNC تهی gen_vla_sp_save(صحیح addr);
ST_FUNC تهی gen_vla_sp_restore(صحیح addr);
ST_FUNC تهی gen_vla_alloc(CType *type, صحیح align);

ایستا درونخطی uint16_t read16le(unsigned نویسه *p) {
    بازگشت p[0] | (uint16_t)p[1] << 8;
}
ایستا درونخطی تهی write16le(unsigned نویسه *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ایستا درونخطی uint32_t read32le(unsigned نویسه *p) {
  بازگشت read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ایستا درونخطی تهی write32le(unsigned نویسه *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ایستا درونخطی تهی add32le(unsigned نویسه *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ایستا درونخطی uint64_t read64le(unsigned نویسه *p) {
  بازگشت read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ایستا درونخطی تهی write64le(unsigned نویسه *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ایستا درونخطی تهی add64le(unsigned نویسه *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#اگر defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC تهی g(صحیح c);
ST_FUNC تهی gen_le16(صحیح c);
ST_FUNC تهی gen_le32(صحیح c);
#endif
#اگر defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC تهی gen_addr32(صحیح r, Sym *sym, صحیح c);
ST_FUNC تهی gen_addrpc32(صحیح r, Sym *sym, صحیح c);
ST_FUNC تهی gen_cvt_csti(صحیح t);
ST_FUNC تهی gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC تهی gen_opl(صحیح op);
#ifdef TCC_TARGET_PE
ST_FUNC تهی gen_vla_result(صحیح addr);
#endif
ST_FUNC تهی gen_cvt_sxtw(تهی);
ST_FUNC تهی gen_cvt_csti(صحیح t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#اگر defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت نویسه *default_elfinterp(ساختار TCCState *s);
#endif
ST_FUNC تهی arm_init(ساختار TCCState *s);
ST_FUNC تهی gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC تهی gen_opl(صحیح op);
ST_FUNC تهی gfunc_return(CType *func_type);
ST_FUNC تهی gen_va_start(تهی);
ST_FUNC تهی gen_va_arg(CType *t);
ST_FUNC تهی gen_clear_cache(تهی);
ST_FUNC تهی gen_cvt_sxtw(تهی);
ST_FUNC تهی gen_cvt_csti(صحیح t);
ST_FUNC تهی gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC تهی gen_opl(صحیح op);
ST_FUNC تهی gen_va_start(تهی);
ST_FUNC تهی arch_transfer_ret_regs(صحیح);
ST_FUNC تهی gen_cvt_sxtw(تهی);
ST_FUNC تهی gen_cvt_csti(صحیح t);
ST_FUNC تهی gen_increment_tcov (SValue *sv);
ST_FUNC تهی gen_clear_cache(تهی);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC صحیح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحیح tcc_load_coff(TCCState * s1, صحیح fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC تهی asm_instr(تهی);
ST_FUNC تهی asm_global_instr(تهی);
ST_FUNC صحیح tcc_assemble(TCCState *s1, صحیح do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC صحیح find_constraint(ASMOperand *operands, صحیح nb_operands, ثابت نویسه *name, ثابت نویسه **pp);
ST_FUNC Sym* get_asm_sym(صحیح name, Sym *csym);
ST_FUNC تهی asm_عبارت(TCCState *s1, عبارت_مقدار *pe);
ST_FUNC صحیح asm_int_عبارت(TCCState *s1);
#اگر PTR_SIZE == 8
ST_FUNC تهی gen_expr64(عبارت_مقدار *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC تهی gen_expr32(عبارت_مقدار *pe);
ST_FUNC تهی asm_opcode(TCCState *s1, صحیح opcode);
ST_FUNC صحیح asm_parse_regvar(صحیح t);
ST_FUNC تهی asm_compute_constraints(ASMOperand *operands, صحیح nb_operands, صحیح nb_outputs, ثابت uint8_t *clobber_regs, صحیح *pout_reg);
ST_FUNC تهی subst_asm_operand(CString *add_str, SValue *sv, صحیح modifier);
ST_FUNC تهی asm_gen_code(ASMOperand *operands, صحیح nb_operands, صحیح nb_outputs, صحیح is_output, uint8_t *clobber_regs, صحیح out_reg);
ST_FUNC تهی asm_clobber(uint8_t *clobber_regs, ثابت نویسه *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC صحیح pe_load_file(ساختار TCCState *s1, صحیح fd, ثابت نویسه *filename);
ST_FUNC صحیح pe_output_file(TCCState * s1, ثابت نویسه *filename);
ST_FUNC صحیح pe_putimport(TCCState *s1, صحیح dllindex, ثابت نویسه *name, addr_t مقدار);
ST_FUNC صحیح pe_setsubsy(TCCState *s1, ثابت نویسه *arg);
#اگر defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#اگر defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC تهی pe_add_unwind_data(unsigned start, unsigned end, unsigned پشته);
#endif
PUB_FUNC صحیح tcc_get_dllexports(ثابت نویسه *filename, نویسه **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC صحیح macho_output_file(TCCState * s1, ثابت نویسه *filename);
ST_FUNC صحیح macho_load_dll(TCCState *s1, صحیح fd, ثابت نویسه *filename, صحیح lev);
ST_FUNC صحیح macho_load_tbd(TCCState *s1, صحیح fd, ثابت نویسه *filename, صحیح lev);
#ifdef TCC_IS_NATIVE
ST_FUNC تهی tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC نویسه* macho_tbd_soname(صحیح fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    پوچ
/* dummy function for profiling */
ST_FUNC تهی *dlopen(ثابت نویسه *filename, صحیح flag);
ST_FUNC تهی dlclose(تهی *p);
ST_FUNC ثابت نویسه *dlerror(تهی);
ST_FUNC تهی *dlsym(تهی *handle, ثابت نویسه *نماد);
#endif
ST_FUNC تهی tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#اگر 0 /* included in tcc.c */
ST_FUNC صحیح tcc_tool_ar(TCCState *s, صحیح argc, نویسه **argv);
#ifdef TCC_TARGET_PE
ST_FUNC صحیح tcc_tool_impdef(TCCState *s, صحیح argc, نویسه **argv);
#endif
ST_FUNC صحیح tcc_tool_cross(TCCState *s, نویسه **argv, صحیح option);
ST_FUNC صحیح gen_makedeps(TCCState *s, ثابت نویسه *target, ثابت نویسه *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC تهی tcc_debug_new(TCCState *s);

ST_FUNC تهی tcc_debug_start(TCCState *s1);
ST_FUNC تهی tcc_debug_end(TCCState *s1);
ST_FUNC تهی tcc_debug_bincl(TCCState *s1);
ST_FUNC تهی tcc_debug_eincl(TCCState *s1);
ST_FUNC تهی tcc_debug_newfile(TCCState *s1);

ST_FUNC تهی tcc_debug_سطر(TCCState *s1);
ST_FUNC تهی tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC تهی tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC تهی tcc_debug_prolog_epilog(TCCState *s1, صحیح مقدار);
ST_FUNC تهی tcc_debug_funcend(TCCState *s1, صحیح size);
ST_FUNC تهی tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحیح sh_رقم, صحیح sym_bind, صحیح sym_type);
ST_FUNC تهی tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC تهی tcc_debug_stabn(TCCState *s1, صحیح type, صحیح مقدار);
ST_FUNC تهی tcc_debug_fix_forw(TCCState *s1, CType *t);

#اگر !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC تهی tcc_eh_frame_start(TCCState *s1);
ST_FUNC تهی tcc_eh_frame_end(TCCState *s1);
ST_FUNC تهی tcc_eh_frame_hdr(TCCState *s1, صحیح final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC تهی tcc_tcov_start(TCCState *s1);
ST_FUNC تهی tcc_tcov_end(TCCState *s1);
ST_FUNC تهی tcc_tcov_check_سطر(TCCState *s1, صحیح start);
ST_FUNC تهی tcc_tcov_block_end(TCCState *s1, صحیح سطر);
ST_FUNC تهی tcc_tcov_block_begin(TCCState *s1);
ST_FUNC تهی tcc_tcov_reset_ind(TCCState *s1);

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

#define DWARF_MAX_128	((8 * اندازه (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
ایستا درونخطی uint64_t
dwarf_read_uleb128(unsigned نویسه **ln, unsigned نویسه *end)
{
    unsigned نویسه *cp = *ln;
    uint64_t retval = 0;
    صحیح i;
    برای (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	اگر ((byte & 0x80) == 0)
	    بشکن;
    }
    *ln = cp;
    بازگشت retval;
}
ایستا درونخطی int64_t
dwarf_read_sleb128(unsigned نویسه **ln, unsigned نویسه *end)
{
    unsigned نویسه *cp = *ln;
    int64_t retval = 0;
    صحیح i;
    برای (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	اگر ((byte & 0x80) == 0) {
	    اگر ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    بشکن;
	}
    }
    *ln = cp;
    بازگشت retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#وگرنه
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#اگر defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#وگرنه
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#اگر CONFIG_TCC_SEMLOCK
#اگر defined _WIN32
تعریفنوع ساختار { فرار LONG init; CRITICAL_SECTION cs; } TCCSem;
ایستا درونخطی تهی wait_sem(TCCSem *p) {
    اگر (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } وگرنه {
        وقتی (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ایستا درونخطی تهی post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#وگرنهاگر defined __APPLE__
#شامل <dispatch/dispatch.h>
تعریفنوع ساختار { صحیح init; dispatch_semaphore_t sem; } TCCSem;
ایستا درونخطی تهی wait_sem(TCCSem *p) {
    اگر (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
ایستا درونخطی تهی post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#وگرنه
#شامل <semaphore.h>
تعریفنوع ساختار { صحیح init; sem_t sem; } TCCSem;
ایستا درونخطی تهی wait_sem(TCCSem *p) {
    اگر (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    وقتی (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ایستا درونخطی تهی post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#وگرنه
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#اگر ONE_SOURCE
#define ST_DATA ایستا
#وگرنه
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
#define total_سطرها         TCC_STATE_VAR(total_سطرها)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC تهی tcc_enter_state(TCCState *s1);
PUB_FUNC تهی tcc_exit_state(TCCState *s1);

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
#وگرنه
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
