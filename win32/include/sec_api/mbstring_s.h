/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_MBSTRING_S
#تعریف_کرو _INC_MBSTRING_S

#شامل <mbstring.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _MBSTRING_S_DEFINED
#تعریف_کرو _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(غیرعلامتی حرف *_Str,سائز_t سائز_اندر_بائٹیں);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(غیرعلامتی حرف *_Str,سائز_t سائز_اندر_بائٹیں,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,غیرعلامتی صحیح _Ch,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,غیرعلامتی صحیح _Ch,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,ثابت غیرعلامتی حرف *_Src,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,غیرعلامتی صحیح _Val,سائز_t Max_گنتی);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,غیرعلامتی صحیح _Val,سائز_t Max_گنتی,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,غیرعلامتی صحیح _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,غیرعلامتی صحیح _Val,_locale_t _Locale);
  _CRTIMP غیرعلامتی حرف *__cdecl _mbstok_s(غیرعلامتی حرف *_Str,ثابت غیرعلامتی حرف *_Delim,غیرعلامتی حرف **_Context);
  _CRTIMP غیرعلامتی حرف *__cdecl _mbstok_s_l(غیرعلامتی حرف *_Str,ثابت غیرعلامتی حرف *_Delim,غیرعلامتی حرف **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(غیرعلامتی حرف *_Str,سائز_t سائز_اندر_بائٹیں);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(غیرعلامتی حرف *_Str,سائز_t سائز_اندر_بائٹیں,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,صحیح *_PCopied,ثابت غیرعلامتی حرف *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(غیرعلامتی حرف *_Dst,سائز_t Dst_سائز_اندر_بائٹیں,صحیح *_PCopied,ثابت غیرعلامتی حرف *_Src,_locale_t _Locale);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
