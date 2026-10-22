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
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,स्थिरांक शून्य *_Src,पूर्णांक _Val,माप_प्रकार Max_मोजणी);
  _CONST_RETURN शून्य *__cdecl स_प्रथम(स्थिरांक शून्य *_Buf ,पूर्णांक _Val,माप_प्रकार Max_मोजणी);
  _CRTIMP पूर्णांक __cdecl _memicmp(स्थिरांक शून्य *_Buf1,स्थिरांक शून्य *_Buf2,माप_प्रकार _Size);
  _CRTIMP पूर्णांक __cdecl _memicmp_l(स्थिरांक शून्य *_Buf1,स्थिरांक शून्य *_Buf2,माप_प्रकार _Size,_locale_t _Locale);
  पूर्णांक __cdecl स_भेद(स्थिरांक शून्य *_Buf1,स्थिरांक शून्य *_Buf2,माप_प्रकार _Size);
  शून्य *__cdecl स_नकल(शून्य *_Dst,स्थिरांक शून्य *_Src,माप_प्रकार _Size);
  शून्य *__cdecl स_रखो(शून्य *_Dst,पूर्णांक _Val,माप_प्रकार _Size);

#ifndef	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,स्थिरांक शून्य *_Src,पूर्णांक _Val,माप_प्रकार _Size);
  पूर्णांक __cdecl memicmp(स्थिरांक शून्य *_Buf1,स्थिरांक शून्य *_Buf2,माप_प्रकार _Size);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
