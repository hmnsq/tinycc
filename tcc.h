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

#اگر_غیر_تعریف_شدہ _TCC_H
#تعریف_کرو _TCC_H

#تعریف_کرو GNU_ماخذ
#تعریف_کرو DARWIN_C_ماخذ
#شامل "config.h"

#شامل <stdarg.h>
#شامل <stdlib.h>
#شامل <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#اگر_تعریف_شدہ __TINYC__
# undef __attribute__
#اگر_ختم
#شامل <string.h>
#شامل <errno.h>
#شامل <math.h>
#شامل <fcntl.h>
#شامل <setjmp.h>
#شامل <time.h>

#اگر_غیر_تعریف_شدہ _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
خارجی اعشاری strtof (ثابت حرف *__nptr, حرف **__endptr);
خارجی طویل دوہرا strtold (ثابت حرف *__nptr, حرف **__endptr);
#اگر_ختم

#اگر_تعریف_شدہ _WIN32
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
# define اندرونی __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (طویل دوہرا)strtod
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
#اگر_ختم

#اگر_غیر_تعریف_شدہ O_ثنائی_2
# define O_ثنائی_2 0
#اگر_ختم

#اگر_غیر_تعریف_شدہ offsetof
#اگر_تعریف_شدہ __clang__ // clang -fsanitize compains about: NULL+value
#تعریف_کرو offsetof(type, میدان) __builtin_offsetof(type, میدان)
#ورنہ
#تعریف_کرو offsetof(type, میدان) ((سائز_t) &((type *)0)->میدان)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ countof
#تعریف_کرو countof(tab) (حجم(tab) / حجم((tab)[0]))
#اگر_ختم

#اگر_تعریف_شدہ _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#ورنہ
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (لکھو, (x), (y))))
#اگر_ختم

#اگر_تعریف_شدہ _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#ورنہ
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#اگر_ختم

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
#اگر !defined(TCC_ہدف_I386) && !defined(TCC_ہدف_ARM) && \
    !defined(TCC_ہدف_ARM64) && !defined(TCC_ہدف_C67) && \
    !defined(TCC_ہدف_X86_64) && !defined(TCC_ہدف_RISCV64)
# اگر defined __x86_64__
#  define TCC_ہدف_X86_64
# elif defined __arm__
#  define TCC_ہدف_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_ہدف_ARM64
# elif defined __riscv
#  define TCC_ہدف_RISCV64
# ورنہ
#  define TCC_ہدف_I386
# endif
# ifdef _WIN32
#  define TCC_ہدف_PE 1
# endif
# ifdef __APPLE__
#  define TCC_ہدف_MACHO 1
# endif
#اگر_ختم

/* only native compiler supports -run */
#اگر defined _WIN32 == defined TCC_ہدف_PE \
    && defined __APPLE__ == defined TCC_ہدف_MACHO
# اگر defined __i386__ && defined TCC_ہدف_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_ہدف_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_ہدف_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_ہدف_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_ہدف_RISCV64
#  define TCC_IS_NATIVE
# endif
#اگر_ختم

#اگر defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#ورنہ
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#اگر_ختم

#اگر defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#ورنہ
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#اگر_ختم

#اگر defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#ورنہ
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#اگر_ختم

#اگر defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#وگرنہ_اگر !(defined TCC_ہدف_PE || defined TCC_ہدف_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#اگر_ختم

