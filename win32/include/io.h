
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#অন্তর্ভাব <_mingw.h>
#অন্তর্ভাব <string.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
বাহ্য "C" {
#endif

_CRTIMP বর্ণ* __cdecl _getcwd (বর্ণ*, পূর্ণাঙ্ক);
#ifndef _FSIZE_T_DEFINED
  প্রকারনির্দেশ unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  সংরচনা _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    বর্ণ name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  সংরচনা _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    বর্ণ name[260];
  };

  সংরচনা _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    বর্ণ name[260];
  };

  সংরচনা __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    বর্ণ name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#অন্যথা
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#অন্যথা
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

  সংরচনা _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  সংরচনা _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  সংরচনা _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  সংরচনা _wfinddata64_t {
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
#অন্যথা
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
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক size_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ unsigned __int64 size_t;
#endif
#অন্যথা
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ পূর্ণাঙ্ক ssize_t __attribute__ ((mode (DI)));
#অন্যথা
  প্রকারনির্দেশ __int64 ssize_t;
#endif
#অন্যথা
  প্রকারনির্দেশ পূর্ণাঙ্ক ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  প্রকারনির্দেশ long _off_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#যদি defined(__GNUC__) && defined(__STRICT_ANSI__)
  প্রকারনির্দেশ পূর্ণাঙ্ক _off64_t __attribute__ ((mode (DI)));
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ পূর্ণাঙ্ক off64_t __attribute__ ((mode (DI)));
#endif
#অন্যথা
  প্রকারনির্দেশ long long _off64_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP পূর্ণাঙ্ক __cdecl _access(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _AccessMode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _chmod(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _Mode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _chsize(পূর্ণাঙ্ক _FileHandle,long _Size);
  _CRTIMP পূর্ণাঙ্ক __cdecl _close(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _commit(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _creat(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _PermissionMode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _dup(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _dup2(পূর্ণাঙ্ক _FileHandleSrc,পূর্ণাঙ্ক _FileHandleDst);
  _CRTIMP পূর্ণাঙ্ক __cdecl _eof(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP long __cdecl _filelength(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ধ্রুব বর্ণ *_Filename,সংরচনা _finddata32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _findnext32(intptr_t _FindHandle,সংরচনা _finddata32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _isatty(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _locking(পূর্ণাঙ্ক _FileHandle,পূর্ণাঙ্ক _LockMode,long অঙ্ক_Of_Bytes);
  _CRTIMP long __cdecl _lseek(পূর্ণাঙ্ক _FileHandle,long _Offset,পূর্ণাঙ্ক _Origin);
  _off64_t lseek64(পূর্ণাঙ্ক fd,_off64_t offset, পূর্ণাঙ্ক whence);
  _CRTIMP বর্ণ *__cdecl _mktemp(বর্ণ *_TemplateName);
  _CRTIMP পূর্ণাঙ্ক __cdecl _pipe(পূর্ণাঙ্ক *_PtHandles,unsigned পূর্ণাঙ্ক _PipeSize,পূর্ণাঙ্ক _TextMode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _read(পূর্ণাঙ্ক _FileHandle,শূন্য *_DstBuf,unsigned পূর্ণাঙ্ক Max_Char_গুনতি);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  পূর্ণাঙ্ক __cdecl remove(ধ্রুব বর্ণ *_Filename);
  পূর্ণাঙ্ক __cdecl rename(ধ্রুব বর্ণ *_OldFilename,ধ্রুব বর্ণ *_NewFilename);
  _CRTIMP পূর্ণাঙ্ক __cdecl _unlink(ধ্রুব বর্ণ *_Filename);
#ifndef	NO_OLDNAMES
  পূর্ণাঙ্ক __cdecl unlink(ধ্রুব বর্ণ *_Filename);
#endif
#endif

  _CRTIMP পূর্ণাঙ্ক __cdecl _setmode(পূর্ণাঙ্ক _FileHandle,পূর্ণাঙ্ক _Mode);
  _CRTIMP long __cdecl _tell(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _umask(পূর্ণাঙ্ক _Mode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _write(পূর্ণাঙ্ক _FileHandle,ধ্রুব শূন্য *_Buf,unsigned পূর্ণাঙ্ক Max_Char_গুনতি);

#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ধ্রুব বর্ণ *_Filename,সংরচনা _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(ধ্রুব বর্ণ *_Filename,সংরচনা __finddata64_t *_FindData);
#ifdef __cplusplus
#অন্তর্ভাব <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(ধ্রুব বর্ণ *_Filename,সংরচনা _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ধ্রুব বর্ণ *_Filename,সংরচনা _finddata64i32_t *_FindData)
  {
    সংরচনা __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    প্রত্যাগম ret;
  }
  _CRTIMP পূর্ণাঙ্ক __cdecl _findnext32i64(intptr_t _FindHandle,সংরচনা _finddata32i64_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _findnext64(intptr_t _FindHandle,সংরচনা __finddata64_t *_FindData);
  পূর্ণাঙ্ক __cdecl _findnext64i32(intptr_t _FindHandle,সংরচনা _finddata64i32_t *_FindData);
  __CRT_INLINE পূর্ণাঙ্ক __cdecl _findnext64i32(intptr_t _FindHandle,সংরচনা _finddata64i32_t *_FindData)
  {
    সংরচনা __finddata64_t fd;
    পূর্ণাঙ্ক ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    প্রত্যাগম ret;
  }
  __int64 __cdecl _lseeki64(পূর্ণাঙ্ক _FileHandle,__int64 _Offset,পূর্ণাঙ্ক _Origin);
  __int64 __cdecl _telli64(পূর্ণাঙ্ক _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  পূর্ণাঙ্ক __cdecl chdir (ধ্রুব বর্ণ *);
  বর্ণ *__cdecl getcwd (বর্ণ *, পূর্ণাঙ্ক);
  পূর্ণাঙ্ক __cdecl mkdir (ধ্রুব বর্ণ *);
  বর্ণ *__cdecl mktemp(বর্ণ *);
  পূর্ণাঙ্ক __cdecl rmdir (ধ্রুব বর্ণ*);
  পূর্ণাঙ্ক __cdecl chmod (ধ্রুব বর্ণ *, পূর্ণাঙ্ক);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(পূর্ণাঙ্ক *_FileHandle,ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,পূর্ণাঙ্ক _PermissionMode);

#ifndef __cplusplus
  _CRTIMP পূর্ণাঙ্ক __cdecl _open(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _OpenFlag,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _sopen(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,...);
#অন্যথা
  বাহ্য "C++" _CRTIMP পূর্ণাঙ্ক __cdecl _open(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _Openflag,পূর্ণাঙ্ক _PermissionMode = 0);
  বাহ্য "C++" _CRTIMP পূর্ণাঙ্ক __cdecl _sopen(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _Openflag,পূর্ণাঙ্ক _ShareFlag,পূর্ণাঙ্ক _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP পূর্ণাঙ্ক __cdecl _waccess(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _AccessMode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wchmod(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _Mode);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wcreat(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wfindnext32(intptr_t _FindHandle,সংরচনা _wfinddata32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wunlink(ধ্রুব wchar_t *_Filename);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wrename(ধ্রুব wchar_t *_NewFilename,ধ্রুব wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#যদি _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ধ্রুব wchar_t *_Filename,সংরচনা _wfinddata64_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wfindnext32i64(intptr_t _FindHandle,সংরচনা _wfinddata32i64_t *_FindData);
  পূর্ণাঙ্ক __cdecl _wfindnext64i32(intptr_t _FindHandle,সংরচনা _wfinddata64i32_t *_FindData);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wfindnext64(intptr_t _FindHandle,সংরচনা _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(পূর্ণাঙ্ক *_FileHandle,ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,পূর্ণাঙ্ক _PermissionFlag);

#যদি !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP পূর্ণাঙ্ক __cdecl _wopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _wsopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,...);
#অন্যথা
  বাহ্য "C++" _CRTIMP পূর্ণাঙ্ক __cdecl _wopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _PermissionMode = 0);
  বাহ্য "C++" _CRTIMP পূর্ণাঙ্ক __cdecl _wsopen(ধ্রুব wchar_t *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,পূর্ণাঙ্ক _PermissionMode = 0);
#endif

#endif

  পূর্ণাঙ্ক __cdecl __lock_fhandle(পূর্ণাঙ্ক _Filehandle);
  শূন্য __cdecl _unlock_fhandle(পূর্ণাঙ্ক _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(পূর্ণাঙ্ক _FileHandle);
  _CRTIMP পূর্ণাঙ্ক __cdecl _open_osfhandle(intptr_t _OSFileHandle,পূর্ণাঙ্ক _Flags);

#ifndef	NO_OLDNAMES
  পূর্ণাঙ্ক __cdecl access(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _AccessMode);
  পূর্ণাঙ্ক __cdecl chmod(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _AccessMode);
  পূর্ণাঙ্ক __cdecl chsize(পূর্ণাঙ্ক _FileHandle,long _Size);
  পূর্ণাঙ্ক __cdecl close(পূর্ণাঙ্ক _FileHandle);
  পূর্ণাঙ্ক __cdecl creat(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _PermissionMode);
  পূর্ণাঙ্ক __cdecl dup(পূর্ণাঙ্ক _FileHandle);
  পূর্ণাঙ্ক __cdecl dup2(পূর্ণাঙ্ক _FileHandleSrc,পূর্ণাঙ্ক _FileHandleDst);
  পূর্ণাঙ্ক __cdecl eof(পূর্ণাঙ্ক _FileHandle);
  long __cdecl filelength(পূর্ণাঙ্ক _FileHandle);
  পূর্ণাঙ্ক __cdecl isatty(পূর্ণাঙ্ক _FileHandle);
  পূর্ণাঙ্ক __cdecl locking(পূর্ণাঙ্ক _FileHandle,পূর্ণাঙ্ক _LockMode,long অঙ্ক_Of_Bytes);
  long __cdecl lseek(পূর্ণাঙ্ক _FileHandle,long _Offset,পূর্ণাঙ্ক _Origin);
  বর্ণ *__cdecl mktemp(বর্ণ *_TemplateName);
  পূর্ণাঙ্ক __cdecl open(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _OpenFlag,...);
  পূর্ণাঙ্ক __cdecl পঠ(পূর্ণাঙ্ক _FileHandle,শূন্য *_DstBuf,unsigned পূর্ণাঙ্ক Max_Char_গুনতি);
  পূর্ণাঙ্ক __cdecl setmode(পূর্ণাঙ্ক _FileHandle,পূর্ণাঙ্ক _Mode);
  পূর্ণাঙ্ক __cdecl sopen(ধ্রুব বর্ণ *_Filename,পূর্ণাঙ্ক _OpenFlag,পূর্ণাঙ্ক _ShareFlag,...);
  long __cdecl tell(পূর্ণাঙ্ক _FileHandle);
  পূর্ণাঙ্ক __cdecl umask(পূর্ণাঙ্ক _Mode);
  পূর্ণাঙ্ক __cdecl লিখ(পূর্ণাঙ্ক _Filehandle,ধ্রুব শূন্য *_Buf,unsigned পূর্ণাঙ্ক Max_Char_গুনতি);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
বাহ্য "C" {
#endif

/* Misc stuff */
বর্ণ *getlogin(শূন্য);
#ifdef __USE_MINGW_ALARM
unsigned পূর্ণাঙ্ক alarm(unsigned পূর্ণাঙ্ক seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
স্থির অন্তঃস্থ পূর্ণাঙ্ক __mingw_access (ধ্রুব বর্ণ *__fname, পূর্ণাঙ্ক __mode) {
  প্রত্যাগম  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/io_s.h>

#endif /* End _IO_H_ */

