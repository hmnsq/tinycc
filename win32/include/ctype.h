/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_CTYPE
#تعریف_کرو _INC_CTYPE

#شامل <_mingw.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_CTYPEDATA_DEFINED
#تعریف_کرو _CRT_CTYPEDATA_DEFINED
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS

#اگر_غیر_تعریف_شدہ __PCTYPE_FUNC
#تعریف_کرو __PCTYPE_FUNC __pctype_func()
#اگر_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pctype_func()	(_pctype)
#ورنہ
#تعریف_کرو __pctype_func()	(*_imp___pctype)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _pctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_pctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___pctype;
#تعریف_کرو _pctype (*_imp___pctype)
#اگر_ختم
#اگر_ختم

#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_WCTYPEDATA_DEFINED
#تعریف_کرو _CRT_WCTYPEDATA_DEFINED
#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS
#اگر_غیر_تعریف_شدہ _wctype
#اگر_تعریف_شدہ _MSVCRT_
  خارجی غیرعلامتی مختصر *_wctype;
#ورنہ
  خارجی غیرعلامتی مختصر **_imp___wctype;
#تعریف_کرو _wctype (*_imp___wctype)
#اگر_ختم
#اگر_ختم
#اگر_تعریف_شدہ _MSVCRT_
#تعریف_کرو __pwctype_func() (_pwctype)
#اگر_غیر_تعریف_شدہ _pwctype
  خارجی غیرعلامتی مختصر *_pwctype;
#اگر_ختم
#ورنہ
#تعریف_کرو __pwctype_func() (*_imp___pwctype)
#اگر_غیر_تعریف_شدہ _pwctype
  خارجی غیرعلامتی مختصر **_imp___pwctype;
#تعریف_کرو _pwctype (*_imp___pwctype)
#اگر_ختم
#اگر_ختم
#اگر_ختم
#اگر_ختم

  /* CRT stuff */
#اگر 1
  خارجی ثابت غیرعلامتی حرف __newclmap[];
  خارجی ثابت غیرعلامتی حرف __newcumap[];
  خارجی pthreadlocinfo __ptlocinfo;
  خارجی pthreadmbcinfo __ptmbcinfo;
  خارجی صحیح __globallocalestatus;
  خارجی صحیح __locale_changed;
  خارجی ساخت threadlocaleinfostruct __initiallocinfo;
  خارجی _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(خالی);
  pthreadmbcinfo __cdecl __updatetmbcinfo(خالی);
#اگر_ختم

#تعریف_کرو بالائی_3 0x1
#تعریف_کرو زیریں_2 0x2
#تعریف_کرو _DIGIT 0x4
#تعریف_کرو _SPACE 0x8

#تعریف_کرو _PUNCT 0x10
#تعریف_کرو _CONTROL 0x20
#تعریف_کرو _BLANK 0x40
#تعریف_کرو _HEX 0x80

#تعریف_کرو _LEADBYTE 0x8000
#تعریف_کرو _ALPHA (0x0100|بالائی_3|زیریں_2)

