/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#অন্তর্ভাব <_mingw.h>

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP শূন্য *__cdecl _memccpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CONST_RETURN শূন্য *__cdecl memchr(ধ্রুবক শূন্য *_Buf ,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _memicmp(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5);
  _CRTIMP পূর্ণসংখ্যা __cdecl _memicmp_l(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl memcmp(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5);
  শূন্য *__cdecl memcpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,আকার_t আকার_5);
  শূন্য *__cdecl memset(শূন্য *_Dst,পূর্ণসংখ্যা _Val,আকার_t আকার_5);
#ifndef	NO_OLDNAMES
  শূন্য *__cdecl memccpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,পূর্ণসংখ্যা _Val,আকার_t আকার_5);
  পূর্ণসংখ্যা __cdecl memicmp(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5);
#endif
#endif
  অক্ষর *__cdecl _strset(অক্ষর *_Str,পূর্ণসংখ্যা _Val);
  অক্ষর *__cdecl strcpy(অক্ষর *_Dest,ধ্রুবক অক্ষর *_Source);
  অক্ষর *__cdecl strcat(অক্ষর *_Dest,ধ্রুবক অক্ষর *_Source);
  পূর্ণসংখ্যা __cdecl strcmp(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  আকার_t __cdecl strlen(ধ্রুবক অক্ষর *_Str);
#যদি 0
  আকার_t __cdecl strnlen(ধ্রুবক অক্ষর *_Str,আকার_t Max_গুনতি);
#endif
  শূন্য *__cdecl memmove(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,আকার_t আকার_5);
  _CRTIMP অক্ষর *__cdecl _strdup(ধ্রুবক অক্ষর *_Src);
  _CONST_RETURN অক্ষর *__cdecl strchr(ধ্রুবক অক্ষর *_Str,পূর্ণসংখ্যা _Val);
  _CRTIMP পূর্ণসংখ্যা __cdecl _stricmp(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strcmpi(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _stricmp_l(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl strcoll(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strcoll_l(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _stricoll(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _stricoll_l(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strncoll (ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strncoll_l(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strnicoll (ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strnicoll_l(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  আকার_t __cdecl strcspn(ধ্রুবক অক্ষর *_Str,ধ্রুবক অক্ষর *_Control);
  _CRTIMP অক্ষর *__cdecl _strerror(ধ্রুবক অক্ষর *Err_বার্তা);
  অক্ষর *__cdecl strerror(পূর্ণসংখ্যা);
  _CRTIMP অক্ষর *__cdecl _strlwr(অক্ষর *_String);
  অক্ষর *strlwr_l(অক্ষর *_String,_locale_t _Locale);
  অক্ষর *__cdecl strncat(অক্ষর *_Dest,ধ্রুবক অক্ষর *_Source,আকার_t গুনতি_5);
  পূর্ণসংখ্যা __cdecl strncmp(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strnicmp(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _strnicmp_l(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  অক্ষর *strncpy(অক্ষর *_Dest,ধ্রুবক অক্ষর *_Source,আকার_t গুনতি_5);
  _CRTIMP অক্ষর *__cdecl _strnset(অক্ষর *_Str,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CONST_RETURN অক্ষর *__cdecl strpbrk(ধ্রুবক অক্ষর *_Str,ধ্রুবক অক্ষর *_Control);
  _CONST_RETURN অক্ষর *__cdecl strrchr(ধ্রুবক অক্ষর *_Str,পূর্ণসংখ্যা _Ch);
  _CRTIMP অক্ষর *__cdecl _strrev(অক্ষর *_Str);
  আকার_t __cdecl strspn(ধ্রুবক অক্ষর *_Str,ধ্রুবক অক্ষর *_Control);
  _CONST_RETURN অক্ষর *__cdecl strstr(ধ্রুবক অক্ষর *_Str,ধ্রুবক অক্ষর *_SubStr);
  অক্ষর *__cdecl strtok(অক্ষর *_Str,ধ্রুবক অক্ষর *_Delim);
  _CRTIMP অক্ষর *__cdecl _strupr(অক্ষর *_String);
  _CRTIMP অক্ষর *_strupr_l(অক্ষর *_String,_locale_t _Locale);
  আকার_t __cdecl strxfrm(অক্ষর *_Dst,ধ্রুবক অক্ষর *_Src,আকার_t Max_গুনতি);
  _CRTIMP আকার_t __cdecl _strxfrm_l(অক্ষর *_Dst,ধ্রুবক অক্ষর *_Src,আকার_t Max_গুনতি,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  অক্ষর *__cdecl strdup(ধ্রুবক অক্ষর *_Src);
  পূর্ণসংখ্যা __cdecl strcmpi(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  পূর্ণসংখ্যা __cdecl stricmp(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str2);
  অক্ষর *__cdecl strlwr(অক্ষর *_Str);
  পূর্ণসংখ্যা __cdecl strnicmp(ধ্রুবক অক্ষর *_Str1,ধ্রুবক অক্ষর *_Str,আকার_t Max_গুনতি);
  __CRT_INLINE পূর্ণসংখ্যা __cdecl strncasecmp (ধ্রুবক অক্ষর *__sz1, ধ্রুবক অক্ষর *__sz2, আকার_t __sizeMaxCompare) { ফেরত _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE পূর্ণসংখ্যা __cdecl strcasecmp (ধ্রুবক অক্ষর *__sz1, ধ্রুবক অক্ষর *__sz2) { ফেরত _stricmp (__sz1, __sz2); }
  অক্ষর *__cdecl strnset(অক্ষর *_Str,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  অক্ষর *__cdecl strrev(অক্ষর *_Str);
  অক্ষর *__cdecl strset(অক্ষর *_Str,পূর্ণসংখ্যা _Val);
  অক্ষর *__cdecl strupr(অক্ষর *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ধ্রুবক wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ধ্রুবক wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ধ্রুবক wchar_t *_Str,wchar_t _Ch);
  পূর্ণসংখ্যা __cdecl wcscmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ধ্রুবক wchar_t *_Source);
  আকার_t __cdecl wcscspn(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_Control);
  আকার_t __cdecl wcslen(ধ্রুবক wchar_t *_Str);
  আকার_t __cdecl wcsnlen(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি);
  wchar_t *wcsncat(wchar_t *_Dest,ধ্রুবক wchar_t *_Source,আকার_t গুনতি_5);
  পূর্ণসংখ্যা __cdecl wcsncmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  wchar_t *wcsncpy(wchar_t *_Dest,ধ্রুবক wchar_t *_Source,আকার_t গুনতি_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ধ্রুবক wchar_t *_Str,wchar_t _Ch);
  আকার_t __cdecl wcsspn(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ধ্রুবক wchar_t *_Str,ধ্রুবক wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ধ্রুবক wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(পূর্ণসংখ্যা Err_অঙ্ক);
  _CRTIMP wchar_t *__cdecl __wcserror(ধ্রুবক wchar_t *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicmp_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicmp_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,আকার_t Max_গুনতি);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  আকার_t __cdecl wcsxfrm(wchar_t *_Dst,ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি);
  _CRTIMP আকার_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl wcscoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcscoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsicoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsncoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsncoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wcsnicoll_l(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ধ্রুবক wchar_t *_Str);
#define wcswcs wcsstr
  পূর্ণসংখ্যা __cdecl wcsicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
  পূর্ণসংখ্যা __cdecl wcsnicmp(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2,আকার_t Max_গুনতি);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,আকার_t Max_গুনতি);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  পূর্ণসংখ্যা __cdecl wcsicoll(ধ্রুবক wchar_t *_Str1,ধ্রুবক wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#অন্তর্ভাব <sec_api/string_s.h>
#endif
