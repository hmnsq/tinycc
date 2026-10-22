
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

_CRTIMP var_na* __cdecl _getcwd (var_na*, ကိန်းပြည့်);
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
#မဟုတ်ပါက
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#မဟုတ်ပါက
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
#မဟုတ်ပါက
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
#အကယ်၍ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef unsigned ကိန်းပြည့် size_t __attribute__ ((mode (DI)));
#မဟုတ်ပါက
  typedef unsigned __int64 size_t;
#endif
#မဟုတ်ပါက
  typedef unsigned ကိန်းပြည့် size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#အကယ်၍ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef ကိန်းပြည့် ssize_t __attribute__ ((mode (DI)));
#မဟုတ်ပါက
  typedef __int64 ssize_t;
#endif
#မဟုတ်ပါက
  typedef ကိန်းပြည့် ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#အကယ်၍ !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#အကယ်၍ defined(__GNUC__) && defined(__STRICT_ANSI__)
  typedef ကိန်းပြည့် _off64_t __attribute__ ((mode (DI)));
#အကယ်၍ !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef ကိန်းပြည့် off64_t __attribute__ ((mode (DI)));
#endif
#မဟုတ်ပါက
  typedef long long _off64_t;
#အကယ်၍ !defined(NO_OLDNAMES) || defined(_POSIX)
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

  _CRTIMP ကိန်းပြည့် __cdecl _access(const var_na *_Filename,ကိန်းပြည့် _AccessMode);
  _CRTIMP ကိန်းပြည့် __cdecl _chmod(const var_na *_Filename,ကိန်းပြည့် _Mode);
  _CRTIMP ကိန်းပြည့် __cdecl _chsize(ကိန်းပြည့် _FileHandle,long _Size);
  _CRTIMP ကိန်းပြည့် __cdecl _close(ကိန်းပြည့် _FileHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _commit(ကိန်းပြည့် _FileHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _creat(const var_na *_Filename,ကိန်းပြည့် _PermissionMode);
  _CRTIMP ကိန်းပြည့် __cdecl _dup(ကိန်းပြည့် _FileHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _dup2(ကိန်းပြည့် _FileHandleSrc,ကိန်းပြည့် _FileHandleDst);
  _CRTIMP ကိန်းပြည့် __cdecl _eof(ကိန်းပြည့် _FileHandle);
  _CRTIMP long __cdecl _filelength(ကိန်းပြည့် _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(const var_na *_Filename,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _findnext32(intptr_t _FindHandle,sa_nracanaa _finddata32_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _isatty(ကိန်းပြည့် _FileHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _locking(ကိန်းပြည့် _FileHandle,ကိန်းပြည့် _LockMode,long _NumOfBytes);
  _CRTIMP long __cdecl _lseek(ကိန်းပြည့် _FileHandle,long _Offset,ကိန်းပြည့် _Origin);
  _off64_t lseek64(ကိန်းပြည့် fd,_off64_t offset, ကိန်းပြည့် whence);
  _CRTIMP var_na *__cdecl _mktemp(var_na *_TemplateName);
  _CRTIMP ကိန်းပြည့် __cdecl _pipe(ကိန်းပြည့် *_PtHandles,unsigned ကိန်းပြည့် _PipeSize,ကိန်းပြည့် _TextMode);
  _CRTIMP ကိန်းပြည့် __cdecl _read(ကိန်းပြည့် _FileHandle,void *_DstBuf,unsigned ကိန်းပြည့် _MaxCharCount);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ကိန်းပြည့် __cdecl remove(const var_na *_Filename);
  ကိန်းပြည့် __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP ကိန်းပြည့် __cdecl _unlink(const var_na *_Filename);
#ifndef	NO_OLDNAMES
  ကိန်းပြည့် __cdecl unlink(const var_na *_Filename);
#endif
#endif

  _CRTIMP ကိန်းပြည့် __cdecl _setmode(ကိန်းပြည့် _FileHandle,ကိန်းပြည့် _Mode);
  _CRTIMP long __cdecl _tell(ကိန်းပြည့် _FileHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _umask(ကိန်းပြည့် _Mode);
  _CRTIMP ကိန်းပြည့် __cdecl _write(ကိန်းပြည့် _FileHandle,const void *_Buf,unsigned ကိန်းပြည့် _MaxCharCount);

#အကယ်၍ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ကိန်းပြည့် _FileHandle);
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
    ပြန်ပေး ret;
  }
  _CRTIMP ကိန်းပြည့် __cdecl _findnext32i64(intptr_t _FindHandle,sa_nracanaa _finddata32i64_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _findnext64(intptr_t _FindHandle,sa_nracanaa __finddata64_t *_FindData);
  ကိန်းပြည့် __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData);
  __CRT_INLINE ကိန်းပြည့် __cdecl _findnext64i32(intptr_t _FindHandle,sa_nracanaa _finddata64i32_t *_FindData)
  {
    sa_nracanaa __finddata64_t fd;
    ကိန်းပြည့် ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ပြန်ပေး ret;
  }
  __int64 __cdecl _lseeki64(ကိန်းပြည့် _FileHandle,__int64 _Offset,ကိန်းပြည့် _Origin);
  __int64 __cdecl _telli64(ကိန်းပြည့် _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  ကိန်းပြည့် __cdecl chdir (const var_na *);
  var_na *__cdecl getcwd (var_na *, ကိန်းပြည့်);
  ကိန်းပြည့် __cdecl mkdir (const var_na *);
  var_na *__cdecl mktemp(var_na *);
  ကိန်းပြည့် __cdecl rmdir (const var_na*);
  ကိန်းပြည့် __cdecl chmod (const var_na *, ကိန်းပြည့်);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ကိန်းပြည့် *_FileHandle,const var_na *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _ShareFlag,ကိန်းပြည့် _PermissionMode);

#ifndef __cplusplus
  _CRTIMP ကိန်းပြည့် __cdecl _open(const var_na *_Filename,ကိန်းပြည့် _OpenFlag,...);
  _CRTIMP ကိန်းပြည့် __cdecl _sopen(const var_na *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _ShareFlag,...);
#မဟုတ်ပါက
  extern "C++" _CRTIMP ကိန်းပြည့် __cdecl _open(const var_na *_Filename,ကိန်းပြည့် _Openflag,ကိန်းပြည့် _PermissionMode = 0);
  extern "C++" _CRTIMP ကိန်းပြည့် __cdecl _sopen(const var_na *_Filename,ကိန်းပြည့် _Openflag,ကိန်းပြည့် _ShareFlag,ကိန်းပြည့် _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP ကိန်းပြည့် __cdecl _waccess(const wchar_t *_Filename,ကိန်းပြည့် _AccessMode);
  _CRTIMP ကိန်းပြည့် __cdecl _wchmod(const wchar_t *_Filename,ကိန်းပြည့် _Mode);
  _CRTIMP ကိန်းပြည့် __cdecl _wcreat(const wchar_t *_Filename,ကိန်းပြည့် _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(const wchar_t *_Filename,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _wfindnext32(intptr_t _FindHandle,sa_nracanaa _wfinddata32_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _wunlink(const wchar_t *_Filename);
  _CRTIMP ကိန်းပြည့် __cdecl _wrename(const wchar_t *_NewFilename,const wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#အကယ်၍ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename,sa_nracanaa _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(const wchar_t *_Filename,sa_nracanaa _wfinddata64_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _wfindnext32i64(intptr_t _FindHandle,sa_nracanaa _wfinddata32i64_t *_FindData);
  ကိန်းပြည့် __cdecl _wfindnext64i32(intptr_t _FindHandle,sa_nracanaa _wfinddata64i32_t *_FindData);
  _CRTIMP ကိန်းပြည့် __cdecl _wfindnext64(intptr_t _FindHandle,sa_nracanaa _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(ကိန်းပြည့် *_FileHandle,const wchar_t *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _ShareFlag,ကိန်းပြည့် _PermissionFlag);

#အကယ်၍ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ကိန်းပြည့် __cdecl _wopen(const wchar_t *_Filename,ကိန်းပြည့် _OpenFlag,...);
  _CRTIMP ကိန်းပြည့် __cdecl _wsopen(const wchar_t *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _ShareFlag,...);
#မဟုတ်ပါက
  extern "C++" _CRTIMP ကိန်းပြည့် __cdecl _wopen(const wchar_t *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _PermissionMode = 0);
  extern "C++" _CRTIMP ကိန်းပြည့် __cdecl _wsopen(const wchar_t *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _ShareFlag,ကိန်းပြည့် _PermissionMode = 0);
#endif

#endif

  ကိန်းပြည့် __cdecl __lock_fhandle(ကိန်းပြည့် _Filehandle);
  void __cdecl _unlock_fhandle(ကိန်းပြည့် _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ကိန်းပြည့် _FileHandle);
  _CRTIMP ကိန်းပြည့် __cdecl _open_osfhandle(intptr_t _OSFileHandle,ကိန်းပြည့် _Flags);

#ifndef	NO_OLDNAMES
  ကိန်းပြည့် __cdecl access(const var_na *_Filename,ကိန်းပြည့် _AccessMode);
  ကိန်းပြည့် __cdecl chmod(const var_na *_Filename,ကိန်းပြည့် _AccessMode);
  ကိန်းပြည့် __cdecl chsize(ကိန်းပြည့် _FileHandle,long _Size);
  ကိန်းပြည့် __cdecl close(ကိန်းပြည့် _FileHandle);
  ကိန်းပြည့် __cdecl creat(const var_na *_Filename,ကိန်းပြည့် _PermissionMode);
  ကိန်းပြည့် __cdecl dup(ကိန်းပြည့် _FileHandle);
  ကိန်းပြည့် __cdecl dup2(ကိန်းပြည့် _FileHandleSrc,ကိန်းပြည့် _FileHandleDst);
  ကိန်းပြည့် __cdecl eof(ကိန်းပြည့် _FileHandle);
  long __cdecl filelength(ကိန်းပြည့် _FileHandle);
  ကိန်းပြည့် __cdecl isatty(ကိန်းပြည့် _FileHandle);
  ကိန်းပြည့် __cdecl locking(ကိန်းပြည့် _FileHandle,ကိန်းပြည့် _LockMode,long _NumOfBytes);
  long __cdecl lseek(ကိန်းပြည့် _FileHandle,long _Offset,ကိန်းပြည့် _Origin);
  var_na *__cdecl mktemp(var_na *_TemplateName);
  ကိန်းပြည့် __cdecl open(const var_na *_Filename,ကိန်းပြည့် _OpenFlag,...);
  ကိန်းပြည့် __cdecl read(ကိန်းပြည့် _FileHandle,void *_DstBuf,unsigned ကိန်းပြည့် _MaxCharCount);
  ကိန်းပြည့် __cdecl setmode(ကိန်းပြည့် _FileHandle,ကိန်းပြည့် _Mode);
  ကိန်းပြည့် __cdecl sopen(const var_na *_Filename,ကိန်းပြည့် _OpenFlag,ကိန်းပြည့် _ShareFlag,...);
  long __cdecl tell(ကိန်းပြည့် _FileHandle);
  ကိန်းပြည့် __cdecl umask(ကိန်းပြည့် _Mode);
  ကိန်းပြည့် __cdecl write(ကိန်းပြည့် _Filehandle,const void *_Buf,unsigned ကိန်းပြည့် _MaxCharCount);
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
unsigned ကိန်းပြည့် alarm(unsigned ကိန်းပြည့် seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
static anta_hstha ကိန်းပြည့် __mingw_access (const var_na *__fname, ကိန်းပြည့် __mode) {
  ပြန်ပေး  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(pop)

#include <sec_api/io_s.h>

#endif /* End _IO_H_ */

