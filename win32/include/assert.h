/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् __ASSERT_H_
#परिभाषय __ASSERT_H_

#अन्तर्भाव <_mingw.h>
#यदि_परिभाषितम् __cplusplus
#अन्तर्भाव <stdlib.h>
#यदि_अन्तः

#यदि_परिभाषितम् NDEBUG
#यदि_अपरिभाषितम् प्रतिज्ञा
#परिभाषय प्रतिज्ञा(_Expression) ((शून्य)0)
#यदि_अन्तः
#अन्यथा

#यदि_अपरिभाषितम् _CRT_TERMINATE_DEFINED
#परिभाषय _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निर्गच्छ(पूर्णाङ्क संहिता_3) __MINGW_ATTRIB_NORETURN;
 _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णाङ्क संहिता_3) __MINGW_ATTRIB_NORETURN;
#यदि !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
शून्य __cdecl _Exit(पूर्णाङ्क) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN शून्य __cdecl _Exit(पूर्णाङ्क स्थितिः)
{  _exit(स्थितिः); }
#यदि_अन्तः

#निर्देशः प्रक्षिप_macro("abort")
#अपरिभाषय abort
  शून्य __cdecl __declspec(noreturn) abort(शून्य);
#निर्देशः निष्कासय_macro("abort")

#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः


बाह्य शून्य __cdecl _wassert(ध्रुव wchar_t *सन्देशः_4,ध्रुव wchar_t *_File,अचिह्नित पङ्क्तिः_2);
बाह्य शून्य __cdecl _assert(ध्रुव वर्ण *, ध्रुव वर्ण *, अचिह्नित);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अपरिभाषितम् प्रतिज्ञा
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#परिभाषय प्रतिज्ञा(e) ((e) ? (शून्य)0 : _assert(#e, __FILE__, __LINE__))
#यदि_अन्तः

#यदि_अन्तः

#यदि (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#परिभाषय static_assert(घातांकः, str) _Static_assert(घातांकः, str) 
#यदि_अन्तः

#यदि_अन्तः
