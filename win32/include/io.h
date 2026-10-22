
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <string.h>

#pragma pack(धकेलो,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
बाह्य "C" {
#endif

_CRTIMP वर्ण* __cdecl _getcwd (वर्ण*, पूर्णाङ्क);
#ifndef _FSIZE_T_DEFINED
  प्रकारनिर्देश unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  संरचना _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    वर्ण name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  संरचना _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    वर्ण name[260];
  };

  संरचना _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    वर्ण name[260];
  };

  संरचना __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    वर्ण name[260];
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
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  संरचना _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  संरचना _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  संरचना _wfinddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    wchar_t name[260];
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
#undef size_t
#ifdef _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश unsigned पूर्णाङ्क size_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश unsigned __int64 size_t;
#endif
#अन्यथा
  प्रकारनिर्देश unsigned पूर्णाङ्क size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((mode (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 ssize_t;
#endif
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  प्रकारनिर्देश long _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क _off64_t __attribute__ ((mode (DI)));
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश पूर्णाङ्क off64_t __attribute__ ((mode (DI)));
#endif
#अन्यथा
  प्रकारनिर्देश long long _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP पूर्णाङ्क __cdecl _access(ध्रुव वर्ण *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP पूर्णाङ्क __cdecl _chmod(ध्रुव वर्ण *_Filename,पूर्णाङ्क _Mode);
  _CRTIMP पूर्णाङ्क __cdecl _chsize(पूर्णाङ्क _FileHandle,long _Size);
  _CRTIMP पूर्णाङ्क __cdecl _close(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _commit(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _creat(ध्रुव वर्ण *_Filename,पूर्णाङ्क _PermissionMode);
  _CRTIMP पूर्णाङ्क __cdecl _dup(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _dup2(पूर्णाङ्क _FileHandleSrc,पूर्णाङ्क _FileHandleDst);
  _CRTIMP पूर्णाङ्क __cdecl _eof(पूर्णाङ्क _FileHandle);
  _CRTIMP long __cdecl _filelength(पूर्णाङ्क _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ध्रुव वर्ण *_Filename,संरचना _finddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _findnext32(intptr_t _FindHandle,संरचना _finddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP पूर्णाङ्क __cdecl _isatty(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _locking(पूर्णाङ्क _FileHandle,पूर्णाङ्क _LockMode,long अंक_Of_Bytes);
  _CRTIMP long __cdecl _lseek(पूर्णाङ्क _FileHandle,long _Offset,पूर्णाङ्क _Origin);
  _off64_t lseek64(पूर्णाङ्क fd,_off64_t offset, पूर्णाङ्क whence);
  _CRTIMP वर्ण *__cdecl _mktemp(वर्ण *_TemplateName);
  _CRTIMP पूर्णाङ्क __cdecl _pipe(पूर्णाङ्क *_PtHandles,unsigned पूर्णाङ्क _PipeSize,पूर्णाङ्क _TextMode);
  _CRTIMP पूर्णाङ्क __cdecl _read(पूर्णाङ्क _FileHandle,शून्य *_DstBuf,unsigned पूर्णाङ्क Max_Char_गिनती);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  पूर्णाङ्क __cdecl remove(ध्रुव वर्ण *_Filename);
  पूर्णाङ्क __cdecl rename(ध्रुव वर्ण *_OldFilename,ध्रुव वर्ण *_NewFilename);
  _CRTIMP पूर्णाङ्क __cdecl _unlink(ध्रुव वर्ण *_Filename);
#ifndef	NO_OLDNAMES
  पूर्णाङ्क __cdecl unlink(ध्रुव वर्ण *_Filename);
#endif
#endif

  _CRTIMP पूर्णाङ्क __cdecl _setmode(पूर्णाङ्क _FileHandle,पूर्णाङ्क _Mode);
  _CRTIMP long __cdecl _tell(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _umask(पूर्णाङ्क _Mode);
  _CRTIMP पूर्णाङ्क __cdecl _write(पूर्णाङ्क _FileHandle,ध्रुव शून्य *_Buf,unsigned पूर्णाङ्क Max_Char_गिनती);

#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(पूर्णाङ्क _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ध्रुव वर्ण *_Filename,संरचना _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(ध्रुव वर्ण *_Filename,संरचना __finddata64_t *_FindData);
#ifdef __cplusplus
#अन्तर्भाव <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(ध्रुव वर्ण *_Filename,संरचना _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ध्रुव वर्ण *_Filename,संरचना _finddata64i32_t *_FindData)
  {
    संरचना __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    प्रत्यागम ret;
  }
  _CRTIMP पूर्णाङ्क __cdecl _findnext32i64(intptr_t _FindHandle,संरचना _finddata32i64_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _findnext64(intptr_t _FindHandle,संरचना __finddata64_t *_FindData);
  पूर्णाङ्क __cdecl _findnext64i32(intptr_t _FindHandle,संरचना _finddata64i32_t *_FindData);
  __CRT_INLINE पूर्णाङ्क __cdecl _findnext64i32(intptr_t _FindHandle,संरचना _finddata64i32_t *_FindData)
  {
    संरचना __finddata64_t fd;
    पूर्णाङ्क ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    प्रत्यागम ret;
  }
  __int64 __cdecl _lseeki64(पूर्णाङ्क _FileHandle,__int64 _Offset,पूर्णाङ्क _Origin);
  __int64 __cdecl _telli64(पूर्णाङ्क _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  पूर्णाङ्क __cdecl chdir (ध्रुव वर्ण *);
  वर्ण *__cdecl getcwd (वर्ण *, पूर्णाङ्क);
  पूर्णाङ्क __cdecl mkdir (ध्रुव वर्ण *);
  वर्ण *__cdecl mktemp(वर्ण *);
  पूर्णाङ्क __cdecl rmdir (ध्रुव वर्ण*);
  पूर्णाङ्क __cdecl chmod (ध्रुव वर्ण *, पूर्णाङ्क);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(पूर्णाङ्क *_FileHandle,ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionMode);

#ifndef __cplusplus
  _CRTIMP पूर्णाङ्क __cdecl _open(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _sopen(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _open(ध्रुव वर्ण *_Filename,पूर्णाङ्क _Openflag,पूर्णाङ्क _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _sopen(ध्रुव वर्ण *_Filename,पूर्णाङ्क _Openflag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _waccess(ध्रुव wchar_t *_Filename,पूर्णाङ्क _AccessMode);
  _CRTIMP पूर्णाङ्क __cdecl _wchmod(ध्रुव wchar_t *_Filename,पूर्णाङ्क _Mode);
  _CRTIMP पूर्णाङ्क __cdecl _wcreat(ध्रुव wchar_t *_Filename,पूर्णाङ्क _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ध्रुव wchar_t *_Filename,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32(intptr_t _FindHandle,संरचना _wfinddata32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wunlink(ध्रुव wchar_t *_Filename);
  _CRTIMP पूर्णाङ्क __cdecl _wrename(ध्रुव wchar_t *_NewFilename,ध्रुव wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#यदि _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ध्रुव wchar_t *_Filename,संरचना _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ध्रुव wchar_t *_Filename,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ध्रुव wchar_t *_Filename,संरचना _wfinddata64_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32i64(intptr_t _FindHandle,संरचना _wfinddata32i64_t *_FindData);
  पूर्णाङ्क __cdecl _wfindnext64i32(intptr_t _FindHandle,संरचना _wfinddata64i32_t *_FindData);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext64(intptr_t _FindHandle,संरचना _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णाङ्क *_FileHandle,ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionFlag);

#यदि !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _PermissionMode = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionMode = 0);
#endif

#endif

  पूर्णाङ्क __cdecl __lock_fhandle(पूर्णाङ्क _Filehandle);
  शून्य __cdecl _unlock_fhandle(पूर्णाङ्क _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _open_osfhandle(intptr_t _OSFileHandle,पूर्णाङ्क _Flags);

#ifndef	NO_OLDNAMES
  पूर्णाङ्क __cdecl access(ध्रुव वर्ण *_Filename,पूर्णाङ्क _AccessMode);
  पूर्णाङ्क __cdecl chmod(ध्रुव वर्ण *_Filename,पूर्णाङ्क _AccessMode);
  पूर्णाङ्क __cdecl chsize(पूर्णाङ्क _FileHandle,long _Size);
  पूर्णाङ्क __cdecl close(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl creat(ध्रुव वर्ण *_Filename,पूर्णाङ्क _PermissionMode);
  पूर्णाङ्क __cdecl dup(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl dup2(पूर्णाङ्क _FileHandleSrc,पूर्णाङ्क _FileHandleDst);
  पूर्णाङ्क __cdecl eof(पूर्णाङ्क _FileHandle);
  long __cdecl filelength(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl isatty(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl locking(पूर्णाङ्क _FileHandle,पूर्णाङ्क _LockMode,long अंक_Of_Bytes);
  long __cdecl lseek(पूर्णाङ्क _FileHandle,long _Offset,पूर्णाङ्क _Origin);
  वर्ण *__cdecl mktemp(वर्ण *_TemplateName);
  पूर्णाङ्क __cdecl open(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,...);
  पूर्णाङ्क __cdecl पठ(पूर्णाङ्क _FileHandle,शून्य *_DstBuf,unsigned पूर्णाङ्क Max_Char_गिनती);
  पूर्णाङ्क __cdecl setmode(पूर्णाङ्क _FileHandle,पूर्णाङ्क _Mode);
  पूर्णाङ्क __cdecl sopen(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
  long __cdecl tell(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl umask(पूर्णाङ्क _Mode);
  पूर्णाङ्क __cdecl लिख(पूर्णाङ्क _Filehandle,ध्रुव शून्य *_Buf,unsigned पूर्णाङ्क Max_Char_गिनती);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
बाह्य "C" {
#endif

/* Misc stuff */
वर्ण *getlogin(शून्य);
#ifdef __USE_MINGW_ALARM
unsigned पूर्णाङ्क alarm(unsigned पूर्णाङ्क seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
स्थिर अन्तःस्थ पूर्णाङ्क __mingw_access (ध्रुव वर्ण *__fname, पूर्णाङ्क __mode) {
  प्रत्यागम  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(निकालो)

#अन्तर्भाव <sec_api/io_s.h>

#endif /* End _IO_H_ */

