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

#جے_بنا_تعریف _TCC_H
#تعریف_کرو _TCC_H

#تعریف_کرو GNU_سروت
#تعریف_کرو DARWIN_C_سروت
#ضمن "config.h"

#ضمن <stdarg.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#جے_تعریف_شدہ __TINYC__
# undef __attribute__
#جے_انت
#ضمن <string.h>
#ضمن <errno.h>
#ضمن <math.h>
#ضمن <fcntl.h>
#ضمن <setjmp.h>
#ضمن <time.h>

#جے_بنا_تعریف _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
خارجي عائم strtof (ثابت حرف *__nptr, حرف **__endptr);
خارجي لما مزدوج strtold (ثابت حرف *__nptr, حرف **__endptr);
#جے_انت

#جے_تعریف_شدہ _WIN32
# define WIN32_LEAN_AND_اوسط 1
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
#  define strtold (لما مزدوج)strtod
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
#جے_انت

#جے_بنا_تعریف O_ثنائی_2
# define O_ثنائی_2 0
#جے_انت

#جے_بنا_تعریف offsetof
#جے_تعریف_شدہ __clang__ // clang -fsanitize compains about: NULL+value
#تعریف_کرو offsetof(type, میدان) __builtin_offsetof(type, میدان)
#وإلا
#تعریف_کرو offsetof(type, میدان) ((ناپ_t) &((type *)0)->میدان)
#جے_انت
#جے_انت

#جے_بنا_تعریف countof
#تعریف_کرو countof(tab) (حجم(tab) / حجم((tab)[0]))
#جے_انت

#جے_تعریف_شدہ _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#وإلا
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (لکھو, (x), (y))))
#جے_انت

#جے_تعریف_شدہ _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#وإلا
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#جے_انت

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
#إذا !defined(TCC_نشانہ_I386) && !defined(TCC_نشانہ_ARM) && \
    !defined(TCC_نشانہ_ARM64) && !defined(TCC_نشانہ_C67) && \
    !defined(TCC_نشانہ_X86_64) && !defined(TCC_نشانہ_RISCV64)
# إذا defined __x86_64__
#  define TCC_نشانہ_X86_64
# elif defined __arm__
#  define TCC_نشانہ_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_نشانہ_ARM64
# elif defined __riscv
#  define TCC_نشانہ_RISCV64
# وإلا
#  define TCC_نشانہ_I386
# endif
# ifdef _WIN32
#  define TCC_نشانہ_PE 1
# endif
# ifdef __APPLE__
#  define TCC_نشانہ_MACHO 1
# endif
#جے_انت

/* only native compiler supports -run */
#إذا defined _WIN32 == defined TCC_نشانہ_PE \
    && defined __APPLE__ == defined TCC_نشانہ_MACHO
# إذا defined __i386__ && defined TCC_نشانہ_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_نشانہ_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_نشانہ_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_نشانہ_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_نشانہ_RISCV64
#  define TCC_IS_NATIVE
# endif
#جے_انت

#إذا defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#وإلا
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#جے_انت

#إذا defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#وإلا
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#جے_انت

#إذا defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#وإلا
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#جے_انت

#إذا defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وإلاإذا !(defined TCC_نشانہ_PE || defined TCC_نشانہ_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#جے_انت

