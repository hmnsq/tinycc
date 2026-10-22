/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_STAT
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_STAT

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ದೋಷ Only Win32 ಗುರಿ is supported!
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <io.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRTIMP
#ವ್ಯಾಖ್ಯಾನಿಸು _CRTIMP __declspec(dllimport)
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <sys/types.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __TINYC__ /* gr */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು < 64
#ವ್ಯಾಖ್ಯಾನಿಸು USE_32_ಬಿಟ್_ಸಮಯ_T
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME32_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ __time32_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME32_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIME64_T_DEFINED
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 __time64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _TIME64_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಸಮಯ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time32_t time_t;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __time64_t time_t;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCHAR_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wchar_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _WCHAR_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STAT_DEFINED

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು _fstat32 _fstat
#ವ್ಯಾಖ್ಯಾನಿಸು _stat32 _stat
#ವ್ಯಾಖ್ಯಾನಿಸು _wstat32 _wstat
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _fstat _fstat32
#ವ್ಯಾಖ್ಯಾನಿಸು _stat _stat32
#ವ್ಯಾಖ್ಯಾನಿಸು _wstat _wstat32
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _fstati64 _fstat32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _stati64 _stat32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _wstati64 _wstat32i64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _fstat _fstat64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _fstati64 _fstat64
#ವ್ಯಾಖ್ಯಾನಿಸು _stat _stat64
#ವ್ಯಾಖ್ಯಾನಿಸು _stati64 _stat64
#ವ್ಯಾಖ್ಯಾನಿಸು _wstat _wstat64
#ವ್ಯಾಖ್ಯಾನಿಸು _wstati64 _wstat64
#ಆದರೆ_ಅಂತ್ಯ

  ರಚನೆ _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    _off_t st_ಗಾತ್ರ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ರಚನೆ stat {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    _off_t st_ಗಾತ್ರ;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ರಚನೆ _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    __int64 st_ಗಾತ್ರ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ರಚನೆ _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    _off_t st_ಗಾತ್ರ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ರಚನೆ _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ st_ಬಹುಲಕ;
    ಗಿಡ್ಡ st_nlink;
    ಗಿಡ್ಡ st_uid;
    ಗಿಡ್ಡ st_gid;
    _dev_t st_rdev;
    __int64 st_ಗಾತ್ರ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು __stat64 _stat64

#ವ್ಯಾಖ್ಯಾನಿಸು _STAT_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _S_IFMT 0xF000
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IFDIR 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IFCHR 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IFIFO 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IFREG 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IREAD 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IWRITE 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು _S_IEXEC 0x0040

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fstat32(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ _stat32 *_Stat);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _stat32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Name,ರಚನೆ _stat32 *_Stat);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fstat64(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ _stat64 *_Stat);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fstat32i64(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ _stat32i64 *_Stat);
  ಪೂರ್ಣಾಂಕ __cdecl _fstat64i32(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ _stat64i32 *_Stat);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _fstat64i32(ಪೂರ್ಣಾಂಕ _FileDes,ರಚನೆ _stat64i32 *_Stat)
  {
    ರಚನೆ _stat64 st;
    ಪೂರ್ಣಾಂಕ ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_ಬಹುಲಕ=st.st_ಬಹುಲಕ;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_ಗಾತ್ರ=(_off_t) st.st_ಗಾತ್ರ;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    ಹಿಂತಿರುಗಿ ret;
  }
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _stat64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Name,ರಚನೆ _stat64 *_Stat);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _stat32i64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Name,ರಚನೆ _stat32i64 *_Stat);
  ಪೂರ್ಣಾಂಕ __cdecl _stat64i32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Name,ರಚನೆ _stat64i32 *_Stat);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _stat64i32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Name,ರಚನೆ _stat64i32 *_Stat)
  {
    ರಚನೆ _stat64 st;
    ಪೂರ್ಣಾಂಕ ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_ಬಹುಲಕ=st.st_ಬಹುಲಕ;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_ಗಾತ್ರ=(_off_t) st.st_ಗಾತ್ರ;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    ಹಿಂತಿರುಗಿ ret;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTAT_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WSTAT_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wstat32(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat32 *_Stat);
#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wstat32i64(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat32i64 *_Stat);
  ಪೂರ್ಣಾಂಕ __cdecl _wstat64i32(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat64i32 *_Stat);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wstat64(ಸ್ಥಿರಾಂಕ wchar_t *_Name,ರಚನೆ _stat64 *_Stat);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿಸು	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#ವ್ಯಾಖ್ಯಾನಿಸು S_IFMT _S_IFMT
#ವ್ಯಾಖ್ಯಾನಿಸು S_IFDIR _S_IFDIR
#ವ್ಯಾಖ್ಯಾನಿಸು S_IFCHR _S_IFCHR
#ವ್ಯಾಖ್ಯಾನಿಸು S_IFREG _S_IFREG
#ವ್ಯಾಖ್ಯಾನಿಸು S_IREAD _S_IREAD
#ವ್ಯಾಖ್ಯಾನಿಸು S_IWRITE _S_IWRITE
#ವ್ಯಾಖ್ಯಾನಿಸು S_IEXEC _S_IEXEC
#ವ್ಯಾಖ್ಯಾನಿಸು	S_IFIFO		_S_IFIFO
#ವ್ಯಾಖ್ಯಾನಿಸು	S_IFBLK		_S_IFBLK

#ವ್ಯಾಖ್ಯಾನಿಸು	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#ವ್ಯಾಖ್ಯಾನಿಸು	_S_IXUSR	_S_IEXEC
#ವ್ಯಾಖ್ಯಾನಿಸು	_S_IWUSR	_S_IWRITE

#ವ್ಯಾಖ್ಯಾನಿಸು	S_IRWXU		_S_IRWXU
#ವ್ಯಾಖ್ಯಾನಿಸು	S_IXUSR		_S_IXUSR
#ವ್ಯಾಖ್ಯಾನಿಸು	S_IWUSR		_S_IWUSR
#ವ್ಯಾಖ್ಯಾನಿಸು	S_IRUSR		_S_IRUSR
#ವ್ಯಾಖ್ಯಾನಿಸು	_S_IRUSR	_S_IREAD

#ವ್ಯಾಖ್ಯಾನಿಸು	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#ವ್ಯಾಖ್ಯಾನಿಸು	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#ವ್ಯಾಖ್ಯಾನಿಸು	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#ವ್ಯಾಖ್ಯಾನಿಸು	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#ವ್ಯಾಖ್ಯಾನಿಸು	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
ಪೂರ್ಣಾಂಕ __cdecl stat(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ stat *_Stat);
ಪೂರ್ಣಾಂಕ __cdecl fstat(ಪೂರ್ಣಾಂಕ _Desc,ರಚನೆ stat *_Stat);
ಪೂರ್ಣಾಂಕ __cdecl wstat(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ stat *_Stat);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl fstat(ಪೂರ್ಣಾಂಕ _Desc,ರಚನೆ stat *_Stat) {
  ಹಿಂತಿರುಗಿ _fstat32(_Desc,(ರಚನೆ _stat32 *)_Stat);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl stat(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ stat *_Stat) {
  ಹಿಂತಿರುಗಿ _stat32(_Filename,(ರಚನೆ _stat32 *)_Stat);
}
#ಇಲ್ಲದಿದ್ದರೆ
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl fstat(ಪೂರ್ಣಾಂಕ _Desc,ರಚನೆ stat *_Stat) {
  ಹಿಂತಿರುಗಿ _fstat64i32(_Desc,(ರಚನೆ _stat64i32 *)_Stat);
}
__CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl stat(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ stat *_Stat) {
  ಹಿಂತಿರುಗಿ _stat64i32(_Filename,(ರಚನೆ _stat64i32 *)_Stat);
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
