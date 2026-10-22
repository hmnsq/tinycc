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
  struct _iobuf {
    char *_ptr;
    ціле _cnt;
    char *_base;
    ціле _flag;
    ціле _file;
    ціле _charbuf;
    ціле _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#інакше
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (sizeof(_P_tmpdir) + 12)

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
#інакше
#define NULL ((void *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#якщо !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  typedef long long _off64_t;
#якщо !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(void);
#інакше
#ifdef _MSVCRT_
extern FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#інакше
extern FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#якщо (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  typedef __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#інакше
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

  _CRTIMP ціле __cdecl _filbuf(FILE *_File);
  _CRTIMP ціле __cdecl _flsbuf(ціле _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode);
#інакше
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode,ціле _ShFlag);
#endif
  void __cdecl clearerr(FILE *_File);
  ціле __cdecl fclose(FILE *_File);
  _CRTIMP ціле __cdecl _fcloseall(void);
#ifdef _POSIX_
  FILE *__cdecl fdopen(ціле _FileHandle,const char *_Mode);
#інакше
  _CRTIMP FILE *__cdecl _fdopen(ціле _FileHandle,const char *_Mode);
#endif
  ціле __cdecl feof(FILE *_File);
  ціле __cdecl ferror(FILE *_File);
  ціле __cdecl fflush(FILE *_File);
  ціле __cdecl fgetc(FILE *_File);
  _CRTIMP ціле __cdecl _fgetchar(void);
  ціле __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  char *__cdecl fgets(char *_Buf,ціле _MaxCount,FILE *_File);
#ifdef _POSIX_
  ціле __cdecl fileno(FILE *_File);
