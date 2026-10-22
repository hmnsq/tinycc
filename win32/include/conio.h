/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_CONIO
#परिभाषय _INC_CONIO

#अन्तर्भाव <_mingw.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  _CRTIMP वर्ण *_cgets(वर्ण *बफर_2);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cputs(ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _getch(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getche(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf(ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_p(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_p(ध्रुव वर्ण *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _kbhit(शून्य);

#यदि defined(_X86_) && !defined(__x86_64)
  पूर्णाङ्क __cdecl _inp(अचिह्नित ह्रस्व);
  अचिह्नित ह्रस्व __cdecl _inpw(अचिह्नित ह्रस्व);
  अचिह्नित दीर्घ __cdecl _inpd(अचिह्नित ह्रस्व);
  पूर्णाङ्क __cdecl _outp(अचिह्नित ह्रस्व,पूर्णाङ्क);
  अचिह्नित ह्रस्व __cdecl _outpw(अचिह्नित ह्रस्व,अचिह्नित ह्रस्व);
  अचिह्नित दीर्घ __cdecl _outpd(अचिह्नित ह्रस्व,अचिह्नित दीर्घ);
#यदि_अन्तः

  _CRTIMP पूर्णाङ्क __cdecl _putch(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _ungetch(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _getch_nolock(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getche_nolock(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _putch_nolock(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _ungetch_nolock(पूर्णाङ्क _Ch);

#यदि_अपरिभाषितम् _WCONIO_DEFINED
#परिभाषय _WCONIO_DEFINED

#यदि_अपरिभाषितम् WEOF
#परिभाषय WEOF (wint_t)(0xFFFF)
#यदि_अन्तः

  _CRTIMP wchar_t *_cgetws(wchar_t *बफर_2);
  _CRTIMP wint_t __cdecl _getwch(शून्य);
  _CRTIMP wint_t __cdecl _getwche(शून्य);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _cputws(ध्रुव wchar_t *_String);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p(ध्रुव wchar_t *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p(ध्रुव wchar_t *_Format,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p_l(ध्रुव wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(शून्य);
  _CRTIMP wint_t __cdecl _getwche_nolock(शून्य);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
  वर्ण *__cdecl cgets(वर्ण *बफर_2);
  पूर्णाङ्क __cdecl cprintf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl cputs(ध्रुव वर्ण *_Str);
  पूर्णाङ्क __cdecl cscanf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl getch(शून्य);
  पूर्णाङ्क __cdecl getche(शून्य);
  पूर्णाङ्क __cdecl kbhit(शून्य);
  पूर्णाङ्क __cdecl putch(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl ungetch(पूर्णाङ्क _Ch);

#यदि (defined(_X86_) && !defined(__x86_64))
  पूर्णाङ्क __cdecl inp(अचिह्नित ह्रस्व);
  अचिह्नित ह्रस्व __cdecl inpw(अचिह्नित ह्रस्व);
  पूर्णाङ्क __cdecl outp(अचिह्नित ह्रस्व,पूर्णाङ्क);
  अचिह्नित ह्रस्व __cdecl outpw(अचिह्नित ह्रस्व,अचिह्नित ह्रस्व);
#यदि_अन्तः

  /* I/O intrin functions.  */
  __CRT_INLINE अचिह्नित वर्ण __inbyte(अचिह्नित ह्रस्व पत्तनम्)
  {
      अचिह्नित वर्ण मानम्;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (मानम्)
          : "Nd" (पत्तनम्));
      प्रत्यागम मानम्;
  }
  __CRT_INLINE अचिह्नित ह्रस्व __inword(अचिह्नित ह्रस्व पत्तनम्)
  {
      अचिह्नित ह्रस्व मानम्;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (मानम्)
          : "Nd" (पत्तनम्));
      प्रत्यागम मानम्;
  }
  __CRT_INLINE अचिह्नित दीर्घ __indword(अचिह्नित ह्रस्व पत्तनम्)
  {
      अचिह्नित दीर्घ मानम्;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (मानम्)
          : "Nd" (पत्तनम्));
      प्रत्यागम मानम्;
  }
  __CRT_INLINE शून्य __outbyte(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित वर्ण दत्त_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (दत्त_3), "Nd" (पत्तनम्));
  }
  __CRT_INLINE शून्य __outword(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित ह्रस्व दत्त_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (दत्त_3), "Nd" (पत्तनम्));
  }
  __CRT_INLINE शून्य __outdword(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित दीर्घ दत्त_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (दत्त_3), "Nd" (पत्तनम्));
  }
  __CRT_INLINE शून्य __inbytestring(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित वर्ण *बफर_3,अचिह्नित दीर्घ गणनम्_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (बफर_3), "=c" (गणनम्_3)
		: "d"(पत्तनम्), "0"(बफर_3), "1" (गणनम्_3)
		);
  }
  __CRT_INLINE शून्य __inwordstring(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित ह्रस्व *बफर_3,अचिह्नित दीर्घ गणनम्_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (बफर_3), "=c" (गणनम्_3)
		: "d"(पत्तनम्), "0"(बफर_3), "1" (गणनम्_3)
		);
  }
  __CRT_INLINE शून्य __indwordstring(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित दीर्घ *बफर_3,अचिह्नित दीर्घ गणनम्_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (बफर_3), "=c" (गणनम्_3)
		: "d"(पत्तनम्), "0"(बफर_3), "1" (गणनम्_3)
		);
  }

  __CRT_INLINE शून्य __outbytestring(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित वर्ण *बफर_3,अचिह्नित दीर्घ गणनम्_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (बफर_3), "=c" (गणनम्_3)
          : "d"(पत्तनम्), "0"(बफर_3), "1" (गणनम्_3)
          );
  }
  __CRT_INLINE शून्य __outwordstring(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित ह्रस्व *बफर_3,अचिह्नित दीर्घ गणनम्_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (बफर_3), "=c" (गणनम्_3)
          : "d"(पत्तनम्), "0"(बफर_3), "1" (गणनम्_3)
          );
  }
  __CRT_INLINE शून्य __outdwordstring(अचिह्नित ह्रस्व पत्तनम्,अचिह्नित दीर्घ *बफर_3,अचिह्नित दीर्घ गणनम्_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (बफर_3), "=c" (गणनम्_3)
          : "d"(पत्तनम्), "0"(बफर_3), "1" (गणनम्_3)
          );
  }

  __CRT_INLINE अचिह्नित __int64 __readcr0(शून्य)
  {
      अचिह्नित __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#यदि_परिभाषितम् _WIN64
  __CRT_INLINE शून्य __writecr0(अचिह्नित __int64 दत्त_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
  }
 
  __CRT_INLINE अचिह्नित __int64 __readcr2(शून्य)
  {
      अचिह्नित __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr2(अचिह्नित __int64 दत्त_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
 }
 
  __CRT_INLINE अचिह्नित __int64 __readcr3(शून्य)
  {
      अचिह्नित __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr3(अचिह्नित __int64 दत्त_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
 }
 
  __CRT_INLINE अचिह्नित __int64 __readcr4(शून्य)
  {
      अचिह्नित __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr4(अचिह्नित __int64 दत्त_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [दत्त_3] "q" (दत्त_3)
         : "memory");
 }
 
  __CRT_INLINE अचिह्नित __int64 __readcr8(शून्य)
  {
      अचिह्नित __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr8(अचिह्नित __int64 दत्त_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
 }
 
#नोचेद्यदि defined(_WIN32)

  __CRT_INLINE शून्य __writecr0(अचिह्नित दत्त_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
  }
 
  __CRT_INLINE अचिह्नित दीर्घ __readcr2(शून्य)
  {
      अचिह्नित दीर्घ मानम्;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr2(अचिह्नित दत्त_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
 }
 
  __CRT_INLINE अचिह्नित दीर्घ __readcr3(शून्य)
  {
      अचिह्नित दीर्घ मानम्;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr3(अचिह्नित दत्त_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
 }
 
  __CRT_INLINE अचिह्नित दीर्घ __readcr4(शून्य)
  {
      अचिह्नित दीर्घ मानम्;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मानम्] "=q" (मानम्));
      प्रत्यागम मानम्;
  }

 __CRT_INLINE शून्य __writecr4(अचिह्नित दत्त_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [दत्त_3] "q" (दत्त_3)
         : "memory");
 }
 
 __CRT_INLINE अचिह्नित दीर्घ __readcr8(शून्य)
 {
   अचिह्नित दीर्घ मानम्;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मानम्] "=q" (मानम्));
     प्रत्यागम मानम्;
 }

 __CRT_INLINE शून्य __writecr8(अचिह्नित दत्त_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [दत्त_3] "q" (दत्त_3)
       : "memory");
 }
 
#यदि_अन्तः

  __CRT_INLINE अचिह्नित __int64 __readmsr(अचिह्नित दीर्घ msr)
  {
      अचिह्नित __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      प्रत्यागम val1 | (val2 << 32);
  }

 __CRT_INLINE शून्य __writemsr (अचिह्नित दीर्घ msr, अचिह्नित __int64 मानम्_3)
 {
    अचिह्नित दीर्घ val1 = मानम्_3, val2 = मानम्_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE अचिह्नित __int64 __rdtsc(शून्य)
  {
      अचिह्नित __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      प्रत्यागम val1 | (val2 << 32);
  }

  __CRT_INLINE शून्य __cpuid(पूर्णाङ्क CPUInfo[4], पूर्णाङ्क InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#अन्तर्भाव <sec_api/conio_s.h>

#यदि_अन्तः
