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

#അന്തര്ഭാവ <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#എങ്കിൽ defined(RC_INVOKED) && !defined(NOWINRES)

#അന്തര്ഭാവ <winresrc.h>
#അല്ലെങ്കിൽ

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

#എങ്കിൽ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#എങ്കിൽ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#എങ്കിൽ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#എങ്കിൽ !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#അന്തര്ഭാവ <excpt.h>
#അന്തര്ഭാവ <stdarg.h>
#endif

#അന്തര്ഭാവ <windef.h>
#അന്തര്ഭാവ <winbase.h>
#അന്തര്ഭാവ <wingdi.h>
#അന്തര്ഭാവ <winuser.h>
#അന്തര്ഭാവ <winnls.h>
#അന്തര്ഭാവ <wincon.h>
#അന്തര്ഭാവ <winver.h>
#അന്തര്ഭാവ <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#അന്തര്ഭാവ <cderr.h>
#അന്തര്ഭാവ <dde.h>
#അന്തര്ഭാവ <ddeml.h>
#അന്തര്ഭാവ <dlgs.h>
#അന്തര്ഭാവ <lzexpand.h>
#അന്തര്ഭാവ <mmsystem.h>
#അന്തര്ഭാവ <nb30.h>
#അന്തര്ഭാവ <rpc.h>
#അന്തര്ഭാവ <shellapi.h>
#അന്തര്ഭാവ <winperf.h>
#അന്തര്ഭാവ <winsock.h>
#ifndef NOCRYPT
#അന്തര്ഭാവ <wincrypt.h>
#അന്തര്ഭാവ <winefs.h>
#അന്തര്ഭാവ <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#അന്തര്ഭാവ <winspool.h>
#ifdef INC_OLE1
#അന്തര്ഭാവ <ole.h>
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <ole2.h>
#endif
#അന്തര്ഭാവ <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#അന്തര്ഭാവ <ole2.h>
#endif

#ifndef NOSERVICE
#അന്തര്ഭാവ <winsvc.h>
#endif

#ifndef NOMCX
#അന്തര്ഭാവ <mcx.h>
#endif

#ifndef NOIME
#അന്തര്ഭാവ <imm.h>
#endif

#endif
#endif
#endif
