/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  ସଂରଚନା _iobuf {
    ଅକ୍ଷର *_ptr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _cnt;
    ଅକ୍ଷର *_base;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _flag;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _file;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _charbuf;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _bufsiz;
    ଅକ୍ଷର *_tmpfname;
  };
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#ଅନ୍ୟଥା
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (ଆକାର(_P_tmpdir) + 12)

#ifdef _POSIX_
#define L_ctermid 9
#define L_cuserid 32
#endif

#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

#define FILENAME_MAX 260
#define FOPEN_MAX 20
#define _SYS_OPEN 20
#define TMP_MAX 32767

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long _off_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long _off64_t;
#ଯଦି !defined(NO_OLDNAMES) || defined(_POSIX)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ଶୂନ୍ୟ);
#ଅନ୍ୟଥା
#ifdef _MSVCRT_
ବାହ୍ୟ FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#ଅନ୍ୟଥା
ବାହ୍ୟ FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#ଯଦି (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  ପ୍ରକାରବ୍ୟାଖ୍ୟା __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long long fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#endif

#endif

#ifndef _STDSTREAM_DEFINED
#define _STDSTREAM_DEFINED

#define stdin (&__iob_func()[0])
#define stdout (&__iob_func()[1])
#define stderr (&__iob_func()[2])
#endif

#define _IOREAD 0x0001
#define _IOWRT 0x0002

#define _IOFBF 0x0000
#define _IOLBF 0x0040
#define _IONBF 0x0004

#define _IOMYBUF 0x0008
#define _IOEOF 0x0010
#define _IOERR 0x0020
#define _IOSTRG 0x0040
#define _IORW 0x0080
#ifdef _POSIX_
#define _IOAPPEND 0x0200
#endif

#define _TWO_DIGIT_EXPONENT 0x1

#ifndef _STDIO_DEFINED

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _filbuf(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _flsbuf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_Mode);
#ଅନ୍ୟଥା
  _CRTIMP FILE *__cdecl _fsopen(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_Mode,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShFlag);
