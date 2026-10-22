/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STRING
#define _INC_STRING

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _NLSCMP_DEFINED
#define _NLSCMP_DEFINED
#define _NLSCMPERROR 2147483647
#endif

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
#endif
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP ଶୂନ୍ୟ *__cdecl _memccpy(ଶୂନ୍ୟ *_Dst,ଅଚଳ ଶୂନ୍ୟ *_Src,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା);
  _CONST_RETURN ଶୂନ୍ୟ *__cdecl memchr(ଅଚଳ ଶୂନ୍ୟ *_Buf ,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _memicmp(ଅଚଳ ଶୂନ୍ୟ *_Buf1,ଅଚଳ ଶୂନ୍ୟ *_Buf2,size_t _Size);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _memicmp_l(ଅଚଳ ଶୂନ୍ୟ *_Buf1,ଅଚଳ ଶୂନ୍ୟ *_Buf2,size_t _Size,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl memcmp(ଅଚଳ ଶୂନ୍ୟ *_Buf1,ଅଚଳ ଶୂନ୍ୟ *_Buf2,size_t _Size);
  ଶୂନ୍ୟ *__cdecl memcpy(ଶୂନ୍ୟ *_Dst,ଅଚଳ ଶୂନ୍ୟ *_Src,size_t _Size);
  ଶୂନ୍ୟ *__cdecl memset(ଶୂନ୍ୟ *_Dst,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t _Size);
#ifndef	NO_OLDNAMES
  ଶୂନ୍ୟ *__cdecl memccpy(ଶୂନ୍ୟ *_Dst,ଅଚଳ ଶୂନ୍ୟ *_Src,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t _Size);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl memicmp(ଅଚଳ ଶୂନ୍ୟ *_Buf1,ଅଚଳ ଶୂନ୍ୟ *_Buf2,size_t _Size);
#endif
#endif
  ଅକ୍ଷର *__cdecl _strset(ଅକ୍ଷର *_Str,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val);
  ଅକ୍ଷର *__cdecl strcpy(ଅକ୍ଷର *_Dest,ଅଚଳ ଅକ୍ଷର *_Source);
  ଅକ୍ଷର *__cdecl strcat(ଅକ୍ଷର *_Dest,ଅଚଳ ଅକ୍ଷର *_Source);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strcmp(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  size_t __cdecl strlen(ଅଚଳ ଅକ୍ଷର *_Str);
#ଯଦି 0
  size_t __cdecl strnlen(ଅଚଳ ଅକ୍ଷର *_Str,size_t Max_ଗଣନା);
#endif
  ଶୂନ୍ୟ *__cdecl memmove(ଶୂନ୍ୟ *_Dst,ଅଚଳ ଶୂନ୍ୟ *_Src,size_t _Size);
  _CRTIMP ଅକ୍ଷର *__cdecl _strdup(ଅଚଳ ଅକ୍ଷର *_Src);
  _CONST_RETURN ଅକ୍ଷର *__cdecl strchr(ଅଚଳ ଅକ୍ଷର *_Str,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _stricmp(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strcmpi(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _stricmp_l(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strcoll(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strcoll_l(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _stricoll(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _stricoll_l(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strncoll (ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strncoll_l(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strnicoll (ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strnicoll_l(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  size_t __cdecl strcspn(ଅଚଳ ଅକ୍ଷର *_Str,ଅଚଳ ଅକ୍ଷର *_Control);
  _CRTIMP ଅକ୍ଷର *__cdecl _strerror(ଅଚଳ ଅକ୍ଷର *Err_ସନ୍ଦେଶ);
  ଅକ୍ଷର *__cdecl strerror(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  _CRTIMP ଅକ୍ଷର *__cdecl _strlwr(ଅକ୍ଷର *_String);
  ଅକ୍ଷର *strlwr_l(ଅକ୍ଷର *_String,_locale_t _Locale);
  ଅକ୍ଷର *__cdecl strncat(ଅକ୍ଷର *_Dest,ଅଚଳ ଅକ୍ଷର *_Source,size_t ଗଣନା_6);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strncmp(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strnicmp(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _strnicmp_l(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  ଅକ୍ଷର *strncpy(ଅକ୍ଷର *_Dest,ଅଚଳ ଅକ୍ଷର *_Source,size_t ଗଣନା_6);
  _CRTIMP ଅକ୍ଷର *__cdecl _strnset(ଅକ୍ଷର *_Str,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା);
  _CONST_RETURN ଅକ୍ଷର *__cdecl strpbrk(ଅଚଳ ଅକ୍ଷର *_Str,ଅଚଳ ଅକ୍ଷର *_Control);
  _CONST_RETURN ଅକ୍ଷର *__cdecl strrchr(ଅଚଳ ଅକ୍ଷର *_Str,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  _CRTIMP ଅକ୍ଷର *__cdecl _strrev(ଅକ୍ଷର *_Str);
  size_t __cdecl strspn(ଅଚଳ ଅକ୍ଷର *_Str,ଅଚଳ ଅକ୍ଷର *_Control);
  _CONST_RETURN ଅକ୍ଷର *__cdecl strstr(ଅଚଳ ଅକ୍ଷର *_Str,ଅଚଳ ଅକ୍ଷର *_SubStr);
  ଅକ୍ଷର *__cdecl strtok(ଅକ୍ଷର *_Str,ଅଚଳ ଅକ୍ଷର *_Delim);
  _CRTIMP ଅକ୍ଷର *__cdecl _strupr(ଅକ୍ଷର *_String);
  _CRTIMP ଅକ୍ଷର *_strupr_l(ଅକ୍ଷର *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(ଅକ୍ଷର *_Dst,ଅଚଳ ଅକ୍ଷର *_Src,size_t Max_ଗଣନା);
  _CRTIMP size_t __cdecl _strxfrm_l(ଅକ୍ଷର *_Dst,ଅଚଳ ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  ଅକ୍ଷର *__cdecl strdup(ଅଚଳ ଅକ୍ଷର *_Src);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strcmpi(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl stricmp(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str2);
  ଅକ୍ଷର *__cdecl strlwr(ଅକ୍ଷର *_Str);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strnicmp(ଅଚଳ ଅକ୍ଷର *_Str1,ଅଚଳ ଅକ୍ଷର *_Str,size_t Max_ଗଣନା);
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strncasecmp (ଅଚଳ ଅକ୍ଷର *__sz1, ଅଚଳ ଅକ୍ଷର *__sz2, size_t __sizeMaxCompare) { ଫେରନ୍ତୁ _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl strcasecmp (ଅଚଳ ଅକ୍ଷର *__sz1, ଅଚଳ ଅକ୍ଷର *__sz2) { ଫେରନ୍ତୁ _stricmp (__sz1, __sz2); }
  ଅକ୍ଷର *__cdecl strnset(ଅକ୍ଷର *_Str,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val,size_t Max_ଗଣନା);
  ଅକ୍ଷର *__cdecl strrev(ଅକ୍ଷର *_Str);
  ଅକ୍ଷର *__cdecl strset(ଅକ୍ଷର *_Str,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Val);
  ଅକ୍ଷର *__cdecl strupr(ଅକ୍ଷର *_Str);
#endif

#ifndef _WSTRING_DEFINED
#define _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ଅଚଳ wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ଅଚଳ wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(ଅଚଳ wchar_t *_Str,wchar_t _Ch);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcscmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ଅଚଳ wchar_t *_Source);
  size_t __cdecl wcscspn(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_Control);
  size_t __cdecl wcslen(ଅଚଳ wchar_t *_Str);
  size_t __cdecl wcsnlen(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା);
  wchar_t *wcsncat(wchar_t *_Dest,ଅଚଳ wchar_t *_Source,size_t ଗଣନା_6);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsncmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  wchar_t *wcsncpy(wchar_t *_Dest,ଅଚଳ wchar_t *_Source,size_t ଗଣନା_6);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ଅଚଳ wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ଅଚଳ wchar_t *_Str,ଅଚଳ wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ଅଚଳ wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(ପୂର୍ଣ୍ଣସଂଖ୍ୟା Err_ଅଙ୍କ);
  _CRTIMP wchar_t *__cdecl __wcserror(ଅଚଳ wchar_t *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicmp_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicmp_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ଗଣନା);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcscoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcscoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsicoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsncoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsncoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcsnicoll_l(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା,_locale_t _Locale);

#ifndef	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ଅଚଳ wchar_t *_Str);
#define wcswcs wcsstr
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsnicmp(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2,size_t Max_ଗଣନା);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t Max_ଗଣନା);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wcsicoll(ଅଚଳ wchar_t *_Str1,ଅଚଳ wchar_t *_Str2);
#endif
#endif

#ifdef __cplusplus
}
#endif

#ଅନ୍ତର୍ଭାଵ <sec_api/string_s.h>
#endif
