/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _WINDOWS_
#تعریف_کرو _WINDOWS_

#اگر_غیر_تعریف_شدہ WIN32_LEAN_AND_اوسط
#تعریف_کرو WIN32_LEAN_AND_اوسط 1
#اگر_ختم

#اگر_غیر_تعریف_شدہ WINVER
#تعریف_کرو WINVER 0x0502
#اگر_ختم

#شامل <_mingw.h>

#اگر_غیر_تعریف_شدہ _INC_WINDOWS
#تعریف_کرو _INC_WINDOWS

#اگر defined(RC_INVOKED) && !defined(NOWINRES)

#شامل <winresrc.h>
#ورنہ

#اگر_تعریف_شدہ RC_INVOKED
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
#اگر_ختم

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کرو I_X86_
#اگر_ختم

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کرو _AMD64_
#اگر_ختم

#اگر !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#اگر !defined(_IA64_)
#تعریف_کرو _IA64_
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ RC_INVOKED
#شامل <excpt.h>
#شامل <stdarg.h>
#اگر_ختم

#شامل <windef.h>
#شامل <winbase.h>
#شامل <wingdi.h>
#شامل <winuser.h>
#شامل <winnls.h>
#شامل <wincon.h>
#شامل <winver.h>
#شامل <winreg.h>
//gr #include <winnetwk.h>

#اگر_غیر_تعریف_شدہ WIN32_LEAN_AND_اوسط
#شامل <cderr.h>
#شامل <dde.h>
#شامل <ddeml.h>
#شامل <dlgs.h>
#شامل <lzexpand.h>
#شامل <mmsystem.h>
#شامل <nb30.h>
#شامل <rpc.h>
#شامل <shellapi.h>
#شامل <winperf.h>
#شامل <winsock.h>
#اگر_غیر_تعریف_شدہ NOCRYPT
#شامل <wincrypt.h>
#شامل <winefs.h>
#شامل <winscard.h>
#اگر_ختم

#اگر_غیر_تعریف_شدہ NOUSER
#اگر_غیر_تعریف_شدہ NOGDI
#شامل <winspool.h>
#اگر_تعریف_شدہ INC_OLE1
#شامل <ole.h>
#ورنہ
#شامل <ole2.h>
#اگر_ختم
#شامل <commdlg.h>
#اگر_ختم
#اگر_ختم
#اگر_ختم

//gr #include <stralign.h>

#اگر_تعریف_شدہ INC_OLE2
#شامل <ole2.h>
#اگر_ختم

#اگر_غیر_تعریف_شدہ NOSERVICE
#شامل <winsvc.h>
#اگر_ختم

#اگر_غیر_تعریف_شدہ NOMCX
#شامل <mcx.h>
#اگر_ختم

#اگر_غیر_تعریف_شدہ NOIME
#شامل <imm.h>
#اگر_ختم

#اگر_ختم
#اگر_ختم
#اگر_ختم
