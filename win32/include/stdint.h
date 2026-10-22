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


#جے_بنا_تعریف _STDINT_H
#تعریف_کرو _STDINT_H

#ضمن <_mingw.h>

#تعریف_کرو __need_wint_t
#تعریف_کرو __need_wchar_t
#ضمن "stddef.h"

#جے_بنا_تعریف __int8_t_defined
#تعریف_کرو __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
تعريفنوع نشانیوالا حرف int8_t;
تعريفنوع بنانشانی حرف   uint8_t;
تعريفنوع چھوٹا  int16_t;
تعريفنوع بنانشانی چھوٹا  uint16_t;
تعريفنوع صحيح  int32_t;
تعريفنوع بنانشانی   uint32_t;
تعريفنوع لما لما  int64_t;
تعريفنوع بنانشانی لما لما   uint64_t;
#جے_انت

/* 7.18.1.2  Minimum-width integer types */
تعريفنوع نشانیوالا حرف int_least8_t;
تعريفنوع بنانشانی حرف   uint_least8_t;
تعريفنوع چھوٹا  int_least16_t;
تعريفنوع بنانشانی چھوٹا  uint_least16_t;
تعريفنوع صحيح  int_least32_t;
تعريفنوع بنانشانی   uint_least32_t;
تعريفنوع لما لما  int_least64_t;
تعريفنوع بنانشانی لما لما   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
تعريفنوع حرف int_fast8_t;
تعريفنوع بنانشانی حرف uint_fast8_t;
تعريفنوع چھوٹا  int_fast16_t;
تعريفنوع بنانشانی چھوٹا  uint_fast16_t;
تعريفنوع صحيح  int_fast32_t;
تعريفنوع بنانشانی  صحيح  uint_fast32_t;
تعريفنوع لما لما  int_fast64_t;
تعريفنوع بنانشانی لما لما   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
تعريفنوع لما لما  intmax_t;
تعريفنوع بنانشانی لما لما   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#إذا !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#تعریف_کرو INT8_MIN (-128)
#تعریف_کرو INT16_MIN (-32768)
#تعریف_کرو INT32_MIN (-2147483647 - 1)
#تعریف_کرو INT64_MIN  (-9223372036854775807LL - 1)

#تعریف_کرو INT8_MAX 127
#تعریف_کرو INT16_MAX 32767
#تعریف_کرو INT32_MAX 2147483647
#تعریف_کرو INT64_MAX 9223372036854775807LL

#تعریف_کرو UINT8_MAX 0xff /* 255U */
#تعریف_کرو UINT16_MAX 0xffff /* 65535U */
#تعریف_کرو UINT32_MAX 0xffffffff  /* 4294967295U */
#تعریف_کرو UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#تعریف_کرو INT_LEAST8_MIN INT8_MIN
#تعریف_کرو INT_LEAST16_MIN INT16_MIN
#تعریف_کرو INT_LEAST32_MIN INT32_MIN
#تعریف_کرو INT_LEAST64_MIN INT64_MIN

#تعریف_کرو INT_LEAST8_MAX INT8_MAX
#تعریف_کرو INT_LEAST16_MAX INT16_MAX
#تعریف_کرو INT_LEAST32_MAX INT32_MAX
#تعریف_کرو INT_LEAST64_MAX INT64_MAX

#تعریف_کرو UINT_LEAST8_MAX UINT8_MAX
#تعریف_کرو UINT_LEAST16_MAX UINT16_MAX
#تعریف_کرو UINT_LEAST32_MAX UINT32_MAX
#تعریف_کرو UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#تعریف_کرو INT_FAST8_MIN INT8_MIN
#تعریف_کرو INT_FAST16_MIN INT16_MIN
#تعریف_کرو INT_FAST32_MIN INT32_MIN
#تعریف_کرو INT_FAST64_MIN INT64_MIN

#تعریف_کرو INT_FAST8_MAX INT8_MAX
#تعریف_کرو INT_FAST16_MAX INT16_MAX
#تعریف_کرو INT_FAST32_MAX INT32_MAX
#تعریف_کرو INT_FAST64_MAX INT64_MAX

#تعریف_کرو UINT_FAST8_MAX UINT8_MAX
#تعریف_کرو UINT_FAST16_MAX UINT16_MAX
#تعریف_کرو UINT_FAST32_MAX UINT32_MAX
#تعریف_کرو UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#جے_تعریف_شدہ _WIN64
#تعریف_کرو INTPTR_MIN INT64_MIN
#تعریف_کرو INTPTR_MAX INT64_MAX
#تعریف_کرو UINTPTR_MAX UINT64_MAX
#وإلا
#تعریف_کرو INTPTR_MIN INT32_MIN
#تعریف_کرو INTPTR_MAX INT32_MAX
#تعریف_کرو UINTPTR_MAX UINT32_MAX
#جے_انت

/* 7.18.2.5  Limits of greatest-width integer types */
#تعریف_کرو INTMAX_MIN INT64_MIN
#تعریف_کرو INTMAX_MAX INT64_MAX
#تعریف_کرو UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#جے_تعریف_شدہ _WIN64
#تعریف_کرو PTRDIFF_MIN INT64_MIN
#تعریف_کرو PTRDIFF_MAX INT64_MAX
#وإلا
#تعریف_کرو PTRDIFF_MIN INT32_MIN
#تعریف_کرو PTRDIFF_MAX INT32_MAX
#جے_انت

#تعریف_کرو SIG_ATOMIC_MIN INT32_MIN
#تعریف_کرو SIG_ATOMIC_MAX INT32_MAX

#جے_بنا_تعریف SIZE_MAX
#جے_تعریف_شدہ _WIN64
#تعریف_کرو SIZE_MAX UINT64_MAX
#وإلا
#تعریف_کرو SIZE_MAX UINT32_MAX
#جے_انت
#جے_انت

#جے_بنا_تعریف WCHAR_MIN  /* also in wchar.h */
#تعریف_کرو WCHAR_MIN 0
#تعریف_کرو WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#جے_انت

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#تعریف_کرو WINT_MIN 0
#تعریف_کرو WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#جے_انت /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


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

#تعریف_کرو INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#تعریف_کرو INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#تعریف_کرو INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#تعریف_کرو INT64_C(val) val##LL

#تعریف_کرو UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#تعریف_کرو UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#تعریف_کرو UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#تعریف_کرو UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#تعریف_کرو INTMAX_C(val) val##LL
#تعریف_کرو UINTMAX_C(val) val##ULL

#جے_انت  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#جے_انت
