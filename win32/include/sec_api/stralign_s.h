/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __STRALIGN_H_S_
#ವ್ಯಾಖ್ಯಾನಿಸು __STRALIGN_H_S_

#ಅನ್ತರ್ಭಾವ <stralign.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#ಆದರೆ defined(__cplusplus) && defined(_WConst_Return)
  ಸ್ಥಿರ __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,ಗಾತ್ರ_t Destination_ಗಾತ್ರ,PCUWSTR ಮೂಲ_2) {
    ಆದರೆ(WSTR_ALIGNED(ಮೂಲ_2) && WSTR_ALIGNED(Destination)) ಹಿಂತಿರುಗಿ (wcscpy_s((PWSTR)Destination,Destination_ಗಾತ್ರ,(PCWSTR)ಮೂಲ_2)==0 ? Destination : ಖಾಲಿ);
    ಹಿಂತಿರುಗಿ uaw_wcscpy((PCUWSTR)String,Character);
  }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
