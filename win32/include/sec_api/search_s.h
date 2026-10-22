/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef INC_अन्वेषणम्_S
#define INC_अन्वेषणम्_S

#अन्तर्भाव <search.h>

#जइ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP शून्य *__cdecl _lfind_s(ध्रुव शून्य *कुञ्चिका_2,ध्रुव शून्य *_Base,unsigned पूर्णाङ्क *अङ्कः_Of_Elements,size_t _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(शून्य *,ध्रुव शून्य *,ध्रुव शून्य *),शून्य *_Context);
  _CRTIMP शून्य *__cdecl _lsearch_s(ध्रुव शून्य *कुञ्चिका_2,शून्य *_Base,unsigned पूर्णाङ्क *अङ्कः_Of_Elements,size_t _SizeOfElements,पूर्णाङ्क (__cdecl *_PtFuncCompare)(शून्य *,ध्रुव शून्य *,ध्रुव शून्य *),शून्य *_Context);

#ifdef __cplusplus
}
#endif

#endif
#endif
