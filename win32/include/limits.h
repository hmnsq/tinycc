/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#اگر_تعریف_نشده _INC_LIMITS
#تعریف_کن _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#تعریف_کن PATH_MAX	(259)

#تعریف_کن CHAR_BIT 8
#تعریف_کن SCHAR_MIN (-128)
#تعریف_کن SCHAR_MAX 127
#تعریف_کن UCHAR_MAX 0xff

#اگر_تعریف_نشده __CHAR_UNSIGNED__
#تعریف_کن CHAR_MIN SCHAR_MIN
#تعریف_کن CHAR_MAX SCHAR_MAX
#وإلا
#تعریف_کن CHAR_MIN 0
#تعریف_کن CHAR_MAX UCHAR_MAX
#پایان_اگر

#تعریف_کن MB_LEN_MAX 5
#تعریف_کن SHRT_MIN (-32768)
#تعریف_کن SHRT_MAX 32767
#تعریف_کن USHRT_MAX 0xffff
#تعریف_کن INT_MIN (-2147483647 - 1)
#تعریف_کن بیشترین_صحیح 2147483647
#تعریف_کن UINT_MAX 0xffffffff
#تعریف_کن LONG_MIN (-2147483647L - 1)
#تعریف_کن LONG_MAX 2147483647L
#تعریف_کن ULONG_MAX 0xffffffffUL
#تعریف_کن LLONG_MAX 9223372036854775807ll
#تعریف_کن LLONG_MIN (-9223372036854775807ll - 1)
#تعریف_کن ULLONG_MAX 0xffffffffffffffffull

#إذا INTEGRAL_MAX_بیتها >= 8
#تعریف_کن _I8_MIN (-127 - 1)
#تعریف_کن _I8_MAX 127i8
#تعریف_کن _UI8_MAX 0xffu
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 16
#تعریف_کن _I16_MIN (-32767 - 1)
#تعریف_کن _I16_MAX 32767i16
#تعریف_کن _UI16_MAX 0xffffu
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 32
#تعریف_کن _I32_MIN (-2147483647 - 1)
#تعریف_کن _I32_MAX 2147483647
#تعریف_کن _UI32_MAX 0xffffffffu
#پایان_اگر

#إذا defined(__GNUC__)
#لغو_تعریف LONG_LONG_MAX
#تعریف_کن LONG_LONG_MAX 9223372036854775807ll
#لغو_تعریف LONG_LONG_MIN
#تعریف_کن LONG_LONG_MIN (-LONG_LONG_MAX-1)
#لغو_تعریف ULONG_LONG_MAX
#تعریف_کن ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 64
#تعریف_کن _I64_MIN (-9223372036854775807ll - 1)
#تعریف_کن _I64_MAX 9223372036854775807ll
#تعریف_کن _UI64_MAX 0xffffffffffffffffull
#پایان_اگر

#اگر_تعریف_نشده SIZE_MAX
#اگر_تعریف_شده _WIN64
#تعریف_کن SIZE_MAX _UI64_MAX
#وإلا
#تعریف_کن SIZE_MAX UINT_MAX
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده _POSIX_
#تعریف_کن _POSIX_ARG_MAX 4096
#تعریف_کن _POSIX_CHILD_MAX 6
#تعریف_کن _POSIX_LINK_MAX 8
#تعریف_کن _POSIX_MAX_CANON 255
#تعریف_کن _POSIX_MAX_INPUT 255
#تعریف_کن _POSIX_NAME_MAX 14
#تعریف_کن _POSIX_NGROUPS_MAX 0
#تعریف_کن _POSIX_OPEN_MAX 16
#تعریف_کن _POSIX_PATH_MAX 255
#تعریف_کن _POSIX_PIPE_BUF 512
#تعریف_کن _POSIX_SSIZE_MAX 32767
#تعریف_کن _POSIX_STREAM_MAX 8
#تعریف_کن _POSIX_TZNAME_MAX 3
#تعریف_کن ARG_MAX 14500
#تعریف_کن LINK_MAX 1024
#تعریف_کن MAX_CANON _POSIX_MAX_CANON
#تعریف_کن MAX_INPUT _POSIX_MAX_INPUT
#تعریف_کن NAME_MAX 255
#تعریف_کن NGROUPS_MAX 16
#تعریف_کن OPEN_MAX 32
#تعریف_کن PATH_MAX 512
#تعریف_کن PIPE_BUF _POSIX_PIPE_BUF
#تعریف_کن SSIZE_MAX _POSIX_SSIZE_MAX
#تعریف_کن جریان_MAX 20
#تعریف_کن TZNAME_MAX 10
#پایان_اگر
#پایان_اگر
