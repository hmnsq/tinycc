/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#अन्तर्भाव <string.h>

#जर defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(अक्षर *_Dst,माप_प्रकार _DstSize,पूर्णांक मूल्य_2);
  _CRTIMP errno_t __cdecl _strerror_s(अक्षर *_Buf,माप_प्रकार _SizeInBytes,स्थिरांक अक्षर *Err_संदेश);
  _CRTIMP errno_t __cdecl _strlwr_s(अक्षर *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(अक्षर *_Str,माप_प्रकार _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(अक्षर *_Str,माप_प्रकार _Size,पूर्णांक _Val,माप_प्रकार Max_मोजणी);
  _CRTIMP errno_t __cdecl _strupr_s(अक्षर *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(अक्षर *_Str,माप_प्रकार _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl wcstok_s(ब_अक्षर_प्रकार *_Str,स्थिरांक ब_अक्षर_प्रकार *_Delim,ब_अक्षर_प्रकार **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्द,पूर्णांक Err_अंक);
  _CRTIMP errno_t __cdecl __wcserror_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *Err_संदेश);
  _CRTIMP errno_t __cdecl _wcsnset_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Dst_Size_In_शब्द,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_मोजणी);
  _CRTIMP errno_t __cdecl _wcsset_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्द,ब_अक्षर_प्रकार _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्द);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्द,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
