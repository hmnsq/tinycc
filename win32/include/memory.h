/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف INC_حافظہ
#تعریف_کرو INC_حافظہ

#ضمن <_mingw.h>

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _CONST_RETURN
#تعریف_کرو _CONST_RETURN
#جے_انت

#تعریف_کرو _WConst_return _CONST_RETURN

#جے_بنا_تعریف CRT_حافظہ_DEFINED
#تعریف_کرو CRT_حافظہ_DEFINED
  _CRTIMP فراغ *__cdecl _memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,ناپ_t Max_گنتی);
  _CONST_RETURN فراغ *__cdecl memchr(ثابت فراغ *_Buf ,صحيح _Val,ناپ_t Max_گنتی);
  _CRTIMP صحيح __cdecl _memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,ناپ_t ناپ_4);
  _CRTIMP صحيح __cdecl _memicmp_l(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,ناپ_t ناپ_4,_locale_t _Locale);
  صحيح __cdecl memcmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,ناپ_t ناپ_4);
  فراغ *__cdecl حافظہ_نقل(فراغ *_Dst,ثابت فراغ *_Src,ناپ_t ناپ_4);
  فراغ *__cdecl memset(فراغ *_Dst,صحيح _Val,ناپ_t ناپ_4);

#جے_بنا_تعریف	NO_OLDNAMES
  فراغ *__cdecl memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,ناپ_t ناپ_4);
  صحيح __cdecl memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,ناپ_t ناپ_4);
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
