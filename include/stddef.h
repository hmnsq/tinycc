#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDDEF_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDDEF_H

ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ ਮਾਪ_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __PTRDIFF_TYPE__ ssize_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __WCHAR_TYPE__ wchar_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __PTRDIFF_TYPE__ ptrdiff_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __PTRDIFF_TYPE__ intptr_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ uintptr_t;

#ਜੇ __STDC_VERSION__ >= 201112L
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ { ਲੰਮਾ ਲੰਮਾ __ll; ਲੰਮਾ ਦੁੱਗਣਾ __ld; } max_align_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਨਿਰਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ ((ਖਾਲੀ*)0)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ offsetof
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ offsetof(type, ਖੇਤਰ) __builtin_offsetof(type, ਖੇਤਰ)

ਖਾਲੀ *alloca(ਮਾਪ_t ਮਾਪ);

#ਜੇ_ਅੰਤ

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#ਜੇ defined (__need_wint_t)
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINT_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINT_T
ਕਿਸਮਪਰਿਭਾਸ਼ਾ __WINT_TYPE__ wint_t;
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __need_wint_t
#ਜੇ_ਅੰਤ
