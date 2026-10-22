
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

_CRTIMP char* __cdecl _getcwd (char*, цео);
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
#инако
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#инако
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
#инако
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
  typedef unsigned цео size_t __attribute__ ((mode (DI)));
#инако
  typedef unsigned __int64 size_t;
#endif
#инако
  typedef unsigned цео size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ако defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef цео ssize_t __attribute__ ((mode (DI)));
#инако
  typedef __int64 ssize_t;
#endif
#инако
  typedef цео ssize_t;
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
  typedef цео _off64_t __attribute__ ((mode (DI)));
#ако !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef цео off64_t __attribute__ ((mode (DI)));
#endif
#инако
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

  _CRTIMP цео __cdecl _access(const char *_Filename,цео _AccessMode);
  _CRTIMP цео __cdecl _chmod(const char *_Filename,цео _Mode);
  _CRTIMP цео __cdecl _chsize(цео _FileHandle,long _Size);
  _CRTIMP цео __cdecl _close(цео _FileHandle);
  _CRTIMP цео __cdecl _commit(цео _FileHandle);
  _CRTIMP цео __cdecl _creat(const char *_Filename,цео _PermissionMode);
  _CRTIMP цео __cdecl _dup(цео _FileHandle);
  _CRTIMP цео __cdecl _dup2(цео _FileHandleSrc,цео _FileHandleDst);
  _CRTIMP цео __cdecl _eof(цео _FileHandle);
  _CRTIMP long __cdecl _filelength(цео _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const char *_Filename,struct _finddata32_t *_FindData);
  _CRTIMP цео __cdecl _findnext32(intptr_t _FindHandle,struct _finddata32_t *_FindData);
  _CRTIMP цео __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP цео __cdecl _isatty(цео _FileHandle);
  _CRTIMP цео __cdecl _locking(цео _FileHandle,цео _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(цео _FileHandle,long _Offset,цео _Origin);
  _off64_t lseek64(цео fd,_off64_t offset, цео whence);
  _CRTIMP char *__cdecl _mktemp(char *_TemplateName);
  _CRTIMP цео __cdecl _pipe(цео *_PtHandles,unsigned цео _PipeSize,цео _TextMode);
  _CRTIMP цео __cdecl _read(цео _FileHandle,void *_DstBuf,unsigned цео _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  цео __cdecl remove(const char *_Filename);
  цео __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  _CRTIMP цео __cdecl _unlink(const char *_Filename);
#ifndef	NO_OLDNAMES
  цео __cdecl unlink(const char *_Filename);
#endif
#endif

  _CRTIMP цео __cdecl _setmode(цео _FileHandle,цео _Mode);
  _CRTIMP long __cdecl _tell(цео _FileHandle);
  _CRTIMP цео __cdecl _umask(цео _Mode);
  _CRTIMP цео __cdecl _write(цео _FileHandle,const void *_Buf,unsigned цео _MaxCharCount);

#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(цео _FileHandle);
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
    врати ret;
  }
  _CRTIMP цео __cdecl _findnext32i64(intptr_t _FindHandle,struct _finddata32i64_t *_FindData);
  _CRTIMP цео __cdecl _findnext64(intptr_t _FindHandle,struct __finddata64_t *_FindData);
  цео __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData);
  __CRT_INLINE цео __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData)
  {
    struct __finddata64_t fd;
    цео ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    врати ret;
  }
  __int64 __cdecl _lseeki64(цео _FileHandle,__int64 _Offset,цео _Origin);
  __int64 __cdecl _telli64(цео _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  цео __cdecl chdir (const char *);
  char *__cdecl getcwd (char *, цео);
  цео __cdecl mkdir (const char *);
  char *__cdecl mktemp(char *);
  цео __cdecl rmdir (const char*);
  цео __cdecl chmod (const char *, цео);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(цео *_FileHandle,const char *_Filename,цео _OpenFlag,цео _ShareFlag,цео _PermissionMode);

#ifndef __cplusplus
  _CRTIMP цео __cdecl _open(const char *_Filename,цео _OpenFlag,...);
  _CRTIMP цео __cdecl _sopen(const char *_Filename,цео _OpenFlag,цео _ShareFlag,...);
#инако
  extern "C++" _CRTIMP цео __cdecl _open(const char *_Filename,цео _Openflag,цео _PermissionMode = 0);
  extern "C++" _CRTIMP цео __cdecl _sopen(const char *_Filename,цео _Openflag,цео _ShareFlag,цео _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP цео __cdecl _waccess(const wchar_t *_Filename,цео _AccessMode);
  _CRTIMP цео __cdecl _wchmod(const wchar_t *_Filename,цео _Mode);
  _CRTIMP цео __cdecl _wcreat(const wchar_t *_Filename,цео _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP цео __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP цео __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP цео __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ако _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP цео __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  цео __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP цео __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(цео *_FileHandle,const wchar_t *_Filename,цео _OpenFlag,цео _ShareFlag,цео _PermissionFlag);

#ако !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP цео __cdecl _wopen(const wchar_t *_Filename,цео _OpenFlag,...);
  _CRTIMP цео __cdecl _wsopen(const wchar_t *_Filename,цео _OpenFlag,цео _ShareFlag,...);
#инако
  extern "C++" _CRTIMP цео __cdecl _wopen(const wchar_t *_Filename,цео _OpenFlag,цео _PermissionMode = 0);
  extern "C++" _CRTIMP цео __cdecl _wsopen(const wchar_t *_Filename,цео _OpenFlag,цео _ShareFlag,цео _PermissionMode = 0);
#endif

#endif

  цео __cdecl __lock_fhandle(цео _Filehandle);
  void __cdecl _unlock_fhandle(цео _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(цео _FileHandle);
  _CRTIMP цео __cdecl _open_osfhandle(intptr_t _OSFileHandle,цео _Flags);

#ifndef	NO_OLDNAMES
  цео __cdecl access(const char *_Filename,цео _AccessMode);
  цео __cdecl chmod(const char *_Filename,цео _AccessMode);
  цео __cdecl chsize(цео _FileHandle,long _Size);
  цео __cdecl close(цео _FileHandle);
  цео __cdecl creat(const char *_Filename,цео _PermissionMode);
  цео __cdecl dup(цео _FileHandle);
  цео __cdecl dup2(цео _FileHandleSrc,цео _FileHandleDst);
  цео __cdecl eof(цео _FileHandle);
  long __cdecl filelength(цео _FileHandle);
  цео __cdecl isatty(цео _FileHandle);
  цео __cdecl locking(цео _FileHandle,цео _LockMode,long _NumOfBytes);
  long __cdecl lseek(цео _FileHandle,long _Offset,цео _Origin);
  char *__cdecl mktemp(char *_TemplateName);
  цео __cdecl open(const char *_Filename,цео _OpenFlag,...);
  цео __cdecl read(цео _FileHandle,void *_DstBuf,unsigned цео _MaxCharCount);
  цео __cdecl setmode(цео _FileHandle,цео _Mode);
  цео __cdecl sopen(const char *_Filename,цео _OpenFlag,цео _ShareFlag,...);
  long __cdecl tell(цео _FileHandle);
  цео __cdecl umask(цео _Mode);
  цео __cdecl write(цео _Filehandle,const void *_Buf,unsigned цео _MaxCharCount);
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
unsigned цео alarm(unsigned цео seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static inline цео __mingw_access (const char *__fname, цео __mode) {
  врати  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

