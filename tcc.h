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
#அந்தர்பாவ "config.h"

#அந்தர்பாவ <stdarg.h>
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ifdef __TINYC__
# undef __attribute__
#endif
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <errno.h>
#அந்தர்பாவ <math.h>
#அந்தர்பாவ <fcntl.h>
#அந்தர்பாவ <setjmp.h>
#அந்தர்பாவ <time.h>

#ifndef _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
வெளி தசம strtof (மாறிலி எழுத்து *__nptr, எழுத்து **__endptr);
வெளி long இரட்டை strtold (மாறிலி எழுத்து *__nptr, எழுத்து **__endptr);
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
# define உள்வரி __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (long இரட்டை)strtod
#  define strtof (தசம)strtod
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
# எனில் defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#endif

#ifndef O_இருமம்_2
# define O_இருமம்_2 0
#endif

#ifndef offsetof
#ifdef __clang__ // clang -fsanitize compains about: NULL+value
#define offsetof(type, field) __builtin_offsetof(type, field)
#இல்லையெனில்
#define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif
#endif

#ifndef countof
#define countof(tab) (அளவு(tab) / அளவு((tab)[0]))
#endif

#ifdef _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#இல்லையெனில்
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (printf, (x), (y))))
#endif

#ifdef _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#இல்லையெனில்
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
#எனில் !defined(TCC_TARGET_I386) && !defined(TCC_TARGET_ARM) && \
    !defined(TCC_TARGET_ARM64) && !defined(TCC_TARGET_C67) && \
    !defined(TCC_TARGET_X86_64) && !defined(TCC_TARGET_RISCV64)
# எனில் defined __x86_64__
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
# இல்லையெனில்
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
#எனில் defined _WIN32 == defined TCC_TARGET_PE \
    && defined __APPLE__ == defined TCC_TARGET_MACHO
# எனில் defined __i386__ && defined TCC_TARGET_I386
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

#எனில் defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#இல்லையெனில்
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#endif

#எனில் defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#இல்லையெனில்
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#endif

#எனில் defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#இல்லையெனில்
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#endif

#எனில் defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#அல்லதெனில் !(defined TCC_TARGET_PE || defined TCC_TARGET_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#endif

#எனில் defined TCC_TARGET_PE || defined TCC_TARGET_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#இல்லையெனில்
# define TCC_TARGET_UNIX 1
#endif

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#எனில் defined TCC_TARGET_PE \
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

#எனில் !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif

#ifdef CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#இல்லையெனில்
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
# எனில் defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# இல்லையெனில்
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#endif

/* library search paths */
#ifndef CONFIG_TCC_LIBPATHS
# எனில் defined TCC_TARGET_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# இல்லையெனில்
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#endif

/* name of ELF interpreter */
#ifndef CONFIG_TCC_ELFINTERP
# எனில் defined __GNU__
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
# இல்லையெனில்
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

#அந்தர்பாவ "libtcc.h"
#அந்தர்பாவ "elf.h"
#அந்தர்பாவ "stab.h"
#அந்தர்பாவ "dwarf.h"

/* -------------------------------------------- */

#ifndef PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#endif

#ifndef ONE_SOURCE
# define ONE_SOURCE 0
#endif

#எனில் ONE_SOURCE
#define ST_INLN நிலையான உள்வரி
#define ST_FUNC நிலையான
#define ST_DATA நிலையான
#இல்லையெனில்
#define ST_INLN
#define ST_FUNC
#define ST_DATA வெளி
#endif

#ifdef TCC_PROFILE /* profile all functions */
# define நிலையான
# define உள்வரி
#endif

/* -------------------------------------------- */
/* include the target specific definitions */

#define TARGET_DEFS_ONLY
#ifdef TCC_TARGET_I386
# include "i386-gen.c"
# include "i386-link.c"
#அல்லதெனில் defined TCC_TARGET_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#அல்லதெனில் defined TCC_TARGET_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#அல்லதெனில் defined TCC_TARGET_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#அல்லதெனில் defined TCC_TARGET_C67
# define TCC_TARGET_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#அல்லதெனில் defined(TCC_TARGET_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#இல்லையெனில்
#error unknown target
#endif
#undef TARGET_DEFS_ONLY

/* -------------------------------------------- */

#எனில் PTR_SIZE == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#இல்லையெனில்
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

#எனில் PTR_SIZE == 8 && !defined TCC_TARGET_PE
# define LONG_SIZE 8
#இல்லையெனில்
# define LONG_SIZE 4
#endif

/* -------------------------------------------- */

#define INCLUDE_அடுக்கு_SIZE  32
#define IFDEF_அடுக்கு_SIZE    64
#define VSTACK_SIZE         512
#define STRING_MAX_SIZE     1024
#define TOKSTR_MAX_SIZE     256
#define PACK_அடுக்கு_SIZE     8

#define TOK_HASH_SIZE       16384 /* must be a power of two */
#define TOK_ALLOC_INCR      512  /* must be a power of two */
#define TOK_MAX_SIZE        4 /* token max size in int unit when stored in string */

/* token symbol management */
வகைவரை கட்டமைப்பு TokenSym {
    கட்டமைப்பு TokenSym *hash_next;
    கட்டமைப்பு Sym *sym_define; /* direct pointer to define */
    கட்டமைப்பு Sym *sym_label; /* direct pointer to label */
    கட்டமைப்பு Sym *sym_struct; /* direct pointer to structure */
    கட்டமைப்பு Sym *sym_identifier; /* direct pointer to identifier */
    முழு tok; /* token number */
    முழு len;
    எழுத்து str[1];
} TokenSym;

#ifdef TCC_TARGET_PE
வகைவரை unsigned short nwchar_t;
#இல்லையெனில்
வகைவரை முழு nwchar_t;
#endif

வகைவரை கட்டமைப்பு CString {
    முழு size; /* size in bytes */
    முழு size_allocated;
    எழுத்து *data; /* nwchar_t* in cases */
} CString;

/* type definition */
வகைவரை கட்டமைப்பு CType {
    முழு t;
    கட்டமைப்பு Sym *ref;
} CType;

/* long double words on host(!) platform */
#define LDOUBLE_சொற்கள் ((அளவு(long இரட்டை)+3)/4)

/* constant value */
வகைவரை ஒன்றிப்பு CValue {
    long இரட்டை ld;
    இரட்டை d;
    தசம f;
    uint64_t i;
    கட்டமைப்பு {
        எழுத்து *data;
        முழு size;
    } str;
    முழு tab[LDOUBLE_சொற்கள்];
} CValue;

