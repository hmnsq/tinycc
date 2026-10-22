/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_LOCKING
#تعریف_کرو _INC_LOCKING

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

/* All the headers include this file. */
#شامل <_mingw.h>

#تعریف_کرو _LK_UNLCK 0
#تعریف_کرو LK_تالا 1
#تعریف_کرو _LK_NBLCK 2
#تعریف_کرو _LK_RLCK 3
#تعریف_کرو _LK_NBRLCK 4

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#تعریف_کرو LK_UNLCK _LK_UNLCK
#تعریف_کرو LK_تالا_2 LK_تالا
#تعریف_کرو LK_NBLCK _LK_NBLCK
#تعریف_کرو LK_RLCK _LK_RLCK
#تعریف_کرو LK_NBRLCK _LK_NBRLCK
#اگر_ختم

#اگر_ختم
