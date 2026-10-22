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

#અન્તર્ભાવ <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#જો defined(RC_INVOKED) && !defined(NOWINRES)

#અન્તર્ભાવ <winresrc.h>
#નહીંતર

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

#જો !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#જો !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#જો !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#જો !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#અન્તર્ભાવ <excpt.h>
#અન્તર્ભાવ <stdarg.h>
#endif

#અન્તર્ભાવ <windef.h>
#અન્તર્ભાવ <winbase.h>
#અન્તર્ભાવ <wingdi.h>
#અન્તર્ભાવ <winuser.h>
#અન્તર્ભાવ <winnls.h>
#અન્તર્ભાવ <wincon.h>
#અન્તર્ભાવ <winver.h>
#અન્તર્ભાવ <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#અન્તર્ભાવ <cderr.h>
#અન્તર્ભાવ <dde.h>
#અન્તર્ભાવ <ddeml.h>
#અન્તર્ભાવ <dlgs.h>
#અન્તર્ભાવ <lzexpand.h>
#અન્તર્ભાવ <mmsystem.h>
#અન્તર્ભાવ <nb30.h>
#અન્તર્ભાવ <rpc.h>
#અન્તર્ભાવ <shellapi.h>
#અન્તર્ભાવ <winperf.h>
#અન્તર્ભાવ <winsock.h>
#ifndef NOCRYPT
#અન્તર્ભાવ <wincrypt.h>
#અન્તર્ભાવ <winefs.h>
#અન્તર્ભાવ <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#અન્તર્ભાવ <winspool.h>
#ifdef INC_OLE1
#અન્તર્ભાવ <ole.h>
#નહીંતર
#અન્તર્ભાવ <ole2.h>
#endif
#અન્તર્ભાવ <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#અન્તર્ભાવ <ole2.h>
#endif

#ifndef NOSERVICE
#અન્તર્ભાવ <winsvc.h>
#endif

#ifndef NOMCX
#અન્તર્ભાવ <mcx.h>
#endif

#ifndef NOIME
#અન્તર્ભાવ <imm.h>
#endif

#endif
#endif
#endif
