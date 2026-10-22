/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_LOCKING
#تعریف_کن _INC_LOCKING

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

/* All the headers include this file. */
#ضمن <_mingw.h>

#تعریف_کن _LK_UNLCK 0
#تعریف_کن LK_قفل 1
#تعریف_کن _LK_NBLCK 2
#تعریف_کن _LK_RLCK 3
#تعریف_کن _LK_NBRLCK 4

#اگر_تعریف_نشده	NO_OLDNAMES
#تعریف_کن LK_UNLCK _LK_UNLCK
#تعریف_کن LK_قفل_2 LK_قفل
#تعریف_کن LK_NBLCK _LK_NBLCK
#تعریف_کن LK_RLCK _LK_RLCK
#تعریف_کن LK_NBRLCK _LK_NBRLCK
#پایان_اگر

#پایان_اگر
