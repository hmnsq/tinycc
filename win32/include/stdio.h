/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_STDIO
#وصف_ڪريو _INC_STDIO

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#وصف_ڪريو BUFSIZ 512
#وصف_ڪريو _NFILE _NSTREAM_
#وصف_ڪريو _NSTREAM_ 512
#وصف_ڪريو _IOB_ENTRIES 20
#وصف_ڪريو EOF (-1)

#جيڪڏهن_وصف_نه_ٿيل _FILE_DEFINED
  بنية _iobuf {
    حرف *_ptr;
    صحيح _cnt;
    حرف *بنياد_4;
    صحيح _flag;
    صحيح _file;
    صحيح _charbuf;
    صحيح _bufsiz;
    حرف *_tmpfname;
  };
  تعريفنوع بنية _iobuf FILE;
#وصف_ڪريو _FILE_DEFINED
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو _P_tmpdir "/"
#وصف_ڪريو _wP_tmpdir L"/"
#وإلا
#وصف_ڪريو _P_tmpdir "\\"
#وصف_ڪريو _wP_tmpdir L"\\"
#جيڪڏهن_پورو

#وصف_ڪريو L_tmpnam (حجم(_P_tmpdir) + 12)

#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو L_ctermid 9
#وصف_ڪريو L_cuserid 32
#جيڪڏهن_پورو

#وصف_ڪريو SEEK_CUR 1
#وصف_ڪريو SEEK_END 2
#وصف_ڪريو SEEK_SET 0

#وصف_ڪريو STDIN_FILENO    0
#وصف_ڪريو STDOUT_FILENO   1
#وصف_ڪريو STDERR_FILENO   2

#وصف_ڪريو FILENAME_MAX 260
#وصف_ڪريو FOPEN_MAX 20
#وصف_ڪريو _SYS_OPEN 20
#وصف_ڪريو TMP_MAX 32767

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF_T_DEFINED
#وصف_ڪريو _OFF_T_DEFINED
#جيڪڏهن_وصف_نه_ٿيل _OFF_T_
#وصف_ڪريو _OFF_T_
  تعريفنوع ڊگهو _off_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو off_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _OFF64_T_DEFINED
#وصف_ڪريو _OFF64_T_DEFINED
  تعريفنوع ڊگهو ڊگهو _off64_t;
#إذا !defined(NO_OLDNAMES) || defined(_POSIX)
  تعريفنوع ڊگهو ڊگهو off64_t;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STDIO_DEFINED
#جيڪڏهن_وصف_ٿيل _WIN64
  _CRTIMP FILE *__cdecl __iob_func(فراغ);
#وإلا
#جيڪڏهن_وصف_ٿيل _MSVCRT_
خارجي FILE _iob[];     /* A pointer to an array of FILE */
#وصف_ڪريو __iob_func()    (_iob)
#وإلا
خارجي FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#وصف_ڪريو __iob_func()    (*_imp___iob)
#وصف_ڪريو _iob __iob_func()
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _FPOS_T_DEFINED
#وصف_ڪريو _FPOS_T_DEFINED
#وصف_رد _FPOSOFF

#إذا (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_بٽ >= 64
  تعريفنوع __int64 fpos_t;
#وصف_ڪريو _FPOSOFF(fp) ((ڊگهو)(fp))
#وإلا
  تعريفنوع ڊگهو ڊگهو fpos_t;
#وصف_ڪريو _FPOSOFF(fp) ((ڊگهو)(fp))
#جيڪڏهن_پورو

#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _STDSTREAM_DEFINED
#وصف_ڪريو _STDSTREAM_DEFINED

#وصف_ڪريو stdin (&__iob_func()[0])
#وصف_ڪريو stdout (&__iob_func()[1])
#وصف_ڪريو stderr (&__iob_func()[2])
#جيڪڏهن_پورو

#وصف_ڪريو _IOREAD 0x0001
#وصف_ڪريو _IOWRT 0x0002

#وصف_ڪريو _IOFBF 0x0000
#وصف_ڪريو _IOLBF 0x0040
#وصف_ڪريو _IONBF 0x0004

