/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_CTYPE
#परिभाषय _INC_CTYPE

#अन्तर्भाव <_mingw.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
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
#परिभाषय __pctype_func()	(_pctype)
#अन्यथा
#परिभाषय __pctype_func()	(*_imp___pctype)
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
#यदि_परिभाषितम् _MSVCRT_
#परिभाषय __pwctype_func() (_pwctype)
#यदि_अपरिभाषितम् _pwctype
  बाह्य अचिह्नित ह्रस्व *_pwctype;
#यदि_अन्तः
#अन्यथा
#परिभाषय __pwctype_func() (*_imp___pwctype)
#यदि_अपरिभाषितम् _pwctype
  बाह्य अचिह्नित ह्रस्व **_imp___pwctype;
#परिभाषय _pwctype (*_imp___pwctype)
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

  /* CRT stuff */
#यदि 1
  बाह्य ध्रुव अचिह्नित वर्ण __newclmap[];
  बाह्य ध्रुव अचिह्नित वर्ण __newcumap[];
  बाह्य pthreadlocinfo __ptlocinfo;
  बाह्य pthreadmbcinfo __ptmbcinfo;
  बाह्य पूर्णाङ्क __globallocalestatus;
  बाह्य पूर्णाङ्क __locale_changed;
  बाह्य संरचना threadlocaleinfostruct __initiallocinfo;
  बाह्य _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(शून्य);
  pthreadmbcinfo __cdecl __updatetmbcinfo(शून्य);
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

#यदि_अपरिभाषितम् _CTYPE_DEFINED
#परिभाषय _CTYPE_DEFINED

  _CRTIMP पूर्णाङ्क __cdecl _isctype(पूर्णाङ्क _C,पूर्णाङ्क _Type);
  _CRTIMP पूर्णाङ्क __cdecl _isctype_l(पूर्णाङ्क _C,पूर्णाङ्क _Type,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl अक्षरम्_वा(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isalpha_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl isupper(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isupper_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl islower(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _islower_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl अङ्कः_वा(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isdigit_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl isxdigit(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isxdigit_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl रिक्तम्_वा(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isspace_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl ispunct(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _ispunct_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl अक्षरम्_अङ्कः_वा(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isalnum_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl isprint(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isprint_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl isgraph(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isgraph_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl iscntrl(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _iscntrl_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl महाक्षरम्(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl tolower(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _tolower(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _tolower_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl _toupper(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _toupper_l(पूर्णाङ्क _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl __isascii(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl __toascii(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl __iscsymf(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl __iscsym(पूर्णाङ्क _C);

#यदि (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णाङ्क __cdecl isblank(पूर्णाङ्क _C);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCTYPE_DEFINED
#परिभाषय _WCTYPE_DEFINED

  पूर्णाङ्क __cdecl iswalpha(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswupper(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswlower(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswdigit(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswxdigit(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswspace(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswpunct(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswalnum(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswprint(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswgraph(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswcntrl(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswascii(wint_t _C);
  पूर्णाङ्क __cdecl isleadbyte(पूर्णाङ्क _C);
  _CRTIMP पूर्णाङ्क __cdecl _isleadbyte_l(पूर्णाङ्क _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP पूर्णाङ्क __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl __iswcsymf(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP पूर्णाङ्क __cdecl __iswcsym(wint_t _C);
  _CRTIMP पूर्णाङ्क __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  पूर्णाङ्क __cdecl is_wctype(wint_t _C,wctype_t _Type);

#यदि (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णाङ्क __cdecl iswblank(wint_t _C);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _CTYPE_DISABLE_MACROS

#यदि_अपरिभाषितम् MB_CUR_MAX
#परिभाषय MB_CUR_MAX ___mb_cur_max_func()
#यदि_अपरिभाषितम् __mb_cur_max
#यदि_परिभाषितम् _MSVCRT_
  बाह्य पूर्णाङ्क __mb_cur_max;
#अन्यथा
#परिभाषय __mb_cur_max	(*_imp____mb_cur_max)
  बाह्य पूर्णाङ्क *_imp____mb_cur_max;
#यदि_अन्तः
#यदि_अन्तः
#यदि_परिभाषितम् _MSVCRT_
#परिभाषय ___mb_cur_max_func() (__mb_cur_max)
#अन्यथा
#परिभाषय ___mb_cur_max_func() (*_imp____mb_cur_max)
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#परिभाषय _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#परिभाषय _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=रिक्त && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#परिभाषय _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#परिभाषय _isupper_l(_Char,_Locale) _ischartype_l(_Char,ऊर्ध्वस्थम्_3,_Locale)
#परिभाषय _islower_l(_Char,_Locale) _ischartype_l(_Char,अधस्तनम्_2,_Locale)
#परिभाषय _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#परिभाषय _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#परिभाषय _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#परिभाषय _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#परिभाषय _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#परिभाषय _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#परिभाषय _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#परिभाषय _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#परिभाषय _tolower(_Char) ((_Char)-'A'+'a')
#परिभाषय _toupper(_Char) ((_Char)-'a'+'A')
#परिभाषय __isascii(_Char) ((अचिह्नित)(_Char) < 0x80)
#परिभाषय __toascii(_Char) ((_Char) & 0x7f)

#यदि_अपरिभाषितम् _WCTYPE_INLINE_DEFINED
#परिभाषय _WCTYPE_INLINE_DEFINED

#अपरिभाषय _CRT_WCTYPE_NOINLINE
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
#परिभाषय _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#परिभाषय _iswupper_l(_c,_p) (_iswctype_l(_c,ऊर्ध्वस्थम्_3,_p))
#परिभाषय _iswlower_l(_c,_p) (_iswctype_l(_c,अधस्तनम्_2,_p))
#परिभाषय _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#परिभाषय _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#परिभाषय _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#परिभाषय _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#परिभाषय _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#परिभाषय _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#परिभाषय _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#परिभाषय _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय __iscsymf(_c) (अक्षरम्_वा(_c) || ((_c)=='_'))
#परिभाषय __iscsym(_c) (अक्षरम्_अङ्कः_वा(_c) || ((_c)=='_'))
#परिभाषय __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#परिभाषय __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#परिभाषय _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#परिभाषय _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#परिभाषय _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#परिभाषय _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
#यदि_अपरिभाषितम् _CTYPE_DEFINED
  पूर्णाङ्क __cdecl isascii(पूर्णाङ्क _C);
  पूर्णाङ्क __cdecl toascii(पूर्णाङ्क _C);
  पूर्णाङ्क __cdecl iscsymf(पूर्णाङ्क _C);
  पूर्णाङ्क __cdecl iscsym(पूर्णाङ्क _C);
#अन्यथा
#परिभाषय isascii __isascii
#परिभाषय toascii __toascii
#परिभाषय iscsymf __iscsymf
#परिभाषय iscsym __iscsym
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
