/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _TIME_H__S
#define _TIME_H__S

#अन्तर्भाव <time.h>

#जर defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _ctime32_s(अक्षर *_Buf,माप_प्रकार _SizeInBytes,स्थिरांक __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(संरचना पंचांग *_Tm,स्थिरांक __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(संरचना पंचांग *_Tm,स्थिरांक __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(अक्षर *_Buf,माप_प्रकार _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(अक्षर *_Buf ,माप_प्रकार _SizeInBytes);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(अक्षर *_Buf,माप_प्रकार _SizeInBytes,स्थिरांक __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(संरचना पंचांग *_Tm,स्थिरांक __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(संरचना पंचांग *_Tm,स्थिरांक __time64_t *_Time);
#endif

#ifndef _WTIME_S_DEFINED
#define _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्द,स्थिरांक संरचना पंचांग *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्द,स्थिरांक __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्द);
  _CRTIMP errno_t __cdecl _wstrtime_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्द);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्द,स्थिरांक __time64_t *_Time);
#endif

#जर !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#define _INC_WTIME_S_INL
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्द,स्थिरांक समय_प्रकार *_Time) { परत _wctime32_s(_Buffer,Size_In_शब्द,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl _wctime_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्द,स्थिरांक समय_प्रकार *_Time) { परत _wctime64_s(_Buffer,Size_In_शब्द,_Time); }
#endif
#endif
#endif

#ifndef RC_INVOKED
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(संरचना पंचांग *_Tm,स्थिरांक समय_प्रकार *_Time) { परत _localtime32_s(_Tm,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl localtime_s(संरचना पंचांग *_Tm,स्थिरांक समय_प्रकार *_Time) { परत _localtime64_s(_Tm,_Time); }
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