#إذا defined TCC_نشانہ_PE || defined TCC_نشانہ_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#وإلا
# define TCC_نشانہ_UNIX 1
#جے_انت

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#إذا defined TCC_نشانہ_PE \
    || (defined TCC_نشانہ_MACHO && defined TCC_نشانہ_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#جے_انت

#جے_تعریف_شدہ CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#جے_انت

/* support using libtcc from threads */
#جے_بنا_تعریف CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#جے_انت

/* ------------ path configuration ------------ */

#جے_بنا_تعریف CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#جے_انت

#إذا !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#جے_انت

#جے_تعریف_شدہ CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#وإلا
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#جے_انت

/* path to find crt1.o, crti.o and crtn.o */
#جے_بنا_تعریف CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#جے_انت

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#جے_بنا_تعریف CONFIG_TCC_SYSINCLUDEPATHS
# إذا defined TCC_نشانہ_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# وإلا
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#جے_انت

/* library search paths */
#جے_بنا_تعریف CONFIG_TCC_LIBPATHS
# إذا defined TCC_نشانہ_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# وإلا
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#جے_انت

/* name of ELF interpreter */
#جے_بنا_تعریف CONFIG_TCC_ELFINTERP
# إذا defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_نشانہ_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_نشانہ_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_نشانہ_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_نشانہ_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_نشانہ_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# وإلا
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#جے_انت

/* (target specific) libtcc1.a */
#جے_بنا_تعریف TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#جے_انت

/* <cross-prefix-to->libtcc1.a */
#جے_بنا_تعریف CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#جے_انت

/* -------------------------------------------- */

#ضمن "libtcc.h"
#ضمن "elf.h"
#ضمن "stab.h"
#ضمن "dwarf.h"

/* -------------------------------------------- */

#جے_بنا_تعریف PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#جے_انت

#جے_بنا_تعریف ONE_سروت
# define ONE_سروت 0
#جے_انت

#إذا ONE_سروت
#تعریف_کرو ST_INLN ساكن مضمن
#تعریف_کرو ST_FUNC ساكن
#تعریف_کرو ST_انکڑے ساكن
#وإلا
#تعریف_کرو ST_INLN
#تعریف_کرو ST_FUNC
#تعریف_کرو ST_انکڑے خارجي
#جے_انت

#جے_تعریف_شدہ TCC_PROFILE /* profile all functions */
# define ساكن
# define مضمن
#جے_انت

/* -------------------------------------------- */
/* include the target specific definitions */

#تعریف_کرو نشانہ_DEFS_ONLY
#جے_تعریف_شدہ TCC_نشانہ_I386
# include "i386-gen.c"
# include "i386-link.c"
#وإلاإذا defined TCC_نشانہ_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#وإلاإذا defined TCC_نشانہ_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#وإلاإذا defined TCC_نشانہ_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#وإلاإذا defined TCC_نشانہ_C67
# define TCC_نشانہ_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#وإلاإذا defined(TCC_نشانہ_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#وإلا
#غلطی unknown نشانہ
#جے_انت
#تعریف_رد نشانہ_DEFS_ONLY

/* -------------------------------------------- */

#إذا PTR_ناپ == 8
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
#جے_انت
/* target address type */
#تعریف_کرو addr_t ElfW(Addr)
#تعریف_کرو ElfSym ElfW(Sym)

#إذا PTR_ناپ == 8 && !defined TCC_نشانہ_PE
# define LONG_ناپ 8
#وإلا
# define LONG_ناپ 4
#جے_انت

/* -------------------------------------------- */

#تعریف_کرو INCLUDE_ڈھیر_ناپ  32
#تعریف_کرو IFDEF_ڈھیر_ناپ    64
#تعریف_کرو VSTACK_ناپ         512
#تعریف_کرو STRING_MAX_ناپ     1024
#تعریف_کرو TOKSTR_MAX_ناپ     256
#تعریف_کرو PACK_ڈھیر_ناپ     8

#تعریف_کرو TOK_HASH_ناپ       16384 /* must be a power of two */
#تعریف_کرو TOK_ALLOC_INCR      512  /* must be a power of two */
#تعریف_کرو TOK_MAX_ناپ        4 /* token max size in int unit when stored in string */

/* token symbol management */
تعريفنوع بنية TokenSym {
    بنية TokenSym *hash_اگلا;
    بنية Sym *sym_define; /* direct pointer to define */
    بنية Sym *sym_label; /* direct pointer to label */
    بنية Sym *sym_struct; /* direct pointer to structure */
    بنية Sym *sym_identifier; /* direct pointer to identifier */
    صحيح tok; /* token number */
    صحيح len;
    حرف str[1];
} TokenSym;

#جے_تعریف_شدہ TCC_نشانہ_PE
تعريفنوع بنانشانی چھوٹا nwchar_t;
#وإلا
تعريفنوع صحيح nwchar_t;
#جے_انت

تعريفنوع بنية CString {
    صحيح ناپ; /* size in bytes */
    صحيح ناپ_allocated;
    حرف *انکڑے; /* nwchar_t* in cases */
} CString;

/* type definition */
تعريفنوع بنية CType {
    صحيح t;
    بنية Sym *ref;
} CType;

/* long double words on host(!) platform */
#تعریف_کرو LDOUBLE_الفاظ ((حجم(لما مزدوج)+3)/4)

/* constant value */
تعريفنوع اتحاد CValue {
    لما مزدوج ld;
    مزدوج d;
    عائم f;
    uint64_t i;
    بنية {
        حرف *انکڑے;
        صحيح ناپ;
    } str;
    صحيح tab[LDOUBLE_الفاظ];
} CValue;

/* value on stack */
تعريفنوع بنية SValue {
    CType type;      /* type */
    بنانشانی چھوٹا r;      /* register + flags */
    بنانشانی چھوٹا r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اتحاد {
      بنية { صحيح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اتحاد {
      بنية { بنانشانی چھوٹا cmp_op, cmp_r; }; /* VT_CMP operation */
      بنية Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
بنية SymAttr {
    بنانشانی چھوٹا
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
    بنانشانی
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_دلیلاں   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
تعريفنوع بنية Sym {
    صحيح v; /* symbol token */
    بنانشانی چھوٹا r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
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
        لما لما enum_val; /* enum constant if IS_ENUM_VAL */
        صحيح *d; /* define token stream */
        بنية Sym *cleanup_func;
    };

    CType type; /* associated type */
    اتحاد {
        بنية Sym *اگلا; /* next related symbol (for fields and anoms) */
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
    بنانشانی لما انکڑے_وتھ; /* current data offset */
    بنانشانی حرف *انکڑے;       /* section data */
    بنانشانی لما انکڑے_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحيح sh_name;             /* elf section name (only used during output) */
    صحيح sh_عدد;              /* elf section number */
    صحيح sh_type;             /* elf section type */
    صحيح sh_flags;            /* elf section flags */
    صحيح sh_info;             /* elf section info */
    صحيح sh_addralign;        /* elf section alignment */
    صحيح sh_entsize;          /* elf entry size */
    بنانشانی لما sh_ناپ;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    بنانشانی لما sh_وتھ; /* file offset */
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
    بنانشانی حرف لبھیا, اشاریہ;
    حرف name[1];
} DLLReference;

/* -------------------------------------------------- */

#تعریف_کرو SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#تعریف_کرو SYM_میدان      0x20000000 /* struct/union field symbol space */
#تعریف_کرو SYM_پہلا_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#تعریف_کرو FUNC_NEW       1 /* ansi function prototype */
#تعریف_کرو FUNC_OLD       2 /* old function prototype */
#تعریف_کرو FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#تعریف_کرو FUNC_CDECL     0 /* standard c call */
#تعریف_کرو FUNC_STDCALL   1 /* pascal c call */
#تعریف_کرو FUNC_FASTCALL1 2 /* first param in %eax */
#تعریف_کرو FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#تعریف_کرو FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#تعریف_کرو FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#تعریف_کرو FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#تعریف_کرو MACRO_OBJ      0 /* object like macro */
#تعریف_کرو MACRO_FUNC     1 /* function like macro */
#تعریف_کرو MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#تعریف_کرو LABEL_DEFINED  0 /* label is defined */
#تعریف_کرو LABEL_FORWARD  1 /* label is forward defined */
#تعریف_کرو LABEL_DECLARED 2 /* label is declared but never used */
#تعریف_کرو LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#تعریف_کرو TYPE_ABSTRACT  1 /* type without variable */
#تعریف_کرو TYPE_سدھا    2 /* type with variable */
#تعریف_کرو TYPE_PARAM     4 /* type declares function parameter */
#تعریف_کرو TYPE_NEST      8 /* nested call to post_type */

#تعریف_کرو IO_BUF_ناپ 8192

تعريفنوع بنية BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_سرا;
    صحيح fd;
    بنية BufferedFile *prev;
    صحيح سطر_عدد;    /* current line number - here to simplify code */
    صحيح سطر_ref;    /* tcc -E: last printed line */
    صحيح ifndef_macro;  /* #ifndef macro / #endif search */
    صحيح ifndef_macro_saved; /* saved ifndef_macro */
    صحيح *ifdef_ڈھیر_ptr; /* ifdef_stack value at the start of the file */
    صحيح include_اگلا_اشاریہ; /* next search path */
    صحيح prev_tok_flags; /* saved tok_flags */
    حرف filename[1024];    /* filename */
    حرف *true_filename; /* filename not modified by # line directive */
    بنانشانی حرف unget[4];
    بنانشانی حرف بفر[1]; /* extra size for CH_EOB char */
} BufferedFile;

#تعریف_کرو CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#تعریف_کرو CH_EOF   (-1)   /* end of file */

/* used to record tokens */
تعريفنوع بنية TokenString {
    صحيح *str;
    صحيح len;
    صحيح need_spc;
    صحيح allocated_len;
    صحيح آخری_سطر_عدد;
    صحيح save_سطر_عدد;
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
    صحيح alias_نشانہ; /* token */
    صحيح asm_label; /* associated asm label */
    حرف attr_منوال; /* __attribute__((__mode__(...))) */
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
    صحيح hash_اگلا; /* -1 if none */
    حرف filename[1]; /* path specified in #include */
} CachedInclude;

#تعریف_کرو CACHED_INCLUDES_HASH_ناپ 32

#جے_تعریف_شدہ CONFIG_TCC_ASM
تعريفنوع بنية اظہاریہ_قدر {
    uint64_t v;
    Sym *sym;
    صحيح pcrel;
} اظہاریہ_قدر;

#تعریف_کرو MAX_ASM_OPERANDS 30
تعريفنوع بنية ASMOperand {
    صحيح id; /* GCC 3 optional identifier (0 if number only supported) */
    حرف constraint[16];
    حرف asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحيح ref_اشاریہ; /* if >= 0, gives reference to a output constraint */
    صحيح داخلہ_اشاریہ; /* if >= 0, gives reference to an input constraint */
    صحيح ترجیح; /* priority, used to assign registers */
    صحيح reg; /* if >= 0, register number used for this operand */
    صحيح is_llong; /* true if double register value */
    صحيح is_حافظہ; /* true if memory operand */
    صحيح is_rw;     /* for '+' modifier */
    صحيح is_label;  /* for asm goto */
} ASMOperand;
#جے_انت

/* extra symbol attributes (not in symbol table) */
بنية sym_attr {
    بنانشانی got_وتھ;
    بنانشانی plt_وتھ;
    صحيح plt_sym;
    صحيح dyn_اشاریہ;
    بنانشانی حرف linker_sym:1;
#جے_تعریف_شدہ TCC_نشانہ_ARM
    بنانشانی حرف plt_thumb_stub:1;
#جے_انت
};

بنية TCCState {
    بنانشانی حرف verbose; /* if true, display some information during compilation */
    بنانشانی حرف nostdinc; /* if true, no standard headers are added */
    بنانشانی حرف nostdlib; /* if true, no standard libraries are added */
    بنانشانی حرف nostdlib_paths; /* if true, the default paths are not searched for libraries */
    بنانشانی حرف nocommon; /* if true, do not use common symbols for .bss data */
    بنانشانی حرف static_link; /* if true, static linking is performed */
    بنانشانی حرف rdynamic; /* if true, all symbols are exported */
    بنانشانی حرف symbolic; /* if true, resolve symbols in the current module first */
    بنانشانی حرف znodelete; /* Set DF_1_NODELETE in dynamic section */
    بنانشانی حرف filetype; /* file type for compilation (NONE,C,ASM) */
    بنانشانی حرف optimize; /* only to #define __OPTIMIZE__ */
    بنانشانی حرف option_pthread; /* -pthread option */
    بنانشانی حرف enable_new_dtags; /* -Wl,--enable-new-dtags */
    بنانشانی صحيح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    بنانشانی حرف char_is_unsigned;
    بنانشانی حرف leading_underscore;
    بنانشانی حرف ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    بنانشانی حرف dollars_وچ_identifiers;  /* allows '$' char in identifiers */
    بنانشانی حرف ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    بنانشانی حرف الٹ_funcargs; /* if true, evaluate last function arg first */
    بنانشانی حرف gnu89_inline; /* treat 'extern inline' like 'static inline' */
    بنانشانی حرف unwind_tables; /* create eh_frame section */

    /* warning switches */
    بنانشانی حرف warn_none;
    بنانشانی حرف warn_all;
    بنانشانی حرف warn_error;
    بنانشانی حرف warn_write_لڑیاں;
    بنانشانی حرف warn_unsupported;
    بنانشانی حرف warn_implicit_function_declaration;
    بنانشانی حرف warn_discarded_qualifiers;
    #تعریف_کرو WARN_ON  1 /* warning is on (-Woption) */
    بنانشانی حرف warn_عدد; /* temp var for tcc_warning_c() */

    بنانشانی حرف option_r; /* option -r */
    بنانشانی حرف do_bench; /* option -bench */
    بنانشانی حرف just_deps; /* option -M  */
    بنانشانی حرف gen_deps; /* option -MD  */
    بنانشانی حرف include_sys_deps; /* option -MD  */
    بنانشانی حرف gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    بنانشانی حرف do_debug;
    بنانشانی حرف dwarf;
    بنانشانی حرف do_backtrace;
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    بنانشانی حرف do_bounds_check;
#جے_انت
    بنانشانی حرف test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    بنانشانی حرف gnu_ext;
    /* use TinyCC extensions */
    بنانشانی حرف tcc_ext;

    بنانشانی حرف dflag; /* -dX value */
    بنانشانی حرف Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#جے_تعریف_شدہ TCC_نشانہ_X86_64
    بنانشانی حرف nosse; /* For -mno-sse support. */
#جے_انت
#جے_تعریف_شدہ TCC_نشانہ_ARM
    بنانشانی حرف float_abi; /* float ABI of the generated code*/
#جے_انت

    بنانشانی حرف has_متن_addr;
    addr_t متن_addr; /* address of text section */
    بنانشانی section_align; /* section alignment */
#جے_تعریف_شدہ TCC_نشانہ_I386
    صحيح seg_ناپ; /* 32. Can be 16 with i386 assembler (.code16) */
#جے_انت

    حرف *tcc_lib_رستہ; /* CONFIG_TCCDIR or -B option */
    حرف *soname; /* as specified on the command line (-soname) */
    حرف *rpath; /* as specified on the command line (-Wl,-rpath=) */
    حرف *elfint; /* -Wl,-I... on command line */
    حرف *elf_entryname; /* "_start" unless set */
    حرف *init_علامت; /* symbols to call at load-time (not used currently) */
    حرف *fini_علامت; /* symbols to call at unload-time (not used currently) */
    حرف *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحيح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحيح output_format;
    /* nth test to run with -dt -run */
    صحيح لگاتار_test;

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
    صحيح error_سیٹ_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحيح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    حرف **نشانہ_deps;
    صحيح nb_نشانہ_deps;

    /* compilation */
    BufferedFile *include_ڈھیر[INCLUDE_ڈھیر_ناپ];
    BufferedFile **include_ڈھیر_ptr;

    صحيح ifdef_ڈھیر[IFDEF_ڈھیر_ناپ];
    صحيح *ifdef_ڈھیر_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحيح cached_includes_hash[CACHED_INCLUDES_HASH_ناپ];
    CachedInclude **cached_includes;
    صحيح nb_cached_includes;

    /* #pragma pack stack */
    صحيح pack_ڈھیر[PACK_ڈھیر_ناپ];
    صحيح *pack_ڈھیر_ptr;
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
    Section *متن_section, *انکڑے_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_متن_section; /* current section where function code is generated */
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#جے_انت
    /* symbol section */
    اتحاد { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_چوکھٹا_section;
    Section *eh_چوکھٹا_hdr_section;
    بنانشانی لما eh_شروع;
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
    #تعریف_کرو qrel s1->qrel

    addr_t tls_شروع, tls_سرا;

#جے_تعریف_شدہ TCC_نشانہ_RISCV64
    بنية pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحيح nb_pcrel_hi_entries;
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_PE
    /* PE info */
    صحيح pe_subsystem;
    بنانشانی pe_characteristics;
    بنانشانی pe_dll_characteristics;
    بنانشانی pe_file_align;
    بنانشانی pe_ڈھیر_ناپ;
    addr_t pe_imagebase;
# إذا defined(TCC_نشانہ_X86_64) || defined(TCC_نشانہ_ARM64)
    Section *uw_pdata;
    صحيح uw_sym;
    صحيح uw_xsym;
    بنانشانی uw_offs;
# endif
#جے_انت

#إذا defined TCC_نشانہ_MACHO
    حرف *install_name;
    uint32_t compatibility_نسخہ;
    uint32_t current_نسخہ;
#جے_انت

#جے_بنا_تعریف ELF_OBJ_ONLY
    صحيح nb_sym_versions;
    بنية sym_نسخہ *sym_versions;
    صحيح nb_sym_منزل_نسخہ;
    صحيح *sym_منزل_نسخہ;
    صحيح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#جے_انت

#جے_تعریف_شدہ TCC_IS_NATIVE
    ثابت حرف *لگاتار_main; /* entry for tcc_run() */
    فراغ *لگاتار_ptr; /* runtime_memory */
    بنانشانی لگاتار_ناپ; /* size of runtime_memory  */
    ثابت حرف *لگاتار_stdin; /* custom stdin file for run_main */
#جے_تعریف_شدہ _WIN64
    فراغ *لگاتار_function_جدول; /* unwind data */
#جے_انت
    بنية TCCState *اگلا;
    بنية rt_context *rc; /* pointer to backtrace info block */
    فراغ *لگاتار_lj, *لگاتار_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    فراغ *bt_انکڑے;
#جے_انت

#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    صحيح rt_عدد_callers;
#جے_انت

    /* benchmark info */
    صحيح کل_idents;
    صحيح کل_سطریں;
    بنانشانی صحيح کل_بائٹاں;
    بنانشانی صحيح کل_output[4];

    /* used by tcc_load_ldscript */
    بنانشانی حرف *ld_p; /* text pointer */

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
#تعریف_کرو VT_VALMASK   0x003f  /* mask for value location, register or: */
#تعریف_کرو VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#تعریف_کرو VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#تعریف_کرو VT_LOCAL     0x0032  /* offset on stack */
#تعریف_کرو VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#تعریف_کرو VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#تعریف_کرو VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#تعریف_کرو VT_LVAL      0x0100  /* var is an lvalue */
#تعریف_کرو VT_SYM       0x0200  /* a symbol value is added */
#تعریف_کرو VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#تعریف_کرو VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#تعریف_کرو VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#تعریف_کرو VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#تعریف_کرو VT_BTYPE       0x000f  /* mask for basic type */
#تعریف_کرو VT_VOID             0  /* void type */
#تعریف_کرو VT_BYTE             1  /* signed byte type */
#تعریف_کرو VT_SHORT            2  /* short type */
#تعریف_کرو VT_INT              3  /* integer type */
#تعریف_کرو VT_LLONG            4  /* 64 bit integer */
#تعریف_کرو VT_PTR              5  /*اشارہ_گر*/
#تعریف_کرو VT_FUNC             6  /* function type */
#تعریف_کرو VT_STRUCT           7  /* struct/union definition */
#تعریف_کرو VT_FLOAT            8  /* IEEE float */
#تعریف_کرو VT_DOUBLE           9  /* IEEE double */
#تعریف_کرو VT_LDOUBLE         10  /* IEEE long double */
#تعریف_کرو VT_BOOL            11  /* ISOC99 boolean type */
#تعریف_کرو VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#تعریف_کرو VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#تعریف_کرو VT_UNSIGNED    0x0010  /* unsigned type */
#تعریف_کرو VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#تعریف_کرو VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#تعریف_کرو VT_BITFIELD    0x0080  /* bitfield modifier */
#تعریف_کرو VT_CONSTANT    0x0100  /* const modifier */
#تعریف_کرو VT_VOLATILE    0x0200  /* volatile modifier */
#تعریف_کرو VT_RESTRICT    0x0400  /* restrict modifier */
#تعریف_کرو VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#تعریف_کرو VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#تعریف_کرو VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#تعریف_کرو VT_EXTERN  0x00002000  /* extern definition */
#تعریف_کرو VT_STATIC  0x00004000  /* static variable */
#تعریف_کرو VT_TYPEDEF 0x00008000  /* typedef definition */
#تعریف_کرو VT_INLINE  0x00010000  /* inline definition */
#تعریف_کرو VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#تعریف_کرو VT_STRUCT_کھسکاؤ 20     /* shift for bitfield shift values (32 - 2*6) */
#تعریف_کرو VT_STRUCT_نقاب (((1U << (6+6)) - 1) << VT_STRUCT_کھسکاؤ | VT_BITFIELD)
#تعریف_کرو ثنائی_ہندسہ_POS(t) (((t) >> VT_STRUCT_کھسکاؤ) & 0x3f)
#تعریف_کرو ثنائی_ہندسہ_ناپ(t) (((t) >> (VT_STRUCT_کھسکاؤ + 6)) & 0x3f)

#تعریف_کرو VT_UNION    (1 << VT_STRUCT_کھسکاؤ | VT_STRUCT)
#تعریف_کرو VT_ENUM     (2 << VT_STRUCT_کھسکاؤ) /* integral type is an enum really */
#تعریف_کرو VT_ENUM_VAL (3 << VT_STRUCT_کھسکاؤ) /* integral type is an enum constant really */

#تعریف_کرو IS_ENUM(t) ((t & VT_STRUCT_نقاب) == VT_ENUM)
#تعریف_کرو IS_ENUM_VAL(t) ((t & VT_STRUCT_نقاب) == VT_ENUM_VAL)
#تعریف_کرو IS_UNION(t) ((t & (VT_STRUCT_نقاب|VT_BTYPE)) == VT_UNION)

#تعریف_کرو VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#تعریف_کرو VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#تعریف_کرو VT_TYPE (~(VT_STORAGE|VT_STRUCT_نقاب))

/* symbol was created by tccasm.c first */
#تعریف_کرو VT_ASM (VT_VOID | 4 << VT_STRUCT_کھسکاؤ)
#تعریف_کرو VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_کھسکاؤ)
#تعریف_کرو IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_نقاب) & ~(1<<VT_STRUCT_کھسکاؤ))) == VT_ASM)
#تعریف_کرو IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_نقاب)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#تعریف_کرو VT_BT_ARRAY (6 << VT_STRUCT_کھسکاؤ)
#تعریف_کرو IS_BT_ARRAY(t) ((t & VT_STRUCT_نقاب) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#تعریف_کرو BFVAL(M,N) ((بنانشانی)((M) & ~((M) << 1)) * (N))
#تعریف_کرو BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#تعریف_کرو BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#تعریف_کرو TOK_LAND  0x90
#تعریف_کرو TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#تعریف_کرو TOK_ULT 0x92
#تعریف_کرو TOK_UGE 0x93
#تعریف_کرو TOK_EQ  0x94
#تعریف_کرو TOK_NE  0x95
#تعریف_کرو TOK_ULE 0x96
#تعریف_کرو TOK_UGT 0x97
#تعریف_کرو TOK_Nset 0x98
#تعریف_کرو TOK_Nclear 0x99
#تعریف_کرو TOK_LT  0x9c
#تعریف_کرو TOK_GE  0x9d
#تعریف_کرو TOK_LE  0x9e
#تعریف_کرو TOK_GT  0x9f

#تعریف_کرو TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#تعریف_کرو TOK_DEC     0x80 /* -- */
#تعریف_کرو TOK_MID     0x81 /* inc/dec, to void constant */
#تعریف_کرو TOK_INC     0x82 /* ++ */
#تعریف_کرو TOK_UDIV    0x83 /* unsigned division */
#تعریف_کرو TOK_UMOD    0x84 /* unsigned modulo */
#تعریف_کرو TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#تعریف_کرو TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#تعریف_کرو TOK_ADDC1   0x87 /* add with carry generation */
#تعریف_کرو TOK_ADDC2   0x88 /* add with carry use */
#تعریف_کرو TOK_SUBC1   0x89 /* add with carry generation */
#تعریف_کرو TOK_SUBC2   0x8a /* add with carry use */
#تعریف_کرو TOK_SHL     '<' /* shift left */
#تعریف_کرو TOK_SAR     '>' /* signed shift right */
#تعریف_کرو TOK_SHR     0x8b /* unsigned shift right */
#تعریف_کرو TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#تعریف_کرو TOK_ARROW   0xa0 /* -> */
#تعریف_کرو TOK_DOTS    0xa1 /* three dots */
#تعریف_کرو TOK_TWODOTS 0xa2 /* C++ token ? */
#تعریف_کرو TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#تعریف_کرو TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#تعریف_کرو TOK_PPJOIN  (TOK_TWOSHARPS | SYM_میدان) /* A '##' in a macro to mean pasting */
#تعریف_کرو TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#تعریف_کرو TOK_A_جوڑو   0xb0
#تعریف_کرو TOK_A_SUB   0xb1
#تعریف_کرو TOK_A_MUL   0xb2
#تعریف_کرو TOK_A_DIV   0xb3
#تعریف_کرو TOK_A_MOD   0xb4
#تعریف_کرو TOK_A_AND   0xb5
#تعریف_کرو TOK_A_OR    0xb6
#تعریف_کرو TOK_A_XOR   0xb7
#تعریف_کرو TOK_A_SHL   0xb8
#تعریف_کرو TOK_A_SAR   0xb9

#تعریف_کرو TOK_سونپو(t) (t >= TOK_A_جوڑو && t <= TOK_A_SAR)
#تعریف_کرو TOK_سونپو_OP(t) ("+-*/%&|^<>"[t - TOK_A_جوڑو])

/* tokens that carry values (in additional token string space / tokc) --> */
#تعریف_کرو TOK_CCHAR   0xc0 /* char constant in tokc */
#تعریف_کرو TOK_LCHAR   0xc1
#تعریف_کرو TOK_CINT    0xc2 /* number in tokc */
#تعریف_کرو TOK_CUINT   0xc3 /* unsigned int constant */
#تعریف_کرو TOK_CLLONG  0xc4 /* long long constant */
#تعریف_کرو TOK_CULLONG 0xc5 /* unsigned long long constant */
#تعریف_کرو TOK_CLONG   0xc6 /* long constant */
#تعریف_کرو TOK_CULONG  0xc7 /* unsigned long constant */
#تعریف_کرو TOK_STR     0xc8 /* pointer to string in tokc */
#تعریف_کرو TOK_LSTR    0xc9
#تعریف_کرو TOK_CFLOAT  0xca /* float constant */
#تعریف_کرو TOK_CDOUBLE 0xcb /* double constant */
#تعریف_کرو TOK_CLDOUBLE 0xcc /* long double constant */
#تعریف_کرو TOK_PPNUM   0xcd /* preprocessor number */
#تعریف_کرو TOK_PPSTR   0xce /* preprocessor string */
#تعریف_کرو TOK_LINENUM 0xcf /* line number info */

#تعریف_کرو TOK_HAS_قدر(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#تعریف_کرو TOK_EOF       (-1)  /* end of file */
#تعریف_کرو TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#تعریف_کرو TOK_IDENT 256

تعداد tcc_token {
    TOK_آخری = TOK_IDENT - 1
#تعریف_کرو DEF(id, str) ,id
#ضمن "tcctok.h"
#تعریف_رد DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#تعریف_کرو TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_انکڑے بنية TCCState *tcc_state;
ST_انکڑے فراغ** stk_انکڑے;
ST_انکڑے صحيح nb_stk_انکڑے;
ST_انکڑے صحيح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC حرف *pstrcpy(حرف *buf, ناپ_t buf_ناپ, ثابت حرف *s);
ST_FUNC حرف *pstrcat(حرف *buf, ناپ_t buf_ناپ, ثابت حرف *s);
ST_FUNC حرف *pstrncpy(حرف *باہرلا, ناپ_t buf_ناپ, ثابت حرف *s, ناپ_t عدد);
PUB_FUNC حرف *tcc_basename(ثابت حرف *name);
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC فراغ tcc_free(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc(بنانشانی لما ناپ);
PUB_FUNC فراغ *tcc_mallocz(بنانشانی لما ناپ);
PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, بنانشانی لما ناپ);
PUB_FUNC حرف *tcc_strdup(ثابت حرف *str);

#جے_تعریف_شدہ MEM_DEBUG
#تعریف_کرو tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کرو tcc_malloc(ناپ)        tcc_malloc_debug(ناپ, __FILE__, __LINE__)
#تعریف_کرو tcc_mallocz(ناپ)       tcc_mallocz_debug(ناپ, __FILE__, __LINE__)
#تعریف_کرو tcc_realloc(ptr,ناپ)   tcc_realloc_debug(ptr, ناپ, __FILE__, __LINE__)
#تعریف_کرو tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC فراغ tcc_free_debug(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc_debug(بنانشانی لما ناپ, ثابت حرف *file, صحيح سطر);
PUB_FUNC فراغ *tcc_mallocz_debug(بنانشانی لما ناپ, ثابت حرف *file, صحيح سطر);
PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, بنانشانی لما ناپ, ثابت حرف *file, صحيح سطر);
PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح سطر);
#جے_انت

ST_FUNC فراغ libc_free(فراغ *ptr);
/* defined to be not used */
#تعریف_کرو حرر(p) use_tcc_free(p)
#تعریف_کرو حافظہ_دیو(s) use_tcc_malloc(s)
#تعریف_کرو realloc(p, s) use_tcc_realloc(p, s)
#تعریف_رد strdup
#تعریف_کرو strdup(s) use_tcc_strdup(s)
PUB_FUNC صحيح _tcc_error_noabort(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN فراغ _tcc_error(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC فراغ _tcc_warning(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
#تعریف_کرو tcc_اندرونی_error(پیغام) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,پیغام)

/* other utilities */
ST_FUNC فراغ dynarray_جوڑو(فراغ *ptab, صحيح *nb_ptr, فراغ *انکڑے);
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
#تعریف_کرو stk_ڈالو(p) dynarray_جوڑو(&stk_انکڑے, &nb_stk_انکڑے, p)
#تعریف_کرو stk_نکالو() (--nb_stk_انکڑے)
/* mark CString on stack for cleanup errors */
#تعریف_کرو cstr_new_s(cstr) (cstr_new(cstr), stk_ڈالو(&(cstr)->انکڑے))
#تعریف_کرو cstr_free_s(cstr) (cstr_free(cstr), stk_نکالو())

ST_FUNC صحيح tcc_جوڑو_file_اندرونی(TCCState *s1, ثابت حرف *filename, صحيح flags);
/* flags: */
#تعریف_کرو AFF_PRINT_ERROR     0x10 /* print error if file not found */
#تعریف_کرو AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#تعریف_کرو AFF_TYPE_BIN        0x40 /* file to add is binary */
#تعریف_کرو AFF_سارا_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#تعریف_کرو AFF_TYPE_NONE   0
#تعریف_کرو AFF_TYPE_C      1
#تعریف_کرو AFF_TYPE_ASM    2
#تعریف_کرو AFF_TYPE_ASMPP  4
#تعریف_کرو AFF_TYPE_LIB    8
#تعریف_کرو AFF_TYPE_نقاب   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#تعریف_کرو AFF_BINTYPE_REL 1
#تعریف_کرو AFF_BINTYPE_DYN 2
#تعریف_کرو AFF_BINTYPE_AR  3
#تعریف_کرو AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#تعریف_کرو FILE_NOT_لبھیا -2
#تعریف_کرو FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#جے_بنا_تعریف ELF_OBJ_ONLY
ST_FUNC صحيح tcc_جوڑو_crt(TCCState *s, ثابت حرف *filename);
#جے_انت
ST_FUNC صحيح tcc_جوڑو_dll(TCCState *s, ثابت حرف *filename, صحيح flags);
ST_FUNC صحيح tcc_جوڑو_support(TCCState *s1, ثابت حرف *filename);
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_جوڑو_bcheck(TCCState *s1);
#جے_انت
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
ST_FUNC فراغ tcc_جوڑو_btstub(TCCState *s1);
#جے_انت
ST_FUNC فراغ tcc_جوڑو_pragma_libs(TCCState *s1);
PUB_FUNC صحيح tcc_جوڑو_library_err(TCCState *s, ثابت حرف *f);
PUB_FUNC فراغ tcc_print_stats(TCCState *s, بنانشانی کل_ویلا);
PUB_FUNC صحيح tcc_parse_دلیلاں(TCCState *s, صحيح *argc, حرف ***argv);
#جے_تعریف_شدہ _WIN32
ST_FUNC حرف *normalize_slashes(حرف *رستہ);
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m);
PUB_FUNC صحيح tcc_fclose(FILE *f);
#وإلا
# define tcc_fopen fopen
# define tcc_fclose fclose
#جے_انت
ST_FUNC DLLReference *tcc_جوڑو_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level);
ST_FUNC حرف *tcc_لدو_متن(صحيح fd);
/* for #pragma once */
ST_FUNC صحيح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2);

/* tcc_parse_args return codes: */
#تعریف_کرو OPT_HELP 1
#تعریف_کرو OPT_HELP2 2
#تعریف_کرو OPT_V 3
#تعریف_کرو OPT_PRINT_DIRS 4
#تعریف_کرو OPT_AR 5
#تعریف_کرو OPT_IMPDEF 6
#تعریف_کرو OPT_M32 32
#تعریف_کرو OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_انکڑے بنية BufferedFile *file;
ST_انکڑے صحيح tok;
ST_انکڑے CValue tokc;
ST_انکڑے ثابت صحيح *macro_ptr;
ST_انکڑے صحيح parse_flags;
ST_انکڑے صحيح tok_flags;
ST_انکڑے CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_انکڑے صحيح tok_ident;
ST_انکڑے TokenSym **جدول_ident;
ST_انکڑے صحيح pp_اظہاریہ;

#تعریف_کرو TOK_FLAG_BOL   0x0001 /* beginning of line before */
#تعریف_کرو TOK_FLAG_BOF   0x0002 /* beginning of file before */
#تعریف_کرو TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#تعریف_کرو PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#تعریف_کرو PARSE_FLAG_TOK_عدد    0x0002 /* return numbers instead of TOK_PPNUM */
#تعریف_کرو PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#تعریف_کرو PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#تعریف_کرو PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#تعریف_کرو PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#تعریف_کرو PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#تعریف_کرو IS_SPC 1
#تعریف_کرو IS_ID  2
#تعریف_کرو IS_عدد 4

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
ST_FUNC فراغ سرا_macro(فراغ);
ST_FUNC صحيح سیٹ_idnum(صحيح c, صحيح val);
ST_INLN فراغ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(فراغ);
ST_FUNC فراغ tok_str_free(TokenString *s);
ST_FUNC فراغ tok_str_free_str(صحيح *str);
ST_FUNC فراغ tok_str_جوڑو(TokenString *s, صحيح t);
ST_FUNC فراغ tok_str_جوڑو_tok(TokenString *s);
ST_INLN فراغ define_ڈالو(صحيح v, صحيح macro_type, صحيح *str, Sym *پہلا_arg);
ST_FUNC فراغ define_undef(Sym *s);
ST_INLN Sym *define_لبھو(صحيح v);
ST_FUNC فراغ free_مقرر_کردا(Sym *b);
ST_FUNC فراغ parse_define(فراغ);
ST_FUNC فراغ skip_منزل_eol(صحيح warn);
ST_FUNC فراغ preprocess(صحيح is_bof);
ST_FUNC فراغ اگلا(فراغ);
ST_INLN فراغ unget_tok(صحيح آخری_tok);
ST_FUNC فراغ preprocess_شروع(TCCState *s1, صحيح filetype);
ST_FUNC فراغ preprocess_سرا(TCCState *s1);
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

#تعریف_کرو SYM_POOL_NB (8192 / حجم(Sym))

ST_انکڑے Sym *global_ڈھیر;
ST_انکڑے Sym *local_ڈھیر;
ST_انکڑے Sym *local_label_ڈھیر;
ST_انکڑے Sym *global_label_ڈھیر;
ST_انکڑے Sym *define_ڈھیر;
ST_انکڑے CType int_type, func_old_type, char_اشارہ_گر_type;
ST_انکڑے SValue *vtop;
ST_انکڑے صحيح rsym, anon_sym, ind, loc;
ST_انکڑے حرف debug_modes;

ST_انکڑے صحيح nocode_wanted; /* true if no code generation wanted for an expression */
ST_انکڑے صحيح global_اظہاریہ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_انکڑے CType func_vt; /* current function return type (used by return instruction) */
ST_انکڑے صحيح func_var; /* true if current function is variadic */
ST_انکڑے صحيح func_vc; /* stack address for implicit struct return storage */
ST_انکڑے صحيح func_ind; /* function start address */
ST_انکڑے ثابت حرف *funcname;

ST_FUNC فراغ tccgen_init(TCCState *s1);
ST_FUNC صحيح tccgen_compile(TCCState *s1);
ST_FUNC فراغ tccgen_انت(TCCState *s1);
ST_FUNC فراغ check_vstack(فراغ);

ST_INLN صحيح is_float(صحيح t);
ST_FUNC صحيح ieee_finite(مزدوج d);
ST_FUNC صحيح exact_log2p1(صحيح i);
ST_FUNC فراغ test_lvalue(فراغ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC فراغ update_storage(Sym *sym);
ST_FUNC فراغ put_extern_sym2(Sym *sym, صحيح sh_عدد, addr_t قدر, بنانشانی لما ناپ, صحيح can_جوڑو_underscore);
ST_FUNC فراغ put_extern_sym(Sym *sym, Section *section, addr_t قدر, بنانشانی لما ناپ);
#إذا PTR_ناپ == 4
ST_FUNC فراغ greloc(Section *s, Sym *sym, بنانشانی لما وتھ, صحيح type);
#جے_انت
ST_FUNC فراغ greloca(Section *s, Sym *sym, بنانشانی لما وتھ, صحيح type, addr_t addend);

ST_INLN فراغ sym_free(Sym *sym);
ST_FUNC Sym *sym_ڈالو(صحيح v, CType *type, صحيح r, صحيح c);
ST_FUNC فراغ sym_نکالو(Sym **ptop, Sym *b, صحيح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحيح v, صحيح t, صحيح c);
ST_FUNC Sym *sym_find2(Sym *s, صحيح v);
ST_INLN Sym *sym_لبھو(صحيح v);
ST_FUNC Sym *label_لبھو(صحيح v);
ST_FUNC Sym *label_ڈالو(Sym **ptop, صحيح v, صحيح flags);
ST_FUNC فراغ label_نکالو(Sym **ptop, Sym *slast, صحيح keep);
ST_INLN Sym *struct_لبھو(صحيح v);

ST_FUNC Sym *global_identifier_ڈالو(صحيح v, صحيح t, صحيح c);
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
#إذا PTR_ناپ == 4
ST_FUNC فراغ lexpand(فراغ);
#جے_انت
#جے_تعریف_شدہ TCC_نشانہ_ARM
ST_FUNC صحيح get_reg_ex(صحيح rc, صحيح rc2);
#جے_انت
ST_FUNC فراغ save_reg(صحيح r);
ST_FUNC فراغ save_reg_upstack(صحيح r, صحيح n);
ST_FUNC صحيح get_reg(صحيح rc);
ST_FUNC فراغ save_regs(صحيح n);
ST_FUNC فراغ gaddrof(فراغ);
ST_FUNC صحيح gv(صحيح rc);
ST_FUNC فراغ gv2(صحيح rc1, صحيح rc2);
ST_FUNC فراغ gen_op(صحيح op);
ST_FUNC صحيح type_ناپ(CType *type, صحيح *a);
ST_FUNC فراغ mk_اشارہ_گر(CType *type);
ST_FUNC فراغ vstore(فراغ);
ST_FUNC فراغ inc(صحيح post, صحيح c);
ST_FUNC CString* parse_mult_str(ثابت حرف *پیغام);
ST_FUNC CString* parse_asm_str(فراغ);
ST_FUNC فراغ indir(فراغ);
ST_FUNC فراغ unary(فراغ);
ST_FUNC فراغ gexpr(فراغ);
ST_FUNC صحيح اظہاریہ_const(فراغ);
#إذا defined CONFIG_TCC_BCHECK || defined TCC_نشانہ_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, بنانشانی لما وتھ, بنانشانی لما ناپ);
#جے_انت
#إذا defined TCC_نشانہ_X86_64 && !defined TCC_نشانہ_PE
ST_FUNC صحيح classify_x86_64_va_arg(CType *ty);
#جے_انت
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
ST_FUNC فراغ gbound_دلیلاں(صحيح nb_دلیلاں);
ST_انکڑے صحيح func_bound_جوڑو_epilog;
#جے_انت
ST_FUNC Sym *gfunc_سیٹ_param(Sym *s, صحيح c, صحيح byref);

/* ------------ tccelf.c ------------ */

#تعریف_کرو TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#تعریف_کرو TCC_OUTPUT_FORMAT_ثنائی 1 /* binary image output */
#تعریف_کرو TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#تعریف_کرو TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#تعریف_کرو ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

تعريفنوع بنية {
    بنانشانی صحيح n_strx;         /* index into string table of name */
    بنانشانی حرف n_type;         /* type of symbol */
    بنانشانی حرف n_other;        /* misc info (usually empty) */
    بنانشانی چھوٹا n_desc;        /* description field */
    بنانشانی صحيح n_قدر;        /* value of symbol */
} Stab_Sym;

ST_FUNC فراغ tccelf_new(TCCState *s);
ST_FUNC فراغ tccelf_delete(TCCState *s);
ST_FUNC فراغ tccelf_begin_file(TCCState *s1);
ST_FUNC فراغ tccelf_سرا_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags);
ST_FUNC فراغ section_realloc(Section *sec, بنانشانی لما new_ناپ);
ST_FUNC ناپ_t section_جوڑو(Section *sec, addr_t ناپ, صحيح align);
ST_FUNC فراغ *section_ptr_جوڑو(Section *sec, addr_t ناپ);
ST_FUNC Section *لبھو_section(TCCState *s1, ثابت حرف *name);
ST_FUNC فراغ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت حرف *symtab_name, صحيح sh_type, صحيح sh_flags, ثابت حرف *strtab_name, ثابت حرف *hash_name, صحيح hash_sh_flags);
ST_FUNC فراغ init_symtab(Section *s);

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym);
ST_FUNC صحيح put_elf_sym(Section *s, addr_t قدر, بنانشانی لما ناپ, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح سیٹ_elf_sym(Section *s, addr_t قدر, بنانشانی لما ناپ, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح لبھو_elf_sym(Section *s, ثابت حرف *name);
ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, بنانشانی لما وتھ, صحيح type, صحيح علامت);
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, بنانشانی لما وتھ, صحيح type, صحيح علامت, addr_t addend);

ST_FUNC فراغ resolve_common_syms(TCCState *s1);
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve);
ST_FUNC فراغ relocate_sections(TCCState *s1);

ST_FUNC ssize_t بھریا_read(صحيح fd, فراغ *buf, ناپ_t گنتی_2);
ST_FUNC فراغ *لدو_انکڑے(صحيح fd, بنانشانی لما file_وتھ, بنانشانی لما ناپ);
ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h);
ST_FUNC صحيح tcc_لدو_object_file(TCCState *s1, صحيح fd, بنانشانی لما file_وتھ);
ST_FUNC صحيح tcc_لدو_archive(TCCState *s1, صحيح fd, صحيح alacarte);
ST_FUNC فراغ جوڑو_array(TCCState *s1, ثابت حرف *sec, صحيح c);

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح اشاریہ, صحيح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت حرف *name, صحيح err, صحيح forc);
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*علامت_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));
ST_FUNC صحيح سیٹ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#تعریف_کرو for_each_elem(sec, startoff, elem, type) \
    لكل (elem = (type *) sec->انکڑے + startoff; \
         elem < (type *) (sec->انکڑے + sec->انکڑے_وتھ); elem++)

