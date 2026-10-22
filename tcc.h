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

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TCC_H
#ವ್ಯಾಖ್ಯಾನಿಸು _TCC_H

#ವ್ಯಾಖ್ಯಾನಿಸು GNU_ಮೂಲ
#ವ್ಯಾಖ್ಯಾನಿಸು DARWIN_C_ಮೂಲ
#ಅನ್ತರ್ಭಾವ "config.h"

#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
/* gnu headers use to #define __attribute__ to empty for non-gcc compilers */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
# undef __attribute__
#ಆದರೆ_ಅಂತ್ಯ
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ತರ್ಭಾವ <math.h>
#ಅನ್ತರ್ಭಾವ <fcntl.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>
#ಅನ್ತರ್ಭಾವ <time.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
# include <unistd.h>
# include <sys/time.h>
# ifndef CONFIG_TCC_STATIC
#  include <dlfcn.h>
# endif
/* XXX: need to define this to use them in non ISOC99 context */
ಬಾಹ್ಯ ದಶಮಾಂಶ strtof (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *__nptr, ಅಕ್ಷರ **__endptr);
ಬಾಹ್ಯ ದೀರ್ಘ ದ್ವಿಗುಣ strtold (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *__nptr, ಅಕ್ಷರ **__endptr);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
# define WIN32_LEAN_AND_ಸರಾಸರಿ 1
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
# define ಸಾಲೊಳಗೆ __inline
# define snprintf _snprintf
# define vsnprintf _vsnprintf
# ifndef __GNUC__
#  define strtold (ದೀರ್ಘ ದ್ವಿಗುಣ)strtod
#  define strtof (ದಶಮಾಂಶ)strtod
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
# ಆದರೆ defined(_M_ARM64) && !defined(__aarch64__)
#  define __aarch64__ 1
# endif
# ifndef va_copy
#  define va_copy(a,b) a = b
# endif
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ O_ದ್ವಿಮಾನ_2
# define O_ದ್ವಿಮಾನ_2 0
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ offsetof
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__ // clang -fsanitize compains about: NULL+value
#ವ್ಯಾಖ್ಯಾನಿಸು offsetof(type, ಕ್ಷೇತ್ರ) __builtin_offsetof(type, ಕ್ಷೇತ್ರ)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು offsetof(type, ಕ್ಷೇತ್ರ) ((ಗಾತ್ರ_t) &((type *)0)->ಕ್ಷೇತ್ರ)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ countof
#ವ್ಯಾಖ್ಯಾನಿಸು countof(tab) (ಗಾತ್ರ(tab) / ಗಾತ್ರ((tab)[0]))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSC_VER
# define NORETURN __declspec(noreturn)
# define ALIGNED(x) __declspec(align(x))
# define PRINTF_LIKE(x,y)
#ಇಲ್ಲದಿದ್ದರೆ
# define NORETURN __attribute__((noreturn))
# define ALIGNED(x) __attribute__((aligned(x)))
# define PRINTF_LIKE(x,y) __attribute__ ((format (ಬರೆ, (x), (y))))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
# define IS_DIRSEP(c) (c == '/' || c == '\\')
# define IS_ABSPATH(p) (IS_DIRSEP(p[0]) || (p[0] && p[1] == ':' && IS_DIRSEP(p[2])))
# define PATHCMP stricmp
# define PATHSEP ";"
#ಇಲ್ಲದಿದ್ದರೆ
# define IS_DIRSEP(c) (c == '/')
# define IS_ABSPATH(p) IS_DIRSEP(p[0])
# define PATHCMP strcmp
# define PATHSEP ":"
#ಆದರೆ_ಅಂತ್ಯ

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
#ಆದರೆ !defined(TCC_ಗುರಿ_I386) && !defined(TCC_ಗುರಿ_ARM) && \
    !defined(TCC_ಗುರಿ_ARM64) && !defined(TCC_ಗುರಿ_C67) && \
    !defined(TCC_ಗುರಿ_X86_64) && !defined(TCC_ಗುರಿ_RISCV64)
# ಆದರೆ defined __x86_64__
#  define TCC_ಗುರಿ_X86_64
# elif defined __arm__
#  define TCC_ಗುರಿ_ARM
#  define TCC_ARM_EABI
#  define TCC_ARM_VFP
#  define TCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define TCC_ಗುರಿ_ARM64
# elif defined __riscv
#  define TCC_ಗುರಿ_RISCV64
# ಇಲ್ಲದಿದ್ದರೆ
#  define TCC_ಗುರಿ_I386
# endif
# ifdef _WIN32
#  define TCC_ಗುರಿ_PE 1
# endif
# ifdef __APPLE__
#  define TCC_ಗುರಿ_MACHO 1
# endif
#ಆದರೆ_ಅಂತ್ಯ

/* only native compiler supports -run */
#ಆದರೆ defined _WIN32 == defined TCC_ಗುರಿ_PE \
    && defined __APPLE__ == defined TCC_ಗುರಿ_MACHO
# ಆದರೆ defined __i386__ && defined TCC_ಗುರಿ_I386
#  define TCC_IS_NATIVE
# elif defined __x86_64__ && defined TCC_ಗುರಿ_X86_64
#  define TCC_IS_NATIVE
# elif defined __arm__ && defined TCC_ಗುರಿ_ARM
#  define TCC_IS_NATIVE
# elif defined __aarch64__ && defined TCC_ಗುರಿ_ARM64
#  define TCC_IS_NATIVE
# elif defined __riscv && defined __LP64__ && defined TCC_ಗುರಿ_RISCV64
#  define TCC_IS_NATIVE
# endif
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined CONFIG_TCC_BACKTRACE && CONFIG_TCC_BACKTRACE==0
# undef CONFIG_TCC_BACKTRACE
#ಇಲ್ಲದಿದ್ದರೆ
# define CONFIG_TCC_BACKTRACE 1 /* enable builtin stack backtraces */
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined CONFIG_TCC_BCHECK && CONFIG_TCC_BCHECK==0
#  undef CONFIG_TCC_BCHECK
#ಇಲ್ಲದಿದ್ದರೆ
#  define CONFIG_TCC_BCHECK 1 /* enable bound checking code */
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined CONFIG_NEW_MACHO && CONFIG_NEW_MACHO==0
#  undef CONFIG_NEW_MACHO
#ಇಲ್ಲದಿದ್ದರೆ
#  define CONFIG_NEW_MACHO 1 /* enable new macho code */
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined TARGETOS_OpenBSD \
    || defined TARGETOS_FreeBSD \
    || defined TARGETOS_NetBSD \
    || defined TARGETOS_FreeBSD_kernel
# define TARGETOS_BSD 1
#ಅಥವಾಆದರೆ !(defined TCC_ಗುರಿ_PE || defined TCC_ಗುರಿ_MACHO)
# define TARGETOS_Linux 1 /* for tccdefs_.h */
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined TCC_ಗುರಿ_PE || defined TCC_ಗುರಿ_MACHO
# define ELF_OBJ_ONLY /* create elf .o but native executables */
#ಇಲ್ಲದಿದ್ದರೆ
# define TCC_ಗುರಿ_UNIX 1
#ಆದರೆ_ಅಂತ್ಯ

/* No ten-byte long doubles on window and macos except in
   cross-compilers made by a mingw-GCC */
#ಆದರೆ defined TCC_ಗುರಿ_PE \
    || (defined TCC_ಗುರಿ_MACHO && defined TCC_ಗುರಿ_ARM64)
# define TCC_USING_DOUBLE_FOR_LDOUBLE 1
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_PIE
# define CONFIG_TCC_PIC 1
#ಆದರೆ_ಅಂತ್ಯ

/* support using libtcc from threads */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_SEMLOCK
# define CONFIG_TCC_SEMLOCK 1
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ path configuration ------------ */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_SYSROOT
# define CONFIG_SYSROOT ""
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined CONFIG_TCCDIR && !defined _WIN32
# define CONFIG_TCCDIR "/usr/local/lib/tcc"
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TRIPLET
# define USE_TRIPLET(s) s "/" CONFIG_TRIPLET
# define ALSO_TRIPLET(s) USE_TRIPLET(s) PATHSEP s
#ಇಲ್ಲದಿದ್ದರೆ
# define USE_TRIPLET(s) s
# define ALSO_TRIPLET(s) s
#ಆದರೆ_ಅಂತ್ಯ

/* path to find crt1.o, crti.o and crtn.o */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_CRTPREFIX
# define CONFIG_TCC_CRTPREFIX \
    USE_TRIPLET(CONFIG_SYSROOT "/usr/lib")
#ಆದರೆ_ಅಂತ್ಯ

/* Below: {B} is substituted by CONFIG_TCCDIR (rsp. -B option) */

/* system include paths */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_SYSINCLUDEPATHS
# ಆದರೆ defined TCC_ಗುರಿ_PE || defined _WIN32
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP "{B}/include/winapi"
# ಇಲ್ಲದಿದ್ದರೆ
#  define CONFIG_TCC_SYSINCLUDEPATHS \
    "{B}/include" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/include")
# endif
#ಆದರೆ_ಅಂತ್ಯ

/* library search paths */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_LIBPATHS
# ಆದರೆ defined TCC_ಗುರಿ_PE || defined _WIN32
#  define CONFIG_TCC_LIBPATHS \
    "{B}/lib"
# ಇಲ್ಲದಿದ್ದರೆ
#  define CONFIG_TCC_LIBPATHS \
    "{B}" PATHSEP ALSO_TRIPLET(CONFIG_SYSROOT "/usr/lib")
# endif
#ಆದರೆ_ಅಂತ್ಯ

/* name of ELF interpreter */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_ELFINTERP
# ಆದರೆ defined __GNU__
#  define CONFIG_TCC_ELFINTERP "/lib/ld.so"
# elif defined(TCC_ಗುರಿ_PE)
#  define CONFIG_TCC_ELFINTERP "-"
# elif defined TCC_ಗುರಿ_ARM64
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-aarch64.so.1"
# elif defined(TCC_ಗುರಿ_X86_64)
#  define CONFIG_TCC_ELFINTERP "/lib64/ld-linux-x86-64.so.2"
# elif defined(TCC_ಗುರಿ_RISCV64)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux-riscv64-lp64d.so.1"
# elif defined(TCC_ಗುರಿ_ARM)
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.3"
#  define CONFIG_TCC_ELFINTERP_ARMHF "/lib/ld-linux-armhf.so.3"
# ಇಲ್ಲದಿದ್ದರೆ
#  define CONFIG_TCC_ELFINTERP "/lib/ld-linux.so.2"
# endif
#ಆದರೆ_ಅಂತ್ಯ

/* (target specific) libtcc1.a */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_LIBTCC1
# define TCC_LIBTCC1 "libtcc1.a"
#ಆದರೆ_ಅಂತ್ಯ

/* <cross-prefix-to->libtcc1.a */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_CROSSPREFIX
# define CONFIG_TCC_CROSSPREFIX ""
#ಆದರೆ_ಅಂತ್ಯ

/* -------------------------------------------- */

#ಅನ್ತರ್ಭಾವ "libtcc.h"
#ಅನ್ತರ್ಭಾವ "elf.h"
#ಅನ್ತರ್ಭಾವ "stab.h"
#ಅನ್ತರ್ಭಾವ "dwarf.h"

/* -------------------------------------------- */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ PUB_FUNC /* functions used by tcc.c but not in libtcc.h */
# define PUB_FUNC
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ONE_ಮೂಲ
# define ONE_ಮೂಲ 0
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ ONE_ಮೂಲ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_INLN ಸ್ಥಿರ ಸಾಲೊಳಗೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_FUNC ಸ್ಥಿರ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_ದತ್ತಾಂಶ ಸ್ಥಿರ
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_INLN
#ವ್ಯಾಖ್ಯಾನಿಸು ST_FUNC
#ವ್ಯಾಖ್ಯಾನಿಸು ST_ದತ್ತಾಂಶ ಬಾಹ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_PROFILE /* profile all functions */
# define ಸ್ಥಿರ
# define ಸಾಲೊಳಗೆ
#ಆದರೆ_ಅಂತ್ಯ

/* -------------------------------------------- */
/* include the target specific definitions */

#ವ್ಯಾಖ್ಯಾನಿಸು ಗುರಿ_DEFS_ONLY
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
# include "i386-gen.c"
# include "i386-link.c"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
# include "x86_64-gen.c"
# include "x86_64-link.c"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
# include "arm-gen.c"
# include "arm-link.c"
# include "arm-asm.c"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
# include "arm64-gen.c"
# include "arm64-link.c"
# include "arm64-asm.c"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_C67
# define TCC_ಗುರಿ_COFF
# include "coff.h"
# include "c67-gen.c"
# include "c67-link.c"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_RISCV64)
# include "riscv64-gen.c"
# include "riscv64-link.c"
# include "riscv64-asm.c"
#ಇಲ್ಲದಿದ್ದರೆ
#ದೋಷ unknown ಗುರಿ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ಗುರಿ_DEFS_ONLY

