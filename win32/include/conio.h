/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_CONIO
#నిర్వచించు _INC_CONIO

#అన్తర్భావ <_mingw.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  _CRTIMP అక్షరం *_cgets(అక్షరం *బఫరు_2);
  _CRTIMP పూర్ణాంకం __cdecl _cprintf(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cputs(స్థిరరాశి అక్షరం *_Str);
  _CRTIMP పూర్ణాంకం __cdecl _cscanf(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cscanf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _getch(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _getche(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _vcprintf(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cprintf_p(స్థిరరాశి అక్షరం *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcprintf_p(స్థిరరాశి అక్షరం *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cprintf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcprintf_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cprintf_p_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcprintf_p_l(స్థిరరాశి అక్షరం *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _kbhit(శూన్య);

#ఒకవేళ defined(_X86_) && !defined(__x86_64)
  పూర్ణాంకం __cdecl _inp(గుర్తులేని పొట్టి);
  గుర్తులేని పొట్టి __cdecl _inpw(గుర్తులేని పొట్టి);
  గుర్తులేని దీర్ఘ __cdecl _inpd(గుర్తులేని పొట్టి);
  పూర్ణాంకం __cdecl _outp(గుర్తులేని పొట్టి,పూర్ణాంకం);
  గుర్తులేని పొట్టి __cdecl _outpw(గుర్తులేని పొట్టి,గుర్తులేని పొట్టి);
  గుర్తులేని దీర్ఘ __cdecl _outpd(గుర్తులేని పొట్టి,గుర్తులేని దీర్ఘ);
#అయితే_ముగింపు

  _CRTIMP పూర్ణాంకం __cdecl _putch(పూర్ణాంకం _Ch);
  _CRTIMP పూర్ణాంకం __cdecl _ungetch(పూర్ణాంకం _Ch);
  _CRTIMP పూర్ణాంకం __cdecl _getch_nolock(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _getche_nolock(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _putch_nolock(పూర్ణాంకం _Ch);
  _CRTIMP పూర్ణాంకం __cdecl _ungetch_nolock(పూర్ణాంకం _Ch);

#నిర్వచితం_కాకపోతే _WCONIO_DEFINED
#నిర్వచించు _WCONIO_DEFINED

#నిర్వచితం_కాకపోతే WEOF
#నిర్వచించు WEOF (wint_t)(0xFFFF)
#అయితే_ముగింపు

  _CRTIMP wchar_t *_cgetws(wchar_t *బఫరు_2);
  _CRTIMP wint_t __cdecl _getwch(శూన్య);
  _CRTIMP wint_t __cdecl _getwche(శూన్య);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP పూర్ణాంకం __cdecl _cputws(స్థిరరాశి wchar_t *_String);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _cwscanf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_p(స్థిరరాశి wchar_t *_Format,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_p(స్థిరరాశి wchar_t *_Format,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP పూర్ణాంకం __cdecl _cwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP పూర్ణాంకం __cdecl _vcwprintf_p_l(స్థిరరాశి wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(శూన్య);
  _CRTIMP wint_t __cdecl _getwche_nolock(శూన్య);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
  అక్షరం *__cdecl cgets(అక్షరం *బఫరు_2);
  పూర్ణాంకం __cdecl cprintf(స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl cputs(స్థిరరాశి అక్షరం *_Str);
  పూర్ణాంకం __cdecl cscanf(స్థిరరాశి అక్షరం *_Format,...);
  పూర్ణాంకం __cdecl getch(శూన్య);
  పూర్ణాంకం __cdecl getche(శూన్య);
  పూర్ణాంకం __cdecl kbhit(శూన్య);
  పూర్ణాంకం __cdecl putch(పూర్ణాంకం _Ch);
  పూర్ణాంకం __cdecl ungetch(పూర్ణాంకం _Ch);

#ఒకవేళ (defined(_X86_) && !defined(__x86_64))
  పూర్ణాంకం __cdecl inp(గుర్తులేని పొట్టి);
  గుర్తులేని పొట్టి __cdecl inpw(గుర్తులేని పొట్టి);
  పూర్ణాంకం __cdecl outp(గుర్తులేని పొట్టి,పూర్ణాంకం);
  గుర్తులేని పొట్టి __cdecl outpw(గుర్తులేని పొట్టి,గుర్తులేని పొట్టి);
#అయితే_ముగింపు

  /* I/O intrin functions.  */
  __CRT_INLINE గుర్తులేని అక్షరం __inbyte(గుర్తులేని పొట్టి పోర్టు)
  {
      గుర్తులేని అక్షరం విలువ;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (విలువ)
          : "Nd" (పోర్టు));
      తిరిగి విలువ;
  }
  __CRT_INLINE గుర్తులేని పొట్టి __inword(గుర్తులేని పొట్టి పోర్టు)
  {
      గుర్తులేని పొట్టి విలువ;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (విలువ)
          : "Nd" (పోర్టు));
      తిరిగి విలువ;
  }
  __CRT_INLINE గుర్తులేని దీర్ఘ __indword(గుర్తులేని పొట్టి పోర్టు)
  {
      గుర్తులేని దీర్ఘ విలువ;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (విలువ)
          : "Nd" (పోర్టు));
      తిరిగి విలువ;
  }
  __CRT_INLINE శూన్య __outbyte(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని అక్షరం దత్తాంశం_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (దత్తాంశం_3), "Nd" (పోర్టు));
  }
  __CRT_INLINE శూన్య __outword(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని పొట్టి దత్తాంశం_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (దత్తాంశం_3), "Nd" (పోర్టు));
  }
  __CRT_INLINE శూన్య __outdword(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని దీర్ఘ దత్తాంశం_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (దత్తాంశం_3), "Nd" (పోర్టు));
  }
  __CRT_INLINE శూన్య __inbytestring(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని అక్షరం *బఫరు_3,గుర్తులేని దీర్ఘ లెక్క_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (బఫరు_3), "=c" (లెక్క_3)
		: "d"(పోర్టు), "0"(బఫరు_3), "1" (లెక్క_3)
		);
  }
  __CRT_INLINE శూన్య __inwordstring(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని పొట్టి *బఫరు_3,గుర్తులేని దీర్ఘ లెక్క_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (బఫరు_3), "=c" (లెక్క_3)
		: "d"(పోర్టు), "0"(బఫరు_3), "1" (లెక్క_3)
		);
  }
  __CRT_INLINE శూన్య __indwordstring(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని దీర్ఘ *బఫరు_3,గుర్తులేని దీర్ఘ లెక్క_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (బఫరు_3), "=c" (లెక్క_3)
		: "d"(పోర్టు), "0"(బఫరు_3), "1" (లెక్క_3)
		);
  }

  __CRT_INLINE శూన్య __outbytestring(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని అక్షరం *బఫరు_3,గుర్తులేని దీర్ఘ లెక్క_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (బఫరు_3), "=c" (లెక్క_3)
          : "d"(పోర్టు), "0"(బఫరు_3), "1" (లెక్క_3)
          );
  }
  __CRT_INLINE శూన్య __outwordstring(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని పొట్టి *బఫరు_3,గుర్తులేని దీర్ఘ లెక్క_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (బఫరు_3), "=c" (లెక్క_3)
          : "d"(పోర్టు), "0"(బఫరు_3), "1" (లెక్క_3)
          );
  }
  __CRT_INLINE శూన్య __outdwordstring(గుర్తులేని పొట్టి పోర్టు,గుర్తులేని దీర్ఘ *బఫరు_3,గుర్తులేని దీర్ఘ లెక్క_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (బఫరు_3), "=c" (లెక్క_3)
          : "d"(పోర్టు), "0"(బఫరు_3), "1" (లెక్క_3)
          );
  }

  __CRT_INLINE గుర్తులేని __int64 __readcr0(శూన్య)
  {
      గుర్తులేని __int64 విలువ;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#నిర్వచితమైతే _WIN64
  __CRT_INLINE శూన్య __writecr0(గుర్తులేని __int64 దత్తాంశం_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
  }
 
  __CRT_INLINE గుర్తులేని __int64 __readcr2(శూన్య)
  {
      గుర్తులేని __int64 విలువ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr2(గుర్తులేని __int64 దత్తాంశం_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
 }
 
  __CRT_INLINE గుర్తులేని __int64 __readcr3(శూన్య)
  {
      గుర్తులేని __int64 విలువ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr3(గుర్తులేని __int64 దత్తాంశం_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
 }
 
  __CRT_INLINE గుర్తులేని __int64 __readcr4(శూన్య)
  {
      గుర్తులేని __int64 విలువ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr4(గుర్తులేని __int64 దత్తాంశం_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [దత్తాంశం_3] "q" (దత్తాంశం_3)
         : "memory");
 }
 
  __CRT_INLINE గుర్తులేని __int64 __readcr8(శూన్య)
  {
      గుర్తులేని __int64 విలువ;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr8(గుర్తులేని __int64 దత్తాంశం_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
 }
 
#లేదావేళ defined(_WIN32)

  __CRT_INLINE శూన్య __writecr0(గుర్తులేని దత్తాంశం_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
  }
 
  __CRT_INLINE గుర్తులేని దీర్ఘ __readcr2(శూన్య)
  {
      గుర్తులేని దీర్ఘ విలువ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr2(గుర్తులేని దత్తాంశం_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
 }
 
  __CRT_INLINE గుర్తులేని దీర్ఘ __readcr3(శూన్య)
  {
      గుర్తులేని దీర్ఘ విలువ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr3(గుర్తులేని దత్తాంశం_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
 }
 
  __CRT_INLINE గుర్తులేని దీర్ఘ __readcr4(శూన్య)
  {
      గుర్తులేని దీర్ఘ విలువ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [విలువ] "=q" (విలువ));
      తిరిగి విలువ;
  }

 __CRT_INLINE శూన్య __writecr4(గుర్తులేని దత్తాంశం_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [దత్తాంశం_3] "q" (దత్తాంశం_3)
         : "memory");
 }
 
 __CRT_INLINE గుర్తులేని దీర్ఘ __readcr8(శూన్య)
 {
   గుర్తులేని దీర్ఘ విలువ;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [విలువ] "=q" (విలువ));
     తిరిగి విలువ;
 }

 __CRT_INLINE శూన్య __writecr8(గుర్తులేని దత్తాంశం_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [దత్తాంశం_3] "q" (దత్తాంశం_3)
       : "memory");
 }
 
#అయితే_ముగింపు

  __CRT_INLINE గుర్తులేని __int64 __readmsr(గుర్తులేని దీర్ఘ msr)
  {
      గుర్తులేని __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      తిరిగి val1 | (val2 << 32);
  }

 __CRT_INLINE శూన్య __writemsr (గుర్తులేని దీర్ఘ msr, గుర్తులేని __int64 విలువ_3)
 {
    గుర్తులేని దీర్ఘ val1 = విలువ_3, val2 = విలువ_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE గుర్తులేని __int64 __rdtsc(శూన్య)
  {
      గుర్తులేని __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      తిరిగి val1 | (val2 << 32);
  }

  __CRT_INLINE శూన్య __cpuid(పూర్ణాంకం CPUInfo[4], పూర్ణాంకం InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అన్తర్భావ <sec_api/conio_s.h>

#అయితే_ముగింపు
