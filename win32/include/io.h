
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _IO_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IO_H_

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _POSIX_

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

_CRTIMP ਅੱਖਰ* __cdecl _getcwd (ਅੱਖਰ*, ਪੂਰਨ);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FSIZE_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ _fsize_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FSIZE_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FINDDATA_T_DEFINED

  ਬਣਤਰ _finddata32_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time32_t ਸਮਾਂ_create;
    __time32_t ਸਮਾਂ_access;
    __time32_t ਸਮਾਂ_write;
    _fsize_t ਮਾਪ;
    ਅੱਖਰ name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ਬਣਤਰ _finddata32i64_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time32_t ਸਮਾਂ_create;
    __time32_t ਸਮਾਂ_access;
    __time32_t ਸਮਾਂ_write;
    __int64 ਮਾਪ;
    ਅੱਖਰ name[260];
  };

  ਬਣਤਰ _finddata64i32_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time64_t ਸਮਾਂ_create;
    __time64_t ਸਮਾਂ_access;
    __time64_t ਸਮਾਂ_write;
    _fsize_t ਮਾਪ;
    ਅੱਖਰ name[260];
  };

  ਬਣਤਰ __finddata64_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time64_t ਸਮਾਂ_create;
    __time64_t ਸਮਾਂ_access;
    __time64_t ਸਮਾਂ_write;
    __int64 ਮਾਪ;
    ਅੱਖਰ name[260];
  };
/* #endif */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _finddata_t _finddata32_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _finddatai64_t _finddata32i64_t

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findfirst _findfirst32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findnext _findnext32
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findfirst32 _findfirst
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findnext32 _findnext
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findfirsti64 _findfirst32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findnexti64 _findnext32i64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _finddata_t _finddata64i32_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _finddatai64_t __finddata64_t

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findfirst _findfirst64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findnext _findnext64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findfirsti64 _findfirst64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _findnexti64 _findnext64
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FINDDATA_T_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WFINDDATA_T_DEFINED

  ਬਣਤਰ _wfinddata32_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time32_t ਸਮਾਂ_create;
    __time32_t ਸਮਾਂ_access;
    __time32_t ਸਮਾਂ_write;
    _fsize_t ਮਾਪ;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ਬਣਤਰ _wfinddata32i64_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time32_t ਸਮਾਂ_create;
    __time32_t ਸਮਾਂ_access;
    __time32_t ਸਮਾਂ_write;
    __int64 ਮਾਪ;
    wchar_t name[260];
  };

  ਬਣਤਰ _wfinddata64i32_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time64_t ਸਮਾਂ_create;
    __time64_t ਸਮਾਂ_access;
    __time64_t ਸਮਾਂ_write;
    _fsize_t ਮਾਪ;
    wchar_t name[260];
  };

  ਬਣਤਰ _wfinddata64_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ attrib;
    __time64_t ਸਮਾਂ_create;
    __time64_t ਸਮਾਂ_access;
    __time64_t ਸਮਾਂ_write;
    __int64 ਮਾਪ;
    wchar_t name[260];
  };
