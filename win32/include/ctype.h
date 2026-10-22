/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_CTYPE
#تعریف_کن _INC_CTYPE

#ضمن <_mingw.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

#اگر_تعریف_نشده _CRT_CTYPEDATA_DEFINED
#تعریف_کن _CRT_CTYPEDATA_DEFINED
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS

#اگر_تعریف_نشده __PCTYPE_FUNC
#تعریف_کن __PCTYPE_FUNC __pctype_func()
#اگر_تعریف_شده _MSVCRT_
#تعریف_کن __pctype_func()	(_pctype)
#وإلا
#تعریف_کن __pctype_func()	(*_imp___pctype)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _pctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_pctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___pctype;
#تعریف_کن _pctype (*_imp___pctype)
#پایان_اگر
#پایان_اگر

#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CRT_WCTYPEDATA_DEFINED
#تعریف_کن _CRT_WCTYPEDATA_DEFINED
#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS
#اگر_تعریف_نشده _wctype
#اگر_تعریف_شده _MSVCRT_
  خارجي بیعلامت کوتاه *_wctype;
#وإلا
  خارجي بیعلامت کوتاه **_imp___wctype;
#تعریف_کن _wctype (*_imp___wctype)
#پایان_اگر
#پایان_اگر
#اگر_تعریف_شده _MSVCRT_
#تعریف_کن __pwctype_func() (_pwctype)
#اگر_تعریف_نشده _pwctype
  خارجي بیعلامت کوتاه *_pwctype;
#پایان_اگر
#وإلا
#تعریف_کن __pwctype_func() (*_imp___pwctype)
#اگر_تعریف_نشده _pwctype
  خارجي بیعلامت کوتاه **_imp___pwctype;
#تعریف_کن _pwctype (*_imp___pwctype)
#پایان_اگر
#پایان_اگر
#پایان_اگر
#پایان_اگر

  /* CRT stuff */
#إذا 1
  خارجي ثابت بیعلامت حرف __newclmap[];
  خارجي ثابت بیعلامت حرف __newcumap[];
  خارجي pthreadlocinfo __ptlocinfo;
  خارجي pthreadmbcinfo __ptmbcinfo;
  خارجي صحيح __globallocalestatus;
  خارجي صحيح __locale_changed;
  خارجي بنية threadlocaleinfostruct __initiallocinfo;
  خارجي _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(فراغ);
  pthreadmbcinfo __cdecl __updatetmbcinfo(فراغ);
#پایان_اگر

#تعریف_کن فوقانی_3 0x1
#تعریف_کن پایینی_2 0x2
#تعریف_کن _DIGIT 0x4
#تعریف_کن _SPACE 0x8

#تعریف_کن _PUNCT 0x10
#تعریف_کن _CONTROL 0x20
#تعریف_کن _BLANK 0x40
#تعریف_کن _HEX 0x80

#تعریف_کن _LEADBYTE 0x8000
#تعریف_کن _ALPHA (0x0100|فوقانی_3|پایینی_2)

#اگر_تعریف_نشده _CTYPE_DEFINED
#تعریف_کن _CTYPE_DEFINED

  _CRTIMP صحيح __cdecl _isctype(صحيح _C,صحيح _Type);
  _CRTIMP صحيح __cdecl _isctype_l(صحيح _C,صحيح _Type,_locale_t _Locale);
  _CRTIMP صحيح __cdecl آیا_حرف(صحيح _C);
  _CRTIMP صحيح __cdecl _isalpha_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isupper(صحيح _C);
  _CRTIMP صحيح __cdecl _isupper_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl islower(صحيح _C);
  _CRTIMP صحيح __cdecl _islower_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl آیا_رقم(صحيح _C);
  _CRTIMP صحيح __cdecl _isdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isxdigit(صحيح _C);
  _CRTIMP صحيح __cdecl _isxdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl آیا_فاصله(صحيح _C);
  _CRTIMP صحيح __cdecl _isspace_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl ispunct(صحيح _C);
  _CRTIMP صحيح __cdecl _ispunct_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl آیا_حرف_یا_رقم(صحيح _C);
  _CRTIMP صحيح __cdecl _isalnum_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isprint(صحيح _C);
  _CRTIMP صحيح __cdecl _isprint_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isgraph(صحيح _C);
  _CRTIMP صحيح __cdecl _isgraph_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl iscntrl(صحيح _C);
  _CRTIMP صحيح __cdecl _iscntrl_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl به_بزرگ(صحيح _C);
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
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _WCTYPE_DEFINED
#تعریف_کن _WCTYPE_DEFINED

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
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _CTYPE_DISABLE_MACROS

