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

#اگر_تعریف_نشده _TCC_H
#تعریف_کن _TCC_H

#تعریف_کن GNU_منبع
#تعریف_کن DARWIN_C_منبع
#ضمن "config.h"

#ضمن <stdarg.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#اگر_تعریف_شده __TINYC__
# undef __attribute__
#پایان_اگر
#ضمن <string.h>
#ضمن <errno.h>
#ضمن <math.h>
#ضمن <fcntl.h>
#ضمن <setjmp.h>
#ضمن <time.h>

#اگر_تعریف_نشده _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
خارجي عائم strtof (ثابت حرف *__nptr, حرف **__endptr);
خارجي دراز مزدوج strtold (ثابت حرف *__nptr, حرف **__endptr);
#پایان_اگر

#اگر_تعریف_شده _WIN32
# define WIN32_LEAN_AND_میانگین 1
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
#  define strtold (دراز مزدوج)strtod
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
#پایان_اگر

#اگر_تعریف_نشده O_دودویی_2
# define O_دودویی_2 0
#پایان_اگر

#اگر_تعریف_نشده offsetof
#اگر_تعریف_شده __clang__ // clang -fsanitize compains about: NULL+value
#تعریف_کن offsetof(type, فیلد) __builtin_offsetof(type, فیلد)
#وإلا
#تعریف_کن offsetof(type, فیلد) ((اندازه_t) &((type *)0)->فیلد)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده countof
#تعریف_کن countof(tab) (حجم(tab) / حجم((tab)[0]))
#پایان_اگر

#اگر_تعریف_شده _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#وإلا
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (چاپ_کن, (x), (y))))
#پایان_اگر

#اگر_تعریف_شده _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#وإلا
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#پایان_اگر

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
#إذا !defined(TCC_هدف_I386) && !defined(TCC_هدف_ARM) && \
    !defined(TCC_هدف_ARM64) && !defined(TCC_هدف_C67) && \
    !defined(TCC_هدف_X86_64) && !defined(TCC_هدف_RISCV64)
# إذا defined __x86_64__
#  define TCC_هدف_X86_64
# elif defined __arm__
#  define TCC_هدف_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_هدف_ARM64
# elif defined __riscv
#  define TCC_هدف_RISCV64
# وإلا
#  define TCC_هدف_I386
# endif
# ifdef _WIN32
#  define TCC_هدف_PE 1
# endif
# ifdef __APPLE__
#  define TCC_هدف_MACHO 1
# endif
#پایان_اگر

/* only native compiler supports -run */
#إذا defined _WIN32 == defined TCC_هدف_PE \
    && defined __APPLE__ == defined TCC_هدف_MACHO
# إذا defined __i386__ && defined TCC_هدف_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_هدف_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_هدف_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_هدف_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_هدف_RISCV64
#  define TCC_IS_NATIVE
# endif
#پایان_اگر

#إذا defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#وإلا
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#پایان_اگر

#إذا defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#وإلا
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#پایان_اگر

#إذا defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#وإلا
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#پایان_اگر

#إذا defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وإلاإذا !(defined TCC_هدف_PE || defined TCC_هدف_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#پایان_اگر

