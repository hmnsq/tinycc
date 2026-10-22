/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_CTYPE
#घोषणा _INC_CTYPE

#समावेश <_mingw.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

#अगर_अघोषित _CRT_CTYPEDATA_DEFINED
#घोषणा _CRT_CTYPEDATA_DEFINED
#अगर_अघोषित _CTYPE_DISABLE_MACROS

#अगर_अघोषित __PCTYPE_FUNC
#घोषणा __PCTYPE_FUNC __pctype_func()
#अगर_घोषित _MSVCRT_
#घोषणा __pctype_func()	(_pctype)
#अन्यथा
#घोषणा __pctype_func()	(*_imp___pctype)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _pctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_pctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___pctype;
#घोषणा _pctype (*_imp___pctype)
#पूर्ण_अगर
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CRT_WCTYPEDATA_DEFINED
#घोषणा _CRT_WCTYPEDATA_DEFINED
#अगर_अघोषित _CTYPE_DISABLE_MACROS
#अगर_अघोषित _wctype
#अगर_घोषित _MSVCRT_
  बाह्य अचिन्हित लघु *_wctype;
#अन्यथा
  बाह्य अचिन्हित लघु **_imp___wctype;
#घोषणा _wctype (*_imp___wctype)
#पूर्ण_अगर
#पूर्ण_अगर
#अगर_घोषित _MSVCRT_
#घोषणा __pwctype_func() (_pwctype)
#अगर_अघोषित _pwctype
  बाह्य अचिन्हित लघु *_pwctype;
#पूर्ण_अगर
#अन्यथा
#घोषणा __pwctype_func() (*_imp___pwctype)
#अगर_अघोषित _pwctype
  बाह्य अचिन्हित लघु **_imp___pwctype;
#घोषणा _pwctype (*_imp___pwctype)
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

  /* CRT stuff */
#अगर 1
  बाह्य स्थिर अचिन्हित अक्षर __newclmap[];
  बाह्य स्थिर अचिन्हित अक्षर __newcumap[];
  बाह्य pthreadlocinfo __ptlocinfo;
  बाह्य pthreadmbcinfo __ptmbcinfo;
  बाह्य पूर्णांक __globallocalestatus;
  बाह्य पूर्णांक __locale_changed;
  बाह्य काष्ठा threadlocaleinfostruct __initiallocinfo;
  बाह्य _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(व्योम);
  pthreadmbcinfo __cdecl __updatetmbcinfo(व्योम);
#पूर्ण_अगर

#घोषणा _UPPER 0x1
#घोषणा _LOWER 0x2
#घोषणा _DIGIT 0x4
#घोषणा _SPACE 0x8

#घोषणा _PUNCT 0x10
#घोषणा _CONTROL 0x20
#घोषणा _BLANK 0x40
#घोषणा _HEX 0x80

#घोषणा _LEADBYTE 0x8000
#घोषणा _ALPHA (0x0100|_UPPER|_LOWER)

