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

#که_نه_تعریف_شوی _TCC_H
#تعریف_کړه _TCC_H

#تعریف_کړه GNU_سرچینه
#تعریف_کړه DARWIN_C_سرچینه
#ضمن "config.h"

#ضمن <stdarg.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#که_تعریف_شوی __TINYC__
# undef __attribute__
#د_که_پای
#ضمن <string.h>
#ضمن <errno.h>
#ضمن <math.h>
#ضمن <fcntl.h>
#ضمن <setjmp.h>
#ضمن <time.h>

#که_نه_تعریف_شوی _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
خارجي عائم strtof (ثابت حرف *__nptr, حرف **__endptr);
خارجي اوږد مزدوج strtold (ثابت حرف *__nptr, حرف **__endptr);
#د_که_پای

#که_تعریف_شوی _WIN32
# define WIN32_LEAN_AND_منځنۍ 1
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
#  define strtold (اوږد مزدوج)strtod
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
#د_که_پای

#که_نه_تعریف_شوی O_دوګونی_2
# define O_دوګونی_2 0
#د_که_پای

#که_نه_تعریف_شوی offsetof
#که_تعریف_شوی __clang__ // clang -fsanitize compains about: NULL+value
#تعریف_کړه offsetof(type, ډګر) __builtin_offsetof(type, ډګر)
#وإلا
#تعریف_کړه offsetof(type, ډګر) ((اندازه_t) &((type *)0)->ډګر)
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی countof
#تعریف_کړه countof(tab) (حجم(tab) / حجم((tab)[0]))
#د_که_پای

#که_تعریف_شوی _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#وإلا
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (چاپ_کړه, (x), (y))))
#د_که_پای

#که_تعریف_شوی _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#وإلا
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#د_که_پای

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
#إذا !defined(TCC_موخه_I386) && !defined(TCC_موخه_ARM) && \
    !defined(TCC_موخه_ARM64) && !defined(TCC_موخه_C67) && \
    !defined(TCC_موخه_X86_64) && !defined(TCC_موخه_RISCV64)
# إذا defined __x86_64__
#  define TCC_موخه_X86_64
# elif defined __arm__
#  define TCC_موخه_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_موخه_ARM64
# elif defined __riscv
#  define TCC_موخه_RISCV64
# وإلا
#  define TCC_موخه_I386
# endif
# ifdef _WIN32
#  define TCC_موخه_PE 1
# endif
# ifdef __APPLE__
#  define TCC_موخه_MACHO 1
# endif
#د_که_پای

/* only native compiler supports -run */
#إذا defined _WIN32 == defined TCC_موخه_PE \
    && defined __APPLE__ == defined TCC_موخه_MACHO
# إذا defined __i386__ && defined TCC_موخه_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_موخه_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_موخه_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_موخه_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_موخه_RISCV64
#  define TCC_IS_NATIVE
# endif
#د_که_پای

#إذا defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#وإلا
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#د_که_پای

#إذا defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#وإلا
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#د_که_پای

#إذا defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#وإلا
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#د_که_پای

#إذا defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وإلاإذا !(defined TCC_موخه_PE || defined TCC_موخه_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#د_که_پای

