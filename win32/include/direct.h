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
  struct _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP char *__cdecl _getcwd(char *_DstBuf,整数 _SizeInBytes);
  _CRTIMP char *__cdecl _getdcwd(整数 _Drive,char *_DstBuf,整数 _SizeInBytes);
  char *__cdecl _getdcwd_nolock(整数 _Drive,char *_DstBuf,整数 _SizeInBytes);
  _CRTIMP 整数 __cdecl _chdir(const char *_Path);
  _CRTIMP 整数 __cdecl _mkdir(const char *_Path);
  _CRTIMP 整数 __cdecl _rmdir(const char *_Path);
  _CRTIMP 整数 __cdecl _chdrive(整数 _Drive);
  _CRTIMP 整数 __cdecl _getdrive(void);
  _CRTIMP unsigned long __cdecl _getdrives(void);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,struct _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,整数 _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(整数 _Drive,wchar_t *_DstBuf,整数 _SizeInWords);
  wchar_t *__cdecl _wgetdcwd_nolock(整数 _Drive,wchar_t *_DstBuf,整数 _SizeInWords);
  _CRTIMP 整数 __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP 整数 __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP 整数 __cdecl _wrmdir(const wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  char *__cdecl getcwd(char *_DstBuf,整数 _SizeInBytes);
  整数 __cdecl chdir(const char *_Path);
  整数 __cdecl mkdir(const char *_Path);
  整数 __cdecl rmdir(const char *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
