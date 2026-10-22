/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
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

#ifdef __cplusplus
}
#endif
#endif
