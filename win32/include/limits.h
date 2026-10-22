/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل _INC_LIMITS
#وصف_ڪريو _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#وصف_ڪريو PATH_MAX	(259)

#وصف_ڪريو CHAR_BIT 8
#وصف_ڪريو SCHAR_MIN (-128)
#وصف_ڪريو SCHAR_MAX 127
#وصف_ڪريو UCHAR_MAX 0xff

#جيڪڏهن_وصف_نه_ٿيل __CHAR_UNSIGNED__
#وصف_ڪريو CHAR_MIN SCHAR_MIN
#وصف_ڪريو CHAR_MAX SCHAR_MAX
#وإلا
#وصف_ڪريو CHAR_MIN 0
#وصف_ڪريو CHAR_MAX UCHAR_MAX
#جيڪڏهن_پورو

#وصف_ڪريو MB_LEN_MAX 5
#وصف_ڪريو SHRT_MIN (-32768)
#وصف_ڪريو SHRT_MAX 32767
#وصف_ڪريو USHRT_MAX 0xffff
#وصف_ڪريو INT_MIN (-2147483647 - 1)
#وصف_ڪريو وڌ_کان_وڌ_عدد 2147483647
#وصف_ڪريو UINT_MAX 0xffffffff
#وصف_ڪريو LONG_MIN (-2147483647L - 1)
#وصف_ڪريو LONG_MAX 2147483647L
#وصف_ڪريو ULONG_MAX 0xffffffffUL
#وصف_ڪريو LLONG_MAX 9223372036854775807ll
#وصف_ڪريو LLONG_MIN (-9223372036854775807ll - 1)
#وصف_ڪريو ULLONG_MAX 0xffffffffffffffffull

#إذا INTEGRAL_MAX_بٽ >= 8
#وصف_ڪريو _I8_MIN (-127 - 1)
#وصف_ڪريو _I8_MAX 127i8
#وصف_ڪريو _UI8_MAX 0xffu
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 16
#وصف_ڪريو _I16_MIN (-32767 - 1)
#وصف_ڪريو _I16_MAX 32767i16
#وصف_ڪريو _UI16_MAX 0xffffu
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 32
#وصف_ڪريو _I32_MIN (-2147483647 - 1)
#وصف_ڪريو _I32_MAX 2147483647
#وصف_ڪريو _UI32_MAX 0xffffffffu
#جيڪڏهن_پورو

#إذا defined(__GNUC__)
#وصف_رد LONG_LONG_MAX
#وصف_ڪريو LONG_LONG_MAX 9223372036854775807ll
#وصف_رد LONG_LONG_MIN
#وصف_ڪريو LONG_LONG_MIN (-LONG_LONG_MAX-1)
#وصف_رد ULONG_LONG_MAX
#وصف_ڪريو ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 64
#وصف_ڪريو _I64_MIN (-9223372036854775807ll - 1)
#وصف_ڪريو _I64_MAX 9223372036854775807ll
#وصف_ڪريو _UI64_MAX 0xffffffffffffffffull
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل SIZE_MAX
#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو SIZE_MAX _UI64_MAX
#وإلا
#وصف_ڪريو SIZE_MAX UINT_MAX
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو _POSIX_ARG_MAX 4096
#وصف_ڪريو _POSIX_CHILD_MAX 6
#وصف_ڪريو _POSIX_LINK_MAX 8
#وصف_ڪريو _POSIX_MAX_CANON 255
#وصف_ڪريو _POSIX_MAX_INPUT 255
#وصف_ڪريو _POSIX_NAME_MAX 14
#وصف_ڪريو _POSIX_NGROUPS_MAX 0
#وصف_ڪريو _POSIX_OPEN_MAX 16
#وصف_ڪريو _POSIX_PATH_MAX 255
#وصف_ڪريو _POSIX_PIPE_BUF 512
#وصف_ڪريو _POSIX_SSIZE_MAX 32767
#وصف_ڪريو _POSIX_STREAM_MAX 8
#وصف_ڪريو _POSIX_TZNAME_MAX 3
#وصف_ڪريو ARG_MAX 14500
#وصف_ڪريو LINK_MAX 1024
#وصف_ڪريو MAX_CANON _POSIX_MAX_CANON
#وصف_ڪريو MAX_INPUT _POSIX_MAX_INPUT
#وصف_ڪريو NAME_MAX 255
#وصف_ڪريو NGROUPS_MAX 16
#وصف_ڪريو OPEN_MAX 32
#وصف_ڪريو PATH_MAX 512
#وصف_ڪريو PIPE_BUF _POSIX_PIPE_BUF
#وصف_ڪريو SSIZE_MAX _POSIX_SSIZE_MAX
#وصف_ڪريو وهڪرو_MAX 20
#وصف_ڪريو TZNAME_MAX 10
#جيڪڏهن_پورو
#جيڪڏهن_پورو
