
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _IO_H_
#define _IO_H_

#અન્તર્ભાવ <_mingw.h>
#અન્તર્ભાવ <string.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifndef _POSIX_

#ifdef __cplusplus
બાહ્ય "C" {
#endif

_CRTIMP અક્ષર* __cdecl _getcwd (અક્ષર*, પૂર્ણાંક);
#ifndef _FSIZE_T_DEFINED
  પ્રકારવ્યાખ્યા unsigned long _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED

  સંરચના _finddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    અક્ષર name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  સંરચના _finddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    અક્ષર name[260];
  };

  સંરચના _finddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    અક્ષર name[260];
  };

  સંરચના __finddata64_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    અક્ષર name[260];
  };
/* #endif */

#ifdef _USE_32BIT_TIME_T
#define _finddata_t _finddata32_t
#define _finddatai64_t _finddata32i64_t

#ifdef _WIN64
#define _findfirst _findfirst32
#define _findnext _findnext32
#નહીંતર
#define _findfirst32 _findfirst
#define _findnext32 _findnext
#endif
#define _findfirsti64 _findfirst32i64
#define _findnexti64 _findnext32i64
#નહીંતર
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

  સંરચના _wfinddata32_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  સંરચના _wfinddata32i64_t {
    unsigned attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  સંરચના _wfinddata64i32_t {
    unsigned attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  સંરચના _wfinddata64_t {
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
#નહીંતર
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
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક size_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા unsigned __int64 size_t;
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#undef ssize_t
#ifdef _WIN64
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા પૂર્ણાંક ssize_t __attribute__ ((mode (DI)));
#નહીંતર
  પ્રકારવ્યાખ્યા __int64 ssize_t;
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા પૂર્ણાંક ssize_t;
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  પ્રકારવ્યાખ્યા long _off_t;
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
#જો defined(__GNUC__) && defined(__STRICT_ANSI__)
  પ્રકારવ્યાખ્યા પૂર્ણાંક _off64_t __attribute__ ((mode (DI)));
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા પૂર્ણાંક off64_t __attribute__ ((mode (DI)));
#endif
#નહીંતર
  પ્રકારવ્યાખ્યા long long _off64_t;
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા long long off64_t;
#endif
#endif
#endif

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#define	F_OK	0	/* Check for file existence */
#define	X_OK	1	/* Check for execute permission. */
#define	W_OK	2	/* Check for write permission */
#define	R_OK	4	/* Check for read permission */

  _CRTIMP પૂર્ણાંક __cdecl _access(અચલ અક્ષર *_Filename,પૂર્ણાંક _AccessMode);
  _CRTIMP પૂર્ણાંક __cdecl _chmod(અચલ અક્ષર *_Filename,પૂર્ણાંક _Mode);
  _CRTIMP પૂર્ણાંક __cdecl _chsize(પૂર્ણાંક _FileHandle,long _Size);
  _CRTIMP પૂર્ણાંક __cdecl _close(પૂર્ણાંક _FileHandle);
  _CRTIMP પૂર્ણાંક __cdecl _commit(પૂર્ણાંક _FileHandle);
  _CRTIMP પૂર્ણાંક __cdecl _creat(અચલ અક્ષર *_Filename,પૂર્ણાંક _PermissionMode);
  _CRTIMP પૂર્ણાંક __cdecl _dup(પૂર્ણાંક _FileHandle);
  _CRTIMP પૂર્ણાંક __cdecl _dup2(પૂર્ણાંક _FileHandleSrc,પૂર્ણાંક _FileHandleDst);
  _CRTIMP પૂર્ણાંક __cdecl _eof(પૂર્ણાંક _FileHandle);
  _CRTIMP long __cdecl _filelength(પૂર્ણાંક _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(અચલ અક્ષર *_Filename,સંરચના _finddata32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _findnext32(intptr_t _FindHandle,સંરચના _finddata32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP પૂર્ણાંક __cdecl _isatty(પૂર્ણાંક _FileHandle);
  _CRTIMP પૂર્ણાંક __cdecl _locking(પૂર્ણાંક _FileHandle,પૂર્ણાંક _LockMode,long અંક_Of_Bytes);
  _CRTIMP long __cdecl _lseek(પૂર્ણાંક _FileHandle,long _Offset,પૂર્ણાંક _Origin);
  _off64_t lseek64(પૂર્ણાંક fd,_off64_t offset, પૂર્ણાંક whence);
  _CRTIMP અક્ષર *__cdecl _mktemp(અક્ષર *_TemplateName);
  _CRTIMP પૂર્ણાંક __cdecl _pipe(પૂર્ણાંક *_PtHandles,unsigned પૂર્ણાંક _PipeSize,પૂર્ણાંક _TextMode);
  _CRTIMP પૂર્ણાંક __cdecl _read(પૂર્ણાંક _FileHandle,શૂન્ય *_DstBuf,unsigned પૂર્ણાંક Max_Char_ગણતરી);

#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  પૂર્ણાંક __cdecl remove(અચલ અક્ષર *_Filename);
  પૂર્ણાંક __cdecl rename(અચલ અક્ષર *_OldFilename,અચલ અક્ષર *_NewFilename);
  _CRTIMP પૂર્ણાંક __cdecl _unlink(અચલ અક્ષર *_Filename);
#ifndef	NO_OLDNAMES
  પૂર્ણાંક __cdecl unlink(અચલ અક્ષર *_Filename);
#endif
#endif

  _CRTIMP પૂર્ણાંક __cdecl _setmode(પૂર્ણાંક _FileHandle,પૂર્ણાંક _Mode);
  _CRTIMP long __cdecl _tell(પૂર્ણાંક _FileHandle);
  _CRTIMP પૂર્ણાંક __cdecl _umask(પૂર્ણાંક _Mode);
  _CRTIMP પૂર્ણાંક __cdecl _write(પૂર્ણાંક _FileHandle,અચલ શૂન્ય *_Buf,unsigned પૂર્ણાંક Max_Char_ગણતરી);

#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(પૂર્ણાંક _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(અચલ અક્ષર *_Filename,સંરચના _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(અચલ અક્ષર *_Filename,સંરચના __finddata64_t *_FindData);
#ifdef __cplusplus
#અન્તર્ભાવ <string.h>
#endif
  intptr_t __cdecl _findfirst64i32(અચલ અક્ષર *_Filename,સંરચના _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(અચલ અક્ષર *_Filename,સંરચના _finddata64i32_t *_FindData)
  {
    સંરચના __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    પાછા ret;
  }
  _CRTIMP પૂર્ણાંક __cdecl _findnext32i64(intptr_t _FindHandle,સંરચના _finddata32i64_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _findnext64(intptr_t _FindHandle,સંરચના __finddata64_t *_FindData);
  પૂર્ણાંક __cdecl _findnext64i32(intptr_t _FindHandle,સંરચના _finddata64i32_t *_FindData);
  __CRT_INLINE પૂર્ણાંક __cdecl _findnext64i32(intptr_t _FindHandle,સંરચના _finddata64i32_t *_FindData)
  {
    સંરચના __finddata64_t fd;
    પૂર્ણાંક ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    પાછા ret;
  }
  __int64 __cdecl _lseeki64(પૂર્ણાંક _FileHandle,__int64 _Offset,પૂર્ણાંક _Origin);
  __int64 __cdecl _telli64(પૂર્ણાંક _FileHandle);
#endif
#ifndef NO_OLDNAMES

#ifndef _UWIN
  પૂર્ણાંક __cdecl chdir (અચલ અક્ષર *);
  અક્ષર *__cdecl getcwd (અક્ષર *, પૂર્ણાંક);
  પૂર્ણાંક __cdecl mkdir (અચલ અક્ષર *);
  અક્ષર *__cdecl mktemp(અક્ષર *);
  પૂર્ણાંક __cdecl rmdir (અચલ અક્ષર*);
  પૂર્ણાંક __cdecl chmod (અચલ અક્ષર *, પૂર્ણાંક);
#endif /* _UWIN */

#endif /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(પૂર્ણાંક *_FileHandle,અચલ અક્ષર *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,પૂર્ણાંક _PermissionMode);

#ifndef __cplusplus
  _CRTIMP પૂર્ણાંક __cdecl _open(અચલ અક્ષર *_Filename,પૂર્ણાંક _OpenFlag,...);
  _CRTIMP પૂર્ણાંક __cdecl _sopen(અચલ અક્ષર *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,...);
#નહીંતર
  બાહ્ય "C++" _CRTIMP પૂર્ણાંક __cdecl _open(અચલ અક્ષર *_Filename,પૂર્ણાંક _Openflag,પૂર્ણાંક _PermissionMode = 0);
  બાહ્ય "C++" _CRTIMP પૂર્ણાંક __cdecl _sopen(અચલ અક્ષર *_Filename,પૂર્ણાંક _Openflag,પૂર્ણાંક _ShareFlag,પૂર્ણાંક _PermissionMode = 0);
#endif

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
  _CRTIMP પૂર્ણાંક __cdecl _waccess(અચલ wchar_t *_Filename,પૂર્ણાંક _AccessMode);
  _CRTIMP પૂર્ણાંક __cdecl _wchmod(અચલ wchar_t *_Filename,પૂર્ણાંક _Mode);
  _CRTIMP પૂર્ણાંક __cdecl _wcreat(અચલ wchar_t *_Filename,પૂર્ણાંક _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(અચલ wchar_t *_Filename,સંરચના _wfinddata32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wfindnext32(intptr_t _FindHandle,સંરચના _wfinddata32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wunlink(અચલ wchar_t *_Filename);
  _CRTIMP પૂર્ણાંક __cdecl _wrename(અચલ wchar_t *_NewFilename,અચલ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#જો _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(અચલ wchar_t *_Filename,સંરચના _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(અચલ wchar_t *_Filename,સંરચના _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(અચલ wchar_t *_Filename,સંરચના _wfinddata64_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wfindnext32i64(intptr_t _FindHandle,સંરચના _wfinddata32i64_t *_FindData);
  પૂર્ણાંક __cdecl _wfindnext64i32(intptr_t _FindHandle,સંરચના _wfinddata64i32_t *_FindData);
  _CRTIMP પૂર્ણાંક __cdecl _wfindnext64(intptr_t _FindHandle,સંરચના _wfinddata64_t *_FindData);
#endif

  _CRTIMP errno_t __cdecl _wsopen_s(પૂર્ણાંક *_FileHandle,અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,પૂર્ણાંક _PermissionFlag);

#જો !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP પૂર્ણાંક __cdecl _wopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,...);
  _CRTIMP પૂર્ણાંક __cdecl _wsopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,...);
#નહીંતર
  બાહ્ય "C++" _CRTIMP પૂર્ણાંક __cdecl _wopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _PermissionMode = 0);
  બાહ્ય "C++" _CRTIMP પૂર્ણાંક __cdecl _wsopen(અચલ wchar_t *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,પૂર્ણાંક _PermissionMode = 0);
#endif

#endif

  પૂર્ણાંક __cdecl __lock_fhandle(પૂર્ણાંક _Filehandle);
  શૂન્ય __cdecl _unlock_fhandle(પૂર્ણાંક _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(પૂર્ણાંક _FileHandle);
  _CRTIMP પૂર્ણાંક __cdecl _open_osfhandle(intptr_t _OSFileHandle,પૂર્ણાંક _Flags);

#ifndef	NO_OLDNAMES
  પૂર્ણાંક __cdecl access(અચલ અક્ષર *_Filename,પૂર્ણાંક _AccessMode);
  પૂર્ણાંક __cdecl chmod(અચલ અક્ષર *_Filename,પૂર્ણાંક _AccessMode);
  પૂર્ણાંક __cdecl chsize(પૂર્ણાંક _FileHandle,long _Size);
  પૂર્ણાંક __cdecl close(પૂર્ણાંક _FileHandle);
  પૂર્ણાંક __cdecl creat(અચલ અક્ષર *_Filename,પૂર્ણાંક _PermissionMode);
  પૂર્ણાંક __cdecl dup(પૂર્ણાંક _FileHandle);
  પૂર્ણાંક __cdecl dup2(પૂર્ણાંક _FileHandleSrc,પૂર્ણાંક _FileHandleDst);
  પૂર્ણાંક __cdecl eof(પૂર્ણાંક _FileHandle);
  long __cdecl filelength(પૂર્ણાંક _FileHandle);
  પૂર્ણાંક __cdecl isatty(પૂર્ણાંક _FileHandle);
  પૂર્ણાંક __cdecl locking(પૂર્ણાંક _FileHandle,પૂર્ણાંક _LockMode,long અંક_Of_Bytes);
  long __cdecl lseek(પૂર્ણાંક _FileHandle,long _Offset,પૂર્ણાંક _Origin);
  અક્ષર *__cdecl mktemp(અક્ષર *_TemplateName);
  પૂર્ણાંક __cdecl open(અચલ અક્ષર *_Filename,પૂર્ણાંક _OpenFlag,...);
  પૂર્ણાંક __cdecl પઠ(પૂર્ણાંક _FileHandle,શૂન્ય *_DstBuf,unsigned પૂર્ણાંક Max_Char_ગણતરી);
  પૂર્ણાંક __cdecl setmode(પૂર્ણાંક _FileHandle,પૂર્ણાંક _Mode);
  પૂર્ણાંક __cdecl sopen(અચલ અક્ષર *_Filename,પૂર્ણાંક _OpenFlag,પૂર્ણાંક _ShareFlag,...);
  long __cdecl tell(પૂર્ણાંક _FileHandle);
  પૂર્ણાંક __cdecl umask(પૂર્ણાંક _Mode);
  પૂર્ણાંક __cdecl લિખ(પૂર્ણાંક _Filehandle,અચલ શૂન્ય *_Buf,unsigned પૂર્ણાંક Max_Char_ગણતરી);
#endif

#ifdef __cplusplus
}
#endif
#endif

#ifdef __cplusplus
બાહ્ય "C" {
#endif

/* Misc stuff */
અક્ષર *getlogin(શૂન્ય);
#ifdef __USE_MINGW_ALARM
unsigned પૂર્ણાંક alarm(unsigned પૂર્ણાંક seconds);
#endif

#ifdef __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
સ્થિર અંતઃરેખ પૂર્ણાંક __mingw_access (અચલ અક્ષર *__fname, પૂર્ણાંક __mode) {
  પાછા  _access (__fname, __mode & ~X_OK);
}

#define access(__f,__m)  __mingw_access (__f, __m)
#endif


#ifdef __cplusplus
}
#endif


#pragma pack(કાઢો)

#અન્તર્ભાવ <sec_api/io_s.h>

#endif /* End _IO_H_ */

