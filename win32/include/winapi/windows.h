/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WINDOWS_
#تعریف_کرو _WINDOWS_

#جے_بنا_تعریف WIN32_LEAN_AND_اوسط
#تعریف_کرو WIN32_LEAN_AND_اوسط 1
#جے_انت

#جے_بنا_تعریف WINVER
#تعریف_کرو WINVER 0x0502
#جے_انت

#ضمن <_mingw.h>

#جے_بنا_تعریف _INC_WINDOWS
#تعریف_کرو _INC_WINDOWS

#إذا defined(RC_INVOKED) && !defined(NOWINRES)

#ضمن <winresrc.h>
#وإلا

#جے_تعریف_شدہ RC_INVOKED
#تعریف_کرو NOATOM
#تعریف_کرو NOGDI
#تعریف_کرو NOGDICAPMASKS
#تعریف_کرو NOMETAFILE
#تعریف_کرو NOMINMAX
#تعریف_کرو NOMSG
#تعریف_کرو NOOPENFILE
#تعریف_کرو NORASTEROPS
#تعریف_کرو NOSCROLL
#تعریف_کرو NOSOUND
#تعریف_کرو NOSYSMETRICS
#تعریف_کرو NOTEXTMETRIC
#تعریف_کرو NOWH
#تعریف_کرو NOCOMM
#تعریف_کرو NOKANJI
#تعریف_کرو NOCRYPT
#تعریف_کرو NOMCX
#جے_انت

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کرو I_X86_
#جے_انت

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کرو _AMD64_
#جے_انت

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#تعریف_کرو _IA64_
#جے_انت
#جے_انت

#جے_بنا_تعریف RC_INVOKED
#ضمن <excpt.h>
#ضمن <stdarg.h>
#جے_انت

#ضمن <windef.h>
#ضمن <winbase.h>
#ضمن <wingdi.h>
#ضمن <winuser.h>
#ضمن <winnls.h>
#ضمن <wincon.h>
#ضمن <winver.h>
#ضمن <winreg.h>
//gr #include <winnetwk.h>

#جے_بنا_تعریف WIN32_LEAN_AND_اوسط
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
#جے_بنا_تعریف NOCRYPT
#ضمن <wincrypt.h>
#ضمن <winefs.h>
#ضمن <winscard.h>
#جے_انت

#جے_بنا_تعریف NOUSER
#جے_بنا_تعریف NOGDI
#ضمن <winspool.h>
#جے_تعریف_شدہ INC_OLE1
#ضمن <ole.h>
#وإلا
#ضمن <ole2.h>
#جے_انت
#ضمن <commdlg.h>
#جے_انت
#جے_انت
#جے_انت

//gr #include <stralign.h>

#جے_تعریف_شدہ INC_OLE2
#ضمن <ole2.h>
#جے_انت

#جے_بنا_تعریف NOSERVICE
#ضمن <winsvc.h>
#جے_انت

#جے_بنا_تعریف NOMCX
#ضمن <mcx.h>
#جے_انت

#جے_بنا_تعریف NOIME
#ضمن <imm.h>
#جے_انت

#جے_انت
#جے_انت
#جے_انت