#جے_بنا_تعریف ELF_OBJ_ONLY
ST_FUNC صحيح tcc_لدو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level);
ST_FUNC صحيح tcc_لدو_ldscript(TCCState *s1, صحيح fd);
ST_FUNC فراغ tccelf_جوڑو_crtbegin(TCCState *s1);
ST_FUNC فراغ tccelf_جوڑو_crtend(TCCState *s1);
#جے_انت
#جے_بنا_تعریف TCC_نشانہ_PE
ST_FUNC فراغ tcc_جوڑو_runtime(TCCState *s1);
#جے_انت

/* ------------ xxx-link.c ------------ */

#جے_بنا_تعریف TCC_نشانہ_PE
ST_FUNC صحيح کوڈ_reloc (صحيح reloc_type);
ST_FUNC صحيح gotplt_اندراج_type (صحيح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
تعداد gotplt_اندراج {
    NO_GOTPLT_اندراج,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_اندراج,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_اندراج	/* always generate (eg. PLTOFF relocs) */
};
#تعریف_کرو NEED_RELOC_TYPE
#إذا !defined TCC_نشانہ_MACHO || defined TCC_IS_NATIVE
ST_FUNC بنانشانی create_plt_اندراج(TCCState *s1, بنانشانی got_وتھ, بنية sym_attr *attr);
ST_FUNC فراغ relocate_plt(TCCState *s1);
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym); /* in tccelf.c */
#تعریف_کرو NEED_BUILD_GOT
#جے_انت
#جے_انت

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بنانشانی حرف *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_انکڑے ثابت حرف * ثابت نشانہ_machine_defs;
ST_انکڑے ثابت صحيح reg_classes[NB_REGS];

