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
বাহ্যিক "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  কাঠামো _diskfree_t {
    unsigned যোগ_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP অক্ষর *__cdecl _getcwd(অক্ষর *_DstBuf,পূর্ণসংখ্যা আকার_In_Bytes);
  _CRTIMP অক্ষর *__cdecl _getdcwd(পূর্ণসংখ্যা _Drive,অক্ষর *_DstBuf,পূর্ণসংখ্যা আকার_In_Bytes);
  অক্ষর *__cdecl _getdcwd_nolock(পূর্ণসংখ্যা _Drive,অক্ষর *_DstBuf,পূর্ণসংখ্যা আকার_In_Bytes);
  _CRTIMP পূর্ণসংখ্যা __cdecl _chdir(ধ্রুবক অক্ষর *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _mkdir(ধ্রুবক অক্ষর *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _rmdir(ধ্রুবক অক্ষর *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _chdrive(পূর্ণসংখ্যা _Drive);
  _CRTIMP পূর্ণসংখ্যা __cdecl _getdrive(শূন্য);
  _CRTIMP unsigned long __cdecl _getdrives(শূন্য);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,কাঠামো _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,পূর্ণসংখ্যা আকার_In_শব্দগুলি);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(পূর্ণসংখ্যা _Drive,wchar_t *_DstBuf,পূর্ণসংখ্যা আকার_In_শব্দগুলি);
  wchar_t *__cdecl _wgetdcwd_nolock(পূর্ণসংখ্যা _Drive,wchar_t *_DstBuf,পূর্ণসংখ্যা আকার_In_শব্দগুলি);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wchdir(ধ্রুবক wchar_t *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wmkdir(ধ্রুবক wchar_t *_Path);
  _CRTIMP পূর্ণসংখ্যা __cdecl _wrmdir(ধ্রুবক wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  অক্ষর *__cdecl getcwd(অক্ষর *_DstBuf,পূর্ণসংখ্যা আকার_In_Bytes);
  পূর্ণসংখ্যা __cdecl chdir(ধ্রুবক অক্ষর *_Path);
  পূর্ণসংখ্যা __cdecl mkdir(ধ্রুবক অক্ষর *_Path);
  পূর্ণসংখ্যা __cdecl rmdir(ধ্রুবক অক্ষর *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)
#endif
