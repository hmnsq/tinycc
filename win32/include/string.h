/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#không_thì
#define NULL ((void *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP void *__cdecl _memccpy(void *_Dst,const void *_Src,số_nguyên _Val,size_t _MaxCount);
  _CONST_RETURN void *__cdecl memchr(const void *_Buf ,số_nguyên _Val,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  _CRTIMP số_nguyên __cdecl _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  số_nguyên __cdecl memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void *__cdecl memcpy(void *_Dst,const void *_Src,size_t _Size);
  void *__cdecl memset(void *_Dst,số_nguyên _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  void *__cdecl memccpy(void *_Dst,const void *_Src,số_nguyên _Val,size_t _Size);
  số_nguyên __cdecl memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
#endif
#endif
  char *__cdecl _strset(char *_Str,số_nguyên _Val);
  char *__cdecl strcpy(char *_Dest,const char *_Source);
  char *__cdecl strcat(char *_Dest,const char *_Source);
  số_nguyên __cdecl strcmp(const char *_Str1,const char *_Str2);
  size_t __cdecl strlen(const char *_Str);
#nếu 0
  size_t __cdecl strnlen(const char *_Str,size_t _MaxCount);
#endif
  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size);
  _CRTIMP char *__cdecl _strdup(const char *_Src);
  _CONST_RETURN char *__cdecl strchr(const char *_Str,số_nguyên _Val);
  _CRTIMP số_nguyên __cdecl _stricmp(const char *_Str1,const char *_Str2);
  _CRTIMP số_nguyên __cdecl _strcmpi(const char *_Str1,const char *_Str2);
  _CRTIMP số_nguyên __cdecl _stricmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  số_nguyên __cdecl strcoll(const char *_Str1,const char *_Str2);
  _CRTIMP số_nguyên __cdecl _strcoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _stricoll(const char *_Str1,const char *_Str2);
  _CRTIMP số_nguyên __cdecl _stricoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _strncoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _strncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _strnicoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _strnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(const char *_Str,const char *_Control);
  _CRTIMP char *__cdecl _strerror(const char *_ErrMsg);
  char *__cdecl strerror(số_nguyên);
  _CRTIMP char *__cdecl _strlwr(char *_String);
  char *strlwr_l(char *_String,_locale_t _Locale);
  char *__cdecl strncat(char *_Dest,const char *_Source,size_t _Count);
  số_nguyên __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _strnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _strnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  char *strncpy(char *_Dest,const char *_Source,size_t _Count);
  _CRTIMP char *__cdecl _strnset(char *_Str,số_nguyên _Val,size_t _MaxCount);
  _CONST_RETURN char *__cdecl strpbrk(const char *_Str,const char *_Control);
  _CONST_RETURN char *__cdecl strrchr(const char *_Str,số_nguyên _Ch);
  _CRTIMP char *__cdecl _strrev(char *_Str);
  size_t __cdecl strspn(const char *_Str,const char *_Control);
  _CONST_RETURN char *__cdecl strstr(const char *_Str,const char *_SubStr);
  char *__cdecl strtok(char *_Str,const char *_Delim);
  _CRTIMP char *__cdecl _strupr(char *_String);
  _CRTIMP char *_strupr_l(char *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(char *_Dst,const char *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _strxfrm_l(char *_Dst,const char *_Src,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  char *__cdecl strdup(const char *_Src);
  số_nguyên __cdecl strcmpi(const char *_Str1,const char *_Str2);
  số_nguyên __cdecl stricmp(const char *_Str1,const char *_Str2);
  char *__cdecl strlwr(char *_Str);
  số_nguyên __cdecl strnicmp(const char *_Str1,const char *_Str,size_t _MaxCount);
  __CRT_INLINE số_nguyên __cdecl strncasecmp (const char *__sz1, const char *__sz2, size_t __sizeMaxCompare) { trả_về _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE số_nguyên __cdecl strcasecmp (const char *__sz1, const char *__sz2) { trả_về _stricmp (__sz1, __sz2); }
  char *__cdecl strnset(char *_Str,số_nguyên _Val,size_t _MaxCount);
  char *__cdecl strrev(char *_Str);
  char *__cdecl strset(char *_Str,số_nguyên _Val);
  char *__cdecl strupr(char *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,const wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  số_nguyên __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,const wchar_t *_Source);
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t *_Dest,const wchar_t *_Source,size_t _Count);
  số_nguyên __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t *_Dest,const wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,const wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(số_nguyên _ErrNum);
  _CRTIMP wchar_t *__cdecl __wcserror(const wchar_t *_Str);
  _CRTIMP số_nguyên __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP số_nguyên __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,const wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,const wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  số_nguyên __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP số_nguyên __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP số_nguyên __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP số_nguyên __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP số_nguyên __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(const wchar_t *_Str);
#define wcswcs wcsstr
  số_nguyên __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  số_nguyên __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  số_nguyên __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#include <sec_api/string_s.h>
#endif
