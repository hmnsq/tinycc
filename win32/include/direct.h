/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی INC_مستقیم
#تعریف_کړه INC_مستقیم

#ضمن <_mingw.h>
#ضمن <io.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _DISKFREE_T_DEFINED
#تعریف_کړه _DISKFREE_T_DEFINED
  بنية _diskfree_t {
    بینښه ټول_clusters;
    بینښه avail_clusters;
    بینښه sectors_فی_cluster;
    بینښه بایټونه_فی_sector;
  };
#د_که_پای

  _CRTIMP حرف *__cdecl _getcwd(حرف *_DstBuf,صحيح اندازه_دننه_بایټونه);
  _CRTIMP حرف *__cdecl _getdcwd(صحيح _Drive,حرف *_DstBuf,صحيح اندازه_دننه_بایټونه);
  حرف *__cdecl _getdcwd_nolock(صحيح _Drive,حرف *_DstBuf,صحيح اندازه_دننه_بایټونه);
  _CRTIMP صحيح __cdecl _chdir(ثابت حرف *لار_2);
  _CRTIMP صحيح __cdecl _mkdir(ثابت حرف *لار_2);
  _CRTIMP صحيح __cdecl _rmdir(ثابت حرف *لار_2);
  _CRTIMP صحيح __cdecl _chdrive(صحيح _Drive);
  _CRTIMP صحيح __cdecl _getdrive(فراغ);
  _CRTIMP بینښه اوږد __cdecl _getdrives(فراغ);

#که_نه_تعریف_شوی _GETDISKFREE_DEFINED
#تعریف_کړه _GETDISKFREE_DEFINED
  _CRTIMP بینښه __cdecl _getdiskfree(بینښه _Drive,بنية _diskfree_t *_DiskFree);
#د_که_پای

#که_نه_تعریف_شوی _WDIRECT_DEFINED
#تعریف_کړه _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح اندازه_دننه_ټکي);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح اندازه_دننه_ټکي);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح اندازه_دننه_ټکي);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *لار_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *لار_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *لار_2);
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES

#تعریف_کړه diskfree_t _diskfree_t

  حرف *__cdecl getcwd(حرف *_DstBuf,صحيح اندازه_دننه_بایټونه);
  صحيح __cdecl chdir(ثابت حرف *لار_2);
  صحيح __cdecl mkdir(ثابت حرف *لار_2);
  صحيح __cdecl rmdir(ثابت حرف *لار_2);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
