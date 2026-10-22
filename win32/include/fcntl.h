/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#ضمن <io.h>

#که_نه_تعریف_شوی _INC_FCNTL
#تعریف_کړه _INC_FCNTL

#تعریف_کړه _O_RDONLY 0x0000
#تعریف_کړه _O_WRONLY 0x0001
#تعریف_کړه _O_RDWR 0x0002
#تعریف_کړه _O_APPEND 0x0008
#تعریف_کړه _O_CREAT 0x0100
#تعریف_کړه _O_TRUNC 0x0200
#تعریف_کړه _O_EXCL 0x0400
#تعریف_کړه O_متن 0x4000
#تعریف_کړه O_دوګونی 0x8000
#تعریف_کړه _O_WTEXT 0x10000
#تعریف_کړه O_U16_متن 0x20000
#تعریف_کړه O_U8_متن 0x40000
#تعریف_کړه _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#تعریف_کړه _O_RAW O_دوګونی
#تعریف_کړه _O_NOINHERIT 0x0080
#تعریف_کړه _O_TEMPORARY 0x0040
#تعریف_کړه _O_SHORT_LIVED 0x1000

#تعریف_کړه _O_SEQUENTIAL 0x0020
#تعریف_کړه _O_RANDOM 0x0010

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کړه O_RDONLY _O_RDONLY
#تعریف_کړه O_WRONLY _O_WRONLY
#تعریف_کړه O_RDWR _O_RDWR
#تعریف_کړه O_APPEND _O_APPEND
#تعریف_کړه O_CREAT _O_CREAT
#تعریف_کړه O_TRUNC _O_TRUNC
#تعریف_کړه O_EXCL _O_EXCL
#تعریف_کړه O_متن_2 O_متن
#تعریف_کړه O_دوګونی_2 O_دوګونی
#تعریف_کړه O_RAW O_دوګونی
#تعریف_کړه O_TEMPORARY _O_TEMPORARY
#تعریف_کړه O_NOINHERIT _O_NOINHERIT
#تعریف_کړه O_SEQUENTIAL _O_SEQUENTIAL
#تعریف_کړه O_RANDOM _O_RANDOM
#تعریف_کړه O_ACCMODE _O_ACCMODE
#د_که_پای
#د_که_پای
