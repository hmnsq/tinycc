/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#অন্তর্ভাব <_mingw.h>

#ifdef __cplusplus
বাহ্য "C" {
#endif

  _CRTIMP বর্ণ *_cgets(বর্ণ *_Buffer);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cprintf(ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cputs(ধ্রুব বর্ণ *_Str);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cscanf(ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cscanf_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getch(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getche(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcprintf(ধ্রুব বর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cprintf_p(ধ্রুব বর্ণ *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcprintf_p(ধ্রুব বর্ণ *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cprintf_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcprintf_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cprintf_p_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcprintf_p_l(ধ্রুব বর্ণ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _kbhit(শূন্য);

#যদি defined(_X86_) && !defined(__x86_64)
  পূর্ণাঙ্ক __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  পূর্ণাঙ্ক __cdecl _outp(unsigned short,পূর্ণাঙ্ক);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP পূর্ণাঙ্ক __cdecl _putch(পূর্ণাঙ্ক _Ch);
  _CRTIMP পূর্ণাঙ্ক __cdecl _ungetch(পূর্ণাঙ্ক _Ch);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getch_nolock(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getche_nolock(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _putch_nolock(পূর্ণাঙ্ক _Ch);
  _CRTIMP পূর্ণাঙ্ক __cdecl _ungetch_nolock(পূর্ণাঙ্ক _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(শূন্য);
  _CRTIMP wint_t __cdecl _getwche(শূন্য);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cputws(ধ্রুব wchar_t *_String);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwscanf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_p(ধ্রুব wchar_t *_Format,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_p(ধ্রুব wchar_t *_Format,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP পূর্ণাঙ্ক __cdecl _cwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP পূর্ণাঙ্ক __cdecl _vcwprintf_p_l(ধ্রুব wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(শূন্য);
  _CRTIMP wint_t __cdecl _getwche_nolock(শূন্য);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  বর্ণ *__cdecl cgets(বর্ণ *_Buffer);
  পূর্ণাঙ্ক __cdecl cprintf(ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl cputs(ধ্রুব বর্ণ *_Str);
  পূর্ণাঙ্ক __cdecl cscanf(ধ্রুব বর্ণ *_Format,...);
  পূর্ণাঙ্ক __cdecl getch(শূন্য);
  পূর্ণাঙ্ক __cdecl getche(শূন্য);
  পূর্ণাঙ্ক __cdecl kbhit(শূন্য);
  পূর্ণাঙ্ক __cdecl putch(পূর্ণাঙ্ক _Ch);
  পূর্ণাঙ্ক __cdecl ungetch(পূর্ণাঙ্ক _Ch);

#যদি (defined(_X86_) && !defined(__x86_64))
  পূর্ণাঙ্ক __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  পূর্ণাঙ্ক __cdecl outp(unsigned short,পূর্ণাঙ্ক);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned বর্ণ __inbyte(unsigned short Port)
  {
      unsigned বর্ণ মান;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (মান)
          : "Nd" (Port));
      প্রত্যাগম মান;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short মান;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (মান)
          : "Nd" (Port));
      প্রত্যাগম মান;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long মান;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (মান)
          : "Nd" (Port));
      প্রত্যাগম মান;
  }
  __CRT_INLINE শূন্য __outbyte(unsigned short Port,unsigned বর্ণ Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE শূন্য __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE শূন্য __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE শূন্য __inbytestring(unsigned short Port,unsigned বর্ণ *Buffer,unsigned long গুনতি_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (গুনতি_3)
		: "d"(Port), "0"(Buffer), "1" (গুনতি_3)
		);
  }
  __CRT_INLINE শূন্য __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long গুনতি_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (গুনতি_3)
		: "d"(Port), "0"(Buffer), "1" (গুনতি_3)
		);
  }
  __CRT_INLINE শূন্য __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long গুনতি_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (গুনতি_3)
		: "d"(Port), "0"(Buffer), "1" (গুনতি_3)
		);
  }

  __CRT_INLINE শূন্য __outbytestring(unsigned short Port,unsigned বর্ণ *Buffer,unsigned long গুনতি_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (গুনতি_3)
          : "d"(Port), "0"(Buffer), "1" (গুনতি_3)
          );
  }
  __CRT_INLINE শূন্য __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long গুনতি_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (গুনতি_3)
          : "d"(Port), "0"(Buffer), "1" (গুনতি_3)
          );
  }
  __CRT_INLINE শূন্য __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long গুনতি_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (গুনতি_3)
          : "d"(Port), "0"(Buffer), "1" (গুনতি_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(শূন্য)
  {
      unsigned __int64 মান;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE শূন্য __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(শূন্য)
  {
      unsigned __int64 মান;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(শূন্য)
  {
      unsigned __int64 মান;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(শূন্য)
  {
      unsigned __int64 মান;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(শূন্য)
  {
      unsigned __int64 মান;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#নোচেদ্যদি defined(_WIN32)

  __CRT_INLINE শূন্য __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(শূন্য)
  {
      unsigned long মান;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(শূন্য)
  {
      unsigned long মান;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(শূন্য)
  {
      unsigned long মান;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [মান] "=q" (মান));
      প্রত্যাগম মান;
  }

 __CRT_INLINE শূন্য __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(শূন্য)
 {
   unsigned long মান;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [মান] "=q" (মান));
     প্রত্যাগম মান;
 }

 __CRT_INLINE শূন্য __writecr8(unsigned Data)
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
      প্রত্যাগম val1 | (val2 << 32);
  }

 __CRT_INLINE শূন্য __writemsr (unsigned long msr, unsigned __int64 মান_3)
 {
    unsigned long val1 = মান_3, val2 = মান_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(শূন্য)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      প্রত্যাগম val1 | (val2 << 32);
  }

  __CRT_INLINE শূন্য __cpuid(পূর্ণাঙ্ক CPUInfo[4], পূর্ণাঙ্ক InfoType)
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

#অন্তর্ভাব <sec_api/conio_s.h>

#endif
