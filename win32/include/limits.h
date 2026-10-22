/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_LIMITS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PATH_MAX	(259)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_BIT 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCHAR_MIN (-128)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCHAR_MAX 127
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UCHAR_MAX 0xff

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __CHAR_UNSIGNED__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_MIN SCHAR_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_MAX SCHAR_MAX
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_MIN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHAR_MAX UCHAR_MAX
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_LEN_MAX 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHRT_MIN (-32768)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHRT_MAX 32767
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USHRT_MAX 0xffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT_MIN (-2147483647 - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_ਅੰਕ 2147483647
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UINT_MAX 0xffffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_MIN (-2147483647L - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_MAX 2147483647L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULONG_MAX 0xffffffffUL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLONG_MAX 9223372036854775807ll
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLONG_MIN (-9223372036854775807ll - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULLONG_MAX 0xffffffffffffffffull

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I8_MIN (-127 - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I8_MAX 127i8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UI8_MAX 0xffu
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I16_MIN (-32767 - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I16_MAX 32767i16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UI16_MAX 0xffffu
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I32_MIN (-2147483647 - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I32_MAX 2147483647
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UI32_MAX 0xffffffffu
#ਜੇ_ਅੰਤ

#ਜੇ defined(__GNUC__)
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ LONG_LONG_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_LONG_MAX 9223372036854775807ll
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ LONG_LONG_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_LONG_MIN (-LONG_LONG_MAX-1)
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ULONG_LONG_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I64_MIN (-9223372036854775807ll - 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _I64_MAX 9223372036854775807ll
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _UI64_MAX 0xffffffffffffffffull
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SIZE_MAX
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZE_MAX _UI64_MAX
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZE_MAX UINT_MAX
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_ARG_MAX 4096
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_CHILD_MAX 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_LINK_MAX 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_MAX_CANON 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_MAX_INPUT 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_NAME_MAX 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_NGROUPS_MAX 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_OPEN_MAX 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_PATH_MAX 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_PIPE_BUF 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_SSIZE_MAX 32767
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_STREAM_MAX 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _POSIX_TZNAME_MAX 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARG_MAX 14500
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LINK_MAX 1024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_CANON _POSIX_MAX_CANON
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_INPUT _POSIX_MAX_INPUT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NAME_MAX 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NGROUPS_MAX 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPEN_MAX 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PATH_MAX 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_BUF _POSIX_PIPE_BUF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSIZE_MAX _POSIX_SSIZE_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧਾਰਾ_MAX 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TZNAME_MAX 10
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
