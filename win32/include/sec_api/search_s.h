/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_खोज_S
#define INC_खोज_S

#अन्तर्भाव <search.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP शून्य *__cdecl _lfind_s(अचर शून्य *साँचो_2,अचर शून्य *_Base,अचिन्हित पूर्णाङ्क *अङ्क_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(शून्य *,अचर शून्य *,अचर शून्य *),शून्य *_Context);
  _CRTIMP शून्य *__cdecl _lsearch_s(अचर शून्य *साँचो_2,शून्य *_Base,अचिन्हित पूर्णाङ्क *अङ्क_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(शून्य *,अचर शून्य *,अचर शून्य *),शून्य *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
