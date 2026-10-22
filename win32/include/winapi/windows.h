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

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#ಯದಿ defined(RC_INVOKED) && !defined(NOWINRES)

#ಅನ್ತರ್ಭಾವ <winresrc.h>
#ಅನ್ಯಥಾ

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

#ಯದಿ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#ಯದಿ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#ಯದಿ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ಯದಿ !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#ಅನ್ತರ್ಭಾವ <excpt.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>
#endif

#ಅನ್ತರ್ಭಾವ <windef.h>
#ಅನ್ತರ್ಭಾವ <winbase.h>
#ಅನ್ತರ್ಭಾವ <wingdi.h>
#ಅನ್ತರ್ಭಾವ <winuser.h>
#ಅನ್ತರ್ಭಾವ <winnls.h>
#ಅನ್ತರ್ಭಾವ <wincon.h>
#ಅನ್ತರ್ಭಾವ <winver.h>
#ಅನ್ತರ್ಭಾವ <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#ಅನ್ತರ್ಭಾವ <cderr.h>
#ಅನ್ತರ್ಭಾವ <dde.h>
#ಅನ್ತರ್ಭಾವ <ddeml.h>
#ಅನ್ತರ್ಭಾವ <dlgs.h>
#ಅನ್ತರ್ಭಾವ <lzexpand.h>
#ಅನ್ತರ್ಭಾವ <mmsystem.h>
#ಅನ್ತರ್ಭಾವ <nb30.h>
#ಅನ್ತರ್ಭಾವ <rpc.h>
#ಅನ್ತರ್ಭಾವ <shellapi.h>
#ಅನ್ತರ್ಭಾವ <winperf.h>
#ಅನ್ತರ್ಭಾವ <winsock.h>
#ifndef NOCRYPT
#ಅನ್ತರ್ಭಾವ <wincrypt.h>
#ಅನ್ತರ್ಭಾವ <winefs.h>
#ಅನ್ತರ್ಭಾವ <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#ಅನ್ತರ್ಭಾವ <winspool.h>
#ifdef INC_OLE1
#ಅನ್ತರ್ಭಾವ <ole.h>
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <ole2.h>
#endif
#ಅನ್ತರ್ಭಾವ <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#ಅನ್ತರ್ಭಾವ <ole2.h>
#endif

#ifndef NOSERVICE
#ಅನ್ತರ್ಭಾವ <winsvc.h>
#endif

#ifndef NOMCX
#ಅನ್ತರ್ಭಾವ <mcx.h>
#endif

#ifndef NOIME
#ಅನ್ತರ್ಭಾವ <imm.h>
#endif

#endif
#endif
#endif
