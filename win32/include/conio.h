/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#അന്തര്ഭാവ <_mingw.h>

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  _CRTIMP അക്ഷരം *_cgets(അക്ഷരം *_Buffer);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cprintf(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cputs(സ്ഥിരം അക്ഷരം *_Str);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cscanf(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cscanf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getch(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getche(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcprintf(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cprintf_p(സ്ഥിരം അക്ഷരം *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcprintf_p(സ്ഥിരം അക്ഷരം *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cprintf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcprintf_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cprintf_p_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcprintf_p_l(സ്ഥിരം അക്ഷരം *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _kbhit(ശൂന്യം);

#എങ്കിൽ defined(_X86_) && !defined(__x86_64)
  പൂർണ്ണസംഖ്യ __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  പൂർണ്ണസംഖ്യ __cdecl _outp(unsigned short,പൂർണ്ണസംഖ്യ);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _putch(പൂർണ്ണസംഖ്യ _Ch);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _ungetch(പൂർണ്ണസംഖ്യ _Ch);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getch_nolock(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getche_nolock(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _putch_nolock(പൂർണ്ണസംഖ്യ _Ch);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _ungetch_nolock(പൂർണ്ണസംഖ്യ _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(ശൂന്യം);
  _CRTIMP wint_t __cdecl _getwche(ശൂന്യം);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cputws(സ്ഥിരം wchar_t *_String);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwscanf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_p(സ്ഥിരം wchar_t *_Format,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_p(സ്ഥിരം wchar_t *_Format,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _cwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _vcwprintf_p_l(സ്ഥിരം wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(ശൂന്യം);
  _CRTIMP wint_t __cdecl _getwche_nolock(ശൂന്യം);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  അക്ഷരം *__cdecl cgets(അക്ഷരം *_Buffer);
  പൂർണ്ണസംഖ്യ __cdecl cprintf(സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl cputs(സ്ഥിരം അക്ഷരം *_Str);
  പൂർണ്ണസംഖ്യ __cdecl cscanf(സ്ഥിരം അക്ഷരം *_Format,...);
  പൂർണ്ണസംഖ്യ __cdecl getch(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl getche(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl kbhit(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl putch(പൂർണ്ണസംഖ്യ _Ch);
  പൂർണ്ണസംഖ്യ __cdecl ungetch(പൂർണ്ണസംഖ്യ _Ch);

#എങ്കിൽ (defined(_X86_) && !defined(__x86_64))
  പൂർണ്ണസംഖ്യ __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  പൂർണ്ണസംഖ്യ __cdecl outp(unsigned short,പൂർണ്ണസംഖ്യ);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned അക്ഷരം __inbyte(unsigned short Port)
  {
      unsigned അക്ഷരം മൂല്യം;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (മൂല്യം)
          : "Nd" (Port));
      തിരികെ മൂല്യം;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short മൂല്യം;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (മൂല്യം)
          : "Nd" (Port));
      തിരികെ മൂല്യം;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long മൂല്യം;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (മൂല്യം)
          : "Nd" (Port));
      തിരികെ മൂല്യം;
  }
  __CRT_INLINE ശൂന്യം __outbyte(unsigned short Port,unsigned അക്ഷരം Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ശൂന്യം __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ശൂന്യം __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ശൂന്യം __inbytestring(unsigned short Port,unsigned അക്ഷരം *Buffer,unsigned long എണ്ണം_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (എണ്ണം_3)
		: "d"(Port), "0"(Buffer), "1" (എണ്ണം_3)
		);
  }
  __CRT_INLINE ശൂന്യം __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long എണ്ണം_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (എണ്ണം_3)
		: "d"(Port), "0"(Buffer), "1" (എണ്ണം_3)
		);
  }
  __CRT_INLINE ശൂന്യം __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long എണ്ണം_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (എണ്ണം_3)
		: "d"(Port), "0"(Buffer), "1" (എണ്ണം_3)
		);
  }

  __CRT_INLINE ശൂന്യം __outbytestring(unsigned short Port,unsigned അക്ഷരം *Buffer,unsigned long എണ്ണം_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (എണ്ണം_3)
          : "d"(Port), "0"(Buffer), "1" (എണ്ണം_3)
          );
  }
  __CRT_INLINE ശൂന്യം __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long എണ്ണം_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (എണ്ണം_3)
          : "d"(Port), "0"(Buffer), "1" (എണ്ണം_3)
          );
  }
  __CRT_INLINE ശൂന്യം __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long എണ്ണം_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (എണ്ണം_3)
          : "d"(Port), "0"(Buffer), "1" (എണ്ണം_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(ശൂന്യം)
  {
      unsigned __int64 മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE ശൂന്യം __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(ശൂന്യം)
  {
      unsigned __int64 മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(ശൂന്യം)
  {
      unsigned __int64 മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(ശൂന്യം)
  {
      unsigned __int64 മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(ശൂന്യം)
  {
      unsigned __int64 മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#അല്ലെങ്കിലെങ്കിൽ defined(_WIN32)

  __CRT_INLINE ശൂന്യം __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(ശൂന്യം)
  {
      unsigned long മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(ശൂന്യം)
  {
      unsigned long മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(ശൂന്യം)
  {
      unsigned long മൂല്യം;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
      തിരികെ മൂല്യം;
  }

 __CRT_INLINE ശൂന്യം __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(ശൂന്യം)
 {
   unsigned long മൂല്യം;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [മൂല്യം] "=q" (മൂല്യം));
     തിരികെ മൂല്യം;
 }

 __CRT_INLINE ശൂന്യം __writecr8(unsigned Data)
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
      തിരികെ val1 | (val2 << 32);
  }

 __CRT_INLINE ശൂന്യം __writemsr (unsigned long msr, unsigned __int64 മൂല്യം_3)
 {
    unsigned long val1 = മൂല്യം_3, val2 = മൂല്യം_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(ശൂന്യം)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      തിരികെ val1 | (val2 << 32);
  }

  __CRT_INLINE ശൂന്യം __cpuid(പൂർണ്ണസംഖ്യ CPUInfo[4], പൂർണ്ണസംഖ്യ InfoType)
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

#അന്തര്ഭാവ <sec_api/conio_s.h>

#endif