#إذا defined TCC_هدف_PE || defined TCC_هدف_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#وإلا
# define TCC_هدف_UNIX 1
#پایان_اگر

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#إذا defined TCC_هدف_PE \
    || (defined TCC_هدف_MACHO && defined TCC_هدف_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#پایان_اگر

#اگر_تعریف_شده CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#پایان_اگر

/* support using libtcc from threads */
#اگر_تعریف_نشده CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#پایان_اگر

/* ------------ path configuration ------------ */

#اگر_تعریف_نشده CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#پایان_اگر

#إذا !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#پایان_اگر

#اگر_تعریف_شده CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#وإلا
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#پایان_اگر

/* path to find crt1.o, crti.o and crtn.o */
#اگر_تعریف_نشده CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#پایان_اگر

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#اگر_تعریف_نشده CONFIG_TCC_SYSINCLUDEPATHS
# إذا defined TCC_هدف_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# وإلا
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#پایان_اگر

/* library search paths */
#اگر_تعریف_نشده CONFIG_TCC_LIBPATHS
# إذا defined TCC_هدف_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# وإلا
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#پایان_اگر

/* name of ELF interpreter */
#اگر_تعریف_نشده CONFIG_TCC_ELFINTERP
# إذا defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_هدف_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_هدف_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_هدف_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_هدف_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_هدف_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# وإلا
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#پایان_اگر

/* (target specific) libtcc1.a */
#اگر_تعریف_نشده TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#پایان_اگر

/* <cross-prefix-to->libtcc1.a */
#اگر_تعریف_نشده CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#پایان_اگر

/* -------------------------------------------- */

#ضمن "libtcc.h"
#ضمن "elf.h"
#ضمن "stab.h"
#ضمن "dwarf.h"

/* -------------------------------------------- */

#اگر_تعریف_نشده PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#پایان_اگر

#اگر_تعریف_نشده ONE_منبع
# define ONE_منبع 0
#پایان_اگر

#إذا ONE_منبع
#تعریف_کن ST_INLN ساكن مضمن
#تعریف_کن ST_FUNC ساكن
#تعریف_کن ST_داده ساكن
#وإلا
#تعریف_کن ST_INLN
#تعریف_کن ST_FUNC
#تعریف_کن ST_داده خارجي
#پایان_اگر

#اگر_تعریف_شده TCC_PROFILE /* profile all functions */
# define ساكن
# define مضمن
#پایان_اگر

/* -------------------------------------------- */
/* include the target specific definitions */

#تعریف_کن هدف_DEFS_ONLY
#اگر_تعریف_شده TCC_هدف_I386
# include "i386-gen.c"
# include "i386-link.c"
#وإلاإذا defined TCC_هدف_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#وإلاإذا defined TCC_هدف_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#وإلاإذا defined TCC_هدف_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#وإلاإذا defined TCC_هدف_C67
# define TCC_هدف_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#وإلاإذا defined(TCC_هدف_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#وإلا
#خطا unknown هدف
#پایان_اگر
#لغو_تعریف هدف_DEFS_ONLY

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
#پایان_اگر
/* target address type */
#تعریف_کن addr_t ElfW(Addr)
#تعریف_کن ElfSym ElfW(Sym)

#إذا PTR_اندازه == 8 && !defined TCC_هدف_PE
# define LONG_اندازه 8
#وإلا
# define LONG_اندازه 4
#پایان_اگر

/* -------------------------------------------- */

#تعریف_کن INCLUDE_پشته_اندازه  32
#تعریف_کن IFDEF_پشته_اندازه    64
#تعریف_کن VSTACK_اندازه         512
#تعریف_کن STRING_MAX_اندازه     1024
#تعریف_کن TOKSTR_MAX_اندازه     256
#تعریف_کن PACK_پشته_اندازه     8

#تعریف_کن TOK_HASH_اندازه       16384 /* must be a power of two */
#تعریف_کن TOK_ALLOC_INCR      512  /* must be a power of two */
#تعریف_کن TOK_MAX_اندازه        4 /* token max size in int unit when stored in string */

/* token symbol management */
تعريفنوع بنية TokenSym {
    بنية TokenSym *hash_بعدی;
    بنية Sym *sym_define; /* direct pointer to define */
    بنية Sym *sym_label; /* direct pointer to label */
    بنية Sym *sym_struct; /* direct pointer to structure */
    بنية Sym *sym_identifier; /* direct pointer to identifier */
    صحيح tok; /* token number */
    صحيح len;
    حرف str[1];
} TokenSym;

#اگر_تعریف_شده TCC_هدف_PE
تعريفنوع بیعلامت کوتاه nwchar_t;
#وإلا
تعريفنوع صحيح nwchar_t;
#پایان_اگر

تعريفنوع بنية CString {
    صحيح اندازه; /* size in bytes */
    صحيح اندازه_allocated;
    حرف *داده; /* nwchar_t* in cases */
} CString;

/* type definition */
تعريفنوع بنية CType {
    صحيح t;
    بنية Sym *ref;
} CType;

/* long double words on host(!) platform */
#تعریف_کن LDOUBLE_واژگان ((حجم(دراز مزدوج)+3)/4)

/* constant value */
تعريفنوع اتحاد CValue {
    دراز مزدوج ld;
    مزدوج d;
    عائم f;
    uint64_t i;
    بنية {
        حرف *داده;
        صحيح اندازه;
    } str;
    صحيح tab[LDOUBLE_واژگان];
} CValue;

/* value on stack */
تعريفنوع بنية SValue {
    CType type;      /* type */
    بیعلامت کوتاه r;      /* register + flags */
    بیعلامت کوتاه r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اتحاد {
      بنية { صحيح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اتحاد {
      بنية { بیعلامت کوتاه cmp_op, cmp_r; }; /* VT_CMP operation */
      بنية Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
بنية SymAttr {
    بیعلامت کوتاه
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
    بیعلامت
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_آرگومانها   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
تعريفنوع بنية Sym {
    صحيح v; /* symbol token */
    بیعلامت کوتاه r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
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
        دراز دراز enum_val; /* enum constant if IS_ENUM_VAL */
        صحيح *d; /* define token stream */
        بنية Sym *cleanup_func;
    };

    CType type; /* associated type */
    اتحاد {
        بنية Sym *بعدی; /* next related symbol (for fields and anoms) */
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
    بیعلامت دراز داده_جابه_جایی; /* current data offset */
    بیعلامت حرف *داده;       /* section data */
    بیعلامت دراز داده_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحيح sh_name;             /* elf section name (only used during output) */
    صحيح sh_رقم;              /* elf section number */
    صحيح sh_type;             /* elf section type */
    صحيح sh_flags;            /* elf section flags */
    صحيح sh_info;             /* elf section info */
    صحيح sh_addralign;        /* elf section alignment */
    صحيح sh_entsize;          /* elf entry size */
    بیعلامت دراز sh_اندازه;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    بیعلامت دراز sh_جابه_جایی; /* file offset */
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
    بیعلامت حرف یافت, شاخص;
    حرف name[1];
} DLLReference;

/* -------------------------------------------------- */

#تعریف_کن SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#تعریف_کن SYM_فیلد      0x20000000 /* struct/union field symbol space */
#تعریف_کن SYM_اولی_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#تعریف_کن FUNC_NEW       1 /* ansi function prototype */
#تعریف_کن FUNC_OLD       2 /* old function prototype */
#تعریف_کن FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#تعریف_کن FUNC_CDECL     0 /* standard c call */
#تعریف_کن FUNC_STDCALL   1 /* pascal c call */
#تعریف_کن FUNC_FASTCALL1 2 /* first param in %eax */
#تعریف_کن FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#تعریف_کن FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#تعریف_کن FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#تعریف_کن FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#تعریف_کن MACRO_OBJ      0 /* object like macro */
#تعریف_کن MACRO_FUNC     1 /* function like macro */
#تعریف_کن MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#تعریف_کن LABEL_DEFINED  0 /* label is defined */
#تعریف_کن LABEL_FORWARD  1 /* label is forward defined */
#تعریف_کن LABEL_DECLARED 2 /* label is declared but never used */
#تعریف_کن LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#تعریف_کن TYPE_ABSTRACT  1 /* type without variable */
#تعریف_کن TYPE_مستقیم    2 /* type with variable */
#تعریف_کن TYPE_PARAM     4 /* type declares function parameter */
#تعریف_کن TYPE_NEST      8 /* nested call to post_type */

#تعریف_کن IO_BUF_اندازه 8192

تعريفنوع بنية BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_انتها;
    صحيح fd;
    بنية BufferedFile *prev;
    صحيح سطر_رقم;    /* current line number - here to simplify code */
    صحيح سطر_ref;    /* tcc -E: last printed line */
    صحيح ifndef_macro;  /* #ifndef macro / #endif search */
    صحيح ifndef_macro_saved; /* saved ifndef_macro */
    صحيح *ifdef_پشته_ptr; /* ifdef_stack value at the start of the file */
    صحيح include_بعدی_شاخص; /* next search path */
    صحيح prev_tok_flags; /* saved tok_flags */
    حرف filename[1024];    /* filename */
    حرف *true_filename; /* filename not modified by # line directive */
    بیعلامت حرف unget[4];
    بیعلامت حرف میانگیر[1]; /* extra size for CH_EOB char */
} BufferedFile;

#تعریف_کن CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#تعریف_کن CH_EOF   (-1)   /* end of file */

/* used to record tokens */
تعريفنوع بنية TokenString {
    صحيح *str;
    صحيح len;
    صحيح need_spc;
    صحيح allocated_len;
    صحيح آخرین_سطر_رقم;
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
    صحيح alias_هدف; /* token */
    صحيح asm_label; /* associated asm label */
    حرف attr_نما; /* __attribute__((__mode__(...))) */
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
    صحيح hash_بعدی; /* -1 if none */
    حرف filename[1]; /* path specified in #include */
} CachedInclude;

#تعریف_کن CACHED_INCLUDES_HASH_اندازه 32

#اگر_تعریف_شده CONFIG_TCC_ASM
تعريفنوع بنية عبارت_مقدار {
    uint64_t v;
    Sym *sym;
    صحيح pcrel;
} عبارت_مقدار;

#تعریف_کن MAX_ASM_OPERANDS 30
تعريفنوع بنية ASMOperand {
    صحيح id; /* GCC 3 optional identifier (0 if number only supported) */
    حرف constraint[16];
    حرف asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحيح ref_شاخص; /* if >= 0, gives reference to a output constraint */
    صحيح درون_داد_شاخص; /* if >= 0, gives reference to an input constraint */
    صحيح اولویت; /* priority, used to assign registers */
    صحيح reg; /* if >= 0, register number used for this operand */
    صحيح is_llong; /* true if double register value */
    صحيح is_حافظه; /* true if memory operand */
    صحيح is_rw;     /* for '+' modifier */
    صحيح is_label;  /* for asm goto */
} ASMOperand;
#پایان_اگر

/* extra symbol attributes (not in symbol table) */
بنية sym_attr {
    بیعلامت got_جابه_جایی;
    بیعلامت plt_جابه_جایی;
    صحيح plt_sym;
    صحيح dyn_شاخص;
    بیعلامت حرف linker_sym:1;
#اگر_تعریف_شده TCC_هدف_ARM
    بیعلامت حرف plt_thumb_stub:1;
#پایان_اگر
};

بنية TCCState {
    بیعلامت حرف verbose; /* if true, display some information during compilation */
    بیعلامت حرف nostdinc; /* if true, no standard headers are added */
    بیعلامت حرف nostdlib; /* if true, no standard libraries are added */
    بیعلامت حرف nostdlib_paths; /* if true, the default paths are not searched for libraries */
    بیعلامت حرف nocommon; /* if true, do not use common symbols for .bss data */
    بیعلامت حرف static_link; /* if true, static linking is performed */
    بیعلامت حرف rdynamic; /* if true, all symbols are exported */
    بیعلامت حرف symbolic; /* if true, resolve symbols in the current module first */
    بیعلامت حرف znodelete; /* Set DF_1_NODELETE in dynamic section */
    بیعلامت حرف filetype; /* file type for compilation (NONE,C,ASM) */
    بیعلامت حرف optimize; /* only to #define __OPTIMIZE__ */
    بیعلامت حرف option_pthread; /* -pthread option */
    بیعلامت حرف enable_new_dtags; /* -Wl,--enable-new-dtags */
    بیعلامت صحيح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    بیعلامت حرف char_is_unsigned;
    بیعلامت حرف leading_underscore;
    بیعلامت حرف ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    بیعلامت حرف dollars_درون_identifiers;  /* allows '$' char in identifiers */
    بیعلامت حرف ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    بیعلامت حرف معکوس_funcargs; /* if true, evaluate last function arg first */
    بیعلامت حرف gnu89_inline; /* treat 'extern inline' like 'static inline' */
    بیعلامت حرف unwind_tables; /* create eh_frame section */

    /* warning switches */
    بیعلامت حرف warn_none;
    بیعلامت حرف warn_all;
    بیعلامت حرف warn_error;
    بیعلامت حرف warn_write_رشتهها;
    بیعلامت حرف warn_unsupported;
    بیعلامت حرف warn_implicit_function_declaration;
    بیعلامت حرف warn_discarded_qualifiers;
    #تعریف_کن WARN_ON  1 /* warning is on (-Woption) */
    بیعلامت حرف warn_رقم; /* temp var for tcc_warning_c() */

    بیعلامت حرف option_r; /* option -r */
    بیعلامت حرف do_bench; /* option -bench */
    بیعلامت حرف just_deps; /* option -M  */
    بیعلامت حرف gen_deps; /* option -MD  */
    بیعلامت حرف include_sys_deps; /* option -MD  */
    بیعلامت حرف gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    بیعلامت حرف do_debug;
    بیعلامت حرف dwarf;
    بیعلامت حرف do_backtrace;
#اگر_تعریف_شده CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    بیعلامت حرف do_bounds_check;
#پایان_اگر
    بیعلامت حرف test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    بیعلامت حرف gnu_ext;
    /* use TinyCC extensions */
    بیعلامت حرف tcc_ext;

    بیعلامت حرف dflag; /* -dX value */
    بیعلامت حرف Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#اگر_تعریف_شده TCC_هدف_X86_64
    بیعلامت حرف nosse; /* For -mno-sse support. */
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_ARM
    بیعلامت حرف float_abi; /* float ABI of the generated code*/
#پایان_اگر

    بیعلامت حرف has_متن_addr;
    addr_t متن_addr; /* address of text section */
    بیعلامت section_align; /* section alignment */
#اگر_تعریف_شده TCC_هدف_I386
    صحيح seg_اندازه; /* 32. Can be 16 with i386 assembler (.code16) */
#پایان_اگر

    حرف *tcc_lib_مسیر; /* CONFIG_TCCDIR or -B option */
    حرف *soname; /* as specified on the command line (-soname) */
    حرف *rpath; /* as specified on the command line (-Wl,-rpath=) */
    حرف *elfint; /* -Wl,-I... on command line */
    حرف *elf_entryname; /* "_start" unless set */
    حرف *init_نماد; /* symbols to call at load-time (not used currently) */
    حرف *fini_نماد; /* symbols to call at unload-time (not used currently) */
    حرف *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحيح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحيح output_format;
    /* nth test to run with -dt -run */
    صحيح پیاپی_test;

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
    فراغ (*error_func)(فراغ *opaque, ثابت حرف *پیام);
    صحيح error_مجموعه_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحيح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    حرف **هدف_deps;
    صحيح nb_هدف_deps;

    /* compilation */
    BufferedFile *include_پشته[INCLUDE_پشته_اندازه];
    BufferedFile **include_پشته_ptr;

    صحيح ifdef_پشته[IFDEF_پشته_اندازه];
    صحيح *ifdef_پشته_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحيح cached_includes_hash[CACHED_INCLUDES_HASH_اندازه];
    CachedInclude **cached_includes;
    صحيح nb_cached_includes;

    /* #pragma pack stack */
    صحيح pack_پشته[PACK_پشته_اندازه];
    صحيح *pack_پشته_ptr;
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
    Section *متن_section, *داده_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_متن_section; /* current section where function code is generated */
#اگر_تعریف_شده CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#پایان_اگر
    /* symbol section */
    اتحاد { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_قاب_section;
    Section *eh_قاب_hdr_section;
    بیعلامت دراز eh_شروع;
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
    #تعریف_کن qrel s1->qrel

    addr_t tls_شروع, tls_انتها;

#اگر_تعریف_شده TCC_هدف_RISCV64
    بنية pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحيح nb_pcrel_hi_entries;
#پایان_اگر

#اگر_تعریف_شده TCC_هدف_PE
    /* PE info */
    صحيح pe_subsystem;
    بیعلامت pe_characteristics;
    بیعلامت pe_dll_characteristics;
    بیعلامت pe_file_align;
    بیعلامت pe_پشته_اندازه;
    addr_t pe_imagebase;
# إذا defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
    Section *uw_pdata;
    صحيح uw_sym;
    صحيح uw_xsym;
    بیعلامت uw_offs;
# endif
#پایان_اگر

#إذا defined TCC_هدف_MACHO
    حرف *install_name;
    uint32_t compatibility_نسخه;
    uint32_t current_نسخه;
#پایان_اگر

#اگر_تعریف_نشده ELF_OBJ_ONLY
    صحيح nb_sym_versions;
    بنية sym_نسخه *sym_versions;
    صحيح nb_sym_مقصد_نسخه;
    صحيح *sym_مقصد_نسخه;
    صحيح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#پایان_اگر

#اگر_تعریف_شده TCC_IS_NATIVE
    ثابت حرف *پیاپی_main; /* entry for tcc_run() */
    فراغ *پیاپی_ptr; /* runtime_memory */
    بیعلامت پیاپی_اندازه; /* size of runtime_memory  */
    ثابت حرف *پیاپی_stdin; /* custom stdin file for run_main */
#اگر_تعریف_شده _WIN64
    فراغ *پیاپی_function_جدول; /* unwind data */
#پایان_اگر
    بنية TCCState *بعدی;
    بنية rt_context *rc; /* pointer to backtrace info block */
    فراغ *پیاپی_lj, *پیاپی_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    فراغ *bt_داده;
#پایان_اگر

#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    صحيح rt_رقم_callers;
#پایان_اگر

    /* benchmark info */
    صحيح مجموع_idents;
    صحيح مجموع_سطرها;
    بیعلامت صحيح مجموع_بایتها;
    بیعلامت صحيح مجموع_output[4];

    /* used by tcc_load_ldscript */
    بیعلامت حرف *ld_p; /* text pointer */

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
#تعریف_کن VT_VALMASK   0x003f  /* mask for value location, register or: */
#تعریف_کن VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#تعریف_کن VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#تعریف_کن VT_LOCAL     0x0032  /* offset on stack */
#تعریف_کن VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#تعریف_کن VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#تعریف_کن VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#تعریف_کن VT_LVAL      0x0100  /* var is an lvalue */
#تعریف_کن VT_SYM       0x0200  /* a symbol value is added */
#تعریف_کن VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#تعریف_کن VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#تعریف_کن VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#تعریف_کن VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#تعریف_کن VT_BTYPE       0x000f  /* mask for basic type */
#تعریف_کن VT_VOID             0  /* void type */
#تعریف_کن VT_BYTE             1  /* signed byte type */
#تعریف_کن VT_SHORT            2  /* short type */
#تعریف_کن VT_INT              3  /* integer type */
#تعریف_کن VT_LLONG            4  /* 64 bit integer */
#تعریف_کن VT_PTR              5  /*اشاره_گر*/
#تعریف_کن VT_FUNC             6  /* function type */
#تعریف_کن VT_STRUCT           7  /* struct/union definition */
#تعریف_کن VT_FLOAT            8  /* IEEE float */
#تعریف_کن VT_DOUBLE           9  /* IEEE double */
#تعریف_کن VT_LDOUBLE         10  /* IEEE long double */
#تعریف_کن VT_BOOL            11  /* ISOC99 boolean type */
#تعریف_کن VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#تعریف_کن VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#تعریف_کن VT_UNSIGNED    0x0010  /* unsigned type */
#تعریف_کن VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#تعریف_کن VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#تعریف_کن VT_BITFIELD    0x0080  /* bitfield modifier */
#تعریف_کن VT_CONSTANT    0x0100  /* const modifier */
#تعریف_کن VT_VOLATILE    0x0200  /* volatile modifier */
#تعریف_کن VT_RESTRICT    0x0400  /* restrict modifier */
#تعریف_کن VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#تعریف_کن VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#تعریف_کن VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#تعریف_کن VT_EXTERN  0x00002000  /* extern definition */
#تعریف_کن VT_STATIC  0x00004000  /* static variable */
#تعریف_کن VT_TYPEDEF 0x00008000  /* typedef definition */
#تعریف_کن VT_INLINE  0x00010000  /* inline definition */
#تعریف_کن VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#تعریف_کن VT_STRUCT_لغزش 20     /* shift for bitfield shift values (32 - 2*6) */
#تعریف_کن VT_STRUCT_ماسک (((1U << (6+6)) - 1) << VT_STRUCT_لغزش | VT_BITFIELD)
#تعریف_کن بیت_POS(t) (((t) >> VT_STRUCT_لغزش) & 0x3f)
#تعریف_کن بیت_اندازه(t) (((t) >> (VT_STRUCT_لغزش + 6)) & 0x3f)

#تعریف_کن VT_UNION    (1 << VT_STRUCT_لغزش | VT_STRUCT)
#تعریف_کن VT_ENUM     (2 << VT_STRUCT_لغزش) /* integral type is an enum really */
#تعریف_کن VT_ENUM_VAL (3 << VT_STRUCT_لغزش) /* integral type is an enum constant really */

#تعریف_کن IS_ENUM(t) ((t & VT_STRUCT_ماسک) == VT_ENUM)
#تعریف_کن IS_ENUM_VAL(t) ((t & VT_STRUCT_ماسک) == VT_ENUM_VAL)
#تعریف_کن IS_UNION(t) ((t & (VT_STRUCT_ماسک|VT_BTYPE)) == VT_UNION)

#تعریف_کن VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#تعریف_کن VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#تعریف_کن VT_TYPE (~(VT_STORAGE|VT_STRUCT_ماسک))

/* symbol was created by tccasm.c first */
#تعریف_کن VT_ASM (VT_VOID | 4 << VT_STRUCT_لغزش)
#تعریف_کن VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_لغزش)
#تعریف_کن IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_ماسک) & ~(1<<VT_STRUCT_لغزش))) == VT_ASM)
#تعریف_کن IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_ماسک)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#تعریف_کن VT_BT_ARRAY (6 << VT_STRUCT_لغزش)
#تعریف_کن IS_BT_ARRAY(t) ((t & VT_STRUCT_ماسک) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#تعریف_کن BFVAL(M,N) ((بیعلامت)((M) & ~((M) << 1)) * (N))
#تعریف_کن BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#تعریف_کن BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#تعریف_کن TOK_LAND  0x90
#تعریف_کن TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#تعریف_کن TOK_ULT 0x92
#تعریف_کن TOK_UGE 0x93
#تعریف_کن TOK_EQ  0x94
#تعریف_کن TOK_NE  0x95
#تعریف_کن TOK_ULE 0x96
#تعریف_کن TOK_UGT 0x97
#تعریف_کن TOK_Nset 0x98
#تعریف_کن TOK_Nclear 0x99
#تعریف_کن TOK_LT  0x9c
#تعریف_کن TOK_GE  0x9d
#تعریف_کن TOK_LE  0x9e
#تعریف_کن TOK_GT  0x9f

#تعریف_کن TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#تعریف_کن TOK_DEC     0x80 /* -- */
#تعریف_کن TOK_MID     0x81 /* inc/dec, to void constant */
#تعریف_کن TOK_INC     0x82 /* ++ */
#تعریف_کن TOK_UDIV    0x83 /* unsigned division */
#تعریف_کن TOK_UMOD    0x84 /* unsigned modulo */
#تعریف_کن TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#تعریف_کن TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#تعریف_کن TOK_ADDC1   0x87 /* add with carry generation */
#تعریف_کن TOK_ADDC2   0x88 /* add with carry use */
#تعریف_کن TOK_SUBC1   0x89 /* add with carry generation */
#تعریف_کن TOK_SUBC2   0x8a /* add with carry use */
#تعریف_کن TOK_SHL     '<' /* shift left */
#تعریف_کن TOK_SAR     '>' /* signed shift right */
#تعریف_کن TOK_SHR     0x8b /* unsigned shift right */
#تعریف_کن TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#تعریف_کن TOK_ARROW   0xa0 /* -> */
#تعریف_کن TOK_DOTS    0xa1 /* three dots */
#تعریف_کن TOK_TWODOTS 0xa2 /* C++ token ? */
#تعریف_کن TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#تعریف_کن TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#تعریف_کن TOK_PPJOIN  (TOK_TWOSHARPS | SYM_فیلد) /* A '##' in a macro to mean pasting */
#تعریف_کن TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#تعریف_کن TOK_A_جمع_کن   0xb0
#تعریف_کن TOK_A_SUB   0xb1
#تعریف_کن TOK_A_MUL   0xb2
#تعریف_کن TOK_A_DIV   0xb3
#تعریف_کن TOK_A_MOD   0xb4
#تعریف_کن TOK_A_AND   0xb5
#تعریف_کن TOK_A_OR    0xb6
#تعریف_کن TOK_A_XOR   0xb7
#تعریف_کن TOK_A_SHL   0xb8
#تعریف_کن TOK_A_SAR   0xb9

#تعریف_کن TOK_تخصیص_بده(t) (t >= TOK_A_جمع_کن && t <= TOK_A_SAR)
#تعریف_کن TOK_تخصیص_بده_OP(t) ("+-*/%&|^<>"[t - TOK_A_جمع_کن])

/* tokens that carry values (in additional token string space / tokc) --> */
#تعریف_کن TOK_CCHAR   0xc0 /* char constant in tokc */
#تعریف_کن TOK_LCHAR   0xc1
#تعریف_کن TOK_CINT    0xc2 /* number in tokc */
#تعریف_کن TOK_CUINT   0xc3 /* unsigned int constant */
#تعریف_کن TOK_CLLONG  0xc4 /* long long constant */
#تعریف_کن TOK_CULLONG 0xc5 /* unsigned long long constant */
#تعریف_کن TOK_CLONG   0xc6 /* long constant */
#تعریف_کن TOK_CULONG  0xc7 /* unsigned long constant */
#تعریف_کن TOK_STR     0xc8 /* pointer to string in tokc */
#تعریف_کن TOK_LSTR    0xc9
#تعریف_کن TOK_CFLOAT  0xca /* float constant */
#تعریف_کن TOK_CDOUBLE 0xcb /* double constant */
#تعریف_کن TOK_CLDOUBLE 0xcc /* long double constant */
#تعریف_کن TOK_PPNUM   0xcd /* preprocessor number */
#تعریف_کن TOK_PPSTR   0xce /* preprocessor string */
#تعریف_کن TOK_LINENUM 0xcf /* line number info */

#تعریف_کن TOK_HAS_مقدار(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#تعریف_کن TOK_EOF       (-1)  /* end of file */
#تعریف_کن TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#تعریف_کن TOK_IDENT 256

تعداد tcc_token {
    TOK_آخرین = TOK_IDENT - 1
#تعریف_کن DEF(id, str) ,id
#ضمن "tcctok.h"
#لغو_تعریف DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#تعریف_کن TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_داده بنية TCCState *tcc_state;
ST_داده فراغ** stk_داده;
ST_داده صحيح nb_stk_داده;
ST_داده صحيح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC حرف *pstrcpy(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s);
ST_FUNC حرف *pstrcat(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s);
ST_FUNC حرف *pstrncpy(حرف *بیرون, اندازه_t buf_اندازه, ثابت حرف *s, اندازه_t رقم);
PUB_FUNC حرف *tcc_basename(ثابت حرف *name);
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC فراغ tcc_free(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc(بیعلامت دراز اندازه);
PUB_FUNC فراغ *tcc_mallocz(بیعلامت دراز اندازه);
PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, بیعلامت دراز اندازه);
PUB_FUNC حرف *tcc_strdup(ثابت حرف *str);

#اگر_تعریف_شده MEM_DEBUG
#تعریف_کن tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کن tcc_malloc(اندازه)        tcc_malloc_debug(اندازه, __FILE__, __LINE__)
#تعریف_کن tcc_mallocz(اندازه)       tcc_mallocz_debug(اندازه, __FILE__, __LINE__)
#تعریف_کن tcc_realloc(ptr,اندازه)   tcc_realloc_debug(ptr, اندازه, __FILE__, __LINE__)
#تعریف_کن tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC فراغ tcc_free_debug(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc_debug(بیعلامت دراز اندازه, ثابت حرف *file, صحيح سطر);
PUB_FUNC فراغ *tcc_mallocz_debug(بیعلامت دراز اندازه, ثابت حرف *file, صحيح سطر);
PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, بیعلامت دراز اندازه, ثابت حرف *file, صحيح سطر);
PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح سطر);
#پایان_اگر

ST_FUNC فراغ libc_free(فراغ *ptr);
/* defined to be not used */
#تعریف_کن حرر(p) use_tcc_free(p)
#تعریف_کن حافظه_بده(s) use_tcc_malloc(s)
#تعریف_کن realloc(p, s) use_tcc_realloc(p, s)
#لغو_تعریف strdup
#تعریف_کن strdup(s) use_tcc_strdup(s)
PUB_FUNC صحيح _tcc_error_noabort(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN فراغ _tcc_error(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC فراغ _tcc_warning(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
#تعریف_کن tcc_داخلی_error(پیام) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,پیام)

/* other utilities */
ST_FUNC فراغ dynarray_جمع_کن(فراغ *ptab, صحيح *nb_ptr, فراغ *داده);
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
#تعریف_کن stk_افزودن(p) dynarray_جمع_کن(&stk_داده, &nb_stk_داده, p)
#تعریف_کن stk_برداشت() (--nb_stk_داده)
/* mark CString on stack for cleanup errors */
#تعریف_کن cstr_new_s(cstr) (cstr_new(cstr), stk_افزودن(&(cstr)->داده))
#تعریف_کن cstr_free_s(cstr) (cstr_free(cstr), stk_برداشت())

ST_FUNC صحيح tcc_جمع_کن_file_داخلی(TCCState *s1, ثابت حرف *filename, صحيح flags);
/* flags: */
#تعریف_کن AFF_PRINT_ERROR     0x10 /* print error if file not found */
#تعریف_کن AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#تعریف_کن AFF_TYPE_BIN        0x40 /* file to add is binary */
#تعریف_کن AFF_کامل_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#تعریف_کن AFF_TYPE_NONE   0
#تعریف_کن AFF_TYPE_C      1
#تعریف_کن AFF_TYPE_ASM    2
#تعریف_کن AFF_TYPE_ASMPP  4
#تعریف_کن AFF_TYPE_LIB    8
#تعریف_کن AFF_TYPE_ماسک   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#تعریف_کن AFF_BINTYPE_REL 1
#تعریف_کن AFF_BINTYPE_DYN 2
#تعریف_کن AFF_BINTYPE_AR  3
#تعریف_کن AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#تعریف_کن FILE_NOT_یافت -2
#تعریف_کن FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#اگر_تعریف_نشده ELF_OBJ_ONLY
ST_FUNC صحيح tcc_جمع_کن_crt(TCCState *s, ثابت حرف *filename);
#پایان_اگر
ST_FUNC صحيح tcc_جمع_کن_dll(TCCState *s, ثابت حرف *filename, صحيح flags);
ST_FUNC صحيح tcc_جمع_کن_support(TCCState *s1, ثابت حرف *filename);
#اگر_تعریف_شده CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_جمع_کن_bcheck(TCCState *s1);
#پایان_اگر
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
ST_FUNC فراغ tcc_جمع_کن_btstub(TCCState *s1);
#پایان_اگر
ST_FUNC فراغ tcc_جمع_کن_pragma_libs(TCCState *s1);
PUB_FUNC صحيح tcc_جمع_کن_library_err(TCCState *s, ثابت حرف *f);
PUB_FUNC فراغ tcc_print_stats(TCCState *s, بیعلامت مجموع_زمان);
PUB_FUNC صحيح tcc_parse_آرگومانها(TCCState *s, صحيح *argc, حرف ***argv);
#اگر_تعریف_شده _WIN32
ST_FUNC حرف *normalize_slashes(حرف *مسیر);
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m);
PUB_FUNC صحيح tcc_fclose(FILE *f);
#وإلا
# define tcc_fopen fopen
# define tcc_fclose fclose
#پایان_اگر
ST_FUNC DLLReference *tcc_جمع_کن_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level);
ST_FUNC حرف *tcc_بارگیری_متن(صحيح fd);
/* for #pragma once */
ST_FUNC صحيح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2);

/* tcc_parse_args return codes: */
#تعریف_کن OPT_HELP 1
#تعریف_کن OPT_HELP2 2
#تعریف_کن OPT_V 3
#تعریف_کن OPT_PRINT_DIRS 4
#تعریف_کن OPT_AR 5
#تعریف_کن OPT_IMPDEF 6
#تعریف_کن OPT_M32 32
#تعریف_کن OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_داده بنية BufferedFile *file;
ST_داده صحيح tok;
ST_داده CValue tokc;
ST_داده ثابت صحيح *macro_ptr;
ST_داده صحيح parse_flags;
ST_داده صحيح tok_flags;
ST_داده CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_داده صحيح tok_ident;
ST_داده TokenSym **جدول_ident;
ST_داده صحيح pp_عبارت;

#تعریف_کن TOK_FLAG_BOL   0x0001 /* beginning of line before */
#تعریف_کن TOK_FLAG_BOF   0x0002 /* beginning of file before */
#تعریف_کن TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#تعریف_کن PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#تعریف_کن PARSE_FLAG_TOK_رقم    0x0002 /* return numbers instead of TOK_PPNUM */
#تعریف_کن PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#تعریف_کن PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#تعریف_کن PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#تعریف_کن PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#تعریف_کن PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#تعریف_کن IS_SPC 1
#تعریف_کن IS_ID  2
#تعریف_کن IS_رقم 4

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
ST_FUNC فراغ انتها_macro(فراغ);
ST_FUNC صحيح مجموعه_idnum(صحيح c, صحيح val);
ST_INLN فراغ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(فراغ);
ST_FUNC فراغ tok_str_free(TokenString *s);
ST_FUNC فراغ tok_str_free_str(صحيح *str);
ST_FUNC فراغ tok_str_جمع_کن(TokenString *s, صحيح t);
ST_FUNC فراغ tok_str_جمع_کن_tok(TokenString *s);
ST_INLN فراغ define_افزودن(صحيح v, صحيح macro_type, صحيح *str, Sym *اولی_arg);
ST_FUNC فراغ define_undef(Sym *s);
ST_INLN Sym *define_پیدا_کن(صحيح v);
ST_FUNC فراغ free_تعریف_میکند(Sym *b);
ST_FUNC فراغ parse_define(فراغ);
ST_FUNC فراغ skip_مقصد_eol(صحيح warn);
ST_FUNC فراغ preprocess(صحيح is_bof);
ST_FUNC فراغ بعدی(فراغ);
ST_INLN فراغ unget_tok(صحيح آخرین_tok);
ST_FUNC فراغ preprocess_شروع(TCCState *s1, صحيح filetype);
ST_FUNC فراغ preprocess_انتها(TCCState *s1);
ST_FUNC فراغ tccpp_new(TCCState *s);
ST_FUNC فراغ tccpp_delete(TCCState *s);
ST_FUNC فراغ tccpp_putfile(ثابت حرف *filename);
ST_FUNC صحيح tcc_preprocess(TCCState *s1);
ST_FUNC فراغ skip(صحيح c);
ST_FUNC NORETURN فراغ expect(ثابت حرف *پیام);
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

#تعریف_کن SYM_POOL_NB (8192 / حجم(Sym))

ST_داده Sym *global_پشته;
ST_داده Sym *local_پشته;
ST_داده Sym *local_label_پشته;
ST_داده Sym *global_label_پشته;
ST_داده Sym *define_پشته;
ST_داده CType int_type, func_old_type, char_اشاره_گر_type;
ST_داده SValue *vtop;
ST_داده صحيح rsym, anon_sym, ind, loc;
ST_داده حرف debug_modes;

ST_داده صحيح nocode_wanted; /* true if no code generation wanted for an expression */
ST_داده صحيح global_عبارت;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_داده CType func_vt; /* current function return type (used by return instruction) */
ST_داده صحيح func_var; /* true if current function is variadic */
ST_داده صحيح func_vc; /* stack address for implicit struct return storage */
ST_داده صحيح func_ind; /* function start address */
ST_داده ثابت حرف *funcname;

ST_FUNC فراغ tccgen_init(TCCState *s1);
ST_FUNC صحيح tccgen_compile(TCCState *s1);
ST_FUNC فراغ tccgen_پایان(TCCState *s1);
ST_FUNC فراغ check_vstack(فراغ);

ST_INLN صحيح is_float(صحيح t);
ST_FUNC صحيح ieee_finite(مزدوج d);
ST_FUNC صحيح exact_log2p1(صحيح i);
ST_FUNC فراغ test_lvalue(فراغ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC فراغ update_storage(Sym *sym);
ST_FUNC فراغ put_extern_sym2(Sym *sym, صحيح sh_رقم, addr_t مقدار, بیعلامت دراز اندازه, صحيح can_جمع_کن_underscore);
ST_FUNC فراغ put_extern_sym(Sym *sym, Section *section, addr_t مقدار, بیعلامت دراز اندازه);
#إذا PTR_اندازه == 4
ST_FUNC فراغ greloc(Section *s, Sym *sym, بیعلامت دراز جابه_جایی, صحيح type);
#پایان_اگر
ST_FUNC فراغ greloca(Section *s, Sym *sym, بیعلامت دراز جابه_جایی, صحيح type, addr_t addend);

ST_INLN فراغ sym_free(Sym *sym);
ST_FUNC Sym *sym_افزودن(صحيح v, CType *type, صحيح r, صحيح c);
ST_FUNC فراغ sym_برداشت(Sym **ptop, Sym *b, صحيح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحيح v, صحيح t, صحيح c);
ST_FUNC Sym *sym_find2(Sym *s, صحيح v);
ST_INLN Sym *sym_پیدا_کن(صحيح v);
ST_FUNC Sym *label_پیدا_کن(صحيح v);
ST_FUNC Sym *label_افزودن(Sym **ptop, صحيح v, صحيح flags);
ST_FUNC فراغ label_برداشت(Sym **ptop, Sym *slast, صحيح keep);
ST_INLN Sym *struct_پیدا_کن(صحيح v);

ST_FUNC Sym *global_identifier_افزودن(صحيح v, صحيح t, صحيح c);
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
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_ARM
ST_FUNC صحيح get_reg_ex(صحيح rc, صحيح rc2);
#پایان_اگر
ST_FUNC فراغ save_reg(صحيح r);
ST_FUNC فراغ save_reg_upstack(صحيح r, صحيح n);
ST_FUNC صحيح get_reg(صحيح rc);
ST_FUNC فراغ save_regs(صحيح n);
ST_FUNC فراغ gaddrof(فراغ);
ST_FUNC صحيح gv(صحيح rc);
ST_FUNC فراغ gv2(صحيح rc1, صحيح rc2);
ST_FUNC فراغ gen_op(صحيح op);
ST_FUNC صحيح type_اندازه(CType *type, صحيح *a);
ST_FUNC فراغ mk_اشاره_گر(CType *type);
ST_FUNC فراغ vstore(فراغ);
ST_FUNC فراغ inc(صحيح post, صحيح c);
ST_FUNC CString* parse_mult_str(ثابت حرف *پیام);
ST_FUNC CString* parse_asm_str(فراغ);
ST_FUNC فراغ indir(فراغ);
ST_FUNC فراغ unary(فراغ);
ST_FUNC فراغ gexpr(فراغ);
ST_FUNC صحيح عبارت_const(فراغ);
#إذا defined CONFIG_TCC_BCHECK || defined TCC_هدف_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, بیعلامت دراز جابه_جایی, بیعلامت دراز اندازه);
#پایان_اگر
#إذا defined TCC_هدف_X86_64 && !defined TCC_هدف_PE
ST_FUNC صحيح classify_x86_64_va_arg(CType *ty);
#پایان_اگر
#اگر_تعریف_شده CONFIG_TCC_BCHECK
ST_FUNC فراغ gbound_آرگومانها(صحيح nb_آرگومانها);
ST_داده صحيح func_bound_جمع_کن_epilog;
#پایان_اگر
ST_FUNC Sym *gfunc_مجموعه_param(Sym *s, صحيح c, صحيح byref);

/* ------------ tccelf.c ------------ */

#تعریف_کن TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#تعریف_کن TCC_OUTPUT_FORMAT_دودویی 1 /* binary image output */
#تعریف_کن TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#تعریف_کن TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#تعریف_کن ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

تعريفنوع بنية {
    بیعلامت صحيح n_strx;         /* index into string table of name */
    بیعلامت حرف n_type;         /* type of symbol */
    بیعلامت حرف n_other;        /* misc info (usually empty) */
    بیعلامت کوتاه n_desc;        /* description field */
    بیعلامت صحيح n_مقدار;        /* value of symbol */
} Stab_Sym;

ST_FUNC فراغ tccelf_new(TCCState *s);
ST_FUNC فراغ tccelf_delete(TCCState *s);
ST_FUNC فراغ tccelf_begin_file(TCCState *s1);
ST_FUNC فراغ tccelf_انتها_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags);
ST_FUNC فراغ section_realloc(Section *sec, بیعلامت دراز new_اندازه);
ST_FUNC اندازه_t section_جمع_کن(Section *sec, addr_t اندازه, صحيح align);
ST_FUNC فراغ *section_ptr_جمع_کن(Section *sec, addr_t اندازه);
ST_FUNC Section *پیدا_کن_section(TCCState *s1, ثابت حرف *name);
ST_FUNC فراغ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت حرف *symtab_name, صحيح sh_type, صحيح sh_flags, ثابت حرف *strtab_name, ثابت حرف *hash_name, صحيح hash_sh_flags);
ST_FUNC فراغ init_symtab(Section *s);

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym);
ST_FUNC صحيح put_elf_sym(Section *s, addr_t مقدار, بیعلامت دراز اندازه, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح مجموعه_elf_sym(Section *s, addr_t مقدار, بیعلامت دراز اندازه, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح پیدا_کن_elf_sym(Section *s, ثابت حرف *name);
ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, بیعلامت دراز جابه_جایی, صحيح type, صحيح نماد);
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, بیعلامت دراز جابه_جایی, صحيح type, صحيح نماد, addr_t addend);

ST_FUNC فراغ resolve_common_syms(TCCState *s1);
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve);
ST_FUNC فراغ relocate_sections(TCCState *s1);

ST_FUNC ssize_t پر_read(صحيح fd, فراغ *buf, اندازه_t شمار_2);
ST_FUNC فراغ *بارگیری_داده(صحيح fd, بیعلامت دراز file_جابه_جایی, بیعلامت دراز اندازه);
ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h);
ST_FUNC صحيح tcc_بارگیری_object_file(TCCState *s1, صحيح fd, بیعلامت دراز file_جابه_جایی);
ST_FUNC صحيح tcc_بارگیری_archive(TCCState *s1, صحيح fd, صحيح alacarte);
ST_FUNC فراغ جمع_کن_array(TCCState *s1, ثابت حرف *sec, صحيح c);

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح شاخص, صحيح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت حرف *name, صحيح err, صحيح forc);
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*نماد_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));
ST_FUNC صحيح مجموعه_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#تعریف_کن for_each_elem(sec, startoff, elem, type) \
    لكل (elem = (type *) sec->داده + startoff; \
         elem < (type *) (sec->داده + sec->داده_جابه_جایی); elem++)

