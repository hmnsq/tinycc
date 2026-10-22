/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  संरचना _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP वर्ण *__cdecl _getcwd(वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  _CRTIMP वर्ण *__cdecl _getdcwd(पूर्णाङ्क _Drive,वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  वर्ण *__cdecl _getdcwd_nolock(पूर्णाङ्क _Drive,वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  _CRTIMP पूर्णाङ्क __cdecl _chdir(ध्रुव वर्ण *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _mkdir(ध्रुव वर्ण *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _rmdir(ध्रुव वर्ण *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _chdrive(पूर्णाङ्क _Drive);
  _CRTIMP पूर्णाङ्क __cdecl _getdrive(शून्य);
  _CRTIMP unsigned long __cdecl _getdrives(शून्य);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,संरचना _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,पूर्णाङ्क Size_In_शब्द);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क Size_In_शब्द);
  wchar_t *__cdecl _wgetdcwd_nolock(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क Size_In_शब्द);
  _CRTIMP पूर्णाङ्क __cdecl _wchdir(ध्रुव wchar_t *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wmkdir(ध्रुव wchar_t *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wrmdir(ध्रुव wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  वर्ण *__cdecl getcwd(वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  पूर्णाङ्क __cdecl chdir(ध्रुव वर्ण *_Path);
  पूर्णाङ्क __cdecl mkdir(ध्रुव वर्ण *_Path);
  पूर्णाङ्क __cdecl rmdir(ध्रुव वर्ण *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