#إذا defined TCC_موخه_PE || defined TCC_موخه_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#وإلا
# define TCC_موخه_UNIX 1
#د_که_پای

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#إذا defined TCC_موخه_PE \
    || (defined TCC_موخه_MACHO && defined TCC_موخه_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#د_که_پای

#که_تعریف_شوی CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#د_که_پای

/* support using libtcc from threads */
#که_نه_تعریف_شوی CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#د_که_پای

/* ------------ path configuration ------------ */

#که_نه_تعریف_شوی CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#د_که_پای

#إذا !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#د_که_پای

#که_تعریف_شوی CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#وإلا
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#د_که_پای

/* path to find crt1.o, crti.o and crtn.o */
#که_نه_تعریف_شوی CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#د_که_پای

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#که_نه_تعریف_شوی CONFIG_TCC_SYSINCLUDEPATHS
# إذا defined TCC_موخه_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# وإلا
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#د_که_پای

/* library search paths */
#که_نه_تعریف_شوی CONFIG_TCC_LIBPATHS
# إذا defined TCC_موخه_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# وإلا
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#د_که_پای

/* name of ELF interpreter */
#که_نه_تعریف_شوی CONFIG_TCC_ELFINTERP
# إذا defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_موخه_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_موخه_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_موخه_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_موخه_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_موخه_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# وإلا
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#د_که_پای

/* (target specific) libtcc1.a */
#که_نه_تعریف_شوی TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#د_که_پای

/* <cross-prefix-to->libtcc1.a */
#که_نه_تعریف_شوی CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#د_که_پای

/* -------------------------------------------- */

#ضمن "libtcc.h"
#ضمن "elf.h"
#ضمن "stab.h"
#ضمن "dwarf.h"

/* -------------------------------------------- */

#که_نه_تعریف_شوی PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#د_که_پای

#که_نه_تعریف_شوی ONE_سرچینه
# define ONE_سرچینه 0
#د_که_پای

#إذا ONE_سرچینه
#تعریف_کړه ST_INLN ساكن مضمن
#تعریف_کړه ST_FUNC ساكن
#تعریف_کړه ST_معلومات ساكن
#وإلا
#تعریف_کړه ST_INLN
#تعریف_کړه ST_FUNC
#تعریف_کړه ST_معلومات خارجي
#د_که_پای

#که_تعریف_شوی TCC_PROFILE /* profile all functions */
# define ساكن
# define مضمن
#د_که_پای

/* -------------------------------------------- */
/* include the target specific definitions */

#تعریف_کړه موخه_DEFS_ONLY
#که_تعریف_شوی TCC_موخه_I386
# include "i386-gen.c"
# include "i386-link.c"
#وإلاإذا defined TCC_موخه_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#وإلاإذا defined TCC_موخه_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#وإلاإذا defined TCC_موخه_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#وإلاإذا defined TCC_موخه_C67
# define TCC_موخه_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#وإلاإذا defined(TCC_موخه_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#وإلا
#تېروتنه unknown موخه
#د_که_پای
#تعریف_لغوه موخه_DEFS_ONLY

/* -------------------------------------------- */

#إذا PTR_اندازه == 8
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
#د_که_پای
/* target address type */
#تعریف_کړه addr_t ElfW(Addr)
#تعریف_کړه ElfSym ElfW(Sym)

#إذا PTR_اندازه == 8 && !defined TCC_موخه_PE
# define LONG_اندازه 8
#وإلا
# define LONG_اندازه 4
#د_که_پای

/* -------------------------------------------- */

#تعریف_کړه INCLUDE_ډېری_اندازه  32
#تعریف_کړه IFDEF_ډېری_اندازه    64
#تعریف_کړه VSTACK_اندازه         512
#تعریف_کړه STRING_MAX_اندازه     1024
#تعریف_کړه TOKSTR_MAX_اندازه     256
#تعریف_کړه PACK_ډېری_اندازه     8

#تعریف_کړه TOK_HASH_اندازه       16384 /* must be a power of two */
#تعریف_کړه TOK_ALLOC_INCR      512  /* must be a power of two */
#تعریف_کړه TOK_MAX_اندازه        4 /* token max size in int unit when stored in string */

/* token symbol management */
تعريفنوع بنية TokenSym {
    بنية TokenSym *hash_بل;
    بنية Sym *sym_define; /* direct pointer to define */
    بنية Sym *sym_label; /* direct pointer to label */
    بنية Sym *sym_struct; /* direct pointer to structure */
    بنية Sym *sym_identifier; /* direct pointer to identifier */
    صحيح tok; /* token number */
    صحيح len;
    حرف str[1];
} TokenSym;

#که_تعریف_شوی TCC_موخه_PE
تعريفنوع بینښه لنډ nwchar_t;
#وإلا
تعريفنوع صحيح nwchar_t;
#د_که_پای

تعريفنوع بنية CString {
    صحيح اندازه; /* size in bytes */
    صحيح اندازه_allocated;
    حرف *معلومات; /* nwchar_t* in cases */
} CString;

/* type definition */
تعريفنوع بنية CType {
    صحيح t;
    بنية Sym *ref;
} CType;

/* long double words on host(!) platform */
#تعریف_کړه LDOUBLE_ټکي ((حجم(اوږد مزدوج)+3)/4)

/* constant value */
تعريفنوع اتحاد CValue {
    اوږد مزدوج ld;
    مزدوج d;
    عائم f;
    uint64_t i;
    بنية {
        حرف *معلومات;
        صحيح اندازه;
    } str;
    صحيح tab[LDOUBLE_ټکي];
} CValue;

/* value on stack */
تعريفنوع بنية SValue {
    CType type;      /* type */
    بینښه لنډ r;      /* register + flags */
    بینښه لنډ r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اتحاد {
      بنية { صحيح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اتحاد {
      بنية { بینښه لنډ cmp_op, cmp_r; }; /* VT_CMP operation */
      بنية Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
بنية SymAttr {
    بینښه لنډ
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
    بینښه
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_دلیلونه   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
تعريفنوع بنية Sym {
    صحيح v; /* symbol token */
    بینښه لنډ r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
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
        اوږد اوږد enum_val; /* enum constant if IS_ENUM_VAL */
        صحيح *d; /* define token stream */
        بنية Sym *cleanup_func;
    };

    CType type; /* associated type */
    اتحاد {
        بنية Sym *بل; /* next related symbol (for fields and anoms) */
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
    بینښه اوږد معلومات_دننه_واټن; /* current data offset */
    بینښه حرف *معلومات;       /* section data */
    بینښه اوږد معلومات_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحيح sh_name;             /* elf section name (only used during output) */
    صحيح sh_عدد;              /* elf section number */
    صحيح sh_type;             /* elf section type */
    صحيح sh_flags;            /* elf section flags */
    صحيح sh_info;             /* elf section info */
    صحيح sh_addralign;        /* elf section alignment */
    صحيح sh_entsize;          /* elf entry size */
    بینښه اوږد sh_اندازه;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    بینښه اوږد sh_دننه_واټن; /* file offset */
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
    بینښه حرف وموندل, شاخص;
    حرف name[1];
} DLLReference;

/* -------------------------------------------------- */

#تعریف_کړه SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#تعریف_کړه SYM_ډګر      0x20000000 /* struct/union field symbol space */
#تعریف_کړه SYM_لومړی_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#تعریف_کړه FUNC_NEW       1 /* ansi function prototype */
#تعریف_کړه FUNC_OLD       2 /* old function prototype */
#تعریف_کړه FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#تعریف_کړه FUNC_CDECL     0 /* standard c call */
#تعریف_کړه FUNC_STDCALL   1 /* pascal c call */
#تعریف_کړه FUNC_FASTCALL1 2 /* first param in %eax */
#تعریف_کړه FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#تعریف_کړه FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#تعریف_کړه FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#تعریف_کړه FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#تعریف_کړه MACRO_OBJ      0 /* object like macro */
#تعریف_کړه MACRO_FUNC     1 /* function like macro */
#تعریف_کړه MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#تعریف_کړه LABEL_DEFINED  0 /* label is defined */
#تعریف_کړه LABEL_FORWARD  1 /* label is forward defined */
#تعریف_کړه LABEL_DECLARED 2 /* label is declared but never used */
#تعریف_کړه LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#تعریف_کړه TYPE_ABSTRACT  1 /* type without variable */
#تعریف_کړه TYPE_مستقیم    2 /* type with variable */
#تعریف_کړه TYPE_PARAM     4 /* type declares function parameter */
#تعریف_کړه TYPE_NEST      8 /* nested call to post_type */

#تعریف_کړه IO_BUF_اندازه 8192

تعريفنوع بنية BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_پای_ټکی;
    صحيح fd;
    بنية BufferedFile *prev;
    صحيح کرښه_عدد;    /* current line number - here to simplify code */
    صحيح کرښه_ref;    /* tcc -E: last printed line */
    صحيح ifndef_macro;  /* #ifndef macro / #endif search */
    صحيح ifndef_macro_saved; /* saved ifndef_macro */
    صحيح *ifdef_ډېری_ptr; /* ifdef_stack value at the start of the file */
    صحيح include_بل_شاخص; /* next search path */
    صحيح prev_tok_flags; /* saved tok_flags */
    حرف filename[1024];    /* filename */
    حرف *true_filename; /* filename not modified by # line directive */
    بینښه حرف unget[4];
    بینښه حرف بفر[1]; /* extra size for CH_EOB char */
} BufferedFile;

#تعریف_کړه CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#تعریف_کړه CH_EOF   (-1)   /* end of file */

/* used to record tokens */
تعريفنوع بنية TokenString {
    صحيح *str;
    صحيح len;
    صحيح need_spc;
    صحيح allocated_len;
    صحيح وروستی_کرښه_عدد;
    صحيح save_کرښه_عدد;
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
    صحيح alias_موخه; /* token */
    صحيح asm_label; /* associated asm label */
    حرف attr_ډېرپېښ; /* __attribute__((__mode__(...))) */
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
    صحيح hash_بل; /* -1 if none */
    حرف filename[1]; /* path specified in #include */
} CachedInclude;

#تعریف_کړه CACHED_INCLUDES_HASH_اندازه 32

#که_تعریف_شوی CONFIG_TCC_ASM
تعريفنوع بنية بیان_ارزښت {
    uint64_t v;
    Sym *sym;
    صحيح pcrel;
} بیان_ارزښت;

#تعریف_کړه MAX_ASM_OPERANDS 30
تعريفنوع بنية ASMOperand {
    صحيح id; /* GCC 3 optional identifier (0 if number only supported) */
    حرف constraint[16];
    حرف asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحيح ref_شاخص; /* if >= 0, gives reference to a output constraint */
    صحيح ننوت_شاخص; /* if >= 0, gives reference to an input constraint */
    صحيح لومړیتوب; /* priority, used to assign registers */
    صحيح reg; /* if >= 0, register number used for this operand */
    صحيح is_llong; /* true if double register value */
    صحيح is_حافظه; /* true if memory operand */
    صحيح is_rw;     /* for '+' modifier */
    صحيح is_label;  /* for asm goto */
} ASMOperand;
#د_که_پای

/* extra symbol attributes (not in symbol table) */
بنية sym_attr {
    بینښه got_دننه_واټن;
    بینښه plt_دننه_واټن;
    صحيح plt_sym;
    صحيح dyn_شاخص;
    بینښه حرف linker_sym:1;
#که_تعریف_شوی TCC_موخه_ARM
    بینښه حرف plt_thumb_stub:1;
#د_که_پای
};

بنية TCCState {
    بینښه حرف verbose; /* if true, display some information during compilation */
    بینښه حرف nostdinc; /* if true, no standard headers are added */
    بینښه حرف nostdlib; /* if true, no standard libraries are added */
    بینښه حرف nostdlib_paths; /* if true, the default paths are not searched for libraries */
    بینښه حرف nocommon; /* if true, do not use common symbols for .bss data */
    بینښه حرف static_link; /* if true, static linking is performed */
    بینښه حرف rdynamic; /* if true, all symbols are exported */
    بینښه حرف symbolic; /* if true, resolve symbols in the current module first */
    بینښه حرف znodelete; /* Set DF_1_NODELETE in dynamic section */
    بینښه حرف filetype; /* file type for compilation (NONE,C,ASM) */
    بینښه حرف optimize; /* only to #define __OPTIMIZE__ */
    بینښه حرف option_pthread; /* -pthread option */
    بینښه حرف enable_new_dtags; /* -Wl,--enable-new-dtags */
    بینښه صحيح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    بینښه حرف char_is_unsigned;
    بینښه حرف leading_underscore;
    بینښه حرف ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    بینښه حرف dollars_دننه_identifiers;  /* allows '$' char in identifiers */
    بینښه حرف ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    بینښه حرف سرچپه_funcargs; /* if true, evaluate last function arg first */
    بینښه حرف gnu89_inline; /* treat 'extern inline' like 'static inline' */
    بینښه حرف unwind_tables; /* create eh_frame section */

    /* warning switches */
    بینښه حرف warn_none;
    بینښه حرف warn_all;
    بینښه حرف warn_error;
    بینښه حرف warn_write_مزي_ګانې;
    بینښه حرف warn_unsupported;
    بینښه حرف warn_implicit_function_declaration;
    بینښه حرف warn_discarded_qualifiers;
    #تعریف_کړه WARN_ON  1 /* warning is on (-Woption) */
    بینښه حرف warn_عدد; /* temp var for tcc_warning_c() */

    بینښه حرف option_r; /* option -r */
    بینښه حرف do_bench; /* option -bench */
    بینښه حرف just_deps; /* option -M  */
    بینښه حرف gen_deps; /* option -MD  */
    بینښه حرف include_sys_deps; /* option -MD  */
    بینښه حرف gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    بینښه حرف do_debug;
    بینښه حرف dwarf;
    بینښه حرف do_backtrace;
#که_تعریف_شوی CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    بینښه حرف do_bounds_check;
#د_که_پای
    بینښه حرف test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    بینښه حرف gnu_ext;
    /* use TinyCC extensions */
    بینښه حرف tcc_ext;

    بینښه حرف dflag; /* -dX value */
    بینښه حرف Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#که_تعریف_شوی TCC_موخه_X86_64
    بینښه حرف nosse; /* For -mno-sse support. */
#د_که_پای
#که_تعریف_شوی TCC_موخه_ARM
    بینښه حرف float_abi; /* float ABI of the generated code*/
#د_که_پای

    بینښه حرف has_متن_addr;
    addr_t متن_addr; /* address of text section */
    بینښه section_align; /* section alignment */
#که_تعریف_شوی TCC_موخه_I386
    صحيح seg_اندازه; /* 32. Can be 16 with i386 assembler (.code16) */
#د_که_پای

    حرف *tcc_lib_لار; /* CONFIG_TCCDIR or -B option */
    حرف *soname; /* as specified on the command line (-soname) */
    حرف *rpath; /* as specified on the command line (-Wl,-rpath=) */
    حرف *elfint; /* -Wl,-I... on command line */
    حرف *elf_entryname; /* "_start" unless set */
    حرف *init_نښه; /* symbols to call at load-time (not used currently) */
    حرف *fini_نښه; /* symbols to call at unload-time (not used currently) */
    حرف *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحيح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحيح output_format;
    /* nth test to run with -dt -run */
    صحيح پرلپسې_test;

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
    فراغ (*error_func)(فراغ *opaque, ثابت حرف *پیغام);
    صحيح error_سېټ_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحيح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    حرف **موخه_deps;
    صحيح nb_موخه_deps;

    /* compilation */
    BufferedFile *include_ډېری[INCLUDE_ډېری_اندازه];
    BufferedFile **include_ډېری_ptr;

    صحيح ifdef_ډېری[IFDEF_ډېری_اندازه];
    صحيح *ifdef_ډېری_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحيح cached_includes_hash[CACHED_INCLUDES_HASH_اندازه];
    CachedInclude **cached_includes;
    صحيح nb_cached_includes;

    /* #pragma pack stack */
    صحيح pack_ډېری[PACK_ډېری_اندازه];
    صحيح *pack_ډېری_ptr;
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
    Section *متن_section, *معلومات_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_متن_section; /* current section where function code is generated */
#که_تعریف_شوی CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#د_که_پای
    /* symbol section */
    اتحاد { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_چوکاټ_section;
    Section *eh_چوکاټ_hdr_section;
    بینښه اوږد eh_پیل;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_کرښه_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_کرښه_str_section;
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
    #تعریف_کړه qrel s1->qrel

    addr_t tls_پیل, tls_پای_ټکی;

#که_تعریف_شوی TCC_موخه_RISCV64
    بنية pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحيح nb_pcrel_hi_entries;
#د_که_پای

#که_تعریف_شوی TCC_موخه_PE
    /* PE info */
    صحيح pe_subsystem;
    بینښه pe_characteristics;
    بینښه pe_dll_characteristics;
    بینښه pe_file_align;
    بینښه pe_ډېری_اندازه;
    addr_t pe_imagebase;
# إذا defined(TCC_موخه_X86_64) || defined(TCC_موخه_ARM64)
    Section *uw_pdata;
    صحيح uw_sym;
    صحيح uw_xsym;
    بینښه uw_offs;
# endif
#د_که_پای

#إذا defined TCC_موخه_MACHO
    حرف *install_name;
    uint32_t compatibility_نسخه;
    uint32_t current_نسخه;
#د_که_پای

#که_نه_تعریف_شوی ELF_OBJ_ONLY
    صحيح nb_sym_versions;
    بنية sym_نسخه *sym_versions;
    صحيح nb_sym_منزل_نسخه;
    صحيح *sym_منزل_نسخه;
    صحيح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#د_که_پای

#که_تعریف_شوی TCC_IS_NATIVE
    ثابت حرف *پرلپسې_main; /* entry for tcc_run() */
    فراغ *پرلپسې_ptr; /* runtime_memory */
    بینښه پرلپسې_اندازه; /* size of runtime_memory  */
    ثابت حرف *پرلپسې_stdin; /* custom stdin file for run_main */
#که_تعریف_شوی _WIN64
    فراغ *پرلپسې_function_جدول; /* unwind data */
#د_که_پای
    بنية TCCState *بل;
    بنية rt_context *rc; /* pointer to backtrace info block */
    فراغ *پرلپسې_lj, *پرلپسې_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    فراغ *bt_معلومات;
#د_که_پای

#که_تعریف_شوی CONFIG_TCC_BACKTRACE
    صحيح rt_عدد_callers;
#د_که_پای

    /* benchmark info */
    صحيح ټول_idents;
    صحيح ټول_کرښې;
    بینښه صحيح ټول_بایټونه;
    بینښه صحيح ټول_output[4];

    /* used by tcc_load_ldscript */
    بینښه حرف *ld_p; /* text pointer */

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
#تعریف_کړه VT_VALMASK   0x003f  /* mask for value location, register or: */
#تعریف_کړه VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#تعریف_کړه VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#تعریف_کړه VT_LOCAL     0x0032  /* offset on stack */
#تعریف_کړه VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#تعریف_کړه VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#تعریف_کړه VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#تعریف_کړه VT_LVAL      0x0100  /* var is an lvalue */
#تعریف_کړه VT_SYM       0x0200  /* a symbol value is added */
#تعریف_کړه VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#تعریف_کړه VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#تعریف_کړه VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#تعریف_کړه VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#تعریف_کړه VT_BTYPE       0x000f  /* mask for basic type */
#تعریف_کړه VT_VOID             0  /* void type */
#تعریف_کړه VT_BYTE             1  /* signed byte type */
#تعریف_کړه VT_SHORT            2  /* short type */
#تعریف_کړه VT_INT              3  /* integer type */
#تعریف_کړه VT_LLONG            4  /* 64 bit integer */
#تعریف_کړه VT_PTR              5  /*اشاره_ګر*/
#تعریف_کړه VT_FUNC             6  /* function type */
#تعریف_کړه VT_STRUCT           7  /* struct/union definition */
#تعریف_کړه VT_FLOAT            8  /* IEEE float */
#تعریف_کړه VT_DOUBLE           9  /* IEEE double */
#تعریف_کړه VT_LDOUBLE         10  /* IEEE long double */
#تعریف_کړه VT_BOOL            11  /* ISOC99 boolean type */
#تعریف_کړه VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#تعریف_کړه VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#تعریف_کړه VT_UNSIGNED    0x0010  /* unsigned type */
#تعریف_کړه VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#تعریف_کړه VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#تعریف_کړه VT_BITFIELD    0x0080  /* bitfield modifier */
#تعریف_کړه VT_CONSTANT    0x0100  /* const modifier */
#تعریف_کړه VT_VOLATILE    0x0200  /* volatile modifier */
#تعریف_کړه VT_RESTRICT    0x0400  /* restrict modifier */
#تعریف_کړه VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#تعریف_کړه VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#تعریف_کړه VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#تعریف_کړه VT_EXTERN  0x00002000  /* extern definition */
#تعریف_کړه VT_STATIC  0x00004000  /* static variable */
#تعریف_کړه VT_TYPEDEF 0x00008000  /* typedef definition */
#تعریف_کړه VT_INLINE  0x00010000  /* inline definition */
#تعریف_کړه VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#تعریف_کړه VT_STRUCT_ښويدنه 20     /* shift for bitfield shift values (32 - 2*6) */
#تعریف_کړه VT_STRUCT_ماسک (((1U << (6+6)) - 1) << VT_STRUCT_ښويدنه | VT_BITFIELD)
#تعریف_کړه بټ_POS(t) (((t) >> VT_STRUCT_ښويدنه) & 0x3f)
#تعریف_کړه بټ_اندازه(t) (((t) >> (VT_STRUCT_ښويدنه + 6)) & 0x3f)

#تعریف_کړه VT_UNION    (1 << VT_STRUCT_ښويدنه | VT_STRUCT)
#تعریف_کړه VT_ENUM     (2 << VT_STRUCT_ښويدنه) /* integral type is an enum really */
#تعریف_کړه VT_ENUM_VAL (3 << VT_STRUCT_ښويدنه) /* integral type is an enum constant really */

#تعریف_کړه IS_ENUM(t) ((t & VT_STRUCT_ماسک) == VT_ENUM)
#تعریف_کړه IS_ENUM_VAL(t) ((t & VT_STRUCT_ماسک) == VT_ENUM_VAL)
#تعریف_کړه IS_UNION(t) ((t & (VT_STRUCT_ماسک|VT_BTYPE)) == VT_UNION)

#تعریف_کړه VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#تعریف_کړه VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#تعریف_کړه VT_TYPE (~(VT_STORAGE|VT_STRUCT_ماسک))

/* symbol was created by tccasm.c first */
#تعریف_کړه VT_ASM (VT_VOID | 4 << VT_STRUCT_ښويدنه)
#تعریف_کړه VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_ښويدنه)
#تعریف_کړه IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_ماسک) & ~(1<<VT_STRUCT_ښويدنه))) == VT_ASM)
#تعریف_کړه IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_ماسک)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#تعریف_کړه VT_BT_ARRAY (6 << VT_STRUCT_ښويدنه)
#تعریف_کړه IS_BT_ARRAY(t) ((t & VT_STRUCT_ماسک) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#تعریف_کړه BFVAL(M,N) ((بینښه)((M) & ~((M) << 1)) * (N))
#تعریف_کړه BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#تعریف_کړه BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#تعریف_کړه TOK_LAND  0x90
#تعریف_کړه TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#تعریف_کړه TOK_ULT 0x92
#تعریف_کړه TOK_UGE 0x93
#تعریف_کړه TOK_EQ  0x94
#تعریف_کړه TOK_NE  0x95
#تعریف_کړه TOK_ULE 0x96
#تعریف_کړه TOK_UGT 0x97
#تعریف_کړه TOK_Nset 0x98
#تعریف_کړه TOK_Nclear 0x99
#تعریف_کړه TOK_LT  0x9c
#تعریف_کړه TOK_GE  0x9d
#تعریف_کړه TOK_LE  0x9e
#تعریف_کړه TOK_GT  0x9f

#تعریف_کړه TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#تعریف_کړه TOK_DEC     0x80 /* -- */
#تعریف_کړه TOK_MID     0x81 /* inc/dec, to void constant */
#تعریف_کړه TOK_INC     0x82 /* ++ */
#تعریف_کړه TOK_UDIV    0x83 /* unsigned division */
#تعریف_کړه TOK_UMOD    0x84 /* unsigned modulo */
#تعریف_کړه TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#تعریف_کړه TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#تعریف_کړه TOK_ADDC1   0x87 /* add with carry generation */
#تعریف_کړه TOK_ADDC2   0x88 /* add with carry use */
#تعریف_کړه TOK_SUBC1   0x89 /* add with carry generation */
#تعریف_کړه TOK_SUBC2   0x8a /* add with carry use */
#تعریف_کړه TOK_SHL     '<' /* shift left */
#تعریف_کړه TOK_SAR     '>' /* signed shift right */
#تعریف_کړه TOK_SHR     0x8b /* unsigned shift right */
#تعریف_کړه TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#تعریف_کړه TOK_ARROW   0xa0 /* -> */
#تعریف_کړه TOK_DOTS    0xa1 /* three dots */
#تعریف_کړه TOK_TWODOTS 0xa2 /* C++ token ? */
#تعریف_کړه TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#تعریف_کړه TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#تعریف_کړه TOK_PPJOIN  (TOK_TWOSHARPS | SYM_ډګر) /* A '##' in a macro to mean pasting */
#تعریف_کړه TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#تعریف_کړه TOK_A_جمع_کړه   0xb0
#تعریف_کړه TOK_A_SUB   0xb1
#تعریف_کړه TOK_A_MUL   0xb2
#تعریف_کړه TOK_A_DIV   0xb3
#تعریف_کړه TOK_A_MOD   0xb4
#تعریف_کړه TOK_A_AND   0xb5
#تعریف_کړه TOK_A_OR    0xb6
#تعریف_کړه TOK_A_XOR   0xb7
#تعریف_کړه TOK_A_SHL   0xb8
#تعریف_کړه TOK_A_SAR   0xb9

#تعریف_کړه TOK_ټاکل(t) (t >= TOK_A_جمع_کړه && t <= TOK_A_SAR)
#تعریف_کړه TOK_ټاکل_OP(t) ("+-*/%&|^<>"[t - TOK_A_جمع_کړه])

/* tokens that carry values (in additional token string space / tokc) --> */
#تعریف_کړه TOK_CCHAR   0xc0 /* char constant in tokc */
#تعریف_کړه TOK_LCHAR   0xc1
#تعریف_کړه TOK_CINT    0xc2 /* number in tokc */
#تعریف_کړه TOK_CUINT   0xc3 /* unsigned int constant */
#تعریف_کړه TOK_CLLONG  0xc4 /* long long constant */
#تعریف_کړه TOK_CULLONG 0xc5 /* unsigned long long constant */
#تعریف_کړه TOK_CLONG   0xc6 /* long constant */
#تعریف_کړه TOK_CULONG  0xc7 /* unsigned long constant */
#تعریف_کړه TOK_STR     0xc8 /* pointer to string in tokc */
#تعریف_کړه TOK_LSTR    0xc9
#تعریف_کړه TOK_CFLOAT  0xca /* float constant */
#تعریف_کړه TOK_CDOUBLE 0xcb /* double constant */
#تعریف_کړه TOK_CLDOUBLE 0xcc /* long double constant */
#تعریف_کړه TOK_PPNUM   0xcd /* preprocessor number */
#تعریف_کړه TOK_PPSTR   0xce /* preprocessor string */
#تعریف_کړه TOK_LINENUM 0xcf /* line number info */

#تعریف_کړه TOK_HAS_ارزښت(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#تعریف_کړه TOK_EOF       (-1)  /* end of file */
#تعریف_کړه TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#تعریف_کړه TOK_IDENT 256

تعداد tcc_token {
    TOK_وروستی = TOK_IDENT - 1
#تعریف_کړه DEF(id, str) ,id
#ضمن "tcctok.h"
#تعریف_لغوه DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#تعریف_کړه TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_معلومات بنية TCCState *tcc_state;
ST_معلومات فراغ** stk_معلومات;
ST_معلومات صحيح nb_stk_معلومات;
ST_معلومات صحيح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC حرف *pstrcpy(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s);
ST_FUNC حرف *pstrcat(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s);
ST_FUNC حرف *pstrncpy(حرف *بهر, اندازه_t buf_اندازه, ثابت حرف *s, اندازه_t عدد);
PUB_FUNC حرف *tcc_basename(ثابت حرف *name);
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC فراغ tcc_free(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc(بینښه اوږد اندازه);
PUB_FUNC فراغ *tcc_mallocz(بینښه اوږد اندازه);
PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, بینښه اوږد اندازه);
PUB_FUNC حرف *tcc_strdup(ثابت حرف *str);

#که_تعریف_شوی MEM_DEBUG
#تعریف_کړه tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کړه tcc_malloc(اندازه)        tcc_malloc_debug(اندازه, __FILE__, __LINE__)
#تعریف_کړه tcc_mallocz(اندازه)       tcc_mallocz_debug(اندازه, __FILE__, __LINE__)
#تعریف_کړه tcc_realloc(ptr,اندازه)   tcc_realloc_debug(ptr, اندازه, __FILE__, __LINE__)
#تعریف_کړه tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC فراغ tcc_free_debug(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc_debug(بینښه اوږد اندازه, ثابت حرف *file, صحيح کرښه);
PUB_FUNC فراغ *tcc_mallocz_debug(بینښه اوږد اندازه, ثابت حرف *file, صحيح کرښه);
PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, بینښه اوږد اندازه, ثابت حرف *file, صحيح کرښه);
PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح کرښه);
#د_که_پای

ST_FUNC فراغ libc_free(فراغ *ptr);
/* defined to be not used */
#تعریف_کړه حرر(p) use_tcc_free(p)
#تعریف_کړه حافظه_ورکړه(s) use_tcc_malloc(s)
#تعریف_کړه realloc(p, s) use_tcc_realloc(p, s)
#تعریف_لغوه strdup
#تعریف_کړه strdup(s) use_tcc_strdup(s)
PUB_FUNC صحيح _tcc_error_noabort(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN فراغ _tcc_error(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC فراغ _tcc_warning(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
#تعریف_کړه tcc_دننی_error(پیغام) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,پیغام)

/* other utilities */
ST_FUNC فراغ dynarray_جمع_کړه(فراغ *ptab, صحيح *nb_ptr, فراغ *معلومات);
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
#تعریف_کړه stk_ټېل(p) dynarray_جمع_کړه(&stk_معلومات, &nb_stk_معلومات, p)
#تعریف_کړه stk_راوباسه() (--nb_stk_معلومات)
/* mark CString on stack for cleanup errors */
#تعریف_کړه cstr_new_s(cstr) (cstr_new(cstr), stk_ټېل(&(cstr)->معلومات))
#تعریف_کړه cstr_free_s(cstr) (cstr_free(cstr), stk_راوباسه())

ST_FUNC صحيح tcc_جمع_کړه_file_دننی(TCCState *s1, ثابت حرف *filename, صحيح flags);
/* flags: */
#تعریف_کړه AFF_PRINT_ERROR     0x10 /* print error if file not found */
#تعریف_کړه AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#تعریف_کړه AFF_TYPE_BIN        0x40 /* file to add is binary */
#تعریف_کړه AFF_ټولیز_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#تعریف_کړه AFF_TYPE_NONE   0
#تعریف_کړه AFF_TYPE_C      1
#تعریف_کړه AFF_TYPE_ASM    2
#تعریف_کړه AFF_TYPE_ASMPP  4
#تعریف_کړه AFF_TYPE_LIB    8
#تعریف_کړه AFF_TYPE_ماسک   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#تعریف_کړه AFF_BINTYPE_REL 1
#تعریف_کړه AFF_BINTYPE_DYN 2
#تعریف_کړه AFF_BINTYPE_AR  3
#تعریف_کړه AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#تعریف_کړه FILE_NOT_وموندل -2
#تعریف_کړه FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#که_نه_تعریف_شوی ELF_OBJ_ONLY
ST_FUNC صحيح tcc_جمع_کړه_crt(TCCState *s, ثابت حرف *filename);
#د_که_پای
ST_FUNC صحيح tcc_جمع_کړه_dll(TCCState *s, ثابت حرف *filename, صحيح flags);
ST_FUNC صحيح tcc_جمع_کړه_support(TCCState *s1, ثابت حرف *filename);
#که_تعریف_شوی CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_جمع_کړه_bcheck(TCCState *s1);
#د_که_پای
#که_تعریف_شوی CONFIG_TCC_BACKTRACE
ST_FUNC فراغ tcc_جمع_کړه_btstub(TCCState *s1);
#د_که_پای
ST_FUNC فراغ tcc_جمع_کړه_pragma_libs(TCCState *s1);
PUB_FUNC صحيح tcc_جمع_کړه_library_err(TCCState *s, ثابت حرف *f);
PUB_FUNC فراغ tcc_print_stats(TCCState *s, بینښه ټول_وخت);
PUB_FUNC صحيح tcc_parse_دلیلونه(TCCState *s, صحيح *argc, حرف ***argv);
#که_تعریف_شوی _WIN32
ST_FUNC حرف *normalize_slashes(حرف *لار);
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m);
PUB_FUNC صحيح tcc_fclose(FILE *f);
#وإلا
# define tcc_fopen fopen
# define tcc_fclose fclose
#د_که_پای
ST_FUNC DLLReference *tcc_جمع_کړه_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level);
ST_FUNC حرف *tcc_بارول_متن(صحيح fd);
/* for #pragma once */
ST_FUNC صحيح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2);

/* tcc_parse_args return codes: */
#تعریف_کړه OPT_HELP 1
#تعریف_کړه OPT_HELP2 2
#تعریف_کړه OPT_V 3
#تعریف_کړه OPT_PRINT_DIRS 4
#تعریف_کړه OPT_AR 5
#تعریف_کړه OPT_IMPDEF 6
#تعریف_کړه OPT_M32 32
#تعریف_کړه OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_معلومات بنية BufferedFile *file;
ST_معلومات صحيح tok;
ST_معلومات CValue tokc;
ST_معلومات ثابت صحيح *macro_ptr;
ST_معلومات صحيح parse_flags;
ST_معلومات صحيح tok_flags;
ST_معلومات CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_معلومات صحيح tok_ident;
ST_معلومات TokenSym **جدول_ident;
ST_معلومات صحيح pp_بیان;

#تعریف_کړه TOK_FLAG_BOL   0x0001 /* beginning of line before */
#تعریف_کړه TOK_FLAG_BOF   0x0002 /* beginning of file before */
#تعریف_کړه TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#تعریف_کړه PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#تعریف_کړه PARSE_FLAG_TOK_عدد    0x0002 /* return numbers instead of TOK_PPNUM */
#تعریف_کړه PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#تعریف_کړه PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#تعریف_کړه PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#تعریف_کړه PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#تعریف_کړه PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#تعریف_کړه IS_SPC 1
#تعریف_کړه IS_ID  2
#تعریف_کړه IS_عدد 4

تعداد کرښه_macro_output_format {
    کرښه_MACRO_OUTPUT_FORMAT_GCC,
    کرښه_MACRO_OUTPUT_FORMAT_NONE,
    کرښه_MACRO_OUTPUT_FORMAT_STD,
    کرښه_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحيح len);
ST_FUNC صحيح tok_alloc_const(ثابت حرف *str);
ST_FUNC ثابت حرف *get_tok_str(صحيح v, CValue *cv);
ST_FUNC فراغ begin_macro(TokenString *str, صحيح alloc);
ST_FUNC فراغ پای_ټکی_macro(فراغ);
ST_FUNC صحيح سېټ_idnum(صحيح c, صحيح val);
ST_INLN فراغ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(فراغ);
ST_FUNC فراغ tok_str_free(TokenString *s);
ST_FUNC فراغ tok_str_free_str(صحيح *str);
ST_FUNC فراغ tok_str_جمع_کړه(TokenString *s, صحيح t);
ST_FUNC فراغ tok_str_جمع_کړه_tok(TokenString *s);
ST_INLN فراغ define_ټېل(صحيح v, صحيح macro_type, صحيح *str, Sym *لومړی_arg);
ST_FUNC فراغ define_undef(Sym *s);
ST_INLN Sym *define_پیدا_کړه(صحيح v);
ST_FUNC فراغ free_تعریفوي(Sym *b);
ST_FUNC فراغ parse_define(فراغ);
ST_FUNC فراغ skip_منزل_eol(صحيح warn);
ST_FUNC فراغ preprocess(صحيح is_bof);
ST_FUNC فراغ بل(فراغ);
ST_INLN فراغ unget_tok(صحيح وروستی_tok);
ST_FUNC فراغ preprocess_پیل(TCCState *s1, صحيح filetype);
ST_FUNC فراغ preprocess_پای_ټکی(TCCState *s1);
ST_FUNC فراغ tccpp_new(TCCState *s);
ST_FUNC فراغ tccpp_delete(TCCState *s);
ST_FUNC فراغ tccpp_putfile(ثابت حرف *filename);
ST_FUNC صحيح tcc_preprocess(TCCState *s1);
ST_FUNC فراغ skip(صحيح c);
ST_FUNC NORETURN فراغ expect(ثابت حرف *پیغام);
ST_FUNC فراغ pp_error(CString *cs);


/* space excluding newline */
ساكن مضمن صحيح is_space(صحيح ch) {
    أرجع ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ساكن مضمن صحيح isid(صحيح c) {
    أرجع (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ساكن مضمن صحيح isnum(صحيح c) {
    أرجع c >= '0' && c <= '9';
}
ساكن مضمن صحيح isoct(صحيح c) {
    أرجع c >= '0' && c <= '7';
}
ساكن مضمن صحيح toup(صحيح c) {
    أرجع (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#تعریف_کړه SYM_POOL_NB (8192 / حجم(Sym))

ST_معلومات Sym *global_ډېری;
ST_معلومات Sym *local_ډېری;
ST_معلومات Sym *local_label_ډېری;
ST_معلومات Sym *global_label_ډېری;
ST_معلومات Sym *define_ډېری;
ST_معلومات CType int_type, func_old_type, char_اشاره_ګر_type;
ST_معلومات SValue *vtop;
ST_معلومات صحيح rsym, anon_sym, ind, loc;
ST_معلومات حرف debug_modes;

ST_معلومات صحيح nocode_wanted; /* true if no code generation wanted for an expression */
ST_معلومات صحيح global_بیان;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_معلومات CType func_vt; /* current function return type (used by return instruction) */
ST_معلومات صحيح func_var; /* true if current function is variadic */
ST_معلومات صحيح func_vc; /* stack address for implicit struct return storage */
ST_معلومات صحيح func_ind; /* function start address */
ST_معلومات ثابت حرف *funcname;

ST_FUNC فراغ tccgen_init(TCCState *s1);
ST_FUNC صحيح tccgen_compile(TCCState *s1);
ST_FUNC فراغ tccgen_پای(TCCState *s1);
ST_FUNC فراغ check_vstack(فراغ);

ST_INLN صحيح is_float(صحيح t);
ST_FUNC صحيح ieee_finite(مزدوج d);
ST_FUNC صحيح exact_log2p1(صحيح i);
ST_FUNC فراغ test_lvalue(فراغ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC فراغ update_storage(Sym *sym);
ST_FUNC فراغ put_extern_sym2(Sym *sym, صحيح sh_عدد, addr_t ارزښت, بینښه اوږد اندازه, صحيح can_جمع_کړه_underscore);
ST_FUNC فراغ put_extern_sym(Sym *sym, Section *section, addr_t ارزښت, بینښه اوږد اندازه);
#إذا PTR_اندازه == 4
ST_FUNC فراغ greloc(Section *s, Sym *sym, بینښه اوږد دننه_واټن, صحيح type);
#د_که_پای
ST_FUNC فراغ greloca(Section *s, Sym *sym, بینښه اوږد دننه_واټن, صحيح type, addr_t addend);

ST_INLN فراغ sym_free(Sym *sym);
ST_FUNC Sym *sym_ټېل(صحيح v, CType *type, صحيح r, صحيح c);
ST_FUNC فراغ sym_راوباسه(Sym **ptop, Sym *b, صحيح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحيح v, صحيح t, صحيح c);
ST_FUNC Sym *sym_find2(Sym *s, صحيح v);
ST_INLN Sym *sym_پیدا_کړه(صحيح v);
ST_FUNC Sym *label_پیدا_کړه(صحيح v);
ST_FUNC Sym *label_ټېل(Sym **ptop, صحيح v, صحيح flags);
ST_FUNC فراغ label_راوباسه(Sym **ptop, Sym *slast, صحيح keep);
ST_INLN Sym *struct_پیدا_کړه(صحيح v);

ST_FUNC Sym *global_identifier_ټېل(صحيح v, صحيح t, صحيح c);
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
#إذا PTR_اندازه == 4
ST_FUNC فراغ lexpand(فراغ);
#د_که_پای
#که_تعریف_شوی TCC_موخه_ARM
ST_FUNC صحيح get_reg_ex(صحيح rc, صحيح rc2);
#د_که_پای
ST_FUNC فراغ save_reg(صحيح r);
ST_FUNC فراغ save_reg_upstack(صحيح r, صحيح n);
ST_FUNC صحيح get_reg(صحيح rc);
ST_FUNC فراغ save_regs(صحيح n);
ST_FUNC فراغ gaddrof(فراغ);
ST_FUNC صحيح gv(صحيح rc);
ST_FUNC فراغ gv2(صحيح rc1, صحيح rc2);
ST_FUNC فراغ gen_op(صحيح op);
ST_FUNC صحيح type_اندازه(CType *type, صحيح *a);
ST_FUNC فراغ mk_اشاره_ګر(CType *type);
ST_FUNC فراغ vstore(فراغ);
ST_FUNC فراغ inc(صحيح post, صحيح c);
ST_FUNC CString* parse_mult_str(ثابت حرف *پیغام);
ST_FUNC CString* parse_asm_str(فراغ);
ST_FUNC فراغ indir(فراغ);
ST_FUNC فراغ unary(فراغ);
ST_FUNC فراغ gexpr(فراغ);
ST_FUNC صحيح بیان_const(فراغ);
#إذا defined CONFIG_TCC_BCHECK || defined TCC_موخه_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, بینښه اوږد دننه_واټن, بینښه اوږد اندازه);
#د_که_پای
#إذا defined TCC_موخه_X86_64 && !defined TCC_موخه_PE
ST_FUNC صحيح classify_x86_64_va_arg(CType *ty);
#د_که_پای
#که_تعریف_شوی CONFIG_TCC_BCHECK
ST_FUNC فراغ gbound_دلیلونه(صحيح nb_دلیلونه);
ST_معلومات صحيح func_bound_جمع_کړه_epilog;
#د_که_پای
ST_FUNC Sym *gfunc_سېټ_param(Sym *s, صحيح c, صحيح byref);

/* ------------ tccelf.c ------------ */

#تعریف_کړه TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#تعریف_کړه TCC_OUTPUT_FORMAT_دوګونی 1 /* binary image output */
#تعریف_کړه TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#تعریف_کړه TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#تعریف_کړه ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

تعريفنوع بنية {
    بینښه صحيح n_strx;         /* index into string table of name */
    بینښه حرف n_type;         /* type of symbol */
    بینښه حرف n_other;        /* misc info (usually empty) */
    بینښه لنډ n_desc;        /* description field */
    بینښه صحيح n_ارزښت;        /* value of symbol */
} Stab_Sym;

ST_FUNC فراغ tccelf_new(TCCState *s);
ST_FUNC فراغ tccelf_delete(TCCState *s);
ST_FUNC فراغ tccelf_begin_file(TCCState *s1);
ST_FUNC فراغ tccelf_پای_ټکی_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags);
ST_FUNC فراغ section_realloc(Section *sec, بینښه اوږد new_اندازه);
ST_FUNC اندازه_t section_جمع_کړه(Section *sec, addr_t اندازه, صحيح align);
ST_FUNC فراغ *section_ptr_جمع_کړه(Section *sec, addr_t اندازه);
ST_FUNC Section *پیدا_کړه_section(TCCState *s1, ثابت حرف *name);
ST_FUNC فراغ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت حرف *symtab_name, صحيح sh_type, صحيح sh_flags, ثابت حرف *strtab_name, ثابت حرف *hash_name, صحيح hash_sh_flags);
ST_FUNC فراغ init_symtab(Section *s);

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym);
ST_FUNC صحيح put_elf_sym(Section *s, addr_t ارزښت, بینښه اوږد اندازه, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح سېټ_elf_sym(Section *s, addr_t ارزښت, بینښه اوږد اندازه, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح پیدا_کړه_elf_sym(Section *s, ثابت حرف *name);
ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, بینښه اوږد دننه_واټن, صحيح type, صحيح نښه);
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, بینښه اوږد دننه_واټن, صحيح type, صحيح نښه, addr_t addend);

ST_FUNC فراغ resolve_common_syms(TCCState *s1);
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve);
ST_FUNC فراغ relocate_sections(TCCState *s1);

ST_FUNC ssize_t ډک_read(صحيح fd, فراغ *buf, اندازه_t شمېر_2);
ST_FUNC فراغ *بارول_معلومات(صحيح fd, بینښه اوږد file_دننه_واټن, بینښه اوږد اندازه);
ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h);
ST_FUNC صحيح tcc_بارول_object_file(TCCState *s1, صحيح fd, بینښه اوږد file_دننه_واټن);
ST_FUNC صحيح tcc_بارول_archive(TCCState *s1, صحيح fd, صحيح alacarte);
ST_FUNC فراغ جمع_کړه_array(TCCState *s1, ثابت حرف *sec, صحيح c);

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح شاخص, صحيح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت حرف *name, صحيح err, صحيح forc);
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*نښه_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));
ST_FUNC صحيح سېټ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#تعریف_کړه for_each_elem(sec, startoff, elem, type) \
    لكل (elem = (type *) sec->معلومات + startoff; \
         elem < (type *) (sec->معلومات + sec->معلومات_دننه_واټن); elem++)

#که_نه_تعریف_شوی ELF_OBJ_ONLY
ST_FUNC صحيح tcc_بارول_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level);
ST_FUNC صحيح tcc_بارول_ldscript(TCCState *s1, صحيح fd);
ST_FUNC فراغ tccelf_جمع_کړه_crtbegin(TCCState *s1);
ST_FUNC فراغ tccelf_جمع_کړه_crtend(TCCState *s1);
#د_که_پای
#که_نه_تعریف_شوی TCC_موخه_PE
ST_FUNC فراغ tcc_جمع_کړه_runtime(TCCState *s1);
#د_که_پای

/* ------------ xxx-link.c ------------ */

#که_نه_تعریف_شوی TCC_موخه_PE
ST_FUNC صحيح کوډ_reloc (صحيح reloc_type);
ST_FUNC صحيح gotplt_ثبت_type (صحيح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
تعداد gotplt_ثبت {
    NO_GOTPLT_ثبت,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ثبت,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ثبت	/* always generate (eg. PLTOFF relocs) */
};
#تعریف_کړه NEED_RELOC_TYPE
#إذا !defined TCC_موخه_MACHO || defined TCC_IS_NATIVE
ST_FUNC بینښه create_plt_ثبت(TCCState *s1, بینښه got_دننه_واټن, بنية sym_attr *attr);
ST_FUNC فراغ relocate_plt(TCCState *s1);
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym); /* in tccelf.c */
#تعریف_کړه NEED_BUILD_GOT
#د_که_پای
#د_که_پای

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بینښه حرف *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_معلومات ثابت حرف * ثابت موخه_machine_defs;
ST_معلومات ثابت صحيح reg_classes[NB_REGS];

ST_FUNC فراغ gsym_addr(صحيح t, صحيح a);
ST_FUNC فراغ gsym(صحيح t);
ST_FUNC فراغ بارول(صحيح r, SValue *sv);
ST_FUNC فراغ store(صحيح r, SValue *v);
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *align, صحيح *regsize);
ST_FUNC فراغ gfunc_call(صحيح nb_دلیلونه);
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
#که_نه_تعریف_شوی TCC_موخه_C67
ST_FUNC فراغ o(بینښه صحيح c);
#د_که_پای
ST_FUNC فراغ gen_vla_sp_save(صحيح addr);
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr);
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align);

