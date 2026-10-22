
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _IO_H_
#నిర్వచించు _IO_H_

#అన్తర్భావ <_mingw.h>
#అన్తర్భావ <string.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితం_కాకపోతే _POSIX_

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

_CRTIMP అక్షరం* __cdecl _getcwd (అక్షరం*, పూర్ణాంకం);
#నిర్వచితం_కాకపోతే _FSIZE_T_DEFINED
  రకనిర్వచనం గుర్తులేని దీర్ఘ _fsize_t;
#నిర్వచించు _FSIZE_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _FINDDATA_T_DEFINED

  నిర్మాణం _finddata32_t {
    గుర్తులేని attrib;
    __time32_t సమయం_create;
    __time32_t సమయం_access;
    __time32_t సమయం_write;
    _fsize_t కొలత;
    అక్షరం name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  నిర్మాణం _finddata32i64_t {
    గుర్తులేని attrib;
    __time32_t సమయం_create;
    __time32_t సమయం_access;
    __time32_t సమయం_write;
    __int64 కొలత;
    అక్షరం name[260];
  };

  నిర్మాణం _finddata64i32_t {
    గుర్తులేని attrib;
    __time64_t సమయం_create;
    __time64_t సమయం_access;
    __time64_t సమయం_write;
    _fsize_t కొలత;
    అక్షరం name[260];
  };

  నిర్మాణం __finddata64_t {
    గుర్తులేని attrib;
    __time64_t సమయం_create;
    __time64_t సమయం_access;
    __time64_t సమయం_write;
    __int64 కొలత;
    అక్షరం name[260];
  };
/* #endif */

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచించు _finddata_t _finddata32_t
#నిర్వచించు _finddatai64_t _finddata32i64_t

#నిర్వచితమైతే _WIN64
#నిర్వచించు _findfirst _findfirst32
#నిర్వచించు _findnext _findnext32
#లేకపోతే
#నిర్వచించు _findfirst32 _findfirst
#నిర్వచించు _findnext32 _findnext
#అయితే_ముగింపు
#నిర్వచించు _findfirsti64 _findfirst32i64
#నిర్వచించు _findnexti64 _findnext32i64
#లేకపోతే
#నిర్వచించు _finddata_t _finddata64i32_t
#నిర్వచించు _finddatai64_t __finddata64_t

#నిర్వచించు _findfirst _findfirst64i32
#నిర్వచించు _findnext _findnext64i32
#నిర్వచించు _findfirsti64 _findfirst64
#నిర్వచించు _findnexti64 _findnext64
#అయితే_ముగింపు

#నిర్వచించు _FINDDATA_T_DEFINED
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WFINDDATA_T_DEFINED

  నిర్మాణం _wfinddata32_t {
    గుర్తులేని attrib;
    __time32_t సమయం_create;
    __time32_t సమయం_access;
    __time32_t సమయం_write;
    _fsize_t కొలత;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  నిర్మాణం _wfinddata32i64_t {
    గుర్తులేని attrib;
    __time32_t సమయం_create;
    __time32_t సమయం_access;
    __time32_t సమయం_write;
    __int64 కొలత;
    wchar_t name[260];
  };

  నిర్మాణం _wfinddata64i32_t {
    గుర్తులేని attrib;
    __time64_t సమయం_create;
    __time64_t సమయం_access;
    __time64_t సమయం_write;
    _fsize_t కొలత;
    wchar_t name[260];
  };

  నిర్మాణం _wfinddata64_t {
    గుర్తులేని attrib;
    __time64_t సమయం_create;
    __time64_t సమయం_access;
    __time64_t సమయం_write;
    __int64 కొలత;
    wchar_t name[260];
  };
/* #endif */

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచించు _wfinddata_t _wfinddata32_t
#నిర్వచించు _wfinddatai64_t _wfinddata32i64_t

#నిర్వచించు _wfindfirst _wfindfirst32
#నిర్వచించు _wfindnext _wfindnext32
#నిర్వచించు _wfindfirsti64 _wfindfirst32i64
#నిర్వచించు _wfindnexti64 _wfindnext32i64
#లేకపోతే
#నిర్వచించు _wfinddata_t _wfinddata64i32_t
#నిర్వచించు _wfinddatai64_t _wfinddata64_t

#నిర్వచించు _wfindfirst _wfindfirst64i32
#నిర్వచించు _wfindnext _wfindnext64i32
#నిర్వచించు _wfindfirsti64 _wfindfirst64
#నిర్వచించు _wfindnexti64 _wfindnext64
#అయితే_ముగింపు

#నిర్వచించు _WFINDDATA_T_DEFINED
#అయితే_ముగింపు

#నిర్వచించు A_సాధారణ 0x00
#నిర్వచించు _A_RDONLY 0x01
#నిర్వచించు _A_HIDDEN 0x02
#నిర్వచించు _A_SYSTEM 0x04
#నిర్వచించు _A_SUBDIR 0x10
#నిర్వచించు _A_ARCH 0x20

#నిర్వచితం_కాకపోతే _SIZE_T_DEFINED
#నిర్వచించు _SIZE_T_DEFINED
#నిర్వచనం_రద్దు కొలత_t
#నిర్వచితమైతే _WIN64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం కొలత_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం గుర్తులేని __int64 కొలత_t;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం కొలత_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _SSIZE_T_DEFINED
#నిర్వచించు _SSIZE_T_DEFINED
#నిర్వచనం_రద్దు ssize_t
#నిర్వచితమైతే _WIN64
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం పూర్ణాంకం ssize_t __attribute__ ((బహుళకం (DI)));
#లేకపోతే
  రకనిర్వచనం __int64 ssize_t;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం పూర్ణాంకం ssize_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF_T_DEFINED
#నిర్వచించు _OFF_T_DEFINED
#నిర్వచితం_కాకపోతే _OFF_T_
#నిర్వచించు _OFF_T_
  రకనిర్వచనం దీర్ఘ _off_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ off_t;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF64_T_DEFINED
#నిర్వచించు _OFF64_T_DEFINED
#ఒకవేళ defined(__GNUC__) && defined(__STRICT_ANSI__)
  రకనిర్వచనం పూర్ణాంకం _off64_t __attribute__ ((బహుళకం (DI)));
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం పూర్ణాంకం off64_t __attribute__ ((బహుళకం (DI)));
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం దీర్ఘ దీర్ఘ _off64_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ దీర్ఘ off64_t;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#నిర్వచించు	F_OK	0	/* Check for file existence */
#నిర్వచించు	X_OK	1	/* Check for execute permission. */
#నిర్వచించు	W_OK	2	/* Check for write permission */
#నిర్వచించు	R_OK	4	/* Check for read permission */

  _CRTIMP పూర్ణాంకం __cdecl _access(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం Access_బహుళకం);
  _CRTIMP పూర్ణాంకం __cdecl _chmod(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం బహుళకం_3);
  _CRTIMP పూర్ణాంకం __cdecl _chsize(పూర్ణాంకం _FileHandle,దీర్ఘ కొలత_4);
  _CRTIMP పూర్ణాంకం __cdecl _close(పూర్ణాంకం _FileHandle);
  _CRTIMP పూర్ణాంకం __cdecl _commit(పూర్ణాంకం _FileHandle);
  _CRTIMP పూర్ణాంకం __cdecl _creat(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం Permission_బహుళకం);
  _CRTIMP పూర్ణాంకం __cdecl _dup(పూర్ణాంకం _FileHandle);
  _CRTIMP పూర్ణాంకం __cdecl _dup2(పూర్ణాంకం _FileHandleSrc,పూర్ణాంకం _FileHandleDst);
  _CRTIMP పూర్ణాంకం __cdecl _eof(పూర్ణాంకం _FileHandle);
  _CRTIMP దీర్ఘ __cdecl _filelength(పూర్ణాంకం _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం _finddata32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _findnext32(intptr_t కనుగొను_Handle,నిర్మాణం _finddata32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _findclose(intptr_t కనుగొను_Handle);
  _CRTIMP పూర్ణాంకం __cdecl _isatty(పూర్ణాంకం _FileHandle);
  _CRTIMP పూర్ణాంకం __cdecl _locking(పూర్ణాంకం _FileHandle,పూర్ణాంకం తాళం_బహుళకం,దీర్ఘ అంకె_యొక్క_బైట్లు);
  _CRTIMP దీర్ఘ __cdecl _lseek(పూర్ణాంకం _FileHandle,దీర్ఘ స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
  _off64_t lseek64(పూర్ణాంకం fd,_off64_t స్థానభ్రంశం, పూర్ణాంకం whence);
  _CRTIMP అక్షరం *__cdecl _mktemp(అక్షరం *_TemplateName);
  _CRTIMP పూర్ణాంకం __cdecl _pipe(పూర్ణాంకం *_PtHandles,గుర్తులేని పూర్ణాంకం Pipe_కొలత,పూర్ణాంకం పాఠ్యం_బహుళకం);
  _CRTIMP పూర్ణాంకం __cdecl _read(పూర్ణాంకం _FileHandle,శూన్య *_DstBuf,గుర్తులేని పూర్ణాంకం Max_Char_లెక్క);

#నిర్వచితం_కాకపోతే _CRT_DIRECTORY_DEFINED
#నిర్వచించు _CRT_DIRECTORY_DEFINED
  పూర్ణాంకం __cdecl remove(స్థిరరాశి అక్షరం *_Filename);
  పూర్ణాంకం __cdecl rename(స్థిరరాశి అక్షరం *_OldFilename,స్థిరరాశి అక్షరం *_NewFilename);
  _CRTIMP పూర్ణాంకం __cdecl _unlink(స్థిరరాశి అక్షరం *_Filename);
#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  పూర్ణాంకం __cdecl unlink(స్థిరరాశి అక్షరం *_Filename);
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP పూర్ణాంకం __cdecl _setmode(పూర్ణాంకం _FileHandle,పూర్ణాంకం బహుళకం_3);
  _CRTIMP దీర్ఘ __cdecl _tell(పూర్ణాంకం _FileHandle);
  _CRTIMP పూర్ణాంకం __cdecl _umask(పూర్ణాంకం బహుళకం_3);
  _CRTIMP పూర్ణాంకం __cdecl _write(పూర్ణాంకం _FileHandle,స్థిరరాశి శూన్య *_Buf,గుర్తులేని పూర్ణాంకం Max_Char_లెక్క);

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(పూర్ణాంకం _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం _finddata32i64_t *కనుగొను_దత్తాంశం);
  _CRTIMP intptr_t __cdecl _findfirst64(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం __finddata64_t *కనుగొను_దత్తాంశం);
#నిర్వచితమైతే __cplusplus
#అన్తర్భావ <string.h>
#అయితే_ముగింపు
  intptr_t __cdecl _findfirst64i32(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం _finddata64i32_t *కనుగొను_దత్తాంశం);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(స్థిరరాశి అక్షరం *_Filename,నిర్మాణం _finddata64i32_t *కనుగొను_దత్తాంశం)
  {
    నిర్మాణం __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    కనుగొను_దత్తాంశం->attrib=fd.attrib;
    కనుగొను_దత్తాంశం->సమయం_create=fd.సమయం_create;
    కనుగొను_దత్తాంశం->సమయం_access=fd.సమయం_access;
    కనుగొను_దత్తాంశం->సమయం_write=fd.సమయం_write;
    కనుగొను_దత్తాంశం->కొలత=(_fsize_t) fd.కొలత;
    strncpy(కనుగొను_దత్తాంశం->name,fd.name,260);
    తిరిగి ret;
  }
  _CRTIMP పూర్ణాంకం __cdecl _findnext32i64(intptr_t కనుగొను_Handle,నిర్మాణం _finddata32i64_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _findnext64(intptr_t కనుగొను_Handle,నిర్మాణం __finddata64_t *కనుగొను_దత్తాంశం);
  పూర్ణాంకం __cdecl _findnext64i32(intptr_t కనుగొను_Handle,నిర్మాణం _finddata64i32_t *కనుగొను_దత్తాంశం);
  __CRT_INLINE పూర్ణాంకం __cdecl _findnext64i32(intptr_t కనుగొను_Handle,నిర్మాణం _finddata64i32_t *కనుగొను_దత్తాంశం)
  {
    నిర్మాణం __finddata64_t fd;
    పూర్ణాంకం ret = _findnext64(కనుగొను_Handle,&fd);
    కనుగొను_దత్తాంశం->attrib=fd.attrib;
    కనుగొను_దత్తాంశం->సమయం_create=fd.సమయం_create;
    కనుగొను_దత్తాంశం->సమయం_access=fd.సమయం_access;
    కనుగొను_దత్తాంశం->సమయం_write=fd.సమయం_write;
    కనుగొను_దత్తాంశం->కొలత=(_fsize_t) fd.కొలత;
    strncpy(కనుగొను_దత్తాంశం->name,fd.name,260);
    తిరిగి ret;
  }
  __int64 __cdecl _lseeki64(పూర్ణాంకం _FileHandle,__int64 స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
  __int64 __cdecl _telli64(పూర్ణాంకం _FileHandle);
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే NO_OLDNAMES

#నిర్వచితం_కాకపోతే _UWIN
  పూర్ణాంకం __cdecl chdir (స్థిరరాశి అక్షరం *);
  అక్షరం *__cdecl getcwd (అక్షరం *, పూర్ణాంకం);
  పూర్ణాంకం __cdecl mkdir (స్థిరరాశి అక్షరం *);
  అక్షరం *__cdecl mktemp(అక్షరం *);
  పూర్ణాంకం __cdecl rmdir (స్థిరరాశి అక్షరం*);
  పూర్ణాంకం __cdecl chmod (స్థిరరాశి అక్షరం *, పూర్ణాంకం);
#అయితే_ముగింపు /* _UWIN */

#అయితే_ముగింపు /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(పూర్ణాంకం *_FileHandle,స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,పూర్ణాంకం Permission_బహుళకం);

#నిర్వచితం_కాకపోతే __cplusplus
  _CRTIMP పూర్ణాంకం __cdecl _open(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _OpenFlag,...);
  _CRTIMP పూర్ణాంకం __cdecl _sopen(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,...);
#లేకపోతే
  బాహ్య "C++" _CRTIMP పూర్ణాంకం __cdecl _open(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _Openflag,పూర్ణాంకం Permission_బహుళకం = 0);
  బాహ్య "C++" _CRTIMP పూర్ణాంకం __cdecl _sopen(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _Openflag,పూర్ణాంకం _ShareFlag,పూర్ణాంకం Permission_బహుళకం = 0);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WIO_DEFINED
#నిర్వచించు _WIO_DEFINED
  _CRTIMP పూర్ణాంకం __cdecl _waccess(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం Access_బహుళకం);
  _CRTIMP పూర్ణాంకం __cdecl _wchmod(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం బహుళకం_3);
  _CRTIMP పూర్ణాంకం __cdecl _wcreat(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం Permission_బహుళకం);
  _CRTIMP intptr_t __cdecl _wfindfirst32(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wfindnext32(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wunlink(స్థిరరాశి wchar_t *_Filename);
  _CRTIMP పూర్ణాంకం __cdecl _wrename(స్థిరరాశి wchar_t *_NewFilename,స్థిరరాశి wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata32i64_t *కనుగొను_దత్తాంశం);
  intptr_t __cdecl _wfindfirst64i32(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata64i32_t *కనుగొను_దత్తాంశం);
  _CRTIMP intptr_t __cdecl _wfindfirst64(స్థిరరాశి wchar_t *_Filename,నిర్మాణం _wfinddata64_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wfindnext32i64(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata32i64_t *కనుగొను_దత్తాంశం);
  పూర్ణాంకం __cdecl _wfindnext64i32(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata64i32_t *కనుగొను_దత్తాంశం);
  _CRTIMP పూర్ణాంకం __cdecl _wfindnext64(intptr_t కనుగొను_Handle,నిర్మాణం _wfinddata64_t *కనుగొను_దత్తాంశం);
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _wsopen_s(పూర్ణాంకం *_FileHandle,స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,పూర్ణాంకం _PermissionFlag);

#ఒకవేళ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP పూర్ణాంకం __cdecl _wopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,...);
  _CRTIMP పూర్ణాంకం __cdecl _wsopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,...);
#లేకపోతే
  బాహ్య "C++" _CRTIMP పూర్ణాంకం __cdecl _wopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం Permission_బహుళకం = 0);
  బాహ్య "C++" _CRTIMP పూర్ణాంకం __cdecl _wsopen(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,పూర్ణాంకం Permission_బహుళకం = 0);
#అయితే_ముగింపు

#అయితే_ముగింపు

  పూర్ణాంకం __cdecl __lock_fhandle(పూర్ణాంకం _Filehandle);
  శూన్య __cdecl _unlock_fhandle(పూర్ణాంకం _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(పూర్ణాంకం _FileHandle);
  _CRTIMP పూర్ణాంకం __cdecl _open_osfhandle(intptr_t _OSFileHandle,పూర్ణాంకం _Flags);

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  పూర్ణాంకం __cdecl access(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం Access_బహుళకం);
  పూర్ణాంకం __cdecl chmod(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం Access_బహుళకం);
  పూర్ణాంకం __cdecl chsize(పూర్ణాంకం _FileHandle,దీర్ఘ కొలత_4);
  పూర్ణాంకం __cdecl close(పూర్ణాంకం _FileHandle);
  పూర్ణాంకం __cdecl creat(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం Permission_బహుళకం);
  పూర్ణాంకం __cdecl dup(పూర్ణాంకం _FileHandle);
  పూర్ణాంకం __cdecl dup2(పూర్ణాంకం _FileHandleSrc,పూర్ణాంకం _FileHandleDst);
  పూర్ణాంకం __cdecl eof(పూర్ణాంకం _FileHandle);
  దీర్ఘ __cdecl filelength(పూర్ణాంకం _FileHandle);
  పూర్ణాంకం __cdecl isatty(పూర్ణాంకం _FileHandle);
  పూర్ణాంకం __cdecl locking(పూర్ణాంకం _FileHandle,పూర్ణాంకం తాళం_బహుళకం,దీర్ఘ అంకె_యొక్క_బైట్లు);
  దీర్ఘ __cdecl lseek(పూర్ణాంకం _FileHandle,దీర్ఘ స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
  అక్షరం *__cdecl mktemp(అక్షరం *_TemplateName);
  పూర్ణాంకం __cdecl open(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _OpenFlag,...);
  పూర్ణాంకం __cdecl పఠ(పూర్ణాంకం _FileHandle,శూన్య *_DstBuf,గుర్తులేని పూర్ణాంకం Max_Char_లెక్క);
  పూర్ణాంకం __cdecl setmode(పూర్ణాంకం _FileHandle,పూర్ణాంకం బహుళకం_3);
  పూర్ణాంకం __cdecl sopen(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం _OpenFlag,పూర్ణాంకం _ShareFlag,...);
  దీర్ఘ __cdecl tell(పూర్ణాంకం _FileHandle);
  పూర్ణాంకం __cdecl umask(పూర్ణాంకం బహుళకం_3);
  పూర్ణాంకం __cdecl లిఖ(పూర్ణాంకం _Filehandle,స్థిరరాశి శూన్య *_Buf,గుర్తులేని పూర్ణాంకం Max_Char_లెక్క);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

/* Misc stuff */
అక్షరం *getlogin(శూన్య);
#నిర్వచితమైతే __USE_MINGW_ALARM
గుర్తులేని పూర్ణాంకం alarm(గుర్తులేని పూర్ణాంకం seconds);
#అయితే_ముగింపు

#నిర్వచితమైతే __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
స్థిర అంతఃవరుస పూర్ణాంకం __mingw_access (స్థిరరాశి అక్షరం *__fname, పూర్ణాంకం __mode) {
  తిరిగి  _access (__fname, __mode & ~X_OK);
}

#నిర్వచించు access(__f,__m)  __mingw_access (__f, __m)
#అయితే_ముగింపు


#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు


#సూచన pack(తీయి)

#అన్తర్భావ <sec_api/io_s.h>

#అయితే_ముగింపు /* End _IO_H_ */

