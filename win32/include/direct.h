/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् INC_प्रत्यक्षम्
#परिभाषय INC_प्रत्यक्षम्

#अन्तर्भाव <_mingw.h>
#अन्तर्भाव <io.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _DISKFREE_T_DEFINED
#परिभाषय _DISKFREE_T_DEFINED
  संरचना _diskfree_t {
    अचिह्नित योग_clusters;
    अचिह्नित avail_clusters;
    अचिह्नित sectors_प्रत्येकम्_cluster;
    अचिह्नित अष्टकानि_प्रत्येकम्_sector;
  };
#यदि_अन्तः

  _CRTIMP वर्ण *__cdecl _getcwd(वर्ण *_DstBuf,पूर्णाङ्क आकार_अन्तर्_अष्टकानि);
  _CRTIMP वर्ण *__cdecl _getdcwd(पूर्णाङ्क _Drive,वर्ण *_DstBuf,पूर्णाङ्क आकार_अन्तर्_अष्टकानि);
  वर्ण *__cdecl _getdcwd_nolock(पूर्णाङ्क _Drive,वर्ण *_DstBuf,पूर्णाङ्क आकार_अन्तर्_अष्टकानि);
  _CRTIMP पूर्णाङ्क __cdecl _chdir(ध्रुव वर्ण *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _mkdir(ध्रुव वर्ण *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _rmdir(ध्रुव वर्ण *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _chdrive(पूर्णाङ्क _Drive);
  _CRTIMP पूर्णाङ्क __cdecl _getdrive(शून्य);
  _CRTIMP अचिह्नित दीर्घ __cdecl _getdrives(शून्य);

#यदि_अपरिभाषितम् _GETDISKFREE_DEFINED
#परिभाषय _GETDISKFREE_DEFINED
  _CRTIMP अचिह्नित __cdecl _getdiskfree(अचिह्नित _Drive,संरचना _diskfree_t *_DiskFree);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WDIRECT_DEFINED
#परिभाषय _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,पूर्णाङ्क आकार_अन्तर्_शब्दाः);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क आकार_अन्तर्_शब्दाः);
  wchar_t *__cdecl _wgetdcwd_nolock(पूर्णाङ्क _Drive,wchar_t *_DstBuf,पूर्णाङ्क आकार_अन्तर्_शब्दाः);
  _CRTIMP पूर्णाङ्क __cdecl _wchdir(ध्रुव wchar_t *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _wmkdir(ध्रुव wchar_t *मार्गः_2);
  _CRTIMP पूर्णाङ्क __cdecl _wrmdir(ध्रुव wchar_t *मार्गः_2);
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES

#परिभाषय diskfree_t _diskfree_t

  वर्ण *__cdecl getcwd(वर्ण *_DstBuf,पूर्णाङ्क आकार_अन्तर्_अष्टकानि);
  पूर्णाङ्क __cdecl chdir(ध्रुव वर्ण *मार्गः_2);
  पूर्णाङ्क __cdecl mkdir(ध्रुव वर्ण *मार्गः_2);
  पूर्णाङ्क __cdecl rmdir(ध्रुव वर्ण *मार्गः_2);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