ST_FUNC فراغ gsym_addr(صحيح t, صحيح a);
ST_FUNC فراغ gsym(صحيح t);
ST_FUNC فراغ لدو(صحيح r, SValue *sv);
ST_FUNC فراغ store(صحيح r, SValue *v);
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *align, صحيح *regsize);
ST_FUNC فراغ gfunc_call(صحيح nb_دلیلاں);
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
#جے_بنا_تعریف TCC_نشانہ_C67
ST_FUNC فراغ o(بنانشانی صحيح c);
#جے_انت
ST_FUNC فراغ gen_vla_sp_save(صحيح addr);
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr);
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align);

ساكن مضمن uint16_t read16le(بنانشانی حرف *p) {
    أرجع p[0] | (uint16_t)p[1] << 8;
}
ساكن مضمن فراغ write16le(بنانشانی حرف *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ساكن مضمن uint32_t read32le(بنانشانی حرف *p) {
  أرجع read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ساكن مضمن فراغ write32le(بنانشانی حرف *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ساكن مضمن فراغ add32le(بنانشانی حرف *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ساكن مضمن uint64_t read64le(بنانشانی حرف *p) {
  أرجع read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ساكن مضمن فراغ write64le(بنانشانی حرف *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ساكن مضمن فراغ add64le(بنانشانی حرف *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#إذا defined TCC_نشانہ_I386 || defined TCC_نشانہ_X86_64 || defined TCC_نشانہ_ARM
ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);
#جے_انت
#إذا defined TCC_نشانہ_I386 || defined TCC_نشانہ_X86_64
ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#جے_انت

/* ------------ x86_64-gen.c ------------ */
#جے_تعریف_شدہ TCC_نشانہ_X86_64
ST_FUNC فراغ gen_opl(صحيح op);
#جے_تعریف_شدہ TCC_نشانہ_PE
ST_FUNC فراغ gen_vla_نتیجہ(صحيح addr);
#جے_انت
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
#جے_انت

/* ------------ arm-gen.c ------------ */
#جے_تعریف_شدہ TCC_نشانہ_ARM
#إذا defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت حرف *default_elfinterp(بنية TCCState *s);
#جے_انت
ST_FUNC فراغ arm_init(بنية TCCState *s);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#جے_انت

/* ------------ arm64-gen.c ------------ */
#جے_تعریف_شدہ TCC_نشانہ_ARM64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gfunc_return(CType *func_type);
ST_FUNC فراغ gen_va_شروع(فراغ);
ST_FUNC فراغ gen_va_arg(CType *t);
ST_FUNC فراغ gen_clear_cache(فراغ);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#جے_انت

/* ------------ riscv64-gen.c ------------ */
#جے_تعریف_شدہ TCC_نشانہ_RISCV64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gen_va_شروع(فراغ);
ST_FUNC فراغ arch_transfer_ret_regs(صحيح);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
ST_FUNC فراغ gen_clear_cache(فراغ);
#جے_انت

/* ------------ c67-gen.c ------------ */
#جے_تعریف_شدہ TCC_نشانہ_C67
#جے_انت

/* ------------ tcccoff.c ------------ */
#جے_تعریف_شدہ TCC_نشانہ_COFF
ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحيح tcc_لدو_coff(TCCState * s1, صحيح fd);
#جے_انت

/* ------------ tccasm.c ------------ */
ST_FUNC فراغ asm_instr(فراغ);
ST_FUNC فراغ asm_global_instr(فراغ);
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess);
#جے_تعریف_شدہ CONFIG_TCC_ASM
ST_FUNC صحيح لبھو_constraint(ASMOperand *operands, صحيح nb_operands, ثابت حرف *name, ثابت حرف **pp);
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym);
ST_FUNC فراغ asm_اظہاریہ(TCCState *s1, اظہاریہ_قدر *pe);
ST_FUNC صحيح asm_int_اظہاریہ(TCCState *s1);
#إذا PTR_ناپ == 8
ST_FUNC فراغ gen_expr64(اظہاریہ_قدر *pe);
#جے_انت
/* ------------ i386-asm.c ------------ */
ST_FUNC فراغ gen_expr32(اظہاریہ_قدر *pe);
ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode);
ST_FUNC صحيح asm_parse_regvar(صحيح t);
ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, ثابت uint8_t *clobber_regs, صحيح *pout_reg);
ST_FUNC فراغ subst_asm_عملیہ(CString *جوڑو_str, SValue *sv, صحيح modifier);
ST_FUNC فراغ asm_gen_کوڈ(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, صحيح is_output, uint8_t *clobber_regs, صحيح باہرلا_reg);
ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str);
#جے_انت

/* ------------ tccpe.c -------------- */
#جے_تعریف_شدہ TCC_نشانہ_PE
ST_FUNC صحيح pe_لدو_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename);
ST_FUNC صحيح pe_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t قدر);
ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg);
#إذا defined TCC_نشانہ_I386 || defined TCC_نشانہ_X86_64
#جے_انت
#إذا defined(TCC_نشانہ_X86_64) || defined(TCC_نشانہ_ARM64)
ST_FUNC فراغ pe_جوڑو_unwind_انکڑے(بنانشانی شروع, بنانشانی سرا, بنانشانی ڈھیر);
#جے_انت
PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#جے_انت
#تعریف_کرو ST_ASM_سیٹ 0x04

