/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_STDIO
#تعریف_کرو _INC_STDIO

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#تعریف_کرو BUFSIZ 512
#تعریف_کرو _NFILE _NSTREAM_
#تعریف_کرو _NSTREAM_ 512
#تعریف_کرو _IOB_ENTRIES 20
#تعریف_کرو EOF (-1)

#اگر_غیر_تعریف_شدہ _FILE_DEFINED
  ساخت _iobuf {
    حرف *_ptr;
    صحیح _cnt;
    حرف *بنیاد_4;
    صحیح _flag;
    صحیح _file;
    صحیح _charbuf;
    صحیح _bufsiz;
    حرف *_tmpfname;
  };
  قسمتعریف ساخت _iobuf FILE;
#تعریف_کرو _FILE_DEFINED
#اگر_ختم

#اگر_تعریف_شدہ _POSIX_
#تعریف_کرو _P_tmpdir "/"
#تعریف_کرو _wP_tmpdir L"/"
#ورنہ
#تعریف_کرو _P_tmpdir "\\"
#تعریف_کرو _wP_tmpdir L"\\"
#اگر_ختم

#تعریف_کرو L_tmpnam (حجم(_P_tmpdir) + 12)

#اگر_تعریف_شدہ _POSIX_
#تعریف_کرو L_ctermid 9
#تعریف_کرو L_cuserid 32
#اگر_ختم

#تعریف_کرو SEEK_CUR 1
#تعریف_کرو SEEK_END 2
#تعریف_کرو SEEK_SET 0

#تعریف_کرو STDIN_FILENO    0
#تعریف_کرو STDOUT_FILENO   1
#تعریف_کرو STDERR_FILENO   2

#تعریف_کرو FILENAME_MAX 260
#تعریف_کرو FOPEN_MAX 20
#تعریف_کرو _SYS_OPEN 20
#تعریف_کرو TMP_MAX 32767

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF_T_DEFINED
#تعریف_کرو _OFF_T_DEFINED
#اگر_غیر_تعریف_شدہ _OFF_T_
#تعریف_کرو _OFF_T_
  قسمتعریف طویل _off_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل off_t;
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _OFF64_T_DEFINED
#تعریف_کرو _OFF64_T_DEFINED
  قسمتعریف طویل طویل _off64_t;
#اگر !defined(NO_OLDNAMES) || defined(_POSIX)
  قسمتعریف طویل طویل off64_t;
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _STDIO_DEFINED
#اگر_تعریف_شدہ _WIN64
  _CRTIMP FILE *__cdecl __iob_func(خالی);
#ورنہ
#اگر_تعریف_شدہ _MSVCRT_
خارجی FILE _iob[];     /* A pointer to an array of FILE */
#تعریف_کرو __iob_func()    (_iob)
#ورنہ
خارجی FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#تعریف_کرو __iob_func()    (*_imp___iob)
#تعریف_کرو _iob __iob_func()
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _FPOS_T_DEFINED
#تعریف_کرو _FPOS_T_DEFINED
#تعریف_منسوخ _FPOSOFF

#اگر (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_بٹ >= 64
  قسمتعریف __int64 fpos_t;
#تعریف_کرو _FPOSOFF(fp) ((طویل)(fp))
#ورنہ
  قسمتعریف طویل طویل fpos_t;
#تعریف_کرو _FPOSOFF(fp) ((طویل)(fp))
#اگر_ختم

#اگر_ختم

#اگر_غیر_تعریف_شدہ _STDSTREAM_DEFINED
#تعریف_کرو _STDSTREAM_DEFINED

#تعریف_کرو stdin (&__iob_func()[0])
#تعریف_کرو stdout (&__iob_func()[1])
#تعریف_کرو stderr (&__iob_func()[2])
#اگر_ختم

#تعریف_کرو _IOREAD 0x0001
#تعریف_کرو _IOWRT 0x0002

