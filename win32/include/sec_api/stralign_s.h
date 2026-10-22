/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#അന്തര്ഭാവ <stralign.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#എങ്കിൽ !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#എങ്കിൽ defined(__cplusplus) && defined(_WConst_Return)
  സ്ഥിതം __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    എങ്കിൽ(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) തിരികെ (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : ശൂന്യ);
    തിരികെ uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
