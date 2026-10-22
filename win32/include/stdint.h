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


#यदि_अपरिभाषितम् _STDINT_H
#परिभाषय _STDINT_H

#अन्तर्भाव <_mingw.h>

#परिभाषय __need_wint_t
#परिभाषय __need_wchar_t
#अन्तर्भाव "stddef.h"

#यदि_अपरिभाषितम् __int8_t_defined
#परिभाषय __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
प्रकारनिर्देश चिह्नित वर्ण int8_t;
प्रकारनिर्देश अचिह्नित वर्ण   uint8_t;
प्रकारनिर्देश ह्रस्व  int16_t;
प्रकारनिर्देश अचिह्नित ह्रस्व  uint16_t;
प्रकारनिर्देश पूर्णाङ्क  int32_t;
प्रकारनिर्देश अचिह्नित   uint32_t;
प्रकारनिर्देश दीर्घ दीर्घ  int64_t;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ   uint64_t;
#यदि_अन्तः

/* 7.18.1.2  Minimum-width integer types */
प्रकारनिर्देश चिह्नित वर्ण int_least8_t;
प्रकारनिर्देश अचिह्नित वर्ण   uint_least8_t;
प्रकारनिर्देश ह्रस्व  int_least16_t;
प्रकारनिर्देश अचिह्नित ह्रस्व  uint_least16_t;
प्रकारनिर्देश पूर्णाङ्क  int_least32_t;
प्रकारनिर्देश अचिह्नित   uint_least32_t;
प्रकारनिर्देश दीर्घ दीर्घ  int_least64_t;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
प्रकारनिर्देश वर्ण int_fast8_t;
प्रकारनिर्देश अचिह्नित वर्ण uint_fast8_t;
प्रकारनिर्देश ह्रस्व  int_fast16_t;
प्रकारनिर्देश अचिह्नित ह्रस्व  uint_fast16_t;
प्रकारनिर्देश पूर्णाङ्क  int_fast32_t;
प्रकारनिर्देश अचिह्नित  पूर्णाङ्क  uint_fast32_t;
प्रकारनिर्देश दीर्घ दीर्घ  int_fast64_t;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
प्रकारनिर्देश दीर्घ दीर्घ  intmax_t;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#यदि !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#परिभाषय INT8_MIN (-128)
#परिभाषय INT16_MIN (-32768)
#परिभाषय INT32_MIN (-2147483647 - 1)
#परिभाषय INT64_MIN  (-9223372036854775807LL - 1)

#परिभाषय INT8_MAX 127
#परिभाषय INT16_MAX 32767
#परिभाषय INT32_MAX 2147483647
#परिभाषय INT64_MAX 9223372036854775807LL

#परिभाषय UINT8_MAX 0xff /* 255U */
#परिभाषय UINT16_MAX 0xffff /* 65535U */
#परिभाषय UINT32_MAX 0xffffffff  /* 4294967295U */
#परिभाषय UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#परिभाषय INT_LEAST8_MIN INT8_MIN
#परिभाषय INT_LEAST16_MIN INT16_MIN
#परिभाषय INT_LEAST32_MIN INT32_MIN
#परिभाषय INT_LEAST64_MIN INT64_MIN

#परिभाषय INT_LEAST8_MAX INT8_MAX
#परिभाषय INT_LEAST16_MAX INT16_MAX
#परिभाषय INT_LEAST32_MAX INT32_MAX
#परिभाषय INT_LEAST64_MAX INT64_MAX

#परिभाषय UINT_LEAST8_MAX UINT8_MAX
#परिभाषय UINT_LEAST16_MAX UINT16_MAX
#परिभाषय UINT_LEAST32_MAX UINT32_MAX
#परिभाषय UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#परिभाषय INT_FAST8_MIN INT8_MIN
#परिभाषय INT_FAST16_MIN INT16_MIN
#परिभाषय INT_FAST32_MIN INT32_MIN
#परिभाषय INT_FAST64_MIN INT64_MIN

#परिभाषय INT_FAST8_MAX INT8_MAX
#परिभाषय INT_FAST16_MAX INT16_MAX
#परिभाषय INT_FAST32_MAX INT32_MAX
#परिभाषय INT_FAST64_MAX INT64_MAX

#परिभाषय UINT_FAST8_MAX UINT8_MAX
#परिभाषय UINT_FAST16_MAX UINT16_MAX
#परिभाषय UINT_FAST32_MAX UINT32_MAX
#परिभाषय UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#यदि_परिभाषितम् _WIN64
#परिभाषय INTPTR_MIN INT64_MIN
#परिभाषय INTPTR_MAX INT64_MAX
#परिभाषय UINTPTR_MAX UINT64_MAX
#अन्यथा
#परिभाषय INTPTR_MIN INT32_MIN
#परिभाषय INTPTR_MAX INT32_MAX
#परिभाषय UINTPTR_MAX UINT32_MAX
#यदि_अन्तः

/* 7.18.2.5  Limits of greatest-width integer types */
#परिभाषय INTMAX_MIN INT64_MIN
#परिभाषय INTMAX_MAX INT64_MAX
#परिभाषय UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#यदि_परिभाषितम् _WIN64
#परिभाषय PTRDIFF_MIN INT64_MIN
#परिभाषय PTRDIFF_MAX INT64_MAX
#अन्यथा
#परिभाषय PTRDIFF_MIN INT32_MIN
#परिभाषय PTRDIFF_MAX INT32_MAX
#यदि_अन्तः

#परिभाषय SIG_ATOMIC_MIN INT32_MIN
#परिभाषय SIG_ATOMIC_MAX INT32_MAX

#यदि_अपरिभाषितम् SIZE_MAX
#यदि_परिभाषितम् _WIN64
#परिभाषय SIZE_MAX UINT64_MAX
#अन्यथा
#परिभाषय SIZE_MAX UINT32_MAX
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् WCHAR_MIN  /* also in wchar.h */
#परिभाषय WCHAR_MIN 0
#परिभाषय WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#यदि_अन्तः

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#परिभाषय WINT_MIN 0
#परिभाषय WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#यदि_अन्तः /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


/* 7.18.4  Macros for integer constants */
#यदि !defined ( __cplusplus) || defined (__STDC_CONSTANT_MACROS)

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

#परिभाषय INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#परिभाषय INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#परिभाषय INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#परिभाषय INT64_C(val) val##LL

#परिभाषय UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#परिभाषय UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#परिभाषय UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#परिभाषय UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#परिभाषय INTMAX_C(val) val##LL
#परिभाषय UINTMAX_C(val) val##ULL

#यदि_अन्तः  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#यदि_अन्तः
