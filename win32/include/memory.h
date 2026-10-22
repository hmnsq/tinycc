/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده INC_حافظه
#تعریف_کن INC_حافظه

#ضمن <_mingw.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CONST_RETURN
#تعریف_کن _CONST_RETURN
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

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
