/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#அந்தர்பாவ <_mingw.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  கட்டமைப்பு _iobuf {
    எழுத்து *_ptr;
    முழு _cnt;
    எழுத்து *_base;
    முழு _flag;
    முழு _file;
    முழு _charbuf;
    முழு _bufsiz;
    எழுத்து *_tmpfname;
  };
  வகைவரை கட்டமைப்பு _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#இல்லையெனில்
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (அளவு(_P_tmpdir) + 12)

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

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  வகைவரை long _off_t;
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  வகைவரை long long _off64_t;
#எனில் !defined(NO_OLDNAMES) || defined(_POSIX)
  வகைவரை long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(வெறுமை);
#இல்லையெனில்
#ifdef _MSVCRT_
வெளி FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#இல்லையெனில்
வெளி FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#எனில் (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  வகைவரை __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#இல்லையெனில்
  வகைவரை long long fpos_t;
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

  _CRTIMP முழு __cdecl _filbuf(FILE *_File);
  _CRTIMP முழு __cdecl _flsbuf(முழு _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_Mode);
#இல்லையெனில்
  _CRTIMP FILE *__cdecl _fsopen(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_Mode,முழு _ShFlag);
#endif
  வெறுமை __cdecl clearerr(FILE *_File);
  முழு __cdecl fclose(FILE *_File);
  _CRTIMP முழு __cdecl _fcloseall(வெறுமை);
#ifdef _POSIX_
  FILE *__cdecl fdopen(முழு _FileHandle,மாறிலி எழுத்து *_Mode);
#இல்லையெனில்
  _CRTIMP FILE *__cdecl _fdopen(முழு _FileHandle,மாறிலி எழுத்து *_Mode);
#endif
  முழு __cdecl feof(FILE *_File);
  முழு __cdecl ferror(FILE *_File);
  முழு __cdecl fflush(FILE *_File);
  முழு __cdecl fgetc(FILE *_File);
  _CRTIMP முழு __cdecl _fgetchar(வெறுமை);
  முழு __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  எழுத்து *__cdecl fgets(எழுத்து *_Buf,முழு Max_மொத்தம்,FILE *_File);
#ifdef _POSIX_
  முழு __cdecl fileno(FILE *_File);
