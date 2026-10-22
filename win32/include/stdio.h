/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_STDIO
#تعریف_کړه _INC_STDIO

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#تعریف_کړه BUFSIZ 512
#تعریف_کړه _NFILE _NSTREAM_
#تعریف_کړه _NSTREAM_ 512
#تعریف_کړه _IOB_ENTRIES 20
#تعریف_کړه EOF (-1)

#که_نه_تعریف_شوی _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *بنسټ_4;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#تعریف_کړه _FILE_DEFINED
#د_که_پای

#که_تعریف_شوی _POSIX_
#تعریف_کړه _P_tmpdir "/"
#تعریف_کړه _wP_tmpdir L"/"
#وإلا
#تعریف_کړه _P_tmpdir "\\"
#تعریف_کړه _wP_tmpdir L"\\"
#د_که_پای

#تعریف_کړه L_tmpnam (حجم(_P_tmpdir) + 12)

#که_تعریف_شوی _POSIX_
#تعریف_کړه L_ctermid 9
#تعریف_کړه L_cuserid 32
#د_که_پای

#تعریف_کړه SEEK_CUR 1
#تعریف_کړه SEEK_END 2
#تعریف_کړه SEEK_SET 0

#تعریف_کړه STDIN_FILENO    0
#تعریف_کړه STDOUT_FILENO   1
#تعریف_کړه STDERR_FILENO   2

#تعریف_کړه FILENAME_MAX 260
#تعریف_کړه FOPEN_MAX 20
#تعریف_کړه _SYS_OPEN 20
#تعریف_کړه TMP_MAX 32767

#که_نه_تعریف_شوی عدم
#که_تعریف_شوی __cplusplus
#تعریف_کړه عدم 0
#وإلا
#تعریف_کړه عدم ((فراغ *)0)
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _OFF_T_DEFINED
#تعریف_کړه _OFF_T_DEFINED
#که_نه_تعریف_شوی _OFF_T_
#تعریف_کړه _OFF_T_
  تعريفنوع اوږد _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع اوږد off_t;
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _OFF64_T_DEFINED
#تعریف_کړه _OFF64_T_DEFINED
  تعريفنوع اوږد اوږد _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع اوږد اوږد off64_t;
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _STDIO_DEFINED
#که_تعریف_شوی _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#که_تعریف_شوی _MSVCRT_
خارجي FILE _iob[];     /* A pointer to an array of FILE */
#تعریف_کړه __iob_func()    (_iob)
#وإلا
خارجي FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#تعریف_کړه __iob_func()    (*_imp___iob)
#تعریف_کړه _iob __iob_func()
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _FPOS_T_DEFINED
#تعریف_کړه _FPOS_T_DEFINED
#تعریف_لغوه _FPOSOFF

#إذا (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_بټونه >= 64
  تعريفنوع __int64 fpos_t;
#تعریف_کړه _FPOSOFF(fp) ((اوږد)(fp))
#وإلا
  تعريفنوع اوږد اوږد fpos_t;
#تعریف_کړه _FPOSOFF(fp) ((اوږد)(fp))
#د_که_پای

#د_که_پای

#که_نه_تعریف_شوی _STDSTREAM_DEFINED
#تعریف_کړه _STDSTREAM_DEFINED

#تعریف_کړه stdin (&__iob_func()[0])
#تعریف_کړه stdout (&__iob_func()[1])
#تعریف_کړه stderr (&__iob_func()[2])
#د_که_پای

#تعریف_کړه _IOREAD 0x0001
#تعریف_کړه _IOWRT 0x0002

#تعریف_کړه _IOFBF 0x0000
#تعریف_کړه _IOLBF 0x0040
#تعریف_کړه _IONBF 0x0004

#تعریف_کړه _IOMYBUF 0x0008
#تعریف_کړه _IOEOF 0x0010
#تعریف_کړه _IOERR 0x0020
#تعریف_کړه _IOSTRG 0x0040
#تعریف_کړه _IORW 0x0080
#که_تعریف_شوی _POSIX_
#تعریف_کړه _IOAPPEND 0x0200
#د_که_پای

#تعریف_کړه _TWO_DIGIT_EXPONENT 0x1