#інакше
  _CRTIMP ціле __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP char *__cdecl _tempnam(const char *_DirName,const char *_FilePrefix);
  _CRTIMP ціле __cdecl _flushall(void);
  FILE *__cdecl fopen(const char *_Filename,const char *_Mode);
  FILE *fopen64(const char *filename,const char *mode);
  ціле __cdecl fprintf(FILE *_File,const char *_Format,...);
  ціле __cdecl fputc(ціле _Ch,FILE *_File);
  _CRTIMP ціле __cdecl _fputchar(ціле _Ch);
  ціле __cdecl fputs(const char *_Str,FILE *_File);
  size_t __cdecl fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  FILE *__cdecl freopen(const char *_Filename,const char *_Mode,FILE *_File);
  ціле __cdecl fscanf(FILE *_File,const char *_Format,...);
  ціле __cdecl fsetpos(FILE *_File,const fpos_t *_Pos);
  ціле __cdecl fseek(FILE *_File,long _Offset,ціле _Origin);
   ціле fseeko64(FILE* stream, _off64_t offset, ціле whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  ціле __cdecl _fseeki64(FILE *_File,__int64 _Offset,ціле _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(const void *_Str,size_t _Size,size_t _Count,FILE *_File);
  ціле __cdecl getc(FILE *_File);
  ціле __cdecl getchar(void);
  _CRTIMP ціле __cdecl _getmaxstdio(void);
  char *__cdecl gets(char *_Buffer);
  ціле __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const char *_ErrMsg);
#endif
  _CRTIMP ціле __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(const char *_Command,const char *_Mode);
#якщо !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  ціле __cdecl printf(const char *_Format,...);
  ціле __cdecl putc(ціле _Ch,FILE *_File);
  ціле __cdecl putchar(ціле _Ch);
  ціле __cdecl puts(const char *_Str);
  _CRTIMP ціле __cdecl _putw(ціле _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  ціле __cdecl remove(const char *_Filename);
  ціле __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  _CRTIMP ціле __cdecl _unlink(const char *_Filename);
#ifndef NO_OLDNAMES
  ціле __cdecl unlink(const char *_Filename);
#endif
#endif
  void __cdecl rewind(FILE *_File);
  _CRTIMP ціле __cdecl _rmtmp(void);
  ціле __cdecl scanf(const char *_Format,...);
  void __cdecl setbuf(FILE *_File,char *_Buffer);
  _CRTIMP ціле __cdecl _setmaxstdio(ціле _Max);
  _CRTIMP unsigned ціле __cdecl _set_output_format(unsigned ціле _Format);
  _CRTIMP unsigned ціле __cdecl _get_output_format(void);
  ціле __cdecl setvbuf(FILE *_File,char *_Buf,ціле _Mode,size_t _Size);
  _CRTIMP ціле __cdecl _scprintf(const char *_Format,...);
  ціле __cdecl sscanf(const char *_Src,const char *_Format,...);
  _CRTIMP ціле __cdecl _snscanf(const char *_Src,size_t _MaxCount,const char *_Format,...);
  FILE *__cdecl tmpfile(void);
  char *__cdecl tmpnam(char *_Buffer);
  ціле __cdecl ungetc(ціле _Ch,FILE *_File);
  ціле __cdecl vfprintf(FILE *_File,const char *_Format,va_list _ArgList);
  ціле __cdecl vprintf(const char *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma push_macro("vsnprintf")
#pragma push_macro("snprintf")
# undef vsnprintf
# undef snprintf
  extern
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  ціле __mingw_vsnprintf(char *_DstBuf,size_t _MaxCount,const char *_Format,va_list _ArgList);
  extern
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  ціле __mingw_snprintf(char* s, size_t n, const char*  format, ...);
  ціле __cdecl vsnprintf(char *_DstBuf,size_t _MaxCount,const char *_Format,va_list _ArgList);
  _CRTIMP ціле __cdecl _snprintf(char *_Dest,size_t _Count,const char *_Format,...);
  _CRTIMP ціле __cdecl _vsnprintf(char *_Dest,size_t _Count,const char *_Format,va_list _Args);
  ціле __cdecl sprintf(char *_Dest,const char *_Format,...);
  ціле __cdecl vsprintf(char *_Dest,const char *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ціле __cdecl snprintf(char* s, size_t n, const char*  format, ...);
  __CRT_INLINE ціле __cdecl vsnprintf (char* s, size_t n, const char* format,va_list arg) {
    повернути _vsnprintf ( s, n, format, arg);
  }
  ціле __cdecl vscanf(const char * Format, va_list argp);
  ціле __cdecl vfscanf (FILE * fp, const char * Format,va_list argp);
  ціле __cdecl vsscanf (const char * _Str,const char * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# якщо defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP ціле __cdecl _vscprintf(const char *_Format,va_list _ArgList);
  _CRTIMP ціле __cdecl _set_printf_count_output(ціле _Value);
  _CRTIMP ціле __cdecl _get_printf_count_output(void);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode);
#інакше
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,ціле _ShFlag);
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
  wchar_t *__cdecl fgetws(wchar_t *_Dst,ціле _SizeInWords,FILE *_File);
  ціле __cdecl fputws(const wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP ціле __cdecl _putws(const wchar_t *_Str);
  ціле __cdecl fwprintf(FILE *_File,const wchar_t *_Format,...);
  ціле __cdecl wprintf(const wchar_t *_Format,...);
  _CRTIMP ціле __cdecl _scwprintf(const wchar_t *_Format,...);
  ціле __cdecl vfwprintf(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  ціле __cdecl vwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP ціле __cdecl swprintf(wchar_t*, const wchar_t*, ...);
  _CRTIMP ціле __cdecl vswprintf(wchar_t*, const wchar_t*,va_list);
  _CRTIMP ціле __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,...);
  _CRTIMP ціле __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP ціле __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,...);
  _CRTIMP ціле __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  ціле __cdecl snwprintf (wchar_t* s, size_t n, const wchar_t*  format, ...);
  __CRT_INLINE ціле __cdecl vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, va_list arg) { повернути _vsnwprintf(s,n,format,arg); }
  ціле __cdecl vwscanf (const wchar_t *, va_list);
  ціле __cdecl vfwscanf (FILE *,const wchar_t *,va_list);
  ціле __cdecl vswscanf (const wchar_t *,const wchar_t *,va_list);
#endif
  _CRTIMP ціле __cdecl _swprintf(wchar_t *_Dest,const wchar_t *_Format,...);
  _CRTIMP ціле __cdecl _vswprintf(wchar_t *_Dest,const wchar_t *_Format,va_list _Args);

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
  _CRTIMP ціле __cdecl _vscwprintf(const wchar_t *_Format,va_list _ArgList);
  ціле __cdecl fwscanf(FILE *_File,const wchar_t *_Format,...);
  ціле __cdecl swscanf(const wchar_t *_Src,const wchar_t *_Format,...);
  _CRTIMP ціле __cdecl _snwscanf(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,...);
  ціле __cdecl wscanf(const wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(ціле _FileHandle ,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t *_Filename,const wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);
#якщо !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP ціле __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#якщо !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#інакше
  __CRT_INLINE wint_t __cdecl getwchar() { повернути (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { повернути (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (char)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP void __cdecl _lock_file(FILE *_File);
  _CRTIMP void __cdecl _unlock_file(FILE *_File);
  _CRTIMP ціле __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP ціле __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP ціле __cdecl _fseek_nolock(FILE *_File,long _Offset,ціле _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP ціле __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,ціле _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(const void *_DstBuf,size_t _Size,size_t _Count,FILE *_File);
  _CRTIMP ціле __cdecl _ungetc_nolock(ціле _Ch,FILE *_File);

#якщо !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  char *__cdecl tempnam(const char *_Directory,const char *_FilePrefix);
  ціле __cdecl fcloseall(void);
  FILE *__cdecl fdopen(ціле _FileHandle,const char *_Format);
  ціле __cdecl fgetchar(void);
  ціле __cdecl fileno(FILE *_File);
  ціле __cdecl flushall(void);
  ціле __cdecl fputchar(ціле _Ch);
  ціле __cdecl getw(FILE *_File);
  ціле __cdecl putw(ціле _Ch,FILE *_File);
  ціле __cdecl rmtmp(void);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/stdio_s.h>

#endif
