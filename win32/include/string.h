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
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,माप_प्रकार Max_गिनती);
  _CONST_RETURN शून्य *__cdecl स_प्रथम(ध्रुव शून्य *_Buf ,पूर्णाङ्क _Val,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,माप_प्रकार _Size);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp_l(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,माप_प्रकार _Size,_locale_t _Locale);
  पूर्णाङ्क __cdecl स_भेद(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,माप_प्रकार _Size);
  शून्य *__cdecl स_नकल(शून्य *_Dst,ध्रुव शून्य *_Src,माप_प्रकार _Size);
  शून्य *__cdecl स_रखो(शून्य *_Dst,पूर्णाङ्क _Val,माप_प्रकार _Size);
#ifndef	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,माप_प्रकार _Size);
  पूर्णाङ्क __cdecl memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,माप_प्रकार _Size);
#endif
#endif
  वर्ण *__cdecl _strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl म_नकल(वर्ण *_Dest,ध्रुव वर्ण *_Source);
  वर्ण *__cdecl म_जोड़ो(वर्ण *_Dest,ध्रुव वर्ण *_Source);
  पूर्णाङ्क __cdecl म_भेद(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  माप_प्रकार __cdecl म_माप(ध्रुव वर्ण *_Str);
#यदि 0
  माप_प्रकार __cdecl strnlen(ध्रुव वर्ण *_Str,माप_प्रकार Max_गिनती);
#endif
  शून्य *__cdecl स_हटाओ(शून्य *_Dst,ध्रुव शून्य *_Src,माप_प्रकार _Size);
  _CRTIMP वर्ण *__cdecl _strdup(ध्रुव वर्ण *_Src);
  _CONST_RETURN वर्ण *__cdecl म_अक्षर(ध्रुव वर्ण *_Str,पूर्णाङ्क _Val);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcmpi(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  पूर्णाङ्क __cdecl strcoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll (ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll (ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  माप_प्रकार __cdecl म_खोज(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CRTIMP वर्ण *__cdecl _strerror(ध्रुव वर्ण *Err_संदेश);
  वर्ण *__cdecl म_त्रुटि(पूर्णाङ्क);
  _CRTIMP वर्ण *__cdecl _strlwr(वर्ण *_String);
  वर्ण *strlwr_l(वर्ण *_String,_locale_t _Locale);
  वर्ण *__cdecl म_जोड़न(वर्ण *_Dest,ध्रुव वर्ण *_Source,माप_प्रकार गिनती_5);
  पूर्णाङ्क __cdecl म_भेदन(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  वर्ण *म_नकलन(वर्ण *_Dest,ध्रुव वर्ण *_Source,माप_प्रकार गिनती_5);
  _CRTIMP वर्ण *__cdecl _strnset(वर्ण *_Str,पूर्णाङ्क _Val,माप_प्रकार Max_गिनती);
  _CONST_RETURN वर्ण *__cdecl strpbrk(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl म_खोजप(ध्रुव वर्ण *_Str,पूर्णाङ्क _Ch);
  _CRTIMP वर्ण *__cdecl _strrev(वर्ण *_Str);
  माप_प्रकार __cdecl म_अखोज(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl म_माला(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_SubStr);
  वर्ण *__cdecl म_मोहर(वर्ण *_Str,ध्रुव वर्ण *_Delim);
  _CRTIMP वर्ण *__cdecl _strupr(वर्ण *_String);
  _CRTIMP वर्ण *_strupr_l(वर्ण *_String,_locale_t _Locale);
  माप_प्रकार __cdecl strxfrm(वर्ण *_Dst,ध्रुव वर्ण *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _strxfrm_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  वर्ण *__cdecl strdup(ध्रुव वर्ण *_Src);
  पूर्णाङ्क __cdecl strcmpi(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  पूर्णाङ्क __cdecl stricmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  वर्ण *__cdecl strlwr(वर्ण *_Str);
  पूर्णाङ्क __cdecl strnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str,माप_प्रकार Max_गिनती);
  __CRT_INLINE पूर्णाङ्क __cdecl strncasecmp (ध्रुव वर्ण *__sz1, ध्रुव वर्ण *__sz2, माप_प्रकार __sizeMaxCompare) { प्रत्यागम _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE पूर्णाङ्क __cdecl strcasecmp (ध्रुव वर्ण *__sz1, ध्रुव वर्ण *__sz2) { प्रत्यागम _stricmp (__sz1, __sz2); }
  वर्ण *__cdecl strnset(वर्ण *_Str,पूर्णाङ्क _Val,माप_प्रकार Max_गिनती);
  वर्ण *__cdecl strrev(वर्ण *_Str);
  वर्ण *__cdecl strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl strupr(वर्ण *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsdup(ध्रुव ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcscat(ब_अक्षर_प्रकार *_Dest,ध्रुव ब_अक्षर_प्रकार *_Source);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcschr(ध्रुव ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  पूर्णाङ्क __cdecl wcscmp(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2);
  ब_अक्षर_प्रकार *__cdecl wcscpy(ब_अक्षर_प्रकार *_Dest,ध्रुव ब_अक्षर_प्रकार *_Source);
  माप_प्रकार __cdecl wcscspn(ध्रुव ब_अक्षर_प्रकार *_Str,ध्रुव ब_अक्षर_प्रकार *_Control);
  माप_प्रकार __cdecl wcslen(ध्रुव ब_अक्षर_प्रकार *_Str);
  माप_प्रकार __cdecl wcsnlen(ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *wcsncat(ब_अक्षर_प्रकार *_Dest,ध्रुव ब_अक्षर_प्रकार *_Source,माप_प्रकार गिनती_5);
  पूर्णाङ्क __cdecl wcsncmp(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *wcsncpy(ब_अक्षर_प्रकार *_Dest,ध्रुव ब_अक्षर_प्रकार *_Source,माप_प्रकार गिनती_5);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcspbrk(ध्रुव ब_अक्षर_प्रकार *_Str,ध्रुव ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsrchr(ध्रुव ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Ch);
  माप_प्रकार __cdecl wcsspn(ध्रुव ब_अक्षर_प्रकार *_Str,ध्रुव ब_अक्षर_प्रकार *_Control);
  _CONST_RETURN ब_अक्षर_प्रकार *__cdecl wcsstr(ध्रुव ब_अक्षर_प्रकार *_Str,ध्रुव ब_अक्षर_प्रकार *_SubStr);
  ब_अक्षर_प्रकार *__cdecl wcstok(ब_अक्षर_प्रकार *_Str,ध्रुव ब_अक्षर_प्रकार *_Delim);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcserror(पूर्णाङ्क Err_अंक);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl __wcserror(ध्रुव ब_अक्षर_प्रकार *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsrev(ब_अक्षर_प्रकार *_Str);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcslwr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcslwr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wcsupr(ब_अक्षर_प्रकार *_String);
  _CRTIMP ब_अक्षर_प्रकार *_wcsupr_l(ब_अक्षर_प्रकार *_String,_locale_t _Locale);
  माप_प्रकार __cdecl wcsxfrm(ब_अक्षर_प्रकार *_Dst,ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती);
  _CRTIMP माप_प्रकार __cdecl _wcsxfrm_l(ब_अक्षर_प्रकार *_Dst,ध्रुव ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  ब_अक्षर_प्रकार *__cdecl wcsdup(ध्रुव ब_अक्षर_प्रकार *_Str);
#define wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsnset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val,माप_प्रकार Max_गिनती);
  ब_अक्षर_प्रकार *__cdecl wcsrev(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsset(ब_अक्षर_प्रकार *_Str,ब_अक्षर_प्रकार _Val);
  ब_अक्षर_प्रकार *__cdecl wcslwr(ब_अक्षर_प्रकार *_Str);
  ब_अक्षर_प्रकार *__cdecl wcsupr(ब_अक्षर_प्रकार *_Str);
  पूर्णाङ्क __cdecl wcsicoll(ध्रुव ब_अक्षर_प्रकार *_Str1,ध्रुव ब_अक्षर_प्रकार *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#अन्तर्भाव <sec_api/string_s.h>
#endif
