/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#شامل <_mingw.h>
#شامل <io.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  ساختار _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP نویسه *__cdecl _getcwd(نویسه *_DstBuf,صحیح _SizeInBytes);
  _CRTIMP نویسه *__cdecl _getdcwd(صحیح _Drive,نویسه *_DstBuf,صحیح _SizeInBytes);
  نویسه *__cdecl _getdcwd_nolock(صحیح _Drive,نویسه *_DstBuf,صحیح _SizeInBytes);
  _CRTIMP صحیح __cdecl _chdir(ثابت نویسه *_Path);
  _CRTIMP صحیح __cdecl _mkdir(ثابت نویسه *_Path);
  _CRTIMP صحیح __cdecl _rmdir(ثابت نویسه *_Path);
  _CRTIMP صحیح __cdecl _chdrive(صحیح _Drive);
  _CRTIMP صحیح __cdecl _getdrive(تهی);
  _CRTIMP unsigned long __cdecl _getdrives(تهی);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,ساختار _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحیح Size_In_واژگان);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحیح _Drive,wchar_t *_DstBuf,صحیح Size_In_واژگان);
  wchar_t *__cdecl _wgetdcwd_nolock(صحیح _Drive,wchar_t *_DstBuf,صحیح Size_In_واژگان);
  _CRTIMP صحیح __cdecl _wchdir(ثابت wchar_t *_Path);
  _CRTIMP صحیح __cdecl _wmkdir(ثابت wchar_t *_Path);
  _CRTIMP صحیح __cdecl _wrmdir(ثابت wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  نویسه *__cdecl getcwd(نویسه *_DstBuf,صحیح _SizeInBytes);
  صحیح __cdecl chdir(ثابت نویسه *_Path);
  صحیح __cdecl mkdir(ثابت نویسه *_Path);
  صحیح __cdecl rmdir(ثابت نویسه *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)
#endif
