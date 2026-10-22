/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_ERRNO
#تعریف_کرو _INC_ERRNO

#شامل <_mingw.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRT_ERRNO_DEFINED
#تعریف_کرو _CRT_ERRNO_DEFINED
  _CRTIMP صحیح *__cdecl _errno(خالی);
#تعریف_کرو errno (*_errno())

  errno_t __cdecl سیٹ_errno(صحیح قدر_2);
  errno_t __cdecl _get_errno(صحیح *قدر_2);
#اگر_ختم

#تعریف_کرو EPERM 1
#تعریف_کرو ENOENT 2
#تعریف_کرو ESRCH 3
#تعریف_کرو EINTR 4
#تعریف_کرو EIO 5
#تعریف_کرو ENXIO 6
#تعریف_کرو E2BIG 7
#تعریف_کرو ENOEXEC 8
#تعریف_کرو EBADF 9
#تعریف_کرو ECHILD 10
#تعریف_کرو EAGAIN 11
#تعریف_کرو ENOMEM 12
#تعریف_کرو EACCES 13
#تعریف_کرو EFAULT 14
#تعریف_کرو EBUSY 16
#تعریف_کرو EEXIST 17
#تعریف_کرو EXDEV 18
#تعریف_کرو ENODEV 19
#تعریف_کرو ENOTDIR 20
#تعریف_کرو EISDIR 21
#تعریف_کرو ENFILE 23
#تعریف_کرو EMFILE 24
#تعریف_کرو ENOTTY 25
#تعریف_کرو EFBIG 27
#تعریف_کرو ENOSPC 28
#تعریف_کرو ESPIPE 29
#تعریف_کرو EROFS 30
#تعریف_کرو EMLINK 31
#تعریف_کرو EPIPE 32
#تعریف_کرو EDOM 33
#تعریف_کرو EDEADLK 36
#تعریف_کرو ENAMETOOLONG 38
#تعریف_کرو ENOLCK 39
#تعریف_کرو ENOSYS 40
#تعریف_کرو ENOTEMPTY 41

#اگر_غیر_تعریف_شدہ RC_INVOKED
#اگر !defined(SECURECRT_ERRCODE_اقدار_DEFINED)
#تعریف_کرو SECURECRT_ERRCODE_اقدار_DEFINED
#تعریف_کرو EINVAL 22
#تعریف_کرو ERANGE 34
#تعریف_کرو EILSEQ 42
#تعریف_کرو STRUNCATE 80
#اگر_ختم
#اگر_ختم

#تعریف_کرو EDEADLOCK EDEADLK

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
