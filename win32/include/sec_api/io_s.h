/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_IO_S
#وصف_ڪريو _INC_IO_S

#ضمن <io.h>

#إذا defined(MINGW_HAS_SECURE_API)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _access_s(ثابت حرف *_Filename,صحيح Access_گهڻائي);
  _CRTIMP errno_t __cdecl _chsize_s(صحيح _FileHandle,__int64 سائيز_4);
  _CRTIMP errno_t __cdecl _mktemp_s(حرف *_TemplateName,سائيز_t سائيز_4);
  _CRTIMP errno_t __cdecl _umask_s(صحيح New_گهڻائي,صحيح *Old_گهڻائي);

#جيڪڏهن_وصف_نه_ٿيل _WIO_S_DEFINED
#وصف_ڪريو _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_گهڻائي);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,سائيز_t سائيز_اندريون_لفظ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
#جيڪڏهن_پورو
