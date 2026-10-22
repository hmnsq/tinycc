/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STRING
#నిర్వచించు _INC_STRING

#అన్తర్భావ <_mingw.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _NLSCMP_DEFINED
#నిర్వచించు _NLSCMP_DEFINED
#నిర్వచించు _NLSCMPERROR 2147483647
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు _WConst_return _CONST_RETURN

#నిర్వచితం_కాకపోతే CRT_జ్ఞాపకం_DEFINED
#నిర్వచించు CRT_జ్ఞాపకం_DEFINED
  _CRTIMP శూన్య *__cdecl _memccpy(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CONST_RETURN శూన్య *__cdecl memchr(స్థిరరాశి శూన్య *_Buf ,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _memicmp(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4);
  _CRTIMP పూర్ణాంకం __cdecl _memicmp_l(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4,_locale_t _Locale);
  పూర్ణాంకం __cdecl memcmp(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4);
  శూన్య *__cdecl జ్ఞాపకం_నకలు(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,కొలత_t కొలత_4);
  శూన్య *__cdecl memset(శూన్య *_Dst,పూర్ణాంకం _Val,కొలత_t కొలత_4);
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  శూన్య *__cdecl memccpy(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,పూర్ణాంకం _Val,కొలత_t కొలత_4);
  పూర్ణాంకం __cdecl memicmp(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4);
#అయితే_ముగింపు
#అయితే_ముగింపు
  అక్షరం *__cdecl _strset(అక్షరం *_Str,పూర్ణాంకం _Val);
  అక్షరం *__cdecl strcpy(అక్షరం *_Dest,స్థిరరాశి అక్షరం *ఆధారం_3);
  అక్షరం *__cdecl strcat(అక్షరం *_Dest,స్థిరరాశి అక్షరం *ఆధారం_3);
  పూర్ణాంకం __cdecl strcmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  కొలత_t __cdecl అక్షరశ్రేణి_పొడవు(స్థిరరాశి అక్షరం *_Str);
#ఒకవేళ 0
  కొలత_t __cdecl strnlen(స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క);
#అయితే_ముగింపు
  శూన్య *__cdecl memmove(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,కొలత_t కొలత_4);
  _CRTIMP అక్షరం *__cdecl _strdup(స్థిరరాశి అక్షరం *_Src);
  _CONST_RETURN అక్షరం *__cdecl strchr(స్థిరరాశి అక్షరం *_Str,పూర్ణాంకం _Val);
  _CRTIMP పూర్ణాంకం __cdecl _stricmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _strcmpi(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _stricmp_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,_locale_t _Locale);
  పూర్ణాంకం __cdecl strcoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _strcoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _stricoll(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _stricoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _strncoll (స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _strncoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _strnicoll (స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _strnicoll_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  కొలత_t __cdecl strcspn(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Control);
  _CRTIMP అక్షరం *__cdecl _strerror(స్థిరరాశి అక్షరం *Err_సందేశం);
  అక్షరం *__cdecl strerror(పూర్ణాంకం);
  _CRTIMP అక్షరం *__cdecl _strlwr(అక్షరం *_String);
  అక్షరం *strlwr_l(అక్షరం *_String,_locale_t _Locale);
  అక్షరం *__cdecl strncat(అక్షరం *_Dest,స్థిరరాశి అక్షరం *ఆధారం_3,కొలత_t లెక్క_5);
  పూర్ణాంకం __cdecl అక్షరశ్రేణి_పోలిక(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _strnicmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _strnicmp_l(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  అక్షరం *strncpy(అక్షరం *_Dest,స్థిరరాశి అక్షరం *ఆధారం_3,కొలత_t లెక్క_5);
  _CRTIMP అక్షరం *__cdecl _strnset(అక్షరం *_Str,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CONST_RETURN అక్షరం *__cdecl strpbrk(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Control);
  _CONST_RETURN అక్షరం *__cdecl strrchr(స్థిరరాశి అక్షరం *_Str,పూర్ణాంకం _Ch);
  _CRTIMP అక్షరం *__cdecl _strrev(అక్షరం *_Str);
  కొలత_t __cdecl strspn(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_Control);
  _CONST_RETURN అక్షరం *__cdecl అక్షరశ్రేణి_శోధన(స్థిరరాశి అక్షరం *_Str,స్థిరరాశి అక్షరం *_SubStr);
  అక్షరం *__cdecl strtok(అక్షరం *_Str,స్థిరరాశి అక్షరం *_Delim);
  _CRTIMP అక్షరం *__cdecl _strupr(అక్షరం *_String);
  _CRTIMP అక్షరం *_strupr_l(అక్షరం *_String,_locale_t _Locale);
  కొలత_t __cdecl strxfrm(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _strxfrm_l(అక్షరం *_Dst,స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  అక్షరం *__cdecl strdup(స్థిరరాశి అక్షరం *_Src);
  పూర్ణాంకం __cdecl strcmpi(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  పూర్ణాంకం __cdecl stricmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str2);
  అక్షరం *__cdecl strlwr(అక్షరం *_Str);
  పూర్ణాంకం __cdecl strnicmp(స్థిరరాశి అక్షరం *_Str1,స్థిరరాశి అక్షరం *_Str,కొలత_t Max_లెక్క);
  __CRT_INLINE పూర్ణాంకం __cdecl strncasecmp (స్థిరరాశి అక్షరం *__sz1, స్థిరరాశి అక్షరం *__sz2, కొలత_t __sizeMaxCompare) { తిరిగి _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE పూర్ణాంకం __cdecl strcasecmp (స్థిరరాశి అక్షరం *__sz1, స్థిరరాశి అక్షరం *__sz2) { తిరిగి _stricmp (__sz1, __sz2); }
  అక్షరం *__cdecl strnset(అక్షరం *_Str,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  అక్షరం *__cdecl strrev(అక్షరం *_Str);
  అక్షరం *__cdecl strset(అక్షరం *_Str,పూర్ణాంకం _Val);
  అక్షరం *__cdecl strupr(అక్షరం *_Str);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTRING_DEFINED
#నిర్వచించు _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(స్థిరరాశి wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3);
  _CONST_RETURN wchar_t *__cdecl wcschr(స్థిరరాశి wchar_t *_Str,wchar_t _Ch);
  పూర్ణాంకం __cdecl wcscmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3);
  కొలత_t __cdecl wcscspn(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_Control);
  కొలత_t __cdecl wcslen(స్థిరరాశి wchar_t *_Str);
  కొలత_t __cdecl wcsnlen(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క);
  wchar_t *wcsncat(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3,కొలత_t లెక్క_5);
  పూర్ణాంకం __cdecl wcsncmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  wchar_t *wcsncpy(wchar_t *_Dest,స్థిరరాశి wchar_t *ఆధారం_3,కొలత_t లెక్క_5);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(స్థిరరాశి wchar_t *_Str,wchar_t _Ch);
  కొలత_t __cdecl wcsspn(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(స్థిరరాశి wchar_t *_Str,స్థిరరాశి wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,స్థిరరాశి wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(పూర్ణాంకం Err_అంకె);
  _CRTIMP wchar_t *__cdecl __wcserror(స్థిరరాశి wchar_t *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicmp_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicmp_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,కొలత_t Max_లెక్క);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  కొలత_t __cdecl wcsxfrm(wchar_t *_Dst,స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క);
  _CRTIMP కొలత_t __cdecl _wcsxfrm_l(wchar_t *_Dst,స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,_locale_t _Locale);
  పూర్ణాంకం __cdecl wcscoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _wcscoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  _CRTIMP పూర్ణాంకం __cdecl _wcsicoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsncoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _wcsncoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _wcsnicoll_l(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క,_locale_t _Locale);

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(స్థిరరాశి wchar_t *_Str);
#నిర్వచించు wcswcs wcsstr
  పూర్ణాంకం __cdecl wcsicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
  పూర్ణాంకం __cdecl wcsnicmp(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2,కొలత_t Max_లెక్క);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,కొలత_t Max_లెక్క);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  పూర్ణాంకం __cdecl wcsicoll(స్థిరరాశి wchar_t *_Str1,స్థిరరాశి wchar_t *_Str2);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అన్తర్భావ <sec_api/string_s.h>
#అయితే_ముగింపు
