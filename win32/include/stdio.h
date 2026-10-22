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

#define बफ_मान 512
#define _NFILE _NSTREAM_
#define _NSTREAM_ 512
#define _IOB_ENTRIES 20
#define खातापूर्ण (-1)

#ifndef _FILE_DEFINED
  संरचना _iobuf {
    अक्षर *_ptr;
    पूर्णांक _cnt;
    अक्षर *_base;
    पूर्णांक _flag;
    पूर्णांक _file;
    पूर्णांक _charbuf;
    पूर्णांक _bufsiz;
    अक्षर *_tmpfname;
  };
  प्रकारव्याख्या संरचना _iobuf खाता;
#define _FILE_DEFINED
#endif

#ifdef _POSIX_
#define _P_tmpdir "/"
#define _wP_tmpdir L"/"
#अन्यथा
#define _P_tmpdir "\\"
#define _wP_tmpdir L"\\"
#endif

#define ब_क्षणिक (आकार(_P_tmpdir) + 12)

#ifdef _POSIX_
#define L_ctermid 9
#define L_cuserid 32
#endif

#define प्रस्तुत_से 1
#define अंत_से 2
#define शुरू_से 0

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

#define खातानाम_उच्च 260
#define ख_खोलो_उच्च 20
#define _SYS_OPEN 20
#define क्षणिक_उच्च 32767

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
  प्रकारव्याख्या दीर्घ _off_t;
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या दीर्घ off_t;
#endif
#endif
#endif

#ifndef _OFF64_T_DEFINED
#define _OFF64_T_DEFINED
  प्रकारव्याख्या दीर्घ दीर्घ _off64_t;
#जर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकारव्याख्या दीर्घ दीर्घ off64_t;
#endif
#endif

#ifndef _STDIO_DEFINED
#ifdef _WIN64
  _CRTIMP खाता *__cdecl __iob_func(शून्य);
#अन्यथा
#ifdef _MSVCRT_
बाह्य खाता _iob[];     /* A pointer to an array of FILE */
#define __iob_func()    (_iob)
#अन्यथा
बाह्य खाता (*_imp___iob)[];    /* A pointer to an array of FILE */
#define __iob_func()    (*_imp___iob)
#define _iob __iob_func()
#endif
#endif
#endif

#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
#undef _FPOSOFF

#जर (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  प्रकारव्याख्या __int64 ख_स्थान_प्रकार;
#define _FPOSOFF(fp) ((दीर्घ)(fp))
#अन्यथा
  प्रकारव्याख्या दीर्घ दीर्घ ख_स्थान_प्रकार;
#define _FPOSOFF(fp) ((दीर्घ)(fp))
#endif

#endif

#ifndef _STDSTREAM_DEFINED
#define _STDSTREAM_DEFINED

