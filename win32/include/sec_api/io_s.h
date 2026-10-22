/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#अन्तर्भाव <io.h>

#यदि defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(ध्रुव वर्ण *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(पूर्णाङ्क _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(वर्ण *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(पूर्णाङ्क _NewMode,पूर्णाङ्क *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ध्रुव wchar_t *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_शब्दगण);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
