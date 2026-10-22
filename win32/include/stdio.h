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
    පූර්ණ_සංඛ්‍යා _cnt;
    var_na *_base;
    පූර්ණ_සංඛ්‍යා _flag;
    පූර්ණ_සංඛ්‍යා _file;
    පූර්ණ_සංඛ්‍යා _charbuf;
    පූර්ණ_සංඛ්‍යා _bufsiz;
    var_na *_tmpfname;
  };
  typedef sa_nracanaa _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#නැතහොත්
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
#නැතහොත්
#define NULL ((void *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#නම් !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  typedef long long _off64_t;
#නම් !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(void);
#නැතහොත්
#ifdef _MSVCRT_
extern FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#නැතහොත්
extern FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#නම් (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  typedef __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#නැතහොත්
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

  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _filbuf(FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _flsbuf(පූර්ණ_සංඛ්‍යා _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(const var_na *_Filename,const var_na *_Mode);
#නැතහොත්
  _CRTIMP FILE *__cdecl _fsopen(const var_na *_Filename,const var_na *_Mode,පූර්ණ_සංඛ්‍යා _ShFlag);
#endif
  void __cdecl clearerr(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl fclose(FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fcloseall(void);
#ifdef _POSIX_
  FILE *__cdecl fdopen(පූර්ණ_සංඛ්‍යා _FileHandle,const var_na *_Mode);
#නැතහොත්
  _CRTIMP FILE *__cdecl _fdopen(පූර්ණ_සංඛ්‍යා _FileHandle,const var_na *_Mode);
#endif
  පූර්ණ_සංඛ්‍යා __cdecl feof(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl ferror(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl fflush(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl fgetc(FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fgetchar(void);
  පූර්ණ_සංඛ්‍යා __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  var_na *__cdecl fgets(var_na *_Buf,පූර්ණ_සංඛ්‍යා _MaxCount,FILE *_File);
#ifdef _POSIX_
  පූර්ණ_සංඛ්‍යා __cdecl fileno(FILE *_File);
#නැතහොත්
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP var_na *__cdecl _tempnam(const var_na *_DirName,const var_na *_FilePrefix);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _flushall(void);
  FILE *__cdecl fopen(const var_na *_Filename,const var_na *_Mode);
  FILE *fopen64(const var_na *filename,const var_na *mode);
  පූර්ණ_සංඛ්‍යා __cdecl fprintf(FILE *_File,const var_na *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl fputc(පූර්ණ_සංඛ්‍යා _Ch,FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fputchar(පූර්ණ_සංඛ්‍යා _Ch);
  පූර්ණ_සංඛ්‍යා __cdecl fputs(const var_na *_Str,FILE *_File);
  size_t __cdecl fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  FILE *__cdecl freopen(const var_na *_Filename,const var_na *_Mode,FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl fscanf(FILE *_File,const var_na *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl fsetpos(FILE *_File,const fpos_t *_Pos);
  පූර්ණ_සංඛ්‍යා __cdecl fseek(FILE *_File,long _Offset,පූර්ණ_සංඛ්‍යා _Origin);
   පූර්ණ_සංඛ්‍යා fseeko64(FILE* stream, _off64_t offset, පූර්ණ_සංඛ්‍යා whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  පූර්ණ_සංඛ්‍යා __cdecl _fseeki64(FILE *_File,__int64 _Offset,පූර්ණ_සංඛ්‍යා _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(const void *_Str,size_t _Size,size_t _Count,FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl getc(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl getchar(void);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _getmaxstdio(void);
  var_na *__cdecl gets(var_na *_Buffer);
  පූර්ණ_සංඛ්‍යා __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const var_na *_ErrMsg);
#endif
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(const var_na *_Command,const var_na *_Mode);
#නම් !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  පූර්ණ_සංඛ්‍යා __cdecl printf(const var_na *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl putc(පූර්ණ_සංඛ්‍යා _Ch,FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl putchar(පූර්ණ_සංඛ්‍යා _Ch);
  පූර්ණ_සංඛ්‍යා __cdecl puts(const var_na *_Str);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _putw(පූර්ණ_සංඛ්‍යා _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  පූර්ණ_සංඛ්‍යා __cdecl remove(const var_na *_Filename);
  පූර්ණ_සංඛ්‍යා __cdecl rename(const var_na *_OldFilename,const var_na *_NewFilename);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _unlink(const var_na *_Filename);
#ifndef NO_OLDNAMES
  පූර්ණ_සංඛ්‍යා __cdecl unlink(const var_na *_Filename);
#endif
#endif
  void __cdecl rewind(FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _rmtmp(void);
  පූර්ණ_සංඛ්‍යා __cdecl scanf(const var_na *_Format,...);
  void __cdecl setbuf(FILE *_File,var_na *_Buffer);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _setmaxstdio(පූර්ණ_සංඛ්‍යා _Max);
  _CRTIMP unsigned පූර්ණ_සංඛ්‍යා __cdecl _set_output_format(unsigned පූර්ණ_සංඛ්‍යා _Format);
  _CRTIMP unsigned පූර්ණ_සංඛ්‍යා __cdecl _get_output_format(void);
  පූර්ණ_සංඛ්‍යා __cdecl setvbuf(FILE *_File,var_na *_Buf,පූර්ණ_සංඛ්‍යා _Mode,size_t _Size);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _scprintf(const var_na *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl sscanf(const var_na *_Src,const var_na *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _snscanf(const var_na *_Src,size_t _MaxCount,const var_na *_Format,...);
  FILE *__cdecl tmpfile(void);
  var_na *__cdecl tmpnam(var_na *_Buffer);
  පූර්ණ_සංඛ්‍යා __cdecl ungetc(පූර්ණ_සංඛ්‍යා _Ch,FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl vfprintf(FILE *_File,const var_na *_Format,va_list _ArgList);
  පූර්ණ_සංඛ්‍යා __cdecl vprintf(const var_na *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma push_macro("vsnprintf")
#pragma push_macro("snprintf")
# undef vsnprintf
# undef snprintf
  extern
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  පූර්ණ_සංඛ්‍යා __mingw_vsnprintf(var_na *_DstBuf,size_t _MaxCount,const var_na *_Format,va_list _ArgList);
  extern
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  පූර්ණ_සංඛ්‍යා __mingw_snprintf(var_na* s, size_t n, const var_na*  format, ...);
  පූර්ණ_සංඛ්‍යා __cdecl vsnprintf(var_na *_DstBuf,size_t _MaxCount,const var_na *_Format,va_list _ArgList);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _snprintf(var_na *_Dest,size_t _Count,const var_na *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _vsnprintf(var_na *_Dest,size_t _Count,const var_na *_Format,va_list _Args);
  පූර්ණ_සංඛ්‍යා __cdecl sprintf(var_na *_Dest,const var_na *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl vsprintf(var_na *_Dest,const var_na *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  පූර්ණ_සංඛ්‍යා __cdecl snprintf(var_na* s, size_t n, const var_na*  format, ...);
  __CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl vsnprintf (var_na* s, size_t n, const var_na* format,va_list arg) {
    ආපසු _vsnprintf ( s, n, format, arg);
  }
  පූර්ණ_සංඛ්‍යා __cdecl vscanf(const var_na * Format, va_list argp);
  පූර්ණ_සංඛ්‍යා __cdecl vfscanf (FILE * fp, const var_na * Format,va_list argp);
  පූර්ණ_සංඛ්‍යා __cdecl vsscanf (const var_na * _Str,const var_na * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# නම් defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _vscprintf(const var_na *_Format,va_list _ArgList);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _set_printf_count_output(පූර්ණ_සංඛ්‍යා _Value);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _get_printf_count_output(void);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode);
#නැතහොත්
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,පූර්ණ_සංඛ්‍යා _ShFlag);
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
  wchar_t *__cdecl fgetws(wchar_t *_Dst,පූර්ණ_සංඛ්‍යා _SizeInWords,FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl fputws(const wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _putws(const wchar_t *_Str);
  පූර්ණ_සංඛ්‍යා __cdecl fwprintf(FILE *_File,const wchar_t *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl wprintf(const wchar_t *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _scwprintf(const wchar_t *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl vfwprintf(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  පූර්ණ_සංඛ්‍යා __cdecl vwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl swprintf(wchar_t*, const wchar_t*, ...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl vswprintf(wchar_t*, const wchar_t*,va_list);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  පූර්ණ_සංඛ්‍යා __cdecl snwprintf (wchar_t* s, size_t n, const wchar_t*  format, ...);
  __CRT_INLINE පූර්ණ_සංඛ්‍යා __cdecl vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, va_list arg) { ආපසු _vsnwprintf(s,n,format,arg); }
  පූර්ණ_සංඛ්‍යා __cdecl vwscanf (const wchar_t *, va_list);
  පූර්ණ_සංඛ්‍යා __cdecl vfwscanf (FILE *,const wchar_t *,va_list);
  පූර්ණ_සංඛ්‍යා __cdecl vswscanf (const wchar_t *,const wchar_t *,va_list);
#endif
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _swprintf(wchar_t *_Dest,const wchar_t *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _vswprintf(wchar_t *_Dest,const wchar_t *_Format,va_list _Args);

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
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _vscwprintf(const wchar_t *_Format,va_list _ArgList);
  පූර්ණ_සංඛ්‍යා __cdecl fwscanf(FILE *_File,const wchar_t *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl swscanf(const wchar_t *_Src,const wchar_t *_Format,...);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _snwscanf(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,...);
  පූර්ණ_සංඛ්‍යා __cdecl wscanf(const wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(පූර්ණ_සංඛ්‍යා _FileHandle ,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t *_Filename,const wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);
#නම් !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#නම් !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#නැතහොත්
  __CRT_INLINE wint_t __cdecl getwchar() { ආපසු (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { ආපසු (fputwc(_C,stdout)); }
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
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fseek_nolock(FILE *_File,long _Offset,පූර්ණ_සංඛ්‍යා _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,පූර්ණ_සංඛ්‍යා _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(const void *_DstBuf,size_t _Size,size_t _Count,FILE *_File);
  _CRTIMP පූර්ණ_සංඛ්‍යා __cdecl _ungetc_nolock(පූර්ණ_සංඛ්‍යා _Ch,FILE *_File);

#නම් !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  var_na *__cdecl tempnam(const var_na *_Directory,const var_na *_FilePrefix);
  පූර්ණ_සංඛ්‍යා __cdecl fcloseall(void);
  FILE *__cdecl fdopen(පූර්ණ_සංඛ්‍යා _FileHandle,const var_na *_Format);
  පූර්ණ_සංඛ්‍යා __cdecl fgetchar(void);
  පූර්ණ_සංඛ්‍යා __cdecl fileno(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl flushall(void);
  පූර්ණ_සංඛ්‍යා __cdecl fputchar(පූර්ණ_සංඛ්‍යා _Ch);
  පූර්ණ_සංඛ්‍යා __cdecl getw(FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl putw(පූර්ණ_සංඛ්‍යා _Ch,FILE *_File);
  පූර්ණ_සංඛ්‍යා __cdecl rmtmp(void);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/stdio_s.h>

#endif
