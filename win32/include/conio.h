/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

  _CRTIMP var_na *_cgets(var_na *_Buffer);
  _CRTIMP puur_naa_nka __cdecl _cprintf(const var_na *_Format,...);
  _CRTIMP puur_naa_nka __cdecl _cputs(const var_na *_Str);
  _CRTIMP puur_naa_nka __cdecl _cscanf(const var_na *_Format,...);
  _CRTIMP puur_naa_nka __cdecl _cscanf_l(const var_na *_Format,_locale_t _Locale,...);
  _CRTIMP puur_naa_nka __cdecl _getch(void);
  _CRTIMP puur_naa_nka __cdecl _getche(void);
  _CRTIMP puur_naa_nka __cdecl _vcprintf(const var_na *_Format,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _cprintf_p(const var_na *_Format,...);
  _CRTIMP puur_naa_nka __cdecl _vcprintf_p(const var_na *_Format,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _cprintf_l(const var_na *_Format,_locale_t _Locale,...);
  _CRTIMP puur_naa_nka __cdecl _vcprintf_l(const var_na *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _cprintf_p_l(const var_na *_Format,_locale_t _Locale,...);
  _CRTIMP puur_naa_nka __cdecl _vcprintf_p_l(const var_na *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _kbhit(void);

#ᤀᤡ᤺ defined(_X86_) && !defined(__x86_64)
  puur_naa_nka __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  puur_naa_nka __cdecl _outp(unsigned short,puur_naa_nka);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP puur_naa_nka __cdecl _putch(puur_naa_nka _Ch);
  _CRTIMP puur_naa_nka __cdecl _ungetch(puur_naa_nka _Ch);
  _CRTIMP puur_naa_nka __cdecl _getch_nolock(void);
  _CRTIMP puur_naa_nka __cdecl _getche_nolock(void);
  _CRTIMP puur_naa_nka __cdecl _putch_nolock(puur_naa_nka _Ch);
  _CRTIMP puur_naa_nka __cdecl _ungetch_nolock(puur_naa_nka _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(void);
  _CRTIMP wint_t __cdecl _getwche(void);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP puur_naa_nka __cdecl _cputws(const wchar_t *_String);
  _CRTIMP puur_naa_nka __cdecl _cwprintf(const wchar_t *_Format,...);
  _CRTIMP puur_naa_nka __cdecl _cwscanf(const wchar_t *_Format,...);
  _CRTIMP puur_naa_nka __cdecl _cwscanf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP puur_naa_nka __cdecl _vcwprintf(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _cwprintf_p(const wchar_t *_Format,...);
  _CRTIMP puur_naa_nka __cdecl _vcwprintf_p(const wchar_t *_Format,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _cwprintf_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP puur_naa_nka __cdecl _vcwprintf_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP puur_naa_nka __cdecl _cwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP puur_naa_nka __cdecl _vcwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(void);
  _CRTIMP wint_t __cdecl _getwche_nolock(void);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  var_na *__cdecl cgets(var_na *_Buffer);
  puur_naa_nka __cdecl cprintf(const var_na *_Format,...);
  puur_naa_nka __cdecl cputs(const var_na *_Str);
  puur_naa_nka __cdecl cscanf(const var_na *_Format,...);
  puur_naa_nka __cdecl getch(void);
  puur_naa_nka __cdecl getche(void);
  puur_naa_nka __cdecl kbhit(void);
  puur_naa_nka __cdecl putch(puur_naa_nka _Ch);
  puur_naa_nka __cdecl ungetch(puur_naa_nka _Ch);

#ᤀᤡ᤺ (defined(_X86_) && !defined(__x86_64))
  puur_naa_nka __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  puur_naa_nka __cdecl outp(unsigned short,puur_naa_nka);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned var_na __inbyte(unsigned short Port)
  {
      unsigned var_na value;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (value)
          : "Nd" (Port));
      ᤀᤡᤴ value;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short value;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (value)
          : "Nd" (Port));
      ᤀᤡᤴ value;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long value;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (value)
          : "Nd" (Port));
      ᤀᤡᤴ value;
  }
  __CRT_INLINE void __outbyte(unsigned short Port,unsigned var_na Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE void __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE void __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE void __inbytestring(unsigned short Port,unsigned var_na *Buffer,unsigned long Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE void __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE void __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }

  __CRT_INLINE void __outbytestring(unsigned short Port,unsigned var_na *Buffer,unsigned long Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE void __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE void __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE void __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#elif defined(_WIN32)

  __CRT_INLINE void __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      ᤀᤡᤴ value;
  }

 __CRT_INLINE void __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(void)
 {
   unsigned long value;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
     ᤀᤡᤴ value;
 }

 __CRT_INLINE void __writecr8(unsigned Data)
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
      ᤀᤡᤴ val1 | (val2 << 32);
  }

 __CRT_INLINE void __writemsr (unsigned long msr, unsigned __int64 Value)
 {
    unsigned long val1 = Value, val2 = Value >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(void)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      ᤀᤡᤴ val1 | (val2 << 32);
  }

  __CRT_INLINE void __cpuid(puur_naa_nka CPUInfo[4], puur_naa_nka InfoType)
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

#include <sec_api/conio_s.h>

#endif
