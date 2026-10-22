/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_SHARE
#تعریف_کن _INC_SHARE

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#تعریف_کن _SH_COMPAT 0x00
#تعریف_کن _SH_DENYRW 0x10
#تعریف_کن _SH_DENYWR 0x20
#تعریف_کن _SH_DENYRD 0x30
#تعریف_کن _SH_DENYNO 0x40
#تعریف_کن _SH_SECURE 0x80

#اگر_تعریف_نشده	NO_OLDNAMES
#تعریف_کن SH_COMPAT _SH_COMPAT
#تعریف_کن SH_DENYRW _SH_DENYRW
#تعریف_کن SH_DENYWR _SH_DENYWR
#تعریف_کن SH_DENYRD _SH_DENYRD
#تعریف_کن SH_DENYNO _SH_DENYNO
#پایان_اگر

#پایان_اگر
