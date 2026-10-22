/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_STRING
#تعریف_کن _INC_STRING

#ضمن <_mingw.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _NLSCMP_DEFINED
#تعریف_کن _NLSCMP_DEFINED
#تعریف_کن _NLSCMPERROR 2147483647
#پایان_اگر

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#تعریف_کن _WConst_return _CONST_RETURN

#اگر_تعریف_نشده CRT_حافظه_DEFINED
#تعریف_کن CRT_حافظه_DEFINED
  _CRTIMP فراغ *__cdecl _memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,اندازه_t Max_شمار);
  _CONST_RETURN فراغ *__cdecl memchr(ثابت فراغ *_Buf ,صحيح _Val,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4);
  _CRTIMP صحيح __cdecl _memicmp_l(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4,_locale_t _Locale);
  صحيح __cdecl memcmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4);
  فراغ *__cdecl کپی_حافظه(فراغ *_Dst,ثابت فراغ *_Src,اندازه_t اندازه_4);
  فراغ *__cdecl memset(فراغ *_Dst,صحيح _Val,اندازه_t اندازه_4);
#اگر_تعریف_نشده	NO_OLDNAMES
  فراغ *__cdecl memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,اندازه_t اندازه_4);
  صحيح __cdecl memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4);
#پایان_اگر
#پایان_اگر
  حرف *__cdecl _strset(حرف *_Str,صحيح _Val);
  حرف *__cdecl strcpy(حرف *_Dest,ثابت حرف *منبع_3);
  حرف *__cdecl strcat(حرف *_Dest,ثابت حرف *منبع_3);
  صحيح __cdecl strcmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  اندازه_t __cdecl طول_رشته(ثابت حرف *_Str);
#إذا 0
  اندازه_t __cdecl strnlen(ثابت حرف *_Str,اندازه_t Max_شمار);
#پایان_اگر
  فراغ *__cdecl memmove(فراغ *_Dst,ثابت فراغ *_Src,اندازه_t اندازه_4);
  _CRTIMP حرف *__cdecl _strdup(ثابت حرف *_Src);
  _CONST_RETURN حرف *__cdecl strchr(ثابت حرف *_Str,صحيح _Val);
  _CRTIMP صحيح __cdecl _stricmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _strcmpi(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _stricmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  صحيح __cdecl strcoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _strcoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _stricoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحيح __cdecl _stricoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _strncoll (ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _strncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _strnicoll (ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _strnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  اندازه_t __cdecl strcspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _strerror(ثابت حرف *Err_پیام);
  حرف *__cdecl strerror(صحيح);
  _CRTIMP حرف *__cdecl _strlwr(حرف *_String);
  حرف *strlwr_l(حرف *_String,_locale_t _Locale);
  حرف *__cdecl strncat(حرف *_Dest,ثابت حرف *منبع_3,اندازه_t شمار_5);
  صحيح __cdecl مقایسه_رشته(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _strnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _strnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  حرف *strncpy(حرف *_Dest,ثابت حرف *منبع_3,اندازه_t شمار_5);
  _CRTIMP حرف *__cdecl _strnset(حرف *_Str,صحيح _Val,اندازه_t Max_شمار);
  _CONST_RETURN حرف *__cdecl strpbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CONST_RETURN حرف *__cdecl strrchr(ثابت حرف *_Str,صحيح _Ch);
  _CRTIMP حرف *__cdecl _strrev(حرف *_Str);
  اندازه_t __cdecl strspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CONST_RETURN حرف *__cdecl جستجوی_رشته(ثابت حرف *_Str,ثابت حرف *_SubStr);
  حرف *__cdecl strtok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _strupr(حرف *_String);
  _CRTIMP حرف *_strupr_l(حرف *_String,_locale_t _Locale);
  اندازه_t __cdecl strxfrm(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _strxfrm_l(حرف *_Dst,ثابت حرف *_Src,اندازه_t Max_شمار,_locale_t _Locale);

#اگر_تعریف_نشده	NO_OLDNAMES
  حرف *__cdecl strdup(ثابت حرف *_Src);
  صحيح __cdecl strcmpi(ثابت حرف *_Str1,ثابت حرف *_Str2);
  صحيح __cdecl stricmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  حرف *__cdecl strlwr(حرف *_Str);
  صحيح __cdecl strnicmp(ثابت حرف *_Str1,ثابت حرف *_Str,اندازه_t Max_شمار);
  __CRT_INLINE صحيح __cdecl strncasecmp (ثابت حرف *__sz1, ثابت حرف *__sz2, اندازه_t __sizeMaxCompare) { أرجع _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE صحيح __cdecl strcasecmp (ثابت حرف *__sz1, ثابت حرف *__sz2) { أرجع _stricmp (__sz1, __sz2); }
  حرف *__cdecl strnset(حرف *_Str,صحيح _Val,اندازه_t Max_شمار);
  حرف *__cdecl strrev(حرف *_Str);
  حرف *__cdecl strset(حرف *_Str,صحيح _Val);
  حرف *__cdecl strupr(حرف *_Str);
#پایان_اگر

#اگر_تعریف_نشده _WSTRING_DEFINED
#تعریف_کن _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *منبع_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحيح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *منبع_3);
  اندازه_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  اندازه_t __cdecl wcslen(ثابت wchar_t *_Str);
  اندازه_t __cdecl wcsnlen(ثابت wchar_t *_Src,اندازه_t Max_شمار);
  wchar_t *wcsncat(wchar_t *_Dest,ثابت wchar_t *منبع_3,اندازه_t شمار_5);
  صحيح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  wchar_t *wcsncpy(wchar_t *_Dest,ثابت wchar_t *منبع_3,اندازه_t شمار_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  اندازه_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحيح Err_رقم);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحيح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,اندازه_t Max_شمار);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  اندازه_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,اندازه_t Max_شمار);
  _CRTIMP اندازه_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,اندازه_t Max_شمار,_locale_t _Locale);
  صحيح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحيح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  _CRTIMP صحيح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار,_locale_t _Locale);

#اگر_تعریف_نشده	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#تعریف_کن wcswcs wcsstr
  صحيح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحيح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,اندازه_t Max_شمار);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,اندازه_t Max_شمار);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحيح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#ضمن <sec_api/string_s.h>
#پایان_اگر
