/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#ضمن <io.h>

#אם defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
خارجي "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(ثابت حرف *_Filename,صحيح _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(صحيح _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(حرف *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(صحيح _NewMode,صحيح *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
