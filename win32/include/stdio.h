/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_STDIO
#घोषणा _INC_STDIO

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#घोषणा बफ_मान 512
#घोषणा _NFILE _NSTREAM_
#घोषणा _NSTREAM_ 512
#घोषणा _IOB_ENTRIES 20
#घोषणा खातापूर्ण (-1)

#अगर_अघोषित _FILE_DEFINED
  काष्ठा _iobuf {
    अक्षर *_ptr;
    पूर्णांक _cnt;
    अक्षर *_base;
    पूर्णांक _flag;
    पूर्णांक _file;
    पूर्णांक _charbuf;
    पूर्णांक _bufsiz;
    अक्षर *_tmpfname;
  };
  प्रकार काष्ठा _iobuf खाता;
#घोषणा _FILE_DEFINED
#पूर्ण_अगर

#अगर_घोषित _POSIX_
#घोषणा _P_tmpdir "/"
#घोषणा _wP_tmpdir L"/"
#अन्यथा
#घोषणा _P_tmpdir "\\"
#घोषणा _wP_tmpdir L"\\"
#पूर्ण_अगर

#घोषणा ब_क्षणिक (माप(_P_tmpdir) + 12)

#अगर_घोषित _POSIX_
#घोषणा L_ctermid 9
#घोषणा L_cuserid 32
#पूर्ण_अगर

#घोषणा प्रस्तुत_से 1
#घोषणा अंत_से 2
#घोषणा शुरू_से 0

#घोषणा STDIN_FILENO    0
#घोषणा STDOUT_FILENO   1
#घोषणा STDERR_FILENO   2

#घोषणा खातानाम_उच्च 260
#घोषणा ख_खोलो_उच्च 20
#घोषणा _SYS_OPEN 20
#घोषणा क्षणिक_उच्च 32767

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF_T_DEFINED
#घोषणा _OFF_T_DEFINED
#अगर_अघोषित _OFF_T_
#घोषणा _OFF_T_
  प्रकार दीर्घ _off_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ off_t;
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _OFF64_T_DEFINED
#घोषणा _OFF64_T_DEFINED
  प्रकार दीर्घ दीर्घ _off64_t;
#अगर !defined(NO_OLDNAMES) || defined(_POSIX)
  प्रकार दीर्घ दीर्घ off64_t;
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _STDIO_DEFINED
#अगर_घोषित _WIN64
  _CRTIMP खाता *__cdecl __iob_func(व्योम);
#अन्यथा
#अगर_घोषित _MSVCRT_
बाह्य खाता _iob[];     /* A pointer to an array of FILE */
#घोषणा __iob_func()    (_iob)
#अन्यथा
बाह्य खाता (*_imp___iob)[];    /* A pointer to an array of FILE */
#घोषणा __iob_func()    (*_imp___iob)
#घोषणा _iob __iob_func()
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _FPOS_T_DEFINED
#घोषणा _FPOS_T_DEFINED
#अघोषित _FPOSOFF

#अगर (!defined(NO_OLDNAMES) || defined(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  प्रकार __int64 ख_स्थान_प्रकार;
#घोषणा _FPOSOFF(fp) ((दीर्घ)(fp))
#अन्यथा
  प्रकार दीर्घ दीर्घ ख_स्थान_प्रकार;
#घोषणा _FPOSOFF(fp) ((दीर्घ)(fp))
#पूर्ण_अगर

#पूर्ण_अगर

#अगर_अघोषित _STDSTREAM_DEFINED
#घोषणा _STDSTREAM_DEFINED

#घोषणा मानक_निवेश (&__iob_func()[0])
#घोषणा मानक_निकास (&__iob_func()[1])
#घोषणा मानक_त्रुटि (&__iob_func()[2])
#पूर्ण_अगर

#घोषणा _IOREAD 0x0001
#घोषणा _IOWRT 0x0002

#घोषणा _IOFBF 0x0000
#घोषणा _IOLBF 0x0040
#घोषणा _IONBF 0x0004

#घोषणा _IOMYBUF 0x0008
#घोषणा _IOEOF 0x0010
#घोषणा _IOERR 0x0020
#घोषणा _IOSTRG 0x0040
#घोषणा _IORW 0x0080
#अगर_घोषित _POSIX_
#घोषणा _IOAPPEND 0x0200
#पूर्ण_अगर

#घोषणा _TWO_DIGIT_EXPONENT 0x1

