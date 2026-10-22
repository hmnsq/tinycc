/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_STAT
#घोषणा _INC_STAT

#अगर_अघोषित _WIN32
#त्रुटि Only Win32 target is supported!
#पूर्ण_अगर

#समावेश <_mingw.h>
#समावेश <io.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _CRTIMP
#घोषणा _CRTIMP __declspec(dllimport)
#पूर्ण_अगर

#समावेश <sys/types.h>

#अगर_अघोषित __TINYC__ /* gr */
#अगर_घोषित _USE_32BIT_TIME_T
#अगर_घोषित _WIN64
#अघोषित _USE_32BIT_TIME_T
#पूर्ण_अगर
#अन्यथा
#अगर _INTEGRAL_MAX_BITS < 64
#घोषणा _USE_32BIT_TIME_T
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _TIME32_T_DEFINED
  प्रकार दीर्घ __time32_t;
#घोषणा _TIME32_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _TIME64_T_DEFINED
#अगर _INTEGRAL_MAX_BITS >= 64
  प्रकार __int64 __time64_t;
#पूर्ण_अगर
#घोषणा _TIME64_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _TIME_T_DEFINED
#अगर_घोषित _USE_32BIT_TIME_T
  प्रकार __time32_t समय_प्रकार;
#अन्यथा
  प्रकार __time64_t समय_प्रकार;
#पूर्ण_अगर
#घोषणा _TIME_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _WCHAR_T_DEFINED
  प्रकार अचिन्हित लघु ब_अक्षर_प्रकार;
#घोषणा _WCHAR_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _STAT_DEFINED

#अगर_घोषित _USE_32BIT_TIME_T
#अगर_अघोषित _WIN64
#घोषणा _fstat32 _fstat
#घोषणा _stat32 _stat
#घोषणा _wstat32 _wstat
#अन्यथा
#घोषणा _fstat _fstat32
#घोषणा _stat _stat32
#घोषणा _wstat _wstat32
#पूर्ण_अगर
#घोषणा _fstati64 _fstat32i64
#घोषणा _stati64 _stat32i64
#घोषणा _wstati64 _wstat32i64
#अन्यथा
#घोषणा _fstat _fstat64i32
#घोषणा _fstati64 _fstat64
#घोषणा _stat _stat64
#घोषणा _stati64 _stat64
#घोषणा _wstat _wstat64
#घोषणा _wstati64 _wstat64
#पूर्ण_अगर

  काष्ठा _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#अगर_अघोषित	NO_OLDNAMES
  काष्ठा stat {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    समय_प्रकार st_atime;
    समय_प्रकार st_mtime;
    समय_प्रकार st_ctime;
  };
#पूर्ण_अगर

#अगर _INTEGRAL_MAX_BITS >= 64
  काष्ठा _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  काष्ठा _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    _off_t st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  काष्ठा _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    अचिन्हित लघु st_mode;
    लघु st_nlink;
    लघु st_uid;
    लघु st_gid;
    _dev_t st_rdev;
    __int64 st_आकार;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#पूर्ण_अगर

#घोषणा __stat64 _stat64

#घोषणा _STAT_DEFINED
#पूर्ण_अगर

