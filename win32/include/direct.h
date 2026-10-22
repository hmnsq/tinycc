/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ INC_براہ_راست
#تعریف_کرو INC_براہ_راست

#شامل <_mingw.h>
#شامل <io.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _DISKFREE_T_DEFINED
#تعریف_کرو _DISKFREE_T_DEFINED
  ساخت _diskfree_t {
    غیرعلامتی کل_clusters;
    غیرعلامتی avail_clusters;
    غیرعلامتی sectors_فی_cluster;
    غیرعلامتی بائٹیں_فی_sector;
  };
#اگر_ختم

  _CRTIMP حرف *__cdecl _getcwd(حرف *_DstBuf,صحیح سائز_اندر_بائٹیں);
  _CRTIMP حرف *__cdecl _getdcwd(صحیح _Drive,حرف *_DstBuf,صحیح سائز_اندر_بائٹیں);
  حرف *__cdecl _getdcwd_nolock(صحیح _Drive,حرف *_DstBuf,صحیح سائز_اندر_بائٹیں);
  _CRTIMP صحیح __cdecl _chdir(ثابت حرف *راستہ_2);
  _CRTIMP صحیح __cdecl _mkdir(ثابت حرف *راستہ_2);
  _CRTIMP صحیح __cdecl _rmdir(ثابت حرف *راستہ_2);
  _CRTIMP صحیح __cdecl _chdrive(صحیح _Drive);
  _CRTIMP صحیح __cdecl _getdrive(خالی);
  _CRTIMP غیرعلامتی طویل __cdecl _getdrives(خالی);

#اگر_غیر_تعریف_شدہ _GETDISKFREE_DEFINED
#تعریف_کرو _GETDISKFREE_DEFINED
  _CRTIMP غیرعلامتی __cdecl _getdiskfree(غیرعلامتی _Drive,ساخت _diskfree_t *_DiskFree);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WDIRECT_DEFINED
#تعریف_کرو _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,صحیح سائز_اندر_الفاظ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(صحیح _Drive,wchar_t *_DstBuf,صحیح سائز_اندر_الفاظ);
  wchar_t *__cdecl _wgetdcwd_nolock(صحیح _Drive,wchar_t *_DstBuf,صحیح سائز_اندر_الفاظ);
  _CRTIMP صحیح __cdecl _wchdir(ثابت wchar_t *راستہ_2);
  _CRTIMP صحیح __cdecl _wmkdir(ثابت wchar_t *راستہ_2);
  _CRTIMP صحیح __cdecl _wrmdir(ثابت wchar_t *راستہ_2);
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES

#تعریف_کرو diskfree_t _diskfree_t

  حرف *__cdecl getcwd(حرف *_DstBuf,صحیح سائز_اندر_بائٹیں);
  صحیح __cdecl chdir(ثابت حرف *راستہ_2);
  صحیح __cdecl mkdir(ثابت حرف *راستہ_2);
  صحیح __cdecl rmdir(ثابت حرف *راستہ_2);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
