/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#அந்தர்பாவ <_mingw.h>
#அந்தர்பாவ <io.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  கட்டமைப்பு _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP எழுத்து *__cdecl _getcwd(எழுத்து *_DstBuf,முழு _SizeInBytes);
  _CRTIMP எழுத்து *__cdecl _getdcwd(முழு _Drive,எழுத்து *_DstBuf,முழு _SizeInBytes);
  எழுத்து *__cdecl _getdcwd_nolock(முழு _Drive,எழுத்து *_DstBuf,முழு _SizeInBytes);
  _CRTIMP முழு __cdecl _chdir(மாறிலி எழுத்து *_Path);
  _CRTIMP முழு __cdecl _mkdir(மாறிலி எழுத்து *_Path);
  _CRTIMP முழு __cdecl _rmdir(மாறிலி எழுத்து *_Path);
  _CRTIMP முழு __cdecl _chdrive(முழு _Drive);
  _CRTIMP முழு __cdecl _getdrive(வெறுமை);
  _CRTIMP unsigned long __cdecl _getdrives(வெறுமை);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,கட்டமைப்பு _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,முழு Size_In_சொற்கள்);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(முழு _Drive,wchar_t *_DstBuf,முழு Size_In_சொற்கள்);
  wchar_t *__cdecl _wgetdcwd_nolock(முழு _Drive,wchar_t *_DstBuf,முழு Size_In_சொற்கள்);
  _CRTIMP முழு __cdecl _wchdir(மாறிலி wchar_t *_Path);
  _CRTIMP முழு __cdecl _wmkdir(மாறிலி wchar_t *_Path);
  _CRTIMP முழு __cdecl _wrmdir(மாறிலி wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  எழுத்து *__cdecl getcwd(எழுத்து *_DstBuf,முழு _SizeInBytes);
  முழு __cdecl chdir(மாறிலி எழுத்து *_Path);
  முழு __cdecl mkdir(மாறிலி எழுத்து *_Path);
  முழு __cdecl rmdir(மாறிலி எழுத்து *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)
#endif
