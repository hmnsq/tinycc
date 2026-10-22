
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _IO_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _IO_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>
#ಅನ್ತರ್ಭಾವ <string.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _POSIX_

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

_CRTIMP ಅಕ್ಷರ* __cdecl _getcwd (ಅಕ್ಷರ*, ಪೂರ್ಣಾಂಕ);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FSIZE_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ _fsize_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _FSIZE_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FINDDATA_T_DEFINED

  ರಚನೆ _finddata32_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time32_t ಸಮಯ_create;
    __time32_t ಸಮಯ_access;
    __time32_t ಸಮಯ_write;
    _fsize_t ಗಾತ್ರ_2;
    ಅಕ್ಷರ name[260];
  };

/*#if _INTEGRAL_MAX_BITS >= 64*/

  ರಚನೆ _finddata32i64_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time32_t ಸಮಯ_create;
    __time32_t ಸಮಯ_access;
    __time32_t ಸಮಯ_write;
    __int64 ಗಾತ್ರ_2;
    ಅಕ್ಷರ name[260];
  };

  ರಚನೆ _finddata64i32_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time64_t ಸಮಯ_create;
    __time64_t ಸಮಯ_access;
    __time64_t ಸಮಯ_write;
    _fsize_t ಗಾತ್ರ_2;
    ಅಕ್ಷರ name[260];
  };

  ರಚನೆ __finddata64_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time64_t ಸಮಯ_create;
    __time64_t ಸಮಯ_access;
    __time64_t ಸಮಯ_write;
    __int64 ಗಾತ್ರ_2;
    ಅಕ್ಷರ name[260];
  };
/* #endif */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿಸು _finddata_t _finddata32_t
#ವ್ಯಾಖ್ಯಾನಿಸು _finddatai64_t _finddata32i64_t

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು _findfirst _findfirst32
#ವ್ಯಾಖ್ಯಾನಿಸು _findnext _findnext32
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _findfirst32 _findfirst
#ವ್ಯಾಖ್ಯಾನಿಸು _findnext32 _findnext
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು _findfirsti64 _findfirst32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _findnexti64 _findnext32i64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _finddata_t _finddata64i32_t
#ವ್ಯಾಖ್ಯಾನಿಸು _finddatai64_t __finddata64_t

#ವ್ಯಾಖ್ಯಾನಿಸು _findfirst _findfirst64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _findnext _findnext64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _findfirsti64 _findfirst64
#ವ್ಯಾಖ್ಯಾನಿಸು _findnexti64 _findnext64
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _FINDDATA_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WFINDDATA_T_DEFINED

  ರಚನೆ _wfinddata32_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time32_t ಸಮಯ_create;
    __time32_t ಸಮಯ_access;
    __time32_t ಸಮಯ_write;
    _fsize_t ಗಾತ್ರ_2;
    wchar_t name[260];
  };

/* #if _INTEGRAL_MAX_BITS >= 64 */

  ರಚನೆ _wfinddata32i64_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time32_t ಸಮಯ_create;
    __time32_t ಸಮಯ_access;
    __time32_t ಸಮಯ_write;
    __int64 ಗಾತ್ರ_2;
    wchar_t name[260];
  };

  ರಚನೆ _wfinddata64i32_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time64_t ಸಮಯ_create;
    __time64_t ಸಮಯ_access;
    __time64_t ಸಮಯ_write;
    _fsize_t ಗಾತ್ರ_2;
    wchar_t name[260];
  };

  ರಚನೆ _wfinddata64_t {
    ಚಿಹ್ನೆರಹಿತ attrib;
    __time64_t ಸಮಯ_create;
    __time64_t ಸಮಯ_access;
    __time64_t ಸಮಯ_write;
    __int64 ಗಾತ್ರ_2;
    wchar_t name[260];
  };
/* #endif */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ USE_32_ಬಿಟ್_ಸಮಯ_T
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddata_t _wfinddata32_t
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddatai64_t _wfinddata32i64_t

#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirst _wfindfirst32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnext _wfindnext32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirsti64 _wfindfirst32i64
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnexti64 _wfindnext32i64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddata_t _wfinddata64i32_t
#ವ್ಯಾಖ್ಯಾನಿಸು _wfinddatai64_t _wfinddata64_t

