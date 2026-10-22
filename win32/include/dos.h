/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_DOS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_DOS

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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ A_ਸਾਧਾਰਨ 0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_RDONLY 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_HIDDEN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_SYSTEM 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_SUBDIR 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _A_ARCH 0x20

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _GETDISKFREE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _GETDISKFREE_DEFINED
  _CRTIMP ਬਿਨਾਨਿਸ਼ਾਨੀ __cdecl _getdiskfree(ਬਿਨਾਨਿਸ਼ਾਨੀ _Drive,ਬਣਤਰ _diskfree_t *_DiskFree);
#ਜੇ_ਅੰਤ

#ਜੇ (defined(_X86_) && !defined(__x86_64))
  ਖਾਲੀ __cdecl _disable(ਖਾਲੀ);
  ਖਾਲੀ __cdecl _enable(ਖਾਲੀ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ diskfree_t _diskfree_t
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
