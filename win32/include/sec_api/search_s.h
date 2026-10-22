/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_ସନ୍ଧାନ_S
#define INC_ସନ୍ଧାନ_S

#ଅନ୍ତର୍ଭାଵ <search.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP ଶୂନ୍ୟ *__cdecl _lfind_s(ଅଚଳ ଶୂନ୍ୟ *ଚାବି_2,ଅଚଳ ଶୂନ୍ୟ *_Base,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଙ୍କ_Of_Elements,size_t _SizeOfElements,ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *_PtFuncCompare)(ଶୂନ୍ୟ *,ଅଚଳ ଶୂନ୍ୟ *,ଅଚଳ ଶୂନ୍ୟ *),ଶୂନ୍ୟ *_Context);
  _CRTIMP ଶୂନ୍ୟ *__cdecl _lsearch_s(ଅଚଳ ଶୂନ୍ୟ *ଚାବି_2,ଶୂନ୍ୟ *_Base,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ଅଙ୍କ_Of_Elements,size_t _SizeOfElements,ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *_PtFuncCompare)(ଶୂନ୍ୟ *,ଅଚଳ ଶୂନ୍ୟ *,ଅଚଳ ଶୂନ୍ୟ *),ଶୂନ୍ୟ *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
