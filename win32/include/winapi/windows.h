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

#अन्तर्भाव <_mingw.h>

#ifndef _INC_WINDOWS
#define _INC_WINDOWS

#यदि defined(RC_INVOKED) && !defined(NOWINRES)

#अन्तर्भाव <winresrc.h>
#अन्यथा

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

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#define I_X86_
#endif

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#define _AMD64_
#endif

#यदि !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#यदि !defined(_IA64_)
#define _IA64_
#endif
#endif

#ifndef RC_INVOKED
#अन्तर्भाव <excpt.h>
#अन्तर्भाव <stdarg.h>
#endif

#अन्तर्भाव <windef.h>
#अन्तर्भाव <winbase.h>
#अन्तर्भाव <wingdi.h>
#अन्तर्भाव <winuser.h>
#अन्तर्भाव <winnls.h>
#अन्तर्भाव <wincon.h>
#अन्तर्भाव <winver.h>
#अन्तर्भाव <winreg.h>
//gr #include <winnetwk.h>

#ifndef WIN32_LEAN_AND_MEAN
#अन्तर्भाव <cderr.h>
#अन्तर्भाव <dde.h>
#अन्तर्भाव <ddeml.h>
#अन्तर्भाव <dlgs.h>
#अन्तर्भाव <lzexpand.h>
#अन्तर्भाव <mmsystem.h>
#अन्तर्भाव <nb30.h>
#अन्तर्भाव <rpc.h>
#अन्तर्भाव <shellapi.h>
#अन्तर्भाव <winperf.h>
#अन्तर्भाव <winsock.h>
#ifndef NOCRYPT
#अन्तर्भाव <wincrypt.h>
#अन्तर्भाव <winefs.h>
#अन्तर्भाव <winscard.h>
#endif

#ifndef NOUSER
#ifndef NOGDI
#अन्तर्भाव <winspool.h>
#ifdef INC_OLE1
#अन्तर्भाव <ole.h>
#अन्यथा
#अन्तर्भाव <ole2.h>
#endif
#अन्तर्भाव <commdlg.h>
#endif
#endif
#endif

//gr #include <stralign.h>

#ifdef INC_OLE2
#अन्तर्भाव <ole2.h>
#endif

#ifndef NOSERVICE
#अन्तर्भाव <winsvc.h>
#endif

#ifndef NOMCX
#अन्तर्भाव <mcx.h>
#endif

#ifndef NOIME
#अन्तर्भाव <imm.h>
#endif

#endif
#endif
#endif
