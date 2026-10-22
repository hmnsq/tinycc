#ifndef _STDDEF_H
#define _STDDEF_H

प्रकारव्याख्या __SIZE_TYPE__ माप_प्रकार;
प्रकारव्याख्या __PTRDIFF_TYPE__ ssize_t;
प्रकारव्याख्या __WCHAR_TYPE__ ब_अक्षर_प्रकार;
प्रकारव्याख्या __PTRDIFF_TYPE__ सूचक_भेद_प्रकार;
प्रकारव्याख्या __PTRDIFF_TYPE__ intptr_t;
प्रकारव्याख्या __SIZE_TYPE__ uintptr_t;

#जर __STDC_VERSION__ >= 201112L
प्रकारव्याख्या संघ { दीर्घ दीर्घ __ll; दीर्घ द्विगुण __ld; } max_align_t;
#endif

#ifndef रिक्त
#define रिक्त ((शून्य*)0)
#endif

#undef दुरत्व
#define दुरत्व(type, field) __builtin_offsetof(type, field)

शून्य *alloca(माप_प्रकार size);

#endif

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#जर defined (__need_wint_t)
#ifndef _WINT_T
#define _WINT_T
प्रकारव्याख्या __WINT_TYPE__ wint_t;
#endif
#undef __need_wint_t
#endif
