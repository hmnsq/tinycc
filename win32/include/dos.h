/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_DOS
#تعریف_کرو _INC_DOS

#شامل <_mingw.h>
#شامل <io.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _DISKFREE_T_DEFINED
#تعریف_کرو _DISKFREE_T_DEFINED

  ساخت _diskfree_t {
    غیرعلامتی کل_clusters;
    غیرعلامتی avail_clusters;
    غیرعلامتی sectors_فی_cluster;
    غیرعلامتی بائٹیں_فی_sector;
  };
#اگر_ختم

#تعریف_کرو A_معمول 0x00
#تعریف_کرو _A_RDONLY 0x01
#تعریف_کرو _A_HIDDEN 0x02
#تعریف_کرو _A_SYSTEM 0x04
#تعریف_کرو _A_SUBDIR 0x10
#تعریف_کرو _A_ARCH 0x20

#اگر_غیر_تعریف_شدہ _GETDISKFREE_DEFINED
#تعریف_کرو _GETDISKFREE_DEFINED
  _CRTIMP غیرعلامتی __cdecl _getdiskfree(غیرعلامتی _Drive,ساخت _diskfree_t *_DiskFree);
#اگر_ختم

#اگر (defined(_X86_) && !defined(__x86_64))
  خالی __cdecl _disable(خالی);
  خالی __cdecl _enable(خالی);
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#تعریف_کرو diskfree_t _diskfree_t
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
