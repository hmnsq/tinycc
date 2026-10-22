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

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TCC_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TCC_H

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GNU_ਸਰੋਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DARWIN_C_ਸਰੋਤ
#ਅਨ੍ਤਰ੍ਭਾਵ "config.h"

#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
# undef __attribute__
#ਜੇ_ਅੰਤ
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <errno.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <math.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <fcntl.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <setjmp.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <time.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
ਬਾਹਰੀ ਦਸ਼ਮਲਵ strtof (ਅਚਲ ਅੱਖਰ *__nptr, ਅੱਖਰ **__endptr);
ਬਾਹਰੀ ਲੰਮਾ ਦੁੱਗਣਾ strtold (ਅਚਲ ਅੱਖਰ *__nptr, ਅੱਖਰ **__endptr);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
# define WIN32_LEAN_AND_ਔਸਤ 1
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
# define ਸਤਰਅੰਦਰ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (ਲੰਮਾ ਦੁੱਗਣਾ)strtod
#  define strtof (ਦਸ਼ਮਲਵ)strtod
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
# ਜੇ defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ O_ਦੁਆਧਾਰੀ_2
# define O_ਦੁਆਧਾਰੀ_2 0
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ offsetof
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__ // clang -fsanitize compains about: NULL+value
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ offsetof(type, ਖੇਤਰ) __builtin_offsetof(type, ਖੇਤਰ)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ offsetof(type, ਖੇਤਰ) ((ਮਾਪ_t) &((type *)0)->ਖੇਤਰ)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ countof
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ countof(tab) (ਆਕਾਰ(tab) / ਆਕਾਰ((tab)[0]))
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#ਨਹੀਂਤਾਂ
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (ਲਿਖੋ, (x), (y))))
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#ਨਹੀਂਤਾਂ
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#ਜੇ_ਅੰਤ

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
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_I386) && !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM) && \
    !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64) && !defined(TCC_ਨਿਸ਼ਾਨਾ_C67) && \
    !defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) && !defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
# ਜੇ defined __x86_64__
#  define TCC_ਨਿਸ਼ਾਨਾ_X86_64
# elif defined __arm__
#  define TCC_ਨਿਸ਼ਾਨਾ_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_ਨਿਸ਼ਾਨਾ_ARM64
# elif defined __riscv
#  define TCC_ਨਿਸ਼ਾਨਾ_RISCV64
# ਨਹੀਂਤਾਂ
#  define TCC_ਨਿਸ਼ਾਨਾ_I386
# endif
# ifdef _WIN32
#  define TCC_ਨਿਸ਼ਾਨਾ_PE 1
# endif
# ifdef __APPLE__
#  define TCC_ਨਿਸ਼ਾਨਾ_MACHO 1
# endif
#ਜੇ_ਅੰਤ

/* only native compiler supports -run */
#ਜੇ defined _WIN32 == defined TCC_ਨਿਸ਼ਾਨਾ_PE \
    && defined __APPLE__ == defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
# ਜੇ defined __i386__ && defined TCC_ਨਿਸ਼ਾਨਾ_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_ਨਿਸ਼ਾਨਾ_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
#  define TCC_IS_NATIVE
# endif
#ਜੇ_ਅੰਤ

#ਜੇ defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#ਨਹੀਂਤਾਂ
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#ਜੇ_ਅੰਤ

#ਜੇ defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#ਨਹੀਂਤਾਂ
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#ਜੇ_ਅੰਤ

#ਜੇ defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#ਨਹੀਂਤਾਂ
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#ਜੇ_ਅੰਤ

