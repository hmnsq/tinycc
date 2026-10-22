/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_ERRNO
#define _INC_ERRNO

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା *__cdecl _errno(ଶୂନ୍ୟ);
#define errno (*_errno())

  errno_t __cdecl _set_errno(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2);
  errno_t __cdecl _get_errno(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ମୂଲ୍ୟ_2);
#endif

#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define EDEADLK 36
#define ENAMETOOLONG 38
#define ENOLCK 39
#define ENOSYS 40
#define ENOTEMPTY 41

#ifndef RC_INVOKED
#ଯଦି !defined(SECURECRT_ERRCODE_ମୂଲ୍ୟଗୁଡ଼ିକ_DEFINED)
#define SECURECRT_ERRCODE_ମୂଲ୍ୟଗୁଡ଼ିକ_DEFINED
#define EINVAL 22
#define ERANGE 34
#define EILSEQ 42
#define STRUNCATE 80
#endif
#endif

#define EDEADLOCK EDEADLK

#ifdef __cplusplus
}
#endif
#endif
