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

#यदि_अपरिभाषितम् _TCC_H
#परिभाषय _TCC_H

#परिभाषय _GNU_SOURCE
#परिभाषय _DARWIN_C_SOURCE
#अन्तर्भाव "config.h"

#अन्तर्भाव <stdarg.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#यदि_परिभाषितम् __TINYC__
# undef __attribute__
#यदि_अन्तः
#अन्तर्भाव <string.h>
#अन्तर्भाव <errno.h>
#अन्तर्भाव <math.h>
#अन्तर्भाव <fcntl.h>
#अन्तर्भाव <setjmp.h>
#अन्तर्भाव <time.h>

#यदि_अपरिभाषितम् _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
बाह्य भिन्न strtof (ध्रुव वर्ण *__nptr, वर्ण **__endptr);
बाह्य दीर्घ द्विगुण strtold (ध्रुव वर्ण *__nptr, वर्ण **__endptr);
#यदि_अन्तः

#यदि_परिभाषितम् _WIN32
# define WIN32_LEAN_AND_माध्यम् 1
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
# define अन्तःस्थ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (दीर्घ द्विगुण)strtod
#  define strtof (भिन्न)strtod
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
# यदि defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#यदि_अन्तः

#यदि_अपरिभाषितम् O_द्विमान_2
# define O_द्विमान_2 0
#यदि_अन्तः

#यदि_अपरिभाषितम् offsetof
#यदि_परिभाषितम् __clang__ // clang -fsanitize compains about: NULL+value
#परिभाषय offsetof(type, क्षेत्रम्) __builtin_offsetof(type, क्षेत्रम्)
#अन्यथा
#परिभाषय offsetof(type, क्षेत्रम्) ((आकार_t) &((type *)0)->क्षेत्रम्)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् countof
#परिभाषय countof(tab) (परिमाण(tab) / परिमाण((tab)[0]))
#यदि_अन्तः

#यदि_परिभाषितम् _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#अन्यथा
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (प्रारूप_लिख, (x), (y))))
#यदि_अन्तः

#यदि_परिभाषितम् _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#अन्यथा
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP वाक्यं_तुलय
# define PATHSEP ":"
#यदि_अन्तः

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
#यदि !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# यदि defined __x86_64__
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
#यदि_अन्तः

/* only native compiler supports -run */
#यदि defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# यदि defined __i386__ && defined TCC_TARGET_I386
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
#यदि_अन्तः

#यदि defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#अन्यथा
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#यदि_अन्तः

#यदि defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#अन्यथा
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#यदि_अन्तः

#यदि defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#अन्यथा
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#यदि_अन्तः

#यदि defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#नोचेद्यदि !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#यदि_अन्तः

