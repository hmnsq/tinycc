
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _IO_H_
#تعریف_کرو _IO_H_

#ضمن <_mingw.h>
#ضمن <string.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_بنا_تعریف _POSIX_

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

_CRTIMP حرف* __cdecl _getcwd (حرف*, صحيح);
#جے_بنا_تعریف _FSIZE_T_DEFINED
  تعريفنوع بنانشانی لما _fsize_t;
#تعریف_کرو _FSIZE_T_DEFINED
#جے_انت

#جے_بنا_تعریف _FINDDATA_T_DEFINED

  بنية _finddata32_t {
    بنانشانی attrib;
    __time32_t ویلا_create;
    __time32_t ویلا_access;
    __time32_t ویلا_write;
    _fsize_t ناپ;
    حرف name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  بنية _finddata32i64_t {
    بنانشانی attrib;
    __time32_t ویلا_create;
    __time32_t ویلا_access;
    __time32_t ویلا_write;
    __int64 ناپ;
    حرف name[260];
  };

  بنية _finddata64i32_t {
    بنانشانی attrib;
    __time64_t ویلا_create;
    __time64_t ویلا_access;
    __time64_t ویلا_write;
    _fsize_t ناپ;
    حرف name[260];
  };

  بنية __finddata64_t {
    بنانشانی attrib;
    __time64_t ویلا_create;
    __time64_t ویلا_access;
    __time64_t ویلا_write;
    __int64 ناپ;
    حرف name[260];
  };
/* #endif */

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#تعریف_کرو _finddata_t _finddata32_t
#تعریف_کرو _finddatai64_t _finddata32i64_t

#جے_تعریف_شدہ _WIN64
#تعریف_کرو _findfirst _findfirst32
#تعریف_کرو _findnext _findnext32
#وإلا
#تعریف_کرو _findfirst32 _findfirst
#تعریف_کرو _findnext32 _findnext
#جے_انت
#تعریف_کرو _findfirsti64 _findfirst32i64
#تعریف_کرو _findnexti64 _findnext32i64
#وإلا
#تعریف_کرو _finddata_t _finddata64i32_t
#تعریف_کرو _finddatai64_t __finddata64_t

#تعریف_کرو _findfirst _findfirst64i32
#تعریف_کرو _findnext _findnext64i32
#تعریف_کرو _findfirsti64 _findfirst64
#تعریف_کرو _findnexti64 _findnext64
#جے_انت

#تعریف_کرو _FINDDATA_T_DEFINED
#جے_انت

#جے_بنا_تعریف _WFINDDATA_T_DEFINED

  بنية _wfinddata32_t {
    بنانشانی attrib;
    __time32_t ویلا_create;
    __time32_t ویلا_access;
    __time32_t ویلا_write;
    _fsize_t ناپ;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  بنية _wfinddata32i64_t {
    بنانشانی attrib;
    __time32_t ویلا_create;
    __time32_t ویلا_access;
    __time32_t ویلا_write;
    __int64 ناپ;
    wchar_t name[260];
  };

  بنية _wfinddata64i32_t {
    بنانشانی attrib;
    __time64_t ویلا_create;
    __time64_t ویلا_access;
    __time64_t ویلا_write;
    _fsize_t ناپ;
    wchar_t name[260];
  };

  بنية _wfinddata64_t {
    بنانشانی attrib;
    __time64_t ویلا_create;
    __time64_t ویلا_access;
    __time64_t ویلا_write;
    __int64 ناپ;
    wchar_t name[260];
  };
/* #endif */

#جے_تعریف_شدہ USE_32_ثنائی_ہندسہ_ویلا_T
#تعریف_کرو _wfinddata_t _wfinddata32_t
#تعریف_کرو _wfinddatai64_t _wfinddata32i64_t

#تعریف_کرو _wfindfirst _wfindfirst32
#تعریف_کرو _wfindnext _wfindnext32
#تعریف_کرو _wfindfirsti64 _wfindfirst32i64
#تعریف_کرو _wfindnexti64 _wfindnext32i64
#وإلا
#تعریف_کرو _wfinddata_t _wfinddata64i32_t
#تعریف_کرو _wfinddatai64_t _wfinddata64_t

#تعریف_کرو _wfindfirst _wfindfirst64i32
#تعریف_کرو _wfindnext _wfindnext64i32
#تعریف_کرو _wfindfirsti64 _wfindfirst64
#تعریف_کرو _wfindnexti64 _wfindnext64
#جے_انت

#تعریف_کرو _WFINDDATA_T_DEFINED
#جے_انت

#تعریف_کرو A_عام 0x00
#تعریف_کرو _A_RDONLY 0x01
#تعریف_کرو _A_HIDDEN 0x02
#تعریف_کرو _A_SYSTEM 0x04
#تعریف_کرو _A_SUBDIR 0x10
#تعریف_کرو _A_ARCH 0x20

#جے_بنا_تعریف _SIZE_T_DEFINED
#تعریف_کرو _SIZE_T_DEFINED
#تعریف_رد ناپ_t
#جے_تعریف_شدہ _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع بنانشانی صحيح ناپ_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع بنانشانی __int64 ناپ_t;
#جے_انت
#وإلا
  تعريفنوع بنانشانی صحيح ناپ_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _SSIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#تعریف_رد ssize_t
#جے_تعریف_شدہ _WIN64
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح ssize_t __attribute__ ((منوال (DI)));
#وإلا
  تعريفنوع __int64 ssize_t;
#جے_انت
#وإلا
  تعريفنوع صحيح ssize_t;
#جے_انت
#جے_انت

#جے_بنا_تعریف _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#جے_بنا_تعریف _OFF_T_
#تعریف_کرو _OFF_T_
  تعريفنوع لما _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع لما off_t;
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
#إذا defined(__GNUC__) && defined(__STRICT_ANSI__)
  تعريفنوع صحيح _off64_t __attribute__ ((منوال (DI)));
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع صحيح off64_t __attribute__ ((منوال (DI)));
#جے_انت
#وإلا
  تعريفنوع لما لما _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع لما لما off64_t;
#جے_انت
#جے_انت
#جے_انت

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#تعریف_کرو	F_OK	0	/* Check for file existence */
#تعریف_کرو	X_OK	1	/* Check for execute permission. */
#تعریف_کرو	W_OK	2	/* Check for write permission */
#تعریف_کرو	R_OK	4	/* Check for read permission */

  _CRTIMP صحيح __cdecl _access(ثابت حرف *_Filename,صحيح Access_منوال);
  _CRTIMP صحيح __cdecl _chmod(ثابت حرف *_Filename,صحيح منوال_3);
  _CRTIMP صحيح __cdecl _chsize(صحيح _FileHandle,لما ناپ_4);
  _CRTIMP صحيح __cdecl _close(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _commit(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _creat(ثابت حرف *_Filename,صحيح Permission_منوال);
  _CRTIMP صحيح __cdecl _dup(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  _CRTIMP صحيح __cdecl _eof(صحيح _FileHandle);
  _CRTIMP لما __cdecl _filelength(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت حرف *_Filename,بنية _finddata32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _findnext32(intptr_t لبھو_Handle,بنية _finddata32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _findclose(intptr_t لبھو_Handle);
  _CRTIMP صحيح __cdecl _isatty(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _locking(صحيح _FileHandle,صحيح جندرا_منوال,لما عدد_دا_بائٹاں);
  _CRTIMP لما __cdecl _lseek(صحيح _FileHandle,لما وتھ_2,صحيح _Origin);
  _off64_t lseek64(صحيح fd,_off64_t وتھ, صحيح whence);
  _CRTIMP حرف *__cdecl _mktemp(حرف *_TemplateName);
  _CRTIMP صحيح __cdecl _pipe(صحيح *_PtHandles,بنانشانی صحيح Pipe_ناپ,صحيح متن_منوال);
  _CRTIMP صحيح __cdecl _read(صحيح _FileHandle,فراغ *_DstBuf,بنانشانی صحيح Max_Char_گنتی);

#جے_بنا_تعریف _CRT_DIRECTORY_DEFINED
#تعریف_کرو _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#جے_بنا_تعریف	NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#جے_انت
#جے_انت

  _CRTIMP صحيح __cdecl _setmode(صحيح _FileHandle,صحيح منوال_3);
  _CRTIMP لما __cdecl _tell(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _umask(صحيح منوال_3);
  _CRTIMP صحيح __cdecl _write(صحيح _FileHandle,ثابت فراغ *_Buf,بنانشانی صحيح Max_Char_گنتی);

#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحيح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت حرف *_Filename,بنية _finddata32i64_t *لبھو_انکڑے);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت حرف *_Filename,بنية __finddata64_t *لبھو_انکڑے);
#جے_تعریف_شدہ __cplusplus
#ضمن <string.h>
#جے_انت
  intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *لبھو_انکڑے);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,بنية _finddata64i32_t *لبھو_انکڑے)
  {
    بنية __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    لبھو_انکڑے->attrib=fd.attrib;
    لبھو_انکڑے->ویلا_create=fd.ویلا_create;
    لبھو_انکڑے->ویلا_access=fd.ویلا_access;
    لبھو_انکڑے->ویلا_write=fd.ویلا_write;
    لبھو_انکڑے->ناپ=(_fsize_t) fd.ناپ;
    strncpy(لبھو_انکڑے->name,fd.name,260);
    أرجع ret;
  }
  _CRTIMP صحيح __cdecl _findnext32i64(intptr_t لبھو_Handle,بنية _finddata32i64_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _findnext64(intptr_t لبھو_Handle,بنية __finddata64_t *لبھو_انکڑے);
  صحيح __cdecl _findnext64i32(intptr_t لبھو_Handle,بنية _finddata64i32_t *لبھو_انکڑے);
  __CRT_INLINE صحيح __cdecl _findnext64i32(intptr_t لبھو_Handle,بنية _finddata64i32_t *لبھو_انکڑے)
  {
    بنية __finddata64_t fd;
    صحيح ret = _findnext64(لبھو_Handle,&fd);
    لبھو_انکڑے->attrib=fd.attrib;
    لبھو_انکڑے->ویلا_create=fd.ویلا_create;
    لبھو_انکڑے->ویلا_access=fd.ویلا_access;
    لبھو_انکڑے->ویلا_write=fd.ویلا_write;
    لبھو_انکڑے->ناپ=(_fsize_t) fd.ناپ;
    strncpy(لبھو_انکڑے->name,fd.name,260);
    أرجع ret;
  }
  __int64 __cdecl _lseeki64(صحيح _FileHandle,__int64 وتھ_2,صحيح _Origin);
  __int64 __cdecl _telli64(صحيح _FileHandle);
#جے_انت
#جے_بنا_تعریف NO_OLDNAMES

#جے_بنا_تعریف _UWIN
  صحيح __cdecl chdir (ثابت حرف *);
  حرف *__cdecl getcwd (حرف *, صحيح);
  صحيح __cdecl mkdir (ثابت حرف *);
  حرف *__cdecl mktemp(حرف *);
  صحيح __cdecl rmdir (ثابت حرف*);
  صحيح __cdecl chmod (ثابت حرف *, صحيح);
#جے_انت /* _UWIN */

#جے_انت /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحيح *_FileHandle,ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_منوال);

#جے_بنا_تعریف __cplusplus
  _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _open(ثابت حرف *_Filename,صحيح _Openflag,صحيح Permission_منوال = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _sopen(ثابت حرف *_Filename,صحيح _Openflag,صحيح _ShareFlag,صحيح Permission_منوال = 0);
#جے_انت

#جے_بنا_تعریف _WIO_DEFINED
#تعریف_کرو _WIO_DEFINED
  _CRTIMP صحيح __cdecl _waccess(ثابت wchar_t *_Filename,صحيح Access_منوال);
  _CRTIMP صحيح __cdecl _wchmod(ثابت wchar_t *_Filename,صحيح منوال_3);
  _CRTIMP صحيح __cdecl _wcreat(ثابت wchar_t *_Filename,صحيح Permission_منوال);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,بنية _wfinddata32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wfindnext32(intptr_t لبھو_Handle,بنية _wfinddata32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحيح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#إذا INTEGRAL_MAX_بٹ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,بنية _wfinddata32i64_t *لبھو_انکڑے);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,بنية _wfinddata64i32_t *لبھو_انکڑے);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,بنية _wfinddata64_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wfindnext32i64(intptr_t لبھو_Handle,بنية _wfinddata32i64_t *لبھو_انکڑے);
  صحيح __cdecl _wfindnext64i32(intptr_t لبھو_Handle,بنية _wfinddata64i32_t *لبھو_انکڑے);
  _CRTIMP صحيح __cdecl _wfindnext64(intptr_t لبھو_Handle,بنية _wfinddata64_t *لبھو_انکڑے);
#جے_انت

  _CRTIMP errno_t __cdecl _wsopen_s(صحيح *_FileHandle,ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح _PermissionFlag);

#إذا !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,...);
  _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
#وإلا
  خارجي "C++" _CRTIMP صحيح __cdecl _wopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح Permission_منوال = 0);
  خارجي "C++" _CRTIMP صحيح __cdecl _wsopen(ثابت wchar_t *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,صحيح Permission_منوال = 0);
#جے_انت

#جے_انت

  صحيح __cdecl __lock_fhandle(صحيح _Filehandle);
  فراغ __cdecl _unlock_fhandle(صحيح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحيح _FileHandle);
  _CRTIMP صحيح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحيح _Flags);

#جے_بنا_تعریف	NO_OLDNAMES
  صحيح __cdecl access(ثابت حرف *_Filename,صحيح Access_منوال);
  صحيح __cdecl chmod(ثابت حرف *_Filename,صحيح Access_منوال);
  صحيح __cdecl chsize(صحيح _FileHandle,لما ناپ_4);
  صحيح __cdecl close(صحيح _FileHandle);
  صحيح __cdecl creat(ثابت حرف *_Filename,صحيح Permission_منوال);
  صحيح __cdecl dup(صحيح _FileHandle);
  صحيح __cdecl dup2(صحيح _FileHandleSrc,صحيح _FileHandleDst);
  صحيح __cdecl eof(صحيح _FileHandle);
  لما __cdecl filelength(صحيح _FileHandle);
  صحيح __cdecl isatty(صحيح _FileHandle);
  صحيح __cdecl locking(صحيح _FileHandle,صحيح جندرا_منوال,لما عدد_دا_بائٹاں);
  لما __cdecl lseek(صحيح _FileHandle,لما وتھ_2,صحيح _Origin);
  حرف *__cdecl mktemp(حرف *_TemplateName);
  صحيح __cdecl open(ثابت حرف *_Filename,صحيح _OpenFlag,...);
  صحيح __cdecl اقرأ(صحيح _FileHandle,فراغ *_DstBuf,بنانشانی صحيح Max_Char_گنتی);
  صحيح __cdecl setmode(صحيح _FileHandle,صحيح منوال_3);
  صحيح __cdecl sopen(ثابت حرف *_Filename,صحيح _OpenFlag,صحيح _ShareFlag,...);
  لما __cdecl tell(صحيح _FileHandle);
  صحيح __cdecl umask(صحيح منوال_3);
  صحيح __cdecl اكتب(صحيح _Filehandle,ثابت فراغ *_Buf,بنانشانی صحيح Max_Char_گنتی);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

/* Misc stuff */
حرف *getlogin(فراغ);
#جے_تعریف_شدہ __USE_MINGW_ALARM
بنانشانی صحيح alarm(بنانشانی صحيح seconds);
#جے_انت

#جے_تعریف_شدہ __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ساكن مضمن صحيح __mingw_access (ثابت حرف *__fname, صحيح __mode) {
  أرجع  _access (__fname, __mode & ~X_OK);
}

#تعریف_کرو access(__f,__m)  __mingw_access (__f, __m)
#جے_انت


#جے_تعریف_شدہ __cplusplus
}
#جے_انت


#ہدایت pack(نکالو)

#ضمن <sec_api/io_s.h>

#جے_انت /* End _IO_H_ */

