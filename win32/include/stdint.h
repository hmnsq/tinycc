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


#నిర్వచితం_కాకపోతే _STDINT_H
#నిర్వచించు _STDINT_H

#అన్తర్భావ <_mingw.h>

#నిర్వచించు __need_wint_t
#నిర్వచించు __need_wchar_t
#అన్తర్భావ "stddef.h"

#నిర్వచితం_కాకపోతే __int8_t_defined
#నిర్వచించు __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
రకనిర్వచనం గుర్తుగల అక్షరం int8_t;
రకనిర్వచనం గుర్తులేని అక్షరం   uint8_t;
రకనిర్వచనం పొట్టి  int16_t;
రకనిర్వచనం గుర్తులేని పొట్టి  uint16_t;
రకనిర్వచనం పూర్ణాంకం  int32_t;
రకనిర్వచనం గుర్తులేని   uint32_t;
రకనిర్వచనం దీర్ఘ దీర్ఘ  int64_t;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ   uint64_t;
#అయితే_ముగింపు

/* 7.18.1.2  Minimum-width integer types */
రకనిర్వచనం గుర్తుగల అక్షరం int_least8_t;
రకనిర్వచనం గుర్తులేని అక్షరం   uint_least8_t;
రకనిర్వచనం పొట్టి  int_least16_t;
రకనిర్వచనం గుర్తులేని పొట్టి  uint_least16_t;
రకనిర్వచనం పూర్ణాంకం  int_least32_t;
రకనిర్వచనం గుర్తులేని   uint_least32_t;
రకనిర్వచనం దీర్ఘ దీర్ఘ  int_least64_t;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest for all purposes
 *  Here we use the exact-width types for 8 and 16-bit ints.
 */
రకనిర్వచనం అక్షరం int_fast8_t;
రకనిర్వచనం గుర్తులేని అక్షరం uint_fast8_t;
రకనిర్వచనం పొట్టి  int_fast16_t;
రకనిర్వచనం గుర్తులేని పొట్టి  uint_fast16_t;
రకనిర్వచనం పూర్ణాంకం  int_fast32_t;
రకనిర్వచనం గుర్తులేని  పూర్ణాంకం  uint_fast32_t;
రకనిర్వచనం దీర్ఘ దీర్ఘ  int_fast64_t;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
రకనిర్వచనం దీర్ఘ దీర్ఘ  intmax_t;
రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#ఒకవేళ !defined ( __cplusplus) || defined (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#నిర్వచించు INT8_MIN (-128)
#నిర్వచించు INT16_MIN (-32768)
#నిర్వచించు INT32_MIN (-2147483647 - 1)
#నిర్వచించు INT64_MIN  (-9223372036854775807LL - 1)

#నిర్వచించు INT8_MAX 127
#నిర్వచించు INT16_MAX 32767
#నిర్వచించు INT32_MAX 2147483647
#నిర్వచించు INT64_MAX 9223372036854775807LL

#నిర్వచించు UINT8_MAX 0xff /* 255U */
#నిర్వచించు UINT16_MAX 0xffff /* 65535U */
#నిర్వచించు UINT32_MAX 0xffffffff  /* 4294967295U */
#నిర్వచించు UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#నిర్వచించు INT_LEAST8_MIN INT8_MIN
#నిర్వచించు INT_LEAST16_MIN INT16_MIN
#నిర్వచించు INT_LEAST32_MIN INT32_MIN
#నిర్వచించు INT_LEAST64_MIN INT64_MIN

#నిర్వచించు INT_LEAST8_MAX INT8_MAX
#నిర్వచించు INT_LEAST16_MAX INT16_MAX
#నిర్వచించు INT_LEAST32_MAX INT32_MAX
#నిర్వచించు INT_LEAST64_MAX INT64_MAX

#నిర్వచించు UINT_LEAST8_MAX UINT8_MAX
#నిర్వచించు UINT_LEAST16_MAX UINT16_MAX
#నిర్వచించు UINT_LEAST32_MAX UINT32_MAX
#నిర్వచించు UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#నిర్వచించు INT_FAST8_MIN INT8_MIN
#నిర్వచించు INT_FAST16_MIN INT16_MIN
#నిర్వచించు INT_FAST32_MIN INT32_MIN
#నిర్వచించు INT_FAST64_MIN INT64_MIN

#నిర్వచించు INT_FAST8_MAX INT8_MAX
#నిర్వచించు INT_FAST16_MAX INT16_MAX
#నిర్వచించు INT_FAST32_MAX INT32_MAX
#నిర్వచించు INT_FAST64_MAX INT64_MAX

#నిర్వచించు UINT_FAST8_MAX UINT8_MAX
#నిర్వచించు UINT_FAST16_MAX UINT16_MAX
#నిర్వచించు UINT_FAST32_MAX UINT32_MAX
#నిర్వచించు UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#నిర్వచితమైతే _WIN64
#నిర్వచించు INTPTR_MIN INT64_MIN
#నిర్వచించు INTPTR_MAX INT64_MAX
#నిర్వచించు UINTPTR_MAX UINT64_MAX
#లేకపోతే
#నిర్వచించు INTPTR_MIN INT32_MIN
#నిర్వచించు INTPTR_MAX INT32_MAX
#నిర్వచించు UINTPTR_MAX UINT32_MAX
#అయితే_ముగింపు

/* 7.18.2.5  Limits of greatest-width integer types */
#నిర్వచించు INTMAX_MIN INT64_MIN
#నిర్వచించు INTMAX_MAX INT64_MAX
#నిర్వచించు UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#నిర్వచితమైతే _WIN64
#నిర్వచించు PTRDIFF_MIN INT64_MIN
#నిర్వచించు PTRDIFF_MAX INT64_MAX
#లేకపోతే
#నిర్వచించు PTRDIFF_MIN INT32_MIN
#నిర్వచించు PTRDIFF_MAX INT32_MAX
#అయితే_ముగింపు

#నిర్వచించు SIG_ATOMIC_MIN INT32_MIN
#నిర్వచించు SIG_ATOMIC_MAX INT32_MAX

#నిర్వచితం_కాకపోతే SIZE_MAX
#నిర్వచితమైతే _WIN64
#నిర్వచించు SIZE_MAX UINT64_MAX
#లేకపోతే
#నిర్వచించు SIZE_MAX UINT32_MAX
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WCHAR_MIN  /* also in wchar.h */
#నిర్వచించు WCHAR_MIN 0
#నిర్వచించు WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#అయితే_ముగింపు

/*
 * wint_t is unsigned short for compatibility with MS runtime
 */
#నిర్వచించు WINT_MIN 0
#నిర్వచించు WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#అయితే_ముగింపు /* !defined ( __cplusplus) || defined __STDC_LIMIT_MACROS */


/* 7.18.4  Macros for integer constants */
#ఒకవేళ !defined ( __cplusplus) || defined (__STDC_CONSTANT_MACROS)

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

#నిర్వచించు INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#నిర్వచించు INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#నిర్వచించు INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 for long long because, without
    suffix, (val) will be evaluated as int, not intmax_t */
#నిర్వచించు INT64_C(val) val##LL

#నిర్వచించు UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#నిర్వచించు UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#నిర్వచించు UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#నిర్వచించు UINT64_C(val) val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants */
#నిర్వచించు INTMAX_C(val) val##LL
#నిర్వచించు UINTMAX_C(val) val##ULL

#అయితే_ముగింపు  /* !defined ( __cplusplus) || defined __STDC_CONSTANT_MACROS */

#అయితే_ముగింపు
