/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_DOS
#परिभाषय _INC_DOS

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _DISKFREE_T_DEFINED
#परिभाषय _DISKFREE_T_DEFINED

  संरचना _diskfree_t {
    अचिह्नित योग_clusters;
    अचिह्नित avail_clusters;
    अचिह्नित sectors_प्रत्येकम्_cluster;
    अचिह्नित अष्टकानि_प्रत्येकम्_sector;
  };
#यदि_अन्तः

#परिभाषय A_प्रसामान्यम् 0x00
#परिभाषय _A_RDONLY 0x01
#परिभाषय _A_HIDDEN 0x02
#परिभाषय _A_SYSTEM 0x04
#परिभाषय _A_SUBDIR 0x10
#परिभाषय _A_ARCH 0x20

#यदि_अपरिभाषितम् _GETDISKFREE_DEFINED
#परिभाषय _GETDISKFREE_DEFINED
  _CRTIMP अचिह्नित __cdecl _getdiskfree(अचिह्नित _Drive,संरचना _diskfree_t *_DiskFree);
#यदि_अन्तः

#यदि (defined(_X86_) && !defined(__x86_64))
  शून्य __cdecl _disable(शून्य);
  शून्य __cdecl _enable(शून्य);
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
#परिभाषय diskfree_t _diskfree_t
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
