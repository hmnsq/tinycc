/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#ضمن <_mingw.h>

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef عدم
#ifdef __cplusplus
#define عدم 0
#وإلا
#define عدم ((فراغ *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP فراغ *__cdecl _memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,size_t Max_كدي);
  _CONST_RETURN فراغ *__cdecl memchr(ثابت فراغ *_Buf ,صحيح _Val,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,size_t _Size);
  _CRTIMP صحيح __cdecl _memicmp_l(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,size_t _Size,_locale_t _Locale);
  صحيح __cdecl memcmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,size_t _Size);
  فراغ *__cdecl memcpy(فراغ *_Dst,ثابت فراغ *_Src,size_t _Size);
  فراغ *__cdecl memset(فراغ *_Dst,صحيح _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  فراغ *__cdecl memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,size_t _Size);
  صحيح __cdecl memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,size_t _Size);
#endif
#endif
  حرف *__cdecl _strset(حرف *_Str,صحيح _Val);
  حرف *__cdecl strcpy(حرف *_Dest,ثابت حرف *_Source);
  حرف *__cdecl strcat(حرف *_Dest,ثابت حرف *_Source);
  صحيح __cdecl strcmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  size_t __cdecl strlen(ثابت حرف *_Str);
#إذا 0
  size_t __cdecl strnlen(ثابت حرف *_Str,size_t Max_كدي);
#endif
  فراغ *__cdecl memmove(فراغ *_Dst,ثابت فراغ *_Src,size_t _Size);
  _CRTIMP حرف *__cdecl _strdup(ثابت حرف *_Src);
  _CONST_RETURN حرف *__cdecl strchr(ثابت حرف *_Str,صحيح _Val);
  _CRTIMP صحيح __cdecl _stricmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _strcmpi(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _stricmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  صحيح __cdecl strcoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _strcoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _stricoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _stricoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _strncoll (ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _strncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _strnicoll (ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _strnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي,_locale_t _Locale);
  size_t __cdecl strcspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _strerror(ثابت حرف *Err_سكو);
  حرف *__cdecl strerror(صحيح);
  _CRTIMP حرف *__cdecl _strlwr(حرف *_String);
  حرف *strlwr_l(حرف *_String,_locale_t _Locale);
  حرف *__cdecl strncat(حرف *_Dest,ثابت حرف *_Source,size_t كدي_5);
  صحيح __cdecl strncmp(ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _strnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _strnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,size_t Max_كدي,_locale_t _Locale);
  حرف *strncpy(حرف *_Dest,ثابت حرف *_Source,size_t كدي_5);
  _CRTIMP حرف *__cdecl _strnset(حرف *_Str,صحيح _Val,size_t Max_كدي);
  _CONST_RETURN حرف *__cdecl strpbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CONST_RETURN حرف *__cdecl strrchr(ثابت حرف *_Str,صحيح _Ch);
  _CRTIMP حرف *__cdecl _strrev(حرف *_Str);
  size_t __cdecl strspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CONST_RETURN حرف *__cdecl strstr(ثابت حرف *_Str,ثابت حرف *_SubStr);
  حرف *__cdecl strtok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _strupr(حرف *_String);
  _CRTIMP حرف *_strupr_l(حرف *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(حرف *_Dst,ثابت حرف *_Src,size_t Max_كدي);
  _CRTIMP size_t __cdecl _strxfrm_l(حرف *_Dst,ثابت حرف *_Src,size_t Max_كدي,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  حرف *__cdecl strdup(ثابت حرف *_Src);
  صحيح __cdecl strcmpi(ثابت حرف *_Str1,ثابت حرف *_Str2);
  صحيح __cdecl stricmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  حرف *__cdecl strlwr(حرف *_Str);
  صحيح __cdecl strnicmp(ثابت حرف *_Str1,ثابت حرف *_Str,size_t Max_كدي);
  __CRT_INLINE صحيح __cdecl strncasecmp (ثابت حرف *__sz1, ثابت حرف *__sz2, size_t __sizeMaxCompare) { أرجع _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE صحيح __cdecl strcasecmp (ثابت حرف *__sz1, ثابت حرف *__sz2) { أرجع _stricmp (__sz1, __sz2); }
  حرف *__cdecl strnset(حرف *_Str,صحيح _Val,size_t Max_كدي);
  حرف *__cdecl strrev(حرف *_Str);
  حرف *__cdecl strset(حرف *_Str,صحيح _Val);
  حرف *__cdecl strupr(حرف *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحيح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *_Source);
  size_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  size_t __cdecl wcslen(ثابت wchar_t *_Str);
  size_t __cdecl wcsnlen(ثابت wchar_t *_Src,size_t Max_كدي);
  wchar_t *wcsncat(wchar_t *_Dest,ثابت wchar_t *_Source,size_t كدي_5);
  صحيح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي);
  wchar_t *wcsncpy(wchar_t *_Dest,ثابت wchar_t *_Source,size_t كدي_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحيح Err_لمب);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_كدي);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,size_t Max_كدي);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,size_t Max_كدي,_locale_t _Locale);
  صحيح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي);
  _CRTIMP صحيح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#define wcswcs wcsstr
  صحيح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحيح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,size_t Max_كدي);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_كدي);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحيح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#ضمن <sec_api/string_s.h>
#endif
