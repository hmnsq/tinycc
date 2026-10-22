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
    целое _cnt;
    char *_base;
    целое _flag;
    целое _file;
    целое _charbuf;
    целое _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#иначе
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
#иначе
#define NULL ((void *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  typedef long _off_t;
#если !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  typedef long long _off64_t;
#если !defined(NO_OLDNAMES) || defined(_POSIX)
  typedef long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(void);
#иначе
#ifdef _MSVCRT_
extern FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#иначе
extern FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#если (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  typedef __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#иначе
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

  _CRTIMP целое __cdecl _filbuf(FILE *_File);
  _CRTIMP целое __cdecl _flsbuf(целое _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode);
#иначе
  _CRTIMP FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode,целое _ShFlag);
#endif
  void __cdecl clearerr(FILE *_File);
  целое __cdecl fclose(FILE *_File);
  _CRTIMP целое __cdecl _fcloseall(void);
#ifdef _POSIX_
  FILE *__cdecl fdopen(целое _FileHandle,const char *_Mode);
#иначе
  _CRTIMP FILE *__cdecl _fdopen(целое _FileHandle,const char *_Mode);
#endif
  целое __cdecl feof(FILE *_File);
  целое __cdecl ferror(FILE *_File);
  целое __cdecl fflush(FILE *_File);
  целое __cdecl fgetc(FILE *_File);
  _CRTIMP целое __cdecl _fgetchar(void);
  целое __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  char *__cdecl fgets(char *_Buf,целое _MaxCount,FILE *_File);
#ifdef _POSIX_
  целое __cdecl fileno(FILE *_File);