/* ------------ tccmacho.c ----------------- */
#جے_تعریف_شدہ TCC_نشانہ_MACHO
ST_FUNC صحيح macho_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح macho_لدو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
ST_FUNC صحيح macho_لدو_tbd(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
#جے_تعریف_شدہ TCC_IS_NATIVE
ST_FUNC فراغ tcc_جوڑو_macos_sdkpath(TCCState* s);
ST_FUNC حرف* macho_tbd_soname(صحيح fd);
#جے_انت
#جے_انت
/* ------------ tccrun.c ----------------- */
#جے_تعریف_شدہ TCC_IS_NATIVE
#جے_تعریف_شدہ CONFIG_TCC_STATIC
#تعریف_کرو RTLD_LAZY       0x001
#تعریف_کرو RTLD_NOW        0x002
#تعریف_کرو RTLD_GLOBAL     0x100
#تعریف_کرو RTLD_DEFAULT    عدم
/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ST_FUNC فراغ dlclose(فراغ *p);
ST_FUNC ثابت حرف *dlerror(فراغ);
ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *علامت);
#جے_انت
ST_FUNC فراغ tcc_لگاتار_free(TCCState *s1);
#جے_انت

/* ------------ tcctools.c ----------------- */
#إذا 0 /* included in tcc.c */
ST_FUNC صحيح tcc_tool_ar(TCCState *s, صحيح argc, حرف **argv);
#جے_تعریف_شدہ TCC_نشانہ_PE
ST_FUNC صحيح tcc_tool_impdef(TCCState *s, صحيح argc, حرف **argv);
#جے_انت
ST_FUNC صحيح tcc_tool_cross(TCCState *s, حرف **argv, صحيح option);
ST_FUNC صحيح gen_makedeps(TCCState *s, ثابت حرف *نشانہ, ثابت حرف *filename);
#جے_انت

