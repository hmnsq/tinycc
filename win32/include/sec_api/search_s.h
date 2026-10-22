/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_शोध_S
#define INC_शोध_S

#अन्तर्भाव <search.h>

#जर defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP शून्य *__cdecl _lfind_s(स्थिरांक शून्य *किल्ली_2,स्थिरांक शून्य *_Base,अचिन्हित पूर्णांक *अंक_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णांक (__cdecl *_PtFuncCompare)(शून्य *,स्थिरांक शून्य *,स्थिरांक शून्य *),शून्य *_Context);
  _CRTIMP शून्य *__cdecl _lsearch_s(स्थिरांक शून्य *किल्ली_2,शून्य *_Base,अचिन्हित पूर्णांक *अंक_Of_Elements,माप_प्रकार _SizeOfElements,पूर्णांक (__cdecl *_PtFuncCompare)(शून्य *,स्थिरांक शून्य *,स्थिरांक शून्य *),शून्य *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
