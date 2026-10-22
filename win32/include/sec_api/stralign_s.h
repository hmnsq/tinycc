/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف __STRALIGN_H_S_
#تعریف_کرو __STRALIGN_H_S_

#ضمن <stralign.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#إذا !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#إذا defined(__cplusplus) && defined(_WConst_Return)
  ساكن __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,ناپ_t Destination_ناپ,PCUWSTR سروت_2) {
    إذا(WSTR_ALIGNED(سروت_2) && WSTR_ALIGNED(Destination)) أرجع (wcscpy_s((PWSTR)Destination,Destination_ناپ,(PCWSTR)سروت_2)==0 ? Destination : عدم);
    أرجع uaw_wcscpy((PCUWSTR)String,Character);
  }
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
#جے_انت