#اگر_تعریف_نشده ELF_OBJ_ONLY
ST_FUNC صحيح tcc_بارگیری_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level);
ST_FUNC صحيح tcc_بارگیری_ldscript(TCCState *s1, صحيح fd);
ST_FUNC فراغ tccelf_جمع_کن_crtbegin(TCCState *s1);
ST_FUNC فراغ tccelf_جمع_کن_crtend(TCCState *s1);
#پایان_اگر
#اگر_تعریف_نشده TCC_هدف_PE
ST_FUNC فراغ tcc_جمع_کن_runtime(TCCState *s1);
#پایان_اگر

/* ------------ xxx-link.c ------------ */

#اگر_تعریف_نشده TCC_هدف_PE
ST_FUNC صحيح کد_reloc (صحيح reloc_type);
ST_FUNC صحيح gotplt_مدخل_type (صحيح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
تعداد gotplt_مدخل {
    NO_GOTPLT_مدخل,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_مدخل,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_مدخل	/* always generate (eg. PLTOFF relocs) */
};
#تعریف_کن NEED_RELOC_TYPE
#إذا !defined TCC_هدف_MACHO || defined TCC_IS_NATIVE
ST_FUNC بیعلامت create_plt_مدخل(TCCState *s1, بیعلامت got_جابه_جایی, بنية sym_attr *attr);
ST_FUNC فراغ relocate_plt(TCCState *s1);
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym); /* in tccelf.c */
#تعریف_کن NEED_BUILD_GOT
#پایان_اگر
#پایان_اگر

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بیعلامت حرف *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_داده ثابت حرف * ثابت هدف_machine_defs;
ST_داده ثابت صحيح reg_classes[NB_REGS];