ساكن مضمن uint16_t read16le(بینښه حرف *p) {
    أرجع p[0] | (uint16_t)p[1] << 8;
}
ساكن مضمن فراغ write16le(بینښه حرف *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ساكن مضمن uint32_t read32le(بینښه حرف *p) {
  أرجع read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ساكن مضمن فراغ write32le(بینښه حرف *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ساكن مضمن فراغ add32le(بینښه حرف *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ساكن مضمن uint64_t read64le(بینښه حرف *p) {
  أرجع read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ساكن مضمن فراغ write64le(بینښه حرف *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ساكن مضمن فراغ add64le(بینښه حرف *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#إذا defined TCC_موخه_I386 || defined TCC_موخه_X86_64 || defined TCC_موخه_ARM
ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);
#د_که_پای
#إذا defined TCC_موخه_I386 || defined TCC_موخه_X86_64
ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#د_که_پای

/* ------------ x86_64-gen.c ------------ */
#که_تعریف_شوی TCC_موخه_X86_64
ST_FUNC فراغ gen_opl(صحيح op);
#که_تعریف_شوی TCC_موخه_PE
ST_FUNC فراغ gen_vla_پایله(صحيح addr);
#د_که_پای
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
#د_که_پای

/* ------------ arm-gen.c ------------ */
#که_تعریف_شوی TCC_موخه_ARM
#إذا defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت حرف *default_elfinterp(بنية TCCState *s);
#د_که_پای
ST_FUNC فراغ arm_init(بنية TCCState *s);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#د_که_پای

/* ------------ arm64-gen.c ------------ */
#که_تعریف_شوی TCC_موخه_ARM64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gfunc_return(CType *func_type);
ST_FUNC فراغ gen_va_پیل(فراغ);
ST_FUNC فراغ gen_va_arg(CType *t);
ST_FUNC فراغ gen_clear_cache(فراغ);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#د_که_پای

/* ------------ riscv64-gen.c ------------ */
#که_تعریف_شوی TCC_موخه_RISCV64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gen_va_پیل(فراغ);
ST_FUNC فراغ arch_transfer_ret_regs(صحيح);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
ST_FUNC فراغ gen_clear_cache(فراغ);
#د_که_پای

/* ------------ c67-gen.c ------------ */
#که_تعریف_شوی TCC_موخه_C67
#د_که_پای

/* ------------ tcccoff.c ------------ */
#که_تعریف_شوی TCC_موخه_COFF
ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحيح tcc_بارول_coff(TCCState * s1, صحيح fd);
#د_که_پای

/* ------------ tccasm.c ------------ */
ST_FUNC فراغ asm_instr(فراغ);
ST_FUNC فراغ asm_global_instr(فراغ);
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess);
#که_تعریف_شوی CONFIG_TCC_ASM
ST_FUNC صحيح پیدا_کړه_constraint(ASMOperand *operands, صحيح nb_operands, ثابت حرف *name, ثابت حرف **pp);
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym);
ST_FUNC فراغ asm_بیان(TCCState *s1, بیان_ارزښت *pe);
ST_FUNC صحيح asm_int_بیان(TCCState *s1);
#إذا PTR_اندازه == 8
ST_FUNC فراغ gen_expr64(بیان_ارزښت *pe);
#د_که_پای
/* ------------ i386-asm.c ------------ */
ST_FUNC فراغ gen_expr32(بیان_ارزښت *pe);
ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode);
ST_FUNC صحيح asm_parse_regvar(صحيح t);
ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, ثابت uint8_t *clobber_regs, صحيح *pout_reg);
ST_FUNC فراغ subst_asm_عملوند(CString *جمع_کړه_str, SValue *sv, صحيح modifier);
ST_FUNC فراغ asm_gen_کوډ(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, صحيح is_output, uint8_t *clobber_regs, صحيح بهر_reg);
ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str);
#د_که_پای

/* ------------ tccpe.c -------------- */
#که_تعریف_شوی TCC_موخه_PE
ST_FUNC صحيح pe_بارول_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename);
ST_FUNC صحيح pe_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t ارزښت);
ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg);
#إذا defined TCC_موخه_I386 || defined TCC_موخه_X86_64
#د_که_پای
#إذا defined(TCC_موخه_X86_64) || defined(TCC_موخه_ARM64)
ST_FUNC فراغ pe_جمع_کړه_unwind_معلومات(بینښه پیل, بینښه پای_ټکی, بینښه ډېری);
#د_که_پای
PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#د_که_پای
#تعریف_کړه ST_ASM_سېټ 0x04

