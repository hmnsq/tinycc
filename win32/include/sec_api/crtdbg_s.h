/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_غیر_تعریف_شدہ _INC_CRTDBG_S
#تعریف_کرو _INC_CRTDBG_S

#شامل <crtdbg.h>

#اگر defined(MINGW_HAS_SECURE_API)

#تعریف_کرو _dupenv_s_dbg(ps1,سائز,s2,t,f,l) _dupenv_s(ps1,سائز,s2)
#تعریف_کرو _wdupenv_s_dbg(ps1,سائز,s2,t,f,l) _wdupenv_s(ps1,سائز,s2)

#اگر_ختم

#اگر_ختم