ST_FUNC فراغ gsym_addr(صحيح t, صحيح a);
ST_FUNC فراغ gsym(صحيح t);
ST_FUNC فراغ بارگیری(صحيح r, SValue *sv);
ST_FUNC فراغ store(صحيح r, SValue *v);
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *align, صحيح *regsize);
ST_FUNC فراغ gfunc_call(صحيح nb_آرگومانها);
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
#اگر_تعریف_نشده TCC_هدف_C67
ST_FUNC فراغ o(بیعلامت صحيح c);
#پایان_اگر
ST_FUNC فراغ gen_vla_sp_save(صحيح addr);
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr);
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align);

ساكن مضمن uint16_t read16le(بیعلامت حرف *p) {
    أرجع p[0] | (uint16_t)p[1] << 8;
}
ساكن مضمن فراغ write16le(بیعلامت حرف *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ساكن مضمن uint32_t read32le(بیعلامت حرف *p) {
  أرجع read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ساكن مضمن فراغ write32le(بیعلامت حرف *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ساكن مضمن فراغ add32le(بیعلامت حرف *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ساكن مضمن uint64_t read64le(بیعلامت حرف *p) {
  أرجع read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ساكن مضمن فراغ write64le(بیعلامت حرف *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ساكن مضمن فراغ add64le(بیعلامت حرف *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64 || defined TCC_هدف_ARM
ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);
#پایان_اگر
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64
ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#پایان_اگر

/* ------------ x86_64-gen.c ------------ */
#اگر_تعریف_شده TCC_هدف_X86_64
ST_FUNC فراغ gen_opl(صحيح op);
#اگر_تعریف_شده TCC_هدف_PE
ST_FUNC فراغ gen_vla_نتیجه(صحيح addr);
#پایان_اگر
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
#پایان_اگر

/* ------------ arm-gen.c ------------ */
#اگر_تعریف_شده TCC_هدف_ARM
#إذا defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت حرف *default_elfinterp(بنية TCCState *s);
#پایان_اگر
ST_FUNC فراغ arm_init(بنية TCCState *s);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#پایان_اگر

/* ------------ arm64-gen.c ------------ */
#اگر_تعریف_شده TCC_هدف_ARM64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gfunc_return(CType *func_type);
ST_FUNC فراغ gen_va_شروع(فراغ);
ST_FUNC فراغ gen_va_arg(CType *t);
ST_FUNC فراغ gen_clear_cache(فراغ);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#پایان_اگر

/* ------------ riscv64-gen.c ------------ */
#اگر_تعریف_شده TCC_هدف_RISCV64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gen_va_شروع(فراغ);
ST_FUNC فراغ arch_transfer_ret_regs(صحيح);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
ST_FUNC فراغ gen_clear_cache(فراغ);
#پایان_اگر

/* ------------ c67-gen.c ------------ */
#اگر_تعریف_شده TCC_هدف_C67
#پایان_اگر

/* ------------ tcccoff.c ------------ */
#اگر_تعریف_شده TCC_هدف_COFF
ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحيح tcc_بارگیری_coff(TCCState * s1, صحيح fd);
#پایان_اگر

/* ------------ tccasm.c ------------ */
ST_FUNC فراغ asm_instr(فراغ);
ST_FUNC فراغ asm_global_instr(فراغ);
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess);
#اگر_تعریف_شده CONFIG_TCC_ASM
ST_FUNC صحيح پیدا_کن_constraint(ASMOperand *operands, صحيح nb_operands, ثابت حرف *name, ثابت حرف **pp);
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym);
ST_FUNC فراغ asm_عبارت(TCCState *s1, عبارت_مقدار *pe);
ST_FUNC صحيح asm_int_عبارت(TCCState *s1);
#إذا PTR_اندازه == 8
ST_FUNC فراغ gen_expr64(عبارت_مقدار *pe);
#پایان_اگر
/* ------------ i386-asm.c ------------ */
ST_FUNC فراغ gen_expr32(عبارت_مقدار *pe);
ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode);
ST_FUNC صحيح asm_parse_regvar(صحيح t);
ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, ثابت uint8_t *clobber_regs, صحيح *pout_reg);
ST_FUNC فراغ subst_asm_عملوند(CString *جمع_کن_str, SValue *sv, صحيح modifier);
ST_FUNC فراغ asm_gen_کد(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, صحيح is_output, uint8_t *clobber_regs, صحيح بیرون_reg);
ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str);
#پایان_اگر

/* ------------ tccpe.c -------------- */
#اگر_تعریف_شده TCC_هدف_PE
ST_FUNC صحيح pe_بارگیری_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename);
ST_FUNC صحيح pe_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t مقدار);
ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg);
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64
#پایان_اگر
#إذا defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
ST_FUNC فراغ pe_جمع_کن_unwind_داده(بیعلامت شروع, بیعلامت انتها, بیعلامت پشته);
#پایان_اگر
PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#پایان_اگر
#تعریف_کن ST_ASM_مجموعه 0x04