/* -------------------------------------------- */

#ಆದರೆ PTR_ಗಾತ್ರ == 8
# define ELFCLASSW ELFCLASS64
# define ElfW(type) Elf##64##_##type
# define ELFW(type) ELF##64##_##type
# define ElfW_Rel ElfW(Rela)
# define SHT_RELX SHT_RELA
# define REL_SECTION_FMT ".rela%s"
#ಇಲ್ಲದಿದ್ದರೆ
# define ELFCLASSW ELFCLASS32
# define ElfW(type) Elf##32##_##type
# define ELFW(type) ELF##32##_##type
# define ElfW_Rel ElfW(Rel)
# define SHT_RELX SHT_REL
# define REL_SECTION_FMT ".rel%s"
#ಆದರೆ_ಅಂತ್ಯ
/* target address type */
#ವ್ಯಾಖ್ಯಾನಿಸು addr_t ElfW(Addr)
#ವ್ಯಾಖ್ಯಾನಿಸು ElfSym ElfW(Sym)

#ಆದರೆ PTR_ಗಾತ್ರ == 8 && !defined TCC_ಗುರಿ_PE
# define LONG_ಗಾತ್ರ 8
#ಇಲ್ಲದಿದ್ದರೆ
# define LONG_ಗಾತ್ರ 4
#ಆದರೆ_ಅಂತ್ಯ

/* -------------------------------------------- */

#ವ್ಯಾಖ್ಯಾನಿಸು INCLUDE_ರಾಶಿ_ಗಾತ್ರ  32
#ವ್ಯಾಖ್ಯಾನಿಸು IFDEF_ರಾಶಿ_ಗಾತ್ರ    64
#ವ್ಯಾಖ್ಯಾನಿಸು VSTACK_ಗಾತ್ರ         512
#ವ್ಯಾಖ್ಯಾನಿಸು STRING_MAX_ಗಾತ್ರ     1024
#ವ್ಯಾಖ್ಯಾನಿಸು TOKSTR_MAX_ಗಾತ್ರ     256
#ವ್ಯಾಖ್ಯಾನಿಸು PACK_ರಾಶಿ_ಗಾತ್ರ     8

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_HASH_ಗಾತ್ರ       16384 /* must be a power of two */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ALLOC_INCR      512  /* must be a power of two */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_MAX_ಗಾತ್ರ        4 /* token max size in int unit when stored in string */

/* token symbol management */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TokenSym {
    ರಚನೆ TokenSym *hash_ಮುಂದಿನ;
    ರಚನೆ Sym *sym_define; /* direct pointer to define */
    ರಚನೆ Sym *sym_label; /* direct pointer to label */
    ರಚನೆ Sym *sym_struct; /* direct pointer to structure */
    ರಚನೆ Sym *sym_identifier; /* direct pointer to identifier */
    ಪೂರ್ಣಾಂಕ tok; /* token number */
    ಪೂರ್ಣಾಂಕ len;
    ಅಕ್ಷರ str[1];
} TokenSym;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ nwchar_t;
#ಇಲ್ಲದಿದ್ದರೆ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ nwchar_t;
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ CString {
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2; /* size in bytes */
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_allocated;
    ಅಕ್ಷರ *ದತ್ತಾಂಶ; /* nwchar_t* in cases */
} CString;

/* type definition */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ CType {
    ಪೂರ್ಣಾಂಕ t;
    ರಚನೆ Sym *ref;
} CType;

/* long double words on host(!) platform */
#ವ್ಯಾಖ್ಯಾನಿಸು LDOUBLE_ಪದಗಳು ((ಗಾತ್ರ(ದೀರ್ಘ ದ್ವಿಗುಣ)+3)/4)

/* constant value */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ CValue {
    ದೀರ್ಘ ದ್ವಿಗುಣ ld;
    ದ್ವಿಗುಣ d;
    ದಶಮಾಂಶ f;
    uint64_t i;
    ರಚನೆ {
        ಅಕ್ಷರ *ದತ್ತಾಂಶ;
        ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2;
    } str;
    ಪೂರ್ಣಾಂಕ tab[LDOUBLE_ಪದಗಳು];
} CValue;

/* value on stack */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SValue {
    CType type;      /* type */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ r;      /* register + flags */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ r2;     /* second register, used for 'long long'
                              type. If not used, set to VT_CONST */
    ಒಕ್ಕೂಟ {
      ರಚನೆ { ಪೂರ್ಣಾಂಕ jtrue, jfalse; }; /* forward jmps */
      CValue c;         /* constant, if VT_CONST */
    };
    ಒಕ್ಕೂಟ {
      ರಚನೆ { ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ cmp_op, cmp_r; }; /* VT_CMP operation */
      ರಚನೆ Sym *sym;  /* symbol, if (VT_SYM | VT_CONST), or if */
    };                  /* result of unary() for an identifier. */

} SValue;

/* symbol attributes */
ರಚನೆ SymAttr {
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ
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
ರಚನೆ FuncAttr {
    ಚಿಹ್ನೆರಹಿತ
    func_call   : 3, /* calling convention (0..5), see below */
    func_type   : 2, /* FUNC_OLD/NEW/ELLIPSIS */
    func_noreturn : 1, /* attribute((noreturn)) */
    func_ctor   : 1, /* attribute((constructor)) */
    func_dtor   : 1, /* attribute((destructor)) */
    func_ವಾದಗಳು   : 8, /* PE __stdcall args */
    func_alwinl : 1, /* always_inline */
    xxxx        : 15;
};

/* symbol management */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Sym {
    ಪೂರ್ಣಾಂಕ v; /* symbol token */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ r; /* associated register or VT_CONST/VT_LOCAL and LVAL type */
    ರಚನೆ SymAttr a; /* symbol attributes */
    ಒಕ್ಕೂಟ {
        ರಚನೆ {
            ಪೂರ್ಣಾಂಕ c; /* associated number or Elf symbol index */
            ಒಕ್ಕೂಟ {
                ಪೂರ್ಣಾಂಕ sym_scope; /* scope level for locals */
                ಪೂರ್ಣಾಂಕ jnext; /* next jump label */
                ಪೂರ್ಣಾಂಕ jind; /* label position */
                ರಚನೆ FuncAttr f; /* function attributes */
                ಪೂರ್ಣಾಂಕ auxtype; /* bitfield access type */
            };
        };
        ದೀರ್ಘ ದೀರ್ಘ enum_val; /* enum constant if IS_ENUM_VAL */
        ಪೂರ್ಣಾಂಕ *d; /* define token stream */
        ರಚನೆ Sym *cleanup_func;
    };

    CType type; /* associated type */
    ಒಕ್ಕೂಟ {
        ರಚನೆ Sym *ಮುಂದಿನ; /* next related symbol (for fields and anoms) */
        ಪೂರ್ಣಾಂಕ *e; /* expanded token stream with preprocessor macros */
        ಪೂರ್ಣಾಂಕ asm_label; /* associated asm label */
        ರಚನೆ Sym *cleanupstate; /* in defined labels */
        ಪೂರ್ಣಾಂಕ *vla_array_str; /* vla array code */
    };
    ರಚನೆ Sym *prev; /* prev symbol in stack */
    ಒಕ್ಕೂಟ {
        ರಚನೆ Sym *prev_tok; /* previous symbol for this token */
        ರಚನೆ Sym *cleanup_sym; /* symbol from __attribute__((cleanup())) */
        ರಚನೆ Sym *cleanup_label; /* label in 'pending_gotos' chain */
    };
} Sym;

/* section definition */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Section {
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ; /* current data offset */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ದತ್ತಾಂಶ;       /* section data */
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದತ್ತಾಂಶ_allocated; /* used for realloc() handling */
    TCCState *s1;
    ಪೂರ್ಣಾಂಕ sh_name;             /* elf section name (only used during output) */
    ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ;              /* elf section number */
    ಪೂರ್ಣಾಂಕ sh_type;             /* elf section type */
    ಪೂರ್ಣಾಂಕ sh_flags;            /* elf section flags */
    ಪೂರ್ಣಾಂಕ sh_info;             /* elf section info */
    ಪೂರ್ಣಾಂಕ sh_addralign;        /* elf section alignment */
    ಪೂರ್ಣಾಂಕ sh_entsize;          /* elf entry size */
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ sh_ಗಾತ್ರ;   /* section size (only used during output) */
    addr_t sh_addr;          /* address at which the section is relocated */
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ sh_ಸ್ಥಾನಾಂತರ; /* file offset */
    ಪೂರ್ಣಾಂಕ nb_hashed_syms;      /* used to resize the hash table */
    ರಚನೆ Section *link;    /* link to another section */
    ರಚನೆ Section *reloc;   /* corresponding section for relocation, if any */
    ರಚನೆ Section *hash;    /* hash table for symbols */
    ರಚನೆ Section *prev;    /* previous section on section stack */
    ಅಕ್ಷರ name[1];           /* section name */
} Section;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DLLReference {
    ಪೂರ್ಣಾಂಕ level;
    ಶೂನ್ಯ *handle;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಸಿಕ್ಕಿತು, ಸೂಚ್ಯಂಕ;
    ಅಕ್ಷರ name[1];
} DLLReference;

/* -------------------------------------------------- */

#ವ್ಯಾಖ್ಯಾನಿಸು SYM_STRUCT     0x40000000 /* struct/union/enum symbol space */
#ವ್ಯಾಖ್ಯಾನಿಸು SYM_ಕ್ಷೇತ್ರ      0x20000000 /* struct/union field symbol space */
#ವ್ಯಾಖ್ಯಾನಿಸು SYM_ಮೊದಲ_ANOM 0x10000000 /* first anonymous sym */

/* stored in 'Sym->f.func_type' field */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_NEW       1 /* ansi function prototype */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_OLD       2 /* old function prototype */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_ELLIPSIS  3 /* ansi function prototype with ... */

/* stored in 'Sym->f.func_call' field */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_CDECL     0 /* standard c call */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_STDCALL   1 /* pascal c call */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_FASTCALL1 2 /* first param in %eax */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_FASTCALL2 3 /* first parameters in %eax, %edx */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_FASTCALL3 4 /* first parameter in %eax, %edx, %ecx */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_FASTCALLW 5 /* first parameter in %ecx, %edx */
#ವ್ಯಾಖ್ಯಾನಿಸು FUNC_THISCALL  6 /* first param in %ecx */

/* field 'Sym.t' for macros */
#ವ್ಯಾಖ್ಯಾನಿಸು MACRO_OBJ      0 /* object like macro */
#ವ್ಯಾಖ್ಯಾನಿಸು MACRO_FUNC     1 /* function like macro */
#ವ್ಯಾಖ್ಯಾನಿಸು MACRO_JOIN     2 /* macro uses ## */

/* field 'Sym.r' for C labels */
#ವ್ಯಾಖ್ಯಾನಿಸು LABEL_DEFINED  0 /* label is defined */
#ವ್ಯಾಖ್ಯಾನಿಸು LABEL_FORWARD  1 /* label is forward defined */
#ವ್ಯಾಖ್ಯಾನಿಸು LABEL_DECLARED 2 /* label is declared but never used */
#ವ್ಯಾಖ್ಯಾನಿಸು LABEL_GONE     3 /* label isn't in scope, but not yet popped
                            from local_label_stack (stmt exprs) */

/* type_decl() types */
#ವ್ಯಾಖ್ಯಾನಿಸು TYPE_ABSTRACT  1 /* type without variable */
#ವ್ಯಾಖ್ಯಾನಿಸು TYPE_ನೇರ    2 /* type with variable */
#ವ್ಯಾಖ್ಯಾನಿಸು TYPE_PARAM     4 /* type declares function parameter */
#ವ್ಯಾಖ್ಯಾನಿಸು TYPE_NEST      8 /* nested call to post_type */

#ವ್ಯಾಖ್ಯಾನಿಸು IO_BUF_ಗಾತ್ರ 8192

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_ಕೊನೆ;
    ಪೂರ್ಣಾಂಕ fd;
    ರಚನೆ BufferedFile *prev;
    ಪೂರ್ಣಾಂಕ ಸಾಲು_ಅಂಕೆ;    /* current line number - here to simplify code */
    ಪೂರ್ಣಾಂಕ ಸಾಲು_ref;    /* tcc -E: last printed line */
    ಪೂರ್ಣಾಂಕ ifndef_macro;  /* #ifndef macro / #endif search */
    ಪೂರ್ಣಾಂಕ ifndef_macro_saved; /* saved ifndef_macro */
    ಪೂರ್ಣಾಂಕ *ifdef_ರಾಶಿ_ptr; /* ifdef_stack value at the start of the file */
    ಪೂರ್ಣಾಂಕ include_ಮುಂದಿನ_ಸೂಚ್ಯಂಕ; /* next search path */
    ಪೂರ್ಣಾಂಕ prev_tok_flags; /* saved tok_flags */
    ಅಕ್ಷರ filename[1024];    /* filename */
    ಅಕ್ಷರ *true_filename; /* filename not modified by # line directive */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ unget[4];
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಬಫರ್[1]; /* extra size for CH_EOB char */
} BufferedFile;