#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirst _wfindfirst64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnext _wfindnext64i32
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindfirsti64 _wfindfirst64
#ವ್ಯಾಖ್ಯಾನಿಸು _wfindnexti64 _wfindnext64
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _WFINDDATA_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು A_ಸಾಮಾನ್ಯ 0x00
#ವ್ಯಾಖ್ಯಾನಿಸು _A_RDONLY 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು _A_HIDDEN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು _A_SYSTEM 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು _A_SUBDIR 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು _A_ARCH 0x20

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ಗಾತ್ರ_t
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ಗಾತ್ರ_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SSIZE_T_DEFINED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ssize_t
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ ssize_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 ssize_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ ssize_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF_T_
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF_T_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ _off_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ off_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _OFF64_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _OFF64_T_DEFINED
#ಆದರೆ defined(__GNUC__) && defined(__STRICT_ANSI__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ _off64_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ off64_t __attribute__ ((ಬಹುಲಕ (DI)));
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ _off64_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ off64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  /* Some defines for _access nAccessMode (MS doesn't define them, but
  * it doesn't seem to hurt to add them). */
#ವ್ಯಾಖ್ಯಾನಿಸು	F_OK	0	/* Check for file existence */
#ವ್ಯಾಖ್ಯಾನಿಸು	X_OK	1	/* Check for execute permission. */
#ವ್ಯಾಖ್ಯಾನಿಸು	W_OK	2	/* Check for write permission */
#ವ್ಯಾಖ್ಯಾನಿಸು	R_OK	4	/* Check for read permission */

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _access(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _chmod(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _chsize(ಪೂರ್ಣಾಂಕ _FileHandle,ದೀರ್ಘ ಗಾತ್ರ_5);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _close(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _commit(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _creat(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _dup(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _dup2(ಪೂರ್ಣಾಂಕ _FileHandleSrc,ಪೂರ್ಣಾಂಕ _FileHandleDst);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _eof(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ದೀರ್ಘ __cdecl _filelength(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ _finddata32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _findnext32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _finddata32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _findclose(intptr_t ಕಂಡುಹಿಡಿ_Handle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _isatty(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _locking(ಪೂರ್ಣಾಂಕ _FileHandle,ಪೂರ್ಣಾಂಕ ಬೀಗ_ಬಹುಲಕ,ದೀರ್ಘ ಅಂಕೆ_ದ_ಬೈಟುಗಳು);
  _CRTIMP ದೀರ್ಘ __cdecl _lseek(ಪೂರ್ಣಾಂಕ _FileHandle,ದೀರ್ಘ ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
  _off64_t lseek64(ಪೂರ್ಣಾಂಕ fd,_off64_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ whence);
  _CRTIMP ಅಕ್ಷರ *__cdecl _mktemp(ಅಕ್ಷರ *_TemplateName);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _pipe(ಪೂರ್ಣಾಂಕ *_PtHandles,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Pipe_ಗಾತ್ರ,ಪೂರ್ಣಾಂಕ ಪಠ್ಯ_ಬಹುಲಕ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _read(ಪೂರ್ಣಾಂಕ _FileHandle,ಶೂನ್ಯ *_DstBuf,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Max_Char_ಎಣಿಕೆ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_DIRECTORY_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_DIRECTORY_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl remove(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename);
  ಪೂರ್ಣಾಂಕ __cdecl rename(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_OldFilename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_NewFilename);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _unlink(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ಪೂರ್ಣಾಂಕ __cdecl unlink(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _setmode(ಪೂರ್ಣಾಂಕ _FileHandle,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  _CRTIMP ದೀರ್ಘ __cdecl _tell(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _umask(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _write(ಪೂರ್ಣಾಂಕ _FileHandle,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_Buf,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Max_Char_ಎಣಿಕೆ);

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ _finddata32i64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP intptr_t __cdecl _findfirst64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ __finddata64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ಅನ್ತರ್ಭಾವ <string.h>
#ಆದರೆ_ಅಂತ್ಯ
  intptr_t __cdecl _findfirst64i32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ _finddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ರಚನೆ _finddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ)
  {
    ರಚನೆ __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->attrib=fd.attrib;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಸಮಯ_create=fd.ಸಮಯ_create;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಸಮಯ_access=fd.ಸಮಯ_access;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಸಮಯ_write=fd.ಸಮಯ_write;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಗಾತ್ರ_2=(_fsize_t) fd.ಗಾತ್ರ_2;
    strncpy(ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->name,fd.name,260);
    ಹಿಂತಿರುಗಿ ret;
  }
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _findnext32i64(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _finddata32i64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _findnext64(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ __finddata64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  ಪೂರ್ಣಾಂಕ __cdecl _findnext64i32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _finddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl _findnext64i32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _finddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ)
  {
    ರಚನೆ __finddata64_t fd;
    ಪೂರ್ಣಾಂಕ ret = _findnext64(ಕಂಡುಹಿಡಿ_Handle,&fd);
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->attrib=fd.attrib;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಸಮಯ_create=fd.ಸಮಯ_create;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಸಮಯ_access=fd.ಸಮಯ_access;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಸಮಯ_write=fd.ಸಮಯ_write;
    ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->ಗಾತ್ರ_2=(_fsize_t) fd.ಗಾತ್ರ_2;
    strncpy(ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ->name,fd.name,260);
    ಹಿಂತಿರುಗಿ ret;
  }
  __int64 __cdecl _lseeki64(ಪೂರ್ಣಾಂಕ _FileHandle,__int64 ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
  __int64 __cdecl _telli64(ಪೂರ್ಣಾಂಕ _FileHandle);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NO_OLDNAMES

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _UWIN
  ಪೂರ್ಣಾಂಕ __cdecl chdir (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *);
  ಅಕ್ಷರ *__cdecl getcwd (ಅಕ್ಷರ *, ಪೂರ್ಣಾಂಕ);
  ಪೂರ್ಣಾಂಕ __cdecl mkdir (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *);
  ಅಕ್ಷರ *__cdecl mktemp(ಅಕ್ಷರ *);
  ಪೂರ್ಣಾಂಕ __cdecl rmdir (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*);
  ಪೂರ್ಣಾಂಕ __cdecl chmod (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ಪೂರ್ಣಾಂಕ);
#ಆದರೆ_ಅಂತ್ಯ /* _UWIN */

#ಆದರೆ_ಅಂತ್ಯ /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(ಪೂರ್ಣಾಂಕ *_FileHandle,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _open(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,...);
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _open(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _Openflag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ = 0);
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _sopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _Openflag,ಪೂರ್ಣಾಂಕ _ShareFlag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ = 0);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WIO_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _waccess(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wchmod(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wcreat(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ);
  _CRTIMP intptr_t __cdecl _wfindfirst32(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wfindnext32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wunlink(ಸ್ಥಿರಾಂಕ wchar_t *_Filename);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wrename(ಸ್ಥಿರಾಂಕ wchar_t *_NewFilename,ಸ್ಥಿರಾಂಕ wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);

#ಆದರೆ INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata32i64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  intptr_t __cdecl _wfindfirst64i32(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP intptr_t __cdecl _wfindfirst64(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ರಚನೆ _wfinddata64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wfindnext32i64(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata32i64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  ಪೂರ್ಣಾಂಕ __cdecl _wfindnext64i32(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata64i32_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wfindnext64(intptr_t ಕಂಡುಹಿಡಿ_Handle,ರಚನೆ _wfinddata64_t *ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP errno_t __cdecl _wsopen_s(ಪೂರ್ಣಾಂಕ *_FileHandle,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,ಪೂರ್ಣಾಂಕ _PermissionFlag);

#ಆದರೆ !defined(__cplusplus) || !(defined(_X86_) && !defined(__x86_64))
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,...);
#ಇಲ್ಲದಿದ್ದರೆ
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ = 0);
  ಬಾಹ್ಯ "C++" _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ = 0);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ

  ಪೂರ್ಣಾಂಕ __cdecl __lock_fhandle(ಪೂರ್ಣಾಂಕ _Filehandle);
  ಶೂನ್ಯ __cdecl _unlock_fhandle(ಪೂರ್ಣಾಂಕ _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(ಪೂರ್ಣಾಂಕ _FileHandle);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _open_osfhandle(intptr_t _OSFileHandle,ಪೂರ್ಣಾಂಕ _Flags);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ಪೂರ್ಣಾಂಕ __cdecl access(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  ಪೂರ್ಣಾಂಕ __cdecl chmod(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ Access_ಬಹುಲಕ);
  ಪೂರ್ಣಾಂಕ __cdecl chsize(ಪೂರ್ಣಾಂಕ _FileHandle,ದೀರ್ಘ ಗಾತ್ರ_5);
  ಪೂರ್ಣಾಂಕ __cdecl close(ಪೂರ್ಣಾಂಕ _FileHandle);
  ಪೂರ್ಣಾಂಕ __cdecl creat(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ Permission_ಬಹುಲಕ);
  ಪೂರ್ಣಾಂಕ __cdecl dup(ಪೂರ್ಣಾಂಕ _FileHandle);
  ಪೂರ್ಣಾಂಕ __cdecl dup2(ಪೂರ್ಣಾಂಕ _FileHandleSrc,ಪೂರ್ಣಾಂಕ _FileHandleDst);
  ಪೂರ್ಣಾಂಕ __cdecl eof(ಪೂರ್ಣಾಂಕ _FileHandle);
  ದೀರ್ಘ __cdecl filelength(ಪೂರ್ಣಾಂಕ _FileHandle);
  ಪೂರ್ಣಾಂಕ __cdecl isatty(ಪೂರ್ಣಾಂಕ _FileHandle);
  ಪೂರ್ಣಾಂಕ __cdecl locking(ಪೂರ್ಣಾಂಕ _FileHandle,ಪೂರ್ಣಾಂಕ ಬೀಗ_ಬಹುಲಕ,ದೀರ್ಘ ಅಂಕೆ_ದ_ಬೈಟುಗಳು);
  ದೀರ್ಘ __cdecl lseek(ಪೂರ್ಣಾಂಕ _FileHandle,ದೀರ್ಘ ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
  ಅಕ್ಷರ *__cdecl mktemp(ಅಕ್ಷರ *_TemplateName);
  ಪೂರ್ಣಾಂಕ __cdecl open(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,...);
  ಪೂರ್ಣಾಂಕ __cdecl ಪಠ(ಪೂರ್ಣಾಂಕ _FileHandle,ಶೂನ್ಯ *_DstBuf,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Max_Char_ಎಣಿಕೆ);
  ಪೂರ್ಣಾಂಕ __cdecl setmode(ಪೂರ್ಣಾಂಕ _FileHandle,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  ಪೂರ್ಣಾಂಕ __cdecl sopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಪೂರ್ಣಾಂಕ _OpenFlag,ಪೂರ್ಣಾಂಕ _ShareFlag,...);
  ದೀರ್ಘ __cdecl tell(ಪೂರ್ಣಾಂಕ _FileHandle);
  ಪೂರ್ಣಾಂಕ __cdecl umask(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3);
  ಪೂರ್ಣಾಂಕ __cdecl ಲಿಖ(ಪೂರ್ಣಾಂಕ _Filehandle,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_Buf,ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Max_Char_ಎಣಿಕೆ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

/* Misc stuff */
ಅಕ್ಷರ *getlogin(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __USE_MINGW_ALARM
ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ alarm(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ seconds);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, while the version
    shipped with Vista, returns an error code.  This will restore the
    old behaviour  */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ __mingw_access (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *__fname, ಪೂರ್ಣಾಂಕ __mode) {
  ಹಿಂತಿರುಗಿ  _access (__fname, __mode & ~X_OK);
}

#ವ್ಯಾಖ್ಯಾನಿಸು access(__f,__m)  __mingw_access (__f, __m)
#ಆದರೆ_ಅಂತ್ಯ


#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ


#ಸೂಚನೆ pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/io_s.h>

#ಆದರೆ_ಅಂತ್ಯ /* End _IO_H_ */

