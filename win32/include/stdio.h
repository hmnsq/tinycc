/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_STDIO
#تعریف_کن _INC_STDIO

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#تعریف_کن BUFSIZ 512
#تعریف_کن _NFILE _NSTREAM_
#تعریف_کن _NSTREAM_ 512
#تعریف_کن _IOB_ENTRIES 20
#تعریف_کن EOF (-1)

#اگر_تعریف_نشده _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *پایه_4;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#تعریف_کن _FILE_DEFINED
#پایان_اگر

#اگر_تعریف_شده _POSIX_
#تعریف_کن _P_tmpdir "/"
#تعریف_کن _wP_tmpdir L"/"
#وإلا
#تعریف_کن _P_tmpdir "\\"
#تعریف_کن _wP_tmpdir L"\\"
#پایان_اگر

#تعریف_کن L_tmpnam (حجم(_P_tmpdir) + 12)

#اگر_تعریف_شده _POSIX_
#تعریف_کن L_ctermid 9
#تعریف_کن L_cuserid 32
#پایان_اگر

#تعریف_کن SEEK_CUR 1
#تعریف_کن SEEK_END 2
#تعریف_کن SEEK_SET 0

#تعریف_کن STDIN_FILENO    0
#تعریف_کن STDOUT_FILENO   1
#تعریف_کن STDERR_FILENO   2

#تعریف_کن FILENAME_MAX 260
#تعریف_کن FOPEN_MAX 20
#تعریف_کن _SYS_OPEN 20
#تعریف_کن TMP_MAX 32767

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF_T_DEFINED
#تعریف_کن _OFF_T_DEFINED
#اگر_تعریف_نشده _OFF_T_
#تعریف_کن _OFF_T_
  تعريفنوع دراز _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز off_t;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _OFF64_T_DEFINED
#تعریف_کن _OFF64_T_DEFINED
  تعريفنوع دراز دراز _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع دراز دراز off64_t;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _STDIO_DEFINED
#اگر_تعریف_شده _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#اگر_تعریف_شده _MSVCRT_
خارجي FILE _iob[];     /* A pointer to an array of FILE */
#تعریف_کن __iob_func()    (_iob)
#وإلا
خارجي FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#تعریف_کن __iob_func()    (*_imp___iob)
#تعریف_کن _iob __iob_func()
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _FPOS_T_DEFINED
#تعریف_کن _FPOS_T_DEFINED
#لغو_تعریف _FPOSOFF

#إذا (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_بیتها >= 64
  تعريفنوع __int64 fpos_t;
#تعریف_کن _FPOSOFF(fp) ((دراز)(fp))
#وإلا
  تعريفنوع دراز دراز fpos_t;
#تعریف_کن _FPOSOFF(fp) ((دراز)(fp))
#پایان_اگر

#پایان_اگر

#اگر_تعریف_نشده _STDSTREAM_DEFINED
#تعریف_کن _STDSTREAM_DEFINED

#تعریف_کن stdin (&__iob_func()[0])
#تعریف_کن stdout (&__iob_func()[1])
#تعریف_کن stderr (&__iob_func()[2])
#پایان_اگر

#تعریف_کن _IOREAD 0x0001
#تعریف_کن _IOWRT 0x0002

#تعریف_کن _IOFBF 0x0000
#تعریف_کن _IOLBF 0x0040
#تعریف_کن _IONBF 0x0004

#تعریف_کن _IOMYBUF 0x0008
#تعریف_کن _IOEOF 0x0010
#تعریف_کن _IOERR 0x0020
#تعریف_کن _IOSTRG 0x0040
#تعریف_کن _IORW 0x0080
#اگر_تعریف_شده _POSIX_
#تعریف_کن _IOAPPEND 0x0200
#پایان_اگر

#تعریف_کن _TWO_DIGIT_EXPONENT 0x1

#اگر_تعریف_نشده _STDIO_DEFINED

  _CRTIMP صحيح __cdecl _filbuf(FILE *_File);
  _CRTIMP صحيح __cdecl _flsbuf(صحيح _Ch,FILE *_File);