/* ------------ tccmacho.c ----------------- */
#اگر_تعریف_شده TCC_هدف_MACHO
ST_FUNC صحيح macho_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح macho_بارگیری_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
ST_FUNC صحيح macho_بارگیری_tbd(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
#اگر_تعریف_شده TCC_IS_NATIVE
ST_FUNC فراغ tcc_جمع_کن_macos_sdkpath(TCCState* s);
ST_FUNC حرف* macho_tbd_soname(صحيح fd);
#پایان_اگر
#پایان_اگر
/* ------------ tccrun.c ----------------- */
#اگر_تعریف_شده TCC_IS_NATIVE
#اگر_تعریف_شده CONFIG_TCC_STATIC
#تعریف_کن RTLD_LAZY       0x001
#تعریف_کن RTLD_NOW        0x002
#تعریف_کن RTLD_GLOBAL     0x100
#تعریف_کن RTLD_DEFAULT    عدم
/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ST_FUNC فراغ dlclose(فراغ *p);
ST_FUNC ثابت حرف *dlerror(فراغ);
ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *نماد);
#پایان_اگر
ST_FUNC فراغ tcc_پیاپی_free(TCCState *s1);
#پایان_اگر

/* ------------ tcctools.c ----------------- */
#إذا 0 /* included in tcc.c */
ST_FUNC صحيح tcc_tool_ar(TCCState *s, صحيح argc, حرف **argv);
#اگر_تعریف_شده TCC_هدف_PE
ST_FUNC صحيح tcc_tool_impdef(TCCState *s, صحيح argc, حرف **argv);
#پایان_اگر
ST_FUNC صحيح tcc_tool_cross(TCCState *s, حرف **argv, صحيح option);
ST_FUNC صحيح gen_makedeps(TCCState *s, ثابت حرف *هدف, ثابت حرف *filename);
#پایان_اگر

