
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#شامل <_mingw.h>
#شامل <string.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
بیرونی "C" {
#endif

_CRTIMP نویسه* __cdecl _getcwd (نویسه*, صحیح);
#ifndef _FSIZE_T_DEFINED
  تعریفنوع unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  ساختار _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    نویسه name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ساختار _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    نویسه name[260];
  };

  ساختار _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    نویسه name[260];
  };

  ساختار __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    نویسه name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#وگرنه
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#وگرنه
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

  ساختار _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ساختار _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ساختار _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ساختار _wfinddata64_t {
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
#وگرنه
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
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع unsigned صحیح size_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع unsigned __int64 size_t;
#endif
#وگرنه
  تعریفنوع unsigned صحیح size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع صحیح ssize_t __attribute__ ((mode (DI)));
#وگرنه
  تعریفنوع __int64 ssize_t;
#endif
#وگرنه
  تعریفنوع صحیح ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  تعریفنوع long _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعریفنوع صحیح _off64_t __attribute__ ((mode (DI)));
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع صحیح off64_t __attribute__ ((mode (DI)));
#endif
#وگرنه
  تعریفنوع long long _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP صحیح __cdecl _access(ثابت نویسه *_Filename,صحیح _AccessMode);
  _CRTIMP صحیح __cdecl _chmod(ثابت نویسه *_Filename,صحیح _Mode);
  _CRTIMP صحیح __cdecl _chsize(صحیح _FileHandle,long _Size);
  _CRTIMP صحیح __cdecl _close(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _commit(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _creat(ثابت نویسه *_Filename,صحیح _PermissionMode);
  _CRTIMP صحیح __cdecl _dup(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _dup2(صحیح _FileHandleSrc,صحیح _FileHandleDst);
  _CRTIMP صحیح __cdecl _eof(صحیح _FileHandle);
  _CRTIMP long __cdecl _filelength(صحیح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت نویسه *_Filename,ساختار _finddata32_t *_FindData);
  _CRTIMP صحیح __cdecl _findnext32(intptr_t _FindHandle,ساختار _finddata32_t *_FindData);
  _CRTIMP صحیح __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP صحیح __cdecl _isatty(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _locking(صحیح _FileHandle,صحیح _LockMode,long رقم_Of_Bytes);
  _CRTIMP long __cdecl _lseek(صحیح _FileHandle,long _Offset,صحیح _Origin);
  _off64_t lseek64(صحیح fd,_off64_t offset, صحیح whence);
  _CRTIMP نویسه *__cdecl _mktemp(نویسه *_TemplateName);
  _CRTIMP صحیح __cdecl _pipe(صحیح *_PtHandles,unsigned صحیح _PipeSize,صحیح _TextMode);
  _CRTIMP صحیح __cdecl _read(صحیح _FileHandle,تهی *_DstBuf,unsigned صحیح Max_Char_شمار);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  صحیح __cdecl remove(ثابت نویسه *_Filename);
  صحیح __cdecl rename(ثابت نویسه *_OldFilename,ثابت نویسه *_NewFilename);
  _CRTIMP صحیح __cdecl _unlink(ثابت نویسه *_Filename);
#ifndef	NO_OLDNAMES
  صحیح __cdecl unlink(ثابت نویسه *_Filename);
#endif
#endif

  _CRTIMP صحیح __cdecl _setmode(صحیح _FileHandle,صحیح _Mode);
  _CRTIMP long __cdecl _tell(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _umask(صحیح _Mode);
  _CRTIMP صحیح __cdecl _write(صحیح _FileHandle,ثابت تهی *_Buf,unsigned صحیح Max_Char_شمار);

#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحیح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت نویسه *_Filename,ساختار _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت نویسه *_Filename,ساختار __finddata64_t *_FindData);
#ifdef __cplusplus
#شامل <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(ثابت نویسه *_Filename,ساختار _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت نویسه *_Filename,ساختار _finddata64i32_t *_FindData)
  {
    ساختار __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    بازگشت ret;
  }
  _CRTIMP صحیح __cdecl _findnext32i64(intptr_t _FindHandle,ساختار _finddata32i64_t *_FindData);
  _CRTIMP صحیح __cdecl _findnext64(intptr_t _FindHandle,ساختار __finddata64_t *_FindData);
  صحیح __cdecl _findnext64i32(intptr_t _FindHandle,ساختار _finddata64i32_t *_FindData);
  __CRT_INLINE صحیح __cdecl _findnext64i32(intptr_t _FindHandle,ساختار _finddata64i32_t *_FindData)
  {
    ساختار __finddata64_t fd;
    صحیح ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    بازگشت ret;
  }
  __int64 __cdecl _lseeki64(صحیح _FileHandle,__int64 _Offset,صحیح _Origin);
  __int64 __cdecl _telli64(صحیح _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  صحیح __cdecl chdir (ثابت نویسه *);
  نویسه *__cdecl getcwd (نویسه *, صحیح);
  صحیح __cdecl mkdir (ثابت نویسه *);
  نویسه *__cdecl mktemp(نویسه *);
  صحیح __cdecl rmdir (ثابت نویسه*);
  صحیح __cdecl chmod (ثابت نویسه *, صحیح);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحیح *_FileHandle,ثابت نویسه *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionMode);

#ifndef __cplusplus
  _CRTIMP صحیح __cdecl _open(ثابت نویسه *_Filename,صحیح _OpenFlag,...);
  _CRTIMP صحیح __cdecl _sopen(ثابت نویسه *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
#وگرنه
  بیرونی "C++" _CRTIMP صحیح __cdecl _open(ثابت نویسه *_Filename,صحیح _Openflag,صحیح _PermissionMode = 0);
  بیرونی "C++" _CRTIMP صحیح __cdecl _sopen(ثابت نویسه *_Filename,صحیح _Openflag,صحیح _ShareFlag,صحیح _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP صحیح __cdecl _waccess(ثابت wchar_t *_Filename,صحیح _AccessMode);
  _CRTIMP صحیح __cdecl _wchmod(ثابت wchar_t *_Filename,صحیح _Mode);
  _CRTIMP صحیح __cdecl _wcreat(ثابت wchar_t *_Filename,صحیح _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,ساختار _wfinddata32_t *_FindData);
  _CRTIMP صحیح __cdecl _wfindnext32(intptr_t _FindHandle,ساختار _wfinddata32_t *_FindData);
  _CRTIMP صحیح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحیح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#اگر _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,ساختار _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,ساختار _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,ساختار _wfinddata64_t *_FindData);
  _CRTIMP صحیح __cdecl _wfindnext32i64(intptr_t _FindHandle,ساختار _wfinddata32i64_t *_FindData);
  صحیح __cdecl _wfindnext64i32(intptr_t _FindHandle,ساختار _wfinddata64i32_t *_FindData);
  _CRTIMP صحیح __cdecl _wfindnext64(intptr_t _FindHandle,ساختار _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(صحیح *_FileHandle,ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionFlag);

#اگر !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,...);
  _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
#وگرنه
  بیرونی "C++" _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _PermissionMode = 0);
  بیرونی "C++" _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionMode = 0);
#endif

#endif

  صحیح __cdecl __lock_fhandle(صحیح _Filehandle);
  تهی __cdecl _unlock_fhandle(صحیح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحیح _Flags);

#ifndef	NO_OLDNAMES
  صحیح __cdecl access(ثابت نویسه *_Filename,صحیح _AccessMode);
  صحیح __cdecl chmod(ثابت نویسه *_Filename,صحیح _AccessMode);
  صحیح __cdecl chsize(صحیح _FileHandle,long _Size);
  صحیح __cdecl close(صحیح _FileHandle);
  صحیح __cdecl creat(ثابت نویسه *_Filename,صحیح _PermissionMode);
  صحیح __cdecl dup(صحیح _FileHandle);
  صحیح __cdecl dup2(صحیح _FileHandleSrc,صحیح _FileHandleDst);
  صحیح __cdecl eof(صحیح _FileHandle);
  long __cdecl filelength(صحیح _FileHandle);
  صحیح __cdecl isatty(صحیح _FileHandle);
  صحیح __cdecl locking(صحیح _FileHandle,صحیح _LockMode,long رقم_Of_Bytes);
  long __cdecl lseek(صحیح _FileHandle,long _Offset,صحیح _Origin);
  نویسه *__cdecl mktemp(نویسه *_TemplateName);
  صحیح __cdecl open(ثابت نویسه *_Filename,صحیح _OpenFlag,...);
  صحیح __cdecl اقرأ(صحیح _FileHandle,تهی *_DstBuf,unsigned صحیح Max_Char_شمار);
  صحیح __cdecl setmode(صحیح _FileHandle,صحیح _Mode);
  صحیح __cdecl sopen(ثابت نویسه *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
  long __cdecl tell(صحیح _FileHandle);
  صحیح __cdecl umask(صحیح _Mode);
  صحیح __cdecl اكتب(صحیح _Filehandle,ثابت تهی *_Buf,unsigned صحیح Max_Char_شمار);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
بیرونی "C" {
#endif

/* Misc stuff */
نویسه *getlogin(تهی);
#ifdef __USE_MINGW_ALARM
unsigned صحیح alarm(unsigned صحیح seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ایستا درونخطی صحیح __mingw_access (ثابت نویسه *__fname, صحیح __mode) {
  بازگشت  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(برداشت)

#شامل <sec_api/io_s.h>

#endif /* End _IO_H_ */

