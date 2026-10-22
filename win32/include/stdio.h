/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_STDIO
#define _INC_STDIO

#अन्तर्भाव <_mingw.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#define BUFSIZ 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define EOF (-1)

#ifndef _FILE_DEFINED
  संरचना _iobuf {
    वर्ण *_ptr;
    पूर्णाङ्क _cnt;
    वर्ण *_base;
    पूर्णाङ्क _flag;
    पूर्णाङ्क _file;
    पूर्णाङ्क _charbuf;
    पूर्णाङ्क _bufsiz;
    वर्ण *_tmpfname;
  };
  प्रकारनिर्देश संरचना _iobuf FILE;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#अन्यथा
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define L_tmpnam (परिमाण(_P_tmpdir) + 12)

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

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अन्यथा
#define रिक्त ((शून्य *)0)
#endif
#endif

#ifndef _OFF_T_DEFINED
#define _OFF_T_DEFINED
#ifndef _OFF_T_
#define _OFF_T_
  प्रकारनिर्देश long _off_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश long off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  प्रकारनिर्देश long long _off64_t;
#यदि !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारनिर्देश long long off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP FILE *__cdecl __iob_func(शून्य);
#अन्यथा
#ifdef _MSVCRT_
बाह्य FILE _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#अन्यथा
बाह्य FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#यदि (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  प्रकारनिर्देश __int64 fpos_t;
#define _FPOSOFF(fp) ((long)(fp))
#अन्यथा
  प्रकारनिर्देश long long fpos_t;
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

  _CRTIMP पूर्णाङ्क __cdecl _filbuf(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _flsbuf(पूर्णाङ्क _Ch,FILE *_File);
#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Mode);
#अन्यथा
  _CRTIMP FILE *__cdecl _fsopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Mode,पूर्णाङ्क _ShFlag);
