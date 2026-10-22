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

#அந்தர்பாவ <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#எனில் defined(RC_INVOKED) && !defined(NOWINRES)

#அந்தர்பாவ <winresrc.h>
#இல்லையெனில்

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

#எனில் !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#எனில் !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#எனில் !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#எனில் !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#அந்தர்பாவ <excpt.h>
#அந்தர்பாவ <stdarg.h>
#endif

#அந்தர்பாவ <windef.h>
#அந்தர்பாவ <winbase.h>
#அந்தர்பாவ <wingdi.h>
#அந்தர்பாவ <winuser.h>
#அந்தர்பாவ <winnls.h>
#அந்தர்பாவ <wincon.h>
#அந்தர்பாவ <winver.h>
#அந்தர்பாவ <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#அந்தர்பாவ <cderr.h>
#அந்தர்பாவ <dde.h>
#அந்தர்பாவ <ddeml.h>
#அந்தர்பாவ <dlgs.h>
#அந்தர்பாவ <lzexpand.h>
#அந்தர்பாவ <mmsystem.h>
#அந்தர்பாவ <nb30.h>
#அந்தர்பாவ <rpc.h>
#அந்தர்பாவ <shellapi.h>
#அந்தர்பாவ <winperf.h>
#அந்தர்பாவ <winsock.h>
#ifndef NOCRYPT
#அந்தர்பாவ <wincrypt.h>
#அந்தர்பாவ <winefs.h>
#அந்தர்பாவ <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#அந்தர்பாவ <winspool.h>
#ifdef INC_OLE1
#அந்தர்பாவ <ole.h>
#இல்லையெனில்
#அந்தர்பாவ <ole2.h>
#endif
#அந்தர்பாவ <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#அந்தர்பாவ <ole2.h>
#endif

#ifndef NOSERVICE
#அந்தர்பாவ <winsvc.h>
#endif

#ifndef NOMCX
#அந்தர்பாவ <mcx.h>
#endif

#ifndef NOIME
#அந்தர்பாவ <imm.h>
#endif

#endif
#endif
#endif
