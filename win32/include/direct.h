/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <io.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  ಸಂರಚನಾ _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP ವರ್ಣ *__cdecl _getcwd(ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _SizeInBytes);
  _CRTIMP ವರ್ಣ *__cdecl _getdcwd(ಪೂರ್ಣಾಙ್ಕ _Drive,ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _SizeInBytes);
  ವರ್ಣ *__cdecl _getdcwd_nolock(ಪೂರ್ಣಾಙ್ಕ _Drive,ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _SizeInBytes);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _chdir(ಧ್ರುವ ವರ್ಣ *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _mkdir(ಧ್ರುವ ವರ್ಣ *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _rmdir(ಧ್ರುವ ವರ್ಣ *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _chdrive(ಪೂರ್ಣಾಙ್ಕ _Drive);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getdrive(ಶೂನ್ಯ);
  _CRTIMP unsigned long __cdecl _getdrives(ಶೂನ್ಯ);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,ಸಂರಚನಾ _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ಪೂರ್ಣಾಙ್ಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು);
  wchar_t *__cdecl _wgetdcwd_nolock(ಪೂರ್ಣಾಙ್ಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wchdir(ಧ್ರುವ wchar_t *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wmkdir(ಧ್ರುವ wchar_t *_Path);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wrmdir(ಧ್ರುವ wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  ವರ್ಣ *__cdecl getcwd(ವರ್ಣ *_DstBuf,ಪೂರ್ಣಾಙ್ಕ _SizeInBytes);
  ಪೂರ್ಣಾಙ್ಕ __cdecl chdir(ಧ್ರುವ ವರ್ಣ *_Path);
  ಪೂರ್ಣಾಙ್ಕ __cdecl mkdir(ಧ್ರುವ ವರ್ಣ *_Path);
  ಪೂರ್ಣಾಙ್ಕ __cdecl rmdir(ಧ್ರುವ ವರ್ಣ *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)
#endif
