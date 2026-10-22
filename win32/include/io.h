
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _IO_H_
#परिभाषय _IO_H_

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <string.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_अपरिभाषितम् _POSIX_

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

_CRTIMP वर्ण* __cdecl _getcwd (वर्ण*, पूर्णाङ्क);
#यदि_अपरिभाषितम् _FSIZE_T_DEFINED
  प्रकारनिर्देश अचिह्नित दीर्घ _fsize_t;
#परिभाषय _FSIZE_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _FINDDATA_T_DEFINED

  संरचना _finddata32_t {
    अचिह्नित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t आकार;
    वर्ण name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  संरचना _finddata32i64_t {
    अचिह्नित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 आकार;
    वर्ण name[260];
  };

  संरचना _finddata64i32_t {
    अचिह्नित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t आकार;
    वर्ण name[260];
  };

  संरचना __finddata64_t {
    अचिह्नित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 आकार;
    वर्ण name[260];
  };
/* #endif */

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#परिभाषय _finddata_t _finddata32_t
#परिभाषय _finddatai64_t _finddata32i64_t

#यदि_परिभाषितम् _WIN64
#परिभाषय _findfirst _findfirst32
#परिभाषय _findnext _findnext32
#अन्यथा
#परिभाषय _findfirst32 _findfirst
#परिभाषय _findnext32 _findnext
#यदि_अन्तः
#परिभाषय _findfirsti64 _findfirst32i64
#परिभाषय _findnexti64 _findnext32i64
#अन्यथा
#परिभाषय _finddata_t _finddata64i32_t
#परिभाषय _finddatai64_t __finddata64_t

#परिभाषय _findfirst _findfirst64i32
#परिभाषय _findnext _findnext64i32
#परिभाषय _findfirsti64 _findfirst64
#परिभाषय _findnexti64 _findnext64
#यदि_अन्तः

#परिभाषय _FINDDATA_T_DEFINED
#यदि_अन्तः

#यदि_अपरिभाषितम् _WFINDDATA_T_DEFINED

  संरचना _wfinddata32_t {
    अचिह्नित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t आकार;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  संरचना _wfinddata32i64_t {
    अचिह्नित attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 आकार;
    wchar_t name[260];
  };

  संरचना _wfinddata64i32_t {
    अचिह्नित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t आकार;
    wchar_t name[260];
  };

  संरचना _wfinddata64_t {
    अचिह्नित attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 आकार;
    wchar_t name[260];
  };
/* #endif */

#यदि_परिभाषितम् _USE_32BIT_TIME_T
#परिभाषय _wfinddata_t _wfinddata32_t
#परिभाषय _wfinddatai64_t _wfinddata32i64_t

#परिभाषय _wfindfirst _wfindfirst32
#परिभाषय _wfindnext _wfindnext32
#परिभाषय _wfindfirsti64 _wfindfirst32i64
#परिभाषय _wfindnexti64 _wfindnext32i64
#अन्यथा
#परिभाषय _wfinddata_t _wfinddata64i32_t
#परिभाषय _wfinddatai64_t _wfinddata64_t

#परिभाषय _wfindfirst _wfindfirst64i32
#परिभाषय _wfindnext _wfindnext64i32
#परिभाषय _wfindfirsti64 _wfindfirst64
#परिभाषय _wfindnexti64 _wfindnext64
#यदि_अन्तः

#परिभाषय _WFINDDATA_T_DEFINED
#यदि_अन्तः

#परिभाषय A_प्रसामान्यम् 0x00
#परिभाषय _A_RDONLY 0x01
#परिभाषय _A_HIDDEN 0x02
#परिभाषय _A_SYSTEM 0x04
#परिभाषय _A_SUBDIR 0x10
#परिभाषय _A_ARCH 0x20

#यदि_अपरिभाषितम् _SIZE_T_DEFINED
#परिभाषय _SIZE_T_DEFINED
#अपरिभाषय आकार_t
#यदि_परिभाषितम् _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क आकार_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश अचिह्नित __int64 आकार_t;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क आकार_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _SSIZE_T_DEFINED
#परिभाषय _SSIZE_T_DEFINED
#अपरिभाषय ssize_t
#यदि_परिभाषितम् _WIN64
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क ssize_t __attribute__ ((बहुलकम् (DI)));
#अन्यथा
  प्रकारनिर्देश __int64 ssize_t;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क ssize_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF_T_DEFINED
#परिभाषय _OFF_T_DEFINED
#यदि_अपरिभाषितम् _OFF_T_
#परिभाषय _OFF_T_
  प्रकारनिर्देश दीर्घ _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ off_t;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF64_T_DEFINED
#परिभाषय _OFF64_T_DEFINED
#यदि defined(__GNUC__) && defined(__STRICT_ANSI__)
  प्रकारनिर्देश पूर्णाङ्क _off64_t __attribute__ ((बहुलकम् (DI)));
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश पूर्णाङ्क off64_t __attribute__ ((बहुलकम् (DI)));
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश दीर्घ दीर्घ _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ दीर्घ off64_t;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#परिभाषय	F_OK	0	/* Check for file existence */
#परिभाषय	X_OK	1	/* Check for execute permission. */
#परिभाषय	W_OK	2	/* Check for write permission */
#परिभाषय	R_OK	4	/* Check for read permission */

  _CRTIMP पूर्णाङ्क __cdecl _access(ध्रुव वर्ण *_Filename,पूर्णाङ्क Access_बहुलकम्);
  _CRTIMP पूर्णाङ्क __cdecl _chmod(ध्रुव वर्ण *_Filename,पूर्णाङ्क बहुलकम्_3);
  _CRTIMP पूर्णाङ्क __cdecl _chsize(पूर्णाङ्क _FileHandle,दीर्घ आकार_4);
  _CRTIMP पूर्णाङ्क __cdecl _close(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _commit(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _creat(ध्रुव वर्ण *_Filename,पूर्णाङ्क Permission_बहुलकम्);
  _CRTIMP पूर्णाङ्क __cdecl _dup(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _dup2(पूर्णाङ्क _FileHandleSrc,पूर्णाङ्क _FileHandleDst);
  _CRTIMP पूर्णाङ्क __cdecl _eof(पूर्णाङ्क _FileHandle);
  _CRTIMP दीर्घ __cdecl _filelength(पूर्णाङ्क _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ध्रुव वर्ण *_Filename,संरचना _finddata32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _findnext32(intptr_t _FindHandle,संरचना _finddata32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP पूर्णाङ्क __cdecl _isatty(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _locking(पूर्णाङ्क _FileHandle,पूर्णाङ्क तालकम्_बहुलकम्,दीर्घ अङ्कः_सम्बन्धि_अष्टकानि);
  _CRTIMP दीर्घ __cdecl _lseek(पूर्णाङ्क _FileHandle,दीर्घ विस्थापनम्_2,पूर्णाङ्क _Origin);
  _off64_t lseek64(पूर्णाङ्क fd,_off64_t विस्थापनम्, पूर्णाङ्क whence);
  _CRTIMP वर्ण *__cdecl _mktemp(वर्ण *_TemplateName);
  _CRTIMP पूर्णाङ्क __cdecl _pipe(पूर्णाङ्क *_PtHandles,अचिह्नित पूर्णाङ्क Pipe_आकार,पूर्णाङ्क Text_बहुलकम्);
  _CRTIMP पूर्णाङ्क __cdecl _read(पूर्णाङ्क _FileHandle,शून्य *_DstBuf,अचिह्नित पूर्णाङ्क Max_Char_गणनम्);

#यदि_अपरिभाषितम् _CRT_DIRECTORY_DEFINED
#परिभाषय _CRT_DIRECTORY_DEFINED
  पूर्णाङ्क __cdecl remove(ध्रुव वर्ण *_Filename);
  पूर्णाङ्क __cdecl rename(ध्रुव वर्ण *_OldFilename,ध्रुव वर्ण *_NewFilename);
  _CRTIMP पूर्णाङ्क __cdecl _unlink(ध्रुव वर्ण *_Filename);
#यदि_अपरिभाषितम्	NO_OLDNAMES
  पूर्णाङ्क __cdecl unlink(ध्रुव वर्ण *_Filename);
#यदि_अन्तः
#यदि_अन्तः

  _CRTIMP पूर्णाङ्क __cdecl _setmode(पूर्णाङ्क _FileHandle,पूर्णाङ्क बहुलकम्_3);
  _CRTIMP दीर्घ __cdecl _tell(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _umask(पूर्णाङ्क बहुलकम्_3);
  _CRTIMP पूर्णाङ्क __cdecl _write(पूर्णाङ्क _FileHandle,ध्रुव शून्य *_Buf,अचिह्नित पूर्णाङ्क Max_Char_गणनम्);

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(पूर्णाङ्क _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ध्रुव वर्ण *_Filename,संरचना _finddata32i64_t *Find_दत्त);
  _CRTIMP intptr_t __cdecl _findfirst64(ध्रुव वर्ण *_Filename,संरचना __finddata64_t *Find_दत्त);
#यदि_परिभाषितम् __cplusplus
#अन्तर्भाव <string.h>
#यदि_अन्तः
  intptr_t __cdecl _findfirst64i32(ध्रुव वर्ण *_Filename,संरचना _finddata64i32_t *Find_दत्त);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ध्रुव वर्ण *_Filename,संरचना _finddata64i32_t *Find_दत्त)
  {
    संरचना __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    Find_दत्त->attrib=fd.attrib;
    Find_दत्त->time_create=fd.time_create;
    Find_दत्त->time_access=fd.time_access;
    Find_दत्त->time_write=fd.time_write;
    Find_दत्त->आकार=(_fsize_t) fd.आकार;
    strncpy(Find_दत्त->name,fd.name,260);
    प्रत्यागम ret;
  }
  _CRTIMP पूर्णाङ्क __cdecl _findnext32i64(intptr_t _FindHandle,संरचना _finddata32i64_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _findnext64(intptr_t _FindHandle,संरचना __finddata64_t *Find_दत्त);
  पूर्णाङ्क __cdecl _findnext64i32(intptr_t _FindHandle,संरचना _finddata64i32_t *Find_दत्त);
  __CRT_INLINE पूर्णाङ्क __cdecl _findnext64i32(intptr_t _FindHandle,संरचना _finddata64i32_t *Find_दत्त)
  {
    संरचना __finddata64_t fd;
    पूर्णाङ्क ret = _findnext64(_FindHandle,&fd);
    Find_दत्त->attrib=fd.attrib;
    Find_दत्त->time_create=fd.time_create;
    Find_दत्त->time_access=fd.time_access;
    Find_दत्त->time_write=fd.time_write;
    Find_दत्त->आकार=(_fsize_t) fd.आकार;
    strncpy(Find_दत्त->name,fd.name,260);
    प्रत्यागम ret;
  }
  __int64 __cdecl _lseeki64(पूर्णाङ्क _FileHandle,__int64 विस्थापनम्_2,पूर्णाङ्क _Origin);
  __int64 __cdecl _telli64(पूर्णाङ्क _FileHandle);
#यदि_अन्तः
#यदि_अपरिभाषितम् NO_OLDNAMES

#यदि_अपरिभाषितम् _UWIN
  पूर्णाङ्क __cdecl chdir (ध्रुव वर्ण *);
  वर्ण *__cdecl getcwd (वर्ण *, पूर्णाङ्क);
  पूर्णाङ्क __cdecl mkdir (ध्रुव वर्ण *);
  वर्ण *__cdecl mktemp(वर्ण *);
  पूर्णाङ्क __cdecl rmdir (ध्रुव वर्ण*);
  पूर्णाङ्क __cdecl chmod (ध्रुव वर्ण *, पूर्णाङ्क);
#यदि_अन्तः /* _UWIN */

#यदि_अन्तः /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(पूर्णाङ्क *_FileHandle,ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क Permission_बहुलकम्);

#यदि_अपरिभाषितम् __cplusplus
  _CRTIMP पूर्णाङ्क __cdecl _open(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _sopen(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _open(ध्रुव वर्ण *_Filename,पूर्णाङ्क _Openflag,पूर्णाङ्क Permission_बहुलकम् = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _sopen(ध्रुव वर्ण *_Filename,पूर्णाङ्क _Openflag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क Permission_बहुलकम् = 0);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WIO_DEFINED
#परिभाषय _WIO_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _waccess(ध्रुव wchar_t *_Filename,पूर्णाङ्क Access_बहुलकम्);
  _CRTIMP पूर्णाङ्क __cdecl _wchmod(ध्रुव wchar_t *_Filename,पूर्णाङ्क बहुलकम्_3);
  _CRTIMP पूर्णाङ्क __cdecl _wcreat(ध्रुव wchar_t *_Filename,पूर्णाङ्क Permission_बहुलकम्);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ध्रुव wchar_t *_Filename,संरचना _wfinddata32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32(intptr_t _FindHandle,संरचना _wfinddata32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wunlink(ध्रुव wchar_t *_Filename);
  _CRTIMP पूर्णाङ्क __cdecl _wrename(ध्रुव wchar_t *_NewFilename,ध्रुव wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#यदि INTEGRAL_MAX_द्वयङ्काः >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ध्रुव wchar_t *_Filename,संरचना _wfinddata32i64_t *Find_दत्त);
  intptr_t __cdecl _wfindfirst64i32(ध्रुव wchar_t *_Filename,संरचना _wfinddata64i32_t *Find_दत्त);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ध्रुव wchar_t *_Filename,संरचना _wfinddata64_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext32i64(intptr_t _FindHandle,संरचना _wfinddata32i64_t *Find_दत्त);
  पूर्णाङ्क __cdecl _wfindnext64i32(intptr_t _FindHandle,संरचना _wfinddata64i32_t *Find_दत्त);
  _CRTIMP पूर्णाङ्क __cdecl _wfindnext64(intptr_t _FindHandle,संरचना _wfinddata64_t *Find_दत्त);
#यदि_अन्तः

  _CRTIMP errno_t __cdecl _wsopen_s(पूर्णाङ्क *_FileHandle,ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क _PermissionFlag);

#यदि !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,...);
  _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
#अन्यथा
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क Permission_बहुलकम् = 0);
  बाह्य "C++" _CRTIMP पूर्णाङ्क __cdecl _wsopen(ध्रुव wchar_t *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,पूर्णाङ्क Permission_बहुलकम् = 0);
#यदि_अन्तः

#यदि_अन्तः

  पूर्णाङ्क __cdecl __lock_fhandle(पूर्णाङ्क _Filehandle);
  शून्य __cdecl _unlock_fhandle(पूर्णाङ्क _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(पूर्णाङ्क _FileHandle);
  _CRTIMP पूर्णाङ्क __cdecl _open_osfhandle(intptr_t _OSFileHandle,पूर्णाङ्क _Flags);

#यदि_अपरिभाषितम्	NO_OLDNAMES
  पूर्णाङ्क __cdecl access(ध्रुव वर्ण *_Filename,पूर्णाङ्क Access_बहुलकम्);
  पूर्णाङ्क __cdecl chmod(ध्रुव वर्ण *_Filename,पूर्णाङ्क Access_बहुलकम्);
  पूर्णाङ्क __cdecl chsize(पूर्णाङ्क _FileHandle,दीर्घ आकार_4);
  पूर्णाङ्क __cdecl close(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl creat(ध्रुव वर्ण *_Filename,पूर्णाङ्क Permission_बहुलकम्);
  पूर्णाङ्क __cdecl dup(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl dup2(पूर्णाङ्क _FileHandleSrc,पूर्णाङ्क _FileHandleDst);
  पूर्णाङ्क __cdecl eof(पूर्णाङ्क _FileHandle);
  दीर्घ __cdecl filelength(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl isatty(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl locking(पूर्णाङ्क _FileHandle,पूर्णाङ्क तालकम्_बहुलकम्,दीर्घ अङ्कः_सम्बन्धि_अष्टकानि);
  दीर्घ __cdecl lseek(पूर्णाङ्क _FileHandle,दीर्घ विस्थापनम्_2,पूर्णाङ्क _Origin);
  वर्ण *__cdecl mktemp(वर्ण *_TemplateName);
  पूर्णाङ्क __cdecl उद्घाटय(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,...);
  पूर्णाङ्क __cdecl पठ(पूर्णाङ्क _FileHandle,शून्य *_DstBuf,अचिह्नित पूर्णाङ्क Max_Char_गणनम्);
  पूर्णाङ्क __cdecl setmode(पूर्णाङ्क _FileHandle,पूर्णाङ्क बहुलकम्_3);
  पूर्णाङ्क __cdecl sopen(ध्रुव वर्ण *_Filename,पूर्णाङ्क _OpenFlag,पूर्णाङ्क _ShareFlag,...);
  दीर्घ __cdecl tell(पूर्णाङ्क _FileHandle);
  पूर्णाङ्क __cdecl umask(पूर्णाङ्क बहुलकम्_3);
  पूर्णाङ्क __cdecl लिख(पूर्णाङ्क _Filehandle,ध्रुव शून्य *_Buf,अचिह्नित पूर्णाङ्क Max_Char_गणनम्);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

/* Misc stuff */
वर्ण *getlogin(शून्य);
#यदि_परिभाषितम् __USE_MINGW_ALARM
अचिह्नित पूर्णाङ्क alarm(अचिह्नित पूर्णाङ्क seconds);
#यदि_अन्तः

#यदि_परिभाषितम् __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
स्थिर अन्तःस्थ पूर्णाङ्क __mingw_access (ध्रुव वर्ण *__fname, पूर्णाङ्क __mode) {
  प्रत्यागम  _access (__fname, __mode & ~X_OK);
}

#परिभाषय access(__f,__m)  __mingw_access (__f, __m)
#यदि_अन्तः


#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः


#निर्देशः pack(निष्कासय)

#अन्तर्भाव <sec_api/io_s.h>

#यदि_अन्तः /* End _IO_H_ */

