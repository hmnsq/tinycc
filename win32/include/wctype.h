/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WCTYPE
#define _INC_WCTYPE

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef _WCTYPE_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short wint_t;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short wctype_t;
#define _WCTYPE_T_DEFINED
#endif

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifndef _CRT_CTYPEDATA_DEFINED
#define _CRT_CTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS

#ifndef __PCTYPE_FUNC
#define __PCTYPE_FUNC __pctype_func()
#ifdef _MSVCRT_
#define __pctype_func() (_pctype)
#ಅನ್ಯಥಾ
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned short *_pctype;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ unsigned short **_imp___pctype;
#define _pctype (*_imp___pctype)
#endif
#endif

#endif
#endif

#ifndef _CRT_WCTYPEDATA_DEFINED
#define _CRT_WCTYPEDATA_DEFINED
#ifndef _CTYPE_DISABLE_MACROS
#ifndef _wctype
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned short *_wctype;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  ಬಾಹ್ಯ unsigned short *_pwctype;
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ unsigned short **_imp___pwctype;
#define _pwctype (*_imp___pwctype)
#define __pwctype_func() (*_imp___pwctype)
#endif
#endif
#endif
#endif

#define _UPPER 0x1
#define _LOWER 0x2
#define _DIGIT 0x4
#define _SPACE 0x8

#define _PUNCT 0x10
#define _CONTROL 0x20
#define _BLANK 0x40
#define _HEX 0x80

#define _LEADBYTE 0x8000
#define _ALPHA (0x0100|_UPPER|_LOWER)

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED

  ಪೂರ್ಣಾಙ್ಕ __cdecl iswalpha(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswupper(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswlower(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswdigit(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswxdigit(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswspace(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswpunct(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswalnum(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswprint(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswgraph(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswcntrl(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswascii(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl isleadbyte(ಪೂರ್ಣಾಙ್ಕ);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __iswcsymf(wint_t);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl __iswcsym(wint_t);
  ಪೂರ್ಣಾಙ್ಕ __cdecl is_wctype(wint_t,wctype_t);
#ಯದಿ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
ಪೂರ್ಣಾಙ್ಕ __cdecl isblank(ಪೂರ್ಣಾಙ್ಕ _C);
#endif
#endif

#ifndef _WCTYPE_INLINE_DEFINED
#define _WCTYPE_INLINE_DEFINED
#ifndef __cplusplus
#define iswalpha(_c) (iswctype(_c,_ALPHA))
#define iswupper(_c) (iswctype(_c,_UPPER))
#define iswlower(_c) (iswctype(_c,_LOWER))
#define iswdigit(_c) (iswctype(_c,_DIGIT))
#define iswxdigit(_c) (iswctype(_c,_HEX))
#define iswspace(_c) (iswctype(_c,_SPACE))
#define iswpunct(_c) (iswctype(_c,_PUNCT))
#define iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#define iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#define iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#define iswcntrl(_c) (iswctype(_c,_CONTROL))
#define iswascii(_c) ((unsigned)(_c) < 0x80)
#define isleadbyte(c) (__pctype_func()[(unsigned ವರ್ಣ)(c)] & _LEADBYTE)
#ಅನ್ಯಥಾ
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswalpha(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_ALPHA)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswupper(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_UPPER)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswlower(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_LOWER)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswdigit(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswxdigit(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_HEX)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswspace(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_SPACE)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswpunct(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_PUNCT)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswalnum(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswprint(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswgraph(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswcntrl(wint_t _C) {ಪ್ರತ್ಯಾಗಮ (iswctype(_C,_CONTROL)); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl iswascii(wint_t _C) {ಪ್ರತ್ಯಾಗಮ ((unsigned)(_C) < 0x80); }
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl isleadbyte(ಪೂರ್ಣಾಙ್ಕ _C) {ಪ್ರತ್ಯಾಗಮ (__pctype_func()[(unsigned ವರ್ಣ)(_C)] & _LEADBYTE); }
#endif
#endif

  ಪ್ರಕಾರನಿರ್ದೇಶ wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ಧ್ರುವ ವರ್ಣ *);
  wctype_t __cdecl wctype(ಧ್ರುವ ವರ್ಣ *);

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)
#endif
