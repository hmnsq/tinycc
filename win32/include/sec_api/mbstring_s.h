/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_MBSTRING_S
#घोषणा _INC_MBSTRING_S

#समावेश <mbstring.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _MBSTRING_S_DEFINED
#घोषणा _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(अचिन्हित अक्षर *_Str,माप_प्रकार आकार_In_Bytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(अचिन्हित अक्षर *_Str,माप_प्रकार आकार_In_Bytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,अचिन्हित पूर्णांक _Ch,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,अचिन्हित पूर्णांक _Ch,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,स्थिर अचिन्हित अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,अचिन्हित पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,अचिन्हित पूर्णांक _Val,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,अचिन्हित पूर्णांक _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,अचिन्हित पूर्णांक _Val,_locale_t _Locale);
  _CRTIMP अचिन्हित अक्षर *__cdecl _mbstok_s(अचिन्हित अक्षर *_Str,स्थिर अचिन्हित अक्षर *_Delim,अचिन्हित अक्षर **_Context);
  _CRTIMP अचिन्हित अक्षर *__cdecl _mbstok_s_l(अचिन्हित अक्षर *_Str,स्थिर अचिन्हित अक्षर *_Delim,अचिन्हित अक्षर **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(अचिन्हित अक्षर *_Str,माप_प्रकार आकार_In_Bytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(अचिन्हित अक्षर *_Str,माप_प्रकार आकार_In_Bytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,पूर्णांक *_PCopied,स्थिर अचिन्हित अक्षर *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(अचिन्हित अक्षर *_Dst,माप_प्रकार Dst_आकार_In_Bytes,पूर्णांक *_PCopied,स्थिर अचिन्हित अक्षर *_Src,_locale_t _Locale);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
