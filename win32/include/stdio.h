/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  ಸಂರಚನಾ _iobuf {
    ವರ್ಣ *_ptr;
    ಪೂರ್ಣಾಙ್ಕ _cnt;
    ವರ್ಣ *_base;
    ಪೂರ್ಣಾಙ್ಕ _flag;
    ಪೂರ್ಣಾಙ್ಕ _file;
    ಪೂರ್ಣಾಙ್ಕ _charbuf;
    ಪೂರ್ಣಾಙ್ಕ _bufsiz;
    ವರ್ಣ *_tmpfname;
  };
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#ಅನ್ಯಥಾ
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (ಪರಿಮಾಣ(_P_tmpdir) + 12)

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

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  ಪ್ರಕಾರನಿರ್ದೇಶ long _off_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  ಪ್ರಕಾರನಿರ್ದೇಶ long long _off64_t;
#ಯದಿ !defined(NO_OLDNAMES) || defined(_POSIX)
  ಪ್ರಕಾರನಿರ್ದೇಶ long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ಶೂನ್ಯ);
#ಅನ್ಯಥಾ
#ifdef _MSVCRT_
ಬಾಹ್ಯ FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#ಅನ್ಯಥಾ
ಬಾಹ್ಯ FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#ಯದಿ (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  ಪ್ರಕಾರನಿರ್ದೇಶ __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ long long fpos_t;
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

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _filbuf(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _flsbuf(ಪೂರ್ಣಾಙ್ಕ _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_Mode);
#ಅನ್ಯಥಾ
  _CRTIMP FILE *__cdecl _fsopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_Mode,ಪೂರ್ಣಾಙ್ಕ _ShFlag);
