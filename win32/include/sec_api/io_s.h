/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_IO_S
#परिभाषय _INC_IO_S

#अन्तर्भाव <io.h>

#यदि defined(MINGW_HAS_SECURE_API)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _access_s(ध्रुव वर्ण *_Filename,पूर्णाङ्क Access_बहुलकम्);
  _CRTIMP errno_t __cdecl _chsize_s(पूर्णाङ्क _FileHandle,__int64 आकार_4);
  _CRTIMP errno_t __cdecl _mktemp_s(वर्ण *_TemplateName,आकार_t आकार_4);
  _CRTIMP errno_t __cdecl _umask_s(पूर्णाङ्क New_बहुलकम्,पूर्णाङ्क *Old_बहुलकम्);

#यदि_अपरिभाषितम् _WIO_S_DEFINED
#परिभाषय _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ध्रुव wchar_t *_Filename,पूर्णाङ्क Access_बहुलकम्);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,आकार_t आकार_अन्तर्_शब्दाः);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
#यदि_अन्तः
