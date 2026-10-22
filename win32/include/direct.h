/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ INC_ನೇರ
#ವ್ಯಾಖ್ಯಾನಿಸು INC_ನೇರ

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

  _CRTIMP ಅಕ್ಷರ *__cdecl _getcwd(ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP ಅಕ್ಷರ *__cdecl _getdcwd(ಪೂರ್ಣಾಂಕ _Drive,ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  ಅಕ್ಷರ *__cdecl _getdcwd_nolock(ಪೂರ್ಣಾಂಕ _Drive,ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _chdir(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _mkdir(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _rmdir(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _chdrive(ಪೂರ್ಣಾಂಕ _Drive);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getdrive(ಶೂನ್ಯ);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _getdrives(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _GETDISKFREE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _GETDISKFREE_DEFINED
  _CRTIMP ಚಿಹ್ನೆರಹಿತ __cdecl _getdiskfree(ಚಿಹ್ನೆರಹಿತ _Drive,ರಚನೆ _diskfree_t *_DiskFree);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WDIRECT_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ಪೂರ್ಣಾಂಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  wchar_t *__cdecl _wgetdcwd_nolock(ಪೂರ್ಣಾಂಕ _Drive,wchar_t *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wchdir(ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wmkdir(ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wrmdir(ಸ್ಥಿರಾಂಕ wchar_t *ಮಾರ್ಗ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES

#ವ್ಯಾಖ್ಯಾನಿಸು diskfree_t _diskfree_t

  ಅಕ್ಷರ *__cdecl getcwd(ಅಕ್ಷರ *_DstBuf,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  ಪೂರ್ಣಾಂಕ __cdecl chdir(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2);
  ಪೂರ್ಣಾಂಕ __cdecl mkdir(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2);
  ಪೂರ್ಣಾಂಕ __cdecl rmdir(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
