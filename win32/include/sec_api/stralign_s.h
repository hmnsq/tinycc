/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __STRALIGN_H_S_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __STRALIGN_H_S_

#ਅਨ੍ਤਰ੍ਭਾਵ <stralign.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#ਜੇ defined(__cplusplus) && defined(_WConst_Return)
  ਸਥਿਰ __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,ਮਾਪ_t Destination_ਮਾਪ,PCUWSTR ਸਰੋਤ_2) {
    ਜੇ(WSTR_ALIGNED(ਸਰੋਤ_2) && WSTR_ALIGNED(Destination)) ਵਾਪਸ (wcscpy_s((PWSTR)Destination,Destination_ਮਾਪ,(PCWSTR)ਸਰੋਤ_2)==0 ? Destination : ਨਿਰਾ);
    ਵਾਪਸ uaw_wcscpy((PCUWSTR)String,Character);
  }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
