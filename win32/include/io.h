
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

_CRTIMP var_na* __cdecl _getcwd (var_na*, පූර්ණ_සංඛ්‍යා);
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
#නැතහොත්
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#නැතහොත්
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
#නැතහොත්
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
#නම් defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned පූර්ණ_සංඛ්‍යා size_t __attribute__ ((mode (DI)));
#නැතහොත්
  typedef unsigned __int64 size_t;
#endif
#නැතහොත්
  typedef unsigned පූර්ණ_සංඛ්‍යා size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#නම් defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef පූර්ණ_සංඛ්‍යා ssize_t __attribute__ ((mode (DI)));
#නැතහොත්
  typedef __int64 ssize_t;
#endif
#නැතහොත්
  typedef පූර්ණ_සංඛ්‍යා ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#නම් !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#නම් defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef පූර්ණ_සංඛ්‍යා _off64_t __attribute__ ((mode (DI)));
#නම් !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef පූර්ණ_සංඛ්‍යා off64_t __attribute__ ((mode (DI)));
#endif
#නැතහොත්
  typedef long long _off64_t;
#නම් !defined(NO_OLDNAMES) || defined(_POSIX)
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

  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _access(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _AccessMode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _chmod(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _Mode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _chsize(පූර්ණ_සංඛ්‍යා _FileHandle,long _Size);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _close(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _commit(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _creat(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _PermissionMode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _dup(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _dup2(පූර්ණ_සංඛ්‍යා _FileHandleSrc,පූර්ණ_සංඛ්‍යා _FileHandleDst);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _eof(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP long __cdecl _filelength(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const var_na *_Filename,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _findnext32(intptr_t _FindHandle,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _isatty(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _locking(පූර්ණ_සංඛ්‍යා _FileHandle,පූර්ණ_සංඛ්‍යා _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(පූර්ණ_සංඛ්‍යා _FileHandle,long _Offset,පූර්ණ_සංඛ්‍යා _Origin);
  _off64_t lseek64(පූර්ණ_සංඛ්‍යා fd,_off64_t offset, පූර්ණ_සංඛ්‍යා whence);
  _CRTIMP var_na *__cdecl _mktemp(var_na *_TemplateName);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _pipe(පූර්ණ_සංඛ්‍යා *_PtHandles,unsigned පූර්ණ_සංඛ්‍යා _PipeSize,පූර්ණ_සංඛ්‍යා _TextMode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _read(පූර්ණ_සංඛ්‍යා _FileHandle,void *_DstBuf,unsigned පූර්ණ_සංඛ්‍යා _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  පූර්ණ_සංඛ්‍යා __cdecl remove(const var_na *_Filename);
  පූර්ණ_සංඛ්‍යා __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _unlink(const var_na *_Filename);
#ifndef	NO_OLDNAMES
  පූර්ණ_සංඛ්‍යා __cdecl unlink(const var_na *_Filename);
#endif
#endif

  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _setmode(පූර්ණ_සංඛ්‍යා _FileHandle,පූර්ණ_සංඛ්‍යා _Mode);
  _CRTIMP long __cdecl _tell(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _umask(පූර්ණ_සංඛ්‍යා _Mode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _write(පූර්ණ_සංඛ්‍යා _FileHandle,const void *_Buf,unsigned පූර්ණ_සංඛ්‍යා _MaxCharCount);

#නම් _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(පූර්ණ_සංඛ්‍යා _FileHandle);
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
    ආපසු ret;
  }
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _findnext32i64(intptr_t _FindHandle,sa_nracanaa _finddata32i64_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _findnext64(intptr_t _FindHandle,sa_nracanaa __finddata64_t *_FindData);
  පූර්ණ_සංඛ්‍යා __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData);
  __CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData)
  {
    sa_nracanaa __finddata64_t fd;
    පූර්ණ_සංඛ්‍යා ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ආපසු ret;
  }
  __int64 __cdecl _lseeki64(පූර්ණ_සංඛ්‍යා _FileHandle,__int64 _Offset,පූර්ණ_සංඛ්‍යා _Origin);
  __int64 __cdecl _telli64(පූර්ණ_සංඛ්‍යා _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  පූර්ණ_සංඛ්‍යා __cdecl chdir (const var_na *);
  var_na *__cdecl getcwd (var_na *, පූර්ණ_සංඛ්‍යා);
  පූර්ණ_සංඛ්‍යා __cdecl mkdir (const var_na *);
  var_na *__cdecl mktemp(var_na *);
  පූර්ණ_සංඛ්‍යා __cdecl rmdir (const var_na*);
  පූර්ණ_සංඛ්‍යා __cdecl chmod (const var_na *, පූර්ණ_සංඛ්‍යා);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(පූර්ණ_සංඛ්‍යා *_FileHandle,const var_na *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _ShareFlag,පූර්ණ_සංඛ්‍යා _PermissionMode);

#ifndef __cplusplus
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _open(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _sopen(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _ShareFlag,...);
#නැතහොත්
  extern "C++" _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _open(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _Openflag,පූර්ණ_සංඛ්‍යා _PermissionMode = 0);
  extern "C++" _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _sopen(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _Openflag,පූර්ණ_සංඛ්‍යා _ShareFlag,පූර්ණ_සංඛ්‍යා _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _waccess(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _AccessMode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wchmod(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _Mode);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wcreat(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wfindnext32(intptr_t _FindHandle,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#නම් _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,sa_nracanaa _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,sa_nracanaa _wfinddata64_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wfindnext32i64(intptr_t _FindHandle,sa_nracanaa _wfinddata32i64_t *_FindData);
  පූර්ණ_සංඛ්‍යා __cdecl _wfindnext64i32(intptr_t _FindHandle,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wfindnext64(intptr_t _FindHandle,sa_nracanaa _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(පූර්ණ_සංඛ්‍යා *_FileHandle,const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _ShareFlag,පූර්ණ_සංඛ්‍යා _PermissionFlag);

#නම් !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wopen(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wsopen(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _ShareFlag,...);
#නැතහොත්
  extern "C++" _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wopen(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _PermissionMode = 0);
  extern "C++" _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wsopen(const wchar_t *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _ShareFlag,පූර්ණ_සංඛ්‍යා _PermissionMode = 0);
#endif

#endif

  පූර්ණ_සංඛ්‍යා __cdecl __lock_fhandle(පූර්ණ_සංඛ්‍යා _Filehandle);
  void __cdecl _unlock_fhandle(පූර්ණ_සංඛ්‍යා _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(පූර්ණ_සංඛ්‍යා _FileHandle);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _open_osfhandle(intptr_t _OSFileHandle,පූර්ණ_සංඛ්‍යා _Flags);

#ifndef	NO_OLDNAMES
  පූර්ණ_සංඛ්‍යා __cdecl access(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _AccessMode);
  පූර්ණ_සංඛ්‍යා __cdecl chmod(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _AccessMode);
  පූර්ණ_සංඛ්‍යා __cdecl chsize(පූර්ණ_සංඛ්‍යා _FileHandle,long _Size);
  පූර්ණ_සංඛ්‍යා __cdecl close(පූර්ණ_සංඛ්‍යා _FileHandle);
  පූර්ණ_සංඛ්‍යා __cdecl creat(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _PermissionMode);
  පූර්ණ_සංඛ්‍යා __cdecl dup(පූර්ණ_සංඛ්‍යා _FileHandle);
  පූර්ණ_සංඛ්‍යා __cdecl dup2(පූර්ණ_සංඛ්‍යා _FileHandleSrc,පූර්ණ_සංඛ්‍යා _FileHandleDst);
  පූර්ණ_සංඛ්‍යා __cdecl eof(පූර්ණ_සංඛ්‍යා _FileHandle);
  long __cdecl filelength(පූර්ණ_සංඛ්‍යා _FileHandle);
  පූර්ණ_සංඛ්‍යා __cdecl isatty(පූර්ණ_සංඛ්‍යා _FileHandle);
  පූර්ණ_සංඛ්‍යා __cdecl locking(පූර්ණ_සංඛ්‍යා _FileHandle,පූර්ණ_සංඛ්‍යා _LockMode,long _NumOfBytes);
  long __cdecl lseek(පූර්ණ_සංඛ්‍යා _FileHandle,long _Offset,පූර්ණ_සංඛ්‍යා _Origin);
  var_na *__cdecl mktemp(var_na *_TemplateName);
  පූර්ණ_සංඛ්‍යා __cdecl open(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,...);
  පූර්ණ_සංඛ්‍යා __cdecl read(පූර්ණ_සංඛ්‍යා _FileHandle,void *_DstBuf,unsigned පූර්ණ_සංඛ්‍යා _MaxCharCount);
  පූර්ණ_සංඛ්‍යා __cdecl setmode(පූර්ණ_සංඛ්‍යා _FileHandle,පූර්ණ_සංඛ්‍යා _Mode);
  පූර්ණ_සංඛ්‍යා __cdecl sopen(const var_na *_Filename,පූර්ණ_සංඛ්‍යා _OpenFlag,පූර්ණ_සංඛ්‍යා _ShareFlag,...);
  long __cdecl tell(පූර්ණ_සංඛ්‍යා _FileHandle);
  පූර්ණ_සංඛ්‍යා __cdecl umask(පූර්ණ_සංඛ්‍යා _Mode);
  පූර්ණ_සංඛ්‍යා __cdecl write(පූර්ණ_සංඛ්‍යා _Filehandle,const void *_Buf,unsigned පූර්ණ_සංඛ්‍යා _MaxCharCount);
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
unsigned පූර්ණ_සංඛ්‍යා alarm(unsigned පූර්ණ_සංඛ්‍යා seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static anta_hstha පූර්ණ_සංඛ්‍යා __mingw_access (const var_na *__fname, පූර්ණ_සංඛ්‍යා __mode) {
  ආපසු  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

