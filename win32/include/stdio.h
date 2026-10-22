/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_STDIO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_STDIO

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BUFSIZ 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _NFILE _NSTREAM_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _NSTREAM_ 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOB_ENTRIES 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EOF (-1)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FILE_DEFINED
  ਬਣਤਰ _iobuf {
    ਅੱਖਰ *_ptr;
    ਪੂਰਨ _cnt;
    ਅੱਖਰ *ਅਧਾਰ_4;
    ਪੂਰਨ _flag;
    ਪੂਰਨ _file;
    ਪੂਰਨ _charbuf;
    ਪੂਰਨ _bufsiz;
    ਅੱਖਰ *_tmpfname;
  };
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _iobuf FILE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FILE_DEFINED
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_tmpdir "/"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wP_tmpdir L"/"
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_tmpdir "\\"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _wP_tmpdir L"\\"
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ L_tmpnam (ਆਕਾਰ(_P_tmpdir) + 12)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ L_ctermid 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ L_cuserid 32
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEEK_CUR 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEEK_END 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEEK_SET 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDIN_FILENO    0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDOUT_FILENO   1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDERR_FILENO   2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILENAME_MAX 260
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOPEN_MAX 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SYS_OPEN 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TMP_MAX 32767

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਨਿਰਾ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ 0
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਰਾ ((ਖਾਲੀ *)0)
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
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ _off64_t;
#ਜੇ !defined(NO_OLDNAMES) || defined(_POSIX)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ off64_t;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDIO_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ਖਾਲੀ);
#ਨਹੀਂਤਾਂ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _MSVCRT_
ਬਾਹਰੀ FILE _iob[];     /* A pointer to an array of FILE */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __iob_func()    (_iob)
#ਨਹੀਂਤਾਂ
ਬਾਹਰੀ FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __iob_func()    (*_imp___iob)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _iob __iob_func()
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FPOS_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FPOS_T_DEFINED
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _FPOSOFF

#ਜੇ (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_ਬਿੱਟ >= 64
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 fpos_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FPOSOFF(fp) ((ਲੰਮਾ)(fp))
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ ਲੰਮਾ fpos_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FPOSOFF(fp) ((ਲੰਮਾ)(fp))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDSTREAM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDSTREAM_DEFINED

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stdin (&__iob_func()[0])
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stdout (&__iob_func()[1])
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stderr (&__iob_func()[2])
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOREAD 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOWRT 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOFBF 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOLBF 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IONBF 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOMYBUF 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOEOF 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOERR 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOSTRG 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IORW 0x0080
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOAPPEND 0x0200
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TWO_DIGIT_EXPONENT 0x1

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _STDIO_DEFINED

  _CRTIMP ਪੂਰਨ __cdecl _filbuf(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _flsbuf(ਪੂਰਨ _Ch,FILE *_File);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3);
#ਨਹੀਂਤਾਂ
  _CRTIMP FILE *__cdecl _fsopen(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3,ਪੂਰਨ _ShFlag);
