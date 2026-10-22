/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#ضمن <io.h>

#اگر_تعریف_نشده _INC_FCNTL
#تعریف_کن _INC_FCNTL

#تعریف_کن _O_RDONLY 0x0000
#تعریف_کن _O_WRONLY 0x0001
#تعریف_کن _O_RDWR 0x0002
#تعریف_کن _O_APPEND 0x0008
#تعریف_کن _O_CREAT 0x0100
#تعریف_کن _O_TRUNC 0x0200
#تعریف_کن _O_EXCL 0x0400
#تعریف_کن O_متن 0x4000
#تعریف_کن O_دودویی 0x8000
#تعریف_کن _O_WTEXT 0x10000
#تعریف_کن O_U16_متن 0x20000
#تعریف_کن O_U8_متن 0x40000
#تعریف_کن _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#تعریف_کن _O_RAW O_دودویی
#تعریف_کن _O_NOINHERIT 0x0080
#تعریف_کن _O_TEMPORARY 0x0040
#تعریف_کن _O_SHORT_LIVED 0x1000

#تعریف_کن _O_SEQUENTIAL 0x0020
#تعریف_کن _O_RANDOM 0x0010

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کن O_RDONLY _O_RDONLY
#تعریف_کن O_WRONLY _O_WRONLY
#تعریف_کن O_RDWR _O_RDWR
#تعریف_کن O_APPEND _O_APPEND
#تعریف_کن O_CREAT _O_CREAT
#تعریف_کن O_TRUNC _O_TRUNC
#تعریف_کن O_EXCL _O_EXCL
#تعریف_کن O_متن_2 O_متن
#تعریف_کن O_دودویی_2 O_دودویی
#تعریف_کن O_RAW O_دودویی
#تعریف_کن O_TEMPORARY _O_TEMPORARY
#تعریف_کن O_NOINHERIT _O_NOINHERIT
#تعریف_کن O_SEQUENTIAL _O_SEQUENTIAL
#تعریف_کن O_RANDOM _O_RANDOM
#تعریف_کن O_ACCMODE _O_ACCMODE
#پایان_اگر
#پایان_اگر
