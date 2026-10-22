/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#شامل <_mingw.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  ساختار _iobuf {
    نویسه *_ptr;
    صحیح _cnt;
    نویسه *_base;
    صحیح _flag;
    صحیح _file;
    صحیح _charbuf;
    صحیح _bufsiz;
    نویسه *_tmpfname;
  };
  تعریفنوع ساختار _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#وگرنه
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (اندازه(_P_tmpdir) + 12)

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

#ifndef پوچ
#ifdef __cplusplus
#define پوچ 0
#وگرنه
#define پوچ ((تهی *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  تعریفنوع long _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  تعریفنوع long long _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  تعریفنوع long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(تهی);
#وگرنه
#ifdef _MSVCRT_
بیرونی FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#وگرنه
بیرونی FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#اگر (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  تعریفنوع __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#وگرنه
  تعریفنوع long long fpos_t;
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

  _CRTIMP صحیح __cdecl _filbuf(FILE *_File);
  _CRTIMP صحیح __cdecl _flsbuf(صحیح _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ثابت نویسه *_Filename,ثابت نویسه *_Mode);
#وگرنه
  _CRTIMP FILE *__cdecl _fsopen(ثابت نویسه *_Filename,ثابت نویسه *_Mode,صحیح _ShFlag);
#endif
  تهی __cdecl clearerr(FILE *_File);
  صحیح __cdecl fclose(FILE *_File);
  _CRTIMP صحیح __cdecl _fcloseall(تهی);
#ifdef _POSIX_
  FILE *__cdecl fdopen(صحیح _FileHandle,ثابت نویسه *_Mode);
#وگرنه
  _CRTIMP FILE *__cdecl _fdopen(صحیح _FileHandle,ثابت نویسه *_Mode);
#endif
  صحیح __cdecl feof(FILE *_File);
  صحیح __cdecl ferror(FILE *_File);
  صحیح __cdecl fflush(FILE *_File);
  صحیح __cdecl fgetc(FILE *_File);
  _CRTIMP صحیح __cdecl _fgetchar(تهی);
  صحیح __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  نویسه *__cdecl fgets(نویسه *_Buf,صحیح Max_شمار,FILE *_File);
#ifdef _POSIX_
  صحیح __cdecl fileno(FILE *_File);
