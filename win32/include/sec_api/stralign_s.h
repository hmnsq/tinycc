/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#ضمن <stralign.h>

#إذا defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

#إذا !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#إذا defined(__cplusplus) && defined(_WConst_Return)
  ساكن __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    إذا(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) إرجاع (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : عدم);
    إرجاع uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
