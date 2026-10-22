/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#অন্তর্ভাৱ <stralign.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#যদি !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#যদি defined(__cplusplus) && defined(_WConst_Return)
  স্থির __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    যদি(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) ঘূৰাই (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : রিক্ত);
    ঘূৰাই uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
