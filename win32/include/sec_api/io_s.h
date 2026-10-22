/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_IO_S
#నిర్వచించు _INC_IO_S

#అన్తర్భావ <io.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _access_s(స్థిరరాశి అక్షరం *_Filename,పూర్ణాంకం Access_బహుళకం);
  _CRTIMP errno_t __cdecl _chsize_s(పూర్ణాంకం _FileHandle,__int64 కొలత_4);
  _CRTIMP errno_t __cdecl _mktemp_s(అక్షరం *_TemplateName,కొలత_t కొలత_4);
  _CRTIMP errno_t __cdecl _umask_s(పూర్ణాంకం New_బహుళకం,పూర్ణాంకం *Old_బహుళకం);

#నిర్వచితం_కాకపోతే _WIO_S_DEFINED
#నిర్వచించు _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(స్థిరరాశి wchar_t *_Filename,పూర్ణాంకం Access_బహుళకం);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,కొలత_t కొలత_లోపల_పదాలు);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
#అయితే_ముగింపు
