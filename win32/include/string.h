/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP ಶೂನ್ಯ *__cdecl _memccpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CONST_RETURN ಶೂನ್ಯ *__cdecl memchr(ಧ್ರುವ ಶೂನ್ಯ *_Buf ,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _memicmp(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _memicmp_l(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl memcmp(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size);
  ಶೂನ್ಯ *__cdecl memcpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,size_t _Size);
  ಶೂನ್ಯ *__cdecl memset(ಶೂನ್ಯ *_Dst,ಪೂರ್ಣಾಙ್ಕ _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  ಶೂನ್ಯ *__cdecl memccpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,ಪೂರ್ಣಾಙ್ಕ _Val,size_t _Size);
  ಪೂರ್ಣಾಙ್ಕ __cdecl memicmp(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size);
#endif
#endif
  ವರ್ಣ *__cdecl _strset(ವರ್ಣ *_Str,ಪೂರ್ಣಾಙ್ಕ _Val);
  ವರ್ಣ *__cdecl strcpy(ವರ್ಣ *_Dest,ಧ್ರುವ ವರ್ಣ *_Source);
  ವರ್ಣ *__cdecl strcat(ವರ್ಣ *_Dest,ಧ್ರುವ ವರ್ಣ *_Source);
  ಪೂರ್ಣಾಙ್ಕ __cdecl strcmp(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  size_t __cdecl strlen(ಧ್ರುವ ವರ್ಣ *_Str);
#ಯದಿ 0
  size_t __cdecl strnlen(ಧ್ರುವ ವರ್ಣ *_Str,size_t Max_ಎಣಿಕೆ);
#endif
  ಶೂನ್ಯ *__cdecl memmove(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,size_t _Size);
  _CRTIMP ವರ್ಣ *__cdecl _strdup(ಧ್ರುವ ವರ್ಣ *_Src);
  _CONST_RETURN ವರ್ಣ *__cdecl strchr(ಧ್ರುವ ವರ್ಣ *_Str,ಪೂರ್ಣಾಙ್ಕ _Val);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _stricmp(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strcmpi(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _stricmp_l(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl strcoll(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strcoll_l(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _stricoll(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _stricoll_l(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strncoll (ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strncoll_l(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strnicoll (ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strnicoll_l(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  size_t __cdecl strcspn(ಧ್ರುವ ವರ್ಣ *_Str,ಧ್ರುವ ವರ್ಣ *_Control);
  _CRTIMP ವರ್ಣ *__cdecl _strerror(ಧ್ರುವ ವರ್ಣ *Err_ಸಂದೇಶ);
  ವರ್ಣ *__cdecl strerror(ಪೂರ್ಣಾಙ್ಕ);
  _CRTIMP ವರ್ಣ *__cdecl _strlwr(ವರ್ಣ *_String);
  ವರ್ಣ *strlwr_l(ವರ್ಣ *_String,_locale_t _Locale);
  ವರ್ಣ *__cdecl strncat(ವರ್ಣ *_Dest,ಧ್ರುವ ವರ್ಣ *_Source,size_t ಎಣಿಕೆ_5);
  ಪೂರ್ಣಾಙ್ಕ __cdecl strncmp(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strnicmp(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _strnicmp_l(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ವರ್ಣ *strncpy(ವರ್ಣ *_Dest,ಧ್ರುವ ವರ್ಣ *_Source,size_t ಎಣಿಕೆ_5);
  _CRTIMP ವರ್ಣ *__cdecl _strnset(ವರ್ಣ *_Str,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CONST_RETURN ವರ್ಣ *__cdecl strpbrk(ಧ್ರುವ ವರ್ಣ *_Str,ಧ್ರುವ ವರ್ಣ *_Control);
  _CONST_RETURN ವರ್ಣ *__cdecl strrchr(ಧ್ರುವ ವರ್ಣ *_Str,ಪೂರ್ಣಾಙ್ಕ _Ch);
  _CRTIMP ವರ್ಣ *__cdecl _strrev(ವರ್ಣ *_Str);
  size_t __cdecl strspn(ಧ್ರುವ ವರ್ಣ *_Str,ಧ್ರುವ ವರ್ಣ *_Control);
  _CONST_RETURN ವರ್ಣ *__cdecl strstr(ಧ್ರುವ ವರ್ಣ *_Str,ಧ್ರುವ ವರ್ಣ *_SubStr);
  ವರ್ಣ *__cdecl strtok(ವರ್ಣ *_Str,ಧ್ರುವ ವರ್ಣ *_Delim);
  _CRTIMP ವರ್ಣ *__cdecl _strupr(ವರ್ಣ *_String);
  _CRTIMP ವರ್ಣ *_strupr_l(ವರ್ಣ *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(ವರ್ಣ *_Dst,ಧ್ರುವ ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP size_t __cdecl _strxfrm_l(ವರ್ಣ *_Dst,ಧ್ರುವ ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  ವರ್ಣ *__cdecl strdup(ಧ್ರುವ ವರ್ಣ *_Src);
  ಪೂರ್ಣಾಙ್ಕ __cdecl strcmpi(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  ಪೂರ್ಣಾಙ್ಕ __cdecl stricmp(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str2);
  ವರ್ಣ *__cdecl strlwr(ವರ್ಣ *_Str);
  ಪೂರ್ಣಾಙ್ಕ __cdecl strnicmp(ಧ್ರುವ ವರ್ಣ *_Str1,ಧ್ರುವ ವರ್ಣ *_Str,size_t Max_ಎಣಿಕೆ);
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl strncasecmp (ಧ್ರುವ ವರ್ಣ *__sz1, ಧ್ರುವ ವರ್ಣ *__sz2, size_t __sizeMaxCompare) { ಪ್ರತ್ಯಾಗಮ _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl strcasecmp (ಧ್ರುವ ವರ್ಣ *__sz1, ಧ್ರುವ ವರ್ಣ *__sz2) { ಪ್ರತ್ಯಾಗಮ _stricmp (__sz1, __sz2); }
  ವರ್ಣ *__cdecl strnset(ವರ್ಣ *_Str,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  ವರ್ಣ *__cdecl strrev(ವರ್ಣ *_Str);
  ವರ್ಣ *__cdecl strset(ವರ್ಣ *_Str,ಪೂರ್ಣಾಙ್ಕ _Val);
  ವರ್ಣ *__cdecl strupr(ವರ್ಣ *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ಧ್ರುವ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ಧ್ರುವ wchar_t *_Str,wchar_t _Ch);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcscmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source);
  size_t __cdecl wcscspn(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_Control);
  size_t __cdecl wcslen(ಧ್ರುವ wchar_t *_Str);
  size_t __cdecl wcsnlen(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ);
  wchar_t *wcsncat(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source,size_t ಎಣಿಕೆ_5);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsncmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  wchar_t *wcsncpy(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Source,size_t ಎಣಿಕೆ_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ಧ್ರುವ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ಧ್ರುವ wchar_t *_Str,ಧ್ರುವ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ಧ್ರುವ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(ಪೂರ್ಣಾಙ್ಕ Err_ಅಂಕೆ);
  _CRTIMP wchar_t *__cdecl __wcserror(ಧ್ರುವ wchar_t *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicmp_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicmp_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcscoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcscoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsicoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsncoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsncoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcsnicoll_l(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ಧ್ರುವ wchar_t *_Str);
#define wcswcs wcsstr
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsnicmp(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2,size_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ಎಣಿಕೆ);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wcsicoll(ಧ್ರುವ wchar_t *_Str1,ಧ್ರುವ wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#ಅನ್ತರ್ಭಾವ <sec_api/string_s.h>
#endif
