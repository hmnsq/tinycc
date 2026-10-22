/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_ERRNO
#وصف_ڪريو _INC_ERRNO

#ضمن <_mingw.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRT_ERRNO_DEFINED
#وصف_ڪريو _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#وصف_ڪريو errno (*_errno())

  errno_t __cdecl سيٽ_errno(صحيح قدر_2);
  errno_t __cdecl _get_errno(صحيح *قدر_2);
#جيڪڏهن_پورو

#وصف_ڪريو EPERM 1
#وصف_ڪريو ENOENT 2
#وصف_ڪريو ESRCH 3
#وصف_ڪريو EINTR 4
#وصف_ڪريو EIO 5
#وصف_ڪريو ENXIO 6
#وصف_ڪريو E2BIG 7
#وصف_ڪريو ENOEXEC 8
#وصف_ڪريو EBADF 9
#وصف_ڪريو ECHILD 10
#وصف_ڪريو EAGAIN 11
#وصف_ڪريو ENOMEM 12
#وصف_ڪريو EACCES 13
#وصف_ڪريو EFAULT 14
#وصف_ڪريو EBUSY 16
#وصف_ڪريو EEXIST 17
#وصف_ڪريو EXDEV 18
#وصف_ڪريو ENODEV 19
#وصف_ڪريو ENOTDIR 20
#وصف_ڪريو EISDIR 21
#وصف_ڪريو ENFILE 23
#وصف_ڪريو EMFILE 24
#وصف_ڪريو ENOTTY 25
#وصف_ڪريو EFBIG 27
#وصف_ڪريو ENOSPC 28
#وصف_ڪريو ESPIPE 29
#وصف_ڪريو EROFS 30
#وصف_ڪريو EMLINK 31
#وصف_ڪريو EPIPE 32
#وصف_ڪريو EDOM 33
#وصف_ڪريو EDEADLK 36
#وصف_ڪريو ENAMETOOLONG 38
#وصف_ڪريو ENOLCK 39
#وصف_ڪريو ENOSYS 40
#وصف_ڪريو ENOTEMPTY 41

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#إذا !defined(SECURECRT_ERRCODE_قدرون_DEFINED)
#وصف_ڪريو SECURECRT_ERRCODE_قدرون_DEFINED
#وصف_ڪريو EINVAL 22
#وصف_ڪريو ERANGE 34
#وصف_ڪريو EILSEQ 42
#وصف_ڪريو STRUNCATE 80
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو EDEADLOCK EDEADLK

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
