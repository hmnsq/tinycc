/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STRING
#تعریف_کرو _INC_STRING

#شامل <_mingw.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _NLSCMP_DEFINED
#تعریف_کرو _NLSCMP_DEFINED
#تعریف_کرو _NLSCMPERROR 2147483647
#اگر_ختم

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#تعریف_کرو _WConst_return _CONST_RETURN

#اگر_غیر_تعریف_شدہ CRT_حافظہ_DEFINED
#تعریف_کرو CRT_حافظہ_DEFINED
  _CRTIMP خالی *__cdecl _memccpy(خالی *_Dst,ثابت خالی *_Src,صحیح _Val,سائز_t Max_گنتی);
  _CONST_RETURN خالی *__cdecl memchr(ثابت خالی *_Buf ,صحیح _Val,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _memicmp(ثابت خالی *_Buf1,ثابت خالی *_Buf2,سائز_t سائز_4);
  _CRTIMP صحیح __cdecl _memicmp_l(ثابت خالی *_Buf1,ثابت خالی *_Buf2,سائز_t سائز_4,_locale_t _Locale);
  صحیح __cdecl memcmp(ثابت خالی *_Buf1,ثابت خالی *_Buf2,سائز_t سائز_4);
  خالی *__cdecl حافظہ_نقل(خالی *_Dst,ثابت خالی *_Src,سائز_t سائز_4);
  خالی *__cdecl memset(خالی *_Dst,صحیح _Val,سائز_t سائز_4);
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  خالی *__cdecl memccpy(خالی *_Dst,ثابت خالی *_Src,صحیح _Val,سائز_t سائز_4);
  صحیح __cdecl memicmp(ثابت خالی *_Buf1,ثابت خالی *_Buf2,سائز_t سائز_4);
#اگر_ختم
#اگر_ختم
  حرف *__cdecl _strset(حرف *_Str,صحیح _Val);
  حرف *__cdecl strcpy(حرف *_Dest,ثابت حرف *ماخذ_3);
  حرف *__cdecl strcat(حرف *_Dest,ثابت حرف *ماخذ_3);
  صحیح __cdecl strcmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  سائز_t __cdecl لڑی_لمبائی(ثابت حرف *_Str);
#اگر 0
  سائز_t __cdecl strnlen(ثابت حرف *_Str,سائز_t Max_گنتی);
#اگر_ختم
  خالی *__cdecl memmove(خالی *_Dst,ثابت خالی *_Src,سائز_t سائز_4);
  _CRTIMP حرف *__cdecl _strdup(ثابت حرف *_Src);
  _CONST_RETURN حرف *__cdecl strchr(ثابت حرف *_Str,صحیح _Val);
  _CRTIMP صحیح __cdecl _stricmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _strcmpi(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _stricmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  صحیح __cdecl strcoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _strcoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _stricoll(ثابت حرف *_Str1,ثابت حرف *_Str2);
  _CRTIMP صحیح __cdecl _stricoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _strncoll (ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _strncoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _strnicoll (ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _strnicoll_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  سائز_t __cdecl strcspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CRTIMP حرف *__cdecl _strerror(ثابت حرف *Err_پیغام);
  حرف *__cdecl strerror(صحیح);
  _CRTIMP حرف *__cdecl _strlwr(حرف *_String);
  حرف *strlwr_l(حرف *_String,_locale_t _Locale);
  حرف *__cdecl strncat(حرف *_Dest,ثابت حرف *ماخذ_3,سائز_t گنتی_5);
  صحیح __cdecl لڑی_موازنہ(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _strnicmp(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _strnicmp_l(ثابت حرف *_Str1,ثابت حرف *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  حرف *strncpy(حرف *_Dest,ثابت حرف *ماخذ_3,سائز_t گنتی_5);
  _CRTIMP حرف *__cdecl _strnset(حرف *_Str,صحیح _Val,سائز_t Max_گنتی);
  _CONST_RETURN حرف *__cdecl strpbrk(ثابت حرف *_Str,ثابت حرف *_Control);
  _CONST_RETURN حرف *__cdecl strrchr(ثابت حرف *_Str,صحیح _Ch);
  _CRTIMP حرف *__cdecl _strrev(حرف *_Str);
  سائز_t __cdecl strspn(ثابت حرف *_Str,ثابت حرف *_Control);
  _CONST_RETURN حرف *__cdecl لڑی_تلاش(ثابت حرف *_Str,ثابت حرف *_SubStr);
  حرف *__cdecl strtok(حرف *_Str,ثابت حرف *_Delim);
  _CRTIMP حرف *__cdecl _strupr(حرف *_String);
  _CRTIMP حرف *_strupr_l(حرف *_String,_locale_t _Locale);
  سائز_t __cdecl strxfrm(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _strxfrm_l(حرف *_Dst,ثابت حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  حرف *__cdecl strdup(ثابت حرف *_Src);
  صحیح __cdecl strcmpi(ثابت حرف *_Str1,ثابت حرف *_Str2);
  صحیح __cdecl stricmp(ثابت حرف *_Str1,ثابت حرف *_Str2);
  حرف *__cdecl strlwr(حرف *_Str);
  صحیح __cdecl strnicmp(ثابت حرف *_Str1,ثابت حرف *_Str,سائز_t Max_گنتی);
  __CRT_INLINE صحیح __cdecl strncasecmp (ثابت حرف *__sz1, ثابت حرف *__sz2, سائز_t __sizeMaxCompare) { واپس _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE صحیح __cdecl strcasecmp (ثابت حرف *__sz1, ثابت حرف *__sz2) { واپس _stricmp (__sz1, __sz2); }
  حرف *__cdecl strnset(حرف *_Str,صحیح _Val,سائز_t Max_گنتی);
  حرف *__cdecl strrev(حرف *_Str);
  حرف *__cdecl strset(حرف *_Str,صحیح _Val);
  حرف *__cdecl strupr(حرف *_Str);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTRING_DEFINED
#تعریف_کرو _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(ثابت wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,ثابت wchar_t *ماخذ_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(ثابت wchar_t *_Str,wchar_t _Ch);
  صحیح __cdecl wcscmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,ثابت wchar_t *ماخذ_3);
  سائز_t __cdecl wcscspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  سائز_t __cdecl wcslen(ثابت wchar_t *_Str);
  سائز_t __cdecl wcsnlen(ثابت wchar_t *_Src,سائز_t Max_گنتی);
  wchar_t *wcsncat(wchar_t *_Dest,ثابت wchar_t *ماخذ_3,سائز_t گنتی_5);
  صحیح __cdecl wcsncmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  wchar_t *wcsncpy(wchar_t *_Dest,ثابت wchar_t *ماخذ_3,سائز_t گنتی_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(ثابت wchar_t *_Str,wchar_t _Ch);
  سائز_t __cdecl wcsspn(ثابت wchar_t *_Str,ثابت wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(ثابت wchar_t *_Str,ثابت wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,ثابت wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(صحیح Err_عدد);
  _CRTIMP wchar_t *__cdecl __wcserror(ثابت wchar_t *_Str);
  _CRTIMP صحیح __cdecl _wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _wcsnicmp_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,سائز_t Max_گنتی);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  سائز_t __cdecl wcsxfrm(wchar_t *_Dst,ثابت wchar_t *_Src,سائز_t Max_گنتی);
  _CRTIMP سائز_t __cdecl _wcsxfrm_l(wchar_t *_Dst,ثابت wchar_t *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  صحیح __cdecl wcscoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcscoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  _CRTIMP صحیح __cdecl _wcsicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsncoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _wcsncoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _wcsnicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  _CRTIMP صحیح __cdecl _wcsnicoll_l(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی,_locale_t _Locale);

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(ثابت wchar_t *_Str);
#تعریف_کرو wcswcs wcsstr
  صحیح __cdecl wcsicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
  صحیح __cdecl wcsnicmp(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2,سائز_t Max_گنتی);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,سائز_t Max_گنتی);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  صحیح __cdecl wcsicoll(ثابت wchar_t *_Str1,ثابت wchar_t *_Str2);
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#شامل <sec_api/string_s.h>
#اگر_ختم
