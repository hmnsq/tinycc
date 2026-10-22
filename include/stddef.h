#ifndef _STDDEF_H
#define _STDDEF_H

تعریفنوع __SIZE_TYPE__ size_t;
تعریفنوع __PTRDIFF_TYPE__ ssize_t;
تعریفنوع __WCHAR_TYPE__ wchar_t;
تعریفنوع __PTRDIFF_TYPE__ ptrdiff_t;
تعریفنوع __PTRDIFF_TYPE__ intptr_t;
تعریفنوع __SIZE_TYPE__ uintptr_t;

#اگر __STDC_VERSION__ >= 201112L
تعریفنوع اجتماع { long long __ll; long دوگانه __ld; } max_align_t;
#endif

#ifndef پوچ
#define پوچ ((تهی*)0)
#endif

#undef offsetof
#define offsetof(type, field) __builtin_offsetof(type, field)

تهی *alloca(size_t size);

#endif

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#اگر defined (__need_wint_t)
#ifndef _WINT_T
#define _WINT_T
تعریفنوع __WINT_TYPE__ wint_t;
#endif
#undef __need_wint_t
#endif
