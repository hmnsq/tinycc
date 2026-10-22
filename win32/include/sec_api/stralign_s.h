/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#ଅନ୍ତର୍ଭାଵ <stralign.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ଯଦି !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#ଯଦି defined(__cplusplus) && defined(_WConst_Return)
  ସ୍ଥିର __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    ଯଦି(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) ଫେରନ୍ତୁ (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : ଖାଲି);
    ଫେରନ୍ତୁ uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
