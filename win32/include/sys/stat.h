/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STAT
#define _INC_STAT

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#अन्तर्भाव <sys/types.h>

#ifndef __TINYC__ /* gr */
#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#undef _USE_32BIT_TIME_T
#endif
#अन्यथा
#जर _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif
#endif

#ifndef _TIME32_T_DEFINED
  प्रकारव्याख्या दीर्घ __time32_t;
#define _TIME32_T_DEFINED
#endif

#ifndef _TIME64_T_DEFINED
#जर _INTEGRAL_MAX_BITS >= 64
  प्रकारव्याख्या __int64 __time64_t;
#endif
#define _TIME64_T_DEFINED
#endif

#ifndef _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  प्रकारव्याख्या __time32_t समय_प्रकार;
#अन्यथा
  प्रकारव्याख्या __time64_t समय_प्रकार;
#endif
#define _TIME_T_DEFINED
#endif

#ifndef _WCHAR_T_DEFINED
  प्रकारव्याख्या अचिन्हित लघु ब_अक्षर_प्रकार;
#define _WCHAR_T_DEFINED
#endif

#ifndef _STAT_DEFINED

#ifdef _USE_32BIT_TIME_T
#ifndef _WIN64
#define _fstat32 _fstat
#define _stat32 _stat
#define _wstat32 _wstat
#अन्यथा
#define _fstat _fstat32
#define _stat _stat32
#define _wstat _wstat32
#endif
#define _fstati64 _fstat32i64
#define _stati64 _stat32i64
#define _wstati64 _wstat32i64
#अन्यथा
#define _fstat _fstat64i32
#define _fstati64 _fstat64
#define _stat _stat64
#define _stati64 _stat64
#define _wstat _wstat64
#define _wstati64 _wstat64
#endif

  संरचना _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ifndef	NO_OLDNAMES
  संरचना stat {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    समय_प्रकार st_atime;
    समय_प्रकार st_mtime;
    समय_प्रकार st_ctime;
  };
#endif

#जर _INTEGRAL_MAX_BITS >= 64
  संरचना _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  संरचना _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  संरचना _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#endif

#define __stat64 _stat64

#define _STAT_DEFINED
#endif

#define _S_IFMT 0xF000
#define _S_IFDIR 0x4000
#define _S_IFCHR 0x2000
#define _S_IFIFO 0x1000
#define _S_IFREG 0x8000
#define _S_IREAD 0x0100
#define _S_IWRITE 0x0080
#define _S_IEXEC 0x0040

  _CRTIMP पूर्णांक __cdecl _fstat32(पूर्णांक _FileDes,संरचना _stat32 *_Stat);
  _CRTIMP पूर्णांक __cdecl _stat32(स्थिरांक अक्षर *_Name,संरचना _stat32 *_Stat);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _fstat64(पूर्णांक _FileDes,संरचना _stat64 *_Stat);
  _CRTIMP पूर्णांक __cdecl _fstat32i64(पूर्णांक _FileDes,संरचना _stat32i64 *_Stat);
  पूर्णांक __cdecl _fstat64i32(पूर्णांक _FileDes,संरचना _stat64i32 *_Stat);
  __CRT_INLINE पूर्णांक __cdecl _fstat64i32(पूर्णांक _FileDes,संरचना _stat64i32 *_Stat)
  {
    संरचना _stat64 st;
    पूर्णांक ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_size=(_off_t) st.st_size;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    परत ret;
  }
  _CRTIMP पूर्णांक __cdecl _stat64(स्थिरांक अक्षर *_Name,संरचना _stat64 *_Stat);
  _CRTIMP पूर्णांक __cdecl _stat32i64(स्थिरांक अक्षर *_Name,संरचना _stat32i64 *_Stat);
  पूर्णांक __cdecl _stat64i32(स्थिरांक अक्षर *_Name,संरचना _stat64i32 *_Stat);
  __CRT_INLINE पूर्णांक __cdecl _stat64i32(स्थिरांक अक्षर *_Name,संरचना _stat64i32 *_Stat)
  {
    संरचना _stat64 st;
    पूर्णांक ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_size=(_off_t) st.st_size;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    परत ret;
  }
#endif

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED
  _CRTIMP पूर्णांक __cdecl _wstat32(स्थिरांक ब_अक्षर_प्रकार *_Name,संरचना _stat32 *_Stat);
#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _wstat32i64(स्थिरांक ब_अक्षर_प्रकार *_Name,संरचना _stat32i64 *_Stat);
  पूर्णांक __cdecl _wstat64i32(स्थिरांक ब_अक्षर_प्रकार *_Name,संरचना _stat64i32 *_Stat);
  _CRTIMP पूर्णांक __cdecl _wstat64(स्थिरांक ब_अक्षर_प्रकार *_Name,संरचना _stat64 *_Stat);
#endif
#endif

#ifndef	NO_OLDNAMES
#define	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#define S_IFMT _S_IFMT
#define S_IFDIR _S_IFDIR
#define S_IFCHR _S_IFCHR
#define S_IFREG _S_IFREG
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#define S_IEXEC _S_IEXEC
#define	S_IFIFO		_S_IFIFO
#define	S_IFBLK		_S_IFBLK

#define	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#define	_S_IXUSR	_S_IEXEC
#define	_S_IWUSR	_S_IWRITE

#define	S_IRWXU		_S_IRWXU
#define	S_IXUSR		_S_IXUSR
#define	S_IWUSR		_S_IWUSR
#define	S_IRUSR		_S_IRUSR
#define	_S_IRUSR	_S_IREAD

#define	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#endif

#जर !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
पूर्णांक __cdecl stat(स्थिरांक अक्षर *_Filename,संरचना stat *_Stat);
पूर्णांक __cdecl ख_स्थिति(पूर्णांक _Desc,संरचना stat *_Stat);
पूर्णांक __cdecl wstat(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना stat *_Stat);
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE पूर्णांक __cdecl ख_स्थिति(पूर्णांक _Desc,संरचना stat *_Stat) {
  परत _fstat32(_Desc,(संरचना _stat32 *)_Stat);
}
__CRT_INLINE पूर्णांक __cdecl stat(स्थिरांक अक्षर *_Filename,संरचना stat *_Stat) {
  परत _stat32(_Filename,(संरचना _stat32 *)_Stat);
}
#अन्यथा
__CRT_INLINE पूर्णांक __cdecl ख_स्थिति(पूर्णांक _Desc,संरचना stat *_Stat) {
  परत _fstat64i32(_Desc,(संरचना _stat64i32 *)_Stat);
}
__CRT_INLINE पूर्णांक __cdecl stat(स्थिरांक अक्षर *_Filename,संरचना stat *_Stat) {
  परत _stat64i32(_Filename,(संरचना _stat64i32 *)_Stat);
}
#endif
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
