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

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#ଯଦି defined(RC_INVOKED) && !defined(NOWINRES)

#ଅନ୍ତର୍ଭାଵ <winresrc.h>
#ଅନ୍ୟଥା

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

#ଯଦି !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#ଯଦି !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#ଯଦି !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ଯଦି !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#ଅନ୍ତର୍ଭାଵ <excpt.h>
#ଅନ୍ତର୍ଭାଵ <stdarg.h>
#endif

#ଅନ୍ତର୍ଭାଵ <windef.h>
#ଅନ୍ତର୍ଭାଵ <winbase.h>
#ଅନ୍ତର୍ଭାଵ <wingdi.h>
#ଅନ୍ତର୍ଭାଵ <winuser.h>
#ଅନ୍ତର୍ଭାଵ <winnls.h>
#ଅନ୍ତର୍ଭାଵ <wincon.h>
#ଅନ୍ତର୍ଭାଵ <winver.h>
#ଅନ୍ତର୍ଭାଵ <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#ଅନ୍ତର୍ଭାଵ <cderr.h>
#ଅନ୍ତର୍ଭାଵ <dde.h>
#ଅନ୍ତର୍ଭାଵ <ddeml.h>
#ଅନ୍ତର୍ଭାଵ <dlgs.h>
#ଅନ୍ତର୍ଭାଵ <lzexpand.h>
#ଅନ୍ତର୍ଭାଵ <mmsystem.h>
#ଅନ୍ତର୍ଭାଵ <nb30.h>
#ଅନ୍ତର୍ଭାଵ <rpc.h>
#ଅନ୍ତର୍ଭାଵ <shellapi.h>
#ଅନ୍ତର୍ଭାଵ <winperf.h>
#ଅନ୍ତର୍ଭାଵ <winsock.h>
#ifndef NOCRYPT
#ଅନ୍ତର୍ଭାଵ <wincrypt.h>
#ଅନ୍ତର୍ଭାଵ <winefs.h>
#ଅନ୍ତର୍ଭାଵ <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#ଅନ୍ତର୍ଭାଵ <winspool.h>
#ifdef INC_OLE1
#ଅନ୍ତର୍ଭାଵ <ole.h>
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <ole2.h>
#endif
#ଅନ୍ତର୍ଭାଵ <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#ଅନ୍ତର୍ଭାଵ <ole2.h>
#endif

#ifndef NOSERVICE
#ଅନ୍ତର୍ଭାଵ <winsvc.h>
#endif

#ifndef NOMCX
#ଅନ୍ତର୍ଭାଵ <mcx.h>
#endif

#ifndef NOIME
#ଅନ୍ତର୍ଭାଵ <imm.h>
#endif

#endif
#endif
#endif
