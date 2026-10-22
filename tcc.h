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

#جيڪڏهن_وصف_نه_ٿيل _TCC_H
#وصف_ڪريو _TCC_H

#وصف_ڪريو GNU_ذريعو
#وصف_ڪريو DARWIN_C_ذريعو
#ضمن "config.h"

#ضمن <stdarg.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#جيڪڏهن_وصف_ٿيل __TINYC__
# undef __attribute__
#جيڪڏهن_پورو
#ضمن <string.h>
#ضمن <errno.h>
#ضمن <math.h>
#ضمن <fcntl.h>
#ضمن <setjmp.h>
#ضمن <time.h>

#جيڪڏهن_وصف_نه_ٿيل _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
خارجي عائم strtof (ثابت حرف *__nptr, حرف **__endptr);
خارجي ڊگهو مزدوج strtold (ثابت حرف *__nptr, حرف **__endptr);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN32
# define WIN32_LEAN_AND_سراسري 1
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
#  define strtold (ڊگهو مزدوج)strtod
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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل O_ٻٽو_2
# define O_ٻٽو_2 0
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل offsetof
#جيڪڏهن_وصف_ٿيل __clang__ // clang -fsanitize compains about: NULL+value
#وصف_ڪريو offsetof(type, ميدان) __builtin_offsetof(type, ميدان)
#وإلا
#وصف_ڪريو offsetof(type, ميدان) ((سائيز_t) &((type *)0)->ميدان)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل countof
#وصف_ڪريو countof(tab) (حجم(tab) / حجم((tab)[0]))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#وإلا
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (لکو, (x), (y))))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#وإلا
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#جيڪڏهن_پورو

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
#جيڪڏهن_پورو

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
#جيڪڏهن_پورو

#إذا defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#وإلا
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#جيڪڏهن_پورو

#إذا defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#وإلا
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#جيڪڏهن_پورو

#إذا defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#وإلا
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#جيڪڏهن_پورو

#إذا defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وإلاإذا !(defined TCC_هدف_PE || defined TCC_هدف_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#جيڪڏهن_پورو

