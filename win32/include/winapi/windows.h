/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINDOWS_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINDOWS_

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WIN32_LEAN_AND_ಸರಾಸರಿ
#ವ್ಯಾಖ್ಯಾನಿಸು WIN32_LEAN_AND_ಸರಾಸರಿ 1
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINVER
#ವ್ಯಾಖ್ಯಾನಿಸು WINVER 0x0502
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_WINDOWS
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_WINDOWS

#ಆದರೆ defined(RC_INVOKED) && !defined(NOWINRES)

#ಅನ್ತರ್ಭಾವ <winresrc.h>
#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿಸು NOATOM
#ವ್ಯಾಖ್ಯಾನಿಸು NOGDI
#ವ್ಯಾಖ್ಯಾನಿಸು NOGDICAPMASKS
#ವ್ಯಾಖ್ಯಾನಿಸು NOMETAFILE
#ವ್ಯಾಖ್ಯಾನಿಸು NOMINMAX
#ವ್ಯಾಖ್ಯಾನಿಸು NOMSG
#ವ್ಯಾಖ್ಯಾನಿಸು NOOPENFILE
#ವ್ಯಾಖ್ಯಾನಿಸು NORASTEROPS
#ವ್ಯಾಖ್ಯಾನಿಸು NOSCROLL
#ವ್ಯಾಖ್ಯಾನಿಸು NOSOUND
#ವ್ಯಾಖ್ಯಾನಿಸು NOSYSMETRICS
#ವ್ಯಾಖ್ಯಾನಿಸು NOTEXTMETRIC
#ವ್ಯಾಖ್ಯಾನಿಸು NOWH
#ವ್ಯಾಖ್ಯಾನಿಸು NOCOMM
#ವ್ಯಾಖ್ಯಾನಿಸು NOKANJI
#ವ್ಯಾಖ್ಯಾನಿಸು NOCRYPT
#ವ್ಯಾಖ್ಯಾನಿಸು NOMCX
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#ವ್ಯಾಖ್ಯಾನಿಸು I_X86_
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#ವ್ಯಾಖ್ಯಾನಿಸು _AMD64_
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ಆದರೆ !defined(_IA64_)
#ವ್ಯಾಖ್ಯಾನಿಸು _IA64_
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ಅನ್ತರ್ಭಾವ <excpt.h>
#ಅನ್ತರ್ಭಾವ <stdarg.h>
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <windef.h>
#ಅನ್ತರ್ಭಾವ <winbase.h>
#ಅನ್ತರ್ಭಾವ <wingdi.h>
#ಅನ್ತರ್ಭಾವ <winuser.h>
#ಅನ್ತರ್ಭಾವ <winnls.h>
#ಅನ್ತರ್ಭಾವ <wincon.h>
#ಅನ್ತರ್ಭಾವ <winver.h>
#ಅನ್ತರ್ಭಾವ <winreg.h>
//gr #include <winnetwk.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WIN32_LEAN_AND_ಸರಾಸರಿ
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
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOCRYPT
#ಅನ್ತರ್ಭಾವ <wincrypt.h>
#ಅನ್ತರ್ಭಾವ <winefs.h>
#ಅನ್ತರ್ಭಾವ <winscard.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOUSER
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDI
#ಅನ್ತರ್ಭಾವ <winspool.h>
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_OLE1
#ಅನ್ತರ್ಭಾವ <ole.h>
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <ole2.h>
#ಆದರೆ_ಅಂತ್ಯ
#ಅನ್ತರ್ಭಾವ <commdlg.h>
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

//gr #include <stralign.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_OLE2
#ಅನ್ತರ್ಭಾವ <ole2.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSERVICE
#ಅನ್ತರ್ಭಾವ <winsvc.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMCX
#ಅನ್ತರ್ಭಾವ <mcx.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOIME
#ಅನ್ತರ್ಭಾವ <imm.h>
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