#ವ್ಯಾಖ್ಯಾನಿಸು CH_EOB   '\\'       /* end of buffer or '\0' char in file */
#ವ್ಯಾಖ್ಯಾನಿಸು CH_EOF   (-1)   /* end of file */

/* used to record tokens */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TokenString {
    ಪೂರ್ಣಾಂಕ *str;
    ಪೂರ್ಣಾಂಕ len;
    ಪೂರ್ಣಾಂಕ need_spc;
    ಪೂರ್ಣಾಂಕ allocated_len;
    ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ;
    ಪೂರ್ಣಾಂಕ save_ಸಾಲು_ಅಂಕೆ;
    /* used to chain token-strings with begin/end_macro() */
    ರಚನೆ TokenString *prev;
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *prev_ptr;
    ಅಕ್ಷರ alloc;
} TokenString;

/* GNUC attribute definition */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ AttributeDef {
    ರಚನೆ SymAttr a;
    ರಚನೆ FuncAttr f;
    ರಚನೆ Section *section;
    Sym *cleanup_func;
    ಪೂರ್ಣಾಂಕ alias_ಗುರಿ; /* token */
    ಪೂರ್ಣಾಂಕ asm_label; /* associated asm label */
    ಅಕ್ಷರ attr_ಬಹುಲಕ; /* __attribute__((__mode__(...))) */
    ಅಕ್ಷರ new_section; /* section is new */
} AttributeDef;

/* inline functions */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ InlineFunc {
    TokenString *func_str;
    Sym *sym;
    ಅಕ್ಷರ filename[1];
} InlineFunc;

/* include file cache, used to find files faster and also to eliminate
   inclusion if the include file is protected by #ifndef ... #endif */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ CachedInclude {
    ಪೂರ್ಣಾಂಕ ifndef_macro;
    ಪೂರ್ಣಾಂಕ once;
    ಪೂರ್ಣಾಂಕ hash_ಮುಂದಿನ; /* -1 if none */
    ಅಕ್ಷರ filename[1]; /* path specified in #include */
} CachedInclude;

#ವ್ಯಾಖ್ಯಾನಿಸು CACHED_INCLUDES_HASH_ಗಾತ್ರ 32

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_ASM
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ {
    uint64_t v;
    Sym *sym;
    ಪೂರ್ಣಾಂಕ pcrel;
} ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ;

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ASM_OPERANDS 30
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ASMOperand {
    ಪೂರ್ಣಾಂಕ id; /* GCC 3 optional identifier (0 if number only supported) */
    ಅಕ್ಷರ constraint[16];
    ಅಕ್ಷರ asm_str[16]; /* computed asm string for operand */
    SValue *vt; /* C value of the expression */
    ಪೂರ್ಣಾಂಕ ref_ಸೂಚ್ಯಂಕ; /* if >= 0, gives reference to a output constraint */
    ಪೂರ್ಣಾಂಕ ಒಳಹರಿವು_ಸೂಚ್ಯಂಕ; /* if >= 0, gives reference to an input constraint */
    ಪೂರ್ಣಾಂಕ ಆದ್ಯತೆ; /* priority, used to assign registers */
    ಪೂರ್ಣಾಂಕ reg; /* if >= 0, register number used for this operand */
    ಪೂರ್ಣಾಂಕ is_llong; /* true if double register value */
    ಪೂರ್ಣಾಂಕ is_ಸ್ಮರಣೆ; /* true if memory operand */
    ಪೂರ್ಣಾಂಕ is_rw;     /* for '+' modifier */
    ಪೂರ್ಣಾಂಕ is_label;  /* for asm goto */
} ASMOperand;
#ಆದರೆ_ಅಂತ್ಯ

/* extra symbol attributes (not in symbol table) */
ರಚನೆ sym_attr {
    ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ;
    ಚಿಹ್ನೆರಹಿತ plt_ಸ್ಥಾನಾಂತರ;
    ಪೂರ್ಣಾಂಕ plt_sym;
    ಪೂರ್ಣಾಂಕ dyn_ಸೂಚ್ಯಂಕ;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ linker_sym:1;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ plt_thumb_stub:1;
#ಆದರೆ_ಅಂತ್ಯ
};

ರಚನೆ TCCState {
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ verbose; /* if true, display some information during compilation */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ nostdinc; /* if true, no standard headers are added */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ nostdlib; /* if true, no standard libraries are added */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ nostdlib_paths; /* if true, the default paths are not searched for libraries */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ nocommon; /* if true, do not use common symbols for .bss data */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ static_link; /* if true, static linking is performed */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ rdynamic; /* if true, all symbols are exported */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ symbolic; /* if true, resolve symbols in the current module first */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ znodelete; /* Set DF_1_NODELETE in dynamic section */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ filetype; /* file type for compilation (NONE,C,ASM) */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ optimize; /* only to #define __OPTIMIZE__ */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ option_pthread; /* -pthread option */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ enable_new_dtags; /* -Wl,--enable-new-dtags */
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ  cversion; /* supported C ISO version, 199901 (the default), 201112, ... */

    /* C language options */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ char_is_unsigned;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ leading_underscore;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ms_extensions; /* allow nested named struct w/o identifier behave like unnamed */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ dollars_ಒಳ_identifiers;  /* allows '$' char in identifiers */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ms_bitfields; /* if true, emulate MS algorithm for aligning bitfields */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಹಿಮ್ಮುಖ_funcargs; /* if true, evaluate last function arg first */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ gnu89_inline; /* treat 'extern inline' like 'static inline' */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ unwind_tables; /* create eh_frame section */

    /* warning switches */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_none;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_all;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_error;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_write_ಅಕ್ಷರಸರಣಿಗಳು;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_unsupported;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_implicit_function_declaration;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_discarded_qualifiers;
    #ವ್ಯಾಖ್ಯಾನಿಸು WARN_ON  1 /* warning is on (-Woption) */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ warn_ಅಂಕೆ; /* temp var for tcc_warning_c() */

    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ option_r; /* option -r */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ do_bench; /* option -bench */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ just_deps; /* option -M  */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ gen_deps; /* option -MD  */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ include_sys_deps; /* option -MD  */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ gen_phony_deps; /* option -MP */

    /* compile with debug symbol (and use them if error during execution) */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ do_debug;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ dwarf;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ do_backtrace;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    /* compile with built-in memory and bounds checker */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ do_bounds_check;
#ಆದರೆ_ಅಂತ್ಯ
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ test_coverage;  /* generate test coverage code */

    /* use GNU C extensions */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ gnu_ext;
    /* use TinyCC extensions */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ tcc_ext;

    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ dflag; /* -dX value */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ Pflag; /* -P switch (LINE_MACRO_OUTPUT_FORMAT) */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ nosse; /* For -mno-sse support. */
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ float_abi; /* float ABI of the generated code*/
#ಆದರೆ_ಅಂತ್ಯ

    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ has_ಪಠ್ಯ_addr;
    addr_t ಪಠ್ಯ_addr; /* address of text section */
    ಚಿಹ್ನೆರಹಿತ section_align; /* section alignment */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
    ಪೂರ್ಣಾಂಕ seg_ಗಾತ್ರ; /* 32. Can be 16 with i386 assembler (.code16) */
#ಆದರೆ_ಅಂತ್ಯ

    ಅಕ್ಷರ *tcc_lib_ಮಾರ್ಗ; /* CONFIG_TCCDIR or -B option */
    ಅಕ್ಷರ *soname; /* as specified on the command line (-soname) */
    ಅಕ್ಷರ *rpath; /* as specified on the command line (-Wl,-rpath=) */
    ಅಕ್ಷರ *elfint; /* -Wl,-I... on command line */
    ಅಕ್ಷರ *elf_entryname; /* "_start" unless set */
    ಅಕ್ಷರ *init_ಚಿಹ್ನೆ; /* symbols to call at load-time (not used currently) */
    ಅಕ್ಷರ *fini_ಚಿಹ್ನೆ; /* symbols to call at unload-time (not used currently) */
    ಅಕ್ಷರ *mapfile; /* create a mapfile (not used currently) */

    /* output type, see TCC_OUTPUT_XXX */
    ಪೂರ್ಣಾಂಕ output_type;
    /* output format, see TCC_OUTPUT_FORMAT_xxx */
    ಪೂರ್ಣಾಂಕ output_format;
    /* nth test to run with -dt -run */
    ಪೂರ್ಣಾಂಕ ಸತತ_test;

    /* array of all loaded dlls (including those referenced by loaded dlls) */
    DLLReference **loaded_dlls;
    ಪೂರ್ಣಾಂಕ nb_loaded_dlls;

    /* include paths */
    ಅಕ್ಷರ **include_paths;
    ಪೂರ್ಣಾಂಕ nb_include_paths;

    ಅಕ್ಷರ **sysinclude_paths;
    ಪೂರ್ಣಾಂಕ nb_sysinclude_paths;

    /* library paths */
    ಅಕ್ಷರ **library_paths;
    ಪೂರ್ಣಾಂಕ nb_library_paths;

    /* crt?.o object path */
    ಅಕ್ಷರ **crt_paths;
    ಪೂರ್ಣಾಂಕ nb_crt_paths;

    /* -D / -U options */
    CString cmdline_defs;
    /* -include options */
    CString cmdline_incl;

    /* error handling */
    ಶೂನ್ಯ *error_opaque;
    ಶೂನ್ಯ (*error_func)(ಶೂನ್ಯ *opaque, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ);
    ಪೂರ್ಣಾಂಕ error_ಗಣ_jmp_enabled;
    jmp_buf error_jmp_buf;
    ಪೂರ್ಣಾಂಕ nb_errors;

    /* output file for preprocessing (-E) */
    FILE *ppfp;

    /* for -MD/-MF: collected dependencies for this compilation */
    ಅಕ್ಷರ **ಗುರಿ_deps;
    ಪೂರ್ಣಾಂಕ nb_ಗುರಿ_deps;

    /* compilation */
    BufferedFile *include_ರಾಶಿ[INCLUDE_ರಾಶಿ_ಗಾತ್ರ];
    BufferedFile **include_ರಾಶಿ_ptr;

    ಪೂರ್ಣಾಂಕ ifdef_ರಾಶಿ[IFDEF_ರಾಶಿ_ಗಾತ್ರ];
    ಪೂರ್ಣಾಂಕ *ifdef_ರಾಶಿ_ptr;

    /* included files enclosed with #ifndef MACRO */
    ಪೂರ್ಣಾಂಕ cached_includes_hash[CACHED_INCLUDES_HASH_ಗಾತ್ರ];
    CachedInclude **cached_includes;
    ಪೂರ್ಣಾಂಕ nb_cached_includes;

    /* #pragma pack stack */
    ಪೂರ್ಣಾಂಕ pack_ರಾಶಿ[PACK_ರಾಶಿ_ಗಾತ್ರ];
    ಪೂರ್ಣಾಂಕ *pack_ರಾಶಿ_ptr;
    ಅಕ್ಷರ **pragma_libs;
    ಪೂರ್ಣಾಂಕ nb_pragma_libs;

    /* inline functions are stored as token lists and compiled last
       only if referenced */
    ರಚನೆ InlineFunc **inline_fns;
    ಪೂರ್ಣಾಂಕ nb_inline_fns;

    /* sections */
    Section **sections;
    ಪೂರ್ಣಾಂಕ nb_sections; /* number of sections, including first dummy section */

    Section **priv_sections;
    ಪೂರ್ಣಾಂಕ nb_priv_sections; /* number of private sections */

    /* predefined sections */
    Section *ಪಠ್ಯ_section, *ದತ್ತಾಂಶ_section, *rodata_section, *bss_section;
    Section *common_section;
    Section *cur_ಪಠ್ಯ_section; /* current section where function code is generated */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    /* bound check related sections */
    Section *bounds_section; /* contains global data bound description */
    Section *lbounds_section; /* contains local data bound description */
#ಆದರೆ_ಅಂತ್ಯ
    /* symbol section */
    ಒಕ್ಕೂಟ { Section *symtab_section, *symtab; }; /* historical alias */
    /* temporary dynamic symbol sections (for dll loading) */
    Section *dynsymtab_section;
    /* exported dynamic symbol section */
    Section *dynsym;
    /* got & plt handling */
    Section *got, *plt;
    /* exception handling */
    Section *eh_ಚೌಕಟ್ಟು_section;
    Section *eh_ಚೌಕಟ್ಟು_hdr_section;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ eh_ಆರಂಭ;
    /* debug sections */
    Section *stab_section;
    Section *dwarf_info_section;
    Section *dwarf_abbrev_section;
    Section *dwarf_ಸಾಲು_section;
    Section *dwarf_aranges_section;
    Section *dwarf_str_section;
    Section *dwarf_ಸಾಲು_str_section;
    ಪೂರ್ಣಾಂಕ dwlo, dwhi; /* dwarf section range */
    /* test coverage */
    Section *tcov_section;
    /* debug state */
    ರಚನೆ _tccdbg *dState;

    /* extra attributes (eg. GOT/PLT value) for symtab symbols */
    ರಚನೆ sym_attr *sym_attrs;
    ಪೂರ್ಣಾಂಕ nb_sym_attrs;
    /* ptr to next reloc entry reused */
    ElfW_Rel *qrel;
    #ವ್ಯಾಖ್ಯಾನಿಸು qrel s1->qrel

    addr_t tls_ಆರಂಭ, tls_ಕೊನೆ;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
    ರಚನೆ pcrel_hi { addr_t addr, val; } **pcrel_hi_entries;
    ಪೂರ್ಣಾಂಕ nb_pcrel_hi_entries;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    /* PE info */
    ಪೂರ್ಣಾಂಕ pe_subsystem;
    ಚಿಹ್ನೆರಹಿತ pe_characteristics;
    ಚಿಹ್ನೆರಹಿತ pe_dll_characteristics;
    ಚಿಹ್ನೆರಹಿತ pe_file_align;
    ಚಿಹ್ನೆರಹಿತ pe_ರಾಶಿ_ಗಾತ್ರ;
    addr_t pe_imagebase;
# ಆದರೆ defined(TCC_ಗುರಿ_X86_64) || defined(TCC_ಗುರಿ_ARM64)
    Section *uw_pdata;
    ಪೂರ್ಣಾಂಕ uw_sym;
    ಪೂರ್ಣಾಂಕ uw_xsym;
    ಚಿಹ್ನೆರಹಿತ uw_offs;
# endif
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined TCC_ಗುರಿ_MACHO
    ಅಕ್ಷರ *install_name;
    uint32_t compatibility_ಆವೃತ್ತಿ;
    uint32_t current_ಆವೃತ್ತಿ;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
    ಪೂರ್ಣಾಂಕ nb_sym_versions;
    ರಚನೆ sym_ಆವೃತ್ತಿ *sym_versions;
    ಪೂರ್ಣಾಂಕ nb_sym_ಗಮ್ಯ_ಆವೃತ್ತಿ;
    ಪೂರ್ಣಾಂಕ *sym_ಗಮ್ಯ_ಆವೃತ್ತಿ;
    ಪೂರ್ಣಾಂಕ dt_verneednum;
    Section *versym_section;
    Section *verneed_section;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸತತ_main; /* entry for tcc_run() */
    ಶೂನ್ಯ *ಸತತ_ptr; /* runtime_memory */
    ಚಿಹ್ನೆರಹಿತ ಸತತ_ಗಾತ್ರ; /* size of runtime_memory  */
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸತತ_stdin; /* custom stdin file for run_main */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಶೂನ್ಯ *ಸತತ_function_ಕೋಷ್ಟಕ; /* unwind data */
#ಆದರೆ_ಅಂತ್ಯ
    ರಚನೆ TCCState *ಮುಂದಿನ;
    ರಚನೆ rt_context *rc; /* pointer to backtrace info block */
    ಶೂನ್ಯ *ಸತತ_lj, *ಸತತ_jb; /* sj/lj for tcc_setjmp()/tcc_run() */
    TCCBtFunc *bt_func;
    ಶೂನ್ಯ *bt_ದತ್ತಾಂಶ;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    ಪೂರ್ಣಾಂಕ rt_ಅಂಕೆ_callers;
#ಆದರೆ_ಅಂತ್ಯ

    /* benchmark info */
    ಪೂರ್ಣಾಂಕ ಒಟ್ಟು_idents;
    ಪೂರ್ಣಾಂಕ ಒಟ್ಟು_ಸಾಲುಗಳು;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಒಟ್ಟು_ಬೈಟುಗಳು;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಒಟ್ಟು_output[4];

    /* used by tcc_load_ldscript */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ld_p; /* text pointer */

    /* for warnings/errors for object files */
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *current_filename;

    /* used by main and tcc_parse_args only */
    ರಚನೆ filespec **files; /* files seen on command line */
    ಪೂರ್ಣಾಂಕ nb_files; /* number thereof */
    ಪೂರ್ಣಾಂಕ nb_libraries; /* number of libs thereof */
    ಅಕ್ಷರ *outfile; /* output filename */
    ಅಕ್ಷರ *deps_outfile; /* option -MF */
    ಪೂರ್ಣಾಂಕ argc;
    ಅಕ್ಷರ **argv;
    /* -Wl options */
    ಅಕ್ಷರ **link_argv;
    ಪೂರ್ಣಾಂಕ link_argc, link_optind;
};

