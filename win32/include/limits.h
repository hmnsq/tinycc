/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#جے_بنا_تعریف _INC_LIMITS
#تعریف_کرو _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#تعریف_کرو PATH_MAX	(259)

#تعریف_کرو CHAR_BIT 8
#تعریف_کرو SCHAR_MIN (-128)
#تعریف_کرو SCHAR_MAX 127
#تعریف_کرو UCHAR_MAX 0xff

#جے_بنا_تعریف __CHAR_UNSIGNED__
#تعریف_کرو CHAR_MIN SCHAR_MIN
#تعریف_کرو CHAR_MAX SCHAR_MAX
#وإلا
#تعریف_کرو CHAR_MIN 0
#تعریف_کرو CHAR_MAX UCHAR_MAX
#جے_انت

#تعریف_کرو MB_LEN_MAX 5
#تعریف_کرو SHRT_MIN (-32768)
#تعریف_کرو SHRT_MAX 32767
#تعریف_کرو USHRT_MAX 0xffff
#تعریف_کرو INT_MIN (-2147483647 - 1)
#تعریف_کرو ودھ_توں_ودھ_عدد 2147483647
#تعریف_کرو UINT_MAX 0xffffffff
#تعریف_کرو LONG_MIN (-2147483647L - 1)
#تعریف_کرو LONG_MAX 2147483647L
#تعریف_کرو ULONG_MAX 0xffffffffUL
#تعریف_کرو LLONG_MAX 9223372036854775807ll
#تعریف_کرو LLONG_MIN (-9223372036854775807ll - 1)
#تعریف_کرو ULLONG_MAX 0xffffffffffffffffull

#إذا INTEGRAL_MAX_بٹ >= 8
#تعریف_کرو _I8_MIN (-127 - 1)
#تعریف_کرو _I8_MAX 127i8
#تعریف_کرو _UI8_MAX 0xffu
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 16
#تعریف_کرو _I16_MIN (-32767 - 1)
#تعریف_کرو _I16_MAX 32767i16
#تعریف_کرو _UI16_MAX 0xffffu
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 32
#تعریف_کرو _I32_MIN (-2147483647 - 1)
#تعریف_کرو _I32_MAX 2147483647
#تعریف_کرو _UI32_MAX 0xffffffffu
#جے_انت

#إذا defined(__GNUC__)
#تعریف_رد LONG_LONG_MAX
#تعریف_کرو LONG_LONG_MAX 9223372036854775807ll
#تعریف_رد LONG_LONG_MIN
#تعریف_کرو LONG_LONG_MIN (-LONG_LONG_MAX-1)
#تعریف_رد ULONG_LONG_MAX
#تعریف_کرو ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 64
#تعریف_کرو _I64_MIN (-9223372036854775807ll - 1)
#تعریف_کرو _I64_MAX 9223372036854775807ll
#تعریف_کرو _UI64_MAX 0xffffffffffffffffull
#جے_انت

#جے_بنا_تعریف SIZE_MAX
#جے_تعریف_شدہ _WIN64
#تعریف_کرو SIZE_MAX _UI64_MAX
#وإلا
#تعریف_کرو SIZE_MAX UINT_MAX
#جے_انت
#جے_انت

#جے_تعریف_شدہ _POSIX_
#تعریف_کرو _POSIX_ARG_MAX 4096
#تعریف_کرو _POSIX_CHILD_MAX 6
#تعریف_کرو _POSIX_LINK_MAX 8
#تعریف_کرو _POSIX_MAX_CANON 255
#تعریف_کرو _POSIX_MAX_INPUT 255
#تعریف_کرو _POSIX_NAME_MAX 14
#تعریف_کرو _POSIX_NGROUPS_MAX 0
#تعریف_کرو _POSIX_OPEN_MAX 16
#تعریف_کرو _POSIX_PATH_MAX 255
#تعریف_کرو _POSIX_PIPE_BUF 512
#تعریف_کرو _POSIX_SSIZE_MAX 32767
#تعریف_کرو _POSIX_STREAM_MAX 8
#تعریف_کرو _POSIX_TZNAME_MAX 3
#تعریف_کرو ARG_MAX 14500
#تعریف_کرو LINK_MAX 1024
#تعریف_کرو MAX_CANON _POSIX_MAX_CANON
#تعریف_کرو MAX_INPUT _POSIX_MAX_INPUT
#تعریف_کرو NAME_MAX 255
#تعریف_کرو NGROUPS_MAX 16
#تعریف_کرو OPEN_MAX 32
#تعریف_کرو PATH_MAX 512
#تعریف_کرو PIPE_BUF _POSIX_PIPE_BUF
#تعریف_کرو SSIZE_MAX _POSIX_SSIZE_MAX
#تعریف_کرو دھارا_MAX 20
#تعریف_کرو TZNAME_MAX 10
#جے_انت
#جے_انت
