/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_STAT
#परिभाषय _INC_STAT

#यदि_अपरिभाषितम् _WIN32
#दोषः Only Win32 target is supported!
#यदि_अन्तः

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _CRTIMP
#परिभाषय _CRTIMP __declspec(dllimport)
#यदि_अन्तः

#अन्तर्भाव <sys/types.h>

#यदि_अपरिभाषितम् __TINYC__ /* gr */
#यदि_परिभाषितम् _USE_32BIT_TIME_T
#यदि_परिभाषितम् _WIN64
#अपरिभाषय _USE_32BIT_TIME_T
#यदि_अन्तः
#अन्यथा
#यदि INTEGRAL_MAX_द्वयङ्काः < 64
#परिभाषय _USE_32BIT_TIME_T
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME32_T_DEFINED
  प्रकारनिर्देश दीर्घ __time32_t;
#परिभाषय _TIME32_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME64_T_DEFINED
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  प्रकारनिर्देश __int64 __time64_t;
#यदि_अन्तः
#परिभाषय _TIME64_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _TIME_T_DEFINED
#यदि_परिभाषितम् _USE_32BIT_TIME_T
  प्रकारनिर्देश __time32_t time_t;
#अन्यथा
  प्रकारनिर्देश __time64_t time_t;
#यदि_अन्तः
#परिभाषय _TIME_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCHAR_T_DEFINED
  प्रकारनिर्देश अचिह्नित ह्रस्व wchar_t;
