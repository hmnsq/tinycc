/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_جستجو_S
#define INC_جستجو_S

#شامل <search.h>

#اگر defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
بیرونی "C" {
#endif

  _CRTIMP تهی *__cdecl _lfind_s(ثابت تهی *کلید_2,ثابت تهی *_Base,unsigned صحیح *رقم_Of_Elements,size_t _SizeOfElements,صحیح (__cdecl *_PtFuncCompare)(تهی *,ثابت تهی *,ثابت تهی *),تهی *_Context);
  _CRTIMP تهی *__cdecl _lsearch_s(ثابت تهی *کلید_2,تهی *_Base,unsigned صحیح *رقم_Of_Elements,size_t _SizeOfElements,صحیح (__cdecl *_PtFuncCompare)(تهی *,ثابت تهی *,ثابت تهی *),تهی *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
