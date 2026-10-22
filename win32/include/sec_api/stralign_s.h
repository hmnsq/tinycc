/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده __STRALIGN_H_S_
#تعریف_کن __STRALIGN_H_S_

#ضمن <stralign.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#إذا !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#إذا defined(__cplusplus) && defined(_WConst_Return)
  ساكن __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,اندازه_t Destination_اندازه,PCUWSTR منبع_2) {
    إذا(WSTR_ALIGNED(منبع_2) && WSTR_ALIGNED(Destination)) أرجع (wcscpy_s((PWSTR)Destination,Destination_اندازه,(PCWSTR)منبع_2)==0 ? Destination : عدم);
    أرجع uaw_wcscpy((PCUWSTR)String,Character);
  }
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
#پایان_اگر
