/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_MEMORY
#घोषणा _INC_MEMORY

#समावेश <_mingw.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CONST_RETURN
#घोषणा _CONST_RETURN
#पूर्ण_अगर

#घोषणा _WConst_return _CONST_RETURN

#अगर_अघोषित _CRT_MEMORY_DEFINED
#घोषणा _CRT_MEMORY_DEFINED
  _CRTIMP व्योम *__cdecl _memccpy(व्योम *_Dst,स्थिर व्योम *_Src,पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CONST_RETURN व्योम *__cdecl स_प्रथम(स्थिर व्योम *_Buf ,पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _memicmp(स्थिर व्योम *_Buf1,स्थिर व्योम *_Buf2,माप_प्रकार आकार_4);
  _CRTIMP पूर्णांक __cdecl _memicmp_l(स्थिर व्योम *_Buf1,स्थिर व्योम *_Buf2,माप_प्रकार आकार_4,_locale_t _Locale);
  पूर्णांक __cdecl स_भेद(स्थिर व्योम *_Buf1,स्थिर व्योम *_Buf2,माप_प्रकार आकार_4);
  व्योम *__cdecl स_नकल(व्योम *_Dst,स्थिर व्योम *_Src,माप_प्रकार आकार_4);
  व्योम *__cdecl स_रखो(व्योम *_Dst,पूर्णांक _Val,माप_प्रकार आकार_4);

#अगर_अघोषित	NO_OLDNAMES
  व्योम *__cdecl memccpy(व्योम *_Dst,स्थिर व्योम *_Src,पूर्णांक _Val,माप_प्रकार आकार_4);
  पूर्णांक __cdecl memicmp(स्थिर व्योम *_Buf1,स्थिर व्योम *_Buf2,माप_प्रकार आकार_4);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
