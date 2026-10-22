/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* ISO C9x  7.18  Integer types <stdint.h>
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  Contributor: Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2000-12-02
 */


#اگر_تعریف_نشده _STDINT_H
#تعریف_کن _STDINT_H

#ضمن <_mingw.h>

#تعریف_کن __need_wint_t
#تعریف_کن __need_wchar_t
#ضمن "stddef.h"

#اگر_تعریف_نشده __int8_t_defined
#تعریف_کن __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
تعريفنوع علامتدار حرف int8_t;
تعريفنوع بیعلامت حرف   uint8_t;
تعريفنوع کوتاه  int16_t;
تعريفنوع بیعلامت کوتاه  uint16_t;
تعريفنوع صحيح  int32_t;
تعريفنوع بیعلامت   uint32_t;
تعريفنوع دراز دراز  int64_t;
تعريفنوع بیعلامت دراز دراز   uint64_t;
#پایان_اگر

/* 7.18.1.2  Minimum-width integer types */
تعريفنوع علامتدار حرف int_least8_t;
تعريفنوع بیعلامت حرف   uint_least8_t;
تعريفنوع کوتاه  int_least16_t;
تعريفنوع بیعلامت کوتاه  uint_least16_t;
تعريفنوع صحيح  int_least32_t;
تعريفنوع بیعلامت   uint_least32_t;
تعريفنوع دراز دراز  int_least64_t;
تعريفنوع بیعلامت دراز دراز   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
تعريفنوع حرف int_fast8_t;
تعريفنوع بیعلامت حرف uint_fast8_t;
تعريفنوع کوتاه  int_fast16_t;
تعريفنوع بیعلامت کوتاه  uint_fast16_t;
تعريفنوع صحيح  int_fast32_t;
تعريفنوع بیعلامت  صحيح  uint_fast32_t;
تعريفنوع دراز دراز  int_fast64_t;
تعريفنوع بیعلامت دراز دراز   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
تعريفنوع دراز دراز  intmax_t;
تعريفنوع بیعلامت دراز دراز   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#إذا !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#تعریف_کن INT8_MIN (-128)
#تعریف_کن INT16_MIN (-32768)
#تعریف_کن INT32_MIN (-2147483647 - 1)
#تعریف_کن INT64_MIN  (-9223372036854775807LL - 1)

#تعریف_کن INT8_MAX 127
#تعریف_کن INT16_MAX 32767
#تعریف_کن INT32_MAX 2147483647
#تعریف_کن INT64_MAX 9223372036854775807LL

#تعریف_کن UINT8_MAX 0xff /* 255U */
#تعریف_کن UINT16_MAX 0xffff /* 65535U */
#تعریف_کن UINT32_MAX 0xffffffff  /* 4294967295U */
#تعریف_کن UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#تعریف_کن INT_LEAST8_MIN INT8_MIN
#تعریف_کن INT_LEAST16_MIN INT16_MIN
#تعریف_کن INT_LEAST32_MIN INT32_MIN
#تعریف_کن INT_LEAST64_MIN INT64_MIN

#تعریف_کن INT_LEAST8_MAX INT8_MAX
#تعریف_کن INT_LEAST16_MAX INT16_MAX
#تعریف_کن INT_LEAST32_MAX INT32_MAX
#تعریف_کن INT_LEAST64_MAX INT64_MAX

#تعریف_کن UINT_LEAST8_MAX UINT8_MAX
#تعریف_کن UINT_LEAST16_MAX UINT16_MAX
#تعریف_کن UINT_LEAST32_MAX UINT32_MAX
#تعریف_کن UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#تعریف_کن INT_FAST8_MIN INT8_MIN
#تعریف_کن INT_FAST16_MIN INT16_MIN
#تعریف_کن INT_FAST32_MIN INT32_MIN
#تعریف_کن INT_FAST64_MIN INT64_MIN

#تعریف_کن INT_FAST8_MAX INT8_MAX
#تعریف_کن INT_FAST16_MAX INT16_MAX
#تعریف_کن INT_FAST32_MAX INT32_MAX
#تعریف_کن INT_FAST64_MAX INT64_MAX

#تعریف_کن UINT_FAST8_MAX UINT8_MAX
#تعریف_کن UINT_FAST16_MAX UINT16_MAX
#تعریف_کن UINT_FAST32_MAX UINT32_MAX
#تعریف_کن UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#اگر_تعریف_شده _WIN64
#تعریف_کن INTPTR_MIN INT64_MIN
#تعریف_کن INTPTR_MAX INT64_MAX
#تعریف_کن UINTPTR_MAX UINT64_MAX
#وإلا
#تعریف_کن INTPTR_MIN INT32_MIN
#تعریف_کن INTPTR_MAX INT32_MAX
#تعریف_کن UINTPTR_MAX UINT32_MAX
#پایان_اگر

/* 7.18.2.5  Limits of greatest-width integer types */
#تعریف_کن INTMAX_MIN INT64_MIN
#تعریف_کن INTMAX_MAX INT64_MAX
#تعریف_کن UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#اگر_تعریف_شده _WIN64
#تعریف_کن PTRDIFF_MIN INT64_MIN
#تعریف_کن PTRDIFF_MAX INT64_MAX
#وإلا
#تعریف_کن PTRDIFF_MIN INT32_MIN
#تعریف_کن PTRDIFF_MAX INT32_MAX
#پایان_اگر

#تعریف_کن SIG_ATOMIC_MIN INT32_MIN
#تعریف_کن SIG_ATOMIC_MAX INT32_MAX

#اگر_تعریف_نشده SIZE_MAX
#اگر_تعریف_شده _WIN64
#تعریف_کن SIZE_MAX UINT64_MAX
#وإلا
#تعریف_کن SIZE_MAX UINT32_MAX
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده WCHAR_MIN  /* also in wchar.h */
#تعریف_کن WCHAR_MIN 0
#تعریف_کن WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#پایان_اگر

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#تعریف_کن WINT_MIN 0
#تعریف_کن WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#پایان_اگر /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


/* 7.18.4  Macros for integer constants */
#إذا !defined ( __cplusplus) || defined (__STDC_CONSTANT_MACROS)

/* 7.18.4.1  Macros for minimum-width integer constants

    According to Douglas Gwyn <gwyn@arl.mil>:
	"This spec was changed in ISO/IEC 9899:1999 TC1; in ISO/IEC
	9899:1999 as initially published, the expansion was required
	to be an integer constant of precisely matching type, which
	is impossible to accomplish for the shorter types on most
	platforms, because C99 provides no standard way to designate
	an integer constant with width less than that of type int.
	TC1 changed this to require just an integer constant
	*expression* with *promoted* type."

	The trick used here is from Clive D W Feather.
*/

#تعریف_کن INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#تعریف_کن INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#تعریف_کن INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#تعریف_کن INT64_C(val) val##LL

#تعریف_کن UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#تعریف_کن UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#تعریف_کن UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#تعریف_کن UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#تعریف_کن INTMAX_C(val) val##LL
#تعریف_کن UINTMAX_C(val) val##ULL

#پایان_اگر  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#پایان_اگر
