/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DOS
#define _INC_DOS

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

#define _A_NORMAL 0x00
#define _A_RDONLY 0x01
#define _A_HIDDEN 0x02
#define _A_SYSTEM 0x04
#define _A_SUBDIR 0x10
#define _A_ARCH 0x20

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,கட்டமைப்பு _diskfree_t *_DiskFree);
#endif

#எனில் (defined(_X86_) && !defined(__x86_64))
  வெறுமை __cdecl _disable(வெறுமை);
  வெறுமை __cdecl _enable(வெறுமை);
#endif

#ifndef	NO_OLDNAMES
#define diskfree_t _diskfree_t
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)
#endif
