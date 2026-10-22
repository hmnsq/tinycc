/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __ASSERT_H_
#define __ASSERT_H_

#अन्तर्भाव <_mingw.h>
#ifdef __cplusplus
#अन्तर्भाव <stdlib.h>
#endif

#ifdef न_संशोधन
#ifndef प्रतिज्ञा
#define प्रतिज्ञा(_Expression) ((शून्य)0)
#endif
#अन्यथा

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निकास(पूर्णाङ्क _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णाङ्क _Code) __MINGW_ATTRIB_NORETURN;
#यदि !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
शून्य __cdecl _Exit(पूर्णाङ्क) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN शून्य __cdecl _Exit(पूर्णाङ्क status)
{  _exit(status); }
#endif

#pragma धकेलो_macro("abort")
#undef पात
  शून्य __cdecl __declspec(noreturn) पात(शून्य);
#pragma निकालो_macro("abort")

#endif

#ifdef __cplusplus
बाह्य "C" {
#endif


बाह्य शून्य __cdecl _wassert(ध्रुव ब_अक्षर_प्रकार *_Message,ध्रुव ब_अक्षर_प्रकार *_File,अचिन्हित पंक्ति_2);
बाह्य शून्य __cdecl _assert(ध्रुव वर्ण *, ध्रुव वर्ण *, अचिन्हित);

#ifdef __cplusplus
}
#endif

#ifndef प्रतिज्ञा
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#define प्रतिज्ञा(e) ((e) ? (शून्य)0 : _assert(#e, __FILE__, __LINE__))
#endif

#endif

#यदि (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#define static_assert(exp, str) _Static_assert(exp, str) 
#endif

#endif
