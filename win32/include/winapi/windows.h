/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINDOWS_
#నిర్వచించు _WINDOWS_

#నిర్వచితం_కాకపోతే WIN32_LEAN_AND_సగటు
#నిర్వచించు WIN32_LEAN_AND_సగటు 1
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINVER
#నిర్వచించు WINVER 0x0502
#అయితే_ముగింపు

#అన్తర్భావ <_mingw.h>

#నిర్వచితం_కాకపోతే _INC_WINDOWS
#నిర్వచించు _INC_WINDOWS

#ఒకవేళ defined(RC_INVOKED) && !defined(NOWINRES)

#అన్తర్భావ <winresrc.h>
#లేకపోతే

#నిర్వచితమైతే RC_INVOKED
#నిర్వచించు NOATOM
#నిర్వచించు NOGDI
#నిర్వచించు NOGDICAPMASKS
#నిర్వచించు NOMETAFILE
#నిర్వచించు NOMINMAX
#నిర్వచించు NOMSG
#నిర్వచించు NOOPENFILE
#నిర్వచించు NORASTEROPS
#నిర్వచించు NOSCROLL
#నిర్వచించు NOSOUND
#నిర్వచించు NOSYSMETRICS
#నిర్వచించు NOTEXTMETRIC
#నిర్వచించు NOWH
#నిర్వచించు NOCOMM
#నిర్వచించు NOKANJI
#నిర్వచించు NOCRYPT
#నిర్వచించు NOMCX
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#నిర్వచించు I_X86_
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#నిర్వచించు _AMD64_
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ఒకవేళ !defined(_IA64_)
#నిర్వచించు _IA64_
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే RC_INVOKED
#అన్తర్భావ <excpt.h>
#అన్తర్భావ <stdarg.h>
#అయితే_ముగింపు

#అన్తర్భావ <windef.h>
#అన్తర్భావ <winbase.h>
#అన్తర్భావ <wingdi.h>
#అన్తర్భావ <winuser.h>
#అన్తర్భావ <winnls.h>
#అన్తర్భావ <wincon.h>
#అన్తర్భావ <winver.h>
#అన్తర్భావ <winreg.h>
//gr #include <winnetwk.h>

#నిర్వచితం_కాకపోతే WIN32_LEAN_AND_సగటు
#అన్తర్భావ <cderr.h>
#అన్తర్భావ <dde.h>
#అన్తర్భావ <ddeml.h>
#అన్తర్భావ <dlgs.h>
#అన్తర్భావ <lzexpand.h>
#అన్తర్భావ <mmsystem.h>
#అన్తర్భావ <nb30.h>
#అన్తర్భావ <rpc.h>
#అన్తర్భావ <shellapi.h>
#అన్తర్భావ <winperf.h>
#అన్తర్భావ <winsock.h>
#నిర్వచితం_కాకపోతే NOCRYPT
#అన్తర్భావ <wincrypt.h>
#అన్తర్భావ <winefs.h>
#అన్తర్భావ <winscard.h>
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOUSER
#నిర్వచితం_కాకపోతే NOGDI
#అన్తర్భావ <winspool.h>
#నిర్వచితమైతే INC_OLE1
#అన్తర్భావ <ole.h>
#లేకపోతే
#అన్తర్భావ <ole2.h>
#అయితే_ముగింపు
#అన్తర్భావ <commdlg.h>
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

//gr #include <stralign.h>

#నిర్వచితమైతే INC_OLE2
#అన్తర్భావ <ole2.h>
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOSERVICE
#అన్తర్భావ <winsvc.h>
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOMCX
#అన్తర్భావ <mcx.h>
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOIME
#అన్తర్భావ <imm.h>
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
