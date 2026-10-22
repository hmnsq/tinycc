/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_STAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_STAT

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਗਲਤੀ Only Win32 ਨਿਸ਼ਾਨਾ is supported!
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <io.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRTIMP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRTIMP __declspec(dllimport)
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <sys/types.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __TINYC__ /* gr */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ < 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME32_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ __time32_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME32_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIME64_T_DEFINED
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 __time64_t;
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIME64_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time32_t time_t;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __time64_t time_t;
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCHAR_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wchar_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCHAR_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STAT_DEFINED

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstat32 _fstat
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stat32 _stat
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstat32 _wstat
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstat _fstat32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stat _stat32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstat _wstat32
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstati64 _fstat32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stati64 _stat32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstati64 _wstat32i64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstat _fstat64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fstati64 _fstat64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stat _stat64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _stati64 _stat64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstat _wstat64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wstati64 _wstat64
#ਜੇ_ਅੰਤ

  ਬਣਤਰ _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    _off_t st_ਮਾਪ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਬਣਤਰ stat {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    _off_t st_ਮਾਪ;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#ਜੇ_ਅੰਤ

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਬਣਤਰ _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    __int64 st_ਮਾਪ;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  ਬਣਤਰ _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    _off_t st_ਮਾਪ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  ਬਣਤਰ _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ st_ਬਹੁਲਕ;
    ਛੋਟਾ st_nlink;
    ਛੋਟਾ st_uid;
    ਛੋਟਾ st_gid;
    _dev_t st_rdev;
    __int64 st_ਮਾਪ;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __stat64 _stat64

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STAT_DEFINED
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IFMT 0xF000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IFDIR 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IFCHR 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IFIFO 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IFREG 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IREAD 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IWRITE 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S_IEXEC 0x0040

  _CRTIMP ਪੂਰਨ __cdecl _fstat32(ਪੂਰਨ _FileDes,ਬਣਤਰ _stat32 *_Stat);
  _CRTIMP ਪੂਰਨ __cdecl _stat32(ਅਚਲ ਅੱਖਰ *_Name,ਬਣਤਰ _stat32 *_Stat);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP ਪੂਰਨ __cdecl _fstat64(ਪੂਰਨ _FileDes,ਬਣਤਰ _stat64 *_Stat);
  _CRTIMP ਪੂਰਨ __cdecl _fstat32i64(ਪੂਰਨ _FileDes,ਬਣਤਰ _stat32i64 *_Stat);
  ਪੂਰਨ __cdecl _fstat64i32(ਪੂਰਨ _FileDes,ਬਣਤਰ _stat64i32 *_Stat);
  __CRT_INLINE ਪੂਰਨ __cdecl _fstat64i32(ਪੂਰਨ _FileDes,ਬਣਤਰ _stat64i32 *_Stat)
  {
    ਬਣਤਰ _stat64 st;
    ਪੂਰਨ ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_ਬਹੁਲਕ=st.st_ਬਹੁਲਕ;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_ਮਾਪ=(_off_t) st.st_ਮਾਪ;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    ਵਾਪਸ ret;
  }
  _CRTIMP ਪੂਰਨ __cdecl _stat64(ਅਚਲ ਅੱਖਰ *_Name,ਬਣਤਰ _stat64 *_Stat);
  _CRTIMP ਪੂਰਨ __cdecl _stat32i64(ਅਚਲ ਅੱਖਰ *_Name,ਬਣਤਰ _stat32i64 *_Stat);
  ਪੂਰਨ __cdecl _stat64i32(ਅਚਲ ਅੱਖਰ *_Name,ਬਣਤਰ _stat64i32 *_Stat);
  __CRT_INLINE ਪੂਰਨ __cdecl _stat64i32(ਅਚਲ ਅੱਖਰ *_Name,ਬਣਤਰ _stat64i32 *_Stat)
  {
    ਬਣਤਰ _stat64 st;
    ਪੂਰਨ ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_ਬਹੁਲਕ=st.st_ਬਹੁਲਕ;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_ਮਾਪ=(_off_t) st.st_ਮਾਪ;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    ਵਾਪਸ ret;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTAT_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTAT_DEFINED
  _CRTIMP ਪੂਰਨ __cdecl _wstat32(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat32 *_Stat);
#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP ਪੂਰਨ __cdecl _wstat32i64(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat32i64 *_Stat);
  ਪੂਰਨ __cdecl _wstat64i32(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat64i32 *_Stat);
  _CRTIMP ਪੂਰਨ __cdecl _wstat64(ਅਚਲ wchar_t *_Name,ਬਣਤਰ _stat64 *_Stat);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IFMT _S_IFMT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IFDIR _S_IFDIR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IFCHR _S_IFCHR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IFREG _S_IFREG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IREAD _S_IREAD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IWRITE _S_IWRITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_IEXEC _S_IEXEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_IFIFO		_S_IFIFO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_IFBLK		_S_IFBLK

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_S_IXUSR	_S_IEXEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_S_IWUSR	_S_IWRITE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_IRWXU		_S_IRWXU
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_IXUSR		_S_IXUSR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_IWUSR		_S_IWUSR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_IRUSR		_S_IRUSR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	_S_IRUSR	_S_IREAD

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#ਜੇ_ਅੰਤ

#ਜੇ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
ਪੂਰਨ __cdecl stat(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ stat *_Stat);
ਪੂਰਨ __cdecl fstat(ਪੂਰਨ _Desc,ਬਣਤਰ stat *_Stat);
ਪੂਰਨ __cdecl wstat(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ stat *_Stat);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
__CRT_INLINE ਪੂਰਨ __cdecl fstat(ਪੂਰਨ _Desc,ਬਣਤਰ stat *_Stat) {
  ਵਾਪਸ _fstat32(_Desc,(ਬਣਤਰ _stat32 *)_Stat);
}
__CRT_INLINE ਪੂਰਨ __cdecl stat(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ stat *_Stat) {
  ਵਾਪਸ _stat32(_Filename,(ਬਣਤਰ _stat32 *)_Stat);
}
#ਨਹੀਂਤਾਂ
__CRT_INLINE ਪੂਰਨ __cdecl fstat(ਪੂਰਨ _Desc,ਬਣਤਰ stat *_Stat) {
  ਵਾਪਸ _fstat64i32(_Desc,(ਬਣਤਰ _stat64i32 *)_Stat);
}
__CRT_INLINE ਪੂਰਨ __cdecl stat(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ stat *_Stat) {
  ਵਾਪਸ _stat64i32(_Filename,(ਬਣਤਰ _stat64i32 *)_Stat);
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
