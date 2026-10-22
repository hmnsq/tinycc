/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STAT
#تعریف_کرو _INC_STAT

#اگر_غیر_تعریف_شدہ _WIN32
#غلطی Only Win32 ہدف is supported!
#اگر_ختم

#شامل <_mingw.h>
#شامل <io.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _CRTIMP
#تعریف_کرو _CRTIMP __declspec(dllimport)
#اگر_ختم

#شامل <sys/types.h>

#اگر_غیر_تعریف_شدہ __TINYC__ /* gr */
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_تعریف_شدہ _WIN64
#تعریف_منسوخ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#ورنہ
#اگر INTEGRAL_MAX_بٹ < 64
#تعریف_کرو USE_32_ثنائی_ہندسہ_وقت_T
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME32_T_DEFINED
  قسمتعریف طویل __time32_t;
#تعریف_کرو _TIME32_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _TIME64_T_DEFINED
#اگر INTEGRAL_MAX_بٹ >= 64
  قسمتعریف __int64 __time64_t;
#اگر_ختم
#تعریف_کرو _TIME64_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ وقت_T_DEFINED
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
  قسمتعریف __time32_t time_t;
#ورنہ
  قسمتعریف __time64_t time_t;
#اگر_ختم
#تعریف_کرو وقت_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCHAR_T_DEFINED
  قسمتعریف غیرعلامتی مختصر wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STAT_DEFINED

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#اگر_غیر_تعریف_شدہ _WIN64
#تعریف_کرو _fstat32 _fstat
#تعریف_کرو _stat32 _stat
#تعریف_کرو _wstat32 _wstat
#ورنہ
#تعریف_کرو _fstat _fstat32
#تعریف_کرو _stat _stat32
#تعریف_کرو _wstat _wstat32
#اگر_ختم
#تعریف_کرو _fstati64 _fstat32i64
#تعریف_کرو _stati64 _stat32i64
#تعریف_کرو _wstati64 _wstat32i64
#ورنہ
#تعریف_کرو _fstat _fstat64i32
#تعریف_کرو _fstati64 _fstat64
#تعریف_کرو _stat _stat64
#تعریف_کرو _stati64 _stat64
#تعریف_کرو _wstat _wstat64
#تعریف_کرو _wstati64 _wstat64
#اگر_ختم

  ساخت _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    _off_t st_سائز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  ساخت stat {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    _off_t st_سائز;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#اگر_ختم

#اگر INTEGRAL_MAX_بٹ >= 64
  ساخت _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    __int64 st_سائز;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ساخت _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    _off_t st_سائز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ساخت _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    غیرعلامتی مختصر st_منوال;
    مختصر st_nlink;
    مختصر st_uid;
    مختصر st_gid;
    _dev_t st_rdev;
    __int64 st_سائز;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#اگر_ختم

#تعریف_کرو __stat64 _stat64

#تعریف_کرو _STAT_DEFINED
#اگر_ختم

#تعریف_کرو _S_IFMT 0xF000
#تعریف_کرو _S_IFDIR 0x4000
#تعریف_کرو _S_IFCHR 0x2000
#تعریف_کرو _S_IFIFO 0x1000
#تعریف_کرو _S_IFREG 0x8000
#تعریف_کرو _S_IREAD 0x0100
#تعریف_کرو _S_IWRITE 0x0080
#تعریف_کرو _S_IEXEC 0x0040

  _CRTIMP صحیح __cdecl _fstat32(صحیح _FileDes,ساخت _stat32 *_Stat);
  _CRTIMP صحیح __cdecl _stat32(ثابت حرف *_Name,ساخت _stat32 *_Stat);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحیح __cdecl _fstat64(صحیح _FileDes,ساخت _stat64 *_Stat);
  _CRTIMP صحیح __cdecl _fstat32i64(صحیح _FileDes,ساخت _stat32i64 *_Stat);
  صحیح __cdecl _fstat64i32(صحیح _FileDes,ساخت _stat64i32 *_Stat);
  __CRT_INLINE صحیح __cdecl _fstat64i32(صحیح _FileDes,ساخت _stat64i32 *_Stat)
  {
    ساخت _stat64 st;
    صحیح ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_منوال=st.st_منوال;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_سائز=(_off_t) st.st_سائز;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    واپس ret;
  }
  _CRTIMP صحیح __cdecl _stat64(ثابت حرف *_Name,ساخت _stat64 *_Stat);
  _CRTIMP صحیح __cdecl _stat32i64(ثابت حرف *_Name,ساخت _stat32i64 *_Stat);
  صحیح __cdecl _stat64i32(ثابت حرف *_Name,ساخت _stat64i32 *_Stat);
  __CRT_INLINE صحیح __cdecl _stat64i32(ثابت حرف *_Name,ساخت _stat64i32 *_Stat)
  {
    ساخت _stat64 st;
    صحیح ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_منوال=st.st_منوال;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_سائز=(_off_t) st.st_سائز;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    واپس ret;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WSTAT_DEFINED
#تعریف_کرو _WSTAT_DEFINED
  _CRTIMP صحیح __cdecl _wstat32(ثابت wchar_t *_Name,ساخت _stat32 *_Stat);
#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP صحیح __cdecl _wstat32i64(ثابت wchar_t *_Name,ساخت _stat32i64 *_Stat);
  صحیح __cdecl _wstat64i32(ثابت wchar_t *_Name,ساخت _stat64i32 *_Stat);
  _CRTIMP صحیح __cdecl _wstat64(ثابت wchar_t *_Name,ساخت _stat64 *_Stat);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
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

#اگر_ختم

#اگر !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
صحیح __cdecl stat(ثابت حرف *_Filename,ساخت stat *_Stat);
صحیح __cdecl fstat(صحیح _Desc,ساخت stat *_Stat);
صحیح __cdecl wstat(ثابت wchar_t *_Filename,ساخت stat *_Stat);
#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
__CRT_INLINE صحیح __cdecl fstat(صحیح _Desc,ساخت stat *_Stat) {
  واپس _fstat32(_Desc,(ساخت _stat32 *)_Stat);
}
__CRT_INLINE صحیح __cdecl stat(ثابت حرف *_Filename,ساخت stat *_Stat) {
  واپس _stat32(_Filename,(ساخت _stat32 *)_Stat);
}
#ورنہ
__CRT_INLINE صحیح __cdecl fstat(صحیح _Desc,ساخت stat *_Stat) {
  واپس _fstat64i32(_Desc,(ساخت _stat64i32 *)_Stat);
}
__CRT_INLINE صحیح __cdecl stat(ثابت حرف *_Filename,ساخت stat *_Stat) {
  واپس _stat64i32(_Filename,(ساخت _stat64i32 *)_Stat);
}
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