#اگر_تعریف_شده _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *نما_3);
#وإلا
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *نما_3,صحيح _ShFlag);
#پایان_اگر
  فراغ __cdecl clearerr(FILE *_File);
  صحيح __cdecl fclose(FILE *_File);
  _CRTIMP صحيح __cdecl _fcloseall(فراغ);
#اگر_تعریف_شده _POSIX_
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *نما_3);
#وإلا
  _CRTIMP FILE *__cdecl _fdopen(صحيح _FileHandle,ثابت حرف *نما_3);
#پایان_اگر
  صحيح __cdecl feof(FILE *_File);
  صحيح __cdecl ferror(FILE *_File);
  صحيح __cdecl fflush(FILE *_File);
  صحيح __cdecl fgetc(FILE *_File);
  _CRTIMP صحيح __cdecl _fgetchar(فراغ);
  صحيح __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  حرف *__cdecl fgets(حرف *_Buf,صحيح Max_شمار,FILE *_File);
#اگر_تعریف_شده _POSIX_
  صحيح __cdecl fileno(FILE *_File);
#وإلا
  _CRTIMP صحيح __cdecl _fileno(FILE *_File);
#پایان_اگر
  _CRTIMP حرف *__cdecl _tempnam(ثابت حرف *_DirName,ثابت حرف *File_پیشوند);
  _CRTIMP صحيح __cdecl _flushall(فراغ);
  FILE *__cdecl fopen(ثابت حرف *_Filename,ثابت حرف *نما_3);
  FILE *fopen64(ثابت حرف *filename,ثابت حرف *نما);
  صحيح __cdecl fprintf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fputc(صحيح _Ch,FILE *_File);
  _CRTIMP صحيح __cdecl _fputchar(صحيح _Ch);
  صحيح __cdecl fputs(ثابت حرف *_Str,FILE *_File);
  اندازه_t __cdecl fread(فراغ *_DstBuf,اندازه_t Element_اندازه,اندازه_t شمار_5,FILE *_File);
  FILE *__cdecl freopen(ثابت حرف *_Filename,ثابت حرف *نما_3,FILE *_File);
  صحيح __cdecl fscanf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fsetpos(FILE *_File,ثابت fpos_t *_Pos);
  صحيح __cdecl fseek(FILE *_File,دراز جابه_جایی_2,صحيح _Origin);
   صحيح fseeko64(FILE* جریان, _off64_t جابه_جایی, صحيح whence);
  دراز __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * جریان);
  صحيح __cdecl _fseeki64(FILE *_File,__int64 جابه_جایی_2,صحيح _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  اندازه_t __cdecl fwrite(ثابت فراغ *_Str,اندازه_t اندازه_4,اندازه_t شمار_5,FILE *_File);
  صحيح __cdecl getc(FILE *_File);
  صحيح __cdecl getchar(فراغ);
  _CRTIMP صحيح __cdecl _getmaxstdio(فراغ);
  حرف *__cdecl gets(حرف *میانگیر_2);
  صحيح __cdecl _getw(FILE *_File);
#اگر_تعریف_نشده _CRT_PERROR_DEFINED
#تعریف_کن _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_پیام);
#پایان_اگر
  _CRTIMP صحيح __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ثابت حرف *_Command,ثابت حرف *نما_3);