/* #endif */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ USE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਸਮਾਂ_T
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddata_t _wfinddata32_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddatai64_t _wfinddata32i64_t

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirst _wfindfirst32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnext _wfindnext32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirsti64 _wfindfirst32i64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnexti64 _wfindnext32i64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddata_t _wfinddata64i32_t
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfinddatai64_t _wfinddata64_t

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirst _wfindfirst64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnext _wfindnext64i32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindfirsti64 _wfindfirst64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wfindnexti64 _wfindnext64
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WFINDDATA_T_DEFINED
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ A_ਸਾਧਾਰਨ 0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_RDONLY 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_HIDDEN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_SYSTEM 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_SUBDIR 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_ARCH 0x20

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਮਾਪ_t
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮਾਪ_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮਾਪ_t;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮਾਪ_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SSIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SSIZE_T_DEFINED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ssize_t
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ ssize_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 ssize_t;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ ssize_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF_T_DEFINED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF_T_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF_T_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ _off_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ off_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _OFF64_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OFF64_T_DEFINED
#ਜੇ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ _off64_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ off64_t __attribute__ ((ਬਹੁਲਕ (DI)));
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ _off64_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ off64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	F_OK	0	/* Check for file existence */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	X_OK	1	/* Check for execute permission. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	W_OK	2	/* Check for write permission */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	R_OK	4	/* Check for read permission */

  _CRTIMP ਪੂਰਨ __cdecl _access(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  _CRTIMP ਪੂਰਨ __cdecl _chmod(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ ਬਹੁਲਕ_3);
  _CRTIMP ਪੂਰਨ __cdecl _chsize(ਪੂਰਨ _FileHandle,ਲੰਮਾ ਮਾਪ_4);
  _CRTIMP ਪੂਰਨ __cdecl _close(ਪੂਰਨ _FileHandle);
  _CRTIMP ਪੂਰਨ __cdecl _commit(ਪੂਰਨ _FileHandle);
  _CRTIMP ਪੂਰਨ __cdecl _creat(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ Permission_ਬਹੁਲਕ);
  _CRTIMP ਪੂਰਨ __cdecl _dup(ਪੂਰਨ _FileHandle);
  _CRTIMP ਪੂਰਨ __cdecl _dup2(ਪੂਰਨ _FileHandleSrc,ਪੂਰਨ _FileHandleDst);
  _CRTIMP ਪੂਰਨ __cdecl _eof(ਪੂਰਨ _FileHandle);
  _CRTIMP ਲੰਮਾ __cdecl _filelength(ਪੂਰਨ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ _finddata32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _findnext32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _finddata32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _findclose(intptr_t ਲੱਭੋ_Handle);
  _CRTIMP ਪੂਰਨ __cdecl _isatty(ਪੂਰਨ _FileHandle);
  _CRTIMP ਪੂਰਨ __cdecl _locking(ਪੂਰਨ _FileHandle,ਪੂਰਨ ਤਾਲਾ_ਬਹੁਲਕ,ਲੰਮਾ ਅੰਕ_ਦਾ_ਬਾਈਟਾਂ);
  _CRTIMP ਲੰਮਾ __cdecl _lseek(ਪੂਰਨ _FileHandle,ਲੰਮਾ ਵਿੱਥ_2,ਪੂਰਨ _Origin);
  _off64_t lseek64(ਪੂਰਨ fd,_off64_t ਵਿੱਥ, ਪੂਰਨ whence);
  _CRTIMP ਅੱਖਰ *__cdecl _mktemp(ਅੱਖਰ *_TemplateName);
  _CRTIMP ਪੂਰਨ __cdecl _pipe(ਪੂਰਨ *_PtHandles,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Pipe_ਮਾਪ,ਪੂਰਨ ਪਾਠ_ਬਹੁਲਕ);
  _CRTIMP ਪੂਰਨ __cdecl _read(ਪੂਰਨ _FileHandle,ਖਾਲੀ *_DstBuf,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Max_Char_ਗਿਣਤੀ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_DIRECTORY_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_DIRECTORY_DEFINED
  ਪੂਰਨ __cdecl remove(ਅਚਲ ਅੱਖਰ *_Filename);
  ਪੂਰਨ __cdecl rename(ਅਚਲ ਅੱਖਰ *_OldFilename,ਅਚਲ ਅੱਖਰ *_NewFilename);
  _CRTIMP ਪੂਰਨ __cdecl _unlink(ਅਚਲ ਅੱਖਰ *_Filename);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਪੂਰਨ __cdecl unlink(ਅਚਲ ਅੱਖਰ *_Filename);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP ਪੂਰਨ __cdecl _setmode(ਪੂਰਨ _FileHandle,ਪੂਰਨ ਬਹੁਲਕ_3);
  _CRTIMP ਲੰਮਾ __cdecl _tell(ਪੂਰਨ _FileHandle);
  _CRTIMP ਪੂਰਨ __cdecl _umask(ਪੂਰਨ ਬਹੁਲਕ_3);
  _CRTIMP ਪੂਰਨ __cdecl _write(ਪੂਰਨ _FileHandle,ਅਚਲ ਖਾਲੀ *_Buf,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Max_Char_ਗਿਣਤੀ);

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ਪੂਰਨ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ _finddata32i64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP intptr_t __cdecl _findfirst64(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ __finddata64_t *ਲੱਭੋ_ਅੰਕੜੇ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਜੇ_ਅੰਤ
  intptr_t __cdecl _findfirst64i32(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ _finddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ਅਚਲ ਅੱਖਰ *_Filename,ਬਣਤਰ _finddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ)
  {
    ਬਣਤਰ __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    ਲੱਭੋ_ਅੰਕੜੇ->attrib=fd.attrib;
    ਲੱਭੋ_ਅੰਕੜੇ->ਸਮਾਂ_create=fd.ਸਮਾਂ_create;
    ਲੱਭੋ_ਅੰਕੜੇ->ਸਮਾਂ_access=fd.ਸਮਾਂ_access;
    ਲੱਭੋ_ਅੰਕੜੇ->ਸਮਾਂ_write=fd.ਸਮਾਂ_write;
    ਲੱਭੋ_ਅੰਕੜੇ->ਮਾਪ=(_fsize_t) fd.ਮਾਪ;
    strncpy(ਲੱਭੋ_ਅੰਕੜੇ->name,fd.name,260);
    ਵਾਪਸ ret;
  }
  _CRTIMP ਪੂਰਨ __cdecl _findnext32i64(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _finddata32i64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _findnext64(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ __finddata64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  ਪੂਰਨ __cdecl _findnext64i32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _finddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  __CRT_INLINE ਪੂਰਨ __cdecl _findnext64i32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _finddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ)
  {
    ਬਣਤਰ __finddata64_t fd;
    ਪੂਰਨ ret = _findnext64(ਲੱਭੋ_Handle,&fd);
    ਲੱਭੋ_ਅੰਕੜੇ->attrib=fd.attrib;
    ਲੱਭੋ_ਅੰਕੜੇ->ਸਮਾਂ_create=fd.ਸਮਾਂ_create;
    ਲੱਭੋ_ਅੰਕੜੇ->ਸਮਾਂ_access=fd.ਸਮਾਂ_access;
    ਲੱਭੋ_ਅੰਕੜੇ->ਸਮਾਂ_write=fd.ਸਮਾਂ_write;
    ਲੱਭੋ_ਅੰਕੜੇ->ਮਾਪ=(_fsize_t) fd.ਮਾਪ;
    strncpy(ਲੱਭੋ_ਅੰਕੜੇ->name,fd.name,260);
    ਵਾਪਸ ret;
  }
  __int64 __cdecl _lseeki64(ਪੂਰਨ _FileHandle,__int64 ਵਿੱਥ_2,ਪੂਰਨ _Origin);
  __int64 __cdecl _telli64(ਪੂਰਨ _FileHandle);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NO_OLDNAMES

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _UWIN
  ਪੂਰਨ __cdecl chdir (ਅਚਲ ਅੱਖਰ *);
  ਅੱਖਰ *__cdecl getcwd (ਅੱਖਰ *, ਪੂਰਨ);
  ਪੂਰਨ __cdecl mkdir (ਅਚਲ ਅੱਖਰ *);
  ਅੱਖਰ *__cdecl mktemp(ਅੱਖਰ *);
  ਪੂਰਨ __cdecl rmdir (ਅਚਲ ਅੱਖਰ*);
  ਪੂਰਨ __cdecl chmod (ਅਚਲ ਅੱਖਰ *, ਪੂਰਨ);
#ਜੇ_ਅੰਤ /* _UWIN */

#ਜੇ_ਅੰਤ /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ਪੂਰਨ *_FileHandle,ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,ਪੂਰਨ Permission_ਬਹੁਲਕ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
  _CRTIMP ਪੂਰਨ __cdecl _open(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _OpenFlag,...);
  _CRTIMP ਪੂਰਨ __cdecl _sopen(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,...);
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ "C++" _CRTIMP ਪੂਰਨ __cdecl _open(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _Openflag,ਪੂਰਨ Permission_ਬਹੁਲਕ = 0);
  ਬਾਹਰੀ "C++" _CRTIMP ਪੂਰਨ __cdecl _sopen(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _Openflag,ਪੂਰਨ _ShareFlag,ਪੂਰਨ Permission_ਬਹੁਲਕ = 0);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WIO_DEFINED
  _CRTIMP ਪੂਰਨ __cdecl _waccess(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  _CRTIMP ਪੂਰਨ __cdecl _wchmod(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ ਬਹੁਲਕ_3);
  _CRTIMP ਪੂਰਨ __cdecl _wcreat(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ Permission_ਬਹੁਲਕ);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wfindnext32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wunlink(ਅਚਲ wchar_t *_Filename);
  _CRTIMP ਪੂਰਨ __cdecl _wrename(ਅਚਲ wchar_t *_NewFilename,ਅਚਲ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ਜੇ INTEGRAL_MAX_ਬਿੱਟ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata32i64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  intptr_t __cdecl _wfindfirst64i32(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ਅਚਲ wchar_t *_Filename,ਬਣਤਰ _wfinddata64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wfindnext32i64(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata32i64_t *ਲੱਭੋ_ਅੰਕੜੇ);
  ਪੂਰਨ __cdecl _wfindnext64i32(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata64i32_t *ਲੱਭੋ_ਅੰਕੜੇ);
  _CRTIMP ਪੂਰਨ __cdecl _wfindnext64(intptr_t ਲੱਭੋ_Handle,ਬਣਤਰ _wfinddata64_t *ਲੱਭੋ_ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ

  _CRTIMP errno_t __cdecl _wsopen_s(ਪੂਰਨ *_FileHandle,ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,ਪੂਰਨ _PermissionFlag);

#ਜੇ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ਪੂਰਨ __cdecl _wopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,...);
  _CRTIMP ਪੂਰਨ __cdecl _wsopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,...);
#ਨਹੀਂਤਾਂ
  ਬਾਹਰੀ "C++" _CRTIMP ਪੂਰਨ __cdecl _wopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ Permission_ਬਹੁਲਕ = 0);
  ਬਾਹਰੀ "C++" _CRTIMP ਪੂਰਨ __cdecl _wsopen(ਅਚਲ wchar_t *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,ਪੂਰਨ Permission_ਬਹੁਲਕ = 0);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ

  ਪੂਰਨ __cdecl __lock_fhandle(ਪੂਰਨ _Filehandle);
  ਖਾਲੀ __cdecl _unlock_fhandle(ਪੂਰਨ _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ਪੂਰਨ _FileHandle);
  _CRTIMP ਪੂਰਨ __cdecl _open_osfhandle(intptr_t _OSFileHandle,ਪੂਰਨ _Flags);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਪੂਰਨ __cdecl access(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  ਪੂਰਨ __cdecl chmod(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ Access_ਬਹੁਲਕ);
  ਪੂਰਨ __cdecl chsize(ਪੂਰਨ _FileHandle,ਲੰਮਾ ਮਾਪ_4);
  ਪੂਰਨ __cdecl close(ਪੂਰਨ _FileHandle);
  ਪੂਰਨ __cdecl creat(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ Permission_ਬਹੁਲਕ);
  ਪੂਰਨ __cdecl dup(ਪੂਰਨ _FileHandle);
  ਪੂਰਨ __cdecl dup2(ਪੂਰਨ _FileHandleSrc,ਪੂਰਨ _FileHandleDst);
  ਪੂਰਨ __cdecl eof(ਪੂਰਨ _FileHandle);
  ਲੰਮਾ __cdecl filelength(ਪੂਰਨ _FileHandle);
  ਪੂਰਨ __cdecl isatty(ਪੂਰਨ _FileHandle);
  ਪੂਰਨ __cdecl locking(ਪੂਰਨ _FileHandle,ਪੂਰਨ ਤਾਲਾ_ਬਹੁਲਕ,ਲੰਮਾ ਅੰਕ_ਦਾ_ਬਾਈਟਾਂ);
  ਲੰਮਾ __cdecl lseek(ਪੂਰਨ _FileHandle,ਲੰਮਾ ਵਿੱਥ_2,ਪੂਰਨ _Origin);
  ਅੱਖਰ *__cdecl mktemp(ਅੱਖਰ *_TemplateName);
  ਪੂਰਨ __cdecl open(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _OpenFlag,...);
  ਪੂਰਨ __cdecl ਪਠ(ਪੂਰਨ _FileHandle,ਖਾਲੀ *_DstBuf,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Max_Char_ਗਿਣਤੀ);
  ਪੂਰਨ __cdecl setmode(ਪੂਰਨ _FileHandle,ਪੂਰਨ ਬਹੁਲਕ_3);
  ਪੂਰਨ __cdecl sopen(ਅਚਲ ਅੱਖਰ *_Filename,ਪੂਰਨ _OpenFlag,ਪੂਰਨ _ShareFlag,...);
  ਲੰਮਾ __cdecl tell(ਪੂਰਨ _FileHandle);
  ਪੂਰਨ __cdecl umask(ਪੂਰਨ ਬਹੁਲਕ_3);
  ਪੂਰਨ __cdecl ਲਿਖ(ਪੂਰਨ _Filehandle,ਅਚਲ ਖਾਲੀ *_Buf,ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Max_Char_ਗਿਣਤੀ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

/* Misc stuff */
ਅੱਖਰ *getlogin(ਖਾਲੀ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __USE_MINGW_ALARM
ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ alarm(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ seconds);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ __mingw_access (ਅਚਲ ਅੱਖਰ *__fname, ਪੂਰਨ __mode) {
  ਵਾਪਸ  _access (__fname, __mode & ~X_OK);
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ access(__f,__m)  __mingw_access (__f, __m)
#ਜੇ_ਅੰਤ


#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ


#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/io_s.h>

#ਜੇ_ਅੰਤ /* End _IO_H_ */

