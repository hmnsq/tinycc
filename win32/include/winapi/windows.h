/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINDOWS_
#परिभाषय _WINDOWS_

#यदि_अपरिभाषितम् WIN32_LEAN_AND_माध्यम्
#परिभाषय WIN32_LEAN_AND_माध्यम् 1
#यदि_अन्तः

#यदि_अपरिभाषितम् WINVER
#परिभाषय WINVER 0x0502
#यदि_अन्तः

#अन्तर्भाव <_mingw.h>

#यदि_अपरिभाषितम् _INC_WINDOWS
#परिभाषय _INC_WINDOWS

#यदि defined(RC_INVOKED) && !defined(NOWINRES)

#अन्तर्भाव <winresrc.h>
#अन्यथा

#यदि_परिभाषितम् RC_INVOKED
#परिभाषय NOATOM
#परिभाषय NOGDI
#परिभाषय NOGDICAPMASKS
#परिभाषय NOMETAFILE
#परिभाषय NOMINMAX
#परिभाषय NOMSG
#परिभाषय NOOPENFILE
#परिभाषय NORASTEROPS
#परिभाषय NOSCROLL
#परिभाषय NOSOUND
#परिभाषय NOSYSMETRICS
#परिभाषय NOTEXTMETRIC
#परिभाषय NOWH
#परिभाषय NOCOMM
#परिभाषय NOKANJI
#परिभाषय NOCRYPT
#परिभाषय NOMCX
#यदि_अन्तः

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#परिभाषय I_X86_
#यदि_अन्तः

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#परिभाषय _AMD64_
#यदि_अन्तः

#यदि !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#यदि !defined(_IA64_)
#परिभाषय _IA64_
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् RC_INVOKED
#अन्तर्भाव <excpt.h>
#अन्तर्भाव <stdarg.h>
#यदि_अन्तः

#अन्तर्भाव <windef.h>
#अन्तर्भाव <winbase.h>
#अन्तर्भाव <wingdi.h>
#अन्तर्भाव <winuser.h>
#अन्तर्भाव <winnls.h>
#अन्तर्भाव <wincon.h>
#अन्तर्भाव <winver.h>
#अन्तर्भाव <winreg.h>
//gr #include <winnetwk.h>

#यदि_अपरिभाषितम् WIN32_LEAN_AND_माध्यम्
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
#यदि_अपरिभाषितम् NOCRYPT
#अन्तर्भाव <wincrypt.h>
#अन्तर्भाव <winefs.h>
#अन्तर्भाव <winscard.h>
#यदि_अन्तः

#यदि_अपरिभाषितम् NOUSER
#यदि_अपरिभाषितम् NOGDI
#अन्तर्भाव <winspool.h>
#यदि_परिभाषितम् INC_OLE1
#अन्तर्भाव <ole.h>
#अन्यथा
#अन्तर्भाव <ole2.h>
#यदि_अन्तः
#अन्तर्भाव <commdlg.h>
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

//gr #include <stralign.h>

#यदि_परिभाषितम् INC_OLE2
#अन्तर्भाव <ole2.h>
#यदि_अन्तः

#यदि_अपरिभाषितम् NOSERVICE
#अन्तर्भाव <winsvc.h>
#यदि_अन्तः

#यदि_अपरिभाषितम् NOMCX
#अन्तर्भाव <mcx.h>
#यदि_अन्तः

#यदि_अपरिभाषितम् NOIME
#अन्तर्भाव <imm.h>
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
