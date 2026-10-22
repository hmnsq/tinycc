/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#অন্তর্ভাব <_mingw.h>

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP শূন্য *__cdecl _memccpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CONST_RETURN শূন্য *__cdecl memchr(ধ্রুবক শূন্য *_Buf ,পূর্ণসংখ্যা _Val,আকার_t Max_গুনতি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _memicmp(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5);
  _CRTIMP পূর্ণসংখ্যা __cdecl _memicmp_l(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5,_locale_t _Locale);
  পূর্ণসংখ্যা __cdecl memcmp(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5);
  শূন্য *__cdecl memcpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,আকার_t আকার_5);
  শূন্য *__cdecl memset(শূন্য *_Dst,পূর্ণসংখ্যা _Val,আকার_t আকার_5);

#ifndef	NO_OLDNAMES
  শূন্য *__cdecl memccpy(শূন্য *_Dst,ধ্রুবক শূন্য *_Src,পূর্ণসংখ্যা _Val,আকার_t আকার_5);
  পূর্ণসংখ্যা __cdecl memicmp(ধ্রুবক শূন্য *_Buf1,ধ্রুবক শূন্য *_Buf2,আকার_t আকার_5);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
