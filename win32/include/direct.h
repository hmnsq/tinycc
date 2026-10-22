/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_DIRECT
#define _INC_DIRECT

#અન્તર્ભાવ <_mingw.h>
#અન્તર્ભાવ <io.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef _DISKFREE_T_DEFINED
#define _DISKFREE_T_DEFINED
  સંરચના _diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
  };
#endif

  _CRTIMP અક્ષર *__cdecl _getcwd(અક્ષર *_DstBuf,પૂર્ણાંક _SizeInBytes);
  _CRTIMP અક્ષર *__cdecl _getdcwd(પૂર્ણાંક _Drive,અક્ષર *_DstBuf,પૂર્ણાંક _SizeInBytes);
  અક્ષર *__cdecl _getdcwd_nolock(પૂર્ણાંક _Drive,અક્ષર *_DstBuf,પૂર્ણાંક _SizeInBytes);
  _CRTIMP પૂર્ણાંક __cdecl _chdir(અચલ અક્ષર *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _mkdir(અચલ અક્ષર *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _rmdir(અચલ અક્ષર *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _chdrive(પૂર્ણાંક _Drive);
  _CRTIMP પૂર્ણાંક __cdecl _getdrive(શૂન્ય);
  _CRTIMP unsigned long __cdecl _getdrives(શૂન્ય);

#ifndef _GETDISKFREE_DEFINED
#define _GETDISKFREE_DEFINED
  _CRTIMP unsigned __cdecl _getdiskfree(unsigned _Drive,સંરચના _diskfree_t *_DiskFree);
#endif

#ifndef _WDIRECT_DEFINED
#define _WDIRECT_DEFINED
  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,પૂર્ણાંક Size_In_શબ્દો);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(પૂર્ણાંક _Drive,wchar_t *_DstBuf,પૂર્ણાંક Size_In_શબ્દો);
  wchar_t *__cdecl _wgetdcwd_nolock(પૂર્ણાંક _Drive,wchar_t *_DstBuf,પૂર્ણાંક Size_In_શબ્દો);
  _CRTIMP પૂર્ણાંક __cdecl _wchdir(અચલ wchar_t *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _wmkdir(અચલ wchar_t *_Path);
  _CRTIMP પૂર્ણાંક __cdecl _wrmdir(અચલ wchar_t *_Path);
#endif

#ifndef	NO_OLDNAMES

#define diskfree_t _diskfree_t

  અક્ષર *__cdecl getcwd(અક્ષર *_DstBuf,પૂર્ણાંક _SizeInBytes);
  પૂર્ણાંક __cdecl chdir(અચલ અક્ષર *_Path);
  પૂર્ણાંક __cdecl mkdir(અચલ અક્ષર *_Path);
  પૂર્ણાંક __cdecl rmdir(અચલ અક્ષર *_Path);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)
#endif
