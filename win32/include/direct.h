/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#include <_mingw.h>
#include <io.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  sa_nracanaa _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP var_na *__cdecl _getcwd(var_na *_DstBuf,ကိန်းပြည့် _SizeInBytes);
  _CRTIMP var_na *__cdecl _getdcwd(ကိန်းပြည့် _Drive,var_na *_DstBuf,ကိန်းပြည့် _SizeInBytes);
  var_na *__cdecl _getdcwd_nolock(ကိန်းပြည့် _Drive,var_na *_DstBuf,ကိန်းပြည့် _SizeInBytes);
  _CRTIMP ကိန်းပြည့် __cdecl _chdir(const var_na *_Path);
  _CRTIMP ကိန်းပြည့် __cdecl _mkdir(const var_na *_Path);
  _CRTIMP ကိန်းပြည့် __cdecl _rmdir(const var_na *_Path);
  _CRTIMP ကိန်းပြည့် __cdecl _chdrive(ကိန်းပြည့် _Drive);
  _CRTIMP ကိန်းပြည့် __cdecl _getdrive(void);
  _CRTIMP unsigned long __cdecl _getdrives(void);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,sa_nracanaa _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ကိန်းပြည့် _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ကိန်းပြည့် _Drive,wchar_t *_DstBuf,ကိန်းပြည့် _SizeInWords);
  wchar_t *__cdecl _wgetdcwd_nolock(ကိန်းပြည့် _Drive,wchar_t *_DstBuf,ကိန်းပြည့် _SizeInWords);
  _CRTIMP ကိန်းပြည့် __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP ကိန်းပြည့် __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP ကိန်းပြည့် __cdecl _wrmdir(const wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  var_na *__cdecl getcwd(var_na *_DstBuf,ကိန်းပြည့် _SizeInBytes);
  ကိန်းပြည့် __cdecl chdir(const var_na *_Path);
  ကိန်းပြည့် __cdecl mkdir(const var_na *_Path);
  ကိန်းပြည့် __cdecl rmdir(const var_na *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
