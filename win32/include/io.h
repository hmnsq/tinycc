
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _IO_H_
#وصف_ڪريو _IO_H_

#ضمن <_mingw.h>
#ضمن <string.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_نه_ٿيل _POSIX_

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

_CRTIMP حرف* __cdecl _getcwd (حرف*, صحيح);
#جيڪڏهن_وصف_نه_ٿيل _FSIZE_T_DEFINED
  تعريفنوع بنانشان ڊگهو _fsize_t;
#وصف_ڪريو _FSIZE_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _FINDDATA_T_DEFINED

  بنية _finddata32_t {
    بنانشان attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    _fsize_t سائيز;
    حرف name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  بنية _finddata32i64_t {
    بنانشان attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    __int64 سائيز;
    حرف name[260];
  };

  بنية _finddata64i32_t {
    بنانشان attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    _fsize_t سائيز;
    حرف name[260];
  };

  بنية __finddata64_t {
    بنانشان attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    __int64 سائيز;
    حرف name[260];
  };
/* #endif */

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#وصف_ڪريو _finddata_t _finddata32_t
#وصف_ڪريو _finddatai64_t _finddata32i64_t

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو _findfirst _findfirst32
#وصف_ڪريو _findnext _findnext32
#وإلا
#وصف_ڪريو _findfirst32 _findfirst
#وصف_ڪريو _findnext32 _findnext
#جيڪڏهن_پورو
#وصف_ڪريو _findfirsti64 _findfirst32i64
#وصف_ڪريو _findnexti64 _findnext32i64
#وإلا
#وصف_ڪريو _finddata_t _finddata64i32_t
#وصف_ڪريو _finddatai64_t __finddata64_t

#وصف_ڪريو _findfirst _findfirst64i32
#وصف_ڪريو _findnext _findnext64i32
#وصف_ڪريو _findfirsti64 _findfirst64
#وصف_ڪريو _findnexti64 _findnext64
#جيڪڏهن_پورو

#وصف_ڪريو _FINDDATA_T_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WFINDDATA_T_DEFINED

  بنية _wfinddata32_t {
    بنانشان attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    _fsize_t سائيز;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بنانشان attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    __int64 سائيز;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بنانشان attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    _fsize_t سائيز;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بنانشان attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    __int64 سائيز;
    wchar_t name[260];
  };
/* #endif */

#جيڪڏهن_وصف_ٿيل USE_32_ٻٽو_انگ_وقت_T
#وصف_ڪريو _wfinddata_t _wfinddata32_t
#وصف_ڪريو _wfinddatai64_t _wfinddata32i64_t

#وصف_ڪريو _wfindfirst _wfindfirst32
#وصف_ڪريو _wfindnext _wfindnext32
#وصف_ڪريو _wfindfirsti64 _wfindfirst32i64
#وصف_ڪريو _wfindnexti64 _wfindnext32i64
#وإلا
#وصف_ڪريو _wfinddata_t _wfinddata64i32_t
#وصف_ڪريو _wfinddatai64_t _wfinddata64_t

#وصف_ڪريو _wfindfirst _wfindfirst64i32
#وصف_ڪريو _wfindnext _wfindnext64i32
#وصف_ڪريو _wfindfirsti64 _wfindfirst64
#وصف_ڪريو _wfindnexti64 _wfindnext64
#جيڪڏهن_پورو

#وصف_ڪريو _WFINDDATA_T_DEFINED
#جيڪڏهن_پورو

#وصف_ڪريو A_عام 0x00
#وصف_ڪريو _A_RDONLY 0x01
#وصف_ڪريو _A_HIDDEN 0x02
#وصف_ڪريو _A_SYSTEM 0x04
#وصف_ڪريو _A_SUBDIR 0x10
#وصف_ڪريو _A_ARCH 0x20

#جيڪڏهن_وصف_نه_ٿيل _SIZE_T_DEFINED
#وصف_ڪريو _SIZE_T_DEFINED
#وصف_رد سائيز_t
#جيڪڏهن_وصف_ٿيل _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بنانشان صحيح سائيز_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع بنانشان __int64 سائيز_t;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع بنانشان صحيح سائيز_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _SSIZE_T_DEFINED
#وصف_ڪريو _SSIZE_T_DEFINED
#وصف_رد ssize_t
#جيڪڏهن_وصف_ٿيل _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((گهڻائي (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع صحيح ssize_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF_T_DEFINED
#وصف_ڪريو _OFF_T_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _OFF_T_
#وصف_ڪريو _OFF_T_
  تعريفنوع ڊگهو _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو off_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF64_T_DEFINED
#وصف_ڪريو _OFF64_T_DEFINED
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _off64_t __attribute__ ((گهڻائي (DI)));
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع صحيح off64_t __attribute__ ((گهڻائي (DI)));
#جيڪڏهن_پورو
#وإلا
  تعريفنوع ڊگهو ڊگهو _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو ڊگهو off64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#وصف_ڪريو	F_OK	0	/* Check for file existence */
#وصف_ڪريو	X_OK	1	/* Check for execute permission. */
#وصف_ڪريو	W_OK	2	/* Check for write permission */
#وصف_ڪريو	R_OK	4	/* Check for read permission */

  _CRTIMP صحيح __cdecl _access(ثابت حرف *_Filename,صحيح Access_گهڻائي);
  _CRTIMP صحيح __cdecl _chmod(ثابت حرف *_Filename,صحيح گهڻائي_3);
  _CRTIMP صحيح __cdecl _chsize(صحيح _FileHandle,ڊگهو سائيز_4);
  _CRTIMP صحيح __cdecl _close(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _commit(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _creat(ثابت حرف *_Filename,صحيح Permission_گهڻائي);
  _CRTIMP صحيح __cdecl _dup(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  _CRTIMP صحيح __cdecl _eof(صحيح _FileHandle);
  _CRTIMP ڊگهو __cdecl _filelength(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت حرف *_Filename,بنية _finddata32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _findnext32(intptr_t ڳوليو_Handle,بنية _finddata32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _findclose(intptr_t ڳوليو_Handle);
  _CRTIMP صحيح __cdecl _isatty(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _locking(صحيح _FileHandle,صحيح تالو_گهڻائي,ڊگهو انگ_جو_بائيٽون);
  _CRTIMP ڊگهو __cdecl _lseek(صحيح _FileHandle,ڊگهو وٿي_2,صحيح _Origin);
  _off64_t lseek64(صحيح fd,_off64_t وٿي, صحيح whence);
  _CRTIMP حرف *__cdecl _mktemp(حرف *_TemplateName);
  _CRTIMP صحيح __cdecl _pipe(صحيح *_PtHandles,بنانشان صحيح Pipe_سائيز,صحيح متن_گهڻائي);
  _CRTIMP صحيح __cdecl _read(صحيح _FileHandle,فراغ *_DstBuf,بنانشان صحيح Max_Char_ڳڻپ);

#جيڪڏهن_وصف_نه_ٿيل _CRT_DIRECTORY_DEFINED
#وصف_ڪريو _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  _CRTIMP صحيح __cdecl _setmode(صحيح _FileHandle,صحيح گهڻائي_3);
  _CRTIMP ڊگهو __cdecl _tell(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _umask(صحيح گهڻائي_3);
  _CRTIMP صحيح __cdecl _write(صحيح _FileHandle,ثابت فراغ *_Buf,بنانشان صحيح Max_Char_ڳڻپ);

#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت حرف *_Filename,بنية _finddata32i64_t *ڳوليو_معلومات);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت حرف *_Filename,بنية __finddata64_t *ڳوليو_معلومات);
#جيڪڏهن_وصف_ٿيل __cplusplus
#ضمن <string.h>
#جيڪڏهن_پورو
  intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *ڳوليو_معلومات);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *ڳوليو_معلومات)
  {
    بنية __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    ڳوليو_معلومات->attrib=fd.attrib;
    ڳوليو_معلومات->وقت_create=fd.وقت_create;
    ڳوليو_معلومات->وقت_access=fd.وقت_access;
    ڳوليو_معلومات->وقت_write=fd.وقت_write;
    ڳوليو_معلومات->سائيز=(_fsize_t) fd.سائيز;
    strncpy(ڳوليو_معلومات->name,fd.name,260);
    أرجع ret;
  }
  _CRTIMP صحيح __cdecl _findnext32i64(intptr_t ڳوليو_Handle,بنية _finddata32i64_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _findnext64(intptr_t ڳوليو_Handle,بنية __finddata64_t *ڳوليو_معلومات);
  صحيح __cdecl _findnext64i32(intptr_t ڳوليو_Handle,بنية _finddata64i32_t *ڳوليو_معلومات);
  __CRT_INLINE صحيح __cdecl _findnext64i32(intptr_t ڳوليو_Handle,بنية _finddata64i32_t *ڳوليو_معلومات)
  {
    بنية __finddata64_t fd;
    صحيح ret = _findnext64(ڳوليو_Handle,&fd);
    ڳوليو_معلومات->attrib=fd.attrib;
    ڳوليو_معلومات->وقت_create=fd.وقت_create;
    ڳوليو_معلومات->وقت_access=fd.وقت_access;
    ڳوليو_معلومات->وقت_write=fd.وقت_write;
    ڳوليو_معلومات->سائيز=(_fsize_t) fd.سائيز;
    strncpy(ڳوليو_معلومات->name,fd.name,260);
    أرجع ret;
  }
  __int64 __cdecl _lseeki64(صحيح _FileHandle,__int64 وٿي_2,صحيح _Origin);
  __int64 __cdecl _telli64(صحيح _FileHandle);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل NO_OLDNAMES

#جيڪڏهن_وصف_نه_ٿيل _UWIN
  صحيح __cdecl chdir (ثابت حرف *);
  حرف *__cdecl getcwd (حرف *, صحيح);
  صحيح __cdecl mkdir (ثابت حرف *);
  حرف *__cdecl mktemp(حرف *);
  صحيح __cdecl rmdir (ثابت حرف*);
  صحيح __cdecl chmod (ثابت حرف *, صحيح);
#جيڪڏهن_پورو /* _UWIN */

#جيڪڏهن_پورو /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحيح *_FileHandle,ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_گهڻائي);

#جيڪڏهن_وصف_نه_ٿيل __cplusplus
  _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _Openflag,صحيح Permission_گهڻائي = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _Openflag,صحيح _ShareFlag,صحيح Permission_گهڻائي = 0);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WIO_DEFINED
#وصف_ڪريو _WIO_DEFINED
  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_گهڻائي);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح گهڻائي_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_گهڻائي);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t ڳوليو_Handle,بنية _wfinddata32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#إذا INTEGRAL_MAX_بٽ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *ڳوليو_معلومات);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *ڳوليو_معلومات);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t ڳوليو_Handle,بنية _wfinddata32i64_t *ڳوليو_معلومات);
  صحيح __cdecl _wfindnext64i32(intptr_t ڳوليو_Handle,بنية _wfinddata64i32_t *ڳوليو_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t ڳوليو_Handle,بنية _wfinddata64_t *ڳوليو_معلومات);
#جيڪڏهن_پورو

  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);

#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_گهڻائي = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_گهڻائي = 0);
#جيڪڏهن_پورو

#جيڪڏهن_پورو

  صحيح __cdecl __lock_fhandle(صحيح _Filehandle);
  فراغ __cdecl _unlock_fhandle(صحيح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحيح _Flags);

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
  صحيح __cdecl access(ثابت حرف *_Filename,صحيح Access_گهڻائي);
  صحيح __cdecl chmod(ثابت حرف *_Filename,صحيح Access_گهڻائي);
  صحيح __cdecl chsize(صحيح _FileHandle,ڊگهو سائيز_4);
  صحيح __cdecl close(صحيح _FileHandle);
  صحيح __cdecl creat(ثابت حرف *_Filename,صحيح Permission_گهڻائي);
  صحيح __cdecl dup(صحيح _FileHandle);
  صحيح __cdecl dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  صحيح __cdecl eof(صحيح _FileHandle);
  ڊگهو __cdecl filelength(صحيح _FileHandle);
  صحيح __cdecl isatty(صحيح _FileHandle);
  صحيح __cdecl locking(صحيح _FileHandle,صحيح تالو_گهڻائي,ڊگهو انگ_جو_بائيٽون);
  ڊگهو __cdecl lseek(صحيح _FileHandle,ڊگهو وٿي_2,صحيح _Origin);
  حرف *__cdecl mktemp(حرف *_TemplateName);
  صحيح __cdecl open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  صحيح __cdecl اقرأ(صحيح _FileHandle,فراغ *_DstBuf,بنانشان صحيح Max_Char_ڳڻپ);
  صحيح __cdecl setmode(صحيح _FileHandle,صحيح گهڻائي_3);
  صحيح __cdecl sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
  ڊگهو __cdecl tell(صحيح _FileHandle);
  صحيح __cdecl umask(صحيح گهڻائي_3);
  صحيح __cdecl اكتب(صحيح _Filehandle,ثابت فراغ *_Buf,بنانشان صحيح Max_Char_ڳڻپ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

/* Misc stuff */
حرف *getlogin(فراغ);
#جيڪڏهن_وصف_ٿيل __USE_MINGW_ALARM
بنانشان صحيح alarm(بنانشان صحيح seconds);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ساكن مضمن صحيح __mingw_access (ثابت حرف *__fname, صحيح __mode) {
  أرجع  _access (__fname, __mode & ~X_OK);
}

#وصف_ڪريو access(__f,__m)  __mingw_access (__f, __m)
#جيڪڏهن_پورو


#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو


#هدايت pack(ڪڍو)

#ضمن <sec_api/io_s.h>

#جيڪڏهن_پورو /* End _IO_H_ */

