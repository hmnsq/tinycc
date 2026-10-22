/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_DOS
#تعریف_کړه _INC_DOS

#ضمن <_mingw.h>
#ضمن <io.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _DISKFREE_T_DEFINED
#تعریف_کړه _DISKFREE_T_DEFINED

  بنية _diskfree_t {
    بینښه ټول_clusters;
    بینښه avail_clusters;
    بینښه sectors_فی_cluster;
    بینښه بایټونه_فی_sector;
  };
#د_که_پای

#تعریف_کړه A_نورمال 0x00
#تعریف_کړه _A_RDONLY 0x01
#تعریف_کړه _A_HIDDEN 0x02
#تعریف_کړه _A_SYSTEM 0x04
#تعریف_کړه _A_SUBDIR 0x10
#تعریف_کړه _A_ARCH 0x20

#که_نه_تعریف_شوی _GETDISKFREE_DEFINED
#تعریف_کړه _GETDISKFREE_DEFINED
  _CRTIMP بینښه __cdecl _getdiskfree(بینښه _Drive,بنية _diskfree_t *_DiskFree);
#د_که_پای

#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __cdecl _disable(فراغ);
  فراغ __cdecl _enable(فراغ);
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
#تعریف_کړه diskfree_t _diskfree_t
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
