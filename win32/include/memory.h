/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل INC_يادگيري
#وصف_ڪريو INC_يادگيري

#ضمن <_mingw.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CONST_RETURN
#وصف_ڪريو _CONST_RETURN
#جيڪڏهن_پورو

#وصف_ڪريو _WConst_return _CONST_RETURN

#جيڪڏهن_وصف_نه_ٿيل CRT_يادگيري_DEFINED
#وصف_ڪريو CRT_يادگيري_DEFINED
  _CRTIMP فراغ *__cdecl _memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,سائيز_t Max_ڳڻپ);
  _CONST_RETURN فراغ *__cdecl memchr(ثابت فراغ *_Buf ,صحيح _Val,سائيز_t Max_ڳڻپ);
  _CRTIMP صحيح __cdecl _memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,سائيز_t سائيز_4);
  _CRTIMP صحيح __cdecl _memicmp_l(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,سائيز_t سائيز_4,_locale_t _Locale);
  صحيح __cdecl memcmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,سائيز_t سائيز_4);
  فراغ *__cdecl يادگيري_نقل(فراغ *_Dst,ثابت فراغ *_Src,سائيز_t سائيز_4);
  فراغ *__cdecl memset(فراغ *_Dst,صحيح _Val,سائيز_t سائيز_4);

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  فراغ *__cdecl memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,سائيز_t سائيز_4);
  صحيح __cdecl memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,سائيز_t سائيز_4);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
