/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#અન્તર્ભાવ <stralign.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#જો !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#જો defined(__cplusplus) && defined(_WConst_Return)
  સ્થિર __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    જો(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) પાછા (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : ખાલી);
    પાછા uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
