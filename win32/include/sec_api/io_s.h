/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_IO_S
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_IO_S

#ಅನ್ತರ್ಭಾವ <io.h>

#ಆದರೆ defined(MINGW_HAS_SECURE_API)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP errno_t __cdecl _access_s(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  _CRTIMP errno_t __cdecl _chsize_s(ಪೂರ್ಣಾಂಕ _FileHandle,__int64 ಗಾತ್ರ_5);
  _CRTIMP errno_t __cdecl _mktemp_s(ಅಕ್ಷರ *_TemplateName,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP errno_t __cdecl _umask_s(ಪೂರ್ಣಾಂಕ New_ಬಹುಲಕ,ಪೂರ್ಣಾಂಕ *Old_ಬಹುಲಕ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIO_S_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
