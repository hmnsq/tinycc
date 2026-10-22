/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WINDOWS_
#घोषणा _WINDOWS_

#अगर_अघोषित WIN32_LEAN_AND_MEAN
#घोषणा WIN32_LEAN_AND_MEAN 1
#पूर्ण_अगर

#अगर_अघोषित WINVER
#घोषणा WINVER 0x0502
#पूर्ण_अगर

#समावेश <_mingw.h>

#अगर_अघोषित _INC_WINDOWS
#घोषणा _INC_WINDOWS

#अगर defined(RC_INVOKED) && !defined(NOWINRES)

#समावेश <winresrc.h>
#अन्यथा

#अगर_घोषित RC_INVOKED
#घोषणा NOATOM
#घोषणा NOGDI
#घोषणा NOGDICAPMASKS
#घोषणा NOMETAFILE
#घोषणा NOMINMAX
#घोषणा NOMSG
#घोषणा NOOPENFILE
#घोषणा NORASTEROPS
#घोषणा NOSCROLL
#घोषणा NOSOUND
#घोषणा NOSYSMETRICS
#घोषणा NOTEXTMETRIC
#घोषणा NOWH
#घोषणा NOCOMM
#घोषणा NOKANJI
#घोषणा NOCRYPT
#घोषणा NOMCX
#पूर्ण_अगर

#अगर !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#घोषणा I_X86_
#पूर्ण_अगर

#अगर !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#घोषणा _AMD64_
#पूर्ण_अगर

#अगर !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#अगर !defined(_IA64_)
#घोषणा _IA64_
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित RC_INVOKED
#समावेश <excpt.h>
#समावेश <stdarg.h>
#पूर्ण_अगर

#समावेश <windef.h>
#समावेश <winbase.h>
#समावेश <wingdi.h>
#समावेश <winuser.h>
#समावेश <winnls.h>
#समावेश <wincon.h>
#समावेश <winver.h>
#समावेश <winreg.h>
//gr #include <winnetwk.h>

#अगर_अघोषित WIN32_LEAN_AND_MEAN
#समावेश <cderr.h>
#समावेश <dde.h>
#समावेश <ddeml.h>
#समावेश <dlgs.h>
#समावेश <lzexpand.h>
#समावेश <mmsystem.h>
#समावेश <nb30.h>
#समावेश <rpc.h>
#समावेश <shellapi.h>
#समावेश <winperf.h>
#समावेश <winsock.h>
#अगर_अघोषित NOCRYPT
#समावेश <wincrypt.h>
#समावेश <winefs.h>
#समावेश <winscard.h>
#पूर्ण_अगर

#अगर_अघोषित NOUSER
#अगर_अघोषित NOGDI
#समावेश <winspool.h>
#अगर_घोषित INC_OLE1
#समावेश <ole.h>
#अन्यथा
#समावेश <ole2.h>
#पूर्ण_अगर
#समावेश <commdlg.h>
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

//gr #include <stralign.h>

#अगर_घोषित INC_OLE2
#समावेश <ole2.h>
#पूर्ण_अगर

#अगर_अघोषित NOSERVICE
#समावेश <winsvc.h>
#पूर्ण_अगर

#अगर_अघोषित NOMCX
#समावेश <mcx.h>
#पूर्ण_अगर

#अगर_अघोषित NOIME
#समावेश <imm.h>
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