#وصف_ڪريو _IOMYBUF 0x0008
#وصف_ڪريو _IOEOF 0x0010
#وصف_ڪريو _IOERR 0x0020
#وصف_ڪريو _IOSTRG 0x0040
#وصف_ڪريو _IORW 0x0080
#جيڪڏهن_وصف_ٿيل _POSIX_
#وصف_ڪريو _IOAPPEND 0x0200
#جيڪڏهن_پورو

#وصف_ڪريو _TWO_DIGIT_EXPONENT 0x1

#جيڪڏهن_وصف_نه_ٿيل _STDIO_DEFINED

  _CRTIMP صحيح __cdecl _filbuf(FILE *_File);
  _CRTIMP صحيح __cdecl _flsbuf(صحيح _Ch,FILE *_File);
#جيڪڏهن_وصف_ٿيل _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *گهڻائي_3);
#وإلا
  _CRTIMP FILE *__cdecl _fsopen(ثابت حرف *_Filename,ثابت حرف *گهڻائي_3,صحيح _ShFlag);
#جيڪڏهن_پورو
  فراغ __cdecl clearerr(FILE *_File);
  صحيح __cdecl fclose(FILE *_File);
  _CRTIMP صحيح __cdecl _fcloseall(فراغ);
#جيڪڏهن_وصف_ٿيل _POSIX_
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *گهڻائي_3);
#وإلا
  _CRTIMP FILE *__cdecl _fdopen(صحيح _FileHandle,ثابت حرف *گهڻائي_3);
#جيڪڏهن_پورو
  صحيح __cdecl feof(FILE *_File);
  صحيح __cdecl ferror(FILE *_File);
  صحيح __cdecl fflush(FILE *_File);
  صحيح __cdecl fgetc(FILE *_File);
  _CRTIMP صحيح __cdecl _fgetchar(فراغ);
  صحيح __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  حرف *__cdecl fgets(حرف *_Buf,صحيح Max_ڳڻپ,FILE *_File);
#جيڪڏهن_وصف_ٿيل _POSIX_
  صحيح __cdecl fileno(FILE *_File);
#وإلا
  _CRTIMP صحيح __cdecl _fileno(FILE *_File);