#که_نه_تعریف_شوی _STDIO_DEFINED

  _CRTIMP صحيح __cdecl _filbuf(FILE *_File);
  _CRTIMP صحيح __cdecl _flsbuf(صحيح _Ch,FILE *_File);
#که_تعریف_شوی _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *ډېرپېښ_3);
#وإلا
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *ډېرپېښ_3,صحيح _ShFlag);
#د_که_پای
  فراغ __cdecl clearerr(FILE *_File);
  صحيح __cdecl fclose(FILE *_File);
  _CRTIMP صحيح __cdecl _fcloseall(فراغ);
#که_تعریف_شوی _POSIX_
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *ډېرپېښ_3);
#وإلا
  _CRTIMP FILE *__cdecl _fdopen(صحيح _FileHandle,ثابت حرف *ډېرپېښ_3);
#د_که_پای
  صحيح __cdecl feof(FILE *_File);
  صحيح __cdecl ferror(FILE *_File);
  صحيح __cdecl fflush(FILE *_File);
  صحيح __cdecl fgetc(FILE *_File);
  _CRTIMP صحيح __cdecl _fgetchar(فراغ);
  صحيح __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  حرف *__cdecl fgets(حرف *_Buf,صحيح Max_شمېر,FILE *_File);
#که_تعریف_شوی _POSIX_
  صحيح __cdecl fileno(FILE *_File);
#وإلا
  _CRTIMP صحيح __cdecl _fileno(FILE *_File);
#د_که_پای
  _CRTIMP حرف *__cdecl _tempnam(ثابت حرف *_DirName,ثابت حرف *File_مختاړی);
  _CRTIMP صحيح __cdecl _flushall(فراغ);
  FILE *__cdecl fopen(ثابت حرف *_Filename,ثابت حرف *ډېرپېښ_3);
  FILE *fopen64(ثابت حرف *filename,ثابت حرف *ډېرپېښ);
  صحيح __cdecl fprintf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fputc(صحيح _Ch,FILE *_File);
  _CRTIMP صحيح __cdecl _fputchar(صحيح _Ch);
  صحيح __cdecl fputs(ثابت حرف *_Str,FILE *_File);
  اندازه_t __cdecl fread(فراغ *_DstBuf,اندازه_t Element_اندازه,اندازه_t شمېر_5,FILE *_File);
  FILE *__cdecl freopen(ثابت حرف *_Filename,ثابت حرف *ډېرپېښ_3,FILE *_File);
  صحيح __cdecl fscanf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fsetpos(FILE *_File,ثابت fpos_t *_Pos);
  صحيح __cdecl fseek(FILE *_File,اوږد دننه_واټن_2,صحيح _Origin);
   صحيح fseeko64(FILE* بهیر, _off64_t دننه_واټن, صحيح whence);
  اوږد __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * بهیر);
  صحيح __cdecl _fseeki64(FILE *_File,__int64 دننه_واټن_2,صحيح _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  اندازه_t __cdecl fwrite(ثابت فراغ *_Str,اندازه_t اندازه_4,اندازه_t شمېر_5,FILE *_File);
  صحيح __cdecl getc(FILE *_File);
  صحيح __cdecl getchar(فراغ);
  _CRTIMP صحيح __cdecl _getmaxstdio(فراغ);
  حرف *__cdecl gets(حرف *بفر_2);
  صحيح __cdecl _getw(FILE *_File);
#که_نه_تعریف_شوی _CRT_PERROR_DEFINED
#تعریف_کړه _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_پیغام);
#د_که_پای
  _CRTIMP صحيح __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ثابت حرف *_Command,ثابت حرف *ډېرپېښ_3);
