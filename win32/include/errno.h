/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_ERRNO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_ERRNO

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_ERRNO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_ERRNO_DEFINED
  _CRTIMP ਪੂਰਨ *__cdecl _errno(ਖਾਲੀ);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ errno (*_errno())

  errno_t __cdecl ਸੈੱਟ_errno(ਪੂਰਨ ਮੁੱਲ_2);
  errno_t __cdecl _get_errno(ਪੂਰਨ *ਮੁੱਲ_2);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPERM 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOENT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESRCH 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EINTR 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EIO 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENXIO 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ E2BIG 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOEXEC 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EBADF 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ECHILD 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAGAIN 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOMEM 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EACCES 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EFAULT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EBUSY 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EEXIST 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXDEV 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENODEV 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOTDIR 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EISDIR 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENFILE 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMFILE 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOTTY 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EFBIG 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOSPC 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESPIPE 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EROFS 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMLINK 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPIPE 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDOM 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDEADLK 36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENAMETOOLONG 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOLCK 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOSYS 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOTEMPTY 41

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਜੇ !defined(SECURECRT_ERRCODE_ਮੁੱਲਾਂ_DEFINED)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURECRT_ERRCODE_ਮੁੱਲਾਂ_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EINVAL 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERANGE 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EILSEQ 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRUNCATE 80
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDEADLOCK EDEADLK

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
