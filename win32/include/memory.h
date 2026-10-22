/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#شامل <_mingw.h>

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP تهی *__cdecl _memccpy(تهی *_Dst,ثابت تهی *_Src,صحیح _Val,size_t Max_شمار);
  _CONST_RETURN تهی *__cdecl memchr(ثابت تهی *_Buf ,صحیح _Val,size_t Max_شمار);
  _CRTIMP صحیح __cdecl _memicmp(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size);
  _CRTIMP صحیح __cdecl _memicmp_l(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size,_locale_t _Locale);
  صحیح __cdecl memcmp(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size);
  تهی *__cdecl memcpy(تهی *_Dst,ثابت تهی *_Src,size_t _Size);
  تهی *__cdecl memset(تهی *_Dst,صحیح _Val,size_t _Size);

#ifndef	NO_OLDNAMES
  تهی *__cdecl memccpy(تهی *_Dst,ثابت تهی *_Src,صحیح _Val,size_t _Size);
  صحیح __cdecl memicmp(ثابت تهی *_Buf1,ثابت تهی *_Buf2,size_t _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
