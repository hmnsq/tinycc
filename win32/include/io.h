
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <string.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
बाह्य "C" {
#endif

_CRTIMP अक्षर* __cdecl _getcwd (अक्षर*, पूर्णांक);
#ifndef _FSIZE_T_DEFINED
  प्रकारव्याख्या अचिन्हित दीर्घ _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  संरचना _finddata32_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    अक्षर name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  संरचना _finddata32i64_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    अक्षर name[260];
  };

  संरचना _finddata64i32_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    अक्षर name[260];
  };

  संरचना __finddata64_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    अक्षर name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#अन्यथा
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#अन्यथा
#define _finddata_t _finddata64i32_t
#define _finddatai64_t __finddata64_t

#define _findfirst _findfirst64i32
#define _findnext _findnext64i32
#define _findfirsti64 _findfirst64
#define _findnexti64 _findnext64
#endif

#define _FINDDATA_T_DEFINED
#endif

#ifndef _WFINDDATA_T_DEFINED

  संरचना _wfinddata32_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    ब_अक्षर_प्रकार name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  संरचना _wfinddata32i64_t {
    अचिन्हित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    ब_अक्षर_प्रकार name[260];
  };

  संरचना _wfinddata64i32_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    ब_अक्षर_प्रकार name[260];
  };

  संरचना _wfinddata64_t {
    अचिन्हित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    ब_अक्षर_प्रकार name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _wfinddata_t _wfinddata32_t
#define _wfinddatai64_t _wfinddata32i64_t

#define _wfindfirst _wfindfirst32
#define _wfindnext _wfindnext32
#define _wfindfirsti64 _wfindfirst32i64
#define _wfindnexti64 _wfindnext32i64
#अन्यथा
#define _wfinddata_t _wfinddata64i32_t
#define _wfinddatai64_t _wfinddata64_t

#define _wfindfirst _wfindfirst64i32
#define _wfindnext _wfindnext64i32
#define _wfindfirsti64 _wfindfirst64
#define _wfindnexti64 _wfindnext64
#endif

#define _WFINDDATA_T_DEFINED
#endif

#define _A_NORMAL 0x00
#define _A_RDONLY 0x01
#define _A_HIDDEN 0x02
#define _A_SYSTEM 0x04
#define _A_SUBDIR 0x10
#define _A_ARCH 0x20

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#undef माप_प्रकार
#ifdef _WIN64
#जर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारव्याख्या अचिन्हित पूर्णांक माप_प्रकार __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारव्याख्या अचिन्हित __int64 माप_प्रकार;
#endif
#अन्यथा
  प्रकारव्याख्या अचिन्हित पूर्णांक माप_प्रकार;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#जर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारव्याख्या पूर्णांक ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारव्याख्या __int64 ssize_t;
#endif
#अन्यथा
  प्रकारव्याख्या पूर्णांक ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  प्रकारव्याख्या दीर्घ _off_t;
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या दीर्घ off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#जर defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारव्याख्या पूर्णांक _off64_t __attribute__ ((mode (DI)));
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या पूर्णांक off64_t __attribute__ ((mode (DI)));
#endif
#अन्यथा
  प्रकारव्याख्या दीर्घ दीर्घ _off64_t;
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या दीर्घ दीर्घ off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP पूर्णांक __cdecl _access(स्थिरांक अक्षर *_Filename,पूर्णांक _AccessMode);
  _CRTIMP पूर्णांक __cdecl _chmod(स्थिरांक अक्षर *_Filename,पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _chsize(पूर्णांक _FileHandle,दीर्घ _Size);
  _CRTIMP पूर्णांक __cdecl _close(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _commit(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _creat(स्थिरांक अक्षर *_Filename,पूर्णांक _PermissionMode);
  _CRTIMP पूर्णांक __cdecl _dup(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _dup2(पूर्णांक _FileHandleSrc,पूर्णांक _FileHandleDst);
  _CRTIMP पूर्णांक __cdecl _eof(पूर्णांक _FileHandle);
  _CRTIMP दीर्घ __cdecl _filelength(पूर्णांक _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(स्थिरांक अक्षर *_Filename,संरचना _finddata32_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _findnext32(intptr_t _FindHandle,संरचना _finddata32_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP पूर्णांक __cdecl _isatty(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _locking(पूर्णांक _FileHandle,पूर्णांक _LockMode,दीर्घ अंक_Of_Bytes);
  _CRTIMP दीर्घ __cdecl _lseek(पूर्णांक _FileHandle,दीर्घ _Offset,पूर्णांक _Origin);
  _off64_t lseek64(पूर्णांक fd,_off64_t offset, पूर्णांक whence);
  _CRTIMP अक्षर *__cdecl _mktemp(अक्षर *_TemplateName);
  _CRTIMP पूर्णांक __cdecl _pipe(पूर्णांक *_PtHandles,अचिन्हित पूर्णांक _PipeSize,पूर्णांक _TextMode);
  _CRTIMP पूर्णांक __cdecl _read(पूर्णांक _FileHandle,शून्य *_DstBuf,अचिन्हित पूर्णांक Max_Char_मोजणी);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  पूर्णांक __cdecl हटाओ(स्थिरांक अक्षर *_Filename);
  पूर्णांक __cdecl नाम(स्थिरांक अक्षर *_OldFilename,स्थिरांक अक्षर *_NewFilename);
  _CRTIMP पूर्णांक __cdecl _unlink(स्थिरांक अक्षर *_Filename);
#ifndef	NO_OLDNAMES
  पूर्णांक __cdecl unlink(स्थिरांक अक्षर *_Filename);
#endif
#endif

  _CRTIMP पूर्णांक __cdecl _setmode(पूर्णांक _FileHandle,पूर्णांक _Mode);
  _CRTIMP दीर्घ __cdecl _tell(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _umask(पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _write(पूर्णांक _FileHandle,स्थिरांक शून्य *_Buf,अचिन्हित पूर्णांक Max_Char_मोजणी);

#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(पूर्णांक _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(स्थिरांक अक्षर *_Filename,संरचना _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(स्थिरांक अक्षर *_Filename,संरचना __finddata64_t *_FindData);
#ifdef __cplusplus
#अन्तर्भाव <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(स्थिरांक अक्षर *_Filename,संरचना _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(स्थिरांक अक्षर *_Filename,संरचना _finddata64i32_t *_FindData)
  {
    संरचना __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    म_नकलन(_FindData->name,fd.name,260);
    परत ret;
  }
  _CRTIMP पूर्णांक __cdecl _findnext32i64(intptr_t _FindHandle,संरचना _finddata32i64_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _findnext64(intptr_t _FindHandle,संरचना __finddata64_t *_FindData);
  पूर्णांक __cdecl _findnext64i32(intptr_t _FindHandle,संरचना _finddata64i32_t *_FindData);
  __CRT_INLINE पूर्णांक __cdecl _findnext64i32(intptr_t _FindHandle,संरचना _finddata64i32_t *_FindData)
  {
    संरचना __finddata64_t fd;
    पूर्णांक ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    म_नकलन(_FindData->name,fd.name,260);
    परत ret;
  }
  __int64 __cdecl _lseeki64(पूर्णांक _FileHandle,__int64 _Offset,पूर्णांक _Origin);
  __int64 __cdecl _telli64(पूर्णांक _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  पूर्णांक __cdecl स_बदलो (स्थिरांक अक्षर *);
  अक्षर *__cdecl getcwd (अक्षर *, पूर्णांक);
  पूर्णांक __cdecl सूची_गढ़ो (स्थिरांक अक्षर *);
  अक्षर *__cdecl mktemp(अक्षर *);
  पूर्णांक __cdecl सूची_हटाओ (स्थिरांक अक्षर*);
  पूर्णांक __cdecl chmod (स्थिरांक अक्षर *, पूर्णांक);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(पूर्णांक *_FileHandle,स्थिरांक अक्षर *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode);

#ifndef __cplusplus
  _CRTIMP पूर्णांक __cdecl _open(स्थिरांक अक्षर *_Filename,पूर्णांक _OpenFlag,...);
  _CRTIMP पूर्णांक __cdecl _sopen(स्थिरांक अक्षर *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _open(स्थिरांक अक्षर *_Filename,पूर्णांक _Openflag,पूर्णांक _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _sopen(स्थिरांक अक्षर *_Filename,पूर्णांक _Openflag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP पूर्णांक __cdecl _waccess(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _AccessMode);
  _CRTIMP पूर्णांक __cdecl _wchmod(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _Mode);
  _CRTIMP पूर्णांक __cdecl _wcreat(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _wfindnext32(intptr_t _FindHandle,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _wunlink(स्थिरांक ब_अक्षर_प्रकार *_Filename);
  _CRTIMP पूर्णांक __cdecl _wrename(स्थिरांक ब_अक्षर_प्रकार *_NewFilename,स्थिरांक ब_अक्षर_प्रकार *_OldFilename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wmktemp(ब_अक्षर_प्रकार *_TemplateName);

#जर _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(स्थिरांक ब_अक्षर_प्रकार *_Filename,संरचना _wfinddata64_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _wfindnext32i64(intptr_t _FindHandle,संरचना _wfinddata32i64_t *_FindData);
  पूर्णांक __cdecl _wfindnext64i32(intptr_t _FindHandle,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP पूर्णांक __cdecl _wfindnext64(intptr_t _FindHandle,संरचना _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णांक *_FileHandle,स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionFlag);

#जर !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णांक __cdecl _wopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,...);
  _CRTIMP पूर्णांक __cdecl _wsopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _wopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णांक __cdecl _wsopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,पूर्णांक _PermissionMode = 0);
#endif

#endif

  पूर्णांक __cdecl __lock_fhandle(पूर्णांक _Filehandle);
  शून्य __cdecl _unlock_fhandle(पूर्णांक _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(पूर्णांक _FileHandle);
  _CRTIMP पूर्णांक __cdecl _open_osfhandle(intptr_t _OSFileHandle,पूर्णांक _Flags);

#ifndef	NO_OLDNAMES
  पूर्णांक __cdecl access(स्थिरांक अक्षर *_Filename,पूर्णांक _AccessMode);
  पूर्णांक __cdecl chmod(स्थिरांक अक्षर *_Filename,पूर्णांक _AccessMode);
  पूर्णांक __cdecl chsize(पूर्णांक _FileHandle,दीर्घ _Size);
  पूर्णांक __cdecl बंद(पूर्णांक _FileHandle);
  पूर्णांक __cdecl creat(स्थिरांक अक्षर *_Filename,पूर्णांक _PermissionMode);
  पूर्णांक __cdecl dup(पूर्णांक _FileHandle);
  पूर्णांक __cdecl dup2(पूर्णांक _FileHandleSrc,पूर्णांक _FileHandleDst);
  पूर्णांक __cdecl eof(पूर्णांक _FileHandle);
  दीर्घ __cdecl filelength(पूर्णांक _FileHandle);
  पूर्णांक __cdecl isatty(पूर्णांक _FileHandle);
  पूर्णांक __cdecl locking(पूर्णांक _FileHandle,पूर्णांक _LockMode,दीर्घ अंक_Of_Bytes);
  दीर्घ __cdecl lseek(पूर्णांक _FileHandle,दीर्घ _Offset,पूर्णांक _Origin);
  अक्षर *__cdecl mktemp(अक्षर *_TemplateName);
  पूर्णांक __cdecl खोलो(स्थिरांक अक्षर *_Filename,पूर्णांक _OpenFlag,...);
  पूर्णांक __cdecl पठ(पूर्णांक _FileHandle,शून्य *_DstBuf,अचिन्हित पूर्णांक Max_Char_मोजणी);
  पूर्णांक __cdecl setmode(पूर्णांक _FileHandle,पूर्णांक _Mode);
  पूर्णांक __cdecl sopen(स्थिरांक अक्षर *_Filename,पूर्णांक _OpenFlag,पूर्णांक _ShareFlag,...);
  दीर्घ __cdecl tell(पूर्णांक _FileHandle);
  पूर्णांक __cdecl umask(पूर्णांक _Mode);
  पूर्णांक __cdecl लिख(पूर्णांक _Filehandle,स्थिरांक शून्य *_Buf,अचिन्हित पूर्णांक Max_Char_मोजणी);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
बाह्य "C" {
#endif

/* Misc stuff */
अक्षर *getlogin(शून्य);
#ifdef __USE_MINGW_ALARM
अचिन्हित पूर्णांक alarm(अचिन्हित पूर्णांक seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
स्थिर ओळीत पूर्णांक __mingw_access (स्थिरांक अक्षर *__fname, पूर्णांक __mode) {
  परत  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(काढा)

#अन्तर्भाव <sec_api/io_s.h>

#endif /* End _IO_H_ */

