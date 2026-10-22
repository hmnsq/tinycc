/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_DOS
#నిర్వచించు _INC_DOS

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

#నిర్వచించు A_సాధారణ 0x00
#నిర్వచించు _A_RDONLY 0x01
#నిర్వచించు _A_HIDDEN 0x02
#నిర్వచించు _A_SYSTEM 0x04
#నిర్వచించు _A_SUBDIR 0x10
#నిర్వచించు _A_ARCH 0x20

#నిర్వచితం_కాకపోతే _GETDISKFREE_DEFINED
#నిర్వచించు _GETDISKFREE_DEFINED
  _CRTIMP గుర్తులేని __cdecl _getdiskfree(గుర్తులేని _Drive,నిర్మాణం _diskfree_t *_DiskFree);
#అయితే_ముగింపు

#ఒకవేళ (defined(_X86_) && !defined(__x86_64))
  శూన్య __cdecl _disable(శూన్య);
  శూన్య __cdecl _enable(శూన్య);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచించు diskfree_t _diskfree_t
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