#endif
  ಶೂನ್ಯ __cdecl clearerr(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fclose(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fcloseall(ಶೂನ್ಯ);
#ifdef _POSIX_
  FILE *__cdecl fdopen(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಧ್ರುವ ವರ್ಣ *_Mode);
#ಅನ್ಯಥಾ
  _CRTIMP FILE *__cdecl _fdopen(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಧ್ರುವ ವರ್ಣ *_Mode);
#endif
  ಪೂರ್ಣಾಙ್ಕ __cdecl feof(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl ferror(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fflush(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fgetc(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fgetchar(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  ವರ್ಣ *__cdecl fgets(ವರ್ಣ *_Buf,ಪೂರ್ಣಾಙ್ಕ Max_ಎಣಿಕೆ,FILE *_File);
#ifdef _POSIX_
  ಪೂರ್ಣಾಙ್ಕ __cdecl fileno(FILE *_File);
#ಅನ್ಯಥಾ
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP ವರ್ಣ *__cdecl _tempnam(ಧ್ರುವ ವರ್ಣ *_DirName,ಧ್ರುವ ವರ್ಣ *_FilePrefix);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _flushall(ಶೂನ್ಯ);
  FILE *__cdecl fopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_Mode);
  FILE *fopen64(ಧ್ರುವ ವರ್ಣ *filename,ಧ್ರುವ ವರ್ಣ *mode);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fprintf(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fputc(ಪೂರ್ಣಾಙ್ಕ _Ch,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fputchar(ಪೂರ್ಣಾಙ್ಕ _Ch);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fputs(ಧ್ರುವ ವರ್ಣ *_Str,FILE *_File);
  size_t __cdecl fread(ಶೂನ್ಯ *_DstBuf,size_t _ElementSize,size_t ಎಣಿಕೆ_5,FILE *_File);
  FILE *__cdecl freopen(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_Mode,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fscanf(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fsetpos(FILE *_File,ಧ್ರುವ fpos_t *_Pos);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fseek(FILE *_File,long _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
   ಪೂರ್ಣಾಙ್ಕ fseeko64(FILE* stream, _off64_t offset, ಪೂರ್ಣಾಙ್ಕ whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _fseeki64(FILE *_File,__int64 _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(ಧ್ರುವ ಶೂನ್ಯ *_Str,size_t _Size,size_t ಎಣಿಕೆ_5,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl getc(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl getchar(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getmaxstdio(ಶೂನ್ಯ);
  ವರ್ಣ *__cdecl gets(ವರ್ಣ *_Buffer);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  ಶೂನ್ಯ __cdecl perror(ಧ್ರುವ ವರ್ಣ *Err_ಸಂದೇಶ);
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ಧ್ರುವ ವರ್ಣ *_Command,ಧ್ರುವ ವರ್ಣ *_Mode);
#ಯದಿ !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  ಪೂರ್ಣಾಙ್ಕ __cdecl printf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl putc(ಪೂರ್ಣಾಙ್ಕ _Ch,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl putchar(ಪೂರ್ಣಾಙ್ಕ _Ch);
  ಪೂರ್ಣಾಙ್ಕ __cdecl puts(ಧ್ರುವ ವರ್ಣ *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _putw(ಪೂರ್ಣಾಙ್ಕ _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl remove(ಧ್ರುವ ವರ್ಣ *_Filename);
  ಪೂರ್ಣಾಙ್ಕ __cdecl rename(ಧ್ರುವ ವರ್ಣ *_OldFilename,ಧ್ರುವ ವರ್ಣ *_NewFilename);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _unlink(ಧ್ರುವ ವರ್ಣ *_Filename);
#ifndef NO_OLDNAMES
  ಪೂರ್ಣಾಙ್ಕ __cdecl unlink(ಧ್ರುವ ವರ್ಣ *_Filename);
#endif
#endif
  ಶೂನ್ಯ __cdecl rewind(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _rmtmp(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl scanf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಶೂನ್ಯ __cdecl setbuf(FILE *_File,ವರ್ಣ *_Buffer);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _setmaxstdio(ಪೂರ್ಣಾಙ್ಕ _Max);
  _CRTIMP unsigned ಪೂರ್ಣಾಙ್ಕ __cdecl _set_output_format(unsigned ಪೂರ್ಣಾಙ್ಕ _Format);
  _CRTIMP unsigned ಪೂರ್ಣಾಙ್ಕ __cdecl _get_output_format(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl setvbuf(FILE *_File,ವರ್ಣ *_Buf,ಪೂರ್ಣಾಙ್ಕ _Mode,size_t _Size);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scprintf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl sscanf(ಧ್ರುವ ವರ್ಣ *_Src,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snscanf(ಧ್ರುವ ವರ್ಣ *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,...);
  FILE *__cdecl tmpfile(ಶೂನ್ಯ);
  ವರ್ಣ *__cdecl tmpnam(ವರ್ಣ *_Buffer);
  ಪೂರ್ಣಾಙ್ಕ __cdecl ungetc(ಪೂರ್ಣಾಙ್ಕ _Ch,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfprintf(FILE *_File,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vprintf(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ತಳ್ಳು_macro("vsnprintf")
#pragma ತಳ್ಳು_macro("snprintf")
# undef vsnprintf
# undef snprintf
  ಬಾಹ್ಯ
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  ಪೂರ್ಣಾಙ್ಕ __mingw_vsnprintf(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  ಬಾಹ್ಯ
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  ಪೂರ್ಣಾಙ್ಕ __mingw_snprintf(ವರ್ಣ* s, size_t n, ಧ್ರುವ ವರ್ಣ*  format, ...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vsnprintf(ವರ್ಣ *_DstBuf,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snprintf(ವರ್ಣ *_Dest,size_t ಎಣಿಕೆ_5,ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnprintf(ವರ್ಣ *_Dest,size_t ಎಣಿಕೆ_5,ಧ್ರುವ ವರ್ಣ *_Format,va_list _Args);
  ಪೂರ್ಣಾಙ್ಕ __cdecl sprintf(ವರ್ಣ *_Dest,ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vsprintf(ವರ್ಣ *_Dest,ಧ್ರುವ ವರ್ಣ *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ಪೂರ್ಣಾಙ್ಕ __cdecl snprintf(ವರ್ಣ* s, size_t n, ಧ್ರುವ ವರ್ಣ*  format, ...);
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl vsnprintf (ವರ್ಣ* s, size_t n, ಧ್ರುವ ವರ್ಣ* format,va_list arg) {
    ಪ್ರತ್ಯಾಗಮ _vsnprintf ( s, n, format, arg);
  }
  ಪೂರ್ಣಾಙ್ಕ __cdecl vscanf(ಧ್ರುವ ವರ್ಣ * Format, va_list argp);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfscanf (FILE * fp, ಧ್ರುವ ವರ್ಣ * Format,va_list argp);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vsscanf (ಧ್ರುವ ವರ್ಣ * _Str,ಧ್ರುವ ವರ್ಣ * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma ತೆಗೆ_macro("snprintf")
#pragma ತೆಗೆ_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# ಯದಿ defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscprintf(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl set_printf_ಎಣಿಕೆ_output(ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ_2);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl get_printf_ಎಣಿಕೆ_output(ಶೂನ್ಯ);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode);
#ಅನ್ಯಥಾ
  _CRTIMP FILE *__cdecl _wfsopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode,ಪೂರ್ಣಾಙ್ಕ _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ಶೂನ್ಯ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ಶೂನ್ಯ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ಪೂರ್ಣಾಙ್ಕ Size_In_ಪದಗಳು,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fputws(ಧ್ರುವ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _putws(ಧ್ರುವ wchar_t *_Str);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fwprintf(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wprintf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _scwprintf(ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfwprintf(FILE *_File,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vwprintf(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl swprintf(wchar_t*, ಧ್ರುವ wchar_t*, ...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl vswprintf(wchar_t*, ಧ್ರುವ wchar_t*,va_list);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_ಪದಗಳು,ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwprintf(wchar_t *_Dest,size_t ಎಣಿಕೆ_5,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vsnwprintf(wchar_t *_Dest,size_t ಎಣಿಕೆ_5,ಧ್ರುವ wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ಪೂರ್ಣಾಙ್ಕ __cdecl snwprintf (wchar_t* s, size_t n, ಧ್ರುವ wchar_t*  format, ...);
  __CRT_INLINE ಪೂರ್ಣಾಙ್ಕ __cdecl vsnwprintf (wchar_t* s, size_t n, ಧ್ರುವ wchar_t* format, va_list arg) { ಪ್ರತ್ಯಾಗಮ _vsnwprintf(s,n,format,arg); }
  ಪೂರ್ಣಾಙ್ಕ __cdecl vwscanf (ಧ್ರುವ wchar_t *, va_list);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vfwscanf (FILE *,ಧ್ರುವ wchar_t *,va_list);
  ಪೂರ್ಣಾಙ್ಕ __cdecl vswscanf (ಧ್ರುವ wchar_t *,ಧ್ರುವ wchar_t *,va_list);
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _swprintf(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vswprintf(wchar_t *_Dest,ಧ್ರುವ wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#ಅನ್ತರ್ಭಾವ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ಧ್ರುವ wchar_t *_Directory,ಧ್ರುವ wchar_t *_FilePrefix);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vscwprintf(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fwscanf(FILE *_File,ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl swscanf(ಧ್ರುವ wchar_t *_Src,ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _snwscanf(ಧ್ರುವ wchar_t *_Src,size_t Max_ಎಣಿಕೆ,ಧ್ರುವ wchar_t *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl wscanf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(ಪೂರ್ಣಾಙ್ಕ _FileHandle ,ಧ್ರುವ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ಶೂನ್ಯ __cdecl _wperror(ಧ್ರುವ wchar_t *Err_ಸಂದೇಶ);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ಧ್ರುವ wchar_t *_Command,ಧ್ರುವ wchar_t *_Mode);
#ಯದಿ !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wremove(ಧ್ರುವ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#ಯದಿ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#ಅನ್ಯಥಾ
  __CRT_INLINE wint_t __cdecl getwchar() { ಪ್ರತ್ಯಾಗಮ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { ಪ್ರತ್ಯಾಗಮ (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (ವರ್ಣ)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP ಶೂನ್ಯ __cdecl _lock_file(FILE *_File);
  _CRTIMP ಶೂನ್ಯ __cdecl _unlock_file(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(ಶೂನ್ಯ *_DstBuf,size_t _ElementSize,size_t ಎಣಿಕೆ_5,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fseek_nolock(FILE *_File,long _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,ಪೂರ್ಣಾಙ್ಕ _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(ಧ್ರುವ ಶೂನ್ಯ *_DstBuf,size_t _Size,size_t ಎಣಿಕೆ_5,FILE *_File);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _ungetc_nolock(ಪೂರ್ಣಾಙ್ಕ _Ch,FILE *_File);

#ಯದಿ !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  ವರ್ಣ *__cdecl tempnam(ಧ್ರುವ ವರ್ಣ *_Directory,ಧ್ರುವ ವರ್ಣ *_FilePrefix);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fcloseall(ಶೂನ್ಯ);
  FILE *__cdecl fdopen(ಪೂರ್ಣಾಙ್ಕ _FileHandle,ಧ್ರುವ ವರ್ಣ *_Format);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fgetchar(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fileno(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl flushall(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl fputchar(ಪೂರ್ಣಾಙ್ಕ _Ch);
  ಪೂರ್ಣಾಙ್ಕ __cdecl getw(FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl putw(ಪೂರ್ಣಾಙ್ಕ _Ch,FILE *_File);
  ಪೂರ್ಣಾಙ್ಕ __cdecl rmtmp(ಶೂನ್ಯ);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)

#ಅನ್ತರ್ಭಾವ <sec_api/stdio_s.h>

#endif
