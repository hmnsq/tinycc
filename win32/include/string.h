/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#شامل <_mingw.h>

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef پوچ
#ifdef __cplusplus
#define پوچ 0
#وگرنه
#define پوچ ((تهی *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP تهی *__cdecl _memccpy(تهی *_Dst,ثابت تهی *_Src,صحیح _Val,size_t Max_شمار);
  _CONST_RETURN تهی *__cdecl memchr(ثابت تهی *_Buf ,صحیح _Val,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _memicmp(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size);
  _CRTIMP صحیح __cdecl _memicmp_l(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size,_locale_t _Locale);
  صحیح __cdecl memcmp(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size);
  تهی *__cdecl memcpy(تهی *_Dst,ثابت تهی *_Src,size_t _Size);
  تهی *__cdecl memset(تهی *_Dst,صحیح _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  تهی *__cdecl memccpy(تهی *_Dst,ثابت تهی *_Src,صحیح _Val,size_t _Size);
  صحیح __cdecl memicmp(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size);
#endif
#endif
  نویسه *__cdecl _strset(نویسه *_Str,صحیح _Val);
  نویسه *__cdecl strcpy(نویسه *_Dest,ثابت نویسه *_Source);
  نویسه *__cdecl strcat(نویسه *_Dest,ثابت نویسه *_Source);
  صحیح __cdecl strcmp(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  size_t __cdecl strlen(ثابت نویسه *_Str);
#اگر 0
  size_t __cdecl strnlen(ثابت نویسه *_Str,size_t Max_شمار);
#endif
  تهی *__cdecl memmove(تهی *_Dst,ثابت تهی *_Src,size_t _Size);
  _CRTIMP نویسه *__cdecl _strdup(ثابت نویسه *_Src);
  _CONST_RETURN نویسه *__cdecl strchr(ثابت نویسه *_Str,صحیح _Val);
  _CRTIMP صحیح __cdecl _stricmp(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  _CRTIMP صحیح __cdecl _strcmpi(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  _CRTIMP صحیح __cdecl _stricmp_l(ثابت نویسه *_Str1,ثابت نویسه *_Str2,_locale_t _Locale);
  صحیح __cdecl strcoll(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  _CRTIMP صحیح __cdecl _strcoll_l(ثابت نویسه *_Str1,ثابت نویسه *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _stricoll(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  _CRTIMP صحیح __cdecl _stricoll_l(ثابت نویسه *_Str1,ثابت نویسه *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _strncoll (ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _strncoll_l(ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _strnicoll (ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _strnicoll_l(ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار,_locale_t _Locale);
  size_t __cdecl strcspn(ثابت نویسه *_Str,ثابت نویسه *_Control);
  _CRTIMP نویسه *__cdecl _strerror(ثابت نویسه *Err_پیام);
  نویسه *__cdecl strerror(صحیح);
  _CRTIMP نویسه *__cdecl _strlwr(نویسه *_String);
  نویسه *strlwr_l(نویسه *_String,_locale_t _Locale);
  نویسه *__cdecl strncat(نویسه *_Dest,ثابت نویسه *_Source,size_t شمار_5);
  صحیح __cdecl strncmp(ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _strnicmp(ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _strnicmp_l(ثابت نویسه *_Str1,ثابت نویسه *_Str2,size_t Max_شمار,_locale_t _Locale);
  نویسه *strncpy(نویسه *_Dest,ثابت نویسه *_Source,size_t شمار_5);
  _CRTIMP نویسه *__cdecl _strnset(نویسه *_Str,صحیح _Val,size_t Max_شمار);
  _CONST_RETURN نویسه *__cdecl strpbrk(ثابت نویسه *_Str,ثابت نویسه *_Control);
  _CONST_RETURN نویسه *__cdecl strrchr(ثابت نویسه *_Str,صحیح _Ch);
  _CRTIMP نویسه *__cdecl _strrev(نویسه *_Str);
  size_t __cdecl strspn(ثابت نویسه *_Str,ثابت نویسه *_Control);
  _CONST_RETURN نویسه *__cdecl strstr(ثابت نویسه *_Str,ثابت نویسه *_SubStr);
  نویسه *__cdecl strtok(نویسه *_Str,ثابت نویسه *_Delim);
  _CRTIMP نویسه *__cdecl _strupr(نویسه *_String);
  _CRTIMP نویسه *_strupr_l(نویسه *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(نویسه *_Dst,ثابت نویسه *_Src,size_t Max_شمار);
  _CRTIMP size_t __cdecl _strxfrm_l(نویسه *_Dst,ثابت نویسه *_Src,size_t Max_شمار,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  نویسه *__cdecl strdup(ثابت نویسه *_Src);
  صحیح __cdecl strcmpi(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  صحیح __cdecl stricmp(ثابت نویسه *_Str1,ثابت نویسه *_Str2);
  نویسه *__cdecl strlwr(نویسه *_Str);
  صحیح __cdecl strnicmp(ثابت نویسه *_Str1,ثابت نویسه *_Str,size_t Max_شمار);
  __CRT_INLINE صحیح __cdecl strncasecmp (ثابت نویسه *__sz1, ثابت نویسه *__sz2, size_t __sizeMaxCompare) { بازگشت _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE صحیح __cdecl strcasecmp (ثابت نویسه *__sz1, ثابت نویسه *__sz2) { بازگشت _stricmp (__sz1, __sz2); }
  نویسه *__cdecl strnset(نویسه *_Str,صحیح _Val,size_t Max_شمار);
  نویسه *__cdecl strrev(نویسه *_Str);
  نویسه *__cdecl strset(نویسه *_Str,صحیح _Val);
  نویسه *__cdecl strupr(نویسه *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحیح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *_Source);
  size_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  size_t __cdecl wcslen(ثابت wchar_t *_Str);
  size_t __cdecl wcsnlen(ثابت wchar_t *_Src,size_t Max_شمار);
  wchar_t *wcsncat(wchar_t *_Dest,ثابت wchar_t *_Source,size_t شمار_5);
  صحیح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  wchar_t *wcsncpy(wchar_t *_Dest,ثابت wchar_t *_Source,size_t شمار_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحیح Err_رقم);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_شمار);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,size_t Max_شمار);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,size_t Max_شمار,_locale_t _Locale);
  صحیح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#define wcswcs wcsstr
  صحیح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحیح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_شمار);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_شمار);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحیح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#شامل <sec_api/string_s.h>
#endif
