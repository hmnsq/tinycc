/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_IO_S
#تعریف_کرو _INC_IO_S

#ضمن <io.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  _CRTIMP errno_t __cdecl _access_s(ثابت حرف *_Filename,صحيح Access_منوال);
  _CRTIMP errno_t __cdecl _chsize_s(صحيح _FileHandle,__int64 ناپ_4);
  _CRTIMP errno_t __cdecl _mktemp_s(حرف *_TemplateName,ناپ_t ناپ_4);
  _CRTIMP errno_t __cdecl _umask_s(صحيح New_منوال,صحيح *Old_منوال);

#جے_بنا_تعریف _WIO_S_DEFINED
#تعریف_کرو _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_منوال);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,ناپ_t ناپ_وچ_الفاظ);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
#جے_انت