/* ------------ tccdbg.c ------------ */

ST_FUNC فراغ tcc_debug_new(TCCState *s);

ST_FUNC فراغ tcc_debug_شروع(TCCState *s1);
ST_FUNC فراغ tcc_debug_انتها(TCCState *s1);
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1);

ST_FUNC فراغ tcc_debug_سطر(TCCState *s1);
ST_FUNC فراغ tcc_جمع_کن_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC فراغ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح مقدار);
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح اندازه);
ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_رقم, صحيح sym_bind, صحيح sym_type);
ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح مقدار);
ST_FUNC فراغ tcc_debug_fix_forw(TCCState *s1, CType *t);

#إذا !(defined ELF_OBJ_ONLY || defined TCC_هدف_ARM || defined TARGETOS_BSD)
ST_FUNC فراغ tcc_eh_قاب_شروع(TCCState *s1);
ST_FUNC فراغ tcc_eh_قاب_انتها(TCCState *s1);
ST_FUNC فراغ tcc_eh_قاب_hdr(TCCState *s1, صحيح final);
#تعریف_کن TCC_EH_قاب 1
#پایان_اگر

ST_FUNC فراغ tcc_tcov_شروع(TCCState *s1);
ST_FUNC فراغ tcc_tcov_انتها(TCCState *s1);
ST_FUNC فراغ tcc_tcov_check_سطر(TCCState *s1, صحيح شروع);
ST_FUNC فراغ tcc_tcov_بلوک_انتها(TCCState *s1, صحيح سطر);
ST_FUNC فراغ tcc_tcov_بلوک_begin(TCCState *s1);
ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1);

