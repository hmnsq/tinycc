/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_STAT
#تعریف_کرو _INC_STAT

#جے_بنا_تعریف _WIN32
#غلطی Only Win32 نشانہ is supported!
#جے_انت

#ضمن <_mingw.h>
#ضمن <io.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#جے_انت

#ضمن <sys/types.h>

#جے_بنا_تعریف __TINYC__ /* gr */
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#جے_تعریف_شدہ _WIN64
#تعریف_رد USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#وإلا
#إذا INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_ویلا_T
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _TIME32_T_DEFINED
  تعريفنوع لما __time32_t;
#تعریف_کرو _TIME32_T_DEFINED
#جے_انت

#جے_بنا_تعریف _TIME64_T_DEFINED
#إذا INTEGRAL_MAX_بٹ >= 64
  تعريفنوع __int64 __time64_t;
#جے_انت
#تعریف_کرو _TIME64_T_DEFINED
#جے_انت

#جے_بنا_تعریف ویلا_T_DEFINED
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
  تعريفنوع __time32_t time_t;
#وإلا
  تعريفنوع __time64_t time_t;
#جے_انت
#تعریف_کرو ویلا_T_DEFINED
#جے_انت

#جے_بنا_تعریف _WCHAR_T_DEFINED
  تعريفنوع بنانشانی چھوٹا wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#جے_انت

#جے_بنا_تعریف _STAT_DEFINED

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#جے_بنا_تعریف _WIN64
#تعریف_کرو _fstat32 _fstat
#تعریف_کرو _stat32 _stat
#تعریف_کرو _wstat32 _wstat
#وإلا
#تعریف_کرو _fstat _fstat32
#تعریف_کرو _stat _stat32
#تعریف_کرو _wstat _wstat32
#جے_انت
#تعریف_کرو _fstati64 _fstat32i64
#تعریف_کرو _stati64 _stat32i64
#تعریف_کرو _wstati64 _wstat32i64
#وإلا
#تعریف_کرو _fstat _fstat64i32
#تعریف_کرو _fstati64 _fstat64
#تعریف_کرو _stat _stat64
#تعریف_کرو _stati64 _stat64
#تعریف_کرو _wstat _wstat64
#تعریف_کرو _wstati64 _wstat64
#جے_انت

  بنية _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    _off_t st_ناپ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#جے_بنا_تعریف	NO_OLDNAMES
  بنية stat {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    _off_t st_ناپ;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#جے_انت

#إذا INTEGRAL_MAX_بٹ >= 64
  بنية _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    __int64 st_ناپ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  بنية _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    _off_t st_ناپ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  بنية _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    بنانشانی چھوٹا st_منوال;
    چھوٹا st_nlink;
    چھوٹا st_uid;
    چھوٹا st_gid;
    _dev_t st_rdev;
    __int64 st_ناپ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#جے_انت

#تعریف_کرو __stat64 _stat64

#تعریف_کرو _STAT_DEFINED
#جے_انت

#تعریف_کرو _S_IFMT 0xF000
#تعریف_کرو _S_IFDIR 0x4000
#تعریف_کرو _S_IFCHR 0x2000
#تعریف_کرو _S_IFIFO 0x1000
#تعریف_کرو _S_IFREG 0x8000
#تعریف_کرو _S_IREAD 0x0100
#تعریف_کرو _S_IWRITE 0x0080
#تعریف_کرو _S_IEXEC 0x0040

  _CRTIMP صحيح __cdecl _fstat32(صحيح _FileDes,بنية _stat32 *_Stat);
  _CRTIMP صحيح __cdecl _stat32(ثابت حرف *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحيح __cdecl _fstat64(صحيح _FileDes,بنية _stat64 *_Stat);
  _CRTIMP صحيح __cdecl _fstat32i64(صحيح _FileDes,بنية _stat32i64 *_Stat);
  صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat);
  __CRT_INLINE صحيح __cdecl _fstat64i32(صحيح _FileDes,بنية _stat64i32 *_Stat)
  {
    بنية _stat64 st;
    صحيح ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_منوال=st.st_منوال;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_ناپ=(_off_t) st.st_ناپ;
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
    _Stat->st_منوال=st.st_منوال;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_ناپ=(_off_t) st.st_ناپ;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    أرجع ret;
  }
#جے_انت

#جے_بنا_تعریف _WSTAT_DEFINED
#تعریف_کرو _WSTAT_DEFINED
  _CRTIMP صحيح __cdecl _wstat32(ثابت wchar_t *_Name,بنية _stat32 *_Stat);
#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحيح __cdecl _wstat32i64(ثابت wchar_t *_Name,بنية _stat32i64 *_Stat);
  صحيح __cdecl _wstat64i32(ثابت wchar_t *_Name,بنية _stat64i32 *_Stat);
  _CRTIMP صحيح __cdecl _wstat64(ثابت wchar_t *_Name,بنية _stat64 *_Stat);
#جے_انت
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
#تعریف_کرو	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#تعریف_کرو S_IFMT _S_IFMT
#تعریف_کرو S_IFDIR _S_IFDIR
#تعریف_کرو S_IFCHR _S_IFCHR
#تعریف_کرو S_IFREG _S_IFREG
#تعریف_کرو S_IREAD _S_IREAD
#تعریف_کرو S_IWRITE _S_IWRITE
#تعریف_کرو S_IEXEC _S_IEXEC
#تعریف_کرو	S_IFIFO		_S_IFIFO
#تعریف_کرو	S_IFBLK		_S_IFBLK

#تعریف_کرو	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#تعریف_کرو	_S_IXUSR	_S_IEXEC
#تعریف_کرو	_S_IWUSR	_S_IWRITE

#تعریف_کرو	S_IRWXU		_S_IRWXU
#تعریف_کرو	S_IXUSR		_S_IXUSR
#تعریف_کرو	S_IWUSR		_S_IWUSR
#تعریف_کرو	S_IRUSR		_S_IRUSR
#تعریف_کرو	_S_IRUSR	_S_IREAD

#تعریف_کرو	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#تعریف_کرو	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#تعریف_کرو	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#تعریف_کرو	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#تعریف_کرو	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#جے_انت

#إذا !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
صحيح __cdecl stat(ثابت حرف *_Filename,بنية stat *_Stat);
صحيح __cdecl fstat(صحيح _Desc,بنية stat *_Stat);
صحيح __cdecl wstat(ثابت wchar_t *_Filename,بنية stat *_Stat);
#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
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
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)
#جے_انت
