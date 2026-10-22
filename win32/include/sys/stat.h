/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_STAT
#تعریف_کړه _INC_STAT

#که_نه_تعریف_شوی _WIN32
#تېروتنه Only Win32 موخه is supported!
#د_که_پای

#ضمن <_mingw.h>
#ضمن <io.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _CRTIMP
#تعریف_کړه _CRTIMP __declspec(dllimport)
#د_که_پای

#ضمن <sys/types.h>

#که_نه_تعریف_شوی __TINYC__ /* gr */
#که_تعریف_شوی USE_32_بټ_وخت_T
#که_تعریف_شوی _WIN64
#تعریف_لغوه USE_32_بټ_وخت_T
#د_که_پای
#وإلا
#إذا INTEGRAL_MAX_بټونه < 64
#تعریف_کړه USE_32_بټ_وخت_T
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _TIME32_T_DEFINED
  تعريفنوع اوږد __time32_t;
#تعریف_کړه _TIME32_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بټونه >= 64
  تعريفنوع __int64 __time64_t;
#د_که_پای
#تعریف_کړه _TIME64_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی وخت_T_DEFINED
#که_تعریف_شوی USE_32_بټ_وخت_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#د_که_پای
#تعریف_کړه وخت_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _WCHAR_T_DEFINED
  تعريفنوع بینښه لنډ wchar_t;
#تعریف_کړه _WCHAR_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _STAT_DEFINED

#که_تعریف_شوی USE_32_بټ_وخت_T
#که_نه_تعریف_شوی _WIN64
#تعریف_کړه _fstat32 _fstat
#تعریف_کړه _stat32 _stat
#تعریف_کړه _wstat32 _wstat
#وإلا
#تعریف_کړه _fstat _fstat32
#تعریف_کړه _stat _stat32
#تعریف_کړه _wstat _wstat32
#د_که_پای
#تعریف_کړه _fstati64 _fstat32i64
#تعریف_کړه _stati64 _stat32i64
#تعریف_کړه _wstati64 _wstat32i64
#وإلا
#تعریف_کړه _fstat _fstat64i32
#تعریف_کړه _fstati64 _fstat64
#تعریف_کړه _stat _stat64
#تعریف_کړه _stati64 _stat64
#تعریف_کړه _wstat _wstat64
#تعریف_کړه _wstati64 _wstat64
#د_که_پای

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بینښه لنډ st_ډېرپېښ;
    لنډ st_nlink;
    لنډ st_uid;
    لنډ st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#که_نه_تعریف_شوی	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بینښه لنډ st_ډېرپېښ;
    لنډ st_nlink;
    لنډ st_uid;
    لنډ st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#د_که_پای

#إذا INTEGRAL_MAX_بټونه >= 64
  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بینښه لنډ st_ډېرپېښ;
    لنډ st_nlink;
    لنډ st_uid;
    لنډ st_gid;
    _dev_t st_rdev;
    __int64 st_اندازه;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بینښه لنډ st_ډېرپېښ;
    لنډ st_nlink;
    لنډ st_uid;
    لنډ st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بینښه لنډ st_ډېرپېښ;
    لنډ st_nlink;
    لنډ st_uid;
    لنډ st_gid;
    _dev_t st_rdev;
    __int64 st_اندازه;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#د_که_پای

#تعریف_کړه __stat64 _stat64

#تعریف_کړه _STAT_DEFINED
#د_که_پای

#تعریف_کړه _S_IFMT 0xF000
#تعریف_کړه _S_IFDIR 0x4000
#تعریف_کړه _S_IFCHR 0x2000
#تعریف_کړه _S_IFIFO 0x1000
#تعریف_کړه _S_IFREG 0x8000
#تعریف_کړه _S_IREAD 0x0100
#تعریف_کړه _S_IWRITE 0x0080
#تعریف_کړه _S_IEXEC 0x0040

  _CRTIMP صحيح __cdecl _fstat32(صحيح _FileDes,بنية _stat32 *_Stat);
  _CRTIMP صحيح __cdecl _stat32(ثابت حرف *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP صحيح __cdecl _fstat64(صحيح _FileDes,بنية _stat64 *_Stat);
  _CRTIMP صحيح __cdecl _fstat32i64(صحيح _FileDes,بنية _stat32i64 *_Stat);
  صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat);
  __CRT_INLINE صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat)
  {
    بنية _stat64 st;
    صحيح ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_ډېرپېښ=st.st_ډېرپېښ;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_اندازه=(_off_t) st.st_اندازه;
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
    _Stat->st_ډېرپېښ=st.st_ډېرپېښ;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_اندازه=(_off_t) st.st_اندازه;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    أرجع ret;
  }
#د_که_پای

#که_نه_تعریف_شوی _WSTAT_DEFINED
#تعریف_کړه _WSTAT_DEFINED
  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
#تعریف_کړه	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#تعریف_کړه S_IFMT _S_IFMT
#تعریف_کړه S_IFDIR _S_IFDIR
#تعریف_کړه S_IFCHR _S_IFCHR
#تعریف_کړه S_IFREG _S_IFREG
#تعریف_کړه S_IREAD _S_IREAD
#تعریف_کړه S_IWRITE _S_IWRITE
#تعریف_کړه S_IEXEC _S_IEXEC
#تعریف_کړه	S_IFIFO		_S_IFIFO
#تعریف_کړه	S_IFBLK		_S_IFBLK

#تعریف_کړه	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#تعریف_کړه	_S_IXUSR	_S_IEXEC
#تعریف_کړه	_S_IWUSR	_S_IWRITE

#تعریف_کړه	S_IRWXU		_S_IRWXU
#تعریف_کړه	S_IXUSR		_S_IXUSR
#تعریف_کړه	S_IWUSR		_S_IWUSR
#تعریف_کړه	S_IRUSR		_S_IRUSR
#تعریف_کړه	_S_IRUSR	_S_IREAD

#تعریف_کړه	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#تعریف_کړه	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#تعریف_کړه	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#تعریف_کړه	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#تعریف_کړه	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#د_که_پای

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
صحيح __cdecl stat(ثابت حرف *_Filename,بنية stat *_Stat);
صحيح __cdecl fstat(صحيح _Desc,بنية stat *_Stat);
صحيح __cdecl wstat(ثابت wchar_t *_Filename,بنية stat *_Stat);
#که_تعریف_شوی USE_32_بټ_وخت_T
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
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
