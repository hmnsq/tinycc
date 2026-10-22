/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#അന്തര്ഭാവ <_mingw.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  ഘടന _iobuf {
    അക്ഷരം *_ptr;
    പൂർണ്ണസംഖ്യ _cnt;
    അക്ഷരം *_base;
    പൂർണ്ണസംഖ്യ _flag;
    പൂർണ്ണസംഖ്യ _file;
    പൂർണ്ണസംഖ്യ _charbuf;
    പൂർണ്ണസംഖ്യ _bufsiz;
    അക്ഷരം *_tmpfname;
  };
  തരനിർവചനം ഘടന _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#അല്ലെങ്കിൽ
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (വലുപ്പം(_P_tmpdir) + 12)

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

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  തരനിർവചനം long _off_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  തരനിർവചനം long long _off64_t;
#എങ്കിൽ !defined(NO_OLDNAMES) || defined(_POSIX)
  തരനിർവചനം long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(ശൂന്യം);
#അല്ലെങ്കിൽ
#ifdef _MSVCRT_
ബാഹ്യ FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#അല്ലെങ്കിൽ
ബാഹ്യ FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#എങ്കിൽ (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  തരനിർവചനം __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#അല്ലെങ്കിൽ
  തരനിർവചനം long long fpos_t;
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

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _filbuf(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _flsbuf(പൂർണ്ണസംഖ്യ _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_Mode);
#അല്ലെങ്കിൽ
  _CRTIMP FILE *__cdecl _fsopen(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_Mode,പൂർണ്ണസംഖ്യ _ShFlag);
#endif
  ശൂന്യം __cdecl clearerr(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fclose(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fcloseall(ശൂന്യം);
#ifdef _POSIX_
  FILE *__cdecl fdopen(പൂർണ്ണസംഖ്യ _FileHandle,സ്ഥിരം അക്ഷരം *_Mode);
#അല്ലെങ്കിൽ
  _CRTIMP FILE *__cdecl _fdopen(പൂർണ്ണസംഖ്യ _FileHandle,സ്ഥിരം അക്ഷരം *_Mode);
#endif
  പൂർണ്ണസംഖ്യ __cdecl feof(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl ferror(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fflush(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fgetc(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fgetchar(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  അക്ഷരം *__cdecl fgets(അക്ഷരം *_Buf,പൂർണ്ണസംഖ്യ Max_എണ്ണം,FILE *_File);
#ifdef _POSIX_
  പൂർണ്ണസംഖ്യ __cdecl fileno(FILE *_File);
#അല്ലെങ്കിൽ
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP അക്ഷരം *__cdecl _tempnam(സ്ഥിരം അക്ഷരം *_DirName,സ്ഥിരം അക്ഷരം *_FilePrefix);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _flushall(ശൂന്യം);
  FILE *__cdecl fopen(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_Mode);
  FILE *fopen64(സ്ഥിരം അക്ഷരം *filename,സ്ഥിരം അക്ഷരം *mode);
  പൂർണ്ണസംഖ്യ __cdecl fprintf(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl fputc(പൂർണ്ണസംഖ്യ _Ch,FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fputchar(പൂർണ്ണസംഖ്യ _Ch);
  പൂർണ്ണസംഖ്യ __cdecl fputs(സ്ഥിരം അക്ഷരം *_Str,FILE *_File);
  size_t __cdecl fread(ശൂന്യം *_DstBuf,size_t _ElementSize,size_t എണ്ണം_5,FILE *_File);
  FILE *__cdecl freopen(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_Mode,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fscanf(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl fsetpos(FILE *_File,സ്ഥിരം fpos_t *_Pos);
  പൂർണ്ണസംഖ്യ __cdecl fseek(FILE *_File,long _Offset,പൂർണ്ണസംഖ്യ _Origin);
   പൂർണ്ണസംഖ്യ fseeko64(FILE* stream, _off64_t offset, പൂർണ്ണസംഖ്യ whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  പൂർണ്ണസംഖ്യ __cdecl _fseeki64(FILE *_File,__int64 _Offset,പൂർണ്ണസംഖ്യ _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(സ്ഥിരം ശൂന്യം *_Str,size_t _Size,size_t എണ്ണം_5,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl getc(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl getchar(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getmaxstdio(ശൂന്യം);
  അക്ഷരം *__cdecl gets(അക്ഷരം *_Buffer);
  പൂർണ്ണസംഖ്യ __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  ശൂന്യം __cdecl perror(സ്ഥിരം അക്ഷരം *Err_സന്ദേശം);
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(സ്ഥിരം അക്ഷരം *_Command,സ്ഥിരം അക്ഷരം *_Mode);
#എങ്കിൽ !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  പൂർണ്ണസംഖ്യ __cdecl printf(സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl putc(പൂർണ്ണസംഖ്യ _Ch,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl putchar(പൂർണ്ണസംഖ്യ _Ch);
  പൂർണ്ണസംഖ്യ __cdecl puts(സ്ഥിരം അക്ഷരം *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _putw(പൂർണ്ണസംഖ്യ _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  പൂർണ്ണസംഖ്യ __cdecl remove(സ്ഥിരം അക്ഷരം *_Filename);
  പൂർണ്ണസംഖ്യ __cdecl rename(സ്ഥിരം അക്ഷരം *_OldFilename,സ്ഥിരം അക്ഷരം *_NewFilename);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _unlink(സ്ഥിരം അക്ഷരം *_Filename);
#ifndef NO_OLDNAMES
  പൂർണ്ണസംഖ്യ __cdecl unlink(സ്ഥിരം അക്ഷരം *_Filename);
#endif
#endif
  ശൂന്യം __cdecl rewind(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _rmtmp(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl scanf(സ്ഥിരം അക്ഷരം *_Format,...);
  ശൂന്യം __cdecl setbuf(FILE *_File,അക്ഷരം *_Buffer);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _setmaxstdio(പൂർണ്ണസംഖ്യ _Max);
  _CRTIMP unsigned പൂർണ്ണസംഖ്യ __cdecl _set_output_format(unsigned പൂർണ്ണസംഖ്യ _Format);
  _CRTIMP unsigned പൂർണ്ണസംഖ്യ __cdecl _get_output_format(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl setvbuf(FILE *_File,അക്ഷരം *_Buf,പൂർണ്ണസംഖ്യ _Mode,size_t _Size);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scprintf(സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl sscanf(സ്ഥിരം അക്ഷരം *_Src,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snscanf(സ്ഥിരം അക്ഷരം *_Src,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,...);
  FILE *__cdecl tmpfile(ശൂന്യം);
  അക്ഷരം *__cdecl tmpnam(അക്ഷരം *_Buffer);
  പൂർണ്ണസംഖ്യ __cdecl ungetc(പൂർണ്ണസംഖ്യ _Ch,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl vfprintf(FILE *_File,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl vprintf(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma തള്ളുക_macro("vsnprintf")
#pragma തള്ളുക_macro("snprintf")
# undef vsnprintf
# undef snprintf
  ബാഹ്യ
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  പൂർണ്ണസംഖ്യ __mingw_vsnprintf(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  ബാഹ്യ
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  പൂർണ്ണസംഖ്യ __mingw_snprintf(അക്ഷരം* s, size_t n, സ്ഥിരം അക്ഷരം*  format, ...);
  പൂർണ്ണസംഖ്യ __cdecl vsnprintf(അക്ഷരം *_DstBuf,size_t Max_എണ്ണം,സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snprintf(അക്ഷരം *_Dest,size_t എണ്ണം_5,സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnprintf(അക്ഷരം *_Dest,size_t എണ്ണം_5,സ്ഥിരം അക്ഷരം *_Format,va_list _Args);
  പൂർണ്ണസംഖ്യ __cdecl sprintf(അക്ഷരം *_Dest,സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl vsprintf(അക്ഷരം *_Dest,സ്ഥിരം അക്ഷരം *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  പൂർണ്ണസംഖ്യ __cdecl snprintf(അക്ഷരം* s, size_t n, സ്ഥിരം അക്ഷരം*  format, ...);
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl vsnprintf (അക്ഷരം* s, size_t n, സ്ഥിരം അക്ഷരം* format,va_list arg) {
    തിരികെ _vsnprintf ( s, n, format, arg);
  }
  പൂർണ്ണസംഖ്യ __cdecl vscanf(സ്ഥിരം അക്ഷരം * Format, va_list argp);
  പൂർണ്ണസംഖ്യ __cdecl vfscanf (FILE * fp, സ്ഥിരം അക്ഷരം * Format,va_list argp);
  പൂർണ്ണസംഖ്യ __cdecl vsscanf (സ്ഥിരം അക്ഷരം * _Str,സ്ഥിരം അക്ഷരം * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma എടുക്കുക_macro("snprintf")
#pragma എടുക്കുക_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# എങ്കിൽ defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscprintf(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl set_printf_എണ്ണം_output(പൂർണ്ണസംഖ്യ മൂല്യം_2);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl get_printf_എണ്ണം_output(ശൂന്യം);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode);
#അല്ലെങ്കിൽ
  _CRTIMP FILE *__cdecl _wfsopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode,പൂർണ്ണസംഖ്യ _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(ശൂന്യം);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(ശൂന്യം);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,പൂർണ്ണസംഖ്യ Size_In_വാക്കുകൾ,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl fputws(സ്ഥിരം wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _putws(സ്ഥിരം wchar_t *_Str);
  പൂർണ്ണസംഖ്യ __cdecl fwprintf(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl wprintf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _scwprintf(സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl vfwprintf(FILE *_File,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl vwprintf(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl swprintf(wchar_t*, സ്ഥിരം wchar_t*, ...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl vswprintf(wchar_t*, സ്ഥിരം wchar_t*,va_list);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_വാക്കുകൾ,സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwprintf(wchar_t *_Dest,size_t എണ്ണം_5,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vsnwprintf(wchar_t *_Dest,size_t എണ്ണം_5,സ്ഥിരം wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  പൂർണ്ണസംഖ്യ __cdecl snwprintf (wchar_t* s, size_t n, സ്ഥിരം wchar_t*  format, ...);
  __CRT_INLINE പൂർണ്ണസംഖ്യ __cdecl vsnwprintf (wchar_t* s, size_t n, സ്ഥിരം wchar_t* format, va_list arg) { തിരികെ _vsnwprintf(s,n,format,arg); }
  പൂർണ്ണസംഖ്യ __cdecl vwscanf (സ്ഥിരം wchar_t *, va_list);
  പൂർണ്ണസംഖ്യ __cdecl vfwscanf (FILE *,സ്ഥിരം wchar_t *,va_list);
  പൂർണ്ണസംഖ്യ __cdecl vswscanf (സ്ഥിരം wchar_t *,സ്ഥിരം wchar_t *,va_list);
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _swprintf(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vswprintf(wchar_t *_Dest,സ്ഥിരം wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#അന്തര്ഭാവ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(സ്ഥിരം wchar_t *_Directory,സ്ഥിരം wchar_t *_FilePrefix);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vscwprintf(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  പൂർണ്ണസംഖ്യ __cdecl fwscanf(FILE *_File,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl swscanf(സ്ഥിരം wchar_t *_Src,സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _snwscanf(സ്ഥിരം wchar_t *_Src,size_t Max_എണ്ണം,സ്ഥിരം wchar_t *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl wscanf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(പൂർണ്ണസംഖ്യ _FileHandle ,സ്ഥിരം wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP ശൂന്യം __cdecl _wperror(സ്ഥിരം wchar_t *Err_സന്ദേശം);
#endif
  _CRTIMP FILE *__cdecl _wpopen(സ്ഥിരം wchar_t *_Command,സ്ഥിരം wchar_t *_Mode);
#എങ്കിൽ !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wremove(സ്ഥിരം wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#എങ്കിൽ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#അല്ലെങ്കിൽ
  __CRT_INLINE wint_t __cdecl getwchar() { തിരികെ (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { തിരികെ (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (അക്ഷരം)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP ശൂന്യം __cdecl _lock_file(FILE *_File);
  _CRTIMP ശൂന്യം __cdecl _unlock_file(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(ശൂന്യം *_DstBuf,size_t _ElementSize,size_t എണ്ണം_5,FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fseek_nolock(FILE *_File,long _Offset,പൂർണ്ണസംഖ്യ _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,പൂർണ്ണസംഖ്യ _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(സ്ഥിരം ശൂന്യം *_DstBuf,size_t _Size,size_t എണ്ണം_5,FILE *_File);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _ungetc_nolock(പൂർണ്ണസംഖ്യ _Ch,FILE *_File);

#എങ്കിൽ !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  അക്ഷരം *__cdecl tempnam(സ്ഥിരം അക്ഷരം *_Directory,സ്ഥിരം അക്ഷരം *_FilePrefix);
  പൂർണ്ണസംഖ്യ __cdecl fcloseall(ശൂന്യം);
  FILE *__cdecl fdopen(പൂർണ്ണസംഖ്യ _FileHandle,സ്ഥിരം അക്ഷരം *_Format);
  പൂർണ്ണസംഖ്യ __cdecl fgetchar(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl fileno(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl flushall(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl fputchar(പൂർണ്ണസംഖ്യ _Ch);
  പൂർണ്ണസംഖ്യ __cdecl getw(FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl putw(പൂർണ്ണസംഖ്യ _Ch,FILE *_File);
  പൂർണ്ണസംഖ്യ __cdecl rmtmp(ശൂന്യം);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)

#അന്തര്ഭാവ <sec_api/stdio_s.h>

#endif
