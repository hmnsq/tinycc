/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_CTYPE
#నిర్వచించు _INC_CTYPE

#అన్తర్భావ <_mingw.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_CTYPEDATA_DEFINED
#నిర్వచించు _CRT_CTYPEDATA_DEFINED
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS

#నిర్వచితం_కాకపోతే __PCTYPE_FUNC
#నిర్వచించు __PCTYPE_FUNC __pctype_func()
#నిర్వచితమైతే _MSVCRT_
#నిర్వచించు __pctype_func()	(_pctype)
#లేకపోతే
#నిర్వచించు __pctype_func()	(*_imp___pctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _pctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_pctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___pctype;
#నిర్వచించు _pctype (*_imp___pctype)
#అయితే_ముగింపు
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_WCTYPEDATA_DEFINED
#నిర్వచించు _CRT_WCTYPEDATA_DEFINED
#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS
#నిర్వచితం_కాకపోతే _wctype
#నిర్వచితమైతే _MSVCRT_
  బాహ్య గుర్తులేని పొట్టి *_wctype;
#లేకపోతే
  బాహ్య గుర్తులేని పొట్టి **_imp___wctype;
#నిర్వచించు _wctype (*_imp___wctype)
#అయితే_ముగింపు
#అయితే_ముగింపు
#నిర్వచితమైతే _MSVCRT_
#నిర్వచించు __pwctype_func() (_pwctype)
#నిర్వచితం_కాకపోతే _pwctype
  బాహ్య గుర్తులేని పొట్టి *_pwctype;
#అయితే_ముగింపు
#లేకపోతే
#నిర్వచించు __pwctype_func() (*_imp___pwctype)
#నిర్వచితం_కాకపోతే _pwctype
  బాహ్య గుర్తులేని పొట్టి **_imp___pwctype;
#నిర్వచించు _pwctype (*_imp___pwctype)
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

  /* CRT stuff */
#ఒకవేళ 1
  బాహ్య స్థిరరాశి గుర్తులేని అక్షరం __newclmap[];
  బాహ్య స్థిరరాశి గుర్తులేని అక్షరం __newcumap[];
  బాహ్య pthreadlocinfo __ptlocinfo;
  బాహ్య pthreadmbcinfo __ptmbcinfo;
  బాహ్య పూర్ణాంకం __globallocalestatus;
  బాహ్య పూర్ణాంకం __locale_changed;
  బాహ్య నిర్మాణం threadlocaleinfostruct __initiallocinfo;
  బాహ్య _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(శూన్య);
  pthreadmbcinfo __cdecl __updatetmbcinfo(శూన్య);
#అయితే_ముగింపు

#నిర్వచించు పై_3 0x1
#నిర్వచించు క్రింది_2 0x2
#నిర్వచించు _DIGIT 0x4
#నిర్వచించు _SPACE 0x8

#నిర్వచించు _PUNCT 0x10
#నిర్వచించు _CONTROL 0x20
#నిర్వచించు _BLANK 0x40
#నిర్వచించు _HEX 0x80

#నిర్వచించు _LEADBYTE 0x8000
#నిర్వచించు _ALPHA (0x0100|పై_3|క్రింది_2)

