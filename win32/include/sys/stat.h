/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_STAT
#وصف_ڪريو _INC_STAT

#جيڪڏهن_وصف_نه_ٿيل _WIN32
#غلطي Only Win32 هدف is supported!
#جيڪڏهن_پورو

#ضمن <_mingw.h>
#ضمن <io.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _CRTIMP
#وصف_ڪريو _CRTIMP __declspec(dllimport)
#جيڪڏهن_پورو

#ضمن <sys/types.h>

#جيڪڏهن_وصف_نه_ٿيل __TINYC__ /* gr */
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_رد USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#وإلا
#إذا INTEGRAL_MAX_بٽ < 64
#وصف_ڪريو USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME32_T_DEFINED
  تعريفنوع ڊگهو __time32_t;
#وصف_ڪريو _TIME32_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٽ >= 64
  تعريفنوع __int64 __time64_t;
#جيڪڏهن_پورو
#وصف_ڪريو _TIME64_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل وقت_T_DEFINED
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جيڪڏهن_پورو
#وصف_ڪريو وقت_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCHAR_T_DEFINED
  تعريفنوع بنانشان ننڍو wchar_t;
#وصف_ڪريو _WCHAR_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STAT_DEFINED

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#جيڪڏهن_وصف_نه_ٿيل _WIN64
#وصف_ڪريو _fstat32 _fstat
#وصف_ڪريو _stat32 _stat
#وصف_ڪريو _wstat32 _wstat
#وإلا
#وصف_ڪريو _fstat _fstat32
#وصف_ڪريو _stat _stat32
#وصف_ڪريو _wstat _wstat32
#جيڪڏهن_پورو
#وصف_ڪريو _fstati64 _fstat32i64
#وصف_ڪريو _stati64 _stat32i64
#وصف_ڪريو _wstati64 _wstat32i64
#وإلا
#وصف_ڪريو _fstat _fstat64i32
#وصف_ڪريو _fstati64 _fstat64
#وصف_ڪريو _stat _stat64
#وصف_ڪريو _stati64 _stat64
#وصف_ڪريو _wstat _wstat64
#وصف_ڪريو _wstati64 _wstat64
#جيڪڏهن_پورو

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    _off_t st_سائيز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    _off_t st_سائيز;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#جيڪڏهن_پورو

#إذا INTEGRAL_MAX_بٽ >= 64
  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    __int64 st_سائيز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    _off_t st_سائيز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشان ننڍو st_گهڻائي;
    ننڍو st_nlink;
    ننڍو st_uid;
    ننڍو st_gid;
    _dev_t st_rdev;
    __int64 st_سائيز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#جيڪڏهن_پورو

#وصف_ڪريو __stat64 _stat64

#وصف_ڪريو _STAT_DEFINED
#جيڪڏهن_پورو

#وصف_ڪريو _S_IFMT 0xF000
#وصف_ڪريو _S_IFDIR 0x4000
#وصف_ڪريو _S_IFCHR 0x2000
#وصف_ڪريو _S_IFIFO 0x1000
#وصف_ڪريو _S_IFREG 0x8000
#وصف_ڪريو _S_IREAD 0x0100
#وصف_ڪريو _S_IWRITE 0x0080
#وصف_ڪريو _S_IEXEC 0x0040

  _CRTIMP صحيح __cdecl _fstat32(صحيح _FileDes,بنية _stat32 *_Stat);
  _CRTIMP صحيح __cdecl _stat32(ثابت حرف *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP صحيح __cdecl _fstat64(صحيح _FileDes,بنية _stat64 *_Stat);
  _CRTIMP صحيح __cdecl _fstat32i64(صحيح _FileDes,بنية _stat32i64 *_Stat);
  صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat);
  __CRT_INLINE صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat)
  {
    بنية _stat64 st;
    صحيح ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_گهڻائي=st.st_گهڻائي;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_سائيز=(_off_t) st.st_سائيز;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    أرجع ret;
  }
  _CRTIMP صحيح __cdecl _stat64(ثابت حرف *_Name,بنية _stat64 *_Stat);
  _CRTIMP صحيح __cdecl _stat32i64(ثابت حرف *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _stat64i32(ثابت حرف *_Name,بنية _stat64i32 *_Stat);
  __CRT_INLINE صحيح __cdecl _stat64i32(ثابت حرف *_Name,بنية _stat64i32 *_Stat)
  {
    بنية _stat64 st;
    صحيح ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_گهڻائي=st.st_گهڻائي;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_سائيز=(_off_t) st.st_سائيز;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    أرجع ret;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WSTAT_DEFINED
#وصف_ڪريو _WSTAT_DEFINED
  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#وصف_ڪريو	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#وصف_ڪريو S_IFMT _S_IFMT
#وصف_ڪريو S_IFDIR _S_IFDIR
#وصف_ڪريو S_IFCHR _S_IFCHR
#وصف_ڪريو S_IFREG _S_IFREG
#وصف_ڪريو S_IREAD _S_IREAD
#وصف_ڪريو S_IWRITE _S_IWRITE
#وصف_ڪريو S_IEXEC _S_IEXEC
#وصف_ڪريو	S_IFIFO		_S_IFIFO
#وصف_ڪريو	S_IFBLK		_S_IFBLK

#وصف_ڪريو	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#وصف_ڪريو	_S_IXUSR	_S_IEXEC
#وصف_ڪريو	_S_IWUSR	_S_IWRITE

#وصف_ڪريو	S_IRWXU		_S_IRWXU
#وصف_ڪريو	S_IXUSR		_S_IXUSR
#وصف_ڪريو	S_IWUSR		_S_IWUSR
#وصف_ڪريو	S_IRUSR		_S_IRUSR
#وصف_ڪريو	_S_IRUSR	_S_IREAD

#وصف_ڪريو	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#وصف_ڪريو	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#وصف_ڪريو	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#وصف_ڪريو	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#وصف_ڪريو	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#جيڪڏهن_پورو

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
صحيح __cdecl stat(ثابت حرف *_Filename,بنية stat *_Stat);
صحيح __cdecl fstat(صحيح _Desc,بنية stat *_Stat);
صحيح __cdecl wstat(ثابت wchar_t *_Filename,بنية stat *_Stat);
#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
__CRT_INLINE صحيح __cdecl fstat(صحيح _Desc,بنية stat *_Stat) {
  أرجع _fstat32(_Desc,(بنية _stat32 *)_Stat);
}
__CRT_INLINE صحيح __cdecl stat(ثابت حرف *_Filename,بنية stat *_Stat) {
  أرجع _stat32(_Filename,(بنية _stat32 *)_Stat);
}
#وإلا
__CRT_INLINE صحيح __cdecl fstat(صحيح _Desc,بنية stat *_Stat) {
  أرجع _fstat64i32(_Desc,(بنية _stat64i32 *)_Stat);
}
__CRT_INLINE صحيح __cdecl stat(ثابت حرف *_Filename,بنية stat *_Stat) {
  أرجع _stat64i32(_Filename,(بنية _stat64i32 *)_Stat);
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
