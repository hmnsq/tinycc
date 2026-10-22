/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_IO_S
#تعریف_کړه _INC_IO_S

#ضمن <io.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  _CRTIMP errno_t __cdecl _access_s(ثابت حرف *_Filename,صحيح Access_ډېرپېښ);
  _CRTIMP errno_t __cdecl _chsize_s(صحيح _FileHandle,__int64 اندازه_4);
  _CRTIMP errno_t __cdecl _mktemp_s(حرف *_TemplateName,اندازه_t اندازه_4);
  _CRTIMP errno_t __cdecl _umask_s(صحيح New_ډېرپېښ,صحيح *Old_ډېرپېښ);

#که_نه_تعریف_شوی _WIO_S_DEFINED
#تعریف_کړه _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحيح Access_ډېرپېښ);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,اندازه_t اندازه_دننه_ټکي);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
#د_که_پای