#परिभाषय _WCHAR_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _STAT_DEFINED

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#यदि_अपरिभाषितम् _WIN64
#परिभाषय _fstat32 _fstat
#परिभाषय _stat32 _stat
#परिभाषय _wstat32 _wstat
#अन्यथा
#परिभाषय _fstat _fstat32
#परिभाषय _stat _stat32
#परिभाषय _wstat _wstat32
#यदि_अन्तः
#परिभाषय _fstati64 _fstat32i64
#परिभाषय _stati64 _stat32i64
#परिभाषय _wstati64 _wstat32i64
#अन्यथा
#परिभाषय _fstat _fstat64i32
#परिभाषय _fstati64 _fstat64
#परिभाषय _stat _stat64
#परिभाषय _stati64 _stat64
#परिभाषय _wstat _wstat64
#परिभाषय _wstati64 _wstat64
#यदि_अन्तः

  संरचना _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#यदि_अपरिभाषितम्	NO_OLDNAMES
  संरचना stat {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#यदि_अन्तः

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  संरचना _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  संरचना _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  संरचना _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिह्नित ह्रस्व st_बहुलकम्;
    ह्रस्व st_nlink;
    ह्रस्व st_uid;
    ह्रस्व st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#यदि_अन्तः

#परिभाषय __stat64 _stat64

#परिभाषय _STAT_DEFINED
#यदि_अन्तः

#परिभाषय _S_IFMT 0xF000
#परिभाषय _S_IFDIR 0x4000
#परिभाषय _S_IFCHR 0x2000
#परिभाषय _S_IFIFO 0x1000
#परिभाषय _S_IFREG 0x8000
#परिभाषय _S_IREAD 0x0100
#परिभाषय _S_IWRITE 0x0080
#परिभाषय _S_IEXEC 0x0040

  _CRTIMP पूर्णाङ्क __cdecl _fstat32(पूर्णाङ्क _FileDes,संरचना _stat32 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _stat32(ध्रुव वर्ण *_Name,संरचना _stat32 *_Stat);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP पूर्णाङ्क __cdecl _fstat64(पूर्णाङ्क _FileDes,संरचना _stat64 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _fstat32i64(पूर्णाङ्क _FileDes,संरचना _stat32i64 *_Stat);
  पूर्णाङ्क __cdecl _fstat64i32(पूर्णाङ्क _FileDes,संरचना _stat64i32 *_Stat);
  __CRT_INLINE पूर्णाङ्क __cdecl _fstat64i32(पूर्णाङ्क _FileDes,संरचना _stat64i32 *_Stat)
  {
    संरचना _stat64 st;
    पूर्णाङ्क ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_बहुलकम्=st.st_बहुलकम्;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_आकार=(_off_t) st.st_आकार;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    प्रत्यागम ret;
  }
  _CRTIMP पूर्णाङ्क __cdecl _stat64(ध्रुव वर्ण *_Name,संरचना _stat64 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _stat32i64(ध्रुव वर्ण *_Name,संरचना _stat32i64 *_Stat);
  पूर्णाङ्क __cdecl _stat64i32(ध्रुव वर्ण *_Name,संरचना _stat64i32 *_Stat);
  __CRT_INLINE पूर्णाङ्क __cdecl _stat64i32(ध्रुव वर्ण *_Name,संरचना _stat64i32 *_Stat)
  {
    संरचना _stat64 st;
    पूर्णाङ्क ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_बहुलकम्=st.st_बहुलकम्;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_आकार=(_off_t) st.st_आकार;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    प्रत्यागम ret;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् _WSTAT_DEFINED
#परिभाषय _WSTAT_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wstat32(ध्रुव wchar_t *_Name,संरचना _stat32 *_Stat);
#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP पूर्णाङ्क __cdecl _wstat32i64(ध्रुव wchar_t *_Name,संरचना _stat32i64 *_Stat);
  पूर्णाङ्क __cdecl _wstat64i32(ध्रुव wchar_t *_Name,संरचना _stat64i32 *_Stat);
  _CRTIMP पूर्णाङ्क __cdecl _wstat64(ध्रुव wchar_t *_Name,संरचना _stat64 *_Stat);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
#परिभाषय	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#परिभाषय S_IFMT _S_IFMT
#परिभाषय S_IFDIR _S_IFDIR
#परिभाषय S_IFCHR _S_IFCHR
#परिभाषय S_IFREG _S_IFREG
#परिभाषय S_IREAD _S_IREAD
#परिभाषय S_IWRITE _S_IWRITE
#परिभाषय S_IEXEC _S_IEXEC
#परिभाषय	S_IFIFO		_S_IFIFO
#परिभाषय	S_IFBLK		_S_IFBLK

#परिभाषय	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#परिभाषय	_S_IXUSR	_S_IEXEC
#परिभाषय	_S_IWUSR	_S_IWRITE

#परिभाषय	S_IRWXU		_S_IRWXU
#परिभाषय	S_IXUSR		_S_IXUSR
#परिभाषय	S_IWUSR		_S_IWUSR
#परिभाषय	S_IRUSR		_S_IRUSR
#परिभाषय	_S_IRUSR	_S_IREAD

#परिभाषय	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#परिभाषय	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#परिभाषय	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#परिभाषय	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#परिभाषय	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#यदि_अन्तः

#यदि !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
पूर्णाङ्क __cdecl stat(ध्रुव वर्ण *_Filename,संरचना stat *_Stat);
पूर्णाङ्क __cdecl fstat(पूर्णाङ्क _Desc,संरचना stat *_Stat);
पूर्णाङ्क __cdecl wstat(ध्रुव wchar_t *_Filename,संरचना stat *_Stat);
#यदि_परिभाषितम् _USE_32BIT_TIME_T
__CRT_INLINE पूर्णाङ्क __cdecl fstat(पूर्णाङ्क _Desc,संरचना stat *_Stat) {
  प्रत्यागम _fstat32(_Desc,(संरचना _stat32 *)_Stat);
}
__CRT_INLINE पूर्णाङ्क __cdecl stat(ध्रुव वर्ण *_Filename,संरचना stat *_Stat) {
  प्रत्यागम _stat32(_Filename,(संरचना _stat32 *)_Stat);
}
#अन्यथा
__CRT_INLINE पूर्णाङ्क __cdecl fstat(पूर्णाङ्क _Desc,संरचना stat *_Stat) {
  प्रत्यागम _fstat64i32(_Desc,(संरचना _stat64i32 *)_Stat);
}
__CRT_INLINE पूर्णाङ्क __cdecl stat(ध्रुव वर्ण *_Filename,संरचना stat *_Stat) {
  प्रत्यागम _stat64i32(_Filename,(संरचना _stat64i32 *)_Stat);
}
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
