/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_DOS
#تعریف_کرو _INC_DOS

#ضمن <_mingw.h>
#ضمن <io.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _DISKFREE_T_DEFINED
#تعریف_کرو _DISKFREE_T_DEFINED

  بنية _diskfree_t {
    بنانشانی کل_clusters;
    بنانشانی avail_clusters;
    بنانشانی sectors_فی_cluster;
    بنانشانی بائٹاں_فی_sector;
  };
#جے_انت

#تعریف_کرو A_عام 0x00
#تعریف_کرو _A_RDONLY 0x01
#تعریف_کرو _A_HIDDEN 0x02
#تعریف_کرو _A_SYSTEM 0x04
#تعریف_کرو _A_SUBDIR 0x10
#تعریف_کرو _A_ARCH 0x20

#جے_بنا_تعریف _GETDISKFREE_DEFINED
#تعریف_کرو _GETDISKFREE_DEFINED
  _CRTIMP بنانشانی __cdecl _getdiskfree(بنانشانی _Drive,بنية _diskfree_t *_DiskFree);
#جے_انت

#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __cdecl _disable(فراغ);
  فراغ __cdecl _enable(فراغ);
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
#تعریف_کرو diskfree_t _diskfree_t
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)
#جے_انت
