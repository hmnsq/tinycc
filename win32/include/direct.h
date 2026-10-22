/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#ضمن <_mingw.h>
#ضمن <io.h>

#pragma pack(تور,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  بنية _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP حرف *__cdecl _getcwd(حرف *_DstBuf,صحيح _SizeInBytes);
  _CRTIMP حرف *__cdecl _getdcwd(صحيح _Drive,حرف *_DstBuf,صحيح _SizeInBytes);
  حرف *__cdecl _getdcwd_nolock(صحيح _Drive,حرف *_DstBuf,صحيح _SizeInBytes);
  _CRTIMP صحيح __cdecl _chdir(ثابت حرف *_Path);
  _CRTIMP صحيح __cdecl _mkdir(ثابت حرف *_Path);
  _CRTIMP صحيح __cdecl _rmdir(ثابت حرف *_Path);
  _CRTIMP صحيح __cdecl _chdrive(صحيح _Drive);
  _CRTIMP صحيح __cdecl _getdrive(فراغ);
  _CRTIMP unsigned long __cdecl _getdrives(فراغ);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,بنية _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح Size_In_كلموم);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح Size_In_كلموم);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح Size_In_كلموم);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *_Path);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *_Path);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  حرف *__cdecl getcwd(حرف *_DstBuf,صحيح _SizeInBytes);
  صحيح __cdecl chdir(ثابت حرف *_Path);
  صحيح __cdecl mkdir(ثابت حرف *_Path);
  صحيح __cdecl rmdir(ثابت حرف *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(چرو)
#endif
