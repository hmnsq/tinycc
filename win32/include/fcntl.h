/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#समावेश <_mingw.h>

#समावेश <io.h>

#अगर_अघोषित _INC_FCNTL
#घोषणा _INC_FCNTL

#घोषणा _O_RDONLY 0x0000
#घोषणा _O_WRONLY 0x0001
#घोषणा _O_RDWR 0x0002
#घोषणा _O_APPEND 0x0008
#घोषणा _O_CREAT 0x0100
#घोषणा _O_TRUNC 0x0200
#घोषणा _O_EXCL 0x0400
#घोषणा _O_TEXT 0x4000
#घोषणा O_द्विआधारी 0x8000
#घोषणा _O_WTEXT 0x10000
#घोषणा _O_U16TEXT 0x20000
#घोषणा _O_U8TEXT 0x40000
#घोषणा _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#घोषणा _O_RAW O_द्विआधारी
#घोषणा _O_NOINHERIT 0x0080
#घोषणा _O_TEMPORARY 0x0040
#घोषणा _O_SHORT_LIVED 0x1000

#घोषणा _O_SEQUENTIAL 0x0020
#घोषणा _O_RANDOM 0x0010

#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
#घोषणा O_RDONLY _O_RDONLY
#घोषणा O_WRONLY _O_WRONLY
#घोषणा O_RDWR _O_RDWR
#घोषणा O_APPEND _O_APPEND
#घोषणा O_CREAT _O_CREAT
#घोषणा O_TRUNC _O_TRUNC
#घोषणा O_EXCL _O_EXCL
#घोषणा O_TEXT _O_TEXT
#घोषणा O_द्विआधारी_2 O_द्विआधारी
#घोषणा O_RAW O_द्विआधारी
#घोषणा O_TEMPORARY _O_TEMPORARY
#घोषणा O_NOINHERIT _O_NOINHERIT
#घोषणा O_SEQUENTIAL _O_SEQUENTIAL
#घोषणा O_RANDOM _O_RANDOM
#घोषणा O_ACCMODE _O_ACCMODE
#पूर्ण_अगर
#पूर्ण_अगर