/* ------------ tccmacho.c ----------------- */
#که_تعریف_شوی TCC_موخه_MACHO
ST_FUNC صحيح macho_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح macho_بارول_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
ST_FUNC صحيح macho_بارول_tbd(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
#که_تعریف_شوی TCC_IS_NATIVE
ST_FUNC فراغ tcc_جمع_کړه_macos_sdkpath(TCCState* s);
ST_FUNC حرف* macho_tbd_soname(صحيح fd);
#د_که_پای
#د_که_پای
/* ------------ tccrun.c ----------------- */
#که_تعریف_شوی TCC_IS_NATIVE
#که_تعریف_شوی CONFIG_TCC_STATIC
#تعریف_کړه RTLD_LAZY       0x001
#تعریف_کړه RTLD_NOW        0x002
#تعریف_کړه RTLD_GLOBAL     0x100
#تعریف_کړه RTLD_DEFAULT    عدم
/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ST_FUNC فراغ dlclose(فراغ *p);
ST_FUNC ثابت حرف *dlerror(فراغ);
ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *نښه);
#د_که_پای
ST_FUNC فراغ tcc_پرلپسې_free(TCCState *s1);
#د_که_پای

/* ------------ tcctools.c ----------------- */
#إذا 0 /* included in tcc.c */
ST_FUNC صحيح tcc_tool_ar(TCCState *s, صحيح argc, حرف **argv);
#که_تعریف_شوی TCC_موخه_PE
ST_FUNC صحيح tcc_tool_impdef(TCCState *s, صحيح argc, حرف **argv);
#د_که_پای
ST_FUNC صحيح tcc_tool_cross(TCCState *s, حرف **argv, صحيح option);
ST_FUNC صحيح gen_makedeps(TCCState *s, ثابت حرف *موخه, ثابت حرف *filename);
#د_که_پای

