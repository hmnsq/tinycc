/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#ଅନ୍ତର୍ଭାଵ <_mingw.h>
#ଅନ୍ତର୍ଭାଵ <io.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  ସଂରଚନା _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP ଅକ୍ଷର *__cdecl _getcwd(ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _SizeInBytes);
  _CRTIMP ଅକ୍ଷର *__cdecl _getdcwd(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive,ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _SizeInBytes);
  ଅକ୍ଷର *__cdecl _getdcwd_nolock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive,ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _SizeInBytes);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _chdir(ଅଚଳ ଅକ୍ଷର *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _mkdir(ଅଚଳ ଅକ୍ଷର *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _rmdir(ଅଚଳ ଅକ୍ଷର *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _chdrive(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getdrive(ଶୂନ୍ୟ);
  _CRTIMP unsigned long __cdecl _getdrives(ଶୂନ୍ୟ);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,ସଂରଚନା _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  wchar_t *__cdecl _wgetdcwd_nolock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Drive,wchar_t *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wchdir(ଅଚଳ wchar_t *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wmkdir(ଅଚଳ wchar_t *_Path);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wrmdir(ଅଚଳ wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  ଅକ୍ଷର *__cdecl getcwd(ଅକ୍ଷର *_DstBuf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _SizeInBytes);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl chdir(ଅଚଳ ଅକ୍ଷର *_Path);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl mkdir(ଅଚଳ ଅକ୍ଷର *_Path);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl rmdir(ଅଚଳ ଅକ୍ଷର *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)
#endif
