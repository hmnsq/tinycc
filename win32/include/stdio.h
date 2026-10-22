/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_STDIO
#నిర్వచించు _INC_STDIO

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచించు BUFSIZ 512
#నిర్వచించు _NFILE _NSTREAM_
#నిర్వచించు _NSTREAM_ 512
#నిర్వచించు _IOB_ENTRIES 20
#నిర్వచించు EOF (-1)

#నిర్వచితం_కాకపోతే _FILE_DEFINED
  నిర్మాణం _iobuf {
    అక్షరం *_ptr;
    పూర్ణాంకం _cnt;
    అక్షరం *పునాది_4;
    పూర్ణాంకం _flag;
    పూర్ణాంకం _file;
    పూర్ణాంకం _charbuf;
    పూర్ణాంకం _bufsiz;
    అక్షరం *_tmpfname;
  };
  రకనిర్వచనం నిర్మాణం _iobuf FILE;
#నిర్వచించు _FILE_DEFINED
#అయితే_ముగింపు

#నిర్వచితమైతే _POSIX_
#నిర్వచించు _P_tmpdir "/"
#నిర్వచించు _wP_tmpdir L"/"
#లేకపోతే
#నిర్వచించు _P_tmpdir "\\"
#నిర్వచించు _wP_tmpdir L"\\"
#అయితే_ముగింపు

#నిర్వచించు L_tmpnam (పరిమాణం(_P_tmpdir) + 12)

#నిర్వచితమైతే _POSIX_
#నిర్వచించు L_ctermid 9
#నిర్వచించు L_cuserid 32
#అయితే_ముగింపు

#నిర్వచించు SEEK_CUR 1
#నిర్వచించు SEEK_END 2
#నిర్వచించు SEEK_SET 0

#నిర్వచించు STDIN_FILENO    0
#నిర్వచించు STDOUT_FILENO   1
#నిర్వచించు STDERR_FILENO   2

#నిర్వచించు FILENAME_MAX 260
#నిర్వచించు FOPEN_MAX 20
#నిర్వచించు _SYS_OPEN 20
#నిర్వచించు TMP_MAX 32767

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF_T_DEFINED
#నిర్వచించు _OFF_T_DEFINED
#నిర్వచితం_కాకపోతే _OFF_T_
#నిర్వచించు _OFF_T_
  రకనిర్వచనం దీర్ఘ _off_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ off_t;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _OFF64_T_DEFINED
#నిర్వచించు _OFF64_T_DEFINED
  రకనిర్వచనం దీర్ఘ దీర్ఘ _off64_t;
#ఒకవేళ !defined(NO_OLDNAMES) || defined(_POSIX)
  రకనిర్వచనం దీర్ఘ దీర్ఘ off64_t;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STDIO_DEFINED
#నిర్వచితమైతే _WIN64
  _CRTIMP FILE *__cdecl __iob_func(శూన్య);
#లేకపోతే
#నిర్వచితమైతే _MSVCRT_
బాహ్య FILE _iob[];     /* A pointer to an array of FILE */
#నిర్వచించు __iob_func()    (_iob)
#లేకపోతే
బాహ్య FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#నిర్వచించు __iob_func()    (*_imp___iob)
#నిర్వచించు _iob __iob_func()
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _FPOS_T_DEFINED
#నిర్వచించు _FPOS_T_DEFINED
#నిర్వచనం_రద్దు _FPOSOFF

#ఒకవేళ (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_బిట్లు >= 64
  రకనిర్వచనం __int64 fpos_t;
#నిర్వచించు _FPOSOFF(fp) ((దీర్ఘ)(fp))
#లేకపోతే
  రకనిర్వచనం దీర్ఘ దీర్ఘ fpos_t;
#నిర్వచించు _FPOSOFF(fp) ((దీర్ఘ)(fp))
#అయితే_ముగింపు

#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _STDSTREAM_DEFINED
#నిర్వచించు _STDSTREAM_DEFINED

#నిర్వచించు stdin (&__iob_func()[0])
#నిర్వచించు stdout (&__iob_func()[1])
#నిర్వచించు stderr (&__iob_func()[2])
#అయితే_ముగింపు

#నిర్వచించు _IOREAD 0x0001
#నిర్వచించు _IOWRT 0x0002

#నిర్వచించు _IOFBF 0x0000
#నిర్వచించు _IOLBF 0x0040
#నిర్వచించు _IONBF 0x0004