ರಚನೆ filespec {
    ಅಕ್ಷರ type;
    ಅಕ್ಷರ name[1];
};

/* The current value can be: */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_VALMASK   0x003f  /* mask for value location, register or: */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_CONST     0x0030  /* constant in vc (must be first non register value) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_LLOCAL    0x0031  /* lvalue, offset on stack */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_LOCAL     0x0032  /* offset on stack */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_CMP       0x0033  /* the value is stored in processor flags (in vc) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_JMP       0x0034  /* value is the consequence of jmp true (even) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_JMPI      0x0035  /* value is the consequence of jmp false (odd) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_LVAL      0x0100  /* var is an lvalue */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_SYM       0x0200  /* a symbol value is added */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_MUSTCAST  0x0C00  /* value must be casted to be correct (used for
                                char/short stored in integer registers) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_NONCONST  0x1000  /* VT_CONST, but not an (C standard) integer
                                constant expression */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_MUSTBOUND 0x4000  /* bound checking must be done before
                                dereferencing value */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_BOUNDED   0x8000  /* value is bounded. The address of the
                                bounding function call point is in vc */
/* types */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_BTYPE       0x000f  /* mask for basic type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_VOID             0  /* void type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_BYTE             1  /* signed byte type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_SHORT            2  /* short type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_INT              3  /* integer type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_LLONG            4  /* 64 bit integer */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_PTR              5  /*ಸೂಚಕ*/
#ವ್ಯಾಖ್ಯಾನಿಸು VT_FUNC             6  /* function type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_STRUCT           7  /* struct/union definition */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_FLOAT            8  /* IEEE float */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_DOUBLE           9  /* IEEE double */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_LDOUBLE         10  /* IEEE long double */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_BOOL            11  /* ISOC99 boolean type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_QLONG           13  /* 128-bit integer. Only used for x86-64 ABI */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_QFLOAT          14  /* 128-bit float. Only used for x86-64 ABI */

#ವ್ಯಾಖ್ಯಾನಿಸು VT_UNSIGNED    0x0010  /* unsigned type */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_DEFSIGN     0x0020  /* explicitly signed or unsigned */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ARRAY       0x0040  /* array type (also has VT_PTR) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_BITFIELD    0x0080  /* bitfield modifier */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_CONSTANT    0x0100  /* const modifier */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_VOLATILE    0x0200  /* volatile modifier */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_RESTRICT    0x0400  /* restrict modifier */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_QUAL        (VT_CONSTANT | VT_VOLATILE | VT_RESTRICT)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_VLA         0x0800  /* VLA type (also has VT_PTR and VT_ARRAY) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_LONG        0x1000  /* long type (also has VT_INT rsp. VT_LLONG) */

/* storage */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_EXTERN  0x00002000  /* extern definition */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_STATIC  0x00004000  /* static variable */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_TYPEDEF 0x00008000  /* typedef definition */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_INLINE  0x00010000  /* inline definition */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_TLS     0x00020000  /* thread-local storage */
/* currently unused: 0x000[48]0000  */

#ವ್ಯಾಖ್ಯಾನಿಸು VT_STRUCT_ಸರಿಸು 20     /* shift for bitfield shift values (32 - 2*6) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_STRUCT_ಮುಖವಾಡ (((1U << (6+6)) - 1) << VT_STRUCT_ಸರಿಸು | VT_BITFIELD)
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_POS(t) (((t) >> VT_STRUCT_ಸರಿಸು) & 0x3f)
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_ಗಾತ್ರ(t) (((t) >> (VT_STRUCT_ಸರಿಸು + 6)) & 0x3f)

#ವ್ಯಾಖ್ಯಾನಿಸು VT_UNION    (1 << VT_STRUCT_ಸರಿಸು | VT_STRUCT)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ENUM     (2 << VT_STRUCT_ಸರಿಸು) /* integral type is an enum really */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ENUM_VAL (3 << VT_STRUCT_ಸರಿಸು) /* integral type is an enum constant really */

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ENUM(t) ((t & VT_STRUCT_ಮುಖವಾಡ) == VT_ENUM)
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ENUM_VAL(t) ((t & VT_STRUCT_ಮುಖವಾಡ) == VT_ENUM_VAL)
#ವ್ಯಾಖ್ಯಾನಿಸು IS_UNION(t) ((t & (VT_STRUCT_ಮುಖವಾಡ|VT_BTYPE)) == VT_UNION)

#ವ್ಯಾಖ್ಯಾನಿಸು VT_ATOMIC   VT_VOLATILE

/* type mask (except storage) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_STORAGE (VT_EXTERN | VT_STATIC | VT_TYPEDEF | VT_INLINE | VT_TLS)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_TYPE (~(VT_STORAGE|VT_STRUCT_ಮುಖವಾಡ))

/* symbol was created by tccasm.c first */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ASM (VT_VOID | 4 << VT_STRUCT_ಸರಿಸು)
#ವ್ಯಾಖ್ಯಾನಿಸು VT_ASM_FUNC (VT_VOID | 5 << VT_STRUCT_ಸರಿಸು)
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ASM_SYM(sym) (((sym)->type.t & ((VT_BTYPE|VT_STRUCT_ಮುಖವಾಡ) & ~(1<<VT_STRUCT_ಸರಿಸು))) == VT_ASM)
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ASM_FUNC(t) ((t & (VT_BTYPE|VT_STRUCT_ಮುಖವಾಡ)) == VT_ASM_FUNC)

/* base type is array (from typedef/typeof) */
#ವ್ಯಾಖ್ಯಾನಿಸು VT_BT_ARRAY (6 << VT_STRUCT_ಸರಿಸು)
#ವ್ಯಾಖ್ಯಾನಿಸು IS_BT_ARRAY(t) ((t & VT_STRUCT_ಮುಖವಾಡ) == VT_BT_ARRAY)

/* general: set/get the pseudo-bitfield value for bit-mask M */
#ವ್ಯಾಖ್ಯಾನಿಸು BFVAL(M,N) ((ಚಿಹ್ನೆರಹಿತ)((M) & ~((M) << 1)) * (N))
#ವ್ಯಾಖ್ಯಾನಿಸು BFGET(X,M) (((X) & (M)) / BFVAL(M,1))
#ವ್ಯಾಖ್ಯಾನಿಸು BFSET(X,M,N) ((X) = ((X) & ~(M)) | BFVAL(M,N))

/* token values */

/* conditional ops */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LAND  0x90
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LOR   0x91
/* warning: the following compare tokens depend on i386 asm code */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ULT 0x92
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_UGE 0x93
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_EQ  0x94
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_NE  0x95
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ULE 0x96
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_UGT 0x97
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_Nset 0x98
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_Nclear 0x99
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LT  0x9c
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_GE  0x9d
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LE  0x9e
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_GT  0x9f

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ISCOND(t) (t >= TOK_LAND && t <= TOK_GT)

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_DEC     0x80 /* -- */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_MID     0x81 /* inc/dec, to void constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_INC     0x82 /* ++ */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_UDIV    0x83 /* unsigned division */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_UMOD    0x84 /* unsigned modulo */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_PDIV    0x85 /* fast division with undefined rounding for pointers */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_UMULL   0x86 /* unsigned 32x32 -> 64 mul */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ADDC1   0x87 /* add with carry generation */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ADDC2   0x88 /* add with carry use */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_SUBC1   0x89 /* add with carry generation */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_SUBC2   0x8a /* add with carry use */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_SHL     '<' /* shift left */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_SAR     '>' /* signed shift right */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_SHR     0x8b /* unsigned shift right */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_NEG     TOK_MID /* unary minus operation (for floats) */

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ARROW   0xa0 /* -> */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_DOTS    0xa1 /* three dots */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_TWODOTS 0xa2 /* C++ token ? */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_TWOSHARPS 0xa3 /* ## preprocessing token */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_PLCHLDR 0xa4 /* placeholder token as defined in C99 */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_PPJOIN  (TOK_TWOSHARPS | SYM_ಕ್ಷೇತ್ರ) /* A '##' in a macro to mean pasting */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_SOTYPE  0xa7 /* alias of '(' for parsing sizeof (type) */

/* assignment operators */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_ಕೂಡಿಸು   0xb0
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_SUB   0xb1
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_MUL   0xb2
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_DIV   0xb3
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_MOD   0xb4
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_AND   0xb5
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_OR    0xb6
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_XOR   0xb7
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_SHL   0xb8
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_A_SAR   0xb9

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ನಿಯೋಜಿಸು(t) (t >= TOK_A_ಕೂಡಿಸು && t <= TOK_A_SAR)
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_ನಿಯೋಜಿಸು_OP(t) ("+-*/%&|^<>"[t - TOK_A_ಕೂಡಿಸು])

