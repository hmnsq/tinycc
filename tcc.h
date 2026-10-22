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

#अगर_अघोषित _TCC_H
#घोषणा _TCC_H

#घोषणा _GNU_SOURCE
#घोषणा _DARWIN_C_SOURCE
#समावेश "config.h"

#समावेश <stdarg.h>
#समावेश <stdlib.h>
#समावेश <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#अगर_घोषित __TINYC__
# undef __attribute__
#पूर्ण_अगर
#समावेश <string.h>
#समावेश <errno.h>
#समावेश <math.h>
#समावेश <fcntl.h>
#समावेश <setjmp.h>
#समावेश <time.h>

#अगर_अघोषित _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
बाह्य भग्न strtof (स्थिर अक्षर *__nptr, अक्षर **__endptr);
बाह्य दीर्घ द्विगुन strtold (स्थिर अक्षर *__nptr, अक्षर **__endptr);
#पूर्ण_अगर

#अगर_घोषित _WIN32
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
# define अंतरभूत __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (दीर्घ द्विगुन)म_से_भग्न
#  define strtof (भग्न)म_से_भग्न
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
# अगर defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#पूर्ण_अगर

#अगर_अघोषित O_द्विआधारी_2
# define O_द्विआधारी_2 0
#पूर्ण_अगर

#अगर_अघोषित दुरत्व
#अगर_घोषित __clang__ // clang -fsanitize compains about: NULL+value
#घोषणा दुरत्व(type, field) __builtin_offsetof(type, field)
#अन्यथा
#घोषणा दुरत्व(type, field) ((माप_प्रकार) &((type *)0)->field)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित countof
#घोषणा countof(tab) (माप(tab) / माप((tab)[0]))
#पूर्ण_अगर

#अगर_घोषित _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#अन्यथा
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (म_लिखो, (x), (y))))
#पूर्ण_अगर

#अगर_घोषित _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#अन्यथा
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP म_भेद
# define PATHSEP ":"
#पूर्ण_अगर

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
#अगर !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# अगर defined __x86_64__
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
# अन्यथा
#  define TCC_TARGET_I386
# endif
# ifdef _WIN32
#  define TCC_TARGET_PE 1
# endif
# ifdef __APPLE__
#  define TCC_TARGET_MACHO 1
# endif
#पूर्ण_अगर

/* only native compiler supports -run */
#अगर defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# अगर defined __i386__ && defined TCC_TARGET_I386
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
#पूर्ण_अगर

#अगर defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#अन्यथा
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#पूर्ण_अगर

#अगर defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#अन्यथा
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#पूर्ण_अगर

#अगर defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#अन्यथा
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#पूर्ण_अगर

#अगर defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#या_अगर !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#पूर्ण_अगर

