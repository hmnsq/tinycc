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


#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDINT_H
#ವ್ಯಾಖ್ಯಾನಿಸು _STDINT_H

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿಸು __need_wint_t
#ವ್ಯಾಖ್ಯಾನಿಸು __need_wchar_t
#ಅನ್ತರ್ಭಾವ "stddef.h"

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __int8_t_defined
#ವ್ಯಾಖ್ಯಾನಿಸು __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ int8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ   uint8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಗಿಡ್ಡ  int16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  uint16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ  int32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ   uint32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ  int64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ   uint64_t;
#ಆದರೆ_ಅಂತ್ಯ

/* 7.18.1.2  Minimum-width integer types */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ int_least8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ   uint_least8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಗಿಡ್ಡ  int_least16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  uint_least16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ  int_least32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ   uint_least32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ  int_least64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ int_fast8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ uint_fast8_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಗಿಡ್ಡ  int_fast16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  uint_fast16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ  int_fast32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ  ಪೂರ್ಣಾಂಕ  uint_fast32_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ  int_fast64_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ  intmax_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#ಆದರೆ !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#ವ್ಯಾಖ್ಯಾನಿಸು INT8_MIN (-128)
#ವ್ಯಾಖ್ಯಾನಿಸು INT16_MIN (-32768)
#ವ್ಯಾಖ್ಯಾನಿಸು INT32_MIN (-2147483647 - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು INT64_MIN  (-9223372036854775807LL - 1)

#ವ್ಯಾಖ್ಯಾನಿಸು INT8_MAX 127
#ವ್ಯಾಖ್ಯಾನಿಸು INT16_MAX 32767
#ವ್ಯಾಖ್ಯಾನಿಸು INT32_MAX 2147483647
#ವ್ಯಾಖ್ಯಾನಿಸು INT64_MAX 9223372036854775807LL

#ವ್ಯಾಖ್ಯಾನಿಸು UINT8_MAX 0xff /* 255U */
#ವ್ಯಾಖ್ಯಾನಿಸು UINT16_MAX 0xffff /* 65535U */
#ವ್ಯಾಖ್ಯಾನಿಸು UINT32_MAX 0xffffffff  /* 4294967295U */
#ವ್ಯಾಖ್ಯಾನಿಸು UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST8_MIN INT8_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST16_MIN INT16_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST32_MIN INT32_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST64_MIN INT64_MIN

#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST8_MAX INT8_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST16_MAX INT16_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST32_MAX INT32_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು INT_LEAST64_MAX INT64_MAX

#ವ್ಯಾಖ್ಯಾನಿಸು UINT_LEAST8_MAX UINT8_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_LEAST16_MAX UINT16_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_LEAST32_MAX UINT32_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST8_MIN INT8_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST16_MIN INT16_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST32_MIN INT32_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST64_MIN INT64_MIN

#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST8_MAX INT8_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST16_MAX INT16_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST32_MAX INT32_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು INT_FAST64_MAX INT64_MAX

#ವ್ಯಾಖ್ಯಾನಿಸು UINT_FAST8_MAX UINT8_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_FAST16_MAX UINT16_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_FAST32_MAX UINT32_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು INTPTR_MIN INT64_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INTPTR_MAX INT64_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINTPTR_MAX UINT64_MAX
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು INTPTR_MIN INT32_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INTPTR_MAX INT32_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINTPTR_MAX UINT32_MAX
#ಆದರೆ_ಅಂತ್ಯ

/* 7.18.2.5  Limits of greatest-width integer types */
#ವ್ಯಾಖ್ಯಾನಿಸು INTMAX_MIN INT64_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು INTMAX_MAX INT64_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು PTRDIFF_MIN INT64_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು PTRDIFF_MAX INT64_MAX
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PTRDIFF_MIN INT32_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು PTRDIFF_MAX INT32_MAX
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SIG_ATOMIC_MIN INT32_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು SIG_ATOMIC_MAX INT32_MAX

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SIZE_MAX
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು SIZE_MAX UINT64_MAX
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SIZE_MAX UINT32_MAX
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WCHAR_MIN  /* also in wchar.h */
#ವ್ಯಾಖ್ಯಾನಿಸು WCHAR_MIN 0
#ವ್ಯಾಖ್ಯಾನಿಸು WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#ಆದರೆ_ಅಂತ್ಯ

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#ವ್ಯಾಖ್ಯಾನಿಸು WINT_MIN 0
#ವ್ಯಾಖ್ಯಾನಿಸು WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#ಆದರೆ_ಅಂತ್ಯ /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


/* 7.18.4  Macros for integer constants */
#ಆದರೆ !defined ( __cplusplus) || defined (__STDC_CONSTANT_MACROS)

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

#ವ್ಯಾಖ್ಯಾನಿಸು INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#ವ್ಯಾಖ್ಯಾನಿಸು INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#ವ್ಯಾಖ್ಯಾನಿಸು INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#ವ್ಯಾಖ್ಯಾನಿಸು INT64_C(val) val##LL

#ವ್ಯಾಖ್ಯಾನಿಸು UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#ವ್ಯಾಖ್ಯಾನಿಸು UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#ವ್ಯಾಖ್ಯಾನಿಸು UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#ವ್ಯಾಖ್ಯಾನಿಸು UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#ವ್ಯಾಖ್ಯಾನಿಸು INTMAX_C(val) val##LL
#ವ್ಯಾಖ್ಯಾನಿಸು UINTMAX_C(val) val##ULL

#ಆದರೆ_ಅಂತ್ಯ  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#ಆದರೆ_ಅಂತ್ಯ