#إذا !defined(NO_OLDNAMES) && !defined(popen)
#تعریف_کن popen   _popen
#تعریف_کن pclose  _pclose
#پایان_اگر
  صحيح __cdecl چاپ_کن(ثابت حرف *_Format,...);
  صحيح __cdecl putc(صحيح _Ch,FILE *_File);
  صحيح __cdecl حرف_چاپ_کن(صحيح _Ch);
  صحيح __cdecl puts(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _putw(صحيح کلمه_4,FILE *_File);
#اگر_تعریف_نشده _CRT_DIRECTORY_DEFINED
#تعریف_کن _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#اگر_تعریف_نشده NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#پایان_اگر
#پایان_اگر
  فراغ __cdecl rewind(FILE *_File);
  _CRTIMP صحيح __cdecl _rmtmp(فراغ);
  صحيح __cdecl scanf(ثابت حرف *_Format,...);
  فراغ __cdecl setbuf(FILE *_File,حرف *میانگیر_2);
  _CRTIMP صحيح __cdecl _setmaxstdio(صحيح _Max);
  _CRTIMP بیعلامت صحيح __cdecl مجموعه_output_format(بیعلامت صحيح _Format);
  _CRTIMP بیعلامت صحيح __cdecl _get_output_format(فراغ);
  صحيح __cdecl setvbuf(FILE *_File,حرف *_Buf,صحيح نما_3,اندازه_t اندازه_4);
  _CRTIMP صحيح __cdecl _scprintf(ثابت حرف *_Format,...);
  صحيح __cdecl از_رشته_بخوان(ثابت حرف *_Src,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _snscanf(ثابت حرف *_Src,اندازه_t Max_شمار,ثابت حرف *_Format,...);
  FILE *__cdecl tmpfile(فراغ);
  حرف *__cdecl tmpnam(حرف *میانگیر_2);
  صحيح __cdecl ungetc(صحيح _Ch,FILE *_File);
  صحيح __cdecl vfprintf(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vprintf(ثابت حرف *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#رهنمود افزودن_macro("vsnprintf")
#رهنمود افزودن_macro("snprintf")
# undef vsnprintf
# undef snprintf
  خارجي
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  صحيح __mingw_vsnprintf(حرف *_DstBuf,اندازه_t Max_شمار,ثابت حرف *_Format,va_list _ArgList);
  خارجي
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  صحيح __mingw_snprintf(حرف* s, اندازه_t n, ثابت حرف*  format, ...);
  صحيح __cdecl vsnprintf(حرف *_DstBuf,اندازه_t Max_شمار,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snprintf(حرف *_Dest,اندازه_t شمار_5,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vsnprintf(حرف *_Dest,اندازه_t شمار_5,ثابت حرف *_Format,va_list آرگومانها_2);
  صحيح __cdecl sprintf(حرف *_Dest,ثابت حرف *_Format,...);
  صحيح __cdecl vsprintf(حرف *_Dest,ثابت حرف *_Format,va_list آرگومانها_2);
#اگر_تعریف_نشده __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snprintf(حرف* s, اندازه_t n, ثابت حرف*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnprintf (حرف* s, اندازه_t n, ثابت حرف* format,va_list arg) {
    أرجع _vsnprintf ( s, n, format, arg);
  }
  صحيح __cdecl vscanf(ثابت حرف * Format, va_list argp);
  صحيح __cdecl vfscanf (FILE * fp, ثابت حرف * Format,va_list argp);
  صحيح __cdecl vsscanf (ثابت حرف * _Str,ثابت حرف * Format,va_list argp);
#پایان_اگر
/* Restore may prior defined macros snprintf/vsnprintf.  */
#رهنمود برداشت_macro("snprintf")
#رهنمود برداشت_macro("vsnprintf")
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
  _CRTIMP صحيح __cdecl مجموعه_printf_شمار_output(صحيح مقدار_2);
  _CRTIMP صحيح __cdecl get_printf_شمار_output(فراغ);

#اگر_تعریف_نشده _WSTDIO_DEFINED

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

#اگر_تعریف_شده _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3,صحيح _ShFlag);
#پایان_اگر
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح اندازه_درون_واژگان,FILE *_File);
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
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,اندازه_t اندازه_درون_واژگان,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,اندازه_t شمار_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,اندازه_t شمار_5,ثابت wchar_t *_Format,va_list آرگومانها_2);
#اگر_تعریف_نشده __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t* s, اندازه_t n, ثابت wchar_t*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t* s, اندازه_t n, ثابت wchar_t* format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#پایان_اگر
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list آرگومانها_2);

#اگر_تعریف_نشده RC_INVOKED
#ضمن <vadefs.h>
#پایان_اگر

#اگر_تعریف_شده _CRT_NON_CONFORMING_SWPRINTFS
#اگر_تعریف_نشده __cplusplus
#تعریف_کن swprintf _swprintf
#تعریف_کن vswprintf _vswprintf
#تعریف_کن _swprintf_l __swprintf_l
#تعریف_کن _vswprintf_l __vswprintf_l
#پایان_اگر
#پایان_اگر

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_پیشوند);
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,اندازه_t Max_شمار,ثابت wchar_t *_Format,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *نما_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *نما_3,FILE *_OldFile);
#اگر_تعریف_نشده _CRT_WPERROR_DEFINED
#تعریف_کن _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیام);
#پایان_اگر
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *نما_3);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#تعریف_کن wpopen  _wpopen
#پایان_اگر
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *میانگیر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#لغو_تعریف _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#تعریف_کن getwchar() fgetwc(stdin)
#تعریف_کن putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() { أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { أرجع (fputwc(_C,stdout)); }
#پایان_اگر