#إذا !defined(NO_OLDNAMES) && !defined(popen)
#تعریف_کړه popen   _popen
#تعریف_کړه pclose  _pclose
#د_که_پای
  صحيح __cdecl چاپ_کړه(ثابت حرف *_Format,...);
  صحيح __cdecl putc(صحيح _Ch,FILE *_File);
  صحيح __cdecl توری_چاپ_کړه(صحيح _Ch);
  صحيح __cdecl puts(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _putw(صحيح کلمه_4,FILE *_File);
#که_نه_تعریف_شوی _CRT_DIRECTORY_DEFINED
#تعریف_کړه _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#که_نه_تعریف_شوی NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#د_که_پای
#د_که_پای
  فراغ __cdecl rewind(FILE *_File);
  _CRTIMP صحيح __cdecl _rmtmp(فراغ);
  صحيح __cdecl scanf(ثابت حرف *_Format,...);
  فراغ __cdecl setbuf(FILE *_File,حرف *بفر_2);
  _CRTIMP صحيح __cdecl _setmaxstdio(صحيح _Max);
  _CRTIMP بینښه صحيح __cdecl سېټ_output_format(بینښه صحيح _Format);
  _CRTIMP بینښه صحيح __cdecl _get_output_format(فراغ);
  صحيح __cdecl setvbuf(FILE *_File,حرف *_Buf,صحيح ډېرپېښ_3,اندازه_t اندازه_4);
  _CRTIMP صحيح __cdecl _scprintf(ثابت حرف *_Format,...);
  صحيح __cdecl له_مزي_ولوله(ثابت حرف *_Src,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _snscanf(ثابت حرف *_Src,اندازه_t Max_شمېر,ثابت حرف *_Format,...);
  FILE *__cdecl tmpfile(فراغ);
  حرف *__cdecl tmpnam(حرف *بفر_2);
  صحيح __cdecl ungetc(صحيح _Ch,FILE *_File);
  صحيح __cdecl vfprintf(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vprintf(ثابت حرف *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#لارښوونه ټېل_macro("vsnprintf")
#لارښوونه ټېل_macro("snprintf")
# undef vsnprintf
# undef snprintf
  خارجي
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  صحيح __mingw_vsnprintf(حرف *_DstBuf,اندازه_t Max_شمېر,ثابت حرف *_Format,va_list _ArgList);
  خارجي
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  صحيح __mingw_snprintf(حرف* s, اندازه_t n, ثابت حرف*  format, ...);
  صحيح __cdecl vsnprintf(حرف *_DstBuf,اندازه_t Max_شمېر,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snprintf(حرف *_Dest,اندازه_t شمېر_5,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vsnprintf(حرف *_Dest,اندازه_t شمېر_5,ثابت حرف *_Format,va_list دلیلونه_2);
  صحيح __cdecl sprintf(حرف *_Dest,ثابت حرف *_Format,...);
  صحيح __cdecl vsprintf(حرف *_Dest,ثابت حرف *_Format,va_list دلیلونه_2);
#که_نه_تعریف_شوی __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snprintf(حرف* s, اندازه_t n, ثابت حرف*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnprintf (حرف* s, اندازه_t n, ثابت حرف* format,va_list arg) {
    أرجع _vsnprintf ( s, n, format, arg);
  }
  صحيح __cdecl vscanf(ثابت حرف * Format, va_list argp);
  صحيح __cdecl vfscanf (FILE * fp, ثابت حرف * Format,va_list argp);
  صحيح __cdecl vsscanf (ثابت حرف * _Str,ثابت حرف * Format,va_list argp);
#د_که_پای
/* Restore may prior defined macros snprintf/vsnprintf.  */
#لارښوونه راوباسه_macro("snprintf")
#لارښوونه راوباسه_macro("vsnprintf")
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
  _CRTIMP صحيح __cdecl سېټ_printf_شمېر_output(صحيح ارزښت_2);
  _CRTIMP صحيح __cdecl get_printf_شمېر_output(فراغ);

#که_نه_تعریف_شوی _WSTDIO_DEFINED

#که_نه_تعریف_شوی WEOF
#تعریف_کړه WEOF (wint_t)(0xFFFF)
#د_که_پای

#که_تعریف_شوی _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *ډېرپېښ_3);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *ډېرپېښ_3,صحيح _ShFlag);
#د_که_پای
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح اندازه_دننه_ټکي,FILE *_File);
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
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,اندازه_t اندازه_دننه_ټکي,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,اندازه_t شمېر_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,اندازه_t شمېر_5,ثابت wchar_t *_Format,va_list دلیلونه_2);
#که_نه_تعریف_شوی __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t* s, اندازه_t n, ثابت wchar_t*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t* s, اندازه_t n, ثابت wchar_t* format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#د_که_پای
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list دلیلونه_2);

#که_نه_تعریف_شوی RC_INVOKED
#ضمن <vadefs.h>
#د_که_پای

#که_تعریف_شوی _CRT_NON_CONFORMING_SWPRINTFS
#که_نه_تعریف_شوی __cplusplus
#تعریف_کړه swprintf _swprintf
#تعریف_کړه vswprintf _vswprintf
#تعریف_کړه _swprintf_l __swprintf_l
#تعریف_کړه _vswprintf_l __vswprintf_l
#د_که_پای
#د_که_پای

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_مختاړی);
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,اندازه_t Max_شمېر,ثابت wchar_t *_Format,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *ډېرپېښ_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *ډېرپېښ_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *ډېرپېښ_3,FILE *_OldFile);
#که_نه_تعریف_شوی _CRT_WPERROR_DEFINED
#تعریف_کړه _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#د_که_پای
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *ډېرپېښ_3);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#تعریف_کړه wpopen  _wpopen
#د_که_پای
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#تعریف_لغوه _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#تعریف_کړه getwchar() fgetwc(stdin)
#تعریف_کړه putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() { أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { أرجع (fputwc(_C,stdout)); }
#د_که_پای

