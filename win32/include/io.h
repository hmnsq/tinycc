
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _IO_H_
#घोषणा _IO_H_

#समावेश <_mingw.h>
#समावेश <string.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_अघोषित _POSIX_

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

_CRTIMP अक्षर* __cdecl _getcwd (अक्षर*, पूर्णांक);
#अगर_अघोषित _FSIZE_T_DEFINED
  प्रकार अचिन्हित दीर्घ _fsize_t;
#घोषणा _FSIZE_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _FINDDATA_T_DEFINED

  काष्ठा _finddata32_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t आकार;
    अक्षर name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  काष्ठा _finddata32i64_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 आकार;
    अक्षर name[260];
  };

  काष्ठा _finddata64i32_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t आकार;
    अक्षर name[260];
  };

  काष्ठा __finddata64_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 आकार;
    अक्षर name[260];
  };
/* #endif */

#अगर_घोषित _USE_32BIT_TIME_T
#घोषणा _finddata_t _finddata32_t
#घोषणा _finddatai64_t _finddata32i64_t

#अगर_घोषित _WIN64
#घोषणा _findfirst _findfirst32
#घोषणा _findnext _findnext32
#अन्यथा
#घोषणा _findfirst32 _findfirst
#घोषणा _findnext32 _findnext
#पूर्ण_अगर
#घोषणा _findfirsti64 _findfirst32i64
#घोषणा _findnexti64 _findnext32i64
#अन्यथा
#घोषणा _finddata_t _finddata64i32_t
#घोषणा _finddatai64_t __finddata64_t

#घोषणा _findfirst _findfirst64i32
#घोषणा _findnext _findnext64i32
#घोषणा _findfirsti64 _findfirst64
#घोषणा _findnexti64 _findnext64
#पूर्ण_अगर

#घोषणा _FINDDATA_T_DEFINED
#पूर्ण_अगर

#अगर_अघोषित _WFINDDATA_T_DEFINED

  काष्ठा _wfinddata32_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t आकार;
    ब_अक्षर_प्रकार name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  काष्ठा _wfinddata32i64_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 आकार;
    ब_अक्षर_प्रकार name[260];
  };

  काष्ठा _wfinddata64i32_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t आकार;
    ब_अक्षर_प्रकार name[260];
  };

  काष्ठा _wfinddata64_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 आकार;
    ब_अक्षर_प्रकार name[260];
  };
/* #endif */

#अगर_घोषित _USE_32BIT_TIME_T
#घोषणा _wfinddata_t _wfinddata32_t
#घोषणा _wfinddatai64_t _wfinddata32i64_t

#घोषणा _wfindfirst _wfindfirst32
#घोषणा _wfindnext _wfindnext32
#घोषणा _wfindfirsti64 _wfindfirst32i64
#घोषणा _wfindnexti64 _wfindnext32i64
#अन्यथा
#घोषणा _wfinddata_t _wfinddata64i32_t
#घोषणा _wfinddatai64_t _wfinddata64_t

#घोषणा _wfindfirst _wfindfirst64i32
#घोषणा _wfindnext _wfindnext64i32
#घोषणा _wfindfirsti64 _wfindfirst64
#घोषणा _wfindnexti64 _wfindnext64
#पूर्ण_अगर

#घोषणा _WFINDDATA_T_DEFINED
#पूर्ण_अगर

#घोषणा _A_NORMAL 0x00
#घोषणा _A_RDONLY 0x01
#घोषणा _A_HIDDEN 0x02
#घोषणा _A_SYSTEM 0x04
#घोषणा _A_SUBDIR 0x10
#घोषणा _A_ARCH 0x20

#अगर_अघोषित _SIZE_T_DEFINED
#घोषणा _SIZE_T_DEFINED
#अघोषित माप_प्रकार
#अगर_घोषित _WIN64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार अचिन्हित पूर्णांक माप_प्रकार __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार अचिन्हित __int64 माप_प्रकार;
#पूर्ण_अगर
#अन्यथा
  प्रकार अचिन्हित पूर्णांक माप_प्रकार;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _SSIZE_T_DEFINED
