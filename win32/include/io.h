
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

_CRTIMP var_na* __cdecl _getcwd (var_na*, ຈຳນວນເຕັມ);
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
#ບໍ່ດັ່ງນັ້ນ
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#ບໍ່ດັ່ງນັ້ນ
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
#ບໍ່ດັ່ງນັ້ນ
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
#ຖ້າ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned ຈຳນວນເຕັມ size_t __attribute__ ((mode (DI)));
#ບໍ່ດັ່ງນັ້ນ
  typedef unsigned __int64 size_t;
#endif
#ບໍ່ດັ່ງນັ້ນ
  typedef unsigned ຈຳນວນເຕັມ size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ຖ້າ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef ຈຳນວນເຕັມ ssize_t __attribute__ ((mode (DI)));
#ບໍ່ດັ່ງນັ້ນ
  typedef __int64 ssize_t;
#endif
#ບໍ່ດັ່ງນັ້ນ
  typedef ຈຳນວນເຕັມ ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#ຖ້າ !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#ຖ້າ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef ຈຳນວນເຕັມ _off64_t __attribute__ ((mode (DI)));
#ຖ້າ !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef ຈຳນວນເຕັມ off64_t __attribute__ ((mode (DI)));
#endif
#ບໍ່ດັ່ງນັ້ນ
  typedef long long _off64_t;
