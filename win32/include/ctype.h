/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_CTYPE
#تعریف_کړه _INC_CTYPE

#ضمن <_mingw.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی WEOF
#تعریف_کړه WEOF (wint_t)(0xFFFF)
#د_که_پای

#که_نه_تعریف_شوی _CRT_CTYPEDATA_DEFINED
#تعریف_کړه _CRT_CTYPEDATA_DEFINED
#که_نه_تعریف_شوی _CTYPE_DISABLE_MACROS

#که_نه_تعریف_شوی __PCTYPE_FUNC
#تعریف_کړه __PCTYPE_FUNC __pctype_func()
#که_تعریف_شوی _MSVCRT_
#تعریف_کړه __pctype_func()	(_pctype)
#وإلا
#تعریف_کړه __pctype_func()	(*_imp___pctype)
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _pctype
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه لنډ *_pctype;
#وإلا
  خارجي بینښه لنډ **_imp___pctype;
#تعریف_کړه _pctype (*_imp___pctype)
#د_که_پای
#د_که_پای

#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _CRT_WCTYPEDATA_DEFINED
#تعریف_کړه _CRT_WCTYPEDATA_DEFINED
#که_نه_تعریف_شوی _CTYPE_DISABLE_MACROS
#که_نه_تعریف_شوی _wctype
#که_تعریف_شوی _MSVCRT_
  خارجي بینښه لنډ *_wctype;
#وإلا
  خارجي بینښه لنډ **_imp___wctype;
#تعریف_کړه _wctype (*_imp___wctype)
#د_که_پای
#د_که_پای
#که_تعریف_شوی _MSVCRT_
#تعریف_کړه __pwctype_func() (_pwctype)
#که_نه_تعریف_شوی _pwctype
  خارجي بینښه لنډ *_pwctype;
#د_که_پای
#وإلا
#تعریف_کړه __pwctype_func() (*_imp___pwctype)
#که_نه_تعریف_شوی _pwctype
  خارجي بینښه لنډ **_imp___pwctype;
#تعریف_کړه _pwctype (*_imp___pwctype)
#د_که_پای
#د_که_پای
#د_که_پای
#د_که_پای

  /* CRT stuff */
#إذا 1
  خارجي ثابت بینښه حرف __newclmap[];
  خارجي ثابت بینښه حرف __newcumap[];
  خارجي pthreadlocinfo __ptlocinfo;
  خارجي pthreadmbcinfo __ptmbcinfo;
  خارجي صحيح __globallocalestatus;
  خارجي صحيح __locale_changed;
  خارجي بنية threadlocaleinfostruct __initiallocinfo;
  خارجي _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(فراغ);
  pthreadmbcinfo __cdecl __updatetmbcinfo(فراغ);
#د_که_پای

#تعریف_کړه پاسنی_3 0x1
#تعریف_کړه ښکتنی_2 0x2
#تعریف_کړه _DIGIT 0x4
#تعریف_کړه _SPACE 0x8

#تعریف_کړه _PUNCT 0x10
#تعریف_کړه _CONTROL 0x20
#تعریف_کړه _BLANK 0x40
#تعریف_کړه _HEX 0x80

#تعریف_کړه _LEADBYTE 0x8000
#تعریف_کړه _ALPHA (0x0100|پاسنی_3|ښکتنی_2)

#که_نه_تعریف_شوی _CTYPE_DEFINED
#تعریف_کړه _CTYPE_DEFINED

  _CRTIMP صحيح __cdecl _isctype(صحيح _C,صحيح _Type);
  _CRTIMP صحيح __cdecl _isctype_l(صحيح _C,صحيح _Type,_locale_t _Locale);
  _CRTIMP صحيح __cdecl که_توری(صحيح _C);
  _CRTIMP صحيح __cdecl _isalpha_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isupper(صحيح _C);
  _CRTIMP صحيح __cdecl _isupper_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl islower(صحيح _C);
  _CRTIMP صحيح __cdecl _islower_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl که_عدد(صحيح _C);
  _CRTIMP صحيح __cdecl _isdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isxdigit(صحيح _C);
  _CRTIMP صحيح __cdecl _isxdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl که_تشه(صحيح _C);
  _CRTIMP صحيح __cdecl _isspace_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl ispunct(صحيح _C);
  _CRTIMP صحيح __cdecl _ispunct_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl که_توری_یا_عدد(صحيح _C);
  _CRTIMP صحيح __cdecl _isalnum_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isprint(صحيح _C);
  _CRTIMP صحيح __cdecl _isprint_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isgraph(صحيح _C);
  _CRTIMP صحيح __cdecl _isgraph_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl iscntrl(صحيح _C);
  _CRTIMP صحيح __cdecl _iscntrl_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl لوی_توری(صحيح _C);
  _CRTIMP صحيح __cdecl tolower(صحيح _C);
  _CRTIMP صحيح __cdecl _tolower(صحيح _C);
  _CRTIMP صحيح __cdecl _tolower_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl _toupper(صحيح _C);
  _CRTIMP صحيح __cdecl _toupper_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl __isascii(صحيح _C);
  _CRTIMP صحيح __cdecl __toascii(صحيح _C);
  _CRTIMP صحيح __cdecl __iscsymf(صحيح _C);
  _CRTIMP صحيح __cdecl __iscsym(صحيح _C);

