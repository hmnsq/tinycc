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
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,size_t Max_मोजणी);
  _CONST_RETURN शून्य *__cdecl memchr(ध्रुव शून्य *_Buf ,पूर्णाङ्क _Val,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,size_t _Size);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp_l(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,size_t _Size,_locale_t _Locale);
  पूर्णाङ्क __cdecl memcmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,size_t _Size);
  शून्य *__cdecl memcpy(शून्य *_Dst,ध्रुव शून्य *_Src,size_t _Size);
  शून्य *__cdecl memset(शून्य *_Dst,पूर्णाङ्क _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,size_t _Size);
  पूर्णाङ्क __cdecl memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,size_t _Size);
#endif
#endif
  वर्ण *__cdecl _strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl strcpy(वर्ण *_Dest,ध्रुव वर्ण *_Source);
  वर्ण *__cdecl strcat(वर्ण *_Dest,ध्रुव वर्ण *_Source);
  पूर्णाङ्क __cdecl strcmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  size_t __cdecl strlen(ध्रुव वर्ण *_Str);
#यदि 0
  size_t __cdecl strnlen(ध्रुव वर्ण *_Str,size_t Max_मोजणी);
#endif
  शून्य *__cdecl memmove(शून्य *_Dst,ध्रुव शून्य *_Src,size_t _Size);
  _CRTIMP वर्ण *__cdecl _strdup(ध्रुव वर्ण *_Src);
  _CONST_RETURN वर्ण *__cdecl strchr(ध्रुव वर्ण *_Str,पूर्णाङ्क _Val);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcmpi(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  पूर्णाङ्क __cdecl strcoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _strcoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _stricoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll (ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _strncoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll (ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _strnicoll_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी,_locale_t _Locale);
  size_t __cdecl strcspn(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CRTIMP वर्ण *__cdecl _strerror(ध्रुव वर्ण *Err_संदेश);
  वर्ण *__cdecl strerror(पूर्णाङ्क);
  _CRTIMP वर्ण *__cdecl _strlwr(वर्ण *_String);
  वर्ण *strlwr_l(वर्ण *_String,_locale_t _Locale);
  वर्ण *__cdecl strncat(वर्ण *_Dest,ध्रुव वर्ण *_Source,size_t मोजणी_5);
  पूर्णाङ्क __cdecl strncmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _strnicmp_l(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2,size_t Max_मोजणी,_locale_t _Locale);
  वर्ण *strncpy(वर्ण *_Dest,ध्रुव वर्ण *_Source,size_t मोजणी_5);
  _CRTIMP वर्ण *__cdecl _strnset(वर्ण *_Str,पूर्णाङ्क _Val,size_t Max_मोजणी);
  _CONST_RETURN वर्ण *__cdecl strpbrk(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl strrchr(ध्रुव वर्ण *_Str,पूर्णाङ्क _Ch);
  _CRTIMP वर्ण *__cdecl _strrev(वर्ण *_Str);
  size_t __cdecl strspn(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_Control);
  _CONST_RETURN वर्ण *__cdecl strstr(ध्रुव वर्ण *_Str,ध्रुव वर्ण *_SubStr);
  वर्ण *__cdecl strtok(वर्ण *_Str,ध्रुव वर्ण *_Delim);
  _CRTIMP वर्ण *__cdecl _strupr(वर्ण *_String);
  _CRTIMP वर्ण *_strupr_l(वर्ण *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(वर्ण *_Dst,ध्रुव वर्ण *_Src,size_t Max_मोजणी);
  _CRTIMP size_t __cdecl _strxfrm_l(वर्ण *_Dst,ध्रुव वर्ण *_Src,size_t Max_मोजणी,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  वर्ण *__cdecl strdup(ध्रुव वर्ण *_Src);
  पूर्णाङ्क __cdecl strcmpi(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  पूर्णाङ्क __cdecl stricmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str2);
  वर्ण *__cdecl strlwr(वर्ण *_Str);
  पूर्णाङ्क __cdecl strnicmp(ध्रुव वर्ण *_Str1,ध्रुव वर्ण *_Str,size_t Max_मोजणी);
  __CRT_INLINE पूर्णाङ्क __cdecl strncasecmp (ध्रुव वर्ण *__sz1, ध्रुव वर्ण *__sz2, size_t __sizeMaxCompare) { प्रत्यागम _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE पूर्णाङ्क __cdecl strcasecmp (ध्रुव वर्ण *__sz1, ध्रुव वर्ण *__sz2) { प्रत्यागम _stricmp (__sz1, __sz2); }
  वर्ण *__cdecl strnset(वर्ण *_Str,पूर्णाङ्क _Val,size_t Max_मोजणी);
  वर्ण *__cdecl strrev(वर्ण *_Str);
  वर्ण *__cdecl strset(वर्ण *_Str,पूर्णाङ्क _Val);
  वर्ण *__cdecl strupr(वर्ण *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ध्रुव wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  पूर्णाङ्क __cdecl wcscmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ध्रुव wchar_t *_Source);
  size_t __cdecl wcscspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  size_t __cdecl wcslen(ध्रुव wchar_t *_Str);
  size_t __cdecl wcsnlen(ध्रुव wchar_t *_Src,size_t Max_मोजणी);
  wchar_t *wcsncat(wchar_t *_Dest,ध्रुव wchar_t *_Source,size_t मोजणी_5);
  पूर्णाङ्क __cdecl wcsncmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी);
  wchar_t *wcsncpy(wchar_t *_Dest,ध्रुव wchar_t *_Source,size_t मोजणी_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ध्रुव wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ध्रुव wchar_t *_Str,ध्रुव wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ध्रुव wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(पूर्णाङ्क Err_अंक);
  _CRTIMP wchar_t *__cdecl __wcserror(ध्रुव wchar_t *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicmp_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_मोजणी);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ध्रुव wchar_t *_Src,size_t Max_मोजणी);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ध्रुव wchar_t *_Src,size_t Max_मोजणी,_locale_t _Locale);
  पूर्णाङ्क __cdecl wcscoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcscoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  _CRTIMP पूर्णाङ्क __cdecl _wcsicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _wcsncoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी);
  _CRTIMP पूर्णाङ्क __cdecl _wcsnicoll_l(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ध्रुव wchar_t *_Str);
#define wcswcs wcsstr
  पूर्णाङ्क __cdecl wcsicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
  पूर्णाङ्क __cdecl wcsnicmp(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2,size_t Max_मोजणी);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_मोजणी);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  पूर्णाङ्क __cdecl wcsicoll(ध्रुव wchar_t *_Str1,ध्रुव wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#अन्तर्भाव <sec_api/string_s.h>
#endif
