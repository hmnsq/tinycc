/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే INC_జ్ఞాపకం
#నిర్వచించు INC_జ్ఞాపకం

#అన్తర్భావ <_mingw.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _CONST_RETURN
#నిర్వచించు _CONST_RETURN
#అయితే_ముగింపు

#నిర్వచించు _WConst_return _CONST_RETURN

#నిర్వచితం_కాకపోతే CRT_జ్ఞాపకం_DEFINED
#నిర్వచించు CRT_జ్ఞాపకం_DEFINED
  _CRTIMP శూన్య *__cdecl _memccpy(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CONST_RETURN శూన్య *__cdecl memchr(స్థిరరాశి శూన్య *_Buf ,పూర్ణాంకం _Val,కొలత_t Max_లెక్క);
  _CRTIMP పూర్ణాంకం __cdecl _memicmp(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4);
  _CRTIMP పూర్ణాంకం __cdecl _memicmp_l(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4,_locale_t _Locale);
  పూర్ణాంకం __cdecl memcmp(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4);
  శూన్య *__cdecl జ్ఞాపకం_నకలు(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,కొలత_t కొలత_4);
  శూన్య *__cdecl memset(శూన్య *_Dst,పూర్ణాంకం _Val,కొలత_t కొలత_4);

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  శూన్య *__cdecl memccpy(శూన్య *_Dst,స్థిరరాశి శూన్య *_Src,పూర్ణాంకం _Val,కొలత_t కొలత_4);
  పూర్ణాంకం __cdecl memicmp(స్థిరరాశి శూన్య *_Buf1,స్థిరరాశి శూన్య *_Buf2,కొలత_t కొలత_4);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
