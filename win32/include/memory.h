/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् INC_स्मृतिः
#परिभाषय INC_स्मृतिः

#अन्तर्भाव <_mingw.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CONST_RETURN
#परिभाषय _CONST_RETURN
#यदि_अन्तः

#परिभाषय _WConst_return _CONST_RETURN

#यदि_अपरिभाषितम् CRT_स्मृतिः_DEFINED
#परिभाषय CRT_स्मृतिः_DEFINED
  _CRTIMP शून्य *__cdecl _memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CONST_RETURN शून्य *__cdecl memchr(ध्रुव शून्य *_Buf ,पूर्णाङ्क _Val,आकार_t Max_गणनम्);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4);
  _CRTIMP पूर्णाङ्क __cdecl _memicmp_l(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4,_locale_t _Locale);
  पूर्णाङ्क __cdecl memcmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4);
  शून्य *__cdecl स्मृतिं_प्रतिलिख(शून्य *_Dst,ध्रुव शून्य *_Src,आकार_t आकार_4);
  शून्य *__cdecl स्मृतिं_पूरय(शून्य *_Dst,पूर्णाङ्क _Val,आकार_t आकार_4);

#यदि_अपरिभाषितम्	NO_OLDNAMES
  शून्य *__cdecl memccpy(शून्य *_Dst,ध्रुव शून्य *_Src,पूर्णाङ्क _Val,आकार_t आकार_4);
  पूर्णाङ्क __cdecl memicmp(ध्रुव शून्य *_Buf1,ध्रुव शून्य *_Buf2,आकार_t आकार_4);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
