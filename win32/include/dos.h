/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_DOS
#وصف_ڪريو _INC_DOS

#ضمن <_mingw.h>
#ضمن <io.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _DISKFREE_T_DEFINED
#وصف_ڪريو _DISKFREE_T_DEFINED

  بنية _diskfree_t {
    بنانشان ڪل_clusters;
    بنانشان avail_clusters;
    بنانشان sectors_في_cluster;
    بنانشان بائيٽون_في_sector;
  };
#جيڪڏهن_پورو

#وصف_ڪريو A_عام 0x00
#وصف_ڪريو _A_RDONLY 0x01
#وصف_ڪريو _A_HIDDEN 0x02
#وصف_ڪريو _A_SYSTEM 0x04
#وصف_ڪريو _A_SUBDIR 0x10
#وصف_ڪريو _A_ARCH 0x20

#جيڪڏهن_وصف_نه_ٿيل _GETDISKFREE_DEFINED
#وصف_ڪريو _GETDISKFREE_DEFINED
  _CRTIMP بنانشان __cdecl _getdiskfree(بنانشان _Drive,بنية _diskfree_t *_DiskFree);
#جيڪڏهن_پورو

#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __cdecl _disable(فراغ);
  فراغ __cdecl _enable(فراغ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#وصف_ڪريو diskfree_t _diskfree_t
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
