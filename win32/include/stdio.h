/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_STDIO
#परिभाषय _INC_STDIO

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#परिभाषय BUFSIZ 512
#परिभाषय _NFILE _NSTREAM_
#परिभाषय _NSTREAM_ 512
#परिभाषय _IOB_ENTRIES 20
#परिभाषय EOF (-1)

#यदि_अपरिभाषितम् _FILE_DEFINED
  संरचना _iobuf {
    वर्ण *_ptr;
    पूर्णाङ्क _cnt;
    वर्ण *आधारः_4;
    पूर्णाङ्क _flag;
    पूर्णाङ्क _file;
    पूर्णाङ्क _charbuf;
    पूर्णाङ्क _bufsiz;
    वर्ण *_tmpfname;
  };
  प्रकारनिर्देश संरचना _iobuf FILE;
#परिभाषय _FILE_DEFINED
#यदि_अन्तः

#यदि_परिभाषितम् _POSIX_
#परिभाषय _P_tmpdir "/"
#परिभाषय _wP_tmpdir L"/"
#अन्यथा
#परिभाषय _P_tmpdir "\\"
#परिभाषय _wP_tmpdir L"\\"
#यदि_अन्तः

#परिभाषय L_tmpnam (परिमाण(_P_tmpdir) + 12)

#यदि_परिभाषितम् _POSIX_
#परिभाषय L_ctermid 9
#परिभाषय L_cuserid 32
#यदि_अन्तः

#परिभाषय SEEK_CUR 1
#परिभाषय SEEK_END 2
#परिभाषय SEEK_SET 0

#परिभाषय STDIN_FILENO    0
#परिभाषय STDOUT_FILENO   1
#परिभाषय STDERR_FILENO   2

#परिभाषय FILENAME_MAX 260
#परिभाषय FOPEN_MAX 20
#परिभाषय _SYS_OPEN 20
#परिभाषय TMP_MAX 32767

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF_T_DEFINED
#परिभाषय _OFF_T_DEFINED
#यदि_अपरिभाषितम् _OFF_T_
#परिभाषय _OFF_T_
  प्रकारनिर्देश दीर्घ _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ off_t;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _OFF64_T_DEFINED
#परिभाषय _OFF64_T_DEFINED
  प्रकारनिर्देश दीर्घ दीर्घ _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश दीर्घ दीर्घ off64_t;
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _STDIO_DEFINED
#यदि_परिभाषितम् _WIN64
  _CRTIMP FILE *__cdecl __iob_func(शून्य);
#अन्यथा
#यदि_परिभाषितम् _MSVCRT_
बाह्य FILE _iob[];     /* A pointer to an array of FILE */
#परिभाषय __iob_func()    (_iob)
#अन्यथा
बाह्य FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#परिभाषय __iob_func()    (*_imp___iob)
#परिभाषय _iob __iob_func()
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _FPOS_T_DEFINED
#परिभाषय _FPOS_T_DEFINED
#अपरिभाषय _FPOSOFF

#यदि (!defined(NO_OLDNAMES) || defined(__GNUC__)) && INTEGRAL_MAX_द्वयङ्काः >= 64
  प्रकारनिर्देश __int64 fpos_t;
#परिभाषय _FPOSOFF(fp) ((दीर्घ)(fp))
#अन्यथा
  प्रकारनिर्देश दीर्घ दीर्घ fpos_t;
#परिभाषय _FPOSOFF(fp) ((दीर्घ)(fp))
#यदि_अन्तः

#यदि_अन्तः

#यदि_अपरिभाषितम् _STDSTREAM_DEFINED
#परिभाषय _STDSTREAM_DEFINED

#परिभाषय stdin (&__iob_func()[0])
#परिभाषय stdout (&__iob_func()[1])
#परिभाषय stderr (&__iob_func()[2])
#यदि_अन्तः

#परिभाषय _IOREAD 0x0001
#परिभाषय _IOWRT 0x0002

#परिभाषय _IOFBF 0x0000
#परिभाषय _IOLBF 0x0040
#परिभाषय _IONBF 0x0004