#иначе
  _CRTIMP целое __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP char *__cdecl _tempnam(const char *_DirName,const char *_FilePrefix);
  _CRTIMP целое __cdecl _flushall(void);
  FILE *__cdecl fopen(const char *_Filename,const char *_Mode);
  FILE *fopen64(const char *filename,const char *mode);
  целое __cdecl fprintf(FILE *_File,const char *_Format,...);
  целое __cdecl fputc(целое _Ch,FILE *_File);
  _CRTIMP целое __cdecl _fputchar(целое _Ch);
  целое __cdecl fputs(const char *_Str,FILE *_File);
  size_t __cdecl fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  FILE *__cdecl freopen(const char *_Filename,const char *_Mode,FILE *_File);
  целое __cdecl fscanf(FILE *_File,const char *_Format,...);
  целое __cdecl fsetpos(FILE *_File,const fpos_t *_Pos);
  целое __cdecl fseek(FILE *_File,long _Offset,целое _Origin);
   целое fseeko64(FILE* stream, _off64_t offset, целое whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  целое __cdecl _fseeki64(FILE *_File,__int64 _Offset,целое _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(const void *_Str,size_t _Size,size_t _Count,FILE *_File);
  целое __cdecl getc(FILE *_File);
  целое __cdecl getchar(void);
  _CRTIMP целое __cdecl _getmaxstdio(void);
  char *__cdecl gets(char *_Buffer);
  целое __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  void __cdecl perror(const char *_ErrMsg);
#endif
  _CRTIMP целое __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(const char *_Command,const char *_Mode);
#если !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  целое __cdecl printf(const char *_Format,...);
  целое __cdecl putc(целое _Ch,FILE *_File);
  целое __cdecl putchar(целое _Ch);
  целое __cdecl puts(const char *_Str);
  _CRTIMP целое __cdecl _putw(целое _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  целое __cdecl remove(const char *_Filename);
  целое __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  _CRTIMP целое __cdecl _unlink(const char *_Filename);
#ifndef NO_OLDNAMES
  целое __cdecl unlink(const char *_Filename);
#endif
#endif
  void __cdecl rewind(FILE *_File);
  _CRTIMP целое __cdecl _rmtmp(void);
  целое __cdecl scanf(const char *_Format,...);
  void __cdecl setbuf(FILE *_File,char *_Buffer);
  _CRTIMP целое __cdecl _setmaxstdio(целое _Max);
  _CRTIMP unsigned целое __cdecl _set_output_format(unsigned целое _Format);
  _CRTIMP unsigned целое __cdecl _get_output_format(void);
  целое __cdecl setvbuf(FILE *_File,char *_Buf,целое _Mode,size_t _Size);
  _CRTIMP целое __cdecl _scprintf(const char *_Format,...);
  целое __cdecl sscanf(const char *_Src,const char *_Format,...);
  _CRTIMP целое __cdecl _snscanf(const char *_Src,size_t _MaxCount,const char *_Format,...);
  FILE *__cdecl tmpfile(void);
  char *__cdecl tmpnam(char *_Buffer);
  целое __cdecl ungetc(целое _Ch,FILE *_File);
  целое __cdecl vfprintf(FILE *_File,const char *_Format,va_list _ArgList);
  целое __cdecl vprintf(const char *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma push_macro("vsnprintf")
#pragma push_macro("snprintf")
# undef vsnprintf
# undef snprintf
  extern
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  целое __mingw_vsnprintf(char *_DstBuf,size_t _MaxCount,const char *_Format,va_list _ArgList);
  extern
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  целое __mingw_snprintf(char* s, size_t n, const char*  format, ...);
  целое __cdecl vsnprintf(char *_DstBuf,size_t _MaxCount,const char *_Format,va_list _ArgList);
  _CRTIMP целое __cdecl _snprintf(char *_Dest,size_t _Count,const char *_Format,...);
  _CRTIMP целое __cdecl _vsnprintf(char *_Dest,size_t _Count,const char *_Format,va_list _Args);
  целое __cdecl sprintf(char *_Dest,const char *_Format,...);
  целое __cdecl vsprintf(char *_Dest,const char *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  целое __cdecl snprintf(char* s, size_t n, const char*  format, ...);
  __CRT_INLINE целое __cdecl vsnprintf (char* s, size_t n, const char* format,va_list arg) {
    вернуть _vsnprintf ( s, n, format, arg);
  }
  целое __cdecl vscanf(const char * Format, va_list argp);
  целое __cdecl vfscanf (FILE * fp, const char * Format,va_list argp);
  целое __cdecl vsscanf (const char * _Str,const char * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma pop_macro("snprintf")
#pragma pop_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# если defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP целое __cdecl _vscprintf(const char *_Format,va_list _ArgList);
  _CRTIMP целое __cdecl _set_printf_count_output(целое _Value);
  _CRTIMP целое __cdecl _get_printf_count_output(void);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode);
#иначе
  _CRTIMP FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,целое _ShFlag);
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
  wchar_t *__cdecl fgetws(wchar_t *_Dst,целое _SizeInWords,FILE *_File);
  целое __cdecl fputws(const wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP целое __cdecl _putws(const wchar_t *_Str);
  целое __cdecl fwprintf(FILE *_File,const wchar_t *_Format,...);
  целое __cdecl wprintf(const wchar_t *_Format,...);
  _CRTIMP целое __cdecl _scwprintf(const wchar_t *_Format,...);
  целое __cdecl vfwprintf(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  целое __cdecl vwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP целое __cdecl swprintf(wchar_t*, const wchar_t*, ...);
  _CRTIMP целое __cdecl vswprintf(wchar_t*, const wchar_t*,va_list);
  _CRTIMP целое __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,...);
  _CRTIMP целое __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,const wchar_t *_Format,va_list _ArgList);
  _CRTIMP целое __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,...);
  _CRTIMP целое __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,const wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  целое __cdecl snwprintf (wchar_t* s, size_t n, const wchar_t*  format, ...);
  __CRT_INLINE целое __cdecl vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, va_list arg) { вернуть _vsnwprintf(s,n,format,arg); }
  целое __cdecl vwscanf (const wchar_t *, va_list);
  целое __cdecl vfwscanf (FILE *,const wchar_t *,va_list);
  целое __cdecl vswscanf (const wchar_t *,const wchar_t *,va_list);
#endif
  _CRTIMP целое __cdecl _swprintf(wchar_t *_Dest,const wchar_t *_Format,...);
  _CRTIMP целое __cdecl _vswprintf(wchar_t *_Dest,const wchar_t *_Format,va_list _Args);

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
  _CRTIMP целое __cdecl _vscwprintf(const wchar_t *_Format,va_list _ArgList);
  целое __cdecl fwscanf(FILE *_File,const wchar_t *_Format,...);
  целое __cdecl swscanf(const wchar_t *_Src,const wchar_t *_Format,...);
  _CRTIMP целое __cdecl _snwscanf(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,...);
  целое __cdecl wscanf(const wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(целое _FileHandle ,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(const wchar_t *_Filename,const wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(const wchar_t *_Filename,const wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP void __cdecl _wperror(const wchar_t *_ErrMsg);
#endif
  _CRTIMP FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);
#если !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP целое __cdecl _wremove(const wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#если !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#иначе
  __CRT_INLINE wint_t __cdecl getwchar() { вернуть (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { вернуть (fputwc(_C,stdout)); }
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
  _CRTIMP целое __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP целое __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP целое __cdecl _fseek_nolock(FILE *_File,long _Offset,целое _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP целое __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,целое _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(const void *_DstBuf,size_t _Size,size_t _Count,FILE *_File);
  _CRTIMP целое __cdecl _ungetc_nolock(целое _Ch,FILE *_File);

#если !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  char *__cdecl tempnam(const char *_Directory,const char *_FilePrefix);
  целое __cdecl fcloseall(void);
  FILE *__cdecl fdopen(целое _FileHandle,const char *_Format);
  целое __cdecl fgetchar(void);
  целое __cdecl fileno(FILE *_File);
  целое __cdecl flushall(void);
  целое __cdecl fputchar(целое _Ch);
  целое __cdecl getw(FILE *_File);
  целое __cdecl putw(целое _Ch,FILE *_File);
  целое __cdecl rmtmp(void);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#include <sec_api/stdio_s.h>

#endif
