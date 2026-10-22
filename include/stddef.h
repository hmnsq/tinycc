#यदि_अपरिभाषितम् _STDDEF_H
#परिभाषय _STDDEF_H

प्रकारनिर्देश __SIZE_TYPE__ आकार_t;
प्रकारनिर्देश __PTRDIFF_TYPE__ ssize_t;
प्रकारनिर्देश __WCHAR_TYPE__ wchar_t;
प्रकारनिर्देश __PTRDIFF_TYPE__ ptrdiff_t;
प्रकारनिर्देश __PTRDIFF_TYPE__ intptr_t;
प्रकारनिर्देश __SIZE_TYPE__ uintptr_t;

#यदि __STDC_VERSION__ >= 201112L
प्रकारनिर्देश सङ्घ { दीर्घ दीर्घ __ll; दीर्घ द्विगुण __ld; } max_align_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् रिक्त
#परिभाषय रिक्त ((शून्य*)0)
#यदि_अन्तः

#अपरिभाषय offsetof
#परिभाषय offsetof(type, क्षेत्रम्) __builtin_offsetof(type, क्षेत्रम्)

शून्य *alloca(आकार_t आकार);

#यदि_अन्तः

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#यदि defined (__need_wint_t)
#यदि_अपरिभाषितम् _WINT_T
#परिभाषय _WINT_T
प्रकारनिर्देश __WINT_TYPE__ wint_t;
#यदि_अन्तः
#अपरिभाषय __need_wint_t
#यदि_अन्तः