/* ------------ tccdbg.c ------------ */

ST_FUNC فراغ tcc_debug_new(TCCState *s);

ST_FUNC فراغ tcc_debug_پیل(TCCState *s1);
ST_FUNC فراغ tcc_debug_پای_ټکی(TCCState *s1);
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1);

ST_FUNC فراغ tcc_debug_کرښه(TCCState *s1);
ST_FUNC فراغ tcc_جمع_کړه_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC فراغ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح ارزښت);
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح اندازه);
ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_عدد, صحيح sym_bind, صحيح sym_type);
ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح ارزښت);
ST_FUNC فراغ tcc_debug_fix_forw(TCCState *s1, CType *t);

#إذا !(defined ELF_OBJ_ONLY || defined TCC_موخه_ARM || defined TARGETOS_BSD)
ST_FUNC فراغ tcc_eh_چوکاټ_پیل(TCCState *s1);
ST_FUNC فراغ tcc_eh_چوکاټ_پای_ټکی(TCCState *s1);
ST_FUNC فراغ tcc_eh_چوکاټ_hdr(TCCState *s1, صحيح final);
#تعریف_کړه TCC_EH_چوکاټ 1
#د_که_پای

ST_FUNC فراغ tcc_tcov_پیل(TCCState *s1);
ST_FUNC فراغ tcc_tcov_پای_ټکی(TCCState *s1);
ST_FUNC فراغ tcc_tcov_check_کرښه(TCCState *s1, صحيح پیل);
ST_FUNC فراغ tcc_tcov_بلاک_پای_ټکی(TCCState *s1, صحيح کرښه);
ST_FUNC فراغ tcc_tcov_بلاک_begin(TCCState *s1);
ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1);

