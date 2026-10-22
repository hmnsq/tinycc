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

#अन्तर्भाव <_mingw.h>

#pragma pack(प्रक्षिप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  प्रकारनिर्देश unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef _WCTYPE_T_DEFINED
  प्रकारनिर्देश unsigned short wint_t;
  प्रकारनिर्देश unsigned short wctype_t;
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
#अण्णहा
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  बाह्य unsigned short *_pctype;
#अण्णहा
  बाह्य unsigned short **_imp___pctype;
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
  बाह्य unsigned short *_wctype;
#अण्णहा
  बाह्य unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  बाह्य unsigned short *_pwctype;
#अण्णहा
  बाह्य unsigned short **_imp___pwctype;
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

  पूर्णाङ्क __cdecl iswalpha(wint_t);
  पूर्णाङ्क __cdecl iswupper(wint_t);
  पूर्णाङ्क __cdecl iswlower(wint_t);
  पूर्णाङ्क __cdecl iswdigit(wint_t);
  पूर्णाङ्क __cdecl iswxdigit(wint_t);
  पूर्णाङ्क __cdecl iswspace(wint_t);
  पूर्णाङ्क __cdecl iswpunct(wint_t);
  पूर्णाङ्क __cdecl iswalnum(wint_t);
  पूर्णाङ्क __cdecl iswprint(wint_t);
  पूर्णाङ्क __cdecl iswgraph(wint_t);
  पूर्णाङ्क __cdecl iswcntrl(wint_t);
  पूर्णाङ्क __cdecl iswascii(wint_t);
  पूर्णाङ्क __cdecl isleadbyte(पूर्णाङ्क);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  पूर्णाङ्क __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP पूर्णाङ्क __cdecl __iswcsymf(wint_t);
  _CRTIMP पूर्णाङ्क __cdecl __iswcsym(wint_t);
  पूर्णाङ्क __cdecl is_wctype(wint_t,wctype_t);
#जइ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णाङ्क __cdecl isblank(पूर्णाङ्क _C);
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
#define isleadbyte(c) (__pctype_func()[(unsigned वर्ण)(c)] & _LEADBYTE)
#अण्णहा
  __CRT_INLINE पूर्णाङ्क __cdecl iswalpha(wint_t _C) {प्रत्यागम (iswctype(_C,_ALPHA)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswupper(wint_t _C) {प्रत्यागम (iswctype(_C,_UPPER)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswlower(wint_t _C) {प्रत्यागम (iswctype(_C,_LOWER)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswdigit(wint_t _C) {प्रत्यागम (iswctype(_C,_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswxdigit(wint_t _C) {प्रत्यागम (iswctype(_C,_HEX)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswspace(wint_t _C) {प्रत्यागम (iswctype(_C,_SPACE)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswpunct(wint_t _C) {प्रत्यागम (iswctype(_C,_PUNCT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswalnum(wint_t _C) {प्रत्यागम (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswprint(wint_t _C) {प्रत्यागम (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswgraph(wint_t _C) {प्रत्यागम (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswcntrl(wint_t _C) {प्रत्यागम (iswctype(_C,_CONTROL)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswascii(wint_t _C) {प्रत्यागम ((unsigned)(_C) < 0x80); }
  __CRT_INLINE पूर्णाङ्क __cdecl isleadbyte(पूर्णाङ्क _C) {प्रत्यागम (__pctype_func()[(unsigned वर्ण)(_C)] & _LEADBYTE); }
#endif
#endif

  प्रकारनिर्देश wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ध्रुव वर्ण *);
  wctype_t __cdecl wctype(ध्रुव वर्ण *);

#ifdef __cplusplus
}
#endif

#pragma pack(निष्कासय)
#endif
