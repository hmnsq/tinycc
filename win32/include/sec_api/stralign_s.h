/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् __STRALIGN_H_S_
#परिभाषय __STRALIGN_H_S_

#अन्तर्भाव <stralign.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#यदि defined(__cplusplus) && defined(_WConst_Return)
  स्थिर __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,आकार_t Destination_आकार,PCUWSTR Source) {
    यदि(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) प्रत्यागम (wcscpy_s((PWSTR)Destination,Destination_आकार,(PCWSTR)Source)==0 ? Destination : रिक्त);
    प्रत्यागम uaw_wcscpy((PCUWSTR)String,Character);
  }
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
