/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#அந்தர்பாவ <_mingw.h>

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP வெறுமை *__cdecl _memccpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,முழு _Val,size_t Max_மொத்தம்);
  _CONST_RETURN வெறுமை *__cdecl memchr(மாறிலி வெறுமை *_Buf ,முழு _Val,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _memicmp(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size);
  _CRTIMP முழு __cdecl _memicmp_l(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size,_locale_t _Locale);
  முழு __cdecl memcmp(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size);
  வெறுமை *__cdecl memcpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,size_t _Size);
  வெறுமை *__cdecl memset(வெறுமை *_Dst,முழு _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  வெறுமை *__cdecl memccpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,முழு _Val,size_t _Size);
  முழு __cdecl memicmp(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size);
#endif
#endif
  எழுத்து *__cdecl _strset(எழுத்து *_Str,முழு _Val);
  எழுத்து *__cdecl strcpy(எழுத்து *_Dest,மாறிலி எழுத்து *_Source);
  எழுத்து *__cdecl strcat(எழுத்து *_Dest,மாறிலி எழுத்து *_Source);
  முழு __cdecl strcmp(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  size_t __cdecl strlen(மாறிலி எழுத்து *_Str);
#எனில் 0
  size_t __cdecl strnlen(மாறிலி எழுத்து *_Str,size_t Max_மொத்தம்);
#endif
  வெறுமை *__cdecl memmove(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,size_t _Size);
  _CRTIMP எழுத்து *__cdecl _strdup(மாறிலி எழுத்து *_Src);
  _CONST_RETURN எழுத்து *__cdecl strchr(மாறிலி எழுத்து *_Str,முழு _Val);
  _CRTIMP முழு __cdecl _stricmp(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  _CRTIMP முழு __cdecl _strcmpi(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  _CRTIMP முழு __cdecl _stricmp_l(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,_locale_t _Locale);
  முழு __cdecl strcoll(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  _CRTIMP முழு __cdecl _strcoll_l(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _stricoll(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  _CRTIMP முழு __cdecl _stricoll_l(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _strncoll (மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _strncoll_l(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP முழு __cdecl _strnicoll (மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _strnicoll_l(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  size_t __cdecl strcspn(மாறிலி எழுத்து *_Str,மாறிலி எழுத்து *_Control);
  _CRTIMP எழுத்து *__cdecl _strerror(மாறிலி எழுத்து *Err_செய்தி);
  எழுத்து *__cdecl strerror(முழு);
  _CRTIMP எழுத்து *__cdecl _strlwr(எழுத்து *_String);
  எழுத்து *strlwr_l(எழுத்து *_String,_locale_t _Locale);
  எழுத்து *__cdecl strncat(எழுத்து *_Dest,மாறிலி எழுத்து *_Source,size_t மொத்தம்_5);
  முழு __cdecl strncmp(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _strnicmp(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _strnicmp_l(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  எழுத்து *strncpy(எழுத்து *_Dest,மாறிலி எழுத்து *_Source,size_t மொத்தம்_5);
  _CRTIMP எழுத்து *__cdecl _strnset(எழுத்து *_Str,முழு _Val,size_t Max_மொத்தம்);
  _CONST_RETURN எழுத்து *__cdecl strpbrk(மாறிலி எழுத்து *_Str,மாறிலி எழுத்து *_Control);
  _CONST_RETURN எழுத்து *__cdecl strrchr(மாறிலி எழுத்து *_Str,முழு _Ch);
  _CRTIMP எழுத்து *__cdecl _strrev(எழுத்து *_Str);
  size_t __cdecl strspn(மாறிலி எழுத்து *_Str,மாறிலி எழுத்து *_Control);
  _CONST_RETURN எழுத்து *__cdecl strstr(மாறிலி எழுத்து *_Str,மாறிலி எழுத்து *_SubStr);
  எழுத்து *__cdecl strtok(எழுத்து *_Str,மாறிலி எழுத்து *_Delim);
  _CRTIMP எழுத்து *__cdecl _strupr(எழுத்து *_String);
  _CRTIMP எழுத்து *_strupr_l(எழுத்து *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(எழுத்து *_Dst,மாறிலி எழுத்து *_Src,size_t Max_மொத்தம்);
  _CRTIMP size_t __cdecl _strxfrm_l(எழுத்து *_Dst,மாறிலி எழுத்து *_Src,size_t Max_மொத்தம்,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  எழுத்து *__cdecl strdup(மாறிலி எழுத்து *_Src);
  முழு __cdecl strcmpi(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  முழு __cdecl stricmp(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str2);
  எழுத்து *__cdecl strlwr(எழுத்து *_Str);
  முழு __cdecl strnicmp(மாறிலி எழுத்து *_Str1,மாறிலி எழுத்து *_Str,size_t Max_மொத்தம்);
  __CRT_INLINE முழு __cdecl strncasecmp (மாறிலி எழுத்து *__sz1, மாறிலி எழுத்து *__sz2, size_t __sizeMaxCompare) { திரும்பு _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE முழு __cdecl strcasecmp (மாறிலி எழுத்து *__sz1, மாறிலி எழுத்து *__sz2) { திரும்பு _stricmp (__sz1, __sz2); }
  எழுத்து *__cdecl strnset(எழுத்து *_Str,முழு _Val,size_t Max_மொத்தம்);
  எழுத்து *__cdecl strrev(எழுத்து *_Str);
  எழுத்து *__cdecl strset(எழுத்து *_Str,முழு _Val);
  எழுத்து *__cdecl strupr(எழுத்து *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(மாறிலி wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,மாறிலி wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(மாறிலி wchar_t *_Str,wchar_t _Ch);
  முழு __cdecl wcscmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,மாறிலி wchar_t *_Source);
  size_t __cdecl wcscspn(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_Control);
  size_t __cdecl wcslen(மாறிலி wchar_t *_Str);
  size_t __cdecl wcsnlen(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்);
  wchar_t *wcsncat(wchar_t *_Dest,மாறிலி wchar_t *_Source,size_t மொத்தம்_5);
  முழு __cdecl wcsncmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  wchar_t *wcsncpy(wchar_t *_Dest,மாறிலி wchar_t *_Source,size_t மொத்தம்_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(மாறிலி wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(மாறிலி wchar_t *_Str,மாறிலி wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,மாறிலி wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(முழு Err_இலக்கம்);
  _CRTIMP wchar_t *__cdecl __wcserror(மாறிலி wchar_t *_Str);
  _CRTIMP முழு __cdecl _wcsicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  _CRTIMP முழு __cdecl _wcsicmp_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsnicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _wcsnicmp_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_மொத்தம்);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,மாறிலி wchar_t *_Src,size_t Max_மொத்தம்);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,_locale_t _Locale);
  முழு __cdecl wcscoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  _CRTIMP முழு __cdecl _wcscoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsicoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  _CRTIMP முழு __cdecl _wcsicoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsncoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _wcsncoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);
  _CRTIMP முழு __cdecl _wcsnicoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _wcsnicoll_l(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(மாறிலி wchar_t *_Str);
#define wcswcs wcsstr
  முழு __cdecl wcsicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
  முழு __cdecl wcsnicmp(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2,size_t Max_மொத்தம்);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_மொத்தம்);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  முழு __cdecl wcsicoll(மாறிலி wchar_t *_Str1,மாறிலி wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#அந்தர்பாவ <sec_api/string_s.h>
#endif
