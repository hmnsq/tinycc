/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#ضمن <_mingw.h>

#ifdef __cplusplus
خارجي "C" {
#endif

  _CRTIMP حرف *_cgets(حرف *_Buffer);
  _CRTIMP صحيح __cdecl _cprintf(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cputs(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _cscanf(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cscanf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _getch(فراغ);
  _CRTIMP صحيح __cdecl _getche(فراغ);
  _CRTIMP صحيح __cdecl _vcprintf(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_p(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vcprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _kbhit(فراغ);

#אם defined(_X86_) && !defined(__x86_64)
  صحيح __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  صحيح __cdecl _outp(unsigned short,صحيح);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP صحيح __cdecl _putch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _getch_nolock(فراغ);
  _CRTIMP صحيح __cdecl _getche_nolock(فراغ);
  _CRTIMP صحيح __cdecl _putch_nolock(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch_nolock(صحيح _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(فراغ);
  _CRTIMP wint_t __cdecl _getwche(فراغ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP صحيح __cdecl _cputws(ثابت wchar_t *_String);
  _CRTIMP صحيح __cdecl _cwprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vcwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(فراغ);
  _CRTIMP wint_t __cdecl _getwche_nolock(فراغ);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  حرف *__cdecl cgets(حرف *_Buffer);
  صحيح __cdecl cprintf(ثابت حرف *_Format,...);
  صحيح __cdecl cputs(ثابت حرف *_Str);
  صحيح __cdecl cscanf(ثابت حرف *_Format,...);
  صحيح __cdecl getch(فراغ);
  صحيح __cdecl getche(فراغ);
  صحيح __cdecl kbhit(فراغ);
  صحيح __cdecl putch(صحيح _Ch);
  صحيح __cdecl ungetch(صحيح _Ch);

#אם (defined(_X86_) && !defined(__x86_64))
  صحيح __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  صحيح __cdecl outp(unsigned short,صحيح);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned حرف __inbyte(unsigned short Port)
  {
      unsigned حرف value;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (value)
          : "Nd" (Port));
      החזר value;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short value;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (value)
          : "Nd" (Port));
      החזר value;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long value;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (value)
          : "Nd" (Port));
      החזר value;
  }
  __CRT_INLINE فراغ __outbyte(unsigned short Port,unsigned حرف Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE فراغ __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE فراغ __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE فراغ __inbytestring(unsigned short Port,unsigned حرف *Buffer,unsigned long Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE فراغ __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE فراغ __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }

  __CRT_INLINE فراغ __outbytestring(unsigned short Port,unsigned حرف *Buffer,unsigned long Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE فراغ __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE فراغ __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(فراغ)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE فراغ __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(فراغ)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(فراغ)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(فراغ)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(فراغ)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#وإلاإذا defined(_WIN32)

  __CRT_INLINE فراغ __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(فراغ)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(فراغ)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(فراغ)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      החזר value;
  }

 __CRT_INLINE فراغ __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(فراغ)
 {
   unsigned long value;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
     החזר value;
 }

 __CRT_INLINE فراغ __writecr8(unsigned Data)
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
      החזר val1 | (val2 << 32);
  }

 __CRT_INLINE فراغ __writemsr (unsigned long msr, unsigned __int64 Value)
 {
    unsigned long val1 = Value, val2 = Value >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(فراغ)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      החזר val1 | (val2 << 32);
  }

  __CRT_INLINE فراغ __cpuid(صحيح CPUInfo[4], صحيح InfoType)
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

#ضمن <sec_api/conio_s.h>

#endif
