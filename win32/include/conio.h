/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#अन्तर्भाव <_mingw.h>

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP वर्ण *_cgets(वर्ण *_Buffer);
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

#सचे defined(_X86_) && !defined(__x86_64)
  पूर्णाङ्क __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  पूर्णाङ्क __cdecl _outp(unsigned short,पूर्णाङ्क);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP पूर्णाङ्क __cdecl _putch(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _ungetch(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _getch_nolock(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getche_nolock(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _putch_nolock(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _ungetch_nolock(पूर्णाङ्क _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
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
#endif

#ifndef	NO_OLDNAMES
  वर्ण *__cdecl cgets(वर्ण *_Buffer);
  पूर्णाङ्क __cdecl cprintf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl cputs(ध्रुव वर्ण *_Str);
  पूर्णाङ्क __cdecl cscanf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl getch(शून्य);
  पूर्णाङ्क __cdecl getche(शून्य);
  पूर्णाङ्क __cdecl kbhit(शून्य);
  पूर्णाङ्क __cdecl putch(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl ungetch(पूर्णाङ्क _Ch);

#सचे (defined(_X86_) && !defined(__x86_64))
  पूर्णाङ्क __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  पूर्णाङ्क __cdecl outp(unsigned short,पूर्णाङ्क);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned वर्ण __inbyte(unsigned short Port)
  {
      unsigned वर्ण मानम्;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (मानम्)
          : "Nd" (Port));
      पटिनिवत्त मानम्;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short मानम्;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (मानम्)
          : "Nd" (Port));
      पटिनिवत्त मानम्;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long मानम्;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (मानम्)
          : "Nd" (Port));
      पटिनिवत्त मानम्;
  }
  __CRT_INLINE शून्य __outbyte(unsigned short Port,unsigned वर्ण Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE शून्य __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE शून्य __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE शून्य __inbytestring(unsigned short Port,unsigned वर्ण *Buffer,unsigned long गणनम्_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (गणनम्_3)
		: "d"(Port), "0"(Buffer), "1" (गणनम्_3)
		);
  }
  __CRT_INLINE शून्य __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long गणनम्_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (गणनम्_3)
		: "d"(Port), "0"(Buffer), "1" (गणनम्_3)
		);
  }
  __CRT_INLINE शून्य __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long गणनम्_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (गणनम्_3)
		: "d"(Port), "0"(Buffer), "1" (गणनम्_3)
		);
  }

  __CRT_INLINE शून्य __outbytestring(unsigned short Port,unsigned वर्ण *Buffer,unsigned long गणनम्_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (गणनम्_3)
          : "d"(Port), "0"(Buffer), "1" (गणनम्_3)
          );
  }
  __CRT_INLINE शून्य __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long गणनम्_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (गणनम्_3)
          : "d"(Port), "0"(Buffer), "1" (गणनम्_3)
          );
  }
  __CRT_INLINE शून्य __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long गणनम्_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (गणनम्_3)
          : "d"(Port), "0"(Buffer), "1" (गणनम्_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(शून्य)
  {
      unsigned __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE शून्य __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(शून्य)
  {
      unsigned __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(शून्य)
  {
      unsigned __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(शून्य)
  {
      unsigned __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(शून्य)
  {
      unsigned __int64 मानम्;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#नोचेद्यदि defined(_WIN32)

  __CRT_INLINE शून्य __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(शून्य)
  {
      unsigned long मानम्;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(शून्य)
  {
      unsigned long मानम्;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(शून्य)
  {
      unsigned long मानम्;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मानम्] "=q" (मानम्));
      पटिनिवत्त मानम्;
  }

 __CRT_INLINE शून्य __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(शून्य)
 {
   unsigned long मानम्;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मानम्] "=q" (मानम्));
     पटिनिवत्त मानम्;
 }

 __CRT_INLINE शून्य __writecr8(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#endif

  __CRT_INLINE unsigned __int64 __readmsr(unsigned long msr)
  {
      unsigned __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      पटिनिवत्त val1 | (val2 << 32);
  }

 __CRT_INLINE शून्य __writemsr (unsigned long msr, unsigned __int64 मानम्_3)
 {
    unsigned long val1 = मानम्_3, val2 = मानम्_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(शून्य)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      पटिनिवत्त val1 | (val2 << 32);
  }

  __CRT_INLINE शून्य __cpuid(पूर्णाङ्क CPUInfo[4], पूर्णाङ्क InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#endif

#ifdef __cplusplus
}
#endif

#अन्तर्भाव <sec_api/conio_s.h>

#endif
