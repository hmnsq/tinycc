/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_STAT
#تعریف_کن _INC_STAT

#اگر_تعریف_نشده _WIN32
#خطا Only Win32 هدف is supported!
#پایان_اگر

#ضمن <_mingw.h>
#ضمن <io.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _CRTIMP
#تعریف_کن _CRTIMP __declspec(dllimport)
#پایان_اگر

#ضمن <sys/types.h>

#اگر_تعریف_نشده __TINYC__ /* gr */
#اگر_تعریف_شده USE_32_بیت_زمان_T
#اگر_تعریف_شده _WIN64
#لغو_تعریف USE_32_بیت_زمان_T
#پایان_اگر
#وإلا
#إذا INTEGRAL_MAX_بیتها < 64
#تعریف_کن USE_32_بیت_زمان_T
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _TIME32_T_DEFINED
  تعريفنوع دراز __time32_t;
#تعریف_کن _TIME32_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بیتها >= 64
  تعريفنوع __int64 __time64_t;
#پایان_اگر
#تعریف_کن _TIME64_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده زمان_T_DEFINED
#اگر_تعریف_شده USE_32_بیت_زمان_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#پایان_اگر
#تعریف_کن زمان_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _WCHAR_T_DEFINED
  تعريفنوع بیعلامت کوتاه wchar_t;
#تعریف_کن _WCHAR_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _STAT_DEFINED

#اگر_تعریف_شده USE_32_بیت_زمان_T
#اگر_تعریف_نشده _WIN64
#تعریف_کن _fstat32 _fstat
#تعریف_کن _stat32 _stat
#تعریف_کن _wstat32 _wstat
#وإلا
#تعریف_کن _fstat _fstat32
#تعریف_کن _stat _stat32
#تعریف_کن _wstat _wstat32
#پایان_اگر
#تعریف_کن _fstati64 _fstat32i64
#تعریف_کن _stati64 _stat32i64
#تعریف_کن _wstati64 _wstat32i64
#وإلا
#تعریف_کن _fstat _fstat64i32
#تعریف_کن _fstati64 _fstat64
#تعریف_کن _stat _stat64
#تعریف_کن _stati64 _stat64
#تعریف_کن _wstat _wstat64
#تعریف_کن _wstati64 _wstat64
#پایان_اگر

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#اگر_تعریف_نشده	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#پایان_اگر

#إذا INTEGRAL_MAX_بیتها >= 64
  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    __int64 st_اندازه;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    _off_t st_اندازه;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بیعلامت کوتاه st_نما;
    کوتاه st_nlink;
    کوتاه st_uid;
    کوتاه st_gid;
    _dev_t st_rdev;
    __int64 st_اندازه;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#پایان_اگر

#تعریف_کن __stat64 _stat64

#تعریف_کن _STAT_DEFINED
#پایان_اگر

#تعریف_کن _S_IFMT 0xF000
#تعریف_کن _S_IFDIR 0x4000
#تعریف_کن _S_IFCHR 0x2000
#تعریف_کن _S_IFIFO 0x1000
#تعریف_کن _S_IFREG 0x8000
#تعریف_کن _S_IREAD 0x0100
#تعریف_کن _S_IWRITE 0x0080
#تعریف_کن _S_IEXEC 0x0040

  _CRTIMP صحيح __cdecl _fstat32(صحيح _FileDes,بنية _stat32 *_Stat);
  _CRTIMP صحيح __cdecl _stat32(ثابت حرف *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP صحيح __cdecl _fstat64(صحيح _FileDes,بنية _stat64 *_Stat);
  _CRTIMP صحيح __cdecl _fstat32i64(صحيح _FileDes,بنية _stat32i64 *_Stat);
  صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat);
  __CRT_INLINE صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat)
  {
    بنية _stat64 st;
    صحيح ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_نما=st.st_نما;
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
    _Stat->st_نما=st.st_نما;
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
#پایان_اگر

#اگر_تعریف_نشده _WSTAT_DEFINED
#تعریف_کن _WSTAT_DEFINED
  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
#تعریف_کن	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#تعریف_کن S_IFMT _S_IFMT
#تعریف_کن S_IFDIR _S_IFDIR
#تعریف_کن S_IFCHR _S_IFCHR
#تعریف_کن S_IFREG _S_IFREG
#تعریف_کن S_IREAD _S_IREAD
#تعریف_کن S_IWRITE _S_IWRITE
#تعریف_کن S_IEXEC _S_IEXEC
#تعریف_کن	S_IFIFO		_S_IFIFO
#تعریف_کن	S_IFBLK		_S_IFBLK

#تعریف_کن	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#تعریف_کن	_S_IXUSR	_S_IEXEC
#تعریف_کن	_S_IWUSR	_S_IWRITE

#تعریف_کن	S_IRWXU		_S_IRWXU
#تعریف_کن	S_IXUSR		_S_IXUSR
#تعریف_کن	S_IWUSR		_S_IWUSR
#تعریف_کن	S_IRUSR		_S_IRUSR
#تعریف_کن	_S_IRUSR	_S_IREAD

#تعریف_کن	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#تعریف_کن	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#تعریف_کن	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#تعریف_کن	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#تعریف_کن	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#پایان_اگر

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
صحيح __cdecl stat(ثابت حرف *_Filename,بنية stat *_Stat);
صحيح __cdecl fstat(صحيح _Desc,بنية stat *_Stat);
صحيح __cdecl wstat(ثابت wchar_t *_Filename,بنية stat *_Stat);
#اگر_تعریف_شده USE_32_بیت_زمان_T
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
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
