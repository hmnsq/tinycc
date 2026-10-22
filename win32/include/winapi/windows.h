/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINDOWS_
#define _WINDOWS_

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#شامل <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#اگر defined(RC_INVOKED) && !defined(NOWINRES)

#شامل <winresrc.h>
#وگرنه

#ifdef RC_INVOKED
#define NOATOM
#define NOGDI
#define NOGDICAPMASKS
#define NOMETAFILE
#define NOMINMAX
#define NOMSG
#define NOOPENFILE
#define NORASTEROPS
#define NOSCROLL
#define NOSOUND
#define NOSYSMETRICS
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOCRYPT
#define NOMCX
#endif

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#اگر !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#اگر !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#شامل <excpt.h>
#شامل <stdarg.h>
#endif

#شامل <windef.h>
#شامل <winbase.h>
#شامل <wingdi.h>
#شامل <winuser.h>
#شامل <winnls.h>
#شامل <wincon.h>
#شامل <winver.h>
#شامل <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
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
#ifndef NOCRYPT
#شامل <wincrypt.h>
#شامل <winefs.h>
#شامل <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#شامل <winspool.h>
#ifdef INC_OLE1
#شامل <ole.h>
#وگرنه
#شامل <ole2.h>
#endif
#شامل <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#شامل <ole2.h>
#endif

#ifndef NOSERVICE
#شامل <winsvc.h>
#endif

#ifndef NOMCX
#شامل <mcx.h>
#endif

#ifndef NOIME
#شامل <imm.h>
#endif

#endif
#endif
#endif