/* ------------ tccdbg.c ------------ */

ST_FUNC فراغ tcc_debug_new(TCCState *s);

ST_FUNC فراغ tcc_debug_شروع(TCCState *s1);
ST_FUNC فراغ tcc_debug_سرا(TCCState *s1);
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1);

ST_FUNC فراغ tcc_debug_سطر(TCCState *s1);
ST_FUNC فراغ tcc_جوڑو_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC فراغ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح قدر);
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح ناپ);
ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_عدد, صحيح sym_bind, صحيح sym_type);
ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح قدر);
ST_FUNC فراغ tcc_debug_fix_forw(TCCState *s1, CType *t);

#إذا !(defined ELF_OBJ_ONLY || defined TCC_نشانہ_ARM || defined TARGETOS_BSD)
ST_FUNC فراغ tcc_eh_چوکھٹا_شروع(TCCState *s1);
ST_FUNC فراغ tcc_eh_چوکھٹا_سرا(TCCState *s1);
ST_FUNC فراغ tcc_eh_چوکھٹا_hdr(TCCState *s1, صحيح final);
#تعریف_کرو TCC_EH_چوکھٹا 1
#جے_انت

ST_FUNC فراغ tcc_tcov_شروع(TCCState *s1);
ST_FUNC فراغ tcc_tcov_سرا(TCCState *s1);
ST_FUNC فراغ tcc_tcov_check_سطر(TCCState *s1, صحيح شروع);
ST_FUNC فراغ tcc_tcov_بلاک_سرا(TCCState *s1, صحيح سطر);
ST_FUNC فراغ tcc_tcov_بلاک_begin(TCCState *s1);
ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1);