#إذا defined TCC_هدف_PE || defined TCC_هدف_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#وإلا
# define TCC_هدف_UNIX 1
#جيڪڏهن_پورو

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#إذا defined TCC_هدف_PE \
    || (defined TCC_هدف_MACHO && defined TCC_هدف_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#جيڪڏهن_پورو

/* support using libtcc from threads */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#جيڪڏهن_پورو

/* ------------ path configuration ------------ */

#جيڪڏهن_وصف_نه_ٿيل CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#جيڪڏهن_پورو

#إذا !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#وإلا
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#جيڪڏهن_پورو

/* path to find crt1.o, crti.o and crtn.o */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#جيڪڏهن_پورو

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_SYSINCLUDEPATHS
# إذا defined TCC_هدف_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# وإلا
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#جيڪڏهن_پورو

/* library search paths */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_LIBPATHS
# إذا defined TCC_هدف_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# وإلا
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#جيڪڏهن_پورو

/* name of ELF interpreter */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_ELFINTERP
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
#جيڪڏهن_پورو

/* (target specific) libtcc1.a */
#جيڪڏهن_وصف_نه_ٿيل TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#جيڪڏهن_پورو

/* <cross-prefix-to->libtcc1.a */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#جيڪڏهن_پورو

/* -------------------------------------------- */

#ضمن "libtcc.h"
#ضمن "elf.h"
#ضمن "stab.h"
#ضمن "dwarf.h"

/* -------------------------------------------- */

#جيڪڏهن_وصف_نه_ٿيل PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ONE_ذريعو
# define ONE_ذريعو 0
#جيڪڏهن_پورو

#إذا ONE_ذريعو
#وصف_ڪريو ST_INLN ساكن مضمن
#وصف_ڪريو ST_FUNC ساكن
#وصف_ڪريو ST_معلومات ساكن
#وإلا
#وصف_ڪريو ST_INLN
#وصف_ڪريو ST_FUNC
#وصف_ڪريو ST_معلومات خارجي
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_PROFILE /* profile all functions */
# define ساكن
# define مضمن
#جيڪڏهن_پورو

/* -------------------------------------------- */
/* include the target specific definitions */

#وصف_ڪريو هدف_DEFS_ONLY
#جيڪڏهن_وصف_ٿيل TCC_هدف_I386
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
#غلطي unknown هدف
#جيڪڏهن_پورو
#وصف_رد هدف_DEFS_ONLY

/* -------------------------------------------- */

#إذا PTR_سائيز == 8
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
#جيڪڏهن_پورو
/* target address type */
#وصف_ڪريو addr_t ElfW(Addr)
#وصف_ڪريو ElfSym ElfW(Sym)

#إذا PTR_سائيز == 8 && !defined TCC_هدف_PE
# define LONG_سائيز 8
#وإلا
# define LONG_سائيز 4
#جيڪڏهن_پورو

/* -------------------------------------------- */

#وصف_ڪريو INCLUDE_ڍير_سائيز  32
#وصف_ڪريو IFDEF_ڍير_سائيز    64
#وصف_ڪريو VSTACK_سائيز         512
#وصف_ڪريو STRING_MAX_سائيز     1024
#وصف_ڪريو TOKSTR_MAX_سائيز     256
#وصف_ڪريو PACK_ڍير_سائيز     8

#وصف_ڪريو TOK_HASH_سائيز       16384 /* must be a power of two */
#وصف_ڪريو TOK_ALLOC_INCR      512  /* must be a power of two */
#وصف_ڪريو TOK_MAX_سائيز        4 /* token max size in int unit when stored in string */

/* token symbol management */
تعريفنوع بنية TokenSym {
    بنية TokenSym *hash_ايندڙ;
    بنية Sym *sym_define; /* direct pointer to define */
    بنية Sym *sym_label; /* direct pointer to label */
    بنية Sym *sym_struct; /* direct pointer to structure */
    بنية Sym *sym_identifier; /* direct pointer to identifier */
    صحيح tok; /* token number */
    صحيح len;
    حرف str[1];
} TokenSym;

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
تعريفنوع بنانشان ننڍو nwchar_t;
#وإلا
تعريفنوع صحيح nwchar_t;
#جيڪڏهن_پورو

تعريفنوع بنية CString {
    صحيح سائيز; /* size in bytes */
    صحيح سائيز_allocated;
    حرف *معلومات; /* nwchar_t* in cases */
} CString;

/* type definition */
تعريفنوع بنية CType {
    صحيح t;
    بنية Sym *ref;
} CType;

/* long double words on host(!) platform */
#وصف_ڪريو LDOUBLE_لفظ ((حجم(ڊگهو مزدوج)+3)/4)

/* constant value */
تعريفنوع اتحاد CValue {
    ڊگهو مزدوج ld;
    مزدوج d;
    عائم f;
    uint64_t i;
    بنية {
        حرف *معلومات;
        صحيح سائيز;
    } str;
    صحيح tab[LDOUBLE_لفظ];
} CValue;

/* value on stack */
تعريفنوع بنية SValue {
    CType type;      /* type */
    بنانشان ننڍو r;      /* register + flags */
    بنانشان ننڍو r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اتحاد {
      بنية { صحيح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اتحاد {
      بنية { بنانشان ننڍو cmp_op, cmp_r; }; /* VT_CMP operation */
      بنية Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
بنية SymAttr {
    بنانشان ننڍو
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
    بنانشان
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_دليلون   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
تعريفنوع بنية Sym {
    صحيح v; /* symbol token */
    بنانشان ننڍو r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
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
        ڊگهو ڊگهو enum_val; /* enum constant if IS_ENUM_VAL */
        صحيح *d; /* define token stream */
        بنية Sym *cleanup_func;
    };

    CType type; /* associated type */
    اتحاد {
        بنية Sym *ايندڙ; /* next related symbol (for fields and anoms) */
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
    بنانشان ڊگهو معلومات_وٿي; /* current data offset */
    بنانشان حرف *معلومات;       /* section data */
    بنانشان ڊگهو معلومات_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحيح sh_name;             /* elf section name (only used during output) */
    صحيح sh_انگ;              /* elf section number */
    صحيح sh_type;             /* elf section type */
    صحيح sh_flags;            /* elf section flags */
    صحيح sh_info;             /* elf section info */
    صحيح sh_addralign;        /* elf section alignment */
    صحيح sh_entsize;          /* elf entry size */
    بنانشان ڊگهو sh_سائيز;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    بنانشان ڊگهو sh_وٿي; /* file offset */
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
    بنانشان حرف مليو, اشاريو;
    حرف name[1];
} DLLReference;

/* -------------------------------------------------- */

#وصف_ڪريو SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#وصف_ڪريو SYM_ميدان      0x20000000 /* struct/union field symbol space */
#وصف_ڪريو SYM_پهريون_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#وصف_ڪريو FUNC_NEW       1 /* ansi function prototype */
#وصف_ڪريو FUNC_OLD       2 /* old function prototype */
#وصف_ڪريو FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#وصف_ڪريو FUNC_CDECL     0 /* standard c call */
#وصف_ڪريو FUNC_STDCALL   1 /* pascal c call */
#وصف_ڪريو FUNC_FASTCALL1 2 /* first param in %eax */
#وصف_ڪريو FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#وصف_ڪريو FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#وصف_ڪريو FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#وصف_ڪريو FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#وصف_ڪريو MACRO_OBJ      0 /* object like macro */
#وصف_ڪريو MACRO_FUNC     1 /* function like macro */
#وصف_ڪريو MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#وصف_ڪريو LABEL_DEFINED  0 /* label is defined */
#وصف_ڪريو LABEL_FORWARD  1 /* label is forward defined */
#وصف_ڪريو LABEL_DECLARED 2 /* label is declared but never used */
#وصف_ڪريو LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#وصف_ڪريو TYPE_ABSTRACT  1 /* type without variable */
#وصف_ڪريو TYPE_سڌو    2 /* type with variable */
#وصف_ڪريو TYPE_PARAM     4 /* type declares function parameter */
#وصف_ڪريو TYPE_NEST      8 /* nested call to post_type */

#وصف_ڪريو IO_BUF_سائيز 8192

تعريفنوع بنية BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_پڇاڙي;
    صحيح fd;
    بنية BufferedFile *prev;
    صحيح سٽ_انگ;    /* current line number - here to simplify code */
    صحيح سٽ_ref;    /* tcc -E: last printed line */
    صحيح ifndef_macro;  /* #ifndef macro / #endif search */
    صحيح ifndef_macro_saved; /* saved ifndef_macro */
    صحيح *ifdef_ڍير_ptr; /* ifdef_stack value at the start of the file */
    صحيح include_ايندڙ_اشاريو; /* next search path */
    صحيح prev_tok_flags; /* saved tok_flags */
    حرف filename[1024];    /* filename */
    حرف *true_filename; /* filename not modified by # line directive */
    بنانشان حرف unget[4];
    بنانشان حرف بفر[1]; /* extra size for CH_EOB char */
} BufferedFile;

#وصف_ڪريو CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#وصف_ڪريو CH_EOF   (-1)   /* end of file */

/* used to record tokens */
تعريفنوع بنية TokenString {
    صحيح *str;
    صحيح len;
    صحيح need_spc;
    صحيح allocated_len;
    صحيح آخري_سٽ_انگ;
    صحيح save_سٽ_انگ;
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
    حرف attr_گهڻائي; /* __attribute__((__mode__(...))) */
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
    صحيح hash_ايندڙ; /* -1 if none */
    حرف filename[1]; /* path specified in #include */
} CachedInclude;

#وصف_ڪريو CACHED_INCLUDES_HASH_سائيز 32

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_ASM
تعريفنوع بنية اظهار_قدر {
    uint64_t v;
    Sym *sym;
    صحيح pcrel;
} اظهار_قدر;

#وصف_ڪريو MAX_ASM_OPERANDS 30
تعريفنوع بنية ASMOperand {
    صحيح id; /* GCC 3 optional identifier (0 if number only supported) */
    حرف constraint[16];
    حرف asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحيح ref_اشاريو; /* if >= 0, gives reference to a output constraint */
    صحيح داخلا_اشاريو; /* if >= 0, gives reference to an input constraint */
    صحيح ترجيح; /* priority, used to assign registers */
    صحيح reg; /* if >= 0, register number used for this operand */
    صحيح is_llong; /* true if double register value */
    صحيح is_يادگيري; /* true if memory operand */
    صحيح is_rw;     /* for '+' modifier */
    صحيح is_label;  /* for asm goto */
} ASMOperand;
#جيڪڏهن_پورو

/* extra symbol attributes (not in symbol table) */
بنية sym_attr {
    بنانشان got_وٿي;
    بنانشان plt_وٿي;
    صحيح plt_sym;
    صحيح dyn_اشاريو;
    بنانشان حرف linker_sym:1;
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
    بنانشان حرف plt_thumb_stub:1;
#جيڪڏهن_پورو
};

بنية TCCState {
    بنانشان حرف verbose; /* if true, display some information during compilation */
    بنانشان حرف nostdinc; /* if true, no standard headers are added */
    بنانشان حرف nostdlib; /* if true, no standard libraries are added */
    بنانشان حرف nostdlib_paths; /* if true, the default paths are not searched for libraries */
    بنانشان حرف nocommon; /* if true, do not use common symbols for .bss data */
    بنانشان حرف static_link; /* if true, static linking is performed */
    بنانشان حرف rdynamic; /* if true, all symbols are exported */
    بنانشان حرف symbolic; /* if true, resolve symbols in the current module first */
    بنانشان حرف znodelete; /* Set DF_1_NODELETE in dynamic section */
    بنانشان حرف filetype; /* file type for compilation (NONE,C,ASM) */
    بنانشان حرف optimize; /* only to #define __OPTIMIZE__ */
    بنانشان حرف option_pthread; /* -pthread option */
    بنانشان حرف enable_new_dtags; /* -Wl,--enable-new-dtags */
    بنانشان صحيح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    بنانشان حرف char_is_unsigned;
    بنانشان حرف leading_underscore;
    بنانشان حرف ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    بنانشان حرف dollars_اندريون_identifiers;  /* allows '$' char in identifiers */
    بنانشان حرف ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    بنانشان حرف ابتو_funcargs; /* if true, evaluate last function arg first */
    بنانشان حرف gnu89_inline; /* treat 'extern inline' like 'static inline' */
    بنانشان حرف unwind_tables; /* create eh_frame section */

    /* warning switches */
    بنانشان حرف warn_none;
    بنانشان حرف warn_all;
    بنانشان حرف warn_error;
    بنانشان حرف warn_write_لڙيون;
    بنانشان حرف warn_unsupported;
    بنانشان حرف warn_implicit_function_declaration;
    بنانشان حرف warn_discarded_qualifiers;
    #وصف_ڪريو WARN_ON  1 /* warning is on (-Woption) */
    بنانشان حرف warn_انگ; /* temp var for tcc_warning_c() */

    بنانشان حرف option_r; /* option -r */
    بنانشان حرف do_bench; /* option -bench */
    بنانشان حرف just_deps; /* option -M  */
    بنانشان حرف gen_deps; /* option -MD  */
    بنانشان حرف include_sys_deps; /* option -MD  */
    بنانشان حرف gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    بنانشان حرف do_debug;
    بنانشان حرف dwarf;
    بنانشان حرف do_backtrace;
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    بنانشان حرف do_bounds_check;
#جيڪڏهن_پورو
    بنانشان حرف test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    بنانشان حرف gnu_ext;
    /* use TinyCC extensions */
    بنانشان حرف tcc_ext;

    بنانشان حرف dflag; /* -dX value */
    بنانشان حرف Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
    بنانشان حرف nosse; /* For -mno-sse support. */
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
    بنانشان حرف float_abi; /* float ABI of the generated code*/
#جيڪڏهن_پورو

    بنانشان حرف has_متن_addr;
    addr_t متن_addr; /* address of text section */
    بنانشان section_align; /* section alignment */
#جيڪڏهن_وصف_ٿيل TCC_هدف_I386
    صحيح seg_سائيز; /* 32. Can be 16 with i386 assembler (.code16) */
#جيڪڏهن_پورو

    حرف *tcc_lib_رستو; /* CONFIG_TCCDIR or -B option */
    حرف *soname; /* as specified on the command line (-soname) */
    حرف *rpath; /* as specified on the command line (-Wl,-rpath=) */
    حرف *elfint; /* -Wl,-I... on command line */
    حرف *elf_entryname; /* "_start" unless set */
    حرف *init_نشان; /* symbols to call at load-time (not used currently) */
    حرف *fini_نشان; /* symbols to call at unload-time (not used currently) */
    حرف *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحيح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحيح output_format;
    /* nth test to run with -dt -run */
    صحيح لاڳيتو_test;

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
    فراغ (*error_func)(فراغ *opaque, ثابت حرف *نياپو);
    صحيح error_سيٽ_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحيح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    حرف **هدف_deps;
    صحيح nb_هدف_deps;

    /* compilation */
    BufferedFile *include_ڍير[INCLUDE_ڍير_سائيز];
    BufferedFile **include_ڍير_ptr;

    صحيح ifdef_ڍير[IFDEF_ڍير_سائيز];
    صحيح *ifdef_ڍير_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحيح cached_includes_hash[CACHED_INCLUDES_HASH_سائيز];
    CachedInclude **cached_includes;
    صحيح nb_cached_includes;

    /* #pragma pack stack */
    صحيح pack_ڍير[PACK_ڍير_سائيز];
    صحيح *pack_ڍير_ptr;
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
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#جيڪڏهن_پورو
    /* symbol section */
    اتحاد { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_چوکٺو_section;
    Section *eh_چوکٺو_hdr_section;
    بنانشان ڊگهو eh_شروعات;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_سٽ_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_سٽ_str_section;
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
    #وصف_ڪريو qrel s1->qrel

    addr_t tls_شروعات, tls_پڇاڙي;

#جيڪڏهن_وصف_ٿيل TCC_هدف_RISCV64
    بنية pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحيح nb_pcrel_hi_entries;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    /* PE info */
    صحيح pe_subsystem;
    بنانشان pe_characteristics;
    بنانشان pe_dll_characteristics;
    بنانشان pe_file_align;
    بنانشان pe_ڍير_سائيز;
    addr_t pe_imagebase;
# إذا defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
    Section *uw_pdata;
    صحيح uw_sym;
    صحيح uw_xsym;
    بنانشان uw_offs;
# endif
#جيڪڏهن_پورو

#إذا defined TCC_هدف_MACHO
    حرف *install_name;
    uint32_t compatibility_نسخو;
    uint32_t current_نسخو;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
    صحيح nb_sym_versions;
    بنية sym_نسخو *sym_versions;
    صحيح nb_sym_منزل_نسخو;
    صحيح *sym_منزل_نسخو;
    صحيح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل TCC_IS_NATIVE
    ثابت حرف *لاڳيتو_main; /* entry for tcc_run() */
    فراغ *لاڳيتو_ptr; /* runtime_memory */
    بنانشان لاڳيتو_سائيز; /* size of runtime_memory  */
    ثابت حرف *لاڳيتو_stdin; /* custom stdin file for run_main */
#جيڪڏهن_وصف_ٿيل _WIN64
    فراغ *لاڳيتو_function_جدول; /* unwind data */
#جيڪڏهن_پورو
    بنية TCCState *ايندڙ;
    بنية rt_context *rc; /* pointer to backtrace info block */
    فراغ *لاڳيتو_lj, *لاڳيتو_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    فراغ *bt_معلومات;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
    صحيح rt_انگ_callers;
#جيڪڏهن_پورو

    /* benchmark info */
    صحيح ڪل_idents;
    صحيح ڪل_سٽون;
    بنانشان صحيح ڪل_بائيٽون;
    بنانشان صحيح ڪل_output[4];

    /* used by tcc_load_ldscript */
    بنانشان حرف *ld_p; /* text pointer */

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
#وصف_ڪريو VT_VALMASK   0x003f  /* mask for value location, register or: */
#وصف_ڪريو VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#وصف_ڪريو VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#وصف_ڪريو VT_LOCAL     0x0032  /* offset on stack */
#وصف_ڪريو VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#وصف_ڪريو VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#وصف_ڪريو VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#وصف_ڪريو VT_LVAL      0x0100  /* var is an lvalue */
#وصف_ڪريو VT_SYM       0x0200  /* a symbol value is added */
#وصف_ڪريو VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#وصف_ڪريو VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#وصف_ڪريو VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#وصف_ڪريو VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#وصف_ڪريو VT_BTYPE       0x000f  /* mask for basic type */
#وصف_ڪريو VT_VOID             0  /* void type */
#وصف_ڪريو VT_BYTE             1  /* signed byte type */
#وصف_ڪريو VT_SHORT            2  /* short type */
#وصف_ڪريو VT_INT              3  /* integer type */
#وصف_ڪريو VT_LLONG            4  /* 64 bit integer */
#وصف_ڪريو VT_PTR              5  /*اشارو*/
#وصف_ڪريو VT_FUNC             6  /* function type */
#وصف_ڪريو VT_STRUCT           7  /* struct/union definition */
#وصف_ڪريو VT_FLOAT            8  /* IEEE float */
#وصف_ڪريو VT_DOUBLE           9  /* IEEE double */
#وصف_ڪريو VT_LDOUBLE         10  /* IEEE long double */
#وصف_ڪريو VT_BOOL            11  /* ISOC99 boolean type */
#وصف_ڪريو VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#وصف_ڪريو VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#وصف_ڪريو VT_UNSIGNED    0x0010  /* unsigned type */
#وصف_ڪريو VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#وصف_ڪريو VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#وصف_ڪريو VT_BITFIELD    0x0080  /* bitfield modifier */
#وصف_ڪريو VT_CONSTANT    0x0100  /* const modifier */
#وصف_ڪريو VT_VOLATILE    0x0200  /* volatile modifier */
#وصف_ڪريو VT_RESTRICT    0x0400  /* restrict modifier */
#وصف_ڪريو VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#وصف_ڪريو VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#وصف_ڪريو VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#وصف_ڪريو VT_EXTERN  0x00002000  /* extern definition */
#وصف_ڪريو VT_STATIC  0x00004000  /* static variable */
#وصف_ڪريو VT_TYPEDEF 0x00008000  /* typedef definition */
#وصف_ڪريو VT_INLINE  0x00010000  /* inline definition */
#وصف_ڪريو VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#وصف_ڪريو VT_STRUCT_سرڪايو 20     /* shift for bitfield shift values (32 - 2*6) */
#وصف_ڪريو VT_STRUCT_نقاب (((1U << (6+6)) - 1) << VT_STRUCT_سرڪايو | VT_BITFIELD)
#وصف_ڪريو ٻٽو_انگ_POS(t) (((t) >> VT_STRUCT_سرڪايو) & 0x3f)
#وصف_ڪريو ٻٽو_انگ_سائيز(t) (((t) >> (VT_STRUCT_سرڪايو + 6)) & 0x3f)

#وصف_ڪريو VT_UNION    (1 << VT_STRUCT_سرڪايو | VT_STRUCT)
#وصف_ڪريو VT_ENUM     (2 << VT_STRUCT_سرڪايو) /* integral type is an enum really */
#وصف_ڪريو VT_ENUM_VAL (3 << VT_STRUCT_سرڪايو) /* integral type is an enum constant really */

#وصف_ڪريو IS_ENUM(t) ((t & VT_STRUCT_نقاب) == VT_ENUM)
#وصف_ڪريو IS_ENUM_VAL(t) ((t & VT_STRUCT_نقاب) == VT_ENUM_VAL)
#وصف_ڪريو IS_UNION(t) ((t & (VT_STRUCT_نقاب|VT_BTYPE)) == VT_UNION)

#وصف_ڪريو VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#وصف_ڪريو VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#وصف_ڪريو VT_TYPE (~(VT_STORAGE|VT_STRUCT_نقاب))

/* symbol was created by tccasm.c first */
#وصف_ڪريو VT_ASM (VT_VOID | 4 << VT_STRUCT_سرڪايو)
#وصف_ڪريو VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_سرڪايو)
#وصف_ڪريو IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_نقاب) & ~(1<<VT_STRUCT_سرڪايو))) == VT_ASM)
#وصف_ڪريو IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_نقاب)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#وصف_ڪريو VT_BT_ARRAY (6 << VT_STRUCT_سرڪايو)
#وصف_ڪريو IS_BT_ARRAY(t) ((t & VT_STRUCT_نقاب) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#وصف_ڪريو BFVAL(M,N) ((بنانشان)((M) & ~((M) << 1)) * (N))
#وصف_ڪريو BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#وصف_ڪريو BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#وصف_ڪريو TOK_LAND  0x90
#وصف_ڪريو TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#وصف_ڪريو TOK_ULT 0x92
#وصف_ڪريو TOK_UGE 0x93
#وصف_ڪريو TOK_EQ  0x94
#وصف_ڪريو TOK_NE  0x95
#وصف_ڪريو TOK_ULE 0x96
#وصف_ڪريو TOK_UGT 0x97
#وصف_ڪريو TOK_Nset 0x98
#وصف_ڪريو TOK_Nclear 0x99
#وصف_ڪريو TOK_LT  0x9c
#وصف_ڪريو TOK_GE  0x9d
#وصف_ڪريو TOK_LE  0x9e
#وصف_ڪريو TOK_GT  0x9f

#وصف_ڪريو TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#وصف_ڪريو TOK_DEC     0x80 /* -- */
#وصف_ڪريو TOK_MID     0x81 /* inc/dec, to void constant */
#وصف_ڪريو TOK_INC     0x82 /* ++ */
#وصف_ڪريو TOK_UDIV    0x83 /* unsigned division */
#وصف_ڪريو TOK_UMOD    0x84 /* unsigned modulo */
#وصف_ڪريو TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#وصف_ڪريو TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#وصف_ڪريو TOK_ADDC1   0x87 /* add with carry generation */
#وصف_ڪريو TOK_ADDC2   0x88 /* add with carry use */
#وصف_ڪريو TOK_SUBC1   0x89 /* add with carry generation */
#وصف_ڪريو TOK_SUBC2   0x8a /* add with carry use */
#وصف_ڪريو TOK_SHL     '<' /* shift left */
#وصف_ڪريو TOK_SAR     '>' /* signed shift right */
#وصف_ڪريو TOK_SHR     0x8b /* unsigned shift right */
#وصف_ڪريو TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#وصف_ڪريو TOK_ARROW   0xa0 /* -> */
#وصف_ڪريو TOK_DOTS    0xa1 /* three dots */
#وصف_ڪريو TOK_TWODOTS 0xa2 /* C++ token ? */
#وصف_ڪريو TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#وصف_ڪريو TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#وصف_ڪريو TOK_PPJOIN  (TOK_TWOSHARPS | SYM_ميدان) /* A '##' in a macro to mean pasting */
#وصف_ڪريو TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#وصف_ڪريو TOK_A_جوڙيو   0xb0
#وصف_ڪريو TOK_A_SUB   0xb1
#وصف_ڪريو TOK_A_MUL   0xb2
#وصف_ڪريو TOK_A_DIV   0xb3
#وصف_ڪريو TOK_A_MOD   0xb4
#وصف_ڪريو TOK_A_AND   0xb5
#وصف_ڪريو TOK_A_OR    0xb6
#وصف_ڪريو TOK_A_XOR   0xb7
#وصف_ڪريو TOK_A_SHL   0xb8
#وصف_ڪريو TOK_A_SAR   0xb9

#وصف_ڪريو TOK_سونپيو(t) (t >= TOK_A_جوڙيو && t <= TOK_A_SAR)
#وصف_ڪريو TOK_سونپيو_OP(t) ("+-*/%&|^<>"[t - TOK_A_جوڙيو])

/* tokens that carry values (in additional token string space / tokc) --> */
#وصف_ڪريو TOK_CCHAR   0xc0 /* char constant in tokc */
#وصف_ڪريو TOK_LCHAR   0xc1
#وصف_ڪريو TOK_CINT    0xc2 /* number in tokc */
#وصف_ڪريو TOK_CUINT   0xc3 /* unsigned int constant */
#وصف_ڪريو TOK_CLLONG  0xc4 /* long long constant */
#وصف_ڪريو TOK_CULLONG 0xc5 /* unsigned long long constant */
#وصف_ڪريو TOK_CLONG   0xc6 /* long constant */
#وصف_ڪريو TOK_CULONG  0xc7 /* unsigned long constant */
#وصف_ڪريو TOK_STR     0xc8 /* pointer to string in tokc */
#وصف_ڪريو TOK_LSTR    0xc9
#وصف_ڪريو TOK_CFLOAT  0xca /* float constant */
#وصف_ڪريو TOK_CDOUBLE 0xcb /* double constant */
#وصف_ڪريو TOK_CLDOUBLE 0xcc /* long double constant */
#وصف_ڪريو TOK_PPNUM   0xcd /* preprocessor number */
#وصف_ڪريو TOK_PPSTR   0xce /* preprocessor string */
#وصف_ڪريو TOK_LINENUM 0xcf /* line number info */

#وصف_ڪريو TOK_HAS_قدر(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#وصف_ڪريو TOK_EOF       (-1)  /* end of file */
#وصف_ڪريو TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#وصف_ڪريو TOK_IDENT 256

تعداد tcc_token {
    TOK_آخري = TOK_IDENT - 1
#وصف_ڪريو DEF(id, str) ,id
#ضمن "tcctok.h"
#وصف_رد DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#وصف_ڪريو TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_معلومات بنية TCCState *tcc_state;
ST_معلومات فراغ** stk_معلومات;
ST_معلومات صحيح nb_stk_معلومات;
ST_معلومات صحيح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC حرف *pstrcpy(حرف *buf, سائيز_t buf_سائيز, ثابت حرف *s);
ST_FUNC حرف *pstrcat(حرف *buf, سائيز_t buf_سائيز, ثابت حرف *s);
ST_FUNC حرف *pstrncpy(حرف *ٻاهريون, سائيز_t buf_سائيز, ثابت حرف *s, سائيز_t انگ);
PUB_FUNC حرف *tcc_basename(ثابت حرف *name);
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC فراغ tcc_free(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc(بنانشان ڊگهو سائيز);
PUB_FUNC فراغ *tcc_mallocz(بنانشان ڊگهو سائيز);
PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, بنانشان ڊگهو سائيز);
PUB_FUNC حرف *tcc_strdup(ثابت حرف *str);

#جيڪڏهن_وصف_ٿيل MEM_DEBUG
#وصف_ڪريو tcc_free(ptr)           tcc_free_debug(ptr)
#وصف_ڪريو tcc_malloc(سائيز)        tcc_malloc_debug(سائيز, __FILE__, __LINE__)
#وصف_ڪريو tcc_mallocz(سائيز)       tcc_mallocz_debug(سائيز, __FILE__, __LINE__)
#وصف_ڪريو tcc_realloc(ptr,سائيز)   tcc_realloc_debug(ptr, سائيز, __FILE__, __LINE__)
#وصف_ڪريو tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC فراغ tcc_free_debug(فراغ *ptr);
PUB_FUNC فراغ *tcc_malloc_debug(بنانشان ڊگهو سائيز, ثابت حرف *file, صحيح سٽ);
PUB_FUNC فراغ *tcc_mallocz_debug(بنانشان ڊگهو سائيز, ثابت حرف *file, صحيح سٽ);
PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, بنانشان ڊگهو سائيز, ثابت حرف *file, صحيح سٽ);
PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح سٽ);
#جيڪڏهن_پورو

ST_FUNC فراغ libc_free(فراغ *ptr);
/* defined to be not used */
#وصف_ڪريو حرر(p) use_tcc_free(p)
#وصف_ڪريو يادگيري_ڏيو(s) use_tcc_malloc(s)
#وصف_ڪريو realloc(p, s) use_tcc_realloc(p, s)
#وصف_رد strdup
#وصف_ڪريو strdup(s) use_tcc_strdup(s)
PUB_FUNC صحيح _tcc_error_noabort(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN فراغ _tcc_error(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC فراغ _tcc_warning(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
#وصف_ڪريو tcc_اندروني_error(نياپو) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,نياپو)

/* other utilities */
ST_FUNC فراغ dynarray_جوڙيو(فراغ *ptab, صحيح *nb_ptr, فراغ *معلومات);
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
#وصف_ڪريو stk_ڌڪو(p) dynarray_جوڙيو(&stk_معلومات, &nb_stk_معلومات, p)
#وصف_ڪريو stk_ڪڍو() (--nb_stk_معلومات)
/* mark CString on stack for cleanup errors */
#وصف_ڪريو cstr_new_s(cstr) (cstr_new(cstr), stk_ڌڪو(&(cstr)->معلومات))
#وصف_ڪريو cstr_free_s(cstr) (cstr_free(cstr), stk_ڪڍو())

ST_FUNC صحيح tcc_جوڙيو_file_اندروني(TCCState *s1, ثابت حرف *filename, صحيح flags);
/* flags: */
#وصف_ڪريو AFF_PRINT_ERROR     0x10 /* print error if file not found */
#وصف_ڪريو AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#وصف_ڪريو AFF_TYPE_BIN        0x40 /* file to add is binary */
#وصف_ڪريو AFF_سڄو_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#وصف_ڪريو AFF_TYPE_NONE   0
#وصف_ڪريو AFF_TYPE_C      1
#وصف_ڪريو AFF_TYPE_ASM    2
#وصف_ڪريو AFF_TYPE_ASMPP  4
#وصف_ڪريو AFF_TYPE_LIB    8
#وصف_ڪريو AFF_TYPE_نقاب   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#وصف_ڪريو AFF_BINTYPE_REL 1
#وصف_ڪريو AFF_BINTYPE_DYN 2
#وصف_ڪريو AFF_BINTYPE_AR  3
#وصف_ڪريو AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#وصف_ڪريو FILE_NOT_مليو -2
#وصف_ڪريو FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
ST_FUNC صحيح tcc_جوڙيو_crt(TCCState *s, ثابت حرف *filename);
#جيڪڏهن_پورو
ST_FUNC صحيح tcc_جوڙيو_dll(TCCState *s, ثابت حرف *filename, صحيح flags);
ST_FUNC صحيح tcc_جوڙيو_support(TCCState *s1, ثابت حرف *filename);
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
ST_FUNC فراغ tcc_جوڙيو_bcheck(TCCState *s1);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
ST_FUNC فراغ tcc_جوڙيو_btstub(TCCState *s1);
#جيڪڏهن_پورو
ST_FUNC فراغ tcc_جوڙيو_pragma_libs(TCCState *s1);
PUB_FUNC صحيح tcc_جوڙيو_library_err(TCCState *s, ثابت حرف *f);
PUB_FUNC فراغ tcc_print_stats(TCCState *s, بنانشان ڪل_وقت);
PUB_FUNC صحيح tcc_parse_دليلون(TCCState *s, صحيح *argc, حرف ***argv);
#جيڪڏهن_وصف_ٿيل _WIN32
ST_FUNC حرف *normalize_slashes(حرف *رستو);
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m);
PUB_FUNC صحيح tcc_fclose(FILE *f);
#وإلا
# define tcc_fopen fopen
# define tcc_fclose fclose
#جيڪڏهن_پورو
ST_FUNC DLLReference *tcc_جوڙيو_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level);
ST_FUNC حرف *tcc_ڀريو_متن(صحيح fd);
/* for #pragma once */
ST_FUNC صحيح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2);

/* tcc_parse_args return codes: */
#وصف_ڪريو OPT_HELP 1
#وصف_ڪريو OPT_HELP2 2
#وصف_ڪريو OPT_V 3
#وصف_ڪريو OPT_PRINT_DIRS 4
#وصف_ڪريو OPT_AR 5
#وصف_ڪريو OPT_IMPDEF 6
#وصف_ڪريو OPT_M32 32
#وصف_ڪريو OPT_M64 64

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
ST_معلومات صحيح pp_اظهار;

#وصف_ڪريو TOK_FLAG_BOL   0x0001 /* beginning of line before */
#وصف_ڪريو TOK_FLAG_BOF   0x0002 /* beginning of file before */
#وصف_ڪريو TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#وصف_ڪريو PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#وصف_ڪريو PARSE_FLAG_TOK_انگ    0x0002 /* return numbers instead of TOK_PPNUM */
#وصف_ڪريو PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#وصف_ڪريو PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#وصف_ڪريو PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#وصف_ڪريو PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#وصف_ڪريو PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#وصف_ڪريو IS_SPC 1
#وصف_ڪريو IS_ID  2
#وصف_ڪريو IS_انگ 4

تعداد سٽ_macro_output_format {
    سٽ_MACRO_OUTPUT_FORMAT_GCC,
    سٽ_MACRO_OUTPUT_FORMAT_NONE,
    سٽ_MACRO_OUTPUT_FORMAT_STD,
    سٽ_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحيح len);
ST_FUNC صحيح tok_alloc_const(ثابت حرف *str);
ST_FUNC ثابت حرف *get_tok_str(صحيح v, CValue *cv);
ST_FUNC فراغ begin_macro(TokenString *str, صحيح alloc);
ST_FUNC فراغ پڇاڙي_macro(فراغ);
ST_FUNC صحيح سيٽ_idnum(صحيح c, صحيح val);
ST_INLN فراغ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(فراغ);
ST_FUNC فراغ tok_str_free(TokenString *s);
ST_FUNC فراغ tok_str_free_str(صحيح *str);
ST_FUNC فراغ tok_str_جوڙيو(TokenString *s, صحيح t);
ST_FUNC فراغ tok_str_جوڙيو_tok(TokenString *s);
ST_INLN فراغ define_ڌڪو(صحيح v, صحيح macro_type, صحيح *str, Sym *پهريون_arg);
ST_FUNC فراغ define_undef(Sym *s);
ST_INLN Sym *define_ڳوليو(صحيح v);
ST_FUNC فراغ free_مقرر_ڪري(Sym *b);
ST_FUNC فراغ parse_define(فراغ);
ST_FUNC فراغ skip_منزل_eol(صحيح warn);
ST_FUNC فراغ preprocess(صحيح is_bof);
ST_FUNC فراغ ايندڙ(فراغ);
ST_INLN فراغ unget_tok(صحيح آخري_tok);
ST_FUNC فراغ preprocess_شروعات(TCCState *s1, صحيح filetype);
ST_FUNC فراغ preprocess_پڇاڙي(TCCState *s1);
ST_FUNC فراغ tccpp_new(TCCState *s);
ST_FUNC فراغ tccpp_delete(TCCState *s);
ST_FUNC فراغ tccpp_putfile(ثابت حرف *filename);
ST_FUNC صحيح tcc_preprocess(TCCState *s1);
ST_FUNC فراغ skip(صحيح c);
ST_FUNC NORETURN فراغ expect(ثابت حرف *نياپو);
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

#وصف_ڪريو SYM_POOL_NB (8192 / حجم(Sym))

ST_معلومات Sym *global_ڍير;
ST_معلومات Sym *local_ڍير;
ST_معلومات Sym *local_label_ڍير;
ST_معلومات Sym *global_label_ڍير;
ST_معلومات Sym *define_ڍير;
ST_معلومات CType int_type, func_old_type, char_اشارو_type;
ST_معلومات SValue *vtop;
ST_معلومات صحيح rsym, anon_sym, ind, loc;
ST_معلومات حرف debug_modes;

ST_معلومات صحيح nocode_wanted; /* true if no code generation wanted for an expression */
ST_معلومات صحيح global_اظهار;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_معلومات CType func_vt; /* current function return type (used by return instruction) */
ST_معلومات صحيح func_var; /* true if current function is variadic */
ST_معلومات صحيح func_vc; /* stack address for implicit struct return storage */
ST_معلومات صحيح func_ind; /* function start address */
ST_معلومات ثابت حرف *funcname;

ST_FUNC فراغ tccgen_init(TCCState *s1);
ST_FUNC صحيح tccgen_compile(TCCState *s1);
ST_FUNC فراغ tccgen_پڄاڻي(TCCState *s1);
ST_FUNC فراغ check_vstack(فراغ);

ST_INLN صحيح is_float(صحيح t);
ST_FUNC صحيح ieee_finite(مزدوج d);
ST_FUNC صحيح exact_log2p1(صحيح i);
ST_FUNC فراغ test_lvalue(فراغ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC فراغ update_storage(Sym *sym);
ST_FUNC فراغ put_extern_sym2(Sym *sym, صحيح sh_انگ, addr_t قدر, بنانشان ڊگهو سائيز, صحيح can_جوڙيو_underscore);
ST_FUNC فراغ put_extern_sym(Sym *sym, Section *section, addr_t قدر, بنانشان ڊگهو سائيز);
#إذا PTR_سائيز == 4
ST_FUNC فراغ greloc(Section *s, Sym *sym, بنانشان ڊگهو وٿي, صحيح type);
#جيڪڏهن_پورو
ST_FUNC فراغ greloca(Section *s, Sym *sym, بنانشان ڊگهو وٿي, صحيح type, addr_t addend);

ST_INLN فراغ sym_free(Sym *sym);
ST_FUNC Sym *sym_ڌڪو(صحيح v, CType *type, صحيح r, صحيح c);
ST_FUNC فراغ sym_ڪڍو(Sym **ptop, Sym *b, صحيح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحيح v, صحيح t, صحيح c);
ST_FUNC Sym *sym_find2(Sym *s, صحيح v);
ST_INLN Sym *sym_ڳوليو(صحيح v);
ST_FUNC Sym *label_ڳوليو(صحيح v);
ST_FUNC Sym *label_ڌڪو(Sym **ptop, صحيح v, صحيح flags);
ST_FUNC فراغ label_ڪڍو(Sym **ptop, Sym *slast, صحيح keep);
ST_INLN Sym *struct_ڳوليو(صحيح v);

ST_FUNC Sym *global_identifier_ڌڪو(صحيح v, صحيح t, صحيح c);
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
#إذا PTR_سائيز == 4
ST_FUNC فراغ lexpand(فراغ);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
ST_FUNC صحيح get_reg_ex(صحيح rc, صحيح rc2);
#جيڪڏهن_پورو
ST_FUNC فراغ save_reg(صحيح r);
ST_FUNC فراغ save_reg_upstack(صحيح r, صحيح n);
ST_FUNC صحيح get_reg(صحيح rc);
ST_FUNC فراغ save_regs(صحيح n);
ST_FUNC فراغ gaddrof(فراغ);
ST_FUNC صحيح gv(صحيح rc);
ST_FUNC فراغ gv2(صحيح rc1, صحيح rc2);
ST_FUNC فراغ gen_op(صحيح op);
ST_FUNC صحيح type_سائيز(CType *type, صحيح *a);
ST_FUNC فراغ mk_اشارو(CType *type);
ST_FUNC فراغ vstore(فراغ);
ST_FUNC فراغ inc(صحيح post, صحيح c);
ST_FUNC CString* parse_mult_str(ثابت حرف *نياپو);
ST_FUNC CString* parse_asm_str(فراغ);
ST_FUNC فراغ indir(فراغ);
ST_FUNC فراغ unary(فراغ);
ST_FUNC فراغ gexpr(فراغ);
ST_FUNC صحيح اظهار_const(فراغ);
#إذا defined CONFIG_TCC_BCHECK || defined TCC_هدف_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, بنانشان ڊگهو وٿي, بنانشان ڊگهو سائيز);
#جيڪڏهن_پورو
#إذا defined TCC_هدف_X86_64 && !defined TCC_هدف_PE
ST_FUNC صحيح classify_x86_64_va_arg(CType *ty);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
ST_FUNC فراغ gbound_دليلون(صحيح nb_دليلون);
ST_معلومات صحيح func_bound_جوڙيو_epilog;
#جيڪڏهن_پورو
ST_FUNC Sym *gfunc_سيٽ_param(Sym *s, صحيح c, صحيح byref);

/* ------------ tccelf.c ------------ */

#وصف_ڪريو TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#وصف_ڪريو TCC_OUTPUT_FORMAT_ٻٽو 1 /* binary image output */
#وصف_ڪريو TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#وصف_ڪريو TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#وصف_ڪريو ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

تعريفنوع بنية {
    بنانشان صحيح n_strx;         /* index into string table of name */
    بنانشان حرف n_type;         /* type of symbol */
    بنانشان حرف n_other;        /* misc info (usually empty) */
    بنانشان ننڍو n_desc;        /* description field */
    بنانشان صحيح n_قدر;        /* value of symbol */
} Stab_Sym;

ST_FUNC فراغ tccelf_new(TCCState *s);
ST_FUNC فراغ tccelf_delete(TCCState *s);
ST_FUNC فراغ tccelf_begin_file(TCCState *s1);
ST_FUNC فراغ tccelf_پڇاڙي_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحيح sh_type, صحيح sh_flags);
ST_FUNC فراغ section_realloc(Section *sec, بنانشان ڊگهو new_سائيز);
ST_FUNC سائيز_t section_جوڙيو(Section *sec, addr_t سائيز, صحيح align);
ST_FUNC فراغ *section_ptr_جوڙيو(Section *sec, addr_t سائيز);
ST_FUNC Section *ڳوليو_section(TCCState *s1, ثابت حرف *name);
ST_FUNC فراغ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت حرف *symtab_name, صحيح sh_type, صحيح sh_flags, ثابت حرف *strtab_name, ثابت حرف *hash_name, صحيح hash_sh_flags);
ST_FUNC فراغ init_symtab(Section *s);

ST_FUNC صحيح put_elf_str(Section *s, ثابت حرف *sym);
ST_FUNC صحيح put_elf_sym(Section *s, addr_t قدر, بنانشان ڊگهو سائيز, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح سيٽ_elf_sym(Section *s, addr_t قدر, بنانشان ڊگهو سائيز, صحيح info, صحيح other, صحيح shndx, ثابت حرف *name);
ST_FUNC صحيح ڳوليو_elf_sym(Section *s, ثابت حرف *name);
ST_FUNC فراغ put_elf_reloc(Section *symtab, Section *s, بنانشان ڊگهو وٿي, صحيح type, صحيح نشان);
ST_FUNC فراغ put_elf_reloca(Section *symtab, Section *s, بنانشان ڊگهو وٿي, صحيح type, صحيح نشان, addr_t addend);

ST_FUNC فراغ resolve_common_syms(TCCState *s1);
ST_FUNC فراغ relocate_syms(TCCState *s1, Section *symtab, صحيح do_resolve);
ST_FUNC فراغ relocate_sections(TCCState *s1);

ST_FUNC ssize_t ڀريل_read(صحيح fd, فراغ *buf, سائيز_t ڳڻپ_2);
ST_FUNC فراغ *ڀريو_معلومات(صحيح fd, بنانشان ڊگهو file_وٿي, بنانشان ڊگهو سائيز);
ST_FUNC صحيح tcc_object_type(صحيح fd, ElfW(Ehdr) *h);
ST_FUNC صحيح tcc_ڀريو_object_file(TCCState *s1, صحيح fd, بنانشان ڊگهو file_وٿي);
ST_FUNC صحيح tcc_ڀريو_archive(TCCState *s1, صحيح fd, صحيح alacarte);
ST_FUNC فراغ جوڙيو_array(TCCState *s1, ثابت حرف *sec, صحيح c);

ST_FUNC بنية sym_attr *get_sym_attr(TCCState *s1, صحيح اشاريو, صحيح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت حرف *name, صحيح err, صحيح forc);
ST_FUNC فراغ list_elf_symbols(TCCState *s, فراغ *ctx,
    فراغ (*نشان_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));
ST_FUNC صحيح سيٽ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#وصف_ڪريو for_each_elem(sec, startoff, elem, type) \
    لكل (elem = (type *) sec->معلومات + startoff; \
         elem < (type *) (sec->معلومات + sec->معلومات_وٿي); elem++)

#جيڪڏهن_وصف_نه_ٿيل ELF_OBJ_ONLY
ST_FUNC صحيح tcc_ڀريو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح level);
ST_FUNC صحيح tcc_ڀريو_ldscript(TCCState *s1, صحيح fd);
ST_FUNC فراغ tccelf_جوڙيو_crtbegin(TCCState *s1);
ST_FUNC فراغ tccelf_جوڙيو_crtend(TCCState *s1);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_PE
ST_FUNC فراغ tcc_جوڙيو_runtime(TCCState *s1);
#جيڪڏهن_پورو

/* ------------ xxx-link.c ------------ */

#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_PE
ST_FUNC صحيح ڪوڊ_reloc (صحيح reloc_type);
ST_FUNC صحيح gotplt_داخلا_type (صحيح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
تعداد gotplt_داخلا {
    NO_GOTPLT_داخلا,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_داخلا,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_داخلا	/* always generate (eg. PLTOFF relocs) */
};
#وصف_ڪريو NEED_RELOC_TYPE
#إذا !defined TCC_هدف_MACHO || defined TCC_IS_NATIVE
ST_FUNC بنانشان create_plt_داخلا(TCCState *s1, بنانشان got_وٿي, بنية sym_attr *attr);
ST_FUNC فراغ relocate_plt(TCCState *s1);
ST_FUNC فراغ build_got_entries(TCCState *s1, صحيح got_sym); /* in tccelf.c */
#وصف_ڪريو NEED_BUILD_GOT
#جيڪڏهن_پورو
#جيڪڏهن_پورو

ST_FUNC فراغ relocate(TCCState *s1, ElfW_Rel *rel, صحيح type, بنانشان حرف *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_معلومات ثابت حرف * ثابت هدف_machine_defs;
ST_معلومات ثابت صحيح reg_classes[NB_REGS];

ST_FUNC فراغ gsym_addr(صحيح t, صحيح a);
ST_FUNC فراغ gsym(صحيح t);
ST_FUNC فراغ ڀريو(صحيح r, SValue *sv);
ST_FUNC فراغ store(صحيح r, SValue *v);
ST_FUNC صحيح gfunc_sret(CType *vt, صحيح variadic, CType *ret, صحيح *align, صحيح *regsize);
ST_FUNC فراغ gfunc_call(صحيح nb_دليلون);
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
#جيڪڏهن_وصف_نه_ٿيل TCC_هدف_C67
ST_FUNC فراغ o(بنانشان صحيح c);
#جيڪڏهن_پورو
ST_FUNC فراغ gen_vla_sp_save(صحيح addr);
ST_FUNC فراغ gen_vla_sp_restore(صحيح addr);
ST_FUNC فراغ gen_vla_alloc(CType *type, صحيح align);

ساكن مضمن uint16_t read16le(بنانشان حرف *p) {
    أرجع p[0] | (uint16_t)p[1] << 8;
}
ساكن مضمن فراغ write16le(بنانشان حرف *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ساكن مضمن uint32_t read32le(بنانشان حرف *p) {
  أرجع read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ساكن مضمن فراغ write32le(بنانشان حرف *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ساكن مضمن فراغ add32le(بنانشان حرف *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ساكن مضمن uint64_t read64le(بنانشان حرف *p) {
  أرجع read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ساكن مضمن فراغ write64le(بنانشان حرف *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ساكن مضمن فراغ add64le(بنانشان حرف *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64 || defined TCC_هدف_ARM
ST_FUNC فراغ g(صحيح c);
ST_FUNC فراغ gen_le16(صحيح c);
ST_FUNC فراغ gen_le32(صحيح c);
#جيڪڏهن_پورو
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64
ST_FUNC فراغ gen_addr32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_addrpc32(صحيح r, Sym *sym, صحيح c);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#جيڪڏهن_پورو

/* ------------ x86_64-gen.c ------------ */
#جيڪڏهن_وصف_ٿيل TCC_هدف_X86_64
ST_FUNC فراغ gen_opl(صحيح op);
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
ST_FUNC فراغ gen_vla_نتيجو(صحيح addr);
#جيڪڏهن_پورو
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
#جيڪڏهن_پورو

/* ------------ arm-gen.c ------------ */
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM
#إذا defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت حرف *default_elfinterp(بنية TCCState *s);
#جيڪڏهن_پورو
ST_FUNC فراغ arm_init(بنية TCCState *s);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#جيڪڏهن_پورو

/* ------------ arm64-gen.c ------------ */
#جيڪڏهن_وصف_ٿيل TCC_هدف_ARM64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gfunc_return(CType *func_type);
ST_FUNC فراغ gen_va_شروعات(فراغ);
ST_FUNC فراغ gen_va_arg(CType *t);
ST_FUNC فراغ gen_clear_cache(فراغ);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
#جيڪڏهن_پورو

/* ------------ riscv64-gen.c ------------ */
#جيڪڏهن_وصف_ٿيل TCC_هدف_RISCV64
ST_FUNC فراغ gen_opl(صحيح op);
ST_FUNC فراغ gen_va_شروعات(فراغ);
ST_FUNC فراغ arch_transfer_ret_regs(صحيح);
ST_FUNC فراغ gen_cvt_sxtw(فراغ);
ST_FUNC فراغ gen_cvt_csti(صحيح t);
ST_FUNC فراغ gen_increment_tcov (SValue *sv);
ST_FUNC فراغ gen_clear_cache(فراغ);
#جيڪڏهن_پورو

/* ------------ c67-gen.c ------------ */
#جيڪڏهن_وصف_ٿيل TCC_هدف_C67
#جيڪڏهن_پورو

/* ------------ tcccoff.c ------------ */
#جيڪڏهن_وصف_ٿيل TCC_هدف_COFF
ST_FUNC صحيح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحيح tcc_ڀريو_coff(TCCState * s1, صحيح fd);
#جيڪڏهن_پورو

/* ------------ tccasm.c ------------ */
ST_FUNC فراغ asm_instr(فراغ);
ST_FUNC فراغ asm_global_instr(فراغ);
ST_FUNC صحيح tcc_assemble(TCCState *s1, صحيح do_preprocess);
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_ASM
ST_FUNC صحيح ڳوليو_constraint(ASMOperand *operands, صحيح nb_operands, ثابت حرف *name, ثابت حرف **pp);
ST_FUNC Sym* get_asm_sym(صحيح name, Sym *csym);
ST_FUNC فراغ asm_اظهار(TCCState *s1, اظهار_قدر *pe);
ST_FUNC صحيح asm_int_اظهار(TCCState *s1);
#إذا PTR_سائيز == 8
ST_FUNC فراغ gen_expr64(اظهار_قدر *pe);
#جيڪڏهن_پورو
/* ------------ i386-asm.c ------------ */
ST_FUNC فراغ gen_expr32(اظهار_قدر *pe);
ST_FUNC فراغ asm_opcode(TCCState *s1, صحيح opcode);
ST_FUNC صحيح asm_parse_regvar(صحيح t);
ST_FUNC فراغ asm_compute_constraints(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, ثابت uint8_t *clobber_regs, صحيح *pout_reg);
ST_FUNC فراغ subst_asm_عمليو(CString *جوڙيو_str, SValue *sv, صحيح modifier);
ST_FUNC فراغ asm_gen_ڪوڊ(ASMOperand *operands, صحيح nb_operands, صحيح nb_outputs, صحيح is_output, uint8_t *clobber_regs, صحيح ٻاهريون_reg);
ST_FUNC فراغ asm_clobber(uint8_t *clobber_regs, ثابت حرف *str);
#جيڪڏهن_پورو

/* ------------ tccpe.c -------------- */
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
ST_FUNC صحيح pe_ڀريو_file(بنية TCCState *s1, صحيح fd, ثابت حرف *filename);
ST_FUNC صحيح pe_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح pe_putimport(TCCState *s1, صحيح dllindex, ثابت حرف *name, addr_t قدر);
ST_FUNC صحيح pe_setsubsy(TCCState *s1, ثابت حرف *arg);
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64
#جيڪڏهن_پورو
#إذا defined(TCC_هدف_X86_64) || defined(TCC_هدف_ARM64)
ST_FUNC فراغ pe_جوڙيو_unwind_معلومات(بنانشان شروعات, بنانشان پڇاڙي, بنانشان ڍير);
#جيڪڏهن_پورو
PUB_FUNC صحيح tcc_get_dllexports(ثابت حرف *filename, حرف **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#جيڪڏهن_پورو
#وصف_ڪريو ST_ASM_سيٽ 0x04

/* ------------ tccmacho.c ----------------- */
#جيڪڏهن_وصف_ٿيل TCC_هدف_MACHO
ST_FUNC صحيح macho_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحيح macho_ڀريو_dll(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
ST_FUNC صحيح macho_ڀريو_tbd(TCCState *s1, صحيح fd, ثابت حرف *filename, صحيح lev);
#جيڪڏهن_وصف_ٿيل TCC_IS_NATIVE
ST_FUNC فراغ tcc_جوڙيو_macos_sdkpath(TCCState* s);
ST_FUNC حرف* macho_tbd_soname(صحيح fd);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
/* ------------ tccrun.c ----------------- */
#جيڪڏهن_وصف_ٿيل TCC_IS_NATIVE
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_STATIC
#وصف_ڪريو RTLD_LAZY       0x001
#وصف_ڪريو RTLD_NOW        0x002
#وصف_ڪريو RTLD_GLOBAL     0x100
#وصف_ڪريو RTLD_DEFAULT    عدم
/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag);
ST_FUNC فراغ dlclose(فراغ *p);
ST_FUNC ثابت حرف *dlerror(فراغ);
ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *نشان);
#جيڪڏهن_پورو
ST_FUNC فراغ tcc_لاڳيتو_free(TCCState *s1);
#جيڪڏهن_پورو

/* ------------ tcctools.c ----------------- */
#إذا 0 /* included in tcc.c */
ST_FUNC صحيح tcc_tool_ar(TCCState *s, صحيح argc, حرف **argv);
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
ST_FUNC صحيح tcc_tool_impdef(TCCState *s, صحيح argc, حرف **argv);
#جيڪڏهن_پورو
ST_FUNC صحيح tcc_tool_cross(TCCState *s, حرف **argv, صحيح option);
ST_FUNC صحيح gen_makedeps(TCCState *s, ثابت حرف *هدف, ثابت حرف *filename);
#جيڪڏهن_پورو

/* ------------ tccdbg.c ------------ */

ST_FUNC فراغ tcc_debug_new(TCCState *s);

ST_FUNC فراغ tcc_debug_شروعات(TCCState *s1);
ST_FUNC فراغ tcc_debug_پڇاڙي(TCCState *s1);
ST_FUNC فراغ tcc_debug_bincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_eincl(TCCState *s1);
ST_FUNC فراغ tcc_debug_newfile(TCCState *s1);

ST_FUNC فراغ tcc_debug_سٽ(TCCState *s1);
ST_FUNC فراغ tcc_جوڙيو_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC فراغ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_prolog_epilog(TCCState *s1, صحيح قدر);
ST_FUNC فراغ tcc_debug_funcend(TCCState *s1, صحيح سائيز);
ST_FUNC فراغ tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحيح sh_انگ, صحيح sym_bind, صحيح sym_type);
ST_FUNC فراغ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC فراغ tcc_debug_stabn(TCCState *s1, صحيح type, صحيح قدر);
ST_FUNC فراغ tcc_debug_fix_forw(TCCState *s1, CType *t);

#إذا !(defined ELF_OBJ_ONLY || defined TCC_هدف_ARM || defined TARGETOS_BSD)
ST_FUNC فراغ tcc_eh_چوکٺو_شروعات(TCCState *s1);
ST_FUNC فراغ tcc_eh_چوکٺو_پڇاڙي(TCCState *s1);
ST_FUNC فراغ tcc_eh_چوکٺو_hdr(TCCState *s1, صحيح final);
#وصف_ڪريو TCC_EH_چوکٺو 1
#جيڪڏهن_پورو

ST_FUNC فراغ tcc_tcov_شروعات(TCCState *s1);
ST_FUNC فراغ tcc_tcov_پڇاڙي(TCCState *s1);
ST_FUNC فراغ tcc_tcov_check_سٽ(TCCState *s1, صحيح شروعات);
ST_FUNC فراغ tcc_tcov_بلاڪ_پڇاڙي(TCCState *s1, صحيح سٽ);
ST_FUNC فراغ tcc_tcov_بلاڪ_begin(TCCState *s1);
ST_FUNC فراغ tcc_tcov_reset_ind(TCCState *s1);

#وصف_ڪريو stab_section            s1->stab_section
#وصف_ڪريو stabstr_section         stab_section->link
#وصف_ڪريو tcov_section            s1->tcov_section
#وصف_ڪريو eh_چوکٺو_section        s1->eh_چوکٺو_section
#وصف_ڪريو eh_چوکٺو_hdr_section    s1->eh_چوکٺو_hdr_section
#وصف_ڪريو dwarf_info_section      s1->dwarf_info_section
#وصف_ڪريو dwarf_abbrev_section    s1->dwarf_abbrev_section
#وصف_ڪريو dwarf_سٽ_section      s1->dwarf_سٽ_section
#وصف_ڪريو dwarf_aranges_section   s1->dwarf_aranges_section
#وصف_ڪريو dwarf_str_section       s1->dwarf_str_section
#وصف_ڪريو dwarf_سٽ_str_section  s1->dwarf_سٽ_str_section

#وصف_ڪريو DWARF_MAX_128	((8 * حجم (int64_t) + 6) / 7)
#وصف_ڪريو	dwarf_read_1(ln,پڇاڙي) \
	((ln) < (پڇاڙي) ? *(ln)++ : 0)
#وصف_ڪريو	dwarf_read_2(ln,پڇاڙي) \
	((ln) + 1 < (پڇاڙي) ? read16le(((ln)+=2) - 2) : 0)
#وصف_ڪريو	dwarf_read_4(ln,پڇاڙي) \
	((ln) + 3 < (پڇاڙي) ? read32le(((ln)+=4) - 4) : 0)
#وصف_ڪريو	dwarf_read_8(ln,پڇاڙي) \
	((ln) + 7 < (پڇاڙي) ? read64le(((ln)+=8) - 8) : 0)
ساكن مضمن uint64_t
dwarf_read_uleb128(بنانشان حرف **ln, بنانشان حرف *پڇاڙي)
{
    بنانشان حرف *cp = *ln;
    uint64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, پڇاڙي);
        retval |= (byte & 0x7f) << (i * 7);
	إذا ((byte & 0x80) == 0)
	    اكسر;
    }
    *ln = cp;
    أرجع retval;
}
ساكن مضمن int64_t
dwarf_read_sleb128(بنانشان حرف **ln, بنانشان حرف *پڇاڙي)
{
    بنانشان حرف *cp = *ln;
    int64_t retval = 0;
    صحيح i;
    لكل (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, پڇاڙي);
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
#جيڪڏهن_وصف_ٿيل TCC_هدف_MACHO
# define DEFAULT_DWARF_نسخو 2
#وإلا
# define DEFAULT_DWARF_نسخو 5
#جيڪڏهن_پورو

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_DWARF_نسخو
# define CONFIG_DWARF_نسخو 0
#جيڪڏهن_پورو

#إذا defined TCC_هدف_X86_64
# define R_معلومات_32_DW R_X86_64_32
#وإلا
# define R_معلومات_32_DW R_معلومات_32
#جيڪڏهن_پورو

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
    dispatch_semaphore_wait(p->sem, DISPATCH_وقت_FOREVER);
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
#جيڪڏهن_پورو
#وصف_ڪريو TCC_SEM(s) TCCSem s
#وصف_ڪريو WAIT_SEM wait_sem
#وصف_ڪريو POST_SEM post_sem
#وإلا
#وصف_ڪريو TCC_SEM(s)
#وصف_ڪريو WAIT_SEM(p)
#وصف_ڪريو POST_SEM(p)
#جيڪڏهن_پورو

/********************************************************/
#وصف_رد ST_معلومات
#إذا ONE_ذريعو
#وصف_ڪريو ST_معلومات ساكن
#وإلا
#وصف_ڪريو ST_معلومات
#جيڪڏهن_پورو
/********************************************************/

#وصف_ڪريو متن_section        TCC_STATE_VAR(متن_section)
#وصف_ڪريو معلومات_section        TCC_STATE_VAR(معلومات_section)
#وصف_ڪريو rodata_section      TCC_STATE_VAR(rodata_section)
#وصف_ڪريو bss_section         TCC_STATE_VAR(bss_section)
#وصف_ڪريو common_section      TCC_STATE_VAR(common_section)
#وصف_ڪريو cur_متن_section    TCC_STATE_VAR(cur_متن_section)
#وصف_ڪريو bounds_section      TCC_STATE_VAR(bounds_section)
#وصف_ڪريو lbounds_section     TCC_STATE_VAR(lbounds_section)
#وصف_ڪريو symtab_section      TCC_STATE_VAR(symtab_section)
#وصف_ڪريو gnu_ext             TCC_STATE_VAR(gnu_ext)
#وصف_ڪريو tcc_error_noabort   TCC_سيٽ_STATE(_tcc_error_noabort)
#وصف_ڪريو tcc_error           TCC_سيٽ_STATE(_tcc_error)
#وصف_ڪريو tcc_warning         TCC_سيٽ_STATE(_tcc_warning)

#وصف_ڪريو ڪل_idents        TCC_STATE_VAR(ڪل_idents)
#وصف_ڪريو ڪل_سٽون         TCC_STATE_VAR(ڪل_سٽون)
#وصف_ڪريو ڪل_بائيٽون         TCC_STATE_VAR(ڪل_بائيٽون)

PUB_FUNC فراغ tcc_enter_state(TCCState *s1);
PUB_FUNC فراغ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#وصف_ڪريو tcc_warning_c(sw) TCC_سيٽ_STATE((\
    tcc_state->warn_انگ = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#جيڪڏهن_پورو /* _TCC_H */

#وصف_رد TCC_STATE_VAR
#وصف_رد TCC_سيٽ_STATE

#جيڪڏهن_وصف_ٿيل USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_سيٽ_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#وإلا
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_سيٽ_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#جيڪڏهن_پورو
