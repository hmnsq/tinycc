/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_LOCALE
#define _INC_LOCALE

#அந்தர்பாவ <_mingw.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
#endif
#endif

#define LC_ALL 0
#define LC_COLLATE 1
#define LC_CTYPE 2
#define LC_MONETARY 3
#define LC_NUMERIC 4
#define LC_TIME 5

#define LC_MIN LC_ALL
#define LC_MAX LC_TIME

#ifndef _LCONV_DEFINED
#define _LCONV_DEFINED
  கட்டமைப்பு lconv {
    எழுத்து *decimal_point;
    எழுத்து *thousands_sep;
    எழுத்து *grouping;
    எழுத்து *int_curr_குறியீடு;
    எழுத்து *currency_குறியீடு;
    எழுத்து *mon_decimal_point;
    எழுத்து *mon_thousands_sep;
    எழுத்து *mon_grouping;
    எழுத்து *positive_sign;
    எழுத்து *negative_sign;
    எழுத்து int_frac_digits;
    எழுத்து frac_digits;
    எழுத்து p_cs_precedes;
    எழுத்து p_sep_by_space;
    எழுத்து n_cs_precedes;
    எழுத்து n_sep_by_space;
    எழுத்து p_sign_posn;
    எழுத்து n_sign_posn;
  };
#endif

#ifndef _CONFIG_LOCALE_SWT
#define _CONFIG_LOCALE_SWT

#define _ENABLE_PER_THREAD_LOCALE 0x1
#define _DISABLE_PER_THREAD_LOCALE 0x2
#define _ENABLE_PER_THREAD_LOCALE_GLOBAL 0x10
#define _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#define _ENABLE_PER_THREAD_LOCALE_NEW 0x100
#define _DISABLE_PER_THREAD_LOCALE_NEW 0x200

#endif

  முழு __cdecl _configthreadlocale(முழு _Flag);
  எழுத்து *__cdecl setlocale(முழு _Category,மாறிலி எழுத்து *_Locale);
  _CRTIMP கட்டமைப்பு lconv *__cdecl localeconv(வெறுமை);
  _locale_t __cdecl _get_current_locale(வெறுமை);
  _locale_t __cdecl _create_locale(முழு _Category,மாறிலி எழுத்து *_Locale);
  வெறுமை __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(வெறுமை);
  _locale_t __cdecl __create_locale(முழு _Category,மாறிலி எழுத்து *_Locale);
  வெறுமை __cdecl __free_locale(_locale_t _Locale);

#ifndef _WLOCALE_DEFINED
#define _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(முழு _Category,மாறிலி wchar_t *_Locale);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)
#endif
