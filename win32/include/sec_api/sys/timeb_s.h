/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#నిర్వచితం_కాకపోతే _TIMEB_H_S
#నిర్వచించు _TIMEB_H_S

#అన్తర్భావ <sys/timeb.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే USE_32_బిట్టు_సమయం_T
#నిర్వచించు _ftime_s _ftime32_s
#లేకపోతే
#నిర్వచించు _ftime_s _ftime64_s
#అయితే_ముగింపు

  _CRTIMP errno_t __cdecl _ftime32_s(నిర్మాణం __timeb32 *సమయం_2);
#ఒకవేళ INTEGRAL_MAX_బిట్లు >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(నిర్మాణం __timeb64 *సమయం_2);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
