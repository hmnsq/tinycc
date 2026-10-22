/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_WCTYPE
#परिभाषय _INC_WCTYPE

#यदि_अपरिभाषितम् _WIN32
#दोषः Only Win32 target is supported!
#यदि_अन्तः

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRTIMP
#परिभाषय _CRTIMP __declspec(dllimport)
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCHAR_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व wchar_t;
#परिभाषय _WCHAR_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCTYPE_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व wint_t;
  प्रकारनिर्देश अचिह्नित ह्रस्व wctype_t;
#परिभाषय _WCTYPE_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् WEOF
#परिभाषय WEOF (wint_t)(0xFFFF)
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRT_CTYPEDATA_DEFINED
#परिभाषय _CRT_CTYPEDATA_DEFINED
#यदि_अपरिभाषितम् _CTYPE_DISABLE_MACROS

#यदि_अपरिभाषितम् __PCTYPE_FUNC
#परिभाषय __PCTYPE_FUNC __pctype_func()
#यदि_परिभाषितम् _MSVCRT_
#परिभाषय __pctype_func() (_pctype)
#अन्यथा
#परिभाषय __pctype_func() (*_imp___pctype)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _pctype
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित ह्रस्व *_pctype;
#अन्यथा
  बाह्य अचिह्नित ह्रस्व **_imp___pctype;
#परिभाषय _pctype (*_imp___pctype)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRT_WCTYPEDATA_DEFINED
#परिभाषय _CRT_WCTYPEDATA_DEFINED
#यदि_अपरिभाषितम् _CTYPE_DISABLE_MACROS
#यदि_अपरिभाषितम् _wctype
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित ह्रस्व *_wctype;
#अन्यथा
  बाह्य अचिह्नित ह्रस्व **_imp___wctype;
#परिभाषय _wctype (*_imp___wctype)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _pwctype
#यदि_परिभाषितम् _MSVCRT_
  बाह्य अचिह्नित ह्रस्व *_pwctype;
#अन्यथा
  बाह्य अचिह्नित ह्रस्व **_imp___pwctype;
#परिभाषय _pwctype (*_imp___pwctype)
#परिभाषय __pwctype_func() (*_imp___pwctype)
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय ऊर्ध्वस्थम्_3 0x1
#परिभाषय अधस्तनम्_2 0x2
#परिभाषय _DIGIT 0x4
#परिभाषय _SPACE 0x8

#परिभाषय _PUNCT 0x10
#परिभाषय _CONTROL 0x20
#परिभाषय _BLANK 0x40
#परिभाषय _HEX 0x80

#परिभाषय _LEADBYTE 0x8000
#परिभाषय _ALPHA (0x0100|ऊर्ध्वस्थम्_3|अधस्तनम्_2)

#यदि_अपरिभाषितम् _WCTYPE_DEFINED
#परिभाषय _WCTYPE_DEFINED

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
#यदि (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णाङ्क __cdecl isblank(पूर्णाङ्क _C);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCTYPE_INLINE_DEFINED
#परिभाषय _WCTYPE_INLINE_DEFINED
#यदि_अपरिभाषितम् __cplusplus
#परिभाषय iswalpha(_c) (iswctype(_c,_ALPHA))
#परिभाषय iswupper(_c) (iswctype(_c,ऊर्ध्वस्थम्_3))
#परिभाषय iswlower(_c) (iswctype(_c,अधस्तनम्_2))
#परिभाषय iswdigit(_c) (iswctype(_c,_DIGIT))
#परिभाषय iswxdigit(_c) (iswctype(_c,_HEX))
#परिभाषय iswspace(_c) (iswctype(_c,_SPACE))
#परिभाषय iswpunct(_c) (iswctype(_c,_PUNCT))
#परिभाषय iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#परिभाषय iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#परिभाषय iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#परिभाषय iswcntrl(_c) (iswctype(_c,_CONTROL))
#परिभाषय iswascii(_c) ((अचिह्नित)(_c) < 0x80)
#परिभाषय isleadbyte(c) (__pctype_func()[(अचिह्नित वर्ण)(c)] & _LEADBYTE)
#अन्यथा
  __CRT_INLINE पूर्णाङ्क __cdecl iswalpha(wint_t _C) {प्रत्यागम (iswctype(_C,_ALPHA)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswupper(wint_t _C) {प्रत्यागम (iswctype(_C,ऊर्ध्वस्थम्_3)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswlower(wint_t _C) {प्रत्यागम (iswctype(_C,अधस्तनम्_2)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswdigit(wint_t _C) {प्रत्यागम (iswctype(_C,_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswxdigit(wint_t _C) {प्रत्यागम (iswctype(_C,_HEX)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswspace(wint_t _C) {प्रत्यागम (iswctype(_C,_SPACE)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswpunct(wint_t _C) {प्रत्यागम (iswctype(_C,_PUNCT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswalnum(wint_t _C) {प्रत्यागम (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswprint(wint_t _C) {प्रत्यागम (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswgraph(wint_t _C) {प्रत्यागम (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswcntrl(wint_t _C) {प्रत्यागम (iswctype(_C,_CONTROL)); }
  __CRT_INLINE पूर्णाङ्क __cdecl iswascii(wint_t _C) {प्रत्यागम ((अचिह्नित)(_C) < 0x80); }
  __CRT_INLINE पूर्णाङ्क __cdecl isleadbyte(पूर्णाङ्क _C) {प्रत्यागम (__pctype_func()[(अचिह्नित वर्ण)(_C)] & _LEADBYTE); }
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(ध्रुव वर्ण *);
  wctype_t __cdecl wctype(ध्रुव वर्ण *);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
