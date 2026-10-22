/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_CTYPE
#وصف_ڪريو _INC_CTYPE

#ضمن <_mingw.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_CTYPEDATA_DEFINED
#وصف_ڪريو _CRT_CTYPEDATA_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS

#جيڪڏهن_وصف_نه_ٿيل __PCTYPE_FUNC
#وصف_ڪريو __PCTYPE_FUNC __pctype_func()
#جيڪڏهن_وصف_ٿيل _MSVCRT_
#وصف_ڪريو __pctype_func()	(_pctype)
#وإلا
#وصف_ڪريو __pctype_func()	(*_imp___pctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _pctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_pctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___pctype;
#وصف_ڪريو _pctype (*_imp___pctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_WCTYPEDATA_DEFINED
#وصف_ڪريو _CRT_WCTYPEDATA_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS
#جيڪڏهن_وصف_نه_ٿيل _wctype
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي بنانشان ننڍو *_wctype;
#وإلا
  خارجي بنانشان ننڍو **_imp___wctype;
#وصف_ڪريو _wctype (*_imp___wctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل _MSVCRT_
#وصف_ڪريو __pwctype_func() (_pwctype)
#جيڪڏهن_وصف_نه_ٿيل _pwctype
  خارجي بنانشان ننڍو *_pwctype;
#جيڪڏهن_پورو
#وإلا
#وصف_ڪريو __pwctype_func() (*_imp___pwctype)
#جيڪڏهن_وصف_نه_ٿيل _pwctype
  خارجي بنانشان ننڍو **_imp___pwctype;
#وصف_ڪريو _pwctype (*_imp___pwctype)
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  /* CRT stuff */
#إذا 1
  خارجي ثابت بنانشان حرف __newclmap[];
  خارجي ثابت بنانشان حرف __newcumap[];
  خارجي pthreadlocinfo __ptlocinfo;
  خارجي pthreadmbcinfo __ptmbcinfo;
  خارجي صحيح __globallocalestatus;
  خارجي صحيح __locale_changed;
  خارجي بنية threadlocaleinfostruct __initiallocinfo;
  خارجي _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(فراغ);
  pthreadmbcinfo __cdecl __updatetmbcinfo(فراغ);
#جيڪڏهن_پورو

#وصف_ڪريو مٿانهون_3 0x1
#وصف_ڪريو هيٺاهون_2 0x2
#وصف_ڪريو _DIGIT 0x4
#وصف_ڪريو _SPACE 0x8

#وصف_ڪريو _PUNCT 0x10
#وصف_ڪريو _CONTROL 0x20
#وصف_ڪريو _BLANK 0x40
#وصف_ڪريو _HEX 0x80

#وصف_ڪريو _LEADBYTE 0x8000
#وصف_ڪريو _ALPHA (0x0100|مٿانهون_3|هيٺاهون_2)

#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DEFINED
#وصف_ڪريو _CTYPE_DEFINED

  _CRTIMP صحيح __cdecl _isctype(صحيح _C,صحيح _Type);
  _CRTIMP صحيح __cdecl _isctype_l(صحيح _C,صحيح _Type,_locale_t _Locale);
  _CRTIMP صحيح __cdecl اکر_آهي(صحيح _C);
  _CRTIMP صحيح __cdecl _isalpha_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isupper(صحيح _C);
  _CRTIMP صحيح __cdecl _isupper_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl islower(صحيح _C);
  _CRTIMP صحيح __cdecl _islower_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl انگ_آهي(صحيح _C);
  _CRTIMP صحيح __cdecl _isdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isxdigit(صحيح _C);
  _CRTIMP صحيح __cdecl _isxdigit_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl خال_آهي(صحيح _C);
  _CRTIMP صحيح __cdecl _isspace_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl ispunct(صحيح _C);
  _CRTIMP صحيح __cdecl _ispunct_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl اکر_يا_انگ(صحيح _C);
  _CRTIMP صحيح __cdecl _isalnum_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isprint(صحيح _C);
  _CRTIMP صحيح __cdecl _isprint_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl isgraph(صحيح _C);
  _CRTIMP صحيح __cdecl _isgraph_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl iscntrl(صحيح _C);
  _CRTIMP صحيح __cdecl _iscntrl_l(صحيح _C,_locale_t _Locale);
  _CRTIMP صحيح __cdecl وڏو_اکر(صحيح _C);
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
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_DEFINED
#وصف_ڪريو _WCTYPE_DEFINED

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
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DISABLE_MACROS

