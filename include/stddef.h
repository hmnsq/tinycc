#ifndef _STDDEF_H
#define _STDDEF_H

প্রকারনির্দেশ __SIZE_TYPE__ size_t;
প্রকারনির্দেশ __PTRDIFF_TYPE__ ssize_t;
প্রকারনির্দেশ __WCHAR_TYPE__ wchar_t;
প্রকারনির্দেশ __PTRDIFF_TYPE__ ptrdiff_t;
প্রকারনির্দেশ __PTRDIFF_TYPE__ intptr_t;
প্রকারনির্দেশ __SIZE_TYPE__ uintptr_t;

#যদি __STDC_VERSION__ >= 201112L
প্রকারনির্দেশ সঙ্ঘ { long long __ll; long দ্বিগুণ __ld; } max_align_t;
#endif

#ifndef রিক্ত
#define রিক্ত ((শূন্য*)0)
#endif

#undef offsetof
#define offsetof(type, field) __builtin_offsetof(type, field)

শূন্য *alloca(size_t size);

#endif

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#যদি defined (__need_wint_t)
#ifndef _WINT_T
#define _WINT_T
প্রকারনির্দেশ __WINT_TYPE__ wint_t;
#endif
#undef __need_wint_t
#endif
