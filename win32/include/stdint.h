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


#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDINT_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDINT_H

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __need_wint_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __need_wchar_t
#ਅਨ੍ਤਰ੍ਭਾਵ "stddef.h"

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __int8_t_defined
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ int8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ   uint8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਛੋਟਾ  int16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  uint16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ  int32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ   uint32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ  int64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ   uint64_t;
#ਜੇ_ਅੰਤ

/* 7.18.1.2  Minimum-width integer types */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ int_least8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ   uint_least8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਛੋਟਾ  int_least16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  uint_least16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ  int_least32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ   uint_least32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ  int_least64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ int_fast8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ uint_fast8_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਛੋਟਾ  int_fast16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  uint_fast16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ  int_fast32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ  ਪੂਰਨ  uint_fast32_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ  int_fast64_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ  intmax_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#ਜੇ !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT8_MIN (-128)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT16_MIN (-32768)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT32_MIN (-2147483647 - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT64_MIN  (-9223372036854775807LL - 1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT8_MAX 127
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT16_MAX 32767
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT32_MAX 2147483647
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT64_MAX 9223372036854775807LL

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT8_MAX 0xff /* 255U */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT16_MAX 0xffff /* 65535U */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT32_MAX 0xffffffff  /* 4294967295U */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST8_MIN INT8_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST16_MIN INT16_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST32_MIN INT32_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST64_MIN INT64_MIN

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST8_MAX INT8_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST16_MAX INT16_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST32_MAX INT32_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_LEAST64_MAX INT64_MAX

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_LEAST8_MAX UINT8_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_LEAST16_MAX UINT16_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_LEAST32_MAX UINT32_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST8_MIN INT8_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST16_MIN INT16_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST32_MIN INT32_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST64_MIN INT64_MIN

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST8_MAX INT8_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST16_MAX INT16_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST32_MAX INT32_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_FAST64_MAX INT64_MAX

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_FAST8_MAX UINT8_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_FAST16_MAX UINT16_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_FAST32_MAX UINT32_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTPTR_MIN INT64_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTPTR_MAX INT64_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINTPTR_MAX UINT64_MAX
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTPTR_MIN INT32_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTPTR_MAX INT32_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINTPTR_MAX UINT32_MAX
#ਜੇ_ਅੰਤ

/* 7.18.2.5  Limits of greatest-width integer types */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTMAX_MIN INT64_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTMAX_MAX INT64_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTRDIFF_MIN INT64_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTRDIFF_MAX INT64_MAX
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTRDIFF_MIN INT32_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PTRDIFF_MAX INT32_MAX
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_ATOMIC_MIN INT32_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_ATOMIC_MAX INT32_MAX

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SIZE_MAX
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZE_MAX UINT64_MAX
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZE_MAX UINT32_MAX
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WCHAR_MIN  /* also in wchar.h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WCHAR_MIN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#ਜੇ_ਅੰਤ

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINT_MIN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#ਜੇ_ਅੰਤ /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


/* 7.18.4  Macros for integer constants */
#ਜੇ !defined ( __cplusplus) || defined (__STDC_CONSTANT_MACROS)

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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT64_C(val) val##LL

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INTMAX_C(val) val##LL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINTMAX_C(val) val##ULL

#ਜੇ_ਅੰਤ  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#ਜੇ_ਅੰਤ