#تعریف_کن stab_section            s1->stab_section
#تعریف_کن stabstr_section         stab_section->link
#تعریف_کن tcov_section            s1->tcov_section
#تعریف_کن eh_قاب_section        s1->eh_قاب_section
#تعریف_کن eh_قاب_hdr_section    s1->eh_قاب_hdr_section
#تعریف_کن dwarf_info_section      s1->dwarf_info_section
#تعریف_کن dwarf_abbrev_section    s1->dwarf_abbrev_section
#تعریف_کن dwarf_سطر_section      s1->dwarf_سطر_section
#تعریف_کن dwarf_aranges_section   s1->dwarf_aranges_section
#تعریف_کن dwarf_str_section       s1->dwarf_str_section
#تعریف_کن dwarf_سطر_str_section  s1->dwarf_سطر_str_section

#تعریف_کن DWARF_MAX_128	((8 * حجم (int64_t) + 6) / 7)
#تعریف_کن	dwarf_read_1(ln,انتها) \
	((ln) < (انتها) ? *(ln)++ : 0)
#تعریف_کن	dwarf_read_2(ln,انتها) \
	((ln) + 1 < (انتها) ? read16le(((ln)+=2) - 2) : 0)
#تعریف_کن	dwarf_read_4(ln,انتها) \
	((ln) + 3 < (انتها) ? read32le(((ln)+=4) - 4) : 0)
