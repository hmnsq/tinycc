/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#അന്തര്ഭാവ <_mingw.h>
#അന്തര്ഭാവ <io.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  ഘടന _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP അക്ഷരം *__cdecl _getcwd(അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _SizeInBytes);
  _CRTIMP അക്ഷരം *__cdecl _getdcwd(പൂർണ്ണസംഖ്യ _Drive,അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _SizeInBytes);
  അക്ഷരം *__cdecl _getdcwd_nolock(പൂർണ്ണസംഖ്യ _Drive,അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _SizeInBytes);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _chdir(സ്ഥിരം അക്ഷരം *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _mkdir(സ്ഥിരം അക്ഷരം *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _rmdir(സ്ഥിരം അക്ഷരം *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _chdrive(പൂർണ്ണസംഖ്യ _Drive);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getdrive(ശൂന്യം);
  _CRTIMP unsigned long __cdecl _getdrives(ശൂന്യം);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,ഘടന _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(പൂർണ്ണസംഖ്യ _Drive,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ);
  wchar_t *__cdecl _wgetdcwd_nolock(പൂർണ്ണസംഖ്യ _Drive,wchar_t *_DstBuf,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wchdir(സ്ഥിരം wchar_t *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wmkdir(സ്ഥിരം wchar_t *_Path);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wrmdir(സ്ഥിരം wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  അക്ഷരം *__cdecl getcwd(അക്ഷരം *_DstBuf,പൂർണ്ണസംഖ്യ _SizeInBytes);
  പൂർണ്ണസംഖ്യ __cdecl chdir(സ്ഥിരം അക്ഷരം *_Path);
  പൂർണ്ണസംഖ്യ __cdecl mkdir(സ്ഥിരം അക്ഷരം *_Path);
  പൂർണ്ണസംഖ്യ __cdecl rmdir(സ്ഥിരം അക്ഷരം *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)
#endif
