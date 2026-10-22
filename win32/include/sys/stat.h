/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STAT
#నిర్వచించు _INC_STAT

#నిర్వచితం_కాకపోతే _WIN32
#దోషం Only Win32 లక్ష్యం is supported!
#అయితే_ముగింపు

#అన్తర్భావ <_mingw.h>
#అన్తర్భావ <io.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CRTIMP
#నిర్వచించు _CRTIMP __declspec(dllimport)
#అయితే_ముగింపు

#అన్తర్భావ <sys/types.h>

#నిర్వచితం_కాకపోతే __TINYC__ /* gr */
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచితమైతే _WIN64
#నిర్వచనం_రద్దు USE_32_బిట్టు_సమయం_T
#అయితే_ముగింపు
#లేకపోతే
#ఒకవేళ INTEGRAL_MAX_బిట్లు < 64
#నిర్వచించు USE_32_బిట్టు_సమయం_T
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME32_T_DEFINED
  రకనిర్వచనం దీర్ఘ __time32_t;
#నిర్వచించు _TIME32_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TIME64_T_DEFINED
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  రకనిర్వచనం __int64 __time64_t;
#అయితే_ముగింపు
#నిర్వచించు _TIME64_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే సమయం_T_DEFINED
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
  రకనిర్వచనం __time32_t time_t;
#లేకపోతే
  రకనిర్వచనం __time64_t time_t;
#అయితే_ముగింపు
#నిర్వచించు సమయం_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCHAR_T_DEFINED
  రకనిర్వచనం గుర్తులేని పొట్టి wchar_t;
