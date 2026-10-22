/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ INC_ਸਿੱਧਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INC_ਸਿੱਧਾ

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <io.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _DISKFREE_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DISKFREE_T_DEFINED
  ਬਣਤਰ _diskfree_t {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਕੁੱਲ_clusters;
    ਬਿਨਾਨਿਸ਼ਾਨੀ avail_clusters;
    ਬਿਨਾਨਿਸ਼ਾਨੀ sectors_ਪ੍ਰਤੀ_cluster;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਬਾਈਟਾਂ_ਪ੍ਰਤੀ_sector;
  };
#ਜੇ_ਅੰਤ

  _CRTIMP ਅੱਖਰ *__cdecl _getcwd(ਅੱਖਰ *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP ਅੱਖਰ *__cdecl _getdcwd(ਪੂਰਨ _Drive,ਅੱਖਰ *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  ਅੱਖਰ *__cdecl _getdcwd_nolock(ਪੂਰਨ _Drive,ਅੱਖਰ *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  _CRTIMP ਪੂਰਨ __cdecl _chdir(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _mkdir(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _rmdir(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _chdrive(ਪੂਰਨ _Drive);
  _CRTIMP ਪੂਰਨ __cdecl _getdrive(ਖਾਲੀ);
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _getdrives(ਖਾਲੀ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _GETDISKFREE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _GETDISKFREE_DEFINED
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __cdecl _getdiskfree(ਬਿਨਾਨਿਸ਼ਾਨੀ _Drive,ਬਣਤਰ _diskfree_t *_DiskFree);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WDIRECT_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(ਪੂਰਨ _Drive,wchar_t *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  wchar_t *__cdecl _wgetdcwd_nolock(ਪੂਰਨ _Drive,wchar_t *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਸ਼ਬਦ);
  _CRTIMP ਪੂਰਨ __cdecl _wchdir(ਅਚਲ wchar_t *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _wmkdir(ਅਚਲ wchar_t *ਰਸਤਾ_2);
  _CRTIMP ਪੂਰਨ __cdecl _wrmdir(ਅਚਲ wchar_t *ਰਸਤਾ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ diskfree_t _diskfree_t

  ਅੱਖਰ *__cdecl getcwd(ਅੱਖਰ *_DstBuf,ਪੂਰਨ ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  ਪੂਰਨ __cdecl chdir(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2);
  ਪੂਰਨ __cdecl mkdir(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2);
  ਪੂਰਨ __cdecl rmdir(ਅਚਲ ਅੱਖਰ *ਰਸਤਾ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
