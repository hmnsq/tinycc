
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _IO_H_
#تعریف_کرو _IO_H_

#شامل <_mingw.h>
#شامل <string.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_غیر_تعریف_شدہ _POSIX_

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

_CRTIMP حرف* __cdecl _getcwd (حرف*, صحیح);
#اگر_غیر_تعریف_شدہ _FSIZE_T_DEFINED
  قسمتعریف غیرعلامتی طویل _fsize_t;
#تعریف_کرو _FSIZE_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _FINDDATA_T_DEFINED

  ساخت _finddata32_t {
    غیرعلامتی attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    _fsize_t سائز;
    حرف name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ساخت _finddata32i64_t {
    غیرعلامتی attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    __int64 سائز;
    حرف name[260];
  };

  ساخت _finddata64i32_t {
    غیرعلامتی attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    _fsize_t سائز;
    حرف name[260];
  };

  ساخت __finddata64_t {
    غیرعلامتی attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    __int64 سائز;
    حرف name[260];
  };
/* #endif */

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#تعریف_کرو _finddata_t _finddata32_t
#تعریف_کرو _finddatai64_t _finddata32i64_t

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو _findfirst _findfirst32
#تعریف_کرو _findnext _findnext32
#ورنہ
#تعریف_کرو _findfirst32 _findfirst
#تعریف_کرو _findnext32 _findnext
#اگر_ختم
#تعریف_کرو _findfirsti64 _findfirst32i64
#تعریف_کرو _findnexti64 _findnext32i64
#ورنہ
#تعریف_کرو _finddata_t _finddata64i32_t
#تعریف_کرو _finddatai64_t __finddata64_t

#تعریف_کرو _findfirst _findfirst64i32
#تعریف_کرو _findnext _findnext64i32
#تعریف_کرو _findfirsti64 _findfirst64
#تعریف_کرو _findnexti64 _findnext64
#اگر_ختم

#تعریف_کرو _FINDDATA_T_DEFINED
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WFINDDATA_T_DEFINED

  ساخت _wfinddata32_t {
    غیرعلامتی attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    _fsize_t سائز;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ساخت _wfinddata32i64_t {
    غیرعلامتی attrib;
    __time32_t وقت_create;
    __time32_t وقت_access;
    __time32_t وقت_write;
    __int64 سائز;
    wchar_t name[260];
  };

  ساخت _wfinddata64i32_t {
    غیرعلامتی attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    _fsize_t سائز;
    wchar_t name[260];
  };

  ساخت _wfinddata64_t {
    غیرعلامتی attrib;
    __time64_t وقت_create;
    __time64_t وقت_access;
    __time64_t وقت_write;
    __int64 سائز;
    wchar_t name[260];
  };
/* #endif */

#اگر_تعریف_شدہ USE_32_ثنائی_ہندسہ_وقت_T
#تعریف_کرو _wfinddata_t _wfinddata32_t
#تعریف_کرو _wfinddatai64_t _wfinddata32i64_t

#تعریف_کرو _wfindfirst _wfindfirst32
#تعریف_کرو _wfindnext _wfindnext32
#تعریف_کرو _wfindfirsti64 _wfindfirst32i64
#تعریف_کرو _wfindnexti64 _wfindnext32i64
#ورنہ
#تعریف_کرو _wfinddata_t _wfinddata64i32_t
#تعریف_کرو _wfinddatai64_t _wfinddata64_t

#تعریف_کرو _wfindfirst _wfindfirst64i32
#تعریف_کرو _wfindnext _wfindnext64i32
#تعریف_کرو _wfindfirsti64 _wfindfirst64
#تعریف_کرو _wfindnexti64 _wfindnext64
#اگر_ختم

#تعریف_کرو _WFINDDATA_T_DEFINED
#اگر_ختم

#تعریف_کرو A_معمول 0x00
#تعریف_کرو _A_RDONLY 0x01
#تعریف_کرو _A_HIDDEN 0x02
#تعریف_کرو _A_SYSTEM 0x04
#تعریف_کرو _A_SUBDIR 0x10
#تعریف_کرو _A_ARCH 0x20

#اگر_غیر_تعریف_شدہ _SIZE_T_DEFINED
#تعریف_کرو _SIZE_T_DEFINED
#تعریف_منسوخ سائز_t
#اگر_تعریف_شدہ _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف غیرعلامتی صحیح سائز_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف غیرعلامتی __int64 سائز_t;
#اگر_ختم
#ورنہ
  قسمتعریف غیرعلامتی صحیح سائز_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _SSIZE_T_DEFINED
#تعریف_کرو _SSIZE_T_DEFINED
#تعریف_منسوخ ssize_t
#اگر_تعریف_شدہ _WIN64
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف صحیح ssize_t __attribute__ ((منوال (DI)));
#ورنہ
  قسمتعریف __int64 ssize_t;
#اگر_ختم
#ورنہ
  قسمتعریف صحیح ssize_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#اگر_غیر_تعریف_شدہ _OFF_T_
#تعریف_کرو _OFF_T_
  قسمتعریف طویل _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل off_t;
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
#اگر defined(__GNUC__) && defined(__STRICT_ANSI__)
  قسمتعریف صحیح _off64_t __attribute__ ((منوال (DI)));
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف صحیح off64_t __attribute__ ((منوال (DI)));
#اگر_ختم
#ورنہ
  قسمتعریف طویل طویل _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل طویل off64_t;
#اگر_ختم
#اگر_ختم
#اگر_ختم

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#تعریف_کرو	F_OK	0	/* Check for file existence */
#تعریف_کرو	X_OK	1	/* Check for execute permission. */
#تعریف_کرو	W_OK	2	/* Check for write permission */
#تعریف_کرو	R_OK	4	/* Check for read permission */

  _CRTIMP صحیح __cdecl _access(ثابت حرف *_Filename,صحیح Access_منوال);
  _CRTIMP صحیح __cdecl _chmod(ثابت حرف *_Filename,صحیح منوال_3);
  _CRTIMP صحیح __cdecl _chsize(صحیح _FileHandle,طویل سائز_4);
  _CRTIMP صحیح __cdecl _close(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _commit(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _creat(ثابت حرف *_Filename,صحیح Permission_منوال);
  _CRTIMP صحیح __cdecl _dup(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _dup2(صحیح _FileHandleSrc,صحیح _FileHandleDst);
  _CRTIMP صحیح __cdecl _eof(صحیح _FileHandle);
  _CRTIMP طویل __cdecl _filelength(صحیح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ثابت حرف *_Filename,ساخت _finddata32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _findnext32(intptr_t ڈھونڈو_Handle,ساخت _finddata32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _findclose(intptr_t ڈھونڈو_Handle);
  _CRTIMP صحیح __cdecl _isatty(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _locking(صحیح _FileHandle,صحیح تالا_منوال,طویل عدد_کا_بائٹیں);
  _CRTIMP طویل __cdecl _lseek(صحیح _FileHandle,طویل انحراف_2,صحیح _Origin);
  _off64_t lseek64(صحیح fd,_off64_t انحراف, صحیح whence);
  _CRTIMP حرف *__cdecl _mktemp(حرف *_TemplateName);
  _CRTIMP صحیح __cdecl _pipe(صحیح *_PtHandles,غیرعلامتی صحیح Pipe_سائز,صحیح متن_منوال);
  _CRTIMP صحیح __cdecl _read(صحیح _FileHandle,خالی *_DstBuf,غیرعلامتی صحیح Max_Char_گنتی);

#اگر_غیر_تعریف_شدہ _CRT_DIRECTORY_DEFINED
#تعریف_کرو _CRT_DIRECTORY_DEFINED
  صحیح __cdecl remove(ثابت حرف *_Filename);
  صحیح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحیح __cdecl _unlink(ثابت حرف *_Filename);
#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  صحیح __cdecl unlink(ثابت حرف *_Filename);
#اگر_ختم
#اگر_ختم

  _CRTIMP صحیح __cdecl _setmode(صحیح _FileHandle,صحیح منوال_3);
  _CRTIMP طویل __cdecl _tell(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _umask(صحیح منوال_3);
  _CRTIMP صحیح __cdecl _write(صحیح _FileHandle,ثابت خالی *_Buf,غیرعلامتی صحیح Max_Char_گنتی);

#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(صحیح _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ثابت حرف *_Filename,ساخت _finddata32i64_t *ڈھونڈو_ڈیٹا);
  _CRTIMP intptr_t __cdecl _findfirst64(ثابت حرف *_Filename,ساخت __finddata64_t *ڈھونڈو_ڈیٹا);
#اگر_تعریف_شدہ __cplusplus
#شامل <string.h>
#اگر_ختم
  intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,ساخت _finddata64i32_t *ڈھونڈو_ڈیٹا);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ثابت حرف *_Filename,ساخت _finddata64i32_t *ڈھونڈو_ڈیٹا)
  {
    ساخت __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    ڈھونڈو_ڈیٹا->attrib=fd.attrib;
    ڈھونڈو_ڈیٹا->وقت_create=fd.وقت_create;
    ڈھونڈو_ڈیٹا->وقت_access=fd.وقت_access;
    ڈھونڈو_ڈیٹا->وقت_write=fd.وقت_write;
    ڈھونڈو_ڈیٹا->سائز=(_fsize_t) fd.سائز;
    strncpy(ڈھونڈو_ڈیٹا->name,fd.name,260);
    واپس ret;
  }
  _CRTIMP صحیح __cdecl _findnext32i64(intptr_t ڈھونڈو_Handle,ساخت _finddata32i64_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _findnext64(intptr_t ڈھونڈو_Handle,ساخت __finddata64_t *ڈھونڈو_ڈیٹا);
  صحیح __cdecl _findnext64i32(intptr_t ڈھونڈو_Handle,ساخت _finddata64i32_t *ڈھونڈو_ڈیٹا);
  __CRT_INLINE صحیح __cdecl _findnext64i32(intptr_t ڈھونڈو_Handle,ساخت _finddata64i32_t *ڈھونڈو_ڈیٹا)
  {
    ساخت __finddata64_t fd;
    صحیح ret = _findnext64(ڈھونڈو_Handle,&fd);
    ڈھونڈو_ڈیٹا->attrib=fd.attrib;
    ڈھونڈو_ڈیٹا->وقت_create=fd.وقت_create;
    ڈھونڈو_ڈیٹا->وقت_access=fd.وقت_access;
    ڈھونڈو_ڈیٹا->وقت_write=fd.وقت_write;
    ڈھونڈو_ڈیٹا->سائز=(_fsize_t) fd.سائز;
    strncpy(ڈھونڈو_ڈیٹا->name,fd.name,260);
    واپس ret;
  }
  __int64 __cdecl _lseeki64(صحیح _FileHandle,__int64 انحراف_2,صحیح _Origin);
  __int64 __cdecl _telli64(صحیح _FileHandle);
#اگر_ختم
#اگر_غیر_تعریف_شدہ NO_OLDNAMES

#اگر_غیر_تعریف_شدہ _UWIN
  صحیح __cdecl chdir (ثابت حرف *);
  حرف *__cdecl getcwd (حرف *, صحیح);
  صحیح __cdecl mkdir (ثابت حرف *);
  حرف *__cdecl mktemp(حرف *);
  صحیح __cdecl rmdir (ثابت حرف*);
  صحیح __cdecl chmod (ثابت حرف *, صحیح);
#اگر_ختم /* _UWIN */

#اگر_ختم /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(صحیح *_FileHandle,ثابت حرف *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح Permission_منوال);

#اگر_غیر_تعریف_شدہ __cplusplus
  _CRTIMP صحیح __cdecl _open(ثابت حرف *_Filename,صحیح _OpenFlag,...);
  _CRTIMP صحیح __cdecl _sopen(ثابت حرف *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
#ورنہ
  خارجی "C++" _CRTIMP صحیح __cdecl _open(ثابت حرف *_Filename,صحیح _Openflag,صحیح Permission_منوال = 0);
  خارجی "C++" _CRTIMP صحیح __cdecl _sopen(ثابت حرف *_Filename,صحیح _Openflag,صحیح _ShareFlag,صحیح Permission_منوال = 0);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WIO_DEFINED
#تعریف_کرو _WIO_DEFINED
  _CRTIMP صحیح __cdecl _waccess(ثابت wchar_t *_Filename,صحیح Access_منوال);
  _CRTIMP صحیح __cdecl _wchmod(ثابت wchar_t *_Filename,صحیح منوال_3);
  _CRTIMP صحیح __cdecl _wcreat(ثابت wchar_t *_Filename,صحیح Permission_منوال);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ثابت wchar_t *_Filename,ساخت _wfinddata32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wfindnext32(intptr_t ڈھونڈو_Handle,ساخت _wfinddata32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wunlink(ثابت wchar_t *_Filename);
  _CRTIMP صحیح __cdecl _wrename(ثابت wchar_t *_NewFilename,ثابت wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#اگر INTEGRAL_MAX_بٹ >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ثابت wchar_t *_Filename,ساخت _wfinddata32i64_t *ڈھونڈو_ڈیٹا);
  intptr_t __cdecl _wfindfirst64i32(ثابت wchar_t *_Filename,ساخت _wfinddata64i32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ثابت wchar_t *_Filename,ساخت _wfinddata64_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wfindnext32i64(intptr_t ڈھونڈو_Handle,ساخت _wfinddata32i64_t *ڈھونڈو_ڈیٹا);
  صحیح __cdecl _wfindnext64i32(intptr_t ڈھونڈو_Handle,ساخت _wfinddata64i32_t *ڈھونڈو_ڈیٹا);
  _CRTIMP صحیح __cdecl _wfindnext64(intptr_t ڈھونڈو_Handle,ساخت _wfinddata64_t *ڈھونڈو_ڈیٹا);
#اگر_ختم

  _CRTIMP errno_t __cdecl _wsopen_s(صحیح *_FileHandle,ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح _PermissionFlag);

#اگر !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,...);
  _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
#ورنہ
  خارجی "C++" _CRTIMP صحیح __cdecl _wopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح Permission_منوال = 0);
  خارجی "C++" _CRTIMP صحیح __cdecl _wsopen(ثابت wchar_t *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,صحیح Permission_منوال = 0);
#اگر_ختم

#اگر_ختم

  صحیح __cdecl __lock_fhandle(صحیح _Filehandle);
  خالی __cdecl _unlock_fhandle(صحیح _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(صحیح _FileHandle);
  _CRTIMP صحیح __cdecl _open_osfhandle(intptr_t _OSFileHandle,صحیح _Flags);

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  صحیح __cdecl access(ثابت حرف *_Filename,صحیح Access_منوال);
  صحیح __cdecl chmod(ثابت حرف *_Filename,صحیح Access_منوال);
  صحیح __cdecl chsize(صحیح _FileHandle,طویل سائز_4);
  صحیح __cdecl close(صحیح _FileHandle);
  صحیح __cdecl creat(ثابت حرف *_Filename,صحیح Permission_منوال);
  صحیح __cdecl dup(صحیح _FileHandle);
  صحیح __cdecl dup2(صحیح _FileHandleSrc,صحیح _FileHandleDst);
  صحیح __cdecl eof(صحیح _FileHandle);
  طویل __cdecl filelength(صحیح _FileHandle);
  صحیح __cdecl isatty(صحیح _FileHandle);
  صحیح __cdecl locking(صحیح _FileHandle,صحیح تالا_منوال,طویل عدد_کا_بائٹیں);
  طویل __cdecl lseek(صحیح _FileHandle,طویل انحراف_2,صحیح _Origin);
  حرف *__cdecl mktemp(حرف *_TemplateName);
  صحیح __cdecl open(ثابت حرف *_Filename,صحیح _OpenFlag,...);
  صحیح __cdecl اقرأ(صحیح _FileHandle,خالی *_DstBuf,غیرعلامتی صحیح Max_Char_گنتی);
  صحیح __cdecl setmode(صحیح _FileHandle,صحیح منوال_3);
  صحیح __cdecl sopen(ثابت حرف *_Filename,صحیح _OpenFlag,صحیح _ShareFlag,...);
  طویل __cdecl tell(صحیح _FileHandle);
  صحیح __cdecl umask(صحیح منوال_3);
  صحیح __cdecl اكتب(صحیح _Filehandle,ثابت خالی *_Buf,غیرعلامتی صحیح Max_Char_گنتی);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

/* Misc stuff */
حرف *getlogin(خالی);
#اگر_تعریف_شدہ __USE_MINGW_ALARM
غیرعلامتی صحیح alarm(غیرعلامتی صحیح seconds);
#اگر_ختم

#اگر_تعریف_شدہ __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ساکن اندرونی صحیح __mingw_access (ثابت حرف *__fname, صحیح __mode) {
  واپس  _access (__fname, __mode & ~X_OK);
}

#تعریف_کرو access(__f,__m)  __mingw_access (__f, __m)
#اگر_ختم


#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم


#ہدایت pack(نکالو)

#شامل <sec_api/io_s.h>

#اگر_ختم /* End _IO_H_ */

