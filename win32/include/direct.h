/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  संरचना _diskfree_t {
    अचिन्हित total_clusters;
    अचिन्हित avail_clusters;
    अचिन्हित sectors_per_cluster;
    अचिन्हित bytes_per_sector;
  };
#endif

  _CRTIMP अक्षर *__cdecl _getcwd(अक्षर *_DstBuf,पूर्णांक _SizeInBytes);
  _CRTIMP अक्षर *__cdecl _getdcwd(पूर्णांक _Drive,अक्षर *_DstBuf,पूर्णांक _SizeInBytes);
  अक्षर *__cdecl _getdcwd_nolock(पूर्णांक _Drive,अक्षर *_DstBuf,पूर्णांक _SizeInBytes);
  _CRTIMP पूर्णांक __cdecl _chdir(स्थिरांक अक्षर *_Path);
  _CRTIMP पूर्णांक __cdecl _mkdir(स्थिरांक अक्षर *_Path);
  _CRTIMP पूर्णांक __cdecl _rmdir(स्थिरांक अक्षर *_Path);
  _CRTIMP पूर्णांक __cdecl _chdrive(पूर्णांक _Drive);
  _CRTIMP पूर्णांक __cdecl _getdrive(शून्य);
  _CRTIMP अचिन्हित दीर्घ __cdecl _getdrives(शून्य);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP अचिन्हित __cdecl _getdiskfree(अचिन्हित _Drive,संरचना _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetcwd(ब_अक्षर_प्रकार *_DstBuf,पूर्णांक Size_In_शब्द);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetdcwd(पूर्णांक _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक Size_In_शब्द);
  ब_अक्षर_प्रकार *__cdecl _wgetdcwd_nolock(पूर्णांक _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णांक Size_In_शब्द);
  _CRTIMP पूर्णांक __cdecl _wchdir(स्थिरांक ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णांक __cdecl _wmkdir(स्थिरांक ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णांक __cdecl _wrmdir(स्थिरांक ब_अक्षर_प्रकार *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  अक्षर *__cdecl getcwd(अक्षर *_DstBuf,पूर्णांक _SizeInBytes);
  पूर्णांक __cdecl स_बदलो(स्थिरांक अक्षर *_Path);
  पूर्णांक __cdecl सूची_गढ़ो(स्थिरांक अक्षर *_Path);
  पूर्णांक __cdecl सूची_हटाओ(स्थिरांक अक्षर *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
