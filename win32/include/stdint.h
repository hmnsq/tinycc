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


#अगर_अघोषित _STDINT_H
#घोषणा _STDINT_H

#समावेश <_mingw.h>

#घोषणा __need_wint_t
#घोषणा __need_wchar_t
#समावेश "stddef.h"

#अगर_अघोषित __int8_t_defined
#घोषणा __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
प्रकार चिन्हित अक्षर int8_t;
प्रकार अचिन्हित अक्षर   uint8_t;
प्रकार लघु  int16_t;
प्रकार अचिन्हित लघु  uint16_t;
प्रकार पूर्णांक  int32_t;
प्रकार अचिन्हित   uint32_t;
प्रकार दीर्घ दीर्घ  int64_t;
प्रकार अचिन्हित दीर्घ दीर्घ   uint64_t;
#पूर्ण_अगर

/* 7.18.1.2  Minimum-width integer types */
प्रकार चिन्हित अक्षर int_least8_t;
प्रकार अचिन्हित अक्षर   uint_least8_t;
प्रकार लघु  int_least16_t;
प्रकार अचिन्हित लघु  uint_least16_t;
प्रकार पूर्णांक  int_least32_t;
प्रकार अचिन्हित   uint_least32_t;
प्रकार दीर्घ दीर्घ  int_least64_t;
प्रकार अचिन्हित दीर्घ दीर्घ   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
प्रकार अक्षर int_fast8_t;
प्रकार अचिन्हित अक्षर uint_fast8_t;
प्रकार लघु  int_fast16_t;
प्रकार अचिन्हित लघु  uint_fast16_t;
प्रकार पूर्णांक  int_fast32_t;
प्रकार अचिन्हित  पूर्णांक  uint_fast32_t;
प्रकार दीर्घ दीर्घ  int_fast64_t;
प्रकार अचिन्हित दीर्घ दीर्घ   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
प्रकार दीर्घ दीर्घ  intmax_t;
प्रकार अचिन्हित दीर्घ दीर्घ   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#अगर !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#घोषणा INT8_MIN (-128)
#घोषणा INT16_MIN (-32768)
#घोषणा INT32_MIN (-2147483647 - 1)
#घोषणा INT64_MIN  (-9223372036854775807LL - 1)

#घोषणा INT8_MAX 127
#घोषणा INT16_MAX 32767
#घोषणा INT32_MAX 2147483647
#घोषणा INT64_MAX 9223372036854775807LL

#घोषणा UINT8_MAX 0xff /* 255U */
#घोषणा UINT16_MAX 0xffff /* 65535U */
#घोषणा UINT32_MAX 0xffffffff  /* 4294967295U */
#घोषणा UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#घोषणा INT_LEAST8_MIN INT8_MIN
#घोषणा INT_LEAST16_MIN INT16_MIN
#घोषणा INT_LEAST32_MIN INT32_MIN
#घोषणा INT_LEAST64_MIN INT64_MIN

#घोषणा INT_LEAST8_MAX INT8_MAX
#घोषणा INT_LEAST16_MAX INT16_MAX
#घोषणा INT_LEAST32_MAX INT32_MAX
#घोषणा INT_LEAST64_MAX INT64_MAX

#घोषणा UINT_LEAST8_MAX UINT8_MAX
#घोषणा UINT_LEAST16_MAX UINT16_MAX
#घोषणा UINT_LEAST32_MAX UINT32_MAX
#घोषणा UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#घोषणा INT_FAST8_MIN INT8_MIN
#घोषणा INT_FAST16_MIN INT16_MIN
#घोषणा INT_FAST32_MIN INT32_MIN
#घोषणा INT_FAST64_MIN INT64_MIN

#घोषणा INT_FAST8_MAX INT8_MAX
#घोषणा INT_FAST16_MAX INT16_MAX
#घोषणा INT_FAST32_MAX INT32_MAX
#घोषणा INT_FAST64_MAX INT64_MAX

#घोषणा UINT_FAST8_MAX UINT8_MAX
#घोषणा UINT_FAST16_MAX UINT16_MAX
#घोषणा UINT_FAST32_MAX UINT32_MAX
#घोषणा UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#अगर_घोषित _WIN64
#घोषणा INTPTR_MIN INT64_MIN
#घोषणा INTPTR_MAX INT64_MAX
#घोषणा UINTPTR_MAX UINT64_MAX
#अन्यथा
#घोषणा INTPTR_MIN INT32_MIN
#घोषणा INTPTR_MAX INT32_MAX
#घोषणा UINTPTR_MAX UINT32_MAX
#पूर्ण_अगर

/* 7.18.2.5  Limits of greatest-width integer types */
#घोषणा INTMAX_MIN INT64_MIN
#घोषणा INTMAX_MAX INT64_MAX
#घोषणा UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#अगर_घोषित _WIN64
#घोषणा PTRDIFF_MIN INT64_MIN
#घोषणा PTRDIFF_MAX INT64_MAX
#अन्यथा
#घोषणा PTRDIFF_MIN INT32_MIN
#घोषणा PTRDIFF_MAX INT32_MAX
#पूर्ण_अगर

#घोषणा SIG_ATOMIC_MIN INT32_MIN
#घोषणा SIG_ATOMIC_MAX INT32_MAX

#अगर_अघोषित SIZE_MAX
#अगर_घोषित _WIN64
#घोषणा SIZE_MAX UINT64_MAX
#अन्यथा
#घोषणा SIZE_MAX UINT32_MAX
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित WCHAR_MIN  /* also in wchar.h */
#घोषणा WCHAR_MIN 0
#घोषणा WCHAR_MAX ((ब_अक्षर_प्रकार)-1) /* UINT16_MAX */
#पूर्ण_अगर

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#घोषणा WINT_MIN 0
#घोषणा WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#पूर्ण_अगर /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


/* 7.18.4  Macros for integer constants */
#अगर !defined ( __cplusplus) || defined (__STDC_CONSTANT_MACROS)

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

#घोषणा INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#घोषणा INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#घोषणा INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#घोषणा INT64_C(val) val##LL

#घोषणा UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#घोषणा UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#घोषणा UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#घोषणा UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#घोषणा INTMAX_C(val) val##LL
#घोषणा UINTMAX_C(val) val##ULL

#पूर्ण_अगर  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#पूर्ण_अगर
