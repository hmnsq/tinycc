/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DOS
#define _INC_DOS

#અન્તર્ભાવ <_mingw.h>
#અન્તર્ભાવ <io.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED

  સંરચના _diskfree_t {
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
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,સંરચના _diskfree_t *_DiskFree);
#endif

#જો (defined(_X86_) && !defined(__x86_64))
  શૂન્ય __cdecl _disable(શૂન્ય);
  શૂન્ય __cdecl _enable(શૂન્ય);
#endif

#ifndef	NO_OLDNAMES
#define diskfree_t _diskfree_t
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)
#endif
