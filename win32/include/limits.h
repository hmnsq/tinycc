/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#समावेश <_mingw.h>

#अगर_अघोषित _INC_LIMITS
#घोषणा _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required for the NUL. TODO: Test?
*/
#घोषणा PATH_MAX	(259)

#घोषणा अक्षर_बिट 8
#घोषणा च_अक्षर_न्यून (-128)
#घोषणा च_अक्षर_उच्च 127
#घोषणा अच_अक्षर_उच्च 0xff

#अगर_अघोषित __CHAR_UNSIGNED__
#घोषणा अक्षर_न्यून च_अक्षर_न्यून
#घोषणा अक्षर_उच्च च_अक्षर_उच्च
#अन्यथा
#घोषणा अक्षर_न्यून 0
#घोषणा अक्षर_उच्च अच_अक्षर_उच्च
#पूर्ण_अगर

#घोषणा MB_LEN_MAX 5
#घोषणा लघु_न्यून (-32768)
#घोषणा लघु_उच्च 32767
#घोषणा अच_लघु_उच्च 0xffff
#घोषणा पूर्णांक_न्यून (-2147483647 - 1)
#घोषणा पूर्णांक_उच्च 2147483647
#घोषणा अच_पूर्णांक_उच्च 0xffffffff
#घोषणा दीर्घ_न्यून (-2147483647L - 1)
#घोषणा दीर्घ_उच्च 2147483647L
#घोषणा अच_दीर्घ_उच्च 0xffffffffUL
#घोषणा LLONG_MAX 9223372036854775807ll
#घोषणा LLONG_MIN (-9223372036854775807ll - 1)
#घोषणा ULLONG_MAX 0xffffffffffffffffull

#अगर _INTEGRAL_MAX_BITS >= 8
#घोषणा _I8_MIN (-127 - 1)
#घोषणा _I8_MAX 127i8
#घोषणा _UI8_MAX 0xffu
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 16
#घोषणा _I16_MIN (-32767 - 1)
#घोषणा _I16_MAX 32767i16
#घोषणा _UI16_MAX 0xffffu
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 32
#घोषणा _I32_MIN (-2147483647 - 1)
#घोषणा _I32_MAX 2147483647
#घोषणा _UI32_MAX 0xffffffffu
#पूर्ण_अगर

#अगर defined(__GNUC__)
#अघोषित LONG_LONG_MAX
#घोषणा LONG_LONG_MAX 9223372036854775807ll
#अघोषित LONG_LONG_MIN
#घोषणा LONG_LONG_MIN (-LONG_LONG_MAX-1)
#अघोषित ULONG_LONG_MAX
#घोषणा ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 64
#घोषणा _I64_MIN (-9223372036854775807ll - 1)
#घोषणा _I64_MAX 9223372036854775807ll
#घोषणा _UI64_MAX 0xffffffffffffffffull
#पूर्ण_अगर

#अगर_अघोषित SIZE_MAX
#अगर_घोषित _WIN64
#घोषणा SIZE_MAX _UI64_MAX
#अन्यथा
#घोषणा SIZE_MAX अच_पूर्णांक_उच्च
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित _POSIX_
#घोषणा _POSIX_ARG_MAX 4096
#घोषणा _POSIX_CHILD_MAX 6
#घोषणा _POSIX_LINK_MAX 8
#घोषणा _POSIX_MAX_CANON 255
#घोषणा _POSIX_MAX_INPUT 255
#घोषणा _POSIX_NAME_MAX 14
#घोषणा _POSIX_NGROUPS_MAX 0
#घोषणा _POSIX_OPEN_MAX 16
#घोषणा _POSIX_PATH_MAX 255
#घोषणा _POSIX_PIPE_BUF 512
#घोषणा _POSIX_SSIZE_MAX 32767
#घोषणा _POSIX_STREAM_MAX 8
#घोषणा _POSIX_TZNAME_MAX 3
#घोषणा ARG_MAX 14500
#घोषणा LINK_MAX 1024
#घोषणा MAX_CANON _POSIX_MAX_CANON
#घोषणा MAX_INPUT _POSIX_MAX_INPUT
#घोषणा NAME_MAX 255
#घोषणा NGROUPS_MAX 16
#घोषणा OPEN_MAX 32
#घोषणा PATH_MAX 512
#घोषणा PIPE_BUF _POSIX_PIPE_BUF
#घोषणा SSIZE_MAX _POSIX_SSIZE_MAX
#घोषणा STREAM_MAX 20
#घोषणा TZNAME_MAX 10
#पूर्ण_अगर
#पूर्ण_अगर