#నిర్వచితం_కాకపోతే _CTYPE_DEFINED
#నిర్వచించు _CTYPE_DEFINED

  _CRTIMP పూర్ణాంకం __cdecl _isctype(పూర్ణాంకం _C,పూర్ణాంకం _Type);
  _CRTIMP పూర్ణాంకం __cdecl _isctype_l(పూర్ణాంకం _C,పూర్ణాంకం _Type,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl అక్షరమా(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isalpha_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl isupper(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isupper_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl islower(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _islower_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl అంకెనా(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isdigit_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl isxdigit(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isxdigit_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl ఖాళీనా(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isspace_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl ispunct(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _ispunct_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl అక్షరమా_అంకెనా(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isalnum_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl isprint(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isprint_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl isgraph(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isgraph_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl iscntrl(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _iscntrl_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl పెద్ద_అక్షరం(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl tolower(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _tolower(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _tolower_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl _toupper(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _toupper_l(పూర్ణాంకం _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl __isascii(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl __toascii(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl __iscsymf(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl __iscsym(పూర్ణాంకం _C);

#ఒకవేళ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
పూర్ణాంకం __cdecl isblank(పూర్ణాంకం _C);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCTYPE_DEFINED
#నిర్వచించు _WCTYPE_DEFINED

  పూర్ణాంకం __cdecl iswalpha(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswupper(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswlower(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswdigit(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswxdigit(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswspace(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswpunct(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswalnum(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswprint(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswgraph(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswcntrl(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswascii(wint_t _C);
  పూర్ణాంకం __cdecl isleadbyte(పూర్ణాంకం _C);
  _CRTIMP పూర్ణాంకం __cdecl _isleadbyte_l(పూర్ణాంకం _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP పూర్ణాంకం __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl __iswcsymf(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP పూర్ణాంకం __cdecl __iswcsym(wint_t _C);
  _CRTIMP పూర్ణాంకం __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  పూర్ణాంకం __cdecl is_wctype(wint_t _C,wctype_t _Type);

#ఒకవేళ (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
పూర్ణాంకం __cdecl iswblank(wint_t _C);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CTYPE_DISABLE_MACROS

#నిర్వచితం_కాకపోతే MB_CUR_MAX
#నిర్వచించు MB_CUR_MAX ___mb_cur_max_func()
#నిర్వచితం_కాకపోతే __mb_cur_max
#నిర్వచితమైతే _MSVCRT_
  బాహ్య పూర్ణాంకం __mb_cur_max;
#లేకపోతే
#నిర్వచించు __mb_cur_max	(*_imp____mb_cur_max)
  బాహ్య పూర్ణాంకం *_imp____mb_cur_max;
#అయితే_ముగింపు
#అయితే_ముగింపు
#నిర్వచితమైతే _MSVCRT_
#నిర్వచించు ___mb_cur_max_func() (__mb_cur_max)
#లేకపోతే
#నిర్వచించు ___mb_cur_max_func() (*_imp____mb_cur_max)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#నిర్వచించు _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#నిర్వచించు _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=ఖాళీ && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#నిర్వచించు _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#నిర్వచించు _isupper_l(_Char,_Locale) _ischartype_l(_Char,పై_3,_Locale)
#నిర్వచించు _islower_l(_Char,_Locale) _ischartype_l(_Char,క్రింది_2,_Locale)
#నిర్వచించు _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#నిర్వచించు _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#నిర్వచించు _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#నిర్వచించు _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#నిర్వచించు _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#నిర్వచించు _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#నిర్వచించు _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#నిర్వచించు _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#నిర్వచించు _tolower(_Char) ((_Char)-'A'+'a')
#నిర్వచించు _toupper(_Char) ((_Char)-'a'+'A')
#నిర్వచించు __isascii(_Char) ((గుర్తులేని)(_Char) < 0x80)
#నిర్వచించు __toascii(_Char) ((_Char) & 0x7f)

#నిర్వచితం_కాకపోతే _WCTYPE_INLINE_DEFINED
#నిర్వచించు _WCTYPE_INLINE_DEFINED

#నిర్వచనం_రద్దు _CRT_WCTYPE_NOINLINE
#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచించు iswalpha(_c) (iswctype(_c,_ALPHA))
#నిర్వచించు iswupper(_c) (iswctype(_c,పై_3))
#నిర్వచించు iswlower(_c) (iswctype(_c,క్రింది_2))
#నిర్వచించు iswdigit(_c) (iswctype(_c,_DIGIT))
#నిర్వచించు iswxdigit(_c) (iswctype(_c,_HEX))
#నిర్వచించు iswspace(_c) (iswctype(_c,_SPACE))
#నిర్వచించు iswpunct(_c) (iswctype(_c,_PUNCT))
#నిర్వచించు iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#నిర్వచించు iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#నిర్వచించు iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#నిర్వచించు iswcntrl(_c) (iswctype(_c,_CONTROL))
#నిర్వచించు iswascii(_c) ((గుర్తులేని)(_c) < 0x80)
#నిర్వచించు _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#నిర్వచించు _iswupper_l(_c,_p) (_iswctype_l(_c,పై_3,_p))
#నిర్వచించు _iswlower_l(_c,_p) (_iswctype_l(_c,క్రింది_2,_p))
#నిర్వచించు _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#నిర్వచించు _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#నిర్వచించు _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#నిర్వచించు _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#నిర్వచించు _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#నిర్వచించు _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#నిర్వచించు _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#నిర్వచించు _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు __iscsymf(_c) (అక్షరమా(_c) || ((_c)=='_'))
#నిర్వచించు __iscsym(_c) (అక్షరమా_అంకెనా(_c) || ((_c)=='_'))
#నిర్వచించు __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#నిర్వచించు __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#నిర్వచించు _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#నిర్వచించు _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#నిర్వచించు _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#నిర్వచించు _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచితం_కాకపోతే _CTYPE_DEFINED
  పూర్ణాంకం __cdecl isascii(పూర్ణాంకం _C);
  పూర్ణాంకం __cdecl toascii(పూర్ణాంకం _C);
  పూర్ణాంకం __cdecl iscsymf(పూర్ణాంకం _C);
  పూర్ణాంకం __cdecl iscsym(పూర్ణాంకం _C);
#లేకపోతే
#నిర్వచించు isascii __isascii
#నిర్వచించు toascii __toascii
#నిర్వచించు iscsymf __iscsymf
#నిర్వచించు iscsym __iscsym
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
