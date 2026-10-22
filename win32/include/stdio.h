/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#ضمن <_mingw.h>

#pragma pack(ئىتتىرىش,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *_base;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#وإلا
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (حجم(_P_tmpdir) + 12)

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

#ifndef عدم
#ifdef __cplusplus
#define عدم 0
#وإلا
#define عدم ((فراغ *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  تعريفنوع long _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  تعريفنوع long long _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#ifdef _MSVCRT_
خارجي FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#وإلا
خارجي FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#إذا (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  تعريفنوع __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#وإلا
  تعريفنوع long long fpos_t;
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

  _CRTIMP صحيح __cdecl _filbuf(FILE *_File);
  _CRTIMP صحيح __cdecl _flsbuf(صحيح _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *_Mode);
#وإلا
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *_Mode,صحيح _ShFlag);
#endif
  فراغ __cdecl clearerr(FILE *_File);
  صحيح __cdecl fclose(FILE *_File);
  _CRTIMP صحيح __cdecl _fcloseall(فراغ);
#ifdef _POSIX_
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *_Mode);
#وإلا
  _CRTIMP FILE *__cdecl _fdopen(صحيح _FileHandle,ثابت حرف *_Mode);
#endif
  صحيح __cdecl feof(FILE *_File);
  صحيح __cdecl ferror(FILE *_File);
  صحيح __cdecl fflush(FILE *_File);
  صحيح __cdecl fgetc(FILE *_File);
  _CRTIMP صحيح __cdecl _fgetchar(فراغ);
  صحيح __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  حرف *__cdecl fgets(حرف *_Buf,صحيح Max_سانى,FILE *_File);
#ifdef _POSIX_
  صحيح __cdecl fileno(FILE *_File);
#وإلا
  _CRTIMP صحيح __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP حرف *__cdecl _tempnam(ثابت حرف *_DirName,ثابت حرف *_FilePrefix);
  _CRTIMP صحيح __cdecl _flushall(فراغ);
  FILE *__cdecl fopen(ثابت حرف *_Filename,ثابت حرف *_Mode);
  FILE *fopen64(ثابت حرف *filename,ثابت حرف *mode);
  صحيح __cdecl fprintf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fputc(صحيح _Ch,FILE *_File);
  _CRTIMP صحيح __cdecl _fputchar(صحيح _Ch);
  صحيح __cdecl fputs(ثابت حرف *_Str,FILE *_File);
  size_t __cdecl fread(فراغ *_DstBuf,size_t _ElementSize,size_t سانى_5,FILE *_File);
  FILE *__cdecl freopen(ثابت حرف *_Filename,ثابت حرف *_Mode,FILE *_File);
  صحيح __cdecl fscanf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fsetpos(FILE *_File,ثابت fpos_t *_Pos);
  صحيح __cdecl fseek(FILE *_File,long _Offset,صحيح _Origin);
   صحيح fseeko64(FILE* stream, _off64_t offset, صحيح whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  صحيح __cdecl _fseeki64(FILE *_File,__int64 _Offset,صحيح _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(ثابت فراغ *_Str,size_t _Size,size_t سانى_5,FILE *_File);
  صحيح __cdecl getc(FILE *_File);
  صحيح __cdecl getchar(فراغ);
  _CRTIMP صحيح __cdecl _getmaxstdio(فراغ);
  حرف *__cdecl gets(حرف *_Buffer);
  صحيح __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_ئۇچۇر);
#endif
  _CRTIMP صحيح __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ثابت حرف *_Command,ثابت حرف *_Mode);
