/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#અન્તર્ભાવ <_mingw.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  સંરચના _iobuf {
    અક્ષર *_ptr;
    પૂર્ણાંક _cnt;
    અક્ષર *_base;
    પૂર્ણાંક _flag;
    પૂર્ણાંક _file;
    પૂર્ણાંક _charbuf;
    પૂર્ણાંક _bufsiz;
    અક્ષર *_tmpfname;
  };
  પ્રકારવ્યાખ્યા સંરચના _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#નહીંતર
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (કદ(_P_tmpdir) + 12)

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

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  પ્રકારવ્યાખ્યા long _off_t;
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  પ્રકારવ્યાખ્યા long long _off64_t;
#જો !defined(NO_OLDNAMES) || defined(_POSIX)
  પ્રકારવ્યાખ્યા long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(શૂન્ય);
#નહીંતર
#ifdef _MSVCRT_
બાહ્ય FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#નહીંતર
બાહ્ય FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#જો (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  પ્રકારવ્યાખ્યા __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#નહીંતર
  પ્રકારવ્યાખ્યા long long fpos_t;
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

  _CRTIMP પૂર્ણાંક __cdecl _filbuf(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _flsbuf(પૂર્ણાંક _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(અચલ અક્ષર *_Filename,અચલ અક્ષર *_Mode);
#નહીંતર
  _CRTIMP FILE *__cdecl _fsopen(અચલ અક્ષર *_Filename,અચલ અક્ષર *_Mode,પૂર્ણાંક _ShFlag);
#endif
  શૂન્ય __cdecl clearerr(FILE *_File);
  પૂર્ણાંક __cdecl fclose(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fcloseall(શૂન્ય);
#ifdef _POSIX_
  FILE *__cdecl fdopen(પૂર્ણાંક _FileHandle,અચલ અક્ષર *_Mode);
#નહીંતર
  _CRTIMP FILE *__cdecl _fdopen(પૂર્ણાંક _FileHandle,અચલ અક્ષર *_Mode);
#endif
  પૂર્ણાંક __cdecl feof(FILE *_File);
  પૂર્ણાંક __cdecl ferror(FILE *_File);
  પૂર્ણાંક __cdecl fflush(FILE *_File);
  પૂર્ણાંક __cdecl fgetc(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fgetchar(શૂન્ય);
  પૂર્ણાંક __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  અક્ષર *__cdecl fgets(અક્ષર *_Buf,પૂર્ણાંક Max_ગણતરી,FILE *_File);
#ifdef _POSIX_
  પૂર્ણાંક __cdecl fileno(FILE *_File);
#નહીંતર
  _CRTIMP પૂર્ણાંક __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP અક્ષર *__cdecl _tempnam(અચલ અક્ષર *_DirName,અચલ અક્ષર *_FilePrefix);
  _CRTIMP પૂર્ણાંક __cdecl _flushall(શૂન્ય);
  FILE *__cdecl fopen(અચલ અક્ષર *_Filename,અચલ અક્ષર *_Mode);
  FILE *fopen64(અચલ અક્ષર *filename,અચલ અક્ષર *mode);
  પૂર્ણાંક __cdecl fprintf(FILE *_File,અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl fputc(પૂર્ણાંક _Ch,FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fputchar(પૂર્ણાંક _Ch);
  પૂર્ણાંક __cdecl fputs(અચલ અક્ષર *_Str,FILE *_File);
  size_t __cdecl fread(શૂન્ય *_DstBuf,size_t _ElementSize,size_t ગણતરી_5,FILE *_File);
  FILE *__cdecl freopen(અચલ અક્ષર *_Filename,અચલ અક્ષર *_Mode,FILE *_File);
  પૂર્ણાંક __cdecl fscanf(FILE *_File,અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl fsetpos(FILE *_File,અચલ fpos_t *_Pos);
  પૂર્ણાંક __cdecl fseek(FILE *_File,long _Offset,પૂર્ણાંક _Origin);
   પૂર્ણાંક fseeko64(FILE* stream, _off64_t offset, પૂર્ણાંક whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  પૂર્ણાંક __cdecl _fseeki64(FILE *_File,__int64 _Offset,પૂર્ણાંક _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(અચલ શૂન્ય *_Str,size_t _Size,size_t ગણતરી_5,FILE *_File);
  પૂર્ણાંક __cdecl getc(FILE *_File);
  પૂર્ણાંક __cdecl getchar(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _getmaxstdio(શૂન્ય);
  અક્ષર *__cdecl gets(અક્ષર *_Buffer);
  પૂર્ણાંક __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  શૂન્ય __cdecl perror(અચલ અક્ષર *Err_સંદેશ);
#endif
  _CRTIMP પૂર્ણાંક __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(અચલ અક્ષર *_Command,અચલ અક્ષર *_Mode);
#જો !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  પૂર્ણાંક __cdecl printf(અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl putc(પૂર્ણાંક _Ch,FILE *_File);
  પૂર્ણાંક __cdecl putchar(પૂર્ણાંક _Ch);
  પૂર્ણાંક __cdecl puts(અચલ અક્ષર *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _putw(પૂર્ણાંક _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  પૂર્ણાંક __cdecl remove(અચલ અક્ષર *_Filename);
  પૂર્ણાંક __cdecl rename(અચલ અક્ષર *_OldFilename,અચલ અક્ષર *_NewFilename);
  _CRTIMP પૂર્ણાંક __cdecl _unlink(અચલ અક્ષર *_Filename);
#ifndef NO_OLDNAMES
  પૂર્ણાંક __cdecl unlink(અચલ અક્ષર *_Filename);
#endif
#endif
  શૂન્ય __cdecl rewind(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _rmtmp(શૂન્ય);
  પૂર્ણાંક __cdecl scanf(અચલ અક્ષર *_Format,...);
  શૂન્ય __cdecl setbuf(FILE *_File,અક્ષર *_Buffer);
  _CRTIMP પૂર્ણાંક __cdecl _setmaxstdio(પૂર્ણાંક _Max);
  _CRTIMP unsigned પૂર્ણાંક __cdecl _set_output_format(unsigned પૂર્ણાંક _Format);
  _CRTIMP unsigned પૂર્ણાંક __cdecl _get_output_format(શૂન્ય);
  પૂર્ણાંક __cdecl setvbuf(FILE *_File,અક્ષર *_Buf,પૂર્ણાંક _Mode,size_t _Size);
  _CRTIMP પૂર્ણાંક __cdecl _scprintf(અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl sscanf(અચલ અક્ષર *_Src,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _snscanf(અચલ અક્ષર *_Src,size_t Max_ગણતરી,અચલ અક્ષર *_Format,...);
  FILE *__cdecl tmpfile(શૂન્ય);
  અક્ષર *__cdecl tmpnam(અક્ષર *_Buffer);
  પૂર્ણાંક __cdecl ungetc(પૂર્ણાંક _Ch,FILE *_File);
  પૂર્ણાંક __cdecl vfprintf(FILE *_File,અચલ અક્ષર *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl vprintf(અચલ અક્ષર *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ધકેલો_macro("vsnprintf")
#pragma ધકેલો_macro("snprintf")
# undef vsnprintf
# undef snprintf
  બાહ્ય
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  પૂર્ણાંક __mingw_vsnprintf(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,va_list _ArgList);
  બાહ્ય
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  પૂર્ણાંક __mingw_snprintf(અક્ષર* s, size_t n, અચલ અક્ષર*  format, ...);
  પૂર્ણાંક __cdecl vsnprintf(અક્ષર *_DstBuf,size_t Max_ગણતરી,અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snprintf(અક્ષર *_Dest,size_t ગણતરી_5,અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnprintf(અક્ષર *_Dest,size_t ગણતરી_5,અચલ અક્ષર *_Format,va_list _Args);
  પૂર્ણાંક __cdecl sprintf(અક્ષર *_Dest,અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl vsprintf(અક્ષર *_Dest,અચલ અક્ષર *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  પૂર્ણાંક __cdecl snprintf(અક્ષર* s, size_t n, અચલ અક્ષર*  format, ...);
  __CRT_INLINE પૂર્ણાંક __cdecl vsnprintf (અક્ષર* s, size_t n, અચલ અક્ષર* format,va_list arg) {
    પાછા _vsnprintf ( s, n, format, arg);
  }
  પૂર્ણાંક __cdecl vscanf(અચલ અક્ષર * Format, va_list argp);
  પૂર્ણાંક __cdecl vfscanf (FILE * fp, અચલ અક્ષર * Format,va_list argp);
  પૂર્ણાંક __cdecl vsscanf (અચલ અક્ષર * _Str,અચલ અક્ષર * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma કાઢો_macro("snprintf")
#pragma કાઢો_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# જો defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP પૂર્ણાંક __cdecl _vscprintf(અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl set_printf_ગણતરી_output(પૂર્ણાંક કિંમત_2);
  _CRTIMP પૂર્ણાંક __cdecl get_printf_ગણતરી_output(શૂન્ય);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode);
#નહીંતર
  _CRTIMP FILE *__cdecl _wfsopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode,પૂર્ણાંક _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(શૂન્ય);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(શૂન્ય);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,પૂર્ણાંક Size_In_શબ્દો,FILE *_File);
  પૂર્ણાંક __cdecl fputws(અચલ wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP પૂર્ણાંક __cdecl _putws(અચલ wchar_t *_Str);
  પૂર્ણાંક __cdecl fwprintf(FILE *_File,અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl wprintf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _scwprintf(અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl vfwprintf(FILE *_File,અચલ wchar_t *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl vwprintf(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl swprintf(wchar_t*, અચલ wchar_t*, ...);
  _CRTIMP પૂર્ણાંક __cdecl vswprintf(wchar_t*, અચલ wchar_t*,va_list);
  _CRTIMP પૂર્ણાંક __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_શબ્દો,અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _snwprintf(wchar_t *_Dest,size_t ગણતરી_5,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vsnwprintf(wchar_t *_Dest,size_t ગણતરી_5,અચલ wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  પૂર્ણાંક __cdecl snwprintf (wchar_t* s, size_t n, અચલ wchar_t*  format, ...);
  __CRT_INLINE પૂર્ણાંક __cdecl vsnwprintf (wchar_t* s, size_t n, અચલ wchar_t* format, va_list arg) { પાછા _vsnwprintf(s,n,format,arg); }
  પૂર્ણાંક __cdecl vwscanf (અચલ wchar_t *, va_list);
  પૂર્ણાંક __cdecl vfwscanf (FILE *,અચલ wchar_t *,va_list);
  પૂર્ણાંક __cdecl vswscanf (અચલ wchar_t *,અચલ wchar_t *,va_list);
#endif
  _CRTIMP પૂર્ણાંક __cdecl _swprintf(wchar_t *_Dest,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vswprintf(wchar_t *_Dest,અચલ wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#અન્તર્ભાવ <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(અચલ wchar_t *_Directory,અચલ wchar_t *_FilePrefix);
  _CRTIMP પૂર્ણાંક __cdecl _vscwprintf(અચલ wchar_t *_Format,va_list _ArgList);
  પૂર્ણાંક __cdecl fwscanf(FILE *_File,અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl swscanf(અચલ wchar_t *_Src,અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _snwscanf(અચલ wchar_t *_Src,size_t Max_ગણતરી,અચલ wchar_t *_Format,...);
  પૂર્ણાંક __cdecl wscanf(અચલ wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(પૂર્ણાંક _FileHandle ,અચલ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(અચલ wchar_t *_Filename,અચલ wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP શૂન્ય __cdecl _wperror(અચલ wchar_t *Err_સંદેશ);
#endif
  _CRTIMP FILE *__cdecl _wpopen(અચલ wchar_t *_Command,અચલ wchar_t *_Mode);
#જો !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP પૂર્ણાંક __cdecl _wremove(અચલ wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#જો !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#નહીંતર
  __CRT_INLINE wint_t __cdecl getwchar() { પાછા (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { પાછા (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (અક્ષર)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP શૂન્ય __cdecl _lock_file(FILE *_File);
  _CRTIMP શૂન્ય __cdecl _unlock_file(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(શૂન્ય *_DstBuf,size_t _ElementSize,size_t ગણતરી_5,FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fseek_nolock(FILE *_File,long _Offset,પૂર્ણાંક _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,પૂર્ણાંક _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(અચલ શૂન્ય *_DstBuf,size_t _Size,size_t ગણતરી_5,FILE *_File);
  _CRTIMP પૂર્ણાંક __cdecl _ungetc_nolock(પૂર્ણાંક _Ch,FILE *_File);

#જો !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  અક્ષર *__cdecl tempnam(અચલ અક્ષર *_Directory,અચલ અક્ષર *_FilePrefix);
  પૂર્ણાંક __cdecl fcloseall(શૂન્ય);
  FILE *__cdecl fdopen(પૂર્ણાંક _FileHandle,અચલ અક્ષર *_Format);
  પૂર્ણાંક __cdecl fgetchar(શૂન્ય);
  પૂર્ણાંક __cdecl fileno(FILE *_File);
  પૂર્ણાંક __cdecl flushall(શૂન્ય);
  પૂર્ણાંક __cdecl fputchar(પૂર્ણાંક _Ch);
  પૂર્ણાંક __cdecl getw(FILE *_File);
  પૂર્ણાંક __cdecl putw(પૂર્ણાંક _Ch,FILE *_File);
  પૂર્ણાંક __cdecl rmtmp(શૂન્ય);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)

#અન્તર્ભાવ <sec_api/stdio_s.h>

#endif
