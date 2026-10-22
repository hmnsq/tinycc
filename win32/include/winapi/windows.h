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

#অন্তর্ভাৱ <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#যদি defined(RC_INVOKED) && !defined(NOWINRES)

#অন্তর্ভাৱ <winresrc.h>
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
#অন্তর্ভাৱ <excpt.h>
#অন্তর্ভাৱ <stdarg.h>
#endif

#অন্তর্ভাৱ <windef.h>
#অন্তর্ভাৱ <winbase.h>
#অন্তর্ভাৱ <wingdi.h>
#অন্তর্ভাৱ <winuser.h>
#অন্তর্ভাৱ <winnls.h>
#অন্তর্ভাৱ <wincon.h>
#অন্তর্ভাৱ <winver.h>
#অন্তর্ভাৱ <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#অন্তর্ভাৱ <cderr.h>
#অন্তর্ভাৱ <dde.h>
#অন্তর্ভাৱ <ddeml.h>
#অন্তর্ভাৱ <dlgs.h>
#অন্তর্ভাৱ <lzexpand.h>
#অন্তর্ভাৱ <mmsystem.h>
#অন্তর্ভাৱ <nb30.h>
#অন্তর্ভাৱ <rpc.h>
#অন্তর্ভাৱ <shellapi.h>
#অন্তর্ভাৱ <winperf.h>
#অন্তর্ভাৱ <winsock.h>
#ifndef NOCRYPT
#অন্তর্ভাৱ <wincrypt.h>
#অন্তর্ভাৱ <winefs.h>
#অন্তর্ভাৱ <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#অন্তর্ভাৱ <winspool.h>
#ifdef INC_OLE1
#অন্তর্ভাৱ <ole.h>
#অন্যথা
#অন্তর্ভাৱ <ole2.h>
#endif
#অন্তর্ভাৱ <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#অন্তর্ভাৱ <ole2.h>
#endif

#ifndef NOSERVICE
#অন্তর্ভাৱ <winsvc.h>
#endif

#ifndef NOMCX
#অন্তর্ভাৱ <mcx.h>
#endif

#ifndef NOIME
#অন্তর্ভাৱ <imm.h>
#endif

#endif
#endif
#endif
