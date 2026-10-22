/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#অন্তর্ভাব <io.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(ধ্রুবক অক্ষর *_Filename,পূর্ণসংখ্যা _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(পূর্ণসংখ্যা _FileHandle,__int64 আকার_5);
  _CRTIMP errno_t __cdecl _mktemp_s(অক্ষর *_TemplateName,আকার_t আকার_5);
  _CRTIMP errno_t __cdecl _umask_s(পূর্ণসংখ্যা _NewMode,পূর্ণসংখ্যা *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ধ্রুবক wchar_t *_Filename,পূর্ণসংখ্যা _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,আকার_t আকার_In_শব্দগুলি);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
