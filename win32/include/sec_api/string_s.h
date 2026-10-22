/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_STRING_S
#घोषणा _INC_STRING_S

#समावेश <string.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _strset_s(अक्षर *_Dst,माप_प्रकार Dst_आकार,पूर्णांक मूल्य_2);
  _CRTIMP errno_t __cdecl _strerror_s(अक्षर *_Buf,माप_प्रकार आकार_In_Bytes,स्थिर अक्षर *Err_संदेश);
  _CRTIMP errno_t __cdecl _strlwr_s(अक्षर *_Str,माप_प्रकार आकार_4);
  _CRTIMP errno_t __cdecl _strlwr_s_l(अक्षर *_Str,माप_प्रकार आकार_4,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(अक्षर *_Str,माप_प्रकार आकार_4,पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _strupr_s(अक्षर *_Str,माप_प्रकार आकार_4);
  _CRTIMP errno_t __cdecl _strupr_s_l(अक्षर *_Str,माप_प्रकार आकार_4,_locale_t _Locale);
#अगर_अघोषित _WSTRING_S_DEFINED
#घोषणा _WSTRING_S_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl wcstok_s(ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Delim,ब_अक्षर_प्रकार **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(ब_अक्षर_प्रकार *_Buf,माप_प्रकार आकार_In_शब्दगण,पूर्णांक Err_अंक);
  _CRTIMP errno_t __cdecl __wcserror_s(ब_अक्षर_प्रकार *बफर_2,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *Err_संदेश);
  _CRTIMP errno_t __cdecl _wcsnset_s(ब_अक्षर_प्रकार *_Dst,माप_प्रकार Dst_आकार_In_शब्दगण,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _wcsset_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण,ब_अक्षर_प्रकार _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_In_शब्दगण,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_4);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(ब_अक्षर_प्रकार *_Str,माप_प्रकार आकार_4,_locale_t _Locale);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
