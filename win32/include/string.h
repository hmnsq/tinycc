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
#නැතහොත්
#define NULL ((void *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP void *__cdecl _memccpy(void *_Dst,const void *_Src,පූර්ණ_සංඛ්‍යා _Val,size_t _MaxCount);
  _CONST_RETURN void *__cdecl memchr(const void *_Buf ,පූර්ණ_සංඛ්‍යා _Val,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  පූර්ණ_සංඛ්‍යා __cdecl memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void *__cdecl memcpy(void *_Dst,const void *_Src,size_t _Size);
  void *__cdecl memset(void *_Dst,පූර්ණ_සංඛ්‍යා _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  void *__cdecl memccpy(void *_Dst,const void *_Src,පූර්ණ_සංඛ්‍යා _Val,size_t _Size);
  පූර්ණ_සංඛ්‍යා __cdecl memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
#endif
#endif
  var_na *__cdecl _strset(var_na *_Str,පූර්ණ_සංඛ්‍යා _Val);
  var_na *__cdecl strcpy(var_na *_Dest,const var_na *_Source);
  var_na *__cdecl strcat(var_na *_Dest,const var_na *_Source);
  පූර්ණ_සංඛ්‍යා __cdecl strcmp(const var_na *_Str1,const var_na *_Str2);
  size_t __cdecl strlen(const var_na *_Str);
#නම් 0
  size_t __cdecl strnlen(const var_na *_Str,size_t _MaxCount);
#endif
  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size);
  _CRTIMP var_na *__cdecl _strdup(const var_na *_Src);
  _CONST_RETURN var_na *__cdecl strchr(const var_na *_Str,පූර්ණ_සංඛ්‍යා _Val);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _stricmp(const var_na *_Str1,const var_na *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strcmpi(const var_na *_Str1,const var_na *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _stricmp_l(const var_na *_Str1,const var_na *_Str2,_locale_t _Locale);
  පූර්ණ_සංඛ්‍යා __cdecl strcoll(const var_na *_Str1,const var_na *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strcoll_l(const var_na *_Str1,const var_na *_Str2,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _stricoll(const var_na *_Str1,const var_na *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _stricoll_l(const var_na *_Str1,const var_na *_Str2,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strncoll (const var_na *_Str1,const var_na *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strncoll_l(const var_na *_Str1,const var_na *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strnicoll (const var_na *_Str1,const var_na *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strnicoll_l(const var_na *_Str1,const var_na *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(const var_na *_Str,const var_na *_Control);
  _CRTIMP var_na *__cdecl _strerror(const var_na *_ErrMsg);
  var_na *__cdecl strerror(පූර්ණ_සංඛ්‍යා);
  _CRTIMP var_na *__cdecl _strlwr(var_na *_String);
  var_na *strlwr_l(var_na *_String,_locale_t _Locale);
  var_na *__cdecl strncat(var_na *_Dest,const var_na *_Source,size_t _Count);
  පූර්ණ_සංඛ්‍යා __cdecl strncmp(const var_na *_Str1,const var_na *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strnicmp(const var_na *_Str1,const var_na *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _strnicmp_l(const var_na *_Str1,const var_na *_Str2,size_t _MaxCount,_locale_t _Locale);
  var_na *strncpy(var_na *_Dest,const var_na *_Source,size_t _Count);
  _CRTIMP var_na *__cdecl _strnset(var_na *_Str,පූර්ණ_සංඛ්‍යා _Val,size_t _MaxCount);
  _CONST_RETURN var_na *__cdecl strpbrk(const var_na *_Str,const var_na *_Control);
  _CONST_RETURN var_na *__cdecl strrchr(const var_na *_Str,පූර්ණ_සංඛ්‍යා _Ch);
  _CRTIMP var_na *__cdecl _strrev(var_na *_Str);
  size_t __cdecl strspn(const var_na *_Str,const var_na *_Control);
  _CONST_RETURN var_na *__cdecl strstr(const var_na *_Str,const var_na *_SubStr);
  var_na *__cdecl strtok(var_na *_Str,const var_na *_Delim);
  _CRTIMP var_na *__cdecl _strupr(var_na *_String);
  _CRTIMP var_na *_strupr_l(var_na *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(var_na *_Dst,const var_na *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _strxfrm_l(var_na *_Dst,const var_na *_Src,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  var_na *__cdecl strdup(const var_na *_Src);
  පූර්ණ_සංඛ්‍යා __cdecl strcmpi(const var_na *_Str1,const var_na *_Str2);
  පූර්ණ_සංඛ්‍යා __cdecl stricmp(const var_na *_Str1,const var_na *_Str2);
  var_na *__cdecl strlwr(var_na *_Str);
  පූර්ණ_සංඛ්‍යා __cdecl strnicmp(const var_na *_Str1,const var_na *_Str,size_t _MaxCount);
  __CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl strncasecmp (const var_na *__sz1, const var_na *__sz2, size_t __sizeMaxCompare) { ආපසු _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl strcasecmp (const var_na *__sz1, const var_na *__sz2) { ආපසු _stricmp (__sz1, __sz2); }
  var_na *__cdecl strnset(var_na *_Str,පූර්ණ_සංඛ්‍යා _Val,size_t _MaxCount);
  var_na *__cdecl strrev(var_na *_Str);
  var_na *__cdecl strset(var_na *_Str,පූර්ණ_සංඛ්‍යා _Val);
  var_na *__cdecl strupr(var_na *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,const wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  පූර්ණ_සංඛ්‍යා __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,const wchar_t *_Source);
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t *_Dest,const wchar_t *_Source,size_t _Count);
  පූර්ණ_සංඛ්‍යා __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t *_Dest,const wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,const wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(පූර්ණ_සංඛ්‍යා _ErrNum);
  _CRTIMP wchar_t *__cdecl __wcserror(const wchar_t *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,const wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,const wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  පූර්ණ_සංඛ්‍යා __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(const wchar_t *_Str);
#define wcswcs wcsstr
  පූර්ණ_සංඛ්‍යා __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  පූර්ණ_සංඛ්‍යා __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  පූර්ණ_සංඛ්‍යා __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#include <sec_api/string_s.h>
#endif
