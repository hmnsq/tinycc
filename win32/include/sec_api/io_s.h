/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#ଅନ୍ତର୍ଭାଵ <io.h>

#ଯଦି defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(ଅକ୍ଷର *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _NewMode,ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
