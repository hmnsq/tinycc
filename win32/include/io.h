
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

_CRTIMP var_na* __cdecl _getcwd (var_na*, ចំនួនគត់);
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
#បើមិនដូច្នេះ
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#បើមិនដូច្នេះ
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
#បើមិនដូច្នេះ
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
#ប្រសិនបើ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned ចំនួនគត់ size_t __attribute__ ((mode (DI)));
#បើមិនដូច្នេះ
  typedef unsigned __int64 size_t;
#endif
#បើមិនដូច្នេះ
  typedef unsigned ចំនួនគត់ size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ប្រសិនបើ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef ចំនួនគត់ ssize_t __attribute__ ((mode (DI)));
#បើមិនដូច្នេះ
  typedef __int64 ssize_t;
#endif
#បើមិនដូច្នេះ
  typedef ចំនួនគត់ ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#ប្រសិនបើ !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#ប្រសិនបើ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef ចំនួនគត់ _off64_t __attribute__ ((mode (DI)));
#ប្រសិនបើ !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef ចំនួនគត់ off64_t __attribute__ ((mode (DI)));
#endif
#បើមិនដូច្នេះ
  typedef long long _off64_t;
#ប្រសិនបើ !defined(NO_OLDNAMES) || defined(_POSIX)
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

  _CRTIMP ចំនួនគត់ __cdecl _access(const var_na *_Filename,ចំនួនគត់ _AccessMode);
  _CRTIMP ចំនួនគត់ __cdecl _chmod(const var_na *_Filename,ចំនួនគត់ _Mode);
  _CRTIMP ចំនួនគត់ __cdecl _chsize(ចំនួនគត់ _FileHandle,long _Size);
  _CRTIMP ចំនួនគត់ __cdecl _close(ចំនួនគត់ _FileHandle);
  _CRTIMP ចំនួនគត់ __cdecl _commit(ចំនួនគត់ _FileHandle);
  _CRTIMP ចំនួនគត់ __cdecl _creat(const var_na *_Filename,ចំនួនគត់ _PermissionMode);
  _CRTIMP ចំនួនគត់ __cdecl _dup(ចំនួនគត់ _FileHandle);
  _CRTIMP ចំនួនគត់ __cdecl _dup2(ចំនួនគត់ _FileHandleSrc,ចំនួនគត់ _FileHandleDst);
  _CRTIMP ចំនួនគត់ __cdecl _eof(ចំនួនគត់ _FileHandle);
  _CRTIMP long __cdecl _filelength(ចំនួនគត់ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const var_na *_Filename,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _findnext32(intptr_t _FindHandle,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP ចំនួនគត់ __cdecl _isatty(ចំនួនគត់ _FileHandle);
  _CRTIMP ចំនួនគត់ __cdecl _locking(ចំនួនគត់ _FileHandle,ចំនួនគត់ _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(ចំនួនគត់ _FileHandle,long _Offset,ចំនួនគត់ _Origin);
  _off64_t lseek64(ចំនួនគត់ fd,_off64_t offset, ចំនួនគត់ whence);
  _CRTIMP var_na *__cdecl _mktemp(var_na *_TemplateName);
  _CRTIMP ចំនួនគត់ __cdecl _pipe(ចំនួនគត់ *_PtHandles,unsigned ចំនួនគត់ _PipeSize,ចំនួនគត់ _TextMode);
  _CRTIMP ចំនួនគត់ __cdecl _read(ចំនួនគត់ _FileHandle,void *_DstBuf,unsigned ចំនួនគត់ _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ចំនួនគត់ __cdecl remove(const var_na *_Filename);
  ចំនួនគត់ __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP ចំនួនគត់ __cdecl _unlink(const var_na *_Filename);
#ifndef	NO_OLDNAMES
  ចំនួនគត់ __cdecl unlink(const var_na *_Filename);
#endif
#endif

  _CRTIMP ចំនួនគត់ __cdecl _setmode(ចំនួនគត់ _FileHandle,ចំនួនគត់ _Mode);
  _CRTIMP long __cdecl _tell(ចំនួនគត់ _FileHandle);
  _CRTIMP ចំនួនគត់ __cdecl _umask(ចំនួនគត់ _Mode);
  _CRTIMP ចំនួនគត់ __cdecl _write(ចំនួនគត់ _FileHandle,const void *_Buf,unsigned ចំនួនគត់ _MaxCharCount);

#ប្រសិនបើ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ចំនួនគត់ _FileHandle);
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
    ត្រឡប់ ret;
  }
  _CRTIMP ចំនួនគត់ __cdecl _findnext32i64(intptr_t _FindHandle,sa_nracanaa _finddata32i64_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _findnext64(intptr_t _FindHandle,sa_nracanaa __finddata64_t *_FindData);
  ចំនួនគត់ __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData);
  __CRT_INLINE ចំនួនគត់ __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData)
  {
    sa_nracanaa __finddata64_t fd;
    ចំនួនគត់ ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ត្រឡប់ ret;
  }
  __int64 __cdecl _lseeki64(ចំនួនគត់ _FileHandle,__int64 _Offset,ចំនួនគត់ _Origin);
  __int64 __cdecl _telli64(ចំនួនគត់ _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  ចំនួនគត់ __cdecl chdir (const var_na *);
  var_na *__cdecl getcwd (var_na *, ចំនួនគត់);
  ចំនួនគត់ __cdecl mkdir (const var_na *);
  var_na *__cdecl mktemp(var_na *);
  ចំនួនគត់ __cdecl rmdir (const var_na*);
  ចំនួនគត់ __cdecl chmod (const var_na *, ចំនួនគត់);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ចំនួនគត់ *_FileHandle,const var_na *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _ShareFlag,ចំនួនគត់ _PermissionMode);

#ifndef __cplusplus
  _CRTIMP ចំនួនគត់ __cdecl _open(const var_na *_Filename,ចំនួនគត់ _OpenFlag,...);
  _CRTIMP ចំនួនគត់ __cdecl _sopen(const var_na *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _ShareFlag,...);
#បើមិនដូច្នេះ
  extern "C++" _CRTIMP ចំនួនគត់ __cdecl _open(const var_na *_Filename,ចំនួនគត់ _Openflag,ចំនួនគត់ _PermissionMode = 0);
  extern "C++" _CRTIMP ចំនួនគត់ __cdecl _sopen(const var_na *_Filename,ចំនួនគត់ _Openflag,ចំនួនគត់ _ShareFlag,ចំនួនគត់ _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP ចំនួនគត់ __cdecl _waccess(const wchar_t *_Filename,ចំនួនគត់ _AccessMode);
  _CRTIMP ចំនួនគត់ __cdecl _wchmod(const wchar_t *_Filename,ចំនួនគត់ _Mode);
  _CRTIMP ចំនួនគត់ __cdecl _wcreat(const wchar_t *_Filename,ចំនួនគត់ _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _wfindnext32(intptr_t _FindHandle,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP ចំនួនគត់ __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ប្រសិនបើ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,sa_nracanaa _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,sa_nracanaa _wfinddata64_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _wfindnext32i64(intptr_t _FindHandle,sa_nracanaa _wfinddata32i64_t *_FindData);
  ចំនួនគត់ __cdecl _wfindnext64i32(intptr_t _FindHandle,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP ចំនួនគត់ __cdecl _wfindnext64(intptr_t _FindHandle,sa_nracanaa _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(ចំនួនគត់ *_FileHandle,const wchar_t *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _ShareFlag,ចំនួនគត់ _PermissionFlag);

#ប្រសិនបើ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ចំនួនគត់ __cdecl _wopen(const wchar_t *_Filename,ចំនួនគត់ _OpenFlag,...);
  _CRTIMP ចំនួនគត់ __cdecl _wsopen(const wchar_t *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _ShareFlag,...);
#បើមិនដូច្នេះ
  extern "C++" _CRTIMP ចំនួនគត់ __cdecl _wopen(const wchar_t *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _PermissionMode = 0);
  extern "C++" _CRTIMP ចំនួនគត់ __cdecl _wsopen(const wchar_t *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _ShareFlag,ចំនួនគត់ _PermissionMode = 0);
#endif

#endif

  ចំនួនគត់ __cdecl __lock_fhandle(ចំនួនគត់ _Filehandle);
  void __cdecl _unlock_fhandle(ចំនួនគត់ _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ចំនួនគត់ _FileHandle);
  _CRTIMP ចំនួនគត់ __cdecl _open_osfhandle(intptr_t _OSFileHandle,ចំនួនគត់ _Flags);

#ifndef	NO_OLDNAMES
  ចំនួនគត់ __cdecl access(const var_na *_Filename,ចំនួនគត់ _AccessMode);
  ចំនួនគត់ __cdecl chmod(const var_na *_Filename,ចំនួនគត់ _AccessMode);
  ចំនួនគត់ __cdecl chsize(ចំនួនគត់ _FileHandle,long _Size);
  ចំនួនគត់ __cdecl close(ចំនួនគត់ _FileHandle);
  ចំនួនគត់ __cdecl creat(const var_na *_Filename,ចំនួនគត់ _PermissionMode);
  ចំនួនគត់ __cdecl dup(ចំនួនគត់ _FileHandle);
  ចំនួនគត់ __cdecl dup2(ចំនួនគត់ _FileHandleSrc,ចំនួនគត់ _FileHandleDst);
  ចំនួនគត់ __cdecl eof(ចំនួនគត់ _FileHandle);
  long __cdecl filelength(ចំនួនគត់ _FileHandle);
  ចំនួនគត់ __cdecl isatty(ចំនួនគត់ _FileHandle);
  ចំនួនគត់ __cdecl locking(ចំនួនគត់ _FileHandle,ចំនួនគត់ _LockMode,long _NumOfBytes);
  long __cdecl lseek(ចំនួនគត់ _FileHandle,long _Offset,ចំនួនគត់ _Origin);
  var_na *__cdecl mktemp(var_na *_TemplateName);
  ចំនួនគត់ __cdecl open(const var_na *_Filename,ចំនួនគត់ _OpenFlag,...);
  ចំនួនគត់ __cdecl read(ចំនួនគត់ _FileHandle,void *_DstBuf,unsigned ចំនួនគត់ _MaxCharCount);
  ចំនួនគត់ __cdecl setmode(ចំនួនគត់ _FileHandle,ចំនួនគត់ _Mode);
  ចំនួនគត់ __cdecl sopen(const var_na *_Filename,ចំនួនគត់ _OpenFlag,ចំនួនគត់ _ShareFlag,...);
  long __cdecl tell(ចំនួនគត់ _FileHandle);
  ចំនួនគត់ __cdecl umask(ចំនួនគត់ _Mode);
  ចំនួនគត់ __cdecl write(ចំនួនគត់ _Filehandle,const void *_Buf,unsigned ចំនួនគត់ _MaxCharCount);
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
unsigned ចំនួនគត់ alarm(unsigned ចំនួនគត់ seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static anta_hstha ចំនួនគត់ __mingw_access (const var_na *__fname, ចំនួនគត់ __mode) {
  ត្រឡប់  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

