/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __STRALIGN_H_S_
#define __STRALIGN_H_S_

#अन्तर्भाव <stralign.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

#यदि !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#यदि defined(__cplusplus) && defined(_WConst_Return)
  स्थिर __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,माप_प्रकार DestinationSize,PCUWSTR Source) {
    यदि(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) प्रत्यागम (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : रिक्त);
    प्रत्यागम uaw_wcscpy((PCUWSTR)String,Character);
  }
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
