#अगर_अघोषित _STDDEF_H
#घोषणा _STDDEF_H

प्रकार __SIZE_TYPE__ माप_प्रकार;
प्रकार __PTRDIFF_TYPE__ ssize_t;
प्रकार __WCHAR_TYPE__ ब_अक्षर_प्रकार;
प्रकार __PTRDIFF_TYPE__ सूचक_भेद_प्रकार;
प्रकार __PTRDIFF_TYPE__ intptr_t;
प्रकार __SIZE_TYPE__ uintptr_t;

#अगर __STDC_VERSION__ >= 201112L
प्रकार जोड़ { दीर्घ दीर्घ __ll; दीर्घ द्विगुन __ld; } max_align_t;
#पूर्ण_अगर

#अगर_अघोषित शून्य
#घोषणा शून्य ((व्योम*)0)
#पूर्ण_अगर

#अघोषित दुरत्व
#घोषणा दुरत्व(type, field) __builtin_offsetof(type, field)

व्योम *alloca(माप_प्रकार आकार);

#पूर्ण_अगर

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   define this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs define _WINT_T
   if they've already provided that type, so we can use that as guard.
   TCC defines __WINT_TYPE__ for us.  */
#अगर defined (__need_wint_t)
#अगर_अघोषित _WINT_T
#घोषणा _WINT_T
प्रकार __WINT_TYPE__ wint_t;
#पूर्ण_अगर
#अघोषित __need_wint_t
#पूर्ण_अगर
