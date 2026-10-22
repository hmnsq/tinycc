/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित __STRALIGN_H_S_
#घोषणा __STRALIGN_H_S_

#समावेश <stralign.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#अगर defined(__cplusplus) && defined(_WConst_Return)
  अटल __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,माप_प्रकार Destination_आकार,PCUWSTR Source) {
    अगर(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) वापस (wcscpy_s((PWSTR)Destination,Destination_आकार,(PCWSTR)Source)==0 ? Destination : शून्य);
    वापस uaw_wcscpy((PCUWSTR)String,Character);
  }
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