#تعریف_کړه getwc(_stm) fgetwc(_stm)
#تعریف_کړه putwc(_c,_stm) fputwc(_c,_stm)
#تعریف_کړه _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#تعریف_کړه _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#تعریف_کړه _WSTDIO_DEFINED
#د_که_پای

#تعریف_کړه _STDIO_DEFINED
#د_که_پای

#تعریف_کړه _fgetc_nolock(بهیر_2) (--(بهیر_2)->_cnt >= 0 ? 0xff & *(بهیر_2)->_ptr++ : _filbuf(بهیر_2))
#تعریف_کړه _fputc_nolock(_c,بهیر_2) (--(بهیر_2)->_cnt >= 0 ? 0xff & (*(بهیر_2)->_ptr++ = (حرف)(_c)) : _flsbuf((_c),(بهیر_2)))
#تعریف_کړه _getc_nolock(بهیر_2) _fgetc_nolock(بهیر_2)
#تعریف_کړه _putc_nolock(_c,بهیر_2) _fputc_nolock(_c,بهیر_2)
#تعریف_کړه _getchar_nolock() _getc_nolock(stdin)
#تعریف_کړه _putchar_nolock(_c) _putc_nolock((_c),stdout)
#تعریف_کړه _getwchar_nolock() _getwc_nolock(stdin)
#تعریف_کړه _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP فراغ __cdecl قلف_file(FILE *_File);
  _CRTIMP فراغ __cdecl _unlock_file(FILE *_File);
  _CRTIMP صحيح __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP اندازه_t __cdecl _fread_nolock(فراغ *_DstBuf,اندازه_t Element_اندازه,اندازه_t شمېر_5,FILE *_File);
  _CRTIMP صحيح __cdecl _fseek_nolock(FILE *_File,اوږد دننه_واټن_2,صحيح _Origin);
  _CRTIMP اوږد __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fseeki64_nolock(FILE *_File,__int64 دننه_واټن_2,صحيح _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP اندازه_t __cdecl _fwrite_nolock(ثابت فراغ *_DstBuf,اندازه_t اندازه_4,اندازه_t شمېر_5,FILE *_File);
  _CRTIMP صحيح __cdecl _ungetc_nolock(صحيح _Ch,FILE *_File);

#إذا !defined(NO_OLDNAMES) || !defined(_POSIX)
#تعریف_کړه P_tmpdir _P_tmpdir
#تعریف_کړه SYS_OPEN _SYS_OPEN

  حرف *__cdecl tempnam(ثابت حرف *_Directory,ثابت حرف *File_مختاړی);
  صحيح __cdecl fcloseall(فراغ);
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *_Format);
  صحيح __cdecl fgetchar(فراغ);
  صحيح __cdecl fileno(FILE *_File);
  صحيح __cdecl flushall(فراغ);
  صحيح __cdecl fputchar(صحيح _Ch);
  صحيح __cdecl getw(FILE *_File);
  صحيح __cdecl putw(صحيح _Ch,FILE *_File);
  صحيح __cdecl rmtmp(فراغ);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)

#ضمن <sec_api/stdio_s.h>

#د_که_پای
