
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

_CRTIMP char* __cdecl _getcwd (char*, цяло);
#ifndef _FSIZE_T_DEFINED
  typedef unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  struct _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    char name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  struct _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    char name[260];
  };

  struct _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    char name[260];
  };

  struct __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    char name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#иначе
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#иначе
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

  struct _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  struct _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  struct _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  struct _wfinddata64_t {
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
#иначе
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
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned цяло size_t __attribute__ ((mode (DI)));
#иначе
  typedef unsigned __int64 size_t;
#endif
#иначе
  typedef unsigned цяло size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef цяло ssize_t __attribute__ ((mode (DI)));
#иначе
  typedef __int64 ssize_t;
#endif
#иначе
  typedef цяло ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#ако !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef цяло _off64_t __attribute__ ((mode (DI)));
#ако !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef цяло off64_t __attribute__ ((mode (DI)));
#endif
#иначе
  typedef long long _off64_t;
#ако !defined(NO_OLDNAMES) || defined(_POSIX)
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

  _CRTIMP цяло __cdecl _access(const char *_Filename,цяло _AccessMode);
  _CRTIMP цяло __cdecl _chmod(const char *_Filename,цяло _Mode);
  _CRTIMP цяло __cdecl _chsize(цяло _FileHandle,long _Size);
  _CRTIMP цяло __cdecl _close(цяло _FileHandle);
  _CRTIMP цяло __cdecl _commit(цяло _FileHandle);
  _CRTIMP цяло __cdecl _creat(const char *_Filename,цяло _PermissionMode);
  _CRTIMP цяло __cdecl _dup(цяло _FileHandle);
  _CRTIMP цяло __cdecl _dup2(цяло _FileHandleSrc,цяло _FileHandleDst);
  _CRTIMP цяло __cdecl _eof(цяло _FileHandle);
  _CRTIMP long __cdecl _filelength(цяло _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const char *_Filename,struct _finddata32_t *_FindData);
  _CRTIMP цяло __cdecl _findnext32(intptr_t _FindHandle,struct _finddata32_t *_FindData);
  _CRTIMP цяло __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP цяло __cdecl _isatty(цяло _FileHandle);
  _CRTIMP цяло __cdecl _locking(цяло _FileHandle,цяло _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(цяло _FileHandle,long _Offset,цяло _Origin);
  _off64_t lseek64(цяло fd,_off64_t offset, цяло whence);
  _CRTIMP char *__cdecl _mktemp(char *_TemplateName);
  _CRTIMP цяло __cdecl _pipe(цяло *_PtHandles,unsigned цяло _PipeSize,цяло _TextMode);
  _CRTIMP цяло __cdecl _read(цяло _FileHandle,void *_DstBuf,unsigned цяло _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  цяло __cdecl remove(const char *_Filename);
  цяло __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  _CRTIMP цяло __cdecl _unlink(const char *_Filename);
#ifndef	NO_OLDNAMES
  цяло __cdecl unlink(const char *_Filename);
#endif
#endif

  _CRTIMP цяло __cdecl _setmode(цяло _FileHandle,цяло _Mode);
  _CRTIMP long __cdecl _tell(цяло _FileHandle);
  _CRTIMP цяло __cdecl _umask(цяло _Mode);
  _CRTIMP цяло __cdecl _write(цяло _FileHandle,const void *_Buf,unsigned цяло _MaxCharCount);

#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(цяло _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(const char *_Filename,struct _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(const char *_Filename,struct __finddata64_t *_FindData);
#ifdef __cplusplus
#include <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(const char *_Filename,struct _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(const char *_Filename,struct _finddata64i32_t *_FindData)
  {
    struct __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    върни ret;
  }
  _CRTIMP цяло __cdecl _findnext32i64(intptr_t _FindHandle,struct _finddata32i64_t *_FindData);
  _CRTIMP цяло __cdecl _findnext64(intptr_t _FindHandle,struct __finddata64_t *_FindData);
  цяло __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData);
  __CRT_INLINE цяло __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData)
  {
    struct __finddata64_t fd;
    цяло ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    върни ret;
  }
  __int64 __cdecl _lseeki64(цяло _FileHandle,__int64 _Offset,цяло _Origin);
  __int64 __cdecl _telli64(цяло _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  цяло __cdecl chdir (const char *);
  char *__cdecl getcwd (char *, цяло);
  цяло __cdecl mkdir (const char *);
  char *__cdecl mktemp(char *);
  цяло __cdecl rmdir (const char*);
  цяло __cdecl chmod (const char *, цяло);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(цяло *_FileHandle,const char *_Filename,цяло _OpenFlag,цяло _ShareFlag,цяло _PermissionMode);

#ifndef __cplusplus
  _CRTIMP цяло __cdecl _open(const char *_Filename,цяло _OpenFlag,...);
  _CRTIMP цяло __cdecl _sopen(const char *_Filename,цяло _OpenFlag,цяло _ShareFlag,...);
#иначе
  extern "C++" _CRTIMP цяло __cdecl _open(const char *_Filename,цяло _Openflag,цяло _PermissionMode = 0);
  extern "C++" _CRTIMP цяло __cdecl _sopen(const char *_Filename,цяло _Openflag,цяло _ShareFlag,цяло _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP цяло __cdecl _waccess(const wchar_t *_Filename,цяло _AccessMode);
  _CRTIMP цяло __cdecl _wchmod(const wchar_t *_Filename,цяло _Mode);
  _CRTIMP цяло __cdecl _wcreat(const wchar_t *_Filename,цяло _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP цяло __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP цяло __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP цяло __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP цяло __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  цяло __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP цяло __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(цяло *_FileHandle,const wchar_t *_Filename,цяло _OpenFlag,цяло _ShareFlag,цяло _PermissionFlag);

#ако !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP цяло __cdecl _wopen(const wchar_t *_Filename,цяло _OpenFlag,...);
  _CRTIMP цяло __cdecl _wsopen(const wchar_t *_Filename,цяло _OpenFlag,цяло _ShareFlag,...);
#иначе
  extern "C++" _CRTIMP цяло __cdecl _wopen(const wchar_t *_Filename,цяло _OpenFlag,цяло _PermissionMode = 0);
  extern "C++" _CRTIMP цяло __cdecl _wsopen(const wchar_t *_Filename,цяло _OpenFlag,цяло _ShareFlag,цяло _PermissionMode = 0);
#endif

#endif

  цяло __cdecl __lock_fhandle(цяло _Filehandle);
  void __cdecl _unlock_fhandle(цяло _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(цяло _FileHandle);
  _CRTIMP цяло __cdecl _open_osfhandle(intptr_t _OSFileHandle,цяло _Flags);

#ifndef	NO_OLDNAMES
  цяло __cdecl access(const char *_Filename,цяло _AccessMode);
  цяло __cdecl chmod(const char *_Filename,цяло _AccessMode);
  цяло __cdecl chsize(цяло _FileHandle,long _Size);
  цяло __cdecl close(цяло _FileHandle);
  цяло __cdecl creat(const char *_Filename,цяло _PermissionMode);
  цяло __cdecl dup(цяло _FileHandle);
  цяло __cdecl dup2(цяло _FileHandleSrc,цяло _FileHandleDst);
  цяло __cdecl eof(цяло _FileHandle);
  long __cdecl filelength(цяло _FileHandle);
  цяло __cdecl isatty(цяло _FileHandle);
  цяло __cdecl locking(цяло _FileHandle,цяло _LockMode,long _NumOfBytes);
  long __cdecl lseek(цяло _FileHandle,long _Offset,цяло _Origin);
  char *__cdecl mktemp(char *_TemplateName);
  цяло __cdecl open(const char *_Filename,цяло _OpenFlag,...);
  цяло __cdecl read(цяло _FileHandle,void *_DstBuf,unsigned цяло _MaxCharCount);
  цяло __cdecl setmode(цяло _FileHandle,цяло _Mode);
  цяло __cdecl sopen(const char *_Filename,цяло _OpenFlag,цяло _ShareFlag,...);
  long __cdecl tell(цяло _FileHandle);
  цяло __cdecl umask(цяло _Mode);
  цяло __cdecl write(цяло _Filehandle,const void *_Buf,unsigned цяло _MaxCharCount);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Misc stuff */
char *getlogin(void);
#ifdef __USE_MINGW_ALARM
unsigned цяло alarm(unsigned цяло seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static inline цяло __mingw_access (const char *__fname, цяло __mode) {
  върни  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

