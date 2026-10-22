/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_ERRNO
#تعریف_کړه _INC_ERRNO

#ضمن <_mingw.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CRT_ERRNO_DEFINED
#تعریف_کړه _CRT_ERRNO_DEFINED
  _CRTIMP صحيح *__cdecl _errno(فراغ);
#تعریف_کړه errno (*_errno())

  errno_t __cdecl سېټ_errno(صحيح ارزښت_2);
  errno_t __cdecl _get_errno(صحيح *ارزښت_2);
#د_که_پای

#تعریف_کړه EPERM 1
#تعریف_کړه ENOENT 2
#تعریف_کړه ESRCH 3
#تعریف_کړه EINTR 4
#تعریف_کړه EIO 5
#تعریف_کړه ENXIO 6
#تعریف_کړه E2BIG 7
#تعریف_کړه ENOEXEC 8
#تعریف_کړه EBADF 9
#تعریف_کړه ECHILD 10
#تعریف_کړه EAGAIN 11
#تعریف_کړه ENOMEM 12
#تعریف_کړه EACCES 13
#تعریف_کړه EFAULT 14
#تعریف_کړه EBUSY 16
#تعریف_کړه EEXIST 17
#تعریف_کړه EXDEV 18
#تعریف_کړه ENODEV 19
#تعریف_کړه ENOTDIR 20
#تعریف_کړه EISDIR 21
#تعریف_کړه ENFILE 23
#تعریف_کړه EMFILE 24
#تعریف_کړه ENOTTY 25
#تعریف_کړه EFBIG 27
#تعریف_کړه ENOSPC 28
#تعریف_کړه ESPIPE 29
#تعریف_کړه EROFS 30
#تعریف_کړه EMLINK 31
#تعریف_کړه EPIPE 32
#تعریف_کړه EDOM 33
#تعریف_کړه EDEADLK 36
#تعریف_کړه ENAMETOOLONG 38
#تعریف_کړه ENOLCK 39
#تعریف_کړه ENOSYS 40
#تعریف_کړه ENOTEMPTY 41

#که_نه_تعریف_شوی RC_INVOKED
#إذا !defined(SECURECRT_ERRCODE_ارزښتونه_DEFINED)
#تعریف_کړه SECURECRT_ERRCODE_ارزښتونه_DEFINED
#تعریف_کړه EINVAL 22
#تعریف_کړه ERANGE 34
#تعریف_کړه EILSEQ 42
#تعریف_کړه STRUNCATE 80
#د_که_پای
#د_که_پای

#تعریف_کړه EDEADLOCK EDEADLK

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
