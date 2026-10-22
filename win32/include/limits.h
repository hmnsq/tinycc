/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_LIMITS
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#ವ್ಯಾಖ್ಯಾನಿಸು PATH_MAX	(259)

#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_BIT 8
#ವ್ಯಾಖ್ಯಾನಿಸು SCHAR_MIN (-128)
#ವ್ಯಾಖ್ಯಾನಿಸು SCHAR_MAX 127
#ವ್ಯಾಖ್ಯಾನಿಸು UCHAR_MAX 0xff

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __CHAR_UNSIGNED__
#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_MIN SCHAR_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_MAX SCHAR_MAX
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_MIN 0
#ವ್ಯಾಖ್ಯಾನಿಸು CHAR_MAX UCHAR_MAX
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು MB_LEN_MAX 5
#ವ್ಯಾಖ್ಯಾನಿಸು SHRT_MIN (-32768)
#ವ್ಯಾಖ್ಯಾನಿಸು SHRT_MAX 32767
#ವ್ಯಾಖ್ಯಾನಿಸು USHRT_MAX 0xffff
#ವ್ಯಾಖ್ಯಾನಿಸು INT_MIN (-2147483647 - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_ಪೂರ್ಣಾಂಕ 2147483647
#ವ್ಯಾಖ್ಯಾನಿಸು UINT_MAX 0xffffffff
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_MIN (-2147483647L - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_MAX 2147483647L
#ವ್ಯಾಖ್ಯಾನಿಸು ULONG_MAX 0xffffffffUL
#ವ್ಯಾಖ್ಯಾನಿಸು LLONG_MAX 9223372036854775807ll
#ವ್ಯಾಖ್ಯಾನಿಸು LLONG_MIN (-9223372036854775807ll - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು ULLONG_MAX 0xffffffffffffffffull

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 8
#ವ್ಯಾಖ್ಯಾನಿಸು _I8_MIN (-127 - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು _I8_MAX 127i8
#ವ್ಯಾಖ್ಯಾನಿಸು _UI8_MAX 0xffu
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 16
#ವ್ಯಾಖ್ಯಾನಿಸು _I16_MIN (-32767 - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು _I16_MAX 32767i16
#ವ್ಯಾಖ್ಯಾನಿಸು _UI16_MAX 0xffffu
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 32
#ವ್ಯಾಖ್ಯಾನಿಸು _I32_MIN (-2147483647 - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು _I32_MAX 2147483647
#ವ್ಯಾಖ್ಯಾನಿಸು _UI32_MAX 0xffffffffu
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(__GNUC__)
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು LONG_LONG_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_LONG_MAX 9223372036854775807ll
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು LONG_LONG_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_LONG_MIN (-LONG_LONG_MAX-1)
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ULONG_LONG_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
#ವ್ಯಾಖ್ಯಾನಿಸು _I64_MIN (-9223372036854775807ll - 1)
#ವ್ಯಾಖ್ಯಾನಿಸು _I64_MAX 9223372036854775807ll
#ವ್ಯಾಖ್ಯಾನಿಸು _UI64_MAX 0xffffffffffffffffull
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SIZE_MAX
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು SIZE_MAX _UI64_MAX
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SIZE_MAX UINT_MAX
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_ARG_MAX 4096
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_CHILD_MAX 6
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_LINK_MAX 8
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_MAX_CANON 255
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_MAX_INPUT 255
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_NAME_MAX 14
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_NGROUPS_MAX 0
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_OPEN_MAX 16
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_PATH_MAX 255
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_PIPE_BUF 512
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_SSIZE_MAX 32767
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_STREAM_MAX 8
#ವ್ಯಾಖ್ಯಾನಿಸು _POSIX_TZNAME_MAX 3
#ವ್ಯಾಖ್ಯಾನಿಸು ARG_MAX 14500
#ವ್ಯಾಖ್ಯಾನಿಸು LINK_MAX 1024
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_CANON _POSIX_MAX_CANON
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_INPUT _POSIX_MAX_INPUT
#ವ್ಯಾಖ್ಯಾನಿಸು NAME_MAX 255
#ವ್ಯಾಖ್ಯಾನಿಸು NGROUPS_MAX 16
#ವ್ಯಾಖ್ಯಾನಿಸು OPEN_MAX 32
#ವ್ಯಾಖ್ಯಾನಿಸು PATH_MAX 512
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_BUF _POSIX_PIPE_BUF
#ವ್ಯಾಖ್ಯಾನಿಸು SSIZE_MAX _POSIX_SSIZE_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು ಹರಿವು_MAX 20
#ವ್ಯಾಖ್ಯಾನಿಸು TZNAME_MAX 10
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
