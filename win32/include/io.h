
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _IO_H_
#تعریف_کن _IO_H_

#ضمن <_mingw.h>
#ضمن <string.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_نشده _POSIX_

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

_CRTIMP حرف* __cdecl _getcwd (حرف*, صحيح);
#اگر_تعریف_نشده _FSIZE_T_DEFINED
  تعريفنوع بیعلامت دراز _fsize_t;
#تعریف_کن _FSIZE_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _FINDDATA_T_DEFINED

  بنية _finddata32_t {
    بیعلامت attrib;
    __time32_t زمان_create;
    __time32_t زمان_access;
    __time32_t زمان_write;
    _fsize_t اندازه;
    حرف name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  بنية _finddata32i64_t {
    بیعلامت attrib;
    __time32_t زمان_create;
    __time32_t زمان_access;
    __time32_t زمان_write;
    __int64 اندازه;
    حرف name[260];
  };

  بنية _finddata64i32_t {
    بیعلامت attrib;
    __time64_t زمان_create;
    __time64_t زمان_access;
    __time64_t زمان_write;
    _fsize_t اندازه;
    حرف name[260];
  };

  بنية __finddata64_t {
    بیعلامت attrib;
    __time64_t زمان_create;
    __time64_t زمان_access;
    __time64_t زمان_write;
    __int64 اندازه;
    حرف name[260];
  };
/* #endif */

#اگر_تعریف_شده USE_32_بیت_زمان_T
#تعریف_کن _finddata_t _finddata32_t
#تعریف_کن _finddatai64_t _finddata32i64_t

#اگر_تعریف_شده _WIN64
#تعریف_کن _findfirst _findfirst32
#تعریف_کن _findnext _findnext32
#وإلا
#تعریف_کن _findfirst32 _findfirst
#تعریف_کن _findnext32 _findnext
#پایان_اگر
#تعریف_کن _findfirsti64 _findfirst32i64
#تعریف_کن _findnexti64 _findnext32i64
#وإلا
#تعریف_کن _finddata_t _finddata64i32_t
#تعریف_کن _finddatai64_t __finddata64_t

#تعریف_کن _findfirst _findfirst64i32
#تعریف_کن _findnext _findnext64i32
#تعریف_کن _findfirsti64 _findfirst64
#تعریف_کن _findnexti64 _findnext64
#پایان_اگر

#تعریف_کن _FINDDATA_T_DEFINED
#پایان_اگر

#اگر_تعریف_نشده _WFINDDATA_T_DEFINED

  بنية _wfinddata32_t {
    بیعلامت attrib;
    __time32_t زمان_create;
    __time32_t زمان_access;
    __time32_t زمان_write;
    _fsize_t اندازه;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بیعلامت attrib;
    __time32_t زمان_create;
    __time32_t زمان_access;
    __time32_t زمان_write;
    __int64 اندازه;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بیعلامت attrib;
    __time64_t زمان_create;
    __time64_t زمان_access;
    __time64_t زمان_write;
    _fsize_t اندازه;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بیعلامت attrib;
    __time64_t زمان_create;
    __time64_t زمان_access;
    __time64_t زمان_write;
    __int64 اندازه;
    wchar_t name[260];
  };
/* #endif */

#اگر_تعریف_شده USE_32_بیت_زمان_T
#تعریف_کن _wfinddata_t _wfinddata32_t
#تعریف_کن _wfinddatai64_t _wfinddata32i64_t

#تعریف_کن _wfindfirst _wfindfirst32
#تعریف_کن _wfindnext _wfindnext32
#تعریف_کن _wfindfirsti64 _wfindfirst32i64
#تعریف_کن _wfindnexti64 _wfindnext32i64
#وإلا
#تعریف_کن _wfinddata_t _wfinddata64i32_t
#تعریف_کن _wfinddatai64_t _wfinddata64_t

#تعریف_کن _wfindfirst _wfindfirst64i32
#تعریف_کن _wfindnext _wfindnext64i32
#تعریف_کن _wfindfirsti64 _wfindfirst64
#تعریف_کن _wfindnexti64 _wfindnext64
#پایان_اگر

#تعریف_کن _WFINDDATA_T_DEFINED
#پایان_اگر

#تعریف_کن A_نرمال 0x00
#تعریف_کن _A_RDONLY 0x01
#تعریف_کن _A_HIDDEN 0x02
#تعریف_کن _A_SYSTEM 0x04
#تعریف_کن _A_SUBDIR 0x10
#تعریف_کن _A_ARCH 0x20

#اگر_تعریف_نشده _SIZE_T_DEFINED
#تعریف_کن _SIZE_T_DEFINED
#لغو_تعریف اندازه_t
#اگر_تعریف_شده _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بیعلامت صحيح اندازه_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع بیعلامت __int64 اندازه_t;
#پایان_اگر
#وإلا
  تعريفنوع بیعلامت صحيح اندازه_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _SSIZE_T_DEFINED
#تعریف_کن _SSIZE_T_DEFINED
#لغو_تعریف ssize_t
#اگر_تعریف_شده _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((نما (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#پایان_اگر
#وإلا
  تعريفنوع صحيح ssize_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF_T_DEFINED
#تعریف_کن _OFF_T_DEFINED
#اگر_تعریف_نشده _OFF_T_
#تعریف_کن _OFF_T_
  تعريفنوع دراز _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز off_t;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF64_T_DEFINED
#تعریف_کن _OFF64_T_DEFINED
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _off64_t __attribute__ ((نما (DI)));
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع صحيح off64_t __attribute__ ((نما (DI)));
#پایان_اگر
#وإلا
  تعريفنوع دراز دراز _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز دراز off64_t;
#پایان_اگر
#پایان_اگر
#پایان_اگر

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#تعریف_کن	F_OK	0	/* Check for file existence */
#تعریف_کن	X_OK	1	/* Check for execute permission. */
#تعریف_کن	W_OK	2	/* Check for write permission */
#تعریف_کن	R_OK	4	/* Check for read permission */

  _CRTIMP صحيح __cdecl _access(ثابت حرف *_Filename,صحيح Access_نما);
  _CRTIMP صحيح __cdecl _chmod(ثابت حرف *_Filename,صحيح نما_3);
  _CRTIMP صحيح __cdecl _chsize(صحيح _FileHandle,دراز اندازه_4);
  _CRTIMP صحيح __cdecl _close(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _commit(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _creat(ثابت حرف *_Filename,صحيح Permission_نما);
  _CRTIMP صحيح __cdecl _dup(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  _CRTIMP صحيح __cdecl _eof(صحيح _FileHandle);
  _CRTIMP دراز __cdecl _filelength(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت حرف *_Filename,بنية _finddata32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _findnext32(intptr_t پیدا_کن_Handle,بنية _finddata32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _findclose(intptr_t پیدا_کن_Handle);
  _CRTIMP صحيح __cdecl _isatty(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _locking(صحيح _FileHandle,صحيح قفل_نما,دراز رقم_از_بایتها);
  _CRTIMP دراز __cdecl _lseek(صحيح _FileHandle,دراز جابه_جایی_2,صحيح _Origin);
  _off64_t lseek64(صحيح fd,_off64_t جابه_جایی, صحيح whence);
  _CRTIMP حرف *__cdecl _mktemp(حرف *_TemplateName);
  _CRTIMP صحيح __cdecl _pipe(صحيح *_PtHandles,بیعلامت صحيح Pipe_اندازه,صحيح متن_نما);
  _CRTIMP صحيح __cdecl _read(صحيح _FileHandle,فراغ *_DstBuf,بیعلامت صحيح Max_Char_شمار);

#اگر_تعریف_نشده _CRT_DIRECTORY_DEFINED
#تعریف_کن _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#اگر_تعریف_نشده	NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#پایان_اگر
#پایان_اگر

  _CRTIMP صحيح __cdecl _setmode(صحيح _FileHandle,صحيح نما_3);
  _CRTIMP دراز __cdecl _tell(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _umask(صحيح نما_3);
  _CRTIMP صحيح __cdecl _write(صحيح _FileHandle,ثابت فراغ *_Buf,بیعلامت صحيح Max_Char_شمار);

#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت حرف *_Filename,بنية _finddata32i64_t *پیدا_کن_داده);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت حرف *_Filename,بنية __finddata64_t *پیدا_کن_داده);
#اگر_تعریف_شده __cplusplus
#ضمن <string.h>
#پایان_اگر
  intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *پیدا_کن_داده);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *پیدا_کن_داده)
  {
    بنية __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    پیدا_کن_داده->attrib=fd.attrib;
    پیدا_کن_داده->زمان_create=fd.زمان_create;
    پیدا_کن_داده->زمان_access=fd.زمان_access;
    پیدا_کن_داده->زمان_write=fd.زمان_write;
    پیدا_کن_داده->اندازه=(_fsize_t) fd.اندازه;
    strncpy(پیدا_کن_داده->name,fd.name,260);
    أرجع ret;
  }
  _CRTIMP صحيح __cdecl _findnext32i64(intptr_t پیدا_کن_Handle,بنية _finddata32i64_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _findnext64(intptr_t پیدا_کن_Handle,بنية __finddata64_t *پیدا_کن_داده);
  صحيح __cdecl _findnext64i32(intptr_t پیدا_کن_Handle,بنية _finddata64i32_t *پیدا_کن_داده);
  __CRT_INLINE صحيح __cdecl _findnext64i32(intptr_t پیدا_کن_Handle,بنية _finddata64i32_t *پیدا_کن_داده)
  {
    بنية __finddata64_t fd;
    صحيح ret = _findnext64(پیدا_کن_Handle,&fd);
    پیدا_کن_داده->attrib=fd.attrib;
    پیدا_کن_داده->زمان_create=fd.زمان_create;
    پیدا_کن_داده->زمان_access=fd.زمان_access;
    پیدا_کن_داده->زمان_write=fd.زمان_write;
    پیدا_کن_داده->اندازه=(_fsize_t) fd.اندازه;
    strncpy(پیدا_کن_داده->name,fd.name,260);
    أرجع ret;
  }
  __int64 __cdecl _lseeki64(صحيح _FileHandle,__int64 جابه_جایی_2,صحيح _Origin);
  __int64 __cdecl _telli64(صحيح _FileHandle);
#پایان_اگر
#اگر_تعریف_نشده NO_OLDNAMES

#اگر_تعریف_نشده _UWIN
  صحيح __cdecl chdir (ثابت حرف *);
  حرف *__cdecl getcwd (حرف *, صحيح);
  صحيح __cdecl mkdir (ثابت حرف *);
  حرف *__cdecl mktemp(حرف *);
  صحيح __cdecl rmdir (ثابت حرف*);
  صحيح __cdecl chmod (ثابت حرف *, صحيح);
#پایان_اگر /* _UWIN */

#پایان_اگر /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحيح *_FileHandle,ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_نما);

#اگر_تعریف_نشده __cplusplus
  _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _Openflag,صحيح Permission_نما = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _Openflag,صحيح _ShareFlag,صحيح Permission_نما = 0);
#پایان_اگر

#اگر_تعریف_نشده _WIO_DEFINED
#تعریف_کن _WIO_DEFINED
  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_نما);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح نما_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_نما);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t پیدا_کن_Handle,بنية _wfinddata32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#إذا INTEGRAL_MAX_بیتها >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *پیدا_کن_داده);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *پیدا_کن_داده);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t پیدا_کن_Handle,بنية _wfinddata32i64_t *پیدا_کن_داده);
  صحيح __cdecl _wfindnext64i32(intptr_t پیدا_کن_Handle,بنية _wfinddata64i32_t *پیدا_کن_داده);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t پیدا_کن_Handle,بنية _wfinddata64_t *پیدا_کن_داده);
#پایان_اگر

  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);

#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_نما = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_نما = 0);
#پایان_اگر

#پایان_اگر

  صحيح __cdecl __lock_fhandle(صحيح _Filehandle);
  فراغ __cdecl _unlock_fhandle(صحيح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحيح _Flags);

#اگر_تعریف_نشده	NO_OLDNAMES
  صحيح __cdecl access(ثابت حرف *_Filename,صحيح Access_نما);
  صحيح __cdecl chmod(ثابت حرف *_Filename,صحيح Access_نما);
  صحيح __cdecl chsize(صحيح _FileHandle,دراز اندازه_4);
  صحيح __cdecl close(صحيح _FileHandle);
  صحيح __cdecl creat(ثابت حرف *_Filename,صحيح Permission_نما);
  صحيح __cdecl dup(صحيح _FileHandle);
  صحيح __cdecl dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  صحيح __cdecl eof(صحيح _FileHandle);
  دراز __cdecl filelength(صحيح _FileHandle);
  صحيح __cdecl isatty(صحيح _FileHandle);
  صحيح __cdecl locking(صحيح _FileHandle,صحيح قفل_نما,دراز رقم_از_بایتها);
  دراز __cdecl lseek(صحيح _FileHandle,دراز جابه_جایی_2,صحيح _Origin);
  حرف *__cdecl mktemp(حرف *_TemplateName);
  صحيح __cdecl open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  صحيح __cdecl اقرأ(صحيح _FileHandle,فراغ *_DstBuf,بیعلامت صحيح Max_Char_شمار);
  صحيح __cdecl setmode(صحيح _FileHandle,صحيح نما_3);
  صحيح __cdecl sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
  دراز __cdecl tell(صحيح _FileHandle);
  صحيح __cdecl umask(صحيح نما_3);
  صحيح __cdecl اكتب(صحيح _Filehandle,ثابت فراغ *_Buf,بیعلامت صحيح Max_Char_شمار);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

/* Misc stuff */
حرف *getlogin(فراغ);
#اگر_تعریف_شده __USE_MINGW_ALARM
بیعلامت صحيح alarm(بیعلامت صحيح seconds);
#پایان_اگر

#اگر_تعریف_شده __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ساكن مضمن صحيح __mingw_access (ثابت حرف *__fname, صحيح __mode) {
  أرجع  _access (__fname, __mode & ~X_OK);
}

#تعریف_کن access(__f,__m)  __mingw_access (__f, __m)
#پایان_اگر


#اگر_تعریف_شده __cplusplus
}
#پایان_اگر


#رهنمود pack(برداشت)

#ضمن <sec_api/io_s.h>

#پایان_اگر /* End _IO_H_ */