#अगर_अघोषित _CTYPE_DEFINED
#घोषणा _CTYPE_DEFINED

  _CRTIMP पूर्णांक __cdecl _isctype(पूर्णांक _C,पूर्णांक _Type);
  _CRTIMP पूर्णांक __cdecl _isctype_l(पूर्णांक _C,पूर्णांक _Type,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_अक्षर(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isalpha_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_बड़ा(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isupper_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_छोटा(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _islower_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_अंक(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isdigit_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_षष्ठादशक(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isxdigit_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_खाली(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isspace_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_विराम(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _ispunct_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_अक्षर_अंक(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isalnum_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_छाप(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isprint_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_चित्र(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isgraph_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl है_नियंत्रण(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _iscntrl_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl बड़े(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl छोटे(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _tolower(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _tolower_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl _toupper(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _toupper_l(पूर्णांक _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl __isascii(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl __toascii(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl __iscsymf(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl __iscsym(पूर्णांक _C);

#अगर (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णांक __cdecl isblank(पूर्णांक _C);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _WCTYPE_DEFINED
#घोषणा _WCTYPE_DEFINED

  पूर्णांक __cdecl iswalpha(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswupper(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswlower(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswdigit(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswxdigit(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswspace(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswpunct(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswalnum(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswprint(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswgraph(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswcntrl(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswascii(wint_t _C);
  पूर्णांक __cdecl isleadbyte(पूर्णांक _C);
  _CRTIMP पूर्णांक __cdecl _isleadbyte_l(पूर्णांक _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP पूर्णांक __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl __iswcsymf(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP पूर्णांक __cdecl __iswcsym(wint_t _C);
  _CRTIMP पूर्णांक __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  पूर्णांक __cdecl is_wctype(wint_t _C,wctype_t _Type);

#अगर (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
पूर्णांक __cdecl iswblank(wint_t _C);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _CTYPE_DISABLE_MACROS

#अगर_अघोषित MB_CUR_MAX
#घोषणा MB_CUR_MAX ___mb_cur_max_func()
#अगर_अघोषित __mb_cur_max
#अगर_घोषित _MSVCRT_
  बाह्य पूर्णांक __mb_cur_max;
#अन्यथा
#घोषणा __mb_cur_max	(*_imp____mb_cur_max)
  बाह्य पूर्णांक *_imp____mb_cur_max;
#पूर्ण_अगर
#पूर्ण_अगर
#अगर_घोषित _MSVCRT_
#घोषणा ___mb_cur_max_func() (__mb_cur_max)
#अन्यथा
#घोषणा ___mb_cur_max_func() (*_imp____mb_cur_max)
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#घोषणा _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#घोषणा _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=शून्य && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#घोषणा _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#घोषणा _isupper_l(_Char,_Locale) _ischartype_l(_Char,_UPPER,_Locale)
#घोषणा _islower_l(_Char,_Locale) _ischartype_l(_Char,_LOWER,_Locale)
#घोषणा _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#घोषणा _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#घोषणा _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#घोषणा _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#घोषणा _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#घोषणा _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#घोषणा _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#घोषणा _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#घोषणा _tolower(_Char) ((_Char)-'A'+'a')
#घोषणा _toupper(_Char) ((_Char)-'a'+'A')
#घोषणा __isascii(_Char) ((अचिन्हित)(_Char) < 0x80)
#घोषणा __toascii(_Char) ((_Char) & 0x7f)

#अगर_अघोषित _WCTYPE_INLINE_DEFINED
#घोषणा _WCTYPE_INLINE_DEFINED

#अघोषित _CRT_WCTYPE_NOINLINE
#अगर_अघोषित __cplusplus
#घोषणा iswalpha(_c) (iswctype(_c,_ALPHA))
#घोषणा iswupper(_c) (iswctype(_c,_UPPER))
#घोषणा iswlower(_c) (iswctype(_c,_LOWER))
#घोषणा iswdigit(_c) (iswctype(_c,_DIGIT))
#घोषणा iswxdigit(_c) (iswctype(_c,_HEX))
#घोषणा iswspace(_c) (iswctype(_c,_SPACE))
#घोषणा iswpunct(_c) (iswctype(_c,_PUNCT))
#घोषणा iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#घोषणा iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#घोषणा iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#घोषणा iswcntrl(_c) (iswctype(_c,_CONTROL))
#घोषणा iswascii(_c) ((अचिन्हित)(_c) < 0x80)
#घोषणा _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#घोषणा _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#घोषणा _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#घोषणा _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#घोषणा _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#घोषणा _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#घोषणा _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#घोषणा _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#घोषणा _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#घोषणा _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#घोषणा _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा __iscsymf(_c) (है_अक्षर(_c) || ((_c)=='_'))
#घोषणा __iscsym(_c) (है_अक्षर_अंक(_c) || ((_c)=='_'))
#घोषणा __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#घोषणा __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#घोषणा _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#घोषणा _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#घोषणा _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#घोषणा _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
#अगर_अघोषित _CTYPE_DEFINED
  पूर्णांक __cdecl isascii(पूर्णांक _C);
  पूर्णांक __cdecl toascii(पूर्णांक _C);
  पूर्णांक __cdecl iscsymf(पूर्णांक _C);
  पूर्णांक __cdecl iscsym(पूर्णांक _C);
#अन्यथा
#घोषणा isascii __isascii
#घोषणा toascii __toascii
#घोषणा iscsymf __iscsymf
#घोषणा iscsym __iscsym
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
