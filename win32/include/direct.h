/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف INC_سدھا
#تعریف_کرو INC_سدھا

#ضمن <_mingw.h>
#ضمن <io.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _DISKFREE_T_DEFINED
#تعریف_کرو _DISKFREE_T_DEFINED
  بنية _diskfree_t {
    بنانشانی کل_clusters;
    بنانشانی avail_clusters;
    بنانشانی sectors_فی_cluster;
    بنانشانی بائٹاں_فی_sector;
  };
#جے_انت

  _CRTIMP حرف *__cdecl _getcwd(حرف *_DstBuf,صحيح ناپ_وچ_بائٹاں);
  _CRTIMP حرف *__cdecl _getdcwd(صحيح _Drive,حرف *_DstBuf,صحيح ناپ_وچ_بائٹاں);
  حرف *__cdecl _getdcwd_nolock(صحيح _Drive,حرف *_DstBuf,صحيح ناپ_وچ_بائٹاں);
  _CRTIMP صحيح __cdecl _chdir(ثابت حرف *رستہ_2);
  _CRTIMP صحيح __cdecl _mkdir(ثابت حرف *رستہ_2);
  _CRTIMP صحيح __cdecl _rmdir(ثابت حرف *رستہ_2);
  _CRTIMP صحيح __cdecl _chdrive(صحيح _Drive);
  _CRTIMP صحيح __cdecl _getdrive(فراغ);
  _CRTIMP بنانشانی لما __cdecl _getdrives(فراغ);

#جے_بنا_تعریف _GETDISKFREE_DEFINED
#تعریف_کرو _GETDISKFREE_DEFINED
  _CRTIMP بنانشانی __cdecl _getdiskfree(بنانشانی _Drive,بنية _diskfree_t *_DiskFree);
#جے_انت

#جے_بنا_تعریف _WDIRECT_DEFINED
#تعریف_کرو _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح ناپ_وچ_الفاظ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح ناپ_وچ_الفاظ);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح ناپ_وچ_الفاظ);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *رستہ_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *رستہ_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *رستہ_2);
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES

#تعریف_کرو diskfree_t _diskfree_t

  حرف *__cdecl getcwd(حرف *_DstBuf,صحيح ناپ_وچ_بائٹاں);
  صحيح __cdecl chdir(ثابت حرف *رستہ_2);
  صحيح __cdecl mkdir(ثابت حرف *رستہ_2);
  صحيح __cdecl rmdir(ثابت حرف *رستہ_2);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)
#جے_انت
