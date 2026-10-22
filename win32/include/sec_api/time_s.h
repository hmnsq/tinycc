/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _TIME_H__S
#घोषणा _TIME_H__S

#समावेश <time.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _ctime32_s(अक्षर *_Buf,माप_प्रकार आकार_In_Bytes,स्थिर __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(काष्ठा पंचांग *_Tm,स्थिर __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(काष्ठा पंचांग *_Tm,स्थिर __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(अक्षर *_Buf,माप_प्रकार आकार_In_Bytes);
  _CRTIMP errno_t __cdecl _strtime_s(अक्षर *_Buf ,माप_प्रकार आकार_In_Bytes);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(अक्षर *_Buf,माप_प्रकार आकार_In_Bytes,स्थिर __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(काष्ठा पंचांग *_Tm,स्थिर __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(काष्ठा पंचांग *_Tm,स्थिर __time64_t *_Time);
#पूर्ण_अगर

#अगर_अघोषित _WTIME_S_DEFINED
#घोषणा _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर काष्ठा पंचांग *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wstrtime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,स्थिर __time64_t *_Time);
#पूर्ण_अगर

#अगर !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#घोषणा _INC_WTIME_S_INL
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,स्थिर समय_प्रकार *_Time) { वापस _wctime32_s(बफर_2,आकार_In_शब्दगण,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,स्थिर समय_प्रकार *_Time) { वापस _wctime64_s(बफर_2,आकार_In_शब्दगण,_Time); }
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित RC_INVOKED
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(काष्ठा पंचांग *_Tm,स्थिर समय_प्रकार *_Time) { वापस _localtime32_s(_Tm,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl localtime_s(काष्ठा पंचांग *_Tm,स्थिर समय_प्रकार *_Time) { वापस _localtime64_s(_Tm,_Time); }
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
