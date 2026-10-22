/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#અન્તર્ભાવ <_mingw.h>

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP શૂન્ય *__cdecl _memccpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CONST_RETURN શૂન્ય *__cdecl memchr(અચલ શૂન્ય *_Buf ,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _memicmp(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size);
  _CRTIMP પૂર્ણાંક __cdecl _memicmp_l(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size,_locale_t _Locale);
  પૂર્ણાંક __cdecl memcmp(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size);
  શૂન્ય *__cdecl memcpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,size_t _Size);
  શૂન્ય *__cdecl memset(શૂન્ય *_Dst,પૂર્ણાંક _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  શૂન્ય *__cdecl memccpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,પૂર્ણાંક _Val,size_t _Size);
  પૂર્ણાંક __cdecl memicmp(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size);
#endif
#endif
  અક્ષર *__cdecl _strset(અક્ષર *_Str,પૂર્ણાંક _Val);
  અક્ષર *__cdecl strcpy(અક્ષર *_Dest,અચલ અક્ષર *_Source);
  અક્ષર *__cdecl strcat(અક્ષર *_Dest,અચલ અક્ષર *_Source);
  પૂર્ણાંક __cdecl strcmp(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  size_t __cdecl strlen(અચલ અક્ષર *_Str);
#જો 0
  size_t __cdecl strnlen(અચલ અક્ષર *_Str,size_t Max_ગણતરી);
#endif
  શૂન્ય *__cdecl memmove(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,size_t _Size);
  _CRTIMP અક્ષર *__cdecl _strdup(અચલ અક્ષર *_Src);
  _CONST_RETURN અક્ષર *__cdecl strchr(અચલ અક્ષર *_Str,પૂર્ણાંક _Val);
  _CRTIMP પૂર્ણાંક __cdecl _stricmp(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _strcmpi(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _stricmp_l(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,_locale_t _Locale);
  પૂર્ણાંક __cdecl strcoll(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _strcoll_l(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _stricoll(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _stricoll_l(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _strncoll (અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _strncoll_l(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _strnicoll (અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _strnicoll_l(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  size_t __cdecl strcspn(અચલ અક્ષર *_Str,અચલ અક્ષર *_Control);
  _CRTIMP અક્ષર *__cdecl _strerror(અચલ અક્ષર *Err_સંદેશ);
  અક્ષર *__cdecl strerror(પૂર્ણાંક);
  _CRTIMP અક્ષર *__cdecl _strlwr(અક્ષર *_String);
  અક્ષર *strlwr_l(અક્ષર *_String,_locale_t _Locale);
  અક્ષર *__cdecl strncat(અક્ષર *_Dest,અચલ અક્ષર *_Source,size_t ગણતરી_5);
  પૂર્ણાંક __cdecl strncmp(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _strnicmp(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _strnicmp_l(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  અક્ષર *strncpy(અક્ષર *_Dest,અચલ અક્ષર *_Source,size_t ગણતરી_5);
  _CRTIMP અક્ષર *__cdecl _strnset(અક્ષર *_Str,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CONST_RETURN અક્ષર *__cdecl strpbrk(અચલ અક્ષર *_Str,અચલ અક્ષર *_Control);
  _CONST_RETURN અક્ષર *__cdecl strrchr(અચલ અક્ષર *_Str,પૂર્ણાંક _Ch);
  _CRTIMP અક્ષર *__cdecl _strrev(અક્ષર *_Str);
  size_t __cdecl strspn(અચલ અક્ષર *_Str,અચલ અક્ષર *_Control);
  _CONST_RETURN અક્ષર *__cdecl strstr(અચલ અક્ષર *_Str,અચલ અક્ષર *_SubStr);
  અક્ષર *__cdecl strtok(અક્ષર *_Str,અચલ અક્ષર *_Delim);
  _CRTIMP અક્ષર *__cdecl _strupr(અક્ષર *_String);
  _CRTIMP અક્ષર *_strupr_l(અક્ષર *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(અક્ષર *_Dst,અચલ અક્ષર *_Src,size_t Max_ગણતરી);
  _CRTIMP size_t __cdecl _strxfrm_l(અક્ષર *_Dst,અચલ અક્ષર *_Src,size_t Max_ગણતરી,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  અક્ષર *__cdecl strdup(અચલ અક્ષર *_Src);
  પૂર્ણાંક __cdecl strcmpi(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  પૂર્ણાંક __cdecl stricmp(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str2);
  અક્ષર *__cdecl strlwr(અક્ષર *_Str);
  પૂર્ણાંક __cdecl strnicmp(અચલ અક્ષર *_Str1,અચલ અક્ષર *_Str,size_t Max_ગણતરી);
  __CRT_INLINE પૂર્ણાંક __cdecl strncasecmp (અચલ અક્ષર *__sz1, અચલ અક્ષર *__sz2, size_t __sizeMaxCompare) { પાછા _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE પૂર્ણાંક __cdecl strcasecmp (અચલ અક્ષર *__sz1, અચલ અક્ષર *__sz2) { પાછા _stricmp (__sz1, __sz2); }
  અક્ષર *__cdecl strnset(અક્ષર *_Str,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  અક્ષર *__cdecl strrev(અક્ષર *_Str);
  અક્ષર *__cdecl strset(અક્ષર *_Str,પૂર્ણાંક _Val);
  અક્ષર *__cdecl strupr(અક્ષર *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(અચલ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,અચલ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(અચલ wchar_t *_Str,wchar_t _Ch);
  પૂર્ણાંક __cdecl wcscmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,અચલ wchar_t *_Source);
  size_t __cdecl wcscspn(અચલ wchar_t *_Str,અચલ wchar_t *_Control);
  size_t __cdecl wcslen(અચલ wchar_t *_Str);
  size_t __cdecl wcsnlen(અચલ wchar_t *_Src,size_t Max_ગણતરી);
  wchar_t *wcsncat(wchar_t *_Dest,અચલ wchar_t *_Source,size_t ગણતરી_5);
  પૂર્ણાંક __cdecl wcsncmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  wchar_t *wcsncpy(wchar_t *_Dest,અચલ wchar_t *_Source,size_t ગણતરી_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(અચલ wchar_t *_Str,અચલ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(અચલ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(અચલ wchar_t *_Str,અચલ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(અચલ wchar_t *_Str,અચલ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,અચલ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(પૂર્ણાંક Err_અંક);
  _CRTIMP wchar_t *__cdecl __wcserror(અચલ wchar_t *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicmp_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicmp_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ગણતરી);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,અચલ wchar_t *_Src,size_t Max_ગણતરી);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,અચલ wchar_t *_Src,size_t Max_ગણતરી,_locale_t _Locale);
  પૂર્ણાંક __cdecl wcscoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _wcscoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  _CRTIMP પૂર્ણાંક __cdecl _wcsicoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsncoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _wcsncoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી,_locale_t _Locale);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _wcsnicoll_l(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(અચલ wchar_t *_Str);
#define wcswcs wcsstr
  પૂર્ણાંક __cdecl wcsicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
  પૂર્ણાંક __cdecl wcsnicmp(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2,size_t Max_ગણતરી);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ગણતરી);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  પૂર્ણાંક __cdecl wcsicoll(અચલ wchar_t *_Str1,અચલ wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#અન્તર્ભાવ <sec_api/string_s.h>
#endif