/* value on stack */
வகைவரை கட்டமைப்பு SValue {
    CType type;      /* type */
    unsigned short r;      /* register + flags */
    unsigned short r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    ஒன்றிப்பு {
      கட்டமைப்பு { முழு jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    ஒன்றிப்பு {
      கட்டமைப்பு { unsigned short cmp_op, cmp_r; }; /* VT_CMP operation */
      கட்டமைப்பு Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
கட்டமைப்பு SymAttr {
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
கட்டமைப்பு FuncAttr {
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
வகைவரை கட்டமைப்பு Sym {
    முழு v; /* symbol token */
    unsigned short r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    கட்டமைப்பு SymAttr a; /* symbol attributes */
    ஒன்றிப்பு {
        கட்டமைப்பு {
            முழு c; /* associated number or Elf symbol index */
            ஒன்றிப்பு {
                முழு sym_scope; /* scope level for locals */
                முழு jnext; /* next jump label */
                முழு jind; /* label position */
                கட்டமைப்பு FuncAttr f; /* function attributes */
                முழு auxtype; /* bitfield access type */
            };
        };
        long long enum_val; /* enum constant if IS_ENUM_VAL */
        முழு *d; /* define token stream */
        கட்டமைப்பு Sym *cleanup_func;
    };

    CType type; /* associated type */
    ஒன்றிப்பு {
        கட்டமைப்பு Sym *next; /* next related symbol (for fields and anoms) */
        முழு *e; /* expanded token stream with preprocessor macros */
        முழு asm_label; /* associated asm label */
        கட்டமைப்பு Sym *cleanupstate; /* in defined labels */
        முழு *vla_array_str; /* vla array code */
    };
    கட்டமைப்பு Sym *prev; /* prev symbol in stack */
    ஒன்றிப்பு {
        கட்டமைப்பு Sym *prev_tok; /* previous symbol for this token */
        கட்டமைப்பு Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        கட்டமைப்பு Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
வகைவரை கட்டமைப்பு Section {
    unsigned long data_offset; /* current data offset */
    unsigned எழுத்து *data;       /* section data */
    unsigned long data_allocated; /* used for realloc() handling */
    TCCState *s1;
    முழு sh_name;             /* elf section name (only used during output) */
    முழு sh_இலக்கம்;              /* elf section number */
    முழு sh_type;             /* elf section type */
    முழு sh_flags;            /* elf section flags */
    முழு sh_info;             /* elf section info */
    முழு sh_addralign;        /* elf section alignment */
    முழு sh_entsize;          /* elf entry size */
    unsigned long sh_size;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    unsigned long sh_offset; /* file offset */
    முழு nb_hashed_syms;      /* used to resize the hash table */
    கட்டமைப்பு Section *link;    /* link to another section */
    கட்டமைப்பு Section *reloc;   /* corresponding section for relocation, if any */
    கட்டமைப்பு Section *hash;    /* hash table for symbols */
    கட்டமைப்பு Section *prev;    /* previous section on section stack */
    எழுத்து name[1];           /* section name */
} Section;

வகைவரை கட்டமைப்பு DLLReference {
    முழு level;
    வெறுமை *handle;
    unsigned எழுத்து found, index;
    எழுத்து name[1];
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

வகைவரை கட்டமைப்பு BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    முழு fd;
    கட்டமைப்பு BufferedFile *prev;
    முழு வரி_இலக்கம்;    /* current line number - here to simplify code */
    முழு வரி_ref;    /* tcc -E: last printed line */
    முழு ifndef_macro;  /* #ifndef macro / #endif search */
    முழு ifndef_macro_saved; /* saved ifndef_macro */
    முழு *ifdef_அடுக்கு_ptr; /* ifdef_stack value at the start of the file */
    முழு include_next_index; /* next search path */
    முழு prev_tok_flags; /* saved tok_flags */
    எழுத்து filename[1024];    /* filename */
    எழுத்து *true_filename; /* filename not modified by # line directive */
    unsigned எழுத்து unget[4];
    unsigned எழுத்து buffer[1]; /* extra size for CH_EOB char */
} BufferedFile;

#define CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#define CH_EOF   (-1)   /* end of file */

/* used to record tokens */
வகைவரை கட்டமைப்பு TokenString {
    முழு *str;
    முழு len;
    முழு need_spc;
    முழு allocated_len;
    முழு last_வரி_இலக்கம்;
    முழு save_வரி_இலக்கம்;
    /* used to chain token-strings with begin/end_macro() */
    கட்டமைப்பு TokenString *prev;
    மாறிலி முழு *prev_ptr;
    எழுத்து alloc;
} TokenString;

/* GNUC attribute definition */
வகைவரை கட்டமைப்பு AttributeDef {
    கட்டமைப்பு SymAttr a;
    கட்டமைப்பு FuncAttr f;
    கட்டமைப்பு Section *section;
    Sym *cleanup_func;
    முழு alias_target; /* token */
    முழு asm_label; /* associated asm label */
    எழுத்து attr_mode; /* __attribute__((__mode__(...))) */
    எழுத்து new_section; /* section is new */
} AttributeDef;

/* inline functions */
வகைவரை கட்டமைப்பு InlineFunc {
    TokenString *func_str;
    Sym *sym;
    எழுத்து filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
வகைவரை கட்டமைப்பு CachedInclude {
    முழு ifndef_macro;
    முழு once;
    முழு hash_next; /* -1 if none */
    எழுத்து filename[1]; /* path specified in #include */
} CachedInclude;

#define CACHED_INCLUDES_HASH_SIZE 32

#ifdef CONFIG_TCC_ASM
வகைவரை கட்டமைப்பு கோவை_மதிப்பு {
    uint64_t v;
    Sym *sym;
    முழு pcrel;
} கோவை_மதிப்பு;

#define MAX_ASM_OPERANDS 30
வகைவரை கட்டமைப்பு ASMOperand {
    முழு id; /* GCC 3 optional identifier (0 if number only supported) */
    எழுத்து constraint[16];
    எழுத்து asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    முழு ref_index; /* if >= 0, gives reference to a output constraint */
    முழு உள்ளீடு_index; /* if >= 0, gives reference to an input constraint */
    முழு priority; /* priority, used to assign registers */
    முழு reg; /* if >= 0, register number used for this operand */
    முழு is_llong; /* true if double register value */
    முழு is_memory; /* true if memory operand */
    முழு is_rw;     /* for '+' modifier */
    முழு is_label;  /* for asm goto */
} ASMOperand;
#endif

/* extra symbol attributes (not in symbol table) */
கட்டமைப்பு sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    முழு plt_sym;
    முழு dyn_index;
    unsigned எழுத்து linker_sym:1;
#ifdef TCC_TARGET_ARM
    unsigned எழுத்து plt_thumb_stub:1;
#endif
};

கட்டமைப்பு TCCState {
    unsigned எழுத்து verbose; /* if true, display some information during compilation */
    unsigned எழுத்து nostdinc; /* if true, no standard headers are added */
    unsigned எழுத்து nostdlib; /* if true, no standard libraries are added */
    unsigned எழுத்து nostdlib_paths; /* if true, the default paths are not searched for libraries */
    unsigned எழுத்து nocommon; /* if true, do not use common symbols for .bss data */
    unsigned எழுத்து static_link; /* if true, static linking is performed */
    unsigned எழுத்து rdynamic; /* if true, all symbols are exported */
    unsigned எழுத்து symbolic; /* if true, resolve symbols in the current module first */
    unsigned எழுத்து znodelete; /* Set DF_1_NODELETE in dynamic section */
    unsigned எழுத்து filetype; /* file type for compilation (NONE,C,ASM) */
    unsigned எழுத்து optimize; /* only to #define __OPTIMIZE__ */
    unsigned எழுத்து option_pthread; /* -pthread option */
    unsigned எழுத்து enable_new_dtags; /* -Wl,--enable-new-dtags */
    unsigned முழு  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    unsigned எழுத்து char_is_unsigned;
    unsigned எழுத்து leading_underscore;
    unsigned எழுத்து ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    unsigned எழுத்து dollars_in_identifiers;  /* allows '$' char in identifiers */
    unsigned எழுத்து ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    unsigned எழுத்து reverse_funcargs; /* if true, evaluate last function arg first */
    unsigned எழுத்து gnu89_inline; /* treat 'extern inline' like 'static inline' */
    unsigned எழுத்து unwind_tables; /* create eh_frame section */

    /* warning switches */
    unsigned எழுத்து warn_none;
    unsigned எழுத்து warn_all;
    unsigned எழுத்து warn_error;
    unsigned எழுத்து warn_write_strings;
    unsigned எழுத்து warn_unsupported;
    unsigned எழுத்து warn_implicit_function_declaration;
    unsigned எழுத்து warn_discarded_qualifiers;
    #define WARN_ON  1 /* warning is on (-Woption) */
    unsigned எழுத்து warn_இலக்கம்; /* temp var for tcc_warning_c() */

    unsigned எழுத்து option_r; /* option -r */
    unsigned எழுத்து do_bench; /* option -bench */
    unsigned எழுத்து just_deps; /* option -M  */
    unsigned எழுத்து gen_deps; /* option -MD  */
    unsigned எழுத்து include_sys_deps; /* option -MD  */
    unsigned எழுத்து gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    unsigned எழுத்து do_debug;
    unsigned எழுத்து dwarf;
    unsigned எழுத்து do_backtrace;
#ifdef CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    unsigned எழுத்து do_bounds_check;
#endif
    unsigned எழுத்து test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    unsigned எழுத்து gnu_ext;
    /* use TinyCC extensions */
    unsigned எழுத்து tcc_ext;

    unsigned எழுத்து dflag; /* -dX value */
    unsigned எழுத்து Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ifdef TCC_TARGET_X86_64
    unsigned எழுத்து nosse; /* For -mno-sse support. */
#endif
#ifdef TCC_TARGET_ARM
    unsigned எழுத்து float_abi; /* float ABI of the generated code*/
#endif

    unsigned எழுத்து has_text_addr;
    addr_t text_addr; /* address of text section */
    unsigned section_align; /* section alignment */
#ifdef TCC_TARGET_I386
    முழு seg_size; /* 32. Can be 16 with i386 assembler (.code16) */
#endif

    எழுத்து *tcc_lib_path; /* CONFIG_TCCDIR or -B option */
    எழுத்து *soname; /* as specified on the command line (-soname) */
    எழுத்து *rpath; /* as specified on the command line (-Wl,-rpath=) */
    எழுத்து *elfint; /* -Wl,-I... on command line */
    எழுத்து *elf_entryname; /* "_start" unless set */
    எழுத்து *init_குறியீடு; /* symbols to call at load-time (not used currently) */
    எழுத்து *fini_குறியீடு; /* symbols to call at unload-time (not used currently) */
    எழுத்து *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    முழு output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    முழு output_format;
    /* nth test to run with -dt -run */
    முழு run_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    முழு nb_loaded_dlls;

    /* include paths */
    எழுத்து **include_paths;
    முழு nb_include_paths;

    எழுத்து **sysinclude_paths;
    முழு nb_sysinclude_paths;

    /* library paths */
    எழுத்து **library_paths;
    முழு nb_library_paths;

    /* crt?.o object path */
    எழுத்து **crt_paths;
    முழு nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    வெறுமை *error_opaque;
    வெறுமை (*error_func)(வெறுமை *opaque, மாறிலி எழுத்து *செய்தி);
    முழு error_set_jmp_enabled;
    jmp_buf error_jmp_buf;
    முழு nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    எழுத்து **target_deps;
    முழு nb_target_deps;

    /* compilation */
    BufferedFile *include_அடுக்கு[INCLUDE_அடுக்கு_SIZE];
    BufferedFile **include_அடுக்கு_ptr;

    முழு ifdef_அடுக்கு[IFDEF_அடுக்கு_SIZE];
    முழு *ifdef_அடுக்கு_ptr;

    /* included files enclosed with #ifndef MACRO */
    முழு cached_includes_hash[CACHED_INCLUDES_HASH_SIZE];
    CachedInclude **cached_includes;
    முழு nb_cached_includes;

    /* #pragma pack stack */
    முழு pack_அடுக்கு[PACK_அடுக்கு_SIZE];
    முழு *pack_அடுக்கு_ptr;
    எழுத்து **pragma_libs;
    முழு nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    கட்டமைப்பு InlineFunc **inline_fns;
    முழு nb_inline_fns;

    /* sections */
    Section **sections;
    முழு nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    முழு nb_priv_sections; /* number of private sections */

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
    ஒன்றிப்பு { Section *symtab_section, *symtab; }; /* historical alias */
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
    Section *dwarf_வரி_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_வரி_str_section;
    முழு dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    கட்டமைப்பு _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    கட்டமைப்பு sym_attr *sym_attrs;
    முழு nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #define qrel s1->qrel

    addr_t tls_start, tls_end;

#ifdef TCC_TARGET_RISCV64
    கட்டமைப்பு pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    முழு nb_pcrel_hi_entries;
#endif

#ifdef TCC_TARGET_PE
    /* PE info */
    முழு pe_subsystem;
    unsigned pe_characteristics;
    unsigned pe_dll_characteristics;
    unsigned pe_file_align;
    unsigned pe_அடுக்கு_size;
    addr_t pe_imagebase;
# எனில் defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
    Section *uw_pdata;
    முழு uw_sym;
    முழு uw_xsym;
    unsigned uw_offs;
# endif
#endif

#எனில் defined TCC_TARGET_MACHO
    எழுத்து *install_name;
    uint32_t compatibility_version;
    uint32_t current_version;
#endif

#ifndef ELF_OBJ_ONLY
    முழு nb_sym_versions;
    கட்டமைப்பு sym_version *sym_versions;
    முழு nb_sym_to_version;
    முழு *sym_to_version;
    முழு dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#endif

#ifdef TCC_IS_NATIVE
    மாறிலி எழுத்து *run_main; /* entry for tcc_run() */
    வெறுமை *run_ptr; /* runtime_memory */
    unsigned run_size; /* size of runtime_memory  */
    மாறிலி எழுத்து *run_stdin; /* custom stdin file for run_main */
#ifdef _WIN64
    வெறுமை *run_function_table; /* unwind data */
#endif
    கட்டமைப்பு TCCState *next;
    கட்டமைப்பு rt_context *rc; /* pointer to backtrace info block */
    வெறுமை *run_lj, *run_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    வெறுமை *bt_data;
#endif

#ifdef CONFIG_TCC_BACKTRACE
    முழு rt_இலக்கம்_callers;
#endif

    /* benchmark info */
    முழு total_idents;
    முழு total_வரிகள்;
    unsigned முழு total_bytes;
    unsigned முழு total_output[4];

    /* used by tcc_load_ldscript */
    unsigned எழுத்து *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    மாறிலி எழுத்து *current_filename;

    /* used by main and tcc_parse_args only */
    கட்டமைப்பு filespec **files; /* files seen on command line */
    முழு nb_files; /* number thereof */
    முழு nb_libraries; /* number of libs thereof */
    எழுத்து *outfile; /* output filename */
    எழுத்து *deps_outfile; /* option -MF */
    முழு argc;
    எழுத்து **argv;
    /* -Wl options */
    எழுத்து **link_argv;
    முழு link_argc, link_optind;
};

கட்டமைப்பு filespec {
    எழுத்து type;
    எழுத்து name[1];
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

#define TOK_HAS_மதிப்பு(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#define TOK_EOF       (-1)  /* end of file */
#define TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#define TOK_IDENT 256

எண்ணிக்கை tcc_token {
    TOK_LAST = TOK_IDENT - 1
#define DEF(id, str) ,id
#அந்தர்பாவ "tcctok.h"
#undef DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#define TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_DATA கட்டமைப்பு TCCState *tcc_state;
ST_DATA வெறுமை** stk_data;
ST_DATA முழு nb_stk_data;
ST_DATA முழு g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC எழுத்து *pstrcpy(எழுத்து *buf, size_t buf_size, மாறிலி எழுத்து *s);
ST_FUNC எழுத்து *pstrcat(எழுத்து *buf, size_t buf_size, மாறிலி எழுத்து *s);
ST_FUNC எழுத்து *pstrncpy(எழுத்து *out, size_t buf_size, மாறிலி எழுத்து *s, size_t இலக்கம்);
PUB_FUNC எழுத்து *tcc_basename(மாறிலி எழுத்து *name);
PUB_FUNC எழுத்து *tcc_fileextension (மாறிலி எழுத்து *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC வெறுமை tcc_free(வெறுமை *ptr);
PUB_FUNC வெறுமை *tcc_malloc(unsigned long size);
PUB_FUNC வெறுமை *tcc_mallocz(unsigned long size);
PUB_FUNC வெறுமை *tcc_realloc(வெறுமை *ptr, unsigned long size);
PUB_FUNC எழுத்து *tcc_strdup(மாறிலி எழுத்து *str);

#ifdef MEM_DEBUG
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC வெறுமை tcc_free_debug(வெறுமை *ptr);
PUB_FUNC வெறுமை *tcc_malloc_debug(unsigned long size, மாறிலி எழுத்து *file, முழு வரி);
PUB_FUNC வெறுமை *tcc_mallocz_debug(unsigned long size, மாறிலி எழுத்து *file, முழு வரி);
PUB_FUNC வெறுமை *tcc_realloc_debug(வெறுமை *ptr, unsigned long size, மாறிலி எழுத்து *file, முழு வரி);
PUB_FUNC எழுத்து *tcc_strdup_debug(மாறிலி எழுத்து *str, மாறிலி எழுத்து *file, முழு வரி);
#endif

ST_FUNC வெறுமை libc_free(வெறுமை *ptr);
/* defined to be not used */
#define விடுவி(p) use_tcc_free(p)
#define malloc(s) use_tcc_malloc(s)
#define realloc(p, s) use_tcc_realloc(p, s)
#undef strdup
#define strdup(s) use_tcc_strdup(s)
PUB_FUNC முழு _tcc_error_noabort(மாறிலி எழுத்து *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN வெறுமை _tcc_error(மாறிலி எழுத்து *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC வெறுமை _tcc_warning(மாறிலி எழுத்து *fmt, ...) PRINTF_LIKE(1,2);
#define tcc_internal_error(செய்தி) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,செய்தி)

/* other utilities */
ST_FUNC வெறுமை dynarray_add(வெறுமை *ptab, முழு *nb_ptr, வெறுமை *data);
ST_FUNC வெறுமை dynarray_reset(வெறுமை *pp, முழு *n);
ST_INLN வெறுமை cstr_ccat(CString *cstr, முழு ch);
ST_FUNC வெறுமை cstr_cat(CString *cstr, மாறிலி எழுத்து *str, முழு len);
ST_FUNC வெறுமை cstr_wccat(CString *cstr, முழு ch);
ST_FUNC வெறுமை cstr_new(CString *cstr);
ST_FUNC வெறுமை cstr_free(CString *cstr);
ST_FUNC முழு cstr_printf(CString *cs, மாறிலி எழுத்து *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC முழு cstr_vprintf(CString *cstr, மாறிலி எழுத்து *fmt, va_list ap);
ST_FUNC வெறுமை cstr_reset(CString *cstr);
ST_FUNC வெறுமை tcc_open_bf(TCCState *s1, மாறிலி எழுத்து *filename, முழு initlen);
ST_FUNC முழு tcc_open(TCCState *s1, மாறிலி எழுத்து *filename);
ST_FUNC வெறுமை tcc_close(வெறுமை);

/* mark a memory pointer on stack for cleanup after errors */
#define stk_தள்ளு(p) dynarray_add(&stk_data, &nb_stk_data, p)
#define stk_எடு() (--nb_stk_data)
/* mark CString on stack for cleanup errors */
#define cstr_new_s(cstr) (cstr_new(cstr), stk_தள்ளு(&(cstr)->data))
#define cstr_free_s(cstr) (cstr_free(cstr), stk_எடு())

ST_FUNC முழு tcc_add_file_internal(TCCState *s1, மாறிலி எழுத்து *filename, முழு flags);
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
ST_FUNC முழு tcc_add_crt(TCCState *s, மாறிலி எழுத்து *filename);
#endif
ST_FUNC முழு tcc_add_dll(TCCState *s, மாறிலி எழுத்து *filename, முழு flags);
ST_FUNC முழு tcc_add_support(TCCState *s1, மாறிலி எழுத்து *filename);
#ifdef CONFIG_TCC_BCHECK
ST_FUNC வெறுமை tcc_add_bcheck(TCCState *s1);
#endif
#ifdef CONFIG_TCC_BACKTRACE
ST_FUNC வெறுமை tcc_add_btstub(TCCState *s1);
#endif
ST_FUNC வெறுமை tcc_add_pragma_libs(TCCState *s1);
PUB_FUNC முழு tcc_add_library_err(TCCState *s, மாறிலி எழுத்து *f);
PUB_FUNC வெறுமை tcc_print_stats(TCCState *s, unsigned total_time);
PUB_FUNC முழு tcc_parse_args(TCCState *s, முழு *argc, எழுத்து ***argv);
#ifdef _WIN32
ST_FUNC எழுத்து *normalize_slashes(எழுத்து *path);
PUB_FUNC FILE *tcc_fopen(மாறிலி எழுத்து *f, மாறிலி எழுத்து *m);
PUB_FUNC முழு tcc_fclose(FILE *f);
#இல்லையெனில்
# define tcc_fopen fopen
# define tcc_fclose fclose
#endif
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, மாறிலி எழுத்து *dllname, முழு level);
ST_FUNC எழுத்து *tcc_load_text(முழு fd);
/* for #pragma once */
ST_FUNC முழு normalized_PATHCMP(மாறிலி எழுத்து *f1, மாறிலி எழுத்து *f2);

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

ST_DATA கட்டமைப்பு BufferedFile *file;
ST_DATA முழு tok;
ST_DATA CValue tokc;
ST_DATA மாறிலி முழு *macro_ptr;
ST_DATA முழு parse_flags;
ST_DATA முழு tok_flags;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA முழு tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA முழு pp_கோவை;

#define TOK_FLAG_BOL   0x0001 /* beginning of line before */
#define TOK_FLAG_BOF   0x0002 /* beginning of file before */
#define TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#define PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#define PARSE_FLAG_TOK_இலக்கம்    0x0002 /* return numbers instead of TOK_PPNUM */
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
#define IS_இலக்கம் 4

எண்ணிக்கை வரி_macro_output_format {
    வரி_MACRO_OUTPUT_FORMAT_GCC,
    வரி_MACRO_OUTPUT_FORMAT_NONE,
    வரி_MACRO_OUTPUT_FORMAT_STD,
    வரி_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(மாறிலி எழுத்து *str, முழு len);
ST_FUNC முழு tok_alloc_const(மாறிலி எழுத்து *str);
ST_FUNC மாறிலி எழுத்து *get_tok_str(முழு v, CValue *cv);
ST_FUNC வெறுமை begin_macro(TokenString *str, முழு alloc);
ST_FUNC வெறுமை end_macro(வெறுமை);
ST_FUNC முழு set_idnum(முழு c, முழு val);
ST_INLN வெறுமை tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(வெறுமை);
ST_FUNC வெறுமை tok_str_free(TokenString *s);
ST_FUNC வெறுமை tok_str_free_str(முழு *str);
ST_FUNC வெறுமை tok_str_add(TokenString *s, முழு t);
ST_FUNC வெறுமை tok_str_add_tok(TokenString *s);
ST_INLN வெறுமை define_தள்ளு(முழு v, முழு macro_type, முழு *str, Sym *first_arg);
ST_FUNC வெறுமை define_undef(Sym *s);
ST_INLN Sym *define_find(முழு v);
ST_FUNC வெறுமை free_defines(Sym *b);
ST_FUNC வெறுமை parse_define(வெறுமை);
ST_FUNC வெறுமை skip_to_eol(முழு warn);
ST_FUNC வெறுமை preprocess(முழு is_bof);
ST_FUNC வெறுமை next(வெறுமை);
ST_INLN வெறுமை unget_tok(முழு last_tok);
ST_FUNC வெறுமை preprocess_start(TCCState *s1, முழு filetype);
ST_FUNC வெறுமை preprocess_end(TCCState *s1);
ST_FUNC வெறுமை tccpp_new(TCCState *s);
ST_FUNC வெறுமை tccpp_delete(TCCState *s);
ST_FUNC வெறுமை tccpp_putfile(மாறிலி எழுத்து *filename);
ST_FUNC முழு tcc_preprocess(TCCState *s1);
ST_FUNC வெறுமை skip(முழு c);
ST_FUNC NORETURN வெறுமை expect(மாறிலி எழுத்து *செய்தி);
ST_FUNC வெறுமை pp_error(CString *cs);


/* space excluding newline */
நிலையான உள்வரி முழு is_space(முழு ch) {
    திரும்பு ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
நிலையான உள்வரி முழு isid(முழு c) {
    திரும்பு (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
நிலையான உள்வரி முழு isnum(முழு c) {
    திரும்பு c >= '0' && c <= '9';
}
நிலையான உள்வரி முழு isoct(முழு c) {
    திரும்பு c >= '0' && c <= '7';
}
நிலையான உள்வரி முழு toup(முழு c) {
    திரும்பு (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#define SYM_POOL_NB (8192 / அளவு(Sym))

ST_DATA Sym *global_அடுக்கு;
ST_DATA Sym *local_அடுக்கு;
ST_DATA Sym *local_label_அடுக்கு;
ST_DATA Sym *global_label_அடுக்கு;
ST_DATA Sym *define_அடுக்கு;
ST_DATA CType int_type, func_old_type, char_pointer_type;
ST_DATA SValue *vtop;
ST_DATA முழு rsym, anon_sym, ind, loc;
ST_DATA எழுத்து debug_modes;

ST_DATA முழு nocode_wanted; /* true if no code generation wanted for an expression */
ST_DATA முழு global_கோவை;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_DATA CType func_vt; /* current function return type (used by return instruction) */
ST_DATA முழு func_var; /* true if current function is variadic */
ST_DATA முழு func_vc; /* stack address for implicit struct return storage */
ST_DATA முழு func_ind; /* function start address */
ST_DATA மாறிலி எழுத்து *funcname;

ST_FUNC வெறுமை tccgen_init(TCCState *s1);
ST_FUNC முழு tccgen_compile(TCCState *s1);
ST_FUNC வெறுமை tccgen_finish(TCCState *s1);
ST_FUNC வெறுமை check_vstack(வெறுமை);

ST_INLN முழு is_float(முழு t);
ST_FUNC முழு ieee_finite(இரட்டை d);
ST_FUNC முழு exact_log2p1(முழு i);
ST_FUNC வெறுமை test_lvalue(வெறுமை);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC வெறுமை update_storage(Sym *sym);
ST_FUNC வெறுமை put_extern_sym2(Sym *sym, முழு sh_இலக்கம், addr_t மதிப்பு, unsigned long size, முழு can_add_underscore);
ST_FUNC வெறுமை put_extern_sym(Sym *sym, Section *section, addr_t மதிப்பு, unsigned long size);
#எனில் PTR_SIZE == 4
ST_FUNC வெறுமை greloc(Section *s, Sym *sym, unsigned long offset, முழு type);
#endif
ST_FUNC வெறுமை greloca(Section *s, Sym *sym, unsigned long offset, முழு type, addr_t addend);

ST_INLN வெறுமை sym_free(Sym *sym);
ST_FUNC Sym *sym_தள்ளு(முழு v, CType *type, முழு r, முழு c);
ST_FUNC வெறுமை sym_எடு(Sym **ptop, Sym *b, முழு keep);
ST_FUNC Sym *sym_push2(Sym **ps, முழு v, முழு t, முழு c);
ST_FUNC Sym *sym_find2(Sym *s, முழு v);
ST_INLN Sym *sym_find(முழு v);
ST_FUNC Sym *label_find(முழு v);
ST_FUNC Sym *label_தள்ளு(Sym **ptop, முழு v, முழு flags);
ST_FUNC வெறுமை label_எடு(Sym **ptop, Sym *slast, முழு keep);
ST_INLN Sym *struct_find(முழு v);

ST_FUNC Sym *global_identifier_தள்ளு(முழு v, முழு t, முழு c);
ST_FUNC Sym *external_global_sym(முழு v, CType *type);
ST_FUNC Sym *external_helper_sym(முழு v);
ST_FUNC வெறுமை vpush_helper_func(முழு v);
ST_FUNC வெறுமை vset(CType *type, முழு r, முழு v);
ST_FUNC வெறுமை vset_VT_CMP(முழு op);
ST_FUNC வெறுமை vpushi(முழு v);
ST_FUNC வெறுமை vpushv(SValue *v);
ST_FUNC வெறுமை vpushsym(CType *type, Sym *sym);
ST_FUNC வெறுமை vswap(வெறுமை);
ST_FUNC வெறுமை vrott(முழு n);
ST_FUNC வெறுமை vrotb(முழு n);
ST_FUNC வெறுமை vrev(முழு n);
ST_FUNC வெறுமை vpop(வெறுமை);
#எனில் PTR_SIZE == 4
ST_FUNC வெறுமை lexpand(வெறுமை);
#endif
#ifdef TCC_TARGET_ARM
ST_FUNC முழு get_reg_ex(முழு rc, முழு rc2);
#endif
ST_FUNC வெறுமை save_reg(முழு r);
ST_FUNC வெறுமை save_reg_upstack(முழு r, முழு n);
ST_FUNC முழு get_reg(முழு rc);
ST_FUNC வெறுமை save_regs(முழு n);
ST_FUNC வெறுமை gaddrof(வெறுமை);
ST_FUNC முழு gv(முழு rc);
ST_FUNC வெறுமை gv2(முழு rc1, முழு rc2);
ST_FUNC வெறுமை gen_op(முழு op);
ST_FUNC முழு type_size(CType *type, முழு *a);
ST_FUNC வெறுமை mk_pointer(CType *type);
ST_FUNC வெறுமை vstore(வெறுமை);
ST_FUNC வெறுமை inc(முழு post, முழு c);
ST_FUNC CString* parse_mult_str(மாறிலி எழுத்து *செய்தி);
ST_FUNC CString* parse_asm_str(வெறுமை);
ST_FUNC வெறுமை indir(வெறுமை);
ST_FUNC வெறுமை unary(வெறுமை);
ST_FUNC வெறுமை gexpr(வெறுமை);
ST_FUNC முழு கோவை_const(வெறுமை);
#எனில் defined CONFIG_TCC_BCHECK || defined TCC_TARGET_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size);
#endif
#எனில் defined TCC_TARGET_X86_64 && !defined TCC_TARGET_PE
ST_FUNC முழு classify_x86_64_va_arg(CType *ty);
#endif
#ifdef CONFIG_TCC_BCHECK
ST_FUNC வெறுமை gbound_args(முழு nb_args);
ST_DATA முழு func_bound_add_epilog;
#endif
ST_FUNC Sym *gfunc_set_param(Sym *s, முழு c, முழு byref);

/* ------------ tccelf.c ------------ */

#define TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#define TCC_OUTPUT_FORMAT_இருமம் 1 /* binary image output */
#define TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#define TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#define ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

வகைவரை கட்டமைப்பு {
    unsigned முழு n_strx;         /* index into string table of name */
    unsigned எழுத்து n_type;         /* type of symbol */
    unsigned எழுத்து n_other;        /* misc info (usually empty) */
    unsigned short n_desc;        /* description field */
    unsigned முழு n_மதிப்பு;        /* value of symbol */
} Stab_Sym;

ST_FUNC வெறுமை tccelf_new(TCCState *s);
ST_FUNC வெறுமை tccelf_delete(TCCState *s);
ST_FUNC வெறுமை tccelf_begin_file(TCCState *s1);
ST_FUNC வெறுமை tccelf_end_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, மாறிலி எழுத்து *name, முழு sh_type, முழு sh_flags);
ST_FUNC வெறுமை section_realloc(Section *sec, unsigned long new_size);
ST_FUNC size_t section_add(Section *sec, addr_t size, முழு align);
ST_FUNC வெறுமை *section_ptr_add(Section *sec, addr_t size);
ST_FUNC Section *find_section(TCCState *s1, மாறிலி எழுத்து *name);
ST_FUNC வெறுமை free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, மாறிலி எழுத்து *symtab_name, முழு sh_type, முழு sh_flags, மாறிலி எழுத்து *strtab_name, மாறிலி எழுத்து *hash_name, முழு hash_sh_flags);
ST_FUNC வெறுமை init_symtab(Section *s);

ST_FUNC முழு put_elf_str(Section *s, மாறிலி எழுத்து *sym);
ST_FUNC முழு put_elf_sym(Section *s, addr_t மதிப்பு, unsigned long size, முழு info, முழு other, முழு shndx, மாறிலி எழுத்து *name);
ST_FUNC முழு set_elf_sym(Section *s, addr_t மதிப்பு, unsigned long size, முழு info, முழு other, முழு shndx, மாறிலி எழுத்து *name);
ST_FUNC முழு find_elf_sym(Section *s, மாறிலி எழுத்து *name);
ST_FUNC வெறுமை put_elf_reloc(Section *symtab, Section *s, unsigned long offset, முழு type, முழு குறியீடு);
ST_FUNC வெறுமை put_elf_reloca(Section *symtab, Section *s, unsigned long offset, முழு type, முழு குறியீடு, addr_t addend);

ST_FUNC வெறுமை resolve_common_syms(TCCState *s1);
ST_FUNC வெறுமை relocate_syms(TCCState *s1, Section *symtab, முழு do_resolve);
ST_FUNC வெறுமை relocate_sections(TCCState *s1);

ST_FUNC ssize_t full_read(முழு fd, வெறுமை *buf, size_t மொத்தம்_2);
ST_FUNC வெறுமை *load_data(முழு fd, unsigned long file_offset, unsigned long size);
ST_FUNC முழு tcc_object_type(முழு fd, ElfW(Ehdr) *h);
ST_FUNC முழு tcc_load_object_file(TCCState *s1, முழு fd, unsigned long file_offset);
ST_FUNC முழு tcc_load_archive(TCCState *s1, முழு fd, முழு alacarte);
ST_FUNC வெறுமை add_array(TCCState *s1, மாறிலி எழுத்து *sec, முழு c);

ST_FUNC கட்டமைப்பு sym_attr *get_sym_attr(TCCState *s1, முழு index, முழு alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, மாறிலி எழுத்து *name, முழு err, முழு forc);
ST_FUNC வெறுமை list_elf_symbols(TCCState *s, வெறுமை *ctx,
    வெறுமை (*குறியீடு_cb)(வெறுமை *ctx, மாறிலி எழுத்து *name, மாறிலி வெறுமை *val));
ST_FUNC முழு set_global_sym(TCCState *s1, மாறிலி எழுத்து *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    க்கு (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

#ifndef ELF_OBJ_ONLY
ST_FUNC முழு tcc_load_dll(TCCState *s1, முழு fd, மாறிலி எழுத்து *filename, முழு level);
ST_FUNC முழு tcc_load_ldscript(TCCState *s1, முழு fd);
ST_FUNC வெறுமை tccelf_add_crtbegin(TCCState *s1);
ST_FUNC வெறுமை tccelf_add_crtend(TCCState *s1);
#endif
#ifndef TCC_TARGET_PE
ST_FUNC வெறுமை tcc_add_runtime(TCCState *s1);
#endif

/* ------------ xxx-link.c ------------ */

#ifndef TCC_TARGET_PE
ST_FUNC முழு code_reloc (முழு reloc_type);
ST_FUNC முழு gotplt_entry_type (முழு reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
எண்ணிக்கை gotplt_entry {
    NO_GOTPLT_ENTRY,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ENTRY,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ENTRY	/* always generate (eg. PLTOFF relocs) */
};
#define NEED_RELOC_TYPE
#எனில் !defined TCC_TARGET_MACHO || defined TCC_IS_NATIVE
ST_FUNC unsigned create_plt_entry(TCCState *s1, unsigned got_offset, கட்டமைப்பு sym_attr *attr);
ST_FUNC வெறுமை relocate_plt(TCCState *s1);
ST_FUNC வெறுமை build_got_entries(TCCState *s1, முழு got_sym); /* in tccelf.c */
#define NEED_BUILD_GOT
#endif
#endif

ST_FUNC வெறுமை relocate(TCCState *s1, ElfW_Rel *rel, முழு type, unsigned எழுத்து *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_DATA மாறிலி எழுத்து * மாறிலி target_machine_defs;
ST_DATA மாறிலி முழு reg_classes[NB_REGS];

ST_FUNC வெறுமை gsym_addr(முழு t, முழு a);
ST_FUNC வெறுமை gsym(முழு t);
ST_FUNC வெறுமை load(முழு r, SValue *sv);
ST_FUNC வெறுமை store(முழு r, SValue *v);
ST_FUNC முழு gfunc_sret(CType *vt, முழு variadic, CType *ret, முழு *align, முழு *regsize);
ST_FUNC வெறுமை gfunc_call(முழு nb_args);
ST_FUNC வெறுமை gfunc_prolog(Sym *func_sym);
ST_FUNC வெறுமை gfunc_epilog(வெறுமை);
ST_FUNC வெறுமை gen_fill_nops(முழு);
ST_FUNC முழு gjmp(முழு t);
ST_FUNC வெறுமை gjmp_addr(முழு a);
ST_FUNC முழு gjmp_cond(முழு op, முழு t);
ST_FUNC முழு gjmp_append(முழு n, முழு t);
ST_FUNC வெறுமை gen_opi(முழு op);
ST_FUNC வெறுமை gen_opf(முழு op);
ST_FUNC வெறுமை gen_cvt_ftoi(முழு t);
ST_FUNC வெறுமை gen_cvt_itof(முழு t);
ST_FUNC வெறுமை gen_cvt_ftof(முழு t);
ST_FUNC வெறுமை ggoto(வெறுமை);
#ifndef TCC_TARGET_C67
ST_FUNC வெறுமை o(unsigned முழு c);
#endif
ST_FUNC வெறுமை gen_vla_sp_save(முழு addr);
ST_FUNC வெறுமை gen_vla_sp_restore(முழு addr);
ST_FUNC வெறுமை gen_vla_alloc(CType *type, முழு align);

நிலையான உள்வரி uint16_t read16le(unsigned எழுத்து *p) {
    திரும்பு p[0] | (uint16_t)p[1] << 8;
}
நிலையான உள்வரி வெறுமை write16le(unsigned எழுத்து *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
நிலையான உள்வரி uint32_t read32le(unsigned எழுத்து *p) {
  திரும்பு read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
நிலையான உள்வரி வெறுமை write32le(unsigned எழுத்து *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
நிலையான உள்வரி வெறுமை add32le(unsigned எழுத்து *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
நிலையான உள்வரி uint64_t read64le(unsigned எழுத்து *p) {
  திரும்பு read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
நிலையான உள்வரி வெறுமை write64le(unsigned எழுத்து *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
நிலையான உள்வரி வெறுமை add64le(unsigned எழுத்து *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#எனில் defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64 || defined TCC_TARGET_ARM
ST_FUNC வெறுமை g(முழு c);
ST_FUNC வெறுமை gen_le16(முழு c);
ST_FUNC வெறுமை gen_le32(முழு c);
#endif
#எனில் defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
ST_FUNC வெறுமை gen_addr32(முழு r, Sym *sym, முழு c);
ST_FUNC வெறுமை gen_addrpc32(முழு r, Sym *sym, முழு c);
ST_FUNC வெறுமை gen_cvt_csti(முழு t);
ST_FUNC வெறுமை gen_increment_tcov (SValue *sv);
#endif

/* ------------ x86_64-gen.c ------------ */
#ifdef TCC_TARGET_X86_64
ST_FUNC வெறுமை gen_opl(முழு op);
#ifdef TCC_TARGET_PE
ST_FUNC வெறுமை gen_vla_result(முழு addr);
#endif
ST_FUNC வெறுமை gen_cvt_sxtw(வெறுமை);
ST_FUNC வெறுமை gen_cvt_csti(முழு t);
#endif

/* ------------ arm-gen.c ------------ */
#ifdef TCC_TARGET_ARM
#எனில் defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC மாறிலி எழுத்து *default_elfinterp(கட்டமைப்பு TCCState *s);
#endif
ST_FUNC வெறுமை arm_init(கட்டமைப்பு TCCState *s);
ST_FUNC வெறுமை gen_increment_tcov (SValue *sv);
#endif

/* ------------ arm64-gen.c ------------ */
#ifdef TCC_TARGET_ARM64
ST_FUNC வெறுமை gen_opl(முழு op);
ST_FUNC வெறுமை gfunc_return(CType *func_type);
ST_FUNC வெறுமை gen_va_start(வெறுமை);
ST_FUNC வெறுமை gen_va_arg(CType *t);
ST_FUNC வெறுமை gen_clear_cache(வெறுமை);
ST_FUNC வெறுமை gen_cvt_sxtw(வெறுமை);
ST_FUNC வெறுமை gen_cvt_csti(முழு t);
ST_FUNC வெறுமை gen_increment_tcov (SValue *sv);
#endif

/* ------------ riscv64-gen.c ------------ */
#ifdef TCC_TARGET_RISCV64
ST_FUNC வெறுமை gen_opl(முழு op);
ST_FUNC வெறுமை gen_va_start(வெறுமை);
ST_FUNC வெறுமை arch_transfer_ret_regs(முழு);
ST_FUNC வெறுமை gen_cvt_sxtw(வெறுமை);
ST_FUNC வெறுமை gen_cvt_csti(முழு t);
ST_FUNC வெறுமை gen_increment_tcov (SValue *sv);
ST_FUNC வெறுமை gen_clear_cache(வெறுமை);
#endif

/* ------------ c67-gen.c ------------ */
#ifdef TCC_TARGET_C67
#endif

/* ------------ tcccoff.c ------------ */
#ifdef TCC_TARGET_COFF
ST_FUNC முழு tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC முழு tcc_load_coff(TCCState * s1, முழு fd);
#endif

/* ------------ tccasm.c ------------ */
ST_FUNC வெறுமை asm_instr(வெறுமை);
ST_FUNC வெறுமை asm_global_instr(வெறுமை);
ST_FUNC முழு tcc_assemble(TCCState *s1, முழு do_preprocess);
#ifdef CONFIG_TCC_ASM
ST_FUNC முழு find_constraint(ASMOperand *operands, முழு nb_operands, மாறிலி எழுத்து *name, மாறிலி எழுத்து **pp);
ST_FUNC Sym* get_asm_sym(முழு name, Sym *csym);
ST_FUNC வெறுமை asm_கோவை(TCCState *s1, கோவை_மதிப்பு *pe);
ST_FUNC முழு asm_int_கோவை(TCCState *s1);
#எனில் PTR_SIZE == 8
ST_FUNC வெறுமை gen_expr64(கோவை_மதிப்பு *pe);
#endif
/* ------------ i386-asm.c ------------ */
ST_FUNC வெறுமை gen_expr32(கோவை_மதிப்பு *pe);
ST_FUNC வெறுமை asm_opcode(TCCState *s1, முழு opcode);
ST_FUNC முழு asm_parse_regvar(முழு t);
ST_FUNC வெறுமை asm_compute_constraints(ASMOperand *operands, முழு nb_operands, முழு nb_outputs, மாறிலி uint8_t *clobber_regs, முழு *pout_reg);
ST_FUNC வெறுமை subst_asm_operand(CString *add_str, SValue *sv, முழு modifier);
ST_FUNC வெறுமை asm_gen_code(ASMOperand *operands, முழு nb_operands, முழு nb_outputs, முழு is_output, uint8_t *clobber_regs, முழு out_reg);
ST_FUNC வெறுமை asm_clobber(uint8_t *clobber_regs, மாறிலி எழுத்து *str);
#endif

/* ------------ tccpe.c -------------- */
#ifdef TCC_TARGET_PE
ST_FUNC முழு pe_load_file(கட்டமைப்பு TCCState *s1, முழு fd, மாறிலி எழுத்து *filename);
ST_FUNC முழு pe_output_file(TCCState * s1, மாறிலி எழுத்து *filename);
ST_FUNC முழு pe_putimport(TCCState *s1, முழு dllindex, மாறிலி எழுத்து *name, addr_t மதிப்பு);
ST_FUNC முழு pe_setsubsy(TCCState *s1, மாறிலி எழுத்து *arg);
#எனில் defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
#endif
#எனில் defined(TCC_TARGET_X86_64) || defined(TCC_TARGET_ARM64)
ST_FUNC வெறுமை pe_add_unwind_data(unsigned start, unsigned end, unsigned அடுக்கு);
#endif
PUB_FUNC முழு tcc_get_dllexports(மாறிலி எழுத்து *filename, எழுத்து **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#endif
#define ST_ASM_SET 0x04

/* ------------ tccmacho.c ----------------- */
#ifdef TCC_TARGET_MACHO
ST_FUNC முழு macho_output_file(TCCState * s1, மாறிலி எழுத்து *filename);
ST_FUNC முழு macho_load_dll(TCCState *s1, முழு fd, மாறிலி எழுத்து *filename, முழு lev);
ST_FUNC முழு macho_load_tbd(TCCState *s1, முழு fd, மாறிலி எழுத்து *filename, முழு lev);
#ifdef TCC_IS_NATIVE
ST_FUNC வெறுமை tcc_add_macos_sdkpath(TCCState* s);
ST_FUNC எழுத்து* macho_tbd_soname(முழு fd);
#endif
#endif
/* ------------ tccrun.c ----------------- */
#ifdef TCC_IS_NATIVE
#ifdef CONFIG_TCC_STATIC
#define RTLD_LAZY       0x001
#define RTLD_NOW        0x002
#define RTLD_GLOBAL     0x100
#define RTLD_DEFAULT    வெற்று
/* dummy function for profiling */
ST_FUNC வெறுமை *dlopen(மாறிலி எழுத்து *filename, முழு flag);
ST_FUNC வெறுமை dlclose(வெறுமை *p);
ST_FUNC மாறிலி எழுத்து *dlerror(வெறுமை);
ST_FUNC வெறுமை *dlsym(வெறுமை *handle, மாறிலி எழுத்து *குறியீடு);
#endif
ST_FUNC வெறுமை tcc_run_free(TCCState *s1);
#endif

/* ------------ tcctools.c ----------------- */
#எனில் 0 /* included in tcc.c */
ST_FUNC முழு tcc_tool_ar(TCCState *s, முழு argc, எழுத்து **argv);
#ifdef TCC_TARGET_PE
ST_FUNC முழு tcc_tool_impdef(TCCState *s, முழு argc, எழுத்து **argv);
#endif
ST_FUNC முழு tcc_tool_cross(TCCState *s, எழுத்து **argv, முழு option);
ST_FUNC முழு gen_makedeps(TCCState *s, மாறிலி எழுத்து *target, மாறிலி எழுத்து *filename);
#endif

/* ------------ tccdbg.c ------------ */

ST_FUNC வெறுமை tcc_debug_new(TCCState *s);

ST_FUNC வெறுமை tcc_debug_start(TCCState *s1);
ST_FUNC வெறுமை tcc_debug_end(TCCState *s1);
ST_FUNC வெறுமை tcc_debug_bincl(TCCState *s1);
ST_FUNC வெறுமை tcc_debug_eincl(TCCState *s1);
ST_FUNC வெறுமை tcc_debug_newfile(TCCState *s1);

ST_FUNC வெறுமை tcc_debug_வரி(TCCState *s1);
ST_FUNC வெறுமை tcc_add_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC வெறுமை tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC வெறுமை tcc_debug_prolog_epilog(TCCState *s1, முழு மதிப்பு);
ST_FUNC வெறுமை tcc_debug_funcend(TCCState *s1, முழு size);
ST_FUNC வெறுமை tcc_debug_extern_sym(TCCState *s1, Sym *sym, முழு sh_இலக்கம், முழு sym_bind, முழு sym_type);
ST_FUNC வெறுமை tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC வெறுமை tcc_debug_stabn(TCCState *s1, முழு type, முழு மதிப்பு);
ST_FUNC வெறுமை tcc_debug_fix_forw(TCCState *s1, CType *t);

#எனில் !(defined ELF_OBJ_ONLY || defined TCC_TARGET_ARM || defined TARGETOS_BSD)
ST_FUNC வெறுமை tcc_eh_frame_start(TCCState *s1);
ST_FUNC வெறுமை tcc_eh_frame_end(TCCState *s1);
ST_FUNC வெறுமை tcc_eh_frame_hdr(TCCState *s1, முழு final);
#define TCC_EH_FRAME 1
#endif

ST_FUNC வெறுமை tcc_tcov_start(TCCState *s1);
ST_FUNC வெறுமை tcc_tcov_end(TCCState *s1);
ST_FUNC வெறுமை tcc_tcov_check_வரி(TCCState *s1, முழு start);
ST_FUNC வெறுமை tcc_tcov_block_end(TCCState *s1, முழு வரி);
ST_FUNC வெறுமை tcc_tcov_block_begin(TCCState *s1);
ST_FUNC வெறுமை tcc_tcov_reset_ind(TCCState *s1);

#define stab_section            s1->stab_section
#define stabstr_section         stab_section->link
#define tcov_section            s1->tcov_section
#define eh_frame_section        s1->eh_frame_section
#define eh_frame_hdr_section    s1->eh_frame_hdr_section
#define dwarf_info_section      s1->dwarf_info_section
#define dwarf_abbrev_section    s1->dwarf_abbrev_section
#define dwarf_வரி_section      s1->dwarf_வரி_section
#define dwarf_aranges_section   s1->dwarf_aranges_section
#define dwarf_str_section       s1->dwarf_str_section
#define dwarf_வரி_str_section  s1->dwarf_வரி_str_section

#define DWARF_MAX_128	((8 * அளவு (int64_t) + 6) / 7)
#define	dwarf_read_1(ln,end) \
	((ln) < (end) ? *(ln)++ : 0)
#define	dwarf_read_2(ln,end) \
	((ln) + 1 < (end) ? read16le(((ln)+=2) - 2) : 0)
#define	dwarf_read_4(ln,end) \
	((ln) + 3 < (end) ? read32le(((ln)+=4) - 4) : 0)
#define	dwarf_read_8(ln,end) \
	((ln) + 7 < (end) ? read64le(((ln)+=8) - 8) : 0)
நிலையான உள்வரி uint64_t
dwarf_read_uleb128(unsigned எழுத்து **ln, unsigned எழுத்து *end)
{
    unsigned எழுத்து *cp = *ln;
    uint64_t retval = 0;
    முழு i;
    க்கு (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	எனில் ((byte & 0x80) == 0)
	    நிறுத்து;
    }
    *ln = cp;
    திரும்பு retval;
}
நிலையான உள்வரி int64_t
dwarf_read_sleb128(unsigned எழுத்து **ln, unsigned எழுத்து *end)
{
    unsigned எழுத்து *cp = *ln;
    int64_t retval = 0;
    முழு i;
    க்கு (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, end);
        retval |= (byte & 0x7f) << (i * 7);
	எனில் ((byte & 0x80) == 0) {
	    எனில் ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    நிறுத்து;
	}
    }
    *ln = cp;
    திரும்பு retval;
}

/* default dwarf version for "-gdwarf" */
#ifdef TCC_TARGET_MACHO
# define DEFAULT_DWARF_VERSION 2
#இல்லையெனில்
# define DEFAULT_DWARF_VERSION 5
#endif

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ifndef CONFIG_DWARF_VERSION
# define CONFIG_DWARF_VERSION 0
#endif

#எனில் defined TCC_TARGET_X86_64
# define R_DATA_32DW R_X86_64_32
#இல்லையெனில்
# define R_DATA_32DW R_DATA_32
#endif

/********************************************************/
#எனில் CONFIG_TCC_SEMLOCK
#எனில் defined _WIN32
வகைவரை கட்டமைப்பு { நிலையற்ற LONG init; CRITICAL_SECTION cs; } TCCSem;
நிலையான உள்வரி வெறுமை wait_sem(TCCSem *p) {
    எனில் (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } இல்லையெனில் {
        போது (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
நிலையான உள்வரி வெறுமை post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#அல்லதெனில் defined __APPLE__
#அந்தர்பாவ <dispatch/dispatch.h>
வகைவரை கட்டமைப்பு { முழு init; dispatch_semaphore_t sem; } TCCSem;
நிலையான உள்வரி வெறுமை wait_sem(TCCSem *p) {
    எனில் (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_TIME_FOREVER);
}
நிலையான உள்வரி வெறுமை post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#இல்லையெனில்
#அந்தர்பாவ <semaphore.h>
வகைவரை கட்டமைப்பு { முழு init; sem_t sem; } TCCSem;
நிலையான உள்வரி வெறுமை wait_sem(TCCSem *p) {
    எனில் (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    போது (sem_wait(&p->sem) < 0 && errno == EINTR);
}
நிலையான உள்வரி வெறுமை post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#endif
#define TCC_SEM(s) TCCSem s
#define WAIT_SEM wait_sem
#define POST_SEM post_sem
#இல்லையெனில்
#define TCC_SEM(s)
#define WAIT_SEM(p)
#define POST_SEM(p)
#endif

/********************************************************/
#undef ST_DATA
#எனில் ONE_SOURCE
#define ST_DATA நிலையான
#இல்லையெனில்
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
#define total_வரிகள்         TCC_STATE_VAR(total_வரிகள்)
#define total_bytes         TCC_STATE_VAR(total_bytes)

PUB_FUNC வெறுமை tcc_enter_state(TCCState *s1);
PUB_FUNC வெறுமை tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#define tcc_warning_c(sw) TCC_SET_STATE((\
    tcc_state->warn_இலக்கம் = offsetof(TCCState, sw) \
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
#இல்லையெனில்
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_SET_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#endif