#تعریف_کرو stab_section            s1->stab_section
#تعریف_کرو stabstr_section         stab_section->link
#تعریف_کرو tcov_section            s1->tcov_section
#تعریف_کرو eh_چوکھٹا_section        s1->eh_چوکھٹا_section
#تعریف_کرو eh_چوکھٹا_hdr_section    s1->eh_چوکھٹا_hdr_section
#تعریف_کرو dwarf_info_section      s1->dwarf_info_section
#تعریف_کرو dwarf_abbrev_section    s1->dwarf_abbrev_section
#تعریف_کرو dwarf_سطر_section      s1->dwarf_سطر_section
#تعریف_کرو dwarf_aranges_section   s1->dwarf_aranges_section
#تعریف_کرو dwarf_str_section       s1->dwarf_str_section
#تعریف_کرو dwarf_سطر_str_section  s1->dwarf_سطر_str_section

#تعریف_کرو DWARF_MAX_128	((8 * حجم (int64_t) + 6) / 7)
#تعریف_کرو	dwarf_read_1(ln,سرا) \
	((ln) < (سرا) ? *(ln)++ : 0)
#تعریف_کرو	dwarf_read_2(ln,سرا) \
	((ln) + 1 < (سرا) ? read16le(((ln)+=2) - 2) : 0)
