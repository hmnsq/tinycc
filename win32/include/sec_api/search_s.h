/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SEARCH_S
#define _INC_SEARCH_S

#ضمن <search.h>

#ܐܢ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

  _CRTIMP فراغ *__cdecl _lfind_s(ثابت فراغ *_Key,ثابت فراغ *_Base,unsigned صحيح *_NumOfElements,size_t _SizeOfElements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);
  _CRTIMP فراغ *__cdecl _lsearch_s(ثابت فراغ *_Key,فراغ *_Base,unsigned صحيح *_NumOfElements,size_t _SizeOfElements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
