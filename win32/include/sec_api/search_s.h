/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित INC_खोज_S
#घोषणा INC_खोज_S

#समावेश <search.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP व्योम *__cdecl _lfind_s(स्थिर व्योम *कुंजी_2,स्थिर व्योम *_Base,अचिन्हित पूर्णांक *अंक_Of_Elements,माप_प्रकार आकार_Of_Elements,पूर्णांक (__cdecl *_PtFuncCompare)(व्योम *,स्थिर व्योम *,स्थिर व्योम *),व्योम *_Context);
  _CRTIMP व्योम *__cdecl _lsearch_s(स्थिर व्योम *कुंजी_2,व्योम *_Base,अचिन्हित पूर्णांक *अंक_Of_Elements,माप_प्रकार आकार_Of_Elements,पूर्णांक (__cdecl *_PtFuncCompare)(व्योम *,स्थिर व्योम *,स्थिर व्योम *),व्योम *_Context);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
