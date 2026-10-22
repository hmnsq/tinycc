/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده INC_مستقیم
#تعریف_کن INC_مستقیم

#ضمن <_mingw.h>
#ضمن <io.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _DISKFREE_T_DEFINED
#تعریف_کن _DISKFREE_T_DEFINED
  بنية _diskfree_t {
    بیعلامت مجموع_clusters;
    بیعلامت avail_clusters;
    بیعلامت sectors_در_هر_cluster;
    بیعلامت بایتها_در_هر_sector;
  };
#پایان_اگر

  _CRTIMP حرف *__cdecl _getcwd(حرف *_DstBuf,صحيح اندازه_درون_بایتها);
  _CRTIMP حرف *__cdecl _getdcwd(صحيح _Drive,حرف *_DstBuf,صحيح اندازه_درون_بایتها);
  حرف *__cdecl _getdcwd_nolock(صحيح _Drive,حرف *_DstBuf,صحيح اندازه_درون_بایتها);
  _CRTIMP صحيح __cdecl _chdir(ثابت حرف *مسیر_2);
  _CRTIMP صحيح __cdecl _mkdir(ثابت حرف *مسیر_2);
  _CRTIMP صحيح __cdecl _rmdir(ثابت حرف *مسیر_2);
  _CRTIMP صحيح __cdecl _chdrive(صحيح _Drive);
  _CRTIMP صحيح __cdecl _getdrive(فراغ);
  _CRTIMP بیعلامت دراز __cdecl _getdrives(فراغ);

#اگر_تعریف_نشده _GETDISKFREE_DEFINED
#تعریف_کن _GETDISKFREE_DEFINED
  _CRTIMP بیعلامت __cdecl _getdiskfree(بیعلامت _Drive,بنية _diskfree_t *_DiskFree);
#پایان_اگر

#اگر_تعریف_نشده _WDIRECT_DEFINED
#تعریف_کن _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحيح اندازه_درون_واژگان);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحيح _Drive,wchar_t *_DstBuf,صحيح اندازه_درون_واژگان);
  wchar_t *__cdecl _wgetdcwd_nolock(صحيح _Drive,wchar_t *_DstBuf,صحيح اندازه_درون_واژگان);
  _CRTIMP صحيح __cdecl _wchdir(ثابت wchar_t *مسیر_2);
  _CRTIMP صحيح __cdecl _wmkdir(ثابت wchar_t *مسیر_2);
  _CRTIMP صحيح __cdecl _wrmdir(ثابت wchar_t *مسیر_2);
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES

#تعریف_کن diskfree_t _diskfree_t

  حرف *__cdecl getcwd(حرف *_DstBuf,صحيح اندازه_درون_بایتها);
  صحيح __cdecl chdir(ثابت حرف *مسیر_2);
  صحيح __cdecl mkdir(ثابت حرف *مسیر_2);
  صحيح __cdecl rmdir(ثابت حرف *مسیر_2);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
