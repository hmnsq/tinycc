/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  _CRTIMP ଅକ୍ଷର *_cgets(ଅକ୍ଷର *_Buffer);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cprintf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cputs(ଅଚଳ ଅକ୍ଷର *_Str);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cscanf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cscanf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getch(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getche(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcprintf(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cprintf_p(ଅଚଳ ଅକ୍ଷର *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcprintf_p(ଅଚଳ ଅକ୍ଷର *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cprintf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcprintf_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cprintf_p_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcprintf_p_l(ଅଚଳ ଅକ୍ଷର *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _kbhit(ଶୂନ୍ୟ);

#ଯଦି defined(_X86_) && !defined(__x86_64)
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _outp(unsigned short,ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _putch(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _ungetch(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getch_nolock(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getche_nolock(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _putch_nolock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _ungetch_nolock(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(ଶୂନ୍ୟ);
  _CRTIMP wint_t __cdecl _getwche(ଶୂନ୍ୟ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cputws(ଅଚଳ wchar_t *_String);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwscanf(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwscanf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_p(ଅଚଳ wchar_t *_Format,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_p(ଅଚଳ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _cwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _vcwprintf_p_l(ଅଚଳ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(ଶୂନ୍ୟ);
  _CRTIMP wint_t __cdecl _getwche_nolock(ଶୂନ୍ୟ);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  ଅକ୍ଷର *__cdecl cgets(ଅକ୍ଷର *_Buffer);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl cprintf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl cputs(ଅଚଳ ଅକ୍ଷର *_Str);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl cscanf(ଅଚଳ ଅକ୍ଷର *_Format,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl getch(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl getche(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl kbhit(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl putch(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl ungetch(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Ch);

#ଯଦି (defined(_X86_) && !defined(__x86_64))
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl outp(unsigned short,ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned ଅକ୍ଷର __inbyte(unsigned short Port)
  {
      unsigned ଅକ୍ଷର ମୂଲ୍ୟ;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (ମୂଲ୍ୟ)
          : "Nd" (Port));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short ମୂଲ୍ୟ;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (ମୂଲ୍ୟ)
          : "Nd" (Port));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long ମୂଲ୍ୟ;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (ମୂଲ୍ୟ)
          : "Nd" (Port));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }
  __CRT_INLINE ଶୂନ୍ୟ __outbyte(unsigned short Port,unsigned ଅକ୍ଷର Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ଶୂନ୍ୟ __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ଶୂନ୍ୟ __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ଶୂନ୍ୟ __inbytestring(unsigned short Port,unsigned ଅକ୍ଷର *Buffer,unsigned long ଗଣନା_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (ଗଣନା_4)
		: "d"(Port), "0"(Buffer), "1" (ଗଣନା_4)
		);
  }
  __CRT_INLINE ଶୂନ୍ୟ __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long ଗଣନା_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (ଗଣନା_4)
		: "d"(Port), "0"(Buffer), "1" (ଗଣନା_4)
		);
  }
  __CRT_INLINE ଶୂନ୍ୟ __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long ଗଣନା_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (ଗଣନା_4)
		: "d"(Port), "0"(Buffer), "1" (ଗଣନା_4)
		);
  }

  __CRT_INLINE ଶୂନ୍ୟ __outbytestring(unsigned short Port,unsigned ଅକ୍ଷର *Buffer,unsigned long ଗଣନା_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (ଗଣନା_4)
          : "d"(Port), "0"(Buffer), "1" (ଗଣନା_4)
          );
  }
  __CRT_INLINE ଶୂନ୍ୟ __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long ଗଣନା_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (ଗଣନା_4)
          : "d"(Port), "0"(Buffer), "1" (ଗଣନା_4)
          );
  }
  __CRT_INLINE ଶୂନ୍ୟ __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long ଗଣନା_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (ଗଣନା_4)
          : "d"(Port), "0"(Buffer), "1" (ଗଣନା_4)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(ଶୂନ୍ୟ)
  {
      unsigned __int64 ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE ଶୂନ୍ୟ __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(ଶୂନ୍ୟ)
  {
      unsigned __int64 ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(ଶୂନ୍ୟ)
  {
      unsigned __int64 ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(ଶୂନ୍ୟ)
  {
      unsigned __int64 ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(ଶୂନ୍ୟ)
  {
      unsigned __int64 ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#ନଚେତଯଦି defined(_WIN32)

  __CRT_INLINE ଶୂନ୍ୟ __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(ଶୂନ୍ୟ)
  {
      unsigned long ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(ଶୂନ୍ୟ)
  {
      unsigned long ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(ଶୂନ୍ୟ)
  {
      unsigned long ମୂଲ୍ୟ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
      ଫେରନ୍ତୁ ମୂଲ୍ୟ;
  }

 __CRT_INLINE ଶୂନ୍ୟ __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(ଶୂନ୍ୟ)
 {
   unsigned long ମୂଲ୍ୟ;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ମୂଲ୍ୟ] "=q" (ମୂଲ୍ୟ));
     ଫେରନ୍ତୁ ମୂଲ୍ୟ;
 }

 __CRT_INLINE ଶୂନ୍ୟ __writecr8(unsigned Data)
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
      ଫେରନ୍ତୁ val1 | (val2 << 32);
  }

 __CRT_INLINE ଶୂନ୍ୟ __writemsr (unsigned long msr, unsigned __int64 ମୂଲ୍ୟ_3)
 {
    unsigned long val1 = ମୂଲ୍ୟ_3, val2 = ମୂଲ୍ୟ_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(ଶୂନ୍ୟ)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      ଫେରନ୍ତୁ val1 | (val2 << 32);
  }

  __CRT_INLINE ଶୂନ୍ୟ __cpuid(ପୂର୍ଣ୍ଣସଂଖ୍ୟା CPUInfo[4], ପୂର୍ଣ୍ଣସଂଖ୍ୟା InfoType)
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

#ଅନ୍ତର୍ଭାଵ <sec_api/conio_s.h>

#endif
