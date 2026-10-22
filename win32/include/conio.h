/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#અન્તર્ભાવ <_mingw.h>

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  _CRTIMP અક્ષર *_cgets(અક્ષર *_Buffer);
  _CRTIMP પૂર્ણાંક __cdecl _cprintf(અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _cputs(અચલ અક્ષર *_Str);
  _CRTIMP પૂર્ણાંક __cdecl _cscanf(અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _cscanf_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _getch(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _getche(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _vcprintf(અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cprintf_p(અચલ અક્ષર *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcprintf_p(અચલ અક્ષર *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cprintf_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcprintf_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cprintf_p_l(અચલ અક્ષર *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcprintf_p_l(અચલ અક્ષર *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _kbhit(શૂન્ય);

#જો defined(_X86_) && !defined(__x86_64)
  પૂર્ણાંક __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  પૂર્ણાંક __cdecl _outp(unsigned short,પૂર્ણાંક);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP પૂર્ણાંક __cdecl _putch(પૂર્ણાંક _Ch);
  _CRTIMP પૂર્ણાંક __cdecl _ungetch(પૂર્ણાંક _Ch);
  _CRTIMP પૂર્ણાંક __cdecl _getch_nolock(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _getche_nolock(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _putch_nolock(પૂર્ણાંક _Ch);
  _CRTIMP પૂર્ણાંક __cdecl _ungetch_nolock(પૂર્ણાંક _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(શૂન્ય);
  _CRTIMP wint_t __cdecl _getwche(શૂન્ય);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP પૂર્ણાંક __cdecl _cputws(અચલ wchar_t *_String);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _cwscanf(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _cwscanf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf_p(અચલ wchar_t *_Format,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf_p(અચલ wchar_t *_Format,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP પૂર્ણાંક __cdecl _cwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP પૂર્ણાંક __cdecl _vcwprintf_p_l(અચલ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(શૂન્ય);
  _CRTIMP wint_t __cdecl _getwche_nolock(શૂન્ય);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  અક્ષર *__cdecl cgets(અક્ષર *_Buffer);
  પૂર્ણાંક __cdecl cprintf(અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl cputs(અચલ અક્ષર *_Str);
  પૂર્ણાંક __cdecl cscanf(અચલ અક્ષર *_Format,...);
  પૂર્ણાંક __cdecl getch(શૂન્ય);
  પૂર્ણાંક __cdecl getche(શૂન્ય);
  પૂર્ણાંક __cdecl kbhit(શૂન્ય);
  પૂર્ણાંક __cdecl putch(પૂર્ણાંક _Ch);
  પૂર્ણાંક __cdecl ungetch(પૂર્ણાંક _Ch);

#જો (defined(_X86_) && !defined(__x86_64))
  પૂર્ણાંક __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  પૂર્ણાંક __cdecl outp(unsigned short,પૂર્ણાંક);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned અક્ષર __inbyte(unsigned short Port)
  {
      unsigned અક્ષર કિંમત;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (કિંમત)
          : "Nd" (Port));
      પાછા કિંમત;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short કિંમત;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (કિંમત)
          : "Nd" (Port));
      પાછા કિંમત;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long કિંમત;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (કિંમત)
          : "Nd" (Port));
      પાછા કિંમત;
  }
  __CRT_INLINE શૂન્ય __outbyte(unsigned short Port,unsigned અક્ષર Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE શૂન્ય __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE શૂન્ય __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE શૂન્ય __inbytestring(unsigned short Port,unsigned અક્ષર *Buffer,unsigned long ગણતરી_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (ગણતરી_3)
		: "d"(Port), "0"(Buffer), "1" (ગણતરી_3)
		);
  }
  __CRT_INLINE શૂન્ય __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long ગણતરી_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (ગણતરી_3)
		: "d"(Port), "0"(Buffer), "1" (ગણતરી_3)
		);
  }
  __CRT_INLINE શૂન્ય __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long ગણતરી_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (ગણતરી_3)
		: "d"(Port), "0"(Buffer), "1" (ગણતરી_3)
		);
  }

  __CRT_INLINE શૂન્ય __outbytestring(unsigned short Port,unsigned અક્ષર *Buffer,unsigned long ગણતરી_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (ગણતરી_3)
          : "d"(Port), "0"(Buffer), "1" (ગણતરી_3)
          );
  }
  __CRT_INLINE શૂન્ય __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long ગણતરી_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (ગણતરી_3)
          : "d"(Port), "0"(Buffer), "1" (ગણતરી_3)
          );
  }
  __CRT_INLINE શૂન્ય __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long ગણતરી_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (ગણતરી_3)
          : "d"(Port), "0"(Buffer), "1" (ગણતરી_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(શૂન્ય)
  {
      unsigned __int64 કિંમત;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE શૂન્ય __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(શૂન્ય)
  {
      unsigned __int64 કિંમત;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(શૂન્ય)
  {
      unsigned __int64 કિંમત;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(શૂન્ય)
  {
      unsigned __int64 કિંમત;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(શૂન્ય)
  {
      unsigned __int64 કિંમત;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#અથવાજો defined(_WIN32)

  __CRT_INLINE શૂન્ય __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(શૂન્ય)
  {
      unsigned long કિંમત;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(શૂન્ય)
  {
      unsigned long કિંમત;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(શૂન્ય)
  {
      unsigned long કિંમત;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [કિંમત] "=q" (કિંમત));
      પાછા કિંમત;
  }

 __CRT_INLINE શૂન્ય __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(શૂન્ય)
 {
   unsigned long કિંમત;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [કિંમત] "=q" (કિંમત));
     પાછા કિંમત;
 }

 __CRT_INLINE શૂન્ય __writecr8(unsigned Data)
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
      પાછા val1 | (val2 << 32);
  }

 __CRT_INLINE શૂન્ય __writemsr (unsigned long msr, unsigned __int64 કિંમત_3)
 {
    unsigned long val1 = કિંમત_3, val2 = કિંમત_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(શૂન્ય)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      પાછા val1 | (val2 << 32);
  }

  __CRT_INLINE શૂન્ય __cpuid(પૂર્ણાંક CPUInfo[4], પૂર્ણાંક InfoType)
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

#અન્તર્ભાવ <sec_api/conio_s.h>

#endif
