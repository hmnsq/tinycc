
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <string.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

_CRTIMP ವರ್ಣ* __cdecl _getcwd (ವರ್ಣ*, ಪೂರ್ಣಾಙ್ಕ);
#ifndef _FSIZE_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  ಸಂರಚನಾ _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    ವರ್ಣ name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ಸಂರಚನಾ _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    ವರ್ಣ name[260];
  };

  ಸಂರಚನಾ _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    ವರ್ಣ name[260];
  };

  ಸಂರಚನಾ __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    ವರ್ಣ name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#ಅನ್ಯಥಾ
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#ಅನ್ಯಥಾ
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

  ಸಂರಚನಾ _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ಸಂರಚನಾ _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ಸಂರಚನಾ _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ಸಂರಚನಾ _wfinddata64_t {
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
#ಅನ್ಯಥಾ
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
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ size_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned __int64 size_t;
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ ssize_t __attribute__ ((mode (DI)));
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 ssize_t;
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ಪ್ರಕಾರನಿರ್ದೇಶ long _off_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#ಯದಿ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ _off64_t __attribute__ ((mode (DI)));
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ off64_t __attribute__ ((mode (DI)));
#endif
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ long long _off64_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _access(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _chmod(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _Mode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _chsize(ಪೂರ್ಣಾಙ್ಕ _FileHandle,long _Size);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _close(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _commit(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _creat(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _PermissionMode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _dup(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _dup2(ಪೂರ್ಣಾಙ್ಕ _FileHandleSrc,ಪೂರ್ಣಾಙ್ಕ _FileHandleDst);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _eof(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP long __cdecl _filelength(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ _finddata32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _findnext32(intptr_t _FindHandle,ಸಂರಚನಾ _finddata32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _isatty(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _locking(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಪೂರ್ಣಾಙ್ಕ _LockMode,long ಅಂಕೆ_Of_Bytes);
  _CRTIMP long __cdecl _lseek(ಪೂರ್ಣಾಙ್ಕ _FileHandle,long _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
  _off64_t lseek64(ಪೂರ್ಣಾಙ್ಕ fd,_off64_t offset, ಪೂರ್ಣಾಙ್ಕ whence);
  _CRTIMP ವರ್ಣ *__cdecl _mktemp(ವರ್ಣ *_TemplateName);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _pipe(ಪೂರ್ಣಾಙ್ಕ *_PtHandles,unsigned ಪೂರ್ಣಾಙ್ಕ _PipeSize,ಪೂರ್ಣಾಙ್ಕ _TextMode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _read(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಶೂನ್ಯ *_DstBuf,unsigned ಪೂರ್ಣಾಙ್ಕ Max_Char_ಎಣಿಕೆ);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl remove(ಧ್ರುವ ವರ್ಣ *_Filename);
  ಪೂರ್ಣಾಙ್ಕ __cdecl rename(ಧ್ರುವ ವರ್ಣ *_OldFilename,ಧ್ರುವ ವರ್ಣ *_NewFilename);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _unlink(ಧ್ರುವ ವರ್ಣ *_Filename);
#ifndef	NO_OLDNAMES
  ಪೂರ್ಣಾಙ್ಕ __cdecl unlink(ಧ್ರುವ ವರ್ಣ *_Filename);
#endif
#endif

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _setmode(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಪೂರ್ಣಾಙ್ಕ _Mode);
  _CRTIMP long __cdecl _tell(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _umask(ಪೂರ್ಣಾಙ್ಕ _Mode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _write(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಧ್ರುವ ಶೂನ್ಯ *_Buf,unsigned ಪೂರ್ಣಾಙ್ಕ Max_Char_ಎಣಿಕೆ);

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ __finddata64_t *_FindData);
#ifdef __cplusplus
#ಅನ್ತರ್ಭಾವ <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ಧ್ರುವ ವರ್ಣ *_Filename,ಸಂರಚನಾ _finddata64i32_t *_FindData)
  {
    ಸಂರಚನಾ __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ಪ್ರತ್ಯಾಗಮ ret;
  }
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _findnext32i64(intptr_t _FindHandle,ಸಂರಚನಾ _finddata32i64_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _findnext64(intptr_t _FindHandle,ಸಂರಚನಾ __finddata64_t *_FindData);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _findnext64i32(intptr_t _FindHandle,ಸಂರಚನಾ _finddata64i32_t *_FindData);
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl _findnext64i32(intptr_t _FindHandle,ಸಂರಚನಾ _finddata64i32_t *_FindData)
  {
    ಸಂರಚನಾ __finddata64_t fd;
    ಪೂರ್ಣಾಙ್ಕ ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ಪ್ರತ್ಯಾಗಮ ret;
  }
  __int64 __cdecl _lseeki64(ಪೂರ್ಣಾಙ್ಕ _FileHandle,__int64 _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
  __int64 __cdecl _telli64(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  ಪೂರ್ಣಾಙ್ಕ __cdecl chdir (ಧ್ರುವ ವರ್ಣ *);
  ವರ್ಣ *__cdecl getcwd (ವರ್ಣ *, ಪೂರ್ಣಾಙ್ಕ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl mkdir (ಧ್ರುವ ವರ್ಣ *);
  ವರ್ಣ *__cdecl mktemp(ವರ್ಣ *);
  ಪೂರ್ಣಾಙ್ಕ __cdecl rmdir (ಧ್ರುವ ವರ್ಣ*);
  ಪೂರ್ಣಾಙ್ಕ __cdecl chmod (ಧ್ರುವ ವರ್ಣ *, ಪೂರ್ಣಾಙ್ಕ);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ಪೂರ್ಣಾಙ್ಕ *_FileHandle,ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode);

#ifndef __cplusplus
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _open(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,...);
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _open(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _Openflag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode = 0);
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _sopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _Openflag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _waccess(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wchmod(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _Mode);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wcreat(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext32(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wunlink(ಧ್ರುವ wchar_t *_Filename);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wrename(ಧ್ರುವ wchar_t *_NewFilename,ಧ್ರುವ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ಯದಿ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ಧ್ರುವ wchar_t *_Filename,ಸಂರಚನಾ _wfinddata64_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext32i64(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata32i64_t *_FindData);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext64i32(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata64i32_t *_FindData);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wfindnext64(intptr_t _FindHandle,ಸಂರಚನಾ _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(ಪೂರ್ಣಾಙ್ಕ *_FileHandle,ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionFlag);

#ಯದಿ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,...);
#ಅನ್ಯಥಾ
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode = 0);
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsopen(ಧ್ರುವ wchar_t *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,ಪೂರ್ಣಾಙ್ಕ _PermissionMode = 0);
#endif

#endif

  ಪೂರ್ಣಾಙ್ಕ __cdecl __lock_fhandle(ಪೂರ್ಣಾಙ್ಕ _Filehandle);
  ಶೂನ್ಯ __cdecl _unlock_fhandle(ಪೂರ್ಣಾಙ್ಕ _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _open_osfhandle(intptr_t _OSFileHandle,ಪೂರ್ಣಾಙ್ಕ _Flags);

#ifndef	NO_OLDNAMES
  ಪೂರ್ಣಾಙ್ಕ __cdecl access(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  ಪೂರ್ಣಾಙ್ಕ __cdecl chmod(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _AccessMode);
  ಪೂರ್ಣಾಙ್ಕ __cdecl chsize(ಪೂರ್ಣಾಙ್ಕ _FileHandle,long _Size);
  ಪೂರ್ಣಾಙ್ಕ __cdecl close(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  ಪೂರ್ಣಾಙ್ಕ __cdecl creat(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _PermissionMode);
  ಪೂರ್ಣಾಙ್ಕ __cdecl dup(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  ಪೂರ್ಣಾಙ್ಕ __cdecl dup2(ಪೂರ್ಣಾಙ್ಕ _FileHandleSrc,ಪೂರ್ಣಾಙ್ಕ _FileHandleDst);
  ಪೂರ್ಣಾಙ್ಕ __cdecl eof(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  long __cdecl filelength(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  ಪೂರ್ಣಾಙ್ಕ __cdecl isatty(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  ಪೂರ್ಣಾಙ್ಕ __cdecl locking(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಪೂರ್ಣಾಙ್ಕ _LockMode,long ಅಂಕೆ_Of_Bytes);
  long __cdecl lseek(ಪೂರ್ಣಾಙ್ಕ _FileHandle,long _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
  ವರ್ಣ *__cdecl mktemp(ವರ್ಣ *_TemplateName);
  ಪೂರ್ಣಾಙ್ಕ __cdecl open(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl ಪಠ(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಶೂನ್ಯ *_DstBuf,unsigned ಪೂರ್ಣಾಙ್ಕ Max_Char_ಎಣಿಕೆ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl setmode(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಪೂರ್ಣಾಙ್ಕ _Mode);
  ಪೂರ್ಣಾಙ್ಕ __cdecl sopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಪೂರ್ಣಾಙ್ಕ _OpenFlag,ಪೂರ್ಣಾಙ್ಕ _ShareFlag,...);
  long __cdecl tell(ಪೂರ್ಣಾಙ್ಕ _FileHandle);
  ಪೂರ್ಣಾಙ್ಕ __cdecl umask(ಪೂರ್ಣಾಙ್ಕ _Mode);
  ಪೂರ್ಣಾಙ್ಕ __cdecl ಲಿಖ(ಪೂರ್ಣಾಙ್ಕ _Filehandle,ಧ್ರುವ ಶೂನ್ಯ *_Buf,unsigned ಪೂರ್ಣಾಙ್ಕ Max_Char_ಎಣಿಕೆ);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

/* Misc stuff */
ವರ್ಣ *getlogin(ಶೂನ್ಯ);
#ifdef __USE_MINGW_ALARM
unsigned ಪೂರ್ಣಾಙ್ಕ alarm(unsigned ಪೂರ್ಣಾಙ್ಕ seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ __mingw_access (ಧ್ರುವ ವರ್ಣ *__fname, ಪೂರ್ಣಾಙ್ಕ __mode) {
  ಪ್ರತ್ಯಾಗಮ  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/io_s.h>

#endif /* End _IO_H_ */

