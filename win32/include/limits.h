/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अन्तर्भाव <_mingw.h>

#यदि_अपरिभाषितम् _INC_LIMITS
#परिभाषय _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#परिभाषय PATH_MAX	(259)

#परिभाषय CHAR_BIT 8
#परिभाषय SCHAR_MIN (-128)
#परिभाषय SCHAR_MAX 127
#परिभाषय UCHAR_MAX 0xff

#यदि_अपरिभाषितम् __CHAR_UNSIGNED__
#परिभाषय CHAR_MIN SCHAR_MIN
#परिभाषय CHAR_MAX SCHAR_MAX
#अन्यथा
#परिभाषय CHAR_MIN 0
#परिभाषय CHAR_MAX UCHAR_MAX
#यदि_अन्तः

#परिभाषय MB_LEN_MAX 5
#परिभाषय SHRT_MIN (-32768)
#परिभाषय SHRT_MAX 32767
#परिभाषय USHRT_MAX 0xffff
#परिभाषय INT_MIN (-2147483647 - 1)
#परिभाषय अधिकतम_पूर्णाङ्कः 2147483647
#परिभाषय UINT_MAX 0xffffffff
#परिभाषय LONG_MIN (-2147483647L - 1)
#परिभाषय LONG_MAX 2147483647L
#परिभाषय ULONG_MAX 0xffffffffUL
#परिभाषय LLONG_MAX 9223372036854775807ll
#परिभाषय LLONG_MIN (-9223372036854775807ll - 1)
#परिभाषय ULLONG_MAX 0xffffffffffffffffull

#यदि INTEGRAL_MAX_द्वयङ्काः >= 8
#परिभाषय _I8_MIN (-127 - 1)
#परिभाषय _I8_MAX 127i8
#परिभाषय _UI8_MAX 0xffu
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 16
#परिभाषय _I16_MIN (-32767 - 1)
#परिभाषय _I16_MAX 32767i16
#परिभाषय _UI16_MAX 0xffffu
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 32
#परिभाषय _I32_MIN (-2147483647 - 1)
#परिभाषय _I32_MAX 2147483647
#परिभाषय _UI32_MAX 0xffffffffu
#यदि_अन्तः

#यदि defined(__GNUC__)
#अपरिभाषय LONG_LONG_MAX
#परिभाषय LONG_LONG_MAX 9223372036854775807ll
#अपरिभाषय LONG_LONG_MIN
#परिभाषय LONG_LONG_MIN (-LONG_LONG_MAX-1)
#अपरिभाषय ULONG_LONG_MAX
#परिभाषय ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
#परिभाषय _I64_MIN (-9223372036854775807ll - 1)
#परिभाषय _I64_MAX 9223372036854775807ll
#परिभाषय _UI64_MAX 0xffffffffffffffffull
#यदि_अन्तः

#यदि_अपरिभाषितम् SIZE_MAX
#यदि_परिभाषितम् _WIN64
#परिभाषय SIZE_MAX _UI64_MAX
#अन्यथा
#परिभाषय SIZE_MAX UINT_MAX
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् _POSIX_
#परिभाषय _POSIX_ARG_MAX 4096
#परिभाषय _POSIX_CHILD_MAX 6
#परिभाषय _POSIX_LINK_MAX 8
#परिभाषय _POSIX_MAX_CANON 255
#परिभाषय _POSIX_MAX_INPUT 255
#परिभाषय _POSIX_NAME_MAX 14
#परिभाषय _POSIX_NGROUPS_MAX 0
#परिभाषय _POSIX_OPEN_MAX 16
#परिभाषय _POSIX_PATH_MAX 255
#परिभाषय _POSIX_PIPE_BUF 512
#परिभाषय _POSIX_SSIZE_MAX 32767
#परिभाषय _POSIX_STREAM_MAX 8
#परिभाषय _POSIX_TZNAME_MAX 3
#परिभाषय ARG_MAX 14500
#परिभाषय LINK_MAX 1024
#परिभाषय MAX_CANON _POSIX_MAX_CANON
#परिभाषय MAX_INPUT _POSIX_MAX_INPUT
#परिभाषय NAME_MAX 255
#परिभाषय NGROUPS_MAX 16
#परिभाषय OPEN_MAX 32
#परिभाषय PATH_MAX 512
#परिभाषय PIPE_BUF _POSIX_PIPE_BUF
#परिभाषय SSIZE_MAX _POSIX_SSIZE_MAX
#परिभाषय प्रवाहः_MAX 20
#परिभाषय TZNAME_MAX 10
#यदि_अन्तः
#यदि_अन्तः
