/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#அந்தர்பாவ <_mingw.h>

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP வெறுமை *__cdecl _memccpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,முழு _Val,size_t Max_மொத்தம்);
  _CONST_RETURN வெறுமை *__cdecl memchr(மாறிலி வெறுமை *_Buf ,முழு _Val,size_t Max_மொத்தம்);
  _CRTIMP முழு __cdecl _memicmp(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size);
  _CRTIMP முழு __cdecl _memicmp_l(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size,_locale_t _Locale);
  முழு __cdecl memcmp(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size);
  வெறுமை *__cdecl memcpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,size_t _Size);
  வெறுமை *__cdecl memset(வெறுமை *_Dst,முழு _Val,size_t _Size);

#ifndef	NO_OLDNAMES
  வெறுமை *__cdecl memccpy(வெறுமை *_Dst,மாறிலி வெறுமை *_Src,முழு _Val,size_t _Size);
  முழு __cdecl memicmp(மாறிலி வெறுமை *_Buf1,மாறிலி வெறுமை *_Buf2,size_t _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