#यदि defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#अन्यथा
# define TCC_TARGET_UNIX 1
#यदि_अन्तः

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#यदि defined TCC_TARGET_PE \
    || (defined TCC_TARGET_MACHO && defined TCC_TARGET_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#यदि_अन्तः

#यदि_परिभाषितम् CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#यदि_अन्तः

/* support using libtcc from threads */
#यदि_अपरिभाषितम् CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#यदि_अन्तः

/* ------------ path configuration ------------ */

#यदि_अपरिभाषितम् CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#यदि_अन्तः

#यदि !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#यदि_अन्तः

#यदि_परिभाषितम् CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#अन्यथा
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#यदि_अन्तः

/* path to find crt1.o, crti.o and crtn.o */
#यदि_अपरिभाषितम् CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#यदि_अन्तः

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#यदि_अपरिभाषितम् CONFIG_TCC_SYSINCLUDEPATHS
# यदि defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# अन्यथा
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#यदि_अन्तः

/* library search paths */
#यदि_अपरिभाषितम् CONFIG_TCC_LIBPATHS
# यदि defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# अन्यथा
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#यदि_अन्तः

/* name of ELF interpreter */
#यदि_अपरिभाषितम् CONFIG_TCC_ELFINTERP
# यदि defined __GNU__
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
#यदि_अन्तः

/* (target specific) libtcc1.a */
#यदि_अपरिभाषितम् TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#यदि_अन्तः

/* <cross-prefix-to->libtcc1.a */
#यदि_अपरिभाषितम् CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#यदि_अन्तः

/* -------------------------------------------- */

#अन्तर्भाव "libtcc.h"
#अन्तर्भाव "elf.h"
#अन्तर्भाव "stab.h"
#अन्तर्भाव "dwarf.h"

/* -------------------------------------------- */

#यदि_अपरिभाषितम् PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#यदि_अन्तः

#यदि_अपरिभाषितम् ONE_SOURCE
# define ONE_SOURCE 0
#यदि_अन्तः

#यदि ONE_SOURCE
#परिभाषय ST_INLN स्थिर अन्तःस्थ
#परिभाषय ST_FUNC स्थिर
#परिभाषय ST_दत्त स्थिर
#अन्यथा
#परिभाषय ST_INLN
#परिभाषय ST_FUNC
#परिभाषय ST_दत्त बाह्य
#यदि_अन्तः

#यदि_परिभाषितम् TCC_PROFILE /* profile all functions */
# define स्थिर
# define अन्तःस्थ
#यदि_अन्तः

/* -------------------------------------------- */
/* include the target specific definitions */

#परिभाषय TARGET_DEFS_ONLY
#यदि_परिभाषितम् TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#नोचेद्यदि defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#नोचेद्यदि defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#नोचेद्यदि defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#नोचेद्यदि defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#नोचेद्यदि defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#अन्यथा
#दोषः unknown target
#यदि_अन्तः
#अपरिभाषय TARGET_DEFS_ONLY

/* -------------------------------------------- */

#यदि PTR_आकार == 8
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
#यदि_अन्तः
/* target address type */
#परिभाषय addr_t ElfW(Addr)
#परिभाषय ElfSym ElfW(Sym)

#यदि PTR_आकार == 8 && !defined TCC_TARGET_PE
# define LONG_आकार 8
#अन्यथा
# define LONG_आकार 4
#यदि_अन्तः

/* -------------------------------------------- */

#परिभाषय INCLUDE_राशिः_आकार  32
#परिभाषय IFDEF_राशिः_आकार    64
#परिभाषय VSTACK_आकार         512
#परिभाषय STRING_MAX_आकार     1024
#परिभाषय TOKSTR_MAX_आकार     256
#परिभाषय PACK_राशिः_आकार     8

#परिभाषय TOK_HASH_आकार       16384 /* must be a power of two */
#परिभाषय TOK_ALLOC_INCR      512  /* must be a power of two */
#परिभाषय TOK_MAX_आकार        4 /* token max size in int unit when stored in string */

/* token symbol management */
प्रकारनिर्देश संरचना TokenSym {
    संरचना TokenSym *hash_अग्र;
    संरचना Sym *sym_define; /* direct pointer to define */
    संरचना Sym *sym_label; /* direct pointer to label */
    संरचना Sym *sym_struct; /* direct pointer to structure */
    संरचना Sym *sym_identifier; /* direct pointer to identifier */
    पूर्णाङ्क tok; /* token number */
    पूर्णाङ्क len;
    वर्ण str[1];
} TokenSym;

#यदि_परिभाषितम् TCC_TARGET_PE
प्रकारनिर्देश अचिह्नित ह्रस्व nwchar_t;
#अन्यथा
प्रकारनिर्देश पूर्णाङ्क nwchar_t;
#यदि_अन्तः

प्रकारनिर्देश संरचना CString {
    पूर्णाङ्क आकार; /* size in bytes */
    पूर्णाङ्क आकार_allocated;
    वर्ण *दत्त; /* nwchar_t* in cases */
} CString;

/* type definition */
प्रकारनिर्देश संरचना CType {
    पूर्णाङ्क t;
    संरचना Sym *ref;
} CType;

/* long double words on host(!) platform */
#परिभाषय LDOUBLE_शब्दाः ((परिमाण(दीर्घ द्विगुण)+3)/4)

/* constant value */
प्रकारनिर्देश सङ्घ CValue {
    दीर्घ द्विगुण ld;
    द्विगुण d;
    भिन्न f;
    uint64_t i;
    संरचना {
        वर्ण *दत्त;
        पूर्णाङ्क आकार;
    } str;
    पूर्णाङ्क tab[LDOUBLE_शब्दाः];
} CValue;

/* value on stack */
प्रकारनिर्देश संरचना SValue {
    CType type;      /* type */
    अचिह्नित ह्रस्व r;      /* register + flags */
    अचिह्नित ह्रस्व r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    सङ्घ {
      संरचना { पूर्णाङ्क jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    सङ्घ {
      संरचना { अचिह्नित ह्रस्व cmp_op, cmp_r; }; /* VT_CMP operation */
      संरचना Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
संरचना SymAttr {
    अचिह्नित ह्रस्व
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
संरचना FuncAttr {
    अचिह्नित
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_तर्काः   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
प्रकारनिर्देश संरचना Sym {
    पूर्णाङ्क v; /* symbol token */
    अचिह्नित ह्रस्व r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    संरचना SymAttr a; /* symbol attributes */
    सङ्घ {
        संरचना {
            पूर्णाङ्क c; /* associated number or Elf symbol index */
            सङ्घ {
                पूर्णाङ्क sym_scope; /* scope level for locals */
                पूर्णाङ्क jnext; /* next jump label */
                पूर्णाङ्क jind; /* label position */
                संरचना FuncAttr f; /* function attributes */
                पूर्णाङ्क auxtype; /* bitfield access type */
            };
        };
        दीर्घ दीर्घ enum_val; /* enum constant if IS_ENUM_VAL */
        पूर्णाङ्क *d; /* define token stream */
        संरचना Sym *cleanup_func;
    };

    CType type; /* associated type */
    सङ्घ {
        संरचना Sym *अग्र; /* next related symbol (for fields and anoms) */
        पूर्णाङ्क *e; /* expanded token stream with preprocessor macros */
        पूर्णाङ्क asm_label; /* associated asm label */
        संरचना Sym *cleanupstate; /* in defined labels */
        पूर्णाङ्क *vla_array_str; /* vla array code */
    };
    संरचना Sym *पूर्व; /* prev symbol in stack */
    सङ्घ {
        संरचना Sym *पूर्व_tok; /* previous symbol for this token */
        संरचना Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        संरचना Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
प्रकारनिर्देश संरचना Section {
    अचिह्नित दीर्घ दत्त_विस्थापनम्; /* current data offset */
    अचिह्नित वर्ण *दत्त;       /* section data */
    अचिह्नित दीर्घ दत्त_allocated; /* used for realloc() handling */
    TCCState *s1;
    पूर्णाङ्क sh_name;             /* elf section name (only used during output) */
    पूर्णाङ्क sh_अङ्कः;              /* elf section number */
    पूर्णाङ्क sh_type;             /* elf section type */
    पूर्णाङ्क sh_flags;            /* elf section flags */
    पूर्णाङ्क sh_info;             /* elf section info */
    पूर्णाङ्क sh_addralign;        /* elf section alignment */
    पूर्णाङ्क sh_entsize;          /* elf entry size */
    अचिह्नित दीर्घ sh_आकार;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    अचिह्नित दीर्घ sh_विस्थापनम्; /* file offset */
    पूर्णाङ्क nb_hashed_syms;      /* used to resize the hash table */
    संरचना Section *link;    /* link to another section */
    संरचना Section *reloc;   /* corresponding section for relocation, if any */
    संरचना Section *hash;    /* hash table for symbols */
    संरचना Section *पूर्व;    /* previous section on section stack */
    वर्ण name[1];           /* section name */
} Section;

प्रकारनिर्देश संरचना DLLReference {
    पूर्णाङ्क level;
    शून्य *handle;
    अचिह्नित वर्ण प्राप्तम्, सूचकांक;
    वर्ण name[1];
} DLLReference;

/* -------------------------------------------------- */

#परिभाषय SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#परिभाषय SYM_क्षेत्रम्      0x20000000 /* struct/union field symbol space */
#परिभाषय SYM_FIRST_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#परिभाषय FUNC_NEW       1 /* ansi function prototype */
#परिभाषय FUNC_OLD       2 /* old function prototype */
#परिभाषय FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#परिभाषय FUNC_CDECL     0 /* standard c call */
#परिभाषय FUNC_STDCALL   1 /* pascal c call */
#परिभाषय FUNC_FASTCALL1 2 /* first param in %eax */
#परिभाषय FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#परिभाषय FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#परिभाषय FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#परिभाषय FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#परिभाषय MACRO_OBJ      0 /* object like macro */
#परिभाषय MACRO_FUNC     1 /* function like macro */
#परिभाषय MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#परिभाषय LABEL_DEFINED  0 /* label is defined */
#परिभाषय LABEL_FORWARD  1 /* label is forward defined */
#परिभाषय LABEL_DECLARED 2 /* label is declared but never used */
#परिभाषय LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#परिभाषय TYPE_ABSTRACT  1 /* type without variable */
#परिभाषय TYPE_प्रत्यक्षम्    2 /* type with variable */
#परिभाषय TYPE_PARAM     4 /* type declares function parameter */
#परिभाषय TYPE_NEST      8 /* nested call to post_type */

#परिभाषय IO_BUF_आकार 8192

प्रकारनिर्देश संरचना BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_अन्तः;
    पूर्णाङ्क fd;
    संरचना BufferedFile *पूर्व;
    पूर्णाङ्क पङ्क्तिः_अङ्कः;    /* current line number - here to simplify code */
    पूर्णाङ्क पङ्क्तिः_ref;    /* tcc -E: last printed line */
    पूर्णाङ्क ifndef_macro;  /* #ifndef macro / #endif search */
    पूर्णाङ्क ifndef_macro_saved; /* saved ifndef_macro */
    पूर्णाङ्क *ifdef_राशिः_ptr; /* ifdef_stack value at the start of the file */
    पूर्णाङ्क include_अग्र_सूचकांक; /* next search path */
    पूर्णाङ्क पूर्व_tok_flags; /* saved tok_flags */
    वर्ण filename[1024];    /* filename */
    वर्ण *true_filename; /* filename not modified by # line directive */
    अचिह्नित वर्ण unget[4];
    अचिह्नित वर्ण बफर[1]; /* extra size for CH_EOB char */
} BufferedFile;

#परिभाषय CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#परिभाषय CH_EOF   (-1)   /* end of file */

/* used to record tokens */
प्रकारनिर्देश संरचना TokenString {
    पूर्णाङ्क *str;
    पूर्णाङ्क len;
    पूर्णाङ्क need_spc;
    पूर्णाङ्क allocated_len;
    पूर्णाङ्क चरमः_पङ्क्तिः_अङ्कः;
    पूर्णाङ्क save_पङ्क्तिः_अङ्कः;
    /* used to chain token-strings with begin/end_macro() */
    संरचना TokenString *पूर्व;
    ध्रुव पूर्णाङ्क *पूर्व_ptr;
    वर्ण alloc;
} TokenString;

/* GNUC attribute definition */
प्रकारनिर्देश संरचना AttributeDef {
    संरचना SymAttr a;
    संरचना FuncAttr f;
    संरचना Section *section;
    Sym *cleanup_func;
    पूर्णाङ्क alias_target; /* token */
    पूर्णाङ्क asm_label; /* associated asm label */
    वर्ण attr_बहुलकम्; /* __attribute__((__mode__(...))) */
    वर्ण new_section; /* section is new */
} AttributeDef;

/* inline functions */
प्रकारनिर्देश संरचना InlineFunc {
    TokenString *func_str;
    Sym *sym;
    वर्ण filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
प्रकारनिर्देश संरचना CachedInclude {
    पूर्णाङ्क ifndef_macro;
    पूर्णाङ्क once;
    पूर्णाङ्क hash_अग्र; /* -1 if none */
    वर्ण filename[1]; /* path specified in #include */
} CachedInclude;

#परिभाषय CACHED_INCLUDES_HASH_आकार 32

#यदि_परिभाषितम् CONFIG_TCC_ASM
प्रकारनिर्देश संरचना व्यञ्जकम्_मानम् {
    uint64_t v;
    Sym *sym;
    पूर्णाङ्क pcrel;
} व्यञ्जकम्_मानम्;

#परिभाषय MAX_ASM_OPERANDS 30
प्रकारनिर्देश संरचना ASMOperand {
    पूर्णाङ्क id; /* GCC 3 optional identifier (0 if number only supported) */
    वर्ण constraint[16];
    वर्ण asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    पूर्णाङ्क ref_सूचकांक; /* if >= 0, gives reference to a output constraint */
    पूर्णाङ्क निवेशः_सूचकांक; /* if >= 0, gives reference to an input constraint */
    पूर्णाङ्क प्राथमिकता; /* priority, used to assign registers */
    पूर्णाङ्क reg; /* if >= 0, register number used for this operand */
    पूर्णाङ्क is_llong; /* true if double register value */
    पूर्णाङ्क is_स्मृतिः; /* true if memory operand */
    पूर्णाङ्क is_rw;     /* for '+' modifier */
    पूर्णाङ्क is_label;  /* for asm goto */
} ASMOperand;
#यदि_अन्तः

/* extra symbol attributes (not in symbol table) */
संरचना sym_attr {
    अचिह्नित got_विस्थापनम्;
    अचिह्नित plt_विस्थापनम्;
    पूर्णाङ्क plt_sym;
    पूर्णाङ्क dyn_सूचकांक;
    अचिह्नित वर्ण linker_sym:1;
#यदि_परिभाषितम् TCC_TARGET_ARM
    अचिह्नित वर्ण plt_thumb_stub:1;
#यदि_अन्तः
};

संरचना TCCState {
    अचिह्नित वर्ण verbose; /* if true, display some information during compilation */
    अचिह्नित वर्ण nostdinc; /* if true, no standard headers are added */
    अचिह्नित वर्ण nostdlib; /* if true, no standard libraries are added */
    अचिह्नित वर्ण nostdlib_paths; /* if true, the default paths are not searched for libraries */
    अचिह्नित वर्ण nocommon; /* if true, do not use common symbols for .bss data */
    अचिह्नित वर्ण static_link; /* if true, static linking is performed */
    अचिह्नित वर्ण rdynamic; /* if true, all symbols are exported */
    अचिह्नित वर्ण symbolic; /* if true, resolve symbols in the current module first */
    अचिह्नित वर्ण znodelete; /* Set DF_1_NODELETE in dynamic section */
    अचिह्नित वर्ण filetype; /* file type for compilation (NONE,C,ASM) */
    अचिह्नित वर्ण optimize; /* only to #define __OPTIMIZE__ */
    अचिह्नित वर्ण option_pthread; /* -pthread option */
    अचिह्नित वर्ण enable_new_dtags; /* -Wl,--enable-new-dtags */
    अचिह्नित पूर्णाङ्क  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    अचिह्नित वर्ण char_is_unsigned;
    अचिह्नित वर्ण leading_underscore;
    अचिह्नित वर्ण ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    अचिह्नित वर्ण dollars_अन्तर्_identifiers;  /* allows '$' char in identifiers */
    अचिह्नित वर्ण ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    अचिह्नित वर्ण reverse_funcargs; /* if true, evaluate last function arg first */
    अचिह्नित वर्ण gnu89_inline; /* treat 'extern inline' like 'static inline' */
    अचिह्नित वर्ण unwind_tables; /* create eh_frame section */

    /* warning switches */
    अचिह्नित वर्ण warn_none;
    अचिह्नित वर्ण warn_all;
    अचिह्नित वर्ण warn_error;
    अचिह्नित वर्ण warn_write_वाक्यानि;
    अचिह्नित वर्ण warn_unsupported;
    अचिह्नित वर्ण warn_implicit_function_declaration;
    अचिह्नित वर्ण warn_discarded_qualifiers;
    #परिभाषय WARN_ON  1 /* warning is on (-Woption) */
    अचिह्नित वर्ण warn_अङ्कः; /* temp var for tcc_warning_c() */

    अचिह्नित वर्ण option_r; /* option -r */
    अचिह्नित वर्ण do_bench; /* option -bench */
    अचिह्नित वर्ण just_deps; /* option -M  */
    अचिह्नित वर्ण gen_deps; /* option -MD  */
    अचिह्नित वर्ण include_sys_deps; /* option -MD  */
    अचिह्नित वर्ण gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    अचिह्नित वर्ण do_debug;
    अचिह्नित वर्ण dwarf;
    अचिह्नित वर्ण do_backtrace;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    अचिह्नित वर्ण do_bounds_check;
#यदि_अन्तः
    अचिह्नित वर्ण test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    अचिह्नित वर्ण gnu_ext;
    /* use TinyCC extensions */
    अचिह्नित वर्ण tcc_ext;

    अचिह्नित वर्ण dflag; /* -dX value */
    अचिह्नित वर्ण Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#यदि_परिभाषितम् TCC_TARGET_X86_64
    अचिह्नित वर्ण nosse; /* For -mno-sse support. */
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_ARM
    अचिह्नित वर्ण float_abi; /* float ABI of the generated code*/
#यदि_अन्तः

    अचिह्नित वर्ण has_text_addr;
    addr_t text_addr; /* address of text section */
    अचिह्नित section_align; /* section alignment */
#यदि_परिभाषितम् TCC_TARGET_I386
    पूर्णाङ्क seg_आकार; /* 32. Can be 16 with i386 assembler (.code16) */
#यदि_अन्तः

    वर्ण *tcc_lib_मार्गः; /* CONFIG_TCCDIR or -B option */
    वर्ण *soname; /* as specified on the command line (-soname) */
    वर्ण *rpath; /* as specified on the command line (-Wl,-rpath=) */
    वर्ण *elfint; /* -Wl,-I... on command line */
    वर्ण *elf_entryname; /* "_start" unless set */
    वर्ण *init_चिह्नम्; /* symbols to call at load-time (not used currently) */
    वर्ण *fini_चिह्नम्; /* symbols to call at unload-time (not used currently) */
    वर्ण *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    पूर्णाङ्क output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    पूर्णाङ्क output_format;
    /* nth test to run with -dt -run */
    पूर्णाङ्क सततम्_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    पूर्णाङ्क nb_loaded_dlls;

    /* include paths */
    वर्ण **include_paths;
    पूर्णाङ्क nb_include_paths;

    वर्ण **sysinclude_paths;
    पूर्णाङ्क nb_sysinclude_paths;

    /* library paths */
    वर्ण **library_paths;
    पूर्णाङ्क nb_library_paths;

    /* crt?.o object path */
    वर्ण **crt_paths;
    पूर्णाङ्क nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    शून्य *error_opaque;
    शून्य (*error_func)(शून्य *opaque, ध्रुव वर्ण *सन्देशः);
    पूर्णाङ्क error_समुच्चयः_jmp_enabled;
    jmp_buf error_jmp_buf;
    पूर्णाङ्क nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    वर्ण **target_deps;
    पूर्णाङ्क nb_target_deps;

    /* compilation */
    BufferedFile *include_राशिः[INCLUDE_राशिः_आकार];
    BufferedFile **include_राशिः_ptr;

    पूर्णाङ्क ifdef_राशिः[IFDEF_राशिः_आकार];
    पूर्णाङ्क *ifdef_राशिः_ptr;

    /* included files enclosed with #ifndef MACRO */
    पूर्णाङ्क cached_includes_hash[CACHED_INCLUDES_HASH_आकार];
    CachedInclude **cached_includes;
    पूर्णाङ्क nb_cached_includes;

    /* #pragma pack stack */
    पूर्णाङ्क pack_राशिः[PACK_राशिः_आकार];
    पूर्णाङ्क *pack_राशिः_ptr;
    वर्ण **pragma_libs;
    पूर्णाङ्क nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    संरचना InlineFunc **inline_fns;
    पूर्णाङ्क nb_inline_fns;

    /* sections */
    Section **sections;
    पूर्णाङ्क nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    पूर्णाङ्क nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *text_section, *दत्त_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_text_section; /* current section where function code is generated */
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#यदि_अन्तः
    /* symbol section */
    सङ्घ { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_frame_section;
    Section *eh_frame_hdr_section;
    अचिह्नित दीर्घ eh_start;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_पङ्क्तिः_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_पङ्क्तिः_str_section;
    पूर्णाङ्क dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    संरचना _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    संरचना sym_attr *sym_attrs;
    पूर्णाङ्क nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #परिभाषय qrel s1->qrel

    addr_t tls_start, tls_अन्तः;

#यदि_परिभाषितम् TCC_TARGET_RISCV64
    संरचना pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    पूर्णाङ्क nb_pcrel_hi_entries;
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_PE
    /* PE info */
    पूर्णाङ्क pe_subsystem;
    अचिह्नित pe_characteristics;
    अचिह्नित pe_dll_characteristics;
    अचिह्नित pe_file_align;
    अचिह्नित pe_राशिः_आकार;
    addr_t pe_imagebase;
# यदि defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    पूर्णाङ्क uw_sym;
    पूर्णाङ्क uw_xsym;
    अचिह्नित uw_offs;
# endif
#यदि_अन्तः

#यदि defined TCC_TARGET_MACHO
    वर्ण *install_name;
    uint32_t compatibility_संस्करणम्;
    uint32_t current_संस्करणम्;
#यदि_अन्तः

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
    पूर्णाङ्क nb_sym_versions;
    संरचना sym_संस्करणम् *sym_versions;
    पूर्णाङ्क nb_sym_गन्तव्यम्_संस्करणम्;
    पूर्णाङ्क *sym_गन्तव्यम्_संस्करणम्;
    पूर्णाङ्क dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#यदि_अन्तः

#यदि_परिभाषितम् TCC_IS_NATIVE
    ध्रुव वर्ण *सततम्_main; /* entry for tcc_run() */
    शून्य *सततम्_ptr; /* runtime_memory */
    अचिह्नित सततम्_आकार; /* size of runtime_memory  */
    ध्रुव वर्ण *सततम्_stdin; /* custom stdin file for run_main */
#यदि_परिभाषितम् _WIN64
    शून्य *सततम्_function_सारणी; /* unwind data */
#यदि_अन्तः
    संरचना TCCState *अग्र;
    संरचना rt_context *rc; /* pointer to backtrace info block */
    शून्य *सततम्_lj, *सततम्_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    शून्य *bt_दत्त;
#यदि_अन्तः

#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    पूर्णाङ्क rt_अङ्कः_callers;
#यदि_अन्तः

    /* benchmark info */
    पूर्णाङ्क योग_idents;
    पूर्णाङ्क योग_पङ्क्तयः;
    अचिह्नित पूर्णाङ्क योग_अष्टकानि;
    अचिह्नित पूर्णाङ्क योग_output[4];

    /* used by tcc_load_ldscript */
    अचिह्नित वर्ण *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ध्रुव वर्ण *current_filename;

    /* used by main and tcc_parse_args only */
    संरचना filespec **files; /* files seen on command line */
    पूर्णाङ्क nb_files; /* number thereof */
    पूर्णाङ्क nb_libraries; /* number of libs thereof */
    वर्ण *outfile; /* output filename */
    वर्ण *deps_outfile; /* option -MF */
    पूर्णाङ्क argc;
    वर्ण **argv;
    /* -Wl options */
    वर्ण **link_argv;
    पूर्णाङ्क link_argc, link_optind;
};

संरचना filespec {
    वर्ण type;
    वर्ण name[1];
};

/* The current value can be: */
#परिभाषय VT_VALMASK   0x003f  /* mask for value location, register or: */
#परिभाषय VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#परिभाषय VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#परिभाषय VT_LOCAL     0x0032  /* offset on stack */
#परिभाषय VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#परिभाषय VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#परिभाषय VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#परिभाषय VT_LVAL      0x0100  /* var is an lvalue */
#परिभाषय VT_SYM       0x0200  /* a symbol value is added */
#परिभाषय VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#परिभाषय VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#परिभाषय VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#परिभाषय VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#परिभाषय VT_BTYPE       0x000f  /* mask for basic type */
#परिभाषय VT_VOID             0  /* void type */
#परिभाषय VT_BYTE             1  /* signed byte type */
#परिभाषय VT_SHORT            2  /* short type */
#परिभाषय VT_INT              3  /* integer type */
#परिभाषय VT_LLONG            4  /* 64 bit integer */
#परिभाषय VT_PTR              5  /* pointer */
#परिभाषय VT_FUNC             6  /* function type */
#परिभाषय VT_STRUCT           7  /* struct/union definition */
#परिभाषय VT_FLOAT            8  /* IEEE float */
#परिभाषय VT_DOUBLE           9  /* IEEE double */
#परिभाषय VT_LDOUBLE         10  /* IEEE long double */
#परिभाषय VT_BOOL            11  /* ISOC99 boolean type */
#परिभाषय VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#परिभाषय VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#परिभाषय VT_UNSIGNED    0x0010  /* unsigned type */
#परिभाषय VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#परिभाषय VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#परिभाषय VT_BITFIELD    0x0080  /* bitfield modifier */
#परिभाषय VT_CONSTANT    0x0100  /* const modifier */
#परिभाषय VT_VOLATILE    0x0200  /* volatile modifier */
#परिभाषय VT_RESTRICT    0x0400  /* restrict modifier */
#परिभाषय VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#परिभाषय VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#परिभाषय VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#परिभाषय VT_EXTERN  0x00002000  /* extern definition */
#परिभाषय VT_STATIC  0x00004000  /* static variable */
#परिभाषय VT_TYPEDEF 0x00008000  /* typedef definition */
#परिभाषय VT_INLINE  0x00010000  /* inline definition */
#परिभाषय VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#परिभाषय VT_STRUCT_सरणम् 20     /* shift for bitfield shift values (32 - 2*6) */
#परिभाषय VT_STRUCT_आवरणम् (((1U << (6+6)) - 1) << VT_STRUCT_सरणम् | VT_BITFIELD)
#परिभाषय BIT_POS(t) (((t) >> VT_STRUCT_सरणम्) & 0x3f)
#परिभाषय BIT_आकार(t) (((t) >> (VT_STRUCT_सरणम् + 6)) & 0x3f)

#परिभाषय VT_UNION    (1 << VT_STRUCT_सरणम् | VT_STRUCT)
#परिभाषय VT_ENUM     (2 << VT_STRUCT_सरणम्) /* integral type is an enum really */
#परिभाषय VT_ENUM_VAL (3 << VT_STRUCT_सरणम्) /* integral type is an enum constant really */

#परिभाषय IS_ENUM(t) ((t & VT_STRUCT_आवरणम्) == VT_ENUM)
#परिभाषय IS_ENUM_VAL(t) ((t & VT_STRUCT_आवरणम्) == VT_ENUM_VAL)
#परिभाषय IS_UNION(t) ((t & (VT_STRUCT_आवरणम्|VT_BTYPE)) == VT_UNION)

#परिभाषय VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#परिभाषय VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#परिभाषय VT_TYPE (~(VT_STORAGE|VT_STRUCT_आवरणम्))

/* symbol was created by tccasm.c first */
#परिभाषय VT_ASM (VT_VOID | 4 << VT_STRUCT_सरणम्)
#परिभाषय VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_सरणम्)
#परिभाषय IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_आवरणम्) & ~(1<<VT_STRUCT_सरणम्))) == VT_ASM)
#परिभाषय IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_आवरणम्)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#परिभाषय VT_BT_ARRAY (6 << VT_STRUCT_सरणम्)
#परिभाषय IS_BT_ARRAY(t) ((t & VT_STRUCT_आवरणम्) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#परिभाषय BFVAL(M,N) ((अचिह्नित)((M) & ~((M) << 1)) * (N))
#परिभाषय BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#परिभाषय BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#परिभाषय TOK_LAND  0x90
#परिभाषय TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#परिभाषय TOK_ULT 0x92
#परिभाषय TOK_UGE 0x93
#परिभाषय TOK_EQ  0x94
#परिभाषय TOK_NE  0x95
#परिभाषय TOK_ULE 0x96
#परिभाषय TOK_UGT 0x97
#परिभाषय TOK_Nset 0x98
#परिभाषय TOK_Nclear 0x99
#परिभाषय TOK_LT  0x9c
#परिभाषय TOK_GE  0x9d
#परिभाषय TOK_LE  0x9e
#परिभाषय TOK_GT  0x9f

#परिभाषय TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#परिभाषय TOK_DEC     0x80 /* -- */
#परिभाषय TOK_MID     0x81 /* inc/dec, to void constant */
#परिभाषय TOK_INC     0x82 /* ++ */
#परिभाषय TOK_UDIV    0x83 /* unsigned division */
#परिभाषय TOK_UMOD    0x84 /* unsigned modulo */
#परिभाषय TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#परिभाषय TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#परिभाषय TOK_ADDC1   0x87 /* add with carry generation */
#परिभाषय TOK_ADDC2   0x88 /* add with carry use */
#परिभाषय TOK_SUBC1   0x89 /* add with carry generation */
#परिभाषय TOK_SUBC2   0x8a /* add with carry use */
#परिभाषय TOK_SHL     '<' /* shift left */
#परिभाषय TOK_SAR     '>' /* signed shift right */
#परिभाषय TOK_SHR     0x8b /* unsigned shift right */
#परिभाषय TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#परिभाषय TOK_ARROW   0xa0 /* -> */
#परिभाषय TOK_DOTS    0xa1 /* three dots */
#परिभाषय TOK_TWODOTS 0xa2 /* C++ token ? */
#परिभाषय TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#परिभाषय TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#परिभाषय TOK_PPJOIN  (TOK_TWOSHARPS | SYM_क्षेत्रम्) /* A '##' in a macro to mean pasting */
#परिभाषय TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#परिभाषय TOK_A_सङ्कलय   0xb0
#परिभाषय TOK_A_SUB   0xb1
#परिभाषय TOK_A_MUL   0xb2
#परिभाषय TOK_A_DIV   0xb3
#परिभाषय TOK_A_MOD   0xb4
#परिभाषय TOK_A_AND   0xb5
#परिभाषय TOK_A_OR    0xb6
#परिभाषय TOK_A_XOR   0xb7
#परिभाषय TOK_A_SHL   0xb8
#परिभाषय TOK_A_SAR   0xb9

#परिभाषय TOK_नियोजय(t) (t >= TOK_A_सङ्कलय && t <= TOK_A_SAR)
#परिभाषय TOK_नियोजय_OP(t) ("+-*/%&|^<>"[t - TOK_A_सङ्कलय])

/* tokens that carry values (in additional token string space / tokc) --> */
#परिभाषय TOK_CCHAR   0xc0 /* char constant in tokc */
#परिभाषय TOK_LCHAR   0xc1
#परिभाषय TOK_CINT    0xc2 /* number in tokc */
#परिभाषय TOK_CUINT   0xc3 /* unsigned int constant */
#परिभाषय TOK_CLLONG  0xc4 /* long long constant */
#परिभाषय TOK_CULLONG 0xc5 /* unsigned long long constant */
#परिभाषय TOK_CLONG   0xc6 /* long constant */
#परिभाषय TOK_CULONG  0xc7 /* unsigned long constant */
#परिभाषय TOK_STR     0xc8 /* pointer to string in tokc */
#परिभाषय TOK_LSTR    0xc9
#परिभाषय TOK_CFLOAT  0xca /* float constant */
#परिभाषय TOK_CDOUBLE 0xcb /* double constant */
#परिभाषय TOK_CLDOUBLE 0xcc /* long double constant */
#परिभाषय TOK_PPNUM   0xcd /* preprocessor number */
#परिभाषय TOK_PPSTR   0xce /* preprocessor string */
#परिभाषय TOK_LINENUM 0xcf /* line number info */

#परिभाषय TOK_HAS_मानम्(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#परिभाषय TOK_EOF       (-1)  /* end of file */
#परिभाषय TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#परिभाषय TOK_IDENT 256

गणना tcc_token {
    TOK_चरमः = TOK_IDENT - 1
#परिभाषय DEF(id, str) ,id
#अन्तर्भाव "tcctok.h"
#अपरिभाषय DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#परिभाषय TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_दत्त संरचना TCCState *tcc_state;
ST_दत्त शून्य** stk_दत्त;
ST_दत्त पूर्णाङ्क nb_stk_दत्त;
ST_दत्त पूर्णाङ्क g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC वर्ण *pstrcpy(वर्ण *buf, आकार_t buf_आकार, ध्रुव वर्ण *s);
ST_FUNC वर्ण *pstrcat(वर्ण *buf, आकार_t buf_आकार, ध्रुव वर्ण *s);
ST_FUNC वर्ण *pstrncpy(वर्ण *बहिर्गमनम्, आकार_t buf_आकार, ध्रुव वर्ण *s, आकार_t अङ्कः);
PUB_FUNC वर्ण *tcc_basename(ध्रुव वर्ण *name);
PUB_FUNC वर्ण *tcc_fileextension (ध्रुव वर्ण *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC शून्य tcc_free(शून्य *ptr);
PUB_FUNC शून्य *tcc_malloc(अचिह्नित दीर्घ आकार);
PUB_FUNC शून्य *tcc_mallocz(अचिह्नित दीर्घ आकार);
PUB_FUNC शून्य *tcc_realloc(शून्य *ptr, अचिह्नित दीर्घ आकार);
PUB_FUNC वर्ण *tcc_strdup(ध्रुव वर्ण *str);

#यदि_परिभाषितम् MEM_DEBUG
#परिभाषय tcc_free(ptr)           tcc_free_debug(ptr)
#परिभाषय tcc_malloc(आकार)        tcc_malloc_debug(आकार, __FILE__, __LINE__)
#परिभाषय tcc_mallocz(आकार)       tcc_mallocz_debug(आकार, __FILE__, __LINE__)
#परिभाषय tcc_realloc(ptr,आकार)   tcc_realloc_debug(ptr, आकार, __FILE__, __LINE__)
#परिभाषय tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC शून्य tcc_free_debug(शून्य *ptr);
PUB_FUNC शून्य *tcc_malloc_debug(अचिह्नित दीर्घ आकार, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः);
PUB_FUNC शून्य *tcc_mallocz_debug(अचिह्नित दीर्घ आकार, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः);
PUB_FUNC शून्य *tcc_realloc_debug(शून्य *ptr, अचिह्नित दीर्घ आकार, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः);
PUB_FUNC वर्ण *tcc_strdup_debug(ध्रुव वर्ण *str, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः);
#यदि_अन्तः

ST_FUNC शून्य libc_free(शून्य *ptr);
/* defined to be not used */
#परिभाषय मुक्त(p) use_tcc_free(p)
#परिभाषय स्मृतिं_देहि(s) use_tcc_malloc(s)
#परिभाषय realloc(p, s) use_tcc_realloc(p, s)
#अपरिभाषय strdup
#परिभाषय strdup(s) use_tcc_strdup(s)
PUB_FUNC पूर्णाङ्क _tcc_error_noabort(ध्रुव वर्ण *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN शून्य _tcc_error(ध्रुव वर्ण *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC शून्य _tcc_warning(ध्रुव वर्ण *fmt, ...) PRINTF_LIKE(1,2);
#परिभाषय tcc_आन्तरिकम्_error(सन्देशः) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,सन्देशः)

/* other utilities */
ST_FUNC शून्य dynarray_सङ्कलय(शून्य *ptab, पूर्णाङ्क *nb_ptr, शून्य *दत्त);
ST_FUNC शून्य dynarray_reset(शून्य *pp, पूर्णाङ्क *n);
ST_INLN शून्य cstr_ccat(CString *cstr, पूर्णाङ्क ch);
ST_FUNC शून्य cstr_cat(CString *cstr, ध्रुव वर्ण *str, पूर्णाङ्क len);
ST_FUNC शून्य cstr_wccat(CString *cstr, पूर्णाङ्क ch);
ST_FUNC शून्य cstr_new(CString *cstr);
ST_FUNC शून्य cstr_free(CString *cstr);
ST_FUNC पूर्णाङ्क cstr_printf(CString *cs, ध्रुव वर्ण *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC पूर्णाङ्क cstr_vprintf(CString *cstr, ध्रुव वर्ण *fmt, va_list ap);
ST_FUNC शून्य cstr_reset(CString *cstr);
ST_FUNC शून्य tcc_open_bf(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क initlen);
ST_FUNC पूर्णाङ्क tcc_open(TCCState *s1, ध्रुव वर्ण *filename);
ST_FUNC शून्य tcc_close(शून्य);

/* mark a memory pointer on stack for cleanup after errors */
#परिभाषय stk_प्रक्षिप(p) dynarray_सङ्कलय(&stk_दत्त, &nb_stk_दत्त, p)
#परिभाषय stk_निष्कासय() (--nb_stk_दत्त)
/* mark CString on stack for cleanup errors */
#परिभाषय cstr_new_s(cstr) (cstr_new(cstr), stk_प्रक्षिप(&(cstr)->दत्त))
#परिभाषय cstr_free_s(cstr) (cstr_free(cstr), stk_निष्कासय())

ST_FUNC पूर्णाङ्क tcc_सङ्कलय_file_आन्तरिकम्(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क flags);
/* flags: */
#परिभाषय AFF_PRINT_ERROR     0x10 /* print error if file not found */
#परिभाषय AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#परिभाषय AFF_TYPE_BIN        0x40 /* file to add is binary */
#परिभाषय AFF_सम्पूर्णम्_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#परिभाषय AFF_TYPE_NONE   0
#परिभाषय AFF_TYPE_C      1
#परिभाषय AFF_TYPE_ASM    2
#परिभाषय AFF_TYPE_ASMPP  4
#परिभाषय AFF_TYPE_LIB    8
#परिभाषय AFF_TYPE_आवरणम्   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#परिभाषय AFF_BINTYPE_REL 1
#परिभाषय AFF_BINTYPE_DYN 2
#परिभाषय AFF_BINTYPE_AR  3
#परिभाषय AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#परिभाषय FILE_NOT_प्राप्तम् -2
#परिभाषय FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
ST_FUNC पूर्णाङ्क tcc_सङ्कलय_crt(TCCState *s, ध्रुव वर्ण *filename);
#यदि_अन्तः
ST_FUNC पूर्णाङ्क tcc_सङ्कलय_dll(TCCState *s, ध्रुव वर्ण *filename, पूर्णाङ्क flags);
ST_FUNC पूर्णाङ्क tcc_सङ्कलय_support(TCCState *s1, ध्रुव वर्ण *filename);
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
ST_FUNC शून्य tcc_सङ्कलय_bcheck(TCCState *s1);
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
ST_FUNC शून्य tcc_सङ्कलय_btstub(TCCState *s1);
#यदि_अन्तः
ST_FUNC शून्य tcc_सङ्कलय_pragma_libs(TCCState *s1);
PUB_FUNC पूर्णाङ्क tcc_सङ्कलय_library_err(TCCState *s, ध्रुव वर्ण *f);
PUB_FUNC शून्य tcc_print_stats(TCCState *s, अचिह्नित योग_time);
PUB_FUNC पूर्णाङ्क tcc_parse_तर्काः(TCCState *s, पूर्णाङ्क *argc, वर्ण ***argv);
#यदि_परिभाषितम् _WIN32
ST_FUNC वर्ण *normalize_slashes(वर्ण *मार्गः);
PUB_FUNC FILE *tcc_fopen(ध्रुव वर्ण *f, ध्रुव वर्ण *m);
PUB_FUNC पूर्णाङ्क tcc_fclose(FILE *f);
#अन्यथा
# define tcc_fopen fopen
# define tcc_fclose fclose
#यदि_अन्तः
ST_FUNC DLLReference *tcc_सङ्कलय_dllref(TCCState *s1, ध्रुव वर्ण *dllname, पूर्णाङ्क level);
ST_FUNC वर्ण *tcc_आरोपय_text(पूर्णाङ्क fd);
/* for #pragma once */
ST_FUNC पूर्णाङ्क normalized_PATHCMP(ध्रुव वर्ण *f1, ध्रुव वर्ण *f2);

/* tcc_parse_args return codes: */
#परिभाषय OPT_HELP 1
#परिभाषय OPT_HELP2 2
#परिभाषय OPT_V 3
#परिभाषय OPT_PRINT_DIRS 4
#परिभाषय OPT_AR 5
#परिभाषय OPT_IMPDEF 6
#परिभाषय OPT_M32 32
#परिभाषय OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_दत्त संरचना BufferedFile *file;
ST_दत्त पूर्णाङ्क tok;
ST_दत्त CValue tokc;
ST_दत्त ध्रुव पूर्णाङ्क *macro_ptr;
ST_दत्त पूर्णाङ्क parse_flags;
ST_दत्त पूर्णाङ्क tok_flags;
ST_दत्त CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_दत्त पूर्णाङ्क tok_ident;
ST_दत्त TokenSym **सारणी_ident;
ST_दत्त पूर्णाङ्क pp_व्यञ्जकम्;

#परिभाषय TOK_FLAG_BOL   0x0001 /* beginning of line before */
#परिभाषय TOK_FLAG_BOF   0x0002 /* beginning of file before */
#परिभाषय TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#परिभाषय PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#परिभाषय PARSE_FLAG_TOK_अङ्कः    0x0002 /* return numbers instead of TOK_PPNUM */
#परिभाषय PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#परिभाषय PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#परिभाषय PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#परिभाषय PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#परिभाषय PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#परिभाषय IS_SPC 1
#परिभाषय IS_ID  2
#परिभाषय IS_अङ्कः 4

गणना पङ्क्तिः_macro_output_format {
    पङ्क्तिः_MACRO_OUTPUT_FORMAT_GCC,
    पङ्क्तिः_MACRO_OUTPUT_FORMAT_NONE,
    पङ्क्तिः_MACRO_OUTPUT_FORMAT_STD,
    पङ्क्तिः_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ध्रुव वर्ण *str, पूर्णाङ्क len);
ST_FUNC पूर्णाङ्क tok_alloc_const(ध्रुव वर्ण *str);
ST_FUNC ध्रुव वर्ण *get_tok_str(पूर्णाङ्क v, CValue *cv);
ST_FUNC शून्य begin_macro(TokenString *str, पूर्णाङ्क alloc);
ST_FUNC शून्य अन्तः_macro(शून्य);
ST_FUNC पूर्णाङ्क समुच्चयः_idnum(पूर्णाङ्क c, पूर्णाङ्क val);
ST_INLN शून्य tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(शून्य);
ST_FUNC शून्य tok_str_free(TokenString *s);
ST_FUNC शून्य tok_str_free_str(पूर्णाङ्क *str);
ST_FUNC शून्य tok_str_सङ्कलय(TokenString *s, पूर्णाङ्क t);
ST_FUNC शून्य tok_str_सङ्कलय_tok(TokenString *s);
ST_INLN शून्य define_प्रक्षिप(पूर्णाङ्क v, पूर्णाङ्क macro_type, पूर्णाङ्क *str, Sym *first_arg);
ST_FUNC शून्य define_undef(Sym *s);
ST_INLN Sym *define_find(पूर्णाङ्क v);
ST_FUNC शून्य free_परिभाषते(Sym *b);
ST_FUNC शून्य parse_define(शून्य);
ST_FUNC शून्य skip_गन्तव्यम्_eol(पूर्णाङ्क warn);
ST_FUNC शून्य preprocess(पूर्णाङ्क is_bof);
ST_FUNC शून्य अग्र(शून्य);
ST_INLN शून्य unget_tok(पूर्णाङ्क चरमः_tok);
ST_FUNC शून्य preprocess_start(TCCState *s1, पूर्णाङ्क filetype);
ST_FUNC शून्य preprocess_अन्तः(TCCState *s1);
ST_FUNC शून्य tccpp_new(TCCState *s);
ST_FUNC शून्य tccpp_delete(TCCState *s);
ST_FUNC शून्य tccpp_putfile(ध्रुव वर्ण *filename);
ST_FUNC पूर्णाङ्क tcc_preprocess(TCCState *s1);
ST_FUNC शून्य skip(पूर्णाङ्क c);
ST_FUNC NORETURN शून्य expect(ध्रुव वर्ण *सन्देशः);
ST_FUNC शून्य pp_error(CString *cs);


/* space excluding newline */
स्थिर अन्तःस्थ पूर्णाङ्क is_space(पूर्णाङ्क ch) {
    प्रत्यागम ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
स्थिर अन्तःस्थ पूर्णाङ्क isid(पूर्णाङ्क c) {
    प्रत्यागम (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
स्थिर अन्तःस्थ पूर्णाङ्क isnum(पूर्णाङ्क c) {
    प्रत्यागम c >= '0' && c <= '9';
}
स्थिर अन्तःस्थ पूर्णाङ्क isoct(पूर्णाङ्क c) {
    प्रत्यागम c >= '0' && c <= '7';
}
स्थिर अन्तःस्थ पूर्णाङ्क toup(पूर्णाङ्क c) {
    प्रत्यागम (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#परिभाषय SYM_POOL_NB (8192 / परिमाण(Sym))

ST_दत्त Sym *global_राशिः;
ST_दत्त Sym *local_राशिः;
ST_दत्त Sym *local_label_राशिः;
ST_दत्त Sym *global_label_राशिः;
ST_दत्त Sym *define_राशिः;
ST_दत्त CType int_type, func_old_type, char_pointer_type;
ST_दत्त SValue *vtop;
ST_दत्त पूर्णाङ्क rsym, anon_sym, ind, loc;
ST_दत्त वर्ण debug_modes;

ST_दत्त पूर्णाङ्क nocode_wanted; /* true if no code generation wanted for an expression */
ST_दत्त पूर्णाङ्क global_व्यञ्जकम्;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_दत्त CType func_vt; /* current function return type (used by return instruction) */
ST_दत्त पूर्णाङ्क func_var; /* true if current function is variadic */
ST_दत्त पूर्णाङ्क func_vc; /* stack address for implicit struct return storage */
ST_दत्त पूर्णाङ्क func_ind; /* function start address */
ST_दत्त ध्रुव वर्ण *funcname;

ST_FUNC शून्य tccgen_init(TCCState *s1);
ST_FUNC पूर्णाङ्क tccgen_compile(TCCState *s1);
ST_FUNC शून्य tccgen_finish(TCCState *s1);
ST_FUNC शून्य check_vstack(शून्य);

ST_INLN पूर्णाङ्क is_float(पूर्णाङ्क t);
ST_FUNC पूर्णाङ्क ieee_finite(द्विगुण d);
ST_FUNC पूर्णाङ्क exact_log2p1(पूर्णाङ्क i);
ST_FUNC शून्य test_lvalue(शून्य);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC शून्य update_storage(Sym *sym);
ST_FUNC शून्य put_extern_sym2(Sym *sym, पूर्णाङ्क sh_अङ्कः, addr_t मानम्, अचिह्नित दीर्घ आकार, पूर्णाङ्क can_सङ्कलय_underscore);
ST_FUNC शून्य put_extern_sym(Sym *sym, Section *section, addr_t मानम्, अचिह्नित दीर्घ आकार);
#यदि PTR_आकार == 4
ST_FUNC शून्य greloc(Section *s, Sym *sym, अचिह्नित दीर्घ विस्थापनम्, पूर्णाङ्क type);
#यदि_अन्तः
ST_FUNC शून्य greloca(Section *s, Sym *sym, अचिह्नित दीर्घ विस्थापनम्, पूर्णाङ्क type, addr_t addend);

ST_INLN शून्य sym_free(Sym *sym);
ST_FUNC Sym *sym_प्रक्षिप(पूर्णाङ्क v, CType *type, पूर्णाङ्क r, पूर्णाङ्क c);
ST_FUNC शून्य sym_निष्कासय(Sym **ptop, Sym *b, पूर्णाङ्क keep);
ST_FUNC Sym *sym_push2(Sym **ps, पूर्णाङ्क v, पूर्णाङ्क t, पूर्णाङ्क c);
ST_FUNC Sym *sym_find2(Sym *s, पूर्णाङ्क v);
ST_INLN Sym *sym_find(पूर्णाङ्क v);
ST_FUNC Sym *label_find(पूर्णाङ्क v);
ST_FUNC Sym *label_प्रक्षिप(Sym **ptop, पूर्णाङ्क v, पूर्णाङ्क flags);
ST_FUNC शून्य label_निष्कासय(Sym **ptop, Sym *slast, पूर्णाङ्क keep);
ST_INLN Sym *struct_find(पूर्णाङ्क v);

ST_FUNC Sym *global_identifier_प्रक्षिप(पूर्णाङ्क v, पूर्णाङ्क t, पूर्णाङ्क c);
ST_FUNC Sym *external_global_sym(पूर्णाङ्क v, CType *type);
ST_FUNC Sym *external_helper_sym(पूर्णाङ्क v);
ST_FUNC शून्य vpush_helper_func(पूर्णाङ्क v);
ST_FUNC शून्य vset(CType *type, पूर्णाङ्क r, पूर्णाङ्क v);
ST_FUNC शून्य vset_VT_CMP(पूर्णाङ्क op);
ST_FUNC शून्य vpushi(पूर्णाङ्क v);
ST_FUNC शून्य vpushv(SValue *v);
ST_FUNC शून्य vpushsym(CType *type, Sym *sym);
ST_FUNC शून्य vswap(शून्य);
ST_FUNC शून्य vrott(पूर्णाङ्क n);
ST_FUNC शून्य vrotb(पूर्णाङ्क n);
ST_FUNC शून्य vrev(पूर्णाङ्क n);
ST_FUNC शून्य vpop(शून्य);
#यदि PTR_आकार == 4
ST_FUNC शून्य lexpand(शून्य);
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_ARM
ST_FUNC पूर्णाङ्क get_reg_ex(पूर्णाङ्क rc, पूर्णाङ्क rc2);
#यदि_अन्तः
ST_FUNC शून्य save_reg(पूर्णाङ्क r);
ST_FUNC शून्य save_reg_upstack(पूर्णाङ्क r, पूर्णाङ्क n);
ST_FUNC पूर्णाङ्क get_reg(पूर्णाङ्क rc);
ST_FUNC शून्य save_regs(पूर्णाङ्क n);
ST_FUNC शून्य gaddrof(शून्य);
ST_FUNC पूर्णाङ्क gv(पूर्णाङ्क rc);
ST_FUNC शून्य gv2(पूर्णाङ्क rc1, पूर्णाङ्क rc2);
ST_FUNC शून्य gen_op(पूर्णाङ्क op);
ST_FUNC पूर्णाङ्क type_आकार(CType *type, पूर्णाङ्क *a);
ST_FUNC शून्य mk_pointer(CType *type);
ST_FUNC शून्य vstore(शून्य);
ST_FUNC शून्य inc(पूर्णाङ्क post, पूर्णाङ्क c);
ST_FUNC CString* parse_mult_str(ध्रुव वर्ण *सन्देशः);
ST_FUNC CString* parse_asm_str(शून्य);
ST_FUNC शून्य indir(शून्य);
ST_FUNC शून्य unary(शून्य);
ST_FUNC शून्य gexpr(शून्य);
ST_FUNC पूर्णाङ्क व्यञ्जकम्_const(शून्य);
#यदि defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, अचिह्नित दीर्घ विस्थापनम्, अचिह्नित दीर्घ आकार);
#यदि_अन्तः
#यदि defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC पूर्णाङ्क classify_x86_64_va_arg(CType *ty);
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
ST_FUNC शून्य gbound_तर्काः(पूर्णाङ्क nb_तर्काः);
ST_दत्त पूर्णाङ्क func_bound_सङ्कलय_epilog;
#यदि_अन्तः
ST_FUNC Sym *gfunc_समुच्चयः_param(Sym *s, पूर्णाङ्क c, पूर्णाङ्क byref);

/* ------------ tccelf.c ------------ */

#परिभाषय TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#परिभाषय TCC_OUTPUT_FORMAT_द्विमान 1 /* binary image output */
#परिभाषय TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#परिभाषय TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#परिभाषय ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

प्रकारनिर्देश संरचना {
    अचिह्नित पूर्णाङ्क n_strx;         /* index into string table of name */
    अचिह्नित वर्ण n_type;         /* type of symbol */
    अचिह्नित वर्ण n_other;        /* misc info (usually empty) */
    अचिह्नित ह्रस्व n_desc;        /* description field */
    अचिह्नित पूर्णाङ्क n_मानम्;        /* value of symbol */
} Stab_Sym;

ST_FUNC शून्य tccelf_new(TCCState *s);
ST_FUNC शून्य tccelf_delete(TCCState *s);
ST_FUNC शून्य tccelf_begin_file(TCCState *s1);
ST_FUNC शून्य tccelf_अन्तः_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ध्रुव वर्ण *name, पूर्णाङ्क sh_type, पूर्णाङ्क sh_flags);
ST_FUNC शून्य section_realloc(Section *sec, अचिह्नित दीर्घ new_आकार);
ST_FUNC आकार_t section_सङ्कलय(Section *sec, addr_t आकार, पूर्णाङ्क align);
ST_FUNC शून्य *section_ptr_सङ्कलय(Section *sec, addr_t आकार);
ST_FUNC Section *find_section(TCCState *s1, ध्रुव वर्ण *name);
ST_FUNC शून्य free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ध्रुव वर्ण *symtab_name, पूर्णाङ्क sh_type, पूर्णाङ्क sh_flags, ध्रुव वर्ण *strtab_name, ध्रुव वर्ण *hash_name, पूर्णाङ्क hash_sh_flags);
ST_FUNC शून्य init_symtab(Section *s);

ST_FUNC पूर्णाङ्क put_elf_str(Section *s, ध्रुव वर्ण *sym);
ST_FUNC पूर्णाङ्क put_elf_sym(Section *s, addr_t मानम्, अचिह्नित दीर्घ आकार, पूर्णाङ्क info, पूर्णाङ्क other, पूर्णाङ्क shndx, ध्रुव वर्ण *name);
ST_FUNC पूर्णाङ्क समुच्चयः_elf_sym(Section *s, addr_t मानम्, अचिह्नित दीर्घ आकार, पूर्णाङ्क info, पूर्णाङ्क other, पूर्णाङ्क shndx, ध्रुव वर्ण *name);
ST_FUNC पूर्णाङ्क find_elf_sym(Section *s, ध्रुव वर्ण *name);
ST_FUNC शून्य put_elf_reloc(Section *symtab, Section *s, अचिह्नित दीर्घ विस्थापनम्, पूर्णाङ्क type, पूर्णाङ्क चिह्नम्);
ST_FUNC शून्य put_elf_reloca(Section *symtab, Section *s, अचिह्नित दीर्घ विस्थापनम्, पूर्णाङ्क type, पूर्णाङ्क चिह्नम्, addr_t addend);

ST_FUNC शून्य resolve_common_syms(TCCState *s1);
ST_FUNC शून्य relocate_syms(TCCState *s1, Section *symtab, पूर्णाङ्क do_resolve);
ST_FUNC शून्य relocate_sections(TCCState *s1);

ST_FUNC ssize_t पूर्णम्_read(पूर्णाङ्क fd, शून्य *buf, आकार_t गणनम्_2);
ST_FUNC शून्य *आरोपय_दत्त(पूर्णाङ्क fd, अचिह्नित दीर्घ file_विस्थापनम्, अचिह्नित दीर्घ आकार);
ST_FUNC पूर्णाङ्क tcc_object_type(पूर्णाङ्क fd, ElfW(Ehdr) *h);
ST_FUNC पूर्णाङ्क tcc_आरोपय_object_file(TCCState *s1, पूर्णाङ्क fd, अचिह्नित दीर्घ file_विस्थापनम्);
ST_FUNC पूर्णाङ्क tcc_आरोपय_archive(TCCState *s1, पूर्णाङ्क fd, पूर्णाङ्क alacarte);
ST_FUNC शून्य सङ्कलय_array(TCCState *s1, ध्रुव वर्ण *sec, पूर्णाङ्क c);

ST_FUNC संरचना sym_attr *get_sym_attr(TCCState *s1, पूर्णाङ्क सूचकांक, पूर्णाङ्क alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ध्रुव वर्ण *name, पूर्णाङ्क err, पूर्णाङ्क forc);
ST_FUNC शून्य list_elf_symbols(TCCState *s, शून्य *ctx,
    शून्य (*चिह्नम्_cb)(शून्य *ctx, ध्रुव वर्ण *name, ध्रुव शून्य *val));
ST_FUNC पूर्णाङ्क समुच्चयः_global_sym(TCCState *s1, ध्रुव वर्ण *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#परिभाषय for_each_elem(sec, startoff, elem, type) \
    प्रति (elem = (type *) sec->दत्त + startoff; \
         elem < (type *) (sec->दत्त + sec->दत्त_विस्थापनम्); elem++)

#यदि_अपरिभाषितम् ELF_OBJ_ONLY
ST_FUNC पूर्णाङ्क tcc_आरोपय_dll(TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename, पूर्णाङ्क level);
ST_FUNC पूर्णाङ्क tcc_आरोपय_ldscript(TCCState *s1, पूर्णाङ्क fd);
ST_FUNC शून्य tccelf_सङ्कलय_crtbegin(TCCState *s1);
ST_FUNC शून्य tccelf_सङ्कलय_crtend(TCCState *s1);
#यदि_अन्तः
#यदि_अपरिभाषितम् TCC_TARGET_PE
ST_FUNC शून्य tcc_सङ्कलय_runtime(TCCState *s1);
#यदि_अन्तः

/* ------------ xxx-link.c ------------ */

#यदि_अपरिभाषितम् TCC_TARGET_PE
ST_FUNC पूर्णाङ्क संहिता_reloc (पूर्णाङ्क reloc_type);
ST_FUNC पूर्णाङ्क gotplt_प्रविष्टिः_type (पूर्णाङ्क reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
गणना gotplt_प्रविष्टिः {
    NO_GOTPLT_प्रविष्टिः,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_प्रविष्टिः,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_प्रविष्टिः	/* always generate (eg. PLTOFF relocs) */
};
#परिभाषय NEED_RELOC_TYPE
#यदि !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC अचिह्नित create_plt_प्रविष्टिः(TCCState *s1, अचिह्नित got_विस्थापनम्, संरचना sym_attr *attr);
ST_FUNC शून्य relocate_plt(TCCState *s1);
ST_FUNC शून्य build_got_entries(TCCState *s1, पूर्णाङ्क got_sym); /* in tccelf.c */
#परिभाषय NEED_BUILD_GOT
#यदि_अन्तः
#यदि_अन्तः

ST_FUNC शून्य relocate(TCCState *s1, ElfW_Rel *rel, पूर्णाङ्क type, अचिह्नित वर्ण *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_दत्त ध्रुव वर्ण * ध्रुव target_machine_defs;
ST_दत्त ध्रुव पूर्णाङ्क reg_classes[NB_REGS];

ST_FUNC शून्य gsym_addr(पूर्णाङ्क t, पूर्णाङ्क a);
ST_FUNC शून्य gsym(पूर्णाङ्क t);
ST_FUNC शून्य आरोपय(पूर्णाङ्क r, SValue *sv);
ST_FUNC शून्य store(पूर्णाङ्क r, SValue *v);
ST_FUNC पूर्णाङ्क gfunc_sret(CType *vt, पूर्णाङ्क variadic, CType *ret, पूर्णाङ्क *align, पूर्णाङ्क *regsize);
ST_FUNC शून्य gfunc_call(पूर्णाङ्क nb_तर्काः);
ST_FUNC शून्य gfunc_prolog(Sym *func_sym);
ST_FUNC शून्य gfunc_epilog(शून्य);
ST_FUNC शून्य gen_fill_nops(पूर्णाङ्क);
ST_FUNC पूर्णाङ्क gjmp(पूर्णाङ्क t);
ST_FUNC शून्य gjmp_addr(पूर्णाङ्क a);
ST_FUNC पूर्णाङ्क gjmp_cond(पूर्णाङ्क op, पूर्णाङ्क t);
ST_FUNC पूर्णाङ्क gjmp_append(पूर्णाङ्क n, पूर्णाङ्क t);
ST_FUNC शून्य gen_opi(पूर्णाङ्क op);
ST_FUNC शून्य gen_opf(पूर्णाङ्क op);
ST_FUNC शून्य gen_cvt_ftoi(पूर्णाङ्क t);
ST_FUNC शून्य gen_cvt_itof(पूर्णाङ्क t);
ST_FUNC शून्य gen_cvt_ftof(पूर्णाङ्क t);
ST_FUNC शून्य ggoto(शून्य);
#यदि_अपरिभाषितम् TCC_TARGET_C67
ST_FUNC शून्य o(अचिह्नित पूर्णाङ्क c);
#यदि_अन्तः
ST_FUNC शून्य gen_vla_sp_save(पूर्णाङ्क addr);
ST_FUNC शून्य gen_vla_sp_restore(पूर्णाङ्क addr);
ST_FUNC शून्य gen_vla_alloc(CType *type, पूर्णाङ्क align);

स्थिर अन्तःस्थ uint16_t read16le(अचिह्नित वर्ण *p) {
    प्रत्यागम p[0] | (uint16_t)p[1] << 8;
}
स्थिर अन्तःस्थ शून्य write16le(अचिह्नित वर्ण *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
स्थिर अन्तःस्थ uint32_t read32le(अचिह्नित वर्ण *p) {
  प्रत्यागम read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
स्थिर अन्तःस्थ शून्य write32le(अचिह्नित वर्ण *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
स्थिर अन्तःस्थ शून्य add32le(अचिह्नित वर्ण *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
स्थिर अन्तःस्थ uint64_t read64le(अचिह्नित वर्ण *p) {
  प्रत्यागम read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
स्थिर अन्तःस्थ शून्य write64le(अचिह्नित वर्ण *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
स्थिर अन्तःस्थ शून्य add64le(अचिह्नित वर्ण *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#यदि defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC शून्य g(पूर्णाङ्क c);
ST_FUNC शून्य gen_le16(पूर्णाङ्क c);
ST_FUNC शून्य gen_le32(पूर्णाङ्क c);
#यदि_अन्तः
#यदि defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC शून्य gen_addr32(पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c);
ST_FUNC शून्य gen_addrpc32(पूर्णाङ्क r, Sym *sym, पूर्णाङ्क c);
ST_FUNC शून्य gen_cvt_csti(पूर्णाङ्क t);
ST_FUNC शून्य gen_increment_tcov (SValue *sv);
#यदि_अन्तः

/* ------------ x86_64-gen.c ------------ */
#यदि_परिभाषितम् TCC_TARGET_X86_64
ST_FUNC शून्य gen_opl(पूर्णाङ्क op);
#यदि_परिभाषितम् TCC_TARGET_PE
ST_FUNC शून्य gen_vla_परिणाम(पूर्णाङ्क addr);
#यदि_अन्तः
ST_FUNC शून्य gen_cvt_sxtw(शून्य);
ST_FUNC शून्य gen_cvt_csti(पूर्णाङ्क t);
#यदि_अन्तः

/* ------------ arm-gen.c ------------ */
#यदि_परिभाषितम् TCC_TARGET_ARM
#यदि defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ध्रुव वर्ण *default_elfinterp(संरचना TCCState *s);
#यदि_अन्तः
ST_FUNC शून्य arm_init(संरचना TCCState *s);
ST_FUNC शून्य gen_increment_tcov (SValue *sv);
#यदि_अन्तः

/* ------------ arm64-gen.c ------------ */
#यदि_परिभाषितम् TCC_TARGET_ARM64
ST_FUNC शून्य gen_opl(पूर्णाङ्क op);
ST_FUNC शून्य gfunc_return(CType *func_type);
ST_FUNC शून्य gen_va_start(शून्य);
ST_FUNC शून्य gen_va_arg(CType *t);
ST_FUNC शून्य gen_clear_cache(शून्य);
ST_FUNC शून्य gen_cvt_sxtw(शून्य);
ST_FUNC शून्य gen_cvt_csti(पूर्णाङ्क t);
ST_FUNC शून्य gen_increment_tcov (SValue *sv);
#यदि_अन्तः

/* ------------ riscv64-gen.c ------------ */
#यदि_परिभाषितम् TCC_TARGET_RISCV64
ST_FUNC शून्य gen_opl(पूर्णाङ्क op);
ST_FUNC शून्य gen_va_start(शून्य);
ST_FUNC शून्य arch_transfer_ret_regs(पूर्णाङ्क);
ST_FUNC शून्य gen_cvt_sxtw(शून्य);
ST_FUNC शून्य gen_cvt_csti(पूर्णाङ्क t);
ST_FUNC शून्य gen_increment_tcov (SValue *sv);
ST_FUNC शून्य gen_clear_cache(शून्य);
#यदि_अन्तः

/* ------------ c67-gen.c ------------ */
#यदि_परिभाषितम् TCC_TARGET_C67
#यदि_अन्तः

/* ------------ tcccoff.c ------------ */
#यदि_परिभाषितम् TCC_TARGET_COFF
ST_FUNC पूर्णाङ्क tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC पूर्णाङ्क tcc_आरोपय_coff(TCCState * s1, पूर्णाङ्क fd);
#यदि_अन्तः

/* ------------ tccasm.c ------------ */
ST_FUNC शून्य asm_instr(शून्य);
ST_FUNC शून्य asm_global_instr(शून्य);
ST_FUNC पूर्णाङ्क tcc_assemble(TCCState *s1, पूर्णाङ्क do_preprocess);
#यदि_परिभाषितम् CONFIG_TCC_ASM
ST_FUNC पूर्णाङ्क find_constraint(ASMOperand *operands, पूर्णाङ्क nb_operands, ध्रुव वर्ण *name, ध्रुव वर्ण **pp);
ST_FUNC Sym* get_asm_sym(पूर्णाङ्क name, Sym *csym);
ST_FUNC शून्य asm_व्यञ्जकम्(TCCState *s1, व्यञ्जकम्_मानम् *pe);
ST_FUNC पूर्णाङ्क asm_int_व्यञ्जकम्(TCCState *s1);
#यदि PTR_आकार == 8
ST_FUNC शून्य gen_expr64(व्यञ्जकम्_मानम् *pe);
#यदि_अन्तः
/* ------------ i386-asm.c ------------ */
ST_FUNC शून्य gen_expr32(व्यञ्जकम्_मानम् *pe);
ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क opcode);
ST_FUNC पूर्णाङ्क asm_parse_regvar(पूर्णाङ्क t);
ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands, पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs, ध्रुव uint8_t *clobber_regs, पूर्णाङ्क *pout_reg);
ST_FUNC शून्य subst_asm_सङ्कार्यम्(CString *सङ्कलय_str, SValue *sv, पूर्णाङ्क modifier);
ST_FUNC शून्य asm_gen_संहिता(ASMOperand *operands, पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output, uint8_t *clobber_regs, पूर्णाङ्क बहिर्गमनम्_reg);
ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, ध्रुव वर्ण *str);
#यदि_अन्तः

/* ------------ tccpe.c -------------- */
#यदि_परिभाषितम् TCC_TARGET_PE
ST_FUNC पूर्णाङ्क pe_आरोपय_file(संरचना TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename);
ST_FUNC पूर्णाङ्क pe_output_file(TCCState * s1, ध्रुव वर्ण *filename);
ST_FUNC पूर्णाङ्क pe_putimport(TCCState *s1, पूर्णाङ्क dllindex, ध्रुव वर्ण *name, addr_t मानम्);
ST_FUNC पूर्णाङ्क pe_setsubsy(TCCState *s1, ध्रुव वर्ण *arg);
#यदि defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#यदि_अन्तः
#यदि defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC शून्य pe_सङ्कलय_unwind_दत्त(अचिह्नित start, अचिह्नित अन्तः, अचिह्नित राशिः);
#यदि_अन्तः
PUB_FUNC पूर्णाङ्क tcc_get_dllexports(ध्रुव वर्ण *filename, वर्ण **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#यदि_अन्तः
#परिभाषय ST_ASM_समुच्चयः 0x04

/* ------------ tccmacho.c ----------------- */
#यदि_परिभाषितम् TCC_TARGET_MACHO
ST_FUNC पूर्णाङ्क macho_output_file(TCCState * s1, ध्रुव वर्ण *filename);
ST_FUNC पूर्णाङ्क macho_आरोपय_dll(TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename, पूर्णाङ्क lev);
ST_FUNC पूर्णाङ्क macho_आरोपय_tbd(TCCState *s1, पूर्णाङ्क fd, ध्रुव वर्ण *filename, पूर्णाङ्क lev);
#यदि_परिभाषितम् TCC_IS_NATIVE
ST_FUNC शून्य tcc_सङ्कलय_macos_sdkpath(TCCState* s);
ST_FUNC वर्ण* macho_tbd_soname(पूर्णाङ्क fd);
#यदि_अन्तः
#यदि_अन्तः
/* ------------ tccrun.c ----------------- */
#यदि_परिभाषितम् TCC_IS_NATIVE
#यदि_परिभाषितम् CONFIG_TCC_STATIC
#परिभाषय RTLD_LAZY       0x001
#परिभाषय RTLD_NOW        0x002
#परिभाषय RTLD_GLOBAL     0x100
#परिभाषय RTLD_DEFAULT    रिक्त
/* dummy function for profiling */
ST_FUNC शून्य *dlopen(ध्रुव वर्ण *filename, पूर्णाङ्क flag);
ST_FUNC शून्य dlclose(शून्य *p);
ST_FUNC ध्रुव वर्ण *dlerror(शून्य);
ST_FUNC शून्य *dlsym(शून्य *handle, ध्रुव वर्ण *चिह्नम्);
#यदि_अन्तः
ST_FUNC शून्य tcc_सततम्_free(TCCState *s1);
#यदि_अन्तः

/* ------------ tcctools.c ----------------- */
#यदि 0 /* included in tcc.c */
ST_FUNC पूर्णाङ्क tcc_tool_ar(TCCState *s, पूर्णाङ्क argc, वर्ण **argv);
#यदि_परिभाषितम् TCC_TARGET_PE
ST_FUNC पूर्णाङ्क tcc_tool_impdef(TCCState *s, पूर्णाङ्क argc, वर्ण **argv);
#यदि_अन्तः
ST_FUNC पूर्णाङ्क tcc_tool_cross(TCCState *s, वर्ण **argv, पूर्णाङ्क option);
ST_FUNC पूर्णाङ्क gen_makedeps(TCCState *s, ध्रुव वर्ण *target, ध्रुव वर्ण *filename);
#यदि_अन्तः

/* ------------ tccdbg.c ------------ */

ST_FUNC शून्य tcc_debug_new(TCCState *s);

ST_FUNC शून्य tcc_debug_start(TCCState *s1);
ST_FUNC शून्य tcc_debug_अन्तः(TCCState *s1);
ST_FUNC शून्य tcc_debug_bincl(TCCState *s1);
ST_FUNC शून्य tcc_debug_eincl(TCCState *s1);
ST_FUNC शून्य tcc_debug_newfile(TCCState *s1);

ST_FUNC शून्य tcc_debug_पङ्क्तिः(TCCState *s1);
ST_FUNC शून्य tcc_सङ्कलय_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC शून्य tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC शून्य tcc_debug_prolog_epilog(TCCState *s1, पूर्णाङ्क मानम्);
ST_FUNC शून्य tcc_debug_funcend(TCCState *s1, पूर्णाङ्क आकार);
ST_FUNC शून्य tcc_debug_extern_sym(TCCState *s1, Sym *sym, पूर्णाङ्क sh_अङ्कः, पूर्णाङ्क sym_bind, पूर्णाङ्क sym_type);
ST_FUNC शून्य tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC शून्य tcc_debug_stabn(TCCState *s1, पूर्णाङ्क type, पूर्णाङ्क मानम्);
ST_FUNC शून्य tcc_debug_fix_forw(TCCState *s1, CType *t);

#यदि !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC शून्य tcc_eh_frame_start(TCCState *s1);
ST_FUNC शून्य tcc_eh_frame_अन्तः(TCCState *s1);
ST_FUNC शून्य tcc_eh_frame_hdr(TCCState *s1, पूर्णाङ्क final);
#परिभाषय TCC_EH_FRAME 1
#यदि_अन्तः

ST_FUNC शून्य tcc_tcov_start(TCCState *s1);
ST_FUNC शून्य tcc_tcov_अन्तः(TCCState *s1);
ST_FUNC शून्य tcc_tcov_check_पङ्क्तिः(TCCState *s1, पूर्णाङ्क start);
ST_FUNC शून्य tcc_tcov_खण्डम्_अन्तः(TCCState *s1, पूर्णाङ्क पङ्क्तिः);
ST_FUNC शून्य tcc_tcov_खण्डम्_begin(TCCState *s1);
ST_FUNC शून्य tcc_tcov_reset_ind(TCCState *s1);

#परिभाषय stab_section            s1->stab_section
#परिभाषय stabstr_section         stab_section->link
#परिभाषय tcov_section            s1->tcov_section
#परिभाषय eh_frame_section        s1->eh_frame_section
#परिभाषय eh_frame_hdr_section    s1->eh_frame_hdr_section
#परिभाषय dwarf_info_section      s1->dwarf_info_section
#परिभाषय dwarf_abbrev_section    s1->dwarf_abbrev_section
#परिभाषय dwarf_पङ्क्तिः_section      s1->dwarf_पङ्क्तिः_section
#परिभाषय dwarf_aranges_section   s1->dwarf_aranges_section
#परिभाषय dwarf_str_section       s1->dwarf_str_section
#परिभाषय dwarf_पङ्क्तिः_str_section  s1->dwarf_पङ्क्तिः_str_section

#परिभाषय DWARF_MAX_128	((8 * परिमाण (int64_t) + 6) / 7)
#परिभाषय	dwarf_read_1(ln,अन्तः) \
	((ln) < (अन्तः) ? *(ln)++ : 0)
#परिभाषय	dwarf_read_2(ln,अन्तः) \
	((ln) + 1 < (अन्तः) ? read16le(((ln)+=2) - 2) : 0)
#परिभाषय	dwarf_read_4(ln,अन्तः) \
	((ln) + 3 < (अन्तः) ? read32le(((ln)+=4) - 4) : 0)
#परिभाषय	dwarf_read_8(ln,अन्तः) \
	((ln) + 7 < (अन्तः) ? read64le(((ln)+=8) - 8) : 0)
स्थिर अन्तःस्थ uint64_t
dwarf_read_uleb128(अचिह्नित वर्ण **ln, अचिह्नित वर्ण *अन्तः)
{
    अचिह्नित वर्ण *cp = *ln;
    uint64_t retval = 0;
    पूर्णाङ्क i;
    प्रति (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, अन्तः);
        retval |= (byte & 0x7f) << (i * 7);
	यदि ((byte & 0x80) == 0)
	    भङ्ग;
    }
    *ln = cp;
    प्रत्यागम retval;
}
स्थिर अन्तःस्थ int64_t
dwarf_read_sleb128(अचिह्नित वर्ण **ln, अचिह्नित वर्ण *अन्तः)
{
    अचिह्नित वर्ण *cp = *ln;
    int64_t retval = 0;
    पूर्णाङ्क i;
    प्रति (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, अन्तः);
        retval |= (byte & 0x7f) << (i * 7);
	यदि ((byte & 0x80) == 0) {
	    यदि ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    भङ्ग;
	}
    }
    *ln = cp;
    प्रत्यागम retval;
}

/* default dwarf version for "-gdwarf" */
#यदि_परिभाषितम् TCC_TARGET_MACHO
# define DEFAULT_DWARF_संस्करणम् 2
#अन्यथा
# define DEFAULT_DWARF_संस्करणम् 5
#यदि_अन्तः

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#यदि_अपरिभाषितम् CONFIG_DWARF_संस्करणम्
# define CONFIG_DWARF_संस्करणम् 0
#यदि_अन्तः

#यदि defined TCC_TARGET_X86_64
# define R_दत्त_32_DW R_X86_64_32
#अन्यथा
# define R_दत्त_32_DW R_दत्त_32
#यदि_अन्तः

/********************************************************/
#यदि CONFIG_TCC_SEMLOCK
#यदि defined _WIN32
प्रकारनिर्देश संरचना { चञ्चल LONG init; CRITICAL_SECTION cs; } TCCSem;
स्थिर अन्तःस्थ शून्य wait_sem(TCCSem *p) {
    यदि (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } अन्यथा {
        यावत् (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
स्थिर अन्तःस्थ शून्य post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#नोचेद्यदि defined __APPLE__
#अन्तर्भाव <dispatch/dispatch.h>
प्रकारनिर्देश संरचना { पूर्णाङ्क init; dispatch_semaphore_t sem; } TCCSem;
स्थिर अन्तःस्थ शून्य wait_sem(TCCSem *p) {
    यदि (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
स्थिर अन्तःस्थ शून्य post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#अन्यथा
#अन्तर्भाव <semaphore.h>
प्रकारनिर्देश संरचना { पूर्णाङ्क init; sem_t sem; } TCCSem;
स्थिर अन्तःस्थ शून्य wait_sem(TCCSem *p) {
    यदि (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    यावत् (sem_wait(&p->sem) < 0 && errno == EINTR);
}
स्थिर अन्तःस्थ शून्य post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#यदि_अन्तः
#परिभाषय TCC_SEM(s) TCCSem s
#परिभाषय WAIT_SEM wait_sem
#परिभाषय POST_SEM post_sem
#अन्यथा
#परिभाषय TCC_SEM(s)
#परिभाषय WAIT_SEM(p)
#परिभाषय POST_SEM(p)
#यदि_अन्तः

/********************************************************/
#अपरिभाषय ST_दत्त
#यदि ONE_SOURCE
#परिभाषय ST_दत्त स्थिर
#अन्यथा
#परिभाषय ST_दत्त
#यदि_अन्तः
/********************************************************/

#परिभाषय text_section        TCC_STATE_VAR(text_section)
#परिभाषय दत्त_section        TCC_STATE_VAR(दत्त_section)
#परिभाषय rodata_section      TCC_STATE_VAR(rodata_section)
#परिभाषय bss_section         TCC_STATE_VAR(bss_section)
#परिभाषय common_section      TCC_STATE_VAR(common_section)
#परिभाषय cur_text_section    TCC_STATE_VAR(cur_text_section)
#परिभाषय bounds_section      TCC_STATE_VAR(bounds_section)
#परिभाषय lbounds_section     TCC_STATE_VAR(lbounds_section)
#परिभाषय symtab_section      TCC_STATE_VAR(symtab_section)
#परिभाषय gnu_ext             TCC_STATE_VAR(gnu_ext)
#परिभाषय tcc_error_noabort   TCC_समुच्चयः_STATE(_tcc_error_noabort)
#परिभाषय tcc_error           TCC_समुच्चयः_STATE(_tcc_error)
#परिभाषय tcc_warning         TCC_समुच्चयः_STATE(_tcc_warning)

#परिभाषय योग_idents        TCC_STATE_VAR(योग_idents)
#परिभाषय योग_पङ्क्तयः         TCC_STATE_VAR(योग_पङ्क्तयः)
#परिभाषय योग_अष्टकानि         TCC_STATE_VAR(योग_अष्टकानि)

PUB_FUNC शून्य tcc_enter_state(TCCState *s1);
PUB_FUNC शून्य tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#परिभाषय tcc_warning_c(sw) TCC_समुच्चयः_STATE((\
    tcc_state->warn_अङ्कः = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#यदि_अन्तः /* _TCC_H */

#अपरिभाषय TCC_STATE_VAR
#अपरिभाषय TCC_समुच्चयः_STATE

#यदि_परिभाषितम् USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_समुच्चयः_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#अन्यथा
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_समुच्चयः_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#यदि_अन्तः
