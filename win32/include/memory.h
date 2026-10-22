/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی INC_حافظه
#تعریف_کړه INC_حافظه

#ضمن <_mingw.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CONST_RETURN
#تعریف_کړه _CONST_RETURN
#د_که_پای

#تعریف_کړه _WConst_return _CONST_RETURN

#که_نه_تعریف_شوی CRT_حافظه_DEFINED
#تعریف_کړه CRT_حافظه_DEFINED
  _CRTIMP فراغ *__cdecl _memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,اندازه_t Max_شمېر);
  _CONST_RETURN فراغ *__cdecl memchr(ثابت فراغ *_Buf ,صحيح _Val,اندازه_t Max_شمېر);
  _CRTIMP صحيح __cdecl _memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4);
  _CRTIMP صحيح __cdecl _memicmp_l(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4,_locale_t _Locale);
  صحيح __cdecl memcmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4);
  فراغ *__cdecl حافظه_نقل(فراغ *_Dst,ثابت فراغ *_Src,اندازه_t اندازه_4);
  فراغ *__cdecl memset(فراغ *_Dst,صحيح _Val,اندازه_t اندازه_4);

#که_نه_تعریف_شوی	NO_OLDNAMES
  فراغ *__cdecl memccpy(فراغ *_Dst,ثابت فراغ *_Src,صحيح _Val,اندازه_t اندازه_4);
  صحيح __cdecl memicmp(ثابت فراغ *_Buf1,ثابت فراغ *_Buf2,اندازه_t اندازه_4);
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
