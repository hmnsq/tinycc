/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_IO_S
#define _INC_IO_S

#അന്തര്ഭാവ <io.h>

#എങ്കിൽ defined(MINGW_HAS_SECURE_API)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP errno_t __cdecl _access_s(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(പൂർണ്ണസംഖ്യ _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(അക്ഷരം *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(പൂർണ്ണസംഖ്യ _NewMode,പൂർണ്ണസംഖ്യ *_OldMode);

#ifndef _WIO_S_DEFINED
#define _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t Size_In_വാക്കുകൾ);
#endif

#ifdef __cplusplus
}
#endif

#endif
#endif
