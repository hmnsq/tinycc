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

#অন্তর্ভাব <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#যদি defined(RC_INVOKED) && !defined(NOWINRES)

#অন্তর্ভাব <winresrc.h>
#অন্যথা

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

#যদি !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#যদি !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#যদি !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#যদি !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#অন্তর্ভাব <excpt.h>
#অন্তর্ভাব <stdarg.h>
#endif

#অন্তর্ভাব <windef.h>
#অন্তর্ভাব <winbase.h>
#অন্তর্ভাব <wingdi.h>
#অন্তর্ভাব <winuser.h>
#অন্তর্ভাব <winnls.h>
#অন্তর্ভাব <wincon.h>
#অন্তর্ভাব <winver.h>
#অন্তর্ভাব <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#অন্তর্ভাব <cderr.h>
#অন্তর্ভাব <dde.h>
#অন্তর্ভাব <ddeml.h>
#অন্তর্ভাব <dlgs.h>
#অন্তর্ভাব <lzexpand.h>
#অন্তর্ভাব <mmsystem.h>
#অন্তর্ভাব <nb30.h>
#অন্তর্ভাব <rpc.h>
#অন্তর্ভাব <shellapi.h>
#অন্তর্ভাব <winperf.h>
#অন্তর্ভাব <winsock.h>
#ifndef NOCRYPT
#অন্তর্ভাব <wincrypt.h>
#অন্তর্ভাব <winefs.h>
#অন্তর্ভাব <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#অন্তর্ভাব <winspool.h>
#ifdef INC_OLE1
#অন্তর্ভাব <ole.h>
#অন্যথা
#অন্তর্ভাব <ole2.h>
#endif
#অন্তর্ভাব <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#অন্তর্ভাব <ole2.h>
#endif

#ifndef NOSERVICE
#অন্তর্ভাব <winsvc.h>
#endif

#ifndef NOMCX
#অন্তর্ভাব <mcx.h>
#endif

#ifndef NOIME
#অন্তর্ভাব <imm.h>
#endif

#endif
#endif
#endif
