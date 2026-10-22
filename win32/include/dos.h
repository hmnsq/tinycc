/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_DOS
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_DOS

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <io.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _DISKFREE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _DISKFREE_T_DEFINED

  ರಚನೆ _diskfree_t {
    ಚಿಹ್ನೆರಹಿತ ಒಟ್ಟು_clusters;
    ಚಿಹ್ನೆರಹಿತ avail_clusters;
    ಚಿಹ್ನೆರಹಿತ sectors_ಪ್ರತಿ_cluster;
    ಚಿಹ್ನೆರಹಿತ ಬೈಟುಗಳು_ಪ್ರತಿ_sector;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು A_ಸಾಮಾನ್ಯ 0x00
#ವ್ಯಾಖ್ಯಾನಿಸು _A_RDONLY 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು _A_HIDDEN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು _A_SYSTEM 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು _A_SUBDIR 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು _A_ARCH 0x20

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _GETDISKFREE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _GETDISKFREE_DEFINED
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __cdecl _getdiskfree(ಚಿಹ್ನೆರಹಿತ _Drive,ರಚನೆ _diskfree_t *_DiskFree);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ (defined(_X86_) && !defined(__x86_64))
  ಶೂನ್ಯ __cdecl _disable(ಶೂನ್ಯ);
  ಶೂನ್ಯ __cdecl _enable(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿಸು diskfree_t _diskfree_t
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
