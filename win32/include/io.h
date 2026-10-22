
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _IO_H_
#تعریف_کړه _IO_H_

#ضمن <_mingw.h>
#ضمن <string.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_نه_تعریف_شوی _POSIX_

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

_CRTIMP حرف* __cdecl _getcwd (حرف*, صحيح);
#که_نه_تعریف_شوی _FSIZE_T_DEFINED
  تعريفنوع بینښه اوږد _fsize_t;
#تعریف_کړه _FSIZE_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _FINDDATA_T_DEFINED

  بنية _finddata32_t {
    بینښه attrib;
    __time32_t وخت_create;
    __time32_t وخت_access;
    __time32_t وخت_write;
    _fsize_t اندازه;
    حرف name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  بنية _finddata32i64_t {
    بینښه attrib;
    __time32_t وخت_create;
    __time32_t وخت_access;
    __time32_t وخت_write;
    __int64 اندازه;
    حرف name[260];
  };

  بنية _finddata64i32_t {
    بینښه attrib;
    __time64_t وخت_create;
    __time64_t وخت_access;
    __time64_t وخت_write;
    _fsize_t اندازه;
    حرف name[260];
  };

  بنية __finddata64_t {
    بینښه attrib;
    __time64_t وخت_create;
    __time64_t وخت_access;
    __time64_t وخت_write;
    __int64 اندازه;
    حرف name[260];
  };
/* #endif */

#که_تعریف_شوی USE_32_بټ_وخت_T
#تعریف_کړه _finddata_t _finddata32_t
#تعریف_کړه _finddatai64_t _finddata32i64_t

#که_تعریف_شوی _WIN64
#تعریف_کړه _findfirst _findfirst32
#تعریف_کړه _findnext _findnext32
#وإلا
#تعریف_کړه _findfirst32 _findfirst
#تعریف_کړه _findnext32 _findnext
#د_که_پای
#تعریف_کړه _findfirsti64 _findfirst32i64
#تعریف_کړه _findnexti64 _findnext32i64
#وإلا
#تعریف_کړه _finddata_t _finddata64i32_t
#تعریف_کړه _finddatai64_t __finddata64_t

#تعریف_کړه _findfirst _findfirst64i32
#تعریف_کړه _findnext _findnext64i32
#تعریف_کړه _findfirsti64 _findfirst64
#تعریف_کړه _findnexti64 _findnext64
#د_که_پای

#تعریف_کړه _FINDDATA_T_DEFINED
#د_که_پای

#که_نه_تعریف_شوی _WFINDDATA_T_DEFINED

  بنية _wfinddata32_t {
    بینښه attrib;
    __time32_t وخت_create;
    __time32_t وخت_access;
    __time32_t وخت_write;
    _fsize_t اندازه;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بینښه attrib;
    __time32_t وخت_create;
    __time32_t وخت_access;
    __time32_t وخت_write;
    __int64 اندازه;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بینښه attrib;
    __time64_t وخت_create;
    __time64_t وخت_access;
    __time64_t وخت_write;
    _fsize_t اندازه;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بینښه attrib;
    __time64_t وخت_create;
    __time64_t وخت_access;
    __time64_t وخت_write;
    __int64 اندازه;
    wchar_t name[260];
  };
/* #endif */

#که_تعریف_شوی USE_32_بټ_وخت_T
#تعریف_کړه _wfinddata_t _wfinddata32_t
#تعریف_کړه _wfinddatai64_t _wfinddata32i64_t

#تعریف_کړه _wfindfirst _wfindfirst32
#تعریف_کړه _wfindnext _wfindnext32
#تعریف_کړه _wfindfirsti64 _wfindfirst32i64
#تعریف_کړه _wfindnexti64 _wfindnext32i64
#وإلا
#تعریف_کړه _wfinddata_t _wfinddata64i32_t
#تعریف_کړه _wfinddatai64_t _wfinddata64_t

#تعریف_کړه _wfindfirst _wfindfirst64i32
#تعریف_کړه _wfindnext _wfindnext64i32
#تعریف_کړه _wfindfirsti64 _wfindfirst64
#تعریف_کړه _wfindnexti64 _wfindnext64
#د_که_پای

#تعریف_کړه _WFINDDATA_T_DEFINED
#د_که_پای

#تعریف_کړه A_نورمال 0x00
#تعریف_کړه _A_RDONLY 0x01
#تعریف_کړه _A_HIDDEN 0x02
#تعریف_کړه _A_SYSTEM 0x04
#تعریف_کړه _A_SUBDIR 0x10
#تعریف_کړه _A_ARCH 0x20

#که_نه_تعریف_شوی _SIZE_T_DEFINED
#تعریف_کړه _SIZE_T_DEFINED
#تعریف_لغوه اندازه_t
#که_تعریف_شوی _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بینښه صحيح اندازه_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع بینښه __int64 اندازه_t;
#د_که_پای
#وإلا
  تعريفنوع بینښه صحيح اندازه_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _SSIZE_T_DEFINED
#تعریف_کړه _SSIZE_T_DEFINED
#تعریف_لغوه ssize_t
#که_تعریف_شوی _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((ډېرپېښ (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#د_که_پای
#وإلا
  تعريفنوع صحيح ssize_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _OFF_T_DEFINED
#تعریف_کړه _OFF_T_DEFINED
#که_نه_تعریف_شوی _OFF_T_
#تعریف_کړه _OFF_T_
  تعريفنوع اوږد _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع اوږد off_t;
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _OFF64_T_DEFINED
#تعریف_کړه _OFF64_T_DEFINED
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _off64_t __attribute__ ((ډېرپېښ (DI)));
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع صحيح off64_t __attribute__ ((ډېرپېښ (DI)));
#د_که_پای
#وإلا
  تعريفنوع اوږد اوږد _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع اوږد اوږد off64_t;
#د_که_پای
#د_که_پای
#د_که_پای

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#تعریف_کړه	F_OK	0	/* Check for file existence */
#تعریف_کړه	X_OK	1	/* Check for execute permission. */
#تعریف_کړه	W_OK	2	/* Check for write permission */
#تعریف_کړه	R_OK	4	/* Check for read permission */

  _CRTIMP صحيح __cdecl _access(ثابت حرف *_Filename,صحيح Access_ډېرپېښ);
  _CRTIMP صحيح __cdecl _chmod(ثابت حرف *_Filename,صحيح ډېرپېښ_3);
  _CRTIMP صحيح __cdecl _chsize(صحيح _FileHandle,اوږد اندازه_4);
  _CRTIMP صحيح __cdecl _close(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _commit(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _creat(ثابت حرف *_Filename,صحيح Permission_ډېرپېښ);
  _CRTIMP صحيح __cdecl _dup(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  _CRTIMP صحيح __cdecl _eof(صحيح _FileHandle);
  _CRTIMP اوږد __cdecl _filelength(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت حرف *_Filename,بنية _finddata32_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _findnext32(intptr_t پیدا_کړه_Handle,بنية _finddata32_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _findclose(intptr_t پیدا_کړه_Handle);
  _CRTIMP صحيح __cdecl _isatty(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _locking(صحيح _FileHandle,صحيح قلف_ډېرپېښ,اوږد عدد_د_بایټونه);
  _CRTIMP اوږد __cdecl _lseek(صحيح _FileHandle,اوږد دننه_واټن_2,صحيح _Origin);
  _off64_t lseek64(صحيح fd,_off64_t دننه_واټن, صحيح whence);
  _CRTIMP حرف *__cdecl _mktemp(حرف *_TemplateName);
  _CRTIMP صحيح __cdecl _pipe(صحيح *_PtHandles,بینښه صحيح Pipe_اندازه,صحيح متن_ډېرپېښ);
  _CRTIMP صحيح __cdecl _read(صحيح _FileHandle,فراغ *_DstBuf,بینښه صحيح Max_Char_شمېر);

#که_نه_تعریف_شوی _CRT_DIRECTORY_DEFINED
#تعریف_کړه _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#که_نه_تعریف_شوی	NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#د_که_پای
#د_که_پای

  _CRTIMP صحيح __cdecl _setmode(صحيح _FileHandle,صحيح ډېرپېښ_3);
  _CRTIMP اوږد __cdecl _tell(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _umask(صحيح ډېرپېښ_3);
  _CRTIMP صحيح __cdecl _write(صحيح _FileHandle,ثابت فراغ *_Buf,بینښه صحيح Max_Char_شمېر);

#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت حرف *_Filename,بنية _finddata32i64_t *پیدا_کړه_معلومات);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت حرف *_Filename,بنية __finddata64_t *پیدا_کړه_معلومات);
#که_تعریف_شوی __cplusplus
#ضمن <string.h>
#د_که_پای
  intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *پیدا_کړه_معلومات);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *پیدا_کړه_معلومات)
  {
    بنية __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    پیدا_کړه_معلومات->attrib=fd.attrib;
    پیدا_کړه_معلومات->وخت_create=fd.وخت_create;
    پیدا_کړه_معلومات->وخت_access=fd.وخت_access;
    پیدا_کړه_معلومات->وخت_write=fd.وخت_write;
    پیدا_کړه_معلومات->اندازه=(_fsize_t) fd.اندازه;
    strncpy(پیدا_کړه_معلومات->name,fd.name,260);
    أرجع ret;
  }
  _CRTIMP صحيح __cdecl _findnext32i64(intptr_t پیدا_کړه_Handle,بنية _finddata32i64_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _findnext64(intptr_t پیدا_کړه_Handle,بنية __finddata64_t *پیدا_کړه_معلومات);
  صحيح __cdecl _findnext64i32(intptr_t پیدا_کړه_Handle,بنية _finddata64i32_t *پیدا_کړه_معلومات);
  __CRT_INLINE صحيح __cdecl _findnext64i32(intptr_t پیدا_کړه_Handle,بنية _finddata64i32_t *پیدا_کړه_معلومات)
  {
    بنية __finddata64_t fd;
    صحيح ret = _findnext64(پیدا_کړه_Handle,&fd);
    پیدا_کړه_معلومات->attrib=fd.attrib;
    پیدا_کړه_معلومات->وخت_create=fd.وخت_create;
    پیدا_کړه_معلومات->وخت_access=fd.وخت_access;
    پیدا_کړه_معلومات->وخت_write=fd.وخت_write;
    پیدا_کړه_معلومات->اندازه=(_fsize_t) fd.اندازه;
    strncpy(پیدا_کړه_معلومات->name,fd.name,260);
    أرجع ret;
  }
  __int64 __cdecl _lseeki64(صحيح _FileHandle,__int64 دننه_واټن_2,صحيح _Origin);
  __int64 __cdecl _telli64(صحيح _FileHandle);
#د_که_پای
#که_نه_تعریف_شوی NO_OLDNAMES

#که_نه_تعریف_شوی _UWIN
  صحيح __cdecl chdir (ثابت حرف *);
  حرف *__cdecl getcwd (حرف *, صحيح);
  صحيح __cdecl mkdir (ثابت حرف *);
  حرف *__cdecl mktemp(حرف *);
  صحيح __cdecl rmdir (ثابت حرف*);
  صحيح __cdecl chmod (ثابت حرف *, صحيح);
#د_که_پای /* _UWIN */

#د_که_پای /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحيح *_FileHandle,ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_ډېرپېښ);

#که_نه_تعریف_شوی __cplusplus
  _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _Openflag,صحيح Permission_ډېرپېښ = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _Openflag,صحيح _ShareFlag,صحيح Permission_ډېرپېښ = 0);
#د_که_پای

#که_نه_تعریف_شوی _WIO_DEFINED
#تعریف_کړه _WIO_DEFINED
  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_ډېرپېښ);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح ډېرپېښ_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_ډېرپېښ);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t پیدا_کړه_Handle,بنية _wfinddata32_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#إذا INTEGRAL_MAX_بټونه >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *پیدا_کړه_معلومات);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *پیدا_کړه_معلومات);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t پیدا_کړه_Handle,بنية _wfinddata32i64_t *پیدا_کړه_معلومات);
  صحيح __cdecl _wfindnext64i32(intptr_t پیدا_کړه_Handle,بنية _wfinddata64i32_t *پیدا_کړه_معلومات);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t پیدا_کړه_Handle,بنية _wfinddata64_t *پیدا_کړه_معلومات);
#د_که_پای

  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);

#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_ډېرپېښ = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_ډېرپېښ = 0);
#د_که_پای

#د_که_پای

  صحيح __cdecl __lock_fhandle(صحيح _Filehandle);
  فراغ __cdecl _unlock_fhandle(صحيح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحيح _Flags);

#که_نه_تعریف_شوی	NO_OLDNAMES
  صحيح __cdecl access(ثابت حرف *_Filename,صحيح Access_ډېرپېښ);
  صحيح __cdecl chmod(ثابت حرف *_Filename,صحيح Access_ډېرپېښ);
  صحيح __cdecl chsize(صحيح _FileHandle,اوږد اندازه_4);
  صحيح __cdecl close(صحيح _FileHandle);
  صحيح __cdecl creat(ثابت حرف *_Filename,صحيح Permission_ډېرپېښ);
  صحيح __cdecl dup(صحيح _FileHandle);
  صحيح __cdecl dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  صحيح __cdecl eof(صحيح _FileHandle);
  اوږد __cdecl filelength(صحيح _FileHandle);
  صحيح __cdecl isatty(صحيح _FileHandle);
  صحيح __cdecl locking(صحيح _FileHandle,صحيح قلف_ډېرپېښ,اوږد عدد_د_بایټونه);
  اوږد __cdecl lseek(صحيح _FileHandle,اوږد دننه_واټن_2,صحيح _Origin);
  حرف *__cdecl mktemp(حرف *_TemplateName);
  صحيح __cdecl open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  صحيح __cdecl اقرأ(صحيح _FileHandle,فراغ *_DstBuf,بینښه صحيح Max_Char_شمېر);
  صحيح __cdecl setmode(صحيح _FileHandle,صحيح ډېرپېښ_3);
  صحيح __cdecl sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
  اوږد __cdecl tell(صحيح _FileHandle);
  صحيح __cdecl umask(صحيح ډېرپېښ_3);
  صحيح __cdecl اكتب(صحيح _Filehandle,ثابت فراغ *_Buf,بینښه صحيح Max_Char_شمېر);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

/* Misc stuff */
حرف *getlogin(فراغ);
#که_تعریف_شوی __USE_MINGW_ALARM
بینښه صحيح alarm(بینښه صحيح seconds);
#د_که_پای

#که_تعریف_شوی __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ساكن مضمن صحيح __mingw_access (ثابت حرف *__fname, صحيح __mode) {
  أرجع  _access (__fname, __mode & ~X_OK);
}

#تعریف_کړه access(__f,__m)  __mingw_access (__f, __m)
#د_که_پای


#که_تعریف_شوی __cplusplus
}
#د_که_پای


#لارښوونه pack(راوباسه)

#ضمن <sec_api/io_s.h>

#د_که_پای /* End _IO_H_ */

