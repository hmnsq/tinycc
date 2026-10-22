/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#অন্তর্ভাৱ <io.h>

#যদি defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
বাহ্য "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(ধ্রুৱ ৱর্ণ *_Filename,পূর্ণাঙ্ক _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(পূর্ণাঙ্ক _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(ৱর্ণ *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(পূর্ণাঙ্ক _NewMode,পূর্ণাঙ্ক *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ধ্রুৱ wchar_t *_Filename,পূর্ণাঙ্ক _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_শব্দগুলি);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
