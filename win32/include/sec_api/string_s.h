/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING_S
#define _INC_STRING_S

#अन्तर्भाव <string.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _strset_s(वर्ण *_Dst,माप_प्रकार _DstSize,पूर्णाङ्क मान_2);
  _CRTIMP errno_t __cdecl _strerror_s(वर्ण *_Buf,माप_प्रकार _SizeInBytes,अचर वर्ण *Err_सन्देश);
  _CRTIMP errno_t __cdecl _strlwr_s(वर्ण *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(वर्ण *_Str,माप_प्रकार _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(वर्ण *_Str,माप_प्रकार _Size,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  _CRTIMP errno_t __cdecl _strupr_s(वर्ण *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(वर्ण *_Str,माप_प्रकार _Size,_locale_t _Locale);
#ifndef _WSTRING_S_DEFINED
#define _WSTRING_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl wcstok_s(ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Delim,ब_अक्षर_प्रकार **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार Size_In_शब्दहरू,पूर्णाङ्क Err_अङ्क);
  _CRTIMP errno_t __cdecl __wcserror_s(ब_अक्षर_प्रकार *_Buffer,माप_प्रकार Size_In_शब्दहरू,अचर ब_अक्षर_प्रकार *Err_सन्देश);
  _CRTIMP errno_t __cdecl _wcsnset_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Dst_Size_In_शब्दहरू,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गन्ती);
  _CRTIMP errno_t __cdecl _wcsset_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दहरू,ब_अक्षर_प्रकार _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दहरू);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार Size_In_शब्दहरू,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार _Size,_locale_t _Locale);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