#ຖ້າ !defined(NO_OLDNAMES) || defined(_POSIX)
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

  _CRTIMP ຈຳນວນເຕັມ __cdecl _access(const var_na *_Filename,ຈຳນວນເຕັມ _AccessMode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _chmod(const var_na *_Filename,ຈຳນວນເຕັມ _Mode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _chsize(ຈຳນວນເຕັມ _FileHandle,long _Size);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _close(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _commit(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _creat(const var_na *_Filename,ຈຳນວນເຕັມ _PermissionMode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _dup(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _dup2(ຈຳນວນເຕັມ _FileHandleSrc,ຈຳນວນເຕັມ _FileHandleDst);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _eof(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP long __cdecl _filelength(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const var_na *_Filename,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _findnext32(intptr_t _FindHandle,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _isatty(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _locking(ຈຳນວນເຕັມ _FileHandle,ຈຳນວນເຕັມ _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(ຈຳນວນເຕັມ _FileHandle,long _Offset,ຈຳນວນເຕັມ _Origin);
  _off64_t lseek64(ຈຳນວນເຕັມ fd,_off64_t offset, ຈຳນວນເຕັມ whence);
  _CRTIMP var_na *__cdecl _mktemp(var_na *_TemplateName);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _pipe(ຈຳນວນເຕັມ *_PtHandles,unsigned ຈຳນວນເຕັມ _PipeSize,ຈຳນວນເຕັມ _TextMode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _read(ຈຳນວນເຕັມ _FileHandle,void *_DstBuf,unsigned ຈຳນວນເຕັມ _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ຈຳນວນເຕັມ __cdecl remove(const var_na *_Filename);
  ຈຳນວນເຕັມ __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _unlink(const var_na *_Filename);
#ifndef	NO_OLDNAMES
  ຈຳນວນເຕັມ __cdecl unlink(const var_na *_Filename);
#endif
#endif

  _CRTIMP ຈຳນວນເຕັມ __cdecl _setmode(ຈຳນວນເຕັມ _FileHandle,ຈຳນວນເຕັມ _Mode);
  _CRTIMP long __cdecl _tell(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _umask(ຈຳນວນເຕັມ _Mode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _write(ຈຳນວນເຕັມ _FileHandle,const void *_Buf,unsigned ຈຳນວນເຕັມ _MaxCharCount);

#ຖ້າ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ຈຳນວນເຕັມ _FileHandle);
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
    ສົ່ງຄືນ ret;
  }
  _CRTIMP ຈຳນວນເຕັມ __cdecl _findnext32i64(intptr_t _FindHandle,sa_nracanaa _finddata32i64_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _findnext64(intptr_t _FindHandle,sa_nracanaa __finddata64_t *_FindData);
  ຈຳນວນເຕັມ __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData);
  __CRT_INLINE ຈຳນວນເຕັມ __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData)
  {
    sa_nracanaa __finddata64_t fd;
    ຈຳນວນເຕັມ ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ສົ່ງຄືນ ret;
  }
  __int64 __cdecl _lseeki64(ຈຳນວນເຕັມ _FileHandle,__int64 _Offset,ຈຳນວນເຕັມ _Origin);
  __int64 __cdecl _telli64(ຈຳນວນເຕັມ _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  ຈຳນວນເຕັມ __cdecl chdir (const var_na *);
  var_na *__cdecl getcwd (var_na *, ຈຳນວນເຕັມ);
  ຈຳນວນເຕັມ __cdecl mkdir (const var_na *);
  var_na *__cdecl mktemp(var_na *);
  ຈຳນວນເຕັມ __cdecl rmdir (const var_na*);
  ຈຳນວນເຕັມ __cdecl chmod (const var_na *, ຈຳນວນເຕັມ);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ຈຳນວນເຕັມ *_FileHandle,const var_na *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _ShareFlag,ຈຳນວນເຕັມ _PermissionMode);

#ifndef __cplusplus
  _CRTIMP ຈຳນວນເຕັມ __cdecl _open(const var_na *_Filename,ຈຳນວນເຕັມ _OpenFlag,...);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _sopen(const var_na *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _ShareFlag,...);
#ບໍ່ດັ່ງນັ້ນ
  extern "C++" _CRTIMP ຈຳນວນເຕັມ __cdecl _open(const var_na *_Filename,ຈຳນວນເຕັມ _Openflag,ຈຳນວນເຕັມ _PermissionMode = 0);
  extern "C++" _CRTIMP ຈຳນວນເຕັມ __cdecl _sopen(const var_na *_Filename,ຈຳນວນເຕັມ _Openflag,ຈຳນວນເຕັມ _ShareFlag,ຈຳນວນເຕັມ _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP ຈຳນວນເຕັມ __cdecl _waccess(const wchar_t *_Filename,ຈຳນວນເຕັມ _AccessMode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wchmod(const wchar_t *_Filename,ຈຳນວນເຕັມ _Mode);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wcreat(const wchar_t *_Filename,ຈຳນວນເຕັມ _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wfindnext32(intptr_t _FindHandle,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ຖ້າ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,sa_nracanaa _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,sa_nracanaa _wfinddata64_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wfindnext32i64(intptr_t _FindHandle,sa_nracanaa _wfinddata32i64_t *_FindData);
  ຈຳນວນເຕັມ __cdecl _wfindnext64i32(intptr_t _FindHandle,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wfindnext64(intptr_t _FindHandle,sa_nracanaa _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(ຈຳນວນເຕັມ *_FileHandle,const wchar_t *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _ShareFlag,ຈຳນວນເຕັມ _PermissionFlag);

#ຖ້າ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wopen(const wchar_t *_Filename,ຈຳນວນເຕັມ _OpenFlag,...);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _wsopen(const wchar_t *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _ShareFlag,...);
#ບໍ່ດັ່ງນັ້ນ
  extern "C++" _CRTIMP ຈຳນວນເຕັມ __cdecl _wopen(const wchar_t *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _PermissionMode = 0);
  extern "C++" _CRTIMP ຈຳນວນເຕັມ __cdecl _wsopen(const wchar_t *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _ShareFlag,ຈຳນວນເຕັມ _PermissionMode = 0);
#endif

#endif

  ຈຳນວນເຕັມ __cdecl __lock_fhandle(ຈຳນວນເຕັມ _Filehandle);
  void __cdecl _unlock_fhandle(ຈຳນວນເຕັມ _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ຈຳນວນເຕັມ _FileHandle);
  _CRTIMP ຈຳນວນເຕັມ __cdecl _open_osfhandle(intptr_t _OSFileHandle,ຈຳນວນເຕັມ _Flags);

#ifndef	NO_OLDNAMES
  ຈຳນວນເຕັມ __cdecl access(const var_na *_Filename,ຈຳນວນເຕັມ _AccessMode);
  ຈຳນວນເຕັມ __cdecl chmod(const var_na *_Filename,ຈຳນວນເຕັມ _AccessMode);
  ຈຳນວນເຕັມ __cdecl chsize(ຈຳນວນເຕັມ _FileHandle,long _Size);
  ຈຳນວນເຕັມ __cdecl close(ຈຳນວນເຕັມ _FileHandle);
  ຈຳນວນເຕັມ __cdecl creat(const var_na *_Filename,ຈຳນວນເຕັມ _PermissionMode);
  ຈຳນວນເຕັມ __cdecl dup(ຈຳນວນເຕັມ _FileHandle);
  ຈຳນວນເຕັມ __cdecl dup2(ຈຳນວນເຕັມ _FileHandleSrc,ຈຳນວນເຕັມ _FileHandleDst);
  ຈຳນວນເຕັມ __cdecl eof(ຈຳນວນເຕັມ _FileHandle);
  long __cdecl filelength(ຈຳນວນເຕັມ _FileHandle);
  ຈຳນວນເຕັມ __cdecl isatty(ຈຳນວນເຕັມ _FileHandle);
  ຈຳນວນເຕັມ __cdecl locking(ຈຳນວນເຕັມ _FileHandle,ຈຳນວນເຕັມ _LockMode,long _NumOfBytes);
  long __cdecl lseek(ຈຳນວນເຕັມ _FileHandle,long _Offset,ຈຳນວນເຕັມ _Origin);
  var_na *__cdecl mktemp(var_na *_TemplateName);
  ຈຳນວນເຕັມ __cdecl open(const var_na *_Filename,ຈຳນວນເຕັມ _OpenFlag,...);
  ຈຳນວນເຕັມ __cdecl read(ຈຳນວນເຕັມ _FileHandle,void *_DstBuf,unsigned ຈຳນວນເຕັມ _MaxCharCount);
  ຈຳນວນເຕັມ __cdecl setmode(ຈຳນວນເຕັມ _FileHandle,ຈຳນວນເຕັມ _Mode);
  ຈຳນວນເຕັມ __cdecl sopen(const var_na *_Filename,ຈຳນວນເຕັມ _OpenFlag,ຈຳນວນເຕັມ _ShareFlag,...);
  long __cdecl tell(ຈຳນວນເຕັມ _FileHandle);
  ຈຳນວນເຕັມ __cdecl umask(ຈຳນວນເຕັມ _Mode);
  ຈຳນວນເຕັມ __cdecl write(ຈຳນວນເຕັມ _Filehandle,const void *_Buf,unsigned ຈຳນວນເຕັມ _MaxCharCount);
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
unsigned ຈຳນວນເຕັມ alarm(unsigned ຈຳນວນເຕັມ seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static anta_hstha ຈຳນວນເຕັມ __mingw_access (const var_na *__fname, ຈຳນວນເຕັມ __mode) {
  ສົ່ງຄືນ  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