#اگر defined TCC_ہدف_PE || defined TCC_ہدف_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#ورنہ
# define TCC_ہدف_UNIX 1
#اگر_ختم

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#اگر defined TCC_ہدف_PE \
    || (defined TCC_ہدف_MACHO && defined TCC_ہدف_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#اگر_ختم

#اگر_تعریف_شدہ CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#اگر_ختم

/* support using libtcc from threads */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#اگر_ختم

/* ------------ path configuration ------------ */

#اگر_غیر_تعریف_شدہ CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#اگر_ختم

#اگر !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#اگر_ختم

#اگر_تعریف_شدہ CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#ورنہ
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#اگر_ختم

/* path to find crt1.o, crti.o and crtn.o */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#اگر_ختم

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_SYSINCLUDEPATHS
# اگر defined TCC_ہدف_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# ورنہ
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#اگر_ختم

/* library search paths */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_LIBPATHS
# اگر defined TCC_ہدف_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# ورنہ
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#اگر_ختم

/* name of ELF interpreter */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_ELFINTERP
# اگر defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_ہدف_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_ہدف_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_ہدف_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_ہدف_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_ہدف_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# ورنہ
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#اگر_ختم

/* (target specific) libtcc1.a */
#اگر_غیر_تعریف_شدہ TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#اگر_ختم

/* <cross-prefix-to->libtcc1.a */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#اگر_ختم

/* -------------------------------------------- */

#شامل "libtcc.h"
#شامل "elf.h"
#شامل "stab.h"
#شامل "dwarf.h"

/* -------------------------------------------- */

#اگر_غیر_تعریف_شدہ PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#اگر_ختم

#اگر_غیر_تعریف_شدہ ONE_ماخذ
# define ONE_ماخذ 0
#اگر_ختم

#اگر ONE_ماخذ
#تعریف_کرو ST_INLN ساکن اندرونی
#تعریف_کرو ST_FUNC ساکن
#تعریف_کرو ST_ڈیٹا ساکن
#ورنہ
#تعریف_کرو ST_INLN
#تعریف_کرو ST_FUNC
#تعریف_کرو ST_ڈیٹا خارجی
#اگر_ختم

#اگر_تعریف_شدہ TCC_PROFILE /* profile all functions */
# define ساکن
# define اندرونی
#اگر_ختم

/* -------------------------------------------- */
/* include the target specific definitions */

#تعریف_کرو ہدف_DEFS_ONLY
#اگر_تعریف_شدہ TCC_ہدف_I386
# include "i386-gen.c"
# include "i386-link.c"
#وگرنہ_اگر defined TCC_ہدف_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#وگرنہ_اگر defined TCC_ہدف_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#وگرنہ_اگر defined TCC_ہدف_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#وگرنہ_اگر defined TCC_ہدف_C67
# define TCC_ہدف_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#وگرنہ_اگر defined(TCC_ہدف_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#ورنہ
#غلطی unknown ہدف
#اگر_ختم
#تعریف_منسوخ ہدف_DEFS_ONLY

/* -------------------------------------------- */

#اگر PTR_سائز == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#ورنہ
# define ELFCLASSW ELFCLASS32
# define ElfW(type) Elf##32##_##type
# define ELFW(type) ELF##32##_##type
# define ElfW_Rel ElfW(Rel)
# define SHT_RELX SHT_REL
# define REL_SECTION_FMT ".rel%s"
#اگر_ختم
/* target address type */
#تعریف_کرو addr_t ElfW(Addr)
#تعریف_کرو ElfSym ElfW(Sym)

#اگر PTR_سائز == 8 && !defined TCC_ہدف_PE
# define LONG_سائز 8
#ورنہ
# define LONG_سائز 4
#اگر_ختم

/* -------------------------------------------- */

#تعریف_کرو INCLUDE_ڈھیر_سائز  32
#تعریف_کرو IFDEF_ڈھیر_سائز    64
#تعریف_کرو VSTACK_سائز         512
#تعریف_کرو STRING_MAX_سائز     1024
#تعریف_کرو TOKSTR_MAX_سائز     256
#تعریف_کرو PACK_ڈھیر_سائز     8

#تعریف_کرو TOK_HASH_سائز       16384 /* must be a power of two */
#تعریف_کرو TOK_ALLOC_INCR      512  /* must be a power of two */
#تعریف_کرو TOK_MAX_سائز        4 /* token max size in int unit when stored in string */

/* token symbol management */
قسمتعریف ساخت TokenSym {
    ساخت TokenSym *hash_اگلا;
    ساخت Sym *sym_define; /* direct pointer to define */
    ساخت Sym *sym_label; /* direct pointer to label */
    ساخت Sym *sym_struct; /* direct pointer to structure */
    ساخت Sym *sym_identifier; /* direct pointer to identifier */
    صحیح tok; /* token number */
    صحیح len;
    حرف str[1];
} TokenSym;

#اگر_تعریف_شدہ TCC_ہدف_PE
قسمتعریف غیرعلامتی مختصر nwchar_t;
#ورنہ
قسمتعریف صحیح nwchar_t;
#اگر_ختم

قسمتعریف ساخت CString {
    صحیح سائز; /* size in bytes */
    صحیح سائز_allocated;
    حرف *ڈیٹا; /* nwchar_t* in cases */
} CString;

/* type definition */
قسمتعریف ساخت CType {
    صحیح t;
    ساخت Sym *ref;
} CType;

/* long double words on host(!) platform */
#تعریف_کرو LDOUBLE_الفاظ ((حجم(طویل دوہرا)+3)/4)

/* constant value */
قسمتعریف اتحاد CValue {
    طویل دوہرا ld;
    دوہرا d;
    اعشاری f;
    uint64_t i;
    ساخت {
        حرف *ڈیٹا;
        صحیح سائز;
    } str;
    صحیح tab[LDOUBLE_الفاظ];
} CValue;

/* value on stack */
قسمتعریف ساخت SValue {
    CType type;      /* type */
    غیرعلامتی مختصر r;      /* register + flags */
    غیرعلامتی مختصر r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    اتحاد {
      ساخت { صحیح jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    اتحاد {
      ساخت { غیرعلامتی مختصر cmp_op, cmp_r; }; /* VT_CMP operation */
      ساخت Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ساخت SymAttr {
    غیرعلامتی مختصر
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
ساخت FuncAttr {
    غیرعلامتی
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_دلائل   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
قسمتعریف ساخت Sym {
    صحیح v; /* symbol token */
    غیرعلامتی مختصر r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ساخت SymAttr a; /* symbol attributes */
    اتحاد {
        ساخت {
            صحیح c; /* associated number or Elf symbol index */
            اتحاد {
                صحیح sym_scope; /* scope level for locals */
                صحیح jnext; /* next jump label */
                صحیح jind; /* label position */
                ساخت FuncAttr f; /* function attributes */
                صحیح auxtype; /* bitfield access type */
            };
        };
        طویل طویل enum_val; /* enum constant if IS_ENUM_VAL */
        صحیح *d; /* define token stream */
        ساخت Sym *cleanup_func;
    };

    CType type; /* associated type */
    اتحاد {
        ساخت Sym *اگلا; /* next related symbol (for fields and anoms) */
        صحیح *e; /* expanded token stream with preprocessor macros */
        صحیح asm_label; /* associated asm label */
        ساخت Sym *cleanupstate; /* in defined labels */
        صحیح *vla_array_str; /* vla array code */
    };
    ساخت Sym *پچھلا; /* prev symbol in stack */
    اتحاد {
        ساخت Sym *پچھلا_tok; /* previous symbol for this token */
        ساخت Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ساخت Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
قسمتعریف ساخت Section {
    غیرعلامتی طویل ڈیٹا_انحراف; /* current data offset */
    غیرعلامتی حرف *ڈیٹا;       /* section data */
    غیرعلامتی طویل ڈیٹا_allocated; /* used for realloc() handling */
    TCCState *s1;
    صحیح sh_name;             /* elf section name (only used during output) */
    صحیح sh_عدد;              /* elf section number */
    صحیح sh_type;             /* elf section type */
    صحیح sh_flags;            /* elf section flags */
    صحیح sh_info;             /* elf section info */
    صحیح sh_addralign;        /* elf section alignment */
    صحیح sh_entsize;          /* elf entry size */
    غیرعلامتی طویل sh_سائز;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    غیرعلامتی طویل sh_انحراف; /* file offset */
    صحیح nb_hashed_syms;      /* used to resize the hash table */
    ساخت Section *link;    /* link to another section */
    ساخت Section *reloc;   /* corresponding section for relocation, if any */
    ساخت Section *hash;    /* hash table for symbols */
    ساخت Section *پچھلا;    /* previous section on section stack */
    حرف name[1];           /* section name */
} Section;

قسمتعریف ساخت DLLReference {
    صحیح level;
    خالی *handle;
    غیرعلامتی حرف ملا, اشاریہ;
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
#تعریف_کرو TYPE_براہ_راست    2 /* type with variable */
#تعریف_کرو TYPE_PARAM     4 /* type declares function parameter */
#تعریف_کرو TYPE_NEST      8 /* nested call to post_type */

#تعریف_کرو IO_BUF_سائز 8192

قسمتعریف ساخت BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_انتہا;
    صحیح fd;
    ساخت BufferedFile *پچھلا;
    صحیح سطر_عدد;    /* current line number - here to simplify code */
    صحیح سطر_ref;    /* tcc -E: last printed line */
    صحیح ifndef_macro;  /* #ifndef macro / #endif search */
    صحیح ifndef_macro_saved; /* saved ifndef_macro */
    صحیح *ifdef_ڈھیر_ptr; /* ifdef_stack value at the start of the file */
    صحیح include_اگلا_اشاریہ; /* next search path */
    صحیح پچھلا_tok_flags; /* saved tok_flags */
    حرف filename[1024];    /* filename */
    حرف *true_filename; /* filename not modified by # line directive */
    غیرعلامتی حرف unget[4];
    غیرعلامتی حرف بفر[1]; /* extra size for CH_EOB char */
} BufferedFile;

#تعریف_کرو CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#تعریف_کرو CH_EOF   (-1)   /* end of file */

/* used to record tokens */
قسمتعریف ساخت TokenString {
    صحیح *str;
    صحیح len;
    صحیح need_spc;
    صحیح allocated_len;
    صحیح آخری_سطر_عدد;
    صحیح save_سطر_عدد;
    /* used to chain token-strings with begin/end_macro() */
    ساخت TokenString *پچھلا;
    ثابت صحیح *پچھلا_ptr;
    حرف alloc;
} TokenString;

/* GNUC attribute definition */
قسمتعریف ساخت AttributeDef {
    ساخت SymAttr a;
    ساخت FuncAttr f;
    ساخت Section *section;
    Sym *cleanup_func;
    صحیح alias_ہدف; /* token */
    صحیح asm_label; /* associated asm label */
    حرف attr_منوال; /* __attribute__((__mode__(...))) */
    حرف new_section; /* section is new */
} AttributeDef;

/* inline functions */
قسمتعریف ساخت InlineFunc {
    TokenString *func_str;
    Sym *sym;
    حرف filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
قسمتعریف ساخت CachedInclude {
    صحیح ifndef_macro;
    صحیح once;
    صحیح hash_اگلا; /* -1 if none */
    حرف filename[1]; /* path specified in #include */
} CachedInclude;

#تعریف_کرو CACHED_INCLUDES_HASH_سائز 32

#اگر_تعریف_شدہ CONFIG_TCC_ASM
قسمتعریف ساخت اظہاریہ_قدر {
    uint64_t v;
    Sym *sym;
    صحیح pcrel;
} اظہاریہ_قدر;

#تعریف_کرو MAX_ASM_OPERANDS 30
قسمتعریف ساخت ASMOperand {
    صحیح id; /* GCC 3 optional identifier (0 if number only supported) */
    حرف constraint[16];
    حرف asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    صحیح ref_اشاریہ; /* if >= 0, gives reference to a output constraint */
    صحیح داخلہ_اشاریہ; /* if >= 0, gives reference to an input constraint */
    صحیح ترجیح; /* priority, used to assign registers */
    صحیح reg; /* if >= 0, register number used for this operand */
    صحیح is_llong; /* true if double register value */
    صحیح is_حافظہ; /* true if memory operand */
    صحیح is_rw;     /* for '+' modifier */
    صحیح is_label;  /* for asm goto */
} ASMOperand;
#اگر_ختم

/* extra symbol attributes (not in symbol table) */
ساخت sym_attr {
    غیرعلامتی got_انحراف;
    غیرعلامتی plt_انحراف;
    صحیح plt_sym;
    صحیح dyn_اشاریہ;
    غیرعلامتی حرف linker_sym:1;
#اگر_تعریف_شدہ TCC_ہدف_ARM
    غیرعلامتی حرف plt_thumb_stub:1;
#اگر_ختم
};

ساخت TCCState {
    غیرعلامتی حرف verbose; /* if true, display some information during compilation */
    غیرعلامتی حرف nostdinc; /* if true, no standard headers are added */
    غیرعلامتی حرف nostdlib; /* if true, no standard libraries are added */
    غیرعلامتی حرف nostdlib_paths; /* if true, the default paths are not searched for libraries */
    غیرعلامتی حرف nocommon; /* if true, do not use common symbols for .bss data */
    غیرعلامتی حرف static_link; /* if true, static linking is performed */
    غیرعلامتی حرف rdynamic; /* if true, all symbols are exported */
    غیرعلامتی حرف symbolic; /* if true, resolve symbols in the current module first */
    غیرعلامتی حرف znodelete; /* Set DF_1_NODELETE in dynamic section */
    غیرعلامتی حرف filetype; /* file type for compilation (NONE,C,ASM) */
    غیرعلامتی حرف optimize; /* only to #define __OPTIMIZE__ */
    غیرعلامتی حرف option_pthread; /* -pthread option */
    غیرعلامتی حرف enable_new_dtags; /* -Wl,--enable-new-dtags */
    غیرعلامتی صحیح  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    غیرعلامتی حرف char_is_unsigned;
    غیرعلامتی حرف leading_underscore;
    غیرعلامتی حرف ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    غیرعلامتی حرف dollars_اندر_identifiers;  /* allows '$' char in identifiers */
    غیرعلامتی حرف ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    غیرعلامتی حرف الٹ_funcargs; /* if true, evaluate last function arg first */
    غیرعلامتی حرف gnu89_inline; /* treat 'extern inline' like 'static inline' */
    غیرعلامتی حرف unwind_tables; /* create eh_frame section */

    /* warning switches */
    غیرعلامتی حرف warn_none;
    غیرعلامتی حرف warn_all;
    غیرعلامتی حرف warn_error;
    غیرعلامتی حرف warn_write_لڑیاں;
    غیرعلامتی حرف warn_unsupported;
    غیرعلامتی حرف warn_implicit_function_declaration;
    غیرعلامتی حرف warn_discarded_qualifiers;
    #تعریف_کرو WARN_ON  1 /* warning is on (-Woption) */
    غیرعلامتی حرف warn_عدد; /* temp var for tcc_warning_c() */

    غیرعلامتی حرف option_r; /* option -r */
    غیرعلامتی حرف do_bench; /* option -bench */
    غیرعلامتی حرف just_deps; /* option -M  */
    غیرعلامتی حرف gen_deps; /* option -MD  */
    غیرعلامتی حرف include_sys_deps; /* option -MD  */
    غیرعلامتی حرف gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    غیرعلامتی حرف do_debug;
    غیرعلامتی حرف dwarf;
    غیرعلامتی حرف do_backtrace;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    غیرعلامتی حرف do_bounds_check;
#اگر_ختم
    غیرعلامتی حرف test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    غیرعلامتی حرف gnu_ext;
    /* use TinyCC extensions */
    غیرعلامتی حرف tcc_ext;

    غیرعلامتی حرف dflag; /* -dX value */
    غیرعلامتی حرف Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#اگر_تعریف_شدہ TCC_ہدف_X86_64
    غیرعلامتی حرف nosse; /* For -mno-sse support. */
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_ARM
    غیرعلامتی حرف float_abi; /* float ABI of the generated code*/
#اگر_ختم

    غیرعلامتی حرف has_متن_addr;
    addr_t متن_addr; /* address of text section */
    غیرعلامتی section_align; /* section alignment */
#اگر_تعریف_شدہ TCC_ہدف_I386
    صحیح seg_سائز; /* 32. Can be 16 with i386 assembler (.code16) */
#اگر_ختم

    حرف *tcc_lib_راستہ; /* CONFIG_TCCDIR or -B option */
    حرف *soname; /* as specified on the command line (-soname) */
    حرف *rpath; /* as specified on the command line (-Wl,-rpath=) */
    حرف *elfint; /* -Wl,-I... on command line */
    حرف *elf_entryname; /* "_start" unless set */
    حرف *init_علامت; /* symbols to call at load-time (not used currently) */
    حرف *fini_علامت; /* symbols to call at unload-time (not used currently) */
    حرف *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    صحیح output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    صحیح output_format;
    /* nth test to run with -dt -run */
    صحیح تسلسل_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    صحیح nb_loaded_dlls;

    /* include paths */
    حرف **include_paths;
    صحیح nb_include_paths;

    حرف **sysinclude_paths;
    صحیح nb_sysinclude_paths;

    /* library paths */
    حرف **library_paths;
    صحیح nb_library_paths;

    /* crt?.o object path */
    حرف **crt_paths;
    صحیح nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    خالی *error_opaque;
    خالی (*error_func)(خالی *opaque, ثابت حرف *پیغام);
    صحیح error_سیٹ_jmp_enabled;
    jmp_buf error_jmp_buf;
    صحیح nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    حرف **ہدف_deps;
    صحیح nb_ہدف_deps;

    /* compilation */
    BufferedFile *include_ڈھیر[INCLUDE_ڈھیر_سائز];
    BufferedFile **include_ڈھیر_ptr;

    صحیح ifdef_ڈھیر[IFDEF_ڈھیر_سائز];
    صحیح *ifdef_ڈھیر_ptr;

    /* included files enclosed with #ifndef MACRO */
    صحیح cached_includes_hash[CACHED_INCLUDES_HASH_سائز];
    CachedInclude **cached_includes;
    صحیح nb_cached_includes;

    /* #pragma pack stack */
    صحیح pack_ڈھیر[PACK_ڈھیر_سائز];
    صحیح *pack_ڈھیر_ptr;
    حرف **pragma_libs;
    صحیح nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ساخت InlineFunc **inline_fns;
    صحیح nb_inline_fns;

    /* sections */
    Section **sections;
    صحیح nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    صحیح nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *متن_section, *ڈیٹا_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_متن_section; /* current section where function code is generated */
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#اگر_ختم
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
    غیرعلامتی طویل eh_آغاز;
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
    ساخت _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ساخت sym_attr *sym_attrs;
    صحیح nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #تعریف_کرو qrel s1->qrel

    addr_t tls_آغاز, tls_انتہا;

#اگر_تعریف_شدہ TCC_ہدف_RISCV64
    ساخت pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    صحیح nb_pcrel_hi_entries;
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_PE
    /* PE info */
    صحیح pe_subsystem;
    غیرعلامتی pe_characteristics;
    غیرعلامتی pe_dll_characteristics;
    غیرعلامتی pe_file_align;
    غیرعلامتی pe_ڈھیر_سائز;
    addr_t pe_imagebase;
# اگر defined(TCC_ہدف_X86_64) || defined(TCC_ہدف_ARM64)
    Section *uw_pdata;
    صحیح uw_sym;
    صحیح uw_xsym;
    غیرعلامتی uw_offs;
# endif
#اگر_ختم

#اگر defined TCC_ہدف_MACHO
    حرف *install_name;
    uint32_t compatibility_نسخہ;
    uint32_t current_نسخہ;
#اگر_ختم

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
    صحیح nb_sym_versions;
    ساخت sym_نسخہ *sym_versions;
    صحیح nb_sym_مقصد_نسخہ;
    صحیح *sym_مقصد_نسخہ;
    صحیح dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#اگر_ختم

#اگر_تعریف_شدہ TCC_IS_NATIVE
    ثابت حرف *تسلسل_main; /* entry for tcc_run() */
    خالی *تسلسل_ptr; /* runtime_memory */
    غیرعلامتی تسلسل_سائز; /* size of runtime_memory  */
    ثابت حرف *تسلسل_stdin; /* custom stdin file for run_main */
#اگر_تعریف_شدہ _WIN64
    خالی *تسلسل_function_جدول; /* unwind data */
#اگر_ختم
    ساخت TCCState *اگلا;
    ساخت rt_context *rc; /* pointer to backtrace info block */
    خالی *تسلسل_lj, *تسلسل_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    خالی *bt_ڈیٹا;
#اگر_ختم

#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    صحیح rt_عدد_callers;
#اگر_ختم

    /* benchmark info */
    صحیح کل_idents;
    صحیح کل_سطریں;
    غیرعلامتی صحیح کل_بائٹیں;
    غیرعلامتی صحیح کل_output[4];

    /* used by tcc_load_ldscript */
    غیرعلامتی حرف *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ثابت حرف *current_filename;

    /* used by main and tcc_parse_args only */
    ساخت filespec **files; /* files seen on command line */
    صحیح nb_files; /* number thereof */
    صحیح nb_libraries; /* number of libs thereof */
    حرف *outfile; /* output filename */
    حرف *deps_outfile; /* option -MF */
    صحیح argc;
    حرف **argv;
    /* -Wl options */
    حرف **link_argv;
    صحیح link_argc, link_optind;
};

ساخت filespec {
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

#تعریف_کرو VT_STRUCT_سرکاؤ 20     /* shift for bitfield shift values (32 - 2*6) */
#تعریف_کرو VT_STRUCT_نقاب (((1U << (6+6)) - 1) << VT_STRUCT_سرکاؤ | VT_BITFIELD)
#تعریف_کرو ثنائی_ہندسہ_POS(t) (((t) >> VT_STRUCT_سرکاؤ) & 0x3f)
#تعریف_کرو ثنائی_ہندسہ_سائز(t) (((t) >> (VT_STRUCT_سرکاؤ + 6)) & 0x3f)

#تعریف_کرو VT_UNION    (1 << VT_STRUCT_سرکاؤ | VT_STRUCT)
#تعریف_کرو VT_ENUM     (2 << VT_STRUCT_سرکاؤ) /* integral type is an enum really */
#تعریف_کرو VT_ENUM_VAL (3 << VT_STRUCT_سرکاؤ) /* integral type is an enum constant really */

#تعریف_کرو IS_ENUM(t) ((t & VT_STRUCT_نقاب) == VT_ENUM)
#تعریف_کرو IS_ENUM_VAL(t) ((t & VT_STRUCT_نقاب) == VT_ENUM_VAL)
#تعریف_کرو IS_UNION(t) ((t & (VT_STRUCT_نقاب|VT_BTYPE)) == VT_UNION)

#تعریف_کرو VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#تعریف_کرو VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#تعریف_کرو VT_TYPE (~(VT_STORAGE|VT_STRUCT_نقاب))

/* symbol was created by tccasm.c first */
#تعریف_کرو VT_ASM (VT_VOID | 4 << VT_STRUCT_سرکاؤ)
#تعریف_کرو VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_سرکاؤ)
#تعریف_کرو IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_نقاب) & ~(1<<VT_STRUCT_سرکاؤ))) == VT_ASM)
#تعریف_کرو IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_نقاب)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#تعریف_کرو VT_BT_ARRAY (6 << VT_STRUCT_سرکاؤ)
#تعریف_کرو IS_BT_ARRAY(t) ((t & VT_STRUCT_نقاب) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#تعریف_کرو BFVAL(M,N) ((غیرعلامتی)((M) & ~((M) << 1)) * (N))
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

#تعریف_کرو TOK_تفویض(t) (t >= TOK_A_جوڑو && t <= TOK_A_SAR)
#تعریف_کرو TOK_تفویض_OP(t) ("+-*/%&|^<>"[t - TOK_A_جوڑو])

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

شمار tcc_token {
    TOK_آخری = TOK_IDENT - 1
#تعریف_کرو DEF(id, str) ,id
#شامل "tcctok.h"
#تعریف_منسوخ DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#تعریف_کرو TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_ڈیٹا ساخت TCCState *tcc_state;
ST_ڈیٹا خالی** stk_ڈیٹا;
ST_ڈیٹا صحیح nb_stk_ڈیٹا;
ST_ڈیٹا صحیح g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC حرف *pstrcpy(حرف *buf, سائز_t buf_سائز, ثابت حرف *s);
ST_FUNC حرف *pstrcat(حرف *buf, سائز_t buf_سائز, ثابت حرف *s);
ST_FUNC حرف *pstrncpy(حرف *برآمد, سائز_t buf_سائز, ثابت حرف *s, سائز_t عدد);
PUB_FUNC حرف *tcc_basename(ثابت حرف *name);
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC خالی tcc_free(خالی *ptr);
PUB_FUNC خالی *tcc_malloc(غیرعلامتی طویل سائز);
PUB_FUNC خالی *tcc_mallocz(غیرعلامتی طویل سائز);
PUB_FUNC خالی *tcc_realloc(خالی *ptr, غیرعلامتی طویل سائز);
PUB_FUNC حرف *tcc_strdup(ثابت حرف *str);

#اگر_تعریف_شدہ MEM_DEBUG
#تعریف_کرو tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کرو tcc_malloc(سائز)        tcc_malloc_debug(سائز, __FILE__, __LINE__)
#تعریف_کرو tcc_mallocz(سائز)       tcc_mallocz_debug(سائز, __FILE__, __LINE__)
#تعریف_کرو tcc_realloc(ptr,سائز)   tcc_realloc_debug(ptr, سائز, __FILE__, __LINE__)
#تعریف_کرو tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC خالی tcc_free_debug(خالی *ptr);
PUB_FUNC خالی *tcc_malloc_debug(غیرعلامتی طویل سائز, ثابت حرف *file, صحیح سطر);
PUB_FUNC خالی *tcc_mallocz_debug(غیرعلامتی طویل سائز, ثابت حرف *file, صحیح سطر);
PUB_FUNC خالی *tcc_realloc_debug(خالی *ptr, غیرعلامتی طویل سائز, ثابت حرف *file, صحیح سطر);
PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحیح سطر);
#اگر_ختم

ST_FUNC خالی libc_free(خالی *ptr);
/* defined to be not used */
#تعریف_کرو آزاد(p) use_tcc_free(p)
#تعریف_کرو حافظہ_دو(s) use_tcc_malloc(s)
#تعریف_کرو realloc(p, s) use_tcc_realloc(p, s)
#تعریف_منسوخ strdup
#تعریف_کرو strdup(s) use_tcc_strdup(s)
PUB_FUNC صحیح _tcc_error_noabort(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN خالی _tcc_error(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC خالی _tcc_warning(ثابت حرف *fmt, ...) PRINTF_LIKE(1,2);
#تعریف_کرو tcc_اندرونی_error(پیغام) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,پیغام)

/* other utilities */
ST_FUNC خالی dynarray_جوڑو(خالی *ptab, صحیح *nb_ptr, خالی *ڈیٹا);
ST_FUNC خالی dynarray_reset(خالی *pp, صحیح *n);
ST_INLN خالی cstr_ccat(CString *cstr, صحیح ch);
ST_FUNC خالی cstr_cat(CString *cstr, ثابت حرف *str, صحیح len);
ST_FUNC خالی cstr_wccat(CString *cstr, صحیح ch);
ST_FUNC خالی cstr_new(CString *cstr);
ST_FUNC خالی cstr_free(CString *cstr);
ST_FUNC صحیح cstr_printf(CString *cs, ثابت حرف *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC صحیح cstr_vprintf(CString *cstr, ثابت حرف *fmt, va_list ap);
ST_FUNC خالی cstr_reset(CString *cstr);
ST_FUNC خالی tcc_open_bf(TCCState *s1, ثابت حرف *filename, صحیح initlen);
ST_FUNC صحیح tcc_open(TCCState *s1, ثابت حرف *filename);
ST_FUNC خالی tcc_close(خالی);

/* mark a memory pointer on stack for cleanup after errors */
#تعریف_کرو stk_ڈالو(p) dynarray_جوڑو(&stk_ڈیٹا, &nb_stk_ڈیٹا, p)
#تعریف_کرو stk_نکالو() (--nb_stk_ڈیٹا)
/* mark CString on stack for cleanup errors */
#تعریف_کرو cstr_new_s(cstr) (cstr_new(cstr), stk_ڈالو(&(cstr)->ڈیٹا))
#تعریف_کرو cstr_free_s(cstr) (cstr_free(cstr), stk_نکالو())

ST_FUNC صحیح tcc_جوڑو_file_اندرونی(TCCState *s1, ثابت حرف *filename, صحیح flags);
/* flags: */
#تعریف_کرو AFF_PRINT_ERROR     0x10 /* print error if file not found */
#تعریف_کرو AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#تعریف_کرو AFF_TYPE_BIN        0x40 /* file to add is binary */
#تعریف_کرو AFF_پورا_ARCHIVE   0x80 /* load all objects from archive */
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
#تعریف_کرو FILE_NOT_ملا -2
#تعریف_کرو FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
ST_FUNC صحیح tcc_جوڑو_crt(TCCState *s, ثابت حرف *filename);
#اگر_ختم
ST_FUNC صحیح tcc_جوڑو_dll(TCCState *s, ثابت حرف *filename, صحیح flags);
ST_FUNC صحیح tcc_جوڑو_support(TCCState *s1, ثابت حرف *filename);
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
ST_FUNC خالی tcc_جوڑو_bcheck(TCCState *s1);
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
ST_FUNC خالی tcc_جوڑو_btstub(TCCState *s1);
#اگر_ختم
ST_FUNC خالی tcc_جوڑو_pragma_libs(TCCState *s1);
PUB_FUNC صحیح tcc_جوڑو_library_err(TCCState *s, ثابت حرف *f);
PUB_FUNC خالی tcc_print_stats(TCCState *s, غیرعلامتی کل_وقت);
PUB_FUNC صحیح tcc_parse_دلائل(TCCState *s, صحیح *argc, حرف ***argv);
#اگر_تعریف_شدہ _WIN32
ST_FUNC حرف *normalize_slashes(حرف *راستہ);
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m);
PUB_FUNC صحیح tcc_fclose(FILE *f);
#ورنہ
# define tcc_fopen fopen
# define tcc_fclose fclose
#اگر_ختم
ST_FUNC DLLReference *tcc_جوڑو_dllref(TCCState *s1, ثابت حرف *dllname, صحیح level);
ST_FUNC حرف *tcc_بھرو_متن(صحیح fd);
/* for #pragma once */
ST_FUNC صحیح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2);

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

ST_ڈیٹا ساخت BufferedFile *file;
ST_ڈیٹا صحیح tok;
ST_ڈیٹا CValue tokc;
ST_ڈیٹا ثابت صحیح *macro_ptr;
ST_ڈیٹا صحیح parse_flags;
ST_ڈیٹا صحیح tok_flags;
ST_ڈیٹا CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_ڈیٹا صحیح tok_ident;
ST_ڈیٹا TokenSym **جدول_ident;
ST_ڈیٹا صحیح pp_اظہاریہ;

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

شمار سطر_macro_output_format {
    سطر_MACRO_OUTPUT_FORMAT_GCC,
    سطر_MACRO_OUTPUT_FORMAT_NONE,
    سطر_MACRO_OUTPUT_FORMAT_STD,
    سطر_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحیح len);
ST_FUNC صحیح tok_alloc_const(ثابت حرف *str);
ST_FUNC ثابت حرف *get_tok_str(صحیح v, CValue *cv);
ST_FUNC خالی begin_macro(TokenString *str, صحیح alloc);
ST_FUNC خالی انتہا_macro(خالی);
ST_FUNC صحیح سیٹ_idnum(صحیح c, صحیح val);
ST_INLN خالی tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(خالی);
ST_FUNC خالی tok_str_free(TokenString *s);
ST_FUNC خالی tok_str_free_str(صحیح *str);
ST_FUNC خالی tok_str_جوڑو(TokenString *s, صحیح t);
ST_FUNC خالی tok_str_جوڑو_tok(TokenString *s);
ST_INLN خالی define_ڈالو(صحیح v, صحیح macro_type, صحیح *str, Sym *پہلا_arg);
ST_FUNC خالی define_undef(Sym *s);
ST_INLN Sym *define_ڈھونڈو(صحیح v);
ST_FUNC خالی free_متعین_کرتا(Sym *b);
ST_FUNC خالی parse_define(خالی);
ST_FUNC خالی skip_مقصد_eol(صحیح warn);
ST_FUNC خالی preprocess(صحیح is_bof);
ST_FUNC خالی اگلا(خالی);
ST_INLN خالی unget_tok(صحیح آخری_tok);
ST_FUNC خالی preprocess_آغاز(TCCState *s1, صحیح filetype);
ST_FUNC خالی preprocess_انتہا(TCCState *s1);
ST_FUNC خالی tccpp_new(TCCState *s);
ST_FUNC خالی tccpp_delete(TCCState *s);
ST_FUNC خالی tccpp_putfile(ثابت حرف *filename);
ST_FUNC صحیح tcc_preprocess(TCCState *s1);
ST_FUNC خالی skip(صحیح c);
ST_FUNC NORETURN خالی expect(ثابت حرف *پیغام);
ST_FUNC خالی pp_error(CString *cs);


/* space excluding newline */
ساکن اندرونی صحیح is_space(صحیح ch) {
    واپس ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ساکن اندرونی صحیح isid(صحیح c) {
    واپس (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ساکن اندرونی صحیح isnum(صحیح c) {
    واپس c >= '0' && c <= '9';
}
ساکن اندرونی صحیح isoct(صحیح c) {
    واپس c >= '0' && c <= '7';
}
ساکن اندرونی صحیح toup(صحیح c) {
    واپس (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#تعریف_کرو SYM_POOL_NB (8192 / حجم(Sym))

ST_ڈیٹا Sym *global_ڈھیر;
ST_ڈیٹا Sym *local_ڈھیر;
ST_ڈیٹا Sym *local_label_ڈھیر;
ST_ڈیٹا Sym *global_label_ڈھیر;
ST_ڈیٹا Sym *define_ڈھیر;
ST_ڈیٹا CType int_type, func_old_type, char_اشارہ_گر_type;
ST_ڈیٹا SValue *vtop;
ST_ڈیٹا صحیح rsym, anon_sym, ind, loc;
ST_ڈیٹا حرف debug_modes;

ST_ڈیٹا صحیح nocode_wanted; /* true if no code generation wanted for an expression */
ST_ڈیٹا صحیح global_اظہاریہ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_ڈیٹا CType func_vt; /* current function return type (used by return instruction) */
ST_ڈیٹا صحیح func_var; /* true if current function is variadic */
ST_ڈیٹا صحیح func_vc; /* stack address for implicit struct return storage */
ST_ڈیٹا صحیح func_ind; /* function start address */
ST_ڈیٹا ثابت حرف *funcname;

ST_FUNC خالی tccgen_init(TCCState *s1);
ST_FUNC صحیح tccgen_compile(TCCState *s1);
ST_FUNC خالی tccgen_اختتام(TCCState *s1);
ST_FUNC خالی check_vstack(خالی);

ST_INLN صحیح is_float(صحیح t);
ST_FUNC صحیح ieee_finite(دوہرا d);
ST_FUNC صحیح exact_log2p1(صحیح i);
ST_FUNC خالی test_lvalue(خالی);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC خالی update_storage(Sym *sym);
ST_FUNC خالی put_extern_sym2(Sym *sym, صحیح sh_عدد, addr_t قدر, غیرعلامتی طویل سائز, صحیح can_جوڑو_underscore);
ST_FUNC خالی put_extern_sym(Sym *sym, Section *section, addr_t قدر, غیرعلامتی طویل سائز);
#اگر PTR_سائز == 4
ST_FUNC خالی greloc(Section *s, Sym *sym, غیرعلامتی طویل انحراف, صحیح type);
#اگر_ختم
ST_FUNC خالی greloca(Section *s, Sym *sym, غیرعلامتی طویل انحراف, صحیح type, addr_t addend);

ST_INLN خالی sym_free(Sym *sym);
ST_FUNC Sym *sym_ڈالو(صحیح v, CType *type, صحیح r, صحیح c);
ST_FUNC خالی sym_نکالو(Sym **ptop, Sym *b, صحیح keep);
ST_FUNC Sym *sym_push2(Sym **ps, صحیح v, صحیح t, صحیح c);
ST_FUNC Sym *sym_find2(Sym *s, صحیح v);
ST_INLN Sym *sym_ڈھونڈو(صحیح v);
ST_FUNC Sym *label_ڈھونڈو(صحیح v);
ST_FUNC Sym *label_ڈالو(Sym **ptop, صحیح v, صحیح flags);
ST_FUNC خالی label_نکالو(Sym **ptop, Sym *slast, صحیح keep);
ST_INLN Sym *struct_ڈھونڈو(صحیح v);

ST_FUNC Sym *global_identifier_ڈالو(صحیح v, صحیح t, صحیح c);
ST_FUNC Sym *external_global_sym(صحیح v, CType *type);
ST_FUNC Sym *external_helper_sym(صحیح v);
ST_FUNC خالی vpush_helper_func(صحیح v);
ST_FUNC خالی vset(CType *type, صحیح r, صحیح v);
ST_FUNC خالی vset_VT_CMP(صحیح op);
ST_FUNC خالی vpushi(صحیح v);
ST_FUNC خالی vpushv(SValue *v);
ST_FUNC خالی vpushsym(CType *type, Sym *sym);
ST_FUNC خالی vswap(خالی);
ST_FUNC خالی vrott(صحیح n);
ST_FUNC خالی vrotb(صحیح n);
ST_FUNC خالی vrev(صحیح n);
ST_FUNC خالی vpop(خالی);
#اگر PTR_سائز == 4
ST_FUNC خالی lexpand(خالی);
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_ARM
ST_FUNC صحیح get_reg_ex(صحیح rc, صحیح rc2);
#اگر_ختم
ST_FUNC خالی save_reg(صحیح r);
ST_FUNC خالی save_reg_upstack(صحیح r, صحیح n);
ST_FUNC صحیح get_reg(صحیح rc);
ST_FUNC خالی save_regs(صحیح n);
ST_FUNC خالی gaddrof(خالی);
ST_FUNC صحیح gv(صحیح rc);
ST_FUNC خالی gv2(صحیح rc1, صحیح rc2);
ST_FUNC خالی gen_op(صحیح op);
ST_FUNC صحیح type_سائز(CType *type, صحیح *a);
ST_FUNC خالی mk_اشارہ_گر(CType *type);
ST_FUNC خالی vstore(خالی);
ST_FUNC خالی inc(صحیح post, صحیح c);
ST_FUNC CString* parse_mult_str(ثابت حرف *پیغام);
ST_FUNC CString* parse_asm_str(خالی);
ST_FUNC خالی indir(خالی);
ST_FUNC خالی unary(خالی);
ST_FUNC خالی gexpr(خالی);
ST_FUNC صحیح اظہاریہ_const(خالی);
#اگر defined CONFIG_TCC_BCHECK || defined TCC_ہدف_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, غیرعلامتی طویل انحراف, غیرعلامتی طویل سائز);
#اگر_ختم
#اگر defined TCC_ہدف_X86_64 && !defined TCC_ہدف_PE
ST_FUNC صحیح classify_x86_64_va_arg(CType *ty);
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
ST_FUNC خالی gbound_دلائل(صحیح nb_دلائل);
ST_ڈیٹا صحیح func_bound_جوڑو_epilog;
#اگر_ختم
ST_FUNC Sym *gfunc_سیٹ_param(Sym *s, صحیح c, صحیح byref);

/* ------------ tccelf.c ------------ */

#تعریف_کرو TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#تعریف_کرو TCC_OUTPUT_FORMAT_ثنائی 1 /* binary image output */
#تعریف_کرو TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#تعریف_کرو TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#تعریف_کرو ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

قسمتعریف ساخت {
    غیرعلامتی صحیح n_strx;         /* index into string table of name */
    غیرعلامتی حرف n_type;         /* type of symbol */
    غیرعلامتی حرف n_other;        /* misc info (usually empty) */
    غیرعلامتی مختصر n_desc;        /* description field */
    غیرعلامتی صحیح n_قدر;        /* value of symbol */
} Stab_Sym;

ST_FUNC خالی tccelf_new(TCCState *s);
ST_FUNC خالی tccelf_delete(TCCState *s);
ST_FUNC خالی tccelf_begin_file(TCCState *s1);
ST_FUNC خالی tccelf_انتہا_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ثابت حرف *name, صحیح sh_type, صحیح sh_flags);
ST_FUNC خالی section_realloc(Section *sec, غیرعلامتی طویل new_سائز);
ST_FUNC سائز_t section_جوڑو(Section *sec, addr_t سائز, صحیح align);
ST_FUNC خالی *section_ptr_جوڑو(Section *sec, addr_t سائز);
ST_FUNC Section *ڈھونڈو_section(TCCState *s1, ثابت حرف *name);
ST_FUNC خالی free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ثابت حرف *symtab_name, صحیح sh_type, صحیح sh_flags, ثابت حرف *strtab_name, ثابت حرف *hash_name, صحیح hash_sh_flags);
ST_FUNC خالی init_symtab(Section *s);

ST_FUNC صحیح put_elf_str(Section *s, ثابت حرف *sym);
ST_FUNC صحیح put_elf_sym(Section *s, addr_t قدر, غیرعلامتی طویل سائز, صحیح info, صحیح other, صحیح shndx, ثابت حرف *name);
ST_FUNC صحیح سیٹ_elf_sym(Section *s, addr_t قدر, غیرعلامتی طویل سائز, صحیح info, صحیح other, صحیح shndx, ثابت حرف *name);
ST_FUNC صحیح ڈھونڈو_elf_sym(Section *s, ثابت حرف *name);
ST_FUNC خالی put_elf_reloc(Section *symtab, Section *s, غیرعلامتی طویل انحراف, صحیح type, صحیح علامت);
ST_FUNC خالی put_elf_reloca(Section *symtab, Section *s, غیرعلامتی طویل انحراف, صحیح type, صحیح علامت, addr_t addend);

ST_FUNC خالی resolve_common_syms(TCCState *s1);
ST_FUNC خالی relocate_syms(TCCState *s1, Section *symtab, صحیح do_resolve);
ST_FUNC خالی relocate_sections(TCCState *s1);

ST_FUNC ssize_t بھرا_read(صحیح fd, خالی *buf, سائز_t گنتی_2);
ST_FUNC خالی *بھرو_ڈیٹا(صحیح fd, غیرعلامتی طویل file_انحراف, غیرعلامتی طویل سائز);
ST_FUNC صحیح tcc_object_type(صحیح fd, ElfW(Ehdr) *h);
ST_FUNC صحیح tcc_بھرو_object_file(TCCState *s1, صحیح fd, غیرعلامتی طویل file_انحراف);
ST_FUNC صحیح tcc_بھرو_archive(TCCState *s1, صحیح fd, صحیح alacarte);
ST_FUNC خالی جوڑو_array(TCCState *s1, ثابت حرف *sec, صحیح c);

ST_FUNC ساخت sym_attr *get_sym_attr(TCCState *s1, صحیح اشاریہ, صحیح alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ثابت حرف *name, صحیح err, صحیح forc);
ST_FUNC خالی list_elf_symbols(TCCState *s, خالی *ctx,
    خالی (*علامت_cb)(خالی *ctx, ثابت حرف *name, ثابت خالی *val));
ST_FUNC صحیح سیٹ_global_sym(TCCState *s1, ثابت حرف *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#تعریف_کرو for_each_elem(sec, startoff, elem, type) \
    برائے (elem = (type *) sec->ڈیٹا + startoff; \
         elem < (type *) (sec->ڈیٹا + sec->ڈیٹا_انحراف); elem++)

#اگر_غیر_تعریف_شدہ ELF_OBJ_ONLY
ST_FUNC صحیح tcc_بھرو_dll(TCCState *s1, صحیح fd, ثابت حرف *filename, صحیح level);
ST_FUNC صحیح tcc_بھرو_ldscript(TCCState *s1, صحیح fd);
ST_FUNC خالی tccelf_جوڑو_crtbegin(TCCState *s1);
ST_FUNC خالی tccelf_جوڑو_crtend(TCCState *s1);
#اگر_ختم
#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
ST_FUNC خالی tcc_جوڑو_runtime(TCCState *s1);
#اگر_ختم

/* ------------ xxx-link.c ------------ */

#اگر_غیر_تعریف_شدہ TCC_ہدف_PE
ST_FUNC صحیح رمز_reloc (صحیح reloc_type);
ST_FUNC صحیح gotplt_اندراج_type (صحیح reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
شمار gotplt_اندراج {
    NO_GOTPLT_اندراج,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_اندراج,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_اندراج	/* always generate (eg. PLTOFF relocs) */
};
#تعریف_کرو NEED_RELOC_TYPE
#اگر !defined TCC_ہدف_MACHO || defined TCC_IS_NATIVE
ST_FUNC غیرعلامتی create_plt_اندراج(TCCState *s1, غیرعلامتی got_انحراف, ساخت sym_attr *attr);
ST_FUNC خالی relocate_plt(TCCState *s1);
ST_FUNC خالی build_got_entries(TCCState *s1, صحیح got_sym); /* in tccelf.c */
#تعریف_کرو NEED_BUILD_GOT
#اگر_ختم
#اگر_ختم

ST_FUNC خالی relocate(TCCState *s1, ElfW_Rel *rel, صحیح type, غیرعلامتی حرف *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_ڈیٹا ثابت حرف * ثابت ہدف_machine_defs;
ST_ڈیٹا ثابت صحیح reg_classes[NB_REGS];

ST_FUNC خالی gsym_addr(صحیح t, صحیح a);
ST_FUNC خالی gsym(صحیح t);
ST_FUNC خالی بھرو(صحیح r, SValue *sv);
ST_FUNC خالی store(صحیح r, SValue *v);
ST_FUNC صحیح gfunc_sret(CType *vt, صحیح variadic, CType *ret, صحیح *align, صحیح *regsize);
ST_FUNC خالی gfunc_call(صحیح nb_دلائل);
ST_FUNC خالی gfunc_prolog(Sym *func_sym);
ST_FUNC خالی gfunc_epilog(خالی);
ST_FUNC خالی gen_fill_nops(صحیح);
ST_FUNC صحیح gjmp(صحیح t);
ST_FUNC خالی gjmp_addr(صحیح a);
ST_FUNC صحیح gjmp_cond(صحیح op, صحیح t);
ST_FUNC صحیح gjmp_append(صحیح n, صحیح t);
ST_FUNC خالی gen_opi(صحیح op);
ST_FUNC خالی gen_opf(صحیح op);
ST_FUNC خالی gen_cvt_ftoi(صحیح t);
ST_FUNC خالی gen_cvt_itof(صحیح t);
ST_FUNC خالی gen_cvt_ftof(صحیح t);
ST_FUNC خالی ggoto(خالی);
#اگر_غیر_تعریف_شدہ TCC_ہدف_C67
ST_FUNC خالی o(غیرعلامتی صحیح c);
#اگر_ختم
ST_FUNC خالی gen_vla_sp_save(صحیح addr);
ST_FUNC خالی gen_vla_sp_restore(صحیح addr);
ST_FUNC خالی gen_vla_alloc(CType *type, صحیح align);

ساکن اندرونی uint16_t read16le(غیرعلامتی حرف *p) {
    واپس p[0] | (uint16_t)p[1] << 8;
}
ساکن اندرونی خالی write16le(غیرعلامتی حرف *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ساکن اندرونی uint32_t read32le(غیرعلامتی حرف *p) {
  واپس read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ساکن اندرونی خالی write32le(غیرعلامتی حرف *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ساکن اندرونی خالی add32le(غیرعلامتی حرف *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ساکن اندرونی uint64_t read64le(غیرعلامتی حرف *p) {
  واپس read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ساکن اندرونی خالی write64le(غیرعلامتی حرف *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ساکن اندرونی خالی add64le(غیرعلامتی حرف *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#اگر defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64 || defined TCC_ہدف_ARM
ST_FUNC خالی g(صحیح c);
ST_FUNC خالی gen_le16(صحیح c);
ST_FUNC خالی gen_le32(صحیح c);
#اگر_ختم
#اگر defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64
ST_FUNC خالی gen_addr32(صحیح r, Sym *sym, صحیح c);
ST_FUNC خالی gen_addrpc32(صحیح r, Sym *sym, صحیح c);
ST_FUNC خالی gen_cvt_csti(صحیح t);
ST_FUNC خالی gen_increment_tcov (SValue *sv);
#اگر_ختم

/* ------------ x86_64-gen.c ------------ */
#اگر_تعریف_شدہ TCC_ہدف_X86_64
ST_FUNC خالی gen_opl(صحیح op);
#اگر_تعریف_شدہ TCC_ہدف_PE
ST_FUNC خالی gen_vla_نتیجہ(صحیح addr);
#اگر_ختم
ST_FUNC خالی gen_cvt_sxtw(خالی);
ST_FUNC خالی gen_cvt_csti(صحیح t);
#اگر_ختم

/* ------------ arm-gen.c ------------ */
#اگر_تعریف_شدہ TCC_ہدف_ARM
#اگر defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ثابت حرف *default_elfinterp(ساخت TCCState *s);
#اگر_ختم
ST_FUNC خالی arm_init(ساخت TCCState *s);
ST_FUNC خالی gen_increment_tcov (SValue *sv);
#اگر_ختم

/* ------------ arm64-gen.c ------------ */
#اگر_تعریف_شدہ TCC_ہدف_ARM64
ST_FUNC خالی gen_opl(صحیح op);
ST_FUNC خالی gfunc_return(CType *func_type);
ST_FUNC خالی gen_va_آغاز(خالی);
ST_FUNC خالی gen_va_arg(CType *t);
ST_FUNC خالی gen_clear_cache(خالی);
ST_FUNC خالی gen_cvt_sxtw(خالی);
ST_FUNC خالی gen_cvt_csti(صحیح t);
ST_FUNC خالی gen_increment_tcov (SValue *sv);
#اگر_ختم

/* ------------ riscv64-gen.c ------------ */
#اگر_تعریف_شدہ TCC_ہدف_RISCV64
ST_FUNC خالی gen_opl(صحیح op);
ST_FUNC خالی gen_va_آغاز(خالی);
ST_FUNC خالی arch_transfer_ret_regs(صحیح);
ST_FUNC خالی gen_cvt_sxtw(خالی);
ST_FUNC خالی gen_cvt_csti(صحیح t);
ST_FUNC خالی gen_increment_tcov (SValue *sv);
ST_FUNC خالی gen_clear_cache(خالی);
#اگر_ختم

/* ------------ c67-gen.c ------------ */
#اگر_تعریف_شدہ TCC_ہدف_C67
#اگر_ختم

/* ------------ tcccoff.c ------------ */
#اگر_تعریف_شدہ TCC_ہدف_COFF
ST_FUNC صحیح tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC صحیح tcc_بھرو_coff(TCCState * s1, صحیح fd);
#اگر_ختم

/* ------------ tccasm.c ------------ */
ST_FUNC خالی asm_instr(خالی);
ST_FUNC خالی asm_global_instr(خالی);
ST_FUNC صحیح tcc_assemble(TCCState *s1, صحیح do_preprocess);
#اگر_تعریف_شدہ CONFIG_TCC_ASM
ST_FUNC صحیح ڈھونڈو_constraint(ASMOperand *operands, صحیح nb_operands, ثابت حرف *name, ثابت حرف **pp);
ST_FUNC Sym* get_asm_sym(صحیح name, Sym *csym);
ST_FUNC خالی asm_اظہاریہ(TCCState *s1, اظہاریہ_قدر *pe);
ST_FUNC صحیح asm_int_اظہاریہ(TCCState *s1);
#اگر PTR_سائز == 8
ST_FUNC خالی gen_expr64(اظہاریہ_قدر *pe);
#اگر_ختم
/* ------------ i386-asm.c ------------ */
ST_FUNC خالی gen_expr32(اظہاریہ_قدر *pe);
ST_FUNC خالی asm_opcode(TCCState *s1, صحیح opcode);
ST_FUNC صحیح asm_parse_regvar(صحیح t);
ST_FUNC خالی asm_compute_constraints(ASMOperand *operands, صحیح nb_operands, صحیح nb_outputs, ثابت uint8_t *clobber_regs, صحیح *pout_reg);
ST_FUNC خالی subst_asm_عملیہ(CString *جوڑو_str, SValue *sv, صحیح modifier);
ST_FUNC خالی asm_gen_رمز(ASMOperand *operands, صحیح nb_operands, صحیح nb_outputs, صحیح is_output, uint8_t *clobber_regs, صحیح برآمد_reg);
ST_FUNC خالی asm_clobber(uint8_t *clobber_regs, ثابت حرف *str);
#اگر_ختم

/* ------------ tccpe.c -------------- */
#اگر_تعریف_شدہ TCC_ہدف_PE
ST_FUNC صحیح pe_بھرو_file(ساخت TCCState *s1, صحیح fd, ثابت حرف *filename);
ST_FUNC صحیح pe_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحیح pe_putimport(TCCState *s1, صحیح dllindex, ثابت حرف *name, addr_t قدر);
ST_FUNC صحیح pe_setsubsy(TCCState *s1, ثابت حرف *arg);
#اگر defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64
#اگر_ختم
#اگر defined(TCC_ہدف_X86_64) || defined(TCC_ہدف_ARM64)
ST_FUNC خالی pe_جوڑو_unwind_ڈیٹا(غیرعلامتی آغاز, غیرعلامتی انتہا, غیرعلامتی ڈھیر);
#اگر_ختم
PUB_FUNC صحیح tcc_get_dllexports(ثابت حرف *filename, حرف **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#اگر_ختم
#تعریف_کرو ST_ASM_سیٹ 0x04

/* ------------ tccmacho.c ----------------- */
#اگر_تعریف_شدہ TCC_ہدف_MACHO
ST_FUNC صحیح macho_output_file(TCCState * s1, ثابت حرف *filename);
ST_FUNC صحیح macho_بھرو_dll(TCCState *s1, صحیح fd, ثابت حرف *filename, صحیح lev);
ST_FUNC صحیح macho_بھرو_tbd(TCCState *s1, صحیح fd, ثابت حرف *filename, صحیح lev);
#اگر_تعریف_شدہ TCC_IS_NATIVE
ST_FUNC خالی tcc_جوڑو_macos_sdkpath(TCCState* s);
ST_FUNC حرف* macho_tbd_soname(صحیح fd);
#اگر_ختم
#اگر_ختم
/* ------------ tccrun.c ----------------- */
#اگر_تعریف_شدہ TCC_IS_NATIVE
#اگر_تعریف_شدہ CONFIG_TCC_STATIC
#تعریف_کرو RTLD_LAZY       0x001
#تعریف_کرو RTLD_NOW        0x002
#تعریف_کرو RTLD_GLOBAL     0x100
#تعریف_کرو RTLD_DEFAULT    تہی
/* dummy function for profiling */
ST_FUNC خالی *dlopen(ثابت حرف *filename, صحیح flag);
ST_FUNC خالی dlclose(خالی *p);
ST_FUNC ثابت حرف *dlerror(خالی);
ST_FUNC خالی *dlsym(خالی *handle, ثابت حرف *علامت);
#اگر_ختم
ST_FUNC خالی tcc_تسلسل_free(TCCState *s1);
#اگر_ختم

/* ------------ tcctools.c ----------------- */
#اگر 0 /* included in tcc.c */
ST_FUNC صحیح tcc_tool_ar(TCCState *s, صحیح argc, حرف **argv);
#اگر_تعریف_شدہ TCC_ہدف_PE
ST_FUNC صحیح tcc_tool_impdef(TCCState *s, صحیح argc, حرف **argv);
#اگر_ختم
ST_FUNC صحیح tcc_tool_cross(TCCState *s, حرف **argv, صحیح option);
ST_FUNC صحیح gen_makedeps(TCCState *s, ثابت حرف *ہدف, ثابت حرف *filename);
#اگر_ختم

/* ------------ tccdbg.c ------------ */

ST_FUNC خالی tcc_debug_new(TCCState *s);

ST_FUNC خالی tcc_debug_آغاز(TCCState *s1);
ST_FUNC خالی tcc_debug_انتہا(TCCState *s1);
ST_FUNC خالی tcc_debug_bincl(TCCState *s1);
ST_FUNC خالی tcc_debug_eincl(TCCState *s1);
ST_FUNC خالی tcc_debug_newfile(TCCState *s1);

ST_FUNC خالی tcc_debug_سطر(TCCState *s1);
ST_FUNC خالی tcc_جوڑو_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC خالی tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC خالی tcc_debug_prolog_epilog(TCCState *s1, صحیح قدر);
ST_FUNC خالی tcc_debug_funcend(TCCState *s1, صحیح سائز);
ST_FUNC خالی tcc_debug_extern_sym(TCCState *s1, Sym *sym, صحیح sh_عدد, صحیح sym_bind, صحیح sym_type);
ST_FUNC خالی tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC خالی tcc_debug_stabn(TCCState *s1, صحیح type, صحیح قدر);
ST_FUNC خالی tcc_debug_fix_forw(TCCState *s1, CType *t);

#اگر !(defined ELF_OBJ_ONLY || defined TCC_ہدف_ARM || defined TARGETOS_BSD)
ST_FUNC خالی tcc_eh_چوکھٹا_آغاز(TCCState *s1);
ST_FUNC خالی tcc_eh_چوکھٹا_انتہا(TCCState *s1);
ST_FUNC خالی tcc_eh_چوکھٹا_hdr(TCCState *s1, صحیح final);
#تعریف_کرو TCC_EH_چوکھٹا 1
#اگر_ختم

ST_FUNC خالی tcc_tcov_آغاز(TCCState *s1);
ST_FUNC خالی tcc_tcov_انتہا(TCCState *s1);
ST_FUNC خالی tcc_tcov_check_سطر(TCCState *s1, صحیح آغاز);
ST_FUNC خالی tcc_tcov_بلاک_انتہا(TCCState *s1, صحیح سطر);
ST_FUNC خالی tcc_tcov_بلاک_begin(TCCState *s1);
ST_FUNC خالی tcc_tcov_reset_ind(TCCState *s1);

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
#تعریف_کرو	dwarf_read_1(ln,انتہا) \
	((ln) < (انتہا) ? *(ln)++ : 0)
#تعریف_کرو	dwarf_read_2(ln,انتہا) \
	((ln) + 1 < (انتہا) ? read16le(((ln)+=2) - 2) : 0)
#تعریف_کرو	dwarf_read_4(ln,انتہا) \
	((ln) + 3 < (انتہا) ? read32le(((ln)+=4) - 4) : 0)
#تعریف_کرو	dwarf_read_8(ln,انتہا) \
	((ln) + 7 < (انتہا) ? read64le(((ln)+=8) - 8) : 0)
ساکن اندرونی uint64_t
dwarf_read_uleb128(غیرعلامتی حرف **ln, غیرعلامتی حرف *انتہا)
{
    غیرعلامتی حرف *cp = *ln;
    uint64_t retval = 0;
    صحیح i;
    برائے (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, انتہا);
        retval |= (byte & 0x7f) << (i * 7);
	اگر ((byte & 0x80) == 0)
	    توڑو;
    }
    *ln = cp;
    واپس retval;
}
ساکن اندرونی int64_t
dwarf_read_sleb128(غیرعلامتی حرف **ln, غیرعلامتی حرف *انتہا)
{
    غیرعلامتی حرف *cp = *ln;
    int64_t retval = 0;
    صحیح i;
    برائے (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, انتہا);
        retval |= (byte & 0x7f) << (i * 7);
	اگر ((byte & 0x80) == 0) {
	    اگر ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    توڑو;
	}
    }
    *ln = cp;
    واپس retval;
}

/* default dwarf version for "-gdwarf" */
#اگر_تعریف_شدہ TCC_ہدف_MACHO
# define DEFAULT_DWARF_نسخہ 2
#ورنہ
# define DEFAULT_DWARF_نسخہ 5
#اگر_ختم

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#اگر_غیر_تعریف_شدہ CONFIG_DWARF_نسخہ
# define CONFIG_DWARF_نسخہ 0
#اگر_ختم

#اگر defined TCC_ہدف_X86_64
# define R_ڈیٹا_32_DW R_X86_64_32
#ورنہ
# define R_ڈیٹا_32_DW R_ڈیٹا_32
#اگر_ختم

/********************************************************/
#اگر CONFIG_TCC_SEMLOCK
#اگر defined _WIN32
قسمتعریف ساخت { متلون LONG init; CRITICAL_SECTION cs; } TCCSem;
ساکن اندرونی خالی wait_sem(TCCSem *p) {
    اگر (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } ورنہ {
        جب (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ساکن اندرونی خالی post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#وگرنہ_اگر defined __APPLE__
#شامل <dispatch/dispatch.h>
قسمتعریف ساخت { صحیح init; dispatch_semaphore_t sem; } TCCSem;
ساکن اندرونی خالی wait_sem(TCCSem *p) {
    اگر (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_وقت_FOREVER);
}
ساکن اندرونی خالی post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#ورنہ
#شامل <semaphore.h>
قسمتعریف ساخت { صحیح init; sem_t sem; } TCCSem;
ساکن اندرونی خالی wait_sem(TCCSem *p) {
    اگر (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    جب (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ساکن اندرونی خالی post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#اگر_ختم
#تعریف_کرو TCC_SEM(s) TCCSem s
#تعریف_کرو WAIT_SEM wait_sem
#تعریف_کرو POST_SEM post_sem
#ورنہ
#تعریف_کرو TCC_SEM(s)
#تعریف_کرو WAIT_SEM(p)
#تعریف_کرو POST_SEM(p)
#اگر_ختم

/********************************************************/
#تعریف_منسوخ ST_ڈیٹا
#اگر ONE_ماخذ
#تعریف_کرو ST_ڈیٹا ساکن
#ورنہ
#تعریف_کرو ST_ڈیٹا
#اگر_ختم
/********************************************************/

#تعریف_کرو متن_section        TCC_STATE_VAR(متن_section)
#تعریف_کرو ڈیٹا_section        TCC_STATE_VAR(ڈیٹا_section)
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
#تعریف_کرو کل_بائٹیں         TCC_STATE_VAR(کل_بائٹیں)

PUB_FUNC خالی tcc_enter_state(TCCState *s1);
PUB_FUNC خالی tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#تعریف_کرو tcc_warning_c(sw) TCC_سیٹ_STATE((\
    tcc_state->warn_عدد = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#اگر_ختم /* _TCC_H */

#تعریف_منسوخ TCC_STATE_VAR
#تعریف_منسوخ TCC_سیٹ_STATE

#اگر_تعریف_شدہ USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_سیٹ_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#ورنہ
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_سیٹ_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#اگر_ختم