#جيڪڏهن_وصف_نه_ٿيل MB_CUR_MAX
#وصف_ڪريو MB_CUR_MAX ___mb_cur_max_func()
#جيڪڏهن_وصف_نه_ٿيل __mb_cur_max
#جيڪڏهن_وصف_ٿيل _MSVCRT_
  خارجي صحيح __mb_cur_max;
#وإلا
#وصف_ڪريو __mb_cur_max	(*_imp____mb_cur_max)
  خارجي صحيح *_imp____mb_cur_max;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل _MSVCRT_
#وصف_ڪريو ___mb_cur_max_func() (__mb_cur_max)
#وإلا
#وصف_ڪريو ___mb_cur_max_func() (*_imp____mb_cur_max)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#وصف_ڪريو _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#وصف_ڪريو _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=عدم && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#وصف_ڪريو _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#وصف_ڪريو _isupper_l(_Char,_Locale) _ischartype_l(_Char,مٿانهون_3,_Locale)
#وصف_ڪريو _islower_l(_Char,_Locale) _ischartype_l(_Char,هيٺاهون_2,_Locale)
#وصف_ڪريو _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#وصف_ڪريو _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#وصف_ڪريو _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#وصف_ڪريو _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#وصف_ڪريو _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#وصف_ڪريو _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#وصف_ڪريو _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#وصف_ڪريو _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#وصف_ڪريو _tolower(_Char) ((_Char)-'A'+'a')
#وصف_ڪريو _toupper(_Char) ((_Char)-'a'+'A')
#وصف_ڪريو __isascii(_Char) ((بنانشان)(_Char) < 0x80)
#وصف_ڪريو __toascii(_Char) ((_Char) & 0x7f)

#جيڪڏهن_وصف_نه_ٿيل _WCTYPE_INLINE_DEFINED
#وصف_ڪريو _WCTYPE_INLINE_DEFINED

#وصف_رد _CRT_WCTYPE_NOINLINE
#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#وصف_ڪريو iswalpha(_c) (iswctype(_c,_ALPHA))
#وصف_ڪريو iswupper(_c) (iswctype(_c,مٿانهون_3))
#وصف_ڪريو iswlower(_c) (iswctype(_c,هيٺاهون_2))
#وصف_ڪريو iswdigit(_c) (iswctype(_c,_DIGIT))
#وصف_ڪريو iswxdigit(_c) (iswctype(_c,_HEX))
#وصف_ڪريو iswspace(_c) (iswctype(_c,_SPACE))
#وصف_ڪريو iswpunct(_c) (iswctype(_c,_PUNCT))
#وصف_ڪريو iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#وصف_ڪريو iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#وصف_ڪريو iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#وصف_ڪريو iswcntrl(_c) (iswctype(_c,_CONTROL))
#وصف_ڪريو iswascii(_c) ((بنانشان)(_c) < 0x80)
#وصف_ڪريو _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#وصف_ڪريو _iswupper_l(_c,_p) (_iswctype_l(_c,مٿانهون_3,_p))
#وصف_ڪريو _iswlower_l(_c,_p) (_iswctype_l(_c,هيٺاهون_2,_p))
#وصف_ڪريو _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#وصف_ڪريو _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#وصف_ڪريو _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#وصف_ڪريو _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#وصف_ڪريو _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#وصف_ڪريو _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#وصف_ڪريو _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#وصف_ڪريو _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو __iscsymf(_c) (اکر_آهي(_c) || ((_c)=='_'))
#وصف_ڪريو __iscsym(_c) (اکر_يا_انگ(_c) || ((_c)=='_'))
#وصف_ڪريو __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#وصف_ڪريو __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#وصف_ڪريو _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#وصف_ڪريو _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#وصف_ڪريو _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#وصف_ڪريو _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#جيڪڏهن_وصف_نه_ٿيل _CTYPE_DEFINED
  صحيح __cdecl isascii(صحيح _C);
  صحيح __cdecl toascii(صحيح _C);
  صحيح __cdecl iscsymf(صحيح _C);
  صحيح __cdecl iscsym(صحيح _C);
#وإلا
#وصف_ڪريو isascii __isascii
#وصف_ڪريو toascii __toascii
#وصف_ڪريو iscsymf __iscsymf
#وصف_ڪريو iscsym __iscsym
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