#اگر_غیر_تعریف_شدہ _CTYPE_DEFINED
#تعریف_کرو _CTYPE_DEFINED

  _CRTIMP صحیح __cdecl _isctype(صحیح _C,صحیح _Type);
  _CRTIMP صحیح __cdecl _isctype_l(صحیح _C,صحیح _Type,_locale_t _Locale);
  _CRTIMP صحیح __cdecl حرف_ہے(صحیح _C);
  _CRTIMP صحیح __cdecl _isalpha_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl isupper(صحیح _C);
  _CRTIMP صحیح __cdecl _isupper_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl islower(صحیح _C);
  _CRTIMP صحیح __cdecl _islower_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl ہندسہ_ہے(صحیح _C);
  _CRTIMP صحیح __cdecl _isdigit_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl isxdigit(صحیح _C);
  _CRTIMP صحیح __cdecl _isxdigit_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl خلا_ہے(صحیح _C);
  _CRTIMP صحیح __cdecl _isspace_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl ispunct(صحیح _C);
  _CRTIMP صحیح __cdecl _ispunct_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl حرف_یا_ہندسہ(صحیح _C);
  _CRTIMP صحیح __cdecl _isalnum_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl isprint(صحیح _C);
  _CRTIMP صحیح __cdecl _isprint_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl isgraph(صحیح _C);
  _CRTIMP صحیح __cdecl _isgraph_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl iscntrl(صحیح _C);
  _CRTIMP صحیح __cdecl _iscntrl_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl بڑا_حرف(صحیح _C);
  _CRTIMP صحیح __cdecl tolower(صحیح _C);
  _CRTIMP صحیح __cdecl _tolower(صحیح _C);
  _CRTIMP صحیح __cdecl _tolower_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl _toupper(صحیح _C);
  _CRTIMP صحیح __cdecl _toupper_l(صحیح _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl __isascii(صحیح _C);
  _CRTIMP صحیح __cdecl __toascii(صحیح _C);
  _CRTIMP صحیح __cdecl __iscsymf(صحیح _C);
  _CRTIMP صحیح __cdecl __iscsym(صحیح _C);

#اگر (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
صحیح __cdecl isblank(صحیح _C);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCTYPE_DEFINED
#تعریف_کرو _WCTYPE_DEFINED

  صحیح __cdecl iswalpha(wint_t _C);
  _CRTIMP صحیح __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswupper(wint_t _C);
  _CRTIMP صحیح __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswlower(wint_t _C);
  _CRTIMP صحیح __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswdigit(wint_t _C);
  _CRTIMP صحیح __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswxdigit(wint_t _C);
  _CRTIMP صحیح __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswspace(wint_t _C);
  _CRTIMP صحیح __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswpunct(wint_t _C);
  _CRTIMP صحیح __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswalnum(wint_t _C);
  _CRTIMP صحیح __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswprint(wint_t _C);
  _CRTIMP صحیح __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswgraph(wint_t _C);
  _CRTIMP صحیح __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswcntrl(wint_t _C);
  _CRTIMP صحیح __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswascii(wint_t _C);
  صحیح __cdecl isleadbyte(صحیح _C);
  _CRTIMP صحیح __cdecl _isleadbyte_l(صحیح _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP صحیح __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP صحیح __cdecl __iswcsymf(wint_t _C);
  _CRTIMP صحیح __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP صحیح __cdecl __iswcsym(wint_t _C);
  _CRTIMP صحیح __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  صحیح __cdecl is_wctype(wint_t _C,wctype_t _Type);

#اگر (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
صحیح __cdecl iswblank(wint_t _C);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CTYPE_DISABLE_MACROS

#اگر_غیر_تعریف_شدہ MB_CUR_MAX
#تعریف_کرو MB_CUR_MAX ___mb_cur_max_func()
#اگر_غیر_تعریف_شدہ __mb_cur_max
#اگر_تعریف_شدہ _MSVCRT_
  خارجی صحیح __mb_cur_max;
#ورنہ
#تعریف_کرو __mb_cur_max	(*_imp____mb_cur_max)
  خارجی صحیح *_imp____mb_cur_max;
#اگر_ختم
#اگر_ختم
#اگر_تعریف_شدہ _MSVCRT_
#تعریف_کرو ___mb_cur_max_func() (__mb_cur_max)
#ورنہ
#تعریف_کرو ___mb_cur_max_func() (*_imp____mb_cur_max)
#اگر_ختم
#اگر_ختم

#تعریف_کرو __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#تعریف_کرو _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#تعریف_کرو _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=تہی && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#تعریف_کرو _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#تعریف_کرو _isupper_l(_Char,_Locale) _ischartype_l(_Char,بالائی_3,_Locale)
#تعریف_کرو _islower_l(_Char,_Locale) _ischartype_l(_Char,زیریں_2,_Locale)
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
#تعریف_کرو __isascii(_Char) ((غیرعلامتی)(_Char) < 0x80)
#تعریف_کرو __toascii(_Char) ((_Char) & 0x7f)

#اگر_غیر_تعریف_شدہ _WCTYPE_INLINE_DEFINED
#تعریف_کرو _WCTYPE_INLINE_DEFINED

#تعریف_منسوخ _CRT_WCTYPE_NOINLINE
#اگر_غیر_تعریف_شدہ __cplusplus
#تعریف_کرو iswalpha(_c) (iswctype(_c,_ALPHA))
#تعریف_کرو iswupper(_c) (iswctype(_c,بالائی_3))
#تعریف_کرو iswlower(_c) (iswctype(_c,زیریں_2))
#تعریف_کرو iswdigit(_c) (iswctype(_c,_DIGIT))
#تعریف_کرو iswxdigit(_c) (iswctype(_c,_HEX))
#تعریف_کرو iswspace(_c) (iswctype(_c,_SPACE))
#تعریف_کرو iswpunct(_c) (iswctype(_c,_PUNCT))
#تعریف_کرو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#تعریف_کرو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#تعریف_کرو iswcntrl(_c) (iswctype(_c,_CONTROL))
#تعریف_کرو iswascii(_c) ((غیرعلامتی)(_c) < 0x80)
#تعریف_کرو _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#تعریف_کرو _iswupper_l(_c,_p) (_iswctype_l(_c,بالائی_3,_p))
#تعریف_کرو _iswlower_l(_c,_p) (_iswctype_l(_c,زیریں_2,_p))
#تعریف_کرو _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#تعریف_کرو _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#تعریف_کرو _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#تعریف_کرو _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#تعریف_کرو _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#تعریف_کرو _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#اگر_ختم
#اگر_ختم

#تعریف_کرو __iscsymf(_c) (حرف_ہے(_c) || ((_c)=='_'))
#تعریف_کرو __iscsym(_c) (حرف_یا_ہندسہ(_c) || ((_c)=='_'))
#تعریف_کرو __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#تعریف_کرو __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#تعریف_کرو _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کرو _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#تعریف_کرو _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#تعریف_کرو _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#اگر_غیر_تعریف_شدہ _CTYPE_DEFINED
  صحیح __cdecl isascii(صحیح _C);
  صحیح __cdecl toascii(صحیح _C);
  صحیح __cdecl iscsymf(صحیح _C);
  صحیح __cdecl iscsym(صحیح _C);
#ورنہ
#تعریف_کرو isascii __isascii
#تعریف_کرو toascii __toascii
#تعریف_کرو iscsymf __iscsymf
#تعریف_کرو iscsym __iscsym
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