/* tokens that carry values (in additional token string space / tokc) --> */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CCHAR   0xc0 /* char constant in tokc */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LCHAR   0xc1
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CINT    0xc2 /* number in tokc */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CUINT   0xc3 /* unsigned int constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CLLONG  0xc4 /* long long constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CULLONG 0xc5 /* unsigned long long constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CLONG   0xc6 /* long constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CULONG  0xc7 /* unsigned long constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_STR     0xc8 /* pointer to string in tokc */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LSTR    0xc9
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CFLOAT  0xca /* float constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CDOUBLE 0xcb /* double constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_CLDOUBLE 0xcc /* long double constant */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_PPNUM   0xcd /* preprocessor number */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_PPSTR   0xce /* preprocessor string */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LINENUM 0xcf /* line number info */

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_HAS_ಮೌಲ್ಯ(t) (t >= TOK_CCHAR && t <= TOK_LINENUM)

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_EOF       (-1)  /* end of file */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_LINEFEED  10    /* line feed */

/* all identifiers and strings have token above that */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_IDENT 256

ಎಣಿಕೆ tcc_token {
    TOK_ಕೊನೆಯ = TOK_IDENT - 1
#ವ್ಯಾಖ್ಯಾನಿಸು DEF(id, str) ,id
#ಅನ್ತರ್ಭಾವ "tcctok.h"
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DEF
};

/* keywords: tok >= TOK_IDENT && tok < TOK_UIDENT */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_UIDENT TOK_DEFINE

/* ------------ libtcc.c ------------ */

ST_ದತ್ತಾಂಶ ರಚನೆ TCCState *tcc_state;
ST_ದತ್ತಾಂಶ ಶೂನ್ಯ** stk_ದತ್ತಾಂಶ;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ nb_stk_ದತ್ತಾಂಶ;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ g_debug;

