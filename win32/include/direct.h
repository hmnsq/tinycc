/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#অন্তর্ভাব <_mingw.h>
#অন্তর্ভাব <io.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  সংরচনা _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP বর্ণ *__cdecl _getcwd(বর্ণ *_DstBuf,পূর্ণাঙ্ক _SizeInBytes);
  _CRTIMP বর্ণ *__cdecl _getdcwd(পূর্ণাঙ্ক _Drive,বর্ণ *_DstBuf,পূর্ণাঙ্ক _SizeInBytes);
  বর্ণ *__cdecl _getdcwd_nolock(পূর্ণাঙ্ক _Drive,বর্ণ *_DstBuf,পূর্ণাঙ্ক _SizeInBytes);
  _CRTIMP পূর্ণাঙ্ক __cdecl _chdir(ধ্রুব বর্ণ *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _mkdir(ধ্রুব বর্ণ *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _rmdir(ধ্রুব বর্ণ *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _chdrive(পূর্ণাঙ্ক _Drive);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getdrive(শূন্য);
  _CRTIMP unsigned long __cdecl _getdrives(শূন্য);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,সংরচনা _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,পূর্ণাঙ্ক Size_In_শব্দগুলি);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(পূর্ণাঙ্ক _Drive,wchar_t *_DstBuf,পূর্ণাঙ্ক Size_In_শব্দগুলি);
  wchar_t *__cdecl _wgetdcwd_nolock(পূর্ণাঙ্ক _Drive,wchar_t *_DstBuf,পূর্ণাঙ্ক Size_In_শব্দগুলি);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wchdir(ধ্রুব wchar_t *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wmkdir(ধ্রুব wchar_t *_Path);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wrmdir(ধ্রুব wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  বর্ণ *__cdecl getcwd(বর্ণ *_DstBuf,পূর্ণাঙ্ক _SizeInBytes);
  পূর্ণাঙ্ক __cdecl chdir(ধ্রুব বর্ণ *_Path);
  পূর্ণাঙ্ক __cdecl mkdir(ধ্রুব বর্ণ *_Path);
  পূর্ণাঙ্ক __cdecl rmdir(ধ্রুব বর্ণ *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)
#endif
