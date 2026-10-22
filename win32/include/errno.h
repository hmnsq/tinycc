/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_ERRNO
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_ERRNO

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_ERRNO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_ERRNO_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ *__cdecl _errno(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿಸು errno (*_errno())

  errno_t __cdecl ಗಣ_errno(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2);
  errno_t __cdecl _get_errno(ಪೂರ್ಣಾಂಕ *ಮೌಲ್ಯ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EPERM 1
#ವ್ಯಾಖ್ಯಾನಿಸು ENOENT 2
#ವ್ಯಾಖ್ಯಾನಿಸು ESRCH 3
#ವ್ಯಾಖ್ಯಾನಿಸು EINTR 4
#ವ್ಯಾಖ್ಯಾನಿಸು EIO 5
#ವ್ಯಾಖ್ಯಾನಿಸು ENXIO 6
#ವ್ಯಾಖ್ಯಾನಿಸು E2BIG 7
#ವ್ಯಾಖ್ಯಾನಿಸು ENOEXEC 8
#ವ್ಯಾಖ್ಯಾನಿಸು EBADF 9
#ವ್ಯಾಖ್ಯಾನಿಸು ECHILD 10
#ವ್ಯಾಖ್ಯಾನಿಸು EAGAIN 11
#ವ್ಯಾಖ್ಯಾನಿಸು ENOMEM 12
#ವ್ಯಾಖ್ಯಾನಿಸು EACCES 13
#ವ್ಯಾಖ್ಯಾನಿಸು EFAULT 14
#ವ್ಯಾಖ್ಯಾನಿಸು EBUSY 16
#ವ್ಯಾಖ್ಯಾನಿಸು EEXIST 17
#ವ್ಯಾಖ್ಯಾನಿಸು EXDEV 18
#ವ್ಯಾಖ್ಯಾನಿಸು ENODEV 19
#ವ್ಯಾಖ್ಯಾನಿಸು ENOTDIR 20
#ವ್ಯಾಖ್ಯಾನಿಸು EISDIR 21
#ವ್ಯಾಖ್ಯಾನಿಸು ENFILE 23
#ವ್ಯಾಖ್ಯಾನಿಸು EMFILE 24
#ವ್ಯಾಖ್ಯಾನಿಸು ENOTTY 25
#ವ್ಯಾಖ್ಯಾನಿಸು EFBIG 27
#ವ್ಯಾಖ್ಯಾನಿಸು ENOSPC 28
#ವ್ಯಾಖ್ಯಾನಿಸು ESPIPE 29
#ವ್ಯಾಖ್ಯಾನಿಸು EROFS 30
#ವ್ಯಾಖ್ಯಾನಿಸು EMLINK 31
#ವ್ಯಾಖ್ಯಾನಿಸು EPIPE 32
#ವ್ಯಾಖ್ಯಾನಿಸು EDOM 33
#ವ್ಯಾಖ್ಯಾನಿಸು EDEADLK 36
#ವ್ಯಾಖ್ಯಾನಿಸು ENAMETOOLONG 38
#ವ್ಯಾಖ್ಯಾನಿಸು ENOLCK 39
#ವ್ಯಾಖ್ಯಾನಿಸು ENOSYS 40
#ವ್ಯಾಖ್ಯಾನಿಸು ENOTEMPTY 41

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ಆದರೆ !defined(SECURECRT_ERRCODE_ಮೌಲ್ಯಗಳು_DEFINED)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURECRT_ERRCODE_ಮೌಲ್ಯಗಳು_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು EINVAL 22
#ವ್ಯಾಖ್ಯಾನಿಸು ERANGE 34
#ವ್ಯಾಖ್ಯಾನಿಸು EILSEQ 42
#ವ್ಯಾಖ್ಯಾನಿಸು STRUNCATE 80
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EDEADLOCK EDEADLK

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
