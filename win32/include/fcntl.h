/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अन्तर्भाव <_mingw.h>

#अन्तर्भाव <io.h>

#यदि_अपरिभाषितम् _INC_FCNTL
#परिभाषय _INC_FCNTL

#परिभाषय _O_RDONLY 0x0000
#परिभाषय _O_WRONLY 0x0001
#परिभाषय _O_RDWR 0x0002
#परिभाषय _O_APPEND 0x0008
#परिभाषय _O_CREAT 0x0100
#परिभाषय _O_TRUNC 0x0200
#परिभाषय _O_EXCL 0x0400
#परिभाषय _O_TEXT 0x4000
#परिभाषय O_द्विमान 0x8000
#परिभाषय _O_WTEXT 0x10000
#परिभाषय _O_U16TEXT 0x20000
#परिभाषय _O_U8TEXT 0x40000
#परिभाषय _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#परिभाषय _O_RAW O_द्विमान
#परिभाषय _O_NOINHERIT 0x0080
#परिभाषय _O_TEMPORARY 0x0040
#परिभाषय _O_SHORT_LIVED 0x1000

#परिभाषय _O_SEQUENTIAL 0x0020
#परिभाषय _O_RANDOM 0x0010

#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
#परिभाषय O_RDONLY _O_RDONLY
#परिभाषय O_WRONLY _O_WRONLY
#परिभाषय O_RDWR _O_RDWR
#परिभाषय O_APPEND _O_APPEND
#परिभाषय O_CREAT _O_CREAT
#परिभाषय O_TRUNC _O_TRUNC
#परिभाषय O_EXCL _O_EXCL
#परिभाषय O_TEXT _O_TEXT
#परिभाषय O_द्विमान_2 O_द्विमान
#परिभाषय O_RAW O_द्विमान
#परिभाषय O_TEMPORARY _O_TEMPORARY
#परिभाषय O_NOINHERIT _O_NOINHERIT
#परिभाषय O_SEQUENTIAL _O_SEQUENTIAL
#परिभाषय O_RANDOM _O_RANDOM
#परिभाषय O_ACCMODE _O_ACCMODE
#यदि_अन्तः
#यदि_अन्तः
