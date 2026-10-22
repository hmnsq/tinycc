/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_ERRNO
#परिभाषय _INC_ERRNO

#अन्तर्भाव <_mingw.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRT_ERRNO_DEFINED
#परिभाषय _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णाङ्क *__cdecl _errno(शून्य);
#परिभाषय errno (*_errno())

  errno_t __cdecl समुच्चयः_errno(पूर्णाङ्क मानम्_2);
  errno_t __cdecl _get_errno(पूर्णाङ्क *मानम्_2);
#यदि_अन्तः

#परिभाषय EPERM 1
#परिभाषय ENOENT 2
#परिभाषय ESRCH 3
#परिभाषय EINTR 4
#परिभाषय EIO 5
#परिभाषय ENXIO 6
#परिभाषय E2BIG 7
#परिभाषय ENOEXEC 8
#परिभाषय EBADF 9
#परिभाषय ECHILD 10
#परिभाषय EAGAIN 11
#परिभाषय ENOMEM 12
#परिभाषय EACCES 13
#परिभाषय EFAULT 14
#परिभाषय EBUSY 16
#परिभाषय EEXIST 17
#परिभाषय EXDEV 18
#परिभाषय ENODEV 19
#परिभाषय ENOTDIR 20
#परिभाषय EISDIR 21
#परिभाषय ENFILE 23
#परिभाषय EMFILE 24
#परिभाषय ENOTTY 25
#परिभाषय EFBIG 27
#परिभाषय ENOSPC 28
#परिभाषय ESPIPE 29
#परिभाषय EROFS 30
#परिभाषय EMLINK 31
#परिभाषय EPIPE 32
#परिभाषय EDOM 33
#परिभाषय EDEADLK 36
#परिभाषय ENAMETOOLONG 38
#परिभाषय ENOLCK 39
#परिभाषय ENOSYS 40
#परिभाषय ENOTEMPTY 41

#यदि_अपरिभाषितम् RC_INVOKED
#यदि !defined(SECURECRT_ERRCODE_मानानि_DEFINED)
#परिभाषय SECURECRT_ERRCODE_मानानि_DEFINED
#परिभाषय EINVAL 22
#परिभाषय ERANGE 34
#परिभाषय EILSEQ 42
#परिभाषय STRUNCATE 80
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय EDEADLOCK EDEADLK

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
