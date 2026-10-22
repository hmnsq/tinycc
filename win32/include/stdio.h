/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#include <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  sa_nracanaa _iobuf {
    var_na *_ptr;
    จำนวนเต็ม _cnt;
    var_na *_base;
    จำนวนเต็ม _flag;
    จำนวนเต็ม _file;
    จำนวนเต็ม _charbuf;
    จำนวนเต็ม _bufsiz;
    var_na *_tmpfname;
  };
  typedef sa_nracanaa _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#มิฉะนั้น
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (parimaa_na(_P_tmpdir) + 12)

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

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#มิฉะนั้น
#define NULL ((void *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#ถ้า !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  typedef long long _off64_t;
#ถ้า !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(void);
#มิฉะนั้น
#ifdef _MSVCRT_
extern FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#มิฉะนั้น
extern FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#ถ้า (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  typedef __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#มิฉะนั้น
  typedef long long fpos_t;
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

  _CRTIMP จำนวนเต็ม __cdecl _filbuf(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _flsbuf(จำนวนเต็ม _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(const var_na *_Filename,const var_na *_Mode);
#มิฉะนั้น
  _CRTIMP FILE *__cdecl _fsopen(const var_na *_Filename,const var_na *_Mode,จำนวนเต็ม _ShFlag);
#endif
  void __cdecl clearerr(FILE *_File);
  จำนวนเต็ม __cdecl fclose(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fcloseall(void);
#ifdef _POSIX_
  FILE *__cdecl fdopen(จำนวนเต็ม _FileHandle,const var_na *_Mode);
#มิฉะนั้น
  _CRTIMP FILE *__cdecl _fdopen(จำนวนเต็ม _FileHandle,const var_na *_Mode);
#endif
  จำนวนเต็ม __cdecl feof(FILE *_File);
  จำนวนเต็ม __cdecl ferror(FILE *_File);
  จำนวนเต็ม __cdecl fflush(FILE *_File);
  จำนวนเต็ม __cdecl fgetc(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fgetchar(void);
  จำนวนเต็ม __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  var_na *__cdecl fgets(var_na *_Buf,จำนวนเต็ม _MaxCount,FILE *_File);
#ifdef _POSIX_
  จำนวนเต็ม __cdecl fileno(FILE *_File);
#มิฉะนั้น
  _CRTIMP จำนวนเต็ม __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP var_na *__cdecl _tempnam(const var_na *_DirName,const var_na *_FilePrefix);
  _CRTIMP จำนวนเต็ม __cdecl _flushall(void);
  FILE *__cdecl fopen(const var_na *_Filename,const var_na *_Mode);
  FILE *fopen64(const var_na *filename,const var_na *mode);
  จำนวนเต็ม __cdecl fprintf(FILE *_File,const var_na *_Format,...);
  จำนวนเต็ม __cdecl fputc(จำนวนเต็ม _Ch,FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fputchar(จำนวนเต็ม _Ch);
  จำนวนเต็ม __cdecl fputs(const var_na *_Str,FILE *_File);
  size_t __cdecl fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  FILE *__cdecl freopen(const var_na *_Filename,const var_na *_Mode,FILE *_File);
  จำนวนเต็ม __cdecl fscanf(FILE *_File,const var_na *_Format,...);
  จำนวนเต็ม __cdecl fsetpos(FILE *_File,const fpos_t *_Pos);
  จำนวนเต็ม __cdecl fseek(FILE *_File,long _Offset,จำนวนเต็ม _Origin);
   จำนวนเต็ม fseeko64(FILE* stream, _off64_t offset, จำนวนเต็ม whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  จำนวนเต็ม __cdecl _fseeki64(FILE *_File,__int64 _Offset,จำนวนเต็ม _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(const void *_Str,size_t _Size,size_t _Count,FILE *_File);
  จำนวนเต็ม __cdecl getc(FILE *_File);
  จำนวนเต็ม __cdecl getchar(void);
  _CRTIMP จำนวนเต็ม __cdecl _getmaxstdio(void);
  var_na *__cdecl gets(var_na *_Buffer);
  จำนวนเต็ม __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const var_na *_ErrMsg);
#endif
  _CRTIMP จำนวนเต็ม __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(const var_na *_Command,const var_na *_Mode);
#ถ้า !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  จำนวนเต็ม __cdecl printf(const var_na *_Format,...);
  จำนวนเต็ม __cdecl putc(จำนวนเต็ม _Ch,FILE *_File);
  จำนวนเต็ม __cdecl putchar(จำนวนเต็ม _Ch);
  จำนวนเต็ม __cdecl puts(const var_na *_Str);
  _CRTIMP จำนวนเต็ม __cdecl _putw(จำนวนเต็ม _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  จำนวนเต็ม __cdecl remove(const var_na *_Filename);
  จำนวนเต็ม __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP จำนวนเต็ม __cdecl _unlink(const var_na *_Filename);
#ifndef NO_OLDNAMES
  จำนวนเต็ม __cdecl unlink(const var_na *_Filename);
#endif
#endif
  void __cdecl rewind(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _rmtmp(void);
  จำนวนเต็ม __cdecl scanf(const var_na *_Format,...);
  void __cdecl setbuf(FILE *_File,var_na *_Buffer);
  _CRTIMP จำนวนเต็ม __cdecl _setmaxstdio(จำนวนเต็ม _Max);
  _CRTIMP unsigned จำนวนเต็ม __cdecl _set_output_format(unsigned จำนวนเต็ม _Format);
  _CRTIMP unsigned จำนวนเต็ม __cdecl _get_output_format(void);
  จำนวนเต็ม __cdecl setvbuf(FILE *_File,var_na *_Buf,จำนวนเต็ม _Mode,size_t _Size);
  _CRTIMP จำนวนเต็ม __cdecl _scprintf(const var_na *_Format,...);
  จำนวนเต็ม __cdecl sscanf(const var_na *_Src,const var_na *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _snscanf(const var_na *_Src,size_t _MaxCount,const var_na *_Format,...);
  FILE *__cdecl tmpfile(void);
  var_na *__cdecl tmpnam(var_na *_Buffer);
  จำนวนเต็ม __cdecl ungetc(จำนวนเต็ม _Ch,FILE *_File);
  จำนวนเต็ม __cdecl vfprintf(FILE *_File,const var_na *_Format,va_list _ArgList);
  จำนวนเต็ม __cdecl vprintf(const var_na *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma push_macro("vsnprintf")
#pragma push_macro("snprintf")
# undef vsnprintf
# undef snprintf
  extern
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  จำนวนเต็ม __mingw_vsnprintf(var_na *_DstBuf,size_t _MaxCount,const var_na *_Format,va_list _ArgList);
  extern
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  จำนวนเต็ม __mingw_snprintf(var_na* s, size_t n, const var_na*  format, ...);
  จำนวนเต็ม __cdecl vsnprintf(var_na *_DstBuf,size_t _MaxCount,const var_na *_Format,va_list _ArgList);
  _CRTIMP จำนวนเต็ม __cdecl _snprintf(var_na *_Dest,size_t _Count,const var_na *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _vsnprintf(var_na *_Dest,size_t _Count,const var_na *_Format,va_list _Args);
  จำนวนเต็ม __cdecl sprintf(var_na *_Dest,const var_na *_Format,...);
  จำนวนเต็ม __cdecl vsprintf(var_na *_Dest,const var_na *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  จำนวนเต็ม __cdecl snprintf(var_na* s, size_t n, const var_na*  format, ...);
  __CRT_INLINE จำนวนเต็ม __cdecl vsnprintf (var_na* s, size_t n, const var_na* format,va_list arg) {
    คืน _vsnprintf ( s, n, format, arg);
  }
  จำนวนเต็ม __cdecl vscanf(const var_na * Format, va_list argp);
  จำนวนเต็ม __cdecl vfscanf (FILE * fp, const var_na * Format,va_list argp);
  จำนวนเต็ม __cdecl vsscanf (const var_na * _Str,const var_na * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# ถ้า defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP จำนวนเต็ม __cdecl _vscprintf(const var_na *_Format,va_list _ArgList);
  _CRTIMP จำนวนเต็ม __cdecl _set_printf_count_output(จำนวนเต็ม _Value);
  _CRTIMP จำนวนเต็ม __cdecl _get_printf_count_output(void);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode);
#มิฉะนั้น
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,จำนวนเต็ม _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,จำนวนเต็ม _SizeInWords,FILE *_File);
  จำนวนเต็ม __cdecl fputws(const wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP จำนวนเต็ม __cdecl _putws(const wchar_t *_Str);
  จำนวนเต็ม __cdecl fwprintf(FILE *_File,const wchar_t *_Format,...);
  จำนวนเต็ม __cdecl wprintf(const wchar_t *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _scwprintf(const wchar_t *_Format,...);
  จำนวนเต็ม __cdecl vfwprintf(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  จำนวนเต็ม __cdecl vwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP จำนวนเต็ม __cdecl swprintf(wchar_t*, const wchar_t*, ...);
  _CRTIMP จำนวนเต็ม __cdecl vswprintf(wchar_t*, const wchar_t*,va_list);
  _CRTIMP จำนวนเต็ม __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP จำนวนเต็ม __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  จำนวนเต็ม __cdecl snwprintf (wchar_t* s, size_t n, const wchar_t*  format, ...);
  __CRT_INLINE จำนวนเต็ม __cdecl vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, va_list arg) { คืน _vsnwprintf(s,n,format,arg); }
  จำนวนเต็ม __cdecl vwscanf (const wchar_t *, va_list);
  จำนวนเต็ม __cdecl vfwscanf (FILE *,const wchar_t *,va_list);
  จำนวนเต็ม __cdecl vswscanf (const wchar_t *,const wchar_t *,va_list);
#endif
  _CRTIMP จำนวนเต็ม __cdecl _swprintf(wchar_t *_Dest,const wchar_t *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _vswprintf(wchar_t *_Dest,const wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#include <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(const wchar_t *_Directory,const wchar_t *_FilePrefix);
  _CRTIMP จำนวนเต็ม __cdecl _vscwprintf(const wchar_t *_Format,va_list _ArgList);
  จำนวนเต็ม __cdecl fwscanf(FILE *_File,const wchar_t *_Format,...);
  จำนวนเต็ม __cdecl swscanf(const wchar_t *_Src,const wchar_t *_Format,...);
  _CRTIMP จำนวนเต็ม __cdecl _snwscanf(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,...);
  จำนวนเต็ม __cdecl wscanf(const wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(จำนวนเต็ม _FileHandle ,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t *_Filename,const wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);
#ถ้า !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP จำนวนเต็ม __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#ถ้า !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#มิฉะนั้น
  __CRT_INLINE wint_t __cdecl getwchar() { คืน (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { คืน (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (var_na)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP void __cdecl _lock_file(FILE *_File);
  _CRTIMP void __cdecl _unlock_file(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fseek_nolock(FILE *_File,long _Offset,จำนวนเต็ม _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,จำนวนเต็ม _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(const void *_DstBuf,size_t _Size,size_t _Count,FILE *_File);
  _CRTIMP จำนวนเต็ม __cdecl _ungetc_nolock(จำนวนเต็ม _Ch,FILE *_File);

#ถ้า !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  var_na *__cdecl tempnam(const var_na *_Directory,const var_na *_FilePrefix);
  จำนวนเต็ม __cdecl fcloseall(void);
  FILE *__cdecl fdopen(จำนวนเต็ม _FileHandle,const var_na *_Format);
  จำนวนเต็ม __cdecl fgetchar(void);
  จำนวนเต็ม __cdecl fileno(FILE *_File);
  จำนวนเต็ม __cdecl flushall(void);
  จำนวนเต็ม __cdecl fputchar(จำนวนเต็ม _Ch);
  จำนวนเต็ม __cdecl getw(FILE *_File);
  จำนวนเต็ม __cdecl putw(จำนวนเต็ม _Ch,FILE *_File);
  จำนวนเต็ม __cdecl rmtmp(void);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/stdio_s.h>

#endif
