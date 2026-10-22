/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#அந்தர்பாவ <io.h>

#எனில் defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
வெளி "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(மாறிலி எழுத்து *_Filename,முழு _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(முழு _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(எழுத்து *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(முழு _NewMode,முழு *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(மாறிலி wchar_t *_Filename,முழு _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_சொற்கள்);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