#परिभाषय _IOMYBUF 0x0008
#परिभाषय _IOEOF 0x0010
#परिभाषय _IOERR 0x0020
#परिभाषय _IOSTRG 0x0040
#परिभाषय _IORW 0x0080
#यदि_परिभाषितम् _POSIX_
#परिभाषय _IOAPPEND 0x0200
#यदि_अन्तः

#परिभाषय _TWO_DIGIT_EXPONENT 0x1

#यदि_अपरिभाषितम् _STDIO_DEFINED

  _CRTIMP पूर्णाङ्क __cdecl _filbuf(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _flsbuf(पूर्णाङ्क _Ch,FILE *_File);
#यदि_परिभाषितम् _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *बहुलकम्_3);
#अन्यथा
  _CRTIMP FILE *__cdecl _fsopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *बहुलकम्_3,पूर्णाङ्क _ShFlag);
#यदि_अन्तः
  शून्य __cdecl clearerr(FILE *_File);
  पूर्णाङ्क __cdecl fclose(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fcloseall(शून्य);
#यदि_परिभाषितम् _POSIX_
  FILE *__cdecl fdopen(पूर्णाङ्क _FileHandle,ध्रुव वर्ण *बहुलकम्_3);
#अन्यथा
  _CRTIMP FILE *__cdecl _fdopen(पूर्णाङ्क _FileHandle,ध्रुव वर्ण *बहुलकम्_3);
#यदि_अन्तः
  पूर्णाङ्क __cdecl feof(FILE *_File);
  पूर्णाङ्क __cdecl ferror(FILE *_File);
  पूर्णाङ्क __cdecl fflush(FILE *_File);
  पूर्णाङ्क __cdecl fgetc(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fgetchar(शून्य);
  पूर्णाङ्क __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  वर्ण *__cdecl fgets(वर्ण *_Buf,पूर्णाङ्क Max_गणनम्,FILE *_File);
#यदि_परिभाषितम् _POSIX_
  पूर्णाङ्क __cdecl fileno(FILE *_File);
#अन्यथा
  _CRTIMP पूर्णाङ्क __cdecl _fileno(FILE *_File);
#यदि_अन्तः
  _CRTIMP वर्ण *__cdecl _tempnam(ध्रुव वर्ण *_DirName,ध्रुव वर्ण *File_उपसर्गः);
  _CRTIMP पूर्णाङ्क __cdecl _flushall(शून्य);
  FILE *__cdecl fopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *बहुलकम्_3);
  FILE *fopen64(ध्रुव वर्ण *filename,ध्रुव वर्ण *बहुलकम्);
  पूर्णाङ्क __cdecl fprintf(FILE *_File,ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl fputc(पूर्णाङ्क _Ch,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fputchar(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl fputs(ध्रुव वर्ण *_Str,FILE *_File);
  आकार_t __cdecl fread(शून्य *_DstBuf,आकार_t Element_आकार,आकार_t गणनम्_5,FILE *_File);
  FILE *__cdecl freopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *बहुलकम्_3,FILE *_File);
  पूर्णाङ्क __cdecl fscanf(FILE *_File,ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl fsetpos(FILE *_File,ध्रुव fpos_t *_Pos);
  पूर्णाङ्क __cdecl fseek(FILE *_File,दीर्घ विस्थापनम्_2,पूर्णाङ्क _Origin);
   पूर्णाङ्क fseeko64(FILE* प्रवाहः, _off64_t विस्थापनम्, पूर्णाङ्क whence);
  दीर्घ __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * प्रवाहः);
  पूर्णाङ्क __cdecl _fseeki64(FILE *_File,__int64 विस्थापनम्_2,पूर्णाङ्क _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  आकार_t __cdecl fwrite(ध्रुव शून्य *_Str,आकार_t आकार_4,आकार_t गणनम्_5,FILE *_File);
  पूर्णाङ्क __cdecl getc(FILE *_File);
  पूर्णाङ्क __cdecl अक्षरं_पठ(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getmaxstdio(शून्य);
  वर्ण *__cdecl gets(वर्ण *बफर_2);
  पूर्णाङ्क __cdecl _getw(FILE *_File);
#यदि_अपरिभाषितम् _CRT_PERROR_DEFINED
#परिभाषय _CRT_PERROR_DEFINED
  शून्य __cdecl perror(ध्रुव वर्ण *Err_सन्देशः);
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ध्रुव वर्ण *_Command,ध्रुव वर्ण *बहुलकम्_3);
#यदि !defined(NO_OLDNAMES) && !defined(popen)
#परिभाषय popen   _popen
#परिभाषय pclose  _pclose
#यदि_अन्तः
  पूर्णाङ्क __cdecl प्रारूप_लिख(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl putc(पूर्णाङ्क _Ch,FILE *_File);
  पूर्णाङ्क __cdecl अक्षरं_लिख(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl पङ्क्तिं_लिख(ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _putw(पूर्णाङ्क _Word,FILE *_File);
#यदि_अपरिभाषितम् _CRT_DIRECTORY_DEFINED
#परिभाषय _CRT_DIRECTORY_DEFINED
  पूर्णाङ्क __cdecl remove(ध्रुव वर्ण *_Filename);
  पूर्णाङ्क __cdecl rename(ध्रुव वर्ण *_OldFilename,ध्रुव वर्ण *_NewFilename);
  _CRTIMP पूर्णाङ्क __cdecl _unlink(ध्रुव वर्ण *_Filename);
#यदि_अपरिभाषितम् NO_OLDNAMES
  पूर्णाङ्क __cdecl unlink(ध्रुव वर्ण *_Filename);
#यदि_अन्तः
#यदि_अन्तः
  शून्य __cdecl rewind(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _rmtmp(शून्य);
  पूर्णाङ्क __cdecl प्रारूप_पठ(ध्रुव वर्ण *_Format,...);
  शून्य __cdecl setbuf(FILE *_File,वर्ण *बफर_2);
  _CRTIMP पूर्णाङ्क __cdecl _setmaxstdio(पूर्णाङ्क _Max);
  _CRTIMP अचिह्नित पूर्णाङ्क __cdecl समुच्चयः_output_format(अचिह्नित पूर्णाङ्क _Format);
  _CRTIMP अचिह्नित पूर्णाङ्क __cdecl _get_output_format(शून्य);
  पूर्णाङ्क __cdecl setvbuf(FILE *_File,वर्ण *_Buf,पूर्णाङ्क बहुलकम्_3,आकार_t आकार_4);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl वाक्यात्_पठ(ध्रुव वर्ण *_Src,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf(ध्रुव वर्ण *_Src,आकार_t Max_गणनम्,ध्रुव वर्ण *_Format,...);
  FILE *__cdecl tmpfile(शून्य);
  वर्ण *__cdecl tmpnam(वर्ण *बफर_2);
  पूर्णाङ्क __cdecl ungetc(पूर्णाङ्क _Ch,FILE *_File);
  पूर्णाङ्क __cdecl vfprintf(FILE *_File,ध्रुव वर्ण *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vprintf(ध्रुव वर्ण *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#निर्देशः प्रक्षिप_macro("vsnprintf")
#निर्देशः प्रक्षिप_macro("snprintf")
# undef vsnprintf
# undef snprintf
  बाह्य
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  पूर्णाङ्क __mingw_vsnprintf(वर्ण *_DstBuf,आकार_t Max_गणनम्,ध्रुव वर्ण *_Format,va_list _ArgList);
  बाह्य
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  पूर्णाङ्क __mingw_snprintf(वर्ण* s, आकार_t n, ध्रुव वर्ण*  format, ...);
  पूर्णाङ्क __cdecl vsnprintf(वर्ण *_DstBuf,आकार_t Max_गणनम्,ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf(वर्ण *_Dest,आकार_t गणनम्_5,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf(वर्ण *_Dest,आकार_t गणनम्_5,ध्रुव वर्ण *_Format,va_list तर्काः_2);
  पूर्णाङ्क __cdecl sprintf(वर्ण *_Dest,ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl vsprintf(वर्ण *_Dest,ध्रुव वर्ण *_Format,va_list तर्काः_2);
#यदि_अपरिभाषितम् __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snprintf(वर्ण* s, आकार_t n, ध्रुव वर्ण*  format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnprintf (वर्ण* s, आकार_t n, ध्रुव वर्ण* format,va_list arg) {
    प्रत्यागम _vsnprintf ( s, n, format, arg);
  }
  पूर्णाङ्क __cdecl vscanf(ध्रुव वर्ण * Format, va_list argp);
  पूर्णाङ्क __cdecl vfscanf (FILE * fp, ध्रुव वर्ण * Format,va_list argp);
  पूर्णाङ्क __cdecl vsscanf (ध्रुव वर्ण * _Str,ध्रुव वर्ण * Format,va_list argp);
#यदि_अन्तः
/* Restore may prior defined macros snprintf/vsnprintf.  */
#निर्देशः निष्कासय_macro("snprintf")
#निर्देशः निष्कासय_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# यदि defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP पूर्णाङ्क __cdecl _vscprintf(ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl समुच्चयः_printf_गणनम्_output(पूर्णाङ्क मानम्_2);
  _CRTIMP पूर्णाङ्क __cdecl get_printf_गणनम्_output(शून्य);

#यदि_अपरिभाषितम् _WSTDIO_DEFINED

#यदि_अपरिभाषितम् WEOF
#परिभाषय WEOF (wint_t)(0xFFFF)
#यदि_अन्तः

#यदि_परिभाषितम् _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3);
#अन्यथा
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3,पूर्णाङ्क _ShFlag);
#यदि_अन्तः
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(शून्य);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(शून्य);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,पूर्णाङ्क आकार_अन्तर्_शब्दाः,FILE *_File);
  पूर्णाङ्क __cdecl fputws(ध्रुव wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP पूर्णाङ्क __cdecl _putws(ध्रुव wchar_t *_Str);
  पूर्णाङ्क __cdecl fwprintf(FILE *_File,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl wprintf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _scwprintf(ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl vfwprintf(FILE *_File,ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl swprintf(wchar_t*, ध्रुव wchar_t*, ...);
  _CRTIMP पूर्णाङ्क __cdecl vswprintf(wchar_t*, ध्रुव wchar_t*,va_list);
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c(wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c(wchar_t *_DstBuf,आकार_t आकार_अन्तर्_शब्दाः,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf(wchar_t *_Dest,आकार_t गणनम्_5,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf(wchar_t *_Dest,आकार_t गणनम्_5,ध्रुव wchar_t *_Format,va_list तर्काः_2);
#यदि_अपरिभाषितम् __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snwprintf (wchar_t* s, आकार_t n, ध्रुव wchar_t*  format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnwprintf (wchar_t* s, आकार_t n, ध्रुव wchar_t* format, va_list arg) { प्रत्यागम _vsnwprintf(s,n,format,arg); }
  पूर्णाङ्क __cdecl vwscanf (ध्रुव wchar_t *, va_list);
  पूर्णाङ्क __cdecl vfwscanf (FILE *,ध्रुव wchar_t *,va_list);
  पूर्णाङ्क __cdecl vswscanf (ध्रुव wchar_t *,ध्रुव wchar_t *,va_list);
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _swprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,va_list तर्काः_2);

#यदि_अपरिभाषितम् RC_INVOKED
#अन्तर्भाव <vadefs.h>
#यदि_अन्तः

#यदि_परिभाषितम् _CRT_NON_CONFORMING_SWPRINTFS
#यदि_अपरिभाषितम् __cplusplus
#परिभाषय swprintf _swprintf
#परिभाषय vswprintf _vswprintf
#परिभाषय _swprintf_l __swprintf_l
#परिभाषय _vswprintf_l __vswprintf_l
#यदि_अन्तः
#यदि_अन्तः

  _CRTIMP wchar_t *__cdecl _wtempnam(ध्रुव wchar_t *_Directory,ध्रुव wchar_t *File_उपसर्गः);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl fwscanf(FILE *_File,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl swscanf(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf(ध्रुव wchar_t *_Src,आकार_t Max_गणनम्,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl wscanf(ध्रुव wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(पूर्णाङ्क _FileHandle ,ध्रुव wchar_t *बहुलकम्_3);
  _CRTIMP FILE *__cdecl _wfopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3);
  _CRTIMP FILE *__cdecl _wfreopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *बहुलकम्_3,FILE *_OldFile);
#यदि_अपरिभाषितम् _CRT_WPERROR_DEFINED
#परिभाषय _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_सन्देशः);
#यदि_अन्तः
  _CRTIMP FILE *__cdecl _wpopen(ध्रुव wchar_t *_Command,ध्रुव wchar_t *बहुलकम्_3);
#यदि !defined(NO_OLDNAMES) && !defined(wpopen)
#परिभाषय wpopen  _wpopen
#यदि_अन्तः
  _CRTIMP पूर्णाङ्क __cdecl _wremove(ध्रुव wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *बफर_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#अपरिभाषय _CRT_GETPUTWCHAR_NOINLINE

#यदि !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#परिभाषय getwchar() fgetwc(stdin)
#परिभाषय putwchar(_c) fputwc((_c),stdout)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() { प्रत्यागम (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { प्रत्यागम (fputwc(_C,stdout)); }
#यदि_अन्तः

#परिभाषय getwc(_stm) fgetwc(_stm)
#परिभाषय putwc(_c,_stm) fputwc(_c,_stm)
#परिभाषय _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#परिभाषय _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#परिभाषय _WSTDIO_DEFINED
#यदि_अन्तः

#परिभाषय _STDIO_DEFINED
#यदि_अन्तः

#परिभाषय _fgetc_nolock(प्रवाहः_2) (--(प्रवाहः_2)->_cnt >= 0 ? 0xff & *(प्रवाहः_2)->_ptr++ : _filbuf(प्रवाहः_2))
#परिभाषय _fputc_nolock(_c,प्रवाहः_2) (--(प्रवाहः_2)->_cnt >= 0 ? 0xff & (*(प्रवाहः_2)->_ptr++ = (वर्ण)(_c)) : _flsbuf((_c),(प्रवाहः_2)))
#परिभाषय _getc_nolock(प्रवाहः_2) _fgetc_nolock(प्रवाहः_2)
#परिभाषय _putc_nolock(_c,प्रवाहः_2) _fputc_nolock(_c,प्रवाहः_2)
#परिभाषय _getchar_nolock() _getc_nolock(stdin)
#परिभाषय _putchar_nolock(_c) _putc_nolock((_c),stdout)
#परिभाषय _getwchar_nolock() _getwc_nolock(stdin)
#परिभाषय _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP शून्य __cdecl तालकम्_file(FILE *_File);
  _CRTIMP शून्य __cdecl _unlock_file(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP आकार_t __cdecl _fread_nolock(शून्य *_DstBuf,आकार_t Element_आकार,आकार_t गणनम्_5,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fseek_nolock(FILE *_File,दीर्घ विस्थापनम्_2,पूर्णाङ्क _Origin);
  _CRTIMP दीर्घ __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fseeki64_nolock(FILE *_File,__int64 विस्थापनम्_2,पूर्णाङ्क _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP आकार_t __cdecl _fwrite_nolock(ध्रुव शून्य *_DstBuf,आकार_t आकार_4,आकार_t गणनम्_5,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _ungetc_nolock(पूर्णाङ्क _Ch,FILE *_File);

#यदि !defined(NO_OLDNAMES) || !defined(_POSIX)
#परिभाषय P_tmpdir _P_tmpdir
#परिभाषय SYS_OPEN _SYS_OPEN

  वर्ण *__cdecl tempnam(ध्रुव वर्ण *_Directory,ध्रुव वर्ण *File_उपसर्गः);
  पूर्णाङ्क __cdecl fcloseall(शून्य);
  FILE *__cdecl fdopen(पूर्णाङ्क _FileHandle,ध्रुव वर्ण *_Format);
  पूर्णाङ्क __cdecl fgetchar(शून्य);
  पूर्णाङ्क __cdecl fileno(FILE *_File);
  पूर्णाङ्क __cdecl flushall(शून्य);
  पूर्णाङ्क __cdecl fputchar(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl getw(FILE *_File);
  पूर्णाङ्क __cdecl putw(पूर्णाङ्क _Ch,FILE *_File);
  पूर्णाङ्क __cdecl rmtmp(शून्य);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#अन्तर्भाव <sec_api/stdio_s.h>

#यदि_अन्तः
