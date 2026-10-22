/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_DIRECT
#घोषणा _INC_DIRECT

#समावेश <_mingw.h>
#समावेश <io.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _DISKFREE_T_DEFINED
#घोषणा _DISKFREE_T_DEFINED
  काष्ठा _diskfree_t {
    अचिन्हित योग_clusters;
    अचिन्हित avail_clusters;
    अचिन्हित sectors_per_cluster;
    अचिन्हित bytes_per_sector;
  };
#पूर्ण_अगर

  _CRTIMP अक्षर *__cdecl _getcwd(अक्षर *_DstBuf,पूर्णांक आकार_In_Bytes);
  _CRTIMP अक्षर *__cdecl _getdcwd(पूर्णांक _Drive,अक्षर *_DstBuf,पूर्णांक आकार_In_Bytes);
  अक्षर *__cdecl _getdcwd_nolock(पूर्णांक _Drive,अक्षर *_DstBuf,पूर्णांक आकार_In_Bytes);
  _CRTIMP पूर्णांक __cdecl _chdir(स्थिर अक्षर *_Path);
  _CRTIMP पूर्णांक __cdecl _mkdir(स्थिर अक्षर *_Path);
  _CRTIMP पूर्णांक __cdecl _rmdir(स्थिर अक्षर *_Path);
  _CRTIMP पूर्णांक __cdecl _chdrive(पूर्णांक _Drive);
  _CRTIMP पूर्णांक __cdecl _getdrive(व्योम);
  _CRTIMP अचिन्हित दीर्घ __cdecl _getdrives(व्योम);

#अगर_अघोषित _GETDISKFREE_DEFINED
#घोषणा _GETDISKFREE_DEFINED
  _CRTIMP अचिन्हित __cdecl _getdiskfree(अचिन्हित _Drive,काष्ठा _diskfree_t *_DiskFree);
#पूर्ण_अगर

#अगर_अघोषित _WDIRECT_DEFINED
#घोषणा _WDIRECT_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetcwd(ब_अक्षर_प्रकार *_DstBuf,पूर्णांक आकार_In_शब्दगण);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetdcwd(पूर्णांक _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक आकार_In_शब्दगण);
  ब_अक्षर_प्रकार *__cdecl _wgetdcwd_nolock(पूर्णांक _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक आकार_In_शब्दगण);
  _CRTIMP पूर्णांक __cdecl _wchdir(स्थिर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णांक __cdecl _wmkdir(स्थिर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णांक __cdecl _wrmdir(स्थिर ब_अक्षर_प्रकार *_Path);
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES

#घोषणा diskfree_t _diskfree_t

  अक्षर *__cdecl getcwd(अक्षर *_DstBuf,पूर्णांक आकार_In_Bytes);
  पूर्णांक __cdecl स_बदलो(स्थिर अक्षर *_Path);
  पूर्णांक __cdecl सूची_गढ़ो(स्थिर अक्षर *_Path);
  पूर्णांक __cdecl सूची_हटाओ(स्थिर अक्षर *_Path);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
