/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل __STRALIGN_H_S_
#وصف_ڪريو __STRALIGN_H_S_

#ضمن <stralign.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#إذا defined(__cplusplus) && defined(_WConst_Return)
  ساكن __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,سائيز_t Destination_سائيز,PCUWSTR ذريعو_2) {
    إذا(WSTR_ALIGNED(ذريعو_2) && WSTR_ALIGNED(Destination)) أرجع (wcscpy_s((PWSTR)Destination,Destination_سائيز,(PCWSTR)ذريعو_2)==0 ? Destination : عدم);
    أرجع uaw_wcscpy((PCUWSTR)String,Character);
  }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
