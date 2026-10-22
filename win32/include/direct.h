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

  _CRTIMP char *__cdecl _getcwd(char *_DstBuf,정수 _SizeInBytes);
  _CRTIMP char *__cdecl _getdcwd(정수 _Drive,char *_DstBuf,정수 _SizeInBytes);
  char *__cdecl _getdcwd_nolock(정수 _Drive,char *_DstBuf,정수 _SizeInBytes);
  _CRTIMP 정수 __cdecl _chdir(const char *_Path);
  _CRTIMP 정수 __cdecl _mkdir(const char *_Path);
  _CRTIMP 정수 __cdecl _rmdir(const char *_Path);
  _CRTIMP 정수 __cdecl _chdrive(정수 _Drive);
  _CRTIMP 정수 __cdecl _getdrive(void);
  _CRTIMP unsigned long __cdecl _getdrives(void);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,struct _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,정수 _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(정수 _Drive,wchar_t *_DstBuf,정수 _SizeInWords);
  wchar_t *__cdecl _wgetdcwd_nolock(정수 _Drive,wchar_t *_DstBuf,정수 _SizeInWords);
  _CRTIMP 정수 __cdecl _wchdir(const wchar_t *_Path);
  _CRTIMP 정수 __cdecl _wmkdir(const wchar_t *_Path);
  _CRTIMP 정수 __cdecl _wrmdir(const wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  char *__cdecl getcwd(char *_DstBuf,정수 _SizeInBytes);
  정수 __cdecl chdir(const char *_Path);
  정수 __cdecl mkdir(const char *_Path);
  정수 __cdecl rmdir(const char *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
