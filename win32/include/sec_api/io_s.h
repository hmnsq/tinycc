/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#અન્તર્ભાવ <io.h>

#જો defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(અચલ અક્ષર *_Filename,પૂર્ણાંક _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(પૂર્ણાંક _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(અક્ષર *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(પૂર્ણાંક _NewMode,પૂર્ણાંક *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(અચલ wchar_t *_Filename,પૂર્ણાંક _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_શબ્દો);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
