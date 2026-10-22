/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_CTYPE
#تعریف_کرو _INC_CTYPE

#ضمن <_mingw.h>

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#جے_انت

#جے_بنا_تعریف _CRT_CTYPEDATA_DEFINED
#تعریف_کرو _CRT_CTYPEDATA_DEFINED
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS

#جے_بنا_تعریف __PCTYPE_FUNC
#تعریف_کرو __PCTYPE_FUNC __pctype_func()
#جے_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pctype_func()	(_pctype)
#وإلا
#تعریف_کرو __pctype_func()	(*_imp___pctype)
#جے_انت
#جے_انت

#جے_بنا_تعریف _pctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_pctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___pctype;
#تعریف_کرو _pctype (*_imp___pctype)
#جے_انت
#جے_انت

#جے_انت
#جے_انت

#جے_بنا_تعریف _CRT_WCTYPEDATA_DEFINED
#تعریف_کرو _CRT_WCTYPEDATA_DEFINED
#جے_بنا_تعریف _CTYPE_DISABLE_MACROS
#جے_بنا_تعریف _wctype
#جے_تعریف_شدہ _MSVCRT_
  خارجي بنانشانی چھوٹا *_wctype;
#وإلا
  خارجي بنانشانی چھوٹا **_imp___wctype;
#تعریف_کرو _wctype (*_imp___wctype)
#جے_انت
#جے_انت
#جے_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pwctype_func() (_pwctype)
#جے_بنا_تعریف _pwctype
  خارجي بنانشانی چھوٹا *_pwctype;
#جے_انت
#وإلا
#تعریف_کرو __pwctype_func() (*_imp___pwctype)
#جے_بنا_تعریف _pwctype
  خارجي بنانشانی چھوٹا **_imp___pwctype;
#تعریف_کرو _pwctype (*_imp___pwctype)
#جے_انت
#جے_انت
#جے_انت
#جے_انت

  /* CRT stuff */
#إذا 1
  خارجي ثابت بنانشانی حرف __newclmap[];
  خارجي ثابت بنانشانی حرف __newcumap[];
  خارجي pthreadlocinfo __ptlocinfo;
  خارجي pthreadmbcinfo __ptmbcinfo;
  خارجي صحيح __globallocalestatus;
  خارجي صحيح __locale_changed;
  خارجي بنية threadlocaleinfostruct __initiallocinfo;
  خارجي _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(فراغ);
  pthreadmbcinfo __cdecl __updatetmbcinfo(فراغ);
#جے_انت

#تعریف_کرو اتلا_3 0x1
#تعریف_کرو ہیٹھلا_2 0x2
#تعریف_کرو _DIGIT 0x4
#تعریف_کرو _SPACE 0x8

#تعریف_کرو _PUNCT 0x10
#تعریف_کرو _CONTROL 0x20
#تعریف_کرو _BLANK 0x40
#تعریف_کرو _HEX 0x80

#تعریف_کرو _LEADBYTE 0x8000
#تعریف_کرو _ALPHA (0x0100|اتلا_3|ہیٹھلا_2)

#جے_بنا_تعریف _CTYPE_DEFINED
#تعریف_کرو _CTYPE_DEFINED

  _CRTIMP صحيح __cdecl _isctype(صحيح _C,صحيح _Type);
  _CRTIMP صحيح __cdecl _isctype_l(صحيح _C,صحيح _Type,_locale_t _Locale);
  _CRTIMP صحيح __cdecl حرف_اے(صحيح _C);
  _CRTIMP صحيح __cdecl _isalpha_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isupper(صحيح _C);
  _CRTIMP صحيح __cdecl _isupper_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl islower(صحيح _C);
  _CRTIMP صحيح __cdecl _islower_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl ہندسہ_اے(صحيح _C);
  _CRTIMP صحيح __cdecl _isdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isxdigit(صحيح _C);
  _CRTIMP صحيح __cdecl _isxdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl خلا_اے(صحيح _C);
  _CRTIMP صحيح __cdecl _isspace_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl ispunct(صحيح _C);
  _CRTIMP صحيح __cdecl _ispunct_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl حرف_یا_ہندسہ(صحيح _C);
  _CRTIMP صحيح __cdecl _isalnum_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isprint(صحيح _C);
  _CRTIMP صحيح __cdecl _isprint_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isgraph(صحيح _C);
  _CRTIMP صحيح __cdecl _isgraph_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl iscntrl(صحيح _C);
  _CRTIMP صحيح __cdecl _iscntrl_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl وڈا_حرف(صحيح _C);
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
#جے_انت
#جے_انت

