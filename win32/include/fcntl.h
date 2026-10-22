/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ضمن <_mingw.h>

#ضمن <io.h>

#جيڪڏهن_وصف_نه_ٿيل _INC_FCNTL
#وصف_ڪريو _INC_FCNTL

#وصف_ڪريو _O_RDONLY 0x0000
#وصف_ڪريو _O_WRONLY 0x0001
#وصف_ڪريو _O_RDWR 0x0002
#وصف_ڪريو _O_APPEND 0x0008
#وصف_ڪريو _O_CREAT 0x0100
#وصف_ڪريو _O_TRUNC 0x0200
#وصف_ڪريو _O_EXCL 0x0400
#وصف_ڪريو O_متن 0x4000
#وصف_ڪريو O_ٻٽو 0x8000
#وصف_ڪريو _O_WTEXT 0x10000
#وصف_ڪريو O_U16_متن 0x20000
#وصف_ڪريو O_U8_متن 0x40000
#وصف_ڪريو _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#وصف_ڪريو _O_RAW O_ٻٽو
#وصف_ڪريو _O_NOINHERIT 0x0080
#وصف_ڪريو _O_TEMPORARY 0x0040
#وصف_ڪريو _O_SHORT_LIVED 0x1000

#وصف_ڪريو _O_SEQUENTIAL 0x0020
#وصف_ڪريو _O_RANDOM 0x0010

#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
#وصف_ڪريو O_RDONLY _O_RDONLY
#وصف_ڪريو O_WRONLY _O_WRONLY
#وصف_ڪريو O_RDWR _O_RDWR
#وصف_ڪريو O_APPEND _O_APPEND
#وصف_ڪريو O_CREAT _O_CREAT
#وصف_ڪريو O_TRUNC _O_TRUNC
#وصف_ڪريو O_EXCL _O_EXCL
#وصف_ڪريو O_متن_2 O_متن
#وصف_ڪريو O_ٻٽو_2 O_ٻٽو
#وصف_ڪريو O_RAW O_ٻٽو
#وصف_ڪريو O_TEMPORARY _O_TEMPORARY
#وصف_ڪريو O_NOINHERIT _O_NOINHERIT
#وصف_ڪريو O_SEQUENTIAL _O_SEQUENTIAL
#وصف_ڪريو O_RANDOM _O_RANDOM
#وصف_ڪريو O_ACCMODE _O_ACCMODE
#جيڪڏهن_پورو
#جيڪڏهن_پورو