#تعریف_کرو _IOFBF 0x0000
#تعریف_کرو _IOLBF 0x0040
#تعریف_کرو _IONBF 0x0004

#تعریف_کرو _IOMYBUF 0x0008
#تعریف_کرو _IOEOF 0x0010
#تعریف_کرو _IOERR 0x0020
#تعریف_کرو _IOSTRG 0x0040
#تعریف_کرو _IORW 0x0080
#اگر_تعریف_شدہ _POSIX_
#تعریف_کرو _IOAPPEND 0x0200
#اگر_ختم

#تعریف_کرو _TWO_DIGIT_EXPONENT 0x1

#اگر_غیر_تعریف_شدہ _STDIO_DEFINED

  _CRTIMP صحیح __cdecl _filbuf(FILE *_File);
  _CRTIMP صحیح __cdecl _flsbuf(صحیح _Ch,FILE *_File);
#اگر_تعریف_شدہ _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *منوال_3);
#ورنہ
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *منوال_3,صحیح _ShFlag);
#اگر_ختم
  خالی __cdecl clearerr(FILE *_File);
  صحیح __cdecl fclose(FILE *_File);
  _CRTIMP صحیح __cdecl _fcloseall(خالی);
#اگر_تعریف_شدہ _POSIX_
  FILE *__cdecl fdopen(صحیح _FileHandle,ثابت حرف *منوال_3);
#ورنہ
  _CRTIMP FILE *__cdecl _fdopen(صحیح _FileHandle,ثابت حرف *منوال_3);
#اگر_ختم
  صحیح __cdecl feof(FILE *_File);
  صحیح __cdecl ferror(FILE *_File);
  صحیح __cdecl fflush(FILE *_File);
  صحیح __cdecl fgetc(FILE *_File);
  _CRTIMP صحیح __cdecl _fgetchar(خالی);
  صحیح __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  حرف *__cdecl fgets(حرف *_Buf,صحیح Max_گنتی,FILE *_File);
#اگر_تعریف_شدہ _POSIX_
  صحیح __cdecl fileno(FILE *_File);
#ورنہ
  _CRTIMP صحیح __cdecl _fileno(FILE *_File);
#اگر_ختم
  _CRTIMP حرف *__cdecl _tempnam(ثابت حرف *_DirName,ثابت حرف *File_سابقہ);
  _CRTIMP صحیح __cdecl _flushall(خالی);
  FILE *__cdecl fopen(ثابت حرف *_Filename,ثابت حرف *منوال_3);
  FILE *fopen64(ثابت حرف *filename,ثابت حرف *منوال);
  صحیح __cdecl fprintf(FILE *_File,ثابت حرف *_Format,...);
  صحیح __cdecl fputc(صحیح _Ch,FILE *_File);
  _CRTIMP صحیح __cdecl _fputchar(صحیح _Ch);
  صحیح __cdecl fputs(ثابت حرف *_Str,FILE *_File);
  سائز_t __cdecl fread(خالی *_DstBuf,سائز_t Element_سائز,سائز_t گنتی_5,FILE *_File);
  FILE *__cdecl freopen(ثابت حرف *_Filename,ثابت حرف *منوال_3,FILE *_File);
  صحیح __cdecl fscanf(FILE *_File,ثابت حرف *_Format,...);
  صحیح __cdecl fsetpos(FILE *_File,ثابت fpos_t *_Pos);
  صحیح __cdecl fseek(FILE *_File,طویل انحراف_2,صحیح _Origin);
   صحیح fseeko64(FILE* دھارا, _off64_t انحراف, صحیح whence);
  طویل __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * دھارا);
  صحیح __cdecl _fseeki64(FILE *_File,__int64 انحراف_2,صحیح _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  سائز_t __cdecl fwrite(ثابت خالی *_Str,سائز_t سائز_4,سائز_t گنتی_5,FILE *_File);
  صحیح __cdecl getc(FILE *_File);
  صحیح __cdecl getchar(خالی);
  _CRTIMP صحیح __cdecl _getmaxstdio(خالی);
  حرف *__cdecl gets(حرف *بفر_2);
  صحیح __cdecl _getw(FILE *_File);
#اگر_غیر_تعریف_شدہ _CRT_PERROR_DEFINED
#تعریف_کرو _CRT_PERROR_DEFINED
  خالی __cdecl perror(ثابت حرف *Err_پیغام);
#اگر_ختم
  _CRTIMP صحیح __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ثابت حرف *_Command,ثابت حرف *منوال_3);
