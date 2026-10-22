/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINDOWS_
#تعریف_کړه _WINDOWS_

#که_نه_تعریف_شوی WIN32_LEAN_AND_منځنۍ
#تعریف_کړه WIN32_LEAN_AND_منځنۍ 1
#د_که_پای

#که_نه_تعریف_شوی WINVER
#تعریف_کړه WINVER 0x0502
#د_که_پای

#ضمن <_mingw.h>

#که_نه_تعریف_شوی _INC_WINDOWS
#تعریف_کړه _INC_WINDOWS

#إذا defined(RC_INVOKED) && !defined(NOWINRES)

#ضمن <winresrc.h>
#وإلا

#که_تعریف_شوی RC_INVOKED
#تعریف_کړه NOATOM
#تعریف_کړه NOGDI
#تعریف_کړه NOGDICAPMASKS
#تعریف_کړه NOMETAFILE
#تعریف_کړه NOMINMAX
#تعریف_کړه NOMSG
#تعریف_کړه NOOPENFILE
#تعریف_کړه NORASTEROPS
#تعریف_کړه NOSCROLL
#تعریف_کړه NOSOUND
#تعریف_کړه NOSYSMETRICS
#تعریف_کړه NOTEXTMETRIC
#تعریف_کړه NOWH
#تعریف_کړه NOCOMM
#تعریف_کړه NOKANJI
#تعریف_کړه NOCRYPT
#تعریف_کړه NOMCX
#د_که_پای

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کړه I_X86_
#د_که_پای

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کړه _AMD64_
#د_که_پای

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#تعریف_کړه _IA64_
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی RC_INVOKED
#ضمن <excpt.h>
#ضمن <stdarg.h>
#د_که_پای

#ضمن <windef.h>
#ضمن <winbase.h>
#ضمن <wingdi.h>
#ضمن <winuser.h>
#ضمن <winnls.h>
#ضمن <wincon.h>
#ضمن <winver.h>
#ضمن <winreg.h>
//gr #include <winnetwk.h>

#که_نه_تعریف_شوی WIN32_LEAN_AND_منځنۍ
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
#که_نه_تعریف_شوی NOCRYPT
#ضمن <wincrypt.h>
#ضمن <winefs.h>
#ضمن <winscard.h>
#د_که_پای

#که_نه_تعریف_شوی NOUSER
#که_نه_تعریف_شوی NOGDI
#ضمن <winspool.h>
#که_تعریف_شوی INC_OLE1
#ضمن <ole.h>
#وإلا
#ضمن <ole2.h>
#د_که_پای
#ضمن <commdlg.h>
#د_که_پای
#د_که_پای
#د_که_پای

//gr #include <stralign.h>

#که_تعریف_شوی INC_OLE2
#ضمن <ole2.h>
#د_که_پای

#که_نه_تعریف_شوی NOSERVICE
#ضمن <winsvc.h>
#د_که_پای

#که_نه_تعریف_شوی NOMCX
#ضمن <mcx.h>
#د_که_پای

#که_نه_تعریف_شوی NOIME
#ضمن <imm.h>
#د_که_پای

#د_که_پای
#د_که_پای
#د_که_پای