#ਜੇ defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#ਜਾਂਜੇ !(defined TCC_ਨਿਸ਼ਾਨਾ_PE || defined TCC_ਨਿਸ਼ਾਨਾ_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#ਜੇ_ਅੰਤ

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE || defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#ਨਹੀਂਤਾਂ
# define TCC_ਨਿਸ਼ਾਨਾ_UNIX 1
#ਜੇ_ਅੰਤ

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE \
    || (defined TCC_ਨਿਸ਼ਾਨਾ_MACHO && defined TCC_ਨਿਸ਼ਾਨਾ_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#ਜੇ_ਅੰਤ

/* support using libtcc from threads */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#ਜੇ_ਅੰਤ

/* ------------ path configuration ------------ */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#ਜੇ_ਅੰਤ

#ਜੇ !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#ਨਹੀਂਤਾਂ
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#ਜੇ_ਅੰਤ

/* path to find crt1.o, crti.o and crtn.o */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#ਜੇ_ਅੰਤ

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_SYSINCLUDEPATHS
# ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# ਨਹੀਂਤਾਂ
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#ਜੇ_ਅੰਤ

/* library search paths */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_LIBPATHS
# ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# ਨਹੀਂਤਾਂ
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#ਜੇ_ਅੰਤ

/* name of ELF interpreter */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_ELFINTERP
# ਜੇ defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_ਨਿਸ਼ਾਨਾ_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_ਨਿਸ਼ਾਨਾ_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# ਨਹੀਂਤਾਂ
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#ਜੇ_ਅੰਤ

/* (target specific) libtcc1.a */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#ਜੇ_ਅੰਤ

/* <cross-prefix-to->libtcc1.a */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#ਜੇ_ਅੰਤ

/* -------------------------------------------- */

#ਅਨ੍ਤਰ੍ਭਾਵ "libtcc.h"
#ਅਨ੍ਤਰ੍ਭਾਵ "elf.h"
#ਅਨ੍ਤਰ੍ਭਾਵ "stab.h"
#ਅਨ੍ਤਰ੍ਭਾਵ "dwarf.h"

/* -------------------------------------------- */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ONE_ਸਰੋਤ
# define ONE_ਸਰੋਤ 0
#ਜੇ_ਅੰਤ

#ਜੇ ONE_ਸਰੋਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_INLN ਸਥਿਰ ਸਤਰਅੰਦਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_FUNC ਸਥਿਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_ਅੰਕੜੇ ਸਥਿਰ
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_INLN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_FUNC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_ਅੰਕੜੇ ਬਾਹਰੀ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_PROFILE /* profile all functions */
# define ਸਥਿਰ
# define ਸਤਰਅੰਦਰ
#ਜੇ_ਅੰਤ

/* -------------------------------------------- */
/* include the target specific definitions */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਸ਼ਾਨਾ_DEFS_ONLY
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
# include "i386-gen.c"
# include "i386-link.c"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_C67
# define TCC_ਨਿਸ਼ਾਨਾ_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#ਨਹੀਂਤਾਂ
#ਗਲਤੀ unknown ਨਿਸ਼ਾਨਾ
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

/* -------------------------------------------- */

#ਜੇ PTR_ਮਾਪ == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#ਨਹੀਂਤਾਂ
# define ELFCLASSW ELFCLASS32
# define ElfW(type) Elf##32##_##type
# define ELFW(type) ELF##32##_##type
# define ElfW_Rel ElfW(Rel)
# define SHT_RELX SHT_REL
# define REL_SECTION_FMT ".rel%s"
#ਜੇ_ਅੰਤ
/* target address type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ addr_t ElfW(Addr)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ElfSym ElfW(Sym)

#ਜੇ PTR_ਮਾਪ == 8 && !defined TCC_ਨਿਸ਼ਾਨਾ_PE
# define LONG_ਮਾਪ 8
#ਨਹੀਂਤਾਂ
# define LONG_ਮਾਪ 4
#ਜੇ_ਅੰਤ

/* -------------------------------------------- */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCLUDE_ਢੇਰ_ਮਾਪ  32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IFDEF_ਢੇਰ_ਮਾਪ    64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VSTACK_ਮਾਪ         512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRING_MAX_ਮਾਪ     1024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKSTR_MAX_ਮਾਪ     256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PACK_ਢੇਰ_ਮਾਪ     8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_HASH_ਮਾਪ       16384 /* must be a power of two */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ALLOC_INCR      512  /* must be a power of two */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_MAX_ਮਾਪ        4 /* token max size in int unit when stored in string */

/* token symbol management */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TokenSym {
    ਬਣਤਰ TokenSym *hash_ਅਗਲਾ;
    ਬਣਤਰ Sym *sym_define; /* direct pointer to define */
    ਬਣਤਰ Sym *sym_label; /* direct pointer to label */
    ਬਣਤਰ Sym *sym_struct; /* direct pointer to structure */
    ਬਣਤਰ Sym *sym_identifier; /* direct pointer to identifier */
    ਪੂਰਨ tok; /* token number */
    ਪੂਰਨ len;
    ਅੱਖਰ str[1];
} TokenSym;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ nwchar_t;
#ਨਹੀਂਤਾਂ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ nwchar_t;
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ CString {
    ਪੂਰਨ ਮਾਪ; /* size in bytes */
    ਪੂਰਨ ਮਾਪ_allocated;
    ਅੱਖਰ *ਅੰਕੜੇ; /* nwchar_t* in cases */
} CString;

/* type definition */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ CType {
    ਪੂਰਨ t;
    ਬਣਤਰ Sym *ref;
} CType;

/* long double words on host(!) platform */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDOUBLE_ਸ਼ਬਦ ((ਆਕਾਰ(ਲੰਮਾ ਦੁੱਗਣਾ)+3)/4)

/* constant value */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ CValue {
    ਲੰਮਾ ਦੁੱਗਣਾ ld;
    ਦੁੱਗਣਾ d;
    ਦਸ਼ਮਲਵ f;
    uint64_t i;
    ਬਣਤਰ {
        ਅੱਖਰ *ਅੰਕੜੇ;
        ਪੂਰਨ ਮਾਪ;
    } str;
    ਪੂਰਨ tab[LDOUBLE_ਸ਼ਬਦ];
} CValue;

/* value on stack */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SValue {
    CType type;      /* type */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ r;      /* register + flags */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    ਸੰਘ {
      ਬਣਤਰ { ਪੂਰਨ jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    ਸੰਘ {
      ਬਣਤਰ { ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ cmp_op, cmp_r; }; /* VT_CMP operation */
      ਬਣਤਰ Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ਬਣਤਰ SymAttr {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ
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
ਬਣਤਰ FuncAttr {
    ਬਿਨਾਨਿਸ਼ਾਨੀ
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_ਦਲੀਲਾਂ   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Sym {
    ਪੂਰਨ v; /* symbol token */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ਬਣਤਰ SymAttr a; /* symbol attributes */
    ਸੰਘ {
        ਬਣਤਰ {
            ਪੂਰਨ c; /* associated number or Elf symbol index */
            ਸੰਘ {
                ਪੂਰਨ sym_scope; /* scope level for locals */
                ਪੂਰਨ jnext; /* next jump label */
                ਪੂਰਨ jind; /* label position */
                ਬਣਤਰ FuncAttr f; /* function attributes */
                ਪੂਰਨ auxtype; /* bitfield access type */
            };
        };
        ਲੰਮਾ ਲੰਮਾ enum_val; /* enum constant if IS_ENUM_VAL */
        ਪੂਰਨ *d; /* define token stream */
        ਬਣਤਰ Sym *cleanup_func;
    };

    CType type; /* associated type */
    ਸੰਘ {
        ਬਣਤਰ Sym *ਅਗਲਾ; /* next related symbol (for fields and anoms) */
        ਪੂਰਨ *e; /* expanded token stream with preprocessor macros */
        ਪੂਰਨ asm_label; /* associated asm label */
        ਬਣਤਰ Sym *cleanupstate; /* in defined labels */
        ਪੂਰਨ *vla_array_str; /* vla array code */
    };
    ਬਣਤਰ Sym *prev; /* prev symbol in stack */
    ਸੰਘ {
        ਬਣਤਰ Sym *prev_tok; /* previous symbol for this token */
        ਬਣਤਰ Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ਬਣਤਰ Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Section {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਅੰਕੜੇ_ਵਿੱਥ; /* current data offset */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਅੰਕੜੇ;       /* section data */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਅੰਕੜੇ_allocated; /* used for realloc() handling */
    TCCState *s1;
    ਪੂਰਨ sh_name;             /* elf section name (only used during output) */
    ਪੂਰਨ sh_ਅੰਕ;              /* elf section number */
    ਪੂਰਨ sh_type;             /* elf section type */
    ਪੂਰਨ sh_flags;            /* elf section flags */
    ਪੂਰਨ sh_info;             /* elf section info */
    ਪੂਰਨ sh_addralign;        /* elf section alignment */
    ਪੂਰਨ sh_entsize;          /* elf entry size */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ sh_ਮਾਪ;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ sh_ਵਿੱਥ; /* file offset */
    ਪੂਰਨ nb_hashed_syms;      /* used to resize the hash table */
    ਬਣਤਰ Section *link;    /* link to another section */
    ਬਣਤਰ Section *reloc;   /* corresponding section for relocation, if any */
    ਬਣਤਰ Section *hash;    /* hash table for symbols */
    ਬਣਤਰ Section *prev;    /* previous section on section stack */
    ਅੱਖਰ name[1];           /* section name */
} Section;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DLLReference {
    ਪੂਰਨ level;
    ਖਾਲੀ *handle;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਮਿਲਿਆ, ਸੂਚਕਾਂਕ;
    ਅੱਖਰ name[1];
} DLLReference;

/* -------------------------------------------------- */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYM_ਖੇਤਰ      0x20000000 /* struct/union field symbol space */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYM_ਪਹਿਲਾ_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_NEW       1 /* ansi function prototype */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_OLD       2 /* old function prototype */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_CDECL     0 /* standard c call */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_STDCALL   1 /* pascal c call */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_FASTCALL1 2 /* first param in %eax */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MACRO_OBJ      0 /* object like macro */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MACRO_FUNC     1 /* function like macro */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LABEL_DEFINED  0 /* label is defined */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LABEL_FORWARD  1 /* label is forward defined */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LABEL_DECLARED 2 /* label is declared but never used */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TYPE_ABSTRACT  1 /* type without variable */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TYPE_ਸਿੱਧਾ    2 /* type with variable */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TYPE_PARAM     4 /* type declares function parameter */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TYPE_NEST      8 /* nested call to post_type */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_BUF_ਮਾਪ 8192

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_ਸਿਰਾ;
    ਪੂਰਨ fd;
    ਬਣਤਰ BufferedFile *prev;
    ਪੂਰਨ ਸਤਰ_ਅੰਕ;    /* current line number - here to simplify code */
    ਪੂਰਨ ਸਤਰ_ref;    /* tcc -E: last printed line */
    ਪੂਰਨ ifndef_macro;  /* #ifndef macro / #endif search */
    ਪੂਰਨ ifndef_macro_saved; /* saved ifndef_macro */
    ਪੂਰਨ *ifdef_ਢੇਰ_ptr; /* ifdef_stack value at the start of the file */
    ਪੂਰਨ include_ਅਗਲਾ_ਸੂਚਕਾਂਕ; /* next search path */
    ਪੂਰਨ prev_tok_flags; /* saved tok_flags */
    ਅੱਖਰ filename[1024];    /* filename */
    ਅੱਖਰ *true_filename; /* filename not modified by # line directive */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ unget[4];
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਬਫਰ[1]; /* extra size for CH_EOB char */
} BufferedFile;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CH_EOF   (-1)   /* end of file */

/* used to record tokens */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TokenString {
    ਪੂਰਨ *str;
    ਪੂਰਨ len;
    ਪੂਰਨ need_spc;
    ਪੂਰਨ allocated_len;
    ਪੂਰਨ ਆਖਰੀ_ਸਤਰ_ਅੰਕ;
    ਪੂਰਨ save_ਸਤਰ_ਅੰਕ;
    /* used to chain token-strings with begin/end_macro() */
    ਬਣਤਰ TokenString *prev;
    ਅਚਲ ਪੂਰਨ *prev_ptr;
    ਅੱਖਰ alloc;
} TokenString;

/* GNUC attribute definition */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ AttributeDef {
    ਬਣਤਰ SymAttr a;
    ਬਣਤਰ FuncAttr f;
    ਬਣਤਰ Section *section;
    Sym *cleanup_func;
    ਪੂਰਨ alias_ਨਿਸ਼ਾਨਾ; /* token */
    ਪੂਰਨ asm_label; /* associated asm label */
    ਅੱਖਰ attr_ਬਹੁਲਕ; /* __attribute__((__mode__(...))) */
    ਅੱਖਰ new_section; /* section is new */
} AttributeDef;

/* inline functions */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ InlineFunc {
    TokenString *func_str;
    Sym *sym;
    ਅੱਖਰ filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ CachedInclude {
    ਪੂਰਨ ifndef_macro;
    ਪੂਰਨ once;
    ਪੂਰਨ hash_ਅਗਲਾ; /* -1 if none */
    ਅੱਖਰ filename[1]; /* path specified in #include */
} CachedInclude;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CACHED_INCLUDES_HASH_ਮਾਪ 32

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_ASM
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਵਿਅੰਜਕ_ਮੁੱਲ {
    uint64_t v;
    Sym *sym;
    ਪੂਰਨ pcrel;
} ਵਿਅੰਜਕ_ਮੁੱਲ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ASM_OPERANDS 30
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ASMOperand {
    ਪੂਰਨ id; /* GCC 3 optional identifier (0 if number only supported) */
    ਅੱਖਰ constraint[16];
    ਅੱਖਰ asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    ਪੂਰਨ ref_ਸੂਚਕਾਂਕ; /* if >= 0, gives reference to a output constraint */
    ਪੂਰਨ ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ; /* if >= 0, gives reference to an input constraint */
    ਪੂਰਨ ਤਰਜੀਹ; /* priority, used to assign registers */
    ਪੂਰਨ reg; /* if >= 0, register number used for this operand */
    ਪੂਰਨ is_llong; /* true if double register value */
    ਪੂਰਨ is_ਸਮ੍ਰਿਤੀ; /* true if memory operand */
    ਪੂਰਨ is_rw;     /* for '+' modifier */
    ਪੂਰਨ is_label;  /* for asm goto */
} ASMOperand;
#ਜੇ_ਅੰਤ

/* extra symbol attributes (not in symbol table) */
ਬਣਤਰ sym_attr {
    ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ plt_ਵਿੱਥ;
    ਪੂਰਨ plt_sym;
    ਪੂਰਨ dyn_ਸੂਚਕਾਂਕ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ linker_sym:1;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ plt_thumb_stub:1;
#ਜੇ_ਅੰਤ
};

ਬਣਤਰ TCCState {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ verbose; /* if true, display some information during compilation */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ nostdinc; /* if true, no standard headers are added */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ nostdlib; /* if true, no standard libraries are added */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ nostdlib_paths; /* if true, the default paths are not searched for libraries */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ nocommon; /* if true, do not use common symbols for .bss data */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ static_link; /* if true, static linking is performed */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ rdynamic; /* if true, all symbols are exported */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ symbolic; /* if true, resolve symbols in the current module first */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ znodelete; /* Set DF_1_NODELETE in dynamic section */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ filetype; /* file type for compilation (NONE,C,ASM) */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ optimize; /* only to #define __OPTIMIZE__ */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ option_pthread; /* -pthread option */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ enable_new_dtags; /* -Wl,--enable-new-dtags */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ char_is_unsigned;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ leading_underscore;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ dollars_ਵਿੱਚ_identifiers;  /* allows '$' char in identifiers */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਉਲਟ_funcargs; /* if true, evaluate last function arg first */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ gnu89_inline; /* treat 'extern inline' like 'static inline' */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ unwind_tables; /* create eh_frame section */

    /* warning switches */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_none;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_all;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_error;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_write_ਲੜੀਆਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_unsupported;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_implicit_function_declaration;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_discarded_qualifiers;
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WARN_ON  1 /* warning is on (-Woption) */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ warn_ਅੰਕ; /* temp var for tcc_warning_c() */

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ option_r; /* option -r */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ do_bench; /* option -bench */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ just_deps; /* option -M  */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ gen_deps; /* option -MD  */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ include_sys_deps; /* option -MD  */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ do_debug;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ dwarf;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ do_backtrace;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ do_bounds_check;
#ਜੇ_ਅੰਤ
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ gnu_ext;
    /* use TinyCC extensions */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ tcc_ext;

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ dflag; /* -dX value */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ nosse; /* For -mno-sse support. */
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ float_abi; /* float ABI of the generated code*/
#ਜੇ_ਅੰਤ

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ has_ਪਾਠ_addr;
    addr_t ਪਾਠ_addr; /* address of text section */
    ਬਿਨਾਨਿਸ਼ਾਨੀ section_align; /* section alignment */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
    ਪੂਰਨ seg_ਮਾਪ; /* 32. Can be 16 with i386 assembler (.code16) */
#ਜੇ_ਅੰਤ

    ਅੱਖਰ *tcc_lib_ਰਸਤਾ; /* CONFIG_TCCDIR or -B option */
    ਅੱਖਰ *soname; /* as specified on the command line (-soname) */
    ਅੱਖਰ *rpath; /* as specified on the command line (-Wl,-rpath=) */
    ਅੱਖਰ *elfint; /* -Wl,-I... on command line */
    ਅੱਖਰ *elf_entryname; /* "_start" unless set */
    ਅੱਖਰ *init_ਚਿੰਨ੍ਹ; /* symbols to call at load-time (not used currently) */
    ਅੱਖਰ *fini_ਚਿੰਨ੍ਹ; /* symbols to call at unload-time (not used currently) */
    ਅੱਖਰ *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    ਪੂਰਨ output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    ਪੂਰਨ output_format;
    /* nth test to run with -dt -run */
    ਪੂਰਨ ਲੜੀਵਾਰ_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    ਪੂਰਨ nb_loaded_dlls;

    /* include paths */
    ਅੱਖਰ **include_paths;
    ਪੂਰਨ nb_include_paths;

    ਅੱਖਰ **sysinclude_paths;
    ਪੂਰਨ nb_sysinclude_paths;

    /* library paths */
    ਅੱਖਰ **library_paths;
    ਪੂਰਨ nb_library_paths;

    /* crt?.o object path */
    ਅੱਖਰ **crt_paths;
    ਪੂਰਨ nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    ਖਾਲੀ *error_opaque;
    ਖਾਲੀ (*error_func)(ਖਾਲੀ *opaque, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ);
    ਪੂਰਨ error_ਸੈੱਟ_jmp_enabled;
    jmp_buf error_jmp_buf;
    ਪੂਰਨ nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    ਅੱਖਰ **ਨਿਸ਼ਾਨਾ_deps;
    ਪੂਰਨ nb_ਨਿਸ਼ਾਨਾ_deps;

    /* compilation */
    BufferedFile *include_ਢੇਰ[INCLUDE_ਢੇਰ_ਮਾਪ];
    BufferedFile **include_ਢੇਰ_ptr;

    ਪੂਰਨ ifdef_ਢੇਰ[IFDEF_ਢੇਰ_ਮਾਪ];
    ਪੂਰਨ *ifdef_ਢੇਰ_ptr;

    /* included files enclosed with #ifndef MACRO */
    ਪੂਰਨ cached_includes_hash[CACHED_INCLUDES_HASH_ਮਾਪ];
    CachedInclude **cached_includes;
    ਪੂਰਨ nb_cached_includes;

    /* #pragma pack stack */
    ਪੂਰਨ pack_ਢੇਰ[PACK_ਢੇਰ_ਮਾਪ];
    ਪੂਰਨ *pack_ਢੇਰ_ptr;
    ਅੱਖਰ **pragma_libs;
    ਪੂਰਨ nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ਬਣਤਰ InlineFunc **inline_fns;
    ਪੂਰਨ nb_inline_fns;

    /* sections */
    Section **sections;
    ਪੂਰਨ nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    ਪੂਰਨ nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *ਪਾਠ_section, *ਅੰਕੜੇ_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_ਪਾਠ_section; /* current section where function code is generated */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#ਜੇ_ਅੰਤ
    /* symbol section */
    ਸੰਘ { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_ਚੌਖਟਾ_section;
    Section *eh_ਚੌਖਟਾ_hdr_section;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ eh_ਸ਼ੁਰੂ;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_ਸਤਰ_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_ਸਤਰ_str_section;
    ਪੂਰਨ dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    ਬਣਤਰ _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ਬਣਤਰ sym_attr *sym_attrs;
    ਪੂਰਨ nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ qrel s1->qrel

    addr_t tls_ਸ਼ੁਰੂ, tls_ਸਿਰਾ;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਬਣਤਰ pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    ਪੂਰਨ nb_pcrel_hi_entries;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    /* PE info */
    ਪੂਰਨ pe_subsystem;
    ਬਿਨਾਨਿਸ਼ਾਨੀ pe_characteristics;
    ਬਿਨਾਨਿਸ਼ਾਨੀ pe_dll_characteristics;
    ਬਿਨਾਨਿਸ਼ਾਨੀ pe_file_align;
    ਬਿਨਾਨਿਸ਼ਾਨੀ pe_ਢੇਰ_ਮਾਪ;
    addr_t pe_imagebase;
# ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) || defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
    Section *uw_pdata;
    ਪੂਰਨ uw_sym;
    ਪੂਰਨ uw_xsym;
    ਬਿਨਾਨਿਸ਼ਾਨੀ uw_offs;
# endif
#ਜੇ_ਅੰਤ

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
    ਅੱਖਰ *install_name;
    uint32_t compatibility_ਸੰਸਕਰਣ;
    uint32_t current_ਸੰਸਕਰਣ;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
    ਪੂਰਨ nb_sym_versions;
    ਬਣਤਰ sym_ਸੰਸਕਰਣ *sym_versions;
    ਪੂਰਨ nb_sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ;
    ਪੂਰਨ *sym_ਮੰਜ਼ਿਲ_ਸੰਸਕਰਣ;
    ਪੂਰਨ dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
    ਅਚਲ ਅੱਖਰ *ਲੜੀਵਾਰ_main; /* entry for tcc_run() */
    ਖਾਲੀ *ਲੜੀਵਾਰ_ptr; /* runtime_memory */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੜੀਵਾਰ_ਮਾਪ; /* size of runtime_memory  */
    ਅਚਲ ਅੱਖਰ *ਲੜੀਵਾਰ_stdin; /* custom stdin file for run_main */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਖਾਲੀ *ਲੜੀਵਾਰ_function_ਸਾਰਣੀ; /* unwind data */
#ਜੇ_ਅੰਤ
    ਬਣਤਰ TCCState *ਅਗਲਾ;
    ਬਣਤਰ rt_context *rc; /* pointer to backtrace info block */
    ਖਾਲੀ *ਲੜੀਵਾਰ_lj, *ਲੜੀਵਾਰ_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    ਖਾਲੀ *bt_ਅੰਕੜੇ;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    ਪੂਰਨ rt_ਅੰਕ_callers;
#ਜੇ_ਅੰਤ

    /* benchmark info */
    ਪੂਰਨ ਕੁੱਲ_idents;
    ਪੂਰਨ ਕੁੱਲ_ਸਤਰਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਕੁੱਲ_ਬਾਈਟਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਕੁੱਲ_output[4];

    /* used by tcc_load_ldscript */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ਅਚਲ ਅੱਖਰ *current_filename;

    /* used by main and tcc_parse_args only */
    ਬਣਤਰ filespec **files; /* files seen on command line */
    ਪੂਰਨ nb_files; /* number thereof */
    ਪੂਰਨ nb_libraries; /* number of libs thereof */
    ਅੱਖਰ *outfile; /* output filename */
    ਅੱਖਰ *deps_outfile; /* option -MF */
    ਪੂਰਨ argc;
    ਅੱਖਰ **argv;
    /* -Wl options */
    ਅੱਖਰ **link_argv;
    ਪੂਰਨ link_argc, link_optind;
};

ਬਣਤਰ filespec {
    ਅੱਖਰ type;
    ਅੱਖਰ name[1];
};

/* The current value can be: */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_VALMASK   0x003f  /* mask for value location, register or: */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_LOCAL     0x0032  /* offset on stack */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_LVAL      0x0100  /* var is an lvalue */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_SYM       0x0200  /* a symbol value is added */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_BTYPE       0x000f  /* mask for basic type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_VOID             0  /* void type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_BYTE             1  /* signed byte type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_SHORT            2  /* short type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_INT              3  /* integer type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_LLONG            4  /* 64 bit integer */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_PTR              5  /*ਸੂਚਕ*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_FUNC             6  /* function type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_STRUCT           7  /* struct/union definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_FLOAT            8  /* IEEE float */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_DOUBLE           9  /* IEEE double */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_LDOUBLE         10  /* IEEE long double */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_BOOL            11  /* ISOC99 boolean type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_UNSIGNED    0x0010  /* unsigned type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_BITFIELD    0x0080  /* bitfield modifier */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_CONSTANT    0x0100  /* const modifier */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_VOLATILE    0x0200  /* volatile modifier */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_RESTRICT    0x0400  /* restrict modifier */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_EXTERN  0x00002000  /* extern definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_STATIC  0x00004000  /* static variable */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_TYPEDEF 0x00008000  /* typedef definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_INLINE  0x00010000  /* inline definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_STRUCT_ਖਿਸਕਾਓ 20     /* shift for bitfield shift values (32 - 2*6) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_STRUCT_ਨਕਾਬ (((1U << (6+6)) - 1) << VT_STRUCT_ਖਿਸਕਾਓ | VT_BITFIELD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_POS(t) (((t) >> VT_STRUCT_ਖਿਸਕਾਓ) & 0x3f)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_ਮਾਪ(t) (((t) >> (VT_STRUCT_ਖਿਸਕਾਓ + 6)) & 0x3f)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_UNION    (1 << VT_STRUCT_ਖਿਸਕਾਓ | VT_STRUCT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ENUM     (2 << VT_STRUCT_ਖਿਸਕਾਓ) /* integral type is an enum really */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ENUM_VAL (3 << VT_STRUCT_ਖਿਸਕਾਓ) /* integral type is an enum constant really */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ENUM(t) ((t & VT_STRUCT_ਨਕਾਬ) == VT_ENUM)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ENUM_VAL(t) ((t & VT_STRUCT_ਨਕਾਬ) == VT_ENUM_VAL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_UNION(t) ((t & (VT_STRUCT_ਨਕਾਬ|VT_BTYPE)) == VT_UNION)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_TYPE (~(VT_STORAGE|VT_STRUCT_ਨਕਾਬ))

/* symbol was created by tccasm.c first */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ASM (VT_VOID | 4 << VT_STRUCT_ਖਿਸਕਾਓ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_ਖਿਸਕਾਓ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_ਨਕਾਬ) & ~(1<<VT_STRUCT_ਖਿਸਕਾਓ))) == VT_ASM)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_ਨਕਾਬ)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VT_BT_ARRAY (6 << VT_STRUCT_ਖਿਸਕਾਓ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_BT_ARRAY(t) ((t & VT_STRUCT_ਨਕਾਬ) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BFVAL(M,N) ((ਬਿਨਾਨਿਸ਼ਾਨੀ)((M) & ~((M) << 1)) * (N))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LAND  0x90
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ULT 0x92
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_UGE 0x93
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_EQ  0x94
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_NE  0x95
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ULE 0x96
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_UGT 0x97
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_Nset 0x98
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_Nclear 0x99
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LT  0x9c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_GE  0x9d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LE  0x9e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_GT  0x9f

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_DEC     0x80 /* -- */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_MID     0x81 /* inc/dec, to void constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_INC     0x82 /* ++ */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_UDIV    0x83 /* unsigned division */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_UMOD    0x84 /* unsigned modulo */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ADDC1   0x87 /* add with carry generation */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ADDC2   0x88 /* add with carry use */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_SUBC1   0x89 /* add with carry generation */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_SUBC2   0x8a /* add with carry use */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_SHL     '<' /* shift left */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_SAR     '>' /* signed shift right */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_SHR     0x8b /* unsigned shift right */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ARROW   0xa0 /* -> */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_DOTS    0xa1 /* three dots */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_TWODOTS 0xa2 /* C++ token ? */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_PPJOIN  (TOK_TWOSHARPS | SYM_ਖੇਤਰ) /* A '##' in a macro to mean pasting */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_ਜੋੜੋ   0xb0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_SUB   0xb1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_MUL   0xb2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_DIV   0xb3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_MOD   0xb4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_AND   0xb5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_OR    0xb6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_XOR   0xb7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_SHL   0xb8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_A_SAR   0xb9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ਸੌਂਪੋ(t) (t >= TOK_A_ਜੋੜੋ && t <= TOK_A_SAR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_ਸੌਂਪੋ_OP(t) ("+-*/%&|^<>"[t - TOK_A_ਜੋੜੋ])

/* tokens that carry values (in additional token string space / tokc) --> */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CCHAR   0xc0 /* char constant in tokc */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LCHAR   0xc1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CINT    0xc2 /* number in tokc */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CUINT   0xc3 /* unsigned int constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CLLONG  0xc4 /* long long constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CULLONG 0xc5 /* unsigned long long constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CLONG   0xc6 /* long constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CULONG  0xc7 /* unsigned long constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_STR     0xc8 /* pointer to string in tokc */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LSTR    0xc9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CFLOAT  0xca /* float constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CDOUBLE 0xcb /* double constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_CLDOUBLE 0xcc /* long double constant */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_PPNUM   0xcd /* preprocessor number */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_PPSTR   0xce /* preprocessor string */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LINENUM 0xcf /* line number info */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_HAS_ਮੁੱਲ(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_EOF       (-1)  /* end of file */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_IDENT 256

ਗਿਣਤੀ tcc_token {
    TOK_ਆਖਰੀ = TOK_IDENT - 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF(id, str) ,id
#ਅਨ੍ਤਰ੍ਭਾਵ "tcctok.h"
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_ਅੰਕੜੇ ਬਣਤਰ TCCState *tcc_state;
ST_ਅੰਕੜੇ ਖਾਲੀ** stk_ਅੰਕੜੇ;
ST_ਅੰਕੜੇ ਪੂਰਨ nb_stk_ਅੰਕੜੇ;
ST_ਅੰਕੜੇ ਪੂਰਨ g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC ਅੱਖਰ *pstrcpy(ਅੱਖਰ *buf, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s);
ST_FUNC ਅੱਖਰ *pstrcat(ਅੱਖਰ *buf, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s);
ST_FUNC ਅੱਖਰ *pstrncpy(ਅੱਖਰ *ਬਾਹਰਲਾ, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s, ਮਾਪ_t ਅੰਕ);
PUB_FUNC ਅੱਖਰ *tcc_basename(ਅਚਲ ਅੱਖਰ *name);
PUB_FUNC ਅੱਖਰ *tcc_fileextension (ਅਚਲ ਅੱਖਰ *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC ਖਾਲੀ tcc_free(ਖਾਲੀ *ptr);
PUB_FUNC ਖਾਲੀ *tcc_malloc(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
PUB_FUNC ਖਾਲੀ *tcc_mallocz(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
PUB_FUNC ਖਾਲੀ *tcc_realloc(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
PUB_FUNC ਅੱਖਰ *tcc_strdup(ਅਚਲ ਅੱਖਰ *str);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ MEM_DEBUG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_free(ptr)           tcc_free_debug(ptr)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_malloc(ਮਾਪ)        tcc_malloc_debug(ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_mallocz(ਮਾਪ)       tcc_mallocz_debug(ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_realloc(ptr,ਮਾਪ)   tcc_realloc_debug(ptr, ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC ਖਾਲੀ tcc_free_debug(ਖਾਲੀ *ptr);
PUB_FUNC ਖਾਲੀ *tcc_malloc_debug(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ);
PUB_FUNC ਖਾਲੀ *tcc_mallocz_debug(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ);
PUB_FUNC ਖਾਲੀ *tcc_realloc_debug(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ);
PUB_FUNC ਅੱਖਰ *tcc_strdup_debug(ਅਚਲ ਅੱਖਰ *str, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ);
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ libc_free(ਖਾਲੀ *ptr);
/* defined to be not used */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮੁਕਤ(p) use_tcc_free(p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_ਦਿਓ(s) use_tcc_malloc(s)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ realloc(p, s) use_tcc_realloc(p, s)
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ strdup
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ strdup(s) use_tcc_strdup(s)
PUB_FUNC ਪੂਰਨ _tcc_error_noabort(ਅਚਲ ਅੱਖਰ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN ਖਾਲੀ _tcc_error(ਅਚਲ ਅੱਖਰ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC ਖਾਲੀ _tcc_warning(ਅਚਲ ਅੱਖਰ *fmt, ...) PRINTF_LIKE(1,2);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_ਅੰਦਰੂਨੀ_error(ਸੁਨੇਹਾ) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,ਸੁਨੇਹਾ)

/* other utilities */
ST_FUNC ਖਾਲੀ dynarray_ਜੋੜੋ(ਖਾਲੀ *ptab, ਪੂਰਨ *nb_ptr, ਖਾਲੀ *ਅੰਕੜੇ);
ST_FUNC ਖਾਲੀ dynarray_reset(ਖਾਲੀ *pp, ਪੂਰਨ *n);
ST_INLN ਖਾਲੀ cstr_ccat(CString *cstr, ਪੂਰਨ ch);
ST_FUNC ਖਾਲੀ cstr_cat(CString *cstr, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ len);
ST_FUNC ਖਾਲੀ cstr_wccat(CString *cstr, ਪੂਰਨ ch);
ST_FUNC ਖਾਲੀ cstr_new(CString *cstr);
ST_FUNC ਖਾਲੀ cstr_free(CString *cstr);
ST_FUNC ਪੂਰਨ cstr_printf(CString *cs, ਅਚਲ ਅੱਖਰ *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC ਪੂਰਨ cstr_vprintf(CString *cstr, ਅਚਲ ਅੱਖਰ *fmt, va_list ap);
ST_FUNC ਖਾਲੀ cstr_reset(CString *cstr);
ST_FUNC ਖਾਲੀ tcc_open_bf(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ initlen);
ST_FUNC ਪੂਰਨ tcc_open(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename);
ST_FUNC ਖਾਲੀ tcc_close(ਖਾਲੀ);

/* mark a memory pointer on stack for cleanup after errors */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stk_ਧੱਕੋ(p) dynarray_ਜੋੜੋ(&stk_ਅੰਕੜੇ, &nb_stk_ਅੰਕੜੇ, p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stk_ਕੱਢੋ() (--nb_stk_ਅੰਕੜੇ)
/* mark CString on stack for cleanup errors */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ cstr_new_s(cstr) (cstr_new(cstr), stk_ਧੱਕੋ(&(cstr)->ਅੰਕੜੇ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ cstr_free_s(cstr) (cstr_free(cstr), stk_ਕੱਢੋ())

ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_file_ਅੰਦਰੂਨੀ(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flags);
/* flags: */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_PRINT_ERROR     0x10 /* print error if file not found */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_BIN        0x40 /* file to add is binary */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_ਸਾਰਾ_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_NONE   0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_C      1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_ASM    2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_ASMPP  4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_LIB    8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_TYPE_ਨਕਾਬ   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_BINTYPE_REL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_BINTYPE_DYN 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_BINTYPE_AR  3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOT_ਮਿਲਿਆ -2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_crt(TCCState *s, ਅਚਲ ਅੱਖਰ *filename);
#ਜੇ_ਅੰਤ
ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_dll(TCCState *s, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flags);
ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_support(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_bcheck(TCCState *s1);
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_btstub(TCCState *s1);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_pragma_libs(TCCState *s1);
PUB_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_library_err(TCCState *s, ਅਚਲ ਅੱਖਰ *f);
PUB_FUNC ਖਾਲੀ tcc_print_stats(TCCState *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਕੁੱਲ_ਸਮਾਂ);
PUB_FUNC ਪੂਰਨ tcc_parse_ਦਲੀਲਾਂ(TCCState *s, ਪੂਰਨ *argc, ਅੱਖਰ ***argv);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
ST_FUNC ਅੱਖਰ *normalize_slashes(ਅੱਖਰ *ਰਸਤਾ);
PUB_FUNC FILE *tcc_fopen(ਅਚਲ ਅੱਖਰ *f, ਅਚਲ ਅੱਖਰ *m);
PUB_FUNC ਪੂਰਨ tcc_fclose(FILE *f);
#ਨਹੀਂਤਾਂ
# define tcc_fopen fopen
# define tcc_fclose fclose
#ਜੇ_ਅੰਤ
ST_FUNC DLLReference *tcc_ਜੋੜੋ_dllref(TCCState *s1, ਅਚਲ ਅੱਖਰ *dllname, ਪੂਰਨ level);
ST_FUNC ਅੱਖਰ *tcc_ਲੱਦੋ_ਪਾਠ(ਪੂਰਨ fd);
/* for #pragma once */
ST_FUNC ਪੂਰਨ normalized_PATHCMP(ਅਚਲ ਅੱਖਰ *f1, ਅਚਲ ਅੱਖਰ *f2);

/* tcc_parse_args return codes: */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_HELP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_HELP2 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_V 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_PRINT_DIRS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_AR 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_IMPDEF 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_M32 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_ਅੰਕੜੇ ਬਣਤਰ BufferedFile *file;
ST_ਅੰਕੜੇ ਪੂਰਨ tok;
ST_ਅੰਕੜੇ CValue tokc;
ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ *macro_ptr;
ST_ਅੰਕੜੇ ਪੂਰਨ parse_flags;
ST_ਅੰਕੜੇ ਪੂਰਨ tok_flags;
ST_ਅੰਕੜੇ CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_ਅੰਕੜੇ ਪੂਰਨ tok_ident;
ST_ਅੰਕੜੇ TokenSym **ਸਾਰਣੀ_ident;
ST_ਅੰਕੜੇ ਪੂਰਨ pp_ਵਿਅੰਜਕ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_FLAG_BOL   0x0001 /* beginning of line before */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_FLAG_BOF   0x0002 /* beginning of file before */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_TOK_ਅੰਕ    0x0002 /* return numbers instead of TOK_PPNUM */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_SPC 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ID  2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਅੰਕ 4

ਗਿਣਤੀ ਸਤਰ_macro_output_format {
    ਸਤਰ_MACRO_OUTPUT_FORMAT_GCC,
    ਸਤਰ_MACRO_OUTPUT_FORMAT_NONE,
    ਸਤਰ_MACRO_OUTPUT_FORMAT_STD,
    ਸਤਰ_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ len);
ST_FUNC ਪੂਰਨ tok_alloc_const(ਅਚਲ ਅੱਖਰ *str);
ST_FUNC ਅਚਲ ਅੱਖਰ *get_tok_str(ਪੂਰਨ v, CValue *cv);
ST_FUNC ਖਾਲੀ begin_macro(TokenString *str, ਪੂਰਨ alloc);
ST_FUNC ਖਾਲੀ ਸਿਰਾ_macro(ਖਾਲੀ);
ST_FUNC ਪੂਰਨ ਸੈੱਟ_idnum(ਪੂਰਨ c, ਪੂਰਨ val);
ST_INLN ਖਾਲੀ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ tok_str_free(TokenString *s);
ST_FUNC ਖਾਲੀ tok_str_free_str(ਪੂਰਨ *str);
ST_FUNC ਖਾਲੀ tok_str_ਜੋੜੋ(TokenString *s, ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ tok_str_ਜੋੜੋ_tok(TokenString *s);
ST_INLN ਖਾਲੀ define_ਧੱਕੋ(ਪੂਰਨ v, ਪੂਰਨ macro_type, ਪੂਰਨ *str, Sym *ਪਹਿਲਾ_arg);
ST_FUNC ਖਾਲੀ define_undef(Sym *s);
ST_INLN Sym *define_ਲੱਭੋ(ਪੂਰਨ v);
ST_FUNC ਖਾਲੀ free_ਨਿਰਧਾਰਤ_ਕਰਦਾ(Sym *b);
ST_FUNC ਖਾਲੀ parse_define(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ skip_ਮੰਜ਼ਿਲ_eol(ਪੂਰਨ warn);
ST_FUNC ਖਾਲੀ preprocess(ਪੂਰਨ is_bof);
ST_FUNC ਖਾਲੀ ਅਗਲਾ(ਖਾਲੀ);
ST_INLN ਖਾਲੀ unget_tok(ਪੂਰਨ ਆਖਰੀ_tok);
ST_FUNC ਖਾਲੀ preprocess_ਸ਼ੁਰੂ(TCCState *s1, ਪੂਰਨ filetype);
ST_FUNC ਖਾਲੀ preprocess_ਸਿਰਾ(TCCState *s1);
ST_FUNC ਖਾਲੀ tccpp_new(TCCState *s);
ST_FUNC ਖਾਲੀ tccpp_delete(TCCState *s);
ST_FUNC ਖਾਲੀ tccpp_putfile(ਅਚਲ ਅੱਖਰ *filename);
ST_FUNC ਪੂਰਨ tcc_preprocess(TCCState *s1);
ST_FUNC ਖਾਲੀ skip(ਪੂਰਨ c);
ST_FUNC NORETURN ਖਾਲੀ expect(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ);
ST_FUNC ਖਾਲੀ pp_error(CString *cs);


/* space excluding newline */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ is_space(ਪੂਰਨ ch) {
    ਵਾਪਸ ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ isid(ਪੂਰਨ c) {
    ਵਾਪਸ (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ isnum(ਪੂਰਨ c) {
    ਵਾਪਸ c >= '0' && c <= '9';
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ isoct(ਪੂਰਨ c) {
    ਵਾਪਸ c >= '0' && c <= '7';
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ toup(ਪੂਰਨ c) {
    ਵਾਪਸ (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYM_POOL_NB (8192 / ਆਕਾਰ(Sym))

ST_ਅੰਕੜੇ Sym *global_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *local_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *local_label_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *global_label_ਢੇਰ;
ST_ਅੰਕੜੇ Sym *define_ਢੇਰ;
ST_ਅੰਕੜੇ CType int_type, func_old_type, char_ਸੂਚਕ_type;
ST_ਅੰਕੜੇ SValue *vtop;
ST_ਅੰਕੜੇ ਪੂਰਨ rsym, anon_sym, ind, loc;
ST_ਅੰਕੜੇ ਅੱਖਰ debug_modes;

ST_ਅੰਕੜੇ ਪੂਰਨ nocode_wanted; /* true if no code generation wanted for an expression */
ST_ਅੰਕੜੇ ਪੂਰਨ global_ਵਿਅੰਜਕ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_ਅੰਕੜੇ CType func_vt; /* current function return type (used by return instruction) */
ST_ਅੰਕੜੇ ਪੂਰਨ func_var; /* true if current function is variadic */
ST_ਅੰਕੜੇ ਪੂਰਨ func_vc; /* stack address for implicit struct return storage */
ST_ਅੰਕੜੇ ਪੂਰਨ func_ind; /* function start address */
ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ *funcname;

ST_FUNC ਖਾਲੀ tccgen_init(TCCState *s1);
ST_FUNC ਪੂਰਨ tccgen_compile(TCCState *s1);
ST_FUNC ਖਾਲੀ tccgen_ਅੰਤ(TCCState *s1);
ST_FUNC ਖਾਲੀ check_vstack(ਖਾਲੀ);

ST_INLN ਪੂਰਨ is_float(ਪੂਰਨ t);
ST_FUNC ਪੂਰਨ ieee_finite(ਦੁੱਗਣਾ d);
ST_FUNC ਪੂਰਨ exact_log2p1(ਪੂਰਨ i);
ST_FUNC ਖਾਲੀ test_lvalue(ਖਾਲੀ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC ਖਾਲੀ update_storage(Sym *sym);
ST_FUNC ਖਾਲੀ put_extern_sym2(Sym *sym, ਪੂਰਨ sh_ਅੰਕ, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਪੂਰਨ can_ਜੋੜੋ_underscore);
ST_FUNC ਖਾਲੀ put_extern_sym(Sym *sym, Section *section, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
#ਜੇ PTR_ਮਾਪ == 4
ST_FUNC ਖਾਲੀ greloc(Section *s, Sym *sym, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਪੂਰਨ type);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ greloca(Section *s, Sym *sym, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਪੂਰਨ type, addr_t addend);

ST_INLN ਖਾਲੀ sym_free(Sym *sym);
ST_FUNC Sym *sym_ਧੱਕੋ(ਪੂਰਨ v, CType *type, ਪੂਰਨ r, ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ sym_ਕੱਢੋ(Sym **ptop, Sym *b, ਪੂਰਨ keep);
ST_FUNC Sym *sym_push2(Sym **ps, ਪੂਰਨ v, ਪੂਰਨ t, ਪੂਰਨ c);
ST_FUNC Sym *sym_find2(Sym *s, ਪੂਰਨ v);
ST_INLN Sym *sym_ਲੱਭੋ(ਪੂਰਨ v);
ST_FUNC Sym *label_ਲੱਭੋ(ਪੂਰਨ v);
ST_FUNC Sym *label_ਧੱਕੋ(Sym **ptop, ਪੂਰਨ v, ਪੂਰਨ flags);
ST_FUNC ਖਾਲੀ label_ਕੱਢੋ(Sym **ptop, Sym *slast, ਪੂਰਨ keep);
ST_INLN Sym *struct_ਲੱਭੋ(ਪੂਰਨ v);

ST_FUNC Sym *global_identifier_ਧੱਕੋ(ਪੂਰਨ v, ਪੂਰਨ t, ਪੂਰਨ c);
ST_FUNC Sym *external_global_sym(ਪੂਰਨ v, CType *type);
ST_FUNC Sym *external_helper_sym(ਪੂਰਨ v);
ST_FUNC ਖਾਲੀ vpush_helper_func(ਪੂਰਨ v);
ST_FUNC ਖਾਲੀ vset(CType *type, ਪੂਰਨ r, ਪੂਰਨ v);
ST_FUNC ਖਾਲੀ vset_VT_CMP(ਪੂਰਨ op);
ST_FUNC ਖਾਲੀ vpushi(ਪੂਰਨ v);
ST_FUNC ਖਾਲੀ vpushv(SValue *v);
ST_FUNC ਖਾਲੀ vpushsym(CType *type, Sym *sym);
ST_FUNC ਖਾਲੀ vswap(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ vrott(ਪੂਰਨ n);
ST_FUNC ਖਾਲੀ vrotb(ਪੂਰਨ n);
ST_FUNC ਖਾਲੀ vrev(ਪੂਰਨ n);
ST_FUNC ਖਾਲੀ vpop(ਖਾਲੀ);
#ਜੇ PTR_ਮਾਪ == 4
ST_FUNC ਖਾਲੀ lexpand(ਖਾਲੀ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
ST_FUNC ਪੂਰਨ get_reg_ex(ਪੂਰਨ rc, ਪੂਰਨ rc2);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ save_reg(ਪੂਰਨ r);
ST_FUNC ਖਾਲੀ save_reg_upstack(ਪੂਰਨ r, ਪੂਰਨ n);
ST_FUNC ਪੂਰਨ get_reg(ਪੂਰਨ rc);
ST_FUNC ਖਾਲੀ save_regs(ਪੂਰਨ n);
ST_FUNC ਖਾਲੀ gaddrof(ਖਾਲੀ);
ST_FUNC ਪੂਰਨ gv(ਪੂਰਨ rc);
ST_FUNC ਖਾਲੀ gv2(ਪੂਰਨ rc1, ਪੂਰਨ rc2);
ST_FUNC ਖਾਲੀ gen_op(ਪੂਰਨ op);
ST_FUNC ਪੂਰਨ type_ਮਾਪ(CType *type, ਪੂਰਨ *a);
ST_FUNC ਖਾਲੀ mk_ਸੂਚਕ(CType *type);
ST_FUNC ਖਾਲੀ vstore(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ inc(ਪੂਰਨ post, ਪੂਰਨ c);
ST_FUNC CString* parse_mult_str(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ);
ST_FUNC CString* parse_asm_str(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ indir(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ unary(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gexpr(ਖਾਲੀ);
ST_FUNC ਪੂਰਨ ਵਿਅੰਜਕ_const(ਖਾਲੀ);
#ਜੇ defined CONFIG_TCC_BCHECK || defined TCC_ਨਿਸ਼ਾਨਾ_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
#ਜੇ_ਅੰਤ
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 && !defined TCC_ਨਿਸ਼ਾਨਾ_PE
ST_FUNC ਪੂਰਨ classify_x86_64_va_arg(CType *ty);
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
ST_FUNC ਖਾਲੀ gbound_ਦਲੀਲਾਂ(ਪੂਰਨ nb_ਦਲੀਲਾਂ);
ST_ਅੰਕੜੇ ਪੂਰਨ func_bound_ਜੋੜੋ_epilog;
#ਜੇ_ਅੰਤ
ST_FUNC Sym *gfunc_ਸੈੱਟ_param(Sym *s, ਪੂਰਨ c, ਪੂਰਨ byref);

/* ------------ tccelf.c ------------ */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_FORMAT_ਦੁਆਧਾਰੀ 1 /* binary image output */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ n_strx;         /* index into string table of name */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ n_type;         /* type of symbol */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ n_other;        /* misc info (usually empty) */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ n_desc;        /* description field */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ n_ਮੁੱਲ;        /* value of symbol */
} Stab_Sym;

ST_FUNC ਖਾਲੀ tccelf_new(TCCState *s);
ST_FUNC ਖਾਲੀ tccelf_delete(TCCState *s);
ST_FUNC ਖਾਲੀ tccelf_begin_file(TCCState *s1);
ST_FUNC ਖਾਲੀ tccelf_ਸਿਰਾ_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, ਪੂਰਨ sh_type, ਪੂਰਨ sh_flags);
ST_FUNC ਖਾਲੀ section_realloc(Section *sec, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ new_ਮਾਪ);
ST_FUNC ਮਾਪ_t section_ਜੋੜੋ(Section *sec, addr_t ਮਾਪ, ਪੂਰਨ align);
ST_FUNC ਖਾਲੀ *section_ptr_ਜੋੜੋ(Section *sec, addr_t ਮਾਪ);
ST_FUNC Section *ਲੱਭੋ_section(TCCState *s1, ਅਚਲ ਅੱਖਰ *name);
ST_FUNC ਖਾਲੀ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ਅਚਲ ਅੱਖਰ *symtab_name, ਪੂਰਨ sh_type, ਪੂਰਨ sh_flags, ਅਚਲ ਅੱਖਰ *strtab_name, ਅਚਲ ਅੱਖਰ *hash_name, ਪੂਰਨ hash_sh_flags);
ST_FUNC ਖਾਲੀ init_symtab(Section *s);

ST_FUNC ਪੂਰਨ put_elf_str(Section *s, ਅਚਲ ਅੱਖਰ *sym);
ST_FUNC ਪੂਰਨ put_elf_sym(Section *s, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਪੂਰਨ info, ਪੂਰਨ other, ਪੂਰਨ shndx, ਅਚਲ ਅੱਖਰ *name);
ST_FUNC ਪੂਰਨ ਸੈੱਟ_elf_sym(Section *s, addr_t ਮੁੱਲ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਪੂਰਨ info, ਪੂਰਨ other, ਪੂਰਨ shndx, ਅਚਲ ਅੱਖਰ *name);
ST_FUNC ਪੂਰਨ ਲੱਭੋ_elf_sym(Section *s, ਅਚਲ ਅੱਖਰ *name);
ST_FUNC ਖਾਲੀ put_elf_reloc(Section *symtab, Section *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਪੂਰਨ type, ਪੂਰਨ ਚਿੰਨ੍ਹ);
ST_FUNC ਖਾਲੀ put_elf_reloca(Section *symtab, Section *s, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਵਿੱਥ, ਪੂਰਨ type, ਪੂਰਨ ਚਿੰਨ੍ਹ, addr_t addend);

ST_FUNC ਖਾਲੀ resolve_common_syms(TCCState *s1);
ST_FUNC ਖਾਲੀ relocate_syms(TCCState *s1, Section *symtab, ਪੂਰਨ do_resolve);
ST_FUNC ਖਾਲੀ relocate_sections(TCCState *s1);

ST_FUNC ssize_t ਭਰਿਆ_read(ਪੂਰਨ fd, ਖਾਲੀ *buf, ਮਾਪ_t ਗਿਣਤੀ_3);
ST_FUNC ਖਾਲੀ *ਲੱਦੋ_ਅੰਕੜੇ(ਪੂਰਨ fd, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ file_ਵਿੱਥ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ);
ST_FUNC ਪੂਰਨ tcc_object_type(ਪੂਰਨ fd, ElfW(Ehdr) *h);
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_object_file(TCCState *s1, ਪੂਰਨ fd, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ file_ਵਿੱਥ);
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_archive(TCCState *s1, ਪੂਰਨ fd, ਪੂਰਨ alacarte);
ST_FUNC ਖਾਲੀ ਜੋੜੋ_array(TCCState *s1, ਅਚਲ ਅੱਖਰ *sec, ਪੂਰਨ c);

ST_FUNC ਬਣਤਰ sym_attr *get_sym_attr(TCCState *s1, ਪੂਰਨ ਸੂਚਕਾਂਕ, ਪੂਰਨ alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ਅਚਲ ਅੱਖਰ *name, ਪੂਰਨ err, ਪੂਰਨ forc);
ST_FUNC ਖਾਲੀ list_elf_symbols(TCCState *s, ਖਾਲੀ *ctx,
    ਖਾਲੀ (*ਚਿੰਨ੍ਹ_cb)(ਖਾਲੀ *ctx, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਖਾਲੀ *val));
ST_FUNC ਪੂਰਨ ਸੈੱਟ_global_sym(TCCState *s1, ਅਚਲ ਅੱਖਰ *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ for_each_elem(sec, startoff, elem, type) \
    ਲਈ (elem = (type *) sec->ਅੰਕੜੇ + startoff; \
         elem < (type *) (sec->ਅੰਕੜੇ + sec->ਅੰਕੜੇ_ਵਿੱਥ); elem++)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ELF_OBJ_ONLY
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_dll(TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ level);
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_ldscript(TCCState *s1, ਪੂਰਨ fd);
ST_FUNC ਖਾਲੀ tccelf_ਜੋੜੋ_crtbegin(TCCState *s1);
ST_FUNC ਖਾਲੀ tccelf_ਜੋੜੋ_crtend(TCCState *s1);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_runtime(TCCState *s1);
#ਜੇ_ਅੰਤ

/* ------------ xxx-link.c ------------ */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ST_FUNC ਪੂਰਨ ਕੋਡ_reloc (ਪੂਰਨ reloc_type);
ST_FUNC ਪੂਰਨ gotplt_ਇੰਦਰਾਜ_type (ਪੂਰਨ reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
ਗਿਣਤੀ gotplt_ਇੰਦਰਾਜ {
    NO_GOTPLT_ਇੰਦਰਾਜ,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ਇੰਦਰਾਜ,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ਇੰਦਰਾਜ	/* always generate (eg. PLTOFF relocs) */
};
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NEED_RELOC_TYPE
#ਜੇ !defined TCC_ਨਿਸ਼ਾਨਾ_MACHO || defined TCC_IS_NATIVE
ST_FUNC ਬਿਨਾਨਿਸ਼ਾਨੀ create_plt_ਇੰਦਰਾਜ(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ got_ਵਿੱਥ, ਬਣਤਰ sym_attr *attr);
ST_FUNC ਖਾਲੀ relocate_plt(TCCState *s1);
ST_FUNC ਖਾਲੀ build_got_entries(TCCState *s1, ਪੂਰਨ got_sym); /* in tccelf.c */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NEED_BUILD_GOT
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ relocate(TCCState *s1, ElfW_Rel *rel, ਪੂਰਨ type, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_ਅੰਕੜੇ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_machine_defs;
ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ reg_classes[NB_REGS];

ST_FUNC ਖਾਲੀ gsym_addr(ਪੂਰਨ t, ਪੂਰਨ a);
ST_FUNC ਖਾਲੀ gsym(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ ਲੱਦੋ(ਪੂਰਨ r, SValue *sv);
ST_FUNC ਖਾਲੀ store(ਪੂਰਨ r, SValue *v);
ST_FUNC ਪੂਰਨ gfunc_sret(CType *vt, ਪੂਰਨ variadic, CType *ret, ਪੂਰਨ *align, ਪੂਰਨ *regsize);
ST_FUNC ਖਾਲੀ gfunc_call(ਪੂਰਨ nb_ਦਲੀਲਾਂ);
ST_FUNC ਖਾਲੀ gfunc_prolog(Sym *func_sym);
ST_FUNC ਖਾਲੀ gfunc_epilog(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gen_fill_nops(ਪੂਰਨ);
ST_FUNC ਪੂਰਨ gjmp(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gjmp_addr(ਪੂਰਨ a);
ST_FUNC ਪੂਰਨ gjmp_cond(ਪੂਰਨ op, ਪੂਰਨ t);
ST_FUNC ਪੂਰਨ gjmp_append(ਪੂਰਨ n, ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gen_opi(ਪੂਰਨ op);
ST_FUNC ਖਾਲੀ gen_opf(ਪੂਰਨ op);
ST_FUNC ਖਾਲੀ gen_cvt_ftoi(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gen_cvt_itof(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gen_cvt_ftof(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ ggoto(ਖਾਲੀ);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_C67
ST_FUNC ਖਾਲੀ o(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ c);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ gen_vla_sp_save(ਪੂਰਨ addr);
ST_FUNC ਖਾਲੀ gen_vla_sp_restore(ਪੂਰਨ addr);
ST_FUNC ਖਾਲੀ gen_vla_alloc(CType *type, ਪੂਰਨ align);

ਸਥਿਰ ਸਤਰਅੰਦਰ uint16_t read16le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p) {
    ਵਾਪਸ p[0] | (uint16_t)p[1] << 8;
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ write16le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ਸਥਿਰ ਸਤਰਅੰਦਰ uint32_t read32le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p) {
  ਵਾਪਸ read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ write32le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ add32le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ਸਥਿਰ ਸਤਰਅੰਦਰ uint64_t read64le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p) {
  ਵਾਪਸ read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ write64le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ add64le(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64 || defined TCC_ਨਿਸ਼ਾਨਾ_ARM
ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le16(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le32(ਪੂਰਨ c);
#ਜੇ_ਅੰਤ
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
ST_FUNC ਖਾਲੀ gen_addr32(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_addrpc32(ਪੂਰਨ r, Sym *sym, ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv);
#ਜੇ_ਅੰਤ

/* ------------ x86_64-gen.c ------------ */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
ST_FUNC ਖਾਲੀ gen_opl(ਪੂਰਨ op);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ST_FUNC ਖਾਲੀ gen_vla_ਨਤੀਜਾ(ਪੂਰਨ addr);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ gen_cvt_sxtw(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t);
#ਜੇ_ਅੰਤ

/* ------------ arm-gen.c ------------ */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
#ਜੇ defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ਅਚਲ ਅੱਖਰ *default_elfinterp(ਬਣਤਰ TCCState *s);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ arm_init(ਬਣਤਰ TCCState *s);
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv);
#ਜੇ_ਅੰਤ

/* ------------ arm64-gen.c ------------ */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM64
ST_FUNC ਖਾਲੀ gen_opl(ਪੂਰਨ op);
ST_FUNC ਖਾਲੀ gfunc_return(CType *func_type);
ST_FUNC ਖਾਲੀ gen_va_ਸ਼ੁਰੂ(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gen_va_arg(CType *t);
ST_FUNC ਖਾਲੀ gen_clear_cache(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gen_cvt_sxtw(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv);
#ਜੇ_ਅੰਤ

/* ------------ riscv64-gen.c ------------ */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_RISCV64
ST_FUNC ਖਾਲੀ gen_opl(ਪੂਰਨ op);
ST_FUNC ਖਾਲੀ gen_va_ਸ਼ੁਰੂ(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ arch_transfer_ret_regs(ਪੂਰਨ);
ST_FUNC ਖਾਲੀ gen_cvt_sxtw(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ gen_cvt_csti(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ gen_increment_tcov (SValue *sv);
ST_FUNC ਖਾਲੀ gen_clear_cache(ਖਾਲੀ);
#ਜੇ_ਅੰਤ

/* ------------ c67-gen.c ------------ */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_C67
#ਜੇ_ਅੰਤ

/* ------------ tcccoff.c ------------ */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_COFF
ST_FUNC ਪੂਰਨ tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC ਪੂਰਨ tcc_ਲੱਦੋ_coff(TCCState * s1, ਪੂਰਨ fd);
#ਜੇ_ਅੰਤ

/* ------------ tccasm.c ------------ */
ST_FUNC ਖਾਲੀ asm_instr(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ asm_global_instr(ਖਾਲੀ);
ST_FUNC ਪੂਰਨ tcc_assemble(TCCState *s1, ਪੂਰਨ do_preprocess);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_ASM
ST_FUNC ਪੂਰਨ ਲੱਭੋ_constraint(ASMOperand *operands, ਪੂਰਨ nb_operands, ਅਚਲ ਅੱਖਰ *name, ਅਚਲ ਅੱਖਰ **pp);
ST_FUNC Sym* get_asm_sym(ਪੂਰਨ name, Sym *csym);
ST_FUNC ਖਾਲੀ asm_ਵਿਅੰਜਕ(TCCState *s1, ਵਿਅੰਜਕ_ਮੁੱਲ *pe);
ST_FUNC ਪੂਰਨ asm_int_ਵਿਅੰਜਕ(TCCState *s1);
#ਜੇ PTR_ਮਾਪ == 8
ST_FUNC ਖਾਲੀ gen_expr64(ਵਿਅੰਜਕ_ਮੁੱਲ *pe);
#ਜੇ_ਅੰਤ
/* ------------ i386-asm.c ------------ */
ST_FUNC ਖਾਲੀ gen_expr32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe);
ST_FUNC ਖਾਲੀ asm_opcode(TCCState *s1, ਪੂਰਨ opcode);
ST_FUNC ਪੂਰਨ asm_parse_regvar(ਪੂਰਨ t);
ST_FUNC ਖਾਲੀ asm_compute_constraints(ASMOperand *operands, ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs, ਅਚਲ uint8_t *clobber_regs, ਪੂਰਨ *pout_reg);
ST_FUNC ਖਾਲੀ subst_asm_ਸੰਕਾਰਜ(CString *ਜੋੜੋ_str, SValue *sv, ਪੂਰਨ modifier);
ST_FUNC ਖਾਲੀ asm_gen_ਕੋਡ(ASMOperand *operands, ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs, ਪੂਰਨ is_output, uint8_t *clobber_regs, ਪੂਰਨ ਬਾਹਰਲਾ_reg);
ST_FUNC ਖਾਲੀ asm_clobber(uint8_t *clobber_regs, ਅਚਲ ਅੱਖਰ *str);
#ਜੇ_ਅੰਤ

/* ------------ tccpe.c -------------- */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ST_FUNC ਪੂਰਨ pe_ਲੱਦੋ_file(ਬਣਤਰ TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename);
ST_FUNC ਪੂਰਨ pe_output_file(TCCState * s1, ਅਚਲ ਅੱਖਰ *filename);
ST_FUNC ਪੂਰਨ pe_putimport(TCCState *s1, ਪੂਰਨ dllindex, ਅਚਲ ਅੱਖਰ *name, addr_t ਮੁੱਲ);
ST_FUNC ਪੂਰਨ pe_setsubsy(TCCState *s1, ਅਚਲ ਅੱਖਰ *arg);
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
#ਜੇ_ਅੰਤ
#ਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64) || defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
ST_FUNC ਖਾਲੀ pe_ਜੋੜੋ_unwind_ਅੰਕੜੇ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਸ਼ੁਰੂ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਸਿਰਾ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਢੇਰ);
#ਜੇ_ਅੰਤ
PUB_FUNC ਪੂਰਨ tcc_get_dllexports(ਅਚਲ ਅੱਖਰ *filename, ਅੱਖਰ **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_ASM_ਸੈੱਟ 0x04

/* ------------ tccmacho.c ----------------- */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_MACHO
ST_FUNC ਪੂਰਨ macho_output_file(TCCState * s1, ਅਚਲ ਅੱਖਰ *filename);
ST_FUNC ਪੂਰਨ macho_ਲੱਦੋ_dll(TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ lev);
ST_FUNC ਪੂਰਨ macho_ਲੱਦੋ_tbd(TCCState *s1, ਪੂਰਨ fd, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ lev);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_macos_sdkpath(TCCState* s);
ST_FUNC ਅੱਖਰ* macho_tbd_soname(ਪੂਰਨ fd);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
/* ------------ tccrun.c ----------------- */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_STATIC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_LAZY       0x001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_NOW        0x002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_GLOBAL     0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTLD_DEFAULT    ਨਿਰਾ
/* dummy function for profiling */
ST_FUNC ਖਾਲੀ *dlopen(ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flag);
ST_FUNC ਖਾਲੀ dlclose(ਖਾਲੀ *p);
ST_FUNC ਅਚਲ ਅੱਖਰ *dlerror(ਖਾਲੀ);
ST_FUNC ਖਾਲੀ *dlsym(ਖਾਲੀ *handle, ਅਚਲ ਅੱਖਰ *ਚਿੰਨ੍ਹ);
#ਜੇ_ਅੰਤ
ST_FUNC ਖਾਲੀ tcc_ਲੜੀਵਾਰ_free(TCCState *s1);
#ਜੇ_ਅੰਤ

/* ------------ tcctools.c ----------------- */
#ਜੇ 0 /* included in tcc.c */
ST_FUNC ਪੂਰਨ tcc_tool_ar(TCCState *s, ਪੂਰਨ argc, ਅੱਖਰ **argv);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
ST_FUNC ਪੂਰਨ tcc_tool_impdef(TCCState *s, ਪੂਰਨ argc, ਅੱਖਰ **argv);
#ਜੇ_ਅੰਤ
ST_FUNC ਪੂਰਨ tcc_tool_cross(TCCState *s, ਅੱਖਰ **argv, ਪੂਰਨ option);
ST_FUNC ਪੂਰਨ gen_makedeps(TCCState *s, ਅਚਲ ਅੱਖਰ *ਨਿਸ਼ਾਨਾ, ਅਚਲ ਅੱਖਰ *filename);
#ਜੇ_ਅੰਤ

/* ------------ tccdbg.c ------------ */

ST_FUNC ਖਾਲੀ tcc_debug_new(TCCState *s);

ST_FUNC ਖਾਲੀ tcc_debug_ਸ਼ੁਰੂ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_debug_ਸਿਰਾ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_debug_bincl(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_debug_eincl(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_debug_newfile(TCCState *s1);

ST_FUNC ਖਾਲੀ tcc_debug_ਸਤਰ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC ਖਾਲੀ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC ਖਾਲੀ tcc_debug_prolog_epilog(TCCState *s1, ਪੂਰਨ ਮੁੱਲ);
ST_FUNC ਖਾਲੀ tcc_debug_funcend(TCCState *s1, ਪੂਰਨ ਮਾਪ);
ST_FUNC ਖਾਲੀ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ਪੂਰਨ sh_ਅੰਕ, ਪੂਰਨ sym_bind, ਪੂਰਨ sym_type);
ST_FUNC ਖਾਲੀ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC ਖਾਲੀ tcc_debug_stabn(TCCState *s1, ਪੂਰਨ type, ਪੂਰਨ ਮੁੱਲ);
ST_FUNC ਖਾਲੀ tcc_debug_fix_forw(TCCState *s1, CType *t);

#ਜੇ !(defined ELF_OBJ_ONLY || defined TCC_ਨਿਸ਼ਾਨਾ_ARM || defined TARGETOS_BSD)
ST_FUNC ਖਾਲੀ tcc_eh_ਚੌਖਟਾ_ਸ਼ੁਰੂ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_eh_ਚੌਖਟਾ_ਸਿਰਾ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_eh_ਚੌਖਟਾ_hdr(TCCState *s1, ਪੂਰਨ final);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_EH_ਚੌਖਟਾ 1
#ਜੇ_ਅੰਤ

ST_FUNC ਖਾਲੀ tcc_tcov_ਸ਼ੁਰੂ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_tcov_ਸਿਰਾ(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_tcov_check_ਸਤਰ(TCCState *s1, ਪੂਰਨ ਸ਼ੁਰੂ);
ST_FUNC ਖਾਲੀ tcc_tcov_ਖੰਡ_ਸਿਰਾ(TCCState *s1, ਪੂਰਨ ਸਤਰ);
ST_FUNC ਖਾਲੀ tcc_tcov_ਖੰਡ_begin(TCCState *s1);
ST_FUNC ਖਾਲੀ tcc_tcov_reset_ind(TCCState *s1);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stab_section            s1->stab_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stabstr_section         stab_section->link
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcov_section            s1->tcov_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ eh_ਚੌਖਟਾ_section        s1->eh_ਚੌਖਟਾ_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ eh_ਚੌਖਟਾ_hdr_section    s1->eh_ਚੌਖਟਾ_hdr_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_info_section      s1->dwarf_info_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_abbrev_section    s1->dwarf_abbrev_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_ਸਤਰ_section      s1->dwarf_ਸਤਰ_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_aranges_section   s1->dwarf_aranges_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_str_section       s1->dwarf_str_section
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dwarf_ਸਤਰ_str_section  s1->dwarf_ਸਤਰ_str_section

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWARF_MAX_128	((8 * ਆਕਾਰ (int64_t) + 6) / 7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_read_1(ln,ਸਿਰਾ) \
	((ln) < (ਸਿਰਾ) ? *(ln)++ : 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_read_2(ln,ਸਿਰਾ) \
	((ln) + 1 < (ਸਿਰਾ) ? read16le(((ln)+=2) - 2) : 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_read_4(ln,ਸਿਰਾ) \
	((ln) + 3 < (ਸਿਰਾ) ? read32le(((ln)+=4) - 4) : 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_read_8(ln,ਸਿਰਾ) \
	((ln) + 7 < (ਸਿਰਾ) ? read64le(((ln)+=8) - 8) : 0)
ਸਥਿਰ ਸਤਰਅੰਦਰ uint64_t
dwarf_read_uleb128(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ **ln, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਸਿਰਾ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *cp = *ln;
    uint64_t retval = 0;
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, ਸਿਰਾ);
        retval |= (byte & 0x7f) << (i * 7);
	ਜੇ ((byte & 0x80) == 0)
	    ਰੋਕੋ;
    }
    *ln = cp;
    ਵਾਪਸ retval;
}
ਸਥਿਰ ਸਤਰਅੰਦਰ int64_t
dwarf_read_sleb128(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ **ln, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਸਿਰਾ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *cp = *ln;
    int64_t retval = 0;
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, ਸਿਰਾ);
        retval |= (byte & 0x7f) << (i * 7);
	ਜੇ ((byte & 0x80) == 0) {
	    ਜੇ ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    ਰੋਕੋ;
	}
    }
    *ln = cp;
    ਵਾਪਸ retval;
}

/* default dwarf version for "-gdwarf" */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_MACHO
# define DEFAULT_DWARF_ਸੰਸਕਰਣ 2
#ਨਹੀਂਤਾਂ
# define DEFAULT_DWARF_ਸੰਸਕਰਣ 5
#ਜੇ_ਅੰਤ

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_DWARF_ਸੰਸਕਰਣ
# define CONFIG_DWARF_ਸੰਸਕਰਣ 0
#ਜੇ_ਅੰਤ

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
# define R_ਅੰਕੜੇ_32_DW R_X86_64_32
#ਨਹੀਂਤਾਂ
# define R_ਅੰਕੜੇ_32_DW R_ਅੰਕੜੇ_32
#ਜੇ_ਅੰਤ

/********************************************************/
#ਜੇ CONFIG_TCC_SEMLOCK
#ਜੇ defined _WIN32
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਅਸਥਿਰ LONG init; CRITICAL_SECTION cs; } TCCSem;
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ wait_sem(TCCSem *p) {
    ਜੇ (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } ਨਹੀਂਤਾਂ {
        ਜਦੋਂ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#ਜਾਂਜੇ defined __APPLE__
#ਅਨ੍ਤਰ੍ਭਾਵ <dispatch/dispatch.h>
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ init; dispatch_semaphore_t sem; } TCCSem;
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ wait_sem(TCCSem *p) {
    ਜੇ (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_ਸਮਾਂ_FOREVER);
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <semaphore.h>
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ init; sem_t sem; } TCCSem;
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ wait_sem(TCCSem *p) {
    ਜੇ (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    ਜਦੋਂ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_SEM(s) TCCSem s
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM wait_sem
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM post_sem
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_SEM(s)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_SEM(p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POST_SEM(p)
#ਜੇ_ਅੰਤ

/********************************************************/
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ST_ਅੰਕੜੇ
#ਜੇ ONE_ਸਰੋਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_ਅੰਕੜੇ ਸਥਿਰ
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ST_ਅੰਕੜੇ
#ਜੇ_ਅੰਤ
/********************************************************/

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਠ_section        TCC_STATE_VAR(ਪਾਠ_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅੰਕੜੇ_section        TCC_STATE_VAR(ਅੰਕੜੇ_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ rodata_section      TCC_STATE_VAR(rodata_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bss_section         TCC_STATE_VAR(bss_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ common_section      TCC_STATE_VAR(common_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ cur_ਪਾਠ_section    TCC_STATE_VAR(cur_ਪਾਠ_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bounds_section      TCC_STATE_VAR(bounds_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lbounds_section     TCC_STATE_VAR(lbounds_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ symtab_section      TCC_STATE_VAR(symtab_section)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gnu_ext             TCC_STATE_VAR(gnu_ext)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_error_noabort   TCC_ਸੈੱਟ_STATE(_tcc_error_noabort)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_error           TCC_ਸੈੱਟ_STATE(_tcc_error)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_warning         TCC_ਸੈੱਟ_STATE(_tcc_warning)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੱਲ_idents        TCC_STATE_VAR(ਕੁੱਲ_idents)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੱਲ_ਸਤਰਾਂ         TCC_STATE_VAR(ਕੁੱਲ_ਸਤਰਾਂ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੱਲ_ਬਾਈਟਾਂ         TCC_STATE_VAR(ਕੁੱਲ_ਬਾਈਟਾਂ)

PUB_FUNC ਖਾਲੀ tcc_enter_state(TCCState *s1);
PUB_FUNC ਖਾਲੀ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_warning_c(sw) TCC_ਸੈੱਟ_STATE((\
    tcc_state->warn_ਅੰਕ = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#ਜੇ_ਅੰਤ /* _TCC_H */

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ TCC_STATE_VAR
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ TCC_ਸੈੱਟ_STATE

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_ਸੈੱਟ_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#ਨਹੀਂਤਾਂ
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_ਸੈੱਟ_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#ਜੇ_ਅੰਤ
