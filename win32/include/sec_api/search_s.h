/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_অনুসন্ধান_S
#define INC_অনুসন্ধান_S

#অন্তর্ভাব <search.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

  _CRTIMP শূন্য *__cdecl _lfind_s(ধ্রুবক শূন্য *চাবি_2,ধ্রুবক শূন্য *_Base,unsigned পূর্ণসংখ্যা *অঙ্ক_Of_Elements,আকার_t আকার_Of_Elements,পূর্ণসংখ্যা (__cdecl *_PtFuncCompare)(শূন্য *,ধ্রুবক শূন্য *,ধ্রুবক শূন্য *),শূন্য *_Context);
  _CRTIMP শূন্য *__cdecl _lsearch_s(ধ্রুবক শূন্য *চাবি_2,শূন্য *_Base,unsigned পূর্ণসংখ্যা *অঙ্ক_Of_Elements,আকার_t আকার_Of_Elements,পূর্ণসংখ্যা (__cdecl *_PtFuncCompare)(শূন্য *,ধ্রুবক শূন্য *,ধ্রুবক শূন্য *),শূন্য *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
