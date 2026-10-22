/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#അന്തര്ഭാവ <_mingw.h>

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP ശൂന്യം *__cdecl _memccpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CONST_RETURN ശൂന്യം *__cdecl memchr(സ്ഥിരം ശൂന്യം *_Buf ,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _memicmp(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _memicmp_l(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl memcmp(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size);
  ശൂന്യം *__cdecl memcpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,size_t _Size);
  ശൂന്യം *__cdecl memset(ശൂന്യം *_Dst,പൂർണ്ണസംഖ്യ _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  ശൂന്യം *__cdecl memccpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,പൂർണ്ണസംഖ്യ _Val,size_t _Size);
  പൂർണ്ണസംഖ്യ __cdecl memicmp(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size);
#endif
#endif
  അക്ഷരം *__cdecl _strset(അക്ഷരം *_Str,പൂർണ്ണസംഖ്യ _Val);
  അക്ഷരം *__cdecl strcpy(അക്ഷരം *_Dest,സ്ഥിരം അക്ഷരം *_Source);
  അക്ഷരം *__cdecl strcat(അക്ഷരം *_Dest,സ്ഥിരം അക്ഷരം *_Source);
  പൂർണ്ണസംഖ്യ __cdecl strcmp(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  size_t __cdecl strlen(സ്ഥിരം അക്ഷരം *_Str);
#എങ്കിൽ 0
  size_t __cdecl strnlen(സ്ഥിരം അക്ഷരം *_Str,size_t Max_എണ്ണം);
#endif
  ശൂന്യം *__cdecl memmove(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,size_t _Size);
  _CRTIMP അക്ഷരം *__cdecl _strdup(സ്ഥിരം അക്ഷരം *_Src);
  _CONST_RETURN അക്ഷരം *__cdecl strchr(സ്ഥിരം അക്ഷരം *_Str,പൂർണ്ണസംഖ്യ _Val);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _stricmp(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strcmpi(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _stricmp_l(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl strcoll(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strcoll_l(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _stricoll(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _stricoll_l(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strncoll (സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strncoll_l(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strnicoll (സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strnicoll_l(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  size_t __cdecl strcspn(സ്ഥിരം അക്ഷരം *_Str,സ്ഥിരം അക്ഷരം *_Control);
  _CRTIMP അക്ഷരം *__cdecl _strerror(സ്ഥിരം അക്ഷരം *Err_സന്ദേശം);
  അക്ഷരം *__cdecl strerror(പൂർണ്ണസംഖ്യ);
  _CRTIMP അക്ഷരം *__cdecl _strlwr(അക്ഷരം *_String);
  അക്ഷരം *strlwr_l(അക്ഷരം *_String,_locale_t _Locale);
  അക്ഷരം *__cdecl strncat(അക്ഷരം *_Dest,സ്ഥിരം അക്ഷരം *_Source,size_t എണ്ണം_5);
  പൂർണ്ണസംഖ്യ __cdecl strncmp(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strnicmp(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _strnicmp_l(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  അക്ഷരം *strncpy(അക്ഷരം *_Dest,സ്ഥിരം അക്ഷരം *_Source,size_t എണ്ണം_5);
  _CRTIMP അക്ഷരം *__cdecl _strnset(അക്ഷരം *_Str,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CONST_RETURN അക്ഷരം *__cdecl strpbrk(സ്ഥിരം അക്ഷരം *_Str,സ്ഥിരം അക്ഷരം *_Control);
  _CONST_RETURN അക്ഷരം *__cdecl strrchr(സ്ഥിരം അക്ഷരം *_Str,പൂർണ്ണസംഖ്യ _Ch);
  _CRTIMP അക്ഷരം *__cdecl _strrev(അക്ഷരം *_Str);
  size_t __cdecl strspn(സ്ഥിരം അക്ഷരം *_Str,സ്ഥിരം അക്ഷരം *_Control);
  _CONST_RETURN അക്ഷരം *__cdecl strstr(സ്ഥിരം അക്ഷരം *_Str,സ്ഥിരം അക്ഷരം *_SubStr);
  അക്ഷരം *__cdecl strtok(അക്ഷരം *_Str,സ്ഥിരം അക്ഷരം *_Delim);
  _CRTIMP അക്ഷരം *__cdecl _strupr(അക്ഷരം *_String);
  _CRTIMP അക്ഷരം *_strupr_l(അക്ഷരം *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(അക്ഷരം *_Dst,സ്ഥിരം അക്ഷരം *_Src,size_t Max_എണ്ണം);
  _CRTIMP size_t __cdecl _strxfrm_l(അക്ഷരം *_Dst,സ്ഥിരം അക്ഷരം *_Src,size_t Max_എണ്ണം,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  അക്ഷരം *__cdecl strdup(സ്ഥിരം അക്ഷരം *_Src);
  പൂർണ്ണസംഖ്യ __cdecl strcmpi(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  പൂർണ്ണസംഖ്യ __cdecl stricmp(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str2);
  അക്ഷരം *__cdecl strlwr(അക്ഷരം *_Str);
  പൂർണ്ണസംഖ്യ __cdecl strnicmp(സ്ഥിരം അക്ഷരം *_Str1,സ്ഥിരം അക്ഷരം *_Str,size_t Max_എണ്ണം);
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl strncasecmp (സ്ഥിരം അക്ഷരം *__sz1, സ്ഥിരം അക്ഷരം *__sz2, size_t __sizeMaxCompare) { തിരികെ _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl strcasecmp (സ്ഥിരം അക്ഷരം *__sz1, സ്ഥിരം അക്ഷരം *__sz2) { തിരികെ _stricmp (__sz1, __sz2); }
  അക്ഷരം *__cdecl strnset(അക്ഷരം *_Str,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  അക്ഷരം *__cdecl strrev(അക്ഷരം *_Str);
  അക്ഷരം *__cdecl strset(അക്ഷരം *_Str,പൂർണ്ണസംഖ്യ _Val);
  അക്ഷരം *__cdecl strupr(അക്ഷരം *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(സ്ഥിരം wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(സ്ഥിരം wchar_t *_Str,wchar_t _Ch);
  പൂർണ്ണസംഖ്യ __cdecl wcscmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source);
  size_t __cdecl wcscspn(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_Control);
  size_t __cdecl wcslen(സ്ഥിരം wchar_t *_Str);
  size_t __cdecl wcsnlen(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം);
  wchar_t *wcsncat(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source,size_t എണ്ണം_5);
  പൂർണ്ണസംഖ്യ __cdecl wcsncmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  wchar_t *wcsncpy(wchar_t *_Dest,സ്ഥിരം wchar_t *_Source,size_t എണ്ണം_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(സ്ഥിരം wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(സ്ഥിരം wchar_t *_Str,സ്ഥിരം wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,സ്ഥിരം wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(പൂർണ്ണസംഖ്യ Err_അക്കം);
  _CRTIMP wchar_t *__cdecl __wcserror(സ്ഥിരം wchar_t *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicmp_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicmp_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_എണ്ണം);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl wcscoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcscoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsicoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsncoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsncoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcsnicoll_l(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(സ്ഥിരം wchar_t *_Str);
#define wcswcs wcsstr
  പൂർണ്ണസംഖ്യ __cdecl wcsicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
  പൂർണ്ണസംഖ്യ __cdecl wcsnicmp(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2,size_t Max_എണ്ണം);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_എണ്ണം);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  പൂർണ്ണസംഖ്യ __cdecl wcsicoll(സ്ഥിരം wchar_t *_Str1,സ്ഥിരം wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#അന്തര്ഭാവ <sec_api/string_s.h>
#endif
