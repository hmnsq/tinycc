/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#অন্তর্ভাব <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  কাঠামো _iobuf {
    অক্ষর *_ptr;
    পূর্ণসংখ্যা _cnt;
    অক্ষর *_base;
    পূর্ণসংখ্যা _flag;
    পূর্ণসংখ্যা _file;
    পূর্ণসংখ্যা _charbuf;
    পূর্ণসংখ্যা _bufsiz;
    অক্ষর *_tmpfname;
  };
  প্রকারলেখ কাঠামো _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#অন্যথা
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (আকার(_P_tmpdir) + 12)

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

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  প্রকারলেখ long _off_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারলেখ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  প্রকারলেখ long long _off64_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারলেখ long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(শূন্য);
#অন্যথা
#ifdef _MSVCRT_
বাহ্যিক FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#অন্যথা
বাহ্যিক FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#যদি (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  প্রকারলেখ __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#অন্যথা
  প্রকারলেখ long long fpos_t;
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

  _CRTIMP পূর্ণসংখ্যা __cdecl _filbuf(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _flsbuf(পূর্ণসংখ্যা _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _fsopen(ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_Mode,পূর্ণসংখ্যা _ShFlag);
#endif
  শূন্য __cdecl clearerr(FILE *_File);
  পূর্ণসংখ্যা __cdecl fclose(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fcloseall(শূন্য);
#ifdef _POSIX_
  FILE *__cdecl fdopen(পূর্ণসংখ্যা _FileHandle,ধ্রুবক অক্ষর *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _fdopen(পূর্ণসংখ্যা _FileHandle,ধ্রুবক অক্ষর *_Mode);
#endif
  পূর্ণসংখ্যা __cdecl feof(FILE *_File);
  পূর্ণসংখ্যা __cdecl ferror(FILE *_File);
  পূর্ণসংখ্যা __cdecl fflush(FILE *_File);
  পূর্ণসংখ্যা __cdecl fgetc(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fgetchar(শূন্য);
  পূর্ণসংখ্যা __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  অক্ষর *__cdecl fgets(অক্ষর *_Buf,পূর্ণসংখ্যা Max_গুনতি,FILE *_File);
#ifdef _POSIX_
  পূর্ণসংখ্যা __cdecl fileno(FILE *_File);
#অন্যথা
  _CRTIMP পূর্ণসংখ্যা __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP অক্ষর *__cdecl _tempnam(ধ্রুবক অক্ষর *_DirName,ধ্রুবক অক্ষর *_FilePrefix);
  _CRTIMP পূর্ণসংখ্যা __cdecl _flushall(শূন্য);
  FILE *__cdecl fopen(ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_Mode);
  FILE *fopen64(ধ্রুবক অক্ষর *filename,ধ্রুবক অক্ষর *mode);
  পূর্ণসংখ্যা __cdecl fprintf(FILE *_File,ধ্রুবক অক্ষর *_Format,...);
  পূর্ণসংখ্যা __cdecl fputc(পূর্ণসংখ্যা _Ch,FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fputchar(পূর্ণসংখ্যা _Ch);
  পূর্ণসংখ্যা __cdecl fputs(ধ্রুবক অক্ষর *_Str,FILE *_File);
  আকার_t __cdecl fread(শূন্য *_DstBuf,আকার_t Element_আকার,আকার_t গুনতি_5,FILE *_File);
  FILE *__cdecl freopen(ধ্রুবক অক্ষর *_Filename,ধ্রুবক অক্ষর *_Mode,FILE *_File);
  পূর্ণসংখ্যা __cdecl fscanf(FILE *_File,ধ্রুবক অক্ষর *_Format,...);
  পূর্ণসংখ্যা __cdecl fsetpos(FILE *_File,ধ্রুবক fpos_t *_Pos);
  পূর্ণসংখ্যা __cdecl fseek(FILE *_File,long _Offset,পূর্ণসংখ্যা _Origin);
   পূর্ণসংখ্যা fseeko64(FILE* stream, _off64_t offset, পূর্ণসংখ্যা whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  পূর্ণসংখ্যা __cdecl _fseeki64(FILE *_File,__int64 _Offset,পূর্ণসংখ্যা _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  আকার_t __cdecl fwrite(ধ্রুবক শূন্য *_Str,আকার_t আকার_5,আকার_t গুনতি_5,FILE *_File);
  পূর্ণসংখ্যা __cdecl getc(FILE *_File);
  পূর্ণসংখ্যা __cdecl getchar(শূন্য);
  _CRTIMP পূর্ণসংখ্যা __cdecl _getmaxstdio(শূন্য);
  অক্ষর *__cdecl gets(অক্ষর *বাফার_2);
  পূর্ণসংখ্যা __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  শূন্য __cdecl perror(ধ্রুবক অক্ষর *Err_বার্তা);
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ধ্রুবক অক্ষর *_Command,ধ্রুবক অক্ষর *_Mode);
#যদি !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  পূর্ণসংখ্যা __cdecl printf(ধ্রুবক অক্ষর *_Format,...);
  পূর্ণসংখ্যা __cdecl putc(পূর্ণসংখ্যা _Ch,FILE *_File);
  পূর্ণসংখ্যা __cdecl putchar(পূর্ণসংখ্যা _Ch);
  পূর্ণসংখ্যা __cdecl puts(ধ্রুবক অক্ষর *_Str);
  _CRTIMP পূর্ণসংখ্যা __cdecl _putw(পূর্ণসংখ্যা _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  পূর্ণসংখ্যা __cdecl remove(ধ্রুবক অক্ষর *_Filename);
  পূর্ণসংখ্যা __cdecl rename(ধ্রুবক অক্ষর *_OldFilename,ধ্রুবক অক্ষর *_NewFilename);
  _CRTIMP পূর্ণসংখ্যা __cdecl _unlink(ধ্রুবক অক্ষর *_Filename);
#ifndef NO_OLDNAMES
  পূর্ণসংখ্যা __cdecl unlink(ধ্রুবক অক্ষর *_Filename);
#endif
#endif
  শূন্য __cdecl rewind(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _rmtmp(শূন্য);
  পূর্ণসংখ্যা __cdecl scanf(ধ্রুবক অক্ষর *_Format,...);
  শূন্য __cdecl setbuf(FILE *_File,অক্ষর *বাফার_2);
  _CRTIMP পূর্ণসংখ্যা __cdecl _setmaxstdio(পূর্ণসংখ্যা _Max);
  _CRTIMP unsigned পূর্ণসংখ্যা __cdecl _set_output_format(unsigned পূর্ণসংখ্যা _Format);
  _CRTIMP unsigned পূর্ণসংখ্যা __cdecl _get_output_format(শূন্য);
  পূর্ণসংখ্যা __cdecl setvbuf(FILE *_File,অক্ষর *_Buf,পূর্ণসংখ্যা _Mode,আকার_t আকার_5);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scprintf(ধ্রুবক অক্ষর *_Format,...);
  পূর্ণসংখ্যা __cdecl sscanf(ধ্রুবক অক্ষর *_Src,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snscanf(ধ্রুবক অক্ষর *_Src,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,...);
  FILE *__cdecl tmpfile(শূন্য);
  অক্ষর *__cdecl tmpnam(অক্ষর *বাফার_2);
  পূর্ণসংখ্যা __cdecl ungetc(পূর্ণসংখ্যা _Ch,FILE *_File);
  পূর্ণসংখ্যা __cdecl vfprintf(FILE *_File,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl vprintf(ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ঠেলো_macro("vsnprintf")
#pragma ঠেলো_macro("snprintf")
# undef vsnprintf
# undef snprintf
  বাহ্যিক
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  পূর্ণসংখ্যা __mingw_vsnprintf(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  বাহ্যিক
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  পূর্ণসংখ্যা __mingw_snprintf(অক্ষর* s, আকার_t n, ধ্রুবক অক্ষর*  format, ...);
  পূর্ণসংখ্যা __cdecl vsnprintf(অক্ষর *_DstBuf,আকার_t Max_গুনতি,ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snprintf(অক্ষর *_Dest,আকার_t গুনতি_5,ধ্রুবক অক্ষর *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnprintf(অক্ষর *_Dest,আকার_t গুনতি_5,ধ্রুবক অক্ষর *_Format,va_list _Args);
  পূর্ণসংখ্যা __cdecl sprintf(অক্ষর *_Dest,ধ্রুবক অক্ষর *_Format,...);
  পূর্ণসংখ্যা __cdecl vsprintf(অক্ষর *_Dest,ধ্রুবক অক্ষর *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  পূর্ণসংখ্যা __cdecl snprintf(অক্ষর* s, আকার_t n, ধ্রুবক অক্ষর*  format, ...);
  __CRT_INLINE পূর্ণসংখ্যা __cdecl vsnprintf (অক্ষর* s, আকার_t n, ধ্রুবক অক্ষর* format,va_list arg) {
    ফেরত _vsnprintf ( s, n, format, arg);
  }
  পূর্ণসংখ্যা __cdecl vscanf(ধ্রুবক অক্ষর * Format, va_list argp);
  পূর্ণসংখ্যা __cdecl vfscanf (FILE * fp, ধ্রুবক অক্ষর * Format,va_list argp);
  পূর্ণসংখ্যা __cdecl vsscanf (ধ্রুবক অক্ষর * _Str,ধ্রুবক অক্ষর * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma বের_করো_macro("snprintf")
#pragma বের_করো_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# যদি defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscprintf(ধ্রুবক অক্ষর *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl set_printf_গুনতি_output(পূর্ণসংখ্যা মান_2);
  _CRTIMP পূর্ণসংখ্যা __cdecl get_printf_গুনতি_output(শূন্য);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode,পূর্ণসংখ্যা _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(শূন্য);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(শূন্য);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,পূর্ণসংখ্যা আকার_In_শব্দগুলি,FILE *_File);
  পূর্ণসংখ্যা __cdecl fputws(ধ্রুবক wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP পূর্ণসংখ্যা __cdecl _putws(ধ্রুবক wchar_t *_Str);
  পূর্ণসংখ্যা __cdecl fwprintf(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl wprintf(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _scwprintf(ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl vfwprintf(FILE *_File,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl vwprintf(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl swprintf(wchar_t*, ধ্রুবক wchar_t*, ...);
  _CRTIMP পূর্ণসংখ্যা __cdecl vswprintf(wchar_t*, ধ্রুবক wchar_t*,va_list);
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf_c(wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf_c(wchar_t *_DstBuf,আকার_t আকার_In_শব্দগুলি,ধ্রুবক wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwprintf(wchar_t *_Dest,আকার_t গুনতি_5,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vsnwprintf(wchar_t *_Dest,আকার_t গুনতি_5,ধ্রুবক wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  পূর্ণসংখ্যা __cdecl snwprintf (wchar_t* s, আকার_t n, ধ্রুবক wchar_t*  format, ...);
  __CRT_INLINE পূর্ণসংখ্যা __cdecl vsnwprintf (wchar_t* s, আকার_t n, ধ্রুবক wchar_t* format, va_list arg) { ফেরত _vsnwprintf(s,n,format,arg); }
  পূর্ণসংখ্যা __cdecl vwscanf (ধ্রুবক wchar_t *, va_list);
  পূর্ণসংখ্যা __cdecl vfwscanf (FILE *,ধ্রুবক wchar_t *,va_list);
  পূর্ণসংখ্যা __cdecl vswscanf (ধ্রুবক wchar_t *,ধ্রুবক wchar_t *,va_list);
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _swprintf(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vswprintf(wchar_t *_Dest,ধ্রুবক wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#অন্তর্ভাব <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ধ্রুবক wchar_t *_Directory,ধ্রুবক wchar_t *_FilePrefix);
  _CRTIMP পূর্ণসংখ্যা __cdecl _vscwprintf(ধ্রুবক wchar_t *_Format,va_list _ArgList);
  পূর্ণসংখ্যা __cdecl fwscanf(FILE *_File,ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl swscanf(ধ্রুবক wchar_t *_Src,ধ্রুবক wchar_t *_Format,...);
  _CRTIMP পূর্ণসংখ্যা __cdecl _snwscanf(ধ্রুবক wchar_t *_Src,আকার_t Max_গুনতি,ধ্রুবক wchar_t *_Format,...);
  পূর্ণসংখ্যা __cdecl wscanf(ধ্রুবক wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(পূর্ণসংখ্যা _FileHandle ,ধ্রুবক wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ধ্রুবক wchar_t *_Filename,ধ্রুবক wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুবক wchar_t *Err_বার্তা);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ধ্রুবক wchar_t *_Command,ধ্রুবক wchar_t *_Mode);
#যদি !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP পূর্ণসংখ্যা __cdecl _wremove(ধ্রুবক wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *বাফার_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#যদি !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#অন্যথা
  __CRT_INLINE wint_t __cdecl getwchar() { ফেরত (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { ফেরত (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (অক্ষর)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP শূন্য __cdecl _lock_file(FILE *_File);
  _CRTIMP শূন্য __cdecl _unlock_file(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP আকার_t __cdecl _fread_nolock(শূন্য *_DstBuf,আকার_t Element_আকার,আকার_t গুনতি_5,FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fseek_nolock(FILE *_File,long _Offset,পূর্ণসংখ্যা _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,পূর্ণসংখ্যা _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP আকার_t __cdecl _fwrite_nolock(ধ্রুবক শূন্য *_DstBuf,আকার_t আকার_5,আকার_t গুনতি_5,FILE *_File);
  _CRTIMP পূর্ণসংখ্যা __cdecl _ungetc_nolock(পূর্ণসংখ্যা _Ch,FILE *_File);

#যদি !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  অক্ষর *__cdecl tempnam(ধ্রুবক অক্ষর *_Directory,ধ্রুবক অক্ষর *_FilePrefix);
  পূর্ণসংখ্যা __cdecl fcloseall(শূন্য);
  FILE *__cdecl fdopen(পূর্ণসংখ্যা _FileHandle,ধ্রুবক অক্ষর *_Format);
  পূর্ণসংখ্যা __cdecl fgetchar(শূন্য);
  পূর্ণসংখ্যা __cdecl fileno(FILE *_File);
  পূর্ণসংখ্যা __cdecl flushall(শূন্য);
  পূর্ণসংখ্যা __cdecl fputchar(পূর্ণসংখ্যা _Ch);
  পূর্ণসংখ্যা __cdecl getw(FILE *_File);
  পূর্ণসংখ্যা __cdecl putw(পূর্ণসংখ্যা _Ch,FILE *_File);
  পূর্ণসংখ্যা __cdecl rmtmp(শূন্য);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/stdio_s.h>

#endif