#घोषणा _SSIZE_T_DEFINED
#अघोषित ssize_t
#अगर_घोषित _WIN64
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार पूर्णांक ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकार __int64 ssize_t;
#पूर्ण_अगर
#अन्यथा
  प्रकार पूर्णांक ssize_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF_T_DEFINED
#घोषणा _OFF_T_DEFINED
#अगर_अघोषित _OFF_T_
#घोषणा _OFF_T_
  प्रकार दीर्घ _off_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ off_t;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF64_T_DEFINED
#घोषणा _OFF64_T_DEFINED
#अगर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकार पूर्णांक _off64_t __attribute__ ((mode (DI)));
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार पूर्णांक off64_t __attribute__ ((mode (DI)));
#पूर्ण_अगर
#अन्यथा
  प्रकार दीर्घ दीर्घ _off64_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ दीर्घ off64_t;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#घोषणा	F_OK	0	/* Check for file existence */
#घोषणा	X_OK	1	/* Check for execute permission. */
#घोषणा	W_OK	2	/* Check for write permission */
#घोषणा	R_OK	4	/* Check for read permission */

  _CRTIMP पूर्णांक __cdecl _access(स्थिर अक्षर *_Filename,पूर्णांक _AccessMode);
  _CRTIMP पूर्णांक __cdecl _chmod(स्थिर अक्षर *_Filename,पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _chsize(पूर्णांक _FileHandle,दीर्घ आकार_4);
  _CRTIMP पूर्णांक __cdecl _close(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _commit(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _creat(स्थिर अक्षर *_Filename,पूर्णांक _PermissionMode);
  _CRTIMP पूर्णांक __cdecl _dup(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _dup2(पूर्णांक _FileHandleSrc,पूर्णांक _FileHandleDst);
  _CRTIMP पूर्णांक __cdecl _eof(पूर्णांक _FileHandle);
  _CRTIMP दीर्घ __cdecl _filelength(पूर्णांक _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(स्थिर अक्षर *_Filename,काष्ठा _finddata32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _findnext32(intptr_t _FindHandle,काष्ठा _finddata32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP पूर्णांक __cdecl _isatty(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _locking(पूर्णांक _FileHandle,पूर्णांक _LockMode,दीर्घ अंक_Of_Bytes);
  _CRTIMP दीर्घ __cdecl _lseek(पूर्णांक _FileHandle,दीर्घ _Offset,पूर्णांक _Origin);
  _off64_t lseek64(पूर्णांक fd,_off64_t offset, पूर्णांक whence);
  _CRTIMP अक्षर *__cdecl _mktemp(अक्षर *_TemplateName);
  _CRTIMP पूर्णांक __cdecl _pipe(पूर्णांक *_PtHandles,अचिन्हित पूर्णांक Pipe_आकार,पूर्णांक _TextMode);
  _CRTIMP पूर्णांक __cdecl _read(पूर्णांक _FileHandle,व्योम *_DstBuf,अचिन्हित पूर्णांक Max_Char_गिनती);

#अगर_अघोषित _CRT_DIRECTORY_DEFINED
#घोषणा _CRT_DIRECTORY_DEFINED
  पूर्णांक __cdecl हटाओ(स्थिर अक्षर *_Filename);
  पूर्णांक __cdecl नाम(स्थिर अक्षर *_OldFilename,स्थिर अक्षर *_NewFilename);
  _CRTIMP पूर्णांक __cdecl _unlink(स्थिर अक्षर *_Filename);
#अगर_अघोषित	NO_OLDNAMES
  पूर्णांक __cdecl unlink(स्थिर अक्षर *_Filename);
#पूर्ण_अगर
#पूर्ण_अगर

  _CRTIMP पूर्णांक __cdecl _setmode(पूर्णांक _FileHandle,पूर्णांक _Mode);
  _CRTIMP दीर्घ __cdecl _tell(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _umask(पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _write(पूर्णांक _FileHandle,स्थिर व्योम *_Buf,अचिन्हित पूर्णांक Max_Char_गिनती);

#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(पूर्णांक _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(स्थिर अक्षर *_Filename,काष्ठा _finddata32i64_t *Find_तथ्य);
  _CRTIMP intptr_t __cdecl _findfirst64(स्थिर अक्षर *_Filename,काष्ठा __finddata64_t *Find_तथ्य);
#अगर_घोषित __cplusplus
#समावेश <string.h>
#पूर्ण_अगर
  intptr_t __cdecl _findfirst64i32(स्थिर अक्षर *_Filename,काष्ठा _finddata64i32_t *Find_तथ्य);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(स्थिर अक्षर *_Filename,काष्ठा _finddata64i32_t *Find_तथ्य)
  {
    काष्ठा __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    Find_तथ्य->attrib=fd.attrib;
    Find_तथ्य->time_create=fd.time_create;
    Find_तथ्य->time_access=fd.time_access;
    Find_तथ्य->time_write=fd.time_write;
    Find_तथ्य->आकार=(_fsize_t) fd.आकार;
    म_नकलन(Find_तथ्य->name,fd.name,260);
    वापस ret;
  }
  _CRTIMP पूर्णांक __cdecl _findnext32i64(intptr_t _FindHandle,काष्ठा _finddata32i64_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _findnext64(intptr_t _FindHandle,काष्ठा __finddata64_t *Find_तथ्य);
  पूर्णांक __cdecl _findnext64i32(intptr_t _FindHandle,काष्ठा _finddata64i32_t *Find_तथ्य);
  __CRT_INLINE पूर्णांक __cdecl _findnext64i32(intptr_t _FindHandle,काष्ठा _finddata64i32_t *Find_तथ्य)
  {
    काष्ठा __finddata64_t fd;
    पूर्णांक ret = _findnext64(_FindHandle,&fd);
    Find_तथ्य->attrib=fd.attrib;
    Find_तथ्य->time_create=fd.time_create;
    Find_तथ्य->time_access=fd.time_access;
    Find_तथ्य->time_write=fd.time_write;
    Find_तथ्य->आकार=(_fsize_t) fd.आकार;
    म_नकलन(Find_तथ्य->name,fd.name,260);
    वापस ret;
  }
  __int64 __cdecl _lseeki64(पूर्णांक _FileHandle,__int64 _Offset,पूर्णांक _Origin);
  __int64 __cdecl _telli64(पूर्णांक _FileHandle);
#पूर्ण_अगर
#अगर_अघोषित NO_OLDNAMES

#अगर_अघोषित _UWIN
  पूर्णांक __cdecl स_बदलो (स्थिर अक्षर *);
  अक्षर *__cdecl getcwd (अक्षर *, पूर्णांक);
  पूर्णांक __cdecl सूची_गढ़ो (स्थिर अक्षर *);
  अक्षर *__cdecl mktemp(अक्षर *);
  पूर्णांक __cdecl सूची_हटाओ (स्थिर अक्षर*);
  पूर्णांक __cdecl chmod (स्थिर अक्षर *, पूर्णांक);
#पूर्ण_अगर /* _UWIN */

#पूर्ण_अगर /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(पूर्णांक *_FileHandle,स्थिर अक्षर *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode);

#अगर_अघोषित __cplusplus
  _CRTIMP पूर्णांक __cdecl _open(स्थिर अक्षर *_Filename,पूर्णांक _OpenFlag,...);
  _CRTIMP पूर्णांक __cdecl _sopen(स्थिर अक्षर *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _open(स्थिर अक्षर *_Filename,पूर्णांक _Openflag,पूर्णांक _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _sopen(स्थिर अक्षर *_Filename,पूर्णांक _Openflag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode = 0);
#पूर्ण_अगर

#अगर_अघोषित _WIO_DEFINED
#घोषणा _WIO_DEFINED
  _CRTIMP पूर्णांक __cdecl _waccess(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _AccessMode);
  _CRTIMP पूर्णांक __cdecl _wchmod(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _wcreat(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wfindnext32(intptr_t _FindHandle,काष्ठा _wfinddata32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wunlink(स्थिर ब_अक्षर_प्रकार *_Filename);
  _CRTIMP पूर्णांक __cdecl _wrename(स्थिर ब_अक्षर_प्रकार *_NewFilename,स्थिर ब_अक्षर_प्रकार *_OldFilename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wmktemp(ब_अक्षर_प्रकार *_TemplateName);

#अगर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata32i64_t *Find_तथ्य);
  intptr_t __cdecl _wfindfirst64i32(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata64i32_t *Find_तथ्य);
  _CRTIMP intptr_t __cdecl _wfindfirst64(स्थिर ब_अक्षर_प्रकार *_Filename,काष्ठा _wfinddata64_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wfindnext32i64(intptr_t _FindHandle,काष्ठा _wfinddata32i64_t *Find_तथ्य);
  पूर्णांक __cdecl _wfindnext64i32(intptr_t _FindHandle,काष्ठा _wfinddata64i32_t *Find_तथ्य);
  _CRTIMP पूर्णांक __cdecl _wfindnext64(intptr_t _FindHandle,काष्ठा _wfinddata64_t *Find_तथ्य);
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णांक *_FileHandle,स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionFlag);

#अगर !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक __cdecl _wopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,...);
  _CRTIMP पूर्णांक __cdecl _wsopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _wopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _wsopen(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode = 0);
#पूर्ण_अगर

#पूर्ण_अगर

  पूर्णांक __cdecl __lock_fhandle(पूर्णांक _Filehandle);
  व्योम __cdecl _unlock_fhandle(पूर्णांक _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _open_osfhandle(intptr_t _OSFileHandle,पूर्णांक _Flags);

#अगर_अघोषित	NO_OLDNAMES
  पूर्णांक __cdecl access(स्थिर अक्षर *_Filename,पूर्णांक _AccessMode);
  पूर्णांक __cdecl chmod(स्थिर अक्षर *_Filename,पूर्णांक _AccessMode);
  पूर्णांक __cdecl chsize(पूर्णांक _FileHandle,दीर्घ आकार_4);
  पूर्णांक __cdecl बंद(पूर्णांक _FileHandle);
  पूर्णांक __cdecl creat(स्थिर अक्षर *_Filename,पूर्णांक _PermissionMode);
  पूर्णांक __cdecl dup(पूर्णांक _FileHandle);
  पूर्णांक __cdecl dup2(पूर्णांक _FileHandleSrc,पूर्णांक _FileHandleDst);
  पूर्णांक __cdecl eof(पूर्णांक _FileHandle);
  दीर्घ __cdecl filelength(पूर्णांक _FileHandle);
  पूर्णांक __cdecl isatty(पूर्णांक _FileHandle);
  पूर्णांक __cdecl locking(पूर्णांक _FileHandle,पूर्णांक _LockMode,दीर्घ अंक_Of_Bytes);
  दीर्घ __cdecl lseek(पूर्णांक _FileHandle,दीर्घ _Offset,पूर्णांक _Origin);
  अक्षर *__cdecl mktemp(अक्षर *_TemplateName);
  पूर्णांक __cdecl खोलो(स्थिर अक्षर *_Filename,पूर्णांक _OpenFlag,...);
  पूर्णांक __cdecl पढ़ो(पूर्णांक _FileHandle,व्योम *_DstBuf,अचिन्हित पूर्णांक Max_Char_गिनती);
  पूर्णांक __cdecl setmode(पूर्णांक _FileHandle,पूर्णांक _Mode);
  पूर्णांक __cdecl sopen(स्थिर अक्षर *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
  दीर्घ __cdecl tell(पूर्णांक _FileHandle);
  पूर्णांक __cdecl umask(पूर्णांक _Mode);
  पूर्णांक __cdecl ग_लिखो(पूर्णांक _Filehandle,स्थिर व्योम *_Buf,अचिन्हित पूर्णांक Max_Char_गिनती);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

/* Misc stuff */
अक्षर *getlogin(व्योम);
#अगर_घोषित __USE_MINGW_ALARM
अचिन्हित पूर्णांक alarm(अचिन्हित पूर्णांक seconds);
#पूर्ण_अगर

#अगर_घोषित __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
अटल अंतरभूत पूर्णांक __mingw_access (स्थिर अक्षर *__fname, पूर्णांक __mode) {
  वापस  _access (__fname, __mode & ~X_OK);
}

#घोषणा access(__f,__m)  __mingw_access (__f, __m)
#पूर्ण_अगर


#अगर_घोषित __cplusplus
}
#पूर्ण_अगर


#आशय pack(निकालो)

#समावेश <sec_api/io_s.h>

#पूर्ण_अगर /* End _IO_H_ */