#अगर_अघोषित _STDIO_DEFINED

  _CRTIMP पूर्णांक __cdecl _filbuf(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _flsbuf(पूर्णांक _Ch,खाता *_File);
#अगर_घोषित _POSIX_
  _CRTIMP खाता *__cdecl _fsopen(स्थिर अक्षर *_Filename,स्थिर अक्षर *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _fsopen(स्थिर अक्षर *_Filename,स्थिर अक्षर *_Mode,पूर्णांक _ShFlag);
#पूर्ण_अगर
  व्योम __cdecl साफ_त्रुटि(खाता *_File);
  पूर्णांक __cdecl ख_बंद(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fcloseall(व्योम);
#अगर_घोषित _POSIX_
  खाता *__cdecl fdopen(पूर्णांक _FileHandle,स्थिर अक्षर *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _fdopen(पूर्णांक _FileHandle,स्थिर अक्षर *_Mode);
#पूर्ण_अगर
  पूर्णांक __cdecl ख_पूर्ण(खाता *_File);
  पूर्णांक __cdecl ख_त्रुटि(खाता *_File);
  पूर्णांक __cdecl ख_साफ(खाता *_File);
  पूर्णांक __cdecl ख_अक्षर_लो(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fgetchar(व्योम);
  पूर्णांक __cdecl ख_स्थान_लो(खाता *_File ,ख_स्थान_प्रकार *_Pos);
  अक्षर *__cdecl ख_माला_लो(अक्षर *_Buf,पूर्णांक Max_गिनती,खाता *_File);
#अगर_घोषित _POSIX_
  पूर्णांक __cdecl fileno(खाता *_File);
#अन्यथा
  _CRTIMP पूर्णांक __cdecl _fileno(खाता *_File);
#पूर्ण_अगर
  _CRTIMP अक्षर *__cdecl _tempnam(स्थिर अक्षर *_DirName,स्थिर अक्षर *_FilePrefix);
  _CRTIMP पूर्णांक __cdecl _flushall(व्योम);
  खाता *__cdecl ख_खोलो(स्थिर अक्षर *_Filename,स्थिर अक्षर *_Mode);
  खाता *fopen64(स्थिर अक्षर *filename,स्थिर अक्षर *mode);
  पूर्णांक __cdecl ख_लिखो(खाता *_File,स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl ख_अक्षर_दो(पूर्णांक _Ch,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fputchar(पूर्णांक _Ch);
  पूर्णांक __cdecl ख_माला_दो(स्थिर अक्षर *_Str,खाता *_File);
  माप_प्रकार __cdecl ख_पढ़ो(व्योम *_DstBuf,माप_प्रकार Element_आकार,माप_प्रकार गिनती_5,खाता *_File);
  खाता *__cdecl ख_व_खोलो(स्थिर अक्षर *_Filename,स्थिर अक्षर *_Mode,खाता *_File);
  पूर्णांक __cdecl ख_पूछो(खाता *_File,स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl ख_स्थान_दो(खाता *_File,स्थिर ख_स्थान_प्रकार *_Pos);
  पूर्णांक __cdecl ख_जाओ(खाता *_File,दीर्घ _Offset,पूर्णांक _Origin);
   पूर्णांक fseeko64(खाता* stream, _off64_t offset, पूर्णांक whence);
  दीर्घ __cdecl ख_बताओ(खाता *_File);
  _off64_t ftello64(खाता * stream);
  पूर्णांक __cdecl _fseeki64(खाता *_File,__int64 _Offset,पूर्णांक _Origin);
  __int64 __cdecl _ftelli64(खाता *_File);
  माप_प्रकार __cdecl ख_डालो(स्थिर व्योम *_Str,माप_प्रकार आकार_4,माप_प्रकार गिनती_5,खाता *_File);
  पूर्णांक __cdecl अ_लो(खाता *_File);
  पूर्णांक __cdecl अक्षर_लो(व्योम);
  _CRTIMP पूर्णांक __cdecl _getmaxstdio(व्योम);
  अक्षर *__cdecl माला_लो(अक्षर *बफर_2);
  पूर्णांक __cdecl _getw(खाता *_File);
#अगर_अघोषित _CRT_PERROR_DEFINED
#घोषणा _CRT_PERROR_DEFINED
  व्योम __cdecl लिखो_त्रुटि(स्थिर अक्षर *Err_संदेश);
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _pclose(खाता *_File);
  _CRTIMP खाता *__cdecl _popen(स्थिर अक्षर *_Command,स्थिर अक्षर *_Mode);
#अगर !defined(NO_OLDNAMES) && !defined(popen)
#घोषणा popen   _popen
#घोषणा pclose  _pclose
#पूर्ण_अगर
  पूर्णांक __cdecl म_लिखो(स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl अ_दो(पूर्णांक _Ch,खाता *_File);
  पूर्णांक __cdecl अक्षर_दो(पूर्णांक _Ch);
  पूर्णांक __cdecl माला_दो(स्थिर अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _putw(पूर्णांक _Word,खाता *_File);
#अगर_अघोषित _CRT_DIRECTORY_DEFINED
#घोषणा _CRT_DIRECTORY_DEFINED
  पूर्णांक __cdecl हटाओ(स्थिर अक्षर *_Filename);
  पूर्णांक __cdecl नाम(स्थिर अक्षर *_OldFilename,स्थिर अक्षर *_NewFilename);
  _CRTIMP पूर्णांक __cdecl _unlink(स्थिर अक्षर *_Filename);
#अगर_अघोषित NO_OLDNAMES
  पूर्णांक __cdecl unlink(स्थिर अक्षर *_Filename);
#पूर्ण_अगर
#पूर्ण_अगर
  व्योम __cdecl शुरुआत(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _rmtmp(व्योम);
  पूर्णांक __cdecl म_पूछो(स्थिर अक्षर *_Format,...);
  व्योम __cdecl रखो_बफ(खाता *_File,अक्षर *बफर_2);
  _CRTIMP पूर्णांक __cdecl _setmaxstdio(पूर्णांक _Max);
  _CRTIMP अचिन्हित पूर्णांक __cdecl _set_output_format(अचिन्हित पूर्णांक _Format);
  _CRTIMP अचिन्हित पूर्णांक __cdecl _get_output_format(व्योम);
  पूर्णांक __cdecl रखो_भबफ(खाता *_File,अक्षर *_Buf,पूर्णांक _Mode,माप_प्रकार आकार_4);
  _CRTIMP पूर्णांक __cdecl _scprintf(स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl माला_पूछो(स्थिर अक्षर *_Src,स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snscanf(स्थिर अक्षर *_Src,माप_प्रकार Max_गिनती,स्थिर अक्षर *_Format,...);
  खाता *__cdecl क्षणिक_ख(व्योम);
  अक्षर *__cdecl क्षणिक(अक्षर *बफर_2);
  पूर्णांक __cdecl अक्षर_वापस(पूर्णांक _Ch,खाता *_File);
  पूर्णांक __cdecl भख_लिखो(खाता *_File,स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl भ_लिखो(स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  /* Make sure macros are not defined.  */
#आशय धकेलो_macro("vsnprintf")
#आशय धकेलो_macro("snprintf")
# undef vsnprintf
# undef snprintf
  बाह्य
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  पूर्णांक __mingw_vsnprintf(अक्षर *_DstBuf,माप_प्रकार Max_गिनती,स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  बाह्य
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  पूर्णांक __mingw_snprintf(अक्षर* s, माप_प्रकार n, स्थिर अक्षर*  format, ...);
  पूर्णांक __cdecl vsnprintf(अक्षर *_DstBuf,माप_प्रकार Max_गिनती,स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snprintf(अक्षर *_Dest,माप_प्रकार गिनती_5,स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnprintf(अक्षर *_Dest,माप_प्रकार गिनती_5,स्थिर अक्षर *_Format,बहु_सूची _Args);
  पूर्णांक __cdecl प्र_लिखो(अक्षर *_Dest,स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl भम_लिखो(अक्षर *_Dest,स्थिर अक्षर *_Format,बहु_सूची _Args);
#अगर_अघोषित __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णांक __cdecl snprintf(अक्षर* s, माप_प्रकार n, स्थिर अक्षर*  format, ...);
  __CRT_INLINE पूर्णांक __cdecl vsnprintf (अक्षर* s, माप_प्रकार n, स्थिर अक्षर* format,बहु_सूची arg) {
    वापस _vsnprintf ( s, n, format, arg);
  }
  पूर्णांक __cdecl vscanf(स्थिर अक्षर * Format, बहु_सूची argp);
  पूर्णांक __cdecl vfscanf (खाता * fp, स्थिर अक्षर * Format,बहु_सूची argp);
  पूर्णांक __cdecl vsscanf (स्थिर अक्षर * _Str,स्थिर अक्षर * Format,बहु_सूची argp);
#पूर्ण_अगर
/* Restore may prior defined macros snprintf/vsnprintf.  */
#आशय निकालो_macro("snprintf")
#आशय निकालो_macro("vsnprintf")
/* Check if vsnprintf and snprintf are defaulting to gnu-style.  */
# अगर defined(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# ifndef vsnprint
# define vsnprintf __mingw_vsnprintf
# endif
# ifndef snprintf
# define snprintf __mingw_snprintf
# endif
# endif
  _CRTIMP पूर्णांक __cdecl _vscprintf(स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl set_printf_गिनती_output(पूर्णांक मूल्य_2);
  _CRTIMP पूर्णांक __cdecl get_printf_गिनती_output(व्योम);

#अगर_अघोषित _WSTDIO_DEFINED

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

#अगर_घोषित _POSIX_
  _CRTIMP खाता *__cdecl _wfsopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode);
#अन्यथा
  _CRTIMP खाता *__cdecl _wfsopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode,पूर्णांक _ShFlag);
#पूर्ण_अगर
  wint_t __cdecl fgetwc(खाता *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(व्योम);
  wint_t __cdecl fputwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _fputwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl getwc(खाता *_File);
  wint_t __cdecl getwchar(व्योम);
  wint_t __cdecl putwc(ब_अक्षर_प्रकार _Ch,खाता *_File);
  wint_t __cdecl putwchar(ब_अक्षर_प्रकार _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,खाता *_File);
  ब_अक्षर_प्रकार *__cdecl fgetws(ब_अक्षर_प्रकार *_Dst,पूर्णांक आकार_In_शब्दगण,खाता *_File);
  पूर्णांक __cdecl fputws(स्थिर ब_अक्षर_प्रकार *_Str,खाता *_File);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _getws(ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णांक __cdecl _putws(स्थिर ब_अक्षर_प्रकार *_Str);
  पूर्णांक __cdecl fwprintf(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wprintf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _scwprintf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl vfwprintf(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl vwprintf(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl swprintf(ब_अक्षर_प्रकार*, स्थिर ब_अक्षर_प्रकार*, ...);
  _CRTIMP पूर्णांक __cdecl vswprintf(ब_अक्षर_प्रकार*, स्थिर ब_अक्षर_प्रकार*,बहु_सूची);
  _CRTIMP पूर्णांक __cdecl _swprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf_c(ब_अक्षर_प्रकार *_DstBuf,माप_प्रकार आकार_In_शब्दगण,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _snwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार गिनती_5,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vsnwprintf(ब_अक्षर_प्रकार *_Dest,माप_प्रकार गिनती_5,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);
#अगर_अघोषित __NO_ISOCEXT  /* externs in libmingwex.a */
  पूर्णांक __cdecl snwprintf (ब_अक्षर_प्रकार* s, माप_प्रकार n, स्थिर ब_अक्षर_प्रकार*  format, ...);
  __CRT_INLINE पूर्णांक __cdecl vsnwprintf (ब_अक्षर_प्रकार* s, माप_प्रकार n, स्थिर ब_अक्षर_प्रकार* format, बहु_सूची arg) { वापस _vsnwprintf(s,n,format,arg); }
  पूर्णांक __cdecl vwscanf (स्थिर ब_अक्षर_प्रकार *, बहु_सूची);
  पूर्णांक __cdecl vfwscanf (खाता *,स्थिर ब_अक्षर_प्रकार *,बहु_सूची);
  पूर्णांक __cdecl vswscanf (स्थिर ब_अक्षर_प्रकार *,स्थिर ब_अक्षर_प्रकार *,बहु_सूची);
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _swprintf(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vswprintf(ब_अक्षर_प्रकार *_Dest,स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _Args);

#अगर_अघोषित RC_INVOKED
#समावेश <vadefs.h>
#पूर्ण_अगर

#अगर_घोषित _CRT_NON_CONFORMING_SWPRINTFS
#अगर_अघोषित __cplusplus
#घोषणा swprintf _swprintf
#घोषणा vswprintf _vswprintf
#घोषणा _swprintf_l __swprintf_l
#घोषणा _vswprintf_l __vswprintf_l
#पूर्ण_अगर
#पूर्ण_अगर

  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtempnam(स्थिर ब_अक्षर_प्रकार *_Directory,स्थिर ब_अक्षर_प्रकार *_FilePrefix);
  _CRTIMP पूर्णांक __cdecl _vscwprintf(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  पूर्णांक __cdecl fwscanf(खाता *_File,स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl swscanf(स्थिर ब_अक्षर_प्रकार *_Src,स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _snwscanf(स्थिर ब_अक्षर_प्रकार *_Src,माप_प्रकार Max_गिनती,स्थिर ब_अक्षर_प्रकार *_Format,...);
  पूर्णांक __cdecl wscanf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP खाता *__cdecl _wfdopen(पूर्णांक _FileHandle ,स्थिर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode);
  _CRTIMP खाता *__cdecl _wfreopen(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_Mode,खाता *_OldFile);
#अगर_अघोषित _CRT_WPERROR_DEFINED
#घोषणा _CRT_WPERROR_DEFINED
  _CRTIMP व्योम __cdecl _wperror(स्थिर ब_अक्षर_प्रकार *Err_संदेश);
#पूर्ण_अगर
  _CRTIMP खाता *__cdecl _wpopen(स्थिर ब_अक्षर_प्रकार *_Command,स्थिर ब_अक्षर_प्रकार *_Mode);
#अगर !defined(NO_OLDNAMES) && !defined(wpopen)
#घोषणा wpopen  _wpopen
#पूर्ण_अगर
  _CRTIMP पूर्णांक __cdecl _wremove(स्थिर ब_अक्षर_प्रकार *_Filename);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wtmpnam(ब_अक्षर_प्रकार *बफर_2);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(खाता *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(ब_अक्षर_प्रकार _Ch,खाता *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,खाता *_File);

#अघोषित _CRT_GETPUTWCHAR_NOINLINE

#अगर !defined(__cplusplus) || defined(_CRT_GETPUTWCHAR_NOINLINE)
#घोषणा getwchar() fgetwc(मानक_निवेश)
#घोषणा putwchar(_c) fputwc((_c),मानक_निकास)
#अन्यथा
  __CRT_INLINE wint_t __cdecl getwchar() { वापस (fgetwc(मानक_निवेश)); }
  __CRT_INLINE wint_t __cdecl putwchar(ब_अक्षर_प्रकार _C) { वापस (fputwc(_C,मानक_निकास)); }
#पूर्ण_अगर

#घोषणा getwc(_stm) fgetwc(_stm)
#घोषणा putwc(_c,_stm) fputwc(_c,_stm)
#घोषणा _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#घोषणा _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#घोषणा _WSTDIO_DEFINED
#पूर्ण_अगर

#घोषणा _STDIO_DEFINED
#पूर्ण_अगर

#घोषणा _fgetc_nolock(_stream) (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#घोषणा _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (अक्षर)(_c)) : _flsbuf((_c),(_stream)))
#घोषणा _getc_nolock(_stream) _fgetc_nolock(_stream)
#घोषणा _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#घोषणा _getchar_nolock() _getc_nolock(मानक_निवेश)
#घोषणा _putchar_nolock(_c) _putc_nolock((_c),मानक_निकास)
#घोषणा _getwchar_nolock() _getwc_nolock(मानक_निवेश)
#घोषणा _putwchar_nolock(_c) _putwc_nolock((_c),मानक_निकास)

  _CRTIMP व्योम __cdecl _lock_file(खाता *_File);
  _CRTIMP व्योम __cdecl _unlock_file(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fclose_nolock(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fflush_nolock(खाता *_File);
  _CRTIMP माप_प्रकार __cdecl _fread_nolock(व्योम *_DstBuf,माप_प्रकार Element_आकार,माप_प्रकार गिनती_5,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fseek_nolock(खाता *_File,दीर्घ _Offset,पूर्णांक _Origin);
  _CRTIMP दीर्घ __cdecl _ftell_nolock(खाता *_File);
  _CRTIMP पूर्णांक __cdecl _fseeki64_nolock(खाता *_File,__int64 _Offset,पूर्णांक _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(खाता *_File);
  _CRTIMP माप_प्रकार __cdecl _fwrite_nolock(स्थिर व्योम *_DstBuf,माप_प्रकार आकार_4,माप_प्रकार गिनती_5,खाता *_File);
  _CRTIMP पूर्णांक __cdecl _ungetc_nolock(पूर्णांक _Ch,खाता *_File);

#अगर !defined(NO_OLDNAMES) || !defined(_POSIX)
#घोषणा P_tmpdir _P_tmpdir
#घोषणा SYS_OPEN _SYS_OPEN

  अक्षर *__cdecl tempnam(स्थिर अक्षर *_Directory,स्थिर अक्षर *_FilePrefix);
  पूर्णांक __cdecl fcloseall(व्योम);
  खाता *__cdecl fdopen(पूर्णांक _FileHandle,स्थिर अक्षर *_Format);
  पूर्णांक __cdecl fgetchar(व्योम);
  पूर्णांक __cdecl fileno(खाता *_File);
  पूर्णांक __cdecl flushall(व्योम);
  पूर्णांक __cdecl fputchar(पूर्णांक _Ch);
  पूर्णांक __cdecl getw(खाता *_File);
  पूर्णांक __cdecl putw(पूर्णांक _Ch,खाता *_File);
  पूर्णांक __cdecl rmtmp(व्योम);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)

#समावेश <sec_api/stdio_s.h>

#पूर्ण_अगर
