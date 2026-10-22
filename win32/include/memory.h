/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ INC_حافظہ
#تعریف_کرو INC_حافظہ

#شامل <_mingw.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CONST_RETURN
#تعریف_کرو _CONST_RETURN
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

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
