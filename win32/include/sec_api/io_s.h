/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_IO_S
#تعریف_کرو _INC_IO_S

#شامل <io.h>

#اگر defined(MINGW_HAS_SECURE_API)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP errno_t __cdecl _access_s(ثابت حرف *_Filename,صحیح Access_منوال);
  _CRTIMP errno_t __cdecl _chsize_s(صحیح _FileHandle,__int64 سائز_4);
  _CRTIMP errno_t __cdecl _mktemp_s(حرف *_TemplateName,سائز_t سائز_4);
  _CRTIMP errno_t __cdecl _umask_s(صحیح New_منوال,صحیح *Old_منوال);

#اگر_غیر_تعریف_شدہ _WIO_S_DEFINED
#تعریف_کرو _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ثابت wchar_t *_Filename,صحیح Access_منوال);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,سائز_t سائز_اندر_الفاظ);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
#اگر_ختم
