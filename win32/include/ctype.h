/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CTYPE
#define _INC_CTYPE

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifdef __cplusplus
ବାହ୍ୟ "C" {
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
#ଅନ୍ୟଥା
#define __pctype_func()	(*_imp___pctype)
#endif
#endif

#ifndef _pctype
#ifdef _MSVCRT_
  ବାହ୍ୟ unsigned short *_pctype;
#ଅନ୍ୟଥା
  ବାହ୍ୟ unsigned short **_imp___pctype;
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
  ବାହ୍ୟ unsigned short *_wctype;
#ଅନ୍ୟଥା
  ବାହ୍ୟ unsigned short **_imp___wctype;
#define _wctype (*_imp___wctype)
#endif
#endif
#ifdef _MSVCRT_
#define __pwctype_func() (_pwctype)
#ifndef _pwctype
  ବାହ୍ୟ unsigned short *_pwctype;
#endif
#ଅନ୍ୟଥା
#define __pwctype_func() (*_imp___pwctype)
#ifndef _pwctype
  ବାହ୍ୟ unsigned short **_imp___pwctype;
#define _pwctype (*_imp___pwctype)
#endif
#endif
#endif
#endif

  /* CRT stuff */
#ଯଦି 1
  ବାହ୍ୟ ଅଚଳ unsigned ଅକ୍ଷର __newclmap[];
  ବାହ୍ୟ ଅଚଳ unsigned ଅକ୍ଷର __newcumap[];
  ବାହ୍ୟ pthreadlocinfo __ptlocinfo;
  ବାହ୍ୟ pthreadmbcinfo __ptmbcinfo;
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __globallocalestatus;
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __locale_changed;
  ବାହ୍ୟ ସଂରଚନା threadlocaleinfostruct __initiallocinfo;
  ବାହ୍ୟ _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(ଶୂନ୍ୟ);
  pthreadmbcinfo __cdecl __updatetmbcinfo(ଶୂନ୍ୟ);
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

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isctype(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Type);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isctype_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Type,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isalpha(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isalpha_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isupper(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isupper_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl islower(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _islower_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isdigit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isdigit_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isxdigit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isxdigit_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isspace(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isspace_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ispunct(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _ispunct_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isalnum(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isalnum_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isprint(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isprint_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isgraph(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isgraph_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iscntrl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iscntrl_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl toupper(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl tolower(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _tolower(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _tolower_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _toupper(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _toupper_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __isascii(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __toascii(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __iscsymf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __iscsym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);

#ଯଦି (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isblank(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
#endif
#endif

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswalpha(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswupper(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswlower(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswdigit(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswxdigit(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswspace(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswpunct(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswalnum(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswprint(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswgraph(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswcntrl(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswascii(wint_t _C);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isleadbyte(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isleadbyte_l(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __iswcsymf(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __iswcsym(wint_t _C);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl is_wctype(wint_t _C,wctype_t _Type);

#ଯଦି (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !defined (NO_OLDNAMES)
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iswblank(wint_t _C);
#endif
#endif

#ifndef _CTYPE_DISABLE_MACROS

#ifndef MB_CUR_MAX
#define MB_CUR_MAX ___mb_cur_max_func()
#ifndef __mb_cur_max
#ifdef _MSVCRT_
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mb_cur_max;
#ଅନ୍ୟଥା
#define __mb_cur_max	(*_imp____mb_cur_max)
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_imp____mb_cur_max;
#endif
#endif
#ifdef _MSVCRT_
#define ___mb_cur_max_func() (__mb_cur_max)
#ଅନ୍ୟଥା
#define ___mb_cur_max_func() (*_imp____mb_cur_max)
#endif
#endif

#define __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#define _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#define _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=ଖାଲି && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
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
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isascii(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl toascii(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iscsymf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl iscsym(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _C);
#ଅନ୍ୟଥା
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
