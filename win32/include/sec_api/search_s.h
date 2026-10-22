/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_തിരയൽ_S
#define INC_തിരയൽ_S

#അന്തര്ഭാവ <search.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP ശൂന്യം *__cdecl _lfind_s(സ്ഥിരം ശൂന്യം *താക്കോൽ_2,സ്ഥിരം ശൂന്യം *_Base,unsigned പൂർണ്ണസംഖ്യ *അക്കം_Of_Elements,size_t _SizeOfElements,പൂർണ്ണസംഖ്യ (__cdecl *_PtFuncCompare)(ശൂന്യം *,സ്ഥിരം ശൂന്യം *,സ്ഥിരം ശൂന്യം *),ശൂന്യം *_Context);
  _CRTIMP ശൂന്യം *__cdecl _lsearch_s(സ്ഥിരം ശൂന്യം *താക്കോൽ_2,ശൂന്യം *_Base,unsigned പൂർണ്ണസംഖ്യ *അക്കം_Of_Elements,size_t _SizeOfElements,പൂർണ്ണസംഖ്യ (__cdecl *_PtFuncCompare)(ശൂന്യം *,സ്ഥിരം ശൂന്യം *,സ്ഥിരം ശൂന്യം *),ശൂന്യം *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
