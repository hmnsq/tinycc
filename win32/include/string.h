/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#অন্তর্ভাৱ <_mingw.h>

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP শূন্য *__cdecl _memccpy(শূন্য *_Dst,ধ্রুৱ শূন্য *_Src,পূর্ণাঙ্ক _Val,size_t Max_গুনতি);
  _CONST_RETURN শূন্য *__cdecl memchr(ধ্রুৱ শূন্য *_Buf ,পূর্ণাঙ্ক _Val,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _memicmp(ধ্রুৱ শূন্য *_Buf1,ধ্রুৱ শূন্য *_Buf2,size_t _Size);
  _CRTIMP পূর্ণাঙ্ক __cdecl _memicmp_l(ধ্রুৱ শূন্য *_Buf1,ধ্রুৱ শূন্য *_Buf2,size_t _Size,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl memcmp(ধ্রুৱ শূন্য *_Buf1,ধ্রুৱ শূন্য *_Buf2,size_t _Size);
  শূন্য *__cdecl memcpy(শূন্য *_Dst,ধ্রুৱ শূন্য *_Src,size_t _Size);
  শূন্য *__cdecl memset(শূন্য *_Dst,পূর্ণাঙ্ক _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  শূন্য *__cdecl memccpy(শূন্য *_Dst,ধ্রুৱ শূন্য *_Src,পূর্ণাঙ্ক _Val,size_t _Size);
  পূর্ণাঙ্ক __cdecl memicmp(ধ্রুৱ শূন্য *_Buf1,ধ্রুৱ শূন্য *_Buf2,size_t _Size);
#endif
#endif
  ৱর্ণ *__cdecl _strset(ৱর্ণ *_Str,পূর্ণাঙ্ক _Val);
  ৱর্ণ *__cdecl strcpy(ৱর্ণ *_Dest,ধ্রুৱ ৱর্ণ *_Source);
  ৱর্ণ *__cdecl strcat(ৱর্ণ *_Dest,ধ্রুৱ ৱর্ণ *_Source);
  পূর্ণাঙ্ক __cdecl strcmp(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  size_t __cdecl strlen(ধ্রুৱ ৱর্ণ *_Str);
#যদি 0
  size_t __cdecl strnlen(ধ্রুৱ ৱর্ণ *_Str,size_t Max_গুনতি);
#endif
  শূন্য *__cdecl memmove(শূন্য *_Dst,ধ্রুৱ শূন্য *_Src,size_t _Size);
  _CRTIMP ৱর্ণ *__cdecl _strdup(ধ্রুৱ ৱর্ণ *_Src);
  _CONST_RETURN ৱর্ণ *__cdecl strchr(ধ্রুৱ ৱর্ণ *_Str,পূর্ণাঙ্ক _Val);
  _CRTIMP পূর্ণাঙ্ক __cdecl _stricmp(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strcmpi(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _stricmp_l(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl strcoll(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strcoll_l(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _stricoll(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _stricoll_l(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strncoll (ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strncoll_l(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strnicoll (ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strnicoll_l(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  size_t __cdecl strcspn(ধ্রুৱ ৱর্ণ *_Str,ধ্রুৱ ৱর্ণ *_Control);
  _CRTIMP ৱর্ণ *__cdecl _strerror(ধ্রুৱ ৱর্ণ *Err_বাৰ্তা);
  ৱর্ণ *__cdecl strerror(পূর্ণাঙ্ক);
  _CRTIMP ৱর্ণ *__cdecl _strlwr(ৱর্ণ *_String);
  ৱর্ণ *strlwr_l(ৱর্ণ *_String,_locale_t _Locale);
  ৱর্ণ *__cdecl strncat(ৱর্ণ *_Dest,ধ্রুৱ ৱর্ণ *_Source,size_t গুনতি_5);
  পূর্ণাঙ্ক __cdecl strncmp(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strnicmp(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _strnicmp_l(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  ৱর্ণ *strncpy(ৱর্ণ *_Dest,ধ্রুৱ ৱর্ণ *_Source,size_t গুনতি_5);
  _CRTIMP ৱর্ণ *__cdecl _strnset(ৱর্ণ *_Str,পূর্ণাঙ্ক _Val,size_t Max_গুনতি);
  _CONST_RETURN ৱর্ণ *__cdecl strpbrk(ধ্রুৱ ৱর্ণ *_Str,ধ্রুৱ ৱর্ণ *_Control);
  _CONST_RETURN ৱর্ণ *__cdecl strrchr(ধ্রুৱ ৱর্ণ *_Str,পূর্ণাঙ্ক _Ch);
  _CRTIMP ৱর্ণ *__cdecl _strrev(ৱর্ণ *_Str);
  size_t __cdecl strspn(ধ্রুৱ ৱর্ণ *_Str,ধ্রুৱ ৱর্ণ *_Control);
  _CONST_RETURN ৱর্ণ *__cdecl strstr(ধ্রুৱ ৱর্ণ *_Str,ধ্রুৱ ৱর্ণ *_SubStr);
  ৱর্ণ *__cdecl strtok(ৱর্ণ *_Str,ধ্রুৱ ৱর্ণ *_Delim);
  _CRTIMP ৱর্ণ *__cdecl _strupr(ৱর্ণ *_String);
  _CRTIMP ৱর্ণ *_strupr_l(ৱর্ণ *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(ৱর্ণ *_Dst,ধ্রুৱ ৱর্ণ *_Src,size_t Max_গুনতি);
  _CRTIMP size_t __cdecl _strxfrm_l(ৱর্ণ *_Dst,ধ্রুৱ ৱর্ণ *_Src,size_t Max_গুনতি,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  ৱর্ণ *__cdecl strdup(ধ্রুৱ ৱর্ণ *_Src);
  পূর্ণাঙ্ক __cdecl strcmpi(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  পূর্ণাঙ্ক __cdecl stricmp(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str2);
  ৱর্ণ *__cdecl strlwr(ৱর্ণ *_Str);
  পূর্ণাঙ্ক __cdecl strnicmp(ধ্রুৱ ৱর্ণ *_Str1,ধ্রুৱ ৱর্ণ *_Str,size_t Max_গুনতি);
  __CRT_INLINE পূর্ণাঙ্ক __cdecl strncasecmp (ধ্রুৱ ৱর্ণ *__sz1, ধ্রুৱ ৱর্ণ *__sz2, size_t __sizeMaxCompare) { ঘূৰাই _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE পূর্ণাঙ্ক __cdecl strcasecmp (ধ্রুৱ ৱর্ণ *__sz1, ধ্রুৱ ৱর্ণ *__sz2) { ঘূৰাই _stricmp (__sz1, __sz2); }
  ৱর্ণ *__cdecl strnset(ৱর্ণ *_Str,পূর্ণাঙ্ক _Val,size_t Max_গুনতি);
  ৱর্ণ *__cdecl strrev(ৱর্ণ *_Str);
  ৱর্ণ *__cdecl strset(ৱর্ণ *_Str,পূর্ণাঙ্ক _Val);
  ৱর্ণ *__cdecl strupr(ৱর্ণ *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ধ্রুৱ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ধ্রুৱ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ধ্রুৱ wchar_t *_Str,wchar_t _Ch);
  পূর্ণাঙ্ক __cdecl wcscmp(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ধ্রুৱ wchar_t *_Source);
  size_t __cdecl wcscspn(ধ্রুৱ wchar_t *_Str,ধ্রুৱ wchar_t *_Control);
  size_t __cdecl wcslen(ধ্রুৱ wchar_t *_Str);
  size_t __cdecl wcsnlen(ধ্রুৱ wchar_t *_Src,size_t Max_গুনতি);
  wchar_t *wcsncat(wchar_t *_Dest,ধ্রুৱ wchar_t *_Source,size_t গুনতি_5);
  পূর্ণাঙ্ক __cdecl wcsncmp(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি);
  wchar_t *wcsncpy(wchar_t *_Dest,ধ্রুৱ wchar_t *_Source,size_t গুনতি_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ধ্রুৱ wchar_t *_Str,ধ্রুৱ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ধ্রুৱ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ধ্রুৱ wchar_t *_Str,ধ্রুৱ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ধ্রুৱ wchar_t *_Str,ধ্রুৱ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ধ্রুৱ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(পূর্ণাঙ্ক Err_অঙ্ক);
  _CRTIMP wchar_t *__cdecl __wcserror(ধ্রুৱ wchar_t *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicmp(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicmp_l(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicmp(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicmp_l(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_গুনতি);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ধ্রুৱ wchar_t *_Src,size_t Max_গুনতি);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ধ্রুৱ wchar_t *_Src,size_t Max_গুনতি,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl wcscoll(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcscoll_l(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicoll(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsicoll_l(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsncoll(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsncoll_l(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicoll(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcsnicoll_l(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ধ্রুৱ wchar_t *_Str);
#define wcswcs wcsstr
  পূর্ণাঙ্ক __cdecl wcsicmp(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2);
  পূর্ণাঙ্ক __cdecl wcsnicmp(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2,size_t Max_গুনতি);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_গুনতি);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  পূর্ণাঙ্ক __cdecl wcsicoll(ধ্রুৱ wchar_t *_Str1,ধ্রুৱ wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#অন্তর্ভাৱ <sec_api/string_s.h>
#endif