#இல்லையெனில்
  _CRTIMP முழு __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP எழுத்து *__cdecl _tempnam(மாறிலி எழுத்து *_DirName,மாறிலி எழுத்து *_FilePrefix);
  _CRTIMP முழு __cdecl _flushall(வெறுமை);
  FILE *__cdecl fopen(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_Mode);
  FILE *fopen64(மாறிலி எழுத்து *filename,மாறிலி எழுத்து *mode);
  முழு __cdecl fprintf(FILE *_File,மாறிலி எழுத்து *_Format,...);
  முழு __cdecl fputc(முழு _Ch,FILE *_File);
  _CRTIMP முழு __cdecl _fputchar(முழு _Ch);
  முழு __cdecl fputs(மாறிலி எழுத்து *_Str,FILE *_File);
  size_t __cdecl fread(வெறுமை *_DstBuf,size_t _ElementSize,size_t மொத்தம்_5,FILE *_File);
  FILE *__cdecl freopen(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_Mode,FILE *_File);
  முழு __cdecl fscanf(FILE *_File,மாறிலி எழுத்து *_Format,...);
  முழு __cdecl fsetpos(FILE *_File,மாறிலி fpos_t *_Pos);
  முழு __cdecl fseek(FILE *_File,long _Offset,முழு _Origin);
   முழு fseeko64(FILE* stream, _off64_t offset, முழு whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  முழு __cdecl _fseeki64(FILE *_File,__int64 _Offset,முழு _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(மாறிலி வெறுமை *_Str,size_t _Size,size_t மொத்தம்_5,FILE *_File);
  முழு __cdecl getc(FILE *_File);
  முழு __cdecl getchar(வெறுமை);
  _CRTIMP முழு __cdecl _getmaxstdio(வெறுமை);
  எழுத்து *__cdecl gets(எழுத்து *_Buffer);
  முழு __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  வெறுமை __cdecl perror(மாறிலி எழுத்து *Err_செய்தி);
#endif
  _CRTIMP முழு __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(மாறிலி எழுத்து *_Command,மாறிலி எழுத்து *_Mode);
#எனில் !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  முழு __cdecl printf(மாறிலி எழுத்து *_Format,...);
  முழு __cdecl putc(முழு _Ch,FILE *_File);
  முழு __cdecl putchar(முழு _Ch);
  முழு __cdecl puts(மாறிலி எழுத்து *_Str);
  _CRTIMP முழு __cdecl _putw(முழு _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  முழு __cdecl remove(மாறிலி எழுத்து *_Filename);
  முழு __cdecl rename(மாறிலி எழுத்து *_OldFilename,மாறிலி எழுத்து *_NewFilename);
  _CRTIMP முழு __cdecl _unlink(மாறிலி எழுத்து *_Filename);
#ifndef NO_OLDNAMES
  முழு __cdecl unlink(மாறிலி எழுத்து *_Filename);
#endif
#endif
  வெறுமை __cdecl rewind(FILE *_File);
  _CRTIMP முழு __cdecl _rmtmp(வெறுமை);
  முழு __cdecl scanf(மாறிலி எழுத்து *_Format,...);
  வெறுமை __cdecl setbuf(FILE *_File,எழுத்து *_Buffer);
  _CRTIMP முழு __cdecl _setmaxstdio(முழு _Max);
  _CRTIMP unsigned முழு __cdecl _set_output_format(unsigned முழு _Format);
  _CRTIMP unsigned முழு __cdecl _get_output_format(வெறுமை);
  முழு __cdecl setvbuf(FILE *_File,எழுத்து *_Buf,முழு _Mode,size_t _Size);
  _CRTIMP முழு __cdecl _scprintf(மாறிலி எழுத்து *_Format,...);
  முழு __cdecl sscanf(மாறிலி எழுத்து *_Src,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _snscanf(மாறிலி எழுத்து *_Src,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,...);
  FILE *__cdecl tmpfile(வெறுமை);
  எழுத்து *__cdecl tmpnam(எழுத்து *_Buffer);
  முழு __cdecl ungetc(முழு _Ch,FILE *_File);
  முழு __cdecl vfprintf(FILE *_File,மாறிலி எழுத்து *_Format,va_list _ArgList);
  முழு __cdecl vprintf(மாறிலி எழுத்து *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma தள்ளு_macro("vsnprintf")
#pragma தள்ளு_macro("snprintf")
# undef vsnprintf
# undef snprintf
  வெளி
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  முழு __mingw_vsnprintf(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,va_list _ArgList);
  வெளி
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  முழு __mingw_snprintf(எழுத்து* s, size_t n, மாறிலி எழுத்து*  format, ...);
  முழு __cdecl vsnprintf(எழுத்து *_DstBuf,size_t Max_மொத்தம்,மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _snprintf(எழுத்து *_Dest,size_t மொத்தம்_5,மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _vsnprintf(எழுத்து *_Dest,size_t மொத்தம்_5,மாறிலி எழுத்து *_Format,va_list _Args);
  முழு __cdecl sprintf(எழுத்து *_Dest,மாறிலி எழுத்து *_Format,...);
  முழு __cdecl vsprintf(எழுத்து *_Dest,மாறிலி எழுத்து *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  முழு __cdecl snprintf(எழுத்து* s, size_t n, மாறிலி எழுத்து*  format, ...);
  __CRT_INLINE முழு __cdecl vsnprintf (எழுத்து* s, size_t n, மாறிலி எழுத்து* format,va_list arg) {
    திரும்பு _vsnprintf ( s, n, format, arg);
  }
  முழு __cdecl vscanf(மாறிலி எழுத்து * Format, va_list argp);
  முழு __cdecl vfscanf (FILE * fp, மாறிலி எழுத்து * Format,va_list argp);
  முழு __cdecl vsscanf (மாறிலி எழுத்து * _Str,மாறிலி எழுத்து * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma எடு_macro("snprintf")
#pragma எடு_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# எனில் defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP முழு __cdecl _vscprintf(மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl set_printf_மொத்தம்_output(முழு மதிப்பு_2);
  _CRTIMP முழு __cdecl get_printf_மொத்தம்_output(வெறுமை);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode);
#இல்லையெனில்
  _CRTIMP FILE *__cdecl _wfsopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode,முழு _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(வெறுமை);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(வெறுமை);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,முழு Size_In_சொற்கள்,FILE *_File);
  முழு __cdecl fputws(மாறிலி wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP முழு __cdecl _putws(மாறிலி wchar_t *_Str);
  முழு __cdecl fwprintf(FILE *_File,மாறிலி wchar_t *_Format,...);
  முழு __cdecl wprintf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _scwprintf(மாறிலி wchar_t *_Format,...);
  முழு __cdecl vfwprintf(FILE *_File,மாறிலி wchar_t *_Format,va_list _ArgList);
  முழு __cdecl vwprintf(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl swprintf(wchar_t*, மாறிலி wchar_t*, ...);
  _CRTIMP முழு __cdecl vswprintf(wchar_t*, மாறிலி wchar_t*,va_list);
  _CRTIMP முழு __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_சொற்கள்,மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _snwprintf(wchar_t *_Dest,size_t மொத்தம்_5,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vsnwprintf(wchar_t *_Dest,size_t மொத்தம்_5,மாறிலி wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  முழு __cdecl snwprintf (wchar_t* s, size_t n, மாறிலி wchar_t*  format, ...);
  __CRT_INLINE முழு __cdecl vsnwprintf (wchar_t* s, size_t n, மாறிலி wchar_t* format, va_list arg) { திரும்பு _vsnwprintf(s,n,format,arg); }
  முழு __cdecl vwscanf (மாறிலி wchar_t *, va_list);
  முழு __cdecl vfwscanf (FILE *,மாறிலி wchar_t *,va_list);
  முழு __cdecl vswscanf (மாறிலி wchar_t *,மாறிலி wchar_t *,va_list);
#endif
  _CRTIMP முழு __cdecl _swprintf(wchar_t *_Dest,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vswprintf(wchar_t *_Dest,மாறிலி wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#அந்தர்பாவ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(மாறிலி wchar_t *_Directory,மாறிலி wchar_t *_FilePrefix);
  _CRTIMP முழு __cdecl _vscwprintf(மாறிலி wchar_t *_Format,va_list _ArgList);
  முழு __cdecl fwscanf(FILE *_File,மாறிலி wchar_t *_Format,...);
  முழு __cdecl swscanf(மாறிலி wchar_t *_Src,மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _snwscanf(மாறிலி wchar_t *_Src,size_t Max_மொத்தம்,மாறிலி wchar_t *_Format,...);
  முழு __cdecl wscanf(மாறிலி wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(முழு _FileHandle ,மாறிலி wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP வெறுமை __cdecl _wperror(மாறிலி wchar_t *Err_செய்தி);
#endif
  _CRTIMP FILE *__cdecl _wpopen(மாறிலி wchar_t *_Command,மாறிலி wchar_t *_Mode);
#எனில் !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP முழு __cdecl _wremove(மாறிலி wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#எனில் !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#இல்லையெனில்
  __CRT_INLINE wint_t __cdecl getwchar() { திரும்பு (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { திரும்பு (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (எழுத்து)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP வெறுமை __cdecl _lock_file(FILE *_File);
  _CRTIMP வெறுமை __cdecl _unlock_file(FILE *_File);
  _CRTIMP முழு __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP முழு __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(வெறுமை *_DstBuf,size_t _ElementSize,size_t மொத்தம்_5,FILE *_File);
  _CRTIMP முழு __cdecl _fseek_nolock(FILE *_File,long _Offset,முழு _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP முழு __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,முழு _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(மாறிலி வெறுமை *_DstBuf,size_t _Size,size_t மொத்தம்_5,FILE *_File);
  _CRTIMP முழு __cdecl _ungetc_nolock(முழு _Ch,FILE *_File);

#எனில் !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  எழுத்து *__cdecl tempnam(மாறிலி எழுத்து *_Directory,மாறிலி எழுத்து *_FilePrefix);
  முழு __cdecl fcloseall(வெறுமை);
  FILE *__cdecl fdopen(முழு _FileHandle,மாறிலி எழுத்து *_Format);
  முழு __cdecl fgetchar(வெறுமை);
  முழு __cdecl fileno(FILE *_File);
  முழு __cdecl flushall(வெறுமை);
  முழு __cdecl fputchar(முழு _Ch);
  முழு __cdecl getw(FILE *_File);
  முழு __cdecl putw(முழு _Ch,FILE *_File);
  முழு __cdecl rmtmp(வெறுமை);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)

#அந்தர்பாவ <sec_api/stdio_s.h>

#endif