#جيڪڏهن_پورو
  _CRTIMP حرف *__cdecl _tempnam(ثابت حرف *_DirName,ثابت حرف *File_اڳياڙي);
  _CRTIMP صحيح __cdecl _flushall(فراغ);
  FILE *__cdecl fopen(ثابت حرف *_Filename,ثابت حرف *گهڻائي_3);
  FILE *fopen64(ثابت حرف *filename,ثابت حرف *گهڻائي);
  صحيح __cdecl fprintf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fputc(صحيح _Ch,FILE *_File);
  _CRTIMP صحيح __cdecl _fputchar(صحيح _Ch);
  صحيح __cdecl fputs(ثابت حرف *_Str,FILE *_File);
  سائيز_t __cdecl fread(فراغ *_DstBuf,سائيز_t Element_سائيز,سائيز_t ڳڻپ_5,FILE *_File);
  FILE *__cdecl freopen(ثابت حرف *_Filename,ثابت حرف *گهڻائي_3,FILE *_File);
  صحيح __cdecl fscanf(FILE *_File,ثابت حرف *_Format,...);
  صحيح __cdecl fsetpos(FILE *_File,ثابت fpos_t *_Pos);
  صحيح __cdecl fseek(FILE *_File,ڊگهو وٿي_2,صحيح _Origin);
   صحيح fseeko64(FILE* وهڪرو, _off64_t وٿي, صحيح whence);
  ڊگهو __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * وهڪرو);
  صحيح __cdecl _fseeki64(FILE *_File,__int64 وٿي_2,صحيح _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  سائيز_t __cdecl fwrite(ثابت فراغ *_Str,سائيز_t سائيز_4,سائيز_t ڳڻپ_5,FILE *_File);
  صحيح __cdecl getc(FILE *_File);
  صحيح __cdecl getchar(فراغ);
  _CRTIMP صحيح __cdecl _getmaxstdio(فراغ);
  حرف *__cdecl gets(حرف *بفر_2);
  صحيح __cdecl _getw(FILE *_File);
#جيڪڏهن_وصف_نه_ٿيل _CRT_PERROR_DEFINED
#وصف_ڪريو _CRT_PERROR_DEFINED
  فراغ __cdecl perror(ثابت حرف *Err_نياپو);
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ثابت حرف *_Command,ثابت حرف *گهڻائي_3);
#إذا !defined(NO_OLDNAMES) && !defined(popen)
#وصف_ڪريو popen   _popen
#وصف_ڪريو pclose  _pclose
#جيڪڏهن_پورو
  صحيح __cdecl لکو(ثابت حرف *_Format,...);
  صحيح __cdecl putc(صحيح _Ch,FILE *_File);
  صحيح __cdecl اکر_لکو(صحيح _Ch);
  صحيح __cdecl puts(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _putw(صحيح لفظ_4,FILE *_File);
#جيڪڏهن_وصف_نه_ٿيل _CRT_DIRECTORY_DEFINED
#وصف_ڪريو _CRT_DIRECTORY_DEFINED
  صحيح __cdecl remove(ثابت حرف *_Filename);
  صحيح __cdecl rename(ثابت حرف *_OldFilename,ثابت حرف *_NewFilename);
  _CRTIMP صحيح __cdecl _unlink(ثابت حرف *_Filename);
#جيڪڏهن_وصف_نه_ٿيل NO_OLDNAMES
  صحيح __cdecl unlink(ثابت حرف *_Filename);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
  فراغ __cdecl rewind(FILE *_File);
  _CRTIMP صحيح __cdecl _rmtmp(فراغ);
  صحيح __cdecl scanf(ثابت حرف *_Format,...);
  فراغ __cdecl setbuf(FILE *_File,حرف *بفر_2);
  _CRTIMP صحيح __cdecl _setmaxstdio(صحيح _Max);
  _CRTIMP بنانشان صحيح __cdecl سيٽ_output_format(بنانشان صحيح _Format);
  _CRTIMP بنانشان صحيح __cdecl _get_output_format(فراغ);
  صحيح __cdecl setvbuf(FILE *_File,حرف *_Buf,صحيح گهڻائي_3,سائيز_t سائيز_4);
  _CRTIMP صحيح __cdecl _scprintf(ثابت حرف *_Format,...);
  صحيح __cdecl لڙي_مان_پڙهو(ثابت حرف *_Src,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _snscanf(ثابت حرف *_Src,سائيز_t Max_ڳڻپ,ثابت حرف *_Format,...);
  FILE *__cdecl tmpfile(فراغ);
  حرف *__cdecl tmpnam(حرف *بفر_2);
  صحيح __cdecl ungetc(صحيح _Ch,FILE *_File);
  صحيح __cdecl vfprintf(FILE *_File,ثابت حرف *_Format,va_list _ArgList);
  صحيح __cdecl vprintf(ثابت حرف *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#هدايت ڌڪو_macro("vsnprintf")
#هدايت ڌڪو_macro("snprintf")
# undef vsnprintf
# undef snprintf
  خارجي
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  صحيح __mingw_vsnprintf(حرف *_DstBuf,سائيز_t Max_ڳڻپ,ثابت حرف *_Format,va_list _ArgList);
  خارجي
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  صحيح __mingw_snprintf(حرف* s, سائيز_t n, ثابت حرف*  format, ...);
  صحيح __cdecl vsnprintf(حرف *_DstBuf,سائيز_t Max_ڳڻپ,ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snprintf(حرف *_Dest,سائيز_t ڳڻپ_5,ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vsnprintf(حرف *_Dest,سائيز_t ڳڻپ_5,ثابت حرف *_Format,va_list دليلون_2);
  صحيح __cdecl sprintf(حرف *_Dest,ثابت حرف *_Format,...);
  صحيح __cdecl vsprintf(حرف *_Dest,ثابت حرف *_Format,va_list دليلون_2);
#جيڪڏهن_وصف_نه_ٿيل __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snprintf(حرف* s, سائيز_t n, ثابت حرف*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnprintf (حرف* s, سائيز_t n, ثابت حرف* format,va_list arg) {
    أرجع _vsnprintf ( s, n, format, arg);
  }
  صحيح __cdecl vscanf(ثابت حرف * Format, va_list argp);
  صحيح __cdecl vfscanf (FILE * fp, ثابت حرف * Format,va_list argp);
  صحيح __cdecl vsscanf (ثابت حرف * _Str,ثابت حرف * Format,va_list argp);
#جيڪڏهن_پورو
/* Restore may prior defined macros snprintf/vsnprintf.  */
#هدايت ڪڍو_macro("snprintf")
#هدايت ڪڍو_macro("vsnprintf")
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
  _CRTIMP صحيح __cdecl سيٽ_printf_ڳڻپ_output(صحيح قدر_2);
  _CRTIMP صحيح __cdecl get_printf_ڳڻپ_output(فراغ);

#جيڪڏهن_وصف_نه_ٿيل _WSTDIO_DEFINED

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3);
#وإلا
  _CRTIMP FILE *__cdecl _wfsopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3,صحيح _ShFlag);
#جيڪڏهن_پورو
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(فراغ);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(فراغ);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,صحيح سائيز_اندريون_لفظ,FILE *_File);
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
  _CRTIMP صحيح __cdecl _swprintf_c(wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf_c(wchar_t *_DstBuf,سائيز_t سائيز_اندريون_لفظ,ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _snwprintf(wchar_t *_Dest,سائيز_t ڳڻپ_5,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vsnwprintf(wchar_t *_Dest,سائيز_t ڳڻپ_5,ثابت wchar_t *_Format,va_list دليلون_2);
#جيڪڏهن_وصف_نه_ٿيل __NO_ISOCEXT  /* externs in libmingwex.a */
  صحيح __cdecl snwprintf (wchar_t* s, سائيز_t n, ثابت wchar_t*  format, ...);
  __CRT_INLINE صحيح __cdecl vsnwprintf (wchar_t* s, سائيز_t n, ثابت wchar_t* format, va_list arg) { أرجع _vsnwprintf(s,n,format,arg); }
  صحيح __cdecl vwscanf (ثابت wchar_t *, va_list);
  صحيح __cdecl vfwscanf (FILE *,ثابت wchar_t *,va_list);
  صحيح __cdecl vswscanf (ثابت wchar_t *,ثابت wchar_t *,va_list);
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _swprintf(wchar_t *_Dest,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vswprintf(wchar_t *_Dest,ثابت wchar_t *_Format,va_list دليلون_2);

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#ضمن <vadefs.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _CRT_NON_CONFORMING_SWPRINTFS
#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#وصف_ڪريو swprintf _swprintf
#وصف_ڪريو vswprintf _vswprintf
#وصف_ڪريو _swprintf_l __swprintf_l
#وصف_ڪريو _vswprintf_l __vswprintf_l
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  _CRTIMP wchar_t *__cdecl _wtempnam(ثابت wchar_t *_Directory,ثابت wchar_t *File_اڳياڙي);
  _CRTIMP صحيح __cdecl _vscwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  صحيح __cdecl fwscanf(FILE *_File,ثابت wchar_t *_Format,...);
  صحيح __cdecl swscanf(ثابت wchar_t *_Src,ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _snwscanf(ثابت wchar_t *_Src,سائيز_t Max_ڳڻپ,ثابت wchar_t *_Format,...);
  صحيح __cdecl wscanf(ثابت wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(صحيح _FileHandle ,ثابت wchar_t *گهڻائي_3);
  _CRTIMP FILE *__cdecl _wfopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3);
  _CRTIMP FILE *__cdecl _wfreopen(ثابت wchar_t *_Filename,ثابت wchar_t *گهڻائي_3,FILE *_OldFile);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WPERROR_DEFINED
#وصف_ڪريو _CRT_WPERROR_DEFINED
  _CRTIMP فراغ __cdecl _wperror(ثابت wchar_t *Err_نياپو);
#جيڪڏهن_پورو
  _CRTIMP FILE *__cdecl _wpopen(ثابت wchar_t *_Command,ثابت wchar_t *گهڻائي_3);
#إذا !defined(NO_OLDNAMES) && !defined(wpopen)
#وصف_ڪريو wpopen  _wpopen
#جيڪڏهن_پورو
  _CRTIMP صحيح __cdecl _wremove(ثابت wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#وصف_رد _CRT_GETPUTWCHAR_NOINLINE

#إذا !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#وصف_ڪريو getwchar() fgetwc(stdin)
#وصف_ڪريو putwchar(_c) fputwc((_c),stdout)
#وإلا
  __CRT_INLINE wint_t __cdecl getwchar() { أرجع (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { أرجع (fputwc(_C,stdout)); }
#جيڪڏهن_پورو

#وصف_ڪريو getwc(_stm) fgetwc(_stm)
#وصف_ڪريو putwc(_c,_stm) fputwc(_c,_stm)
#وصف_ڪريو _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#وصف_ڪريو _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#وصف_ڪريو _WSTDIO_DEFINED
#جيڪڏهن_پورو

#وصف_ڪريو _STDIO_DEFINED
#جيڪڏهن_پورو

#وصف_ڪريو _fgetc_nolock(وهڪرو_2) (--(وهڪرو_2)->_cnt >= 0 ? 0xff & *(وهڪرو_2)->_ptr++ : _filbuf(وهڪرو_2))
#وصف_ڪريو _fputc_nolock(_c,وهڪرو_2) (--(وهڪرو_2)->_cnt >= 0 ? 0xff & (*(وهڪرو_2)->_ptr++ = (حرف)(_c)) : _flsbuf((_c),(وهڪرو_2)))
#وصف_ڪريو _getc_nolock(وهڪرو_2) _fgetc_nolock(وهڪرو_2)
#وصف_ڪريو _putc_nolock(_c,وهڪرو_2) _fputc_nolock(_c,وهڪرو_2)
#وصف_ڪريو _getchar_nolock() _getc_nolock(stdin)
#وصف_ڪريو _putchar_nolock(_c) _putc_nolock((_c),stdout)
#وصف_ڪريو _getwchar_nolock() _getwc_nolock(stdin)
#وصف_ڪريو _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP فراغ __cdecl تالو_file(FILE *_File);
  _CRTIMP فراغ __cdecl _unlock_file(FILE *_File);
  _CRTIMP صحيح __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP سائيز_t __cdecl _fread_nolock(فراغ *_DstBuf,سائيز_t Element_سائيز,سائيز_t ڳڻپ_5,FILE *_File);
  _CRTIMP صحيح __cdecl _fseek_nolock(FILE *_File,ڊگهو وٿي_2,صحيح _Origin);
  _CRTIMP ڊگهو __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP صحيح __cdecl _fseeki64_nolock(FILE *_File,__int64 وٿي_2,صحيح _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP سائيز_t __cdecl _fwrite_nolock(ثابت فراغ *_DstBuf,سائيز_t سائيز_4,سائيز_t ڳڻپ_5,FILE *_File);
  _CRTIMP صحيح __cdecl _ungetc_nolock(صحيح _Ch,FILE *_File);

#إذا !defined(NO_OLDNAMES) || !defined(_POSIX)
#وصف_ڪريو P_tmpdir _P_tmpdir
#وصف_ڪريو SYS_OPEN _SYS_OPEN

  حرف *__cdecl tempnam(ثابت حرف *_Directory,ثابت حرف *File_اڳياڙي);
  صحيح __cdecl fcloseall(فراغ);
  FILE *__cdecl fdopen(صحيح _FileHandle,ثابت حرف *_Format);
  صحيح __cdecl fgetchar(فراغ);
  صحيح __cdecl fileno(FILE *_File);
  صحيح __cdecl flushall(فراغ);
  صحيح __cdecl fputchar(صحيح _Ch);
  صحيح __cdecl getw(FILE *_File);
  صحيح __cdecl putw(صحيح _Ch,FILE *_File);
  صحيح __cdecl rmtmp(فراغ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#ضمن <sec_api/stdio_s.h>

#جيڪڏهن_پورو
