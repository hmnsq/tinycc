/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_SHARE
#تعریف_کرو _INC_SHARE

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#تعریف_کرو _SH_COMPAT 0x00
#تعریف_کرو _SH_DENYRW 0x10
#تعریف_کرو _SH_DENYWR 0x20
#تعریف_کرو _SH_DENYRD 0x30
#تعریف_کرو _SH_DENYNO 0x40
#تعریف_کرو _SH_SECURE 0x80

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#تعریف_کرو SH_COMPAT _SH_COMPAT
#تعریف_کرو SH_DENYRW _SH_DENYRW
#تعریف_کرو SH_DENYWR _SH_DENYWR
#تعریف_کرو SH_DENYRD _SH_DENYRD
#تعریف_کرو SH_DENYNO _SH_DENYNO
#اگر_ختم

#اگر_ختم