#నిర్వచించు _WCHAR_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STAT_DEFINED

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచితం_కాకపోతే _WIN64
#నిర్వచించు _fstat32 _fstat
#నిర్వచించు _stat32 _stat
#నిర్వచించు _wstat32 _wstat
#లేకపోతే
#నిర్వచించు _fstat _fstat32
#నిర్వచించు _stat _stat32
#నిర్వచించు _wstat _wstat32
#అయితే_ముగింపు
#నిర్వచించు _fstati64 _fstat32i64
#నిర్వచించు _stati64 _stat32i64
#నిర్వచించు _wstati64 _wstat32i64
#లేకపోతే
#నిర్వచించు _fstat _fstat64i32
#నిర్వచించు _fstati64 _fstat64
#నిర్వచించు _stat _stat64
#నిర్వచించు _stati64 _stat64
#నిర్వచించు _wstat _wstat64
#నిర్వచించు _wstati64 _wstat64
#అయితే_ముగింపు

  నిర్మాణం _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    _off_t st_కొలత;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  నిర్మాణం stat {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    _off_t st_కొలత;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#అయితే_ముగింపు

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  నిర్మాణం _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    __int64 st_కొలత;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  నిర్మాణం _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    _off_t st_కొలత;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  నిర్మాణం _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    గుర్తులేని పొట్టి st_బహుళకం;
    పొట్టి st_nlink;
    పొట్టి st_uid;
    పొట్టి st_gid;
    _dev_t st_rdev;
    __int64 st_కొలత;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#అయితే_ముగింపు

#నిర్వచించు __stat64 _stat64

#నిర్వచించు _STAT_DEFINED
#అయితే_ముగింపు

#నిర్వచించు _S_IFMT 0xF000
#నిర్వచించు _S_IFDIR 0x4000
#నిర్వచించు _S_IFCHR 0x2000
#నిర్వచించు _S_IFIFO 0x1000
#నిర్వచించు _S_IFREG 0x8000
#నిర్వచించు _S_IREAD 0x0100
#నిర్వచించు _S_IWRITE 0x0080
#నిర్వచించు _S_IEXEC 0x0040

  _CRTIMP పూర్ణాంకం __cdecl _fstat32(పూర్ణాంకం _FileDes,నిర్మాణం _stat32 *_Stat);
  _CRTIMP పూర్ణాంకం __cdecl _stat32(స్థిరరాశి అక్షరం *_Name,నిర్మాణం _stat32 *_Stat);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP పూర్ణాంకం __cdecl _fstat64(పూర్ణాంకం _FileDes,నిర్మాణం _stat64 *_Stat);
  _CRTIMP పూర్ణాంకం __cdecl _fstat32i64(పూర్ణాంకం _FileDes,నిర్మాణం _stat32i64 *_Stat);
  పూర్ణాంకం __cdecl _fstat64i32(పూర్ణాంకం _FileDes,నిర్మాణం _stat64i32 *_Stat);
  __CRT_INLINE పూర్ణాంకం __cdecl _fstat64i32(పూర్ణాంకం _FileDes,నిర్మాణం _stat64i32 *_Stat)
  {
    నిర్మాణం _stat64 st;
    పూర్ణాంకం ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_బహుళకం=st.st_బహుళకం;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_కొలత=(_off_t) st.st_కొలత;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    తిరిగి ret;
  }
  _CRTIMP పూర్ణాంకం __cdecl _stat64(స్థిరరాశి అక్షరం *_Name,నిర్మాణం _stat64 *_Stat);
  _CRTIMP పూర్ణాంకం __cdecl _stat32i64(స్థిరరాశి అక్షరం *_Name,నిర్మాణం _stat32i64 *_Stat);
  పూర్ణాంకం __cdecl _stat64i32(స్థిరరాశి అక్షరం *_Name,నిర్మాణం _stat64i32 *_Stat);
  __CRT_INLINE పూర్ణాంకం __cdecl _stat64i32(స్థిరరాశి అక్షరం *_Name,నిర్మాణం _stat64i32 *_Stat)
  {
    నిర్మాణం _stat64 st;
    పూర్ణాంకం ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_బహుళకం=st.st_బహుళకం;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_కొలత=(_off_t) st.st_కొలత;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    తిరిగి ret;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WSTAT_DEFINED
#నిర్వచించు _WSTAT_DEFINED
  _CRTIMP పూర్ణాంకం __cdecl _wstat32(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat32 *_Stat);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP పూర్ణాంకం __cdecl _wstat32i64(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat32i64 *_Stat);
  పూర్ణాంకం __cdecl _wstat64i32(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat64i32 *_Stat);
  _CRTIMP పూర్ణాంకం __cdecl _wstat64(స్థిరరాశి wchar_t *_Name,నిర్మాణం _stat64 *_Stat);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచించు	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#నిర్వచించు S_IFMT _S_IFMT
#నిర్వచించు S_IFDIR _S_IFDIR
#నిర్వచించు S_IFCHR _S_IFCHR
#నిర్వచించు S_IFREG _S_IFREG
#నిర్వచించు S_IREAD _S_IREAD
#నిర్వచించు S_IWRITE _S_IWRITE
#నిర్వచించు S_IEXEC _S_IEXEC
#నిర్వచించు	S_IFIFO		_S_IFIFO
#నిర్వచించు	S_IFBLK		_S_IFBLK

#నిర్వచించు	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#నిర్వచించు	_S_IXUSR	_S_IEXEC
#నిర్వచించు	_S_IWUSR	_S_IWRITE

#నిర్వచించు	S_IRWXU		_S_IRWXU
#నిర్వచించు	S_IXUSR		_S_IXUSR
#నిర్వచించు	S_IWUSR		_S_IWUSR
#నిర్వచించు	S_IRUSR		_S_IRUSR
#నిర్వచించు	_S_IRUSR	_S_IREAD

#నిర్వచించు	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#నిర్వచించు	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#నిర్వచించు	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#నిర్వచించు	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#నిర్వచించు	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#అయితే_ముగింపు

#ఒకవేళ !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
పూర్ణాంకం __cdecl stat(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం stat *_Stat);
పూర్ణాంకం __cdecl fstat(పూర్ణాంకం _Desc,నిర్మాణం stat *_Stat);
పూర్ణాంకం __cdecl wstat(స్థిరరాశి wchar_t *_Filename,నిర్మాణం stat *_Stat);
#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
__CRT_INLINE పూర్ణాంకం __cdecl fstat(పూర్ణాంకం _Desc,నిర్మాణం stat *_Stat) {
  తిరిగి _fstat32(_Desc,(నిర్మాణం _stat32 *)_Stat);
}
__CRT_INLINE పూర్ణాంకం __cdecl stat(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం stat *_Stat) {
  తిరిగి _stat32(_Filename,(నిర్మాణం _stat32 *)_Stat);
}
#లేకపోతే
__CRT_INLINE పూర్ణాంకం __cdecl fstat(పూర్ణాంకం _Desc,నిర్మాణం stat *_Stat) {
  తిరిగి _fstat64i32(_Desc,(నిర్మాణం _stat64i32 *)_Stat);
}
__CRT_INLINE పూర్ణాంకం __cdecl stat(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం stat *_Stat) {
  తిరిగి _stat64i32(_Filename,(నిర్మాణం _stat64i32 *)_Stat);
}
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