#تعریف_کن	dwarf_read_8(ln,انتها) \
	((ln) + 7 < (انتها) ? read64le(((ln)+=8) - 8) : 0)
ساكن مضمن uint64_t
dwarf_read_uleb128(بیعلامت حرف **ln, بیعلامت حرف *انتها)
{
    بیعلامت حرف *cp = *ln;
    uint64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, انتها);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0)
	    اكسر;
    }
    *ln = cp;
    أرجع retval;
}
ساكن مضمن int64_t
dwarf_read_sleb128(بیعلامت حرف **ln, بیعلامت حرف *انتها)
{
    بیعلامت حرف *cp = *ln;
    int64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, انتها);
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
#اگر_تعریف_شده TCC_هدف_MACHO
# define DEFAULT_DWARF_نسخه 2
#وإلا
# define DEFAULT_DWARF_نسخه 5
#پایان_اگر

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#اگر_تعریف_نشده CONFIG_DWARF_نسخه
# define CONFIG_DWARF_نسخه 0
#پایان_اگر

#إذا defined TCC_هدف_X86_64
# define R_داده_32_DW R_X86_64_32
#وإلا
# define R_داده_32_DW R_داده_32
#پایان_اگر

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
    dispatch_semaphore_wait(p->sem, DISPATCH_زمان_FOREVER);
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
#پایان_اگر
#تعریف_کن TCC_SEM(s) TCCSem s
#تعریف_کن WAIT_SEM wait_sem
#تعریف_کن POST_SEM post_sem
#وإلا
#تعریف_کن TCC_SEM(s)
#تعریف_کن WAIT_SEM(p)
#تعریف_کن POST_SEM(p)
#پایان_اگر

/********************************************************/
#لغو_تعریف ST_داده
#إذا ONE_منبع
#تعریف_کن ST_داده ساكن
#وإلا
#تعریف_کن ST_داده
#پایان_اگر
/********************************************************/

#تعریف_کن متن_section        TCC_STATE_VAR(متن_section)
#تعریف_کن داده_section        TCC_STATE_VAR(داده_section)
#تعریف_کن rodata_section      TCC_STATE_VAR(rodata_section)
#تعریف_کن bss_section         TCC_STATE_VAR(bss_section)
#تعریف_کن common_section      TCC_STATE_VAR(common_section)
#تعریف_کن cur_متن_section    TCC_STATE_VAR(cur_متن_section)
#تعریف_کن bounds_section      TCC_STATE_VAR(bounds_section)
#تعریف_کن lbounds_section     TCC_STATE_VAR(lbounds_section)
#تعریف_کن symtab_section      TCC_STATE_VAR(symtab_section)
#تعریف_کن gnu_ext             TCC_STATE_VAR(gnu_ext)
#تعریف_کن tcc_error_noabort   TCC_مجموعه_STATE(_tcc_error_noabort)
#تعریف_کن tcc_error           TCC_مجموعه_STATE(_tcc_error)
#تعریف_کن tcc_warning         TCC_مجموعه_STATE(_tcc_warning)

#تعریف_کن مجموع_idents        TCC_STATE_VAR(مجموع_idents)
#تعریف_کن مجموع_سطرها         TCC_STATE_VAR(مجموع_سطرها)
#تعریف_کن مجموع_بایتها         TCC_STATE_VAR(مجموع_بایتها)

PUB_FUNC فراغ tcc_enter_state(TCCState *s1);
PUB_FUNC فراغ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#تعریف_کن tcc_warning_c(sw) TCC_مجموعه_STATE((\
    tcc_state->warn_رقم = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#پایان_اگر /* _TCC_H */

#لغو_تعریف TCC_STATE_VAR
#لغو_تعریف TCC_مجموعه_STATE

#اگر_تعریف_شده USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_مجموعه_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#وإلا
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_مجموعه_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#پایان_اگر
