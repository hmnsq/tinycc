/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _TIME_H__S
#परिभाषय _TIME_H__S

#अन्तर्भाव <time.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _ctime32_s(वर्ण *_Buf,आकार_t आकार_अन्तर्_अष्टकानि,ध्रुव __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(संरचना tm *_Tm,ध्रुव __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(संरचना tm *_Tm,ध्रुव __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(वर्ण *_Buf,आकार_t आकार_अन्तर्_अष्टकानि);
  _CRTIMP errno_t __cdecl _strtime_s(वर्ण *_Buf ,आकार_t आकार_अन्तर्_अष्टकानि);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(वर्ण *_Buf,आकार_t आकार_अन्तर्_अष्टकानि,ध्रुव __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(संरचना tm *_Tm,ध्रुव __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(संरचना tm *_Tm,ध्रुव __time64_t *_Time);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WTIME_S_DEFINED
#परिभाषय _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव संरचना tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव __time64_t *_Time);
#यदि_अन्तः

#यदि !defined (RC_INVOKED) && !defined (_INC_WTIME_S_INL)
#परिभाषय _INC_WTIME_S_INL
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव time_t *_Time) { प्रत्यागम _wctime32_s(बफर_2,आकार_अन्तर्_शब्दाः,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *बफर_2,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव time_t *_Time) { प्रत्यागम _wctime64_s(बफर_2,आकार_अन्तर्_शब्दाः,_Time); }
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् RC_INVOKED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(संरचना tm *_Tm,ध्रुव time_t *_Time) { प्रत्यागम _localtime32_s(_Tm,_Time); }
#अन्यथा
__CRT_INLINE errno_t __cdecl localtime_s(संरचना tm *_Tm,ध्रुव time_t *_Time) { प्रत्यागम _localtime64_s(_Tm,_Time); }
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
