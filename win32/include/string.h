/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#अन्तर्भाव <_mingw.h>

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अन्यथा
#define रिक्त ((शून्य *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,अचर शून्य *_Src,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  _CONST_RETURN शून्य *__cdecl स_प्रथम(अचर शून्य *_Buf ,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp_l(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size,_locale_t _Locale);
  पूर्णाङ्क __cdecl स_भेद(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size);
  शून्य *__cdecl स_नकल(शून्य *_Dst,अचर शून्य *_Src,माप_प्रकार _Size);
  शून्य *__cdecl स_रखो(शून्य *_Dst,पूर्णाङ्क _Val,माप_प्रकार _Size);
#ifndef	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,अचर शून्य *_Src,पूर्णाङ्क _Val,माप_प्रकार _Size);
  पूर्णाङ्क __cdecl memicmp(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size);
#endif
#endif
  वर्ण *__cdecl _strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl म_नकल(वर्ण *_Dest,अचर वर्ण *_Source);
  वर्ण *__cdecl म_जोड़ो(वर्ण *_Dest,अचर वर्ण *_Source);
  पूर्णाङ्क __cdecl म_भेद(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  माप_प्रकार __cdecl म_माप(अचर वर्ण *_Str);
#यदि 0
  माप_प्रकार __cdecl strnlen(अचर वर्ण *_Str,माप_प्रकार Max_गन्ती);
#endif
  शून्य *__cdecl स_हटाओ(शून्य *_Dst,अचर शून्य *_Src,माप_प्रकार _Size);
  _CRTIMP वर्ण *__cdecl _strdup(अचर वर्ण *_Src);
  _CONST_RETURN वर्ण *__cdecl म_अक्षर(अचर वर्ण *_Str,पूर्णाङ्क _Val);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcmpi(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp_l(अचर वर्ण *_Str1,अचर वर्ण *_Str2,_locale_t _Locale);
  पूर्णाङ्क __cdecl strcoll(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcoll_l(अचर वर्ण *_Str1,अचर वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll_l(अचर वर्ण *_Str1,अचर वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll (अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll_l(अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll (अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll_l(अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  माप_प्रकार __cdecl म_खोज(अचर वर्ण *_Str,अचर वर्ण *_Control);
  _CRTIMP वर्ण *__cdecl _strerror(अचर वर्ण *Err_सन्देश);
  वर्ण *__cdecl म_त्रुटि(पूर्णाङ्क);
  _CRTIMP वर्ण *__cdecl _strlwr(वर्ण *_String);
  वर्ण *strlwr_l(वर्ण *_String,_locale_t _Locale);
  वर्ण *__cdecl म_जोड़न(वर्ण *_Dest,अचर वर्ण *_Source,माप_प्रकार गन्ती_5);
  पूर्णाङ्क __cdecl म_भेदन(अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp(अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp_l(अचर वर्ण *_Str1,अचर वर्ण *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  वर्ण *म_नकलन(वर्ण *_Dest,अचर वर्ण *_Source,माप_प्रकार गन्ती_5);
  _CRTIMP वर्ण *__cdecl _strnset(वर्ण *_Str,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  _CONST_RETURN वर्ण *__cdecl strpbrk(अचर वर्ण *_Str,अचर वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl म_खोजप(अचर वर्ण *_Str,पूर्णाङ्क _Ch);
  _CRTIMP वर्ण *__cdecl _strrev(वर्ण *_Str);
  माप_प्रकार __cdecl म_अखोज(अचर वर्ण *_Str,अचर वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl म_माला(अचर वर्ण *_Str,अचर वर्ण *_SubStr);
  वर्ण *__cdecl म_मोहर(वर्ण *_Str,अचर वर्ण *_Delim);
  _CRTIMP वर्ण *__cdecl _strupr(वर्ण *_String);
  _CRTIMP वर्ण *_strupr_l(वर्ण *_String,_locale_t _Locale);
  माप_प्रकार __cdecl strxfrm(वर्ण *_Dst,अचर वर्ण *_Src,माप_प्रकार Max_गन्ती);
  _CRTIMP माप_प्रकार __cdecl _strxfrm_l(वर्ण *_Dst,अचर वर्ण *_Src,माप_प्रकार Max_गन्ती,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  वर्ण *__cdecl strdup(अचर वर्ण *_Src);
  पूर्णाङ्क __cdecl strcmpi(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  पूर्णाङ्क __cdecl stricmp(अचर वर्ण *_Str1,अचर वर्ण *_Str2);
  वर्ण *__cdecl strlwr(वर्ण *_Str);
  पूर्णाङ्क __cdecl strnicmp(अचर वर्ण *_Str1,अचर वर्ण *_Str,माप_प्रकार Max_गन्ती);
  __CRT_INLINE पूर्णाङ्क __cdecl strncasecmp (अचर वर्ण *__sz1, अचर वर्ण *__sz2, माप_प्रकार __sizeMaxCompare) { फर्काऊ _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE पूर्णाङ्क __cdecl strcasecmp (अचर वर्ण *__sz1, अचर वर्ण *__sz2) { फर्काऊ _stricmp (__sz1, __sz2); }
  वर्ण *__cdecl strnset(वर्ण *_Str,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  वर्ण *__cdecl strrev(वर्ण *_Str);
  वर्ण *__cdecl strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl strupr(वर्ण *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsdup(अचर ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcscat(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcschr(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  पूर्णाङ्क __cdecl wcscmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  ब_अक्षर_प्रकार *__cdecl wcscpy(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source);
  माप_प्रकार __cdecl wcscspn(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Control);
  माप_प्रकार __cdecl wcslen(अचर ब_अक्षर_प्रकार *_Str);
  माप_प्रकार __cdecl wcsnlen(अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *wcsncat(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source,माप_प्रकार गन्ती_5);
  पूर्णाङ्क __cdecl wcsncmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *wcsncpy(ब_अक्षर_प्रकार *_Dest,अचर ब_अक्षर_प्रकार *_Source,माप_प्रकार गन्ती_5);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcspbrk(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsrchr(अचर ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  माप_प्रकार __cdecl wcsspn(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsstr(अचर ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_SubStr);
  ब_अक्षर_प्रकार *__cdecl wcstok(ब_अक्षर_प्रकार *_Str,अचर ब_अक्षर_प्रकार *_Delim);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcserror(पूर्णाङ्क Err_अङ्क);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl __wcserror(अचर ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गन्ती);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsrev(ब_अक्षर_प्रकार *_Str);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcslwr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcslwr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsupr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcsupr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  माप_प्रकार __cdecl wcsxfrm(ब_अक्षर_प्रकार *_Dst,अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती);
  _CRTIMP माप_प्रकार __cdecl _wcsxfrm_l(ब_अक्षर_प्रकार *_Dst,अचर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  ब_अक्षर_प्रकार *__cdecl wcsdup(अचर ब_अक्षर_प्रकार *_Str);
#define wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *__cdecl wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गन्ती);
  ब_अक्षर_प्रकार *__cdecl wcsrev(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  ब_अक्षर_प्रकार *__cdecl wcslwr(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsupr(ब_अक्षर_प्रकार *_Str);
  पूर्णाङ्क __cdecl wcsicoll(अचर ब_अक्षर_प्रकार *_Str1,अचर ब_अक्षर_प्रकार *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#अन्तर्भाव <sec_api/string_s.h>
#endif
