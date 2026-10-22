/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_ERRNO
#تعریف_کن _INC_ERRNO

#ضمن <_mingw.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CRT_ERRNO_DEFINED
#تعریف_کن _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#تعریف_کن errno (*_errno())

  errno_t __cdecl مجموعه_errno(صحيح مقدار_2);
  errno_t __cdecl _get_errno(صحيح *مقدار_2);
#پایان_اگر

#تعریف_کن EPERM 1
#تعریف_کن ENOENT 2
#تعریف_کن ESRCH 3
#تعریف_کن EINTR 4
#تعریف_کن EIO 5
#تعریف_کن ENXIO 6
#تعریف_کن E2BIG 7
#تعریف_کن ENOEXEC 8
#تعریف_کن EBADF 9
#تعریف_کن ECHILD 10
#تعریف_کن EAGAIN 11
#تعریف_کن ENOMEM 12
#تعریف_کن EACCES 13
#تعریف_کن EFAULT 14
#تعریف_کن EBUSY 16
#تعریف_کن EEXIST 17
#تعریف_کن EXDEV 18
#تعریف_کن ENODEV 19
#تعریف_کن ENOTDIR 20
#تعریف_کن EISDIR 21
#تعریف_کن ENFILE 23
#تعریف_کن EMFILE 24
#تعریف_کن ENOTTY 25
#تعریف_کن EFBIG 27
#تعریف_کن ENOSPC 28
#تعریف_کن ESPIPE 29
#تعریف_کن EROFS 30
#تعریف_کن EMLINK 31
#تعریف_کن EPIPE 32
#تعریف_کن EDOM 33
#تعریف_کن EDEADLK 36
#تعریف_کن ENAMETOOLONG 38
#تعریف_کن ENOLCK 39
#تعریف_کن ENOSYS 40
#تعریف_کن ENOTEMPTY 41

#اگر_تعریف_نشده RC_INVOKED
#إذا !defined(SECURECRT_ERRCODE_مقادیر_DEFINED)
#تعریف_کن SECURECRT_ERRCODE_مقادیر_DEFINED
#تعریف_کن EINVAL 22
#تعریف_کن ERANGE 34
#تعریف_کن EILSEQ 42
#تعریف_کن STRUNCATE 80
#پایان_اگر
#پایان_اگر

#تعریف_کن EDEADLOCK EDEADLK

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