#وگرنه
  _CRTIMP صحیح __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP نویسه *__cdecl _tempnam(ثابت نویسه *_DirName,ثابت نویسه *_FilePrefix);
  _CRTIMP صحیح __cdecl _flushall(تهی);
  FILE *__cdecl fopen(ثابت نویسه *_Filename,ثابت نویسه *_Mode);
  FILE *fopen64(ثابت نویسه *filename,ثابت نویسه *mode);
  صحیح __cdecl fprintf(FILE *_File,ثابت نویسه *_Format,...);
  صحیح __cdecl fputc(صحیح _Ch,FILE *_File);
  _CRTIMP صحیح __cdecl _fputchar(صحیح _Ch);
  صحیح __cdecl fputs(ثابت نویسه *_Str,FILE *_File);
  size_t __cdecl fread(تهی *_DstBuf,size_t _ElementSize,size_t شمار_5,FILE *_File);
  FILE *__cdecl freopen(ثابت نویسه *_Filename,ثابت نویسه *_Mode,FILE *_File);
  صحیح __cdecl fscanf(FILE *_File,ثابت نویسه *_Format,...);
  صحیح __cdecl fsetpos(FILE *_File,ثابت fpos_t *_Pos);
  صحیح __cdecl fseek(FILE *_File,long _Offset,صحیح _Origin);
   صحیح fseeko64(FILE* stream, _off64_t offset, صحیح whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  صحیح __cdecl _fseeki64(FILE *_File,__int64 _Offset,صحیح _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(ثابت تهی *_Str,size_t _Size,size_t شمار_5,FILE *_File);
  صحیح __cdecl getc(FILE *_File);
  صحیح __cdecl getchar(تهی);
  _CRTIMP صحیح __cdecl _getmaxstdio(تهی);
  نویسه *__cdecl gets(نویسه *_Buffer);
  صحیح __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  تهی __cdecl perror(ثابت نویسه *Err_پیام);
#endif
  _CRTIMP صحیح __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ثابت نویسه *_Command,ثابت نویسه *_Mode);
#اگر !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  صحیح __cdecl printf(ثابت نویسه *_Format,...);
  صحیح __cdecl putc(صحیح _Ch,FILE *_File);
  صحیح __cdecl putchar(صحیح _Ch);
  صحیح __cdecl puts(ثابت نویسه *_Str);
  _CRTIMP صحیح __cdecl _putw(صحیح _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  صحیح __cdecl remove(ثابت نویسه *_Filename);
  صحیح __cdecl rename(ثابت نویسه *_OldFilename,ثابت نویسه *_NewFilename);
  _CRTIMP صحیح __cdecl _unlink(ثابت نویسه *_Filename);
#ifndef NO_OLDNAMES
  صحیح __cdecl unlink(ثابت نویسه *_Filename);
#endif
#endif
  تهی __cdecl rewind(FILE *_File);
  _CRTIMP صحیح __cdecl _rmtmp(تهی);
  صحیح __cdecl scanf(ثابت نویسه *_Format,...);
  تهی __cdecl setbuf(FILE *_File,نویسه *_Buffer);
  _CRTIMP صحیح __cdecl _setmaxstdio(صحیح _Max);
  _CRTIMP unsigned صحیح __cdecl _set_output_format(unsigned صحیح _Format);
  _CRTIMP unsigned صحیح __cdecl _get_output_format(تهی);
  صحیح __cdecl setvbuf(FILE *_File,نویسه *_Buf,صحیح _Mode,size_t _Size);
  _CRTIMP صحیح __cdecl _scprintf(ثابت نویسه *_Format,...);
  صحیح __cdecl sscanf(ثابت نویسه *_Src,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _snscanf(ثابت نویسه *_Src,size_t Max_شمار,ثابت نویسه *_Format,...);
  FILE *__cdecl tmpfile(تهی);
  نویسه *__cdecl tmpnam(نویسه *_Buffer);
  صحیح __cdecl ungetc(صحیح _Ch,FILE *_File);
  صحیح __cdecl vfprintf(FILE *_File,ثابت نویسه *_Format,va_list _ArgList);
  صحیح __cdecl vprintf(ثابت نویسه *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma افزودن_macro("vsnprintf")
#pragma افزودن_macro("snprintf")
# undef vsnprintf
# undef snprintf
  بیرونی
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  صحیح __mingw_vsnprintf(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,va_list _ArgList);
  بیرونی
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  صحیح __mingw_snprintf(نویسه* s, size_t n, ثابت نویسه*  format, ...);
  صحیح __cdecl vsnprintf(نویسه *_DstBuf,size_t Max_شمار,ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snprintf(نویسه *_Dest,size_t شمار_5,ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _vsnprintf(نویسه *_Dest,size_t شمار_5,ثابت نویسه *_Format,va_list _Args);
  صحیح __cdecl sprintf(نویسه *_Dest,ثابت نویسه *_Format,...);
  صحیح __cdecl vsprintf(نویسه *_Dest,ثابت نویسه *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  صحیح __cdecl snprintf(نویسه* s, size_t n, ثابت نویسه*  format, ...);
  __CRT_INLINE صحیح __cdecl vsnprintf (نویسه* s, size_t n, ثابت نویسه* format,va_list arg) {
    بازگشت _vsnprintf ( s, n, format, arg);
  }
  صحیح __cdecl vscanf(ثابت نویسه * Format, va_list argp);
  صحیح __cdecl vfscanf (FILE * fp, ثابت نویسه * Format,va_list argp);
  صحیح __cdecl vsscanf (ثابت نویسه * _Str,ثابت نویسه * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma برداشت_macro("snprintf")
#pragma برداشت_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# اگر defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP صحیح __cdecl _vscprintf(ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl set_printf_شمار_output(صحیح مقدار_2);
  _CRTIMP صحیح __cdecl get_printf_شمار_output(تهی);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
#وگرنه
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,صحیح _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(تهی);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(تهی);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحیح Size_In_واژگان,FILE *_File);
  صحیح __cdecl fputws(ثابت wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP صحیح __cdecl _putws(ثابت wchar_t *_Str);
  صحیح __cdecl fwprintf(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl wprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _scwprintf(ثابت wchar_t *_Format,...);
  صحیح __cdecl vfwprintf(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl vwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl swprintf(wchar_t*, ثابت wchar_t*, ...);
  _CRTIMP صحیح __cdecl vswprintf(wchar_t*, ثابت wchar_t*,va_list);
  _CRTIMP صحیح __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_واژگان,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_واژگان,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf(wchar_t *_Dest,size_t شمار_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vsnwprintf(wchar_t *_Dest,size_t شمار_5,ثابت wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  صحیح __cdecl snwprintf (wchar_t* s, size_t n, ثابت wchar_t*  format, ...);
  __CRT_INLINE صحیح __cdecl vsnwprintf (wchar_t* s, size_t n, ثابت wchar_t* format, va_list arg) { بازگشت _vsnwprintf(s,n,format,arg); }
  صحیح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحیح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحیح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#endif
  _CRTIMP صحیح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#شامل <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *_FilePrefix);
  _CRTIMP صحیح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _snwscanf(ثابت wchar_t *_Src,size_t Max_شمار,ثابت wchar_t *_Format,...);
  صحیح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحیح _FileHandle ,ثابت wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP تهی __cdecl _wperror(ثابت wchar_t *Err_پیام);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *_Mode);
#اگر !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP صحیح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#اگر !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#وگرنه
  __CRT_INLINE wint_t __cdecl getwchar() { بازگشت (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { بازگشت (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (نویسه)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP تهی __cdecl _lock_file(FILE *_File);
  _CRTIMP تهی __cdecl _unlock_file(FILE *_File);
  _CRTIMP صحیح __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP صحیح __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(تهی *_DstBuf,size_t _ElementSize,size_t شمار_5,FILE *_File);
  _CRTIMP صحیح __cdecl _fseek_nolock(FILE *_File,long _Offset,صحیح _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP صحیح __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,صحیح _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(ثابت تهی *_DstBuf,size_t _Size,size_t شمار_5,FILE *_File);
  _CRTIMP صحیح __cdecl _ungetc_nolock(صحیح _Ch,FILE *_File);

#اگر !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  نویسه *__cdecl tempnam(ثابت نویسه *_Directory,ثابت نویسه *_FilePrefix);
  صحیح __cdecl fcloseall(تهی);
  FILE *__cdecl fdopen(صحیح _FileHandle,ثابت نویسه *_Format);
  صحیح __cdecl fgetchar(تهی);
  صحیح __cdecl fileno(FILE *_File);
  صحیح __cdecl flushall(تهی);
  صحیح __cdecl fputchar(صحیح _Ch);
  صحیح __cdecl getw(FILE *_File);
  صحیح __cdecl putw(صحیح _Ch,FILE *_File);
  صحیح __cdecl rmtmp(تهی);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)

#شامل <sec_api/stdio_s.h>

#endif
