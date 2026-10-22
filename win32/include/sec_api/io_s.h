/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_IO_S
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_IO_S

#ਅਨ੍ਤਰ੍ਭਾਵ <io.h>

#ਜੇ defined(MINGW_HAS_SECURE_API)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _access_s(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  _CRTIMP errno_t __cdecl _chsize_s(ਪੂਰਨ _FileHandle,__int64 ਮਾਪ_4);
  _CRTIMP errno_t __cdecl _mktemp_s(ਅੱਖਰ *_TemplateName,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP errno_t __cdecl _umask_s(ਪੂਰਨ New_ਬਹੁਲਕ,ਪੂਰਨ *Old_ਬਹੁਲਕ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIO_S_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
