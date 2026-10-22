/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#অন্তর্ভাব <stralign.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#যদি !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#যদি defined(__cplusplus) && defined(_WConst_Return)
  স্থির __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,আকার_t Destination_আকার,PCUWSTR Source) {
    যদি(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) ফেরত (wcscpy_s((PWSTR)Destination,Destination_আকার,(PCWSTR)Source)==0 ? Destination : ফাঁকা);
    ফেরত uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
