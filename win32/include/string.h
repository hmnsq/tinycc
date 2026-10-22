/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_STRING
#घोषणा _INC_STRING

#समावेश <_mingw.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _NLSCMP_DEFINED
#घोषणा _NLSCMP_DEFINED
#घोषणा _NLSCMPERROR 2147483647
#पूर्ण_अगर

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
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
  अक्षर *__cdecl _strset(अक्षर *_Str,पूर्णांक _Val);
  अक्षर *__cdecl म_नकल(अक्षर *_Dest,स्थिर अक्षर *_Source);
  अक्षर *__cdecl म_जोड़ो(अक्षर *_Dest,स्थिर अक्षर *_Source);
  पूर्णांक __cdecl म_भेद(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  माप_प्रकार __cdecl म_माप(स्थिर अक्षर *_Str);
#अगर 0
  माप_प्रकार __cdecl strnlen(स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती);
#पूर्ण_अगर
  व्योम *__cdecl स_हटाओ(व्योम *_Dst,स्थिर व्योम *_Src,माप_प्रकार आकार_4);
  _CRTIMP अक्षर *__cdecl _strdup(स्थिर अक्षर *_Src);
  _CONST_RETURN अक्षर *__cdecl म_अक्षर(स्थिर अक्षर *_Str,पूर्णांक _Val);
  _CRTIMP पूर्णांक __cdecl _stricmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _strcmpi(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _stricmp_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,_locale_t _Locale);
  पूर्णांक __cdecl strcoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _strcoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _stricoll(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  _CRTIMP पूर्णांक __cdecl _stricoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _strncoll (स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _strncoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _strnicoll (स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _strnicoll_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  माप_प्रकार __cdecl म_खोज(स्थिर अक्षर *_Str,स्थिर अक्षर *_Control);
  _CRTIMP अक्षर *__cdecl _strerror(स्थिर अक्षर *Err_संदेश);
  अक्षर *__cdecl म_त्रुटि(पूर्णांक);
  _CRTIMP अक्षर *__cdecl _strlwr(अक्षर *_String);
  अक्षर *strlwr_l(अक्षर *_String,_locale_t _Locale);
  अक्षर *__cdecl म_जोड़न(अक्षर *_Dest,स्थिर अक्षर *_Source,माप_प्रकार गिनती_5);
  पूर्णांक __cdecl म_भेदन(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _strnicmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _strnicmp_l(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  अक्षर *म_नकलन(अक्षर *_Dest,स्थिर अक्षर *_Source,माप_प्रकार गिनती_5);
  _CRTIMP अक्षर *__cdecl _strnset(अक्षर *_Str,पूर्णांक _Val,माप_प्रकार Max_गिनती);
  _CONST_RETURN अक्षर *__cdecl strpbrk(स्थिर अक्षर *_Str,स्थिर अक्षर *_Control);
  _CONST_RETURN अक्षर *__cdecl म_खोजप(स्थिर अक्षर *_Str,पूर्णांक _Ch);
  _CRTIMP अक्षर *__cdecl _strrev(अक्षर *_Str);
  माप_प्रकार __cdecl म_अखोज(स्थिर अक्षर *_Str,स्थिर अक्षर *_Control);
  _CONST_RETURN अक्षर *__cdecl म_माला(स्थिर अक्षर *_Str,स्थिर अक्षर *_SubStr);
  अक्षर *__cdecl म_मोहर(अक्षर *_Str,स्थिर अक्षर *_Delim);
  _CRTIMP अक्षर *__cdecl _strupr(अक्षर *_String);
  _CRTIMP अक्षर *_strupr_l(अक्षर *_String,_locale_t _Locale);
  माप_प्रकार __cdecl strxfrm(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _strxfrm_l(अक्षर *_Dst,स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);

#अगर_अघोषित	NO_OLDNAMES
  अक्षर *__cdecl strdup(स्थिर अक्षर *_Src);
  पूर्णांक __cdecl strcmpi(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  पूर्णांक __cdecl stricmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str2);
  अक्षर *__cdecl strlwr(अक्षर *_Str);
  पूर्णांक __cdecl strnicmp(स्थिर अक्षर *_Str1,स्थिर अक्षर *_Str,माप_प्रकार Max_गिनती);
  __CRT_INLINE पूर्णांक __cdecl strncasecmp (स्थिर अक्षर *__sz1, स्थिर अक्षर *__sz2, माप_प्रकार __sizeMaxCompare) { वापस _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE पूर्णांक __cdecl strcasecmp (स्थिर अक्षर *__sz1, स्थिर अक्षर *__sz2) { वापस _stricmp (__sz1, __sz2); }
  अक्षर *__cdecl strnset(अक्षर *_Str,पूर्णांक _Val,माप_प्रकार Max_गिनती);
  अक्षर *__cdecl strrev(अक्षर *_Str);
  अक्षर *__cdecl strset(अक्षर *_Str,पूर्णांक _Val);
  अक्षर *__cdecl strupr(अक्षर *_Str);
#पूर्ण_अगर

#अगर_अघोषित _WSTRING_DEFINED
#घोषणा _WSTRING_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsdup(स्थिर ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcscat(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcschr(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  पूर्णांक __cdecl wcscmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  ब_अक्षर_प्रकार *__cdecl wcscpy(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source);
  माप_प्रकार __cdecl wcscspn(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Control);
  माप_प्रकार __cdecl wcslen(स्थिर ब_अक्षर_प्रकार *_Str);
  माप_प्रकार __cdecl wcsnlen(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *wcsncat(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source,माप_प्रकार गिनती_5);
  पूर्णांक __cdecl wcsncmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *wcsncpy(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Source,माप_प्रकार गिनती_5);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcspbrk(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsrchr(स्थिर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  माप_प्रकार __cdecl wcsspn(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsstr(स्थिर ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_SubStr);
  ब_अक्षर_प्रकार *__cdecl wcstok(ब_अक्षर_प्रकार *_Str,स्थिर ब_अक्षर_प्रकार *_Delim);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcserror(पूर्णांक Err_अंक);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl __wcserror(स्थिर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णांक __cdecl _wcsicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णांक __cdecl _wcsicmp_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsnicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _wcsnicmp_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsrev(ब_अक्षर_प्रकार *_Str);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcslwr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcslwr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsupr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcsupr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  माप_प्रकार __cdecl wcsxfrm(ब_अक्षर_प्रकार *_Dst,स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _wcsxfrm_l(ब_अक्षर_प्रकार *_Dst,स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  पूर्णांक __cdecl wcscoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णांक __cdecl _wcscoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsicoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णांक __cdecl _wcsicoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsncoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _wcsncoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _wcsnicoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णांक __cdecl _wcsnicoll_l(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);

#अगर_अघोषित	NO_OLDNAMES
  ब_अक्षर_प्रकार *__cdecl wcsdup(स्थिर ब_अक्षर_प्रकार *_Str);
#घोषणा wcswcs wcsstr
  पूर्णांक __cdecl wcsicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
  पूर्णांक __cdecl wcsnicmp(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsrev(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  ब_अक्षर_प्रकार *__cdecl wcslwr(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsupr(ब_अक्षर_प्रकार *_Str);
  पूर्णांक __cdecl wcsicoll(स्थिर ब_अक्षर_प्रकार *_Str1,स्थिर ब_अक्षर_प्रकार *_Str2);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#समावेश <sec_api/string_s.h>
#पूर्ण_अगर
