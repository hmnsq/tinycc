/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_IO_S
#تعریف_کن _INC_IO_S

#ضمن <io.h>

#إذا defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  _CRTIMP errno_t __cdecl _access_s(ثابت حرف *_Filename,صحيح Access_نما);
  _CRTIMP errno_t __cdecl _chsize_s(صحيح _FileHandle,__int64 اندازه_4);
  _CRTIMP errno_t __cdecl _mktemp_s(حرف *_TemplateName,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _umask_s(صحيح New_نما,صحيح *Old_نما);

#اگر_تعریف_نشده _WIO_S_DEFINED
#تعریف_کن _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_نما);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,اندازه_t اندازه_درون_واژگان);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
#پایان_اگر
