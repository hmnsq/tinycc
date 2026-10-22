/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#که_نه_تعریف_شوی _INC_LIMITS
#تعریف_کړه _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#تعریف_کړه PATH_MAX	(259)

#تعریف_کړه CHAR_BIT 8
#تعریف_کړه SCHAR_MIN (-128)
#تعریف_کړه SCHAR_MAX 127
#تعریف_کړه UCHAR_MAX 0xff

#که_نه_تعریف_شوی __CHAR_UNSIGNED__
#تعریف_کړه CHAR_MIN SCHAR_MIN
#تعریف_کړه CHAR_MAX SCHAR_MAX
#وإلا
#تعریف_کړه CHAR_MIN 0
#تعریف_کړه CHAR_MAX UCHAR_MAX
#د_که_پای

#تعریف_کړه MB_LEN_MAX 5
#تعریف_کړه SHRT_MIN (-32768)
#تعریف_کړه SHRT_MAX 32767
#تعریف_کړه USHRT_MAX 0xffff
#تعریف_کړه INT_MIN (-2147483647 - 1)
#تعریف_کړه لوی_عدد 2147483647
#تعریف_کړه UINT_MAX 0xffffffff
#تعریف_کړه LONG_MIN (-2147483647L - 1)
#تعریف_کړه LONG_MAX 2147483647L
#تعریف_کړه ULONG_MAX 0xffffffffUL
#تعریف_کړه LLONG_MAX 9223372036854775807ll
#تعریف_کړه LLONG_MIN (-9223372036854775807ll - 1)
#تعریف_کړه ULLONG_MAX 0xffffffffffffffffull

#إذا INTEGRAL_MAX_بټونه >= 8
#تعریف_کړه _I8_MIN (-127 - 1)
#تعریف_کړه _I8_MAX 127i8
#تعریف_کړه _UI8_MAX 0xffu
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 16
#تعریف_کړه _I16_MIN (-32767 - 1)
#تعریف_کړه _I16_MAX 32767i16
#تعریف_کړه _UI16_MAX 0xffffu
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 32
#تعریف_کړه _I32_MIN (-2147483647 - 1)
#تعریف_کړه _I32_MAX 2147483647
#تعریف_کړه _UI32_MAX 0xffffffffu
#د_که_پای

#إذا defined(__GNUC__)
#تعریف_لغوه LONG_LONG_MAX
#تعریف_کړه LONG_LONG_MAX 9223372036854775807ll
#تعریف_لغوه LONG_LONG_MIN
#تعریف_کړه LONG_LONG_MIN (-LONG_LONG_MAX-1)
#تعریف_لغوه ULONG_LONG_MAX
#تعریف_کړه ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 64
#تعریف_کړه _I64_MIN (-9223372036854775807ll - 1)
#تعریف_کړه _I64_MAX 9223372036854775807ll
#تعریف_کړه _UI64_MAX 0xffffffffffffffffull
#د_که_پای

#که_نه_تعریف_شوی SIZE_MAX
#که_تعریف_شوی _WIN64
#تعریف_کړه SIZE_MAX _UI64_MAX
#وإلا
#تعریف_کړه SIZE_MAX UINT_MAX
#د_که_پای
#د_که_پای

#که_تعریف_شوی _POSIX_
#تعریف_کړه _POSIX_ARG_MAX 4096
#تعریف_کړه _POSIX_CHILD_MAX 6
#تعریف_کړه _POSIX_LINK_MAX 8
#تعریف_کړه _POSIX_MAX_CANON 255
#تعریف_کړه _POSIX_MAX_INPUT 255
#تعریف_کړه _POSIX_NAME_MAX 14
#تعریف_کړه _POSIX_NGROUPS_MAX 0
#تعریف_کړه _POSIX_OPEN_MAX 16
#تعریف_کړه _POSIX_PATH_MAX 255
#تعریف_کړه _POSIX_PIPE_BUF 512
#تعریف_کړه _POSIX_SSIZE_MAX 32767
#تعریف_کړه _POSIX_STREAM_MAX 8
#تعریف_کړه _POSIX_TZNAME_MAX 3
#تعریف_کړه ARG_MAX 14500
#تعریف_کړه LINK_MAX 1024
#تعریف_کړه MAX_CANON _POSIX_MAX_CANON
#تعریف_کړه MAX_INPUT _POSIX_MAX_INPUT
#تعریف_کړه NAME_MAX 255
#تعریف_کړه NGROUPS_MAX 16
#تعریف_کړه OPEN_MAX 32
#تعریف_کړه PATH_MAX 512
#تعریف_کړه PIPE_BUF _POSIX_PIPE_BUF
#تعریف_کړه SSIZE_MAX _POSIX_SSIZE_MAX
#تعریف_کړه بهیر_MAX 20
#تعریف_کړه TZNAME_MAX 10
#د_که_پای
#د_که_پای
