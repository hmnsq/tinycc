/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_DOS
#تعریف_کن _INC_DOS

#ضمن <_mingw.h>
#ضمن <io.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _DISKFREE_T_DEFINED
#تعریف_کن _DISKFREE_T_DEFINED

  بنية _diskfree_t {
    بیعلامت مجموع_clusters;
    بیعلامت avail_clusters;
    بیعلامت sectors_در_هر_cluster;
    بیعلامت بایتها_در_هر_sector;
  };
#پایان_اگر

#تعریف_کن A_نرمال 0x00
#تعریف_کن _A_RDONLY 0x01
#تعریف_کن _A_HIDDEN 0x02
#تعریف_کن _A_SYSTEM 0x04
#تعریف_کن _A_SUBDIR 0x10
#تعریف_کن _A_ARCH 0x20

#اگر_تعریف_نشده _GETDISKFREE_DEFINED
#تعریف_کن _GETDISKFREE_DEFINED
  _CRTIMP بیعلامت __cdecl _getdiskfree(بیعلامت _Drive,بنية _diskfree_t *_DiskFree);
#پایان_اگر

#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __cdecl _disable(فراغ);
  فراغ __cdecl _enable(فراغ);
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
#تعریف_کن diskfree_t _diskfree_t
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
