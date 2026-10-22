/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_گەڕان_S
#define INC_گەڕان_S

#ضمن <search.h>

#إذا defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

  _CRTIMP فراغ *__cdecl _lfind_s(ثابت فراغ *کلیل_2,ثابت فراغ *_Base,unsigned صحيح *ژمارە_Of_Elements,size_t _SizeOfElements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);
  _CRTIMP فراغ *__cdecl _lsearch_s(ثابت فراغ *کلیل_2,فراغ *_Base,unsigned صحيح *ژمارە_Of_Elements,size_t _SizeOfElements,صحيح (__cdecl *_PtFuncCompare)(فراغ *,ثابت فراغ *,ثابت فراغ *),فراغ *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