#تعریف_کړه stab_section            s1->stab_section
#تعریف_کړه stabstr_section         stab_section->link
#تعریف_کړه tcov_section            s1->tcov_section
#تعریف_کړه eh_چوکاټ_section        s1->eh_چوکاټ_section
#تعریف_کړه eh_چوکاټ_hdr_section    s1->eh_چوکاټ_hdr_section
#تعریف_کړه dwarf_info_section      s1->dwarf_info_section
#تعریف_کړه dwarf_abbrev_section    s1->dwarf_abbrev_section
#تعریف_کړه dwarf_کرښه_section      s1->dwarf_کرښه_section
#تعریف_کړه dwarf_aranges_section   s1->dwarf_aranges_section
#تعریف_کړه dwarf_str_section       s1->dwarf_str_section
#تعریف_کړه dwarf_کرښه_str_section  s1->dwarf_کرښه_str_section

#تعریف_کړه DWARF_MAX_128	((8 * حجم (int64_t) + 6) / 7)
#تعریف_کړه	dwarf_read_1(ln,پای_ټکی) \
	((ln) < (پای_ټکی) ? *(ln)++ : 0)
#تعریف_کړه	dwarf_read_2(ln,پای_ټکی) \
	((ln) + 1 < (پای_ټکی) ? read16le(((ln)+=2) - 2) : 0)
