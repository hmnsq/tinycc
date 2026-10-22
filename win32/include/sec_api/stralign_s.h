/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ __STRALIGN_H_S_
#تعریف_کرو __STRALIGN_H_S_

#شامل <stralign.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#اگر defined(__cplusplus) && defined(_WConst_Return)
  ساکن __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,سائز_t Destination_سائز,PCUWSTR ماخذ_2) {
    اگر(WSTR_ALIGNED(ماخذ_2) && WSTR_ALIGNED(Destination)) واپس (wcscpy_s((PWSTR)Destination,Destination_سائز,(PCWSTR)ماخذ_2)==0 ? Destination : تہی);
    واپس uaw_wcscpy((PCUWSTR)String,Character);
  }
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
#اگر_ختم
