
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#അന്തര്ഭാവ <_mingw.h>
#അന്തര്ഭാവ <string.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

_CRTIMP അക്ഷരം* __cdecl _getcwd (അക്ഷരം*, പൂർണ്ണസംഖ്യ);
#ifndef _FSIZE_T_DEFINED
  തരനിർവചനം unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  ഘടന _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    അക്ഷരം name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ഘടന _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    അക്ഷരം name[260];
  };

  ഘടന _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    അക്ഷരം name[260];
  };

  ഘടന __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    അക്ഷരം name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#അല്ലെങ്കിൽ
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#അല്ലെങ്കിൽ
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

  ഘടന _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ഘടന _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  ഘടന _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  ഘടന _wfinddata64_t {
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
#അല്ലെങ്കിൽ
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
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ size_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം unsigned __int64 size_t;
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം പൂർണ്ണസംഖ്യ ssize_t __attribute__ ((mode (DI)));
#അല്ലെങ്കിൽ
  തരനിർവചനം __int64 ssize_t;
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം പൂർണ്ണസംഖ്യ ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  തരനിർവചനം long _off_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#എങ്കിൽ defined(__GNUC__) && defined(__STRICT_ANSI__)
  തരനിർവചനം പൂർണ്ണസംഖ്യ _off64_t __attribute__ ((mode (DI)));
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം പൂർണ്ണസംഖ്യ off64_t __attribute__ ((mode (DI)));
#endif
#അല്ലെങ്കിൽ
  തരനിർവചനം long long _off64_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _access(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _chmod(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _Mode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _chsize(പൂർണ്ണസംഖ്യ _FileHandle,long _Size);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _close(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _commit(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _creat(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _PermissionMode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _dup(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _dup2(പൂർണ്ണസംഖ്യ _FileHandleSrc,പൂർണ്ണസംഖ്യ _FileHandleDst);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _eof(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP long __cdecl _filelength(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(സ്ഥിരം അക്ഷരം *_Filename,ഘടന _finddata32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _findnext32(intptr_t _FindHandle,ഘടന _finddata32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _isatty(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _locking(പൂർണ്ണസംഖ്യ _FileHandle,പൂർണ്ണസംഖ്യ _LockMode,long അക്കം_Of_Bytes);
  _CRTIMP long __cdecl _lseek(പൂർണ്ണസംഖ്യ _FileHandle,long _Offset,പൂർണ്ണസംഖ്യ _Origin);
  _off64_t lseek64(പൂർണ്ണസംഖ്യ fd,_off64_t offset, പൂർണ്ണസംഖ്യ whence);
  _CRTIMP അക്ഷരം *__cdecl _mktemp(അക്ഷരം *_TemplateName);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _pipe(പൂർണ്ണസംഖ്യ *_PtHandles,unsigned പൂർണ്ണസംഖ്യ _PipeSize,പൂർണ്ണസംഖ്യ _TextMode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _read(പൂർണ്ണസംഖ്യ _FileHandle,ശൂന്യം *_DstBuf,unsigned പൂർണ്ണസംഖ്യ Max_Char_എണ്ണം);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  പൂർണ്ണസംഖ്യ __cdecl remove(സ്ഥിരം അക്ഷരം *_Filename);
  പൂർണ്ണസംഖ്യ __cdecl rename(സ്ഥിരം അക്ഷരം *_OldFilename,സ്ഥിരം അക്ഷരം *_NewFilename);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _unlink(സ്ഥിരം അക്ഷരം *_Filename);
#ifndef	NO_OLDNAMES
  പൂർണ്ണസംഖ്യ __cdecl unlink(സ്ഥിരം അക്ഷരം *_Filename);
#endif
#endif

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _setmode(പൂർണ്ണസംഖ്യ _FileHandle,പൂർണ്ണസംഖ്യ _Mode);
  _CRTIMP long __cdecl _tell(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _umask(പൂർണ്ണസംഖ്യ _Mode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _write(പൂർണ്ണസംഖ്യ _FileHandle,സ്ഥിരം ശൂന്യം *_Buf,unsigned പൂർണ്ണസംഖ്യ Max_Char_എണ്ണം);

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(സ്ഥിരം അക്ഷരം *_Filename,ഘടന _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(സ്ഥിരം അക്ഷരം *_Filename,ഘടന __finddata64_t *_FindData);
#ifdef __cplusplus
#അന്തര്ഭാവ <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(സ്ഥിരം അക്ഷരം *_Filename,ഘടന _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(സ്ഥിരം അക്ഷരം *_Filename,ഘടന _finddata64i32_t *_FindData)
  {
    ഘടന __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    തിരികെ ret;
  }
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _findnext32i64(intptr_t _FindHandle,ഘടന _finddata32i64_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _findnext64(intptr_t _FindHandle,ഘടന __finddata64_t *_FindData);
  പൂർണ്ണസംഖ്യ __cdecl _findnext64i32(intptr_t _FindHandle,ഘടന _finddata64i32_t *_FindData);
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl _findnext64i32(intptr_t _FindHandle,ഘടന _finddata64i32_t *_FindData)
  {
    ഘടന __finddata64_t fd;
    പൂർണ്ണസംഖ്യ ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    തിരികെ ret;
  }
  __int64 __cdecl _lseeki64(പൂർണ്ണസംഖ്യ _FileHandle,__int64 _Offset,പൂർണ്ണസംഖ്യ _Origin);
  __int64 __cdecl _telli64(പൂർണ്ണസംഖ്യ _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  പൂർണ്ണസംഖ്യ __cdecl chdir (സ്ഥിരം അക്ഷരം *);
  അക്ഷരം *__cdecl getcwd (അക്ഷരം *, പൂർണ്ണസംഖ്യ);
  പൂർണ്ണസംഖ്യ __cdecl mkdir (സ്ഥിരം അക്ഷരം *);
  അക്ഷരം *__cdecl mktemp(അക്ഷരം *);
  പൂർണ്ണസംഖ്യ __cdecl rmdir (സ്ഥിരം അക്ഷരം*);
  പൂർണ്ണസംഖ്യ __cdecl chmod (സ്ഥിരം അക്ഷരം *, പൂർണ്ണസംഖ്യ);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(പൂർണ്ണസംഖ്യ *_FileHandle,സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,പൂർണ്ണസംഖ്യ _PermissionMode);

#ifndef __cplusplus
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _open(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sopen(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,...);
#അല്ലെങ്കിൽ
  ബാഹ്യ "C++" _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _open(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _Openflag,പൂർണ്ണസംഖ്യ _PermissionMode = 0);
  ബാഹ്യ "C++" _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _sopen(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _Openflag,പൂർണ്ണസംഖ്യ _ShareFlag,പൂർണ്ണസംഖ്യ _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _waccess(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wchmod(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _Mode);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wcreat(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wfindnext32(intptr_t _FindHandle,ഘടന _wfinddata32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wunlink(സ്ഥിരം wchar_t *_Filename);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wrename(സ്ഥിരം wchar_t *_NewFilename,സ്ഥിരം wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#എങ്കിൽ _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(സ്ഥിരം wchar_t *_Filename,ഘടന _wfinddata64_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wfindnext32i64(intptr_t _FindHandle,ഘടന _wfinddata32i64_t *_FindData);
  പൂർണ്ണസംഖ്യ __cdecl _wfindnext64i32(intptr_t _FindHandle,ഘടന _wfinddata64i32_t *_FindData);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wfindnext64(intptr_t _FindHandle,ഘടന _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(പൂർണ്ണസംഖ്യ *_FileHandle,സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,പൂർണ്ണസംഖ്യ _PermissionFlag);

#എങ്കിൽ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,...);
#അല്ലെങ്കിൽ
  ബാഹ്യ "C++" _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _PermissionMode = 0);
  ബാഹ്യ "C++" _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsopen(സ്ഥിരം wchar_t *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,പൂർണ്ണസംഖ്യ _PermissionMode = 0);
#endif

#endif

  പൂർണ്ണസംഖ്യ __cdecl __lock_fhandle(പൂർണ്ണസംഖ്യ _Filehandle);
  ശൂന്യം __cdecl _unlock_fhandle(പൂർണ്ണസംഖ്യ _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(പൂർണ്ണസംഖ്യ _FileHandle);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _open_osfhandle(intptr_t _OSFileHandle,പൂർണ്ണസംഖ്യ _Flags);

#ifndef	NO_OLDNAMES
  പൂർണ്ണസംഖ്യ __cdecl access(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  പൂർണ്ണസംഖ്യ __cdecl chmod(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _AccessMode);
  പൂർണ്ണസംഖ്യ __cdecl chsize(പൂർണ്ണസംഖ്യ _FileHandle,long _Size);
  പൂർണ്ണസംഖ്യ __cdecl close(പൂർണ്ണസംഖ്യ _FileHandle);
  പൂർണ്ണസംഖ്യ __cdecl creat(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _PermissionMode);
  പൂർണ്ണസംഖ്യ __cdecl dup(പൂർണ്ണസംഖ്യ _FileHandle);
  പൂർണ്ണസംഖ്യ __cdecl dup2(പൂർണ്ണസംഖ്യ _FileHandleSrc,പൂർണ്ണസംഖ്യ _FileHandleDst);
  പൂർണ്ണസംഖ്യ __cdecl eof(പൂർണ്ണസംഖ്യ _FileHandle);
  long __cdecl filelength(പൂർണ്ണസംഖ്യ _FileHandle);
  പൂർണ്ണസംഖ്യ __cdecl isatty(പൂർണ്ണസംഖ്യ _FileHandle);
  പൂർണ്ണസംഖ്യ __cdecl locking(പൂർണ്ണസംഖ്യ _FileHandle,പൂർണ്ണസംഖ്യ _LockMode,long അക്കം_Of_Bytes);
  long __cdecl lseek(പൂർണ്ണസംഖ്യ _FileHandle,long _Offset,പൂർണ്ണസംഖ്യ _Origin);
  അക്ഷരം *__cdecl mktemp(അക്ഷരം *_TemplateName);
  പൂർണ്ണസംഖ്യ __cdecl open(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,...);
  പൂർണ്ണസംഖ്യ __cdecl പഠ(പൂർണ്ണസംഖ്യ _FileHandle,ശൂന്യം *_DstBuf,unsigned പൂർണ്ണസംഖ്യ Max_Char_എണ്ണം);
  പൂർണ്ണസംഖ്യ __cdecl setmode(പൂർണ്ണസംഖ്യ _FileHandle,പൂർണ്ണസംഖ്യ _Mode);
  പൂർണ്ണസംഖ്യ __cdecl sopen(സ്ഥിരം അക്ഷരം *_Filename,പൂർണ്ണസംഖ്യ _OpenFlag,പൂർണ്ണസംഖ്യ _ShareFlag,...);
  long __cdecl tell(പൂർണ്ണസംഖ്യ _FileHandle);
  പൂർണ്ണസംഖ്യ __cdecl umask(പൂർണ്ണസംഖ്യ _Mode);
  പൂർണ്ണസംഖ്യ __cdecl ലിഖ(പൂർണ്ണസംഖ്യ _Filehandle,സ്ഥിരം ശൂന്യം *_Buf,unsigned പൂർണ്ണസംഖ്യ Max_Char_എണ്ണം);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

/* Misc stuff */
അക്ഷരം *getlogin(ശൂന്യം);
#ifdef __USE_MINGW_ALARM
unsigned പൂർണ്ണസംഖ്യ alarm(unsigned പൂർണ്ണസംഖ്യ seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ __mingw_access (സ്ഥിരം അക്ഷരം *__fname, പൂർണ്ണസംഖ്യ __mode) {
  തിരികെ  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(എടുക്കുക)

#അന്തര്ഭാവ <sec_api/io_s.h>

#endif /* End _IO_H_ */