#تعریف_کړه	dwarf_read_4(ln,پای_ټکی) \
	((ln) + 3 < (پای_ټکی) ? read32le(((ln)+=4) - 4) : 0)
#تعریف_کړه	dwarf_read_8(ln,پای_ټکی) \
	((ln) + 7 < (پای_ټکی) ? read64le(((ln)+=8) - 8) : 0)
ساكن مضمن uint64_t
dwarf_read_uleb128(بینښه حرف **ln, بینښه حرف *پای_ټکی)
{
    بینښه حرف *cp = *ln;
    uint64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, پای_ټکی);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0)
	    اكسر;
    }
    *ln = cp;
    أرجع retval;
}
ساكن مضمن int64_t
dwarf_read_sleb128(بینښه حرف **ln, بینښه حرف *پای_ټکی)
{
    بینښه حرف *cp = *ln;
    int64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, پای_ټکی);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0) {
	    إذا ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    اكسر;
	}
    }
    *ln = cp;
    أرجع retval;
}

/* default dwarf version for "-gdwarf" */
#که_تعریف_شوی TCC_موخه_MACHO
# define DEFAULT_DWARF_نسخه 2
#وإلا
# define DEFAULT_DWARF_نسخه 5
#د_که_پای

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#که_نه_تعریف_شوی CONFIG_DWARF_نسخه
# define CONFIG_DWARF_نسخه 0
#د_که_پای

