/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CTYPE
#define _INC_CTYPE

#অন্তর্ভাৱ <_mingw.h>

#ifdef __cplusplus
বাহ্য "C" {
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
#define __pctype_func()	(_pctype)
#অন্যথা
#define __pctype_func()	(*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  বাহ্য unsigned short *_pctype;
#অন্যথা
  বাহ্য unsigned short **_imp___pctype;
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
  বাহ্য unsigned short *_wctype;
#অন্যথা
  বাহ্য unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif
#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#ifndef _pwctype
  বাহ্য unsigned short *_pwctype;
#endif
#অন্যথা
#define __pwctype_func() (*_imp___pwctype)
#ifndef _pwctype
  বাহ্য unsigned short **_imp___pwctype;
#define _pwctype (*_imp___pwctype)
#endif
#endif
#endif
#endif

  /* CRT stuff */
#যদি 1
  বাহ্য ধ্রুৱ unsigned ৱর্ণ __newclmap[];
  বাহ্য ধ্রুৱ unsigned ৱর্ণ __newcumap[];
  বাহ্য pthreadlocinfo __ptlocinfo;
  বাহ্য pthreadmbcinfo __ptmbcinfo;
  বাহ্য পূর্ণাঙ্ক __globallocalestatus;
  বাহ্য পূর্ণাঙ্ক __locale_changed;
  বাহ্য সংরচনা threadlocaleinfostruct __initiallocinfo;
  বাহ্য _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(শূন্য);
  pthreadmbcinfo __cdecl __updatetmbcinfo(শূন্য);
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

#ifndef _CTYPE_DEFINED
#define _CTYPE_DEFINED

  _CRTIMP পূর্ণাঙ্ক __cdecl _isctype(পূর্ণাঙ্ক _C,পূর্ণাঙ্ক _Type);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isctype_l(পূর্ণাঙ্ক _C,পূর্ণাঙ্ক _Type,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isalpha(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isalpha_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isupper(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isupper_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl islower(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _islower_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isdigit(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isdigit_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isxdigit(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isxdigit_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isspace(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isspace_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl ispunct(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _ispunct_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isalnum(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isalnum_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isprint(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isprint_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl isgraph(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isgraph_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl iscntrl(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iscntrl_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl toupper(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl tolower(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _tolower(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _tolower_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl _toupper(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _toupper_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl __isascii(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl __toascii(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl __iscsymf(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl __iscsym(পূর্ণাঙ্ক _C);

#যদি (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
পূর্ণাঙ্ক __cdecl isblank(পূর্ণাঙ্ক _C);
#endif
#endif

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED

  পূর্ণাঙ্ক __cdecl iswalpha(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswupper(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswlower(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswdigit(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswxdigit(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswspace(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswpunct(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswalnum(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswprint(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswgraph(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswcntrl(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswascii(wint_t _C);
  পূর্ণাঙ্ক __cdecl isleadbyte(পূর্ণাঙ্ক _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isleadbyte_l(পূর্ণাঙ্ক _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl __iswcsymf(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP পূর্ণাঙ্ক __cdecl __iswcsym(wint_t _C);
  _CRTIMP পূর্ণাঙ্ক __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  পূর্ণাঙ্ক __cdecl is_wctype(wint_t _C,wctype_t _Type);

#যদি (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
পূর্ণাঙ্ক __cdecl iswblank(wint_t _C);
#endif
#endif

#ifndef _CTYPE_DISABLE_MACROS

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  বাহ্য পূর্ণাঙ্ক __mb_cur_max;
#অন্যথা
#define __mb_cur_max	(*_imp____mb_cur_max)
  বাহ্য পূর্ণাঙ্ক *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
#define ___mb_cur_max_func() (__mb_cur_max)
#অন্যথা
#define ___mb_cur_max_func() (*_imp____mb_cur_max)
#endif
#endif

#define __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#define _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#define _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=রিক্ত && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#define _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#define _isupper_l(_Char,_Locale) _ischartype_l(_Char,_UPPER,_Locale)
#define _islower_l(_Char,_Locale) _ischartype_l(_Char,_LOWER,_Locale)
#define _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#define _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#define _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#define _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#define _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#define _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#define _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#define _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#define _tolower(_Char) ((_Char)-'A'+'a')
#define _toupper(_Char) ((_Char)-'a'+'A')
#define __isascii(_Char) ((unsigned)(_Char) < 0x80)
#define __toascii(_Char) ((_Char) & 0x7f)

#ifndef _WCTYPE_INLINE_DEFINED
#define _WCTYPE_INLINE_DEFINED

#undef _CRT_WCTYPE_NOINLINE
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
#define iswascii(_c) ((unsigned)(_c) < 0x80)
#define _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#define _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#define _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#define _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#define _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#define _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#define _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#define _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#define _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#define _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#define _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#endif
#endif

#define __iscsymf(_c) (isalpha(_c) || ((_c)=='_'))
#define __iscsym(_c) (isalnum(_c) || ((_c)=='_'))
#define __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#define __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#define _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#define _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#define _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#define _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#endif

#ifndef	NO_OLDNAMES
#ifndef _CTYPE_DEFINED
  পূর্ণাঙ্ক __cdecl isascii(পূর্ণাঙ্ক _C);
  পূর্ণাঙ্ক __cdecl toascii(পূর্ণাঙ্ক _C);
  পূর্ণাঙ্ক __cdecl iscsymf(পূর্ণাঙ্ক _C);
  পূর্ণাঙ্ক __cdecl iscsym(পূর্ণাঙ্ক _C);
#অন্যথা
#define isascii __isascii
#define toascii __toascii
#define iscsymf __iscsymf
#define iscsym __iscsym
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
