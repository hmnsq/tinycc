/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#അന്തര്ഭാവ <_mingw.h>

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP ശൂന്യം *__cdecl _memccpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CONST_RETURN ശൂന്യം *__cdecl memchr(സ്ഥിരം ശൂന്യം *_Buf ,പൂർണ്ണസംഖ്യ _Val,size_t Max_എണ്ണം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _memicmp(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _memicmp_l(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size,_locale_t _Locale);
  പൂർണ്ണസംഖ്യ __cdecl memcmp(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size);
  ശൂന്യം *__cdecl memcpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,size_t _Size);
  ശൂന്യം *__cdecl memset(ശൂന്യം *_Dst,പൂർണ്ണസംഖ്യ _Val,size_t _Size);

#ifndef	NO_OLDNAMES
  ശൂന്യം *__cdecl memccpy(ശൂന്യം *_Dst,സ്ഥിരം ശൂന്യം *_Src,പൂർണ്ണസംഖ്യ _Val,size_t _Size);
  പൂർണ്ണസംഖ്യ __cdecl memicmp(സ്ഥിരം ശൂന്യം *_Buf1,സ്ഥിരം ശൂന്യം *_Buf2,size_t _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
