
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#அந்தர்பாவ <_mingw.h>
#அந்தர்பாவ <string.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
வெளி "C" {
#endif

_CRTIMP எழுத்து* __cdecl _getcwd (எழுத்து*, முழு);
#ifndef _FSIZE_T_DEFINED
  வகைவரை unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  கட்டமைப்பு _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    எழுத்து name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  கட்டமைப்பு _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    எழுத்து name[260];
  };

  கட்டமைப்பு _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    எழுத்து name[260];
  };

  கட்டமைப்பு __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    எழுத்து name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#இல்லையெனில்
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#இல்லையெனில்
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

  கட்டமைப்பு _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  கட்டமைப்பு _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  கட்டமைப்பு _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  கட்டமைப்பு _wfinddata64_t {
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
#இல்லையெனில்
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
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை unsigned முழு size_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை unsigned __int64 size_t;
#endif
#இல்லையெனில்
  வகைவரை unsigned முழு size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை முழு ssize_t __attribute__ ((mode (DI)));
#இல்லையெனில்
  வகைவரை __int64 ssize_t;
#endif
#இல்லையெனில்
  வகைவரை முழு ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  வகைவரை long _off_t;
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#எனில் defined(__GNUC__) && defined(__STRICT_ANSI__)
  வகைவரை முழு _off64_t __attribute__ ((mode (DI)));
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை முழு off64_t __attribute__ ((mode (DI)));
#endif
#இல்லையெனில்
  வகைவரை long long _off64_t;
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP முழு __cdecl _access(மாறிலி எழுத்து *_Filename,முழு _AccessMode);
  _CRTIMP முழு __cdecl _chmod(மாறிலி எழுத்து *_Filename,முழு _Mode);
  _CRTIMP முழு __cdecl _chsize(முழு _FileHandle,long _Size);
  _CRTIMP முழு __cdecl _close(முழு _FileHandle);
  _CRTIMP முழு __cdecl _commit(முழு _FileHandle);
  _CRTIMP முழு __cdecl _creat(மாறிலி எழுத்து *_Filename,முழு _PermissionMode);
  _CRTIMP முழு __cdecl _dup(முழு _FileHandle);
  _CRTIMP முழு __cdecl _dup2(முழு _FileHandleSrc,முழு _FileHandleDst);
  _CRTIMP முழு __cdecl _eof(முழு _FileHandle);
  _CRTIMP long __cdecl _filelength(முழு _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(மாறிலி எழுத்து *_Filename,கட்டமைப்பு _finddata32_t *_FindData);
  _CRTIMP முழு __cdecl _findnext32(intptr_t _FindHandle,கட்டமைப்பு _finddata32_t *_FindData);
  _CRTIMP முழு __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP முழு __cdecl _isatty(முழு _FileHandle);
  _CRTIMP முழு __cdecl _locking(முழு _FileHandle,முழு _LockMode,long இலக்கம்_Of_Bytes);
  _CRTIMP long __cdecl _lseek(முழு _FileHandle,long _Offset,முழு _Origin);
  _off64_t lseek64(முழு fd,_off64_t offset, முழு whence);
  _CRTIMP எழுத்து *__cdecl _mktemp(எழுத்து *_TemplateName);
  _CRTIMP முழு __cdecl _pipe(முழு *_PtHandles,unsigned முழு _PipeSize,முழு _TextMode);
  _CRTIMP முழு __cdecl _read(முழு _FileHandle,வெறுமை *_DstBuf,unsigned முழு Max_Char_மொத்தம்);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  முழு __cdecl remove(மாறிலி எழுத்து *_Filename);
  முழு __cdecl rename(மாறிலி எழுத்து *_OldFilename,மாறிலி எழுத்து *_NewFilename);
  _CRTIMP முழு __cdecl _unlink(மாறிலி எழுத்து *_Filename);
#ifndef	NO_OLDNAMES
  முழு __cdecl unlink(மாறிலி எழுத்து *_Filename);
#endif
#endif

  _CRTIMP முழு __cdecl _setmode(முழு _FileHandle,முழு _Mode);
  _CRTIMP long __cdecl _tell(முழு _FileHandle);
  _CRTIMP முழு __cdecl _umask(முழு _Mode);
  _CRTIMP முழு __cdecl _write(முழு _FileHandle,மாறிலி வெறுமை *_Buf,unsigned முழு Max_Char_மொத்தம்);

#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(முழு _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(மாறிலி எழுத்து *_Filename,கட்டமைப்பு _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(மாறிலி எழுத்து *_Filename,கட்டமைப்பு __finddata64_t *_FindData);
#ifdef __cplusplus
#அந்தர்பாவ <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(மாறிலி எழுத்து *_Filename,கட்டமைப்பு _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(மாறிலி எழுத்து *_Filename,கட்டமைப்பு _finddata64i32_t *_FindData)
  {
    கட்டமைப்பு __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    திரும்பு ret;
  }
  _CRTIMP முழு __cdecl _findnext32i64(intptr_t _FindHandle,கட்டமைப்பு _finddata32i64_t *_FindData);
  _CRTIMP முழு __cdecl _findnext64(intptr_t _FindHandle,கட்டமைப்பு __finddata64_t *_FindData);
  முழு __cdecl _findnext64i32(intptr_t _FindHandle,கட்டமைப்பு _finddata64i32_t *_FindData);
  __CRT_INLINE முழு __cdecl _findnext64i32(intptr_t _FindHandle,கட்டமைப்பு _finddata64i32_t *_FindData)
  {
    கட்டமைப்பு __finddata64_t fd;
    முழு ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    திரும்பு ret;
  }
  __int64 __cdecl _lseeki64(முழு _FileHandle,__int64 _Offset,முழு _Origin);
  __int64 __cdecl _telli64(முழு _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  முழு __cdecl chdir (மாறிலி எழுத்து *);
  எழுத்து *__cdecl getcwd (எழுத்து *, முழு);
  முழு __cdecl mkdir (மாறிலி எழுத்து *);
  எழுத்து *__cdecl mktemp(எழுத்து *);
  முழு __cdecl rmdir (மாறிலி எழுத்து*);
  முழு __cdecl chmod (மாறிலி எழுத்து *, முழு);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(முழு *_FileHandle,மாறிலி எழுத்து *_Filename,முழு _OpenFlag,முழு _ShareFlag,முழு _PermissionMode);

#ifndef __cplusplus
  _CRTIMP முழு __cdecl _open(மாறிலி எழுத்து *_Filename,முழு _OpenFlag,...);
  _CRTIMP முழு __cdecl _sopen(மாறிலி எழுத்து *_Filename,முழு _OpenFlag,முழு _ShareFlag,...);
#இல்லையெனில்
  வெளி "C++" _CRTIMP முழு __cdecl _open(மாறிலி எழுத்து *_Filename,முழு _Openflag,முழு _PermissionMode = 0);
  வெளி "C++" _CRTIMP முழு __cdecl _sopen(மாறிலி எழுத்து *_Filename,முழு _Openflag,முழு _ShareFlag,முழு _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP முழு __cdecl _waccess(மாறிலி wchar_t *_Filename,முழு _AccessMode);
  _CRTIMP முழு __cdecl _wchmod(மாறிலி wchar_t *_Filename,முழு _Mode);
  _CRTIMP முழு __cdecl _wcreat(மாறிலி wchar_t *_Filename,முழு _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata32_t *_FindData);
  _CRTIMP முழு __cdecl _wfindnext32(intptr_t _FindHandle,கட்டமைப்பு _wfinddata32_t *_FindData);
  _CRTIMP முழு __cdecl _wunlink(மாறிலி wchar_t *_Filename);
  _CRTIMP முழு __cdecl _wrename(மாறிலி wchar_t *_NewFilename,மாறிலி wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#எனில் _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(மாறிலி wchar_t *_Filename,கட்டமைப்பு _wfinddata64_t *_FindData);
  _CRTIMP முழு __cdecl _wfindnext32i64(intptr_t _FindHandle,கட்டமைப்பு _wfinddata32i64_t *_FindData);
  முழு __cdecl _wfindnext64i32(intptr_t _FindHandle,கட்டமைப்பு _wfinddata64i32_t *_FindData);
  _CRTIMP முழு __cdecl _wfindnext64(intptr_t _FindHandle,கட்டமைப்பு _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(முழு *_FileHandle,மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _ShareFlag,முழு _PermissionFlag);

#எனில் !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP முழு __cdecl _wopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,...);
  _CRTIMP முழு __cdecl _wsopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _ShareFlag,...);
#இல்லையெனில்
  வெளி "C++" _CRTIMP முழு __cdecl _wopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _PermissionMode = 0);
  வெளி "C++" _CRTIMP முழு __cdecl _wsopen(மாறிலி wchar_t *_Filename,முழு _OpenFlag,முழு _ShareFlag,முழு _PermissionMode = 0);
#endif

#endif

  முழு __cdecl __lock_fhandle(முழு _Filehandle);
  வெறுமை __cdecl _unlock_fhandle(முழு _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(முழு _FileHandle);
  _CRTIMP முழு __cdecl _open_osfhandle(intptr_t _OSFileHandle,முழு _Flags);

#ifndef	NO_OLDNAMES
  முழு __cdecl access(மாறிலி எழுத்து *_Filename,முழு _AccessMode);
  முழு __cdecl chmod(மாறிலி எழுத்து *_Filename,முழு _AccessMode);
  முழு __cdecl chsize(முழு _FileHandle,long _Size);
  முழு __cdecl close(முழு _FileHandle);
  முழு __cdecl creat(மாறிலி எழுத்து *_Filename,முழு _PermissionMode);
  முழு __cdecl dup(முழு _FileHandle);
  முழு __cdecl dup2(முழு _FileHandleSrc,முழு _FileHandleDst);
  முழு __cdecl eof(முழு _FileHandle);
  long __cdecl filelength(முழு _FileHandle);
  முழு __cdecl isatty(முழு _FileHandle);
  முழு __cdecl locking(முழு _FileHandle,முழு _LockMode,long இலக்கம்_Of_Bytes);
  long __cdecl lseek(முழு _FileHandle,long _Offset,முழு _Origin);
  எழுத்து *__cdecl mktemp(எழுத்து *_TemplateName);
  முழு __cdecl open(மாறிலி எழுத்து *_Filename,முழு _OpenFlag,...);
  முழு __cdecl பட(முழு _FileHandle,வெறுமை *_DstBuf,unsigned முழு Max_Char_மொத்தம்);
  முழு __cdecl setmode(முழு _FileHandle,முழு _Mode);
  முழு __cdecl sopen(மாறிலி எழுத்து *_Filename,முழு _OpenFlag,முழு _ShareFlag,...);
  long __cdecl tell(முழு _FileHandle);
  முழு __cdecl umask(முழு _Mode);
  முழு __cdecl லிக(முழு _Filehandle,மாறிலி வெறுமை *_Buf,unsigned முழு Max_Char_மொத்தம்);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
வெளி "C" {
#endif

/* Misc stuff */
எழுத்து *getlogin(வெறுமை);
#ifdef __USE_MINGW_ALARM
unsigned முழு alarm(unsigned முழு seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
நிலையான உள்வரி முழு __mingw_access (மாறிலி எழுத்து *__fname, முழு __mode) {
  திரும்பு  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(எடு)

#அந்தர்பாவ <sec_api/io_s.h>

#endif /* End _IO_H_ */

