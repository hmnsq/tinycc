
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#ضمن <_mingw.h>
#ضمن <string.h>

#pragma pack(تور,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
خارجي "C" {
#endif

_CRTIMP حرف* __cdecl _getcwd (حرف*, صحيح);
#ifndef _FSIZE_T_DEFINED
  تعريفنوع unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  بنية _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    حرف name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  بنية _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    حرف name[260];
  };

  بنية _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    حرف name[260];
  };

  بنية __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    حرف name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#وإلا
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#وإلا
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

  بنية _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
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
#وإلا
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
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع unsigned صحيح size_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع unsigned __int64 size_t;
#endif
#وإلا
  تعريفنوع unsigned صحيح size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((mode (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#endif
#وإلا
  تعريفنوع صحيح ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  تعريفنوع long _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _off64_t __attribute__ ((mode (DI)));
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع صحيح off64_t __attribute__ ((mode (DI)));
#endif
#وإلا
  تعريفنوع long long _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP صحيح __cdecl _access(ثابت حرف *_Filename,صحيح _AccessMode);
  _CRTIMP صحيح __cdecl _chmod(ثابت حرف *_Filename,صحيح _Mode);
  _CRTIMP صحيح __cdecl _chsize(صحيح _FileHandle,long _Size);
  _CRTIMP صحيح __cdecl _close(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _commit(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _creat(ثابت حرف *_Filename,صحيح _PermissionMode);
  _CRTIMP صحيح __cdecl _dup(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  _CRTIMP صحيح __cdecl _eof(صحيح _FileHandle);
  _CRTIMP long __cdecl _filelength(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت حرف *_Filename,بنية _finddata32_t *_FindData);
  _CRTIMP صحيح __cdecl _findnext32(intptr_t _FindHandle,بنية _finddata32_t *_FindData);
  _CRTIMP صحيح __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP صحيح __cdecl _isatty(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _locking(صحيح _FileHandle,صحيح _LockMode,long لمب_Of_Bytes);
  _CRTIMP long __cdecl _lseek(صحيح _FileHandle,long _Offset,صحيح _Origin);
  _off64_t lseek64(صحيح fd,_off64_t offset, صحيح whence);
  _CRTIMP حرف *__cdecl _mktemp(حرف *_TemplateName);
  _CRTIMP صحيح __cdecl _pipe(صحيح *_PtHandles,unsigned صحيح _PipeSize,صحيح _TextMode);
  _CRTIMP صحيح __cdecl _read(صحيح _FileHandle,فراغ *_DstBuf,unsigned صحيح Max_Char_كدي);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#ifndef	NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#endif
#endif

  _CRTIMP صحيح __cdecl _setmode(صحيح _FileHandle,صحيح _Mode);
  _CRTIMP long __cdecl _tell(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _umask(صحيح _Mode);
  _CRTIMP صحيح __cdecl _write(صحيح _FileHandle,ثابت فراغ *_Buf,unsigned صحيح Max_Char_كدي);

#إذا _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت حرف *_Filename,بنية _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت حرف *_Filename,بنية __finddata64_t *_FindData);
#ifdef __cplusplus
#ضمن <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *_FindData)
  {
    بنية __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    أرجع ret;
  }
  _CRTIMP صحيح __cdecl _findnext32i64(intptr_t _FindHandle,بنية _finddata32i64_t *_FindData);
  _CRTIMP صحيح __cdecl _findnext64(intptr_t _FindHandle,بنية __finddata64_t *_FindData);
  صحيح __cdecl _findnext64i32(intptr_t _FindHandle,بنية _finddata64i32_t *_FindData);
  __CRT_INLINE صحيح __cdecl _findnext64i32(intptr_t _FindHandle,بنية _finddata64i32_t *_FindData)
  {
    بنية __finddata64_t fd;
    صحيح ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    أرجع ret;
  }
  __int64 __cdecl _lseeki64(صحيح _FileHandle,__int64 _Offset,صحيح _Origin);
  __int64 __cdecl _telli64(صحيح _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  صحيح __cdecl chdir (ثابت حرف *);
  حرف *__cdecl getcwd (حرف *, صحيح);
  صحيح __cdecl mkdir (ثابت حرف *);
  حرف *__cdecl mktemp(حرف *);
  صحيح __cdecl rmdir (ثابت حرف*);
  صحيح __cdecl chmod (ثابت حرف *, صحيح);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحيح *_FileHandle,ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionMode);

#ifndef __cplusplus
  _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _Openflag,صحيح _PermissionMode = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _Openflag,صحيح _ShareFlag,صحيح _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح _AccessMode);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح _Mode);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *_FindData);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t _FindHandle,بنية _wfinddata32_t *_FindData);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#إذا _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *_FindData);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t _FindHandle,بنية _wfinddata32i64_t *_FindData);
  صحيح __cdecl _wfindnext64i32(intptr_t _FindHandle,بنية _wfinddata64i32_t *_FindData);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t _FindHandle,بنية _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);

#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _PermissionMode = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionMode = 0);
#endif

#endif

  صحيح __cdecl __lock_fhandle(صحيح _Filehandle);
  فراغ __cdecl _unlock_fhandle(صحيح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحيح _Flags);

#ifndef	NO_OLDNAMES
  صحيح __cdecl access(ثابت حرف *_Filename,صحيح _AccessMode);
  صحيح __cdecl chmod(ثابت حرف *_Filename,صحيح _AccessMode);
  صحيح __cdecl chsize(صحيح _FileHandle,long _Size);
  صحيح __cdecl close(صحيح _FileHandle);
  صحيح __cdecl creat(ثابت حرف *_Filename,صحيح _PermissionMode);
  صحيح __cdecl dup(صحيح _FileHandle);
  صحيح __cdecl dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  صحيح __cdecl eof(صحيح _FileHandle);
  long __cdecl filelength(صحيح _FileHandle);
  صحيح __cdecl isatty(صحيح _FileHandle);
  صحيح __cdecl locking(صحيح _FileHandle,صحيح _LockMode,long لمب_Of_Bytes);
  long __cdecl lseek(صحيح _FileHandle,long _Offset,صحيح _Origin);
  حرف *__cdecl mktemp(حرف *_TemplateName);
  صحيح __cdecl open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  صحيح __cdecl اقرأ(صحيح _FileHandle,فراغ *_DstBuf,unsigned صحيح Max_Char_كدي);
  صحيح __cdecl setmode(صحيح _FileHandle,صحيح _Mode);
  صحيح __cdecl sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
  long __cdecl tell(صحيح _FileHandle);
  صحيح __cdecl umask(صحيح _Mode);
  صحيح __cdecl اكتب(صحيح _Filehandle,ثابت فراغ *_Buf,unsigned صحيح Max_Char_كدي);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
خارجي "C" {
#endif

/* Misc stuff */
حرف *getlogin(فراغ);
#ifdef __USE_MINGW_ALARM
unsigned صحيح alarm(unsigned صحيح seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ساكن مضمن صحيح __mingw_access (ثابت حرف *__fname, صحيح __mode) {
  أرجع  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(چرو)

#ضمن <sec_api/io_s.h>

#endif /* End _IO_H_ */