#endif
  ଶୂନ୍ୟ __cdecl clearerr(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fclose(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fcloseall(ଶୂନ୍ୟ);
#ifdef _POSIX_
  FILE *__cdecl fdopen(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ଅଚଳ ଅକ୍ଷର *_Mode);
#ଅନ୍ୟଥା
  _CRTIMP FILE *__cdecl _fdopen(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ଅଚଳ ଅକ୍ଷର *_Mode);
#endif
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl feof(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ferror(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fflush(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fgetc(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fgetchar(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  ଅକ୍ଷର *__cdecl fgets(ଅକ୍ଷର *_Buf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Max_ଗଣନା,FILE *_File);
#ifdef _POSIX_
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fileno(FILE *_File);
#ଅନ୍ୟଥା
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP ଅକ୍ଷର *__cdecl _tempnam(ଅଚଳ ଅକ୍ଷର *_DirName,ଅଚଳ ଅକ୍ଷର *_FilePrefix);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _flushall(ଶୂନ୍ୟ);
  FILE *__cdecl fopen(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_Mode);
  FILE *fopen64(ଅଚଳ ଅକ୍ଷର *filename,ଅଚଳ ଅକ୍ଷର *mode);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fprintf(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fputc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fputchar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fputs(ଅଚଳ ଅକ୍ଷର *_Str,FILE *_File);
  size_t __cdecl fread(ଶୂନ୍ୟ *_DstBuf,size_t _ElementSize,size_t ଗଣନା_6,FILE *_File);
  FILE *__cdecl freopen(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_Mode,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fscanf(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fsetpos(FILE *_File,ଅଚଳ fpos_t *_Pos);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fseek(FILE *_File,long _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
   ପୂର୍ଣ୍ଣସଂଖ୍ୟା fseeko64(FILE* stream, _off64_t offset, ପୂର୍ଣ୍ଣସଂଖ୍ୟା whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fseeki64(FILE *_File,__int64 _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(ଅଚଳ ଶୂନ୍ୟ *_Str,size_t _Size,size_t ଗଣନା_6,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl getc(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl getchar(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getmaxstdio(ଶୂନ୍ୟ);
  ଅକ୍ଷର *__cdecl gets(ଅକ୍ଷର *_Buffer);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  ଶୂନ୍ୟ __cdecl perror(ଅଚଳ ଅକ୍ଷର *Err_ସନ୍ଦେଶ);
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ଅଚଳ ଅକ୍ଷର *_Command,ଅଚଳ ଅକ୍ଷର *_Mode);
#ଯଦି !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl printf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl putc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl putchar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl puts(ଅଚଳ ଅକ୍ଷର *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _putw(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl remove(ଅଚଳ ଅକ୍ଷର *_Filename);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl rename(ଅଚଳ ଅକ୍ଷର *_OldFilename,ଅଚଳ ଅକ୍ଷର *_NewFilename);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _unlink(ଅଚଳ ଅକ୍ଷର *_Filename);
#ifndef NO_OLDNAMES
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl unlink(ଅଚଳ ଅକ୍ଷର *_Filename);
#endif
#endif
  ଶୂନ୍ୟ __cdecl rewind(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _rmtmp(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl scanf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  ଶୂନ୍ୟ __cdecl setbuf(FILE *_File,ଅକ୍ଷର *_Buffer);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _setmaxstdio(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Max);
  _CRTIMP unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _set_output_format(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Format);
  _CRTIMP unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _get_output_format(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl setvbuf(FILE *_File,ଅକ୍ଷର *_Buf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,size_t _Size);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scprintf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl sscanf(ଅଚଳ ଅକ୍ଷର *_Src,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snscanf(ଅଚଳ ଅକ୍ଷର *_Src,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,...);
  FILE *__cdecl tmpfile(ଶୂନ୍ୟ);
  ଅକ୍ଷର *__cdecl tmpnam(ଅକ୍ଷର *_Buffer);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ungetc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfprintf(FILE *_File,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vprintf(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ଠେଲ_macro("vsnprintf")
#pragma ଠେଲ_macro("snprintf")
# undef vsnprintf
# undef snprintf
  ବାହ୍ୟ
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mingw_vsnprintf(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  ବାହ୍ୟ
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __mingw_snprintf(ଅକ୍ଷର* s, size_t n, ଅଚଳ ଅକ୍ଷର*  format, ...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsnprintf(ଅକ୍ଷର *_DstBuf,size_t Max_ଗଣନା,ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snprintf(ଅକ୍ଷର *_Dest,size_t ଗଣନା_6,ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnprintf(ଅକ୍ଷର *_Dest,size_t ଗଣନା_6,ଅଚଳ ଅକ୍ଷର *_Format,va_list _Args);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl sprintf(ଅକ୍ଷର *_Dest,ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsprintf(ଅକ୍ଷର *_Dest,ଅଚଳ ଅକ୍ଷର *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl snprintf(ଅକ୍ଷର* s, size_t n, ଅଚଳ ଅକ୍ଷର*  format, ...);
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsnprintf (ଅକ୍ଷର* s, size_t n, ଅଚଳ ଅକ୍ଷର* format,va_list arg) {
    ଫେରନ୍ତୁ _vsnprintf ( s, n, format, arg);
  }
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vscanf(ଅଚଳ ଅକ୍ଷର * Format, va_list argp);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfscanf (FILE * fp, ଅଚଳ ଅକ୍ଷର * Format,va_list argp);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsscanf (ଅଚଳ ଅକ୍ଷର * _Str,ଅଚଳ ଅକ୍ଷର * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma କାଢ଼_macro("snprintf")
#pragma କାଢ଼_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# ଯଦି defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscprintf(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl set_printf_ଗଣନା_output(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl get_printf_ଗଣନା_output(ଶୂନ୍ୟ);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode);
#ଅନ୍ୟଥା
  _CRTIMP FILE *__cdecl _wfsopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ଶୂନ୍ୟ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ଶୂନ୍ୟ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ପୂର୍ଣ୍ଣସଂଖ୍ୟା Size_In_ଶବ୍ଦଗୁଡ଼ିକ,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fputws(ଅଚଳ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _putws(ଅଚଳ wchar_t *_Str);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fwprintf(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wprintf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _scwprintf(ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfwprintf(FILE *_File,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vwprintf(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl swprintf(wchar_t*, ଅଚଳ wchar_t*, ...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vswprintf(wchar_t*, ଅଚଳ wchar_t*,va_list);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_ଶବ୍ଦଗୁଡ଼ିକ,ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwprintf(wchar_t *_Dest,size_t ଗଣନା_6,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vsnwprintf(wchar_t *_Dest,size_t ଗଣନା_6,ଅଚଳ wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl snwprintf (wchar_t* s, size_t n, ଅଚଳ wchar_t*  format, ...);
  __CRT_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vsnwprintf (wchar_t* s, size_t n, ଅଚଳ wchar_t* format, va_list arg) { ଫେରନ୍ତୁ _vsnwprintf(s,n,format,arg); }
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vwscanf (ଅଚଳ wchar_t *, va_list);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vfwscanf (FILE *,ଅଚଳ wchar_t *,va_list);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl vswscanf (ଅଚଳ wchar_t *,ଅଚଳ wchar_t *,va_list);
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _swprintf(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vswprintf(wchar_t *_Dest,ଅଚଳ wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#ଅନ୍ତର୍ଭାଵ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ଅଚଳ wchar_t *_Directory,ଅଚଳ wchar_t *_FilePrefix);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vscwprintf(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fwscanf(FILE *_File,ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl swscanf(ଅଚଳ wchar_t *_Src,ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _snwscanf(ଅଚଳ wchar_t *_Src,size_t Max_ଗଣନା,ଅଚଳ wchar_t *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl wscanf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle ,ଅଚଳ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ଶୂନ୍ୟ __cdecl _wperror(ଅଚଳ wchar_t *Err_ସନ୍ଦେଶ);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ଅଚଳ wchar_t *_Command,ଅଚଳ wchar_t *_Mode);
#ଯଦି !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wremove(ଅଚଳ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#ଯଦି !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#ଅନ୍ୟଥା
  __CRT_INLINE wint_t __cdecl getwchar() { ଫେରନ୍ତୁ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { ଫେରନ୍ତୁ (fputwc(_C,stdout)); }
#endif

#define getwc(_stm) fgetwc(_stm)
#define putwc(_c,_stm) fputwc(_c,_stm)
#define _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#define _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#define _WSTDIO_DEFINED
#endif

#define _STDIO_DEFINED
#endif

#define _fgetc_nolock(_stream) (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (ଅକ୍ଷର)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP ଶୂନ୍ୟ __cdecl _lock_file(FILE *_File);
  _CRTIMP ଶୂନ୍ୟ __cdecl _unlock_file(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(ଶୂନ୍ୟ *_DstBuf,size_t _ElementSize,size_t ଗଣନା_6,FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fseek_nolock(FILE *_File,long _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(ଅଚଳ ଶୂନ୍ୟ *_DstBuf,size_t _Size,size_t ଗଣନା_6,FILE *_File);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _ungetc_nolock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,FILE *_File);

#ଯଦି !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  ଅକ୍ଷର *__cdecl tempnam(ଅଚଳ ଅକ୍ଷର *_Directory,ଅଚଳ ଅକ୍ଷର *_FilePrefix);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fcloseall(ଶୂନ୍ୟ);
  FILE *__cdecl fdopen(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _FileHandle,ଅଚଳ ଅକ୍ଷର *_Format);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fgetchar(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fileno(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl flushall(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl fputchar(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl getw(FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl putw(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch,FILE *_File);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl rmtmp(ଶୂନ୍ୟ);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)

#ଅନ୍ତର୍ଭାଵ <sec_api/stdio_s.h>

#endif