#endif
  शून्य __cdecl clearerr(FILE *_File);
  पूर्णाङ्क __cdecl fclose(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fcloseall(शून्य);
#ifdef _POSIX_
  FILE *__cdecl fdopen(पूर्णाङ्क _FileHandle,ध्रुव वर्ण *_Mode);
#अन्यथा
  _CRTIMP FILE *__cdecl _fdopen(पूर्णाङ्क _FileHandle,ध्रुव वर्ण *_Mode);
#endif
  पूर्णाङ्क __cdecl feof(FILE *_File);
  पूर्णाङ्क __cdecl ferror(FILE *_File);
  पूर्णाङ्क __cdecl fflush(FILE *_File);
  पूर्णाङ्क __cdecl fgetc(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fgetchar(शून्य);
  पूर्णाङ्क __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  वर्ण *__cdecl fgets(वर्ण *_Buf,पूर्णाङ्क Max_मोजणी,FILE *_File);
#ifdef _POSIX_
  पूर्णाङ्क __cdecl fileno(FILE *_File);
#अन्यथा
  _CRTIMP पूर्णाङ्क __cdecl _fileno(FILE *_File);
#endif
  _CRTIMP वर्ण *__cdecl _tempnam(ध्रुव वर्ण *_DirName,ध्रुव वर्ण *_FilePrefix);
  _CRTIMP पूर्णाङ्क __cdecl _flushall(शून्य);
  FILE *__cdecl fopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Mode);
  FILE *fopen64(ध्रुव वर्ण *filename,ध्रुव वर्ण *mode);
  पूर्णाङ्क __cdecl fprintf(FILE *_File,ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl fputc(पूर्णाङ्क _Ch,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fputchar(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl fputs(ध्रुव वर्ण *_Str,FILE *_File);
  size_t __cdecl fread(शून्य *_DstBuf,size_t _ElementSize,size_t मोजणी_5,FILE *_File);
  FILE *__cdecl freopen(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_Mode,FILE *_File);
  पूर्णाङ्क __cdecl fscanf(FILE *_File,ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl fsetpos(FILE *_File,ध्रुव fpos_t *_Pos);
  पूर्णाङ्क __cdecl fseek(FILE *_File,long _Offset,पूर्णाङ्क _Origin);
   पूर्णाङ्क fseeko64(FILE* stream, _off64_t offset, पूर्णाङ्क whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  पूर्णाङ्क __cdecl _fseeki64(FILE *_File,__int64 _Offset,पूर्णाङ्क _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(ध्रुव शून्य *_Str,size_t _Size,size_t मोजणी_5,FILE *_File);
  पूर्णाङ्क __cdecl getc(FILE *_File);
  पूर्णाङ्क __cdecl getchar(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getmaxstdio(शून्य);
  वर्ण *__cdecl gets(वर्ण *_Buffer);
  पूर्णाङ्क __cdecl _getw(FILE *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  शून्य __cdecl perror(ध्रुव वर्ण *Err_संदेश);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(ध्रुव वर्ण *_Command,ध्रुव वर्ण *_Mode);
#यदि !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  पूर्णाङ्क __cdecl printf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl putc(पूर्णाङ्क _Ch,FILE *_File);
  पूर्णाङ्क __cdecl putchar(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl puts(ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _putw(पूर्णाङ्क _Word,FILE *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  पूर्णाङ्क __cdecl remove(ध्रुव वर्ण *_Filename);
  पूर्णाङ्क __cdecl rename(ध्रुव वर्ण *_OldFilename,ध्रुव वर्ण *_NewFilename);
  _CRTIMP पूर्णाङ्क __cdecl _unlink(ध्रुव वर्ण *_Filename);
#ifndef NO_OLDNAMES
  पूर्णाङ्क __cdecl unlink(ध्रुव वर्ण *_Filename);
#endif
#endif
  शून्य __cdecl rewind(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _rmtmp(शून्य);
  पूर्णाङ्क __cdecl scanf(ध्रुव वर्ण *_Format,...);
  शून्य __cdecl setbuf(FILE *_File,वर्ण *_Buffer);
  _CRTIMP पूर्णाङ्क __cdecl _setmaxstdio(पूर्णाङ्क _Max);
  _CRTIMP unsigned पूर्णाङ्क __cdecl _set_output_format(unsigned पूर्णाङ्क _Format);
  _CRTIMP unsigned पूर्णाङ्क __cdecl _get_output_format(शून्य);
  पूर्णाङ्क __cdecl setvbuf(FILE *_File,वर्ण *_Buf,पूर्णाङ्क _Mode,size_t _Size);
  _CRTIMP पूर्णाङ्क __cdecl _scprintf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl sscanf(ध्रुव वर्ण *_Src,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snscanf(ध्रुव वर्ण *_Src,size_t Max_मोजणी,ध्रुव वर्ण *_Format,...);
  FILE *__cdecl tmpfile(शून्य);
  वर्ण *__cdecl tmpnam(वर्ण *_Buffer);
  पूर्णाङ्क __cdecl ungetc(पूर्णाङ्क _Ch,FILE *_File);
  पूर्णाङ्क __cdecl vfprintf(FILE *_File,ध्रुव वर्ण *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl vprintf(ध्रुव वर्ण *_Format,va_list _ArgList);
  /* Make sure macros are not defined.  */
#pragma ढकला_macro("vsnprintf")
#pragma ढकला_macro("snprintf")
# undef vsnprintf
# undef snprintf
  बाह्य
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  पूर्णाङ्क __mingw_vsnprintf(वर्ण *_DstBuf,size_t Max_मोजणी,ध्रुव वर्ण *_Format,va_list _ArgList);
  बाह्य
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  पूर्णाङ्क __mingw_snprintf(वर्ण* s, size_t n, ध्रुव वर्ण*  format, ...);
  पूर्णाङ्क __cdecl vsnprintf(वर्ण *_DstBuf,size_t Max_मोजणी,ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snprintf(वर्ण *_Dest,size_t मोजणी_5,ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnprintf(वर्ण *_Dest,size_t मोजणी_5,ध्रुव वर्ण *_Format,va_list _Args);
  पूर्णाङ्क __cdecl sprintf(वर्ण *_Dest,ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl vsprintf(वर्ण *_Dest,ध्रुव वर्ण *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snprintf(वर्ण* s, size_t n, ध्रुव वर्ण*  format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnprintf (वर्ण* s, size_t n, ध्रुव वर्ण* format,va_list arg) {
    प्रत्यागम _vsnprintf ( s, n, format, arg);
  }
  पूर्णाङ्क __cdecl vscanf(ध्रुव वर्ण * Format, va_list argp);
  पूर्णाङ्क __cdecl vfscanf (FILE * fp, ध्रुव वर्ण * Format,va_list argp);
  पूर्णाङ्क __cdecl vsscanf (ध्रुव वर्ण * _Str,ध्रुव वर्ण * Format,va_list argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma काढा_macro("snprintf")
#pragma काढा_macro("vsnprintf")
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
  _CRTIMP पूर्णाङ्क __cdecl set_printf_मोजणी_output(पूर्णाङ्क मूल्य_2);
  _CRTIMP पूर्णाङ्क __cdecl get_printf_मोजणी_output(शून्य);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode);
#अन्यथा
  _CRTIMP FILE *__cdecl _wfsopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode,पूर्णाङ्क _ShFlag);
#endif
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(शून्य);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(शून्य);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,पूर्णाङ्क Size_In_शब्द,FILE *_File);
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
  _CRTIMP पूर्णाङ्क __cdecl _swprintf_c(wchar_t *_DstBuf,size_t Size_In_शब्द,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t Size_In_शब्द,ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _snwprintf(wchar_t *_Dest,size_t मोजणी_5,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vsnwprintf(wchar_t *_Dest,size_t मोजणी_5,ध्रुव wchar_t *_Format,va_list _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णाङ्क __cdecl snwprintf (wchar_t* s, size_t n, ध्रुव wchar_t*  format, ...);
  __CRT_INLINE पूर्णाङ्क __cdecl vsnwprintf (wchar_t* s, size_t n, ध्रुव wchar_t* format, va_list arg) { प्रत्यागम _vsnwprintf(s,n,format,arg); }
  पूर्णाङ्क __cdecl vwscanf (ध्रुव wchar_t *, va_list);
  पूर्णाङ्क __cdecl vfwscanf (FILE *,ध्रुव wchar_t *,va_list);
  पूर्णाङ्क __cdecl vswscanf (ध्रुव wchar_t *,ध्रुव wchar_t *,va_list);
#endif
  _CRTIMP पूर्णाङ्क __cdecl _swprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vswprintf(wchar_t *_Dest,ध्रुव wchar_t *_Format,va_list _Args);

#ifndef RC_INVOKED
#अन्तर्भाव <vadefs.h>
#endif

#ifdef _CRT_NON_CONFORMING_SWPRINTFS
#ifndef __cplusplus
#define swprintf _swprintf
#define vswprintf _vswprintf
#define _swprintf_l __swprintf_l
#define _vswprintf_l __vswprintf_l
#endif
#endif

  _CRTIMP wchar_t *__cdecl _wtempnam(ध्रुव wchar_t *_Directory,ध्रुव wchar_t *_FilePrefix);
  _CRTIMP पूर्णाङ्क __cdecl _vscwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  पूर्णाङ्क __cdecl fwscanf(FILE *_File,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl swscanf(ध्रुव wchar_t *_Src,ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _snwscanf(ध्रुव wchar_t *_Src,size_t Max_मोजणी,ध्रुव wchar_t *_Format,...);
  पूर्णाङ्क __cdecl wscanf(ध्रुव wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(पूर्णाङ्क _FileHandle ,ध्रुव wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_Mode,FILE *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(ध्रुव wchar_t *Err_संदेश);
#endif
  _CRTIMP FILE *__cdecl _wpopen(ध्रुव wchar_t *_Command,ध्रुव wchar_t *_Mode);
#यदि !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP पूर्णाङ्क __cdecl _wremove(ध्रुव wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#यदि !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(stdin)
#define putwchar(_c) fputwc((_c),stdout)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() { प्रत्यागम (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { प्रत्यागम (fputwc(_C,stdout)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (वर्ण)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(stdin)
#define _putchar_nolock(_c) _putc_nolock((_c),stdout)
#define _getwchar_nolock() _getwc_nolock(stdin)
#define _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP शून्य __cdecl _lock_file(FILE *_File);
  _CRTIMP शून्य __cdecl _unlock_file(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(शून्य *_DstBuf,size_t _ElementSize,size_t मोजणी_5,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fseek_nolock(FILE *_File,long _Offset,पूर्णाङ्क _Origin);
  _CRTIMP long __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,पूर्णाङ्क _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(ध्रुव शून्य *_DstBuf,size_t _Size,size_t मोजणी_5,FILE *_File);
  _CRTIMP पूर्णाङ्क __cdecl _ungetc_nolock(पूर्णाङ्क _Ch,FILE *_File);

#यदि !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  वर्ण *__cdecl tempnam(ध्रुव वर्ण *_Directory,ध्रुव वर्ण *_FilePrefix);
  पूर्णाङ्क __cdecl fcloseall(शून्य);
  FILE *__cdecl fdopen(पूर्णाङ्क _FileHandle,ध्रुव वर्ण *_Format);
  पूर्णाङ्क __cdecl fgetchar(शून्य);
  पूर्णाङ्क __cdecl fileno(FILE *_File);
  पूर्णाङ्क __cdecl flushall(शून्य);
  पूर्णाङ्क __cdecl fputchar(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl getw(FILE *_File);
  पूर्णाङ्क __cdecl putw(पूर्णाङ्क _Ch,FILE *_File);
  पूर्णाङ्क __cdecl rmtmp(शून्य);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)

#अन्तर्भाव <sec_api/stdio_s.h>

#endif
