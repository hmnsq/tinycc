/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DOS
#define _INC_DOS

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

#define _A_NORMAL 0x00
#define _A_RDONLY 0x01
#define _A_HIDDEN 0x02
#define _A_SYSTEM 0x04
#define _A_SUBDIR 0x10
#define _A_ARCH 0x20

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,ಸಂರಚನಾ _diskfree_t *_DiskFree);
#endif

#ಯದಿ (defined(_X86_) && !defined(__x86_64))
  ಶೂನ್ಯ __cdecl _disable(ಶೂನ್ಯ);
  ಶೂನ್ಯ __cdecl _enable(ಶೂನ್ಯ);
#endif

#ifndef	NO_OLDNAMES
#define diskfree_t _diskfree_t
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)
#endif
