/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_தேடல்_S
#define INC_தேடல்_S

#அந்தர்பாவ <search.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

  _CRTIMP வெறுமை *__cdecl _lfind_s(மாறிலி வெறுமை *சாவி_2,மாறிலி வெறுமை *_Base,unsigned முழு *இலக்கம்_Of_Elements,size_t _SizeOfElements,முழு (__cdecl *_PtFuncCompare)(வெறுமை *,மாறிலி வெறுமை *,மாறிலி வெறுமை *),வெறுமை *_Context);
  _CRTIMP வெறுமை *__cdecl _lsearch_s(மாறிலி வெறுமை *சாவி_2,வெறுமை *_Base,unsigned முழு *இலக்கம்_Of_Elements,size_t _SizeOfElements,முழு (__cdecl *_PtFuncCompare)(வெறுமை *,மாறிலி வெறுமை *,மாறிலி வெறுமை *),வெறுமை *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
