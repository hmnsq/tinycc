/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_શોધ_S
#define INC_શોધ_S

#અન્તર્ભાવ <search.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  _CRTIMP શૂન્ય *__cdecl _lfind_s(અચલ શૂન્ય *ચાવી_2,અચલ શૂન્ય *_Base,unsigned પૂર્ણાંક *અંક_Of_Elements,size_t _SizeOfElements,પૂર્ણાંક (__cdecl *_PtFuncCompare)(શૂન્ય *,અચલ શૂન્ય *,અચલ શૂન્ય *),શૂન્ય *_Context);
  _CRTIMP શૂન્ય *__cdecl _lsearch_s(અચલ શૂન્ય *ચાવી_2,શૂન્ય *_Base,unsigned પૂર્ણાંક *અંક_Of_Elements,size_t _SizeOfElements,પૂર્ણાંક (__cdecl *_PtFuncCompare)(શૂન્ય *,અચલ શૂન્ય *,અચલ શૂન્ય *),શૂન્ય *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
