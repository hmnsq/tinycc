/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#అన్తర్భావ <_mingw.h>

#అన్తర్భావ <io.h>

#నిర్వచితం_కాకపోతే _INC_FCNTL
#నిర్వచించు _INC_FCNTL

#నిర్వచించు _O_RDONLY 0x0000
#నిర్వచించు _O_WRONLY 0x0001
#నిర్వచించు _O_RDWR 0x0002
#నిర్వచించు _O_APPEND 0x0008
#నిర్వచించు _O_CREAT 0x0100
#నిర్వచించు _O_TRUNC 0x0200
#నిర్వచించు _O_EXCL 0x0400
#నిర్వచించు O_పాఠ్యం 0x4000
#నిర్వచించు O_ద్విమాన 0x8000
#నిర్వచించు _O_WTEXT 0x10000
#నిర్వచించు O_U16_పాఠ్యం 0x20000
#నిర్వచించు O_U8_పాఠ్యం 0x40000
#నిర్వచించు _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#నిర్వచించు _O_RAW O_ద్విమాన
#నిర్వచించు _O_NOINHERIT 0x0080
#నిర్వచించు _O_TEMPORARY 0x0040
#నిర్వచించు _O_SHORT_LIVED 0x1000

#నిర్వచించు _O_SEQUENTIAL 0x0020
#నిర్వచించు _O_RANDOM 0x0010

#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
#నిర్వచించు O_RDONLY _O_RDONLY
#నిర్వచించు O_WRONLY _O_WRONLY
#నిర్వచించు O_RDWR _O_RDWR
#నిర్వచించు O_APPEND _O_APPEND
#నిర్వచించు O_CREAT _O_CREAT
#నిర్వచించు O_TRUNC _O_TRUNC
#నిర్వచించు O_EXCL _O_EXCL
#నిర్వచించు O_పాఠ్యం_2 O_పాఠ్యం
#నిర్వచించు O_ద్విమాన_2 O_ద్విమాన
#నిర్వచించు O_RAW O_ద్విమాన
#నిర్వచించు O_TEMPORARY _O_TEMPORARY
#నిర్వచించు O_NOINHERIT _O_NOINHERIT
#నిర్వచించు O_SEQUENTIAL _O_SEQUENTIAL
#నిర్వచించు O_RANDOM _O_RANDOM
#నిర్వచించు O_ACCMODE _O_ACCMODE
#అయితే_ముగింపు
#అయితే_ముగింపు
