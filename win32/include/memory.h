/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#અન્તર્ભાવ <_mingw.h>

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP શૂન્ય *__cdecl _memccpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CONST_RETURN શૂન્ય *__cdecl memchr(અચલ શૂન્ય *_Buf ,પૂર્ણાંક _Val,size_t Max_ગણતરી);
  _CRTIMP પૂર્ણાંક __cdecl _memicmp(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size);
  _CRTIMP પૂર્ણાંક __cdecl _memicmp_l(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size,_locale_t _Locale);
  પૂર્ણાંક __cdecl memcmp(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size);
  શૂન્ય *__cdecl memcpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,size_t _Size);
  શૂન્ય *__cdecl memset(શૂન્ય *_Dst,પૂર્ણાંક _Val,size_t _Size);

#ifndef	NO_OLDNAMES
  શૂન્ય *__cdecl memccpy(શૂન્ય *_Dst,અચલ શૂન્ય *_Src,પૂર્ણાંક _Val,size_t _Size);
  પૂર્ણાંક __cdecl memicmp(અચલ શૂન્ય *_Buf1,અચલ શૂન્ય *_Buf2,size_t _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
