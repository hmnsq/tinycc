/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#अगर_अघोषित _TIMEB_H_S
#घोषणा _TIMEB_H_S

#समावेश <sys/timeb.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित _USE_32BIT_TIME_T
#घोषणा _ftime_s _ftime32_s
#अन्यथा
#घोषणा _ftime_s _ftime64_s
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _ftime32_s(काष्ठा __timeb32 *_Time);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(काष्ठा __timeb64 *_Time);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
