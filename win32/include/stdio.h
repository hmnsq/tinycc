/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_STDIO
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_STDIO

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು BUFSIZ 512
#ವ್ಯಾಖ್ಯಾನಿಸು _NFILE _NSTREAM_
#ವ್ಯಾಖ್ಯಾನಿಸು _NSTREAM_ 512
#ವ್ಯಾಖ್ಯಾನಿಸು _IOB_ENTRIES 20
#ವ್ಯಾಖ್ಯಾನಿಸು EOF (-1)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FILE_DEFINED
  ರಚನೆ _iobuf {
    ಅಕ್ಷರ *_ptr;
    ಪೂರ್ಣಾಂಕ _cnt;
    ಅಕ್ಷರ *ತಳ_4;
    ಪೂರ್ಣಾಂಕ _flag;
    ಪೂರ್ಣಾಂಕ _file;
    ಪೂರ್ಣಾಂಕ _charbuf;
    ಪೂರ್ಣಾಂಕ _bufsiz;
    ಅಕ್ಷರ *_tmpfname;
  };
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _iobuf FILE;
#ವ್ಯಾಖ್ಯಾನಿಸು _FILE_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿಸು _P_tmpdir "/"
#ವ್ಯಾಖ್ಯಾನಿಸು _wP_tmpdir L"/"
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _P_tmpdir "\\"
#ವ್ಯಾಖ್ಯಾನಿಸು _wP_tmpdir L"\\"
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು L_tmpnam (ಗಾತ್ರ(_P_tmpdir) + 12)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿಸು L_ctermid 9
#ವ್ಯಾಖ್ಯಾನಿಸು L_cuserid 32
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SEEK_CUR 1
#ವ್ಯಾಖ್ಯಾನಿಸು SEEK_END 2
#ವ್ಯಾಖ್ಯಾನಿಸು SEEK_SET 0

#ವ್ಯಾಖ್ಯಾನಿಸು STDIN_FILENO    0
#ವ್ಯಾಖ್ಯಾನಿಸು STDOUT_FILENO   1
#ವ್ಯಾಖ್ಯಾನಿಸು STDERR_FILENO   2

#ವ್ಯಾಖ್ಯಾನಿಸು FILENAME_MAX 260
#ವ್ಯಾಖ್ಯಾನಿಸು FOPEN_MAX 20
#ವ್ಯಾಖ್ಯಾನಿಸು _SYS_OPEN 20
#ವ್ಯಾಖ್ಯಾನಿಸು TMP_MAX 32767

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಖಾಲಿ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ 0
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಲಿ ((ಶೂನ್ಯ *)0)
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
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ _off64_t;
#ಆದರೆ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ off64_t;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ಶೂನ್ಯ);
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _MSVCRT_
ಬಾಹ್ಯ FILE _iob[];     /* A pointer to an array of FILE */
#ವ್ಯಾಖ್ಯಾನಿಸು __iob_func()    (_iob)
#ಇಲ್ಲದಿದ್ದರೆ
ಬಾಹ್ಯ FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#ವ್ಯಾಖ್ಯಾನಿಸು __iob_func()    (*_imp___iob)
#ವ್ಯಾಖ್ಯಾನಿಸು _iob __iob_func()
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FPOS_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _FPOS_T_DEFINED
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _FPOSOFF

#ಆದರೆ (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 fpos_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _FPOSOFF(fp) ((ದೀರ್ಘ)(fp))
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ ದೀರ್ಘ fpos_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _FPOSOFF(fp) ((ದೀರ್ಘ)(fp))
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDSTREAM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _STDSTREAM_DEFINED

