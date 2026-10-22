/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_हानाप_S
#define INC_हानाप_S

#include <search.h>

#if defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
extern "C" {
#endif

  _CRTIMP void *__cdecl _lfind_s(const void *सुसि_2,const void *_Base,unsigned int *नुमेरो_Of_Elements,size_t _SizeOfElements,int (__cdecl *_PtFuncCompare)(void *,const void *,const void *),void *_Context);
  _CRTIMP void *__cdecl _lsearch_s(const void *सुसि_2,void *_Base,unsigned int *नुमेरो_Of_Elements,size_t _SizeOfElements,int (__cdecl *_PtFuncCompare)(void *,const void *,const void *),void *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