#تعریف_کرو	dwarf_read_4(ln,سرا) \
	((ln) + 3 < (سرا) ? read32le(((ln)+=4) - 4) : 0)
#تعریف_کرو	dwarf_read_8(ln,سرا) \
	((ln) + 7 < (سرا) ? read64le(((ln)+=8) - 8) : 0)
ساكن مضمن uint64_t
dwarf_read_uleb128(بنانشانی حرف **ln, بنانشانی حرف *سرا)
{
    بنانشانی حرف *cp = *ln;
    uint64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, سرا);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0)
	    اكسر;
    }
    *ln = cp;
    أرجع retval;
}
ساكن مضمن int64_t
dwarf_read_sleb128(بنانشانی حرف **ln, بنانشانی حرف *سرا)
{
    بنانشانی حرف *cp = *ln;
    int64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, سرا);
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
#جے_تعریف_شدہ TCC_نشانہ_MACHO
# define DEFAULT_DWARF_نسخہ 2
#وإلا
# define DEFAULT_DWARF_نسخہ 5
#جے_انت

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#جے_بنا_تعریف CONFIG_DWARF_نسخہ
# define CONFIG_DWARF_نسخہ 0
#جے_انت

#إذا defined TCC_نشانہ_X86_64
# define R_انکڑے_32_DW R_X86_64_32
#وإلا
# define R_انکڑے_32_DW R_انکڑے_32
#جے_انت

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
    dispatch_semaphore_wait(p->sem, DISPATCH_ویلا_FOREVER);
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
#جے_انت
#تعریف_کرو TCC_SEM(s) TCCSem s
#تعریف_کرو WAIT_SEM wait_sem
#تعریف_کرو POST_SEM post_sem
#وإلا
#تعریف_کرو TCC_SEM(s)
#تعریف_کرو WAIT_SEM(p)
#تعریف_کرو POST_SEM(p)
#جے_انت

/********************************************************/
#تعریف_رد ST_انکڑے
#إذا ONE_سروت
#تعریف_کرو ST_انکڑے ساكن
#وإلا
#تعریف_کرو ST_انکڑے
#جے_انت
/********************************************************/

#تعریف_کرو متن_section        TCC_STATE_VAR(متن_section)
#تعریف_کرو انکڑے_section        TCC_STATE_VAR(انکڑے_section)
#تعریف_کرو rodata_section      TCC_STATE_VAR(rodata_section)
#تعریف_کرو bss_section         TCC_STATE_VAR(bss_section)
#تعریف_کرو common_section      TCC_STATE_VAR(common_section)
#تعریف_کرو cur_متن_section    TCC_STATE_VAR(cur_متن_section)
#تعریف_کرو bounds_section      TCC_STATE_VAR(bounds_section)
#تعریف_کرو lbounds_section     TCC_STATE_VAR(lbounds_section)
#تعریف_کرو symtab_section      TCC_STATE_VAR(symtab_section)
#تعریف_کرو gnu_ext             TCC_STATE_VAR(gnu_ext)
#تعریف_کرو tcc_error_noabort   TCC_سیٹ_STATE(_tcc_error_noabort)
#تعریف_کرو tcc_error           TCC_سیٹ_STATE(_tcc_error)
#تعریف_کرو tcc_warning         TCC_سیٹ_STATE(_tcc_warning)

#تعریف_کرو کل_idents        TCC_STATE_VAR(کل_idents)
#تعریف_کرو کل_سطریں         TCC_STATE_VAR(کل_سطریں)
#تعریف_کرو کل_بائٹاں         TCC_STATE_VAR(کل_بائٹاں)

PUB_FUNC فراغ tcc_enter_state(TCCState *s1);
PUB_FUNC فراغ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#تعریف_کرو tcc_warning_c(sw) TCC_سیٹ_STATE((\
    tcc_state->warn_عدد = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#جے_انت /* _TCC_H */

#تعریف_رد TCC_STATE_VAR
#تعریف_رد TCC_سیٹ_STATE

#جے_تعریف_شدہ USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_سیٹ_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#وإلا
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_سیٹ_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#جے_انت