#إذا !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  صحيح __cdecl printf(ثابت حرف *_Format,...);
  صحيح __cdecl putc(صحيح _Ch,FILE *_File);
  صحيح __cdecl putchar(صحيح _Ch);
  صحيح __cdecl puts(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _putw(صحيح _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#ifndef NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#endif
#endif
  فراغ __cdecl rewind(FILE *_File);
  _CRTIMP صحيح __cdecl _rmtmp(فراغ);
  صحيح __cdecl scanf(ثابت حرف *_Format,...);
  فراغ __cdecl setbuf(FILE *_File,حرف *_Buffer);
  _CRTIMP صحيح __cdecl _setmaxstdio(صحيح _Max);
  _CRTIMP unsigned صحيح __cdecl _set_output_format(unsigned صحيح _Format);
  _CRTIMP unsigned صحيح __cdecl _get_output_format(فراغ);
  صحيح __cdecl setvbuf(FILE *_File,حرف *_Buf,صحيح _Mode,size_t _Size);
  _CRTIMP صحيح __cdecl _scprintf(ثابت حرف *_Format,...);
  صحيح __cdecl sscanf(ثابت حرف *_Src,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _snscanf(ثابت حرف *_Src,size_t Max_سانى,ثابت حرف *_Format,...);
  FILE *__cdecl tmpfile(فراغ);
  حرف *__cdecl tmpnam(حرف *_Buffer);
  صحيح __cdecl ungetc(صحيح _Ch,FILE *_File);
  صحيح __cdecl vfprintf(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vprintf(ثابت حرف *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ئىتتىرىش_macro("vsnprintf")
#pragma ئىتتىرىش_macro("snprintf")
# undef vsnprintf
# undef snprintf
  خارجي
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  صحيح __mingw_vsnprintf(حرف *_DstBuf,size_t Max_سانى,ثابت حرف *_Format,va_list _ArgList);
  خارجي
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  صحيح __mingw_snprintf(حرف* s, size_t n, ثابت حرف*  format, ...);
  صحيح __cdecl vsnprintf(حرف *_DstBuf,size_t Max_سانى,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snprintf(حرف *_Dest,size_t سانى_5,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vsnprintf(حرف *_Dest,size_t سانى_5,ثابت حرف *_Format,va_list _Args);
  صحيح __cdecl sprintf(حرف *_Dest,ثابت حرف *_Format,...);
  صحيح __cdecl vsprintf(حرف *_Dest,ثابت حرف *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snprintf(حرف* s, size_t n, ثابت حرف*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnprintf (حرف* s, size_t n, ثابت حرف* format,va_list arg) {
    أرجع _vsnprintf ( s, n, format, arg);
  }
  صحيح __cdecl vscanf(ثابت حرف * Format, va_list argp);
  صحيح __cdecl vfscanf (FILE * fp, ثابت حرف * Format,va_list argp);
  صحيح __cdecl vsscanf (ثابت حرف * _Str,ثابت حرف * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma چىقىرىش_macro("snprintf")
#pragma چىقىرىش_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# إذا defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP صحيح __cdecl _vscprintf(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl set_printf_سانى_output(صحيح قىممەت_2);
  _CRTIMP صحيح __cdecl get_printf_سانى_output(فراغ);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,صحيح _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح Size_In_سۆزلەر,FILE *_File);
  صحيح __cdecl fputws(ثابت wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP صحيح __cdecl _putws(ثابت wchar_t *_Str);
  صحيح __cdecl fwprintf(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl wprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _scwprintf(ثابت wchar_t *_Format,...);
  صحيح __cdecl vfwprintf(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl vwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl swprintf(wchar_t*, ثابت wchar_t*, ...);
  _CRTIMP صحيح __cdecl vswprintf(wchar_t*, ثابت wchar_t*,va_list);
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_سۆزلەر,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_سۆزلەر,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,size_t سانى_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,size_t سانى_5,ثابت wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t* s, size_t n, ثابت wchar_t*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t* s, size_t n, ثابت wchar_t* format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#endif
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#ضمن <vadefs.h>
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
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,size_t Max_سانى,ثابت wchar_t *_Format,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_ئۇچۇر);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *_Mode);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() { أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { أرجع (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (حرف)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP فراغ __cdecl _lock_file(FILE *_File);
  _CRTIMP فراغ __cdecl _unlock_file(FILE *_File);
  _CRTIMP صحيح __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(فراغ *_DstBuf,size_t _ElementSize,size_t سانى_5,FILE *_File);
  _CRTIMP صحيح __cdecl _fseek_nolock(FILE *_File,long _Offset,صحيح _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,صحيح _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(ثابت فراغ *_DstBuf,size_t _Size,size_t سانى_5,FILE *_File);
  _CRTIMP صحيح __cdecl _ungetc_nolock(صحيح _Ch,FILE *_File);

#إذا !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  حرف *__cdecl tempnam(ثابت حرف *_Directory,ثابت حرف *_FilePrefix);
  صحيح __cdecl fcloseall(فراغ);
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *_Format);
  صحيح __cdecl fgetchar(فراغ);
  صحيح __cdecl fileno(FILE *_File);
  صحيح __cdecl flushall(فراغ);
  صحيح __cdecl fputchar(صحيح _Ch);
  صحيح __cdecl getw(FILE *_File);
  صحيح __cdecl putw(صحيح _Ch,FILE *_File);
  صحيح __cdecl rmtmp(فراغ);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(چىقىرىش)

#ضمن <sec_api/stdio_s.h>

#endif