/* public functions currently used by the tcc main function */
ST_FUNC ಅಕ್ಷರ *pstrcpy(ಅಕ್ಷರ *buf, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);
ST_FUNC ಅಕ್ಷರ *pstrcat(ಅಕ್ಷರ *buf, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s);
ST_FUNC ಅಕ್ಷರ *pstrncpy(ಅಕ್ಷರ *ಹೊರಹೋಗು, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಗಾತ್ರ_t ಅಂಕೆ);
PUB_FUNC ಅಕ್ಷರ *tcc_basename(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
PUB_FUNC ಅಕ್ಷರ *tcc_fileextension (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);

/* all allocations - even MEM_DEBUG - use these */
PUB_FUNC ಶೂನ್ಯ tcc_free(ಶೂನ್ಯ *ptr);
PUB_FUNC ಶೂನ್ಯ *tcc_malloc(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
PUB_FUNC ಶೂನ್ಯ *tcc_mallocz(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
PUB_FUNC ಶೂನ್ಯ *tcc_realloc(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
PUB_FUNC ಅಕ್ಷರ *tcc_strdup(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ MEM_DEBUG
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_free(ptr)           tcc_free_debug(ptr)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_malloc(ಗಾತ್ರ_2)        tcc_malloc_debug(ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_mallocz(ಗಾತ್ರ_2)       tcc_mallocz_debug(ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_realloc(ptr,ಗಾತ್ರ_2)   tcc_realloc_debug(ptr, ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)
PUB_FUNC ಶೂನ್ಯ tcc_free_debug(ಶೂನ್ಯ *ptr);
PUB_FUNC ಶೂನ್ಯ *tcc_malloc_debug(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು);
PUB_FUNC ಶೂನ್ಯ *tcc_mallocz_debug(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು);
PUB_FUNC ಶೂನ್ಯ *tcc_realloc_debug(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು);
PUB_FUNC ಅಕ್ಷರ *tcc_strdup_debug(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು);
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ libc_free(ಶೂನ್ಯ *ptr);
/* defined to be not used */
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಡುಗಡೆ(p) use_tcc_free(p)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_ಕೊಡು(s) use_tcc_malloc(s)
#ವ್ಯಾಖ್ಯಾನಿಸು realloc(p, s) use_tcc_realloc(p, s)
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು strdup
#ವ್ಯಾಖ್ಯಾನಿಸು strdup(s) use_tcc_strdup(s)
PUB_FUNC ಪೂರ್ಣಾಂಕ _tcc_error_noabort(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC NORETURN ಶೂನ್ಯ _tcc_error(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...) PRINTF_LIKE(1,2);
PUB_FUNC ಶೂನ್ಯ _tcc_warning(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...) PRINTF_LIKE(1,2);
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_ಆಂತರಿಕ_error(ಸಂದೇಶ) \
    tcc_error("internal compiler error in %s:%d: %s", __FUNCTION__,__LINE__,ಸಂದೇಶ)

/* other utilities */
ST_FUNC ಶೂನ್ಯ dynarray_ಕೂಡಿಸು(ಶೂನ್ಯ *ptab, ಪೂರ್ಣಾಂಕ *nb_ptr, ಶೂನ್ಯ *ದತ್ತಾಂಶ);
ST_FUNC ಶೂನ್ಯ dynarray_reset(ಶೂನ್ಯ *pp, ಪೂರ್ಣಾಂಕ *n);
ST_INLN ಶೂನ್ಯ cstr_ccat(CString *cstr, ಪೂರ್ಣಾಂಕ ch);
ST_FUNC ಶೂನ್ಯ cstr_cat(CString *cstr, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ len);
ST_FUNC ಶೂನ್ಯ cstr_wccat(CString *cstr, ಪೂರ್ಣಾಂಕ ch);
ST_FUNC ಶೂನ್ಯ cstr_new(CString *cstr);
ST_FUNC ಶೂನ್ಯ cstr_free(CString *cstr);
ST_FUNC ಪೂರ್ಣಾಂಕ cstr_printf(CString *cs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...) PRINTF_LIKE(2,3);
ST_FUNC ಪೂರ್ಣಾಂಕ cstr_vprintf(CString *cstr, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap);
ST_FUNC ಶೂನ್ಯ cstr_reset(CString *cstr);
ST_FUNC ಶೂನ್ಯ tcc_open_bf(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ initlen);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_open(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
ST_FUNC ಶೂನ್ಯ tcc_close(ಶೂನ್ಯ);

/* mark a memory pointer on stack for cleanup after errors */
#ವ್ಯಾಖ್ಯಾನಿಸು stk_ತಳ್ಳು(p) dynarray_ಕೂಡಿಸು(&stk_ದತ್ತಾಂಶ, &nb_stk_ದತ್ತಾಂಶ, p)
#ವ್ಯಾಖ್ಯಾನಿಸು stk_ತೆಗೆ() (--nb_stk_ದತ್ತಾಂಶ)
/* mark CString on stack for cleanup errors */
#ವ್ಯಾಖ್ಯಾನಿಸು cstr_new_s(cstr) (cstr_new(cstr), stk_ತಳ್ಳು(&(cstr)->ದತ್ತಾಂಶ))
#ವ್ಯಾಖ್ಯಾನಿಸು cstr_free_s(cstr) (cstr_free(cstr), stk_ತೆಗೆ())

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_file_ಆಂತರಿಕ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flags);
/* flags: */
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_PRINT_ERROR     0x10 /* print error if file not found */
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_REFERENCED_DLL  0x20 /* load a referenced dll from another dll */
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_BIN        0x40 /* file to add is binary */
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_ಸಂಪೂರ್ಣ_ARCHIVE   0x80 /* load all objects from archive */
/* s->filetype: */
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_NONE   0
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_C      1
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_ASM    2
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_ASMPP  4
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_LIB    8
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_TYPE_ಮುಖವಾಡ   (7 | AFF_TYPE_BIN)
/* values from tcc_object_type(...) */
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_BINTYPE_REL 1
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_BINTYPE_DYN 2
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_BINTYPE_AR  3
#ವ್ಯಾಖ್ಯಾನಿಸು AFF_BINTYPE_C67 4

/* return value of tcc_add_file_internal(): 0, -1, or FILE_NOT_FOUND */
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOT_ಸಿಕ್ಕಿತು -2
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOT_RECOGNIZED -3 /* unrecognized file type */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_crt(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_dll(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flags);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_support(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_bcheck(TCCState *s1);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_btstub(TCCState *s1);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_pragma_libs(TCCState *s1);
PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_library_err(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f);
PUB_FUNC ಶೂನ್ಯ tcc_print_stats(TCCState *s, ಚಿಹ್ನೆರಹಿತ ಒಟ್ಟು_ಸಮಯ);
PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_parse_ವಾದಗಳು(TCCState *s, ಪೂರ್ಣಾಂಕ *argc, ಅಕ್ಷರ ***argv);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
ST_FUNC ಅಕ್ಷರ *normalize_slashes(ಅಕ್ಷರ *ಮಾರ್ಗ);
PUB_FUNC FILE *tcc_fopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *m);
PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_fclose(FILE *f);
#ಇಲ್ಲದಿದ್ದರೆ
# define tcc_fopen fopen
# define tcc_fclose fclose
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC DLLReference *tcc_ಕೂಡಿಸು_dllref(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *dllname, ಪೂರ್ಣಾಂಕ level);
ST_FUNC ಅಕ್ಷರ *tcc_ತುಂಬು_ಪಠ್ಯ(ಪೂರ್ಣಾಂಕ fd);
/* for #pragma once */
ST_FUNC ಪೂರ್ಣಾಂಕ normalized_PATHCMP(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f2);

/* tcc_parse_args return codes: */
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_HELP 1
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_HELP2 2
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_V 3
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_PRINT_DIRS 4
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_AR 5
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_IMPDEF 6
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_M32 32
#ವ್ಯಾಖ್ಯಾನಿಸು OPT_M64 64

/* ------------ tccpp.c ------------ */

ST_ದತ್ತಾಂಶ ರಚನೆ BufferedFile *file;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ tok;
ST_ದತ್ತಾಂಶ CValue tokc;
ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *macro_ptr;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ parse_flags;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ tok_flags;
ST_ದತ್ತಾಂಶ CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ tok_ident;
ST_ದತ್ತಾಂಶ TokenSym **ಕೋಷ್ಟಕ_ident;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ pp_ಅಭಿವ್ಯಕ್ತಿ;

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_FLAG_BOL   0x0001 /* beginning of line before */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_FLAG_BOF   0x0002 /* beginning of file before */
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_FLAG_ENDIF 0x0004 /* a endif was found matching starting #ifdef */

#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_PREPROCESS 0x0001 /* activate preprocessing */
#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_TOK_ಅಂಕೆ    0x0002 /* return numbers instead of TOK_PPNUM */
#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_LINEFEED   0x0004 /* line feed is returned as a
                                        token. line feed is also
                                        returned at eof */
#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_ASM_FILE 0x0008 /* we processing an asm file: '#' can be used for line comment, etc. */
#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_SPACES     0x0010 /* next() returns space tokens (for -E) */
#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_ACCEPT_STRAYS 0x0020 /* next() returns '\\' token */
#ವ್ಯಾಖ್ಯಾನಿಸು PARSE_FLAG_TOK_STR    0x0040 /* return parsed strings instead of TOK_PPSTR */

/* isidnum_table flags: */
#ವ್ಯಾಖ್ಯಾನಿಸು IS_SPC 1
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ID  2
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಅಂಕೆ 4

ಎಣಿಕೆ ಸಾಲು_macro_output_format {
    ಸಾಲು_MACRO_OUTPUT_FORMAT_GCC,
    ಸಾಲು_MACRO_OUTPUT_FORMAT_NONE,
    ಸಾಲು_MACRO_OUTPUT_FORMAT_STD,
    ಸಾಲು_MACRO_OUTPUT_FORMAT_P10 = 11
};

ST_FUNC TokenSym *tok_alloc(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ len);
ST_FUNC ಪೂರ್ಣಾಂಕ tok_alloc_const(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str);
ST_FUNC ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *get_tok_str(ಪೂರ್ಣಾಂಕ v, CValue *cv);
ST_FUNC ಶೂನ್ಯ begin_macro(TokenString *str, ಪೂರ್ಣಾಂಕ alloc);
ST_FUNC ಶೂನ್ಯ ಕೊನೆ_macro(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಂಕ ಗಣ_idnum(ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ val);
ST_INLN ಶೂನ್ಯ tok_str_new(TokenString *s);
ST_FUNC TokenString *tok_str_alloc(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ tok_str_free(TokenString *s);
ST_FUNC ಶೂನ್ಯ tok_str_free_str(ಪೂರ್ಣಾಂಕ *str);
ST_FUNC ಶೂನ್ಯ tok_str_ಕೂಡಿಸು(TokenString *s, ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ tok_str_ಕೂಡಿಸು_tok(TokenString *s);
ST_INLN ಶೂನ್ಯ define_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ macro_type, ಪೂರ್ಣಾಂಕ *str, Sym *ಮೊದಲ_arg);
ST_FUNC ಶೂನ್ಯ define_undef(Sym *s);
ST_INLN Sym *define_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v);
ST_FUNC ಶೂನ್ಯ free_ನಿರೂಪಿಸುತ್ತದೆ(Sym *b);
ST_FUNC ಶೂನ್ಯ parse_define(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ skip_ಗಮ್ಯ_eol(ಪೂರ್ಣಾಂಕ warn);
ST_FUNC ಶೂನ್ಯ preprocess(ಪೂರ್ಣಾಂಕ is_bof);
ST_FUNC ಶೂನ್ಯ ಮುಂದಿನ(ಶೂನ್ಯ);
ST_INLN ಶೂನ್ಯ unget_tok(ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_tok);
ST_FUNC ಶೂನ್ಯ preprocess_ಆರಂಭ(TCCState *s1, ಪೂರ್ಣಾಂಕ filetype);
ST_FUNC ಶೂನ್ಯ preprocess_ಕೊನೆ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccpp_new(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccpp_delete(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccpp_putfile(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_preprocess(TCCState *s1);
ST_FUNC ಶೂನ್ಯ skip(ಪೂರ್ಣಾಂಕ c);
ST_FUNC NORETURN ಶೂನ್ಯ expect(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ);
ST_FUNC ಶೂನ್ಯ pp_error(CString *cs);


/* space excluding newline */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ is_space(ಪೂರ್ಣಾಂಕ ch) {
    ಹಿಂತಿರುಗಿ ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ isid(ಪೂರ್ಣಾಂಕ c) {
    ಹಿಂತಿರುಗಿ (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ isnum(ಪೂರ್ಣಾಂಕ c) {
    ಹಿಂತಿರುಗಿ c >= '0' && c <= '9';
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ isoct(ಪೂರ್ಣಾಂಕ c) {
    ಹಿಂತಿರುಗಿ c >= '0' && c <= '7';
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ toup(ಪೂರ್ಣಾಂಕ c) {
    ಹಿಂತಿರುಗಿ (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/* ------------ tccgen.c ------------ */

#ವ್ಯಾಖ್ಯಾನಿಸು SYM_POOL_NB (8192 / ಗಾತ್ರ(Sym))

ST_ದತ್ತಾಂಶ Sym *global_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *local_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *local_label_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *global_label_ರಾಶಿ;
ST_ದತ್ತಾಂಶ Sym *define_ರಾಶಿ;
ST_ದತ್ತಾಂಶ CType int_type, func_old_type, char_ಸೂಚಕ_type;
ST_ದತ್ತಾಂಶ SValue *vtop;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ rsym, anon_sym, ind, loc;
ST_ದತ್ತಾಂಶ ಅಕ್ಷರ debug_modes;

ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ nocode_wanted; /* true if no code generation wanted for an expression */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ global_ಅಭಿವ್ಯಕ್ತಿ;  /* true if compound literals must be allocated globally (used during initializers parsing */
ST_ದತ್ತಾಂಶ CType func_vt; /* current function return type (used by return instruction) */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_var; /* true if current function is variadic */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_vc; /* stack address for implicit struct return storage */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_ind; /* function start address */
ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *funcname;

ST_FUNC ಶೂನ್ಯ tccgen_init(TCCState *s1);
ST_FUNC ಪೂರ್ಣಾಂಕ tccgen_compile(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccgen_ಮುಕ್ತಾಯ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ check_vstack(ಶೂನ್ಯ);

ST_INLN ಪೂರ್ಣಾಂಕ is_float(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಪೂರ್ಣಾಂಕ ieee_finite(ದ್ವಿಗುಣ d);
ST_FUNC ಪೂರ್ಣಾಂಕ exact_log2p1(ಪೂರ್ಣಾಂಕ i);
ST_FUNC ಶೂನ್ಯ test_lvalue(ಶೂನ್ಯ);

ST_FUNC ElfSym *elfsym(Sym *);
ST_FUNC ಶೂನ್ಯ update_storage(Sym *sym);
ST_FUNC ಶೂನ್ಯ put_extern_sym2(Sym *sym, ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ can_ಕೂಡಿಸು_underscore);
ST_FUNC ಶೂನ್ಯ put_extern_sym(Sym *sym, Section *section, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
ST_FUNC ಶೂನ್ಯ greloc(Section *s, Sym *sym, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ type);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ greloca(Section *s, Sym *sym, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ type, addr_t addend);

ST_INLN ಶೂನ್ಯ sym_free(Sym *sym);
ST_FUNC Sym *sym_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v, CType *type, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ sym_ತೆಗೆ(Sym **ptop, Sym *b, ಪೂರ್ಣಾಂಕ keep);
ST_FUNC Sym *sym_push2(Sym **ps, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ c);
ST_FUNC Sym *sym_find2(Sym *s, ಪೂರ್ಣಾಂಕ v);
ST_INLN Sym *sym_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v);
ST_FUNC Sym *label_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v);
ST_FUNC Sym *label_ತಳ್ಳು(Sym **ptop, ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ flags);
ST_FUNC ಶೂನ್ಯ label_ತೆಗೆ(Sym **ptop, Sym *slast, ಪೂರ್ಣಾಂಕ keep);
ST_INLN Sym *struct_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v);

ST_FUNC Sym *global_identifier_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ c);
ST_FUNC Sym *external_global_sym(ಪೂರ್ಣಾಂಕ v, CType *type);
ST_FUNC Sym *external_helper_sym(ಪೂರ್ಣಾಂಕ v);
ST_FUNC ಶೂನ್ಯ vpush_helper_func(ಪೂರ್ಣಾಂಕ v);
ST_FUNC ಶೂನ್ಯ vset(CType *type, ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ v);
ST_FUNC ಶೂನ್ಯ vset_VT_CMP(ಪೂರ್ಣಾಂಕ op);
ST_FUNC ಶೂನ್ಯ vpushi(ಪೂರ್ಣಾಂಕ v);
ST_FUNC ಶೂನ್ಯ vpushv(SValue *v);
ST_FUNC ಶೂನ್ಯ vpushsym(CType *type, Sym *sym);
ST_FUNC ಶೂನ್ಯ vswap(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ vrott(ಪೂರ್ಣಾಂಕ n);
ST_FUNC ಶೂನ್ಯ vrotb(ಪೂರ್ಣಾಂಕ n);
ST_FUNC ಶೂನ್ಯ vrev(ಪೂರ್ಣಾಂಕ n);
ST_FUNC ಶೂನ್ಯ vpop(ಶೂನ್ಯ);
#ಆದರೆ PTR_ಗಾತ್ರ == 4
ST_FUNC ಶೂನ್ಯ lexpand(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
ST_FUNC ಪೂರ್ಣಾಂಕ get_reg_ex(ಪೂರ್ಣಾಂಕ rc, ಪೂರ್ಣಾಂಕ rc2);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ save_reg(ಪೂರ್ಣಾಂಕ r);
ST_FUNC ಶೂನ್ಯ save_reg_upstack(ಪೂರ್ಣಾಂಕ r, ಪೂರ್ಣಾಂಕ n);
ST_FUNC ಪೂರ್ಣಾಂಕ get_reg(ಪೂರ್ಣಾಂಕ rc);
ST_FUNC ಶೂನ್ಯ save_regs(ಪೂರ್ಣಾಂಕ n);
ST_FUNC ಶೂನ್ಯ gaddrof(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಂಕ gv(ಪೂರ್ಣಾಂಕ rc);
ST_FUNC ಶೂನ್ಯ gv2(ಪೂರ್ಣಾಂಕ rc1, ಪೂರ್ಣಾಂಕ rc2);
ST_FUNC ಶೂನ್ಯ gen_op(ಪೂರ್ಣಾಂಕ op);
ST_FUNC ಪೂರ್ಣಾಂಕ type_ಗಾತ್ರ(CType *type, ಪೂರ್ಣಾಂಕ *a);
ST_FUNC ಶೂನ್ಯ mk_ಸೂಚಕ(CType *type);
ST_FUNC ಶೂನ್ಯ vstore(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ inc(ಪೂರ್ಣಾಂಕ post, ಪೂರ್ಣಾಂಕ c);
ST_FUNC CString* parse_mult_str(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ);
ST_FUNC CString* parse_asm_str(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ indir(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ unary(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gexpr(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಂಕ ಅಭಿವ್ಯಕ್ತಿ_const(ಶೂನ್ಯ);
#ಆದರೆ defined CONFIG_TCC_BCHECK || defined TCC_ಗುರಿ_C67
ST_FUNC Sym *get_sym_ref(CType *type, Section *sec, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined TCC_ಗುರಿ_X86_64 && !defined TCC_ಗುರಿ_PE
ST_FUNC ಪೂರ್ಣಾಂಕ classify_x86_64_va_arg(CType *ty);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
ST_FUNC ಶೂನ್ಯ gbound_ವಾದಗಳು(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು);
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ func_bound_ಕೂಡಿಸು_epilog;
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC Sym *gfunc_ಗಣ_param(Sym *s, ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ byref);

/* ------------ tccelf.c ------------ */

#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_FORMAT_ELF    0 /* default output format: ELF */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_FORMAT_ದ್ವಿಮಾನ 1 /* binary image output */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_FORMAT_COFF   2 /* COFF */
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OUTPUT_DYN           TCC_OUTPUT_DLL

#ವ್ಯಾಖ್ಯಾನಿಸು ARMAG  "!<arch>\n"    /* For COFF and a.out archives */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ n_strx;         /* index into string table of name */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ n_type;         /* type of symbol */
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ n_other;        /* misc info (usually empty) */
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ n_desc;        /* description field */
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ n_ಮೌಲ್ಯ;        /* value of symbol */
} Stab_Sym;

ST_FUNC ಶೂನ್ಯ tccelf_new(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccelf_delete(TCCState *s);
ST_FUNC ಶೂನ್ಯ tccelf_begin_file(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccelf_ಕೊನೆ_file(TCCState *s1);
ST_FUNC Section *new_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಪೂರ್ಣಾಂಕ sh_type, ಪೂರ್ಣಾಂಕ sh_flags);
ST_FUNC ಶೂನ್ಯ section_realloc(Section *sec, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ new_ಗಾತ್ರ);
ST_FUNC ಗಾತ್ರ_t section_ಕೂಡಿಸು(Section *sec, addr_t ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ align);
ST_FUNC ಶೂನ್ಯ *section_ptr_ಕೂಡಿಸು(Section *sec, addr_t ಗಾತ್ರ_2);
ST_FUNC Section *ಕಂಡುಹಿಡಿ_section(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
ST_FUNC ಶೂನ್ಯ free_section(Section *s);
ST_FUNC Section *new_symtab(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *symtab_name, ಪೂರ್ಣಾಂಕ sh_type, ಪೂರ್ಣಾಂಕ sh_flags, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *strtab_name, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *hash_name, ಪೂರ್ಣಾಂಕ hash_sh_flags);
ST_FUNC ಶೂನ್ಯ init_symtab(Section *s);

ST_FUNC ಪೂರ್ಣಾಂಕ put_elf_str(Section *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sym);
ST_FUNC ಪೂರ್ಣಾಂಕ put_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ info, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ shndx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
ST_FUNC ಪೂರ್ಣಾಂಕ ಗಣ_elf_sym(Section *s, addr_t ಮೌಲ್ಯ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಪೂರ್ಣಾಂಕ info, ಪೂರ್ಣಾಂಕ other, ಪೂರ್ಣಾಂಕ shndx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
ST_FUNC ಪೂರ್ಣಾಂಕ ಕಂಡುಹಿಡಿ_elf_sym(Section *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
ST_FUNC ಶೂನ್ಯ put_elf_reloc(Section *symtab, Section *s, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ ಚಿಹ್ನೆ);
ST_FUNC ಶೂನ್ಯ put_elf_reloca(Section *symtab, Section *s, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ ಚಿಹ್ನೆ, addr_t addend);

ST_FUNC ಶೂನ್ಯ resolve_common_syms(TCCState *s1);
ST_FUNC ಶೂನ್ಯ relocate_syms(TCCState *s1, Section *symtab, ಪೂರ್ಣಾಂಕ do_resolve);
ST_FUNC ಶೂನ್ಯ relocate_sections(TCCState *s1);

ST_FUNC ssize_t ತುಂಬಿದ_read(ಪೂರ್ಣಾಂಕ fd, ಶೂನ್ಯ *buf, ಗಾತ್ರ_t ಎಣಿಕೆ_3);
ST_FUNC ಶೂನ್ಯ *ತುಂಬು_ದತ್ತಾಂಶ(ಪೂರ್ಣಾಂಕ fd, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ file_ಸ್ಥಾನಾಂತರ, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_object_type(ಪೂರ್ಣಾಂಕ fd, ElfW(Ehdr) *h);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_object_file(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ file_ಸ್ಥಾನಾಂತರ);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_archive(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಪೂರ್ಣಾಂಕ alacarte);
ST_FUNC ಶೂನ್ಯ ಕೂಡಿಸು_array(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sec, ಪೂರ್ಣಾಂಕ c);

ST_FUNC ರಚನೆ sym_attr *get_sym_attr(TCCState *s1, ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ, ಪೂರ್ಣಾಂಕ alloc);
ST_FUNC addr_t get_sym_addr(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಪೂರ್ಣಾಂಕ err, ಪೂರ್ಣಾಂಕ forc);
ST_FUNC ಶೂನ್ಯ list_elf_symbols(TCCState *s, ಶೂನ್ಯ *ctx,
    ಶೂನ್ಯ (*ಚಿಹ್ನೆ_cb)(ಶೂನ್ಯ *ctx, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *val));
ST_FUNC ಪೂರ್ಣಾಂಕ ಗಣ_global_sym(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, Section *sec, addr_t offs);

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#ವ್ಯಾಖ್ಯಾನಿಸು for_each_elem(sec, startoff, elem, type) \
    ಗಾಗಿ (elem = (type *) sec->ದತ್ತಾಂಶ + startoff; \
         elem < (type *) (sec->ದತ್ತಾಂಶ + sec->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ); elem++)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ELF_OBJ_ONLY
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_dll(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ level);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_ldscript(TCCState *s1, ಪೂರ್ಣಾಂಕ fd);
ST_FUNC ಶೂನ್ಯ tccelf_ಕೂಡಿಸು_crtbegin(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tccelf_ಕೂಡಿಸು_crtend(TCCState *s1);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_runtime(TCCState *s1);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ xxx-link.c ------------ */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_PE
ST_FUNC ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_reloc (ಪೂರ್ಣಾಂಕ reloc_type);
ST_FUNC ಪೂರ್ಣಾಂಕ gotplt_ನಮೂದು_type (ಪೂರ್ಣಾಂಕ reloc_type);
/* Whether to generate a GOT/PLT entry and when. NO_GOTPLT_ENTRY is first so
   that unknown relocation don't create a GOT or PLT entry */
ಎಣಿಕೆ gotplt_ನಮೂದು {
    NO_GOTPLT_ನಮೂದು,	/* never generate (eg. GLOB_DAT & JMP_SLOT relocs) */
    BUILD_GOT_ONLY,	/* only build GOT (eg. TPOFF relocs) */
    AUTO_GOTPLT_ನಮೂದು,	/* generate if sym is UNDEF */
    ALWAYS_GOTPLT_ನಮೂದು	/* always generate (eg. PLTOFF relocs) */
};
#ವ್ಯಾಖ್ಯಾನಿಸು NEED_RELOC_TYPE
#ಆದರೆ !defined TCC_ಗುರಿ_MACHO || defined TCC_IS_NATIVE
ST_FUNC ಚಿಹ್ನೆರಹಿತ create_plt_ನಮೂದು(TCCState *s1, ಚಿಹ್ನೆರಹಿತ got_ಸ್ಥಾನಾಂತರ, ರಚನೆ sym_attr *attr);
ST_FUNC ಶೂನ್ಯ relocate_plt(TCCState *s1);
ST_FUNC ಶೂನ್ಯ build_got_entries(TCCState *s1, ಪೂರ್ಣಾಂಕ got_sym); /* in tccelf.c */
#ವ್ಯಾಖ್ಯಾನಿಸು NEED_BUILD_GOT
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ relocate(TCCState *s1, ElfW_Rel *rel, ಪೂರ್ಣಾಂಕ type, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ptr, addr_t addr, addr_t val);

/* ------------ xxx-gen.c ------------ */
ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ ಗುರಿ_machine_defs;
ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ reg_classes[NB_REGS];

ST_FUNC ಶೂನ್ಯ gsym_addr(ಪೂರ್ಣಾಂಕ t, ಪೂರ್ಣಾಂಕ a);
ST_FUNC ಶೂನ್ಯ gsym(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ ತುಂಬು(ಪೂರ್ಣಾಂಕ r, SValue *sv);
ST_FUNC ಶೂನ್ಯ store(ಪೂರ್ಣಾಂಕ r, SValue *v);
ST_FUNC ಪೂರ್ಣಾಂಕ gfunc_sret(CType *vt, ಪೂರ್ಣಾಂಕ variadic, CType *ret, ಪೂರ್ಣಾಂಕ *align, ಪೂರ್ಣಾಂಕ *regsize);
ST_FUNC ಶೂನ್ಯ gfunc_call(ಪೂರ್ಣಾಂಕ nb_ವಾದಗಳು);
ST_FUNC ಶೂನ್ಯ gfunc_prolog(Sym *func_sym);
ST_FUNC ಶೂನ್ಯ gfunc_epilog(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_fill_nops(ಪೂರ್ಣಾಂಕ);
ST_FUNC ಪೂರ್ಣಾಂಕ gjmp(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gjmp_addr(ಪೂರ್ಣಾಂಕ a);
ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_cond(ಪೂರ್ಣಾಂಕ op, ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಪೂರ್ಣಾಂಕ gjmp_append(ಪೂರ್ಣಾಂಕ n, ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gen_opi(ಪೂರ್ಣಾಂಕ op);
ST_FUNC ಶೂನ್ಯ gen_opf(ಪೂರ್ಣಾಂಕ op);
ST_FUNC ಶೂನ್ಯ gen_cvt_ftoi(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gen_cvt_itof(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gen_cvt_ftof(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ ggoto(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ TCC_ಗುರಿ_C67
ST_FUNC ಶೂನ್ಯ o(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ c);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ gen_vla_sp_save(ಪೂರ್ಣಾಂಕ addr);
ST_FUNC ಶೂನ್ಯ gen_vla_sp_restore(ಪೂರ್ಣಾಂಕ addr);
ST_FUNC ಶೂನ್ಯ gen_vla_alloc(CType *type, ಪೂರ್ಣಾಂಕ align);

ಸ್ಥಿರ ಸಾಲೊಳಗೆ uint16_t read16le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p) {
    ಹಿಂತಿರುಗಿ p[0] | (uint16_t)p[1] << 8;
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ write16le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ uint32_t read32le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p) {
  ಹಿಂತಿರುಗಿ read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ write32le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ add32le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ uint64_t read64le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p) {
  ಹಿಂತಿರುಗಿ read32le(p) | (uint64_t)read32le(p + 4) << 32;
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ write64le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, uint64_t x) {
    write32le(p, x);  write32le(p + 4, x >> 32);
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ add64le(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *p, int64_t x) {
    write64le(p, read64le(p) + x);
}
/* ------------ i386-gen.c ------------ */
#ಆದರೆ defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64 || defined TCC_ಗುರಿ_ARM
ST_FUNC ಶೂನ್ಯ g(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le16(ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_le32(ಪೂರ್ಣಾಂಕ c);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64
ST_FUNC ಶೂನ್ಯ gen_addr32(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_addrpc32(ಪೂರ್ಣಾಂಕ r, Sym *sym, ಪೂರ್ಣಾಂಕ c);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ x86_64-gen.c ------------ */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಂಕ op);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ST_FUNC ಶೂನ್ಯ gen_vla_ಫಲಿತಾಂಶ(ಪೂರ್ಣಾಂಕ addr);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ arm-gen.c ------------ */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
#ಆದರೆ defined(TCC_ARM_EABI) && !defined(CONFIG_TCC_ELFINTERP)
PUB_FUNC ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *default_elfinterp(ರಚನೆ TCCState *s);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ arm_init(ರಚನೆ TCCState *s);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ arm64-gen.c ------------ */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM64
ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಂಕ op);
ST_FUNC ಶೂನ್ಯ gfunc_return(CType *func_type);
ST_FUNC ಶೂನ್ಯ gen_va_ಆರಂಭ(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_va_arg(CType *t);
ST_FUNC ಶೂನ್ಯ gen_clear_cache(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ riscv64-gen.c ------------ */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_RISCV64
ST_FUNC ಶೂನ್ಯ gen_opl(ಪೂರ್ಣಾಂಕ op);
ST_FUNC ಶೂನ್ಯ gen_va_ಆರಂಭ(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ arch_transfer_ret_regs(ಪೂರ್ಣಾಂಕ);
ST_FUNC ಶೂನ್ಯ gen_cvt_sxtw(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ gen_cvt_csti(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ gen_increment_tcov (SValue *sv);
ST_FUNC ಶೂನ್ಯ gen_clear_cache(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ c67-gen.c ------------ */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_C67
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ tcccoff.c ------------ */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_COFF
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_output_coff(TCCState *s1, FILE *f);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ತುಂಬು_coff(TCCState * s1, ಪೂರ್ಣಾಂಕ fd);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ tccasm.c ------------ */
ST_FUNC ಶೂನ್ಯ asm_instr(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ asm_global_instr(ಶೂನ್ಯ);
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_assemble(TCCState *s1, ಪೂರ್ಣಾಂಕ do_preprocess);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_ASM
ST_FUNC ಪೂರ್ಣಾಂಕ ಕಂಡುಹಿಡಿ_constraint(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ **pp);
ST_FUNC Sym* get_asm_sym(ಪೂರ್ಣಾಂಕ name, Sym *csym);
ST_FUNC ಶೂನ್ಯ asm_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1, ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
ST_FUNC ಪೂರ್ಣಾಂಕ asm_int_ಅಭಿವ್ಯಕ್ತಿ(TCCState *s1);
#ಆದರೆ PTR_ಗಾತ್ರ == 8
ST_FUNC ಶೂನ್ಯ gen_expr64(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
#ಆದರೆ_ಅಂತ್ಯ
/* ------------ i386-asm.c ------------ */
ST_FUNC ಶೂನ್ಯ gen_expr32(ಅಭಿವ್ಯಕ್ತಿ_ಮೌಲ್ಯ *pe);
ST_FUNC ಶೂನ್ಯ asm_opcode(TCCState *s1, ಪೂರ್ಣಾಂಕ opcode);
ST_FUNC ಪೂರ್ಣಾಂಕ asm_parse_regvar(ಪೂರ್ಣಾಂಕ t);
ST_FUNC ಶೂನ್ಯ asm_compute_constraints(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs, ಸ್ಥಿರಾಂಕ uint8_t *clobber_regs, ಪೂರ್ಣಾಂಕ *pout_reg);
ST_FUNC ಶೂನ್ಯ subst_asm_ಕಾರ್ಯಾಂಶ(CString *ಕೂಡಿಸು_str, SValue *sv, ಪೂರ್ಣಾಂಕ modifier);
ST_FUNC ಶೂನ್ಯ asm_gen_ಸಂಕೇತ(ASMOperand *operands, ಪೂರ್ಣಾಂಕ nb_operands, ಪೂರ್ಣಾಂಕ nb_outputs, ಪೂರ್ಣಾಂಕ is_output, uint8_t *clobber_regs, ಪೂರ್ಣಾಂಕ ಹೊರಹೋಗು_reg);
ST_FUNC ಶೂನ್ಯ asm_clobber(uint8_t *clobber_regs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ tccpe.c -------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ST_FUNC ಪೂರ್ಣಾಂಕ pe_ತುಂಬು_file(ರಚನೆ TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
ST_FUNC ಪೂರ್ಣಾಂಕ pe_output_file(TCCState * s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
ST_FUNC ಪೂರ್ಣಾಂಕ pe_putimport(TCCState *s1, ಪೂರ್ಣಾಂಕ dllindex, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name, addr_t ಮೌಲ್ಯ);
ST_FUNC ಪೂರ್ಣಾಂಕ pe_setsubsy(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *arg);
#ಆದರೆ defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined(TCC_ಗುರಿ_X86_64) || defined(TCC_ಗುರಿ_ARM64)
ST_FUNC ಶೂನ್ಯ pe_ಕೂಡಿಸು_unwind_ದತ್ತಾಂಶ(ಚಿಹ್ನೆರಹಿತ ಆರಂಭ, ಚಿಹ್ನೆರಹಿತ ಕೊನೆ, ಚಿಹ್ನೆರಹಿತ ರಾಶಿ);
#ಆದರೆ_ಅಂತ್ಯ
PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_get_dllexports(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಅಕ್ಷರ **pp);
/* symbol properties stored in Elf32_Sym->st_other */
# define ST_PE_EXPORT 0x10
# define ST_PE_IMPORT 0x20
# define ST_PE_STDCALL 0x40
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_ASM_ಗಣ 0x04

/* ------------ tccmacho.c ----------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_MACHO
ST_FUNC ಪೂರ್ಣಾಂಕ macho_output_file(TCCState * s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
ST_FUNC ಪೂರ್ಣಾಂಕ macho_ತುಂಬು_dll(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ lev);
ST_FUNC ಪೂರ್ಣಾಂಕ macho_ತುಂಬು_tbd(TCCState *s1, ಪೂರ್ಣಾಂಕ fd, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ lev);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_macos_sdkpath(TCCState* s);
ST_FUNC ಅಕ್ಷರ* macho_tbd_soname(ಪೂರ್ಣಾಂಕ fd);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
/* ------------ tccrun.c ----------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_STATIC
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_LAZY       0x001
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_NOW        0x002
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_GLOBAL     0x100
#ವ್ಯಾಖ್ಯಾನಿಸು RTLD_DEFAULT    ಖಾಲಿ
/* dummy function for profiling */
ST_FUNC ಶೂನ್ಯ *dlopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flag);
ST_FUNC ಶೂನ್ಯ dlclose(ಶೂನ್ಯ *p);
ST_FUNC ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *dlerror(ಶೂನ್ಯ);
ST_FUNC ಶೂನ್ಯ *dlsym(ಶೂನ್ಯ *handle, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಚಿಹ್ನೆ);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಶೂನ್ಯ tcc_ಸತತ_free(TCCState *s1);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ tcctools.c ----------------- */
#ಆದರೆ 0 /* included in tcc.c */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_ar(TCCState *s, ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_impdef(TCCState *s, ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv);
#ಆದರೆ_ಅಂತ್ಯ
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_tool_cross(TCCState *s, ಅಕ್ಷರ **argv, ಪೂರ್ಣಾಂಕ option);
ST_FUNC ಪೂರ್ಣಾಂಕ gen_makedeps(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಗುರಿ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename);
#ಆದರೆ_ಅಂತ್ಯ

/* ------------ tccdbg.c ------------ */

ST_FUNC ಶೂನ್ಯ tcc_debug_new(TCCState *s);

ST_FUNC ಶೂನ್ಯ tcc_debug_ಆರಂಭ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_ಕೊನೆ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_bincl(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_eincl(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_debug_newfile(TCCState *s1);

ST_FUNC ಶೂನ್ಯ tcc_debug_ಸಾಲು(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_debug_info(TCCState *s1, Sym *s, Sym *e);
ST_FUNC ಶೂನ್ಯ tcc_debug_funcstart(TCCState *s1, Sym *sym);
ST_FUNC ಶೂನ್ಯ tcc_debug_prolog_epilog(TCCState *s1, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ);
ST_FUNC ಶೂನ್ಯ tcc_debug_funcend(TCCState *s1, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2);
ST_FUNC ಶೂನ್ಯ tcc_debug_extern_sym(TCCState *s1, Sym *sym, ಪೂರ್ಣಾಂಕ sh_ಅಂಕೆ, ಪೂರ್ಣಾಂಕ sym_bind, ಪೂರ್ಣಾಂಕ sym_type);
ST_FUNC ಶೂನ್ಯ tcc_debug_typedef(TCCState *s1, Sym *sym);
ST_FUNC ಶೂನ್ಯ tcc_debug_stabn(TCCState *s1, ಪೂರ್ಣಾಂಕ type, ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ);
ST_FUNC ಶೂನ್ಯ tcc_debug_fix_forw(TCCState *s1, CType *t);

#ಆದರೆ !(defined ELF_OBJ_ONLY || defined TCC_ಗುರಿ_ARM || defined TARGETOS_BSD)
ST_FUNC ಶೂನ್ಯ tcc_eh_ಚೌಕಟ್ಟು_ಆರಂಭ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_eh_ಚೌಕಟ್ಟು_ಕೊನೆ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_eh_ಚೌಕಟ್ಟು_hdr(TCCState *s1, ಪೂರ್ಣಾಂಕ final);
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_EH_ಚೌಕಟ್ಟು 1
#ಆದರೆ_ಅಂತ್ಯ

ST_FUNC ಶೂನ್ಯ tcc_tcov_ಆರಂಭ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_tcov_ಕೊನೆ(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_tcov_check_ಸಾಲು(TCCState *s1, ಪೂರ್ಣಾಂಕ ಆರಂಭ);
ST_FUNC ಶೂನ್ಯ tcc_tcov_ಖಂಡ_ಕೊನೆ(TCCState *s1, ಪೂರ್ಣಾಂಕ ಸಾಲು);
ST_FUNC ಶೂನ್ಯ tcc_tcov_ಖಂಡ_begin(TCCState *s1);
ST_FUNC ಶೂನ್ಯ tcc_tcov_reset_ind(TCCState *s1);

#ವ್ಯಾಖ್ಯಾನಿಸು stab_section            s1->stab_section
#ವ್ಯಾಖ್ಯಾನಿಸು stabstr_section         stab_section->link
#ವ್ಯಾಖ್ಯಾನಿಸು tcov_section            s1->tcov_section
#ವ್ಯಾಖ್ಯಾನಿಸು eh_ಚೌಕಟ್ಟು_section        s1->eh_ಚೌಕಟ್ಟು_section
#ವ್ಯಾಖ್ಯಾನಿಸು eh_ಚೌಕಟ್ಟು_hdr_section    s1->eh_ಚೌಕಟ್ಟು_hdr_section
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_info_section      s1->dwarf_info_section
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_abbrev_section    s1->dwarf_abbrev_section
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_ಸಾಲು_section      s1->dwarf_ಸಾಲು_section
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_aranges_section   s1->dwarf_aranges_section
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_str_section       s1->dwarf_str_section
#ವ್ಯಾಖ್ಯಾನಿಸು dwarf_ಸಾಲು_str_section  s1->dwarf_ಸಾಲು_str_section

#ವ್ಯಾಖ್ಯಾನಿಸು DWARF_MAX_128	((8 * ಗಾತ್ರ (int64_t) + 6) / 7)
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_read_1(ln,ಕೊನೆ) \
	((ln) < (ಕೊನೆ) ? *(ln)++ : 0)
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_read_2(ln,ಕೊನೆ) \
	((ln) + 1 < (ಕೊನೆ) ? read16le(((ln)+=2) - 2) : 0)
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_read_4(ln,ಕೊನೆ) \
	((ln) + 3 < (ಕೊನೆ) ? read32le(((ln)+=4) - 4) : 0)
#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_read_8(ln,ಕೊನೆ) \
	((ln) + 7 < (ಕೊನೆ) ? read64le(((ln)+=8) - 8) : 0)
ಸ್ಥಿರ ಸಾಲೊಳಗೆ uint64_t
dwarf_read_uleb128(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ **ln, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಕೊನೆ)
{
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *cp = *ln;
    uint64_t retval = 0;
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, ಕೊನೆ);
        retval |= (byte & 0x7f) << (i * 7);
	ಆದರೆ ((byte & 0x80) == 0)
	    ನಿಲ್ಲಿಸು;
    }
    *ln = cp;
    ಹಿಂತಿರುಗಿ retval;
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ int64_t
dwarf_read_sleb128(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ **ln, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಕೊನೆ)
{
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *cp = *ln;
    int64_t retval = 0;
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < DWARF_MAX_128; i++) {
	uint64_t byte = dwarf_read_1(cp, ಕೊನೆ);
        retval |= (byte & 0x7f) << (i * 7);
	ಆದರೆ ((byte & 0x80) == 0) {
	    ಆದರೆ ((byte & 0x40) && (i + 1) * 7 < 64)
		retval |= (uint64_t)-1LL << ((i + 1) * 7);
	    ನಿಲ್ಲಿಸು;
	}
    }
    *ln = cp;
    ಹಿಂತಿರುಗಿ retval;
}

/* default dwarf version for "-gdwarf" */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_MACHO
# define DEFAULT_DWARF_ಆವೃತ್ತಿ 2
#ಇಲ್ಲದಿದ್ದರೆ
# define DEFAULT_DWARF_ಆವೃತ್ತಿ 5
#ಆದರೆ_ಅಂತ್ಯ

/* default dwarf version for "-g". use 0 to emit stab debug infos */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_DWARF_ಆವೃತ್ತಿ
# define CONFIG_DWARF_ಆವೃತ್ತಿ 0
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined TCC_ಗುರಿ_X86_64
# define R_ದತ್ತಾಂಶ_32_DW R_X86_64_32
#ಇಲ್ಲದಿದ್ದರೆ
# define R_ದತ್ತಾಂಶ_32_DW R_ದತ್ತಾಂಶ_32
#ಆದರೆ_ಅಂತ್ಯ

/********************************************************/
#ಆದರೆ CONFIG_TCC_SEMLOCK
#ಆದರೆ defined _WIN32
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಅಸ್ಥಿರ LONG init; CRITICAL_SECTION cs; } TCCSem;
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ wait_sem(TCCSem *p) {
    ಆದರೆ (InterlockedCompareExchange(&p->init, 1, 0) == 0) {
        InitializeCriticalSection(&p->cs);
        InterlockedExchange(&p->init, 2);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆಗ (InterlockedCompareExchange(&p->init, 2, 2) != 2)
            Sleep(0);
    }
    EnterCriticalSection(&p->cs);
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ post_sem(TCCSem *p) {
    LeaveCriticalSection(&p->cs);
}
#ಅಥವಾಆದರೆ defined __APPLE__
#ಅನ್ತರ್ಭಾವ <dispatch/dispatch.h>
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ init; dispatch_semaphore_t sem; } TCCSem;
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ wait_sem(TCCSem *p) {
    ಆದರೆ (!p->init)
        p->sem = dispatch_semaphore_create(1), p->init = 1;
    dispatch_semaphore_wait(p->sem, DISPATCH_ಸಮಯ_FOREVER);
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ post_sem(TCCSem *p) {
    dispatch_semaphore_signal(p->sem);
}
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <semaphore.h>
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ init; sem_t sem; } TCCSem;
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ wait_sem(TCCSem *p) {
    ಆದರೆ (!p->init)
        sem_init(&p->sem, 0, 1), p->init = 1;
    ಆಗ (sem_wait(&p->sem) < 0 && errno == EINTR);
}
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ post_sem(TCCSem *p) {
    sem_post(&p->sem);
}
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_SEM(s) TCCSem s
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM wait_sem
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM post_sem
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_SEM(s)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_SEM(p)
#ವ್ಯಾಖ್ಯಾನಿಸು POST_SEM(p)
#ಆದರೆ_ಅಂತ್ಯ

/********************************************************/
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ST_ದತ್ತಾಂಶ
#ಆದರೆ ONE_ಮೂಲ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_ದತ್ತಾಂಶ ಸ್ಥಿರ
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ST_ದತ್ತಾಂಶ
#ಆದರೆ_ಅಂತ್ಯ
/********************************************************/

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಠ್ಯ_section        TCC_STATE_VAR(ಪಠ್ಯ_section)
#ವ್ಯಾಖ್ಯಾನಿಸು ದತ್ತಾಂಶ_section        TCC_STATE_VAR(ದತ್ತಾಂಶ_section)
#ವ್ಯಾಖ್ಯಾನಿಸು rodata_section      TCC_STATE_VAR(rodata_section)
#ವ್ಯಾಖ್ಯಾನಿಸು bss_section         TCC_STATE_VAR(bss_section)
#ವ್ಯಾಖ್ಯಾನಿಸು common_section      TCC_STATE_VAR(common_section)
#ವ್ಯಾಖ್ಯಾನಿಸು cur_ಪಠ್ಯ_section    TCC_STATE_VAR(cur_ಪಠ್ಯ_section)
#ವ್ಯಾಖ್ಯಾನಿಸು bounds_section      TCC_STATE_VAR(bounds_section)
#ವ್ಯಾಖ್ಯಾನಿಸು lbounds_section     TCC_STATE_VAR(lbounds_section)
#ವ್ಯಾಖ್ಯಾನಿಸು symtab_section      TCC_STATE_VAR(symtab_section)
#ವ್ಯಾಖ್ಯಾನಿಸು gnu_ext             TCC_STATE_VAR(gnu_ext)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_error_noabort   TCC_ಗಣ_STATE(_tcc_error_noabort)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_error           TCC_ಗಣ_STATE(_tcc_error)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_warning         TCC_ಗಣ_STATE(_tcc_warning)

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಟ್ಟು_idents        TCC_STATE_VAR(ಒಟ್ಟು_idents)
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಟ್ಟು_ಸಾಲುಗಳು         TCC_STATE_VAR(ಒಟ್ಟು_ಸಾಲುಗಳು)
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಟ್ಟು_ಬೈಟುಗಳು         TCC_STATE_VAR(ಒಟ್ಟು_ಬೈಟುಗಳು)

PUB_FUNC ಶೂನ್ಯ tcc_enter_state(TCCState *s1);
PUB_FUNC ಶೂನ್ಯ tcc_exit_state(TCCState *s1);

/* conditional warning depending on switch */
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_warning_c(sw) TCC_ಗಣ_STATE((\
    tcc_state->warn_ಅಂಕೆ = offsetof(TCCState, sw) \
    - offsetof(TCCState, warn_none), _tcc_warning))

/********************************************************/
#ಆದರೆ_ಅಂತ್ಯ /* _TCC_H */

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು TCC_STATE_VAR
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು TCC_ಗಣ_STATE

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USING_GLOBALS
# define TCC_STATE_VAR(sym) tcc_state->sym
# define TCC_ಗಣ_STATE(fn) fn
# undef USING_GLOBALS
# undef _tcc_error
#ಇಲ್ಲದಿದ್ದರೆ
# define TCC_STATE_VAR(sym) s1->sym
# define TCC_ಗಣ_STATE(fn) (tcc_enter_state(s1),fn)
# define _tcc_error use_tcc_error_noabort
#ಆದರೆ_ಅಂತ್ಯ
