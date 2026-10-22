/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#pragma pack(थप,_CRT_PACKING)

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

  _CRTIMP वर्ण *__cdecl _getcwd(वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  _CRTIMP वर्ण *__cdecl _getdcwd(पूर्णाङ्क _Drive,वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  वर्ण *__cdecl _getdcwd_nolock(पूर्णाङ्क _Drive,वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  _CRTIMP पूर्णाङ्क __cdecl _chdir(अचर वर्ण *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _mkdir(अचर वर्ण *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _rmdir(अचर वर्ण *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _chdrive(पूर्णाङ्क _Drive);
  _CRTIMP पूर्णाङ्क __cdecl _getdrive(शून्य);
  _CRTIMP अचिन्हित दीर्घ __cdecl _getdrives(शून्य);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP अचिन्हित __cdecl _getdiskfree(अचिन्हित _Drive,संरचना _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetcwd(ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क Size_In_शब्दहरू);
  _CRTIMP ब_अक्षर_प्रकार *__cdecl _wgetdcwd(पूर्णाङ्क _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क Size_In_शब्दहरू);
  ब_अक्षर_प्रकार *__cdecl _wgetdcwd_nolock(पूर्णाङ्क _Drive,ब_अक्षर_प्रकार *_DstBuf,पूर्णाङ्क Size_In_शब्दहरू);
  _CRTIMP पूर्णाङ्क __cdecl _wchdir(अचर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wmkdir(अचर ब_अक्षर_प्रकार *_Path);
  _CRTIMP पूर्णाङ्क __cdecl _wrmdir(अचर ब_अक्षर_प्रकार *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  वर्ण *__cdecl getcwd(वर्ण *_DstBuf,पूर्णाङ्क _SizeInBytes);
  पूर्णाङ्क __cdecl स_बदलो(अचर वर्ण *_Path);
  पूर्णाङ्क __cdecl सूची_गढ़ो(अचर वर्ण *_Path);
  पूर्णाङ्क __cdecl सूची_हटाओ(अचर वर्ण *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(झिक)
#endif
