/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_UTIME
#घोषणा _INC_UTIME

#अगर_अघोषित _WIN32
#त्रुटि Only Win32 target is supported!
#पूर्ण_अगर

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CRTIMP
#घोषणा _CRTIMP __declspec(dllimport)
#पूर्ण_अगर

#अगर_अघोषित _WCHAR_T_DEFINED
  प्रकार अचिन्हित लघु ब_अक्षर_प्रकार;
#घोषणा _WCHAR_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित __TINYC__ /* gr */
#अगर_घोषित _USE_32BIT_TIME_T
#अगर_घोषित _WIN64
#अघोषित _USE_32BIT_TIME_T
#पूर्ण_अगर
#अन्यथा
#अगर _INTEGRAL_MAX_BITS < 64
#घोषणा _USE_32BIT_TIME_T
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME32_T_DEFINED
#घोषणा _TIME32_T_DEFINED
  प्रकार दीर्घ __time32_t;
#पूर्ण_अगर

#अगर_अघोषित _TIME64_T_DEFINED
#घोषणा _TIME64_T_DEFINED
#अगर _INTEGRAL_MAX_BITS >= 64
  प्रकार __int64 __time64_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME_T_DEFINED
#घोषणा _TIME_T_DEFINED
#अगर_घोषित _USE_32BIT_TIME_T
  प्रकार __time32_t समय_प्रकार;
#अन्यथा
  प्रकार __time64_t समय_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _UTIMBUF_DEFINED
#घोषणा _UTIMBUF_DEFINED

  काष्ठा _utimbuf {
    समय_प्रकार actime;
    समय_प्रकार modtime;
  };

  काष्ठा __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#अगर _INTEGRAL_MAX_BITS >= 64
  काष्ठा __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
  काष्ठा utimbuf {
    समय_प्रकार actime;
    समय_प्रकार modtime;
  };

  काष्ठा utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#पूर्ण_अगर
#पूर्ण_अगर

  _CRTIMP पूर्णांक __cdecl _utime32(स्थिर अक्षर *_Filename,काष्ठा __utimbuf32 *_Time);
  _CRTIMP पूर्णांक __cdecl _futime32(पूर्णांक _FileDes,काष्ठा __utimbuf32 *_Time);
  _CRTIMP पूर्णांक __cdecl _wutime32(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा __utimbuf32 *_Time);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _utime64(स्थिर अक्षर *_Filename,काष्ठा __utimbuf64 *_Time);
  _CRTIMP पूर्णांक __cdecl _futime64(पूर्णांक _FileDes,काष्ठा __utimbuf64 *_Time);
  _CRTIMP पूर्णांक __cdecl _wutime64(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा __utimbuf64 *_Time);
#पूर्ण_अगर

#अगर_अघोषित RC_INVOKED
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE पूर्णांक __cdecl _utime(स्थिर अक्षर *_Filename,काष्ठा _utimbuf *_Utimbuf) {
  वापस _utime32(_Filename,(काष्ठा __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _futime(पूर्णांक _Desc,काष्ठा _utimbuf *_Utimbuf) {
  वापस _futime32(_Desc,(काष्ठा __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _wutime(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _utimbuf *_Utimbuf) {
  वापस _wutime32(_Filename,(काष्ठा __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णांक __cdecl _utime(स्थिर अक्षर *_Filename,काष्ठा _utimbuf *_Utimbuf) {
  वापस _utime64(_Filename,(काष्ठा __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _futime(पूर्णांक _Desc,काष्ठा _utimbuf *_Utimbuf) {
  वापस _futime64(_Desc,(काष्ठा __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE पूर्णांक __cdecl _wutime(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _utimbuf *_Utimbuf) {
  वापस _wutime64(_Filename,(काष्ठा __utimbuf64 *)_Utimbuf);
}
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE पूर्णांक __cdecl utime(स्थिर अक्षर *_Filename,काष्ठा utimbuf *_Utimbuf) {
  वापस _utime32(_Filename,(काष्ठा __utimbuf32 *)_Utimbuf);
}
#अन्यथा
__CRT_INLINE पूर्णांक __cdecl utime(स्थिर अक्षर *_Filename,काष्ठा utimbuf *_Utimbuf) {
  वापस _utime64(_Filename,(काष्ठा __utimbuf64 *)_Utimbuf);
}
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
