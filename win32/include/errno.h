/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_ERRNO
#घोषणा _INC_ERRNO

#समावेश <_mingw.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CRT_ERRNO_DEFINED
#घोषणा _CRT_ERRNO_DEFINED
  _CRTIMP पूर्णांक *__cdecl _errno(व्योम);
#घोषणा त्रुटि_सं (*_errno())

  errno_t __cdecl _set_errno(पूर्णांक मूल्य_2);
  errno_t __cdecl _get_errno(पूर्णांक *मूल्य_2);
#पूर्ण_अगर

#घोषणा EPERM 1
#घोषणा ENOENT 2
#घोषणा ESRCH 3
#घोषणा EINTR 4
#घोषणा EIO 5
#घोषणा ENXIO 6
#घोषणा E2BIG 7
#घोषणा ENOEXEC 8
#घोषणा EBADF 9
#घोषणा ECHILD 10
#घोषणा EAGAIN 11
#घोषणा ENOMEM 12
#घोषणा EACCES 13
#घोषणा EFAULT 14
#घोषणा EBUSY 16
#घोषणा EEXIST 17
#घोषणा EXDEV 18
#घोषणा ENODEV 19
#घोषणा ENOTDIR 20
#घोषणा EISDIR 21
#घोषणा ENFILE 23
#घोषणा EMFILE 24
#घोषणा ENOTTY 25
#घोषणा EFBIG 27
#घोषणा ENOSPC 28
#घोषणा ESPIPE 29
#घोषणा EROFS 30
#घोषणा EMLINK 31
#घोषणा EPIPE 32
#घोषणा गलत_तर्क 33
#घोषणा EDEADLK 36
#घोषणा ENAMETOOLONG 38
#घोषणा ENOLCK 39
#घोषणा ENOSYS 40
#घोषणा ENOTEMPTY 41

#अगर_अघोषित RC_INVOKED
#अगर !defined(SECURECRT_ERRCODE_मूल्यावली_DEFINED)
#घोषणा SECURECRT_ERRCODE_मूल्यावली_DEFINED
#घोषणा EINVAL 22
#घोषणा दुस्फल 34
#घोषणा EILSEQ 42
#घोषणा STRUNCATE 80
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा EDEADLOCK EDEADLK

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