#اگر_تعریف_نشده MB_CUR_MAX
#تعریف_کن MB_CUR_MAX ___mb_cur_max_func()
#اگر_تعریف_نشده __mb_cur_max
#اگر_تعریف_شده _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#تعریف_کن __mb_cur_max	(*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#پایان_اگر
#پایان_اگر
#اگر_تعریف_شده _MSVCRT_
#تعریف_کن ___mb_cur_max_func() (__mb_cur_max)
#وإلا
#تعریف_کن ___mb_cur_max_func() (*_imp____mb_cur_max)
#پایان_اگر
#پایان_اگر

#تعریف_کن __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#تعریف_کن _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#تعریف_کن _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=عدم && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#تعریف_کن _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#تعریف_کن _isupper_l(_Char,_Locale) _ischartype_l(_Char,فوقانی_3,_Locale)
#تعریف_کن _islower_l(_Char,_Locale) _ischartype_l(_Char,پایینی_2,_Locale)
#تعریف_کن _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#تعریف_کن _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#تعریف_کن _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#تعریف_کن _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#تعریف_کن _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#تعریف_کن _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#تعریف_کن _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#تعریف_کن _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#تعریف_کن _tolower(_Char) ((_Char)-'A'+'a')
#تعریف_کن _toupper(_Char) ((_Char)-'a'+'A')
#تعریف_کن __isascii(_Char) ((بیعلامت)(_Char) < 0x80)
#تعریف_کن __toascii(_Char) ((_Char) & 0x7f)

#اگر_تعریف_نشده _WCTYPE_INLINE_DEFINED
#تعریف_کن _WCTYPE_INLINE_DEFINED

#لغو_تعریف _CRT_WCTYPE_NOINLINE
#اگر_تعریف_نشده __cplusplus
#تعریف_کن iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کن iswupper(_c) (iswctype(_c,فوقانی_3))
#تعریف_کن iswlower(_c) (iswctype(_c,پایینی_2))
#تعریف_کن iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کن iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کن iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کن iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کن iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کن iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کن iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کن iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کن iswascii(_c) ((بیعلامت)(_c) < 0x80)
#تعریف_کن _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کن _iswupper_l(_c,_p) (_iswctype_l(_c,فوقانی_3,_p))
#تعریف_کن _iswlower_l(_c,_p) (_iswctype_l(_c,پایینی_2,_p))
#تعریف_کن _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کن _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کن _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کن _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کن _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کن _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کن _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کن _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#پایان_اگر
#پایان_اگر

#تعریف_کن __iscsymf(_c) (آیا_حرف(_c) || ((_c)=='_'))
#تعریف_کن __iscsym(_c) (آیا_حرف_یا_رقم(_c) || ((_c)=='_'))
#تعریف_کن __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#تعریف_کن __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#تعریف_کن _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کن _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#تعریف_کن _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کن _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
#اگر_تعریف_نشده _CTYPE_DEFINED
  صحيح __cdecl isascii(صحيح _C);
  صحيح __cdecl toascii(صحيح _C);
  صحيح __cdecl iscsymf(صحيح _C);
  صحيح __cdecl iscsym(صحيح _C);
#وإلا
#تعریف_کن isascii __isascii
#تعریف_کن toascii __toascii
#تعریف_کن iscsymf __iscsymf
#تعریف_کن iscsym __iscsym
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
