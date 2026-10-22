
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#include <_mingw.h>
#include <string.h>

#pragma pack(push,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
extern "C" {
#endif

_CRTIMP var_na* __cdecl _getcwd (var_na*, จำนวนเต็ม);
#ifndef _FSIZE_T_DEFINED
  typedef unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  sa_nracanaa _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    var_na name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  sa_nracanaa _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    var_na name[260];
  };

  sa_nracanaa _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    var_na name[260];
  };

  sa_nracanaa __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    var_na name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#มิฉะนั้น
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#มิฉะนั้น
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

  sa_nracanaa _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  sa_nracanaa _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  sa_nracanaa _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  sa_nracanaa _wfinddata64_t {
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
#มิฉะนั้น
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
#ถ้า defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned จำนวนเต็ม size_t __attribute__ ((mode (DI)));
#มิฉะนั้น
  typedef unsigned __int64 size_t;
#endif
#มิฉะนั้น
  typedef unsigned จำนวนเต็ม size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ถ้า defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef จำนวนเต็ม ssize_t __attribute__ ((mode (DI)));
#มิฉะนั้น
  typedef __int64 ssize_t;
#endif
#มิฉะนั้น
  typedef จำนวนเต็ม ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#ถ้า !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#ถ้า defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef จำนวนเต็ม _off64_t __attribute__ ((mode (DI)));
#ถ้า !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef จำนวนเต็ม off64_t __attribute__ ((mode (DI)));
#endif
#มิฉะนั้น
  typedef long long _off64_t;
#ถ้า !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP จำนวนเต็ม __cdecl _access(const var_na *_Filename,จำนวนเต็ม _AccessMode);
  _CRTIMP จำนวนเต็ม __cdecl _chmod(const var_na *_Filename,จำนวนเต็ม _Mode);
  _CRTIMP จำนวนเต็ม __cdecl _chsize(จำนวนเต็ม _FileHandle,long _Size);
  _CRTIMP จำนวนเต็ม __cdecl _close(จำนวนเต็ม _FileHandle);
  _CRTIMP จำนวนเต็ม __cdecl _commit(จำนวนเต็ม _FileHandle);
  _CRTIMP จำนวนเต็ม __cdecl _creat(const var_na *_Filename,จำนวนเต็ม _PermissionMode);
  _CRTIMP จำนวนเต็ม __cdecl _dup(จำนวนเต็ม _FileHandle);
  _CRTIMP จำนวนเต็ม __cdecl _dup2(จำนวนเต็ม _FileHandleSrc,จำนวนเต็ม _FileHandleDst);
  _CRTIMP จำนวนเต็ม __cdecl _eof(จำนวนเต็ม _FileHandle);
  _CRTIMP long __cdecl _filelength(จำนวนเต็ม _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const var_na *_Filename,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _findnext32(intptr_t _FindHandle,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP จำนวนเต็ม __cdecl _isatty(จำนวนเต็ม _FileHandle);
  _CRTIMP จำนวนเต็ม __cdecl _locking(จำนวนเต็ม _FileHandle,จำนวนเต็ม _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(จำนวนเต็ม _FileHandle,long _Offset,จำนวนเต็ม _Origin);
  _off64_t lseek64(จำนวนเต็ม fd,_off64_t offset, จำนวนเต็ม whence);
  _CRTIMP var_na *__cdecl _mktemp(var_na *_TemplateName);
  _CRTIMP จำนวนเต็ม __cdecl _pipe(จำนวนเต็ม *_PtHandles,unsigned จำนวนเต็ม _PipeSize,จำนวนเต็ม _TextMode);
  _CRTIMP จำนวนเต็ม __cdecl _read(จำนวนเต็ม _FileHandle,void *_DstBuf,unsigned จำนวนเต็ม _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  จำนวนเต็ม __cdecl remove(const var_na *_Filename);
  จำนวนเต็ม __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP จำนวนเต็ม __cdecl _unlink(const var_na *_Filename);
#ifndef	NO_OLDNAMES
  จำนวนเต็ม __cdecl unlink(const var_na *_Filename);
#endif
#endif

  _CRTIMP จำนวนเต็ม __cdecl _setmode(จำนวนเต็ม _FileHandle,จำนวนเต็ม _Mode);
  _CRTIMP long __cdecl _tell(จำนวนเต็ม _FileHandle);
  _CRTIMP จำนวนเต็ม __cdecl _umask(จำนวนเต็ม _Mode);
  _CRTIMP จำนวนเต็ม __cdecl _write(จำนวนเต็ม _FileHandle,const void *_Buf,unsigned จำนวนเต็ม _MaxCharCount);

#ถ้า _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(จำนวนเต็ม _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(const var_na *_Filename,sa_nracanaa _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(const var_na *_Filename,sa_nracanaa __finddata64_t *_FindData);
#ifdef __cplusplus
#include <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(const var_na *_Filename,sa_nracanaa _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(const var_na *_Filename,sa_nracanaa _finddata64i32_t *_FindData)
  {
    sa_nracanaa __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    คืน ret;
  }
  _CRTIMP จำนวนเต็ม __cdecl _findnext32i64(intptr_t _FindHandle,sa_nracanaa _finddata32i64_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _findnext64(intptr_t _FindHandle,sa_nracanaa __finddata64_t *_FindData);
  จำนวนเต็ม __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData);
  __CRT_INLINE จำนวนเต็ม __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData)
  {
    sa_nracanaa __finddata64_t fd;
    จำนวนเต็ม ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    คืน ret;
  }
  __int64 __cdecl _lseeki64(จำนวนเต็ม _FileHandle,__int64 _Offset,จำนวนเต็ม _Origin);
  __int64 __cdecl _telli64(จำนวนเต็ม _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  จำนวนเต็ม __cdecl chdir (const var_na *);
  var_na *__cdecl getcwd (var_na *, จำนวนเต็ม);
  จำนวนเต็ม __cdecl mkdir (const var_na *);
  var_na *__cdecl mktemp(var_na *);
  จำนวนเต็ม __cdecl rmdir (const var_na*);
  จำนวนเต็ม __cdecl chmod (const var_na *, จำนวนเต็ม);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(จำนวนเต็ม *_FileHandle,const var_na *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _ShareFlag,จำนวนเต็ม _PermissionMode);

#ifndef __cplusplus
  _CRTIMP จำนวนเต็ม __cdecl _open(const var_na *_Filename,จำนวนเต็ม _OpenFlag,...);
  _CRTIMP จำนวนเต็ม __cdecl _sopen(const var_na *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _ShareFlag,...);
#มิฉะนั้น
  extern "C++" _CRTIMP จำนวนเต็ม __cdecl _open(const var_na *_Filename,จำนวนเต็ม _Openflag,จำนวนเต็ม _PermissionMode = 0);
  extern "C++" _CRTIMP จำนวนเต็ม __cdecl _sopen(const var_na *_Filename,จำนวนเต็ม _Openflag,จำนวนเต็ม _ShareFlag,จำนวนเต็ม _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP จำนวนเต็ม __cdecl _waccess(const wchar_t *_Filename,จำนวนเต็ม _AccessMode);
  _CRTIMP จำนวนเต็ม __cdecl _wchmod(const wchar_t *_Filename,จำนวนเต็ม _Mode);
  _CRTIMP จำนวนเต็ม __cdecl _wcreat(const wchar_t *_Filename,จำนวนเต็ม _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _wfindnext32(intptr_t _FindHandle,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP จำนวนเต็ม __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ถ้า _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,sa_nracanaa _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,sa_nracanaa _wfinddata64_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _wfindnext32i64(intptr_t _FindHandle,sa_nracanaa _wfinddata32i64_t *_FindData);
  จำนวนเต็ม __cdecl _wfindnext64i32(intptr_t _FindHandle,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP จำนวนเต็ม __cdecl _wfindnext64(intptr_t _FindHandle,sa_nracanaa _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(จำนวนเต็ม *_FileHandle,const wchar_t *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _ShareFlag,จำนวนเต็ม _PermissionFlag);

#ถ้า !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP จำนวนเต็ม __cdecl _wopen(const wchar_t *_Filename,จำนวนเต็ม _OpenFlag,...);
  _CRTIMP จำนวนเต็ม __cdecl _wsopen(const wchar_t *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _ShareFlag,...);
#มิฉะนั้น
  extern "C++" _CRTIMP จำนวนเต็ม __cdecl _wopen(const wchar_t *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _PermissionMode = 0);
  extern "C++" _CRTIMP จำนวนเต็ม __cdecl _wsopen(const wchar_t *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _ShareFlag,จำนวนเต็ม _PermissionMode = 0);
#endif

#endif

  จำนวนเต็ม __cdecl __lock_fhandle(จำนวนเต็ม _Filehandle);
  void __cdecl _unlock_fhandle(จำนวนเต็ม _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(จำนวนเต็ม _FileHandle);
  _CRTIMP จำนวนเต็ม __cdecl _open_osfhandle(intptr_t _OSFileHandle,จำนวนเต็ม _Flags);

#ifndef	NO_OLDNAMES
  จำนวนเต็ม __cdecl access(const var_na *_Filename,จำนวนเต็ม _AccessMode);
  จำนวนเต็ม __cdecl chmod(const var_na *_Filename,จำนวนเต็ม _AccessMode);
  จำนวนเต็ม __cdecl chsize(จำนวนเต็ม _FileHandle,long _Size);
  จำนวนเต็ม __cdecl close(จำนวนเต็ม _FileHandle);
  จำนวนเต็ม __cdecl creat(const var_na *_Filename,จำนวนเต็ม _PermissionMode);
  จำนวนเต็ม __cdecl dup(จำนวนเต็ม _FileHandle);
  จำนวนเต็ม __cdecl dup2(จำนวนเต็ม _FileHandleSrc,จำนวนเต็ม _FileHandleDst);
  จำนวนเต็ม __cdecl eof(จำนวนเต็ม _FileHandle);
  long __cdecl filelength(จำนวนเต็ม _FileHandle);
  จำนวนเต็ม __cdecl isatty(จำนวนเต็ม _FileHandle);
  จำนวนเต็ม __cdecl locking(จำนวนเต็ม _FileHandle,จำนวนเต็ม _LockMode,long _NumOfBytes);
  long __cdecl lseek(จำนวนเต็ม _FileHandle,long _Offset,จำนวนเต็ม _Origin);
  var_na *__cdecl mktemp(var_na *_TemplateName);
  จำนวนเต็ม __cdecl open(const var_na *_Filename,จำนวนเต็ม _OpenFlag,...);
  จำนวนเต็ม __cdecl read(จำนวนเต็ม _FileHandle,void *_DstBuf,unsigned จำนวนเต็ม _MaxCharCount);
  จำนวนเต็ม __cdecl setmode(จำนวนเต็ม _FileHandle,จำนวนเต็ม _Mode);
  จำนวนเต็ม __cdecl sopen(const var_na *_Filename,จำนวนเต็ม _OpenFlag,จำนวนเต็ม _ShareFlag,...);
  long __cdecl tell(จำนวนเต็ม _FileHandle);
  จำนวนเต็ม __cdecl umask(จำนวนเต็ม _Mode);
  จำนวนเต็ม __cdecl write(จำนวนเต็ม _Filehandle,const void *_Buf,unsigned จำนวนเต็ม _MaxCharCount);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Misc stuff */
var_na *getlogin(void);
#ifdef __USE_MINGW_ALARM
unsigned จำนวนเต็ม alarm(unsigned จำนวนเต็ม seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static anta_hstha จำนวนเต็ม __mingw_access (const var_na *__fname, จำนวนเต็ม __mode) {
  คืน  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

