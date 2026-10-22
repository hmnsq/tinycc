/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే INC_ప్రత్యక్ష
#నిర్వచించు INC_ప్రత్యక్ష

#అన్తర్భావ <_mingw.h>
#అన్తర్భావ <io.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _DISKFREE_T_DEFINED
#నిర్వచించు _DISKFREE_T_DEFINED
  నిర్మాణం _diskfree_t {
    గుర్తులేని మొత్తం_clusters;
    గుర్తులేని avail_clusters;
    గుర్తులేని sectors_చొప్పున_cluster;
    గుర్తులేని బైట్లు_చొప్పున_sector;
  };
#అయితే_ముగింపు

  _CRTIMP అక్షరం *__cdecl _getcwd(అక్షరం *_DstBuf,పూర్ణాంకం కొలత_లోపల_బైట్లు);
  _CRTIMP అక్షరం *__cdecl _getdcwd(పూర్ణాంకం _Drive,అక్షరం *_DstBuf,పూర్ణాంకం కొలత_లోపల_బైట్లు);
  అక్షరం *__cdecl _getdcwd_nolock(పూర్ణాంకం _Drive,అక్షరం *_DstBuf,పూర్ణాంకం కొలత_లోపల_బైట్లు);
  _CRTIMP పూర్ణాంకం __cdecl _chdir(స్థిరరాశి అక్షరం *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _mkdir(స్థిరరాశి అక్షరం *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _rmdir(స్థిరరాశి అక్షరం *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _chdrive(పూర్ణాంకం _Drive);
  _CRTIMP పూర్ణాంకం __cdecl _getdrive(శూన్య);
  _CRTIMP గుర్తులేని దీర్ఘ __cdecl _getdrives(శూన్య);

#నిర్వచితం_కాకపోతే _GETDISKFREE_DEFINED
#నిర్వచించు _GETDISKFREE_DEFINED
  _CRTIMP గుర్తులేని __cdecl _getdiskfree(గుర్తులేని _Drive,నిర్మాణం _diskfree_t *_DiskFree);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WDIRECT_DEFINED
#నిర్వచించు _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,పూర్ణాంకం కొలత_లోపల_పదాలు);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(పూర్ణాంకం _Drive,wchar_t *_DstBuf,పూర్ణాంకం కొలత_లోపల_పదాలు);
  wchar_t *__cdecl _wgetdcwd_nolock(పూర్ణాంకం _Drive,wchar_t *_DstBuf,పూర్ణాంకం కొలత_లోపల_పదాలు);
  _CRTIMP పూర్ణాంకం __cdecl _wchdir(స్థిరరాశి wchar_t *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _wmkdir(స్థిరరాశి wchar_t *మార్గం_2);
  _CRTIMP పూర్ణాంకం __cdecl _wrmdir(స్థిరరాశి wchar_t *మార్గం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES

#నిర్వచించు diskfree_t _diskfree_t

  అక్షరం *__cdecl getcwd(అక్షరం *_DstBuf,పూర్ణాంకం కొలత_లోపల_బైట్లు);
  పూర్ణాంకం __cdecl chdir(స్థిరరాశి అక్షరం *మార్గం_2);
  పూర్ణాంకం __cdecl mkdir(స్థిరరాశి అక్షరం *మార్గం_2);
  పూర్ణాంకం __cdecl rmdir(స్థిరరాశి అక్షరం *మార్గం_2);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
