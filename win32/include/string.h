/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_STRING
#परिभाषय _INC_STRING

#अन्तर्भाव <_mingw.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _NLSCMP_DEFINED
#परिभाषय _NLSCMP_DEFINED
#परिभाषय _NLSCMPERROR 2147483647
#यदि_अन्तः

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय _WConst_return _CONST_RETURN

#यदि_अपरिभाषितम् CRT_स्मृतिः_DEFINED
#परिभाषय CRT_स्मृतिः_DEFINED
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CONST_RETURN शून्य *__cdecl memchr(ध्रुव शून्य *_Buf ,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp_l(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4,_locale_t _Locale);
  पूर्णाङ्क __cdecl memcmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4);
  शून्य *__cdecl स्मृतिं_प्रतिलिख(शून्य *_Dst,ध्रुव शून्य *_Src,आकार_t आकार_4);
  शून्य *__cdecl स्मृतिं_पूरय(शून्य *_Dst,पूर्णाङ्क _Val,आकार_t आकार_4);
#यदि_अपरिभाषितम्	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,आकार_t आकार_4);
  पूर्णाङ्क __cdecl memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4);
#यदि_अन्तः
#यदि_अन्तः
  वर्ण *__cdecl _strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl वाक्यं_प्रतिलिख(वर्ण *_Dest,ध्रुव वर्ण *_Source);
  वर्ण *__cdecl वाक्यं_योजय(वर्ण *_Dest,ध्रुव वर्ण *_Source);
  पूर्णाङ्क __cdecl वाक्यं_तुलय(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  आकार_t __cdecl वाक्यदैर्घ्यम्(ध्रुव वर्ण *_Str);
#यदि 0
  आकार_t __cdecl strnlen(ध्रुव वर्ण *_Str,आकार_t Max_गणनम्);
#यदि_अन्तः
  शून्य *__cdecl memmove(शून्य *_Dst,ध्रुव शून्य *_Src,आकार_t आकार_4);
  _CRTIMP वर्ण *__cdecl _strdup(ध्रुव वर्ण *_Src);
  _CONST_RETURN वर्ण *__cdecl strchr(ध्रुव वर्ण *_Str,पूर्णाङ्क _Val);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcmpi(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  पूर्णाङ्क __cdecl strcoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll (ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll (ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  आकार_t __cdecl strcspn(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CRTIMP वर्ण *__cdecl _strerror(ध्रुव वर्ण *Err_सन्देशः);
  वर्ण *__cdecl strerror(पूर्णाङ्क);
  _CRTIMP वर्ण *__cdecl _strlwr(वर्ण *_String);
  वर्ण *strlwr_l(वर्ण *_String,_locale_t _Locale);
  वर्ण *__cdecl strncat(वर्ण *_Dest,ध्रुव वर्ण *_Source,आकार_t गणनम्_5);
  पूर्णाङ्क __cdecl वाक्ये_तुलय(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  वर्ण *strncpy(वर्ण *_Dest,ध्रुव वर्ण *_Source,आकार_t गणनम्_5);
  _CRTIMP वर्ण *__cdecl _strnset(वर्ण *_Str,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CONST_RETURN वर्ण *__cdecl strpbrk(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl strrchr(ध्रुव वर्ण *_Str,पूर्णाङ्क _Ch);
  _CRTIMP वर्ण *__cdecl _strrev(वर्ण *_Str);
  आकार_t __cdecl strspn(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl वाक्ये_अन्विष(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_SubStr);
  वर्ण *__cdecl strtok(वर्ण *_Str,ध्रुव वर्ण *_Delim);
  _CRTIMP वर्ण *__cdecl _strupr(वर्ण *_String);
  _CRTIMP वर्ण *_strupr_l(वर्ण *_String,_locale_t _Locale);
  आकार_t __cdecl strxfrm(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _strxfrm_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,_locale_t _Locale);

#यदि_अपरिभाषितम्	NO_OLDNAMES
  वर्ण *__cdecl strdup(ध्रुव वर्ण *_Src);
  पूर्णाङ्क __cdecl strcmpi(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  पूर्णाङ्क __cdecl stricmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  वर्ण *__cdecl strlwr(वर्ण *_Str);
  पूर्णाङ्क __cdecl strnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str,आकार_t Max_गणनम्);
  __CRT_INLINE पूर्णाङ्क __cdecl strncasecmp (ध्रुव वर्ण *__sz1, ध्रुव वर्ण *__sz2, आकार_t __sizeMaxCompare) { प्रत्यागम _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE पूर्णाङ्क __cdecl strcasecmp (ध्रुव वर्ण *__sz1, ध्रुव वर्ण *__sz2) { प्रत्यागम _stricmp (__sz1, __sz2); }
  वर्ण *__cdecl strnset(वर्ण *_Str,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  वर्ण *__cdecl strrev(वर्ण *_Str);
  वर्ण *__cdecl strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl strupr(वर्ण *_Str);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTRING_DEFINED
#परिभाषय _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ध्रुव wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  पूर्णाङ्क __cdecl wcscmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  आकार_t __cdecl wcscspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  आकार_t __cdecl wcslen(ध्रुव wchar_t *_Str);
  आकार_t __cdecl wcsnlen(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्);
  wchar_t *wcsncat(wchar_t *_Dest,ध्रुव wchar_t *_Source,आकार_t गणनम्_5);
  पूर्णाङ्क __cdecl wcsncmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  wchar_t *wcsncpy(wchar_t *_Dest,ध्रुव wchar_t *_Source,आकार_t गणनम्_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  आकार_t __cdecl wcsspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ध्रुव wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(पूर्णाङ्क Err_अङ्कः);
  _CRTIMP wchar_t *__cdecl __wcserror(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,आकार_t Max_गणनम्);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  आकार_t __cdecl wcsxfrm(wchar_t *_Dst,ध्रुव wchar_t *_Src,आकार_t Max_गणनम्);
  _CRTIMP आकार_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्,_locale_t _Locale);

#यदि_अपरिभाषितम्	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ध्रुव wchar_t *_Str);
#परिभाषय wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,आकार_t Max_गणनम्);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,आकार_t Max_गणनम्);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  पूर्णाङ्क __cdecl wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#अन्तर्भाव <sec_api/string_s.h>
#यदि_अन्तः
