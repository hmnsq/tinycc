/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINDOWS_
#وصف_ڪريو _WINDOWS_

#جيڪڏهن_وصف_نه_ٿيل WIN32_LEAN_AND_سراسري
#وصف_ڪريو WIN32_LEAN_AND_سراسري 1
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINVER
#وصف_ڪريو WINVER 0x0502
#جيڪڏهن_پورو

#ضمن <_mingw.h>

#جيڪڏهن_وصف_نه_ٿيل _INC_WINDOWS
#وصف_ڪريو _INC_WINDOWS

#إذا defined(RC_INVOKED) && !defined(NOWINRES)

#ضمن <winresrc.h>
#وإلا

#جيڪڏهن_وصف_ٿيل RC_INVOKED
#وصف_ڪريو NOATOM
#وصف_ڪريو NOGDI
#وصف_ڪريو NOGDICAPMASKS
#وصف_ڪريو NOMETAFILE
#وصف_ڪريو NOMINMAX
#وصف_ڪريو NOMSG
#وصف_ڪريو NOOPENFILE
#وصف_ڪريو NORASTEROPS
#وصف_ڪريو NOSCROLL
#وصف_ڪريو NOSOUND
#وصف_ڪريو NOSYSMETRICS
#وصف_ڪريو NOTEXTMETRIC
#وصف_ڪريو NOWH
#وصف_ڪريو NOCOMM
#وصف_ڪريو NOKANJI
#وصف_ڪريو NOCRYPT
#وصف_ڪريو NOMCX
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#وصف_ڪريو I_X86_
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#وصف_ڪريو _AMD64_
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#وصف_ڪريو _IA64_
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#ضمن <excpt.h>
#ضمن <stdarg.h>
#جيڪڏهن_پورو

#ضمن <windef.h>
#ضمن <winbase.h>
#ضمن <wingdi.h>
#ضمن <winuser.h>
#ضمن <winnls.h>
#ضمن <wincon.h>
#ضمن <winver.h>
#ضمن <winreg.h>
//gr #include <winnetwk.h>

#جيڪڏهن_وصف_نه_ٿيل WIN32_LEAN_AND_سراسري
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
#جيڪڏهن_وصف_نه_ٿيل NOCRYPT
#ضمن <wincrypt.h>
#ضمن <winefs.h>
#ضمن <winscard.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOUSER
#جيڪڏهن_وصف_نه_ٿيل NOGDI
#ضمن <winspool.h>
#جيڪڏهن_وصف_ٿيل INC_OLE1
#ضمن <ole.h>
#وإلا
#ضمن <ole2.h>
#جيڪڏهن_پورو
#ضمن <commdlg.h>
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

//gr #include <stralign.h>

#جيڪڏهن_وصف_ٿيل INC_OLE2
#ضمن <ole2.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOSERVICE
#ضمن <winsvc.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOMCX
#ضمن <mcx.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOIME
#ضمن <imm.h>
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
