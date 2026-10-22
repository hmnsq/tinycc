/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_ERRNO
#నిర్వచించు _INC_ERRNO

#అన్తర్భావ <_mingw.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRT_ERRNO_DEFINED
#నిర్వచించు _CRT_ERRNO_DEFINED
  _CRTIMP పూర్ణాంకం *__cdecl _errno(శూన్య);
#నిర్వచించు errno (*_errno())

  errno_t __cdecl సమితి_errno(పూర్ణాంకం విలువ_2);
  errno_t __cdecl _get_errno(పూర్ణాంకం *విలువ_2);
#అయితే_ముగింపు

#నిర్వచించు EPERM 1
#నిర్వచించు ENOENT 2
#నిర్వచించు ESRCH 3
#నిర్వచించు EINTR 4
#నిర్వచించు EIO 5
#నిర్వచించు ENXIO 6
#నిర్వచించు E2BIG 7
#నిర్వచించు ENOEXEC 8
#నిర్వచించు EBADF 9
#నిర్వచించు ECHILD 10
#నిర్వచించు EAGAIN 11
#నిర్వచించు ENOMEM 12
#నిర్వచించు EACCES 13
#నిర్వచించు EFAULT 14
#నిర్వచించు EBUSY 16
#నిర్వచించు EEXIST 17
#నిర్వచించు EXDEV 18
#నిర్వచించు ENODEV 19
#నిర్వచించు ENOTDIR 20
#నిర్వచించు EISDIR 21
#నిర్వచించు ENFILE 23
#నిర్వచించు EMFILE 24
#నిర్వచించు ENOTTY 25
#నిర్వచించు EFBIG 27
#నిర్వచించు ENOSPC 28
#నిర్వచించు ESPIPE 29
#నిర్వచించు EROFS 30
#నిర్వచించు EMLINK 31
#నిర్వచించు EPIPE 32
#నిర్వచించు EDOM 33
#నిర్వచించు EDEADLK 36
#నిర్వచించు ENAMETOOLONG 38
#నిర్వచించు ENOLCK 39
#నిర్వచించు ENOSYS 40
#నిర్వచించు ENOTEMPTY 41

#నిర్వచితం_కాకపోతే RC_INVOKED
#ఒకవేళ !defined(SECURECRT_ERRCODE_విలువలు_DEFINED)
#నిర్వచించు SECURECRT_ERRCODE_విలువలు_DEFINED
#నిర్వచించు EINVAL 22
#నిర్వచించు ERANGE 34
#నిర్వచించు EILSEQ 42
#నిర్వచించు STRUNCATE 80
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు EDEADLOCK EDEADLK

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
