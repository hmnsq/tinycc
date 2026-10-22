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
বাহ্য "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  সংরচনা _iobuf {
    বর্ণ *_ptr;
    পূর্ণাঙ্ক _cnt;
    বর্ণ *_base;
    পূর্ণাঙ্ক _flag;
    পূর্ণাঙ্ক _file;
    পূর্ণাঙ্ক _charbuf;
    পূর্ণাঙ্ক _bufsiz;
    বর্ণ *_tmpfname;
  };
  প্রকারনির্দেশ সংরচনা _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#অন্যথা
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (পরিমাণ(_P_tmpdir) + 12)

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

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  প্রকারনির্দেশ long _off_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  প্রকারনির্দেশ long long _off64_t;
#যদি !defined(NO_OLDNAMES) || defined(_POSIX)
  প্রকারনির্দেশ long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(শূন্য);
#অন্যথা
#ifdef _MSVCRT_
বাহ্য FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#অন্যথা
বাহ্য FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#যদি (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  প্রকারনির্দেশ __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#অন্যথা
  প্রকারনির্দেশ long long fpos_t;
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

  _CRTIMP পূর্ণাঙ্ক __cdecl _filbuf(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _flsbuf(পূর্ণাঙ্ক _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _fsopen(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_Mode,পূর্ণাঙ্ক _ShFlag);
#endif
  শূন্য __cdecl clearerr(FILE *_File);
  পূর্ণাঙ্ক __cdecl fclose(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fcloseall(শূন্য);
#ifdef _POSIX_
  FILE *__cdecl fdopen(পূর্ণাঙ্ক _FileHandle,ধ্রুব বর্ণ *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _fdopen(পূর্ণাঙ্ক _FileHandle,ধ্রুব বর্ণ *_Mode);
#endif
  পূর্ণাঙ্ক __cdecl feof(FILE *_File);
  পূর্ণাঙ্ক __cdecl ferror(FILE *_File);
  পূর্ণাঙ্ক __cdecl fflush(FILE *_File);
  পূর্ণাঙ্ক __cdecl fgetc(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fgetchar(শূন্য);
  পূর্ণাঙ্ক __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  বর্ণ *__cdecl fgets(বর্ণ *_Buf,পূর্ণাঙ্ক Max_গুনতি,FILE *_File);
#ifdef _POSIX_
  পূর্ণাঙ্ক __cdecl fileno(FILE *_File);
#অন্যথা
  _CRTIMP পূর্ণাঙ্ক __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP বর্ণ *__cdecl _tempnam(ধ্রুব বর্ণ *_DirName,ধ্রুব বর্ণ *_FilePrefix);
  _CRTIMP পূর্ণাঙ্ক __cdecl _flushall(শূন্য);
  FILE *__cdecl fopen(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_Mode);
  FILE *fopen64(ধ্রুব বর্ণ *filename,ধ্রুব বর্ণ *mode);
  পূর্ণাঙ্ক __cdecl fprintf(FILE *_File,ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl fputc(পূর্ণাঙ্ক _Ch,FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fputchar(পূর্ণাঙ্ক _Ch);
  পূর্ণাঙ্ক __cdecl fputs(ধ্রুব বর্ণ *_Str,FILE *_File);
  size_t __cdecl fread(শূন্য *_DstBuf,size_t _ElementSize,size_t গুনতি_5,FILE *_File);
  FILE *__cdecl freopen(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_Mode,FILE *_File);
  পূর্ণাঙ্ক __cdecl fscanf(FILE *_File,ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl fsetpos(FILE *_File,ধ্রুব fpos_t *_Pos);
  পূর্ণাঙ্ক __cdecl fseek(FILE *_File,long _Offset,পূর্ণাঙ্ক _Origin);
   পূর্ণাঙ্ক fseeko64(FILE* stream, _off64_t offset, পূর্ণাঙ্ক whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  পূর্ণাঙ্ক __cdecl _fseeki64(FILE *_File,__int64 _Offset,পূর্ণাঙ্ক _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(ধ্রুব শূন্য *_Str,size_t _Size,size_t গুনতি_5,FILE *_File);
  পূর্ণাঙ্ক __cdecl getc(FILE *_File);
  পূর্ণাঙ্ক __cdecl getchar(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getmaxstdio(শূন্য);
  বর্ণ *__cdecl gets(বর্ণ *_Buffer);
  পূর্ণাঙ্ক __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  শূন্য __cdecl perror(ধ্রুব বর্ণ *Err_বার্তা);
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ধ্রুব বর্ণ *_Command,ধ্রুব বর্ণ *_Mode);
#যদি !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  পূর্ণাঙ্ক __cdecl printf(ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl putc(পূর্ণাঙ্ক _Ch,FILE *_File);
  পূর্ণাঙ্ক __cdecl putchar(পূর্ণাঙ্ক _Ch);
  পূর্ণাঙ্ক __cdecl puts(ধ্রুব বর্ণ *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _putw(পূর্ণাঙ্ক _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  পূর্ণাঙ্ক __cdecl remove(ধ্রুব বর্ণ *_Filename);
  পূর্ণাঙ্ক __cdecl rename(ধ্রুব বর্ণ *_OldFilename,ধ্রুব বর্ণ *_NewFilename);
  _CRTIMP পূর্ণাঙ্ক __cdecl _unlink(ধ্রুব বর্ণ *_Filename);
#ifndef NO_OLDNAMES
  পূর্ণাঙ্ক __cdecl unlink(ধ্রুব বর্ণ *_Filename);
#endif
#endif
  শূন্য __cdecl rewind(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _rmtmp(শূন্য);
  পূর্ণাঙ্ক __cdecl scanf(ধ্রুব বর্ণ *_Format,...);
  শূন্য __cdecl setbuf(FILE *_File,বর্ণ *_Buffer);
  _CRTIMP পূর্ণাঙ্ক __cdecl _setmaxstdio(পূর্ণাঙ্ক _Max);
  _CRTIMP unsigned পূর্ণাঙ্ক __cdecl _set_output_format(unsigned পূর্ণাঙ্ক _Format);
  _CRTIMP unsigned পূর্ণাঙ্ক __cdecl _get_output_format(শূন্য);
  পূর্ণাঙ্ক __cdecl setvbuf(FILE *_File,বর্ণ *_Buf,পূর্ণাঙ্ক _Mode,size_t _Size);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scprintf(ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl sscanf(ধ্রুব বর্ণ *_Src,ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snscanf(ধ্রুব বর্ণ *_Src,size_t Max_গুনতি,ধ্রুব বর্ণ *_Format,...);
  FILE *__cdecl tmpfile(শূন্য);
  বর্ণ *__cdecl tmpnam(বর্ণ *_Buffer);
  পূর্ণাঙ্ক __cdecl ungetc(পূর্ণাঙ্ক _Ch,FILE *_File);
  পূর্ণাঙ্ক __cdecl vfprintf(FILE *_File,ধ্রুব বর্ণ *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl vprintf(ধ্রুব বর্ণ *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ঠেলো_macro("vsnprintf")
#pragma ঠেলো_macro("snprintf")
# undef vsnprintf
# undef snprintf
  বাহ্য
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  পূর্ণাঙ্ক __mingw_vsnprintf(বর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুব বর্ণ *_Format,va_list _ArgList);
  বাহ্য
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  পূর্ণাঙ্ক __mingw_snprintf(বর্ণ* s, size_t n, ধ্রুব বর্ণ*  format, ...);
  পূর্ণাঙ্ক __cdecl vsnprintf(বর্ণ *_DstBuf,size_t Max_গুনতি,ধ্রুব বর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snprintf(বর্ণ *_Dest,size_t গুনতি_5,ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnprintf(বর্ণ *_Dest,size_t গুনতি_5,ধ্রুব বর্ণ *_Format,va_list _Args);
  পূর্ণাঙ্ক __cdecl sprintf(বর্ণ *_Dest,ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl vsprintf(বর্ণ *_Dest,ধ্রুব বর্ণ *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  পূর্ণাঙ্ক __cdecl snprintf(বর্ণ* s, size_t n, ধ্রুব বর্ণ*  format, ...);
  __CRT_INLINE পূর্ণাঙ্ক __cdecl vsnprintf (বর্ণ* s, size_t n, ধ্রুব বর্ণ* format,va_list arg) {
    প্রত্যাগম _vsnprintf ( s, n, format, arg);
  }
  পূর্ণাঙ্ক __cdecl vscanf(ধ্রুব বর্ণ * Format, va_list argp);
  পূর্ণাঙ্ক __cdecl vfscanf (FILE * fp, ধ্রুব বর্ণ * Format,va_list argp);
  পূর্ণাঙ্ক __cdecl vsscanf (ধ্রুব বর্ণ * _Str,ধ্রুব বর্ণ * Format,va_list argp);
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
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscprintf(ধ্রুব বর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl set_printf_গুনতি_output(পূর্ণাঙ্ক মান_2);
  _CRTIMP পূর্ণাঙ্ক __cdecl get_printf_গুনতি_output(শূন্য);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode);
#অন্যথা
  _CRTIMP FILE *__cdecl _wfsopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode,পূর্ণাঙ্ক _ShFlag);
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
  wchar_t *__cdecl fgetws(wchar_t *_Dst,পূর্ণাঙ্ক Size_In_শব্দগুলি,FILE *_File);
  পূর্ণাঙ্ক __cdecl fputws(ধ্রুব wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP পূর্ণাঙ্ক __cdecl _putws(ধ্রুব wchar_t *_Str);
  পূর্ণাঙ্ক __cdecl fwprintf(FILE *_File,ধ্রুব wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl wprintf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _scwprintf(ধ্রুব wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl vfwprintf(FILE *_File,ধ্রুব wchar_t *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl vwprintf(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl swprintf(wchar_t*, ধ্রুব wchar_t*, ...);
  _CRTIMP পূর্ণাঙ্ক __cdecl vswprintf(wchar_t*, ধ্রুব wchar_t*,va_list);
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_শব্দগুলি,ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwprintf(wchar_t *_Dest,size_t গুনতি_5,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vsnwprintf(wchar_t *_Dest,size_t গুনতি_5,ধ্রুব wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  পূর্ণাঙ্ক __cdecl snwprintf (wchar_t* s, size_t n, ধ্রুব wchar_t*  format, ...);
  __CRT_INLINE পূর্ণাঙ্ক __cdecl vsnwprintf (wchar_t* s, size_t n, ধ্রুব wchar_t* format, va_list arg) { প্রত্যাগম _vsnwprintf(s,n,format,arg); }
  পূর্ণাঙ্ক __cdecl vwscanf (ধ্রুব wchar_t *, va_list);
  পূর্ণাঙ্ক __cdecl vfwscanf (FILE *,ধ্রুব wchar_t *,va_list);
  পূর্ণাঙ্ক __cdecl vswscanf (ধ্রুব wchar_t *,ধ্রুব wchar_t *,va_list);
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _swprintf(wchar_t *_Dest,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vswprintf(wchar_t *_Dest,ধ্রুব wchar_t *_Format,va_list _Args);

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

  _CRTIMP wchar_t *__cdecl _wtempnam(ধ্রুব wchar_t *_Directory,ধ্রুব wchar_t *_FilePrefix);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vscwprintf(ধ্রুব wchar_t *_Format,va_list _ArgList);
  পূর্ণাঙ্ক __cdecl fwscanf(FILE *_File,ধ্রুব wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl swscanf(ধ্রুব wchar_t *_Src,ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _snwscanf(ধ্রুব wchar_t *_Src,size_t Max_গুনতি,ধ্রুব wchar_t *_Format,...);
  পূর্ণাঙ্ক __cdecl wscanf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(পূর্ণাঙ্ক _FileHandle ,ধ্রুব wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP শূন্য __cdecl _wperror(ধ্রুব wchar_t *Err_বার্তা);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ধ্রুব wchar_t *_Command,ধ্রুব wchar_t *_Mode);
#যদি !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP পূর্ণাঙ্ক __cdecl _wremove(ধ্রুব wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#যদি !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#অন্যথা
  __CRT_INLINE wint_t __cdecl getwchar() { প্রত্যাগম (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { প্রত্যাগম (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (বর্ণ)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP শূন্য __cdecl _lock_file(FILE *_File);
  _CRTIMP শূন্য __cdecl _unlock_file(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(শূন্য *_DstBuf,size_t _ElementSize,size_t গুনতি_5,FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fseek_nolock(FILE *_File,long _Offset,পূর্ণাঙ্ক _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,পূর্ণাঙ্ক _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(ধ্রুব শূন্য *_DstBuf,size_t _Size,size_t গুনতি_5,FILE *_File);
  _CRTIMP পূর্ণাঙ্ক __cdecl _ungetc_nolock(পূর্ণাঙ্ক _Ch,FILE *_File);

#যদি !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  বর্ণ *__cdecl tempnam(ধ্রুব বর্ণ *_Directory,ধ্রুব বর্ণ *_FilePrefix);
  পূর্ণাঙ্ক __cdecl fcloseall(শূন্য);
  FILE *__cdecl fdopen(পূর্ণাঙ্ক _FileHandle,ধ্রুব বর্ণ *_Format);
  পূর্ণাঙ্ক __cdecl fgetchar(শূন্য);
  পূর্ণাঙ্ক __cdecl fileno(FILE *_File);
  পূর্ণাঙ্ক __cdecl flushall(শূন্য);
  পূর্ণাঙ্ক __cdecl fputchar(পূর্ণাঙ্ক _Ch);
  পূর্ণাঙ্ক __cdecl getw(FILE *_File);
  পূর্ণাঙ্ক __cdecl putw(পূর্ণাঙ্ক _Ch,FILE *_File);
  পূর্ণাঙ্ক __cdecl rmtmp(শূন্য);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)

#অন্তর্ভাব <sec_api/stdio_s.h>

#endif