#నిర్వచించు _IOMYBUF 0x0008
#నిర్వచించు _IOEOF 0x0010
#నిర్వచించు _IOERR 0x0020
#నిర్వచించు _IOSTRG 0x0040
#నిర్వచించు _IORW 0x0080
#నిర్వచితమైతే _POSIX_
#నిర్వచించు _IOAPPEND 0x0200
#అయితే_ముగింపు

#నిర్వచించు _TWO_DIGIT_EXPONENT 0x1

#నిర్వచితం_కాకపోతే _STDIO_DEFINED

  _CRTIMP పూర్ణాంకం __cdecl _filbuf(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _flsbuf(పూర్ణాంకం _Ch,FILE *_File);
#నిర్వచితమైతే _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *బహుళకం_3);
#లేకపోతే
  _CRTIMP FILE *__cdecl _fsopen(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *బహుళకం_3,పూర్ణాంకం _ShFlag);
#అయితే_ముగింపు
  శూన్య __cdecl clearerr(FILE *_File);
  పూర్ణాంకం __cdecl fclose(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fcloseall(శూన్య);
#నిర్వచితమైతే _POSIX_
  FILE *__cdecl fdopen(పూర్ణాంకం _FileHandle,స్థిరరాశి అక్షరం *బహుళకం_3);
#లేకపోతే
  _CRTIMP FILE *__cdecl _fdopen(పూర్ణాంకం _FileHandle,స్థిరరాశి అక్షరం *బహుళకం_3);
#అయితే_ముగింపు
  పూర్ణాంకం __cdecl feof(FILE *_File);
  పూర్ణాంకం __cdecl ferror(FILE *_File);
  పూర్ణాంకం __cdecl fflush(FILE *_File);
  పూర్ణాంకం __cdecl fgetc(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fgetchar(శూన్య);
  పూర్ణాంకం __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  అక్షరం *__cdecl fgets(అక్షరం *_Buf,పూర్ణాంకం Max_లెక్క,FILE *_File);
#నిర్వచితమైతే _POSIX_
  పూర్ణాంకం __cdecl fileno(FILE *_File);
#లేకపోతే
  _CRTIMP పూర్ణాంకం __cdecl _fileno(FILE *_File);
#అయితే_ముగింపు
  _CRTIMP అక్షరం *__cdecl _tempnam(స్థిరరాశి అక్షరం *_DirName,స్థిరరాశి అక్షరం *File_ఉపసర్గ);
  _CRTIMP పూర్ణాంకం __cdecl _flushall(శూన్య);
  FILE *__cdecl fopen(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *బహుళకం_3);
  FILE *fopen64(స్థిరరాశి అక్షరం *filename,స్థిరరాశి అక్షరం *బహుళకం);
  పూర్ణాంకం __cdecl fprintf(FILE *_File,స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl fputc(పూర్ణాంకం _Ch,FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fputchar(పూర్ణాంకం _Ch);
  పూర్ణాంకం __cdecl fputs(స్థిరరాశి అక్షరం *_Str,FILE *_File);
  కొలత_t __cdecl fread(శూన్య *_DstBuf,కొలత_t Element_కొలత,కొలత_t లెక్క_5,FILE *_File);
  FILE *__cdecl freopen(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *బహుళకం_3,FILE *_File);
  పూర్ణాంకం __cdecl fscanf(FILE *_File,స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl fsetpos(FILE *_File,స్థిరరాశి fpos_t *_Pos);
  పూర్ణాంకం __cdecl fseek(FILE *_File,దీర్ఘ స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
   పూర్ణాంకం fseeko64(FILE* ప్రవాహం, _off64_t స్థానభ్రంశం, పూర్ణాంకం whence);
  దీర్ఘ __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * ప్రవాహం);
  పూర్ణాంకం __cdecl _fseeki64(FILE *_File,__int64 స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  కొలత_t __cdecl fwrite(స్థిరరాశి శూన్య *_Str,కొలత_t కొలత_4,కొలత_t లెక్క_5,FILE *_File);
  పూర్ణాంకం __cdecl getc(FILE *_File);
  పూర్ణాంకం __cdecl getchar(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _getmaxstdio(శూన్య);
  అక్షరం *__cdecl gets(అక్షరం *బఫరు_2);
  పూర్ణాంకం __cdecl _getw(FILE *_File);
#నిర్వచితం_కాకపోతే _CRT_PERROR_DEFINED
#నిర్వచించు _CRT_PERROR_DEFINED
  శూన్య __cdecl perror(స్థిరరాశి అక్షరం *Err_సందేశం);
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(స్థిరరాశి అక్షరం *_Command,స్థిరరాశి అక్షరం *బహుళకం_3);
#ఒకవేళ !defined(NO_OLDNAMES) && !defined(popen)
#నిర్వచించు popen   _popen
#నిర్వచించు pclose  _pclose
#అయితే_ముగింపు
  పూర్ణాంకం __cdecl రాయి(స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl putc(పూర్ణాంకం _Ch,FILE *_File);
  పూర్ణాంకం __cdecl అక్షరం_రాయి(పూర్ణాంకం _Ch);
  పూర్ణాంకం __cdecl puts(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _putw(పూర్ణాంకం మాట_4,FILE *_File);
#నిర్వచితం_కాకపోతే _CRT_DIRECTORY_DEFINED
#నిర్వచించు _CRT_DIRECTORY_DEFINED
  పూర్ణాంకం __cdecl remove(స్థిరరాశి అక్షరం *_Filename);
  పూర్ణాంకం __cdecl rename(స్థిరరాశి అక్షరం *_OldFilename,స్థిరరాశి అక్షరం *_NewFilename);
  _CRTIMP పూర్ణాంకం __cdecl _unlink(స్థిరరాశి అక్షరం *_Filename);
#నిర్వచితం_కాకపోతే NO_OLDNAMES
  పూర్ణాంకం __cdecl unlink(స్థిరరాశి అక్షరం *_Filename);
#అయితే_ముగింపు
#అయితే_ముగింపు
  శూన్య __cdecl rewind(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _rmtmp(శూన్య);
  పూర్ణాంకం __cdecl scanf(స్థిరరాశి అక్షరం *_Format,...);
  శూన్య __cdecl setbuf(FILE *_File,అక్షరం *బఫరు_2);
  _CRTIMP పూర్ణాంకం __cdecl _setmaxstdio(పూర్ణాంకం _Max);
  _CRTIMP గుర్తులేని పూర్ణాంకం __cdecl సమితి_output_format(గుర్తులేని పూర్ణాంకం _Format);
  _CRTIMP గుర్తులేని పూర్ణాంకం __cdecl _get_output_format(శూన్య);
  పూర్ణాంకం __cdecl setvbuf(FILE *_File,అక్షరం *_Buf,పూర్ణాంకం బహుళకం_3,కొలత_t కొలత_4);
  _CRTIMP పూర్ణాంకం __cdecl _scprintf(స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl అక్షరశ్రేణి_చదువు(స్థిరరాశి అక్షరం *_Src,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _snscanf(స్థిరరాశి అక్షరం *_Src,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,...);
  FILE *__cdecl tmpfile(శూన్య);
  అక్షరం *__cdecl tmpnam(అక్షరం *బఫరు_2);
  పూర్ణాంకం __cdecl ungetc(పూర్ణాంకం _Ch,FILE *_File);
  పూర్ణాంకం __cdecl vfprintf(FILE *_File,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl vprintf(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#సూచన నెట్టు_macro("vsnprintf")
#సూచన నెట్టు_macro("snprintf")
# undef vsnprintf
# undef snprintf
  బాహ్య
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  పూర్ణాంకం __mingw_vsnprintf(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  బాహ్య
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  పూర్ణాంకం __mingw_snprintf(అక్షరం* s, కొలత_t n, స్థిరరాశి అక్షరం*  format, ...);
  పూర్ణాంకం __cdecl vsnprintf(అక్షరం *_DstBuf,కొలత_t Max_లెక్క,స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snprintf(అక్షరం *_Dest,కొలత_t లెక్క_5,స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnprintf(అక్షరం *_Dest,కొలత_t లెక్క_5,స్థిరరాశి అక్షరం *_Format,va_list వాదనలు_2);
  పూర్ణాంకం __cdecl sprintf(అక్షరం *_Dest,స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl vsprintf(అక్షరం *_Dest,స్థిరరాశి అక్షరం *_Format,va_list వాదనలు_2);
#నిర్వచితం_కాకపోతే __NO_ISOCEXT  /* externs in libmingwex.a */
  పూర్ణాంకం __cdecl snprintf(అక్షరం* s, కొలత_t n, స్థిరరాశి అక్షరం*  format, ...);
  __CRT_INLINE పూర్ణాంకం __cdecl vsnprintf (అక్షరం* s, కొలత_t n, స్థిరరాశి అక్షరం* format,va_list arg) {
    తిరిగి _vsnprintf ( s, n, format, arg);
  }
  పూర్ణాంకం __cdecl vscanf(స్థిరరాశి అక్షరం * Format, va_list argp);
  పూర్ణాంకం __cdecl vfscanf (FILE * fp, స్థిరరాశి అక్షరం * Format,va_list argp);
  పూర్ణాంకం __cdecl vsscanf (స్థిరరాశి అక్షరం * _Str,స్థిరరాశి అక్షరం * Format,va_list argp);
#అయితే_ముగింపు
/* Restore may prior defined macros snprintf/vsnprintf.  */
#సూచన తీయి_macro("snprintf")
#సూచన తీయి_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# ఒకవేళ defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP పూర్ణాంకం __cdecl _vscprintf(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl సమితి_printf_లెక్క_output(పూర్ణాంకం విలువ_2);
  _CRTIMP పూర్ణాంకం __cdecl get_printf_లెక్క_output(శూన్య);

#నిర్వచితం_కాకపోతే _WSTDIO_DEFINED

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

#నిర్వచితమైతే _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3);
#లేకపోతే
  _CRTIMP FILE *__cdecl _wfsopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3,పూర్ణాంకం _ShFlag);
#అయితే_ముగింపు
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(శూన్య);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(శూన్య);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,పూర్ణాంకం కొలత_లోపల_పదాలు,FILE *_File);
  పూర్ణాంకం __cdecl fputws(స్థిరరాశి wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP పూర్ణాంకం __cdecl _putws(స్థిరరాశి wchar_t *_Str);
  పూర్ణాంకం __cdecl fwprintf(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl wprintf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _scwprintf(స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl vfwprintf(FILE *_File,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl vwprintf(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl swprintf(wchar_t*, స్థిరరాశి wchar_t*, ...);
  _CRTIMP పూర్ణాంకం __cdecl vswprintf(wchar_t*, స్థిరరాశి wchar_t*,va_list);
  _CRTIMP పూర్ణాంకం __cdecl _swprintf_c(wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf_c(wchar_t *_DstBuf,కొలత_t కొలత_లోపల_పదాలు,స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _snwprintf(wchar_t *_Dest,కొలత_t లెక్క_5,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vsnwprintf(wchar_t *_Dest,కొలత_t లెక్క_5,స్థిరరాశి wchar_t *_Format,va_list వాదనలు_2);
#నిర్వచితం_కాకపోతే __NO_ISOCEXT  /* externs in libmingwex.a */
  పూర్ణాంకం __cdecl snwprintf (wchar_t* s, కొలత_t n, స్థిరరాశి wchar_t*  format, ...);
  __CRT_INLINE పూర్ణాంకం __cdecl vsnwprintf (wchar_t* s, కొలత_t n, స్థిరరాశి wchar_t* format, va_list arg) { తిరిగి _vsnwprintf(s,n,format,arg); }
  పూర్ణాంకం __cdecl vwscanf (స్థిరరాశి wchar_t *, va_list);
  పూర్ణాంకం __cdecl vfwscanf (FILE *,స్థిరరాశి wchar_t *,va_list);
  పూర్ణాంకం __cdecl vswscanf (స్థిరరాశి wchar_t *,స్థిరరాశి wchar_t *,va_list);
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _swprintf(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vswprintf(wchar_t *_Dest,స్థిరరాశి wchar_t *_Format,va_list వాదనలు_2);

#నిర్వచితం_కాకపోతే RC_INVOKED
#అన్తర్భావ <vadefs.h>
#అయితే_ముగింపు

#నిర్వచితమైతే _CRT_NON_CONFORMING_SWPRINTFS
#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచించు swprintf _swprintf
#నిర్వచించు vswprintf _vswprintf
#నిర్వచించు _swprintf_l __swprintf_l
#నిర్వచించు _vswprintf_l __vswprintf_l
#అయితే_ముగింపు
#అయితే_ముగింపు

  _CRTIMP wchar_t *__cdecl _wtempnam(స్థిరరాశి wchar_t *_Directory,స్థిరరాశి wchar_t *File_ఉపసర్గ);
  _CRTIMP పూర్ణాంకం __cdecl _vscwprintf(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  పూర్ణాంకం __cdecl fwscanf(FILE *_File,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl swscanf(స్థిరరాశి wchar_t *_Src,స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _snwscanf(స్థిరరాశి wchar_t *_Src,కొలత_t Max_లెక్క,స్థిరరాశి wchar_t *_Format,...);
  పూర్ణాంకం __cdecl wscanf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(పూర్ణాంకం _FileHandle ,స్థిరరాశి wchar_t *బహుళకం_3);
  _CRTIMP FILE *__cdecl _wfopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3);
  _CRTIMP FILE *__cdecl _wfreopen(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *బహుళకం_3,FILE *_OldFile);
#నిర్వచితం_కాకపోతే _CRT_WPERROR_DEFINED
#నిర్వచించు _CRT_WPERROR_DEFINED
  _CRTIMP శూన్య __cdecl _wperror(స్థిరరాశి wchar_t *Err_సందేశం);
#అయితే_ముగింపు
  _CRTIMP FILE *__cdecl _wpopen(స్థిరరాశి wchar_t *_Command,స్థిరరాశి wchar_t *బహుళకం_3);
#ఒకవేళ !defined(NO_OLDNAMES) && !defined(wpopen)
#నిర్వచించు wpopen  _wpopen
#అయితే_ముగింపు
  _CRTIMP పూర్ణాంకం __cdecl _wremove(స్థిరరాశి wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *బఫరు_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#నిర్వచనం_రద్దు _CRT_GETPUTWCHAR_NOINLINE

#ఒకవేళ !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#నిర్వచించు getwchar() fgetwc(stdin)
#నిర్వచించు putwchar(_c) fputwc((_c),stdout)
#లేకపోతే
  __CRT_INLINE wint_t __cdecl getwchar() { తిరిగి (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { తిరిగి (fputwc(_C,stdout)); }
#అయితే_ముగింపు

#నిర్వచించు getwc(_stm) fgetwc(_stm)
#నిర్వచించు putwc(_c,_stm) fputwc(_c,_stm)
#నిర్వచించు _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#నిర్వచించు _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#నిర్వచించు _WSTDIO_DEFINED
#అయితే_ముగింపు

#నిర్వచించు _STDIO_DEFINED
#అయితే_ముగింపు

#నిర్వచించు _fgetc_nolock(ప్రవాహం_2) (--(ప్రవాహం_2)->_cnt >= 0 ? 0xff & *(ప్రవాహం_2)->_ptr++ : _filbuf(ప్రవాహం_2))
#నిర్వచించు _fputc_nolock(_c,ప్రవాహం_2) (--(ప్రవాహం_2)->_cnt >= 0 ? 0xff & (*(ప్రవాహం_2)->_ptr++ = (అక్షరం)(_c)) : _flsbuf((_c),(ప్రవాహం_2)))
#నిర్వచించు _getc_nolock(ప్రవాహం_2) _fgetc_nolock(ప్రవాహం_2)
#నిర్వచించు _putc_nolock(_c,ప్రవాహం_2) _fputc_nolock(_c,ప్రవాహం_2)
#నిర్వచించు _getchar_nolock() _getc_nolock(stdin)
#నిర్వచించు _putchar_nolock(_c) _putc_nolock((_c),stdout)
#నిర్వచించు _getwchar_nolock() _getwc_nolock(stdin)
#నిర్వచించు _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP శూన్య __cdecl తాళం_file(FILE *_File);
  _CRTIMP శూన్య __cdecl _unlock_file(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP కొలత_t __cdecl _fread_nolock(శూన్య *_DstBuf,కొలత_t Element_కొలత,కొలత_t లెక్క_5,FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fseek_nolock(FILE *_File,దీర్ఘ స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
  _CRTIMP దీర్ఘ __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _fseeki64_nolock(FILE *_File,__int64 స్థానభ్రంశం_2,పూర్ణాంకం _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP కొలత_t __cdecl _fwrite_nolock(స్థిరరాశి శూన్య *_DstBuf,కొలత_t కొలత_4,కొలత_t లెక్క_5,FILE *_File);
  _CRTIMP పూర్ణాంకం __cdecl _ungetc_nolock(పూర్ణాంకం _Ch,FILE *_File);

#ఒకవేళ !defined(NO_OLDNAMES) || !defined(_POSIX)
#నిర్వచించు P_tmpdir _P_tmpdir
#నిర్వచించు SYS_OPEN _SYS_OPEN

  అక్షరం *__cdecl tempnam(స్థిరరాశి అక్షరం *_Directory,స్థిరరాశి అక్షరం *File_ఉపసర్గ);
  పూర్ణాంకం __cdecl fcloseall(శూన్య);
  FILE *__cdecl fdopen(పూర్ణాంకం _FileHandle,స్థిరరాశి అక్షరం *_Format);
  పూర్ణాంకం __cdecl fgetchar(శూన్య);
  పూర్ణాంకం __cdecl fileno(FILE *_File);
  పూర్ణాంకం __cdecl flushall(శూన్య);
  పూర్ణాంకం __cdecl fputchar(పూర్ణాంకం _Ch);
  పూర్ణాంకం __cdecl getw(FILE *_File);
  పూర్ణాంకం __cdecl putw(పూర్ణాంకం _Ch,FILE *_File);
  పూర్ణాంకం __cdecl rmtmp(శూన్య);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)

#అన్తర్భావ <sec_api/stdio_s.h>

#అయితే_ముగింపు
