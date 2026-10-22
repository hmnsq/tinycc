/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే __STRALIGN_H_S_
#నిర్వచించు __STRALIGN_H_S_

#అన్తర్భావ <stralign.h>

#ఒకవేళ defined(MINGW_HAS_SECURE_API)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#ఒకవేళ defined(__cplusplus) && defined(_WConst_Return)
  స్థిర __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,కొలత_t Destination_కొలత,PCUWSTR ఆధారం_2) {
    ఒకవేళ(WSTR_ALIGNED(ఆధారం_2) && WSTR_ALIGNED(Destination)) తిరిగి (wcscpy_s((PWSTR)Destination,Destination_కొలత,(PCWSTR)ఆధారం_2)==0 ? Destination : ఖాళీ);
    తిరిగి uaw_wcscpy((PCUWSTR)String,Character);
  }
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