#अगर defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#अन्यथा
# define TCC_TARGET_UNIX 1
#पूर्ण_अगर

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#अगर defined TCC_TARGET_PE \
    || (defined TCC_TARGET_MACHO && defined TCC_TARGET_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#पूर्ण_अगर

#अगर_घोषित CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#पूर्ण_अगर

/* support using libtcc from threads */
#अगर_अघोषित CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#पूर्ण_अगर

/* ------------ path configuration ------------ */

#अगर_अघोषित CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#पूर्ण_अगर

#अगर !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#पूर्ण_अगर

#अगर_घोषित CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#अन्यथा
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#पूर्ण_अगर

/* path to find crt1.o, crti.o and crtn.o */
#अगर_अघोषित CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#पूर्ण_अगर

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#अगर_अघोषित CONFIG_TCC_SYSINCLUDEPATHS
# अगर defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# अन्यथा
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#पूर्ण_अगर

/* library search paths */
#अगर_अघोषित CONFIG_TCC_LIBPATHS
# अगर defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# अन्यथा
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#पूर्ण_अगर

/* name of ELF interpreter */
#अगर_अघोषित CONFIG_TCC_ELFINTERP
# अगर defined __GNU__
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
# अन्यथा
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#पूर्ण_अगर

/* (target specific) libtcc1.a */
#अगर_अघोषित TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#पूर्ण_अगर

/* <cross-prefix-to->libtcc1.a */
#अगर_अघोषित CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#पूर्ण_अगर

/* -------------------------------------------- */

#समावेश "libtcc.h"
#समावेश "elf.h"
#समावेश "stab.h"
#समावेश "dwarf.h"

/* -------------------------------------------- */

#अगर_अघोषित PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#पूर्ण_अगर

#अगर_अघोषित ONE_SOURCE
# define ONE_SOURCE 0
#पूर्ण_अगर

#अगर ONE_SOURCE
#घोषणा ST_INLN अटल अंतरभूत
#घोषणा ST_FUNC अटल
#घोषणा ST_तथ्य अटल
#अन्यथा
#घोषणा ST_INLN
#घोषणा ST_FUNC
#घोषणा ST_तथ्य बाह्य
#पूर्ण_अगर

#अगर_घोषित TCC_PROFILE /* profile all functions */
# define अटल
# define अंतरभूत
#पूर्ण_अगर

/* -------------------------------------------- */
/* include the target specific definitions */

#घोषणा TARGET_DEFS_ONLY
#अगर_घोषित TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#या_अगर defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#या_अगर defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#या_अगर defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#या_अगर defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#या_अगर defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#अन्यथा
#त्रुटि unknown target
#पूर्ण_अगर
#अघोषित TARGET_DEFS_ONLY

/* -------------------------------------------- */

#अगर PTR_आकार == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#अन्यथा
# define ELFCLASSW ELFCLASS32
# define ElfW(type) Elf##32##_##type
# define ELFW(type) ELF##32##_##type
# define ElfW_Rel ElfW(Rel)
# define SHT_RELX SHT_REL
# define REL_SECTION_FMT ".rel%s"
#पूर्ण_अगर
/* target address type */
#घोषणा addr_t ElfW(Addr)
#घोषणा ElfSym ElfW(Sym)

#अगर PTR_आकार == 8 && !defined TCC_TARGET_PE
# define LONG_आकार 8
#अन्यथा
# define LONG_आकार 4
#पूर्ण_अगर

/* -------------------------------------------- */

#घोषणा INCLUDE_ढेर_आकार  32
#घोषणा IFDEF_ढेर_आकार    64
#घोषणा VSTACK_आकार         512
#घोषणा STRING_MAX_आकार     1024
#घोषणा TOKSTR_MAX_आकार     256
#घोषणा PACK_ढेर_आकार     8

#घोषणा TOK_HASH_आकार       16384 /* must be a power of two */
#घोषणा TOK_ALLOC_INCR      512  /* must be a power of two */
#घोषणा TOK_MAX_आकार        4 /* token max size in int unit when stored in string */

/* token symbol management */
प्रकार काष्ठा TokenSym {
    काष्ठा TokenSym *hash_अग्र;
    काष्ठा Sym *sym_define; /* direct pointer to define */
    काष्ठा Sym *sym_label; /* direct pointer to label */
    काष्ठा Sym *sym_struct; /* direct pointer to structure */
    काष्ठा Sym *sym_identifier; /* direct pointer to identifier */
    पूर्णांक tok; /* token number */
    पूर्णांक len;
    अक्षर str[1];
} TokenSym;

#अगर_घोषित TCC_TARGET_PE
प्रकार अचिन्हित लघु nwchar_t;
#अन्यथा
प्रकार पूर्णांक nwchar_t;
#पूर्ण_अगर

प्रकार काष्ठा CString {
    पूर्णांक आकार; /* size in bytes */
    पूर्णांक आकार_allocated;
    अक्षर *तथ्य; /* nwchar_t* in cases */
} CString;

/* type definition */
प्रकार काष्ठा CType {
    पूर्णांक t;
    काष्ठा Sym *ref;
} CType;

/* long double words on host(!) platform */
#घोषणा LDOUBLE_शब्दगण ((माप(दीर्घ द्विगुन)+3)/4)

/* constant value */
प्रकार जोड़ CValue {
    दीर्घ द्विगुन ld;
    द्विगुन d;
    भग्न f;
    uint64_t i;
    काष्ठा {
        अक्षर *तथ्य;
        पूर्णांक आकार;
    } str;
    पूर्णांक tab[LDOUBLE_शब्दगण];
} CValue;

/* value on stack */
प्रकार काष्ठा SValue {
    CType type;      /* type */
    अचिन्हित लघु r;      /* register + flags */
    अचिन्हित लघु r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    जोड़ {
      काष्ठा { पूर्णांक jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    जोड़ {
      काष्ठा { अचिन्हित लघु cmp_op, cmp_r; }; /* VT_CMP operation */
      काष्ठा Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
काष्ठा SymAttr {
    अचिन्हित लघु
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
काष्ठा FuncAttr {
    अचिन्हित
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
प्रकार काष्ठा Sym {
    पूर्णांक v; /* symbol token */
    अचिन्हित लघु r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    काष्ठा SymAttr a; /* symbol attributes */
    जोड़ {
        काष्ठा {
            पूर्णांक c; /* associated number or Elf symbol index */
            जोड़ {
                पूर्णांक sym_scope; /* scope level for locals */
                पूर्णांक jnext; /* next jump label */
                पूर्णांक jind; /* label position */
                काष्ठा FuncAttr f; /* function attributes */
                पूर्णांक auxtype; /* bitfield access type */
            };
        };
        दीर्घ दीर्घ enum_val; /* enum constant if IS_ENUM_VAL */
        पूर्णांक *d; /* define token stream */
        काष्ठा Sym *cleanup_func;
    };

    CType type; /* associated type */
    जोड़ {
        काष्ठा Sym *अग्र; /* next related symbol (for fields and anoms) */
        पूर्णांक *e; /* expanded token stream with preprocessor macros */
        पूर्णांक asm_label; /* associated asm label */
        काष्ठा Sym *cleanupstate; /* in defined labels */
        पूर्णांक *vla_array_str; /* vla array code */
    };
    काष्ठा Sym *पूर्व; /* prev symbol in stack */
    जोड़ {
        काष्ठा Sym *पूर्व_tok; /* previous symbol for this token */
        काष्ठा Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        काष्ठा Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
प्रकार काष्ठा Section {
    अचिन्हित दीर्घ तथ्य_offset; /* current data offset */
    अचिन्हित अक्षर *तथ्य;       /* section data */
    अचिन्हित दीर्घ तथ्य_allocated; /* used for realloc() handling */
    TCCState *s1;
    पूर्णांक sh_name;             /* elf section name (only used during output) */
    पूर्णांक sh_अंक;              /* elf section number */
    पूर्णांक sh_type;             /* elf section type */
    पूर्णांक sh_flags;            /* elf section flags */
    पूर्णांक sh_info;             /* elf section info */
    पूर्णांक sh_addralign;        /* elf section alignment */
    पूर्णांक sh_entsize;          /* elf entry size */
    अचिन्हित दीर्घ sh_आकार;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    अचिन्हित दीर्घ sh_offset; /* file offset */
    पूर्णांक nb_hashed_syms;      /* used to resize the hash table */
    काष्ठा Section *link;    /* link to another section */
    काष्ठा Section *reloc;   /* corresponding section for relocation, if any */
    काष्ठा Section *hash;    /* hash table for symbols */
    काष्ठा Section *पूर्व;    /* previous section on section stack */
    अक्षर name[1];           /* section name */
} Section;

प्रकार काष्ठा DLLReference {
    पूर्णांक level;
    व्योम *handle;
    अचिन्हित अक्षर found, सूचकांक;
    अक्षर name[1];
} DLLReference;

/* -------------------------------------------------- */

#घोषणा SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#घोषणा SYM_FIELD      0x20000000 /* struct/union field symbol space */
#घोषणा SYM_FIRST_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#घोषणा FUNC_NEW       1 /* ansi function prototype */
#घोषणा FUNC_OLD       2 /* old function prototype */
#घोषणा FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#घोषणा FUNC_CDECL     0 /* standard c call */
#घोषणा FUNC_STDCALL   1 /* pascal c call */
#घोषणा FUNC_FASTCALL1 2 /* first param in %eax */
#घोषणा FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#घोषणा FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#घोषणा FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#घोषणा FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#घोषणा MACRO_OBJ      0 /* object like macro */
#घोषणा MACRO_FUNC     1 /* function like macro */
#घोषणा MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#घोषणा LABEL_DEFINED  0 /* label is defined */
#घोषणा LABEL_FORWARD  1 /* label is forward defined */
#घोषणा LABEL_DECLARED 2 /* label is declared but never used */
#घोषणा LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#घोषणा TYPE_ABSTRACT  1 /* type without variable */
#घोषणा TYPE_DIRECT    2 /* type with variable */
#घोषणा TYPE_PARAM     4 /* type declares function parameter */
#घोषणा TYPE_NEST      8 /* nested call to post_type */

#घोषणा IO_BUF_आकार 8192

प्रकार काष्ठा BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    पूर्णांक fd;
    काष्ठा BufferedFile *पूर्व;
    पूर्णांक पंक्ति_अंक;    /* current line number - here to simplify code */
    पूर्णांक पंक्ति_ref;    /* tcc -E: last printed line */
    पूर्णांक ifndef_macro;  /* #ifndef macro / #endif search */
    पूर्णांक ifndef_macro_saved; /* saved ifndef_macro */
    पूर्णांक *ifdef_ढेर_ptr; /* ifdef_stack value at the start of the file */
    पूर्णांक include_अग्र_सूचकांक; /* next search path */
    पूर्णांक पूर्व_tok_flags; /* saved tok_flags */
    अक्षर filename[1024];    /* filename */
    अक्षर *true_filename; /* filename not modified by # line directive */
    अचिन्हित अक्षर unget[4];
    अचिन्हित अक्षर बफर[1]; /* extra size for CH_EOB char */
} BufferedFile;

#घोषणा CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#घोषणा CH_EOF   (-1)   /* end of file */

/* used to record tokens */
प्रकार काष्ठा TokenString {
    पूर्णांक *str;
    पूर्णांक len;
    पूर्णांक need_spc;
    पूर्णांक allocated_len;
    पूर्णांक last_पंक्ति_अंक;
    पूर्णांक save_पंक्ति_अंक;
    /* used to chain token-strings with begin/end_macro() */
    काष्ठा TokenString *पूर्व;
    स्थिर पूर्णांक *पूर्व_ptr;
    अक्षर alloc;
} TokenString;

/* GNUC attribute definition */
प्रकार काष्ठा AttributeDef {
    काष्ठा SymAttr a;
    काष्ठा FuncAttr f;
    काष्ठा Section *section;
    Sym *cleanup_func;
    पूर्णांक alias_target; /* token */
    पूर्णांक asm_label; /* associated asm label */
    अक्षर attr_mode; /* __attribute__((__mode__(...))) */
    अक्षर new_section; /* section is new */
} AttributeDef;

/* inline functions */
प्रकार काष्ठा InlineFunc {
    TokenString *func_str;
    Sym *sym;
    अक्षर filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
प्रकार काष्ठा CachedInclude {
    पूर्णांक ifndef_macro;
    पूर्णांक once;
    पूर्णांक hash_अग्र; /* -1 if none */
    अक्षर filename[1]; /* path specified in #include */
} CachedInclude;

#घोषणा CACHED_INCLUDES_HASH_आकार 32

#अगर_घोषित CONFIG_TCC_ASM
प्रकार काष्ठा व्यंजक_मूल्य {
    uint64_t v;
    Sym *sym;
    पूर्णांक pcrel;
} व्यंजक_मूल्य;

#घोषणा MAX_ASM_OPERANDS 30
प्रकार काष्ठा ASMOperand {
    पूर्णांक id; /* GCC 3 optional identifier (0 if number only supported) */
    अक्षर constraint[16];
    अक्षर asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    पूर्णांक ref_सूचकांक; /* if >= 0, gives reference to a output constraint */
    पूर्णांक निवेश_सूचकांक; /* if >= 0, gives reference to an input constraint */
    पूर्णांक priority; /* priority, used to assign registers */
    पूर्णांक reg; /* if >= 0, register number used for this operand */
    पूर्णांक is_llong; /* true if double register value */
    पूर्णांक is_memory; /* true if memory operand */
    पूर्णांक is_rw;     /* for '+' modifier */
    पूर्णांक is_label;  /* for asm goto */
} ASMOperand;
#पूर्ण_अगर

/* extra symbol attributes (not in symbol table) */
काष्ठा sym_attr {
    अचिन्हित got_offset;
    अचिन्हित plt_offset;
    पूर्णांक plt_sym;
    पूर्णांक dyn_सूचकांक;
    अचिन्हित अक्षर linker_sym:1;
#अगर_घोषित TCC_TARGET_ARM
    अचिन्हित अक्षर plt_thumb_stub:1;
#पूर्ण_अगर
};

काष्ठा TCCState {
    अचिन्हित अक्षर verbose; /* if true, display some information during compilation */
    अचिन्हित अक्षर nostdinc; /* if true, no standard headers are added */
    अचिन्हित अक्षर nostdlib; /* if true, no standard libraries are added */
    अचिन्हित अक्षर nostdlib_paths; /* if true, the default paths are not searched for libraries */
    अचिन्हित अक्षर nocommon; /* if true, do not use common symbols for .bss data */
    अचिन्हित अक्षर static_link; /* if true, static linking is performed */
    अचिन्हित अक्षर rdynamic; /* if true, all symbols are exported */
    अचिन्हित अक्षर symbolic; /* if true, resolve symbols in the current module first */
    अचिन्हित अक्षर znodelete; /* Set DF_1_NODELETE in dynamic section */
    अचिन्हित अक्षर filetype; /* file type for compilation (NONE,C,ASM) */
    अचिन्हित अक्षर optimize; /* only to #define __OPTIMIZE__ */
    अचिन्हित अक्षर option_pthread; /* -pthread option */
    अचिन्हित अक्षर enable_new_dtags; /* -Wl,--enable-new-dtags */
    अचिन्हित पूर्णांक  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    अचिन्हित अक्षर char_is_unsigned;
    अचिन्हित अक्षर leading_underscore;
    अचिन्हित अक्षर ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    अचिन्हित अक्षर dollars_in_identifiers;  /* allows '$' char in identifiers */
    अचिन्हित अक्षर ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    अचिन्हित अक्षर reverse_funcargs; /* if true, evaluate last function arg first */
    अचिन्हित अक्षर gnu89_inline; /* treat 'extern inline' like 'static inline' */
    अचिन्हित अक्षर unwind_tables; /* create eh_frame section */

    /* warning switches */
    अचिन्हित अक्षर warn_none;
    अचिन्हित अक्षर warn_all;
    अचिन्हित अक्षर warn_error;
    अचिन्हित अक्षर warn_write_strings;
    अचिन्हित अक्षर warn_unsupported;
    अचिन्हित अक्षर warn_implicit_function_declaration;
    अचिन्हित अक्षर warn_discarded_qualifiers;
    #घोषणा WARN_ON  1 /* warning is on (-Woption) */
    अचिन्हित अक्षर warn_अंक; /* temp var for tcc_warning_c() */

    अचिन्हित अक्षर option_r; /* option -r */
    अचिन्हित अक्षर do_bench; /* option -bench */
    अचिन्हित अक्षर just_deps; /* option -M  */
    अचिन्हित अक्षर gen_deps; /* option -MD  */
    अचिन्हित अक्षर include_sys_deps; /* option -MD  */
    अचिन्हित अक्षर gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    अचिन्हित अक्षर do_debug;
    अचिन्हित अक्षर dwarf;
    अचिन्हित अक्षर do_backtrace;
#अगर_घोषित CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    अचिन्हित अक्षर do_bounds_check;
#पूर्ण_अगर
    अचिन्हित अक्षर test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    अचिन्हित अक्षर gnu_ext;
    /* use TinyCC extensions */
    अचिन्हित अक्षर tcc_ext;

    अचिन्हित अक्षर dflag; /* -dX value */
    अचिन्हित अक्षर Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#अगर_घोषित TCC_TARGET_X86_64
    अचिन्हित अक्षर nosse; /* For -mno-sse support. */
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_ARM
    अचिन्हित अक्षर float_abi; /* float ABI of the generated code*/
#पूर्ण_अगर

    अचिन्हित अक्षर has_text_addr;
    addr_t text_addr; /* address of text section */
    अचिन्हित section_align; /* section alignment */
#अगर_घोषित TCC_TARGET_I386
    पूर्णांक seg_आकार; /* 32. Can be 16 with i386 assembler (.code16) */
#पूर्ण_अगर

    अक्षर *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    अक्षर *soname; /* as specified on the command line (-soname) */
    अक्षर *rpath; /* as specified on the command line (-Wl,-rpath=) */
    अक्षर *elfint; /* -Wl,-I... on command line */
    अक्षर *elf_entryname; /* "_start" unless set */
    अक्षर *init_प्रतीक; /* symbols to call at load-time (not used currently) */
    अक्षर *fini_प्रतीक; /* symbols to call at unload-time (not used currently) */
    अक्षर *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    पूर्णांक output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    पूर्णांक output_format;
    /* nth test to run with -dt -run */
    पूर्णांक run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    पूर्णांक nb_loaded_dlls;

    /* include paths */
    अक्षर **include_paths;
    पूर्णांक nb_include_paths;

    अक्षर **sysinclude_paths;
    पूर्णांक nb_sysinclude_paths;

    /* library paths */
    अक्षर **library_paths;
    पूर्णांक nb_library_paths;

    /* crt?.o object path */
    अक्षर **crt_paths;
    पूर्णांक nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    व्योम *error_opaque;
    व्योम (*error_func)(व्योम *opaque, स्थिर अक्षर *संदेश);
    पूर्णांक error_set_jmp_enabled;
    लाँघ_बफ error_jmp_buf;
    पूर्णांक nb_errors;

    /* output file for preprocessing (-E) */
    खाता *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    अक्षर **target_deps;
    पूर्णांक nb_target_deps;

    /* compilation */
    BufferedFile *include_ढेर[INCLUDE_ढेर_आकार];
    BufferedFile **include_ढेर_ptr;

    पूर्णांक ifdef_ढेर[IFDEF_ढेर_आकार];
    पूर्णांक *ifdef_ढेर_ptr;

    /* included files enclosed with #ifndef MACRO */
    पूर्णांक cached_includes_hash[CACHED_INCLUDES_HASH_आकार];
    CachedInclude **cached_includes;
    पूर्णांक nb_cached_includes;

    /* #pragma pack stack */
    पूर्णांक pack_ढेर[PACK_ढेर_आकार];
    पूर्णांक *pack_ढेर_ptr;
    अक्षर **pragma_libs;
    पूर्णांक nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    काष्ठा InlineFunc **inline_fns;
    पूर्णांक nb_inline_fns;

    /* sections */
    Section **sections;
    पूर्णांक nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    पूर्णांक nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *text_section, *तथ्य_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_text_section; /* current section where function code is generated */
#अगर_घोषित CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#पूर्ण_अगर
    /* symbol section */
    जोड़ { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_frame_section;
    Section *eh_frame_hdr_section;
    अचिन्हित दीर्घ eh_start;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_पंक्ति_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_पंक्ति_str_section;
    पूर्णांक dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    काष्ठा _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    काष्ठा sym_attr *sym_attrs;
    पूर्णांक nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #घोषणा qrel s1->qrel

    addr_t tls_start, tls_end;

#अगर_घोषित TCC_TARGET_RISCV64
    काष्ठा pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    पूर्णांक nb_pcrel_hi_entries;
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_PE
    /* PE info */
    पूर्णांक pe_subsystem;
    अचिन्हित pe_characteristics;
    अचिन्हित pe_dll_characteristics;
    अचिन्हित pe_file_align;
    अचिन्हित pe_ढेर_आकार;
    addr_t pe_imagebase;
# अगर defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    पूर्णांक uw_sym;
    पूर्णांक uw_xsym;
    अचिन्हित uw_offs;
# endif
#पूर्ण_अगर

#अगर defined TCC_TARGET_MACHO
    अक्षर *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#पूर्ण_अगर

#अगर_अघोषित ELF_OBJ_ONLY
    पूर्णांक nb_sym_versions;
    काष्ठा sym_version *sym_versions;
    पूर्णांक nb_sym_to_version;
    पूर्णांक *sym_to_version;
    पूर्णांक dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#पूर्ण_अगर

#अगर_घोषित TCC_IS_NATIVE
    स्थिर अक्षर *run_main; /* entry for tcc_run() */
    व्योम *run_ptr; /* runtime_memory */
    अचिन्हित run_आकार; /* size of runtime_memory  */
    स्थिर अक्षर *run_stdin; /* custom stdin file for run_main */
#अगर_घोषित _WIN64
    व्योम *run_function_table; /* unwind data */
#पूर्ण_अगर
    काष्ठा TCCState *अग्र;
    काष्ठा rt_context *rc; /* pointer to backtrace info block */
    व्योम *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    व्योम *bt_तथ्य;
#पूर्ण_अगर

#अगर_घोषित CONFIG_TCC_BACKTRACE
    पूर्णांक rt_अंक_callers;
#पूर्ण_अगर

    /* benchmark info */
    पूर्णांक योग_idents;
    पूर्णांक योग_पंक्तियाँ;
    अचिन्हित पूर्णांक योग_bytes;
    अचिन्हित पूर्णांक योग_output[4];

    /* used by tcc_load_ldscript */
    अचिन्हित अक्षर *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    स्थिर अक्षर *current_filename;

    /* used by main and tcc_parse_args only */
    काष्ठा filespec **files; /* files seen on command line */
    पूर्णांक nb_files; /* number thereof */
    पूर्णांक nb_libraries; /* number of libs thereof */
    अक्षर *outfile; /* output filename */
    अक्षर *deps_outfile; /* option -MF */
    पूर्णांक argc;
    अक्षर **argv;
    /* -Wl options */
    अक्षर **link_argv;
    पूर्णांक link_argc, link_optind;
};

काष्ठा filespec {
    अक्षर type;
    अक्षर name[1];
};

/* The current value can be: */
#घोषणा VT_VALMASK   0x003f  /* mask for value location, register or: */
#घोषणा VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#घोषणा VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#घोषणा VT_LOCAL     0x0032  /* offset on stack */
#घोषणा VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#घोषणा VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#घोषणा VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#घोषणा VT_LVAL      0x0100  /* var is an lvalue */
#घोषणा VT_SYM       0x0200  /* a symbol value is added */
#घोषणा VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#घोषणा VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#घोषणा VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#घोषणा VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#घोषणा VT_BTYPE       0x000f  /* mask for basic type */
#घोषणा VT_VOID             0  /* void type */
#घोषणा VT_BYTE             1  /* signed byte type */
#घोषणा VT_SHORT            2  /* short type */
#घोषणा VT_INT              3  /* integer type */
#घोषणा VT_LLONG            4  /* 64 bit integer */
#घोषणा VT_PTR              5  /* pointer */
#घोषणा VT_FUNC             6  /* function type */
#घोषणा VT_STRUCT           7  /* struct/union definition */
#घोषणा VT_FLOAT            8  /* IEEE float */
#घोषणा VT_DOUBLE           9  /* IEEE double */
#घोषणा VT_LDOUBLE         10  /* IEEE long double */
#घोषणा VT_BOOL            11  /* ISOC99 boolean type */
#घोषणा VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#घोषणा VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#घोषणा VT_UNSIGNED    0x0010  /* unsigned type */
#घोषणा VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#घोषणा VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#घोषणा VT_BITFIELD    0x0080  /* bitfield modifier */
#घोषणा VT_CONSTANT    0x0100  /* const modifier */
#घोषणा VT_VOLATILE    0x0200  /* volatile modifier */
#घोषणा VT_RESTRICT    0x0400  /* restrict modifier */
#घोषणा VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#घोषणा VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#घोषणा VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#घोषणा VT_EXTERN  0x00002000  /* extern definition */
#घोषणा VT_STATIC  0x00004000  /* static variable */
#घोषणा VT_TYPEDEF 0x00008000  /* typedef definition */
#घोषणा VT_INLINE  0x00010000  /* inline definition */
#घोषणा VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#घोषणा VT_STRUCT_SHIFT 20     /* shift for bitfield shift values (32 - 2*6) */
#घोषणा VT_STRUCT_MASK (((1U << (6+6)) - 1) << VT_STRUCT_SHIFT | VT_BITFIELD)
#घोषणा BIT_POS(t) (((t) >> VT_STRUCT_SHIFT) & 0x3f)
#घोषणा BIT_आकार(t) (((t) >> (VT_STRUCT_SHIFT + 6)) & 0x3f)

#घोषणा VT_UNION    (1 << VT_STRUCT_SHIFT | VT_STRUCT)
#घोषणा VT_ENUM     (2 << VT_STRUCT_SHIFT) /* integral type is an enum really */
#घोषणा VT_ENUM_VAL (3 << VT_STRUCT_SHIFT) /* integral type is an enum constant really */

#घोषणा IS_ENUM(t) ((t & VT_STRUCT_MASK) == VT_ENUM)
#घोषणा IS_ENUM_VAL(t) ((t & VT_STRUCT_MASK) == VT_ENUM_VAL)
#घोषणा IS_UNION(t) ((t & (VT_STRUCT_MASK|VT_BTYPE)) == VT_UNION)

#घोषणा VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#घोषणा VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#घोषणा VT_TYPE (~(VT_STORAGE|VT_STRUCT_MASK))

/* symbol was created by tccasm.c first */
#घोषणा VT_ASM (VT_VOID | 4 << VT_STRUCT_SHIFT)
#घोषणा VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_SHIFT)
#घोषणा IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_MASK) & ~(1<<VT_STRUCT_SHIFT))) == VT_ASM)
#घोषणा IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_MASK)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#घोषणा VT_BT_ARRAY (6 << VT_STRUCT_SHIFT)
#घोषणा IS_BT_ARRAY(t) ((t & VT_STRUCT_MASK) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#घोषणा BFVAL(M,N) ((अचिन्हित)((M) & ~((M) << 1)) * (N))
#घोषणा BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#घोषणा BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#घोषणा TOK_LAND  0x90
#घोषणा TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#घोषणा TOK_ULT 0x92
#घोषणा TOK_UGE 0x93
#घोषणा TOK_EQ  0x94
#घोषणा TOK_NE  0x95
#घोषणा TOK_ULE 0x96
#घोषणा TOK_UGT 0x97
#घोषणा TOK_Nset 0x98
#घोषणा TOK_Nclear 0x99
#घोषणा TOK_LT  0x9c
#घोषणा TOK_GE  0x9d
#घोषणा TOK_LE  0x9e
#घोषणा TOK_GT  0x9f

#घोषणा TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#घोषणा TOK_DEC     0x80 /* -- */
#घोषणा TOK_MID     0x81 /* inc/dec, to void constant */
#घोषणा TOK_INC     0x82 /* ++ */
#घोषणा TOK_UDIV    0x83 /* unsigned division */
#घोषणा TOK_UMOD    0x84 /* unsigned modulo */
#घोषणा TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#घोषणा TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#घोषणा TOK_ADDC1   0x87 /* add with carry generation */
#घोषणा TOK_ADDC2   0x88 /* add with carry use */
#घोषणा TOK_SUBC1   0x89 /* add with carry generation */
#घोषणा TOK_SUBC2   0x8a /* add with carry use */
#घोषणा TOK_SHL     '<' /* shift left */
#घोषणा TOK_SAR     '>' /* signed shift right */
#घोषणा TOK_SHR     0x8b /* unsigned shift right */
#घोषणा TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#घोषणा TOK_ARROW   0xa0 /* -> */
#घोषणा TOK_DOTS    0xa1 /* three dots */
#घोषणा TOK_TWODOTS 0xa2 /* C++ token ? */
#घोषणा TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#घोषणा TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#घोषणा TOK_PPJOIN  (TOK_TWOSHARPS | SYM_FIELD) /* A '##' in a macro to mean pasting */
#घोषणा TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#घोषणा TOK_A_ADD   0xb0
#घोषणा TOK_A_SUB   0xb1
#घोषणा TOK_A_MUL   0xb2
#घोषणा TOK_A_DIV   0xb3
#घोषणा TOK_A_MOD   0xb4
#घोषणा TOK_A_AND   0xb5
#घोषणा TOK_A_OR    0xb6
#घोषणा TOK_A_XOR   0xb7
#घोषणा TOK_A_SHL   0xb8
#घोषणा TOK_A_SAR   0xb9

#घोषणा TOK_ASSIGN(t) (t >= TOK_A_ADD && t <= TOK_A_SAR)
#घोषणा TOK_ASSIGN_OP(t) ("+-*/%&|^<>"[t - TOK_A_ADD])

/* tokens that carry values (in additional token string space / tokc) --> */
#घोषणा TOK_CCHAR   0xc0 /* char constant in tokc */
#घोषणा TOK_LCHAR   0xc1
#घोषणा TOK_CINT    0xc2 /* number in tokc */
#घोषणा TOK_CUINT   0xc3 /* unsigned int constant */
#घोषणा TOK_CLLONG  0xc4 /* long long constant */
#घोषणा TOK_CULLONG 0xc5 /* unsigned long long constant */
#घोषणा TOK_CLONG   0xc6 /* long constant */
#घोषणा TOK_CULONG  0xc7 /* unsigned long constant */
#घोषणा TOK_STR     0xc8 /* pointer to string in tokc */
#घोषणा TOK_LSTR    0xc9
#घोषणा TOK_CFLOAT  0xca /* float constant */
#घोषणा TOK_CDOUBLE 0xcb /* double constant */
#घोषणा TOK_CLDOUBLE 0xcc /* long double constant */
#घोषणा TOK_PPNUM   0xcd /* preprocessor number */
#घोषणा TOK_PPSTR   0xce /* preprocessor string */
#घोषणा TOK_LINENUM 0xcf /* line number info */

#घोषणा TOK_HAS_मूल्य(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#घोषणा TOK_EOF       (-1)  /* end of file */
#घोषणा TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#घोषणा TOK_IDENT 256

क्रमागत tcc_token {
    TOK_LAST = TOK_IDENT - 1
#घोषणा DEF(id, str) ,id
#समावेश "tcctok.h"
#अघोषित DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#घोषणा TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_तथ्य काष्ठा TCCState *tcc_state;
ST_तथ्य व्योम** stk_तथ्य;
ST_तथ्य पूर्णांक nb_stk_तथ्य;
ST_तथ्य पूर्णांक g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC अक्षर *pstrcpy(अक्षर *buf, माप_प्रकार buf_आकार, स्थिर अक्षर *s);
ST_FUNC अक्षर *pstrcat(अक्षर *buf, माप_प्रकार buf_आकार, स्थिर अक्षर *s);
ST_FUNC अक्षर *pstrncpy(अक्षर *out, माप_प्रकार buf_आकार, स्थिर अक्षर *s, माप_प्रकार अंक);
PUB_FUNC अक्षर *tcc_basename(स्थिर अक्षर *name);
PUB_FUNC अक्षर *tcc_fileextension (स्थिर अक्षर *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC व्योम tcc_free(व्योम *ptr);
PUB_FUNC व्योम *tcc_malloc(अचिन्हित दीर्घ आकार);
PUB_FUNC व्योम *tcc_mallocz(अचिन्हित दीर्घ आकार);
PUB_FUNC व्योम *tcc_realloc(व्योम *ptr, अचिन्हित दीर्घ आकार);
PUB_FUNC अक्षर *tcc_strdup(स्थिर अक्षर *str);

#अगर_घोषित MEM_DEBUG
#घोषणा tcc_free(ptr)           tcc_free_debug(ptr)
#घोषणा tcc_malloc(आकार)        tcc_malloc_debug(आकार, __खाता__, __LINE__)
#घोषणा tcc_mallocz(आकार)       tcc_mallocz_debug(आकार, __खाता__, __LINE__)
#घोषणा tcc_realloc(ptr,आकार)   tcc_realloc_debug(ptr, आकार, __खाता__, __LINE__)
#घोषणा tcc_strdup(str)         tcc_strdup_debug(str, __खाता__, __LINE__)
PUB_FUNC व्योम tcc_free_debug(व्योम *ptr);
PUB_FUNC व्योम *tcc_malloc_debug(अचिन्हित दीर्घ आकार, स्थिर अक्षर *file, पूर्णांक पंक्ति_2);
PUB_FUNC व्योम *tcc_mallocz_debug(अचिन्हित दीर्घ आकार, स्थिर अक्षर *file, पूर्णांक पंक्ति_2);
PUB_FUNC व्योम *tcc_realloc_debug(व्योम *ptr, अचिन्हित दीर्घ आकार, स्थिर अक्षर *file, पूर्णांक पंक्ति_2);
PUB_FUNC अक्षर *tcc_strdup_debug(स्थिर अक्षर *str, स्थिर अक्षर *file, पूर्णांक पंक्ति_2);
#पूर्ण_अगर

ST_FUNC व्योम libc_free(व्योम *ptr);
/* defined to be not used */
#घोषणा मुक्त(p) use_tcc_free(p)
#घोषणा दो_स्मृति(s) use_tcc_malloc(s)
#घोषणा पुनः_स्मृति(p, s) use_tcc_realloc(p, s)
#अघोषित strdup
#घोषणा strdup(s) use_tcc_strdup(s)
PUB_FUNC पूर्णांक _tcc_error_noabort(स्थिर अक्षर *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN व्योम _tcc_error(स्थिर अक्षर *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC व्योम _tcc_warning(स्थिर अक्षर *fmt, ...) PRINTF_LIKE(1,2);
#घोषणा tcc_internal_error(संदेश) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,संदेश)

/* other utilities */
ST_FUNC व्योम dynarray_add(व्योम *ptab, पूर्णांक *nb_ptr, व्योम *तथ्य);
ST_FUNC व्योम dynarray_reset(व्योम *pp, पूर्णांक *n);
ST_INLN व्योम cstr_ccat(CString *cstr, पूर्णांक ch);
ST_FUNC व्योम cstr_cat(CString *cstr, स्थिर अक्षर *str, पूर्णांक len);
ST_FUNC व्योम cstr_wccat(CString *cstr, पूर्णांक ch);
ST_FUNC व्योम cstr_new(CString *cstr);
ST_FUNC व्योम cstr_free(CString *cstr);
ST_FUNC पूर्णांक cstr_printf(CString *cs, स्थिर अक्षर *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC पूर्णांक cstr_vprintf(CString *cstr, स्थिर अक्षर *fmt, बहु_सूची ap);
ST_FUNC व्योम cstr_reset(CString *cstr);
ST_FUNC व्योम tcc_open_bf(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक initlen);
ST_FUNC पूर्णांक tcc_open(TCCState *s1, स्थिर अक्षर *filename);
ST_FUNC व्योम tcc_close(व्योम);

/* mark a memory pointer on stack for cleanup after errors */
#घोषणा stk_धकेलो(p) dynarray_add(&stk_तथ्य, &nb_stk_तथ्य, p)
#घोषणा stk_निकालो() (--nb_stk_तथ्य)
/* mark CString on stack for cleanup errors */
#घोषणा cstr_new_s(cstr) (cstr_new(cstr), stk_धकेलो(&(cstr)->तथ्य))
#घोषणा cstr_free_s(cstr) (cstr_free(cstr), stk_निकालो())

ST_FUNC पूर्णांक tcc_add_file_internal(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक flags);
/* flags: */
#घोषणा AFF_PRINT_ERROR     0x10 /* print error if file not found */
#घोषणा AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#घोषणा AFF_TYPE_BIN        0x40 /* file to add is binary */
#घोषणा AFF_WHOLE_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#घोषणा AFF_TYPE_NONE   0
#घोषणा AFF_TYPE_C      1
#घोषणा AFF_TYPE_ASM    2
#घोषणा AFF_TYPE_ASMPP  4
#घोषणा AFF_TYPE_LIB    8
#घोषणा AFF_TYPE_MASK   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#घोषणा AFF_BINTYPE_REL 1
#घोषणा AFF_BINTYPE_DYN 2
#घोषणा AFF_BINTYPE_AR  3
#घोषणा AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#घोषणा FILE_NOT_FOUND -2
#घोषणा FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#अगर_अघोषित ELF_OBJ_ONLY
ST_FUNC पूर्णांक tcc_add_crt(TCCState *s, स्थिर अक्षर *filename);
#पूर्ण_अगर
ST_FUNC पूर्णांक tcc_add_dll(TCCState *s, स्थिर अक्षर *filename, पूर्णांक flags);
ST_FUNC पूर्णांक tcc_add_support(TCCState *s1, स्थिर अक्षर *filename);
#अगर_घोषित CONFIG_TCC_BCHECK
ST_FUNC व्योम tcc_add_bcheck(TCCState *s1);
#पूर्ण_अगर
#अगर_घोषित CONFIG_TCC_BACKTRACE
ST_FUNC व्योम tcc_add_btstub(TCCState *s1);
#पूर्ण_अगर
ST_FUNC व्योम tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC पूर्णांक tcc_add_library_err(TCCState *s, स्थिर अक्षर *f);
PUB_FUNC व्योम tcc_print_stats(TCCState *s, अचिन्हित योग_time);
PUB_FUNC पूर्णांक tcc_parse_args(TCCState *s, पूर्णांक *argc, अक्षर ***argv);
#अगर_घोषित _WIN32
ST_FUNC अक्षर *normalize_slashes(अक्षर *path);
PUB_FUNC खाता *tcc_fopen(स्थिर अक्षर *f, स्थिर अक्षर *m);
PUB_FUNC पूर्णांक tcc_fclose(खाता *f);
#अन्यथा
# define tcc_fopen ख_खोलो
# define tcc_fclose ख_बंद
#पूर्ण_अगर
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, स्थिर अक्षर *dllname, पूर्णांक level);
ST_FUNC अक्षर *tcc_load_text(पूर्णांक fd);
/* for #pragma once */
ST_FUNC पूर्णांक normalized_PATHCMP(स्थिर अक्षर *f1, स्थिर अक्षर *f2);

/* tcc_parse_args return codes: */
#घोषणा OPT_HELP 1
#घोषणा OPT_HELP2 2
#घोषणा OPT_V 3
#घोषणा OPT_PRINT_DIRS 4
#घोषणा OPT_AR 5
#घोषणा OPT_IMPDEF 6
#घोषणा OPT_M32 32
#घोषणा OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_तथ्य काष्ठा BufferedFile *file;
ST_तथ्य पूर्णांक tok;
ST_तथ्य CValue tokc;
ST_तथ्य स्थिर पूर्णांक *macro_ptr;
ST_तथ्य पूर्णांक parse_flags;
ST_तथ्य पूर्णांक tok_flags;
ST_तथ्य CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_तथ्य पूर्णांक tok_ident;
ST_तथ्य TokenSym **table_ident;
ST_तथ्य पूर्णांक pp_व्यंजक;

#घोषणा TOK_FLAG_BOL   0x0001 /* beginning of line before */
#घोषणा TOK_FLAG_BOF   0x0002 /* beginning of file before */
#घोषणा TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#घोषणा PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#घोषणा PARSE_FLAG_TOK_अंक    0x0002 /* return numbers instead of TOK_PPNUM */
#घोषणा PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#घोषणा PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#घोषणा PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#घोषणा PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#घोषणा PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#घोषणा IS_SPC 1
#घोषणा IS_ID  2
#घोषणा IS_अंक 4

क्रमागत पंक्ति_macro_output_format {
    पंक्ति_MACRO_OUTPUT_FORMAT_GCC,
    पंक्ति_MACRO_OUTPUT_FORMAT_NONE,
    पंक्ति_MACRO_OUTPUT_FORMAT_STD,
    पंक्ति_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(स्थिर अक्षर *str, पूर्णांक len);
ST_FUNC पूर्णांक tok_alloc_const(स्थिर अक्षर *str);
ST_FUNC स्थिर अक्षर *get_tok_str(पूर्णांक v, CValue *cv);
ST_FUNC व्योम begin_macro(TokenString *str, पूर्णांक alloc);
ST_FUNC व्योम end_macro(व्योम);
ST_FUNC पूर्णांक set_idnum(पूर्णांक c, पूर्णांक val);
ST_INLN व्योम tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(व्योम);
ST_FUNC व्योम tok_str_free(TokenString *s);
ST_FUNC व्योम tok_str_free_str(पूर्णांक *str);
ST_FUNC व्योम tok_str_add(TokenString *s, पूर्णांक t);
ST_FUNC व्योम tok_str_add_tok(TokenString *s);
ST_INLN व्योम define_धकेलो(पूर्णांक v, पूर्णांक macro_type, पूर्णांक *str, Sym *first_arg);
ST_FUNC व्योम define_undef(Sym *s);
ST_INLN Sym *define_find(पूर्णांक v);
ST_FUNC व्योम free_defines(Sym *b);
ST_FUNC व्योम parse_define(व्योम);
ST_FUNC व्योम skip_to_eol(पूर्णांक warn);
ST_FUNC व्योम preprocess(पूर्णांक is_bof);
ST_FUNC व्योम अग्र(व्योम);
ST_INLN व्योम unget_tok(पूर्णांक last_tok);
ST_FUNC व्योम preprocess_start(TCCState *s1, पूर्णांक filetype);
ST_FUNC व्योम preprocess_end(TCCState *s1);
ST_FUNC व्योम tccpp_new(TCCState *s);
ST_FUNC व्योम tccpp_delete(TCCState *s);
ST_FUNC व्योम tccpp_putfile(स्थिर अक्षर *filename);
ST_FUNC पूर्णांक tcc_preprocess(TCCState *s1);
ST_FUNC व्योम skip(पूर्णांक c);
ST_FUNC NORETURN व्योम expect(स्थिर अक्षर *संदेश);
ST_FUNC व्योम pp_error(CString *cs);


/* space excluding newline */
अटल अंतरभूत पूर्णांक is_space(पूर्णांक ch) {
    वापस ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
अटल अंतरभूत पूर्णांक isid(पूर्णांक c) {
    वापस (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
अटल अंतरभूत पूर्णांक isnum(पूर्णांक c) {
    वापस c >= '0' && c <= '9';
}
अटल अंतरभूत पूर्णांक isoct(पूर्णांक c) {
    वापस c >= '0' && c <= '7';
}
अटल अंतरभूत पूर्णांक toup(पूर्णांक c) {
    वापस (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#घोषणा SYM_POOL_NB (8192 / माप(Sym))

ST_तथ्य Sym *global_ढेर;
ST_तथ्य Sym *local_ढेर;
ST_तथ्य Sym *local_label_ढेर;
ST_तथ्य Sym *global_label_ढेर;
ST_तथ्य Sym *define_ढेर;
ST_तथ्य CType int_type, func_old_type, char_pointer_type;
ST_तथ्य SValue *vtop;
ST_तथ्य पूर्णांक rsym, anon_sym, ind, loc;
ST_तथ्य अक्षर debug_modes;

ST_तथ्य पूर्णांक nocode_wanted; /* true if no code generation wanted for an expression */
ST_तथ्य पूर्णांक global_व्यंजक;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_तथ्य CType func_vt; /* current function return type (used by return instruction) */
ST_तथ्य पूर्णांक func_var; /* true if current function is variadic */
ST_तथ्य पूर्णांक func_vc; /* stack address for implicit struct return storage */
ST_तथ्य पूर्णांक func_ind; /* function start address */
ST_तथ्य स्थिर अक्षर *funcname;

ST_FUNC व्योम tccgen_init(TCCState *s1);
ST_FUNC पूर्णांक tccgen_compile(TCCState *s1);
ST_FUNC व्योम tccgen_finish(TCCState *s1);
ST_FUNC व्योम check_vstack(व्योम);

ST_INLN पूर्णांक is_float(पूर्णांक t);
ST_FUNC पूर्णांक ieee_finite(द्विगुन d);
ST_FUNC पूर्णांक exact_log2p1(पूर्णांक i);
ST_FUNC व्योम test_lvalue(व्योम);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC व्योम update_storage(Sym *sym);
ST_FUNC व्योम put_extern_sym2(Sym *sym, पूर्णांक sh_अंक, addr_t मूल्य, अचिन्हित दीर्घ आकार, पूर्णांक can_add_underscore);
ST_FUNC व्योम put_extern_sym(Sym *sym, Section *section, addr_t मूल्य, अचिन्हित दीर्घ आकार);
#अगर PTR_आकार == 4
ST_FUNC व्योम greloc(Section *s, Sym *sym, अचिन्हित दीर्घ offset, पूर्णांक type);
#पूर्ण_अगर
ST_FUNC व्योम greloca(Section *s, Sym *sym, अचिन्हित दीर्घ offset, पूर्णांक type, addr_t addend);

ST_INLN व्योम sym_free(Sym *sym);
ST_FUNC Sym *sym_धकेलो(पूर्णांक v, CType *type, पूर्णांक r, पूर्णांक c);
ST_FUNC व्योम sym_निकालो(Sym **ptop, Sym *b, पूर्णांक keep);
ST_FUNC Sym *sym_push2(Sym **ps, पूर्णांक v, पूर्णांक t, पूर्णांक c);
ST_FUNC Sym *sym_find2(Sym *s, पूर्णांक v);
ST_INLN Sym *sym_find(पूर्णांक v);
ST_FUNC Sym *label_find(पूर्णांक v);
ST_FUNC Sym *label_धकेलो(Sym **ptop, पूर्णांक v, पूर्णांक flags);
ST_FUNC व्योम label_निकालो(Sym **ptop, Sym *slast, पूर्णांक keep);
ST_INLN Sym *struct_find(पूर्णांक v);

ST_FUNC Sym *global_identifier_धकेलो(पूर्णांक v, पूर्णांक t, पूर्णांक c);
ST_FUNC Sym *external_global_sym(पूर्णांक v, CType *type);
ST_FUNC Sym *external_helper_sym(पूर्णांक v);
ST_FUNC व्योम vpush_helper_func(पूर्णांक v);
ST_FUNC व्योम vset(CType *type, पूर्णांक r, पूर्णांक v);
ST_FUNC व्योम vset_VT_CMP(पूर्णांक op);
ST_FUNC व्योम vpushi(पूर्णांक v);
ST_FUNC व्योम vpushv(SValue *v);
ST_FUNC व्योम vpushsym(CType *type, Sym *sym);
ST_FUNC व्योम vswap(व्योम);
ST_FUNC व्योम vrott(पूर्णांक n);
ST_FUNC व्योम vrotb(पूर्णांक n);
ST_FUNC व्योम vrev(पूर्णांक n);
ST_FUNC व्योम vpop(व्योम);
#अगर PTR_आकार == 4
ST_FUNC व्योम lexpand(व्योम);
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_ARM
ST_FUNC पूर्णांक get_reg_ex(पूर्णांक rc, पूर्णांक rc2);
#पूर्ण_अगर
ST_FUNC व्योम save_reg(पूर्णांक r);
ST_FUNC व्योम save_reg_upstack(पूर्णांक r, पूर्णांक n);
ST_FUNC पूर्णांक get_reg(पूर्णांक rc);
ST_FUNC व्योम save_regs(पूर्णांक n);
ST_FUNC व्योम gaddrof(व्योम);
ST_FUNC पूर्णांक gv(पूर्णांक rc);
ST_FUNC व्योम gv2(पूर्णांक rc1, पूर्णांक rc2);
ST_FUNC व्योम gen_op(पूर्णांक op);
ST_FUNC पूर्णांक type_आकार(CType *type, पूर्णांक *a);
ST_FUNC व्योम mk_pointer(CType *type);
ST_FUNC व्योम vstore(व्योम);
ST_FUNC व्योम inc(पूर्णांक post, पूर्णांक c);
ST_FUNC CString* parse_mult_str(स्थिर अक्षर *संदेश);
ST_FUNC CString* parse_asm_str(व्योम);
ST_FUNC व्योम indir(व्योम);
ST_FUNC व्योम unary(व्योम);
ST_FUNC व्योम gexpr(व्योम);
ST_FUNC पूर्णांक व्यंजक_const(व्योम);
#अगर defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, अचिन्हित दीर्घ offset, अचिन्हित दीर्घ आकार);
#पूर्ण_अगर
#अगर defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC पूर्णांक classify_x86_64_va_arg(CType *ty);
#पूर्ण_अगर
#अगर_घोषित CONFIG_TCC_BCHECK
ST_FUNC व्योम gbound_args(पूर्णांक nb_args);
ST_तथ्य पूर्णांक func_bound_add_epilog;
#पूर्ण_अगर
ST_FUNC Sym *gfunc_set_param(Sym *s, पूर्णांक c, पूर्णांक byref);

/* ------------ tccelf.c ------------ */

#घोषणा TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#घोषणा TCC_OUTPUT_FORMAT_द्विआधारी 1 /* binary image output */
#घोषणा TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#घोषणा TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#घोषणा ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

प्रकार काष्ठा {
    अचिन्हित पूर्णांक n_strx;         /* index into string table of name */
    अचिन्हित अक्षर n_type;         /* type of symbol */
    अचिन्हित अक्षर n_other;        /* misc info (usually empty) */
    अचिन्हित लघु n_desc;        /* description field */
    अचिन्हित पूर्णांक n_मूल्य;        /* value of symbol */
} Stab_Sym;

ST_FUNC व्योम tccelf_new(TCCState *s);
ST_FUNC व्योम tccelf_delete(TCCState *s);
ST_FUNC व्योम tccelf_begin_file(TCCState *s1);
ST_FUNC व्योम tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, स्थिर अक्षर *name, पूर्णांक sh_type, पूर्णांक sh_flags);
ST_FUNC व्योम section_realloc(Section *sec, अचिन्हित दीर्घ new_आकार);
ST_FUNC माप_प्रकार section_add(Section *sec, addr_t आकार, पूर्णांक align);
ST_FUNC व्योम *section_ptr_add(Section *sec, addr_t आकार);
ST_FUNC Section *find_section(TCCState *s1, स्थिर अक्षर *name);
ST_FUNC व्योम free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, स्थिर अक्षर *symtab_name, पूर्णांक sh_type, पूर्णांक sh_flags, स्थिर अक्षर *strtab_name, स्थिर अक्षर *hash_name, पूर्णांक hash_sh_flags);
ST_FUNC व्योम init_symtab(Section *s);

ST_FUNC पूर्णांक put_elf_str(Section *s, स्थिर अक्षर *sym);
ST_FUNC पूर्णांक put_elf_sym(Section *s, addr_t मूल्य, अचिन्हित दीर्घ आकार, पूर्णांक info, पूर्णांक other, पूर्णांक shndx, स्थिर अक्षर *name);
ST_FUNC पूर्णांक set_elf_sym(Section *s, addr_t मूल्य, अचिन्हित दीर्घ आकार, पूर्णांक info, पूर्णांक other, पूर्णांक shndx, स्थिर अक्षर *name);
ST_FUNC पूर्णांक find_elf_sym(Section *s, स्थिर अक्षर *name);
ST_FUNC व्योम put_elf_reloc(Section *symtab, Section *s, अचिन्हित दीर्घ offset, पूर्णांक type, पूर्णांक प्रतीक);
ST_FUNC व्योम put_elf_reloca(Section *symtab, Section *s, अचिन्हित दीर्घ offset, पूर्णांक type, पूर्णांक प्रतीक, addr_t addend);

ST_FUNC व्योम resolve_common_syms(TCCState *s1);
ST_FUNC व्योम relocate_syms(TCCState *s1, Section *symtab, पूर्णांक do_resolve);
ST_FUNC व्योम relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(पूर्णांक fd, व्योम *buf, माप_प्रकार गिनती_2);
ST_FUNC व्योम *load_तथ्य(पूर्णांक fd, अचिन्हित दीर्घ file_offset, अचिन्हित दीर्घ आकार);
ST_FUNC पूर्णांक tcc_object_type(पूर्णांक fd, ElfW(Ehdr) *h);
ST_FUNC पूर्णांक tcc_load_object_file(TCCState *s1, पूर्णांक fd, अचिन्हित दीर्घ file_offset);
ST_FUNC पूर्णांक tcc_load_archive(TCCState *s1, पूर्णांक fd, पूर्णांक alacarte);
ST_FUNC व्योम add_array(TCCState *s1, स्थिर अक्षर *sec, पूर्णांक c);

ST_FUNC काष्ठा sym_attr *get_sym_attr(TCCState *s1, पूर्णांक सूचकांक, पूर्णांक alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, स्थिर अक्षर *name, पूर्णांक err, पूर्णांक forc);
ST_FUNC व्योम list_elf_symbols(TCCState *s, व्योम *ctx,
    व्योम (*प्रतीक_cb)(व्योम *ctx, स्थिर अक्षर *name, स्थिर व्योम *val));
ST_FUNC पूर्णांक set_global_sym(TCCState *s1, स्थिर अक्षर *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#घोषणा for_each_elem(sec, startoff, elem, type) \
    क्रम (elem = (type *) sec->तथ्य + startoff; \
         elem < (type *) (sec->तथ्य + sec->तथ्य_offset); elem++)

#अगर_अघोषित ELF_OBJ_ONLY
ST_FUNC पूर्णांक tcc_load_dll(TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename, पूर्णांक level);
ST_FUNC पूर्णांक tcc_load_ldscript(TCCState *s1, पूर्णांक fd);
ST_FUNC व्योम tccelf_add_crtbegin(TCCState *s1);
ST_FUNC व्योम tccelf_add_crtend(TCCState *s1);
#पूर्ण_अगर
#अगर_अघोषित TCC_TARGET_PE
ST_FUNC व्योम tcc_add_runtime(TCCState *s1);
#पूर्ण_अगर

/* ------------ xxx-link.c ------------ */

#अगर_अघोषित TCC_TARGET_PE
ST_FUNC पूर्णांक code_reloc (पूर्णांक reloc_type);
ST_FUNC पूर्णांक gotplt_entry_type (पूर्णांक reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
क्रमागत gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#घोषणा NEED_RELOC_TYPE
#अगर !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC अचिन्हित create_plt_entry(TCCState *s1, अचिन्हित got_offset, काष्ठा sym_attr *attr);
ST_FUNC व्योम relocate_plt(TCCState *s1);
ST_FUNC व्योम build_got_entries(TCCState *s1, पूर्णांक got_sym); /* in tccelf.c */
#घोषणा NEED_BUILD_GOT
#पूर्ण_अगर
#पूर्ण_अगर

ST_FUNC व्योम relocate(TCCState *s1, ElfW_Rel *rel, पूर्णांक type, अचिन्हित अक्षर *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_तथ्य स्थिर अक्षर * स्थिर target_machine_defs;
ST_तथ्य स्थिर पूर्णांक reg_classes[NB_REGS];

ST_FUNC व्योम gsym_addr(पूर्णांक t, पूर्णांक a);
ST_FUNC व्योम gsym(पूर्णांक t);
ST_FUNC व्योम load(पूर्णांक r, SValue *sv);
ST_FUNC व्योम store(पूर्णांक r, SValue *v);
ST_FUNC पूर्णांक gfunc_sret(CType *vt, पूर्णांक variadic, CType *ret, पूर्णांक *align, पूर्णांक *regsize);
ST_FUNC व्योम gfunc_call(पूर्णांक nb_args);
ST_FUNC व्योम gfunc_prolog(Sym *func_sym);
ST_FUNC व्योम gfunc_epilog(व्योम);
ST_FUNC व्योम gen_fill_nops(पूर्णांक);
ST_FUNC पूर्णांक gjmp(पूर्णांक t);
ST_FUNC व्योम gjmp_addr(पूर्णांक a);
ST_FUNC पूर्णांक gjmp_cond(पूर्णांक op, पूर्णांक t);
ST_FUNC पूर्णांक gjmp_append(पूर्णांक n, पूर्णांक t);
ST_FUNC व्योम gen_opi(पूर्णांक op);
ST_FUNC व्योम gen_opf(पूर्णांक op);
ST_FUNC व्योम gen_cvt_ftoi(पूर्णांक t);
ST_FUNC व्योम gen_cvt_itof(पूर्णांक t);
ST_FUNC व्योम gen_cvt_ftof(पूर्णांक t);
ST_FUNC व्योम ggoto(व्योम);
#अगर_अघोषित TCC_TARGET_C67
ST_FUNC व्योम o(अचिन्हित पूर्णांक c);
#पूर्ण_अगर
ST_FUNC व्योम gen_vla_sp_save(पूर्णांक addr);
ST_FUNC व्योम gen_vla_sp_restore(पूर्णांक addr);
ST_FUNC व्योम gen_vla_alloc(CType *type, पूर्णांक align);

अटल अंतरभूत uint16_t read16le(अचिन्हित अक्षर *p) {
    वापस p[0] | (uint16_t)p[1] << 8;
}
अटल अंतरभूत व्योम write16le(अचिन्हित अक्षर *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
अटल अंतरभूत uint32_t read32le(अचिन्हित अक्षर *p) {
  वापस read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
अटल अंतरभूत व्योम write32le(अचिन्हित अक्षर *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
अटल अंतरभूत व्योम add32le(अचिन्हित अक्षर *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
अटल अंतरभूत uint64_t read64le(अचिन्हित अक्षर *p) {
  वापस read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
अटल अंतरभूत व्योम write64le(अचिन्हित अक्षर *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
अटल अंतरभूत व्योम add64le(अचिन्हित अक्षर *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#अगर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC व्योम g(पूर्णांक c);
ST_FUNC व्योम gen_le16(पूर्णांक c);
ST_FUNC व्योम gen_le32(पूर्णांक c);
#पूर्ण_अगर
#अगर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC व्योम gen_addr32(पूर्णांक r, Sym *sym, पूर्णांक c);
ST_FUNC व्योम gen_addrpc32(पूर्णांक r, Sym *sym, पूर्णांक c);
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t);
ST_FUNC व्योम gen_increment_tcov (SValue *sv);
#पूर्ण_अगर

/* ------------ x86_64-gen.c ------------ */
#अगर_घोषित TCC_TARGET_X86_64
ST_FUNC व्योम gen_opl(पूर्णांक op);
#अगर_घोषित TCC_TARGET_PE
ST_FUNC व्योम gen_vla_परिणाम(पूर्णांक addr);
#पूर्ण_अगर
ST_FUNC व्योम gen_cvt_sxtw(व्योम);
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t);
#पूर्ण_अगर

/* ------------ arm-gen.c ------------ */
#अगर_घोषित TCC_TARGET_ARM
#अगर defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC स्थिर अक्षर *default_elfinterp(काष्ठा TCCState *s);
#पूर्ण_अगर
ST_FUNC व्योम arm_init(काष्ठा TCCState *s);
ST_FUNC व्योम gen_increment_tcov (SValue *sv);
#पूर्ण_अगर

/* ------------ arm64-gen.c ------------ */
#अगर_घोषित TCC_TARGET_ARM64
ST_FUNC व्योम gen_opl(पूर्णांक op);
ST_FUNC व्योम gfunc_return(CType *func_type);
ST_FUNC व्योम gen_va_start(व्योम);
ST_FUNC व्योम gen_va_arg(CType *t);
ST_FUNC व्योम gen_clear_cache(व्योम);
ST_FUNC व्योम gen_cvt_sxtw(व्योम);
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t);
ST_FUNC व्योम gen_increment_tcov (SValue *sv);
#पूर्ण_अगर

/* ------------ riscv64-gen.c ------------ */
#अगर_घोषित TCC_TARGET_RISCV64
ST_FUNC व्योम gen_opl(पूर्णांक op);
ST_FUNC व्योम gen_va_start(व्योम);
ST_FUNC व्योम arch_transfer_ret_regs(पूर्णांक);
ST_FUNC व्योम gen_cvt_sxtw(व्योम);
ST_FUNC व्योम gen_cvt_csti(पूर्णांक t);
ST_FUNC व्योम gen_increment_tcov (SValue *sv);
ST_FUNC व्योम gen_clear_cache(व्योम);
#पूर्ण_अगर

/* ------------ c67-gen.c ------------ */
#अगर_घोषित TCC_TARGET_C67
#पूर्ण_अगर

/* ------------ tcccoff.c ------------ */
#अगर_घोषित TCC_TARGET_COFF
ST_FUNC पूर्णांक tcc_output_coff(TCCState *s1, खाता *f);
ST_FUNC पूर्णांक tcc_load_coff(TCCState * s1, पूर्णांक fd);
#पूर्ण_अगर

/* ------------ tccasm.c ------------ */
ST_FUNC व्योम asm_instr(व्योम);
ST_FUNC व्योम asm_global_instr(व्योम);
ST_FUNC पूर्णांक tcc_assemble(TCCState *s1, पूर्णांक do_preprocess);
#अगर_घोषित CONFIG_TCC_ASM
ST_FUNC पूर्णांक find_constraint(ASMOperand *operands, पूर्णांक nb_operands, स्थिर अक्षर *name, स्थिर अक्षर **pp);
ST_FUNC Sym* get_asm_sym(पूर्णांक name, Sym *csym);
ST_FUNC व्योम asm_व्यंजक(TCCState *s1, व्यंजक_मूल्य *pe);
ST_FUNC पूर्णांक asm_int_व्यंजक(TCCState *s1);
#अगर PTR_आकार == 8
ST_FUNC व्योम gen_expr64(व्यंजक_मूल्य *pe);
#पूर्ण_अगर
/* ------------ i386-asm.c ------------ */
ST_FUNC व्योम gen_expr32(व्यंजक_मूल्य *pe);
ST_FUNC व्योम asm_opcode(TCCState *s1, पूर्णांक opcode);
ST_FUNC पूर्णांक asm_parse_regvar(पूर्णांक t);
ST_FUNC व्योम asm_compute_constraints(ASMOperand *operands, पूर्णांक nb_operands, पूर्णांक nb_outputs, स्थिर uint8_t *clobber_regs, पूर्णांक *pout_reg);
ST_FUNC व्योम subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier);
ST_FUNC व्योम asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands, पूर्णांक nb_outputs, पूर्णांक is_output, uint8_t *clobber_regs, पूर्णांक out_reg);
ST_FUNC व्योम asm_clobber(uint8_t *clobber_regs, स्थिर अक्षर *str);
#पूर्ण_अगर

/* ------------ tccpe.c -------------- */
#अगर_घोषित TCC_TARGET_PE
ST_FUNC पूर्णांक pe_load_file(काष्ठा TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename);
ST_FUNC पूर्णांक pe_output_file(TCCState * s1, स्थिर अक्षर *filename);
ST_FUNC पूर्णांक pe_putimport(TCCState *s1, पूर्णांक dllindex, स्थिर अक्षर *name, addr_t मूल्य);
ST_FUNC पूर्णांक pe_setsubsy(TCCState *s1, स्थिर अक्षर *arg);
#अगर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#पूर्ण_अगर
#अगर defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC व्योम pe_add_unwind_तथ्य(अचिन्हित start, अचिन्हित end, अचिन्हित ढेर);
#पूर्ण_अगर
PUB_FUNC पूर्णांक tcc_get_dllexports(स्थिर अक्षर *filename, अक्षर **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#पूर्ण_अगर
#घोषणा ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#अगर_घोषित TCC_TARGET_MACHO
ST_FUNC पूर्णांक macho_output_file(TCCState * s1, स्थिर अक्षर *filename);
ST_FUNC पूर्णांक macho_load_dll(TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename, पूर्णांक lev);
ST_FUNC पूर्णांक macho_load_tbd(TCCState *s1, पूर्णांक fd, स्थिर अक्षर *filename, पूर्णांक lev);
#अगर_घोषित TCC_IS_NATIVE
ST_FUNC व्योम tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC अक्षर* macho_tbd_soname(पूर्णांक fd);
#पूर्ण_अगर
#पूर्ण_अगर
/* ------------ tccrun.c ----------------- */
#अगर_घोषित TCC_IS_NATIVE
#अगर_घोषित CONFIG_TCC_STATIC
#घोषणा RTLD_LAZY       0x001
#घोषणा RTLD_NOW        0x002
#घोषणा RTLD_GLOBAL     0x100
#घोषणा RTLD_DEFAULT    शून्य
/* dummy function for profiling */
ST_FUNC व्योम *dlopen(स्थिर अक्षर *filename, पूर्णांक flag);
ST_FUNC व्योम dlclose(व्योम *p);
ST_FUNC स्थिर अक्षर *dlerror(व्योम);
ST_FUNC व्योम *dlsym(व्योम *handle, स्थिर अक्षर *प्रतीक);
#पूर्ण_अगर
ST_FUNC व्योम tcc_run_free(TCCState *s1);
#पूर्ण_अगर

/* ------------ tcctools.c ----------------- */
#अगर 0 /* included in tcc.c */
ST_FUNC पूर्णांक tcc_tool_ar(TCCState *s, पूर्णांक argc, अक्षर **argv);
#अगर_घोषित TCC_TARGET_PE
ST_FUNC पूर्णांक tcc_tool_impdef(TCCState *s, पूर्णांक argc, अक्षर **argv);
#पूर्ण_अगर
ST_FUNC पूर्णांक tcc_tool_cross(TCCState *s, अक्षर **argv, पूर्णांक option);
ST_FUNC पूर्णांक gen_makedeps(TCCState *s, स्थिर अक्षर *target, स्थिर अक्षर *filename);
#पूर्ण_अगर

/* ------------ tccdbg.c ------------ */

ST_FUNC व्योम tcc_debug_new(TCCState *s);

ST_FUNC व्योम tcc_debug_start(TCCState *s1);
ST_FUNC व्योम tcc_debug_end(TCCState *s1);
ST_FUNC व्योम tcc_debug_bincl(TCCState *s1);
ST_FUNC व्योम tcc_debug_eincl(TCCState *s1);
ST_FUNC व्योम tcc_debug_newfile(TCCState *s1);

ST_FUNC व्योम tcc_debug_पंक्ति(TCCState *s1);
ST_FUNC व्योम tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC व्योम tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC व्योम tcc_debug_prolog_epilog(TCCState *s1, पूर्णांक मूल्य);
ST_FUNC व्योम tcc_debug_funcend(TCCState *s1, पूर्णांक आकार);
ST_FUNC व्योम tcc_debug_extern_sym(TCCState *s1, Sym *sym, पूर्णांक sh_अंक, पूर्णांक sym_bind, पूर्णांक sym_type);
ST_FUNC व्योम tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC व्योम tcc_debug_stabn(TCCState *s1, पूर्णांक type, पूर्णांक मूल्य);
ST_FUNC व्योम tcc_debug_fix_forw(TCCState *s1, CType *t);

#अगर !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC व्योम tcc_eh_frame_start(TCCState *s1);
ST_FUNC व्योम tcc_eh_frame_end(TCCState *s1);
ST_FUNC व्योम tcc_eh_frame_hdr(TCCState *s1, पूर्णांक final);
#घोषणा TCC_EH_FRAME 1
#पूर्ण_अगर

ST_FUNC व्योम tcc_tcov_start(TCCState *s1);
ST_FUNC व्योम tcc_tcov_end(TCCState *s1);
ST_FUNC व्योम tcc_tcov_check_पंक्ति(TCCState *s1, पूर्णांक start);
ST_FUNC व्योम tcc_tcov_block_end(TCCState *s1, पूर्णांक पंक्ति_2);
ST_FUNC व्योम tcc_tcov_block_begin(TCCState *s1);
ST_FUNC व्योम tcc_tcov_reset_ind(TCCState *s1);

#घोषणा stab_section            s1->stab_section
#घोषणा stabstr_section         stab_section->link
#घोषणा tcov_section            s1->tcov_section
#घोषणा eh_frame_section        s1->eh_frame_section
#घोषणा eh_frame_hdr_section    s1->eh_frame_hdr_section
#घोषणा dwarf_info_section      s1->dwarf_info_section
#घोषणा dwarf_abbrev_section    s1->dwarf_abbrev_section
#घोषणा dwarf_पंक्ति_section      s1->dwarf_पंक्ति_section
#घोषणा dwarf_aranges_section   s1->dwarf_aranges_section
#घोषणा dwarf_str_section       s1->dwarf_str_section
#घोषणा dwarf_पंक्ति_str_section  s1->dwarf_पंक्ति_str_section

#घोषणा DWARF_MAX_128	((8 * माप (int64_t) + 6) / 7)
#घोषणा	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#घोषणा	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#घोषणा	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#घोषणा	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
अटल अंतरभूत uint64_t
dwarf_read_uleb128(अचिन्हित अक्षर **ln, अचिन्हित अक्षर *end)
{
    अचिन्हित अक्षर *cp = *ln;
    uint64_t retval = 0;
    पूर्णांक i;
    क्रम (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	अगर ((byte & 0x80) == 0)
	    अवरोध;
    }
    *ln = cp;
    वापस retval;
}
अटल अंतरभूत int64_t
dwarf_read_sleb128(अचिन्हित अक्षर **ln, अचिन्हित अक्षर *end)
{
    अचिन्हित अक्षर *cp = *ln;
    int64_t retval = 0;
    पूर्णांक i;
    क्रम (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	अगर ((byte & 0x80) == 0) {
	    अगर ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    अवरोध;
	}
    }
    *ln = cp;
    वापस retval;
}

/* default dwarf version for "-gdwarf" */
#अगर_घोषित TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#अन्यथा
# define DEFAULT_DWARF_VERSION 5
#पूर्ण_अगर

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#अगर_अघोषित CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#पूर्ण_अगर

#अगर defined TCC_TARGET_X86_64
# define R_तथ्य_32_DW R_X86_64_32
#अन्यथा
# define R_तथ्य_32_DW R_तथ्य_32
#पूर्ण_अगर

/********************************************************/
#अगर CONFIG_TCC_SEMLOCK
#अगर defined _WIN32
प्रकार काष्ठा { अस्थिर LONG init; CRITICAL_SECTION cs; } TCCSem;
अटल अंतरभूत व्योम wait_sem(TCCSem *p) {
    अगर (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } अन्यथा {
        जबतक (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
अटल अंतरभूत व्योम post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#या_अगर defined __APPLE__
#समावेश <dispatch/dispatch.h>
प्रकार काष्ठा { पूर्णांक init; dispatch_semaphore_t sem; } TCCSem;
अटल अंतरभूत व्योम wait_sem(TCCSem *p) {
    अगर (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
अटल अंतरभूत व्योम post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#अन्यथा
#समावेश <semaphore.h>
प्रकार काष्ठा { पूर्णांक init; sem_t sem; } TCCSem;
अटल अंतरभूत व्योम wait_sem(TCCSem *p) {
    अगर (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    जबतक (sem_wait(&p->sem) < 0 && त्रुटि_सं == EINTR);
}
अटल अंतरभूत व्योम post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#पूर्ण_अगर
#घोषणा TCC_SEM(s) TCCSem s
#घोषणा WAIT_SEM wait_sem
#घोषणा POST_SEM post_sem
#अन्यथा
#घोषणा TCC_SEM(s)
#घोषणा WAIT_SEM(p)
#घोषणा POST_SEM(p)
#पूर्ण_अगर

/********************************************************/
#अघोषित ST_तथ्य
#अगर ONE_SOURCE
#घोषणा ST_तथ्य अटल
#अन्यथा
#घोषणा ST_तथ्य
#पूर्ण_अगर
/********************************************************/

#घोषणा text_section        TCC_STATE_VAR(text_section)
#घोषणा तथ्य_section        TCC_STATE_VAR(तथ्य_section)
#घोषणा rodata_section      TCC_STATE_VAR(rodata_section)
#घोषणा bss_section         TCC_STATE_VAR(bss_section)
#घोषणा common_section      TCC_STATE_VAR(common_section)
#घोषणा cur_text_section    TCC_STATE_VAR(cur_text_section)
#घोषणा bounds_section      TCC_STATE_VAR(bounds_section)
#घोषणा lbounds_section     TCC_STATE_VAR(lbounds_section)
#घोषणा symtab_section      TCC_STATE_VAR(symtab_section)
#घोषणा gnu_ext             TCC_STATE_VAR(gnu_ext)
#घोषणा tcc_error_noabort   TCC_SET_STATE(_tcc_error_noabort)
#घोषणा tcc_error           TCC_SET_STATE(_tcc_error)
#घोषणा tcc_warning         TCC_SET_STATE(_tcc_warning)

#घोषणा योग_idents        TCC_STATE_VAR(योग_idents)
#घोषणा योग_पंक्तियाँ         TCC_STATE_VAR(योग_पंक्तियाँ)
#घोषणा योग_bytes         TCC_STATE_VAR(योग_bytes)

PUB_FUNC व्योम tcc_enter_state(TCCState *s1);
PUB_FUNC व्योम tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#घोषणा tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_अंक = दुरत्व(TCCState, sw) \
    - दुरत्व(TCCState, warn_none), _tcc_warning))

/********************************************************/
#पूर्ण_अगर /* _TCC_H */

#अघोषित TCC_STATE_VAR
#अघोषित TCC_SET_STATE

#अगर_घोषित USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_SET_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#अन्यथा
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#पूर्ण_अगर
