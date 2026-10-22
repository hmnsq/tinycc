/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#شامل <_mingw.h>

#شامل <io.h>

#اگر_غیر_تعریف_شدہ _INC_FCNTL
#تعریف_کرو _INC_FCNTL

#تعریف_کرو _O_RDONLY 0x0000
#تعریف_کرو _O_WRONLY 0x0001
#تعریف_کرو _O_RDWR 0x0002
#تعریف_کرو _O_APPEND 0x0008
#تعریف_کرو _O_CREAT 0x0100
#تعریف_کرو _O_TRUNC 0x0200
#تعریف_کرو _O_EXCL 0x0400
#تعریف_کرو O_متن 0x4000
#تعریف_کرو O_ثنائی 0x8000
#تعریف_کرو _O_WTEXT 0x10000
#تعریف_کرو O_U16_متن 0x20000
#تعریف_کرو O_U8_متن 0x40000
#تعریف_کرو _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#تعریف_کرو _O_RAW O_ثنائی
#تعریف_کرو _O_NOINHERIT 0x0080
#تعریف_کرو _O_TEMPORARY 0x0040
#تعریف_کرو _O_SHORT_LIVED 0x1000

#تعریف_کرو _O_SEQUENTIAL 0x0020
#تعریف_کرو _O_RANDOM 0x0010

#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
#تعریف_کرو O_RDONLY _O_RDONLY
#تعریف_کرو O_WRONLY _O_WRONLY
#تعریف_کرو O_RDWR _O_RDWR
#تعریف_کرو O_APPEND _O_APPEND
#تعریف_کرو O_CREAT _O_CREAT
#تعریف_کرو O_TRUNC _O_TRUNC
#تعریف_کرو O_EXCL _O_EXCL
#تعریف_کرو O_متن_2 O_متن
#تعریف_کرو O_ثنائی_2 O_ثنائی
#تعریف_کرو O_RAW O_ثنائی
#تعریف_کرو O_TEMPORARY _O_TEMPORARY
#تعریف_کرو O_NOINHERIT _O_NOINHERIT
#تعریف_کرو O_SEQUENTIAL _O_SEQUENTIAL
#تعریف_کرو O_RANDOM _O_RANDOM
#تعریف_کرو O_ACCMODE _O_ACCMODE
#اگر_ختم
#اگر_ختم