#اگر !defined(NO_OLDNAMES) && !defined(popen)
#تعریف_کرو popen   _popen
#تعریف_کرو pclose  _pclose
#اگر_ختم
  صحیح __cdecl لکھو(ثابت حرف *_Format,...);
  صحیح __cdecl putc(صحیح _Ch,FILE *_File);
  صحیح __cdecl حرف_لکھو(صحیح _Ch);
  صحیح __cdecl puts(ثابت حرف *_Str);
  _CRTIMP صحیح __cdecl _putw(صحیح لفظ_4,FILE *_File);
#اگر_غیر_تعریف_شدہ _CRT_DIRECTORY_DEFINED
#تعریف_کرو _CRT_DIRECTORY_DEFINED
  صحیح __cdecl remove(ثابت حرف *_Filename);
  صحیح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحیح __cdecl _unlink(ثابت حرف *_Filename);
#اگر_غیر_تعریف_شدہ NO_OLDNAMES
  صحیح __cdecl unlink(ثابت حرف *_Filename);
#اگر_ختم
#اگر_ختم
  خالی __cdecl rewind(FILE *_File);
  _CRTIMP صحیح __cdecl _rmtmp(خالی);
  صحیح __cdecl scanf(ثابت حرف *_Format,...);
  خالی __cdecl setbuf(FILE *_File,حرف *بفر_2);
  _CRTIMP صحیح __cdecl _setmaxstdio(صحیح _Max);
  _CRTIMP غیرعلامتی صحیح __cdecl سیٹ_output_format(غیرعلامتی صحیح _Format);
  _CRTIMP غیرعلامتی صحیح __cdecl _get_output_format(خالی);
  صحیح __cdecl setvbuf(FILE *_File,حرف *_Buf,صحیح منوال_3,سائز_t سائز_4);
  _CRTIMP صحیح __cdecl _scprintf(ثابت حرف *_Format,...);
  صحیح __cdecl لڑی_سے_پڑھو(ثابت حرف *_Src,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _snscanf(ثابت حرف *_Src,سائز_t Max_گنتی,ثابت حرف *_Format,...);
  FILE *__cdecl tmpfile(خالی);
  حرف *__cdecl tmpnam(حرف *بفر_2);
  صحیح __cdecl ungetc(صحیح _Ch,FILE *_File);
  صحیح __cdecl vfprintf(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحیح __cdecl vprintf(ثابت حرف *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#ہدایت ڈالو_macro("vsnprintf")
#ہدایت ڈالو_macro("snprintf")
# undef vsnprintf
# undef snprintf
  خارجی
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  صحیح __mingw_vsnprintf(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,va_list _ArgList);
  خارجی
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  صحیح __mingw_snprintf(حرف* s, سائز_t n, ثابت حرف*  format, ...);
  صحیح __cdecl vsnprintf(حرف *_DstBuf,سائز_t Max_گنتی,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snprintf(حرف *_Dest,سائز_t گنتی_5,ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _vsnprintf(حرف *_Dest,سائز_t گنتی_5,ثابت حرف *_Format,va_list دلائل_2);
  صحیح __cdecl sprintf(حرف *_Dest,ثابت حرف *_Format,...);
  صحیح __cdecl vsprintf(حرف *_Dest,ثابت حرف *_Format,va_list دلائل_2);
#اگر_غیر_تعریف_شدہ __NO_ISOCEXT  /* externs in libmingwex.a */
  صحیح __cdecl snprintf(حرف* s, سائز_t n, ثابت حرف*  format, ...);
  __CRT_INLINE صحیح __cdecl vsnprintf (حرف* s, سائز_t n, ثابت حرف* format,va_list arg) {
    واپس _vsnprintf ( s, n, format, arg);
  }
  صحیح __cdecl vscanf(ثابت حرف * Format, va_list argp);
  صحیح __cdecl vfscanf (FILE * fp, ثابت حرف * Format,va_list argp);
  صحیح __cdecl vsscanf (ثابت حرف * _Str,ثابت حرف * Format,va_list argp);
#اگر_ختم
/* Restore may prior defined macros snprintf/vsnprintf.  */
#ہدایت نکالو_macro("snprintf")
#ہدایت نکالو_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# اگر defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP صحیح __cdecl _vscprintf(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl سیٹ_printf_گنتی_output(صحیح قدر_2);
  _CRTIMP صحیح __cdecl get_printf_گنتی_output(خالی);

#اگر_غیر_تعریف_شدہ _WSTDIO_DEFINED

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

#اگر_تعریف_شدہ _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
#ورنہ
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,صحیح _ShFlag);
#اگر_ختم
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(خالی);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(خالی);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحیح سائز_اندر_الفاظ,FILE *_File);
  صحیح __cdecl fputws(ثابت wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP صحیح __cdecl _putws(ثابت wchar_t *_Str);
  صحیح __cdecl fwprintf(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl wprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _scwprintf(ثابت wchar_t *_Format,...);
  صحیح __cdecl vfwprintf(FILE *_File,ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl vwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl swprintf(wchar_t*, ثابت wchar_t*, ...);
  _CRTIMP صحیح __cdecl vswprintf(wchar_t*, ثابت wchar_t*,va_list);
  _CRTIMP صحیح __cdecl _swprintf_c(wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf_c(wchar_t *_DstBuf,سائز_t سائز_اندر_الفاظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _snwprintf(wchar_t *_Dest,سائز_t گنتی_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vsnwprintf(wchar_t *_Dest,سائز_t گنتی_5,ثابت wchar_t *_Format,va_list دلائل_2);
#اگر_غیر_تعریف_شدہ __NO_ISOCEXT  /* externs in libmingwex.a */
  صحیح __cdecl snwprintf (wchar_t* s, سائز_t n, ثابت wchar_t*  format, ...);
  __CRT_INLINE صحیح __cdecl vsnwprintf (wchar_t* s, سائز_t n, ثابت wchar_t* format, va_list arg) { واپس _vsnwprintf(s,n,format,arg); }
  صحیح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحیح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحیح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#اگر_ختم
  _CRTIMP صحیح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list دلائل_2);

#اگر_غیر_تعریف_شدہ RC_INVOKED
#شامل <vadefs.h>
#اگر_ختم

#اگر_تعریف_شدہ _CRT_NON_CONFORMING_SWPRINTFS
#اگر_غیر_تعریف_شدہ __cplusplus
#تعریف_کرو swprintf _swprintf
#تعریف_کرو vswprintf _vswprintf
#تعریف_کرو _swprintf_l __swprintf_l
#تعریف_کرو _vswprintf_l __vswprintf_l
#اگر_ختم
#اگر_ختم

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_سابقہ);
  _CRTIMP صحیح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  صحیح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  صحیح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _snwscanf(ثابت wchar_t *_Src,سائز_t Max_گنتی,ثابت wchar_t *_Format,...);
  صحیح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحیح _FileHandle ,ثابت wchar_t *منوال_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *منوال_3,FILE *_OldFile);
#اگر_غیر_تعریف_شدہ _CRT_WPERROR_DEFINED
#تعریف_کرو _CRT_WPERROR_DEFINED
  _CRTIMP خالی __cdecl _wperror(ثابت wchar_t *Err_پیغام);
#اگر_ختم
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *منوال_3);
#اگر !defined(NO_OLDNAMES) && !defined(wpopen)
#تعریف_کرو wpopen  _wpopen
#اگر_ختم
  _CRTIMP صحیح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#تعریف_منسوخ _CRT_GETPUTWCHAR_NOINLINE

#اگر !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#تعریف_کرو getwchar() fgetwc(stdin)
#تعریف_کرو putwchar(_c) fputwc((_c),stdout)
#ورنہ
  __CRT_INLINE wint_t __cdecl getwchar() { واپس (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { واپس (fputwc(_C,stdout)); }
#اگر_ختم

#تعریف_کرو getwc(_stm) fgetwc(_stm)
#تعریف_کرو putwc(_c,_stm) fputwc(_c,_stm)
#تعریف_کرو _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#تعریف_کرو _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#تعریف_کرو _WSTDIO_DEFINED
#اگر_ختم

#تعریف_کرو _STDIO_DEFINED
#اگر_ختم

#تعریف_کرو _fgetc_nolock(دھارا_2) (--(دھارا_2)->_cnt >= 0 ? 0xff & *(دھارا_2)->_ptr++ : _filbuf(دھارا_2))
#تعریف_کرو _fputc_nolock(_c,دھارا_2) (--(دھارا_2)->_cnt >= 0 ? 0xff & (*(دھارا_2)->_ptr++ = (حرف)(_c)) : _flsbuf((_c),(دھارا_2)))
#تعریف_کرو _getc_nolock(دھارا_2) _fgetc_nolock(دھارا_2)
#تعریف_کرو _putc_nolock(_c,دھارا_2) _fputc_nolock(_c,دھارا_2)
#تعریف_کرو _getchar_nolock() _getc_nolock(stdin)
#تعریف_کرو _putchar_nolock(_c) _putc_nolock((_c),stdout)
#تعریف_کرو _getwchar_nolock() _getwc_nolock(stdin)
#تعریف_کرو _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP خالی __cdecl تالا_file(FILE *_File);
  _CRTIMP خالی __cdecl _unlock_file(FILE *_File);
  _CRTIMP صحیح __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP صحیح __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP سائز_t __cdecl _fread_nolock(خالی *_DstBuf,سائز_t Element_سائز,سائز_t گنتی_5,FILE *_File);
  _CRTIMP صحیح __cdecl _fseek_nolock(FILE *_File,طویل انحراف_2,صحیح _Origin);
  _CRTIMP طویل __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP صحیح __cdecl _fseeki64_nolock(FILE *_File,__int64 انحراف_2,صحیح _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP سائز_t __cdecl _fwrite_nolock(ثابت خالی *_DstBuf,سائز_t سائز_4,سائز_t گنتی_5,FILE *_File);
  _CRTIMP صحیح __cdecl _ungetc_nolock(صحیح _Ch,FILE *_File);

#اگر !defined(NO_OLDNAMES) || !defined(_POSIX)
#تعریف_کرو P_tmpdir _P_tmpdir
#تعریف_کرو SYS_OPEN _SYS_OPEN

  حرف *__cdecl tempnam(ثابت حرف *_Directory,ثابت حرف *File_سابقہ);
  صحیح __cdecl fcloseall(خالی);
  FILE *__cdecl fdopen(صحیح _FileHandle,ثابت حرف *_Format);
  صحیح __cdecl fgetchar(خالی);
  صحیح __cdecl fileno(FILE *_File);
  صحیح __cdecl flushall(خالی);
  صحیح __cdecl fputchar(صحیح _Ch);
  صحیح __cdecl getw(FILE *_File);
  صحیح __cdecl putw(صحیح _Ch,FILE *_File);
  صحیح __cdecl rmtmp(خالی);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)

#شامل <sec_api/stdio_s.h>

#اگر_ختم
