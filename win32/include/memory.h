/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_MEMORY
#define _INC_MEMORY

#अन्तर्भाव <_mingw.h>

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#define _WConst_return _CONST_RETURN

#ifndef _CRT_MEMORY_DEFINED
#define _CRT_MEMORY_DEFINED
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,अचर शून्य *_Src,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  _CONST_RETURN शून्य *__cdecl स_प्रथम(अचर शून्य *_Buf ,पूर्णाङ्क _Val,माप_प्रकार Max_गन्ती);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp_l(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size,_locale_t _Locale);
  पूर्णाङ्क __cdecl स_भेद(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size);
  शून्य *__cdecl स_नकल(शून्य *_Dst,अचर शून्य *_Src,माप_प्रकार _Size);
  शून्य *__cdecl स_रखो(शून्य *_Dst,पूर्णाङ्क _Val,माप_प्रकार _Size);

#ifndef	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,अचर शून्य *_Src,पूर्णाङ्क _Val,माप_प्रकार _Size);
  पूर्णाङ्क __cdecl memicmp(अचर शून्य *_Buf1,अचर शून्य *_Buf2,माप_प्रकार _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
