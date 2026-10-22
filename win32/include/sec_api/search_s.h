/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_ಹುಡುಕು_S
#define INC_ಹುಡುಕು_S

#ಅನ್ತರ್ಭಾವ <search.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP ಶೂನ್ಯ *__cdecl _lfind_s(ಧ್ರುವ ಶೂನ್ಯ *ಕೀಲಿ_2,ಧ್ರುವ ಶೂನ್ಯ *_Base,unsigned ಪೂರ್ಣಾಙ್ಕ *ಅಂಕೆ_Of_Elements,size_t _SizeOfElements,ಪೂರ್ಣಾಙ್ಕ (__cdecl *_PtFuncCompare)(ಶೂನ್ಯ *,ಧ್ರುವ ಶೂನ್ಯ *,ಧ್ರುವ ಶೂನ್ಯ *),ಶೂನ್ಯ *_Context);
  _CRTIMP ಶೂನ್ಯ *__cdecl _lsearch_s(ಧ್ರುವ ಶೂನ್ಯ *ಕೀಲಿ_2,ಶೂನ್ಯ *_Base,unsigned ಪೂರ್ಣಾಙ್ಕ *ಅಂಕೆ_Of_Elements,size_t _SizeOfElements,ಪೂರ್ಣಾಙ್ಕ (__cdecl *_PtFuncCompare)(ಶೂನ್ಯ *,ಧ್ರುವ ಶೂನ್ಯ *,ಧ್ರುವ ಶೂನ್ಯ *),ಶೂನ್ಯ *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