#إذا defined TCC_موخه_X86_64
# define R_معلومات_32_DW R_X86_64_32
#وإلا
# define R_معلومات_32_DW R_معلومات_32
#د_که_پای

/********************************************************/
#إذا CONFIG_TCC_SEMLOCK
#إذا defined _WIN32
تعريفنوع بنية { متطاير LONG init; CRITICAL_SECTION cs; } TCCSem;
ساكن مضمن فراغ wait_sem(TCCSem *p) {
    إذا (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } وإلا {
        طالما (InterlockedCompareExchange(&p->init, 2, 2) != 2)
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
    dispatch_semaphore_wait(p->sem, DISPATCH_وخت_FOREVER);
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
    طالما (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ساكن مضمن فراغ post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#د_که_پای
#تعریف_کړه TCC_SEM(s) TCCSem s
#تعریف_کړه WAIT_SEM wait_sem
#تعریف_کړه POST_SEM post_sem
#وإلا
#تعریف_کړه TCC_SEM(s)
#تعریف_کړه WAIT_SEM(p)
#تعریف_کړه POST_SEM(p)
#د_که_پای

/********************************************************/
#تعریف_لغوه ST_معلومات
#إذا ONE_سرچینه
#تعریف_کړه ST_معلومات ساكن
#وإلا
#تعریف_کړه ST_معلومات
#د_که_پای
/********************************************************/

#تعریف_کړه متن_section        TCC_STATE_VAR(متن_section)
#تعریف_کړه معلومات_section        TCC_STATE_VAR(معلومات_section)
#تعریف_کړه rodata_section      TCC_STATE_VAR(rodata_section)
#تعریف_کړه bss_section         TCC_STATE_VAR(bss_section)
#تعریف_کړه common_section      TCC_STATE_VAR(common_section)
#تعریف_کړه cur_متن_section    TCC_STATE_VAR(cur_متن_section)
#تعریف_کړه bounds_section      TCC_STATE_VAR(bounds_section)
#تعریف_کړه lbounds_section     TCC_STATE_VAR(lbounds_section)
#تعریف_کړه symtab_section      TCC_STATE_VAR(symtab_section)
#تعریف_کړه gnu_ext             TCC_STATE_VAR(gnu_ext)
#تعریف_کړه tcc_error_noabort   TCC_سېټ_STATE(_tcc_error_noabort)
#تعریف_کړه tcc_error           TCC_سېټ_STATE(_tcc_error)
#تعریف_کړه tcc_warning         TCC_سېټ_STATE(_tcc_warning)

#تعریف_کړه ټول_idents        TCC_STATE_VAR(ټول_idents)
#تعریف_کړه ټول_کرښې         TCC_STATE_VAR(ټول_کرښې)
#تعریف_کړه ټول_بایټونه         TCC_STATE_VAR(ټول_بایټونه)

PUB_FUNC فراغ tcc_enter_state(TCCState *s1);
PUB_FUNC فراغ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#تعریف_کړه tcc_warning_c(sw) TCC_سېټ_STATE((\
    tcc_state->warn_عدد = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#د_که_پای /* _TCC_H */

#تعریف_لغوه TCC_STATE_VAR
#تعریف_لغوه TCC_سېټ_STATE

#که_تعریف_شوی USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_سېټ_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#وإلا
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_سېټ_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#د_که_پای
