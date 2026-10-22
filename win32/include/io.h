
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#ଅନ୍ତର୍ଭାଵ <_mingw.h>
#ଅନ୍ତର୍ଭାଵ <string.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

_CRTIMP ଅକ୍ଷର* __cdecl _getcwd (ଅକ୍ଷର*, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
#ifndef _FSIZE_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  ସଂରଚନା _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    ଅକ୍ଷର name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ସଂରଚନା _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    ଅକ୍ଷର name[260];
  };

  ସଂରଚନା _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    ଅକ୍ଷର name[260];
  };

  ସଂରଚନା __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    ଅକ୍ଷର name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#ଅନ୍ୟଥା
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#ଅନ୍ୟଥା
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

  ସଂରଚନା _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ସଂରଚନା _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ସଂରଚନା _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ସଂରଚନା _wfinddata64_t {
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
#ଅନ୍ୟଥା
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
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା size_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned __int64 size_t;
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା ssize_t __attribute__ ((mode (DI)));
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 ssize_t;
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long _off_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#ଯଦି defined(__GNUC__) && defined(__STRICT_ANSI__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା _off64_t __attribute__ ((mode (DI)));
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା off64_t __attribute__ ((mode (DI)));
#endif
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long _off64_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _access(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _chmod(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _chsize(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,long _Size);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _close(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _commit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _creat(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _dup(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _dup2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandleSrc,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandleDst);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _eof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP long __cdecl _filelength(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା _finddata32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _findnext32(intptr_t _FindHandle,ସଂରଚନା _finddata32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _isatty(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _locking(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _LockMode,long ଅଙ୍କ_Of_Bytes);
  _CRTIMP long __cdecl _lseek(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,long _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
  _off64_t lseek64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd,_off64_t offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା whence);
  _CRTIMP ଅକ୍ଷର *__cdecl _mktemp(ଅକ୍ଷର *_TemplateName);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _pipe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_PtHandles,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PipeSize,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _TextMode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _read(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ଶୂନ୍ୟ *_DstBuf,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା Max_Char_ଗଣନା);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl remove(ଅଚଳ ଅକ୍ଷର *_Filename);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl rename(ଅଚଳ ଅକ୍ଷର *_OldFilename,ଅଚଳ ଅକ୍ଷର *_NewFilename);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _unlink(ଅଚଳ ଅକ୍ଷର *_Filename);
#ifndef	NO_OLDNAMES
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl unlink(ଅଚଳ ଅକ୍ଷର *_Filename);
#endif
#endif

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _setmode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  _CRTIMP long __cdecl _tell(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _umask(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _write(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ଅଚଳ ଶୂନ୍ୟ *_Buf,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା Max_Char_ଗଣନା);

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା __finddata64_t *_FindData);
#ifdef __cplusplus
#ଅନ୍ତର୍ଭାଵ <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ଅଚଳ ଅକ୍ଷର *_Filename,ସଂରଚନା _finddata64i32_t *_FindData)
  {
    ସଂରଚନା __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ଫେରନ୍ତୁ ret;
  }
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _findnext32i64(intptr_t _FindHandle,ସଂରଚନା _finddata32i64_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _findnext64(intptr_t _FindHandle,ସଂରଚନା __finddata64_t *_FindData);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _findnext64i32(intptr_t _FindHandle,ସଂରଚନା _finddata64i32_t *_FindData);
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _findnext64i32(intptr_t _FindHandle,ସଂରଚନା _finddata64i32_t *_FindData)
  {
    ସଂରଚନା __finddata64_t fd;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    ଫେରନ୍ତୁ ret;
  }
  __int64 __cdecl _lseeki64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,__int64 _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
  __int64 __cdecl _telli64(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl chdir (ଅଚଳ ଅକ୍ଷର *);
  ଅକ୍ଷର *__cdecl getcwd (ଅକ୍ଷର *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl mkdir (ଅଚଳ ଅକ୍ଷର *);
  ଅକ୍ଷର *__cdecl mktemp(ଅକ୍ଷର *);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl rmdir (ଅଚଳ ଅକ୍ଷର*);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl chmod (ଅଚଳ ଅକ୍ଷର *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_FileHandle,ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode);

#ifndef __cplusplus
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _open(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sopen(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,...);
#ଅନ୍ୟଥା
  ବାହ୍ୟ "C++" _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _open(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Openflag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode = 0);
  ବାହ୍ୟ "C++" _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _sopen(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Openflag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _waccess(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wchmod(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wcreat(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext32(intptr_t _FindHandle,ସଂରଚନା _wfinddata32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wunlink(ଅଚଳ wchar_t *_Filename);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wrename(ଅଚଳ wchar_t *_NewFilename,ଅଚଳ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ଯଦି _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ଅଚଳ wchar_t *_Filename,ସଂରଚନା _wfinddata64_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext32i64(intptr_t _FindHandle,ସଂରଚନା _wfinddata32i64_t *_FindData);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext64i32(intptr_t _FindHandle,ସଂରଚନା _wfinddata64i32_t *_FindData);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wfindnext64(intptr_t _FindHandle,ସଂରଚନା _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_FileHandle,ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionFlag);

#ଯଦି !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,...);
#ଅନ୍ୟଥା
  ବାହ୍ୟ "C++" _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode = 0);
  ବାହ୍ୟ "C++" _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsopen(ଅଚଳ wchar_t *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode = 0);
#endif

#endif

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __lock_fhandle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Filehandle);
  ଶୂନ୍ୟ __cdecl _unlock_fhandle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _open_osfhandle(intptr_t _OSFileHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Flags);

#ifndef	NO_OLDNAMES
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl access(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl chmod(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _AccessMode);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl chsize(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,long _Size);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl close(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl creat(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _PermissionMode);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl dup(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl dup2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandleSrc,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandleDst);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl eof(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  long __cdecl filelength(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl isatty(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl locking(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _LockMode,long ଅଙ୍କ_Of_Bytes);
  long __cdecl lseek(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,long _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
  ଅକ୍ଷର *__cdecl mktemp(ଅକ୍ଷର *_TemplateName);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl open(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ପଠ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ଶୂନ୍ୟ *_DstBuf,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା Max_Char_ଗଣନା);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl setmode(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl sopen(ଅଚଳ ଅକ୍ଷର *_Filename,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _OpenFlag,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShareFlag,...);
  long __cdecl tell(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl umask(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ଲିଖ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Filehandle,ଅଚଳ ଶୂନ୍ୟ *_Buf,unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା Max_Char_ଗଣନା);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

/* Misc stuff */
ଅକ୍ଷର *getlogin(ଶୂନ୍ୟ);
#ifdef __USE_MINGW_ALARM
unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା alarm(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mingw_access (ଅଚଳ ଅକ୍ଷର *__fname, ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mode) {
  ଫେରନ୍ତୁ  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(କାଢ଼)

#ଅନ୍ତର୍ଭାଵ <sec_api/io_s.h>

#endif /* End _IO_H_ */

