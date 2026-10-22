/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_ERRNO
#define _INC_ERRNO

#અન્તર્ભાવ <_mingw.h>

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _CRT_ERRNO_DEFINED
#define _CRT_ERRNO_DEFINED
  _CRTIMP પૂર્ણાંક *__cdecl _errno(શૂન્ય);
#define errno (*_errno())

  errno_t __cdecl _set_errno(પૂર્ણાંક કિંમત_2);
  errno_t __cdecl _get_errno(પૂર્ણાંક *કિંમત_2);
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
#જો !defined(SECURECRT_ERRCODE_કિંમતો_DEFINED)
#define SECURECRT_ERRCODE_કિંમતો_DEFINED
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