#جے_بنا_تعریف _WCTYPE_DEFINED
#تعریف_کرو _WCTYPE_DEFINED

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
#جے_انت
#جے_انت

#جے_بنا_تعریف _CTYPE_DISABLE_MACROS

#جے_بنا_تعریف MB_CUR_MAX
#تعریف_کرو MB_CUR_MAX ___mb_cur_max_func()
#جے_بنا_تعریف __mb_cur_max
#جے_تعریف_شدہ _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#تعریف_کرو __mb_cur_max	(*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#جے_انت
#جے_انت
#جے_تعریف_شدہ _MSVCRT_
#تعریف_کرو ___mb_cur_max_func() (__mb_cur_max)
#وإلا
#تعریف_کرو ___mb_cur_max_func() (*_imp____mb_cur_max)
#جے_انت
#جے_انت

#تعریف_کرو __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#تعریف_کرو _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#تعریف_کرو _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=عدم && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#تعریف_کرو _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#تعریف_کرو _isupper_l(_Char,_Locale) _ischartype_l(_Char,اتلا_3,_Locale)
#تعریف_کرو _islower_l(_Char,_Locale) _ischartype_l(_Char,ہیٹھلا_2,_Locale)
#تعریف_کرو _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#تعریف_کرو _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#تعریف_کرو _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#تعریف_کرو _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#تعریف_کرو _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#تعریف_کرو _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#تعریف_کرو _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#تعریف_کرو _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#تعریف_کرو _tolower(_Char) ((_Char)-'A'+'a')
#تعریف_کرو _toupper(_Char) ((_Char)-'a'+'A')
#تعریف_کرو __isascii(_Char) ((بنانشانی)(_Char) < 0x80)
#تعریف_کرو __toascii(_Char) ((_Char) & 0x7f)

#جے_بنا_تعریف _WCTYPE_INLINE_DEFINED
#تعریف_کرو _WCTYPE_INLINE_DEFINED

#تعریف_رد _CRT_WCTYPE_NOINLINE
#جے_بنا_تعریف __cplusplus
#تعریف_کرو iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کرو iswupper(_c) (iswctype(_c,اتلا_3))
#تعریف_کرو iswlower(_c) (iswctype(_c,ہیٹھلا_2))
#تعریف_کرو iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کرو iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کرو iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کرو iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کرو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کرو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کرو iswascii(_c) ((بنانشانی)(_c) < 0x80)
#تعریف_کرو _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کرو _iswupper_l(_c,_p) (_iswctype_l(_c,اتلا_3,_p))
#تعریف_کرو _iswlower_l(_c,_p) (_iswctype_l(_c,ہیٹھلا_2,_p))
#تعریف_کرو _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کرو _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کرو _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کرو _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کرو _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#جے_انت
#جے_انت

#تعریف_کرو __iscsymf(_c) (حرف_اے(_c) || ((_c)=='_'))
#تعریف_کرو __iscsym(_c) (حرف_یا_ہندسہ(_c) || ((_c)=='_'))
#تعریف_کرو __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#تعریف_کرو __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#تعریف_کرو _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کرو _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#تعریف_کرو _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کرو _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
#جے_بنا_تعریف _CTYPE_DEFINED
  صحيح __cdecl isascii(صحيح _C);
  صحيح __cdecl toascii(صحيح _C);
  صحيح __cdecl iscsymf(صحيح _C);
  صحيح __cdecl iscsym(صحيح _C);
#وإلا
#تعریف_کرو isascii __isascii
#تعریف_کرو toascii __toascii
#تعریف_کرو iscsymf __iscsymf
#تعریف_کرو iscsym __iscsym
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
