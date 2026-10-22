/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#అన్తర్భావ <_mingw.h>

#నిర్వచితం_కాకపోతే _INC_LIMITS
#నిర్వచించు _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#నిర్వచించు PATH_MAX	(259)

#నిర్వచించు CHAR_BIT 8
#నిర్వచించు SCHAR_MIN (-128)
#నిర్వచించు SCHAR_MAX 127
#నిర్వచించు UCHAR_MAX 0xff

#నిర్వచితం_కాకపోతే __CHAR_UNSIGNED__
#నిర్వచించు CHAR_MIN SCHAR_MIN
#నిర్వచించు CHAR_MAX SCHAR_MAX
#లేకపోతే
#నిర్వచించు CHAR_MIN 0
#నిర్వచించు CHAR_MAX UCHAR_MAX
#అయితే_ముగింపు

#నిర్వచించు MB_LEN_MAX 5
#నిర్వచించు SHRT_MIN (-32768)
#నిర్వచించు SHRT_MAX 32767
#నిర్వచించు USHRT_MAX 0xffff
#నిర్వచించు INT_MIN (-2147483647 - 1)
#నిర్వచించు గరిష్ఠ_పూర్ణాంకం 2147483647
#నిర్వచించు UINT_MAX 0xffffffff
#నిర్వచించు LONG_MIN (-2147483647L - 1)
#నిర్వచించు LONG_MAX 2147483647L
#నిర్వచించు ULONG_MAX 0xffffffffUL
#నిర్వచించు LLONG_MAX 9223372036854775807ll
#నిర్వచించు LLONG_MIN (-9223372036854775807ll - 1)
#నిర్వచించు ULLONG_MAX 0xffffffffffffffffull

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 8
#నిర్వచించు _I8_MIN (-127 - 1)
#నిర్వచించు _I8_MAX 127i8
#నిర్వచించు _UI8_MAX 0xffu
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 16
#నిర్వచించు _I16_MIN (-32767 - 1)
#నిర్వచించు _I16_MAX 32767i16
#నిర్వచించు _UI16_MAX 0xffffu
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 32
#నిర్వచించు _I32_MIN (-2147483647 - 1)
#నిర్వచించు _I32_MAX 2147483647
#నిర్వచించు _UI32_MAX 0xffffffffu
#అయితే_ముగింపు

#ఒకవేళ defined(__GNUC__)
#నిర్వచనం_రద్దు LONG_LONG_MAX
#నిర్వచించు LONG_LONG_MAX 9223372036854775807ll
#నిర్వచనం_రద్దు LONG_LONG_MIN
#నిర్వచించు LONG_LONG_MIN (-LONG_LONG_MAX-1)
#నిర్వచనం_రద్దు ULONG_LONG_MAX
#నిర్వచించు ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
#నిర్వచించు _I64_MIN (-9223372036854775807ll - 1)
#నిర్వచించు _I64_MAX 9223372036854775807ll
#నిర్వచించు _UI64_MAX 0xffffffffffffffffull
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే SIZE_MAX
#నిర్వచితమైతే _WIN64
#నిర్వచించు SIZE_MAX _UI64_MAX
#లేకపోతే
#నిర్వచించు SIZE_MAX UINT_MAX
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే _POSIX_
#నిర్వచించు _POSIX_ARG_MAX 4096
#నిర్వచించు _POSIX_CHILD_MAX 6
#నిర్వచించు _POSIX_LINK_MAX 8
#నిర్వచించు _POSIX_MAX_CANON 255
#నిర్వచించు _POSIX_MAX_INPUT 255
#నిర్వచించు _POSIX_NAME_MAX 14
#నిర్వచించు _POSIX_NGROUPS_MAX 0
#నిర్వచించు _POSIX_OPEN_MAX 16
#నిర్వచించు _POSIX_PATH_MAX 255
#నిర్వచించు _POSIX_PIPE_BUF 512
#నిర్వచించు _POSIX_SSIZE_MAX 32767
#నిర్వచించు _POSIX_STREAM_MAX 8
#నిర్వచించు _POSIX_TZNAME_MAX 3
#నిర్వచించు ARG_MAX 14500
#నిర్వచించు LINK_MAX 1024
#నిర్వచించు MAX_CANON _POSIX_MAX_CANON
#నిర్వచించు MAX_INPUT _POSIX_MAX_INPUT
#నిర్వచించు NAME_MAX 255
#నిర్వచించు NGROUPS_MAX 16
#నిర్వచించు OPEN_MAX 32
#నిర్వచించు PATH_MAX 512
#నిర్వచించు PIPE_BUF _POSIX_PIPE_BUF
#నిర్వచించు SSIZE_MAX _POSIX_SSIZE_MAX
#నిర్వచించు ప్రవాహం_MAX 20
#నిర్వచించు TZNAME_MAX 10
#అయితే_ముగింపు
#అయితే_ముగింపు