#ਜੇ_ਅੰਤ
  ਖਾਲੀ __cdecl clearerr(FILE *_File);
  ਪੂਰਨ __cdecl fclose(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fcloseall(ਖਾਲੀ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
  FILE *__cdecl fdopen(ਪੂਰਨ _FileHandle,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3);
#ਨਹੀਂਤਾਂ
  _CRTIMP FILE *__cdecl _fdopen(ਪੂਰਨ _FileHandle,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3);
#ਜੇ_ਅੰਤ
  ਪੂਰਨ __cdecl feof(FILE *_File);
  ਪੂਰਨ __cdecl ferror(FILE *_File);
  ਪੂਰਨ __cdecl fflush(FILE *_File);
  ਪੂਰਨ __cdecl fgetc(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fgetchar(ਖਾਲੀ);
  ਪੂਰਨ __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  ਅੱਖਰ *__cdecl fgets(ਅੱਖਰ *_Buf,ਪੂਰਨ Max_ਗਿਣਤੀ,FILE *_File);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
  ਪੂਰਨ __cdecl fileno(FILE *_File);
#ਨਹੀਂਤਾਂ
  _CRTIMP ਪੂਰਨ __cdecl _fileno(FILE *_File);
#ਜੇ_ਅੰਤ
  _CRTIMP ਅੱਖਰ *__cdecl _tempnam(ਅਚਲ ਅੱਖਰ *_DirName,ਅਚਲ ਅੱਖਰ *File_ਅਗੇਤਰ);
  _CRTIMP ਪੂਰਨ __cdecl _flushall(ਖਾਲੀ);
  FILE *__cdecl fopen(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3);
  FILE *fopen64(ਅਚਲ ਅੱਖਰ *filename,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ);
  ਪੂਰਨ __cdecl fprintf(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl fputc(ਪੂਰਨ _Ch,FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fputchar(ਪੂਰਨ _Ch);
  ਪੂਰਨ __cdecl fputs(ਅਚਲ ਅੱਖਰ *_Str,FILE *_File);
  ਮਾਪ_t __cdecl fread(ਖਾਲੀ *_DstBuf,ਮਾਪ_t Element_ਮਾਪ,ਮਾਪ_t ਗਿਣਤੀ_6,FILE *_File);
  FILE *__cdecl freopen(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3,FILE *_File);
  ਪੂਰਨ __cdecl fscanf(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl fsetpos(FILE *_File,ਅਚਲ fpos_t *_Pos);
  ਪੂਰਨ __cdecl fseek(FILE *_File,ਲੰਮਾ ਵਿੱਥ_2,ਪੂਰਨ _Origin);
   ਪੂਰਨ fseeko64(FILE* ਧਾਰਾ, _off64_t ਵਿੱਥ, ਪੂਰਨ whence);
  ਲੰਮਾ __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * ਧਾਰਾ);
  ਪੂਰਨ __cdecl _fseeki64(FILE *_File,__int64 ਵਿੱਥ_2,ਪੂਰਨ _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  ਮਾਪ_t __cdecl fwrite(ਅਚਲ ਖਾਲੀ *_Str,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t ਗਿਣਤੀ_6,FILE *_File);
  ਪੂਰਨ __cdecl getc(FILE *_File);
  ਪੂਰਨ __cdecl getchar(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _getmaxstdio(ਖਾਲੀ);
  ਅੱਖਰ *__cdecl gets(ਅੱਖਰ *ਬਫਰ_2);
  ਪੂਰਨ __cdecl _getw(FILE *_File);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_PERROR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_PERROR_DEFINED
  ਖਾਲੀ __cdecl perror(ਅਚਲ ਅੱਖਰ *Err_ਸੁਨੇਹਾ);
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ਅਚਲ ਅੱਖਰ *_Command,ਅਚਲ ਅੱਖਰ *ਬਹੁਲਕ_3);
#ਜੇ !defined(NO_OLDNAMES) && !defined(popen)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ popen   _popen
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pclose  _pclose
#ਜੇ_ਅੰਤ
  ਪੂਰਨ __cdecl ਲਿਖੋ(ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl putc(ਪੂਰਨ _Ch,FILE *_File);
  ਪੂਰਨ __cdecl ਅੱਖਰ_ਲਿਖੋ(ਪੂਰਨ _Ch);
  ਪੂਰਨ __cdecl puts(ਅਚਲ ਅੱਖਰ *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _putw(ਪੂਰਨ ਸ਼ਬਦ_4,FILE *_File);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_DIRECTORY_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_DIRECTORY_DEFINED
  ਪੂਰਨ __cdecl remove(ਅਚਲ ਅੱਖਰ *_Filename);
  ਪੂਰਨ __cdecl rename(ਅਚਲ ਅੱਖਰ *_OldFilename,ਅਚਲ ਅੱਖਰ *_NewFilename);
  _CRTIMP ਪੂਰਨ __cdecl _unlink(ਅਚਲ ਅੱਖਰ *_Filename);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NO_OLDNAMES
  ਪੂਰਨ __cdecl unlink(ਅਚਲ ਅੱਖਰ *_Filename);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
  ਖਾਲੀ __cdecl rewind(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _rmtmp(ਖਾਲੀ);
  ਪੂਰਨ __cdecl scanf(ਅਚਲ ਅੱਖਰ *_Format,...);
  ਖਾਲੀ __cdecl setbuf(FILE *_File,ਅੱਖਰ *ਬਫਰ_2);
  _CRTIMP ਪੂਰਨ __cdecl _setmaxstdio(ਪੂਰਨ _Max);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl ਸੈੱਟ_output_format(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ _Format);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl _get_output_format(ਖਾਲੀ);
  ਪੂਰਨ __cdecl setvbuf(FILE *_File,ਅੱਖਰ *_Buf,ਪੂਰਨ ਬਹੁਲਕ_3,ਮਾਪ_t ਮਾਪ_4);
  _CRTIMP ਪੂਰਨ __cdecl _scprintf(ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ(ਅਚਲ ਅੱਖਰ *_Src,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _snscanf(ਅਚਲ ਅੱਖਰ *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,...);
  FILE *__cdecl tmpfile(ਖਾਲੀ);
  ਅੱਖਰ *__cdecl tmpnam(ਅੱਖਰ *ਬਫਰ_2);
  ਪੂਰਨ __cdecl ungetc(ਪੂਰਨ _Ch,FILE *_File);
  ਪੂਰਨ __cdecl vfprintf(FILE *_File,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vprintf(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#ਹਦਾਇਤ ਧੱਕੋ_macro("vsnprintf")
#ਹਦਾਇਤ ਧੱਕੋ_macro("snprintf")
# undef vsnprintf
# undef snprintf
  ਬਾਹਰੀ
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  ਪੂਰਨ __mingw_vsnprintf(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  ਬਾਹਰੀ
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  ਪੂਰਨ __mingw_snprintf(ਅੱਖਰ* s, ਮਾਪ_t n, ਅਚਲ ਅੱਖਰ*  format, ...);
  ਪੂਰਨ __cdecl vsnprintf(ਅੱਖਰ *_DstBuf,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snprintf(ਅੱਖਰ *_Dest,ਮਾਪ_t ਗਿਣਤੀ_6,ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnprintf(ਅੱਖਰ *_Dest,ਮਾਪ_t ਗਿਣਤੀ_6,ਅਚਲ ਅੱਖਰ *_Format,va_list ਦਲੀਲਾਂ_2);
  ਪੂਰਨ __cdecl sprintf(ਅੱਖਰ *_Dest,ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl vsprintf(ਅੱਖਰ *_Dest,ਅਚਲ ਅੱਖਰ *_Format,va_list ਦਲੀਲਾਂ_2);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NO_ISOCEXT  /* externs in libmingwex.a */
  ਪੂਰਨ __cdecl snprintf(ਅੱਖਰ* s, ਮਾਪ_t n, ਅਚਲ ਅੱਖਰ*  format, ...);
  __CRT_INLINE ਪੂਰਨ __cdecl vsnprintf (ਅੱਖਰ* s, ਮਾਪ_t n, ਅਚਲ ਅੱਖਰ* format,va_list arg) {
    ਵਾਪਸ _vsnprintf ( s, n, format, arg);
  }
  ਪੂਰਨ __cdecl vscanf(ਅਚਲ ਅੱਖਰ * Format, va_list argp);
  ਪੂਰਨ __cdecl vfscanf (FILE * fp, ਅਚਲ ਅੱਖਰ * Format,va_list argp);
  ਪੂਰਨ __cdecl vsscanf (ਅਚਲ ਅੱਖਰ * _Str,ਅਚਲ ਅੱਖਰ * Format,va_list argp);
#ਜੇ_ਅੰਤ
/* Restore may prior defined macros snprintf/vsnprintf.  */
#ਹਦਾਇਤ ਕੱਢੋ_macro("snprintf")
#ਹਦਾਇਤ ਕੱਢੋ_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# ਜੇ defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP ਪੂਰਨ __cdecl _vscprintf(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl ਸੈੱਟ_printf_ਗਿਣਤੀ_output(ਪੂਰਨ ਮੁੱਲ_2);
  _CRTIMP ਪੂਰਨ __cdecl get_printf_ਗਿਣਤੀ_output(ਖਾਲੀ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WSTDIO_DEFINED

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WEOF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WEOF (wint_t)(0xFFFF)
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
#ਨਹੀਂਤਾਂ
  _CRTIMP FILE *__cdecl _wfsopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3,ਪੂਰਨ _ShFlag);
#ਜੇ_ਅੰਤ
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ਖਾਲੀ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ਖਾਲੀ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,FILE *_File);
  ਪੂਰਨ __cdecl fputws(ਅਚਲ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ਪੂਰਨ __cdecl _putws(ਅਚਲ wchar_t *_Str);
  ਪੂਰਨ __cdecl fwprintf(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl wprintf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _scwprintf(ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl vfwprintf(FILE *_File,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl vwprintf(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl swprintf(wchar_t*, ਅਚਲ wchar_t*, ...);
  _CRTIMP ਪੂਰਨ __cdecl vswprintf(wchar_t*, ਅਚਲ wchar_t*,va_list);
  _CRTIMP ਪੂਰਨ __cdecl _swprintf_c(wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf_c(wchar_t *_DstBuf,ਮਾਪ_t ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ,ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _snwprintf(wchar_t *_Dest,ਮਾਪ_t ਗਿਣਤੀ_6,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vsnwprintf(wchar_t *_Dest,ਮਾਪ_t ਗਿਣਤੀ_6,ਅਚਲ wchar_t *_Format,va_list ਦਲੀਲਾਂ_2);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __NO_ISOCEXT  /* externs in libmingwex.a */
  ਪੂਰਨ __cdecl snwprintf (wchar_t* s, ਮਾਪ_t n, ਅਚਲ wchar_t*  format, ...);
  __CRT_INLINE ਪੂਰਨ __cdecl vsnwprintf (wchar_t* s, ਮਾਪ_t n, ਅਚਲ wchar_t* format, va_list arg) { ਵਾਪਸ _vsnwprintf(s,n,format,arg); }
  ਪੂਰਨ __cdecl vwscanf (ਅਚਲ wchar_t *, va_list);
  ਪੂਰਨ __cdecl vfwscanf (FILE *,ਅਚਲ wchar_t *,va_list);
  ਪੂਰਨ __cdecl vswscanf (ਅਚਲ wchar_t *,ਅਚਲ wchar_t *,va_list);
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _swprintf(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vswprintf(wchar_t *_Dest,ਅਚਲ wchar_t *_Format,va_list ਦਲੀਲਾਂ_2);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਅਨ੍ਤਰ੍ਭਾਵ <vadefs.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _CRT_NON_CONFORMING_SWPRINTFS
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ swprintf _swprintf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ vswprintf _vswprintf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _swprintf_l __swprintf_l
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _vswprintf_l __vswprintf_l
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  _CRTIMP wchar_t *__cdecl _wtempnam(ਅਚਲ wchar_t *_Directory,ਅਚਲ wchar_t *File_ਅਗੇਤਰ);
  _CRTIMP ਪੂਰਨ __cdecl _vscwprintf(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  ਪੂਰਨ __cdecl fwscanf(FILE *_File,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl swscanf(ਅਚਲ wchar_t *_Src,ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _snwscanf(ਅਚਲ wchar_t *_Src,ਮਾਪ_t Max_ਗਿਣਤੀ,ਅਚਲ wchar_t *_Format,...);
  ਪੂਰਨ __cdecl wscanf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(ਪੂਰਨ _FileHandle ,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
  _CRTIMP FILE *__cdecl _wfopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
  _CRTIMP FILE *__cdecl _wfreopen(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਬਹੁਲਕ_3,FILE *_OldFile);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WPERROR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WPERROR_DEFINED
  _CRTIMP ਖਾਲੀ __cdecl _wperror(ਅਚਲ wchar_t *Err_ਸੁਨੇਹਾ);
#ਜੇ_ਅੰਤ
  _CRTIMP FILE *__cdecl _wpopen(ਅਚਲ wchar_t *_Command,ਅਚਲ wchar_t *ਬਹੁਲਕ_3);
#ਜੇ !defined(NO_OLDNAMES) && !defined(wpopen)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wpopen  _wpopen
#ਜੇ_ਅੰਤ
  _CRTIMP ਪੂਰਨ __cdecl _wremove(ਅਚਲ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *ਬਫਰ_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _CRT_GETPUTWCHAR_NOINLINE

#ਜੇ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ getwchar() fgetwc(stdin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ putwchar(_c) fputwc((_c),stdout)
#ਨਹੀਂਤਾਂ
  __CRT_INLINE wint_t __cdecl getwchar() { ਵਾਪਸ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { ਵਾਪਸ (fputwc(_C,stdout)); }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ getwc(_stm) fgetwc(_stm)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ putwc(_c,_stm) fputwc(_c,_stm)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSTDIO_DEFINED
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STDIO_DEFINED
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fgetc_nolock(ਧਾਰਾ_2) (--(ਧਾਰਾ_2)->_cnt >= 0 ? 0xff & *(ਧਾਰਾ_2)->_ptr++ : _filbuf(ਧਾਰਾ_2))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _fputc_nolock(_c,ਧਾਰਾ_2) (--(ਧਾਰਾ_2)->_cnt >= 0 ? 0xff & (*(ਧਾਰਾ_2)->_ptr++ = (ਅੱਖਰ)(_c)) : _flsbuf((_c),(ਧਾਰਾ_2)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _getc_nolock(ਧਾਰਾ_2) _fgetc_nolock(ਧਾਰਾ_2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _putc_nolock(_c,ਧਾਰਾ_2) _fputc_nolock(_c,ਧਾਰਾ_2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _getchar_nolock() _getc_nolock(stdin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _putchar_nolock(_c) _putc_nolock((_c),stdout)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _getwchar_nolock() _getwc_nolock(stdin)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP ਖਾਲੀ __cdecl ਤਾਲਾ_file(FILE *_File);
  _CRTIMP ਖਾਲੀ __cdecl _unlock_file(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP ਮਾਪ_t __cdecl _fread_nolock(ਖਾਲੀ *_DstBuf,ਮਾਪ_t Element_ਮਾਪ,ਮਾਪ_t ਗਿਣਤੀ_6,FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fseek_nolock(FILE *_File,ਲੰਮਾ ਵਿੱਥ_2,ਪੂਰਨ _Origin);
  _CRTIMP ਲੰਮਾ __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _fseeki64_nolock(FILE *_File,__int64 ਵਿੱਥ_2,ਪੂਰਨ _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP ਮਾਪ_t __cdecl _fwrite_nolock(ਅਚਲ ਖਾਲੀ *_DstBuf,ਮਾਪ_t ਮਾਪ_4,ਮਾਪ_t ਗਿਣਤੀ_6,FILE *_File);
  _CRTIMP ਪੂਰਨ __cdecl _ungetc_nolock(ਪੂਰਨ _Ch,FILE *_File);

#ਜੇ !defined(NO_OLDNAMES) || !defined(_POSIX)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P_tmpdir _P_tmpdir
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYS_OPEN _SYS_OPEN

  ਅੱਖਰ *__cdecl tempnam(ਅਚਲ ਅੱਖਰ *_Directory,ਅਚਲ ਅੱਖਰ *File_ਅਗੇਤਰ);
  ਪੂਰਨ __cdecl fcloseall(ਖਾਲੀ);
  FILE *__cdecl fdopen(ਪੂਰਨ _FileHandle,ਅਚਲ ਅੱਖਰ *_Format);
  ਪੂਰਨ __cdecl fgetchar(ਖਾਲੀ);
  ਪੂਰਨ __cdecl fileno(FILE *_File);
  ਪੂਰਨ __cdecl flushall(ਖਾਲੀ);
  ਪੂਰਨ __cdecl fputchar(ਪੂਰਨ _Ch);
  ਪੂਰਨ __cdecl getw(FILE *_File);
  ਪੂਰਨ __cdecl putw(ਪੂਰਨ _Ch,FILE *_File);
  ਪੂਰਨ __cdecl rmtmp(ਖਾਲੀ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/stdio_s.h>

#ਜੇ_ਅੰਤ
