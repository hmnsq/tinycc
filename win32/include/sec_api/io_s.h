/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#ಅನ್ತರ್ಭಾವ <io.h>

#ಯದಿ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(ಪೂರ್ಣಾಙ್ಕ _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(ವರ್ಣ *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(ಪೂರ್ಣಾಙ್ಕ _NewMode,ಪೂರ್ಣಾಙ್ಕ *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_ಪದಗಳು);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
