/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_تعریف_نشده _INC_CRTDBG_S
#تعریف_کن _INC_CRTDBG_S

#ضمن <crtdbg.h>

#إذا defined(MINGW_HAS_SECURE_API)

#تعریف_کن _dupenv_s_dbg(ps1,اندازه,s2,t,f,l) _dupenv_s(ps1,اندازه,s2)
#تعریف_کن _wdupenv_s_dbg(ps1,اندازه,s2,t,f,l) _wdupenv_s(ps1,اندازه,s2)

#پایان_اگر

#پایان_اگر