#ವ್ಯಾಖ್ಯಾನಿಸು stdin (&__iob_func()[0])
#ವ್ಯಾಖ್ಯಾನಿಸು stdout (&__iob_func()[1])
#ವ್ಯಾಖ್ಯಾನಿಸು stderr (&__iob_func()[2])
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _IOREAD 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು _IOWRT 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು _IOFBF 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು _IOLBF 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು _IONBF 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು _IOMYBUF 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು _IOEOF 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು _IOERR 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು _IOSTRG 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು _IORW 0x0080
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿಸು _IOAPPEND 0x0200
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _TWO_DIGIT_EXPONENT 0x1

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _STDIO_DEFINED

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _filbuf(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _flsbuf(ಪೂರ್ಣಾಂಕ _Ch,FILE *_File);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3);
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP FILE *__cdecl _fsopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3,ಪೂರ್ಣಾಂಕ _ShFlag);
#ಆದರೆ_ಅಂತ್ಯ
  ಶೂನ್ಯ __cdecl clearerr(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fclose(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fcloseall(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
  FILE *__cdecl fdopen(ಪೂರ್ಣಾಂಕ _FileHandle,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3);
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP FILE *__cdecl _fdopen(ಪೂರ್ಣಾಂಕ _FileHandle,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3);
#ಆದರೆ_ಅಂತ್ಯ
  ಪೂರ್ಣಾಂಕ __cdecl feof(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl ferror(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fflush(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fgetc(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fgetchar(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  ಅಕ್ಷರ *__cdecl fgets(ಅಕ್ಷರ *_Buf,ಪೂರ್ಣಾಂಕ Max_ಎಣಿಕೆ,FILE *_File);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
  ಪೂರ್ಣಾಂಕ __cdecl fileno(FILE *_File);
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fileno(FILE *_File);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಅಕ್ಷರ *__cdecl _tempnam(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_DirName,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *File_ಪೂರ್ವಪ್ರತ್ಯಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _flushall(ಶೂನ್ಯ);
  FILE *__cdecl fopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3);
  FILE *fopen64(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ);
  ಪೂರ್ಣಾಂಕ __cdecl fprintf(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl fputc(ಪೂರ್ಣಾಂಕ _Ch,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fputchar(ಪೂರ್ಣಾಂಕ _Ch);
  ಪೂರ್ಣಾಂಕ __cdecl fputs(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str,FILE *_File);
  ಗಾತ್ರ_t __cdecl fread(ಶೂನ್ಯ *_DstBuf,ಗಾತ್ರ_t Element_ಗಾತ್ರ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,FILE *_File);
  FILE *__cdecl freopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fscanf(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl fsetpos(FILE *_File,ಸ್ಥಿರಾಂಕ fpos_t *_Pos);
  ಪೂರ್ಣಾಂಕ __cdecl fseek(FILE *_File,ದೀರ್ಘ ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
   ಪೂರ್ಣಾಂಕ fseeko64(FILE* ಹರಿವು, _off64_t ಸ್ಥಾನಾಂತರ, ಪೂರ್ಣಾಂಕ whence);
  ದೀರ್ಘ __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * ಹರಿವು);
  ಪೂರ್ಣಾಂಕ __cdecl _fseeki64(FILE *_File,__int64 ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  ಗಾತ್ರ_t __cdecl fwrite(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_Str,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t ಎಣಿಕೆ_6,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl getc(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl getchar(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getmaxstdio(ಶೂನ್ಯ);
  ಅಕ್ಷರ *__cdecl gets(ಅಕ್ಷರ *ಬಫರ್_2);
  ಪೂರ್ಣಾಂಕ __cdecl _getw(FILE *_File);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_PERROR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_PERROR_DEFINED
  ಶೂನ್ಯ __cdecl perror(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *Err_ಸಂದೇಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Command,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಬಹುಲಕ_3);
#ಆದರೆ !defined(NO_OLDNAMES) && !defined(popen)
#ವ್ಯಾಖ್ಯಾನಿಸು popen   _popen
#ವ್ಯಾಖ್ಯಾನಿಸು pclose  _pclose
#ಆದರೆ_ಅಂತ್ಯ
  ಪೂರ್ಣಾಂಕ __cdecl ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl putc(ಪೂರ್ಣಾಂಕ _Ch,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl ಅಕ್ಷರ_ಬರೆ(ಪೂರ್ಣಾಂಕ _Ch);
  ಪೂರ್ಣಾಂಕ __cdecl puts(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _putw(ಪೂರ್ಣಾಂಕ ಶಬ್ದ_4,FILE *_File);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_DIRECTORY_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_DIRECTORY_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl remove(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename);
  ಪೂರ್ಣಾಂಕ __cdecl rename(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_OldFilename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_NewFilename);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _unlink(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NO_OLDNAMES
  ಪೂರ್ಣಾಂಕ __cdecl unlink(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
  ಶೂನ್ಯ __cdecl rewind(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _rmtmp(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl scanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಶೂನ್ಯ __cdecl setbuf(FILE *_File,ಅಕ್ಷರ *ಬಫರ್_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _setmaxstdio(ಪೂರ್ಣಾಂಕ _Max);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl ಗಣ_output_format(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ _Format);
  _CRTIMP ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl _get_output_format(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl setvbuf(FILE *_File,ಅಕ್ಷರ *_Buf,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಗಾತ್ರ_t ಗಾತ್ರ_5);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl ಅಕ್ಷರಸರಣಿ_ಓದು(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snscanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  FILE *__cdecl tmpfile(ಶೂನ್ಯ);
  ಅಕ್ಷರ *__cdecl tmpnam(ಅಕ್ಷರ *ಬಫರ್_2);
  ಪೂರ್ಣಾಂಕ __cdecl ungetc(ಪೂರ್ಣಾಂಕ _Ch,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl vfprintf(FILE *_File,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#ಸೂಚನೆ ತಳ್ಳು_macro("vsnprintf")
#ಸೂಚನೆ ತಳ್ಳು_macro("snprintf")
# undef vsnprintf
# undef snprintf
  ಬಾಹ್ಯ
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  ಪೂರ್ಣಾಂಕ __mingw_vsnprintf(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  ಬಾಹ್ಯ
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  ಪೂರ್ಣಾಂಕ __mingw_snprintf(ಅಕ್ಷರ* s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*  format, ...);
  ಪೂರ್ಣಾಂಕ __cdecl vsnprintf(ಅಕ್ಷರ *_DstBuf,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snprintf(ಅಕ್ಷರ *_Dest,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnprintf(ಅಕ್ಷರ *_Dest,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list ವಾದಗಳು_2);
  ಪೂರ್ಣಾಂಕ __cdecl sprintf(ಅಕ್ಷರ *_Dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl vsprintf(ಅಕ್ಷರ *_Dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list ವಾದಗಳು_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NO_ISOCEXT  /* externs in libmingwex.a */
  ಪೂರ್ಣಾಂಕ __cdecl snprintf(ಅಕ್ಷರ* s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*  format, ...);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl vsnprintf (ಅಕ್ಷರ* s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* format,va_list arg) {
    ಹಿಂತಿರುಗಿ _vsnprintf ( s, n, format, arg);
  }
  ಪೂರ್ಣಾಂಕ __cdecl vscanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * Format, va_list argp);
  ಪೂರ್ಣಾಂಕ __cdecl vfscanf (FILE * fp, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * Format,va_list argp);
  ಪೂರ್ಣಾಂಕ __cdecl vsscanf (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * _Str,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * Format,va_list argp);
#ಆದರೆ_ಅಂತ್ಯ
/* Restore may prior defined macros snprintf/vsnprintf.  */
#ಸೂಚನೆ ತೆಗೆ_macro("snprintf")
#ಸೂಚನೆ ತೆಗೆ_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# ಆದರೆ defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl ಗಣ_printf_ಎಣಿಕೆ_output(ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl get_printf_ಎಣಿಕೆ_output(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WSTDIO_DEFINED

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WEOF
#ವ್ಯಾಖ್ಯಾನಿಸು WEOF (wint_t)(0xFFFF)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
#ಇಲ್ಲದಿದ್ದರೆ
  _CRTIMP FILE *__cdecl _wfsopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3,ಪೂರ್ಣಾಂಕ _ShFlag);
#ಆದರೆ_ಅಂತ್ಯ
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ಶೂನ್ಯ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ಶೂನ್ಯ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_ಒಳ_ಪದಗಳು,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl fputws(ಸ್ಥಿರಾಂಕ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _putws(ಸ್ಥಿರಾಂಕ wchar_t *_Str);
  ಪೂರ್ಣಾಂಕ __cdecl fwprintf(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl wprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _scwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl vfwprintf(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl vwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl swprintf(wchar_t*, ಸ್ಥಿರಾಂಕ wchar_t*, ...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl vswprintf(wchar_t*, ಸ್ಥಿರಾಂಕ wchar_t*,va_list);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf_c(wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf_c(wchar_t *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_ಒಳ_ಪದಗಳು,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwprintf(wchar_t *_Dest,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vsnwprintf(wchar_t *_Dest,ಗಾತ್ರ_t ಎಣಿಕೆ_6,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list ವಾದಗಳು_2);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __NO_ISOCEXT  /* externs in libmingwex.a */
  ಪೂರ್ಣಾಂಕ __cdecl snwprintf (wchar_t* s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ wchar_t*  format, ...);
  __CRT_INLINE ಪೂರ್ಣಾಂಕ __cdecl vsnwprintf (wchar_t* s, ಗಾತ್ರ_t n, ಸ್ಥಿರಾಂಕ wchar_t* format, va_list arg) { ಹಿಂತಿರುಗಿ _vsnwprintf(s,n,format,arg); }
  ಪೂರ್ಣಾಂಕ __cdecl vwscanf (ಸ್ಥಿರಾಂಕ wchar_t *, va_list);
  ಪೂರ್ಣಾಂಕ __cdecl vfwscanf (FILE *,ಸ್ಥಿರಾಂಕ wchar_t *,va_list);
  ಪೂರ್ಣಾಂಕ __cdecl vswscanf (ಸ್ಥಿರಾಂಕ wchar_t *,ಸ್ಥಿರಾಂಕ wchar_t *,va_list);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _swprintf(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vswprintf(wchar_t *_Dest,ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list ವಾದಗಳು_2);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ಅನ್ತರ್ಭಾವ <vadefs.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _CRT_NON_CONFORMING_SWPRINTFS
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು swprintf _swprintf
#ವ್ಯಾಖ್ಯಾನಿಸು vswprintf _vswprintf
#ವ್ಯಾಖ್ಯಾನಿಸು _swprintf_l __swprintf_l
#ವ್ಯಾಖ್ಯಾನಿಸು _vswprintf_l __vswprintf_l
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP wchar_t *__cdecl _wtempnam(ಸ್ಥಿರಾಂಕ wchar_t *_Directory,ಸ್ಥಿರಾಂಕ wchar_t *File_ಪೂರ್ವಪ್ರತ್ಯಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vscwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಂಕ __cdecl fwscanf(FILE *_File,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl swscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _snwscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Src,ಗಾತ್ರ_t Max_ಎಣಿಕೆ,ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl wscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(ಪೂರ್ಣಾಂಕ _FileHandle ,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
  _CRTIMP FILE *__cdecl _wfopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
  _CRTIMP FILE *__cdecl _wfreopen(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3,FILE *_OldFile);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WPERROR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಸ್ಥಿರಾಂಕ wchar_t *Err_ಸಂದೇಶ);
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP FILE *__cdecl _wpopen(ಸ್ಥಿರಾಂಕ wchar_t *_Command,ಸ್ಥಿರಾಂಕ wchar_t *ಬಹುಲಕ_3);
#ಆದರೆ !defined(NO_OLDNAMES) && !defined(wpopen)
#ವ್ಯಾಖ್ಯಾನಿಸು wpopen  _wpopen
#ಆದರೆ_ಅಂತ್ಯ
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wremove(ಸ್ಥಿರಾಂಕ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *ಬಫರ್_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _CRT_GETPUTWCHAR_NOINLINE

#ಆದರೆ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#ವ್ಯಾಖ್ಯಾನಿಸು getwchar() fgetwc(stdin)
#ವ್ಯಾಖ್ಯಾನಿಸು putwchar(_c) fputwc((_c),stdout)
#ಇಲ್ಲದಿದ್ದರೆ
  __CRT_INLINE wint_t __cdecl getwchar() { ಹಿಂತಿರುಗಿ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { ಹಿಂತಿರುಗಿ (fputwc(_C,stdout)); }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು getwc(_stm) fgetwc(_stm)
#ವ್ಯಾಖ್ಯಾನಿಸು putwc(_c,_stm) fputwc(_c,_stm)
#ವ್ಯಾಖ್ಯಾನಿಸು _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#ವ್ಯಾಖ್ಯಾನಿಸು _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#ವ್ಯಾಖ್ಯಾನಿಸು _WSTDIO_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _STDIO_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _fgetc_nolock(ಹರಿವು_2) (--(ಹರಿವು_2)->_cnt >= 0 ? 0xff & *(ಹರಿವು_2)->_ptr++ : _filbuf(ಹರಿವು_2))
#ವ್ಯಾಖ್ಯಾನಿಸು _fputc_nolock(_c,ಹರಿವು_2) (--(ಹರಿವು_2)->_cnt >= 0 ? 0xff & (*(ಹರಿವು_2)->_ptr++ = (ಅಕ್ಷರ)(_c)) : _flsbuf((_c),(ಹರಿವು_2)))
#ವ್ಯಾಖ್ಯಾನಿಸು _getc_nolock(ಹರಿವು_2) _fgetc_nolock(ಹರಿವು_2)
#ವ್ಯಾಖ್ಯಾನಿಸು _putc_nolock(_c,ಹರಿವು_2) _fputc_nolock(_c,ಹರಿವು_2)
#ವ್ಯಾಖ್ಯಾನಿಸು _getchar_nolock() _getc_nolock(stdin)
#ವ್ಯಾಖ್ಯಾನಿಸು _putchar_nolock(_c) _putc_nolock((_c),stdout)
#ವ್ಯಾಖ್ಯಾನಿಸು _getwchar_nolock() _getwc_nolock(stdin)
#ವ್ಯಾಖ್ಯಾನಿಸು _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP ಶೂನ್ಯ __cdecl ಬೀಗ_file(FILE *_File);
  _CRTIMP ಶೂನ್ಯ __cdecl _unlock_file(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP ಗಾತ್ರ_t __cdecl _fread_nolock(ಶೂನ್ಯ *_DstBuf,ಗಾತ್ರ_t Element_ಗಾತ್ರ,ಗಾತ್ರ_t ಎಣಿಕೆ_6,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fseek_nolock(FILE *_File,ದೀರ್ಘ ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
  _CRTIMP ದೀರ್ಘ __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _fseeki64_nolock(FILE *_File,__int64 ಸ್ಥಾನಾಂತರ_2,ಪೂರ್ಣಾಂಕ _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP ಗಾತ್ರ_t __cdecl _fwrite_nolock(ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *_DstBuf,ಗಾತ್ರ_t ಗಾತ್ರ_5,ಗಾತ್ರ_t ಎಣಿಕೆ_6,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _ungetc_nolock(ಪೂರ್ಣಾಂಕ _Ch,FILE *_File);

#ಆದರೆ !defined(NO_OLDNAMES) || !defined(_POSIX)
#ವ್ಯಾಖ್ಯಾನಿಸು P_tmpdir _P_tmpdir
#ವ್ಯಾಖ್ಯಾನಿಸು SYS_OPEN _SYS_OPEN

  ಅಕ್ಷರ *__cdecl tempnam(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Directory,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *File_ಪೂರ್ವಪ್ರತ್ಯಯ);
  ಪೂರ್ಣಾಂಕ __cdecl fcloseall(ಶೂನ್ಯ);
  FILE *__cdecl fdopen(ಪೂರ್ಣಾಂಕ _FileHandle,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format);
  ಪೂರ್ಣಾಂಕ __cdecl fgetchar(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl fileno(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl flushall(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl fputchar(ಪೂರ್ಣಾಂಕ _Ch);
  ಪೂರ್ಣಾಂಕ __cdecl getw(FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl putw(ಪೂರ್ಣಾಂಕ _Ch,FILE *_File);
  ಪೂರ್ಣಾಂಕ __cdecl rmtmp(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/stdio_s.h>

#ಆದರೆ_ಅಂತ್ಯ
