/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित __ASSERT_H_
#घोषणा __ASSERT_H_

#समावेश <_mingw.h>
#अगर_घोषित __cplusplus
#समावेश <stdlib.h>
#पूर्ण_अगर

#अगर_घोषित न_संशोधन
#अगर_अघोषित निश्चित
#घोषणा निश्चित(_Expression) ((व्योम)0)
#पूर्ण_अगर
#अन्यथा

#अगर_अघोषित _CRT_TERMINATE_DEFINED
#घोषणा _CRT_TERMINATE_DEFINED
  व्योम __cdecl __MINGW_NOTHROW निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP व्योम __cdecl __MINGW_NOTHROW _निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
#अगर !defined __NO_ISOCEXT /* extern stub in static libmingwex.a */
/* C99 function name */
व्योम __cdecl _Exit(पूर्णांक) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN व्योम __cdecl _Exit(पूर्णांक status)
{  _निकास(status); }
#पूर्ण_अगर

#आशय धकेलो_macro("abort")
#अघोषित पात
  व्योम __cdecl __declspec(noreturn) पात(व्योम);
#आशय निकालो_macro("abort")

#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर


बाह्य व्योम __cdecl _wassert(स्थिर ब_अक्षर_प्रकार *_Message,स्थिर ब_अक्षर_प्रकार *_File,अचिन्हित पंक्ति_3);
बाह्य व्योम __cdecl _assert(स्थिर अक्षर *, स्थिर अक्षर *, अचिन्हित);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#अगर_अघोषित निश्चित
//#define assert(_Expression) (void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__FILE__),__LINE__),0))
#घोषणा निश्चित(e) ((e) ? (व्योम)0 : _assert(#e, __खाता__, __LINE__))
#पूर्ण_अगर

#पूर्ण_अगर

#अगर (__STDC_VERSION__ >= 201112L) && !defined(static_assert)
/* C11, section 7.2: The macro static_assert expands to _Static_assert. */
#घोषणा static_assert(exp, str) _Static_assert(exp, str) 
#पूर्ण_अगर

#पूर्ण_अगर
