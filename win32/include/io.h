
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

_CRTIMP char* __cdecl _getcwd (char*, целое);
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
#если defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned целое size_t __attribute__ ((mode (DI)));
#иначе
  typedef unsigned __int64 size_t;
#endif
#иначе
  typedef unsigned целое size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#если defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef целое ssize_t __attribute__ ((mode (DI)));
#иначе
  typedef __int64 ssize_t;
#endif
#иначе
  typedef целое ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#если !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#если defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef целое _off64_t __attribute__ ((mode (DI)));
#если !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef целое off64_t __attribute__ ((mode (DI)));
#endif
#иначе
  typedef long long _off64_t;
#если !defined(NO_OLDNAMES) || defined(_POSIX)
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

  _CRTIMP целое __cdecl _access(const char *_Filename,целое _AccessMode);
  _CRTIMP целое __cdecl _chmod(const char *_Filename,целое _Mode);
  _CRTIMP целое __cdecl _chsize(целое _FileHandle,long _Size);
  _CRTIMP целое __cdecl _close(целое _FileHandle);
  _CRTIMP целое __cdecl _commit(целое _FileHandle);
  _CRTIMP целое __cdecl _creat(const char *_Filename,целое _PermissionMode);
  _CRTIMP целое __cdecl _dup(целое _FileHandle);
  _CRTIMP целое __cdecl _dup2(целое _FileHandleSrc,целое _FileHandleDst);
  _CRTIMP целое __cdecl _eof(целое _FileHandle);
  _CRTIMP long __cdecl _filelength(целое _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const char *_Filename,struct _finddata32_t *_FindData);
  _CRTIMP целое __cdecl _findnext32(intptr_t _FindHandle,struct _finddata32_t *_FindData);
  _CRTIMP целое __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP целое __cdecl _isatty(целое _FileHandle);
  _CRTIMP целое __cdecl _locking(целое _FileHandle,целое _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(целое _FileHandle,long _Offset,целое _Origin);
  _off64_t lseek64(целое fd,_off64_t offset, целое whence);
  _CRTIMP char *__cdecl _mktemp(char *_TemplateName);
  _CRTIMP целое __cdecl _pipe(целое *_PtHandles,unsigned целое _PipeSize,целое _TextMode);
  _CRTIMP целое __cdecl _read(целое _FileHandle,void *_DstBuf,unsigned целое _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  целое __cdecl remove(const char *_Filename);
  целое __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  _CRTIMP целое __cdecl _unlink(const char *_Filename);
#ifndef	NO_OLDNAMES
  целое __cdecl unlink(const char *_Filename);
#endif
#endif

  _CRTIMP целое __cdecl _setmode(целое _FileHandle,целое _Mode);
  _CRTIMP long __cdecl _tell(целое _FileHandle);
  _CRTIMP целое __cdecl _umask(целое _Mode);
  _CRTIMP целое __cdecl _write(целое _FileHandle,const void *_Buf,unsigned целое _MaxCharCount);

#если _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(целое _FileHandle);
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
    вернуть ret;
  }
  _CRTIMP целое __cdecl _findnext32i64(intptr_t _FindHandle,struct _finddata32i64_t *_FindData);
  _CRTIMP целое __cdecl _findnext64(intptr_t _FindHandle,struct __finddata64_t *_FindData);
  целое __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData);
  __CRT_INLINE целое __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData)
  {
    struct __finddata64_t fd;
    целое ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    вернуть ret;
  }
  __int64 __cdecl _lseeki64(целое _FileHandle,__int64 _Offset,целое _Origin);
  __int64 __cdecl _telli64(целое _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  целое __cdecl chdir (const char *);
  char *__cdecl getcwd (char *, целое);
  целое __cdecl mkdir (const char *);
  char *__cdecl mktemp(char *);
  целое __cdecl rmdir (const char*);
  целое __cdecl chmod (const char *, целое);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(целое *_FileHandle,const char *_Filename,целое _OpenFlag,целое _ShareFlag,целое _PermissionMode);

#ifndef __cplusplus
  _CRTIMP целое __cdecl _open(const char *_Filename,целое _OpenFlag,...);
  _CRTIMP целое __cdecl _sopen(const char *_Filename,целое _OpenFlag,целое _ShareFlag,...);
#иначе
  extern "C++" _CRTIMP целое __cdecl _open(const char *_Filename,целое _Openflag,целое _PermissionMode = 0);
  extern "C++" _CRTIMP целое __cdecl _sopen(const char *_Filename,целое _Openflag,целое _ShareFlag,целое _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP целое __cdecl _waccess(const wchar_t *_Filename,целое _AccessMode);
  _CRTIMP целое __cdecl _wchmod(const wchar_t *_Filename,целое _Mode);
  _CRTIMP целое __cdecl _wcreat(const wchar_t *_Filename,целое _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,struct _wfinddata32_t *_FindData);
  _CRTIMP целое __cdecl _wfindnext32(intptr_t _FindHandle,struct _wfinddata32_t *_FindData);
  _CRTIMP целое __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP целое __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#если _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,struct _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,struct _wfinddata64_t *_FindData);
  _CRTIMP целое __cdecl _wfindnext32i64(intptr_t _FindHandle,struct _wfinddata32i64_t *_FindData);
  целое __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData);
  _CRTIMP целое __cdecl _wfindnext64(intptr_t _FindHandle,struct _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(целое *_FileHandle,const wchar_t *_Filename,целое _OpenFlag,целое _ShareFlag,целое _PermissionFlag);

#если !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP целое __cdecl _wopen(const wchar_t *_Filename,целое _OpenFlag,...);
  _CRTIMP целое __cdecl _wsopen(const wchar_t *_Filename,целое _OpenFlag,целое _ShareFlag,...);
#иначе
  extern "C++" _CRTIMP целое __cdecl _wopen(const wchar_t *_Filename,целое _OpenFlag,целое _PermissionMode = 0);
  extern "C++" _CRTIMP целое __cdecl _wsopen(const wchar_t *_Filename,целое _OpenFlag,целое _ShareFlag,целое _PermissionMode = 0);
#endif

#endif

  целое __cdecl __lock_fhandle(целое _Filehandle);
  void __cdecl _unlock_fhandle(целое _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(целое _FileHandle);
  _CRTIMP целое __cdecl _open_osfhandle(intptr_t _OSFileHandle,целое _Flags);

#ifndef	NO_OLDNAMES
  целое __cdecl access(const char *_Filename,целое _AccessMode);
  целое __cdecl chmod(const char *_Filename,целое _AccessMode);
  целое __cdecl chsize(целое _FileHandle,long _Size);
  целое __cdecl close(целое _FileHandle);
  целое __cdecl creat(const char *_Filename,целое _PermissionMode);
  целое __cdecl dup(целое _FileHandle);
  целое __cdecl dup2(целое _FileHandleSrc,целое _FileHandleDst);
  целое __cdecl eof(целое _FileHandle);
  long __cdecl filelength(целое _FileHandle);
  целое __cdecl isatty(целое _FileHandle);
  целое __cdecl locking(целое _FileHandle,целое _LockMode,long _NumOfBytes);
  long __cdecl lseek(целое _FileHandle,long _Offset,целое _Origin);
  char *__cdecl mktemp(char *_TemplateName);
  целое __cdecl open(const char *_Filename,целое _OpenFlag,...);
  целое __cdecl read(целое _FileHandle,void *_DstBuf,unsigned целое _MaxCharCount);
  целое __cdecl setmode(целое _FileHandle,целое _Mode);
  целое __cdecl sopen(const char *_Filename,целое _OpenFlag,целое _ShareFlag,...);
  long __cdecl tell(целое _FileHandle);
  целое __cdecl umask(целое _Mode);
  целое __cdecl write(целое _Filehandle,const void *_Buf,unsigned целое _MaxCharCount);
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
unsigned целое alarm(unsigned целое seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static inline целое __mingw_access (const char *__fname, целое __mode) {
  вернуть  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

