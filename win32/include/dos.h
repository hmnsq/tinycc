/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_DOS
#घोषणा _INC_DOS

#समावेश <_mingw.h>
#समावेश <io.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _DISKFREE_T_DEFINED
#घोषणा _DISKFREE_T_DEFINED

  काष्ठा _diskfree_t {
    अचिन्हित योग_clusters;
    अचिन्हित avail_clusters;
    अचिन्हित sectors_per_cluster;
    अचिन्हित bytes_per_sector;
  };
#पूर्ण_अगर

#घोषणा _A_NORMAL 0x00
#घोषणा _A_RDONLY 0x01
#घोषणा _A_HIDDEN 0x02
#घोषणा _A_SYSTEM 0x04
#घोषणा _A_SUBDIR 0x10
#घोषणा _A_ARCH 0x20

#अगर_अघोषित _GETDISKFREE_DEFINED
#घोषणा _GETDISKFREE_DEFINED
  _CRTIMP अचिन्हित __cdecl _getdiskfree(अचिन्हित _Drive,काष्ठा _diskfree_t *_DiskFree);
#पूर्ण_अगर

#अगर (defined(_X86_) && !defined(__x86_64))
  व्योम __cdecl _disable(व्योम);
  व्योम __cdecl _enable(व्योम);
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
#घोषणा diskfree_t _diskfree_t
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
