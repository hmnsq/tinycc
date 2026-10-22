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

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
  प्रकारव्याख्या अचिन्हित लघु ब_अक्षर_प्रकार;
#define _WCHAR_T_DEFINED
#endif

#ifndef _WCTYPE_T_DEFINED
  प्रकारव्याख्या अचिन्हित लघु wint_t;
  प्रकारव्याख्या अचिन्हित लघु wctype_t;
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
#अन्यथा
#define __pctype_func() (*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  बाह्य अचिन्हित लघु *_pctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pctype;
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
  बाह्य अचिन्हित लघु *_wctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif

#ifndef _pwctype
#ifdef _MSVCRT_
  बाह्य अचिन्हित लघु *_pwctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pwctype;
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

  पूर्णांक __cdecl iswalpha(wint_t);
  पूर्णांक __cdecl iswupper(wint_t);
  पूर्णांक __cdecl iswlower(wint_t);
  पूर्णांक __cdecl iswdigit(wint_t);
  पूर्णांक __cdecl iswxdigit(wint_t);
  पूर्णांक __cdecl iswspace(wint_t);
  पूर्णांक __cdecl iswpunct(wint_t);
  पूर्णांक __cdecl iswalnum(wint_t);
  पूर्णांक __cdecl iswprint(wint_t);
  पूर्णांक __cdecl iswgraph(wint_t);
  पूर्णांक __cdecl iswcntrl(wint_t);
  पूर्णांक __cdecl iswascii(wint_t);
  पूर्णांक __cdecl isleadbyte(पूर्णांक);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  पूर्णांक __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP पूर्णांक __cdecl __iswcsymf(wint_t);
  _CRTIMP पूर्णांक __cdecl __iswcsym(wint_t);
  पूर्णांक __cdecl is_wctype(wint_t,wctype_t);
#जर (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णांक __cdecl isblank(पूर्णांक _C);
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
#define iswascii(_c) ((अचिन्हित)(_c) < 0x80)
#define isleadbyte(c) (__pctype_func()[(अचिन्हित अक्षर)(c)] & _LEADBYTE)
#अन्यथा
  __CRT_INLINE पूर्णांक __cdecl iswalpha(wint_t _C) {परत (iswctype(_C,_ALPHA)); }
  __CRT_INLINE पूर्णांक __cdecl iswupper(wint_t _C) {परत (iswctype(_C,_UPPER)); }
  __CRT_INLINE पूर्णांक __cdecl iswlower(wint_t _C) {परत (iswctype(_C,_LOWER)); }
  __CRT_INLINE पूर्णांक __cdecl iswdigit(wint_t _C) {परत (iswctype(_C,_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswxdigit(wint_t _C) {परत (iswctype(_C,_HEX)); }
  __CRT_INLINE पूर्णांक __cdecl iswspace(wint_t _C) {परत (iswctype(_C,_SPACE)); }
  __CRT_INLINE पूर्णांक __cdecl iswpunct(wint_t _C) {परत (iswctype(_C,_PUNCT)); }
  __CRT_INLINE पूर्णांक __cdecl iswalnum(wint_t _C) {परत (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswprint(wint_t _C) {परत (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswgraph(wint_t _C) {परत (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णांक __cdecl iswcntrl(wint_t _C) {परत (iswctype(_C,_CONTROL)); }
  __CRT_INLINE पूर्णांक __cdecl iswascii(wint_t _C) {परत ((अचिन्हित)(_C) < 0x80); }
  __CRT_INLINE पूर्णांक __cdecl isleadbyte(पूर्णांक _C) {परत (__pctype_func()[(अचिन्हित अक्षर)(_C)] & _LEADBYTE); }
#endif
#endif

  प्रकारव्याख्या ब_अक्षर_प्रकार wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(स्थिरांक अक्षर *);
  wctype_t __cdecl wctype(स्थिरांक अक्षर *);

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
