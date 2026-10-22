/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل INC_سڌو
#وصف_ڪريو INC_سڌو

#ضمن <_mingw.h>
#ضمن <io.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _DISKFREE_T_DEFINED
#وصف_ڪريو _DISKFREE_T_DEFINED
  بنية _diskfree_t {
    بنانشان ڪل_clusters;
    بنانشان avail_clusters;
    بنانشان sectors_في_cluster;
    بنانشان بائيٽون_في_sector;
  };
#جيڪڏهن_پورو

  _CRTIMP حرف *__cdecl _getcwd(حرف *_DstBuf,صحيح سائيز_اندريون_بائيٽون);
  _CRTIMP حرف *__cdecl _getdcwd(صحيح _Drive,حرف *_DstBuf,صحيح سائيز_اندريون_بائيٽون);
  حرف *__cdecl _getdcwd_nolock(صحيح _Drive,حرف *_DstBuf,صحيح سائيز_اندريون_بائيٽون);
  _CRTIMP صحيح __cdecl _chdir(ثابت حرف *رستو_2);
  _CRTIMP صحيح __cdecl _mkdir(ثابت حرف *رستو_2);
  _CRTIMP صحيح __cdecl _rmdir(ثابت حرف *رستو_2);
  _CRTIMP صحيح __cdecl _chdrive(صحيح _Drive);
  _CRTIMP صحيح __cdecl _getdrive(فراغ);
  _CRTIMP بنانشان ڊگهو __cdecl _getdrives(فراغ);

#جيڪڏهن_وصف_نه_ٿيل _GETDISKFREE_DEFINED
#وصف_ڪريو _GETDISKFREE_DEFINED
  _CRTIMP بنانشان __cdecl _getdiskfree(بنانشان _Drive,بنية _diskfree_t *_DiskFree);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WDIRECT_DEFINED
#وصف_ڪريو _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح سائيز_اندريون_لفظ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح سائيز_اندريون_لفظ);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح سائيز_اندريون_لفظ);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *رستو_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *رستو_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *رستو_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES

#وصف_ڪريو diskfree_t _diskfree_t

  حرف *__cdecl getcwd(حرف *_DstBuf,صحيح سائيز_اندريون_بائيٽون);
  صحيح __cdecl chdir(ثابت حرف *رستو_2);
  صحيح __cdecl mkdir(ثابت حرف *رستو_2);
  صحيح __cdecl rmdir(ثابت حرف *رستو_2);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