#define मानक_निवेश (&__iob_func()[0])
#define मानक_निकास (&__iob_func()[1])
#define मानक_त्रुटि (&__iob_func()[2])
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

  _CRTIMP पूर्णांक __cdecl _filbuf(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _flsbuf(पूर्णांक _Ch,खाता *_File);
#ifdef _POSIX_
  _CRTIMP खाता *__cdecl _fsopen(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _fsopen(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_Mode,पूर्णांक _ShFlag);
#endif
  शून्य __cdecl साफ_त्रुटि(खाता *_File);
  पूर्णांक __cdecl ख_बंद(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fcloseall(शून्य);
#ifdef _POSIX_
  खाता *__cdecl fdopen(पूर्णांक _FileHandle,स्थिरांक अक्षर *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _fdopen(पूर्णांक _FileHandle,स्थिरांक अक्षर *_Mode);
#endif
  पूर्णांक __cdecl ख_पूर्ण(खाता *_File);
  पूर्णांक __cdecl ख_त्रुटि(खाता *_File);
  पूर्णांक __cdecl ख_साफ(खाता *_File);
  पूर्णांक __cdecl ख_अक्षर_लो(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fgetchar(शून्य);
  पूर्णांक __cdecl ख_स्थान_लो(खाता *_File ,ख_स्थान_प्रकार *_Pos);
  अक्षर *__cdecl ख_माला_लो(अक्षर *_Buf,पूर्णांक Max_मोजणी,खाता *_File);
#ifdef _POSIX_
  पूर्णांक __cdecl fileno(खाता *_File);
#अन्यथा
  _CRTIMP पूर्णांक __cdecl _fileno(खाता *_File);
#endif
  _CRTIMP अक्षर *__cdecl _tempnam(स्थिरांक अक्षर *_DirName,स्थिरांक अक्षर *_FilePrefix);
  _CRTIMP पूर्णांक __cdecl _flushall(शून्य);
  खाता *__cdecl ख_खोलो(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_Mode);
  खाता *fopen64(स्थिरांक अक्षर *filename,स्थिरांक अक्षर *mode);
  पूर्णांक __cdecl ख_लिखो(खाता *_File,स्थिरांक अक्षर *_Format,...);
  पूर्णांक __cdecl ख_अक्षर_दो(पूर्णांक _Ch,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fputchar(पूर्णांक _Ch);
  पूर्णांक __cdecl ख_माला_दो(स्थिरांक अक्षर *_Str,खाता *_File);
  माप_प्रकार __cdecl ख_पढ़ो(शून्य *_DstBuf,माप_प्रकार _ElementSize,माप_प्रकार मोजणी_5,खाता *_File);
  खाता *__cdecl ख_व_खोलो(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_Mode,खाता *_File);
  पूर्णांक __cdecl ख_पूछो(खाता *_File,स्थिरांक अक्षर *_Format,...);
  पूर्णांक __cdecl ख_स्थान_दो(खाता *_File,स्थिरांक ख_स्थान_प्रकार *_Pos);
  पूर्णांक __cdecl ख_जाओ(खाता *_File,दीर्घ _Offset,पूर्णांक _Origin);
   पूर्णांक fseeko64(खाता* stream, _off64_t offset, पूर्णांक whence);
  दीर्घ __cdecl ख_बताओ(खाता *_File);
  _off64_t ftello64(खाता * stream);
  पूर्णांक __cdecl _fseeki64(खाता *_File,__int64 _Offset,पूर्णांक _Origin);
  __int64 __cdecl _ftelli64(खाता *_File);
  माप_प्रकार __cdecl ख_डालो(स्थिरांक शून्य *_Str,माप_प्रकार _Size,माप_प्रकार मोजणी_5,खाता *_File);
  पूर्णांक __cdecl अ_लो(खाता *_File);
  पूर्णांक __cdecl अक्षर_लो(शून्य);
  _CRTIMP पूर्णांक __cdecl _getmaxstdio(शून्य);
  अक्षर *__cdecl माला_लो(अक्षर *_Buffer);
  पूर्णांक __cdecl _getw(खाता *_File);
#ifndef _CRT_PERROR_DEFINED
#define _CRT_PERROR_DEFINED
  शून्य __cdecl लिखो_त्रुटि(स्थिरांक अक्षर *Err_संदेश);
#endif
  _CRTIMP पूर्णांक __cdecl _pclose(खाता *_File);
  _CRTIMP खाता *__cdecl _popen(स्थिरांक अक्षर *_Command,स्थिरांक अक्षर *_Mode);
#जर !defined(NO_OLDNAMES) && !defined(popen)
#define popen   _popen
#define pclose  _pclose
#endif
  पूर्णांक __cdecl म_लिखो(स्थिरांक अक्षर *_Format,...);
  पूर्णांक __cdecl अ_दो(पूर्णांक _Ch,खाता *_File);
  पूर्णांक __cdecl अक्षर_दो(पूर्णांक _Ch);
  पूर्णांक __cdecl माला_दो(स्थिरांक अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _putw(पूर्णांक _Word,खाता *_File);
#ifndef _CRT_DIRECTORY_DEFINED
#define _CRT_DIRECTORY_DEFINED
  पूर्णांक __cdecl हटाओ(स्थिरांक अक्षर *_Filename);
  पूर्णांक __cdecl नाम(स्थिरांक अक्षर *_OldFilename,स्थिरांक अक्षर *_NewFilename);
  _CRTIMP पूर्णांक __cdecl _unlink(स्थिरांक अक्षर *_Filename);
#ifndef NO_OLDNAMES
  पूर्णांक __cdecl unlink(स्थिरांक अक्षर *_Filename);
#endif
#endif
  शून्य __cdecl शुरुआत(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _rmtmp(शून्य);
  पूर्णांक __cdecl म_पूछो(स्थिरांक अक्षर *_Format,...);
  शून्य __cdecl रखो_बफ(खाता *_File,अक्षर *_Buffer);
  _CRTIMP पूर्णांक __cdecl _setmaxstdio(पूर्णांक _Max);
  _CRTIMP अचिन्हित पूर्णांक __cdecl _set_output_format(अचिन्हित पूर्णांक _Format);
  _CRTIMP अचिन्हित पूर्णांक __cdecl _get_output_format(शून्य);
  पूर्णांक __cdecl रखो_भबफ(खाता *_File,अक्षर *_Buf,पूर्णांक _Mode,माप_प्रकार _Size);
  _CRTIMP पूर्णांक __cdecl _scprintf(स्थिरांक अक्षर *_Format,...);
  पूर्णांक __cdecl माला_पूछो(स्थिरांक अक्षर *_Src,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snscanf(स्थिरांक अक्षर *_Src,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,...);
  खाता *__cdecl क्षणिक_ख(शून्य);
  अक्षर *__cdecl क्षणिक(अक्षर *_Buffer);
  पूर्णांक __cdecl अक्षर_वापस(पूर्णांक _Ch,खाता *_File);
  पूर्णांक __cdecl भख_लिखो(खाता *_File,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl भ_लिखो(स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  /* Make sure macros are not defined.  */
#pragma ढकला_macro("vsnprintf")
#pragma ढकला_macro("snprintf")
# undef vsnprintf
# undef snprintf
  बाह्य
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  पूर्णांक __mingw_vsnprintf(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  बाह्य
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  पूर्णांक __mingw_snprintf(अक्षर* s, माप_प्रकार n, स्थिरांक अक्षर*  format, ...);
  पूर्णांक __cdecl vsnprintf(अक्षर *_DstBuf,माप_प्रकार Max_मोजणी,स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snprintf(अक्षर *_Dest,माप_प्रकार मोजणी_5,स्थिरांक अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnprintf(अक्षर *_Dest,माप_प्रकार मोजणी_5,स्थिरांक अक्षर *_Format,बहु_सूची _Args);
  पूर्णांक __cdecl प्र_लिखो(अक्षर *_Dest,स्थिरांक अक्षर *_Format,...);
  पूर्णांक __cdecl भम_लिखो(अक्षर *_Dest,स्थिरांक अक्षर *_Format,बहु_सूची _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णांक __cdecl snprintf(अक्षर* s, माप_प्रकार n, स्थिरांक अक्षर*  format, ...);
  __CRT_INLINE पूर्णांक __cdecl vsnprintf (अक्षर* s, माप_प्रकार n, स्थिरांक अक्षर* format,बहु_सूची arg) {
    परत _vsnprintf ( s, n, format, arg);
  }
  पूर्णांक __cdecl vscanf(स्थिरांक अक्षर * Format, बहु_सूची argp);
  पूर्णांक __cdecl vfscanf (खाता * fp, स्थिरांक अक्षर * Format,बहु_सूची argp);
  पूर्णांक __cdecl vsscanf (स्थिरांक अक्षर * _Str,स्थिरांक अक्षर * Format,बहु_सूची argp);
#endif
/* Restore may prior defined macros snprintf/vsnprintf.  */
#pragma काढा_macro("snprintf")
#pragma काढा_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# जर defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP पूर्णांक __cdecl _vscprintf(स्थिरांक अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl set_printf_मोजणी_output(पूर्णांक मूल्य_2);
  _CRTIMP पूर्णांक __cdecl get_printf_मोजणी_output(शून्य);

#ifndef _WSTDIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

#ifdef _POSIX_
  _CRTIMP खाता *__cdecl _wfsopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _wfsopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Mode,पूर्णांक _ShFlag);
#endif
  wint_t __cdecl fgetwc(खाता *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(शून्य);
  wint_t __cdecl fputwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _fputwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl getwc(खाता *_File);
  wint_t __cdecl getwchar(शून्य);
  wint_t __cdecl putwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  wint_t __cdecl putwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,खाता *_File);
  ब_अक्षर_प्रकार *__cdecl fgetws(ब_अक्षर_प्रकार *_Dst,पूर्णांक Size_In_शब्द,खाता *_File);
  पूर्णांक __cdecl fputws(स्थिरांक ब_अक्षर_प्रकार *_Str,खाता *_File);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws(ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णांक __cdecl _putws(स्थिरांक ब_अक्षर_प्रकार *_Str);
  पूर्णांक __cdecl fwprintf(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wprintf(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _scwprintf(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vfwprintf(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vwprintf(स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl swprintf(ब_अक्षर_प्रकार*, स्थिरांक ब_अक्षर_प्रकार*, ...);
  _CRTIMP पूर्णांक __cdecl vswprintf(ब_अक्षर_प्रकार*, स्थिरांक ब_अक्षर_प्रकार*,बहु_सूची);
  _CRTIMP पूर्णांक __cdecl _swprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार Size_In_शब्द,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार मोजणी_5,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार मोजणी_5,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);
#ifndef __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णांक __cdecl snwprintf (ब_अक्षर_प्रकार* s, माप_प्रकार n, स्थिरांक ब_अक्षर_प्रकार*  format, ...);
  __CRT_INLINE पूर्णांक __cdecl vsnwprintf (ब_अक्षर_प्रकार* s, माप_प्रकार n, स्थिरांक ब_अक्षर_प्रकार* format, बहु_सूची arg) { परत _vsnwprintf(s,n,format,arg); }
  पूर्णांक __cdecl vwscanf (स्थिरांक ब_अक्षर_प्रकार *, बहु_सूची);
  पूर्णांक __cdecl vfwscanf (खाता *,स्थिरांक ब_अक्षर_प्रकार *,बहु_सूची);
  पूर्णांक __cdecl vswscanf (स्थिरांक ब_अक्षर_प्रकार *,स्थिरांक ब_अक्षर_प्रकार *,बहु_सूची);
#endif
  _CRTIMP पूर्णांक __cdecl _swprintf(ब_अक्षर_प्रकार *_Dest,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf(ब_अक्षर_प्रकार *_Dest,स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);

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

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtempnam(स्थिरांक ब_अक्षर_प्रकार *_Directory,स्थिरांक ब_अक्षर_प्रकार *_FilePrefix);
  _CRTIMP पूर्णांक __cdecl _vscwprintf(स्थिरांक ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl fwscanf(खाता *_File,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl swscanf(स्थिरांक ब_अक्षर_प्रकार *_Src,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf(स्थिरांक ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_मोजणी,स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wscanf(स्थिरांक ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP खाता *__cdecl _wfdopen(पूर्णांक _FileHandle ,स्थिरांक ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfreopen(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);
#ifndef _CRT_WPERROR_DEFINED
#define _CRT_WPERROR_DEFINED
  _CRTIMP शून्य __cdecl _wperror(स्थिरांक ब_अक्षर_प्रकार *Err_संदेश);
#endif
  _CRTIMP खाता *__cdecl _wpopen(स्थिरांक ब_अक्षर_प्रकार *_Command,स्थिरांक ब_अक्षर_प्रकार *_Mode);
#जर !defined(NO_OLDNAMES) && !defined(wpopen)
#define wpopen  _wpopen
#endif
  _CRTIMP पूर्णांक __cdecl _wremove(स्थिरांक ब_अक्षर_प्रकार *_Filename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtmpnam(ब_अक्षर_प्रकार *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(खाता *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,खाता *_File);

#undef _CRT_GETPUTWCHAR_NOINLINE

#जर !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#define getwchar() fgetwc(मानक_निवेश)
#define putwchar(_c) fputwc((_c),मानक_निकास)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() { परत (fgetwc(मानक_निवेश)); }
  __CRT_INLINE wint_t __cdecl putwchar(ब_अक्षर_प्रकार _C) { परत (fputwc(_C,मानक_निकास)); }
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
#define _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (अक्षर)(_c)) : _flsbuf((_c),(_stream)))
#define _getc_nolock(_stream) _fgetc_nolock(_stream)
#define _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#define _getchar_nolock() _getc_nolock(मानक_निवेश)
#define _putchar_nolock(_c) _putc_nolock((_c),मानक_निकास)
#define _getwchar_nolock() _getwc_nolock(मानक_निवेश)
#define _putwchar_nolock(_c) _putwc_nolock((_c),मानक_निकास)

  _CRTIMP शून्य __cdecl _lock_file(खाता *_File);
  _CRTIMP शून्य __cdecl _unlock_file(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fclose_nolock(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fflush_nolock(खाता *_File);
  _CRTIMP माप_प्रकार __cdecl _fread_nolock(शून्य *_DstBuf,माप_प्रकार _ElementSize,माप_प्रकार मोजणी_5,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fseek_nolock(खाता *_File,दीर्घ _Offset,पूर्णांक _Origin);
  _CRTIMP दीर्घ __cdecl _ftell_nolock(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fseeki64_nolock(खाता *_File,__int64 _Offset,पूर्णांक _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(खाता *_File);
  _CRTIMP माप_प्रकार __cdecl _fwrite_nolock(स्थिरांक शून्य *_DstBuf,माप_प्रकार _Size,माप_प्रकार मोजणी_5,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _ungetc_nolock(पूर्णांक _Ch,खाता *_File);

#जर !defined(NO_OLDNAMES) || !defined(_POSIX)
#define P_tmpdir _P_tmpdir
#define SYS_OPEN _SYS_OPEN

  अक्षर *__cdecl tempnam(स्थिरांक अक्षर *_Directory,स्थिरांक अक्षर *_FilePrefix);
  पूर्णांक __cdecl fcloseall(शून्य);
  खाता *__cdecl fdopen(पूर्णांक _FileHandle,स्थिरांक अक्षर *_Format);
  पूर्णांक __cdecl fgetchar(शून्य);
  पूर्णांक __cdecl fileno(खाता *_File);
  पूर्णांक __cdecl flushall(शून्य);
  पूर्णांक __cdecl fputchar(पूर्णांक _Ch);
  पूर्णांक __cdecl getw(खाता *_File);
  पूर्णांक __cdecl putw(पूर्णांक _Ch,खाता *_File);
  पूर्णांक __cdecl rmtmp(शून्य);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)

#अन्तर्भाव <sec_api/stdio_s.h>

#endif
