/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINDOWS_
#تعریف_کن _WINDOWS_

#اگر_تعریف_نشده WIN32_LEAN_AND_میانگین
#تعریف_کن WIN32_LEAN_AND_میانگین 1
#پایان_اگر

#اگر_تعریف_نشده WINVER
#تعریف_کن WINVER 0x0502
#پایان_اگر

#ضمن <_mingw.h>

#اگر_تعریف_نشده _INC_WINDOWS
#تعریف_کن _INC_WINDOWS

#إذا defined(RC_INVOKED) && !defined(NOWINRES)

#ضمن <winresrc.h>
#وإلا

#اگر_تعریف_شده RC_INVOKED
#تعریف_کن NOATOM
#تعریف_کن NOGDI
#تعریف_کن NOGDICAPMASKS
#تعریف_کن NOMETAFILE
#تعریف_کن NOMINMAX
#تعریف_کن NOMSG
#تعریف_کن NOOPENFILE
#تعریف_کن NORASTEROPS
#تعریف_کن NOSCROLL
#تعریف_کن NOSOUND
#تعریف_کن NOSYSMETRICS
#تعریف_کن NOTEXTMETRIC
#تعریف_کن NOWH
#تعریف_کن NOCOMM
#تعریف_کن NOKANJI
#تعریف_کن NOCRYPT
#تعریف_کن NOMCX
#پایان_اگر

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کن I_X86_
#پایان_اگر

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کن _AMD64_
#پایان_اگر

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#تعریف_کن _IA64_
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده RC_INVOKED
#ضمن <excpt.h>
#ضمن <stdarg.h>
#پایان_اگر

#ضمن <windef.h>
#ضمن <winbase.h>
#ضمن <wingdi.h>
#ضمن <winuser.h>
#ضمن <winnls.h>
#ضمن <wincon.h>
#ضمن <winver.h>
#ضمن <winreg.h>
//gr #include <winnetwk.h>

#اگر_تعریف_نشده WIN32_LEAN_AND_میانگین
#ضمن <cderr.h>
#ضمن <dde.h>
#ضمن <ddeml.h>
#ضمن <dlgs.h>
#ضمن <lzexpand.h>
#ضمن <mmsystem.h>
#ضمن <nb30.h>
#ضمن <rpc.h>
#ضمن <shellapi.h>
#ضمن <winperf.h>
#ضمن <winsock.h>
#اگر_تعریف_نشده NOCRYPT
#ضمن <wincrypt.h>
#ضمن <winefs.h>
#ضمن <winscard.h>
#پایان_اگر

#اگر_تعریف_نشده NOUSER
#اگر_تعریف_نشده NOGDI
#ضمن <winspool.h>
#اگر_تعریف_شده INC_OLE1
#ضمن <ole.h>
#وإلا
#ضمن <ole2.h>
#پایان_اگر
#ضمن <commdlg.h>
#پایان_اگر
#پایان_اگر
#پایان_اگر

//gr #include <stralign.h>

#اگر_تعریف_شده INC_OLE2
#ضمن <ole2.h>
#پایان_اگر

#اگر_تعریف_نشده NOSERVICE
#ضمن <winsvc.h>
#پایان_اگر

#اگر_تعریف_نشده NOMCX
#ضمن <mcx.h>
#پایان_اگر

#اگر_تعریف_نشده NOIME
#ضمن <imm.h>
#پایان_اگر

#پایان_اگر
#پایان_اگر
#پایان_اگر
