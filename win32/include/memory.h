/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP ಶೂನ್ಯ *__cdecl _memccpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CONST_RETURN ಶೂನ್ಯ *__cdecl memchr(ಧ್ರುವ ಶೂನ್ಯ *_Buf ,ಪೂರ್ಣಾಙ್ಕ _Val,size_t Max_ಎಣಿಕೆ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _memicmp(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _memicmp_l(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size,_locale_t _Locale);
  ಪೂರ್ಣಾಙ್ಕ __cdecl memcmp(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size);
  ಶೂನ್ಯ *__cdecl memcpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,size_t _Size);
  ಶೂನ್ಯ *__cdecl memset(ಶೂನ್ಯ *_Dst,ಪೂರ್ಣಾಙ್ಕ _Val,size_t _Size);

#ifndef	NO_OLDNAMES
  ಶೂನ್ಯ *__cdecl memccpy(ಶೂನ್ಯ *_Dst,ಧ್ರುವ ಶೂನ್ಯ *_Src,ಪೂರ್ಣಾಙ್ಕ _Val,size_t _Size);
  ಪೂರ್ಣಾಙ್ಕ __cdecl memicmp(ಧ್ರುವ ಶೂನ್ಯ *_Buf1,ಧ್ರುವ ಶೂನ್ಯ *_Buf2,size_t _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
