/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINDOWS_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINDOWS_

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WIN32_LEAN_AND_ਔਸਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WIN32_LEAN_AND_ਔਸਤ 1
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINVER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINVER 0x0502
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_WINDOWS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_WINDOWS

#ਜੇ defined(RC_INVOKED) && !defined(NOWINRES)

#ਅਨ੍ਤਰ੍ਭਾਵ <winresrc.h>
#ਨਹੀਂਤਾਂ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOATOM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOGDI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOGDICAPMASKS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOMETAFILE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOMINMAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOMSG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOOPENFILE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NORASTEROPS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOSCROLL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOSOUND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOSYSMETRICS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOTEXTMETRIC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOWH
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOCOMM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOKANJI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOCRYPT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOMCX
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ I_X86_
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _AMD64_
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ਜੇ !defined(_IA64_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IA64_
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਅਨ੍ਤਰ੍ਭਾਵ <excpt.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <windef.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winbase.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <wingdi.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winuser.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winnls.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <wincon.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winver.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winreg.h>
//gr #include <winnetwk.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WIN32_LEAN_AND_ਔਸਤ
#ਅਨ੍ਤਰ੍ਭਾਵ <cderr.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <dde.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <ddeml.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <dlgs.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <lzexpand.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <mmsystem.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <nb30.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <rpc.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <shellapi.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winperf.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winsock.h>
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOCRYPT
#ਅਨ੍ਤਰ੍ਭਾਵ <wincrypt.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winefs.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <winscard.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOUSER
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDI
#ਅਨ੍ਤਰ੍ਭਾਵ <winspool.h>
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_OLE1
#ਅਨ੍ਤਰ੍ਭਾਵ <ole.h>
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <ole2.h>
#ਜੇ_ਅੰਤ
#ਅਨ੍ਤਰ੍ਭਾਵ <commdlg.h>
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

//gr #include <stralign.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_OLE2
#ਅਨ੍ਤਰ੍ਭਾਵ <ole2.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSERVICE
#ਅਨ੍ਤਰ੍ਭਾਵ <winsvc.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMCX
#ਅਨ੍ਤਰ੍ਭਾਵ <mcx.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOIME
#ਅਨ੍ਤਰ੍ਭਾਵ <imm.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