#تعریف_کن getwc(_stm) fgetwc(_stm)
#تعریف_کن putwc(_c,_stm) fputwc(_c,_stm)
#تعریف_کن _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#تعریف_کن _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#تعریف_کن _WSTDIO_DEFINED
#پایان_اگر

#تعریف_کن _STDIO_DEFINED
#پایان_اگر

#تعریف_کن _fgetc_nolock(جریان_2) (--(جریان_2)->_cnt >= 0 ? 0xff & *(جریان_2)->_ptr++ : _filbuf(جریان_2))
#تعریف_کن _fputc_nolock(_c,جریان_2) (--(جریان_2)->_cnt >= 0 ? 0xff & (*(جریان_2)->_ptr++ = (حرف)(_c)) : _flsbuf((_c),(جریان_2)))
#تعریف_کن _getc_nolock(جریان_2) _fgetc_nolock(جریان_2)
#تعریف_کن _putc_nolock(_c,جریان_2) _fputc_nolock(_c,جریان_2)
#تعریف_کن _getchar_nolock() _getc_nolock(stdin)
#تعریف_کن _putchar_nolock(_c) _putc_nolock((_c),stdout)
#تعریف_کن _getwchar_nolock() _getwc_nolock(stdin)
#تعریف_کن _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP فراغ __cdecl قفل_file(FILE *_File);
  _CRTIMP فراغ __cdecl _unlock_file(FILE *_File);
  _CRTIMP صحيح __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP اندازه_t __cdecl _fread_nolock(فراغ *_DstBuf,اندازه_t Element_اندازه,اندازه_t شمار_5,FILE *_File);
  _CRTIMP صحيح __cdecl _fseek_nolock(FILE *_File,دراز جابه_جایی_2,صحيح _Origin);
  _CRTIMP دراز __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fseeki64_nolock(FILE *_File,__int64 جابه_جایی_2,صحيح _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP اندازه_t __cdecl _fwrite_nolock(ثابت فراغ *_DstBuf,اندازه_t اندازه_4,اندازه_t شمار_5,FILE *_File);
  _CRTIMP صحيح __cdecl _ungetc_nolock(صحيح _Ch,FILE *_File);

#إذا !defined(NO_OLDNAMES) || !defined(_POSIX)
#تعریف_کن P_tmpdir _P_tmpdir
#تعریف_کن SYS_OPEN _SYS_OPEN

  حرف *__cdecl tempnam(ثابت حرف *_Directory,ثابت حرف *File_پیشوند);
  صحيح __cdecl fcloseall(فراغ);
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *_Format);
  صحيح __cdecl fgetchar(فراغ);
  صحيح __cdecl fileno(FILE *_File);
  صحيح __cdecl flushall(فراغ);
  صحيح __cdecl fputchar(صحيح _Ch);
  صحيح __cdecl getw(FILE *_File);
  صحيح __cdecl putw(صحيح _Ch,FILE *_File);
  صحيح __cdecl rmtmp(فراغ);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)

#ضمن <sec_api/stdio_s.h>

#پایان_اگر