#घोषणा _S_IFMT 0xF000
#घोषणा _S_IFDIR 0x4000
#घोषणा _S_IFCHR 0x2000
#घोषणा _S_IFIFO 0x1000
#घोषणा _S_IFREG 0x8000
#घोषणा _S_IREAD 0x0100
#घोषणा _S_IWRITE 0x0080
#घोषणा _S_IEXEC 0x0040

  _CRTIMP पूर्णांक __cdecl _fstat32(पूर्णांक _FileDes,काष्ठा _stat32 *_Stat);
  _CRTIMP पूर्णांक __cdecl _stat32(स्थिर अक्षर *_Name,काष्ठा _stat32 *_Stat);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _fstat64(पूर्णांक _FileDes,काष्ठा _stat64 *_Stat);
  _CRTIMP पूर्णांक __cdecl _fstat32i64(पूर्णांक _FileDes,काष्ठा _stat32i64 *_Stat);
  पूर्णांक __cdecl _fstat64i32(पूर्णांक _FileDes,काष्ठा _stat64i32 *_Stat);
  __CRT_INLINE पूर्णांक __cdecl _fstat64i32(पूर्णांक _FileDes,काष्ठा _stat64i32 *_Stat)
  {
    काष्ठा _stat64 st;
    पूर्णांक ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_आकार=(_off_t) st.st_आकार;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    वापस ret;
  }
  _CRTIMP पूर्णांक __cdecl _stat64(स्थिर अक्षर *_Name,काष्ठा _stat64 *_Stat);
  _CRTIMP पूर्णांक __cdecl _stat32i64(स्थिर अक्षर *_Name,काष्ठा _stat32i64 *_Stat);
  पूर्णांक __cdecl _stat64i32(स्थिर अक्षर *_Name,काष्ठा _stat64i32 *_Stat);
  __CRT_INLINE पूर्णांक __cdecl _stat64i32(स्थिर अक्षर *_Name,काष्ठा _stat64i32 *_Stat)
  {
    काष्ठा _stat64 st;
    पूर्णांक ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_आकार=(_off_t) st.st_आकार;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    वापस ret;
  }
#पूर्ण_अगर

#अगर_अघोषित _WSTAT_DEFINED
#घोषणा _WSTAT_DEFINED
  _CRTIMP पूर्णांक __cdecl _wstat32(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat32 *_Stat);
#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP पूर्णांक __cdecl _wstat32i64(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat32i64 *_Stat);
  पूर्णांक __cdecl _wstat64i32(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat64i32 *_Stat);
  _CRTIMP पूर्णांक __cdecl _wstat64(स्थिर ब_अक्षर_प्रकार *_Name,काष्ठा _stat64 *_Stat);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
#घोषणा	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#घोषणा S_IFMT _S_IFMT
#घोषणा S_IFDIR _S_IFDIR
#घोषणा S_IFCHR _S_IFCHR
#घोषणा S_IFREG _S_IFREG
#घोषणा S_IREAD _S_IREAD
#घोषणा S_IWRITE _S_IWRITE
#घोषणा S_IEXEC _S_IEXEC
#घोषणा	S_IFIFO		_S_IFIFO
#घोषणा	S_IFBLK		_S_IFBLK

#घोषणा	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#घोषणा	_S_IXUSR	_S_IEXEC
#घोषणा	_S_IWUSR	_S_IWRITE

#घोषणा	S_IRWXU		_S_IRWXU
#घोषणा	S_IXUSR		_S_IXUSR
#घोषणा	S_IWUSR		_S_IWUSR
#घोषणा	S_IRUSR		_S_IRUSR
#घोषणा	_S_IRUSR	_S_IREAD

#घोषणा	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#घोषणा	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#घोषणा	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#घोषणा	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#घोषणा	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#पूर्ण_अगर

#अगर !defined (RC_INVOKED) && !defined (NO_OLDNAMES)
पूर्णांक __cdecl stat(स्थिर अक्षर *_Filename,काष्ठा stat *_Stat);
पूर्णांक __cdecl ख_स्थिति(पूर्णांक _Desc,काष्ठा stat *_Stat);
पूर्णांक __cdecl wstat(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा stat *_Stat);
#अगर_घोषित _USE_32BIT_TIME_T
__CRT_INLINE पूर्णांक __cdecl ख_स्थिति(पूर्णांक _Desc,काष्ठा stat *_Stat) {
  वापस _fstat32(_Desc,(काष्ठा _stat32 *)_Stat);
}
__CRT_INLINE पूर्णांक __cdecl stat(स्थिर अक्षर *_Filename,काष्ठा stat *_Stat) {
  वापस _stat32(_Filename,(काष्ठा _stat32 *)_Stat);
}
#अन्यथा
__CRT_INLINE पूर्णांक __cdecl ख_स्थिति(पूर्णांक _Desc,काष्ठा stat *_Stat) {
  वापस _fstat64i32(_Desc,(काष्ठा _stat64i32 *)_Stat);
}
__CRT_INLINE पूर्णांक __cdecl stat(स्थिर अक्षर *_Filename,काष्ठा stat *_Stat) {
  वापस _stat64i32(_Filename,(काष्ठा _stat64i32 *)_Stat);
}
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