#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
صحيح __cdecl isblank(صحيح _C);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _WCTYPE_DEFINED
#تعریف_کړه _WCTYPE_DEFINED

  صحيح __cdecl iswalpha(wint_t _C);
  _CRTIMP صحيح __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswupper(wint_t _C);
  _CRTIMP صحيح __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswlower(wint_t _C);
  _CRTIMP صحيح __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswdigit(wint_t _C);
  _CRTIMP صحيح __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswxdigit(wint_t _C);
  _CRTIMP صحيح __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswspace(wint_t _C);
  _CRTIMP صحيح __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswpunct(wint_t _C);
  _CRTIMP صحيح __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswalnum(wint_t _C);
  _CRTIMP صحيح __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswprint(wint_t _C);
  _CRTIMP صحيح __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswgraph(wint_t _C);
  _CRTIMP صحيح __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswcntrl(wint_t _C);
  _CRTIMP صحيح __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswascii(wint_t _C);
  صحيح __cdecl isleadbyte(صحيح _C);
  _CRTIMP صحيح __cdecl _isleadbyte_l(صحيح _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP صحيح __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP صحيح __cdecl __iswcsymf(wint_t _C);
  _CRTIMP صحيح __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl __iswcsym(wint_t _C);
  _CRTIMP صحيح __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  صحيح __cdecl is_wctype(wint_t _C,wctype_t _Type);

#إذا (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
صحيح __cdecl iswblank(wint_t _C);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _CTYPE_DISABLE_MACROS

#که_نه_تعریف_شوی MB_CUR_MAX
#تعریف_کړه MB_CUR_MAX ___mb_cur_max_func()
#که_نه_تعریف_شوی __mb_cur_max
#که_تعریف_شوی _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#تعریف_کړه __mb_cur_max	(*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#د_که_پای
#د_که_پای
#که_تعریف_شوی _MSVCRT_
#تعریف_کړه ___mb_cur_max_func() (__mb_cur_max)
#وإلا
#تعریف_کړه ___mb_cur_max_func() (*_imp____mb_cur_max)
#د_که_پای
#د_که_پای

#تعریف_کړه __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#تعریف_کړه _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#تعریف_کړه _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=عدم && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#تعریف_کړه _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#تعریف_کړه _isupper_l(_Char,_Locale) _ischartype_l(_Char,پاسنی_3,_Locale)
#تعریف_کړه _islower_l(_Char,_Locale) _ischartype_l(_Char,ښکتنی_2,_Locale)
#تعریف_کړه _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#تعریف_کړه _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#تعریف_کړه _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#تعریف_کړه _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#تعریف_کړه _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#تعریف_کړه _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#تعریف_کړه _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#تعریف_کړه _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#تعریف_کړه _tolower(_Char) ((_Char)-'A'+'a')
#تعریف_کړه _toupper(_Char) ((_Char)-'a'+'A')
#تعریف_کړه __isascii(_Char) ((بینښه)(_Char) < 0x80)
#تعریف_کړه __toascii(_Char) ((_Char) & 0x7f)

#که_نه_تعریف_شوی _WCTYPE_INLINE_DEFINED
#تعریف_کړه _WCTYPE_INLINE_DEFINED

#تعریف_لغوه _CRT_WCTYPE_NOINLINE
#که_نه_تعریف_شوی __cplusplus
#تعریف_کړه iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کړه iswupper(_c) (iswctype(_c,پاسنی_3))
#تعریف_کړه iswlower(_c) (iswctype(_c,ښکتنی_2))
#تعریف_کړه iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کړه iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کړه iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کړه iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کړه iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کړه iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کړه iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کړه iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کړه iswascii(_c) ((بینښه)(_c) < 0x80)
#تعریف_کړه _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کړه _iswupper_l(_c,_p) (_iswctype_l(_c,پاسنی_3,_p))
#تعریف_کړه _iswlower_l(_c,_p) (_iswctype_l(_c,ښکتنی_2,_p))
#تعریف_کړه _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کړه _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کړه _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کړه _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کړه _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کړه _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کړه _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کړه _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#د_که_پای
#د_که_پای

#تعریف_کړه __iscsymf(_c) (که_توری(_c) || ((_c)=='_'))
#تعریف_کړه __iscsym(_c) (که_توری_یا_عدد(_c) || ((_c)=='_'))
#تعریف_کړه __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#تعریف_کړه __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#تعریف_کړه _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کړه _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#تعریف_کړه _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کړه _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
#که_نه_تعریف_شوی _CTYPE_DEFINED
  صحيح __cdecl isascii(صحيح _C);
  صحيح __cdecl toascii(صحيح _C);
  صحيح __cdecl iscsymf(صحيح _C);
  صحيح __cdecl iscsym(صحيح _C);
#وإلا
#تعریف_کړه isascii __isascii
#تعریف_کړه toascii __toascii
#تعریف_کړه iscsymf __iscsymf
#تعریف_کړه iscsym __iscsym
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
