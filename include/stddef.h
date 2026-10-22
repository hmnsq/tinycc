#اگر_غیر_تعریف_شدہ _STDDEF_H
#تعریف_کرو _STDDEF_H

قسمتعریف __SIZE_TYPE__ سائز_t;
قسمتعریف __PTRDIFF_TYPE__ ssize_t;
قسمتعریف __WCHAR_TYPE__ wchar_t;
قسمتعریف __PTRDIFF_TYPE__ ptrdiff_t;
قسمتعریف __PTRDIFF_TYPE__ intptr_t;
قسمتعریف __SIZE_TYPE__ uintptr_t;

#اگر __STDC_VERSION__ >= 201112L
قسمتعریف اتحاد { طویل طویل __ll; طویل دوہرا __ld; } max_align_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ تہی
#تعریف_کرو تہی ((خالی*)0)
#اگر_ختم

#تعریف_منسوخ offsetof
#تعریف_کرو offsetof(type, میدان) __builtin_offsetof(type, میدان)

خالی *alloca(سائز_t سائز);

#اگر_ختم

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#اگر defined (__need_wint_t)
#اگر_غیر_تعریف_شدہ _WINT_T
#تعریف_کرو _WINT_T
قسمتعریف __WINT_TYPE__ wint_t;
#اگر_ختم
#تعریف_منسوخ __need_wint_t
#اگر_ختم
