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

#ضمن <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#إذا defined(RC_INVOKED) && !defined(NOWINRES)

#ضمن <winresrc.h>
#وإلا

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

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#ضمن <excpt.h>
#ضمن <stdarg.h>
#endif

#ضمن <windef.h>
#ضمن <winbase.h>
#ضمن <wingdi.h>
#ضمن <winuser.h>
#ضمن <winnls.h>
#ضمن <wincon.h>
#ضمن <winver.h>
#ضمن <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
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
#ifndef NOCRYPT
#ضمن <wincrypt.h>
#ضمن <winefs.h>
#ضمن <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#ضمن <winspool.h>
#ifdef INC_OLE1
#ضمن <ole.h>
#وإلا
#ضمن <ole2.h>
#endif
#ضمن <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#ضمن <ole2.h>
#endif

#ifndef NOSERVICE
#ضمن <winsvc.h>
#endif

#ifndef NOMCX
#ضمن <mcx.h>
#endif

#ifndef NOIME
#ضمن <imm.h>
#endif

#endif
#endif
#endif
